#ifndef STATICCALCULATION_IBASE_COMPONENT_H
#define STATICCALCULATION_IBASE_COMPONENT_H

class IBaseComponent
{
  public:
    virtual void Show() = 0;

    virtual ~IBaseComponent() = default;
};

#endif  // STATICCALCULATION_IBASE_COMPONENT_H
