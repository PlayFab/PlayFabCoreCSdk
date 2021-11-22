#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFTitleDataManagementDataModelWrappers.h>
#include "AutoGenTitleDataManagementResultHolders.h"

namespace PlayFabUnit
{

class AutoGenTitleDataManagementTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

    void TestTitleDataManagementAdminAddLocalizedNews(TestContext& testContext);

    void TestTitleDataManagementAdminAddNews(TestContext& testContext);

    void TestTitleDataManagementAdminAddVirtualCurrencyTypes(TestContext& testContext);

    void TestTitleDataManagementAdminDeleteStore(TestContext& testContext);

    void TestTitleDataManagementAdminDeleteTitleDataOverride(TestContext& testContext);

    void TestTitleDataManagementAdminGetCatalogItems(TestContext& testContext);

    void TestTitleDataManagementAdminGetPublisherData(TestContext& testContext);

    void TestTitleDataManagementAdminGetRandomResultTables(TestContext& testContext);

    void TestTitleDataManagementAdminGetStoreItems(TestContext& testContext);

    void TestTitleDataManagementAdminGetTitleData(TestContext& testContext);

    void TestTitleDataManagementAdminGetTitleInternalData(TestContext& testContext);

    void TestTitleDataManagementAdminListVirtualCurrencyTypes(TestContext& testContext);

    void TestTitleDataManagementAdminRemoveVirtualCurrencyTypes(TestContext& testContext);

    void TestTitleDataManagementAdminSetCatalogItems(TestContext& testContext);

    void TestTitleDataManagementAdminSetPublisherData(TestContext& testContext);

    void TestTitleDataManagementAdminSetStoreItems(TestContext& testContext);

    void TestTitleDataManagementAdminSetTitleData(TestContext& testContext);

    void TestTitleDataManagementAdminSetTitleDataAndOverrides(TestContext& testContext);

    void TestTitleDataManagementAdminSetTitleInternalData(TestContext& testContext);

    void TestTitleDataManagementAdminSetupPushNotification(TestContext& testContext);

    void TestTitleDataManagementAdminUpdateCatalogItems(TestContext& testContext);

    void TestTitleDataManagementAdminUpdateRandomResultTables(TestContext& testContext);

    void TestTitleDataManagementAdminUpdateStoreItems(TestContext& testContext);

    void TestTitleDataManagementClientGetCatalogItems(TestContext& testContext);

    void TestTitleDataManagementClientGetPublisherData(TestContext& testContext);

    void TestTitleDataManagementClientGetStoreItems(TestContext& testContext);

    void TestTitleDataManagementClientGetTime(TestContext& testContext);

    void TestTitleDataManagementClientGetTitleData(TestContext& testContext);

    void TestTitleDataManagementClientGetTitleNews(TestContext& testContext);

    void TestTitleDataManagementServerGetCatalogItems(TestContext& testContext);

    void TestTitleDataManagementServerGetPublisherData(TestContext& testContext);

    void TestTitleDataManagementServerGetStoreItems(TestContext& testContext);

    void TestTitleDataManagementServerGetTime(TestContext& testContext);

    void TestTitleDataManagementServerGetTitleData(TestContext& testContext);

    void TestTitleDataManagementServerGetTitleInternalData(TestContext& testContext);

    void TestTitleDataManagementServerGetTitleNews(TestContext& testContext);

    void TestTitleDataManagementServerSetPublisherData(TestContext& testContext);

    void TestTitleDataManagementServerSetTitleData(TestContext& testContext);

    void TestTitleDataManagementServerSetTitleInternalData(TestContext& testContext);


protected:
    void AddTests();

    static void LogAddLocalizedNewsRequest(PFTitleDataManagementAddLocalizedNewsRequest const* request, const char* testName);
    static void FillAddLocalizedNewsRequest(PlayFab::Wrappers::PFTitleDataManagementAddLocalizedNewsRequestWrapper<>& request);

