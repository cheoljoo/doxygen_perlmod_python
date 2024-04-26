
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
