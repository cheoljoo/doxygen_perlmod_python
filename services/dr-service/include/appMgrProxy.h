
#ifndef APPMGR_PROXY_H
#define APPMGR_PROXY_H

#include "proxy.h"

#include <services/ApplicationManagerService/IApplicationManagerService.h>
#include <services/ApplicationManagerService/IApplicationManagerServiceType.h>


class DrHandler;

class AppMgrProxy : public Proxy{
public:
    AppMgrProxy(const sp<DrHandler>& handler): mHandler(handler){
        mServiceDeathRecipient = new ServiceDeathRecipient(*this);
    }
    virtual ~AppMgrProxy(){}

    virtual void onServiceBinderDied(const android::wp<android::IBinder>& who);

    bool connectToAppMgr();

    class systemPostReceiver: public BnSystemPostReceiver {
    public:
        systemPostReceiver(sp<DrHandler>& handler) : mHandler(handler) {}
        virtual ~systemPostReceiver() {}
        virtual bool onSystemPostReceived(const sp<Post>& systemPost);
    private:
        sp<DrHandler> mHandler;
    };

private:
    sp<DrHandler> mHandler;
    sp<IApplicationManagerService> mAppManager;
    sp<ISystemPostReceiver> mSystemPostReceiver;
};



#endif /* APPMGR_PROXY_H */
