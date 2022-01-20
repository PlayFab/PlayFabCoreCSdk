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

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminAddLocalizedNews(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminAddNews(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminAddVirtualCurrencyTypes(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminDeleteStore(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminDeleteTitleDataOverride(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminGetCatalogItems(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminGetPublisherData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminGetRandomResultTables(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminGetStoreItems(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminGetTitleData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminGetTitleInternalData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminListVirtualCurrencyTypes(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminRemoveVirtualCurrencyTypes(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminSetCatalogItems(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminSetPublisherData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminSetStoreItems(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminSetTitleData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminSetTitleDataAndOverrides(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminSetTitleInternalData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminSetupPushNotification(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminUpdateCatalogItems(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminUpdateRandomResultTables(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementAdminUpdateStoreItems(TestContext& testContext);
#endif

    void TestTitleDataManagementClientGetCatalogItems(TestContext& testContext);

    void TestTitleDataManagementClientGetPublisherData(TestContext& testContext);

    void TestTitleDataManagementClientGetStoreItems(TestContext& testContext);

    void TestTitleDataManagementClientGetTime(TestContext& testContext);

    void TestTitleDataManagementClientGetTitleData(TestContext& testContext);

    void TestTitleDataManagementClientGetTitleNews(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementServerGetCatalogItems(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementServerGetPublisherData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementServerGetStoreItems(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementServerGetTime(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementServerGetTitleData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementServerGetTitleInternalData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementServerGetTitleNews(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementServerSetPublisherData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementServerSetTitleData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestTitleDataManagementServerSetTitleInternalData(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogAddLocalizedNewsRequest(PFTitleDataManagementAddLocalizedNewsRequest const* request, const char* testName);
    static void LogAddNewsRequest(PFTitleDataManagementAddNewsRequest const* request, const char* testName);
    static HRESULT LogAddNewsResult(PFTitleDataManagementAddNewsResult const* result);
    static void LogAddVirtualCurrencyTypesRequest(PFTitleDataManagementAddVirtualCurrencyTypesRequest const* request, const char* testName);
    static void LogDeleteStoreRequest(PFTitleDataManagementDeleteStoreRequest const* request, const char* testName);
    static void LogDeleteTitleDataOverrideRequest(PFTitleDataManagementDeleteTitleDataOverrideRequest const* request, const char* testName);
    static void LogGetCatalogItemsRequest(PFTitleDataManagementGetCatalogItemsRequest const* request, const char* testName);
    static HRESULT LogGetCatalogItemsResult(PFTitleDataManagementGetCatalogItemsResult const* result);
    static void LogGetPublisherDataRequest(PFTitleDataManagementGetPublisherDataRequest const* request, const char* testName);
    static HRESULT LogGetPublisherDataResult(PFTitleDataManagementGetPublisherDataResult const* result);
    static void LogGetRandomResultTablesRequest(PFTitleDataManagementGetRandomResultTablesRequest const* request, const char* testName);
    static HRESULT LogGetRandomResultTablesResult(PFGetRandomResultTablesResult const* result);
    static void LogGetStoreItemsRequest(PFTitleDataManagementGetStoreItemsRequest const* request, const char* testName);
    static HRESULT LogGetStoreItemsResult(PFTitleDataManagementGetStoreItemsResult const* result);
    static void LogGetTitleDataRequest(PFTitleDataManagementGetTitleDataRequest const* request, const char* testName);
    static HRESULT LogGetTitleDataResult(PFTitleDataManagementGetTitleDataResult const* result);
    static HRESULT LogListVirtualCurrencyTypesResult(PFTitleDataManagementListVirtualCurrencyTypesResult const* result);
    static void LogRemoveVirtualCurrencyTypesRequest(PFTitleDataManagementRemoveVirtualCurrencyTypesRequest const* request, const char* testName);
    static void LogUpdateCatalogItemsRequest(PFTitleDataManagementUpdateCatalogItemsRequest const* request, const char* testName);
    static void LogSetPublisherDataRequest(PFTitleDataManagementSetPublisherDataRequest const* request, const char* testName);
    static void LogUpdateStoreItemsRequest(PFTitleDataManagementUpdateStoreItemsRequest const* request, const char* testName);
    static void LogSetTitleDataRequest(PFTitleDataManagementSetTitleDataRequest const* request, const char* testName);
    static HRESULT LogSetTitleDataResult(PFTitleDataManagementSetTitleDataResult const* result);
    static void LogSetTitleDataAndOverridesRequest(PFTitleDataManagementSetTitleDataAndOverridesRequest const* request, const char* testName);
    static void LogSetupPushNotificationRequest(PFTitleDataManagementSetupPushNotificationRequest const* request, const char* testName);
    static HRESULT LogSetupPushNotificationResult(PFTitleDataManagementSetupPushNotificationResult const* result);
    static void LogUpdateRandomResultTablesRequest(PFTitleDataManagementUpdateRandomResultTablesRequest const* request, const char* testName);
    static HRESULT LogGetTimeResult(PFTitleDataManagementGetTimeResult const* result);
    static void LogGetTitleNewsRequest(PFTitleDataManagementGetTitleNewsRequest const* request, const char* testName);
    static HRESULT LogGetTitleNewsResult(PFTitleDataManagementGetTitleNewsResult const* result);
    static void LogGetStoreItemsServerRequest(PFTitleDataManagementGetStoreItemsServerRequest const* request, const char* testName);

    static void FillAdminAddLocalizedNewsRequest(PlayFab::Wrappers::PFTitleDataManagementAddLocalizedNewsRequestWrapper<>& request);

    static void FillAdminAddNewsRequest(PlayFab::Wrappers::PFTitleDataManagementAddNewsRequestWrapper<>& request);
    static HRESULT ValidateAdminAddNewsResponse(PFTitleDataManagementAddNewsResult* result);

    static void FillAdminAddVirtualCurrencyTypesRequest(PlayFab::Wrappers::PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper<>& request);

    static void FillAdminDeleteStoreRequest(PlayFab::Wrappers::PFTitleDataManagementDeleteStoreRequestWrapper<>& request);

    static void FillAdminDeleteTitleDataOverrideRequest(PlayFab::Wrappers::PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper<>& request);

    static void FillAdminGetCatalogItemsRequest(PlayFab::Wrappers::PFTitleDataManagementGetCatalogItemsRequestWrapper<>& request);
    static HRESULT ValidateAdminGetCatalogItemsResponse(PFTitleDataManagementGetCatalogItemsResult* result);

    static void FillAdminGetPublisherDataRequest(PlayFab::Wrappers::PFTitleDataManagementGetPublisherDataRequestWrapper<>& request);
    static HRESULT ValidateAdminGetPublisherDataResponse(PFTitleDataManagementGetPublisherDataResult* result);

    static void FillAdminGetRandomResultTablesRequest(PlayFab::Wrappers::PFTitleDataManagementGetRandomResultTablesRequestWrapper<>& request);
    static HRESULT ValidateAdminGetRandomResultTablesResponse(PFGetRandomResultTablesResult* result);

    static void FillAdminGetStoreItemsRequest(PlayFab::Wrappers::PFTitleDataManagementGetStoreItemsRequestWrapper<>& request);
    static HRESULT ValidateAdminGetStoreItemsResponse(PFTitleDataManagementGetStoreItemsResult* result);

    static void FillAdminGetTitleDataRequest(PlayFab::Wrappers::PFTitleDataManagementGetTitleDataRequestWrapper<>& request);
    static HRESULT ValidateAdminGetTitleDataResponse(PFTitleDataManagementGetTitleDataResult* result);

    static void FillAdminGetTitleInternalDataRequest(PlayFab::Wrappers::PFTitleDataManagementGetTitleDataRequestWrapper<>& request);
    static HRESULT ValidateAdminGetTitleInternalDataResponse(PFTitleDataManagementGetTitleDataResult* result);

    static HRESULT ValidateAdminListVirtualCurrencyTypesResponse(PFTitleDataManagementListVirtualCurrencyTypesResult* result);

    static void FillAdminRemoveVirtualCurrencyTypesRequest(PlayFab::Wrappers::PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper<>& request);

    static void FillAdminSetCatalogItemsRequest(PlayFab::Wrappers::PFTitleDataManagementUpdateCatalogItemsRequestWrapper<>& request);

    static void FillAdminSetPublisherDataRequest(PlayFab::Wrappers::PFTitleDataManagementSetPublisherDataRequestWrapper<>& request);

    static void FillAdminSetStoreItemsRequest(PlayFab::Wrappers::PFTitleDataManagementUpdateStoreItemsRequestWrapper<>& request);

    static void FillAdminSetTitleDataRequest(PlayFab::Wrappers::PFTitleDataManagementSetTitleDataRequestWrapper<>& request);
    static HRESULT ValidateAdminSetTitleDataResponse(PFTitleDataManagementSetTitleDataResult* result);

    static void FillAdminSetTitleDataAndOverridesRequest(PlayFab::Wrappers::PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper<>& request);

    static void FillAdminSetTitleInternalDataRequest(PlayFab::Wrappers::PFTitleDataManagementSetTitleDataRequestWrapper<>& request);
    static HRESULT ValidateAdminSetTitleInternalDataResponse(PFTitleDataManagementSetTitleDataResult* result);

    static void FillAdminSetupPushNotificationRequest(PlayFab::Wrappers::PFTitleDataManagementSetupPushNotificationRequestWrapper<>& request);
    static HRESULT ValidateAdminSetupPushNotificationResponse(PFTitleDataManagementSetupPushNotificationResult* result);

    static void FillAdminUpdateCatalogItemsRequest(PlayFab::Wrappers::PFTitleDataManagementUpdateCatalogItemsRequestWrapper<>& request);

    static void FillAdminUpdateRandomResultTablesRequest(PlayFab::Wrappers::PFTitleDataManagementUpdateRandomResultTablesRequestWrapper<>& request);

    static void FillAdminUpdateStoreItemsRequest(PlayFab::Wrappers::PFTitleDataManagementUpdateStoreItemsRequestWrapper<>& request);

    static void FillClientGetCatalogItemsRequest(PlayFab::Wrappers::PFTitleDataManagementGetCatalogItemsRequestWrapper<>& request);
    static HRESULT ValidateClientGetCatalogItemsResponse(PFTitleDataManagementGetCatalogItemsResult* result);

    static void FillClientGetPublisherDataRequest(PlayFab::Wrappers::PFTitleDataManagementGetPublisherDataRequestWrapper<>& request);
    static HRESULT ValidateClientGetPublisherDataResponse(PFTitleDataManagementGetPublisherDataResult* result);

    static void FillClientGetStoreItemsRequest(PlayFab::Wrappers::PFTitleDataManagementGetStoreItemsRequestWrapper<>& request);
    static HRESULT ValidateClientGetStoreItemsResponse(PFTitleDataManagementGetStoreItemsResult* result);

    static HRESULT ValidateClientGetTimeResponse(PFTitleDataManagementGetTimeResult* result);

    static void FillClientGetTitleDataRequest(PlayFab::Wrappers::PFTitleDataManagementGetTitleDataRequestWrapper<>& request);
    static HRESULT ValidateClientGetTitleDataResponse(PFTitleDataManagementGetTitleDataResult* result);

    static void FillClientGetTitleNewsRequest(PlayFab::Wrappers::PFTitleDataManagementGetTitleNewsRequestWrapper<>& request);
    static HRESULT ValidateClientGetTitleNewsResponse(PFTitleDataManagementGetTitleNewsResult* result);

    static void FillServerGetCatalogItemsRequest(PlayFab::Wrappers::PFTitleDataManagementGetCatalogItemsRequestWrapper<>& request);
    static HRESULT ValidateServerGetCatalogItemsResponse(PFTitleDataManagementGetCatalogItemsResult* result);

    static void FillServerGetPublisherDataRequest(PlayFab::Wrappers::PFTitleDataManagementGetPublisherDataRequestWrapper<>& request);
    static HRESULT ValidateServerGetPublisherDataResponse(PFTitleDataManagementGetPublisherDataResult* result);

    static void FillServerGetStoreItemsRequest(PlayFab::Wrappers::PFTitleDataManagementGetStoreItemsServerRequestWrapper<>& request);
    static HRESULT ValidateServerGetStoreItemsResponse(PFTitleDataManagementGetStoreItemsResult* result);

    static HRESULT ValidateServerGetTimeResponse(PFTitleDataManagementGetTimeResult* result);

    static void FillServerGetTitleDataRequest(PlayFab::Wrappers::PFTitleDataManagementGetTitleDataRequestWrapper<>& request);
    static HRESULT ValidateServerGetTitleDataResponse(PFTitleDataManagementGetTitleDataResult* result);

    static void FillServerGetTitleInternalDataRequest(PlayFab::Wrappers::PFTitleDataManagementGetTitleDataRequestWrapper<>& request);
    static HRESULT ValidateServerGetTitleInternalDataResponse(PFTitleDataManagementGetTitleDataResult* result);

    static void FillServerGetTitleNewsRequest(PlayFab::Wrappers::PFTitleDataManagementGetTitleNewsRequestWrapper<>& request);
    static HRESULT ValidateServerGetTitleNewsResponse(PFTitleDataManagementGetTitleNewsResult* result);

    static void FillServerSetPublisherDataRequest(PlayFab::Wrappers::PFTitleDataManagementSetPublisherDataRequestWrapper<>& request);

    static void FillServerSetTitleDataRequest(PlayFab::Wrappers::PFTitleDataManagementSetTitleDataRequestWrapper<>& request);
    static HRESULT ValidateServerSetTitleDataResponse(PFTitleDataManagementSetTitleDataResult* result);

    static void FillServerSetTitleInternalDataRequest(PlayFab::Wrappers::PFTitleDataManagementSetTitleDataRequestWrapper<>& request);
    static HRESULT ValidateServerSetTitleInternalDataResponse(PFTitleDataManagementSetTitleDataResult* result);

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
