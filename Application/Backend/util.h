#ifndef STATICCALCULATION_UTIL_H
#define STATICCALCULATION_UTIL_H

#include <string>

namespace Util
{

inline std::string ProcessString(const std::string& string)
{
    std::string processed_string{string};

    processed_string[0] = std::toupper(processed_string[0]);
    std::replace(processed_string.begin(), processed_string.end(), '_', ' ');

    return processed_string;
}

}  // namespace Util

#endif  // STATICCALCULATION_UTIL_H
