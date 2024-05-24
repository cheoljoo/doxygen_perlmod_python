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
 * @file        IConfigurationManagerService.h
 * @brief       Declaration of IConfigurationManagerService.h
 * @author
 *    copyright (c) 2015  Jungwook Hong <Jungwook.hong@lge.com>
 *    copyright (c) 2019  Jaeho Choi <elliott.choi@lge.com>
 * @version     2.0.00
*/


/** @defgroup CONFIGMGR ConfigurationManager
 * This is the ConfiManager group and it describes Interface for ConfigManager. \n
 * When application or service needs configuration/provisioning information from oem configuration file, It could be obatined by these APIs. \n
 * To use these APIs, App or Service shall get <IConfigurationManagerService> \n\n
 * @note Here is the example
 * @verbatim

      #include "services/ConfigurationManagerService/IConfigurationManagerService.h"
      #include "services/ConfigurationManagerService/IConfigurationManagerServiceType.h"

      android::sp<IConfigurationManagerService> config;
      config = interface_cast<IConfigurationManagerService>(defaultServiceManager()->getService(String16(CONFIGURATION_SRV_NAME)));

      config->getData(ProvisioningData,"name");

@endverbatim
 */

/** @defgroup CONFIGMGR_CB ConfigurationManager Callback
 *  @ingroup CONFIGMGR
 *  These are ConfigurationManager Callback function.  Since these functions are pure virtual funtion, application shall implement their own receiver function.  \n
 *
 * @startuml
 * hide footbox
 * participant App #99FF99
 *
 * App -> ConfigManager : registerReceiver(ProvisioningData,name, receiver)
 *
 * ConfigManager -> DBManager : registerReceiver(ProvisioningData,name, receiver)
 *
 * activate DBManager
 * create control callback
 *
 * DBManager -> callback
 * DBManager <- callback
 * ConfigManager <- DBManager : result
 * Deactivate DBManager
 * App <- ConfigManager : result
 *
 * DBManager <- callback : changedName
 * ConfigManager <- DBManager : onConfigDataChanged(name,value)
 * App <- ConfigManager : receiver(name,value)
 * @enduml
 *
 *
 *
 *  @note Here is the example of ConfigurationManagerReceiver Callback. But parameter will be changed
 *  @verbatim
    class ConfigReceiver : public BnConfigurationManagerReceiver {
    public:
        ConfigReceiver(XXXXManagerService& c): mParent(c) {}
        virtual ~ConfigReceiver() {}

        virtual void onConfigDataChanged(std::string& name, std::string& value) {
            mParent.onConfigDataChanged(name, value);
        }
        virtual void onConfigDataChanged(android::sp<Buffer>& name) {}
    private:
        XXXXManagerService& mParent;
    };

    void XXXXManagerService::onConfigDataChanged(std::string& name, std::string& value) {
        LOGV("name = %s , value value = %s", name.c_str(), value.c_str());
    }
   @endverbatim
 */

/** @defgroup CONFIGMGR_API ConfigurationManager API
 *  @ingroup CONFIGMGR
 *  Application would set Configuration data with these APIs. \n
 *  Application would set Configuration data with these APIs. \n
 *  App/Service get oem configuration/provisioning data with these functions. \n
 */

#ifndef IConfiguration_MANAGER_SERVICE_H
#define IConfiguration_MANAGER_SERVICE_H

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <iostream>
#include <utility>
#include <vector>

#include "Typedef.h"
#include "utils/Buffer.h"

#include "services/ConfigurationManagerService/IConfigurationManagerReceiver.h"
#include "services/ConfigurationManagerService/IConfigurationManagerServiceType.h"

/**
 * Read and Write the OEM provided data.\n
 * Refer each method function description and sample codes (ConfigApplication.cpp and ConfigApplication.h) \n
 * @author
 *    copyright (c) 2015  Jungwook Hong <Jungwook.hong@lge.com> \n
 *    copyright (c) 2017  Jaeho Choi <elliott.choi@lge.com>
 * @note
 * ConfigurationManagerService's name is @b "service_layer.ConfigurationManagerService"
 *
 */