    static void LogAddNewsRequest(PFTitleDataManagementAddNewsRequest const* request, const char* testName);
    static void FillAddNewsRequest(PlayFab::Wrappers::PFTitleDataManagementAddNewsRequestWrapper<>& request);
    static HRESULT LogPFTitleDataManagementAddNewsResult(PFTitleDataManagementAddNewsResult const* result);
    static HRESULT ValidatePFTitleDataManagementAddNewsResult(PFTitleDataManagementAddNewsResult* result);

    static void LogAddVirtualCurrencyTypesRequest(PFTitleDataManagementAddVirtualCurrencyTypesRequest const* request, const char* testName);
    static void FillAddVirtualCurrencyTypesRequest(PlayFab::Wrappers::PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper<>& request);

    static void LogDeleteStoreRequest(PFTitleDataManagementDeleteStoreRequest const* request, const char* testName);
    static void FillDeleteStoreRequest(PlayFab::Wrappers::PFTitleDataManagementDeleteStoreRequestWrapper<>& request);

    static void LogDeleteTitleDataOverrideRequest(PFTitleDataManagementDeleteTitleDataOverrideRequest const* request, const char* testName);
    static void FillDeleteTitleDataOverrideRequest(PlayFab::Wrappers::PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper<>& request);

    static void LogGetCatalogItemsRequest(PFTitleDataManagementGetCatalogItemsRequest const* request, const char* testName);
    static void FillGetCatalogItemsRequest(PlayFab::Wrappers::PFTitleDataManagementGetCatalogItemsRequestWrapper<>& request);
    static HRESULT LogPFTitleDataManagementGetCatalogItemsResult(PFTitleDataManagementGetCatalogItemsResult const* result);
    static HRESULT ValidatePFTitleDataManagementGetCatalogItemsResult(PFTitleDataManagementGetCatalogItemsResult* result);

    static void LogGetPublisherDataRequest(PFTitleDataManagementGetPublisherDataRequest const* request, const char* testName);
    static void FillGetPublisherDataRequest(PlayFab::Wrappers::PFTitleDataManagementGetPublisherDataRequestWrapper<>& request);
    static HRESULT LogPFTitleDataManagementGetPublisherDataResult(PFTitleDataManagementGetPublisherDataResult const* result);
    static HRESULT ValidatePFTitleDataManagementGetPublisherDataResult(PFTitleDataManagementGetPublisherDataResult* result);

    static void LogGetRandomResultTablesRequest(PFTitleDataManagementGetRandomResultTablesRequest const* request, const char* testName);
    static void FillGetRandomResultTablesRequest(PlayFab::Wrappers::PFTitleDataManagementGetRandomResultTablesRequestWrapper<>& request);
    static HRESULT LogPFGetRandomResultTablesResult(PFGetRandomResultTablesResult const* result);
    static HRESULT ValidatePFGetRandomResultTablesResult(PFGetRandomResultTablesResult* result);

    static void LogGetStoreItemsRequest(PFTitleDataManagementGetStoreItemsRequest const* request, const char* testName);
    static void FillGetStoreItemsRequest(PlayFab::Wrappers::PFTitleDataManagementGetStoreItemsRequestWrapper<>& request);
    static HRESULT LogPFTitleDataManagementGetStoreItemsResult(PFTitleDataManagementGetStoreItemsResult const* result);
    static HRESULT ValidatePFTitleDataManagementGetStoreItemsResult(PFTitleDataManagementGetStoreItemsResult* result);

    static void LogGetTitleDataRequest(PFTitleDataManagementGetTitleDataRequest const* request, const char* testName);
    static void FillGetTitleDataRequest(PlayFab::Wrappers::PFTitleDataManagementGetTitleDataRequestWrapper<>& request);
    static HRESULT LogPFTitleDataManagementGetTitleDataResult(PFTitleDataManagementGetTitleDataResult const* result);
    static HRESULT ValidatePFTitleDataManagementGetTitleDataResult(PFTitleDataManagementGetTitleDataResult* result);


    static HRESULT LogPFTitleDataManagementListVirtualCurrencyTypesResult(PFTitleDataManagementListVirtualCurrencyTypesResult const* result);
    static HRESULT ValidatePFTitleDataManagementListVirtualCurrencyTypesResult(PFTitleDataManagementListVirtualCurrencyTypesResult* result);

