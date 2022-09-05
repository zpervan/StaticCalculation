#ifndef STATICCALCULATION_MAIN_WINDOW_H
#define STATICCALCULATION_MAIN_WINDOW_H

#include "Application/Core/event_system.h"
#include "Application/GUI/Components/fert_component.h"
#include <vector>

namespace GUI
{

class MainWindow
{
  public:
    MainWindow(EventSystem& event_system);
    ~MainWindow();
    void Show();

  private:
    EventSystem& event_system_;
    std::vector<std::pair<std::string, IBaseComponent*>> components_;
};

}  // namespace GUI

#endif  // STATICCALCULATION_MAIN_WINDOW_H
