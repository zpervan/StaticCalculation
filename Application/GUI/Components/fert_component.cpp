#include "fert_component.h"

#include <imgui.h>

#include "Application/Backend/fert_backend.h"
#include "Application/GUI/Elements/combo_box.h"
#include "Application/GUI/Elements/input_fields.h"
#include "Application/GUI/Elements/text_with_padding.h"

namespace GUI
{

Fert::Fert(EventSystem& event_system)
    : event_system_(event_system),
      constant_load_table_(CoefficientTable(event_system_)),
      moving_load_table_(CoefficientTable(event_system_))
{
    Backend::LoadCoefficients constant_load_coefficients;
    constant_load_coefficients.load_coefficients_database = Backend::constant_load_coefficients_database;
    constant_load_table_.SetLoadCoefficients(constant_load_coefficients);

    Backend::LoadCoefficients moving_load_coefficients;
    moving_load_coefficients.load_coefficients_database = Backend::moving_load_coefficients_database;
    moving_load_table_.SetLoadCoefficients(moving_load_coefficients);
}

void Fert::Show()
{
    GUI::TextWithPadding("Staticka shema", true);
    GUI::TextWithPadding("TODO: Dodaj sadrzaj");
    /// @TODO: Add content

    GUI::TextWithPadding("Analiza opterecenja", true);

    GUI::TextWithPadding("A1. Stalni teret");
    constant_load_table_.Show();

    GUI::TextWithPadding("A2. Pokretno opterecenje");
    moving_load_table_.Show();

    ImGui::NewLine();

    if (ImGui::BeginTable("##FertMovingLoadTable", 5, ImGuiTableFlags_Borders))
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
            }
        }

        ImGui::EndTable();
    }
}

}  // namespace GUI
