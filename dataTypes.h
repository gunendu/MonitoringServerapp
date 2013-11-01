/* 
 * File:   dataTypes.h
 * Author: Gunendu Das
 *
 * Created on 4 September, 2012, 3:31 PM
 */

#ifndef DATATYPES_H
#define	DATATYPES_H

#include "defines.h"
#include <map>




#ifdef STD_STL
typedef std::queue<char *, std::list <char *, tbb::scalable_allocator <char*> > > LOG_INFO_Q;

#elif CONCURRENT_STL
#endif

enum pState
{
    OFF = 0, ON = 1
};

typedef struct _SYSTEMTIME
{
    unsigned short wYear;
    unsigned short wMonth;
    unsigned short wDayOfWeek;
    unsigned short wDay;
    unsigned short wHour;
    unsigned short wMinute;
    unsigned short wSecond;
    unsigned short wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME;


typedef struct tagleaseLineInfo
{
    char ipv4adresss[16];
    long userId;
    bool status;
    
} tagLeaseLineInfo;

typedef struct tapServerInfo
{
    char ipAdress[IP_ADDRESS_LEN+1];
    char userName[USER_NAME + 1];
    char password[PASS_WORD + 1];
    int port;
    bool serverStatus;
    bool connectStatus;
    char lineType[5];
    int socketId;
    char dbUserName[USER_NAME+1];
    char dbPassword[PASS_WORD+1];
    char dbName[USER_NAME+1];
    char dbPort[PORT_LENGTH+1];
    bool bdStatus;
    bool status;
    LIBSSH2_SESSION *session;
    LIBSSH2_CHANNEL *channel;
    tagLeaseLineInfo lineInfo[12];
    
} tapServerInfo;

typedef std::vector<tapServerInfo> tapServerDetails;
typedef tapServerDetails::iterator ItrtapServerDetails;


typedef struct tagProcessInfo
{
    char name[PROCESSNAME_LEN + 1];
    int no_of_process;
    bool process_on_off;

} tagProcessInfo;

typedef struct tagSpaceInfo
{
    char name[MAX_DIR_LENGTH];
    bool space_full;
} tagSpaceInfo;

typedef struct tagLineInfo
{
    char line_name[15];
    char ipv4adresss[16];
    long userId;
   
} tagLineInfo;

typedef struct filePath
{
    char filePath[100];
    bool status;
    long size;
   
} tagfilePath;

typedef struct tagServerInfo
{
    tbb::atomic<bool> bIsDirty;
    char ipAdress[IP_ADDRESS_LEN + 1];
    char userName[USER_NAME + 1];
    char password[PASS_WORD + 1];
    char lineType[20];
    bool serverstatus;
    bool conectstatus;
    int m_socketId;
    LIBSSH2_SESSION *session;
    LIBSSH2_CHANNEL *channel;
    char dbUserName[USER_NAME+1];
    char dbPassword[PASS_WORD+1];
    char dbName[USER_NAME+1];
    char dbPort[PORT_LENGTH+1];
    bool dbconStatus;
    int noOfProcess;
    int noOfFilePath;
    int noOfSpace;
    int noOfLine;
    tagfilePath Path[10];
    tagProcessInfo processes[100];
    tagSpaceInfo space[4];
    tagLeaseLineInfo lineInfo[12];    
} tagServerInfo;

typedef struct lineDetailsSeq
{
    long fo_id;
    char product_details[1024];
} lineDetailsSeq;

typedef struct lineDetails
{
    char ipadress[32];
    char processInfo[1024];
    char spaceInfo[1024];
    char CancelOrderStatus[512];
    lineDetailsSeq ld[12];
    long line_count;
} lineDetails;

typedef struct socketConn
{
    int socketId;
    char ipAdress[32];
    struct sockaddr_in sin;
}socketConn;

typedef std::vector<tagServerInfo> serverDetails;
typedef serverDetails::iterator ItrServerDetails;

typedef struct tagThreadInfo
{
    int nThreadIndex;
    //sem_t  ThreadSignal;
    tbb::atomic<bool> bIsDirty;

    tagThreadInfo() : nThreadIndex(0)
    {
        bIsDirty = false;
    }

    tagThreadInfo(const tagThreadInfo & other)
    {
        this->nThreadIndex = other.nThreadIndex;
        this->bIsDirty = other.bIsDirty;
    }

    tagThreadInfo& operator =(const tagThreadInfo & other)
    {
        if (&other != this)
        {
            this->nThreadIndex = other.nThreadIndex;
            this->bIsDirty = other.bIsDirty;
        }
        return *this;
    }
} tagThreadInfo;
typedef int RET_CODE;

typedef struct tagDataToBeSent
{
    size_t nBufferSize;
    char* pcSendBuffer;

    tagDataToBeSent() : nBufferSize(0), pcSendBuffer(NULL)
    {
    }

    //Parameterized CTOR

    tagDataToBeSent(int nLength, char* pcMessage) : nBufferSize(nLength), pcSendBuffer(pcMessage)
    {
    }

    //Copy CTOR

    tagDataToBeSent(const tagDataToBeSent & other) : nBufferSize(other.nBufferSize), pcSendBuffer(other.pcSendBuffer)
    {

    }

    //Overloading Assignment Operator

    tagDataToBeSent& operator=(const tagDataToBeSent & other)
    {
        if (&other != this)
        {
            nBufferSize = other.nBufferSize;
            pcSendBuffer = other.pcSendBuffer;
        }
        return *this;
    }
} tagDataToBeSent;

class serverConnectThread;
class ConnectAdapterThread;
typedef std::queue <tagDataToBeSent, std::list<tagDataToBeSent, tbb::scalable_allocator<tagDataToBeSent> > > SendInputQ;

typedef tbb::concurrent_vector<serverConnectThread*> ThreadStore;
typedef ThreadStore::iterator ItrThreadStore;

typedef tbb::concurrent_vector<ConnectAdapterThread*> AdapaterThreadStore;
typedef AdapaterThreadStore::iterator ItrAdapaterThreadStore;

typedef std::map <long,std::string> tapServerInfoMap;
typedef tapServerInfoMap :: iterator iterServerInfoMap;

typedef std::map <long,std::string> ServerInfoMap;
typedef ServerInfoMap :: iterator iterServerInfoMap;

typedef std::map <std::string,std::string> IpPathMap;
typedef IpPathMap :: iterator iterIpPathMap;

#endif	/* DATATYPES_H */
