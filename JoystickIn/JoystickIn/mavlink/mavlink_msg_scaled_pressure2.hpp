// MESSAGE SCALED_PRESSURE2 support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief SCALED_PRESSURE2 message
 *
 * Barometer readings for 2nd barometer
 */
struct SCALED_PRESSURE2 : mavlink::Message {
    static constexpr msgid_t MSG_ID = 137;
    static constexpr size_t LENGTH = 14;
    static constexpr size_t MIN_LENGTH = 14;
    static constexpr uint8_t CRC_EXTRA = 195;
    static constexpr auto NAME = "SCALED_PRESSURE2";


    uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot). */
    float press_abs; /*< [hPa] Absolute pressure */
    float press_diff; /*< [hPa] Differential pressure */
    int16_t temperature; /*< [cdegC] Temperature measurement */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  time_boot_ms: " << time_boot_ms << std::endl;
        ss << "  press_abs: " << press_abs << std::endl;
        ss << "  press_diff: " << press_diff << std::endl;
        ss << "  temperature: " << temperature << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_boot_ms;                  // offset: 0
        map << press_abs;                     // offset: 4
        map << press_diff;                    // offset: 8
        map << temperature;                   // offset: 12
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_boot_ms;                  // offset: 0
        map >> press_abs;                     // offset: 4
        map >> press_diff;                    // offset: 8
        map >> temperature;                   // offset: 12
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
