#ifndef STATICCALCULATION_MENU_BAR_H
#define STATICCALCULATION_MENU_BAR_H

#include "Application/Core/event_system.h"

namespace GUI
{

class MenuBar
{
  public:
    MenuBar(EventSystem& event_system);
    void Show();

  private:
    EventSystem& event_system_;
};

}  // namespace GUI

#endif  // STATICCALCULATION_MENU_BAR_H
