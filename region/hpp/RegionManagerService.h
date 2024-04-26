
/**
 * @attention Copyright (c) 2015 by LG electronics co, Ltd. All rights reserved.
 *   This program or software including the accompanying associated documentation ("Software") is
 *   the proprietary software of LG Electronics Inc.  and or its licensors, and may only be used,
 *   duplicated, modified or distributed pursuant to the terms and conditions of a separate written license agreement
 *   between you and LG Electronics Inc. ("Authorized License").
 *   Except as set forth in an Authorized License, LG Electronics Inc. grants no license (express or implied), rights to use,
 *   or waiver of any kind with respect to the Software, and LG Electronics Inc. expressly reserves all rights in
 *   and to the Software and all intellectual property therein.
 *   If you have no Authorized License, then you have no rights to use the Software in any ways,
 *   and should immediately notify LG Electronics Inc. and discontinue all use of the Software.
 *
 * @author  logan.kim@lge.com
 * @date    2023.07.13
 * @version 3.0.00
 *
 *
 *  This is the Region Manager Service. This class includes all native functions.
 *  - APIs ( native codes )
 *
 * @cond UML
 * Basic Process about API using binder
 * @startuml
 *     box "Application (Proxy)"
 *     participant App
 *     participant BpRegionManagerService
 *     end box
 *     participant Binder
 *     box "Service (Native)"
 *     participant BnRegionManagerService
 *     participant ServiceStub
 *     end box
 *
 *     App -> BpRegionManagerService : API(arguments)
 *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_API, Parcel)
 *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_API, Parcel >> arguments
 *     BnRegionManagerService -> ServiceStub : API(arguments)
 *     activate ServiceStub
 *     BnRegionManagerService <- ServiceStub : return E_OK
 *     deactivate ServiceStub
 *     Binder <- BnRegionManagerService : reply->writeInt32
 *     BpRegionManagerService <- Binder : reply.readInt32()
 *     App <- BpRegionManagerService : return
 * @enduml
 * @endcond
 *
 */


#ifndef _SERVICELAYER_REGIONNOSTIC_MANAGER_SERVICE_H_
#define _SERVICELAYER_REGIONNOSTIC_MANAGER_SERVICE_H_

#include <map>
#include <list>
#include <vector>
#include <tuple>
#include <algorithm>

#include <Typedef.h>
#include <corebase/SystemService.h>

#include "RegionInputManager.h"

#include "services/RegionManagerService/RegionCommand.h"
//#include "../include/IRegionManagerReceiver.h"
#include "services/RegionManagerService/IRegionManagerService.h"

#ifndef MODULE_REGION_MGR
#define MODULE_REGION_MGR 100
#endif

// @CGA_VARIANT_START{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}
/*
 * Write your own additional code
 * add your #include
 * add your global declare the function and variables
 * add your function
 */
// @CGA_VARIANT___END{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}

/**
 * @brief RegionManagerService is class to serive APIs for application and another services.
 *
 * @cond UML
 * Basic Process about API using binder
 * @startuml
 *     box "Application (Proxy)"
 *     participant App
 *     participant BpRegionManagerService
 *     end box
 *     participant Binder
 *     box "Service (Native)"
 *     participant BnRegionManagerService
 *     participant ServiceStub
 *     end box
 *
 *     App -> BpRegionManagerService : API(arguments)
 *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_API, Parcel)
 *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_API, Parcel >> arguments
 *     BnRegionManagerService -> ServiceStub : API(arguments)
 *     activate ServiceStub
 *     BnRegionManagerService <- ServiceStub : return E_OK
 *     deactivate ServiceStub
 *     Binder <- BnRegionManagerService : reply->writeInt32
 *     BpRegionManagerService <- Binder : reply.readInt32()
 *     App <- BpRegionManagerService : return
 * @enduml
 * @endcond
 */
class RegionManagerService: public SystemService
{
public:
    /**
     * @brief It is the constructor function of RegionManagerService.
     *
     * @retval void
     *
     */
    RegionManagerService();
    /**
     * @brief It is the destructor function of RegionManagerService.
     *
     * @retval void
     *
     */
    virtual ~RegionManagerService();

    /**
     * @brief This function gets service name.
     *
     * @retval   service_layer.RegionManagerService service name
     *
     */
    static const int8_t* getServiceName() { return "service_layer.RegionManagerService"; }

