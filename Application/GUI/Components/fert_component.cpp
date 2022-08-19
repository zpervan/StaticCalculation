#include "fert_component.h"

#include <imgui.h>

#include "Application/Backend/fert.h"
#include "Application/Core/values.h"
#include "Application/GUI/Core/constants.h"
#include "Application/GUI/Elements/input_fields.h"

namespace GUI
{

Fert::Fert(EventSystem& event_system) : event_system_(event_system) {}

void Fert::Show()
{
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
    ImGui::Text("A2. Pokretno opterecenje");
    ImGui::NewLine();

    GUI::InputFloatField("Za stambene prostorije: ", Values::STAMBENE_PROSTORIJE, GUI::Constants::KNM2);

    ImGui::NewLine();

    if (ImGui::BeginTable("table1", 5))
    {

        ImGui::TableSetupColumn("POZICIJA");
        ImGui::TableSetupColumn("SVIJETLI RASPON IZMEDU ZIDOVA Io(m)");
        ImGui::TableSetupColumn("STATICKI RASPON I(m)");
        ImGui::TableSetupColumn("REAKCIJA (RA, RB) - STALNO (kn)");
        ImGui::TableSetupColumn("REAKCIJA (RA, RB) - POKRETNO (kN)");
        ImGui::TableHeadersRow();

        for (int row = 0; row < 5; row++)
        {
            ImGui::TableNextRow();
            for (int column = 0; column < 5; column++)
            {
                ImGui::TableSetColumnIndex(column);
                char buf[32];
                sprintf(buf, "Gumenje kamenje %d,%d", column, row);
                ImGui::TextUnformatted(buf);
                //                ImGui::Button(buf, ImVec2(-FLT_MIN, 0.0f));
            }
        }

        ImGui::EndTable();
    }
}

}  // namespace GUI