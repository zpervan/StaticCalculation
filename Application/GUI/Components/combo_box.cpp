#include "combo_box.h"

#include <spdlog/spdlog.h>

#include "Application/GUI/Core/id.h"

GUI::ComboBox::ComboBox(EventSystem& event_system) : event_system_(event_system)
{
    combo_box_label_ = fmt::format("##ComboBox{}", Id::GenerateId());
}

void GUI::ComboBox::Show(const std::map<std::string, float>& values, std::pair<std::string, float>& selected_value)
{
    ImGui::SetNextItemWidth(200.0f);

    const auto preview_value{std::next(values.begin(), current_coefficient_idx_)->first.c_str()};

    if (selected_value.first.empty())
    {
        selected_value = *std::next(values.begin(), current_coefficient_idx_);
    }

    if (ImGui::BeginCombo(combo_box_label_.c_str(), preview_value, ImGuiComboFlags_None))
    {
        for (std::size_t i = 0; i < values.size(); ++i)
        {
            const bool is_selected{current_coefficient_idx_ == i};

            if (ImGui::Selectable(std::next(values.begin(), i)->first.c_str(), is_selected))
            {
                current_coefficient_idx_ = i;
                selected_value = *std::next(values.begin(), current_coefficient_idx_);
                const auto& combo_box_value{std::next(values.begin(), current_coefficient_idx_)->first};
                spdlog::info("Setting combo box value to {}", combo_box_value);
            }

            if (is_selected)
            {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }
}

void GUI::ComboBox::Show(const std::map<std::string, std::map<char*, float>>& values, std::string& selected_value)
{
    ImGui::SetNextItemWidth(200.0f);

    const auto preview_value{std::next(values.begin(), current_coefficient_idx_)->first.c_str()};

    if (selected_value.empty())
    {
        selected_value = std::next(values.begin(), current_coefficient_idx_)->first;
    }

    if (ImGui::BeginCombo(combo_box_label_.c_str(), preview_value, ImGuiComboFlags_None))
    {
        for (std::size_t i = 0; i < values.size(); ++i)
        {
            const bool is_selected{current_coefficient_idx_ == i};

            if (ImGui::Selectable(std::next(values.begin(), i)->first.c_str(), is_selected))
            {
                current_coefficient_idx_ = i;
                selected_value = std::next(values.begin(), current_coefficient_idx_)->first;
                spdlog::info("Setting combo box value to {}", selected_value);
            }

            if (is_selected)
            {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }
}

void GUI::ComboBox::Show(const std::vector<std::string>& values, std::string& selected_value)
{
    ImGui::SetNextItemWidth(200.0f);

    const auto preview_value{std::next(values.begin(), current_coefficient_idx_)->c_str()};

    if (selected_value.empty())
    {
        selected_value = *values.begin();
    }

    if (ImGui::BeginCombo(combo_box_label_.c_str(), preview_value, ImGuiComboFlags_None))
    {
        for (std::size_t i = 0; i < values.size(); ++i)
        {
            const bool is_selected{current_coefficient_idx_ == i};

            if (ImGui::Selectable(std::next(values.begin(), i)->c_str(), is_selected))
            {
                current_coefficient_idx_ = i;
                selected_value = *std::next(values.begin(), current_coefficient_idx_);
                spdlog::info("Setting combo box value to {}", selected_value);
            }

            if (is_selected)
            {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }
}
