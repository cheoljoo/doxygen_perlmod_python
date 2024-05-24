
#ifndef _DR_DATA_H_
#define _DR_DATA_H_

#include <iostream>
#include <stdint.h>
#include <stddef.h>
#include <cmath>
#include <cstring>
#include <chrono>

#include <mutex>
#include <utils/Mutex.h>


#include <utils/Handler.h>
#include <Typedef.h>
#include <corebase/SystemService.h>
#include <utils/RefBase.h>
#include <utils/external/mindroid/lang/String.h>

#include <Log.h>

/* Trimble */
#include "gnssIface.h"
#include "drIface.h"
#include "ppIface.h"
#include "nvramIface.h"

#include "ppsTime.h"

using namespace std;
using namespace android;


enum DrInputStatus{
    DR_INPUT_NONE = 0,
    DR_INPUT_RUN,
    DR_INPUT_STOP
};


class DRData : public RefBase
{
public:

    DRData(): mPPSTimeHandler(PPSTimeHandler::getInstance()),mGear({0}),mGyro({0}),mSpeed({0}),
                mPreviousWheel(0),mRollOverCntWheel(0),mLastGearStatus(0xff),mGyroCnt(0x0),mSpeedCnt(0x0),mWheelCnt(0x0),
                mGyroLossCnt(0), mInputStatus(DR_INPUT_NONE),mGyroisValid(false){}
    virtual ~DRData(){}

    void clear(){
        mGear = {0};
        mGyro = {0};
        mSpeed = {0};
        mPreviousWheel = 0;
        mRollOverCntWheel = 0;
        mLastGearStatus = 0xff;
        mGyroCnt = 0x00;
        mSpeedCnt = 0x00;
        mWheelCnt = 0x00;
        mGyroLossCnt = 0;
        mInputStatus = DR_INPUT_NONE;
        mGyroisValid = false;

    }

    void getDRData(npDrDataType& output){

        output.ulSysTick = getSysTime();
        output.ulSysTickPps = getPPSTime();

        // Copy gear
        {
            Mutex::Autolock _l(mGearMutex);
#if 0
        /* For testing */
        mGear.bValid = true;
        mGear.ulSysTick = getSysTime();
        mGear.ulNumRpt++;
        mGear.ucValue = DRLIB_TRANS_FORWARD;
        /***************/
#endif			
            output.tTranShftLvrPos = mGear;
            //mGear = {0};
        }

        // Copy Gyro
        {
            Mutex::Autolock _l(mGyroMutex);
            if(mGyroisValid == false){
                mInputStatus = DR_INPUT_STOP;
                LOGE("[DRMGR][DRDATA][GYRO][%d] GYRO is missing",++mGyroLossCnt);
            }
            output.tGyro = mGyro;
            mGyroisValid = false;
            //mGyro = {0};
        }

        // Copy Speed
        {
            Mutex::Autolock _l(mSpeedMutex);
            output.tSpeed = mSpeed;
            //mSpeed = {0};
        }

        // Copy Wheel
        {
            Mutex::Autolock _l(mWheelMutex);
            output.tWheelTick = mWheel;
            //mWheel = {0};
        }

        output.eIgnSwState = IGN_SW_ON;

    }

    DrInputStatus getDRStatus(){
        return mInputStatus;
    }

    void setGear(uint32_t gear){

        Mutex::Autolock _l(mGearMutex);

        mGear.bValid = true;
        mGear.ulSysTick = getSysTime();
        mGear.ulNumRpt++;

        string str;

        switch(gear){
            case 1: // Neutral
                mGear.ucValue = DRLIB_TRANS_NEUTRAL;
                str = "NEUTRA:";
                break;

            case 2: // Reverse
                mGear.ucValue = DRLIB_TRANS_REVERSE;
                str = "REVERSE";
                break;

            case 3 : // Parking
                mGear.ucValue = DRLIB_TRANS_PARK;
                str = "PARKING";
                break;
            default: // Forward
                mGear.ucValue = DRLIB_TRANS_FORWARD;
                str = "FORWARD";
                break;
        }

        if(mGear.ucValue != mLastGearStatus){
            LOGI("[DRMGR][DRDATA][GEAR] %s  time:%d, cnt:%d, gear:%d (%d)",str.c_str(), mGear.ulSysTick, mGear.ulNumRpt, mGear.ucValue, gear);
            mLastGearStatus = mGear.ucValue;
        }
    }

    void setYaw(int32_t yaw){
        Mutex::Autolock _l(mGyroMutex);
        mGyro.ucSensorValid |= SENSOR_DATA_VALID;
        mGyro.ulSysTick = getSysTime();
        mGyro.ulNum++;
        mGyro.alCum[2] += yaw;
        mGyroisValid = true;

        if(mInputStatus != DR_INPUT_RUN){
            string str = (mInputStatus == DR_INPUT_NONE) ? "FIRST" : "RESTART";
            LOGI("[DRMGR][DRDATA][GYRO] %s ", str.c_str());
            mInputStatus = DR_INPUT_RUN;
        }

        if(++mGyroCnt % 100 == 0){
            LOGI("[DRMGR][DRDATA][GYRO] time:%d, cnt:%d, yaw:%d (%d)",mGyro.ulSysTick,mGyro.ulNum,mGyro.alCum[2], yaw);
            mGyroCnt = 0;
        }
    }

