// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFCharacterDataModels.h>
#include <playfab/PFGlobal.h>
#include <playfab/PFTitlePlayer.h>

extern "C"
{

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Completely removes all statistics for the specified character, for the current game
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Note that this action cannot be un-done. All statistics for this character will be deleted, removing
/// the user from all leaderboards for the game.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFCharacterAdminResetCharacterStatisticsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCharacterResetCharacterStatisticsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

/// <summary>
/// Lists all of the characters that belong to a specific user. CharacterIds are not globally unique;
/// characterId must be evaluated with the parent PlayFabId to guarantee uniqueness.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Returns a list of every character that currently belongs to a user. See also ClientGetCharacterDataAsync.
///
/// If successful, call <see cref="PFCharacterClientGetAllUsersCharactersGetResult"/> to get the result.
/// </remarks>
HRESULT PFCharacterClientGetAllUsersCharactersAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFCharacterListUsersCharactersRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetAllUsersCharacters call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterClientGetAllUsersCharactersGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterClientGetAllUsersCharactersAsync call.
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
HRESULT PFCharacterClientGetAllUsersCharactersGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterListUsersCharactersResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the title-specific custom data for the character which is readable and writable by the
/// client
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom character
/// data will be returned. See also ClientGetCharacterReadOnlyDataAsync, ClientGetUserDataAsync, ClientUpdateCharacterDataAsync.
///
/// If successful, call <see cref="PFCharacterClientGetCharacterDataGetResult"/> to get the result.
/// </remarks>
HRESULT PFCharacterClientGetCharacterDataAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFCharacterGetCharacterDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetCharacterData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterClientGetCharacterDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterClientGetCharacterDataAsync call.
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
HRESULT PFCharacterClientGetCharacterDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterClientGetCharacterDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves a list of ranked characters for the given statistic, starting from the indicated point
/// in the leaderboard
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientGetCharacterStatisticsAsync, ClientGetLeaderboardAroundCharacterAsync, ClientUpdateCharacterStatisticsAsync.
///
/// If successful, call <see cref="PFCharacterClientGetCharacterLeaderboardGetResult"/> to get the result.
/// </remarks>
HRESULT PFCharacterClientGetCharacterLeaderboardAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFCharacterGetCharacterLeaderboardRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetCharacterLeaderboard call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterClientGetCharacterLeaderboardGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterClientGetCharacterLeaderboardAsync call.
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
HRESULT PFCharacterClientGetCharacterLeaderboardGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterGetCharacterLeaderboardResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the title-specific custom data for the character which can only be read by the client
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom character
/// data will be returned. See also ClientGetCharacterDataAsync, ClientGetUserDataAsync, ClientUpdateCharacterDataAsync.
///
/// If successful, call <see cref="PFCharacterClientGetCharacterReadOnlyDataGetResult"/> to get the result.
/// </remarks>
HRESULT PFCharacterClientGetCharacterReadOnlyDataAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFCharacterGetCharacterDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetCharacterReadOnlyData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterClientGetCharacterReadOnlyDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterClientGetCharacterReadOnlyDataAsync call.
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
HRESULT PFCharacterClientGetCharacterReadOnlyDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterClientGetCharacterDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the details of all title-specific statistics for the user
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientGetCharacterLeaderboardAsync, ClientGetLeaderboardAroundCharacterAsync, ClientGetLeaderboardForUserCharactersAsync,
/// ClientUpdateCharacterStatisticsAsync.
///
/// If successful, call <see cref="PFCharacterClientGetCharacterStatisticsGetResult"/> to get the result.
/// </remarks>
HRESULT PFCharacterClientGetCharacterStatisticsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFCharacterClientGetCharacterStatisticsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetCharacterStatistics call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterClientGetCharacterStatisticsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterClientGetCharacterStatisticsAsync call.
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
HRESULT PFCharacterClientGetCharacterStatisticsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterClientGetCharacterStatisticsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves a list of ranked characters for the given statistic, centered on the requested Character
/// ID
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientGetCharacterLeaderboardAsync, ClientGetLeaderboardAsync, ClientUpdateCharacterStatisticsAsync.
///
/// If successful, call <see cref="PFCharacterClientGetLeaderboardAroundCharacterGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFCharacterClientGetLeaderboardAroundCharacterAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFCharacterClientGetLeaderboardAroundCharacterRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetLeaderboardAroundCharacter call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterClientGetLeaderboardAroundCharacterGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterClientGetLeaderboardAroundCharacterAsync call.
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
HRESULT PFCharacterClientGetLeaderboardAroundCharacterGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterGetLeaderboardAroundCharacterResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves a list of all of the user's characters for the given statistic.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientGetCharacterLeaderboardAsync, ClientGetLeaderboardAsync, ServerGetLeaderboardAroundUserAsync.
///
/// If successful, call <see cref="PFCharacterClientGetLeaderboardForUserCharactersGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFCharacterClientGetLeaderboardForUserCharactersAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFCharacterClientGetLeaderboardForUsersCharactersRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetLeaderboardForUserCharacters call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterClientGetLeaderboardForUserCharactersGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterClientGetLeaderboardForUserCharactersAsync call.
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
HRESULT PFCharacterClientGetLeaderboardForUserCharactersGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterGetLeaderboardForUsersCharactersResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Grants the specified character type to the user. CharacterIds are not globally unique; characterId
/// must be evaluated with the parent PlayFabId to guarantee uniqueness.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Grants a character to the user of the type specified by the item ID. The user must already have an
/// instance of this item in their inventory in order to allow character creation. This item can come
/// from a purchase or grant, which must be done before calling to create the character.
///
/// If successful, call <see cref="PFCharacterClientGrantCharacterToUserGetResult"/> to get the result.
/// </remarks>
HRESULT PFCharacterClientGrantCharacterToUserAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFCharacterClientGrantCharacterToUserRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGrantCharacterToUser call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterClientGrantCharacterToUserGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterClientGrantCharacterToUserAsync call.
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
HRESULT PFCharacterClientGrantCharacterToUserGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterClientGrantCharacterToUserResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Creates and updates the title-specific custom data for the user's character which is readable and
/// writable by the client
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary strings containing the custom data for
/// the character. In updating the custom data object, keys which already exist in the object will have
/// their values overwritten, while keys with null values will be removed. New keys will be added, with
/// the given values. No other key-value pairs will be changed apart from those specified in the call.
/// See also ClientGetCharacterDataAsync, ClientGetCharacterReadOnlyDataAsync, ClientGetUserDataAsync.
///
/// If successful, call <see cref="PFCharacterClientUpdateCharacterDataGetResult"/> to get the result.
/// </remarks>
HRESULT PFCharacterClientUpdateCharacterDataAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFCharacterClientUpdateCharacterDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterClientUpdateCharacterDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFCharacterUpdateCharacterDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterClientUpdateCharacterDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFCharacterUpdateCharacterDataResult* result
) noexcept;

