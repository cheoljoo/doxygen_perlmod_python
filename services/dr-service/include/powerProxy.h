


#ifndef POWER_PROXY_H
#define POWER_PROXY_H

#include "proxy.h"

#include <services/PowerManagerService/IPowerStateReceiver.h>
#include <services/PowerManagerService/IPowerManagerService.h>
#include <services/PowerManagerService/IPowerManagerServiceType.h>

enum POWER_MODE {
    POWER_MODE_INIT = 0,
    POWER_MODE_SLEEP,
    POWER_MODE_LOW_POWER,
    POWER_MODE_NAD_ALWAYS_ON,
    POWER_MODE_NAD_ALWAYS_ON_DEBUG,
    POWER_MODE_NORMAL_OPERATING,
    POWER_MODE_MTS,
    POWER_MODE_TEMPERATURE_SHUTDOWN,
    POWER_MODE_MAX,
};


class DrHandler;

class PowerProxy : public Proxy{
public:
    PowerProxy(const sp<DrHandler>& handler): mHandler(handler){
        mServiceDeathRecipient = new ServiceDeathRecipient(*this);
    }
    virtual ~PowerProxy(){}

    virtual void onServiceBinderDied(const android::wp<android::IBinder>& who);

    bool connectToPowerMgr();

    class PowerStateReceiver : public BnPowerStateReceiver{
    public:
        PowerStateReceiver(sp<DrHandler>& handler) : mHandler(handler) {}
        virtual ~PowerStateReceiver() {}
        virtual int32_t onPowerPreHandler(const int32_t toState, const int32_t reason);
        virtual void onWakeup(int32_t currentState, int32_t reason);

    private:
        sp<DrHandler> mHandler;
    };

private:
    sp<DrHandler> mHandler;
    sp<IPowerManagerService> mPowerManager;
    sp<IPowerStateReceiver> mPowerStateReceiver;
};


#endif /* POWER_PROXY_H */
