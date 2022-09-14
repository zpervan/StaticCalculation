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

            if(ImGui::MenuItem("Postavke", nullptr))
            {
                event_system_.Set(Events::Options_OpenWindow);
            }

            if (ImGui::MenuItem("Izlaz", nullptr))
            {
                spdlog::info("Exiting application...");
                event_system_.Set(Events::Exit);
            }

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Pomoc"))
        {
            if(ImGui::MenuItem("O aplikaciji", nullptr))
            {
                event_system_.Set(Events::About_OpenWindow);
            }

            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}

}  // namespace GUI