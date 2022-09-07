#include "coefficient_database.h"

#include <imgui.h>
#include <spdlog/spdlog.h>

#include "Application/GUI/Core/id.h"

namespace
{
ImGuiWindowFlags flags{ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
                       ImGuiWindowFlags_Modal};
}

namespace GUI
{

CoefficientDatabase::CoefficientDatabase(EventSystem& event_system)
    : event_system_(event_system),
      size_(400.0f, 400.0f),
      save_button_(Button(event_system_)),
      close_button_(Button(event_system_))
{
    save_button_.SetText("Spremi");
    save_button_.HorizontalAlignment(ButtonHorizontalAlignment::Left, size_);
    save_button_.VerticalAlignment(ButtonVerticalAlignment::Down, size_);

    close_button_.SetText("Zatvori");
    close_button_.HorizontalAlignment(ButtonHorizontalAlignment::Right, size_);
    close_button_.VerticalAlignment(ButtonVerticalAlignment::Down, size_);
}

void CoefficientDatabase::Show()
{
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(size_);

    if (ImGui::Begin("##CoefficientDatabaseWindow", NULL, flags))
    {
        ImGui::Text("Dodaj bazu koeficijenata");

        if (save_button_.Show())
        {
            spdlog::debug("Implement saving functionality");
        }

        if (close_button_.Show())
        {
            event_system_.Set(Events::None);
        }

        ImGui::End();
    }
}

}  // namespace GUI