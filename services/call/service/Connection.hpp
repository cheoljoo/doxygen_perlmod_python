/* This source code is converted from Android Open Source Project to port into telematics,
 * and this is header from original file,
 * android/frameworks/opt/telephony/src/java/com/android/internal/telephony/Connection.java
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

#ifndef TELEPHONY_CONNECTION_HPP
#define TELEPHONY_CONNECTION_HPP

#include <memory>
#include <string>

#include "call/CallState.hpp"
#include "call/DisconnectCause.hpp"
#include "common/PhoneConstants.hpp"

namespace telephony
{

    class Call;

    class Connection : public std::enable_shared_from_this<Connection>
    {
    public:
        Connection();
        virtual ~Connection() = default;

        std::string getAddress() const
        {
            return mAddress;
        }

        std::string getCnapName() const
        {
            return mCnapName;
        }

        virtual std::string getOrigDialString() const
        {
            return "";
        }

        int32_t getCnapNamePresentation() const
        {
            return mCnapNamePresentation;
        }

        virtual std::shared_ptr<Call> getCall() const = 0;

        int64_t getCreateTime() const
        {
            return mCreateTime;
        }

        int64_t getConnectTime() const
        {
            return mConnectTime;
        }

        void setConnectTime(const int64_t connectTime)
        {
            mConnectTime = connectTime;
        }

        int64_t getConnectTimeReal() const
        {
            return mConnectTimeReal;
        }

        virtual int64_t getDisconnectTime() const = 0;

        int64_t getDurationMillis() const;

        int32_t getDisconnectCause() const
        {
            return mCause;
        }

        virtual std::string getVendorDisconnectCause() const = 0;

        bool isIncoming() const
        {
            return mIsIncoming;
        }

        virtual CallState getState() const;

        bool isAlive() const;
        bool isRinging() const;

        virtual void hangup() = 0;

        virtual bool onDisconnect(const int32_t cause)
        {
            return false;
        }

        virtual int32_t getNumberPresentation() const = 0;
        virtual int32_t getPreciseDisconnectCause() const = 0;

        std::shared_ptr<Connection> getOrigConnection() const
        {
            return mOrigConnection;
        }

        std::string toString() const;

    protected:
        std::string mCnapName;
        int32_t mCnapNamePresentation = PhoneConstants::PRESENTATION_ALLOWED;
        std::string mAddress;
        std::string mDialString;
        int32_t mNumberPresentation = PhoneConstants::PRESENTATION_ALLOWED;
        bool mIsIncoming = false;
        int64_t mCreateTime = 0LL;
        int64_t mConnectTime = 0LL;
        int64_t mConnectTimeReal = 0LL;
        int64_t mDuration = 0LL;
        std::shared_ptr<Connection> mOrigConnection;
        int32_t mCause = DisconnectCause::NOT_DISCONNECTED;
    };

} // namespace telephony

#endif // TELEPHONY_CONNECTION_HPP_
