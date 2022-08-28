#ifndef STATICCALCULATION_FERT_COMPONENT_H
#define STATICCALCULATION_FERT_COMPONENT_H

#include "Application/Core/event_system.h"
#include "Application/GUI/Components/ibase_component.h"
#include "Application/GUI/Elements/coefficient_table.h"
#include "Application/GUI/Elements/reactions_table.h"
#include "Application/GUI/Elements/image_area.h"

namespace GUI
{
class Fert : public IBaseComponent
{
  public:
    Fert(EventSystem& event_system);
    void Show() override;

  private:
    EventSystem& event_system_;
    CoefficientTable constant_load_table_;
    CoefficientTable moving_load_table_;
    ReactionsTable summary_table_;
    ImageArea static_scheme_;
};

}  // namespace GUI

#endif  // STATICCALCULATION_FERT_COMPONENT_H
