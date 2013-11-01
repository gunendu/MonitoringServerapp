#include "includes.h"

extern CLogger g_cSystemLogger;
#define TRUE 1
#define FALSE 0
#define CM 0
#define FO 1

serverConnectThread::serverConnectThread(int nThreadIndex) {
    //singleInstance = CControllerThread::getInstance();
    m_threadInfo.nThreadIndex = nThreadIndex;

}

serverConnectThread::~serverConnectThread() {
    //serverObject.clear();
}

RET_CODE serverConnectThread::ParseServerConfigFile(const char* pcFileName, tagServerInfo& ServerInfo,StartLineProcessConnector *lpconn) {
    assert(pcFileName);
    
    CControllerThread *singleInstance;
    singleInstance = CControllerThread::getInstance();
    
    conn = lpconn;
    ConfigParser_t lCConfigParser_t;
    if (-1 == lCConfigParser_t.readFile(pcFileName)) {
        std::cout << __LINE__ << std::endl;
        return false;
     }
    char buffer [20];
    char processBuffer[128];
    char spaceBuffer[128];
    char fileBuffer[128];
    string section;
    string processname;
    string space;
    string option;
    string lstrBuffer;
    string lstrTemp;
    string startPath;
    string stopPath;
    char path[1024];
    int noCons = 0;
    int noOfLines = 0;
    int noOfProcesses = 0;
    int noOfFilePath = 0;
    int noOfSpace = 0;
    if (0 == lCConfigParser_t.getValue("TotalServers", "NoOfConnections", &noCons)) {
        return false;
    }

    for (int i = 1; i < noCons + 1; i++) {
        sprintf(buffer, "%s%d", "server", i);

        stringstream ss;
        ss << buffer;
        ss >> section;
        if (0 == lCConfigParser_t.getValue(section, "Ipadress", &lstrBuffer)) {
            
            return false;
        }
        strncpy(ServerInfo.ipAdress, lstrBuffer.c_str(), 32);
        lstrBuffer.clear();
        ServerInfo.ipAdress[32] = '\0';


        if (0 == lCConfigParser_t.getValue(section, "user", &lstrBuffer)) {
            
            return false;
        }
        strncpy(ServerInfo.userName, lstrBuffer.c_str(), 15);
        lstrBuffer.clear();
        ServerInfo.userName[15] = '\0';


        if (0 == lCConfigParser_t.getValue(section, "password", &lstrBuffer)) {
            return false;

        }
        strncpy(ServerInfo.password, lstrBuffer.c_str(), 15);
        lstrBuffer.clear();
        ServerInfo.password[20] = '\0';


        if (0 == lCConfigParser_t.getValue(section, "dbUserName", &lstrBuffer)) {
            

        }
        strncpy(ServerInfo.dbUserName, lstrBuffer.c_str(), 20);



        lstrBuffer.clear();
        ServerInfo.dbUserName[20] = '\0';



        if (0 == lCConfigParser_t.getValue(section, "dbPassword", &lstrBuffer)) {
            

        }
        strncpy(ServerInfo.dbPassword, lstrBuffer.c_str(), 20);
        lstrBuffer.clear();
        ServerInfo.dbPassword[20] = '\0';



        if (0 == lCConfigParser_t.getValue(section, "dbName", &lstrBuffer)) {
          

        }
        strncpy(ServerInfo.dbName, lstrBuffer.c_str(), 20);
        lstrBuffer.clear();
        ServerInfo.dbName[20] = '\0';


        if (0 == lCConfigParser_t.getValue(section, "dbPort", &lstrBuffer)) {
            

        }
        strncpy(ServerInfo.dbPort, lstrBuffer.c_str(), 20);
        lstrBuffer.clear();
        ServerInfo.dbPort[20] = '\0';
        
//        if (0 == lCConfigParser_t.getValue(section, "stopPath", &lstrBuffer)) {
//            
//
//        }
//        stopPath = lstrBuffer;
//        lstrBuffer.clear();
        
     

        if (0 == lCConfigParser_t.getValue(section, "NumberOfProcess", &noOfProcesses)) {
            
            return false;
        }
        ServerInfo.noOfProcess = noOfProcesses + 1;
        for (int m = 1, j = 1; m < (noOfProcesses + 1); m++, j++) {
            sprintf(processBuffer, "%s%d", "Process", m);

            stringstream ss1;
            ss1 << processBuffer;
            ss1 >> processname;
            if (0 == lCConfigParser_t.getValue(section, processname, &lstrBuffer)) {
               
                return false;
            }
            strncpy(ServerInfo.processes[j].name, lstrBuffer.c_str(), 50);
            lstrBuffer.clear();
            ServerInfo.processes[j].name[50] = '\0';
        }
	
	if (0 == lCConfigParser_t.getValue(section, "FilePath", &lstrBuffer)) {

            
        }
	   strncpy(ServerInfo.Path[0].filePath,lstrBuffer.c_str(),100);
	   lstrBuffer.clear();
	   ServerInfo.Path[0].filePath[100] = '\0';
	   
           //cout << "filePath::" << ServerInfo.Path[0].filePath << endl; 	

	if (0 == lCConfigParser_t.getValue(section, "NumberOfSpace", &noOfSpace)) {

            return false;
        }
	ServerInfo.noOfSpace = noOfSpace + 1;

        for (int n = 1, k = 1; n < (noOfSpace + 1); n++, k++) {
            sprintf(spaceBuffer, "%s%d", "space", n);
            stringstream ss;
            ss << spaceBuffer;
            ss >> space;
            if (0 == lCConfigParser_t.getValue(section, space, &lstrBuffer)) {
               
                return false;
            }
            strncpy(ServerInfo.space[k].name, lstrBuffer.c_str(), 15);

            lstrBuffer.clear();
            ServerInfo.space[k].name[20] = '\0';
        }
	
	//if (0 == lCConfigParser_t.getValue(section, "NumberOfFilePath", &noOfFilePath)) {
           
	            
       // }
       // ServerInfo.noOfFilePath=noOfFilePath+1;
        
       // for (int n = 1, k = 1; n < ServerInfo.noOfFilePath; n++, k++) {
            
         //sprintf(fileBuffer,"%s%d","filePath", n);
           // stringstream ff;
           // ff << fileBuffer;
           // ff >> filePath;
         //   if (0 == lCConfigParser_t.getValue(section, "filePath1", &lstrBuffer)) {
               
                
           // }
           // strncpy(ServerInfo.Path[1].filePath, lstrBuffer.c_str(), 100);

            lstrBuffer.clear();
           // ServerInfo.Path[1].filePath[100] = '\0';
           // ServerInfo.Path[1].size=0;
           // printf("filePath %s \n",ServerInfo.Path[1].filePath);
       // }
        
        if (0 == lCConfigParser_t.getValue(section, "Line name", &lstrBuffer)) {
           

        }
        strncpy(ServerInfo.lineType, lstrBuffer.c_str(), 20);
        lstrBuffer.clear();
        ServerInfo.lineType[20] = '\0';
	//std::cout<<"lineType"<<ServerInfo.lineType;
        if (0 == lCConfigParser_t.getValue(section, "Line noOfConn", &noOfLines)) {
           

        }
        ServerInfo.noOfLine = noOfLines;
        
        singleInstance->serverObject.push_back(ServerInfo);
        ipPathMapObj.insert(std::pair<std::string,std::string>(ServerInfo.ipAdress,startPath));
    }
     lpconn->setPath(ipPathMapObj);
     lpconn->setServerInfo(singleInstance->serverObject);
    return 1;
}

