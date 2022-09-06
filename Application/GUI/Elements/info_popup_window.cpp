#include "info_popup_window.h"

#include <imgui.h>

#include "Application/GUI/Core/id.h"

namespace
{
ImGuiWindowFlags flags{ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize};
}

namespace GUI
{

InfoPopupWindow::InfoPopupWindow(EventSystem& event_system)
    : event_system_(event_system), close_button_(Button(event_system_)), size_({300.0f, 300.0f}), id_(Id::GenerateId())
{
    close_button_.SetText("Zatvori");
    close_button_.HorizontalAlignment(ButtonHorizontalAlignment::Center, size_);
    close_button_.VerticalAlignment(ButtonVerticalAlignment::Down, size_);
}

void InfoPopupWindow::Show(const std::string& text)
{
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(size_);

    if (ImGui::Begin(id_.c_str(), nullptr, flags))
    {
        ImGui::Text("%s", text.c_str());

        if (close_button_.Show())
        {
            event_system_.Set(Events::None);
        }

        ImGui::End();
    }
}

const ImVec2& InfoPopupWindow::GetSize() const
{
    return size_;
}

void InfoPopupWindow::SetSize(const ImVec2& size)
{
    size_ = size;
}

}  // namespace GUI