
#ifndef _GNSS_DATA_H_
#define _GNSS_DATA_H_

#include <iostream>
#include <stdint.h>
#include <stddef.h>
#include <cmath>
#include <cstring>

#include <mutex>
#include <utils/Mutex.h>

#include <utils/Handler.h>
#include <Typedef.h>
#include <corebase/SystemService.h>
#include <utils/RefBase.h>
#include <utils/external/mindroid/lang/String.h>

#include <Log.h>
#include <services/DrManagerService/gps.h>

#include "gnssIface.h"
#include "drIface.h"
#include "ppIface.h"
#include "nvramIface.h"

using namespace std;
using namespace android;

/* If set, GNSS SV measurement is valid (detected by searcher) */
#define PDSM_GNSS_SV_INFO_MEAS_VALID       0x00000001
/* If set, GNSS SV is usable: {GPS|BDS} PRNs or {GLO} Slot IDs */
#define PDSM_GNSS_SV_INFO_USABLE           0x00000002
/* If set, GNSS SV is used for pos fix:   {GPS|BDS} PRNs or {GLO} Slot IDs */
#define PDSM_GNSS_SV_INFO_USED_IN_POS_FIX  0x00000004
/* If set, GNSS SV is used for velocity fix: {GPS|BDS} PRNs or {GLO} Slot IDs */
#define PDSM_GNSS_SV_INFO_USED_IN_VEL_FIX  0x00000008

#define SISE_OF_MEAS_DATA 4

struct OemdreMEAS{
    uint8_t utcOffset;
    uint8_t numOfSVs;
    uint16_t orbitDataFlag;
    uint16_t svStatusFlag;
    uint32_t timeTag;
    uint32_t refCount;
    uint32_t src;
    GnssMeasBlkStructT_v02 data[SISE_OF_MEAS_DATA];
};

//GNSS Position Flags
struct GnssPosFlag{
    // PositionFlags : 64 bit data
    uint64_t b_IsValid            : 1;  /* Solution is/is not valid */
    uint64_t b_IsPropagated       : 1;  /* Solution is/is not propagated */
    uint64_t b_IsWls              : 1;  /* Solution is/is not WLS */
    uint64_t b_IsKf               : 1;  /* Solution is/is not KF */
    uint64_t b_IsItarVln          : 1;  /* Solution is/is not in violation of ITAR */
    uint64_t b_IsOverDetrm        : 1;  /* Solution is/is not over determined */
    uint64_t b_IsExternal         : 1;  /* Solution is/is not an external update */
    uint64_t b_IsRefLoc           : 1;  /* Solution is/is not a ref loc update */
    uint64_t b_IsCoarsePos        : 1;  /* Solution is/is not a coarse pos update */
    uint64_t b_IsInternal         : 1;  /* Solution is/is not an internal update */
    uint64_t b_IsGpsUsed          : 1;  /* GPS is/is not used in solution */
    uint64_t b_IsGloUsed          : 1;  /* GLO is/is not used in solution */
    uint64_t b_IsBdsUsed          : 1;  /* BDS is/is not used in solution */
    uint64_t b_IsGalUsed          : 1;  /* GAL is/is not used in solution */
    uint64_t b_IsSft              : 1;  /* Solution is/is not SFT */
    uint64_t b_Is3D               : 1;  /* Solution is/is not 3D */
    uint64_t b_IsAltConstr        : 1;  /* Solution is/is not alt constrained */
    uint64_t b_IsGpsGloTBConstr   : 1;  /* Solution is/is not GpsGloTB constrained */
    uint64_t b_IsGpsBdsTBConstr   : 1;  /* Solution is/is not GpsBdsTB constrained */
    uint64_t b_IsBdsGloTBConstr   : 1;  /* Solution is/is not BdsGloTB constrained */
    uint64_t b_IsMagDevValid      : 1;  /* Magnetic deviation is/is not valid */
    uint64_t b_IsFinal            : 1;  /* Solution is/is not final */
    uint64_t b_IsBackground       : 1;  /* Solution is/is not background */
    uint64_t b_IsPeGenerated      : 1;  /* Solution is/is not PE generated */
    uint64_t b_IsMeGenerated      : 1;  /* Solution is/is not ME generated */
    uint64_t b_IsGpsXtraSln       : 1;  /* Solution is/is not using GPS XTRA */
    uint64_t b_IsGpsXtraEphSln    : 1;  /* Solution is/is not using GPS XTRA and ephemeris */
    uint64_t b_IsGloXtraSln       : 1;  /* Solution is/is not using Glonass XTRA */
    uint64_t b_IsGloXtraEphSln    : 1;  /* Solution is/is not using Glonass XTRA and ephemeris */
    uint64_t b_IsBdsXtraSln       : 1;  /* Solution is/is not using Beidou XTRA */
    uint64_t b_IsBdsXtraEphSln    : 1;  /* Solution is/is not using Beidou XTRA and ephemeris */
    uint64_t b_IsWifiGenerated    : 1;  /* Solution is/is not WIFI generated */
    uint64_t b_IsHeadingValid     : 1;  /* Heading is/is not valid */
    uint64_t b_IsVelValid         : 1;  /* Velocity is/is not valid */
    uint64_t b_IsEpiHzConstr      : 1;  /* Solution does/does not use an EPI as a horizontal constraint */
    uint64_t b_IsEpiAltConstr     : 1;  /* Solution does/does not use an EPI as an altitude constraint */
    uint64_t b_IsStatic           : 1;  /* Solution is/is not in KF static mode */
    uint64_t b_IsSpiValid         : 1;  /* SPI is/is not valid */
    uint64_t b_IsSpiStationary    : 1;  /* SPI is/is not indicating stationary. Only valid if b_XspiValid == TRUE */
    uint64_t b_IsPosAssistValid   : 1;  /* Initial position is/is not valid for this second. */
    uint64_t b_IsGile             : 1;  /* Solution source is/is not GILE */
    uint64_t b_IsGnssInsSln       : 1;  /* Solution used GNSS and INS measurements */
    uint64_t b_IsInsOnlySln       : 1;  /* Solution used Only INS measurements */
    uint64_t b_IsKfInitFromEpi    : 1;  /* KF is/is not initialized from an EPI */
    uint64_t b_IsKfPvFiltered     : 1;  /* KF is/is not a PV filtered result */
    uint64_t b_IsXmsiKnown        : 1;  /* XMSI is known = true, false otherwise */
    uint64_t b_IsXmsiMounted      : 1;  /* XMSI is mounted = true, false otherwise */
    uint64_t b_IsMsiKnown         : 1;  /*  MSI is known = true, false otherwise */
    uint64_t b_IsMsiMounted       : 1;  /*  MSI is mounted = true, false otherwise */
    uint64_t b_IsCrdDetected      : 1;  /*  Cradle Rotation is = true, false otherwise */
    uint64_t b_IsNhcUsedForHeading : 1; /* NHC used for GILE heading = TRUE */
    uint64_t b_IsEcid             : 1;  /* Solution is an E-CID position = TRUE */
    uint64_t b_IsPle              : 1;  /* Solution is/is not a PLE */
    uint64_t b_IsCellid           : 1;  /* Solution is an Cell ID position = TRUE */
    uint64_t b_IsZppFinal         : 1;  /* Solution is for ZPP reported position = TRUE */
    uint64_t b_IsVehOnlySln       : 1;  /* Solution used only vehicle sensor measurements */
    uint64_t b_IsPedestrianDrSln  : 1;  /* Solution used only pedestrian sensors */
    uint64_t b_IsGpsGcf           : 1;  /* Solution derived while GPS was in GCF */
    uint64_t b_IsGloGcf           : 1;  /* Solution derived while GLO was in GCF */
    uint64_t b_IsBdsGcf           : 1;  /* Solution derived while BDS was in GCF */
    uint64_t b_IsGalGcf           : 1;  /* Solution derived while GAL was in GCF */
    uint64_t b_IsPedWithoutGnss   : 1;  /* flag to indicate pedestrian in w/o GNSS,  used for time-out check */
    uint64_t b_IsPedWithoutGnssTimeout : 1; /* flag to indicate pedestrian w/o GNSS timeout */
    uint64_t b_IsInPedMode        : 1;  /* flag to indicate pedestrian mode */

