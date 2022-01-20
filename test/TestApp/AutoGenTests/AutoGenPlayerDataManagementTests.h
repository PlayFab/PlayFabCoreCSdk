#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFPlayerDataManagementDataModelWrappers.h>
#include "AutoGenPlayerDataManagementResultHolders.h"

namespace PlayFabUnit
{

class AutoGenPlayerDataManagementTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementAdminGetDataReport(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementAdminGetUserData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementAdminGetUserInternalData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementAdminGetUserPublisherData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementAdminGetUserPublisherInternalData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementAdminGetUserPublisherReadOnlyData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementAdminGetUserReadOnlyData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementAdminUpdateUserData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementAdminUpdateUserInternalData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementAdminUpdateUserPublisherData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementAdminUpdateUserPublisherInternalData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementAdminUpdateUserPublisherReadOnlyData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementAdminUpdateUserReadOnlyData(TestContext& testContext);
#endif

    void TestPlayerDataManagementClientGetUserData(TestContext& testContext);

    void TestPlayerDataManagementClientGetUserPublisherData(TestContext& testContext);

    void TestPlayerDataManagementClientGetUserPublisherReadOnlyData(TestContext& testContext);

    void TestPlayerDataManagementClientGetUserReadOnlyData(TestContext& testContext);

    void TestPlayerDataManagementClientUpdateUserData(TestContext& testContext);

    void TestPlayerDataManagementClientUpdateUserPublisherData(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementServerGetUserData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementServerGetUserInternalData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementServerGetUserPublisherData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementServerGetUserPublisherInternalData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementServerGetUserPublisherReadOnlyData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementServerGetUserReadOnlyData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementServerUpdateUserData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementServerUpdateUserInternalData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementServerUpdateUserPublisherData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementServerUpdateUserPublisherInternalData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementServerUpdateUserPublisherReadOnlyData(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestPlayerDataManagementServerUpdateUserReadOnlyData(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogGetDataReportRequest(PFPlayerDataManagementGetDataReportRequest const* request, const char* testName);
    static HRESULT LogGetDataReportResult(PFPlayerDataManagementGetDataReportResult const* result);
    static void LogGetUserDataRequest(PFPlayerDataManagementGetUserDataRequest const* request, const char* testName);
    static HRESULT LogAdminGetUserDataResult(PFPlayerDataManagementAdminGetUserDataResult const* result);
    static void LogAdminUpdateUserDataRequest(PFPlayerDataManagementAdminUpdateUserDataRequest const* request, const char* testName);
    static HRESULT LogUpdateUserDataResult(PFPlayerDataManagementUpdateUserDataResult const* result);
    static void LogUpdateUserInternalDataRequest(PFPlayerDataManagementUpdateUserInternalDataRequest const* request, const char* testName);
    static HRESULT LogClientGetUserDataResult(PFPlayerDataManagementClientGetUserDataResult const* result);
    static void LogClientUpdateUserDataRequest(PFPlayerDataManagementClientUpdateUserDataRequest const* request, const char* testName);
    static HRESULT LogServerGetUserDataResult(PFPlayerDataManagementServerGetUserDataResult const* result);
    static void LogServerUpdateUserDataRequest(PFPlayerDataManagementServerUpdateUserDataRequest const* request, const char* testName);

    static void FillAdminGetDataReportRequest(PlayFab::Wrappers::PFPlayerDataManagementGetDataReportRequestWrapper<>& request);
    static HRESULT ValidateAdminGetDataReportResponse(PFPlayerDataManagementGetDataReportResult* result);

    static void FillAdminGetUserDataRequest(PlayFab::Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<>& request);
    static HRESULT ValidateAdminGetUserDataResponse(PFPlayerDataManagementAdminGetUserDataResult* result);

    static void FillAdminGetUserInternalDataRequest(PlayFab::Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<>& request);
    static HRESULT ValidateAdminGetUserInternalDataResponse(PFPlayerDataManagementAdminGetUserDataResult* result);

    static void FillAdminGetUserPublisherDataRequest(PlayFab::Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<>& request);
    static HRESULT ValidateAdminGetUserPublisherDataResponse(PFPlayerDataManagementAdminGetUserDataResult* result);

    static void FillAdminGetUserPublisherInternalDataRequest(PlayFab::Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<>& request);
    static HRESULT ValidateAdminGetUserPublisherInternalDataResponse(PFPlayerDataManagementAdminGetUserDataResult* result);

    static void FillAdminGetUserPublisherReadOnlyDataRequest(PlayFab::Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<>& request);
    static HRESULT ValidateAdminGetUserPublisherReadOnlyDataResponse(PFPlayerDataManagementAdminGetUserDataResult* result);

    static void FillAdminGetUserReadOnlyDataRequest(PlayFab::Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<>& request);
    static HRESULT ValidateAdminGetUserReadOnlyDataResponse(PFPlayerDataManagementAdminGetUserDataResult* result);

    static void FillAdminUpdateUserDataRequest(PlayFab::Wrappers::PFPlayerDataManagementAdminUpdateUserDataRequestWrapper<>& request);
    static HRESULT ValidateAdminUpdateUserDataResponse(PFPlayerDataManagementUpdateUserDataResult* result);

    static void FillAdminUpdateUserInternalDataRequest(PlayFab::Wrappers::PFPlayerDataManagementUpdateUserInternalDataRequestWrapper<>& request);
    static HRESULT ValidateAdminUpdateUserInternalDataResponse(PFPlayerDataManagementUpdateUserDataResult* result);

    static void FillAdminUpdateUserPublisherDataRequest(PlayFab::Wrappers::PFPlayerDataManagementAdminUpdateUserDataRequestWrapper<>& request);
    static HRESULT ValidateAdminUpdateUserPublisherDataResponse(PFPlayerDataManagementUpdateUserDataResult* result);

    static void FillAdminUpdateUserPublisherInternalDataRequest(PlayFab::Wrappers::PFPlayerDataManagementUpdateUserInternalDataRequestWrapper<>& request);
    static HRESULT ValidateAdminUpdateUserPublisherInternalDataResponse(PFPlayerDataManagementUpdateUserDataResult* result);

    static void FillAdminUpdateUserPublisherReadOnlyDataRequest(PlayFab::Wrappers::PFPlayerDataManagementAdminUpdateUserDataRequestWrapper<>& request);
    static HRESULT ValidateAdminUpdateUserPublisherReadOnlyDataResponse(PFPlayerDataManagementUpdateUserDataResult* result);

    static void FillAdminUpdateUserReadOnlyDataRequest(PlayFab::Wrappers::PFPlayerDataManagementAdminUpdateUserDataRequestWrapper<>& request);
    static HRESULT ValidateAdminUpdateUserReadOnlyDataResponse(PFPlayerDataManagementUpdateUserDataResult* result);

    static void FillClientGetUserDataRequest(PlayFab::Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<>& request);
    static HRESULT ValidateClientGetUserDataResponse(PFPlayerDataManagementClientGetUserDataResult* result);

    static void FillClientGetUserPublisherDataRequest(PlayFab::Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<>& request);
    static HRESULT ValidateClientGetUserPublisherDataResponse(PFPlayerDataManagementClientGetUserDataResult* result);

    static void FillClientGetUserPublisherReadOnlyDataRequest(PlayFab::Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<>& request);
    static HRESULT ValidateClientGetUserPublisherReadOnlyDataResponse(PFPlayerDataManagementClientGetUserDataResult* result);

    static void FillClientGetUserReadOnlyDataRequest(PlayFab::Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<>& request);
    static HRESULT ValidateClientGetUserReadOnlyDataResponse(PFPlayerDataManagementClientGetUserDataResult* result);

    static void FillClientUpdateUserDataRequest(PlayFab::Wrappers::PFPlayerDataManagementClientUpdateUserDataRequestWrapper<>& request);
    static HRESULT ValidateClientUpdateUserDataResponse(PFPlayerDataManagementUpdateUserDataResult* result);

    static void FillClientUpdateUserPublisherDataRequest(PlayFab::Wrappers::PFPlayerDataManagementClientUpdateUserDataRequestWrapper<>& request);
    static HRESULT ValidateClientUpdateUserPublisherDataResponse(PFPlayerDataManagementUpdateUserDataResult* result);

    static void FillServerGetUserDataRequest(PlayFab::Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<>& request);
    static HRESULT ValidateServerGetUserDataResponse(PFPlayerDataManagementServerGetUserDataResult* result);

    static void FillServerGetUserInternalDataRequest(PlayFab::Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<>& request);
    static HRESULT ValidateServerGetUserInternalDataResponse(PFPlayerDataManagementServerGetUserDataResult* result);

    static void FillServerGetUserPublisherDataRequest(PlayFab::Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<>& request);
    static HRESULT ValidateServerGetUserPublisherDataResponse(PFPlayerDataManagementServerGetUserDataResult* result);

    static void FillServerGetUserPublisherInternalDataRequest(PlayFab::Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<>& request);
    static HRESULT ValidateServerGetUserPublisherInternalDataResponse(PFPlayerDataManagementServerGetUserDataResult* result);

    static void FillServerGetUserPublisherReadOnlyDataRequest(PlayFab::Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<>& request);
    static HRESULT ValidateServerGetUserPublisherReadOnlyDataResponse(PFPlayerDataManagementServerGetUserDataResult* result);

    static void FillServerGetUserReadOnlyDataRequest(PlayFab::Wrappers::PFPlayerDataManagementGetUserDataRequestWrapper<>& request);
    static HRESULT ValidateServerGetUserReadOnlyDataResponse(PFPlayerDataManagementServerGetUserDataResult* result);

    static void FillServerUpdateUserDataRequest(PlayFab::Wrappers::PFPlayerDataManagementServerUpdateUserDataRequestWrapper<>& request);
    static HRESULT ValidateServerUpdateUserDataResponse(PFPlayerDataManagementUpdateUserDataResult* result);

    static void FillServerUpdateUserInternalDataRequest(PlayFab::Wrappers::PFPlayerDataManagementUpdateUserInternalDataRequestWrapper<>& request);
    static HRESULT ValidateServerUpdateUserInternalDataResponse(PFPlayerDataManagementUpdateUserDataResult* result);

    static void FillServerUpdateUserPublisherDataRequest(PlayFab::Wrappers::PFPlayerDataManagementServerUpdateUserDataRequestWrapper<>& request);
    static HRESULT ValidateServerUpdateUserPublisherDataResponse(PFPlayerDataManagementUpdateUserDataResult* result);

    static void FillServerUpdateUserPublisherInternalDataRequest(PlayFab::Wrappers::PFPlayerDataManagementUpdateUserInternalDataRequestWrapper<>& request);
    static HRESULT ValidateServerUpdateUserPublisherInternalDataResponse(PFPlayerDataManagementUpdateUserDataResult* result);

    static void FillServerUpdateUserPublisherReadOnlyDataRequest(PlayFab::Wrappers::PFPlayerDataManagementServerUpdateUserDataRequestWrapper<>& request);
    static HRESULT ValidateServerUpdateUserPublisherReadOnlyDataResponse(PFPlayerDataManagementUpdateUserDataResult* result);

    static void FillServerUpdateUserReadOnlyDataRequest(PlayFab::Wrappers::PFPlayerDataManagementServerUpdateUserDataRequestWrapper<>& request);
    static HRESULT ValidateServerUpdateUserReadOnlyDataResponse(PFPlayerDataManagementUpdateUserDataResult* result);

    struct PlayerDataManagementTestData
    {
        ~PlayerDataManagementTestData() = default;

    };

    static PlayerDataManagementTestData testData;

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
