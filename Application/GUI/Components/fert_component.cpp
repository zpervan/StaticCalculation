#include "fert_component.h"

#include <imgui.h>

#include "Application/Backend/fert_backend.h"
#include "Application/Backend/values.h"
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

    /// @TODO: Generate ID has for table so we avoid ID collision
    if (ImGui::BeginTable("##FertParametersTable", 2))
    {
        for (const auto& [key, value] : Backend::fert_coefficients)
        {
            ImGui::TableNextRow();

            ImGui::TableSetColumnIndex(0);
            ImGui::Text("%s", key.c_str());

            ImGui::TableSetColumnIndex(1);
            ImGui::Text("%.2f", value);
        }

        ImGui::EndTable();
    }

    ImGui::Button("Dodaj");
    ImGui::SameLine(0.0f, 10.0f);
    ImGui::Button("Obrisi");

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
