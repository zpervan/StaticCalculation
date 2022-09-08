#ifndef STATICCALCULATION_FERT_PAGE_H
#define STATICCALCULATION_FERT_PAGE_H

#include "Application/Backend/coefficient_service.h"
#include "Application/Core/event_system.h"
#include "Application/GUI/Components/coefficient_table.h"
#include "Application/GUI/Components/image_area.h"
#include "Application/GUI/Components/reactions_table.h"
#include "Application/GUI/Pages/ibase_page.h"

namespace GUI
{
class FertPage : public IBasePage
{
  public:
    FertPage(EventSystem& event_system, Backend::CoefficientService& coefficient_service);
    void Show() override;

  private:
    EventSystem& event_system_;
    Backend::CoefficientService& coefficient_service_;
    CoefficientTable constant_load_table_;
    CoefficientTable moving_load_table_;
    ReactionsTable summary_table_;
    ImageArea static_scheme_;
};

}  // namespace GUI

#endif  // STATICCALCULATION_FERT_PAGE_H
