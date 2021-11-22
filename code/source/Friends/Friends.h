#pragma once

#include "FriendsDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Friends
{

class FriendsAPI
{
public:
    FriendsAPI() = delete;
    FriendsAPI(const FriendsAPI& source) = delete;
    FriendsAPI& operator=(const FriendsAPI& source) = delete;
    ~FriendsAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<AddFriendResult> ClientAddFriend(SharedPtr<TitlePlayer> entity, const ClientAddFriendRequest& request, const TaskQueue& queue);
    static AsyncOp<GetFriendsListResult> ClientGetFriendsList(SharedPtr<TitlePlayer> entity, const ClientGetFriendsListRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientRemoveFriend(SharedPtr<TitlePlayer> entity, const ClientRemoveFriendRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientSetFriendTags(SharedPtr<TitlePlayer> entity, const ClientSetFriendTagsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerAddFriend(SharedPtr<GlobalState const> state, const ServerAddFriendRequest& request, const TaskQueue& queue);
    static AsyncOp<GetFriendsListResult> ServerGetFriendsList(SharedPtr<GlobalState const> state, const ServerGetFriendsListRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerRemoveFriend(SharedPtr<GlobalState const> state, const ServerRemoveFriendRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerSetFriendTags(SharedPtr<GlobalState const> state, const ServerSetFriendTagsRequest& request, const TaskQueue& queue);
};

} // namespace Friends
} // namespace PlayFab
