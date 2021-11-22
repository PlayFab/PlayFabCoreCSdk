#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct CreateSharedGroupResultHolder : public XAsyncResult, public std::enable_shared_from_this<CreateSharedGroupResultHolder>
{
    CreateSharedGroupResultHolder() = default;
    CreateSharedGroupResultHolder(const CreateSharedGroupResultHolder&) = delete;
    CreateSharedGroupResultHolder(CreateSharedGroupResultHolder&&) = default;
    CreateSharedGroupResultHolder& operator=(const CreateSharedGroupResultHolder&) = delete;
    CreateSharedGroupResultHolder& operator=(CreateSharedGroupResultHolder&&) = default;
    ~CreateSharedGroupResultHolder() = default;

    PFSharedGroupsCreateSharedGroupResult* result{ nullptr };
};

struct GetSharedGroupDataResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetSharedGroupDataResultHolder>
{
    GetSharedGroupDataResultHolder() = default;
    GetSharedGroupDataResultHolder(const GetSharedGroupDataResultHolder&) = delete;
    GetSharedGroupDataResultHolder(GetSharedGroupDataResultHolder&&) = default;
    GetSharedGroupDataResultHolder& operator=(const GetSharedGroupDataResultHolder&) = delete;
    GetSharedGroupDataResultHolder& operator=(GetSharedGroupDataResultHolder&&) = default;
    ~GetSharedGroupDataResultHolder() = default;

    PFSharedGroupsGetSharedGroupDataResult* result{ nullptr };
};


}
