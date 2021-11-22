#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct AddServerBuildResultHolder : public XAsyncResult, public std::enable_shared_from_this<AddServerBuildResultHolder>
{
    AddServerBuildResultHolder() = default;
    AddServerBuildResultHolder(const AddServerBuildResultHolder&) = delete;
    AddServerBuildResultHolder(AddServerBuildResultHolder&&) = default;
    AddServerBuildResultHolder& operator=(const AddServerBuildResultHolder&) = delete;
    AddServerBuildResultHolder& operator=(AddServerBuildResultHolder&&) = default;
    ~AddServerBuildResultHolder() = default;

    PFGameServerAddServerBuildResult* result{ nullptr };
};

struct GetServerBuildInfoResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetServerBuildInfoResultHolder>
{
    GetServerBuildInfoResultHolder() = default;
    GetServerBuildInfoResultHolder(const GetServerBuildInfoResultHolder&) = delete;
    GetServerBuildInfoResultHolder(GetServerBuildInfoResultHolder&&) = default;
    GetServerBuildInfoResultHolder& operator=(const GetServerBuildInfoResultHolder&) = delete;
    GetServerBuildInfoResultHolder& operator=(GetServerBuildInfoResultHolder&&) = default;
    ~GetServerBuildInfoResultHolder() = default;

    PFGameServerGetServerBuildInfoResult* result{ nullptr };
};

struct GetServerBuildUploadURLResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetServerBuildUploadURLResultHolder>
{
    GetServerBuildUploadURLResultHolder() = default;
    GetServerBuildUploadURLResultHolder(const GetServerBuildUploadURLResultHolder&) = delete;
    GetServerBuildUploadURLResultHolder(GetServerBuildUploadURLResultHolder&&) = default;
    GetServerBuildUploadURLResultHolder& operator=(const GetServerBuildUploadURLResultHolder&) = delete;
    GetServerBuildUploadURLResultHolder& operator=(GetServerBuildUploadURLResultHolder&&) = default;
    ~GetServerBuildUploadURLResultHolder() = default;

    PFGameServerGetServerBuildUploadURLResult* result{ nullptr };
};

struct ListBuildsResultHolder : public XAsyncResult, public std::enable_shared_from_this<ListBuildsResultHolder>
{
    ListBuildsResultHolder() = default;
    ListBuildsResultHolder(const ListBuildsResultHolder&) = delete;
    ListBuildsResultHolder(ListBuildsResultHolder&&) = default;
    ListBuildsResultHolder& operator=(const ListBuildsResultHolder&) = delete;
    ListBuildsResultHolder& operator=(ListBuildsResultHolder&&) = default;
    ~ListBuildsResultHolder() = default;

    PFGameServerListBuildsResult* result{ nullptr };
};

struct ModifyServerBuildResultHolder : public XAsyncResult, public std::enable_shared_from_this<ModifyServerBuildResultHolder>
{
    ModifyServerBuildResultHolder() = default;
    ModifyServerBuildResultHolder(const ModifyServerBuildResultHolder&) = delete;
    ModifyServerBuildResultHolder(ModifyServerBuildResultHolder&&) = default;
    ModifyServerBuildResultHolder& operator=(const ModifyServerBuildResultHolder&) = delete;
    ModifyServerBuildResultHolder& operator=(ModifyServerBuildResultHolder&&) = default;
    ~ModifyServerBuildResultHolder() = default;

    PFGameServerModifyServerBuildResult* result{ nullptr };
};


}
