#include "includes.h"

void PrintErr(const char *loc)
{
        printf("Error in %s, Err msg is ""%s"", and err no is %d\n ", loc, strerror(errno), errno);
}

void PrintErr(const char *loc, int nErrno)
{
        printf("Error in %s, Err msg is ""%s"", and err no is %d\n ", loc, strerror(nErrno), nErrno);
}

CLogger::CLogger() : m_nFileSequenceNo(0),
                     m_nFileLength(0L),
                     m_bIsFolderReset(false),
                     m_pFile(NULL),
                     m_mqfd(0)
{

        struct rlimit rt;
        rt.rlim_max = rt.rlim_cur = RLIM_INFINITY;
        //rt.rlim_max = rt.rlim_cur = 819200;

        //m_nTotalNewCount = 0;

        if (SYSTEM_CALL_ERROR == setrlimit(RLIMIT_MSGQUEUE, &rt))
        {
                PrintErr("CLogger::CLogger::setrlimit");
        }
        /*getrlimit(RLIMIT_MSGQUEUE, &rt);
        printf("R limit value = %d :: %d\n", rt.rlim_max, rt.rlim_cur);*/
        //startlogger
}

CLogger::~CLogger()
{
        if (m_mqfd > 0)
        {
                StopLogger();
        }
}

bool CLogger::OpenLogFile(const char *szFileName)
{
        if (NULL == szFileName || (0 == strlen(szFileName)))
        {
                printf("CLogger::StartLogger:: Null Ptr \n");
                return false;
        }

        //do i need to check for strlen

        //printf("## full filename: %s\n", szFileName);
        if ((m_pFile = fopen(szFileName, "a")) == NULL)
        {
                PrintErr("OpenLogFile");
                return false;
        }

        // @AV
        // Take the existing file-length, in case, if file is existing.
        // If operation fails, set to zero.
        // For newly created file, it would still return zero.

        m_nFileLength = ftell(m_pFile);

        if (m_nFileLength < 0)
        {
                // Reset, in any possible failure.
                m_nFileLength = 0;
        }
        // @AV


        return true;
}

// Generates a unique file name for logging.
// At present is is: {BaseName}_{PID}_{SEQUENCE}

bool CLogger::GenerateNewFile()
{
        // The present range - till 100
        //assert(m_nFileSequenceNo>=0 && m_nFileSequenceNo<=100);

        const int currentPid = getpid();

        char szFullFileName[MAX_PATH_LEN];

        // 5-width for PID, 2-width for SID
        snprintf(szFullFileName, MAX_PATH_LEN,
                 "%s_%05d_%02d",
                 m_szBaseFileName, currentPid, m_nFileSequenceNo);

        //printf("## full filename: %s\n", szFullFileName);
        if (!OpenLogFile(szFullFileName))
        {
                printf("CLogger::StartLogger:OpenLogFile failed\n");
                return false;
        }

        m_nFileSequenceNo++;

        return true;
}

// nBreakSize - Number of BYTES, when exceeded, the logger
// will create a new file.

bool CLogger::StartLogger(const char *szFileName, int nBreakSize, const char* szDirectoryName /*= NULL*/)
{
        // @AV
        m_ncMaxLogFileSize = nBreakSize;
        //assert(m_ncMaxLogFileSize >= 1024);	// atleast 1KB
        // @AV

        if (NULL == szFileName)
        {
                PrintErr("Pointer to FileName is null");
                return false;
        }

        strncpy(m_szMsgQName, "/", MSG_Q_NAME_LEN);
        strcat(m_szMsgQName, szFileName);
        m_szMsgQName[MSG_Q_NAME_LEN] = 0;

        int lnRetVal = 0;

        mq_unlink(m_szMsgQName);

        struct mq_attr lstMQAttr;
        memset(&lstMQAttr, 0, sizeof (mq_attr));
        lstMQAttr.mq_msgsize = MSG_Q_MSG_SIZE;
        lstMQAttr.mq_maxmsg = MSG_Q_MAX_DEPTH;
        const int lnOpenFlag = O_RDWR | O_CREAT | O_NONBLOCK;

        if ((m_mqfd = mq_open(m_szMsgQName, lnOpenFlag, PMODE_FOR_POSIX_MQ, &lstMQAttr)) == SYSTEM_CALL_ERROR)
        {
                PrintErr("Clogger::LogMessage::mq_open");
                return false;
        }

        if (false == SetFileName(szFileName, szDirectoryName))
        {
                PrintErr("SetFileName failed");
                return false;
        }

        // Generate filename and open new file
        if (!GenerateNewFile())
        {
                printf("CLogger::StartLogger:GenerateNewFile failed\n");
                return false;
        }
        // @AV

#ifdef STD_STL
        if ((lnRetVal = pthread_mutex_init(&m_cMutex, NULL)) != 0)
        {
                printf("CLoger::StartLogger::pthread_mutext_init : err msg %s and err no %d\n", strerror(lnRetVal), lnRetVal);
                return false;
        }
#endif

#ifndef DUMP_FILE
        if ((lnRetVal = pthread_create(&m_cThreadId, NULL, WriteToLogFile, this)) != 0)
        {
                printf("CLogger::StartLogger::pthreadCreate : err msg %s err no %d\n", strerror(lnRetVal), lnRetVal);
                return false;
        }
#endif	
        return true;
}