    /**
     * @brief This function gets module ID.
     *
     * @retval   MODULE_REGION module ID
     *
     */
    virtual uint8_t getModuleID() {
        return MODULE_REGION_MGR;
    }

    /**
     * @brief It is the function to onInit for the RegionManagerService.
     *
     * @retval   bool
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService:onInit"}
     * @details
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService:onInit"}
     */
    virtual bool onInit();
    /**
     * @brief It is the function to instantiate for the RegionManagerService.
     *
     * @retval   void
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService:instantiate"}
     * @details
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService:instantiate"}
     */
    virtual void instantiate();
    /**
     * @brief It is the function to onStart for the RegionManagerService.
     *
     * @retval   error_t   E_OK is returned if this function works properly, otherwise return E_ERROR.
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService:onStart"}
     * @details
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService:onStart"}
     */
    virtual error_t onStart();
    /**
     * @brief It is the function to onStop for the RegionManagerService.
     *
     * @retval   error_t   E_OK is returned if this function works properly, otherwise return E_ERROR.
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService:onStop"}
     * @details
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService:onStop"}
     */
    virtual error_t onStop();
    /**
     * @brief It is the function to dump for the RegionManagerService.
     *
     * @param[in] Data   data for dump
     * @retval   error_t E_OK is returned if this function works properly, otherwise return E_ERROR.
     *
     */
    virtual error_t dump(LogOutput&);




    /**
     * @brief It is the function to check registered receivers for the RegionManagerService.
     *
     * @param[in] id application id
     * @retval   bool
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService:isApplicationExecuted"}
     * @details
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService:isApplicationExecuted"}
     */
    bool isApplicationExecuted(appid_t id);

    /**
     * @brief It is the function to reconnect registered receivers for the RegionManagerService.
     *
     * @param[in] who   who sends death state.
     * @retval   void
     *
     */
    void onReceiverBinderDied(const android::wp<android::IBinder>& who);

    /**
     * @brief setLogLevel sets the log level for region module separately.
     *
     * @details dynamic log level - each module can set log level separately.
     *
     * @param[in] lvl int32_t : set log level
     *
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpRegionManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == setLogLevel ==
     *     App -> BpRegionManagerService : setLogLevel(lvl)
     *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_setLogLevel, Parcel)
     *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_setLogLevel, Parcel >> lvl
     *     BnRegionManagerService -> ServiceStub : setLogLevel(lvl)
     *     activate ServiceStub
     *     BnRegionManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnRegionManagerService : reply->writeInt32
     *     BpRegionManagerService <- Binder : reply.readInt32()
     *     App <- BpRegionManagerService : return
     * @enduml
     * @endcond
     */
    error_t setLogLevel(int32_t lvl);
    /**
     * @brief setLogLevelAsDefault sets the log level according to perf and debug mode.
     *
     * @details dynamic log level - set log level as default log level according to perf and debug mode
     *
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpRegionManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == setLogLevelAsDefault ==
     *     App -> BpRegionManagerService : setLogLevelAsDefault()
     *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_setLogLevelAsDefault, Parcel)
     *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_setLogLevelAsDefault, Parcel
     *     BnRegionManagerService -> ServiceStub : setLogLevelAsDefault()
     *     activate ServiceStub
     *     BnRegionManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnRegionManagerService : reply->writeInt32
     *     BpRegionManagerService <- Binder : reply.readInt32()
     *     App <- BpRegionManagerService : return
     * @enduml
     * @endcond
     */
    error_t setLogLevelAsDefault();
    /**
     * @brief getLogLevel gets the log level for region module separately.
     *
     * @details dynamic log level - get log level of each module separately.
     *
     * @param[out] lvl int32_t& : get log level
     *
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpRegionManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == getLogLevel ==
     *     App -> BpRegionManagerService : getLogLevel(lvl)
     *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_getLogLevel, Parcel)
     *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_getLogLevel, Parcel >> lvl
     *     BnRegionManagerService -> ServiceStub : getLogLevel(lvl)
     *     activate ServiceStub
     *     BnRegionManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnRegionManagerService : reply->writeInt32
     *     BpRegionManagerService <- Binder : reply.readInt32()
     *     App <- BpRegionManagerService : return
     * @enduml
     * @endcond
     */
    error_t getLogLevel(int32_t& lvl);

