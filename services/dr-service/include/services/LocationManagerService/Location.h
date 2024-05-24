/**
 * @copyright
 * Copyright (c) 2016 by LG Electronics Inc.
 * This program or software including the accompanying associated documentation
 * ("Software") is the proprietary software of LG Electronics Inc. and or its
 * licensors, and may only be used, duplicated, modified or distributed pursuant
 * to the terms and conditions of a separate written license agreement between you
 * and LG Electronics Inc. ("Authorized License"). Except as set forth in an
 * Authorized License, LG Electronics Inc. grants no license (express or implied),
 * rights to use, or waiver of any kind with respect to the Software, and LG
 * Electronics Inc. expressly reserves all rights in and to the Software and all
 * intellectual property therein. If you have no Authorized License, then you have
 * no rights to use the Software in any ways, and should immediately notify LG
 * Electronics Inc. and discontinue all use of the Software.
 *
 * @file        Location.h
 * @brief       Declaration of Location
 * @author      wooje.shim
 * @version     0.00.001 (A: major change, B: refactoring or structure change, C: minor change (ex) 1.12.133)
 */

#ifndef TIGER_SDK_LOCATION_LOCATION_H
#define TIGER_SDK_LOCATION_LOCATION_H

#undef  LOG_TAG
#define LOG_TAG "Location"

#include <cmath>
#include <fcntl.h>
#include <unistd.h>

#include <cstring>
#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdbool>
#include <binder/Parcel.h>
#include <sys/cdefs.h>
#include <sys/types.h>
//#include <unordered_map>
#include "utils/Timer.h"
#include <cutils/jstring.h>
#include "utils/external/mindroid/os/Bundle.h"
#include "utils/external/mindroid/lang/String.h"
#include "utils/external/mindroid/lang/StringWrapper.h"
#include <utils/RefBase.h>
#include <sstream>
#include <algorithm>
#include <functional>
#include <ctime>

#include "Log.h"

#ifndef BOUND_VALUE_FUNCTION_UTILITY
#define BOUND_VALUE_FUNCTION_UTILITY
template <typename T>
T BOUND_VALUE(const T value, const T min, const T max) {
    return (value < min) ? min : ((value > max) ? max : value);
}
#endif

enum PosFixType{
    POS_TYPE_NONE_FIX = 0,
    POS_TYPE_GNSS_ONLY,
    POS_TYPE_DR_ONLY,
    POS_TYPE_GNSS_DR,
    POS_TYPE_EXT_SRC,
    POS_TYPE_TSU_LOC_FIX,
    POS_TYPE_TSU_LOC_NONE,
#ifdef BMW_ICON_LOCATION
    POS_TYPE_GNSS_ONLY_3D, 
    POS_TYPE_TIME_ONLY,
#endif
    POS_TYPE_MAX,
};

enum RoadType{
    ROAD_UNKNOWN = 0,
    ROAD_HIGHWAY,
    ROAD_GENERALROAD,
    ROAD_PARKINGLOT,
    ROAD_ETC,
    ROAD_MAX
};

enum DrHeadingSource{
    YAW = 0,
    DWS,
    DRHEADING_MAX
};

enum PositionSource {
    SOURCE_INVALID = 0, ///< No position value stored, invalid data returned
    SOURCE_STORED,  ///< Offline, stored position returned
    SOURCE_LIVE,     ///< Live data returned
    SOURCE_MAX
};
enum CompassDirection {
    DIRECTION_NORTH = 0,
    DIRECTION_NORTH_EAST,
    DIRECTION_EAST,
    DIRECTION_SOUTH_EAST,
    DIRECTION_SOUTH,
    DIRECTION_SOUTH_WEST,
    DIRECTION_WEST,
    DIRECTION_NORTH_WEST,
    DIRECTION_MAX
};
enum RmmFixType {
    GPS_ONLY = 0,
    DR_WHEELSPEED_ONLY,
    DR_WHEELSPEED_GPS,
    DR_GYRO_ONLY,
    DR_GYRO_GPS,
    NO_FIX,
    FIX_TYPE_MAX
};

enum PpsModeStatus {
    INVALID = 0,
    VALID,
    PPS_STATUS_MAX
};

enum PpsMode {
    GNSS = 0,
    GNSS_SBAS,
    GNSS_RTX,
    GNSS_DR,
    GNSS_SBAS_DR,
    GNSS_RTX_DR,
    DR,
    GNSS_RTX_DR_MM,
    PPS_MODE_MAX
};

enum DrCalibrationStatus {
    NOT_CALIBRATED = 0,
    CALIBRATING,
    CALIBRATED,
    DR_CALIBRATION_MAX
};

enum SatDataState {
    NOT_DOWNLOADED = 0,
    DOWNLOADED,
    SAT_STATE_MAX
};

enum SatSystem {
    GPS_SYSTEM = 0,
    GLONASS,
    GALILEO,
    BEIDOU,
    SAT_SYSTEM_MAX
};

enum SatTrackingMode {
    NOT_TRACKED = 0,
    TRACKED,
    USED,
    SAT_TRACKING_MAX
};

typedef struct {
    std::string id;                  ///< ID
    float c_no;                      ///< C/NO
    float azimuth;                   ///< Azimuth
    float elevation;                 ///< Elevation
    SatTrackingMode tracking_mode; ///< Tracking mode
    float frequency;                 ///< Frequency
} Sat_Data_t;

typedef struct {
    SatSystem system;
    uint8_t vsat_count;
    std::vector<Sat_Data_t> vsat_data;
} Sat_Constellation_t;



typedef struct {
    int32_t sec;      // Seconds (0-59)
    int32_t min;      // Minutes (0-59)
    int32_t hour;     // Hour (0-23)
    int32_t day;      // Day of month (1-31)
    int32_t month;    // Month (1-12)
    int32_t year;     // Year (YYYY)
    int32_t tz_hour;  // TimeZone Hour (+/- 12)
    int32_t tz_min;   // TimeZone Minitue
} Timedata_t;

typedef uint32_t LocNavSolutionMask;

namespace tiger{

/**
 * A data class representing a geographic location.
 * A location can consist of a latitude, longitude, timestamp, and other information such as bearing, altitude and velocity.
 * @author
 * wooje.shim
 * @version
 * 0.00.001 (A: major change, B: refactoring or structure change, C: minor change (ex) 1.12.133)
 * @note
 * All locations generated by the LocationManager are guaranteed to have a valid latitude, longitude, and timestamp
 * both UTC time and elapsed real-time since boot), all other parameters are optional.
 */
class Location : public android::RefBase
{
public:
    /**
     * Constant used to specify formatting of a latitude or longitude
     * in the form "[+-]DDD.DDDDD where D indicates degrees.
     */
    static const int FORMAT_DEGREES = 0;

    /**
     * Constant used to specify formatting of a latitude or longitude
     * in the form "[+-]DDD:MM.MMMMM" where D indicates degrees and
     * M indicates minutes of arc (1 minute = 1/60th of a degree).
     */
    static const int FORMAT_MINUTES = 1;

    /**
     * Constant used to specify formatting of a latitude or longitude
     * in the form "DDD:MM:SS.SSSSS" where D indicates degrees, M
     * indicates minutes of arc, and S indicates seconds of arc (1
     * minute = 1/60th of a degree, 1 second = 1/3600th of a degree).
     */
    static const int FORMAT_SECONDS = 2;

    /** Number of milliseconds between January 1, 1970 and January 6, 1980
     * (3657 * 24 * 60 * 60)
     */
    static const int GPS_TO_UTC_DELTA_SECS = 315964800;

    static const int GPS_SECONDS_IN_WEEK = 604800;

    static const int SECS_TO_MSECS = 1000;

