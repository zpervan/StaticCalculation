#ifndef STATICCALCULATION_COEFFICIENT_TABLE_H
#define STATICCALCULATION_COEFFICIENT_TABLE_H

#include <memory>

#include "Application/Backend/fert_backend.h"
#include "Application/Core/event_system.h"
#include "Application/GUI/Elements/combo_box.h"

namespace GUI
{

class CoefficientTable
{
  public:
    CoefficientTable(EventSystem& event_system);
    void SetLoadCoefficients(Backend::LoadCoefficients* load_coefficients);
    void SetSummaryResultVariable(float& summary_result);
    void Show();

  private:
    bool ElementToRemoveExits();

  private:
    EventSystem& event_system_;
    ComboBox load_coefficient_combo_box_;
    std::unique_ptr<Backend::LoadCoefficients> load_coefficients_;
    std::string load_table_label_;
    std::string add_button_label_;
    float * summary_result_;
};

}  // namespace GUI
#endif  // STATICCALCULATION_COEFFICIENT_TABLE_H
