
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from Monitoring.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/


#include <string.h>

#ifdef __cplusplus
#ifndef ndds_cpp_h
  #include "ndds/ndds_cpp.h"
#endif
#else
#ifndef ndds_c_h
  #include "ndds/ndds_c.h"
#endif
#endif

#ifndef osapi_type_h
  #include "osapi/osapi_type.h"
#endif
#ifndef osapi_heap_h
  #include "osapi/osapi_heap.h"
#endif

#ifndef osapi_utility_h
  #include "osapi/osapi_utility.h"
#endif

#ifndef cdr_type_h
  #include "cdr/cdr_type.h"
#endif

#ifndef cdr_encapsulation_h
  #include "cdr/cdr_encapsulation.h"
#endif

#ifndef cdr_stream_h
  #include "cdr/cdr_stream.h"
#endif

#ifndef pres_typePlugin_h
  #include "pres/pres_typePlugin.h"
#endif



#include "MonitoringPlugin.h"


namespace MONITORING{


/* ------------------------------------------------------------------------
   Enum Type: elinestatus
 * ------------------------------------------------------------------------- */
 
/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool elinestatusPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const elinestatus *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample,
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_sample) {

        if (!RTICdrStream_serializeEnum(stream, sample))
        {
            return RTI_FALSE;
        }

    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool 
elinestatusPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    elinestatus *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(deserialize_sample) {

        if (!RTICdrStream_deserializeEnum(stream, sample))
        {
            return RTI_FALSE;
        } 

    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool elinestatusPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(skip_sample) {

        if (!RTICdrStream_skipEnum(stream)) {
            return RTI_FALSE;
        }


    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int elinestatusPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */

    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }

    current_alignment += RTICdrType_getEnumMaxSizeSerialized(current_alignment);


    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }


    return current_alignment - initial_alignment;
}


unsigned int elinestatusPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int initial_alignment = current_alignment;

    current_alignment += ::MONITORING::elinestatusPlugin_get_serialized_sample_max_size(
        endpoint_data,include_encapsulation,
        encapsulation_id, current_alignment);

    return current_alignment - initial_alignment;
}


unsigned int
elinestatusPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const elinestatus * sample) 
{
    unsigned int initial_alignment = current_alignment;

    if (sample) {} /* To avoid warnings */ 

    current_alignment += ::MONITORING::elinestatusPlugin_get_serialized_sample_max_size(
        endpoint_data,include_encapsulation,
        encapsulation_id, current_alignment);

    return current_alignment - initial_alignment;
}

/* ------------------------------------------------------------------------
    Key Management functions:
 * ------------------------------------------------------------------------ */


RTIBool elinestatusPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const elinestatus *sample, 
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{   
    return ::MONITORING::elinestatusPlugin_serialize(
            endpoint_data, sample, stream, 
            serialize_encapsulation, encapsulation_id, 
            serialize_key, endpoint_plugin_qos);
}


RTIBool elinestatusPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    elinestatus *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{   
    return ::MONITORING::elinestatusPlugin_deserialize_sample(
            endpoint_data, sample, stream, deserialize_encapsulation, 
            deserialize_key, endpoint_plugin_qos);
}


unsigned int elinestatusPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int initial_alignment = current_alignment;

    current_alignment += ::MONITORING::elinestatusPlugin_get_serialized_sample_max_size(
        endpoint_data,include_encapsulation,
        encapsulation_id, current_alignment);

    return current_alignment - initial_alignment;
}


RTIBool 
elinestatusPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    elinestatus *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{    
    return ::MONITORING::elinestatusPlugin_deserialize_sample(
            endpoint_data, sample, stream, deserialize_encapsulation, 
            deserialize_key, endpoint_plugin_qos);
}

/* ----------------------------------------------------------------------------
    Support functions:
 * ---------------------------------------------------------------------------- */


void elinestatusPluginSupport_print_data(
    const elinestatus *sample,
    const char *description, int indent_level)
{
    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("NULL\n");
        return;
    }

    RTICdrType_printEnum((RTICdrEnum *)sample, "elinestatus", indent_level + 1);
}




/* ------------------------------------------------------------------------
   Enum Type: eState
 * ------------------------------------------------------------------------- */
 
/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool eStatePlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const eState *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample,
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_sample) {

        if (!RTICdrStream_serializeEnum(stream, sample))
        {
            return RTI_FALSE;
        }

    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool 
eStatePlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    eState *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(deserialize_sample) {

        if (!RTICdrStream_deserializeEnum(stream, sample))
        {
            return RTI_FALSE;
        } 

    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool eStatePlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(skip_sample) {

        if (!RTICdrStream_skipEnum(stream)) {
            return RTI_FALSE;
        }


    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int eStatePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */

    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }

    current_alignment += RTICdrType_getEnumMaxSizeSerialized(current_alignment);


    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }


    return current_alignment - initial_alignment;
}


unsigned int eStatePlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int initial_alignment = current_alignment;

    current_alignment += ::MONITORING::eStatePlugin_get_serialized_sample_max_size(
        endpoint_data,include_encapsulation,
        encapsulation_id, current_alignment);

    return current_alignment - initial_alignment;
}


unsigned int
eStatePlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const eState * sample) 
{
    unsigned int initial_alignment = current_alignment;

    if (sample) {} /* To avoid warnings */ 

    current_alignment += ::MONITORING::eStatePlugin_get_serialized_sample_max_size(
        endpoint_data,include_encapsulation,
        encapsulation_id, current_alignment);

    return current_alignment - initial_alignment;
}

/* ------------------------------------------------------------------------
    Key Management functions:
 * ------------------------------------------------------------------------ */


RTIBool eStatePlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const eState *sample, 
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{   
    return ::MONITORING::eStatePlugin_serialize(
            endpoint_data, sample, stream, 
            serialize_encapsulation, encapsulation_id, 
            serialize_key, endpoint_plugin_qos);
}


RTIBool eStatePlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    eState *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{   
    return ::MONITORING::eStatePlugin_deserialize_sample(
            endpoint_data, sample, stream, deserialize_encapsulation, 
            deserialize_key, endpoint_plugin_qos);
}


unsigned int eStatePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int initial_alignment = current_alignment;

    current_alignment += ::MONITORING::eStatePlugin_get_serialized_sample_max_size(
        endpoint_data,include_encapsulation,
        encapsulation_id, current_alignment);

    return current_alignment - initial_alignment;
}


RTIBool 
eStatePlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    eState *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{    
    return ::MONITORING::eStatePlugin_deserialize_sample(
            endpoint_data, sample, stream, deserialize_encapsulation, 
            deserialize_key, endpoint_plugin_qos);
}

/* ----------------------------------------------------------------------------
    Support functions:
 * ---------------------------------------------------------------------------- */


void eStatePluginSupport_print_data(
    const eState *sample,
    const char *description, int indent_level)
{
    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("NULL\n");
        return;
    }

    RTICdrType_printEnum((RTICdrEnum *)sample, "eState", indent_level + 1);
}




/* ------------------------------------------------------------------------
   Enum Type: eLineType
 * ------------------------------------------------------------------------- */
 
/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */


RTIBool eLineTypePlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const eLineType *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample,
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_sample) {

        if (!RTICdrStream_serializeEnum(stream, sample))
        {
            return RTI_FALSE;
        }

    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool 
eLineTypePlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    eLineType *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(deserialize_sample) {

        if (!RTICdrStream_deserializeEnum(stream, sample))
        {
            return RTI_FALSE;
        } 

    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool eLineTypePlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(skip_sample) {

        if (!RTICdrStream_skipEnum(stream)) {
            return RTI_FALSE;
        }


    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int eLineTypePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */

    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }

    current_alignment += RTICdrType_getEnumMaxSizeSerialized(current_alignment);


    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }


    return current_alignment - initial_alignment;
}


unsigned int eLineTypePlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int initial_alignment = current_alignment;

    current_alignment += ::MONITORING::eLineTypePlugin_get_serialized_sample_max_size(
        endpoint_data,include_encapsulation,
        encapsulation_id, current_alignment);

    return current_alignment - initial_alignment;
}


unsigned int
eLineTypePlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const eLineType * sample) 
{
    unsigned int initial_alignment = current_alignment;

    if (sample) {} /* To avoid warnings */ 

    current_alignment += ::MONITORING::eLineTypePlugin_get_serialized_sample_max_size(
        endpoint_data,include_encapsulation,
        encapsulation_id, current_alignment);

    return current_alignment - initial_alignment;
}

/* ------------------------------------------------------------------------
    Key Management functions:
 * ------------------------------------------------------------------------ */


RTIBool eLineTypePlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const eLineType *sample, 
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{   
    return ::MONITORING::eLineTypePlugin_serialize(
            endpoint_data, sample, stream, 
            serialize_encapsulation, encapsulation_id, 
            serialize_key, endpoint_plugin_qos);
}


RTIBool eLineTypePlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    eLineType *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{   
    return ::MONITORING::eLineTypePlugin_deserialize_sample(
            endpoint_data, sample, stream, deserialize_encapsulation, 
            deserialize_key, endpoint_plugin_qos);
}


unsigned int eLineTypePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int initial_alignment = current_alignment;

    current_alignment += ::MONITORING::eLineTypePlugin_get_serialized_sample_max_size(
        endpoint_data,include_encapsulation,
        encapsulation_id, current_alignment);

    return current_alignment - initial_alignment;
}


RTIBool 
eLineTypePlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    eLineType *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{    
    return ::MONITORING::eLineTypePlugin_deserialize_sample(
            endpoint_data, sample, stream, deserialize_encapsulation, 
            deserialize_key, endpoint_plugin_qos);
}

/* ----------------------------------------------------------------------------
    Support functions:
 * ---------------------------------------------------------------------------- */


void eLineTypePluginSupport_print_data(
    const eLineType *sample,
    const char *description, int indent_level)
{
    if (description != NULL) {
        RTICdrType_printIndent(indent_level);
        RTILog_debug("%s:\n", description);
    }

    if (sample == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("NULL\n");
        return;
    }

    RTICdrType_printEnum((RTICdrEnum *)sample, "eLineType", indent_level + 1);
}



/* --------------------------------------------------------------------------------------
 *  Type lineDetails
 * -------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

lineDetails *
lineDetailsPluginSupport_create_data_ex(RTIBool allocate_pointers){
    lineDetails *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, lineDetails);

    if(sample != NULL) {
        if (!::MONITORING::lineDetails_initialize_ex(sample,allocate_pointers)) {
            RTIOsapiHeap_freeStructure(&sample);
            return NULL;
        }
    }
    return sample; 
}


lineDetails *
lineDetailsPluginSupport_create_data(void)
{
    return ::MONITORING::lineDetailsPluginSupport_create_data_ex(RTI_TRUE);
}


void 
lineDetailsPluginSupport_destroy_data_ex(
    lineDetails *sample,RTIBool deallocate_pointers) {

    ::MONITORING::lineDetails_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}


void 
lineDetailsPluginSupport_destroy_data(
    lineDetails *sample) {

    ::MONITORING::lineDetailsPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}


RTIBool 
lineDetailsPluginSupport_copy_data(
    lineDetails *dst,
    const lineDetails *src)
{
    return ::MONITORING::lineDetails_copy(dst,src);
}


void 
lineDetailsPluginSupport_print_data(
    const lineDetails *sample,
    const char *desc,
    unsigned int indent_level)
{


    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
      RTILog_debug("%s:\n", desc);
    } else {
      RTILog_debug("\n");
    }

    if (sample == NULL) {
      RTILog_debug("NULL\n");
      return;
    }


    RTICdrType_printLong(
        &sample->line_id, "line_id", indent_level + 1);
            
    if (&sample->product_details==NULL) {
        RTICdrType_printString(
            NULL, "product_details", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->product_details, "product_details", indent_level + 1);                
    }
            

}

lineDetails *
lineDetailsPluginSupport_create_key_ex(RTIBool allocate_pointers){
    lineDetails *key = NULL;

    RTIOsapiHeap_allocateStructure(
        &key, lineDetailsKeyHolder);

    ::MONITORING::lineDetails_initialize_ex(key,allocate_pointers);
    return key;
}


lineDetails *
lineDetailsPluginSupport_create_key(void)
{
    return  ::MONITORING::lineDetailsPluginSupport_create_key_ex(RTI_TRUE);
}


void 
lineDetailsPluginSupport_destroy_key_ex(
    lineDetailsKeyHolder *key,RTIBool deallocate_pointers)
{
    ::MONITORING::lineDetails_finalize_ex(key,deallocate_pointers);

    RTIOsapiHeap_freeStructure(key);
}


void 
lineDetailsPluginSupport_destroy_key(
    lineDetailsKeyHolder *key) {

  ::MONITORING::lineDetailsPluginSupport_destroy_key_ex(key,RTI_TRUE);

}



/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */



PRESTypePluginParticipantData 
lineDetailsPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */
    return PRESTypePluginDefaultParticipantData_new(participant_info);

}


void 
lineDetailsPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

  PRESTypePluginDefaultParticipantData_delete(participant_data);
}


PRESTypePluginEndpointData
lineDetailsPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    unsigned int serializedKeyMaxSize;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */


    epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            ::MONITORING::lineDetailsPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            ::MONITORING::lineDetailsPluginSupport_destroy_data,
            (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
            ::MONITORING::lineDetailsPluginSupport_create_key,
            (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
            ::MONITORING::lineDetailsPluginSupport_destroy_key);

    if (epd == NULL) {
        return NULL;
    }
   
    serializedKeyMaxSize = ::MONITORING::lineDetailsPlugin_get_serialized_key_max_size(
        epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
    
    if (!PRESTypePluginDefaultEndpointData_createMD5Stream(
            epd,serializedKeyMaxSize)) 
    {
        PRESTypePluginDefaultEndpointData_delete(epd);
        return NULL;
    }

    
    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                ::MONITORING::lineDetailsPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            ::MONITORING::lineDetailsPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }
    


    return epd;    
}


void 
lineDetailsPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}


RTIBool 
lineDetailsPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    lineDetails *dst,
    const lineDetails *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return ::MONITORING::lineDetailsPluginSupport_copy_data(dst,src);
}

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */


RTIBool 
lineDetailsPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const lineDetails *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;


  if (endpoint_data) {} /* To avoid warnings */
  if (endpoint_plugin_qos) {} /* To avoid warnings */


  if(serialize_encapsulation) {

    if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
        return RTI_FALSE;
    }

    position = RTICdrStream_resetAlignment(stream);

  }

  if(serialize_sample) {

    if (!RTICdrStream_serializeLong(
        stream, &sample->line_id)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeString(
        stream, sample->product_details, (1024) + 1)) {
        return RTI_FALSE;
    }
            
  }

  if(serialize_encapsulation) {
    RTICdrStream_restoreAlignment(stream,position);
  }


  return retval;
}


RTIBool 
lineDetailsPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    lineDetails *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }
    
    if(deserialize_sample) {


    if (!RTICdrStream_deserializeLong(
        stream, &sample->line_id)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->product_details, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}

 
 
RTIBool 
lineDetailsPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    lineDetails **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    if (drop_sample) {} /* To avoid warnings */

    return ::MONITORING::lineDetailsPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
 
}



RTIBool lineDetailsPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (skip_sample) {

    if (!RTICdrStream_skipLong(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipString(stream, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int 
lineDetailsPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (1024) + 1);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


unsigned int 
lineDetailsPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


/* Returns the size of the sample in its serialized form (in bytes).
 * It can also be an estimation in excess of the real buffer needed 
 * during a call to the serialize() function.
 * The value reported does not have to include the space for the
 * encapsulation flags.
 */
unsigned int
lineDetailsPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const lineDetails * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (sample) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment += RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getStringSerializedSize(
        current_alignment, sample->product_details);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */


PRESTypePluginKeyKind 
lineDetailsPlugin_get_key_kind(void)
{

    return PRES_TYPEPLUGIN_USER_KEY;
     
}


RTIBool 
lineDetailsPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const lineDetails *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_key) {

    if (!RTICdrStream_serializeLong(
        stream, &sample->line_id)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeString(
        stream, sample->product_details, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool lineDetailsPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    lineDetails *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;  
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializeLong(
        stream, &sample->line_id)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->product_details, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


 
RTIBool lineDetailsPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    lineDetails **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    if (drop_sample) {} /* To avoid warnings */
    return ::MONITORING::lineDetailsPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
}



unsigned int
lineDetailsPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int encapsulation_size = current_alignment;


    unsigned int initial_alignment = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
        

    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (1024) + 1);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


RTIBool 
lineDetailsPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    lineDetails *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializeLong(
        stream, &sample->line_id)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->product_details, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}





RTIBool 
lineDetailsPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    lineDetailsKeyHolder *dst, 
    const lineDetails *src)
{  

    if (endpoint_data) {} /* To avoid warnings */

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


RTIBool 
lineDetailsPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    lineDetails *dst, const
    lineDetailsKeyHolder *src)
{

    if (endpoint_data) {} /* To avoid warnings */

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


RTIBool 
lineDetailsPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const lineDetails *instance)
{
    struct RTICdrStream * md5Stream = NULL;

    md5Stream = PRESTypePluginDefaultEndpointData_getMD5Stream(endpoint_data);

    if (md5Stream == NULL) {
        return RTI_FALSE;
    }

    RTIOsapiMemory_zero(
        RTICdrStream_getBuffer(md5Stream),
        RTICdrStream_getBufferLength(md5Stream));
    RTICdrStream_resetPosition(md5Stream);
    RTICdrStream_setDirtyBit(md5Stream, RTI_TRUE);

    if (!::MONITORING::lineDetailsPlugin_serialize_key(
            endpoint_data,instance,md5Stream, RTI_FALSE, RTI_CDR_ENCAPSULATION_ID_CDR_BE, RTI_TRUE,NULL)) {
        return RTI_FALSE;
    }
    
    if (PRESTypePluginDefaultEndpointData_getMaxSizeSerializedKey(endpoint_data) > (unsigned int)(MIG_RTPS_KEY_HASH_MAX_LENGTH)) {
        RTICdrStream_computeMD5(md5Stream, keyhash->value);
    } else {
        RTIOsapiMemory_zero(keyhash->value,MIG_RTPS_KEY_HASH_MAX_LENGTH);
        RTIOsapiMemory_copy(
            keyhash->value, 
            RTICdrStream_getBuffer(md5Stream), 
            RTICdrStream_getCurrentPositionOffset(md5Stream));
    }

    keyhash->length = MIG_RTPS_KEY_HASH_MAX_LENGTH;
    return RTI_TRUE;
}


RTIBool 
lineDetailsPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos) 
{   
    char * position = NULL;
    lineDetails * sample;

    if (endpoint_plugin_qos) {} /* To avoid warnings */



    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }


    sample = (lineDetails *)
                PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);

    if (sample == NULL) {
        return RTI_FALSE;
    }


    if (!RTICdrStream_deserializeLong(
        stream, &sample->line_id)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->product_details, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    if (!::MONITORING::lineDetailsPlugin_instance_to_keyhash(
            endpoint_data, keyhash, sample)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}


/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */
 
struct PRESTypePlugin *lineDetailsPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
       return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        ::MONITORING::lineDetailsPlugin_on_participant_attached;
    plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        ::MONITORING::lineDetailsPlugin_on_participant_detached;
    plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        ::MONITORING::lineDetailsPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        ::MONITORING::lineDetailsPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        ::MONITORING::lineDetailsPlugin_copy_sample;
    plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        lineDetailsPlugin_create_sample;
    plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        lineDetailsPlugin_destroy_sample;

    plugin->serializeFnc =
        (PRESTypePluginSerializeFunction)
        ::MONITORING::lineDetailsPlugin_serialize;
    plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction)
        ::MONITORING::lineDetailsPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        ::MONITORING::lineDetailsPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        ::MONITORING::lineDetailsPlugin_get_serialized_sample_min_size;


    plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        lineDetailsPlugin_get_sample;
    plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        lineDetailsPlugin_return_sample;

    plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        ::MONITORING::lineDetailsPlugin_get_key_kind;


    plugin->getSerializedKeyMaxSizeFnc =   
        (PRESTypePluginGetSerializedKeyMaxSizeFunction)
        ::MONITORING::lineDetailsPlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
        (PRESTypePluginSerializeKeyFunction)
        ::MONITORING::lineDetailsPlugin_serialize_key;
    plugin->deserializeKeyFnc =
        (PRESTypePluginDeserializeKeyFunction)
        ::MONITORING::lineDetailsPlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
        (PRESTypePluginDeserializeKeySampleFunction)
        ::MONITORING::lineDetailsPlugin_deserialize_key_sample;

    plugin->instanceToKeyHashFnc = 
        (PRESTypePluginInstanceToKeyHashFunction)
        ::MONITORING::lineDetailsPlugin_instance_to_keyhash;
    plugin->serializedSampleToKeyHashFnc = 
        (PRESTypePluginSerializedSampleToKeyHashFunction)
        ::MONITORING::lineDetailsPlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
        (PRESTypePluginGetKeyFunction)
        lineDetailsPlugin_get_key;
    plugin->returnKeyFnc =
        (PRESTypePluginReturnKeyFunction)
        lineDetailsPlugin_return_key;

    plugin->instanceToKeyFnc =
        (PRESTypePluginInstanceToKeyFunction)
        ::MONITORING::lineDetailsPlugin_instance_to_key;
    plugin->keyToInstanceFnc =
        (PRESTypePluginKeyToInstanceFunction)
        ::MONITORING::lineDetailsPlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    
    plugin->typeCode =  (struct RTICdrTypeCode *)::MONITORING::lineDetails_get_typecode();
    
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

    /* Serialized buffer */
    plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        lineDetailsPlugin_get_buffer;
    plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        lineDetailsPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        ::MONITORING::lineDetailsPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = lineDetailsTYPENAME;

    return plugin;
}

