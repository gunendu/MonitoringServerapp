/*
 * RTC.cxx
 *
 * RTC Receiver
 * This is used by Feeder to switch from receiving yesterday's closing Prices
 * before Market opens to receiving actual Feed when Market opens. Also, used
 * by Feeder to switch to receiving today's closing Prices after Market closes.
 *
 *  Created on:
 *      Author: Santosh Kurian
 *
 *      modification history
------------ -------
Date		Modification Details				Modified by
----------------------------------------------------------------------------
 03/10/2012	0.1: Created for SFS Engine		    Santosh Kurian
 */

#include "common.h"
#include "RTC.h"
#include "SFSEngine.h"
#include "RTCstore.h"

//Collector related

bool RTCCollector::Start() {
    if ((false == m_rtc_conn->CreateReader()) || (false == m_rtc_conn->StartReader(this))) {
        return false;
    }
    return true;
}

bool RTCCollector::collect(MktOpen::MarketOpenTimeSynch *sample) 
{
    
   
    if(m_rtc_store == NULL)
    {
        fprintf(fp_rtc,"Error in mstore \n");
    }
    
    if (NULL == sample) 
    {
        
        fprintf(fp_rtc, "Error ---> RTCCollector::collect(): MktOpen::MarketOpenTimeSynch* sample passed from rtc_data_receiving() is NULL!\n");
        return false; //Serious error!
    }

    fprintf(fp_rtc, "TIME IS %s\n", d_time());
    fprintf(fp_rtc, "RTCCollector::collect(): Received [HH:MM:SS] ---> [%.02d:%.02d:%.02d]\n", sample->HH, sample->MM, sample->SS);

    //TBD - Update the (global) RTC class here...!
    
    m_rtc_store->setRtcTime(sample);
    
    
    fprintf(fp_rtc,"From rtcGet %d \n",m_rtc_store->getRtcTime()->HH);
    
    return true;
}

bool RTCCollector::handle_rtc_liveliness(int alive_count_change) {
    static EngineState::ComponentState state = EngineState::DOWN;
    EngineState* eng_state = SFSEngine::GetEngineState();

    // We don't send the UP event to SFS Engine (overall SFSEngine state is NOT checked
    // during normal operation)
    // NOTE: For consistency and avoiding any race conditions we need to set the Engine
    //       state either here or queue them (UP/DOWN) as events. We set it here, since
    //		 specially for DOWN state, queued data has become stale by now, since RTI
    //		 will take some time to detect publisher down status, so we avoid sending
    //		 orders based on this!
    if ((0 < alive_count_change) && (EngineState::DOWN == state)) {
        eng_state->SetRTC(state = EngineState::UP);
        fprintf(fp_rtc, "MktOpen_MarketOpenTimeSynchListener::on_liveliness_changed: RTC is in UP(%d) STATE!\n", state);
    }
    if ((0 > alive_count_change) && (EngineState::UP == state)) {
        // We send the DOWN event to SFS Engine since it needs a trigger to take action for this one!
        // WARNING: In case we want to check if SFSEngine is already down and then decide to queue/not queue
        //          this event, we are unable to avoid the race condition (e.g. when both Model & Feed
        //          do this checking at the same time) that may result in the event not being queued.
        //			So, there can be multiple DOWN event's queued by various listeners.
        eng_state->SetRTC(state = EngineState::DOWN);
        EngineEvtMgr<void, void>& evt_mgr = EngineEvtMgr<void, void>::getEngineEvtMgr();
        EngineEvent<void, void> *e = new EngineEvent<void, void>(EngineEvent<void, void>::RTC_LISTENER,
                (void *) "RTC", &state);
        fprintf(fp_rtc, "MktOpen_MarketOpenTimeSynchListener::on_liveliness_changed: RTC is in DOWN(%d) STATE!\n", state);
        evt_mgr.sendEvent(e);
    }

    return true;
}

//Connector related
//MKT_OPEN_TIME_SYNCH
//RTI generated class - START...
//

class MktOpen_MarketOpenTimeSynchListener : public DDSDataReaderListener {
public:

    virtual void on_requested_deadline_missed(
            DDSDataReader* /*reader*/,
            const DDS_RequestedDeadlineMissedStatus& /*status*/) {
        fprintf(fp_rtc, "Error---> MktOpen_MarketOpenTimeSynchListener::on_requested_deadline_missed!!! \n");
    }

    virtual void on_requested_incompatible_qos(
            DDSDataReader* /*reader*/,
            const DDS_RequestedIncompatibleQosStatus& /*status*/);

    virtual void on_sample_rejected(
            DDSDataReader* /*reader*/,
            const DDS_SampleRejectedStatus& /*status*/) {
        fprintf(fp_rtc, "Error---> MktOpen_MarketOpenTimeSynchListener::on_sample_rejected!!!\n");
    }

    virtual void on_liveliness_changed(
            DDSDataReader* /*reader*/,
            const DDS_LivelinessChangedStatus& /*status*/);

    virtual void on_sample_lost(
            DDSDataReader* /*reader*/,
            const DDS_SampleLostStatus& /*status*/) {
        fprintf(fp_rtc, "Error---> MktOpen_MarketOpenTimeSynchListener::on_sample_lost\n");
    }

    virtual void on_subscription_matched(
            DDSDataReader* /*reader*/,
            const DDS_SubscriptionMatchedStatus& /*status*/);

    virtual void on_data_available(DDSDataReader* reader) {
        fprintf(fp_rtc, "Error---> MktOpen_MarketOpenTimeSynchListener::on_data_available!!!\n");
    }
};

void MktOpen_MarketOpenTimeSynchListener::on_requested_incompatible_qos(
        DDSDataReader* reader,
        const DDS_RequestedIncompatibleQosStatus& status) {
    fprintf(fp_rtc,
            "Error---> MktOpen_MarketOpenTimeSynchListener::detected incompatible QOS (total_count = %d, policy ID = %d)...\n",
            status.total_count, status.last_policy_id);
}

void MktOpen_MarketOpenTimeSynchListener::on_subscription_matched(
        DDSDataReader* reader,
        const DDS_SubscriptionMatchedStatus& status) {
    fprintf(fp_rtc, "Information... MktOpen_MarketOpenTimeSynchListener::on_subscription_matched\n");
}

void MktOpen_MarketOpenTimeSynchListener::on_liveliness_changed(DDSDataReader* reader, const DDS_LivelinessChangedStatus& status) {
    fprintf(fp_rtc, "MktOpen_MarketOpenTimeSynchListener::on_liveliness_changed: alive_count(%d), not_alive_count(%d), alive_count_change(%d), not_alive_count_change(%d)  \n",
            status.alive_count, status.not_alive_count, status.alive_count_change, status.not_alive_count_change);
    RTCCollector::handle_rtc_liveliness(status.alive_count_change);

    return;
}
//RTI generated class - END...

//Connector related
//

RTCConnector::RTCConnector(const char* rd_topic) {
    DDS_ReturnCode_t retcode_cache;
    
    DDSDomainParticipant *participant = RTIConnector::getParticipant();
    m_read_topic = NULL;
    pt_rtc = NULL;
    m_reader_listener_cache = NULL;
    m_reader_cache = NULL;

    if (rd_topic == NULL) {
        fprintf(fp_rtc, "Error ---> RTCConnector()::rd_topic passed is null\n");
        return;
    }
    if (participant == NULL) {
        fprintf(fp_rtc, "Error ---> RTCConnector()::participant is null\n");
        return;
    }

    /* Register the type before creating the topic for RTC */
    m_type_name_cache = MktOpen::MarketOpenTimeSynchTypeSupport::get_type_name();
    retcode_cache = MktOpen::MarketOpenTimeSynchTypeSupport::register_type(participant, m_type_name_cache);
    if (retcode_cache != DDS_RETCODE_OK) {
        fprintf(fp_rtc, "Error ---> RTCConnector() register_type RTC error\n");
        m_type_name_cache = NULL;
        return;
    }
    if (NULL == m_read_topic) {
        /* To customize the topic QoS, use the configuration file USER_QOS_PROFILES.xml */
        m_read_topic = participant->create_topic(rd_topic, m_type_name_cache, DDS_TOPIC_QOS_DEFAULT, NULL /* listener */
                , DDS_STATUS_MASK_NONE);
        if (m_read_topic == NULL) {
            fprintf(fp_rtc, "Error ---> RTCConnector() create_topic RTC\n");
            return;
        }
        fprintf(fp_rtc, "SUCCESSFULLY <---create_topic RTC SUCCESS \n");
    }
}

