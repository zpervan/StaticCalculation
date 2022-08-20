#ifndef STATICCALCULATION_TEXT_WITH_PADDING_H
#define STATICCALCULATION_TEXT_WITH_PADDING_H

#include <imgui.h>

#include <string>

namespace GUI
{
static inline void TextWithPadding(const std::string& text, bool separator = false)
{
    ImGui::NewLine();
    ImGui::Text("%s", text.c_str());

    if (separator)
    {
        ImGui::Separator();
    }

    ImGui::NewLine();
}
}  // namespace GUI

#endif  // STATICCALCULATION_TEXT_WITH_PADDING_H