void
lineDetailsPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* --------------------------------------------------------------------------------------
 *  Type pslInfo
 * -------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

pslInfo *
pslInfoPluginSupport_create_data_ex(RTIBool allocate_pointers){
    pslInfo *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, pslInfo);

    if(sample != NULL) {
        if (!::MONITORING::pslInfo_initialize_ex(sample,allocate_pointers)) {
            RTIOsapiHeap_freeStructure(&sample);
            return NULL;
        }
    }
    return sample; 
}


pslInfo *
pslInfoPluginSupport_create_data(void)
{
    return ::MONITORING::pslInfoPluginSupport_create_data_ex(RTI_TRUE);
}


void 
pslInfoPluginSupport_destroy_data_ex(
    pslInfo *sample,RTIBool deallocate_pointers) {

    ::MONITORING::pslInfo_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}


void 
pslInfoPluginSupport_destroy_data(
    pslInfo *sample) {

    ::MONITORING::pslInfoPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}


RTIBool 
pslInfoPluginSupport_copy_data(
    pslInfo *dst,
    const pslInfo *src)
{
    return ::MONITORING::pslInfo_copy(dst,src);
}


void 
pslInfoPluginSupport_print_data(
    const pslInfo *sample,
    const char *desc,
    unsigned int indent_level)
{


    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
      RTILog_debug("%s:\n", desc);
    } else {
      RTILog_debug("\n");
    }

    if (sample == NULL) {
      RTILog_debug("NULL\n");
      return;
    }


    if (&sample->ipadress==NULL) {
        RTICdrType_printString(
            NULL, "ipadress", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->ipadress, "ipadress", indent_level + 1);                
    }
            
    if (&sample->processInfo==NULL) {
        RTICdrType_printString(
            NULL, "processInfo", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->processInfo, "processInfo", indent_level + 1);                
    }
            
    if (&sample->spaceInfo==NULL) {
        RTICdrType_printString(
            NULL, "spaceInfo", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->spaceInfo, "spaceInfo", indent_level + 1);                
    }
            
    if (&sample->cancelOrderStatus==NULL) {
        RTICdrType_printString(
            NULL, "cancelOrderStatus", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->cancelOrderStatus, "cancelOrderStatus", indent_level + 1);                
    }
            
    if (&sample->lineInfo == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("lineInfo: NULL\n");    
    } else {
                
        if (MONITORING::lineDetailsSeq_get_contiguous_bufferI(&sample->lineInfo) != NULL) {
            RTICdrType_printArray(
                MONITORING::lineDetailsSeq_get_contiguous_bufferI(&sample->lineInfo), 
                MONITORING::lineDetailsSeq_get_length(&sample->lineInfo),
                sizeof(MONITORING::lineDetails),
                (RTICdrTypePrintFunction)MONITORING::lineDetailsPluginSupport_print_data,
                "lineInfo", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                MONITORING::lineDetailsSeq_get_discontiguous_bufferI(&sample->lineInfo), 
                MONITORING::lineDetailsSeq_get_length(&sample->lineInfo),
                (RTICdrTypePrintFunction)MONITORING::lineDetailsPluginSupport_print_data,
                "lineInfo", indent_level + 1);
        }
    
    }
            

}

pslInfo *
pslInfoPluginSupport_create_key_ex(RTIBool allocate_pointers){
    pslInfo *key = NULL;

    RTIOsapiHeap_allocateStructure(
        &key, pslInfoKeyHolder);

    ::MONITORING::pslInfo_initialize_ex(key,allocate_pointers);
    return key;
}


pslInfo *
pslInfoPluginSupport_create_key(void)
{
    return  ::MONITORING::pslInfoPluginSupport_create_key_ex(RTI_TRUE);
}


void 
pslInfoPluginSupport_destroy_key_ex(
    pslInfoKeyHolder *key,RTIBool deallocate_pointers)
{
    ::MONITORING::pslInfo_finalize_ex(key,deallocate_pointers);

    RTIOsapiHeap_freeStructure(key);
}


void 
pslInfoPluginSupport_destroy_key(
    pslInfoKeyHolder *key) {

  ::MONITORING::pslInfoPluginSupport_destroy_key_ex(key,RTI_TRUE);

}



/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */



PRESTypePluginParticipantData 
pslInfoPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */
    return PRESTypePluginDefaultParticipantData_new(participant_info);

}


void 
pslInfoPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

  PRESTypePluginDefaultParticipantData_delete(participant_data);
}


PRESTypePluginEndpointData
pslInfoPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    unsigned int serializedKeyMaxSize;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */


    epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            ::MONITORING::pslInfoPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            ::MONITORING::pslInfoPluginSupport_destroy_data,
            (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
            ::MONITORING::pslInfoPluginSupport_create_key,
            (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
            ::MONITORING::pslInfoPluginSupport_destroy_key);

    if (epd == NULL) {
        return NULL;
    }
   
    serializedKeyMaxSize = ::MONITORING::pslInfoPlugin_get_serialized_key_max_size(
        epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
    
    if (!PRESTypePluginDefaultEndpointData_createMD5Stream(
            epd,serializedKeyMaxSize)) 
    {
        PRESTypePluginDefaultEndpointData_delete(epd);
        return NULL;
    }

    
    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                ::MONITORING::pslInfoPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            ::MONITORING::pslInfoPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }
    


    return epd;    
}


void 
pslInfoPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}


RTIBool 
pslInfoPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    pslInfo *dst,
    const pslInfo *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return ::MONITORING::pslInfoPluginSupport_copy_data(dst,src);
}

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */


RTIBool 
pslInfoPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const pslInfo *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;


  if (endpoint_data) {} /* To avoid warnings */
  if (endpoint_plugin_qos) {} /* To avoid warnings */


  if(serialize_encapsulation) {

    if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
        return RTI_FALSE;
    }

    position = RTICdrStream_resetAlignment(stream);

  }

  if(serialize_sample) {

    if (!RTICdrStream_serializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeString(
        stream, sample->processInfo, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeString(
        stream, sample->spaceInfo, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeString(
        stream, sample->cancelOrderStatus, (512) + 1)) {
        return RTI_FALSE;
    }
            
    if (MONITORING::lineDetailsSeq_get_contiguous_bufferI(&sample->lineInfo) != NULL) {
        if (!RTICdrStream_serializeNonPrimitiveSequence(
            stream,
            MONITORING::lineDetailsSeq_get_contiguous_bufferI(&sample->lineInfo),
            MONITORING::lineDetailsSeq_get_length(&sample->lineInfo),
            (12),
            sizeof(MONITORING::lineDetails),
            (RTICdrStreamSerializeFunction)MONITORING::lineDetailsPlugin_serialize,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializeNonPrimitivePointerSequence(
            stream,
            (const void **)MONITORING::lineDetailsSeq_get_discontiguous_bufferI(&sample->lineInfo),
            MONITORING::lineDetailsSeq_get_length(&sample->lineInfo),
            (12),
            (RTICdrStreamSerializeFunction)MONITORING::lineDetailsPlugin_serialize,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }
            
  }

  if(serialize_encapsulation) {
    RTICdrStream_restoreAlignment(stream,position);
  }


  return retval;
}


RTIBool 
pslInfoPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    pslInfo *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }
    
    if(deserialize_sample) {


    if (!RTICdrStream_deserializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->processInfo, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->spaceInfo, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->cancelOrderStatus, (512) + 1)) {
        return RTI_FALSE;
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::lineDetailsSeq_get_contiguous_bufferI(&sample->lineInfo) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::lineDetailsSeq_get_contiguous_bufferI(&sample->lineInfo),
                &sequence_length,
                MONITORING::lineDetailsSeq_get_maximum(&sample->lineInfo),
                sizeof(MONITORING::lineDetails),
                (RTICdrStreamDeserializeFunction)MONITORING::lineDetailsPlugin_deserialize_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::lineDetailsSeq_get_discontiguous_bufferI(&sample->lineInfo),
                &sequence_length,
                MONITORING::lineDetailsSeq_get_maximum(&sample->lineInfo),
                (RTICdrStreamDeserializeFunction)MONITORING::lineDetailsPlugin_deserialize_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::lineDetailsSeq_set_length(
            &sample->lineInfo, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}

 
 
RTIBool 
pslInfoPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    pslInfo **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    if (drop_sample) {} /* To avoid warnings */

    return ::MONITORING::pslInfoPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
 
}



RTIBool pslInfoPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (skip_sample) {

    if (!RTICdrStream_skipString(stream, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipString(stream, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipString(stream, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipString(stream, (512) + 1)) {
        return RTI_FALSE;
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipNonPrimitiveSequence(
            stream,
            &sequence_length,
            sizeof(MONITORING::lineDetails),
            (RTICdrStreamSkipFunction)MONITORING::lineDetailsPlugin_skip,
            RTI_FALSE,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }
            
    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int 
pslInfoPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (16) + 1);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (1024) + 1);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (1024) + 1);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (512) + 1);
            
    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (12),
        MONITORING::lineDetailsPlugin_get_serialized_sample_max_size,RTI_FALSE,encapsulation_id,endpoint_data);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


unsigned int 
pslInfoPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
            
    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0,
        MONITORING::lineDetailsPlugin_get_serialized_sample_min_size,RTI_FALSE,encapsulation_id,endpoint_data);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


/* Returns the size of the sample in its serialized form (in bytes).
 * It can also be an estimation in excess of the real buffer needed 
 * during a call to the serialize() function.
 * The value reported does not have to include the space for the
 * encapsulation flags.
 */
unsigned int
pslInfoPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const pslInfo * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (sample) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment += RTICdrType_getStringSerializedSize(
        current_alignment, sample->ipadress);
            
    current_alignment += RTICdrType_getStringSerializedSize(
        current_alignment, sample->processInfo);
            
    current_alignment += RTICdrType_getStringSerializedSize(
        current_alignment, sample->spaceInfo);
            
    current_alignment += RTICdrType_getStringSerializedSize(
        current_alignment, sample->cancelOrderStatus);
            
    if (MONITORING::lineDetailsSeq_get_contiguous_bufferI(&sample->lineInfo) != NULL) {
        current_alignment += RTICdrStream_getNonPrimitiveSequenceSerializedSize(
            current_alignment, MONITORING::lineDetailsSeq_get_length(&sample->lineInfo),
            sizeof(MONITORING::lineDetails),
            (RTICdrTypeGetSerializedSampleSizeFunction)MONITORING::lineDetailsPlugin_get_serialized_sample_size,
            RTI_FALSE,encapsulation_id,
            MONITORING::lineDetailsSeq_get_contiguous_bufferI(&sample->lineInfo),
            endpoint_data);
    } else {
        current_alignment += RTICdrStream_getNonPrimitivePointerSequenceSerializedSize(
            current_alignment, MONITORING::lineDetailsSeq_get_length(&sample->lineInfo),
            sizeof(MONITORING::lineDetails),
            (RTICdrTypeGetSerializedSampleSizeFunction)MONITORING::lineDetailsPlugin_get_serialized_sample_size,
            RTI_FALSE,encapsulation_id,
            (const void **)MONITORING::lineDetailsSeq_get_discontiguous_bufferI(&sample->lineInfo),
            endpoint_data);
    }
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */


PRESTypePluginKeyKind 
pslInfoPlugin_get_key_kind(void)
{

    return PRES_TYPEPLUGIN_USER_KEY;
     
}


RTIBool 
pslInfoPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const pslInfo *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_key) {

    if (!RTICdrStream_serializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeString(
        stream, sample->processInfo, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeString(
        stream, sample->spaceInfo, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeString(
        stream, sample->cancelOrderStatus, (512) + 1)) {
        return RTI_FALSE;
    }
            
    if (MONITORING::lineDetailsSeq_get_contiguous_bufferI(&sample->lineInfo) != NULL) {
        if (!RTICdrStream_serializeNonPrimitiveSequence(
            stream,
            MONITORING::lineDetailsSeq_get_contiguous_bufferI(&sample->lineInfo),
            MONITORING::lineDetailsSeq_get_length(&sample->lineInfo),
            (12),
            sizeof(MONITORING::lineDetails),
            (RTICdrStreamSerializeFunction)MONITORING::lineDetailsPlugin_serialize_key,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializeNonPrimitivePointerSequence(
            stream,
            (const void **)MONITORING::lineDetailsSeq_get_discontiguous_bufferI(&sample->lineInfo),
            MONITORING::lineDetailsSeq_get_length(&sample->lineInfo),
            (12),
            (RTICdrStreamSerializeFunction)MONITORING::lineDetailsPlugin_serialize_key,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }
            
    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool pslInfoPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    pslInfo *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;  
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->processInfo, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->spaceInfo, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->cancelOrderStatus, (512) + 1)) {
        return RTI_FALSE;
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::lineDetailsSeq_get_contiguous_bufferI(&sample->lineInfo) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::lineDetailsSeq_get_contiguous_bufferI(&sample->lineInfo),
                &sequence_length,
                MONITORING::lineDetailsSeq_get_maximum(&sample->lineInfo),
                sizeof(MONITORING::lineDetails),
                (RTICdrStreamDeserializeFunction)MONITORING::lineDetailsPlugin_deserialize_key_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::lineDetailsSeq_get_discontiguous_bufferI(&sample->lineInfo),
                &sequence_length,
                MONITORING::lineDetailsSeq_get_maximum(&sample->lineInfo),
                (RTICdrStreamDeserializeFunction)MONITORING::lineDetailsPlugin_deserialize_key_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::lineDetailsSeq_set_length(
            &sample->lineInfo, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


 
RTIBool pslInfoPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    pslInfo **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    if (drop_sample) {} /* To avoid warnings */
    return ::MONITORING::pslInfoPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
}



unsigned int
pslInfoPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int encapsulation_size = current_alignment;


    unsigned int initial_alignment = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
        

    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (16) + 1);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (1024) + 1);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (1024) + 1);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (512) + 1);
            
    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (12),
        MONITORING::lineDetailsPlugin_get_serialized_key_max_size,RTI_FALSE,encapsulation_id,endpoint_data);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


RTIBool 
pslInfoPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    pslInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->processInfo, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->spaceInfo, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->cancelOrderStatus, (512) + 1)) {
        return RTI_FALSE;
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::lineDetailsSeq_get_contiguous_bufferI(&sample->lineInfo) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::lineDetailsSeq_get_contiguous_bufferI(&sample->lineInfo),
                &sequence_length,
                MONITORING::lineDetailsSeq_get_maximum(&sample->lineInfo),
                sizeof(MONITORING::lineDetails),
                (RTICdrStreamDeserializeFunction)MONITORING::lineDetailsPlugin_serialized_sample_to_key,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::lineDetailsSeq_get_discontiguous_bufferI(&sample->lineInfo),
                &sequence_length,
                MONITORING::lineDetailsSeq_get_maximum(&sample->lineInfo),
                (RTICdrStreamDeserializeFunction)MONITORING::lineDetailsPlugin_serialized_sample_to_key,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::lineDetailsSeq_set_length(
            &sample->lineInfo, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}





RTIBool 
pslInfoPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    pslInfoKeyHolder *dst, 
    const pslInfo *src)
{  

    if (endpoint_data) {} /* To avoid warnings */

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


RTIBool 
pslInfoPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    pslInfo *dst, const
    pslInfoKeyHolder *src)
{

    if (endpoint_data) {} /* To avoid warnings */

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


RTIBool 
pslInfoPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const pslInfo *instance)
{
    struct RTICdrStream * md5Stream = NULL;

    md5Stream = PRESTypePluginDefaultEndpointData_getMD5Stream(endpoint_data);

    if (md5Stream == NULL) {
        return RTI_FALSE;
    }

    RTIOsapiMemory_zero(
        RTICdrStream_getBuffer(md5Stream),
        RTICdrStream_getBufferLength(md5Stream));
    RTICdrStream_resetPosition(md5Stream);
    RTICdrStream_setDirtyBit(md5Stream, RTI_TRUE);

    if (!::MONITORING::pslInfoPlugin_serialize_key(
            endpoint_data,instance,md5Stream, RTI_FALSE, RTI_CDR_ENCAPSULATION_ID_CDR_BE, RTI_TRUE,NULL)) {
        return RTI_FALSE;
    }
    
    if (PRESTypePluginDefaultEndpointData_getMaxSizeSerializedKey(endpoint_data) > (unsigned int)(MIG_RTPS_KEY_HASH_MAX_LENGTH)) {
        RTICdrStream_computeMD5(md5Stream, keyhash->value);
    } else {
        RTIOsapiMemory_zero(keyhash->value,MIG_RTPS_KEY_HASH_MAX_LENGTH);
        RTIOsapiMemory_copy(
            keyhash->value, 
            RTICdrStream_getBuffer(md5Stream), 
            RTICdrStream_getCurrentPositionOffset(md5Stream));
    }

    keyhash->length = MIG_RTPS_KEY_HASH_MAX_LENGTH;
    return RTI_TRUE;
}


RTIBool 
pslInfoPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos) 
{   
    char * position = NULL;
    pslInfo * sample;

    if (endpoint_plugin_qos) {} /* To avoid warnings */



    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }


    sample = (pslInfo *)
                PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);

    if (sample == NULL) {
        return RTI_FALSE;
    }


    if (!RTICdrStream_deserializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->processInfo, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->spaceInfo, (1024) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->cancelOrderStatus, (512) + 1)) {
        return RTI_FALSE;
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::lineDetailsSeq_get_contiguous_bufferI(&sample->lineInfo) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::lineDetailsSeq_get_contiguous_bufferI(&sample->lineInfo),
                &sequence_length,
                MONITORING::lineDetailsSeq_get_maximum(&sample->lineInfo),
                sizeof(MONITORING::lineDetails),
                (RTICdrStreamDeserializeFunction)MONITORING::lineDetailsPlugin_serialized_sample_to_key,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::lineDetailsSeq_get_discontiguous_bufferI(&sample->lineInfo),
                &sequence_length,
                MONITORING::lineDetailsSeq_get_maximum(&sample->lineInfo),
                (RTICdrStreamDeserializeFunction)MONITORING::lineDetailsPlugin_serialized_sample_to_key,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::lineDetailsSeq_set_length(
            &sample->lineInfo, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    if (!::MONITORING::pslInfoPlugin_instance_to_keyhash(
            endpoint_data, keyhash, sample)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}


/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */
 
struct PRESTypePlugin *pslInfoPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
       return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        ::MONITORING::pslInfoPlugin_on_participant_attached;
    plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        ::MONITORING::pslInfoPlugin_on_participant_detached;
    plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        ::MONITORING::pslInfoPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        ::MONITORING::pslInfoPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        ::MONITORING::pslInfoPlugin_copy_sample;
    plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        pslInfoPlugin_create_sample;
    plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        pslInfoPlugin_destroy_sample;

    plugin->serializeFnc =
        (PRESTypePluginSerializeFunction)
        ::MONITORING::pslInfoPlugin_serialize;
    plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction)
        ::MONITORING::pslInfoPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        ::MONITORING::pslInfoPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        ::MONITORING::pslInfoPlugin_get_serialized_sample_min_size;


    plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        pslInfoPlugin_get_sample;
    plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        pslInfoPlugin_return_sample;

    plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        ::MONITORING::pslInfoPlugin_get_key_kind;


    plugin->getSerializedKeyMaxSizeFnc =   
        (PRESTypePluginGetSerializedKeyMaxSizeFunction)
        ::MONITORING::pslInfoPlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
        (PRESTypePluginSerializeKeyFunction)
        ::MONITORING::pslInfoPlugin_serialize_key;
    plugin->deserializeKeyFnc =
        (PRESTypePluginDeserializeKeyFunction)
        ::MONITORING::pslInfoPlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
        (PRESTypePluginDeserializeKeySampleFunction)
        ::MONITORING::pslInfoPlugin_deserialize_key_sample;

    plugin->instanceToKeyHashFnc = 
        (PRESTypePluginInstanceToKeyHashFunction)
        ::MONITORING::pslInfoPlugin_instance_to_keyhash;
    plugin->serializedSampleToKeyHashFnc = 
        (PRESTypePluginSerializedSampleToKeyHashFunction)
        ::MONITORING::pslInfoPlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
        (PRESTypePluginGetKeyFunction)
        pslInfoPlugin_get_key;
    plugin->returnKeyFnc =
        (PRESTypePluginReturnKeyFunction)
        pslInfoPlugin_return_key;

    plugin->instanceToKeyFnc =
        (PRESTypePluginInstanceToKeyFunction)
        ::MONITORING::pslInfoPlugin_instance_to_key;
    plugin->keyToInstanceFnc =
        (PRESTypePluginKeyToInstanceFunction)
        ::MONITORING::pslInfoPlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    
    plugin->typeCode =  (struct RTICdrTypeCode *)::MONITORING::pslInfo_get_typecode();
    
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

    /* Serialized buffer */
    plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        pslInfoPlugin_get_buffer;
    plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        pslInfoPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        ::MONITORING::pslInfoPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = pslInfoTYPENAME;

    return plugin;
}