    // PositionFlags_Ext : 24 bit data
    uint64_t b_IsCogUsed          : 1;  /* Solution used COG data */
    uint64_t b_IsSpdInputUsed     : 1;  /* Solution used Speed input data */
    uint64_t b_IsQzssUsed         : 1;  /* QZSS is/is not used in solution */
    uint64_t b_IsQzssXtraSln      : 1;  /* Solution is/is not using QZSS XTRA */
    uint64_t b_IsQzssXtraEphSln   : 1;  /* Solution is/is not using QZSS XTRA and ephemeris */
    uint64_t b_IsQzssGcf          : 1;  /* Solution derived while QZSS was in GCF */
    uint64_t b_IsGpsGalTBConstr   : 1;  /* Solution is/is not GpsGalTB constrained */
    uint64_t b_IsGalGloTBConstr   : 1;  /* Solution is/is not GalGloTB constrained */
    uint64_t b_IsGalBdsTBConstr   : 1;  /* Solution is/is not GalBdsTB constrained */
    uint64_t b_IsGalXtraSln       : 1;  /* Solution is/is not using Galileo XTRA */
    uint64_t b_IsGalXtraEphSln    : 1;  /* Solution is/is not using Galileo XTRA and ephemeris */
    uint64_t b_IsSbasIonoCorr     : 1;  /* Solution is/is not using SBAS ionospheric correction */
    uint64_t b_IsSbasFastCorr     : 1;  /* Solution is/is not using SBAS fast correction */
    uint64_t b_IsSbasLongCorr     : 1;  /* Solution is/is not using SBAS long-term correction */
    uint64_t b_IsSbasIntegrity    : 1;  /* Solution is/is not using SBAS integrity information */
    uint64_t b_PVAPropagationUsedFixRpt:1; /* acceleration derived from fix history used */

    uint64_t b_IsTdpUsed          : 1;   /* TDP Meas are/are not used in the solution */
    uint64_t b_IsINP              : 1;   /* Position is a Internal (Qualcomm) network provider position */
    uint64_t b_IsExtNP            : 1;   /* Position is an External Network provider position*/
    uint64_t b_FullGnssUsedFixRpt : 1;   /* Fix used full GNSS meas information */
    uint64_t b_IsDgpsModeEngaged  : 1;   /* Flag to indicate if D-GPS mode engaged or not */

    uint64_t b_IsDgnssCorr        : 1;  /* Solution is/is not using DGNSS correction */
    uint64_t b_IsOemDreFix        : 1;  /* If this fix is to be shipped to OEM DRE client */
    uint64_t                      : 40; /* Padding to align with 8 byte boundary, 82+46=128  */
};

//Nav Position Flags : 15 bit data
struct NavPosFlag
{
    /* GPS position report validity flags */
    uint64_t b_IsItarViolated      : 1;
    uint64_t b_IsGpsTimeValid      : 1;
    uint64_t b_IsPuncValid         : 1;
    uint64_t b_IsTuncValid         : 1;

    /* Technology used in computing the position fix flags */
    uint64_t b_IsSatellite         : 1; /* Satellite is used for computing position fix */
    uint64_t b_IsCellId            : 1; /* Cell Id is used for computing position fix */
    uint64_t b_IsWifi              : 1; /* Wifi is used for computing postion fix */
    uint64_t b_IsSensors           : 1; /* Sensors is used for computing position fix */
    uint64_t b_IsRefLoc            : 1; /* Reference location is used for computing position fix */
    uint64_t b_IsCoarsePos         : 1; /* Coarse position is used for computing position fix */

    uint64_t b_IsPosBestAvail      : 1; /* Pos is best available position */
    uint64_t b_IsSensorPropogatedGNSSFix : 1; /* Solution used Only INS ONLY fixes */
    uint64_t b_IsTdp               : 1; /* TDP meas are used for computing position fix */
    uint64_t b_IsPosInConsistent   : 1; /* Indication to SM is any inconsistency detected amongst position in ALE database during a emergency session */
    uint64_t b_IsPosFallBackGnss   : 1; /* Position is a fall back GNSS position and not necessarily best */
};

class GNSSData : public RefBase
{
public:

    static const uint8_t PDSM_GNSS_TIME_SRC_UNKNOWN             = 0x00; /* Source of the Time is unknown */
    static const uint8_t PDSM_GNSS_TIME_SRC_GPS_TOW_DECODE      = 0x04; /* Time is set after decoding over the air GPS navigation data
                                                                           from one GPS satellite */
    static const uint8_t PDSM_GNSS_TIME_SRC_TOW_CONFIRMED       = 0x05; /* Time is set after decoding over the air GPS navigation data
                                                                           from multiple satellites */
    static const uint8_t PDSM_GNSS_TIME_SRC_TOW_WEEK_CONFIRMED  = 0x06; /* Both time of the week and the GPS week number known */
    static const uint8_t PDSM_GNSS_TIME_SRC_NAV_SOLUTION        = 0x08; /* Time is set by position engine
                                                                           after the fix is obtained. */
    static const uint8_t PDSM_GNSS_TIME_SRC_SOLVE_FOR_TIME      = 0x09; /* Time is set by the position engine after performing SFT.
                                                                           This is done when the clock time uncertainty is large */
    static const uint8_t PDSM_GNSS_TIME_SRC_INVALID             = 0xFF; /* Invalid time */

    GNSSData():mGNSSusedSystem(0),mLegacyGPSData({}),mOEMDREData({}),mMEASData({}),mTrimbleData({}),mIsFix(false),mLastFixTimeMs(0){}
    virtual ~GNSSData(){}

    void clear(){
        mGNSSusedSystem = 0;
        mLegacyGPSData = {};
        mOEMDREData = {};
        mMEASData = {};
        mTrimbleData = {};
        mIsFix = false;
        mLastFixTimeMs = 0;
    }

    void setGNSSUsedSystem(int32_t usedSystem){
        Mutex::Autolock _l(mUsedSystemMutex);
        mGNSSusedSystem = usedSystem;
    }

    void setMEAS(OemdreGnssSvMeasInfo& svMeas_info){

        Mutex::Autolock _l(mMeasMutex);

        // GPS - UTC offset = leap seconds
        mMEASData.utcOffset = (svMeas_info.measBlk.MeasClock.zTime.zGnssTimeBias.DeltaLeapSecUnc == 0) ? svMeas_info.measBlk.MeasClock.zTime.zGnssTimeBias.DeltaLeapSec : 0;

        // Number of reported channels
        //mMEASData.numOfSVs = svMeas_info.measBlk.NumSvs;

        mMEASData.orbitDataFlag = static_cast<uint16_t>(CHST_REFPOS | CHST_REFVEL | CHST_LLOS | CHST_AZ_EL);
        mMEASData.svStatusFlag = static_cast<uint16_t>(CHST_PR_RESID | CHST_RR_RESID | CHST_PR_IONO |
                        CHST_RR_IONO | CHST_PR_TROPO | CHST_RR_TROPO);

        // GPS timetag of measurement (msec)
        mMEASData.timeTag = svMeas_info.measBlk.MeasClock.zTime.zGpsTime.GpsMsec;
        mMEASData.refCount = svMeas_info.measBlk.MeasClock.RefFCount;
        mMEASData.src = svMeas_info.measBlk.MeasBlkSrc;

        switch (svMeas_info.measBlk.MeasBlkSrc) {
            case GNSS_MEAS_BLK_SRC_GPS:
            case GNSS_MEAS_BLK_SRC_GLO:
            case GNSS_MEAS_BLK_SRC_BDS:
            case GNSS_MEAS_BLK_SRC_GAL:
                memcpy(&mMEASData.data[svMeas_info.measBlk.MeasBlkSrc], &(svMeas_info.measBlk),sizeof(GnssMeasBlkStructT_v02));
                break;
            default:
                //LOGI("[DRMGR][GNSSDATA] do not useed satelite sys id = %d\n",svMeas_info.measBlk.MeasBlkSrc);
                break;
        }

    }

    void setLegacyGPS(GpsLocation* location, size_t size){
        if(location == nullptr){
            LOGE("[DRMGR][GNSSDATA] GpsLocation is null..");
            return;
        }

        Mutex::Autolock _l(mLegacyGPSMutex);
        mLegacyGPSData = *location;
    }

    void setPositionFixData(OemdrePositionFix* src, size_t size){
        if(src == nullptr){
            LOGE("[DRMGR][GNSSDATA] OemdrePositionFix is null..");
            return;
        }

        Mutex::Autolock _l(mPosFixMutex);
        if(src->NoFixFlags){
            mOEMDREData = {};
            mIsFix = false;
        }else{
            mOEMDREData = *src;
            mIsFix = true;
        }
    }

    // check time sychronization between each informations (Measurement/Position/CPE)
    bool checkTimeSyncIndication(){

        uint32_t measTime = 0;
        uint32_t posTime = 0;

        {
            Mutex::Autolock _l(mMeasMutex);
            measTime = mMEASData.timeTag;
        }

        {
            Mutex::Autolock _l(mPosFixMutex);
            posTime = mOEMDREData.LGEPositionFix.GpsTimeMs;
        }

        if(mIsFix == false){
            return false;
        }

        if(measTime != posTime){
            return false;
        }

        if(mLastFixTimeMs == posTime){
            //LOGI("[DRMGR][GNSSDATA] TIME is same (pos:%d,last:%d) ",posTime,mLastFixTimeMs);
            return false;
        }

        mLastFixTimeMs = posTime;

        return true;
    }

