/**
 * @copyright
 * Copyright (c) 2015 by LG Electronics Inc.
 * This program or software including the accompanying associated documentation
 * ("Software") is the proprietary software of LG Electronics Inc. and or its
 * licensors, and may only be used, duplicated, modified or distributed pursuant
 * to the terms and conditions of a separate written license agreement between you
 * and LG Electronics Inc. ("Authorized License"). Except as set forth in an
 * Authorized License, LG Electronics Inc. grants no license (express or implied),
 * rights to use, or waiver of any kind with respect to the Software, and LG
 * Electronics Inc. expressly reserves all rights in and to the Software and all
 * intellectual property therein. If you have no Authorized License, then you have
 * no rights to use the Software in any ways, and should immediately notify LG
 * Electronics Inc. and discontinue all use of the Software.
 * @file        ConfigManager.h
 * @brief       class for ConfigurationManagerService
 * @author
 *    copyright (c) 2018  Jaeho Choi <elliott.choi@lge.com>
 * @version     1.0.00
*/

#ifndef SERVICELAYER_CONFIG_MANAGER_SERVICE_H
#define SERVICELAYER_CONFIG_MANAGER_SERVICE_H

/* Standard library */
#include <unistd.h>
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
#include <tuple>

/* config manager header files*/
#include "ConfigManagerDefine.h"
#include "ConfigExtJob.h"
#include "DBManager.h"

/* tiger utils header files */
#include <utils/RefBase.h>
#include <utils/Buffer.h>
#include <utils/Mutex.h>
#include <utils/Timer.h>
#include <utils/Handler.h>

#include "Typedef.h"

#include <cutils/sockets.h>
#include <binder/IServiceManager.h>

#include "TCUProtocol.h"
#include "ConfigManagerProperty.h"
#include "Typedef.h"
#include <corebase/SystemService.h>
#include <systemd/sd-daemon.h>
#include <binder/BinderService.h>
#include <binder/Parcel.h>
#include <services/ConfigurationManagerService/IConfigurationManagerReceiver.h>
#include <services/ConfigurationManagerService/IConfigurationManagerService.h>
#include <services/ConfigurationManagerService/IConfigurationManagerServiceType.h>
#include <utils/watchdog/watchdog_client.h>
#include <services/PowerManagerService/PowerLock.h>

#ifdef __UT_BUILD__
#define private public
#endif

#define CONFIG_BUF_MAX_SIZE 255

/*
*
*    Class ConfigManager
*
*/

class ConfigExtJob;
class DBManager;

class ConfigManager : public SystemService
{

public:
    ConfigManager();
    virtual ~ConfigManager();

    /**
      inherit from SystemService
     */

    static const char* getServiceName() {return "service_layer.ConfigurationManagerService";};
    virtual error_t dump(LogOutput& out) { (void) out; return E_OK;}
    virtual uint8_t getModuleID() { return MODULE_CONFIGURATION_MGR; }
    virtual bool onInit();
    virtual error_t onStart();
    virtual error_t onStop() {return E_OK;}
    virtual void instantiate();

    /**
      refactoring APIs:
    */
    ConfigResponse getData(const DataFrom sourceType, const std::string& name);
    ConfigResult getConfigData(const DataFrom sourceType, const std::string& name, std::string& value);
    int32_t setData(const DataFrom sourceType, const std::vector<std::pair<std::string, std::string>>& storeData);
    error_t setConfigData(const DataFrom sourceType, const std::string name, const std::string value);
    bool isProvisioned(void);
    error_t registerReceiver(const DataFrom sourceType, const std::string& name, android::sp<IConfigurationManagerReceiver>& receiver);
    error_t unregisterReceiver(const DataFrom sourceType, const std::string& name, android::sp<IConfigurationManagerReceiver>& receiver);

    ConfigResult defaultDBSelect(const DataFrom sourceType, const int32_t dbIndex);
    ConfigResult dbReloadNeeded(const DataFrom sourceType, const Reload reloadReason, const std::string& location);
    dbStatus dbStatusQuery(const DataFrom sourceType, const Query queryReason, const std::string value);


