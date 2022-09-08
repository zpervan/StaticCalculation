#include "image_area.h"

#include <spdlog/spdlog.h>

#include "Application/GUI/Core/image_loader.h"

namespace GUI
{

ImageArea::ImageArea(EventSystem& event_system) : event_system_(event_system), image_file_browser_(ImGui::FileBrowser())
{
    image_file_browser_.SetTitle("Dodaj sliku...");
}

void ImageArea::LoadImageToBuffer(const std::string& image_path)
{
    if (image_path_ != image_path)
    {
        image_path_ = image_path;
    }

    const bool is_image_loaded = GUI::LoadTextureFromFile(image_path_.c_str(), &texture_, &width_, &height_);

    assert(is_image_loaded);
}

void ImageArea::Show()
{
    if (!image_path_.empty())
    {
        ImGui::Image((void*)(intptr_t)texture_, ImVec2(width_, height_));
    }
    else
    {
        ImGui::Text("Dodaj shemu");
    }

    if (ImGui::Button("Dodaj##ImageArea"))
    {
        spdlog::debug("Opening image file browser");
        image_file_browser_.Open();
    }

    if (image_file_browser_.HasSelected())
    {
        image_path_ = image_file_browser_.GetSelected().string();
        LoadImageToBuffer(image_path_);
        spdlog::debug("Loading image on path: {}", image_path_);
    }

    image_file_browser_.Display();
}

}  // namespace GUI
