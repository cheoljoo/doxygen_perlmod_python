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
 * @file        IDrReceiver.h
 * @brief       Declaration of IDrReceiver
 * @details     TBD
 * @author      youngju.cho
 * @version     0.01.000 (A: major change, B: refactoring or structure change, C: minor change (ex) 1.12.133)
 */


#ifndef _IDR_MANAGER_RECEIVER_H_
#define  _IDR_MANAGER_RECEIVER_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

#include "utils/Buffer.h"
#include "Typedef.h"
#include "TCUProtocol.h"

#include <services/DrManagerService/gps.h>
#include <services/LocationManagerService/Location.h>


using namespace std;
using namespace android;

/**
 * Observer to receive incoming data.\n
 * If App or Service in the Service Layer registers @b DrReceiver into the session
 * which has data Service want to receive, \n these functions will be called if incoming happens. \n
 * @author
 * youngju.cho
 * @version
 * 0.01.000 (A: major change, B: refactoring or structure change, C: minor change (ex) 1.12.133)
 * @note
 * DrManagerService's name is @b "service_layer.DrManagerService"
 *
 */

class IDrManagerReceiver: public android::IInterface
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    DECLARE_META_INTERFACE(DrManagerReceiver);
#endif

    /**
     * Notify location from DrCB. \n
     * @ingroup DRMGR DRMGR_CB
     * @param[out] Location Info for registred receiver
     * @return     void
     */
    virtual void onLocation(const sp<tiger::Location> location) = 0;

    /**
     * Notify GPS status from DrCB. \n
     * @ingroup DRMGR DRMGR_CB
     * @param[out] GPS status
     * @return     void
     */
    virtual void onGPSStatus(uint16_t gpsStatus) = 0;

    /**
     * Notify NMEA Data from DrCB when GPS Module call NMEA Callback Function. \n
     * @ingroup DRMGR DRMGR_CB
     * @condition  To get availble NMEA data, NMEA port should be worked by calling setNMEASerialPortOnOff(1)
     * @param[out] nmea value which is string info for NMEA data
     * @return     void
     * @see        http://aprs.gids.nl/nmea/ or https://www.nmea.org/ for detailed nmea data info.
     */
    virtual void onGPSnmea(int64_t timestamp, const char* nmea, int length) = 0;


    /**
    * This Function is for locationManager
    * @ingroup DRMGR DRMGR_CB
    * @param[out] EXTRA request type
    * @return     void
    */
    virtual void onXTRARequest(int request_type)= 0;

    /**
    * This Function is for locationManager
    * @ingroup DRMGR DRMGR_CB
    * @param[out] capabilities
    * @return     void
    */
    virtual void setCapabilities(uint32_t capabilities) = 0;

    /**
     * Notify SV Status from DrCB when GPS Module call SVStatus Callback Function. \n
     * @ingroup DRMGR DRMGR_CB
     * @param[out] SV Status
     * @return     void
     */
    virtual void onSvStatus(GnssSvStatus& svStatus) = 0;


};

/**
 * @brief BnDrManagerReceiver defines binder native interface for transfer the operation(call) with function name and arguments.
 *
 */
class BnDrManagerReceiver: public android::BnInterface<IDrManagerReceiver>
{
public:
    virtual android::status_t onTransact(uint32_t code, const android::Parcel& data, android::Parcel* reply, uint32_t flags);
};
#endif /** _IDR_MANAGER_RECEIVER_H_*/
