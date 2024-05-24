/*
 * Copyright (C) 2007 The Android Open Source Project
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

#ifndef TELEPHONY_CALL_SYNC_HANDLER_HPP
#define TELEPHONY_CALL_SYNC_HANDLER_HPP

#include <memory>

#include <IVoiceCallStatusCallback.hpp>
#include <IVoiceCallRttCallback.hpp>
#include <TelephonyManagerConstants.hpp>

#include "call/VoiceCallStatusResultImpl.hpp"
#include "sync/SyncHandler.hpp"

namespace telephony
{

    class CallSyncHandler final : public SyncHandler
    {
    public:
        CallSyncHandler() = default;
        virtual ~CallSyncHandler() final = default;

        void dial(const std::string &number, const int32_t callType, const TelephonyManager::SlotIdType slotId);
        void emergencyDial(const std::string &number, const int32_t callType, const TelephonyManager::SlotIdType slotId);
        void endCall(const TelephonyManager::SlotIdType slotId);
        void answerRingingCall(const TelephonyManager::SlotIdType slotId);
        void rejectCall(const TelephonyManager::SlotIdType slotId);
        void sendDtmf(char digit, const TelephonyManager::SlotIdType slotId);
        void startDtmf(char digit, const TelephonyManager::SlotIdType slotId);
        void stopDtmf(const TelephonyManager::SlotIdType slotId);
        int32_t getCallState(const TelephonyManager::SlotIdType slotId);
        int32_t getCallType(const TelephonyManager::SlotIdType slotId);
        void changeCallType(const int32_t callType, const TelephonyManager::SlotIdType slotId);
        std::shared_ptr<EmergencyNumberList> getEmergencyNumberList(const TelephonyManager::SlotIdType slotId);
        void sendRttMessage(const android::sp<IVoiceCallRttCallback> &callback, const int32_t callId, const std::string &rttMsg, const TelephonyManager::SlotIdType slotId);

#ifdef FEATURE_CALL_REJECT_WHEN_NO_CALL_APP
        bool getCallRejectCleared();
        void setCallRejectCleared(bool cleared);
#endif

        bool getAudioEnabled(const TelephonyManager::SlotIdType slotId);
        void setAudioEnabled(const bool enabled, const TelephonyManager::SlotIdType slotId);

        int32_t eCallIndicationRegi(const uint8_t *bytes, const uint64_t length, const TelephonyManager::SlotIdType slotId);
        int32_t eCallDeregistration(const TelephonyManager::SlotIdType slotId);
        int32_t eCallStart(const std::string &number, const int32_t callType, const uint8_t *bytes, const uint64_t length, const TelephonyManager::SlotIdType slotId);
        int32_t NGeCallStart(const std::string &number, const int32_t callType, const uint8_t *bytes, const uint64_t length, const TelephonyManager::SlotIdType slotId);
		int32_t setCustomXMLPayload(const std::string &payload_name, const std::string &payload_id, const std::string &additional_parameter, const uint8_t *bytes, const uint64_t length, const TelephonyManager::SlotIdType slotId);
		int32_t sendCustomXMLInfo(const std::string &payload_id, const uint16_t trans_id, const TelephonyManager::SlotIdType slotId);
        int32_t eCallSetMsd(const uint8_t *bytes, const uint64_t length, const TelephonyManager::SlotIdType slotId);
        int32_t eCallSetConfig(const uint8_t *bytes, const uint64_t length, const TelephonyManager::SlotIdType slotId);
        int32_t eCallStop(const uint8_t stopType, const uint8_t endReason, const TelephonyManager::SlotIdType slotId);
        int32_t eCallSetCallbackState(int32_t state, const TelephonyManager::SlotIdType slotId);
        int32_t eCallGetOperationMode(const TelephonyManager::SlotIdType slotId);
        int32_t eCallSetOperationMode(const int32_t mode, const TelephonyManager::SlotIdType slotId);
        int32_t eCallRestartTimer(const int32_t timerId, const uint32_t duration, const TelephonyManager::SlotIdType slotId);
        std::vector<int32_t> eCallGetTimer(const TelephonyManager::SlotIdType slotId);
        int32_t eCallGetRedialStatus(const TelephonyManager::SlotIdType slotId);
        int32_t eCallGetRemainTimerValue(const uint32_t timerId, const TelephonyManager::SlotIdType slotId);
        int32_t eCallGetECallStatus(const TelephonyManager::SlotIdType slotId);
        int32_t eraECallGetOperationMode(const TelephonyManager::SlotIdType slotId);
        int32_t eraECallSetOperationMode(const int32_t mode, const TelephonyManager::SlotIdType slotId);

        int32_t setMute(const bool enableMute, const TelephonyManager::SlotIdType slotId);
        int32_t getMute(const TelephonyManager::SlotIdType slotId);
        int32_t switchWaitingOrHoldingAndActive(const TelephonyManager::SlotIdType slotId);
        int32_t requestForXcallCleanUp(const TelephonyManager::SlotIdType slotId);

        int32_t setDormantModeAllowed(const bool enable, const TelephonyManager::SlotIdType slotId);
        int32_t getDormantModeAllowed(const TelephonyManager::SlotIdType slotId);
        bool exitDormantMode(const TelephonyManager::SlotIdType slotId);

        int32_t voiceCallStatusRegister(const android::sp<IVoiceCallStatusCallback> &callback, const bool notifyNow, const TelephonyManager::SlotIdType slotId);
        int32_t voiceCallStatusUnregister(const android::sp<IVoiceCallStatusCallback> &callback, const TelephonyManager::SlotIdType slotId);
        int32_t voiceCallStatusRegisterForRtt(const android::sp<IVoiceCallRttCallback> &callback, const bool notifyNow, const TelephonyManager::SlotIdType slotId);
        int32_t voiceCallStatusUnregisterForRtt(const android::sp<IVoiceCallRttCallback> &callback, const TelephonyManager::SlotIdType slotId);

    private:
        virtual bool isRequest(const int32_t command) override final;
        virtual void onRequest(const std::shared_ptr<Message> &msg) override final;
        virtual void onResponse(const std::shared_ptr<Message> &msg) override final;
        virtual std::string getCommandName(const int32_t command) override final;

        void onDialRequest(const std::shared_ptr<SyncRequest> &request);
        void onEmergencyDialRequest(const std::shared_ptr<SyncRequest> &request);
        void onEndCallRequest(const std::shared_ptr<SyncRequest> &request);
        void onAnswerRingingCallRequest(const std::shared_ptr<SyncRequest> &request);
        void onRejectCallRequest(const std::shared_ptr<SyncRequest> &request);
        void onSendDtmfRequest(const std::shared_ptr<SyncRequest> &request);
        void onStartDtmfRequest(const std::shared_ptr<SyncRequest> &request);
        void onStopDtmfRequest(const std::shared_ptr<SyncRequest> &request);
        void onGetCallStateRequest(const std::shared_ptr<SyncRequest> &request);
        void onGetCallTypeRequest(const std::shared_ptr<SyncRequest> &request);
        void onChangeCallTypeRequest(const std::shared_ptr<SyncRequest> &request);
        void onGetEmergencyNumberListRequest(const std::shared_ptr<SyncRequest> &request);

        void onECallIndicationRegiRequest(const std::shared_ptr<SyncRequest> &request);
        void onECallDeregistrationRequest(const std::shared_ptr<SyncRequest> &request);
        void onECallStartRequest(const std::shared_ptr<SyncRequest> &request);
        void onNGECallStartRequest(const std::shared_ptr<SyncRequest> &request);
		void onsetCustomXMLPayloadRequest(const std::shared_ptr<SyncRequest> &request);
		void onsendCustomXMLInfoRequest(const std::shared_ptr<SyncRequest> &request);
        void onECallSetMsdRequest(const std::shared_ptr<SyncRequest> &request);
        void onECallSetConfigRequest(const std::shared_ptr<SyncRequest> &request);
        void onECallStopRequest(const std::shared_ptr<SyncRequest> &request);
        void onECallSetCallbackStateRequest(const std::shared_ptr<SyncRequest> &request);
        void onECallGetOperationModeRequest(const std::shared_ptr<SyncRequest> &request);
        void onECallSetOperationModeRequest(const std::shared_ptr<SyncRequest> &request);
        void onECallRestartTimerRequest(const std::shared_ptr<SyncRequest> &request);
        void onECallGetTimerRequest(const std::shared_ptr<SyncRequest> &request);
        void onECallGetRedialStatus(const std::shared_ptr<SyncRequest> &request);
        void onECallGetRemainTimerValue(const std::shared_ptr<SyncRequest> &request);
        void onECallGetECallStatus(const std::shared_ptr<SyncRequest> &request);
        void onEraECallGetOperationModeRequest(const std::shared_ptr<SyncRequest> &request);
        void onEraECallSetOperationModeRequest(const std::shared_ptr<SyncRequest> &request);

        void onSetMuteRequest(const std::shared_ptr<SyncRequest> &request);
        void onGetMuteRequest(const std::shared_ptr<SyncRequest> &request);
        void onSwitchWaitingOrHoldingAndActiveRequest(const std::shared_ptr<SyncRequest> &request);
        void onRequestForXcallCleanUpRequest(const std::shared_ptr<SyncRequest> &request);
        void onSetDormantModeAllowedRequest(const std::shared_ptr<SyncRequest> &request);
        void onGetDormantModeAllowedRequest(const std::shared_ptr<SyncRequest> &request);
        void onExitDormantModeRequest(const std::shared_ptr<SyncRequest> &request);
    };

} // namespace telephony

#endif // TELEPHONY_CALL_SYNC_HANDLER_HPP_
