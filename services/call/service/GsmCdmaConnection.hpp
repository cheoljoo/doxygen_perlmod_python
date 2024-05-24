/*
 * Copyright (C) 2015 The Android Open Source Project
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

#ifndef TELEPHONY_GSM_CDMA_CONNECTION_HPP
#define TELEPHONY_GSM_CDMA_CONNECTION_HPP

#include "call/Connection.hpp"
#include "ril/common/call/DriverCall.hpp"

namespace telephony
{

    class GsmCdmaCall;
    class GsmCdmaCallTracker;

    class GsmCdmaConnection : public Connection
    {
    public:
        GsmCdmaConnection(const std::shared_ptr<DriverCall> &dc, GsmCdmaCallTracker &ct, const int32_t index);
        GsmCdmaConnection(const std::string &dialString, GsmCdmaCallTracker &ct, std::shared_ptr<GsmCdmaCall> &parent, const bool isEmergencyCall);
        virtual ~GsmCdmaConnection() = default;

        void attach(const std::shared_ptr<DriverCall> &dc);
        void attachFake();

        bool compareTo(const std::shared_ptr<DriverCall> &c);

        virtual std::string getOrigDialString() const override
        {
            return mDialString;
        }

        virtual std::shared_ptr<Call> getCall() const override;
        virtual int64_t getDisconnectTime() const override { return mDisconnectTime; }
        virtual CallState getState() const override;
        virtual void hangup() override;

        void onHangupLocal();
        int32_t disconnectCauseFromCode(const int32_t causeCode);
        void onRemoteDisconnect(const int32_t causeCode, const std::string &vendorCause);
        virtual bool onDisconnect(const int32_t cause) override;
        bool update(const std::shared_ptr<DriverCall> &dc);
        int32_t getGsmCdmaIndex() const;
        void onConnectedInOrOut();
        bool isConnectingInOrOut();
        bool getRttMode() const;

        virtual int32_t getNumberPresentation() const { return mNumberPresentation; }
        virtual int32_t getPreciseDisconnectCause() const { return mPreciseCause; }
        virtual std::string getVendorDisconnectCause() const { return mVendorCause; }

        void fakeHoldBeforeDial();

    private:
        void doDisconnect();
        std::shared_ptr<GsmCdmaCall> parentFromDCState(const DriverCall::State state);
        bool isPhoneTypeGsm();

    private:
        GsmCdmaCallTracker &mOwner;
        std::shared_ptr<GsmCdmaCall> mParent;
        bool mDisconnected = false;
        int32_t mIndex = -1;
        int64_t mDisconnectTime = 0LL;
        int32_t mPreciseCause = 0;
        std::string mVendorCause;
        bool mIsEmergencyCall = false;
        bool mRttMode = false;

        friend class GsmCdmaCallTracker;
    };

} // namespace telephony

#endif // TELEPHONY_GSM_CDMA_CONNECTION_HPP