    /**
     * Construct a new Location with a named provider.
     * By default time, latitude and longitude are 0, and the location has no bearing, altitude, speed, accuracy or extras.
     * @param[in] provider (const char*) the name of the provider that generated this location
     */
    Location() : RefBase(), mProvider(""), mTime(0), mWeek(0U), mTow(0U), mppsTime(0), mElapsedRealtimeNanos(0), mLatitude(0.0), mLongitude(0.0), mPreShiftLatitude(0.0), mPreShiftLongitude(0.0), mAltitude(0.0),
                        mSpeed(0.0F), mBearing(0.0F), mAccuracy(0.0F), mHDOP(0.0F), mVDOP(0.0F), mPDOP(0.0F), mSmin(0.0F), mSmaj(0.0F), mMajaa(0.0F),
                        mDifferentialGNSSAvailable(false), mRaimProblem(false), mDeadReckoning(false), mCalibrated(false),
                        mUsedGNSSSystems(0), mFieldsMask(0x00000000U),  mPosFixType(POS_TYPE_NONE_FIX) , mRoadType(ROAD_UNKNOWN) ,mTimeData({0}),
                       mLat_delta_velocity(0), mLong_delta_velocity(0), mCollisionUTCtime(0),      mSecondary_collision_detection(0), mCompass_direction(0U),
                        mGnssPositionFixAvailable(false), mPositionSource(0U),mVelEast(0.0F), mVelNorth(0.0F), mVelUp(0.0F), mSbasStatus(0U),mElevationAngle(0),
                        mUncHmin(0.0F), mUncHmaj(0.0F), mUncAmaj(0.0F), mUncV(0.0F), mUncA(0.0F), mAltitudeMeanSeaLevel(0.0), mNavSolutionMask(0U), mEnablePositionResult(0U),
                        mVelEast_err(0.0F), mVelNorth_err(0.0F), mVelUp_err(0.0F), mGeodeticSystem(0U)
    {
        mExtras = new (std::nothrow) mindroid::Bundle();
    }

    /**
     * Construct a new Location with a named provider.
     *
     * <p>By default time, latitude and longitude are 0, and the location
     * has no bearing, altitude, speed, accuracy or extras.
     *
     * @param provider the name of the provider that generated this location
     */
    Location(const std::string& provider): RefBase(), mProvider(provider), mTime(0), mWeek(0U), mTow(0U), mppsTime(0), mElapsedRealtimeNanos(0), mLatitude(0.0), mLongitude(0.0), mPreShiftLatitude(0.0), mPreShiftLongitude(0.0), mAltitude(0.0),
                        mSpeed(0.0F), mBearing(0.0F), mAccuracy(0.0F), mHDOP(0.0F), mVDOP(0.0F), mPDOP(0.0F), mSmin(0.0F), mSmaj(0.0F), mMajaa(0.0F),
                        mDifferentialGNSSAvailable(false), mRaimProblem(false), mDeadReckoning(false), mCalibrated(false),
                        mUsedGNSSSystems(0), mFieldsMask(0x00000000U),  mPosFixType(POS_TYPE_NONE_FIX),mRoadType(ROAD_UNKNOWN) ,mTimeData({0}),
                        mLat_delta_velocity(0), mLong_delta_velocity(0), mCollisionUTCtime(0), mSecondary_collision_detection(0), mCompass_direction(0U),
                        mGnssPositionFixAvailable(false), mPositionSource(0U) ,mVelEast(0.0F), mVelNorth(0.0F), mVelUp(0.0F), mSbasStatus(0U) ,mElevationAngle(0),
                        mUncHmin(0.0F), mUncHmaj(0.0F), mUncAmaj(0.0F), mUncV(0.0F), mUncA(0.0F), mAltitudeMeanSeaLevel(0.0), mNavSolutionMask(0U), mEnablePositionResult(0U),
                        mVelEast_err(0.0F), mVelNorth_err(0.0F), mVelUp_err(0.0F), mGeodeticSystem(0U)
    {
        mExtras = new mindroid::Bundle();
    }

    /**
     * Construct a new Location object that is copied from an existing one.
     */
    Location(const tiger::Location& l)
        : RefBase()
    {
        setLocation(l);
    }


    /**
     * Construct a new Location object that is copied from an existing one.
     */
    Location(const android::sp<tiger::Location>& l)
        : RefBase()
    {
        mProvider = l->mProvider;
        mTime = l->mTime;
        mWeek = l->mWeek;
        mTow = l->mTow;
        mppsTime = l->mppsTime;
        mElapsedRealtimeNanos = l->mElapsedRealtimeNanos;
        mLatitude = l->mLatitude;
        mLongitude = l->mLongitude;
        mPreShiftLatitude = l->mPreShiftLatitude;
        mPreShiftLongitude = l->mPreShiftLongitude;
        mAltitude = l->mAltitude;
        mSpeed = l->mSpeed;
        mBearing = l->mBearing;
        mAccuracy = l->mAccuracy;
        mHDOP = l->mHDOP;
        mVDOP = l->mVDOP;
        mPDOP = l->mPDOP;
        mSmin = l->mSmin;
        mSmaj = l->mSmaj;
        mMajaa = l->mMajaa;
        mDifferentialGNSSAvailable = l->mDifferentialGNSSAvailable;
        mRaimProblem = l->mRaimProblem;
        mDeadReckoning = l->mDeadReckoning;
        mCalibrated = l->mCalibrated;
        mUsedGNSSSystems = l->mUsedGNSSSystems;
        mFieldsMask = l->mFieldsMask;
        mPosFixType = l->mPosFixType;
        mRoadType = l->mRoadType;
        mTimeData.year = l->mTimeData.year;
        mTimeData.month = l->mTimeData.month;
        mTimeData.day = l->mTimeData.day;
        mTimeData.hour = l->mTimeData.hour;
        mTimeData.min = l->mTimeData.min;
        mTimeData.sec = l->mTimeData.sec;
        mTimeData.tz_hour = l->mTimeData.tz_hour;
        mTimeData.tz_min = l->mTimeData.tz_min;
        mLat_delta_velocity = l->mLat_delta_velocity;
        mLong_delta_velocity = l->mLong_delta_velocity;
        mCollisionUTCtime = l->mCollisionUTCtime;
        mSecondary_collision_detection = l->mSecondary_collision_detection;		
        mCompass_direction = l->mCompass_direction;	
        mGnssPositionFixAvailable = l->mGnssPositionFixAvailable;	
        mPositionSource = l->mPositionSource;	
        mVelEast = l->mVelEast;	
        mVelNorth = l->mVelNorth;	
        mVelUp = l->mVelUp;	
        mSbasStatus = l->mSbasStatus;
        mElevationAngle = l->mElevationAngle;
        mUncHmin = l->mUncHmin;
        mUncHmaj = l->mUncHmaj;
        mUncAmaj = l->mUncAmaj;
        mUncV = l->mUncV;
        mUncA = l->mUncA;
        mAltitudeMeanSeaLevel = l->mAltitudeMeanSeaLevel;
        mNavSolutionMask = l->mNavSolutionMask;
        mEnablePositionResult = l->mEnablePositionResult;
        mVelEast_err = l->mVelEast_err;
        mVelNorth_err = l->mVelNorth_err;
        mVelUp_err = l->mVelUp_err;
        mGeodeticSystem = l->mGeodeticSystem;

        mExtras = l->mExtras;
    }

    /**
     * Destruct an existing Location object
     */
    virtual ~Location(){}

    /**
     * Sets the contents of the location to the values from the given location.
     */
    void setLocation(const tiger::Location& l){
        mProvider = l.mProvider;
        mTime = l.mTime;
        mWeek = l.mWeek;
        mTow = l.mTow;
        mppsTime = l.mppsTime;
        mElapsedRealtimeNanos = l.mElapsedRealtimeNanos;
        mLatitude = l.mLatitude;
        mLongitude = l.mLongitude;
        mPreShiftLatitude = l.mPreShiftLatitude;
        mPreShiftLongitude = l.mPreShiftLongitude;
        mAltitude = l.mAltitude;
        mSpeed = l.mSpeed;
        mBearing = l.mBearing;
        mAccuracy = l.mAccuracy;
        mHDOP = l.mHDOP;
        mVDOP = l.mVDOP;
        mPDOP = l.mPDOP;
        mSmin = l.mSmin;
        mSmaj = l.mSmaj;
        mMajaa = l.mMajaa;
        mDifferentialGNSSAvailable = l.mDifferentialGNSSAvailable;
        mRaimProblem = l.mRaimProblem;
        mDeadReckoning = l.mDeadReckoning;
        mCalibrated = l.mCalibrated;
        mUsedGNSSSystems = l.mUsedGNSSSystems;
        mFieldsMask = l.mFieldsMask;
        mPosFixType = l.mPosFixType;
        mRoadType = l.mRoadType;
        mTimeData.year = l.mTimeData.year;
        mTimeData.month = l.mTimeData.month;
        mTimeData.day = l.mTimeData.day;
        mTimeData.hour = l.mTimeData.hour;
        mTimeData.min = l.mTimeData.min;
        mTimeData.sec = l.mTimeData.sec;
        mTimeData.tz_hour = l.mTimeData.tz_hour;
        mTimeData.tz_min = l.mTimeData.tz_min;
        mLat_delta_velocity = l.mLat_delta_velocity;
        mLong_delta_velocity = l.mLong_delta_velocity;
        mCollisionUTCtime = l.mCollisionUTCtime;		
        mSecondary_collision_detection = l.mSecondary_collision_detection;		
        mCompass_direction = l.mCompass_direction;		
        mGnssPositionFixAvailable = l.mGnssPositionFixAvailable;
        mPositionSource = l.mPositionSource;
        mVelEast = l.mVelEast;
        mVelNorth = l.mVelNorth;
        mVelUp = l.mVelUp;
        mSbasStatus = l.mSbasStatus;
        mElevationAngle = l.mElevationAngle;
        mUncHmin = l.mUncHmin;
        mUncHmaj = l.mUncHmaj;
        mUncAmaj = l.mUncAmaj;
        mUncV = l.mUncV;
        mUncA = l.mUncA;
        mAltitudeMeanSeaLevel = l.mAltitudeMeanSeaLevel;
        mNavSolutionMask = l.mNavSolutionMask;
        mEnablePositionResult = l.mEnablePositionResult;
        mVelEast_err = l.mVelEast_err;
        mVelNorth_err = l.mVelNorth_err;
        mVelUp_err = l.mVelUp_err;
        mGeodeticSystem = l.mGeodeticSystem;

        mExtras = l.mExtras;
    }