    void setSpeed(uint16_t speed){

        Mutex::Autolock _l(mSpeedMutex);

        mSpeed.bValid = true;
        mSpeed.ulSysTick = getSysTime();
        mSpeed.ulNumRpt++;

        // Convert speed in km/hr to m/sec
        mSpeed.fltValue = static_cast<float>(speed*0.015625*0.277778);

        if(++mSpeedCnt % 10 == 0){
            LOGI("[DRMGR][DRDATA][SPEED] time:%d, cnt:%d, speed:%f (%d)", mSpeed.ulSysTick, mSpeed.ulNumRpt, mSpeed.fltValue, speed);
            mSpeedCnt = 0;
        }
    }

    void setWheel(uint16_t wheel){

        static uint16_t total_wheel = 0;

        Mutex::Autolock _l(mWheelMutex);

        total_wheel += wheel;

        if(mPreviousWheel > total_wheel){
            mRollOverCntWheel++;
        }
        mPreviousWheel= total_wheel;

        unsigned int currentSysTick = 0;
        unsigned int diffSysTick = 0;
        static unsigned int previousSysTick = 0;

        currentSysTick = getSysTime();

        diffSysTick = currentSysTick - previousSysTick;
        if(previousSysTick == 0) {
            diffSysTick = 0;
        }
        previousSysTick = currentSysTick;

        mWheel.ulSysTick = getSysTime();
        mWheel.ulNumMsg++;
        mWheel.dblCumTimeMs = (mWheel.ulNumMsg*diffSysTick);

        mWheel.tWTLeftFront.ucSensorValid = SENSOR_DATA_VALID;
        mWheel.tWTLeftFront.ulCum = total_wheel + (mRollOverCntWheel*MAXIMUM_WHEEL_DATA);

        mWheel.tWTLeftRear.ucSensorValid = SENSOR_DATA_VALID;
        mWheel.tWTLeftRear.ulCum = total_wheel + (mRollOverCntWheel*MAXIMUM_WHEEL_DATA);

        mWheel.tWTRightFront.ucSensorValid = SENSOR_DATA_VALID;
        mWheel.tWTRightFront.ulCum = total_wheel + (mRollOverCntWheel*MAXIMUM_WHEEL_DATA);

        mWheel.tWTRightRear.ucSensorValid = SENSOR_DATA_VALID;
        mWheel.tWTRightRear.ulCum = total_wheel + (mRollOverCntWheel*MAXIMUM_WHEEL_DATA);

        if(++mWheelCnt % 10 == 0){
            LOGV("[DRMGR][DRDATA][WHEEL] time:%d, rollover:%d, wheel:%d (%d, %d)", mWheel.ulSysTick, mRollOverCntWheel, mWheel.tWTLeftFront.ulCum, wheel, total_wheel);
            mWheelCnt = 0;
        }

	}

    uint32_t getSysTime(){
        chrono::steady_clock m_clock_mono;
        auto time = chrono::duration_cast<chrono::milliseconds> (m_clock_mono.now().time_since_epoch()).count();
        //LOGI("[DRMGR][DRDATA] System time:%d ms",static_cast<uint32_t>(time));
        return static_cast<uint32_t>(time);
    }

    uint32_t getPPSTime(){
        if(mPPSTimeHandler == nullptr){
            LOGE("[DRMGR][DRDATA] PPSTimeHandler is null..");
            return 0;
        }
        return mPPSTimeHandler->getPPSTime();
    }

private:
    DRData(const DRData& other) {};
    DRData& operator=(const DRData& other){ return *this;};

    static const uint32_t MAXIMUM_WHEEL_DATA = 65535;
    static const uint32_t YAW_REFERENCE_DATA = 32768;

    PPSTimeHandler* mPPSTimeHandler;

    mutable Mutex mGearMutex;
    mutable Mutex mGyroMutex;
    mutable Mutex mSpeedMutex;
    mutable Mutex mWheelMutex;

    npTranShftLvrPosType mGear;
    np3AxisSensorType mGyro;
    npSpeedometerType mSpeed;
    npWheelTickType mWheel;

    uint16_t mPreviousWheel;
    uint64_t mRollOverCntWheel;

    uint8_t mLastGearStatus;

    uint8_t mGyroCnt;
    uint8_t mSpeedCnt;
    uint8_t mWheelCnt;

    uint32_t mGyroLossCnt;

    DrInputStatus mInputStatus;

    bool mGyroisValid;
};


#endif //_DR_DATA_H_
