
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from Monitoring.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/

#ifndef MonitoringPlugin_1808175700_h
#define MonitoringPlugin_1808175700_h

#include "Monitoring.h"




struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif


#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif


namespace MONITORING{


/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */

NDDSUSERDllExport extern RTIBool
elinestatusPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const elinestatus *sample, struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
elinestatusPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    elinestatus *sample, 
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
elinestatusPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int
elinestatusPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
elinestatusPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
elinestatusPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const elinestatus * sample);

/* ------------------------------------------------------------------------
    Key Management functions:
 * ------------------------------------------------------------------------ */

NDDSUSERDllExport extern RTIBool 
elinestatusPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const elinestatus *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
elinestatusPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    elinestatus *sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
elinestatusPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool
elinestatusPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    elinestatus *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

/* ----------------------------------------------------------------------------
    Support functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern void
elinestatusPluginSupport_print_data(
    const elinestatus *sample, const char *desc, int indent_level);



/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */

NDDSUSERDllExport extern RTIBool
eStatePlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const eState *sample, struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
eStatePlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    eState *sample, 
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
eStatePlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int
eStatePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
eStatePlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
eStatePlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const eState * sample);

/* ------------------------------------------------------------------------
    Key Management functions:
 * ------------------------------------------------------------------------ */

NDDSUSERDllExport extern RTIBool 
eStatePlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const eState *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
eStatePlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    eState *sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
eStatePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool
eStatePlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    eState *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

/* ----------------------------------------------------------------------------
    Support functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern void
eStatePluginSupport_print_data(
    const eState *sample, const char *desc, int indent_level);



/* ------------------------------------------------------------------------
 * (De)Serialization Methods
 * ------------------------------------------------------------------------ */

NDDSUSERDllExport extern RTIBool
eLineTypePlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const eLineType *sample, struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
eLineTypePlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    eLineType *sample, 
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
eLineTypePlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int
eLineTypePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
eLineTypePlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
eLineTypePlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const eLineType * sample);

/* ------------------------------------------------------------------------
    Key Management functions:
 * ------------------------------------------------------------------------ */

NDDSUSERDllExport extern RTIBool 
eLineTypePlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const eLineType *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
eLineTypePlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    eLineType *sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
eLineTypePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool
eLineTypePlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    eLineType *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

/* ----------------------------------------------------------------------------
    Support functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern void
eLineTypePluginSupport_print_data(
    const eLineType *sample, const char *desc, int indent_level);


/* The type used to store keys for instances of type struct
 * lineDetails.
 *
 * By default, this type is struct lineDetails
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct lineDetails)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct lineDetails, the
 * following restriction applies: the key of struct
 * lineDetails must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct lineDetails.
*/
typedef  struct lineDetails lineDetailsKeyHolder;


#define lineDetailsPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define lineDetailsPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define lineDetailsPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define lineDetailsPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define lineDetailsPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define lineDetailsPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey
 

#define lineDetailsPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define lineDetailsPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern lineDetails*
lineDetailsPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern lineDetails*
lineDetailsPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
lineDetailsPluginSupport_copy_data(
    lineDetails *out,
    const lineDetails *in);

NDDSUSERDllExport extern void 
lineDetailsPluginSupport_destroy_data_ex(
    lineDetails *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
lineDetailsPluginSupport_destroy_data(
    lineDetails *sample);

NDDSUSERDllExport extern void 
lineDetailsPluginSupport_print_data(
    const lineDetails *sample,
    const char *desc,
    unsigned int indent);


NDDSUSERDllExport extern lineDetails*
lineDetailsPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern lineDetails*
lineDetailsPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
lineDetailsPluginSupport_destroy_key_ex(
    lineDetailsKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
lineDetailsPluginSupport_destroy_key(
    lineDetailsKeyHolder *key);
 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
lineDetailsPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
lineDetailsPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
lineDetailsPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
lineDetailsPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
lineDetailsPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    lineDetails *out,
    const lineDetails *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
lineDetailsPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const lineDetails *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
lineDetailsPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    lineDetails *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
lineDetailsPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    lineDetails **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
lineDetailsPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
lineDetailsPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
lineDetailsPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
lineDetailsPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const lineDetails * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
lineDetailsPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
lineDetailsPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
lineDetailsPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const lineDetails *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
lineDetailsPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    lineDetails * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
lineDetailsPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    lineDetails ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
lineDetailsPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    lineDetails *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
lineDetailsPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    lineDetailsKeyHolder *key, 
    const lineDetails *instance);

NDDSUSERDllExport extern RTIBool 
lineDetailsPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    lineDetails *instance, 
    const lineDetailsKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
lineDetailsPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const lineDetails *instance);

