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
    static AsyncOp<GetAllSegmentsResult> AdminGetAllSegments(SharedPtr<GlobalState const> state, const TaskQueue& queue);
    static AsyncOp<GetPlayerSegmentsResult> AdminGetPlayerSegments(SharedPtr<GlobalState const> state, const GetPlayersSegmentsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayersInSegmentResult> AdminGetPlayersInSegment(SharedPtr<GlobalState const> state, const GetPlayersInSegmentRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerSegmentsResult> ClientGetPlayerSegments(SharedPtr<TitlePlayer> entity, const TaskQueue& queue);
    static AsyncOp<GetAllSegmentsResult> ServerGetAllSegments(SharedPtr<GlobalState const> state, const TaskQueue& queue);
    static AsyncOp<GetPlayerSegmentsResult> ServerGetPlayerSegments(SharedPtr<GlobalState const> state, const GetPlayersSegmentsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayersInSegmentResult> ServerGetPlayersInSegment(SharedPtr<GlobalState const> state, const GetPlayersInSegmentRequest& request, const TaskQueue& queue);
};

} // namespace PlayStream
} // namespace PlayFab
