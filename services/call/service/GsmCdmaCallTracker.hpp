/*
 * Copyright (C) 2015 The Android Open Source Project
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

#ifndef TELEPHONY_GSM_CDMA_CALL_TRACKER_HPP
#define TELEPHONY_GSM_CDMA_CALL_TRACKER_HPP

#include <memory>
#include <mutex>
#include <string>
#include <vector>

#include <EmergencyNumberList.hpp>
#include <TelephonyManagerConstants.hpp>
#include <os/Handler.hpp>
#include <os/RegistrantList.hpp>

#include "call/CallTracker.hpp"
#include "call/GsmCdmaCall.hpp"
#include "call/GsmCdmaConnection.hpp"
#include "call/LastCallFailCause.hpp"
#include "call/ImssCustomXmlInfo.hpp"
#include "common/PhoneConstants.hpp"
#include "oemhook/OemHookRawManager.hpp"
#include "phone/Phone.hpp"
#include "call/CallState.hpp"
#include "call/CallType.hpp"


#include "call/VoiceCallStatusNotifier.hpp"

namespace telephony
{

    class GsmCdmaCallTracker : public CallTracker
    {
    public:
        explicit GsmCdmaCallTracker(Phone &phone, OemHookRawManager &ohrm);
        virtual ~GsmCdmaCallTracker() = default;

        virtual void init() override;

        virtual void registerForVoiceCallStarted(const std::shared_ptr<Handler> &h, int32_t what, const std::shared_ptr<void> &obj) override;
        virtual void unregisterForVoiceCallStarted(const std::shared_ptr<Handler> &h) override;
        virtual void registerForVoiceCallEnded(const std::shared_ptr<Handler> &h, int32_t what, const std::shared_ptr<void> &obj) override;
        virtual void unregisterForVoiceCallEnded(const std::shared_ptr<Handler> &h) override;

        virtual std::shared_ptr<Call> getRingingCall() override;
        virtual std::shared_ptr<Call> getForegroundCall() override;
        virtual std::shared_ptr<Call> getBackgroundCall() override;

        virtual std::shared_ptr<Connection> dial(const std::string &dialString, const int32_t callType, const int32_t clirMode) override;
        virtual std::shared_ptr<Connection> emergencyDial(const std::string &dialString, const int32_t callType, const int32_t clirMode) override;
        virtual void acceptCall() override;
        virtual void rejectCall() override;
        virtual void clearDisconnected() override;
        virtual PhoneConstants::State getState() override;
        virtual int32_t getCallType() const override;
        virtual void changeCallType(const int32_t callType) override;
        virtual std::shared_ptr<EmergencyNumberList> getEmergencyNumberList() const override;

        virtual void eCallIndicationRegi(const std::vector<uint8_t> &bytes, const std::shared_ptr<Message> &response) override;
        virtual void eCallDeregistration() override;
        virtual std::shared_ptr<Connection> eCallStart(const std::string &dialString, const int32_t callType, const std::vector<uint8_t> &bytes, const int32_t clirMode) override;
        virtual std::shared_ptr<Connection> NGeCallStart(const std::string &dialString, const int32_t callType, const std::vector<uint8_t> &bytes, const int32_t clirMode) override;
		virtual void setCustomXMLPayload(const std::string &payload_name, const std::string &payload_id, const std::string &additional_parameter, const std::vector<uint8_t> &bytes, const std::shared_ptr<Message> &response) override;
		virtual void sendCustomXMLInfo(const std::string &payload_id, const uint16_t trans_id,const std::shared_ptr<Message> &response) override;
        virtual void eCallSetMsd(const std::vector<uint8_t> &bytes, const std::shared_ptr<Message> &response) override;
        virtual void eCallSetConfig(const std::vector<uint8_t> &bytes, const std::shared_ptr<Message> &response) override;
        virtual void eCallStop(const uint8_t type, const uint8_t reason, const std::shared_ptr<Message> &response) override;
        virtual void eCallSetCallbackState(const int32_t state, const std::shared_ptr<Message> &response) override;
        virtual void eCallGetOperationMode(const std::shared_ptr<Message> &response) override;
        virtual void eCallSetOperationMode(const int32_t mode) override;
        virtual void eCallRestartTimer(const int32_t timerId, const uint32_t duration) override;
        virtual void eCallGetTimer(const std::shared_ptr<Message> &response) override;
        virtual void eCallGetRedialStatus(const std::shared_ptr<Message> &response) override;
        virtual void eCallGetRemainTimerValue(const uint32_t timerId, const std::shared_ptr<Message> &response) override;
        virtual void eCallGetECallStatus(const std::shared_ptr<Message> &response) override;
        virtual void eraECallGetOperationMode(const std::shared_ptr<Message> &response) override;
        virtual void eraECallSetOperationMode(const int32_t mode, const std::shared_ptr<Message> &response) override;

        virtual void setMute(const bool enableMute) override;
        virtual void getMute(const std::shared_ptr<Message> &response) override;
        virtual void requestForXcallCleanUp(const std::shared_ptr<Message> &response) override;
        virtual void registerForDormantModeChanged(const std::shared_ptr<Handler> &h, int32_t what, const std::shared_ptr<void> &obj) override;
        virtual void unregisterForDormantModeChanged(const std::shared_ptr<Handler> &h) override;
        virtual int32_t setDormantModeAllowed(const bool enable) override;
        virtual int32_t getDormantModeAllowed() override;
        virtual void registerForExitDormantMode(const std::shared_ptr<Handler> &h, int32_t what, const std::shared_ptr<void> &obj) override;
        virtual void unregisterForExitDormantMode(const std::shared_ptr<Handler> &h) override;
        virtual bool exitDormantMode() override;

        virtual int32_t voiceCallStatusRegister(const bool notifyNow, const std::shared_ptr<IVoiceCallStatusResult> &receiver) override;
        virtual int32_t voiceCallStatusUnregister(const std::shared_ptr<IVoiceCallStatusResult> &receiver) override;
        virtual bool isEqualToFgCallId(const int32_t callId) override;
        virtual int32_t getFgCallId() override;

        virtual void handleMessage(const std::shared_ptr<Message> &msg) override;

        Phone &getPhone();

        void updatePhoneType();
        void updatePhoneType(const bool duringInit);

        bool canDial();

        void hangup(const std::shared_ptr<GsmCdmaConnection> &conn);
        void hangup(const std::shared_ptr<GsmCdmaCall> &call);
        void hangupWaitingOrBackground();
        void hangupForegroundResumeBackground();
        virtual void switchWaitingOrHoldingAndActive() override;
        void fakeHoldForegroundBeforeDial();
        void directAsyncResponse(const std::shared_ptr<Message> &msg, const std::shared_ptr<void> &res);

    public:
        Phone &mPhone;
        OemHookRawManager &mOhrm;
        TelephonyManager::SlotIdType mSlotId;
        std::shared_ptr<GsmCdmaCall> mRingingCall;
        std::shared_ptr<GsmCdmaCall> mForegroundCall;
        std::shared_ptr<GsmCdmaCall> mBackgroundCall;
        std::shared_ptr<GsmCdmaConnection> mPendingMO;
        std::shared_ptr<VoiceCallStatusNotifier> mVoiceCallNotify;
        bool mHangupPendingMO = false;
        PhoneConstants::State mState = PhoneConstants::IDLE;
        bool mHangupChecking = false;
        int32_t mHangupCheckingCount = 0;
        bool mDormantAllowed = true;
        int32_t mCallIdForEcall = -1;

    protected:
        virtual void handlePollCalls(const std::shared_ptr<AsyncResult> &ar) override;

    private:
        std::shared_ptr<Connection> dial(const int32_t dialType, const std::string &dialString, const int32_t callType, const std::vector<uint8_t> &bytes, const int32_t clirMode);
        void initEmergencyNumberList();
        void reset();
        void internalClearDisconnected();
        std::shared_ptr<Message> obtainCompleteMessage();
        std::shared_ptr<Message> obtainCompleteMessage(const int32_t what);
        void operationComplete();
        void updatePhoneState();
        void handleLastCallFailCause(const std::shared_ptr<AsyncResult> &ar);
        void handleRadioNotAvailable();

        void handleRingbackTone(const std::shared_ptr<AsyncResult> &ar);
        void handleEmergencyNumberList(const std::shared_ptr<AsyncResult> &ar);
        void handleVoiceSpeechCodec(const std::shared_ptr<AsyncResult> &ar);
        void notifyCallStatusChanged();
        void handleECallStatusChanged(const std::shared_ptr<AsyncResult> &ar);
        void handleECallOperationModeChanged(const std::shared_ptr<AsyncResult> &ar);
        void handleRadioStateChanged(const std::shared_ptr<AsyncResult> &ar);
		void handleECallIPCallerInfoStatusChanged(const std::shared_ptr<AsyncResult> &ar);
        void handleECallIPSettingMSDChanged(const std::shared_ptr<AsyncResult> &ar);
        void handleECallIPSendCustomXmlInfoChanged(const std::shared_ptr<AsyncResult> &ar);
        void dumpState();
        std::shared_ptr<Connection> checkMtFindNewRinging(const std::shared_ptr<DriverCall> &dc, const int32_t i);
        bool isPhoneTypeGsm();

    private:
        std::array<std::shared_ptr<GsmCdmaConnection>, 2> mConnections;
        std::shared_ptr<RegistrantList> mVoiceCallEndedRegistrants = std::make_shared<RegistrantList>();
        std::shared_ptr<RegistrantList> mVoiceCallStartedRegistrants = std::make_shared<RegistrantList>();
        std::shared_ptr<RegistrantList> mDormantModeRegistrants = std::make_shared<RegistrantList>();
        std::shared_ptr<RegistrantList> mExitDormantRegistrants = std::make_shared<RegistrantList>();

        std::vector<std::shared_ptr<GsmCdmaConnection>> mDroppedDuringPoll;
        std::mutex mMutex;

        std::shared_ptr<EmergencyNumberList> mEmergencyNumberList = std::make_shared<EmergencyNumberList>();
    };

} // namespace telephony

#endif // TELEPHONY_GSM_CDMA_CALL_TRACKER_HPP