NDDSUSERDllExport extern RTIBool 
lineDetailsPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 
     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
lineDetailsPlugin_new(void);

NDDSUSERDllExport extern void
lineDetailsPlugin_delete(struct PRESTypePlugin *);

/* The type used to store keys for instances of type struct
 * pslInfo.
 *
 * By default, this type is struct pslInfo
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct pslInfo)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct pslInfo, the
 * following restriction applies: the key of struct
 * pslInfo must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct pslInfo.
*/
typedef  struct pslInfo pslInfoKeyHolder;


#define pslInfoPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define pslInfoPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define pslInfoPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define pslInfoPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define pslInfoPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define pslInfoPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey
 

#define pslInfoPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define pslInfoPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern pslInfo*
pslInfoPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern pslInfo*
pslInfoPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
pslInfoPluginSupport_copy_data(
    pslInfo *out,
    const pslInfo *in);

NDDSUSERDllExport extern void 
pslInfoPluginSupport_destroy_data_ex(
    pslInfo *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
pslInfoPluginSupport_destroy_data(
    pslInfo *sample);

NDDSUSERDllExport extern void 
pslInfoPluginSupport_print_data(
    const pslInfo *sample,
    const char *desc,
    unsigned int indent);


NDDSUSERDllExport extern pslInfo*
pslInfoPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern pslInfo*
pslInfoPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
pslInfoPluginSupport_destroy_key_ex(
    pslInfoKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
pslInfoPluginSupport_destroy_key(
    pslInfoKeyHolder *key);
 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
pslInfoPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
pslInfoPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
pslInfoPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
pslInfoPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
pslInfoPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    pslInfo *out,
    const pslInfo *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
pslInfoPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const pslInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
pslInfoPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    pslInfo *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
pslInfoPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    pslInfo **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
pslInfoPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
pslInfoPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
pslInfoPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
pslInfoPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const pslInfo * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
pslInfoPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
pslInfoPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
pslInfoPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const pslInfo *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
pslInfoPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    pslInfo * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
pslInfoPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    pslInfo ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
pslInfoPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    pslInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
pslInfoPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    pslInfoKeyHolder *key, 
    const pslInfo *instance);

NDDSUSERDllExport extern RTIBool 
pslInfoPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    pslInfo *instance, 
    const pslInfoKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
pslInfoPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const pslInfo *instance);

NDDSUSERDllExport extern RTIBool 
pslInfoPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 
     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
pslInfoPlugin_new(void);

NDDSUSERDllExport extern void
pslInfoPlugin_delete(struct PRESTypePlugin *);

/* The type used to store keys for instances of type struct
 * ipSequence.
 *
 * By default, this type is struct ipSequence
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct ipSequence)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct ipSequence, the
 * following restriction applies: the key of struct
 * ipSequence must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct ipSequence.
*/
typedef  struct ipSequence ipSequenceKeyHolder;


#define ipSequencePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define ipSequencePlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define ipSequencePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ipSequencePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define ipSequencePlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define ipSequencePlugin_return_key PRESTypePluginDefaultEndpointData_returnKey
 

#define ipSequencePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ipSequencePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern ipSequence*
ipSequencePluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ipSequence*
ipSequencePluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ipSequencePluginSupport_copy_data(
    ipSequence *out,
    const ipSequence *in);

NDDSUSERDllExport extern void 
ipSequencePluginSupport_destroy_data_ex(
    ipSequence *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ipSequencePluginSupport_destroy_data(
    ipSequence *sample);

NDDSUSERDllExport extern void 
ipSequencePluginSupport_print_data(
    const ipSequence *sample,
    const char *desc,
    unsigned int indent);


NDDSUSERDllExport extern ipSequence*
ipSequencePluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ipSequence*
ipSequencePluginSupport_create_key(void);

NDDSUSERDllExport extern void 
ipSequencePluginSupport_destroy_key_ex(
    ipSequenceKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ipSequencePluginSupport_destroy_key(
    ipSequenceKeyHolder *key);
 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
ipSequencePlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
ipSequencePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
ipSequencePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
ipSequencePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
ipSequencePlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ipSequence *out,
    const ipSequence *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
ipSequencePlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const ipSequence *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ipSequencePlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    ipSequence *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ipSequencePlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ipSequence **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
ipSequencePlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
ipSequencePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ipSequencePlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
ipSequencePlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const ipSequence * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
ipSequencePlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ipSequencePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
ipSequencePlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const ipSequence *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
ipSequencePlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    ipSequence * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ipSequencePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ipSequence ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
ipSequencePlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ipSequence *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
ipSequencePlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    ipSequenceKeyHolder *key, 
    const ipSequence *instance);

NDDSUSERDllExport extern RTIBool 
ipSequencePlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    ipSequence *instance, 
    const ipSequenceKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
ipSequencePlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const ipSequence *instance);

