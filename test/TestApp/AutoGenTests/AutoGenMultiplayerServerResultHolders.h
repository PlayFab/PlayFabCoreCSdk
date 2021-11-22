#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct BuildAliasDetailsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<BuildAliasDetailsResponseHolder>
{
    BuildAliasDetailsResponseHolder() = default;
    BuildAliasDetailsResponseHolder(const BuildAliasDetailsResponseHolder&) = delete;
    BuildAliasDetailsResponseHolder(BuildAliasDetailsResponseHolder&&) = default;
    BuildAliasDetailsResponseHolder& operator=(const BuildAliasDetailsResponseHolder&) = delete;
    BuildAliasDetailsResponseHolder& operator=(BuildAliasDetailsResponseHolder&&) = default;
    ~BuildAliasDetailsResponseHolder() = default;

    PFMultiplayerServerBuildAliasDetailsResponse* result{ nullptr };
};

struct CreateBuildWithCustomContainerResponseHolder : public XAsyncResult, public std::enable_shared_from_this<CreateBuildWithCustomContainerResponseHolder>
{
    CreateBuildWithCustomContainerResponseHolder() = default;
    CreateBuildWithCustomContainerResponseHolder(const CreateBuildWithCustomContainerResponseHolder&) = delete;
    CreateBuildWithCustomContainerResponseHolder(CreateBuildWithCustomContainerResponseHolder&&) = default;
    CreateBuildWithCustomContainerResponseHolder& operator=(const CreateBuildWithCustomContainerResponseHolder&) = delete;
    CreateBuildWithCustomContainerResponseHolder& operator=(CreateBuildWithCustomContainerResponseHolder&&) = default;
    ~CreateBuildWithCustomContainerResponseHolder() = default;

    PFMultiplayerServerCreateBuildWithCustomContainerResponse* result{ nullptr };
};

struct CreateBuildWithManagedContainerResponseHolder : public XAsyncResult, public std::enable_shared_from_this<CreateBuildWithManagedContainerResponseHolder>
{
    CreateBuildWithManagedContainerResponseHolder() = default;
    CreateBuildWithManagedContainerResponseHolder(const CreateBuildWithManagedContainerResponseHolder&) = delete;
    CreateBuildWithManagedContainerResponseHolder(CreateBuildWithManagedContainerResponseHolder&&) = default;
    CreateBuildWithManagedContainerResponseHolder& operator=(const CreateBuildWithManagedContainerResponseHolder&) = delete;
    CreateBuildWithManagedContainerResponseHolder& operator=(CreateBuildWithManagedContainerResponseHolder&&) = default;
    ~CreateBuildWithManagedContainerResponseHolder() = default;

    PFMultiplayerServerCreateBuildWithManagedContainerResponse* result{ nullptr };
};

struct CreateBuildWithProcessBasedServerResponseHolder : public XAsyncResult, public std::enable_shared_from_this<CreateBuildWithProcessBasedServerResponseHolder>
{
    CreateBuildWithProcessBasedServerResponseHolder() = default;
    CreateBuildWithProcessBasedServerResponseHolder(const CreateBuildWithProcessBasedServerResponseHolder&) = delete;
    CreateBuildWithProcessBasedServerResponseHolder(CreateBuildWithProcessBasedServerResponseHolder&&) = default;
    CreateBuildWithProcessBasedServerResponseHolder& operator=(const CreateBuildWithProcessBasedServerResponseHolder&) = delete;
    CreateBuildWithProcessBasedServerResponseHolder& operator=(CreateBuildWithProcessBasedServerResponseHolder&&) = default;
    ~CreateBuildWithProcessBasedServerResponseHolder() = default;

    PFMultiplayerServerCreateBuildWithProcessBasedServerResponse* result{ nullptr };
};

struct CreateRemoteUserResponseHolder : public XAsyncResult, public std::enable_shared_from_this<CreateRemoteUserResponseHolder>
{
    CreateRemoteUserResponseHolder() = default;
    CreateRemoteUserResponseHolder(const CreateRemoteUserResponseHolder&) = delete;
    CreateRemoteUserResponseHolder(CreateRemoteUserResponseHolder&&) = default;
    CreateRemoteUserResponseHolder& operator=(const CreateRemoteUserResponseHolder&) = delete;
    CreateRemoteUserResponseHolder& operator=(CreateRemoteUserResponseHolder&&) = default;
    ~CreateRemoteUserResponseHolder() = default;

