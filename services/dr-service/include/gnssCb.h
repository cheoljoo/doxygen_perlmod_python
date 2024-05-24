
#ifndef _GNSS_CB_H_
#define _GNSS_CB_H_

#include <utils/Handler.h>
#include <Typedef.h>
#include <corebase/SystemService.h>
#include <utils/RefBase.h>
#include <utils/external/mindroid/lang/String.h>
#include <services/DrManagerService/gps.h>

using namespace std;
using namespace android;

class GnssInputHandler;

class GpsCb :  public RefBase{
public:
    GpsCb(sp<GnssInputHandler>& handler) : mGnssInputHandler(handler){ mThis = this; }
    virtual ~GpsCb(){};

    static void gps_locationCB(GpsLocation* location);
    static void gps_statusCB(GpsStatus* status);
    static void gps_sv_statusCB(GpsSvStatus* sv_status){}
    static void gps_nmeaCB(GpsUtcTime timestamp, const char* nmea, int length);
    static void gps_set_capabilitiesCB(uint32_t capabilities);
    static void gnss_sv_statusCB(GnssSvStatus* sv_info);

    static void gps_acquire_wakelockCB(){}
    static void gps_release_wakelockCB(){}
    static void gps_request_utc_timeCB(){}
    static void gnss_set_system_infoCB(const GnssSystemInfo* info){}

    static GpsCb* mThis;

private:
    sp<GnssInputHandler>& mGnssInputHandler;
};

class GpsXtraCb :  public RefBase{
public:
    GpsXtraCb(sp<GnssInputHandler>& handler) : mGnssInputHandler(handler){ mThis = this; }
    virtual ~GpsXtraCb(){};


    static void XTRA_requestCB(int request_type);
    static void XTRA_inject_dataCB(int data_event_type){}
    static void XTRA_inject_timeCB(int time_event_type){}

    static GpsXtraCb* mThis;

private:
    sp<GnssInputHandler>& mGnssInputHandler;
};

class GnssOEMDRECb : public RefBase{
public:
    GnssOEMDRECb(sp<GnssInputHandler>& handler) : mGnssInputHandler(handler){ mThis = this; }
    virtual ~GnssOEMDRECb(){};


    static void oemdre_gnss_svmeasCB(OemdreGnssSvMeasInfo* svMeas_info);
    static void oemdre_position_fix_reportCB(OemdrePositionFix* fix_info);
    static void oemdre_gnss_svpolyCB(OemdretGnssSvPoly* svPoly_info);
    static void oemdre_gps_ephemerisCB(GpsEphemeris* gpsEph_info);
    static void oemdre_glo_ephemerisCB(GloEphemeris* gloEph_info);
    static void oemdre_bds_ephemerisCB(BdsEphemeris* bdsEph_info);
    static void oemdre_gal_ephemerisCB(GalEphemeris* galEph_info);
    static void oemdre_cpe_reportCB(Oemcpe* cpe_info);
    static void oemdre_antenna_adcCB(GPSAntennaReport* value);
    static void oemdre_status_reportCB(GnssStatusReport* status_info);
    static void oemdre_nmea_reportCB(GpsUtcTime timestamp, const char* nmea, int length);

    static GnssOEMDRECb* mThis;

private:
    sp<GnssInputHandler>& mGnssInputHandler;
};

class GnssCB :  public RefBase{
public:
    GnssCB(sp<GnssInputHandler>& handler){
        mGpsCb = new GpsCb(handler);
        mGpsXtraCb = new GpsXtraCb(handler);
        mGnssOEMDRECb = new GnssOEMDRECb(handler);
    }
    virtual ~GnssCB(){};

private:
    sp<GpsCb> mGpsCb;
    sp<GpsXtraCb> mGpsXtraCb;
    sp<GnssOEMDRECb> mGnssOEMDRECb;
};

#endif //_GNSS_CB_H_