class IConfigurationManagerService : public android::IInterface
{

public:

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    enum
    {
        TRANSACTION_getData = android::IBinder::FIRST_CALL_TRANSACTION,
        TRANSACTION_getConfigData,
        TRANSACTION_setData,
        TRANSACTION_setConfigData,
        TRANSACTION_isProvisioned,
        TRANSACTION_registerReceiver,
        TRANSACTION_unregisterReceiver,
        TRANSACTION_defaultDBSelect,
        TRANSACTION_dbReloadNeeded,
        TRANSACTION_register_receiver,
        TRANSACTION_unregister_receiver,
        TRANSACTION_query_db_status,
        TRANSACTION_slddcmd,
        TRANSACTION_REGISTER_SOME_DATA_CHANGED_EVENT,
        TRANSACTION_REGISTER_ANY_DATA_CHANGED_EVENT,
        TRANSACTION_REGISTER_USER_INFO_DELETED_EVENT,
        TRANSACTION_UNREGISTER_SOME_DATA_CHANGED_EVENT,
        TRANSACTION_UNREGISTER_ANY_DATA_CHANGED_EVENT,
        TRANSACTION_UNREGISTER_USER_INFO_DELETED_EVENT,
        TRANSACTION_READ_DATA_OBJECT,
        TRANSACTION_READ_BOOLEAN,
        TRANSACTION_READ_INT64,
        TRANSACTION_READ_DOUBLE,
        TRANSACTION_READ_STRING,
        TRANSACTION_READ_BOOLEAN_VECTOR,
        TRANSACTION_READ_INT64_VECTOR,
        TRANSACTION_READ_DOUBLE_VECTOR,
        TRANSACTION_READ_STRING_VECTOR,
        TRANSACTION_WRITE_DATA_OBJECT,
        TRANSACTION_WRITE_BOOLEAN,
        TRANSACTION_WRITE_INT64,
        TRANSACTION_WRITE_DOUBLE,
        TRANSACTION_WRITE_STRING,
        TRANSACTION_WRITE_BOOLEAN_VECTOR,
        TRANSACTION_WRITE_INT64_VECTOR,
        TRANSACTION_WRITE_DOUBLE_VECTOR,
        TRANSACTION_WRITE_STRING_VECTOR,
        TRANSACTION_ADD_DATA_OBJECT,
        TRANSACTION_ADD_BOOLEAN,
        TRANSACTION_ADD_INT64,
        TRANSACTION_ADD_DOUBLE,
        TRANSACTION_ADD_STRING,
        TRANSACTION_ADD_BOOLEAN_VECTOR,
        TRANSACTION_ADD_INT64_VECTOR,
        TRANSACTION_ADD_DOUBLE_VECTOR,
        TRANSACTION_ADD_STRING_VECTOR,
        TRANSACTION_REMOVE_DATA_ITEM,
        TRANSACTION_ERASE_USER_INFO,
        TRANSACTION_GETJSONDATA,
    };

    DECLARE_META_INTERFACE(ConfigurationManagerService)

#endif

