#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct GetMatchmakerGameInfoResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetMatchmakerGameInfoResultHolder>
{
    GetMatchmakerGameInfoResultHolder() = default;
    GetMatchmakerGameInfoResultHolder(const GetMatchmakerGameInfoResultHolder&) = delete;
    GetMatchmakerGameInfoResultHolder(GetMatchmakerGameInfoResultHolder&&) = default;
    GetMatchmakerGameInfoResultHolder& operator=(const GetMatchmakerGameInfoResultHolder&) = delete;
    GetMatchmakerGameInfoResultHolder& operator=(GetMatchmakerGameInfoResultHolder&&) = default;
    ~GetMatchmakerGameInfoResultHolder() = default;

    PFMatchmakingGetMatchmakerGameInfoResult* result{ nullptr };
};

struct GetMatchmakerGameModesResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetMatchmakerGameModesResultHolder>
{
    GetMatchmakerGameModesResultHolder() = default;
    GetMatchmakerGameModesResultHolder(const GetMatchmakerGameModesResultHolder&) = delete;
    GetMatchmakerGameModesResultHolder(GetMatchmakerGameModesResultHolder&&) = default;
    GetMatchmakerGameModesResultHolder& operator=(const GetMatchmakerGameModesResultHolder&) = delete;
    GetMatchmakerGameModesResultHolder& operator=(GetMatchmakerGameModesResultHolder&&) = default;
    ~GetMatchmakerGameModesResultHolder() = default;

    PFMatchmakingGetMatchmakerGameModesResult* result{ nullptr };
};

struct CurrentGamesResultHolder : public XAsyncResult, public std::enable_shared_from_this<CurrentGamesResultHolder>
{
    CurrentGamesResultHolder() = default;
    CurrentGamesResultHolder(const CurrentGamesResultHolder&) = delete;
    CurrentGamesResultHolder(CurrentGamesResultHolder&&) = default;
    CurrentGamesResultHolder& operator=(const CurrentGamesResultHolder&) = delete;
    CurrentGamesResultHolder& operator=(CurrentGamesResultHolder&&) = default;
    ~CurrentGamesResultHolder() = default;

    PFMatchmakingCurrentGamesResult* result{ nullptr };
};

struct GameServerRegionsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GameServerRegionsResultHolder>
{
    GameServerRegionsResultHolder() = default;
    GameServerRegionsResultHolder(const GameServerRegionsResultHolder&) = delete;
    GameServerRegionsResultHolder(GameServerRegionsResultHolder&&) = default;
    GameServerRegionsResultHolder& operator=(const GameServerRegionsResultHolder&) = delete;
    GameServerRegionsResultHolder& operator=(GameServerRegionsResultHolder&&) = default;
    ~GameServerRegionsResultHolder() = default;

    PFMatchmakingGameServerRegionsResult* result{ nullptr };
};

struct MatchmakeResultHolder : public XAsyncResult, public std::enable_shared_from_this<MatchmakeResultHolder>
{
    MatchmakeResultHolder() = default;
    MatchmakeResultHolder(const MatchmakeResultHolder&) = delete;
    MatchmakeResultHolder(MatchmakeResultHolder&&) = default;
    MatchmakeResultHolder& operator=(const MatchmakeResultHolder&) = delete;
    MatchmakeResultHolder& operator=(MatchmakeResultHolder&&) = default;
    ~MatchmakeResultHolder() = default;

    PFMatchmakingMatchmakeResult* result{ nullptr };
};

struct StartGameResultHolder : public XAsyncResult, public std::enable_shared_from_this<StartGameResultHolder>
{
    StartGameResultHolder() = default;
    StartGameResultHolder(const StartGameResultHolder&) = delete;
    StartGameResultHolder(StartGameResultHolder&&) = default;
    StartGameResultHolder& operator=(const StartGameResultHolder&) = delete;
    StartGameResultHolder& operator=(StartGameResultHolder&&) = default;
    ~StartGameResultHolder() = default;

    PFMatchmakingStartGameResult* result{ nullptr };
};

struct AuthUserResponseHolder : public XAsyncResult, public std::enable_shared_from_this<AuthUserResponseHolder>
{
    AuthUserResponseHolder() = default;
    AuthUserResponseHolder(const AuthUserResponseHolder&) = delete;
    AuthUserResponseHolder(AuthUserResponseHolder&&) = default;
    AuthUserResponseHolder& operator=(const AuthUserResponseHolder&) = delete;
    AuthUserResponseHolder& operator=(AuthUserResponseHolder&&) = default;
    ~AuthUserResponseHolder() = default;

    PFMatchmakingAuthUserResponse* result{ nullptr };
};

