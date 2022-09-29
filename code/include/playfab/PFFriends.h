// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFFriendsDataModels.h>
#include <playfab/PFGlobal.h>
#include <playfab/PFTitlePlayer.h>

extern "C"
{

/// <summary>
/// Adds the PlayFab user, based upon a match against a supplied unique identifier, to the friend list
/// of the local user. At least one of FriendPlayFabId,FriendUsername,FriendEmail, or FriendTitleDisplayName
/// should be initialized.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientGetFriendsListAsync, ClientSetFriendTagsAsync.
///
/// If successful, call <see cref="PFFriendsClientAddFriendGetResult"/> to get the result.
/// </remarks>
HRESULT PFFriendsClientAddFriendAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFFriendsClientAddFriendRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFFriendsClientAddFriendAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFFriendsAddFriendResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFFriendsClientAddFriendGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFFriendsAddFriendResult* result
) noexcept;

/// <summary>
/// Retrieves the current friend list for the local user, constrained to users who have PlayFab accounts.
/// Friends from linked accounts (Facebook, Steam) are also included. You may optionally exclude some
/// linked services' friends.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientAddFriendAsync, ClientGetPlayerProfileAsync, ClientRemoveFriendAsync.
///
/// If successful, call <see cref="PFFriendsClientGetFriendsListGetResult"/> to get the result.
/// </remarks>
HRESULT PFFriendsClientGetFriendsListAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFFriendsClientGetFriendsListRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetFriendsList call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFFriendsClientGetFriendsListGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFFriendsClientGetFriendsListAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFFriendsClientGetFriendsListGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFFriendsGetFriendsListResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Removes a specified user from the friend list of the local user
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientAddFriendAsync, ClientSetFriendTagsAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFFriendsClientRemoveFriendAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFFriendsClientRemoveFriendRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Updates the tag list for a specified user in the friend list of the local user
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This operation is not additive. It will completely replace the tag list for the specified user. Please
/// note that only users in the PlayFab friends list can be assigned tags. Attempting to set a tag on
/// a friend only included in the friends list from a social site integration (such as Facebook or Steam)
/// will return the AccountNotFound error. See also ClientAddFriendAsync, ClientRemoveFriendAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFFriendsClientSetFriendTagsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFFriendsClientSetFriendTagsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Adds the Friend user to the friendlist of the user with PlayFabId. At least one of FriendPlayFabId,FriendUsername,FriendEmail,
/// or FriendTitleDisplayName should be initialized.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFFriendsServerAddFriendAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFFriendsServerAddFriendRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the current friends for the user with PlayFabId, constrained to users who have PlayFab
/// accounts. Friends from linked accounts (Facebook, Steam) are also included. You may optionally exclude
/// some linked services' friends.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFFriendsServerGetFriendsListGetResult"/> to get the result.
/// </remarks>
HRESULT PFFriendsServerGetFriendsListAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFFriendsServerGetFriendsListRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetFriendsList call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFFriendsServerGetFriendsListGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFFriendsServerGetFriendsListAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFFriendsServerGetFriendsListGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFFriendsGetFriendsListResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Removes the specified friend from the the user's friend list
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFFriendsServerRemoveFriendAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFFriendsServerRemoveFriendRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the tag list for a specified user in the friend list of another user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This operation is not additive. It will completely replace the tag list for the specified user. Please
/// note that only users in the PlayFab friends list can be assigned tags. Attempting to set a tag on
/// a friend only included in the friends list from a social site integration (such as Facebook or Steam)
/// will return the AccountNotFound error.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFFriendsServerSetFriendTagsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFFriendsServerSetFriendTagsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif


}