    // auto API start : wishtoUseAPI
    /**
     *
     * @brief API : Request to get boot mode information in hal system. This api get the boot mode information via hal_system.
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[out] bootMode  boot Mode to get information by reference
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpRegionManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == Request to get boot mode information in hal system. This api get the boot mode information via hal_system. ==
     *     App -> BpRegionManagerService : getHalSystemBootMode(arguments)
     *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETHALSYSTEMBOOTMODE, Parcel)
     *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_GETHALSYSTEMBOOTMODE, Parcel >> arguments
     *     BnRegionManagerService -> ServiceStub : getHalSystemBootMode(arguments)
     *     activate ServiceStub
     *     BnRegionManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnRegionManagerService : reply->writeInt32
     *     BpRegionManagerService <- Binder : reply.readInt32()
     *     App <- BpRegionManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService::getHalSystemBootMode()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService::getHalSystemBootMode()_SRS"}
     * @endcond
     */
    error_t getHalSystemBootMode(
         uint32_t& bootMode
        );
    /**
     *
     * @brief API : Request to get nation information in hal system. This api get the nation information via hal_system.
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[out] halNation  nation to get information by reference
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpRegionManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == Request to get nation information in hal system. This api get the nation information via hal_system. ==
     *     App -> BpRegionManagerService : getHalSystemNation(arguments)
     *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETHALSYSTEMNATION, Parcel)
     *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_GETHALSYSTEMNATION, Parcel >> arguments
     *     BnRegionManagerService -> ServiceStub : getHalSystemNation(arguments)
     *     activate ServiceStub
     *     BnRegionManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnRegionManagerService : reply->writeInt32
     *     BpRegionManagerService <- Binder : reply.readInt32()
     *     App <- BpRegionManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService::getHalSystemNation()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService::getHalSystemNation()_SRS"}
     * @endcond
     */
    error_t getHalSystemNation(
         uint32_t& halNation
        );
    /**
     *
     * @brief API : region information from NAD related to mcfg(modem config)
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[out] mcfgRegion  region from NAD related to mcfg
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpRegionManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == region information from NAD related to mcfg(modem config) ==
     *     App -> BpRegionManagerService : getMcfgRegion(arguments)
     *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETMCFGREGION, Parcel)
     *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_GETMCFGREGION, Parcel >> arguments
     *     BnRegionManagerService -> ServiceStub : getMcfgRegion(arguments)
     *     activate ServiceStub
     *     BnRegionManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnRegionManagerService : reply->writeInt32
     *     BpRegionManagerService <- Binder : reply.readInt32()
     *     App <- BpRegionManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService::getMcfgRegion()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService::getMcfgRegion()_SRS"}
     * @endcond
     */
    error_t getMcfgRegion(
         uint8_t& mcfgRegion
        );
    /**
     *
     * @brief API : Request NAD region information. This api get the NAD information via Telephony and parse the data and then give NAD region enum value.
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[out] nadRegion  enum variable of region to be get by reference
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpRegionManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == Request NAD region information. This api get the NAD information via Telephony and parse the data and then give NAD region enum value. ==
     *     App -> BpRegionManagerService : getNADRegion(arguments)
     *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETNADREGION, Parcel)
     *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_GETNADREGION, Parcel >> arguments
     *     BnRegionManagerService -> ServiceStub : getNADRegion(arguments)
     *     activate ServiceStub
     *     BnRegionManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnRegionManagerService : reply->writeInt32
     *     BpRegionManagerService <- Binder : reply.readInt32()
     *     App <- BpRegionManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService::getNADRegion()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService::getNADRegion()_SRS"}
     * @endcond
     */
    error_t getNADRegion(
         uint8_t& nadRegion
        );
    /**
     *
     * @brief API : Request NAD HW revision information.This api get the NAD information via Telephony and parse the data and then give NAD HW revision enum value.
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[out] nadRevision  enum variable of revision to be get by reference
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpRegionManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == Request NAD HW revision information.This api get the NAD information via Telephony and parse the data and then give NAD HW revision enum value. ==
     *     App -> BpRegionManagerService : getNADRevision(arguments)
     *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETNADREVISION, Parcel)
     *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_GETNADREVISION, Parcel >> arguments
     *     BnRegionManagerService -> ServiceStub : getNADRevision(arguments)
     *     activate ServiceStub
     *     BnRegionManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnRegionManagerService : reply->writeInt32
     *     BpRegionManagerService <- Binder : reply.readInt32()
     *     App <- BpRegionManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService::getNADRevision()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService::getNADRevision()_SRS"}
     * @endcond
     */
    error_t getNADRevision(
         uint8_t& nadRevision
        );
    /**
     *
     * @brief API : Request NAD type information. This api get the NAD information via Telephony and parse the data and then give NAD type enum value.
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[out] nadType  enum variable of type to be get by reference
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpRegionManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == Request NAD type information. This api get the NAD information via Telephony and parse the data and then give NAD type enum value. ==
     *     App -> BpRegionManagerService : getNADType(arguments)
     *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETNADTYPE, Parcel)
     *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_GETNADTYPE, Parcel >> arguments
     *     BnRegionManagerService -> ServiceStub : getNADType(arguments)
     *     activate ServiceStub
     *     BnRegionManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnRegionManagerService : reply->writeInt32
     *     BpRegionManagerService <- Binder : reply.readInt32()
     *     App <- BpRegionManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService::getNADType()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService::getNADType()_SRS"}
     * @endcond
     */
    error_t getNADType(
         uint8_t& nadType
        );
    /**
     *
     * @brief API : Request to get parsed nation information in hal system. This api get the parsed nation information via hal_system.
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[out] nation  nation to get parsed information by reference
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpRegionManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == Request to get parsed nation information in hal system. This api get the parsed nation information via hal_system. ==
     *     App -> BpRegionManagerService : getNation(arguments)
     *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETNATION, Parcel)
     *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_GETNATION, Parcel >> arguments
     *     BnRegionManagerService -> ServiceStub : getNation(arguments)
     *     activate ServiceStub
     *     BnRegionManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnRegionManagerService : reply->writeInt32
     *     BpRegionManagerService <- Binder : reply.readInt32()
     *     App <- BpRegionManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService::getNation()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService::getNation()_SRS"}
     * @endcond
     */
    error_t getNation(
         uint8_t& nation
        );
    /**
     *
     * @brief API : get variant data
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[out] variantData  to be get as variant data
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpRegionManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == get variant data ==
     *     App -> BpRegionManagerService : getVariantData(arguments)
     *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETVARIANTDATA, Parcel)
     *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_GETVARIANTDATA, Parcel >> arguments
     *     BnRegionManagerService -> ServiceStub : getVariantData(arguments)
     *     activate ServiceStub
     *     BnRegionManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnRegionManagerService : reply->writeInt32
     *     BpRegionManagerService <- Binder : reply.readInt32()
     *     App <- BpRegionManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService::getVariantData()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService::getVariantData()_SRS"}
     * @endcond
     */
    error_t getVariantData(
         android::sp< EnvironmentVariant >& variantData
        );
    /**
     *
     * @brief API : Receives the delete request for the created file and deletes the specified file.
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[in] file_path_length Length of file_path
     * @param[in] file_path  to delete file path information
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpRegionManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == Receives the delete request for the created file and deletes the specified file. ==
     *     App -> BpRegionManagerService : memoryFileDelete(arguments)
     *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_MEMORYFILEDELETE, Parcel)
     *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_MEMORYFILEDELETE, Parcel >> arguments
     *     BnRegionManagerService -> ServiceStub : memoryFileDelete(arguments)
     *     activate ServiceStub
     *     BnRegionManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnRegionManagerService : reply->writeInt32
     *     BpRegionManagerService <- Binder : reply.readInt32()
     *     App <- BpRegionManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService::memoryFileDelete()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService::memoryFileDelete()_SRS"}
     * @endcond
     */
    error_t memoryFileDelete(
         size_t& file_path_length
        , uint8_t* file_path
        );
    /**
     *
     * @brief API : Request to set boot mode information in hal system. This api set the boot mode information via hal_system.
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[in] bootMode  boot Mode to be set
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpRegionManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == Request to set boot mode information in hal system. This api set the boot mode information via hal_system. ==
     *     App -> BpRegionManagerService : setHalSystemBootMode(arguments)
     *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_SETHALSYSTEMBOOTMODE, Parcel)
     *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_SETHALSYSTEMBOOTMODE, Parcel >> arguments
     *     BnRegionManagerService -> ServiceStub : setHalSystemBootMode(arguments)
     *     activate ServiceStub
     *     BnRegionManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnRegionManagerService : reply->writeInt32
     *     BpRegionManagerService <- Binder : reply.readInt32()
     *     App <- BpRegionManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService::setHalSystemBootMode()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService::setHalSystemBootMode()_SRS"}
     * @endcond
     */
    error_t setHalSystemBootMode(
         uint32_t& bootMode
        );
    /**
     *
     * @brief API : Request to set nation information in hal system. This api set the nation information via hal_system.
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[in] halNation  nation to be set
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpRegionManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == Request to set nation information in hal system. This api set the nation information via hal_system. ==
     *     App -> BpRegionManagerService : setHalSystemNation(arguments)
     *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_SETHALSYSTEMNATION, Parcel)
     *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_SETHALSYSTEMNATION, Parcel >> arguments
     *     BnRegionManagerService -> ServiceStub : setHalSystemNation(arguments)
     *     activate ServiceStub
     *     BnRegionManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnRegionManagerService : reply->writeInt32
     *     BpRegionManagerService <- Binder : reply.readInt32()
     *     App <- BpRegionManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService::setHalSystemNation()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService::setHalSystemNation()_SRS"}
     * @endcond
     */
    error_t setHalSystemNation(
         uint32_t& halNation
        );
    /**
     *
     * @brief API : set variant data
     *
     * this funciton will be invoked when application or another services call this function through binder.
     *
     * @param[in] variantData  to be set as variant data
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpRegionManagerService
     *     end box
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == set variant data ==
     *     App -> BpRegionManagerService : setVariantData(arguments)
     *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_SETVARIANTDATA, Parcel)
     *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_SETVARIANTDATA, Parcel >> arguments
     *     BnRegionManagerService -> ServiceStub : setVariantData(arguments)
     *     activate ServiceStub
     *     BnRegionManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnRegionManagerService : reply->writeInt32
     *     BpRegionManagerService <- Binder : reply.readInt32()
     *     App <- BpRegionManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService::setVariantData()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService::setVariantData()_SRS"}
     * @endcond
     */
    error_t setVariantData(
         android::sp< EnvironmentVariant >& variantData
        );
    // auto API end : wishtoUseAPI
// @CGA_VARIANT_START{"xxxManagerService.h:__CUSTOM_API__CODE__:variant"}
// @CGA_VARIANT___END{"xxxManagerService.h:__CUSTOM_API__CODE__:variant"}

