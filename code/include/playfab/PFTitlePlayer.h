// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFEntity.h>

extern "C"
{

/// <summary>
/// Entity type for all TitlePlayer Entities. This const value can be used to populate PFEntityKeys referrring to TitlePlayer Entities.
/// </summary>
static const char* PFTitlePlayerEntityType = "title_player_account";

/// <summary>
/// Handle to an authenticated TitlePlayer Entity. Returned from one of the PFAuthenticationClientLogin* APIs.
/// When no longer needed, the Entity handle must be closed with PFTitlePlayerCloseHandle.
/// </summary>
typedef struct PFTitlePlayer* PFTitlePlayerHandle;

/// <summary>
/// Duplicates a PFTitlePlayerHandle.
/// </summary>
/// <param name="titlePlayerHandle">TitlePlayer handle to duplicate.</param>
/// <param name="duplicatedHandle">The duplicated handle.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Both the duplicated handle and the original handle need to be closed with PFTitlePlayerCloseHandle when they
/// are no longer needed.
/// </remarks>
HRESULT PFTitlePlayerDuplicateHandle(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ PFTitlePlayerHandle* duplicatedHandle
) noexcept;

/// <summary>
/// Closes a PFTitlePlayerHandle.
/// </summary>
/// <param name="titlePlayerHandle">TitlePlayer handle to close.</param>
/// <returns>Result code for this API operation.</returns>
void PFTitlePlayerCloseHandle(
    _In_ PFTitlePlayerHandle titlePlayerHandle
) noexcept;

/// <summary>
/// Gets a generic PFEntityHandle for a TitlePlayer Entity. The PFEntityHandle can be used to
/// make API calls which only require a generic Entity rather than specifically a TitlePlayer Entity.
/// </summary>
/// <param name="titlePlayerHandle">PFTitlePlayerHandle returned from a login call.</param>
/// <param name="entityHandle">Generic PFEntityHandle to the TitlePlayer Entity.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// The output entityHandle and the titlePlayerHandle are separate and both need to be closed when they are no longer needed.
/// </remarks>
HRESULT PFTitlePlayerGetEntityHandle(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ PFEntityHandle* entityHandle
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the PlayFabId for a TitlePlayer.
/// </summary>
/// <param name="titlePlayerHandle">PFTitlePlayerHandle returned from a login call.</param>
/// <param name="bufferSize">The buffer size in bytes required for the PlayFabId.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitlePlayerGetPlayFabIdSize(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ size_t* playFabIdSize
) noexcept;

/// <summary>
/// Get the PlayFabId for a TitlePlayer.
/// </summary>
/// <param name="titlePlayerHandle">PFTitlePlayerHandle returned from a login call.</param>
/// <param name="playFabIdSize">The size in bytes of the playFabId buffer. The required size can be obtained from PFTitlePlayerGetPlayFabIdSize.</param>
/// <param name="playFabId">The buffer the playFabId will be written to.</param>
/// <param name="playFabIdUsed">The number of bytes used in the buffer including the null terminator.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitlePlayerGetPlayFabId(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ size_t playFabIdSize,
    _Out_writes_bytes_to_opt_(playFabIdSize, playFabIdUsed) char* playFabId,
    _Out_opt_ size_t* playFabIdUsed
) noexcept;

/// <summary>
/// Get the required buffer size for the TitlePlayer's Client SessionTicket.
/// </summary>
/// <param name="titlePlayerHandle">PFTitlePlayerHandle returned from a login call.</param>
/// <param name='bufferSize'>The required size of the buffer in bytes needed to hold the SessionTicket.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitlePlayerGetCachedSessionTicketSize(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ size_t* sessionTicketSize
) noexcept;

/// <summary>
/// Get the TitlePlayer's cached Client SessionTicket.
/// </summary>
/// <param name="titlePlayerHandle">PFTitlePlayerHandle returned from a login call.</param>
/// <param name='sessionTicketBufferSize'>The size of the provided SessionTicketBuffer, in bytes. The required size can be obtained from PFTitlePlayerGetCachedSessionTicketSize.</param>
/// <param name='SessionTicketBuffer'>Buffer to write the Client SessionTicket into.</param>
/// <param name='bufferUsed'>An optional pointer that contains the number of bytes written to the buffer.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitlePlayerGetCachedSessionTicket(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ size_t sessionTicketBufferSize,
    _Out_writes_bytes_to_opt_(sessionTicketBufferSize, *bufferUsed) char* SessionTicketBuffer,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the PFEntityKey for a TitlePlayer.
