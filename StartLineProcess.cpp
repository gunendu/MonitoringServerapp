#include "includes.h"
extern CLogger g_cSystemLogger;

bool StartLineProcessCollector::start() {
    if ((false == m_rtc_conn->createReader()) || (false == m_rtc_conn->startReader(this))) {
        return false;
    }
    return true;
}

bool StartLineProcessConnector::createReader() {
    DDSSubscriber *subscriber = RTIConnector::getSubscriber();
    if(FAILURE==CControllerThread::getInstance()->CommandWriter("Monitoring_Library","psl_profile"))
    {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Error ---> StartLineProcessConnector::CreateWriter Failure\n ", LOG_LOCATION);
    }
    if (NULL == m_read_topic) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Error ---> StartLineProcessConnector::CreateReader() m_read_topic is NULL for RTC! \n ", LOG_LOCATION);

        return false;
    }

    if (NULL != m_reader_cache) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Error ---> RTCConnector::CreateReader() m_reader_cache exists for RTC!\n  \n ", LOG_LOCATION);

        return false;
    }

    /* Create a data reader listener for cache */
    LineProcessStatusListener *m_reader_listener_cache = new LineProcessStatusListener();
    /* To customize the data reader QoS, use the configuration file USER_QOS_PROFILES.xml */

    m_reader_cache = subscriber->create_datareader_with_profile(m_read_topic, "Monitoring_Library", "Monitoring_Profile", m_reader_listener_cache,
            DDS_STATUS_MASK_ALL);

    if (m_reader_cache == NULL) {
        g_cSystemLogger.LogMessage("(%s:%s:%d)::CreateReader() error for RTC\n  \n ", LOG_LOCATION);
        delete m_reader_listener_cache;
        m_reader_listener_cache = NULL;
        return false;
    }
    g_cSystemLogger.LogMessage("(%s:%s:%d):: Create Reader sucess", LOG_LOCATION);

    return true;
}

