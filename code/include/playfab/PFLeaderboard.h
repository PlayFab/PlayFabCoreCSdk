// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFLeaderboardDataModels.h>
#include <playfab/PFGlobal.h>
#include <playfab/PFTitlePlayer.h>

extern "C"
{

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Adds a new player statistic configuration to the title, optionally allowing the developer to specify
/// a reset interval and an aggregation method.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Statistics are numeric values, with each statistic in the title also generating a leaderboard. The
/// ResetInterval enables automatically resetting leaderboards on a specified interval. Upon reset, the
/// statistic updates to a new version with no values (effectively removing all players from the leaderboard).
/// The previous version's statistic values are also archived for retrieval, if needed (see GetPlayerStatisticVersions).
/// Statistics not created via a call to CreatePlayerStatisticDefinition by default have a VersionChangeInterval
/// of Never, meaning they do not reset on a schedule, but they can be set to do so via a call to UpdatePlayerStatisticDefinition.
/// Once a statistic has been reset (sometimes referred to as versioned or incremented), the now-previous
/// version can still be written to for up a short, pre-defined period (currently 10 seconds), to prevent
/// issues with levels completing around the time of the reset. Also, once reset, the historical statistics
/// for players in the title may be retrieved using the URL specified in the version information (GetPlayerStatisticVersions).
/// The AggregationMethod determines what action is taken when a new statistic value is submitted - always
/// update with the new value (Last), use the highest of the old and new values (Max), use the smallest
/// (Min), or add them together (Sum). See also AdminGetPlayerStatisticDefinitionsAsync, ClientGetPlayerStatisticsAsync,
/// ServerGetPlayerStatisticsAsync, AdminGetPlayerStatisticVersionsAsync, AdminUpdatePlayerStatisticDefinitionAsync,
/// ClientUpdatePlayerStatisticsAsync, ServerUpdatePlayerStatisticsAsync.
///
/// If successful, call <see cref="PFLeaderboardAdminCreatePlayerStatisticDefinitionGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFLeaderboardAdminCreatePlayerStatisticDefinitionAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFLeaderboardCreatePlayerStatisticDefinitionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminCreatePlayerStatisticDefinition call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLeaderboardAdminCreatePlayerStatisticDefinitionGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLeaderboardAdminCreatePlayerStatisticDefinitionAsync call.
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
HRESULT PFLeaderboardAdminCreatePlayerStatisticDefinitionGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLeaderboardCreatePlayerStatisticDefinitionResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the configuration information for all player statistics defined in the title, regardless
/// of whether they have a reset interval.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminCreatePlayerStatisticDefinitionAsync, ClientGetPlayerStatisticsAsync, ServerGetPlayerStatisticsAsync,
/// AdminUpdatePlayerStatisticDefinitionAsync, ClientUpdatePlayerStatisticsAsync, ServerUpdatePlayerStatisticsAsync.
///
/// If successful, call <see cref="PFLeaderboardAdminGetPlayerStatisticDefinitionsGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFLeaderboardAdminGetPlayerStatisticDefinitionsAsync(
    _In_ PFStateHandle stateHandle,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetPlayerStatisticDefinitions call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLeaderboardAdminGetPlayerStatisticDefinitionsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLeaderboardAdminGetPlayerStatisticDefinitionsAsync call.
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
HRESULT PFLeaderboardAdminGetPlayerStatisticDefinitionsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLeaderboardGetPlayerStatisticDefinitionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the information on the available versions of the specified statistic.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminCreatePlayerStatisticDefinitionAsync, AdminGetPlayerStatisticDefinitionsAsync, ClientGetPlayerStatisticsAsync,
/// ServerGetPlayerStatisticsAsync, AdminUpdatePlayerStatisticDefinitionAsync, ClientUpdatePlayerStatisticsAsync,
/// ServerUpdatePlayerStatisticsAsync.
///
/// If successful, call <see cref="PFLeaderboardAdminGetPlayerStatisticVersionsGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFLeaderboardAdminGetPlayerStatisticVersionsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFLeaderboardGetPlayerStatisticVersionsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetPlayerStatisticVersions call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLeaderboardAdminGetPlayerStatisticVersionsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLeaderboardAdminGetPlayerStatisticVersionsAsync call.
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
HRESULT PFLeaderboardAdminGetPlayerStatisticVersionsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLeaderboardGetPlayerStatisticVersionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Resets the indicated statistic, removing all player entries for it and backing up the old values.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Statistics are numeric values, with each statistic in the title also generating a leaderboard. When
/// this call is made on a given statistic, this forces a reset of that statistic. Upon reset, the statistic
/// updates to a new version with no values (effectively removing all players from the leaderboard). The
/// previous version's statistic values are also archived for retrieval, if needed (see GetPlayerStatisticVersions).
/// Statistics not created via a call to CreatePlayerStatisticDefinition by default have a VersionChangeInterval
/// of Never, meaning they do not reset on a schedule, but they can be set to do so via a call to UpdatePlayerStatisticDefinition.
/// Once a statistic has been reset (sometimes referred to as versioned or incremented), the now-previous
/// version can still be written to for up a short, pre-defined period (currently 10 seconds), to prevent
/// issues with levels completing around the time of the reset. Also, once reset, the historical statistics
/// for players in the title may be retrieved using the URL specified in the version information (GetPlayerStatisticVersions).
/// See also AdminCreatePlayerStatisticDefinitionAsync, AdminGetPlayerStatisticDefinitionsAsync, ClientGetPlayerStatisticsAsync,
/// ServerGetPlayerStatisticsAsync, AdminGetPlayerStatisticVersionsAsync, AdminUpdatePlayerStatisticDefinitionAsync,
/// ClientUpdatePlayerStatisticsAsync, ServerUpdatePlayerStatisticsAsync.
///
/// If successful, call <see cref="PFLeaderboardAdminIncrementPlayerStatisticVersionGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFLeaderboardAdminIncrementPlayerStatisticVersionAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFLeaderboardIncrementPlayerStatisticVersionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminIncrementPlayerStatisticVersion call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLeaderboardAdminIncrementPlayerStatisticVersionGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLeaderboardAdminIncrementPlayerStatisticVersionAsync call.
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
HRESULT PFLeaderboardAdminIncrementPlayerStatisticVersionGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLeaderboardIncrementPlayerStatisticVersionResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Completely removes all statistics for the specified user, for the current game
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Note that this action cannot be un-done. All statistics for this user will be deleted, removing the
/// user from all leaderboards for the game.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFLeaderboardAdminResetUserStatisticsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFLeaderboardResetUserStatisticsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates a player statistic configuration for the title, optionally allowing the developer to specify
/// a reset interval.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Statistics are numeric values, with each statistic in the title also generating a leaderboard. The
/// ResetInterval enables automatically resetting leaderboards on a specified interval. Upon reset, the
/// statistic updates to a new version with no values (effectively removing all players from the leaderboard).
/// The previous version's statistic values are also archived for retrieval, if needed (see GetPlayerStatisticVersions).
/// Statistics not created via a call to CreatePlayerStatisticDefinition by default have a VersionChangeInterval
/// of Never, meaning they do not reset on a schedule, but they can be set to do so via a call to UpdatePlayerStatisticDefinition.
/// Once a statistic has been reset (sometimes referred to as versioned or incremented), the now-previous
/// version can still be written to for up a short, pre-defined period (currently 10 seconds), to prevent
/// issues with levels completing around the time of the reset. Also, once reset, the historical statistics
/// for players in the title may be retrieved using the URL specified in the version information (GetPlayerStatisticVersions).
/// The AggregationMethod determines what action is taken when a new statistic value is submitted - always
/// update with the new value (Last), use the highest of the old and new values (Max), use the smallest
/// (Min), or add them together (Sum). See also AdminCreatePlayerStatisticDefinitionAsync, AdminGetPlayerStatisticDefinitionsAsync,
/// ClientGetPlayerStatisticsAsync, ServerGetPlayerStatisticsAsync, AdminGetPlayerStatisticVersionsAsync,
/// ClientUpdatePlayerStatisticsAsync, ServerUpdatePlayerStatisticsAsync.
///
/// If successful, call <see cref="PFLeaderboardAdminUpdatePlayerStatisticDefinitionGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFLeaderboardAdminUpdatePlayerStatisticDefinitionAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFLeaderboardUpdatePlayerStatisticDefinitionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminUpdatePlayerStatisticDefinition call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLeaderboardAdminUpdatePlayerStatisticDefinitionGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLeaderboardAdminUpdatePlayerStatisticDefinitionAsync call.
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
HRESULT PFLeaderboardAdminUpdatePlayerStatisticDefinitionGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLeaderboardUpdatePlayerStatisticDefinitionResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

/// <summary>
/// Retrieves a list of ranked friends of the current player for the given statistic, starting from the
/// indicated point in the leaderboard
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientGetFriendLeaderboardAroundPlayerAsync, ClientGetLeaderboardAsync, ClientGetLeaderboardAroundPlayerAsync,
/// ClientGetUserStatisticsAsync.
///
/// If successful, call <see cref="PFLeaderboardClientGetFriendLeaderboardGetResult"/> to get the result.
/// </remarks>
HRESULT PFLeaderboardClientGetFriendLeaderboardAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFLeaderboardClientGetFriendLeaderboardRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetFriendLeaderboard call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLeaderboardClientGetFriendLeaderboardGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLeaderboardClientGetFriendLeaderboardAsync call.
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
HRESULT PFLeaderboardClientGetFriendLeaderboardGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLeaderboardGetLeaderboardResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves a list of ranked friends of the current player for the given statistic, centered on the
/// requested PlayFab user. If PlayFabId is empty or null will return currently logged in user.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientGetFriendLeaderboardAsync, ClientGetLeaderboardAsync, ClientGetLeaderboardAroundPlayerAsync,
/// ClientGetUserStatisticsAsync.
///
/// If successful, call <see cref="PFLeaderboardClientGetFriendLeaderboardAroundPlayerGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFLeaderboardClientGetFriendLeaderboardAroundPlayerAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFLeaderboardGetFriendLeaderboardAroundPlayerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetFriendLeaderboardAroundPlayer call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLeaderboardClientGetFriendLeaderboardAroundPlayerGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLeaderboardClientGetFriendLeaderboardAroundPlayerAsync call.
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
HRESULT PFLeaderboardClientGetFriendLeaderboardAroundPlayerGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLeaderboardGetFriendLeaderboardAroundPlayerResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves a list of ranked users for the given statistic, starting from the indicated point in the
/// leaderboard
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientGetFriendLeaderboardAsync, ClientGetLeaderboardAroundPlayerAsync, ClientGetUserStatisticsAsync.
///
/// If successful, call <see cref="PFLeaderboardClientGetLeaderboardGetResult"/> to get the result.
/// </remarks>
HRESULT PFLeaderboardClientGetLeaderboardAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFLeaderboardGetLeaderboardRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetLeaderboard call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLeaderboardClientGetLeaderboardGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLeaderboardClientGetLeaderboardAsync call.
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
HRESULT PFLeaderboardClientGetLeaderboardGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLeaderboardGetLeaderboardResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves a list of ranked users for the given statistic, centered on the requested player. If PlayFabId
/// is empty or null will return currently logged in user.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientGetFriendLeaderboardAsync, ClientGetLeaderboardAsync, ClientGetUserStatisticsAsync.
///
/// If successful, call <see cref="PFLeaderboardClientGetLeaderboardAroundPlayerGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFLeaderboardClientGetLeaderboardAroundPlayerAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFLeaderboardGetLeaderboardAroundPlayerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetLeaderboardAroundPlayer call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLeaderboardClientGetLeaderboardAroundPlayerGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLeaderboardClientGetLeaderboardAroundPlayerAsync call.
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
HRESULT PFLeaderboardClientGetLeaderboardAroundPlayerGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLeaderboardGetLeaderboardAroundPlayerResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the indicated statistics (current version and values for all statistics, if none are specified),
/// for the local player.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminCreatePlayerStatisticDefinitionAsync, ClientGetPlayerStatisticVersionsAsync, AdminUpdatePlayerStatisticDefinitionAsync,
/// ClientUpdatePlayerStatisticsAsync.
///
/// If successful, call <see cref="PFLeaderboardClientGetPlayerStatisticsGetResult"/> to get the result.
/// </remarks>
HRESULT PFLeaderboardClientGetPlayerStatisticsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFLeaderboardClientGetPlayerStatisticsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayerStatistics call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLeaderboardClientGetPlayerStatisticsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLeaderboardClientGetPlayerStatisticsAsync call.
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
HRESULT PFLeaderboardClientGetPlayerStatisticsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLeaderboardClientGetPlayerStatisticsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the information on the available versions of the specified statistic.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminCreatePlayerStatisticDefinitionAsync, ClientGetPlayerStatisticsAsync, AdminUpdatePlayerStatisticDefinitionAsync,
/// ClientUpdatePlayerStatisticsAsync.
///
/// If successful, call <see cref="PFLeaderboardClientGetPlayerStatisticVersionsGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFLeaderboardClientGetPlayerStatisticVersionsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFLeaderboardGetPlayerStatisticVersionsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayerStatisticVersions call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLeaderboardClientGetPlayerStatisticVersionsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLeaderboardClientGetPlayerStatisticVersionsAsync call.
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
HRESULT PFLeaderboardClientGetPlayerStatisticVersionsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLeaderboardGetPlayerStatisticVersionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Updates the values of the specified title-specific statistics for the user. By default, clients are
/// not permitted to update statistics. Developers may override this setting in the Game Manager > Settings
/// > API Features.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Enable this option with the 'Allow Client to Post Player Statistics' option in PlayFab GameManager
/// for your title. However, this is not best practice, as this data will no longer be safely controlled
/// by the server. This operation is additive. Statistics not currently defined will be added, while those
/// already defined will be updated with the given values. All other user statistics will remain unchanged.
/// Note that if the statistic is intended to have a reset period, the UpdatePlayerStatisticDefinition
/// API call can be used to define that reset period. Once a statistic has been versioned (reset), the
/// now-previous version can still be written to for up a short, pre-defined period (currently 10 seconds),
/// using the Version parameter in this call. See also AdminCreatePlayerStatisticDefinitionAsync, ClientGetPlayerStatisticsAsync,
/// AdminUpdatePlayerStatisticDefinitionAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFLeaderboardClientUpdatePlayerStatisticsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFLeaderboardClientUpdatePlayerStatisticsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves a list of ranked friends of the given player for the given statistic, starting from the
/// indicated point in the leaderboard
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFLeaderboardServerGetFriendLeaderboardGetResult"/> to get the result.
/// </remarks>
HRESULT PFLeaderboardServerGetFriendLeaderboardAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFLeaderboardServerGetFriendLeaderboardRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetFriendLeaderboard call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLeaderboardServerGetFriendLeaderboardGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLeaderboardServerGetFriendLeaderboardAsync call.
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
HRESULT PFLeaderboardServerGetFriendLeaderboardGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLeaderboardGetLeaderboardResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves a list of ranked users for the given statistic, starting from the indicated point in the
/// leaderboard
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFLeaderboardServerGetLeaderboardGetResult"/> to get the result.
/// </remarks>
HRESULT PFLeaderboardServerGetLeaderboardAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFLeaderboardGetLeaderboardRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetLeaderboard call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLeaderboardServerGetLeaderboardGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLeaderboardServerGetLeaderboardAsync call.
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
HRESULT PFLeaderboardServerGetLeaderboardGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLeaderboardGetLeaderboardResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves a list of ranked users for the given statistic, centered on the currently signed-in user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFLeaderboardServerGetLeaderboardAroundUserGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFLeaderboardServerGetLeaderboardAroundUserAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFLeaderboardGetLeaderboardAroundUserRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetLeaderboardAroundUser call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLeaderboardServerGetLeaderboardAroundUserGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLeaderboardServerGetLeaderboardAroundUserAsync call.
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
HRESULT PFLeaderboardServerGetLeaderboardAroundUserGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLeaderboardGetLeaderboardAroundUserResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the current version and values for the indicated statistics, for the local player.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFLeaderboardServerGetPlayerStatisticsGetResult"/> to get the result.
/// </remarks>
HRESULT PFLeaderboardServerGetPlayerStatisticsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFLeaderboardServerGetPlayerStatisticsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetPlayerStatistics call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLeaderboardServerGetPlayerStatisticsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLeaderboardServerGetPlayerStatisticsAsync call.
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
HRESULT PFLeaderboardServerGetPlayerStatisticsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLeaderboardServerGetPlayerStatisticsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the information on the available versions of the specified statistic.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFLeaderboardServerGetPlayerStatisticVersionsGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFLeaderboardServerGetPlayerStatisticVersionsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFLeaderboardGetPlayerStatisticVersionsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetPlayerStatisticVersions call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFLeaderboardServerGetPlayerStatisticVersionsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFLeaderboardServerGetPlayerStatisticVersionsAsync call.
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
HRESULT PFLeaderboardServerGetPlayerStatisticVersionsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFLeaderboardGetPlayerStatisticVersionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the values of the specified title-specific statistics for the user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This operation is additive. Statistics not currently defined will be added, while those already defined
/// will be updated with the given values. All other user statistics will remain unchanged.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFLeaderboardServerUpdatePlayerStatisticsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFLeaderboardServerUpdatePlayerStatisticsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif


}