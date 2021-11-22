#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct GetGlobalPolicyResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetGlobalPolicyResponseHolder>
{
    GetGlobalPolicyResponseHolder() = default;
    GetGlobalPolicyResponseHolder(const GetGlobalPolicyResponseHolder&) = delete;
    GetGlobalPolicyResponseHolder(GetGlobalPolicyResponseHolder&&) = default;
    GetGlobalPolicyResponseHolder& operator=(const GetGlobalPolicyResponseHolder&) = delete;
    GetGlobalPolicyResponseHolder& operator=(GetGlobalPolicyResponseHolder&&) = default;
    ~GetGlobalPolicyResponseHolder() = default;

    PFProfilesGetGlobalPolicyResponse* result{ nullptr };
};

struct GetEntityProfileResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetEntityProfileResponseHolder>
{
    GetEntityProfileResponseHolder() = default;
    GetEntityProfileResponseHolder(const GetEntityProfileResponseHolder&) = delete;
    GetEntityProfileResponseHolder(GetEntityProfileResponseHolder&&) = default;
    GetEntityProfileResponseHolder& operator=(const GetEntityProfileResponseHolder&) = delete;
    GetEntityProfileResponseHolder& operator=(GetEntityProfileResponseHolder&&) = default;
    ~GetEntityProfileResponseHolder() = default;

    PFProfilesGetEntityProfileResponse* result{ nullptr };
};

struct GetEntityProfilesResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetEntityProfilesResponseHolder>
{
    GetEntityProfilesResponseHolder() = default;
    GetEntityProfilesResponseHolder(const GetEntityProfilesResponseHolder&) = delete;
    GetEntityProfilesResponseHolder(GetEntityProfilesResponseHolder&&) = default;
    GetEntityProfilesResponseHolder& operator=(const GetEntityProfilesResponseHolder&) = delete;
    GetEntityProfilesResponseHolder& operator=(GetEntityProfilesResponseHolder&&) = default;
    ~GetEntityProfilesResponseHolder() = default;

    PFProfilesGetEntityProfilesResponse* result{ nullptr };
};

struct GetTitlePlayersFromMasterPlayerAccountIdsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetTitlePlayersFromMasterPlayerAccountIdsResponseHolder>
{
    GetTitlePlayersFromMasterPlayerAccountIdsResponseHolder() = default;
    GetTitlePlayersFromMasterPlayerAccountIdsResponseHolder(const GetTitlePlayersFromMasterPlayerAccountIdsResponseHolder&) = delete;
    GetTitlePlayersFromMasterPlayerAccountIdsResponseHolder(GetTitlePlayersFromMasterPlayerAccountIdsResponseHolder&&) = default;
    GetTitlePlayersFromMasterPlayerAccountIdsResponseHolder& operator=(const GetTitlePlayersFromMasterPlayerAccountIdsResponseHolder&) = delete;
    GetTitlePlayersFromMasterPlayerAccountIdsResponseHolder& operator=(GetTitlePlayersFromMasterPlayerAccountIdsResponseHolder&&) = default;
    ~GetTitlePlayersFromMasterPlayerAccountIdsResponseHolder() = default;

    PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse* result{ nullptr };
};

struct SetProfileLanguageResponseHolder : public XAsyncResult, public std::enable_shared_from_this<SetProfileLanguageResponseHolder>
{
    SetProfileLanguageResponseHolder() = default;
    SetProfileLanguageResponseHolder(const SetProfileLanguageResponseHolder&) = delete;
    SetProfileLanguageResponseHolder(SetProfileLanguageResponseHolder&&) = default;
    SetProfileLanguageResponseHolder& operator=(const SetProfileLanguageResponseHolder&) = delete;
    SetProfileLanguageResponseHolder& operator=(SetProfileLanguageResponseHolder&&) = default;
    ~SetProfileLanguageResponseHolder() = default;

    PFProfilesSetProfileLanguageResponse* result{ nullptr };
};

struct SetEntityProfilePolicyResponseHolder : public XAsyncResult, public std::enable_shared_from_this<SetEntityProfilePolicyResponseHolder>
{
    SetEntityProfilePolicyResponseHolder() = default;
    SetEntityProfilePolicyResponseHolder(const SetEntityProfilePolicyResponseHolder&) = delete;
    SetEntityProfilePolicyResponseHolder(SetEntityProfilePolicyResponseHolder&&) = default;
    SetEntityProfilePolicyResponseHolder& operator=(const SetEntityProfilePolicyResponseHolder&) = delete;
    SetEntityProfilePolicyResponseHolder& operator=(SetEntityProfilePolicyResponseHolder&&) = default;
    ~SetEntityProfilePolicyResponseHolder() = default;

    PFProfilesSetEntityProfilePolicyResponse* result{ nullptr };
};


}
