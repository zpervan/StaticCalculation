#ifndef STATICCALCULATION_COEFFICIENT_DATABASE_H
#define STATICCALCULATION_COEFFICIENT_DATABASE_H

#include "Application/Core/event_system.h"
#include "Application/GUI/Elements/button.h"

namespace GUI
{

class CoefficientDatabase
{
  public:
    CoefficientDatabase(EventSystem& event_system);
    void Show();

  private:
    EventSystem& event_system_;
    ImVec2 size_;
    Button save_button_;
    Button close_button_;
    bool is_open_{false};
};

}  // namespace GUI
#endif  // STATICCALCULATION_COEFFICIENT_DATABASE_H
