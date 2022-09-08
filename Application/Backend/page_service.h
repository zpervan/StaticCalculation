#ifndef STATICCALCULATION_PAGE_SERVICE_H
#define STATICCALCULATION_PAGE_SERVICE_H

#include <string>
#include <vector>

#include "Application/Core/event_system.h"

namespace Backend
{

enum class PageType
{
    Fert = 0,
    Podroznica,
    Stup
};

class PageService
{
  public:
    PageService(EventSystem& event_system);
    void Add(const std::string & page_title, PageType page_type);
    std::vector<std::pair<std::string, PageType>>& GetPages();
    PageType ConvertPageType(const std::string & page_type);

  private:
    EventSystem& event_system_;
    std::vector<std::pair<std::string, PageType>> pages_;
};

}  // namespace Backend

#endif  // STATICCALCULATION_PAGE_SERVICE_H
