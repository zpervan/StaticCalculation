#include "button.h"

GUI::Button::Button(EventSystem& event_system)
    : event_system_(event_system), size_({120, 30}), x_position_(0.0f), y_position_(0.0f)
{
}

void GUI::Button::SetText(const std::string& button_text)
{
    id_ = Id::GenerateIdWithLabel(button_text);
    button_text_ = button_text;
}

void GUI::Button::SetSize(ImVec2 size)
{
    size_ = size;
}

void GUI::Button::HorizontalAlignment(ButtonHorizontalAlignment button_horizontal_alignment, ImVec2 parent_window_size)
{
    assert(parent_window_size.x > 0.0f && parent_window_size.y > 0.0f && "Parent window size must be valid");

    if (ButtonHorizontalAlignment::Left == button_horizontal_alignment)
    {
        x_position_ = (parent_window_size.x - size_.x) * (0.5f / 8.0f);
    }

    if (ButtonHorizontalAlignment::Center == button_horizontal_alignment)
    {
        x_position_ = (parent_window_size.x - size_.x) * (4.0f / 8.0f);
    }

    if (ButtonHorizontalAlignment::Right == button_horizontal_alignment)
    {
        x_position_ = (parent_window_size.x - size_.x) * (7.5f / 8.0f);
    }
}

void GUI::Button::VerticalAlignment(ButtonVerticalAlignment button_vertical_alignment, ImVec2 parent_window_size)
{
    assert(parent_window_size.x > 0.0f && parent_window_size.y > 0.0f && "Parent window size must be valid");

    if (ButtonVerticalAlignment::Up == button_vertical_alignment)
    {
        y_position_ = (parent_window_size.y - size_.y) * (1.0f / 8.0f);
    }

    if (ButtonVerticalAlignment::Center == button_vertical_alignment)
    {
        y_position_ = (parent_window_size.y - size_.y) * (4.0f / 8.0f);
    }

    if (ButtonVerticalAlignment::Down == button_vertical_alignment)
    {
        y_position_ = (parent_window_size.y - size_.y) * (7.5f / 8.0f);
    }
}

bool GUI::Button::Show()
{
    assert(!button_text_.empty() && "Button text must be set before usage");

    if(x_position_)
    {
        ImGui::SetCursorPosX(x_position_);
    }

    if(y_position_)
    {
        ImGui::SetCursorPosY(y_position_);
    }

    return ImGui::Button(id_.c_str(), size_);
}
