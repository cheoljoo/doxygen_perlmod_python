/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_INCLUDE_HARDWARE_GPS_H
#define ANDROID_INCLUDE_HARDWARE_GPS_H

#include <stdint.h>
#include <sys/cdefs.h>
#include <sys/types.h>
#include <pthread.h>
#include <sys/socket.h>
#include <stdbool.h>

//#include "location_service_v02.h"

//#include <hardware/hardware.h>

#define LGE_XTRA
#define SUPPORT_GEN12_GNSS

__BEGIN_DECLS

/**
 * The id of this module
 */
#define GPS_HARDWARE_MODULE_ID "gps"


/** Milliseconds since January 1, 1970 */
typedef int64_t GpsUtcTime;

/** Maximum number of SVs for gps_sv_status_callback(). */
#define GPS_MAX_SVS 32
/** Maximum number of SVs for gps_sv_status_callback(). */
#define GNSS_MAX_SVS 176

/** Maximum number of Measurements in gps_measurement_callback(). */
#define GPS_MAX_MEASUREMENT   32

/** Maximum number of Measurements in gnss_measurement_callback(). */
#define GNSS_MAX_MEASUREMENT   64

/** Requested operational mode for GPS operation. */
typedef uint32_t GpsPositionMode;
/* IMPORTANT: Note that the following values must match
 * constants in GpsLocationProvider.java. */
/** Mode for running GPS standalone (no assistance). */
#define GPS_POSITION_MODE_STANDALONE    0
/** AGPS MS-Based mode. */
#define GPS_POSITION_MODE_MS_BASED      1
/**
 * AGPS MS-Assisted mode. This mode is not maintained by the platform anymore.
 * It is strongly recommended to use GPS_POSITION_MODE_MS_BASED instead.
 */
#define GPS_POSITION_MODE_MS_ASSISTED   2

/** Requested recurrence mode for GPS operation. */
typedef uint32_t GpsPositionRecurrence;
/* IMPORTANT: Note that the following values must match
 * constants in GpsLocationProvider.java. */
/** Receive GPS fixes on a recurring basis at a specified period. */
#define GPS_POSITION_RECURRENCE_PERIODIC    0
/** Request a single shot GPS fix. */
#define GPS_POSITION_RECURRENCE_SINGLE      1

/** GPS status event values. */
typedef uint16_t GpsStatusValue;
/* IMPORTANT: Note that the following values must match
 * constants in GpsLocationProvider.java. */
/** GPS status unknown. */
#define GPS_STATUS_NONE             0
/** GPS has begun navigating. */
#define GPS_STATUS_SESSION_BEGIN    1
/** GPS has stopped navigating. */
#define GPS_STATUS_SESSION_END      2
/** GPS has powered on but is not navigating. */
#define GPS_STATUS_ENGINE_ON        3
/** GPS is powered off. */
#define GPS_STATUS_ENGINE_OFF       4

/** Flags to indicate which values are valid in a GpsLocation. */
typedef uint16_t GpsLocationFlags;
/* IMPORTANT: Note that the following values must match
 * constants in GpsLocationProvider.java. */
/** GpsLocation has valid latitude and longitude. */
#define GPS_LOCATION_HAS_LAT_LONG   0x0001
/** GpsLocation has valid altitude. */
#define GPS_LOCATION_HAS_ALTITUDE   0x0002
/** GpsLocation has valid speed. */
#define GPS_LOCATION_HAS_SPEED      0x0004
/** GpsLocation has valid bearing. */
#define GPS_LOCATION_HAS_BEARING    0x0008
/** GpsLocation has valid accuracy. */
#define GPS_LOCATION_HAS_ACCURACY   0x0010

/** Flags for the gps_set_capabilities callback. */

/**
 * GPS HAL schedules fixes for GPS_POSITION_RECURRENCE_PERIODIC mode. If this is
 * not set, then the framework will use 1000ms for min_interval and will start
 * and call start() and stop() to schedule the GPS.
 */
#define GPS_CAPABILITY_SCHEDULING       (1 << 0)
/** GPS supports MS-Based AGPS mode */
#define GPS_CAPABILITY_MSB              (1 << 1)
/** GPS supports MS-Assisted AGPS mode */
#define GPS_CAPABILITY_MSA              (1 << 2)
/** GPS supports single-shot fixes */
#define GPS_CAPABILITY_SINGLE_SHOT      (1 << 3)
/** GPS supports on demand time injection */
#define GPS_CAPABILITY_ON_DEMAND_TIME   (1 << 4)
/** GPS supports Geofencing  */
#define GPS_CAPABILITY_GEOFENCING       (1 << 5)
/** GPS supports Measurements. */
#define GPS_CAPABILITY_MEASUREMENTS     (1 << 6)
/** GPS supports Navigation Messages */
#define GPS_CAPABILITY_NAV_MESSAGES     (1 << 7)

/**
 * Flags used to specify which aiding data to delete when calling
 * delete_aiding_data().
 */
typedef uint16_t GpsAidingData;
/* IMPORTANT: Note that the following values must match
 * constants in GpsLocationProvider.java. */
#define GPS_DELETE_EPHEMERIS        0x0001
#define GPS_DELETE_ALMANAC          0x0002
#define GPS_DELETE_POSITION         0x0004
#define GPS_DELETE_TIME             0x0008
#define GPS_DELETE_IONO             0x0010
#define GPS_DELETE_UTC              0x0020
#define GPS_DELETE_HEALTH           0x0040
#define GPS_DELETE_SVDIR            0x0080
#define GPS_DELETE_SVSTEER          0x0100
#define GPS_DELETE_SADATA           0x0200
#define GPS_DELETE_RTI              0x0400
#define GPS_DELETE_CELLDB_INFO      0x8000
#define GPS_DELETE_ALL              0xFFFF

/**
 * Flags used to specify which aiding data to delete when calling
 * delete_aiding_data().
 */
typedef uint32_t GnssAidingDataSvMask;
#define GNSS_AIDING_DATA_SV_EPHEMERIS_BIT         (1<<0)  // ephemeris
#define GNSS_AIDING_DATA_SV_ALMANAC_BIT           (1<<1)  // almanac
#define GNSS_AIDING_DATA_SV_HEALTH_BIT            (1<<2)  // health
#define GNSS_AIDING_DATA_SV_DIRECTION_BIT         (1<<3)  // direction
#define GNSS_AIDING_DATA_SV_STEER_BIT             (1<<4)  // steer
#define GNSS_AIDING_DATA_SV_ALMANAC_CORR_BIT      (1<<5)  // almanac correction
#define GNSS_AIDING_DATA_SV_BLACKLIST_BIT         (1<<6)  // blacklist SVs
#define GNSS_AIDING_DATA_SV_SA_DATA_BIT           (1<<7)  // sensitivity assistance data
#define GNSS_AIDING_DATA_SV_NO_EXIST_BIT          (1<<8)  // SV does not exist
#define GNSS_AIDING_DATA_SV_IONOSPHERE_BIT        (1<<9)  // ionosphere correction
#define GNSS_AIDING_DATA_SV_TIME_BIT              (1<<10) // reset satellite time
#define GNSS_AIDING_DATA_SV_MB_DATA               (1<<11) // delete multiband data
#define GNSS_AIDING_DATA_SV_POLY_BIT              (1<<12) // poly

typedef uint32_t GnssAidingDataCommonMask;
#define GNSS_AIDING_DATA_COMMON_POSITION_BIT      (1<<0)  // position estimate
#define GNSS_AIDING_DATA_COMMON_TIME_BIT          (1<<1)  // reset all clock values
#define GNSS_AIDING_DATA_COMMON_UTC_BIT           (1<<2)  // UTC estimate
#define GNSS_AIDING_DATA_COMMON_RTI_BIT           (1<<3)  // RTI
#define GNSS_AIDING_DATA_COMMON_FREQ_BIAS_EST_BIT (1<<4)  // frequency bias estimate
#define GNSS_AIDING_DATA_COMMON_CELLDB_BIT        (1<<5)  // all celldb info

#define GNSS_AIDING_DATA_DELETE_ALL 0xFFFFFFFF
/** AGPS type */
typedef uint16_t AGpsType;
#define AGPS_TYPE_SUPL          1
#define AGPS_TYPE_C2K           2

typedef uint16_t AGpsSetIDType;
#define AGPS_SETID_TYPE_NONE    0
#define AGPS_SETID_TYPE_IMSI    1
#define AGPS_SETID_TYPE_MSISDN  2

typedef uint16_t ApnIpType;
#define APN_IP_INVALID          0
#define APN_IP_IPV4             1
#define APN_IP_IPV6             2
#define APN_IP_IPV4V6           3

/**
 * String length constants
 */
#define GPS_NI_SHORT_STRING_MAXLEN      256
#define GPS_NI_LONG_STRING_MAXLEN       2048

/**
 * GpsNiType constants
 */
typedef uint32_t GpsNiType;
#define GPS_NI_TYPE_VOICE              1
#define GPS_NI_TYPE_UMTS_SUPL          2
#define GPS_NI_TYPE_UMTS_CTRL_PLANE    3

/**
 * GpsNiNotifyFlags constants
 */
typedef uint32_t GpsNiNotifyFlags;
/** NI requires notification */
#define GPS_NI_NEED_NOTIFY          0x0001
/** NI requires verification */
#define GPS_NI_NEED_VERIFY          0x0002
/** NI requires privacy override, no notification/minimal trace */
#define GPS_NI_PRIVACY_OVERRIDE     0x0004

/**
 * GPS NI responses, used to define the response in
 * NI structures
 */
typedef int GpsUserResponseType;
#define GPS_NI_RESPONSE_ACCEPT         1
#define GPS_NI_RESPONSE_DENY           2
#define GPS_NI_RESPONSE_NORESP         3

/**
 * NI data encoding scheme
 */
typedef int GpsNiEncodingType;
#define GPS_ENC_NONE                   0
#define GPS_ENC_SUPL_GSM_DEFAULT       1
#define GPS_ENC_SUPL_UTF8              2
#define GPS_ENC_SUPL_UCS2              3
#define GPS_ENC_UNKNOWN                -1

/** AGPS status event values. */
typedef uint16_t AGpsStatusValue;
/** GPS requests data connection for AGPS. */
#define GPS_REQUEST_AGPS_DATA_CONN  1
/** GPS releases the AGPS data connection. */
#define GPS_RELEASE_AGPS_DATA_CONN  2
/** AGPS data connection initiated */
#define GPS_AGPS_DATA_CONNECTED     3
/** AGPS data connection completed */
#define GPS_AGPS_DATA_CONN_DONE     4
/** AGPS data connection failed */
#define GPS_AGPS_DATA_CONN_FAILED   5

typedef uint16_t AGpsRefLocationType;
#define AGPS_REF_LOCATION_TYPE_GSM_CELLID   1
#define AGPS_REF_LOCATION_TYPE_UMTS_CELLID  2
#define AGPS_REF_LOCATION_TYPE_MAC          3
#define AGPS_REF_LOCATION_TYPE_LTE_CELLID   4

/* Deprecated, to be removed in the next Android release. */
#define AGPS_REG_LOCATION_TYPE_MAC          3

/** Network types for update_network_state "type" parameter */
#define AGPS_RIL_NETWORK_TYPE_MOBILE        0
#define AGPS_RIL_NETWORK_TYPE_WIFI          1
#define AGPS_RIL_NETWORK_TYPE_MOBILE_MMS    2
#define AGPS_RIL_NETWORK_TYPE_MOBILE_SUPL   3
#define AGPS_RIL_NETWORK_TTYPE_MOBILE_DUN   4
#define AGPS_RIL_NETWORK_TTYPE_MOBILE_HIPRI 5
#define AGPS_RIL_NETWORK_TTYPE_WIMAX        6

/* The following typedef together with its constants below are deprecated, and
 * will be removed in the next release. */
typedef uint16_t GpsClockFlags;
#define GPS_CLOCK_HAS_LEAP_SECOND               (1<<0)
#define GPS_CLOCK_HAS_TIME_UNCERTAINTY          (1<<1)
#define GPS_CLOCK_HAS_FULL_BIAS                 (1<<2)
#define GPS_CLOCK_HAS_BIAS                      (1<<3)
#define GPS_CLOCK_HAS_BIAS_UNCERTAINTY          (1<<4)
#define GPS_CLOCK_HAS_DRIFT                     (1<<5)
#define GPS_CLOCK_HAS_DRIFT_UNCERTAINTY         (1<<6)

/**
 * Flags to indicate what fields in GnssClock are valid.
 */
typedef uint16_t GnssClockFlags;
/** A valid 'leap second' is stored in the data structure. */
#define GNSS_CLOCK_HAS_LEAP_SECOND               (1<<0)
/** A valid 'time uncertainty' is stored in the data structure. */
#define GNSS_CLOCK_HAS_TIME_UNCERTAINTY          (1<<1)
/** A valid 'full bias' is stored in the data structure. */
#define GNSS_CLOCK_HAS_FULL_BIAS                 (1<<2)
/** A valid 'bias' is stored in the data structure. */
#define GNSS_CLOCK_HAS_BIAS                      (1<<3)
/** A valid 'bias uncertainty' is stored in the data structure. */
#define GNSS_CLOCK_HAS_BIAS_UNCERTAINTY          (1<<4)
/** A valid 'drift' is stored in the data structure. */
#define GNSS_CLOCK_HAS_DRIFT                     (1<<5)
/** A valid 'drift uncertainty' is stored in the data structure. */
#define GNSS_CLOCK_HAS_DRIFT_UNCERTAINTY         (1<<6)

/* The following typedef together with its constants below are deprecated, and
 * will be removed in the next release. */
typedef uint8_t GpsClockType;
#define GPS_CLOCK_TYPE_UNKNOWN                  0
#define GPS_CLOCK_TYPE_LOCAL_HW_TIME            1
#define GPS_CLOCK_TYPE_GPS_TIME                 2

/* The following typedef together with its constants below are deprecated, and
 * will be removed in the next release. */
typedef uint32_t GpsMeasurementFlags;
#define GPS_MEASUREMENT_HAS_SNR                               (1<<0)
#define GPS_MEASUREMENT_HAS_ELEVATION                         (1<<1)
#define GPS_MEASUREMENT_HAS_ELEVATION_UNCERTAINTY             (1<<2)
#define GPS_MEASUREMENT_HAS_AZIMUTH                           (1<<3)
#define GPS_MEASUREMENT_HAS_AZIMUTH_UNCERTAINTY               (1<<4)
#define GPS_MEASUREMENT_HAS_PSEUDORANGE                       (1<<5)
#define GPS_MEASUREMENT_HAS_PSEUDORANGE_UNCERTAINTY           (1<<6)
#define GPS_MEASUREMENT_HAS_CODE_PHASE                        (1<<7)
#define GPS_MEASUREMENT_HAS_CODE_PHASE_UNCERTAINTY            (1<<8)
#define GPS_MEASUREMENT_HAS_CARRIER_FREQUENCY                 (1<<9)
#define GPS_MEASUREMENT_HAS_CARRIER_CYCLES                    (1<<10)
#define GPS_MEASUREMENT_HAS_CARRIER_PHASE                     (1<<11)
#define GPS_MEASUREMENT_HAS_CARRIER_PHASE_UNCERTAINTY         (1<<12)
#define GPS_MEASUREMENT_HAS_BIT_NUMBER                        (1<<13)
#define GPS_MEASUREMENT_HAS_TIME_FROM_LAST_BIT                (1<<14)
#define GPS_MEASUREMENT_HAS_DOPPLER_SHIFT                     (1<<15)
#define GPS_MEASUREMENT_HAS_DOPPLER_SHIFT_UNCERTAINTY         (1<<16)
#define GPS_MEASUREMENT_HAS_USED_IN_FIX                       (1<<17)
#define GPS_MEASUREMENT_HAS_UNCORRECTED_PSEUDORANGE_RATE      (1<<18)

/**
 * Flags to indicate what fields in GnssMeasurement are valid.
 */
typedef uint32_t GnssMeasurementFlags;
/** A valid 'snr' is stored in the data structure. */
#define GNSS_MEASUREMENT_HAS_SNR                               (1<<0)
/** A valid 'carrier frequency' is stored in the data structure. */
#define GNSS_MEASUREMENT_HAS_CARRIER_FREQUENCY                 (1<<9)
/** A valid 'carrier cycles' is stored in the data structure. */
#define GNSS_MEASUREMENT_HAS_CARRIER_CYCLES                    (1<<10)
/** A valid 'carrier phase' is stored in the data structure. */
#define GNSS_MEASUREMENT_HAS_CARRIER_PHASE                     (1<<11)
/** A valid 'carrier phase uncertainty' is stored in the data structure. */
#define GNSS_MEASUREMENT_HAS_CARRIER_PHASE_UNCERTAINTY         (1<<12)

/* The following typedef together with its constants below are deprecated, and
 * will be removed in the next release. */
typedef uint8_t GpsLossOfLock;
#define GPS_LOSS_OF_LOCK_UNKNOWN                            0
#define GPS_LOSS_OF_LOCK_OK                                 1
#define GPS_LOSS_OF_LOCK_CYCLE_SLIP                         2

/* The following typedef together with its constants below are deprecated, and
 * will be removed in the next release. Use GnssMultipathIndicator instead.
 */
typedef uint8_t GpsMultipathIndicator;
#define GPS_MULTIPATH_INDICATOR_UNKNOWN                 0
#define GPS_MULTIPATH_INDICATOR_DETECTED                1
#define GPS_MULTIPATH_INDICATOR_NOT_USED                2

/**
 * Enumeration of available values for the GNSS Measurement's multipath
 * indicator.
 */
typedef uint8_t GnssMultipathIndicator;
/** The indicator is not available or unknown. */
#define GNSS_MULTIPATH_INDICATOR_UNKNOWN                 0
/** The measurement is indicated to be affected by multipath. */
#define GNSS_MULTIPATH_INDICATOR_PRESENT                 1
/** The measurement is indicated to be not affected by multipath. */
#define GNSS_MULTIPATH_INDICATOR_NOT_PRESENT             2

/* The following typedef together with its constants below are deprecated, and
 * will be removed in the next release. */
typedef uint16_t GpsMeasurementState;
#define GPS_MEASUREMENT_STATE_UNKNOWN                   0
#define GPS_MEASUREMENT_STATE_CODE_LOCK             (1<<0)
#define GPS_MEASUREMENT_STATE_BIT_SYNC              (1<<1)
#define GPS_MEASUREMENT_STATE_SUBFRAME_SYNC         (1<<2)
#define GPS_MEASUREMENT_STATE_TOW_DECODED           (1<<3)
#define GPS_MEASUREMENT_STATE_MSEC_AMBIGUOUS        (1<<4)

/**
 * Flags indicating the GNSS measurement state.
 *
 * The expected behavior here is for GPS HAL to set all the flags that applies.
 * For example, if the state for a satellite is only C/A code locked and bit
 * synchronized, and there is still millisecond ambiguity, the state should be
 * set as:
 *
 * GNSS_MEASUREMENT_STATE_CODE_LOCK | GNSS_MEASUREMENT_STATE_BIT_SYNC |
 *         GNSS_MEASUREMENT_STATE_MSEC_AMBIGUOUS
 *
 * If GNSS is still searching for a satellite, the corresponding state should be
 * set to GNSS_MEASUREMENT_STATE_UNKNOWN(0).
 */
typedef uint32_t GnssMeasurementState;
#define GNSS_MEASUREMENT_STATE_UNKNOWN                   0
#define GNSS_MEASUREMENT_STATE_CODE_LOCK             (1<<0)
#define GNSS_MEASUREMENT_STATE_BIT_SYNC              (1<<1)
#define GNSS_MEASUREMENT_STATE_SUBFRAME_SYNC         (1<<2)
#define GNSS_MEASUREMENT_STATE_TOW_DECODED           (1<<3)
#define GNSS_MEASUREMENT_STATE_MSEC_AMBIGUOUS        (1<<4)
#define GNSS_MEASUREMENT_STATE_SYMBOL_SYNC           (1<<5)
#define GNSS_MEASUREMENT_STATE_GLO_STRING_SYNC       (1<<6)
#define GNSS_MEASUREMENT_STATE_GLO_TOD_DECODED       (1<<7)
#define GNSS_MEASUREMENT_STATE_BDS_D2_BIT_SYNC       (1<<8)
#define GNSS_MEASUREMENT_STATE_BDS_D2_SUBFRAME_SYNC  (1<<9)
#define GNSS_MEASUREMENT_STATE_GAL_E1BC_CODE_LOCK    (1<<10)
#define GNSS_MEASUREMENT_STATE_GAL_E1C_2ND_CODE_LOCK (1<<11)
#define GNSS_MEASUREMENT_STATE_GAL_E1B_PAGE_SYNC     (1<<12)
#define GNSS_MEASUREMENT_STATE_SBAS_SYNC             (1<<13)

