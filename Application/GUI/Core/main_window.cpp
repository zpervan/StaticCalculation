#include "main_window.h"

#include <imgui.h>
#include <spdlog/spdlog.h>

#include "Application/Core/configuration.h"

namespace
{
ImGuiWindowFlags main_window_flags{ImGuiWindowFlags_NoCollapse |
                                   ImGuiWindowFlags_NoMove |
                                   ImGuiWindowFlags_NoDecoration |
                                   ImGuiWindowFlags_NoBringToFrontOnFocus |
                                   ImGuiWindowFlags_AlwaysVerticalScrollbar};
}  // namespace

namespace GUI
{

MainWindow::MainWindow(EventSystem& event_system) : event_system_(event_system), fert_(event_system_) {}

void MainWindow::Show()
{
    ImGui::SetNextWindowPos({0.0f, Configuration::MENU_BAR_HEIGHT});
    ImGui::SetNextWindowSize({Configuration::WINDOW_WIDTH, Configuration::WINDOW_HEIGHT - Configuration::MENU_BAR_HEIGHT});

    ImGui::Begin("##MainWindow", nullptr, main_window_flags);

    ImGui::BeginTabBar("##MainWindowTabBar");

    if (ImGui::BeginTabItem("FERT", nullptr, ImGuiTabItemFlags_None))
    {
        fert_.Show();
        ImGui::EndTabItem();
    }

    if (ImGui::TabItemButton("+"))
    {
        spdlog::info("TODO: Implement adding new tabs");
    }

    ImGui::EndTabBar();

    ImGui::End();
}
}  // namespace GUI