    void getGPSChannelInfo(int src, int& iTrimbleCh, uint8_t& numSvInFix, int iQcomCh, int iSvInfo){

        //uint16_t svId = 0;
        uint32_t svInfoMask = 0;

        {
            Mutex::Autolock _l(mPosFixMutex);
            svInfoMask = mOEMDREData.NavSvInfo.GpsSvInfo[iSvInfo].SvInfoMask;
            //svId = mOEMDREData.NavSvInfo.GpsSvInfo[iSvInfo].SvId;

            mTrimbleData.tMeas.atCh[iTrimbleCh].dblPRResid = mOEMDREData.NavSvInfo.GpsSvInfo[iSvInfo].PrResMeters;
            mTrimbleData.tMeas.atCh[iTrimbleCh].fltDoppResid = mOEMDREData.NavSvInfo.GpsSvInfo[iSvInfo].PrrResMps;
            mTrimbleData.tMeas.atCh[iTrimbleCh].fltWeight = mOEMDREData.NavSvInfo.GpsSvInfo[iSvInfo].PrUncMeters;
            mTrimbleData.tMeas.atCh[iTrimbleCh].cFreqNum = mOEMDREData.NavSvInfo.GpsSvInfo[iSvInfo].FreqNum;
        }

        Mutex::Autolock _l(mMeasMutex);

        mTrimbleData.tMeas.atCh[iTrimbleCh].tSvId.eSvSys = GPS;
        mTrimbleData.tMeas.atCh[iTrimbleCh].tSvId.ucSvId = mMEASData.data[src].zGnss[iQcomCh].Sv;

        if(((svInfoMask & PDSM_GNSS_SV_INFO_MEAS_VALID) == PDSM_GNSS_SV_INFO_MEAS_VALID)
                && ((svInfoMask & PDSM_GNSS_SV_INFO_USED_IN_POS_FIX) == PDSM_GNSS_SV_INFO_USED_IN_POS_FIX)
                && ((svInfoMask & PDSM_GNSS_SV_INFO_USED_IN_VEL_FIX) == PDSM_GNSS_SV_INFO_USED_IN_VEL_FIX)){

            mTrimbleData.tMeas.atCh[iTrimbleCh].bSvUsedInFix = true;
            numSvInFix++;
        }
        else{
            mTrimbleData.tMeas.atCh[iTrimbleCh].bSvUsedInFix = false;
        }

        mTrimbleData.tMeas.atCh[iTrimbleCh].ucSNR = mMEASData.data[src].zGnss[iQcomCh].Cno * 0.1;
        mTrimbleData.tMeas.atCh[iTrimbleCh].ucCNO = mMEASData.data[src].zGnss[iQcomCh].Cno * 0.1;
        mTrimbleData.tMeas.atCh[iTrimbleCh].dblPR = (mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.zSvTime.Ms + mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.zSvTime.SubMs) * 299792.458;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltPrUnc = mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.SvTimeUncMs * 299792.458;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltDopp = mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.SvSpeed;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltDrUnc = mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.SvSpeedUnc;

        mTrimbleData.tMeas.atCh[iTrimbleCh].ucQual = ((svInfoMask & PDSM_GNSS_SV_INFO_MEAS_VALID) == PDSM_GNSS_SV_INFO_MEAS_VALID) ? GNSS_MEAS_VALID : 0;

        mTrimbleData.tMeas.atCh[iTrimbleCh].ulChStatusFlag = mMEASData.data[src].zGnss[iQcomCh].MeasStatus;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltAzim = mMEASData.data[src].zGnss[iQcomCh].Azimuth * RAD2DEG;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltElev = mMEASData.data[src].zGnss[iQcomCh].Elevation * RAD2DEG;

        //LOGI("[DRMGR][GNSSDATA] GPS ch:%d,sv:%d,svId:%d",iTrimbleCh, mMEASData.data[src].zGnss[iQcomCh].Sv,svId);

        iTrimbleCh++;
    }

    void getGLOChannelInfo(int src, int& iTrimbleCh, uint8_t& numSvInFix, int iQcomCh, int iSvInfo){

        //uint16_t svId = 0;
        uint32_t svInfoMask = 0;

        {
            Mutex::Autolock _l(mPosFixMutex);
            svInfoMask = mOEMDREData.NavSvInfo.GloSvInfo[iSvInfo].SvInfoMask;
            //svId = mOEMDREData.NavSvInfo.GloSvInfo[iSvInfo].SvId;
            mTrimbleData.tMeas.atCh[iTrimbleCh].dblPRResid = mOEMDREData.NavSvInfo.GloSvInfo[iSvInfo].PrResMeters;
            mTrimbleData.tMeas.atCh[iTrimbleCh].fltDoppResid = mOEMDREData.NavSvInfo.GloSvInfo[iSvInfo].PrrResMps;
            mTrimbleData.tMeas.atCh[iTrimbleCh].fltWeight = mOEMDREData.NavSvInfo.GloSvInfo[iSvInfo].PrUncMeters;
            mTrimbleData.tMeas.atCh[iTrimbleCh].cFreqNum = mOEMDREData.NavSvInfo.GloSvInfo[iSvInfo].FreqNum;
        }

        Mutex::Autolock _l(mMeasMutex);

        mTrimbleData.tMeas.atCh[iTrimbleCh].tSvId.eSvSys = GLO;
        mTrimbleData.tMeas.atCh[iTrimbleCh].tSvId.ucSvId = mMEASData.data[src].zGnss[iQcomCh].Sv - 64;

        if(((svInfoMask & PDSM_GNSS_SV_INFO_MEAS_VALID) == PDSM_GNSS_SV_INFO_MEAS_VALID)
                && ((svInfoMask & PDSM_GNSS_SV_INFO_USED_IN_POS_FIX) == PDSM_GNSS_SV_INFO_USED_IN_POS_FIX)
                && ((svInfoMask & PDSM_GNSS_SV_INFO_USED_IN_VEL_FIX) == PDSM_GNSS_SV_INFO_USED_IN_VEL_FIX)){
            mTrimbleData.tMeas.atCh[iTrimbleCh].bSvUsedInFix = true;
            numSvInFix++;
        }
        else {
            mTrimbleData.tMeas.atCh[iTrimbleCh].bSvUsedInFix = false;
        }

        mTrimbleData.tMeas.atCh[iTrimbleCh].ucSNR = mMEASData.data[src].zGnss[iQcomCh].Cno * 0.1;
        mTrimbleData.tMeas.atCh[iTrimbleCh].ucCNO = mMEASData.data[src].zGnss[iQcomCh].Cno * 0.1;
        mTrimbleData.tMeas.atCh[iTrimbleCh].dblPR = (mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.zSvTime.Ms + mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.zSvTime.SubMs) * 299792.458;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltPrUnc = mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.SvTimeUncMs * 299792.458;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltDopp = mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.SvSpeed;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltDrUnc = mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.SvSpeedUnc;

        mTrimbleData.tMeas.atCh[iTrimbleCh].ucQual = ((svInfoMask & PDSM_GNSS_SV_INFO_MEAS_VALID) == PDSM_GNSS_SV_INFO_MEAS_VALID) ? GNSS_MEAS_VALID : 0;

        mTrimbleData.tMeas.atCh[iTrimbleCh].ulChStatusFlag = mMEASData.data[src].zGnss[iQcomCh].MeasStatus;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltAzim = mMEASData.data[src].zGnss[iQcomCh].Azimuth * RAD2DEG;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltElev = mMEASData.data[src].zGnss[iQcomCh].Elevation * RAD2DEG;

        //LOGI("[DRMGR][GNSSDATA] GLO ch:%d,sv:%d,svId:%d",iTrimbleCh, mMEASData.data[src].zGnss[iQcomCh].Sv, svId);

        iTrimbleCh++;

    }