    PFMultiplayerServerCreateRemoteUserResponse* result{ nullptr };
};

struct CreateTitleMultiplayerServersQuotaChangeResponseHolder : public XAsyncResult, public std::enable_shared_from_this<CreateTitleMultiplayerServersQuotaChangeResponseHolder>
{
    CreateTitleMultiplayerServersQuotaChangeResponseHolder() = default;
    CreateTitleMultiplayerServersQuotaChangeResponseHolder(const CreateTitleMultiplayerServersQuotaChangeResponseHolder&) = delete;
    CreateTitleMultiplayerServersQuotaChangeResponseHolder(CreateTitleMultiplayerServersQuotaChangeResponseHolder&&) = default;
    CreateTitleMultiplayerServersQuotaChangeResponseHolder& operator=(const CreateTitleMultiplayerServersQuotaChangeResponseHolder&) = delete;
    CreateTitleMultiplayerServersQuotaChangeResponseHolder& operator=(CreateTitleMultiplayerServersQuotaChangeResponseHolder&&) = default;
    ~CreateTitleMultiplayerServersQuotaChangeResponseHolder() = default;

    PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse* result{ nullptr };
};

struct EnableMultiplayerServersForTitleResponseHolder : public XAsyncResult, public std::enable_shared_from_this<EnableMultiplayerServersForTitleResponseHolder>
{
    EnableMultiplayerServersForTitleResponseHolder() = default;
    EnableMultiplayerServersForTitleResponseHolder(const EnableMultiplayerServersForTitleResponseHolder&) = delete;
    EnableMultiplayerServersForTitleResponseHolder(EnableMultiplayerServersForTitleResponseHolder&&) = default;
    EnableMultiplayerServersForTitleResponseHolder& operator=(const EnableMultiplayerServersForTitleResponseHolder&) = delete;
    EnableMultiplayerServersForTitleResponseHolder& operator=(EnableMultiplayerServersForTitleResponseHolder&&) = default;
    ~EnableMultiplayerServersForTitleResponseHolder() = default;

    PFMultiplayerServerEnableMultiplayerServersForTitleResponse* result{ nullptr };
};

struct GetAssetDownloadUrlResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetAssetDownloadUrlResponseHolder>
{
    GetAssetDownloadUrlResponseHolder() = default;
    GetAssetDownloadUrlResponseHolder(const GetAssetDownloadUrlResponseHolder&) = delete;
    GetAssetDownloadUrlResponseHolder(GetAssetDownloadUrlResponseHolder&&) = default;
    GetAssetDownloadUrlResponseHolder& operator=(const GetAssetDownloadUrlResponseHolder&) = delete;
    GetAssetDownloadUrlResponseHolder& operator=(GetAssetDownloadUrlResponseHolder&&) = default;
    ~GetAssetDownloadUrlResponseHolder() = default;

    PFMultiplayerServerGetAssetDownloadUrlResponse* result{ nullptr };
};

struct GetAssetUploadUrlResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetAssetUploadUrlResponseHolder>
{
    GetAssetUploadUrlResponseHolder() = default;
    GetAssetUploadUrlResponseHolder(const GetAssetUploadUrlResponseHolder&) = delete;
    GetAssetUploadUrlResponseHolder(GetAssetUploadUrlResponseHolder&&) = default;
    GetAssetUploadUrlResponseHolder& operator=(const GetAssetUploadUrlResponseHolder&) = delete;
    GetAssetUploadUrlResponseHolder& operator=(GetAssetUploadUrlResponseHolder&&) = default;
    ~GetAssetUploadUrlResponseHolder() = default;

    PFMultiplayerServerGetAssetUploadUrlResponse* result{ nullptr };
};

