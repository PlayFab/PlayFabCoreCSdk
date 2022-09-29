#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFInventoryDataModelWrappers.h>
#include "AutoGenInventoryResultHolders.h"

namespace PlayFabUnit
{

class AutoGenInventoryTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

    void TestInventoryAddInventoryItems(TestContext& testContext);

    void TestInventoryDeleteInventoryCollection(TestContext& testContext);

    void TestInventoryDeleteInventoryItems(TestContext& testContext);

    void TestInventoryExecuteInventoryOperations(TestContext& testContext);

    void TestInventoryGetInventoryCollectionIds(TestContext& testContext);

    void TestInventoryGetInventoryItems(TestContext& testContext);

    void TestInventoryGetMicrosoftStoreAccessTokens(TestContext& testContext);

    void TestInventoryPurchaseInventoryItems(TestContext& testContext);

    void TestInventoryRedeemAppleAppStoreInventoryItems(TestContext& testContext);

    void TestInventoryRedeemGooglePlayInventoryItems(TestContext& testContext);

    void TestInventoryRedeemMicrosoftStoreInventoryItems(TestContext& testContext);

    void TestInventoryRedeemNintendoEShopInventoryItems(TestContext& testContext);

    void TestInventoryRedeemPlayStationStoreInventoryItems(TestContext& testContext);

    void TestInventoryRedeemSteamInventoryItems(TestContext& testContext);

    void TestInventorySubtractInventoryItems(TestContext& testContext);

    void TestInventoryTransferInventoryItems(TestContext& testContext);

    void TestInventoryUpdateInventoryItems(TestContext& testContext);


protected:
    void AddTests();

    static void LogAddInventoryItemsRequest(PFInventoryAddInventoryItemsRequest const* request, const char* testName);
    static HRESULT LogAddInventoryItemsResponse(PFInventoryAddInventoryItemsResponse const* result);
    static void LogDeleteInventoryCollectionRequest(PFInventoryDeleteInventoryCollectionRequest const* request, const char* testName);
    static void LogDeleteInventoryItemsRequest(PFInventoryDeleteInventoryItemsRequest const* request, const char* testName);
    static HRESULT LogDeleteInventoryItemsResponse(PFInventoryDeleteInventoryItemsResponse const* result);
    static void LogExecuteInventoryOperationsRequest(PFInventoryExecuteInventoryOperationsRequest const* request, const char* testName);
    static HRESULT LogExecuteInventoryOperationsResponse(PFInventoryExecuteInventoryOperationsResponse const* result);
    static void LogGetInventoryCollectionIdsRequest(PFInventoryGetInventoryCollectionIdsRequest const* request, const char* testName);
    static HRESULT LogGetInventoryCollectionIdsResponse(PFInventoryGetInventoryCollectionIdsResponse const* result);
    static void LogGetInventoryItemsRequest(PFInventoryGetInventoryItemsRequest const* request, const char* testName);
    static HRESULT LogGetInventoryItemsResponse(PFInventoryGetInventoryItemsResponse const* result);
    static void LogGetMicrosoftStoreAccessTokensRequest(PFInventoryGetMicrosoftStoreAccessTokensRequest const* request, const char* testName);
    static HRESULT LogGetMicrosoftStoreAccessTokensResponse(PFInventoryGetMicrosoftStoreAccessTokensResponse const* result);
    static void LogPurchaseInventoryItemsRequest(PFInventoryPurchaseInventoryItemsRequest const* request, const char* testName);
    static HRESULT LogPurchaseInventoryItemsResponse(PFInventoryPurchaseInventoryItemsResponse const* result);
    static void LogRedeemAppleAppStoreInventoryItemsRequest(PFInventoryRedeemAppleAppStoreInventoryItemsRequest const* request, const char* testName);
    static HRESULT LogRedeemAppleAppStoreInventoryItemsResponse(PFInventoryRedeemAppleAppStoreInventoryItemsResponse const* result);
    static void LogRedeemGooglePlayInventoryItemsRequest(PFInventoryRedeemGooglePlayInventoryItemsRequest const* request, const char* testName);
    static HRESULT LogRedeemGooglePlayInventoryItemsResponse(PFInventoryRedeemGooglePlayInventoryItemsResponse const* result);
    static void LogRedeemMicrosoftStoreInventoryItemsRequest(PFInventoryRedeemMicrosoftStoreInventoryItemsRequest const* request, const char* testName);
    static HRESULT LogRedeemMicrosoftStoreInventoryItemsResponse(PFInventoryRedeemMicrosoftStoreInventoryItemsResponse const* result);
    static void LogRedeemNintendoEShopInventoryItemsRequest(PFInventoryRedeemNintendoEShopInventoryItemsRequest const* request, const char* testName);
    static HRESULT LogRedeemNintendoEShopInventoryItemsResponse(PFInventoryRedeemNintendoEShopInventoryItemsResponse const* result);
    static void LogRedeemPlayStationStoreInventoryItemsRequest(PFInventoryRedeemPlayStationStoreInventoryItemsRequest const* request, const char* testName);
    static HRESULT LogRedeemPlayStationStoreInventoryItemsResponse(PFInventoryRedeemPlayStationStoreInventoryItemsResponse const* result);
    static void LogRedeemSteamInventoryItemsRequest(PFInventoryRedeemSteamInventoryItemsRequest const* request, const char* testName);
    static HRESULT LogRedeemSteamInventoryItemsResponse(PFInventoryRedeemSteamInventoryItemsResponse const* result);
    static void LogSubtractInventoryItemsRequest(PFInventorySubtractInventoryItemsRequest const* request, const char* testName);
    static HRESULT LogSubtractInventoryItemsResponse(PFInventorySubtractInventoryItemsResponse const* result);
    static void LogTransferInventoryItemsRequest(PFInventoryTransferInventoryItemsRequest const* request, const char* testName);
    static HRESULT LogTransferInventoryItemsResponse(PFInventoryTransferInventoryItemsResponse const* result);
    static void LogUpdateInventoryItemsRequest(PFInventoryUpdateInventoryItemsRequest const* request, const char* testName);
    static HRESULT LogUpdateInventoryItemsResponse(PFInventoryUpdateInventoryItemsResponse const* result);

