#include "event_system.h"

#include <spdlog/spdlog.h>

#include <map>
#include <string>

namespace
{
static std::map<Events, std::string> mapped_map_editor_events{
    {Events::None, "None"},
    {Events::Add, "Add"},
    {Events::Delete, "Delete"},
    {Events::Edit, "Edit"},
    {Events::Saving, "Saving"},
    {Events::SavingConfirmed, "SavingConfirmed"},
    {Events::Loading, "Loading"},
    {Events::LoadingConfirmed, "LoadingConfirmed"},
    {Events::Exit, "Exit"},
};
}

Events EventSystem::Poll()
{
    return event_;
}

void EventSystem::Set(Events event)
{
    spdlog::debug("Setting event of type {}", mapped_map_editor_events[event]);
    event_ = event;
}