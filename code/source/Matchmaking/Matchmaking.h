#pragma once

#include "MatchmakingDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Matchmaking
{

class MatchmakingAPI
{
public:
    MatchmakingAPI() = delete;
    MatchmakingAPI(const MatchmakingAPI& source) = delete;
    MatchmakingAPI& operator=(const MatchmakingAPI& source) = delete;
    ~MatchmakingAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<GetMatchmakerGameInfoResult> AdminGetMatchmakerGameInfo(SharedPtr<GlobalState const> state, const GetMatchmakerGameInfoRequest& request, const TaskQueue& queue);
    static AsyncOp<GetMatchmakerGameModesResult> AdminGetMatchmakerGameModes(SharedPtr<GlobalState const> state, const GetMatchmakerGameModesRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminModifyMatchmakerGameModes(SharedPtr<GlobalState const> state, const ModifyMatchmakerGameModesRequest& request, const TaskQueue& queue);
    static AsyncOp<CurrentGamesResult> ClientGetCurrentGames(SharedPtr<TitlePlayer> entity, const CurrentGamesRequest& request, const TaskQueue& queue);
    static AsyncOp<GameServerRegionsResult> ClientGetGameServerRegions(SharedPtr<TitlePlayer> entity, const GameServerRegionsRequest& request, const TaskQueue& queue);
    static AsyncOp<MatchmakeResult> ClientMatchmake(SharedPtr<TitlePlayer> entity, const MatchmakeRequest& request, const TaskQueue& queue);
    static AsyncOp<StartGameResult> ClientStartGame(SharedPtr<TitlePlayer> entity, const ClientStartGameRequest& request, const TaskQueue& queue);
    static AsyncOp<AuthUserResponse> AuthUser(SharedPtr<GlobalState const> state, const AuthUserRequest& request, const TaskQueue& queue);
    static AsyncOp<void> PlayerJoined(SharedPtr<GlobalState const> state, const PlayerJoinedRequest& request, const TaskQueue& queue);
    static AsyncOp<void> PlayerLeft(SharedPtr<GlobalState const> state, const PlayerLeftRequest& request, const TaskQueue& queue);
    static AsyncOp<StartGameResponse> StartGame(SharedPtr<GlobalState const> state, const MatchmakerStartGameRequest& request, const TaskQueue& queue);
    static AsyncOp<UserInfoResponse> UserInfo(SharedPtr<GlobalState const> state, const UserInfoRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerDeregisterGame(SharedPtr<GlobalState const> state, const DeregisterGameRequest& request, const TaskQueue& queue);
    static AsyncOp<NotifyMatchmakerPlayerLeftResult> ServerNotifyMatchmakerPlayerLeft(SharedPtr<GlobalState const> state, const NotifyMatchmakerPlayerLeftRequest& request, const TaskQueue& queue);
    static AsyncOp<RedeemMatchmakerTicketResult> ServerRedeemMatchmakerTicket(SharedPtr<GlobalState const> state, const RedeemMatchmakerTicketRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerRefreshGameServerInstanceHeartbeat(SharedPtr<GlobalState const> state, const RefreshGameServerInstanceHeartbeatRequest& request, const TaskQueue& queue);
    static AsyncOp<RegisterGameResponse> ServerRegisterGame(SharedPtr<GlobalState const> state, const RegisterGameRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerSetGameServerInstanceData(SharedPtr<GlobalState const> state, const SetGameServerInstanceDataRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerSetGameServerInstanceState(SharedPtr<GlobalState const> state, const SetGameServerInstanceStateRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerSetGameServerInstanceTags(SharedPtr<GlobalState const> state, const SetGameServerInstanceTagsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> CancelAllMatchmakingTicketsForPlayer(SharedPtr<Entity> entity, const CancelAllMatchmakingTicketsForPlayerRequest& request, const TaskQueue& queue);
    static AsyncOp<void> CancelAllServerBackfillTicketsForPlayer(SharedPtr<Entity> entity, const CancelAllServerBackfillTicketsForPlayerRequest& request, const TaskQueue& queue);
    static AsyncOp<void> CancelMatchmakingTicket(SharedPtr<Entity> entity, const CancelMatchmakingTicketRequest& request, const TaskQueue& queue);
    static AsyncOp<void> CancelServerBackfillTicket(SharedPtr<Entity> entity, const CancelServerBackfillTicketRequest& request, const TaskQueue& queue);
    static AsyncOp<CreateMatchmakingTicketResult> CreateMatchmakingTicket(SharedPtr<Entity> entity, const CreateMatchmakingTicketRequest& request, const TaskQueue& queue);
    static AsyncOp<CreateServerBackfillTicketResult> CreateServerBackfillTicket(SharedPtr<Entity> entity, const CreateServerBackfillTicketRequest& request, const TaskQueue& queue);
    static AsyncOp<CreateMatchmakingTicketResult> CreateServerMatchmakingTicket(SharedPtr<Entity> entity, const CreateServerMatchmakingTicketRequest& request, const TaskQueue& queue);
    static AsyncOp<GetMatchResult> GetMatch(SharedPtr<Entity> entity, const GetMatchRequest& request, const TaskQueue& queue);
    static AsyncOp<GetMatchmakingTicketResult> GetMatchmakingTicket(SharedPtr<Entity> entity, const GetMatchmakingTicketRequest& request, const TaskQueue& queue);
    static AsyncOp<GetQueueStatisticsResult> GetQueueStatistics(SharedPtr<Entity> entity, const GetQueueStatisticsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetServerBackfillTicketResult> GetServerBackfillTicket(SharedPtr<Entity> entity, const GetServerBackfillTicketRequest& request, const TaskQueue& queue);
    static AsyncOp<void> JoinMatchmakingTicket(SharedPtr<Entity> entity, const JoinMatchmakingTicketRequest& request, const TaskQueue& queue);
    static AsyncOp<ListMatchmakingTicketsForPlayerResult> ListMatchmakingTicketsForPlayer(SharedPtr<Entity> entity, const ListMatchmakingTicketsForPlayerRequest& request, const TaskQueue& queue);
    static AsyncOp<ListServerBackfillTicketsForPlayerResult> ListServerBackfillTicketsForPlayer(SharedPtr<Entity> entity, const ListServerBackfillTicketsForPlayerRequest& request, const TaskQueue& queue);
};

} // namespace Matchmaking
} // namespace PlayFab
