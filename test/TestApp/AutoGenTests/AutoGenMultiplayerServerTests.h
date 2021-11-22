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

    void TestMultiplayerServerCreateBuildAlias(TestContext& testContext);

    void TestMultiplayerServerCreateBuildWithCustomContainer(TestContext& testContext);

    void TestMultiplayerServerCreateBuildWithManagedContainer(TestContext& testContext);

    void TestMultiplayerServerCreateBuildWithProcessBasedServer(TestContext& testContext);

    void TestMultiplayerServerCreateRemoteUser(TestContext& testContext);

    void TestMultiplayerServerCreateTitleMultiplayerServersQuotaChange(TestContext& testContext);

    void TestMultiplayerServerDeleteAsset(TestContext& testContext);

    void TestMultiplayerServerDeleteBuild(TestContext& testContext);

    void TestMultiplayerServerDeleteBuildAlias(TestContext& testContext);

    void TestMultiplayerServerDeleteBuildRegion(TestContext& testContext);

    void TestMultiplayerServerDeleteCertificate(TestContext& testContext);

    void TestMultiplayerServerDeleteContainerImageRepository(TestContext& testContext);

    void TestMultiplayerServerDeleteRemoteUser(TestContext& testContext);

    void TestMultiplayerServerEnableMultiplayerServersForTitle(TestContext& testContext);

    void TestMultiplayerServerGetAssetDownloadUrl(TestContext& testContext);

    void TestMultiplayerServerGetAssetUploadUrl(TestContext& testContext);

    void TestMultiplayerServerGetBuild(TestContext& testContext);

    void TestMultiplayerServerGetBuildAlias(TestContext& testContext);

    void TestMultiplayerServerGetContainerRegistryCredentials(TestContext& testContext);

    void TestMultiplayerServerGetMultiplayerServerDetails(TestContext& testContext);

    void TestMultiplayerServerGetMultiplayerServerLogs(TestContext& testContext);

    void TestMultiplayerServerGetMultiplayerSessionLogsBySessionId(TestContext& testContext);

    void TestMultiplayerServerGetRemoteLoginEndpoint(TestContext& testContext);

    void TestMultiplayerServerGetTitleEnabledForMultiplayerServersStatus(TestContext& testContext);

    void TestMultiplayerServerGetTitleMultiplayerServersQuotaChange(TestContext& testContext);

    void TestMultiplayerServerGetTitleMultiplayerServersQuotas(TestContext& testContext);

    void TestMultiplayerServerListArchivedMultiplayerServers(TestContext& testContext);

    void TestMultiplayerServerListAssetSummaries(TestContext& testContext);

    void TestMultiplayerServerListBuildAliases(TestContext& testContext);

    void TestMultiplayerServerListBuildSummariesV2(TestContext& testContext);

    void TestMultiplayerServerListCertificateSummaries(TestContext& testContext);

    void TestMultiplayerServerListContainerImages(TestContext& testContext);

    void TestMultiplayerServerListContainerImageTags(TestContext& testContext);

    void TestMultiplayerServerListMultiplayerServers(TestContext& testContext);

    void TestMultiplayerServerListPartyQosServers(TestContext& testContext);

    void TestMultiplayerServerListQosServersForTitle(TestContext& testContext);

    void TestMultiplayerServerListTitleMultiplayerServersQuotaChanges(TestContext& testContext);

    void TestMultiplayerServerListVirtualMachineSummaries(TestContext& testContext);

    void TestMultiplayerServerRequestMultiplayerServer(TestContext& testContext);

    void TestMultiplayerServerRolloverContainerRegistryCredentials(TestContext& testContext);

    void TestMultiplayerServerShutdownMultiplayerServer(TestContext& testContext);

    void TestMultiplayerServerUntagContainerImage(TestContext& testContext);

    void TestMultiplayerServerUpdateBuildAlias(TestContext& testContext);

    void TestMultiplayerServerUpdateBuildName(TestContext& testContext);

    void TestMultiplayerServerUpdateBuildRegion(TestContext& testContext);

    void TestMultiplayerServerUpdateBuildRegions(TestContext& testContext);

    void TestMultiplayerServerUploadCertificate(TestContext& testContext);