    void getBDSChannelInfo(int src, int& iTrimbleCh, uint8_t& numSvInFix, int iQcomCh, int iSvInfo){

        //uint16_t svId = 0;
        uint32_t svInfoMask = 0;

        {
            Mutex::Autolock _l(mPosFixMutex);
            svInfoMask = mOEMDREData.NavSvInfo.GloSvInfo[iSvInfo].SvInfoMask;
            //svId = mOEMDREData.NavSvInfo.GloSvInfo[iSvInfo].SvId;
            mTrimbleData.tMeas.atCh[iTrimbleCh].dblPRResid = mOEMDREData.NavSvInfo.BdsSvInfo[iSvInfo].PrResMeters;
            mTrimbleData.tMeas.atCh[iTrimbleCh].fltDoppResid = mOEMDREData.NavSvInfo.BdsSvInfo[iSvInfo].PrrResMps;
            mTrimbleData.tMeas.atCh[iTrimbleCh].fltWeight = mOEMDREData.NavSvInfo.BdsSvInfo[iSvInfo].PrUncMeters;
            mTrimbleData.tMeas.atCh[iTrimbleCh].cFreqNum = mOEMDREData.NavSvInfo.BdsSvInfo[iSvInfo].FreqNum;
        }

        Mutex::Autolock _l(mMeasMutex);

        mTrimbleData.tMeas.atCh[iTrimbleCh].tSvId.eSvSys = BDS;
        mTrimbleData.tMeas.atCh[iTrimbleCh].tSvId.ucSvId = mMEASData.data[src].zGnss[iQcomCh].Sv - 200;

        if(((svInfoMask & PDSM_GNSS_SV_INFO_MEAS_VALID) == PDSM_GNSS_SV_INFO_MEAS_VALID)
                && ((svInfoMask & PDSM_GNSS_SV_INFO_USED_IN_POS_FIX) == PDSM_GNSS_SV_INFO_USED_IN_POS_FIX)
                && ((svInfoMask & PDSM_GNSS_SV_INFO_USED_IN_VEL_FIX) == PDSM_GNSS_SV_INFO_USED_IN_VEL_FIX)) {
            mTrimbleData.tMeas.atCh[iTrimbleCh].bSvUsedInFix = true;
            numSvInFix++;
        }
        else {
            mTrimbleData.tMeas.atCh[iTrimbleCh].bSvUsedInFix = false;
        }

        mTrimbleData.tMeas.atCh[iTrimbleCh].ucSNR = mMEASData.data[src].zGnss[iQcomCh].Cno * 0.1;
        mTrimbleData.tMeas.atCh[iTrimbleCh].ucCNO = mMEASData.data[src].zGnss[iQcomCh].Cno * 0.1;
        mTrimbleData.tMeas.atCh[iTrimbleCh].dblPR = (mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.zSvTime.Ms + mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.zSvTime.SubMs) * 299792.458;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltPrUnc = mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.SvTimeUncMs * 299792.458;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltDopp = mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.SvSpeed;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltDrUnc = mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.SvSpeedUnc;

        mTrimbleData.tMeas.atCh[iTrimbleCh].ucQual = ((svInfoMask & PDSM_GNSS_SV_INFO_MEAS_VALID) == PDSM_GNSS_SV_INFO_MEAS_VALID) ? GNSS_MEAS_VALID : 0;

        mTrimbleData.tMeas.atCh[iTrimbleCh].ulChStatusFlag = mMEASData.data[src].zGnss[iQcomCh].MeasStatus;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltAzim = mMEASData.data[src].zGnss[iQcomCh].Azimuth * RAD2DEG;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltElev = mMEASData.data[src].zGnss[iQcomCh].Elevation * RAD2DEG;

        //LOGI("[DRMGR][GNSSDATA] BDS ch:%d,sv:%d,svId:%d", iTrimbleCh, mMEASData.data[src].zGnss[iQcomCh].Sv, svId);

        iTrimbleCh++;
    }

