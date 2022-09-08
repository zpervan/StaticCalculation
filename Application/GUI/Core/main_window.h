#ifndef STATICCALCULATION_MAIN_WINDOW_H
#define STATICCALCULATION_MAIN_WINDOW_H

#include <vector>

#include "Application/Backend/coefficient_service.h"
#include "Application/Backend/page_service.h"
#include "Application/Core/event_system.h"
#include "Application/GUI/Pages/page_factory.h"

namespace GUI
{

class MainWindow
{
  public:
    MainWindow(EventSystem& event_system,
               Backend::PageService& page_service,
               Backend::CoefficientService& coefficient_service);
    ~MainWindow();
    void Show();

  private:
    EventSystem& event_system_;
    Backend::PageService& page_service_;
    Backend::CoefficientService& coefficient_service_;
    PageFactory page_factory_;
    std::vector<std::pair<std::string, IBasePage*>> pages_;
};

}  // namespace GUI

#endif  // STATICCALCULATION_MAIN_WINDOW_H