/* The following typedef together with its constants below are deprecated, and
 * will be removed in the next release. */
typedef uint16_t GpsAccumulatedDeltaRangeState;
#define GPS_ADR_STATE_UNKNOWN                       0
#define GPS_ADR_STATE_VALID                     (1<<0)
#define GPS_ADR_STATE_RESET                     (1<<1)
#define GPS_ADR_STATE_CYCLE_SLIP                (1<<2)

/**
 * Flags indicating the Accumulated Delta Range's states.
 */
typedef uint16_t GnssAccumulatedDeltaRangeState;
#define GNSS_ADR_STATE_UNKNOWN                       0
#define GNSS_ADR_STATE_VALID                     (1<<0)
#define GNSS_ADR_STATE_RESET                     (1<<1)
#define GNSS_ADR_STATE_CYCLE_SLIP                (1<<2)

/* The following typedef together with its constants below are deprecated, and
 * will be removed in the next release. */
typedef uint8_t GpsNavigationMessageType;
#define GPS_NAVIGATION_MESSAGE_TYPE_UNKNOWN         0
#define GPS_NAVIGATION_MESSAGE_TYPE_L1CA            1
#define GPS_NAVIGATION_MESSAGE_TYPE_L2CNAV          2
#define GPS_NAVIGATION_MESSAGE_TYPE_L5CNAV          3
#define GPS_NAVIGATION_MESSAGE_TYPE_CNAV2           4

/**
 * Enumeration of available values to indicate the GNSS Navigation message
 * types.
 *
 * For convenience, first byte is the GnssConstellationType on which that signal
 * is typically transmitted
 */
typedef int16_t GnssNavigationMessageType;

#define GNSS_NAVIGATION_MESSAGE_TYPE_UNKNOWN       0
/** GPS L1 C/A message contained in the structure.  */
#define GNSS_NAVIGATION_MESSAGE_TYPE_GPS_L1CA      0x0101
/** GPS L2-CNAV message contained in the structure. */
#define GNSS_NAVIGATION_MESSAGE_TYPE_GPS_L2CNAV    0x0102
/** GPS L5-CNAV message contained in the structure. */
#define GNSS_NAVIGATION_MESSAGE_TYPE_GPS_L5CNAV    0x0103
/** GPS CNAV-2 message contained in the structure. */
#define GNSS_NAVIGATION_MESSAGE_TYPE_GPS_CNAV2     0x0104
/** Glonass L1 CA message contained in the structure. */
#define GNSS_NAVIGATION_MESSAGE_TYPE_GLO_L1CA      0x0301
/** Beidou D1 message contained in the structure. */
#define GNSS_NAVIGATION_MESSAGE_TYPE_BDS_D1        0x0501
/** Beidou D2 message contained in the structure. */
#define GNSS_NAVIGATION_MESSAGE_TYPE_BDS_D2        0x0502
/** Galileo I/NAV message contained in the structure. */
#define GNSS_NAVIGATION_MESSAGE_TYPE_GAL_I         0x0601
/** Galileo F/NAV message contained in the structure. */
#define GNSS_NAVIGATION_MESSAGE_TYPE_GAL_F         0x0602

/**
 * Status of Navigation Message
 * When a message is received properly without any parity error in its navigation words, the
 * status should be set to NAV_MESSAGE_STATUS_PARITY_PASSED. But if a message is received
 * with words that failed parity check, but GPS is able to correct those words, the status
 * should be set to NAV_MESSAGE_STATUS_PARITY_REBUILT.
 * No need to send any navigation message that contains words with parity error and cannot be
 * corrected.
 */
typedef uint16_t NavigationMessageStatus;
#define NAV_MESSAGE_STATUS_UNKNOWN              0
#define NAV_MESSAGE_STATUS_PARITY_PASSED   (1<<0)
#define NAV_MESSAGE_STATUS_PARITY_REBUILT  (1<<1)

/* This constant is deprecated, and will be removed in the next release. */
#define NAV_MESSAGE_STATUS_UNKONW              0

/**
 * Flags that indicate information about the satellite
 */
typedef uint8_t                                 GnssSvStatusType;
#define GNSS_SV_STATUS_IDLE_V02 1, /**<  SV is not being actively processed \n  */
#define GNSS_SV_STATUS_SEARCH_V02 2 /**<  The system is searching for this SV \n */
#define GNSS_SV_STATUS_TRACK_V02 3 /**<  SV is being tracked  */

/**
 * Flags that indicate information about the satellite
 */
typedef uint8_t                                 GnssSvFlags;
#define GNSS_SV_FLAGS_NONE                      0
#define GNSS_SV_FLAGS_HAS_EPHEMERIS_DATA        (1 << 0)
#define GNSS_SV_FLAGS_HAS_ALMANAC_DATA          (1 << 1)
#define GNSS_SV_FLAGS_USED_IN_FIX               (1 << 2)
#define GNSS_SV_FLAGS_HAS_HEALTH                (1 << 3)

/**
 * Constellation type of GnssSvInfo
 */
typedef uint8_t                         GnssConstellationType;
#define GNSS_CONSTELLATION_UNKNOWN      0
#define GNSS_CONSTELLATION_GPS          1
#define GNSS_CONSTELLATION_SBAS         2
#define GNSS_CONSTELLATION_GLONASS      3
#define GNSS_CONSTELLATION_QZSS         4
#define GNSS_CONSTELLATION_BEIDOU       5
#define GNSS_CONSTELLATION_GALILEO      6
#define GNSS_CONSTELLATION_GPS_L2       7
#define GNSS_CONSTELLATION_GPS_L5       8

/**
 * Signal type of GnssSvInfo
 */
typedef uint64_t                         GnssSignalType;
#define GNSS_SIGNAL_TYPE_GPS_L1CA            0x00000001 /**<  GPS L1CA Signal  */
#define GNSS_SIGNAL_TYPE_GPS_L1C             0x00000002 /**<  GPS L1C Signal  */
#define GNSS_SIGNAL_TYPE_GPS_L2C_L           0x00000004 /**<  GPS L2C_L RF Band  */
#define GNSS_SIGNAL_TYPE_GPS_L5_Q            0x00000008 /**<  GPS L5_Q RF Band  */
#define GNSS_SIGNAL_TYPE_GLONASS_G1          0x00000010 /**<  GLONASS G1 (L1OF) RF Band  */
#define GNSS_SIGNAL_TYPE_GLONASS_G2          0x00000020 /**<  GLONASS G2 (L2OF) RF Band  */
#define GNSS_SIGNAL_TYPE_GALILEO_E1_C        0x00000040 /**<  GALILEO E1_C RF Band  */
#define GNSS_SIGNAL_TYPE_GALILEO_E5A_Q       0x00000080 /**<  GALILEO E5A_Q RF Band  */
#define GNSS_SIGNAL_TYPE_GALILEO_E5B_Q       0x00000100 /**<  GALILEO E5B_Q RF Band  */
#define GNSS_SIGNAL_TYPE_BEIDOU_B1_I         0x00000200 /**<  BEIDOU B1_I RF Band  */
#define GNSS_SIGNAL_TYPE_BEIDOU_B1C          0x00000400 /**<  BEIDOU B1C RF Band  */
#define GNSS_SIGNAL_TYPE_BEIDOU_B2_I         0x00000800 /**<  BEIDOU B2_I RF Band  */
#define GNSS_SIGNAL_TYPE_BEIDOU_B2A_I        0x00001000 /**<  BEIDOU B2A_I RF Band  */
#define GNSS_SIGNAL_TYPE_QZSS_L1CA           0x00002000 /**<  QZSS L1CA RF Band  */
#define GNSS_SIGNAL_TYPE_QZSS_L1S            0x00004000 /**<  QZSS L1S RF Band  */
#define GNSS_SIGNAL_TYPE_QZSS_L2C_L          0x00008000 /**<  QZSS L2C_L RF Band  */
#define GNSS_SIGNAL_TYPE_QZSS_L5_Q           0x00010000 /**<  QZSS L5_Q RF Band  */
#define GNSS_SIGNAL_TYPE_SBAS_L1_CA          0x00020000 /**<  SBAS L1_CA RF Band  */

/**
 ********************************************************************************************
 *************************** LGE Define *****************************************************
 ********************************************************************************************
 */

/**
 * LGE CMD
 */
#define GNSS_ELEVATION_MASK  4914
#define GNSS_SBAS_ENABLED    5594
#define GNSS_GNSS_CONFIG     70326

/**
 * LGE CMD READ_PARAM
 */
#define READ_MASIC           1234

/**
 * SBAS Control
 */
#define GNSS_SBAS_DISABLE    0
#define GNSS_SBAS_ENABLE     1

/**
 * Constellation of GNSS_NV_EFS_ME_GNSS_CONFIG
 */
#define GNSS_CONFIG_GPS      0x00000001
#define GNSS_CONFIG_GLO      0x00000002
#define GNSS_CONFIG_BDSOUTUS 0x00000004
// #define GNSS_CONFIG_GALOUTUS 0x00000008 /* Deprecated */
#define GNSS_CONFIG_BDS      0x00000010
// #define GNSS_CONFIG_GAL      0x00000020 /* Deprecated */
#define GNSS_CONFIG_GAL      0x00000800

typedef enum
{
  GNSS_MEAS_BLK_SRC_GPS,       /* Source of the measurement block is GPS */
  GNSS_MEAS_BLK_SRC_GLO,       /* Source of the measurement block is GLONASS */
  GNSS_MEAS_BLK_SRC_BDS,       /* Source of the measurement block is BDS */
  GNSS_MEAS_BLK_SRC_GAL,       /* Source of the measurement block is GAL */
  GNSS_MEAS_BLK_SRC_HBW_GPS,
  GNSS_MEAS_BLK_SRC_RXD_GPS,
  GNSS_MEAS_BLK_SRC_QZSS_SBAS, /*!< Source of the measurement block is QZSS + SBAS */
  GNSS_MEAS_BLK_SRC_LEGACY_MAX, /*!< Source of the measurement block is QZSS + SBAS */
  GNSS_MEAS_BLK_SRC_GPS_L2C = GNSS_MEAS_BLK_SRC_LEGACY_MAX,   /* Source of the measurement block is GPS L2C*/
  GNSS_MEAS_BLK_SRC_GPS_L5Q,   /* Source of the measurement block is GPS L5Q*/
  GNSS_MEAS_BLK_SRC_GLO_G2,    /* Source of the measurement block is GLO G2*/
  GNSS_MEAS_BLK_SRC_BDS_B2,    /* Source of the measurement block is BDS B2*/
  GNSS_MEAS_BLK_SRC_GAL_E5A,   /* Source of the measurement block is GAL E5A*/
  GNSS_MEAS_BLK_SRC_QZSS_L2C,  /* Source of the measurement block is QZSS L2C*/
  GNSS_MEAS_BLK_SRC_QZSS_L5Q,  /* Source of the measurement block is QZSS L5Q*/
  GNSS_MEAS_BLK_SRC_BDS_B2AQ,  /* Source of the measurement block is BDS B2A Q */
  GNSS_MEAS_BLK_SRC_BDS_B1CQ,  /* Source of the measurement block is BDS B1C Q */
  GNSS_MEAS_BLK_SRC_NAVIC,     /* Source of the measurement block is NAVIC L5*/
  GNSS_MEAS_BLK_SRC_GPS_L1_CHIPX4, /* Source of the measurement block is GPS L1 Chipx4 */
  GNSS_MEAS_BLK_SRC_QZSS_L1S,  /* Source of the measurement block is QZSS L1S*/
  GNSS_MEAS_BLK_SRC_GAL_E5B,   /* Source of the measurement block is GAL E5B*/
  GNSS_MEAS_BLK_SRC_QZSS_SBAS_L1_CHIPX4, /* Source of the measurement block is QZSS and SBAS L1 Chipx4 */
  GNSS_MEAS_BLK_SRC_MAX
} gnss_MeasBlkSrcEnumTypeVal;

typedef enum
{
  gNSS_STATUS_NONE = 0,      /** GPS status unknown. */
  gNSS_STATUS_SESSION_BEGIN, /** GPS has begun navigating. */
  gNSS_STATUS_SESSION_END,   /** GPS has stopped navigating. */
  gNSS_STATUS_ENGINE_ON,     /** GPS has powered on but is not navigating. */
  gNSS_STATUS_ENGINE_OFF,    /** GPS is powered off. */
} gnss_lge_NadGnss_GnssStatusReport_e_type;

typedef enum {
    LOC_RELIABILITY_NOT_SET = 0,
    LOC_RELIABILITY_VERY_LOW = 1,
    LOC_RELIABILITY_LOW = 2,
    LOC_RELIABILITY_MEDIUM = 3,
    LOC_RELIABILITY_HIGH = 4
}LocReliability;

typedef struct {
    uint64_t gps_sv_used_ids_mask;
    uint64_t glo_sv_used_ids_mask;
    uint64_t gal_sv_used_ids_mask;
    uint64_t bds_sv_used_ids_mask;
    uint64_t qzss_sv_used_ids_mask;
} GnssSvUsedInPosition;

typedef uint32_t LocNavSolutionMask;
/* Bitmask to specify whether SBAS ionospheric correction is used  */
#define LOC_NAV_MASK_SBAS_CORRECTION_IONO ((LocNavSolutionMask)0x0001)
/* Bitmask to specify whether SBAS fast correction is used  */
#define LOC_NAV_MASK_SBAS_CORRECTION_FAST ((LocNavSolutionMask)0x0002)
/**<  Bitmask to specify whether SBAS long-tem correction is used  */
#define LOC_NAV_MASK_SBAS_CORRECTION_LONG ((LocNavSolutionMask)0x0004)
/**<  Bitmask to specify whether SBAS integrity information is used  */
#define LOC_NAV_MASK_SBAS_INTEGRITY ((LocNavSolutionMask)0x0008)

typedef uint32_t LocPosTechMask;
#define LOC_POS_TECH_MASK_DEFAULT ((LocPosTechMask)0x00000000)
#define LOC_POS_TECH_MASK_SATELLITE ((LocPosTechMask)0x00000001)
#define LOC_POS_TECH_MASK_CELLID ((LocPosTechMask)0x00000002)
#define LOC_POS_TECH_MASK_WIFI ((LocPosTechMask)0x00000004)
#define LOC_POS_TECH_MASK_SENSORS ((LocPosTechMask)0x00000008)
#define LOC_POS_TECH_MASK_REFERENCE_LOCATION ((LocPosTechMask)0x00000010)
#define LOC_POS_TECH_MASK_INJECTED_COARSE_POSITION ((LocPosTechMask)0x00000020)
#define LOC_POS_TECH_MASK_AFLT ((LocPosTechMask)0x00000040)
#define LOC_POS_TECH_MASK_HYBRID ((LocPosTechMask)0x00000080)

typedef uint32_t LocSvInfoSource;
/** SVinfo source is GNSS/DR */
#define ULP_SVINFO_IS_FROM_GNSS       ((LocSvInfoSource)0x0001)
/** Raw SVinfo from GNSS */
#define ULP_SVINFO_IS_FROM_DR         ((LocSvInfoSource)0x0002)

/** Represents a location. */
typedef struct {
  /** set to sizeof(ExtGpsLocation) */
  size_t          size;
  /** LGE Extension Parameter */
  uint64_t PositionFlags;
  uint64_t PositionFlags_ext;
  uint64_t SmPosFlags;
  uint16_t GpsWeek;
  uint32_t GpsTimeMs;
  uint8_t  GloNumFourYear;
  uint16_t GloNumDaysInFourYear;
  uint32_t GloTimeMs;
  uint32_t UtcTimeMs;
  float PDOP;
  float HDOP;
  float VDOP;
  float GDOP;
  float TDOP;  
  float Velocity[3];
  float Velocity_unc[3];
  float vert_unc; //vertical uncertainty in meters
  float horUncEllipseSemiMajor; //Horizontal Elliptical Uncertainty (Semi-Major Axis)
  float horUncEllipseSemiMinor; //Horizontal Elliptical Uncertainty (Semi-Minor Axis)
  float horUncEllipseOrientAzimuth; //Elliptical Horizontal Uncertainty Azimuth
  float altitudeMeanSeaLevel; //Altitude wrt mean sea level
  float magneticDeviation; //Magnetic Deviation
  float speed_unc; //peed uncertainty in m/s
  float           bearing_unc; //heading uncertainty in degrees (0 to 359.999)
  LocReliability  horizontal_reliability; //horizontal reliability
  LocReliability  vertical_reliability; //vertical reliability
  GnssSvUsedInPosition gnss_sv_used_ids; //Gnss sv used in position data
  LocNavSolutionMask  navSolutionMask; //Nav solution mask to indicate sbas corrections
  LocPosTechMask tech_mask; //Position technology used in computing this fix
  LocSvInfoSource sv_source; //SV Info source used in computing this fix
} ExtGpsLocation;

typedef struct {
  uint16_t GpsWeek;
  uint32_t GpsMsec;
  float ClkTimeBias;
  float ClkTimeUncMs;
  uint8_t SourceOfTime;
} GpsTimeStruct;  /* Type */

typedef struct {
  uint8_t SourceOfTime;
  uint8_t FourYear;
  uint16_t Days;
  uint32_t GloMsec;
  float ClkTimeBias;
  float ClkTimeUncMs;
} GloTimeStruct;  /* Type */

typedef struct {
  uint8_t SourceOfTime;
  uint16_t BdsWeek;
  uint32_t BdsMsec;
  float ClkTimeBias;
  float ClkTimeUncMs;
} BdsTimeStruct;  /* Type */

typedef struct {
  uint8_t SourceOfTime;
  uint16_t GalWeek;
  uint32_t GalMsec;
  float ClkTimeBias;
  float ClkTimeUncMs;
} GalTimeStruct;  /* Type */

typedef struct {
  GpsTimeStruct zGpsTime;
  GloTimeStruct zGloTime;
  BdsTimeStruct zBdsTime;
  GalTimeStruct zGalTime;
} GnssTimeStruct;  /* Type */

typedef struct {
  uint8_t  SystemRtcValid;
  uint32_t RefFCount;
  uint32_t NumClockResets;
  uint64_t SystemRtcMs;
  GnssTimeStruct zTime;
//jdoc.kim add for leap seconds
  uint8_t DeltaLeapSec;
  uint8_t DeltaLeapSecUnc;
  uint8_t DeltaLeapSecSrc;
} GnssClockStruct;  /* Type */

//LGE_GNSS_LOCAPI/////////////////////////////////////////////////////////////////////////////
/** Type definition for OEMDRE and OEMCPE from NAS **/

#define POSITION_ECEF_NUM_V02 3
#define POSITION_LLA_NUM_V02 3
#define VELOCITY_ECEF_NUM_V02 3
#define VELOCITY_ENU_NUM_V02 3
#define POSITION_UNCERTAINTY_NUM_V02 2
#define ERROR_ELLIPSE_NUM_V02 3
#define VELOCITY_UNCERTAINTY_NUM_V02 2
#define INTER_CONSTELLATION_TB_NUM_V02 6

#define N_ACTIVE_GPS_CHAN_V02     16  /* Total number of active GPS channels */
#define N_ACTIVE_GLO_CHAN_V02     14  /* Total number of active Glonass channels */
#define N_ACTIVE_BDS_CHAN_V02     16  /* Total number of active BDS channels */
#define N_ACTIVE_GAL_CHAN_V02     16  /* Total number of active GAL channels */
#define N_ACTIVE_QZSS_CHAN_V02    16  /* Total number of active QZSS channels */

//#define N_ACTIVE_CHAN_V02 24 //HIGH
#define N_ACTIVE_CHAN_V02 16 //LOW