    void getGALChannelInfo(int src, int& iTrimbleCh, uint8_t& numSvInFix, int iQcomCh, int iSvInfo){

        //uint16_t svId = 0;
        uint32_t svInfoMask = 0;

        {
            Mutex::Autolock _l(mPosFixMutex);
            svInfoMask = mOEMDREData.NavSvInfo.GloSvInfo[iSvInfo].SvInfoMask;
            //svId = mOEMDREData.NavSvInfo.GloSvInfo[iSvInfo].SvId;
            mTrimbleData.tMeas.atCh[iTrimbleCh].dblPRResid = mOEMDREData.NavSvInfo.GalSvInfo[iSvInfo].PrResMeters;
            mTrimbleData.tMeas.atCh[iTrimbleCh].fltDoppResid = mOEMDREData.NavSvInfo.GalSvInfo[iSvInfo].PrrResMps;
            mTrimbleData.tMeas.atCh[iTrimbleCh].fltWeight = mOEMDREData.NavSvInfo.GalSvInfo[iSvInfo].PrUncMeters;
            mTrimbleData.tMeas.atCh[iTrimbleCh].cFreqNum = mOEMDREData.NavSvInfo.GalSvInfo[iSvInfo].FreqNum;
        }

        Mutex::Autolock _l(mMeasMutex);

        mTrimbleData.tMeas.atCh[iTrimbleCh].tSvId.eSvSys = GAL;
        mTrimbleData.tMeas.atCh[iTrimbleCh].tSvId.ucSvId = mMEASData.data[src].zGnss[iQcomCh].Sv - 300;

        if(((svInfoMask & PDSM_GNSS_SV_INFO_MEAS_VALID) == PDSM_GNSS_SV_INFO_MEAS_VALID)
                && ((svInfoMask & PDSM_GNSS_SV_INFO_USED_IN_POS_FIX) == PDSM_GNSS_SV_INFO_USED_IN_POS_FIX)
                && ((svInfoMask & PDSM_GNSS_SV_INFO_USED_IN_VEL_FIX) == PDSM_GNSS_SV_INFO_USED_IN_VEL_FIX)) {
            mTrimbleData.tMeas.atCh[iTrimbleCh].bSvUsedInFix = true;
            numSvInFix++;
        }
        else {
            mTrimbleData.tMeas.atCh[iTrimbleCh].bSvUsedInFix = false;
        }

        mTrimbleData.tMeas.atCh[iTrimbleCh].ucSNR = mMEASData.data[src].zGnss[iQcomCh].Cno * 0.1;
        mTrimbleData.tMeas.atCh[iTrimbleCh].ucCNO = mMEASData.data[src].zGnss[iQcomCh].Cno * 0.1;
        mTrimbleData.tMeas.atCh[iTrimbleCh].dblPR = (mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.zSvTime.Ms + mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.zSvTime.SubMs) * 299792.458;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltPrUnc = mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.SvTimeUncMs * 299792.458;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltDopp = mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.SvSpeed;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltDrUnc = mMEASData.data[src].zGnss[iQcomCh].zFiltMeas.SvSpeedUnc;

        mTrimbleData.tMeas.atCh[iTrimbleCh].ucQual = ((svInfoMask & PDSM_GNSS_SV_INFO_MEAS_VALID) == PDSM_GNSS_SV_INFO_MEAS_VALID) ? GNSS_MEAS_VALID : 0;

        mTrimbleData.tMeas.atCh[iTrimbleCh].ulChStatusFlag = mMEASData.data[src].zGnss[iQcomCh].MeasStatus;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltAzim = mMEASData.data[src].zGnss[iQcomCh].Azimuth * RAD2DEG;
        mTrimbleData.tMeas.atCh[iTrimbleCh].fltElev = mMEASData.data[src].zGnss[iQcomCh].Elevation * RAD2DEG;

        //LOGI("[DRMGR][GNSSDATA] GAL ch:%d,sv:%d,svId:%d",iTrimbleCh, mMEASData.data[src].zGnss[iQcomCh].Sv, svId);

        iTrimbleCh++;
    }

    int getMaxNumofsvInfo(int src){
        switch(src){
            case GNSS_MEAS_BLK_SRC_GPS:
                return N_ACTIVE_GPS_CHAN_V02;
            case GNSS_MEAS_BLK_SRC_GLO:
                return N_ACTIVE_GLO_CHAN_V02;
            case GNSS_MEAS_BLK_SRC_BDS:
                return N_ACTIVE_BDS_CHAN_V02;
            case GNSS_MEAS_BLK_SRC_GAL:
                return N_ACTIVE_GAL_CHAN_V02;
            default:
                LOGE("[DRMGR][GNSSDATA] Unknown src (%d)",src);
                break;
        }
        return 0;
    }

    uint16_t getPosSvId(int src, int iSvInfo){

        Mutex::Autolock _l(mPosFixMutex);

        switch(src){
            case GNSS_MEAS_BLK_SRC_GPS:
                return mOEMDREData.NavSvInfo.GpsSvInfo[iSvInfo].SvId;
            case GNSS_MEAS_BLK_SRC_GLO:
                return mOEMDREData.NavSvInfo.GloSvInfo[iSvInfo].SvId;
            case GNSS_MEAS_BLK_SRC_BDS:
                return mOEMDREData.NavSvInfo.BdsSvInfo[iSvInfo].SvId;
            case GNSS_MEAS_BLK_SRC_GAL:
                return mOEMDREData.NavSvInfo.GalSvInfo[iSvInfo].SvId;
            default:
                LOGE("[DRMGR][GNSSDATA] Unknown src (%d)",src);
                break;
        }
        return 0;
    }

    void getEachGNSSChannelInfo(int src, int& iTrimbleCh, uint8_t& numSvInFix){
        uint16_t measSv = 0;
        int maxNumovSvnfo = getMaxNumofsvInfo(src);

        for(int iQcomCh = 0; iQcomCh < N_ACTIVE_CHAN_V02; iQcomCh++){
            for(int iSvInfo = 0; iSvInfo < maxNumovSvnfo; iSvInfo++){

                uint16_t posSv = getPosSvId(src,iSvInfo);

                {
                    Mutex::Autolock _l(mMeasMutex);
                    measSv = mMEASData.data[src].zGnss[iQcomCh].Sv;
                }

                if((measSv == posSv) && (measSv != 0 ) && (posSv != 0) && (iTrimbleCh < NUM_CH)){

                    switch(src){
                        case GNSS_MEAS_BLK_SRC_GPS:
                            getGPSChannelInfo(src, iTrimbleCh, numSvInFix, iQcomCh, iSvInfo);
                            break;
                        case GNSS_MEAS_BLK_SRC_GLO:
                            getGLOChannelInfo(src, iTrimbleCh, numSvInFix, iQcomCh, iSvInfo);
                            break;
                        case GNSS_MEAS_BLK_SRC_BDS:
                            getBDSChannelInfo(src, iTrimbleCh, numSvInFix, iQcomCh, iSvInfo);
                            break;
                        case GNSS_MEAS_BLK_SRC_GAL:
                            getGALChannelInfo(src, iTrimbleCh, numSvInFix, iQcomCh, iSvInfo);
                            break;
                        default:
                            LOGE("[DRMGR][GNSSDATA] Unknown src (%d)",src);
                            break;
                    }
                }
            }
        }
    }


