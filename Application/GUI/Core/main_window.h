#ifndef STATICCALCULATION_MAIN_WINDOW_H
#define STATICCALCULATION_MAIN_WINDOW_H

#include "Application/Core/event_system.h"
#include "Application/GUI/Components/fert_component.h"

namespace GUI
{

class MainWindow
{
  public:
    MainWindow(EventSystem& event_system);
    void Show();

  private:
    EventSystem& event_system_;
    Fert fert_;
};

}  // namespace GUI

#endif  // STATICCALCULATION_MAIN_WINDOW_H
