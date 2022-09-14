#ifndef STATICCALCULATION_OPTIONS_POPUP_H
#define STATICCALCULATION_OPTIONS_POPUP_H

#include <imgui.h>

#include "Application/Backend/configuration_service.h"
#include "Application/Core/event_system.h"
#include "Application/GUI/Components/button.h"

namespace GUI
{

class OptionsPopup
{
  public:
    OptionsPopup(EventSystem& event_system, Backend::ConfigurationService& configuration_service);
    void Show();

  private:
    EventSystem& event_system_;
    Backend::ConfigurationService& configuration_service_;

    // GUI
    ImVec2 size_;
    Button close_button_;
};

}  // namespace GUI

#endif  // STATICCALCULATION_OPTIONS_POPUP_H
