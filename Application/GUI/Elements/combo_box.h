#ifndef STATICCALCULATION_COMBO_BOX_H
#define STATICCALCULATION_COMBO_BOX_H

#include <imgui.h>

#include <algorithm>
#include <map>

#include "Application/Backend/fert_backend.h"
#include "Application/Core/event_system.h"

namespace GUI
{

class ComboBox
{
  public:
    ComboBox(EventSystem& event_system);
    void Show(const std::map<std::string, float>& values, std::pair<std::string, float>& selected_value);

  private:
    EventSystem& event_system_;
    /// @TODO: Add ID management system
    std::string combo_box_label_;
    int current_coefficient_idx_{0};
};
}  // namespace GUI

#endif  // STATICCALCULATION_COMBO_BOX_H
