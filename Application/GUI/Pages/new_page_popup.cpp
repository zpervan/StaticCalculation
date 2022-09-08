#include "new_page_popup.h"

#include <spdlog/spdlog.h>

#include "Application/GUI/Components/input_fields.h"

namespace
{
ImGuiWindowFlags flags{ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
                       ImGuiWindowFlags_Modal};

/// @TODO: Move to a constants file or something similar
std::vector<std::string> component_tabs{"Fert", "Podroznica", "Stup"};

static char description_text[100]{""};
static ImU64 position_number{100};
}  // namespace

namespace GUI
{

NewPagePopup::NewPagePopup(EventSystem& event_system)
    : event_system_(event_system),
      size_(280.0f, 250.0f),
      new_component_tab_list_(ComboBox(event_system_)),
      confirm_button_(Button(event_system_)),
      cancel_button_(Button(event_system_))
{
    confirm_button_.SetText("Dodaj");
    confirm_button_.HorizontalAlignment(ButtonHorizontalAlignment::Left, size_);
    confirm_button_.VerticalAlignment(ButtonVerticalAlignment::Down, size_);

    cancel_button_.SetText("Prekini");
    cancel_button_.HorizontalAlignment(ButtonHorizontalAlignment::Right, size_);
    cancel_button_.VerticalAlignment(ButtonVerticalAlignment::Down, size_);
}

void NewPagePopup::Show()
{
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(size_);

    if (ImGui::Begin("Napravi novu komponentu", nullptr, flags))
    {
        ImGui::Text("Vrsta komponente:");
        new_component_tab_list_.Show(component_tabs, selected_component_);

        ImGui::Text("Opis:");
        ImGui::SetNextItemWidth(size_.x * 0.95f);
        ImGui::InputTextWithHint("##Description", "npr. RAVNI KROV", description_text, IM_ARRAYSIZE(description_text));

        ImGui::Text("Pozicija:");
        ImGui::SetNextItemWidth(size_.x * 0.95f);
        ImGui::InputScalar("##Position", ImGuiDataType_U64, &position_number);

        /// @TODO: Add field validation
        /// @TODO: Check if fields are non-empty
        if (confirm_button_.Show())
        {
            std::string tab_name{description_text + std::string("-") + std::to_string(position_number)};
            spdlog::info("Creating tab component: {}", selected_component_ + "-" + tab_name);
        }

        if (cancel_button_.Show())
        {
            event_system_.Set(Events::None);
        }

        ImGui::End();
    }
}

}  // namespace GUI