RET_CODE StartLineProcessCollector::waitsocket(int socket_fd, LIBSSH2_SESSION *session) {
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

bool StartLineProcessCollector::collect(MONITORING::leaseProcessStart *sample, StartLineProcessConnector *conn) {

    if (NULL == sample) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: sample is NULL \n  \n ", LOG_LOCATION);
        return false;
    }
    
    int i=0;
    ItrServerDetails  serIter;
    lineDetails ld;
    g_cSystemLogger.LogMessage("(%s:%s:%d)::cancelid %d \n ", LOG_LOCATION,sample->ip_info[i].CancelOrderId);
    if(sample->ip_info[i].CancelOrderId!=0)
    {
    char buf[50]={0};
    char recvbuf[512]={0};
    int recvLen;
    g_cSystemLogger.LogMessage("(%s:%s:%d):: size of order vector %d \n ",LOG_LOCATION,conn->orderIds.size());
    for(i=0;i<conn->orderIds.size();i++)
    {
   
	//g_cSystemLogger.LogMessage("(%s:%s(:%d)::Inside CancelOrder %d \n", LOG_LOCATION,sample->ip_info[i].CancelOrderId);
        int pos;
        int j;
	pos+=sprintf(buf+5,"%s%d%s","#",conn->orderIds[i],"#");
        g_cSystemLogger.LogMessage("(%s:%s(:%d)::order length %d buf %s \n", LOG_LOCATION,pos,buf);
        char c='0';
        for(j=0;j<=3;j++)
        {
        buf[j]=c;
	//g_cSystemLogger.LogMessage("(%s:%s(:%d)::Inside CancelOrder buf %c \n", LOG_LOCATION,buf[j]);
        }
	char p=(char)(((int)'0')+pos);
        buf[j]=p;
        g_cSystemLogger.LogMessage("(%s:%s(:%d)::Inside CancelOrder buf %s socketId %d \n", LOG_LOCATION,buf,CControllerThread::getInstance()->socketId);
        if(recvLen==write(CControllerThread::getInstance()->socketId,buf,sizeof(buf)))
        {
	   g_cSystemLogger.LogMessage("(%s:%s(:%d)::writeLen %d \n", LOG_LOCATION,recvLen);
           //CControllerThread::getInstance()->makeSocketConnection();
        }
        g_cSystemLogger.LogMessage("(%s:%s(:%d)::write sucessfull writeLen %d \n", LOG_LOCATION,recvLen);

	if(recvLen=recv(CControllerThread::getInstance()->socketId,recvbuf,sizeof(recvbuf),0)<0)
        {
	 g_cSystemLogger.LogMessage("(%s:%s(:%d)::Recv Error \n", LOG_LOCATION);
	}
	g_cSystemLogger.LogMessage("(%s:%s(:%d)::RecvLen %d recvbuf %s \n", LOG_LOCATION,recvLen,recvbuf);
        strncpy(ld.CancelOrderStatus,recvbuf,sizeof(recvbuf)); 
	CcopyStructure::copyCommandData(ld, ld.line_count);
	memset(buf,0,sizeof(buf));
        pos=0;
	sleep(1);
    }
    return true;

   }

else
{
    for(i=0;i<sample->ip_info.length();i++)
{ 
    if(strcmp(sample->ip_info[i].ipadress,"")==0)
 	break;
    LIBSSH2_CHANNEL *channel2;
    LIBSSH2_SESSION *session;
    char* userName;
    char* passWord;
    struct sockaddr_in sin;
    int rc, sock, auth_pw = 0;
    char *exitsignal = (char *) "none";
    size_t lnReturnCode;
    char command[12324] = {0};
    char processes[8024] = {0};

    char *lpUserAuthList;
    g_cSystemLogger.LogMessage("(%s:%s:%d):: Debug", LOG_LOCATION);
    rc = libssh2_init(0);
    
    strcpy(ld.ipadress,sample->ip_info[i].ipadress);
    g_cSystemLogger.LogMessage("(%s:%s:%d)::Sequence Length %d ipadress %s,and psl %s  cancelOrderId %d value of i %d \n", LOG_LOCATION, sample->ip_info._length,sample->ip_info[i].ipadress,sample->ip_info[i].psl,sample->ip_info[i].CancelOrderId,i);
    sock = socket(AF_INET, SOCK_STREAM, 0);

    sin.sin_family = AF_INET;
    sin.sin_port = htons(22);
    sin.sin_addr.s_addr = inet_addr(sample->ip_info[i].ipadress);
    if (connect(sock, (struct sockaddr*) (&sin),
            sizeof (struct sockaddr_in)) != 0) {
        g_cSystemLogger.LogMessage("(%s:%s(:%d)::failure establishing ssh", LOG_LOCATION);
        return -1;
    }

    session = libssh2_session_init();
    if (libssh2_session_handshake(session, sock)) {
        g_cSystemLogger.LogMessage("(%s:%s(:%d):: failure ssh session initiation", LOG_LOCATION);


    }
   /* if((strcmp(sample->ip_info[i].ipadress,"192.168.30.32")==0)|| (strcmp(sample->ip_info[i].psl,"192.168.30.231")==0))
    {
        userName = "root";
        passWord = "catalyst2905"; 
    }
    else*/
    
         userName = "dolat";
         passWord = "ga34567io"; 
    
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
        }

        else {
            g_cSystemLogger.LogMessage("(%s:%s(:%d)::Authentation by mint succesded\n", LOG_LOCATION);
        }

    }

    while ((channel2 = libssh2_channel_open_session(session)) == NULL &&
            libssh2_session_last_error(session, NULL, NULL, 0) == LIBSSH2_ERROR_EAGAIN) {
        waitsocket(sock, session);
    }

    if (channel2 == NULL) {
        g_cSystemLogger.LogMessage("(%s:%s(:%d))ssh channel opening fail", LOG_LOCATION);
    }
   
    if(strcmp(sample->ip_info[i].psl,"Process")==0)
    {
       
    g_cSystemLogger.LogMessage("(%s:%s(:%d)) Inside Process", LOG_LOCATION);
    for(serIter=conn->getServerInfo().begin();serIter!=conn->getServerInfo().end();serIter++)
    {  
        g_cSystemLogger.LogMessage("(%s:%s(:%d)) ipadress from iter %s", LOG_LOCATION,serIter->ipAdress);
        tagServerInfo &tagServ = *serIter;
        g_cSystemLogger.LogMessage("(%s:%s(:%d)) ipadress from tagserver %s sampeip %s \n", LOG_LOCATION,tagServ.ipAdress,sample->ip_info[i].ipadress);

        if(strcmp(tagServ.ipAdress,sample->ip_info[i].ipadress)==0)
        {
            int pos=0;
            g_cSystemLogger.LogMessage("(%s:%s(:%d)) tagServ %s sample %s processLen %d \n", LOG_LOCATION,tagServ.ipAdress,sample->ip_info[i].ipadress,tagServ.noOfProcess);
            for(int j=1;j<tagServ.noOfProcess;j++)
            {
            g_cSystemLogger.LogMessage("(%s:%s(:%d)) Process %s \n", LOG_LOCATION,tagServ.processes[j].name);
            if(j==(tagServ.noOfProcess-1))
            {
            sprintf(processes+pos,tagServ.processes[j].name);
            }
            else
            {
            pos+=sprintf(processes+pos,"%s%s",tagServ.processes[j].name,"|");
          
            }
            }
            sprintf(command,"%s %s%s%s%s %s%s%s%s","ps -ef | egrep -v ","\"", "egrep|vi|tail|cat|emacs|more|nohup","\"" ,"| egrep","\"",processes,"\"","| grep -v daemon");
            g_cSystemLogger.LogMessage("(%s:%s(:%d)) command %s", LOG_LOCATION,command);
            
            while ((rc = libssh2_channel_exec(channel2, command)) == LIBSSH2_ERROR_EAGAIN) {
            waitsocket(sock, session);
            
            
        }
           lnReturnCode = libssh2_channel_read(channel2, command, sizeof (command));
           g_cSystemLogger.LogMessage("(%s:%s(:%d)) lnReturnCode %d command %s", LOG_LOCATION,lnReturnCode,command);
           strncpy(ld.processInfo,command,sizeof(command));
            memset(command, 0, sizeof (command));
            libssh2_channel_free(channel2);
            channel2 = NULL; 
        }     
    }
    }
    
    else if((strcmp(sample->ip_info[i].psl,"Space"))==0)
    {
       while ((rc = libssh2_channel_exec(channel2, "df -kh |grep -v grep")) == LIBSSH2_ERROR_EAGAIN) {
            waitsocket(sock, session);
            
        }
        lnReturnCode = libssh2_channel_read(channel2, command, sizeof (command));
        g_cSystemLogger.LogMessage("(%s:%s(:%d)lnReturnCode %d command after executing %s\n", LOG_LOCATION, lnReturnCode, command);
        strcpy(ld.spaceInfo,command);
        memset(command, 0, sizeof (command));
        libssh2_channel_free(channel2);
        channel2 = NULL;
    }
    
    else if((strcmp(sample->ip_info[i].psl,"Line"))==0)
    {
        
        DBConnection lDBConnectionObject;
        char* dbUserName = "money";
        char* dbPassWord = "billion";
        char* dbName = "mani";
        char* dbPort = "5432";
        if(0==lDBConnectionObject.getFoPiQueryResult(dbUserName,dbPassWord,dbName,dbPort,sample->ip_info[i].ipadress,ld))
        {
            g_cSystemLogger.LogMessage("(%s:%s(:%d) Failed DB query \n", LOG_LOCATION);
        }
        
        g_cSystemLogger.LogMessage("(%s:%s(:%d) LineId %d Product details %s line count %d\n", LOG_LOCATION,ld.ld[0].fo_id,ld.ld[0].product_details,ld.line_count);
        lDBConnectionObject.Close();
    }
    
    
    iterMap = conn->getPath().find(sample->ip_info[i].ipadress);
    g_cSystemLogger.LogMessage("(%s:%s(:%d))Path %s \n", LOG_LOCATION,iterMap->second.c_str());

    if (sample->ip_info[i].status == true) 
    {

        sprintf(command, "%s%s",iterMap->second.c_str(),"/clear_server.sh >> /tmp/LOGS/cronlog 2>&1 &");

        while ((rc = libssh2_channel_exec(channel2, command)) == LIBSSH2_ERROR_EAGAIN) {
            waitsocket(sock, session);
        }
        lnReturnCode = libssh2_channel_read(channel2, command, sizeof (command));
        g_cSystemLogger.LogMessage("(%s:%s(:%d)lnReturnCode %d command after executing %s\n", LOG_LOCATION, lnReturnCode, command);
        memset(command, 0, sizeof (command));
        libssh2_channel_free(channel2);
        channel2 = NULL;
    }
        
    else if((sample->ip_info[i].status==false) && ((strcmp(sample->ip_info[i].psl,""))==0) && (sample->ip_info[i].CancelOrderId==0))
    {
        sprintf(command, "%s", "cd /home/mint/ga/bin; nohup ./shutdownall.sh >> /tmp/LOGS/cronlog1 2>&1 &");

        g_cSystemLogger.LogMessage("(%s:%s(:%d)%s\n", LOG_LOCATION, command);
        while ((rc = libssh2_channel_exec(channel2, command)) == LIBSSH2_ERROR_EAGAIN) {
            g_cSystemLogger.LogMessage("(%s:%s(:%d) ERROR Running command %d\n", LOG_LOCATION, rc);
            waitsocket(sock, session);
        }

        size_t lnReturnCode;
        lnReturnCode = libssh2_channel_read(channel2, command, sizeof (command));

        g_cSystemLogger.LogMessage("(%s:%s(:%d)lnReturnCode %d commandBuffer %s\n", LOG_LOCATION, lnReturnCode, command);
        memset(command, 0, sizeof (command));
        libssh2_channel_free(channel2);
        channel2 = NULL;
    }
    g_cSystemLogger.LogMessage("(%s:%s(:%d)space %s\n", LOG_LOCATION,ld.spaceInfo);
     CcopyStructure::copyCommandData(ld, ld.line_count);
    }
}
   
       
    return true;
}

