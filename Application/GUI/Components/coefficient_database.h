#ifndef STATICCALCULATION_COEFFICIENT_DATABASE_H
#define STATICCALCULATION_COEFFICIENT_DATABASE_H

#include "Application/Core/event_system.h"

namespace GUI
{

class CoefficientDatabase
{
  public:
    CoefficientDatabase(EventSystem& event_system);
    void Show();

  private:
    EventSystem& event_system_;
    bool is_open_{false};
};

}  // namespace GUI
#endif  // STATICCALCULATION_COEFFICIENT_DATABASE_H