    /**
     * Clears the contents of the location.
     */
    void reset();

    /**
     * Converts a coordinate to a String representation. The outputType
     * may be one of FORMAT_DEGREES, FORMAT_MINUTES, or FORMAT_SECONDS.
     * The coordinate must be a valid double between -180.0 and 180.0.
     * This conversion is performed in a method that is dependent on the
     * default locale, and so is not guaranteed to round-trip with
     * {@link #convert(String)}.
     *
     */
    static std::string convert(double coordinate, int outputType);

    /**
     * Converts a String in one of the formats described by
     * FORMAT_DEGREES, FORMAT_MINUTES, or FORMAT_SECONDS into a
     * double. This conversion is performed in a locale agnostic
     * method, and so is not guaranteed to round-trip with
     * {@link #convert(double, int)}.
     *
     */
     static double convert(std::string coordinate);

    /**
     * Converts a time format from utc milisec to ISO8601 Time format
     * @param Source utcMsec the UTC Time sec(milliseconds) since 1970-1-1
     * @param Target Timedata_t data struncture
     */
    static void convertUtcMSecToTime(Timedata_t& time, int64_t utcMSec)
    {
        struct tm utcTime;
        const time_t utcSec = utcMSec/1000;
        
        gmtime_r(&utcSec,&utcTime);

        time.year = static_cast<int32_t>(BOUND_VALUE<int64_t>(static_cast<int64_t>(utcTime.tm_year) + 1900, static_cast<int64_t>(INT32_MIN), static_cast<int64_t>(INT32_MAX)));
        time.month = static_cast<int32_t>(BOUND_VALUE<int64_t>(static_cast<int64_t>(utcTime.tm_mon) + 1, static_cast<int64_t>(INT32_MIN), static_cast<int64_t>(INT32_MAX)));
        time.day = utcTime.tm_mday;
        time.hour = utcTime.tm_hour;
        time.min = utcTime.tm_min;
        time.sec = utcTime.tm_sec;
    }

    /**
     * Converts a time format from ISO8601 format to utc milisec 
     * @param Timedata_t data struncture
     * @return utc time sec(milliseconds)
     */
    static int64_t convertTimeToUtcMsec(const Timedata_t& time)
    {
        struct tm utcTime;
        time_t utcSec;
        int64_t utcMsec;
 
        utcTime.tm_year = static_cast<int32_t>(BOUND_VALUE<int64_t>(static_cast<int64_t>(time.year) - 1900, static_cast<int64_t>(INT32_MIN), static_cast<int64_t>(INT32_MAX)));
        utcTime.tm_mon = static_cast<int32_t>(BOUND_VALUE<int64_t>(static_cast<int64_t>(time.month) - 1, static_cast<int64_t>(INT32_MIN), static_cast<int64_t>(INT32_MAX)));
        utcTime.tm_mday = time.day;
        utcTime.tm_hour = time.hour;
        utcTime.tm_min = time.min;
        utcTime.tm_sec = time.sec;
        utcTime.tm_isdst = -1;

        utcSec = timegm (&utcTime);
        utcMsec = (static_cast<int64_t>(utcSec)) * 1000;
        return utcMsec;
    }

    static int64_t convertUtcMsToWeek(int64_t utcMSec)
    {
        return (utcMSec/1000 - GPS_TO_UTC_DELTA_SECS)/GPS_SECONDS_IN_WEEK;
    }

    static int64_t convertUtcMsToTow(int64_t utcMSec)
    {
        return ((utcMSec/1000 - GPS_TO_UTC_DELTA_SECS)%GPS_SECONDS_IN_WEEK)*SECS_TO_MSECS;
    }
    
    /**
     * Computes the approximate distance in meters between two
     * locations, and optionally the initial and final bearings of the
     * shortest path between them.  Distance and bearing are defined using the
     * WGS84 ellipsoid.
     * @ingroup LOCMGR LOCMGR_OUT
     * <p> The computed distance is stored in results[0].  If results has length
     * 2 or greater, the initial bearing is stored in results[1]. If results has
     * length 3 or greater, the final bearing is stored in results[2].
     *
     * @param startLatitude the starting latitude
     * @param startLongitude the starting longitude
     * @param endLatitude the ending latitude
     * @param endLongitude the ending longitude
     * @param results an array of floats to hold the results
     *
     */
    static bool distanceBetween(double startLatitude, double startLongitude, double endLatitude, double endLongitude, float (&results)[3])
    {

        android::sp<BearingDistanceCache> cache = new BearingDistanceCache();
        computeDistanceAndBearing(startLatitude, startLongitude,endLatitude, endLongitude, cache);
        results[0] = cache->mDistance;
        results[1] = cache->mInitialBearing;
        results[2] = cache->mFinalBearing;
#if 0
        LOGI("distanceBetween() - Lat1 %lf, Long1 %lf, Lat2 %lf, Long2 %lf, Distance %f, InitialBearing %f, FinalBearing %f",
            startLatitude, startLongitude, endLatitude, endLongitude, results[0], results[1], results[2]);
#endif
        return true;
    }

    /**
     * Returns the approximate distance in meters between this
     * location and the given location.  Distance is defined using
     * the WGS84 ellipsoid.
     *
     * @param dest the destination location
     * @return the approximate distance in meters
     */
    float distanceTo(Location& dest);

    /**
     * Returns the approximate initial bearing in degrees East of true
     * North when traveling along the shortest path between this
     * location and the given location.  The shortest path is defined
     * using the WGS84 ellipsoid.  Locations that are (nearly)
     * antipodal may produce meaningless results.
     *
     * @param dest the destination location
     * @return the initial bearing in degrees
     */
    float bearingTo(Location& dest);

    /**
     * Returns the name of the provider that generated this fix.
     *
     * @return the provider, or null if it has not been set
     */
    std::string getProvider() const {
        return mProvider;
    }

    /**
     * Sets the name of the provider that generated this fix.
     */
    void setProvider(const std::string provider) {
        mProvider = provider;
    }

    /**
     * Return the UTC time of this fix, in milliseconds since January 1, 1970.
     *
     * <p>Note that the UTC time on a device is not monotonic: it
     * can jump forwards or backwards unpredictably. So always use
     * {@link #getElapsedRealtimeNanos} when calculating time deltas.
     *
     * <p>On the other hand, {@link #getTime} is useful for presenting
     * a human readable time to the user, or for carefully comparing
     * location fixes across reboot or across devices.
     *
     * <p>All locations generated by the {@link LocationManager}
     * are guaranteed to have a valid UTC time, however remember that
     * the system time may have changed since the location was generated.
     *
     * @return time of fix, in milliseconds since January 1, 1970.
     */
    int64_t getTime() const {
        return mTime;
    }

    /**
     * Set the UTC time of this fix, in milliseconds since January 1,
     * 1970.
     *
     * @param time UTC time of this fix, in milliseconds since January 1, 1970
     */
    void setTime(int64_t time) {
        mTime = time;
    }


    uint16_t getWeek() const {
        return mWeek;
    }

    void setWeek(uint16_t week) {
        mWeek = week;
    }

