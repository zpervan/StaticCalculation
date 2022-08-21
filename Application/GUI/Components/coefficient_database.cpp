#include "coefficient_database.h"

#include <imgui.h>

namespace GUI
{

CoefficientDatabase::CoefficientDatabase(EventSystem& event_system) : event_system_(event_system) {}

void CoefficientDatabase::Show()
{
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5f, 0.5f));

    if (ImGui::Begin("##CoefficientDatabaseWindow", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoDecoration))
    {
        ImGui::Text("Hello from database coefficient");

        ImGui::Button("Spremi");

        ImGui::SameLine(0.0f, 50.0f);

        if(ImGui::Button("Zatvori"))
        {
            event_system_.Set(Events::None);
        }

        ImGui::End();
    }
}

}  // namespace GUI