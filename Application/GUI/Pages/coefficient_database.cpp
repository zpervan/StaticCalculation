#include "coefficient_database.h"

#include <imgui.h>
#include <spdlog/spdlog.h>

#include "Application/Backend/coefficient_parser.h"
#include "Application/GUI/Core/id.h"

namespace
{
ImGuiWindowFlags flags{ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
                       ImGuiWindowFlags_Modal};

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
      close_button_(Button(event_system_))
{
    save_button_.SetText("Spremi");
    save_button_.HorizontalAlignment(ButtonHorizontalAlignment::Left, size_);
    save_button_.VerticalAlignment(ButtonVerticalAlignment::Down, size_);

    close_button_.SetText("Zatvori");
    close_button_.HorizontalAlignment(ButtonHorizontalAlignment::Right, size_);
    close_button_.VerticalAlignment(ButtonVerticalAlignment::Down, size_);
}

void CoefficientDatabase::Show()
{
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(size_);

    if (ImGui::Begin("Baza koeficijenata", NULL, flags))
    {

        coefficient_group_combo_box_.Show(*coefficient_service_.GetCoefficientsDatabase(), selected_coefficient_group_);

        if (ImGui::BeginTable(table_id.c_str(), 3, ImGuiTableFlags_Borders))
        {
            ImGui::TableSetupColumn("Parametar");
            ImGui::TableSetupColumn("Vrijednost");
            ImGui::TableSetupColumn("", ImGuiTableFlags_NoBordersInBody);
            ImGui::TableHeadersRow();

            std::size_t component_id{0};

            auto* selected_database{&(*coefficient_service_.GetCoefficientsDatabase())[selected_coefficient_group_]};

            for (auto it = selected_database->begin(); it != selected_database->end(); ++it)
            {
                ImGui::TableNextRow();

                ImGui::TableSetColumnIndex(0);
                ImGui::Text("%s", it->first.c_str());

                ImGui::TableSetColumnIndex(1);
                ImGui::Text("%.2f", it->second);

                ImGui::TableSetColumnIndex(2);
                std::string delete_label_id{fmt::format("X##{}", component_id)};
                if (ImGui::Button(delete_label_id.c_str(), {20.0f, 0.0f}))
                {
                    /// @TODO: Implement deleting rows and reflect it in coefficient JSON file
                    // row_to_remove_ = it;
                };

                ++component_id;
            }

            ImGui::EndTable();
        }

        if (save_button_.Show())
        {
            spdlog::debug("Implement saving functionality");
        }

        if (close_button_.Show())
        {
            event_system_.Set(Events::None);
        }

        ImGui::End();
    }
}

}  // namespace GUI