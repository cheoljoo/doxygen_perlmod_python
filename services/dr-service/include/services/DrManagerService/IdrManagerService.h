// FileName - IdrManagerService.h
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
 * @file        IDrManagerService.h
 * @brief       Declaration of IDrManagerService
 * @author      youngju.cho
 * @version     A.BB.CCC (A: major change, B: refactoring or structure change, C: minor change (ex) 1.12.133)
 */


/** @defgroup DRMGR DrManager
 * This is the DrManager group and It describes Interface for DrManagerService. \n
 * If Apps or other services needs gnssdr infomation, It could be obatined by these API. \n
 * To use these API, APP or Service, You Should get <IDrService> \n\n
 * @version     0.1.00
 * @note Here is the example
 * @verbatim
     #include "services/DrManagerService/IDrManagerServiceType.h"

     android::sp<IDrManagerService> locm = interface_cast<IDrManagerService>(defaultServiceManager()->getService(String16("service_layer.drManagerService")));
    @endverbatim
 */


/** @defgroup DRMGR_CB DrManager Callback
 *  @ingroup DRMGR
 *  These are DrManager Callback function.  Since these functions are pure virtual funtion, application shall implement their own receiver function.  \n
 *  @b example: \n
 *  class AppDrManager : public BnDrReceiver  \n
 *     { \n
 *        virtual void getGPSLocation(const sp<drmgr::LocationData>&     location){} \n
 *        virtual void getGPSnmea(int64_t timestamp, const char* nmea, int length){} \n
 *      \n
*/


#ifndef _IDRNOSTIC_MANAGER_SERVICE_H_
#define _IDRNOSTIC_MANAGER_SERVICE_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include "Typedef.h"

#include "drCommand.h"
#include "IdrManagerReceiver.h"
#include "IdrManagerServiceType.h"

/**
 * @author
 * youngju.cho
 * @version
 * 0.01.000 (A: major change, B: refactoring or structure change, C: minor change (ex) 1.12.133)
 * @note
 * DrManagerService's name is @b "service_layer.DrManagerService"
 */