    uint32_t getTow() const {
        return mTow;
    }

    void setTow(uint32_t tow) {
        mTow = tow;
    }

    /**
    * Return the UTC time of this fix, in milliseconds since January 1, 1970.
    *
    * <p>Note that the UTC time on a device is not monotonic: it
    * can jump forwards or backwards unpredictably. So always use
    * {@link #getElapsedRealtimeNanos} when calculating time deltas.
    *
    * <p>On the other hand, {@link #getTime} is useful for presenting
    * a human readable time to the user, or for carefully comparing
    * location fixes across reboot or across devices.
    *
    * <p>All locations generated by the {@link LocationManager}
    * are guaranteed to have a valid UTC time, however remember that
    * the system time may have changed since the location was generated.
    *
    * @return time of fix, in milliseconds since January 1, 1970.
    */
    int64_t getppsTime() const {
        return mppsTime;
    }

    /**
    * Set the UTC time of this fix, in milliseconds since January 1,
    * 1970.
    *
    * @param time UTC time of this fix, in milliseconds since January 1, 1970
    */
    void setppsTime(int64_t ppstime) {
        mppsTime = ppstime;
    }

    /**
     * Return the time of this fix, in elapsed real-time since system boot.
     *
     * <p>This value can be reliably compared to
     * {@link android.os.SystemClock#elapsedRealtimeNanos},
     * to calculate the age of a fix and to compare Location fixes. This
     * is reliable because elapsed real-time is guaranteed monotonic for
     * each system boot and continues to increment even when the system
     * is in deep sleep (unlike {@link #getTime}.
     *
     * <p>All locations generated by the {@link LocationManager}
     * are guaranteed to have a valid elapsed real-time.
     *
     * @return elapsed real-time of fix, in nanoseconds since system boot.
     */
    long getElapsedRealtimeNanos() const {
        return mElapsedRealtimeNanos;
    }

    /**
     * Set the time of this fix, in elapsed real-time since system boot.
     *
     * @param time elapsed real-time of fix, in nanoseconds since system boot.
     */
    void setElapsedRealtimeNanos(long time) {
        mElapsedRealtimeNanos = time;
    }

    /**
     * Get the latitude, in degrees.
     *
     * <p>All locations generated by the {@link LocationManager}
     * will have a valid latitude.
     */
    double getLatitude() const {
        return mLatitude;
    }

    /**
     * Set the latitude, in degrees.
     */
    void setLatitude(double latitude) {
        mLatitude = latitude;
    }

    /**
     * Get the longitude, in degrees.
     *
     * <p>All locations generated by the {@link LocationManager}
     * will have a valid longitude.
     */
    double getLongitude() const {
        return mLongitude;
    }

    /**
     * Set the longitude, in degrees.
     */
    void setLongitude(double longitude) {
        mLongitude = longitude;
    }

    double getPreShiftLatitude() const {
        return mPreShiftLatitude;
    }

    void setPreShiftLatitude(double preShiftLatitude) {
        mPreShiftLatitude = preShiftLatitude;
    }

    double getPreShiftLongitude() const {
        return mPreShiftLongitude;
    }

    void setPreShiftLongitude(double preShiftLongitude) {
        mPreShiftLongitude = preShiftLongitude;
    }

    /**
     * True if this location has an altitude.
     */
    bool hasAltitude() const{
        return (mFieldsMask & HAS_ALTITUDE_MASK) != 0U;
    }

    /**
     * Get the altitude if available, in meters above the WGS 84 reference
     * ellipsoid.
     *
     * <p>If this location does not have an altitude then 0.0 is returned.
     */
    double getAltitude() const {
        return mAltitude;
    }

    /**
     * Set the altitude, in meters above the WGS 84 reference ellipsoid.
     *
     * <p>Following this call {@link #hasAltitude} will return true.
     */
    void setAltitude(double altitude) {
        mAltitude = altitude;
        mFieldsMask |= HAS_ALTITUDE_MASK;
    }

    /**
     * Remove the altitude from this location.
     *
     * <p>Following this call {@link #hasAltitude} will return false,
     * and {@link #getAltitude} will return 0.0.
     */
    void removeAltitude() {
        mAltitude = 0.0F;
        mFieldsMask &= ~HAS_ALTITUDE_MASK;
    }

    /**
     * True if this location has a speed.
     */
    bool hasSpeed() const {
        return (mFieldsMask & HAS_SPEED_MASK) != 0U;
    }

    /**
     * Get the speed if it is available, in meters/second over ground.
     *
     * <p>If this location does not have a speed then 0.0 is returned.
     */
    float getSpeed() const{
        return mSpeed;
    }

    /**
     * Set the speed, in meters/second over ground.
     *
     * <p>Following this call {@link #hasSpeed} will return true.
     */
    void setSpeed(float speed) {
        mSpeed = speed;
        mFieldsMask |= HAS_SPEED_MASK;
    }

    /**
     * Remove the speed from this location.
     *
     * <p>Following this call {@link #hasSpeed} will return false,
     * and {@link #getSpeed} will return 0.0.
     */
    void removeSpeed() {
        mSpeed = 0.0F;
        mFieldsMask &= ~HAS_SPEED_MASK;
    }

    /**
     * True if this location has a bearing.
     */
    bool hasBearing() const{
        return (mFieldsMask & HAS_BEARING_MASK) != 0U;
    }

    /**
     * Get the bearing, in degrees.
     *
     * <p>Bearing is the horizontal direction of travel of this device,
     * and is not related to the device orientation. It is guaranteed to
     * be in the range (0.0, 360.0] if the device has a bearing.
     *
     * <p>If this location does not have a bearing then 0.0 is returned.
     */
    float getBearing() const{
        return mBearing;
    }

    /**
     * Set the bearing, in degrees.
     *
     * <p>Bearing is the horizontal direction of travel of this device,
     * and is not related to the device orientation.
     *
     * <p>The input will be wrapped into the range (0.0, 360.0].
     */
    void setBearing(float bearing) {
        while (bearing < 0.0F) {
            bearing += 360.0F;
        }
        while (bearing >= 360.0F) {
            bearing -= 360.0F;
        }
        mBearing = bearing;
        mFieldsMask |= HAS_BEARING_MASK;
    }

    /**
     * Remove the bearing from this location.
     *
     * <p>Following this call {@link #hasBearing} will return false,
     * and {@link #getBearing} will return 0.0.
     */
    void removeBearing() {
        mBearing = 0.0F;
        mFieldsMask &= ~HAS_BEARING_MASK;
    }

    /**
     * True if this location has an accuracy.
     *
     * <p>All locations generated by the {@link LocationManager} have an
     * accuracy.
     */
    bool hasAccuracy() const{
        return (mFieldsMask & HAS_ACCURACY_MASK) != 0U;
    }

    /**
     * Get the estimated accuracy of this location, in meters.
     *
     * <p>We define accuracy as the radius of 68% confidence. In other
     * words, if you draw a circle centered at this location's
     * latitude and longitude, and with a radius equal to the accuracy,
     * then there is a 68% probability that the true location is inside
     * the circle.
     *
     * <p>In statistical terms, it is assumed that location errors
     * are random with a normal distribution, so the 68% confidence circle
     * represents one standard deviation. Note that in practice, location
     * errors do not always follow such a simple distribution.
     *
     * <p>This accuracy estimation is only concerned with horizontal
     * accuracy, and does not indicate the accuracy of bearing,
     * velocity or altitude if those are included in this Location.
     *
     * <p>If this location does not have an accuracy, then 0.0 is returned.
     * All locations generated by the {@link LocationManager} include
     * an accuracy.
     */
    float getAccuracy() const{
        return mAccuracy;
    }

    /**
     * Set the estimated accuracy of this location, meters.
     *
     * <p>See {@link #getAccuracy} for the definition of accuracy.
     *
     * <p>Following this call {@link #hasAccuracy} will return true.
     */
    void setAccuracy(float accuracy) {
        mAccuracy = accuracy;
        mFieldsMask |= HAS_ACCURACY_MASK;
    }

    /**
     * Remove the accuracy from this location.
     *
     * <p>Following this call {@link #hasAccuracy} will return false, and
     * {@link #getAccuracy} will return 0.0.
     */
    void removeAccuracy() {
        mAccuracy = 0.0F;
        mFieldsMask &= ~HAS_ACCURACY_MASK;
    }

    bool hasHDOP() const{
        return (mFieldsMask & HAS_HDOP_MASK) != 0U;
    }

