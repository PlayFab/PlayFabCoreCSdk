#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct GetCloudScriptRevisionResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetCloudScriptRevisionResultHolder>
{
    GetCloudScriptRevisionResultHolder() = default;
    GetCloudScriptRevisionResultHolder(const GetCloudScriptRevisionResultHolder&) = delete;
    GetCloudScriptRevisionResultHolder(GetCloudScriptRevisionResultHolder&&) = default;
    GetCloudScriptRevisionResultHolder& operator=(const GetCloudScriptRevisionResultHolder&) = delete;
    GetCloudScriptRevisionResultHolder& operator=(GetCloudScriptRevisionResultHolder&&) = default;
    ~GetCloudScriptRevisionResultHolder() = default;

    PFCloudScriptGetCloudScriptRevisionResult* result{ nullptr };
};

struct GetCloudScriptVersionsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetCloudScriptVersionsResultHolder>
{
    GetCloudScriptVersionsResultHolder() = default;
    GetCloudScriptVersionsResultHolder(const GetCloudScriptVersionsResultHolder&) = delete;
    GetCloudScriptVersionsResultHolder(GetCloudScriptVersionsResultHolder&&) = default;
    GetCloudScriptVersionsResultHolder& operator=(const GetCloudScriptVersionsResultHolder&) = delete;
    GetCloudScriptVersionsResultHolder& operator=(GetCloudScriptVersionsResultHolder&&) = default;
    ~GetCloudScriptVersionsResultHolder() = default;

    PFCloudScriptGetCloudScriptVersionsResult* result{ nullptr };
};

struct UpdateCloudScriptResultHolder : public XAsyncResult, public std::enable_shared_from_this<UpdateCloudScriptResultHolder>
{
    UpdateCloudScriptResultHolder() = default;
    UpdateCloudScriptResultHolder(const UpdateCloudScriptResultHolder&) = default;
    UpdateCloudScriptResultHolder(UpdateCloudScriptResultHolder&&) = default;
    UpdateCloudScriptResultHolder& operator=(const UpdateCloudScriptResultHolder&) = default;
    UpdateCloudScriptResultHolder& operator=(UpdateCloudScriptResultHolder&&) = default;
    ~UpdateCloudScriptResultHolder() = default;

    PFCloudScriptUpdateCloudScriptResult result{};
};

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

struct GetFunctionResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetFunctionResultHolder>
{
    GetFunctionResultHolder() = default;
    GetFunctionResultHolder(const GetFunctionResultHolder&) = delete;
    GetFunctionResultHolder(GetFunctionResultHolder&&) = default;
    GetFunctionResultHolder& operator=(const GetFunctionResultHolder&) = delete;
    GetFunctionResultHolder& operator=(GetFunctionResultHolder&&) = default;
    ~GetFunctionResultHolder() = default;

    PFCloudScriptGetFunctionResult* result{ nullptr };
};

struct ListFunctionsResultHolder : public XAsyncResult, public std::enable_shared_from_this<ListFunctionsResultHolder>
{
    ListFunctionsResultHolder() = default;
    ListFunctionsResultHolder(const ListFunctionsResultHolder&) = delete;
    ListFunctionsResultHolder(ListFunctionsResultHolder&&) = default;
    ListFunctionsResultHolder& operator=(const ListFunctionsResultHolder&) = delete;
    ListFunctionsResultHolder& operator=(ListFunctionsResultHolder&&) = default;
    ~ListFunctionsResultHolder() = default;

    PFCloudScriptListFunctionsResult* result{ nullptr };
};

struct ListHttpFunctionsResultHolder : public XAsyncResult, public std::enable_shared_from_this<ListHttpFunctionsResultHolder>
{
    ListHttpFunctionsResultHolder() = default;
    ListHttpFunctionsResultHolder(const ListHttpFunctionsResultHolder&) = delete;
    ListHttpFunctionsResultHolder(ListHttpFunctionsResultHolder&&) = default;
    ListHttpFunctionsResultHolder& operator=(const ListHttpFunctionsResultHolder&) = delete;
    ListHttpFunctionsResultHolder& operator=(ListHttpFunctionsResultHolder&&) = default;
    ~ListHttpFunctionsResultHolder() = default;

    PFCloudScriptListHttpFunctionsResult* result{ nullptr };
};

struct ListQueuedFunctionsResultHolder : public XAsyncResult, public std::enable_shared_from_this<ListQueuedFunctionsResultHolder>
{
    ListQueuedFunctionsResultHolder() = default;
    ListQueuedFunctionsResultHolder(const ListQueuedFunctionsResultHolder&) = delete;
    ListQueuedFunctionsResultHolder(ListQueuedFunctionsResultHolder&&) = default;
    ListQueuedFunctionsResultHolder& operator=(const ListQueuedFunctionsResultHolder&) = delete;
    ListQueuedFunctionsResultHolder& operator=(ListQueuedFunctionsResultHolder&&) = default;
    ~ListQueuedFunctionsResultHolder() = default;

    PFCloudScriptListQueuedFunctionsResult* result{ nullptr };
};


}
