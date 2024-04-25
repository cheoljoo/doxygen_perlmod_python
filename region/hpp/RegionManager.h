
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
        /**
         * @brief destructor function for the RegionManager.
         *
         * @retval  void
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:~RegionManager()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:~RegionManager()"}
         */
        virtual ~RegionManager();
        /**
         * @brief instance function for the RegionManager.
         *
         * @retval   RegionManager*
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:instance()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:instance()"}
         */
        static RegionManager* instance();


        /**
         * @brief It is the function to reregister receiver for the RegionManager.
         *
         * @retval   error_t   If the receiver is reregistered successfully, return E_OK, otherwise, return E_ERROR.
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:reregisterReceiver()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:reregisterReceiver()"}
         */
        error_t reregisterReceiver ();
        // we will use reregister when we reconnect.


        /**
         * @brief setLogLevel sets the log level for region module separately.
         *
         * @details dynamic log level - each module can set log level separately.
         *
         * @param[in] lvl int32_t : set log level
         *
         * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
         */
        error_t setLogLevel(int32_t lvl);
        /**
         * @brief setLogLevelAsDefault sets the log level according to perf and debug mode.
         *
         * @details dynamic log level - set log level as default log level according to perf and debug mode
         *
         * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
         *
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
         */
        error_t getLogLevel(int32_t& lvl);

