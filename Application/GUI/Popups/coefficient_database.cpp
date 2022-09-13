#include "Application/GUI/Popups/coefficient_database.h"

#include <imgui.h>
#include <spdlog/spdlog.h>

#include "Application/Backend/coefficient_parser.h"
#include "Application/GUI/Core/id.h"

namespace
{
ImGuiWindowFlags window_flags{ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
                              ImGuiWindowFlags_Modal};

ImGuiTableFlags table_flags{ImGuiTableFlags_Borders | ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_RowBg |
                            ImGuiTableFlags_NoHostExtendX};

std::string table_id{Id::GenerateId()};
}  // namespace

namespace GUI
{

CoefficientDatabase::CoefficientDatabase(EventSystem& event_system, Backend::CoefficientService& coefficient_service)
    : event_system_(event_system),
      coefficient_service_(coefficient_service),
      size_(400.0f, 400.0f),
      coefficient_group_combo_box_(event_system_),
      save_button_(Button(event_system_)),
      close_button_(Button(event_system_)),
      add_button_(Button(event_system_))
{
    save_button_.SetText("Spremi");
    save_button_.HorizontalAlignment(ButtonHorizontalAlignment::Left, size_);
    save_button_.VerticalAlignment(ButtonVerticalAlignment::Down, size_);

    close_button_.SetText("Zatvori");
    close_button_.HorizontalAlignment(ButtonHorizontalAlignment::Right, size_);
    close_button_.VerticalAlignment(ButtonVerticalAlignment::Down, size_);

    add_button_.SetText("+");
    add_button_.SetSize({20.0f, 25.0f});

    previously_selected_coefficient_group_ = coefficient_service_.GetCoefficientsDatabase()->begin()->first;
    selected_database_ = &coefficient_service_.GetCoefficientsDatabase()->begin()->second;
    row_to_remove_ = selected_database_->end();
}

void CoefficientDatabase::Show()
{
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(size_);

    if (ImGui::Begin("Baza koeficijenata", NULL, window_flags))
    {
        coefficient_group_combo_box_.Show(*coefficient_service_.GetCoefficientsDatabase(), selected_coefficient_group_);

        ImGui::SameLine(0.0f, 10.0f);
        if (add_button_.Show())
        {
            selected_database_->emplace(std::make_pair(new char[100](), 0.0));
        }

        selected_database_ = &(*coefficient_service_.GetCoefficientsDatabase())[selected_coefficient_group_];

        // In order to properly delete database entries, change also the database map iterator - otherwise it crashes.
        if (selected_coefficient_group_ != previously_selected_coefficient_group_)
        {
            spdlog::debug("Changing currently selected coefficient group");
            row_to_remove_ = selected_database_->end();
            previously_selected_coefficient_group_ = selected_coefficient_group_;
        }

        if (row_to_remove_ != selected_database_->end())
        {
            spdlog::info("Removing coefficient database entry on position {}", row_to_remove_->first);
            selected_database_->erase(row_to_remove_);
            row_to_remove_ = selected_database_->end();
        }

        if (ImGui::BeginTable(table_id.c_str(), 3, table_flags))
        {
            ImGui::TableSetupColumn("Parametar",ImGuiTableColumnFlags_WidthStretch);
            ImGui::TableSetupColumn("Vrijednost", ImGuiTableColumnFlags_WidthFixed);
            ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed);
            ImGui::TableHeadersRow();

            std::size_t component_id{0};

            for (auto it = selected_database_->begin(); it != selected_database_->end(); ++it)
            {
                ImGui::TableNextRow();

                ImGui::TableSetColumnIndex(0);
                ImGui::PushStyleColor(ImGuiCol_FrameBg, 0);
                ImGui::SetNextItemWidth(-FLT_MIN);
                std::string input_text_label_id{fmt::format("##Text{}", component_id)};
                ImGui::InputText(input_text_label_id.c_str(), it->first, 100);

                ImGui::TableSetColumnIndex(1);
                std::string input_number_label_id{fmt::format("##Label{}", component_id)};
                ImGui::InputScalar(input_number_label_id.c_str(), ImGuiDataType_Float, &it->second);
                ImGui::PopStyleColor();

                ImGui::TableSetColumnIndex(2);
                std::string delete_label_id{fmt::format("X##{}", component_id)};
                if (ImGui::Button(delete_label_id.c_str(), {20.0f, 0.0f}))
                {
                    row_to_remove_ = it;
                };

                ++component_id;
            }

            ImGui::EndTable();
        }

        if (save_button_.Show())
        {
            coefficient_service_.SaveToJson();
        }

        if (close_button_.Show())
        {
            event_system_.Set(Events::None);
        }

        ImGui::End();
    }
}

}  // namespace GUI