    /**
     * When the API is called, it returns value of desired item. \n
     * @ingroup CONFIGMGR_API

     * @startuml
     * hide footbox
     * participant App #99FF99
     * App -> ConfigManager : getData(ProvisioningData,"itemName")
     * ConfigManager -> DBManager : getData(ProvisioningData,"itemName")

     * activate DBManager
     * create database search
     * DBManager -> search
     * DBManager <- search
     * ConfigManager <- DBManager : (result, value)
     * Deactivate DBManager

     * App <- ConfigManager : ConfigResponse
     @enduml

     * @param[in] sourceType Data source (Preloaded data, OTA data, Micom data etc)
     * @param[in] name requesting data name in ConfigManager. Data type is std::string.
     * @retval ProvisoningResponse It contains getData result and value of requested item.
     * @note Here is the example of getData().
     * @verbatim

        for the parameter information, refer the "IConfigurationManagerServiceType.h"

        <volte enabled="false" allowed="false">
          <use_volte_apn_from_SIM enabled="true"/>
          <rsrq_trigger>0</rsrq_trigger>
        </volte>

        std::string name = "volte";
        ConfigResponse r = mConfigManager->getData(sourceType, name);

        if(r.result == NoError) {
            LOGV("%s",r.read().c_str());
            LOGV("%s",r.read("use_volte_apn_from_SIM").c_str());
            LOGV("%s",r.read("rsrq_trigger").c_str());
        }

        <modem>
          <nadAlwaysOnModeEnabled enabled="true"/>
          <networkRegistrationTimerNAD>0</networkRegistrationTimerNAD>
          <wakeupMask>0200000012</wakeupMask>
          <custom_apn enabled="true" allowed="true">
            <use_custom_apn_from_SIM enabled="true"/>
            <ip_version_custom_apn>dual_stack</ip_version_custom_apn>
          </custom_apn>
        </modem>

        DataFrom sourceType = ProvisioningData;
        std::string name = "modem";
        std::string subItem1 = "custom_apn";
        std::string subItem2 = "ip_version_custom_apn";

        ConfigResponse r = mConfigManager->getData(sourceType, name);

        if(r.result == NoError) {
            LOGV("%s",r.read("nadAlwaysOnModeEnabled"));
            LOGV("%s",r.read("wakeupMask").c_str());
            LOGV("%s",r.read(move(subItem1)).c_str());
            LOGV("%s",r.read(move(subItem2)).c_str());
        }

        <ecall>
            <eCallPsapAutoConfig enabled="true">
                <primaryVoiceNum>+4989357458684</primaryVoiceNum>
                <secondaryVoiceNum>+4989357458684</secondaryVoiceNum>
            </eCallPsapAutoConfig>
            <eCallPsapManConfig enabled="false">
                <primaryVoiceNum>+4989357458685</primaryVoiceNum>
                <secondaryVoiceNum>+4989357458684</secondaryVoiceNum>
            </eCallPsapManConfig>
        </ecall>

        DataFrom sourceType = ProvisioningData;
        std::string name = "ecall";

        ConfigResponse r = mConfigManager->getData(sourceType, name);

        if(r.result == NoError) {
            LOGV("%s",r.read("eCallPsapAutoConfig").c_str());
            LOGV("%s",r.read("eCallPsapAutoConfig","privaryVoiceNum").c_str());
            LOGV("%s",r.read("eCallPsapManConfig").c_str());
            LOGV("%s",r.read("eCallPsapManConfig","privaryVoiceNum").c_str());
        }

        DataFrom sourceType = DataFrom::General;
        std::string name = "SIM_ENABLED";
        ConfigResponse r = mConfigManager->getData(sourceType, name);

        if(r.result == NoError) {
            LOGV("%s",r.read().c_str());
        }

       @endverbatim
     */
    virtual ConfigResponse getData(const DataFrom sourceType, const std::string& name)=0;

    virtual ConfigResult getConfigData(const DataFrom sourceType, const std::string& name, std::string& value)=0;

    /**
     * When the API is called, it returns value of desired item. \n
     * @ingroup CONFIGMGR_API
     * @startuml
     * hide footbox
     * participant App #99FF99
     * App -> ConfigManager : setData(General, dataContainer)
     * ConfigManager -> DBManager : setData(General,dataContainer)

     * activate DBManager
     * create database storage
     * DBManager -> storage
     * DBManager <- storage
     * ConfigManager <- DBManager : numOfItem
     * Deactivate DBManager

     * App <- ConfigManager : numOfItem
     @enduml

     * @param[in] sourceType Data source (Micom data)
     * @param[in] data save data to ConfigManager. Data type is std::vector<std::pair<std::string, std::string>>&
     * @retval int32_t It contains number of data to receive from Apps.
     * @note Here is the example of setData().
     * @verbatim

        for the parameter information, refer the "IConfigurationManagerServiceType.h"

        DataFrom sourceType = General;
        std::vector<std::pair<std::string, std::string>> v;
        auto p1 = std::make_pair("item1","value2");
        auto p2 = std::make_pair("item2","value2");
        v.push_back(p1);
        v.push_back(p2);

        int32_t r = mConfigManager->setData(sourceType, v);

        if(r == v.size()) {
          LOGV("setData OK");
        }

       @endverbatim
     */
    virtual int32_t setData(const DataFrom sourceType, const std::vector<std::pair<std::string, std::string>>& storeData)=0;

    virtual int32_t setConfigData(const DataFrom sourceType, const std::string name, const std::string value)=0;

    virtual bool isProvisioned(void)=0;

