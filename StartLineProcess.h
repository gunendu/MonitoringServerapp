/* 
 * File:   StartLineProcess.h
 * Author: Gunendu Das
 *
 * Created on 10 December, 2012, 9:51 AM
 */

#ifndef STARTLINEPROCESS_H
#define	STARTLINEPROCESS_H

#include "logger.h"
#include "dataTypes.h"

extern CLogger g_cSystemLogger;
//#include "common.h"

class StartLineProcessConnector;

class StartLineProcessCollector {
public:

    StartLineProcessCollector(StartLineProcessConnector *rtc_conn) : m_rtc_conn(rtc_conn) {
        
        if (m_rtc_conn == NULL) {

        }
        

    }

    bool start();

    StartLineProcessConnector* getConnector() const {
        return m_rtc_conn;
    }
    bool collect(MONITORING::leaseProcessStart *sample, StartLineProcessConnector *conn);
    int waitsocket(int socket_fd, LIBSSH2_SESSION *session);
    iterIpPathMap iterMap;
    //std::vector<long> orderIds;
protected:

    ~StartLineProcessCollector() {
        m_rtc_conn = NULL;
    }
private:
    
    StartLineProcessConnector *m_rtc_conn;

    StartLineProcessCollector();
    // disable - for Safety
    StartLineProcessCollector(const StartLineProcessCollector&);
    StartLineProcessCollector& operator =(const StartLineProcessCollector&);
};

class StartLineProcessConnector {
public:
    StartLineProcessConnector(const char* rd_topic = "CMD_STARTSTOP");
    IpPathMap pathMap;
    serverDetails    serverObject;    
    std::vector<long> orderIds;
    	
    bool createReader();

    bool startReader(StartLineProcessCollector *coll) {
        if (0 != pthread_create(&pt_rtc, NULL, StartLineProcessConnector::data_recv, coll)) {
            return false;
        }
        return true;
    }

    void setPath(IpPathMap pathMap1)
    {
        pathMap=pathMap1;
    }

    IpPathMap getPath()
    {
        return pathMap;
    }
    
    void setServerInfo(serverDetails serverObject1)
    {
        serverObject = serverObject1;
    }

    serverDetails getServerInfo()
    {
        return serverObject;
    }

protected:
    ~StartLineProcessConnector();

private:
    ConnectAdapterThread *connectadapter;
    const char* m_type_name_cache;
    DDSTopic * m_read_topic;
    // not using for on data available
    DDSDataReader * m_reader_cache;
    pthread_t pt_rtc;
    static void * data_recv(void * arg);

    //Disable for safety
    StartLineProcessConnector(const StartLineProcessConnector&);
    StartLineProcessConnector& operator =(const StartLineProcessConnector&);

};

class LineProcessStatusListener : public DDSDataReaderListener {
public:

    virtual void on_requested_deadline_missed(
            DDSDataReader* /*reader*/,
            const DDS_RequestedDeadlineMissedStatus& /*status*/) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: on_requested_deadline_missed \n", LOG_LOCATION);
    }

    virtual void on_requested_incompatible_qos(
            DDSDataReader* /*reader*/,
            const DDS_RequestedIncompatibleQosStatus& /*status*/) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: on_requested_incompatible_qos \n", LOG_LOCATION);
    }

    virtual void on_sample_rejected(
            DDSDataReader* /*reader*/,
            const DDS_SampleRejectedStatus& /*status*/) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: on_sample_rejected \n", LOG_LOCATION);
    }

    virtual void on_liveliness_changed(
            DDSDataReader* /*reader*/,
            const DDS_LivelinessChangedStatus& /*status*/) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: on_liveliness_changed \n", LOG_LOCATION);
    }

    virtual void on_sample_lost(
            DDSDataReader* /*reader*/,
            const DDS_SampleLostStatus& /*status*/) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: on_sample_lost \n", LOG_LOCATION);
    }

    virtual void on_subscription_matched(
            DDSDataReader* /*reader*/,
            const DDS_SubscriptionMatchedStatus& /*status*/) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: on_data_available \n", LOG_LOCATION);
    }

    virtual void on_data_available(DDSDataReader* reader) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: on_data_available \n", LOG_LOCATION);
    }
};

#endif	/* STARTLINEPROCESS_H */