void
pslInfoPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* --------------------------------------------------------------------------------------
 *  Type ipSequence
 * -------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

ipSequence *
ipSequencePluginSupport_create_data_ex(RTIBool allocate_pointers){
    ipSequence *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, ipSequence);

    if(sample != NULL) {
        if (!::MONITORING::ipSequence_initialize_ex(sample,allocate_pointers)) {
            RTIOsapiHeap_freeStructure(&sample);
            return NULL;
        }
    }
    return sample; 
}


ipSequence *
ipSequencePluginSupport_create_data(void)
{
    return ::MONITORING::ipSequencePluginSupport_create_data_ex(RTI_TRUE);
}


void 
ipSequencePluginSupport_destroy_data_ex(
    ipSequence *sample,RTIBool deallocate_pointers) {

    ::MONITORING::ipSequence_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}


void 
ipSequencePluginSupport_destroy_data(
    ipSequence *sample) {

    ::MONITORING::ipSequencePluginSupport_destroy_data_ex(sample,RTI_TRUE);

}


RTIBool 
ipSequencePluginSupport_copy_data(
    ipSequence *dst,
    const ipSequence *src)
{
    return ::MONITORING::ipSequence_copy(dst,src);
}


void 
ipSequencePluginSupport_print_data(
    const ipSequence *sample,
    const char *desc,
    unsigned int indent_level)
{


    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
      RTILog_debug("%s:\n", desc);
    } else {
      RTILog_debug("\n");
    }

    if (sample == NULL) {
      RTILog_debug("NULL\n");
      return;
    }


    if (&sample->ipadress==NULL) {
        RTICdrType_printString(
            NULL, "ipadress", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->ipadress, "ipadress", indent_level + 1);                
    }
            
    MONITORING::eStatePluginSupport_print_data(
        &sample->status, "status", indent_level + 1);
            
    RTICdrType_printLong(
        &sample->CancelOrderId, "CancelOrderId", indent_level + 1);
            
    if (&sample->psl==NULL) {
        RTICdrType_printString(
            NULL, "psl", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->psl, "psl", indent_level + 1);                
    }
            

}

ipSequence *
ipSequencePluginSupport_create_key_ex(RTIBool allocate_pointers){
    ipSequence *key = NULL;

    RTIOsapiHeap_allocateStructure(
        &key, ipSequenceKeyHolder);

    ::MONITORING::ipSequence_initialize_ex(key,allocate_pointers);
    return key;
}


ipSequence *
ipSequencePluginSupport_create_key(void)
{
    return  ::MONITORING::ipSequencePluginSupport_create_key_ex(RTI_TRUE);
}


void 
ipSequencePluginSupport_destroy_key_ex(
    ipSequenceKeyHolder *key,RTIBool deallocate_pointers)
{
    ::MONITORING::ipSequence_finalize_ex(key,deallocate_pointers);

    RTIOsapiHeap_freeStructure(key);
}


void 
ipSequencePluginSupport_destroy_key(
    ipSequenceKeyHolder *key) {

  ::MONITORING::ipSequencePluginSupport_destroy_key_ex(key,RTI_TRUE);

}



/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */



PRESTypePluginParticipantData 
ipSequencePlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */
    return PRESTypePluginDefaultParticipantData_new(participant_info);

}


void 
ipSequencePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

  PRESTypePluginDefaultParticipantData_delete(participant_data);
}


PRESTypePluginEndpointData
ipSequencePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    unsigned int serializedKeyMaxSize;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */


    epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            ::MONITORING::ipSequencePluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            ::MONITORING::ipSequencePluginSupport_destroy_data,
            (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
            ::MONITORING::ipSequencePluginSupport_create_key,
            (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
            ::MONITORING::ipSequencePluginSupport_destroy_key);

    if (epd == NULL) {
        return NULL;
    }
   
    serializedKeyMaxSize = ::MONITORING::ipSequencePlugin_get_serialized_key_max_size(
        epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
    
    if (!PRESTypePluginDefaultEndpointData_createMD5Stream(
            epd,serializedKeyMaxSize)) 
    {
        PRESTypePluginDefaultEndpointData_delete(epd);
        return NULL;
    }

    
    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                ::MONITORING::ipSequencePlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            ::MONITORING::ipSequencePlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }
    


    return epd;    
}


void 
ipSequencePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}


RTIBool 
ipSequencePlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ipSequence *dst,
    const ipSequence *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return ::MONITORING::ipSequencePluginSupport_copy_data(dst,src);
}

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */


RTIBool 
ipSequencePlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const ipSequence *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;


  if (endpoint_data) {} /* To avoid warnings */
  if (endpoint_plugin_qos) {} /* To avoid warnings */


  if(serialize_encapsulation) {

    if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
        return RTI_FALSE;
    }

    position = RTICdrStream_resetAlignment(stream);

  }

  if(serialize_sample) {

    if (!RTICdrStream_serializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eStatePlugin_serialize(
            endpoint_data,
            &sample->status, 
            stream, 
            RTI_FALSE, encapsulation_id, 
            RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeLong(
        stream, &sample->CancelOrderId)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeString(
        stream, sample->psl, (20) + 1)) {
        return RTI_FALSE;
    }
            
  }

  if(serialize_encapsulation) {
    RTICdrStream_restoreAlignment(stream,position);
  }


  return retval;
}


RTIBool 
ipSequencePlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    ipSequence *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }
    
    if(deserialize_sample) {


    if (!RTICdrStream_deserializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eStatePlugin_deserialize_sample(
            endpoint_data,
            &sample->status,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeLong(
        stream, &sample->CancelOrderId)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->psl, (20) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}

 
 
RTIBool 
ipSequencePlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ipSequence **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    if (drop_sample) {} /* To avoid warnings */

    return ::MONITORING::ipSequencePlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
 
}



RTIBool ipSequencePlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (skip_sample) {

    if (!RTICdrStream_skipString(stream, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eStatePlugin_skip(
            endpoint_data,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipLong(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipString(stream, (20) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int 
ipSequencePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (16) + 1);
            
    current_alignment +=  MONITORING::eStatePlugin_get_serialized_sample_max_size(
        endpoint_data,RTI_FALSE,encapsulation_id,current_alignment);
            
    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (20) + 1);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


unsigned int 
ipSequencePlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
            
    current_alignment +=  MONITORING::eStatePlugin_get_serialized_sample_min_size(
        endpoint_data,RTI_FALSE,encapsulation_id,current_alignment);
            
    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


/* Returns the size of the sample in its serialized form (in bytes).
 * It can also be an estimation in excess of the real buffer needed 
 * during a call to the serialize() function.
 * The value reported does not have to include the space for the
 * encapsulation flags.
 */
unsigned int
ipSequencePlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const ipSequence * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (sample) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment += RTICdrType_getStringSerializedSize(
        current_alignment, sample->ipadress);
            
    current_alignment += MONITORING::eStatePlugin_get_serialized_sample_size(
        endpoint_data,RTI_FALSE, encapsulation_id, 
        current_alignment, &sample->status);
            
    current_alignment += RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment += RTICdrType_getStringSerializedSize(
        current_alignment, sample->psl);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */


PRESTypePluginKeyKind 
ipSequencePlugin_get_key_kind(void)
{

    return PRES_TYPEPLUGIN_USER_KEY;
     
}


RTIBool 
ipSequencePlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const ipSequence *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_key) {

    if (!RTICdrStream_serializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool ipSequencePlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    ipSequence *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;  
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


 
RTIBool ipSequencePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ipSequence **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    if (drop_sample) {} /* To avoid warnings */
    return ::MONITORING::ipSequencePlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
}



unsigned int
ipSequencePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int encapsulation_size = current_alignment;


    unsigned int initial_alignment = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
        

    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (16) + 1);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


RTIBool 
ipSequencePlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ipSequence *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eStatePlugin_skip(
            endpoint_data,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipLong(stream)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipString(stream, (20) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}





RTIBool 
ipSequencePlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ipSequenceKeyHolder *dst, 
    const ipSequence *src)
{  

    if (endpoint_data) {} /* To avoid warnings */

    if (!RTICdrType_copyString(
        dst->ipadress, src->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool 
ipSequencePlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    ipSequence *dst, const
    ipSequenceKeyHolder *src)
{

    if (endpoint_data) {} /* To avoid warnings */

    if (!RTICdrType_copyString(
        dst->ipadress, src->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool 
ipSequencePlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const ipSequence *instance)
{
    struct RTICdrStream * md5Stream = NULL;

    md5Stream = PRESTypePluginDefaultEndpointData_getMD5Stream(endpoint_data);

    if (md5Stream == NULL) {
        return RTI_FALSE;
    }

    RTIOsapiMemory_zero(
        RTICdrStream_getBuffer(md5Stream),
        RTICdrStream_getBufferLength(md5Stream));
    RTICdrStream_resetPosition(md5Stream);
    RTICdrStream_setDirtyBit(md5Stream, RTI_TRUE);

    if (!::MONITORING::ipSequencePlugin_serialize_key(
            endpoint_data,instance,md5Stream, RTI_FALSE, RTI_CDR_ENCAPSULATION_ID_CDR_BE, RTI_TRUE,NULL)) {
        return RTI_FALSE;
    }
    
    if (PRESTypePluginDefaultEndpointData_getMaxSizeSerializedKey(endpoint_data) > (unsigned int)(MIG_RTPS_KEY_HASH_MAX_LENGTH)) {
        RTICdrStream_computeMD5(md5Stream, keyhash->value);
    } else {
        RTIOsapiMemory_zero(keyhash->value,MIG_RTPS_KEY_HASH_MAX_LENGTH);
        RTIOsapiMemory_copy(
            keyhash->value, 
            RTICdrStream_getBuffer(md5Stream), 
            RTICdrStream_getCurrentPositionOffset(md5Stream));
    }

    keyhash->length = MIG_RTPS_KEY_HASH_MAX_LENGTH;
    return RTI_TRUE;
}


RTIBool 
ipSequencePlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos) 
{   
    char * position = NULL;
    ipSequence * sample;

    if (endpoint_plugin_qos) {} /* To avoid warnings */



    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }


    sample = (ipSequence *)
                PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);

    if (sample == NULL) {
        return RTI_FALSE;
    }


    if (!RTICdrStream_deserializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    if (!::MONITORING::ipSequencePlugin_instance_to_keyhash(
            endpoint_data, keyhash, sample)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}


/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */
 
struct PRESTypePlugin *ipSequencePlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
       return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        ::MONITORING::ipSequencePlugin_on_participant_attached;
    plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        ::MONITORING::ipSequencePlugin_on_participant_detached;
    plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        ::MONITORING::ipSequencePlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        ::MONITORING::ipSequencePlugin_on_endpoint_detached;

    plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        ::MONITORING::ipSequencePlugin_copy_sample;
    plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        ipSequencePlugin_create_sample;
    plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        ipSequencePlugin_destroy_sample;

    plugin->serializeFnc =
        (PRESTypePluginSerializeFunction)
        ::MONITORING::ipSequencePlugin_serialize;
    plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction)
        ::MONITORING::ipSequencePlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        ::MONITORING::ipSequencePlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        ::MONITORING::ipSequencePlugin_get_serialized_sample_min_size;


    plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        ipSequencePlugin_get_sample;
    plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        ipSequencePlugin_return_sample;

    plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        ::MONITORING::ipSequencePlugin_get_key_kind;


    plugin->getSerializedKeyMaxSizeFnc =   
        (PRESTypePluginGetSerializedKeyMaxSizeFunction)
        ::MONITORING::ipSequencePlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
        (PRESTypePluginSerializeKeyFunction)
        ::MONITORING::ipSequencePlugin_serialize_key;
    plugin->deserializeKeyFnc =
        (PRESTypePluginDeserializeKeyFunction)
        ::MONITORING::ipSequencePlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
        (PRESTypePluginDeserializeKeySampleFunction)
        ::MONITORING::ipSequencePlugin_deserialize_key_sample;

    plugin->instanceToKeyHashFnc = 
        (PRESTypePluginInstanceToKeyHashFunction)
        ::MONITORING::ipSequencePlugin_instance_to_keyhash;
    plugin->serializedSampleToKeyHashFnc = 
        (PRESTypePluginSerializedSampleToKeyHashFunction)
        ::MONITORING::ipSequencePlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
        (PRESTypePluginGetKeyFunction)
        ipSequencePlugin_get_key;
    plugin->returnKeyFnc =
        (PRESTypePluginReturnKeyFunction)
        ipSequencePlugin_return_key;

    plugin->instanceToKeyFnc =
        (PRESTypePluginInstanceToKeyFunction)
        ::MONITORING::ipSequencePlugin_instance_to_key;
    plugin->keyToInstanceFnc =
        (PRESTypePluginKeyToInstanceFunction)
        ::MONITORING::ipSequencePlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    
    plugin->typeCode =  (struct RTICdrTypeCode *)::MONITORING::ipSequence_get_typecode();
    
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

    /* Serialized buffer */
    plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        ipSequencePlugin_get_buffer;
    plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        ipSequencePlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        ::MONITORING::ipSequencePlugin_get_serialized_sample_size;

    plugin->endpointTypeName = ipSequenceTYPENAME;

    return plugin;
}

void
ipSequencePlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* --------------------------------------------------------------------------------------
 *  Type leaseProcessStart
 * -------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

leaseProcessStart *
leaseProcessStartPluginSupport_create_data_ex(RTIBool allocate_pointers){
    leaseProcessStart *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, leaseProcessStart);

    if(sample != NULL) {
        if (!::MONITORING::leaseProcessStart_initialize_ex(sample,allocate_pointers)) {
            RTIOsapiHeap_freeStructure(&sample);
            return NULL;
        }
    }
    return sample; 
}


leaseProcessStart *
leaseProcessStartPluginSupport_create_data(void)
{
    return ::MONITORING::leaseProcessStartPluginSupport_create_data_ex(RTI_TRUE);
}


void 
leaseProcessStartPluginSupport_destroy_data_ex(
    leaseProcessStart *sample,RTIBool deallocate_pointers) {

    ::MONITORING::leaseProcessStart_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}


void 
leaseProcessStartPluginSupport_destroy_data(
    leaseProcessStart *sample) {

    ::MONITORING::leaseProcessStartPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}


RTIBool 
leaseProcessStartPluginSupport_copy_data(
    leaseProcessStart *dst,
    const leaseProcessStart *src)
{
    return ::MONITORING::leaseProcessStart_copy(dst,src);
}


void 
leaseProcessStartPluginSupport_print_data(
    const leaseProcessStart *sample,
    const char *desc,
    unsigned int indent_level)
{


    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
      RTILog_debug("%s:\n", desc);
    } else {
      RTILog_debug("\n");
    }

    if (sample == NULL) {
      RTILog_debug("NULL\n");
      return;
    }


    if (&sample->ip_info == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("ip_info: NULL\n");    
    } else {
                
        if (MONITORING::ipSequenceSeq_get_contiguous_bufferI(&sample->ip_info) != NULL) {
            RTICdrType_printArray(
                MONITORING::ipSequenceSeq_get_contiguous_bufferI(&sample->ip_info), 
                MONITORING::ipSequenceSeq_get_length(&sample->ip_info),
                sizeof(MONITORING::ipSequence),
                (RTICdrTypePrintFunction)MONITORING::ipSequencePluginSupport_print_data,
                "ip_info", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                MONITORING::ipSequenceSeq_get_discontiguous_bufferI(&sample->ip_info), 
                MONITORING::ipSequenceSeq_get_length(&sample->ip_info),
                (RTICdrTypePrintFunction)MONITORING::ipSequencePluginSupport_print_data,
                "ip_info", indent_level + 1);
        }
    
    }
            

}



/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */



PRESTypePluginParticipantData 
leaseProcessStartPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */
    return PRESTypePluginDefaultParticipantData_new(participant_info);

}


void 
leaseProcessStartPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

  PRESTypePluginDefaultParticipantData_delete(participant_data);
}


PRESTypePluginEndpointData
leaseProcessStartPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

   if (top_level_registration) {} /* To avoid warnings */
   if (containerPluginContext) {} /* To avoid warnings */

    epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            ::MONITORING::leaseProcessStartPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            ::MONITORING::leaseProcessStartPluginSupport_destroy_data,
            NULL, NULL);

    if (epd == NULL) {
        return NULL;
    }

    
    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                ::MONITORING::leaseProcessStartPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            ::MONITORING::leaseProcessStartPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }
    


    return epd;    
}


void 
leaseProcessStartPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}


RTIBool 
leaseProcessStartPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    leaseProcessStart *dst,
    const leaseProcessStart *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return ::MONITORING::leaseProcessStartPluginSupport_copy_data(dst,src);
}

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */


RTIBool 
leaseProcessStartPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const leaseProcessStart *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;


  if (endpoint_data) {} /* To avoid warnings */
  if (endpoint_plugin_qos) {} /* To avoid warnings */


  if(serialize_encapsulation) {

    if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
        return RTI_FALSE;
    }

    position = RTICdrStream_resetAlignment(stream);

  }

  if(serialize_sample) {

    if (MONITORING::ipSequenceSeq_get_contiguous_bufferI(&sample->ip_info) != NULL) {
        if (!RTICdrStream_serializeNonPrimitiveSequence(
            stream,
            MONITORING::ipSequenceSeq_get_contiguous_bufferI(&sample->ip_info),
            MONITORING::ipSequenceSeq_get_length(&sample->ip_info),
            (12),
            sizeof(MONITORING::ipSequence),
            (RTICdrStreamSerializeFunction)MONITORING::ipSequencePlugin_serialize,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializeNonPrimitivePointerSequence(
            stream,
            (const void **)MONITORING::ipSequenceSeq_get_discontiguous_bufferI(&sample->ip_info),
            MONITORING::ipSequenceSeq_get_length(&sample->ip_info),
            (12),
            (RTICdrStreamSerializeFunction)MONITORING::ipSequencePlugin_serialize,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }
            
  }

  if(serialize_encapsulation) {
    RTICdrStream_restoreAlignment(stream,position);
  }


  return retval;
}


RTIBool 
leaseProcessStartPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    leaseProcessStart *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }
    
    if(deserialize_sample) {


    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::ipSequenceSeq_get_contiguous_bufferI(&sample->ip_info) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::ipSequenceSeq_get_contiguous_bufferI(&sample->ip_info),
                &sequence_length,
                MONITORING::ipSequenceSeq_get_maximum(&sample->ip_info),
                sizeof(MONITORING::ipSequence),
                (RTICdrStreamDeserializeFunction)MONITORING::ipSequencePlugin_deserialize_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::ipSequenceSeq_get_discontiguous_bufferI(&sample->ip_info),
                &sequence_length,
                MONITORING::ipSequenceSeq_get_maximum(&sample->ip_info),
                (RTICdrStreamDeserializeFunction)MONITORING::ipSequencePlugin_deserialize_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::ipSequenceSeq_set_length(
            &sample->ip_info, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}

 
 
RTIBool 
leaseProcessStartPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    leaseProcessStart **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    if (drop_sample) {} /* To avoid warnings */

    return ::MONITORING::leaseProcessStartPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
 
}



RTIBool leaseProcessStartPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (skip_sample) {

    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipNonPrimitiveSequence(
            stream,
            &sequence_length,
            sizeof(MONITORING::ipSequence),
            (RTICdrStreamSkipFunction)MONITORING::ipSequencePlugin_skip,
            RTI_FALSE,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }
            
    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int 
leaseProcessStartPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, (12),
        MONITORING::ipSequencePlugin_get_serialized_sample_max_size,RTI_FALSE,encapsulation_id,endpoint_data);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


unsigned int 
leaseProcessStartPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0,
        MONITORING::ipSequencePlugin_get_serialized_sample_min_size,RTI_FALSE,encapsulation_id,endpoint_data);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


/* Returns the size of the sample in its serialized form (in bytes).
 * It can also be an estimation in excess of the real buffer needed 
 * during a call to the serialize() function.
 * The value reported does not have to include the space for the
 * encapsulation flags.
 */