    error_t
    registerDataChangedEvent(const android::sp<IConfigurationManagerReceiver> &receiver);

    error_t
    registerDataChangedEvent(const android::sp<IConfigurationManagerReceiver> &receiver,
                             const std::vector<std::string> &patterns);
    error_t
    unregisterDataChangedEvent(const android::sp<IConfigurationManagerReceiver> &receiver);

    error_t
    unregisterDataChangedEvent(const android::sp<IConfigurationManagerReceiver> &receiver,
                               const std::vector<std::string> &patterns);
    error_t
    registerUserInfoDeletedEvent(const android::sp<IConfigurationManagerReceiver> &receiver);

    error_t
    unregisterUserInfoDeletedEvent(const android::sp<IConfigurationManagerReceiver> &receiver);

    template <typename T>
    int32_t read(const std::string &pattern, T &data);

    template <typename T>
    int32_t write(const std::string &pattern, const T &data);

    int32_t remove(const std::string &pattern, int32_t idx);

    int32_t erase();

    ConfigResponse getJsonData(const DataFrom sourceType, const std::string& name);

    /**
      inner class
    */
    class ReceiverVectorTable : public RefBase
    {
    public:
        ReceiverVectorTable() : mSourceType(DataFrom::General), mName(""), mRegisteredReceiver(nullptr) {}
        virtual ~ReceiverVectorTable() {}
        DataFrom mSourceType;
        std::string mName;
        android::sp<IConfigurationManagerReceiver> mRegisteredReceiver;
    };

    class ConfigMgrWathdogTimer : public TimerTimeoutHandler
    {
    public:
        static const uint32_t TIMER_CONFIG_MANAGER_WATCHDOG = 1;
        ConfigMgrWathdogTimer(ConfigManager& mService): mService(mService) {}
        ~ConfigMgrWathdogTimer() {}
        virtual void handlerFunction(int);
    private:
        ConfigManager& mService;
    };

    /**
     *  Class for DeathRecipient
    */
    class ReceiverDeathRecipient : public android::IBinder::DeathRecipient
    {
    public:
        ReceiverDeathRecipient(ConfigManager& parent) : mParent(parent) {}
        virtual ~ReceiverDeathRecipient() {}
        virtual void binderDied(const android::wp<android::IBinder>& who)
        {
            mParent.onReceiverBinderDied(who);
        }
    private:
        ConfigManager& mParent;
    };


private:
    dbStatus debugCmd(std::string& name, std::string& value);
    std::string get_property(const char* name);
    bool set_property(const char* name, std::string& value);
    uint32_t getCurrentUPTime(void);
    void initWatchdogTimer();
    void onReceiverBinderDied(const android::wp<android::IBinder>& who);

private:
    class ServiceStub : public BnConfigurationManagerService
    {
    public:
        ServiceStub(ConfigManager& parent) : mParent(parent) { }

        ConfigResponse getData(const DataFrom sourceType, const std::string& name) override;
        ConfigResult getConfigData(const DataFrom sourceType,
                                   const std::string& name,
                                   std::string& value) override;
        int32_t setData(const DataFrom sourceType,
                        const std::vector<std::pair<std::string, std::string>>& storeData) override;
        error_t setConfigData(const DataFrom sourceType,
                              const std::string name,
                              const std::string value) override;
        bool isProvisioned(void) override;

        error_t registerReceiver(const DataFrom sourceType,
                                 const std::string& name,
                                 android::sp<IConfigurationManagerReceiver>& receiver) override;
        error_t unregisterReceiver(const DataFrom sourceType,
                                   const std::string& name,
                                   android::sp<IConfigurationManagerReceiver>& receiver) override;

        ConfigResult defaultDBSelect(const DataFrom sourceType, const int32_t dbIndex) override;
        ConfigResult dbReloadNeeded(const DataFrom sourceType,
                                    const Reload reloadReason,
                                    const std::string& location) override;

