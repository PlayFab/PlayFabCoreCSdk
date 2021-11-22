#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct ListUsersCharactersResultHolder : public XAsyncResult, public std::enable_shared_from_this<ListUsersCharactersResultHolder>
{
    ListUsersCharactersResultHolder() = default;
    ListUsersCharactersResultHolder(const ListUsersCharactersResultHolder&) = delete;
    ListUsersCharactersResultHolder(ListUsersCharactersResultHolder&&) = default;
    ListUsersCharactersResultHolder& operator=(const ListUsersCharactersResultHolder&) = delete;
    ListUsersCharactersResultHolder& operator=(ListUsersCharactersResultHolder&&) = default;
    ~ListUsersCharactersResultHolder() = default;

    PFCharacterListUsersCharactersResult* result{ nullptr };
};

struct ClientGetCharacterDataResultHolder : public XAsyncResult, public std::enable_shared_from_this<ClientGetCharacterDataResultHolder>
{
    ClientGetCharacterDataResultHolder() = default;
    ClientGetCharacterDataResultHolder(const ClientGetCharacterDataResultHolder&) = delete;
    ClientGetCharacterDataResultHolder(ClientGetCharacterDataResultHolder&&) = default;
    ClientGetCharacterDataResultHolder& operator=(const ClientGetCharacterDataResultHolder&) = delete;
    ClientGetCharacterDataResultHolder& operator=(ClientGetCharacterDataResultHolder&&) = default;
    ~ClientGetCharacterDataResultHolder() = default;

    PFCharacterClientGetCharacterDataResult* result{ nullptr };
};

struct GetCharacterLeaderboardResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetCharacterLeaderboardResultHolder>
{
    GetCharacterLeaderboardResultHolder() = default;
    GetCharacterLeaderboardResultHolder(const GetCharacterLeaderboardResultHolder&) = delete;
    GetCharacterLeaderboardResultHolder(GetCharacterLeaderboardResultHolder&&) = default;
    GetCharacterLeaderboardResultHolder& operator=(const GetCharacterLeaderboardResultHolder&) = delete;
    GetCharacterLeaderboardResultHolder& operator=(GetCharacterLeaderboardResultHolder&&) = default;
    ~GetCharacterLeaderboardResultHolder() = default;

    PFCharacterGetCharacterLeaderboardResult* result{ nullptr };
};

struct ClientGetCharacterStatisticsResultHolder : public XAsyncResult, public std::enable_shared_from_this<ClientGetCharacterStatisticsResultHolder>
{
    ClientGetCharacterStatisticsResultHolder() = default;
    ClientGetCharacterStatisticsResultHolder(const ClientGetCharacterStatisticsResultHolder&) = delete;
    ClientGetCharacterStatisticsResultHolder(ClientGetCharacterStatisticsResultHolder&&) = default;
    ClientGetCharacterStatisticsResultHolder& operator=(const ClientGetCharacterStatisticsResultHolder&) = delete;
    ClientGetCharacterStatisticsResultHolder& operator=(ClientGetCharacterStatisticsResultHolder&&) = default;
    ~ClientGetCharacterStatisticsResultHolder() = default;

    PFCharacterClientGetCharacterStatisticsResult* result{ nullptr };
};

struct GetLeaderboardAroundCharacterResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetLeaderboardAroundCharacterResultHolder>
{
    GetLeaderboardAroundCharacterResultHolder() = default;
    GetLeaderboardAroundCharacterResultHolder(const GetLeaderboardAroundCharacterResultHolder&) = delete;
    GetLeaderboardAroundCharacterResultHolder(GetLeaderboardAroundCharacterResultHolder&&) = default;
    GetLeaderboardAroundCharacterResultHolder& operator=(const GetLeaderboardAroundCharacterResultHolder&) = delete;
    GetLeaderboardAroundCharacterResultHolder& operator=(GetLeaderboardAroundCharacterResultHolder&&) = default;
    ~GetLeaderboardAroundCharacterResultHolder() = default;

    PFCharacterGetLeaderboardAroundCharacterResult* result{ nullptr };
};

struct GetLeaderboardForUsersCharactersResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetLeaderboardForUsersCharactersResultHolder>
{
    GetLeaderboardForUsersCharactersResultHolder() = default;
    GetLeaderboardForUsersCharactersResultHolder(const GetLeaderboardForUsersCharactersResultHolder&) = delete;
    GetLeaderboardForUsersCharactersResultHolder(GetLeaderboardForUsersCharactersResultHolder&&) = default;
    GetLeaderboardForUsersCharactersResultHolder& operator=(const GetLeaderboardForUsersCharactersResultHolder&) = delete;
    GetLeaderboardForUsersCharactersResultHolder& operator=(GetLeaderboardForUsersCharactersResultHolder&&) = default;
    ~GetLeaderboardForUsersCharactersResultHolder() = default;

