#include "coefficient_table.h"

#include <imgui.h>
#include <spdlog/spdlog.h>

#include <utility>

#include "Application/GUI/Core/constants.h"

static std::size_t component_id{0};

namespace
{
std::string load_coefficient_to_remove{};
}

namespace GUI
{

CoefficientTable::CoefficientTable(EventSystem& event_system)
    : event_system_(event_system), load_coefficient_combo_box_(ComboBox(event_system_))
{
    load_table_label_ = fmt::format("##LoadTable{}", component_id);
    add_button_label_ = fmt::format("Dodaj##{}", component_id);
    component_id += 1;
}

void CoefficientTable::SetLoadCoefficients(Backend::LoadCoefficients* load_coefficients)
{
    if (!load_coefficients_ && load_coefficients)
    {
        load_coefficients_ = std::make_unique<Backend::LoadCoefficients>(*load_coefficients);
    }
}

void CoefficientTable::Show()
{
    if (ImGui::BeginTable(load_table_label_.c_str(), 3, ImGuiTableFlags_SizingFixedSame))
    {
        if (load_coefficients_->populated_load_coefficients.empty())
        {
            ImGui::TableNextRow();

            ImGui::TableSetColumnIndex(0);
            ImGui::Text("    -    ");

            ImGui::TableSetColumnIndex(1);
            ImGui::Text("    -    ");
        }

        if (ElementToRemoveExits())
        {
            spdlog::info("Removing load coefficient {}", load_coefficient_to_remove);
            load_coefficients_->populated_load_coefficients.erase(load_coefficient_to_remove);
            load_coefficient_to_remove.clear();
        }

        for (const auto& [key, value] : load_coefficients_->populated_load_coefficients)
        {
            ImGui::TableNextRow();

            ImGui::TableSetColumnIndex(0);
            ImGui::Text("%s", key.c_str());

            ImGui::TableSetColumnIndex(1);
            ImGui::Text("%.2f %s", value, Constants::KNM2);

            ImGui::TableSetColumnIndex(2);

            std::string label{"X##" + key};
            if (ImGui::Button(label.c_str(), {20.0f, 0.0f}))
            {
                load_coefficient_to_remove = key;
            };
        }

        ImGui::EndTable();
    }

    float constant_load_sum{0.0f};
    for (const auto& [key, value] : load_coefficients_->populated_load_coefficients)
    {
        constant_load_sum += value;
    }

    ImGui::Text("Ukupno stalno opterecenje: %.2f %s", constant_load_sum, GUI::Constants::KNM2);

    if (ImGui::Button(add_button_label_.c_str()))
    {
        load_coefficients_->populated_load_coefficients.emplace(load_coefficients_->selected_load_coefficient);
        load_coefficients_->selected_load_coefficient = {};
    };

    ImGui::SameLine(0.0f, 10.0f);
    load_coefficient_combo_box_.Show(load_coefficients_->load_coefficients_database,
                                     load_coefficients_->selected_load_coefficient);
}

bool CoefficientTable::ElementToRemoveExits()
{
    bool element_exists{true};

    element_exists &= !load_coefficient_to_remove.empty();
    element_exists &= load_coefficients_->populated_load_coefficients.find(load_coefficient_to_remove) != load_coefficients_->populated_load_coefficients.end();

    return element_exists;
}

}  // namespace GUI