typedef enum {
  RELIABILITYENUMT_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  RELIABILITY_NOT_SET_V02 = 0, /**<  Location reliability is not set  */
  RELIABILITY_VERY_LOW_V02 = 1, /**<  Location reliability is very low; use it at your own risk  */
  RELIABILITY_LOW_V02 = 2, /**<  Location reliability is low; little or no cross-checking is possible  */
  RELIABILITY_MEDIUM_V02 = 3, /**<  Location reliability is medium; limited cross-check passed   */
  RELIABILITY_HIGH_V02 = 4, /**<  Location reliability is high; strong cross-check passed  */
  RELIABILITYENUMT_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}ReliabilityEnumT_v02;

typedef struct
{
  float UnfiltMeters;        /* Raw TB in meters */
  float UnfiltUncMeters;     /* Uncertianty of raw TB in
                                   meters */
  uint32_t FiltAgeMs;           /* Msec since last update */
  float FiltMeters;          /* Filtered TB in meters */
  float FiltUncMeters;       /* Uncertainty of filtered TB in meters */
  uint8_t IsPeTbConfident; /* TRUE: PE computed TB is confident, FALSE: otherwise. */
} PeTimeBiasStructT_v02;

typedef struct
{
  /* Bit flags copied verbatim from gnss_NavSolutionStructType */
  uint64_t PositionFlags;
  uint64_t PositionFlags_Ext;

  /* Additional bit flags specific to SM */
  uint64_t SmPosFlags;

  /* GNSS Fix Time Information */
  uint16_t GpsWeek;             /* GPS week number of fix */
  uint32_t GpsTimeMs;           /* GPS time in week (milliseconds) of fix */
  uint8_t  GloNumFourYear;      /* Glonass four-year cycle number */
  uint16_t GloNumDaysInFourYear;/* Glonass calendar day within the current four-year cycle */
  uint32_t GloTimeMs;           /* Glonass time in day (milliseconds) */
  uint32_t UtcFixTime;           /* UTC time (milliseconds) adjusted for leap seconds */
  uint32_t RefFCount;           /* Receiver's ms counter value */
  uint8_t  InitGpsTimeSrc;      /* Time source information (pdsm_extended_time_src_e_type) */

  uint32_t PosCounter;

  uint8_t PosEcef_len;  /**< Must be set to # of elements in PosEcef */
  double PosEcef[POSITION_ECEF_NUM_V02];

  uint8_t PosLla_len;  /**< Must be set to # of elements in PosLla */
  double PosLla[POSITION_LLA_NUM_V02];

  uint8_t VelEcef_len;  /**< Must be set to # of elements in VelEcef */
  double VelEcef[VELOCITY_ECEF_NUM_V02];

  uint8_t VelEnu_len;  /**< Must be set to # of elements in VelEnu */
  float VelEnu[VELOCITY_ENU_NUM_V02];

  float HeadingRad;

  float HeadingUncRad;

  float GnssHeadingRad;

  float GnssHeadingUncRad;

  float    PosSigma;        /* Position standard deviation estimate (m) */
  uint8_t PosUnc2D_len;  /**< Must be set to # of elements in PosUnc2D */
  float    PosUnc2D[POSITION_UNCERTAINTY_NUM_V02]; /* Position (Lat, Long) uncertainty (m) */
  float    PosUncVertical;      /* Vertical position uncertainty (m) */
  uint8_t ErrorEllipse_len;  /**< Must be set to # of elements in ErrorEllipse */
  float    ErrorEllipse[ERROR_ELLIPSE_NUM_V02];     /* loc_uncrtnty_ang (degree), loc_uncrtnty_a (m), loc_uncrtnty_p (m) */
  float    VelUnc;           /* Velocity uncertainty (m/s) */
  uint8_t VuncEastNorthMps_len;  /**< Must be set to # of elements in VuncEastNorthMps */
  float    VuncEastNorthMps[VELOCITY_UNCERTAINTY_NUM_V02]; /* East, North velocity uncertainty (m/s) */
  float    VuncVertMps;         /* Vertical velocity uncertainty (m/s) */
  float    ClockBias;           /* Receiver's clock bias (m) */
  float    ClockBiasUncMs;      /* Receiver's clock uncertainty (m) */
  float    ClockDriftRate;      /* Receiver's clock drift (m/s) */
  float    ClockDriftRateUncMps;/* Receiver's clock frequency bias uncertainty (m/s) */

  uint8_t InterGnssTb_len;  /**< Must be set to # of elements in InterGnssTb */
  PeTimeBiasStructT_v02 InterGnssTb[INTER_CONSTELLATION_TB_NUM_V02];

  float    FilteredAlt;         /* Filtered altitude (m) */
  float    FilteredAltUnc;      /* Filtered altitude uncertainty, one-sided (m) */
  float    UnfilteredAlt;       /* Unfiltered altitude (m) */
  float    UnfilteredAltUnc;    /* Unfiltered altitude uncertainty, one-sided (m) */
  float    MagDeviation;        /* Magnetic deviation from true north (degrees) */

  float    PDOP;                /* Position Dilution of Precision (unitless) */
  float    HDOP;                /* Horizontal DOP (unitless) */
  float    VDOP;                /* Vertial DOP (unitless) */
  float    TDOP; 				/* Time DOP (unitless) */
  float    GDOP; 				/* Geometrical DOP (unitless) */

  uint8_t  FirstFix;            /* Set TRUE when we have are first fix */
  uint8_t  DriftEstimated;      /* Set TRUE when the clock drift rate is estimated from
                                 * a difference of two clock biases */

  uint8_t  MagDevGood;          /* TRUE if magnetic devation is good */
  uint8_t  IonoCorrected;       /* FALSE indicates that not all SV measurements were iono corrected */
  uint8_t  TropoCorrected;      /* FALSE indicates that not all SV measurements were tropo corrected */

  ReliabilityEnumT_v02 HoriRelIndicator; /* horizontal reliability */
  ReliabilityEnumT_v02 VertRelIndicator; /* vertical reliability */

  uint16_t SensorDataUsageMask;    /* A bit set to 1 indicates that data from the corresponding
                                      sensor was used in order to compute the content (position,
                                      velocity, heading) in this packet.
                                      0x0001 ?Accelerometer
                                      0x0002 ?Gyro
                                      0xFFFC - Reserved
                                      Future versions of the GPS service may use reserved bits
                                      to represent new sensor types. A control point should
                                      ignore any bits that it considers to be reserved. */
  uint16_t SensorAidingIndicator;  /* A bit set to to 1 indicates that certain fields (position,
                                      velocity, heading, etc) in parsed position data TLV were
                                      aided with sensor data.
                                      0x0001 ?Heading aided with sensor data
                                      0x0002 ?Speed aided with sensor data
                                      0x0004 ?Position aided with sensor data
                                      0x0008 ?Velocity aided with sensor data
                                      0FFF0 ?Reserved
                                      Future versions of the GPS service may use reserved bits
                                      to represent new methods of sensor aiding (e.g. tightly
                                      coupled measurement combinations). A control point should
                                      ignore any bits that it considers to be reserved. */

} GnssNavPositionStructT_v02;

typedef struct
{
  uint32_t SvInfoMask;  /* See SM_GNSS_SV_INFO_XXX definition bits above */
  uint16_t SvId;        /* GNSS SV: {GPS|BDS|GAL} PRN or {GLO} SlotID. */

  /* GNSS SV-specific data for SVs used in Position Fix (valid if PDSM_GNSS_SV_INFO_USED_POS_FIX is set) */
  float  PrResMeters; /* Pseudo-range measurement residuals of GNSS SV */
  float  PrUncMeters; /* Pseudo-range weights (uncertainties) of GNSS SV */

  /* GNSS SV-specific data for SVs used in Velocity Fix (valid if SM_GNSS_SV_INFO_VEL_FIX_VALID is set) */
  float  PrrResMps;   /* Pseudo-range rate (doppler) measurement residuals of GNSS SV */
  float  PrrUncMps;   /* Pseudo-range rate (doppler) uncertainties of GNSS SV */

  uint16_t IODE;			/* IODE {GPS|BDS|GAL}  */
	/*
	  union
	  {
	    uint16 w_IODE;      // IODE {GPS|BDS|GAL}
	    uint8  u_GloTb;     // Tb for {GLO} SV
	  } ;
	*/

  /* GNSS SV-specific data for SVs detected by searcher (valid if SM_GNSS_SV_INFO_MEAS_VALID is set) */
  int8_t   FreqNum;     /* Frequency number(-7~+6) of the Glonass SV, invalid for GPS/BDS SV
                           valid if PDSM_GNSS_SV_INFO_USED_POS_FIX is set as well*/

  uint8_t  SvFSAvail;   /* Indication for FineSpeed Availability 1:Available 0:NotAvailable */
  uint8_t  SvPrtyGood;  /* Indication for whether any parity errors have been
                         * observed in the last second for each GNSS SV
                         * = 1:Parity Good
                         * = 0:Parity Bad
                         */
  uint16_t SvPrtyErr;   /* {GPS|BDS} the 10 LSB to indicate parity errors in the 10 words of current subframe
                         *     {GLO} boolean type
                         * (bit0 for word 1, ... bit9 for word 10)
                         * = 1:error
                         * = 0:no error
                         */
} GnssSvInfoStructT_v02;

typedef struct
{
  uint8_t  SvInfoValid;  	/* TRUE if all info in this struct valid, otherwise FALSE */

  uint8_t  nSVsDetected;     /* total number of GPS SVs detected by searcher */
  uint8_t  nSVs;             /* Number of SVs used in the position fix. */
  uint8_t  GpsNumSvVelFix;   /* Number of GPS SVs used in Velocity Fix */
  uint32_t GpsSvMaskUsed;    /* Bitmask for GPS SVs used for calculating position fix */
  uint32_t GpsSvMaskUsable;  /* Bitmask for GPS SVs usable for calculating position fix */
  uint8_t GpsSvInfo_len;     /**< Must be set to # of elements in GpsSvInfo */
  GnssSvInfoStructT_v02 GpsSvInfo[N_ACTIVE_GPS_CHAN_V02]; /* SV-specific data for GPS supplemental SV information */

  uint8_t  nGloSVsDetected;  /* total number of GLONASS SVs detected by searcher */
  uint8_t  NumGloSvs;        /* Number of Glonass SVs used in the position fix. */
  uint8_t  GloNumSvVelFix;   /* Number of GLO SVs used in Velocity Fix */
  uint32_t GloSvMaskUsed;    /* Bitmask for GLONASS SVs used for calculating position fix */
  uint32_t GloSvMaskUsable;  /* Bitmask for GLONASS SVs useable for calculating position fix */
  uint8_t GloSvInfo_len;     /**< Must be set to # of elements in GloSvInfo */
  GnssSvInfoStructT_v02 GloSvInfo[N_ACTIVE_GLO_CHAN_V02]; /* SV-specific data for GLO supplemental SV information */

  uint8_t  nBdsSVsDetected;  /* total number of BDS SVs detected by searcher */
  uint8_t  NumBdsSvs;        /* Number of BDS SVs used in the position fix. */
  uint8_t  BdsNumSvVelFix;   /* Number of BDS SVs used in Velocity Fix */
  uint64_t BdsSvMaskUsed;    /* Bitmask for BDS SVs used for calculating position fix */
  uint64_t BdsSvMaskUsable;  /* Bitmask for BDS SVs usable for calculating position fix */
  uint8_t BdsSvInfo_len;     /**< Must be set to # of elements in BdsSvInfo */
  GnssSvInfoStructT_v02 BdsSvInfo[N_ACTIVE_BDS_CHAN_V02]; /* SV-specific data for BDS supplemental SV information */

  uint8_t  nGalSVsDetected;  /* total number of Galileo SVs detected by searcher */
  uint8_t  NumGalSvs;        /* Number of Galileo SVs used in the position fix. */
  uint8_t  GalNumSvVelFix;   /* Number of GAL SVs used in Velocity Fix */
  uint64_t GalSvMaskUsed;    /* Bitmask for GAL SVs used for calculating position fix */
  uint64_t GalSvMaskUsable;  /* Bitmask for GAL SVs usable for calculating position fix */
  uint8_t GalSvInfo_len;     /**< Must be set to # of elements in GalSvInfo */
  GnssSvInfoStructT_v02 GalSvInfo[N_ACTIVE_GAL_CHAN_V02]; /* SV-specific data for GAL supplemental SV information */
} GnssNavSvInfoStructT_v02;

typedef struct
{
  uint16_t  SensorValidMask;/* Use SENSOR_BIAS_VALID_xxx macro to find which of the axes have valid data */
  float XaxisValue;       /*  X-axis Bias
                            - Units gyroscope:(radians)/(seconds)
                            - Units accelerometer:(meters)/(seconds^2)*/
  float YaxisValue;       /*  Y-axis Bias
                            - Units gyroscope:(radians)/(seconds)
                            - Units accelerometer:(meters)/(seconds^2)*/
  float ZaxisValue;       /*  Z-axis Bias
                            - Units gyroscope:(radians)/(seconds)
                            - Units accelerometer:(meters)/(seconds^2)*/
} SensorBiasStructT_v02;


/**
 * On-device Sensor Bias data
 */
typedef struct
{
  uint16_t                    SeqenceNumber;/* Incremental packet serial number (starting from 0), to identify missing packets. */
  SensorBiasStructT_v02  GyroBias;     /* Contains axis validity mask + x,y,z values for Gyro bias */
  SensorBiasStructT_v02  AccelBias;    /* Contains axis validity mask + x,y,z values for accel bias */
} SensorParamReportStructT_v02;


typedef struct {

  uint16_t GpsWeek;

  uint32_t GpsMsec;

  float ClkTimeBias;

  float ClkTimeUncMs;

  uint8_t SourceOfTime;
}GpsTimeStructT_v02;

typedef struct {

  uint8_t SourceOfTime;

  uint8_t FourYear;

  uint16_t Days;

  uint32_t GloMsec;

  float ClkTimeBias;

  float ClkTimeUncMs;
}GloTimeStructT_v02;

typedef struct {

  uint8_t SourceOfTime;

  uint16_t BdsWeek;

  uint32_t BdsMsec;

  float ClkTimeBias;

  float ClkTimeUncMs;
}BdsTimeStructT_v02;

typedef struct {

  uint8_t SourceOfTime;

  uint16_t GalWeek;

  uint32_t GalMsec;

  float ClkTimeBias;

  float ClkTimeUncMs;
}GalTimeStructT_v02;

typedef struct {

  float TBMs;

  float TBUncMs;

  float GrpDelayNs;

  float GrpDelayUncNs;

  float TimeDiffNs;

  float TimeDiffUncNs;
}GnssSingleInterGnssTimeBiasStructT_v02;

typedef struct {

  uint8_t DeltaLeapSec;

  uint8_t DeltaLeapSecUnc;

  uint8_t DeltaLeapSecSrc;

  GnssSingleInterGnssTimeBiasStructT_v02 zGpsGlo;

  GnssSingleInterGnssTimeBiasStructT_v02 zGpsBds;

  GnssSingleInterGnssTimeBiasStructT_v02 zBdsGlo;

  GnssSingleInterGnssTimeBiasStructT_v02 zGpsGal;

  GnssSingleInterGnssTimeBiasStructT_v02 zGalGlo;

  GnssSingleInterGnssTimeBiasStructT_v02 zGalBds;
  }GnssInterGnssTimeBiasStructT_v02;

typedef struct {

  GpsTimeStructT_v02 zGpsTime;

  GloTimeStructT_v02 zGloTime;

  BdsTimeStructT_v02 zBdsTime;

  GalTimeStructT_v02 zGalTime;

  GnssInterGnssTimeBiasStructT_v02 zGnssTimeBias;
}GnssTimeStructT_v02;

typedef enum {
  SRCOFFREQENUMT_MIN_ENUM_VAL_V02 = -2147483647, /**< To force a 32 bit signed enum.  Do not change or use*/
  FREQ_SRC_INVALID_V02 = 0,
  FREQ_SRC_TRANSFER_V02 = 1,
  FREQ_SRC_EXTERNAL_V02 = 2,
  FREQ_SRC_GPS_SV_MEAS_V02 = 3,
  FREQ_SRC_GLO_SV_MEAS_V02 = 4,
  FREQ_SRC_PE_CLK_REPORT_V02 = 5,
  FREQ_SRC_UNKNOWN_V02 = 6,
  FREQ_SRC_MAX_V02 = 7,
  SRCOFFREQENUMT_MAX_ENUM_VAL_V02 = 2147483647 /**< To force a 32 bit signed enum.  Do not change or use*/
}SrcOfFreqEnumT_v02;

typedef struct {

  float ClkFreqBias;

  float ClkFreqUnc;

  SrcOfFreqEnumT_v02 SourceOfFreq;
}GnssFreqStructT_v02;

typedef struct {

  uint8_t SystemRtcValid;

  uint32_t RefFCount;

  uint32_t NumClockResets;

  uint64_t SystemRtcMs;

  GnssTimeStructT_v02 zTime;

  GnssFreqStructT_v02 zFreq;
}GnssClockStructT_v02;

typedef struct {

  uint32_t CdmaRtcSync80CCx8;

  uint32_t GpsRtcSubMsSync80GCx32;

  uint32_t CdmaRtcLatchedCCx32;

  uint32_t GpsRtcLatchedGCx32;

  uint32_t FCount;
}GnssCDMAClockInfoStructT_v02;

typedef struct {

  float SubMs;

  uint32_t Ms;
}GnssSvTimeStructT_v02;

typedef struct {

  GnssSvTimeStructT_v02 zSvTime;

  float SvTimeUncMs;

  float SvSpeed;

  float SvSpeedUnc;
}GnssTimeSpeedStructT_v02;

typedef struct {

  uint16_t Sv;

  int8_t FreqNum;

  uint32_t SvState;

  uint8_t Observe;

  uint8_t GoodObs;

  uint8_t FilterN;

  uint8_t PreInt;

  uint8_t CSlipCount;

  uint16_t PostInt;

  uint32_t MeasStatus;

  uint32_t MeasStatus2;

  uint16_t Cno;

  uint16_t RfLoss;

  int32_t LatencyMs;

  GnssTimeSpeedStructT_v02 zFiltMeas;

  GnssTimeSpeedStructT_v02 zUnfiltMeas;

  uint8_t MultipathEstValid;

  float MultipathEst;

  uint8_t SvDirValid;

  float Azimuth;

  float Elevation;

  float DopplerAccel;

  float FineSpeed;

  float FineSpeedUnc;

  double CarrierPhase;

  uint32_t FCount;

  uint16_t ParityErrorCount;

  uint8_t GoodParity;
}GnssMeasStructT_v02;  /* Type */

typedef struct {

  uint8_t NumSvs;

  uint8_t SeqNum;

  uint8_t MaxMessageNum;

  uint32_t EngineType;

  uint8_t HwVersion;

  GnssClockStructT_v02 MeasClock;

  GnssCDMAClockInfoStructT_v02 CDMAClockInfo;

  uint32_t MeasBlkSrc;

  uint32_t zGnss_len;  /**< Must be set to # of elements in zGnss */

  GnssMeasStructT_v02 zGnss[N_ACTIVE_CHAN_V02];
}GnssMeasBlkStructT_v02;  /* Type */

typedef struct {

  /* Mandatory */
  uint32_t measRptReason;

  /* Mandatory */
  GnssMeasBlkStructT_v02 measBlk;
}OemdreGnssSvMeasInfo;  /* Message */


typedef struct{
	/* Mandatory */
	/* Position Fix/NoFix flag */
	uint8_t NoFixFlags;

	/* Optional */
	uint8_t   LGEPositionFix_valid; 					/* Position Fix report validity flag */
	GnssNavPositionStructT_v02 LGEPositionFix;          /* Position Fix report */

	/* Optional */
	uint8_t   NavSvInfo_valid; 					/* SV info validity flag */
	GnssNavSvInfoStructT_v02 NavSvInfo;          /* for SV Info */

	/* Optional */
	uint8_t   OnDeviceSensorParam_valid; 					/* sensor-related info validity flag */
	SensorParamReportStructT_v02 OnDeviceSensorParam;          /* sensor-related info */

} OemdrePositionFix;

typedef uint16_t SvPolyStatusMaskValidityT_v02;

typedef uint16_t SvPolyStatusMaskT_v02;


