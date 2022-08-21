#include "reactions_table.h"

#include <imgui.h>
#include <spdlog/spdlog.h>

#include <string>

#include "Application/GUI/Core/id.h"

namespace
{
std::string row_to_remove{};
}  // namespace

namespace GUI
{

ReactionsTable::ReactionsTable(EventSystem& event_system) : event_system_(event_system)
{
    button_label_ = Id::GenerateIdWithLabel("Dodaj");
}

void ReactionsTable::SetConstantLoadSum(float& constant_load_sum)
{
    constant_load_sum_ = &constant_load_sum;
}

void ReactionsTable::SetMovingLoadSum(float& moving_load_sum)
{
    moving_load_sum_ = &moving_load_sum;
}

void ReactionsTable::Show()
{
    ImGui::Text("Reakcije");
    ImGui::SameLine(0.0f, 10.0f);
    if (ImGui::Button(button_label_.c_str()))
    {
        spdlog::info("Adding new row to the reaction table");
        reactions_table_parameters_.emplace_back(Backend::ReactionsTableParameters());
    }

    if (ImGui::BeginTable("##FertMovingLoadTable", 6, ImGuiTableFlags_Borders))
    {
        ImGui::TableSetupColumn("POZICIJA");
        ImGui::TableSetupColumn("SVIJETLI RASPON IZMEDU ZIDOVA Io(m)");
        ImGui::TableSetupColumn("STATICKI RASPON I(m)");
        ImGui::TableSetupColumn("REAKCIJA (RA, RB) - STALNO (kn)");
        ImGui::TableSetupColumn("REAKCIJA (RA, RB) - POKRETNO (kN)");
        ImGui::TableSetupColumn("-");
        ImGui::TableHeadersRow();

        for (std::size_t i = 0; i < reactions_table_parameters_.size(); ++i)
        {
            ImGui::TableNextRow();

            ImGui::TableSetColumnIndex(0);
            std::string position_label_id{fmt::format("##Position{}", i)};
            ImGui::InputScalar(position_label_id.c_str(), ImGuiDataType_U32, &reactions_table_parameters_[i].position);

            ImGui::TableSetColumnIndex(1);
            std::string distance_walls_label_id{fmt::format("##DistanceBetweenWalls{}", i)};
            ImGui::InputScalar(distance_walls_label_id.c_str(), ImGuiDataType_Float, &reactions_table_parameters_[i].distance_between_walls);

            ImGui::TableSetColumnIndex(2);
            reactions_table_parameters_[i].static_distance = 1.05f * reactions_table_parameters_[i].distance_between_walls;
            ImGui::Text("%.2f", reactions_table_parameters_[i].static_distance);

            ImGui::TableSetColumnIndex(3);
            reactions_table_parameters_[i].reaction_ra = (reactions_table_parameters_[i].static_distance * *constant_load_sum_) / 2.0f;
            ImGui::Text("%.2f", reactions_table_parameters_[i].reaction_ra);

            ImGui::TableSetColumnIndex(4);
            reactions_table_parameters_[i].reaction_rb = (reactions_table_parameters_[i].static_distance * *moving_load_sum_) / 2.0f;
            ImGui::Text("%.2f", reactions_table_parameters_[i].reaction_rb);

            ImGui::TableSetColumnIndex(5);
            std::string delete_label_id{fmt::format("##X{}", i)};
            if (ImGui::Button(delete_label_id.c_str(), {20.0f, 0.0f}))
            {
                /// @TODO: Implement removal logic
                // load_coefficient_to_remove = key;
            };
        }

        ImGui::EndTable();
    }
}

}  // namespace GUI