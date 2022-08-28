#ifndef STATICCALCULATION_IMAGE_AREA_H
#define STATICCALCULATION_IMAGE_AREA_H

#include <GL/gl.h>

#include <string>

#include "Application/Core/event_system.h"

namespace GUI
{

class ImageArea
{
  public:
    ImageArea(EventSystem& event_system);
    void Show();
    void LoadImage(const std::string& image_path);

  private:
    EventSystem& event_system_;
    std::string image_path_;

    int width_{0};
    int height_{0};
    GLuint texture_{0};
};

}  // namespace GUI

#endif  // STATICCALCULATION_IMAGE_AREA_H
