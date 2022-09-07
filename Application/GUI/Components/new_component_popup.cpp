#include "new_component_popup.h"

namespace
{
ImGuiWindowFlags flags{ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
                       ImGuiWindowFlags_Modal};
}

namespace GUI
{

NewComponentPopup::NewComponentPopup(EventSystem& event_system)
    : event_system_(event_system),
      size_(400.0f, 150.0f),
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

void NewComponentPopup::Show()
{
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(size_);

    if (ImGui::Begin("Odaberi novu komponentu", nullptr, flags))
    {
        ImGui::Text("Nova komponenta....");

        confirm_button_.Show();

        if (cancel_button_.Show())
        {
            event_system_.Set(Events::None);
        }

        ImGui::End();
    }
}

}  // namespace GUI