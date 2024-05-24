/**
 * @copyright
 * Copyright (c) 2020 by LG Electronics Inc.
 * This program or software including the accompanying associated documentation
 * ("Software") is the proprietary software of LG Electronics Inc. and or its
 * licensors, and may only be used, duplicated, modified or distributed pursuant
 * to the terms and conditions of a separate written license agreement between you
 * and LG Electronics Inc. ("Authorized License"). Except as set forth in an
 * Authorized License, LG Electronics Inc. grants no license (express or implied),
 * rights to use, or waiver of any kind with respect to the Software, and LG
 * Electronics Inc. expressly reserves all rights in and to the Software and all
 * intellectual property therein. If you have no Authorized License, then you have
 * no rights to use the Software in any ways, and should immediately notify LG
 * Electronics Inc. and discontinue all use of the Software.
 *
 */

#ifndef TELEPHONY_ECALL_OPERATION_MODE_HPP
#define TELEPHONY_ECALL_OPERATION_MODE_HPP

#include <string>
#include <utils/StrUtils.hpp>

namespace telephony
{
    class ECallOperationMode
    {
        public:
            ECallOperationMode();
            ECallOperationMode(const int32_t mode, const int32_t reason);
            virtual ~ECallOperationMode();

            enum ECallMode : int32_t
            {
                ECALL_NORMAL = 0,
                ECALL_ONLY,
                ECALL_NONE
            };

            enum ECallModeReason : int32_t
            {
                CHANGE_REASON_NORMAL  = 0,
                CHANGE_REASON_ERA_GLONASS
            };

            void showInfo();
            std::string ECallModeToString(const int32_t mode) const;
            std::string ECallModeReasonToString(const int32_t reason) const;
        public:
            void setECallOperationMode(const int32_t mode);
            int32_t getECallOperationMode() const;
            void setECallModeReason(const int32_t reason);
            int32_t getECallModeReason() const;
        private:
            int32_t mEcallMode;
            int32_t mReason;
    };
} // namespace telephony
#endif //TELEPHONY_ECALL_OPERATION_MODE_HPP_
