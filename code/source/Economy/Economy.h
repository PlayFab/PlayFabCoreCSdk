#pragma once

#include "EconomyDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Economy
{

class EconomyAPI
{
public:
    EconomyAPI() = delete;
    EconomyAPI(const EconomyAPI& source) = delete;
    EconomyAPI& operator=(const EconomyAPI& source) = delete;
    ~EconomyAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<RefundPurchaseResponse> AdminRefundPurchase(SharedPtr<GlobalState const> state, const RefundPurchaseRequest& request, const TaskQueue& queue);
    static AsyncOp<ResolvePurchaseDisputeResponse> AdminResolvePurchaseDispute(SharedPtr<GlobalState const> state, const ResolvePurchaseDisputeRequest& request, const TaskQueue& queue);
};

} // namespace Economy
} // namespace PlayFab
