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
    void TestMultiplayerServerCreateBuildAlias(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerCreateBuildWithCustomContainer(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerCreateBuildWithManagedContainer(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerCreateBuildWithProcessBasedServer(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerCreateRemoteUser(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerCreateTitleMultiplayerServersQuotaChange(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerDeleteAsset(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerDeleteBuild(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerDeleteBuildAlias(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerDeleteBuildRegion(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerDeleteCertificate(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerDeleteContainerImageRepository(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerDeleteRemoteUser(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerEnableMultiplayerServersForTitle(TestContext& testContext);
#endif

    void TestMultiplayerServerGetAssetDownloadUrl(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerGetAssetUploadUrl(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerGetBuild(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerGetBuildAlias(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerGetContainerRegistryCredentials(TestContext& testContext);
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
    void TestMultiplayerServerGetTitleEnabledForMultiplayerServersStatus(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerGetTitleMultiplayerServersQuotaChange(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerGetTitleMultiplayerServersQuotas(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerListArchivedMultiplayerServers(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerListAssetSummaries(TestContext& testContext);
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
    void TestMultiplayerServerListContainerImages(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerListContainerImageTags(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerListMultiplayerServers(TestContext& testContext);
#endif

    void TestMultiplayerServerListPartyQosServers(TestContext& testContext);

    void TestMultiplayerServerListQosServersForTitle(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerListTitleMultiplayerServersQuotaChanges(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerListVirtualMachineSummaries(TestContext& testContext);
#endif

    void TestMultiplayerServerRequestMultiplayerServer(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerRolloverContainerRegistryCredentials(TestContext& testContext);
#endif

    void TestMultiplayerServerShutdownMultiplayerServer(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerUntagContainerImage(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerUpdateBuildAlias(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerUpdateBuildName(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerUpdateBuildRegion(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerUpdateBuildRegions(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestMultiplayerServerUploadCertificate(TestContext& testContext);
#endif


protected:
    void AddTests();

    static void LogCreateBuildAliasRequest(PFMultiplayerServerCreateBuildAliasRequest const* request, const char* testName);
    static HRESULT LogBuildAliasDetailsResponse(PFMultiplayerServerBuildAliasDetailsResponse const* result);
    static void LogCreateBuildWithCustomContainerRequest(PFMultiplayerServerCreateBuildWithCustomContainerRequest const* request, const char* testName);
    static HRESULT LogCreateBuildWithCustomContainerResponse(PFMultiplayerServerCreateBuildWithCustomContainerResponse const* result);
    static void LogCreateBuildWithManagedContainerRequest(PFMultiplayerServerCreateBuildWithManagedContainerRequest const* request, const char* testName);
    static HRESULT LogCreateBuildWithManagedContainerResponse(PFMultiplayerServerCreateBuildWithManagedContainerResponse const* result);
    static void LogCreateBuildWithProcessBasedServerRequest(PFMultiplayerServerCreateBuildWithProcessBasedServerRequest const* request, const char* testName);
    static HRESULT LogCreateBuildWithProcessBasedServerResponse(PFMultiplayerServerCreateBuildWithProcessBasedServerResponse const* result);
    static void LogCreateRemoteUserRequest(PFMultiplayerServerCreateRemoteUserRequest const* request, const char* testName);
    static HRESULT LogCreateRemoteUserResponse(PFMultiplayerServerCreateRemoteUserResponse const* result);
    static void LogCreateTitleMultiplayerServersQuotaChangeRequest(PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequest const* request, const char* testName);
    static HRESULT LogCreateTitleMultiplayerServersQuotaChangeResponse(PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse const* result);
    static void LogDeleteAssetRequest(PFMultiplayerServerDeleteAssetRequest const* request, const char* testName);
    static void LogDeleteBuildRequest(PFMultiplayerServerDeleteBuildRequest const* request, const char* testName);
    static void LogDeleteBuildAliasRequest(PFMultiplayerServerDeleteBuildAliasRequest const* request, const char* testName);
    static void LogDeleteBuildRegionRequest(PFMultiplayerServerDeleteBuildRegionRequest const* request, const char* testName);
    static void LogDeleteCertificateRequest(PFMultiplayerServerDeleteCertificateRequest const* request, const char* testName);
    static void LogDeleteContainerImageRequest(PFMultiplayerServerDeleteContainerImageRequest const* request, const char* testName);
    static void LogDeleteRemoteUserRequest(PFMultiplayerServerDeleteRemoteUserRequest const* request, const char* testName);
    static void LogEnableMultiplayerServersForTitleRequest(PFMultiplayerServerEnableMultiplayerServersForTitleRequest const* request, const char* testName);
    static HRESULT LogEnableMultiplayerServersForTitleResponse(PFMultiplayerServerEnableMultiplayerServersForTitleResponse const* result);
    static void LogGetAssetDownloadUrlRequest(PFMultiplayerServerGetAssetDownloadUrlRequest const* request, const char* testName);
    static HRESULT LogGetAssetDownloadUrlResponse(PFMultiplayerServerGetAssetDownloadUrlResponse const* result);
    static void LogGetAssetUploadUrlRequest(PFMultiplayerServerGetAssetUploadUrlRequest const* request, const char* testName);
    static HRESULT LogGetAssetUploadUrlResponse(PFMultiplayerServerGetAssetUploadUrlResponse const* result);
    static void LogGetBuildRequest(PFMultiplayerServerGetBuildRequest const* request, const char* testName);
    static HRESULT LogGetBuildResponse(PFMultiplayerServerGetBuildResponse const* result);
    static void LogGetBuildAliasRequest(PFMultiplayerServerGetBuildAliasRequest const* request, const char* testName);
    static void LogGetContainerRegistryCredentialsRequest(PFMultiplayerServerGetContainerRegistryCredentialsRequest const* request, const char* testName);
    static HRESULT LogGetContainerRegistryCredentialsResponse(PFMultiplayerServerGetContainerRegistryCredentialsResponse const* result);
    static void LogGetMultiplayerServerDetailsRequest(PFMultiplayerServerGetMultiplayerServerDetailsRequest const* request, const char* testName);
    static HRESULT LogGetMultiplayerServerDetailsResponse(PFMultiplayerServerGetMultiplayerServerDetailsResponse const* result);
    static void LogGetMultiplayerServerLogsRequest(PFMultiplayerServerGetMultiplayerServerLogsRequest const* request, const char* testName);
    static HRESULT LogGetMultiplayerServerLogsResponse(PFMultiplayerServerGetMultiplayerServerLogsResponse const* result);
    static void LogGetMultiplayerSessionLogsBySessionIdRequest(PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequest const* request, const char* testName);
    static void LogGetRemoteLoginEndpointRequest(PFMultiplayerServerGetRemoteLoginEndpointRequest const* request, const char* testName);
    static HRESULT LogGetRemoteLoginEndpointResponse(PFMultiplayerServerGetRemoteLoginEndpointResponse const* result);
    static void LogGetTitleEnabledForMultiplayerServersStatusRequest(PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequest const* request, const char* testName);
    static HRESULT LogGetTitleEnabledForMultiplayerServersStatusResponse(PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse const* result);
    static void LogGetTitleMultiplayerServersQuotaChangeRequest(PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequest const* request, const char* testName);
    static HRESULT LogGetTitleMultiplayerServersQuotaChangeResponse(PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse const* result);
    static void LogGetTitleMultiplayerServersQuotasRequest(PFMultiplayerServerGetTitleMultiplayerServersQuotasRequest const* request, const char* testName);
    static HRESULT LogGetTitleMultiplayerServersQuotasResponse(PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse const* result);
    static void LogListMultiplayerServersRequest(PFMultiplayerServerListMultiplayerServersRequest const* request, const char* testName);
    static HRESULT LogListMultiplayerServersResponse(PFMultiplayerServerListMultiplayerServersResponse const* result);
    static void LogListAssetSummariesRequest(PFMultiplayerServerListAssetSummariesRequest const* request, const char* testName);
    static HRESULT LogListAssetSummariesResponse(PFMultiplayerServerListAssetSummariesResponse const* result);
    static void LogListBuildAliasesRequest(PFMultiplayerServerListBuildAliasesRequest const* request, const char* testName);
    static HRESULT LogListBuildAliasesResponse(PFMultiplayerServerListBuildAliasesResponse const* result);
    static void LogListBuildSummariesRequest(PFMultiplayerServerListBuildSummariesRequest const* request, const char* testName);
    static HRESULT LogListBuildSummariesResponse(PFMultiplayerServerListBuildSummariesResponse const* result);
    static void LogListCertificateSummariesRequest(PFMultiplayerServerListCertificateSummariesRequest const* request, const char* testName);
    static HRESULT LogListCertificateSummariesResponse(PFMultiplayerServerListCertificateSummariesResponse const* result);
    static void LogListContainerImagesRequest(PFMultiplayerServerListContainerImagesRequest const* request, const char* testName);
    static HRESULT LogListContainerImagesResponse(PFMultiplayerServerListContainerImagesResponse const* result);
    static void LogListContainerImageTagsRequest(PFMultiplayerServerListContainerImageTagsRequest const* request, const char* testName);
    static HRESULT LogListContainerImageTagsResponse(PFMultiplayerServerListContainerImageTagsResponse const* result);
    static void LogListPartyQosServersRequest(PFMultiplayerServerListPartyQosServersRequest const* request, const char* testName);
    static HRESULT LogListPartyQosServersResponse(PFMultiplayerServerListPartyQosServersResponse const* result);
    static void LogListQosServersForTitleRequest(PFMultiplayerServerListQosServersForTitleRequest const* request, const char* testName);
    static HRESULT LogListQosServersForTitleResponse(PFMultiplayerServerListQosServersForTitleResponse const* result);
    static void LogListTitleMultiplayerServersQuotaChangesRequest(PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequest const* request, const char* testName);
    static HRESULT LogListTitleMultiplayerServersQuotaChangesResponse(PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse const* result);
    static void LogListVirtualMachineSummariesRequest(PFMultiplayerServerListVirtualMachineSummariesRequest const* request, const char* testName);
    static HRESULT LogListVirtualMachineSummariesResponse(PFMultiplayerServerListVirtualMachineSummariesResponse const* result);
    static void LogRequestMultiplayerServerRequest(PFMultiplayerServerRequestMultiplayerServerRequest const* request, const char* testName);
    static HRESULT LogRequestMultiplayerServerResponse(PFMultiplayerServerRequestMultiplayerServerResponse const* result);
    static void LogRolloverContainerRegistryCredentialsRequest(PFMultiplayerServerRolloverContainerRegistryCredentialsRequest const* request, const char* testName);
    static HRESULT LogRolloverContainerRegistryCredentialsResponse(PFMultiplayerServerRolloverContainerRegistryCredentialsResponse const* result);
    static void LogShutdownMultiplayerServerRequest(PFMultiplayerServerShutdownMultiplayerServerRequest const* request, const char* testName);
    static void LogUntagContainerImageRequest(PFMultiplayerServerUntagContainerImageRequest const* request, const char* testName);
    static void LogUpdateBuildAliasRequest(PFMultiplayerServerUpdateBuildAliasRequest const* request, const char* testName);
    static void LogUpdateBuildNameRequest(PFMultiplayerServerUpdateBuildNameRequest const* request, const char* testName);
    static void LogUpdateBuildRegionRequest(PFMultiplayerServerUpdateBuildRegionRequest const* request, const char* testName);
    static void LogUpdateBuildRegionsRequest(PFMultiplayerServerUpdateBuildRegionsRequest const* request, const char* testName);
    static void LogUploadCertificateRequest(PFMultiplayerServerUploadCertificateRequest const* request, const char* testName);

    void FillCreateBuildAliasRequest(PlayFab::Wrappers::PFMultiplayerServerCreateBuildAliasRequestWrapper<>& request);
    static HRESULT ValidateCreateBuildAliasResponse(PFMultiplayerServerBuildAliasDetailsResponse* result);

    void FillCreateBuildWithCustomContainerRequest(PlayFab::Wrappers::PFMultiplayerServerCreateBuildWithCustomContainerRequestWrapper<>& request);
    static HRESULT ValidateCreateBuildWithCustomContainerResponse(PFMultiplayerServerCreateBuildWithCustomContainerResponse* result);

    void FillCreateBuildWithManagedContainerRequest(PlayFab::Wrappers::PFMultiplayerServerCreateBuildWithManagedContainerRequestWrapper<>& request);
    static HRESULT ValidateCreateBuildWithManagedContainerResponse(PFMultiplayerServerCreateBuildWithManagedContainerResponse* result);

    void FillCreateBuildWithProcessBasedServerRequest(PlayFab::Wrappers::PFMultiplayerServerCreateBuildWithProcessBasedServerRequestWrapper<>& request);
    static HRESULT ValidateCreateBuildWithProcessBasedServerResponse(PFMultiplayerServerCreateBuildWithProcessBasedServerResponse* result);

    void FillCreateRemoteUserRequest(PlayFab::Wrappers::PFMultiplayerServerCreateRemoteUserRequestWrapper<>& request);
    static HRESULT ValidateCreateRemoteUserResponse(PFMultiplayerServerCreateRemoteUserResponse* result);

    void FillCreateTitleMultiplayerServersQuotaChangeRequest(PlayFab::Wrappers::PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequestWrapper<>& request);
    static HRESULT ValidateCreateTitleMultiplayerServersQuotaChangeResponse(PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse* result);

    void FillDeleteAssetRequest(PlayFab::Wrappers::PFMultiplayerServerDeleteAssetRequestWrapper<>& request);

    void FillDeleteBuildRequest(PlayFab::Wrappers::PFMultiplayerServerDeleteBuildRequestWrapper<>& request);

    void FillDeleteBuildAliasRequest(PlayFab::Wrappers::PFMultiplayerServerDeleteBuildAliasRequestWrapper<>& request);

    void FillDeleteBuildRegionRequest(PlayFab::Wrappers::PFMultiplayerServerDeleteBuildRegionRequestWrapper<>& request);

    void FillDeleteCertificateRequest(PlayFab::Wrappers::PFMultiplayerServerDeleteCertificateRequestWrapper<>& request);

    void FillDeleteContainerImageRepositoryRequest(PlayFab::Wrappers::PFMultiplayerServerDeleteContainerImageRequestWrapper<>& request);

    void FillDeleteRemoteUserRequest(PlayFab::Wrappers::PFMultiplayerServerDeleteRemoteUserRequestWrapper<>& request);

    void FillEnableMultiplayerServersForTitleRequest(PlayFab::Wrappers::PFMultiplayerServerEnableMultiplayerServersForTitleRequestWrapper<>& request);
    static HRESULT ValidateEnableMultiplayerServersForTitleResponse(PFMultiplayerServerEnableMultiplayerServersForTitleResponse* result);

    void FillGetAssetDownloadUrlRequest(PlayFab::Wrappers::PFMultiplayerServerGetAssetDownloadUrlRequestWrapper<>& request);
    static HRESULT ValidateGetAssetDownloadUrlResponse(PFMultiplayerServerGetAssetDownloadUrlResponse* result);

    void FillGetAssetUploadUrlRequest(PlayFab::Wrappers::PFMultiplayerServerGetAssetUploadUrlRequestWrapper<>& request);
    static HRESULT ValidateGetAssetUploadUrlResponse(PFMultiplayerServerGetAssetUploadUrlResponse* result);

    void FillGetBuildRequest(PlayFab::Wrappers::PFMultiplayerServerGetBuildRequestWrapper<>& request);
    static HRESULT ValidateGetBuildResponse(PFMultiplayerServerGetBuildResponse* result);

    void FillGetBuildAliasRequest(PlayFab::Wrappers::PFMultiplayerServerGetBuildAliasRequestWrapper<>& request);
    static HRESULT ValidateGetBuildAliasResponse(PFMultiplayerServerBuildAliasDetailsResponse* result);

    void FillGetContainerRegistryCredentialsRequest(PlayFab::Wrappers::PFMultiplayerServerGetContainerRegistryCredentialsRequestWrapper<>& request);
    static HRESULT ValidateGetContainerRegistryCredentialsResponse(PFMultiplayerServerGetContainerRegistryCredentialsResponse* result);

    void FillGetMultiplayerServerDetailsRequest(PlayFab::Wrappers::PFMultiplayerServerGetMultiplayerServerDetailsRequestWrapper<>& request);
    static HRESULT ValidateGetMultiplayerServerDetailsResponse(PFMultiplayerServerGetMultiplayerServerDetailsResponse* result);

    void FillGetMultiplayerServerLogsRequest(PlayFab::Wrappers::PFMultiplayerServerGetMultiplayerServerLogsRequestWrapper<>& request);
    static HRESULT ValidateGetMultiplayerServerLogsResponse(PFMultiplayerServerGetMultiplayerServerLogsResponse* result);

    void FillGetMultiplayerSessionLogsBySessionIdRequest(PlayFab::Wrappers::PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequestWrapper<>& request);
    static HRESULT ValidateGetMultiplayerSessionLogsBySessionIdResponse(PFMultiplayerServerGetMultiplayerServerLogsResponse* result);

    void FillGetRemoteLoginEndpointRequest(PlayFab::Wrappers::PFMultiplayerServerGetRemoteLoginEndpointRequestWrapper<>& request);
    static HRESULT ValidateGetRemoteLoginEndpointResponse(PFMultiplayerServerGetRemoteLoginEndpointResponse* result);

    void FillGetTitleEnabledForMultiplayerServersStatusRequest(PlayFab::Wrappers::PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequestWrapper<>& request);
    static HRESULT ValidateGetTitleEnabledForMultiplayerServersStatusResponse(PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse* result);

    void FillGetTitleMultiplayerServersQuotaChangeRequest(PlayFab::Wrappers::PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequestWrapper<>& request);
    static HRESULT ValidateGetTitleMultiplayerServersQuotaChangeResponse(PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse* result);

    void FillGetTitleMultiplayerServersQuotasRequest(PlayFab::Wrappers::PFMultiplayerServerGetTitleMultiplayerServersQuotasRequestWrapper<>& request);
    static HRESULT ValidateGetTitleMultiplayerServersQuotasResponse(PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse* result);

    void FillListArchivedMultiplayerServersRequest(PlayFab::Wrappers::PFMultiplayerServerListMultiplayerServersRequestWrapper<>& request);
    static HRESULT ValidateListArchivedMultiplayerServersResponse(PFMultiplayerServerListMultiplayerServersResponse* result);

    void FillListAssetSummariesRequest(PlayFab::Wrappers::PFMultiplayerServerListAssetSummariesRequestWrapper<>& request);
    static HRESULT ValidateListAssetSummariesResponse(PFMultiplayerServerListAssetSummariesResponse* result);

    void FillListBuildAliasesRequest(PlayFab::Wrappers::PFMultiplayerServerListBuildAliasesRequestWrapper<>& request);
    static HRESULT ValidateListBuildAliasesResponse(PFMultiplayerServerListBuildAliasesResponse* result);

    void FillListBuildSummariesV2Request(PlayFab::Wrappers::PFMultiplayerServerListBuildSummariesRequestWrapper<>& request);
    static HRESULT ValidateListBuildSummariesV2Response(PFMultiplayerServerListBuildSummariesResponse* result);

    void FillListCertificateSummariesRequest(PlayFab::Wrappers::PFMultiplayerServerListCertificateSummariesRequestWrapper<>& request);
    static HRESULT ValidateListCertificateSummariesResponse(PFMultiplayerServerListCertificateSummariesResponse* result);

    void FillListContainerImagesRequest(PlayFab::Wrappers::PFMultiplayerServerListContainerImagesRequestWrapper<>& request);
    static HRESULT ValidateListContainerImagesResponse(PFMultiplayerServerListContainerImagesResponse* result);

    void FillListContainerImageTagsRequest(PlayFab::Wrappers::PFMultiplayerServerListContainerImageTagsRequestWrapper<>& request);
    static HRESULT ValidateListContainerImageTagsResponse(PFMultiplayerServerListContainerImageTagsResponse* result);

    void FillListMultiplayerServersRequest(PlayFab::Wrappers::PFMultiplayerServerListMultiplayerServersRequestWrapper<>& request);
    static HRESULT ValidateListMultiplayerServersResponse(PFMultiplayerServerListMultiplayerServersResponse* result);

    void FillListPartyQosServersRequest(PlayFab::Wrappers::PFMultiplayerServerListPartyQosServersRequestWrapper<>& request);
    static HRESULT ValidateListPartyQosServersResponse(PFMultiplayerServerListPartyQosServersResponse* result);

    void FillListQosServersForTitleRequest(PlayFab::Wrappers::PFMultiplayerServerListQosServersForTitleRequestWrapper<>& request);
    static HRESULT ValidateListQosServersForTitleResponse(PFMultiplayerServerListQosServersForTitleResponse* result);

    void FillListTitleMultiplayerServersQuotaChangesRequest(PlayFab::Wrappers::PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequestWrapper<>& request);
    static HRESULT ValidateListTitleMultiplayerServersQuotaChangesResponse(PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse* result);

    void FillListVirtualMachineSummariesRequest(PlayFab::Wrappers::PFMultiplayerServerListVirtualMachineSummariesRequestWrapper<>& request);
    static HRESULT ValidateListVirtualMachineSummariesResponse(PFMultiplayerServerListVirtualMachineSummariesResponse* result);

    void FillRequestMultiplayerServerRequest(PlayFab::Wrappers::PFMultiplayerServerRequestMultiplayerServerRequestWrapper<>& request);
    static HRESULT ValidateRequestMultiplayerServerResponse(PFMultiplayerServerRequestMultiplayerServerResponse* result);

    void FillRolloverContainerRegistryCredentialsRequest(PlayFab::Wrappers::PFMultiplayerServerRolloverContainerRegistryCredentialsRequestWrapper<>& request);
    static HRESULT ValidateRolloverContainerRegistryCredentialsResponse(PFMultiplayerServerRolloverContainerRegistryCredentialsResponse* result);

    void FillShutdownMultiplayerServerRequest(PlayFab::Wrappers::PFMultiplayerServerShutdownMultiplayerServerRequestWrapper<>& request);

    void FillUntagContainerImageRequest(PlayFab::Wrappers::PFMultiplayerServerUntagContainerImageRequestWrapper<>& request);

    void FillUpdateBuildAliasRequest(PlayFab::Wrappers::PFMultiplayerServerUpdateBuildAliasRequestWrapper<>& request);
    static HRESULT ValidateUpdateBuildAliasResponse(PFMultiplayerServerBuildAliasDetailsResponse* result);

    void FillUpdateBuildNameRequest(PlayFab::Wrappers::PFMultiplayerServerUpdateBuildNameRequestWrapper<>& request);

    void FillUpdateBuildRegionRequest(PlayFab::Wrappers::PFMultiplayerServerUpdateBuildRegionRequestWrapper<>& request);

    void FillUpdateBuildRegionsRequest(PlayFab::Wrappers::PFMultiplayerServerUpdateBuildRegionsRequestWrapper<>& request);

    void FillUploadCertificateRequest(PlayFab::Wrappers::PFMultiplayerServerUploadCertificateRequestWrapper<>& request);

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
