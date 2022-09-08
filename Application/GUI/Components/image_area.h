#ifndef STATICCALCULATION_IMAGE_AREA_H
#define STATICCALCULATION_IMAGE_AREA_H

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_filebrowser.h>

#include <string>

#include "Application/Core/event_system.h"

namespace GUI
{

class ImageArea
{
  public:
    ImageArea(EventSystem& event_system);
    void LoadImageToBuffer(const std::string& image_path);
    void Show();

  private:
    EventSystem& event_system_;
    std::string image_path_;
    ImGui::FileBrowser image_file_browser_;

    int width_{0};
    int height_{0};
    GLuint texture_{0};
};

}  // namespace GUI

#endif  // STATICCALCULATION_IMAGE_AREA_H