unsigned int
leaseProcessStartPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const leaseProcessStart * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (sample) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    if (MONITORING::ipSequenceSeq_get_contiguous_bufferI(&sample->ip_info) != NULL) {
        current_alignment += RTICdrStream_getNonPrimitiveSequenceSerializedSize(
            current_alignment, MONITORING::ipSequenceSeq_get_length(&sample->ip_info),
            sizeof(MONITORING::ipSequence),
            (RTICdrTypeGetSerializedSampleSizeFunction)MONITORING::ipSequencePlugin_get_serialized_sample_size,
            RTI_FALSE,encapsulation_id,
            MONITORING::ipSequenceSeq_get_contiguous_bufferI(&sample->ip_info),
            endpoint_data);
    } else {
        current_alignment += RTICdrStream_getNonPrimitivePointerSequenceSerializedSize(
            current_alignment, MONITORING::ipSequenceSeq_get_length(&sample->ip_info),
            sizeof(MONITORING::ipSequence),
            (RTICdrTypeGetSerializedSampleSizeFunction)MONITORING::ipSequencePlugin_get_serialized_sample_size,
            RTI_FALSE,encapsulation_id,
            (const void **)MONITORING::ipSequenceSeq_get_discontiguous_bufferI(&sample->ip_info),
            endpoint_data);
    }
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */


PRESTypePluginKeyKind 
leaseProcessStartPlugin_get_key_kind(void)
{

    return PRES_TYPEPLUGIN_NO_KEY;
     
}


RTIBool 
leaseProcessStartPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const leaseProcessStart *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_key) {

        if (!::MONITORING::leaseProcessStartPlugin_serialize(
                endpoint_data,
                sample,
                stream,
                RTI_FALSE, encapsulation_id,
                RTI_TRUE,
                endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    
    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool leaseProcessStartPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    leaseProcessStart *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;  
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

        if (!::MONITORING::leaseProcessStartPlugin_deserialize_sample(
                endpoint_data, sample, stream,
                RTI_FALSE, RTI_TRUE, 
                endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


 
RTIBool leaseProcessStartPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    leaseProcessStart **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    if (drop_sample) {} /* To avoid warnings */
    return ::MONITORING::leaseProcessStartPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
}



unsigned int
leaseProcessStartPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int encapsulation_size = current_alignment;


    unsigned int initial_alignment = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
        

    current_alignment += ::MONITORING::leaseProcessStartPlugin_get_serialized_sample_max_size(
        endpoint_data,RTI_FALSE, encapsulation_id, current_alignment);
    
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


RTIBool 
leaseProcessStartPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    leaseProcessStart *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;


    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

        if (!::MONITORING::leaseProcessStartPlugin_deserialize_sample(
            endpoint_data, sample, stream, RTI_FALSE, 
            RTI_TRUE, endpoint_plugin_qos)) {
            return RTI_FALSE;
        }

    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}




/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */
 
struct PRESTypePlugin *leaseProcessStartPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
       return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        ::MONITORING::leaseProcessStartPlugin_on_participant_attached;
    plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        ::MONITORING::leaseProcessStartPlugin_on_participant_detached;
    plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        ::MONITORING::leaseProcessStartPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        ::MONITORING::leaseProcessStartPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        ::MONITORING::leaseProcessStartPlugin_copy_sample;
    plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        leaseProcessStartPlugin_create_sample;
    plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        leaseProcessStartPlugin_destroy_sample;

    plugin->serializeFnc =
        (PRESTypePluginSerializeFunction)
        ::MONITORING::leaseProcessStartPlugin_serialize;
    plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction)
        ::MONITORING::leaseProcessStartPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        ::MONITORING::leaseProcessStartPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        ::MONITORING::leaseProcessStartPlugin_get_serialized_sample_min_size;


    plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        leaseProcessStartPlugin_get_sample;
    plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        leaseProcessStartPlugin_return_sample;

    plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        ::MONITORING::leaseProcessStartPlugin_get_key_kind;

 
    /* These functions are only used for keyed types. As this is not a keyed
    type they are all set to NULL
    */
    plugin->serializeKeyFnc = NULL;
    plugin->deserializeKeyFnc = NULL;
    plugin->getKeyFnc = NULL;
    plugin->returnKeyFnc = NULL;
    plugin->instanceToKeyFnc = NULL;
    plugin->keyToInstanceFnc = NULL;
    plugin->getSerializedKeyMaxSizeFnc = NULL;
    plugin->instanceToKeyHashFnc = NULL;
    plugin->serializedSampleToKeyHashFnc = NULL;
    plugin->serializedKeyToKeyHashFnc = NULL;
    
    plugin->typeCode =  (struct RTICdrTypeCode *)::MONITORING::leaseProcessStart_get_typecode();
    
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

    /* Serialized buffer */
    plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        leaseProcessStartPlugin_get_buffer;
    plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        leaseProcessStartPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        ::MONITORING::leaseProcessStartPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = leaseProcessStartTYPENAME;

    return plugin;
}

void
leaseProcessStartPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* --------------------------------------------------------------------------------------
 *  Type leaseLineInfo
 * -------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

leaseLineInfo *
leaseLineInfoPluginSupport_create_data_ex(RTIBool allocate_pointers){
    leaseLineInfo *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, leaseLineInfo);

    if(sample != NULL) {
        if (!::MONITORING::leaseLineInfo_initialize_ex(sample,allocate_pointers)) {
            RTIOsapiHeap_freeStructure(&sample);
            return NULL;
        }
    }
    return sample; 
}


leaseLineInfo *
leaseLineInfoPluginSupport_create_data(void)
{
    return ::MONITORING::leaseLineInfoPluginSupport_create_data_ex(RTI_TRUE);
}


void 
leaseLineInfoPluginSupport_destroy_data_ex(
    leaseLineInfo *sample,RTIBool deallocate_pointers) {

    ::MONITORING::leaseLineInfo_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}


void 
leaseLineInfoPluginSupport_destroy_data(
    leaseLineInfo *sample) {

    ::MONITORING::leaseLineInfoPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}


RTIBool 
leaseLineInfoPluginSupport_copy_data(
    leaseLineInfo *dst,
    const leaseLineInfo *src)
{
    return ::MONITORING::leaseLineInfo_copy(dst,src);
}


void 
leaseLineInfoPluginSupport_print_data(
    const leaseLineInfo *sample,
    const char *desc,
    unsigned int indent_level)
{


    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
      RTILog_debug("%s:\n", desc);
    } else {
      RTILog_debug("\n");
    }

    if (sample == NULL) {
      RTILog_debug("NULL\n");
      return;
    }


    if (&sample->ipadress==NULL) {
        RTICdrType_printString(
            NULL, "ipadress", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->ipadress, "ipadress", indent_level + 1);                
    }
            
    RTICdrType_printLong(
        &sample->lineId, "lineId", indent_level + 1);
            
    MONITORING::elinestatusPluginSupport_print_data(
        &sample->status, "status", indent_level + 1);
            
    MONITORING::eLineTypePluginSupport_print_data(
        &sample->linetype, "linetype", indent_level + 1);
            

}

leaseLineInfo *
leaseLineInfoPluginSupport_create_key_ex(RTIBool allocate_pointers){
    leaseLineInfo *key = NULL;

    RTIOsapiHeap_allocateStructure(
        &key, leaseLineInfoKeyHolder);

    ::MONITORING::leaseLineInfo_initialize_ex(key,allocate_pointers);
    return key;
}


leaseLineInfo *
leaseLineInfoPluginSupport_create_key(void)
{
    return  ::MONITORING::leaseLineInfoPluginSupport_create_key_ex(RTI_TRUE);
}


void 
leaseLineInfoPluginSupport_destroy_key_ex(
    leaseLineInfoKeyHolder *key,RTIBool deallocate_pointers)
{
    ::MONITORING::leaseLineInfo_finalize_ex(key,deallocate_pointers);

    RTIOsapiHeap_freeStructure(key);
}


void 
leaseLineInfoPluginSupport_destroy_key(
    leaseLineInfoKeyHolder *key) {

  ::MONITORING::leaseLineInfoPluginSupport_destroy_key_ex(key,RTI_TRUE);

}



/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */



PRESTypePluginParticipantData 
leaseLineInfoPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */
    return PRESTypePluginDefaultParticipantData_new(participant_info);

}


void 
leaseLineInfoPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

  PRESTypePluginDefaultParticipantData_delete(participant_data);
}


PRESTypePluginEndpointData
leaseLineInfoPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    unsigned int serializedKeyMaxSize;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */


    epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            ::MONITORING::leaseLineInfoPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            ::MONITORING::leaseLineInfoPluginSupport_destroy_data,
            (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
            ::MONITORING::leaseLineInfoPluginSupport_create_key,
            (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
            ::MONITORING::leaseLineInfoPluginSupport_destroy_key);

    if (epd == NULL) {
        return NULL;
    }
   
    serializedKeyMaxSize = ::MONITORING::leaseLineInfoPlugin_get_serialized_key_max_size(
        epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
    
    if (!PRESTypePluginDefaultEndpointData_createMD5Stream(
            epd,serializedKeyMaxSize)) 
    {
        PRESTypePluginDefaultEndpointData_delete(epd);
        return NULL;
    }

    
    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                ::MONITORING::leaseLineInfoPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            ::MONITORING::leaseLineInfoPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }
    


    return epd;    
}


void 
leaseLineInfoPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}


RTIBool 
leaseLineInfoPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    leaseLineInfo *dst,
    const leaseLineInfo *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return ::MONITORING::leaseLineInfoPluginSupport_copy_data(dst,src);
}

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */


RTIBool 
leaseLineInfoPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const leaseLineInfo *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;


  if (endpoint_data) {} /* To avoid warnings */
  if (endpoint_plugin_qos) {} /* To avoid warnings */


  if(serialize_encapsulation) {

    if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
        return RTI_FALSE;
    }

    position = RTICdrStream_resetAlignment(stream);

  }

  if(serialize_sample) {

    if (!RTICdrStream_serializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeLong(
        stream, &sample->lineId)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::elinestatusPlugin_serialize(
            endpoint_data,
            &sample->status, 
            stream, 
            RTI_FALSE, encapsulation_id, 
            RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eLineTypePlugin_serialize(
            endpoint_data,
            &sample->linetype, 
            stream, 
            RTI_FALSE, encapsulation_id, 
            RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
  }

  if(serialize_encapsulation) {
    RTICdrStream_restoreAlignment(stream,position);
  }


  return retval;
}


RTIBool 
leaseLineInfoPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    leaseLineInfo *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }
    
    if(deserialize_sample) {


    if (!RTICdrStream_deserializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeLong(
        stream, &sample->lineId)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::elinestatusPlugin_deserialize_sample(
            endpoint_data,
            &sample->status,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eLineTypePlugin_deserialize_sample(
            endpoint_data,
            &sample->linetype,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}

 
 
RTIBool 
leaseLineInfoPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    leaseLineInfo **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    if (drop_sample) {} /* To avoid warnings */

    return ::MONITORING::leaseLineInfoPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
 
}



RTIBool leaseLineInfoPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (skip_sample) {

    if (!RTICdrStream_skipString(stream, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipLong(stream)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::elinestatusPlugin_skip(
            endpoint_data,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eLineTypePlugin_skip(
            endpoint_data,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int 
leaseLineInfoPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (16) + 1);
            
    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  MONITORING::elinestatusPlugin_get_serialized_sample_max_size(
        endpoint_data,RTI_FALSE,encapsulation_id,current_alignment);
            
    current_alignment +=  MONITORING::eLineTypePlugin_get_serialized_sample_max_size(
        endpoint_data,RTI_FALSE,encapsulation_id,current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


unsigned int 
leaseLineInfoPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
            
    current_alignment +=  RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  MONITORING::elinestatusPlugin_get_serialized_sample_min_size(
        endpoint_data,RTI_FALSE,encapsulation_id,current_alignment);
            
    current_alignment +=  MONITORING::eLineTypePlugin_get_serialized_sample_min_size(
        endpoint_data,RTI_FALSE,encapsulation_id,current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


/* Returns the size of the sample in its serialized form (in bytes).
 * It can also be an estimation in excess of the real buffer needed 
 * during a call to the serialize() function.
 * The value reported does not have to include the space for the
 * encapsulation flags.
 */
unsigned int
leaseLineInfoPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const leaseLineInfo * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (sample) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment += RTICdrType_getStringSerializedSize(
        current_alignment, sample->ipadress);
            
    current_alignment += RTICdrType_getLongMaxSizeSerialized(
        current_alignment);
            
    current_alignment += MONITORING::elinestatusPlugin_get_serialized_sample_size(
        endpoint_data,RTI_FALSE, encapsulation_id, 
        current_alignment, &sample->status);
            
    current_alignment += MONITORING::eLineTypePlugin_get_serialized_sample_size(
        endpoint_data,RTI_FALSE, encapsulation_id, 
        current_alignment, &sample->linetype);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */


PRESTypePluginKeyKind 
leaseLineInfoPlugin_get_key_kind(void)
{

    return PRES_TYPEPLUGIN_USER_KEY;
     
}


RTIBool 
leaseLineInfoPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const leaseLineInfo *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_key) {

    if (!RTICdrStream_serializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool leaseLineInfoPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    leaseLineInfo *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;  
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


 
RTIBool leaseLineInfoPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    leaseLineInfo **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    if (drop_sample) {} /* To avoid warnings */
    return ::MONITORING::leaseLineInfoPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
}



unsigned int
leaseLineInfoPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int encapsulation_size = current_alignment;


    unsigned int initial_alignment = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
        

    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (16) + 1);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


RTIBool 
leaseLineInfoPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    leaseLineInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipLong(stream)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::elinestatusPlugin_skip(
            endpoint_data,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eLineTypePlugin_skip(
            endpoint_data,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}





RTIBool 
leaseLineInfoPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    leaseLineInfoKeyHolder *dst, 
    const leaseLineInfo *src)
{  

    if (endpoint_data) {} /* To avoid warnings */

    if (!RTICdrType_copyString(
        dst->ipadress, src->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool 
leaseLineInfoPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    leaseLineInfo *dst, const
    leaseLineInfoKeyHolder *src)
{

    if (endpoint_data) {} /* To avoid warnings */

    if (!RTICdrType_copyString(
        dst->ipadress, src->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool 
leaseLineInfoPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const leaseLineInfo *instance)
{
    struct RTICdrStream * md5Stream = NULL;

    md5Stream = PRESTypePluginDefaultEndpointData_getMD5Stream(endpoint_data);

    if (md5Stream == NULL) {
        return RTI_FALSE;
    }

    RTIOsapiMemory_zero(
        RTICdrStream_getBuffer(md5Stream),
        RTICdrStream_getBufferLength(md5Stream));
    RTICdrStream_resetPosition(md5Stream);
    RTICdrStream_setDirtyBit(md5Stream, RTI_TRUE);

    if (!::MONITORING::leaseLineInfoPlugin_serialize_key(
            endpoint_data,instance,md5Stream, RTI_FALSE, RTI_CDR_ENCAPSULATION_ID_CDR_BE, RTI_TRUE,NULL)) {
        return RTI_FALSE;
    }
    
    if (PRESTypePluginDefaultEndpointData_getMaxSizeSerializedKey(endpoint_data) > (unsigned int)(MIG_RTPS_KEY_HASH_MAX_LENGTH)) {
        RTICdrStream_computeMD5(md5Stream, keyhash->value);
    } else {
        RTIOsapiMemory_zero(keyhash->value,MIG_RTPS_KEY_HASH_MAX_LENGTH);
        RTIOsapiMemory_copy(
            keyhash->value, 
            RTICdrStream_getBuffer(md5Stream), 
            RTICdrStream_getCurrentPositionOffset(md5Stream));
    }

    keyhash->length = MIG_RTPS_KEY_HASH_MAX_LENGTH;
    return RTI_TRUE;
}


RTIBool 
leaseLineInfoPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos) 
{   
    char * position = NULL;
    leaseLineInfo * sample;

    if (endpoint_plugin_qos) {} /* To avoid warnings */



    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }


    sample = (leaseLineInfo *)
                PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);

    if (sample == NULL) {
        return RTI_FALSE;
    }


    if (!RTICdrStream_deserializeString(
        stream, sample->ipadress, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    if (!::MONITORING::leaseLineInfoPlugin_instance_to_keyhash(
            endpoint_data, keyhash, sample)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}


/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */
 
struct PRESTypePlugin *leaseLineInfoPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
       return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        ::MONITORING::leaseLineInfoPlugin_on_participant_attached;
    plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        ::MONITORING::leaseLineInfoPlugin_on_participant_detached;
    plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        ::MONITORING::leaseLineInfoPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        ::MONITORING::leaseLineInfoPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        ::MONITORING::leaseLineInfoPlugin_copy_sample;
    plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        leaseLineInfoPlugin_create_sample;
    plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        leaseLineInfoPlugin_destroy_sample;

    plugin->serializeFnc =
        (PRESTypePluginSerializeFunction)
        ::MONITORING::leaseLineInfoPlugin_serialize;
    plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction)
        ::MONITORING::leaseLineInfoPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        ::MONITORING::leaseLineInfoPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        ::MONITORING::leaseLineInfoPlugin_get_serialized_sample_min_size;


    plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        leaseLineInfoPlugin_get_sample;
    plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        leaseLineInfoPlugin_return_sample;

    plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        ::MONITORING::leaseLineInfoPlugin_get_key_kind;


    plugin->getSerializedKeyMaxSizeFnc =   
        (PRESTypePluginGetSerializedKeyMaxSizeFunction)
        ::MONITORING::leaseLineInfoPlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
        (PRESTypePluginSerializeKeyFunction)
        ::MONITORING::leaseLineInfoPlugin_serialize_key;
    plugin->deserializeKeyFnc =
        (PRESTypePluginDeserializeKeyFunction)
        ::MONITORING::leaseLineInfoPlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
        (PRESTypePluginDeserializeKeySampleFunction)
        ::MONITORING::leaseLineInfoPlugin_deserialize_key_sample;

    plugin->instanceToKeyHashFnc = 
        (PRESTypePluginInstanceToKeyHashFunction)
        ::MONITORING::leaseLineInfoPlugin_instance_to_keyhash;
    plugin->serializedSampleToKeyHashFnc = 
        (PRESTypePluginSerializedSampleToKeyHashFunction)
        ::MONITORING::leaseLineInfoPlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
        (PRESTypePluginGetKeyFunction)
        leaseLineInfoPlugin_get_key;
    plugin->returnKeyFnc =
        (PRESTypePluginReturnKeyFunction)
        leaseLineInfoPlugin_return_key;

    plugin->instanceToKeyFnc =
        (PRESTypePluginInstanceToKeyFunction)
        ::MONITORING::leaseLineInfoPlugin_instance_to_key;
    plugin->keyToInstanceFnc =
        (PRESTypePluginKeyToInstanceFunction)
        ::MONITORING::leaseLineInfoPlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    
    plugin->typeCode =  (struct RTICdrTypeCode *)::MONITORING::leaseLineInfo_get_typecode();
    
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

    /* Serialized buffer */
    plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        leaseLineInfoPlugin_get_buffer;
    plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        leaseLineInfoPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        ::MONITORING::leaseLineInfoPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = leaseLineInfoTYPENAME;

    return plugin;
}

void
leaseLineInfoPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* --------------------------------------------------------------------------------------
 *  Type tapServerInfo
 * -------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

tapServerInfo *
tapServerInfoPluginSupport_create_data_ex(RTIBool allocate_pointers){
    tapServerInfo *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, tapServerInfo);

    if(sample != NULL) {
        if (!::MONITORING::tapServerInfo_initialize_ex(sample,allocate_pointers)) {
            RTIOsapiHeap_freeStructure(&sample);
            return NULL;
        }
    }
    return sample; 
}


tapServerInfo *
tapServerInfoPluginSupport_create_data(void)
{
    return ::MONITORING::tapServerInfoPluginSupport_create_data_ex(RTI_TRUE);
}


void 
tapServerInfoPluginSupport_destroy_data_ex(
    tapServerInfo *sample,RTIBool deallocate_pointers) {

    ::MONITORING::tapServerInfo_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}


void 
tapServerInfoPluginSupport_destroy_data(
    tapServerInfo *sample) {

    ::MONITORING::tapServerInfoPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}


RTIBool 
tapServerInfoPluginSupport_copy_data(
    tapServerInfo *dst,
    const tapServerInfo *src)
{
    return ::MONITORING::tapServerInfo_copy(dst,src);
}


void 
tapServerInfoPluginSupport_print_data(
    const tapServerInfo *sample,
    const char *desc,
    unsigned int indent_level)
{


    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
      RTILog_debug("%s:\n", desc);
    } else {
      RTILog_debug("\n");
    }

    if (sample == NULL) {
      RTILog_debug("NULL\n");
      return;
    }


    if (&sample->ipv4Address==NULL) {
        RTICdrType_printString(
            NULL, "ipv4Address", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->ipv4Address, "ipv4Address", indent_level + 1);                
    }
            
    MONITORING::eStatePluginSupport_print_data(
        &sample->status, "status", indent_level + 1);
            
    if (&sample->line_info == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("line_info: NULL\n");    
    } else {
                
        if (MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info) != NULL) {
            RTICdrType_printArray(
                MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info), 
                MONITORING::leaseLineInfoSeq_get_length(&sample->line_info),
                sizeof(MONITORING::leaseLineInfo),
                (RTICdrTypePrintFunction)MONITORING::leaseLineInfoPluginSupport_print_data,
                "line_info", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                MONITORING::leaseLineInfoSeq_get_discontiguous_bufferI(&sample->line_info), 
                MONITORING::leaseLineInfoSeq_get_length(&sample->line_info),
                (RTICdrTypePrintFunction)MONITORING::leaseLineInfoPluginSupport_print_data,
                "line_info", indent_level + 1);
        }
    
    }
            

}

tapServerInfo *
tapServerInfoPluginSupport_create_key_ex(RTIBool allocate_pointers){
    tapServerInfo *key = NULL;

    RTIOsapiHeap_allocateStructure(
        &key, tapServerInfoKeyHolder);

    ::MONITORING::tapServerInfo_initialize_ex(key,allocate_pointers);
    return key;
}


tapServerInfo *
tapServerInfoPluginSupport_create_key(void)
{
    return  ::MONITORING::tapServerInfoPluginSupport_create_key_ex(RTI_TRUE);
}


void 
tapServerInfoPluginSupport_destroy_key_ex(
    tapServerInfoKeyHolder *key,RTIBool deallocate_pointers)
{
    ::MONITORING::tapServerInfo_finalize_ex(key,deallocate_pointers);

    RTIOsapiHeap_freeStructure(key);
}


void 
tapServerInfoPluginSupport_destroy_key(
    tapServerInfoKeyHolder *key) {

  ::MONITORING::tapServerInfoPluginSupport_destroy_key_ex(key,RTI_TRUE);

}



/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */



PRESTypePluginParticipantData 
tapServerInfoPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */
    return PRESTypePluginDefaultParticipantData_new(participant_info);

}


void 
tapServerInfoPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

  PRESTypePluginDefaultParticipantData_delete(participant_data);
}


PRESTypePluginEndpointData
tapServerInfoPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    unsigned int serializedKeyMaxSize;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */


    epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            ::MONITORING::tapServerInfoPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            ::MONITORING::tapServerInfoPluginSupport_destroy_data,
            (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
            ::MONITORING::tapServerInfoPluginSupport_create_key,
            (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
            ::MONITORING::tapServerInfoPluginSupport_destroy_key);

    if (epd == NULL) {
        return NULL;
    }
   
    serializedKeyMaxSize = ::MONITORING::tapServerInfoPlugin_get_serialized_key_max_size(
        epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
    
    if (!PRESTypePluginDefaultEndpointData_createMD5Stream(
            epd,serializedKeyMaxSize)) 
    {
        PRESTypePluginDefaultEndpointData_delete(epd);
        return NULL;
    }

    
    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                ::MONITORING::tapServerInfoPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            ::MONITORING::tapServerInfoPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }
    


    return epd;    
}


void 
tapServerInfoPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}


RTIBool 
tapServerInfoPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    tapServerInfo *dst,
    const tapServerInfo *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return ::MONITORING::tapServerInfoPluginSupport_copy_data(dst,src);
}

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */


RTIBool 
tapServerInfoPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const tapServerInfo *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;


  if (endpoint_data) {} /* To avoid warnings */
  if (endpoint_plugin_qos) {} /* To avoid warnings */


  if(serialize_encapsulation) {

    if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
        return RTI_FALSE;
    }

    position = RTICdrStream_resetAlignment(stream);

  }

  if(serialize_sample) {

    if (!RTICdrStream_serializeString(
        stream, sample->ipv4Address, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eStatePlugin_serialize(
            endpoint_data,
            &sample->status, 
            stream, 
            RTI_FALSE, encapsulation_id, 
            RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    if (MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info) != NULL) {
        if (!RTICdrStream_serializeNonPrimitiveSequence(
            stream,
            MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info),
            MONITORING::leaseLineInfoSeq_get_length(&sample->line_info),
            ((MONITORING::MAX_LEASE_LINE)),
            sizeof(MONITORING::leaseLineInfo),
            (RTICdrStreamSerializeFunction)MONITORING::leaseLineInfoPlugin_serialize,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializeNonPrimitivePointerSequence(
            stream,
            (const void **)MONITORING::leaseLineInfoSeq_get_discontiguous_bufferI(&sample->line_info),
            MONITORING::leaseLineInfoSeq_get_length(&sample->line_info),
            ((MONITORING::MAX_LEASE_LINE)),
            (RTICdrStreamSerializeFunction)MONITORING::leaseLineInfoPlugin_serialize,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }
            
  }

  if(serialize_encapsulation) {
    RTICdrStream_restoreAlignment(stream,position);
  }


  return retval;
}


RTIBool 
tapServerInfoPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    tapServerInfo *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }
    
    if(deserialize_sample) {


    if (!RTICdrStream_deserializeString(
        stream, sample->ipv4Address, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eStatePlugin_deserialize_sample(
            endpoint_data,
            &sample->status,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info),
                &sequence_length,
                MONITORING::leaseLineInfoSeq_get_maximum(&sample->line_info),
                sizeof(MONITORING::leaseLineInfo),
                (RTICdrStreamDeserializeFunction)MONITORING::leaseLineInfoPlugin_deserialize_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::leaseLineInfoSeq_get_discontiguous_bufferI(&sample->line_info),
                &sequence_length,
                MONITORING::leaseLineInfoSeq_get_maximum(&sample->line_info),
                (RTICdrStreamDeserializeFunction)MONITORING::leaseLineInfoPlugin_deserialize_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::leaseLineInfoSeq_set_length(
            &sample->line_info, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}

 
 
RTIBool 
tapServerInfoPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    tapServerInfo **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    if (drop_sample) {} /* To avoid warnings */

    return ::MONITORING::tapServerInfoPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
 
}



RTIBool tapServerInfoPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (skip_sample) {

    if (!RTICdrStream_skipString(stream, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eStatePlugin_skip(
            endpoint_data,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipNonPrimitiveSequence(
            stream,
            &sequence_length,
            sizeof(MONITORING::leaseLineInfo),
            (RTICdrStreamSkipFunction)MONITORING::leaseLineInfoPlugin_skip,
            RTI_FALSE,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }
            
    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int 
tapServerInfoPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (16) + 1);
            
    current_alignment +=  MONITORING::eStatePlugin_get_serialized_sample_max_size(
        endpoint_data,RTI_FALSE,encapsulation_id,current_alignment);
            
    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((MONITORING::MAX_LEASE_LINE)),
        MONITORING::leaseLineInfoPlugin_get_serialized_sample_max_size,RTI_FALSE,encapsulation_id,endpoint_data);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


unsigned int 
tapServerInfoPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
            
    current_alignment +=  MONITORING::eStatePlugin_get_serialized_sample_min_size(
        endpoint_data,RTI_FALSE,encapsulation_id,current_alignment);
            
    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0,
        MONITORING::leaseLineInfoPlugin_get_serialized_sample_min_size,RTI_FALSE,encapsulation_id,endpoint_data);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


/* Returns the size of the sample in its serialized form (in bytes).
 * It can also be an estimation in excess of the real buffer needed 
 * during a call to the serialize() function.
 * The value reported does not have to include the space for the
 * encapsulation flags.
 */
unsigned int
tapServerInfoPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const tapServerInfo * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (sample) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment += RTICdrType_getStringSerializedSize(
        current_alignment, sample->ipv4Address);
            
    current_alignment += MONITORING::eStatePlugin_get_serialized_sample_size(
        endpoint_data,RTI_FALSE, encapsulation_id, 
        current_alignment, &sample->status);
            
    if (MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info) != NULL) {
        current_alignment += RTICdrStream_getNonPrimitiveSequenceSerializedSize(
            current_alignment, MONITORING::leaseLineInfoSeq_get_length(&sample->line_info),
            sizeof(MONITORING::leaseLineInfo),
            (RTICdrTypeGetSerializedSampleSizeFunction)MONITORING::leaseLineInfoPlugin_get_serialized_sample_size,
            RTI_FALSE,encapsulation_id,
            MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info),
            endpoint_data);
    } else {
        current_alignment += RTICdrStream_getNonPrimitivePointerSequenceSerializedSize(
            current_alignment, MONITORING::leaseLineInfoSeq_get_length(&sample->line_info),
            sizeof(MONITORING::leaseLineInfo),
            (RTICdrTypeGetSerializedSampleSizeFunction)MONITORING::leaseLineInfoPlugin_get_serialized_sample_size,
            RTI_FALSE,encapsulation_id,
            (const void **)MONITORING::leaseLineInfoSeq_get_discontiguous_bufferI(&sample->line_info),
            endpoint_data);
    }
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */


PRESTypePluginKeyKind 
tapServerInfoPlugin_get_key_kind(void)
{

    return PRES_TYPEPLUGIN_USER_KEY;
     
}


RTIBool 
tapServerInfoPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const tapServerInfo *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_key) {

    if (!RTICdrStream_serializeString(
        stream, sample->ipv4Address, (16) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool tapServerInfoPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    tapServerInfo *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;  
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializeString(
        stream, sample->ipv4Address, (16) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


 
RTIBool tapServerInfoPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    tapServerInfo **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    if (drop_sample) {} /* To avoid warnings */
    return ::MONITORING::tapServerInfoPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
}



unsigned int
tapServerInfoPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int encapsulation_size = current_alignment;


    unsigned int initial_alignment = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
        

    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (16) + 1);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


RTIBool 
tapServerInfoPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    tapServerInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializeString(
        stream, sample->ipv4Address, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eStatePlugin_skip(
            endpoint_data,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipNonPrimitiveSequence(
            stream,
            &sequence_length,
            sizeof(MONITORING::leaseLineInfo),
            (RTICdrStreamSkipFunction)MONITORING::leaseLineInfoPlugin_skip,
            RTI_FALSE,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}





RTIBool 
tapServerInfoPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    tapServerInfoKeyHolder *dst, 
    const tapServerInfo *src)
{  

    if (endpoint_data) {} /* To avoid warnings */

    if (!RTICdrType_copyString(
        dst->ipv4Address, src->ipv4Address, (16) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool 
tapServerInfoPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    tapServerInfo *dst, const
    tapServerInfoKeyHolder *src)
{

    if (endpoint_data) {} /* To avoid warnings */

    if (!RTICdrType_copyString(
        dst->ipv4Address, src->ipv4Address, (16) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool 
tapServerInfoPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const tapServerInfo *instance)
{
    struct RTICdrStream * md5Stream = NULL;

    md5Stream = PRESTypePluginDefaultEndpointData_getMD5Stream(endpoint_data);

    if (md5Stream == NULL) {
        return RTI_FALSE;
    }

    RTIOsapiMemory_zero(
        RTICdrStream_getBuffer(md5Stream),
        RTICdrStream_getBufferLength(md5Stream));
    RTICdrStream_resetPosition(md5Stream);
    RTICdrStream_setDirtyBit(md5Stream, RTI_TRUE);

    if (!::MONITORING::tapServerInfoPlugin_serialize_key(
            endpoint_data,instance,md5Stream, RTI_FALSE, RTI_CDR_ENCAPSULATION_ID_CDR_BE, RTI_TRUE,NULL)) {
        return RTI_FALSE;
    }
    
    if (PRESTypePluginDefaultEndpointData_getMaxSizeSerializedKey(endpoint_data) > (unsigned int)(MIG_RTPS_KEY_HASH_MAX_LENGTH)) {
        RTICdrStream_computeMD5(md5Stream, keyhash->value);
    } else {
        RTIOsapiMemory_zero(keyhash->value,MIG_RTPS_KEY_HASH_MAX_LENGTH);
        RTIOsapiMemory_copy(
            keyhash->value, 
            RTICdrStream_getBuffer(md5Stream), 
            RTICdrStream_getCurrentPositionOffset(md5Stream));
    }

    keyhash->length = MIG_RTPS_KEY_HASH_MAX_LENGTH;
    return RTI_TRUE;
}


RTIBool 
tapServerInfoPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos) 
{   
    char * position = NULL;
    tapServerInfo * sample;

    if (endpoint_plugin_qos) {} /* To avoid warnings */



    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }


    sample = (tapServerInfo *)
                PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);

    if (sample == NULL) {
        return RTI_FALSE;
    }


    if (!RTICdrStream_deserializeString(
        stream, sample->ipv4Address, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    if (!::MONITORING::tapServerInfoPlugin_instance_to_keyhash(
            endpoint_data, keyhash, sample)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}


/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */
 
struct PRESTypePlugin *tapServerInfoPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
       return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        ::MONITORING::tapServerInfoPlugin_on_participant_attached;
    plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        ::MONITORING::tapServerInfoPlugin_on_participant_detached;
    plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        ::MONITORING::tapServerInfoPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        ::MONITORING::tapServerInfoPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        ::MONITORING::tapServerInfoPlugin_copy_sample;
    plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        tapServerInfoPlugin_create_sample;
    plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        tapServerInfoPlugin_destroy_sample;

    plugin->serializeFnc =
        (PRESTypePluginSerializeFunction)
        ::MONITORING::tapServerInfoPlugin_serialize;
    plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction)
        ::MONITORING::tapServerInfoPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        ::MONITORING::tapServerInfoPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        ::MONITORING::tapServerInfoPlugin_get_serialized_sample_min_size;


    plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        tapServerInfoPlugin_get_sample;
    plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        tapServerInfoPlugin_return_sample;

    plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        ::MONITORING::tapServerInfoPlugin_get_key_kind;


    plugin->getSerializedKeyMaxSizeFnc =   
        (PRESTypePluginGetSerializedKeyMaxSizeFunction)
        ::MONITORING::tapServerInfoPlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
        (PRESTypePluginSerializeKeyFunction)
        ::MONITORING::tapServerInfoPlugin_serialize_key;
    plugin->deserializeKeyFnc =
        (PRESTypePluginDeserializeKeyFunction)
        ::MONITORING::tapServerInfoPlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
        (PRESTypePluginDeserializeKeySampleFunction)
        ::MONITORING::tapServerInfoPlugin_deserialize_key_sample;

    plugin->instanceToKeyHashFnc = 
        (PRESTypePluginInstanceToKeyHashFunction)
        ::MONITORING::tapServerInfoPlugin_instance_to_keyhash;
    plugin->serializedSampleToKeyHashFnc = 
        (PRESTypePluginSerializedSampleToKeyHashFunction)
        ::MONITORING::tapServerInfoPlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
        (PRESTypePluginGetKeyFunction)
        tapServerInfoPlugin_get_key;
    plugin->returnKeyFnc =
        (PRESTypePluginReturnKeyFunction)
        tapServerInfoPlugin_return_key;

    plugin->instanceToKeyFnc =
        (PRESTypePluginInstanceToKeyFunction)
        ::MONITORING::tapServerInfoPlugin_instance_to_key;
    plugin->keyToInstanceFnc =
        (PRESTypePluginKeyToInstanceFunction)
        ::MONITORING::tapServerInfoPlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    
    plugin->typeCode =  (struct RTICdrTypeCode *)::MONITORING::tapServerInfo_get_typecode();
    
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

    /* Serialized buffer */
    plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        tapServerInfoPlugin_get_buffer;
    plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        tapServerInfoPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        ::MONITORING::tapServerInfoPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = tapServerInfoTYPENAME;

    return plugin;
}

void
tapServerInfoPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* --------------------------------------------------------------------------------------
 *  Type tagProcessInfo
 * -------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

tagProcessInfo *
tagProcessInfoPluginSupport_create_data_ex(RTIBool allocate_pointers){
    tagProcessInfo *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, tagProcessInfo);

    if(sample != NULL) {
        if (!::MONITORING::tagProcessInfo_initialize_ex(sample,allocate_pointers)) {
            RTIOsapiHeap_freeStructure(&sample);
            return NULL;
        }
    }
    return sample; 
}


tagProcessInfo *
tagProcessInfoPluginSupport_create_data(void)
{
    return ::MONITORING::tagProcessInfoPluginSupport_create_data_ex(RTI_TRUE);
}


void 
tagProcessInfoPluginSupport_destroy_data_ex(
    tagProcessInfo *sample,RTIBool deallocate_pointers) {

    ::MONITORING::tagProcessInfo_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}


void 
tagProcessInfoPluginSupport_destroy_data(
    tagProcessInfo *sample) {

    ::MONITORING::tagProcessInfoPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}


RTIBool 
tagProcessInfoPluginSupport_copy_data(
    tagProcessInfo *dst,
    const tagProcessInfo *src)
{
    return ::MONITORING::tagProcessInfo_copy(dst,src);
}


void 
tagProcessInfoPluginSupport_print_data(
    const tagProcessInfo *sample,
    const char *desc,
    unsigned int indent_level)
{


    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
      RTILog_debug("%s:\n", desc);
    } else {
      RTILog_debug("\n");
    }

    if (sample == NULL) {
      RTILog_debug("NULL\n");
      return;
    }


    if (&sample->name==NULL) {
        RTICdrType_printString(
            NULL, "name", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->name, "name", indent_level + 1);                
    }
            
    MONITORING::eStatePluginSupport_print_data(
        &sample->state, "state", indent_level + 1);
            

}

tagProcessInfo *
tagProcessInfoPluginSupport_create_key_ex(RTIBool allocate_pointers){
    tagProcessInfo *key = NULL;

    RTIOsapiHeap_allocateStructure(
        &key, tagProcessInfoKeyHolder);

    ::MONITORING::tagProcessInfo_initialize_ex(key,allocate_pointers);
    return key;
}


tagProcessInfo *
tagProcessInfoPluginSupport_create_key(void)
{
    return  ::MONITORING::tagProcessInfoPluginSupport_create_key_ex(RTI_TRUE);
}


void 
tagProcessInfoPluginSupport_destroy_key_ex(
    tagProcessInfoKeyHolder *key,RTIBool deallocate_pointers)
{
    ::MONITORING::tagProcessInfo_finalize_ex(key,deallocate_pointers);

    RTIOsapiHeap_freeStructure(key);
}


void 
tagProcessInfoPluginSupport_destroy_key(
    tagProcessInfoKeyHolder *key) {

  ::MONITORING::tagProcessInfoPluginSupport_destroy_key_ex(key,RTI_TRUE);

}



/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */



PRESTypePluginParticipantData 
tagProcessInfoPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */
    return PRESTypePluginDefaultParticipantData_new(participant_info);

}


void 
tagProcessInfoPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

  PRESTypePluginDefaultParticipantData_delete(participant_data);
}


PRESTypePluginEndpointData
tagProcessInfoPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    unsigned int serializedKeyMaxSize;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */


    epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            ::MONITORING::tagProcessInfoPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            ::MONITORING::tagProcessInfoPluginSupport_destroy_data,
            (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
            ::MONITORING::tagProcessInfoPluginSupport_create_key,
            (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
            ::MONITORING::tagProcessInfoPluginSupport_destroy_key);

    if (epd == NULL) {
        return NULL;
    }
   
    serializedKeyMaxSize = ::MONITORING::tagProcessInfoPlugin_get_serialized_key_max_size(
        epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
    
    if (!PRESTypePluginDefaultEndpointData_createMD5Stream(
            epd,serializedKeyMaxSize)) 
    {
        PRESTypePluginDefaultEndpointData_delete(epd);
        return NULL;
    }

    
    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                ::MONITORING::tagProcessInfoPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            ::MONITORING::tagProcessInfoPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }
    


    return epd;    
}


void 
tagProcessInfoPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}


RTIBool 
tagProcessInfoPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagProcessInfo *dst,
    const tagProcessInfo *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return ::MONITORING::tagProcessInfoPluginSupport_copy_data(dst,src);
}

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */


RTIBool 
tagProcessInfoPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const tagProcessInfo *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;


  if (endpoint_data) {} /* To avoid warnings */
  if (endpoint_plugin_qos) {} /* To avoid warnings */


  if(serialize_encapsulation) {

    if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
        return RTI_FALSE;
    }

    position = RTICdrStream_resetAlignment(stream);

  }

  if(serialize_sample) {

    if (!RTICdrStream_serializeString(
        stream, sample->name, ((MONITORING::MAX_PROC_NAMELEN)) + 1)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eStatePlugin_serialize(
            endpoint_data,
            &sample->state, 
            stream, 
            RTI_FALSE, encapsulation_id, 
            RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
  }

  if(serialize_encapsulation) {
    RTICdrStream_restoreAlignment(stream,position);
  }


  return retval;
}


RTIBool 
tagProcessInfoPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagProcessInfo *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }
    
    if(deserialize_sample) {


    if (!RTICdrStream_deserializeString(
        stream, sample->name, ((MONITORING::MAX_PROC_NAMELEN)) + 1)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eStatePlugin_deserialize_sample(
            endpoint_data,
            &sample->state,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}

 
 
RTIBool 
tagProcessInfoPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    tagProcessInfo **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    if (drop_sample) {} /* To avoid warnings */

    return ::MONITORING::tagProcessInfoPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
 
}



RTIBool tagProcessInfoPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (skip_sample) {

    if (!RTICdrStream_skipString(stream, ((MONITORING::MAX_PROC_NAMELEN)) + 1)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eStatePlugin_skip(
            endpoint_data,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int 
tagProcessInfoPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, ((MONITORING::MAX_PROC_NAMELEN)) + 1);
            
    current_alignment +=  MONITORING::eStatePlugin_get_serialized_sample_max_size(
        endpoint_data,RTI_FALSE,encapsulation_id,current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


unsigned int 
tagProcessInfoPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
            
    current_alignment +=  MONITORING::eStatePlugin_get_serialized_sample_min_size(
        endpoint_data,RTI_FALSE,encapsulation_id,current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


/* Returns the size of the sample in its serialized form (in bytes).
 * It can also be an estimation in excess of the real buffer needed 
 * during a call to the serialize() function.
 * The value reported does not have to include the space for the
 * encapsulation flags.
 */
unsigned int
tagProcessInfoPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const tagProcessInfo * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (sample) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment += RTICdrType_getStringSerializedSize(
        current_alignment, sample->name);
            
    current_alignment += MONITORING::eStatePlugin_get_serialized_sample_size(
        endpoint_data,RTI_FALSE, encapsulation_id, 
        current_alignment, &sample->state);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */


PRESTypePluginKeyKind 
tagProcessInfoPlugin_get_key_kind(void)
{

    return PRES_TYPEPLUGIN_USER_KEY;
     
}


RTIBool 
tagProcessInfoPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const tagProcessInfo *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_key) {

    if (!RTICdrStream_serializeString(
        stream, sample->name, ((MONITORING::MAX_PROC_NAMELEN)) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool tagProcessInfoPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagProcessInfo *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;  
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializeString(
        stream, sample->name, ((MONITORING::MAX_PROC_NAMELEN)) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


 
RTIBool tagProcessInfoPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    tagProcessInfo **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    if (drop_sample) {} /* To avoid warnings */
    return ::MONITORING::tagProcessInfoPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
}



unsigned int
tagProcessInfoPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int encapsulation_size = current_alignment;


    unsigned int initial_alignment = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
        

    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, ((MONITORING::MAX_PROC_NAMELEN)) + 1);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


RTIBool 
tagProcessInfoPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    tagProcessInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializeString(
        stream, sample->name, ((MONITORING::MAX_PROC_NAMELEN)) + 1)) {
        return RTI_FALSE;
    }
            
    if (!MONITORING::eStatePlugin_skip(
            endpoint_data,
            stream, 
            RTI_FALSE, RTI_TRUE, 
            endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}





RTIBool 
tagProcessInfoPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    tagProcessInfoKeyHolder *dst, 
    const tagProcessInfo *src)
{  

    if (endpoint_data) {} /* To avoid warnings */

    if (!RTICdrType_copyString(
        dst->name, src->name, ((MONITORING::MAX_PROC_NAMELEN)) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool 
tagProcessInfoPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    tagProcessInfo *dst, const
    tagProcessInfoKeyHolder *src)
{

    if (endpoint_data) {} /* To avoid warnings */

    if (!RTICdrType_copyString(
        dst->name, src->name, ((MONITORING::MAX_PROC_NAMELEN)) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool 
tagProcessInfoPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const tagProcessInfo *instance)
{
    struct RTICdrStream * md5Stream = NULL;

    md5Stream = PRESTypePluginDefaultEndpointData_getMD5Stream(endpoint_data);

    if (md5Stream == NULL) {
        return RTI_FALSE;
    }

    RTIOsapiMemory_zero(
        RTICdrStream_getBuffer(md5Stream),
        RTICdrStream_getBufferLength(md5Stream));
    RTICdrStream_resetPosition(md5Stream);
    RTICdrStream_setDirtyBit(md5Stream, RTI_TRUE);

    if (!::MONITORING::tagProcessInfoPlugin_serialize_key(
            endpoint_data,instance,md5Stream, RTI_FALSE, RTI_CDR_ENCAPSULATION_ID_CDR_BE, RTI_TRUE,NULL)) {
        return RTI_FALSE;
    }
    
    if (PRESTypePluginDefaultEndpointData_getMaxSizeSerializedKey(endpoint_data) > (unsigned int)(MIG_RTPS_KEY_HASH_MAX_LENGTH)) {
        RTICdrStream_computeMD5(md5Stream, keyhash->value);
    } else {
        RTIOsapiMemory_zero(keyhash->value,MIG_RTPS_KEY_HASH_MAX_LENGTH);
        RTIOsapiMemory_copy(
            keyhash->value, 
            RTICdrStream_getBuffer(md5Stream), 
            RTICdrStream_getCurrentPositionOffset(md5Stream));
    }

    keyhash->length = MIG_RTPS_KEY_HASH_MAX_LENGTH;
    return RTI_TRUE;
}


RTIBool 
tagProcessInfoPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos) 
{   
    char * position = NULL;
    tagProcessInfo * sample;

    if (endpoint_plugin_qos) {} /* To avoid warnings */



    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }


    sample = (tagProcessInfo *)
                PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);

    if (sample == NULL) {
        return RTI_FALSE;
    }


    if (!RTICdrStream_deserializeString(
        stream, sample->name, ((MONITORING::MAX_PROC_NAMELEN)) + 1)) {
        return RTI_FALSE;
    }
            
    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    if (!::MONITORING::tagProcessInfoPlugin_instance_to_keyhash(
            endpoint_data, keyhash, sample)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}


/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */
 
struct PRESTypePlugin *tagProcessInfoPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
       return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        ::MONITORING::tagProcessInfoPlugin_on_participant_attached;
    plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        ::MONITORING::tagProcessInfoPlugin_on_participant_detached;
    plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        ::MONITORING::tagProcessInfoPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        ::MONITORING::tagProcessInfoPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        ::MONITORING::tagProcessInfoPlugin_copy_sample;
    plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        tagProcessInfoPlugin_create_sample;
    plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        tagProcessInfoPlugin_destroy_sample;

    plugin->serializeFnc =
        (PRESTypePluginSerializeFunction)
        ::MONITORING::tagProcessInfoPlugin_serialize;
    plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction)
        ::MONITORING::tagProcessInfoPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        ::MONITORING::tagProcessInfoPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        ::MONITORING::tagProcessInfoPlugin_get_serialized_sample_min_size;


    plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        tagProcessInfoPlugin_get_sample;
    plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        tagProcessInfoPlugin_return_sample;

    plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        ::MONITORING::tagProcessInfoPlugin_get_key_kind;


    plugin->getSerializedKeyMaxSizeFnc =   
        (PRESTypePluginGetSerializedKeyMaxSizeFunction)
        ::MONITORING::tagProcessInfoPlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
        (PRESTypePluginSerializeKeyFunction)
        ::MONITORING::tagProcessInfoPlugin_serialize_key;
    plugin->deserializeKeyFnc =
        (PRESTypePluginDeserializeKeyFunction)
        ::MONITORING::tagProcessInfoPlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
        (PRESTypePluginDeserializeKeySampleFunction)
        ::MONITORING::tagProcessInfoPlugin_deserialize_key_sample;

    plugin->instanceToKeyHashFnc = 
        (PRESTypePluginInstanceToKeyHashFunction)
        ::MONITORING::tagProcessInfoPlugin_instance_to_keyhash;
    plugin->serializedSampleToKeyHashFnc = 
        (PRESTypePluginSerializedSampleToKeyHashFunction)
        ::MONITORING::tagProcessInfoPlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
        (PRESTypePluginGetKeyFunction)
        tagProcessInfoPlugin_get_key;
    plugin->returnKeyFnc =
        (PRESTypePluginReturnKeyFunction)
        tagProcessInfoPlugin_return_key;

    plugin->instanceToKeyFnc =
        (PRESTypePluginInstanceToKeyFunction)
        ::MONITORING::tagProcessInfoPlugin_instance_to_key;
    plugin->keyToInstanceFnc =
        (PRESTypePluginKeyToInstanceFunction)
        ::MONITORING::tagProcessInfoPlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    
    plugin->typeCode =  (struct RTICdrTypeCode *)::MONITORING::tagProcessInfo_get_typecode();
    
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

    /* Serialized buffer */
    plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        tagProcessInfoPlugin_get_buffer;
    plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        tagProcessInfoPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        ::MONITORING::tagProcessInfoPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = tagProcessInfoTYPENAME;

    return plugin;
}

void
tagProcessInfoPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* --------------------------------------------------------------------------------------
 *  Type tagSpaceInfo
 * -------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

tagSpaceInfo *
tagSpaceInfoPluginSupport_create_data_ex(RTIBool allocate_pointers){
    tagSpaceInfo *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, tagSpaceInfo);

    if(sample != NULL) {
        if (!::MONITORING::tagSpaceInfo_initialize_ex(sample,allocate_pointers)) {
            RTIOsapiHeap_freeStructure(&sample);
            return NULL;
        }
    }
    return sample; 
}


tagSpaceInfo *
tagSpaceInfoPluginSupport_create_data(void)
{
    return ::MONITORING::tagSpaceInfoPluginSupport_create_data_ex(RTI_TRUE);
}


void 
tagSpaceInfoPluginSupport_destroy_data_ex(
    tagSpaceInfo *sample,RTIBool deallocate_pointers) {

    ::MONITORING::tagSpaceInfo_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}


void 
tagSpaceInfoPluginSupport_destroy_data(
    tagSpaceInfo *sample) {

    ::MONITORING::tagSpaceInfoPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}


RTIBool 
tagSpaceInfoPluginSupport_copy_data(
    tagSpaceInfo *dst,
    const tagSpaceInfo *src)
{
    return ::MONITORING::tagSpaceInfo_copy(dst,src);
}


void 
tagSpaceInfoPluginSupport_print_data(
    const tagSpaceInfo *sample,
    const char *desc,
    unsigned int indent_level)
{


    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
      RTILog_debug("%s:\n", desc);
    } else {
      RTILog_debug("\n");
    }

    if (sample == NULL) {
      RTILog_debug("NULL\n");
      return;
    }


    if (&sample->name==NULL) {
        RTICdrType_printString(
            NULL, "name", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->name, "name", indent_level + 1);                
    }
            
    RTICdrType_printBoolean(
        &sample->is_space_full, "is_space_full", indent_level + 1);
            

}

tagSpaceInfo *
tagSpaceInfoPluginSupport_create_key_ex(RTIBool allocate_pointers){
    tagSpaceInfo *key = NULL;

    RTIOsapiHeap_allocateStructure(
        &key, tagSpaceInfoKeyHolder);

    ::MONITORING::tagSpaceInfo_initialize_ex(key,allocate_pointers);
    return key;
}


tagSpaceInfo *
tagSpaceInfoPluginSupport_create_key(void)
{
    return  ::MONITORING::tagSpaceInfoPluginSupport_create_key_ex(RTI_TRUE);
}


void 
tagSpaceInfoPluginSupport_destroy_key_ex(
    tagSpaceInfoKeyHolder *key,RTIBool deallocate_pointers)
{
    ::MONITORING::tagSpaceInfo_finalize_ex(key,deallocate_pointers);

    RTIOsapiHeap_freeStructure(key);
}


void 
tagSpaceInfoPluginSupport_destroy_key(
    tagSpaceInfoKeyHolder *key) {

  ::MONITORING::tagSpaceInfoPluginSupport_destroy_key_ex(key,RTI_TRUE);

}



/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */



PRESTypePluginParticipantData 
tagSpaceInfoPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */
    return PRESTypePluginDefaultParticipantData_new(participant_info);

}


void 
tagSpaceInfoPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

  PRESTypePluginDefaultParticipantData_delete(participant_data);
}


PRESTypePluginEndpointData
tagSpaceInfoPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    unsigned int serializedKeyMaxSize;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */


    epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            ::MONITORING::tagSpaceInfoPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            ::MONITORING::tagSpaceInfoPluginSupport_destroy_data,
            (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
            ::MONITORING::tagSpaceInfoPluginSupport_create_key,
            (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
            ::MONITORING::tagSpaceInfoPluginSupport_destroy_key);

    if (epd == NULL) {
        return NULL;
    }
   
    serializedKeyMaxSize = ::MONITORING::tagSpaceInfoPlugin_get_serialized_key_max_size(
        epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
    
    if (!PRESTypePluginDefaultEndpointData_createMD5Stream(
            epd,serializedKeyMaxSize)) 
    {
        PRESTypePluginDefaultEndpointData_delete(epd);
        return NULL;
    }

    
    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                ::MONITORING::tagSpaceInfoPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            ::MONITORING::tagSpaceInfoPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }
    


    return epd;    
}


void 
tagSpaceInfoPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}


RTIBool 
tagSpaceInfoPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagSpaceInfo *dst,
    const tagSpaceInfo *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return ::MONITORING::tagSpaceInfoPluginSupport_copy_data(dst,src);
}

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */


RTIBool 
tagSpaceInfoPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const tagSpaceInfo *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;


  if (endpoint_data) {} /* To avoid warnings */
  if (endpoint_plugin_qos) {} /* To avoid warnings */


  if(serialize_encapsulation) {

    if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
        return RTI_FALSE;
    }

    position = RTICdrStream_resetAlignment(stream);

  }

  if(serialize_sample) {

    if (!RTICdrStream_serializeString(
        stream, sample->name, ((MONITORING::MAX_DIR_PATHLEN)) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeBoolean(
        stream, &sample->is_space_full)) {
        return RTI_FALSE;
    }
            
  }

  if(serialize_encapsulation) {
    RTICdrStream_restoreAlignment(stream,position);
  }


  return retval;
}


RTIBool 
tagSpaceInfoPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagSpaceInfo *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }
    
    if(deserialize_sample) {


    if (!RTICdrStream_deserializeString(
        stream, sample->name, ((MONITORING::MAX_DIR_PATHLEN)) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeBoolean(
        stream, &sample->is_space_full)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}

 
 
RTIBool 
tagSpaceInfoPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    tagSpaceInfo **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    if (drop_sample) {} /* To avoid warnings */

    return ::MONITORING::tagSpaceInfoPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
 
}



RTIBool tagSpaceInfoPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (skip_sample) {

    if (!RTICdrStream_skipString(stream, ((MONITORING::MAX_DIR_PATHLEN)) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipBoolean(stream)) {
        return RTI_FALSE;
    }
            
    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int 
tagSpaceInfoPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, ((MONITORING::MAX_DIR_PATHLEN)) + 1);
            
    current_alignment +=  RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


unsigned int 
tagSpaceInfoPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
            
    current_alignment +=  RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


/* Returns the size of the sample in its serialized form (in bytes).
 * It can also be an estimation in excess of the real buffer needed 
 * during a call to the serialize() function.
 * The value reported does not have to include the space for the
 * encapsulation flags.
 */
unsigned int
tagSpaceInfoPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const tagSpaceInfo * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (sample) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment += RTICdrType_getStringSerializedSize(
        current_alignment, sample->name);
            
    current_alignment += RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */


PRESTypePluginKeyKind 
tagSpaceInfoPlugin_get_key_kind(void)
{

    return PRES_TYPEPLUGIN_USER_KEY;
     
}


RTIBool 
tagSpaceInfoPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const tagSpaceInfo *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_key) {

    if (!RTICdrStream_serializeString(
        stream, sample->name, ((MONITORING::MAX_DIR_PATHLEN)) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool tagSpaceInfoPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagSpaceInfo *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;  
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializeString(
        stream, sample->name, ((MONITORING::MAX_DIR_PATHLEN)) + 1)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


 
RTIBool tagSpaceInfoPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    tagSpaceInfo **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    if (drop_sample) {} /* To avoid warnings */
    return ::MONITORING::tagSpaceInfoPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
}



unsigned int
tagSpaceInfoPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int encapsulation_size = current_alignment;


    unsigned int initial_alignment = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
        

    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, ((MONITORING::MAX_DIR_PATHLEN)) + 1);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


RTIBool 
tagSpaceInfoPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    tagSpaceInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializeString(
        stream, sample->name, ((MONITORING::MAX_DIR_PATHLEN)) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipBoolean(stream)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}





RTIBool 
tagSpaceInfoPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    tagSpaceInfoKeyHolder *dst, 
    const tagSpaceInfo *src)
{  

    if (endpoint_data) {} /* To avoid warnings */

    if (!RTICdrType_copyString(
        dst->name, src->name, ((MONITORING::MAX_DIR_PATHLEN)) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool 
tagSpaceInfoPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    tagSpaceInfo *dst, const
    tagSpaceInfoKeyHolder *src)
{

    if (endpoint_data) {} /* To avoid warnings */

    if (!RTICdrType_copyString(
        dst->name, src->name, ((MONITORING::MAX_DIR_PATHLEN)) + 1)) {
        return RTI_FALSE;
    }
            
    return RTI_TRUE;
}


RTIBool 
tagSpaceInfoPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const tagSpaceInfo *instance)
{
    struct RTICdrStream * md5Stream = NULL;

    md5Stream = PRESTypePluginDefaultEndpointData_getMD5Stream(endpoint_data);

    if (md5Stream == NULL) {
        return RTI_FALSE;
    }

    RTIOsapiMemory_zero(
        RTICdrStream_getBuffer(md5Stream),
        RTICdrStream_getBufferLength(md5Stream));
    RTICdrStream_resetPosition(md5Stream);
    RTICdrStream_setDirtyBit(md5Stream, RTI_TRUE);

    if (!::MONITORING::tagSpaceInfoPlugin_serialize_key(
            endpoint_data,instance,md5Stream, RTI_FALSE, RTI_CDR_ENCAPSULATION_ID_CDR_BE, RTI_TRUE,NULL)) {
        return RTI_FALSE;
    }
    
    if (PRESTypePluginDefaultEndpointData_getMaxSizeSerializedKey(endpoint_data) > (unsigned int)(MIG_RTPS_KEY_HASH_MAX_LENGTH)) {
        RTICdrStream_computeMD5(md5Stream, keyhash->value);
    } else {
        RTIOsapiMemory_zero(keyhash->value,MIG_RTPS_KEY_HASH_MAX_LENGTH);
        RTIOsapiMemory_copy(
            keyhash->value, 
            RTICdrStream_getBuffer(md5Stream), 
            RTICdrStream_getCurrentPositionOffset(md5Stream));
    }

    keyhash->length = MIG_RTPS_KEY_HASH_MAX_LENGTH;
    return RTI_TRUE;
}


RTIBool 
tagSpaceInfoPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos) 
{   
    char * position = NULL;
    tagSpaceInfo * sample;

    if (endpoint_plugin_qos) {} /* To avoid warnings */



    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }


    sample = (tagSpaceInfo *)
                PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);

    if (sample == NULL) {
        return RTI_FALSE;
    }


    if (!RTICdrStream_deserializeString(
        stream, sample->name, ((MONITORING::MAX_DIR_PATHLEN)) + 1)) {
        return RTI_FALSE;
    }
            
    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    if (!::MONITORING::tagSpaceInfoPlugin_instance_to_keyhash(
            endpoint_data, keyhash, sample)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}


/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */
 
