/* 
 * File:   ipchandler.h
 * Author: siddharth
 *
 * Created on 7 August, 2012, 12:20 PM
 */

#ifndef IPCPUBLISHER_H
#define	IPCPUBLISHER_H




template<class CDataType, class CDataTypeSupport, class CDataTypeWriter>
class CIPCPublisher 
{
private:
    DDSTopic*                    m_pcWriteTopic;
    DDSDataWriter*               m_pWriterHandle;
    CDataTypeWriter*             m_pTopicSpecificWriter;
    const char*                  m_pcWriteTypeName;
    

public:
    CIPCPublisher(const char* pcTopicName);
    virtual ~CIPCPublisher();
    
    RET_CODE CreateWriter(const char* pcLibraryName, const char* pcProfileName);
    RET_CODE SendData(CDataType& stDataType);
    
};

#endif	/* IPCPUBLISHER_H */

