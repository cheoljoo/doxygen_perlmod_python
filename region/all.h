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

#ifndef SERVICELAYER_REGION_EXT_BASE_H
#define SERVICELAYER_REGION_EXT_BASE_H

/**
* @MISRA{MISRA C++-2008 Rule 16-2-1,"This is intended design"}
*/
#include <binder/IBinder.h>
#include <binder/IInterface.h>

#include <utils/Handler.h>
#include <utils/SLLooper.h>
#include <utils/Timer.h>
#include <utils/external/mindroid/lang/String.h>
#include <utils/Mutex.h>

#include <services/RegionManagerService/RegionCommand.h>

#include <string>

class RegionExtBase : public virtual android::RefBase {
 public:
    RegionExtBase() {};
    virtual ~RegionExtBase() {};

    virtual error_t init(android::sp<sl::SLLooper>& looper) = 0;
    virtual void handleBootComplete() = 0;

    /*GEN12*/ virtual uint8_t getNadType() { return 0; }
    /*GEN12*/ virtual uint8_t getRegionId() { return 0; }
    /*GEN12*/ virtual uint8_t getHwRevision() { return 0; }
    /*GEN12*/ virtual uint8_t getMcfgRegionId() { return 0; }
    /*24dcm*/ virtual error_t setHalSystemBootMode(uint32_t& bootMode) { return E_OK; }
    /*24dcm*/ virtual error_t setHalSystemNation(uint32_t& nation) { return E_OK; }
    /*24dcm*/ virtual uint32_t getHalSystemBootMode() { return 0; }
    /*24dcm*/ virtual uint32_t getHalSystemNation() { return 0; }
    /*24dcm*/ virtual uint8_t getNation() { return 0; }
    /*24dcm*/ virtual error_t memoryFileDelete(size_t& file_path_length, uint8_t* file_path) { return E_OK; }
    /*ICON*/  virtual android::sp<EnvironmentVariant> getVariantData() { mVariantData = new EnvironmentVariant(); return mVariantData; }
    /*ICON*/  virtual error_t setVariantData(const android::sp<EnvironmentVariant>& data) { return E_OK; }

 private:
    android::sp<EnvironmentVariant> mVariantData;  // dummy variant data
};
typedef RegionExtBase* create_t();
#endif /* SERVICELAYER_REGION_EXT_BASE_H */

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

/* auto __ appmgr Inheritance CGA start-------------------------------------------------*/
#include "services/ApplicationManagerService/ApplicationManager.h"
/* auto __ appmgr Inheritance CGA end-------------------------------------------------*/


#include <services/RegionManagerService/RegionCommand.h>

// @CGA_VARIANT_START{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}
#include "RegionExtBase.h"

// @CGA_VARIANT___END{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}


class RegionManagerService;



enum {
    MSG_RECEIVE_BOOT_COMPLETE = 1,
    MSG_RECEIVE_WATCH_DOG,
    MSG_BOOT_COMPLETE_DID_START,
    MSG_SIGNAL_INTERNAL_IGNITION2_STATUS,
    /* auto __ app manager  Inheritance CGA start-------------------------------------------------*/
    MSG_CONNECT_TO_APPMGR,
    /* auto __ app manager  Inheritance CGA end-------------------------------------------------*/
    MSG_RECEIVE_BOOT_COMPLETE_PRE,
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
class RegionInputManager: public android::RefBase
{
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
        /**
         * @brief This is the handle function of the input manager.
         *
         * @param[in] msg     Message for handler
         * @retval   void
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionInputManager:handleMessage()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionInputManager:handleMessage()"}
         */
        virtual void handleMessage(const android::sp<sl::Message>& msg);

    private:
        RegionInputManager& mRegionInputMgr;
    };