struct GetBuildResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetBuildResponseHolder>
{
    GetBuildResponseHolder() = default;
    GetBuildResponseHolder(const GetBuildResponseHolder&) = delete;
    GetBuildResponseHolder(GetBuildResponseHolder&&) = default;
    GetBuildResponseHolder& operator=(const GetBuildResponseHolder&) = delete;
    GetBuildResponseHolder& operator=(GetBuildResponseHolder&&) = default;
    ~GetBuildResponseHolder() = default;

    PFMultiplayerServerGetBuildResponse* result{ nullptr };
};

struct GetContainerRegistryCredentialsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetContainerRegistryCredentialsResponseHolder>
{
    GetContainerRegistryCredentialsResponseHolder() = default;
    GetContainerRegistryCredentialsResponseHolder(const GetContainerRegistryCredentialsResponseHolder&) = delete;
    GetContainerRegistryCredentialsResponseHolder(GetContainerRegistryCredentialsResponseHolder&&) = default;
    GetContainerRegistryCredentialsResponseHolder& operator=(const GetContainerRegistryCredentialsResponseHolder&) = delete;
    GetContainerRegistryCredentialsResponseHolder& operator=(GetContainerRegistryCredentialsResponseHolder&&) = default;
    ~GetContainerRegistryCredentialsResponseHolder() = default;

    PFMultiplayerServerGetContainerRegistryCredentialsResponse* result{ nullptr };
};

struct GetMultiplayerServerDetailsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetMultiplayerServerDetailsResponseHolder>
{
    GetMultiplayerServerDetailsResponseHolder() = default;
    GetMultiplayerServerDetailsResponseHolder(const GetMultiplayerServerDetailsResponseHolder&) = delete;
    GetMultiplayerServerDetailsResponseHolder(GetMultiplayerServerDetailsResponseHolder&&) = default;
    GetMultiplayerServerDetailsResponseHolder& operator=(const GetMultiplayerServerDetailsResponseHolder&) = delete;
    GetMultiplayerServerDetailsResponseHolder& operator=(GetMultiplayerServerDetailsResponseHolder&&) = default;
    ~GetMultiplayerServerDetailsResponseHolder() = default;

    PFMultiplayerServerGetMultiplayerServerDetailsResponse* result{ nullptr };
};

struct GetMultiplayerServerLogsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetMultiplayerServerLogsResponseHolder>
{
    GetMultiplayerServerLogsResponseHolder() = default;
    GetMultiplayerServerLogsResponseHolder(const GetMultiplayerServerLogsResponseHolder&) = delete;
    GetMultiplayerServerLogsResponseHolder(GetMultiplayerServerLogsResponseHolder&&) = default;
    GetMultiplayerServerLogsResponseHolder& operator=(const GetMultiplayerServerLogsResponseHolder&) = delete;
    GetMultiplayerServerLogsResponseHolder& operator=(GetMultiplayerServerLogsResponseHolder&&) = default;
    ~GetMultiplayerServerLogsResponseHolder() = default;

    PFMultiplayerServerGetMultiplayerServerLogsResponse* result{ nullptr };
};

struct GetRemoteLoginEndpointResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetRemoteLoginEndpointResponseHolder>
{
    GetRemoteLoginEndpointResponseHolder() = default;
    GetRemoteLoginEndpointResponseHolder(const GetRemoteLoginEndpointResponseHolder&) = delete;
    GetRemoteLoginEndpointResponseHolder(GetRemoteLoginEndpointResponseHolder&&) = default;
    GetRemoteLoginEndpointResponseHolder& operator=(const GetRemoteLoginEndpointResponseHolder&) = delete;
    GetRemoteLoginEndpointResponseHolder& operator=(GetRemoteLoginEndpointResponseHolder&&) = default;
    ~GetRemoteLoginEndpointResponseHolder() = default;

    PFMultiplayerServerGetRemoteLoginEndpointResponse* result{ nullptr };
};

