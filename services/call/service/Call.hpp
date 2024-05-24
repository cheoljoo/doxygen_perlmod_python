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

#ifndef TELEPHONY_CALL_HPP_
#define TELEPHONY_CALL_HPP_

#include <memory>
#include <string>
#include <vector>

#include "call/CallState.hpp"
#include "call/CallType.hpp"
#include "call/Connection.hpp"
#include "ril/common/call/DriverCall.hpp"

namespace telephony
{

    class Phone;

    class Call : public std::enable_shared_from_this<Call>
    {
    public:
        enum SrvccState
        {
            NONE,
            STARTED,
            COMPLETED,
            FAILED,
            CANCELED
        };

    public:
        static CallState stateFromDCState(DriverCall::State dcState);

    public:
        Call() = default;
        virtual ~Call() = default;

        inline bool operator==(const Call &call) const
        {
            return (mState == call.mState) && (mConnections == call.mConnections);
        }

        virtual std::vector<std::shared_ptr<Connection>> getConnections() = 0;
        virtual Phone &getPhone() = 0;
        virtual void hangup() = 0;
        virtual std::string toString() = 0;

        inline bool hasConnection(const std::shared_ptr<Connection> &c)
        {
            return *(c->getCall()) == *this;
        }

        inline bool hasConnections()
        {
            return getConnections().size() > 0U;
        }

        inline CallState getState() const
        {
            return mState;
        }

        inline CallType getCallType() const
        {
            return mType;
        }

        inline void setCallType(const uint32_t type)
        {
            mType = type;
        }

        inline bool isIdle() const
        {
            return !getState().isAlive();
        }

        std::shared_ptr<Connection> getEarliestConnection();
        int64_t getEarliestCreateTime();
        int64_t getEarliestConnectTime();

        inline bool isDialingOrAlerting() const
        {
            return getState().isDialing();
        }

        inline bool isRinging() const
        {
            return getState().isRinging();
        }

        std::shared_ptr<Connection> getLatestConnection();

        inline void hangupIfAlive()
        {
            if (getState().isAlive())
            {
                hangup();
            }
        }

        void clearDisconnected();

    public:
        CallState mState;
        CallType mType;
        std::vector<std::shared_ptr<Connection>> mConnections;

    protected:
        inline void setState(const CallState &newState)
        {
            mState = newState;
        }
    };

} // namespace telephony

#endif // TELEPHONY_CALL_HPP_
