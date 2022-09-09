#include "dummy_page.h"

namespace GUI
{

void DummyPage::Show()
{
    ImGui::SetCursorPos(ImGui::GetMainViewport()->GetCenter());
    ImGui::Text("U razvoju");
}

}  // namespace GUI