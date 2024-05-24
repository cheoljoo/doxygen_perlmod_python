
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
 * @date    2021.09.30
 * @version 1.0.00
 */

/** @defgroup REGION_MGR RegionManager
* This is the Class/APIs related with REGION MANAGER SERVICE\n\n
* A. RegionManager - General class for communicating with Region Manager Service\n
* B. IRegionManagerService - Interface class of Region Manager Service\n
* @version
* 3.0.0
*/

/** @defgroup REGIONMGR_API RegionManager API
 *  @ingroup REGION_MGR
 *
 *  Thease are the REGION APIs
 */

#ifndef _IREGIONNOSTIC_MANAGER_SERVICE_H_
#define _IREGIONNOSTIC_MANAGER_SERVICE_H_

#include <string>
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
 *  RegionManagerService service name is @b Region_SRV_NAME (="service_layer.RegionManagerService")
 */
class IRegionManagerService : public android::IInterface
{
public:
    DECLARE_META_INTERFACE(RegionManagerService);
    //< Interfaces for IRegionManagerService


     // auto API start : wishtoUseAPI
     /**
     * @ingroup REGIONMGR_API
     *
     * @brief API : get the NAD region information
     *
     * Request NAD region information.
     * This api get the NAD information via Telephony and parse the data and then give NAD region string value.
     *
     * @param[out] region     string variable that is set to region string by reference
     * @retval   error_t     If the region value is set to string value successfully, return E_OK, otherwise, return E_ERROR.
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
     *     ==  ==
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
    virtual error_t getNADRegion(std::string& region) = 0;

     /**
     * @ingroup REGIONMGR_API
     *
     * @brief API : get the NAD HW revision information
     *
     * Request NAD HW revision information.
     * This api get the NAD information via Telephony and parse the data and then give NAD HW revision string value.
     *
     * @param[out] revision     string variable that is set to hw_revision string by reference
     * @retval   error_t     If the hw_revision value is set to string value successfully, return E_OK, otherwise, return E_ERROR.
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
     *     ==  ==
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
    virtual error_t getNADRevision(std::string& revision) = 0;

     /**
     * @ingroup REGIONMGR_API
     *
     * @brief API : get the NAD type information
     *
     * Request NAD type information.
     * This api get the NAD information via Telephony and parse the data and then give NAD type string value.
     *
     * @param[out] type     string variable that is set to type string by reference
     * @retval   error_t     If the type value is set to string value successfully, return E_OK, otherwise, return E_ERROR.
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
     *     ==  ==
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
    virtual error_t getNADType(std::string& type) = 0;

     /**
     * @ingroup REGIONMGR_API
     *
     * @brief API : check whether region service is alive or not
     *
     * this funciton will be invoked when application or another services call this function through binder.
     * Check RegionMgr service is alive or not
     *
     * @param[out] state  argument for alive by reference
     * @retval   error_t     If the region-service returned successfully, return E_OK, otherwise, return E_ERROR.
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
     *     == desc check whether region service is alive or not ==
     *     App -> BpRegionManagerService : getServiceState(arguments)
     *     BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETSERVICESTATE, Parcel)
     *     Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\n OP_REGISTER_GETSERVICESTATE, Parcel >> arguments
     *     BnRegionManagerService -> ServiceStub : getServiceState(arguments)
     *     activate ServiceStub
     *     BnRegionManagerService <- ServiceStub : return E_OK
     *     deactivate ServiceStub
     *     Binder <- BnRegionManagerService : reply->writeInt32
     *     BpRegionManagerService <- Binder : reply.readInt32()
     *     App <- BpRegionManagerService : return
     * @enduml
     *
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService::getServiceState()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService::getServiceState()_SRS"}
     * @endcond
     */     
    virtual error_t getServiceState(uint8_t& state) = 0;

