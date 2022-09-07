#include "new_component_popup.h"

#include <spdlog/spdlog.h>

#include "Application/GUI/Elements/input_fields.h"

namespace
{
ImGuiWindowFlags flags{ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
                       ImGuiWindowFlags_Modal};
std::vector<std::string> component_tabs{"Fert", "Podroznica", "Stup"};
}  // namespace

namespace GUI
{

NewComponentPopup::NewComponentPopup(EventSystem& event_system)
    : event_system_(event_system),
      size_(400.0f, 150.0f),
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

    //    description_text_.reserve(100);
}

void NewComponentPopup::Show()
{
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(size_);

    if (ImGui::Begin("Napravi novu komponentu", nullptr, flags))
    {
        new_component_tab_list_.Show(component_tabs, selected_component_);

        static char text[100] = "";

        ImGui::Text("Opis:");
        ImGui::InputTextWithHint("##Descritpion", "npr. RAVNI KROV-100", text, IM_ARRAYSIZE(text));

        if (confirm_button_.Show())
        {
            std::string tab_name{text};
            spdlog::info("Creating tab component: {}", selected_component_ + tab_name);
        }

        if (cancel_button_.Show())
        {
            event_system_.Set(Events::None);
        }

        ImGui::End();
    }
}

}  // namespace GUI