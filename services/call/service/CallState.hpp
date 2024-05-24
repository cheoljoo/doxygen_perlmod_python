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

#ifndef TELEPHONY_CALL_STATE_HPP
#define TELEPHONY_CALL_STATE_HPP

#include <string>
#include <vector>
#include <utils/StrUtils.hpp>
#include <utils/Tlog.hpp>

namespace telephony
{

    static const std::vector<const char_t *> kCallStateString{
        "IDLE",
        "ACTIVE",
        "HOLDING",
        "DIALING",
        "ALERTING",
        "INCOMING",
        "WAITING",
        "DISCONNECTED",
        "DISCONNECTING",
    };

    class CallState
    {
    public:
        enum
        {
            IDLE = 0,
            ACTIVE,
            HOLDING,
            DIALING,
            ALERTING,
            INCOMING,
            WAITING,
            DISCONNECTED,
            DISCONNECTING
        };

    public:
        CallState() = default;
        CallState(const uint32_t state) : mState(state) {}
        CallState(const CallState &cs) : mState(cs.mState) {}
        virtual ~CallState() = default;

        inline CallState &operator=(const CallState &s)
        {
            mState = s.mState;
            return *this;
        }

        inline CallState &operator=(const uint32_t s)
        {
            mState = s;
            return *this;
        }

        inline bool operator==(const CallState &s) const
        {
            return mState == s.mState;
        }

        inline bool operator==(const uint32_t s) const
        {
            return mState == s;
        }

        inline bool operator!=(const CallState &s) const
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

        inline bool isAlive() const
        {
            return !((mState == IDLE) || (mState == DISCONNECTED) || (mState == DISCONNECTING));
        }

        inline bool isRinging() const
        {
            return ((mState == INCOMING) || (mState == WAITING));
        }

        inline bool isDialing() const
        {
            return ((mState == DIALING) || (mState == ALERTING));
        }

        inline const char *c_str() const
        {
            if(mState < kCallStateString.size())
            {
                return kCallStateString[mState];
            }
            return kCallStateString[0];
        }

        inline std::string str() const
        {
            if(mState < kCallStateString.size())
            {
                return kCallStateString[mState];
            }
            return kCallStateString[0];
        }

    private:
        uint32_t mState = IDLE;
    };

} // namespace telephony

#endif // TELEPHONY_CALL_STATE_HPP
