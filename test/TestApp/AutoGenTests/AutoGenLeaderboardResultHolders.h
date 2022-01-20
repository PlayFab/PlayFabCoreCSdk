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

    PFLeaderboardCreatePlayerStatisticDefinitionResult* result{ nullptr };
};

struct GetPlayerStatisticDefinitionsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayerStatisticDefinitionsResultHolder>
{
    GetPlayerStatisticDefinitionsResultHolder() = default;
    GetPlayerStatisticDefinitionsResultHolder(const GetPlayerStatisticDefinitionsResultHolder&) = delete;
    GetPlayerStatisticDefinitionsResultHolder(GetPlayerStatisticDefinitionsResultHolder&&) = default;
    GetPlayerStatisticDefinitionsResultHolder& operator=(const GetPlayerStatisticDefinitionsResultHolder&) = delete;
    GetPlayerStatisticDefinitionsResultHolder& operator=(GetPlayerStatisticDefinitionsResultHolder&&) = default;
    ~GetPlayerStatisticDefinitionsResultHolder() = default;

    PFLeaderboardGetPlayerStatisticDefinitionsResult* result{ nullptr };
};

struct GetPlayerStatisticVersionsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayerStatisticVersionsResultHolder>
{
    GetPlayerStatisticVersionsResultHolder() = default;
    GetPlayerStatisticVersionsResultHolder(const GetPlayerStatisticVersionsResultHolder&) = delete;
    GetPlayerStatisticVersionsResultHolder(GetPlayerStatisticVersionsResultHolder&&) = default;
    GetPlayerStatisticVersionsResultHolder& operator=(const GetPlayerStatisticVersionsResultHolder&) = delete;
    GetPlayerStatisticVersionsResultHolder& operator=(GetPlayerStatisticVersionsResultHolder&&) = default;
    ~GetPlayerStatisticVersionsResultHolder() = default;

    PFLeaderboardGetPlayerStatisticVersionsResult* result{ nullptr };
};

struct IncrementPlayerStatisticVersionResultHolder : public XAsyncResult, public std::enable_shared_from_this<IncrementPlayerStatisticVersionResultHolder>
{
    IncrementPlayerStatisticVersionResultHolder() = default;
    IncrementPlayerStatisticVersionResultHolder(const IncrementPlayerStatisticVersionResultHolder&) = delete;
    IncrementPlayerStatisticVersionResultHolder(IncrementPlayerStatisticVersionResultHolder&&) = default;
    IncrementPlayerStatisticVersionResultHolder& operator=(const IncrementPlayerStatisticVersionResultHolder&) = delete;
    IncrementPlayerStatisticVersionResultHolder& operator=(IncrementPlayerStatisticVersionResultHolder&&) = default;
    ~IncrementPlayerStatisticVersionResultHolder() = default;

    PFLeaderboardIncrementPlayerStatisticVersionResult* result{ nullptr };
};

struct UpdatePlayerStatisticDefinitionResultHolder : public XAsyncResult, public std::enable_shared_from_this<UpdatePlayerStatisticDefinitionResultHolder>
{
    UpdatePlayerStatisticDefinitionResultHolder() = default;
    UpdatePlayerStatisticDefinitionResultHolder(const UpdatePlayerStatisticDefinitionResultHolder&) = delete;
    UpdatePlayerStatisticDefinitionResultHolder(UpdatePlayerStatisticDefinitionResultHolder&&) = default;
    UpdatePlayerStatisticDefinitionResultHolder& operator=(const UpdatePlayerStatisticDefinitionResultHolder&) = delete;
    UpdatePlayerStatisticDefinitionResultHolder& operator=(UpdatePlayerStatisticDefinitionResultHolder&&) = default;
    ~UpdatePlayerStatisticDefinitionResultHolder() = default;

    PFLeaderboardUpdatePlayerStatisticDefinitionResult* result{ nullptr };
};

struct GetLeaderboardResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetLeaderboardResultHolder>
{
    GetLeaderboardResultHolder() = default;
    GetLeaderboardResultHolder(const GetLeaderboardResultHolder&) = delete;
    GetLeaderboardResultHolder(GetLeaderboardResultHolder&&) = default;
    GetLeaderboardResultHolder& operator=(const GetLeaderboardResultHolder&) = delete;
    GetLeaderboardResultHolder& operator=(GetLeaderboardResultHolder&&) = default;
    ~GetLeaderboardResultHolder() = default;

