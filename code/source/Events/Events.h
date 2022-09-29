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
    static AsyncOp<void> AdminAddPlayerTag(SharedPtr<GlobalState const> state, const AddPlayerTagRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerTagsResult> AdminGetPlayerTags(SharedPtr<GlobalState const> state, const GetPlayerTagsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminRemovePlayerTag(SharedPtr<GlobalState const> state, const RemovePlayerTagRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerTagsResult> ClientGetPlayerTags(SharedPtr<TitlePlayer> entity, const GetPlayerTagsRequest& request, const TaskQueue& queue);
    static AsyncOp<WriteEventResponse> ClientWriteCharacterEvent(SharedPtr<TitlePlayer> entity, const WriteClientCharacterEventRequest& request, const TaskQueue& queue);
    static AsyncOp<WriteEventResponse> ClientWritePlayerEvent(SharedPtr<TitlePlayer> entity, const WriteClientPlayerEventRequest& request, const TaskQueue& queue);
    static AsyncOp<WriteEventResponse> ClientWriteTitleEvent(SharedPtr<TitlePlayer> entity, const WriteTitleEventRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerAddPlayerTag(SharedPtr<GlobalState const> state, const AddPlayerTagRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerTagsResult> ServerGetPlayerTags(SharedPtr<GlobalState const> state, const GetPlayerTagsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerRemovePlayerTag(SharedPtr<GlobalState const> state, const RemovePlayerTagRequest& request, const TaskQueue& queue);
    static AsyncOp<WriteEventResponse> ServerWriteCharacterEvent(SharedPtr<GlobalState const> state, const WriteServerCharacterEventRequest& request, const TaskQueue& queue);
    static AsyncOp<WriteEventResponse> ServerWritePlayerEvent(SharedPtr<GlobalState const> state, const WriteServerPlayerEventRequest& request, const TaskQueue& queue);
    static AsyncOp<WriteEventResponse> ServerWriteTitleEvent(SharedPtr<GlobalState const> state, const WriteTitleEventRequest& request, const TaskQueue& queue);
    static AsyncOp<WriteEventsResponse> WriteEvents(SharedPtr<Entity> entity, const WriteEventsRequest& request, const TaskQueue& queue);
    static AsyncOp<WriteEventsResponse> WriteTelemetryEvents(SharedPtr<Entity> entity, const WriteEventsRequest& request, const TaskQueue& queue);
};

} // namespace Events
} // namespace PlayFab