struct GetTitleEnabledForMultiplayerServersStatusResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetTitleEnabledForMultiplayerServersStatusResponseHolder>
{
    GetTitleEnabledForMultiplayerServersStatusResponseHolder() = default;
    GetTitleEnabledForMultiplayerServersStatusResponseHolder(const GetTitleEnabledForMultiplayerServersStatusResponseHolder&) = delete;
    GetTitleEnabledForMultiplayerServersStatusResponseHolder(GetTitleEnabledForMultiplayerServersStatusResponseHolder&&) = default;
    GetTitleEnabledForMultiplayerServersStatusResponseHolder& operator=(const GetTitleEnabledForMultiplayerServersStatusResponseHolder&) = delete;
    GetTitleEnabledForMultiplayerServersStatusResponseHolder& operator=(GetTitleEnabledForMultiplayerServersStatusResponseHolder&&) = default;
    ~GetTitleEnabledForMultiplayerServersStatusResponseHolder() = default;

    PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse* result{ nullptr };
};

struct GetTitleMultiplayerServersQuotaChangeResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetTitleMultiplayerServersQuotaChangeResponseHolder>
{
    GetTitleMultiplayerServersQuotaChangeResponseHolder() = default;
    GetTitleMultiplayerServersQuotaChangeResponseHolder(const GetTitleMultiplayerServersQuotaChangeResponseHolder&) = delete;
    GetTitleMultiplayerServersQuotaChangeResponseHolder(GetTitleMultiplayerServersQuotaChangeResponseHolder&&) = default;
    GetTitleMultiplayerServersQuotaChangeResponseHolder& operator=(const GetTitleMultiplayerServersQuotaChangeResponseHolder&) = delete;
    GetTitleMultiplayerServersQuotaChangeResponseHolder& operator=(GetTitleMultiplayerServersQuotaChangeResponseHolder&&) = default;
    ~GetTitleMultiplayerServersQuotaChangeResponseHolder() = default;

    PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse* result{ nullptr };
};

struct GetTitleMultiplayerServersQuotasResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetTitleMultiplayerServersQuotasResponseHolder>
{
    GetTitleMultiplayerServersQuotasResponseHolder() = default;
    GetTitleMultiplayerServersQuotasResponseHolder(const GetTitleMultiplayerServersQuotasResponseHolder&) = delete;
    GetTitleMultiplayerServersQuotasResponseHolder(GetTitleMultiplayerServersQuotasResponseHolder&&) = default;
    GetTitleMultiplayerServersQuotasResponseHolder& operator=(const GetTitleMultiplayerServersQuotasResponseHolder&) = delete;
    GetTitleMultiplayerServersQuotasResponseHolder& operator=(GetTitleMultiplayerServersQuotasResponseHolder&&) = default;
    ~GetTitleMultiplayerServersQuotasResponseHolder() = default;

    PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse* result{ nullptr };
};

struct ListMultiplayerServersResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListMultiplayerServersResponseHolder>
{
    ListMultiplayerServersResponseHolder() = default;
    ListMultiplayerServersResponseHolder(const ListMultiplayerServersResponseHolder&) = delete;
    ListMultiplayerServersResponseHolder(ListMultiplayerServersResponseHolder&&) = default;
    ListMultiplayerServersResponseHolder& operator=(const ListMultiplayerServersResponseHolder&) = delete;
    ListMultiplayerServersResponseHolder& operator=(ListMultiplayerServersResponseHolder&&) = default;
    ~ListMultiplayerServersResponseHolder() = default;

    PFMultiplayerServerListMultiplayerServersResponse* result{ nullptr };
};

struct ListAssetSummariesResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListAssetSummariesResponseHolder>
{
    ListAssetSummariesResponseHolder() = default;
    ListAssetSummariesResponseHolder(const ListAssetSummariesResponseHolder&) = delete;
    ListAssetSummariesResponseHolder(ListAssetSummariesResponseHolder&&) = default;
    ListAssetSummariesResponseHolder& operator=(const ListAssetSummariesResponseHolder&) = delete;
    ListAssetSummariesResponseHolder& operator=(ListAssetSummariesResponseHolder&&) = default;
    ~ListAssetSummariesResponseHolder() = default;

    PFMultiplayerServerListAssetSummariesResponse* result{ nullptr };
};