bool CLogger::SetFileName(const char *szFileName, const char* szDirectoryName /*= NULL*/)
{
        if ((NULL != szDirectoryName) && ('\0' != *szDirectoryName))
        {
                char lszBaseDirectoryName[MAX_DIRECTORY_LEN + 1] = {0};
                snprintf(lszBaseDirectoryName, MAX_DIRECTORY_LEN, "%s", szDirectoryName);
                lszBaseDirectoryName[MAX_DIRECTORY_LEN] = '\0';
                size_t lnEndCharacterIndex = (strlen(lszBaseDirectoryName) - 1);
                if (NULL == opendir(lszBaseDirectoryName))
                {
                        if (FAILURE == mkdir(szDirectoryName, ALLPERMS))
                        {
                                PrintErr("Clogger::LogMessage::mkdir");
                                return false;
                        }
                }

                memset(m_szBaseFileName, 0, MAX_PATH_LEN);

                if (strrchr(lszBaseDirectoryName, '/') != &(lszBaseDirectoryName[lnEndCharacterIndex]))
                {
                        snprintf(m_szBaseFileName, MAX_PATH_LEN, "%s/%s", lszBaseDirectoryName, szFileName);
                }
                else
                {
                        snprintf(m_szBaseFileName, MAX_PATH_LEN, "%s%s", lszBaseDirectoryName, szFileName);
                }
        }
        else
        {
                strncpy(m_szBaseFileName, szFileName, MAX_PATH_LEN);
        }

        return true;
}

bool CLogger::WriteToFile(const char *szLogMsg, int nMsgLen)
{
        bool lbRetVal = true;

        // @AV - Unnecessary to check by 'if' at runtime.
        // Causes performance penalty. Program flow will not
        // cause either of them to be null. And if does,
        // assert will catch the bug!
        assert(m_pFile && szLogMsg);

        // First test if file size is (going to) exceed
        // the maximum specified file-size limit.
        m_nFileLength += nMsgLen;

        if ((m_nFileLength >= m_ncMaxLogFileSize) || (true == m_bIsFolderReset))
        {
                fflush(m_pFile);

                if (SYSTEM_CALL_ERROR == fclose(m_pFile))
                {
                        PrintErr("CLogger::WriteToFile::fclose");

                        return false;
                }

                m_pFile = NULL;

                // @AV
                if (!GenerateNewFile())
                {
                        PrintErr("CLogger::WriteToFile::GenerateNewFile");
                        return false;
                }

                m_bIsFolderReset = false;
                // @AV
        }

        const int lnRetVal = (int) fwrite(szLogMsg, nMsgLen, 1, m_pFile);

        if (lnRetVal <= 0)
        {
                printf("CLogger::WriteToFile::fprintf %d, %d", lnRetVal, nMsgLen);
                lbRetVal = false;
        }

        fflush(m_pFile);

        // @AV

        return lbRetVal;
}

bool CLogger::ResetLogger(const char *szFileName, const char* szDirectoryName /*= NULL*/)
{

        if (false == SetFileName(szFileName, szDirectoryName))
        {
                PrintErr("SetFileName failed");
                return false;
        }

        m_bIsFolderReset = true;

        return true;
}