    /**
     * When the function is called, you can receive the change of status for the specific item name in the configuration manager.
     * @ingroup CONFIGMGR_API
     * @param[in] sourceType Data source (Preloaded data, OTA data, Micom data etc)
     * @param[in] name  item name to get when item value changed
     * @param[in] receiver      the receiver instance pointer to be registered. The receiver is inherited IConfigurationManagerReceiver
     * @retval   (0) No error
     * @retval   (-1) Unknown error
     * @note Here is the example of registerReceiver Callback.
     * @verbatim

     android::sp<IConfigurationManagerService> mConfigManager;
     android::sp<IConfigurationManagerReceiver> mReceive;

     mConfigManager = android::interface_cast<IConfigurationManagerService>(android::defaultServiceManager()->getService(android::String16(CONFIGURATION_SRV_NAME)));
     if(mConfigManager != nullptr) {
         mReceiver  = new ConfigReceiver(*this);
         if(mReceiver != nullptr) {
             DataFrom sourceType = DataFrom::General;
             error_t ret = mConfigManager->registerReceiver(sourceType, "", mReceiver);
             LOGV("XXXXManagerService::registerReceiver General Result = %d", ret);

             sourceType = DataFrom::DefaultProvData;
             ret = mConfigManager->registerReceiver(sourceType, "", mReceiver);
             LOGV("XXXXManagerService::registerReceiver DefaultProvData Result = %d", ret);
         }
     }
     @endverbatim
     */
    virtual error_t registerReceiver(const DataFrom sourceType, const std::string& name, android::sp<IConfigurationManagerReceiver>& receiver)=0;

    /**
     * When the function is called, you can unreceive the change of status for the specific data parameter in the configuration manager

     * @ingroup CONFIGMGR_API
     * @param[in] sourceType Data source (Preloaded data, OTA data, Micom data etc)
     * @param[in] name item name to ignore when item value changed
     * @param[in] receiver      the receiver instance pointer to be registered. The receiver is inherited IConfigurationManagerReceiver
     * @retval   (0) No error
     * @retval   (-1) Unknown error
     * @note Here is the example of unregisterReceiver Callback.
     * @verbatim

     if(mConfigManager != nullptr) {
         if(mReceiver != nullptr) {
             DataFrom sourceType = DataFrom::General;
             error_t ret = mConfigManager->unregisterReceiver(sourceType, "", mReceiver);
             LOGV("XXXXManagerService::unregisterReceiver General Result = %d !!!", ret);

             sourceType = DataFrom::DefaultProvData;
             ret = mConfigManager->unregisterReceiver(sourceType, "", mReceiver);
             LOGV("XXXXManagerService::unregisterReceiver DefaultProvData Result = %d", ret);
         }
     }

     @endverbatim
     */
    virtual error_t unregisterReceiver(const DataFrom sourceType, const std::string& name, android::sp<IConfigurationManagerReceiver>& receiver)=0;



    /**
     * When the function is called, selected DB is activated and loads items.
     * @ingroup CONFIGMGR_API
     @startuml
     hide footbox
     participant Apps #99FF99
     Apps -> ConfigManager : 1.0 defaultDBSelect(General,dbNum)
     ConfigManager -> DBManager : 1.1 selectDB(General,dbNum)
     activate DBManager
     ConfigManager <- DBManager : 1.2 result
     deactivate DBManager
     Apps <- ConfigManager : 1.3 result
     ConfigManager <- DBManager : 1.4 change notification if needed
     Apps <- ConfigManager : 1.5 change notification
     @enduml
     * @param[in] sourceType Data source (Preloaded data, OTA data, Micom data etc)
     * @param[in] dbIndex dbIndex to activate
     * @retval   (ConfigResult::NoError) No error
     * @retval   (ConfigResult::ObjectError) Data object is not exist
     * @note Here is the example of defaultDBSelect
     * @verbatim

     Datafrom sourceType = DefaultProvData;
     int32_t dbIndex= 1;
     ConfigResult result = mConfigManager->defaultDBSelect(sourceType, dbIndex );

     @endverbatim
     */
    virtual ConfigResult defaultDBSelect(const DataFrom sourceType, const int32_t dbIndex)=0;