class IDrManagerService : public android::IInterface
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    DECLARE_META_INTERFACE(DrManagerService);
#endif
#ifndef DOXYGEN_SHOULD_SKIP_THIS

    /**
    * To want to know occurring event and receive data about instance of IDrReceiver.
    *
    * @ingroup DRMGR DRMGR_CB
    * @param[in] receiver id
    * @param[in] receiver Instance of IDrReceiver
    * If there is incoming data, receive it through IDrReceiver.
    * @return    error_t
    * @retval   (0) No error
    * @retval   (-1) Unknown error
    * @retval   (-2) Invalid parameter
    * @retval   (-3) Can not send response
    * @retval   (-4) Occur time-out
    * @retval   (-5) Request is rejected due to some reason
    * @retval   (-6) Request is pending due to some reason
    * @retval   (-7) Not enough memory
    * @retval   (-8) Data corrupted
    * @retval   (-9) Buffer empty
    * @retval   (-10) Input empty
    * @retval   (-11) Frame Not Ready
    * @note
    * It can bind like below method\n
    * android::sp<IDrReceiver> m_DrReceiver = new instance of IDrReceiver \n
    * android::sp<IDrService> m_DrMgr = interface_cast<IDrManagerService>(defaultServiceManager()->getService(String16("service_layer.drManagerService")));\n
    * m_DrMgr->registerReceiver(id,m_DrReceiver);  \n
    */
    virtual error_t registerReceiver(uint32_t id, const android::sp<IDrManagerReceiver>& receiver) = 0;

    /**
     * To break the connection between DrManagerService and receiver
     *
     * @ingroup DRMGR DRMGR_CB
     * @param[in] receiver Instance of IDrReceiver
     * @return    error_t
     * @retval   (0) No error
     * @retval   (-1) Unknown error
     * @retval   (-2) Invalid parameter
     * @retval   (-3) Can not send response
     * @retval   (-4) Occur time-out
     * @retval   (-5) Request is rejected due to some reason
     * @retval   (-6) Request is pending due to some reason
     * @retval   (-7) Not enough memory
     * @retval   (-8) Data corrupted
     * @retval   (-9) Buffer empty
     * @retval   (-10) Input empty
     * @retval   (-11) Frame Not Ready
     * @note When application terminates service, application shall call unregisterReceiver function
     */
    virtual error_t unregisterReceiver(const android::sp<IDrManagerReceiver>& receiver) = 0;


    /**
     * Register for gnssdr start
     *
     * @ingroup DRMGR DRMGR_CB
     * for more detail on how to use this method.
     *
     * @param[in] receiver Instance of IDrReceiver
     * @return    boolean
     */
    virtual bool    gnssInit(android::sp<IDrManagerReceiver> locMgr) = 0;

    /**
     * To start for getting OEMDRE gnss data. \n
     *
     * @ingroup DRMGR DRMGR_IN
     * @return     error_t \n
     * @retval   (0) No error
     * @retval   (-1) Unknown error
     * @retval   (-2) Invalid parameter
     * @retval   (-3) Can not send response
     * @retval   (-4) Occur time-out
     * @retval   (-5) Request is rejected due to some reason
     * @retval   (-6) Request is pending due to some reason
     * @retval   (-7) Not enough memory
     * @retval   (-8) Data corrupted
     * @retval   (-9) Buffer empty
     * @retval   (-10) Input empty
     * @retval   (-11) Frame Not Ready
     */
    virtual bool gnssStart() = 0;

    /**
     * To stop for getting OEMDRE gnss data. \n
     *
     * @ingroup DRMGR DRMGR_IN
     * @return     error_t \n
     * @retval   (0) No error
     * @retval   (-1) Unknown error
     * @retval   (-2) Invalid parameter
     * @retval   (-3) Can not send response
     * @retval   (-4) Occur time-out
     * @retval   (-5) Request is rejected due to some reason
     * @retval   (-6) Request is pending due to some reason
     * @retval   (-7) Not enough memory
     * @retval   (-8) Data corrupted
     * @retval   (-9) Buffer empty
     * @retval   (-10) Input empty
     * @retval   (-11) Frame Not Ready
     */

    virtual bool gnssStop() = 0;

     /**
     * To init for gnss XTRA. \n
     *
     * @ingroup DRMGR DRMGR_IN
     * @return     bool \n
     */
    virtual bool gnssXTRAInit() = 0;

     /**
     * To set gnss position mode. \n
     *
     * @ingroup DRMGR DRMGR_IN
     * @param[in] uint32_t mode
     * @param[in] uint32_t recurrence
     * @param[in] uint32_t min_interval
     * @param[in] uint32_t preferred_accuracy
     * @param[in] uint32_t preferred_time
     * @return     error_t \n
     * @retval   (0) No error
     * @retval   (-1) Unknown error
     * @retval   (-2) Invalid parameter
     * @retval   (-3) Can not send response
     * @retval   (-4) Occur time-out
     * @retval   (-5) Request is rejected due to some reason
     * @retval   (-6) Request is pending due to some reason
     * @retval   (-7) Not enough memory
     * @retval   (-8) Data corrupted
     * @retval   (-9) Buffer empty
     * @retval   (-10) Input empty
     * @retval   (-11) Frame Not Ready
     */
    virtual bool gnssSetPositionMode(uint32_t mode,uint32_t recurrence,uint32_t min_interval,
                                            uint32_t preferred_accuracy, uint32_t preferred_time) = 0;

    /**
    * To delete gnss aiding data. \n
    *
    * @ingroup DRMGR DRMGR_IN
    * @param[in] uint32_t mask
    * @return     error_t \n
    * @retval   (0) No error
    * @retval   (-1) Unknown error
    * @retval   (-2) Invalid parameter
    * @retval   (-3) Can not send response
    * @retval   (-4) Occur time-out
    * @retval   (-5) Request is rejected due to some reason
    * @retval   (-6) Request is pending due to some reason
    * @retval   (-7) Not enough memory
    * @retval   (-8) Data corrupted
    * @retval   (-9) Buffer empty
    * @retval   (-10) Input empty
    * @retval   (-11) Frame Not Ready
    */
    virtual bool gnssDeleteAidingData(int32_t mask) = 0;

    /**
    * To inject gnss time. \n
    *
    * @ingroup DRMGR DRMGR_IN
    * @param[in] int64_t time
    * @param[in] int64_t timeReference
    * @param[in] uint32_t uncertainty
    * @return     error_t \n
    * @retval   (0) No error
    * @retval   (-1) Unknown error
    * @retval   (-2) Invalid parameter
    * @retval   (-3) Can not send response
    * @retval   (-4) Occur time-out
    * @retval   (-5) Request is rejected due to some reason
    * @retval   (-6) Request is pending due to some reason
    * @retval   (-7) Not enough memory
    * @retval   (-8) Data corrupted
    * @retval   (-9) Buffer empty
    * @retval   (-10) Input empty
    * @retval   (-11) Frame Not Ready
    */
    virtual bool gnssInjectTime(int64_t time, int64_t timeReference, int32_t uncertainty) = 0;

    /**
    * To inject gnss extra data. \n
    *
    * @ingroup DRMGR DRMGR_IN
    * @param[in] const char* data
    * @param[in] int length
    * @return     error_t \n
    * @retval   (0) No error
    * @retval   (-1) Unknown error
    * @retval   (-2) Invalid parameter
    * @retval   (-3) Can not send response
    * @retval   (-4) Occur time-out
    * @retval   (-5) Request is rejected due to some reason
    * @retval   (-6) Request is pending due to some reason
    * @retval   (-7) Not enough memory
    * @retval   (-8) Data corrupted
    * @retval   (-9) Buffer empty
    * @retval   (-10) Input empty
    * @retval   (-11) Frame Not Ready
    */
    virtual bool gnssInjectXtraData(const char* data, int length) = 0;

    /**
     * To get gps start mode
     *
     * @ingroup DRMGR DRMGR_OUT
     * @return     int mode \n
     */
    virtual int     gnssGetGpsStartMode() = 0;

    /**
    * To set gnss used system. \n
    *
    * @ingroup DRMGR DRMGR_IN
    * @param[in] uint32_t param
    * @return     error_t \n
    * @retval   (0) No error
    * @retval   (-1) Unknown error
    * @retval   (-2) Invalid parameter
    * @retval   (-3) Can not send response
    * @retval   (-4) Occur time-out
    * @retval   (-5) Request is rejected due to some reason
    * @retval   (-6) Request is pending due to some reason
    * @retval   (-7) Not enough memory
    * @retval   (-8) Data corrupted
    * @retval   (-9) Buffer empty
    * @retval   (-10) Input empty
    * @retval   (-11) Frame Not Ready
    */
    virtual bool gnssSetGnssUsedSystem(int32_t param) = 0;

    /**
     * To get gnss used system
     *
     * @ingroup DRMGR DRMGR_OUT
     * @param[in] int32_t& status
     * @return     error_t \n
     * @retval   (0) No error
     * @retval   (-1) Unknown error
     * @retval   (-2) Invalid parameter
     * @retval   (-3) Can not send response
     * @retval   (-4) Occur time-out
     * @retval   (-5) Request is rejected due to some reason
     * @retval   (-6) Request is pending due to some reason
     * @retval   (-7) Not enough memory
     * @retval   (-8) Data corrupted
     * @retval   (-9) Buffer empty
     * @retval   (-10) Input empty
     * @retval   (-11) Frame Not Ready
     */
    virtual bool gnssGetGnssUsedSystem(int32_t &status) = 0;

    /**
    * To set gnss cn0. \n
    *
    * @ingroup DRMGR DRMGR_IN
    * @param[in] uint32_t param
    * @return     error_t \n
    * @retval   (0) No error
    * @retval   (-1) Unknown error
    * @retval   (-2) Invalid parameter
    * @retval   (-3) Can not send response
    * @retval   (-4) Occur time-out
    * @retval   (-5) Request is rejected due to some reason
    * @retval   (-6) Request is pending due to some reason
    * @retval   (-7) Not enough memory
    * @retval   (-8) Data corrupted
    * @retval   (-9) Buffer empty
    * @retval   (-10) Input empty
    * @retval   (-11) Frame Not Ready
    */
    virtual bool gnssSetGnssCn0(int32_t param) = 0;

    /**
     * To get gnss cn0
     *
     * @ingroup DRMGR DRMGR_OUT
     * @param[in] int32_t& status
     * @return     error_t \n
     * @retval   (0) No error
     * @retval   (-1) Unknown error
     * @retval   (-2) Invalid parameter
     * @retval   (-3) Can not send response
     * @retval   (-4) Occur time-out
     * @retval   (-5) Request is rejected due to some reason
     * @retval   (-6) Request is pending due to some reason
     * @retval   (-7) Not enough memory
     * @retval   (-8) Data corrupted
     * @retval   (-9) Buffer empty
     * @retval   (-10) Input empty
     * @retval   (-11) Frame Not Ready
     */
    virtual bool gnssGetGnssCn0(int32_t &status) = 0;

    virtual bool gnssCommand(int32_t cmdType, int32_t value, int32_t& resp_value) = 0;

    virtual bool setHippoLogging(bool enable) = 0;

    /**
     * API to test IDrManagerReceiver
     *
     * @param[in] id Id of the receiver
     * @return    void
     */
    virtual void cmdTest_IdrManagerReceiver() = 0;

#endif


};

class BnDrManagerService : public android::BnInterface<IDrManagerService>
{

public:
    virtual android::status_t onTransact(uint32_t code, const android::Parcel& data, android::Parcel* reply, uint32_t flags);
};
#endif /**IDR_MANAGER_SERVICE_H*/
