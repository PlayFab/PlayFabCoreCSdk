#pragma once

#include "PlayStreamDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace PlayStream
{

class PlayStreamAPI
{
public:
    PlayStreamAPI() = delete;
    PlayStreamAPI(const PlayStreamAPI& source) = delete;
    PlayStreamAPI& operator=(const PlayStreamAPI& source) = delete;
    ~PlayStreamAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<void> AdminAddPlayerTag(SharedPtr<GlobalState const> state, const AddPlayerTagRequest& request, const TaskQueue& queue);
    static AsyncOp<GetAllSegmentsResult> AdminGetAllSegments(SharedPtr<GlobalState const> state, const TaskQueue& queue);
    static AsyncOp<GetPlayerSegmentsResult> AdminGetPlayerSegments(SharedPtr<GlobalState const> state, const GetPlayersSegmentsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayersInSegmentResult> AdminGetPlayersInSegment(SharedPtr<GlobalState const> state, const GetPlayersInSegmentRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerTagsResult> AdminGetPlayerTags(SharedPtr<GlobalState const> state, const GetPlayerTagsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminRemovePlayerTag(SharedPtr<GlobalState const> state, const RemovePlayerTagRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerSegmentsResult> ClientGetPlayerSegments(SharedPtr<TitlePlayer> entity, const TaskQueue& queue);
    static AsyncOp<GetPlayerTagsResult> ClientGetPlayerTags(SharedPtr<TitlePlayer> entity, const GetPlayerTagsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerAddPlayerTag(SharedPtr<GlobalState const> state, const AddPlayerTagRequest& request, const TaskQueue& queue);
    static AsyncOp<GetAllSegmentsResult> ServerGetAllSegments(SharedPtr<GlobalState const> state, const TaskQueue& queue);
    static AsyncOp<GetPlayerSegmentsResult> ServerGetPlayerSegments(SharedPtr<GlobalState const> state, const GetPlayersSegmentsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayersInSegmentResult> ServerGetPlayersInSegment(SharedPtr<GlobalState const> state, const GetPlayersInSegmentRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerTagsResult> ServerGetPlayerTags(SharedPtr<GlobalState const> state, const GetPlayerTagsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerRemovePlayerTag(SharedPtr<GlobalState const> state, const RemovePlayerTagRequest& request, const TaskQueue& queue);
    static AsyncOp<WriteEventsResponse> WriteEvents(SharedPtr<Entity> entity, const WriteEventsRequest& request, const TaskQueue& queue);
    static AsyncOp<WriteEventsResponse> WriteTelemetryEvents(SharedPtr<Entity> entity, const WriteEventsRequest& request, const TaskQueue& queue);
};

} // namespace PlayStream
} // namespace PlayFab
