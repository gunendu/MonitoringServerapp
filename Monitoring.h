
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from Monitoring.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/

#ifndef Monitoring_1808175700_h
#define Monitoring_1808175700_h

#ifndef NDDS_STANDALONE_TYPE
    #ifdef __cplusplus
        #ifndef ndds_cpp_h
            #include "ndds/ndds_cpp.h"
        #endif
    #else
        #ifndef ndds_c_h
            #include "ndds/ndds_c.h"
        #endif
    #endif
#else
    #include "ndds_standalone_type.h"
#endif


namespace MONITORING{
             
static const DDS_Long MAX_PROCESSES = 100;             
static const DDS_Long MAX_SPACES = 32;             
static const DDS_Long MAX_LINES = 100;             
static const DDS_Long MAX_PROC_NAMELEN = 64;             
static const DDS_Long MAX_DIR_PATHLEN = 32;             
static const DDS_Long MAX_USER_NAMELEN = 32;             
static const DDS_Long MAX_LEASE_LINE = 12;             
static const DDS_Long MAX_TAP_SERVER = 2;

typedef enum elinestatus
{
    UP = 1,
    DOWN = 0
} elinestatus;

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* elinestatus_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(elinestatusSeq, elinestatus);
        
NDDSUSERDllExport
RTIBool elinestatus_initialize(
        elinestatus* self);
        
NDDSUSERDllExport
RTIBool elinestatus_initialize_ex(
        elinestatus* self,RTIBool allocatePointers);

NDDSUSERDllExport
void elinestatus_finalize(
        elinestatus* self);
                        
NDDSUSERDllExport
void elinestatus_finalize_ex(
        elinestatus* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool elinestatus_copy(
        elinestatus* dst,
        const elinestatus* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



typedef enum eState
{
    OFF = 0,
    ON = 1
} eState;

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* eState_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(eStateSeq, eState);
        
NDDSUSERDllExport
RTIBool eState_initialize(
        eState* self);
        
NDDSUSERDllExport
RTIBool eState_initialize_ex(
        eState* self,RTIBool allocatePointers);

NDDSUSERDllExport
void eState_finalize(
        eState* self);
                        
NDDSUSERDllExport
void eState_finalize_ex(
        eState* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool eState_copy(
        eState* dst,
        const eState* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



typedef enum eLineType
{
    CM = 0,
    FO = 1,
    CMFO = 2,
    BSE = 3
} eLineType;

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* eLineType_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(eLineTypeSeq, eLineType);
        
NDDSUSERDllExport
RTIBool eLineType_initialize(
        eLineType* self);
        
NDDSUSERDllExport
RTIBool eLineType_initialize_ex(
        eLineType* self,RTIBool allocatePointers);

NDDSUSERDllExport
void eLineType_finalize(
        eLineType* self);
                        
NDDSUSERDllExport
void eLineType_finalize_ex(
        eLineType* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool eLineType_copy(
        eLineType* dst,
        const eLineType* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


        
extern const char *lineDetailsTYPENAME;
        


#ifdef __cplusplus
    struct lineDetailsSeq;

#ifndef NDDS_STANDALONE_TYPE
    class lineDetailsTypeSupport;
    class lineDetailsDataWriter;
    class lineDetailsDataReader;
#endif

#endif

            
    

typedef struct lineDetails
{
#ifdef __cplusplus
    typedef struct lineDetailsSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef lineDetailsTypeSupport TypeSupport;
    typedef lineDetailsDataWriter DataWriter;
    typedef lineDetailsDataReader DataReader;
#endif

#endif

    DDS_Long  line_id;
    char*  product_details; /* maximum length = (1024) */

} lineDetails;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* lineDetails_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(lineDetailsSeq, lineDetails);
        
NDDSUSERDllExport
RTIBool lineDetails_initialize(
        lineDetails* self);
        
NDDSUSERDllExport
RTIBool lineDetails_initialize_ex(
        lineDetails* self,RTIBool allocatePointers);

NDDSUSERDllExport
void lineDetails_finalize(
        lineDetails* self);
                        
NDDSUSERDllExport
void lineDetails_finalize_ex(
        lineDetails* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool lineDetails_copy(
        lineDetails* dst,
        const lineDetails* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


        
extern const char *pslInfoTYPENAME;
        


#ifdef __cplusplus
    struct pslInfoSeq;

#ifndef NDDS_STANDALONE_TYPE
    class pslInfoTypeSupport;
    class pslInfoDataWriter;
    class pslInfoDataReader;
#endif

#endif

            
    

typedef struct pslInfo
{
#ifdef __cplusplus
    typedef struct pslInfoSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef pslInfoTypeSupport TypeSupport;
    typedef pslInfoDataWriter DataWriter;
    typedef pslInfoDataReader DataReader;
#endif

#endif

    char*  ipadress; /* maximum length = (16) */
    char*  processInfo; /* maximum length = (1024) */
    char*  spaceInfo; /* maximum length = (1024) */
    char*  cancelOrderStatus; /* maximum length = (512) */
     MONITORING::lineDetailsSeq  lineInfo;

} pslInfo;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* pslInfo_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(pslInfoSeq, pslInfo);
        
NDDSUSERDllExport
RTIBool pslInfo_initialize(
        pslInfo* self);
        
NDDSUSERDllExport
RTIBool pslInfo_initialize_ex(
        pslInfo* self,RTIBool allocatePointers);

NDDSUSERDllExport
void pslInfo_finalize(
        pslInfo* self);
                        
NDDSUSERDllExport
void pslInfo_finalize_ex(
        pslInfo* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool pslInfo_copy(
        pslInfo* dst,
        const pslInfo* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


        
extern const char *ipSequenceTYPENAME;
        


#ifdef __cplusplus
    struct ipSequenceSeq;

#ifndef NDDS_STANDALONE_TYPE
    class ipSequenceTypeSupport;
    class ipSequenceDataWriter;
    class ipSequenceDataReader;
#endif

#endif

            
    

typedef struct ipSequence
{
#ifdef __cplusplus
    typedef struct ipSequenceSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef ipSequenceTypeSupport TypeSupport;
    typedef ipSequenceDataWriter DataWriter;
    typedef ipSequenceDataReader DataReader;
#endif

#endif

    char*  ipadress; /* maximum length = (16) */
    MONITORING::eState  status;
    DDS_Long  CancelOrderId;
    char*  psl; /* maximum length = (20) */

} ipSequence;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* ipSequence_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(ipSequenceSeq, ipSequence);
        
NDDSUSERDllExport
RTIBool ipSequence_initialize(
        ipSequence* self);
        
NDDSUSERDllExport
RTIBool ipSequence_initialize_ex(
        ipSequence* self,RTIBool allocatePointers);

NDDSUSERDllExport
void ipSequence_finalize(
        ipSequence* self);
                        
NDDSUSERDllExport
void ipSequence_finalize_ex(
        ipSequence* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool ipSequence_copy(
        ipSequence* dst,
        const ipSequence* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


        
extern const char *leaseProcessStartTYPENAME;
        


#ifdef __cplusplus
    struct leaseProcessStartSeq;

#ifndef NDDS_STANDALONE_TYPE
    class leaseProcessStartTypeSupport;
    class leaseProcessStartDataWriter;
    class leaseProcessStartDataReader;
#endif

#endif

            
    

typedef struct leaseProcessStart
{
#ifdef __cplusplus
    typedef struct leaseProcessStartSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef leaseProcessStartTypeSupport TypeSupport;
    typedef leaseProcessStartDataWriter DataWriter;
    typedef leaseProcessStartDataReader DataReader;
#endif

#endif

     MONITORING::ipSequenceSeq  ip_info;

} leaseProcessStart;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* leaseProcessStart_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(leaseProcessStartSeq, leaseProcessStart);
        
NDDSUSERDllExport
RTIBool leaseProcessStart_initialize(
        leaseProcessStart* self);
        
NDDSUSERDllExport
RTIBool leaseProcessStart_initialize_ex(
        leaseProcessStart* self,RTIBool allocatePointers);

NDDSUSERDllExport
void leaseProcessStart_finalize(
        leaseProcessStart* self);
                        
NDDSUSERDllExport
void leaseProcessStart_finalize_ex(
        leaseProcessStart* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool leaseProcessStart_copy(
        leaseProcessStart* dst,
        const leaseProcessStart* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


        
extern const char *leaseLineInfoTYPENAME;
        


#ifdef __cplusplus
    struct leaseLineInfoSeq;

#ifndef NDDS_STANDALONE_TYPE
    class leaseLineInfoTypeSupport;
    class leaseLineInfoDataWriter;
    class leaseLineInfoDataReader;
#endif

#endif

            
    

typedef struct leaseLineInfo
{
#ifdef __cplusplus
    typedef struct leaseLineInfoSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef leaseLineInfoTypeSupport TypeSupport;
    typedef leaseLineInfoDataWriter DataWriter;
    typedef leaseLineInfoDataReader DataReader;
#endif

#endif

    char*  ipadress; /* maximum length = (16) */
    DDS_Long  lineId;
    MONITORING::elinestatus  status;
    MONITORING::eLineType  linetype;

} leaseLineInfo;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* leaseLineInfo_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(leaseLineInfoSeq, leaseLineInfo);
        
NDDSUSERDllExport
RTIBool leaseLineInfo_initialize(
        leaseLineInfo* self);
        
NDDSUSERDllExport
RTIBool leaseLineInfo_initialize_ex(
        leaseLineInfo* self,RTIBool allocatePointers);

NDDSUSERDllExport
void leaseLineInfo_finalize(
        leaseLineInfo* self);
                        
NDDSUSERDllExport
void leaseLineInfo_finalize_ex(
        leaseLineInfo* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool leaseLineInfo_copy(
        leaseLineInfo* dst,
        const leaseLineInfo* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


        
extern const char *tapServerInfoTYPENAME;
        


#ifdef __cplusplus
    struct tapServerInfoSeq;

#ifndef NDDS_STANDALONE_TYPE
    class tapServerInfoTypeSupport;
    class tapServerInfoDataWriter;
    class tapServerInfoDataReader;
#endif

#endif

            
    

typedef struct tapServerInfo
{
#ifdef __cplusplus
    typedef struct tapServerInfoSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef tapServerInfoTypeSupport TypeSupport;
    typedef tapServerInfoDataWriter DataWriter;
    typedef tapServerInfoDataReader DataReader;
#endif

#endif

    char*  ipv4Address; /* maximum length = (16) */
    MONITORING::eState  status;
     MONITORING::leaseLineInfoSeq  line_info;

} tapServerInfo;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* tapServerInfo_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(tapServerInfoSeq, tapServerInfo);
        
NDDSUSERDllExport
RTIBool tapServerInfo_initialize(
        tapServerInfo* self);
        
NDDSUSERDllExport
RTIBool tapServerInfo_initialize_ex(
        tapServerInfo* self,RTIBool allocatePointers);

NDDSUSERDllExport
void tapServerInfo_finalize(
        tapServerInfo* self);
                        
NDDSUSERDllExport
void tapServerInfo_finalize_ex(
        tapServerInfo* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool tapServerInfo_copy(
        tapServerInfo* dst,
        const tapServerInfo* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


        
extern const char *tagProcessInfoTYPENAME;
        


#ifdef __cplusplus
    struct tagProcessInfoSeq;

#ifndef NDDS_STANDALONE_TYPE
    class tagProcessInfoTypeSupport;
    class tagProcessInfoDataWriter;
    class tagProcessInfoDataReader;
#endif

#endif

            
    

typedef struct tagProcessInfo
{
#ifdef __cplusplus
    typedef struct tagProcessInfoSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef tagProcessInfoTypeSupport TypeSupport;
    typedef tagProcessInfoDataWriter DataWriter;
    typedef tagProcessInfoDataReader DataReader;
#endif

#endif

    char*  name; /* maximum length = ((MONITORING::MAX_PROC_NAMELEN)) */
    MONITORING::eState  state;

} tagProcessInfo;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* tagProcessInfo_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(tagProcessInfoSeq, tagProcessInfo);
        
NDDSUSERDllExport
RTIBool tagProcessInfo_initialize(
        tagProcessInfo* self);
        
NDDSUSERDllExport
RTIBool tagProcessInfo_initialize_ex(
        tagProcessInfo* self,RTIBool allocatePointers);

NDDSUSERDllExport
void tagProcessInfo_finalize(
        tagProcessInfo* self);
                        
NDDSUSERDllExport
void tagProcessInfo_finalize_ex(
        tagProcessInfo* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool tagProcessInfo_copy(
        tagProcessInfo* dst,
        const tagProcessInfo* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


        
extern const char *tagSpaceInfoTYPENAME;
        


#ifdef __cplusplus
    struct tagSpaceInfoSeq;

#ifndef NDDS_STANDALONE_TYPE
    class tagSpaceInfoTypeSupport;
    class tagSpaceInfoDataWriter;
    class tagSpaceInfoDataReader;
#endif

#endif

            
    

typedef struct tagSpaceInfo
{
#ifdef __cplusplus
    typedef struct tagSpaceInfoSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef tagSpaceInfoTypeSupport TypeSupport;
    typedef tagSpaceInfoDataWriter DataWriter;
    typedef tagSpaceInfoDataReader DataReader;
#endif

#endif

    char*  name; /* maximum length = ((MONITORING::MAX_DIR_PATHLEN)) */
    DDS_Boolean  is_space_full;

} tagSpaceInfo;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* tagSpaceInfo_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(tagSpaceInfoSeq, tagSpaceInfo);
        
NDDSUSERDllExport
RTIBool tagSpaceInfo_initialize(
        tagSpaceInfo* self);
        
NDDSUSERDllExport
RTIBool tagSpaceInfo_initialize_ex(
        tagSpaceInfo* self,RTIBool allocatePointers);

NDDSUSERDllExport
void tagSpaceInfo_finalize(
        tagSpaceInfo* self);
                        
NDDSUSERDllExport
void tagSpaceInfo_finalize_ex(
        tagSpaceInfo* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool tagSpaceInfo_copy(
        tagSpaceInfo* dst,
        const tagSpaceInfo* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


        
extern const char *tagServerInfoTYPENAME;
        


#ifdef __cplusplus
    struct tagServerInfoSeq;

#ifndef NDDS_STANDALONE_TYPE
    class tagServerInfoTypeSupport;
    class tagServerInfoDataWriter;
    class tagServerInfoDataReader;
#endif

#endif

            
    

typedef struct tagServerInfo
{
#ifdef __cplusplus
    typedef struct tagServerInfoSeq Seq;

#ifndef NDDS_STANDALONE_TYPE
    typedef tagServerInfoTypeSupport TypeSupport;
    typedef tagServerInfoDataWriter DataWriter;
    typedef tagServerInfoDataReader DataReader;
#endif

#endif

    char*  ipv4Address; /* maximum length = (16) */
    DDS_Boolean  serverStatus;
     MONITORING::tagProcessInfoSeq  process_list;
     MONITORING::tagSpaceInfoSeq  space_list;
     MONITORING::leaseLineInfoSeq  line_info;
    char*  Logpath; /* maximum length = (100) */
    DDS_Boolean  status;

} tagServerInfo;
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* tagServerInfo_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(tagServerInfoSeq, tagServerInfo);
        
NDDSUSERDllExport
RTIBool tagServerInfo_initialize(
        tagServerInfo* self);
        
NDDSUSERDllExport
RTIBool tagServerInfo_initialize_ex(
        tagServerInfo* self,RTIBool allocatePointers);

NDDSUSERDllExport
void tagServerInfo_finalize(
        tagServerInfo* self);
                        
NDDSUSERDllExport
void tagServerInfo_finalize_ex(
        tagServerInfo* self,RTIBool deletePointers);
        
NDDSUSERDllExport
RTIBool tagServerInfo_copy(
        tagServerInfo* dst,
        const tagServerInfo* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif


} /* namespace MONITORING */


#endif /* Monitoring_1808175700_h */
