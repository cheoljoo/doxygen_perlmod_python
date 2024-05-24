/* This source code is converted from Android Open Source Project to port into telematics,
 * and this is header from original file,
 * /frameworks/opt/telephony/src/java/com/android/internal/telephony/Call.java
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

#ifndef TELEPHONY_SRVCC_STATE_HPP
#define TELEPHONY_SRVCC_STATE_HPP

#include <string>
#include <vector>
#include <utils/StrUtils.hpp>
#include <utils/Tlog.hpp>

namespace telephony
{
    static const std::vector<const char_t *> kSrvccStateString{
        "NONE",
        "STARTED",
        "COMPLETED",
        "FAILED",
        "CANCELED",
    };

    class SrvccState
    {
    public:
        enum
        {
            NONE,
            STARTED,
            COMPLETED,
            FAILED,
            CANCELED,
        };

        SrvccState() = default;
        SrvccState(const uint32_t state) : mState(state) {}
        virtual ~SrvccState() = default;

        inline SrvccState &operator=(const SrvccState &s)
        {
            mState = s.mState;
            return *this;
        }

        inline SrvccState &operator=(const uint32_t s)
        {
            mState = s;
            return *this;
        }

        inline bool operator==(const SrvccState &s) const
        {
            return mState == s.mState;
        }

        inline bool operator==(const uint32_t s) const
        {
            return mState == s;
        }

        inline bool operator!=(const SrvccState &s) const
        {
            return mState != s.mState;
        }

        inline bool operator!=(const uint32_t s) const
        {
            return mState != s;
        }

        inline uint32_t toInt() const
        {
            return mState;
        }

        inline const char *c_str() const
        {
            if(mState < kSrvccStateString.size())
            {
                return kSrvccStateString[mState];
            }
            return kSrvccStateString[0];
        }

        inline std::string str() const
        {
            if(mState < kSrvccStateString.size())
            {
                return kSrvccStateString[mState];
            }
            return kSrvccStateString[0];
        }

    private:
        uint32_t mState = NONE;
    };

} // namespace telephony

#endif // TELEPHONY_SRVCC_STATE_HPP