struct ListBuildAliasesResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListBuildAliasesResponseHolder>
{
    ListBuildAliasesResponseHolder() = default;
    ListBuildAliasesResponseHolder(const ListBuildAliasesResponseHolder&) = delete;
    ListBuildAliasesResponseHolder(ListBuildAliasesResponseHolder&&) = default;
    ListBuildAliasesResponseHolder& operator=(const ListBuildAliasesResponseHolder&) = delete;
    ListBuildAliasesResponseHolder& operator=(ListBuildAliasesResponseHolder&&) = default;
    ~ListBuildAliasesResponseHolder() = default;

    PFMultiplayerServerListBuildAliasesResponse* result{ nullptr };
};

struct ListBuildSummariesResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListBuildSummariesResponseHolder>
{
    ListBuildSummariesResponseHolder() = default;
    ListBuildSummariesResponseHolder(const ListBuildSummariesResponseHolder&) = delete;
    ListBuildSummariesResponseHolder(ListBuildSummariesResponseHolder&&) = default;
    ListBuildSummariesResponseHolder& operator=(const ListBuildSummariesResponseHolder&) = delete;
    ListBuildSummariesResponseHolder& operator=(ListBuildSummariesResponseHolder&&) = default;
    ~ListBuildSummariesResponseHolder() = default;

    PFMultiplayerServerListBuildSummariesResponse* result{ nullptr };
};

struct ListCertificateSummariesResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListCertificateSummariesResponseHolder>
{
    ListCertificateSummariesResponseHolder() = default;
    ListCertificateSummariesResponseHolder(const ListCertificateSummariesResponseHolder&) = delete;
    ListCertificateSummariesResponseHolder(ListCertificateSummariesResponseHolder&&) = default;
    ListCertificateSummariesResponseHolder& operator=(const ListCertificateSummariesResponseHolder&) = delete;
    ListCertificateSummariesResponseHolder& operator=(ListCertificateSummariesResponseHolder&&) = default;
    ~ListCertificateSummariesResponseHolder() = default;

    PFMultiplayerServerListCertificateSummariesResponse* result{ nullptr };
};

struct ListContainerImagesResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListContainerImagesResponseHolder>
{
    ListContainerImagesResponseHolder() = default;
    ListContainerImagesResponseHolder(const ListContainerImagesResponseHolder&) = delete;
    ListContainerImagesResponseHolder(ListContainerImagesResponseHolder&&) = default;
    ListContainerImagesResponseHolder& operator=(const ListContainerImagesResponseHolder&) = delete;
    ListContainerImagesResponseHolder& operator=(ListContainerImagesResponseHolder&&) = default;
    ~ListContainerImagesResponseHolder() = default;

    PFMultiplayerServerListContainerImagesResponse* result{ nullptr };
};

struct ListContainerImageTagsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListContainerImageTagsResponseHolder>
{
    ListContainerImageTagsResponseHolder() = default;
    ListContainerImageTagsResponseHolder(const ListContainerImageTagsResponseHolder&) = delete;
    ListContainerImageTagsResponseHolder(ListContainerImageTagsResponseHolder&&) = default;
    ListContainerImageTagsResponseHolder& operator=(const ListContainerImageTagsResponseHolder&) = delete;
    ListContainerImageTagsResponseHolder& operator=(ListContainerImageTagsResponseHolder&&) = default;
    ~ListContainerImageTagsResponseHolder() = default;

    PFMultiplayerServerListContainerImageTagsResponse* result{ nullptr };
};

struct ListPartyQosServersResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListPartyQosServersResponseHolder>
{
    ListPartyQosServersResponseHolder() = default;
    ListPartyQosServersResponseHolder(const ListPartyQosServersResponseHolder&) = delete;
    ListPartyQosServersResponseHolder(ListPartyQosServersResponseHolder&&) = default;
    ListPartyQosServersResponseHolder& operator=(const ListPartyQosServersResponseHolder&) = delete;
    ListPartyQosServersResponseHolder& operator=(ListPartyQosServersResponseHolder&&) = default;
    ~ListPartyQosServersResponseHolder() = default;

    PFMultiplayerServerListPartyQosServersResponse* result{ nullptr };
};

