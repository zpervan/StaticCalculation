#include "menu_bar.h"

#include <imgui.h>
#include <spdlog/spdlog.h>

void MenuBar::Show()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Datoteka"))
        {
            if (ImGui::MenuItem("Spremi", "Ctrl+S"))
            {
                spdlog::info("Spremam dokument...");
            }

            if(ImGui::MenuItem("Otvori", nullptr))
            {
                spdlog::info("Otvaram dokument...");
            }

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Applikacija"))
        {
            ImGui::MenuItem("Ponovno pokreni", nullptr);

            if (ImGui::MenuItem("Ugasi", nullptr))
            {
                spdlog::info("Izlazim iz aplikacije");
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
