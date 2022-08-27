#ifndef STATICCALCULATION_FERT_BACKEND_H
#define STATICCALCULATION_FERT_BACKEND_H

#include <map>
#include <string>

#include "Application/Backend/coefficient_parser.h"

namespace Backend
{

/// @TODO: Once the database functionality created, refactor this
struct LoadCoefficients
{
    std::pair<std::string, float> selected_load_coefficient{};
    std::map<std::string, float> populated_load_coefficients{};
    std::map<std::string, float> load_coefficients_database{};
};

struct ReactionsTableParameters
{
    int position{0};
    float distance_between_walls{0.0f};
    float static_distance{0.0f};
    float reaction_ra{0.0f};
    float reaction_rb{0.0f};
};

/// @TODO: Think of a smarter way to handle global values
static float constant_load_sum{0.0f};
static float moving_load_sum{0.0f};

static Coefficients coefficient_databases;

inline void PopulateCoefficientDatabase()
{
    spdlog::info("Populating coefficient database...");

    coefficient_databases = CoefficientParser::Load();
}

inline std::map<std::string, float> QueryByKey(const std::string& key)
{
    assert(!coefficient_databases.empty());

    std::map <std::string, float> queried_values;

    for (const auto& element : coefficient_databases[key])
    {
        queried_values.emplace(element);
    }

    return queried_values;
}

}  // namespace Backend

#endif  // STATICCALCULATION_FERT_BACKEND_H
