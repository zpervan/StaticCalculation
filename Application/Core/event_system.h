#ifndef STATICCALCULATION_EVENT_SYSTEM_H
#define STATICCALCULATION_EVENT_SYSTEM_H

#include "Application/Core/events.h"

class EventSystem
{
  public:
    Events Poll();
    void Set(Events event);

  private:
    Events event_;
};

#endif  // STATICCALCULATION_EVENT_SYSTEM_H
