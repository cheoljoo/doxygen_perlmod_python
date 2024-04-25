
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

#ifndef _IREGION_MANAGER_SERVICE_TYPE_H_
#define _IREGION_MANAGER_SERVICE_TYPE_H_

/*
* @MISRA{MISRA C++-2008 Rule 16-2-1,"This is intended design"}
*/
#define REGION_SRV_NAME    "service_layer.RegionManagerService"

// @CGA_VARIANT_START{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}

    typedef enum {
        /**< None */
        LGE_REGION_NONE = 0,
        /**< Japan */
        LGE_REGION_JP,
        /**< China */
        LGE_REGION_CN,
        /**< North America */
        LGE_REGION_NA,
        /**< Australia */
        LGE_REGION_AU,
        /**< Saudi */
        LGE_REGION_SA,
         /**< UAE */
        LGE_REGION_AE,
        /**< India */
        LGE_REGION_IN,
        /**< Bahrain */
        LGE_REGION_BH,
        /**< Qatar */
        LGE_REGION_QA,
        /**< Kuwait */
        LGE_REGION_KW,
        /**< New Zealand */
        LGE_REGION_NZ,
        /**< Korea */
        LGE_REGION_KR,
        /**< Taiwan */
        LGE_REGION_TW,
        /**< Global */
        LGE_REGION_GLOBAL,
        /**< Reserved */
        LGE_REGION_RESERVE,
        LGE_REGION_MAX
    } LGE_REGION;

    typedef enum {
        /**< Unknown - initial */
        NAD_REGION_UKN = 0 ,
        /**< North America */
        NAD_REGION_NA ,
        /**< Mexico */
        NAD_REGION_MEX ,
        /**< ROW SA */
        NAD_REGION_ROW_SA ,
        /**< ROW Europe */
        NAD_REGION_ROW_EU ,
        /**< ROW Korea / Middle East */
        NAD_REGION_ROW_KRME ,
        /**< UDA */
        NAD_REGION_UDA ,
        /**< China */
        NAD_REGION_CHN ,
        NAD_REGION_MAX
    } NAD_REGION;

    typedef enum {
        /**< Unknown - initial */
        NAD_TYPE_UKN = 0 ,
        /**< CSAV type */
        NAD_TYPE_CSAV ,
        /**< NonCSAV type */
        NAD_TYPE_NON_CSAV ,
        NAD_TYPE_MAX
    } NAD_TYPE;

    typedef enum {
        /**< Unknown - initial */
        NAD_REVISION_UKN = 0 ,
        /**< Rev A */
        NAD_REVISION_A ,
        /**< Rev B */
        NAD_REVISION_B ,
        /**< Rev C */
        NAD_REVISION_C ,
        /**< Rev D */
        NAD_REVISION_D ,
        /**< Rev E */
        NAD_REVISION_E ,
        /**< Rev F */
        NAD_REVISION_F ,
        /**< Rev G */
        NAD_REVISION_G ,
        /**< Rev H */
        NAD_REVISION_H ,
        NAD_REVISION_MAX
    } NAD_REVISION;

    typedef enum {
        /**< Unknown - initial */
        NAD_MCFG_REGION_UKN = 0 ,
        /**< Korea */
        NAD_MCFG_REGION_KR ,
        /**< Middle East */
        NAD_MCFG_REGION_ME ,
        NAD_MCFG_REGION_MAX
    } NAD_MCFG_REGION;

// @CGA_VARIANT___END{"__GLOBAL_SCOPE__:__YOUR_CODE__:variant"}

#endif
