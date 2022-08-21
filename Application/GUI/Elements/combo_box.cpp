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
                spdlog::info("Setting coefficient value {}",
                             std::next(values.begin(), current_coefficient_idx_)->first);
            }

            if (is_selected)
            {
                ImGui::SetItemDefaultFocus();
            }
        }
        ImGui::EndCombo();
    }
}
