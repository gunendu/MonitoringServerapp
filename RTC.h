/*
 * RTC.h
 *
 *  This file is header of RTC.cxx
 *  Contains the classes and interfaces required to connect to RTC pub.
 *
 *  Created on:
 *  Author: Santosh Kurian
 *
 *      modification history
 ------------ -------
 Date		Modification Details				Modified by
 ----------------------------------------------------------------------------
 03/10/2012	0.1: Created for SFS Engine		    Santosh Kurian
 */

#ifndef RTC_H_
#define RTC_H_

#include "common.h"

class RTCConnector;
//template<class C> class Future;
class RTCCollector
{
public:
	friend class SFSEngine;
	friend class RTCConnector;
       // template<class C> friend class Future;
        
	static bool handle_rtc_liveliness(int alive_count_change);

	RTCCollector(RTCConnector *rtc_conn,RTCstore *rtcstore)
	: m_rtc_conn(rtc_conn),m_rtc_store(rtcstore)
	{
	    if (NULL == rtc_conn)
	    {
		    fprintf(fp_rtc, "Error ----> RTCCollector(): rtc_conn is NULL \n");
	    }
            
            m_rtc_store = new RTCstore();
            
            if (NULL == m_rtc_store)
	    {
		    fprintf(stderr, "Error ----> RTCStore(): rtcstore is NULL \n");
	    }
	}

	bool Start();

	RTCConnector* getConnector() const
	{
		return m_rtc_conn;
	}
        
        RTCstore* getRtcStore() const
	{
		return m_rtc_store;
	}

	//Get relevent data and store in m_store & send event as required
	bool collect(MktOpen::MarketOpenTimeSynch *sample);
         
        
protected:
	~RTCCollector()
	{
	    m_rtc_conn = NULL;
            m_rtc_store = NULL;
	}
private:
	// WARNING : Deleted by SFSEngine
	RTCConnector *m_rtc_conn;
        RTCstore *m_rtc_store;
        //static RTCCollector * m_rtc_coll;
	RTCCollector();
	// disable - for Safety
	RTCCollector(const RTCCollector&);
	RTCCollector& operator =(const RTCCollector&);
};

class MktOpen_MarketOpenTimeSynchListener;
class SFSEngine;

class RTCConnector
{
public:
	friend class SFSEngine;

	RTCConnector(const char* rd_topic = "MKT_OPEN_TIME_SYNCH");

	bool CreateReader();
	bool StartReader(RTCCollector *coll)
	{
		// creating thread for RTC
		if (0 != pthread_create(&pt_rtc, NULL, RTCConnector::rtc_data_receiving, coll))
		{
			fprintf(fp_rtc, "Error --->RTCConnector::StartReader() pthread_create rtc_data_receiving\n");
			return false;
		}
		fprintf(fp_rtc, "Information ... RTCConnector::StartReader() pthread_create rtc_data_receiving\n");
		return true;
	}

protected:
	~RTCConnector();

private:
	const char *m_type_name_cache;
	DDSTopic *m_read_topic;
	MktOpen_MarketOpenTimeSynchListener *m_reader_listener_cache; // not using for on data available
	DDSDataReader *m_reader_cache;
	pthread_t pt_rtc;
	//Used For Creating Waitset for the RTC
	static void* rtc_data_receiving(void* arg);
        
	//Disable for safety
	RTCConnector(const RTCConnector&);
	RTCConnector& operator =(const RTCConnector&);
};

#endif /* RTC_H_ */
