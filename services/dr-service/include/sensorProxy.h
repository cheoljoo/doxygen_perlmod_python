
#ifndef SENSOR_PROXY_H
#define SENSOR_PROXY_H

#include "proxy.h"

#if 0
#include <services/SomeIPConsumerService/ISomeIPConsumerService.h>

// Gear
#include <services/SomeIPConsumerService/IVehicleInformationSomeIPConsumer.h>
#include <services/SomeIPConsumerService/IVehicleInformationSomeIPConsumerReceiver.h>

// Yaw
#include <services/SomeIPConsumerService/IVehicleInfoRouterConsumer.h>
#include <services/SomeIPConsumerService/IVehicleInfoRouterReceiver.h>

// Speed
#include <services/SomeIPConsumerService/ISpeedAccelerationSomeIPConsumerReceiver.h>
#include <services/SomeIPConsumerService/ISpeedAccelerationSomeIPConsumerTypes.h>

// Wheel
#include <services/SomeIPConsumerService/IeCallDataSinkConsumer.h>


using namespace someipconsumer::vehicleinfor;
using namespace someipconsumer::speedacceleration;

#define TO_DEGREE          0.024
#define TO_DEGREE_PER_SEC  100
#define TO_SENSITIVITY     0.02


class DrInputHandler;
class SensorProxy : public Proxy{
public:
    SensorProxy(const sp<DrInputHandler>& handler): mHandler(handler){
        mServiceDeathRecipient = new ServiceDeathRecipient(*this);
    }
    virtual ~SensorProxy(){}

    virtual void onServiceBinderDied(const android::wp<android::IBinder>& who);

    bool connectToSensorMgr();
    bool registerGearReceiver();
    bool registerYawReceiver();
    bool registerSpeedReceiver();
    bool registerWheelReceiver();

    class GearReceiver : public BnVehicleInformationSomeIPConsumerReceiver{
    public:
        GearReceiver(sp<DrInputHandler>& handler) : mHandler(handler) {}
        virtual ~GearReceiver(){}
        virtual void OnStatusGearboxDriveChanged(const StatusGearboxDriveWrapper& newStatusGearboxDriveValue);
        virtual void OnRangeChanged(const RangeWrapper& rangeValue);
    private:
        sp<DrInputHandler> mHandler;
    };

    class YawReceiver : public BnVehicleInfoRouterReceiver{
    public:
        YawReceiver(sp<DrInputHandler>& handler) : mHandler(handler) {}
         virtual ~YawReceiver(){}
         virtual void onOdometryVehicle1Changed(const OdometryVehicle1Wrapper& odo1_value);

    private:
        sp<DrInputHandler> mHandler;
    };

    class SpeedReceiver : public BnSpeedAccelerationSomeIPConsumerReceiver{
    public:
        SpeedReceiver(sp<DrInputHandler>& handler) : mHandler(handler) {}
         virtual ~SpeedReceiver(){}
         virtual void OnVehicleSpeedChanged(const VehicleSpeedWrapper & VehicleSpeed);
         virtual void OnYawSpeedVehicleChanged(const YawSpeedVehicleWrapper & YawSpeed);

    private:
        sp<DrInputHandler> mHandler;
    };

    class WheelReceiver : public BneCallDataSinkConsumerReceiver{
    public:
        WheelReceiver(sp<DrInputHandler>& handler) : mHandler(handler) {}
        virtual ~WheelReceiver(){}
        virtual void onMileageVehicleAttributeExtensionChanged(const MileageVehicleWrapper& wheel);

    private:
        sp<DrInputHandler> mHandler;
    };

private:
    sp<DrInputHandler> mHandler;

    sp<ISomeIPConsumerService> mSomeIPConsumerService;

    sp<IVehicleInformationSomeIPConsumerReceiver> mGearReceiver;
    sp<IVehicleInfoRouterReceiver> mYawReceiver;
    sp<ISpeedAccelerationSomeIPConsumerReceiver> mSpeedReceiver;
    sp<IeCallDataSinkConsumerReceiver> mWheelReceiver;

};
#endif 
#endif /* SENSOR_PROXY_H */