// wishtoUseAPI
        /**
         * @brief boot Mode to get information by reference
         *
         * It is the function for getHalSystemBootMode in the RegionManager.
         *
         * @param[out] bootMode boot Mode to get information by reference
         * @retval   error_t   If this function works successfully, return E_OK, otherwise, return E_ERROR.
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:getHalSystemBootMode()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:getHalSystemBootMode()"}
         */
        error_t getHalSystemBootMode(
                // getHalSystemBootMode 1
                // type : uint32_t
                // name : bootMode
                // direction : out
                // is xxClass : NO
                // is receiver : NO
                // len variable : 
                // default (optional) argument :  
                // init value :  1
             uint32_t& bootMode 
        );
        /**
         * @brief nation to get information by reference
         *
         * It is the function for getHalSystemNation in the RegionManager.
         *
         * @param[out] halNation nation to get information by reference
         * @retval   error_t   If this function works successfully, return E_OK, otherwise, return E_ERROR.
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:getHalSystemNation()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:getHalSystemNation()"}
         */
        error_t getHalSystemNation(
                // getHalSystemNation 1
                // type : uint32_t
                // name : halNation
                // direction : out
                // is xxClass : NO
                // is receiver : NO
                // len variable : 
                // default (optional) argument :  
                // init value :  0
             uint32_t& halNation 
        );
        /**
         * @brief region from NAD related to mcfg
         *
         * It is the function for getMcfgRegion in the RegionManager.
         *
         * @param[out] mcfgRegion region from NAD related to mcfg
         * @retval   error_t   If this function works successfully, return E_OK, otherwise, return E_ERROR.
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:getMcfgRegion()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:getMcfgRegion()"}
         */
        error_t getMcfgRegion(
                // getMcfgRegion 1
                // type : uint8_t
                // name : mcfgRegion
                // direction : out
                // is xxClass : NO
                // is receiver : NO
                // len variable : 
                // default (optional) argument :  
                // init value :  0
             uint8_t& mcfgRegion 
        );
        /**
         * @brief enum variable of region to be get by reference
         *
         * It is the function for getNADRegion in the RegionManager.
         *
         * @param[out] nadRegion enum variable of region to be get by reference
         * @retval   error_t   If this function works successfully, return E_OK, otherwise, return E_ERROR.
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:getNADRegion()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:getNADRegion()"}
         */
        error_t getNADRegion(
                // getNADRegion 1
                // type : uint8_t
                // name : nadRegion
                // direction : out
                // is xxClass : NO
                // is receiver : NO
                // len variable : 
                // default (optional) argument :  
                // init value :  0
             uint8_t& nadRegion 
        );
        /**
         * @brief enum variable of revision to be get by reference
         *
         * It is the function for getNADRevision in the RegionManager.
         *
         * @param[out] nadRevision enum variable of revision to be get by reference
         * @retval   error_t   If this function works successfully, return E_OK, otherwise, return E_ERROR.
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:getNADRevision()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:getNADRevision()"}
         */
        error_t getNADRevision(
                // getNADRevision 1
                // type : uint8_t
                // name : nadRevision
                // direction : out
                // is xxClass : NO
                // is receiver : NO
                // len variable : 
                // default (optional) argument :  
                // init value :  0
             uint8_t& nadRevision 
        );
        /**
         * @brief enum variable of type to be get by reference
         *
         * It is the function for getNADType in the RegionManager.
         *
         * @param[out] nadType enum variable of type to be get by reference
         * @retval   error_t   If this function works successfully, return E_OK, otherwise, return E_ERROR.
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:getNADType()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:getNADType()"}
         */
        error_t getNADType(
                // getNADType 1
                // type : uint8_t
                // name : nadType
                // direction : out
                // is xxClass : NO
                // is receiver : NO
                // len variable : 
                // default (optional) argument :  
                // init value :  0
             uint8_t& nadType 
        );
        /**
         * @brief nation to get parsed information by reference
         *
         * It is the function for getNation in the RegionManager.
         *
         * @param[out] nation nation to get parsed information by reference
         * @retval   error_t   If this function works successfully, return E_OK, otherwise, return E_ERROR.
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:getNation()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:getNation()"}
         */
        error_t getNation(
                // getNation 1
                // type : uint8_t
                // name : nation
                // direction : out
                // is xxClass : NO
                // is receiver : NO
                // len variable : 
                // default (optional) argument :  
                // init value :  0
             uint8_t& nation 
        );
        /**
         * @brief to be get as variant data
         *
         * It is the function for getVariantData in the RegionManager.
         *
         * @param[out] variantData to be get as variant data
         * @retval   error_t   If this function works successfully, return E_OK, otherwise, return E_ERROR.
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:getVariantData()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:getVariantData()"}
         */
        error_t getVariantData(
                // getVariantData 1
                // type : EnvironmentVariant
                // name : variantData
                // direction : out
                // is xxClass : YES
                // is receiver : NO
                // len variable : 
                // default (optional) argument :  
                // init value :  
             android::sp< EnvironmentVariant >& variantData
        );
        /**
         * @brief to delete file path information
         *
         * It is the function for memoryFileDelete in the RegionManager.
         *
         * @param[in] file_path_length Length of file_path
         * @param[in] file_path to delete file path information
         * @retval   error_t   If this function works successfully, return E_OK, otherwise, return E_ERROR.
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:memoryFileDelete()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:memoryFileDelete()"}
         */
        error_t memoryFileDelete(
                // memoryFileDelete 1
                // type : uint8_t*
                // name : file_path
                // direction : in
                // is xxClass : NO
                // is receiver : NO
                // len variable : file_path_length
                // default (optional) argument :  
                // init value :  "default"
             size_t file_path_length
            , uint8_t* file_path
        );
        /**
         * @brief boot Mode to be set
         *
         * It is the function for setHalSystemBootMode in the RegionManager.
         *
         * @param[in] bootMode boot Mode to be set
         * @retval   error_t   If this function works successfully, return E_OK, otherwise, return E_ERROR.
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:setHalSystemBootMode()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:setHalSystemBootMode()"}
         */
        error_t setHalSystemBootMode(
                // setHalSystemBootMode 1
                // type : uint32_t
                // name : bootMode
                // direction : in
                // is xxClass : NO
                // is receiver : NO
                // len variable : 
                // default (optional) argument :  
                // init value :  1
             uint32_t bootMode 
        );
        /**
         * @brief nation to be set
         *
         * It is the function for setHalSystemNation in the RegionManager.
         *
         * @param[in] halNation nation to be set
         * @retval   error_t   If this function works successfully, return E_OK, otherwise, return E_ERROR.
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:setHalSystemNation()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:setHalSystemNation()"}
         */
        error_t setHalSystemNation(
                // setHalSystemNation 1
                // type : uint32_t
                // name : halNation
                // direction : in
                // is xxClass : NO
                // is receiver : NO
                // len variable : 
                // default (optional) argument :  
                // init value :  0
             uint32_t halNation 
        );
        /**
         * @brief to be set as variant data
         *
         * It is the function for setVariantData in the RegionManager.
         *
         * @param[in] variantData to be set as variant data
         * @retval   error_t   If this function works successfully, return E_OK, otherwise, return E_ERROR.
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:setVariantData()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:setVariantData()"}
         */
        error_t setVariantData(
                // setVariantData 1
                // type : EnvironmentVariant
                // name : variantData
                // direction : in
                // is xxClass : YES
                // is receiver : NO
                // len variable : 
                // default (optional) argument :  
                // init value :  
             android::sp< EnvironmentVariant >& variantData
        );

// @CGA_VARIANT_START{"__PUBLIC_SCOPE__:__YOUR_LEGACY_API_CODE__:variant"}
// ....
// @CGA_VARIANT___END{"__PUBLIC_SCOPE__:__YOUR_LEGACY_API_CODE__:variant"}

        /**
         * @brief It is the function to get service for the RegionManager.
         *
         * @param[in] who  who sends Death state.
         * @retval  void
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:onBinderDied()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:onBinderDied()"}
         */
        void onBinderDied(const android::wp<android::IBinder>& who);

    private:
        /**
         * @brief constructor function for the RegionManager.
         *
         * @retval  void
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:RegionManager()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:RegionManager()"}
         */
        RegionManager();
        /**
         * @brief get service for the RegionManager.
         *
         * @retval  android::sp<IRegionManagerService>
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionManager:getService()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionManager:getService()"}
         */
        android::sp<IRegionManagerService> getService();

#ifdef __UNITTEST__
        android::sp<IRegionManagerService> getService_mock();
#endif

        class ManagerDeathRecipient : public android::IBinder::DeathRecipient
        {
            public:
                /**
                 * @brief This is the constructor of DeathRecipient
                 *
                 * @param[in] parent     regionManager
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
        static bool DEBUG;

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
