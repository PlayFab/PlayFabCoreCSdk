#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFPlayerItemManagementDataModelWrappers.h>
#include "AutoGenPlayerItemManagementResultHolders.h"

namespace PlayFabUnit
{

class AutoGenPlayerItemManagementTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

    void TestPlayerItemManagementAdminAddUserVirtualCurrency(TestContext& testContext);

    void TestPlayerItemManagementAdminCheckLimitedEditionItemAvailability(TestContext& testContext);

    void TestPlayerItemManagementAdminGetUserInventory(TestContext& testContext);

    void TestPlayerItemManagementAdminGrantItemsToUsers(TestContext& testContext);

    void TestPlayerItemManagementAdminIncrementLimitedEditionItemAvailability(TestContext& testContext);

    void TestPlayerItemManagementAdminRevokeInventoryItem(TestContext& testContext);

    void TestPlayerItemManagementAdminRevokeInventoryItems(TestContext& testContext);

    void TestPlayerItemManagementAdminSubtractUserVirtualCurrency(TestContext& testContext);

    void TestPlayerItemManagementClientAddUserVirtualCurrency(TestContext& testContext);

    void TestPlayerItemManagementClientConfirmPurchase(TestContext& testContext);

    void TestPlayerItemManagementClientConsumeItem(TestContext& testContext);

    void TestPlayerItemManagementClientGetCharacterInventory(TestContext& testContext);

    void TestPlayerItemManagementClientGetPaymentToken(TestContext& testContext);

    void TestPlayerItemManagementClientGetPurchase(TestContext& testContext);

    void TestPlayerItemManagementClientGetUserInventory(TestContext& testContext);

    void TestPlayerItemManagementClientPayForPurchase(TestContext& testContext);

    void TestPlayerItemManagementClientPurchaseItem(TestContext& testContext);

    void TestPlayerItemManagementClientRedeemCoupon(TestContext& testContext);

    void TestPlayerItemManagementClientStartPurchase(TestContext& testContext);

    void TestPlayerItemManagementClientSubtractUserVirtualCurrency(TestContext& testContext);

    void TestPlayerItemManagementClientUnlockContainerInstance(TestContext& testContext);

    void TestPlayerItemManagementClientUnlockContainerItem(TestContext& testContext);

    void TestPlayerItemManagementServerAddCharacterVirtualCurrency(TestContext& testContext);

    void TestPlayerItemManagementServerAddUserVirtualCurrency(TestContext& testContext);

    void TestPlayerItemManagementServerConsumeItem(TestContext& testContext);

    void TestPlayerItemManagementServerEvaluateRandomResultTable(TestContext& testContext);

    void TestPlayerItemManagementServerGetCharacterInventory(TestContext& testContext);

    void TestPlayerItemManagementServerGetRandomResultTables(TestContext& testContext);

    void TestPlayerItemManagementServerGetUserInventory(TestContext& testContext);

    void TestPlayerItemManagementServerGrantItemsToCharacter(TestContext& testContext);

    void TestPlayerItemManagementServerGrantItemsToUser(TestContext& testContext);

    void TestPlayerItemManagementServerGrantItemsToUsers(TestContext& testContext);

    void TestPlayerItemManagementServerModifyItemUses(TestContext& testContext);

    void TestPlayerItemManagementServerMoveItemToCharacterFromCharacter(TestContext& testContext);

    void TestPlayerItemManagementServerMoveItemToCharacterFromUser(TestContext& testContext);

    void TestPlayerItemManagementServerMoveItemToUserFromCharacter(TestContext& testContext);

    void TestPlayerItemManagementServerRedeemCoupon(TestContext& testContext);

    void TestPlayerItemManagementServerReportPlayer(TestContext& testContext);

    void TestPlayerItemManagementServerRevokeInventoryItem(TestContext& testContext);

    void TestPlayerItemManagementServerRevokeInventoryItems(TestContext& testContext);

    void TestPlayerItemManagementServerSubtractCharacterVirtualCurrency(TestContext& testContext);

    void TestPlayerItemManagementServerSubtractUserVirtualCurrency(TestContext& testContext);

    void TestPlayerItemManagementServerUnlockContainerInstance(TestContext& testContext);

    void TestPlayerItemManagementServerUnlockContainerItem(TestContext& testContext);

    void TestPlayerItemManagementServerUpdateUserInventoryItemCustomData(TestContext& testContext);


protected:
    void AddTests();

