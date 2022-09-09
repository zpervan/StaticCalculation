#include "page_factory.h"

#include "Application/GUI/Pages/dummy_page.h"
#include "Application/GUI/Pages/fert_page.h"

GUI::PageFactory::PageFactory(EventSystem& event_system,
                              Backend::PageService& page_service,
                              Backend::CoefficientService& coefficient_service)
    : event_system_(event_system), page_service_(page_service), coefficient_service_(coefficient_service)
{
}

GUI::IBasePage* GUI::PageFactory::CreatePage(Backend::PageType page_type)
{
    switch (page_type)
    {
        case Backend::PageType::Fert:
            return new FertPage(event_system_, coefficient_service_);

        /// @TODO: Implement other pages once created
        case Backend::PageType::Podroznica:
        case Backend::PageType::Stup:
            return new DummyPage();

        default:
            return nullptr;
    }
}
