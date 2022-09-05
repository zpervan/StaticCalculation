#include "main_window.h"

#include <imgui.h>
#include <spdlog/spdlog.h>

#include "Application/Core/configuration.h"
#include "Application/GUI/Core/id.h"

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

MainWindow::MainWindow(EventSystem& event_system) : event_system_(event_system){}

MainWindow::~MainWindow()
{
    for (auto component : components_)
    {
        delete component.second;
        component.second = nullptr;
    }
}

void MainWindow::Show()
{
    ImGui::SetNextWindowPos({0.0f, Configuration::MENU_BAR_HEIGHT});
    ImGui::SetNextWindowSize({Configuration::WINDOW_WIDTH, Configuration::WINDOW_HEIGHT - Configuration::MENU_BAR_HEIGHT});

    ImGui::Begin("##MainWindow", nullptr, main_window_flags);

    ImGui::BeginTabBar("##MainWindowTabBar");

    for(auto & component : components_)
    {
        if (ImGui::BeginTabItem(component.first.c_str(), nullptr, ImGuiTabItemFlags_None))
        {
            component.second->Show();
            ImGui::EndTabItem();
        }
    }

    if (ImGui::TabItemButton("+"))
    {
        components_.emplace_back(std::make_pair(Id::GenerateIdWithLabel("FERT"), new GUI::Fert(event_system_)));
    }

    ImGui::EndTabBar();

    ImGui::End();
}
}  // namespace GUI