NDDSUSERDllExport extern RTIBool 
ipSequencePlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 
     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
ipSequencePlugin_new(void);

NDDSUSERDllExport extern void
ipSequencePlugin_delete(struct PRESTypePlugin *);


#define leaseProcessStartPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define leaseProcessStartPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define leaseProcessStartPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define leaseProcessStartPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 
 

#define leaseProcessStartPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define leaseProcessStartPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern leaseProcessStart*
leaseProcessStartPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern leaseProcessStart*
leaseProcessStartPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
leaseProcessStartPluginSupport_copy_data(
    leaseProcessStart *out,
    const leaseProcessStart *in);

NDDSUSERDllExport extern void 
leaseProcessStartPluginSupport_destroy_data_ex(
    leaseProcessStart *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
leaseProcessStartPluginSupport_destroy_data(
    leaseProcessStart *sample);

NDDSUSERDllExport extern void 
leaseProcessStartPluginSupport_print_data(
    const leaseProcessStart *sample,
    const char *desc,
    unsigned int indent);

 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
leaseProcessStartPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
leaseProcessStartPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
leaseProcessStartPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
leaseProcessStartPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
leaseProcessStartPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    leaseProcessStart *out,
    const leaseProcessStart *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
leaseProcessStartPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const leaseProcessStart *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
leaseProcessStartPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    leaseProcessStart *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
leaseProcessStartPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    leaseProcessStart **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
leaseProcessStartPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
leaseProcessStartPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
leaseProcessStartPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
leaseProcessStartPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const leaseProcessStart * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
leaseProcessStartPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
leaseProcessStartPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
leaseProcessStartPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const leaseProcessStart *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
leaseProcessStartPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    leaseProcessStart * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
leaseProcessStartPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    leaseProcessStart ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
leaseProcessStartPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    leaseProcessStart *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
leaseProcessStartPlugin_new(void);

NDDSUSERDllExport extern void
leaseProcessStartPlugin_delete(struct PRESTypePlugin *);

/* The type used to store keys for instances of type struct
 * leaseLineInfo.
 *
 * By default, this type is struct leaseLineInfo
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct leaseLineInfo)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct leaseLineInfo, the
 * following restriction applies: the key of struct
 * leaseLineInfo must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct leaseLineInfo.
*/
typedef  struct leaseLineInfo leaseLineInfoKeyHolder;


#define leaseLineInfoPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define leaseLineInfoPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define leaseLineInfoPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define leaseLineInfoPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define leaseLineInfoPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define leaseLineInfoPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey
 

#define leaseLineInfoPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define leaseLineInfoPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern leaseLineInfo*
leaseLineInfoPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern leaseLineInfo*
leaseLineInfoPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
leaseLineInfoPluginSupport_copy_data(
    leaseLineInfo *out,
    const leaseLineInfo *in);

NDDSUSERDllExport extern void 
leaseLineInfoPluginSupport_destroy_data_ex(
    leaseLineInfo *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
leaseLineInfoPluginSupport_destroy_data(
    leaseLineInfo *sample);

NDDSUSERDllExport extern void 
leaseLineInfoPluginSupport_print_data(
    const leaseLineInfo *sample,
    const char *desc,
    unsigned int indent);


NDDSUSERDllExport extern leaseLineInfo*
leaseLineInfoPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern leaseLineInfo*
leaseLineInfoPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
leaseLineInfoPluginSupport_destroy_key_ex(
    leaseLineInfoKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
leaseLineInfoPluginSupport_destroy_key(
    leaseLineInfoKeyHolder *key);
 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
leaseLineInfoPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
leaseLineInfoPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
leaseLineInfoPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
leaseLineInfoPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
leaseLineInfoPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    leaseLineInfo *out,
    const leaseLineInfo *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
leaseLineInfoPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const leaseLineInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
leaseLineInfoPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    leaseLineInfo *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
leaseLineInfoPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    leaseLineInfo **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
leaseLineInfoPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
leaseLineInfoPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
leaseLineInfoPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
leaseLineInfoPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const leaseLineInfo * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
leaseLineInfoPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
leaseLineInfoPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
leaseLineInfoPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const leaseLineInfo *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
leaseLineInfoPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    leaseLineInfo * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
leaseLineInfoPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    leaseLineInfo ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
leaseLineInfoPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    leaseLineInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
leaseLineInfoPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    leaseLineInfoKeyHolder *key, 
    const leaseLineInfo *instance);

NDDSUSERDllExport extern RTIBool 
leaseLineInfoPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    leaseLineInfo *instance, 
    const leaseLineInfoKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
leaseLineInfoPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const leaseLineInfo *instance);

NDDSUSERDllExport extern RTIBool 
leaseLineInfoPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 
     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
leaseLineInfoPlugin_new(void);

NDDSUSERDllExport extern void
leaseLineInfoPlugin_delete(struct PRESTypePlugin *);

/* The type used to store keys for instances of type struct
 * tapServerInfo.
 *
 * By default, this type is struct tapServerInfo
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct tapServerInfo)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct tapServerInfo, the
 * following restriction applies: the key of struct
 * tapServerInfo must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct tapServerInfo.
*/
typedef  struct tapServerInfo tapServerInfoKeyHolder;


#define tapServerInfoPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define tapServerInfoPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define tapServerInfoPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define tapServerInfoPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define tapServerInfoPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define tapServerInfoPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey
 

#define tapServerInfoPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define tapServerInfoPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern tapServerInfo*
tapServerInfoPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern tapServerInfo*
tapServerInfoPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
tapServerInfoPluginSupport_copy_data(
    tapServerInfo *out,
    const tapServerInfo *in);

NDDSUSERDllExport extern void 
tapServerInfoPluginSupport_destroy_data_ex(
    tapServerInfo *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
tapServerInfoPluginSupport_destroy_data(
    tapServerInfo *sample);

NDDSUSERDllExport extern void 
tapServerInfoPluginSupport_print_data(
    const tapServerInfo *sample,
    const char *desc,
    unsigned int indent);


NDDSUSERDllExport extern tapServerInfo*
tapServerInfoPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern tapServerInfo*
tapServerInfoPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
tapServerInfoPluginSupport_destroy_key_ex(
    tapServerInfoKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
tapServerInfoPluginSupport_destroy_key(
    tapServerInfoKeyHolder *key);
 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
tapServerInfoPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
tapServerInfoPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
tapServerInfoPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
tapServerInfoPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
tapServerInfoPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    tapServerInfo *out,
    const tapServerInfo *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
tapServerInfoPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const tapServerInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
tapServerInfoPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    tapServerInfo *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
tapServerInfoPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    tapServerInfo **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
tapServerInfoPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
tapServerInfoPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
tapServerInfoPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
tapServerInfoPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const tapServerInfo * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
tapServerInfoPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
tapServerInfoPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
tapServerInfoPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const tapServerInfo *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
tapServerInfoPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    tapServerInfo * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
tapServerInfoPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    tapServerInfo ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
tapServerInfoPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    tapServerInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
tapServerInfoPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    tapServerInfoKeyHolder *key, 
    const tapServerInfo *instance);

NDDSUSERDllExport extern RTIBool 
tapServerInfoPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    tapServerInfo *instance, 
    const tapServerInfoKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
tapServerInfoPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const tapServerInfo *instance);

NDDSUSERDllExport extern RTIBool 
tapServerInfoPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 
     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
tapServerInfoPlugin_new(void);

NDDSUSERDllExport extern void
tapServerInfoPlugin_delete(struct PRESTypePlugin *);

/* The type used to store keys for instances of type struct
 * tagProcessInfo.
 *
 * By default, this type is struct tagProcessInfo
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct tagProcessInfo)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct tagProcessInfo, the
 * following restriction applies: the key of struct
 * tagProcessInfo must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct tagProcessInfo.
*/
typedef  struct tagProcessInfo tagProcessInfoKeyHolder;


#define tagProcessInfoPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define tagProcessInfoPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define tagProcessInfoPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define tagProcessInfoPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define tagProcessInfoPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define tagProcessInfoPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey
 

#define tagProcessInfoPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define tagProcessInfoPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern tagProcessInfo*
tagProcessInfoPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern tagProcessInfo*
tagProcessInfoPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
tagProcessInfoPluginSupport_copy_data(
    tagProcessInfo *out,
    const tagProcessInfo *in);

NDDSUSERDllExport extern void 
tagProcessInfoPluginSupport_destroy_data_ex(
    tagProcessInfo *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
tagProcessInfoPluginSupport_destroy_data(
    tagProcessInfo *sample);

NDDSUSERDllExport extern void 
tagProcessInfoPluginSupport_print_data(
    const tagProcessInfo *sample,
    const char *desc,
    unsigned int indent);


NDDSUSERDllExport extern tagProcessInfo*
tagProcessInfoPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern tagProcessInfo*
tagProcessInfoPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
tagProcessInfoPluginSupport_destroy_key_ex(
    tagProcessInfoKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
tagProcessInfoPluginSupport_destroy_key(
    tagProcessInfoKeyHolder *key);
 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
tagProcessInfoPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
tagProcessInfoPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
tagProcessInfoPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
tagProcessInfoPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
tagProcessInfoPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagProcessInfo *out,
    const tagProcessInfo *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
tagProcessInfoPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const tagProcessInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
tagProcessInfoPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagProcessInfo *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
tagProcessInfoPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    tagProcessInfo **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
tagProcessInfoPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
tagProcessInfoPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
tagProcessInfoPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
tagProcessInfoPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const tagProcessInfo * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
tagProcessInfoPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
tagProcessInfoPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
tagProcessInfoPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const tagProcessInfo *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
tagProcessInfoPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagProcessInfo * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
tagProcessInfoPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    tagProcessInfo ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
tagProcessInfoPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    tagProcessInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
tagProcessInfoPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    tagProcessInfoKeyHolder *key, 
    const tagProcessInfo *instance);

NDDSUSERDllExport extern RTIBool 
tagProcessInfoPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    tagProcessInfo *instance, 
    const tagProcessInfoKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
tagProcessInfoPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const tagProcessInfo *instance);

NDDSUSERDllExport extern RTIBool 
tagProcessInfoPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 
     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
tagProcessInfoPlugin_new(void);

NDDSUSERDllExport extern void
tagProcessInfoPlugin_delete(struct PRESTypePlugin *);

/* The type used to store keys for instances of type struct
 * tagSpaceInfo.
 *
 * By default, this type is struct tagSpaceInfo
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct tagSpaceInfo)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct tagSpaceInfo, the
 * following restriction applies: the key of struct
 * tagSpaceInfo must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct tagSpaceInfo.
*/
typedef  struct tagSpaceInfo tagSpaceInfoKeyHolder;


#define tagSpaceInfoPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define tagSpaceInfoPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define tagSpaceInfoPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define tagSpaceInfoPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define tagSpaceInfoPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define tagSpaceInfoPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey
 

#define tagSpaceInfoPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define tagSpaceInfoPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern tagSpaceInfo*
tagSpaceInfoPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern tagSpaceInfo*
tagSpaceInfoPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
tagSpaceInfoPluginSupport_copy_data(
    tagSpaceInfo *out,
    const tagSpaceInfo *in);

NDDSUSERDllExport extern void 
tagSpaceInfoPluginSupport_destroy_data_ex(
    tagSpaceInfo *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
tagSpaceInfoPluginSupport_destroy_data(
    tagSpaceInfo *sample);

NDDSUSERDllExport extern void 
tagSpaceInfoPluginSupport_print_data(
    const tagSpaceInfo *sample,
    const char *desc,
    unsigned int indent);


NDDSUSERDllExport extern tagSpaceInfo*
tagSpaceInfoPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern tagSpaceInfo*
tagSpaceInfoPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
tagSpaceInfoPluginSupport_destroy_key_ex(
    tagSpaceInfoKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
tagSpaceInfoPluginSupport_destroy_key(
    tagSpaceInfoKeyHolder *key);
 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
tagSpaceInfoPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
tagSpaceInfoPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
tagSpaceInfoPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
tagSpaceInfoPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
tagSpaceInfoPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagSpaceInfo *out,
    const tagSpaceInfo *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
tagSpaceInfoPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const tagSpaceInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
tagSpaceInfoPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagSpaceInfo *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
tagSpaceInfoPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    tagSpaceInfo **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
tagSpaceInfoPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
tagSpaceInfoPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
tagSpaceInfoPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
tagSpaceInfoPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const tagSpaceInfo * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
tagSpaceInfoPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
tagSpaceInfoPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
tagSpaceInfoPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const tagSpaceInfo *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
tagSpaceInfoPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagSpaceInfo * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
tagSpaceInfoPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    tagSpaceInfo ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
tagSpaceInfoPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    tagSpaceInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
tagSpaceInfoPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    tagSpaceInfoKeyHolder *key, 
    const tagSpaceInfo *instance);

NDDSUSERDllExport extern RTIBool 
tagSpaceInfoPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    tagSpaceInfo *instance, 
    const tagSpaceInfoKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
tagSpaceInfoPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const tagSpaceInfo *instance);

NDDSUSERDllExport extern RTIBool 
tagSpaceInfoPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 
     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
tagSpaceInfoPlugin_new(void);

NDDSUSERDllExport extern void
tagSpaceInfoPlugin_delete(struct PRESTypePlugin *);

/* The type used to store keys for instances of type struct
 * tagServerInfo.
 *
 * By default, this type is struct tagServerInfo
 * itself. However, if for some reason this choice is not practical for your
 * system (e.g. if sizeof(struct tagServerInfo)
 * is very large), you may redefine this typedef in terms of another type of
 * your choosing. HOWEVER, if you define the KeyHolder type to be something
 * other than struct tagServerInfo, the
 * following restriction applies: the key of struct
 * tagServerInfo must consist of a
 * single field of your redefined KeyHolder type and that field must be the
 * first field in struct tagServerInfo.
*/
typedef  struct tagServerInfo tagServerInfoKeyHolder;


#define tagServerInfoPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define tagServerInfoPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define tagServerInfoPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define tagServerInfoPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define tagServerInfoPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define tagServerInfoPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey
 

#define tagServerInfoPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define tagServerInfoPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
    Support functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern tagServerInfo*
tagServerInfoPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern tagServerInfo*
tagServerInfoPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
tagServerInfoPluginSupport_copy_data(
    tagServerInfo *out,
    const tagServerInfo *in);

NDDSUSERDllExport extern void 
tagServerInfoPluginSupport_destroy_data_ex(
    tagServerInfo *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
tagServerInfoPluginSupport_destroy_data(
    tagServerInfo *sample);

NDDSUSERDllExport extern void 
tagServerInfoPluginSupport_print_data(
    const tagServerInfo *sample,
    const char *desc,
    unsigned int indent);


NDDSUSERDllExport extern tagServerInfo*
tagServerInfoPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern tagServerInfo*
tagServerInfoPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
tagServerInfoPluginSupport_destroy_key_ex(
    tagServerInfoKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
tagServerInfoPluginSupport_destroy_key(
    tagServerInfoKeyHolder *key);
 

/* ----------------------------------------------------------------------------
    Callback functions:
 * ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
tagServerInfoPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
tagServerInfoPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);
    
NDDSUSERDllExport extern PRESTypePluginEndpointData 
tagServerInfoPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
tagServerInfoPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern RTIBool 
tagServerInfoPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagServerInfo *out,
    const tagServerInfo *in);

/* --------------------------------------------------------------------------------------
    (De)Serialize functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
tagServerInfoPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const tagServerInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
tagServerInfoPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagServerInfo *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
tagServerInfoPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    tagServerInfo **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);



NDDSUSERDllExport extern RTIBool
tagServerInfoPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
tagServerInfoPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
tagServerInfoPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
tagServerInfoPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const tagServerInfo * sample);


/* --------------------------------------------------------------------------------------
    Key Management functions:
 * -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginKeyKind 
tagServerInfoPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
tagServerInfoPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
tagServerInfoPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const tagServerInfo *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
tagServerInfoPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    tagServerInfo * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
tagServerInfoPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    tagServerInfo ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);


NDDSUSERDllExport extern RTIBool
tagServerInfoPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    tagServerInfo *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

 
NDDSUSERDllExport extern RTIBool 
tagServerInfoPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    tagServerInfoKeyHolder *key, 
    const tagServerInfo *instance);

NDDSUSERDllExport extern RTIBool 
tagServerInfoPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    tagServerInfo *instance, 
    const tagServerInfoKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
tagServerInfoPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const tagServerInfo *instance);

NDDSUSERDllExport extern RTIBool 
tagServerInfoPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 
     
/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
tagServerInfoPlugin_new(void);

NDDSUSERDllExport extern void
tagServerInfoPlugin_delete(struct PRESTypePlugin *);

} /* namespace MONITORING */

        
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif        

#endif /* MonitoringPlugin_1808175700_h */
