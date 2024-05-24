/* This source code is converted from Android Open Source Project to port into telematics,
 * and this is header from original file,
 * android/frameworks/opt/telephony/src/java/com/android/internal/telephony/CallInternalManager.java
 */
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

#ifndef TELEPHONY_CALL_INTERNAL_MANAGER_HPP_
#define TELEPHONY_CALL_INTERNAL_MANAGER_HPP_

#include <memory>
#include <vector>

#include <os/Handler.hpp>
#include <os/Message.hpp>
#include <os/RegistrantList.hpp>

#include <TelephonyManagerConstants.hpp>

#include "call/Call.hpp"
#include "phone/Phone.hpp"

namespace telephony
{

    class CallInternalManager
    {

        friend class CallManagerHandler;

    public:
        static CallInternalManager &instance();

        int32_t getServiceState(const int32_t type, const TelephonyManager::SlotIdType slotId);

        bool registerPhone(const std::shared_ptr<Phone> &phone);
        void unregisterPhone(const std::shared_ptr<Phone> &phone);

        const std::shared_ptr<Phone> getDefaultPhone(const TelephonyManager::SlotIdType slotId = TelephonyManager::SlotIdType::DEFAULT_ID) const;
#if 0 // AOSP code. But it is not used currently. (Static Null return)
        Phone &getFgPhone(const TelephonyManager::SlotIdType slotId = TelephonyManager::SlotIdType::DEFAULT_ID);
#endif
        void dial(const std::shared_ptr<Phone> &phone, const std::string &dialString, const int32_t callType);
        void emergencyDial(const std::shared_ptr<Phone> &phone, const std::string &dialString, const int32_t callType);
        void acceptCall(const std::shared_ptr<Call> &ringingCall) const;
        void rejectCall(const std::shared_ptr<Call> &ringingCall) const;
        void clearDisconnected(const TelephonyManager::SlotIdType slotId = TelephonyManager::SlotIdType::DEFAULT_ID);

        bool sendDtmf(char c, const TelephonyManager::SlotIdType slotId = TelephonyManager::SlotIdType::DEFAULT_ID);
        bool startDtmf(char c, const TelephonyManager::SlotIdType slotId = TelephonyManager::SlotIdType::DEFAULT_ID);
        bool stopDtmf(const TelephonyManager::SlotIdType slotId = TelephonyManager::SlotIdType::DEFAULT_ID);

        bool hasActiveFgCall(const TelephonyManager::SlotIdType slotId = TelephonyManager::SlotIdType::DEFAULT_ID);
        bool hasActiveRingingCall(const TelephonyManager::SlotIdType slotId = TelephonyManager::SlotIdType::DEFAULT_ID);

        std::shared_ptr<Call> getActiveFgCall(const TelephonyManager::SlotIdType slotId = TelephonyManager::SlotIdType::DEFAULT_ID);
        std::shared_ptr<Call> getFirstActiveRingingCall(const TelephonyManager::SlotIdType slotId = TelephonyManager::SlotIdType::DEFAULT_ID);

        CallState getActiveFgCallState(const TelephonyManager::SlotIdType slotId = TelephonyManager::SlotIdType::DEFAULT_ID);
        int32_t getCallState(const TelephonyManager::SlotIdType slotId = TelephonyManager::SlotIdType::DEFAULT_ID);

#ifdef FEATURE_CALL_REJECT_WHEN_NO_CALL_APP
        bool isNeededRejectCall();
        bool isCallRejectCleared();
#endif

    private:
        class CallManagerHandler : public Handler
        {
        public:
            CallManagerHandler(CallInternalManager &parent) : mParent(parent)
            {
            }
            virtual ~CallManagerHandler() {}
            virtual void handleMessage(const std::shared_ptr<Message> &msg) override;

        private:
            CallInternalManager &mParent;
        };

    private:
        CallInternalManager();
        virtual ~CallInternalManager() = default;

        void registerForPhoneStates(const std::shared_ptr<Phone> &phone);
        void unregisterForPhoneStates(const std::shared_ptr<Phone> &phone);

        bool canDial(const std::shared_ptr<Phone> &phone);

        std::shared_ptr<Call> getFirstNonIdleCall(const std::vector<std::shared_ptr<Call>> &calls) const;
        std::shared_ptr<Call> getFirstActiveCall(const std::vector<std::shared_ptr<Call>> &calls) const;

        std::vector<std::shared_ptr<Call>> getCallListRelatedSlot(const std::vector<std::shared_ptr<Call>> &calls,
                                                                const TelephonyManager::SlotIdType slotId) const;

    private:
        std::vector<std::shared_ptr<Phone>> mPhones;
        std::vector<std::shared_ptr<Call>> mRingingCalls;
        std::vector<std::shared_ptr<Call>> mBackgroundCalls;
        std::vector<std::shared_ptr<Call>> mForegroundCalls;
        std::map<TelephonyManager::SlotIdType, std::shared_ptr<Phone>> mDefaultPhones;

        std::shared_ptr<CallManagerHandler> mHandler;
    };

} // namespace telephony

#endif // TELEPHONY_CALL_INTERNAL_MANAGER_HPP_
