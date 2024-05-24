
#ifndef _DR_ENGINE_H_
#define _DR_ENGINE_H_

#include <vector>
#include <map>

#include <Typedef.h>
#include <corebase/SystemService.h>

#include <binder/IBinder.h>
#include <binder/IInterface.h>

#include <services/DrManagerService/IdrManagerReceiver.h>

#include <utils/Handler.h>
#include <utils/RefBase.h>
#include <utils/Timer.h>
#include <utils/external/mindroid/lang/String.h>
#include <utils/Mutex.h>
#include <utils/SLLooper.h>

#include "gnssReceiver.h"
#include "drReceiver.h"

#include "appMgrProxy.h"
#include "powerProxy.h"

#include "gnssData.h"
#include "ppsTime.h"
#include "fileHandler.h"

#include "trimbleConfig.h"

/* Trimble */
#include "gnssIface.h"
#include "drIface.h"
#include "ppIface.h"
#include "nvramIface.h"

using namespace std;
using namespace android;

#define DR_VALID (HIPST_POS | HIPST_HDG | HIPST_ZRO | HIPST_DPP | HIPST_GOODDHDG | HIPST_GOODTACH | HIPST_GSF)

class DrManagerService;
class DrHandler;
class DrTimer;
class ReceiverDeathRecipient;

class DrEngine : public RefBase
{
public:

    explicit DrEngine(DrManagerService& drManager);
    virtual ~DrEngine();

    void start();

    bool connectToAppMgr();
    bool connectToPowerMgr();

    error_t registerReceiver(uint32_t id,const sp<IDrManagerReceiver>& receiver);
    error_t unregisterReceiver(const sp<IDrManagerReceiver>& receiver);
    void onReceiverBinderDied(const android::wp<android::IBinder>& who);

    void updatePowerState(POWER_MODE state);
    bool isPowerOff();


    /* Trimble */
    bool initTrimble();
    bool readLastDataFromNVRAM();
    bool initTrimbleEngine();
    void clearTrimbleData();

    void startTrimble();
    void runTrimble();

    void notifyFirstGyroReceived();

    /* timer */
    void startWatchdog();
    void stopAllTimer();

    /* gnss */
    void sendGPSStatus(uint16_t gpsStatus);
    void sendGPSnmea(GpsUtcTime timestamp, const char* nmea, int length);
    void sendSvStatus(GnssSvStatus& svStatus);
    void XTRARequest(int type);
    void setCapabilities(uint32_t capabilities);

    bool gnssStart();
    bool gnssStop();
    bool gnssXTRAInit();
    bool gnssSetPositionMode(uint32_t mode,uint32_t recurrence,uint32_t min_interval, uint32_t preferred_accuracy, uint32_t preferred_time);
    bool gnssDeleteAidingData(int32_t mask);
    bool gnssInjectTime(int64_t time, int64_t timeReference, int32_t uncertainty);
    bool gnssInjectXtraData(const char* data, int length);
    int gnssGetGpsStartMode();
    bool gnssSetGnssUsedSystem(int32_t param);
    bool gnssGetGnssUsedSystem(int32_t &status);
    bool gnssSetGnssCn0(int32_t param);
    bool gnssGetGnssCn0(int32_t &status);
    bool gnssCommand(int32_t cmdType, int32_t value, int32_t& resp_value);
    bool setHippoLogging(bool enable);

private:

    void getGNSSData();
    void getMapMatchData();
    void getDRData();
    uint32_t getPPSTime();

    void printTROutputMode(uint8_t outputMode, uint32_t ageOfGNSS);
    void printTRResult(eDrLibCallReturnValues result,uint32_t hipStatus);
    void printDREngineOutputStatus(uint32_t status);

    void updateLocation(bool trimbleOutputisValid);
    void convertLegacyGPStoLocation(sp<tiger::Location>& location);
    void convertTROutputtoLocation(sp<tiger::Location>& location);