    void getGNSSChannelInfo(){

        int iTrimbleCh = 0;
        uint8_t numSvInFix = 0;

        getEachGNSSChannelInfo(GNSS_MEAS_BLK_SRC_GPS, iTrimbleCh, numSvInFix);
        getEachGNSSChannelInfo(GNSS_MEAS_BLK_SRC_GLO, iTrimbleCh, numSvInFix);
        getEachGNSSChannelInfo(GNSS_MEAS_BLK_SRC_BDS, iTrimbleCh, numSvInFix);
        getEachGNSSChannelInfo(GNSS_MEAS_BLK_SRC_GAL, iTrimbleCh, numSvInFix);

        mTrimbleData.tMeas.ucNumSvs = (iTrimbleCh > NUM_CH)? NUM_CH : iTrimbleCh;
        mTrimbleData.tFix.ucNumSvsUsed = (numSvInFix > NUM_CH)? NUM_CH : numSvInFix;

    }

    void getMEASInfo(){
        Mutex::Autolock _l(mMeasMutex);
        mTrimbleData.tMeas.ucNumSvs = mMEASData.numOfSVs;
        mTrimbleData.tMeas.ulTowMeas = mMEASData.timeTag;
        mTrimbleData.tMeas.usChOrbFlag = mMEASData.orbitDataFlag;
        mTrimbleData.tMeas.usChDataFlag = mMEASData.svStatusFlag;

        mTrimbleData.tFix.ucUtcOffset = mMEASData.utcOffset;

    }

    void getPositionInfo(){
        setFlag();

        Mutex::Autolock _l(mPosFixMutex);

        // Latitude (degrees, WGS-84)
        mTrimbleData.tFix.dblLat = mOEMDREData.LGEPositionFix.PosLla[0] * RAD2DEG;
        mTrimbleData.tMeas.adblRefPos[0] = mTrimbleData.tFix.dblLat;

        // Longitude (degrees, WGS-84)
        mTrimbleData.tFix.dblLon = mOEMDREData.LGEPositionFix.PosLla[1] * RAD2DEG;
        mTrimbleData.tMeas.adblRefPos[1] = mTrimbleData.tFix.dblLon;

        // Altitude (meters, above WGS-84 ellipsoid)
        mTrimbleData.tFix.dblAlt = mOEMDREData.LGEPositionFix.PosLla[2];
        mTrimbleData.tMeas.adblRefPos[2] = mTrimbleData.tFix.dblAlt;

        // Clock bias offset (meters)
        mTrimbleData.tFix.dblOscBias = mOEMDREData.LGEPositionFix.ClockBias;
        mTrimbleData.tMeas.adblRefPos[3] = mTrimbleData.tFix.dblOscBias;

        // Horizontal speed (m/s)
        mTrimbleData.tFix.fltHorizSpeed = sqrt((mOEMDREData.LGEPositionFix.VelEnu[0]*mOEMDREData.LGEPositionFix.VelEnu[0]) +
            (mOEMDREData.LGEPositionFix.VelEnu[1]*mOEMDREData.LGEPositionFix.VelEnu[1]));

        // Reference east velocity (m/s)
        mTrimbleData.tMeas.afltRefVel[0] = mOEMDREData.LGEPositionFix.VelEnu[0];

        // Reference north velocity (m/s)
        mTrimbleData.tMeas.afltRefVel[1] = mOEMDREData.LGEPositionFix.VelEnu[1];

        // Reference vertical up velocity (m/s)
        mTrimbleData.tMeas.afltRefVel[2] = mOEMDREData.LGEPositionFix.VelEnu[2];

        // Vertical speed (m/s)
        mTrimbleData.tFix.fltVertSpeed = mOEMDREData.LGEPositionFix.VelEnu[2];

        // Horizontal heading (degrees)
        mTrimbleData.tFix.fltHeading = mOEMDREData.LGEPositionFix.HeadingRad * RAD2DEG;

        // Clock frequency offset (m/sec)
        mTrimbleData.tFix.fltOscFreq = mOEMDREData.LGEPositionFix.ClockDriftRate;
        mTrimbleData.tMeas.afltRefVel[3] = mTrimbleData.tFix.fltOscFreq;

        // Clock frequency offset uncertainty (m/sec)
        mTrimbleData.tFix.fltOscFreqUnc = mOEMDREData.LGEPositionFix.ClockDriftRateUncMps;

        // Uncertainty in east/west direction (meters or m/s)
        mTrimbleData.tFix.tUncPos.fltEast = mOEMDREData.LGEPositionFix.PosUnc2D[1];

        // Uncertainty in north/south direction (meters or m/s)
        mTrimbleData.tFix.tUncPos.fltNorth = mOEMDREData.LGEPositionFix.PosUnc2D[0];

        // Uncertainty in vertical up/down direction (meters or m/s)
        mTrimbleData.tFix.tUncPos.fltVert = mOEMDREData.LGEPositionFix.PosUncVertical;

        // Uncertainty in east/west direction (meters or m/s)
        mTrimbleData.tFix.tUncVel.fltEast = mOEMDREData.LGEPositionFix.VuncEastNorthMps[1];

        // Uncertainty in north/south direction (meters or m/s)
        mTrimbleData.tFix.tUncVel.fltNorth = mOEMDREData.LGEPositionFix.VuncEastNorthMps[0];

        // Uncertainty in vertical up/down direction (meters or m/s)
        mTrimbleData.tFix.tUncVel.fltVert = mOEMDREData.LGEPositionFix.VuncVertMps;

        // Horizontal Dilution of Precision
        mTrimbleData.tFix.tDop.fltHDOP = mOEMDREData.LGEPositionFix.HDOP;

        // Vertical Dilution of Precision
        mTrimbleData.tFix.tDop.fltVDOP = mOEMDREData.LGEPositionFix.VDOP;

        // Three-dimensional Dilution of Precision
        mTrimbleData.tFix.tDop.fltPDOP = mOEMDREData.LGEPositionFix.PDOP;

        // Time Dilution of Precision
        mTrimbleData.tFix.tDop.fltTDOP = 1.0;

        // Number of SVs used in fix
        mTrimbleData.tFix.ucNumSvsUsed = mOEMDREData.NavSvInfo.nSVs + mOEMDREData.NavSvInfo.NumGloSvs +
            mOEMDREData.NavSvInfo.NumBdsSvs + mOEMDREData.NavSvInfo.NumGalSvs;

        uint8_t timeStatus = TIME_UNKNOWN;

        switch(mOEMDREData.LGEPositionFix.InitGpsTimeSrc){

            case PDSM_GNSS_TIME_SRC_NAV_SOLUTION:
                timeStatus = TIME_FROM_FIX;
                break;

            case PDSM_GNSS_TIME_SRC_GPS_TOW_DECODE:
            case PDSM_GNSS_TIME_SRC_TOW_CONFIRMED:
            case PDSM_GNSS_TIME_SRC_TOW_WEEK_CONFIRMED:
                timeStatus = TIME_FROM_SV;
                break;

            case PDSM_GNSS_TIME_SRC_UNKNOWN:
            case PDSM_GNSS_TIME_SRC_INVALID:
                timeStatus = TIME_UNKNOWN;
                break;

            default:
                timeStatus = TIME_FROM_RTC;
                break;
        }

        mTrimbleData.tFix.tTime.ucTStatus = timeStatus;
        mTrimbleData.tMeas.ucTowStat = timeStatus;

        // Current Time ? GPS time of week in milliseconds
        mTrimbleData.tFix.tTime.ulTowMs = mOEMDREData.LGEPositionFix.GpsTimeMs;

        // Current Time - GPS week
        mTrimbleData.tFix.tTime.usWeek = mOEMDREData.LGEPositionFix.GpsWeek;

        // Local host time tag corresponding to GPS time above
        mTrimbleData.tFix.tTime.ulTimeTick = mOEMDREData.LGEPositionFix.RefFCount;
    }

