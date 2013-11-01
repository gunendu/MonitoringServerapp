#include "includes.h"


extern CLogger g_cSystemLogger;

template<class CDataType, class CDataTypeSupport, class CDataTypeWriter>
CIPCPublisher<CDataType, CDataTypeSupport, CDataTypeWriter>::CIPCPublisher(const char* pcTopicName) : m_pcWriteTopic(NULL),
                                                                  m_pWriterHandle(NULL),
                                                                  m_pTopicSpecificWriter(NULL),
                                                                  m_pcWriteTypeName(NULL)
{
    assert(pcTopicName);
    DDS_ReturnCode_t lnRetCode = DDS_RETCODE_OK;
    DDSDomainParticipant* lpParticipant = CDDSInterface::GetDomainParticipant();
    
    if(NULL == lpParticipant)
    {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Fatal Error , NULL Pointer to DDS Handler", LOG_LOCATION);
        return;
    }
    
    
    m_pcWriteTypeName = CDataTypeSupport::get_type_name();
    g_cSystemLogger.LogMessage("(%s:%s:%d):: m_pcWriteTypename(%s), topic name(%s)", LOG_LOCATION, m_pcWriteTypeName, pcTopicName);
    lnRetCode = CDataTypeSupport::register_type(lpParticipant, m_pcWriteTypeName);
    if(lnRetCode != DDS_RETCODE_OK)
    {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: register type(%s) failed with error code(%d)", LOG_LOCATION, m_pcWriteTypeName, lnRetCode);
        m_pcWriteTypeName = NULL;
        return;
    }
    
    m_pcWriteTopic = lpParticipant->create_topic(pcTopicName, m_pcWriteTypeName, 
                                                 DDS_TOPIC_QOS_DEFAULT, 
                                                 NULL /* listener */,
                                                 DDS_STATUS_MASK_NONE);
    if (m_pcWriteTopic == NULL)
    {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Create Topic failed for topic name(%s)", LOG_LOCATION, pcTopicName);
        return;
    }
    
    g_cSystemLogger.LogMessage("(%s:%s:%d):: Create Topic successful for topic name(%s) ", LOG_LOCATION, pcTopicName);
}

