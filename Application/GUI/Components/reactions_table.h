#ifndef STATICCALCULATION_REACTIONS_TABLE_H
#define STATICCALCULATION_REACTIONS_TABLE_H

#include <string>
#include <list>

#include "Application/Backend/fert_backend.h"
#include "Application/Core/event_system.h"

namespace GUI
{

class ReactionsTable
{
  public:
    ReactionsTable(EventSystem& event_system);
    void SetConstantLoadSum(float& constant_load_sum);
    void SetMovingLoadSum(float& moving_load_sum);
    void Show();

  private:
    EventSystem& event_system_;
    std::list<Backend::ReactionsTableParameters> reactions_table_parameters_;
    std::list<Backend::ReactionsTableParameters>::iterator row_to_remove_{};
    std::string button_label_;

    float* constant_load_sum_;
    float* moving_load_sum_;
};

}  // namespace GUI
#endif  // STATICCALCULATION_REACTIONS_TABLE_H
