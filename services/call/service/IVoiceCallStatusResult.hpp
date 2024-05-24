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

 * @file       IVoiceCallStatusResult.hpp
 * @brief      IVoiceCallStatusResult declaration and body
 * @author     md.ashpaq
  */

#ifndef TELEPHONY_IVOICE_CALL_STATUS_CHANG_HPP
#define TELEPHONY_IVOICE_CALL_STATUS_CHANG_HPP

namespace telephony
{

    class IVoiceCallStatusResult
    {
    public:
        IVoiceCallStatusResult() {}
        virtual ~IVoiceCallStatusResult() {}

        virtual bool onVoiceCallStatusChanged(int32_t voice_call_id, int32_t call_source_type, int32_t voice_call_type, int32_t voice_call_progress, std::string number, int32_t disconnect_cause, bool rtt_enabled) = 0;
        virtual bool isDuplicateReceiver(std::shared_ptr<IVoiceCallStatusResult> &receiver) = 0;
    };

} // namespace telephony

#endif // TELEPHONY_IVOICE_CALL_STATUS_CHANG_HPP
