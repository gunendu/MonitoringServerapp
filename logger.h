/* 
 * File:   logger.h
 * Author: siddharth
 *
 * Created on 10 July, 2012, 2:26 PM
 */

#ifndef LOGGER_H
#define	LOGGER_H

class  CLogger
{
	// @AV
private:
	short m_nFileSequenceNo;	// File sequence number starting with 0 (for _00)
	char pad[2];
	//int m_nFlushControlCount;
/*#ifdef __x86_64__
	char pad[6];
#else*/
	//char pad[2];
//#endif
	long m_nFileLength;			// Current filelength
	char m_szBaseFileName[MAX_PATH_LEN];
   

	// The maximum applicable logfile size (in bytes).
	long m_ncMaxLogFileSize;

	// Generates the next filename depending on Basefile-name, PID and SequenceID
	// Also opens the filename for writing.
	bool GenerateNewFile();
   bool m_bIsFolderReset;
	// @AV


protected:
	char m_szMsgQName[MSG_Q_NAME_LEN + 1];
	FILE *m_pFile;
	mqd_t m_mqfd; //
#ifdef __x86_64__
	char pad1[4];
#endif
#ifdef STD_STL
	pthread_mutex_t m_cMutex;
#endif
	LOG_INFO_Q m_cLogInfoQ;		
	pthread_t m_cThreadId;

public:
	
	CLogger();

	~CLogger();
	bool LogMessage(const char* szFormat, ...);

	// nBreakSize - Number of BYTES, when exceeded, the logger
	// will create a new file.
	bool StartLogger(const char *szFileName, int nBreakSize, const char* szDirectoryName = NULL);
   bool ResetLogger(const char *szFileName, const char* szDirectoryName = NULL);
	void Flush();
	void StopLogger();

protected:
	static void *WriteToLogFile(void *arg);
	bool WriteToFile(const char *szLogMsg, int nMsgLen);
	bool OpenLogFile(const char *szFileName);
	bool GetLogMessage(int nMsgType, char *szMsg);
   bool SetFileName(const char *szFileName, const char* szDirectoryName = NULL);
};
#endif	/* LOGGER_H */