        dbStatus dbStatusQuery(const DataFrom sourceType,
                               const Query queryReason,
                               const std::string value) override;
        dbStatus debugCmd(std::string& name, std::string& value) override;


        error_t
        registerDataChangedEvent(const android::sp<IConfigurationManagerReceiver> &receiver)
        override;

        error_t
        registerDataChangedEvent(const android::sp<IConfigurationManagerReceiver> &receiver,
                                 const std::vector<std::string> &patterns) override;
        error_t
        unregisterDataChangedEvent(const android::sp<IConfigurationManagerReceiver> &receiver)
        override;

        error_t
        unregisterDataChangedEvent(const android::sp<IConfigurationManagerReceiver> &receiver,
                                   const std::vector<std::string> &patterns) override;
        error_t
        registerUserInfoDeletedEvent(const android::sp<IConfigurationManagerReceiver> &receiver)
        override;

        error_t
        unregisterUserInfoDeletedEvent(const android::sp<IConfigurationManagerReceiver> &receiver)
        override;

        int32_t read(const std::string &pattern, config::data_t &data) override;
        int32_t read(const std::string &pattern, bool &value) override;
        int32_t read(const std::string &pattern, int64_t &value) override;
        int32_t read(const std::string &pattern, double &value) override;
        int32_t read(const std::string &pattern, std::string &value) override;
        int32_t read(const std::string &pattern, std::vector<bool> &values) override;
        int32_t read(const std::string &pattern, std::vector<int64_t> &values) override;
        int32_t read(const std::string &pattern, std::vector<double> &values) override;
        int32_t read(const std::string &pattern, std::vector<std::string> &values) override;

        int32_t write(const std::string &pattern, const config::data_t &data) override;
        int32_t write(const std::string &pattern, bool value) override;
        int32_t write(const std::string &pattern, int64_t value) override;
        int32_t write(const std::string &pattern, double value) override;
        int32_t write(const std::string &pattern, const std::string &value) override;
        int32_t write(const std::string &pattern, const std::vector<bool> &values) override;
        int32_t write(const std::string &pattern, const std::vector<int64_t> &values) override;
        int32_t write(const std::string &pattern, const std::vector<double> &values) override;
        int32_t write(const std::string &pattern, const std::vector<std::string> &values) override;

        int32_t remove(const std::string &pattern, int32_t idx = -1) override;

        int32_t erase() override;

        ConfigResponse getJsonData(const DataFrom sourceType, const std::string& name) override;

    private:
        ConfigManager& mParent;
        friend class ConfigManager;
    };

    class MyHandler : public sl::Handler
    {
    public:
        MyHandler(android::sp<sl::SLLooper>& looper, ConfigManager& outer)
            : Handler(looper), mService(outer) {}
        virtual void handleMessage(const android::sp<sl::Message>& msg);

    private:
        ConfigManager& mService;
    };

private:
    android::sp<PowerLock> mPowerLock = nullptr;

    ConfigMgrWathdogTimer* mConfigMgrWathdogTimer = nullptr;
    android::sp<Timer> mWatchdogTimer = nullptr;

    android::Vector< android::sp<ReceiverVectorTable> > mConfigReceiver;
    android::sp<ReceiverDeathRecipient> mReceiverDeathRecipient = nullptr;

    android::sp<ConfigExtJob> mConfigExtJob = nullptr;
    uint32_t start_uptime = 0;
    uint32_t ready_uptime = 0;

public:
    enum class EconfigMgrHandlerID : int32_t {
        MESSAGE_WATCHDOG_TIMER = 0,
        MESSAGE_SECURITY_CHECK,
        MESSAGE_ON_CONFIG_DATA_CHANGED,
        MESSAGE_CONFIG_EXT_JOB
    };

    android::sp<DBManager> mDBManager;
    android::sp<MyHandler> mHandler = nullptr;
    mutable Mutex mRegisterLock;
};

#endif // SERVICELAYER_CONFIG_MANAGER_SERVICE_H
