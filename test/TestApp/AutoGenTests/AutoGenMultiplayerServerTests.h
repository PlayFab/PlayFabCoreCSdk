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
