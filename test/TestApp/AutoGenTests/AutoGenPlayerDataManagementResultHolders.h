#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct CreatePlayerStatisticDefinitionResultHolder : public XAsyncResult, public std::enable_shared_from_this<CreatePlayerStatisticDefinitionResultHolder>
{
    CreatePlayerStatisticDefinitionResultHolder() = default;
    CreatePlayerStatisticDefinitionResultHolder(const CreatePlayerStatisticDefinitionResultHolder&) = delete;
    CreatePlayerStatisticDefinitionResultHolder(CreatePlayerStatisticDefinitionResultHolder&&) = default;
    CreatePlayerStatisticDefinitionResultHolder& operator=(const CreatePlayerStatisticDefinitionResultHolder&) = delete;
    CreatePlayerStatisticDefinitionResultHolder& operator=(CreatePlayerStatisticDefinitionResultHolder&&) = default;
    ~CreatePlayerStatisticDefinitionResultHolder() = default;

    PFPlayerDataManagementCreatePlayerStatisticDefinitionResult* result{ nullptr };
};

struct GetDataReportResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetDataReportResultHolder>
{
    GetDataReportResultHolder() = default;
    GetDataReportResultHolder(const GetDataReportResultHolder&) = delete;
    GetDataReportResultHolder(GetDataReportResultHolder&&) = default;
    GetDataReportResultHolder& operator=(const GetDataReportResultHolder&) = delete;
    GetDataReportResultHolder& operator=(GetDataReportResultHolder&&) = default;
    ~GetDataReportResultHolder() = default;

    PFPlayerDataManagementGetDataReportResult* result{ nullptr };
};

struct GetPlayerStatisticDefinitionsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayerStatisticDefinitionsResultHolder>
{
    GetPlayerStatisticDefinitionsResultHolder() = default;
    GetPlayerStatisticDefinitionsResultHolder(const GetPlayerStatisticDefinitionsResultHolder&) = delete;
    GetPlayerStatisticDefinitionsResultHolder(GetPlayerStatisticDefinitionsResultHolder&&) = default;
    GetPlayerStatisticDefinitionsResultHolder& operator=(const GetPlayerStatisticDefinitionsResultHolder&) = delete;
    GetPlayerStatisticDefinitionsResultHolder& operator=(GetPlayerStatisticDefinitionsResultHolder&&) = default;
    ~GetPlayerStatisticDefinitionsResultHolder() = default;

    PFPlayerDataManagementGetPlayerStatisticDefinitionsResult* result{ nullptr };
};

struct GetPlayerStatisticVersionsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayerStatisticVersionsResultHolder>
{
    GetPlayerStatisticVersionsResultHolder() = default;
    GetPlayerStatisticVersionsResultHolder(const GetPlayerStatisticVersionsResultHolder&) = delete;
    GetPlayerStatisticVersionsResultHolder(GetPlayerStatisticVersionsResultHolder&&) = default;
    GetPlayerStatisticVersionsResultHolder& operator=(const GetPlayerStatisticVersionsResultHolder&) = delete;
    GetPlayerStatisticVersionsResultHolder& operator=(GetPlayerStatisticVersionsResultHolder&&) = default;
    ~GetPlayerStatisticVersionsResultHolder() = default;

    PFPlayerDataManagementGetPlayerStatisticVersionsResult* result{ nullptr };
};

struct AdminGetUserDataResultHolder : public XAsyncResult, public std::enable_shared_from_this<AdminGetUserDataResultHolder>
{
    AdminGetUserDataResultHolder() = default;
    AdminGetUserDataResultHolder(const AdminGetUserDataResultHolder&) = delete;
    AdminGetUserDataResultHolder(AdminGetUserDataResultHolder&&) = default;
    AdminGetUserDataResultHolder& operator=(const AdminGetUserDataResultHolder&) = delete;
    AdminGetUserDataResultHolder& operator=(AdminGetUserDataResultHolder&&) = default;
    ~AdminGetUserDataResultHolder() = default;

    PFPlayerDataManagementAdminGetUserDataResult* result{ nullptr };
};

struct IncrementPlayerStatisticVersionResultHolder : public XAsyncResult, public std::enable_shared_from_this<IncrementPlayerStatisticVersionResultHolder>
{
    IncrementPlayerStatisticVersionResultHolder() = default;
    IncrementPlayerStatisticVersionResultHolder(const IncrementPlayerStatisticVersionResultHolder&) = delete;
    IncrementPlayerStatisticVersionResultHolder(IncrementPlayerStatisticVersionResultHolder&&) = default;
    IncrementPlayerStatisticVersionResultHolder& operator=(const IncrementPlayerStatisticVersionResultHolder&) = delete;
    IncrementPlayerStatisticVersionResultHolder& operator=(IncrementPlayerStatisticVersionResultHolder&&) = default;
    ~IncrementPlayerStatisticVersionResultHolder() = default;

