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
      summary_table_(event_system_),
      static_scheme_(event_system_)
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

    static_scheme_.LoadImageToBuffer(Paths::StaticSchemeImageFilePath());
}

void Fert::Show()
{
    /// @TODO: Make a element with text formatting options
    static char text[1024 * 16] = "Unesite opisni tekst\n";
    ImGui::InputTextMultiline( "##source", text, IM_ARRAYSIZE(text), ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 16), ImGuiInputTextFlags_AllowTabInput);

    GUI::TextWithPadding("Staticka shema", true);
    static_scheme_.Show();

    GUI::TextWithPadding("Analiza opterecenja", true);

    GUI::TextWithPadding("A1. Stalni teret");
    constant_load_table_.Show();

    GUI::TextWithPadding("A2. Pokretno opterecenje");
    moving_load_table_.Show();

    ImGui::Separator();

    summary_table_.Show();
}

}  // namespace GUI
