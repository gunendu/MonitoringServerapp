/* 
 * File:   Controller.h
 * Author: Gunendu Das
 *
 * Created on 10 September, 2012, 1:31 PM
 */

#include "basicthread.h"
#include "serverConnectThread.h"
#include "StartLineProcess.h"
#include "Monitoring.h"


#ifndef CONTROLLER_H
#define	CONTROLLER_H



#endif	/* CONTROLLER_H */

class CControllerThread {
private:
    
    int m_tTotalThreads;
    int m_tTotalTapconnection;
    ThreadStore m_vThreadStore;
    ItrThreadStore iterThreadStore;

    tapServerDetails tapServerObject;
    AdapaterThreadStore m_vAdapterThreadStore;
    ItrAdapaterThreadStore iterAdapterthreadStore;
    CIPCPublisher<MONITORING::tagServerInfo, MONITORING::tagServerInfoTypeSupport,
    MONITORING::tagServerInfoDataWriter>* m_pcPublisherObject;

    CIPCPublisher<MONITORING::tapServerInfo, MONITORING::tapServerInfoTypeSupport,
    MONITORING::tapServerInfoDataWriter>* m_pcAdapterPublisherObject;
    
    CIPCPublisher<MONITORING::pslInfo, MONITORING::pslInfoTypeSupport,
    MONITORING::pslInfoDataWriter>* m_pslInfoPublisherObject;

    static CControllerThread *singleInstance;
    tagServerInfo lstServer;
    tapServerInfo lstadapaterInfo;
    ConnectAdapterThread *ladapterConnectThread;
    serverConnectThread *lstServerconnectThread;
    serverConnectThread2 *lstServerconnectThread2;
    serverConnectThread3 *lstServerconnectThread3;
    CControllerThread();

public:

    
    virtual ~CControllerThread();
    int socketId;
    ConnectAdapterThread* InitiliazeAdapterController(StartLineProcessConnector *conn);

    serverConnectThread2* InitiliazeController2();
    
    serverConnectThread3* InitiliazeController3();
    
    serverConnectThread* InitiliazeController(StartLineProcessConnector *conn);

    RET_CODE ParseTapServerConfigFile(const char* pcFileName, tapServerInfo& tapServerInfo);

    RET_CODE ParseServerConfigFile(const char* pcFileName, tagServerInfo& ServerInfo);

    RET_CODE CreateAdapterWriter(const char* pcLibraryName, const char* pcProfileName);

    RET_CODE CreateWriter(const char* pcLibraryName, const char* pcProfileName);

    RET_CODE CommandWriter(const char* pcLibraryName, const char* pcProfileName);
    
    RET_CODE SendAdapterDataToUI(MONITORING::tapServerInfo &stServerInfo);

    RET_CODE SendDataToUI(MONITORING::tagServerInfo& stServerInfo);

    RET_CODE SendcommandDataToUI(MONITORING::pslInfo& stServerInfo);
    
    RET_CODE makeSocketConnection();
    
    serverConnectThread* GetThread(int nThreadIndex);

    static CControllerThread* getInstance();

    bool is_connected(int sock);

    serverDetails                serverObject;
    ItrServerDetails             serverIter;

};
