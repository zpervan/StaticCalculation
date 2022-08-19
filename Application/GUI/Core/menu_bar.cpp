#include "menu_bar.h"

#include <imgui.h>
#include <spdlog/spdlog.h>

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
            ImGui::MenuItem("Ponovno pokreni", nullptr);

            if (ImGui::MenuItem("Ugasi", nullptr))
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
