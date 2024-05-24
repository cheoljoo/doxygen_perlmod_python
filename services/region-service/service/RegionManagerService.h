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

/* auto __ appmgr Inheritance CGA start-------------------------------------------------*/
#include <services/ApplicationManagerService/IApplicationManagerService.h>
#include <services/ApplicationManagerService/IApplicationManagerServiceType.h>
/* auto __ appmgr Inheritance CGA end-------------------------------------------------*/

#include <services/HealthManagerService/HealthManager.h>

#include <map>
#include <list>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstring>
#include <string>

#include <Typedef.h>
#include <corebase/SystemService.h>
#include <system_property.h>
#include <sys/stat.h>
#include <unistd.h>

#include "utils/atoi.h"
#include "Typedef.h"
#include "RegionYoursInputManager.h"

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

#ifdef __UNITTEST__
extern std::string getRegionId_UT();
extern std::string getHwRevision_UT();
extern std::string getNadType_UT();
extern std::string getMcfgRegionId_UT();
extern uint8_t getNation_UT();
extern error_t setHalSystemBootMode_UT(uint32_t& bootMode);
extern error_t setHalSystemNation_UT(uint32_t& nation);
extern uint32_t getHalSystemBootMode_UT();
extern uint32_t getHalSystemNation_UT();
extern android::sp<EnvironmentVariant> getVariantData_UT();
extern error_t setVariantData_UT();
#endif

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
    RegionManagerService();
    virtual ~RegionManagerService();

    /**
     * @brief This function gets service name.
     *
     * @retval   service_layer.RegionManagerService service name
     *
     */
    static const char* getServiceName() { return "service_layer.RegionManagerService"; }

    /**
     * @brief This function gets module ID.
     *
     * @retval   MODULE_REGION module ID
     *
     */
    virtual uint8_t getModuleID() { 
        return MODULE_REGION_MGR; 
    }

    virtual bool onInit();
    virtual void instantiate();
    virtual error_t onStart();
    virtual error_t onStop();
    virtual error_t dump(LogOutput&);




    bool isApplicationExecuted(appid_t id);

    void onReceiverBinderDied(const android::wp<android::IBinder>& who);

    // auto API start : wishtoUseAPI
    error_t getNADRegion(std::string& region);
    error_t getNADRevision(std::string& revision);
    error_t getNADType(std::string& type);
    error_t getServiceState(uint8_t& state);
    error_t setHalSystemBootMode(uint32_t& bootMode);
    error_t setHalSystemNation(uint32_t& nation);
    error_t getHalSystemBootMode(uint32_t& bootMode);
    error_t getHalSystemNation(uint32_t& nation);
    error_t getNation(uint8_t& nation);
    error_t memoryFileDelete(uint8_t* file_path, uint16_t file_path_length);
    error_t getMcfgRegion(std::string& revision);
    error_t getVariantData(android::sp<EnvironmentVariant>& data);
    error_t setVariantData(android::sp<EnvironmentVariant>& data);
    // auto API end : wishtoUseAPI

    // auto RECEIVER API start
    // RECEIVER API (tesetCallBack)
    // auto RECEIVER API end

    android::sp<RegionYoursInputManager> getRegionInputManager();

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




        // auto API start : wishtoUseAPI
        virtual error_t getNADRegion(std::string& region);
        virtual error_t getNADRevision(std::string& revision);
        virtual error_t getNADType(std::string& type);
        virtual error_t getServiceState(uint8_t& state);
        virtual error_t setHalSystemBootMode(uint32_t& bootMode);
        virtual error_t setHalSystemNation(uint32_t& nation);
        virtual error_t getHalSystemBootMode(uint32_t& bootMode);
        virtual error_t getHalSystemNation(uint32_t& nation);
        virtual error_t getNation(uint8_t& nation);
        virtual error_t memoryFileDelete(uint8_t* file_path, uint16_t file_path_length);
        virtual error_t getMcfgRegion(std::string& revision);
        virtual error_t getVariantData(android::sp<EnvironmentVariant>& data);
        virtual error_t setVariantData(android::sp<EnvironmentVariant>& data);
        // auto API end : wishtoUseAPI

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
#ifndef __UNITTEST__
    android::sp<RegionYoursInputManager> mRegionInputMgr;
#else
    android::sp<RegionInputManager> mRegionInputMgr;
#endif
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