bool CLogger::LogMessage(const char *szFormat, ...)
{
        const unsigned int lnMsgPri = 1;
        bool lbRetVal = true;
        int lnErrNo = 0;
        va_list arglist;
        va_start(arglist, szFormat);
        
        char lszLogBuf[MSG_Q_MSG_SIZE + 1] = {0};
        int lnTimeStampStrLen = 0;

        if (szFormat[0])
        {
                SYSTEMTIME lstSysTime;
                GetSysLocalTime(&lstSysTime);
                char lszTimeStampBuf[LOG_TIME_STAMP_BUF_SIZE + 1] = {0};
                lnTimeStampStrLen = snprintf(lszTimeStampBuf, sizeof (lszTimeStampBuf), "[%02d:%02d:%02d.%03d] ",
                                             lstSysTime.wHour, lstSysTime.wMinute, lstSysTime.wSecond, lstSysTime.wMilliseconds);
                memcpy(lszLogBuf, lszTimeStampBuf, LOG_TIME_STAMP_BUF_SIZE + 1);
        }
        int lnSize = vsnprintf(lszLogBuf + lnTimeStampStrLen, (sizeof(lszLogBuf) - lnTimeStampStrLen), szFormat, arglist);
        lnSize += (lnTimeStampStrLen + 1);
        assert(lnSize < MSG_Q_MSG_SIZE);

        if ((lnSize + 1) >= MSG_Q_MSG_SIZE)
        {
                lnSize = MSG_Q_MSG_SIZE - 1;
        }

        if (szFormat[0])
        {
                strncat(lszLogBuf, "\n", 1);
        }

        if (m_mqfd == 0)
        {
                printf("CLogger::LogMessage mqfd is already closed or not initialised: %s", lszLogBuf);
                return false;
        }
#ifdef DUMP_FILE
        if ((lnErrNo = pthread_mutex_lock(&m_cMutex)) != 0)
        {
                PrintErr("CLogger::LogMessage:: lock mutex WriteToFile", lnErrNo);
                return false;
        }

        if (!WriteToFile(lszLogBuf, lnSize + 1))
        {
                PrintErr("CLogger::LogMessage::WriteToFile");
                return false;
        }

        if ((lnErrNo = pthread_mutex_unlock(&m_cMutex)) != 0)
        {
                printf("CLogger::LogMessage:: unlock mutex : err msg %s and err no %d\n", strerror(lnErrNo), lnErrNo);
                lbRetVal = false;
        }
#else

#ifdef STD_STL
        //lock
        if ((lnErrNo = pthread_mutex_lock(&m_cMutex)) != 0)
        {
                PrintErr("CLogger::LogMessage:: lock mutex Queue empty", lnErrNo);
                return false;
        }
#endif

        if (m_cLogInfoQ.empty())
        {
                if (SYSTEM_CALL_ERROR == mq_send(m_mqfd, (const char *) lszLogBuf, (size_t) (lnSize + 1), lnMsgPri))
                {
                        if (errno == EAGAIN)
                        {
#ifdef RECYCLE_MEMORY
                                char *lpszLogBuf = AllocMemory(lnSize + 1);
#else
                                char *lpszLogBuf = new char[lnSize + 1];
#endif
                                strncpy(lpszLogBuf, lszLogBuf, lnSize);
                                m_cLogInfoQ.push(lpszLogBuf);
                        }
                        else
                        {
                                PrintErr("Clogger::LogMessage::mq_send ");
                                lbRetVal = false;
                        }
                }
        }
        else
        {
#ifdef RECYCLE_MEMORY
                char *lpszLogBuf = AllocMemory(lnSize + 1);
#else
                char *lpszLogBuf = new char[lnSize + 1];
#endif
                strncpy(lpszLogBuf, lszLogBuf, lnSize);

                m_cLogInfoQ.push(lpszLogBuf);
                lpszLogBuf = NULL;
                bool bSendFlag = false;

                while (!m_cLogInfoQ.empty() || bSendFlag)
                {
#ifdef STD_STL
                        lpszLogBuf = m_cLogInfoQ.front();
#elif CONCURRENT_STL
                        if (lpszLogBuf == NULL) //Remove the message from Queue only if previous message sending is Successful.
                        {
                                if (!m_cLogInfoQ.pop_if_present(lpszLogBuf))
                                {
                                        break;
                                }
                        }
#endif
                        if (SYSTEM_CALL_ERROR != mq_send(m_mqfd, (const char*) lpszLogBuf, (size_t) (strlen(lpszLogBuf) + 1), lnMsgPri))
                        {
#ifdef STD_STL				
                                m_cLogInfoQ.pop();
#endif
                                bSendFlag = false;
#ifdef RECYCLE_MEMORY
                                RecycleMemory(lpszLogBuf);
#else
                                delete [] lpszLogBuf;
#endif
                                lpszLogBuf = NULL;
                        }
                        else
                        {
                                if (errno == EAGAIN)
                                {
                                        bSendFlag = true;
                                }
                                else if (errno != EAGAIN)
                                {

                                        PrintErr("CLogger::LogMessage::mq_send in while");
                                        lbRetVal = false;
                                        break;
                                }
                        }
                }
        }

#ifdef STD_STL
        if ((lnErrNo = pthread_mutex_unlock(&m_cMutex)) != 0)
        {
                printf("CLogger::LogMessage:: unlock mutex : err msg %s and err no %d\n", strerror(lnErrNo), lnErrNo);
                lbRetVal = false;
        }
#endif
#endif
        va_end(arglist);
        return lbRetVal;
}