    float getHDOP() const{
        return mHDOP;
    }

    void setHDOP(float hdop) {
        mHDOP = hdop;
        mFieldsMask |= HAS_HDOP_MASK;
    }

    void removeHDOP() {
        mHDOP = 0.0F;
        mFieldsMask &= ~HAS_HDOP_MASK;
    }

    float getVDOP() const{
        return mVDOP;
    }

    void setVDOP(float vdop) {
        mVDOP = vdop;
        mFieldsMask |= HAS_VDOP_MASK;
    }

    void removeVDOP() {
        mVDOP = 0.0F;
        mFieldsMask &= ~HAS_VDOP_MASK;
    }

    bool hasPDOP() const{
        return (mFieldsMask & HAS_PDOP_MASK) != 0U;
    }

    float getPDOP() const{
        return mPDOP;
    }

    void setPDOP(float pdop) {
        mPDOP = pdop;
        mFieldsMask |= HAS_PDOP_MASK;
    }

    void removePDOP() {
        mPDOP = 0.0F;
        mFieldsMask &= ~HAS_PDOP_MASK;
    }

    bool hasSMIN() const{
        return (mFieldsMask & HAS_SMIN_MASK) != 0U;
    }

    float getSMIN() const{
        return mSmin;
    }

    void setSMIN(float smin) {
        mSmin = smin;
        mFieldsMask |= HAS_SMIN_MASK;
    }

    void removeSIM() {
        mSmin= 0.0F;
        mFieldsMask &= ~HAS_SMIN_MASK;
    }

    bool hasSMAJ() const{
        return (mFieldsMask & HAS_SMAJ_MASK) != 0U;
    }

    float getSMAJ() const{
        return mSmaj;
    }

    void setSMAJ(float smaj) {
        mSmaj = smaj;
        mFieldsMask |= HAS_SMAJ_MASK;
    }

    void removeSMAJ() {
        mSmaj = 0.0F;
        mFieldsMask &= ~HAS_SMAJ_MASK;
    }

    bool hasMAJAA() const{
        return (mFieldsMask & HAS_MAJAA_MASK) != 0U;
    }

    float getMAJAA() const{
        return mMajaa;
    }

    void setMAJAA(float majaa) {
        mMajaa = majaa;
        mFieldsMask |= HAS_MAJAA_MASK;
    }

    void removeMAJAA() {
        mMajaa = 0.0F;
        mFieldsMask &= ~HAS_MAJAA_MASK;
    }

    bool hasDGPS() const{
        return (mFieldsMask & HAS_DGPS_MASK) != 0U;
    }

    bool getDGPS() const{
        return mDifferentialGNSSAvailable;
    }

    void setDGPS(bool pValue) {
        mDifferentialGNSSAvailable = pValue;
        mFieldsMask |= HAS_DGPS_MASK;
    }

    void removeDGPS() {
        mDifferentialGNSSAvailable = false;
        mFieldsMask &= ~HAS_DGPS_MASK;
    }

    bool hasRaimProblem() const{
        return (mFieldsMask & HAS_RAIM_PROBLEM_MASK) != 0U;
    }

    bool getRaimProblem() const{
        return mRaimProblem;
    }

    void setRaimProblem(bool pValue) {
        mRaimProblem = pValue;
        mFieldsMask |= HAS_RAIM_PROBLEM_MASK;
    }

    void removeRaimProblem() {
        mRaimProblem = false;
        mFieldsMask &= ~HAS_RAIM_PROBLEM_MASK;
    }

    bool getDRInfo() const{
        return mDeadReckoning;
    }

    void setDRInfo(bool pValue) {
        mDeadReckoning = pValue;
        mFieldsMask |= HAS_DR_FIX_INFO_MASK;
    }

    void removeDRInfo() {
        mDeadReckoning = false;
        mFieldsMask &= ~HAS_DR_FIX_INFO_MASK;
    }
    bool hasDRCal() const{
        return (mFieldsMask & HAS_DR_CAL_MASK) != 0U;
    }

    bool getDRCal() const{
        return mCalibrated;
    }

    void setDRCal(bool pValue) {
        mCalibrated = pValue;
        mFieldsMask |= HAS_DR_CAL_MASK;
    }

    void removeDRCal() {
        mCalibrated = false;
        mFieldsMask &= ~HAS_DR_CAL_MASK;
    }

    bool hasUsedGNSSSystems() const{
        return (mFieldsMask & HAS_GNSSSYSTEM_MASK) != 0U;
    }

    int32_t getUsedGNSSSystems() const{
        return mUsedGNSSSystems;
    }

    void setUsedGNSSSystems(int32_t GNSSSystems) {
        mUsedGNSSSystems = GNSSSystems;
        mFieldsMask |= HAS_GNSSSYSTEM_MASK;
    }

    void removeUsedGNSSSystems() {
        mUsedGNSSSystems = 0;
        mFieldsMask &= ~HAS_GNSSSYSTEM_MASK;
    }

    uint32_t getFieldsMask()const {
        return mFieldsMask;
    }

    void setPositionFixType(const PosFixType& type){
        mPosFixType = type;
    }

    PosFixType getPositionFixType() const{
        return mPosFixType;
    }

    void setRoadType(RoadType roadType){
        mRoadType = roadType;
    }

    RoadType getRoadType() const{
        return mRoadType;
    }

    void setTimeData(Timedata_t timeData){
        mTimeData.year = timeData.year;
        mTimeData.month = timeData.month;
        mTimeData.day = timeData.day;
        mTimeData.hour = timeData.hour;
        mTimeData.min = timeData.min;
        mTimeData.sec = timeData.sec;
        mTimeData.tz_hour = timeData.tz_hour;
        mTimeData.tz_min = timeData.tz_min;
    }

    Timedata_t getTimeData() const{
        return mTimeData;
    }

    int32_t getSecondaryCollisionDetection() const {
        return mSecondary_collision_detection;
    }

    void setSecondaryCollisionDetection(int32_t secondary_collision_detection) {
        mSecondary_collision_detection = secondary_collision_detection;
    }

    uint8_t getCompassDirection() const {
        return mCompass_direction;
    }

    void setCompassDirection(uint8_t compass_direction) {
        mCompass_direction = compass_direction;
    }

    bool getPositionFixAvailable() const {
        return mGnssPositionFixAvailable;
    }

    void setPositionFixAvailable(bool gnss_posfix_avai) {
        mGnssPositionFixAvailable = gnss_posfix_avai;
    }

    uint8_t getPositionSource() const {
        return mPositionSource;
    }

    void setPositionSource(uint8_t pos_source) {
        mPositionSource = pos_source;
    }

    int8_t getLatDeltaVelocity() const {
        return mLat_delta_velocity;
    }

    void setLatDeltaVelocity(int8_t lat_delta_velocity) {
        mLat_delta_velocity = lat_delta_velocity;
    }

    int8_t getLongDeltaVelocity() const {
        return mLong_delta_velocity;
    }

    void setLongDeltaVelocity(int8_t long_delta_velocity) {
        mLong_delta_velocity = long_delta_velocity;
    }

    time_t getCollisionUTCtime() const {
        return mCollisionUTCtime;
    }

    void setCollisionUTCtime(time_t timestamp) {
        mCollisionUTCtime = timestamp;
    }
    float getVelocityEast() const {
        return mVelEast;
    }

    void setVelocityEast(float velocityEast) {
        mVelEast = velocityEast;
    }

    float getVelocityNorth() const {
        return mVelNorth;
    }

    void setVelocityNorth(float velocityNorth) {
        mVelNorth = velocityNorth;
    }

    float getVelocityUp() const {
        return mVelUp;
    }

    void setVelocityUp(float velocityUp) {
        mVelUp = velocityUp;
    }

    uint8_t getSbasStatus() const {
        return mSbasStatus;
    }

    void setSbasStatus(bool sbasStatus) {
        mSbasStatus = sbasStatus;
    }

    int getElevationAngle( ) const {
        return mElevationAngle;
    }

    void setElevationAngle(int angle) {
        mElevationAngle = angle;
    }

    float getUncHmin( ) const {
        return mUncHmin;
    }

    void setUncHmin(float Velocity_unc_horizontal_minor) {
        mUncHmin  = Velocity_unc_horizontal_minor;
    }

    float getUncHmaj( ) const {
        return mUncHmaj;
    }

    void setUncHmaj(float Velocity_unc_horizontal_major) {
        mUncHmaj  = Velocity_unc_horizontal_major;
    }

