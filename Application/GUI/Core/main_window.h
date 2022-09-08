#ifndef STATICCALCULATION_MAIN_WINDOW_H
#define STATICCALCULATION_MAIN_WINDOW_H

#include <vector>

#include "Application/Backend/coefficient_service.h"
#include "Application/Core/event_system.h"
#include "Application/GUI/Pages/fert_page.h"

namespace GUI
{

class MainWindow
{
  public:
    MainWindow(EventSystem& event_system, Backend::CoefficientService& coefficient_service);
    ~MainWindow();
    void Show();

  private:
    EventSystem& event_system_;
    Backend::CoefficientService& coefficient_service_;
    std::vector<std::pair<std::string, IBasePage*>> components_;
};

}  // namespace GUI

#endif  // STATICCALCULATION_MAIN_WINDOW_H
