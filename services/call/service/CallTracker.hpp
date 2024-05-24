/* This source code is converted from Android Open Source Project to port into telematics,
 * and this is header from original file,
 * android/frameworks/opt/telephony/src/java/com/android/internal/telephony/CallTracker.java
 */
/*
 * Copyright (C) 2006 The Android Open Source Project
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

#ifndef TELEPHONY_CALL_TRACKER_HPP
#define TELEPHONY_CALL_TRACKER_HPP

#include <exception>

#include <EmergencyNumberList.hpp>
#include <os/AsyncResult.hpp>
#include <os/Handler.hpp>
#include <os/Message.hpp>

#include "call/Call.hpp"
#include "common/PhoneConstants.hpp"
#include "common/TelephonyException.hpp"
#include "ril/common/CommandsInterface.hpp"
#include "call/IVoiceCallStatusResult.hpp"

namespace telephony
{

    class CallTracker : public Handler
    {
    public:
        explicit CallTracker(CommandsInterface &mCi);
        virtual ~CallTracker() = default;

        virtual void init() = 0;

        virtual void registerForVoiceCallStarted(const std::shared_ptr<Handler> &h, int32_t what, const std::shared_ptr<void> &obj) = 0;
        virtual void unregisterForVoiceCallStarted(const std::shared_ptr<Handler> &h) = 0;
        virtual void registerForVoiceCallEnded(const std::shared_ptr<Handler> &h, int32_t what, const std::shared_ptr<void> &obj) = 0;
        virtual void unregisterForVoiceCallEnded(const std::shared_ptr<Handler> &h) = 0;

        virtual std::shared_ptr<Call> getRingingCall() = 0;
        virtual std::shared_ptr<Call> getForegroundCall() = 0;
        virtual std::shared_ptr<Call> getBackgroundCall() = 0;

        virtual std::shared_ptr<Connection> dial(const std::string &dialString, const int32_t callType, const int32_t clirMode = CommandsInterface::CLIR_DEFAULT) = 0;
        virtual std::shared_ptr<Connection> emergencyDial(const std::string &dialString, const int32_t callType, const int32_t clirMode = CommandsInterface::CLIR_DEFAULT) = 0;
        virtual void acceptCall() = 0;
        virtual void rejectCall() = 0;
        virtual void clearDisconnected() = 0;
        virtual PhoneConstants::State getState() = 0;
        virtual int32_t getCallType() const = 0;
        virtual void changeCallType(const int32_t callType) = 0;
        virtual std::shared_ptr<EmergencyNumberList> getEmergencyNumberList() const = 0;

        virtual void eCallIndicationRegi(const std::vector<uint8_t> &bytes, const std::shared_ptr<Message> &response) = 0;
        virtual void eCallDeregistration() = 0;
        virtual std::shared_ptr<Connection> eCallStart(const std::string &dialString, const int32_t callType, const std::vector<uint8_t> &bytes, int32_t clirMode = CommandsInterface::CLIR_DEFAULT) = 0;
        virtual std::shared_ptr<Connection> NGeCallStart(const std::string &dialString, const int32_t callType, const std::vector<uint8_t> &bytes, int32_t clirMode = CommandsInterface::CLIR_DEFAULT) = 0;
		virtual void setCustomXMLPayload(const std::string &payload_name, const std::string &payload_id, const std::string &additional_parameter, const std::vector<uint8_t> &bytes, const std::shared_ptr<Message> &response) = 0;
		virtual void sendCustomXMLInfo(const std::string &payload_id, const uint16_t trans_id, const std::shared_ptr<Message> &response) = 0;
        virtual void eCallSetMsd(const std::vector<uint8_t> &bytes, const std::shared_ptr<Message> &response) = 0;
        virtual void eCallSetConfig(const std::vector<uint8_t> &bytes, const std::shared_ptr<Message> &response) = 0;
        virtual void eCallStop(const uint8_t type, const uint8_t reason, const std::shared_ptr<Message> &response) = 0;
        virtual void eCallSetCallbackState(const int32_t state, const std::shared_ptr<Message> &response) = 0;
        virtual void eCallGetOperationMode(const std::shared_ptr<Message> &response) = 0;
        virtual void eCallSetOperationMode(const int32_t mode) = 0;
        virtual void eCallRestartTimer(const int32_t timerId, const uint32_t duration) = 0;
        virtual void eCallGetTimer(const std::shared_ptr<Message> &response) = 0;
        virtual void eCallGetRedialStatus(const std::shared_ptr<Message> &response) = 0;
        virtual void eCallGetRemainTimerValue(const uint32_t timerId, const std::shared_ptr<Message> &response) = 0;
        virtual void eCallGetECallStatus(const std::shared_ptr<Message> &response) = 0;
        virtual void eraECallGetOperationMode(const std::shared_ptr<Message> &response) = 0;
        virtual void eraECallSetOperationMode(const int32_t mode, const std::shared_ptr<Message> &response) = 0;

        virtual void setMute(const bool enableMute) = 0;
        virtual void getMute(const std::shared_ptr<Message> &response) = 0;
        virtual void switchWaitingOrHoldingAndActive() = 0;
        virtual void requestForXcallCleanUp(const std::shared_ptr<Message> &response) = 0;
        virtual void registerForDormantModeChanged(const std::shared_ptr<Handler> &h, int32_t what, const std::shared_ptr<void> &obj) = 0;
        virtual void unregisterForDormantModeChanged(const std::shared_ptr<Handler> &h) = 0;
        virtual int32_t setDormantModeAllowed(const bool enable) = 0;
        virtual int32_t getDormantModeAllowed() = 0;
        virtual void registerForExitDormantMode(const std::shared_ptr<Handler> &h, int32_t what, const std::shared_ptr<void> &obj) = 0;
        virtual void unregisterForExitDormantMode(const std::shared_ptr<Handler> &h) = 0;
        virtual bool exitDormantMode() = 0;

        virtual int32_t voiceCallStatusRegister(const bool notifyNow, const std::shared_ptr<IVoiceCallStatusResult> &receiver) = 0;
        virtual int32_t voiceCallStatusUnregister(const std::shared_ptr<IVoiceCallStatusResult> &receiver) = 0;
        virtual bool isEqualToFgCallId(const int32_t callId) = 0;
        virtual int32_t getFgCallId() = 0;

    public:
        CommandsInterface &mCi;

    protected:
        enum
        {
            EVENT_POLL_CALLS_RESULT = 1,
            EVENT_CALL_STATE_CHANGE = 2,
            EVENT_REPOLL_AFTER_DELAY = 3,
            EVENT_OPERATION_COMPLETE = 4,
            EVENT_GET_LAST_CALL_FAIL_CAUSE = 5,

            EVENT_SWITCH_RESULT = 8,
            EVENT_RADIO_AVAILABLE = 9,
            EVENT_RADIO_NOT_AVAILABLE = 10,
            EVENT_CONFERENCE_RESULT = 11,
            EVENT_SEPARATE_RESULT = 12,
            EVENT_ECT_RESULT = 13,
            EVENT_EXIT_ECM_RESPONSE_CDMA = 14,
            EVENT_CALL_WAITING_INFO_CDMA = 15,
            EVENT_THREE_WAY_DIAL_L2_RESULT_CDMA = 16,
            EVENT_IMS_CALL_STATE_CHANGED = 17,
            EVENT_VOICE_CALL_STATUS_REGISTER = 18,
            EVENT_RADIO_STATE_CHANGED = 19,
        };

    protected:
        void pollCallsWhenSafe();
        void pollCallsAfterDelay();
        bool isTelephonyExceptionRadioNotAvailable(const std::shared_ptr<std::exception> &e) const;
        virtual void handlePollCalls(const std::shared_ptr<AsyncResult> &ar) = 0;
        void handleRadioAvailable();
        std::shared_ptr<Message> obtainNoPollCompleteMessage(const int32_t what);

    protected:
        int32_t mPendingOperations = 0;
        bool mNeedsPoll = false;
        /** default - false, IMS_UNSOL_CALL_STATE_CHANGED - true */
        bool mIsImsCall = false;
        std::shared_ptr<Message> mLastRelevantPoll;
        // std::vector<Connection> mHandoverConnections;

    private:
        bool checkNoOperationsPending() const;
    };

} // namespace telephony

#endif // TELEPHONY_CALL_TRACKER_HPP_
