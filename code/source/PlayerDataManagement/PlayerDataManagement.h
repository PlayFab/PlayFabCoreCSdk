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
    static AsyncOp<GetDataReportResult> AdminGetDataReport(SharedPtr<GlobalState const> state, const GetDataReportRequest& request, const TaskQueue& queue);
    static AsyncOp<AdminGetUserDataResult> AdminGetUserData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<AdminGetUserDataResult> AdminGetUserInternalData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<AdminGetUserDataResult> AdminGetUserPublisherData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<AdminGetUserDataResult> AdminGetUserPublisherInternalData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<AdminGetUserDataResult> AdminGetUserPublisherReadOnlyData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<AdminGetUserDataResult> AdminGetUserReadOnlyData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> AdminUpdateUserData(SharedPtr<GlobalState const> state, const AdminUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> AdminUpdateUserInternalData(SharedPtr<GlobalState const> state, const UpdateUserInternalDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> AdminUpdateUserPublisherData(SharedPtr<GlobalState const> state, const AdminUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> AdminUpdateUserPublisherInternalData(SharedPtr<GlobalState const> state, const UpdateUserInternalDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> AdminUpdateUserPublisherReadOnlyData(SharedPtr<GlobalState const> state, const AdminUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> AdminUpdateUserReadOnlyData(SharedPtr<GlobalState const> state, const AdminUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ClientGetUserDataResult> ClientGetUserData(SharedPtr<TitlePlayer> entity, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ClientGetUserDataResult> ClientGetUserPublisherData(SharedPtr<TitlePlayer> entity, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ClientGetUserDataResult> ClientGetUserPublisherReadOnlyData(SharedPtr<TitlePlayer> entity, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ClientGetUserDataResult> ClientGetUserReadOnlyData(SharedPtr<TitlePlayer> entity, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> ClientUpdateUserData(SharedPtr<TitlePlayer> entity, const ClientUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> ClientUpdateUserPublisherData(SharedPtr<TitlePlayer> entity, const ClientUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetUserDataResult> ServerGetUserData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetUserDataResult> ServerGetUserInternalData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetUserDataResult> ServerGetUserPublisherData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetUserDataResult> ServerGetUserPublisherInternalData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetUserDataResult> ServerGetUserPublisherReadOnlyData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetUserDataResult> ServerGetUserReadOnlyData(SharedPtr<GlobalState const> state, const GetUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> ServerUpdateUserData(SharedPtr<GlobalState const> state, const ServerUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> ServerUpdateUserInternalData(SharedPtr<GlobalState const> state, const UpdateUserInternalDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> ServerUpdateUserPublisherData(SharedPtr<GlobalState const> state, const ServerUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> ServerUpdateUserPublisherInternalData(SharedPtr<GlobalState const> state, const UpdateUserInternalDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> ServerUpdateUserPublisherReadOnlyData(SharedPtr<GlobalState const> state, const ServerUpdateUserDataRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateUserDataResult> ServerUpdateUserReadOnlyData(SharedPtr<GlobalState const> state, const ServerUpdateUserDataRequest& request, const TaskQueue& queue);
};

} // namespace PlayerDataManagement
} // namespace PlayFab