/**  Maximum number of satellites in a measurement block for a given system.  */
#define SV_MEAS_LIST_MAX_SIZE_V02 16
#define SV_POLY_VELOCITY_COEF_SIZE_V02 12
#define SV_POLY_XYZ_0_TH_ORDER_COEFF_SIZE_V02 3
#define SV_POLY_XYZ_N_TH_ORDER_COEFF_SIZE_V02 9
#define SV_POLY_SV_CLKBIAS_COEFF_SIZE_V02 4

typedef struct {

  /* Mandatory */
  /*  GNSS SV Polynomial Report */
  uint16_t gnssSvId;
  /**<   GNSS SV ID. \begin{itemize1}
       \item    Range:    \begin{itemize1}
         \item    For GPS:     1 to 32
         \item    For GLONASS: 65 to 96 (when the slot number to SV ID mapping is unknown, set to 255)
         \item    For SBAS:    120 to 158 and 183 to 187
         \item    For QZSS:    193 to 197
         \item    For BDS:     201 to 237
         \item    For GAL:     301 to 336
       \vspace{-0.18in} \end{itemize1} \end{itemize1} */

  /* Mandatory */
  /*  Reference Time for Polynomial Calculations */
  double T0;
  /**<    Reference time for polynomial calculations. \n
           - GPS, QZSS: Seconds in the week \n
           - GLO: Full seconds since Jan. 1, 1996 \n
           - BDS: Full seconds since Jan. 1, 2006 \n
           - GAL: Calculated from 00:00 UT on Sunday, August 22, 1999 (midnight between August 21 and August 22)
    */

  /* Mandatory */
  /*  SV Polynomial Validity Status */
  SvPolyStatusMaskValidityT_v02 svPolyFlagValid;
  /**<   Validity mask for bits in svPolyFlags. A set bit in svPolyFlagValid indicates that a
 corresponding bit in svPolyFlags has valid status information.

 Valid bitmasks: \n
      - QMI_LOC_SV_POLY_SRC_ALM_CORR_VALID (0x01) --  Validity status for QMI_LOC_SV_POLY_SRC_ALM_CORR
      - QMI_LOC_SV_POLY_GLO_STR4_VALID (0x02) --  Validity status for QMI_LOC_SV_POLY_GLO_STR4   */

  /* Mandatory */
  /*  SV Polynomial Report Status */
  SvPolyStatusMaskT_v02 svPolyFlags;
  /**<   Flags indicating the status of a polynomial report.

 Valid bitmasks: \n
      - QMI_LOC_SV_POLY_SRC_ALM_CORR (0x01) --  Polynomials based on XTRA
      - QMI_LOC_SV_POLY_GLO_STR4 (0x02) --  GLONASS string 4 has been received  */

  /* Optional */
  /*  Polynomial Coefficient's 0th Term for X, Y, and Z Coordinates */
  uint8_t polyCoeffXYZ0_valid;  /**< Must be set to true if polyCoeffXYZ0 is being passed */
  double polyCoeffXYZ0[SV_POLY_XYZ_0_TH_ORDER_COEFF_SIZE_V02];
  /**<   Polynomial coefficient's 0th term for X, Y, and Z coordinates (C0X, C0Y, C0Z). \n
             - Units: Meters
    */

  /* Optional */
  /*  Polynomial Coefficient's 1st, 2nd, and 3rd Terms for X, Y, and Z Coordinates */
  uint8_t polyCoefXYZN_valid;  /**< Must be set to true if polyCoefXYZN is being passed */
  double polyCoefXYZN[SV_POLY_XYZ_N_TH_ORDER_COEFF_SIZE_V02];
  /**<    Polynomial coefficient's 1st, 2nd, and 3rd terms for X, Y, and Z coordinates (C1X, C2X,... C2Z, C3Z). \begin{itemize1}
          \item Units: \begin{itemize1}
             \item 1st term -- Meters/second
             \item 2nd term -- Meters/second^2
             \item 3rd term -- Meters/seconds^3 \vspace{-0.18in} \end{itemize1} end{itemize1}
    */

  /* Optional */
  /*  Polynomial Coefficients for Satellite Clock Bias Correction */
  uint8_t polyCoefClockBias_valid;  /**< Must be set to true if polyCoefClockBias is being passed */
  float polyCoefClockBias[SV_POLY_SV_CLKBIAS_COEFF_SIZE_V02];
  /**<    Polynomial coefficients for satellite clock bias correction (C0T, C1T, C2T, C3T). \begin{itemize1}
          \item Units: \begin{itemize1}
             \item 0th term -- Milliseconds/second
             \item 1st term -- Milliseconds/second^2
             \item 2nd term -- Milliseconds/second^3
             \item 3rd term -- Milliseconds/second^4 \vspace{-0.18in} \end{itemize1} end{itemize1}
    */

  /* Optional */
  /*  GLONASS Frequency Number */
  uint8_t gloFrequency_valid;  /**< Must be set to true if gloFrequency is being passed */
  uint8_t gloFrequency;
  /**<   GLONASS frequency number + 7. \n
         Valid only for GLONASS systems and
         must be ignored for all other systems. \n
             - Range: 1 to 14
    */

  /* Optional */
  /*  Ephemeris Reference Time */
  uint8_t IODE_valid;  /**< Must be set to true if IODE is being passed */
  uint16_t IODE;
  /**<   Ephemeris reference time. \n
         - GPS -- Issue of data ephemeris used (unitless) \n
         - GLONASS -- Tb 7-bit \n
         - Galileo -- 10-bit
    */

  /* Optional */
  /*  Enhanced Reference Time */
  uint8_t enhancedIOD_valid;  /**< Must be set to true if enhancedIOD is being passed */
  uint32_t enhancedIOD;
  /**<   For BDS ephemeris, this is TOE.
    */

  /* Optional */
  /*  SV Position Uncertainty */
  uint8_t svPosUnc_valid;  /**< Must be set to true if svPosUnc is being passed */
  float svPosUnc;
  /**<    SV position uncertainty. \n
             - Units: Meters
    */

  /* Optional */
  /*  Iono Delay */
  uint8_t ionoDelay_valid;  /**< Must be set to true if ionoDelay is being passed */
  float ionoDelay;
  /**<   Ionospheric delay at T0. \n
             - Units: Meters
    */

  /* Optional */
  /*  Iono Delay Rate */
  uint8_t ionoDot_valid;  /**< Must be set to true if ionoDot is being passed */
  float ionoDot;
  /**<   Ionospheric delay rate. \n
             - Units: Meters/second
    */

  /* Optional */
  /*  SBAS Iono Delay */
  uint8_t sbasIonoDelay_valid;  /**< Must be set to true if sbasIonoDelay is being passed */
  float sbasIonoDelay;
  /**<   SBAS ionospheric delay at T0. \n
             - Units: Meters
    */

  /* Optional */
  /*  SBAS Iono Delay Rate */
  uint8_t sbasIonoDot_valid;  /**< Must be set to true if sbasIonoDot is being passed */
  float sbasIonoDot;
  /**<   SBAS ionospheric delay rate. \n
             - Units: Meters/second
    */

  /* Optional */
  /*  Tropospheric Delay */
  uint8_t tropoDelay_valid;  /**< Must be set to true if tropoDelay is being passed */
  float tropoDelay;
  /**<   Tropospheric delay. \n
             - Units: Meters
    */

  /* Optional */
  /*  Satellite Elevation */
  uint8_t elevation_valid;  /**< Must be set to true if elevation is being passed */
  float elevation;
  /**<   Satellite elevation at T0. \n
             - Units: Radians
    */

  /* Optional */
  /*  Satellite Elevation Rate */
  uint8_t elevationDot_valid;  /**< Must be set to true if elevationDot is being passed */
  float elevationDot;
  /**<   Satellite elevation rate. \n
             - Units: Radians/second
    */

  /* Optional */
  /*  Satellite Elevation Uncertainty */
  uint8_t elenationUnc_valid;  /**< Must be set to true if elenationUnc is being passed */
  float elenationUnc;
  /**<   SV elevation uncertainty. \n
             - Units: Radians
    */

  /* Optional */
  /*  Polynomial Coefficients for SV Velocity */
  uint8_t velCoef_valid;  /**< Must be set to true if velCoef is being passed */
  double velCoef[SV_POLY_VELOCITY_COEF_SIZE_V02];
  /**<   Polynomial coefficients for SV velocity (C0X, C1X, C2X, C3X,... C2Z, C3Z). \begin{itemize1}
         \item Units: \begin{itemize1}
            \item 0th term -- Meters/second
            \item 1st term -- Meters/second^2
            \item 2nd term -- Meters/second^3
            \item 3rd term -- Meters/second^4 \vspace{-0.18in} \end{itemize1} end{itemize1}
    */
}OemdretGnssSvPoly;

#define GPS_EHPEMERIS_SF1_RESERVED_BITS_SIZE_V02 3

typedef struct {

  uint8_t   CodeL2;            /* Status for the L2 frequency (2-bits) */
  uint8_t   Accuracy;          /* User Range Accuracy (4-bits) */
  uint8_t   SvHealth;            /* SV Health (6-bits) */
  uint16_t  Iodc;              /* Issue of Data clock (10-bits) */

  uint8_t   PcodeFlagIsValid;  /* TRUE if P-Code indication is valid */
  uint8_t   PcodeFlag;         /* P-Code indication flag (1-bit) */

  uint8_t   Sf1BitsAreValid;   /* TRUE if SF1 Reserved bits are valid */
  uint32_t 	Sf1ResrvBits[GPS_EHPEMERIS_SF1_RESERVED_BITS_SIZE_V02];   /* Reserved bits (87-bits. First bit in LSB) */

  uint8_t 	TimeOfGroupDelaydIsValid;        /* Time of Group Delay validity flag */
  uint8_t   TimeOfGroupDelay;               /* Time of Group Delay (8-bits) */

  uint16_t  TimeOfClock;               /* Time of clock (16-bits) */

  uint8_t   AccelerationCoeff;               /* Clock acceleration coefficient (8-bits) */
  uint16_t  DriftCoeff;               /* Clock drift coefficient (16-bits) */
  uint32_t 	ClkBiasCoeff;               /* Clock bias coefficient (22-bits) */

  uint8_t   IODE;              /* Issue of data ephemeris tag (8-bits) */

  uint16_t  CorrectionSinOrbitRadius;               /* Amplitude of the sine harmonic correction term to Orbit Radius (16-bits) */
  uint16_t  DeltaN;            /* Mean motion difference from computed value (16-bits) */
  uint32_t  M0;                /* Mean anomaly at reference time (32-bits) */
  uint16_t  CorrectionCosLatitude;               /* Amplitude of the cosine harmonic correction term to argument of latitude (16-bits) */
  uint32_t  Eccentricity;                 /* Orbital Eccentricity (32-bits) */
  uint16_t  CorrectionSinLatitude;               /* Amplitude of the sine harmonic correction term to argument of latitude (16-bits) */
  uint32_t  SqrtAxis;             /* Square-root of the Semi-Major axis (32-bits) */
  uint16_t  TimeOfEphemeris;               /* Reference time of Ephemeris (16-bits) */

  uint8_t 	FitIntervalIsValid;			/* Fit Interval validity flag */
  uint8_t   FitInterval;   				/* Fit Interval (1-bit) */

  uint8_t   AodoIsValid;       /* AODO validity flag */
  uint8_t   Aodo;              /* Age of Data offset (5-bits) */

  uint16_t  CorrectionCosAngleInclination;               /* Amplitude of the cosine harmonic correction term to angle of inclination (16-bits) */
  uint32_t 	Omega0;            /* Longitude of the ascending node of orbit plane at weekly epoch (32-bits) */
  uint16_t  CorrectionSinAngleInclination;               /* Amplitude of the sine harmonic correction term to angle of inclination (16-bits) */
  uint32_t  I0;                /* Inclination angle at reference time (32-bits) */
  uint16_t  CorrectionCosOrbitRadius;               /* Amplitude of the cosine harmonic correction term to Orbit Radius (16-bits) */
  uint32_t  Omega;             /* Argument of Perigee (32-bits) */
  uint32_t  OmegaDot;          /* Rate of Right Ascension (24-bits) */
  uint16_t  Idot;              /* Rate of inclination angle (14-bits) */

  uint8_t 	GpsWeekIsValid;    /* TRUE if the week number specified is valid */
  uint16_t  GpsWeek;           /* Unambiguous GPS week */

}GpsEphemerisStructT_v02;  /* Type */

#define LGE_GLONASS_EHPEMERIS_XYZ_COORDINATE_V02 3

typedef struct {

  uint8_t FlagFilledMask;     /* Flags for optional data */
    /*
    union
    {
    uint8 u_FilledMask;
    struct
    {
      uint8  u_GloMFlag : 1;
      uint8  u_TimeSrcPFlag : 1;
      uint8  u_FtFlag : 1;
      uint8  u_NtFlag : 1;
      uint8  u_P4Flag : 1;
      uint8  u_LnFlag : 1;
      uint8  : 2;
    } z_FilledMask;
    } z_Mask;
    */
  uint8_t  Tb;        /* GLONASS eph reference time tb: 7-bit LSBs*/
  uint8_t  GlonassM;      /* Satellite type (GLONASS-M or not), M : 2-bit LSBs*/
  uint8_t  TimeSrcP;  /* Indication the satellite operation mode in respect of
                         time parameters P, 2-bit LSBs*/
  uint8_t  Bn;        /* Health flag Bn: 3-bit LSBs, only check bit 2 */
  uint8_t  L1L2;      /* Time diff between the L2 and L1 transmitters: 5-bit,
                         LSB0-LSB3 is data bit, scale factor 2^-30, LSB4 is
                         the sign bit, Delat_Tao_n */
  uint8_t  P1;        /* Indication of time interval between adjacent eph P1,
                         2-bit LSBs*/
  uint8_t  P2;        /* interval indicator P2: 1 bit, LSB */
  uint8_t  Ln;        /* Additional health flag only available on GLONASS-M
                         satellite, 1 bit LSB*/
  uint8_t  FreqNum;   /* Frequency number: 5-bit LSBs*/
                      /* If the air data is 5-bit string, do a straight copy
                         to the 5-bit LSB.
                         If the air data is int, use translation below
                         -1 ~ -7: 0B11111 - 0B11001
                         0  ~ 13: 0B00000 - 0B01101
                         All other numbers are invalid for eph injection.
                         Don't inject */
  uint8_t  Ft;        /* FT is a parameter shown the URE at time tb: 4-bit
                         LSBs */
  uint8_t  Acc[LGE_GLONASS_EHPEMERIS_XYZ_COORDINATE_V02];    /* acceleration due to lunar-solar gravitational
                         perturbation, 5-bit LSBs, X/Y/ZDotDot_n */
  uint16_t Nt;        /* calendar number of day within four-year interval
                         starting from the 1st of January in a leap year,
                         11-bit LSBs */
  uint16_t FreqOff;   /* (f(pre)-f(nom))/f(nom), unscaled, 11-bit LSBs,
                         Gamma_n */
  uint32_t ClkCorr;   /* Satellite clock correction: 22-bit LSBs, Tao_n */
  uint32_t SatPos[LGE_GLONASS_EHPEMERIS_XYZ_COORDINATE_V02]; /* Satellite position-xyz, 27-bit LSBs each, X/Y/Zn; */
  uint32_t SatVel[LGE_GLONASS_EHPEMERIS_XYZ_COORDINATE_V02]; /* Satellite velocity, 24-bit LSBs each, X/Y/ZDot_n */
  uint8_t  En;        /* Age of Eph in days, 5-bit LSBs */
  uint8_t  P4;        /* Flag P4,1-bit LSB */

}GloEphemerisStructT_v02;  /* Type */

typedef struct {
  uint8_t Sv;
  uint16_t BdsWeek;
  uint32_t Toe;
  uint32_t Toc;
  uint8_t Iode;
  uint8_t Iodc;
  uint8_t Health;
  uint8_t URAI;
  uint32_t SqrtA;
  uint32_t E;
  uint32_t Omega;
  uint16_t DeltaN;
  uint32_t M0;
  uint32_t Omega0;
  uint32_t OmegaDot;
  uint32_t I0;
  uint16_t Idot;
  uint32_t Cuc;
  uint32_t Cus;
  uint32_t Crc;
  uint32_t Crs;
  uint32_t Cic;
  uint32_t Cis;
  uint32_t A0;
  uint32_t A1;
  uint16_t A2;
  uint16_t Tgd;
}BdsEphemerisStruct_v02;  /* Type */


typedef struct {

  uint16_t SvId;
  uint16_t Iode;
  uint16_t Toe;
  uint32_t M0;
  uint16_t DeltaN;
  uint32_t E;
  uint32_t SqrtA;
  uint32_t Omega0;
  uint32_t OmegaDot;
  uint32_t Omega;
  uint32_t I0;
  uint16_t IDot;
  uint16_t Cic;
  uint16_t Cis;
  uint16_t Crc;
  uint16_t Crs;
  uint16_t Cuc;
  uint16_t Cus;
  uint16_t Week;
  uint8_t Sisa;
  uint8_t Health;
  uint16_t Bgd;
  uint16_t Toc;
  uint8_t Af2;
  uint32_t Af1;
  uint32_t Af0;
}GalEphemerisStruct_v02;  /* Type */

typedef struct {
  uint8_t gnssType;
  uint8_t svId;
  int8_t freqChannelNum;
  float cnoDB;
  double codePhase;
  float codePhaseUnc;
  float doppler;
  float dopplerUnc;
  uint32_t measStatus;
  double carrPhaseCycles;
  uint8_t cycleSlipCount;
}OemcpeStructT_v02;  /* Type */

typedef struct
{
  /* Mandatory */
  uint8_t   SvPRN;                /* SV PRN */

  /* Optional */
  uint8_t   GpsEphemerisValidFlag; 					/* GPS Ephemeris report validity flag */
  GpsEphemerisStructT_v02 LGEGpsEphemeris;          /* GPS Ephemeris report */

} GpsEphemeris;

typedef struct
{
  /* Mandatory */
  uint8_t   SvID;                /* SV ID */

  /* Optional */
  uint8_t   GloEphemerisValidFlag;          /* GLONASS Ephemeris report validity flag */
  GloEphemerisStructT_v02 LGEGloEphemeris;          /* GLONASS Ephemeris report */

} GloEphemeris;

typedef struct {

  /* Mandatory */
  BdsEphemerisStruct_v02 LGEBdsEphemeris;
} BdsEphemeris;  /* Message */

typedef struct {

  /* Mandatory */
  GalEphemerisStruct_v02 LGEGalEphemeris;
}GalEphemeris;  /* Message */

#define N_CPE_MAX_SV_V02 46
#define GNSS_STATUS_RESERVED_DATA_NUM_LENGTH_V03 100

typedef struct {

  uint8_t  version;	 /* Version Number of Structure */
  uint32_t fCount;	 /* Receiver Ms count for debugging purpose */
  uint16_t gpsWeek;		/* GPS week number [Unknown = 65535] */
  uint32_t gpsMsec;	/* GPS msec [msec] */
  float clkTimeBias;  /* Clock bias [msec] where
     GPS Time (msec) = w_GpsWeek*WEEK_MSEC + q_GpsMsec - f_ClkTimeBias
  */
  float clkTimeUncMs;  /* Clock Time bias Uncertainty [msec] */
  float clkDrift;  /* Clock Drift [s/s] */
  float clkDriftUnc;  /* 1 sided max Clock Drift uncertainty [s/s] */
  uint8_t numValidReports; /* Number of valid reports in z_Meas */

  uint32_t meas_len;  /**< Must be set to # of elements in meas */
  OemcpeStructT_v02 meas[N_CPE_MAX_SV_V02];
}Oemcpe;

typedef struct {
  /* Mandatory */
  int32_t adc5_read_error;	 		/* 0 : No error */
  int32_t adc5;
  int32_t pt_sense_read_error;	 	/* 0 : No error */
  int32_t pt_sense;
}GPSAntennaReport;

typedef struct {
  /* Mandatory */
  uint32_t status;
  uint32_t reserved[GNSS_STATUS_RESERVED_DATA_NUM_LENGTH_V03];
}GnssStatusReport;

//LGE_GNSS_LOCAPI/////////////////////////////////////////////////////////////////////////////

