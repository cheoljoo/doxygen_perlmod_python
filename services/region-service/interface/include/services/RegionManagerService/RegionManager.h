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


#ifndef _TIGER_SDK_REGIONMANAGER_H_
#define _TIGER_SDK_REGIONMANAGER_H_

#include "Error.h"
#include "Log.h"
#include <utils/SLLooper.h>
#include <utils/Handler.h>
#include <binder/IServiceManager.h>
#include "IRegionManagerServiceType.h"
#include "IRegionManagerService.h"
#include <utils/RefBase.h>
#include <list>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

// @CGA_VARIANT_START{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}
    /*
     * Write your own additional code
     * add your #include
     * add your global declare the function and variables
     * add your function
     */
// @CGA_VARIANT___END{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}

class RegionManager : public android::RefBase
{
    public:
        virtual ~RegionManager();
        static RegionManager* instance();

        // todo : add multiple registerReceiverITKEYIT2KEY with different arguments types
        // case 1 : id : onReceive with different id (it was changed)
        // case 2 : receiver for special purpose
        error_t reregisterReceiver ();
        // todo : what means?  I do not know when we use it.
        // we will use reregister when we reconnect.

// wishtoUseAPI
        error_t getNADRegion(
                // getNADRegion 1
                // type : std::string
                // name : region
                // direction : out
                // is xxClass :
                // is receiver :
                // len variable :
                // default (optional) argument :
                // init value :
             std::string& region);
        error_t getNADRevision(
                // getNADRevision 1
                // type : std::string
                // name : revision
                // direction : out
                // is xxClass :
                // is receiver :
                // len variable :
                // default (optional) argument :
                // init value :
             std::string& revision);
        error_t getNADType(
                // getNADType 1
                // type : std::string
                // name : type
                // direction : out
                // is xxClass :
                // is receiver :
                // len variable :
                // default (optional) argument :
                // init value :
             std::string& type);
        error_t getServiceState(
                // getServiceState 1
                // type : uint8_t
                // name : state
                // direction : out
                // is xxClass : 
                // is receiver : 
                // len variable :  
                // default (optional) argument :  
                // init value :  0
             uint8_t& state 
        );

        error_t setHalSystemBootMode(uint32_t bootMode);
        error_t setHalSystemNation(uint32_t nation);
        error_t getHalSystemBootMode(uint32_t& bootMode);
        error_t getHalSystemNation(uint32_t& nation);
        error_t getNation(uint8_t& nation);
        error_t memoryFileDelete(uint8_t* file_path, uint16_t file_path_length);
        error_t getMcfgRegion(std::string& region);
        error_t getVariantData(android::sp<EnvironmentVariant>& data);
        error_t setVariantData(android::sp<EnvironmentVariant>& data);
        void onBinderDied(const android::wp<android::IBinder>& who);

    private:
        RegionManager();
        android::sp<IRegionManagerService> getService();

        class ManagerDeathRecipient : public android::IBinder::DeathRecipient
        {
            public:
                /**
                 * @brief This is the constructor of DeathRecipient
                 *
                 * @param[in] parent     RegionManager
                 * @retval   void
                 *
                 */
                explicit ManagerDeathRecipient(RegionManager& parent) : mParent(parent) {}

                /**
                 * @brief This is the destructor of DeathRecipient
                 *
                 * @retval   void
                 *
                 */
                virtual ~ManagerDeathRecipient() {}

                /**
                 * @brief This function is called when binder is died.
                 *
                 * @param[in] who     IBinder
                 * @retval   void
                 *
                 */
                virtual void binderDied(const android::wp<android::IBinder>& who);


            private:
                RegionManager& mParent;
        };

    private:
        static RegionManager* mInstance;
        android::sp<android::IBinder> mToken;
        android::sp<ManagerDeathRecipient> mDeathRecipient;
        android::sp<IRegionManagerService> mRegionService;

    

        // @CGA_VARIANT_START{"REGIONMANAGER_H:REGIONMANAGER()"}
        /*
         * Write your own code
         */
        // @CGA_VARIANT___END{"REGIONMANAGER_H:REGIONMANAGER()"}

};

#endif //_TIGER_SDK_REGIONMANAGER_H_
