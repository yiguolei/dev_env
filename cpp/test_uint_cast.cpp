#include <iostream>
#include <memory>
#include <vector>
#include <stdio.h>
#include <cstring>

using int128_t = __int128;
using uint128_t = unsigned __int128;

// 24bit int type, used to store date type in storage
struct uint24_t {
public:
    uint24_t() = default;

    uint24_t(const uint32_t& value) {
        data[0] = static_cast<uint8_t>(value);
        data[1] = static_cast<uint8_t>(value >> 8);
        data[2] = static_cast<uint8_t>(value >> 16);
    }

    uint24_t& operator=(const uint32_t value) {
        data[0] = static_cast<uint8_t>(value);
        data[1] = static_cast<uint8_t>(value >> 8);
        data[2] = static_cast<uint8_t>(value >> 16);
        return *this;
    }

    uint24_t& operator=(const uint128_t& value) {
        data[0] = static_cast<uint8_t>(value);
        data[1] = static_cast<uint8_t>(value >> 8);
        data[2] = static_cast<uint8_t>(value >> 16);
        return *this;
    }

    uint24_t& operator=(const uint64_t value) {
        data[0] = static_cast<uint8_t>(value);
        data[1] = static_cast<uint8_t>(value >> 8);
        data[2] = static_cast<uint8_t>(value >> 16);
        return *this;
    }

    uint24_t& operator+=(const uint24_t& value) {
        *this = static_cast<int>(*this) + static_cast<int>(value);
        return *this;
    }

    uint24_t& operator>>=(const int bits) {
        *this = static_cast<unsigned int>(*this) >> bits;
        return *this;
    }

    uint24_t& operator|=(const uint24_t& value) {
        *this = static_cast<int>(*this) | static_cast<int>(value);
        return *this;
    }

    operator uint32_t() const {
        uint32_t value = static_cast<uint8_t>(data[0]);
        value += (static_cast<uint32_t>(static_cast<uint8_t>(data[1]))) << 8;
        value += (static_cast<uint32_t>(static_cast<uint8_t>(data[2]))) << 16;
        return value;
    }

    uint24_t& operator=(const int value) {
        data[0] = static_cast<uint8_t>(value);
        data[1] = static_cast<uint8_t>(value >> 8);
        data[2] = static_cast<uint8_t>(value >> 16);
        return *this;
    }

    uint24_t& operator=(const int64_t value) {
        data[0] = static_cast<uint8_t>(value);
        data[1] = static_cast<uint8_t>(value >> 8);
        data[2] = static_cast<uint8_t>(value >> 16);
        return *this;
    }

    bool operator==(const uint24_t& value) const { return cmp(value) == 0; }

    bool operator!=(const uint24_t& value) const { return cmp(value) != 0; }

    bool operator<(const uint24_t& value) const { return cmp(value) < 0; }

    bool operator<=(const uint24_t& value) const { return cmp(value) <= 0; }

    bool operator>(const uint24_t& value) const { return cmp(value) > 0; }

    bool operator>=(const uint24_t& value) const { return cmp(value) >= 0; }

    int32_t cmp(const uint24_t& other) const {
        if (data[2] > other.data[2]) {
            return 1;
        } else if (data[2] < other.data[2]) {
            return -1;
        }

        if (data[1] > other.data[1]) {
            return 1;
        } else if (data[1] < other.data[1]) {
            return -1;
        }

        if (data[0] > other.data[0]) {
            return 1;
        } else if (data[0] < other.data[0]) {
            return -1;
        }

        return 0;
    }

    std::string to_string() const {
        tm time_tm;
        int value = *reinterpret_cast<const uint24_t*>(data);
        memset(&time_tm, 0, sizeof(time_tm));
        time_tm.tm_mday = static_cast<int>(value & 31);
        time_tm.tm_mon = static_cast<int>(value >> 5 & 15) - 1;
        time_tm.tm_year = static_cast<int>(value >> 9) - 1900;
        char buf[20] = {'\0'};
        strftime(buf, sizeof(buf), "%Y-%m-%d", &time_tm);
        return std::string(buf);
    }

    const uint8_t* get_data() const { return data; }

private:
    uint8_t data[3];
} __attribute__((packed));

int main() {

    uint64_t a = 1;
    uint32_t b = 2;
    uint24_t c = 3;
    
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;

    std::cout << c << std::endl;

    a = c;

    std::cout << a << std::endl;
}