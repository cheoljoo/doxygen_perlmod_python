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

/**
 *
 * This is the Region Input Manager with msg handler and connector of related tiger managers.
 *
 * @cond UML
 * @startuml
 *    class RegionInputManager
 *    class RegionHandler
 *    class sl::Handler
 *    class android::RefBase
 *    class RegionInputMgrTimer
 *    class TimerTimeoutHandler
 *    class ServiceDeathRecipient
 *    class android::IBinder::DeathRecipient
 *    class RegionManagerService
 *
 *    RegionInputManager *--  RegionManagerService :  >
 *     RegionInputManager --> android::RefBase
 *     RegionInputManager *--  RegionHandler : mMyHandler >
 *     RegionHandler -->  sl::Handler
 *     RegionInputManager *--  RegionInputMgrTimer : mRegionInputMgrTimer >
 *     RegionInputMgrTimer --> TimerTimeoutHandler
 *     RegionInputManager *--  ServiceDeathRecipient : mServiceDeathRecipient >
 *     ServiceDeathRecipient -->  android::IBinder::DeathRecipient
 *    class BnSystemPostReceiver
 *    class SystemPostReceiver
 *     RegionInputManager *-up-  SystemPostReceiver : mSystemPostReceiver >
 *     SystemPostReceiver -up-> BnSystemPostReceiver : appmgr
 * @enduml
 * @endcond
 */

#ifndef SERVICELAYER_REGION_INPUT_MANAGER_H
#define SERVICELAYER_REGION_INPUT_MANAGER_H

/**
* @MISRA{MISRA C++-2008 Rule 16-2-1,"This is intended design"}
*/
#define     TIME_SEND_RETRY_DELAY_MS  500

#include <binder/IBinder.h>
#include <binder/IInterface.h>

#include <utils/Handler.h>
#include <utils/SLLooper.h>
#include <utils/Timer.h>
#include <utils/external/mindroid/lang/String.h>
#include <utils/Mutex.h>

#include <services/HealthManagerService/HealthManager.h>
#include <services/RegionManagerService/RegionCommand.h>

#include <string>

// @CGA_VARIANT_START{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}
    /*
    * Write your own additional code
    * add your #include
    * add your global declare the function and variables
    * add your function
    */
// @CGA_VARIANT___END{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}

enum {
    MSG_RECEIVE_BOOT_COMPLETE = 1,
    MSG_RECEIVE_BOOT_COMPLETE_PRE,
    MSG_RECEIVE_WATCH_DOG,
    MSG_BOOT_COMPLETE_DID_START,
    MSG_SIGNAL_INTERNAL_IGNITION2_STATUS,
    /* auto __ app manager  Inheritance CGA start-------------------------------------------------*/
    MSG_CONNECT_TO_APPMGR,
    /* auto __ app manager  Inheritance CGA end-------------------------------------------------*/

    MSG_CONNECT_TO_HEALTHMGR ,

    // recivers of related managers (ex. v2x , wifi)
};


/**
 * @brief RegionInputManager is Receiver class with msgHandler and relations with another Tiger Manager.
 *
 * @cond UML
 * This is process how to run operations in RegionInputManager class.
 * @startuml
 *    RegionManagerService -> RegionInputManager : init()
 *    RegionManagerService -> RegionInputManager : onStart()
 *    RegionInputManager -> ServiceDeathRecipient : mServiceDeathRecipient - contructor Death
 *    RegionInputManager -> RegionHandler : mMyHandler - looper of MSG
 *    loop each Modules (ex. app , audio , HMI , vif Manager) until all Modules are alive
 *      RegionInputManager -> RegionInputManager : connectToAppMgr()
 *      alt each module  manager is alive
 *        RegionInputManager <-> binder : register Death Recipient / ex. mAppManager
 *      else
 *        RegionInputManager -> RegionHandler : handleMessage   ex. MSG_CONNECT_TO_APPMGR
 *      end
 *    end
 *    RegionInputManager -> RegionInputMgrTimer : mRegionInputMgrTimer - timer
 *    RegionInputManager -> RegionInputMgrTimer : watchDog start
 *    OtherService -> RegionHandler : handleMessage - ex. DID_WORK_FOR_DEFINE_0
 *    alt death of related service module (ex. app, audio, HMI, vif etc)
 *      OtherService -> binder : Death
 *      binder -> RegionInputManager : onServiceBinderDied
 *      loop Died Module (ex. app , audio , HMI , vif Manager) until Died Module is alive
 *        RegionInputManager -> RegionInputManager : ex. connectToAPPMg()
 *        alt each module manager is alive
 *          RegionInputManager <-> binder : register Death Recipient / ex. mAppManager
 *        else
 *          RegionInputManager -> RegionHandler : handleMessage  ex. MSG_CONNECT_TO_APPMGR
 *        end
 *      end
 *    end
 * @enduml
 * @endcond
 **/
class RegionInputManager: public android::RefBase {
 public:
    class RegionHandler: public sl::Handler {
     public:
        /**
         * @brief This is the constructor function for the RegionHandler.
         *
         * @param[in] looper     android SLLooper
         * @param[in] outer     RegionInputManager
         * @retval   void
         *
         */
        RegionHandler(android::sp<sl::SLLooper>& looper, RegionInputManager& outer) :
        Handler(looper), mRegionInputMgr(outer) { }
        virtual void handleMessage(const android::sp<sl::Message>& msg);

     private:
        RegionInputManager& mRegionInputMgr;
    };

    class RegionInputMgrTimer : public TimerTimeoutHandler {
     public:
        /* Timer ID */
        static const uint32_t REGION_WATCHDOG_TIMER = 1U;

