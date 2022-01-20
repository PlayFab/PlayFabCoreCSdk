#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct RefundPurchaseResponseHolder : public XAsyncResult, public std::enable_shared_from_this<RefundPurchaseResponseHolder>
{
    RefundPurchaseResponseHolder() = default;
    RefundPurchaseResponseHolder(const RefundPurchaseResponseHolder&) = delete;
    RefundPurchaseResponseHolder(RefundPurchaseResponseHolder&&) = default;
    RefundPurchaseResponseHolder& operator=(const RefundPurchaseResponseHolder&) = delete;
    RefundPurchaseResponseHolder& operator=(RefundPurchaseResponseHolder&&) = default;
    ~RefundPurchaseResponseHolder() = default;

    PFEconomyRefundPurchaseResponse* result{ nullptr };
};

struct ResolvePurchaseDisputeResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ResolvePurchaseDisputeResponseHolder>
{
    ResolvePurchaseDisputeResponseHolder() = default;
    ResolvePurchaseDisputeResponseHolder(const ResolvePurchaseDisputeResponseHolder&) = delete;
    ResolvePurchaseDisputeResponseHolder(ResolvePurchaseDisputeResponseHolder&&) = default;
    ResolvePurchaseDisputeResponseHolder& operator=(const ResolvePurchaseDisputeResponseHolder&) = delete;
    ResolvePurchaseDisputeResponseHolder& operator=(ResolvePurchaseDisputeResponseHolder&&) = default;
    ~ResolvePurchaseDisputeResponseHolder() = default;

    PFEconomyResolvePurchaseDisputeResponse* result{ nullptr };
};


}
