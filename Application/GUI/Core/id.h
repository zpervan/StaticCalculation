#ifndef STATICCALCULATION_ID_H
#define STATICCALCULATION_ID_H

#include <spdlog/fmt/fmt.h>

#include <string>

static std::size_t id{0};

class Id
{
  public:
    static std::size_t GenerateId()
    {
        id += 1;
        return id;
    };

    static std::string GenerateIdWithLabel(const std::string& label)
    {
        std::string id_with_label;
        return fmt::format("{}##{}", label, GenerateId());
    }
};

#endif  // STATICCALCULATION_ID_H
