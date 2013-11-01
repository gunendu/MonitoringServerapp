/* 
 * File:   main.cpp
 * Author: Gunendu
 *
 * Created on 31 August, 2012, 12:39 PM
 */
#include "includes.h"
#define MAX_USER_THREAD 7

int RTIConnector::g_domainId = 0; //default domain = 0!
DDSDomainParticipant *participant = NULL;
DDSSubscriber *subscriber = NULL;

CLogger g_cSystemLogger;

using namespace std;
sem_t g_semValue;

void signalhandler(int signum) {
    g_cSystemLogger.LogMessage((":%s:%s(:%d) Signal Handling"), LOG_LOCATION);
    sem_post(&g_semValue);
}

//RTIConnector Related...

bool RTIConnector::SetThreadAffinities(DDS_DomainParticipantQos& participant_qos) {
    //Based on the number of user threads and available processors, we
    //assign receive threads to the remaining processors (i.e not
    //having affinities to user threads). If none remaining, we just
    //assign the entire cpu set.
    //NOTE: CPU rotation is tied to cpu_list (affinity)
    int num_cores = static_cast<int> (sysconf(_SC_NPROCESSORS_ONLN));
    if ((1 < num_cores)) {
        int num_user_threads = MAX_USER_THREAD;
        int num_available_processors = (num_cores - num_user_threads);
        int cpu_count = num_user_threads;
        if (0 >= num_available_processors) {
            // fprintf(fp_main,
            //      "RTIConnector::SetThreadAffinities(): User threads occupy all available processors, assigning RTI receive threads to all cores...!\n");
            num_available_processors = num_cores;
            cpu_count = 0;
        }

        //Then initialize affinity related settings
        participant_qos.receiver_pool.thread.cpu_list.ensure_length(num_available_processors, num_available_processors);
        for (int i = 0; (i < num_available_processors); ++i) {
            participant_qos.receiver_pool.thread.cpu_list[i] = cpu_count++;
        }
        //RTI: Any thread controlled by this QoS can run on any listed processor,
        //     as determined by OS scheduling.
        //We opt for no rotation (default) - a more deterministic system
        participant_qos.receiver_pool.thread.cpu_rotation = DDS_THREAD_SETTINGS_CPU_NO_ROTATION;
    }

    return true;
}

