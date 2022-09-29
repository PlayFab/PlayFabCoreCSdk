#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFAnalyticsDataModelWrappers.h>
#include "AutoGenAnalyticsResultHolders.h"

namespace PlayFabUnit
{

class AutoGenAnalyticsTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

    void TestAnalyticsClientReportDeviceInfo(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAnalyticsGetDetails(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAnalyticsGetLimits(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAnalyticsGetOperationStatus(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAnalyticsGetPendingOperations(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAnalyticsSetPerformance(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAnalyticsSetStorageRetention(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogDeviceInfoRequest(PFAnalyticsDeviceInfoRequest const* request, const char* testName);
    static void LogInsightsEmptyRequest(PFAnalyticsInsightsEmptyRequest const* request, const char* testName);
    static HRESULT LogInsightsGetDetailsResponse(PFAnalyticsInsightsGetDetailsResponse const* result);
    static HRESULT LogInsightsGetLimitsResponse(PFAnalyticsInsightsGetLimitsResponse const* result);
    static void LogInsightsGetOperationStatusRequest(PFAnalyticsInsightsGetOperationStatusRequest const* request, const char* testName);
    static HRESULT LogInsightsGetOperationStatusResponse(PFAnalyticsInsightsGetOperationStatusResponse const* result);
    static void LogInsightsGetPendingOperationsRequest(PFAnalyticsInsightsGetPendingOperationsRequest const* request, const char* testName);
    static HRESULT LogInsightsGetPendingOperationsResponse(PFAnalyticsInsightsGetPendingOperationsResponse const* result);
    static void LogInsightsSetPerformanceRequest(PFAnalyticsInsightsSetPerformanceRequest const* request, const char* testName);
    static HRESULT LogInsightsOperationResponse(PFAnalyticsInsightsOperationResponse const* result);
    static void LogInsightsSetStorageRetentionRequest(PFAnalyticsInsightsSetStorageRetentionRequest const* request, const char* testName);

    void FillClientReportDeviceInfoRequest(PlayFab::Wrappers::PFAnalyticsDeviceInfoRequestWrapper<>& request);

    void FillGetDetailsRequest(PlayFab::Wrappers::PFAnalyticsInsightsEmptyRequestWrapper<>& request);
    static HRESULT ValidateGetDetailsResponse(PFAnalyticsInsightsGetDetailsResponse* result);

    void FillGetLimitsRequest(PlayFab::Wrappers::PFAnalyticsInsightsEmptyRequestWrapper<>& request);
    static HRESULT ValidateGetLimitsResponse(PFAnalyticsInsightsGetLimitsResponse* result);

    void FillGetOperationStatusRequest(PlayFab::Wrappers::PFAnalyticsInsightsGetOperationStatusRequestWrapper<>& request);
    static HRESULT ValidateGetOperationStatusResponse(PFAnalyticsInsightsGetOperationStatusResponse* result);

    void FillGetPendingOperationsRequest(PlayFab::Wrappers::PFAnalyticsInsightsGetPendingOperationsRequestWrapper<>& request);
    static HRESULT ValidateGetPendingOperationsResponse(PFAnalyticsInsightsGetPendingOperationsResponse* result);

    void FillSetPerformanceRequest(PlayFab::Wrappers::PFAnalyticsInsightsSetPerformanceRequestWrapper<>& request);
    static HRESULT ValidateSetPerformanceResponse(PFAnalyticsInsightsOperationResponse* result);

    void FillSetStorageRetentionRequest(PlayFab::Wrappers::PFAnalyticsInsightsSetStorageRetentionRequestWrapper<>& request);
    static HRESULT ValidateSetStorageRetentionResponse(PFAnalyticsInsightsOperationResponse* result);

    struct AnalyticsTestData
    {
        ~AnalyticsTestData() = default;

    };

    static AnalyticsTestData testData;

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
