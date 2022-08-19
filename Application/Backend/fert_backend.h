#ifndef STATICCALCULATION_FERT_BACKEND_H
#define STATICCALCULATION_FERT_BACKEND_H

#include <map>
#include <string>

namespace Backend
{

static std::map<std::string, float> fert_coefficients{{"Gotovi pod", 0.50f}};

template <typename T>
T calculateLoad(T value)
{
    return value;
}

template <typename T, typename... Rest>
T calculateLoad(T value, Rest... rest)
{
    return value + calculateLoad(rest...);
}
}  // namespace Backend

#endif  // STATICCALCULATION_FERT_BACKEND_H