bool RTIConnector::SetThreadPriorities(DDS_DomainParticipantQos& participant_qos) {
    /* RTI allows us to configure appropriate thread settings for the following
     * QOS policies (IMMUTABLE i.e. can't change after creation):
     * DDS_EventQosPolicy, DDS_DatabaseQosPolicy, DDS_ReceiverPoolQosPolicy,
     * DDS_AsynchronousPublisherQosPolicy
     * Here, we use the participant QOS and configure thread settings as:
     * - mask & priority: for DDS_EventQosPolicy, DDS_ReceiverPoolQosPolicy,
     */
    /* Can't set non-default mask or priority independently for any of
     * the above QOS. We are only allowed to set default priority
     * (0 for SCHED_OTHER sched. policy for Linux platform). We need to
     * change the mask to use real-time scheduling policy like SCHED_FIFO
     * on Linux platform to use priority > 0 (e.g. having range 1-99 ).
     * And application needs to execute with effective superuser privileges
     * for this to work! Before running ensure that setuid bit is on and
     * owner of the application is superuser.
     * RTI NOTES:
     * SCHED_FIFO is used corresponding to real time mask.
     * You can set any RTI DDS thread to whatever priority you desire. However,
     * it is up to you to prevent inadvertent blocking or priority inversions.
     * This is caused when you have high priority threads waiting for low priority
     * threads to complete. When picking priorities one should consider Rate
     * Monotonic Scheduling theory. In a nut shell you assign the highest priority
     * to the threads that execute at the highest rate.
     */
    if (0 == geteuid()) {
        /* RTI NOTE: The priority of the database thread should be set to the lowest
         * priority among all threads in a real-time system. Although, the database
         * thread should not be permitted to starve, the work that it performs is
         * non-time-critical. We use default priority for now, so that it is this
         * lower than the one for least busy thread (e.g. RTI asynchronous write).
         * TBD: may need to tune accordingly if performance degrades
         */
        /* max_skiplist_level - performance tuning parameter that optimizes the time
         * it takes to search the database for a record.
         * RTI NOTES: This value should be set to log2(N), where N is the maximum
         * number of elements that will be stored in a single list. So, the number
         * of DataWriters or DataReaders in a system across all DomainParticipants
         * in a single domain (which ever is greater) can be used to set this parameter.
         *
         * TBD: Based on rough estimation we consider N = 64. To be tuned as after
         * appropriate calculations considering AH, Monitor Client, AH Engine, etc.
         */
        participant_qos.database.max_skiplist_level = 6;

        /* RTI NOTES: EventQosPolicy can can effect waitset performance. If the priority
         * of the event thread is too low one can have additional latency.
         * For high throughput Event thread’s priority must be sufficiently high on the
         * sending application. If your application is sending a lot of reliable data,
         * you should increase the event thread priority to be higher than the SENDING
         * thread priority. The default Event thread priority is unsuitable for
         * maintaining a fast and sustained reliable communication.
         *
         * TBD: Hence we set priority between REALTIME min & max since the SENDING
         * thread priority is set between REALTIME min & max To be tuned accordingly.
         */
        participant_qos.event.thread.mask |= DDS_THREAD_SETTINGS_REALTIME_PRIORITY;
        participant_qos.event.thread.priority =
                (sched_get_priority_max(SCHED_FIFO) - sched_get_priority_min(SCHED_FIFO))*2 / 3;

        /* RTI NOTES: When samples are sent to the same or another application on the
         * same host, the Receive thread priority should be higher than the writing
         * thread priority (priority of the thread calling write() on the DDSDataWriter).
         * This will allow the Receive thread to process the messages as they are sent by
         * the writing thread. A sustained reliable flow requires the reader to be able
         * to process the samples from the writer at a speed equal to or faster than
         * the writer emits.
         *
         * We set it's priority to 2/3 of (REALTIME min & max) since the most loaded
         * user receive thread's priority is set of 3/4 of (REALTIME min & max)
         * and the target (engine) consumer thread's priority is set to REALTIME max!
         */
        participant_qos.receiver_pool.thread.mask |= DDS_THREAD_SETTINGS_REALTIME_PRIORITY;
        participant_qos.receiver_pool.thread.priority = (sched_get_priority_max(SCHED_FIFO) - sched_get_priority_min(SCHED_FIFO))*2 / 3;
    }//end geteuid()
    else /* Not considering this a serious error for now */ {
        //        fprintf(fp_main,
        //                "RTIConnector::SetThreadPriorities(): PCPT: RTI thread settings for mask and priority require application to run with superuser privileges...\n");
    }

    return true;
}

bool RTIConnector::SetThreadPriorities(DDS_PublisherQos& publisher_qos) {
    /* RTI allows us to configure appropriate thread settings for the following
     * QOS policies (IMMUTABLE i.e. can't change after creation):
     * DDS_EventQosPolicy, DDS_DatabaseQosPolicy, DDS_ReceiverPoolQosPolicy,
     * DDS_AsynchronousPublisherQosPolicy
     * NOTE: Process needs to execute with effective superuser privileges for this:
     * Before running ensure that setuid bit is on and owner of the application
     * is superuser.
     *
     * RTI NOTES: When samples are sent to the same or another application on the
     * same host, the Receive thread priority should be higher than the writing
     * thread priority (priority of the thread calling write() on the DDSDataWriter).
     * (Refer comments for RTI reader pool thread.
     *
     * TBD: Hence we set it's priority to 1/2 of (REALTIME: MAX - MIN)  - to be tuned.
     */
    if (0 == geteuid()) {
        publisher_qos.asynchronous_publisher.disable_asynchronous_write = DDS_BOOLEAN_FALSE; /* default! */
        publisher_qos.asynchronous_publisher.thread.mask |= DDS_THREAD_SETTINGS_REALTIME_PRIORITY;
        publisher_qos.asynchronous_publisher.thread.priority =
                (sched_get_priority_max(SCHED_FIFO) - sched_get_priority_min(SCHED_FIFO)) / 2;
    } else /* Not considering this a serious error for now */ {
        // fprintf(fp_main,
        // "RTIConnector::SetThreadPriorities(): PUB: RTI thread settings for mask and priority require application to run with superuser privileges...\n");
    }

    return true;
}