StartLineProcessConnector::StartLineProcessConnector(const char* rd_topic) {
    DDS_ReturnCode_t retcode_cache;
    DDSDomainParticipant *participant = RTIConnector::getParticipant();
    m_read_topic = NULL;
    pt_rtc = NULL;
    m_reader_cache = NULL;

    if (rd_topic == NULL) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Error --->rd_topic is NULL \n", LOG_LOCATION);
        return;
    }
    if (participant == NULL) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Error --->Participant is NULL \n", LOG_LOCATION);
        return;
    }

    /* Register the type before creating the topic for RTC */
    m_type_name_cache = MONITORING::leaseProcessStartTypeSupport::get_type_name();
    retcode_cache = MONITORING::leaseProcessStartTypeSupport::register_type(participant, m_type_name_cache);
    if (retcode_cache != DDS_RETCODE_OK) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Error --->Register Type RTC ERROR \n", LOG_LOCATION);
        m_type_name_cache = NULL;
        return;
    }
    if (NULL == m_read_topic) {
        /* To customize the topic QoS, use the configuration file USER_QOS_PROFILES.xml */
        m_read_topic = participant->create_topic(rd_topic, m_type_name_cache, DDS_TOPIC_QOS_DEFAULT, NULL /* listener */
                , DDS_STATUS_MASK_NONE);
        if (m_read_topic == NULL) {
            g_cSystemLogger.LogMessage("(%s:%s:%d):: Error --->create topic success is NULL \n", LOG_LOCATION);
            return;
        }
    }
    g_cSystemLogger.LogMessage("(%s:%s:%d)::  --->create topic success \n", LOG_LOCATION);

}

