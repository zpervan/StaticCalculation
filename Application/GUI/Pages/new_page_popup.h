#ifndef STATICCALCULATION_NEW_PAGE_POPUP_H
#define STATICCALCULATION_NEW_PAGE_POPUP_H

#include <imgui.h>

#include "Application/Core/event_system.h"
#include "Application/GUI/Components/button.h"
#include "Application/GUI/Components/combo_box.h"

namespace GUI
{

class NewPagePopup
{
  public:
    NewPagePopup(EventSystem& event_system);
    void Show();

  private:
    EventSystem& event_system_;
    ImVec2 size_;
    std::string selected_component_;

    // GUI Elements
    ComboBox new_component_tab_list_;
    Button confirm_button_;
    Button cancel_button_;
};

}  // namespace GUI

#endif  // STATICCALCULATION_NEW_PAGE_POPUP_H
