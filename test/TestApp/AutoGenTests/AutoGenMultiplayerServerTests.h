#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFMultiplayerServerDataModelWrappers.h>
#include "AutoGenMultiplayerServerResultHolders.h"

namespace PlayFabUnit
{

class AutoGenMultiplayerServerTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerCreateRemoteUser(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerDeleteCertificate(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerDeleteRemoteUser(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerGetMultiplayerServerDetails(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerGetMultiplayerServerLogs(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerGetMultiplayerSessionLogsBySessionId(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerGetRemoteLoginEndpoint(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerListArchivedMultiplayerServers(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerListBuildAliases(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerListBuildSummariesV2(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerListCertificateSummaries(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerListMultiplayerServers(TestContext& testContext);
#endif

    void TestMultiplayerServerListPartyQosServers(TestContext& testContext);

    void TestMultiplayerServerListQosServersForTitle(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerListVirtualMachineSummaries(TestContext& testContext);
#endif

    void TestMultiplayerServerRequestMultiplayerServer(TestContext& testContext);

    void TestMultiplayerServerShutdownMultiplayerServer(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerUploadCertificate(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogCreateRemoteUserRequest(PFMultiplayerServerCreateRemoteUserRequest const* request, const char* testName);
    static HRESULT LogCreateRemoteUserResponse(PFMultiplayerServerCreateRemoteUserResponse const* result);
    static void LogDeleteCertificateRequest(PFMultiplayerServerDeleteCertificateRequest const* request, const char* testName);
    static void LogDeleteRemoteUserRequest(PFMultiplayerServerDeleteRemoteUserRequest const* request, const char* testName);
    static void LogGetMultiplayerServerDetailsRequest(PFMultiplayerServerGetMultiplayerServerDetailsRequest const* request, const char* testName);
    static HRESULT LogGetMultiplayerServerDetailsResponse(PFMultiplayerServerGetMultiplayerServerDetailsResponse const* result);
    static void LogGetMultiplayerServerLogsRequest(PFMultiplayerServerGetMultiplayerServerLogsRequest const* request, const char* testName);
    static HRESULT LogGetMultiplayerServerLogsResponse(PFMultiplayerServerGetMultiplayerServerLogsResponse const* result);
    static void LogGetMultiplayerSessionLogsBySessionIdRequest(PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequest const* request, const char* testName);
    static void LogGetRemoteLoginEndpointRequest(PFMultiplayerServerGetRemoteLoginEndpointRequest const* request, const char* testName);
    static HRESULT LogGetRemoteLoginEndpointResponse(PFMultiplayerServerGetRemoteLoginEndpointResponse const* result);
    static void LogListMultiplayerServersRequest(PFMultiplayerServerListMultiplayerServersRequest const* request, const char* testName);
    static HRESULT LogListMultiplayerServersResponse(PFMultiplayerServerListMultiplayerServersResponse const* result);
    static void LogListBuildAliasesRequest(PFMultiplayerServerListBuildAliasesRequest const* request, const char* testName);
    static HRESULT LogListBuildAliasesResponse(PFMultiplayerServerListBuildAliasesResponse const* result);
    static void LogListBuildSummariesRequest(PFMultiplayerServerListBuildSummariesRequest const* request, const char* testName);
    static HRESULT LogListBuildSummariesResponse(PFMultiplayerServerListBuildSummariesResponse const* result);
    static void LogListCertificateSummariesRequest(PFMultiplayerServerListCertificateSummariesRequest const* request, const char* testName);
    static HRESULT LogListCertificateSummariesResponse(PFMultiplayerServerListCertificateSummariesResponse const* result);
    static void LogListPartyQosServersRequest(PFMultiplayerServerListPartyQosServersRequest const* request, const char* testName);
    static HRESULT LogListPartyQosServersResponse(PFMultiplayerServerListPartyQosServersResponse const* result);
    static void LogListQosServersForTitleRequest(PFMultiplayerServerListQosServersForTitleRequest const* request, const char* testName);
    static HRESULT LogListQosServersForTitleResponse(PFMultiplayerServerListQosServersForTitleResponse const* result);
    static void LogListVirtualMachineSummariesRequest(PFMultiplayerServerListVirtualMachineSummariesRequest const* request, const char* testName);
    static HRESULT LogListVirtualMachineSummariesResponse(PFMultiplayerServerListVirtualMachineSummariesResponse const* result);
    static void LogRequestMultiplayerServerRequest(PFMultiplayerServerRequestMultiplayerServerRequest const* request, const char* testName);
    static HRESULT LogRequestMultiplayerServerResponse(PFMultiplayerServerRequestMultiplayerServerResponse const* result);
    static void LogShutdownMultiplayerServerRequest(PFMultiplayerServerShutdownMultiplayerServerRequest const* request, const char* testName);
    static void LogUploadCertificateRequest(PFMultiplayerServerUploadCertificateRequest const* request, const char* testName);

    static void FillCreateRemoteUserRequest(PlayFab::Wrappers::PFMultiplayerServerCreateRemoteUserRequestWrapper<>& request);
    static HRESULT ValidateCreateRemoteUserResponse(PFMultiplayerServerCreateRemoteUserResponse* result);

    static void FillDeleteCertificateRequest(PlayFab::Wrappers::PFMultiplayerServerDeleteCertificateRequestWrapper<>& request);

    static void FillDeleteRemoteUserRequest(PlayFab::Wrappers::PFMultiplayerServerDeleteRemoteUserRequestWrapper<>& request);

    static void FillGetMultiplayerServerDetailsRequest(PlayFab::Wrappers::PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper<>& request);
    static HRESULT ValidateGetMultiplayerServerDetailsResponse(PFMultiplayerServerGetMultiplayerServerDetailsResponse* result);

    static void FillGetMultiplayerServerLogsRequest(PlayFab::Wrappers::PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper<>& request);
    static HRESULT ValidateGetMultiplayerServerLogsResponse(PFMultiplayerServerGetMultiplayerServerLogsResponse* result);

    static void FillGetMultiplayerSessionLogsBySessionIdRequest(PlayFab::Wrappers::PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper<>& request);
    static HRESULT ValidateGetMultiplayerSessionLogsBySessionIdResponse(PFMultiplayerServerGetMultiplayerServerLogsResponse* result);

    static void FillGetRemoteLoginEndpointRequest(PlayFab::Wrappers::PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper<>& request);
    static HRESULT ValidateGetRemoteLoginEndpointResponse(PFMultiplayerServerGetRemoteLoginEndpointResponse* result);

    static void FillListArchivedMultiplayerServersRequest(PlayFab::Wrappers::PFMultiplayerServerListMultiplayerServersRequestWrapper<>& request);
    static HRESULT ValidateListArchivedMultiplayerServersResponse(PFMultiplayerServerListMultiplayerServersResponse* result);

    static void FillListBuildAliasesRequest(PlayFab::Wrappers::PFMultiplayerServerListBuildAliasesRequestWrapper<>& request);
    static HRESULT ValidateListBuildAliasesResponse(PFMultiplayerServerListBuildAliasesResponse* result);

    static void FillListBuildSummariesV2Request(PlayFab::Wrappers::PFMultiplayerServerListBuildSummariesRequestWrapper<>& request);
    static HRESULT ValidateListBuildSummariesV2Response(PFMultiplayerServerListBuildSummariesResponse* result);

    static void FillListCertificateSummariesRequest(PlayFab::Wrappers::PFMultiplayerServerListCertificateSummariesRequestWrapper<>& request);
    static HRESULT ValidateListCertificateSummariesResponse(PFMultiplayerServerListCertificateSummariesResponse* result);

    static void FillListMultiplayerServersRequest(PlayFab::Wrappers::PFMultiplayerServerListMultiplayerServersRequestWrapper<>& request);
    static HRESULT ValidateListMultiplayerServersResponse(PFMultiplayerServerListMultiplayerServersResponse* result);

    static void FillListPartyQosServersRequest(PlayFab::Wrappers::PFMultiplayerServerListPartyQosServersRequestWrapper<>& request);
    static HRESULT ValidateListPartyQosServersResponse(PFMultiplayerServerListPartyQosServersResponse* result);

    static void FillListQosServersForTitleRequest(PlayFab::Wrappers::PFMultiplayerServerListQosServersForTitleRequestWrapper<>& request);
    static HRESULT ValidateListQosServersForTitleResponse(PFMultiplayerServerListQosServersForTitleResponse* result);

    static void FillListVirtualMachineSummariesRequest(PlayFab::Wrappers::PFMultiplayerServerListVirtualMachineSummariesRequestWrapper<>& request);
    static HRESULT ValidateListVirtualMachineSummariesResponse(PFMultiplayerServerListVirtualMachineSummariesResponse* result);

    static void FillRequestMultiplayerServerRequest(PlayFab::Wrappers::PFMultiplayerServerRequestMultiplayerServerRequestWrapper<>& request);
    static HRESULT ValidateRequestMultiplayerServerResponse(PFMultiplayerServerRequestMultiplayerServerResponse* result);

    static void FillShutdownMultiplayerServerRequest(PlayFab::Wrappers::PFMultiplayerServerShutdownMultiplayerServerRequestWrapper<>& request);

    static void FillUploadCertificateRequest(PlayFab::Wrappers::PFMultiplayerServerUploadCertificateRequestWrapper<>& request);

    struct MultiplayerServerTestData
    {
        ~MultiplayerServerTestData() = default;

    };

    static MultiplayerServerTestData testData;

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