StartLineProcessConnector::~StartLineProcessConnector() {
    DDSDomainParticipant *participant = RTIConnector::getParticipant();
    DDS_ReturnCode_t retcode;


    if (NULL != m_reader_cache) {
        if (DDS_RETCODE_OK != RTIConnector::getSubscriber()->delete_datareader(m_reader_cache)) {

            g_cSystemLogger.LogMessage("(%s:%s(:%d))::Unable to delete m_reader_cache \n", LOG_LOCATION);
        }
        m_reader_cache = NULL;
    }
    if (NULL != m_read_topic) {
        if (DDS_RETCODE_OK != participant->delete_topic(m_read_topic)) {

            g_cSystemLogger.LogMessage("(%s:%s(:%d))::Unable to delete m_read_topic \n", LOG_LOCATION);
        }
        m_read_topic = NULL;
    }

    // Un-register the type...
    if ((NULL != participant) && (NULL != m_type_name_cache)) {
        retcode = MONITORING::leaseProcessStartTypeSupport::unregister_type(participant, m_type_name_cache);
        if (retcode != DDS_RETCODE_OK) {

            g_cSystemLogger.LogMessage("(%s:%s(:%d))::Error ---> RTCConnector() unregister_type RTC error \n", LOG_LOCATION);
        }
        m_type_name_cache = NULL;
    }
    pt_rtc = 0;

    return;
}

