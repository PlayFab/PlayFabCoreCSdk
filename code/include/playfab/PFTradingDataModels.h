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
/// TradeStatus enum.
/// </summary>
enum class PFTradingTradeStatus : uint32_t
{
    Invalid,
    Opening,
    Open,
    Accepting,
    Accepted,
    Filled,
    Cancelled
};

/// <summary>
/// PFTradingAcceptTradeRequest data model.
/// </summary>
typedef struct PFTradingAcceptTradeRequest
{
    /// <summary>
    /// (Optional) Items from the accepting player's inventory in exchange for the offered items in the
    /// trade. In the case of a gift, this will be null.
    /// </summary>
    _Maybenull_ _Field_size_(acceptedInventoryInstanceIdsCount) const char* const* acceptedInventoryInstanceIds;

    /// <summary>
    /// Count of acceptedInventoryInstanceIds
    /// </summary>
    uint32_t acceptedInventoryInstanceIdsCount;

    /// <summary>
    /// Player who opened the trade.
    /// </summary>
    _Null_terminated_ const char* offeringPlayerId;

    /// <summary>
    /// Trade identifier.
    /// </summary>
    _Null_terminated_ const char* tradeId;

} PFTradingAcceptTradeRequest;

/// <summary>
/// PFTradingTradeInfo data model.
/// </summary>
typedef struct PFTradingTradeInfo
{
    /// <summary>
    /// (Optional) Item instances from the accepting player that are used to fulfill the trade. If null,
    /// no one has accepted the trade.
    /// </summary>
    _Maybenull_ _Field_size_(acceptedInventoryInstanceIdsCount) const char* const* acceptedInventoryInstanceIds;

    /// <summary>
    /// Count of acceptedInventoryInstanceIds
    /// </summary>
    uint32_t acceptedInventoryInstanceIdsCount;

    /// <summary>
    /// (Optional) The PlayFab ID of the player who accepted the trade. If null, no one has accepted
    /// the trade.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* acceptedPlayerId;

    /// <summary>
    /// (Optional) An optional list of players allowed to complete this trade. If null, anybody can complete
    /// the trade.
    /// </summary>
    _Maybenull_ _Field_size_(allowedPlayerIdsCount) const char* const* allowedPlayerIds;

    /// <summary>
    /// Count of allowedPlayerIds
    /// </summary>
    uint32_t allowedPlayerIdsCount;

    /// <summary>
    /// (Optional) If set, The UTC time when this trade was canceled.
    /// </summary>
    _Maybenull_ time_t const* cancelledAt;

    /// <summary>
    /// (Optional) If set, The UTC time when this trade was fulfilled.
    /// </summary>
    _Maybenull_ time_t const* filledAt;

    /// <summary>
    /// (Optional) If set, The UTC time when this trade was made invalid.
    /// </summary>
    _Maybenull_ time_t const* invalidatedAt;

    /// <summary>
    /// (Optional) The catalogItem Ids of the item instances being offered.
    /// </summary>
    _Maybenull_ _Field_size_(offeredCatalogItemIdsCount) const char* const* offeredCatalogItemIds;

    /// <summary>
    /// Count of offeredCatalogItemIds
    /// </summary>
    uint32_t offeredCatalogItemIdsCount;

    /// <summary>
    /// (Optional) The itemInstance Ids that are being offered.
    /// </summary>
    _Maybenull_ _Field_size_(offeredInventoryInstanceIdsCount) const char* const* offeredInventoryInstanceIds;

    /// <summary>
    /// Count of offeredInventoryInstanceIds
    /// </summary>
    uint32_t offeredInventoryInstanceIdsCount;

    /// <summary>
    /// (Optional) The PlayFabId for the offering player.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* offeringPlayerId;

    /// <summary>
    /// (Optional) The UTC time when this trade was created.
    /// </summary>
    _Maybenull_ time_t const* openedAt;

    /// <summary>
    /// (Optional) The catalogItem Ids requested in exchange.
    /// </summary>
    _Maybenull_ _Field_size_(requestedCatalogItemIdsCount) const char* const* requestedCatalogItemIds;

    /// <summary>
    /// Count of requestedCatalogItemIds
    /// </summary>
    uint32_t requestedCatalogItemIdsCount;

    /// <summary>
    /// (Optional) Describes the current state of this trade.
    /// </summary>
    _Maybenull_ PFTradingTradeStatus const* status;

    /// <summary>
    /// (Optional) The identifier for this trade.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* tradeId;

} PFTradingTradeInfo;

/// <summary>
/// PFTradingAcceptTradeResponse data model.
/// </summary>
typedef struct PFTradingAcceptTradeResponse
{
    /// <summary>
    /// (Optional) Details about trade which was just accepted.
    /// </summary>
    _Maybenull_ PFTradingTradeInfo const* trade;

} PFTradingAcceptTradeResponse;

