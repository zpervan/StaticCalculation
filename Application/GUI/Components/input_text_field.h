#ifndef STATICCALCULATION_INPUT_TEXT_FIELD_H
#define STATICCALCULATION_INPUT_TEXT_FIELD_H

#include <imgui.h>

#include <string>

namespace GUI
{

static inline void InputTextField(const std::string& label, char* text_buffer, const char * hint = nullptr, const char * trailing_text = nullptr)
{
    ImGui::Text("%s", label.data());
    ImGui::SameLine();
    const auto label_id{"##" + label};
    ImGui::InputTextWithHint(label_id.data(), hint, text_buffer, IM_ARRAYSIZE(text_buffer));
    ImGui::SameLine(0.0f, 1.0f);
    ImGui::Text("%s", trailing_text);
}

}  // namespace GUI

#endif  // STATICCALCULATION_INPUT_TEXT_FIELD_H
