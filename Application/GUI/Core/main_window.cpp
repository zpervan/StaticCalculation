#include "main_window.h"

#include <imgui.h>
#include <spdlog/spdlog.h>

#include "Application/Core/configuration.h"
#include "Application/GUI/Core/id.h"

namespace
{
ImGuiWindowFlags main_window_flags{ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove |
                                   ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBringToFrontOnFocus |
                                   ImGuiWindowFlags_AlwaysVerticalScrollbar};
}  // namespace

namespace GUI
{

MainWindow::MainWindow(EventSystem& event_system,
                       Backend::PageService& page_service,
                       Backend::CoefficientService& coefficient_service)
    : event_system_(event_system),
      page_service_(page_service),
      coefficient_service_(coefficient_service),
      page_factory_(PageFactory(event_system_, page_service_, coefficient_service_))
{
}

MainWindow::~MainWindow()
{
    for (auto component : pages_)
    {
        delete component.second;
        component.second = nullptr;
    }
}

void MainWindow::Show()
{
    ImGui::SetNextWindowPos({0.0f, Configuration::MENU_BAR_HEIGHT});

    const float window_height{Configuration::WINDOW_HEIGHT - Configuration::MENU_BAR_HEIGHT};
    ImGui::SetNextWindowSize({Configuration::WINDOW_WIDTH, window_height});

    ImGui::Begin("##MainWindow", nullptr, main_window_flags);

    ImGui::BeginTabBar("##MainWindowTabBar");

    if (event_system_.Poll() == Events::CreateNewPage)
    {
        const auto page_title{page_service_.GetPages().back().first};
        const auto page_type{page_service_.GetPages().back().second};

        auto new_page{std::make_pair(page_title, page_factory_.CreatePage(page_type))};

        if (new_page.second != nullptr)
        {
            pages_.emplace_back(page_title, page_factory_.CreatePage(page_type));
        }

        event_system_.Set(Events::None);
    }

    for (auto& component : pages_)
    {
        if (ImGui::BeginTabItem(component.first.c_str(), nullptr, ImGuiTabItemFlags_None))
        {
            component.second->Show();
            ImGui::EndTabItem();
        }
    }

    if (ImGui::TabItemButton("+"))
    {
        event_system_.Set(Events::NewComponent_OpenWindow);
    }

    ImGui::EndTabBar();

    ImGui::End();
}
}  // namespace GUI
