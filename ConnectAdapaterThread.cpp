#include "includes.h"
extern CLogger g_cSystemLogger;
#define TRUE 1
#define FALSE 0
#define CM 0
#define FO 1
#define CMFO 2

ConnectAdapterThread::ConnectAdapterThread(int nThreadIndex) {
    m_threadInfo.nThreadIndex = nThreadIndex;
    lDBConnectionObject = new DBConnection();
}

ConnectAdapterThread::~ConnectAdapterThread() {
    tapServerObject.clear();
    delete lDBConnectionObject;
    lDBConnectionObject = NULL;
}

RET_CODE ConnectAdapterThread::ParseTapServerConfigFile(const char* pcFileName, tapServerInfo& tapServerInfo,StartLineProcessConnector *lpconn) {
    assert(pcFileName);

    ConfigParser_t lCConfigParser_t;

    if (-1 == lCConfigParser_t.readFile(pcFileName)) {
        std::cout << __LINE__ << std::endl;
        return false;
    }
    char buffer[20] = {0};
    char path[100] = {0};
    int noCons = 0;
    string lstrBuffer;
    if (0 == lCConfigParser_t.getValue("TotalTapServers", "NoOfConnections", &noCons)) {
        std::cout << __LINE__ << std::endl;
        return false;
    }
    g_cSystemLogger.LogMessage("(%s:%s:%d):: totalServers %d", LOG_LOCATION, noCons);

    for (int i = 1; i < noCons + 1; i++) {

        sprintf(buffer, "%s%d", "TapServer", i);
        if (0 == lCConfigParser_t.getValue(buffer, "Ipadress", &lstrBuffer)) {
            std::cout << __LINE__ << std::endl;
            return false;
        }
        strncpy(tapServerInfo.ipAdress, lstrBuffer.c_str(), 20);
        lstrBuffer.clear();
        tapServerInfo.ipAdress[16] = '\0';



        sprintf(buffer, "%s%d", "TapServer", i);
        if (0 == lCConfigParser_t.getValue(buffer, "user", &lstrBuffer)) {
            std::cout << __LINE__ << std::endl;
            return false;
        }
        strncpy(tapServerInfo.userName, lstrBuffer.c_str(), 20);
        lstrBuffer.clear();
        tapServerInfo.userName[20] = '\0';



        if (0 == lCConfigParser_t.getValue(buffer, "password", &lstrBuffer)) {
            std::cout << __LINE__ << std::endl;
            return false;
        }
        strncpy(tapServerInfo.password, lstrBuffer.c_str(), 20);
        lstrBuffer.clear();
        tapServerInfo.password[20] = '\0';
        int port;
        if (0 == lCConfigParser_t.getValue(buffer, "port", &port)) {
            std::cout << __LINE__ << std::endl;
            return false;
        }

        tapServerInfo.port = port;

        if (0 == lCConfigParser_t.getValue(buffer, "Line name", &lstrBuffer)) {
            std::cout << __LINE__ << std::endl;
            return false;
        }
        strncpy(tapServerInfo.lineType, lstrBuffer.c_str(), 6);
        lstrBuffer.clear();
        tapServerInfo.lineType[6] = '\0';

        if (0 == lCConfigParser_t.getValue(buffer, "Path", &lstrBuffer)) {
            std::cout << __LINE__ << std::endl;
            return false;
        }
        strncpy(path, lstrBuffer.c_str(), 100);
        lstrBuffer.clear();
        path[100] = '\0';



        if (0 == lCConfigParser_t.getValue(buffer, "dbUserName", &lstrBuffer)) {
            std::cout << __LINE__ << std::endl;
            return false;
        }
        strncpy(tapServerInfo.dbUserName, lstrBuffer.c_str(), 20);
        lstrBuffer.clear();
        tapServerInfo.dbUserName[20] = '\0';



        if (0 == lCConfigParser_t.getValue(buffer, "dbPassword", &lstrBuffer)) {
            std::cout << __LINE__ << std::endl;
            return false;
        }
        strncpy(tapServerInfo.dbPassword, lstrBuffer.c_str(), 20);
        lstrBuffer.clear();
        tapServerInfo.dbPassword[20] = '\0';



        if (0 == lCConfigParser_t.getValue(buffer, "dbName", &lstrBuffer)) {
            std::cout << __LINE__ << std::endl;
            return false;
        }
        strncpy(tapServerInfo.dbName, lstrBuffer.c_str(), 20);
        lstrBuffer.clear();
        tapServerInfo.dbName[20] = '\0';


        if (0 == lCConfigParser_t.getValue(buffer, "dbPort", &lstrBuffer)) {
            std::cout << __LINE__ << std::endl;
            return false;
        }
        strncpy(tapServerInfo.dbPort, lstrBuffer.c_str(), 20);
        lstrBuffer.clear();
        tapServerInfo.dbPort[20] = '\0';


        tapServerObject.push_back(tapServerInfo);
        ipPathMapObj.insert(std::pair<std::string,std::string>(tapServerInfo.ipAdress,path));

    }

    lpconn->setPath(ipPathMapObj);
    return SUCCESS;
}

