/* This source code is converted from Android Open Source Project to port into telematics,
 * and this is header from original file,
 * android/frameworks/opt/telephony/src/java/com/android/internal/telephony/LastCallFailCause.java
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

#include <string>

#include <utils/StrUtils.hpp>

namespace telephony
{

    struct LastCallFailCause
    {
        int32_t causeCode;
        std::string vendorCause;
        int32_t extendedCauseCode; // extended call end reason
        int32_t sipErrorCode;

        std::string toString()
        {
            return StrUtils::formatString(" causeCode: %d vendorCause: %s", causeCode, vendorCause.c_str());
        }
    };

} // namespace telephony
