#pragma once

#include "LobbyDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Lobby
{

class LobbyAPI
{
public:
    LobbyAPI() = delete;
    LobbyAPI(const LobbyAPI& source) = delete;
    LobbyAPI& operator=(const LobbyAPI& source) = delete;
    ~LobbyAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<CreateLobbyResult> CreateLobby(SharedPtr<Entity> entity, const CreateLobbyRequest& request, const TaskQueue& queue);
    static AsyncOp<void> DeleteLobby(SharedPtr<Entity> entity, const DeleteLobbyRequest& request, const TaskQueue& queue);
    static AsyncOp<FindFriendLobbiesResult> FindFriendLobbies(SharedPtr<Entity> entity, const FindFriendLobbiesRequest& request, const TaskQueue& queue);
    static AsyncOp<FindLobbiesResult> FindLobbies(SharedPtr<Entity> entity, const FindLobbiesRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLobbyResult> GetLobby(SharedPtr<Entity> entity, const GetLobbyRequest& request, const TaskQueue& queue);
    static AsyncOp<void> InviteToLobby(SharedPtr<Entity> entity, const InviteToLobbyRequest& request, const TaskQueue& queue);
    static AsyncOp<JoinLobbyResult> JoinArrangedLobby(SharedPtr<Entity> entity, const JoinArrangedLobbyRequest& request, const TaskQueue& queue);
    static AsyncOp<JoinLobbyResult> JoinLobby(SharedPtr<Entity> entity, const JoinLobbyRequest& request, const TaskQueue& queue);
    static AsyncOp<void> LeaveLobby(SharedPtr<Entity> entity, const LeaveLobbyRequest& request, const TaskQueue& queue);
    static AsyncOp<void> RemoveMember(SharedPtr<Entity> entity, const RemoveMemberFromLobbyRequest& request, const TaskQueue& queue);
    static AsyncOp<SubscribeToLobbyResourceResult> SubscribeToLobbyResource(SharedPtr<Entity> entity, const SubscribeToLobbyResourceRequest& request, const TaskQueue& queue);
    static AsyncOp<void> UnsubscribeFromLobbyResource(SharedPtr<Entity> entity, const UnsubscribeFromLobbyResourceRequest& request, const TaskQueue& queue);
    static AsyncOp<void> UpdateLobby(SharedPtr<Entity> entity, const UpdateLobbyRequest& request, const TaskQueue& queue);
};

} // namespace Lobby
} // namespace PlayFab
