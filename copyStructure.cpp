#include "includes.h"

extern CLogger g_cSystemLogger;

CcopyStructure::CcopyStructure() {

}

CcopyStructure::~CcopyStructure() {

}

RET_CODE CcopyStructure::copyAdapterData(tapServerInfo& adapterInfo, int lcounter) {
    MONITORING::tapServerInfo lstTapServerInfo;
    MONITORING::tapServerInfoTypeSupport::initialize_data_ex(&lstTapServerInfo, true);
    lstTapServerInfo.ipv4Address = adapterInfo.ipAdress;
    if (adapterInfo.serverStatus == 1) {
        lstTapServerInfo.status = MONITORING::ON;
    }
    if (DDS_BOOLEAN_FALSE == lstTapServerInfo.line_info.ensure_length(12, 12)) {

        return FAILURE;
    }

    for (int lnCounter = 0; lnCounter < lcounter; lnCounter++) {
        lstTapServerInfo.line_info[lnCounter].ipadress = adapterInfo.lineInfo[lnCounter].ipv4adresss;
        std::cout << "line ip ::" << lstTapServerInfo.line_info[lnCounter].ipadress << std::endl;
        lstTapServerInfo.line_info[lnCounter].lineId = adapterInfo.lineInfo[lnCounter].userId;
        std::cout << "line Id ::" << lstTapServerInfo.line_info[lnCounter].lineId << std::endl;

        if (adapterInfo.lineInfo[lnCounter].status == 1) {
            lstTapServerInfo.line_info[lnCounter].status = MONITORING::UP;
            std::cout << " status ::" << lstTapServerInfo.line_info[lnCounter].status << std::endl;
        } else {
            lstTapServerInfo.line_info[lnCounter].status = MONITORING::DOWN;
            std::cout << "status ::" << lstTapServerInfo.line_info[lnCounter].status << std::endl;
        }


        if (strcmp(adapterInfo.lineType, "CM") == 0) {
            lstTapServerInfo.line_info[lnCounter].linetype = MONITORING::CM;

        }

        if (strcmp(adapterInfo.lineType, "FO") == 0) {
            lstTapServerInfo.line_info[lnCounter].linetype = MONITORING::FO;

        }

        if (strcmp(adapterInfo.lineType, "CM FO") == 0) {
            lstTapServerInfo.line_info[lnCounter].linetype = MONITORING::CMFO;
        }

        if (strcmp(adapterInfo.lineType, "BSE") == 0) {
            lstTapServerInfo.line_info[lnCounter].linetype = MONITORING::BSE;
        }

        std::cout << "line Type ::" << lstTapServerInfo.line_info[lnCounter].linetype << std::endl;


    }


    if (FAILURE == CControllerThread::getInstance()->SendAdapterDataToUI(lstTapServerInfo)) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Send data failed ", LOG_LOCATION);
    }

    lstTapServerInfo.ipv4Address = NULL;
    for (int lnCounter = 0; lnCounter < lcounter; lnCounter++) {
        lstTapServerInfo.line_info[lnCounter].ipadress = NULL;
    }
    MONITORING::tapServerInfoTypeSupport::finalize_data_ex(&lstTapServerInfo, true);
    return SUCCESS;
}