void *CLogger::WriteToLogFile(void *arg)
{
        CLogger *pLogger = (CLogger *) arg;
        //char szMsgTypeBuf[MSGTYPE_STR_LEN + 1];
        //char lszLogMsgBuf[LOG_MSG_STR_LEN];
        char lszLogBuf[MSG_Q_MSG_SIZE + 1];
        const int lnOpenFlag = O_RDONLY | O_CREAT;
        unsigned int lnMsgPri = 1;
        mqd_t lmqfd = 0;
        //LogInfo cLogInfo;
        struct mq_attr lstAttr;
        memset(&lstAttr, 0, sizeof (mq_attr));
        lstAttr.mq_msgsize = MSG_Q_MSG_SIZE;
        lstAttr.mq_maxmsg = MSG_Q_MAX_DEPTH;
        int lnSize = 0;

        //	printf("msg que name %s\n", pLogger->m_szMsgQueName);


        pLogger->LogMessage("Thread name = %s, Logfilename: %s and thread id = %lu", __FUNCTION__, pLogger->m_szMsgQName, syscall(SYS_gettid));
        if ((lmqfd = mq_open(pLogger->m_szMsgQName, lnOpenFlag, PMODE_FOR_POSIX_MQ, &lstAttr)) == SYSTEM_CALL_ERROR)
        {
                PrintErr("CLogger::WriteToLogFile::mq_open");
                return (void *) 0;
        }

        ssize_t lnReturnValue = 0;
        while (true)
        {
                if ((lnReturnValue = mq_receive(lmqfd, lszLogBuf, (size_t) MSG_Q_MSG_SIZE, &lnMsgPri)) != SYSTEM_CALL_ERROR)
                {
                        lnSize = static_cast<int> (strlen(lszLogBuf));
                        if (0 == lnSize)
                        {
                                break;
                        }

                        //flag = GetLogMessage(cLogInfo.ntype, szMsgTypeBuf);
                        /*		GetLocalTime(&lstSysTime);*/

                        assert(lnSize <= MSG_Q_MSG_SIZE);
                        //lszLogBuf[lnSize] = '\0';
                        if (!pLogger->WriteToFile(lszLogBuf, lnSize))
                        {
                                printf("CLogger::WriteToLogFile:Write to File\n");
                                break;
                        }
                }
                else
                {
                        PrintErr("CLogger::WriteToLogFile::mq_receive");
                        break;
                }
        }

        if (SYSTEM_CALL_ERROR == mq_close(lmqfd))
        {
                PrintErr("Clogger::WriteToLogFile::mq_close");
        }

        return (void*) 0;
}

void CLogger::Flush()
{
        if (m_pFile != NULL)
        {
                fflush(m_pFile);
        }
}

void CLogger::StopLogger()
{
        int lnRetVal = 0;
        if (!LogMessage(""))
        {
                printf("CLogger::StopLogger::LogMessage");
        }

#ifndef DUMP_FILE
        if ((lnRetVal = pthread_join(m_cThreadId, NULL)) != 0)
        {
                printf("CLogger::StopLogger::pthread_join:: err msg %s and err no %d\n", strerror(lnRetVal), lnRetVal);
        }
#endif

        if (SYSTEM_CALL_ERROR == mq_close(m_mqfd))
        {
                PrintErr("CLogger::LogMessage::mq_close");
        }

        m_mqfd = 0;

#ifdef STD_STL
        if ((lnRetVal = pthread_mutex_destroy(&m_cMutex)) != 0)
        {
                printf("CLogger::StopLogger::pthread_mutex_destroy:: err msg %s and err no %d\n", strerror(lnRetVal), lnRetVal);
        }
#endif

        if (NULL != m_pFile)
        {
                fflush(m_pFile);

                if (SYSTEM_CALL_ERROR == fclose(m_pFile))
                {
                        PrintErr("CLogger::StopLogger::fclose");
                }

                m_pFile = NULL;
        }

        if (SYSTEM_CALL_ERROR == mq_unlink(m_szMsgQName))
        {
                //PrintErr("CLogger::StopLogger:mq_unlink");	
        }

}