/** Callback for oemdre gnss sv measurement infomation */
typedef void(* oemdre_gnss_svmeas_callback)(OemdreGnssSvMeasInfo* svMeas_info);
/** Callback for oemdre position fix infomation */
typedef void(* oemdre_position_fix_callback)(OemdrePositionFix* fix_info);
/** Callback for oemdre gnss sv poly infomation */
typedef void(* oemdre_gnss_svpoly_callback)(OemdretGnssSvPoly* svPoly_info);
/** Callback for gps ephemeris infomation */
typedef void(* oemdre_gps_ephemeris_callback)(GpsEphemeris* gpsEph_info);
/** Callback for glonass ephemeris infomation */
typedef void(* oemdre_glo_ephemeris_callback)(GloEphemeris* gloEph_info);
/** Callback for beidou ephemeris infomation */
typedef void(* oemdre_bds_ephemeris_callback)(BdsEphemeris* bdsEph_info);
/** Callback for galileo ephemeris infomation */
typedef void(* oemdre_gal_ephemeris_callback)(GalEphemeris* galEph_info);
/** Callback for oemcpe report infomation */
typedef void(* oemdre_cpe_report_callback)(Oemcpe* cpe_info);
/** Callback for gps antenna adb value */
typedef void(* oemdre_gps_antenna_adc_callback)(GPSAntennaReport* value);
/** Callback for gnss status report value */
typedef void(* oemdre_gnss_status_report_callback)(GnssStatusReport* status_info);
/** Callback for gnss nmea report value */
typedef void(* oemdre_nmea_callback)(GpsUtcTime timestamp, const char* nmea, int length);

/** GPS OEMDRE callback structure. */
typedef struct {
    /** set to sizeof(GnssOEMDRECallbacks) */
    size_t size;
    oemdre_gnss_svmeas_callback         oemdre_gnss_svmeas_cb;
    oemdre_position_fix_callback        oemdre_position_fix_report_cb;
    oemdre_gnss_svpoly_callback         oemdre_gnss_svpoly_cb;
    oemdre_gps_ephemeris_callback       oemdre_gps_ephemeris_cb;
    oemdre_glo_ephemeris_callback       oemdre_glo_ephemeris_cb;
    oemdre_bds_ephemeris_callback       oemdre_bds_ephemeris_cb;
    oemdre_gal_ephemeris_callback       oemdre_gal_ephemeris_cb;
    oemdre_cpe_report_callback          oemdre_cpe_report_cb;
    oemdre_gps_antenna_adc_callback     oemdre_gnss_ant_adc_cb;
    oemdre_gnss_status_report_callback  oemdre_status_report_cb;
	oemdre_nmea_callback                oemdre_nmea_report_cb;
} GnssOEMDRECallbacks;

/**
 * Extended interface for GNSS OEMDRE support.
 */
typedef struct {
    /** Set to sizeof(GnssOEMDREInterface) */
    size_t size;
    int (*init) (GnssOEMDRECallbacks* callbacks);
    void (*close) (void);
} GnssOEMDREInterface;

/**
 ********************************************************************************************
 *************************** LGE Define *****************************************************
 ********************************************************************************************
 */


/**
 * Name for the GPS XTRA interface.
 */
#define GPS_XTRA_INTERFACE      "gps-xtra"

/**
 * Name for the GPS DEBUG interface.
 */
#define GPS_DEBUG_INTERFACE      "gps-debug"

/**
 * Name for the AGPS interface.
 */
#define AGPS_INTERFACE      "agps"

/**
 * Name of the Supl Certificate interface.
 */
#define SUPL_CERTIFICATE_INTERFACE  "supl-certificate"

/**
 * Name for NI interface
 */
#define GPS_NI_INTERFACE "gps-ni"

/**
 * Name for the AGPS-RIL interface.
 */
#define AGPS_RIL_INTERFACE      "agps_ril"

/**
 * Name for the GPS_Geofencing interface.
 */
#define GPS_GEOFENCING_INTERFACE   "gps_geofencing"

/**
 * Name of the QMI LOC interface.
 */
//#define QMI_LOC_INTERFACE   "qmi_loc_interface"

/**
 * Name of the QMI LOC interface.
 */
//#define QMI_LOC_SV_INTERFACE   "qmi_loc_sv_interface"

/**
 * Name of the GPS Measurements interface.
 */
#define GPS_MEASUREMENT_INTERFACE   "gps_measurement"

/**
 * Name of the GPS navigation message interface.
 */
#define GPS_NAVIGATION_MESSAGE_INTERFACE     "gps_navigation_message"

/**
 * Name of the GNSS/GPS configuration interface.
 */
#define GNSS_CONFIGURATION_INTERFACE     "gnss_configuration"

/**
 * Name of the GPS A7 (loc-hal QMI ) interface.
 */
#define GPS_MASTER_INTERFACE     "gps_master"

/**
 * Name of the GPS Q6 (loc-hal QMI ) interface.
 */
#define GPS_SUB_INTERFACE     "gps_sub"

/**
 * Name of the GPS VSS LGE command interface.
 */
#define GPS_LGE_COMMAND_INTERFACE     "gps_lge_command"

/**
 * Name of the GPS Vehicle interface.
 */
#define GPS_MASTER_VIF_INTERFACE     "gnss_vif"

/**
 * Name of the GPS QDR interface.
 */
#define GPS_MASTER_QDR_INTERFACE     "gnss_qdr"

/**
 * Name of the GNSS OEMDRE interface.
 */
#define GPS_OEMDRE_INTERFACE     "gnss_oemdre"



/** Represents a location. */
typedef struct {
    /** set to sizeof(GpsLocation) */
    size_t          size;
    /** Contains GpsLocationFlags bits. */
    uint16_t        flags;
    /** Represents latitude in degrees. */
    double          latitude;
    /** Represents longitude in degrees. */
    double          longitude;
    /**
     * Represents altitude in meters above the WGS 84 reference ellipsoid.
     */
    double          altitude;
    /** Represents speed in meters per second. */
    float           speed;
    /** Represents heading in degrees. */
    float           bearing;
    /** Represents expected accuracy in meters. */
    float           accuracy;
    /** Timestamp for the location fix. */
    GpsUtcTime      timestamp;

    /** LGE Extension Parameter */
	ExtGpsLocation ext_location;

} GpsLocation;

/** Represents the status. */
typedef struct {
    /** set to sizeof(GpsStatus) */
    size_t          size;
    GpsStatusValue status;
} GpsStatus;

/**
 * Legacy struct to represents SV information.
 * Deprecated, to be removed in the next Android release.
 * Use GnssSvInfo instead.
 */
typedef struct {
    /** set to sizeof(GpsSvInfo) */
    size_t          size;
    /** Pseudo-random number for the SV. */
    int     prn;
    /** Signal to noise ratio. */
    float   snr;
    /** Elevation of SV in degrees. */
    float   elevation;
    /** Azimuth of SV in degrees. */
    float   azimuth;
} GpsSvInfo;

typedef struct {
    /** set to sizeof(GnssSvInfo) */
    size_t size;

    /**
     * Pseudo-random number for the SV, or FCN/OSN number for Glonass. The
     * distinction is made by looking at constellation field. Values should be
     * in the range of:
     *
     * - GPS:     1-32
     * - SBAS:    120-151, 183-192
     * - GLONASS: 1-24, the orbital slot number (OSN), if known.  Or, if not:
     *            93-106, the frequency channel number (FCN) (-7 to +6) offset by + 100
     *            i.e. report an FCN of -7 as 93, FCN of 0 as 100, and FCN of +6 as 106.
     * - QZSS:    193-200
     * - Galileo: 1-36
     * - Beidou:  1-37
     */
    int16_t svid;

    /**
     * Defines the constellation of the given SV. Value should be one of those
     * GNSS_CONSTELLATION_* constants
     */
    GnssConstellationType constellation;

    GnssSignalType signal_type;

    /**
     * Carrier-to-noise density in dB-Hz, typically in the range [0, 63].
     * It contains the measured C/N0 value for the signal at the antenna port.
     *
     * This is a mandatory value.
     */
    float c_n0_dbhz;

    /** Elevation of SV in degrees. */
    float elevation;

    /** Azimuth of SV in degrees. */
    float azimuth;

    GnssSvStatusType status;

    /**
     * Contains additional data about the given SV. Value should be one of those
     * GNSS_SV_FLAGS_* constants
     */
    GnssSvFlags flags;

    int glo_frequency;

    /**<   Health status.
         Range -- 0 to 1 \n
         - 0 -- Unhealthy \n
         - 1 -- Healthy 
         */
	uint8_t healthStatus;

} GnssSvInfo;

/**
 * Legacy struct to represents SV status.
 * Deprecated, to be removed in the next Android release.
 * Use GnssSvStatus instead.
 */
typedef struct {
    /** set to sizeof(GpsSvStatus) */
    size_t size;
    int num_svs;
    GpsSvInfo sv_list[GPS_MAX_SVS];
    uint32_t ephemeris_mask;
    uint32_t almanac_mask;
    uint32_t used_in_fix_mask;
} GpsSvStatus;

/**
 * Represents SV status.
 */
typedef struct {
    /** set to sizeof(GnssSvStatus) */
    size_t size;

    /** Number of GPS SVs currently visible, refers to the SVs stored in sv_list */
    int num_svs;
    /**
     * Pointer to an array of SVs information for all GNSS constellations,
     * except GPS, which is reported using sv_list
     */
    GnssSvInfo gnss_sv_list[GNSS_MAX_SVS];

    /** LGE Extension Parameter */
    GnssClockStruct MeasClock;

} GnssSvStatus;

/* CellID for 2G, 3G and LTE, used in AGPS. */
typedef struct {
    AGpsRefLocationType type;
    /** Mobile Country Code. */
    uint16_t mcc;
    /** Mobile Network Code .*/
    uint16_t mnc;
    /** Location Area Code in 2G, 3G and LTE. In 3G lac is discarded. In LTE,
     * lac is populated with tac, to ensure that we don't break old clients that
     * might rely in the old (wrong) behavior.
     */
    uint16_t lac;
    /** Cell id in 2G. Utran Cell id in 3G. Cell Global Id EUTRA in LTE. */
    uint32_t cid;
    /** Tracking Area Code in LTE. */
    uint16_t tac;
    /** Physical Cell id in LTE (not used in 2G and 3G) */
    uint16_t pcid;
} AGpsRefLocationCellID;

typedef struct {
    uint8_t mac[6];
} AGpsRefLocationMac;

/** Represents ref locations */
typedef struct {
    AGpsRefLocationType type;
    union {
        AGpsRefLocationCellID   cellID;
        AGpsRefLocationMac      mac;
    } u;
} AGpsRefLocation;

/**
 * Callback with location information. Can only be called from a thread created
 * by create_thread_cb.
 */
typedef void (* gps_location_callback)(GpsLocation* location);

/**
 * Callback with status information. Can only be called from a thread created by
 * create_thread_cb.
 */
typedef void (* gps_status_callback)(GpsStatus* status);

/**
 * Legacy callback with SV status information.
 * Can only be called from a thread created by create_thread_cb.
 *
 * This callback is deprecated, and will be removed in the next release. Use
 * gnss_sv_status_callback() instead.
 */
typedef void (* gps_sv_status_callback)(GpsSvStatus* sv_info);

/**
 * Callback with SV status information.
 * Can only be called from a thread created by create_thread_cb.
 */
typedef void (* gnss_sv_status_callback)(GnssSvStatus* sv_info);

/**
 * Callback for reporting NMEA sentences. Can only be called from a thread
 * created by create_thread_cb.
 */
typedef void (* gps_nmea_callback)(GpsUtcTime timestamp, const char* nmea, int length);

/**
 * Callback to inform framework of the GPS engine's capabilities. Capability
 * parameter is a bit field of GPS_CAPABILITY_* flags.
 */
typedef void (* gps_set_capabilities)(uint32_t capabilities);

/**
 * Callback utility for acquiring the GPS wakelock. This can be used to prevent
 * the CPU from suspending while handling GPS events.
 */
typedef void (* gps_acquire_wakelock)(void);

/** Callback utility for releasing the GPS wakelock. */
typedef void (* gps_release_wakelock)(void);

/** Callback for requesting NTP time */
typedef void (* gps_request_utc_time)(void);

/**
 * Callback for creating a thread that can call into the Java framework code.
 * This must be used to create any threads that report events up to the
 * framework.
 */
typedef pthread_t (* gps_create_thread)(const char* name, void (*start)(void *), void* arg);

/**
 * Provides information about how new the underlying GPS/GNSS hardware and
 * software is.
 *
 * This information will be available for Android Test Applications. If a GPS
 * HAL does not provide this information, it will be considered "2015 or
 * earlier".
 *
 * If a GPS HAL does provide this information, then newer years will need to
 * meet newer CTS standards. E.g. if the date are 2016 or above, then N+ level
 * GpsMeasurement support will be verified.
 */
typedef struct {
    /** Set to sizeof(GnssSystemInfo) */
    size_t   size;
    /* year in which the last update was made to the underlying hardware/firmware
     * used to capture GNSS signals, e.g. 2016 */
    uint16_t year_of_hw;
} GnssSystemInfo;

/**
 * Callback to inform framework of the engine's hardware version information.
 */
typedef void (*gnss_set_system_info)(const GnssSystemInfo* info);

/** New GPS callback structure. */
typedef struct {
    /** set to sizeof(GpsCallbacks) */
    size_t      size;
    gps_location_callback location_cb;
    gps_status_callback status_cb;
    gps_sv_status_callback sv_status_cb;
    gps_nmea_callback nmea_cb;
    gps_set_capabilities set_capabilities_cb;
    gps_acquire_wakelock acquire_wakelock_cb;
    gps_release_wakelock release_wakelock_cb;
    gps_create_thread create_thread_cb;
    gps_request_utc_time request_utc_time_cb;

    gnss_set_system_info set_system_info_cb;
    gnss_sv_status_callback gnss_sv_status_cb;
} GpsCallbacks;

/** Represents the standard GPS interface. */
typedef struct {
    /** set to sizeof(GpsInterface) */
    size_t          size;
    /**
     * Opens the interface and provides the callback routines
     * to the implementation of this interface.
     */
    int   (*init)( GpsCallbacks* callbacks );

    /** Starts navigating. */
    int   (*start)( void );

    /** Stops navigating. */
    int   (*stop)( void );

    /** Closes the interface. */
    void  (*cleanup)( void );

    /** Injects the current time. */
    int   (*inject_time)(GpsUtcTime time, int64_t timeReference,
                         int uncertainty);

    /**
     * Injects current location from another location provider (typically cell
     * ID). Latitude and longitude are measured in degrees expected accuracy is
     * measured in meters
     */
    int  (*inject_location)(double latitude, double longitude, float accuracy);

    /**
     * Specifies that the next call to start will not use the
     * information defined in the flags. GPS_DELETE_ALL is passed for
     * a cold start.
     */
    void  (*delete_aiding_data)(GnssAidingDataSvMask svMask, GnssAidingDataCommonMask mask);
    /**
     * min_interval represents the time between fixes in milliseconds.
     * preferred_accuracy represents the requested fix accuracy in meters.
     * preferred_time represents the requested time to first fix in milliseconds.
     *
     * 'mode' parameter should be one of GPS_POSITION_MODE_MS_BASED
     * or GPS_POSITION_MODE_STANDALONE.
     * It is allowed by the platform (and it is recommended) to fallback to
     * GPS_POSITION_MODE_MS_BASED if GPS_POSITION_MODE_MS_ASSISTED is passed in, and
     * GPS_POSITION_MODE_MS_BASED is supported.
     */
    int   (*set_position_mode)(GpsPositionMode mode, GpsPositionRecurrence recurrence,
            uint32_t min_interval, uint32_t preferred_accuracy, uint32_t preferred_time);

    /** Get a pointer to extension information. */
    const void* (*get_extension)(const char* name);
} GpsInterface;

#ifdef LGE_XTRA
/**
 * Callback to request the client to download XTRA data. The client should
 * download XTRA data and inject it by calling inject_xtra_data(). Can only be
 * called from a thread created by create_thread_cb.
 */
typedef void(* XtraRequestCallbacksType)(int request_type);
typedef void(* XtraDataCallbacksType)(int data_event_type);
typedef void(* XtraTimeCallbacksType)(int time_event_type);

/** Callback structure for the XTRA interface. */
typedef struct {
    XtraRequestCallbacksType RequestCallback;
    XtraDataCallbacksType LocalDataCallback;
    XtraTimeCallbacksType LocalTimeCallback;
} GpsXtraCallbacks;

/** Extended interface for XTRA support. */
typedef struct {
    /** set to sizeof(GpsXtraInterface) */
    size_t          size;
    /**
     * Opens the XTRA interface and provides the callback routines
     * to the implementation of this interface.
     */
    int  (*init)( GpsXtraCallbacks* callbacks );
    /** Injects XTRA data into the GPS. */
    int  (*inject_xtra_data)( char* data, int length );
} GpsXtraInterface;
#endif //LGE_XTRA

/** Extended interface for VSS LGE command support. */
typedef struct {
    /** set to sizeof(VSSCommandInterface) */
    size_t          size;

    /** LGE VSS command. */
    void  (*VSS_LGE_command)(int32_t cmd, int32_t param, int32_t *status, int32_t *result);
} VSSCommandInterface;


/** Extended interface for Vehicle Interface support. */
typedef struct {
	uint8_t  sessionId;
	uint8_t  speed_len;
	uint16_t speed;
	uint8_t  speed_err_len;
	uint16_t speed_err;
	uint8_t  yaw_len;
	uint16_t yaw;
	uint8_t  yaw_err_len;
	uint16_t yaw_err;
	uint16_t gear;
} VifPosSetPositioningInfo;

typedef struct {
    /** set to sizeof(GnssVifInterface) */
    size_t          size;
    int  (*loc_vif_pos_reset)(uint8_t sessionId);
	int  (*loc_vif_pos_set_positioning_info)(VifPosSetPositioningInfo possetpos);
    int  (*loc_vif_general_command_req)(int32_t cmd, int32_t param, int32_t *status, int32_t *result);
} GnssVifInterface;


/** Extended interface for DEBUG support. */
typedef struct {
    /** set to sizeof(GpsDebugInterface) */
    size_t          size;

    /**
     * This function should return any information that the native
     * implementation wishes to include in a bugreport.
     */
    size_t (*get_internal_state)(char* buffer, size_t bufferSize);
} GpsDebugInterface;

/*
 * Represents the status of AGPS augmented to support IPv4 and IPv6.
 */
typedef struct {
    /** set to sizeof(AGpsStatus) */
    size_t                  size;

    AGpsType                type;
    AGpsStatusValue         status;

    /**
     * Must be set to a valid IPv4 address if the field 'addr' contains an IPv4
     * address, or set to INADDR_NONE otherwise.
     */
    uint32_t                ipaddr;

    /**
     * Must contain the IPv4 (AF_INET) or IPv6 (AF_INET6) address to report.
     * Any other value of addr.ss_family will be rejected.
     */
    struct sockaddr_storage addr;
} AGpsStatus;

/**
 * Callback with AGPS status information. Can only be called from a thread
 * created by create_thread_cb.
 */
typedef void (* agps_status_callback)(AGpsStatus* status);

/** Callback structure for the AGPS interface. */
typedef struct {
    agps_status_callback status_cb;
    gps_create_thread create_thread_cb;
} AGpsCallbacks;

/**
 * Extended interface for AGPS support, it is augmented to enable to pass
 * extra APN data.
 */
typedef struct {
    /** set to sizeof(AGpsInterface) */
    size_t size;

    /**
     * Opens the AGPS interface and provides the callback routines to the
     * implementation of this interface.
     */
    void (*init)(AGpsCallbacks* callbacks);
    /**
     * Deprecated.
     * If the HAL supports AGpsInterface_v2 this API will not be used, see
     * data_conn_open_with_apn_ip_type for more information.
     */
    int (*data_conn_open)(const char* apn);
    /**
     * Notifies that the AGPS data connection has been closed.
     */
    int (*data_conn_closed)(void);
    /**
     * Notifies that a data connection is not available for AGPS.
     */
    int (*data_conn_failed)(void);
    /**
     * Sets the hostname and port for the AGPS server.
     */
    int (*set_server)(AGpsType type, const char* hostname, int port);

    /**
     * Notifies that a data connection is available and sets the name of the
     * APN, and its IP type, to be used for SUPL connections.
     */
    int (*data_conn_open_with_apn_ip_type)(
            const char* apn,
            ApnIpType apnIpType);
} AGpsInterface;

