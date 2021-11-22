#pragma once

#include "PlayerItemManagementDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace PlayerItemManagement
{

class PlayerItemManagementAPI
{
public:
    PlayerItemManagementAPI() = delete;
    PlayerItemManagementAPI(const PlayerItemManagementAPI& source) = delete;
    PlayerItemManagementAPI& operator=(const PlayerItemManagementAPI& source) = delete;
    ~PlayerItemManagementAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<ModifyUserVirtualCurrencyResult> AdminAddUserVirtualCurrency(SharedPtr<GlobalState const> state, const AdminAddUserVirtualCurrencyRequest& request, const TaskQueue& queue);
    static AsyncOp<CheckLimitedEditionItemAvailabilityResult> AdminCheckLimitedEditionItemAvailability(SharedPtr<GlobalState const> state, const CheckLimitedEditionItemAvailabilityRequest& request, const TaskQueue& queue);
    static AsyncOp<AdminGetUserInventoryResult> AdminGetUserInventory(SharedPtr<GlobalState const> state, const AdminGetUserInventoryRequest& request, const TaskQueue& queue);
    static AsyncOp<GrantItemsToUsersResult> AdminGrantItemsToUsers(SharedPtr<GlobalState const> state, const GrantItemsToUsersRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminIncrementLimitedEditionItemAvailability(SharedPtr<GlobalState const> state, const IncrementLimitedEditionItemAvailabilityRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminRevokeInventoryItem(SharedPtr<GlobalState const> state, const RevokeInventoryItemRequest& request, const TaskQueue& queue);
    static AsyncOp<RevokeInventoryItemsResult> AdminRevokeInventoryItems(SharedPtr<GlobalState const> state, const RevokeInventoryItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<ModifyUserVirtualCurrencyResult> AdminSubtractUserVirtualCurrency(SharedPtr<GlobalState const> state, const AdminSubtractUserVirtualCurrencyRequest& request, const TaskQueue& queue);
    static AsyncOp<ModifyUserVirtualCurrencyResult> ClientAddUserVirtualCurrency(SharedPtr<TitlePlayer> entity, const ClientAddUserVirtualCurrencyRequest& request, const TaskQueue& queue);
    static AsyncOp<ConfirmPurchaseResult> ClientConfirmPurchase(SharedPtr<TitlePlayer> entity, const ConfirmPurchaseRequest& request, const TaskQueue& queue);
    static AsyncOp<ConsumeItemResult> ClientConsumeItem(SharedPtr<TitlePlayer> entity, const ClientConsumeItemRequest& request, const TaskQueue& queue);
    static AsyncOp<ClientGetCharacterInventoryResult> ClientGetCharacterInventory(SharedPtr<TitlePlayer> entity, const ClientGetCharacterInventoryRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPaymentTokenResult> ClientGetPaymentToken(SharedPtr<TitlePlayer> entity, const GetPaymentTokenRequest& request, const TaskQueue& queue);
    static AsyncOp<GetPurchaseResult> ClientGetPurchase(SharedPtr<TitlePlayer> entity, const GetPurchaseRequest& request, const TaskQueue& queue);
    static AsyncOp<ClientGetUserInventoryResult> ClientGetUserInventory(SharedPtr<TitlePlayer> entity, const ClientGetUserInventoryRequest& request, const TaskQueue& queue);
    static AsyncOp<PayForPurchaseResult> ClientPayForPurchase(SharedPtr<TitlePlayer> entity, const PayForPurchaseRequest& request, const TaskQueue& queue);
    static AsyncOp<PurchaseItemResult> ClientPurchaseItem(SharedPtr<TitlePlayer> entity, const PurchaseItemRequest& request, const TaskQueue& queue);
    static AsyncOp<RedeemCouponResult> ClientRedeemCoupon(SharedPtr<TitlePlayer> entity, const ClientRedeemCouponRequest& request, const TaskQueue& queue);
    static AsyncOp<StartPurchaseResult> ClientStartPurchase(SharedPtr<TitlePlayer> entity, const StartPurchaseRequest& request, const TaskQueue& queue);
    static AsyncOp<ModifyUserVirtualCurrencyResult> ClientSubtractUserVirtualCurrency(SharedPtr<TitlePlayer> entity, const ClientSubtractUserVirtualCurrencyRequest& request, const TaskQueue& queue);
    static AsyncOp<UnlockContainerItemResult> ClientUnlockContainerInstance(SharedPtr<TitlePlayer> entity, const ClientUnlockContainerInstanceRequest& request, const TaskQueue& queue);
    static AsyncOp<UnlockContainerItemResult> ClientUnlockContainerItem(SharedPtr<TitlePlayer> entity, const ClientUnlockContainerItemRequest& request, const TaskQueue& queue);
    static AsyncOp<ModifyCharacterVirtualCurrencyResult> ServerAddCharacterVirtualCurrency(SharedPtr<GlobalState const> state, const AddCharacterVirtualCurrencyRequest& request, const TaskQueue& queue);
    static AsyncOp<ModifyUserVirtualCurrencyResult> ServerAddUserVirtualCurrency(SharedPtr<GlobalState const> state, const ServerAddUserVirtualCurrencyRequest& request, const TaskQueue& queue);
    static AsyncOp<ConsumeItemResult> ServerConsumeItem(SharedPtr<GlobalState const> state, const ServerConsumeItemRequest& request, const TaskQueue& queue);
    static AsyncOp<EvaluateRandomResultTableResult> ServerEvaluateRandomResultTable(SharedPtr<GlobalState const> state, const EvaluateRandomResultTableRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetCharacterInventoryResult> ServerGetCharacterInventory(SharedPtr<GlobalState const> state, const ServerGetCharacterInventoryRequest& request, const TaskQueue& queue);
    static AsyncOp<GetRandomResultTablesResult> ServerGetRandomResultTables(SharedPtr<GlobalState const> state, const GetRandomResultTablesRequest& request, const TaskQueue& queue);
    static AsyncOp<ServerGetUserInventoryResult> ServerGetUserInventory(SharedPtr<GlobalState const> state, const ServerGetUserInventoryRequest& request, const TaskQueue& queue);
    static AsyncOp<GrantItemsToCharacterResult> ServerGrantItemsToCharacter(SharedPtr<GlobalState const> state, const GrantItemsToCharacterRequest& request, const TaskQueue& queue);
    static AsyncOp<GrantItemsToUserResult> ServerGrantItemsToUser(SharedPtr<GlobalState const> state, const GrantItemsToUserRequest& request, const TaskQueue& queue);
    static AsyncOp<GrantItemsToUsersResult> ServerGrantItemsToUsers(SharedPtr<GlobalState const> state, const GrantItemsToUsersRequest& request, const TaskQueue& queue);
    static AsyncOp<ModifyItemUsesResult> ServerModifyItemUses(SharedPtr<GlobalState const> state, const ModifyItemUsesRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerMoveItemToCharacterFromCharacter(SharedPtr<GlobalState const> state, const MoveItemToCharacterFromCharacterRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerMoveItemToCharacterFromUser(SharedPtr<GlobalState const> state, const MoveItemToCharacterFromUserRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerMoveItemToUserFromCharacter(SharedPtr<GlobalState const> state, const MoveItemToUserFromCharacterRequest& request, const TaskQueue& queue);
    static AsyncOp<RedeemCouponResult> ServerRedeemCoupon(SharedPtr<GlobalState const> state, const ServerRedeemCouponRequest& request, const TaskQueue& queue);
    static AsyncOp<ReportPlayerServerResult> ServerReportPlayer(SharedPtr<GlobalState const> state, const ReportPlayerServerRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerRevokeInventoryItem(SharedPtr<GlobalState const> state, const RevokeInventoryItemRequest& request, const TaskQueue& queue);
    static AsyncOp<RevokeInventoryItemsResult> ServerRevokeInventoryItems(SharedPtr<GlobalState const> state, const RevokeInventoryItemsRequest& request, const TaskQueue& queue);
    static AsyncOp<ModifyCharacterVirtualCurrencyResult> ServerSubtractCharacterVirtualCurrency(SharedPtr<GlobalState const> state, const SubtractCharacterVirtualCurrencyRequest& request, const TaskQueue& queue);
    static AsyncOp<ModifyUserVirtualCurrencyResult> ServerSubtractUserVirtualCurrency(SharedPtr<GlobalState const> state, const ServerSubtractUserVirtualCurrencyRequest& request, const TaskQueue& queue);
    static AsyncOp<UnlockContainerItemResult> ServerUnlockContainerInstance(SharedPtr<GlobalState const> state, const ServerUnlockContainerInstanceRequest& request, const TaskQueue& queue);
    static AsyncOp<UnlockContainerItemResult> ServerUnlockContainerItem(SharedPtr<GlobalState const> state, const ServerUnlockContainerItemRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ServerUpdateUserInventoryItemCustomData(SharedPtr<GlobalState const> state, const UpdateUserInventoryItemDataRequest& request, const TaskQueue& queue);
};

} // namespace PlayerItemManagement
} // namespace PlayFab