    void setFlag(){
        GnssPosFlag posFlags = {};
        NavPosFlag navPosFlags = {};
        uint8_t initGPSTimesrc = 0;

        {
            Mutex::Autolock _l(mPosFixMutex);
            initGPSTimesrc = mOEMDREData.LGEPositionFix.InitGpsTimeSrc;

            memcpy(&posFlags,  &(mOEMDREData.LGEPositionFix.PositionFlags), sizeof(uint64_t));
            memcpy((char*)&(posFlags) + sizeof(uint64_t),  &(mOEMDREData.LGEPositionFix.PositionFlags_Ext), sizeof(uint64_t));
            memcpy(&navPosFlags,  &(mOEMDREData.LGEPositionFix.SmPosFlags), sizeof(uint64_t));
        }

        setPosFixType(posFlags);
        setPosFixFlags(posFlags,navPosFlags,initGPSTimesrc);
    }

    void setPosFixType(GnssPosFlag& posFlags){
        uint8_t fixType = FIX_TYPE_NONE;

        if(posFlags.b_IsValid){
            if(posFlags.b_IsPropagated){
                fixType = FIX_TYPE_ESTIMATED;
            }else if(posFlags.b_Is3D){
               fixType = (posFlags.b_IsSbasIonoCorr) ? FIX_TYPE_DIFF_3D : FIX_TYPE_3D;
            }else{
                fixType = (posFlags.b_IsSbasIonoCorr) ? FIX_TYPE_DIFF_2D : FIX_TYPE_2D;
            }
        }
        mTrimbleData.tFix.ucFixType = fixType;
    }

    void setPosFixFlags(GnssPosFlag& posFlags,NavPosFlag& navPosFlags, uint8_t initGpsTimeSrc){

        uint32_t fixFlags = 0;

        // Fix flags.  See FIX_FLAG_XXX definitions above.
        if(posFlags.b_Is3D) {
            fixFlags |= FIX_FLAG_3D;
        }
        else {
            fixFlags |= FIX_FLAG_2D;
        }

        if(posFlags.b_IsOverDetrm) {
            fixFlags |= FIX_FLAG_OVERDETERMINED;
        }

        if(posFlags.b_IsSbasIonoCorr) {
            fixFlags |= FIX_FLAG_DIFF;
            fixFlags |= FIX_FLAG_SBAS;
        }

        if(posFlags.b_IsExternal) {
            fixFlags |= FIX_FLAG_EXT_UPDATE;
        }

        if(posFlags.b_IsVelValid) {
            fixFlags |= FIX_FLAG_VEL_FIX;
        }

        if(posFlags.b_IsPropagated) {
            fixFlags |= FIX_FLAG_PROPAGATED;
        }

        if(posFlags.b_IsKf) {
            fixFlags |= FIX_FLAG_KF;
        }

        if(posFlags.b_IsHeadingValid){
            fixFlags |= FIX_FLAG_HDG_VALID;
        }

        if(posFlags.b_IsAltConstr) {
            fixFlags |= FIX_FLAG_ALT_HOLD;
        }

        if(posFlags.b_IsStatic) {
            fixFlags |= FIX_FLAG_POS_HOLD;
        }

        if(navPosFlags.b_IsItarViolated) {
            fixFlags |= FIX_FLAG_ITAR;
        }

        if(initGpsTimeSrc == GNSSData::PDSM_GNSS_TIME_SRC_SOLVE_FOR_TIME) {
            fixFlags |= FIX_FLAG_SOLVE_FOR_TIME;
        }
        mTrimbleData.tFix.ulFixFlags = fixFlags;
    }

    void getGNSSData(npGnssFixDataType& gnssInput, GpsLocation& legacy, int32_t& usedSystem){

        {
            Mutex::Autolock _l(mUsedSystemMutex);
            usedSystem = mGNSSusedSystem;
        }

        {
            Mutex::Autolock _l(mLegacyGPSMutex);
            legacy = mLegacyGPSData;
        }


        if(checkTimeSyncIndication() == false){
            gnssInput = {};
            return;
        }

        getMEASInfo();
        getPositionInfo();
        getGNSSChannelInfo();

        gnssInput = mTrimbleData;
    }

private:
    GNSSData(const GNSSData& other) {};
    GNSSData& operator=(const GNSSData& other){ return *this;};

    mutable Mutex mMeasMutex;
    mutable Mutex mPosFixMutex;
    mutable Mutex mLegacyGPSMutex;

    mutable Mutex mUsedSystemMutex;

    int32_t mGNSSusedSystem;

    GpsLocation mLegacyGPSData;
    OemdrePositionFix mOEMDREData;
    OemdreMEAS mMEASData;

    npGnssFixDataType mTrimbleData;

    bool mIsFix;
    uint32_t mLastFixTimeMs;
};

#endif //_GNSS_DATA_H_