    PFPlayerDataManagementIncrementPlayerStatisticVersionResult* result{ nullptr };
};

struct RefundPurchaseResponseHolder : public XAsyncResult, public std::enable_shared_from_this<RefundPurchaseResponseHolder>
{
    RefundPurchaseResponseHolder() = default;
    RefundPurchaseResponseHolder(const RefundPurchaseResponseHolder&) = delete;
    RefundPurchaseResponseHolder(RefundPurchaseResponseHolder&&) = default;
    RefundPurchaseResponseHolder& operator=(const RefundPurchaseResponseHolder&) = delete;
    RefundPurchaseResponseHolder& operator=(RefundPurchaseResponseHolder&&) = default;
    ~RefundPurchaseResponseHolder() = default;

    PFPlayerDataManagementRefundPurchaseResponse* result{ nullptr };
};

struct ResolvePurchaseDisputeResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ResolvePurchaseDisputeResponseHolder>
{
    ResolvePurchaseDisputeResponseHolder() = default;
    ResolvePurchaseDisputeResponseHolder(const ResolvePurchaseDisputeResponseHolder&) = delete;
    ResolvePurchaseDisputeResponseHolder(ResolvePurchaseDisputeResponseHolder&&) = default;
    ResolvePurchaseDisputeResponseHolder& operator=(const ResolvePurchaseDisputeResponseHolder&) = delete;
    ResolvePurchaseDisputeResponseHolder& operator=(ResolvePurchaseDisputeResponseHolder&&) = default;
    ~ResolvePurchaseDisputeResponseHolder() = default;

    PFPlayerDataManagementResolvePurchaseDisputeResponse* result{ nullptr };
};

struct UpdatePlayerStatisticDefinitionResultHolder : public XAsyncResult, public std::enable_shared_from_this<UpdatePlayerStatisticDefinitionResultHolder>
{
    UpdatePlayerStatisticDefinitionResultHolder() = default;
    UpdatePlayerStatisticDefinitionResultHolder(const UpdatePlayerStatisticDefinitionResultHolder&) = delete;
    UpdatePlayerStatisticDefinitionResultHolder(UpdatePlayerStatisticDefinitionResultHolder&&) = default;
    UpdatePlayerStatisticDefinitionResultHolder& operator=(const UpdatePlayerStatisticDefinitionResultHolder&) = delete;
    UpdatePlayerStatisticDefinitionResultHolder& operator=(UpdatePlayerStatisticDefinitionResultHolder&&) = default;
    ~UpdatePlayerStatisticDefinitionResultHolder() = default;

    PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult* result{ nullptr };
};

struct UpdateUserDataResultHolder : public XAsyncResult, public std::enable_shared_from_this<UpdateUserDataResultHolder>
{
    UpdateUserDataResultHolder() = default;
    UpdateUserDataResultHolder(const UpdateUserDataResultHolder&) = default;
    UpdateUserDataResultHolder(UpdateUserDataResultHolder&&) = default;
    UpdateUserDataResultHolder& operator=(const UpdateUserDataResultHolder&) = default;
    UpdateUserDataResultHolder& operator=(UpdateUserDataResultHolder&&) = default;
    ~UpdateUserDataResultHolder() = default;

    PFPlayerDataManagementUpdateUserDataResult result{};
};

struct GetLeaderboardResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetLeaderboardResultHolder>
{
    GetLeaderboardResultHolder() = default;
    GetLeaderboardResultHolder(const GetLeaderboardResultHolder&) = delete;
    GetLeaderboardResultHolder(GetLeaderboardResultHolder&&) = default;
    GetLeaderboardResultHolder& operator=(const GetLeaderboardResultHolder&) = delete;
    GetLeaderboardResultHolder& operator=(GetLeaderboardResultHolder&&) = default;
    ~GetLeaderboardResultHolder() = default;

    PFPlayerDataManagementGetLeaderboardResult* result{ nullptr };
};

struct GetFriendLeaderboardAroundPlayerResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetFriendLeaderboardAroundPlayerResultHolder>
{
    GetFriendLeaderboardAroundPlayerResultHolder() = default;
    GetFriendLeaderboardAroundPlayerResultHolder(const GetFriendLeaderboardAroundPlayerResultHolder&) = delete;
    GetFriendLeaderboardAroundPlayerResultHolder(GetFriendLeaderboardAroundPlayerResultHolder&&) = default;
    GetFriendLeaderboardAroundPlayerResultHolder& operator=(const GetFriendLeaderboardAroundPlayerResultHolder&) = delete;
    GetFriendLeaderboardAroundPlayerResultHolder& operator=(GetFriendLeaderboardAroundPlayerResultHolder&&) = default;
    ~GetFriendLeaderboardAroundPlayerResultHolder() = default;

    PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult* result{ nullptr };
};

struct GetLeaderboardAroundPlayerResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetLeaderboardAroundPlayerResultHolder>
{
    GetLeaderboardAroundPlayerResultHolder() = default;
    GetLeaderboardAroundPlayerResultHolder(const GetLeaderboardAroundPlayerResultHolder&) = delete;
    GetLeaderboardAroundPlayerResultHolder(GetLeaderboardAroundPlayerResultHolder&&) = default;
    GetLeaderboardAroundPlayerResultHolder& operator=(const GetLeaderboardAroundPlayerResultHolder&) = delete;
    GetLeaderboardAroundPlayerResultHolder& operator=(GetLeaderboardAroundPlayerResultHolder&&) = default;
    ~GetLeaderboardAroundPlayerResultHolder() = default;

    PFPlayerDataManagementGetLeaderboardAroundPlayerResult* result{ nullptr };
};

struct ClientGetPlayerStatisticsResultHolder : public XAsyncResult, public std::enable_shared_from_this<ClientGetPlayerStatisticsResultHolder>
{
    ClientGetPlayerStatisticsResultHolder() = default;
    ClientGetPlayerStatisticsResultHolder(const ClientGetPlayerStatisticsResultHolder&) = delete;
    ClientGetPlayerStatisticsResultHolder(ClientGetPlayerStatisticsResultHolder&&) = default;
    ClientGetPlayerStatisticsResultHolder& operator=(const ClientGetPlayerStatisticsResultHolder&) = delete;
    ClientGetPlayerStatisticsResultHolder& operator=(ClientGetPlayerStatisticsResultHolder&&) = default;
    ~ClientGetPlayerStatisticsResultHolder() = default;

    PFPlayerDataManagementClientGetPlayerStatisticsResult* result{ nullptr };
};

struct ClientGetUserDataResultHolder : public XAsyncResult, public std::enable_shared_from_this<ClientGetUserDataResultHolder>
{
    ClientGetUserDataResultHolder() = default;
    ClientGetUserDataResultHolder(const ClientGetUserDataResultHolder&) = delete;
    ClientGetUserDataResultHolder(ClientGetUserDataResultHolder&&) = default;
    ClientGetUserDataResultHolder& operator=(const ClientGetUserDataResultHolder&) = delete;
    ClientGetUserDataResultHolder& operator=(ClientGetUserDataResultHolder&&) = default;
    ~ClientGetUserDataResultHolder() = default;

    PFPlayerDataManagementClientGetUserDataResult* result{ nullptr };
};

struct GetLeaderboardAroundUserResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetLeaderboardAroundUserResultHolder>
{
    GetLeaderboardAroundUserResultHolder() = default;
    GetLeaderboardAroundUserResultHolder(const GetLeaderboardAroundUserResultHolder&) = delete;
    GetLeaderboardAroundUserResultHolder(GetLeaderboardAroundUserResultHolder&&) = default;
    GetLeaderboardAroundUserResultHolder& operator=(const GetLeaderboardAroundUserResultHolder&) = delete;
    GetLeaderboardAroundUserResultHolder& operator=(GetLeaderboardAroundUserResultHolder&&) = default;
    ~GetLeaderboardAroundUserResultHolder() = default;

    PFPlayerDataManagementGetLeaderboardAroundUserResult* result{ nullptr };
};

struct ServerGetPlayerStatisticsResultHolder : public XAsyncResult, public std::enable_shared_from_this<ServerGetPlayerStatisticsResultHolder>
{
    ServerGetPlayerStatisticsResultHolder() = default;
    ServerGetPlayerStatisticsResultHolder(const ServerGetPlayerStatisticsResultHolder&) = delete;
    ServerGetPlayerStatisticsResultHolder(ServerGetPlayerStatisticsResultHolder&&) = default;
    ServerGetPlayerStatisticsResultHolder& operator=(const ServerGetPlayerStatisticsResultHolder&) = delete;
    ServerGetPlayerStatisticsResultHolder& operator=(ServerGetPlayerStatisticsResultHolder&&) = default;
    ~ServerGetPlayerStatisticsResultHolder() = default;

    PFPlayerDataManagementServerGetPlayerStatisticsResult* result{ nullptr };
};

struct ServerGetUserDataResultHolder : public XAsyncResult, public std::enable_shared_from_this<ServerGetUserDataResultHolder>
{
    ServerGetUserDataResultHolder() = default;
    ServerGetUserDataResultHolder(const ServerGetUserDataResultHolder&) = delete;
    ServerGetUserDataResultHolder(ServerGetUserDataResultHolder&&) = default;
    ServerGetUserDataResultHolder& operator=(const ServerGetUserDataResultHolder&) = delete;
    ServerGetUserDataResultHolder& operator=(ServerGetUserDataResultHolder&&) = default;
    ~ServerGetUserDataResultHolder() = default;

    PFPlayerDataManagementServerGetUserDataResult* result{ nullptr };
};


}
