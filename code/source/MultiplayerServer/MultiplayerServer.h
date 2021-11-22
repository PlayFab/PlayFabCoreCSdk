#pragma once

#include "MultiplayerServerDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace MultiplayerServer
{

class MultiplayerServerAPI
{
public:
    MultiplayerServerAPI() = delete;
    MultiplayerServerAPI(const MultiplayerServerAPI& source) = delete;
    MultiplayerServerAPI& operator=(const MultiplayerServerAPI& source) = delete;
    ~MultiplayerServerAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<BuildAliasDetailsResponse> CreateBuildAlias(SharedPtr<Entity> entity, const CreateBuildAliasRequest& request, const TaskQueue& queue);
    static AsyncOp<CreateBuildWithCustomContainerResponse> CreateBuildWithCustomContainer(SharedPtr<Entity> entity, const CreateBuildWithCustomContainerRequest& request, const TaskQueue& queue);
    static AsyncOp<CreateBuildWithManagedContainerResponse> CreateBuildWithManagedContainer(SharedPtr<Entity> entity, const CreateBuildWithManagedContainerRequest& request, const TaskQueue& queue);
    static AsyncOp<CreateBuildWithProcessBasedServerResponse> CreateBuildWithProcessBasedServer(SharedPtr<Entity> entity, const CreateBuildWithProcessBasedServerRequest& request, const TaskQueue& queue);
    static AsyncOp<CreateRemoteUserResponse> CreateRemoteUser(SharedPtr<Entity> entity, const CreateRemoteUserRequest& request, const TaskQueue& queue);
    static AsyncOp<CreateTitleMultiplayerServersQuotaChangeResponse> CreateTitleMultiplayerServersQuotaChange(SharedPtr<Entity> entity, const CreateTitleMultiplayerServersQuotaChangeRequest& request, const TaskQueue& queue);
    static AsyncOp<void> DeleteAsset(SharedPtr<Entity> entity, const DeleteAssetRequest& request, const TaskQueue& queue);
    static AsyncOp<void> DeleteBuild(SharedPtr<Entity> entity, const DeleteBuildRequest& request, const TaskQueue& queue);
    static AsyncOp<void> DeleteBuildAlias(SharedPtr<Entity> entity, const DeleteBuildAliasRequest& request, const TaskQueue& queue);
    static AsyncOp<void> DeleteBuildRegion(SharedPtr<Entity> entity, const DeleteBuildRegionRequest& request, const TaskQueue& queue);
    static AsyncOp<void> DeleteCertificate(SharedPtr<Entity> entity, const DeleteCertificateRequest& request, const TaskQueue& queue);
    static AsyncOp<void> DeleteContainerImageRepository(SharedPtr<Entity> entity, const DeleteContainerImageRequest& request, const TaskQueue& queue);
    static AsyncOp<void> DeleteRemoteUser(SharedPtr<Entity> entity, const DeleteRemoteUserRequest& request, const TaskQueue& queue);
    static AsyncOp<EnableMultiplayerServersForTitleResponse> EnableMultiplayerServersForTitle(SharedPtr<Entity> entity, const EnableMultiplayerServersForTitleRequest& request, const TaskQueue& queue);
    static AsyncOp<GetAssetDownloadUrlResponse> GetAssetDownloadUrl(SharedPtr<Entity> entity, const GetAssetDownloadUrlRequest& request, const TaskQueue& queue);
    static AsyncOp<GetAssetUploadUrlResponse> GetAssetUploadUrl(SharedPtr<Entity> entity, const GetAssetUploadUrlRequest& request, const TaskQueue& queue);
    static AsyncOp<GetBuildResponse> GetBuild(SharedPtr<Entity> entity, const GetBuildRequest& request, const TaskQueue& queue);
    static AsyncOp<BuildAliasDetailsResponse> GetBuildAlias(SharedPtr<Entity> entity, const GetBuildAliasRequest& request, const TaskQueue& queue);
    static AsyncOp<GetContainerRegistryCredentialsResponse> GetContainerRegistryCredentials(SharedPtr<Entity> entity, const GetContainerRegistryCredentialsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetMultiplayerServerDetailsResponse> GetMultiplayerServerDetails(SharedPtr<Entity> entity, const GetMultiplayerServerDetailsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetMultiplayerServerLogsResponse> GetMultiplayerServerLogs(SharedPtr<Entity> entity, const GetMultiplayerServerLogsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetMultiplayerServerLogsResponse> GetMultiplayerSessionLogsBySessionId(SharedPtr<Entity> entity, const GetMultiplayerSessionLogsBySessionIdRequest& request, const TaskQueue& queue);
    static AsyncOp<GetRemoteLoginEndpointResponse> GetRemoteLoginEndpoint(SharedPtr<Entity> entity, const GetRemoteLoginEndpointRequest& request, const TaskQueue& queue);
    static AsyncOp<GetTitleEnabledForMultiplayerServersStatusResponse> GetTitleEnabledForMultiplayerServersStatus(SharedPtr<Entity> entity, const GetTitleEnabledForMultiplayerServersStatusRequest& request, const TaskQueue& queue);
    static AsyncOp<GetTitleMultiplayerServersQuotaChangeResponse> GetTitleMultiplayerServersQuotaChange(SharedPtr<Entity> entity, const GetTitleMultiplayerServersQuotaChangeRequest& request, const TaskQueue& queue);
    static AsyncOp<GetTitleMultiplayerServersQuotasResponse> GetTitleMultiplayerServersQuotas(SharedPtr<Entity> entity, const GetTitleMultiplayerServersQuotasRequest& request, const TaskQueue& queue);
    static AsyncOp<ListMultiplayerServersResponse> ListArchivedMultiplayerServers(SharedPtr<Entity> entity, const ListMultiplayerServersRequest& request, const TaskQueue& queue);
    static AsyncOp<ListAssetSummariesResponse> ListAssetSummaries(SharedPtr<Entity> entity, const ListAssetSummariesRequest& request, const TaskQueue& queue);
    static AsyncOp<ListBuildAliasesResponse> ListBuildAliases(SharedPtr<Entity> entity, const ListBuildAliasesRequest& request, const TaskQueue& queue);
    static AsyncOp<ListBuildSummariesResponse> ListBuildSummariesV2(SharedPtr<Entity> entity, const ListBuildSummariesRequest& request, const TaskQueue& queue);
    static AsyncOp<ListCertificateSummariesResponse> ListCertificateSummaries(SharedPtr<Entity> entity, const ListCertificateSummariesRequest& request, const TaskQueue& queue);
    static AsyncOp<ListContainerImagesResponse> ListContainerImages(SharedPtr<Entity> entity, const ListContainerImagesRequest& request, const TaskQueue& queue);
    static AsyncOp<ListContainerImageTagsResponse> ListContainerImageTags(SharedPtr<Entity> entity, const ListContainerImageTagsRequest& request, const TaskQueue& queue);
    static AsyncOp<ListMultiplayerServersResponse> ListMultiplayerServers(SharedPtr<Entity> entity, const ListMultiplayerServersRequest& request, const TaskQueue& queue);
    static AsyncOp<ListPartyQosServersResponse> ListPartyQosServers(SharedPtr<GlobalState const> state, const ListPartyQosServersRequest& request, const TaskQueue& queue);
    static AsyncOp<ListQosServersForTitleResponse> ListQosServersForTitle(SharedPtr<Entity> entity, const ListQosServersForTitleRequest& request, const TaskQueue& queue);
    static AsyncOp<ListTitleMultiplayerServersQuotaChangesResponse> ListTitleMultiplayerServersQuotaChanges(SharedPtr<Entity> entity, const ListTitleMultiplayerServersQuotaChangesRequest& request, const TaskQueue& queue);
    static AsyncOp<ListVirtualMachineSummariesResponse> ListVirtualMachineSummaries(SharedPtr<Entity> entity, const ListVirtualMachineSummariesRequest& request, const TaskQueue& queue);
    static AsyncOp<RequestMultiplayerServerResponse> RequestMultiplayerServer(SharedPtr<Entity> entity, const RequestMultiplayerServerRequest& request, const TaskQueue& queue);
    static AsyncOp<RolloverContainerRegistryCredentialsResponse> RolloverContainerRegistryCredentials(SharedPtr<Entity> entity, const RolloverContainerRegistryCredentialsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ShutdownMultiplayerServer(SharedPtr<Entity> entity, const ShutdownMultiplayerServerRequest& request, const TaskQueue& queue);
    static AsyncOp<void> UntagContainerImage(SharedPtr<Entity> entity, const UntagContainerImageRequest& request, const TaskQueue& queue);
    static AsyncOp<BuildAliasDetailsResponse> UpdateBuildAlias(SharedPtr<Entity> entity, const UpdateBuildAliasRequest& request, const TaskQueue& queue);
    static AsyncOp<void> UpdateBuildName(SharedPtr<Entity> entity, const UpdateBuildNameRequest& request, const TaskQueue& queue);
    static AsyncOp<void> UpdateBuildRegion(SharedPtr<Entity> entity, const UpdateBuildRegionRequest& request, const TaskQueue& queue);
    static AsyncOp<void> UpdateBuildRegions(SharedPtr<Entity> entity, const UpdateBuildRegionsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> UploadCertificate(SharedPtr<Entity> entity, const UploadCertificateRequest& request, const TaskQueue& queue);
};

} // namespace MultiplayerServer
} // namespace PlayFab