struct StartGameResponseHolder : public XAsyncResult, public std::enable_shared_from_this<StartGameResponseHolder>
{
    StartGameResponseHolder() = default;
    StartGameResponseHolder(const StartGameResponseHolder&) = delete;
    StartGameResponseHolder(StartGameResponseHolder&&) = default;
    StartGameResponseHolder& operator=(const StartGameResponseHolder&) = delete;
    StartGameResponseHolder& operator=(StartGameResponseHolder&&) = default;
    ~StartGameResponseHolder() = default;

    PFMatchmakingStartGameResponse* result{ nullptr };
};

struct UserInfoResponseHolder : public XAsyncResult, public std::enable_shared_from_this<UserInfoResponseHolder>
{
    UserInfoResponseHolder() = default;
    UserInfoResponseHolder(const UserInfoResponseHolder&) = delete;
    UserInfoResponseHolder(UserInfoResponseHolder&&) = default;
    UserInfoResponseHolder& operator=(const UserInfoResponseHolder&) = delete;
    UserInfoResponseHolder& operator=(UserInfoResponseHolder&&) = default;
    ~UserInfoResponseHolder() = default;

    PFMatchmakingUserInfoResponse* result{ nullptr };
};

struct NotifyMatchmakerPlayerLeftResultHolder : public XAsyncResult, public std::enable_shared_from_this<NotifyMatchmakerPlayerLeftResultHolder>
{
    NotifyMatchmakerPlayerLeftResultHolder() = default;
    NotifyMatchmakerPlayerLeftResultHolder(const NotifyMatchmakerPlayerLeftResultHolder&) = delete;
    NotifyMatchmakerPlayerLeftResultHolder(NotifyMatchmakerPlayerLeftResultHolder&&) = default;
    NotifyMatchmakerPlayerLeftResultHolder& operator=(const NotifyMatchmakerPlayerLeftResultHolder&) = delete;
    NotifyMatchmakerPlayerLeftResultHolder& operator=(NotifyMatchmakerPlayerLeftResultHolder&&) = default;
    ~NotifyMatchmakerPlayerLeftResultHolder() = default;

    PFMatchmakingNotifyMatchmakerPlayerLeftResult* result{ nullptr };
};

struct RedeemMatchmakerTicketResultHolder : public XAsyncResult, public std::enable_shared_from_this<RedeemMatchmakerTicketResultHolder>
{
    RedeemMatchmakerTicketResultHolder() = default;
    RedeemMatchmakerTicketResultHolder(const RedeemMatchmakerTicketResultHolder&) = delete;
    RedeemMatchmakerTicketResultHolder(RedeemMatchmakerTicketResultHolder&&) = default;
    RedeemMatchmakerTicketResultHolder& operator=(const RedeemMatchmakerTicketResultHolder&) = delete;
    RedeemMatchmakerTicketResultHolder& operator=(RedeemMatchmakerTicketResultHolder&&) = default;
    ~RedeemMatchmakerTicketResultHolder() = default;

    PFMatchmakingRedeemMatchmakerTicketResult* result{ nullptr };
};

struct RegisterGameResponseHolder : public XAsyncResult, public std::enable_shared_from_this<RegisterGameResponseHolder>
{
    RegisterGameResponseHolder() = default;
    RegisterGameResponseHolder(const RegisterGameResponseHolder&) = delete;
    RegisterGameResponseHolder(RegisterGameResponseHolder&&) = default;
    RegisterGameResponseHolder& operator=(const RegisterGameResponseHolder&) = delete;
    RegisterGameResponseHolder& operator=(RegisterGameResponseHolder&&) = default;
    ~RegisterGameResponseHolder() = default;

    PFMatchmakingRegisterGameResponse* result{ nullptr };
};

struct CreateMatchmakingTicketResultHolder : public XAsyncResult, public std::enable_shared_from_this<CreateMatchmakingTicketResultHolder>
{
    CreateMatchmakingTicketResultHolder() = default;
    CreateMatchmakingTicketResultHolder(const CreateMatchmakingTicketResultHolder&) = delete;
    CreateMatchmakingTicketResultHolder(CreateMatchmakingTicketResultHolder&&) = default;
    CreateMatchmakingTicketResultHolder& operator=(const CreateMatchmakingTicketResultHolder&) = delete;
    CreateMatchmakingTicketResultHolder& operator=(CreateMatchmakingTicketResultHolder&&) = default;
    ~CreateMatchmakingTicketResultHolder() = default;

    PFMatchmakingCreateMatchmakingTicketResult* result{ nullptr };
};

struct CreateServerBackfillTicketResultHolder : public XAsyncResult, public std::enable_shared_from_this<CreateServerBackfillTicketResultHolder>
{
    CreateServerBackfillTicketResultHolder() = default;
    CreateServerBackfillTicketResultHolder(const CreateServerBackfillTicketResultHolder&) = delete;
    CreateServerBackfillTicketResultHolder(CreateServerBackfillTicketResultHolder&&) = default;
    CreateServerBackfillTicketResultHolder& operator=(const CreateServerBackfillTicketResultHolder&) = delete;
    CreateServerBackfillTicketResultHolder& operator=(CreateServerBackfillTicketResultHolder&&) = default;
    ~CreateServerBackfillTicketResultHolder() = default;

