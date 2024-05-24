/*
 * License
 */

#ifndef TELEPHONY_CALL_TYPE_HPP
#define TELEPHONY_CALL_TYPE_HPP

#include <string>
#include <vector>
#include <utils/StrUtils.hpp>
#include <utils/Tlog.hpp>

namespace telephony
{

    static const std::vector<const char_t *> kCallTypeString{
            "UNKNOWN",
            "VOICE_CALL",
            "EMERGENCY_CALL",
            "EU_ECALL",
            "ERA_ECALL",
            "OEM_ECALL",
    };

    class CallType
    {
    public:
        enum
        {
            UNKNOWN = 0,
            VOICE_CALL,
            EMERGENCY_CALL,
            EU_ECALL,
            ERA_ECALL,
            OEM_ECALL
        };

    public:
        CallType() = default;
        CallType(const uint32_t type) : mType(type) {}
        CallType(const CallType &cp) : mType(cp.mType) {}
        virtual ~CallType() = default;

        inline CallType &operator=(const CallType &type)
        {
            mType = type.mType;
            return *this;
        }

        inline CallType &operator=(const uint32_t type)
        {
            mType = type;
            return *this;
        }

        inline bool operator==(const CallType &type) const
        {
            return mType == type.mType;
        }

        inline bool operator==(const uint32_t type) const
        {
            return mType == type;
        }

        inline bool operator!=(const CallType &type) const
        {
            return mType != type.mType;
        }

        inline bool operator!=(const uint32_t type) const
        {
            return mType != type;
        }

        inline uint32_t toInt() const
        {
            return mType;
        }

        inline std::string str() const
        {
            if(mType < kCallTypeString.size())
            {
                return kCallTypeString[mType];
            }
            return kCallTypeString[0];
        }

    private:
        uint32_t mType = UNKNOWN;
    };

} // namespace telephony

#endif // TELEPHONY_CALL_TYPE_HPP
