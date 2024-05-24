
#ifndef _TRIMBLE_CONFIG_H_
#define _TRIMBLE_CONFIG_H_

#include <Typedef.h>
#include <corebase/SystemService.h>
#include <utils/RefBase.h>
#include <utils/external/mindroid/lang/String.h>

/* Trimble */
#include "gnssIface.h"
#include "drIface.h"
#include "ppIface.h"
#include "fileHandler.h"

using namespace std;
using namespace android;

class TrimbleConfig : public RefBase{
public:

    explicit TrimbleConfig();
    virtual ~TrimbleConfig();

    npDrLibInitType* getTRInitParamPtr(){
        return &mTRInitPram;
   }

private:
    void initSystemFunction();
    void initGyroParam();
    void initVehicleCfg();
    void initDrLibCfg();
    void initVerInfo();

    npDrLibInitType mTRInitPram;

};


#endif //_TRIMBLE_CONFIG_H_

