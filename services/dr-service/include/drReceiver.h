
#ifndef _DR_RECEIVER_H_
#define _DR_RECEIVER_H_

#include <utils/Handler.h>
#include <Typedef.h>
#include <corebase/SystemService.h>
#include <utils/RefBase.h>
#include <utils/external/mindroid/lang/String.h>

#include "sensorProxy.h"
#include "drData.h"


using namespace std;
using namespace android;

class DrEngine;
class DrReceiver;


/* Message ID */
enum{
    MSG_CONNECT_TO_SENSORMGR         = 1,
    MSG_REGISTER_GEAR_RECEIVER       = 2,
    MSG_REGISTER_YAW_RECEIVER        = 3,
    MSG_REGISTER_SPEED_RECEIVER      = 4,
    MSG_REGISTER_WHEEL_RECEIVER      = 5,
    MSG_RECV_GEAR                    = 6,
    MSG_RECV_YAW                     = 7,
    MSG_RECV_SPEED                   = 8,
    MSG_RECV_WHEEL                   = 9,
};

class DrInputHandler : public sl::Handler{
public:
    static const int TIME_SEND_RETRY_DELAY_100_MS   = 100;
    static const int TIME_SEND_RETRY_DELAY_500_MS   = 500;
    explicit DrInputHandler(DrReceiver& outer): Handler(),mDrReceiver(outer){}
    virtual void handleMessage(const sp<sl::Message>& msg);
private:
    DrReceiver& mDrReceiver;
};

class DrReceiver : public RefBase
{
public:
    explicit DrReceiver(DrEngine& drEngine);
    virtual ~DrReceiver(){};

    void start();

    void connectToSensorMgr();
    void registerGearReceiver();
    void registerYawReceiver();
    void registerSpeedReceiver();
    void registerWheelreceiver();

    void getDRData(npDrDataType& output);

    void setGear(uint32_t gear);
    void setYaw(int32_t yaw);
    void setSpeed(uint16_t speed);
    void setWheel(uint16_t wheel);

private:

    DrEngine& mDrEngine;

    sp<DrInputHandler> mDrInputHandler;
//    sp<SensorProxy> mSensorProxy;

    sp<DRData> mDRData;
};


#endif //_DR_RECEIVER_H_