RET_CODE serverConnectThread::waitsocket(int socket_fd, LIBSSH2_SESSION *session) {
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

void print_micro_sec(int idx,FILE* fp_micro) {
  /*
  struct timeval tm;
  struct timezone tz;
  gettimeofday(&tm,&tz);
  
  fprintf(fp_micro,"Sec idx(%d): %ld  Micro Sec idx(%d): %ld\n",idx,tm.tv_sec,idx,tm.tv_usec);
  */
  struct timespec tm;
  if (clock_gettime( CLOCK_REALTIME, &tm) == -1) {
    printf("time error \n");
  }else {
    fprintf(fp_micro,"Sec idx(%d): %ld  Nano Sec idx(%d): %ld\n",idx,tm.tv_sec,idx,tm.tv_nsec);
  }
  

}
RET_CODE serverConnectThread::Process(void* pcThreadParam) {

    CControllerThread *singleInstance;
    singleInstance = CControllerThread::getInstance();
    
    iterServerInfoMap iterMap;
    typedef tbb::concurrent_vector<tapServerInfoMap> mapStore;
    typedef mapStore::iterator iterMapVector;
    mapStore mapStoreObj;
    int whileserverCount = 0;
    
   // CControllerThread *singleInstance;
   // singleInstance = CControllerThread::getInstance();

    unsigned long long int prevSizeroot = 0;
    unsigned long long int currentSizeroot = 0;
    unsigned long long int prevSizedolat = 0;
    unsigned long long int currentSizedolat = 0;
    vector <unsigned long long int> fileSize;
    for(int i=0;i<10;i++)
	fileSize.push_back(0);
   	
    char *hostAdress;
    const char* userName;
    const char* passWord;
    char* dbUserName;
    char* dbPassWord;
    char* dbName;
    char* dbPort;
    char* lineType;
    int globalCounter = 0;
    int count = 0;
    bool breakFlag;
    char commandBuffer[1000];
    char buffer[50];
    char c[20];
    int lProcessListIndex, lSpaceList;
    FILE *p;
   // char *lcPreferredAuthMethod[20];
    int lineCounter;
    DBConnection lDBConnectionObject;
    
    while (1) {
        count = 0;
        breakFlag = false;
        //print_micro_sec(1,stdout);
        for (int i=0;i<(singleInstance->serverObject.size()/3);i++) {
            
            lineCounter =0;
            if (IsThreadInShutdown()) {

                breakFlag = true;
                break;
            }
            tapServerInfoMap m_MapObject;
            tagServerInfo &tsi = singleInstance->serverObject[i];
            
	    //if(tsi.bIsDirty == false)
		//tsi.bIsDirty = true;
            //else
                //continue;            
            hostAdress = tsi.ipAdress;
	    cout <<"hostAdress1 ::: " << tsi.ipAdress << endl;
            userName = tsi.userName;
            passWord = tsi.password;
            dbUserName = tsi.dbUserName;
            dbPassWord = tsi.dbPassword;
            dbName = tsi.dbName;
            dbPort = tsi.dbPort;
            
            //cout <<"FilePath---" << tsi.Path[0].filePath << endl;
    //FILE *fp = fopen("LineIds.txt","w+");
            //lineType = tsi.lineType;

            globalCounter = 0;
            if (!(tsi.dbconStatus)) {
                
                if (0 == lDBConnectionObject.getQueryResult(m_MapObject, dbUserName, dbPassWord, dbName, dbPort, hostAdress, lineType)) {
                   // printf("db connection not found \n");

	          /*  for (std::map <long,std::string>::iterator iterMap = m_MapObject.begin(); iterMap != m_MapObject.end(); iterMap++)
                        {
                        fprintf(fp,"\n");
                        fprintf(fp,"%ld",(*iterMap).first);
                        }*/
                }
		for (std::map <long,std::string>::iterator iterMap = m_MapObject.begin(); iterMap != m_MapObject.end(); iterMap++)
		{		      
	 	  //cout << "userIds::" << iterMap->second << endl;
		  //cout << "first::" << iterMap->first << endl;
 		  conn->orderIds.push_back(iterMap->first);	
                }
                //std::cout<<"m_MapObject"<<m_MapObject.size()<<endl;
                mapStoreObj.push_back(m_MapObject);
                lDBConnectionObject.Close();
                tsi.dbconStatus = true;

            }
	    //memset(buffer,'\0',sizeof(buffer));
            //commandBuffer[1000] = {0};
           // buffer[50] = {0};
           // c[20] = {0};
           
            char *lpUserAuthList;
            struct sockaddr_in sin;
            int rc, sock, auth_pw = 0;
            lProcessListIndex, lSpaceList = 1;

            sprintf(buffer, "ping -c 3 %s | grep -c %s", tsi.ipAdress, "\"3 received\"");
	    g_cSystemLogger.LogMessage("(%s:%s:%d)::Ping Buffer %s", LOG_LOCATION,buffer);
            p = popen(buffer, "r");
            fgets(c, 10, p);
	    //cout << "ping Commmand buff" << buffer << endl;
	   // cout <<" C " << c << endl;
            //pclose(p);
            g_cSystemLogger.LogMessage("(%s:%s:%d)::If Ping Output %s", LOG_LOCATION,c);

            if (atoi(c) == 1) {
                tsi.serverstatus = true;
            } else {
		usleep(1000);
		p = popen(buffer,"r");
		fgets(c,10,p);
		pclose(p);
                g_cSystemLogger.LogMessage("(%s:%s:%d)::Else Ping Output %s", LOG_LOCATION,c);
		cout << "Else C" << c << endl;
		if(atoi(c) == 1)
		{
			tsi.serverstatus = true;
		}
		else
		{
			tsi.serverstatus = false;
			CcopyStructure::copyData(tsi,0,0,0);
			continue;
		}
               
            }
            
	    memset(buffer,'\0',sizeof(buffer));
            memset(c,'\0',sizeof(c));
            rc = libssh2_init(0);

            if (rc != 0) {
                g_cSystemLogger.LogMessage("(%s:%s:%d)::failure establishing ssh", LOG_LOCATION);
                return 1;
            }

            if (tsi.serverstatus == true && tsi.conectstatus == false) {

                sock = socket(AF_INET, SOCK_STREAM, 0);
                tsi.m_socketId = sock;
                sin.sin_family = AF_INET;
                sin.sin_port = htons(22);
                sin.sin_addr.s_addr = inet_addr(tsi.ipAdress);
                if (connect(sock, (struct sockaddr*) (&sin),
                        sizeof (struct sockaddr_in)) != 0) {
                    g_cSystemLogger.LogMessage("(%s:%s(:%d)::failure establishing ssh", LOG_LOCATION);
                    return -1;
                }
                session = libssh2_session_init();
                if (libssh2_session_handshake(session, tsi.m_socketId)) {
                    return -1;
                }
                tsi.session = session;

                lpUserAuthList = libssh2_userauth_list(session, userName, strlen(userName));

                if (NULL == lpUserAuthList) {
                    g_cSystemLogger.LogMessage("(%s:%s(:%d):: get user auth list failed", LOG_LOCATION);
                    continue;
                }

               char lcPreferredAuthMethod[20] = "password";

                g_cSystemLogger.LogMessage("(%s:%s(:%d)::authentication methods(%s)", LOG_LOCATION, lpUserAuthList);
                if (strstr(lpUserAuthList, lcPreferredAuthMethod) != NULL) {
                    auth_pw |= 1;
                    g_cSystemLogger.LogMessage("(%s:%s(:%d)::authentication methods(%d)", LOG_LOCATION, auth_pw);
                }
                g_cSystemLogger.LogMessage("(%s:%s(:%d)::after auth_pw methods(%d)", LOG_LOCATION, auth_pw);
                if (auth_pw & 1) {

                    if (libssh2_userauth_password(session, userName, passWord)) {
                        g_cSystemLogger.LogMessage("(%s:%s(:%d)::Authentation by password failed\n", LOG_LOCATION);

                    } else {
                        g_cSystemLogger.LogMessage("(%s:%s(:%d)::Authentation by password succeded\n", LOG_LOCATION);
                    }
                }
                tsi.session = session;
                tsi.conectstatus = true;
            }

            tapServerInfoMap &MapObject = mapStoreObj.at(count++);

            if (strcmp(tsi.lineType, "FO") == 0) {
                
                int i=0;
                for (iterMap = MapObject.begin(); iterMap != MapObject.end(); iterMap++) {
                  
                     while (((channel = libssh2_channel_open_session(tsi.session)) == NULL) &&
                            (libssh2_session_last_error(tsi.session, NULL, NULL, 0) == LIBSSH2_ERROR_EAGAIN)) {

                        waitsocket(sock, tsi.session);
                    }
                    if (channel == NULL) {
                        g_cSystemLogger.LogMessage("(%s:%s(:%d))ssh channel opening fail",LOG_LOCATION);
                        // goto shutdown;
                    }
                    sprintf(commandBuffer, "%s  %s%s%s%d%s%s%s", "/bin/netstat -n|/bin/grep -c", "\"", iterMap->second.c_str(), ":", 9602, ".*", "ESTABLISHED", "\"");

                    while ((rc = libssh2_channel_exec(channel, commandBuffer)) == LIBSSH2_ERROR_EAGAIN) {
                        waitsocket(sock, tsi.session);
                    }
                    int lnReturnCode;
                    lnReturnCode = libssh2_channel_read(channel, commandBuffer, sizeof (commandBuffer));
                    g_cSystemLogger.LogMessage("(%s:%s(:%d))::commandBuffer %s lnreturncode %d\n", LOG_LOCATION,commandBuffer,lnReturnCode);
                    
                    //std::cout<<"iterMap->first" <<iterMap->first <<endl;
                    if (commandBuffer[0] == '1') {
                        
                        strncpy(tsi.lineInfo[i].ipv4adresss, iterMap->second.c_str(), 16);
                        tsi.lineInfo[i].ipv4adresss[16] = '\0';
                        
                        tsi.lineInfo[i].status = TRUE;
                        tsi.lineInfo[i].userId = iterMap->first;
                    } 
                    else if (commandBuffer[0] == '0') {
                        
                        strncpy(tsi.lineInfo[i].ipv4adresss, iterMap->second.c_str(), 16);
                        tsi.lineInfo[i].ipv4adresss[16] = '\0';
                        
                        tsi.lineInfo[i].status = FALSE;
                        tsi.lineInfo[i].userId = iterMap->first;
                    }
                    //std::cout<<"tsi.lineInfo[lineCounter].userId" <<tsi.lineInfo[lineCounter].userId <<endl;
                    //std::cout<<"tsi.lineInfo[lineCounter].status" <<tsi.lineInfo[lineCounter].status <<endl;
                    if (LIBSSH2_ERROR_EAGAIN == lnReturnCode) {
                        waitsocket(sock, tsi.session);
                    }
                    i++;
                    memset(commandBuffer, 0, sizeof (commandBuffer));
                    libssh2_channel_free(channel);
                    channel = NULL;
                }
                //globalCounter = lineCounter;

            }

           /* if (strcmp(tsi.lineType, "CM") == 0) {

                int lineCounter = 0;
                for (iterMap = MapObject.begin(); iterMap != MapObject.end(); iterMap++) {
                    while (((channel = libssh2_channel_open_session(tsi.session)) == NULL) &&
                            (libssh2_session_last_error(tsi.session, NULL, NULL, 0) == LIBSSH2_ERROR_EAGAIN)) {

                        waitsocket(sock, tsi.session);
                    }

                    if (channel == NULL) {
                        g_cSystemLogger.LogMessage("(%s:%s(:%d))ssh channel opening fail",LOG_LOCATION);
                        // goto shutdown;
                    }

                    sprintf(commandBuffer, "%s  %s%s%s%d%s%s%s", "/bin/netstat -n|/bin/grep -c", "\"", iterMap->second.c_str(), ":", 9601, ".*", "ESTABLISHED", "\"");

                    g_cSystemLogger.LogMessage("(%s:%s(:%d))::command for netstat %s\n", LOG_LOCATION, commandBuffer);
                    while ((rc = libssh2_channel_exec(channel, commandBuffer)) == LIBSSH2_ERROR_EAGAIN) {
                        waitsocket(sock, tsi.session);
                    }
                    int lnReturnCode;
                    lnReturnCode = libssh2_channel_read(channel, commandBuffer, sizeof (commandBuffer));

                    if (commandBuffer[0] == '1') {
                       
                        strncpy(tsi.lineInfo[lineCounter].ipv4adresss, iterMap->second.c_str(), 16);
                        tsi.lineInfo[lineCounter].ipv4adresss[16] = '\0';
                        
                        tsi.lineInfo[lineCounter].status = TRUE;
                        tsi.lineInfo[lineCounter].userId = iterMap->first;
                    }  else if (commandBuffer[0] == '0') {
               
                        strncpy(tsi.lineInfo[lineCounter].ipv4adresss, iterMap->second.c_str(), 16);
                        tsi.lineInfo[lineCounter].ipv4adresss[16] = '\0';
                        
                        tsi.lineInfo[lineCounter].status = FALSE;
                        tsi.lineInfo[lineCounter].userId = iterMap->first;
                    }
                    if (LIBSSH2_ERROR_EAGAIN == lnReturnCode) {
                        waitsocket(sock, tsi.session);
                    }
                    lineCounter++;
                    memset(commandBuffer, 0, sizeof (commandBuffer));
                    libssh2_channel_free(channel);elOrderI
                    channel = NULL;
                }
                globalCounter = lineCounter;

            }
		
 */
	  // for(int i=1;i<tsi.noOfFilePath;i++)
           // {
              //  printf("Inside Filesizecheck \n");
	   // cout <<"filePath::::" << tsi.Path[0].filePath << endl;
            if (!(strcmp(tsi.Path[0].filePath,"") == 0))
            {
                while (((channel = libssh2_channel_open_session(tsi.session)) == NULL) &&
                            (libssh2_session_last_error(tsi.session, NULL, NULL, 0) == LIBSSH2_ERROR_EAGAIN)) {

                        waitsocket(sock, tsi.session);
                    }

                    if (channel == NULL) {
                        g_cSystemLogger.LogMessage("(%s:%s(:%d))ssh channel opening fail",LOG_LOCATION);
                        // goto shutdown;
                    }               
                    sprintf(commandBuffer,"%s %s %s", "du -b",tsi.Path[0].filePath,"| awk '{print $1}' ");
                    g_cSystemLogger.LogMessage("(%s:%s(:%d))::command for netstat %s\n", LOG_LOCATION, commandBuffer);
                    
                    while ((rc = libssh2_channel_exec(channel, commandBuffer)) == LIBSSH2_ERROR_EAGAIN) {
                        waitsocket(sock, tsi.session);
                    }
                    size_t lnReturnCode;
                    lnReturnCode = libssh2_channel_read(channel, commandBuffer, sizeof (commandBuffer));
                    
                    char buff[30];                    
                    int j=0;
		    int i=0; 		    
                    while(commandBuffer[j]!='\n')
                    {
                        buff[i]=commandBuffer[j];
                        j++;
			i++;
			lnReturnCode--;			
                    }
	            
		    lnReturnCode--;
                    currentSizeroot = (atoi(buff));		   
		    if(lnReturnCode)
		    {		   
		    i=0;
		    j++;		    		    
		    memset(buff,0,sizeof(buff));		   		   
		    while(commandBuffer[j]!='\n')
                    {
                        buff[i]=commandBuffer[j];
                        j++;
			i++;
			lnReturnCode--;
                    }
		    }
		    currentSizedolat = (atoi(buff));
                    
	    	    //cout <<"currentSizeroot" << currentSizeroot <<" "<<fileSize[0] <<endl;
		    //cout <<"currentSizedolat" << currentSizedolat <<" " <<fileSize[1] <<endl;
		    
		    if(currentSizeroot!=currentSizedolat)
	            {
			if((currentSizeroot-fileSize[0])>0 && (currentSizedolat-fileSize[1])>0)
                    	{
                        	tsi.Path[0].status=true;
                    	}
		    
                    	else
                    	{
                        	tsi.Path[0].status=false;
                    	}
			fileSize.insert(fileSize.begin()+0,currentSizeroot);
                        fileSize.insert(fileSize.begin()+1,currentSizedolat);

		    }		                        
                    
                    else
                    {
                        if((currentSizeroot-fileSize[2])>0)
                        {
                                tsi.Path[0].status=true;
                        }
                    
                        else
                        {
                                tsi.Path[0].status=false;
                        }
			fileSize.insert(fileSize.begin()+2,currentSizeroot);
                    }
                    
          		                                          
                    memset(commandBuffer, 0, sizeof (commandBuffer));
                    libssh2_channel_free(channel);
                    channel = NULL;
           // }
            }
	
	   /* std::cout<<"tsi.lineType"<<tsi.lineType<<endl;
            if (strcmp(tsi.lineType, "ColoBridge") == 0) {
	singleInstance	 g_cSystemLogger.LogMessage("(%s:%s(:%d))::Inside ColoBridge \n", LOG_LOCATION);

		memset(tsi.lineType, 0, sizeof (tsi.lineType));
		strcpy(tsi.lineType,"CM");
		std::cout<<"LineType"<<tsi.lineType<<endl;
                int lineCounter = 0;
               
                    while (((channel = libssh2_channel_open_session(tsi.session)) == NULL) &&
                            (libssh2_session_last_error(tsi.session, NULL, NULL, 0) == LIBSSH2_ERROR_EAGAIN)) {

                        waitsocket(sock, tsi.session);
                    }

                    if (channel == NULL) {
                        g_cSystemLogger.LogMessage("(%s:%s(:%d))ssh channel opening fail",LOG_LOCATION);
                        // goto shutdown;
                    }

                    sprintf(commandBuffer, "%s  %s%s%s%d%s%s%s", "/bin/netstat -n|/bin/grep -c", "\"", "192.168.30.32", ":", 2004, ".*", "ESTABLISHED", "\"");

                    g_cSystemLogger.LogMessage("(%s:%s(:%d))::command for netstat %s\n", LOG_LOCATION, commandBuffer);
                    while ((rc = libssh2_channel_exec(channel, commandBuffer)) == LIBSSH2_ERROR_EAGAIN) {
                        waitsocket(sock, tsi.session);
                    }
                    int lnReturnCode;
                    lnReturnCode = libssh2_channel_read(channel, commandBuffer, sizeof (commandBuffer));

                    if (commandBuffer[0] == '1') { tsi.lineInfo[lineCounter].userId=2004;

                       
                        strncpy(tsi.lineInfo[lineCounter].ipv4adresss, "192.168.30.32", 16);
                        tsi.lineInfo[lineCounter].ipv4adresss[16] = '\0';
                        tsi.lineInfo[lineCounter].userId=2004;
                        tsi.lineInfo[lineCounter].status = TRUE;
                        
                    }  else if (commandBuffer[0] == '0') {
               
                        strncpy(tsi.lineInfo[lineCounter].ipv4adresss, "192.168.30.32", 16);
                        tsi.lineInfo[lineCounter].ipv4adresss[16] = '\0';
                         tsi.lineInfo[lineCounter].userId=2004;
                        tsi.lineInfo[lineCounter].status = FALSE;
                        
                    }
                    if (LIBSSH2_ERROR_EAGAIN == lnReturnCode) {
                        waitsocket(sock, tsi.session);
                    }
                    lineCounter++;
                    memset(commandBuffer, 0, sizeof (commandBuffer));
                    libssh2_channel_free(channel);
                    channel = NULL;
                    
                     while (((channel = libssh2_channel_open_session(tsi.session)) == NULL) &&
                            (libssh2_session_last_error(tsi.session, NULL, NULL, 0) == LIBSSH2_ERROR_EAGAIN)) {

                        waitsocket(sock, tsi.session);
                    }

                    if (channel == NULL) {
                        g_cSystemLogger.LogMessage("(%s:%s(:%d))ssh channel opening fail",LOG_LOCATION);
                        // goto shutdown;
                    }

                    sprintf(commandBuffer, "%s  %s%s%s%d%s%s%s", "/bin/netstat -n|/bin/grep -c", "\"", "192.168.30.32", ":", 2005, ".*", "ESTABLISHED", "\"");

                    g_cSystemLogger.LogMessage("(%s:%s(:%d))::command for netstat %s\n", LOG_LOCATION, commandBuffer);
                    while ((rc = libssh2_channel_exec(channel, commandBuffer)) == LIBSSH2_ERROR_EAGAIN) {
                        waitsocket(sock, tsi.session);
                    }
                    lnReturnCode;
                    lnReturnCode = libssh2_channel_read(channel, commandBuffer, sizeof (commandBuffer));

                    if (commandBuffer[0] == '1') {
                       
                        strncpy(tsi.lineInfo[lineCounter].ipv4adresss, "192.168.30.32", 16);
                        tsi.lineInfo[lineCounter].ipv4adresss[16] = '\0';
                         tsi.lineInfo[lineCounter].userId=2005;
                        tsi.lineInfo[lineCounter].status = TRUE;
                        
                    }  else if (commandBuffer[0] == '0') {
               
                        strncpy(tsi.lineInfo[lineCounter].ipv4adresss, "192.168.30.32", 16);
                        tsi.lineInfo[lineCounter].ipv4adresss[16] = '\0';
                        tsi.lineInfo[lineCounter].userId=2005;
                        tsi.lineInfo[lineCounter].status = FALSE;
                        
                    }
                    if (LIBSSH2_ERROR_EAGAIN == lnReturnCode) {
                        waitsocket(sock, tsi.session);
                    }
                    lineCounter++;
                    memset(commandBuffer, 0, sizeof (commandBuffer));
                    libssh2_channel_free(channel);
                    channel = NULL;
                    singleInstance->serverObject.size()
                       while (((channel = libssh2_channel_open_session(tsi.session)) == NULL) &&
                            (libssh2_session_last_error(tsi.session, NULL, NULL, 0) == LIBSSH2_ERROR_EAGAIN)) {

                        waitsocket(sock, tsi.session);
                    }

                    if (channel == NULL) {
                        g_cSystemLogger.LogMessage("(%s:%s(:%d))ssh channel opening fail",LOG_LOCATION);
                        // goto shutdown;
                    }

                    sprintf(commandBuffer, "%s  %s%s%s%d%s%s%s", "/bin/netstat -n|/bin/grep -c", "\"", "192.168.30.32", ":", 5432, ".*", "ESTABLISHED", "\"");

                    g_cSystemLogger.LogMessage("(%s:%s(:%d))::command for netstat %s\n", LOG_LOCATION, commandBuffer);
                    while ((rc = libssh2_channel_exec(channel, commandBuffer)) == LIBSSH2_ERROR_EAGAIN) {
                        waitsocket(sock, tsi.session);
                    }
                    lnReturnCode;
                    lnReturnCode = libssh2_channel_read(channel, commandBuffer, sizeof (commandBuffer));

                    if (commandBuffer[0] == '2') {
                       
                        strncpy(tsi.lineInfo[lineCounter].ipv4adresss, "192.168.30.32", 16);
                        tsi.lineInfo[lineCounter].ipv4adresss[16] = '\0';
                        tsi.lineInfo[lineCounter].userId=5432;
                        tsi.lineInfo[lineCounter].status = TRUE;
                        
                    }  else if (commandBuffer[0] == '0') {
               
                        strncpy(tsi.lineInfo[lineCounter].ipv4adresss, "192.168.30.32", 16);
                        tsi.lineInfo[lineCounter].ipv4adresss[16] = '\0';
                         tsi.lineInfo[lineCounter].userId=5432;
                        tsi.lineInfo[lineCounter].status = FALSE;
                        
                    }
                    if (LIBSSH2_ERROR_EAGAIN == lnReturnCode) {
                        waitsocket(sock, tsi.session);
                    }
                    lineCounter++;
                    memset(commandBuffer, 0, sizeof (commandBuffer));
                    libssh2_channel_free(channel);
                    channel = NULL;
                    
                    while (((channel = libssh2_channel_open_session(tsi.session)) == NULL) &&
                            (libssh2_session_last_error(tsi.session, NULL, NULL, 0) == LIBSSH2_ERROR_EAGAIN)) {

                        waitsocket(sock, tsi.session);
                    }

                    if (channel == NULL) {
                        g_cSystemLogger.LogMessage("(%s:%s(:%d))ssh channel opening fail",LOG_LOCATION);
                        // goto shutdown;
                    }

                    sprintf(commandBuffer, "%s  %s%s%s%d%s%s%s", "/bin/netstat -n|/bin/grep -c", "\"", "192.168.30.231", ":", 2004, ".*", "ESTABLISHED", "\"");
singleInstance->serverObject.size()
                    g_cSystemLogger.LogMessage("(%s:%s(:%d))::command for netstat %s\n", LOG_LOCATION, commandBuffer);
                    while ((rc = libssh2_channel_exec(channel, commandBuffer)) == LIBSSH2_ERROR_EAGAIN) {
                        waitsocket(sock, tsi.session);
                    }
                    lnReturnCode;
                    lnReturnCode = libssh2_channel_read(channel, commandBuffer, sizeof (commandBuffer));

                    if (commandBuffer[0] == '1') {
                       
                        strncpy(tsi.lineInfo[lineCounter].ipv4adresss, "192.168.30.231", 16);
                        tsi.lineInfo[lineCounter].ipv4adresss[16] = '\0';
                         tsi.lineInfo[lineCounter].userId=2004;
                        tsi.lineInfo[lineCounter].status = TRUE;
                        
                    }  else if (commandBuffer[0] == '0') {
               
                        strncpy(tsi.lineInfo[lineCounter].ipv4adresss, "192.168.30.231", 16);
                        tsi.lineInfo[lineCounter].ipv4adresss[16] = '\0';
                         tsi.lineInfo[lineCounter].userId=2004;
                        tsi.lineInfo[lineCounter].status = FALSE;
                        
                    }
                    if (LIBSSH2_ERROR_EAGAIN == lnReturnCode) {
                        waitsocket(sock, tsi.session);
                    }
                    lineCounter++;
                    memset(commandBuffer, 0, sizeof (commandBuffer));
                    libssh2_channel_free(channel);
                    channel = NULL;
                    
                    while (((channel = libssh2_channel_open_session(tsi.session)) == NULL) &&
                            (libssh2_session_last_error(tsi.session, NULL, NULL, 0) == LIBSSH2_ERROR_EAGAIN)) {

                        waitsocket(sock, tsi.session);
                    }

                    if (channel == NULL) {
                        g_cSystemLogger.LogMessage("(%s:%s(:%d))ssh channel opening fail",LOG_LOCATION);
                        // goto shutdown;
                    }

                    sprintf(commandBuffer, "%s  %s%s%s%d%s%s%s", "/bin/netstat -n|/bin/grep -c", "\"", "192.168.30.231", ":", 2005, ".*", "ESTABLISHED", "\"");

                    g_cSystemLogger.LogMessage("(%s:%s(:%d))::command for netstat %s\n", LOG_LOCATION, commandBuffer);
                    while ((rc = libssh2_channel_exec(channel, commandBuffer)) == LIBSSH2_ERROR_EAGAIN) {
                        waitsocket(sock, tsi.session);
                    }
                     lnReturnCode;
                    lnReturnCode = libssh2_channel_read(channel, commandBuffer, sizeof (commandBuffer));

                    if (commandBuffer[0] == '1') {
                       
                        strncpy(tsi.lineInfo[lineCounter].ipv4adresss, "192.168.30.231", 16);
                        tsi.lineInfo[lineCounter].ipv4adresss[16] = '\0';
                         tsi.lineInfo[lineCounter].userId=2005;
                        tsi.lineInfo[lineCounter].status = TRUE;
                        
                    }  else if (commandBuffer[0] == '0') {
               
                        strncpy(tsi.lineInfo[lineCounter].ipv4adresss, "192.168.30.231", 16);
                        tsi.lineInfo[lineCounter].ipv4adresss[16] = '\0';
                         tsi.lineInfo[lineCounter].userId=2005;
                        tsi.lineInfo[lineCounter].status = FALSE;
                        
                    }
                    if (LIBSSH2_ERROR_EAGAIN == lnReturnCode) {
                        waitsocket(sock, tsi.session);
                    }
                    lineCounter++;
                    memset(commandBuffer, 0, sizeof (commandBuffer));
                    libssh2_channel_free(channel);
                    channel = NULL;
                    
                     while (((channel = libssh2_channel_open_session(tsi.session)) == NULL) &&
                            (libssh2_session_last_error(tsi.session, NULL, NULL, 0) == LIBSSH2_ERROR_EAGAIN)) {

                        waitsocket(sock, tsi.session);
                    }

                    if (channel == NULL) {
                        g_cSystemLogger.LogMessage("(%s:%s(:%d))ssh channel opening fail",LOG_LOCATION);
                        // goto shutdown;
                    }

                    sprintf(commandBuffer, "%s  %s%s%s%d%s%s%s", "/bin/netstat -n|/bin/grep -c", "\"", "192.168.30.231", ":", 5432, ".*", "ESTABLISHED", "\"");

                    g_cSystemLogger.LogMessage("(%s:%s(:%d))::command for netstat %s\n", LOG_LOCATION, commandBuffer);
                    while ((rc = libssh2_channel_exec(channel, commandBuffer)) == LIBSSH2_ERROR_EAGAIN) {
                        waitsocket(sock, tsi.session);
                    }
                     lnReturnCode;
                    lnReturnCode = libssh2_channel_read(channel, commandBuffer, sizeof (commandBuffer));
		    //std::cout<<"lnReturnCode"<<lnReturnCode<<endl;
                    if (commandBuffer[0] == '2') {
                       
                        strncpy(tsi.lineInfo[lineCounter].ipv4adresss, "192.168.30.231", 16);
                        tsi.lineInfo[lineCounter].ipv4adresss[16] = '\0';
                         tsi.lineInfo[lineCounter].userId=5432;
                        tsi.lineInfo[lineCounter].status = TRUE;
                        
                    }  else if (commandBuffer[0] == '0') {
               
                        strncpy(tsi.lineInfo[lineCounter].ipv4adresss, "192.168.30.231", 16);
                        tsi.lineInfo[lineCounter].ipv4adresss[16] = '\0';
                         tsi.lineInfo[lineCounter].userId=5432;
                        tsi.lineInfo[lineCounter].status = FALSE;
                        
                    }
                    if (LIBSSH2_ERROR_EAGAIN == lnReturnCode) {
                        waitsocket(sock, tsi.session);
                    }
                    lineCounter++;
                    memset(commandBuffer, 0, sizeof (commandBuffer));
                    libssh2_channel_free(channel);
                    channel = NULL;
                
                globalCounter = lineCounter;

            }*/
               
            for (lProcessListIndex = 1; lProcessListIndex < tsi.noOfProcess; lProcessListIndex++) {
                g_cSystemLogger.LogMessage("(%s:%s(:%d))::process name\n", LOG_LOCATION);
                while ((channel = libssh2_channel_open_session(tsi.session)) == NULL &&
                        libssh2_session_last_error(tsi.session, NULL, NULL, 0) == LIBSSH2_ERROR_EAGAIN) {
                    waitsocket(sock, tsi.session);
                }
                if (channel == NULL) {
                    fprintf(stderr, "failure establishing ssh");
                    //goto shutdown;
                }
                sprintf(commandBuffer, "%s %s", "pidof -s", tsi.processes[lProcessListIndex].name);
                g_cSystemLogger.LogMessage("(%s:%s(:%d)):: Pid of process command %s\n", LOG_LOCATION, commandBuffer);

                while ((rc = libssh2_channel_exec(channel, commandBuffer)) == LIBSSH2_ERROR_EAGAIN) {
                    waitsocket(sock, tsi.session);
                    
                }
                size_t lnReturnCode;
                lnReturnCode = libssh2_channel_read(channel, commandBuffer, sizeof (commandBuffer));
                g_cSystemLogger.LogMessage("(%s:%s(:%d))::commandBuffer %s lnreturncode %d\n", LOG_LOCATION,commandBuffer,lnReturnCode);
                if (lnReturnCode == 0) {
                    tsi.processes[lProcessListIndex].process_on_off = FALSE;

                } else {
                    tsi.processes[lProcessListIndex].process_on_off = TRUE;

                    if (lnReturnCode != LIBSSH2_ERROR_EAGAIN) {
                        g_cSystemLogger.LogMessage("(%s:%s(:%d))::libbssh2 %d\n", LOG_LOCATION, lnReturnCode);
                    }
                }
                if (LIBSSH2_ERROR_EAGAIN == lnReturnCode) {
                    waitsocket(sock, tsi.session);
                }
                g_cSystemLogger.LogMessage("(%s:%s(:%d))::tsi.processes[i].process_on_off %d \n", LOG_LOCATION, tsi.processes[lProcessListIndex].process_on_off);
                memset(commandBuffer, 0, sizeof (commandBuffer));
                if (channel) {
                    libssh2_channel_free(channel);
                    channel = NULL;
                }
            }
            char percnt[5] = "\"%\"";
            for (lSpaceList = 1; lSpaceList < tsi.noOfSpace; lSpaceList++) {

                while ((channel = libssh2_channel_open_session(tsi.session)) == NULL &&
                        libssh2_session_last_error(tsi.session, NULL, NULL, 0) == LIBSSH2_ERROR_EAGAIN) {
                    waitsocket(sock, tsi.session);
                }

                if (channel == NULL) {
                    g_cSystemLogger.LogMessage("failure establishing ssh");
                }
                sprintf(commandBuffer, "%s %s  %s %s %s", "df -hk | grep", tsi.space[lSpaceList].name, "| awk '{print $(NF-1)}' | awk -F", percnt, "'{print $1}'");
                g_cSystemLogger.LogMessage("(%s:%s(:%d))::command for space%s\n", LOG_LOCATION, commandBuffer);
                while ((rc = libssh2_channel_exec(channel, commandBuffer)) == LIBSSH2_ERROR_EAGAIN) {
                    waitsocket(sock, tsi.session);

                }
                int lnReturnCode;
                lnReturnCode = libssh2_channel_read(channel, commandBuffer, sizeof (commandBuffer));

                if (lnReturnCode >= 0) {
                    if (atoi(commandBuffer) > 90) {
                        tsi.space[lSpaceList].space_full = TRUE;
                    } else {
                        tsi.space[lSpaceList].space_full = FALSE;
                    }
                }


                if (LIBSSH2_ERROR_EAGAIN == lnReturnCode) {
                    waitsocket(sock, tsi.session);
                }
                memset(commandBuffer, 0, sizeof (commandBuffer));
                if (channel) {
                    libssh2_channel_free(channel);
                    channel = NULL;
                }
            }
            CcopyStructure::copyData(tsi, tsi.noOfProcess, tsi.noOfSpace, tsi.noOfLine);

        }
       // whileserverCount++;
        //std::cout << "while count" << whileserverCount << endl;
        ///if(!(singleInstance->is_connected(singleInstance->socketId)))
		//singleInstance->makeSocketConnection();
	
        if (breakFlag) {
            break;
        }
    }
     for (int i=0;i<(singleInstance->serverObject.size()/3);i++) {
        tagServerInfo tsi;
        tsi = (singleInstance->serverObject[i]);

        libssh2_session_disconnect(tsi.session, "Shutting down,thank you");
        libssh2_session_free(tsi.session);
        close(tsi.m_socketId);
        libssh2_exit();
    }
    return 1;
}




