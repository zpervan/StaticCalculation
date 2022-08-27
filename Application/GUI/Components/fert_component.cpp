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
      moving_load_table_(CoefficientTable(event_system_)),
      summary_table_(event_system_)
{
    Backend::PopulateCoefficientDatabase();

    auto* constant_load_coefficients = new Backend::LoadCoefficients();
    constant_load_coefficients->load_coefficients_database = Backend::QueryByKey("Stalni teret");
    constant_load_table_.SetLoadCoefficients(constant_load_coefficients);
    constant_load_table_.SetSummaryResultVariable(Backend::constant_load_sum);

    auto* moving_load_coefficients = new Backend::LoadCoefficients();
    moving_load_coefficients->load_coefficients_database = Backend::QueryByKey("Pokretni teret");
    moving_load_table_.SetLoadCoefficients(moving_load_coefficients);
    moving_load_table_.SetSummaryResultVariable(Backend::moving_load_sum);

    summary_table_.SetConstantLoadSum(Backend::constant_load_sum);
    summary_table_.SetMovingLoadSum(Backend::moving_load_sum);
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

    ImGui::Separator();

    summary_table_.Show();
}

}  // namespace GUI
