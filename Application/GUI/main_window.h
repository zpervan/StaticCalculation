#ifndef STATICCALCULATION_MAIN_WINDOW_H
#define STATICCALCULATION_MAIN_WINDOW_H

#include "Application/Core/event_system.h"

class MainWindow
{
  public:
    MainWindow(EventSystem& event_system);
    void Show();

  private:
    EventSystem& event_system_;
};

#endif  // STATICCALCULATION_MAIN_WINDOW_H