template<class CDataType, class CDataTypeSupport, class CDataTypeWriter>
RET_CODE CIPCPublisher<CDataType, CDataTypeSupport, CDataTypeWriter>::CreateWriter(const char* pcLibraryName, const char* pcProfileName)
{
    assert(pcLibraryName);
    assert(pcProfileName);
    if (NULL == m_pcWriteTopic)
    {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Topic Handle is NULL ", LOG_LOCATION);
        return FAILURE;
    }

    if (NULL != m_pWriterHandle)
    {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Writer Handle is already created ", LOG_LOCATION);
        return FAILURE;
    }

    DDS_ReturnCode_t lnRetCode;
    DDSPublisher* lpcPublisher = CDDSInterface::GetPublisher();
    //Set writer qos profile from XML file
    lnRetCode = lpcPublisher->set_default_datawriter_qos_with_profile(pcLibraryName, pcProfileName);
    if (lnRetCode != DDS_RETCODE_OK)
    {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: set_default_datawriter_qos_with_profile failed with error code(%d) ", LOG_LOCATION, lnRetCode);
        return FAILURE;
    }

    DDS_DataWriterQos lstWriterQos;
    lnRetCode = lpcPublisher->get_default_datawriter_qos(lstWriterQos);
    if (lnRetCode != DDS_RETCODE_OK)
    {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: get_default_datawriter_qos failed with error code(%d) ", LOG_LOCATION, lnRetCode);
        return FAILURE;
    }
    /* Set writer QoS to publish asynchronously
     * RTI NOTE: In order to use the large data feature with the DDS_RELIABLE_RELIABILITY_QOS
     * setting, the DDSDataWriter must be configured as an asynchronous writer
     * with associated DDS_FlowController.
     */
    lstWriterQos.publish_mode.kind = DDS_ASYNCHRONOUS_PUBLISH_MODE_QOS;
    /* Use default flow controller.
     * RTI NOTES:
     * 1. Use DDS_String_dup() before passing the string to
     *    flow_controller_name, or reset flow_controller_name to NULL before
     * 2. You cannot change the properties of the default flow controller.
     *    The default flow controller sends your data as soon as possible.
     *    This may or may not be sufficient for your needs depending on your
     *    system constraints and requirements.
     */
    DDS_String_free(lstWriterQos.publish_mode.flow_controller_name);
    lstWriterQos.publish_mode.flow_controller_name = DDS_String_dup(DDS_DEFAULT_FLOW_CONTROLLER_NAME);
    /* NOTE: Samples queued for asynchronous write are subject to the History Qos policy! */

    /* Setup Asynchronous Writer here */
    /* To customize data writer QoS, use
       the configuration file USER_QOS_PROFILES.xml */
    /* RTI: MT Safety
     * UNSAFE. If DDS_DATAWRITER_QOS_DEFAULT is used for the qos parameter,
     * it is not safe to create the datawriter while another thread may be
     * simultaneously calling DDS_Publisher_set_default_datawriter_qos.
     * Currently, we don't set a listener here (assuming reader part will handle issues).
     */
    m_pWriterHandle = lpcPublisher->create_datawriter(m_pcWriteTopic, lstWriterQos, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (m_pWriterHandle == NULL)
    {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: create_datawriter_with_profile for Asynchronous Writer failed", LOG_LOCATION);
        return FAILURE;
    }
    // RTI NOTE: DDS_String_free() for the flow controller if the controller
    // is one of those provided by RTI (default,fixed rate or on demand).

    m_pTopicSpecificWriter = CDataTypeWriter::narrow(m_pWriterHandle);
    if (m_pTopicSpecificWriter == NULL)
    {
        
        g_cSystemLogger.LogMessage("(%s:%s:%d):: create_narrow writer failed for Asynchronous Writer", LOG_LOCATION);
        return FAILURE;
    }
    
    g_cSystemLogger.LogMessage("(%s:%s:%d):: SUCCESS", LOG_LOCATION);

    return SUCCESS;
}

template<class CDataType, class CDataTypeSupport, class CDataTypeWriter>
RET_CODE CIPCPublisher<CDataType, CDataTypeSupport, CDataTypeWriter>::SendData(CDataType& stDataType)
{
    /* Write data */
    /* RTI NOTES:
     * - This operation may block if the RELIABILITY kind is set to
     *   DDS_RELIABLE_RELIABILITY_QOS and the modification would cause data to be lost
     *   or else cause one of the limits specified in the RESOURCE_LIMITS to be exceeded.
     * - This operation may also block when using DDS_BEST_EFFORT_RELIABILITY_QOS and
     *   DDS_ASYNCHRONOUS_PUBLISH_MODE_QOS. In this case, the DDS_DataWriter will queue
     *   samples until they are sent by the asynchronous publishing thread. The number
     *   of samples that can be stored is determined by the DDS_HistoryQosPolicy.
     *   If the asynchronous thread does not send samples fast enough (e.g., when using
     *   a slow DDS_FlowController), the queue may fill up. In that case, subsequent
     *   write calls will block.
     *   If this operation does block for any reasons, the RELIABILITY max_blocking_time
     *   configures the maximum time the write operation may block (waiting for space to
     *   become available). If max_blocking_time elapses before the DDS_DataWriter is able
     *   to store the modification without exceeding the limits, the operation will time
     *   out (DDS_RETCODE_TIMEOUT).
     */
    DDS_ReturnCode_t lnRetCode = m_pTopicSpecificWriter->write(stDataType, DDS_HANDLE_NIL);
    if (DDS_RETCODE_OK != lnRetCode)
    {
        /* WARNING: Ensure that we don't timeout easily
         * (max_blocking_time to be set appropriately).
         * TBD: For now we assume limited timeout (to be tuned?)
         * NOTE: We assume that we are using KEEP_ALL_HISTORY QOS
         * for RELIABLE writer (and reader) and that new joiner readers
         * REQUIRE all data ever published by this writer.
         */

        g_cSystemLogger.LogMessage("(%s:%s:%d):: Write failed with error code(%d)", LOG_LOCATION, lnRetCode);
        /* Although we can't miss publishing any sample, we abort here since
         * this we have reached here due to serious RTI failure.
         */
        return FAILURE;
    }
#ifdef DEBUG_LOG    
    CDataTypeSupport::print_data(&stDataType);
#endif
    return SUCCESS;
}

template<class CDataType, class CDataTypeSupport, class CDataTypeWriter>
CIPCPublisher<CDataType, CDataTypeSupport, CDataTypeWriter>::~CIPCPublisher()
{

    DDSDomainParticipant* lpParticipant = CDDSInterface::GetDomainParticipant();
    DDS_ReturnCode_t lnRetCode = DDS_RETCODE_OK;



    if (NULL != m_pWriterHandle)
    {
        /* Wait for Asynchronous write ACK's (wrapper)
         * Check if the sample was sent and acknowledged by the reliable
         * data reader, by waiting for specified time period.
         */
        const DDS_Duration_t timeout = {300, 0};
        /* Wait for maximum possible time for all asynch. writes
         * to be ACK'ed by readers.
         * TBD: For now we wait for 5 mins (to be tuned?).
         * NOTE: We do this during RTI cleanup since the
         * asynchronous publisher thread is internal to RTI
         * We don't check for return value here since
         * application doesn't consider this a data loss.
         * Otherwise we may have to re-try which may block
         * the cleanup activities.
         */
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Waiting (for %d secs, %d nanosecs) for Asynchronous write ACK's...", LOG_LOCATION, timeout.sec, timeout.nanosec);

        lnRetCode = m_pWriterHandle->wait_for_asynchronous_publishing(timeout);
        if (DDS_RETCODE_OK != lnRetCode)
        {
            g_cSystemLogger.LogMessage("(%s:%s:%d):: Writer's wait_for_asynchronous_publishing error(%d)", lnRetCode);
        }
        
        if (DDS_RETCODE_OK != CDDSInterface::GetPublisher()->delete_datawriter(m_pWriterHandle))
        {
            g_cSystemLogger.LogMessage("(%s:%s:%d)::Unable to delete m_pWriterHandle(%p)", LOG_LOCATION, m_pWriterHandle);
        }
        
        m_pWriterHandle = NULL;
    }
    
    if (NULL != m_pcWriteTopic)
    {
        if (DDS_RETCODE_OK != lpParticipant->delete_topic(m_pcWriteTopic))
        {
            g_cSystemLogger.LogMessage("(%s:%s:%d):: Unable to delete m_pcWriteTopic (%p)", m_pcWriteTopic);
        }
        m_pcWriteTopic = NULL;
    }

    // Un-register the type...
    if ((NULL != lpParticipant) && (NULL != m_pcWriteTypeName))
    {
        lnRetCode = CDataTypeSupport::unregister_type(lpParticipant, m_pcWriteTypeName);
        if (DDS_RETCODE_OK != lnRetCode)
        {
            g_cSystemLogger.LogMessage("(%s:%s:%d):: unregister_type(%s), error(%d)",m_pcWriteTypeName, lnRetCode);
        }
        
        //WARNING: Not unregistering this type since already in use by OMS, so need to do only once!
        //		retcode = OMS::orderTypeSupport::unregister_type(participant, m_type_name_write);
        //		if (retcode != DDS_RETCODE_OK)
        //		{
        //			fprintf(fp_ui,"Error ---> MNLUIConn() unregister_type_write  UI Conn error\n");
        //		}
        m_pcWriteTypeName = NULL;
    }
    
    m_pTopicSpecificWriter = NULL;
}


template class CIPCPublisher<MONITORING::tagServerInfo, MONITORING::tagServerInfoTypeSupport,
    MONITORING::tagServerInfoDataWriter>;

template class CIPCPublisher<MONITORING::tapServerInfo, MONITORING::tapServerInfoTypeSupport,
            MONITORING::tapServerInfoDataWriter>;


template class CIPCPublisher<MONITORING::pslInfo, MONITORING::pslInfoTypeSupport,
            MONITORING::pslInfoDataWriter>;