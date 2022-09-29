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

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementAdminAddUserVirtualCurrency(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementAdminCheckLimitedEditionItemAvailability(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementAdminGetUserInventory(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementAdminGrantItemsToUsers(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementAdminIncrementLimitedEditionItemAvailability(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementAdminRevokeInventoryItem(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementAdminRevokeInventoryItems(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementAdminSubtractUserVirtualCurrency(TestContext& testContext);
#endif

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

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerAddCharacterVirtualCurrency(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerAddUserVirtualCurrency(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerConsumeItem(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerEvaluateRandomResultTable(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerGetCharacterInventory(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerGetRandomResultTables(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerGetUserInventory(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerGrantItemsToCharacter(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerGrantItemsToUser(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerGrantItemsToUsers(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerModifyItemUses(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerMoveItemToCharacterFromCharacter(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerMoveItemToCharacterFromUser(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerMoveItemToUserFromCharacter(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerRedeemCoupon(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerReportPlayer(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerRevokeInventoryItem(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerRevokeInventoryItems(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerSubtractCharacterVirtualCurrency(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerSubtractUserVirtualCurrency(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerUnlockContainerInstance(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerUnlockContainerItem(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerItemManagementServerUpdateUserInventoryItemCustomData(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogAdminAddUserVirtualCurrencyRequest(PFPlayerItemManagementAdminAddUserVirtualCurrencyRequest const* request, const char* testName);
    static HRESULT LogModifyUserVirtualCurrencyResult(PFPlayerItemManagementModifyUserVirtualCurrencyResult const* result);
    static void LogCheckLimitedEditionItemAvailabilityRequest(PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequest const* request, const char* testName);
    static HRESULT LogCheckLimitedEditionItemAvailabilityResult(PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult const* result);
    static void LogAdminGetUserInventoryRequest(PFPlayerItemManagementAdminGetUserInventoryRequest const* request, const char* testName);
    static HRESULT LogAdminGetUserInventoryResult(PFPlayerItemManagementAdminGetUserInventoryResult const* result);
    static void LogGrantItemsToUsersRequest(PFPlayerItemManagementGrantItemsToUsersRequest const* request, const char* testName);
    static HRESULT LogGrantItemsToUsersResult(PFPlayerItemManagementGrantItemsToUsersResult const* result);
    static void LogIncrementLimitedEditionItemAvailabilityRequest(PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequest const* request, const char* testName);
    static void LogRevokeInventoryItemRequest(PFPlayerItemManagementRevokeInventoryItemRequest const* request, const char* testName);
    static void LogRevokeInventoryItemsRequest(PFPlayerItemManagementRevokeInventoryItemsRequest const* request, const char* testName);
    static HRESULT LogRevokeInventoryItemsResult(PFPlayerItemManagementRevokeInventoryItemsResult const* result);
    static void LogAdminSubtractUserVirtualCurrencyRequest(PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequest const* request, const char* testName);
    static void LogClientAddUserVirtualCurrencyRequest(PFPlayerItemManagementClientAddUserVirtualCurrencyRequest const* request, const char* testName);
    static void LogConfirmPurchaseRequest(PFPlayerItemManagementConfirmPurchaseRequest const* request, const char* testName);
    static HRESULT LogConfirmPurchaseResult(PFPlayerItemManagementConfirmPurchaseResult const* result);
    static void LogClientConsumeItemRequest(PFPlayerItemManagementClientConsumeItemRequest const* request, const char* testName);
    static HRESULT LogConsumeItemResult(PFPlayerItemManagementConsumeItemResult const* result);
    static void LogClientGetCharacterInventoryRequest(PFPlayerItemManagementClientGetCharacterInventoryRequest const* request, const char* testName);
    static HRESULT LogClientGetCharacterInventoryResult(PFPlayerItemManagementClientGetCharacterInventoryResult const* result);
    static void LogGetPaymentTokenRequest(PFPlayerItemManagementGetPaymentTokenRequest const* request, const char* testName);
    static HRESULT LogGetPaymentTokenResult(PFPlayerItemManagementGetPaymentTokenResult const* result);
    static void LogGetPurchaseRequest(PFPlayerItemManagementGetPurchaseRequest const* request, const char* testName);
    static HRESULT LogGetPurchaseResult(PFPlayerItemManagementGetPurchaseResult const* result);
    static void LogClientGetUserInventoryRequest(PFPlayerItemManagementClientGetUserInventoryRequest const* request, const char* testName);
    static HRESULT LogClientGetUserInventoryResult(PFPlayerItemManagementClientGetUserInventoryResult const* result);
    static void LogPayForPurchaseRequest(PFPlayerItemManagementPayForPurchaseRequest const* request, const char* testName);
    static HRESULT LogPayForPurchaseResult(PFPlayerItemManagementPayForPurchaseResult const* result);
    static void LogPurchaseItemRequest(PFPlayerItemManagementPurchaseItemRequest const* request, const char* testName);
    static HRESULT LogPurchaseItemResult(PFPlayerItemManagementPurchaseItemResult const* result);
    static void LogClientRedeemCouponRequest(PFPlayerItemManagementClientRedeemCouponRequest const* request, const char* testName);
    static HRESULT LogRedeemCouponResult(PFPlayerItemManagementRedeemCouponResult const* result);
    static void LogStartPurchaseRequest(PFPlayerItemManagementStartPurchaseRequest const* request, const char* testName);
    static HRESULT LogStartPurchaseResult(PFPlayerItemManagementStartPurchaseResult const* result);
    static void LogClientSubtractUserVirtualCurrencyRequest(PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequest const* request, const char* testName);
    static void LogClientUnlockContainerInstanceRequest(PFPlayerItemManagementClientUnlockContainerInstanceRequest const* request, const char* testName);
    static HRESULT LogUnlockContainerItemResult(PFPlayerItemManagementUnlockContainerItemResult const* result);
    static void LogClientUnlockContainerItemRequest(PFPlayerItemManagementClientUnlockContainerItemRequest const* request, const char* testName);
    static void LogAddCharacterVirtualCurrencyRequest(PFPlayerItemManagementAddCharacterVirtualCurrencyRequest const* request, const char* testName);
    static HRESULT LogModifyCharacterVirtualCurrencyResult(PFPlayerItemManagementModifyCharacterVirtualCurrencyResult const* result);
    static void LogServerAddUserVirtualCurrencyRequest(PFPlayerItemManagementServerAddUserVirtualCurrencyRequest const* request, const char* testName);
    static void LogServerConsumeItemRequest(PFPlayerItemManagementServerConsumeItemRequest const* request, const char* testName);
    static void LogEvaluateRandomResultTableRequest(PFPlayerItemManagementEvaluateRandomResultTableRequest const* request, const char* testName);
    static HRESULT LogEvaluateRandomResultTableResult(PFPlayerItemManagementEvaluateRandomResultTableResult const* result);
    static void LogServerGetCharacterInventoryRequest(PFPlayerItemManagementServerGetCharacterInventoryRequest const* request, const char* testName);
    static HRESULT LogServerGetCharacterInventoryResult(PFPlayerItemManagementServerGetCharacterInventoryResult const* result);
    static void LogGetRandomResultTablesRequest(PFPlayerItemManagementGetRandomResultTablesRequest const* request, const char* testName);
    static HRESULT LogGetRandomResultTablesResult(PFGetRandomResultTablesResult const* result);
    static void LogServerGetUserInventoryRequest(PFPlayerItemManagementServerGetUserInventoryRequest const* request, const char* testName);
    static HRESULT LogServerGetUserInventoryResult(PFPlayerItemManagementServerGetUserInventoryResult const* result);
    static void LogGrantItemsToCharacterRequest(PFPlayerItemManagementGrantItemsToCharacterRequest const* request, const char* testName);
    static HRESULT LogGrantItemsToCharacterResult(PFPlayerItemManagementGrantItemsToCharacterResult const* result);
    static void LogGrantItemsToUserRequest(PFPlayerItemManagementGrantItemsToUserRequest const* request, const char* testName);
    static HRESULT LogGrantItemsToUserResult(PFPlayerItemManagementGrantItemsToUserResult const* result);
    static void LogModifyItemUsesRequest(PFPlayerItemManagementModifyItemUsesRequest const* request, const char* testName);
    static HRESULT LogModifyItemUsesResult(PFPlayerItemManagementModifyItemUsesResult const* result);
    static void LogMoveItemToCharacterFromCharacterRequest(PFPlayerItemManagementMoveItemToCharacterFromCharacterRequest const* request, const char* testName);
    static void LogMoveItemToCharacterFromUserRequest(PFPlayerItemManagementMoveItemToCharacterFromUserRequest const* request, const char* testName);
    static void LogMoveItemToUserFromCharacterRequest(PFPlayerItemManagementMoveItemToUserFromCharacterRequest const* request, const char* testName);
    static void LogServerRedeemCouponRequest(PFPlayerItemManagementServerRedeemCouponRequest const* request, const char* testName);
    static void LogReportPlayerServerRequest(PFPlayerItemManagementReportPlayerServerRequest const* request, const char* testName);
    static HRESULT LogReportPlayerServerResult(PFPlayerItemManagementReportPlayerServerResult const* result);
    static void LogSubtractCharacterVirtualCurrencyRequest(PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequest const* request, const char* testName);
    static void LogServerSubtractUserVirtualCurrencyRequest(PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequest const* request, const char* testName);
    static void LogServerUnlockContainerInstanceRequest(PFPlayerItemManagementServerUnlockContainerInstanceRequest const* request, const char* testName);
    static void LogServerUnlockContainerItemRequest(PFPlayerItemManagementServerUnlockContainerItemRequest const* request, const char* testName);
    static void LogUpdateUserInventoryItemDataRequest(PFPlayerItemManagementUpdateUserInventoryItemDataRequest const* request, const char* testName);

    void FillAdminAddUserVirtualCurrencyRequest(PlayFab::Wrappers::PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper<>& request);
    static HRESULT ValidateAdminAddUserVirtualCurrencyResponse(PFPlayerItemManagementModifyUserVirtualCurrencyResult* result);

    void FillAdminCheckLimitedEditionItemAvailabilityRequest(PlayFab::Wrappers::PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper<>& request);
    static HRESULT ValidateAdminCheckLimitedEditionItemAvailabilityResponse(PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult* result);

    void FillAdminGetUserInventoryRequest(PlayFab::Wrappers::PFPlayerItemManagementAdminGetUserInventoryRequestWrapper<>& request);
    static HRESULT ValidateAdminGetUserInventoryResponse(PFPlayerItemManagementAdminGetUserInventoryResult* result);

    void FillAdminGrantItemsToUsersRequest(PlayFab::Wrappers::PFPlayerItemManagementGrantItemsToUsersRequestWrapper<>& request);
    static HRESULT ValidateAdminGrantItemsToUsersResponse(PFPlayerItemManagementGrantItemsToUsersResult* result);

    void FillAdminIncrementLimitedEditionItemAvailabilityRequest(PlayFab::Wrappers::PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper<>& request);

    void FillAdminRevokeInventoryItemRequest(PlayFab::Wrappers::PFPlayerItemManagementRevokeInventoryItemRequestWrapper<>& request);

    void FillAdminRevokeInventoryItemsRequest(PlayFab::Wrappers::PFPlayerItemManagementRevokeInventoryItemsRequestWrapper<>& request);
    static HRESULT ValidateAdminRevokeInventoryItemsResponse(PFPlayerItemManagementRevokeInventoryItemsResult* result);

    void FillAdminSubtractUserVirtualCurrencyRequest(PlayFab::Wrappers::PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper<>& request);
    static HRESULT ValidateAdminSubtractUserVirtualCurrencyResponse(PFPlayerItemManagementModifyUserVirtualCurrencyResult* result);

    void FillClientAddUserVirtualCurrencyRequest(PlayFab::Wrappers::PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper<>& request);
    static HRESULT ValidateClientAddUserVirtualCurrencyResponse(PFPlayerItemManagementModifyUserVirtualCurrencyResult* result);

    void FillClientConfirmPurchaseRequest(PlayFab::Wrappers::PFPlayerItemManagementConfirmPurchaseRequestWrapper<>& request);
    static HRESULT ValidateClientConfirmPurchaseResponse(PFPlayerItemManagementConfirmPurchaseResult* result);

    void FillClientConsumeItemRequest(PlayFab::Wrappers::PFPlayerItemManagementClientConsumeItemRequestWrapper<>& request);
    static HRESULT ValidateClientConsumeItemResponse(PFPlayerItemManagementConsumeItemResult* result);

    void FillClientGetCharacterInventoryRequest(PlayFab::Wrappers::PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper<>& request);
    static HRESULT ValidateClientGetCharacterInventoryResponse(PFPlayerItemManagementClientGetCharacterInventoryResult* result);

    void FillClientGetPaymentTokenRequest(PlayFab::Wrappers::PFPlayerItemManagementGetPaymentTokenRequestWrapper<>& request);
    static HRESULT ValidateClientGetPaymentTokenResponse(PFPlayerItemManagementGetPaymentTokenResult* result);

    void FillClientGetPurchaseRequest(PlayFab::Wrappers::PFPlayerItemManagementGetPurchaseRequestWrapper<>& request);
    static HRESULT ValidateClientGetPurchaseResponse(PFPlayerItemManagementGetPurchaseResult* result);

    void FillClientGetUserInventoryRequest(PlayFab::Wrappers::PFPlayerItemManagementClientGetUserInventoryRequestWrapper<>& request);
    static HRESULT ValidateClientGetUserInventoryResponse(PFPlayerItemManagementClientGetUserInventoryResult* result);

    void FillClientPayForPurchaseRequest(PlayFab::Wrappers::PFPlayerItemManagementPayForPurchaseRequestWrapper<>& request);
    static HRESULT ValidateClientPayForPurchaseResponse(PFPlayerItemManagementPayForPurchaseResult* result);

    void FillClientPurchaseItemRequest(PlayFab::Wrappers::PFPlayerItemManagementPurchaseItemRequestWrapper<>& request);
    static HRESULT ValidateClientPurchaseItemResponse(PFPlayerItemManagementPurchaseItemResult* result);

    void FillClientRedeemCouponRequest(PlayFab::Wrappers::PFPlayerItemManagementClientRedeemCouponRequestWrapper<>& request);
    static HRESULT ValidateClientRedeemCouponResponse(PFPlayerItemManagementRedeemCouponResult* result);

    void FillClientStartPurchaseRequest(PlayFab::Wrappers::PFPlayerItemManagementStartPurchaseRequestWrapper<>& request);
    static HRESULT ValidateClientStartPurchaseResponse(PFPlayerItemManagementStartPurchaseResult* result);

    void FillClientSubtractUserVirtualCurrencyRequest(PlayFab::Wrappers::PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper<>& request);
    static HRESULT ValidateClientSubtractUserVirtualCurrencyResponse(PFPlayerItemManagementModifyUserVirtualCurrencyResult* result);

    void FillClientUnlockContainerInstanceRequest(PlayFab::Wrappers::PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper<>& request);
    static HRESULT ValidateClientUnlockContainerInstanceResponse(PFPlayerItemManagementUnlockContainerItemResult* result);

    void FillClientUnlockContainerItemRequest(PlayFab::Wrappers::PFPlayerItemManagementClientUnlockContainerItemRequestWrapper<>& request);
    static HRESULT ValidateClientUnlockContainerItemResponse(PFPlayerItemManagementUnlockContainerItemResult* result);

    void FillServerAddCharacterVirtualCurrencyRequest(PlayFab::Wrappers::PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper<>& request);
    static HRESULT ValidateServerAddCharacterVirtualCurrencyResponse(PFPlayerItemManagementModifyCharacterVirtualCurrencyResult* result);

    void FillServerAddUserVirtualCurrencyRequest(PlayFab::Wrappers::PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper<>& request);
    static HRESULT ValidateServerAddUserVirtualCurrencyResponse(PFPlayerItemManagementModifyUserVirtualCurrencyResult* result);

    void FillServerConsumeItemRequest(PlayFab::Wrappers::PFPlayerItemManagementServerConsumeItemRequestWrapper<>& request);
    static HRESULT ValidateServerConsumeItemResponse(PFPlayerItemManagementConsumeItemResult* result);

    void FillServerEvaluateRandomResultTableRequest(PlayFab::Wrappers::PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper<>& request);
    static HRESULT ValidateServerEvaluateRandomResultTableResponse(PFPlayerItemManagementEvaluateRandomResultTableResult* result);

    void FillServerGetCharacterInventoryRequest(PlayFab::Wrappers::PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper<>& request);
    static HRESULT ValidateServerGetCharacterInventoryResponse(PFPlayerItemManagementServerGetCharacterInventoryResult* result);

    void FillServerGetRandomResultTablesRequest(PlayFab::Wrappers::PFPlayerItemManagementGetRandomResultTablesRequestWrapper<>& request);
    static HRESULT ValidateServerGetRandomResultTablesResponse(PFGetRandomResultTablesResult* result);

    void FillServerGetUserInventoryRequest(PlayFab::Wrappers::PFPlayerItemManagementServerGetUserInventoryRequestWrapper<>& request);
    static HRESULT ValidateServerGetUserInventoryResponse(PFPlayerItemManagementServerGetUserInventoryResult* result);

    void FillServerGrantItemsToCharacterRequest(PlayFab::Wrappers::PFPlayerItemManagementGrantItemsToCharacterRequestWrapper<>& request);
    static HRESULT ValidateServerGrantItemsToCharacterResponse(PFPlayerItemManagementGrantItemsToCharacterResult* result);

    void FillServerGrantItemsToUserRequest(PlayFab::Wrappers::PFPlayerItemManagementGrantItemsToUserRequestWrapper<>& request);
    static HRESULT ValidateServerGrantItemsToUserResponse(PFPlayerItemManagementGrantItemsToUserResult* result);

    void FillServerGrantItemsToUsersRequest(PlayFab::Wrappers::PFPlayerItemManagementGrantItemsToUsersRequestWrapper<>& request);
    static HRESULT ValidateServerGrantItemsToUsersResponse(PFPlayerItemManagementGrantItemsToUsersResult* result);

    void FillServerModifyItemUsesRequest(PlayFab::Wrappers::PFPlayerItemManagementModifyItemUsesRequestWrapper<>& request);
    static HRESULT ValidateServerModifyItemUsesResponse(PFPlayerItemManagementModifyItemUsesResult* result);

    void FillServerMoveItemToCharacterFromCharacterRequest(PlayFab::Wrappers::PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper<>& request);

    void FillServerMoveItemToCharacterFromUserRequest(PlayFab::Wrappers::PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper<>& request);

    void FillServerMoveItemToUserFromCharacterRequest(PlayFab::Wrappers::PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper<>& request);

    void FillServerRedeemCouponRequest(PlayFab::Wrappers::PFPlayerItemManagementServerRedeemCouponRequestWrapper<>& request);
    static HRESULT ValidateServerRedeemCouponResponse(PFPlayerItemManagementRedeemCouponResult* result);

    void FillServerReportPlayerRequest(PlayFab::Wrappers::PFPlayerItemManagementReportPlayerServerRequestWrapper<>& request);
    static HRESULT ValidateServerReportPlayerResponse(PFPlayerItemManagementReportPlayerServerResult* result);

    void FillServerRevokeInventoryItemRequest(PlayFab::Wrappers::PFPlayerItemManagementRevokeInventoryItemRequestWrapper<>& request);

    void FillServerRevokeInventoryItemsRequest(PlayFab::Wrappers::PFPlayerItemManagementRevokeInventoryItemsRequestWrapper<>& request);
    static HRESULT ValidateServerRevokeInventoryItemsResponse(PFPlayerItemManagementRevokeInventoryItemsResult* result);

    void FillServerSubtractCharacterVirtualCurrencyRequest(PlayFab::Wrappers::PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper<>& request);
    static HRESULT ValidateServerSubtractCharacterVirtualCurrencyResponse(PFPlayerItemManagementModifyCharacterVirtualCurrencyResult* result);

    void FillServerSubtractUserVirtualCurrencyRequest(PlayFab::Wrappers::PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper<>& request);
    static HRESULT ValidateServerSubtractUserVirtualCurrencyResponse(PFPlayerItemManagementModifyUserVirtualCurrencyResult* result);

    void FillServerUnlockContainerInstanceRequest(PlayFab::Wrappers::PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper<>& request);
    static HRESULT ValidateServerUnlockContainerInstanceResponse(PFPlayerItemManagementUnlockContainerItemResult* result);

    void FillServerUnlockContainerItemRequest(PlayFab::Wrappers::PFPlayerItemManagementServerUnlockContainerItemRequestWrapper<>& request);
    static HRESULT ValidateServerUnlockContainerItemResponse(PFPlayerItemManagementUnlockContainerItemResult* result);

    void FillServerUpdateUserInventoryItemCustomDataRequest(PlayFab::Wrappers::PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper<>& request);

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
