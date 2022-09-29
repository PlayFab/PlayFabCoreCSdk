#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


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
