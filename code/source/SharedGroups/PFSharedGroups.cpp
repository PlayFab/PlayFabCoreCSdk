#include "stdafx.h"
#include <playfab/PFSharedGroups.h>
#include "SharedGroups.h"
#include "ApiAsyncProviders.h"
#include "GlobalState.h"
#include "Entity.h"

using namespace PlayFab;
using namespace PlayFab::SharedGroups;

HRESULT PFSharedGroupsClientAddSharedGroupMembersAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFSharedGroupsAddSharedGroupMembersRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&SharedGroupsAPI::ClientAddSharedGroupMembers, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFSharedGroupsClientCreateSharedGroupAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFSharedGroupsCreateSharedGroupRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&SharedGroupsAPI::ClientCreateSharedGroup, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFSharedGroupsClientCreateSharedGroupGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFSharedGroupsClientCreateSharedGroupGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFSharedGroupsCreateSharedGroupResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFSharedGroupsCreateSharedGroupResult*>(buffer);

    return S_OK;
}

HRESULT PFSharedGroupsClientGetSharedGroupDataAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFSharedGroupsGetSharedGroupDataRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&SharedGroupsAPI::ClientGetSharedGroupData, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFSharedGroupsClientGetSharedGroupDataGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFSharedGroupsClientGetSharedGroupDataGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFSharedGroupsGetSharedGroupDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFSharedGroupsGetSharedGroupDataResult*>(buffer);

    return S_OK;
}

HRESULT PFSharedGroupsClientRemoveSharedGroupMembersAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFSharedGroupsRemoveSharedGroupMembersRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&SharedGroupsAPI::ClientRemoveSharedGroupMembers, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFSharedGroupsClientUpdateSharedGroupDataAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFSharedGroupsUpdateSharedGroupDataRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&SharedGroupsAPI::ClientUpdateSharedGroupData, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFSharedGroupsServerAddSharedGroupMembersAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFSharedGroupsAddSharedGroupMembersRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&SharedGroupsAPI::ServerAddSharedGroupMembers, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFSharedGroupsServerCreateSharedGroupAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFSharedGroupsCreateSharedGroupRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&SharedGroupsAPI::ServerCreateSharedGroup, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFSharedGroupsServerCreateSharedGroupGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFSharedGroupsServerCreateSharedGroupGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFSharedGroupsCreateSharedGroupResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFSharedGroupsCreateSharedGroupResult*>(buffer);

    return S_OK;
}

HRESULT PFSharedGroupsServerDeleteSharedGroupAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFSharedGroupsDeleteSharedGroupRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&SharedGroupsAPI::ServerDeleteSharedGroup, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFSharedGroupsServerGetSharedGroupDataAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFSharedGroupsGetSharedGroupDataRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&SharedGroupsAPI::ServerGetSharedGroupData, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFSharedGroupsServerGetSharedGroupDataGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFSharedGroupsServerGetSharedGroupDataGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFSharedGroupsGetSharedGroupDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFSharedGroupsGetSharedGroupDataResult*>(buffer);

    return S_OK;
}

HRESULT PFSharedGroupsServerRemoveSharedGroupMembersAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFSharedGroupsRemoveSharedGroupMembersRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&SharedGroupsAPI::ServerRemoveSharedGroupMembers, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFSharedGroupsServerUpdateSharedGroupDataAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFSharedGroupsUpdateSharedGroupDataRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&SharedGroupsAPI::ServerUpdateSharedGroupData, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

