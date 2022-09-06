#ifndef STATICCALCULATION_INFO_POPUP_WINDOW_H
#define STATICCALCULATION_INFO_POPUP_WINDOW_H

#include <string>

#include "Application/Core/event_system.h"
#include "Application/GUI/Elements/button.h"

namespace GUI
{

class InfoPopupWindow
{
  public:
    InfoPopupWindow(EventSystem& event_system);
    void Show(const std::string & text);

  private:
    EventSystem& event_system_;
    Button close_button_;
    ImVec2 size_;

  public:
    const ImVec2& GetSize() const;
    void SetSize(const ImVec2& size);

  private:
    std::string id_;
};

}  // namespace GUI

#endif  // STATICCALCULATION_INFO_POPUP_WINDOW_H
