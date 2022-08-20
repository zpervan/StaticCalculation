#ifndef STATICCALCULATION_FERT_BACKEND_H
#define STATICCALCULATION_FERT_BACKEND_H

#include <map>
#include <string>

namespace Backend
{

/// @TODO: Once the database functionality created, refactor this
struct LoadCoefficients
{
    std::pair<std::string, float> selected_load_coefficient{};
    std::map<std::string, float> populated_load_coefficients{};
    std::map<std::string, float> load_coefficients_database{};
};

static std::map<std::string, float> constant_load_coefficients_database{{"Gotovi pod", 0.50f},
                                                                        {"Termoizolacija", 1.32f},
                                                                        {"Pregradni zidovi", 1.00f}};

static std::map<std::string, float> moving_load_coefficients_database{{"Stambene prostorije", 2.00f}};

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
