#ifndef STATICCALCULATION_ID_H
#define STATICCALCULATION_ID_H

#include <cstddef>

static std::size_t id{0};

class Id
{
  public:
    static std::size_t GenerateId()
    {
        id += 1;
        return id;
    };
};

#endif  // STATICCALCULATION_ID_H