    float getUncAmaj( ) const {
        return mUncAmaj;
    }

    void setUncAmaj(float Velocity_unc_azimuth_major) {
        mUncAmaj  = Velocity_unc_azimuth_major;
    }
    
    float getUncV( ) const {
        return mUncV;
    }

    void setUncV(float Velocity_unc_vertical) {
        mUncV  = Velocity_unc_vertical;
    }

    float getUncA( ) const {
        return mUncA;
    }

    void setUncA(float vert_unc) {
        mUncA  = vert_unc;
    }

    double getAltitudeMeanSeaLevel( ) const {
        return mAltitudeMeanSeaLevel;
    }

    void setAltitudeMeanSeaLevel(double altitudeMeanSeaLevel) {
        mAltitudeMeanSeaLevel  = altitudeMeanSeaLevel;
    }

    LocNavSolutionMask getNavSolutionMask( ) const {
        return mNavSolutionMask;
    }

    void setNavSolutionMask(LocNavSolutionMask navSolutionMask) {
        mNavSolutionMask  = navSolutionMask;
    }

    void setEnablePositionResult(uint8_t uEnable) {
        mEnablePositionResult = uEnable;
    }

    uint8_t getEnablePositionResult() const {
        return mEnablePositionResult;
    }

    float getVelocityEastErr() const {
        return mVelEast_err;
    }

    void setVelocityEastErr(float velocityEast_err) {
        mVelEast_err = velocityEast_err;
    }

    float getVelocityNorthErr() const {
        return mVelNorth_err;
    }

    void setVelocityNorthErr(float velocityNorth_err) {
        mVelNorth_err = velocityNorth_err;
    }

    float getVelocityUpErr() const {
        return mVelUp_err;
    }

    void setVelocityUpErr(float velocityUp_err) {
        mVelUp_err = velocityUp_err;
    }
    void setGeodeticSystem(uint8_t geodetic){
        mGeodeticSystem = geodetic;
    }
    uint8_t getGeodeticSystem() const {
        return mGeodeticSystem;
    }
    android::sp<mindroid::Bundle> getExtras() {
        return mExtras;
    }

    void writeToParcel(android::Parcel* parcel) {
        if (parcel == nullptr)
        {
            return;
        }

        parcel->writeCString(mProvider.c_str());
        parcel->writeInt64(mTime);
        parcel->writeUint32(static_cast<uint32_t>(mWeek));
        parcel->writeUint32(mTow);
        parcel->writeInt64(mppsTime);
        parcel->writeInt64(mElapsedRealtimeNanos);
        parcel->writeDouble(mLatitude);
        parcel->writeDouble(mLongitude);
        parcel->writeDouble(mPreShiftLatitude);
        parcel->writeDouble(mPreShiftLongitude);
        parcel->writeDouble(mAltitude);
        parcel->writeFloat(mSpeed);
        parcel->writeFloat(mBearing);
        parcel->writeFloat(mAccuracy);
        parcel->writeFloat(mHDOP);
        parcel->writeFloat(mVDOP);
        parcel->writeFloat(mPDOP);
        parcel->writeFloat(mSmin);
        parcel->writeFloat(mSmaj);
        parcel->writeFloat(mMajaa);
        parcel->writeInt32(static_cast<int32_t>(mDifferentialGNSSAvailable ? 1 : 0));
        parcel->writeInt32(static_cast<int32_t>(mRaimProblem ? 1 : 0));
        parcel->writeInt32(static_cast<int32_t>(mDeadReckoning ? 1 : 0));
        parcel->writeInt32(static_cast<int32_t>(mCalibrated ? 1 : 0));
        parcel->writeInt32(mUsedGNSSSystems);
        parcel->writeUint32(mFieldsMask);
        parcel->writeInt32(static_cast<int32_t>(mPosFixType));
        parcel->writeInt32(static_cast<int32_t>(mRoadType));
        parcel->writeInt32(mTimeData.year);
        parcel->writeInt32(mTimeData.month);
        parcel->writeInt32(mTimeData.day);
        parcel->writeInt32(mTimeData.hour);
        parcel->writeInt32(mTimeData.min);
        parcel->writeInt32(mTimeData.sec);
        parcel->writeInt32(mTimeData.tz_hour);
        parcel->writeInt32(mTimeData.tz_min);
        parcel->writeInt32(static_cast<int32_t>(mLat_delta_velocity));
        parcel->writeInt32(static_cast<int32_t>(mLong_delta_velocity));
        parcel->writeInt64(mCollisionUTCtime);		
        parcel->writeInt32(mSecondary_collision_detection);		
        parcel->writeUint32(static_cast<uint32_t>(mCompass_direction));		
        parcel->writeInt32(static_cast<int32_t>((mGnssPositionFixAvailable ? 1 : 0)));		
        parcel->writeUint32(static_cast<uint32_t>(mPositionSource));		
        parcel->writeFloat(mVelEast);
        parcel->writeFloat(mVelNorth);
        parcel->writeFloat(mVelUp);
        parcel->writeUint32(static_cast<uint32_t>(mSbasStatus));
        parcel->writeInt32(mElevationAngle);
        parcel->writeFloat(mUncHmin);
        parcel->writeFloat(mUncHmaj);
        parcel->writeFloat(mUncAmaj);
        parcel->writeFloat(mUncV);
        parcel->writeFloat(mUncA);
        parcel->writeDouble(mAltitudeMeanSeaLevel);
        parcel->writeUint32(static_cast<uint32_t>(mNavSolutionMask));
        parcel->writeUint32(static_cast<uint32_t>(mEnablePositionResult));
        parcel->writeFloat(mVelEast_err);
        parcel->writeFloat(mVelNorth_err);
        parcel->writeFloat(mVelUp_err);
        parcel->writeUint32(static_cast<uint32_t>(mGeodeticSystem));
        // TODO: Bundle To Parcel
    }

    void readFromParcel(const android::Parcel& parcel) {
        android::sp<mindroid::String> temp = new (std::nothrow) mindroid::String(parcel.readCString());
        mProvider.clear();
        if (temp != nullptr)
        {
            mProvider.append(temp->c_str());
        }
        else
        {
            mProvider.append("\0");
        }
        mTime = parcel.readInt64();
        mWeek = static_cast<uint16_t>(BOUND_VALUE<uint32_t>(parcel.readUint32(), static_cast<uint32_t>(0U), static_cast<uint32_t>(UINT16_MAX)));
        mTow = parcel.readUint32();
        mppsTime = parcel.readInt64();
        mElapsedRealtimeNanos = parcel.readInt64();
        mLatitude = parcel.readDouble();
        mLongitude = parcel.readDouble();
        mPreShiftLatitude = parcel.readDouble();
        mPreShiftLongitude = parcel.readDouble();
        mAltitude = parcel.readDouble();
        mSpeed = parcel.readFloat();
        mBearing = parcel.readFloat();
        mAccuracy = parcel.readFloat();
        mHDOP = parcel.readFloat();
        mVDOP = parcel.readFloat();
        mPDOP = parcel.readFloat();
        mSmin = parcel.readFloat();
        mSmaj = parcel.readFloat();
        mMajaa = parcel.readFloat();
        mDifferentialGNSSAvailable = static_cast<bool>(parcel.readInt32() != 0);
        mRaimProblem = static_cast<bool>(parcel.readInt32() != 0);
        mDeadReckoning = static_cast<bool>(parcel.readInt32() != 0);
        mCalibrated = static_cast<bool>(parcel.readInt32() != 0);
        mUsedGNSSSystems = parcel.readInt32();
        mFieldsMask = parcel.readUint32();
        mPosFixType = static_cast<PosFixType>(parcel.readInt32());
        mRoadType = static_cast<RoadType>(parcel.readInt32());
        mTimeData.year = parcel.readInt32();
        mTimeData.month = parcel.readInt32();
        mTimeData.day = parcel.readInt32();
        mTimeData.hour = parcel.readInt32();
        mTimeData.min = parcel.readInt32();
        mTimeData.sec = parcel.readInt32();
        mTimeData.tz_hour = parcel.readInt32();
        mTimeData.tz_min = parcel.readInt32();
        mLat_delta_velocity = static_cast<int8_t>(BOUND_VALUE<int>(parcel.readInt32(), INT8_MIN, INT8_MAX));
        mLong_delta_velocity = static_cast<int8_t>(BOUND_VALUE<int>(parcel.readInt32(), INT8_MIN, INT8_MAX));
        mCollisionUTCtime = parcel.readInt64();
        mSecondary_collision_detection = parcel.readInt32();
        mCompass_direction = static_cast<uint8_t>(BOUND_VALUE<uint32_t>(parcel.readUint32(), static_cast<uint32_t>(0U), static_cast<uint32_t>(UINT8_MAX))) ;
        mGnssPositionFixAvailable = static_cast<bool>(parcel.readInt32() != 0) ;
        mPositionSource = static_cast<uint8_t>(BOUND_VALUE<uint32_t>(parcel.readUint32(), static_cast<uint32_t>(0U), static_cast<uint32_t>(UINT8_MAX))) ;
        mVelEast = parcel.readFloat() ;
        mVelNorth = parcel.readFloat() ;
        mVelUp = parcel.readFloat() ;
        mSbasStatus = static_cast<uint8_t>(BOUND_VALUE<uint32_t>(parcel.readUint32(), static_cast<uint32_t>(0U), static_cast<uint32_t>(UINT8_MAX)));
        mElevationAngle = parcel.readInt32();
        mUncHmin = parcel.readFloat();
        mUncHmaj = parcel.readFloat();
        mUncAmaj = parcel.readFloat();
        mUncV = parcel.readFloat();
        mUncA = parcel.readFloat();
        mAltitudeMeanSeaLevel = parcel.readDouble();
        mNavSolutionMask = static_cast<LocNavSolutionMask>(parcel.readUint32());
        mEnablePositionResult = static_cast<uint8_t>(BOUND_VALUE<uint32_t>(parcel.readUint32(), static_cast<uint32_t>(0U), static_cast<uint32_t>(UINT8_MAX)));
        mVelEast_err = parcel.readFloat() ;
        mVelNorth_err = parcel.readFloat() ;
        mVelUp_err = parcel.readFloat() ;
        mGeodeticSystem = static_cast<uint8_t>(BOUND_VALUE<uint32_t>(parcel.readUint32(), static_cast<uint32_t>(0U), static_cast<uint32_t>(UINT8_MAX)));
        // TODO: Parcel To Bundle
    }

