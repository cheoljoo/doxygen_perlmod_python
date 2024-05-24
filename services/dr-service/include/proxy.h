
#ifndef PROXY_H
#define PROXY_H

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/IServiceManager.h>

#include <utils/Handler.h>
#include <Typedef.h>
#include <corebase/SystemService.h>
#include <utils/RefBase.h>
#include <utils/external/mindroid/lang/String.h>

using namespace std;
using namespace android;

class Proxy: public RefBase{
public:
    Proxy(){}
    virtual ~Proxy(){}

    virtual void onServiceBinderDied(const android::wp<android::IBinder>& who) = 0;


    class ServiceDeathRecipient : public android::IBinder::DeathRecipient {
    public:
        ServiceDeathRecipient(Proxy& proxy) : mProxy(proxy) {}
        virtual ~ServiceDeathRecipient() {}
        virtual void binderDied(const android::wp<android::IBinder>& who)
        { mProxy.onServiceBinderDied(who);}
    private:
        Proxy& mProxy;
    };

protected:
    sp<ServiceDeathRecipient> mServiceDeathRecipient;
    mutable Mutex mBinderDiedLock;
};


#endif /* PROXY_H */
