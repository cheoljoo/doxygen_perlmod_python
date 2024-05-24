
#ifndef _GNSS_RECEIVER_H_
#define _GNSS_RECEIVER_H_

#include <utils/Handler.h>
#include <Typedef.h>
#include <corebase/SystemService.h>
#include <utils/RefBase.h>
#include <utils/external/mindroid/lang/String.h>

#include <services/DrManagerService/gps.h>

#include "gnssData.h"
#include "gnssCb.h"

using namespace std;
using namespace android;

class DrEngine;
class GNSSReceiver;

struct gnss_position_flag;
struct  nav_position_flag;

enum LocationFlagsBits{
    LOCATION_HAS_LAT_LONG_BIT          = (1<<0), // location has valid latitude and longitude
    LOCATION_HAS_ALTITUDE_BIT          = (1<<1), // location has valid altitude
    LOCATION_HAS_SPEED_BIT             = (1<<2), // location has valid speed
    LOCATION_HAS_BEARING_BIT           = (1<<3), // location has valid bearing
    LOCATION_HAS_ACCURACY_BIT          = (1<<4), // location has valid accuracy
    LOCATION_HAS_VERTICAL_ACCURACY_BIT = (1<<5), // location has valid vertical accuracy
    LOCATION_HAS_SPEED_ACCURACY_BIT    = (1<<6), // location has valid speed accuracy
    LOCATION_HAS_BEARING_ACCURACY_BIT  = (1<<7), // location has valid bearing accuracy
};

enum GNSSCommand {
    GPS_CMD_GET_STATUS_GNSS_GEODETIC_DATUM = 1,
    GPS_CMD_SET_STEUERN_GNSS_GEODETIC_DATUM = 2,
    GPS_CMD_GET_LEAP_SECONDS = 3,
    GPS_CMD_GET_GPS_WEEK = 4,
    GPS_CMD_GET_GLONASS_WEEK = 5,
    GPS_CMD_GET_BEIDOU_WEEK = 6,
    GPS_CMD_GET_GALILEO_WEEK = 7,
    GPS_CMD_GET_MAX
};


struct gpsTime{
  int32_t leapsec;
  int32_t gpsweek;
  int32_t gloweek;
  int32_t bdsweek;
  int32_t galweek;
};


class GnssInputHandler : public sl::Handler{
public:
    /* Handler Command from NAD */
    static const int RECV_MSG_FROM_GNSS_POS_FIX     = 1;
    static const int RECV_MSG_FROM_GNSS_MEAS        = 2;
    static const int RECV_MSG_FROM_GNSS_NMEA        = 3;
    static const int RECV_MSG_FROM_GNSS_STATUS      = 4;
    static const int RECV_MSG_FROM_GNSS_USED_SYSTEM = 5;
    static const int RECV_MSG_FROM_GNSS_LEGACY_GPS  = 6;
    static const int RECV_MSG_FROM_GNSS_CAPABILITY  = 7;
    static const int RECV_MSG_FROM_GNSS_SV_STATUS   = 8;
    static const int RECV_MSG_FROM_GNSS_XTRA_REQUEST = 9;

     /* Handler Command  from drMgr */
    static const int RECV_MSG_FROM_GNSS_INIT= 51;

    explicit GnssInputHandler(GNSSReceiver& outer): mGNSSReceiver(outer){}
    virtual void handleMessage(const sp<sl::Message>& msg);
private:
    GNSSReceiver& mGNSSReceiver;
};

class GNSSReceiver : public RefBase
{
public:

    /* GNSS Status defined by drMgr*/
    static const int GPS_STATUS_XTRA_READY = 10;

    explicit GNSSReceiver(DrEngine& drEngine);

    virtual ~GNSSReceiver(){};

    bool init();
    bool start();
    bool stop();

    void getGNSSData(npGnssFixDataType& gnssInput, GpsLocation& legacy, int32_t& usedSystem);

    bool gnssEngineInit();
    bool XTRAInit();
    bool setPositionMode(uint32_t mode,uint32_t recurrence,uint32_t min_interval, uint32_t preferred_accuracy, uint32_t preferred_time);
    bool deleteAidingData(int32_t mask);
    bool injectTime(int64_t time, int64_t timeReference, int32_t uncertainty);
    bool injectXtraData(const char* data, int length);
    int  getGpsStartMode();
    bool setGnsssUsedSystem(int32_t param);
    bool getGnssUsedSystem(int32_t &status);
    bool setGnssCn0(int32_t param);
    bool getGnssCn0(int32_t &status);
    bool command(int32_t cmdType, int32_t value, int32_t& resp);

    /* LEGACY GPS */
    void setGPSStatus(uint16_t status);
    void setGPSnmea(GpsUtcTime timestamp, const char* nmea, int32_t length);
    void setCapabilities(uint32_t capabilities);
    void setSVStatus(GnssSvStatus* sv_info);
    void setLegacyGPS(GpsLocation* location);

    /* XTRA */
    void XTRARequest(int32_t type);

    /* OEMDRE */
    void setOemdreSvmeas(OemdreGnssSvMeasInfo* svMeas_info);
    void setOemdrePositionFix(OemdrePositionFix* fix_info);
    void setGNSSUsedSystem(int32_t usedSystem);

private:

    void setPosFixType(gnss_position_flag& posFlags);
    void setPosFixFlags(gnss_position_flag& posFlags,nav_position_flag& navPosFlags, uint8_t initGpsTimeSrc);

    bool getGpsVSSInterface();
    bool getGnssInterface();

    DrEngine& mDrEngine;

    sp<GnssInputHandler> mGnssInputHandler;
    sp<GnssCB> mCb;

    /* GNSS data */
    sp<GNSSData> mGNSSData;

    const GpsInterface* pGpsInterface;
    const GpsXtraInterface* pGpsXTRAInterface;
    const VSSCommandInterface* pGpsVSSInterface;
    const GnssOEMDREInterface* pGnssOEMDREInterface;

    bool mGNSSEngineReady;
    bool mGNSSEngineRun;

    gpsTime mTime;

    int32_t mGNSSusedSystem;

    int32_t mVelocitycnt;
    int32_t mLegacyGPSCnt;
    int32_t mOemdreCnt;
};

#endif //_GNSS_RECEIVER_H_