/** Error codes associated with certificate operations */
#define AGPS_CERTIFICATE_OPERATION_SUCCESS               0
#define AGPS_CERTIFICATE_ERROR_GENERIC                -100
#define AGPS_CERTIFICATE_ERROR_TOO_MANY_CERTIFICATES  -101

/** A data structure that represents an X.509 certificate using DER encoding */
typedef struct {
    size_t  length;
    u_char* data;
} DerEncodedCertificate;

/**
 * A type definition for SHA1 Fingerprints used to identify X.509 Certificates
 * The Fingerprint is a digest of the DER Certificate that uniquely identifies it.
 */
typedef struct {
    u_char data[20];
} Sha1CertificateFingerprint;

/** AGPS Interface to handle SUPL certificate operations */
typedef struct {
    /** set to sizeof(SuplCertificateInterface) */
    size_t size;

    /**
     * Installs a set of Certificates used for SUPL connections to the AGPS server.
     * If needed the HAL should find out internally any certificates that need to be removed to
     * accommodate the certificates to install.
     * The certificates installed represent a full set of valid certificates needed to connect to
     * AGPS SUPL servers.
     * The list of certificates is required, and all must be available at the same time, when trying
     * to establish a connection with the AGPS Server.
     *
     * Parameters:
     *      certificates - A pointer to an array of DER encoded certificates that are need to be
     *                     installed in the HAL.
     *      length - The number of certificates to install.
     * Returns:
     *      AGPS_CERTIFICATE_OPERATION_SUCCESS if the operation is completed successfully
     *      AGPS_CERTIFICATE_ERROR_TOO_MANY_CERTIFICATES if the HAL cannot store the number of
     *          certificates attempted to be installed, the state of the certificates stored should
     *          remain the same as before on this error case.
     *
     * IMPORTANT:
     *      If needed the HAL should find out internally the set of certificates that need to be
     *      removed to accommodate the certificates to install.
     */
    int  (*install_certificates) ( const DerEncodedCertificate* certificates, size_t length );

    /**
     * Notifies the HAL that a list of certificates used for SUPL connections are revoked. It is
     * expected that the given set of certificates is removed from the internal store of the HAL.
     *
     * Parameters:
     *      fingerprints - A pointer to an array of SHA1 Fingerprints to identify the set of
     *                     certificates to revoke.
     *      length - The number of fingerprints provided.
     * Returns:
     *      AGPS_CERTIFICATE_OPERATION_SUCCESS if the operation is completed successfully.
     *
     * IMPORTANT:
     *      If any of the certificates provided (through its fingerprint) is not known by the HAL,
     *      it should be ignored and continue revoking/deleting the rest of them.
     */
    int  (*revoke_certificates) ( const Sha1CertificateFingerprint* fingerprints, size_t length );
} SuplCertificateInterface;

/** Represents an NI request */
typedef struct {
    /** set to sizeof(GpsNiNotification) */
    size_t          size;

    /**
     * An ID generated by HAL to associate NI notifications and UI
     * responses
     */
    int             notification_id;

    /**
     * An NI type used to distinguish different categories of NI
     * events, such as GPS_NI_TYPE_VOICE, GPS_NI_TYPE_UMTS_SUPL, ...
     */
    GpsNiType       ni_type;

    /**
     * Notification/verification options, combinations of GpsNiNotifyFlags constants
     */
    GpsNiNotifyFlags notify_flags;

    /**
     * Timeout period to wait for user response.
     * Set to 0 for no time out limit.
     */
    int             timeout;

    /**
     * Default response when time out.
     */
    GpsUserResponseType default_response;

    /**
     * Requestor ID
     */
    char            requestor_id[GPS_NI_SHORT_STRING_MAXLEN];

    /**
     * Notification message. It can also be used to store client_id in some cases
     */
    char            text[GPS_NI_LONG_STRING_MAXLEN];

    /**
     * Client name decoding scheme
     */
    GpsNiEncodingType requestor_id_encoding;

    /**
     * Client name decoding scheme
     */
    GpsNiEncodingType text_encoding;

    /**
     * A pointer to extra data. Format:
     * key_1 = value_1
     * key_2 = value_2
     */
    char           extras[GPS_NI_LONG_STRING_MAXLEN];

} GpsNiNotification;

/**
 * Callback with NI notification. Can only be called from a thread created by
 * create_thread_cb.
 */
typedef void (*gps_ni_notify_callback)(GpsNiNotification *notification);

/** GPS NI callback structure. */
typedef struct
{
    /**
     * Sends the notification request from HAL to GPSLocationProvider.
     */
    gps_ni_notify_callback notify_cb;
    gps_create_thread create_thread_cb;
} GpsNiCallbacks;

/**
 * Extended interface for Network-initiated (NI) support.
 */
typedef struct
{
    /** set to sizeof(GpsNiInterface) */
    size_t          size;

   /** Registers the callbacks for HAL to use. */
   void (*init) (GpsNiCallbacks *callbacks);

   /** Sends a response to HAL. */
   void (*respond) (int notif_id, GpsUserResponseType user_response);
} GpsNiInterface;

#ifdef _NOT_USED
struct gps_device_t {
    struct hw_device_t common;

    /**
     * Set the provided lights to the provided values.
     *
     * Returns: 0 on succes, error code on failure.
     */
    const GpsInterface* (*get_gps_interface)(struct gps_device_t* dev);
};
#endif

extern const GpsInterface* get_gps_interface(void);

#define AGPS_RIL_REQUEST_SETID_IMSI     (1<<0L)
#define AGPS_RIL_REQUEST_SETID_MSISDN   (1<<1L)

#define AGPS_RIL_REQUEST_REFLOC_CELLID  (1<<0L)
#define AGPS_RIL_REQUEST_REFLOC_MAC     (1<<1L)

typedef void (*agps_ril_request_set_id)(uint32_t flags);
typedef void (*agps_ril_request_ref_loc)(uint32_t flags);

typedef struct {
    agps_ril_request_set_id request_setid;
    agps_ril_request_ref_loc request_refloc;
    gps_create_thread create_thread_cb;
} AGpsRilCallbacks;

/** Extended interface for AGPS_RIL support. */
typedef struct {
    /** set to sizeof(AGpsRilInterface) */
    size_t          size;
    /**
     * Opens the AGPS interface and provides the callback routines
     * to the implementation of this interface.
     */
    void  (*init)( AGpsRilCallbacks* callbacks );

    /**
     * Sets the reference location.
     */
    void (*set_ref_location) (const AGpsRefLocation *agps_reflocation, size_t sz_struct);
    /**
     * Sets the set ID.
     */
    void (*set_set_id) (AGpsSetIDType type, const char* setid);

    /**
     * Send network initiated message.
     */
    void (*ni_message) (uint8_t *msg, size_t len);

    /**
     * Notify GPS of network status changes.
     * These parameters match values in the android.net.NetworkInfo class.
     */
    void (*update_network_state) (int connected, int type, int roaming, const char* extra_info);

    /**
     * Notify GPS of network status changes.
     * These parameters match values in the android.net.NetworkInfo class.
     */
    void (*update_network_availability) (int avaiable, const char* apn);
} AGpsRilInterface;

/**
 * GPS Geofence.
 *      There are 3 states associated with a Geofence: Inside, Outside, Unknown.
 * There are 3 transitions: ENTERED, EXITED, UNCERTAIN.
 *
 * An example state diagram with confidence level: 95% and Unknown time limit
 * set as 30 secs is shown below. (confidence level and Unknown time limit are
 * explained latter)
 *                         ____________________________
 *                        |       Unknown (30 secs)   |
 *                         """"""""""""""""""""""""""""
 *                            ^ |                  |  ^
 *                   UNCERTAIN| |ENTERED     EXITED|  |UNCERTAIN
 *                            | v                  v  |
 *                        ________    EXITED     _________
 *                       | Inside | -----------> | Outside |
 *                       |        | <----------- |         |
 *                        """"""""    ENTERED    """""""""
 *
 * Inside state: We are 95% confident that the user is inside the geofence.
 * Outside state: We are 95% confident that the user is outside the geofence
 * Unknown state: Rest of the time.
 *
 * The Unknown state is better explained with an example:
 *
 *                            __________
 *                           |         c|
 *                           |  ___     |    _______
 *                           |  |a|     |   |   b   |
 *                           |  """     |    """""""
 *                           |          |
 *                            """"""""""
 * In the diagram above, "a" and "b" are 2 geofences and "c" is the accuracy
 * circle reported by the GPS subsystem. Now with regard to "b", the system is
 * confident that the user is outside. But with regard to "a" is not confident
 * whether it is inside or outside the geofence. If the accuracy remains the
 * same for a sufficient period of time, the UNCERTAIN transition would be
 * triggered with the state set to Unknown. If the accuracy improves later, an
 * appropriate transition should be triggered.  This "sufficient period of time"
 * is defined by the parameter in the add_geofence_area API.
 *     In other words, Unknown state can be interpreted as a state in which the
 * GPS subsystem isn't confident enough that the user is either inside or
 * outside the Geofence. It moves to Unknown state only after the expiry of the
 * timeout.
 *
 * The geofence callback needs to be triggered for the ENTERED and EXITED
 * transitions, when the GPS system is confident that the user has entered
 * (Inside state) or exited (Outside state) the Geofence. An implementation
 * which uses a value of 95% as the confidence is recommended. The callback
 * should be triggered only for the transitions requested by the
 * add_geofence_area call.
 *
 * Even though the diagram and explanation talks about states and transitions,
 * the callee is only interested in the transistions. The states are mentioned
 * here for illustrative purposes.
 *
 * Startup Scenario: When the device boots up, if an application adds geofences,
 * and then we get an accurate GPS location fix, it needs to trigger the
 * appropriate (ENTERED or EXITED) transition for every Geofence it knows about.
 * By default, all the Geofences will be in the Unknown state.
 *
 * When the GPS system is unavailable, gps_geofence_status_callback should be
 * called to inform the upper layers of the same. Similarly, when it becomes
 * available the callback should be called. This is a global state while the
 * UNKNOWN transition described above is per geofence.
 *
 * An important aspect to note is that users of this API (framework), will use
 * other subsystems like wifi, sensors, cell to handle Unknown case and
 * hopefully provide a definitive state transition to the third party
 * application. GPS Geofence will just be a signal indicating what the GPS
 * subsystem knows about the Geofence.
 *
 */
#define GPS_GEOFENCE_ENTERED     (1<<0L)
#define GPS_GEOFENCE_EXITED      (1<<1L)
#define GPS_GEOFENCE_UNCERTAIN   (1<<2L)

#define GPS_GEOFENCE_UNAVAILABLE (1<<0L)
#define GPS_GEOFENCE_AVAILABLE   (1<<1L)

#define GPS_GEOFENCE_OPERATION_SUCCESS           0
#define GPS_GEOFENCE_ERROR_TOO_MANY_GEOFENCES -100
#define GPS_GEOFENCE_ERROR_ID_EXISTS          -101
#define GPS_GEOFENCE_ERROR_ID_UNKNOWN         -102
#define GPS_GEOFENCE_ERROR_INVALID_TRANSITION -103
#define GPS_GEOFENCE_ERROR_GENERIC            -149

/**
 * The callback associated with the geofence.
 * Parameters:
 *      geofence_id - The id associated with the add_geofence_area.
 *      location    - The current GPS location.
 *      transition  - Can be one of GPS_GEOFENCE_ENTERED, GPS_GEOFENCE_EXITED,
 *                    GPS_GEOFENCE_UNCERTAIN.
 *      timestamp   - Timestamp when the transition was detected.
 *
 * The callback should only be called when the caller is interested in that
 * particular transition. For instance, if the caller is interested only in
 * ENTERED transition, then the callback should NOT be called with the EXITED
 * transition.
 *
 * IMPORTANT: If a transition is triggered resulting in this callback, the GPS
 * subsystem will wake up the application processor, if its in suspend state.
 */
typedef void (*gps_geofence_transition_callback) (int32_t geofence_id,  GpsLocation* location,
        int32_t transition, GpsUtcTime timestamp);

/**
 * The callback associated with the availability of the GPS system for geofencing
 * monitoring. If the GPS system determines that it cannot monitor geofences
 * because of lack of reliability or unavailability of the GPS signals, it will
 * call this callback with GPS_GEOFENCE_UNAVAILABLE parameter.
 *
 * Parameters:
 *  status - GPS_GEOFENCE_UNAVAILABLE or GPS_GEOFENCE_AVAILABLE.
 *  last_location - Last known location.
 */
typedef void (*gps_geofence_status_callback) (int32_t status, GpsLocation* last_location);

/**
 * The callback associated with the add_geofence call.
 *
 * Parameter:
 * geofence_id - Id of the geofence.
 * status - GPS_GEOFENCE_OPERATION_SUCCESS
 *          GPS_GEOFENCE_ERROR_TOO_MANY_GEOFENCES  - geofence limit has been reached.
 *          GPS_GEOFENCE_ERROR_ID_EXISTS  - geofence with id already exists
 *          GPS_GEOFENCE_ERROR_INVALID_TRANSITION - the monitorTransition contains an
 *              invalid transition
 *          GPS_GEOFENCE_ERROR_GENERIC - for other errors.
 */
typedef void (*gps_geofence_add_callback) (int32_t geofence_id, int32_t status);

/**
 * The callback associated with the remove_geofence call.
 *
 * Parameter:
 * geofence_id - Id of the geofence.
 * status - GPS_GEOFENCE_OPERATION_SUCCESS
 *          GPS_GEOFENCE_ERROR_ID_UNKNOWN - for invalid id
 *          GPS_GEOFENCE_ERROR_GENERIC for others.
 */
typedef void (*gps_geofence_remove_callback) (int32_t geofence_id, int32_t status);


/**
 * The callback associated with the pause_geofence call.
 *
 * Parameter:
 * geofence_id - Id of the geofence.
 * status - GPS_GEOFENCE_OPERATION_SUCCESS
 *          GPS_GEOFENCE_ERROR_ID_UNKNOWN - for invalid id
 *          GPS_GEOFENCE_ERROR_INVALID_TRANSITION -
 *                    when monitor_transitions is invalid
 *          GPS_GEOFENCE_ERROR_GENERIC for others.
 */
typedef void (*gps_geofence_pause_callback) (int32_t geofence_id, int32_t status);

/**
 * The callback associated with the resume_geofence call.
 *
 * Parameter:
 * geofence_id - Id of the geofence.
 * status - GPS_GEOFENCE_OPERATION_SUCCESS
 *          GPS_GEOFENCE_ERROR_ID_UNKNOWN - for invalid id
 *          GPS_GEOFENCE_ERROR_GENERIC for others.
 */
typedef void (*gps_geofence_resume_callback) (int32_t geofence_id, int32_t status);

typedef struct {
    gps_geofence_transition_callback geofence_transition_callback;
    gps_geofence_status_callback geofence_status_callback;
    gps_geofence_add_callback geofence_add_callback;
    gps_geofence_remove_callback geofence_remove_callback;
    gps_geofence_pause_callback geofence_pause_callback;
    gps_geofence_resume_callback geofence_resume_callback;
    gps_create_thread create_thread_cb;
} GpsGeofenceCallbacks;

/** Extended interface for GPS_Geofencing support */
typedef struct {
   /** set to sizeof(GpsGeofencingInterface) */
   size_t          size;

   /**
    * Opens the geofence interface and provides the callback routines
    * to the implementation of this interface.
    */
   void  (*init)( GpsGeofenceCallbacks* callbacks );

   /**
    * Add a geofence area. This api currently supports circular geofences.
    * Parameters:
    *    geofence_id - The id for the geofence. If a geofence with this id
    *       already exists, an error value (GPS_GEOFENCE_ERROR_ID_EXISTS)
    *       should be returned.
    *    latitude, longtitude, radius_meters - The lat, long and radius
    *       (in meters) for the geofence
    *    last_transition - The current state of the geofence. For example, if
    *       the system already knows that the user is inside the geofence,
    *       this will be set to GPS_GEOFENCE_ENTERED. In most cases, it
    *       will be GPS_GEOFENCE_UNCERTAIN.
    *    monitor_transition - Which transitions to monitor. Bitwise OR of
    *       GPS_GEOFENCE_ENTERED, GPS_GEOFENCE_EXITED and
    *       GPS_GEOFENCE_UNCERTAIN.
    *    notification_responsiveness_ms - Defines the best-effort description
    *       of how soon should the callback be called when the transition
    *       associated with the Geofence is triggered. For instance, if set
    *       to 1000 millseconds with GPS_GEOFENCE_ENTERED, the callback
    *       should be called 1000 milliseconds within entering the geofence.
    *       This parameter is defined in milliseconds.
    *       NOTE: This is not to be confused with the rate that the GPS is
    *       polled at. It is acceptable to dynamically vary the rate of
    *       sampling the GPS for power-saving reasons; thus the rate of
    *       sampling may be faster or slower than this.
    *    unknown_timer_ms - The time limit after which the UNCERTAIN transition
    *       should be triggered. This parameter is defined in milliseconds.
    *       See above for a detailed explanation.
    */
   void (*add_geofence_area) (int32_t geofence_id, double latitude, double longitude,
       double radius_meters, int last_transition, int monitor_transitions,
       int notification_responsiveness_ms, int unknown_timer_ms);

   /**
    * Pause monitoring a particular geofence.
    * Parameters:
    *   geofence_id - The id for the geofence.
    */
   void (*pause_geofence) (int32_t geofence_id);

   /**
    * Resume monitoring a particular geofence.
    * Parameters:
    *   geofence_id - The id for the geofence.
    *   monitor_transitions - Which transitions to monitor. Bitwise OR of
    *       GPS_GEOFENCE_ENTERED, GPS_GEOFENCE_EXITED and
    *       GPS_GEOFENCE_UNCERTAIN.
    *       This supersedes the value associated provided in the
    *       add_geofence_area call.
    */
   void (*resume_geofence) (int32_t geofence_id, int monitor_transitions);

   /**
    * Remove a geofence area. After the function returns, no notifications
    * should be sent.
    * Parameter:
    *   geofence_id - The id for the geofence.
    */
   void (*remove_geofence_area) (int32_t geofence_id);
} GpsGeofencingInterface;

/**
 * Legacy struct to represent an estimate of the GPS clock time.
 * Deprecated, to be removed in the next Android release.
 * Use GnssClock instead.
 */
typedef struct {
    /** set to sizeof(GpsClock) */
    size_t size;
    GpsClockFlags flags;
    int16_t leap_second;
    GpsClockType type;
    int64_t time_ns;
    double time_uncertainty_ns;
    int64_t full_bias_ns;
    double bias_ns;
    double bias_uncertainty_ns;
    double drift_nsps;
    double drift_uncertainty_nsps;
} GpsClock;

/**
 * Represents an estimate of the GPS clock time.
 */
