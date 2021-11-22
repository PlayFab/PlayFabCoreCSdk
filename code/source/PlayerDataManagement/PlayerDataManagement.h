#pragma once

#include "PlayerDataManagementDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace PlayerDataManagement
{

class PlayerDataManagementAPI
{
public:
    PlayerDataManagementAPI() = delete;
    PlayerDataManagementAPI(const PlayerDataManagementAPI& source) = delete;
    PlayerDataManagementAPI& operator=(const PlayerDataManagementAPI& source) = delete;
    ~PlayerDataManagementAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<CreatePlayerStatisticDefinitionResult> AdminCreatePlayerStatisticDefinition(SharedPtr<GlobalState const> state, const CreatePlayerStatisticDefinitionRequest& request, const TaskQueue& queue);
    static AsyncOp<GetDataReportResult> AdminGetDataReport(SharedPtr<GlobalState const> state, const GetDataReportRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerStatisticDefinitionsResult> AdminGetPlayerStatisticDefinitions(SharedPtr<GlobalState const> state, const TaskQueue& queue);
    static AsyncOp<GetPlayerStatisticVersionsResult> AdminGetPlayerStatisticVersions(SharedPtr<GlobalState const> state, const GetPlayerStatisticVersionsRequest& request, const TaskQueue& queue);
    static AsyncOp<AdminGetUserDataResult> AdminGetUserData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<AdminGetUserDataResult> AdminGetUserInternalData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<AdminGetUserDataResult> AdminGetUserPublisherData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<AdminGetUserDataResult> AdminGetUserPublisherInternalData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<AdminGetUserDataResult> AdminGetUserPublisherReadOnlyData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<AdminGetUserDataResult> AdminGetUserReadOnlyData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<IncrementPlayerStatisticVersionResult> AdminIncrementPlayerStatisticVersion(SharedPtr<GlobalState const> state, const IncrementPlayerStatisticVersionRequest& request, const TaskQueue& queue);
    static AsyncOp<RefundPurchaseResponse> AdminRefundPurchase(SharedPtr<GlobalState const> state, const RefundPurchaseRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminResetUserStatistics(SharedPtr<GlobalState const> state, const ResetUserStatisticsRequest& request, const TaskQueue& queue);
    static AsyncOp<ResolvePurchaseDisputeResponse> AdminResolvePurchaseDispute(SharedPtr<GlobalState const> state, const ResolvePurchaseDisputeRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdatePlayerStatisticDefinitionResult> AdminUpdatePlayerStatisticDefinition(SharedPtr<GlobalState const> state, const UpdatePlayerStatisticDefinitionRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> AdminUpdateUserData(SharedPtr<GlobalState const> state, const AdminUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> AdminUpdateUserInternalData(SharedPtr<GlobalState const> state, const UpdateUserInternalDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> AdminUpdateUserPublisherData(SharedPtr<GlobalState const> state, const AdminUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> AdminUpdateUserPublisherInternalData(SharedPtr<GlobalState const> state, const UpdateUserInternalDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> AdminUpdateUserPublisherReadOnlyData(SharedPtr<GlobalState const> state, const AdminUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> AdminUpdateUserReadOnlyData(SharedPtr<GlobalState const> state, const AdminUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLeaderboardResult> ClientGetFriendLeaderboard(SharedPtr<TitlePlayer> entity, const ClientGetFriendLeaderboardRequest& request, const TaskQueue& queue);
    static AsyncOp<GetFriendLeaderboardAroundPlayerResult> ClientGetFriendLeaderboardAroundPlayer(SharedPtr<TitlePlayer> entity, const GetFriendLeaderboardAroundPlayerRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLeaderboardResult> ClientGetLeaderboard(SharedPtr<TitlePlayer> entity, const GetLeaderboardRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLeaderboardAroundPlayerResult> ClientGetLeaderboardAroundPlayer(SharedPtr<TitlePlayer> entity, const GetLeaderboardAroundPlayerRequest& request, const TaskQueue& queue);
    static AsyncOp<ClientGetPlayerStatisticsResult> ClientGetPlayerStatistics(SharedPtr<TitlePlayer> entity, const ClientGetPlayerStatisticsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerStatisticVersionsResult> ClientGetPlayerStatisticVersions(SharedPtr<TitlePlayer> entity, const GetPlayerStatisticVersionsRequest& request, const TaskQueue& queue);
    static AsyncOp<ClientGetUserDataResult> ClientGetUserData(SharedPtr<TitlePlayer> entity, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ClientGetUserDataResult> ClientGetUserPublisherData(SharedPtr<TitlePlayer> entity, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ClientGetUserDataResult> ClientGetUserPublisherReadOnlyData(SharedPtr<TitlePlayer> entity, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ClientGetUserDataResult> ClientGetUserReadOnlyData(SharedPtr<TitlePlayer> entity, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUpdatePlayerStatistics(SharedPtr<TitlePlayer> entity, const ClientUpdatePlayerStatisticsRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> ClientUpdateUserData(SharedPtr<TitlePlayer> entity, const ClientUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> ClientUpdateUserPublisherData(SharedPtr<TitlePlayer> entity, const ClientUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLeaderboardResult> ServerGetFriendLeaderboard(SharedPtr<GlobalState const> state, const ServerGetFriendLeaderboardRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLeaderboardResult> ServerGetLeaderboard(SharedPtr<GlobalState const> state, const GetLeaderboardRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLeaderboardAroundUserResult> ServerGetLeaderboardAroundUser(SharedPtr<GlobalState const> state, const GetLeaderboardAroundUserRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerCombinedInfoResult> ServerGetPlayerCombinedInfo(SharedPtr<GlobalState const> state, const GetPlayerCombinedInfoRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetPlayerStatisticsResult> ServerGetPlayerStatistics(SharedPtr<GlobalState const> state, const ServerGetPlayerStatisticsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerStatisticVersionsResult> ServerGetPlayerStatisticVersions(SharedPtr<GlobalState const> state, const GetPlayerStatisticVersionsRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetUserDataResult> ServerGetUserData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetUserDataResult> ServerGetUserInternalData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetUserDataResult> ServerGetUserPublisherData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetUserDataResult> ServerGetUserPublisherInternalData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetUserDataResult> ServerGetUserPublisherReadOnlyData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetUserDataResult> ServerGetUserReadOnlyData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerUpdatePlayerStatistics(SharedPtr<GlobalState const> state, const ServerUpdatePlayerStatisticsRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> ServerUpdateUserData(SharedPtr<GlobalState const> state, const ServerUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> ServerUpdateUserInternalData(SharedPtr<GlobalState const> state, const UpdateUserInternalDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> ServerUpdateUserPublisherData(SharedPtr<GlobalState const> state, const ServerUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> ServerUpdateUserPublisherInternalData(SharedPtr<GlobalState const> state, const UpdateUserInternalDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> ServerUpdateUserPublisherReadOnlyData(SharedPtr<GlobalState const> state, const ServerUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> ServerUpdateUserReadOnlyData(SharedPtr<GlobalState const> state, const ServerUpdateUserDataRequest& request, const TaskQueue& queue);
};

} // namespace PlayerDataManagement
} // namespace PlayFab
