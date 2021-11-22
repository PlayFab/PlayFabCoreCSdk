#pragma once

#include "SharedGroupsDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace SharedGroups
{

class SharedGroupsAPI
{
public:
    SharedGroupsAPI() = delete;
    SharedGroupsAPI(const SharedGroupsAPI& source) = delete;
    SharedGroupsAPI& operator=(const SharedGroupsAPI& source) = delete;
    ~SharedGroupsAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<void> ClientAddSharedGroupMembers(SharedPtr<TitlePlayer> entity, const AddSharedGroupMembersRequest& request, const TaskQueue& queue);
    static AsyncOp<CreateSharedGroupResult> ClientCreateSharedGroup(SharedPtr<TitlePlayer> entity, const CreateSharedGroupRequest& request, const TaskQueue& queue);
    static AsyncOp<GetSharedGroupDataResult> ClientGetSharedGroupData(SharedPtr<TitlePlayer> entity, const GetSharedGroupDataRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientRemoveSharedGroupMembers(SharedPtr<TitlePlayer> entity, const RemoveSharedGroupMembersRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientUpdateSharedGroupData(SharedPtr<TitlePlayer> entity, const UpdateSharedGroupDataRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerAddSharedGroupMembers(SharedPtr<GlobalState const> state, const AddSharedGroupMembersRequest& request, const TaskQueue& queue);
    static AsyncOp<CreateSharedGroupResult> ServerCreateSharedGroup(SharedPtr<GlobalState const> state, const CreateSharedGroupRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerDeleteSharedGroup(SharedPtr<GlobalState const> state, const DeleteSharedGroupRequest& request, const TaskQueue& queue);
    static AsyncOp<GetSharedGroupDataResult> ServerGetSharedGroupData(SharedPtr<GlobalState const> state, const GetSharedGroupDataRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerRemoveSharedGroupMembers(SharedPtr<GlobalState const> state, const RemoveSharedGroupMembersRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerUpdateSharedGroupData(SharedPtr<GlobalState const> state, const UpdateSharedGroupDataRequest& request, const TaskQueue& queue);
};

} // namespace SharedGroups
} // namespace PlayFab