/// </summary>
/// <param name="titlePlayerHandle">PFTitlePlayerHandle returned from a login call.</param>
/// <param name="bufferSize">The buffer size in bytes required for the EntityKey.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitlePlayerGetEntityKeySize(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Get the PFEntityKey for a TitlePlayer.
/// </summary>
/// <param name="titlePlayerHandle">PFTitlePlayerHandle returned from a login call.</param>
/// <param name="bufferSize">The size of the buffer for the PFEntityKey. The required size can be obtained from PFTitlePlayerGetEntityKeySize.</param>
/// <param name="buffer">Byte buffer used for the PFEntityKey and its fields.</param>
/// <param name="result">Pointer to the PFEntityKey object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// entityKey is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFTitlePlayerGetEntityKey(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ const PFEntityKey** entityKey,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the cached PFEntityToken for a TitlePlayer.
/// </summary>
/// <param name="titlePlayerHandle">PFTitlePlayerHandle returned from a login call.</param>
/// <param name="bufferSize">The buffer size in bytes required for the cached PFEntityToken.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitlePlayerGetCachedEntityTokenSize(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Get the cached Entity token.
/// </summary>
/// <param name="titlePlayerHandle">PFTitlePlayerHandle returned from a login call.</param>
/// <param name="bufferSize">The size of the buffer for the PFEntityToken. The required size can be obtained from PFTitlePlayerGetCachedEntityTokenSize.</param>
/// <param name="buffer">Byte buffer used for the PFEntityToken and its fields.</param>
/// <param name="result">Pointer to the PFEntityToken object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// entityToken is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFTitlePlayerGetCachedEntityToken(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ const PFEntityToken** entityToken,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the cached PlayerCombinedInfo for a TitlePlayer.
/// Will be unavailable if combined player info was not requested requested during login (see <see cref="PFGetPlayerCombinedInfoRequestParams"/>) and
/// bufferSize will be set to 0 in this case.
/// </summary>
/// <param name="titlePlayerHandle">PFTitlePlayerHandle returned from a login call.</param>
/// <param name="bufferSize">The buffer size in bytes required for the cached PlayerCombinedInfo.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitlePlayerGetPlayerCombinedInfoSize(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Get combined player info.
/// </summary>
/// <param name="titlePlayerHandle">PFTitlePlayerHandle returned from a login call.</param>
/// <param name="bufferSize">The size of the buffer for the PFGetPlayerCombinedInfoResultPayload.  The required size can be obtained from PFTitlePlayerGetPlayerCombinedInfoSize.</param>
/// <param name="buffer">Byte buffer used for the PFEntityToken and its fields.</param>
/// <param name="result">Pointer to the PFEntityToken object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// playerCombinedInfo is a pointer within buffer and does not need to be freed separately.
/// The returned data is only guaranteed to be up to date as of the login request - it will not be automatically refreshed.
/// To get updated combined player data call <see cref="PFPlayerDataManagementGetPlayerCombinedInfoAsync"/>
/// </remarks>
HRESULT PFTitlePlayerGetPlayerCombinedInfo(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ const PFGetPlayerCombinedInfoResultPayload** playerCombinedInfo,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Get last login time (prior to the login that resulted in this PFTitlePlayerHandle). lastLoginTime will be set to 0 if the user has no previous logins.
/// </summary>
/// <param name="titlePlayerHandle">PFTitlePlayerHandle returned from a login call.</param>
/// <param name="lastLoginTime">Populated with the TitlePlayers last login time, or 0 if the player has not logged in previously.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitlePlayerGetLastLoginTime(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ time_t* lastLoginTime
) noexcept;

/// <summary>
/// Get UserSettings. Will be unavailable if UserSettings were not requested requested during login (see <see cref="PFGetPlayerCombinedInfoRequestParams"/>).
/// </summary>
/// <param name="titlePlayerHandle">PFTitlePlayerHandle returned from a login call.</param>
/// <param name="userSettings">Populated UserSettings.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitlePlayerGetUserSettings(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ PFAuthenticationUserSettings* userSettings
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the cached experimentation treatments for a TitlePlayer.
/// Will be unavailable if treatmentAssignment was not requested requested during login (see <see cref="PFGetPlayerCombinedInfoRequestParams"/>) and
/// bufferSize will be set to 0 in this case.
/// </summary>
/// <param name="titlePlayerHandle">PFTitlePlayerHandle returned from a login call.</param>
/// <param name="bufferSize">The buffer size in bytes required for the cached PFTreatmentAssignment.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitlePlayerGetTreatmentAssignmentSize(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Get experimentation treatments for a user at the time of login.
/// </summary>
/// <param name="titlePlayerHandle">PFTitlePlayerHandle returned from a login call.</param>
/// <param name="bufferSize">The size of the buffer for the PFTreatmentAssignment.  The required size can be obtained from PFTitlePlayerGetTreatmentAssignmentSize.</param>
/// <param name="buffer">Byte buffer used for the PFEntityToken and its fields.</param>
/// <param name="result">Pointer to the PFTreatmentAssignment object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// treatmentAssignment is a pointer within buffer and does not need to be freed separately.
/// The returned data is only guaranteed to be up to date as of the login request - it will not be automatically refreshed.
/// To get updated experimentation treatments call <see cref="PFExperimentationGetTreatmentAssignmentAsync"/>
/// </remarks>
HRESULT PFTitlePlayerGetTreatmentAssignment(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ const PFTreatmentAssignment** treatmentAssignment,
    _Out_opt_ size_t* bufferUsed
) noexcept;

}
