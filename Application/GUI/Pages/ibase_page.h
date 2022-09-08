#ifndef STATICCALCULATION_IBASE_PAGE_H
#define STATICCALCULATION_IBASE_PAGE_H

namespace GUI
{

class IBasePage
{
  public:
    virtual void Show() = 0;

    virtual ~IBasePage() = default;
};

}  // namespace GUI

#endif  // STATICCALCULATION_IBASE_PAGE_H
