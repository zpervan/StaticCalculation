#ifndef STATICCALCULATION_CONFIGURATION_SERVICE_H
#define STATICCALCULATION_CONFIGURATION_SERVICE_H

#include <map>
#include <string>

namespace Backend
{

enum class ApplicationTheme
{
    Dark = 0,
    Light,
    Classic
};

static std::map<ApplicationTheme, std::string> mapped_app_theme_types{{ApplicationTheme::Dark, "Dark"},
                                                               {ApplicationTheme::Light, "Light"},
                                                               {ApplicationTheme::Classic, "Classic"}};

struct Options
{
    ApplicationTheme application_theme{ApplicationTheme::Dark};
};

class ConfigurationService
{
  public:
    /// @brief Allows to change the application options during runtime.
    /// @return Mutable options
    Options& MutableOptions();

    /// @brief Apply options changes.
    void ApplyOptions();

  private:
    Options options_;
};

}  // namespace Backend
#endif  // STATICCALCULATION_CONFIGURATION_SERVICE_H
