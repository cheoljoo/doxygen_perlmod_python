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

#ifndef SERVICELAYER_REGION_EXT_BASE_H
#define SERVICELAYER_REGION_EXT_BASE_H

/**
* @MISRA{MISRA C++-2008 Rule 16-2-1,"This is intended design"}
*/
#include <binder/IBinder.h>
#include <binder/IInterface.h>

#include <utils/Handler.h>
#include <utils/SLLooper.h>
#include <utils/Timer.h>
#include <utils/external/mindroid/lang/String.h>
#include <utils/Mutex.h>

#include <services/RegionManagerService/RegionCommand.h>

#include <string>

class RegionExtBase : public virtual android::RefBase {
 public:
    RegionExtBase() {};
    virtual ~RegionExtBase() {};

    virtual error_t init(android::sp<sl::SLLooper>& looper) = 0;
    virtual void handleBootComplete() = 0;

    /*GEN12*/ virtual uint8_t getNadType() { return 0; }
    /*GEN12*/ virtual uint8_t getRegionId() { return 0; }
    /*GEN12*/ virtual uint8_t getHwRevision() { return 0; }
    /*GEN12*/ virtual uint8_t getMcfgRegionId() { return 0; }
    /*24dcm*/ virtual error_t setHalSystemBootMode(uint32_t& bootMode) { return E_OK; }
    /*24dcm*/ virtual error_t setHalSystemNation(uint32_t& nation) { return E_OK; }
    /*24dcm*/ virtual uint32_t getHalSystemBootMode() { return 0; }
    /*24dcm*/ virtual uint32_t getHalSystemNation() { return 0; }
    /*24dcm*/ virtual uint8_t getNation() { return 0; }
    /*24dcm*/ virtual error_t memoryFileDelete(size_t& file_path_length, uint8_t* file_path) { return E_OK; }
    /*ICON*/  virtual android::sp<EnvironmentVariant> getVariantData() { mVariantData = new EnvironmentVariant(); return mVariantData; }
    /*ICON*/  virtual error_t setVariantData(const android::sp<EnvironmentVariant>& data) { return E_OK; }

 private:
    android::sp<EnvironmentVariant> mVariantData;  // dummy variant data
};
typedef RegionExtBase* create_t();
#endif /* SERVICELAYER_REGION_EXT_BASE_H */