    void storeNVRAM(const npRawNvramType& nvram);

    DrManagerService& mDrManagerService;

    sp<DrHandler> mDrHandler;

    sp<AppMgrProxy> mAppMgrProxy;
    sp<PowerProxy> mPowerMgrProxy;

    sp<GNSSReceiver> mGNSSReceiver;
    sp<DrReceiver> mDrReceiver;

    /* Receiver */
    mutable Mutex mReceiverLock;
    sp<IDrManagerReceiver> mLocReceiver;
    sp<ReceiverDeathRecipient> mReceiverDeathRecipient;
    map<uint32_t, list< android::sp<IDrManagerReceiver>> > mReceivers;

    /* timer */
    DrTimer* mDrTimer;
    Timer* mWatchdogTimer;
    Timer* mTrimbleTimer;

    PPSTimeHandler* mPPSTimeHandler;

    /* trimble */
    mutable Mutex mTrimbleMutex;
    sp<TrimbleConfig> mTrimbleConfig;

    bool mTRisReady;
    bool mTRLastDataIsStored;

    npRawNvramType mTRrawNvram;
    npRawNvramType mTRLastStoredData;
    npDrOutputType mTROutputData;

    npGnssFixDataType mTRGNSSData;
    npDrDataType mTRDRData;
    npMapMatchInputType mTRmapMatchInput;

    GpsLocation mLegacyGPS;
    int32_t mGNSSusedSystem;

    eDrLibCallReturnValues lastTRResult;
    uint32_t lastHIPStatus;
    uint8_t lastTROutputMode;

    uint8_t mInputCnt;

    bool mTROutputValid;

    bool mFirstGyroReceived;

    uint32_t mPPSTime;

    POWER_MODE mPowerMode;

    bool mGNSSEngineRunning;
};

/* Message ID */
enum{
    MSG_CONNECT_TO_APPMGR      = 1,
    MSG_CONNECT_TO_POWERMGR,
    MSG_INIT_WATCHDOG,
    MSG_RECV_START_TRIMBLE,
    MSG_RECV_POWER_STATE,
    MSG_RECV_WATCH_DOG_TIMEOUT = 50,
    MSG_RECV_TRIMBLE_TIMEOUT,
    MSG_RECV_BOOT_COMPLETE     = 100,
};

class DrHandler : public sl::Handler{
public:
    static const int TIME_SEND_RETRY_DELAY_100_MS   = 100;
    static const int TIME_SEND_RETRY_DELAY_500_MS   = 500;
    static const int TIME_TRIMBLE_CALL_MS   = 100;
	static const int TIME_CALL_1000_MS = 1000;
    explicit DrHandler(sp<sl::SLLooper>& looper,DrEngine& outer):
        Handler(looper), mDrEngine(outer){}
    virtual void handleMessage(const sp<sl::Message>& msg);
private:
    DrEngine& mDrEngine;
};

class DrTimer : public TimerTimeoutHandler{
public:
    /* Timer ID */
    static const int TIMER_WATCHDOG = 1;
    static const int TIMER_TRIMBLE  = 2;

    /* Time value */
    static const int TRIMBLE_START_DURATION = 100;
    static const int TRIMBLE_TIME_OUT       = 100;

    explicit DrTimer(const sp<DrHandler>& handler) : mHandler(handler){}
    virtual void handlerFunction(int timer_id);

private:
    sp<DrHandler> mHandler;
};

class ReceiverDeathRecipient : public android::IBinder::DeathRecipient
{
public:
    explicit ReceiverDeathRecipient(DrEngine& drEngine) : mDrEngine(drEngine){}
    virtual ~ReceiverDeathRecipient() {}
    virtual void binderDied(const android::wp<android::IBinder>& who){
        mDrEngine.onReceiverBinderDied(who);
    }

private:
    DrEngine& mDrEngine;
};

#endif //_DRENGINE_H_

