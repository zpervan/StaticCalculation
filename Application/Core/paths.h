#ifndef STATICCALCULATION_PATHS_H
#define STATICCALCULATION_PATHS_H

#include <filesystem>
#include <string>
#include <spdlog/spdlog.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <linux/limits.h>
#endif

namespace
{
#ifdef WIN32
static constexpr auto Assets_Directory{"\\Application\\Assets"};
static constexpr auto Arial_Font_File{"\\Fonts\\arial.ttf"};
static constexpr auto Fert_Coefficients_File{"\\Coefficients\\fert_koeficijenti.json"};
#else
static constexpr auto Assets_Directory{"/Application/Assets"};
static constexpr auto Arial_Font_File{"/Fonts/arial.ttf"};
static constexpr auto Fert_Coefficients_File{"/Coefficients/fert_koeficijenti.json"};
#endif
}

namespace Paths
{

/// @brief Returns the path of the application executable based on OS.
/// @return Path to executable root directory
inline std::filesystem::path RootPath()
{
#ifdef WIN32
    wchar_t szPath[MAX_PATH];
    GetModuleFileNameW(NULL, szPath, MAX_PATH);
#else
    char szPath[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", szPath, PATH_MAX);
    if (count < 0 || count >= PATH_MAX) return {};  // some error
    szPath[count] = '\0';
#endif

    const auto root_path = std::filesystem::path(szPath).parent_path();

    return root_path;
}

inline std::string ArialFontPath()
{
    return RootPath().string() + Assets_Directory + Arial_Font_File;
}

inline std::string FertCoefficientFilePath()
{
    return RootPath().string() + Assets_Directory + Fert_Coefficients_File;
}

}  // namespace Paths

#endif  // STATICCALCULATION_PATHS_H