    class RegionInputMgrTimer : public TimerTimeoutHandler {
    public:
        /* Timer ID */
        static const uint32_t REGION_WATCHDOG_TIMER = 1;

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
                switch(timer_id) {
                    case REGION_WATCHDOG_TIMER:
                        mHandler->obtainMessage(MSG_RECEIVE_WATCH_DOG)->sendToTarget();
                        break;
                    default :
                        break;
                    }
        }

    private:
        android::sp<RegionInputManager::RegionHandler> mHandler;

        // @CGA_VARIANT_START{"class_RegionInputManager_H:RegionInputMgrTimer"}
            /*
             * Write your own code
             */
        // @CGA_VARIANT___END{"class_RegionInputManager_H:RegionInputMgrTimer"}

    };

    /**
     * @brief When the services are died, it is where you put the code to reconnect.
     *
     * @param[in] who     who generates Dead state
     * @retval   void
     *
     */
    void onServiceBinderDied(const android::wp<android::IBinder>& who);

    class ServiceDeathRecipient : public android::IBinder::DeathRecipient {
    public:
        /**
         * @brief This is the constructor function for the ServiceDeathRecipient.
         *
         * @param[in] parent     RegionInputManager
         * @retval   void
         *
         */
        ServiceDeathRecipient(RegionInputManager& parent) : mParent(parent) {}

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

        // @CGA_VARIANT_START{"class_ServiceDeathRecipient:ServiceDeathRecipient"}
            /*
             * Write your own code
             */
        // @CGA_VARIANT___END{"class_ServiceDeathRecipient:ServiceDeathRecipient"}

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
        systemPostReceiver(android::sp<RegionInputManager::RegionHandler> handler) : mHandler(handler) {}  // charles : remove explicit & change the name

        /**
         * @brief This is the function to receive system post event.
         *
         * @param[in] systemPost     android Post
         * @retval   void
         *
         */
        virtual bool onSystemPostReceived(const android::sp<Post>& systemPost) {
            if (SYS_POST_IS_CONTAIN(systemPost->what, SYS_POST_BOOT_COMPLETED) == true) {
               LOGV("systemPostReceiver Boot Complete");   // charles : chage the name (log)
               android::sp<sl::Message> message = mHandler->obtainMessage(MSG_RECEIVE_BOOT_COMPLETE);
               message->sendToTarget();
            } else if (SYS_POST_IS_CONTAIN(systemPost->what, SYS_POST_BOOT_COMPLETED_PRE) == true) {
                LOGV("systemPostReceiver Boot Complete Pre");   // charles : chage the name (log)
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
        /**
         * @brief It is a function for the constructor of the input manager class.
         *
         * @param[in] mRegionMgrService android::sp<RegionManagerService>
         * @retval   void
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionInputManager::RegionInputManager_MISRA"}
         * @MISRA{MISRA C++-2008 Rule 2-10-2,This is intended design}
         * @CGA_VARIANT___END{"DOXYGEN:RegionInputManager::RegionInputManager_MISRA"}
         *
         */
        RegionInputManager(android::sp<RegionManagerService> mRegionMgrService);
        /**
         * @brief It is a function for the destructor of the input manager class.
         *
         * @retval   void
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionInputManager:~RegionInputManager()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionInputManager:~RegionInputManager()"}
         */
        virtual ~RegionInputManager();
        /**
         * @brief It is a function for the initialization of the input manager.
         *
         * @retval   void
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionInputManager:Init()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionInputManager:Init()"}
         */
        error_t init();


    private:
        /* auto __ appmgr Inheritance CGA start-------------------------------------------------*/
        /**
         * @brief When appmgr service is died, it is where you put the code to reconnect.
         *
         * @retval   void
         *
         * @CGA_VARIANT_START{"DOXYGEN:RegionInputManager:connectToAppMgr()"}
         * @details
         * @CGA_VARIANT___END{"DOXYGEN:RegionInputManager:connectToAppMgr()"}
         */
        void connectToAppMgr();
        /* auto __ appmgr Inheritance CGA end-------------------------------------------------*/



    private:
        android::sp<RegionManagerService> mRegionMgrService;
        android::sp<RegionHandler> mMyHandler;
        mutable android::Mutex mBinderDiedLock;

        /* auto __ appmgr Inheritance CGA start-------------------------------------------------*/
        android::sp<ApplicationManager> mAppManager;
        android::sp<ISystemPostReceiver> mSystemPostReceiver;
        /* auto __ appmgr Inheritance CGA end-------------------------------------------------*/




        Timer* m_WatcdogTimer;
        RegionInputMgrTimer* mRegionInputMgrTimer;

        android::sp<ServiceDeathRecipient> mServiceDeathRecipient;

        // @CGA_VARIANT_START{"class_RegionInputManager"}
    public:
        void handleBootComplete();
        uint8_t getNadType();
        uint8_t getRegionId();
        uint8_t getHwRevision();
        error_t setHalSystemBootMode(uint32_t& bootMode);
        error_t setHalSystemNation(uint32_t& nation);
        uint32_t getHalSystemBootMode();
        uint32_t getHalSystemNation();
        uint8_t getNation();
        error_t memoryFileDelete(size_t& file_path_length, uint8_t* file_path);
        uint8_t getMcfgRegionId();
        android::sp<EnvironmentVariant> getVariantData();
        error_t setVariantData(const android::sp<EnvironmentVariant>& data);

    private:
        void *mDLextlib;
        RegionExtBase* m_regionVariant;
        // android::sp<RegionExtBase> mRegionExtBase;

        error_t createVariantImpl(void);
        // @CGA_VARIANT___END{"class_RegionInputManager"}

};

#endif /* SERVICELAYER_REGION_INPUT_MANAGER_H */

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

#ifndef _SERVICELAYER_XXCLASS_ENVIRONMENTVARIANT_H_
#define _SERVICELAYER_XXCLASS_ENVIRONMENTVARIANT_H_

#include <string>
#include "Typedef.h"

#include "utils/Buffer.h"

#include "utils/external/mindroid/lang/String.h"
#include "Log.h"
#include "Error.h"
#include <binder/Parcel.h>
#include <utils/RefBase.h>
#include "EnvironmentVariant.h"



// @CGA_VARIANT_START{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}
/*
 * Write your own additional code
 * add your #include
 * add your global declare the function and variables
 * add your function
 */
/// @CGA_VARIANT___END{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}


#pragma pack(1)

typedef struct {
    std::string ecu;
    std::string hwVar;
    std::string revision;
    int8_t modelYear;
    int8_t housingVariant;
    int8_t mobileStandard;
    int8_t countryEquipment;
    int8_t v2xType;
    int8_t mobilePresent;
    int8_t v2xPresent;
    int8_t wlanPresent;
    int8_t btPresent;
} EnvironmentVariantDataFormat;

#pragma pack()


/**
 * @brief data class : EnvironmentVariant
 * @details EnvironmentVariant class
 */
class EnvironmentVariant : public android::RefBase {
public:
    /**
     * @brief constructor of the EnvironmentVariant data class.
     *
     */
    EnvironmentVariant();
    /**
     * @brief copy operator of the EnvironmentVariant data class.
     *
     * @param[in] other EnvironmentVariant
     *
     */
    EnvironmentVariant(const EnvironmentVariant& other);
    /**
     * @brief destructor of the EnvironmentVariant data class.
     *
     */
    virtual ~EnvironmentVariant();
    /**
     * @brief = operator of the EnvironmentVariant data class.
     *
     * @param[in] other EnvironmentVariant
     * @retval   EnvironmentVariant
     *
     */
    EnvironmentVariant& operator=(const EnvironmentVariant& other);
    /**
     * @brief It is for setting to EnvironmentVariant of the EnvironmentVariant data class.
     *
     * @param[in] other EnvironmentVariant
     * @retval   void
     *
     */
    void setTo(const EnvironmentVariant& other);
    /**
     * @brief This function is for writing parcel of the EnvironmentVariant data class.
     *
     * @param[in] parcel android Parcel
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     *
     */
    error_t writeToParcel(android::Parcel* parcel);
    /**
     * @brief This function is for reading from parcel of the EnvironmentVariant data class.
     *
     * @param[in] parcel android Parcel
     * @retval   error_t   If success, return E_OK, otherwise, return E_ERROR.
     *
     */
    error_t readFromParcel(const android::Parcel& parcel);
    /**
     * @brief This is a function that displays data in the EnvironmentVariant data class.
     *
     * @retval void
     *
     */
    void toString();
    /**
     * @brief This is a function that displays data by a specific name in the EnvironmentVariant data class.
     *
     * @param[in] from  printing data
     * @retval void
     *
     */
    void toString(const char* from);
    /**
     * @brief This function is for getting Ecu of the EnvironmentVariant data class.
     *
     * @retval  std::string
     *
     */
    std::string  getEcu();
    /**
     * @brief This function is for getting V2xPresent of the EnvironmentVariant data class.
     *
     * @retval  int8_t
     *
     */
    int8_t  getV2xPresent();
    /**
     * @brief This function is for getting WlanPresent of the EnvironmentVariant data class.
     *
     * @retval  int8_t
     *
     */
    int8_t  getWlanPresent();
    /**
     * @brief This function is for getting BtPresent of the EnvironmentVariant data class.
     *
     * @retval  int8_t
     *
     */
    int8_t  getBtPresent();
    /**
     * @brief This function is for getting HwVar of the EnvironmentVariant data class.
     *
     * @retval  std::string
     *
     */
    std::string  getHwVar();
    /**
     * @brief This function is for getting Revision of the EnvironmentVariant data class.
     *
     * @retval  std::string
     *
     */
    std::string  getRevision();
    /**
     * @brief This function is for getting ModelYear of the EnvironmentVariant data class.
     *
     * @retval  int8_t
     *
     */
    int8_t  getModelYear();
    /**
     * @brief This function is for getting HousingVariant of the EnvironmentVariant data class.
     *
     * @retval  int8_t
     *
     */
    int8_t  getHousingVariant();
    /**
     * @brief This function is for getting MobileStandard of the EnvironmentVariant data class.
     *
     * @retval  int8_t
     *
     */
    int8_t  getMobileStandard();
    /**
     * @brief This function is for getting CountryEquipment of the EnvironmentVariant data class.
     *
     * @retval  int8_t
     *
     */
    int8_t  getCountryEquipment();
    /**
     * @brief This function is for getting V2xType of the EnvironmentVariant data class.
     *
     * @retval  int8_t
     *
     */
    int8_t  getV2xType();
    /**
     * @brief This function is for getting MobilePresent of the EnvironmentVariant data class.
     *
     * @retval  int8_t
     *
     */
    int8_t  getMobilePresent();

    /**
     * @brief function for setting data into EnvironmentVariantDataFormat structure
     *
     * @param[in] df  EnvironmentVariantDataFormat structure
     * @param[in] mecu  
     * @param[in] mv2xPresent  
     * @param[in] mwlanPresent  
     * @param[in] mbtPresent  
     * @param[in] mhwVar  
     * @param[in] mrevision  
     * @param[in] mmodelYear  
     * @param[in] mhousingVariant  
     * @param[in] mmobileStandard  
     * @param[in] mcountryEquipment  
     * @param[in] mv2xType  
     * @param[in] mmobilePresent  
     * @retval   void
     *
     */
    void setDataFormat(
        EnvironmentVariantDataFormat& df
        , const std::string& mecu
        , const std::string& mhwVar
        , const std::string& mrevision
        , int8_t mmodelYear
        , int8_t mhousingVariant
        , int8_t mmobileStandard
        , int8_t mcountryEquipment
        , int8_t mv2xType
        , int8_t mmobilePresent
        , int8_t mv2xPresent
        , int8_t mwlanPresent
        , int8_t mbtPresent);

    /**
     * @brief It is function for setting data of the EnvironmentVariant data class.
     *
     * @param[in] mecu  
     * @param[in] mv2xPresent  
     * @param[in] mwlanPresent  
     * @param[in] mbtPresent  
     * @param[in] mhwVar  
     * @param[in] mrevision  
     * @param[in] mmodelYear  
     * @param[in] mhousingVariant  
     * @param[in] mmobileStandard  
     * @param[in] mcountryEquipment  
     * @param[in] mv2xType  
     * @param[in] mmobilePresent  
     * @retval   void
     *
     */
    void setData(
            const std::string& mecu
            , const std::string& mhwVar
            , const std::string& mrevision
            , int8_t mmodelYear
            , int8_t mhousingVariant
            , int8_t mmobileStandard
            , int8_t mcountryEquipment
            , int8_t mv2xType
            , int8_t mmobilePresent
            , int8_t mv2xPresent
            , int8_t mwlanPresent
            , int8_t mbtPresent);

private:
    void init();
    std::string  ecu;
    std::string  hwVar;
    std::string  revision;
    int8_t  modelYear;
    int8_t  housingVariant;
    int8_t  mobileStandard;
    int8_t  countryEquipment;
    int8_t  v2xType;
    int8_t  mobilePresent;
    int8_t  v2xPresent;
    int8_t  wlanPresent;
    int8_t  btPresent;
};


#endif /** _SERVICELAYER_XXCLASS_ENVIRONMENTVARIANT_H_ */

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

#ifndef _IREGION_MANAGER_SERVICE_TYPE_H_
#define _IREGION_MANAGER_SERVICE_TYPE_H_

/*
* @MISRA{MISRA C++-2008 Rule 16-2-1,"This is intended design"}
*/
#define REGION_SRV_NAME    "service_layer.RegionManagerService"

// @CGA_VARIANT_START{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}

    typedef enum {
        /**< None */
        LGE_REGION_NONE = 0,
        /**< Japan */
        LGE_REGION_JP,
        /**< China */
        LGE_REGION_CN,
        /**< North America */
        LGE_REGION_NA,
        /**< Australia */
        LGE_REGION_AU,
        /**< Saudi */
        LGE_REGION_SA,
         /**< UAE */
        LGE_REGION_AE,
        /**< India */
        LGE_REGION_IN,
        /**< Bahrain */
        LGE_REGION_BH,
        /**< Qatar */
        LGE_REGION_QA,
        /**< Kuwait */
        LGE_REGION_KW,
        /**< New Zealand */
        LGE_REGION_NZ,
        /**< Korea */
        LGE_REGION_KR,
        /**< Taiwan */
        LGE_REGION_TW,
        /**< Global */
        LGE_REGION_GLOBAL,
        /**< Reserved */
        LGE_REGION_RESERVE,
        LGE_REGION_MAX
    } LGE_REGION;

    typedef enum {
        /**< Unknown - initial */
        NAD_REGION_UKN = 0 ,
        /**< North America */
        NAD_REGION_NA ,
        /**< Mexico */
        NAD_REGION_MEX ,
        /**< ROW SA */
        NAD_REGION_ROW_SA ,
        /**< ROW Europe */
        NAD_REGION_ROW_EU ,
        /**< ROW Korea / Middle East */
        NAD_REGION_ROW_KRME ,
        /**< UDA */
        NAD_REGION_UDA ,
        /**< China */
        NAD_REGION_CHN ,
        NAD_REGION_MAX
    } NAD_REGION;

    typedef enum {
        /**< Unknown - initial */
        NAD_TYPE_UKN = 0 ,
        /**< CSAV type */
        NAD_TYPE_CSAV ,
        /**< NonCSAV type */
        NAD_TYPE_NON_CSAV ,
        NAD_TYPE_MAX
    } NAD_TYPE;

    typedef enum {
        /**< Unknown - initial */
        NAD_REVISION_UKN = 0 ,
        /**< Rev A */
        NAD_REVISION_A ,
        /**< Rev B */
        NAD_REVISION_B ,
        /**< Rev C */
        NAD_REVISION_C ,
        /**< Rev D */
        NAD_REVISION_D ,
        /**< Rev E */
        NAD_REVISION_E ,
        /**< Rev F */
        NAD_REVISION_F ,
        /**< Rev G */
        NAD_REVISION_G ,
        /**< Rev H */
        NAD_REVISION_H ,
        NAD_REVISION_MAX
    } NAD_REVISION;

    typedef enum {
        /**< Unknown - initial */
        NAD_MCFG_REGION_UKN = 0 ,
        /**< Korea */
        NAD_MCFG_REGION_KR ,
        /**< Middle East */
        NAD_MCFG_REGION_ME ,
        NAD_MCFG_REGION_MAX
    } NAD_MCFG_REGION;

// @CGA_VARIANT___END{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}

#endif

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

#ifndef _SERVICELAYER_REGIONNOSTIC_COMMAND_H_
#define _SERVICELAYER_REGIONNOSTIC_COMMAND_H_

#include "Typedef.h"

#include "utils/Buffer.h"

#include "utils/external/mindroid/lang/String.h"
#include "Error.h"
#include <binder/Parcel.h>
#include <utils/RefBase.h>

// @CGA_VARIANT_START{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}
/*
 * Write your own additional code
 * add your #include
 * add your global declare the function and variables
 * add your function
 */
/// @CGA_VARIANT___END{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}

#define REGION_SLDD_TEST

#define REGION_BOOTING_WAIT_TIME                  5
#define REGION_TIME_OUT                           0


#define REGIONDATA_BUFSIZE    (4 * 1024)

#define DID_READ_REQUEST    0x11
#define DID_WRITE_REQUEST   0x01

#define DID_READ_RESPONSE   0x10
#define DID_WRITE_RESPONSE  0x00

#define DATA_ID_SIZE        (2)

#define DATA_EMPTY_SIZE     (1)

#define PAYLOAD_SIZE        400U
#define SIGNAL_INTERNAL_REGION_BASE 0x0001

/**
* @MISRA{MISRA C++-2008 Rule 16-2-1,This is intended design}
*/
#define DID_WORK_FOR_DEFINE_0   0x0001
#define DID_WORK_FOR_DEFINE_1   0x0002
#define DID_WORK_FOR_DEFINE_2   0x0003
#define DID_WORK_FOR_DEFINE_3   0x0004
#define DID_WORK_FOR_DEFINE_4   0x0005
#define DID_WORK_FOR_DEFINE_5   0x0006
#define DID_WORK_FOR_DEFINE_6   0x0007
#define DID_WORK_FOR_DEFINE_7   0x0008
#define DID_WORK_FOR_DEFINE_8   0x0009
#define DID_WORK_FOR_DEFINE_9   0x000A

/**
* @MISRA{MISRA C++-2008 Rule 18-2-1,This is intended design}
*/
#define REGIONDATA_HEAD  (offsetof(regionDataFormat, data) )


#include "EnvironmentVariant.h"


#endif /** _SERVICELAYER_REGIONNOSTIC_COMMAND_H_  */

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


namespace Flight
{
    void fly();
    namespace details
    {
        int speed;
        void thrust() { return fly(); }
        class Animal
        {
        public:
            void task() {}
        }
        class Elephant : Animal
        {
        public:
            void task() {}
        }

        namespace 3rd
        {

            class Tiger :  Flight::Cat
            {
            public:
                void task() {}
            }

            class Cheetah : Cat
            {
            public:
                void task() {}
            }
        }
    }

    int fuel(){...};
    int air(){int i}{return details::speed; }

    class Cat : RegionManager
    {
    public:
        void task() {}
    }
    class Dog : Cat
    {
    public:
        void task() {}
    }

}
