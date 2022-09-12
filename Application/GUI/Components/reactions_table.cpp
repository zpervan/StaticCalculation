#include "reactions_table.h"

#include <imgui.h>
#include <spdlog/spdlog.h>

#include <string>

#include "Application/GUI/Core/id.h"

namespace
{
ImGuiTableFlags table_flags{ImGuiTableFlags_Borders | ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_RowBg |
                            ImGuiTableFlags_NoHostExtendX};
}  // namespace

namespace GUI
{

ReactionsTable::ReactionsTable(EventSystem& event_system)
    : event_system_(event_system), row_to_remove_(reactions_table_parameters_.end())
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

    if (row_to_remove_ != reactions_table_parameters_.end())
    {
        spdlog::info("Removing reaction table entry on position {}", row_to_remove_->position);
        reactions_table_parameters_.erase(row_to_remove_);
        row_to_remove_ = reactions_table_parameters_.end();
    }

    if (ImGui::BeginTable("##FertMovingLoadTable", 6, table_flags))
    {
        ImGui::TableSetupColumn("POZICIJA", ImGuiTableColumnFlags_WidthFixed);
        ImGui::TableSetupColumn("SVIJETLI RASPON IZMEDU ZIDOVA Io(m)", ImGuiTableColumnFlags_WidthFixed);
        ImGui::TableSetupColumn("STATICKI RASPON I(m)", ImGuiTableColumnFlags_WidthFixed);
        ImGui::TableSetupColumn("REAKCIJA (RA, RB) - STALNO (kn)", ImGuiTableColumnFlags_WidthFixed);
        ImGui::TableSetupColumn("REAKCIJA (RA, RB) - POKRETNO (kN)", ImGuiTableColumnFlags_WidthFixed);
        ImGui::TableSetupColumn(" ", ImGuiTableColumnFlags_WidthFixed);
        ImGui::TableHeadersRow();

        /// @TODO: Move the component ID creation to a separate class
        std::size_t component_id{0};

        for (auto it = reactions_table_parameters_.begin(); it != reactions_table_parameters_.end(); ++it)
        {
            ImGui::TableNextRow();

            ImGui::TableSetColumnIndex(0);
            std::string position_label_id{fmt::format("##Position{}", component_id)};
            ImGui::SetNextItemWidth(-FLT_MIN);
            ImGui::InputScalar(position_label_id.c_str(), ImGuiDataType_U32, &(it->position));

            ImGui::TableSetColumnIndex(1);
            std::string distance_walls_label_id{fmt::format("##DistanceBetweenWalls{}", component_id)};
            ImGui::SetNextItemWidth(-FLT_MIN);
            ImGui::InputScalar(distance_walls_label_id.c_str(), ImGuiDataType_Float, &(it->distance_between_walls));

            ImGui::TableSetColumnIndex(2);
            it->static_distance = 1.05f * it->distance_between_walls;
            ImGui::Text("%.2f", it->static_distance);

            ImGui::TableSetColumnIndex(3);
            it->reaction_ra = (it->static_distance * *constant_load_sum_) / 2.0f;
            ImGui::Text("%.2f", it->reaction_ra);

            ImGui::TableSetColumnIndex(4);
            it->reaction_rb = (it->static_distance * *moving_load_sum_) / 2.0f;
            ImGui::Text("%.2f", it->reaction_rb);

            ImGui::TableSetColumnIndex(5);
            std::string delete_label_id{fmt::format("X##{}", component_id)};
            if (ImGui::Button(delete_label_id.c_str(), {20.0f, 0.0f}))
            {
                row_to_remove_ = it;
            };

            ++component_id;
        }

        component_id = 0;

        ImGui::EndTable();
    }
}

}  // namespace GUI