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
 * @file        DBBase.h
 * @brief       class for DBBase which is base class for DAS, OTA, CODING.
 * @author
 *    copyright (c) 2018  Jaeho Choi <elliott.choi@lge.com>
 * @version     1.0.00
*/
#ifndef _DB_BASE_H_
#define _DB_BASE_H_

#include "DBManager.h"

#include <cstring>
#include <memory>
#include <fstream>

#define DEBUG_IOSTREAM 0

#include <system_property.h>

enum class DBState {
    /** Initial state of DB ex). power on */
    INIT,
    /** Read, Parse complete */
    LOADED,
    /** No Raw DB File*/
    NO_FILE,
    /** Parse error*/
    PARSE_ERROR,
    /** undefined state.*/
    StateMax
};

class DBManager;

class DBBase : public android::RefBase {
public:
    DBBase(android::sp<DBManager> _mDBManager);
    virtual ~DBBase();
    virtual void buildDB(Reload reason);
    virtual bool open(std::string& path);
    virtual bool parse(std::string& path);
    virtual std::unique_ptr<DBBase> reload(const Reload reloadReason, const std::string& location);
    virtual ProvisioningResponse get(const std::string& name);
    virtual int32_t set(const std::vector<std::pair<std::string, std::string>>& storeData);
    virtual void setReloadDBPath(const std::string& path);

    virtual void setActiveIndex(const std::string& v);
    virtual std::string getActiveIndex() const ;
    virtual void updateMNO(const Mno mnoType, const std::string& mnoInfo);
    virtual DataFrom getSource(const std::string name) const;
    virtual void setDBState(const DBState state);
    virtual DBState getDBState() const;
    virtual ConfigResult getErrorCause() const;
    virtual dbStatus statusQuery(const Query reason, const std::string& value);
    virtual bool filteredDB();
    virtual void createFile(std::string& path);
    virtual void deleteFile(std::string& path);
    virtual void checkSecurity();
    std::string dbPath;
    std::string dbName;
    int32_t fileStatus = 0;
    int32_t parseStatus = 0;

protected:
    std::string sInfo;
    std::string nInfo;
public:
    DBState state = DBState::INIT;
private:
    android::sp<DBManager> mDBManager;
};

#endif //_DB_BASE_H_