RET_CODE CcopyStructure::copyData(tagServerInfo &tsi, int lProcessList, int lSpaceList, int lineCount) {

    MONITORING::tagServerInfo lstMonitoringInfo;
    MONITORING::tagServerInfoTypeSupport::initialize_data_ex(&lstMonitoringInfo, true);

    lstMonitoringInfo.ipv4Address = tsi.ipAdress;
    g_cSystemLogger.LogMessage("(:%s:%s(:%d))name %s", LOG_LOCATION, lstMonitoringInfo.ipv4Address);
    if (tsi.serverstatus == true) {
        lstMonitoringInfo.serverStatus = MONITORING::ON;
    } else {
        lstMonitoringInfo.serverStatus = MONITORING::OFF;
    }

    g_cSystemLogger.LogMessage("(:%s:%s(:%d))ipadress %s", LOG_LOCATION, lstMonitoringInfo.ipv4Address);

    if (DDS_BOOLEAN_FALSE == lstMonitoringInfo.process_list.ensure_length(lProcessList, 100)) {

        return FAILURE;
    }
	
    //for(int lncounter=1;lncounter < filePath;lncounter++)
	
	if (!(strcmp(tsi.Path[0].filePath,"") == 0)) 
	{	        
	lstMonitoringInfo.Logpath=tsi.Path[0].filePath;        
        if(tsi.Path[0].status==1)
        {
        lstMonitoringInfo.status=MONITORING::ON;
        }
        else
        {
        lstMonitoringInfo.status=MONITORING::OFF;    
        }
	g_cSystemLogger.LogMessage("(:%s:%s(:%d))filestatus %d", LOG_LOCATION,lstMonitoringInfo.status);
   	}

    for (int lnCounter = 1; lnCounter < lProcessList; lnCounter++) {
        lstMonitoringInfo.process_list[lnCounter].name = tsi.processes[lnCounter].name;

        g_cSystemLogger.LogMessage("(:%s:%s(:%d))process name :: %s", LOG_LOCATION, lstMonitoringInfo.process_list[lnCounter].name);
        if (tsi.processes[lnCounter].process_on_off == 1) {
            lstMonitoringInfo.process_list[lnCounter].state = MONITORING::ON;
        } else {
            lstMonitoringInfo.process_list[lnCounter].state = MONITORING::OFF;
        }
       // g_cSystemLogger.LogMessage("(:%s:%s(:%d))name %s", LOG_LOCATION, lstMonitoringInfo.process_list[lnCounter].name);
       // g_cSystemLogger.LogMessage("(:%s:%s(:%d))state %d", LOG_LOCATION, lstMonitoringInfo.process_list[lnCounter].state);
    }

    if (DDS_BOOLEAN_FALSE == lstMonitoringInfo.space_list.ensure_length(lSpaceList, 32)) {

        return FAILURE;
    }

    for (int lscounter = 1; lscounter < lSpaceList; lscounter++) {
        g_cSystemLogger.LogMessage("(:%s:%s(:%d))state %s", LOG_LOCATION, tsi.space[lscounter].name);
        lstMonitoringInfo.space_list[lscounter].name = tsi.space[lscounter].name;

        if (tsi.space[lscounter].space_full == 1) {
            lstMonitoringInfo.space_list[lscounter].is_space_full = MONITORING::ON;
        } else {
            lstMonitoringInfo.space_list[lscounter].is_space_full = MONITORING::OFF;
        }
    }

    if (DDS_BOOLEAN_FALSE == lstMonitoringInfo.line_info.ensure_length(lineCount, 100)) {

        return FAILURE;
    }


    for (int lcounter = 0; lcounter < lineCount; lcounter++) {

        lstMonitoringInfo.line_info[lcounter].ipadress = tsi.lineInfo[lcounter].ipv4adresss;
        lstMonitoringInfo.line_info[lcounter].lineId = tsi.lineInfo[lcounter].userId;
        g_cSystemLogger.LogMessage("(:%s:%s(:%d))LineIp %s", LOG_LOCATION, lstMonitoringInfo.line_info[lcounter].ipadress);
        if (tsi.lineInfo[lcounter].status == 1) {

            lstMonitoringInfo.line_info[lcounter].status = MONITORING::UP;
        } else {
            lstMonitoringInfo.line_info[lcounter].status = MONITORING::DOWN;
        }

        if (strcmp(tsi.lineType, "CM") == 0) {
            lstMonitoringInfo.line_info[lcounter].linetype = MONITORING::CM;
        }
        else {
            lstMonitoringInfo.line_info[lcounter].linetype = MONITORING::FO;
        }
       // g_cSystemLogger.LogMessage("(:%s:%s(:%d))ipadress %s", LOG_LOCATION,lstMonitoringInfo.line_info[lcounter].ipadress);
	//g_cSystemLogger.LogMessage("(:%s:%s(:%d))lineId %d", LOG_LOCATION,lstMonitoringInfo.line_info[lcounter].lineId);
        //g_cSystemLogger.LogMessage("(:%s:%s(:%d))status %d", LOG_LOCATION,lstMonitoringInfo.line_info[lcounter].status);



    }
    if (FAILURE == CControllerThread::getInstance()->SendDataToUI(lstMonitoringInfo)) 
    {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Send data failed ", LOG_LOCATION);
    }


    lstMonitoringInfo.ipv4Address = NULL;
    for (int lnCounter = 1; lnCounter < lProcessList; lnCounter++) {
        lstMonitoringInfo.process_list[lnCounter].name = NULL;
    }
    for (int lscounter = 1; lscounter < lSpaceList; lscounter++) {

        lstMonitoringInfo.space_list[lscounter].name = NULL;
    }

    for (int lcounter = 0; lcounter < lineCount; lcounter++) {

        lstMonitoringInfo.line_info[lcounter].ipadress = NULL;
    }

    if (!(strcmp(tsi.Path[0].filePath,"") == 0))
    	lstMonitoringInfo.Logpath=NULL;
    
    MONITORING::tagServerInfoTypeSupport::finalize_data_ex(&lstMonitoringInfo, true);

    return 1;

}

RET_CODE CcopyStructure::copyCommandData(lineDetails &ld,int number) 
{
    MONITORING::pslInfo pslData;
    MONITORING::pslInfoTypeSupport::initialize_data_ex(&pslData, true);
    pslData.ipadress=ld.ipadress;
    g_cSystemLogger.LogMessage("(:%s:%s(:%d))ipadress %s", LOG_LOCATION, pslData.ipadress);
    strncpy(pslData.processInfo,ld.processInfo,sizeof(ld.processInfo));
    g_cSystemLogger.LogMessage("(:%s:%s(:%d))processInfo %s \n", LOG_LOCATION, pslData.processInfo);
    strncpy(pslData.spaceInfo,ld.spaceInfo,sizeof(ld.spaceInfo));
    g_cSystemLogger.LogMessage("(:%s:%s(:%d))spaceInfo %s number %d\n", LOG_LOCATION, pslData.spaceInfo,number);
     if (DDS_BOOLEAN_FALSE == pslData.lineInfo.ensure_length(12, 12)) 
     {

        return FAILURE;
     }
    
    for(int i=0;i<number;i++)
    {
        pslData.lineInfo[i].line_id=ld.ld[i].fo_id;
        g_cSystemLogger.LogMessage("(:%s:%s(:%d))line_id %d \n", LOG_LOCATION, pslData.lineInfo[i].line_id);
        pslData.lineInfo[i].product_details=ld.ld[i].product_details;
        g_cSystemLogger.LogMessage("(:%s:%s(:%d))Product Details %s \n", LOG_LOCATION, pslData.lineInfo[i].product_details);
    }

    
    strncpy(pslData.cancelOrderStatus,ld.CancelOrderStatus,sizeof(ld.CancelOrderStatus));
    if (FAILURE == CControllerThread::getInstance()->SendcommandDataToUI(pslData)) 
    {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Send data failed ", LOG_LOCATION);
    }
    
    pslData.ipadress=NULL;
    pslData.processInfo=NULL;
    pslData.spaceInfo=NULL;
    for(int i=0;i<number;i++)
    {
        pslData.lineInfo[i].product_details=NULL;
    }
    MONITORING::pslInfoTypeSupport::finalize_data_ex(&pslData,true);
        
}

