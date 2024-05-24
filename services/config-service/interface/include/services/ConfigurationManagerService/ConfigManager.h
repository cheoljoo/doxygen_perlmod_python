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
 * @if (CGA)
 *  @CGA_INCLUDE{ConfigManager.h}
 * @endif
 *
 */

#ifndef _TIGER_SDK_CONFIG_MANAGER_H_
#define _TIGER_SDK_CONFIG_MANAGER_H_

#include <list>
#include <vector>
#include <utility>

#include "Error.h"
#include "services/ConfigurationManagerService/IConfigurationManagerService.h"
#include "services/ConfigurationManagerService/IConfigurationManagerServiceType.h"


/*
 * verion number =  major change, B: refactoring or structure change, C: minor change (ex) 1.12.133)
*/


class ConfigManager : public android::RefBase
{
    public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
        ConfigManager();
        virtual ~ConfigManager();
#endif
        static ConfigManager* instance();
#ifndef DOXYGEN_SHOULD_SKIP_THIS
        void onBinderDied(const android::wp<android::IBinder>& who);
#endif

        ConfigResponse getData(const DataFrom sourceType, const std::string& name);
        int32_t setData(const DataFrom sourceType, const std::vector<std::pair<std::string, std::string>>& storeData);
        error_t registerReceiver(const DataFrom sourceType, const std::string& name, android::sp<IConfigurationManagerReceiver>& receiver);
        error_t unregisterReceiver(const DataFrom sourceType, const std::string& name, android::sp<IConfigurationManagerReceiver>& receiver);

        ConfigResult defaultDBSelect(const DataFrom sourceType, const int32_t dbIndex);
        ConfigResult dbReloadNeeded(const DataFrom sourceType, const Reload reloadReason, const std::string& location);
        dbStatus dbStatusQuery(const DataFrom sourceType, const Query queryReason, const std::string value);

        bool isProvisioned();

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
        int32_t write(const std::string &pattern, const T &value);

        template <typename T>
        int32_t add(const std::string &pattern, const T &value);

        int32_t remove(const std::string &pattern, int32_t idx);

        int32_t erase();

        ConfigResponse getJsonData(const DataFrom sourceType, const std::string& name);

    private:
        android::sp<IConfigurationManagerService> getService();

        /**
         *  Class for DeathRecipient
         */
        class ManagerDeathRecipient : public android::IBinder::DeathRecipient
    {
        public:
            explicit ManagerDeathRecipient(ConfigManager& parent) : mParent(parent) {}
            virtual ~ManagerDeathRecipient() {}
            virtual void binderDied(const android::wp<android::IBinder>& who) {
                mParent.onBinderDied(who);
            }
        private:
            ConfigManager& mParent;
    };

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    private:
        static bool DEBUG;
#endif

    private:
        static ConfigManager* mInstance;
        android::sp<ManagerDeathRecipient> mDeathRecipient;
        android::sp<IConfigurationManagerService> mConfigService;
        android::sp<IConfigurationManagerReceiver> mConfigReceiver;
        std::list<std::pair<std::string, std::string>> itemList;
};

#endif // _TIGER_SDK_CONFIG_MANAGER_H_
