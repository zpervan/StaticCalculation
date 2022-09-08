#include "page_service.h"

#include <spdlog/spdlog.h>

#include <map>

namespace
{
std::map<std::string, Backend::PageType> string_to_page_type{{"Fert", Backend::PageType::Fert},
                                                             {"Podroznica", Backend::PageType::Podroznica},
                                                             {"Stup", Backend::PageType::Stup}};
}

namespace Backend
{

Backend::PageService::PageService(EventSystem& event_system) : event_system_(event_system) {}

void Backend::PageService::Add(const std::string& page_title, Backend::PageType page_type)
{
    spdlog::info("Adding page \"{}\"", page_title);
    pages_.emplace_back(page_title, page_type);
    event_system_.Set(Events::CreateNewPage);
}

std::vector<std::pair<std::string, PageType>>& Backend::PageService::GetPages()
{
    return pages_;
}

PageType PageService::ConvertPageType(const std::string& page_type)
{
    return string_to_page_type[page_type];
}

}  // namespace Backend