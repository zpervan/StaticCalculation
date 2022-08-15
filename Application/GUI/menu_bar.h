#ifndef STATICCALCULATION_MENU_BAR_H
#define STATICCALCULATION_MENU_BAR_H

#include "Application/Core/event_system.h"

class MenuBar
{
  public:
    MenuBar(EventSystem& event_system);
    void Show();

  private:
    EventSystem& event_system_;
};

#endif  // STATICCALCULATION_MENU_BAR_H