struct PRESTypePlugin *tagSpaceInfoPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
       return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        ::MONITORING::tagSpaceInfoPlugin_on_participant_attached;
    plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        ::MONITORING::tagSpaceInfoPlugin_on_participant_detached;
    plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        ::MONITORING::tagSpaceInfoPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        ::MONITORING::tagSpaceInfoPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        ::MONITORING::tagSpaceInfoPlugin_copy_sample;
    plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        tagSpaceInfoPlugin_create_sample;
    plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        tagSpaceInfoPlugin_destroy_sample;

    plugin->serializeFnc =
        (PRESTypePluginSerializeFunction)
        ::MONITORING::tagSpaceInfoPlugin_serialize;
    plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction)
        ::MONITORING::tagSpaceInfoPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        ::MONITORING::tagSpaceInfoPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        ::MONITORING::tagSpaceInfoPlugin_get_serialized_sample_min_size;


    plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        tagSpaceInfoPlugin_get_sample;
    plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        tagSpaceInfoPlugin_return_sample;

    plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        ::MONITORING::tagSpaceInfoPlugin_get_key_kind;


    plugin->getSerializedKeyMaxSizeFnc =   
        (PRESTypePluginGetSerializedKeyMaxSizeFunction)
        ::MONITORING::tagSpaceInfoPlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
        (PRESTypePluginSerializeKeyFunction)
        ::MONITORING::tagSpaceInfoPlugin_serialize_key;
    plugin->deserializeKeyFnc =
        (PRESTypePluginDeserializeKeyFunction)
        ::MONITORING::tagSpaceInfoPlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
        (PRESTypePluginDeserializeKeySampleFunction)
        ::MONITORING::tagSpaceInfoPlugin_deserialize_key_sample;

    plugin->instanceToKeyHashFnc = 
        (PRESTypePluginInstanceToKeyHashFunction)
        ::MONITORING::tagSpaceInfoPlugin_instance_to_keyhash;
    plugin->serializedSampleToKeyHashFnc = 
        (PRESTypePluginSerializedSampleToKeyHashFunction)
        ::MONITORING::tagSpaceInfoPlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
        (PRESTypePluginGetKeyFunction)
        tagSpaceInfoPlugin_get_key;
    plugin->returnKeyFnc =
        (PRESTypePluginReturnKeyFunction)
        tagSpaceInfoPlugin_return_key;

    plugin->instanceToKeyFnc =
        (PRESTypePluginInstanceToKeyFunction)
        ::MONITORING::tagSpaceInfoPlugin_instance_to_key;
    plugin->keyToInstanceFnc =
        (PRESTypePluginKeyToInstanceFunction)
        ::MONITORING::tagSpaceInfoPlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    
    plugin->typeCode =  (struct RTICdrTypeCode *)::MONITORING::tagSpaceInfo_get_typecode();
    
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

    /* Serialized buffer */
    plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        tagSpaceInfoPlugin_get_buffer;
    plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        tagSpaceInfoPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        ::MONITORING::tagSpaceInfoPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = tagSpaceInfoTYPENAME;

    return plugin;
}

void
tagSpaceInfoPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

/* --------------------------------------------------------------------------------------
 *  Type tagServerInfo
 * -------------------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

tagServerInfo *
tagServerInfoPluginSupport_create_data_ex(RTIBool allocate_pointers){
    tagServerInfo *sample = NULL;

    RTIOsapiHeap_allocateStructure(
        &sample, tagServerInfo);

    if(sample != NULL) {
        if (!::MONITORING::tagServerInfo_initialize_ex(sample,allocate_pointers)) {
            RTIOsapiHeap_freeStructure(&sample);
            return NULL;
        }
    }
    return sample; 
}


tagServerInfo *
tagServerInfoPluginSupport_create_data(void)
{
    return ::MONITORING::tagServerInfoPluginSupport_create_data_ex(RTI_TRUE);
}


void 
tagServerInfoPluginSupport_destroy_data_ex(
    tagServerInfo *sample,RTIBool deallocate_pointers) {

    ::MONITORING::tagServerInfo_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
}


void 
tagServerInfoPluginSupport_destroy_data(
    tagServerInfo *sample) {

    ::MONITORING::tagServerInfoPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}


RTIBool 
tagServerInfoPluginSupport_copy_data(
    tagServerInfo *dst,
    const tagServerInfo *src)
{
    return ::MONITORING::tagServerInfo_copy(dst,src);
}


void 
tagServerInfoPluginSupport_print_data(
    const tagServerInfo *sample,
    const char *desc,
    unsigned int indent_level)
{


    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
      RTILog_debug("%s:\n", desc);
    } else {
      RTILog_debug("\n");
    }

    if (sample == NULL) {
      RTILog_debug("NULL\n");
      return;
    }


    if (&sample->ipv4Address==NULL) {
        RTICdrType_printString(
            NULL, "ipv4Address", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->ipv4Address, "ipv4Address", indent_level + 1);                
    }
            
    RTICdrType_printBoolean(
        &sample->serverStatus, "serverStatus", indent_level + 1);
            
    if (&sample->process_list == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("process_list: NULL\n");    
    } else {
                
        if (MONITORING::tagProcessInfoSeq_get_contiguous_bufferI(&sample->process_list) != NULL) {
            RTICdrType_printArray(
                MONITORING::tagProcessInfoSeq_get_contiguous_bufferI(&sample->process_list), 
                MONITORING::tagProcessInfoSeq_get_length(&sample->process_list),
                sizeof(MONITORING::tagProcessInfo),
                (RTICdrTypePrintFunction)MONITORING::tagProcessInfoPluginSupport_print_data,
                "process_list", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                MONITORING::tagProcessInfoSeq_get_discontiguous_bufferI(&sample->process_list), 
                MONITORING::tagProcessInfoSeq_get_length(&sample->process_list),
                (RTICdrTypePrintFunction)MONITORING::tagProcessInfoPluginSupport_print_data,
                "process_list", indent_level + 1);
        }
    
    }
            
    if (&sample->space_list == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("space_list: NULL\n");    
    } else {
                
        if (MONITORING::tagSpaceInfoSeq_get_contiguous_bufferI(&sample->space_list) != NULL) {
            RTICdrType_printArray(
                MONITORING::tagSpaceInfoSeq_get_contiguous_bufferI(&sample->space_list), 
                MONITORING::tagSpaceInfoSeq_get_length(&sample->space_list),
                sizeof(MONITORING::tagSpaceInfo),
                (RTICdrTypePrintFunction)MONITORING::tagSpaceInfoPluginSupport_print_data,
                "space_list", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                MONITORING::tagSpaceInfoSeq_get_discontiguous_bufferI(&sample->space_list), 
                MONITORING::tagSpaceInfoSeq_get_length(&sample->space_list),
                (RTICdrTypePrintFunction)MONITORING::tagSpaceInfoPluginSupport_print_data,
                "space_list", indent_level + 1);
        }
    
    }
            
    if (&sample->line_info == NULL) {
        RTICdrType_printIndent(indent_level+1);
        RTILog_debug("line_info: NULL\n");    
    } else {
                
        if (MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info) != NULL) {
            RTICdrType_printArray(
                MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info), 
                MONITORING::leaseLineInfoSeq_get_length(&sample->line_info),
                sizeof(MONITORING::leaseLineInfo),
                (RTICdrTypePrintFunction)MONITORING::leaseLineInfoPluginSupport_print_data,
                "line_info", indent_level + 1);
        } else {
            RTICdrType_printPointerArray(
                MONITORING::leaseLineInfoSeq_get_discontiguous_bufferI(&sample->line_info), 
                MONITORING::leaseLineInfoSeq_get_length(&sample->line_info),
                (RTICdrTypePrintFunction)MONITORING::leaseLineInfoPluginSupport_print_data,
                "line_info", indent_level + 1);
        }
    
    }
            
    if (&sample->Logpath==NULL) {
        RTICdrType_printString(
            NULL, "Logpath", indent_level + 1);                
    } else {
        RTICdrType_printString(
            sample->Logpath, "Logpath", indent_level + 1);                
    }
            
    RTICdrType_printBoolean(
        &sample->status, "status", indent_level + 1);
            

}

tagServerInfo *
tagServerInfoPluginSupport_create_key_ex(RTIBool allocate_pointers){
    tagServerInfo *key = NULL;

    RTIOsapiHeap_allocateStructure(
        &key, tagServerInfoKeyHolder);

    ::MONITORING::tagServerInfo_initialize_ex(key,allocate_pointers);
    return key;
}


tagServerInfo *
tagServerInfoPluginSupport_create_key(void)
{
    return  ::MONITORING::tagServerInfoPluginSupport_create_key_ex(RTI_TRUE);
}


void 
tagServerInfoPluginSupport_destroy_key_ex(
    tagServerInfoKeyHolder *key,RTIBool deallocate_pointers)
{
    ::MONITORING::tagServerInfo_finalize_ex(key,deallocate_pointers);

    RTIOsapiHeap_freeStructure(key);
}


void 
tagServerInfoPluginSupport_destroy_key(
    tagServerInfoKeyHolder *key) {

  ::MONITORING::tagServerInfoPluginSupport_destroy_key_ex(key,RTI_TRUE);

}



/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */



PRESTypePluginParticipantData 
tagServerInfoPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */
    return PRESTypePluginDefaultParticipantData_new(participant_info);

}


void 
tagServerInfoPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{

  PRESTypePluginDefaultParticipantData_delete(participant_data);
}


