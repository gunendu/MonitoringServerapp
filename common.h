/*
 * common.h
 *        This file is used for common purpose. Its easy to modify and changes in common file and changes occurs
 *        every where.
 *  Created on:
 *      Author: Santosh Kurian
 *
 *
 *      modification history
------------ -------
Date		Modification Details					Modified by
----------------------------------------------------------------------------
 10/09/2012	0.1: Created for SFS Engine		        		Santosh Kurian
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <pthread.h>

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <exception>
using namespace std;

//All externs first
//Hack - refer main.cxx
extern DDSDomainParticipant *participant;
extern DDSSubscriber *subscriber;

//WARNING: For any new file pointer created as global, entry should be present here!


//All declns here
bool set_file_pointers();
void close_files();
char *d_date(); // only used when creating log file
char *d_time();


//All common definitions/decls.
//For hashing strings..
inline size_t stl_hash_string(const char* __s)
{
  unsigned long __h = 0;
  for ( ; *__s; ++__s)
    __h = 5 * __h + *__s;
  return size_t(__h);
}

//Singleton for RTI
class RTIConnector
{
public:
	static RTIConnector& getRTIConnector(int domainId) //Meyer's singleton
	{
		g_domainId = domainId;
		//g_logfp = (logfp == NULL) ? stderr : logfp;
		return RTIConnector::getRTIConnector();
	}

	static DDSDomainParticipant* getParticipant()
	{
		return RTIConnector::getRTIConnector().m_participant;
	}
	static DDSSubscriber* getSubscriber()
	{
		return RTIConnector::getRTIConnector().m_subscriber;
	}
	static DDSPublisher* getPublisher()
	{
		return RTIConnector::getRTIConnector().m_publisher;
	}

private:
	static int g_domainId;
	//static FILE * g_logfp;
	DDSDomainParticipant *m_participant;
	DDSSubscriber *m_subscriber;
	DDSPublisher *m_publisher;

	static RTIConnector& getRTIConnector() //Meyer's singleton
	{
		static RTIConnector rti_conn;
		return rti_conn;
	}
	
	bool shutdown();

	RTIConnector(); //actual valid ctor
	bool SetThreadAffinities(DDS_DomainParticipantQos& participant_qos);
	bool SetThreadPriorities(DDS_DomainParticipantQos& participant_qos);
	bool SetThreadPriorities(DDS_PublisherQos& publisher_qos);
	//PRE: Should reach here only during application exit */
	~RTIConnector()
	{
		shutdown();
	}
	// disable - for singleton
	RTIConnector(const RTIConnector&);
	RTIConnector& operator = (const RTIConnector&);
};

#endif /* COMMON_H_ */
