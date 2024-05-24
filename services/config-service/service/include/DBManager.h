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
 * @file        DBManager.h
 * @brief       class for DBManager. It handles ConfigurationMangager DB.
 * @author
 *    copyright (c) 2018  Jaeho Choi <elliott.choi@lge.com>
 * @version     1.0.00
*/

#ifndef SERVICELAYER_CONFIG_MANAGER_DBMANAGER_H
#define SERVICELAYER_CONFIG_MANAGER_DBMANAGER_H

// #include "ConfigManager.h" -> Recursively included -> Meaningless
#include "ConfigManagerDefine.h"
#include "XmlFileLib.h"
// #include "DBBase.h"  -> Recursively included -> Meaningless
#include "Error.h"
#include <tuple>

class ConfigManager;
class XmlFileLib;
class DBBase;

class DBManager : public android::RefBase {
public:
    DBManager(android::sp<ConfigManager> _mConfigManager);
    virtual ~DBManager();
    ConfigResponse getData(const DataFrom sourceType, const std::string& name);
    ConfigResponse getDataSet(const DataFrom sourceType, const std::string& name);
    ConfigResult getConfigData(const DataFrom sourceType, const std::string& name, std::string& value);
    int32_t setData(const DataFrom sourceType, const std::vector<std::pair<std::string, std::string>>& storeData);
    error_t setConfigData(const DataFrom sourceType, const std::string name, const std::string value);
    bool isProvisioned(void);

    void createDB();
    void postUpdateDB(std::string name, bool updateFromSetData);
    ConfigResult dbReloadNeeded(const DataFrom sourceType, const Reload reloadReason, const std::string& location);

    void setMnoData(const Mno mnoType, const std::string& mnoData);

    dbStatus dbStatusQuery(const DataFrom sourceType, const Query queryReason, const std::string& value);
    void checkSecurity();
    std::string getStringFromDataFrom(DataFrom sourceType);
    error_t initializePath(DataFrom sourceType);

    ConfigResponse getJsonData(const DataFrom sourceType, const std::string& name);
    ConfigResponse getJsonDataSet(const DataFrom sourceType, const std::string& name);

private:
    android::sp<ConfigManager> mConfigManager;
    android::sp<DBBase> mDBBase;
    bool mIsProvisioned;
#if USE_ONE_FILE == 1
    android::sp<XmlFileLib> mXmlFileLib;
    std::string mPathOfXmlFile = CONFIGMGR_FULLPATH;
#else //USE_ONE_FILE
    std::vector<android::sp<XmlFileLib>> mXmlFileLib;
    std::string mPathOfXmlFile[3] = {
       GENERAL_DATA_FULLPATH,
       DEFAULT_PROV_FULLPATH,
       PROVISIONING_FULLPATH
    };
#endif //USE_ONE_FILE
};
#endif