RTIConnector::RTIConnector()
: m_participant(NULL), m_subscriber(NULL), m_publisher(NULL) {
#ifdef _RTI_DEBUG_
    NDDSConfigLogger::get_instance()->set_output_file(fp_rti);
    NDDSConfigLogger::get_instance()->set_print_format(NDDS_CONFIG_LOG_PRINT_FORMAT_VERBOSE);
    NDDSConfigLogger::get_instance()->set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_API,
            NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
#endif

    //Get the domain participant's QOS for configuring RTI threads
    DDS_DomainParticipantQos participant_qos;
    DDS_ReturnCode_t retcode = DDSTheParticipantFactory->get_participant_qos_from_profile(participant_qos,
            "Monitoring_Library", "Monitoring_Profile");
    if (retcode != DDS_RETCODE_OK) {
        // fprintf(fp_main, "Error ---> RTIConnector::RTIConnector() get_participant_qos_from_profile error, (retcode = %d)\n",
        // retcode);
        return;
    }

    if (false == SetThreadAffinities(participant_qos)) {
        return;
    }
    if (false == SetThreadPriorities(participant_qos)) {
        return;
    }
    /* To customize the participant QoS, use the configuration file USER_QOS_PROFILES.xml */
    //    m_participant = DDSTheParticipantFactory->create_participant(g_domainId, DDS_PARTICIPANT_QOS_DEFAULT,
    //    															 NULL /* listener */, DDS_STATUS_MASK_NONE);
    /* To customize the participant QoS, use the configuration file USER_QOS_PROFILES.xml */
    m_participant = DDSTheParticipantFactory->create_participant(g_domainId, participant_qos,
            NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (m_participant == NULL) {
        g_cSystemLogger.LogMessage("(%s:%s:(:%d)):: Create Participant Error %d", LOG_LOCATION);
        shutdown();
        return;
    }

    /* To customize the subscriber QoS, use the configuration file USER_QOS_PROFILES.xml */
    m_subscriber = m_participant->create_subscriber(DDS_SUBSCRIBER_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (m_subscriber == NULL) {
        g_cSystemLogger.LogMessage("(%s:%s:(:%d)):: Create subscriber Error %d", LOG_LOCATION);
        shutdown();
        return;
    }

    // Get the publishers QOS for configuring RTI writer thread
    DDS_PublisherQos publisher_qos;
    retcode = m_participant->get_default_publisher_qos(publisher_qos);
    if (retcode != DDS_RETCODE_OK) {
        // fprintf(fp_main, "Error ---> RTIConnector::RTIConnector() get_default_publisher_qos error, (retcode = %d)\n",
        //    retcode);
        return;
    }
    if (false == SetThreadPriorities(publisher_qos)) {
        return;
    }
    /* To customize publisher QoS, use the configuration file USER_QOS_PROFILES.xml */
    m_publisher = m_participant->create_publisher(publisher_qos, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (m_publisher == NULL) {
        // fprintf(g_logfp, "Error ---> RTIConnector::RTIConnector() create_publisher error\n");
        shutdown();
        return;
    }

    return;
}



// Delete all entities - need to specifically delete individual entities since
// delete_contained_entities(), etc. doesn't seem to work...

bool RTIConnector::shutdown() {
    DDS_ReturnCode_t retcode;
    bool rval = true;

    // fprintf(g_logfp, "Information... RTIConnector::RTIConnector()::shutdown() called...!\n");

    if (m_participant != NULL) {
        if (m_subscriber != NULL) {
            retcode = m_subscriber->delete_contained_entities();
            if (DDS_RETCODE_OK != retcode) {
                g_cSystemLogger.LogMessage("(%s:%s:(:%d)):: subscriber: delete_contained_entities %d", LOG_LOCATION);
                // fprintf(g_logfp, "Error ---> RTIConnector::shutdown() - subscriber: delete_contained_entities (errcode = %d)!\n", retcode);
                rval = false;
            }
            if (DDS_RETCODE_OK != m_participant->delete_subscriber(m_subscriber)) {
                //  fprintf(g_logfp, "RTIConnector()::shutdown() - Unable to delete m_subscriber!\n");
                rval = false;
            }
        }
        if (m_publisher != NULL) {
            retcode = m_publisher->delete_contained_entities();
            if (DDS_RETCODE_OK != retcode) {
                // fprintf(g_logfp, "Error ---> RTIConnector::shutdown() - publisher: delete_contained_entities (errcode = %d)!\n", retcode);
                rval = false;
            }
            if (DDS_RETCODE_OK != m_participant->delete_publisher(m_publisher)) {
                // fprintf(g_logfp, "RTIConnector()::shutdown() - Unable to delete m_publisher!\n");
                rval = false;
            }
        }
        retcode = m_participant->delete_contained_entities();
        if (DDS_RETCODE_OK != retcode) {
            // fprintf(g_logfp, "Error ---> RTIConnector::shutdown() - participant: delete_contained_entities (errcode = %d)!\n", retcode);
            rval = false;
        }
        retcode = DDSTheParticipantFactory->delete_participant(m_participant);
        if (retcode != DDS_RETCODE_OK) {
            // fprintf(g_logfp, "Error ---> RTIConnector::shutdown() - delete_participant (errcode = %d)\n", retcode);
            rval = false;
        }
    }
    /* RTI Data Distribution Service provides the finalize_instance() method on
       domain participant factory and the finalize() method on type support for
       users who want to release memory used by the participant factory and
       type support singletons. Uncomment the following block of code for
       clean destruction of the singletons. */
    /*
        model_parametersTypeSupport::finalize();
     */
    retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        // fprintf(g_logfp, "Error ---> RTIConnector::shutdown() finalize_instance (errcode = %d)\n", retcode);
        rval = false;
    }
    m_participant = NULL;
    m_subscriber = NULL;
    m_publisher = NULL;

    return rval;
}



int main(int argc, char** argv) 
{
      
    signal(SIGINT, signalhandler);
    RTIConnector::getRTIConnector(4);
    participant = RTIConnector::getParticipant();
    if (participant == NULL) {
        g_cSystemLogger.LogMessage("(%s:%s:(:%d)):: Participant is NULL %d", LOG_LOCATION);
    }
    subscriber = RTIConnector::getSubscriber();

    if (subscriber == NULL) {
        g_cSystemLogger.LogMessage("(%s:%s:(:%d)):: Subscriber is NULL %d", LOG_LOCATION);
    }
    g_cSystemLogger.StartLogger("monitorclient_log", 102400, "Monitoring_Log");
    CControllerThread *singleInstance;
    singleInstance = CControllerThread::getInstance();
    
    if (FAILURE == singleInstance->CreateWriter("Monitoring_Library", "Monitoring_Profile")) {
        g_cSystemLogger.LogMessage("(%s:%s:%d)::Failure Create writer", LOG_LOCATION);
    }

    if(FAILURE==singleInstance->makeSocketConnection())
    {
        g_cSystemLogger.LogMessage("(%s:%s(:%d)::Failure establishing socket connection", LOG_LOCATION);
    }
    StartLineProcessConnector * lpConnector = new StartLineProcessConnector("CMD_STARTSTOP");
    StartLineProcessCollector * lpCollector = new StartLineProcessCollector(lpConnector);

    
    serverConnectThread *lservConnectThread = NULL;
    lservConnectThread = singleInstance->InitiliazeController(lpConnector);
    g_cSystemLogger.LogMessage("(%s:%s:(:%d)):: after thread Initialization \n", LOG_LOCATION);
    // ConnectAdapterThread *lstConnectThread = NULL;
     //lstConnectThread = singleInstance->InitiliazeAdapterController();
    // g_cSystemLogger.LogMessage("(%s:%s:(:%d)):: after thread Initialization %d", LOG_LOCATION);

    serverConnectThread2 *lservConnectThread2 = NULL;
    lservConnectThread2 = singleInstance->InitiliazeController2();
    g_cSystemLogger.LogMessage("(%s:%s:(:%d)):: after thread Initialization \n", LOG_LOCATION);

    serverConnectThread3 *lservConnectThread3 = NULL;
    lservConnectThread3 = singleInstance->InitiliazeController3();
     
    lpCollector->start();
    
    sem_wait(&g_semValue);
    close(singleInstance->socketId);
    lservConnectThread->Join();
    delete lservConnectThread;
    
    lservConnectThread2->Join();
    delete lservConnectThread2;

    lservConnectThread2->Join();
    delete lservConnectThread2;

    // lstConnectThread->Join();
    //delete lstConnectThread;

       // delete lpConnector;
       // lpConnector = NULL;
       // delete lpCollector;
       // lpCollector = NULL;



    return 0;
}















