#ifndef STATICCALCULATION_NEW_COMPONENT_POPUP_H
#define STATICCALCULATION_NEW_COMPONENT_POPUP_H

#include <imgui.h>

#include "Application/Core/event_system.h"
#include "Application/GUI/Elements/button.h"

namespace GUI
{

class NewComponentPopup
{
  public:
    NewComponentPopup(EventSystem& event_system);
    void Show();

  private:
    EventSystem& event_system_;
    ImVec2 size_;

    Button confirm_button_;
    Button cancel_button_;
};

}  // namespace GUI

#endif  // STATICCALCULATION_NEW_COMPONENT_POPUP_H
