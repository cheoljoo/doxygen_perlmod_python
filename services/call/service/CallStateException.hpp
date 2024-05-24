/* This source code is converted from Android Open Source Project to port into telematics,
 * and this is header from original file,
 * /frameworks/opt/telephony/src/java/com/android/internal/telephony/CallStateException.java
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

#ifndef TELEPHONY_CALL_STATE_EXCEPTION_HPP
#define TELEPHONY_CALL_STATE_EXCEPTION_HPP

#include <stdexcept>
#include <string>

namespace telephony
{

    class CallStateException : public std::runtime_error
    {
    public:
        explicit CallStateException(const std::string &whatArg);
        virtual ~CallStateException();
    };

} // namespace telephony

#endif // TELEPHONY_CALL_STATE_EXCEPTION_HPP
