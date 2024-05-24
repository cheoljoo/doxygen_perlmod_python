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
 * @date    2021.09.30
 * @version 1.0.00
 */

#ifndef _SERVICELAYER_REGIONNOSTIC_COMMAND_H_
#define _SERVICELAYER_REGIONNOSTIC_COMMAND_H_

#include "Typedef.h"

#include "utils/Buffer.h"

#include "utils/external/mindroid/lang/String.h"
#include "Error.h"
#include <binder/Parcel.h>
#include <utils/RefBase.h>

// @CGA_VARIANT_START{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}
/*
 * Write your own additional code
 * add your #include
 * add your global declare the function and variables
 * add your function
 */
/// @CGA_VARIANT___END{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}

#define REGION_SLDD_TEST

#define REGION_BOOTING_WAIT_TIME                  5
#define REGION_TIME_OUT                           0


#define REGIONDATA_BUFSIZE    (4 * 1024)

#define DID_READ_REQUEST    0x11
#define DID_WRITE_REQUEST   0x01

#define DID_READ_RESPONSE   0x10
#define DID_WRITE_RESPONSE  0x00

#define DATA_ID_SIZE        (2)

#define DATA_EMPTY_SIZE     (1)

#define PAYLOAD_SIZE        400U
#define SIGNAL_INTERNAL_REGION_BASE 0x0001

/**
* @MISRA{MISRA C++-2008 Rule 16-2-1,This is intended design}
*/
#define DID_WORK_FOR_DEFINE_0   0x0001
#define DID_WORK_FOR_DEFINE_1   0x0002
#define DID_WORK_FOR_DEFINE_2   0x0003
#define DID_WORK_FOR_DEFINE_3   0x0004
#define DID_WORK_FOR_DEFINE_4   0x0005
#define DID_WORK_FOR_DEFINE_5   0x0006
#define DID_WORK_FOR_DEFINE_6   0x0007
#define DID_WORK_FOR_DEFINE_7   0x0008
#define DID_WORK_FOR_DEFINE_8   0x0009
#define DID_WORK_FOR_DEFINE_9   0x000A

/**
* @MISRA{MISRA C++-2008 Rule 18-2-1,This is intended design}
*/
#define REGIONDATA_HEAD  (offsetof(regionDataFormat, data) )


#include "EnvironmentVariant.h"


#endif /** _SERVICELAYER_REGIONNOSTIC_COMMAND_H_  */
