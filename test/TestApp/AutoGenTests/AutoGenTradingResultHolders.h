#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct AcceptTradeResponseHolder : public XAsyncResult, public std::enable_shared_from_this<AcceptTradeResponseHolder>
{
    AcceptTradeResponseHolder() = default;
    AcceptTradeResponseHolder(const AcceptTradeResponseHolder&) = delete;
    AcceptTradeResponseHolder(AcceptTradeResponseHolder&&) = default;
    AcceptTradeResponseHolder& operator=(const AcceptTradeResponseHolder&) = delete;
    AcceptTradeResponseHolder& operator=(AcceptTradeResponseHolder&&) = default;
    ~AcceptTradeResponseHolder() = default;

    PFTradingAcceptTradeResponse* result{ nullptr };
};

struct CancelTradeResponseHolder : public XAsyncResult, public std::enable_shared_from_this<CancelTradeResponseHolder>
{
    CancelTradeResponseHolder() = default;
    CancelTradeResponseHolder(const CancelTradeResponseHolder&) = delete;
    CancelTradeResponseHolder(CancelTradeResponseHolder&&) = default;
    CancelTradeResponseHolder& operator=(const CancelTradeResponseHolder&) = delete;
    CancelTradeResponseHolder& operator=(CancelTradeResponseHolder&&) = default;
    ~CancelTradeResponseHolder() = default;

    PFTradingCancelTradeResponse* result{ nullptr };
};

struct GetPlayerTradesResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayerTradesResponseHolder>
{
    GetPlayerTradesResponseHolder() = default;
    GetPlayerTradesResponseHolder(const GetPlayerTradesResponseHolder&) = delete;
    GetPlayerTradesResponseHolder(GetPlayerTradesResponseHolder&&) = default;
    GetPlayerTradesResponseHolder& operator=(const GetPlayerTradesResponseHolder&) = delete;
    GetPlayerTradesResponseHolder& operator=(GetPlayerTradesResponseHolder&&) = default;
    ~GetPlayerTradesResponseHolder() = default;

    PFTradingGetPlayerTradesResponse* result{ nullptr };
};

struct GetTradeStatusResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetTradeStatusResponseHolder>
{
    GetTradeStatusResponseHolder() = default;
    GetTradeStatusResponseHolder(const GetTradeStatusResponseHolder&) = delete;
    GetTradeStatusResponseHolder(GetTradeStatusResponseHolder&&) = default;
    GetTradeStatusResponseHolder& operator=(const GetTradeStatusResponseHolder&) = delete;
    GetTradeStatusResponseHolder& operator=(GetTradeStatusResponseHolder&&) = default;
    ~GetTradeStatusResponseHolder() = default;

    PFTradingGetTradeStatusResponse* result{ nullptr };
};

struct OpenTradeResponseHolder : public XAsyncResult, public std::enable_shared_from_this<OpenTradeResponseHolder>
{
    OpenTradeResponseHolder() = default;
    OpenTradeResponseHolder(const OpenTradeResponseHolder&) = delete;
    OpenTradeResponseHolder(OpenTradeResponseHolder&&) = default;
    OpenTradeResponseHolder& operator=(const OpenTradeResponseHolder&) = delete;
    OpenTradeResponseHolder& operator=(OpenTradeResponseHolder&&) = default;
    ~OpenTradeResponseHolder() = default;

    PFTradingOpenTradeResponse* result{ nullptr };
};


}