    /**
     * When the function is called, selected DB cache would be removed and reloads newly designated oem file.
     * @ingroup CONFIGMGR_API

     @startuml
     hide footbox
     participant Apps #99FF99
     participant ProvisioningApp #99FF99
     ProvisioningApp -> ConfigManager : dbReloadNeeded(sourceType,reason,location)
     ConfigManager -> DBManager : dbReloadNeeded(sourceType,reason,location)
     activate DBManager

     activate DBManager
     create database storage
     DBManager -> storage : reload new db file
     DBManager <- storage : reload complete
     ConfigManager <- DBManager : reload result
     Deactivate DBManager

     deactivate DBManager
     ProvisioningApp <- ConfigManager : reload result
     ConfigManager <- DBManager : change notification if needed
     Apps <- ConfigManager : change notification
     @enduml

     * @param[in] sourceType Data source (Preloaded data, OTA data, Micom data etc)
     * @param[in] reloadReason the reason of why db reload is needed
     * @param[in] location the file path of new database
     * @retval   (ConfigResult::NoError) No error
     * @retval   (ConfigResult::ObjectError) No database object
     * @note Here is the example of dbReloadNeeded.
     * @verbatim

     Datafrom sourceType = DataFrom::Provisioning;
     Reload reloadReason = Reload::Ota;
     std::string path = "/tmp/provioning/prov.xml";
     result = mConfigManager->dbReloadNeeded(sourceType, reloadReason, path);

     @endverbatim
     */
    virtual ConfigResult dbReloadNeeded(const DataFrom sourceType, const Reload reloadReason, const std::string& location)=0;

    /**
     * When the function is called, ConfigManager query for loaded database status. Query reason is up to OEM requirement.
     * @ingroup CONFIGMGR_API

     @startuml
     hide footbox
     participant Apps #99FF99
     Apps -> ConfigManager : dbStatusQuery(sourceType,reason,value)
     ConfigManager -> DBManager : dbStatusQuery(sourceType,reason,value)
     activate DBManager
     activate DBManager
     create database storage
     DBManager -> storage : check the current DB status
     DBManager <- storage : return DB status
     ConfigManager <- DBManager : status result
     Deactivate DBManager
     deactivate DBManager
     Apps <- ConfigManager : status result
     @enduml

     * @param[in] sourceType Data source (Preloaded data, OTA data, Micom data etc)
     * @param[in] queryReason the reason of why db information(status) is needed
     * @param[in] value additional information(general purpose) for dbStatusQuery
     * @retval    dbStatus
     * @note Here is the example of dbStatusQuery.
     * @verbatim

     Datafrom sourceType = DataFrom::Provisioning;
     Query queryReason = Query::Diag;
     std::string value = "";
     dbStatus result = mConfigManager->dbStatusQuery(sourceType, queryReason);

     @endverbatim
     */

    virtual dbStatus dbStatusQuery(const DataFrom sourceType, const Query queryReason, const std::string value) = 0;

    /**
     * @brief Register to receive notification when value of an arbitrary data item changed. Callers
     * should implement corresponding callback functions so to handle accordingly.
     * @param receiver Concrete implementation of IConfigurationManagerReceiver interface.
     * @return 0 on success, others mean failure. Please look at \b error_t for more details.
     */
    virtual error_t
    registerDataChangedEvent(const android::sp<IConfigurationManagerReceiver> &receiver) = 0;

    /**
     * @brief Register to receive notification when data item's value changed. Callers should
     * implement corresponding callback functions so to handle accordingly.
     * @param receiver See description above.
     * @param patterns List of data item patterns caller want to subscribe. See description above
     * about \e pattern for more details.
     * @return 0 on sucess, others mean failure. Please look at \b error_t for more details.
     */
    virtual error_t
    registerDataChangedEvent(const android::sp<IConfigurationManagerReceiver> &receiver,
                             const std::vector<std::string> &patterns) = 0;

    /**
     * @brief Stop to receive notification for all subscribed data items (if any).
     * @param receiver See description above.
     * @return 0 on success, others mean failure. Please look at \b error_t for more details.
     */
    virtual error_t
    unregisterDataChangedEvent(const android::sp<IConfigurationManagerReceiver> &receiver) = 0;

    /**
     * @brief Go hand in hand with registerDataChangedEvent(), stop to receive notification when
     * data item's value changed.
     * @param receiver See description above.
     * @param patterns List of data item patterns caller want to unsubscribe. See description above
     * about \e pattern for more details. It does not need to match (to be exactly as same as) one
     * passed into registerDataChangedEvent(). If it does not match, then caller will get notified
     * only for remaining ones (if any, compared to former list). Otherwise, no more news to come
     * to caller side.
     * @return 0 on success, others mean failure. Please look at \b error_t for more details.
     */
    virtual error_t
    unregisterDataChangedEvent(const android::sp<IConfigurationManagerReceiver> &receiver,
                               const std::vector<std::string> &patterns) = 0;

    /**
     * @brief registerUserInfoDeletedEvent
     * @param receiver
     * @return 0 on success, others mean failure. Please look at error_t for more details.
     * @note Specific for GEN12 project.
     */
    virtual error_t
    registerUserInfoDeletedEvent(const android::sp<IConfigurationManagerReceiver> &receiver) = 0;