/// <summary>
/// Updates the values of the specified title-specific statistics for the specific character. By default,
/// clients are not permitted to update statistics. Developers may override this setting in the Game Manager
/// > Settings > API Features.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Enable this option with the 'Allow Client to Post Player Statistics' option in PlayFab GameManager
/// for your title. However, this is not best practice, as this data will no longer be safely controlled
/// by the server. This operation is additive. Character Statistics not currently defined will be added,
/// while those already defined will be updated with the given values. All other user statistics will
/// remain unchanged. Character statistics are used by the character-leaderboard apis, and accessible
/// for custom game-logic. See also ClientGetCharacterLeaderboardAsync, ClientGetCharacterStatisticsAsync,
/// ClientGetLeaderboardAroundCharacterAsync, ClientGetLeaderboardForUserCharactersAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFCharacterClientUpdateCharacterStatisticsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFCharacterClientUpdateCharacterStatisticsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Deletes the specific character ID from the specified user.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function will delete the specified character from the list allowed by the user, and will also
/// delete any inventory or VC currently held by that character. It will NOT delete any statistics associated
/// for this character, in order to preserve leaderboard integrity.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFCharacterServerDeleteCharacterFromUserAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCharacterDeleteCharacterFromUserRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Lists all of the characters that belong to a specific user. CharacterIds are not globally unique;
/// characterId must be evaluated with the parent PlayFabId to guarantee uniqueness.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Returns a list of every character that currently belongs to a user.
///
/// If successful, call <see cref="PFCharacterServerGetAllUsersCharactersGetResult"/> to get the result.
/// </remarks>
HRESULT PFCharacterServerGetAllUsersCharactersAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCharacterListUsersCharactersRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetAllUsersCharacters call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterServerGetAllUsersCharactersGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterServerGetAllUsersCharactersAsync call.
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
HRESULT PFCharacterServerGetAllUsersCharactersGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterListUsersCharactersResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the title-specific custom data for the user which is readable and writable by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom user
/// data will be returned.
///
/// If successful, call <see cref="PFCharacterServerGetCharacterDataGetResult"/> to get the result.
/// </remarks>
HRESULT PFCharacterServerGetCharacterDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCharacterGetCharacterDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetCharacterData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterServerGetCharacterDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterServerGetCharacterDataAsync call.
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
HRESULT PFCharacterServerGetCharacterDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterServerGetCharacterDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the title-specific custom data for the user's character which cannot be accessed by the
/// client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom user
/// data will be returned.
///
/// If successful, call <see cref="PFCharacterServerGetCharacterInternalDataGetResult"/> to get the result.
/// </remarks>
HRESULT PFCharacterServerGetCharacterInternalDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCharacterGetCharacterDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetCharacterInternalData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterServerGetCharacterInternalDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterServerGetCharacterInternalDataAsync call.
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
HRESULT PFCharacterServerGetCharacterInternalDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterServerGetCharacterDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves a list of ranked characters for the given statistic, starting from the indicated point
/// in the leaderboard
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFCharacterServerGetCharacterLeaderboardGetResult"/> to get the result.
/// </remarks>
HRESULT PFCharacterServerGetCharacterLeaderboardAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCharacterGetCharacterLeaderboardRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetCharacterLeaderboard call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterServerGetCharacterLeaderboardGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterServerGetCharacterLeaderboardAsync call.
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
HRESULT PFCharacterServerGetCharacterLeaderboardGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterGetCharacterLeaderboardResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the title-specific custom data for the user's character which can only be read by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom data
/// will be returned.
///
/// If successful, call <see cref="PFCharacterServerGetCharacterReadOnlyDataGetResult"/> to get the result.
/// </remarks>
HRESULT PFCharacterServerGetCharacterReadOnlyDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCharacterGetCharacterDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetCharacterReadOnlyData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterServerGetCharacterReadOnlyDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterServerGetCharacterReadOnlyDataAsync call.
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
HRESULT PFCharacterServerGetCharacterReadOnlyDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterServerGetCharacterDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the details of all title-specific statistics for the specific character
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Character statistics are similar to user statistics in that they are numeric values which may only
/// be updated by a server operation, in order to minimize the opportunity for unauthorized changes. In
/// addition to being available for use by the title, the statistics are used for all leaderboard operations
/// in PlayFab.
///
/// If successful, call <see cref="PFCharacterServerGetCharacterStatisticsGetResult"/> to get the result.
/// </remarks>
HRESULT PFCharacterServerGetCharacterStatisticsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCharacterServerGetCharacterStatisticsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetCharacterStatistics call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterServerGetCharacterStatisticsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterServerGetCharacterStatisticsAsync call.
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
HRESULT PFCharacterServerGetCharacterStatisticsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterServerGetCharacterStatisticsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves a list of ranked characters for the given statistic, centered on the requested user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFCharacterServerGetLeaderboardAroundCharacterGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFCharacterServerGetLeaderboardAroundCharacterAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCharacterServerGetLeaderboardAroundCharacterRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetLeaderboardAroundCharacter call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterServerGetLeaderboardAroundCharacterGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterServerGetLeaderboardAroundCharacterAsync call.
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
HRESULT PFCharacterServerGetLeaderboardAroundCharacterGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterGetLeaderboardAroundCharacterResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves a list of all of the user's characters for the given statistic.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFCharacterServerGetLeaderboardForUserCharactersGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFCharacterServerGetLeaderboardForUserCharactersAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCharacterServerGetLeaderboardForUsersCharactersRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetLeaderboardForUserCharacters call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterServerGetLeaderboardForUserCharactersGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterServerGetLeaderboardForUserCharactersAsync call.
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
HRESULT PFCharacterServerGetLeaderboardForUserCharactersGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterGetLeaderboardForUsersCharactersResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Grants the specified character type to the user. CharacterIds are not globally unique; characterId
/// must be evaluated with the parent PlayFabId to guarantee uniqueness.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Grants a character to the user of the type and name specified in the request.
///
/// If successful, call <see cref="PFCharacterServerGrantCharacterToUserGetResult"/> to get the result.
/// </remarks>
HRESULT PFCharacterServerGrantCharacterToUserAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCharacterServerGrantCharacterToUserRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGrantCharacterToUser call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterServerGrantCharacterToUserGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterServerGrantCharacterToUserAsync call.
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
HRESULT PFCharacterServerGrantCharacterToUserGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCharacterServerGrantCharacterToUserResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the title-specific custom data for the user's character which is readable and writable by
/// the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary JSON object containing the custom data
/// for the user. In updating the custom data object, keys which already exist in the object will have
/// their values overwritten, while keys with null values will be removed. No other key-value pairs will
/// be changed apart from those specified in the call.
///
/// If successful, call <see cref="PFCharacterServerUpdateCharacterDataGetResult"/> to get the result.
/// </remarks>
HRESULT PFCharacterServerUpdateCharacterDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCharacterServerUpdateCharacterDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterServerUpdateCharacterDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFCharacterUpdateCharacterDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterServerUpdateCharacterDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFCharacterUpdateCharacterDataResult* result
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the title-specific custom data for the user's character which cannot be accessed by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary JSON object containing the custom data
/// for the user. In updating the custom data object, keys which already exist in the object will have
/// their values overwritten, keys with null values will be removed. No other key-value pairs will be
/// changed apart from those specified in the call.
///
/// If successful, call <see cref="PFCharacterServerUpdateCharacterInternalDataGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFCharacterServerUpdateCharacterInternalDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCharacterServerUpdateCharacterDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterServerUpdateCharacterInternalDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFCharacterUpdateCharacterDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterServerUpdateCharacterInternalDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFCharacterUpdateCharacterDataResult* result
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the title-specific custom data for the user's character which can only be read by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary JSON object containing the custom data
/// for the user. In updating the custom data object, keys which already exist in the object will have
/// their values overwritten, keys with null values will be removed. No other key-value pairs will be
/// changed apart from those specified in the call.
///
/// If successful, call <see cref="PFCharacterServerUpdateCharacterReadOnlyDataGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFCharacterServerUpdateCharacterReadOnlyDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCharacterServerUpdateCharacterDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFCharacterServerUpdateCharacterReadOnlyDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFCharacterUpdateCharacterDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCharacterServerUpdateCharacterReadOnlyDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFCharacterUpdateCharacterDataResult* result
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the values of the specified title-specific statistics for the specific character
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Character statistics are similar to user statistics in that they are numeric values which may only
/// be updated by a server operation, in order to minimize the opportunity for unauthorized changes. In
/// addition to being available for use by the title, the statistics are used for all leaderboard operations
/// in PlayFab.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFCharacterServerUpdateCharacterStatisticsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCharacterServerUpdateCharacterStatisticsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif


}