    PFCharacterGetLeaderboardForUsersCharactersResult* result{ nullptr };
};

struct ClientGrantCharacterToUserResultHolder : public XAsyncResult, public std::enable_shared_from_this<ClientGrantCharacterToUserResultHolder>
{
    ClientGrantCharacterToUserResultHolder() = default;
    ClientGrantCharacterToUserResultHolder(const ClientGrantCharacterToUserResultHolder&) = delete;
    ClientGrantCharacterToUserResultHolder(ClientGrantCharacterToUserResultHolder&&) = default;
    ClientGrantCharacterToUserResultHolder& operator=(const ClientGrantCharacterToUserResultHolder&) = delete;
    ClientGrantCharacterToUserResultHolder& operator=(ClientGrantCharacterToUserResultHolder&&) = default;
    ~ClientGrantCharacterToUserResultHolder() = default;

    PFCharacterClientGrantCharacterToUserResult* result{ nullptr };
};

struct UpdateCharacterDataResultHolder : public XAsyncResult, public std::enable_shared_from_this<UpdateCharacterDataResultHolder>
{
    UpdateCharacterDataResultHolder() = default;
    UpdateCharacterDataResultHolder(const UpdateCharacterDataResultHolder&) = default;
    UpdateCharacterDataResultHolder(UpdateCharacterDataResultHolder&&) = default;
    UpdateCharacterDataResultHolder& operator=(const UpdateCharacterDataResultHolder&) = default;
    UpdateCharacterDataResultHolder& operator=(UpdateCharacterDataResultHolder&&) = default;
    ~UpdateCharacterDataResultHolder() = default;

    PFCharacterUpdateCharacterDataResult result{};
};

struct ServerGetCharacterDataResultHolder : public XAsyncResult, public std::enable_shared_from_this<ServerGetCharacterDataResultHolder>
{
    ServerGetCharacterDataResultHolder() = default;
    ServerGetCharacterDataResultHolder(const ServerGetCharacterDataResultHolder&) = delete;
    ServerGetCharacterDataResultHolder(ServerGetCharacterDataResultHolder&&) = default;
    ServerGetCharacterDataResultHolder& operator=(const ServerGetCharacterDataResultHolder&) = delete;
    ServerGetCharacterDataResultHolder& operator=(ServerGetCharacterDataResultHolder&&) = default;
    ~ServerGetCharacterDataResultHolder() = default;

    PFCharacterServerGetCharacterDataResult* result{ nullptr };
};

struct ServerGetCharacterStatisticsResultHolder : public XAsyncResult, public std::enable_shared_from_this<ServerGetCharacterStatisticsResultHolder>
{
    ServerGetCharacterStatisticsResultHolder() = default;
    ServerGetCharacterStatisticsResultHolder(const ServerGetCharacterStatisticsResultHolder&) = delete;
    ServerGetCharacterStatisticsResultHolder(ServerGetCharacterStatisticsResultHolder&&) = default;
    ServerGetCharacterStatisticsResultHolder& operator=(const ServerGetCharacterStatisticsResultHolder&) = delete;
    ServerGetCharacterStatisticsResultHolder& operator=(ServerGetCharacterStatisticsResultHolder&&) = default;
    ~ServerGetCharacterStatisticsResultHolder() = default;

    PFCharacterServerGetCharacterStatisticsResult* result{ nullptr };
};

struct ServerGrantCharacterToUserResultHolder : public XAsyncResult, public std::enable_shared_from_this<ServerGrantCharacterToUserResultHolder>
{
    ServerGrantCharacterToUserResultHolder() = default;
    ServerGrantCharacterToUserResultHolder(const ServerGrantCharacterToUserResultHolder&) = delete;
    ServerGrantCharacterToUserResultHolder(ServerGrantCharacterToUserResultHolder&&) = default;
    ServerGrantCharacterToUserResultHolder& operator=(const ServerGrantCharacterToUserResultHolder&) = delete;
    ServerGrantCharacterToUserResultHolder& operator=(ServerGrantCharacterToUserResultHolder&&) = default;
    ~ServerGrantCharacterToUserResultHolder() = default;

    PFCharacterServerGrantCharacterToUserResult* result{ nullptr };
};


}
