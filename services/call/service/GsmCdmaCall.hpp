/* This source code is converted from Android Open Source Project to port into telematics,
 * and this is header from original file,
 * android/frameworks/opt/telephony/src/java/com/android/internal/telephony/GsmCdmaCall.java
 */
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

#ifndef TELEPHONY_GSM_CDMA_CALL_HPP
#define TELEPHONY_GSM_CDMA_CALL_HPP

#include <string>
#include <vector>

#include "call/Call.hpp"
#include "call/CallState.hpp"
#include "call/Connection.hpp"
#include "phone/Phone.hpp"
#include "ril/common/call/DriverCall.hpp"

namespace telephony
{

    class GsmCdmaConnection;
    class GsmCdmaCallTracker;

    class GsmCdmaCall : public Call
    {
    public:
        explicit GsmCdmaCall(GsmCdmaCallTracker &owner);
        virtual ~GsmCdmaCall() = default;

        virtual std::vector<std::shared_ptr<Connection>> getConnections() override;
        virtual Phone &getPhone() override;
        virtual void hangup() override;
        virtual std::string toString() override;

        void attach(const std::shared_ptr<Connection> &conn, const std::shared_ptr<DriverCall> &dc);
        void attachFake(const std::shared_ptr<Connection> &conn, const CallState &state);
        bool connectionDisconnected(const std::shared_ptr<GsmCdmaConnection> &conn);
        void detach(const std::shared_ptr<GsmCdmaConnection> &conn);
        bool update(const std::shared_ptr<GsmCdmaConnection> &conn, const std::shared_ptr<DriverCall> &dc);
        void onHangupLocal();

    private:
        GsmCdmaCallTracker &mOwner;
    };

} // namespace telephony

#endif // TELEPHONY_GSM_CDMA_CALL_HPP
