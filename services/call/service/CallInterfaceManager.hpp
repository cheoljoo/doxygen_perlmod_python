/* This source code is converted from Android Open Source Project to port into telematics,
 * and this is header from original file,
 * android/packages/services/Telephony/src/com/android/phone/PhoneInterfaceManager.java
 */
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

#ifndef TELEPHONY_CALL_INTERFACE_MANAGER_HPP_
#define TELEPHONY_CALL_INTERFACE_MANAGER_HPP_

#include <memory>
#include <string>

#include <ICallService.hpp>
#include <INetworkInfoCallback.hpp>
#include <TelephonyManagerConstants.hpp>

namespace telephony
{

    class CallInterfaceManager final : public BnCallService
    {
    public:
        static void instantiate();

        CallInterfaceManager() = default;
        virtual ~CallInterfaceManager() final= default;

        virtual void dial(const std::string &number, const int32_t callType, const TelephonyManager::SlotIdType slotId) override final;
        virtual void emergencyDial(const std::string &number, const int32_t callType, const TelephonyManager::SlotIdType slotId) override final;
        virtual void endCall(const TelephonyManager::SlotIdType slotId) override final;
        virtual void answerRingingCall(const TelephonyManager::SlotIdType slotId) override final;
        virtual void rejectCall(const TelephonyManager::SlotIdType slotId) override final;
        virtual void sendDtmf(const char digit, const TelephonyManager::SlotIdType slotId) override final;
        virtual void startDtmf(const char digit, const TelephonyManager::SlotIdType slotId) override final;
        virtual void stopDtmf(const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t getCallState(const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t getCallType(const TelephonyManager::SlotIdType slotId) override final;
        virtual void changeCallType(const int32_t callType, const TelephonyManager::SlotIdType slotId) override final;
        virtual std::shared_ptr<EmergencyNumberList> getEmergencyNumberList(const TelephonyManager::SlotIdType slotId) override final;
        virtual void sendRttMessage(const android::sp<IVoiceCallRttCallback> &callback, const int32_t callId, const std::string &rttMsg, const TelephonyManager::SlotIdType slotId) override final;

#ifdef FEATURE_CALL_REJECT_WHEN_NO_CALL_APP
        virtual bool getCallRejectCleared() override final;
        virtual void setCallRejectCleared(const bool cleared) override final;
#endif

        virtual bool getAudioEnabled(const TelephonyManager::SlotIdType slotId) override final;
        virtual void setAudioEnabled(const bool enabled, const TelephonyManager::SlotIdType slotId) override final;

        virtual int32_t eCallIndicationRegi(const uint8_t *bytes, const uint64_t length, const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t eCallDeregistration(const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t eCallStart(const std::string &number, const int32_t callType, const uint8_t *bytes, const uint64_t length, const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t NGeCallStart(const std::string &number, const int32_t callType, const uint8_t *bytes, const uint64_t length, const TelephonyManager::SlotIdType slotId) override final;
		virtual int32_t setCustomXMLPayload(const std::string &payload_name, const std::string &payload_id, const std::string &additional_parameter, const uint8_t *bytes, const uint64_t length, const TelephonyManager::SlotIdType slotId) override final;
		virtual int32_t sendCustomXMLInfo(const std::string &payload_id, const uint16_t trans_id, const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t eCallSetMsd(const uint8_t *bytes, const uint64_t length, const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t eCallSetConfig(const uint8_t *bytes, const uint64_t length, const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t eCallStop(const uint8_t stopType, const uint8_t endReason, const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t eCallSetCallbackState(const int32_t state, const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t eCallGetOperationMode(const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t eCallSetOperationMode(const int32_t mode, const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t eCallRestartTimer(const int32_t timerId, const uint32_t duration, const TelephonyManager::SlotIdType slotId) override final;
        virtual std::vector<int32_t> eCallGetTimer(const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t eCallGetRedialStatus(const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t eCallGetRemainTimerValue(const uint32_t timerId, const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t eCallGetECallStatus(const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t eraECallGetOperationMode(const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t eraECallSetOperationMode(const int32_t mode, const TelephonyManager::SlotIdType slotId) override final;

        virtual int32_t setMute(const bool enableMute, const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t getMute(const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t switchWaitingOrHoldingAndActive(const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t requestForXcallCleanUp(const TelephonyManager::SlotIdType slotId) override final;

        virtual int32_t setDormantModeAllowed(const bool enable, const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t getDormantModeAllowed(const TelephonyManager::SlotIdType slotId) override final;
        virtual bool exitDormantMode(const TelephonyManager::SlotIdType slotId) override final;

        virtual int32_t voiceCallStatusRegister(const android::sp<IVoiceCallStatusCallback> &callback, const bool notifyNow, const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t voiceCallStatusUnregister(const android::sp<IVoiceCallStatusCallback> &callback, const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t voiceCallStatusRegisterForRtt(const android::sp<IVoiceCallRttCallback> &callback, const bool notifyNow, const TelephonyManager::SlotIdType slotId) override final;
        virtual int32_t voiceCallStatusUnregisterForRtt(const android::sp<IVoiceCallRttCallback> &callback, const TelephonyManager::SlotIdType slotId) override final;
    };

} // namespace telephony

#endif // TELEPHONY_CALL_INTERFACE_MANAGER_HPP_