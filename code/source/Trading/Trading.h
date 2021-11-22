#pragma once

#include "TradingDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Trading
{

class TradingAPI
{
public:
    TradingAPI() = delete;
    TradingAPI(const TradingAPI& source) = delete;
    TradingAPI& operator=(const TradingAPI& source) = delete;
    ~TradingAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<AcceptTradeResponse> ClientAcceptTrade(SharedPtr<TitlePlayer> entity, const AcceptTradeRequest& request, const TaskQueue& queue);
    static AsyncOp<CancelTradeResponse> ClientCancelTrade(SharedPtr<TitlePlayer> entity, const CancelTradeRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPlayerTradesResponse> ClientGetPlayerTrades(SharedPtr<TitlePlayer> entity, const GetPlayerTradesRequest& request, const TaskQueue& queue);
    static AsyncOp<GetTradeStatusResponse> ClientGetTradeStatus(SharedPtr<TitlePlayer> entity, const GetTradeStatusRequest& request, const TaskQueue& queue);
    static AsyncOp<OpenTradeResponse> ClientOpenTrade(SharedPtr<TitlePlayer> entity, const OpenTradeRequest& request, const TaskQueue& queue);
};

} // namespace Trading
} // namespace PlayFab
