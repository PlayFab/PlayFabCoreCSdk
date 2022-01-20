// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFSharedDataModels.h>

extern "C"
{

#pragma push_macro("IN")
#undef IN

/// <summary>
/// ResolutionOutcome enum.
/// </summary>
enum class PFEconomyResolutionOutcome : uint32_t
{
    Revoke,
    Reinstate,
    Manual
};

/// <summary>
/// PFEconomyRefundPurchaseRequest data model.
/// </summary>
typedef struct PFEconomyRefundPurchaseRequest
{
    /// <summary>
    /// Unique order ID for the purchase in question.
    /// </summary>
    _Null_terminated_ const char* orderId;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) The Reason parameter should correspond with the payment providers reason field, if
    /// they require one such as Facebook. In the case of Facebook this must match one of their refund
    /// or dispute resolution enums (See: https://developers.facebook.com/docs/payments/implementation-guide/handling-disputes-refunds).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reason;

} PFEconomyRefundPurchaseRequest;

/// <summary>
/// PFEconomyRefundPurchaseResponse data model.
/// </summary>
typedef struct PFEconomyRefundPurchaseResponse
{
    /// <summary>
    /// (Optional) The order's updated purchase status.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* purchaseStatus;

} PFEconomyRefundPurchaseResponse;

/// <summary>
/// PFEconomyResolvePurchaseDisputeRequest data model.
/// </summary>
typedef struct PFEconomyResolvePurchaseDisputeRequest
{
    /// <summary>
    /// Unique order ID for the purchase in question.
    /// </summary>
    _Null_terminated_ const char* orderId;

    /// <summary>
    /// Enum for the desired purchase result state after notifying the payment provider. Valid values
    /// are Revoke, Reinstate and Manual. Manual will cause no change to the order state.
    /// </summary>
    PFEconomyResolutionOutcome outcome;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) The Reason parameter should correspond with the payment providers reason field, if
    /// they require one such as Facebook. In the case of Facebook this must match one of their refund
    /// or dispute resolution enums (See: https://developers.facebook.com/docs/payments/implementation-guide/handling-disputes-refunds).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reason;

} PFEconomyResolvePurchaseDisputeRequest;

/// <summary>
/// PFEconomyResolvePurchaseDisputeResponse data model.
/// </summary>
typedef struct PFEconomyResolvePurchaseDisputeResponse
{
    /// <summary>
    /// (Optional) The order's updated purchase status.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* purchaseStatus;

} PFEconomyResolvePurchaseDisputeResponse;

#pragma pop_macro("IN")

}
