#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct ExecuteFunctionResultHolder : public XAsyncResult, public std::enable_shared_from_this<ExecuteFunctionResultHolder>
{
    ExecuteFunctionResultHolder() = default;
    ExecuteFunctionResultHolder(const ExecuteFunctionResultHolder&) = delete;
    ExecuteFunctionResultHolder(ExecuteFunctionResultHolder&&) = default;
    ExecuteFunctionResultHolder& operator=(const ExecuteFunctionResultHolder&) = delete;
    ExecuteFunctionResultHolder& operator=(ExecuteFunctionResultHolder&&) = default;
    ~ExecuteFunctionResultHolder() = default;

    PFCloudScriptExecuteFunctionResult* result{ nullptr };
};


}
