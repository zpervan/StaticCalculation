#ifndef STATICCALCULATION_FERT_COMPONENT_H
#define STATICCALCULATION_FERT_COMPONENT_H

#include "Application/Core/event_system.h"
#include "Application/GUI/Components/ibase_component.h"

namespace GUI
{
class Fert : public IBaseComponent
{
  public:
    Fert(EventSystem& event_system);
    void Show() override;

  private:
    EventSystem& event_system_;
};

}  // namespace GUI

#endif  // STATICCALCULATION_FERT_COMPONENT_H