     /**
     * @ingroup REGIONMGR_API
     *
     * @brief API : Set the boot mode in hal system
     *
     * Request to set boot mode information in hal system.
     * This api set the boot mode information via hal_system.
     *
     * @param[in] bootMode  boot Mode to be set
     * @retval   error_t     If boot mode set to hal system is returned successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == Set the boot mode in hal system ==
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
    virtual error_t setHalSystemBootMode(uint32_t& bootMode) = 0;

     /**
     * @ingroup REGIONMGR_API
     *
     * @brief API : Set the nation in hal system
     *
     * Request to set nation information in hal system.
     * This api set the nation information via hal_system.
     *
     * @param[in] nation  nation to be set
     * @retval   error_t     If nation set to hal system is returned successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == Set the nation in hal system ==
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
    virtual error_t setHalSystemNation(uint32_t& nation) = 0;


     /**
     * @ingroup REGIONMGR_API
     *
     * @brief API : Get the boot mode in hal system
     *
     * Request to get boot mode information in hal system.
     * This api get the boot mode information via hal_system.
     *
     * @param[in] bootMode  boot Mode to get information by reference
     * @retval   error_t     If boot mode get from hal system is returned successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == api desc getter of bootMode from hal system ==
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
    virtual error_t getHalSystemBootMode(uint32_t& bootMode) = 0;


     /**
     * @ingroup REGIONMGR_API
     *
     * @brief API : Get the nation in hal system
     *
     * Request to get nation information in hal system.
     * This api get the nation information via hal_system.
     *
     * @param[in] nation  nation to get information by reference
     * @retval   error_t     If nation get from hal system is returned successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == api desc getter of nation from hal system ==
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
    virtual error_t getHalSystemNation(uint32_t& nation) = 0;


     /**
     * @ingroup REGIONMGR_API
     *
     * @brief API : Get the parsed nation in hal system
     *
     * Request to get parsed nation information in hal system.
     * This api get the parsed nation information via hal_system.
     *
     * @param[in] nation  nation to get parsed information by reference
     * @retval   error_t     If nation get from hal system is returned successfully, return E_OK, otherwise, return E_ERROR.
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
     *     == getter of parsed nation information from hal system ==
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
    virtual error_t getNation(uint8_t& nation) = 0;


     /**
     * @ingroup REGIONMGR_API
     *
     * @brief API : Generated File Deletion API
     *
     * Receives the delete request for the created file and deletes the specified file.
     *
     * @param[in] file_path to delete file path information
     * @param[in] file_path_length to file path data length
     * @retval   error_t     If nation get from hal system is returned successfully, return E_OK, otherwise, return E_ERROR.
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
     *     == getter of parsed nation information from hal system ==
     *     App -> BpRegionManagerService : memoryFileDelete(arguments)
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
     * @CGA_VARIANT_START{"DOXYGEN:RegionManagerService::memoryFileDelete()_SRS"}
     * @SRS{TIDL-FR-001,Explanation for FR-001}
     * @CGA_VARIANT___END{"DOXYGEN:RegionManagerService::memoryFileDelete()_SRS"}
     * @endcond
     */
    virtual error_t memoryFileDelete(uint8_t* file_path, uint16_t file_path_length) = 0;

     // auto API start : wishtoUseAPI
     /**
     * @ingroup REGIONMGR_API
     *
     * @brief API : region information from NAD related to mcfg(modem config)
     *
     * this funciton will return mcfg region information from NAD side
     *
     * @param[out] region  desc region from NAD related to mcfg
     * @retval   error_t     If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.
     *
     * @cond UML
     * @startuml
     *     box "Application (Proxy)\n Other Services"
     *     participant App
     *     participant BpRegionManagerService
     *     participant Binder
     *     box "Service (Native) - API"
     *     participant BnRegionManagerService
     *     participant ServiceStub
     *     end box
     *
     *     == api desc region from NAD related to mcfg ==
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
    virtual error_t getMcfgRegion(std::string& region) = 0;

     /**
     * @ingroup REGIONMGR_API
     *
     * @brief API : api desc get variant data
     *
     * This api will return Variant Information as EnvironmentVariant
     *
     * @param[out] data  desc to be get as variant data
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
     *     == api desc get variant data ==
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
    virtual error_t getVariantData(android::sp<EnvironmentVariant>& data) = 0;

     /**
     * @ingroup REGIONMGR_API
     *
     * @brief API : api desc set variant data
     *
     * This api will set Variant Information as EnvironmentVariant
     *
     * @param[in] data  desc to be set as variant data
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
     *     == api desc set variant data ==
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
    virtual error_t setVariantData(android::sp<EnvironmentVariant>& data) = 0;

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
    virtual android::status_t onTransact(uint32_t code, const android::Parcel& data, android::Parcel* reply, uint32_t flags);
};

#endif /**IREGION_MANAGER_SERVICE_H*/
