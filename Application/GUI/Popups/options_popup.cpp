#include "options_popup.h"

#include <vector>

namespace
{
ImGuiWindowFlags window_flags{ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
                              ImGuiWindowFlags_Modal};

const char* themes[]{"Dark", "Light", "Classic"};
int previous_selected_theme{0};
int current_selected_theme{0};
}  // namespace

namespace GUI
{

OptionsPopup::OptionsPopup(EventSystem& event_system, Backend::ConfigurationService& configuration_service)
    : event_system_(event_system),
      configuration_service_(configuration_service),
      size_(300.0f, 300.0f),
      close_button_(Button(event_system_))
{
    close_button_.SetText("Zatvori");
    close_button_.HorizontalAlignment(ButtonHorizontalAlignment::Center, size_);
    close_button_.VerticalAlignment(ButtonVerticalAlignment::Down, size_);
}

void OptionsPopup::Show()
{
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(size_);

    if (ImGui::Begin("Postavke", NULL, window_flags))
    {
        ImGui::Text("Opcenito");
        ImGui::Separator();

        ImGui::Text("Odaberi temu:");
        ImGui::SameLine();
        ImGui::SetNextItemWidth(100.0f);
        ImGui::Combo("##ComboOptionsTheme", &current_selected_theme, themes, IM_ARRAYSIZE(themes));

        if (close_button_.Show())
        {
            event_system_.Set(Events::None);
        }

        ImGui::End();
    }

    /// @TODO: Make it more general so we avoid redundant calls options
    if (current_selected_theme != previous_selected_theme)
    {
        previous_selected_theme = current_selected_theme;

        const auto selected_theme{std::next(Backend::mapped_app_theme_types.begin(), current_selected_theme)};
        configuration_service_.MutableOptions().application_theme = selected_theme->first;
    }
}

}  // namespace GUI