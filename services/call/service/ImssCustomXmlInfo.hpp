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

    struct ImssCustomXmlInfo
    {
        uint16_t sip_response_code;
		std::string payload_id;
		
        std::string toString()
        {
            return StrUtils::formatString(" sip_response_code: %d payload_id: %s", sip_response_code, payload_id.c_str());
        }
    };

} // namespace telephony
