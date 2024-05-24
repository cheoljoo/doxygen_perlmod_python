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
 *
 * @file
 * ConfigExtJob.h @n
 * Declaration of ConfigExtJob
 * @author
 *
 * @date
 * 2018.01.28
 */


#ifndef CONFIG_EXT_JOB_H
#define CONFIG_EXT_JOB_H

#include <utils/Mutex.h>
#include <utils/Vector.h>
#include "utils/Timer.h"
#include "utils/SLLooper.h"
#include "utils/Handler.h"
#include <services/ConfigurationManagerService/IConfigurationManagerServiceType.h>
#include <services/ConfigurationManagerService/IConfigurationManagerReceiver.h>
// #include "ConfigManager.h" -> Recursively included -> Meaningless

#include "Log.h"

class ConfigManager;

/**
 * Class ConfigExtJob
 */
class ConfigExtJob: public android::RefBase {
public:
    ConfigExtJob(ConfigManager& service);
    virtual ~ConfigExtJob();
    void Start(void);
private:
    ConfigManager& mConfigManager;
    static const uint32_t RETRY_TIMER_MS = 300;
    class ServiceDeathRecipient : public android::IBinder::DeathRecipient {
    public:
        ServiceDeathRecipient(ConfigExtJob& parent) : mConfigExt(parent) {}
        virtual ~ServiceDeathRecipient() {}
        virtual void binderDied(const android::wp<android::IBinder>& who) {
            mConfigExt.onServiceBinderDied(who);
        }
    private:
        ConfigExtJob& mConfigExt;
    };
    void onServiceBinderDied(const android::wp<android::IBinder>& who);
    android::sp<ServiceDeathRecipient> mServiceDeathRecipient = nullptr;

public :
    enum class EconfigExtHandlerID : int32_t {
        NONE
    };

    void configExtHandlerJob(EconfigExtHandlerID ExtJobID);

};
#endif //CONFIG_EXT_JOB_H
