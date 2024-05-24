/* This source code is converted from Android Open Source Project to port into telematics,
 * and this is header from original file,
 * android/frameworks/opt/telephony/src/java/com/android/internal/telephony/DisconnectCause.java
 */
/*
 * Copyright (C) 2014 The Android Open Source Project
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

#ifndef TELEPHONY_DISCONNECT_CAUSE_HPP
#define TELEPHONY_DISCONNECT_CAUSE_HPP

namespace telephony
{
    namespace DisconnectCause
    {

        // The disconnect cause is not valid (Not received a disconnect cause)
        constexpr int32_t NOT_VALID = -1;
        // Has not yet disconnected
        constexpr int32_t NOT_DISCONNECTED = 0;
        // An incoming call that was missed and never answered
        constexpr int32_t INCOMING_MISSED = 1;
        // Normal; Remote hangup
        constexpr int32_t NORMAL = 2;
        // Normal; Local hangup
        constexpr int32_t LOCAL = 3;
        // Outgoing call to busy line
        constexpr int32_t BUSY = 4;
        // Outgoing call to congested network
        constexpr int32_t CONGESTION = 5;
        // Not presently used
        constexpr int32_t MMI = 6;
        // Invalid dial string
        constexpr int32_t INVALID_NUMBER = 7;
        // Cannot reach the peer
        constexpr int32_t NUMBER_UNREACHABLE = 8;
        // Cannot reach the server
        constexpr int32_t SERVER_UNREACHABLE = 9;
        // Invalid credentials
        constexpr int32_t INVALID_CREDENTIALS = 10;
        // Calling from out of network is not allowed
        constexpr int32_t OUT_OF_NETWORK = 11;
        // Server error
        constexpr int32_t SERVER_ERROR = 12;
        // Client timed out
        constexpr int32_t TIMED_OUT = 13;
        // Client went out of network range
        constexpr int32_t LOST_SIGNAL = 14;
        // GSM or CDMA ACM limit exceeded
        constexpr int32_t LIMIT_EXCEEDED = 15;
        // An incoming call that was rejected
        constexpr int32_t INCOMING_REJECTED = 16;
        // Radio is turned off explicitly
        constexpr int32_t POWER_OFF = 17;
        // Out of service
        constexpr int32_t OUT_OF_SERVICE = 18;
        // No ICC, ICC locked, or other ICC error
        constexpr int32_t ICC_ERROR = 19;
        // Call was blocked by call barring
        constexpr int32_t CALL_BARRED = 20;
        // Call was blocked by fixed dial number
        constexpr int32_t FDN_BLOCKED = 21;
        // Call was blocked by restricted all voice access
        constexpr int32_t CS_RESTRICTED = 22;
        // Call was blocked by restricted normal voice access
        constexpr int32_t CS_RESTRICTED_NORMAL = 23;
        // Call was blocked by restricted emergency voice access
        constexpr int32_t CS_RESTRICTED_EMERGENCY = 24;
        // Unassigned number
        constexpr int32_t UNOBTAINABLE_NUMBER = 25;
        // MS is locked until next power cycle
        constexpr int32_t CDMA_LOCKED_UNTIL_POWER_CYCLE = 26;
        // Drop call
        constexpr int32_t CDMA_DROP = 27;
        // INTERCEPT order received, MS state idle entered
        constexpr int32_t CDMA_INTERCEPT = 28;
        // MS has been redirected, call is cancelled
        constexpr int32_t CDMA_REORDER = 29;
        // Service option rejection
        constexpr int32_t CDMA_SO_REJECT = 30;
        // Requested service is rejected, retry delay is set
        constexpr int32_t CDMA_RETRY_ORDER = 31;
        // Unable to obtain access to the CDMA system
        constexpr int32_t CDMA_ACCESS_FAILURE = 32;
        // Not a preempted call
        constexpr int32_t CDMA_PREEMPTED = 33;
        // Not an emergency call
        constexpr int32_t CDMA_NOT_EMERGENCY = 34;
        // Access Blocked by CDMA network
        constexpr int32_t CDMA_ACCESS_BLOCKED = 35;
        // Unknown error or not specified
        constexpr int32_t ERROR_UNSPECIFIED = 36;
        // Only emergency numbers are allowed, but we tried to dial a non-emergency number.
        // TODO: This should be the same as NOT_EMERGENCY
        constexpr int32_t EMERGENCY_ONLY = 37;
        // The supplied CALL Intent didn't contain a valid phone number.
        constexpr int32_t NO_PHONE_NUMBER_SUPPLIED = 38;
        // Our initial phone number was actually an MMI sequence.
        constexpr int32_t DIALED_MMI = 39;
        // We tried to call a voicemail: URI but the device has no voicemail number configured.
        constexpr int32_t VOICEMAIL_NUMBER_MISSING = 40;
        // This status indicates that InCallScreen should display the
        // CDMA-specific "call lost" dialog.  (If an outgoing call fails,
        // and the CDMA "auto-retry" feature is enabled, *and// the retried
        // call fails too, we display this specific dialog.)
        constexpr int32_t CDMA_CALL_LOST = 41;
        // This status indicates that the call was placed successfully,
        // but additionally, the InCallScreen needs to display the
        // "Exiting ECM" dialog.
        constexpr int32_t EXITED_ECM = 42;

        // The outgoing call failed with an unknown cause.
        constexpr int32_t OUTGOING_FAILURE = 43;

        // The outgoing call was canceled by telecom::ConnectionService
        constexpr int32_t OUTGOING_CANCELED = 44;

        // The call, which was an IMS call, disconnected because it merged with another call.
        constexpr int32_t IMS_MERGED_SUCCESSFULLY = 45;

        // Stk Call Control modified DIAL request to USSD request.
        constexpr int32_t DIAL_MODIFIED_TO_USSD = 46;
        // Stk Call Control modified DIAL request to SS request.
        constexpr int32_t DIAL_MODIFIED_TO_SS = 47;
        // Stk Call Control modified DIAL request to DIAL with modified data.
        constexpr int32_t DIAL_MODIFIED_TO_DIAL = 48;

        // The call was terminated because CDMA phone service and roaming have already been activated.
        constexpr int32_t CDMA_ALREADY_ACTIVATED = 49;

        // The call was terminated because it is not possible to place a video call while TTY is
        // enabled.
        constexpr int32_t VIDEO_CALL_NOT_ALLOWED_WHILE_TTY_ENABLED = 50;

        // The call was terminated because it was pulled to another device.
        constexpr int32_t CALL_PULLED = 51;

        // The call was terminated because it was answered on another device.
        constexpr int32_t ANSWERED_ELSEWHERE = 52;

        // The call was terminated because the maximum allowable number of calls has been reached.
        constexpr int32_t MAXIMUM_NUMBER_OF_CALLS_REACHED = 53;

        // The call was terminated because cellular data has been disabled.
        // Used when in a video call and the user disables cellular data via the settings.
        constexpr int32_t DATA_DISABLED = 54;

        // The call was terminated because the data policy has disabled cellular data.
        // Used when in a video call and the user has exceeded the device data limit.
        constexpr int32_t DATA_LIMIT_REACHED = 55;

        // The call being placed was detected as a call forwarding number and was being dialed while
        // roaming on a carrier that does not allow this.
        constexpr int32_t DIALED_CALL_FORWARDING_WHILE_ROAMING = 57;

        // The network does not accept the emergency call request because IMEI was used as
        // identification and this cability is not supported by the network.
        constexpr int32_t IMEI_NOT_ACCEPTED = 58;

        // A call over WIFI was disconnected because the WIFI signal was lost or became too degraded to
        // continue the call.
        constexpr int32_t WIFI_LOST = 59;

        // The call has failed because of access class barring.
        constexpr int32_t IMS_ACCESS_BLOCKED = 60;

        // The call has ended (mid-call) because the device's battery is too low.
        constexpr int32_t LOW_BATTERY = 61;

        // A call was not dialed because the device's battery is too low.
        constexpr int32_t DIAL_LOW_BATTERY = 62;

        // Emergency call failed with a temporary fail cause and can be redialed on this slot.
        constexpr int32_t EMERGENCY_TEMP_FAILURE = 63;

        // Emergency call failed with a permanent fail cause and should not be redialed on this
        // slot.
        constexpr int32_t EMERGENCY_PERM_FAILURE = 64;

        // This cause is used to report a normal event only when no other cause in the normal class
        // applies.
        constexpr int32_t NORMAL_UNSPECIFIED = 65;

        // Stk Call Control modified DIAL request to video DIAL request.
        constexpr int32_t DIAL_MODIFIED_TO_DIAL_VIDEO = 66;

        // Stk Call Control modified Video DIAL request to SS request.
        constexpr int32_t DIAL_VIDEO_MODIFIED_TO_SS = 67;

        // Stk Call Control modified Video DIAL request to USSD request.
        constexpr int32_t DIAL_VIDEO_MODIFIED_TO_USSD = 68;

        // Stk Call Control modified Video DIAL request to DIAL request.
        constexpr int32_t DIAL_VIDEO_MODIFIED_TO_DIAL = 69;

        // Stk Call Control modified Video DIAL request to Video DIAL request.
        constexpr int32_t DIAL_VIDEO_MODIFIED_TO_DIAL_VIDEO = 70;

        // The network has reported that an alternative emergency number has been dialed, but the user
        // must exit airplane mode to place the call.
        constexpr int32_t IMS_SIP_ALTERNATE_EMERGENCY_CALL = 71;

        // Indicates that a new outgoing call cannot be placed because there is already an outgoing
        // call dialing out.
        constexpr int32_t ALREADY_DIALING = 72;

        // Indicates that a new outgoing call cannot be placed while there is a ringing call.
        constexpr int32_t CANT_CALL_WHILE_RINGING = 73;

        // Indicates that a new outgoing call cannot be placed because calling has been disabled using
        // the ro.telephony.disable-call system property.
        constexpr int32_t CALLING_DISABLED = 74;

        // Indicates that a new outgoing call cannot be placed because there is currently an ongoing
        // foreground and background call.
        constexpr int32_t TOO_MANY_ONGOING_CALLS = 75;

        // Indicates that a new outgoing call cannot be placed because OTASP provisioning is currently
        // in process.
        constexpr int32_t OTASP_PROVISIONING_IN_PROCESS = 76;

        // Indicates that the call is dropped due to RTCP inactivity, primarily due to media path
        // disruption.
        constexpr int32_t MEDIA_TIMEOUT = 77;

        // Indicates that an emergency call cannot be placed over WFC because the service is not
        // available in the current location.
        constexpr int32_t EMERGENCY_CALL_OVER_WFC_NOT_AVAILABLE = 78;

        // Indicates that WiFi calling service is not available in the current location.
        constexpr int32_t WFC_SERVICE_NOT_AVAILABLE_IN_THIS_LOCATION = 79;

        // Indicates that an emergency call was placed, which caused the existing connection to be
        // hung up.
        constexpr int32_t OUTGOING_EMERGENCY_CALL_PLACED = 80;

        // Indicates that incoming call was rejected by the modem before the call went in ringing
        constexpr int32_t INCOMING_AUTO_REJECTED = 81;

    } // namespace DisconnectCause

} // namespace telephony

#endif // TELEPHONY_DISCONNECT_CAUSE_HPP_
