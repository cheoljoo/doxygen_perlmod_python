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
 * @file        IConfigurationManagerReceiver.h
 * @brief       Declaration of IConfigurationManagerReceiver
 * @author
 *    copyright (c) 2015  Jungwook Hong <Jungwook.hong@lge.com>
 *    copyright (c) 2017  Jaeho Choi <elliott.choi@lge.com>
 *    copyright (c) 2021  Thang Bui Huy <thang1.bui@lge.com>
 * @version     1.0.01
*/


#ifndef ICONFIGUARITIONMANAGER_RECEIVER_H
#define ICONFIGUARITIONMANAGER_RECEIVER_H

#include "services/ConfigurationManagerService/IConfigurationManagerServiceType.h"

#include <string>

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

#include <utils/Buffer.h>


/**
 * Observer to receive incoming data.\n
 * When Apps or services registers @b ConfigurationManagerReceive into their module,
 * \n method will be called with changed item name. \n
 * @author
 *    copyright (c) 2015  Jungwook Hong <Jungwook.hong@lge.com> \n
 *    copyright (c) 2017  Jaeho Choi <elliott.choi@lge.com>
 * @note
 * ConfigurationManagerService's name is @b "service_layer.ConfigurationManagerService"
 * @if (CGA)
 *   @CGA_BNCLASS{BnConfigurationManagerReceiver}
 * @endif
 */
class IConfigurationManagerReceiver: public android::IInterface
{
public:

#ifndef DOXYGEN_SHOULD_SKIP_THIS

enum
{
    TRANSACT_DATA_CHANGED = android::IBinder::FIRST_CALL_TRANSACTION,
    TRANSACT_DATA_BUFFER_CHANGED,
    TRANSACT_CONFIG_DATA_CHANGED,
    TRANSACT_CONFIG_DATA_REMOVED,
    TRANSACT_USER_INFO_DELETED
};

    DECLARE_META_INTERFACE(ConfigurationManagerReceiver)

#endif

    /**
     * \defgroup CallbackFunctions Callback functions
     * @brief Notify receivers when some events occurred.
     * @{
     */

    /**
     * @brief Callback function, which will be called upon changing in value of a config data item.
     * It should be overwritten by anyone who inherited the receiver interface:
     * #BnConfigurationManagerReceiver.
     * @param name  Name \e pattern of data item.
     * @param value Updated value of data item.
     */
    virtual void onConfigDataChanged(std::string &name, std::string &value)
    {
        (void) name;
        (void) value;
    }

    /**
     * @brief Callback function, which will be called upon changing in value of a config data item.
     * It should be overwritten by anyone who inherited the receiver interface:
     * #BnConfigurationManagerReceiver.
     * @param pattern Name \e pattern of data item.
     * @param data    Updated value (currently, stored as JSON) of data item. See #config::data_t
     * for more details.
     */
    virtual void onDataChanged(const std::string &pattern, const config::data_t &data)
    {
        (void) pattern;
        (void) data;
    }

    /**
     * @brief Callback function, which will be called upon removal of an config data item in one
     * of 2 cases:
     * <pre>
     *  1) Remove an item as a whole
     *  2) Remove an element from an item (JSON array)
     *  </pre>
     * It should be overwritten by anyone who inherited the receiver interface:
     * #BnConfigurationManagerReceiver.
     * @param pattern Name \e pattern of now deleted item.
     * @param idx     Optional, index of element of JSON array which has been removed (case 2nd).
     */
    virtual void onDataRemoved(const std::string &pattern, int32_t idx = -1)
    {
        (void) pattern;
        (void) idx;
    }

    /**
     * @brief Callback function, which will be called upon deletion of some information (which is
     * project specific). It should be overwritten by anyone who inherited the receiver interface:
     * #BnConfigurationManagerReceiver.
     */
    virtual void onUserInfoDeleted()
    {
    }

    /** @} end of #CallbackFunctions group */
};


class BnConfigurationManagerReceiver: public android::BnInterface<IConfigurationManagerReceiver>
{
public:
    virtual android::status_t onTransact(uint32_t code,
                                         const android::Parcel &data,
                                         android::Parcel *reply,
                                         uint32_t flags);
};


#endif /* ICONFIGUARITIONMANAGER_RECEIVER_H */

