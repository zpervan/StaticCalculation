#include "image_area.h"

#include <imgui.h>

#include "Application/GUI/Core/image_loader.h"

GUI::ImageArea::ImageArea(EventSystem& event_system) : event_system_(event_system) {}

void GUI::ImageArea::LoadImage(const std::string& image_path)
{
    if (image_path_ != image_path)
    {
        image_path_ = image_path;
    }

    const bool is_image_loaded = GUI::LoadTextureFromFile(image_path_.c_str(), &texture_, &width_, &height_);

    assert(is_image_loaded);
}

void GUI::ImageArea::Show()
{
    if (!image_path_.empty())
    {
        ImGui::Image((void*)(intptr_t)texture_, ImVec2(width_, height_));
    }
    else
    {
        ImGui::Text("Dodaj shemu");
    }

    if(ImGui::Button("Dodaj##ImageArea"))
    {
        /// @TODO: Add file explorer menu
    }
}
