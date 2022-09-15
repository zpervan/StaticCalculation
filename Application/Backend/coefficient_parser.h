#ifndef STATICCALCULATION_COEFFICIENT_PARSER_H
#define STATICCALCULATION_COEFFICIENT_PARSER_H

#include <spdlog/spdlog.h>

#include <fstream>
#include <json.hpp>
#include <map>

#include "Application/Core/paths.h"

using Coefficients = std::map<std::string, std::map<char*, float>>;
using json = nlohmann::json;

namespace
{
static constexpr auto indent_value{2};
}

namespace CoefficientParser
{

inline void Save(Coefficients& coefficients_to_save)
{
    spdlog::info("Saving to JSON file: {}", Paths::FertCoefficientFilePath());

    json json_object = json::object();

    // Save coefficient data to JSON object
    for (auto & group_it : coefficients_to_save)
    {
        json_object.emplace(group_it);
    }

    /// @TODO: Save the JSON file into a different location, otherwise it won't write to the file
    std::ofstream output_file{Paths::FertCoefficientFilePath(), std::ios_base::trunc};

    if(output_file.is_open())
    {
        output_file << json_object.dump(indent_value);
        output_file.close();
    }

    spdlog::debug(json_object.dump(indent_value));
}

inline Coefficients* Load()
{
    spdlog::info("Parsing JSON file: {}", Paths::FertCoefficientFilePath());
    std::ifstream input_file{Paths::FertCoefficientFilePath()};

    if(!input_file.is_open())
    {
        spdlog::warn("Coefficient file doesn't exist");
        return nullptr;
    }

    json parsed_json;
    input_file >> parsed_json;
    input_file.close();

    auto* coefficients{new Coefficients};

    for (auto group = parsed_json.begin(); group != parsed_json.end(); ++group)
    {
        for (auto coefficient = group->begin(); coefficient != group->end(); ++coefficient)
        {
            char* key{new char[100]};
            strcpy(key, coefficient.key().c_str());

            (*coefficients)[group.key()].emplace(std::make_pair(key, coefficient.value()));
        }
    }

    return coefficients;
}

}  // namespace CoefficientParser

#endif  // STATICCALCULATION_COEFFICIENT_PARSER_H
