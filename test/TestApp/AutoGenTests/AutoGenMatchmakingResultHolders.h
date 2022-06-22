#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


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
