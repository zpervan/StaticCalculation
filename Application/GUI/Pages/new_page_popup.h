#ifndef STATICCALCULATION_NEW_PAGE_POPUP_H
#define STATICCALCULATION_NEW_PAGE_POPUP_H

#include <imgui.h>

#include "Application/Core/event_system.h"
#include "Application/Backend/page_service.h"
#include "Application/GUI/Components/button.h"
#include "Application/GUI/Components/combo_box.h"

namespace GUI
{

class NewPagePopup
{
  public:
    NewPagePopup(EventSystem& event_system, Backend::PageService& page_service);
    void Show();

  private:
    EventSystem& event_system_;
    Backend::PageService& page_service_;
    ImVec2 size_;
    std::string selected_page_;

    // GUI Elements
    ComboBox new_page_tab_list_;
    Button confirm_button_;
    Button cancel_button_;
};

}  // namespace GUI

#endif  // STATICCALCULATION_NEW_PAGE_POPUP_H