typedef struct {
    /** set to sizeof(GnssClock) */
    size_t size;

    /**
     * A set of flags indicating the validity of the fields in this data
     * structure.
     */
    GnssClockFlags flags;

    /**
     * Leap second data.
     * The sign of the value is defined by the following equation:
     *      utc_time_ns = time_ns - (full_bias_ns + bias_ns) - leap_second *
     *      1,000,000,000
     *
     * If the data is available 'flags' must contain GNSS_CLOCK_HAS_LEAP_SECOND.
     */
    int16_t leap_second;

    /**
     * The GNSS receiver internal clock value. This is the local hardware clock
     * value.
     *
     * For local hardware clock, this value is expected to be monotonically
     * increasing while the hardware clock remains power on. (For the case of a
     * HW clock that is not continuously on, see the
     * hw_clock_discontinuity_count field). The receiver's estimate of GPS time
     * can be derived by substracting the sum of full_bias_ns and bias_ns (when
     * available) from this value.
     *
     * This GPS time is expected to be the best estimate of current GPS time
     * that GNSS receiver can achieve.
     *
     * Sub-nanosecond accuracy can be provided by means of the 'bias_ns' field.
     * The value contains the 'time uncertainty' in it.
     *
     * This field is mandatory.
     */
    int64_t time_ns;

    /**
     * 1-Sigma uncertainty associated with the clock's time in nanoseconds.
     * The uncertainty is represented as an absolute (single sided) value.
     *
     * If the data is available, 'flags' must contain
     * GNSS_CLOCK_HAS_TIME_UNCERTAINTY. This value is effectively zero (it is
     * the reference local clock, by which all other times and time
     * uncertainties are measured.)  (And thus this field can be not provided,
     * per GNSS_CLOCK_HAS_TIME_UNCERTAINTY flag, or provided & set to 0.)
     */
    double time_uncertainty_ns;

    /**
     * The difference between hardware clock ('time' field) inside GPS receiver
     * and the true GPS time since 0000Z, January 6, 1980, in nanoseconds.
     *
     * The sign of the value is defined by the following equation:
     *      local estimate of GPS time = time_ns - (full_bias_ns + bias_ns)
     *
     * This value is mandatory if the receiver has estimated GPS time. If the
     * computed time is for a non-GPS constellation, the time offset of that
     * constellation to GPS has to be applied to fill this value. The error
     * estimate for the sum of this and the bias_ns is the bias_uncertainty_ns,
     * and the caller is responsible for using this uncertainty (it can be very
     * large before the GPS time has been solved for.) If the data is available
     * 'flags' must contain GNSS_CLOCK_HAS_FULL_BIAS.
     */
    int64_t full_bias_ns;

    /**
     * Sub-nanosecond bias.
     * The error estimate for the sum of this and the full_bias_ns is the
     * bias_uncertainty_ns
     *
     * If the data is available 'flags' must contain GNSS_CLOCK_HAS_BIAS. If GPS
     * has computed a position fix. This value is mandatory if the receiver has
     * estimated GPS time.
     */
    double bias_ns;

    /**
     * 1-Sigma uncertainty associated with the local estimate of GPS time (clock
     * bias) in nanoseconds. The uncertainty is represented as an absolute
     * (single sided) value.
     *
     * If the data is available 'flags' must contain
     * GNSS_CLOCK_HAS_BIAS_UNCERTAINTY. This value is mandatory if the receiver
     * has estimated GPS time.
     */
    double bias_uncertainty_ns;

    /**
     * The clock's drift in nanoseconds (per second).
     *
     * A positive value means that the frequency is higher than the nominal
     * frequency, and that the (full_bias_ns + bias_ns) is growing more positive
     * over time.
     *
     * The value contains the 'drift uncertainty' in it.
     * If the data is available 'flags' must contain GNSS_CLOCK_HAS_DRIFT.
     *
     * This value is mandatory if the receiver has estimated GNSS time
     */
    double drift_nsps;

    /**
     * 1-Sigma uncertainty associated with the clock's drift in nanoseconds (per second).
     * The uncertainty is represented as an absolute (single sided) value.
     *
     * If the data is available 'flags' must contain
     * GNSS_CLOCK_HAS_DRIFT_UNCERTAINTY. If GPS has computed a position fix this
     * field is mandatory and must be populated.
     */
    double drift_uncertainty_nsps;

    /**
     * When there are any discontinuities in the HW clock, this field is
     * mandatory.
     *
     * A "discontinuity" is meant to cover the case of a switch from one source
     * of clock to another.  A single free-running crystal oscillator (XO)
     * should generally not have any discontinuities, and this can be set and
     * left at 0.
     *
     * If, however, the time_ns value (HW clock) is derived from a composite of
     * sources, that is not as smooth as a typical XO, or is otherwise stopped &
     * restarted, then this value shall be incremented each time a discontinuity
     * occurs.  (E.g. this value may start at zero at device boot-up and
     * increment each time there is a change in clock continuity. In the
     * unlikely event that this value reaches full scale, rollover (not
     * clamping) is required, such that this value continues to change, during
     * subsequent discontinuity events.)
     *
     * While this number stays the same, between GnssClock reports, it can be
     * safely assumed that the time_ns value has been running continuously, e.g.
     * derived from a single, high quality clock (XO like, or better, that's
     * typically used during continuous GNSS signal sampling.)
     *
     * It is expected, esp. during periods where there are few GNSS signals
     * available, that the HW clock be discontinuity-free as long as possible,
     * as this avoids the need to use (waste) a GNSS measurement to fully
     * re-solve for the GPS clock bias and drift, when using the accompanying
     * measurements, from consecutive GnssData reports.
     */
    uint32_t hw_clock_discontinuity_count;

} GnssClock;

/**
 * Legacy struct to represent a GPS Measurement, it contains raw and computed
 * information.
 * Deprecated, to be removed in the next Android release.
 * Use GnssMeasurement instead.
 */
typedef struct {
    /** set to sizeof(GpsMeasurement) */
    size_t size;
    GpsMeasurementFlags flags;
    int8_t prn;
    double time_offset_ns;
    GpsMeasurementState state;
    int64_t received_gps_tow_ns;
    int64_t received_gps_tow_uncertainty_ns;
    double c_n0_dbhz;
    double pseudorange_rate_mps;
    double pseudorange_rate_uncertainty_mps;
    GpsAccumulatedDeltaRangeState accumulated_delta_range_state;
    double accumulated_delta_range_m;
    double accumulated_delta_range_uncertainty_m;
    double pseudorange_m;
    double pseudorange_uncertainty_m;
    double code_phase_chips;
    double code_phase_uncertainty_chips;
    float carrier_frequency_hz;
    int64_t carrier_cycles;
    double carrier_phase;
    double carrier_phase_uncertainty;
    GpsLossOfLock loss_of_lock;
    int32_t bit_number;
    int16_t time_from_last_bit_ms;
    double doppler_shift_hz;
    double doppler_shift_uncertainty_hz;
    GpsMultipathIndicator multipath_indicator;
    double snr_db;
    double elevation_deg;
    double elevation_uncertainty_deg;
    double azimuth_deg;
    double azimuth_uncertainty_deg;
    bool used_in_fix;
} GpsMeasurement;

/**
 * Represents a GNSS Measurement, it contains raw and computed information.
 *
 * Independence - All signal measurement information (e.g. sv_time,
 * pseudorange_rate, multipath_indicator) reported in this struct should be
 * based on GNSS signal measurements only. You may not synthesize measurements
 * by calculating or reporting expected measurements based on known or estimated
 * position, velocity, or time.
 */
typedef struct {
    /** set to sizeof(GpsMeasurement) */
    size_t size;

    /** A set of flags indicating the validity of the fields in this data structure. */
    GnssMeasurementFlags flags;

    /**
     * Satellite vehicle ID number, as defined in GnssSvInfo::svid
     * This is a mandatory value.
     */
    int16_t svid;

    /**
     * Defines the constellation of the given SV. Value should be one of those
     * GNSS_CONSTELLATION_* constants
     */
    GnssConstellationType constellation;

    /**
     * Time offset at which the measurement was taken in nanoseconds.
     * The reference receiver's time is specified by GpsData::clock::time_ns and should be
     * interpreted in the same way as indicated by GpsClock::type.
     *
     * The sign of time_offset_ns is given by the following equation:
     *      measurement time = GpsClock::time_ns + time_offset_ns
     *
     * It provides an individual time-stamp for the measurement, and allows sub-nanosecond accuracy.
     * This is a mandatory value.
     */
    double time_offset_ns;

    /**
     * Per satellite sync state. It represents the current sync state for the associated satellite.
     * Based on the sync state, the 'received GPS tow' field should be interpreted accordingly.
     *
     * This is a mandatory value.
     */
    GnssMeasurementState state;

    /**
     * The received GNSS Time-of-Week at the measurement time, in nanoseconds.
     * Ensure that this field is independent (see comment at top of
     * GnssMeasurement struct.)
     *
     * For GPS & QZSS, this is:
     *   Received GPS Time-of-Week at the measurement time, in nanoseconds.
     *   The value is relative to the beginning of the current GPS week.
     *
     *   Given the highest sync state that can be achieved, per each satellite, valid range
     *   for this field can be:
     *     Searching       : [ 0       ]   : GNSS_MEASUREMENT_STATE_UNKNOWN
     *     C/A code lock   : [ 0   1ms ]   : GNSS_MEASUREMENT_STATE_CODE_LOCK is set
     *     Bit sync        : [ 0  20ms ]   : GNSS_MEASUREMENT_STATE_BIT_SYNC is set
     *     Subframe sync   : [ 0    6s ]   : GNSS_MEASUREMENT_STATE_SUBFRAME_SYNC is set
     *     TOW decoded     : [ 0 1week ]   : GNSS_MEASUREMENT_STATE_TOW_DECODED is set
     *
     *   Note well: if there is any ambiguity in integer millisecond,
     *   GNSS_MEASUREMENT_STATE_MSEC_AMBIGUOUS should be set accordingly, in the 'state' field.
     *
     *   This value must be populated if 'state' != GNSS_MEASUREMENT_STATE_UNKNOWN.
     *
     * For Glonass, this is:
     *   Received Glonass time of day, at the measurement time in nanoseconds.
     *
     *   Given the highest sync state that can be achieved, per each satellite, valid range for
     *   this field can be:
     *     Searching       : [ 0       ]   : GNSS_MEASUREMENT_STATE_UNKNOWN
     *     C/A code lock   : [ 0   1ms ]   : GNSS_MEASUREMENT_STATE_CODE_LOCK is set
     *     Symbol sync     : [ 0  10ms ]   : GNSS_MEASUREMENT_STATE_SYMBOL_SYNC is set
     *     Bit sync        : [ 0  20ms ]   : GNSS_MEASUREMENT_STATE_BIT_SYNC is set
     *     String sync     : [ 0    2s ]   : GNSS_MEASUREMENT_STATE_GLO_STRING_SYNC is set
     *     Time of day     : [ 0  1day ]   : GNSS_MEASUREMENT_STATE_GLO_TOD_DECODED is set
     *
     * For Beidou, this is:
     *   Received Beidou time of week, at the measurement time in nanoseconds.
     *
     *   Given the highest sync state that can be achieved, per each satellite, valid range for
     *   this field can be:
     *     Searching    : [ 0       ] : GNSS_MEASUREMENT_STATE_UNKNOWN
     *     C/A code lock: [ 0   1ms ] : GNSS_MEASUREMENT_STATE_CODE_LOCK is set
     *     Bit sync (D2): [ 0   2ms ] : GNSS_MEASUREMENT_STATE_BDS_D2_BIT_SYNC is set
     *     Bit sync (D1): [ 0  20ms ] : GNSS_MEASUREMENT_STATE_BIT_SYNC is set
     *     Subframe (D2): [ 0  0.6s ] : GNSS_MEASUREMENT_STATE_BDS_D2_SUBFRAME_SYNC is set
     *     Subframe (D1): [ 0    6s ] : GNSS_MEASUREMENT_STATE_SUBFRAME_SYNC is set
     *     Time of week : [ 0 1week ] : GNSS_MEASUREMENT_STATE_TOW_DECODED is set
     *
     * For Galileo, this is:
     *   Received Galileo time of week, at the measurement time in nanoseconds.
     *
     *     E1BC code lock   : [ 0   4ms ]   : GNSS_MEASUREMENT_STATE_GAL_E1BC_CODE_LOCK is set
     *     E1C 2nd code lock: [ 0 100ms ]   :
     *     GNSS_MEASUREMENT_STATE_GAL_E1C_2ND_CODE_LOCK is set
     *
     *     E1B page    : [ 0    2s ] : GNSS_MEASUREMENT_STATE_GAL_E1B_PAGE_SYNC is set
     *     Time of week: [ 0 1week ] : GNSS_MEASUREMENT_STATE_TOW_DECODED is set
     *
     * For SBAS, this is:
     *   Received SBAS time, at the measurement time in nanoseconds.
     *
     *   Given the highest sync state that can be achieved, per each satellite,
     *   valid range for this field can be:
     *     Searching    : [ 0     ] : GNSS_MEASUREMENT_STATE_UNKNOWN
     *     C/A code lock: [ 0 1ms ] : GNSS_MEASUREMENT_STATE_CODE_LOCK is set
     *     Symbol sync  : [ 0 2ms ] : GNSS_MEASUREMENT_STATE_SYMBOL_SYNC is set
     *     Message      : [ 0  1s ] : GNSS_MEASUREMENT_STATE_SBAS_SYNC is set
    */
    int64_t received_sv_time_in_ns;

    /**
     * 1-Sigma uncertainty of the Received GPS Time-of-Week in nanoseconds.
     *
     * This value must be populated if 'state' != GPS_MEASUREMENT_STATE_UNKNOWN.
     */
    int64_t received_sv_time_uncertainty_in_ns;

    /**
     * Carrier-to-noise density in dB-Hz, typically in the range [0, 63].
     * It contains the measured C/N0 value for the signal at the antenna port.
     *
     * This is a mandatory value.
     */
    double c_n0_dbhz;

    /**
     * Pseudorange rate at the timestamp in m/s. The correction of a given
     * Pseudorange Rate value includes corrections for receiver and satellite
     * clock frequency errors. Ensure that this field is independent (see
     * comment at top of GnssMeasurement struct.)
     *
     * It is mandatory to provide the 'uncorrected' 'pseudorange rate', and provide GpsClock's
     * 'drift' field as well (When providing the uncorrected pseudorange rate, do not apply the
     * corrections described above.)
     *
     * The value includes the 'pseudorange rate uncertainty' in it.
     * A positive 'uncorrected' value indicates that the SV is moving away from the receiver.
     *
     * The sign of the 'uncorrected' 'pseudorange rate' and its relation to the sign of 'doppler
     * shift' is given by the equation:
     *      pseudorange rate = -k * doppler shift   (where k is a constant)
     *
     * This should be the most accurate pseudorange rate available, based on
     * fresh signal measurements from this channel.
     *
     * It is mandatory that this value be provided at typical carrier phase PRR
     * quality (few cm/sec per second of uncertainty, or better) - when signals
     * are sufficiently strong & stable, e.g. signals from a GPS simulator at >=
     * 35 dB-Hz.
     */
    double pseudorange_rate_mps;

    /**
     * 1-Sigma uncertainty of the pseudorange_rate_mps.
     * The uncertainty is represented as an absolute (single sided) value.
     *
     * This is a mandatory value.
     */
    double pseudorange_rate_uncertainty_mps;

    /**
     * Accumulated delta range's state. It indicates whether ADR is reset or there is a cycle slip
     * (indicating loss of lock).
     *
     * This is a mandatory value.
     */
    GnssAccumulatedDeltaRangeState accumulated_delta_range_state;

    /**
     * Accumulated delta range since the last channel reset in meters.
     * A positive value indicates that the SV is moving away from the receiver.
     *
     * The sign of the 'accumulated delta range' and its relation to the sign of 'carrier phase'
     * is given by the equation:
     *          accumulated delta range = -k * carrier phase    (where k is a constant)
     *
     * This value must be populated if 'accumulated delta range state' != GPS_ADR_STATE_UNKNOWN.
     * However, it is expected that the data is only accurate when:
     *      'accumulated delta range state' == GPS_ADR_STATE_VALID.
     */
    double accumulated_delta_range_m;

    /**
     * 1-Sigma uncertainty of the accumulated delta range in meters.
     * This value must be populated if 'accumulated delta range state' != GPS_ADR_STATE_UNKNOWN.
     */
    double accumulated_delta_range_uncertainty_m;

    /**
     * Carrier frequency at which codes and messages are modulated, it can be L1 or L2.
     * If the field is not set, the carrier frequency is assumed to be L1.
     *
     * If the data is available, 'flags' must contain
     * GNSS_MEASUREMENT_HAS_CARRIER_FREQUENCY.
     */
    float carrier_frequency_hz;

    /**
     * The number of full carrier cycles between the satellite and the receiver.
     * The reference frequency is given by the field 'carrier_frequency_hz'.
     * Indications of possible cycle slips and resets in the accumulation of
     * this value can be inferred from the accumulated_delta_range_state flags.
     *
     * If the data is available, 'flags' must contain
     * GNSS_MEASUREMENT_HAS_CARRIER_CYCLES.
     */
    int64_t carrier_cycles;

    /**
     * The RF phase detected by the receiver, in the range [0.0, 1.0].
     * This is usually the fractional part of the complete carrier phase measurement.
     *
     * The reference frequency is given by the field 'carrier_frequency_hz'.
     * The value contains the 'carrier-phase uncertainty' in it.
     *
     * If the data is available, 'flags' must contain
     * GNSS_MEASUREMENT_HAS_CARRIER_PHASE.
     */
    double carrier_phase;

    /**
     * 1-Sigma uncertainty of the carrier-phase.
     * If the data is available, 'flags' must contain
     * GNSS_MEASUREMENT_HAS_CARRIER_PHASE_UNCERTAINTY.
     */
    double carrier_phase_uncertainty;

    /**
     * An enumeration that indicates the 'multipath' state of the event.
     *
     * The multipath Indicator is intended to report the presence of overlapping
     * signals that manifest as distorted correlation peaks.
     *
     * - if there is a distorted correlation peak shape, report that multipath
     *   is GNSS_MULTIPATH_INDICATOR_PRESENT.
     * - if there is not a distorted correlation peak shape, report
     *   GNSS_MULTIPATH_INDICATOR_NOT_PRESENT
     * - if signals are too weak to discern this information, report
     *   GNSS_MULTIPATH_INDICATOR_UNKNOWN
     *
     * Example: when doing the standardized overlapping Multipath Performance
     * test (3GPP TS 34.171) the Multipath indicator should report
     * GNSS_MULTIPATH_INDICATOR_PRESENT for those signals that are tracked, and
     * contain multipath, and GNSS_MULTIPATH_INDICATOR_NOT_PRESENT for those
     * signals that are tracked and do not contain multipath.
     */
    GnssMultipathIndicator multipath_indicator;

    /**
     * Signal-to-noise ratio at correlator output in dB.
     * If the data is available, 'flags' must contain GNSS_MEASUREMENT_HAS_SNR.
     * This is the power ratio of the "correlation peak height above the
     * observed noise floor" to "the noise RMS".
     */
    double snr_db;
} GnssMeasurement;

/**
 * Legacy struct to represents a reading of GPS measurements.
 * Deprecated, to be removed in the next Android release.
 * Use GnssData instead.
 */
typedef struct {
    /** set to sizeof(GpsData) */
    size_t size;
    size_t measurement_count;
    GpsMeasurement measurements[GPS_MAX_MEASUREMENT];

    /** The GPS clock time reading. */
    GpsClock clock;
} GpsData;

/**
 * Represents a reading of GNSS measurements. For devices where GnssSystemInfo's
 * year_of_hw is set to 2016+, it is mandatory that these be provided, on
 * request, when the GNSS receiver is searching/tracking signals.
 *
 * - Reporting of GPS constellation measurements is mandatory.
 * - Reporting of all tracked constellations are encouraged.
 */
typedef struct {
    /** set to sizeof(GnssData) */
    size_t size;

    /** Number of measurements. */
    size_t measurement_count;

    /** The array of measurements. */
    GnssMeasurement measurements[GNSS_MAX_MEASUREMENT];

    /** The GPS clock time reading. */
    GnssClock clock;
} GnssData;

/**
 * Callback with gnss_position_report_callback. Can only be called from a thread created by
 * create_thread_cb.
 */
//typedef void (* gnss_position_report_callback)(
//       const qmiLocEventPositionReportIndMsgT_v02* pos_ind);

/**
 * Callback with gnss_sv_measurement_info_callback. Can only be called from a thread created by
 * create_thread_cb.
 */
//typedef void (* gnss_sv_measurement_info_callback)(
//        qmiLocEventGnssSvMeasInfoIndMsgT_v02* sv_meas_info);

/**
 * Callback with gnss_sv_info_callback. Can only be called from a thread created by
 * create_thread_cb.
 */
//typedef void (* gnss_sv_info_callback)(
//        qmiLocEventGnssSvInfoIndMsgT_v02* sv_info);

/** New QMI_LOC callback structure for Trimble DR. */
//typedef struct {
    /** set to sizeof(QmiLocCallbacks) */
//    size_t size;
//    gnss_position_report_callback position_report_cb;
//    gnss_sv_measurement_info_callback sv_meas_info_cb;
//}QmiLocCallbacks;