    void FillAddInventoryItemsRequest(PlayFab::Wrappers::PFInventoryAddInventoryItemsRequestWrapper<>& request);
    static HRESULT ValidateAddInventoryItemsResponse(PFInventoryAddInventoryItemsResponse* result);

    void FillDeleteInventoryCollectionRequest(PlayFab::Wrappers::PFInventoryDeleteInventoryCollectionRequestWrapper<>& request);

    void FillDeleteInventoryItemsRequest(PlayFab::Wrappers::PFInventoryDeleteInventoryItemsRequestWrapper<>& request);
    static HRESULT ValidateDeleteInventoryItemsResponse(PFInventoryDeleteInventoryItemsResponse* result);

    void FillExecuteInventoryOperationsRequest(PlayFab::Wrappers::PFInventoryExecuteInventoryOperationsRequestWrapper<>& request);
    static HRESULT ValidateExecuteInventoryOperationsResponse(PFInventoryExecuteInventoryOperationsResponse* result);

    void FillGetInventoryCollectionIdsRequest(PlayFab::Wrappers::PFInventoryGetInventoryCollectionIdsRequestWrapper<>& request);
    static HRESULT ValidateGetInventoryCollectionIdsResponse(PFInventoryGetInventoryCollectionIdsResponse* result);

    void FillGetInventoryItemsRequest(PlayFab::Wrappers::PFInventoryGetInventoryItemsRequestWrapper<>& request);
    static HRESULT ValidateGetInventoryItemsResponse(PFInventoryGetInventoryItemsResponse* result);

    void FillGetMicrosoftStoreAccessTokensRequest(PlayFab::Wrappers::PFInventoryGetMicrosoftStoreAccessTokensRequestWrapper<>& request);
    static HRESULT ValidateGetMicrosoftStoreAccessTokensResponse(PFInventoryGetMicrosoftStoreAccessTokensResponse* result);

    void FillPurchaseInventoryItemsRequest(PlayFab::Wrappers::PFInventoryPurchaseInventoryItemsRequestWrapper<>& request);
    static HRESULT ValidatePurchaseInventoryItemsResponse(PFInventoryPurchaseInventoryItemsResponse* result);

    void FillRedeemAppleAppStoreInventoryItemsRequest(PlayFab::Wrappers::PFInventoryRedeemAppleAppStoreInventoryItemsRequestWrapper<>& request);
    static HRESULT ValidateRedeemAppleAppStoreInventoryItemsResponse(PFInventoryRedeemAppleAppStoreInventoryItemsResponse* result);

    void FillRedeemGooglePlayInventoryItemsRequest(PlayFab::Wrappers::PFInventoryRedeemGooglePlayInventoryItemsRequestWrapper<>& request);
    static HRESULT ValidateRedeemGooglePlayInventoryItemsResponse(PFInventoryRedeemGooglePlayInventoryItemsResponse* result);

    void FillRedeemMicrosoftStoreInventoryItemsRequest(PlayFab::Wrappers::PFInventoryRedeemMicrosoftStoreInventoryItemsRequestWrapper<>& request);
    static HRESULT ValidateRedeemMicrosoftStoreInventoryItemsResponse(PFInventoryRedeemMicrosoftStoreInventoryItemsResponse* result);

    void FillRedeemNintendoEShopInventoryItemsRequest(PlayFab::Wrappers::PFInventoryRedeemNintendoEShopInventoryItemsRequestWrapper<>& request);
    static HRESULT ValidateRedeemNintendoEShopInventoryItemsResponse(PFInventoryRedeemNintendoEShopInventoryItemsResponse* result);

    void FillRedeemPlayStationStoreInventoryItemsRequest(PlayFab::Wrappers::PFInventoryRedeemPlayStationStoreInventoryItemsRequestWrapper<>& request);
    static HRESULT ValidateRedeemPlayStationStoreInventoryItemsResponse(PFInventoryRedeemPlayStationStoreInventoryItemsResponse* result);

    void FillRedeemSteamInventoryItemsRequest(PlayFab::Wrappers::PFInventoryRedeemSteamInventoryItemsRequestWrapper<>& request);
    static HRESULT ValidateRedeemSteamInventoryItemsResponse(PFInventoryRedeemSteamInventoryItemsResponse* result);

    void FillSubtractInventoryItemsRequest(PlayFab::Wrappers::PFInventorySubtractInventoryItemsRequestWrapper<>& request);
    static HRESULT ValidateSubtractInventoryItemsResponse(PFInventorySubtractInventoryItemsResponse* result);

    void FillTransferInventoryItemsRequest(PlayFab::Wrappers::PFInventoryTransferInventoryItemsRequestWrapper<>& request);
    static HRESULT ValidateTransferInventoryItemsResponse(PFInventoryTransferInventoryItemsResponse* result);

    void FillUpdateInventoryItemsRequest(PlayFab::Wrappers::PFInventoryUpdateInventoryItemsRequestWrapper<>& request);
    static HRESULT ValidateUpdateInventoryItemsResponse(PFInventoryUpdateInventoryItemsResponse* result);

    struct InventoryTestData
    {
        ~InventoryTestData() = default;

    };

    static InventoryTestData testData;

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
