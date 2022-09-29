#pragma once

#include "InventoryDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Inventory
{

class InventoryAPI
{
public:
    InventoryAPI() = delete;
    InventoryAPI(const InventoryAPI& source) = delete;
    InventoryAPI& operator=(const InventoryAPI& source) = delete;
    ~InventoryAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<AddInventoryItemsResponse> AddInventoryItems(SharedPtr<Entity> entity, const AddInventoryItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> DeleteInventoryCollection(SharedPtr<Entity> entity, const DeleteInventoryCollectionRequest& request, const TaskQueue& queue);
    static AsyncOp<DeleteInventoryItemsResponse> DeleteInventoryItems(SharedPtr<Entity> entity, const DeleteInventoryItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<ExecuteInventoryOperationsResponse> ExecuteInventoryOperations(SharedPtr<Entity> entity, const ExecuteInventoryOperationsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetInventoryCollectionIdsResponse> GetInventoryCollectionIds(SharedPtr<Entity> entity, const GetInventoryCollectionIdsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetInventoryItemsResponse> GetInventoryItems(SharedPtr<Entity> entity, const GetInventoryItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetMicrosoftStoreAccessTokensResponse> GetMicrosoftStoreAccessTokens(SharedPtr<Entity> entity, const GetMicrosoftStoreAccessTokensRequest& request, const TaskQueue& queue);
    static AsyncOp<PurchaseInventoryItemsResponse> PurchaseInventoryItems(SharedPtr<Entity> entity, const PurchaseInventoryItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<RedeemAppleAppStoreInventoryItemsResponse> RedeemAppleAppStoreInventoryItems(SharedPtr<Entity> entity, const RedeemAppleAppStoreInventoryItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<RedeemGooglePlayInventoryItemsResponse> RedeemGooglePlayInventoryItems(SharedPtr<Entity> entity, const RedeemGooglePlayInventoryItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<RedeemMicrosoftStoreInventoryItemsResponse> RedeemMicrosoftStoreInventoryItems(SharedPtr<Entity> entity, const RedeemMicrosoftStoreInventoryItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<RedeemNintendoEShopInventoryItemsResponse> RedeemNintendoEShopInventoryItems(SharedPtr<Entity> entity, const RedeemNintendoEShopInventoryItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<RedeemPlayStationStoreInventoryItemsResponse> RedeemPlayStationStoreInventoryItems(SharedPtr<Entity> entity, const RedeemPlayStationStoreInventoryItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<RedeemSteamInventoryItemsResponse> RedeemSteamInventoryItems(SharedPtr<Entity> entity, const RedeemSteamInventoryItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<SubtractInventoryItemsResponse> SubtractInventoryItems(SharedPtr<Entity> entity, const SubtractInventoryItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<TransferInventoryItemsResponse> TransferInventoryItems(SharedPtr<Entity> entity, const TransferInventoryItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateInventoryItemsResponse> UpdateInventoryItems(SharedPtr<Entity> entity, const UpdateInventoryItemsRequest& request, const TaskQueue& queue);
};

} // namespace Inventory
} // namespace PlayFab
