#ifndef STATICCALCULATION_MAIN_WINDOW_H
#define STATICCALCULATION_MAIN_WINDOW_H

#include "Application/Core/event_system.h"
#include "Application/Backend/coefficient_service.h"
#include "Application/GUI/Components/fert_component.h"
#include <vector>

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
    std::vector<std::pair<std::string, IBaseComponent*>> components_;
};

}  // namespace GUI

#endif  // STATICCALCULATION_MAIN_WINDOW_H
