
/**
 * @if (CGA)
 *  @CGA_INCLUDE{IRegionManagerService.h}
 * @endif
 */
// FileName - IRegionManagerService.h
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
 */

/** @defgroup REGIONMGR_API REGIONMGR REGION API
 *  @ingroup REGIONMGR
 *
 *  Thease are the REGION APIs
 */

/** @defgroup REGIONMGR_CB REGIONMGR Callback
 *  @ingroup REGIONMGR
 *
 *  This is the REGION Manager Receiver list.
 */ 

/** @defgroup REGION_RECEIVER_TEST_API REGION receiver Test API list
 *  @ingroup REGIONMGR
 *
 *  This is the REGION Test API list for receiver.
 */ 

#ifndef _IREGIONNOSTIC_MANAGER_SERVICE_H_
#define _IREGIONNOSTIC_MANAGER_SERVICE_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include "Typedef.h"

#include "RegionCommand.h"
#include "IRegionManagerServiceType.h"

// @CGA_VARIANT_START{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}
    /*
     * Write your own additional code
     * add your #include
     * add your global declare the function and variables
     * add your function
     */

// @CGA_VARIANT___END{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}

/**
 * @brief If Apps or other services need to control REGION, It could be obatined by these API.
 * To use these API, APP or Service, You Should get IRegionManaerService
 *
 * @note
 *  regionManagerService service name is @b Region_SRV_NAME (="service_layer.regionManagerService")
 */
class IRegionManagerService : public android::IInterface
{
public:
    DECLARE_META_INTERFACE(RegionManagerService);
    //< Interfaces for IRegionManagerService




    /**
     * @brief setLogLevel sets the log level for region module separately.
     *
     * @details dynamic log level - each module can set log level separately.
     *
     * @param[in] lvl int32_t : set log level
     *
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     */
    virtual error_t setLogLevel(int32_t lvl)=0;
    /**
     * @brief setLogLevelAsDefault sets the log level according to perf and debug mode.
     *
     * @details dynamic log level - set log level as default log level according to perf and debug mode
     *
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     *
     */
    virtual error_t setLogLevelAsDefault()=0;
    /**
     * @brief getLogLevel gets the log level for region module separately.
     *
     * @details dynamic log level - get log level of each module separately.
     *
     * @param[out] lvl int32_t& : get log level
     *
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     */
    virtual error_t getLogLevel(int32_t& lvl)=0;

     // auto API start : wishtoUseAPI
     /**
     * @ingroup REGIONMGR_API
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
    virtual error_t getHalSystemBootMode(
         uint32_t& bootMode
        )=0;
     /**
     * @ingroup REGIONMGR_API
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
    virtual error_t getHalSystemNation(
         uint32_t& halNation
        )=0;
     /**
     * @ingroup REGIONMGR_API
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
    virtual error_t getMcfgRegion(
         uint8_t& mcfgRegion
        )=0;
     /**
     * @ingroup REGIONMGR_API
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
    virtual error_t getNADRegion(
         uint8_t& nadRegion
        )=0;
     /**
     * @ingroup REGIONMGR_API
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
    virtual error_t getNADRevision(
         uint8_t& nadRevision
        )=0;
     /**
     * @ingroup REGIONMGR_API
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
    virtual error_t getNADType(
         uint8_t& nadType
        )=0;
     /**
     * @ingroup REGIONMGR_API
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
    virtual error_t getNation(
         uint8_t& nation
        )=0;
     /**
     * @ingroup REGIONMGR_API
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
    virtual error_t getVariantData(
         android::sp< EnvironmentVariant >& variantData
        )=0;
     /**
     * @ingroup REGIONMGR_API
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
    virtual error_t memoryFileDelete(
         size_t& file_path_length
        , uint8_t* file_path
        )=0;
     /**
     * @ingroup REGIONMGR_API
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
    virtual error_t setHalSystemBootMode(
         uint32_t& bootMode
        )=0;
     /**
     * @ingroup REGIONMGR_API
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
    virtual error_t setHalSystemNation(
         uint32_t& halNation
        )=0;
     /**
     * @ingroup REGIONMGR_API
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
    virtual error_t setVariantData(
         android::sp< EnvironmentVariant >& variantData
        )=0;
    // RECEIVER API start
    // auto RECEIVER API end for test : receiver_function

    // @CGA_VARIANT_START{"IRegionManagerService:IRegionManagerService()"}
    /*
     * Write your own code
     */
    // @CGA_VARIANT___END{"IRegionManagerService:IRegionManagerService()"}

};

class BnRegionManagerService : public android::BnInterface<IRegionManagerService>
{

public:
    /**
     * @brief onTransact function for the BnRegionManagerService.
     *
     * @param[in] code operation code in binder
     * @param[in] data data parcel in binder
     * @param[in,out] reply reply packet in binder
     * @param[in] flags flags
     * @retval   status_t It returns the status of onTransact function.
     *
     */
    virtual android::status_t onTransact(uint32_t code, const android::Parcel& data, android::Parcel* reply, uint32_t flags);
};

#endif /**IREGION_MANAGER_SERVICE_H*/
