// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFLobbyDataModels.h>
#include <playfab/PFGlobal.h>
#include <playfab/PFTitlePlayer.h>

extern "C"
{

/// <summary>
/// Create a lobby.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Creates a multiplayer lobby. The caller is the lobby creator. Caller may be a server or player entity.
///
/// If successful, call <see cref="PFLobbyCreateLobbyGetResult"/> to get the result.
/// </remarks>
HRESULT PFLobbyCreateLobbyAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFLobbyCreateLobbyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a CreateLobby call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLobbyCreateLobbyGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLobbyCreateLobbyAsync call.
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
HRESULT PFLobbyCreateLobbyGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLobbyCreateLobbyResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Delete a lobby.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Delete a lobby. This method is only callable by servers.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFLobbyDeleteLobbyAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFLobbyDeleteLobbyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Find lobbies which match certain criteria, and which friends are in.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Find lobbies which match certain criteria and contain friends of the caller. Friends optionally include
/// Steam, Facebook and Xbox friends. Returns a maximum of 50 instances for client calls. This method
/// is not callable by servers.
///
/// If successful, call <see cref="PFLobbyFindFriendLobbiesGetResult"/> to get the result.
/// </remarks>
HRESULT PFLobbyFindFriendLobbiesAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFLobbyFindFriendLobbiesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a FindFriendLobbies call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLobbyFindFriendLobbiesGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLobbyFindFriendLobbiesAsync call.
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
HRESULT PFLobbyFindFriendLobbiesGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLobbyFindFriendLobbiesResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Find all the lobbies that match certain criteria.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Find lobbies which match certain criteria. Returns a maximum of 500 entries for server callers, and
/// 50 entries for client callers.
///
/// If successful, call <see cref="PFLobbyFindLobbiesGetResult"/> to get the result.
/// </remarks>
HRESULT PFLobbyFindLobbiesAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFLobbyFindLobbiesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a FindLobbies call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLobbyFindLobbiesGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLobbyFindLobbiesAsync call.
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
HRESULT PFLobbyFindLobbiesGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLobbyFindLobbiesResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Get a lobby.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFLobbyGetLobbyGetResult"/> to get the result.
/// </remarks>
HRESULT PFLobbyGetLobbyAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFLobbyGetLobbyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetLobby call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLobbyGetLobbyGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLobbyGetLobbyAsync call.
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
HRESULT PFLobbyGetLobbyGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLobbyGetLobbyResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Send a notification to invite a player to a lobby.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Invite a player to a lobby the caller is already a member of. Only players may call this.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFLobbyInviteToLobbyAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFLobbyInviteToLobbyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Join an Arranged lobby.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFLobbyJoinArrangedLobbyGetResult"/> to get the result.
/// </remarks>
HRESULT PFLobbyJoinArrangedLobbyAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFLobbyJoinArrangedLobbyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a JoinArrangedLobby call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLobbyJoinArrangedLobbyGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLobbyJoinArrangedLobbyAsync call.
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
HRESULT PFLobbyJoinArrangedLobbyGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLobbyJoinLobbyResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Join a lobby.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFLobbyJoinLobbyGetResult"/> to get the result.
/// </remarks>
HRESULT PFLobbyJoinLobbyAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFLobbyJoinLobbyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a JoinLobby call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLobbyJoinLobbyGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLobbyJoinLobbyAsync call.
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
HRESULT PFLobbyJoinLobbyGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLobbyJoinLobbyResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Leave a lobby.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Leave a lobby. Members will also be automatically unsubscribed from the lobby.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFLobbyLeaveLobbyAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFLobbyLeaveLobbyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Remove a member from a lobby.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Remove another member from a lobby. Owners and servers may remove any member from a lobby. Members
/// cannot remove themselves but they can use LeaveLobby instead. Members are also unsubscribed from the
/// lobby.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFLobbyRemoveMemberAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFLobbyRemoveMemberFromLobbyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Subscribe to lobby resource notifications.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Subscribe to lobby resource notifications. Lobby subscriptions have two types; LobbyChange and LobbyInvite.
///
/// If successful, call <see cref="PFLobbySubscribeToLobbyResourceGetResult"/> to get the result.
/// </remarks>
HRESULT PFLobbySubscribeToLobbyResourceAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFLobbySubscribeToLobbyResourceRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a SubscribeToLobbyResource call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLobbySubscribeToLobbyResourceGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLobbySubscribeToLobbyResourceAsync call.
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
HRESULT PFLobbySubscribeToLobbyResourceGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLobbySubscribeToLobbyResourceResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Unsubscribe from lobby notifications.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Unsubscribe from lobby notifications.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFLobbyUnsubscribeFromLobbyResourceAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFLobbyUnsubscribeFromLobbyResourceRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Update a lobby.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFLobbyUpdateLobbyAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFLobbyUpdateLobbyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;


}