#include "includes.h"

extern CLogger g_cSystemLogger;

CControllerThread::CControllerThread() {
    CDDSInterface::GetInstanceHandle(4);


    m_pcAdapterPublisherObject = new CIPCPublisher<MONITORING::tapServerInfo, MONITORING::tapServerInfoTypeSupport,
            MONITORING::tapServerInfoDataWriter > ("ADAPTER_ACK");

    m_pcPublisherObject = new CIPCPublisher<MONITORING::tagServerInfo, MONITORING::tagServerInfoTypeSupport,
            MONITORING::tagServerInfoDataWriter > ("MONITORING_ACK");
    
    m_pslInfoPublisherObject = new CIPCPublisher<MONITORING::pslInfo, MONITORING::pslInfoTypeSupport,
            MONITORING::pslInfoDataWriter > ("PSL_ACK");

}

RET_CODE CControllerThread::CreateAdapterWriter(const char* pcLibraryName, const char* pcProfileName) {
    return m_pcAdapterPublisherObject->CreateWriter(pcLibraryName, pcProfileName);
}

RET_CODE CControllerThread::CreateWriter(const char* pcLibraryName, const char* pcProfileName) {
    return m_pcPublisherObject->CreateWriter(pcLibraryName, pcProfileName);
}

RET_CODE CControllerThread::CommandWriter(const char* pcLibraryName, const char* pcProfileName)
{
    return m_pslInfoPublisherObject->CreateWriter(pcLibraryName,pcProfileName);
}


RET_CODE CControllerThread::SendAdapterDataToUI(MONITORING::tapServerInfo &stAdapaterServerInfo) {
    return m_pcAdapterPublisherObject->SendData(stAdapaterServerInfo);
}

RET_CODE CControllerThread::SendDataToUI(MONITORING::tagServerInfo& stServerInfo) {
    return m_pcPublisherObject->SendData(stServerInfo);
    
}

RET_CODE CControllerThread::SendcommandDataToUI(MONITORING::pslInfo& stServerInfo) {
    return m_pslInfoPublisherObject->SendData(stServerInfo);
    
}

CControllerThread::~CControllerThread() {
    delete lstServerconnectThread;
    delete ladapterConnectThread;
    delete m_pcPublisherObject;
    delete m_pslInfoPublisherObject;
    delete m_pcAdapterPublisherObject;
    delete singleInstance;
}
CControllerThread* CControllerThread::singleInstance = NULL;

CControllerThread* CControllerThread::getInstance() {

    if (singleInstance == NULL) {
        singleInstance = new CControllerThread();
        return singleInstance;
    } else {
        return singleInstance;
    }
}

ConnectAdapterThread* CControllerThread::InitiliazeAdapterController(StartLineProcessConnector *conn) {
    ladapterConnectThread = new ConnectAdapterThread(1);
    ladapterConnectThread->ParseTapServerConfigFile("tap_server_config.dat", lstadapaterInfo,conn);
    ladapterConnectThread->Start();

    if (FAILURE == CreateAdapterWriter("Monitoring_Library", "Monitoring_Profile")) {
        g_cSystemLogger.LogMessage("(%s:%s:%d)::Failure Create writer", LOG_LOCATION);
    }
    return ladapterConnectThread;
}

serverConnectThread* CControllerThread::InitiliazeController(StartLineProcessConnector *conn) {
    lstServerconnectThread = new serverConnectThread(0);
    lstServerconnectThread->ParseServerConfigFile("Server_config.dat", lstServer,conn);
    lstServerconnectThread->Start();
   /* if (FAILURE == CreateWriter("Monitoring_Library", "Monitoring_Profile")) {
        g_cSystemLogger.LogMessage("(%s:%s:%d)::Failure Create writer", LOG_LOCATION);
    }*/

    return lstServerconnectThread;
}

serverConnectThread2* CControllerThread::InitiliazeController2() {
    lstServerconnectThread2 = new serverConnectThread2(2);
    //lstServerconnectThread->ParseServerConfigFile("Server_config.dat", lstServer,conn);
    lstServerconnectThread2->Start();
   /* if (FAILURE == CreateWriter("Monitoring_Library", "Monitoring_Profile")) {
        g_cSystemLogger.LogMessage("(%s:%s:%d)::Failure Create writer", LOG_LOCATION);
    }*/

    return lstServerconnectThread2;
}

serverConnectThread3* CControllerThread::InitiliazeController3() {
    lstServerconnectThread3 = new serverConnectThread3(3);
    //lstServerconnectThread->ParseServerConfigFile("Server_config.dat", lstServer,conn);
    lstServerconnectThread3->Start();
   /* if (FAILURE == CreateWriter("Monitoring_Library", "Monitoring_Profile")) {
        g_cSystemLogger.LogMessage("(%s:%s:%d)::Failure Create writer", LOG_LOCATION);
    }*/

    return lstServerconnectThread3;
}

int CControllerThread:: makeSocketConnection()
{
    
    struct sockaddr_in sin;
    socketId = socket(AF_INET, SOCK_STREAM, 0);
    if(socketId<0)
    {
       g_cSystemLogger.LogMessage("(%s:%s(:%d)::Error Opening Socket %d", LOG_LOCATION,socketId); 
    }
    sin.sin_family = AF_INET;
    sin.sin_port = htons(1234);
    sin.sin_addr.s_addr = inet_addr("192.168.30.134");
    int rVal;
     if (rVal=connect(socketId, (struct sockaddr*) (&sin),
                        sizeof (struct sockaddr_in)) != 0) 
     {
      g_cSystemLogger.LogMessage("(%s:%s(:%d)::failure establishing socket connection, rValue %d", LOG_LOCATION,rVal);
      return 0;
     }
    g_cSystemLogger.LogMessage("(%s:%s(:%d)::Success establishing socket connection", LOG_LOCATION);
}

bool CControllerThread::is_connected(int sock)
{
    int error =0;
    socklen_t len = sizeof(error);
    int retval = getsockopt(socketId,SOL_SOCKET,SO_ERROR,&error,&len);
    
    if(retval == 0)
	return true;
    else
        return false;    	
}





