/* 
 * File:   serverConnectThread.h
 * Author: Gunendu das
 *
 * Created on 4 September, 2012, 12:39 PM
 */

#ifndef SERVERCONNECTTHREAD_H
#define	SERVERCONNECTTHREAD_H

#include "dataTypes.h"
#include "StartLineProcess.h"


class serverConnectThread : public CBasicThread
{
    
    private:
        tagThreadInfo                m_threadInfo;
        timespec                     m_stTimeInterval;                
        //serverDetails                serverObject;
        //ItrServerDetails             serverIter;
        tagServerInfo                sdt;
        int noOfProcess;
        
        
        
    public:
     LIBSSH2_CHANNEL *channel;
     LIBSSH2_SESSION *session;  
     IpPathMap ipPathMapObj;
     
    serverConnectThread(int nThreadIndex);
    ~serverConnectThread();
    inline IpPathMap getPathInfo()
    {
        return ipPathMapObj;
    }
	   
    StartLineProcessConnector *conn;
    
    RET_CODE ParseServerConfigFile(const char* pcFileName, tagServerInfo& ServerInfo,StartLineProcessConnector *lpconn);
    
    RET_CODE Process(void* pcThreadParam);
    
    static RET_CODE waitsocket(int socket_fd,LIBSSH2_SESSION *session);
             
};

#endif	/* SERVERCONNECTTHREAD_H */

