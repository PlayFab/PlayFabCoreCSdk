#include "stdafx.h"
#include <playfab/PFFriends.h>
#include "Friends.h"
#include "ApiAsyncProviders.h"
#include "GlobalState.h"
#include "Entity.h"

using namespace PlayFab;
using namespace PlayFab::Friends;

HRESULT PFFriendsClientAddFriendAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFFriendsClientAddFriendRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&FriendsAPI::ClientAddFriend, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFFriendsClientAddFriendGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFFriendsAddFriendResult* result
) noexcept
{
    return XAsyncGetResult(async, nullptr, sizeof(PFFriendsAddFriendResult), result, nullptr);
}

HRESULT PFFriendsClientGetFriendsListAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFFriendsClientGetFriendsListRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&FriendsAPI::ClientGetFriendsList, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFFriendsClientGetFriendsListGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFFriendsClientGetFriendsListGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFFriendsGetFriendsListResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFFriendsGetFriendsListResult*>(buffer);

    return S_OK;
}

HRESULT PFFriendsClientRemoveFriendAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFFriendsClientRemoveFriendRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&FriendsAPI::ClientRemoveFriend, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFFriendsClientSetFriendTagsAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFFriendsClientSetFriendTagsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&FriendsAPI::ClientSetFriendTags, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFFriendsServerAddFriendAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFFriendsServerAddFriendRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&FriendsAPI::ServerAddFriend, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFFriendsServerGetFriendsListAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFFriendsServerGetFriendsListRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&FriendsAPI::ServerGetFriendsList, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFFriendsServerGetFriendsListGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFFriendsServerGetFriendsListGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFFriendsGetFriendsListResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFFriendsGetFriendsListResult*>(buffer);

    return S_OK;
}

HRESULT PFFriendsServerRemoveFriendAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFFriendsServerRemoveFriendRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&FriendsAPI::ServerRemoveFriend, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFFriendsServerSetFriendTagsAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFFriendsServerSetFriendTagsRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&FriendsAPI::ServerSetFriendTags, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

