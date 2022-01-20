#pragma once

#include "LeaderboardDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Leaderboard
{

class LeaderboardAPI
{
public:
    LeaderboardAPI() = delete;
    LeaderboardAPI(const LeaderboardAPI& source) = delete;
    LeaderboardAPI& operator=(const LeaderboardAPI& source) = delete;
    ~LeaderboardAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<CreatePlayerStatisticDefinitionResult> AdminCreatePlayerStatisticDefinition(SharedPtr<GlobalState const> state, const CreatePlayerStatisticDefinitionRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerStatisticDefinitionsResult> AdminGetPlayerStatisticDefinitions(SharedPtr<GlobalState const> state, const TaskQueue& queue);
    static AsyncOp<GetPlayerStatisticVersionsResult> AdminGetPlayerStatisticVersions(SharedPtr<GlobalState const> state, const GetPlayerStatisticVersionsRequest& request, const TaskQueue& queue);
    static AsyncOp<IncrementPlayerStatisticVersionResult> AdminIncrementPlayerStatisticVersion(SharedPtr<GlobalState const> state, const IncrementPlayerStatisticVersionRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminResetUserStatistics(SharedPtr<GlobalState const> state, const ResetUserStatisticsRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdatePlayerStatisticDefinitionResult> AdminUpdatePlayerStatisticDefinition(SharedPtr<GlobalState const> state, const UpdatePlayerStatisticDefinitionRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLeaderboardResult> ClientGetFriendLeaderboard(SharedPtr<TitlePlayer> entity, const ClientGetFriendLeaderboardRequest& request, const TaskQueue& queue);
    static AsyncOp<GetFriendLeaderboardAroundPlayerResult> ClientGetFriendLeaderboardAroundPlayer(SharedPtr<TitlePlayer> entity, const GetFriendLeaderboardAroundPlayerRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLeaderboardResult> ClientGetLeaderboard(SharedPtr<TitlePlayer> entity, const GetLeaderboardRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLeaderboardAroundPlayerResult> ClientGetLeaderboardAroundPlayer(SharedPtr<TitlePlayer> entity, const GetLeaderboardAroundPlayerRequest& request, const TaskQueue& queue);
    static AsyncOp<ClientGetPlayerStatisticsResult> ClientGetPlayerStatistics(SharedPtr<TitlePlayer> entity, const ClientGetPlayerStatisticsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerStatisticVersionsResult> ClientGetPlayerStatisticVersions(SharedPtr<TitlePlayer> entity, const GetPlayerStatisticVersionsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUpdatePlayerStatistics(SharedPtr<TitlePlayer> entity, const ClientUpdatePlayerStatisticsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLeaderboardResult> ServerGetFriendLeaderboard(SharedPtr<GlobalState const> state, const ServerGetFriendLeaderboardRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLeaderboardResult> ServerGetLeaderboard(SharedPtr<GlobalState const> state, const GetLeaderboardRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLeaderboardAroundUserResult> ServerGetLeaderboardAroundUser(SharedPtr<GlobalState const> state, const GetLeaderboardAroundUserRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetPlayerStatisticsResult> ServerGetPlayerStatistics(SharedPtr<GlobalState const> state, const ServerGetPlayerStatisticsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerStatisticVersionsResult> ServerGetPlayerStatisticVersions(SharedPtr<GlobalState const> state, const GetPlayerStatisticVersionsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerUpdatePlayerStatistics(SharedPtr<GlobalState const> state, const ServerUpdatePlayerStatisticsRequest& request, const TaskQueue& queue);
};

} // namespace Leaderboard
} // namespace PlayFab
