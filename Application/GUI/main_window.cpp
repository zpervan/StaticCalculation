#include "main_window.h"

#include <imgui.h>

#include <string>

#include "Application/Core/configuration.h"

namespace
{
ImGuiWindowFlags window_flags {ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration};
}

MainWindow::MainWindow(EventSystem& event_system) : event_system_(event_system) {}

void MainWindow::Show()
{
    ImGui::SetNextWindowPos({0.0f, Configuration::MENU_BAR_HEIGHT});
    ImGui::SetNextWindowSize({Configuration::WINDOW_WIDTH, Configuration::WINDOW_HEIGHT - Configuration::MENU_BAR_HEIGHT});

    ImGui::Begin("##MainWindow", nullptr, window_flags);

    ImGui::Text("Staticka shema");

    /// @TODO: Add content

    ImGui::NewLine();

    ImGui::Text("Analiza opterecenja");

    /// @TODO: Add content

    ImGui::End();
}