/** New QMI_LOC callback structure for Trimble DR. */
//typedef struct {
    /** set to sizeof(QmiLocSVCallbacks) */
//   size_t size;
//    gnss_sv_info_callback sv_info_cb;
//}QmiLocSVCallbacks;

/** QMI LOC interface for TrimbleDR support. */
//typedef struct {
    /** set to sizeof(QmiLocInterface) */
//    size_t          size;
//    int  (*init)( QmiLocCallbacks* callbacks );
//    void (*close) (void);
//} QmiLocInterface;

/** QMI LOC interface for TrimbleDR support. */
//typedef struct {
    /** set to sizeof(QmiLocSVInterface) */
//    size_t          size;
//    int  (*init)( QmiLocSVCallbacks* callbacks );
//    void (*close) (void);
//} QmiLocSVInterface;

/**
 * The legacy callback for to report measurements from the HAL.
 *
 * This callback is deprecated, and will be removed in the next release. Use
 * gnss_measurement_callback() instead.
 *
 * Parameters:
 *    data - A data structure containing the measurements.
 */
typedef void (*gps_measurement_callback) (GpsData* data);

/**
 * The callback for to report measurements from the HAL.
 *
 * Parameters:
 *    data - A data structure containing the measurements.
 */
typedef void (*gnss_measurement_callback) (GnssData* data);

typedef struct {
    /** set to sizeof(GpsMeasurementCallbacks) */
    size_t size;
    gps_measurement_callback measurement_callback;
    gnss_measurement_callback gnss_measurement_callback;
} GpsMeasurementCallbacks;

#define GPS_MEASUREMENT_OPERATION_SUCCESS          0
#define GPS_MEASUREMENT_ERROR_ALREADY_INIT      -100
#define GPS_MEASUREMENT_ERROR_GENERIC           -101

/**
 * Extended interface for GPS Measurements support.
 */
typedef struct {
    /** Set to sizeof(GpsMeasurementInterface) */
    size_t size;

    /**
     * Initializes the interface and registers the callback routines with the HAL.
     * After a successful call to 'init' the HAL must begin to provide updates at its own phase.
     *
     * Status:
     *    GPS_MEASUREMENT_OPERATION_SUCCESS
     *    GPS_MEASUREMENT_ERROR_ALREADY_INIT - if a callback has already been registered without a
     *              corresponding call to 'close'
     *    GPS_MEASUREMENT_ERROR_GENERIC - if any other error occurred, it is expected that the HAL
     *              will not generate any updates upon returning this error code.
     */
    int (*init) (GpsMeasurementCallbacks* callbacks);

    /**
     * Stops updates from the HAL, and unregisters the callback routines.
     * After a call to stop, the previously registered callbacks must be considered invalid by the
     * HAL.
     * If stop is invoked without a previous 'init', this function should perform no work.
     */
    void (*close) (void);

} GpsMeasurementInterface;

/**
 * Legacy struct to represents a GPS navigation message (or a fragment of it).
 * Deprecated, to be removed in the next Android release.
 * Use GnssNavigationMessage instead.
 */
typedef struct {
    /** set to sizeof(GpsNavigationMessage) */
    size_t size;
    int8_t prn;
    GpsNavigationMessageType type;
    NavigationMessageStatus status;
    int16_t message_id;
    int16_t submessage_id;
    size_t data_length;
    uint8_t* data;
} GpsNavigationMessage;

/** Represents a GPS navigation message (or a fragment of it). */
typedef struct {
    /** set to sizeof(GnssNavigationMessage) */
    size_t size;

    /**
     * Satellite vehicle ID number, as defined in GnssSvInfo::svid
     * This is a mandatory value.
     */
    int16_t svid;

    /**
     * The type of message contained in the structure.
     * This is a mandatory value.
     */
    GnssNavigationMessageType type;

    /**
     * The status of the received navigation message.
     * No need to send any navigation message that contains words with parity error and cannot be
     * corrected.
     */
    NavigationMessageStatus status;

    /**
     * Message identifier. It provides an index so the complete Navigation
     * Message can be assembled.
     *
     * - For GPS L1 C/A subframe 4 and 5, this value corresponds to the 'frame
     *   id' of the navigation message, in the range of 1-25 (Subframe 1, 2, 3
     *   does not contain a 'frame id' and this value can be set to -1.)
     *
     * - For Glonass L1 C/A, this refers to the frame ID, in the range of 1-5.
     *
     * - For BeiDou D1, this refers to the frame number in the range of 1-24
     *
     * - For Beidou D2, this refers to the frame number, in the range of 1-120
     *
     * - For Galileo F/NAV nominal frame structure, this refers to the subframe
     *   number, in the range of 1-12
     *
     * - For Galileo I/NAV nominal frame structure, this refers to the subframe
     *   number in the range of 1-24
     */
    int16_t message_id;

    /**
     * Sub-message identifier. If required by the message 'type', this value
     * contains a sub-index within the current message (or frame) that is being
     * transmitted.
     *
     * - For GPS L1 C/A, BeiDou D1 & BeiDou D2, the submessage id corresponds to
     *   the subframe number of the navigation message, in the range of 1-5.
     *
     * - For Glonass L1 C/A, this refers to the String number, in the range from
     *   1-15
     *
     * - For Galileo F/NAV, this refers to the page type in the range 1-6
     *
     * - For Galileo I/NAV, this refers to the word type in the range 1-10+
     */
    int16_t submessage_id;

    /**
     * The length of the data (in bytes) contained in the current message.
     * If this value is different from zero, 'data' must point to an array of the same size.
     * e.g. for L1 C/A the size of the sub-frame will be 40 bytes (10 words, 30 bits/word).
     *
     * This is a mandatory value.
     */
    size_t data_length;

    /**
     * The data of the reported GPS message. The bytes (or words) specified
     * using big endian format (MSB first).
     *
     * - For GPS L1 C/A, Beidou D1 & Beidou D2, each subframe contains 10 30-bit
     *   words. Each word (30 bits) should be fit into the last 30 bits in a
     *   4-byte word (skip B31 and B32), with MSB first, for a total of 40
     *   bytes, covering a time period of 6, 6, and 0.6 seconds, respectively.
     *
     * - For Glonass L1 C/A, each string contains 85 data bits, including the
     *   checksum.  These bits should be fit into 11 bytes, with MSB first (skip
     *   B86-B88), covering a time period of 2 seconds.
     *
     * - For Galileo F/NAV, each word consists of 238-bit (sync & tail symbols
     *   excluded). Each word should be fit into 30-bytes, with MSB first (skip
     *   B239, B240), covering a time period of 10 seconds.
     *
     * - For Galileo I/NAV, each page contains 2 page parts, even and odd, with
     *   a total of 2x114 = 228 bits, (sync & tail excluded) that should be fit
     *   into 29 bytes, with MSB first (skip B229-B232).
     */
    uint8_t* data;

} GnssNavigationMessage;

/**
 * The legacy callback to report an available fragment of a GPS navigation
 * messages from the HAL.
 *
 * This callback is deprecated, and will be removed in the next release. Use
 * gnss_navigation_message_callback() instead.
 *
 * Parameters:
 *      message - The GPS navigation submessage/subframe representation.
 */
typedef void (*gps_navigation_message_callback) (GpsNavigationMessage* message);

/**
 * The callback to report an available fragment of a GPS navigation messages from the HAL.
 *
 * Parameters:
 *      message - The GPS navigation submessage/subframe representation.
 */
typedef void (*gnss_navigation_message_callback) (GnssNavigationMessage* message);

typedef struct {
    /** set to sizeof(GpsNavigationMessageCallbacks) */
    size_t size;
    gps_navigation_message_callback navigation_message_callback;
    gnss_navigation_message_callback gnss_navigation_message_callback;
} GpsNavigationMessageCallbacks;

#define GPS_NAVIGATION_MESSAGE_OPERATION_SUCCESS             0
#define GPS_NAVIGATION_MESSAGE_ERROR_ALREADY_INIT         -100
#define GPS_NAVIGATION_MESSAGE_ERROR_GENERIC              -101

/**
 * Extended interface for GPS navigation message reporting support.
 */
typedef struct {
    /** Set to sizeof(GpsNavigationMessageInterface) */
    size_t size;

    /**
     * Initializes the interface and registers the callback routines with the HAL.
     * After a successful call to 'init' the HAL must begin to provide updates as they become
     * available.
     *
     * Status:
     *      GPS_NAVIGATION_MESSAGE_OPERATION_SUCCESS
     *      GPS_NAVIGATION_MESSAGE_ERROR_ALREADY_INIT - if a callback has already been registered
     *              without a corresponding call to 'close'.
     *      GPS_NAVIGATION_MESSAGE_ERROR_GENERIC - if any other error occurred, it is expected that
     *              the HAL will not generate any updates upon returning this error code.
     */
    int (*init) (GpsNavigationMessageCallbacks* callbacks);

    /**
     * Stops updates from the HAL, and unregisters the callback routines.
     * After a call to stop, the previously registered callbacks must be considered invalid by the
     * HAL.
     * If stop is invoked without a previous 'init', this function should perform no work.
     */
    void (*close) (void);

} GpsNavigationMessageInterface;

/**
 * Interface for passing GNSS configuration contents from platform to HAL.
 */
typedef struct {
    /** Set to sizeof(GnssConfigurationInterface) */
    size_t size;

    /**
     * Deliver GNSS configuration contents to HAL.
     * Parameters:
     *     config_data - a pointer to a char array which holds what usually is expected from
                         file(/etc/gps.conf), i.e., a sequence of UTF8 strings separated by '\n'.
     *     length - total number of UTF8 characters in configuraiton data.
     *
     * IMPORTANT:
     *      GPS HAL should expect this function can be called multiple times. And it may be
     *      called even when GpsLocationProvider is already constructed and enabled. GPS HAL
     *      should maintain the existing requests for various callback regardless the change
     *      in configuration data.
     */
    void (*configuration_update) (const char* config_data, int32_t length);
} GnssConfigurationInterface;

#ifdef _REF_LE21_FLAG_20200612
00  uint64 b_IsValid : 1;       /* Solution is/is not valid */
01  uint64 b_IsPropagated : 1;  /* Solution is/is not propagated */
02  uint64 b_IsWls : 1;         /* Solution is/is not WLS */
03  uint64 b_IsKf : 1;          /* Solution is/is not KF */
04  uint64 b_IsItarVln : 1;     /* Solution is/is not in violation of ITAR */
05  uint64 b_IsOverDetrm : 1;   /* Solution is/is not over determined */
06  uint64 b_IsExternal : 1;    /* Solution is/is not an external update */
07  uint64 b_IsRefLoc : 1;      /* Solution is/is not a ref loc update */
08  uint64 b_IsCoarsePos : 1;   /* Solution is/is not a coarse pos update */
09  uint64 b_IsInternal : 1;    /* Solution is/is not an internal update */
10  uint64 b_IsGpsUsed : 1;     /* GPS is/is not used in solution */
11  uint64 b_IsGloUsed : 1;     /* GLO is/is not used in solution */
12  uint64 b_IsBdsUsed : 1;     /* BDS is/is not used in solution */
13  uint64 b_IsGalUsed : 1;     /* GAL is/is not used in solution */
14  uint64 b_IsSft : 1;         /* Solution is/is not SFT */
15  uint64 b_Is3D : 1;          /* Solution is/is not 3D */
16  uint64 b_IsAltConstr : 1;   /* Solution is/is not alt constrained */
17  uint64 b_IsGpsGloTBConstr : 1;  /* Solution is/is not GpsGloTB constrained */
18  uint64 b_IsGpsBdsTBConstr : 1;  /* Solution is/is not GpsBdsTB constrained */
19  uint64 b_IsBdsGloTBConstr : 1;  /* Solution is/is not BdsGloTB constrained */
20  uint64 b_IsMagDevValid : 1; /* Magnetic deviation is/is not valid */
21  uint64 b_IsFinal : 1;       /* Solution is/is not final */
22  uint64 b_IsBackground : 1;  /* Solution is/is not background */
23  uint64 b_IsPeGenerated : 1; /* Solution is/is not PE generated */
24  uint64 b_IsMeGenerated : 1; /* Solution is/is not ME generated */
25  uint64 b_IsGpsXtraSln : 1;     /* Solution is/is not using GPS XTRA */
26  uint64 b_IsGpsXtraEphSln : 1;  /* Solution is/is not using GPS XTRA and ephemeris */
27  uint64 b_IsGloXtraSln : 1;     /* Solution is/is not using Glonass XTRA */
28  uint64 b_IsGloXtraEphSln : 1;  /* Solution is/is not using Glonass XTRA and ephemeris */
29  uint64 b_IsBdsXtraSln : 1;     /* Solution is/is not using Beidou XTRA */
30  uint64 b_IsBdsXtraEphSln : 1;  /* Solution is/is not using Beidou XTRA and ephemeris */
31  uint64 b_IsWifiGenerated : 1;  /* Solution is/is not WIFI generated */
32  uint64 b_IsHeadingValid : 1;   /* Heading is/is not valid */
33  uint64 b_IsVelValid : 1;    /* Velocity is/is not valid */
34  uint64 b_IsEpiHzConstr : 1;   /* Solution does/does not use an EPI as a horizontal constraint */
35  uint64 b_IsEpiAltConstr : 1;  /* Solution does/does not use an EPI as an altitude constraint */
36  uint64 b_IsStatic : 1;      /* Solution is/is not in KF static mode */
37  uint64 b_IsSpiValid : 1;    /* SPI is/is not valid */
38  uint64 b_IsSpiStationary : 1;  /* SPI is/is not indicating stationary. Only valid if b_XspiValid == TRUE */
39  uint64 b_IsPosAssistValid : 1;  /* Initial position is/is not valid for this second. */
40  uint64 b_IsGile : 1;          /* Solution source is/is not GILE */
41  uint64 b_IsGnssInsSln : 1;   /* Solution used GNSS and INS measurements */
42  uint64 b_IsInsOnlySln : 1;   /* Solution used Only INS measurements */
43  uint64 b_IsKfInitFromEpi : 1;   /* KF is/is not initialized from an EPI */
44  uint64 b_IsKfPvFiltered : 1;    /* KF is/is not a PV filtered result */
45  uint64 b_IsXmsiKnown : 1;    /* XMSI is known = true, false otherwise */
46  uint64 b_IsXmsiMounted : 1;  /* XMSI is mounted = true, false otherwise */
47  uint64 b_IsMsiKnown : 1;     /*  MSI is known = true, false otherwise */
48  uint64 b_IsMsiMounted : 1;  /*  MSI is mounted = true, false otherwise */
49  uint64 b_IsCrdDetected : 1;  /*  Cradle Rotation is = true, false otherwise */
50  uint64 b_IsNhcUsedForHeading : 1; /* NHC used for GILE heading = TRUE */
51  uint64 b_IsEcid : 1;         /* Solution is an E-CID position = TRUE */
52  uint64 b_IsPle: 1;          /* Solution is/is not a PLE */
53  uint64 b_IsCellid : 1;         /* Solution is an Cell ID position = TRUE */
54  uint64 b_IsZppFinal : 1;     /* Solution is for ZPP reported position = TRUE */
55  uint64 b_IsVehOnlySln : 1;   /* Solution used only vehicle sensor measurements */
56  uint64 b_IsPedestrianDrSln : 1; /* Solution used only pedestrian sensors */
57  uint64 b_IsGpsGcf : 1; /* Solution derived while GPS was in GCF */
58  uint64 b_IsGloGcf : 1; /* Solution derived while GLO was in GCF */
59  uint64 b_IsBdsGcf : 1; /* Solution derived while BDS was in GCF */
60  uint64 b_IsGalGcf : 1; /* Solution derived while GAL was in GCF */
61  uint64 b_IsNavicGcf : 1; /* Solution derived while NavIC was in GCF */
62  uint64 b_IsPedWithoutGnss : 1; /* flag to indicate pedestrian in w/o GNSS, used for time-out check */
63  uint64 b_IsPedWithoutGnssTimeout : 1; /* flag to indicate pedestrian w/o GNSS timeout */

00  uint64 b_IsInPedMode : 1;  /* flag to indicate pedestrian mode */
01  uint64 b_IsCogUsed : 1;       /* Solution used COG data */
02  uint64 b_IsSpdInputUsed : 1;  /* Solution used Speed input data */
03  uint64 b_IsQzssUsed : 1;     /* QZSS is/is not used in solution */
04  uint64 b_IsQzssXtraSln : 1;     /* Solution is/is not using QZSS XTRA */
05  uint64 b_IsQzssXtraEphSln : 1;  /* Solution is/is not using QZSS XTRA and ephemeris */
06  uint64 b_IsQzssGcf : 1; /* Solution derived while QZSS was in GCF */
07  uint64 b_IsGpsGalTBConstr:1;   /* Solution is/is not GpsGalTB constrained */
08  uint64 b_IsGalGloTBConstr:1;   /* Solution is/is not GalGloTB constrained */
09  uint64 b_IsGalBdsTBConstr:1;   /* Solution is/is not GalBdsTB constrained */
10  uint64 b_IsGalXtraSln:1;    /* Solution is/is not using Galileo XTRA */
11  uint64 b_IsGalXtraEphSln:1; /* Solution is/is not using Galileo XTRA and  ephemeris */
12  uint64 b_IsSbasIonoCorr:1;    /* Solution is/is not using SBAS ionospheric correction */
13  uint64 b_IsSbasFastCorr:1;    /* Solution is/is not using SBAS fast correction */
14  uint64 b_IsSbasLongCorr:1;    /* Solution is/is not using SBAS long-term correction */
15  uint64 b_IsSbasIntegrity:1; /* Solution is/is not using SBAS integrity information */
16  uint64 b_PVAPropagationUsedFixRpt:1; /* acceleration derived from fix history used */
17  uint64 b_IsTdpUsed:1;       /* TDP Meas are/are not used in the solution */
18  uint64 b_IsINP:1; /* Position is a Internal (Qualcomm) network provider position */
19  uint64 b_IsExtNP:1; /* Position is an External Network provider position */
20  uint64 b_FullGnssUsedFixRpt:1;    /* Fix used full GNSS meas information */
21  uint64 b_NHzGnssUsedFixRpt:1;     /* Fix used Fine speed only GNSS meas information */
22  uint64 b_IsGnssLePos:1; /* The fix is qualified as GNSS-LE fix */
23  uint64 b_IsSmoother:1; /* Ped smoother is used */
24  uint64 b_IsSmootherPlusClipping:1; /* Ped smoother + clipping is used */
25  uint64 b_IsSpeedCorrected:1; /* Speed correction is applied */
26  uint64 b_IsGnssIndoor:1;   /* device is indoor as per gnss signal conditions */
27  uint64 b_IsGnssChallenged:1;  /* device is in challenged gnss signal conditions */
28  uint64 b_IsOemDreFix:1; /* If this fix is to be shipped to OEM DRE client */
29  uint64 v_IsDgpsModeEngaged: 1;     /* Flag to indicate if D-GPS mode engaged or not */
30  uint64 b_GleSpeedMeasUsed : 1;                /* Gle Speed meas used in fix report */
31  uint64 b_PropStateCogMeasUsed : 1;            /* RTA propagated heading used as COG meas */
32  uint64 b_PedoIsUnreliable : 1;                /* Pedometer is/is not unreliable */
33  uint64 b_ScaleFactorReset : 1;
34  uint64 v_NavicUsed : 1;   /* If NAVIC SVs used in fix or not */
35  uint64 v_NavicXtraSln:1;    /* Solution is/is not using NAVIC XTRA */
36  uint64 v_NavicXtraEphSln:1; /* Solution is/is not using NAVIC XTRA and ephemeris */
37  uint64 v_NavicGcf:1;        /* Solution derived while NAVIC was in GCF */
38  uint64 v_GpsNavicTBConstr : 1;  /* Solution is/is not GpsNavicTB constrained */
39  uint64 v_GloNavicTBConstr : 1;  /* Solution is/is not GloNavicTB constrained */
40  uint64 v_BdsNavicTBConstr : 1;  /* Solution is/is not BdsNavicTB constrained */
41  uint64 v_GalNavicTBConstr : 1;  /* Solution is/is not GalNavicTB constrained */
#endif

__END_DECLS

#endif /* ANDROID_INCLUDE_HARDWARE_GPS_H */

