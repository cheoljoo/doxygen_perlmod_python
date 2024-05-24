/* This source code is converted from Android Open Source Project to port into telematics,
 * and this is header from original file,
 * android/frameworks/base/telephony/java/com/android/internal/telephony/TelephonyProperties.java
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

#ifndef TELEPHONY_CALL_PROPERTIES_HPP_
#define TELEPHONY_CALL_PROPERTIES_HPP_

namespace telephony
{

    namespace CallProperties
    {

        constexpr const char *const PROPERTY_EMERGENCY_NUMBER_LIST_CARD = "persist.emergency.number.list.card";
        constexpr const char *const PROPERTY_EMERGENCY_NUMBER_LIST_HARD_CODED = "persist.emergency.number.list.hard.coded";
#ifdef FEATURE_CALL_REJECT_WHEN_NO_CALL_APP
        constexpr const char *const PROPERTY_CALL_REJECT_CLEARED = "persist.call.reject.cleared";
#endif
        constexpr const char *const PROPERTY_AUDIO_ENABLED = "persist.audio.enabled";
        constexpr const char *const PROPERTY_DORMANT_MODE_ALLOWED = "persist.dormant.mode.enabled";

    } // namespace CallProperties

} // namespace telephony

#endif // TELEPHONY_CALL_PROPERTIES_HPP_