    android::sp<mindroid::String> toString() {
        mindroid::StringWrapper s("{");
        s.append(", mProvider=").append(mProvider.c_str());
#if __WORDSIZE == 64
        s.appendFormatted(", mTime=%ld", mTime);
#else
        s.appendFormatted(", mTime=%lld", mTime);
#endif
        s.appendFormatted(", mWeek=%d", mWeek);
        s.appendFormatted(", mTow=%d", mTow);
#if __WORDSIZE == 64
        s.appendFormatted(", mppsTime=%ld", mppsTime);
#else
        s.appendFormatted(", mppsTime=%lld", mppsTime);
#endif
        s.appendFormatted(", mElapsedRealtimeNanos=%ld", mElapsedRealtimeNanos);
        s.appendFormatted(", mLatitude=%lf", mLatitude);
        s.appendFormatted(", mLongitude=%lf", mLongitude);
        s.appendFormatted(", mAltitude=%lf", mAltitude);
        s.appendFormatted(", mSpeed=%f", mSpeed);
        s.appendFormatted(", mBearing=%f", mBearing);
        s.appendFormatted(", mAccuracy=%f", mAccuracy);
        s.appendFormatted(", mHDOP=%f", mHDOP);
        s.appendFormatted(", mVDOP=%f", mVDOP);
        s.appendFormatted(", mPDOP=%f", mPDOP);
        s.appendFormatted(", mSmin=%f", mSmin);
        s.appendFormatted(", mSmaj=%f", mSmaj);
        s.appendFormatted(", mMajaa=%f", mMajaa);
        s.appendFormatted(", mDGPS=%d", mDifferentialGNSSAvailable);
        s.appendFormatted(", mRAIM=%d", mRaimProblem);
        s.appendFormatted(", mDRinfo=%d", mDeadReckoning);
        s.appendFormatted(", mDRcal=%d", mCalibrated);
        s.appendFormatted(", mUsedGNSSSystems=%d", mUsedGNSSSystems);
        s.appendFormatted(", mFieldsMask=0x%08X", mFieldsMask);
        s.appendFormatted(", mPosFixType=%d", mPosFixType);
        s.appendFormatted(", mLat_delta_velocity=%d", mLat_delta_velocity);
        s.appendFormatted(", mLong_delta_velocity=%d", mLong_delta_velocity);
#if __WORDSIZE == 64
        s.appendFormatted(", mTimestamp=%ld", mCollisionUTCtime);
#else
        s.appendFormatted(", mTimestamp=%lld", mCollisionUTCtime);
#endif
        s.appendFormatted(", mSecondary_collision_detection=%d", mSecondary_collision_detection);		
        s.appendFormatted(", mCompass_direction=%d", mCompass_direction);		
        s.appendFormatted(", mGnssPositionFixAvailable=%d", mGnssPositionFixAvailable);		
        s.appendFormatted(", mPositionSource=%d", mPositionSource);
        s.appendFormatted(", mVelEast=%f", mVelEast);
        s.appendFormatted(", mVelNorth=%f", mVelNorth);
        s.appendFormatted(", mVelUp=%f", mVelUp);
        s.appendFormatted(", mSbasStatus=%d", mSbasStatus);
        s.appendFormatted(", mElevationAngle=%d", mElevationAngle);
        s.appendFormatted(", mUncHmin=%f", mUncHmin);
        s.appendFormatted(", mUncHmaj=%f", mUncHmaj);
        s.appendFormatted(", mUncAmaj;=%f", mUncAmaj);
        s.appendFormatted(", mUncV=%f", mUncV);
        s.appendFormatted(", mUncA=%f", mUncA);
        s.appendFormatted(", mAltitudeMeanSeaLevel=%lf", mAltitudeMeanSeaLevel);
        s.appendFormatted(", mNavSolutionMask=%d", mNavSolutionMask);
        s.appendFormatted(", mEnablePositionResult=%d", mEnablePositionResult);
        s.appendFormatted(", mVelEast_err=%f", mVelEast_err);
        s.appendFormatted(", mVelNorth_err=%f", mVelNorth_err);
        s.appendFormatted(", mVelUp_err=%f", mVelUp_err);
        s.appendFormatted(", mGeodeticSystem=%d", mGeodeticSystem);
        s.append("}");
        return new mindroid::String(s.c_str());
    }

private:
    /*
     * Bit mask for mFieldsMask indicating the presence of mAltitude.
     */
    static const uint32_t HAS_ALTITUDE_MASK      = 0x00000001U;
    /**
     * Bit mask for mFieldsMask indicating the presence of mSpeed.
     */
    static const uint32_t HAS_SPEED_MASK         = 0x00000002U;
    /**
     * Bit mask for mFieldsMask indicating the presence of mBearing.
     */
    static const uint32_t HAS_BEARING_MASK       = 0x00000004U;
    /**
     * Bit mask for mFieldsMask indicating the presence of mAccuracy.
     */
    static const uint32_t HAS_ACCURACY_MASK      = 0x00000008U;
    /**
     * Bit mask for mFieldsMask indicating the presence of HDOP.
     */
    static const uint32_t HAS_HDOP_MASK          = 0x00000010U;
    /**
     * Bit mask for mFieldsMask indicating the presence of SMIN.
     */
    static const uint32_t HAS_SMIN_MASK          = 0x00000020U;
    /**
     * Bit mask for mFieldsMask indicating the presence of SMAJ.
     */
    static const uint32_t HAS_SMAJ_MASK          = 0x00000040U;
    /**
     * Bit mask for mFieldsMask indicating the presence of MAJAA.
     */
    static const uint32_t HAS_MAJAA_MASK         = 0x00000080U;
    /**
     * Bit mask for mFieldsMask indicating the presence of DGPS
     */
    static const uint32_t HAS_DGPS_MASK          = 0x00000100U;
    /**
     * Bit mask for mFieldsMask indicating the presence of RAIM PROBLEM.
     */
    static const uint32_t HAS_RAIM_PROBLEM_MASK  = 0x00000200U;
    /**
     * Bit mask for mFieldsMask indicating the presence of DR INFO.
     */
    static const uint32_t HAS_DR_FIX_INFO_MASK       = 0x00000400U;
    /**
     * Bit mask for mFieldsMask indicating the presence of DR CAL.
     */
    static const uint32_t HAS_DR_CAL_MASK        = 0x00000800U;
    /**
     * Bit mask for mFieldsMask indicating the presence of VDOP.
     */
    static const uint32_t HAS_VDOP_MASK          = 0x00001000U;
    /**
     * Bit mask for mFieldsMask indicating the presence of PDOP.
     */
    static const uint32_t HAS_PDOP_MASK          = 0x00002000U;
    /**
    * Bit mask for mFieldsMask indicating the presence of GNSSSYSTEM_MASK.
    */
    static const uint32_t HAS_GNSSSYSTEM_MASK          = 0x00004000U;
    /**
     * Bit mask for mFieldsMask indicating location is from a mock provider.
     */
    static const uint32_t HAS_MOCK_PROVIDER_MASK = 0xFFFFFFFFU;

