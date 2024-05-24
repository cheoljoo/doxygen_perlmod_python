/*
 *   This software is copyright protected and proprietary to
 *   LG electronics. LGE grants to you only those rights as
 *   set out in the license conditions. All other rights remain
 *   with LG electronics.
 * \attention Copyright (c) 2015 by LG electronics co, Ltd. All rights reserved.
 */

#ifndef _SERVICELAYER_DR_COMMAND_H_
#define _SERVICELAYER_DR_COMMAND_H_

#include "Typedef.h"

#include "utils/Buffer.h"
#include <TCUProtocol.h>

#include "utils/external/mindroid/lang/String.h"
#include "Error.h"
#include <binder/Parcel.h>
#include <utils/RefBase.h>

// CGA_VARIANT:__GLOBAL_SCOPE__:__YOUR_CODE__:variant START
    /*
     * Write your own additional code
     * add your #include
     * add your global declare the function and variables
     * add your function
     */
// CGA_VARIANT:__GLOBAL_SCOPE__:__YOUR_CODE__:variant END

#define DR_SLDD_TEST

#define DR_BOOTING_WAIT_TIME                  5
#define DR_TIME_OUT                           0


#define DRDATA_BUFSIZE    (4 * 1024)

#define DID_READ_REQUEST    0x11
#define DID_WRITE_REQUEST   0x01

#define DID_READ_RESPONSE   0x10
#define DID_WRITE_RESPONSE  0x00

#define DATA_ID_SIZE        (2)

#define DATA_EMPTY_SIZE     (1)

#define PAYLOAD_SIZE        400U
#define SIGNAL_INTERNAL_DR_BASE 0x0001


#define DRDATA_HEAD  (offsetof(drDataFormat, data) )

class drData: public android::RefBase {
public:
    drData() {
        type = static_cast< uint8_t >(0);

    }
    drData(const drData& other);
    virtual ~drData();
    drData& operator=(const drData& other);
    void setTo(const drData& other);
    error_t writeToParcel(android::Parcel* parcel);
    error_t readFromParcel(const android::Parcel& parcel);
    void toString();
    void toString(const char* from);
        uint8_t  getType();

    void setData(
            uint8_t mtype
    );

private:
        uint8_t  type;
};


#endif /**_SERVICELAYER_DR_COMMAND_H_*/