    // auto RECEIVER API start
    // RECEIVER API (tesetCallBack)
    // auto RECEIVER API end

public:
    bool mBootCompleted;

private:
    class ReceiverDeathRecipient : public android::IBinder::DeathRecipient {
    public:
        /**
         * @brief This is the constructor of ReceiverDeathRecipient
         *
         * @param[in] parent     RegionManagerService
         * @retval   void
         *
         */
        ReceiverDeathRecipient(RegionManagerService& parent) : mParent(parent) {}

        /**
         * @brief This is the destructor of ReceiverDeathRecipient
         *
         * @retval   void
         *
         */
        virtual ~ReceiverDeathRecipient() {}

        /**
         * @brief This function is called when binder is died.
         *
         * @param[in] who     IBinder
         * @retval   void
         *
         */
        virtual void binderDied(const android::wp<android::IBinder>& who)
            { mParent.onReceiverBinderDied(who); }
    private:
        RegionManagerService& mParent;
    };

private:
    class ServiceStub: public BnRegionManagerService {
    public:
        ServiceStub(RegionManagerService& parent) : mParent(parent) {}




        /**
         * @brief setLogLevel sets the log level for region module separately.
         *
         * @details dynamic log level - each module can set log level separately.
         *
         * @param[in] lvl int32_t : set log level
         *
         * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
         */
        virtual error_t setLogLevel(int32_t lvl);
        /**
         * @brief setLogLevelAsDefault sets the log level according to perf and debug mode.
         *
         * @details dynamic log level - set log level as default log level according to perf and debug mode
         *
         * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
         *
         */
        virtual error_t setLogLevelAsDefault();
        /**
         * @brief getLogLevel gets the log level for region module separately.
         *
         * @details dynamic log level - get log level of each module separately.
         *
         * @param[out] lvl int32_t& : get log level
         *
         * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
         */
        virtual error_t getLogLevel(int32_t& lvl);

