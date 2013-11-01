
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from Monitoring.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/


#ifndef NDDS_STANDALONE_TYPE
    #ifdef __cplusplus
        #ifndef ndds_cpp_h
            #include "ndds/ndds_cpp.h"
        #endif
        #ifndef dds_c_log_impl_h              
            #include "dds_c/dds_c_log_impl.h"                                
        #endif        
    #else
        #ifndef ndds_c_h
            #include "ndds/ndds_c.h"
        #endif
    #endif
    
    #ifndef cdr_type_h
        #include "cdr/cdr_type.h"
    #endif    

    #ifndef osapi_heap_h
        #include "osapi/osapi_heap.h" 
    #endif
#else
    #include "ndds_standalone_type.h"
#endif



#include "Monitoring.h"


namespace MONITORING{
/* ========================================================================= */
const char *elinestatusTYPENAME = "MONITORING::elinestatus";

DDS_TypeCode* elinestatus_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member elinestatus_g_tc_members[2] =
    {
        {
            (char *)"UP",/* Member name */
            {
                0,/* Ignored */
                DDS_BOOLEAN_FALSE, /* Ignored */
                -1, /* Ignored */
                NULL /* Ignored */
            },
            UP, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Ignored */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"DOWN",/* Member name */
            {
                0,/* Ignored */
                DDS_BOOLEAN_FALSE, /* Ignored */
                -1, /* Ignored */
                NULL /* Ignored */
            },
            DOWN, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Ignored */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode elinestatus_g_tc = 
    {{
        DDS_TK_ENUM, /* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1, /* Ignored */
        (char *)"MONITORING::elinestatus", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of enumerators */
        elinestatus_g_tc_members, /* Enumerators */
        DDS_VM_NONE /* Ignored */
}    };

    if (is_initialized) {
        return &elinestatus_g_tc;
    }

    is_initialized = RTI_TRUE;
    return &elinestatus_g_tc;
}
 

RTIBool elinestatus_initialize(
    elinestatus* sample)
{
    /* The following method initializes the enum value to zero. However,
     * some enumerations may not have a member with the value zero. In such
     * cases, it may be desirable to modify the generated code to use a valid
     * enumeration member instead.
     */
    return RTICdrType_initEnum((RTICdrEnum*) sample);
}
        
RTIBool elinestatus_initialize_ex(
    elinestatus* sample, RTIBool allocatePointers)
{
    /* The following method initializes the enum value to zero. However,
     * some enumerations may not have a member with the value zero. In such
     * cases, it may be desirable to modify the generated code to use a valid
     * enumeration member instead.
     */
    if (allocatePointers) {} /* To avoid warnings */
    return RTICdrType_initEnum((RTICdrEnum*) sample);
}

void elinestatus_finalize(
    elinestatus* sample)
{
    if (sample) {} /* To avoid warnings */
    /* empty */
}
        
void elinestatus_finalize_ex(
    elinestatus* sample,RTIBool deletePointers)
{
    if (sample) {} /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */
    /* empty */
}

RTIBool elinestatus_copy(
    elinestatus* dst,
    const elinestatus* src)
{
    return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'elinestatus' sequence class.
 */
#define T elinestatus
#define TSeq elinestatusSeq
#define T_initialize_ex elinestatus_initialize_ex
#define T_finalize_ex   elinestatus_finalize_ex
#define T_copy       elinestatus_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T
/* ========================================================================= */
const char *eStateTYPENAME = "MONITORING::eState";

DDS_TypeCode* eState_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member eState_g_tc_members[2] =
    {
        {
            (char *)"OFF",/* Member name */
            {
                0,/* Ignored */
                DDS_BOOLEAN_FALSE, /* Ignored */
                -1, /* Ignored */
                NULL /* Ignored */
            },
            OFF, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Ignored */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"ON",/* Member name */
            {
                0,/* Ignored */
                DDS_BOOLEAN_FALSE, /* Ignored */
                -1, /* Ignored */
                NULL /* Ignored */
            },
            ON, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Ignored */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode eState_g_tc = 
    {{
        DDS_TK_ENUM, /* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1, /* Ignored */
        (char *)"MONITORING::eState", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of enumerators */
        eState_g_tc_members, /* Enumerators */
        DDS_VM_NONE /* Ignored */
}    };

    if (is_initialized) {
        return &eState_g_tc;
    }

    is_initialized = RTI_TRUE;
    return &eState_g_tc;
}
 

RTIBool eState_initialize(
    eState* sample)
{
    /* The following method initializes the enum value to zero. However,
     * some enumerations may not have a member with the value zero. In such
     * cases, it may be desirable to modify the generated code to use a valid
     * enumeration member instead.
     */
    return RTICdrType_initEnum((RTICdrEnum*) sample);
}
        
RTIBool eState_initialize_ex(
    eState* sample, RTIBool allocatePointers)
{
    /* The following method initializes the enum value to zero. However,
     * some enumerations may not have a member with the value zero. In such
     * cases, it may be desirable to modify the generated code to use a valid
     * enumeration member instead.
     */
    if (allocatePointers) {} /* To avoid warnings */
    return RTICdrType_initEnum((RTICdrEnum*) sample);
}

void eState_finalize(
    eState* sample)
{
    if (sample) {} /* To avoid warnings */
    /* empty */
}
        
void eState_finalize_ex(
    eState* sample,RTIBool deletePointers)
{
    if (sample) {} /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */
    /* empty */
}

RTIBool eState_copy(
    eState* dst,
    const eState* src)
{
    return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'eState' sequence class.
 */
#define T eState
#define TSeq eStateSeq
#define T_initialize_ex eState_initialize_ex
#define T_finalize_ex   eState_finalize_ex
#define T_copy       eState_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T
/* ========================================================================= */
const char *eLineTypeTYPENAME = "MONITORING::eLineType";

DDS_TypeCode* eLineType_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member eLineType_g_tc_members[4] =
    {
        {
            (char *)"CM",/* Member name */
            {
                0,/* Ignored */
                DDS_BOOLEAN_FALSE, /* Ignored */
                -1, /* Ignored */
                NULL /* Ignored */
            },
            CM, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Ignored */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"FO",/* Member name */
            {
                0,/* Ignored */
                DDS_BOOLEAN_FALSE, /* Ignored */
                -1, /* Ignored */
                NULL /* Ignored */
            },
            FO, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Ignored */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"CMFO",/* Member name */
            {
                0,/* Ignored */
                DDS_BOOLEAN_FALSE, /* Ignored */
                -1, /* Ignored */
                NULL /* Ignored */
            },
            CMFO, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Ignored */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"BSE",/* Member name */
            {
                0,/* Ignored */
                DDS_BOOLEAN_FALSE, /* Ignored */
                -1, /* Ignored */
                NULL /* Ignored */
            },
            BSE, /* Enumerator ordinal */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Ignored */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode eLineType_g_tc = 
    {{
        DDS_TK_ENUM, /* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1, /* Ignored */
        (char *)"MONITORING::eLineType", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        4, /* Number of enumerators */
        eLineType_g_tc_members, /* Enumerators */
        DDS_VM_NONE /* Ignored */
}    };

    if (is_initialized) {
        return &eLineType_g_tc;
    }

    is_initialized = RTI_TRUE;
    return &eLineType_g_tc;
}
 

RTIBool eLineType_initialize(
    eLineType* sample)
{
    /* The following method initializes the enum value to zero. However,
     * some enumerations may not have a member with the value zero. In such
     * cases, it may be desirable to modify the generated code to use a valid
     * enumeration member instead.
     */
    return RTICdrType_initEnum((RTICdrEnum*) sample);
}
        
RTIBool eLineType_initialize_ex(
    eLineType* sample, RTIBool allocatePointers)
{
    /* The following method initializes the enum value to zero. However,
     * some enumerations may not have a member with the value zero. In such
     * cases, it may be desirable to modify the generated code to use a valid
     * enumeration member instead.
     */
    if (allocatePointers) {} /* To avoid warnings */
    return RTICdrType_initEnum((RTICdrEnum*) sample);
}

void eLineType_finalize(
    eLineType* sample)
{
    if (sample) {} /* To avoid warnings */
    /* empty */
}
        
void eLineType_finalize_ex(
    eLineType* sample,RTIBool deletePointers)
{
    if (sample) {} /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */
    /* empty */
}

RTIBool eLineType_copy(
    eLineType* dst,
    const eLineType* src)
{
    return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'eLineType' sequence class.
 */
#define T eLineType
#define TSeq eLineTypeSeq
#define T_initialize_ex eLineType_initialize_ex
#define T_finalize_ex   eLineType_finalize_ex
#define T_copy       eLineType_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T
/* ========================================================================= */
const char *lineDetailsTYPENAME = "MONITORING::lineDetails";

DDS_TypeCode* lineDetails_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode lineDetails_g_tc_product_details_string = DDS_INITIALIZE_STRING_TYPECODE(1024);

    static DDS_TypeCode_Member lineDetails_g_tc_members[2]=
    {
        {
            (char *)"line_id",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"product_details",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode lineDetails_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"MONITORING::lineDetails", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        lineDetails_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for lineDetails*/

    if (is_initialized) {
        return &lineDetails_g_tc;
    }


    lineDetails_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    lineDetails_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&lineDetails_g_tc_product_details_string;

    is_initialized = RTI_TRUE;

    return &lineDetails_g_tc;
}


RTIBool lineDetails_initialize(
    lineDetails* sample) {
  return ::MONITORING::lineDetails_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool lineDetails_initialize_ex(
    lineDetails* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    if (!RTICdrType_initLong(&sample->line_id)) {
        return RTI_FALSE;
    }                
            
    sample->product_details = DDS_String_alloc((1024));
    if (sample->product_details == NULL) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void lineDetails_finalize(
    lineDetails* sample)
{
    ::MONITORING::lineDetails_finalize_ex(sample,RTI_TRUE);
}
        
void lineDetails_finalize_ex(
    lineDetails* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


    DDS_String_free(sample->product_details);                
            
}

RTIBool lineDetails_copy(
    lineDetails* dst,
    const lineDetails* src)
{        

    if (!RTICdrType_copyLong(
        &dst->line_id, &src->line_id)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->product_details, src->product_details, (1024) + 1)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'lineDetails' sequence class.
 */
#define T lineDetails
#define TSeq lineDetailsSeq
#define T_initialize_ex ::MONITORING::lineDetails_initialize_ex
#define T_finalize_ex   ::MONITORING::lineDetails_finalize_ex
#define T_copy       ::MONITORING::lineDetails_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *pslInfoTYPENAME = "MONITORING::pslInfo";

DDS_TypeCode* pslInfo_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode pslInfo_g_tc_ipadress_string = DDS_INITIALIZE_STRING_TYPECODE(16);
    static DDS_TypeCode pslInfo_g_tc_processInfo_string = DDS_INITIALIZE_STRING_TYPECODE(1024);
    static DDS_TypeCode pslInfo_g_tc_spaceInfo_string = DDS_INITIALIZE_STRING_TYPECODE(1024);
    static DDS_TypeCode pslInfo_g_tc_cancelOrderStatus_string = DDS_INITIALIZE_STRING_TYPECODE(512);
    static DDS_TypeCode pslInfo_g_tc_lineInfo_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE(12,NULL);

    static DDS_TypeCode_Member pslInfo_g_tc_members[5]=
    {
        {
            (char *)"ipadress",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"processInfo",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"spaceInfo",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"cancelOrderStatus",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"lineInfo",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode pslInfo_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"MONITORING::pslInfo", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        5, /* Number of members */
        pslInfo_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for pslInfo*/

    if (is_initialized) {
        return &pslInfo_g_tc;
    }

    pslInfo_g_tc_lineInfo_sequence._data._typeCode = (RTICdrTypeCode *)MONITORING::lineDetails_get_typecode();

    pslInfo_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&pslInfo_g_tc_ipadress_string;
    pslInfo_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&pslInfo_g_tc_processInfo_string;
    pslInfo_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&pslInfo_g_tc_spaceInfo_string;
    pslInfo_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&pslInfo_g_tc_cancelOrderStatus_string;
    pslInfo_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&pslInfo_g_tc_lineInfo_sequence;

    is_initialized = RTI_TRUE;

    return &pslInfo_g_tc;
}


RTIBool pslInfo_initialize(
    pslInfo* sample) {
  return ::MONITORING::pslInfo_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool pslInfo_initialize_ex(
    pslInfo* sample,RTIBool allocatePointers)
{

    void* buffer = NULL;
    if (buffer) {} /* To avoid warnings */
        
    
    if (allocatePointers) {} /* To avoid warnings */


    sample->ipadress = DDS_String_alloc((16));
    if (sample->ipadress == NULL) {
        return RTI_FALSE;
    }
            
    sample->processInfo = DDS_String_alloc((1024));
    if (sample->processInfo == NULL) {
        return RTI_FALSE;
    }
            
    sample->spaceInfo = DDS_String_alloc((1024));
    if (sample->spaceInfo == NULL) {
        return RTI_FALSE;
    }
            
    sample->cancelOrderStatus = DDS_String_alloc((512));
    if (sample->cancelOrderStatus == NULL) {
        return RTI_FALSE;
    }
            
    MONITORING::lineDetailsSeq_initialize(&sample->lineInfo);
    MONITORING::lineDetailsSeq_set_element_pointers_allocation(&sample->lineInfo,allocatePointers);
    if (!MONITORING::lineDetailsSeq_set_maximum(&sample->lineInfo,
                                       (12))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void pslInfo_finalize(
    pslInfo* sample)
{
    ::MONITORING::pslInfo_finalize_ex(sample,RTI_TRUE);
}
        
void pslInfo_finalize_ex(
    pslInfo* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


    DDS_String_free(sample->ipadress);                
            
    DDS_String_free(sample->processInfo);                
            
    DDS_String_free(sample->spaceInfo);                
            
    DDS_String_free(sample->cancelOrderStatus);                
            
    MONITORING::lineDetailsSeq_finalize(&sample->lineInfo);
            
}

RTIBool pslInfo_copy(
    pslInfo* dst,
    const pslInfo* src)
{        

    if (!RTICdrType_copyString(
        dst->ipadress, src->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->processInfo, src->processInfo, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->spaceInfo, src->spaceInfo, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->cancelOrderStatus, src->cancelOrderStatus, (512) + 1)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::lineDetailsSeq_copy_no_alloc(&dst->lineInfo,
                                          &src->lineInfo)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'pslInfo' sequence class.
 */
#define T pslInfo
#define TSeq pslInfoSeq
#define T_initialize_ex ::MONITORING::pslInfo_initialize_ex
#define T_finalize_ex   ::MONITORING::pslInfo_finalize_ex
#define T_copy       ::MONITORING::pslInfo_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *ipSequenceTYPENAME = "MONITORING::ipSequence";

DDS_TypeCode* ipSequence_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode ipSequence_g_tc_ipadress_string = DDS_INITIALIZE_STRING_TYPECODE(16);
    static DDS_TypeCode ipSequence_g_tc_psl_string = DDS_INITIALIZE_STRING_TYPECODE(20);

    static DDS_TypeCode_Member ipSequence_g_tc_members[4]=
    {
        {
            (char *)"ipadress",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"status",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"CancelOrderId",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"psl",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode ipSequence_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"MONITORING::ipSequence", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        4, /* Number of members */
        ipSequence_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for ipSequence*/

    if (is_initialized) {
        return &ipSequence_g_tc;
    }


    ipSequence_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&ipSequence_g_tc_ipadress_string;
    ipSequence_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)MONITORING::eState_get_typecode();
    ipSequence_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    ipSequence_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&ipSequence_g_tc_psl_string;

    is_initialized = RTI_TRUE;

    return &ipSequence_g_tc;
}


RTIBool ipSequence_initialize(
    ipSequence* sample) {
  return ::MONITORING::ipSequence_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool ipSequence_initialize_ex(
    ipSequence* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    sample->ipadress = DDS_String_alloc((16));
    if (sample->ipadress == NULL) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eState_initialize_ex(&sample->status,allocatePointers)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_initLong(&sample->CancelOrderId)) {
        return RTI_FALSE;
    }                
            
    sample->psl = DDS_String_alloc((20));
    if (sample->psl == NULL) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void ipSequence_finalize(
    ipSequence* sample)
{
    ::MONITORING::ipSequence_finalize_ex(sample,RTI_TRUE);
}
        
void ipSequence_finalize_ex(
    ipSequence* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


    DDS_String_free(sample->ipadress);                
            
    MONITORING::eState_finalize_ex(&sample->status,deletePointers);
            
    DDS_String_free(sample->psl);                
            
}

RTIBool ipSequence_copy(
    ipSequence* dst,
    const ipSequence* src)
{        

    if (!RTICdrType_copyString(
        dst->ipadress, src->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eState_copy(
        &dst->status, &src->status)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->CancelOrderId, &src->CancelOrderId)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->psl, src->psl, (20) + 1)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'ipSequence' sequence class.
 */
#define T ipSequence
#define TSeq ipSequenceSeq
#define T_initialize_ex ::MONITORING::ipSequence_initialize_ex
#define T_finalize_ex   ::MONITORING::ipSequence_finalize_ex
#define T_copy       ::MONITORING::ipSequence_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *leaseProcessStartTYPENAME = "MONITORING::leaseProcessStart";

DDS_TypeCode* leaseProcessStart_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode leaseProcessStart_g_tc_ip_info_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE(12,NULL);

    static DDS_TypeCode_Member leaseProcessStart_g_tc_members[1]=
    {
        {
            (char *)"ip_info",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode leaseProcessStart_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"MONITORING::leaseProcessStart", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        1, /* Number of members */
        leaseProcessStart_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for leaseProcessStart*/

    if (is_initialized) {
        return &leaseProcessStart_g_tc;
    }

    leaseProcessStart_g_tc_ip_info_sequence._data._typeCode = (RTICdrTypeCode *)MONITORING::ipSequence_get_typecode();

    leaseProcessStart_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&leaseProcessStart_g_tc_ip_info_sequence;

    is_initialized = RTI_TRUE;

    return &leaseProcessStart_g_tc;
}


RTIBool leaseProcessStart_initialize(
    leaseProcessStart* sample) {
  return ::MONITORING::leaseProcessStart_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool leaseProcessStart_initialize_ex(
    leaseProcessStart* sample,RTIBool allocatePointers)
{

    void* buffer = NULL;
    if (buffer) {} /* To avoid warnings */
        
    
    if (allocatePointers) {} /* To avoid warnings */


    MONITORING::ipSequenceSeq_initialize(&sample->ip_info);
    MONITORING::ipSequenceSeq_set_element_pointers_allocation(&sample->ip_info,allocatePointers);
    if (!MONITORING::ipSequenceSeq_set_maximum(&sample->ip_info,
                                       (12))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void leaseProcessStart_finalize(
    leaseProcessStart* sample)
{
    ::MONITORING::leaseProcessStart_finalize_ex(sample,RTI_TRUE);
}
        
void leaseProcessStart_finalize_ex(
    leaseProcessStart* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


    MONITORING::ipSequenceSeq_finalize(&sample->ip_info);
            
}

RTIBool leaseProcessStart_copy(
    leaseProcessStart* dst,
    const leaseProcessStart* src)
{        

    if (!MONITORING::ipSequenceSeq_copy_no_alloc(&dst->ip_info,
                                          &src->ip_info)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'leaseProcessStart' sequence class.
 */
#define T leaseProcessStart
#define TSeq leaseProcessStartSeq
#define T_initialize_ex ::MONITORING::leaseProcessStart_initialize_ex
#define T_finalize_ex   ::MONITORING::leaseProcessStart_finalize_ex
#define T_copy       ::MONITORING::leaseProcessStart_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *leaseLineInfoTYPENAME = "MONITORING::leaseLineInfo";

DDS_TypeCode* leaseLineInfo_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode leaseLineInfo_g_tc_ipadress_string = DDS_INITIALIZE_STRING_TYPECODE(16);

    static DDS_TypeCode_Member leaseLineInfo_g_tc_members[4]=
    {
        {
            (char *)"ipadress",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"lineId",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"status",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"linetype",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode leaseLineInfo_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"MONITORING::leaseLineInfo", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        4, /* Number of members */
        leaseLineInfo_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for leaseLineInfo*/

    if (is_initialized) {
        return &leaseLineInfo_g_tc;
    }


    leaseLineInfo_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&leaseLineInfo_g_tc_ipadress_string;
    leaseLineInfo_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    leaseLineInfo_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)MONITORING::elinestatus_get_typecode();
    leaseLineInfo_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)MONITORING::eLineType_get_typecode();

    is_initialized = RTI_TRUE;

    return &leaseLineInfo_g_tc;
}


RTIBool leaseLineInfo_initialize(
    leaseLineInfo* sample) {
  return ::MONITORING::leaseLineInfo_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool leaseLineInfo_initialize_ex(
    leaseLineInfo* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    sample->ipadress = DDS_String_alloc((16));
    if (sample->ipadress == NULL) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_initLong(&sample->lineId)) {
        return RTI_FALSE;
    }                
            
    if (!MONITORING::elinestatus_initialize_ex(&sample->status,allocatePointers)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eLineType_initialize_ex(&sample->linetype,allocatePointers)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void leaseLineInfo_finalize(
    leaseLineInfo* sample)
{
    ::MONITORING::leaseLineInfo_finalize_ex(sample,RTI_TRUE);
}
        
void leaseLineInfo_finalize_ex(
    leaseLineInfo* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


    DDS_String_free(sample->ipadress);                
            
    MONITORING::elinestatus_finalize_ex(&sample->status,deletePointers);
            
    MONITORING::eLineType_finalize_ex(&sample->linetype,deletePointers);
            
}

RTIBool leaseLineInfo_copy(
    leaseLineInfo* dst,
    const leaseLineInfo* src)
{        

    if (!RTICdrType_copyString(
        dst->ipadress, src->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyLong(
        &dst->lineId, &src->lineId)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::elinestatus_copy(
        &dst->status, &src->status)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eLineType_copy(
        &dst->linetype, &src->linetype)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'leaseLineInfo' sequence class.
 */
#define T leaseLineInfo
#define TSeq leaseLineInfoSeq
#define T_initialize_ex ::MONITORING::leaseLineInfo_initialize_ex
#define T_finalize_ex   ::MONITORING::leaseLineInfo_finalize_ex
#define T_copy       ::MONITORING::leaseLineInfo_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *tapServerInfoTYPENAME = "MONITORING::tapServerInfo";

DDS_TypeCode* tapServerInfo_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode tapServerInfo_g_tc_ipv4Address_string = DDS_INITIALIZE_STRING_TYPECODE(16);
    static DDS_TypeCode tapServerInfo_g_tc_line_info_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((MONITORING::MAX_LEASE_LINE),NULL);

    static DDS_TypeCode_Member tapServerInfo_g_tc_members[3]=
    {
        {
            (char *)"ipv4Address",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"status",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"line_info",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode tapServerInfo_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"MONITORING::tapServerInfo", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        3, /* Number of members */
        tapServerInfo_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for tapServerInfo*/

    if (is_initialized) {
        return &tapServerInfo_g_tc;
    }

    tapServerInfo_g_tc_line_info_sequence._data._typeCode = (RTICdrTypeCode *)MONITORING::leaseLineInfo_get_typecode();

    tapServerInfo_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&tapServerInfo_g_tc_ipv4Address_string;
    tapServerInfo_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)MONITORING::eState_get_typecode();
    tapServerInfo_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&tapServerInfo_g_tc_line_info_sequence;

    is_initialized = RTI_TRUE;

    return &tapServerInfo_g_tc;
}


RTIBool tapServerInfo_initialize(
    tapServerInfo* sample) {
  return ::MONITORING::tapServerInfo_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool tapServerInfo_initialize_ex(
    tapServerInfo* sample,RTIBool allocatePointers)
{

    void* buffer = NULL;
    if (buffer) {} /* To avoid warnings */
        
    
    if (allocatePointers) {} /* To avoid warnings */


    sample->ipv4Address = DDS_String_alloc((16));
    if (sample->ipv4Address == NULL) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eState_initialize_ex(&sample->status,allocatePointers)) {
        return RTI_FALSE;
    }
            
    MONITORING::leaseLineInfoSeq_initialize(&sample->line_info);
    MONITORING::leaseLineInfoSeq_set_element_pointers_allocation(&sample->line_info,allocatePointers);
    if (!MONITORING::leaseLineInfoSeq_set_maximum(&sample->line_info,
                                       ((MONITORING::MAX_LEASE_LINE)))) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void tapServerInfo_finalize(
    tapServerInfo* sample)
{
    ::MONITORING::tapServerInfo_finalize_ex(sample,RTI_TRUE);
}
        
void tapServerInfo_finalize_ex(
    tapServerInfo* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


    DDS_String_free(sample->ipv4Address);                
            
    MONITORING::eState_finalize_ex(&sample->status,deletePointers);
            
    MONITORING::leaseLineInfoSeq_finalize(&sample->line_info);
            
}

RTIBool tapServerInfo_copy(
    tapServerInfo* dst,
    const tapServerInfo* src)
{        

    if (!RTICdrType_copyString(
        dst->ipv4Address, src->ipv4Address, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eState_copy(
        &dst->status, &src->status)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::leaseLineInfoSeq_copy_no_alloc(&dst->line_info,
                                          &src->line_info)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'tapServerInfo' sequence class.
 */
#define T tapServerInfo
#define TSeq tapServerInfoSeq
#define T_initialize_ex ::MONITORING::tapServerInfo_initialize_ex
#define T_finalize_ex   ::MONITORING::tapServerInfo_finalize_ex
#define T_copy       ::MONITORING::tapServerInfo_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *tagProcessInfoTYPENAME = "MONITORING::tagProcessInfo";

DDS_TypeCode* tagProcessInfo_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode tagProcessInfo_g_tc_name_string = DDS_INITIALIZE_STRING_TYPECODE((MONITORING::MAX_PROC_NAMELEN));

    static DDS_TypeCode_Member tagProcessInfo_g_tc_members[2]=
    {
        {
            (char *)"name",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"state",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode tagProcessInfo_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"MONITORING::tagProcessInfo", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        tagProcessInfo_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for tagProcessInfo*/

    if (is_initialized) {
        return &tagProcessInfo_g_tc;
    }


    tagProcessInfo_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&tagProcessInfo_g_tc_name_string;
    tagProcessInfo_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)MONITORING::eState_get_typecode();

    is_initialized = RTI_TRUE;

    return &tagProcessInfo_g_tc;
}


RTIBool tagProcessInfo_initialize(
    tagProcessInfo* sample) {
  return ::MONITORING::tagProcessInfo_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool tagProcessInfo_initialize_ex(
    tagProcessInfo* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    sample->name = DDS_String_alloc(((MONITORING::MAX_PROC_NAMELEN)));
    if (sample->name == NULL) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eState_initialize_ex(&sample->state,allocatePointers)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}

void tagProcessInfo_finalize(
    tagProcessInfo* sample)
{
    ::MONITORING::tagProcessInfo_finalize_ex(sample,RTI_TRUE);
}
        
void tagProcessInfo_finalize_ex(
    tagProcessInfo* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


    DDS_String_free(sample->name);                
            
    MONITORING::eState_finalize_ex(&sample->state,deletePointers);
            
}

RTIBool tagProcessInfo_copy(
    tagProcessInfo* dst,
    const tagProcessInfo* src)
{        

    if (!RTICdrType_copyString(
        dst->name, src->name, ((MONITORING::MAX_PROC_NAMELEN)) + 1)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eState_copy(
        &dst->state, &src->state)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'tagProcessInfo' sequence class.
 */
#define T tagProcessInfo
#define TSeq tagProcessInfoSeq
#define T_initialize_ex ::MONITORING::tagProcessInfo_initialize_ex
#define T_finalize_ex   ::MONITORING::tagProcessInfo_finalize_ex
#define T_copy       ::MONITORING::tagProcessInfo_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *tagSpaceInfoTYPENAME = "MONITORING::tagSpaceInfo";

DDS_TypeCode* tagSpaceInfo_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode tagSpaceInfo_g_tc_name_string = DDS_INITIALIZE_STRING_TYPECODE((MONITORING::MAX_DIR_PATHLEN));

    static DDS_TypeCode_Member tagSpaceInfo_g_tc_members[2]=
    {
        {
            (char *)"name",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"is_space_full",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode tagSpaceInfo_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"MONITORING::tagSpaceInfo", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        2, /* Number of members */
        tagSpaceInfo_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for tagSpaceInfo*/

    if (is_initialized) {
        return &tagSpaceInfo_g_tc;
    }


    tagSpaceInfo_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&tagSpaceInfo_g_tc_name_string;
    tagSpaceInfo_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

    is_initialized = RTI_TRUE;

    return &tagSpaceInfo_g_tc;
}


RTIBool tagSpaceInfo_initialize(
    tagSpaceInfo* sample) {
  return ::MONITORING::tagSpaceInfo_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool tagSpaceInfo_initialize_ex(
    tagSpaceInfo* sample,RTIBool allocatePointers)
{
        
    
    if (allocatePointers) {} /* To avoid warnings */


    sample->name = DDS_String_alloc(((MONITORING::MAX_DIR_PATHLEN)));
    if (sample->name == NULL) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_initBoolean(&sample->is_space_full)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void tagSpaceInfo_finalize(
    tagSpaceInfo* sample)
{
    ::MONITORING::tagSpaceInfo_finalize_ex(sample,RTI_TRUE);
}
        
void tagSpaceInfo_finalize_ex(
    tagSpaceInfo* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


    DDS_String_free(sample->name);                
            
}

RTIBool tagSpaceInfo_copy(
    tagSpaceInfo* dst,
    const tagSpaceInfo* src)
{        

    if (!RTICdrType_copyString(
        dst->name, src->name, ((MONITORING::MAX_DIR_PATHLEN)) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyBoolean(
        &dst->is_space_full, &src->is_space_full)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'tagSpaceInfo' sequence class.
 */
#define T tagSpaceInfo
#define TSeq tagSpaceInfoSeq
#define T_initialize_ex ::MONITORING::tagSpaceInfo_initialize_ex
#define T_finalize_ex   ::MONITORING::tagSpaceInfo_finalize_ex
#define T_copy       ::MONITORING::tagSpaceInfo_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T

/* ========================================================================= */
const char *tagServerInfoTYPENAME = "MONITORING::tagServerInfo";

DDS_TypeCode* tagServerInfo_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode tagServerInfo_g_tc_ipv4Address_string = DDS_INITIALIZE_STRING_TYPECODE(16);
    static DDS_TypeCode tagServerInfo_g_tc_process_list_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((MONITORING::MAX_PROCESSES),NULL);
    static DDS_TypeCode tagServerInfo_g_tc_space_list_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((MONITORING::MAX_SPACES),NULL);
    static DDS_TypeCode tagServerInfo_g_tc_line_info_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((MONITORING::MAX_LEASE_LINE),NULL);
    static DDS_TypeCode tagServerInfo_g_tc_Logpath_string = DDS_INITIALIZE_STRING_TYPECODE(100);

    static DDS_TypeCode_Member tagServerInfo_g_tc_members[7]=
    {
        {
            (char *)"ipv4Address",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"serverStatus",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"process_list",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"space_list",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"line_info",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_TRUE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"Logpath",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        },
        {
            (char *)"status",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            DDS_BOOLEAN_FALSE, /* Is a key? */
            DDS_PRIVATE_MEMBER,/* Ignored */
            0,/* Ignored */
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode tagServerInfo_g_tc =
    {{
        DDS_TK_STRUCT,/* Kind */
        DDS_BOOLEAN_FALSE, /* Ignored */
        -1,/* Ignored */
        (char *)"MONITORING::tagServerInfo", /* Name */
        NULL, /* Ignored */
        0, /* Ignored */
        0, /* Ignored */
        NULL, /* Ignored */
        7, /* Number of members */
        tagServerInfo_g_tc_members, /* Members */
        DDS_VM_NONE /* Ignored */
    }}; /* Type code for tagServerInfo*/

    if (is_initialized) {
        return &tagServerInfo_g_tc;
    }

    tagServerInfo_g_tc_process_list_sequence._data._typeCode = (RTICdrTypeCode *)MONITORING::tagProcessInfo_get_typecode();
    tagServerInfo_g_tc_space_list_sequence._data._typeCode = (RTICdrTypeCode *)MONITORING::tagSpaceInfo_get_typecode();
    tagServerInfo_g_tc_line_info_sequence._data._typeCode = (RTICdrTypeCode *)MONITORING::leaseLineInfo_get_typecode();

    tagServerInfo_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&tagServerInfo_g_tc_ipv4Address_string;
    tagServerInfo_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;
    tagServerInfo_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&tagServerInfo_g_tc_process_list_sequence;
    tagServerInfo_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&tagServerInfo_g_tc_space_list_sequence;
    tagServerInfo_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&tagServerInfo_g_tc_line_info_sequence;
    tagServerInfo_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&tagServerInfo_g_tc_Logpath_string;
    tagServerInfo_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

    is_initialized = RTI_TRUE;

    return &tagServerInfo_g_tc;
}


RTIBool tagServerInfo_initialize(
    tagServerInfo* sample) {
  return ::MONITORING::tagServerInfo_initialize_ex(sample,RTI_TRUE);
}
        
RTIBool tagServerInfo_initialize_ex(
    tagServerInfo* sample,RTIBool allocatePointers)
{

    void* buffer = NULL;
    if (buffer) {} /* To avoid warnings */
        
    
    if (allocatePointers) {} /* To avoid warnings */


    sample->ipv4Address = DDS_String_alloc((16));
    if (sample->ipv4Address == NULL) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_initBoolean(&sample->serverStatus)) {
        return RTI_FALSE;
    }                
            
    MONITORING::tagProcessInfoSeq_initialize(&sample->process_list);
    MONITORING::tagProcessInfoSeq_set_element_pointers_allocation(&sample->process_list,allocatePointers);
    if (!MONITORING::tagProcessInfoSeq_set_maximum(&sample->process_list,
                                       ((MONITORING::MAX_PROCESSES)))) {
        return RTI_FALSE;
    }
            
    MONITORING::tagSpaceInfoSeq_initialize(&sample->space_list);
    MONITORING::tagSpaceInfoSeq_set_element_pointers_allocation(&sample->space_list,allocatePointers);
    if (!MONITORING::tagSpaceInfoSeq_set_maximum(&sample->space_list,
                                       ((MONITORING::MAX_SPACES)))) {
        return RTI_FALSE;
    }
            
    MONITORING::leaseLineInfoSeq_initialize(&sample->line_info);
    MONITORING::leaseLineInfoSeq_set_element_pointers_allocation(&sample->line_info,allocatePointers);
    if (!MONITORING::leaseLineInfoSeq_set_maximum(&sample->line_info,
                                       ((MONITORING::MAX_LEASE_LINE)))) {
        return RTI_FALSE;
    }
            
    sample->Logpath = DDS_String_alloc((100));
    if (sample->Logpath == NULL) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_initBoolean(&sample->status)) {
        return RTI_FALSE;
    }                
            

    return RTI_TRUE;
}

void tagServerInfo_finalize(
    tagServerInfo* sample)
{
    ::MONITORING::tagServerInfo_finalize_ex(sample,RTI_TRUE);
}
        
void tagServerInfo_finalize_ex(
    tagServerInfo* sample,RTIBool deletePointers)
{        
    if (sample) { } /* To avoid warnings */
    if (deletePointers) {} /* To avoid warnings */


    DDS_String_free(sample->ipv4Address);                
            
    MONITORING::tagProcessInfoSeq_finalize(&sample->process_list);
            
    MONITORING::tagSpaceInfoSeq_finalize(&sample->space_list);
            
    MONITORING::leaseLineInfoSeq_finalize(&sample->line_info);
            
    DDS_String_free(sample->Logpath);                
            
}

RTIBool tagServerInfo_copy(
    tagServerInfo* dst,
    const tagServerInfo* src)
{        

    if (!RTICdrType_copyString(
        dst->ipv4Address, src->ipv4Address, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyBoolean(
        &dst->serverStatus, &src->serverStatus)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::tagProcessInfoSeq_copy_no_alloc(&dst->process_list,
                                          &src->process_list)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::tagSpaceInfoSeq_copy_no_alloc(&dst->space_list,
                                          &src->space_list)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::leaseLineInfoSeq_copy_no_alloc(&dst->line_info,
                                          &src->line_info)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyString(
        dst->Logpath, src->Logpath, (100) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrType_copyBoolean(
        &dst->status, &src->status)) {
        return RTI_FALSE;
    }
            

    return RTI_TRUE;
}


/**
 * <<IMPLEMENTATION>>
 *
 * Defines:  TSeq, T
 *
 * Configure and implement 'tagServerInfo' sequence class.
 */
#define T tagServerInfo
#define TSeq tagServerInfoSeq
#define T_initialize_ex ::MONITORING::tagServerInfo_initialize_ex
#define T_finalize_ex   ::MONITORING::tagServerInfo_finalize_ex
#define T_copy       ::MONITORING::tagServerInfo_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#endif
#else
#include "dds_c_sequence_TSeq.gen"
#ifdef __cplusplus
#include "dds_cpp_sequence_TSeq.gen"
#endif
#endif

#undef T_copy
#undef T_finalize_ex
#undef T_initialize_ex
#undef TSeq
#undef T


} /* namespace MONITORING */
