#ifndef STATICCALCULATION_COMBO_BOX_H
#define STATICCALCULATION_COMBO_BOX_H

#include <imgui.h>

#include <algorithm>
#include <map>
#include <vector>

#include "Application/Backend/fert_backend.h"
#include "Application/Core/event_system.h"

namespace GUI
{

class ComboBox
{
  public:
    ComboBox(EventSystem& event_system);
    void Show(const std::map<std::string, float>& values, std::pair<std::string, float>& selected_value);
    void Show(const std::map<std::string, std::map<std::string, float>>& values, std::string& selected_value);
    void Show(const std::vector<std::string>& values, std::string& selected_value);

  private:
    EventSystem& event_system_;
    /// @TODO: Add ID management system
    std::string combo_box_label_;
    std::size_t current_coefficient_idx_{0};
};
}  // namespace GUI

#endif  // STATICCALCULATION_COMBO_BOX_H