    PFMatchmakingCreateServerBackfillTicketResult* result{ nullptr };
};

struct GetMatchResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetMatchResultHolder>
{
    GetMatchResultHolder() = default;
    GetMatchResultHolder(const GetMatchResultHolder&) = delete;
    GetMatchResultHolder(GetMatchResultHolder&&) = default;
    GetMatchResultHolder& operator=(const GetMatchResultHolder&) = delete;
    GetMatchResultHolder& operator=(GetMatchResultHolder&&) = default;
    ~GetMatchResultHolder() = default;

    PFMatchmakingGetMatchResult* result{ nullptr };
};

struct GetMatchmakingTicketResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetMatchmakingTicketResultHolder>
{
    GetMatchmakingTicketResultHolder() = default;
    GetMatchmakingTicketResultHolder(const GetMatchmakingTicketResultHolder&) = delete;
    GetMatchmakingTicketResultHolder(GetMatchmakingTicketResultHolder&&) = default;
    GetMatchmakingTicketResultHolder& operator=(const GetMatchmakingTicketResultHolder&) = delete;
    GetMatchmakingTicketResultHolder& operator=(GetMatchmakingTicketResultHolder&&) = default;
    ~GetMatchmakingTicketResultHolder() = default;

    PFMatchmakingGetMatchmakingTicketResult* result{ nullptr };
};

struct GetQueueStatisticsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetQueueStatisticsResultHolder>
{
    GetQueueStatisticsResultHolder() = default;
    GetQueueStatisticsResultHolder(const GetQueueStatisticsResultHolder&) = delete;
    GetQueueStatisticsResultHolder(GetQueueStatisticsResultHolder&&) = default;
    GetQueueStatisticsResultHolder& operator=(const GetQueueStatisticsResultHolder&) = delete;
    GetQueueStatisticsResultHolder& operator=(GetQueueStatisticsResultHolder&&) = default;
    ~GetQueueStatisticsResultHolder() = default;

    PFMatchmakingGetQueueStatisticsResult* result{ nullptr };
};

struct GetServerBackfillTicketResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetServerBackfillTicketResultHolder>
{
    GetServerBackfillTicketResultHolder() = default;
    GetServerBackfillTicketResultHolder(const GetServerBackfillTicketResultHolder&) = delete;
    GetServerBackfillTicketResultHolder(GetServerBackfillTicketResultHolder&&) = default;
    GetServerBackfillTicketResultHolder& operator=(const GetServerBackfillTicketResultHolder&) = delete;
    GetServerBackfillTicketResultHolder& operator=(GetServerBackfillTicketResultHolder&&) = default;
    ~GetServerBackfillTicketResultHolder() = default;

    PFMatchmakingGetServerBackfillTicketResult* result{ nullptr };
};

struct ListMatchmakingTicketsForPlayerResultHolder : public XAsyncResult, public std::enable_shared_from_this<ListMatchmakingTicketsForPlayerResultHolder>
{
    ListMatchmakingTicketsForPlayerResultHolder() = default;
    ListMatchmakingTicketsForPlayerResultHolder(const ListMatchmakingTicketsForPlayerResultHolder&) = delete;
    ListMatchmakingTicketsForPlayerResultHolder(ListMatchmakingTicketsForPlayerResultHolder&&) = default;
    ListMatchmakingTicketsForPlayerResultHolder& operator=(const ListMatchmakingTicketsForPlayerResultHolder&) = delete;
    ListMatchmakingTicketsForPlayerResultHolder& operator=(ListMatchmakingTicketsForPlayerResultHolder&&) = default;
    ~ListMatchmakingTicketsForPlayerResultHolder() = default;

    PFMatchmakingListMatchmakingTicketsForPlayerResult* result{ nullptr };
};

struct ListServerBackfillTicketsForPlayerResultHolder : public XAsyncResult, public std::enable_shared_from_this<ListServerBackfillTicketsForPlayerResultHolder>
{
    ListServerBackfillTicketsForPlayerResultHolder() = default;
    ListServerBackfillTicketsForPlayerResultHolder(const ListServerBackfillTicketsForPlayerResultHolder&) = delete;
    ListServerBackfillTicketsForPlayerResultHolder(ListServerBackfillTicketsForPlayerResultHolder&&) = default;
    ListServerBackfillTicketsForPlayerResultHolder& operator=(const ListServerBackfillTicketsForPlayerResultHolder&) = delete;
    ListServerBackfillTicketsForPlayerResultHolder& operator=(ListServerBackfillTicketsForPlayerResultHolder&&) = default;
    ~ListServerBackfillTicketsForPlayerResultHolder() = default;

    PFMatchmakingListServerBackfillTicketsForPlayerResult* result{ nullptr };
};


}
