#ifndef STATICCALCULATION_BUTTON_H
#define STATICCALCULATION_BUTTON_H

#include <imgui.h>

#include <string>

#include "Application/Core/event_system.h"
#include "Application/GUI/Core/id.h"

namespace GUI
{

enum class ButtonHorizontalAlignment
{
    Left = 0,
    Center,
    Right
};

enum class ButtonVerticalAlignment
{
    Up = 0,
    Center,
    Down
};

class Button
{
  public:
    Button(EventSystem& event_system);

    void SetText(const std::string& button_text);
    void SetSize(ImVec2 size);
    void HorizontalAlignment(GUI::ButtonHorizontalAlignment button_horizontal_alignment, ImVec2 parent_window_size);
    void VerticalAlignment(GUI::ButtonVerticalAlignment button_vertical_alignment, ImVec2 parent_window_size);

    bool Show();

  private:
    EventSystem& event_system_;

    ImVec2 size_;
    float x_position_;
    float y_position_;

    std::string button_text_;
    std::string id_;
};

}  // namespace GUI

#endif  // STATICCALCULATION_BUTTON_H