    static void LogRemoveVirtualCurrencyTypesRequest(PFTitleDataManagementRemoveVirtualCurrencyTypesRequest const* request, const char* testName);
    static void FillRemoveVirtualCurrencyTypesRequest(PlayFab::Wrappers::PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper<>& request);

    static void LogUpdateCatalogItemsRequest(PFTitleDataManagementUpdateCatalogItemsRequest const* request, const char* testName);
    static void FillUpdateCatalogItemsRequest(PlayFab::Wrappers::PFTitleDataManagementUpdateCatalogItemsRequestWrapper<>& request);

    static void LogSetPublisherDataRequest(PFTitleDataManagementSetPublisherDataRequest const* request, const char* testName);
    static void FillSetPublisherDataRequest(PlayFab::Wrappers::PFTitleDataManagementSetPublisherDataRequestWrapper<>& request);

    static void LogUpdateStoreItemsRequest(PFTitleDataManagementUpdateStoreItemsRequest const* request, const char* testName);
    static void FillUpdateStoreItemsRequest(PlayFab::Wrappers::PFTitleDataManagementUpdateStoreItemsRequestWrapper<>& request);

    static void LogSetTitleDataRequest(PFTitleDataManagementSetTitleDataRequest const* request, const char* testName);
    static void FillSetTitleDataRequest(PlayFab::Wrappers::PFTitleDataManagementSetTitleDataRequestWrapper<>& request);
    static HRESULT LogPFTitleDataManagementSetTitleDataResult(PFTitleDataManagementSetTitleDataResult const* result);
    static HRESULT ValidatePFTitleDataManagementSetTitleDataResult(PFTitleDataManagementSetTitleDataResult* result);

    static void LogSetTitleDataAndOverridesRequest(PFTitleDataManagementSetTitleDataAndOverridesRequest const* request, const char* testName);
    static void FillSetTitleDataAndOverridesRequest(PlayFab::Wrappers::PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper<>& request);


    static void LogSetupPushNotificationRequest(PFTitleDataManagementSetupPushNotificationRequest const* request, const char* testName);
    static void FillSetupPushNotificationRequest(PlayFab::Wrappers::PFTitleDataManagementSetupPushNotificationRequestWrapper<>& request);
    static HRESULT LogPFTitleDataManagementSetupPushNotificationResult(PFTitleDataManagementSetupPushNotificationResult const* result);
    static HRESULT ValidatePFTitleDataManagementSetupPushNotificationResult(PFTitleDataManagementSetupPushNotificationResult* result);


    static void LogUpdateRandomResultTablesRequest(PFTitleDataManagementUpdateRandomResultTablesRequest const* request, const char* testName);
    static void FillUpdateRandomResultTablesRequest(PlayFab::Wrappers::PFTitleDataManagementUpdateRandomResultTablesRequestWrapper<>& request);





    static HRESULT LogPFTitleDataManagementGetTimeResult(PFTitleDataManagementGetTimeResult const* result);
    static HRESULT ValidatePFTitleDataManagementGetTimeResult(PFTitleDataManagementGetTimeResult* result);


    static void LogGetTitleNewsRequest(PFTitleDataManagementGetTitleNewsRequest const* request, const char* testName);
    static void FillGetTitleNewsRequest(PlayFab::Wrappers::PFTitleDataManagementGetTitleNewsRequestWrapper<>& request);
    static HRESULT LogPFTitleDataManagementGetTitleNewsResult(PFTitleDataManagementGetTitleNewsResult const* result);
    static HRESULT ValidatePFTitleDataManagementGetTitleNewsResult(PFTitleDataManagementGetTitleNewsResult* result);



    static void LogGetStoreItemsServerRequest(PFTitleDataManagementGetStoreItemsServerRequest const* request, const char* testName);
    static void FillGetStoreItemsServerRequest(PlayFab::Wrappers::PFTitleDataManagementGetStoreItemsServerRequestWrapper<>& request);








    struct TitleDataManagementTestData
    {
        ~TitleDataManagementTestData() = default;

    };

    static TitleDataManagementTestData testData;

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