void* StartLineProcessConnector::data_recv(void* arg) {

    CControllerThread *singleInstance;
    singleInstance = CControllerThread::getInstance();
    
    StartLineProcessCollector *coll = (StartLineProcessCollector *) arg;
    StartLineProcessConnector *conn = NULL;
    g_cSystemLogger.LogMessage("(%s:%s(:%d))::Ipadress data_recv \n", LOG_LOCATION);
    if ((NULL == coll) || (NULL == (conn = coll->getConnector()))) {
        g_cSystemLogger.LogMessage("(%s:%s(:%d))::coll is null \n", LOG_LOCATION);
        //fprintf(fp_rtc, "OR invalid RTCConnector reference received in RTCCollector object...\n");
        return NULL;
    }

    DDS_ReturnCode_t retcode_cache;
    if (NULL == conn->m_reader_cache) {
        g_cSystemLogger.LogMessage("(%s:%s(:%d))::m_reader_cache is NULL \n", LOG_LOCATION);
        return NULL;
    }

    MONITORING::leaseProcessStartDataReader *rtc_reader = MONITORING::leaseProcessStartDataReader::narrow(conn->m_reader_cache);
    if (rtc_reader == NULL) {
        g_cSystemLogger.LogMessage("(%s:%s(:%d))::rtc_reader is NULL \n", LOG_LOCATION);
        return NULL;
    }
    // set the enabled status = DATA_AVAILABLE
    DDSStatusCondition* status_condition = conn->m_reader_cache->get_statuscondition();
    status_condition->set_enabled_statuses(DDS_DATA_AVAILABLE_STATUS);
    // attach the status condition to the waitset
    DDSWaitSet* waitset = new DDSWaitSet();
    retcode_cache = waitset->attach_condition(status_condition);
    if (retcode_cache != DDS_RETCODE_OK) {
        g_cSystemLogger.LogMessage("(%s:%s(:%d))::retcode_cache DDS_RETCODE_OK \n", LOG_LOCATION);
        delete waitset;
        return NULL;
    }

    DDSConditionSeq activeconditions;
    DDS_Duration_t timeout = {1, 0};
    MONITORING::leaseProcessStartSeq data_seq;
    DDS_SampleInfoSeq info_seq;
    MONITORING::leaseProcessStart* sample = NULL;
    int timeout_count = 0;
    const static int MAX_TIMEOUT_COUNT = 60;

    int i = 0;
    while (1) {

        g_cSystemLogger.LogMessage("(%s:%s(:%d))::Inside While \n", LOG_LOCATION);

	if(!(singleInstance->is_connected(singleInstance->socketId)))
                singleInstance->makeSocketConnection();
	
        retcode_cache = waitset->wait(activeconditions, timeout);
        // waitset returned.. check if status changed, or if waitset timed out
        if (retcode_cache == DDS_RETCODE_TIMEOUT) {
            if (++timeout_count > MAX_TIMEOUT_COUNT) //Restrict output till 1 minute!
            {
                g_cSystemLogger.LogMessage("(%s:%s(:%d)):: timed out after <%d> seconds\n", LOG_LOCATION, MAX_TIMEOUT_COUNT);

                timeout_count = 0;
                continue;
            }

        }
        else if (retcode_cache != DDS_RETCODE_OK) {
            timeout_count = 0;
            g_cSystemLogger.LogMessage("(%s:%s(:%d)):: DDS_RETCODE_OK NOT \n", LOG_LOCATION, MAX_TIMEOUT_COUNT);
            continue;
        }
        timeout_count = 0;
        g_cSystemLogger.LogMessage("(%s:%s(:%d)):: Before Take \n", LOG_LOCATION);


        retcode_cache = rtc_reader->take(data_seq, info_seq, DDS_LENGTH_UNLIMITED,
                DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);

        if (retcode_cache == DDS_RETCODE_NO_DATA) {
            g_cSystemLogger.LogMessage("(%s:%s(:%d))::No data Found\n", LOG_LOCATION);

        }
        else if (retcode_cache != DDS_RETCODE_OK) {
            g_cSystemLogger.LogMessage("(%s:%s(:%d))::DDS_RETCODE_OK NOT\n", LOG_LOCATION);

        }
        g_cSystemLogger.LogMessage("(%s:%s(:%d))::Data_seq Length %d\n", LOG_LOCATION, data_seq.length());
        for (i = 0; i < data_seq.length(); ++i) {
            if (info_seq[i].valid_data) {

                sample = &data_seq[i];

                //Invoke collector's action here!
                if (false == coll->collect(sample, conn)) {

                    if (DDS_RETCODE_OK != rtc_reader->return_loan(data_seq, info_seq)) {
                        g_cSystemLogger.LogMessage("(%s:%s(:%d))::Error ---> RTCConnector::rtc_data_receiving() return loan error\n", LOG_LOCATION);

                    }
                    goto endgame;
                }
            } // if (info_seq[i].valid_data)...
        }//for..data_seq.length()..

        retcode_cache = rtc_reader->return_loan(data_seq, info_seq);
        if (retcode_cache != DDS_RETCODE_OK) {

            g_cSystemLogger.LogMessage("(%s:%s(:%d))::Error ---> RTCConnector::rtc_data_receiving()  loan error\n", LOG_LOCATION);

        }
    } //while...

    /* Delete all entities - to cleanup properly! */
endgame:
    waitset->detach_condition(status_condition);
    delete waitset;
    return NULL;
}
