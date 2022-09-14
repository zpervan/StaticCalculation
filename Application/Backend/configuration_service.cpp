#include "Application/Backend/configuration_service.h"

#include <imgui.h>
#include <spdlog/spdlog.h>

namespace
{
bool options_changed{false};
}

namespace Backend
{

Options& ConfigurationService::MutableOptions()
{
    options_changed = true;
    return options_;
}

void ConfigurationService::ApplyOptions()
{
    if (options_changed)
    {
        spdlog::info("Applying new options");

        if (options_.application_theme == ApplicationTheme::Dark)
        {
            ImGui::StyleColorsDark();
        }

        if (options_.application_theme == ApplicationTheme::Light)
        {
            ImGui::StyleColorsLight();
        }

        if (options_.application_theme == ApplicationTheme::Classic)
        {
            ImGui::StyleColorsClassic();
        }

        options_changed = false;
    }
}

}  // namespace Backend
