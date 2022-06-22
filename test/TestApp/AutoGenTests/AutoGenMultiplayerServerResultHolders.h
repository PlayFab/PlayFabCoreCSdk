#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


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


}
