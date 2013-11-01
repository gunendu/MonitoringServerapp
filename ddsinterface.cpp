#include "includes.h"

extern CLogger g_cSystemLogger;

CDDSInterface::CDDSInterface(const int nDomain) : m_participant(NULL),
                                                  m_subscriber(NULL),
                                                  m_publisher(NULL)
{

    assert(nDomain != -1);
    m_nDomain = nDomain;
    
    DDS_DomainParticipantQos participant_qos;
    DDS_ReturnCode_t lnRetCode = DDSTheParticipantFactory->get_participant_qos_from_profile(participant_qos,
                                                                                            "Monitoring_Library", "Monitoring_Profile");
    if (lnRetCode != DDS_RETCODE_OK)
    {
        g_cSystemLogger.LogMessage("%s-%s(%d): get_participant_qos_from_profile failed with error code(%d)", LOG_LOCATION, lnRetCode);
        return;
    }

    if (false == SetThreadAffinities(participant_qos))
    {
        return;
    }

    if (false == SetThreadPriorities(participant_qos))
    {
        return;
    }

    /* To customize the participant QoS, use the configuration file USER_QOS_PROFILES.xml */
    //    m_participant = DDSTheParticipantFactory->create_participant(g_domainId, DDS_PARTICIPANT_QOS_DEFAULT,
    //    															 NULL /* listener */, DDS_STATUS_MASK_NONE);
    /* To customize the participant QoS, use the configuration file USER_QOS_PROFILES.xml */
    m_participant = DDSTheParticipantFactory->create_participant(m_nDomain, participant_qos,
                                                                 NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (m_participant == NULL)
    {
        g_cSystemLogger.LogMessage("%s-%s(%d): create_participant failed", LOG_LOCATION);
        Shutdown();
        return;
    }

    /* To customize the subscriber QoS, use the configuration file USER_QOS_PROFILES.xml */
    m_subscriber = m_participant->create_subscriber(DDS_SUBSCRIBER_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (m_subscriber == NULL)
    {

        g_cSystemLogger.LogMessage("%s-%s(%d): create_subscriber failed", LOG_LOCATION);
        Shutdown();
        return;
    }

    //Get the publishers QOS for configuring RTI writer thread
    DDS_PublisherQos publisher_qos;
    lnRetCode = m_participant->get_default_publisher_qos(publisher_qos);
    if (lnRetCode != DDS_RETCODE_OK)
    {
        g_cSystemLogger.LogMessage("%s-%s(%d): create_subscriber failed with retcode(%d)", LOG_LOCATION, lnRetCode);
        return;
    }
    if (false == SetThreadPriorities(publisher_qos))
    {
        return;
    }
    /* To customize publisher QoS, use the configuration file USER_QOS_PROFILES.xml */
    m_publisher = m_participant->create_publisher(publisher_qos, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (m_publisher == NULL)
    {
        g_cSystemLogger.LogMessage("%s-%s(%d): create_publisher failed", LOG_LOCATION);
        Shutdown();
        return;
    }

    return;
}

bool CDDSInterface::Shutdown()
{
    DDS_ReturnCode_t lnRetCode;
    bool lnRetVal = true;

    g_cSystemLogger.LogMessage("%s-%s(%d): ShutDown Called", LOG_LOCATION);

    if (m_participant != NULL)
    {
        if (m_subscriber != NULL)
        {
            lnRetCode = m_subscriber->delete_contained_entities();
            if (DDS_RETCODE_OK != lnRetCode)
            {
                g_cSystemLogger.LogMessage("%s-%s(%d): m_subscriber::delete_contained_entities failed with error code(%d)", LOG_LOCATION, lnRetCode);
                lnRetVal = false;
            }
            if (DDS_RETCODE_OK != m_participant->delete_subscriber(m_subscriber))
            {
                g_cSystemLogger.LogMessage("%s-%s(%d): delete_subscriber failed", LOG_LOCATION);
                lnRetVal = false;
            }
        }

        if (m_publisher != NULL)
        {
            lnRetCode = m_publisher->delete_contained_entities();
            if (DDS_RETCODE_OK != lnRetCode)
            {
                g_cSystemLogger.LogMessage("%s-%s(%d): m_publisher::delete_contained_entities failed with error code(%d)", LOG_LOCATION, lnRetCode);
                lnRetVal = false;
            }
            if (DDS_RETCODE_OK != m_participant->delete_publisher(m_publisher))
            {
                g_cSystemLogger.LogMessage("%s-%s(%d): delete_publisher failed", LOG_LOCATION);
                lnRetVal = false;
            }
        }

        lnRetCode = m_participant->delete_contained_entities();
        if (DDS_RETCODE_OK != lnRetCode)
        {
            g_cSystemLogger.LogMessage("%s-%s(%d): m_participant::delete_contained_entities failed with error code(%d)", LOG_LOCATION, lnRetCode);
            lnRetVal = false;
        }

        lnRetCode = DDSTheParticipantFactory->delete_participant(m_participant);
        if (lnRetCode != DDS_RETCODE_OK)
        {
            g_cSystemLogger.LogMessage("%s-%s(%d): delete_participant failed ", LOG_LOCATION);
            lnRetVal = false;
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
    lnRetCode = DDSDomainParticipantFactory::finalize_instance();
    if (lnRetCode != DDS_RETCODE_OK)
    {
        g_cSystemLogger.LogMessage("%s-%s(%d): finalize_instance failed with error code(%d)", LOG_LOCATION, lnRetCode);
        lnRetVal = false;
    }
    m_participant = NULL;
    m_subscriber = NULL;
    m_publisher = NULL;

    return lnRetVal;
}

bool CDDSInterface::SetThreadAffinities(DDS_DomainParticipantQos& participant_qos)
{
    int lnNumCores = static_cast<int>(sysconf(_SC_NPROCESSORS_ONLN));
    if ((1 < lnNumCores))
    {
        int lnNumUserThreads = MAX_USER_THREADS;
        int lnNumAvailableProcessors = (lnNumCores - lnNumUserThreads);
        int lnCpuCount = lnNumUserThreads;
        if (0 >= lnNumAvailableProcessors)
        {
            g_cSystemLogger.LogMessage("%s-%s(%d): User threads occupy all available processors, assigning RTI receive threads to all cores...!", LOG_LOCATION);
            lnNumAvailableProcessors = lnNumCores;
            lnCpuCount = 0;
        }

        //Then initialize affinity related settings
        participant_qos.receiver_pool.thread.cpu_list.ensure_length(lnNumAvailableProcessors, lnNumAvailableProcessors);
        for (int lnLoopCounter = 0; (lnLoopCounter < lnNumAvailableProcessors); ++lnLoopCounter)
        {
            participant_qos.receiver_pool.thread.cpu_list[lnLoopCounter] = lnCpuCount++;
        }
        //RTI: Any thread controlled by this QoS can run on any listed processor,
        //     as determined by OS scheduling.
        //We opt for no rotation (default) - a more deterministic system
        participant_qos.receiver_pool.thread.cpu_rotation = DDS_THREAD_SETTINGS_CPU_NO_ROTATION;
    }

    return true;
}

bool CDDSInterface::SetThreadPriorities(DDS_DomainParticipantQos& participant_qos)
{
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
    if (0 == geteuid())
    {
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
    } //end geteuid()
    else /* Not considering this a serious error for now */
    {
        g_cSystemLogger.LogMessage("%s-%s(%d): PCPT: RTI thread settings for mask and priority require application to run with superuser privileges...!", LOG_LOCATION);
    }

    return true;
}

bool CDDSInterface::SetThreadPriorities(DDS_PublisherQos& publisher_qos)
{
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
    if (0 == geteuid())
    {
        publisher_qos.asynchronous_publisher.disable_asynchronous_write = DDS_BOOLEAN_FALSE; /* default! */
        publisher_qos.asynchronous_publisher.thread.mask |= DDS_THREAD_SETTINGS_REALTIME_PRIORITY;
        publisher_qos.asynchronous_publisher.thread.priority =
                (sched_get_priority_max(SCHED_FIFO) - sched_get_priority_min(SCHED_FIFO)) / 2;
    }
    else /* Not considering this a serious error for now */
    {
        g_cSystemLogger.LogMessage("%s-%s(%d): PUB: RTI thread settings for mask and priority require application to run with superuser privileges...!", LOG_LOCATION);
    }

    return true;
}

