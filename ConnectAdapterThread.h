/* 
 * File:   ConnectAdapterThread.h
 * Author: Gunendu
 *
 * Created on 25 September, 2012, 6:24 PM
 */

#ifndef CONNECTADAPTERTHREAD_H
#define	CONNECTADAPTERTHREAD_H

#include "dataTypes.h"
#include "StartLineProcess.h"

class ConnectAdapterThread : public CBasicThread {
private:
    tagThreadInfo m_threadInfo;
    timespec m_stTimeInterval;
    AdapaterThreadStore m_adapaterthreadStore;
    tapServerInfo tapAdpaterInfo;
    tapServerDetails tapServerObject;
    ItrtapServerDetails itertapServer;
    DBConnection *lDBConnectionObject;

public:
    LIBSSH2_CHANNEL *channel2;
    LIBSSH2_SESSION *session;
    IpPathMap ipPathMapObj;


    ConnectAdapterThread(int nThreadIndex);
    ~ConnectAdapterThread();

    inline void setServerInfo(tapServerInfo& adapterInfo) {
        tapAdpaterInfo = adapterInfo;
    }

    inline tapServerInfo getServerInfo() {
        return tapAdpaterInfo;
    }

    inline IpPathMap getPathInfo()
    {
        return ipPathMapObj;
    }

    int ParseTapServerConfigFile(const char* pcFileName, tapServerInfo& tapServerInfo,StartLineProcessConnector *lpconn);
    RET_CODE Process(void* pcThreadParam);
    bool collect(MONITORING::leaseProcessStart *sample);

    static RET_CODE waitsocket(int socket_fd, LIBSSH2_SESSION *session);



};



#endif	/* CONNECTADAPTERTHREAD_H */