struct ListQosServersForTitleResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListQosServersForTitleResponseHolder>
{
    ListQosServersForTitleResponseHolder() = default;
    ListQosServersForTitleResponseHolder(const ListQosServersForTitleResponseHolder&) = delete;
    ListQosServersForTitleResponseHolder(ListQosServersForTitleResponseHolder&&) = default;
    ListQosServersForTitleResponseHolder& operator=(const ListQosServersForTitleResponseHolder&) = delete;
    ListQosServersForTitleResponseHolder& operator=(ListQosServersForTitleResponseHolder&&) = default;
    ~ListQosServersForTitleResponseHolder() = default;

    PFMultiplayerServerListQosServersForTitleResponse* result{ nullptr };
};

struct ListTitleMultiplayerServersQuotaChangesResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListTitleMultiplayerServersQuotaChangesResponseHolder>
{
    ListTitleMultiplayerServersQuotaChangesResponseHolder() = default;
    ListTitleMultiplayerServersQuotaChangesResponseHolder(const ListTitleMultiplayerServersQuotaChangesResponseHolder&) = delete;
    ListTitleMultiplayerServersQuotaChangesResponseHolder(ListTitleMultiplayerServersQuotaChangesResponseHolder&&) = default;
    ListTitleMultiplayerServersQuotaChangesResponseHolder& operator=(const ListTitleMultiplayerServersQuotaChangesResponseHolder&) = delete;
    ListTitleMultiplayerServersQuotaChangesResponseHolder& operator=(ListTitleMultiplayerServersQuotaChangesResponseHolder&&) = default;
    ~ListTitleMultiplayerServersQuotaChangesResponseHolder() = default;

    PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse* result{ nullptr };
};

struct ListVirtualMachineSummariesResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListVirtualMachineSummariesResponseHolder>
{
    ListVirtualMachineSummariesResponseHolder() = default;
    ListVirtualMachineSummariesResponseHolder(const ListVirtualMachineSummariesResponseHolder&) = delete;
    ListVirtualMachineSummariesResponseHolder(ListVirtualMachineSummariesResponseHolder&&) = default;
    ListVirtualMachineSummariesResponseHolder& operator=(const ListVirtualMachineSummariesResponseHolder&) = delete;
    ListVirtualMachineSummariesResponseHolder& operator=(ListVirtualMachineSummariesResponseHolder&&) = default;
    ~ListVirtualMachineSummariesResponseHolder() = default;

    PFMultiplayerServerListVirtualMachineSummariesResponse* result{ nullptr };
};

struct RequestMultiplayerServerResponseHolder : public XAsyncResult, public std::enable_shared_from_this<RequestMultiplayerServerResponseHolder>
{
    RequestMultiplayerServerResponseHolder() = default;
    RequestMultiplayerServerResponseHolder(const RequestMultiplayerServerResponseHolder&) = delete;
    RequestMultiplayerServerResponseHolder(RequestMultiplayerServerResponseHolder&&) = default;
    RequestMultiplayerServerResponseHolder& operator=(const RequestMultiplayerServerResponseHolder&) = delete;
    RequestMultiplayerServerResponseHolder& operator=(RequestMultiplayerServerResponseHolder&&) = default;
    ~RequestMultiplayerServerResponseHolder() = default;

    PFMultiplayerServerRequestMultiplayerServerResponse* result{ nullptr };
};

struct RolloverContainerRegistryCredentialsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<RolloverContainerRegistryCredentialsResponseHolder>
{
    RolloverContainerRegistryCredentialsResponseHolder() = default;
    RolloverContainerRegistryCredentialsResponseHolder(const RolloverContainerRegistryCredentialsResponseHolder&) = delete;
    RolloverContainerRegistryCredentialsResponseHolder(RolloverContainerRegistryCredentialsResponseHolder&&) = default;
    RolloverContainerRegistryCredentialsResponseHolder& operator=(const RolloverContainerRegistryCredentialsResponseHolder&) = delete;
    RolloverContainerRegistryCredentialsResponseHolder& operator=(RolloverContainerRegistryCredentialsResponseHolder&&) = default;
    ~RolloverContainerRegistryCredentialsResponseHolder() = default;

    PFMultiplayerServerRolloverContainerRegistryCredentialsResponse* result{ nullptr };
};


}