    PFLeaderboardGetLeaderboardResult* result{ nullptr };
};

struct GetFriendLeaderboardAroundPlayerResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetFriendLeaderboardAroundPlayerResultHolder>
{
    GetFriendLeaderboardAroundPlayerResultHolder() = default;
    GetFriendLeaderboardAroundPlayerResultHolder(const GetFriendLeaderboardAroundPlayerResultHolder&) = delete;
    GetFriendLeaderboardAroundPlayerResultHolder(GetFriendLeaderboardAroundPlayerResultHolder&&) = default;
    GetFriendLeaderboardAroundPlayerResultHolder& operator=(const GetFriendLeaderboardAroundPlayerResultHolder&) = delete;
    GetFriendLeaderboardAroundPlayerResultHolder& operator=(GetFriendLeaderboardAroundPlayerResultHolder&&) = default;
    ~GetFriendLeaderboardAroundPlayerResultHolder() = default;

    PFLeaderboardGetFriendLeaderboardAroundPlayerResult* result{ nullptr };
};

struct GetLeaderboardAroundPlayerResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetLeaderboardAroundPlayerResultHolder>
{
    GetLeaderboardAroundPlayerResultHolder() = default;
    GetLeaderboardAroundPlayerResultHolder(const GetLeaderboardAroundPlayerResultHolder&) = delete;
    GetLeaderboardAroundPlayerResultHolder(GetLeaderboardAroundPlayerResultHolder&&) = default;
    GetLeaderboardAroundPlayerResultHolder& operator=(const GetLeaderboardAroundPlayerResultHolder&) = delete;
    GetLeaderboardAroundPlayerResultHolder& operator=(GetLeaderboardAroundPlayerResultHolder&&) = default;
    ~GetLeaderboardAroundPlayerResultHolder() = default;

    PFLeaderboardGetLeaderboardAroundPlayerResult* result{ nullptr };
};

struct ClientGetPlayerStatisticsResultHolder : public XAsyncResult, public std::enable_shared_from_this<ClientGetPlayerStatisticsResultHolder>
{
    ClientGetPlayerStatisticsResultHolder() = default;
    ClientGetPlayerStatisticsResultHolder(const ClientGetPlayerStatisticsResultHolder&) = delete;
    ClientGetPlayerStatisticsResultHolder(ClientGetPlayerStatisticsResultHolder&&) = default;
    ClientGetPlayerStatisticsResultHolder& operator=(const ClientGetPlayerStatisticsResultHolder&) = delete;
    ClientGetPlayerStatisticsResultHolder& operator=(ClientGetPlayerStatisticsResultHolder&&) = default;
    ~ClientGetPlayerStatisticsResultHolder() = default;

    PFLeaderboardClientGetPlayerStatisticsResult* result{ nullptr };
};

struct GetLeaderboardAroundUserResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetLeaderboardAroundUserResultHolder>
{
    GetLeaderboardAroundUserResultHolder() = default;
    GetLeaderboardAroundUserResultHolder(const GetLeaderboardAroundUserResultHolder&) = delete;
    GetLeaderboardAroundUserResultHolder(GetLeaderboardAroundUserResultHolder&&) = default;
    GetLeaderboardAroundUserResultHolder& operator=(const GetLeaderboardAroundUserResultHolder&) = delete;
    GetLeaderboardAroundUserResultHolder& operator=(GetLeaderboardAroundUserResultHolder&&) = default;
    ~GetLeaderboardAroundUserResultHolder() = default;

    PFLeaderboardGetLeaderboardAroundUserResult* result{ nullptr };
};

struct ServerGetPlayerStatisticsResultHolder : public XAsyncResult, public std::enable_shared_from_this<ServerGetPlayerStatisticsResultHolder>
{
    ServerGetPlayerStatisticsResultHolder() = default;
    ServerGetPlayerStatisticsResultHolder(const ServerGetPlayerStatisticsResultHolder&) = delete;
    ServerGetPlayerStatisticsResultHolder(ServerGetPlayerStatisticsResultHolder&&) = default;
    ServerGetPlayerStatisticsResultHolder& operator=(const ServerGetPlayerStatisticsResultHolder&) = delete;
    ServerGetPlayerStatisticsResultHolder& operator=(ServerGetPlayerStatisticsResultHolder&&) = default;
    ~ServerGetPlayerStatisticsResultHolder() = default;

    PFLeaderboardServerGetPlayerStatisticsResult* result{ nullptr };
};


}
