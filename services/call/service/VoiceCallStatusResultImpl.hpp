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

 * @file       VoiceCallStatusResultImpl.hpp
 * @brief      NetworkInfoResultImpl declaration and body
 * @author     md.ashpaq
  */

#ifndef TELEPHONY_VOICE_CALL_STATUS_RESULT_IMPL_HPP
#define TELEPHONY_VOICE_CALL_STATUS_RESULT_IMPL_HPP

#include <memory>
#include "IVoiceCallStatusCallback.hpp"
#include "call/IVoiceCallStatusResult.hpp"

namespace telephony
{
    class VoiceCallStatusResultImpl : public IVoiceCallStatusResult
    {
    public:
        VoiceCallStatusResultImpl(android::sp<IVoiceCallStatusCallback> &callback);
        VoiceCallStatusResultImpl(const android::sp<IVoiceCallStatusCallback> &callback, const bool notifyNow);

        virtual ~VoiceCallStatusResultImpl() {}

        virtual bool onVoiceCallStatusChanged(const int32_t voice_call_id, const int32_t call_source_type, const int32_t voice_call_type, const int32_t voice_call_progress, std::string number, const int32_t disconnect_cause, const bool rtt_enabled);
        virtual bool isDuplicateReceiver(std::shared_ptr<IVoiceCallStatusResult> &receiver) override;

        android::sp<IVoiceCallStatusCallback> getCallback()
        {
            return mCallback;
        }
    private:
        android::sp<IVoiceCallStatusCallback> mCallback;
        bool mNotifyNow;
    };
}  // namespace telephony
#endif // TELEPHONY_VOICE_CALL_STATUS_RESULT_IMPL_HPP