// Cleanup RTI part - since top level API's like delete_contained_entities() don't seem to be working
// i.e. leaks memory (as per valgrind)

RTCConnector::~RTCConnector() {
    DDSDomainParticipant *participant = RTIConnector::getParticipant();
    DDS_ReturnCode_t retcode;

    if (NULL != m_reader_listener_cache) {
        delete m_reader_listener_cache;
        m_reader_listener_cache = NULL;
    }

    if (NULL != m_reader_cache) {
        if (DDS_RETCODE_OK != RTIConnector::getSubscriber()->delete_datareader(m_reader_cache)) {
            fprintf(fp_rtc, "~RTCConnector(): Unable to delete m_reader_cache (%p)\n", m_reader_cache);
        }
        m_reader_cache = NULL;
    }
    if (NULL != m_read_topic) {
        if (DDS_RETCODE_OK != participant->delete_topic(m_read_topic)) {
            fprintf(fp_rtc, "~RTCConnector(): Unable to delete m_read_topic (%p)\n", m_read_topic);
        }
        m_read_topic = NULL;
    }

    // Un-register the type...
    if ((NULL != participant) && (NULL != m_type_name_cache)) {
        retcode = MktOpen::MarketOpenTimeSynchTypeSupport::unregister_type(participant, m_type_name_cache);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(fp_rtc, "Error ---> RTCConnector() unregister_type RTC error\n");
        }
        m_type_name_cache = NULL;
    }
    pt_rtc = 0;

    return;
}

bool RTCConnector::CreateReader() {
    DDSSubscriber *subscriber = RTIConnector::getSubscriber();

    if (NULL == m_read_topic) {
        fprintf(fp_rtc, "Error ---> RTCConnector::CreateReader() m_read_topic is NULL for RTC!\n");
        return false;
    }

    if (NULL != m_reader_cache) {
        fprintf(fp_rtc, "Error ---> RTCConnector::CreateReader() m_reader_cache exists for RTC!\n");
        return false;
    }

    /* Create a data reader listener for cache */
    m_reader_listener_cache = new MktOpen_MarketOpenTimeSynchListener();
    /* To customize the data reader QoS, use the configuration file USER_QOS_PROFILES.xml */
    m_reader_cache = subscriber->create_datareader_with_profile(m_read_topic, "SFS_Library", "default_Profile", m_reader_listener_cache,
            DDS_STATUS_MASK_ALL & ~DDS_DATA_AVAILABLE_STATUS);
    if (m_reader_cache == NULL) {
        fprintf(fp_rtc, "Error ---> RTCConnector::CreateReader() error for RTC\n");
        delete m_reader_listener_cache;
        m_reader_listener_cache = NULL;
        return false;
    }
    fprintf(fp_rtc, "SUCCESSFULLY <--- RTCConnector::CreateReader() RTC SUCCESS \n");

    return true;
}

