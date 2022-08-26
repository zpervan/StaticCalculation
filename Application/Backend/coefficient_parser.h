#ifndef STATICCALCULATION_COEFFICIENT_PARSER_H
#define STATICCALCULATION_COEFFICIENT_PARSER_H

#include <spdlog/spdlog.h>

#include <fstream>
#include <json.hpp>
#include <map>

#include "Application/Backend/util.h"
#include "Application/Core/paths.h"

using Coefficients = std::map<std::string, std::map<std::string, float>>;

namespace CoefficientParser
{

inline void Save(const std::map<std::string, float>& coefficients_to_save)
{
    /// @TODO: Implement saving to JSON functionality
}

inline Coefficients Load()
{
    spdlog::info("Parsing JSON file: {}", Paths::FertCoefficientFilePath());
    std::ifstream input_file{Paths::FertCoefficientFilePath()};

    nlohmann::json parsed_json;
    input_file >> parsed_json;

    Coefficients coefficients{};

    for (auto group = parsed_json.begin(); group != parsed_json.end(); ++group)
    {
        std::string processed_group_key{Util::ProcessString(group.key())};

        for (auto coefficient = group->begin(); coefficient != group->end(); ++coefficient)
        {
            coefficients[processed_group_key].emplace(std::make_pair(Util::ProcessString(coefficient.key()), coefficient.value()));
        }
    }

    return coefficients;
}

}  // namespace CoefficientParser

#endif  // STATICCALCULATION_COEFFICIENT_PARSER_H
