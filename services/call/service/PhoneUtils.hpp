/* This source code is converted from Android Open Source Project to port into telematics,
 * and this is header from original file,
 * android/packages/services/Telephony/src/com/android/phone/PhoneUtils.java
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

#ifndef TELEPHONY_PHONE_UTILS_HPP
#define TELEPHONY_PHONE_UTILS_HPP

#include <memory>
#include <string>

#include <TelephonyManagerConstants.hpp>

#include "call/Call.hpp"

namespace telephony
{

    namespace PhoneUtils
    {

        enum {            
            PHONE_CALL_TYPE_UNKNOWN = 0,
            PHONE_CALL_TYPE_VOICE_CALL,
            PHONE_CALL_TYPE_EMERGENCY_CALL,
            PHONE_CALL_TYPE_EU_ECALL,
            PHONE_CALL_TYPE_ERA_ECALL,
            PHONE_CALL_TYPE_OEM_ECALL
        };

        void placeCall(const std::string &number, const int32_t callType,
                    const TelephonyManager::SlotIdType slotId = TelephonyManager::SlotIdType::DEFAULT_ID);
        bool answerCall(const TelephonyManager::SlotIdType slotId = TelephonyManager::SlotIdType::DEFAULT_ID);
        void rejectCall(const TelephonyManager::SlotIdType slotId = TelephonyManager::SlotIdType::DEFAULT_ID);
        bool hangup(const TelephonyManager::SlotIdType slotId = TelephonyManager::SlotIdType::DEFAULT_ID);
        bool hangupRingingCall(const std::shared_ptr<Call> &ringing);
        bool hangup(const std::shared_ptr<Call> &call);

    } // namespace PhoneUtils

} // namespace telephony

#endif // TELEPHONY_PHONE_UTILS_HPP