RET_CODE ConnectAdapterThread::waitsocket(int socket_fd, LIBSSH2_SESSION *session) {
    struct timeval timeout;
    int rc;
    fd_set fd;
    fd_set *writefd = NULL;
    fd_set *readfd = NULL;
    int dir;

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    FD_ZERO(&fd);

    FD_SET(socket_fd, &fd);

    dir = libssh2_session_block_directions(session);

    if (dir & LIBSSH2_SESSION_BLOCK_INBOUND)
        readfd = &fd;
    if (dir & LIBSSH2_SESSION_BLOCK_OUTBOUND)
        writefd = &fd;

    rc = select(socket_fd + 1, readfd, writefd, NULL, &timeout);

    return rc;
}

RET_CODE ConnectAdapterThread::Process(void* pcThreadParam) {
    iterServerInfoMap iterMap;
    typedef tbb::concurrent_vector<ServerInfoMap> mapStore;
    typedef mapStore::iterator iterMapVector;
    mapStore mapStoreObj;

    while (1) {
        int count = 0;

        bool breakflag;
        for (itertapServer = tapServerObject.begin(); itertapServer != tapServerObject.end(); itertapServer++) {
            int globalCounter = 0;
            int lcounter1 = 0;
            int lcounter2 = 0;
            if (IsThreadInShutdown()) {
                breakflag = true;
                break;
            }
            tapServerInfo &adapterInfo = *itertapServer;
            char* userName = adapterInfo.userName;
            char* passWord = adapterInfo.password;
            char* dbUserName = adapterInfo.dbUserName;
            char* dbPassowrd = adapterInfo.dbPassword;
            char* dbName = adapterInfo.dbName;
            char* dbPort = adapterInfo.dbPort;
            char* hostAdress = adapterInfo.ipAdress;
            char* lineType = adapterInfo.lineType;
            ServerInfoMap m_MapObject;

            if (!(adapterInfo.bdStatus)) {

                lDBConnectionObject->getQueryResult(m_MapObject, dbUserName, dbPassowrd, dbName, dbPort, hostAdress, lineType);
                mapStoreObj.push_back(m_MapObject);
                lDBConnectionObject->Close();
                adapterInfo.bdStatus = true;
            }
            char commandBuffer[1000] = {0};
            char *lpUserAuthList;
            char buffer[50] = {0};
            char c[20] = {0};
            struct sockaddr_in sin;
            int rc, sock, auth_pw = 0;
            sprintf(buffer, "ping -c 3 %s | grep -c %s", adapterInfo.ipAdress, "\"3 received\"");
            FILE *p = popen(buffer, "r");
            fgets(c, 10, p);
            pclose(p);

            if (atoi(c) == 1) {
                adapterInfo.serverStatus = true;
            } else {
                adapterInfo.serverStatus = false;
            }

            g_cSystemLogger.LogMessage("(%s:%s:%d):: Debug", LOG_LOCATION);
            rc = libssh2_init(0);
            if ((adapterInfo.serverStatus == true)
                    && (adapterInfo.connectStatus == false)) {

                sock = socket(AF_INET, SOCK_STREAM, 0);
                adapterInfo.socketId = sock;
                sin.sin_family = AF_INET;
                sin.sin_port = htons(22);
                sin.sin_addr.s_addr = inet_addr(adapterInfo.ipAdress);
                if (connect(sock, (struct sockaddr*) (&sin),
                        sizeof (struct sockaddr_in)) != 0) {
                    g_cSystemLogger.LogMessage("(%s:%s(:%d)::failure establishing ssh", LOG_LOCATION);
                    return -1;
                }

                session = libssh2_session_init();
                if (libssh2_session_handshake(session, sock)) {
                    g_cSystemLogger.LogMessage("(%s:%s(:%d):: failure ssh session initiation", LOG_LOCATION);
                    count++;
                    continue;
                }

                lpUserAuthList = libssh2_userauth_list(session, userName, strlen(userName));

                if (NULL == lpUserAuthList) {
                    g_cSystemLogger.LogMessage("(%s:%s(:%d):: get user auth list failed", LOG_LOCATION);

                }
                char lcPreferredAuthMethod[20] = "password";
                g_cSystemLogger.LogMessage("(%s:%s(:%d)::authentication methods(%s)", LOG_LOCATION, lpUserAuthList);
                if (strstr(lpUserAuthList, lcPreferredAuthMethod) != NULL) {
                    auth_pw |= 1;
                    g_cSystemLogger.LogMessage("(%s:%s(:%d)::authentication methods(%d)", LOG_LOCATION, auth_pw);
                }
                if (auth_pw & 1) {
                    if (libssh2_userauth_password(session, userName, passWord)) {
                        g_cSystemLogger.LogMessage("(%s:%s(:%d)::Authentation by password failed\n", LOG_LOCATION);
                    } else {
                        g_cSystemLogger.LogMessage("(%s:%s(:%d)::Authentation by password succeded\n", LOG_LOCATION);
                    }
                }

                adapterInfo.connectStatus = true;
                adapterInfo.session = session;

            }

            if (adapterInfo.serverStatus == false) {
                count++;
                continue;
            }

            if (rc != 0) {
                g_cSystemLogger.LogMessage("(%s:%s:%d)::failure establishing ssh", LOG_LOCATION);
                return 1;
            }
            if (mapStoreObj.at(count).size() != 0) {
                tapServerInfoMap &MapObject = mapStoreObj.at(count++);

                if ((strcmp(adapterInfo.lineType, "CM") == 0)) {

                    while ((channel2 = libssh2_channel_open_session(adapterInfo.session)) == NULL &&
                            libssh2_session_last_error(adapterInfo.session, NULL, NULL, 0) == LIBSSH2_ERROR_EAGAIN) {
                        waitsocket(sock, adapterInfo.session);
                    }

                    if (channel2 == NULL) {
                        g_cSystemLogger.LogMessage("(%s:%s(:%d))ssh channel opening fail", LOG_LOCATION);
                    }
                    for (iterMap = MapObject.begin(); iterMap != MapObject.end(); iterMap++) {

                        sprintf(commandBuffer, "%s  %s%s%s%d%s%s%s", "/bin/netstat -n|/bin/grep -c", "\"", iterMap->second.c_str(), ":", 9601, ".*", "ESTABLISHED", "\"");

                        g_cSystemLogger.LogMessage("(%s:%s(:%d))::command for netstat %s\n", LOG_LOCATION, commandBuffer);
                        while ((rc = libssh2_channel_exec(channel2, commandBuffer)) == LIBSSH2_ERROR_EAGAIN) {
                            waitsocket(sock, session);
                        }

                        size_t lnReturnCode;
                        lnReturnCode = libssh2_channel_read(channel2, commandBuffer, sizeof (commandBuffer));


                        if (commandBuffer[0] == '1') {
                            strncpy(adapterInfo.lineInfo[lcounter1].ipv4adresss, iterMap->second.c_str(), 16);
                            adapterInfo.lineInfo[lcounter1].ipv4adresss[16] = '\0';
                            adapterInfo.lineInfo[lcounter1].userId = iterMap->first;
                            adapterInfo.lineInfo[lcounter1].status = TRUE;



                        }
                        else if (commandBuffer[0] == '0') {

                            strncpy(adapterInfo.lineInfo[lcounter1].ipv4adresss, iterMap->second.c_str(), 16);
                            adapterInfo.lineInfo[lcounter1].ipv4adresss[16] = '\0';
                            adapterInfo.lineInfo[lcounter1].status = FALSE;
                            adapterInfo.lineInfo[lcounter1].userId = iterMap->first;


                        }
                        if (LIBSSH2_ERROR_EAGAIN == lnReturnCode) {
                            waitsocket(sock, adapterInfo.session);
                        }

                        lcounter1++;
                        memset(commandBuffer, 0, sizeof (commandBuffer));
                        libssh2_channel_free(channel2);
                        channel2 = NULL;


                    }
                } else if ((strcmp(adapterInfo.lineType, "FO") == 0)) {


                    while ((channel2 = libssh2_channel_open_session(adapterInfo.session)) == NULL &&
                            libssh2_session_last_error(adapterInfo.session, NULL, NULL, 0) == LIBSSH2_ERROR_EAGAIN) {
                        waitsocket(sock, adapterInfo.session);
                    }
                    for (iterMap = MapObject.begin(); iterMap != MapObject.end(); iterMap++) {
                        sprintf(commandBuffer, "%s  %s%s%s%d%s%s%s", "/bin/netstat -n|/bin/grep -c", "\"", iterMap->second.c_str(), ":", 9602, ".*", "ESTABLISHED", "\"");


                        g_cSystemLogger.LogMessage("(%s:%s(:%d))::command for netstat %s\n", LOG_LOCATION, commandBuffer);
                        while ((rc = libssh2_channel_exec(channel2, commandBuffer)) == LIBSSH2_ERROR_EAGAIN) {
                            waitsocket(sock, session);
                        }
                        //                   // memset(commandBuffer, 0, sizeof (commandBuffer));
                        size_t lnReturnCode;
                        lnReturnCode = libssh2_channel_read(channel2, commandBuffer, sizeof (commandBuffer));


                        if (commandBuffer[0] == '1') {

                            strncpy(adapterInfo.lineInfo[lcounter1].ipv4adresss, iterMap->second.c_str(), 16);
                            adapterInfo.lineInfo[lcounter1].ipv4adresss[16] = '\0';

                            adapterInfo.lineInfo[lcounter1].status = TRUE;
                            adapterInfo.lineInfo[lcounter1].userId = iterMap->first;



                        } else if (commandBuffer[0] == '0') {
                            strncpy(adapterInfo.lineInfo[lcounter1].ipv4adresss, iterMap->second.c_str(), 16);
                            adapterInfo.lineInfo[lcounter1].ipv4adresss[16] = '\0';

                            adapterInfo.lineInfo[lcounter1].status = FALSE;
                            adapterInfo.lineInfo[lcounter1].userId = iterMap->first;

                        }
                        if (LIBSSH2_ERROR_EAGAIN == lnReturnCode) {
                            waitsocket(sock, adapterInfo.session);
                        }
                        lcounter1++;
                        memset(commandBuffer, 0, sizeof (commandBuffer));
                        libssh2_channel_free(channel2);
                        channel2 = NULL;

                    }
                }
                else if ((strcmp(adapterInfo.lineType, "CM FO") == 0)) {

                    int count = 0;
                    int port;
                    for (iterMap = MapObject.begin(); iterMap != MapObject.end(); iterMap++) {
                        if (count == 0) {
                            port = 9601;
                        } else if (count == 1) {
                            port = 9602;
                        }
                        while ((channel2 = libssh2_channel_open_session(adapterInfo.session)) == NULL &&
                                libssh2_session_last_error(adapterInfo.session, NULL, NULL, 0) == LIBSSH2_ERROR_EAGAIN) {
                            waitsocket(sock, adapterInfo.session);
                        }

                        if (channel2 == NULL) {
                            g_cSystemLogger.LogMessage("(%s:%s(:%d))ssh channel opening fail", LOG_LOCATION);
                        }
                        sprintf(commandBuffer, "%s  %s%s%s%d%s%s%s", "/bin/netstat -n|/bin/grep -c", "\"", iterMap->second.c_str(), ":", port, ".*", "ESTABLISHED", "\"");

                        g_cSystemLogger.LogMessage("(%s:%s(:%d))::command for netstat %s\n", LOG_LOCATION, commandBuffer);
                        while ((rc = libssh2_channel_exec(channel2, commandBuffer)) == LIBSSH2_ERROR_EAGAIN) {
                            waitsocket(sock, session);
                        }

                        size_t lnReturnCode;
                        lnReturnCode = libssh2_channel_read(channel2, commandBuffer, sizeof (commandBuffer));


                        if (count == 0) {
                            if (commandBuffer[0] == '1') {

                                strncpy(adapterInfo.lineInfo[lcounter1].ipv4adresss, iterMap->second.c_str(), 16);
                                adapterInfo.lineInfo[lcounter1].ipv4adresss[16] = '\0';
                                adapterInfo.lineInfo[lcounter1].status = TRUE;
                                adapterInfo.lineInfo[lcounter1].userId = iterMap->first;


                            }
                            else if (commandBuffer[0] == '0') {

                                strncpy(adapterInfo.lineInfo[lcounter1].ipv4adresss, iterMap->second.c_str(), 16);
                                adapterInfo.lineInfo[lcounter1].ipv4adresss[16] = '\0';
                                adapterInfo.lineInfo[lcounter1].status = FALSE;
                                adapterInfo.lineInfo[lcounter1].userId = iterMap->first;


                            }
                        } else if (count == 1) {
                            if (commandBuffer[0] == '1') {

                                strncpy(adapterInfo.lineInfo[lcounter1].ipv4adresss, iterMap->second.c_str(), 16);
                                adapterInfo.lineInfo[lcounter1].ipv4adresss[16] = '\0';
                                adapterInfo.lineInfo[lcounter1].status = TRUE;
                                adapterInfo.lineInfo[lcounter1].userId = iterMap->first;


                            }
                            else if (commandBuffer[0] == '0') {

                                strncpy(adapterInfo.lineInfo[lcounter1].ipv4adresss, iterMap->second.c_str(), 16);
                                adapterInfo.lineInfo[lcounter1].ipv4adresss[16] = '\0';
                                adapterInfo.lineInfo[lcounter1].status = FALSE;
                                adapterInfo.lineInfo[lcounter1].userId = iterMap->first;


                            }
                        }
                        if (LIBSSH2_ERROR_EAGAIN == lnReturnCode) {
                            waitsocket(sock, adapterInfo.session);
                        }

                        lcounter1++;
                        memset(commandBuffer, 0, sizeof (commandBuffer));
                        libssh2_channel_free(channel2);
                        channel2 = NULL;

                        count++;
                    }
                }
                else if (strcmp(adapterInfo.lineType, "BSE") == 0) {



                    if (channel2 == NULL) {
                        g_cSystemLogger.LogMessage("(%s:%s(:%d))ssh channel opening fail", LOG_LOCATION);
                    }
                    for (iterMap = MapObject.begin(); iterMap != MapObject.end(); iterMap++) {
                        sprintf(commandBuffer, "%s  %s%s%s%d%s%s%s", "/bin/netstat -n|/bin/grep -c", "\"", iterMap->second.c_str(), ":", 5001, ".*", "ESTABLISHED", "\"");

                        while ((channel2 = libssh2_channel_open_session(adapterInfo.session)) == NULL &&
                                libssh2_session_last_error(adapterInfo.session, NULL, NULL, 0) == LIBSSH2_ERROR_EAGAIN) {
                            waitsocket(sock, adapterInfo.session);
                        }
                        g_cSystemLogger.LogMessage("(%s:%s(:%d))::command for netstat %s\n", LOG_LOCATION, commandBuffer);
                        while ((rc = libssh2_channel_exec(channel2, commandBuffer)) == LIBSSH2_ERROR_EAGAIN) {
                            waitsocket(sock, session);
                        }
                        //                   // memset(commandBuffer, 0, sizeof (commandBuffer));
                        size_t lnReturnCode;
                        lnReturnCode = libssh2_channel_read(channel2, commandBuffer, sizeof (commandBuffer));


                        if (commandBuffer[0] > '1') {

                            strncpy(adapterInfo.lineInfo[lcounter2].ipv4adresss, iterMap->second.c_str(), 16);
                            adapterInfo.lineInfo[lcounter2].ipv4adresss[16] = '\0';

                            adapterInfo.lineInfo[lcounter2].status = TRUE;
                            adapterInfo.lineInfo[lcounter2].userId = iterMap->first;


                        } else if (commandBuffer[0] == '0') {
                            strncpy(adapterInfo.lineInfo[lcounter2].ipv4adresss, iterMap->second.c_str(), 16);
                            adapterInfo.lineInfo[lcounter2].ipv4adresss[16] = '\0';

                            adapterInfo.lineInfo[lcounter2].status = FALSE;
                            adapterInfo.lineInfo[lcounter2].userId = iterMap->first;


                        }
                        if (LIBSSH2_ERROR_EAGAIN == lnReturnCode) {
                            waitsocket(sock, adapterInfo.session);
                        }
                        lcounter2++;
                        memset(commandBuffer, 0, sizeof (commandBuffer));
                        libssh2_channel_free(channel2);
                        channel2 = NULL;
                    }
                }
            }
            globalCounter = lcounter1 + lcounter2;
            CcopyStructure::copyAdapterData(adapterInfo, globalCounter);

        }
        if (breakflag) {
            break;
        }
        sleep(1);
    }

    for (itertapServer = tapServerObject.begin(); itertapServer != tapServerObject.end(); itertapServer++) {

        tapServerInfo adapterinfo;
        adapterinfo = *itertapServer;
        libssh2_session_disconnect(adapterinfo.session, "Shutting down,thank you");
        libssh2_session_free(adapterinfo.session);
        close(adapterinfo.socketId);
        libssh2_exit();

    }

    return 1;
}


