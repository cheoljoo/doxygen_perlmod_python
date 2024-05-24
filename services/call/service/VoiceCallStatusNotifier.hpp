/**
 * @copyright
 * Copyright (c) 2015 by LG Electronics Inc.
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

 * @file       VoiceCallStatusNotifier.hpp
 * @brief      VoiceCallStatusNotifier declaration and body
 * @author     md.ashpaq
 */


#ifndef TELEPHONY_VOICE_CALLSTATUS_NOTIFYER_HPP
#define TELEPHONY_VOICE_CALLSTATUS_NOTIFYER_HPP

#include <memory>
#include <string>
#include <mutex>
#include <vector>

#include <binder/IBinder.h>

#include "call/IVoiceCallStatusResult.hpp"

namespace telephony
{

    class VoiceCallStatusNotifier
    {
    public:
        VoiceCallStatusNotifier();
        virtual ~VoiceCallStatusNotifier()
        { 
            mVoiceDeathRecipient = nullptr;
        }

        int32_t addReceiver(const std::shared_ptr<IVoiceCallStatusResult> &receiver);
        int32_t removeReceiver(const std::shared_ptr<IVoiceCallStatusResult> &receiver);
        bool notifyVoiceCallStatusChange(const int32_t voice_call_id, const int32_t call_source_type, const int32_t voice_call_type, const int32_t voice_call_progress, const std::string number, const int32_t disconnect_cause, const bool rtt_enabled);

        void onBinderDied(const android::wp<android::IBinder> &who);

        class VoiceCallStatusDeathRecipient : public android::IBinder::DeathRecipient
        {
        public:
            VoiceCallStatusDeathRecipient(VoiceCallStatusNotifier& p) : mParent(p) {}
            virtual ~VoiceCallStatusDeathRecipient() {}

            virtual void binderDied(const android::wp<android::IBinder> &who) 
            { 
                 mParent.onBinderDied(who);
            }

        private:
            VoiceCallStatusNotifier &mParent;
        };

    private:
        std::mutex mCallMutex;
        std::vector<std::shared_ptr<IVoiceCallStatusResult>> mReceivers;
        android::sp<VoiceCallStatusDeathRecipient> mVoiceDeathRecipient;
    };
}  // namespace telephony

#endif //TELEPHONY_VOICE_CALLSTATUS_NOTIFYER_HPP