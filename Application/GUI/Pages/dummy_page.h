#ifndef STATICCALCULATION_DUMMY_PAGE_H
#define STATICCALCULATION_DUMMY_PAGE_H

#include <imgui.h>

#include "Application/GUI/Pages/ibase_page.h"

namespace GUI
{

class DummyPage : public IBasePage
{
  public:
    void Show() override;

  private:
    ImVec2 center_position_;
};

}  // namespace GUI
#endif  // STATICCALCULATION_DUMMY_PAGE_H