protected:
    void AddTests();

    static void LogCreateBuildAliasRequest(PFMultiplayerServerCreateBuildAliasRequest const* request, const char* testName);
    static void FillCreateBuildAliasRequest(PlayFab::Wrappers::PFMultiplayerServerCreateBuildAliasRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerBuildAliasDetailsResponse(PFMultiplayerServerBuildAliasDetailsResponse const* result);
    static HRESULT ValidatePFMultiplayerServerBuildAliasDetailsResponse(PFMultiplayerServerBuildAliasDetailsResponse* result);

    static void LogCreateBuildWithCustomContainerRequest(PFMultiplayerServerCreateBuildWithCustomContainerRequest const* request, const char* testName);
    static void FillCreateBuildWithCustomContainerRequest(PlayFab::Wrappers::PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerCreateBuildWithCustomContainerResponse(PFMultiplayerServerCreateBuildWithCustomContainerResponse const* result);
    static HRESULT ValidatePFMultiplayerServerCreateBuildWithCustomContainerResponse(PFMultiplayerServerCreateBuildWithCustomContainerResponse* result);

    static void LogCreateBuildWithManagedContainerRequest(PFMultiplayerServerCreateBuildWithManagedContainerRequest const* request, const char* testName);
    static void FillCreateBuildWithManagedContainerRequest(PlayFab::Wrappers::PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerCreateBuildWithManagedContainerResponse(PFMultiplayerServerCreateBuildWithManagedContainerResponse const* result);
    static HRESULT ValidatePFMultiplayerServerCreateBuildWithManagedContainerResponse(PFMultiplayerServerCreateBuildWithManagedContainerResponse* result);

    static void LogCreateBuildWithProcessBasedServerRequest(PFMultiplayerServerCreateBuildWithProcessBasedServerRequest const* request, const char* testName);
    static void FillCreateBuildWithProcessBasedServerRequest(PlayFab::Wrappers::PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerCreateBuildWithProcessBasedServerResponse(PFMultiplayerServerCreateBuildWithProcessBasedServerResponse const* result);
    static HRESULT ValidatePFMultiplayerServerCreateBuildWithProcessBasedServerResponse(PFMultiplayerServerCreateBuildWithProcessBasedServerResponse* result);

    static void LogCreateRemoteUserRequest(PFMultiplayerServerCreateRemoteUserRequest const* request, const char* testName);
    static void FillCreateRemoteUserRequest(PlayFab::Wrappers::PFMultiplayerServerCreateRemoteUserRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerCreateRemoteUserResponse(PFMultiplayerServerCreateRemoteUserResponse const* result);
    static HRESULT ValidatePFMultiplayerServerCreateRemoteUserResponse(PFMultiplayerServerCreateRemoteUserResponse* result);

    static void LogCreateTitleMultiplayerServersQuotaChangeRequest(PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequest const* request, const char* testName);
    static void FillCreateTitleMultiplayerServersQuotaChangeRequest(PlayFab::Wrappers::PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse(PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse const* result);
    static HRESULT ValidatePFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse(PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse* result);

    static void LogDeleteAssetRequest(PFMultiplayerServerDeleteAssetRequest const* request, const char* testName);
    static void FillDeleteAssetRequest(PlayFab::Wrappers::PFMultiplayerServerDeleteAssetRequestWrapper<>& request);

    static void LogDeleteBuildRequest(PFMultiplayerServerDeleteBuildRequest const* request, const char* testName);
    static void FillDeleteBuildRequest(PlayFab::Wrappers::PFMultiplayerServerDeleteBuildRequestWrapper<>& request);

    static void LogDeleteBuildAliasRequest(PFMultiplayerServerDeleteBuildAliasRequest const* request, const char* testName);
    static void FillDeleteBuildAliasRequest(PlayFab::Wrappers::PFMultiplayerServerDeleteBuildAliasRequestWrapper<>& request);

    static void LogDeleteBuildRegionRequest(PFMultiplayerServerDeleteBuildRegionRequest const* request, const char* testName);
    static void FillDeleteBuildRegionRequest(PlayFab::Wrappers::PFMultiplayerServerDeleteBuildRegionRequestWrapper<>& request);

    static void LogDeleteCertificateRequest(PFMultiplayerServerDeleteCertificateRequest const* request, const char* testName);
    static void FillDeleteCertificateRequest(PlayFab::Wrappers::PFMultiplayerServerDeleteCertificateRequestWrapper<>& request);

    static void LogDeleteContainerImageRequest(PFMultiplayerServerDeleteContainerImageRequest const* request, const char* testName);
    static void FillDeleteContainerImageRequest(PlayFab::Wrappers::PFMultiplayerServerDeleteContainerImageRequestWrapper<>& request);

    static void LogDeleteRemoteUserRequest(PFMultiplayerServerDeleteRemoteUserRequest const* request, const char* testName);
    static void FillDeleteRemoteUserRequest(PlayFab::Wrappers::PFMultiplayerServerDeleteRemoteUserRequestWrapper<>& request);

    static void LogEnableMultiplayerServersForTitleRequest(PFMultiplayerServerEnableMultiplayerServersForTitleRequest const* request, const char* testName);
    static void FillEnableMultiplayerServersForTitleRequest(PlayFab::Wrappers::PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerEnableMultiplayerServersForTitleResponse(PFMultiplayerServerEnableMultiplayerServersForTitleResponse const* result);
    static HRESULT ValidatePFMultiplayerServerEnableMultiplayerServersForTitleResponse(PFMultiplayerServerEnableMultiplayerServersForTitleResponse* result);

    static void LogGetAssetDownloadUrlRequest(PFMultiplayerServerGetAssetDownloadUrlRequest const* request, const char* testName);
    static void FillGetAssetDownloadUrlRequest(PlayFab::Wrappers::PFMultiplayerServerGetAssetDownloadUrlRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerGetAssetDownloadUrlResponse(PFMultiplayerServerGetAssetDownloadUrlResponse const* result);
    static HRESULT ValidatePFMultiplayerServerGetAssetDownloadUrlResponse(PFMultiplayerServerGetAssetDownloadUrlResponse* result);

    static void LogGetAssetUploadUrlRequest(PFMultiplayerServerGetAssetUploadUrlRequest const* request, const char* testName);
    static void FillGetAssetUploadUrlRequest(PlayFab::Wrappers::PFMultiplayerServerGetAssetUploadUrlRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerGetAssetUploadUrlResponse(PFMultiplayerServerGetAssetUploadUrlResponse const* result);
    static HRESULT ValidatePFMultiplayerServerGetAssetUploadUrlResponse(PFMultiplayerServerGetAssetUploadUrlResponse* result);

    static void LogGetBuildRequest(PFMultiplayerServerGetBuildRequest const* request, const char* testName);
    static void FillGetBuildRequest(PlayFab::Wrappers::PFMultiplayerServerGetBuildRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerGetBuildResponse(PFMultiplayerServerGetBuildResponse const* result);
    static HRESULT ValidatePFMultiplayerServerGetBuildResponse(PFMultiplayerServerGetBuildResponse* result);

    static void LogGetBuildAliasRequest(PFMultiplayerServerGetBuildAliasRequest const* request, const char* testName);
    static void FillGetBuildAliasRequest(PlayFab::Wrappers::PFMultiplayerServerGetBuildAliasRequestWrapper<>& request);

    static void LogGetContainerRegistryCredentialsRequest(PFMultiplayerServerGetContainerRegistryCredentialsRequest const* request, const char* testName);
    static void FillGetContainerRegistryCredentialsRequest(PlayFab::Wrappers::PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerGetContainerRegistryCredentialsResponse(PFMultiplayerServerGetContainerRegistryCredentialsResponse const* result);
    static HRESULT ValidatePFMultiplayerServerGetContainerRegistryCredentialsResponse(PFMultiplayerServerGetContainerRegistryCredentialsResponse* result);

    static void LogGetMultiplayerServerDetailsRequest(PFMultiplayerServerGetMultiplayerServerDetailsRequest const* request, const char* testName);
    static void FillGetMultiplayerServerDetailsRequest(PlayFab::Wrappers::PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerGetMultiplayerServerDetailsResponse(PFMultiplayerServerGetMultiplayerServerDetailsResponse const* result);
    static HRESULT ValidatePFMultiplayerServerGetMultiplayerServerDetailsResponse(PFMultiplayerServerGetMultiplayerServerDetailsResponse* result);

    static void LogGetMultiplayerServerLogsRequest(PFMultiplayerServerGetMultiplayerServerLogsRequest const* request, const char* testName);
    static void FillGetMultiplayerServerLogsRequest(PlayFab::Wrappers::PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerGetMultiplayerServerLogsResponse(PFMultiplayerServerGetMultiplayerServerLogsResponse const* result);
    static HRESULT ValidatePFMultiplayerServerGetMultiplayerServerLogsResponse(PFMultiplayerServerGetMultiplayerServerLogsResponse* result);

    static void LogGetMultiplayerSessionLogsBySessionIdRequest(PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequest const* request, const char* testName);
    static void FillGetMultiplayerSessionLogsBySessionIdRequest(PlayFab::Wrappers::PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper<>& request);

    static void LogGetRemoteLoginEndpointRequest(PFMultiplayerServerGetRemoteLoginEndpointRequest const* request, const char* testName);
    static void FillGetRemoteLoginEndpointRequest(PlayFab::Wrappers::PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerGetRemoteLoginEndpointResponse(PFMultiplayerServerGetRemoteLoginEndpointResponse const* result);
    static HRESULT ValidatePFMultiplayerServerGetRemoteLoginEndpointResponse(PFMultiplayerServerGetRemoteLoginEndpointResponse* result);

    static void LogGetTitleEnabledForMultiplayerServersStatusRequest(PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequest const* request, const char* testName);
    static void FillGetTitleEnabledForMultiplayerServersStatusRequest(PlayFab::Wrappers::PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse(PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse const* result);
    static HRESULT ValidatePFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse(PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse* result);

    static void LogGetTitleMultiplayerServersQuotaChangeRequest(PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequest const* request, const char* testName);
    static void FillGetTitleMultiplayerServersQuotaChangeRequest(PlayFab::Wrappers::PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse(PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse const* result);
    static HRESULT ValidatePFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse(PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse* result);

    static void LogGetTitleMultiplayerServersQuotasRequest(PFMultiplayerServerGetTitleMultiplayerServersQuotasRequest const* request, const char* testName);
    static void FillGetTitleMultiplayerServersQuotasRequest(PlayFab::Wrappers::PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerGetTitleMultiplayerServersQuotasResponse(PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse const* result);
    static HRESULT ValidatePFMultiplayerServerGetTitleMultiplayerServersQuotasResponse(PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse* result);

    static void LogListMultiplayerServersRequest(PFMultiplayerServerListMultiplayerServersRequest const* request, const char* testName);
    static void FillListMultiplayerServersRequest(PlayFab::Wrappers::PFMultiplayerServerListMultiplayerServersRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerListMultiplayerServersResponse(PFMultiplayerServerListMultiplayerServersResponse const* result);
    static HRESULT ValidatePFMultiplayerServerListMultiplayerServersResponse(PFMultiplayerServerListMultiplayerServersResponse* result);

    static void LogListAssetSummariesRequest(PFMultiplayerServerListAssetSummariesRequest const* request, const char* testName);
    static void FillListAssetSummariesRequest(PlayFab::Wrappers::PFMultiplayerServerListAssetSummariesRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerListAssetSummariesResponse(PFMultiplayerServerListAssetSummariesResponse const* result);
    static HRESULT ValidatePFMultiplayerServerListAssetSummariesResponse(PFMultiplayerServerListAssetSummariesResponse* result);

    static void LogListBuildAliasesRequest(PFMultiplayerServerListBuildAliasesRequest const* request, const char* testName);
    static void FillListBuildAliasesRequest(PlayFab::Wrappers::PFMultiplayerServerListBuildAliasesRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerListBuildAliasesResponse(PFMultiplayerServerListBuildAliasesResponse const* result);
    static HRESULT ValidatePFMultiplayerServerListBuildAliasesResponse(PFMultiplayerServerListBuildAliasesResponse* result);

    static void LogListBuildSummariesRequest(PFMultiplayerServerListBuildSummariesRequest const* request, const char* testName);
    static void FillListBuildSummariesRequest(PlayFab::Wrappers::PFMultiplayerServerListBuildSummariesRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerListBuildSummariesResponse(PFMultiplayerServerListBuildSummariesResponse const* result);
    static HRESULT ValidatePFMultiplayerServerListBuildSummariesResponse(PFMultiplayerServerListBuildSummariesResponse* result);

    static void LogListCertificateSummariesRequest(PFMultiplayerServerListCertificateSummariesRequest const* request, const char* testName);
    static void FillListCertificateSummariesRequest(PlayFab::Wrappers::PFMultiplayerServerListCertificateSummariesRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerListCertificateSummariesResponse(PFMultiplayerServerListCertificateSummariesResponse const* result);
    static HRESULT ValidatePFMultiplayerServerListCertificateSummariesResponse(PFMultiplayerServerListCertificateSummariesResponse* result);

    static void LogListContainerImagesRequest(PFMultiplayerServerListContainerImagesRequest const* request, const char* testName);
    static void FillListContainerImagesRequest(PlayFab::Wrappers::PFMultiplayerServerListContainerImagesRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerListContainerImagesResponse(PFMultiplayerServerListContainerImagesResponse const* result);
    static HRESULT ValidatePFMultiplayerServerListContainerImagesResponse(PFMultiplayerServerListContainerImagesResponse* result);

    static void LogListContainerImageTagsRequest(PFMultiplayerServerListContainerImageTagsRequest const* request, const char* testName);
    static void FillListContainerImageTagsRequest(PlayFab::Wrappers::PFMultiplayerServerListContainerImageTagsRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerListContainerImageTagsResponse(PFMultiplayerServerListContainerImageTagsResponse const* result);
    static HRESULT ValidatePFMultiplayerServerListContainerImageTagsResponse(PFMultiplayerServerListContainerImageTagsResponse* result);


    static void LogListPartyQosServersRequest(PFMultiplayerServerListPartyQosServersRequest const* request, const char* testName);
    static void FillListPartyQosServersRequest(PlayFab::Wrappers::PFMultiplayerServerListPartyQosServersRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerListPartyQosServersResponse(PFMultiplayerServerListPartyQosServersResponse const* result);
    static HRESULT ValidatePFMultiplayerServerListPartyQosServersResponse(PFMultiplayerServerListPartyQosServersResponse* result);

    static void LogListQosServersForTitleRequest(PFMultiplayerServerListQosServersForTitleRequest const* request, const char* testName);
    static void FillListQosServersForTitleRequest(PlayFab::Wrappers::PFMultiplayerServerListQosServersForTitleRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerListQosServersForTitleResponse(PFMultiplayerServerListQosServersForTitleResponse const* result);
    static HRESULT ValidatePFMultiplayerServerListQosServersForTitleResponse(PFMultiplayerServerListQosServersForTitleResponse* result);

    static void LogListTitleMultiplayerServersQuotaChangesRequest(PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequest const* request, const char* testName);
    static void FillListTitleMultiplayerServersQuotaChangesRequest(PlayFab::Wrappers::PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse(PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse const* result);
    static HRESULT ValidatePFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse(PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse* result);

    static void LogListVirtualMachineSummariesRequest(PFMultiplayerServerListVirtualMachineSummariesRequest const* request, const char* testName);
    static void FillListVirtualMachineSummariesRequest(PlayFab::Wrappers::PFMultiplayerServerListVirtualMachineSummariesRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerListVirtualMachineSummariesResponse(PFMultiplayerServerListVirtualMachineSummariesResponse const* result);
    static HRESULT ValidatePFMultiplayerServerListVirtualMachineSummariesResponse(PFMultiplayerServerListVirtualMachineSummariesResponse* result);

    static void LogRequestMultiplayerServerRequest(PFMultiplayerServerRequestMultiplayerServerRequest const* request, const char* testName);
    static void FillRequestMultiplayerServerRequest(PlayFab::Wrappers::PFMultiplayerServerRequestMultiplayerServerRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerRequestMultiplayerServerResponse(PFMultiplayerServerRequestMultiplayerServerResponse const* result);
    static HRESULT ValidatePFMultiplayerServerRequestMultiplayerServerResponse(PFMultiplayerServerRequestMultiplayerServerResponse* result);

    static void LogRolloverContainerRegistryCredentialsRequest(PFMultiplayerServerRolloverContainerRegistryCredentialsRequest const* request, const char* testName);
    static void FillRolloverContainerRegistryCredentialsRequest(PlayFab::Wrappers::PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper<>& request);
    static HRESULT LogPFMultiplayerServerRolloverContainerRegistryCredentialsResponse(PFMultiplayerServerRolloverContainerRegistryCredentialsResponse const* result);
    static HRESULT ValidatePFMultiplayerServerRolloverContainerRegistryCredentialsResponse(PFMultiplayerServerRolloverContainerRegistryCredentialsResponse* result);

    static void LogShutdownMultiplayerServerRequest(PFMultiplayerServerShutdownMultiplayerServerRequest const* request, const char* testName);
    static void FillShutdownMultiplayerServerRequest(PlayFab::Wrappers::PFMultiplayerServerShutdownMultiplayerServerRequestWrapper<>& request);

    static void LogUntagContainerImageRequest(PFMultiplayerServerUntagContainerImageRequest const* request, const char* testName);
    static void FillUntagContainerImageRequest(PlayFab::Wrappers::PFMultiplayerServerUntagContainerImageRequestWrapper<>& request);

    static void LogUpdateBuildAliasRequest(PFMultiplayerServerUpdateBuildAliasRequest const* request, const char* testName);
    static void FillUpdateBuildAliasRequest(PlayFab::Wrappers::PFMultiplayerServerUpdateBuildAliasRequestWrapper<>& request);

    static void LogUpdateBuildNameRequest(PFMultiplayerServerUpdateBuildNameRequest const* request, const char* testName);
    static void FillUpdateBuildNameRequest(PlayFab::Wrappers::PFMultiplayerServerUpdateBuildNameRequestWrapper<>& request);

    static void LogUpdateBuildRegionRequest(PFMultiplayerServerUpdateBuildRegionRequest const* request, const char* testName);
    static void FillUpdateBuildRegionRequest(PlayFab::Wrappers::PFMultiplayerServerUpdateBuildRegionRequestWrapper<>& request);

    static void LogUpdateBuildRegionsRequest(PFMultiplayerServerUpdateBuildRegionsRequest const* request, const char* testName);
    static void FillUpdateBuildRegionsRequest(PlayFab::Wrappers::PFMultiplayerServerUpdateBuildRegionsRequestWrapper<>& request);

    static void LogUploadCertificateRequest(PFMultiplayerServerUploadCertificateRequest const* request, const char* testName);
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
