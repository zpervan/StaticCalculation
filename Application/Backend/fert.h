#ifndef STATICCALCULATION_FERT_H
#define STATICCALCULATION_FERT_H

namespace Backend
{
template <typename T>
T calculateLoad(T value)
{
    return value;
}

template <typename T, typename... Rest>
T calculateLoad(T value, Rest... rest)
{
    return value + calculateLoad(rest...);
}
}  // namespace Backend

#endif  // STATICCALCULATION_FERT_H
