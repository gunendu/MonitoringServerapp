/* 
 * File:   ddsinterface.h
 * Author: siddharth
 *
 * Created on 7 August, 2012, 5:52 PM
 */

#ifndef DDSINTERFACE_H
#define	DDSINTERFACE_H


class CDDSInterface
{
private :
    
    DDSDomainParticipant* m_participant;
    DDSSubscriber*        m_subscriber;
    DDSPublisher*         m_publisher;
    int                   m_nDomain;  
    
private :
    CDDSInterface(const int nDomain);
    CDDSInterface(const CDDSInterface& other);
    CDDSInterface& operator =(const CDDSInterface& other);
    
    bool SetThreadAffinities(DDS_DomainParticipantQos& participant_qos);
    bool SetThreadPriorities(DDS_DomainParticipantQos& participant_qos);
    bool SetThreadPriorities(DDS_PublisherQos& publisher_qos);
    
    bool Shutdown();
    
    ~CDDSInterface()
    {
        Shutdown();
    }
	
    
public:
    static CDDSInterface& GetInstanceHandle(const int nDomain = -1)
    {
        static CDDSInterface g_cDDSInterface(nDomain);
        return g_cDDSInterface;
    }
    
    static DDSDomainParticipant* GetDomainParticipant()
    {
        return GetInstanceHandle().m_participant;
    }
    
    static DDSSubscriber* GetSubscriber()
    {
        return GetInstanceHandle().m_subscriber;
    }
    
    static DDSPublisher* GetPublisher()
    {
        return GetInstanceHandle().m_publisher;
    }
    
};


#endif	/* DDSINTERFACE_H */

