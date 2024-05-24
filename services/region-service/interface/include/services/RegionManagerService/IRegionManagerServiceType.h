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

#ifndef _IREGION_MANAGER_SERVICE_TYPE_H_
#define _IREGION_MANAGER_SERVICE_TYPE_H_

/*
* @MISRA{MISRA C++-2008 Rule 16-2-1,"This is intended design"}
*/
#define REGION_SRV_NAME    "service_layer.RegionManagerService"

// @CGA_VARIANT_START{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}

    typedef enum {
        LGE_REGION_NONE = 0,
        LGE_REGION_JP,
        LGE_REGION_CN,
        LGE_REGION_NA,
        LGE_REGION_AU,
        LGE_REGION_SA,
        LGE_REGION_AE,
        LGE_REGION_IN,
        LGE_REGION_BH,
        LGE_REGION_QA,
        LGE_REGION_KW,
        LGE_REGION_NZ,
        LGE_REGION_KR,
        LGE_REGION_TW,
        LGE_REGION_MX,
        LGE_REGION_TH,
        LGE_REGION_MY,
        LGE_REGION_ID,
        LGE_REGION_PH,
        LGE_REGION_SG,
        LGE_REGION_ZA,
        LGE_REGION_VN,
        LGE_REGION_RESERVE,
        LGE_REGION_GLOBAL,
        LGE_REGION_ROW,
        LGE_REGION_ROW_V2X,
        LGE_REGION_RUS
    } LGE_REGION;

// @CGA_VARIANT___END{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}

#endif
