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

    void TestAnalyticsClientWriteCharacterEvent(TestContext& testContext);

    void TestAnalyticsClientWritePlayerEvent(TestContext& testContext);

    void TestAnalyticsClientWriteTitleEvent(TestContext& testContext);

    void TestAnalyticsServerWriteCharacterEvent(TestContext& testContext);

    void TestAnalyticsServerWritePlayerEvent(TestContext& testContext);

    void TestAnalyticsServerWriteTitleEvent(TestContext& testContext);

    void TestAnalyticsGetDetails(TestContext& testContext);

    void TestAnalyticsGetLimits(TestContext& testContext);

    void TestAnalyticsGetOperationStatus(TestContext& testContext);

    void TestAnalyticsGetPendingOperations(TestContext& testContext);

    void TestAnalyticsSetPerformance(TestContext& testContext);

    void TestAnalyticsSetStorageRetention(TestContext& testContext);


protected:
    void AddTests();

    static void LogDeviceInfoRequest(PFAnalyticsDeviceInfoRequest const* request, const char* testName);
    static void FillDeviceInfoRequest(PlayFab::Wrappers::PFAnalyticsDeviceInfoRequestWrapper<>& request);

    static void LogWriteClientCharacterEventRequest(PFAnalyticsWriteClientCharacterEventRequest const* request, const char* testName);
    static void FillWriteClientCharacterEventRequest(PlayFab::Wrappers::PFAnalyticsWriteClientCharacterEventRequestWrapper<>& request);
    static HRESULT LogPFAnalyticsWriteEventResponse(PFAnalyticsWriteEventResponse const* result);
    static HRESULT ValidatePFAnalyticsWriteEventResponse(PFAnalyticsWriteEventResponse* result);

    static void LogWriteClientPlayerEventRequest(PFAnalyticsWriteClientPlayerEventRequest const* request, const char* testName);
    static void FillWriteClientPlayerEventRequest(PlayFab::Wrappers::PFAnalyticsWriteClientPlayerEventRequestWrapper<>& request);

    static void LogWriteTitleEventRequest(PFAnalyticsWriteTitleEventRequest const* request, const char* testName);
    static void FillWriteTitleEventRequest(PlayFab::Wrappers::PFAnalyticsWriteTitleEventRequestWrapper<>& request);

    static void LogWriteServerCharacterEventRequest(PFAnalyticsWriteServerCharacterEventRequest const* request, const char* testName);
    static void FillWriteServerCharacterEventRequest(PlayFab::Wrappers::PFAnalyticsWriteServerCharacterEventRequestWrapper<>& request);

    static void LogWriteServerPlayerEventRequest(PFAnalyticsWriteServerPlayerEventRequest const* request, const char* testName);
    static void FillWriteServerPlayerEventRequest(PlayFab::Wrappers::PFAnalyticsWriteServerPlayerEventRequestWrapper<>& request);


    static void LogInsightsEmptyRequest(PFAnalyticsInsightsEmptyRequest const* request, const char* testName);
    static void FillInsightsEmptyRequest(PlayFab::Wrappers::PFAnalyticsInsightsEmptyRequestWrapper<>& request);
    static HRESULT LogPFAnalyticsInsightsGetDetailsResponse(PFAnalyticsInsightsGetDetailsResponse const* result);
    static HRESULT ValidatePFAnalyticsInsightsGetDetailsResponse(PFAnalyticsInsightsGetDetailsResponse* result);

    static HRESULT LogPFAnalyticsInsightsGetLimitsResponse(PFAnalyticsInsightsGetLimitsResponse const* result);
    static HRESULT ValidatePFAnalyticsInsightsGetLimitsResponse(PFAnalyticsInsightsGetLimitsResponse* result);

    static void LogInsightsGetOperationStatusRequest(PFAnalyticsInsightsGetOperationStatusRequest const* request, const char* testName);
    static void FillInsightsGetOperationStatusRequest(PlayFab::Wrappers::PFAnalyticsInsightsGetOperationStatusRequestWrapper<>& request);
    static HRESULT LogPFAnalyticsInsightsGetOperationStatusResponse(PFAnalyticsInsightsGetOperationStatusResponse const* result);
    static HRESULT ValidatePFAnalyticsInsightsGetOperationStatusResponse(PFAnalyticsInsightsGetOperationStatusResponse* result);

    static void LogInsightsGetPendingOperationsRequest(PFAnalyticsInsightsGetPendingOperationsRequest const* request, const char* testName);
    static void FillInsightsGetPendingOperationsRequest(PlayFab::Wrappers::PFAnalyticsInsightsGetPendingOperationsRequestWrapper<>& request);
    static HRESULT LogPFAnalyticsInsightsGetPendingOperationsResponse(PFAnalyticsInsightsGetPendingOperationsResponse const* result);
    static HRESULT ValidatePFAnalyticsInsightsGetPendingOperationsResponse(PFAnalyticsInsightsGetPendingOperationsResponse* result);

    static void LogInsightsSetPerformanceRequest(PFAnalyticsInsightsSetPerformanceRequest const* request, const char* testName);
    static void FillInsightsSetPerformanceRequest(PlayFab::Wrappers::PFAnalyticsInsightsSetPerformanceRequestWrapper<>& request);
    static HRESULT LogPFAnalyticsInsightsOperationResponse(PFAnalyticsInsightsOperationResponse const* result);
    static HRESULT ValidatePFAnalyticsInsightsOperationResponse(PFAnalyticsInsightsOperationResponse* result);

    static void LogInsightsSetStorageRetentionRequest(PFAnalyticsInsightsSetStorageRetentionRequest const* request, const char* testName);
    static void FillInsightsSetStorageRetentionRequest(PlayFab::Wrappers::PFAnalyticsInsightsSetStorageRetentionRequestWrapper<>& request);

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
