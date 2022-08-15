#include "main_window.h"

#include <imgui.h>

#include "Application/Core/configuration.h"
#include "Application/Core/values.h"
#include "Application/GUI/Components/input_text_field.h"
#include "Application/GUI/constants.h"

namespace
{
ImGuiWindowFlags window_flags{ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration};
}

MainWindow::MainWindow(EventSystem& event_system) : event_system_(event_system) {}

void MainWindow::Show()
{
    ImGui::SetNextWindowPos({0.0f, Configuration::MENU_BAR_HEIGHT});
    ImGui::SetNextWindowSize(
        {Configuration::WINDOW_WIDTH, Configuration::WINDOW_HEIGHT - Configuration::MENU_BAR_HEIGHT});

    ImGui::Begin("##MainWindow", nullptr, window_flags);

    ImGui::Text("Staticka shema");
    ImGui::Separator();
    ImGui::Text("TODO: Dodaj sadrzaj");
    /// @TODO: Add content

    ImGui::NewLine();

    ImGui::Text("Analiza opterecenja");
    ImGui::Separator();
    ImGui::NewLine();
    ImGui::Text("A1. Stalni teret");
    GUI::InputTextField("Gotovi pod: ", Values::GOTOVI_POD, "npr. 0.5", GUI::Constants::KNM2);
    GUI::InputTextField("Estrih: ", Values::ESTRIH, "npr. 0.5", GUI::Constants::KNM2);
    GUI::InputTextField("Termoizolacija: ", Values::TERMOIZOLACIJA, "npr. 0.5", GUI::Constants::KNM2);
    GUI::InputTextField("Predgradni zidovi: ", Values::PREGRADNI_ZIDOVI, "npr. 0.5", GUI::Constants::KNM2);
    GUI::InputTextField("Vlastita tezina stropne konstrukcije: ", Values::TEZINA_STROPNE_KONS, "npr. 0.5", GUI::Constants::KNM2);
    GUI::InputTextField("Podgled: ", Values::PODGLED, "npr. 0.5", GUI::Constants::KNM2);
    ImGui::NewLine();
    ImGui::Text("Ukupno stalno opterecenje: ");

    ImGui::End();
}