    /**
     * @brief unregisterUserInfoDeletedEvent
     * @param receiver
     * @return 0 on success, others mean failure. Please look at error_t for more details.
     * @note Specific for GEN12 project.
     */
    virtual error_t
    unregisterUserInfoDeletedEvent(const android::sp<IConfigurationManagerReceiver> &receiver) = 0;

    /**
     * \defgroup ReadFunctions Read JSON configuration data by name pattern
     * @brief Read configuration data by its name pattern. It support to query quite a few commonly
     * used data types like \b bool, \b int64_t, \b double, \b std::string, and \b std::vector of
     * those. I'm just going to wrap very well-regraded library, so there are not so many thing I
     * can do. Even the supported features of that library become limited or unusable due to
     * incompetent myself, or come from platform dependence (\b Binder), really.
     * @param pattern The name pattern of configuration data. \e Pattern here is intent to be the
     * exact name of data item, or that that conforms to some kind of well-known/well-received
     * specifications. For example, we use JSON in GEN12 project, so pattern could be JSON pointer
     * (another common data interchange format is XML which has XPath). Of course the library should
     * support those specs in the first place for this to be available.
     * @param data/value/values Output data. In addition to those of types mentioned above, I
     * decided to make it return orginal library object type as well, just in case callers want to
     * manipulate underlying format directly, and library already supported that pretty well.
     * @return 0 on success, others mean failure. Please see \b android::status_t for more details.
     * @{
     */
    virtual int32_t read(const std::string &pattern, config::data_t &data) = 0;
    virtual int32_t read(const std::string &pattern, bool &value) = 0;
    virtual int32_t read(const std::string &pattern, int64_t &value) = 0;
    virtual int32_t read(const std::string &pattern, double &value) = 0;
    virtual int32_t read(const std::string &pattern, std::string &value) = 0;
    virtual int32_t read(const std::string &pattern, std::vector<bool> &values) = 0;
    virtual int32_t read(const std::string &pattern, std::vector<int64_t> &values) = 0;
    virtual int32_t read(const std::string &pattern, std::vector<double> &values) = 0;
    virtual int32_t read(const std::string &pattern, std::vector<std::string> &values) = 0;
    /** @} end of #ReadFunctions group */

    /**
     * \defgroup WriteFunctions Write JSON configuration data by name pattern
     * @brief Go hand in hand with @ref ReadFunctions, it writes (updates) value for configuration
     * data. Data item is expected to be existed. Otherwise, please use @ref AddFunctions instead.
     * @param pattern Already described in @ref ReadFunctions.
     * @param data/value/values Input data. It is \e new value for data to be updated. Types
     * supported already described in @ref ReadFunctions.
     * @return 0 on success, others mean failure. Please see \b android::status_t for more details.
     * @{
     */
    virtual int32_t write(const std::string &pattern, const config::data_t &data) = 0;
    virtual int32_t write(const std::string &pattern, bool value) = 0;
    virtual int32_t write(const std::string &pattern, int64_t value) = 0;
    virtual int32_t write(const std::string &pattern, double value) = 0;
    virtual int32_t write(const std::string &pattern, const std::string &value) = 0;
    virtual int32_t write(const std::string &pattern, const std::vector<bool> &values) = 0;
    virtual int32_t write(const std::string &pattern, const std::vector<int64_t> &values) = 0;
    virtual int32_t write(const std::string &pattern, const std::vector<double> &values) = 0;
    virtual int32_t write(const std::string &pattern, const std::vector<std::string> &values) = 0;
    /** @} end of #WriteFunctions group */


    /**
     * \defgroup AddFunctions Add configuration data
     * @brief Add new configuration data specified by its name \e pattern.
     * @details In case an item with same pattern has already existed, then, depending on the type
     * of underlying data, either it will completely replace data with new value (similar to family
     * of #write functions), or it can append new item to an existing one. For e.g., if data is an
     * array, then new item will be put at the end of that array, effectively increases its size
     * by 1. On the other hand, if data is type of object, then its old value as a whole will be
     * replaced by new one. Other types have same behavior as object type.
     * @param pattern Name pattern as described in IConfigurationManagerService.h
     * @return 0 on success, others mean failure. Please see \b android::status_t for more details.
     * @note Default implementation also been provided to avoid build issues within other projects.
     * @{
     */