    std::string mProvider;
    int64_t mTime;
    uint16_t mWeek;
    uint32_t mTow;
    int64_t mppsTime;
    long mElapsedRealtimeNanos;
    double mLatitude;
    double mLongitude;
    double mPreShiftLatitude;
    double mPreShiftLongitude;
    double mAltitude;
    float mSpeed;
    float mBearing;
    float mAccuracy;
    // EXTEND VALUE - S
    /** Horizontal Dilution of Precision for the location fix. */
    float mHDOP;
    float mVDOP;
    float mPDOP;
    /** Semi-minor axis of horizontal elliptical uncertainty.
     *  Units: Meters */
    float mSmin;
    /** Semi-major axis of horizontal elliptical uncertainty.
     *  Units: Meters */
    float mSmaj;
    /** Elliptical horizontal uncertainty azimuth of orientation.
     *  Units: Decimal degrees
     *  Range: 0 to 180 */
    float mMajaa;

    bool mDifferentialGNSSAvailable;
    bool mRaimProblem;
    bool mDeadReckoning;
    bool mCalibrated;
    int32_t mUsedGNSSSystems;

    uint32_t mFieldsMask;

    PosFixType mPosFixType;
    RoadType mRoadType;
    Timedata_t mTimeData;

    int8_t mLat_delta_velocity;
    int8_t mLong_delta_velocity;
    time_t mCollisionUTCtime;
    int32_t mSecondary_collision_detection;
    uint8_t mCompass_direction;
    bool mGnssPositionFixAvailable;
    uint8_t mPositionSource;
    float mVelEast;
    float mVelNorth;
    float mVelUp;
    uint8_t mSbasStatus;
    int mElevationAngle;

    //Toyota 24DCM GNSS Data Flame
    /** Speed error (1¥ò)  [horizontal plane, minor axis direction]
     *  Units: meter per sec */
    float mUncHmin;
    /** Speed error (1¥ò)  [horizontal plane, major axis direction]
     *  Units: meter per sec */
    float mUncHmaj;
    /** Speed error [azimuth of major axis]
     *  Units: degree */
    float mUncAmaj;
    /** Speed error (1¥ò) [vertical direction]
     *  Units: meter per sec */
    float mUncV;
    float mUncA; //vertical uncertainty in meters
    double mAltitudeMeanSeaLevel; //Altitude wrt mean sea level
    LocNavSolutionMask  mNavSolutionMask; //Nav solution mask to indicate sbas corrections
    uint8_t mEnablePositionResult;

    float mVelEast_err;
    float mVelNorth_err;
    float mVelUp_err;
    uint8_t mGeodeticSystem;
    // EXTEND VALUE - E
    android::sp<mindroid::Bundle> mExtras;

    static bool DEBUG;

public:
    class BearingDistanceCache  : public android::RefBase
    {
    public:
        double mLat1;
        double mLon1;
        double mLat2;
        double mLon2;
        float mDistance;
        float mInitialBearing;
        float mFinalBearing;
    };

private:
    static void computeDistanceAndBearing(double lat1, double lon1, double lat2, double lon2, android::sp<BearingDistanceCache>& results)
    {
        // Based on http://www.ngs.noaa.gov/PUBS_LIB/inverse.pdf
        // using the "Inverse Formula" (section 4)

        const int MAXITERS = 20;
        // Convert lat/long to radians
        lat1 *= M_PI / 180.0;
        lat2 *= M_PI / 180.0;
        lon1 *= M_PI / 180.0;
        lon2 *= M_PI / 180.0;

        const double a = 6378137.0; // WGS84 major axis
        const double b = 6356752.3142; // WGS84 semi-major axis
        const double f = (a - b) / a;
        const double aSqMinusBSqOverBSq = (a * a - b * b) / (b * b);

        const double L = lon2 - lon1;
        double A = 0.0;
        const double U1 = atan((1.0 - f) * tan(lat1));
        const double U2 = atan((1.0 - f) * tan(lat2));

        const double cosU1 = cos(U1);
        const double cosU2 = cos(U2);
        const double sinU1 = sin(U1);
        const double sinU2 = sin(U2);
        const double cosU1cosU2 = cosU1 * cosU2;
        const double sinU1sinU2 = sinU1 * sinU2;

        double sigma = 0.0;
        double deltaSigma = 0.0;
        double cosSqAlpha = 0.0;
        double cos2SM = 0.0;
        double cosSigma = 0.0;
        double sinSigma = 0.0;
        double cosLambda = 0.0;
        double sinLambda = 0.0;

        double lambda = L; // initial guess
        for (int iter = 0; iter < MAXITERS; iter++) {
            const double lambdaOrig = lambda;
            cosLambda = cos(lambda);
            sinLambda = sin(lambda);
            const double t1 = cosU2 * sinLambda;
            const double t2 = cosU1 * sinU2 - sinU1 * cosU2 * cosLambda;
            const double sinSqSigma = t1 * t1 + t2 * t2; // (14)
            sinSigma = sqrt(sinSqSigma);
            cosSigma = sinU1sinU2 + cosU1cosU2 * cosLambda; // (15)
            sigma = atan2(sinSigma, cosSigma); // (16)
            const double sinAlpha = (std::fabs(sinSigma) < 1e-9) ? 0.0 :
                cosU1cosU2 * sinLambda / sinSigma; // (17)
            cosSqAlpha = 1.0 - sinAlpha * sinAlpha;
            cos2SM = (std::fabs(cosSqAlpha) < 1e-9) ? 0.0 :
                cosSigma - 2.0 * sinU1sinU2 / cosSqAlpha; // (18)

            const double uSquared = cosSqAlpha * aSqMinusBSqOverBSq; // defn
            A = 1.0 + (uSquared / 16384.0) * // (3)
                (4096.0 + uSquared *
                (-768 + uSquared * (320.0 - 175.0 * uSquared)));
            const double B = (uSquared / 1024.0) * // (4)
                (256.0 + uSquared *
                (-128.0 + uSquared * (74.0 - 47.0 * uSquared)));
            const double C = (f / 16.0) *
                cosSqAlpha *
                (4.0 + f * (4.0 - 3.0 * cosSqAlpha)); // (10)
            const double cos2SMSq = cos2SM * cos2SM;
                deltaSigma = B * sinSigma * // (6)
                (cos2SM + (B / 4.0) *
                (cosSigma * (-1.0 + 2.0 * cos2SMSq) -
                (B / 6.0) * cos2SM *
                (-3.0 + 4.0 * sinSigma * sinSigma) *
                (-3.0 + 4.0 * cos2SMSq)));

            lambda = L +
                (1.0 - C) * f * sinAlpha *
                (sigma + C * sinSigma *
                (cos2SM + C * cosSigma *
                (-1.0 + 2.0 * cos2SM * cos2SM))); // (11)

            const double delta = (lambda - lambdaOrig) / lambda;
            if (std::abs(delta) < 1.0e-12) {
                break;
            }
        }

        const float distance = static_cast<float>(b * A * (sigma - deltaSigma));
        results->mDistance = distance;
        float initialBearing = static_cast<float> (atan2(cosU2 * sinLambda,
            cosU1 * sinU2 - sinU1 * cosU2 * cosLambda));
        initialBearing *= 180.0F / M_PI;
        results->mInitialBearing = initialBearing;
        float finalBearing = static_cast<float> (atan2(cosU1 * sinLambda,
                -sinU1 * cosU2 + cosU1 * sinU2 * cosLambda));
        finalBearing *= 180.0F / M_PI;
        results->mFinalBearing = finalBearing;
        results->mLat1 = lat1;
        results->mLat2 = lat2;
        results->mLon1 = lon1;
        results->mLon2 = lon2;
    }

    static void Tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters = " ");

};
}

#endif //TIGER_SDK_LOCATION_LOCATION_H