void* RTCConnector::rtc_data_receiving(void* arg) {
    RTCCollector *coll = (RTCCollector *) arg;
    RTCConnector *conn = NULL;

    if ((NULL == coll) || (NULL == (conn = coll->getConnector()))) {
        fprintf(fp_rtc, "Error ---> RTCConnector::rtc_data_receiving() - RTCCollector reference is NULL!\n");
        fprintf(fp_rtc, "OR invalid RTCConnector reference received in RTCCollector object...\n");
        return NULL;
    }

    DDS_ReturnCode_t retcode_cache;
    if (NULL == conn->m_reader_cache) {
        fprintf(fp_rtc, "Error ---> RTCConnector::rtc_data_receiving() - reader_cache is NULL\n");
        return NULL;
    }

    MktOpen::MarketOpenTimeSynchDataReader *rtc_reader = MktOpen::MarketOpenTimeSynchDataReader::narrow(conn->m_reader_cache);
    if (rtc_reader == NULL) {
        fprintf(fp_rtc, "Error ---> RTCConnector::rtc_data_receiving() - DataReader narrow error\n");
        return NULL;
    }
    // set the enabled status = DATA_AVAILABLE
    DDSStatusCondition* status_condition = conn->m_reader_cache->get_statuscondition();
    status_condition->set_enabled_statuses(DDS_DATA_AVAILABLE_STATUS);
    // attach the status condition to the waitset
    DDSWaitSet* waitset = new DDSWaitSet();
    retcode_cache = waitset->attach_condition(status_condition);
    if (retcode_cache != DDS_RETCODE_OK) {
        fprintf(fp_rtc, "Error ---> RTCConnector::rtc_data_receiving() - unable to attach status condition to WaitSet\n");
        delete waitset;
        return NULL;
    }

    DDSConditionSeq activeconditions;
    DDS_Duration_t timeout = {1, 0};
    MktOpen::MarketOpenTimeSynchSeq data_seq;
    DDS_SampleInfoSeq info_seq;
    MktOpen::MarketOpenTimeSynch* sample = NULL;
    int timeout_count = 0;
    const static int MAX_TIMEOUT_COUNT = 60;

    int i = 0;
    while (1) {
        if (true == EngWatchDog::CheckNotification(true, fp_rtc)) {
            fprintf(fp_rtc, "RTCConnector::rtc_data_receiving(): Got shutdown notification, exiting...!\n");
            break; //de-allocate resources and then return!
        }

        retcode_cache = waitset->wait(activeconditions, timeout);
        // waitset returned.. check if status changed, or if waitset timed out
        if (retcode_cache == DDS_RETCODE_TIMEOUT) 
        {
            if (++timeout_count > MAX_TIMEOUT_COUNT) //Restrict output till 1 minute!
            {
                fprintf(fp_rtc, "RTCConnector(): RTC timed out after <%d> seconds\n", MAX_TIMEOUT_COUNT);
                timeout_count = 0;
            }
            continue;
        } 
        
        else if (retcode_cache != DDS_RETCODE_OK) 
        {
            timeout_count = 0;
            fprintf(fp_rtc, "Error ---> RTCConnector::WaitSet() wait failed retcode(%d)\n", retcode_cache);
            continue;
        }
        timeout_count = 0;

        retcode_cache = rtc_reader->take(data_seq, info_seq, DDS_LENGTH_UNLIMITED,
                DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);
        
        if (retcode_cache == DDS_RETCODE_NO_DATA) {
            fprintf(stderr,"NO data Found \n");
            continue;
        } else if (retcode_cache != DDS_RETCODE_OK) {
            fprintf(fp_rtc, "Error ---> RTCConnector::rtc_data_receiving() take error RTC\n");
            continue;
        }

        for (i = 0; i < data_seq.length(); ++i) {
            if (info_seq[i].valid_data) {
                //MktOpen::MarketOpenTimeSynchTypeSupport::print_data(&data_seq[i]);
                sample = &data_seq[i];
                //Invoke collector's action here!
                if (false == coll->collect(sample)) {
                    fprintf(fp_rtc, "Error ---> RTCConnector::rtc_data_receiving() - collect() failed, exiting thread...!\n");
                    if (DDS_RETCODE_OK != rtc_reader->return_loan(data_seq, info_seq)) {
                        fprintf(fp_rtc, "Error ---> RTCConnector::rtc_data_receiving() return loan error\n");
                    }
                    goto endgame;
                }
            } // if (info_seq[i].valid_data)...
        }//for..data_seq.length()..

        retcode_cache = rtc_reader->return_loan(data_seq, info_seq);
        if (retcode_cache != DDS_RETCODE_OK) {
            fprintf(fp_rtc, "Error ---> RTCConnector::rtc_data_receiving() return loan error\n");
        }
    } //while...

    /* Delete all entities - to cleanup properly! */
endgame:
    waitset->detach_condition(status_condition);
    delete waitset;
    return NULL;
}


//Print - for testin only!
