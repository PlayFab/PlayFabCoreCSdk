// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFMatchmakingDataModels.h>
#include <playfab/PFGlobal.h>
#include <playfab/PFTitlePlayer.h>

extern "C"
{

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the details for a specific completed session, including links to standard out and standard
/// error logs
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminGetMatchmakerGameModesAsync, AdminModifyMatchmakerGameModesAsync.
///
/// If successful, call <see cref="PFMatchmakingAdminGetMatchmakerGameInfoGetResult"/> to get the result.
/// </remarks>
HRESULT PFMatchmakingAdminGetMatchmakerGameInfoAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFMatchmakingGetMatchmakerGameInfoRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetMatchmakerGameInfo call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingAdminGetMatchmakerGameInfoGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingAdminGetMatchmakerGameInfoAsync call.
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
HRESULT PFMatchmakingAdminGetMatchmakerGameInfoGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingGetMatchmakerGameInfoResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the details of defined game modes for the specified game server executable
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// These details are used by the PlayFab matchmaking service to determine if an existing Game Server
/// Instance has room for additional users, and by the PlayFab game server management service to determine
/// when a new Game Server Host should be created in order to prevent excess load on existing Hosts. See
/// also AdminGetMatchmakerGameInfoAsync, AdminModifyMatchmakerGameModesAsync.
///
/// If successful, call <see cref="PFMatchmakingAdminGetMatchmakerGameModesGetResult"/> to get the result.
/// </remarks>
HRESULT PFMatchmakingAdminGetMatchmakerGameModesAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFMatchmakingGetMatchmakerGameModesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetMatchmakerGameModes call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingAdminGetMatchmakerGameModesGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingAdminGetMatchmakerGameModesAsync call.
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
HRESULT PFMatchmakingAdminGetMatchmakerGameModesGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingGetMatchmakerGameModesResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the game server mode details for the specified game server executable
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// These details are used by the PlayFab matchmaking service to determine if an existing Game Server
/// Instance has room for additional users, and by the PlayFab game server management service to determine
/// when a new Game Server Host should be created in order to prevent excess load on existing Hosts. This
/// operation is not additive. Using it will cause the game mode definition for the game server executable
/// in question to be created from scratch. If there is an existing game server mode definition for the
/// given BuildVersion, it will be deleted and replaced with the data specified in this call. See also
/// AdminGetMatchmakerGameInfoAsync, AdminGetMatchmakerGameModesAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMatchmakingAdminModifyMatchmakerGameModesAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFMatchmakingModifyMatchmakerGameModesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Get details about all current running game servers matching the given parameters.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminAddServerBuildAsync, ClientGetGameServerRegionsAsync, ClientMatchmakeAsync, AdminRemoveServerBuildAsync,
/// ClientStartGameAsync.
///
/// If successful, call <see cref="PFMatchmakingClientGetCurrentGamesGetResult"/> to get the result.
/// </remarks>
HRESULT PFMatchmakingClientGetCurrentGamesAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFMatchmakingCurrentGamesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetCurrentGames call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingClientGetCurrentGamesGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingClientGetCurrentGamesAsync call.
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
HRESULT PFMatchmakingClientGetCurrentGamesGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingCurrentGamesResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
///  Get details about the regions hosting game servers matching the given parameters.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminAddServerBuildAsync, ClientGetCurrentGamesAsync, ClientMatchmakeAsync, AdminRemoveServerBuildAsync,
/// ClientStartGameAsync.
///
/// If successful, call <see cref="PFMatchmakingClientGetGameServerRegionsGetResult"/> to get the result.
/// </remarks>
HRESULT PFMatchmakingClientGetGameServerRegionsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFMatchmakingGameServerRegionsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetGameServerRegions call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingClientGetGameServerRegionsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingClientGetGameServerRegionsAsync call.
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
HRESULT PFMatchmakingClientGetGameServerRegionsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingGameServerRegionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Attempts to locate a game session matching the given parameters. If the goal is to match the player
/// into a specific active session, only the LobbyId is required. Otherwise, the BuildVersion, GameMode,
/// and Region are all required parameters. Note that parameters specified in the search are required
/// (they are not weighting factors). If a slot is found in a server instance matching the parameters,
/// the slot will be assigned to that player, removing it from the availabe set. In that case, the information
/// on the game session will be returned, otherwise the Status returned will be GameNotFound.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminAddServerBuildAsync, ClientGetCurrentGamesAsync, ClientGetGameServerRegionsAsync, AdminRemoveServerBuildAsync,
/// ClientStartGameAsync.
///
/// If successful, call <see cref="PFMatchmakingClientMatchmakeGetResult"/> to get the result.
/// </remarks>
HRESULT PFMatchmakingClientMatchmakeAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFMatchmakingMatchmakeRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientMatchmake call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingClientMatchmakeGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingClientMatchmakeAsync call.
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
HRESULT PFMatchmakingClientMatchmakeGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingMatchmakeResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Start a new game server with a given configuration, add the current player and return the connection
/// information.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API must be enabled for use as an option in the game manager website. It is disabled by default.
/// See also AdminAddServerBuildAsync, ClientGetCurrentGamesAsync, ClientGetGameServerRegionsAsync, ClientMatchmakeAsync,
/// AdminRemoveServerBuildAsync.
///
/// If successful, call <see cref="PFMatchmakingClientStartGameGetResult"/> to get the result.
/// </remarks>
HRESULT PFMatchmakingClientStartGameAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFMatchmakingClientStartGameRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientStartGame call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingClientStartGameGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingClientStartGameAsync call.
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
HRESULT PFMatchmakingClientStartGameGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingStartGameResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Validates a user with the PlayFab service
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API allows the external match-making service to confirm that the user has a valid Session Ticket
/// for the title, in order to securely enable match-making. The client passes the user's Session Ticket
/// to the external match-making service, which then passes the Session Ticket in as the AuthorizationTicket
/// in this call. See also MatchmakerPlayerJoinedAsync, MatchmakerPlayerLeftAsync, MatchmakerStartGameAsync,
/// MatchmakerUserInfoAsync.
///
/// If successful, call <see cref="PFMatchmakingAuthUserGetResult"/> to get the result.
/// </remarks>
HRESULT PFMatchmakingAuthUserAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFMatchmakingAuthUserRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AuthUser call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingAuthUserGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingAuthUserAsync call.
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
HRESULT PFMatchmakingAuthUserGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingAuthUserResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Informs the PlayFab game server hosting service that the indicated user has joined the Game Server
/// Instance specified
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also MatchmakerAuthUserAsync, MatchmakerPlayerLeftAsync, MatchmakerStartGameAsync, MatchmakerUserInfoAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMatchmakingPlayerJoinedAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFMatchmakingPlayerJoinedRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Informs the PlayFab game server hosting service that the indicated user has left the Game Server
/// Instance specified
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also MatchmakerAuthUserAsync, MatchmakerPlayerJoinedAsync, MatchmakerStartGameAsync, MatchmakerUserInfoAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMatchmakingPlayerLeftAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFMatchmakingPlayerLeftRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Instructs the PlayFab game server hosting service to instantiate a new Game Server Instance
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also MatchmakerAuthUserAsync, MatchmakerPlayerJoinedAsync, MatchmakerPlayerLeftAsync, MatchmakerUserInfoAsync.
///
/// If successful, call <see cref="PFMatchmakingStartGameGetResult"/> to get the result.
/// </remarks>
HRESULT PFMatchmakingStartGameAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFMatchmakingMatchmakerStartGameRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a StartGame call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingStartGameGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingStartGameAsync call.
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
HRESULT PFMatchmakingStartGameGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingStartGameResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the relevant details for a specified user, which the external match-making service can
/// then use to compute effective matches
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also MatchmakerAuthUserAsync, MatchmakerPlayerJoinedAsync, MatchmakerPlayerLeftAsync, MatchmakerStartGameAsync.
///
/// If successful, call <see cref="PFMatchmakingUserInfoGetResult"/> to get the result.
/// </remarks>
HRESULT PFMatchmakingUserInfoAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFMatchmakingUserInfoRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a UserInfo call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingUserInfoGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingUserInfoAsync call.
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
HRESULT PFMatchmakingUserInfoGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingUserInfoResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Inform the matchmaker that a Game Server Instance is removed.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerRegisterGameAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMatchmakingServerDeregisterGameAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFMatchmakingDeregisterGameRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Informs the PlayFab match-making service that the user specified has left the Game Server Instance
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFMatchmakingServerNotifyMatchmakerPlayerLeftGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFMatchmakingServerNotifyMatchmakerPlayerLeftAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFMatchmakingNotifyMatchmakerPlayerLeftRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerNotifyMatchmakerPlayerLeft call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingServerNotifyMatchmakerPlayerLeftGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingServerNotifyMatchmakerPlayerLeftAsync call.
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
HRESULT PFMatchmakingServerNotifyMatchmakerPlayerLeftGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingNotifyMatchmakerPlayerLeftResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Validates a Game Server session ticket and returns details about the user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function is used by a Game Server Instance to validate with the PlayFab service that a user
/// has been registered as connected to the server. The Ticket is provided to the client either as a result
/// of a call to StartGame or Matchmake, each of which return a Ticket specific to the Game Server Instance.
/// This function will fail in any case where the Ticket presented is not valid for the specific Game
/// Server Instance making the call. Note that data returned may be Personally Identifying Information
/// (PII), such as email address, and so care should be taken in how this data is stored and managed.
/// Since this call will always return the relevant information for users who have accessed the title,
/// the recommendation is to not store this data locally.
///
/// If successful, call <see cref="PFMatchmakingServerRedeemMatchmakerTicketGetResult"/> to get the result.
/// </remarks>
HRESULT PFMatchmakingServerRedeemMatchmakerTicketAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFMatchmakingRedeemMatchmakerTicketRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerRedeemMatchmakerTicket call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingServerRedeemMatchmakerTicketGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingServerRedeemMatchmakerTicketAsync call.
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
HRESULT PFMatchmakingServerRedeemMatchmakerTicketGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingRedeemMatchmakerTicketResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Set the state of the indicated Game Server Instance. Also update the heartbeat for the instance.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMatchmakingServerRefreshGameServerInstanceHeartbeatAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFMatchmakingRefreshGameServerInstanceHeartbeatRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Inform the matchmaker that a new Game Server Instance is added.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerDeregisterGameAsync.
///
/// If successful, call <see cref="PFMatchmakingServerRegisterGameGetResult"/> to get the result.
/// </remarks>
HRESULT PFMatchmakingServerRegisterGameAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFMatchmakingRegisterGameRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerRegisterGame call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingServerRegisterGameGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingServerRegisterGameAsync call.
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
HRESULT PFMatchmakingServerRegisterGameGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingRegisterGameResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Sets the custom data of the indicated Game Server Instance
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMatchmakingServerSetGameServerInstanceDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFMatchmakingSetGameServerInstanceDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Set the state of the indicated Game Server Instance.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMatchmakingServerSetGameServerInstanceStateAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFMatchmakingSetGameServerInstanceStateRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Set custom tags for the specified Game Server Instance
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMatchmakingServerSetGameServerInstanceTagsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFMatchmakingSetGameServerInstanceTagsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Cancel all active tickets the player is a member of in a given queue.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Cancels all tickets of which the player is a member in a given queue that are not cancelled or matched.
/// This API is useful if you lose track of what tickets the player is a member of (if the title crashes
/// for instance) and want to 'reset'. The Entity field is optional if the caller is a player and defaults
/// to that player. Players may not cancel tickets for other people. The Entity field is required if the
/// caller is a server (authenticated as the title).
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMatchmakingCancelAllMatchmakingTicketsForPlayerAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Cancel all active backfill tickets the player is a member of in a given queue.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Cancels all backfill tickets of which the player is a member in a given queue that are not cancelled
/// or matched. This API is useful if you lose track of what tickets the player is a member of (if the
/// server crashes for instance) and want to 'reset'.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMatchmakingCancelAllServerBackfillTicketsForPlayerAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Cancel a matchmaking ticket.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Only servers and ticket members can cancel a ticket. The ticket can be in five different states when
/// it is cancelled. 1: the ticket is waiting for members to join it, and it has not started matching.
/// If the ticket is cancelled at this stage, it will never match. 2: the ticket is matching. If the ticket
/// is cancelled, it will stop matching. 3: the ticket is matched. A matched ticket cannot be cancelled.
/// 4: the ticket is already cancelled and nothing happens. 5: the ticket is waiting for a server. If
/// the ticket is cancelled, server allocation will be stopped. A server may still be allocated due to
/// a race condition, but that will not be reflected in the ticket. There may be race conditions between
/// the ticket getting matched and the client making a cancellation request. The client must handle the
/// possibility that the cancel request fails if a match is found before the cancellation request is processed.
/// We do not allow resubmitting a cancelled ticket because players must consent to enter matchmaking
/// again. Create a new ticket instead.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMatchmakingCancelMatchmakingTicketAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMatchmakingCancelMatchmakingTicketRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Cancel a server backfill ticket.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Only servers can cancel a backfill ticket. The ticket can be in three different states when it is
/// cancelled. 1: the ticket is matching. If the ticket is cancelled, it will stop matching. 2: the ticket
/// is matched. A matched ticket cannot be cancelled. 3: the ticket is already cancelled and nothing happens.
/// There may be race conditions between the ticket getting matched and the server making a cancellation
/// request. The server must handle the possibility that the cancel request fails if a match is found
/// before the cancellation request is processed. We do not allow resubmitting a cancelled ticket. Create
/// a new ticket instead.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMatchmakingCancelServerBackfillTicketAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMatchmakingCancelServerBackfillTicketRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Create a matchmaking ticket as a client.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// The client specifies the creator's attributes and optionally a list of other users to match with.
///
/// If successful, call <see cref="PFMatchmakingCreateMatchmakingTicketGetResult"/> to get the result.
/// </remarks>
HRESULT PFMatchmakingCreateMatchmakingTicketAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMatchmakingCreateMatchmakingTicketRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a CreateMatchmakingTicket call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingCreateMatchmakingTicketGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingCreateMatchmakingTicketAsync call.
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
HRESULT PFMatchmakingCreateMatchmakingTicketGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingCreateMatchmakingTicketResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Create a backfill matchmaking ticket as a server. A backfill ticket represents an ongoing game. The
/// matchmaking service automatically starts matching the backfill ticket against other matchmaking tickets.
/// Backfill tickets cannot match with other backfill tickets.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// The server specifies all the members, their teams and their attributes, and the server details if
/// applicable.
///
/// If successful, call <see cref="PFMatchmakingCreateServerBackfillTicketGetResult"/> to get the result.
/// </remarks>
HRESULT PFMatchmakingCreateServerBackfillTicketAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMatchmakingCreateServerBackfillTicketRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a CreateServerBackfillTicket call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingCreateServerBackfillTicketGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingCreateServerBackfillTicketAsync call.
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
HRESULT PFMatchmakingCreateServerBackfillTicketGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingCreateServerBackfillTicketResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Create a matchmaking ticket as a server. The matchmaking service automatically starts matching the
/// ticket against other matchmaking tickets.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// The server specifies all the members and their attributes.
///
/// If successful, call <see cref="PFMatchmakingCreateServerMatchmakingTicketGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFMatchmakingCreateServerMatchmakingTicketAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMatchmakingCreateServerMatchmakingTicketRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a CreateServerMatchmakingTicket call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingCreateServerMatchmakingTicketGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingCreateServerMatchmakingTicketAsync call.
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
HRESULT PFMatchmakingCreateServerMatchmakingTicketGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingCreateMatchmakingTicketResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Get a match.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// When matchmaking has successfully matched together a collection of tickets, it produces a 'match'
/// with an Id. The match contains all of the players that were matched together, and their team assigments.
/// Only servers and ticket members can get the match.
///
/// If successful, call <see cref="PFMatchmakingGetMatchGetResult"/> to get the result.
/// </remarks>
HRESULT PFMatchmakingGetMatchAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMatchmakingGetMatchRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetMatch call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingGetMatchGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingGetMatchAsync call.
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
HRESULT PFMatchmakingGetMatchGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingGetMatchResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Get a matchmaking ticket by ticket Id.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// The ticket includes the invited players, their attributes if they have joined, the ticket status,
/// the match Id when applicable, etc. Only servers, the ticket creator and the invited players can get
/// the ticket.
///
/// If successful, call <see cref="PFMatchmakingGetMatchmakingTicketGetResult"/> to get the result.
/// </remarks>
HRESULT PFMatchmakingGetMatchmakingTicketAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMatchmakingGetMatchmakingTicketRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetMatchmakingTicket call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingGetMatchmakingTicketGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingGetMatchmakingTicketAsync call.
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
HRESULT PFMatchmakingGetMatchmakingTicketGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingGetMatchmakingTicketResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Get the statistics for a queue.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Returns the matchmaking statistics for a queue. These include the number of players matching and
/// the statistics related to the time to match statistics in seconds (average and percentiles). Statistics
/// are refreshed once every 5 minutes. Servers can access all statistics no matter what the ClientStatisticsVisibility
/// is configured to. Clients can access statistics according to the ClientStatisticsVisibility. Client
/// requests are forbidden if all visibility fields are false.
///
/// If successful, call <see cref="PFMatchmakingGetQueueStatisticsGetResult"/> to get the result.
/// </remarks>
HRESULT PFMatchmakingGetQueueStatisticsAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMatchmakingGetQueueStatisticsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetQueueStatistics call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingGetQueueStatisticsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingGetQueueStatisticsAsync call.
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
HRESULT PFMatchmakingGetQueueStatisticsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingGetQueueStatisticsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Get a matchmaking backfill ticket by ticket Id.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// The ticket includes the players, their attributes, their teams, the ticket status, the match Id and
/// the server details when applicable, etc. Only servers can get the ticket.
///
/// If successful, call <see cref="PFMatchmakingGetServerBackfillTicketGetResult"/> to get the result.
/// </remarks>
HRESULT PFMatchmakingGetServerBackfillTicketAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMatchmakingGetServerBackfillTicketRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetServerBackfillTicket call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingGetServerBackfillTicketGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingGetServerBackfillTicketAsync call.
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
HRESULT PFMatchmakingGetServerBackfillTicketGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingGetServerBackfillTicketResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Join a matchmaking ticket.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Add the player to a matchmaking ticket and specify all of its matchmaking attributes. Players can
/// join a ticket if and only if their EntityKeys are already listed in the ticket's Members list. The
/// matchmaking service automatically starts matching the ticket against other matchmaking tickets once
/// all players have joined the ticket. It is not possible to join a ticket once it has started matching.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMatchmakingJoinMatchmakingTicketAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMatchmakingJoinMatchmakingTicketRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// List all matchmaking ticket Ids the user is a member of.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If the caller is a title, the EntityKey in the request is required. If the caller is a player, then
/// it is optional. If it is provided it must match the caller's entity.
///
/// If successful, call <see cref="PFMatchmakingListMatchmakingTicketsForPlayerGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFMatchmakingListMatchmakingTicketsForPlayerAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMatchmakingListMatchmakingTicketsForPlayerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ListMatchmakingTicketsForPlayer call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingListMatchmakingTicketsForPlayerGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingListMatchmakingTicketsForPlayerAsync call.
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
HRESULT PFMatchmakingListMatchmakingTicketsForPlayerGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingListMatchmakingTicketsForPlayerResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// List all server backfill ticket Ids the user is a member of.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// List all server backfill ticket Ids the user is a member of.
///
/// If successful, call <see cref="PFMatchmakingListServerBackfillTicketsForPlayerGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFMatchmakingListServerBackfillTicketsForPlayerAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMatchmakingListServerBackfillTicketsForPlayerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ListServerBackfillTicketsForPlayer call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMatchmakingListServerBackfillTicketsForPlayerGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMatchmakingListServerBackfillTicketsForPlayerAsync call.
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
HRESULT PFMatchmakingListServerBackfillTicketsForPlayerGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMatchmakingListServerBackfillTicketsForPlayerResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif


}