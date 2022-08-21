#include "menu_bar.h"

#include <imgui.h>
#include <spdlog/spdlog.h>

namespace GUI
{

MenuBar::MenuBar(EventSystem& event_system) : event_system_(event_system) {}

void MenuBar::Show()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Datoteka"))
        {
            if (ImGui::MenuItem("Spremi", "Ctrl+S"))
            {
                spdlog::info("Saving document...");
            }

            if (ImGui::MenuItem("Otvori", nullptr))
            {
                spdlog::info("Loading document");
            }

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Applikacija"))
        {
            if (ImGui::MenuItem("Baza koeficijenata"))
            {
                spdlog::info("Opening coefficient database");
                event_system_.Set(Events::CoefficientDatabase_OpenWindow);
            }

            ImGui::Separator();

            ImGui::MenuItem("Ponovno pokreni", nullptr);

            if (ImGui::MenuItem("Izlaz", nullptr))
            {
                spdlog::info("Exiting application...");
                event_system_.Set(Events::Exit);
            }

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Pomoc"))
        {
            ImGui::MenuItem("Upute koristenja", nullptr);
            ImGui::MenuItem("O aplikaciji", nullptr);

            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}

}  // namespace GUI