    /**
     * @brief Add data as underlying library object. See IConfigurationManagerServiceType.h for
     * more details.
     */
    virtual int32_t add(const std::string &pattern, const config::data_t &data)
    {
        (void) pattern; (void) data; return android::PERMISSION_DENIED;
    }

    /**
     * @brief Add boolean value
     */
    virtual int32_t add(const std::string &pattern, bool value)
    {
        (void) pattern; (void) value; return android::PERMISSION_DENIED;
    }

    /**
     * @brief Add 64-bit integer value
     */
    virtual int32_t add(const std::string &pattern, int64_t value)
    {
        (void) pattern; (void) value; return android::PERMISSION_DENIED;
    }

    /**
     * @brief Add double value
     */
    virtual int32_t add(const std::string &pattern, double value)
    {
        (void) pattern; (void) value; return android::PERMISSION_DENIED;
    }

    /**
     * @brief Add string value
     */
    virtual int32_t add(const std::string &pattern, const std::string &value)
    {
        (void) pattern; (void) value; return android::PERMISSION_DENIED;
    }

    /**
     * @brief Add vector of boolean values
     */
    virtual int32_t add(const std::string &pattern, const std::vector<bool> &values)
    {
        (void) pattern; (void) values; return android::PERMISSION_DENIED;
    }

    /**
     * @brief Add vector of 64-bit integer values
     */
    virtual int32_t add(const std::string &pattern, const std::vector<int64_t> &values)
    {
        (void) pattern; (void) values; return android::PERMISSION_DENIED;
    }

    /**
     * @brief Add vector of double values
     */
    virtual int32_t add(const std::string &pattern, const std::vector<double> &values)
    {
        (void) pattern; (void) values; return android::PERMISSION_DENIED;
    }

    /**
     * @brief Add vector of string values
     */
    virtual int32_t add(const std::string &pattern, const std::vector<std::string> &values)
    {
        (void) pattern; (void) values; return android::PERMISSION_DENIED;
    }

    /** @} end of #AddFunctions group */


    /**
     * \defgroup RemoveFunctions Remove JSON configuration data by name pattern
     * @brief Remove a config data item or an element of it (in case data item is a JSON array) by
     * by its name pattern (and an optional index to denote the position of element in array).
     * @param pattern Already described in @ref ReadFunctions.
     * @param idx     Optional, index of to be deleted array element. In this case, array is still
     * be specified by input param \e pattern as described above.
     * @return 0 on success, others mean failure. Please see \b android::status_t for more details.
     * @note Default implementation also been provided to avoid build issues within other projects.
     * @{
     */
    virtual int32_t remove(const std::string &pattern, int32_t idx = -1)
    {
        (void) pattern; (void) idx; return android::PERMISSION_DENIED;
    }
    /** @} end of #RemoveFunctions group */

    /**
     * @brief The sourceType is ProvisionedData and is used when reading the json file from the
     * provided path, not the default file path downloaded from the server.
     * @param[in] sourceType Data source (Preloaded data)
     * @param[in] Given a json file of a specific path, json data of that path is provided.
     * @retval ConfigResponse It contains getJsonData result and value of requested item.
     * An mJsonData item is provided. You can parse the json data item and use it.
     * nlohmann::json mJsonData;
     * @note Here is the example of getJsonData().
     * <pre>
     *      DataFrom sourceType = DataFrom::ProvisionedData;
     *      std::string name = "/path/provided_path.json";
     *      ConfigResponse r = mConfigManager->getJsonData(sourceType, name);
     * </pre>
     */
    virtual ConfigResponse getJsonData(const DataFrom sourceType, const std::string& name)=0;

    /**
     * \defgroup EraseFunctions Erase data at file and/or directory level
     * @brief Erase any kind of data at file and/or directory level.
     * @return 0 on success, others mean failure. Please see \b android::status_t for more details.
     * @{
     */
    virtual int32_t erase() = 0;
    /** @} end of #EraseFunctions */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    virtual dbStatus debugCmd(std::string& name, std::string& value)=0;
#endif
};

class BnConfigurationManagerService: public android::BnInterface<IConfigurationManagerService>
{
public:
    virtual android::status_t onTransact(uint32_t code,
                                         const android::Parcel &data,
                                         android::Parcel *reply,
                                         uint32_t flags);

};
#endif /* IConfiguration_MANAGER_SERVICE_H */
