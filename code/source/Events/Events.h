#pragma once

#include "EventsDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Events
{

class EventsAPI
{
public:
    EventsAPI() = delete;
    EventsAPI(const EventsAPI& source) = delete;
    EventsAPI& operator=(const EventsAPI& source) = delete;
    ~EventsAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<WriteEventsResponse> WriteEvents(SharedPtr<TitlePlayer> entity, const WriteEventsRequest& request, RunContext rc);
};

} // namespace Events
} // namespace PlayFab