PRESTypePluginEndpointData
tagServerInfoPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;

    unsigned int serializedKeyMaxSize;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */


    epd = PRESTypePluginDefaultEndpointData_new(
            participant_data,
            endpoint_info,
            (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
            ::MONITORING::tagServerInfoPluginSupport_create_data,
            (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
            ::MONITORING::tagServerInfoPluginSupport_destroy_data,
            (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
            ::MONITORING::tagServerInfoPluginSupport_create_key,
            (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
            ::MONITORING::tagServerInfoPluginSupport_destroy_key);

    if (epd == NULL) {
        return NULL;
    }
   
    serializedKeyMaxSize = ::MONITORING::tagServerInfoPlugin_get_serialized_key_max_size(
        epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
    
    if (!PRESTypePluginDefaultEndpointData_createMD5Stream(
            epd,serializedKeyMaxSize)) 
    {
        PRESTypePluginDefaultEndpointData_delete(epd);
        return NULL;
    }

    
    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        if (PRESTypePluginDefaultEndpointData_createWriterPool(
                epd,
                endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                ::MONITORING::tagServerInfoPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            ::MONITORING::tagServerInfoPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }
    


    return epd;    
}


void 
tagServerInfoPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}


RTIBool 
tagServerInfoPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagServerInfo *dst,
    const tagServerInfo *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return ::MONITORING::tagServerInfoPluginSupport_copy_data(dst,src);
}

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */


RTIBool 
tagServerInfoPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const tagServerInfo *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;


  if (endpoint_data) {} /* To avoid warnings */
  if (endpoint_plugin_qos) {} /* To avoid warnings */


  if(serialize_encapsulation) {

    if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
        return RTI_FALSE;
    }

    position = RTICdrStream_resetAlignment(stream);

  }

  if(serialize_sample) {

    if (!RTICdrStream_serializeString(
        stream, sample->ipv4Address, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeBoolean(
        stream, &sample->serverStatus)) {
        return RTI_FALSE;
    }
            
    if (MONITORING::tagProcessInfoSeq_get_contiguous_bufferI(&sample->process_list) != NULL) {
        if (!RTICdrStream_serializeNonPrimitiveSequence(
            stream,
            MONITORING::tagProcessInfoSeq_get_contiguous_bufferI(&sample->process_list),
            MONITORING::tagProcessInfoSeq_get_length(&sample->process_list),
            ((MONITORING::MAX_PROCESSES)),
            sizeof(MONITORING::tagProcessInfo),
            (RTICdrStreamSerializeFunction)MONITORING::tagProcessInfoPlugin_serialize,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializeNonPrimitivePointerSequence(
            stream,
            (const void **)MONITORING::tagProcessInfoSeq_get_discontiguous_bufferI(&sample->process_list),
            MONITORING::tagProcessInfoSeq_get_length(&sample->process_list),
            ((MONITORING::MAX_PROCESSES)),
            (RTICdrStreamSerializeFunction)MONITORING::tagProcessInfoPlugin_serialize,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }
            
    if (MONITORING::tagSpaceInfoSeq_get_contiguous_bufferI(&sample->space_list) != NULL) {
        if (!RTICdrStream_serializeNonPrimitiveSequence(
            stream,
            MONITORING::tagSpaceInfoSeq_get_contiguous_bufferI(&sample->space_list),
            MONITORING::tagSpaceInfoSeq_get_length(&sample->space_list),
            ((MONITORING::MAX_SPACES)),
            sizeof(MONITORING::tagSpaceInfo),
            (RTICdrStreamSerializeFunction)MONITORING::tagSpaceInfoPlugin_serialize,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializeNonPrimitivePointerSequence(
            stream,
            (const void **)MONITORING::tagSpaceInfoSeq_get_discontiguous_bufferI(&sample->space_list),
            MONITORING::tagSpaceInfoSeq_get_length(&sample->space_list),
            ((MONITORING::MAX_SPACES)),
            (RTICdrStreamSerializeFunction)MONITORING::tagSpaceInfoPlugin_serialize,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }
            
    if (MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info) != NULL) {
        if (!RTICdrStream_serializeNonPrimitiveSequence(
            stream,
            MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info),
            MONITORING::leaseLineInfoSeq_get_length(&sample->line_info),
            ((MONITORING::MAX_LEASE_LINE)),
            sizeof(MONITORING::leaseLineInfo),
            (RTICdrStreamSerializeFunction)MONITORING::leaseLineInfoPlugin_serialize,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializeNonPrimitivePointerSequence(
            stream,
            (const void **)MONITORING::leaseLineInfoSeq_get_discontiguous_bufferI(&sample->line_info),
            MONITORING::leaseLineInfoSeq_get_length(&sample->line_info),
            ((MONITORING::MAX_LEASE_LINE)),
            (RTICdrStreamSerializeFunction)MONITORING::leaseLineInfoPlugin_serialize,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }
            
    if (!RTICdrStream_serializeString(
        stream, sample->Logpath, (100) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_serializeBoolean(
        stream, &sample->status)) {
        return RTI_FALSE;
    }
            
  }

  if(serialize_encapsulation) {
    RTICdrStream_restoreAlignment(stream,position);
  }


  return retval;
}


RTIBool 
tagServerInfoPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagServerInfo *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }
    
    if(deserialize_sample) {


    if (!RTICdrStream_deserializeString(
        stream, sample->ipv4Address, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeBoolean(
        stream, &sample->serverStatus)) {
        return RTI_FALSE;
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::tagProcessInfoSeq_get_contiguous_bufferI(&sample->process_list) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::tagProcessInfoSeq_get_contiguous_bufferI(&sample->process_list),
                &sequence_length,
                MONITORING::tagProcessInfoSeq_get_maximum(&sample->process_list),
                sizeof(MONITORING::tagProcessInfo),
                (RTICdrStreamDeserializeFunction)MONITORING::tagProcessInfoPlugin_deserialize_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::tagProcessInfoSeq_get_discontiguous_bufferI(&sample->process_list),
                &sequence_length,
                MONITORING::tagProcessInfoSeq_get_maximum(&sample->process_list),
                (RTICdrStreamDeserializeFunction)MONITORING::tagProcessInfoPlugin_deserialize_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::tagProcessInfoSeq_set_length(
            &sample->process_list, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::tagSpaceInfoSeq_get_contiguous_bufferI(&sample->space_list) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::tagSpaceInfoSeq_get_contiguous_bufferI(&sample->space_list),
                &sequence_length,
                MONITORING::tagSpaceInfoSeq_get_maximum(&sample->space_list),
                sizeof(MONITORING::tagSpaceInfo),
                (RTICdrStreamDeserializeFunction)MONITORING::tagSpaceInfoPlugin_deserialize_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::tagSpaceInfoSeq_get_discontiguous_bufferI(&sample->space_list),
                &sequence_length,
                MONITORING::tagSpaceInfoSeq_get_maximum(&sample->space_list),
                (RTICdrStreamDeserializeFunction)MONITORING::tagSpaceInfoPlugin_deserialize_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::tagSpaceInfoSeq_set_length(
            &sample->space_list, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info),
                &sequence_length,
                MONITORING::leaseLineInfoSeq_get_maximum(&sample->line_info),
                sizeof(MONITORING::leaseLineInfo),
                (RTICdrStreamDeserializeFunction)MONITORING::leaseLineInfoPlugin_deserialize_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::leaseLineInfoSeq_get_discontiguous_bufferI(&sample->line_info),
                &sequence_length,
                MONITORING::leaseLineInfoSeq_get_maximum(&sample->line_info),
                (RTICdrStreamDeserializeFunction)MONITORING::leaseLineInfoPlugin_deserialize_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::leaseLineInfoSeq_set_length(
            &sample->line_info, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    if (!RTICdrStream_deserializeString(
        stream, sample->Logpath, (100) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_deserializeBoolean(
        stream, &sample->status)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}

 
 
RTIBool 
tagServerInfoPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    tagServerInfo **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    if (drop_sample) {} /* To avoid warnings */

    return ::MONITORING::tagServerInfoPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
 
}



RTIBool tagServerInfoPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(skip_encapsulation) {
        if (!RTICdrStream_skipEncapsulation(stream)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (skip_sample) {

    if (!RTICdrStream_skipString(stream, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipBoolean(stream)) {
        return RTI_FALSE;
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipNonPrimitiveSequence(
            stream,
            &sequence_length,
            sizeof(MONITORING::tagProcessInfo),
            (RTICdrStreamSkipFunction)MONITORING::tagProcessInfoPlugin_skip,
            RTI_FALSE,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipNonPrimitiveSequence(
            stream,
            &sequence_length,
            sizeof(MONITORING::tagSpaceInfo),
            (RTICdrStreamSkipFunction)MONITORING::tagSpaceInfoPlugin_skip,
            RTI_FALSE,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (!RTICdrStream_skipNonPrimitiveSequence(
            stream,
            &sequence_length,
            sizeof(MONITORING::leaseLineInfo),
            (RTICdrStreamSkipFunction)MONITORING::leaseLineInfoPlugin_skip,
            RTI_FALSE,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }
            
    if (!RTICdrStream_skipString(stream, (100) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipBoolean(stream)) {
        return RTI_FALSE;
    }
            
    }


    if(skip_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


unsigned int 
tagServerInfoPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (16) + 1);
            
    current_alignment +=  RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((MONITORING::MAX_PROCESSES)),
        MONITORING::tagProcessInfoPlugin_get_serialized_sample_max_size,RTI_FALSE,encapsulation_id,endpoint_data);
            
    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((MONITORING::MAX_SPACES)),
        MONITORING::tagSpaceInfoPlugin_get_serialized_sample_max_size,RTI_FALSE,encapsulation_id,endpoint_data);
            
    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((MONITORING::MAX_LEASE_LINE)),
        MONITORING::leaseLineInfoPlugin_get_serialized_sample_max_size,RTI_FALSE,encapsulation_id,endpoint_data);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (100) + 1);
            
    current_alignment +=  RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


unsigned int 
tagServerInfoPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
            
    current_alignment +=  RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);
            
    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0,
        MONITORING::tagProcessInfoPlugin_get_serialized_sample_min_size,RTI_FALSE,encapsulation_id,endpoint_data);
            
    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0,
        MONITORING::tagSpaceInfoPlugin_get_serialized_sample_min_size,RTI_FALSE,encapsulation_id,endpoint_data);
            
    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, 0,
        MONITORING::leaseLineInfoPlugin_get_serialized_sample_min_size,RTI_FALSE,encapsulation_id,endpoint_data);
            
    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, 1);
            
    current_alignment +=  RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


/* Returns the size of the sample in its serialized form (in bytes).
 * It can also be an estimation in excess of the real buffer needed 
 * during a call to the serialize() function.
 * The value reported does not have to include the space for the
 * encapsulation flags.
 */
unsigned int
tagServerInfoPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const tagServerInfo * sample) 
{

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */
    if (sample) {} /* To avoid warnings */


    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }

        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }


    current_alignment += RTICdrType_getStringSerializedSize(
        current_alignment, sample->ipv4Address);
            
    current_alignment += RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);
            
    if (MONITORING::tagProcessInfoSeq_get_contiguous_bufferI(&sample->process_list) != NULL) {
        current_alignment += RTICdrStream_getNonPrimitiveSequenceSerializedSize(
            current_alignment, MONITORING::tagProcessInfoSeq_get_length(&sample->process_list),
            sizeof(MONITORING::tagProcessInfo),
            (RTICdrTypeGetSerializedSampleSizeFunction)MONITORING::tagProcessInfoPlugin_get_serialized_sample_size,
            RTI_FALSE,encapsulation_id,
            MONITORING::tagProcessInfoSeq_get_contiguous_bufferI(&sample->process_list),
            endpoint_data);
    } else {
        current_alignment += RTICdrStream_getNonPrimitivePointerSequenceSerializedSize(
            current_alignment, MONITORING::tagProcessInfoSeq_get_length(&sample->process_list),
            sizeof(MONITORING::tagProcessInfo),
            (RTICdrTypeGetSerializedSampleSizeFunction)MONITORING::tagProcessInfoPlugin_get_serialized_sample_size,
            RTI_FALSE,encapsulation_id,
            (const void **)MONITORING::tagProcessInfoSeq_get_discontiguous_bufferI(&sample->process_list),
            endpoint_data);
    }
            
    if (MONITORING::tagSpaceInfoSeq_get_contiguous_bufferI(&sample->space_list) != NULL) {
        current_alignment += RTICdrStream_getNonPrimitiveSequenceSerializedSize(
            current_alignment, MONITORING::tagSpaceInfoSeq_get_length(&sample->space_list),
            sizeof(MONITORING::tagSpaceInfo),
            (RTICdrTypeGetSerializedSampleSizeFunction)MONITORING::tagSpaceInfoPlugin_get_serialized_sample_size,
            RTI_FALSE,encapsulation_id,
            MONITORING::tagSpaceInfoSeq_get_contiguous_bufferI(&sample->space_list),
            endpoint_data);
    } else {
        current_alignment += RTICdrStream_getNonPrimitivePointerSequenceSerializedSize(
            current_alignment, MONITORING::tagSpaceInfoSeq_get_length(&sample->space_list),
            sizeof(MONITORING::tagSpaceInfo),
            (RTICdrTypeGetSerializedSampleSizeFunction)MONITORING::tagSpaceInfoPlugin_get_serialized_sample_size,
            RTI_FALSE,encapsulation_id,
            (const void **)MONITORING::tagSpaceInfoSeq_get_discontiguous_bufferI(&sample->space_list),
            endpoint_data);
    }
            
    if (MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info) != NULL) {
        current_alignment += RTICdrStream_getNonPrimitiveSequenceSerializedSize(
            current_alignment, MONITORING::leaseLineInfoSeq_get_length(&sample->line_info),
            sizeof(MONITORING::leaseLineInfo),
            (RTICdrTypeGetSerializedSampleSizeFunction)MONITORING::leaseLineInfoPlugin_get_serialized_sample_size,
            RTI_FALSE,encapsulation_id,
            MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info),
            endpoint_data);
    } else {
        current_alignment += RTICdrStream_getNonPrimitivePointerSequenceSerializedSize(
            current_alignment, MONITORING::leaseLineInfoSeq_get_length(&sample->line_info),
            sizeof(MONITORING::leaseLineInfo),
            (RTICdrTypeGetSerializedSampleSizeFunction)MONITORING::leaseLineInfoPlugin_get_serialized_sample_size,
            RTI_FALSE,encapsulation_id,
            (const void **)MONITORING::leaseLineInfoSeq_get_discontiguous_bufferI(&sample->line_info),
            endpoint_data);
    }
            
    current_alignment += RTICdrType_getStringSerializedSize(
        current_alignment, sample->Logpath);
            
    current_alignment += RTICdrType_getBooleanMaxSizeSerialized(
        current_alignment);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */


PRESTypePluginKeyKind 
tagServerInfoPlugin_get_key_kind(void)
{

    return PRES_TYPEPLUGIN_USER_KEY;
     
}


RTIBool 
tagServerInfoPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const tagServerInfo *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream, encapsulation_id)) {
            return RTI_FALSE;
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if(serialize_key) {

    if (!RTICdrStream_serializeString(
        stream, sample->ipv4Address, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (MONITORING::tagProcessInfoSeq_get_contiguous_bufferI(&sample->process_list) != NULL) {
        if (!RTICdrStream_serializeNonPrimitiveSequence(
            stream,
            MONITORING::tagProcessInfoSeq_get_contiguous_bufferI(&sample->process_list),
            MONITORING::tagProcessInfoSeq_get_length(&sample->process_list),
            ((MONITORING::MAX_PROCESSES)),
            sizeof(MONITORING::tagProcessInfo),
            (RTICdrStreamSerializeFunction)MONITORING::tagProcessInfoPlugin_serialize_key,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializeNonPrimitivePointerSequence(
            stream,
            (const void **)MONITORING::tagProcessInfoSeq_get_discontiguous_bufferI(&sample->process_list),
            MONITORING::tagProcessInfoSeq_get_length(&sample->process_list),
            ((MONITORING::MAX_PROCESSES)),
            (RTICdrStreamSerializeFunction)MONITORING::tagProcessInfoPlugin_serialize_key,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }
            
    if (MONITORING::tagSpaceInfoSeq_get_contiguous_bufferI(&sample->space_list) != NULL) {
        if (!RTICdrStream_serializeNonPrimitiveSequence(
            stream,
            MONITORING::tagSpaceInfoSeq_get_contiguous_bufferI(&sample->space_list),
            MONITORING::tagSpaceInfoSeq_get_length(&sample->space_list),
            ((MONITORING::MAX_SPACES)),
            sizeof(MONITORING::tagSpaceInfo),
            (RTICdrStreamSerializeFunction)MONITORING::tagSpaceInfoPlugin_serialize_key,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializeNonPrimitivePointerSequence(
            stream,
            (const void **)MONITORING::tagSpaceInfoSeq_get_discontiguous_bufferI(&sample->space_list),
            MONITORING::tagSpaceInfoSeq_get_length(&sample->space_list),
            ((MONITORING::MAX_SPACES)),
            (RTICdrStreamSerializeFunction)MONITORING::tagSpaceInfoPlugin_serialize_key,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }
            
    if (MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info) != NULL) {
        if (!RTICdrStream_serializeNonPrimitiveSequence(
            stream,
            MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info),
            MONITORING::leaseLineInfoSeq_get_length(&sample->line_info),
            ((MONITORING::MAX_LEASE_LINE)),
            sizeof(MONITORING::leaseLineInfo),
            (RTICdrStreamSerializeFunction)MONITORING::leaseLineInfoPlugin_serialize_key,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    } else {
        if (!RTICdrStream_serializeNonPrimitivePointerSequence(
            stream,
            (const void **)MONITORING::leaseLineInfoSeq_get_discontiguous_bufferI(&sample->line_info),
            MONITORING::leaseLineInfoSeq_get_length(&sample->line_info),
            ((MONITORING::MAX_LEASE_LINE)),
            (RTICdrStreamSerializeFunction)MONITORING::leaseLineInfoPlugin_serialize_key,
            RTI_FALSE, encapsulation_id,RTI_TRUE,
            endpoint_data,endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
    }
            
    }


    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


RTIBool tagServerInfoPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagServerInfo *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        /* Deserialize encapsulation */
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;  
        }


        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializeString(
        stream, sample->ipv4Address, (16) + 1)) {
        return RTI_FALSE;
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::tagProcessInfoSeq_get_contiguous_bufferI(&sample->process_list) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::tagProcessInfoSeq_get_contiguous_bufferI(&sample->process_list),
                &sequence_length,
                MONITORING::tagProcessInfoSeq_get_maximum(&sample->process_list),
                sizeof(MONITORING::tagProcessInfo),
                (RTICdrStreamDeserializeFunction)MONITORING::tagProcessInfoPlugin_deserialize_key_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::tagProcessInfoSeq_get_discontiguous_bufferI(&sample->process_list),
                &sequence_length,
                MONITORING::tagProcessInfoSeq_get_maximum(&sample->process_list),
                (RTICdrStreamDeserializeFunction)MONITORING::tagProcessInfoPlugin_deserialize_key_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::tagProcessInfoSeq_set_length(
            &sample->process_list, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::tagSpaceInfoSeq_get_contiguous_bufferI(&sample->space_list) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::tagSpaceInfoSeq_get_contiguous_bufferI(&sample->space_list),
                &sequence_length,
                MONITORING::tagSpaceInfoSeq_get_maximum(&sample->space_list),
                sizeof(MONITORING::tagSpaceInfo),
                (RTICdrStreamDeserializeFunction)MONITORING::tagSpaceInfoPlugin_deserialize_key_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::tagSpaceInfoSeq_get_discontiguous_bufferI(&sample->space_list),
                &sequence_length,
                MONITORING::tagSpaceInfoSeq_get_maximum(&sample->space_list),
                (RTICdrStreamDeserializeFunction)MONITORING::tagSpaceInfoPlugin_deserialize_key_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::tagSpaceInfoSeq_set_length(
            &sample->space_list, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info),
                &sequence_length,
                MONITORING::leaseLineInfoSeq_get_maximum(&sample->line_info),
                sizeof(MONITORING::leaseLineInfo),
                (RTICdrStreamDeserializeFunction)MONITORING::leaseLineInfoPlugin_deserialize_key_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::leaseLineInfoSeq_get_discontiguous_bufferI(&sample->line_info),
                &sequence_length,
                MONITORING::leaseLineInfoSeq_get_maximum(&sample->line_info),
                (RTICdrStreamDeserializeFunction)MONITORING::leaseLineInfoPlugin_deserialize_key_sample,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::leaseLineInfoSeq_set_length(
            &sample->line_info, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}


 
RTIBool tagServerInfoPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    tagServerInfo **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    if (drop_sample) {} /* To avoid warnings */
    return ::MONITORING::tagServerInfoPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
}



unsigned int
tagServerInfoPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{

    unsigned int encapsulation_size = current_alignment;


    unsigned int initial_alignment = current_alignment;


    if (endpoint_data) {} /* To avoid warnings */


    if (include_encapsulation) {
        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }


        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;

    }
        

    current_alignment +=  RTICdrType_getStringMaxSizeSerialized(
        current_alignment, (16) + 1);
            
    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((MONITORING::MAX_PROCESSES)),
        MONITORING::tagProcessInfoPlugin_get_serialized_key_max_size,RTI_FALSE,encapsulation_id,endpoint_data);
            
    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((MONITORING::MAX_SPACES)),
        MONITORING::tagSpaceInfoPlugin_get_serialized_key_max_size,RTI_FALSE,encapsulation_id,endpoint_data);
            
    current_alignment +=  RTICdrType_getNonPrimitiveSequenceMaxSizeSerialized(
        current_alignment, ((MONITORING::MAX_LEASE_LINE)),
        MONITORING::leaseLineInfoPlugin_get_serialized_key_max_size,RTI_FALSE,encapsulation_id,endpoint_data);
            
    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }

    return current_alignment - initial_alignment;
}


RTIBool 
tagServerInfoPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    tagServerInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */


    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);

    }

    if (deserialize_key) {

    if (!RTICdrStream_deserializeString(
        stream, sample->ipv4Address, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipBoolean(stream)) {
        return RTI_FALSE;
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::tagProcessInfoSeq_get_contiguous_bufferI(&sample->process_list) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::tagProcessInfoSeq_get_contiguous_bufferI(&sample->process_list),
                &sequence_length,
                MONITORING::tagProcessInfoSeq_get_maximum(&sample->process_list),
                sizeof(MONITORING::tagProcessInfo),
                (RTICdrStreamDeserializeFunction)MONITORING::tagProcessInfoPlugin_serialized_sample_to_key,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::tagProcessInfoSeq_get_discontiguous_bufferI(&sample->process_list),
                &sequence_length,
                MONITORING::tagProcessInfoSeq_get_maximum(&sample->process_list),
                (RTICdrStreamDeserializeFunction)MONITORING::tagProcessInfoPlugin_serialized_sample_to_key,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::tagProcessInfoSeq_set_length(
            &sample->process_list, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::tagSpaceInfoSeq_get_contiguous_bufferI(&sample->space_list) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::tagSpaceInfoSeq_get_contiguous_bufferI(&sample->space_list),
                &sequence_length,
                MONITORING::tagSpaceInfoSeq_get_maximum(&sample->space_list),
                sizeof(MONITORING::tagSpaceInfo),
                (RTICdrStreamDeserializeFunction)MONITORING::tagSpaceInfoPlugin_serialized_sample_to_key,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::tagSpaceInfoSeq_get_discontiguous_bufferI(&sample->space_list),
                &sequence_length,
                MONITORING::tagSpaceInfoSeq_get_maximum(&sample->space_list),
                (RTICdrStreamDeserializeFunction)MONITORING::tagSpaceInfoPlugin_serialized_sample_to_key,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::tagSpaceInfoSeq_set_length(
            &sample->space_list, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info),
                &sequence_length,
                MONITORING::leaseLineInfoSeq_get_maximum(&sample->line_info),
                sizeof(MONITORING::leaseLineInfo),
                (RTICdrStreamDeserializeFunction)MONITORING::leaseLineInfoPlugin_serialized_sample_to_key,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::leaseLineInfoSeq_get_discontiguous_bufferI(&sample->line_info),
                &sequence_length,
                MONITORING::leaseLineInfoSeq_get_maximum(&sample->line_info),
                (RTICdrStreamDeserializeFunction)MONITORING::leaseLineInfoPlugin_serialized_sample_to_key,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::leaseLineInfoSeq_set_length(
            &sample->line_info, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    if (!RTICdrStream_skipString(stream, (100) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipBoolean(stream)) {
        return RTI_FALSE;
    }
            
    }


    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    return RTI_TRUE;
}





RTIBool 
tagServerInfoPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    tagServerInfoKeyHolder *dst, 
    const tagServerInfo *src)
{  

    if (endpoint_data) {} /* To avoid warnings */

    if (!RTICdrType_copyString(
        dst->ipv4Address, src->ipv4Address, (16) + 1)) {
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
            
    return RTI_TRUE;
}


RTIBool 
tagServerInfoPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    tagServerInfo *dst, const
    tagServerInfoKeyHolder *src)
{

    if (endpoint_data) {} /* To avoid warnings */

    if (!RTICdrType_copyString(
        dst->ipv4Address, src->ipv4Address, (16) + 1)) {
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
            
    return RTI_TRUE;
}


RTIBool 
tagServerInfoPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const tagServerInfo *instance)
{
    struct RTICdrStream * md5Stream = NULL;

    md5Stream = PRESTypePluginDefaultEndpointData_getMD5Stream(endpoint_data);

    if (md5Stream == NULL) {
        return RTI_FALSE;
    }

    RTIOsapiMemory_zero(
        RTICdrStream_getBuffer(md5Stream),
        RTICdrStream_getBufferLength(md5Stream));
    RTICdrStream_resetPosition(md5Stream);
    RTICdrStream_setDirtyBit(md5Stream, RTI_TRUE);

    if (!::MONITORING::tagServerInfoPlugin_serialize_key(
            endpoint_data,instance,md5Stream, RTI_FALSE, RTI_CDR_ENCAPSULATION_ID_CDR_BE, RTI_TRUE,NULL)) {
        return RTI_FALSE;
    }
    
    if (PRESTypePluginDefaultEndpointData_getMaxSizeSerializedKey(endpoint_data) > (unsigned int)(MIG_RTPS_KEY_HASH_MAX_LENGTH)) {
        RTICdrStream_computeMD5(md5Stream, keyhash->value);
    } else {
        RTIOsapiMemory_zero(keyhash->value,MIG_RTPS_KEY_HASH_MAX_LENGTH);
        RTIOsapiMemory_copy(
            keyhash->value, 
            RTICdrStream_getBuffer(md5Stream), 
            RTICdrStream_getCurrentPositionOffset(md5Stream));
    }

    keyhash->length = MIG_RTPS_KEY_HASH_MAX_LENGTH;
    return RTI_TRUE;
}


RTIBool 
tagServerInfoPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos) 
{   
    char * position = NULL;
    tagServerInfo * sample;

    if (endpoint_plugin_qos) {} /* To avoid warnings */



    if(deserialize_encapsulation) {
        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }


    sample = (tagServerInfo *)
                PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);

    if (sample == NULL) {
        return RTI_FALSE;
    }


    if (!RTICdrStream_deserializeString(
        stream, sample->ipv4Address, (16) + 1)) {
        return RTI_FALSE;
    }
            
    if (!RTICdrStream_skipBoolean(stream)) {
        return RTI_FALSE;
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::tagProcessInfoSeq_get_contiguous_bufferI(&sample->process_list) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::tagProcessInfoSeq_get_contiguous_bufferI(&sample->process_list),
                &sequence_length,
                MONITORING::tagProcessInfoSeq_get_maximum(&sample->process_list),
                sizeof(MONITORING::tagProcessInfo),
                (RTICdrStreamDeserializeFunction)MONITORING::tagProcessInfoPlugin_serialized_sample_to_key,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::tagProcessInfoSeq_get_discontiguous_bufferI(&sample->process_list),
                &sequence_length,
                MONITORING::tagProcessInfoSeq_get_maximum(&sample->process_list),
                (RTICdrStreamDeserializeFunction)MONITORING::tagProcessInfoPlugin_serialized_sample_to_key,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::tagProcessInfoSeq_set_length(
            &sample->process_list, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::tagSpaceInfoSeq_get_contiguous_bufferI(&sample->space_list) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::tagSpaceInfoSeq_get_contiguous_bufferI(&sample->space_list),
                &sequence_length,
                MONITORING::tagSpaceInfoSeq_get_maximum(&sample->space_list),
                sizeof(MONITORING::tagSpaceInfo),
                (RTICdrStreamDeserializeFunction)MONITORING::tagSpaceInfoPlugin_serialized_sample_to_key,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::tagSpaceInfoSeq_get_discontiguous_bufferI(&sample->space_list),
                &sequence_length,
                MONITORING::tagSpaceInfoSeq_get_maximum(&sample->space_list),
                (RTICdrStreamDeserializeFunction)MONITORING::tagSpaceInfoPlugin_serialized_sample_to_key,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::tagSpaceInfoSeq_set_length(
            &sample->space_list, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    {
        RTICdrUnsignedLong sequence_length;

        if (MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info) != NULL) {
            if (!RTICdrStream_deserializeNonPrimitiveSequence(
                stream,
                MONITORING::leaseLineInfoSeq_get_contiguous_bufferI(&sample->line_info),
                &sequence_length,
                MONITORING::leaseLineInfoSeq_get_maximum(&sample->line_info),
                sizeof(MONITORING::leaseLineInfo),
                (RTICdrStreamDeserializeFunction)MONITORING::leaseLineInfoPlugin_serialized_sample_to_key,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        } else {
            if (!RTICdrStream_deserializeNonPrimitivePointerSequence(
                stream,
                (void **)MONITORING::leaseLineInfoSeq_get_discontiguous_bufferI(&sample->line_info),
                &sequence_length,
                MONITORING::leaseLineInfoSeq_get_maximum(&sample->line_info),
                (RTICdrStreamDeserializeFunction)MONITORING::leaseLineInfoPlugin_serialized_sample_to_key,
                RTI_FALSE,RTI_TRUE,
                endpoint_data,endpoint_plugin_qos)) {
                return RTI_FALSE;
            }
        }
        if (!MONITORING::leaseLineInfoSeq_set_length(
            &sample->line_info, sequence_length)) {
            return RTI_FALSE;
        }
    }
            
    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }


    if (!::MONITORING::tagServerInfoPlugin_instance_to_keyhash(
            endpoint_data, keyhash, sample)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}


/* ------------------------------------------------------------------------
 * Plug-in Installation Methods
 * ------------------------------------------------------------------------ */
 
struct PRESTypePlugin *tagServerInfoPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);
    if (plugin == NULL) {
       return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        ::MONITORING::tagServerInfoPlugin_on_participant_attached;
    plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        ::MONITORING::tagServerInfoPlugin_on_participant_detached;
    plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        ::MONITORING::tagServerInfoPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        ::MONITORING::tagServerInfoPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        ::MONITORING::tagServerInfoPlugin_copy_sample;
    plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        tagServerInfoPlugin_create_sample;
    plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        tagServerInfoPlugin_destroy_sample;

    plugin->serializeFnc =
        (PRESTypePluginSerializeFunction)
        ::MONITORING::tagServerInfoPlugin_serialize;
    plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction)
        ::MONITORING::tagServerInfoPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        ::MONITORING::tagServerInfoPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        ::MONITORING::tagServerInfoPlugin_get_serialized_sample_min_size;


    plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        tagServerInfoPlugin_get_sample;
    plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        tagServerInfoPlugin_return_sample;

    plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        ::MONITORING::tagServerInfoPlugin_get_key_kind;


    plugin->getSerializedKeyMaxSizeFnc =   
        (PRESTypePluginGetSerializedKeyMaxSizeFunction)
        ::MONITORING::tagServerInfoPlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
        (PRESTypePluginSerializeKeyFunction)
        ::MONITORING::tagServerInfoPlugin_serialize_key;
    plugin->deserializeKeyFnc =
        (PRESTypePluginDeserializeKeyFunction)
        ::MONITORING::tagServerInfoPlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
        (PRESTypePluginDeserializeKeySampleFunction)
        ::MONITORING::tagServerInfoPlugin_deserialize_key_sample;

    plugin->instanceToKeyHashFnc = 
        (PRESTypePluginInstanceToKeyHashFunction)
        ::MONITORING::tagServerInfoPlugin_instance_to_keyhash;
    plugin->serializedSampleToKeyHashFnc = 
        (PRESTypePluginSerializedSampleToKeyHashFunction)
        ::MONITORING::tagServerInfoPlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
        (PRESTypePluginGetKeyFunction)
        tagServerInfoPlugin_get_key;
    plugin->returnKeyFnc =
        (PRESTypePluginReturnKeyFunction)
        tagServerInfoPlugin_return_key;

    plugin->instanceToKeyFnc =
        (PRESTypePluginInstanceToKeyFunction)
        ::MONITORING::tagServerInfoPlugin_instance_to_key;
    plugin->keyToInstanceFnc =
        (PRESTypePluginKeyToInstanceFunction)
        ::MONITORING::tagServerInfoPlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    
    plugin->typeCode =  (struct RTICdrTypeCode *)::MONITORING::tagServerInfo_get_typecode();
    
    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE; 

    /* Serialized buffer */
    plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        tagServerInfoPlugin_get_buffer;
    plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        tagServerInfoPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        ::MONITORING::tagServerInfoPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = tagServerInfoTYPENAME;

    return plugin;
}

void
tagServerInfoPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 

} /* namespace MONITORING */
