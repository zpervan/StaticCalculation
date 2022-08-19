#ifndef STATICCALCULATION_FERT_BACKEND_H
#define STATICCALCULATION_FERT_BACKEND_H

#include <map>
#include <string>

namespace Backend
{

static std::pair<std::string, float> temporary_fert_coefficient;
static std::map<std::string, float> fert_coefficients{};
static std::map<std::string, float> fert_coefficients_database{{"Gotovi pod", 0.50f},
                                                               {"Termoizolacija", 1.32f},
                                                               {"Pregradni zidovi", 1.00f}};

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
