#ifndef STATICCALCULATION_PAGE_FACTORY_H
#define STATICCALCULATION_PAGE_FACTORY_H

#include <spdlog/spdlog.h>

#include "Application/Backend/coefficient_service.h"
#include "Application/Backend/page_service.h"
#include "Application/Core/event_system.h"
#include "Application/GUI/Pages/ibase_page.h"

namespace GUI
{

class PageFactory
{
  public:
    PageFactory(EventSystem& event_system,
                Backend::PageService& page_service,
                Backend::CoefficientService& coefficient_service);

    IBasePage* CreatePage(Backend::PageType page_type);

  private:
    EventSystem& event_system_;
    Backend::PageService& page_service_;
    Backend::CoefficientService& coefficient_service_;
};

}  // namespace GUI

#endif  // STATICCALCULATION_PAGE_FACTORY_H
