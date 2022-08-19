#include "main_window.h"

#include <imgui.h>

#include "Application/Backend/fert.h"
#include "Application/Core/configuration.h"
#include "Application/Core/values.h"
#include "Application/GUI/Components/input_fields.h"
#include "Application/GUI/constants.h"

namespace
{
ImGuiWindowFlags window_flags{ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration};
}  // namespace

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
    GUI::InputFloatField("Gotovi pod: ", Values::GOTOVI_POD, GUI::Constants::KNM2);
    GUI::InputFloatField("Estrih: ", Values::ESTRIH, GUI::Constants::KNM2);
    GUI::InputFloatField("Termoizolacija: ", Values::TERMOIZOLACIJA, GUI::Constants::KNM2);
    GUI::InputFloatField("Predgradni zidovi: ", Values::PREGRADNI_ZIDOVI, GUI::Constants::KNM2);
    GUI::InputFloatField("Vlastita tezina stropne konstrukcije: ", Values::TEZINA_STROPNE_KONS, GUI::Constants::KNM2);
    GUI::InputFloatField("Podgled: ", Values::PODGLED, GUI::Constants::KNM2);
    ImGui::NewLine();

    Values::UKUPNO_OPTERECENJE = Backend::calculateLoad(Values::GOTOVI_POD,
                                                        Values::ESTRIH,
                                                        Values::TERMOIZOLACIJA,
                                                        Values::PREGRADNI_ZIDOVI,
                                                        Values::TEZINA_STROPNE_KONS,
                                                        Values::PODGLED);

    ImGui::Text("Ukupno stalno opterecenje: %f %s", Values::UKUPNO_OPTERECENJE, GUI::Constants::KNM2);

    ImGui::NewLine();
    ImGui::Text("Pokretno opterecenje");
    ImGui::Separator();
    ImGui::NewLine();

    GUI::InputFloatField("Za stambene prostorije: ", Values::STAMBENE_PROSTORIJE, GUI::Constants::KNM2);


    ImGui::End();
}
