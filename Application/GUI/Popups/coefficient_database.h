#ifndef STATICCALCULATION_COEFFICIENT_DATABASE_H
#define STATICCALCULATION_COEFFICIENT_DATABASE_H

#include "Application/Backend/coefficient_service.h"
#include "Application/Core/event_system.h"
#include "Application/GUI/Components/button.h"
#include "Application/GUI/Components/combo_box.h"

namespace GUI
{

class CoefficientDatabase
{
  public:
    CoefficientDatabase(EventSystem& event_system, Backend::CoefficientService& coefficient_service);
    void Show();

  private:
    EventSystem& event_system_;
    Backend::CoefficientService& coefficient_service_;
    std::map<std::string, float>* selected_database_;
    std::map<std::string, float>::iterator row_to_remove_;
    std::string selected_coefficient_group_;
    std::string previously_selected_coefficient_group_;

    ImVec2 size_;
    ComboBox coefficient_group_combo_box_;
    Button save_button_;
    Button close_button_;
    bool is_open_{false};
};

}  // namespace GUI
#endif  // STATICCALCULATION_COEFFICIENT_DATABASE_H
