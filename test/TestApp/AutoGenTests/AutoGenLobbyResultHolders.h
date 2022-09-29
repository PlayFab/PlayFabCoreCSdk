#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct CreateLobbyResultHolder : public XAsyncResult, public std::enable_shared_from_this<CreateLobbyResultHolder>
{
    CreateLobbyResultHolder() = default;
    CreateLobbyResultHolder(const CreateLobbyResultHolder&) = delete;
    CreateLobbyResultHolder(CreateLobbyResultHolder&&) = default;
    CreateLobbyResultHolder& operator=(const CreateLobbyResultHolder&) = delete;
    CreateLobbyResultHolder& operator=(CreateLobbyResultHolder&&) = default;
    ~CreateLobbyResultHolder() = default;

    PFLobbyCreateLobbyResult* result{ nullptr };
};

struct FindFriendLobbiesResultHolder : public XAsyncResult, public std::enable_shared_from_this<FindFriendLobbiesResultHolder>
{
    FindFriendLobbiesResultHolder() = default;
    FindFriendLobbiesResultHolder(const FindFriendLobbiesResultHolder&) = delete;
    FindFriendLobbiesResultHolder(FindFriendLobbiesResultHolder&&) = default;
    FindFriendLobbiesResultHolder& operator=(const FindFriendLobbiesResultHolder&) = delete;
    FindFriendLobbiesResultHolder& operator=(FindFriendLobbiesResultHolder&&) = default;
    ~FindFriendLobbiesResultHolder() = default;

    PFLobbyFindFriendLobbiesResult* result{ nullptr };
};

struct FindLobbiesResultHolder : public XAsyncResult, public std::enable_shared_from_this<FindLobbiesResultHolder>
{
    FindLobbiesResultHolder() = default;
    FindLobbiesResultHolder(const FindLobbiesResultHolder&) = delete;
    FindLobbiesResultHolder(FindLobbiesResultHolder&&) = default;
    FindLobbiesResultHolder& operator=(const FindLobbiesResultHolder&) = delete;
    FindLobbiesResultHolder& operator=(FindLobbiesResultHolder&&) = default;
    ~FindLobbiesResultHolder() = default;

    PFLobbyFindLobbiesResult* result{ nullptr };
};

struct GetLobbyResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetLobbyResultHolder>
{
    GetLobbyResultHolder() = default;
    GetLobbyResultHolder(const GetLobbyResultHolder&) = delete;
    GetLobbyResultHolder(GetLobbyResultHolder&&) = default;
    GetLobbyResultHolder& operator=(const GetLobbyResultHolder&) = delete;
    GetLobbyResultHolder& operator=(GetLobbyResultHolder&&) = default;
    ~GetLobbyResultHolder() = default;

    PFLobbyGetLobbyResult* result{ nullptr };
};

struct JoinLobbyResultHolder : public XAsyncResult, public std::enable_shared_from_this<JoinLobbyResultHolder>
{
    JoinLobbyResultHolder() = default;
    JoinLobbyResultHolder(const JoinLobbyResultHolder&) = delete;
    JoinLobbyResultHolder(JoinLobbyResultHolder&&) = default;
    JoinLobbyResultHolder& operator=(const JoinLobbyResultHolder&) = delete;
    JoinLobbyResultHolder& operator=(JoinLobbyResultHolder&&) = default;
    ~JoinLobbyResultHolder() = default;

    PFLobbyJoinLobbyResult* result{ nullptr };
};

struct SubscribeToLobbyResourceResultHolder : public XAsyncResult, public std::enable_shared_from_this<SubscribeToLobbyResourceResultHolder>
{
    SubscribeToLobbyResourceResultHolder() = default;
    SubscribeToLobbyResourceResultHolder(const SubscribeToLobbyResourceResultHolder&) = delete;
    SubscribeToLobbyResourceResultHolder(SubscribeToLobbyResourceResultHolder&&) = default;
    SubscribeToLobbyResourceResultHolder& operator=(const SubscribeToLobbyResourceResultHolder&) = delete;
    SubscribeToLobbyResourceResultHolder& operator=(SubscribeToLobbyResourceResultHolder&&) = default;
    ~SubscribeToLobbyResourceResultHolder() = default;

    PFLobbySubscribeToLobbyResourceResult* result{ nullptr };
};


}