        /**
         * @brief This is the constructor function for the RegionInputMgrTimer.
         *
         * @param[in] handler     android RegionHandler
         * @retval   void
         *
         */
        explicit RegionInputMgrTimer(android::sp<RegionInputManager::RegionHandler> handler) :  mHandler(handler) { }

        /**
         * @brief This is the virtual handle function for the RegionInputMgrTimer.
         *
         * @param[in] timer_id     timer id
         * @retval   void
         *
         */
        virtual void handlerFunction(int timer_id) {
                LOGV("RegionInputMgrTimer is received");
                switch (timer_id) {
                    case REGION_WATCHDOG_TIMER:
                        mHandler->obtainMessage(MSG_RECEIVE_WATCH_DOG)->sendToTarget();
                        break;
                    default :
                        break;
                    }
        }

     private:
        android::sp<RegionInputManager::RegionHandler> mHandler;
    };

    class ServiceDeathRecipient : public android::IBinder::DeathRecipient {
     public:
        /**
         * @brief This is the constructor function for the ServiceDeathRecipient.
         *
         * @param[in] parent     RegionInputManager
         * @retval   void
         *
         */
        explicit ServiceDeathRecipient(RegionInputManager& parent) : mParent(parent) {}

        /**
         * @brief This is the virtual destructor function for the ServiceDeathRecipient.
         *
         * @retval   void
         *
         */
        virtual ~ServiceDeathRecipient() {}

        /**
         * @brief This is the binderdied virtual function for the ServiceDeathRecipient.
         *
         * @param[in] who     IBinder
         * @retval   void
         *
         */
        virtual void binderDied(const android::wp<android::IBinder>& who)
            { mParent.onServiceBinderDied(who);}

     private:
        RegionInputManager& mParent;
    };

    /* auto __ appmgr Inheritance CGA start-------------------------------------------------*/
    class systemPostReceiver: public BnSystemPostReceiver {
     public:
        /**
         * @brief This is the constructor function for the systemPostReceiver.
         *
         * @param[in] handler     android RegionHandler
         * @retval   void
         *
         */
        explicit systemPostReceiver(android::sp<RegionInputManager::RegionHandler> handler) : mHandler(handler) {}

        /**
         * @brief This is the function to receive system post event.
         *
         * @param[in] systemPost     android Post
         * @retval   void
         *
         */
        virtual bool onSystemPostReceived(const android::sp<Post>& systemPost) {
            if (SYS_POST_IS_CONTAIN(systemPost->what, SYS_POST_BOOT_COMPLETED) == true) {
               LOGI("systemPostReceiver Boot Complete");   // charles : chage the name (log)
               android::sp<sl::Message> message = mHandler->obtainMessage(MSG_RECEIVE_BOOT_COMPLETE);
               message->sendToTarget();
            } else if (SYS_POST_IS_CONTAIN(systemPost->what, SYS_POST_BOOT_COMPLETED_PRE) == true) {
                LOGI("systemPostReceiver Boot Complete Pre");   // charles : chage the name (log)
                android::sp<sl::Message> message = mHandler->obtainMessage(MSG_RECEIVE_BOOT_COMPLETE_PRE);
                message->sendToTarget();
            }
            return true;
        }

        /**
         * @brief This is the virtual destructor function.
         *
         * @retval   void
         *
         */
        virtual ~systemPostReceiver() {}  // charles : add destructor

     private:
        android::sp<RegionInputManager::RegionHandler> mHandler;

        // @CGA_VARIANT_START{"class_BnSystemPostReceiver:systemPostReceiver"}
        /*
         * Write your own code
         */
        // @CGA_VARIANT___END{"class_BnSystemPostReceiver:systemPostReceiver"}
    };
    /* auto __ appmgr Inheritance CGA end-------------------------------------------------*/


 public:
    RegionInputManager();
    virtual ~RegionInputManager();

    virtual error_t init();
    virtual void handleBootComplete();

    android::sp<sl::SLLooper>& getLooper();
    void setLooper(const android::sp<sl::SLLooper>& looper);
    bool getBootComplete();

    void onReceiverBinderDied(const android::wp<android::IBinder>& who);
    void onServiceBinderDied(const android::wp<android::IBinder>& who);

    std::string getNadType();
    std::string getRegionId();
    std::string getHwRevision();
    error_t setHalSystemBootMode(uint32_t& bootMode);
    error_t setHalSystemNation(uint32_t& nation);
    uint32_t getHalSystemBootMode();
    uint32_t getHalSystemNation();
    uint8_t getNation();
    error_t memoryFileDelete(const uint8_t* file_path, uint16_t file_path_length);
    std::string getMcfgRegionId();
    android::sp<EnvironmentVariant> getVariantData();
    error_t setVariantData(const android::sp<EnvironmentVariant>& data);

 private:
    /* auto __ appmgr Inheritance CGA start-------------------------------------------------*/
    void connectToAppMgr();
    /* auto __ appmgr Inheritance CGA end-------------------------------------------------*/

    void connectToHealthMgr();

 private:
    android::sp<RegionHandler> mMyHandler;
    android::sp<sl::SLLooper> mLooper;
    mutable android::Mutex mBinderDiedLock;
    mutable android::Mutex mReceiverLock;

    /* auto __ appmgr Inheritance CGA start-------------------------------------------------*/
    android::sp<IApplicationManagerService> mAppManager;
    android::sp<ISystemPostReceiver> mSystemPostReceiver;
    /* auto __ appmgr Inheritance CGA end-------------------------------------------------*/


    android::sp< IHealthManagerService > mHealthManager;


    Timer* m_WatcdogTimer;
    RegionInputMgrTimer* mRegionInputMgrTimer;

    android::sp<ServiceDeathRecipient> mServiceDeathRecipient;

    bool mBootCompleted;
};

#endif /* SERVICELAYER_REGION_INPUT_MANAGER_H */
