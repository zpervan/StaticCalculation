#ifndef STATICCALCULATION_COMBO_BOX_H
#define STATICCALCULATION_COMBO_BOX_H

#include <imgui.h>

#include <algorithm>
#include <map>

#include "Application/Backend/values.h"

namespace GUI
{

static inline void ComboBox(const std::map<std::string, float>& values, std::pair<std::string, float>& selected_value)
{
    ImGui::SetNextItemWidth(200.0f);
    static int current_coefficient_idx{0};
    const auto preview_value{std::next(values.begin(), current_coefficient_idx)->first.c_str()};

    if(selected_value.first.empty())
    {
        selected_value = *std::next(values.begin(), current_coefficient_idx);
    }

    if (ImGui::BeginCombo("##ComboBox", preview_value, ImGuiComboFlags_None))
    {
        for (int i = 0; i < values.size(); ++i)
        {
            const bool is_selected{current_coefficient_idx == i};

            if (ImGui::Selectable(std::next(values.begin(), i)->first.c_str(), is_selected))
            {
                current_coefficient_idx = i;
                selected_value = *std::next(values.begin(), current_coefficient_idx);
                spdlog::info("Setting coefficient value {}", std::next(values.begin(), current_coefficient_idx)->first);
            }

            if (is_selected)
            {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }
}

}  // namespace GUI

#endif  // STATICCALCULATION_COMBO_BOX_H