    static void LogAdminAddUserVirtualCurrencyRequest(PFPlayerItemManagementAdminAddUserVirtualCurrencyRequest const* request, const char* testName);
    static void FillAdminAddUserVirtualCurrencyRequest(PlayFab::Wrappers::PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementModifyUserVirtualCurrencyResult(PFPlayerItemManagementModifyUserVirtualCurrencyResult const* result);
    static HRESULT ValidatePFPlayerItemManagementModifyUserVirtualCurrencyResult(PFPlayerItemManagementModifyUserVirtualCurrencyResult* result);

    static void LogCheckLimitedEditionItemAvailabilityRequest(PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequest const* request, const char* testName);
    static void FillCheckLimitedEditionItemAvailabilityRequest(PlayFab::Wrappers::PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult(PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult const* result);
    static HRESULT ValidatePFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult(PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult* result);

    static void LogAdminGetUserInventoryRequest(PFPlayerItemManagementAdminGetUserInventoryRequest const* request, const char* testName);
    static void FillAdminGetUserInventoryRequest(PlayFab::Wrappers::PFPlayerItemManagementAdminGetUserInventoryRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementAdminGetUserInventoryResult(PFPlayerItemManagementAdminGetUserInventoryResult const* result);
    static HRESULT ValidatePFPlayerItemManagementAdminGetUserInventoryResult(PFPlayerItemManagementAdminGetUserInventoryResult* result);

    static void LogGrantItemsToUsersRequest(PFPlayerItemManagementGrantItemsToUsersRequest const* request, const char* testName);
    static void FillGrantItemsToUsersRequest(PlayFab::Wrappers::PFPlayerItemManagementGrantItemsToUsersRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementGrantItemsToUsersResult(PFPlayerItemManagementGrantItemsToUsersResult const* result);
    static HRESULT ValidatePFPlayerItemManagementGrantItemsToUsersResult(PFPlayerItemManagementGrantItemsToUsersResult* result);

    static void LogIncrementLimitedEditionItemAvailabilityRequest(PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequest const* request, const char* testName);
    static void FillIncrementLimitedEditionItemAvailabilityRequest(PlayFab::Wrappers::PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper<>& request);

    static void LogRevokeInventoryItemRequest(PFPlayerItemManagementRevokeInventoryItemRequest const* request, const char* testName);
    static void FillRevokeInventoryItemRequest(PlayFab::Wrappers::PFPlayerItemManagementRevokeInventoryItemRequestWrapper<>& request);

    static void LogRevokeInventoryItemsRequest(PFPlayerItemManagementRevokeInventoryItemsRequest const* request, const char* testName);
    static void FillRevokeInventoryItemsRequest(PlayFab::Wrappers::PFPlayerItemManagementRevokeInventoryItemsRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementRevokeInventoryItemsResult(PFPlayerItemManagementRevokeInventoryItemsResult const* result);
    static HRESULT ValidatePFPlayerItemManagementRevokeInventoryItemsResult(PFPlayerItemManagementRevokeInventoryItemsResult* result);

    static void LogAdminSubtractUserVirtualCurrencyRequest(PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequest const* request, const char* testName);
    static void FillAdminSubtractUserVirtualCurrencyRequest(PlayFab::Wrappers::PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper<>& request);

    static void LogClientAddUserVirtualCurrencyRequest(PFPlayerItemManagementClientAddUserVirtualCurrencyRequest const* request, const char* testName);
    static void FillClientAddUserVirtualCurrencyRequest(PlayFab::Wrappers::PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper<>& request);

    static void LogConfirmPurchaseRequest(PFPlayerItemManagementConfirmPurchaseRequest const* request, const char* testName);
    static void FillConfirmPurchaseRequest(PlayFab::Wrappers::PFPlayerItemManagementConfirmPurchaseRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementConfirmPurchaseResult(PFPlayerItemManagementConfirmPurchaseResult const* result);
    static HRESULT ValidatePFPlayerItemManagementConfirmPurchaseResult(PFPlayerItemManagementConfirmPurchaseResult* result);

    static void LogClientConsumeItemRequest(PFPlayerItemManagementClientConsumeItemRequest const* request, const char* testName);
    static void FillClientConsumeItemRequest(PlayFab::Wrappers::PFPlayerItemManagementClientConsumeItemRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementConsumeItemResult(PFPlayerItemManagementConsumeItemResult const* result);
    static HRESULT ValidatePFPlayerItemManagementConsumeItemResult(PFPlayerItemManagementConsumeItemResult* result);

    static void LogClientGetCharacterInventoryRequest(PFPlayerItemManagementClientGetCharacterInventoryRequest const* request, const char* testName);
    static void FillClientGetCharacterInventoryRequest(PlayFab::Wrappers::PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementClientGetCharacterInventoryResult(PFPlayerItemManagementClientGetCharacterInventoryResult const* result);
    static HRESULT ValidatePFPlayerItemManagementClientGetCharacterInventoryResult(PFPlayerItemManagementClientGetCharacterInventoryResult* result);

    static void LogGetPaymentTokenRequest(PFPlayerItemManagementGetPaymentTokenRequest const* request, const char* testName);
    static void FillGetPaymentTokenRequest(PlayFab::Wrappers::PFPlayerItemManagementGetPaymentTokenRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementGetPaymentTokenResult(PFPlayerItemManagementGetPaymentTokenResult const* result);
    static HRESULT ValidatePFPlayerItemManagementGetPaymentTokenResult(PFPlayerItemManagementGetPaymentTokenResult* result);

    static void LogGetPurchaseRequest(PFPlayerItemManagementGetPurchaseRequest const* request, const char* testName);
    static void FillGetPurchaseRequest(PlayFab::Wrappers::PFPlayerItemManagementGetPurchaseRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementGetPurchaseResult(PFPlayerItemManagementGetPurchaseResult const* result);
    static HRESULT ValidatePFPlayerItemManagementGetPurchaseResult(PFPlayerItemManagementGetPurchaseResult* result);

    static void LogClientGetUserInventoryRequest(PFPlayerItemManagementClientGetUserInventoryRequest const* request, const char* testName);
    static void FillClientGetUserInventoryRequest(PlayFab::Wrappers::PFPlayerItemManagementClientGetUserInventoryRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementClientGetUserInventoryResult(PFPlayerItemManagementClientGetUserInventoryResult const* result);
    static HRESULT ValidatePFPlayerItemManagementClientGetUserInventoryResult(PFPlayerItemManagementClientGetUserInventoryResult* result);

    static void LogPayForPurchaseRequest(PFPlayerItemManagementPayForPurchaseRequest const* request, const char* testName);
    static void FillPayForPurchaseRequest(PlayFab::Wrappers::PFPlayerItemManagementPayForPurchaseRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementPayForPurchaseResult(PFPlayerItemManagementPayForPurchaseResult const* result);
    static HRESULT ValidatePFPlayerItemManagementPayForPurchaseResult(PFPlayerItemManagementPayForPurchaseResult* result);

    static void LogPurchaseItemRequest(PFPlayerItemManagementPurchaseItemRequest const* request, const char* testName);
    static void FillPurchaseItemRequest(PlayFab::Wrappers::PFPlayerItemManagementPurchaseItemRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementPurchaseItemResult(PFPlayerItemManagementPurchaseItemResult const* result);
    static HRESULT ValidatePFPlayerItemManagementPurchaseItemResult(PFPlayerItemManagementPurchaseItemResult* result);

    static void LogClientRedeemCouponRequest(PFPlayerItemManagementClientRedeemCouponRequest const* request, const char* testName);
    static void FillClientRedeemCouponRequest(PlayFab::Wrappers::PFPlayerItemManagementClientRedeemCouponRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementRedeemCouponResult(PFPlayerItemManagementRedeemCouponResult const* result);
    static HRESULT ValidatePFPlayerItemManagementRedeemCouponResult(PFPlayerItemManagementRedeemCouponResult* result);

    static void LogStartPurchaseRequest(PFPlayerItemManagementStartPurchaseRequest const* request, const char* testName);
    static void FillStartPurchaseRequest(PlayFab::Wrappers::PFPlayerItemManagementStartPurchaseRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementStartPurchaseResult(PFPlayerItemManagementStartPurchaseResult const* result);
    static HRESULT ValidatePFPlayerItemManagementStartPurchaseResult(PFPlayerItemManagementStartPurchaseResult* result);

    static void LogClientSubtractUserVirtualCurrencyRequest(PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequest const* request, const char* testName);
    static void FillClientSubtractUserVirtualCurrencyRequest(PlayFab::Wrappers::PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper<>& request);

    static void LogClientUnlockContainerInstanceRequest(PFPlayerItemManagementClientUnlockContainerInstanceRequest const* request, const char* testName);
    static void FillClientUnlockContainerInstanceRequest(PlayFab::Wrappers::PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementUnlockContainerItemResult(PFPlayerItemManagementUnlockContainerItemResult const* result);
    static HRESULT ValidatePFPlayerItemManagementUnlockContainerItemResult(PFPlayerItemManagementUnlockContainerItemResult* result);

    static void LogClientUnlockContainerItemRequest(PFPlayerItemManagementClientUnlockContainerItemRequest const* request, const char* testName);
    static void FillClientUnlockContainerItemRequest(PlayFab::Wrappers::PFPlayerItemManagementClientUnlockContainerItemRequestWrapper<>& request);

    static void LogAddCharacterVirtualCurrencyRequest(PFPlayerItemManagementAddCharacterVirtualCurrencyRequest const* request, const char* testName);
    static void FillAddCharacterVirtualCurrencyRequest(PlayFab::Wrappers::PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementModifyCharacterVirtualCurrencyResult(PFPlayerItemManagementModifyCharacterVirtualCurrencyResult const* result);
    static HRESULT ValidatePFPlayerItemManagementModifyCharacterVirtualCurrencyResult(PFPlayerItemManagementModifyCharacterVirtualCurrencyResult* result);

    static void LogServerAddUserVirtualCurrencyRequest(PFPlayerItemManagementServerAddUserVirtualCurrencyRequest const* request, const char* testName);
    static void FillServerAddUserVirtualCurrencyRequest(PlayFab::Wrappers::PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper<>& request);

    static void LogServerConsumeItemRequest(PFPlayerItemManagementServerConsumeItemRequest const* request, const char* testName);
    static void FillServerConsumeItemRequest(PlayFab::Wrappers::PFPlayerItemManagementServerConsumeItemRequestWrapper<>& request);

    static void LogEvaluateRandomResultTableRequest(PFPlayerItemManagementEvaluateRandomResultTableRequest const* request, const char* testName);
    static void FillEvaluateRandomResultTableRequest(PlayFab::Wrappers::PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementEvaluateRandomResultTableResult(PFPlayerItemManagementEvaluateRandomResultTableResult const* result);
    static HRESULT ValidatePFPlayerItemManagementEvaluateRandomResultTableResult(PFPlayerItemManagementEvaluateRandomResultTableResult* result);

    static void LogServerGetCharacterInventoryRequest(PFPlayerItemManagementServerGetCharacterInventoryRequest const* request, const char* testName);
    static void FillServerGetCharacterInventoryRequest(PlayFab::Wrappers::PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementServerGetCharacterInventoryResult(PFPlayerItemManagementServerGetCharacterInventoryResult const* result);
    static HRESULT ValidatePFPlayerItemManagementServerGetCharacterInventoryResult(PFPlayerItemManagementServerGetCharacterInventoryResult* result);

    static void LogGetRandomResultTablesRequest(PFPlayerItemManagementGetRandomResultTablesRequest const* request, const char* testName);
    static void FillGetRandomResultTablesRequest(PlayFab::Wrappers::PFPlayerItemManagementGetRandomResultTablesRequestWrapper<>& request);
    static HRESULT LogPFGetRandomResultTablesResult(PFGetRandomResultTablesResult const* result);
    static HRESULT ValidatePFGetRandomResultTablesResult(PFGetRandomResultTablesResult* result);

    static void LogServerGetUserInventoryRequest(PFPlayerItemManagementServerGetUserInventoryRequest const* request, const char* testName);
    static void FillServerGetUserInventoryRequest(PlayFab::Wrappers::PFPlayerItemManagementServerGetUserInventoryRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementServerGetUserInventoryResult(PFPlayerItemManagementServerGetUserInventoryResult const* result);
    static HRESULT ValidatePFPlayerItemManagementServerGetUserInventoryResult(PFPlayerItemManagementServerGetUserInventoryResult* result);

    static void LogGrantItemsToCharacterRequest(PFPlayerItemManagementGrantItemsToCharacterRequest const* request, const char* testName);
    static void FillGrantItemsToCharacterRequest(PlayFab::Wrappers::PFPlayerItemManagementGrantItemsToCharacterRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementGrantItemsToCharacterResult(PFPlayerItemManagementGrantItemsToCharacterResult const* result);
    static HRESULT ValidatePFPlayerItemManagementGrantItemsToCharacterResult(PFPlayerItemManagementGrantItemsToCharacterResult* result);

    static void LogGrantItemsToUserRequest(PFPlayerItemManagementGrantItemsToUserRequest const* request, const char* testName);
    static void FillGrantItemsToUserRequest(PlayFab::Wrappers::PFPlayerItemManagementGrantItemsToUserRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementGrantItemsToUserResult(PFPlayerItemManagementGrantItemsToUserResult const* result);
    static HRESULT ValidatePFPlayerItemManagementGrantItemsToUserResult(PFPlayerItemManagementGrantItemsToUserResult* result);


    static void LogModifyItemUsesRequest(PFPlayerItemManagementModifyItemUsesRequest const* request, const char* testName);
    static void FillModifyItemUsesRequest(PlayFab::Wrappers::PFPlayerItemManagementModifyItemUsesRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementModifyItemUsesResult(PFPlayerItemManagementModifyItemUsesResult const* result);
    static HRESULT ValidatePFPlayerItemManagementModifyItemUsesResult(PFPlayerItemManagementModifyItemUsesResult* result);

    static void LogMoveItemToCharacterFromCharacterRequest(PFPlayerItemManagementMoveItemToCharacterFromCharacterRequest const* request, const char* testName);
    static void FillMoveItemToCharacterFromCharacterRequest(PlayFab::Wrappers::PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper<>& request);

    static void LogMoveItemToCharacterFromUserRequest(PFPlayerItemManagementMoveItemToCharacterFromUserRequest const* request, const char* testName);
    static void FillMoveItemToCharacterFromUserRequest(PlayFab::Wrappers::PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper<>& request);

    static void LogMoveItemToUserFromCharacterRequest(PFPlayerItemManagementMoveItemToUserFromCharacterRequest const* request, const char* testName);
    static void FillMoveItemToUserFromCharacterRequest(PlayFab::Wrappers::PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper<>& request);

    static void LogServerRedeemCouponRequest(PFPlayerItemManagementServerRedeemCouponRequest const* request, const char* testName);
    static void FillServerRedeemCouponRequest(PlayFab::Wrappers::PFPlayerItemManagementServerRedeemCouponRequestWrapper<>& request);

    static void LogReportPlayerServerRequest(PFPlayerItemManagementReportPlayerServerRequest const* request, const char* testName);
    static void FillReportPlayerServerRequest(PlayFab::Wrappers::PFPlayerItemManagementReportPlayerServerRequestWrapper<>& request);
    static HRESULT LogPFPlayerItemManagementReportPlayerServerResult(PFPlayerItemManagementReportPlayerServerResult const* result);
    static HRESULT ValidatePFPlayerItemManagementReportPlayerServerResult(PFPlayerItemManagementReportPlayerServerResult* result);



    static void LogSubtractCharacterVirtualCurrencyRequest(PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequest const* request, const char* testName);
    static void FillSubtractCharacterVirtualCurrencyRequest(PlayFab::Wrappers::PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper<>& request);

    static void LogServerSubtractUserVirtualCurrencyRequest(PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequest const* request, const char* testName);
    static void FillServerSubtractUserVirtualCurrencyRequest(PlayFab::Wrappers::PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper<>& request);

    static void LogServerUnlockContainerInstanceRequest(PFPlayerItemManagementServerUnlockContainerInstanceRequest const* request, const char* testName);
    static void FillServerUnlockContainerInstanceRequest(PlayFab::Wrappers::PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper<>& request);

    static void LogServerUnlockContainerItemRequest(PFPlayerItemManagementServerUnlockContainerItemRequest const* request, const char* testName);
    static void FillServerUnlockContainerItemRequest(PlayFab::Wrappers::PFPlayerItemManagementServerUnlockContainerItemRequestWrapper<>& request);

    static void LogUpdateUserInventoryItemDataRequest(PFPlayerItemManagementUpdateUserInventoryItemDataRequest const* request, const char* testName);
    static void FillUpdateUserInventoryItemDataRequest(PlayFab::Wrappers::PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper<>& request);

    struct PlayerItemManagementTestData
    {
        ~PlayerItemManagementTestData() = default;

    };

    static PlayerItemManagementTestData testData;

public:
    PFStateHandle stateHandle{ nullptr };
    PFTitlePlayerHandle titlePlayerHandle{ nullptr };
    PFEntityHandle entityHandle{ nullptr };
    PFTitlePlayerHandle titlePlayerHandle2{ nullptr };
    PFEntityHandle entityHandle2{ nullptr };
    PFEntityHandle titleEntityHandle{ nullptr };

    void ClassSetUp() override;
    void ClassTearDown() override;
    void SetUp(TestContext& testContext) override;

    void Tick(TestContext&) override {}
};

}