        // auto API start : wishtoUseAPI
        /**
         * @brief API : This is stub code. Implementation will be in parent class with the function name.
         *
         * @param[out] bootMode  boot Mode to get information by reference
         * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
         */
        virtual error_t getHalSystemBootMode(
             uint32_t& bootMode
        );
        /**
         * @brief API : This is stub code. Implementation will be in parent class with the function name.
         *
         * @param[out] halNation  nation to get information by reference
         * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
         */
        virtual error_t getHalSystemNation(
             uint32_t& halNation
        );
        /**
         * @brief API : This is stub code. Implementation will be in parent class with the function name.
         *
         * @param[out] mcfgRegion  region from NAD related to mcfg
         * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
         */
        virtual error_t getMcfgRegion(
             uint8_t& mcfgRegion
        );
        /**
         * @brief API : This is stub code. Implementation will be in parent class with the function name.
         *
         * @param[out] nadRegion  enum variable of region to be get by reference
         * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
         */
        virtual error_t getNADRegion(
             uint8_t& nadRegion
        );
        /**
         * @brief API : This is stub code. Implementation will be in parent class with the function name.
         *
         * @param[out] nadRevision  enum variable of revision to be get by reference
         * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
         */
        virtual error_t getNADRevision(
             uint8_t& nadRevision
        );
        /**
         * @brief API : This is stub code. Implementation will be in parent class with the function name.
         *
         * @param[out] nadType  enum variable of type to be get by reference
         * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
         */
        virtual error_t getNADType(
             uint8_t& nadType
        );
        /**
         * @brief API : This is stub code. Implementation will be in parent class with the function name.
         *
         * @param[out] nation  nation to get parsed information by reference
         * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
         */
        virtual error_t getNation(
             uint8_t& nation
        );
        /**
         * @brief API : This is stub code. Implementation will be in parent class with the function name.
         *
         * @param[out] variantData  to be get as variant data
         * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
         */
        virtual error_t getVariantData(
             android::sp< EnvironmentVariant >& variantData
        );
        /**
         * @brief API : This is stub code. Implementation will be in parent class with the function name.
         *
         * @param[in] file_path_length Length of file_path
         * @param[in] file_path  to delete file path information
         * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
         */
        virtual error_t memoryFileDelete(
             size_t& file_path_length
            , uint8_t* file_path
        );
        /**
         * @brief API : This is stub code. Implementation will be in parent class with the function name.
         *
         * @param[in] bootMode  boot Mode to be set
         * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
         */
        virtual error_t setHalSystemBootMode(
             uint32_t& bootMode
        );
        /**
         * @brief API : This is stub code. Implementation will be in parent class with the function name.
         *
         * @param[in] halNation  nation to be set
         * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
         */
        virtual error_t setHalSystemNation(
             uint32_t& halNation
        );
        /**
         * @brief API : This is stub code. Implementation will be in parent class with the function name.
         *
         * @param[in] variantData  to be set as variant data
         * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
         */
        virtual error_t setVariantData(
             android::sp< EnvironmentVariant >& variantData
        );
        // auto API end : wishtoUseAPI
// @CGA_VARIANT_START{"xxxManagerService.h_ServiceStub:__CUSTOM_API__CODE__:variant"}
// @CGA_VARIANT___END{"xxxManagerService.h_ServiceStub:__CUSTOM_API__CODE__:variant"}

        // RECEIVER API start
        // RECEIVER API end


    private:
        bool check_condition_api_ready(void);

    private:
        RegionManagerService& mParent;
    };

private:

    /**
     * @MISRA{MISRA C++-2008 Rule 8-0-1,This is intended design}
     */
    android::sp<RegionInputManager> mRegionInputMgr;

    // int32_t mCurrentPowerState;
    mutable Mutex mReceiverLock;

    android::sp<ReceiverDeathRecipient> mReceiverDeathRecipient;

    // @CGA_VARIANT_START{"RegionManagerService:__YOUR_CODE__:variant"}
    /*
     * Write your own additional code
     * add your #include
     * add your global declare the function and variables
     * add your function
     */
    // @CGA_VARIANT___END{"RegionManagerService:__YOUR_CODE__:variant"}

};

#endif // _SERVICELAYER_REGIONNOSTIC_MANAGER_SERVICE_H_