/// <summary>
/// PFTradingCancelTradeRequest data model.
/// </summary>
typedef struct PFTradingCancelTradeRequest
{
    /// <summary>
    /// Trade identifier.
    /// </summary>
    _Null_terminated_ const char* tradeId;

} PFTradingCancelTradeRequest;

/// <summary>
/// PFTradingCancelTradeResponse data model.
/// </summary>
typedef struct PFTradingCancelTradeResponse
{
    /// <summary>
    /// (Optional) Details about trade which was just canceled.
    /// </summary>
    _Maybenull_ PFTradingTradeInfo const* trade;

} PFTradingCancelTradeResponse;

/// <summary>
/// PFTradingGetPlayerTradesRequest data model.
/// </summary>
typedef struct PFTradingGetPlayerTradesRequest
{
    /// <summary>
    /// (Optional) Returns only trades with the given status. If null, returns all trades.
    /// </summary>
    _Maybenull_ PFTradingTradeStatus const* statusFilter;

} PFTradingGetPlayerTradesRequest;

/// <summary>
/// PFTradingGetPlayerTradesResponse data model.
/// </summary>
typedef struct PFTradingGetPlayerTradesResponse
{
    /// <summary>
    /// (Optional) History of trades which this player has accepted.
    /// </summary>
    _Maybenull_ _Field_size_(acceptedTradesCount) PFTradingTradeInfo const* const* acceptedTrades;

    /// <summary>
    /// Count of acceptedTrades
    /// </summary>
    uint32_t acceptedTradesCount;

    /// <summary>
    /// (Optional) The trades for this player which are currently available to be accepted.
    /// </summary>
    _Maybenull_ _Field_size_(openedTradesCount) PFTradingTradeInfo const* const* openedTrades;

    /// <summary>
    /// Count of openedTrades
    /// </summary>
    uint32_t openedTradesCount;

} PFTradingGetPlayerTradesResponse;

/// <summary>
/// PFTradingGetTradeStatusRequest data model.
/// </summary>
typedef struct PFTradingGetTradeStatusRequest
{
    /// <summary>
    /// Player who opened trade.
    /// </summary>
    _Null_terminated_ const char* offeringPlayerId;

    /// <summary>
    /// Trade identifier as returned by OpenTradeOffer.
    /// </summary>
    _Null_terminated_ const char* tradeId;

} PFTradingGetTradeStatusRequest;

/// <summary>
/// PFTradingGetTradeStatusResponse data model.
/// </summary>
typedef struct PFTradingGetTradeStatusResponse
{
    /// <summary>
    /// (Optional) Information about the requested trade.
    /// </summary>
    _Maybenull_ PFTradingTradeInfo const* trade;

} PFTradingGetTradeStatusResponse;

/// <summary>
/// PFTradingOpenTradeRequest data model.
/// </summary>
typedef struct PFTradingOpenTradeRequest
{
    /// <summary>
    /// (Optional) Players who are allowed to accept the trade. If null, the trade may be accepted by
    /// any player. If empty, the trade may not be accepted by any player.
    /// </summary>
    _Maybenull_ _Field_size_(allowedPlayerIdsCount) const char* const* allowedPlayerIds;

    /// <summary>
    /// Count of allowedPlayerIds
    /// </summary>
    uint32_t allowedPlayerIdsCount;

    /// <summary>
    /// (Optional) Player inventory items offered for trade. If not set, the trade is effectively a gift
    /// request.
    /// </summary>
    _Maybenull_ _Field_size_(offeredInventoryInstanceIdsCount) const char* const* offeredInventoryInstanceIds;

    /// <summary>
    /// Count of offeredInventoryInstanceIds
    /// </summary>
    uint32_t offeredInventoryInstanceIdsCount;

    /// <summary>
    /// (Optional) Catalog items accepted for the trade. If not set, the trade is effectively a gift.
    /// </summary>
    _Maybenull_ _Field_size_(requestedCatalogItemIdsCount) const char* const* requestedCatalogItemIds;

    /// <summary>
    /// Count of requestedCatalogItemIds
    /// </summary>
    uint32_t requestedCatalogItemIdsCount;

} PFTradingOpenTradeRequest;

/// <summary>
/// PFTradingOpenTradeResponse data model.
/// </summary>
typedef struct PFTradingOpenTradeResponse
{
    /// <summary>
    /// (Optional) The information about the trade that was just opened.
    /// </summary>
    _Maybenull_ PFTradingTradeInfo const* trade;

} PFTradingOpenTradeResponse;

#pragma pop_macro("IN")

}
