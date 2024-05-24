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
 * @author  LGE_worker@lge.com
 * @date    2020.12.11
 * @version 3.0.00
 */

#ifndef _REGION_MGR_ENVIRONMENTVARIANT_H_
#define _REGION_MGR_ENVIRONMENTVARIANT_H_

#include "EnvironmentVariant.h"
#include <binder/Parcel.h>
#include <utils/RefBase.h>
#include <string>

#include "Typedef.h"
#include "utils/Buffer.h"
#include "Log.h"
#include "Error.h"

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
 */
class EnvironmentVariant : public android::RefBase {
 public:
    EnvironmentVariant();
    EnvironmentVariant(const EnvironmentVariant& other);
    virtual ~EnvironmentVariant();
    EnvironmentVariant& operator=(const EnvironmentVariant& other);
    void setTo(const EnvironmentVariant& other);
    error_t writeToParcel(android::Parcel* parcel);
    error_t readFromParcel(const android::Parcel& parcel);
    void toString();
    void toString(const char* from);
    std::string getEcu();
    std::string getHwVar();
    std::string getRevision();
    int8_t getModelYear();
    int8_t getHousingVariant();
    int8_t getMobileStandard();
    int8_t getCountryEquipment();
    int8_t getV2xType();
    int8_t getMobilePresent();
    int8_t getV2xPresent();
    int8_t getWlanPresent();
    int8_t getBtPresent();

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
};

#endif /** _REGION_MGR_ENVIRONMENTVARIANT_H_ */
