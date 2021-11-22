// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFAccountManagementDataModels.h>
#include <playfab/PFGlobal.h>
#include <playfab/PFTitlePlayer.h>

extern "C"
{

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Bans users by PlayFab ID with optional IP address, or MAC address for the provided game.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// The existence of each user will not be verified. When banning by IP or MAC address, multiple players
/// may be affected, so use this feature with caution. Returns information about the new bans. See also
/// AdminGetUserBansAsync, AdminRevokeAllBansForUserAsync, AdminRevokeBansAsync, AdminUpdateBansAsync.
///
/// If successful, call <see cref="PFAccountManagementAdminBanUsersGetResult"/> to get the result.
/// </remarks>
HRESULT PFAccountManagementAdminBanUsersAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementBanUsersRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminBanUsers call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementAdminBanUsersGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementAdminBanUsersAsync call.
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
HRESULT PFAccountManagementAdminBanUsersGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementBanUsersResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Removes a master player account entirely from all titles and deletes all associated data
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Deletes all data associated with the master player account, including data from all titles the player
/// has played, such as statistics, custom data, inventory, purchases, virtual currency balances, characters,
/// group memberships, publisher data, credential data, account linkages, friends list and PlayStream
/// event history. Removes the player from all leaderboards and player search indexes. Note, this API
/// queues the player for deletion and returns a receipt immediately. Record the receipt ID for future
/// reference. It may take some time before all player data is fully deleted. Upon completion of the deletion,
/// an email will be sent to the notification email address configured for the title confirming the deletion.
/// Until the player data is fully deleted, attempts to recreate the player with the same user account
/// in the same title will fail with the 'AccountDeleted' error. It is highly recommended to know the
/// impact of the deletion by calling GetPlayedTitleList, before calling this API. See also AdminGetPlayedTitleListAsync.
///
/// If successful, call <see cref="PFAccountManagementAdminDeleteMasterPlayerAccountGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFAccountManagementAdminDeleteMasterPlayerAccountAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementDeleteMasterPlayerAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminDeleteMasterPlayerAccount call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementAdminDeleteMasterPlayerAccountGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementAdminDeleteMasterPlayerAccountAsync call.
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
HRESULT PFAccountManagementAdminDeleteMasterPlayerAccountGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementDeleteMasterPlayerAccountResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Deletes a player's subscription
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API lets developers delete a membership subscription.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementAdminDeleteMembershipSubscriptionAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementDeleteMembershipSubscriptionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Removes a user's player account from a title and deletes all associated data
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Deletes all data associated with the player, including statistics, custom data, inventory, purchases,
/// virtual currency balances, characters and shared group memberships. Removes the player from all leaderboards
/// and player search indexes. Does not delete PlayStream event history associated with the player. Does
/// not delete the publisher user account that created the player in the title nor associated data such
/// as username, password, email address, account linkages, or friends list. Note, this API queues the
/// player for deletion and returns immediately. It may take several minutes or more before all player
/// data is fully deleted. Until the player data is fully deleted, attempts to recreate the player with
/// the same user account in the same title will fail with the 'AccountDeleted' error.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementAdminDeletePlayerAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementDeletePlayerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Permanently deletes a title and all associated configuration
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Deletes all data associated with the title, including catalog, virtual currencies, leaderboard statistics,
/// Cloud Script revisions, segment definitions, event rules, tasks, add-ons, secret keys, data encryption
/// keys, and permission policies. Removes the title from its studio and removes all associated developer
/// roles and permissions. Does not delete PlayStream event history associated with the title. Note, this
/// API queues the title for deletion and returns immediately. It may take several hours or more before
/// all title data is fully deleted. All player accounts in the title must be deleted before deleting
/// the title. If any player accounts exist, the API will return a 'TitleContainsUserAccounts' error.
/// Until the title data is fully deleted, attempts to call APIs with the title will fail with the 'TitleDeleted'
/// error. See also AdminDeletePlayerAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementAdminDeleteTitleAsync(
    _In_ PFStateHandle stateHandle,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Exports all associated data of a master player account
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Exports all data associated with the master player account, including data from all titles the player
/// has played, such as statistics, custom data, inventory, purchases, virtual currency balances, characters,
/// group memberships, publisher data, credential data, account linkages, friends list and PlayStream
/// event history. Note, this API queues the player for export and returns a receipt immediately. Record
/// the receipt ID for future reference. It may take some time before the export is available for download.
/// Upon completion of the export, an email containing the URL to download the export dump will be sent
/// to the notification email address configured for the title.
///
/// If successful, call <see cref="PFAccountManagementAdminExportMasterPlayerDataGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFAccountManagementAdminExportMasterPlayerDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementExportMasterPlayerDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminExportMasterPlayerData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementAdminExportMasterPlayerDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementAdminExportMasterPlayerDataAsync call.
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
HRESULT PFAccountManagementAdminExportMasterPlayerDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementExportMasterPlayerDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Get the list of titles that the player has played
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Useful for identifying titles of which the player's data will be deleted by DeleteMasterPlayer. See
/// also AdminDeleteMasterPlayerAccountAsync.
///
/// If successful, call <see cref="PFAccountManagementAdminGetPlayedTitleListGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFAccountManagementAdminGetPlayedTitleListAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementGetPlayedTitleListRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetPlayedTitleList call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementAdminGetPlayedTitleListGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementAdminGetPlayedTitleListAsync call.
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
HRESULT PFAccountManagementAdminGetPlayedTitleListGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayedTitleListResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Gets a player's ID from an auth token.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Gets a player ID from an auth token. The token expires after 30 minutes and cannot be used to look
/// up a player when expired.
///
/// If successful, call <see cref="PFAccountManagementAdminGetPlayerIdFromAuthTokenGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFAccountManagementAdminGetPlayerIdFromAuthTokenAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementGetPlayerIdFromAuthTokenRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetPlayerIdFromAuthToken call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementAdminGetPlayerIdFromAuthTokenGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementAdminGetPlayerIdFromAuthTokenAsync call.
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
HRESULT PFAccountManagementAdminGetPlayerIdFromAuthTokenGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayerIdFromAuthTokenResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the player's profile
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API allows for access to details regarding a user in the PlayFab service, usually for purposes
/// of customer support. Note that data returned may be Personally Identifying Information (PII), such
/// as email address, and so care should be taken in how this data is stored and managed. Since this call
/// will always return the relevant information for users who have accessed the title, the recommendation
/// is to not store this data locally.
///
/// If successful, call <see cref="PFAccountManagementAdminGetPlayerProfileGetResult"/> to get the result.
/// </remarks>
HRESULT PFAccountManagementAdminGetPlayerProfileAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementGetPlayerProfileRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetPlayerProfile call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementAdminGetPlayerProfileGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementAdminGetPlayerProfileAsync call.
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
HRESULT PFAccountManagementAdminGetPlayerProfileGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayerProfileResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the relevant details for a specified user, based upon a match against a supplied unique
/// identifier
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API allows for access to details regarding a user in the PlayFab service, usually for purposes
/// of customer support. Note that data returned may be Personally Identifying Information (PII), such
/// as email address, and so care should be taken in how this data is stored and managed. Since this call
/// will always return the relevant information for users who have accessed the title, the recommendation
/// is to not store this data locally. See also AdminGetUserInventoryAsync.
///
/// If successful, call <see cref="PFAccountManagementAdminGetUserAccountInfoGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFAccountManagementAdminGetUserAccountInfoAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementLookupUserAccountInfoRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetUserAccountInfo call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementAdminGetUserAccountInfoGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementAdminGetUserAccountInfoAsync call.
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
HRESULT PFAccountManagementAdminGetUserAccountInfoGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementLookupUserAccountInfoResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Gets all bans for a user.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Get all bans for a user, including inactive and expired bans.  See also AdminBanUsersAsync, AdminRevokeAllBansForUserAsync,
/// AdminRevokeBansAsync, AdminUpdateBansAsync.
///
/// If successful, call <see cref="PFAccountManagementAdminGetUserBansGetResult"/> to get the result.
/// </remarks>
HRESULT PFAccountManagementAdminGetUserBansAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementGetUserBansRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetUserBans call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementAdminGetUserBansGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementAdminGetUserBansAsync call.
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
HRESULT PFAccountManagementAdminGetUserBansGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetUserBansResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Reset a player's password for a given title.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Resets a player's password taking in a new password based and validating the user based off of a
/// token sent to the playerto their email. The token expires after 30 minutes.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementAdminResetPasswordAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementResetPasswordRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Revoke all active bans for a user.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Setting the active state of all non-expired bans for a user to Inactive. Expired bans with an Active
/// state will be ignored, however. Returns information about applied updates only. See also AdminBanUsersAsync,
/// AdminGetUserBansAsync, AdminRevokeBansAsync, AdminUpdateBansAsync.
///
/// If successful, call <see cref="PFAccountManagementAdminRevokeAllBansForUserGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFAccountManagementAdminRevokeAllBansForUserAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementRevokeAllBansForUserRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminRevokeAllBansForUser call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementAdminRevokeAllBansForUserGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementAdminRevokeAllBansForUserAsync call.
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
HRESULT PFAccountManagementAdminRevokeAllBansForUserGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementRevokeAllBansForUserResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Revoke all active bans specified with BanId.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Setting the active state of all bans requested to Inactive regardless of whether that ban has already
/// expired. BanIds that do not exist will be skipped. Returns information about applied updates only.
///  See also AdminBanUsersAsync, AdminGetUserBansAsync, AdminRevokeAllBansForUserAsync, AdminUpdateBansAsync.
///
/// If successful, call <see cref="PFAccountManagementAdminRevokeBansGetResult"/> to get the result.
/// </remarks>
HRESULT PFAccountManagementAdminRevokeBansAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementRevokeBansRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminRevokeBans call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementAdminRevokeBansGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementAdminRevokeBansAsync call.
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
HRESULT PFAccountManagementAdminRevokeBansGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementRevokeBansResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Forces an email to be sent to the registered email address for the user's account, with a link allowing
/// the user to change the password.If an account recovery email template ID is provided, an email using
/// the custom email template will be used.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If the account in question is a 'temporary' account (for example, one that was created via a call
/// to LoginFromIOSDeviceID), thisfunction will have no effect. Only PlayFab accounts which have valid
/// email addresses will be able to receive a password reset email using this API.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementAdminSendAccountRecoveryEmailAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementAdminSendAccountRecoveryEmailRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Sets the override expiration for a membership subscription
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API lets developers set overrides for membership expirations, independent of any subscriptions
/// setting it.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementAdminSetMembershipOverrideAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementSetMembershipOverrideRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates information of a list of existing bans specified with Ban Ids.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// For each ban, only updates the values that are set. Leave any value to null for no change. If a ban
/// could not be found, the rest are still applied. Returns information about applied updates only. See
/// also AdminBanUsersAsync, AdminGetUserBansAsync, AdminRevokeAllBansForUserAsync, AdminRevokeBansAsync.
///
/// If successful, call <see cref="PFAccountManagementAdminUpdateBansGetResult"/> to get the result.
/// </remarks>
HRESULT PFAccountManagementAdminUpdateBansAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementUpdateBansRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminUpdateBans call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementAdminUpdateBansGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementAdminUpdateBansAsync call.
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
HRESULT PFAccountManagementAdminUpdateBansGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementUpdateBansResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the title specific display name for a user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// In addition to the PlayFab username, titles can make use of a DisplayName which is also a unique
/// identifier, but specific to the title. This allows for unique names which more closely match the theme
/// or genre of a title, for example. This API enables changing that name, whether due to a customer request,
/// an offensive name choice, etc.
///
/// If successful, call <see cref="PFAccountManagementAdminUpdateUserTitleDisplayNameGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFAccountManagementAdminUpdateUserTitleDisplayNameAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementAdminUpdateUserTitleDisplayNameRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminUpdateUserTitleDisplayName call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementAdminUpdateUserTitleDisplayNameGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementAdminUpdateUserTitleDisplayNameAsync call.
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
HRESULT PFAccountManagementAdminUpdateUserTitleDisplayNameGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementUpdateUserTitleDisplayNameResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

/// <summary>
/// Adds the specified generic service identifier to the player's PlayFab account. This is designed to
/// allow for a PlayFab ID lookup of any arbitrary service identifier a title wants to add. This identifier
/// should never be used as authentication credentials, as the intent is that it is easily accessible
/// by other players.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientGetPlayFabIDsFromGenericIDsAsync, ClientRemoveGenericIDAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientAddGenericIDAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementClientAddGenericIDRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Adds or updates a contact email to the player's profile.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API adds a contact email to the player's profile. If the player's profile already contains a
/// contact email, it will update the contact email to the email address specified.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientAddOrUpdateContactEmailAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementAddOrUpdateContactEmailRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Adds playfab username/password auth to an existing account created via an anonymous auth method,
/// e.g. automatic device ID login.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLoginWithEmailAddressAsync, ClientLoginWithPlayFabAsync.
///
/// If successful, call <see cref="PFAccountManagementClientAddUsernamePasswordGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFAccountManagementClientAddUsernamePasswordAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementAddUsernamePasswordRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientAddUsernamePassword call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementClientAddUsernamePasswordGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementClientAddUsernamePasswordAsync call.
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
HRESULT PFAccountManagementClientAddUsernamePasswordGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementAddUsernamePasswordResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the user's PlayFab account details
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementClientGetAccountInfoGetResult"/> to get the result.
/// </remarks>
HRESULT PFAccountManagementClientGetAccountInfoAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementGetAccountInfoRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetAccountInfo call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementClientGetAccountInfoGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementClientGetAccountInfoAsync call.
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
HRESULT PFAccountManagementClientGetAccountInfoGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetAccountInfoResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves all of the user's different kinds of info.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementClientGetPlayerCombinedInfoGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFAccountManagementClientGetPlayerCombinedInfoAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFGetPlayerCombinedInfoRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayerCombinedInfo call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementClientGetPlayerCombinedInfoGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementClientGetPlayerCombinedInfoAsync call.
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
HRESULT PFAccountManagementClientGetPlayerCombinedInfoGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFGetPlayerCombinedInfoResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the player's profile
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API allows for access to details regarding a user in the PlayFab service, usually for purposes
/// of customer support. Note that data returned may be Personally Identifying Information (PII), such
/// as email address, and so care should be taken in how this data is stored and managed. Since this call
/// will always return the relevant information for users who have accessed the title, the recommendation
/// is to not store this data locally.
///
/// If successful, call <see cref="PFAccountManagementClientGetPlayerProfileGetResult"/> to get the result.
/// </remarks>
HRESULT PFAccountManagementClientGetPlayerProfileAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementGetPlayerProfileRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayerProfile call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementClientGetPlayerProfileGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementClientGetPlayerProfileAsync call.
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
HRESULT PFAccountManagementClientGetPlayerProfileGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayerProfileResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of Facebook identifiers.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementClientGetPlayFabIDsFromFacebookIDsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFAccountManagementClientGetPlayFabIDsFromFacebookIDsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromFacebookIDsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayFabIDsFromFacebookIDs call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementClientGetPlayFabIDsFromFacebookIDsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementClientGetPlayFabIDsFromFacebookIDsAsync call.
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
HRESULT PFAccountManagementClientGetPlayFabIDsFromFacebookIDsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromFacebookIDsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of Facebook Instant Game identifiers.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementClientGetPlayFabIDsFromFacebookInstantGamesIdsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFAccountManagementClientGetPlayFabIDsFromFacebookInstantGamesIdsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayFabIDsFromFacebookInstantGamesIds call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementClientGetPlayFabIDsFromFacebookInstantGamesIdsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementClientGetPlayFabIDsFromFacebookInstantGamesIdsAsync call.
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
HRESULT PFAccountManagementClientGetPlayFabIDsFromFacebookInstantGamesIdsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of Game Center identifiers (referenced
/// in the Game Center Programming Guide as the Player Identifier).
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementClientGetPlayFabIDsFromGameCenterIDsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFAccountManagementClientGetPlayFabIDsFromGameCenterIDsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayFabIDsFromGameCenterIDs call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementClientGetPlayFabIDsFromGameCenterIDsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementClientGetPlayFabIDsFromGameCenterIDsAsync call.
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
HRESULT PFAccountManagementClientGetPlayFabIDsFromGameCenterIDsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of generic service identifiers. A generic
/// identifier is the service name plus the service-specific ID for the player, as specified by the title
/// when the generic identifier was added to the player account.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientAddGenericIDAsync, ClientRemoveGenericIDAsync.
///
/// If successful, call <see cref="PFAccountManagementClientGetPlayFabIDsFromGenericIDsGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFAccountManagementClientGetPlayFabIDsFromGenericIDsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromGenericIDsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayFabIDsFromGenericIDs call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementClientGetPlayFabIDsFromGenericIDsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementClientGetPlayFabIDsFromGenericIDsAsync call.
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
HRESULT PFAccountManagementClientGetPlayFabIDsFromGenericIDsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromGenericIDsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of Google identifiers. The Google identifiers
/// are the IDs for the user accounts, available as 'id' in the Google+ People API calls.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementClientGetPlayFabIDsFromGoogleIDsGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFAccountManagementClientGetPlayFabIDsFromGoogleIDsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromGoogleIDsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayFabIDsFromGoogleIDs call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementClientGetPlayFabIDsFromGoogleIDsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementClientGetPlayFabIDsFromGoogleIDsAsync call.
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
HRESULT PFAccountManagementClientGetPlayFabIDsFromGoogleIDsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromGoogleIDsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of Kongregate identifiers. The Kongregate
/// identifiers are the IDs for the user accounts, available as 'user_id' from the Kongregate API methods(ex:
/// http://developers.kongregate.com/docs/client/getUserId).
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementClientGetPlayFabIDsFromKongregateIDsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFAccountManagementClientGetPlayFabIDsFromKongregateIDsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromKongregateIDsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayFabIDsFromKongregateIDs call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementClientGetPlayFabIDsFromKongregateIDsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementClientGetPlayFabIDsFromKongregateIDsAsync call.
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
HRESULT PFAccountManagementClientGetPlayFabIDsFromKongregateIDsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromKongregateIDsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of Nintendo Switch identifiers.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementClientGetPlayFabIDsFromNintendoSwitchDeviceIdsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFAccountManagementClientGetPlayFabIDsFromNintendoSwitchDeviceIdsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayFabIDsFromNintendoSwitchDeviceIds call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementClientGetPlayFabIDsFromNintendoSwitchDeviceIdsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementClientGetPlayFabIDsFromNintendoSwitchDeviceIdsAsync call.
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
HRESULT PFAccountManagementClientGetPlayFabIDsFromNintendoSwitchDeviceIdsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of PlayStation Network identifiers.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementClientGetPlayFabIDsFromPSNAccountIDsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFAccountManagementClientGetPlayFabIDsFromPSNAccountIDsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayFabIDsFromPSNAccountIDs call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementClientGetPlayFabIDsFromPSNAccountIDsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementClientGetPlayFabIDsFromPSNAccountIDsAsync call.
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
HRESULT PFAccountManagementClientGetPlayFabIDsFromPSNAccountIDsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of Steam identifiers. The Steam identifiers
/// are the profile IDs for the user accounts, available as SteamId in the Steamworks Community API calls.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementClientGetPlayFabIDsFromSteamIDsGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFAccountManagementClientGetPlayFabIDsFromSteamIDsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromSteamIDsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayFabIDsFromSteamIDs call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementClientGetPlayFabIDsFromSteamIDsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementClientGetPlayFabIDsFromSteamIDsAsync call.
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
HRESULT PFAccountManagementClientGetPlayFabIDsFromSteamIDsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromSteamIDsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of Twitch identifiers. The Twitch identifiers
/// are the IDs for the user accounts, available as '_id' from the Twitch API methods (ex: https://github.com/justintv/Twitch-API/blob/master/v3_resources/users.md#get-usersuser).
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementClientGetPlayFabIDsFromTwitchIDsGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFAccountManagementClientGetPlayFabIDsFromTwitchIDsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromTwitchIDsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayFabIDsFromTwitchIDs call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementClientGetPlayFabIDsFromTwitchIDsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementClientGetPlayFabIDsFromTwitchIDsAsync call.
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
HRESULT PFAccountManagementClientGetPlayFabIDsFromTwitchIDsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromTwitchIDsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of XboxLive identifiers.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementClientGetPlayFabIDsFromXboxLiveIDsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFAccountManagementClientGetPlayFabIDsFromXboxLiveIDsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayFabIDsFromXboxLiveIDs call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementClientGetPlayFabIDsFromXboxLiveIDsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementClientGetPlayFabIDsFromXboxLiveIDsAsync call.
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
HRESULT PFAccountManagementClientGetPlayFabIDsFromXboxLiveIDsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Links the Android device identifier to the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLoginWithAndroidDeviceIDAsync, ClientUnlinkAndroidDeviceIDAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientLinkAndroidDeviceIDAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementLinkAndroidDeviceIDRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Links the Apple account associated with the token to the user's PlayFab account.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLoginWithAppleAsync, ClientUnlinkAppleAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientLinkAppleAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementLinkAppleRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

/// <summary>
/// Links the custom identifier, generated by the title, to the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLoginWithCustomIDAsync, ClientUnlinkCustomIDAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientLinkCustomIDAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementLinkCustomIDRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Links the Facebook account associated with the provided Facebook access token to the user's PlayFab
/// account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Facebook sign-in is accomplished using the Facebook User Access Token. More information on the Token
/// can be found in the Facebook developer documentation (https://developers.facebook.com/docs/facebook-login/access-tokens/).
/// In Unity, for example, the Token is available as AccessToken in the Facebook SDK ScriptableObject
/// FB. Note that titles should never re-use the same Facebook applications between PlayFab Title IDs,
/// as Facebook provides unique user IDs per application and doing so can result in issues with the Facebook
/// ID for the user in their PlayFab account information. If you must re-use an application in a new PlayFab
/// Title ID, please be sure to first unlink all accounts from Facebook, or delete all users in the first
/// Title ID. See also ClientLoginWithFacebookAsync, ClientUnlinkFacebookAccountAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientLinkFacebookAccountAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementLinkFacebookAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Links the Facebook Instant Games Id to the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLoginWithFacebookInstantGamesIdAsync, ClientUnlinkFacebookInstantGamesIdAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientLinkFacebookInstantGamesIdAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementLinkFacebookInstantGamesIdRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Links the Game Center account associated with the provided Game Center ID to the user's PlayFab account.
/// Logging in with a Game Center ID is insecure if you do not include the optional PublicKeyUrl, Salt,
/// Signature, and Timestamp parameters in this request. It is recommended you require these parameters
/// on all Game Center calls by going to the Apple Add-ons page in the PlayFab Game Manager and enabling
/// the 'Require secure authentication only for this app' option.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientUnlinkGameCenterAccountAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientLinkGameCenterAccountAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementLinkGameCenterAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Links the currently signed-in user account to their Google account, using their Google account credentials
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Google sign-in is accomplished by obtaining a Google OAuth 2.0 credential using the Google sign-in
/// for Android APIs on the device and passing it to this API.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientLinkGoogleAccountAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementLinkGoogleAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Links the vendor-specific iOS device identifier to the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLoginWithIOSDeviceIDAsync, ClientUnlinkIOSDeviceIDAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientLinkIOSDeviceIDAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementLinkIOSDeviceIDRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Links the Kongregate identifier to the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLoginWithKongregateAsync, ClientUnlinkKongregateAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientLinkKongregateAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementLinkKongregateAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Links the Nintendo account associated with the token to the user's PlayFab account.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientLinkNintendoServiceAccountAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementLinkNintendoServiceAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Links the NintendoSwitchDeviceId to the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientLinkNintendoSwitchDeviceIdAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementLinkNintendoSwitchDeviceIdRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

/// <summary>
/// Links an OpenID Connect account to a user's PlayFab account, based on an existing relationship between
/// a title and an Open ID Connect provider and the OpenId Connect JWT from that provider.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientLinkOpenIdConnectAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementLinkOpenIdConnectRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Links the PlayStation Network account associated with the provided access code to the user's PlayFab
/// account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLoginWithPSNAsync, ClientUnlinkPSNAccountAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientLinkPSNAccountAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementClientLinkPSNAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Links the Steam account associated with the provided Steam authentication ticket to the user's PlayFab
/// account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Steam authentication is accomplished with the Steam Session Ticket. More information on the Ticket
/// can be found in the Steamworks SDK, here: https://partner.steamgames.com/documentation/auth (requires
/// sign-in). NOTE: For Steam authentication to work, the title must be configured with the Steam Application
/// ID and Publisher Key in the PlayFab Game Manager (under Properties). Information on creating a Publisher
/// Key (referred to as the Secret Key in PlayFab) for your title can be found here: https://partner.steamgames.com/documentation/webapi#publisherkey.
/// See also ClientLoginWithSteamAsync, ClientUnlinkSteamAccountAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientLinkSteamAccountAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementLinkSteamAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Links the Twitch account associated with the token to the user's PlayFab account.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientLinkTwitchAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementLinkTwitchAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

/// <summary>
/// Links the Xbox Live account associated with the provided access code to the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLoginWithXboxAsync, ClientUnlinkXboxAccountAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientLinkXboxAccountAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementClientLinkXboxAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Removes a contact email from the player's profile.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API removes an existing contact email from the player's profile.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientRemoveContactEmailAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementRemoveContactEmailRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Removes the specified generic service identifier from the player's PlayFab account.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientAddGenericIDAsync, ClientGetPlayFabIDsFromGenericIDsAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientRemoveGenericIDAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementClientRemoveGenericIDRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Submit a report for another player (due to bad bahavior, etc.), so that customer service representatives
/// for the title can take action concerning potentially toxic players.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementClientReportPlayerGetResult"/> to get the result.
/// </remarks>
HRESULT PFAccountManagementClientReportPlayerAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementReportPlayerClientRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementClientReportPlayerAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFAccountManagementReportPlayerClientResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementClientReportPlayerGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFAccountManagementReportPlayerClientResult* result
) noexcept;

/// <summary>
/// Forces an email to be sent to the registered email address for the user's account, with a link allowing
/// the user to change the password.If an account recovery email template ID is provided, an email using
/// the custom email template will be used.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If the account in question is a 'temporary' account (for example, one that was created via a call
/// to LoginFromIOSDeviceID), thisfunction will have no effect. Only PlayFab accounts which have valid
/// email addresses will be able to receive a password reset email using this API.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientSendAccountRecoveryEmailAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementClientSendAccountRecoveryEmailRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Unlinks the related Android device identifier from the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLinkAndroidDeviceIDAsync, ClientLoginWithAndroidDeviceIDAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientUnlinkAndroidDeviceIDAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementUnlinkAndroidDeviceIDRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Unlinks the related Apple account from the user's PlayFab account.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLinkAppleAsync, ClientLoginWithAppleAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientUnlinkAppleAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementUnlinkAppleRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

/// <summary>
/// Unlinks the related custom identifier from the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLinkCustomIDAsync, ClientLoginWithCustomIDAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientUnlinkCustomIDAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementUnlinkCustomIDRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Unlinks the related Facebook account from the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLinkFacebookAccountAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientUnlinkFacebookAccountAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementUnlinkFacebookAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Unlinks the related Facebook Instant Game Ids from the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLinkFacebookInstantGamesIdAsync, ClientLoginWithFacebookInstantGamesIdAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientUnlinkFacebookInstantGamesIdAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementUnlinkFacebookInstantGamesIdRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Unlinks the related Game Center account from the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLinkGameCenterAccountAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientUnlinkGameCenterAccountAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementUnlinkGameCenterAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Unlinks the related Google account from the user's PlayFab account (https://developers.google.com/android/reference/com/google/android/gms/auth/GoogleAuthUtil#public-methods).
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientUnlinkGoogleAccountAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementUnlinkGoogleAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Unlinks the related iOS device identifier from the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLinkIOSDeviceIDAsync, ClientLoginWithIOSDeviceIDAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientUnlinkIOSDeviceIDAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementUnlinkIOSDeviceIDRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Unlinks the related Kongregate identifier from the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLinkKongregateAsync, ClientLoginWithKongregateAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientUnlinkKongregateAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementUnlinkKongregateAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Unlinks the related Nintendo account from the user's PlayFab account.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientUnlinkNintendoServiceAccountAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementUnlinkNintendoServiceAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Unlinks the related NintendoSwitchDeviceId from the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientUnlinkNintendoSwitchDeviceIdAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementUnlinkNintendoSwitchDeviceIdRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

/// <summary>
/// Unlinks an OpenID Connect account from a user's PlayFab account, based on the connection ID of an
/// existing relationship between a title and an Open ID Connect provider.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientUnlinkOpenIdConnectAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementUnlinkOpenIdConnectRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Unlinks the related PSN account from the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLinkPSNAccountAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientUnlinkPSNAccountAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementClientUnlinkPSNAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Unlinks the related Steam account from the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLinkSteamAccountAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientUnlinkSteamAccountAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementUnlinkSteamAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Unlinks the related Twitch account from the user's PlayFab account.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientUnlinkTwitchAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementUnlinkTwitchAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

/// <summary>
/// Unlinks the related Xbox Live account from the user's PlayFab account
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLinkXboxAccountAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientUnlinkXboxAccountAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementClientUnlinkXboxAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Update the avatar URL of the player
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementClientUpdateAvatarUrlAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementClientUpdateAvatarUrlRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Updates the title specific display name for the user
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// In addition to the PlayFab username, titles can make use of a DisplayName which is also a unique
/// identifier, but specific to the title. This allows for unique names which more closely match the theme
/// or genre of a title, for example.
///
/// If successful, call <see cref="PFAccountManagementClientUpdateUserTitleDisplayNameGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFAccountManagementClientUpdateUserTitleDisplayNameAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAccountManagementClientUpdateUserTitleDisplayNameRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientUpdateUserTitleDisplayName call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementClientUpdateUserTitleDisplayNameGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementClientUpdateUserTitleDisplayNameAsync call.
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
HRESULT PFAccountManagementClientUpdateUserTitleDisplayNameGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementUpdateUserTitleDisplayNameResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Adds the specified generic service identifier to the player's PlayFab account. This is designed to
/// allow for a PlayFab ID lookup of any arbitrary service identifier a title wants to add. This identifier
/// should never be used as authentication credentials, as the intent is that it is easily accessible
/// by other players.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerGetPlayFabIDsFromGenericIDsAsync, ServerRemoveGenericIDAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementServerAddGenericIDAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementServerAddGenericIDRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Bans users by PlayFab ID with optional IP address, or MAC address for the provided game.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// The existence of each user will not be verified. When banning by IP or MAC address, multiple players
/// may be affected, so use this feature with caution. Returns information about the new bans. See also
/// ServerGetUserBansAsync, ServerRevokeAllBansForUserAsync, ServerRevokeBansAsync, ServerUpdateBansAsync.
///
/// If successful, call <see cref="PFAccountManagementServerBanUsersGetResult"/> to get the result.
/// </remarks>
HRESULT PFAccountManagementServerBanUsersAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementBanUsersRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerBanUsers call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementServerBanUsersGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementServerBanUsersAsync call.
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
HRESULT PFAccountManagementServerBanUsersGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementBanUsersResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Removes a user's player account from a title and deletes all associated data
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Deletes all data associated with the player, including statistics, custom data, inventory, purchases,
/// virtual currency balances, characters and shared group memberships. Removes the player from all leaderboards
/// and player search indexes. Does not delete PlayStream event history associated with the player. Does
/// not delete the publisher user account that created the player in the title nor associated data such
/// as username, password, email address, account linkages, or friends list. Note, this API queues the
/// player for deletion and returns immediately. It may take several minutes or more before all player
/// data is fully deleted. Until the player data is fully deleted, attempts to recreate the player with
/// the same user account in the same title will fail with the 'AccountDeleted' error. This API must be
/// enabled for use as an option in the game manager website. It is disabled by default.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementServerDeletePlayerAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementDeletePlayerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Deletes push notification template for title
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementServerDeletePushNotificationTemplateAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementDeletePushNotificationTemplateRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Retrieves the player's profile
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API allows for access to details regarding a user in the PlayFab service, usually for purposes
/// of customer support. Note that data returned may be Personally Identifying Information (PII), such
/// as email address, and so care should be taken in how this data is stored and managed. Since this call
/// will always return the relevant information for users who have accessed the title, the recommendation
/// is to not store this data locally.
///
/// If successful, call <see cref="PFAccountManagementServerGetPlayerProfileGetResult"/> to get the result.
/// </remarks>
HRESULT PFAccountManagementServerGetPlayerProfileAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementGetPlayerProfileRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetPlayerProfile call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementServerGetPlayerProfileGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementServerGetPlayerProfileAsync call.
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
HRESULT PFAccountManagementServerGetPlayerProfileGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayerProfileResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of Facebook identifiers.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementServerGetPlayFabIDsFromFacebookIDsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFAccountManagementServerGetPlayFabIDsFromFacebookIDsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromFacebookIDsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetPlayFabIDsFromFacebookIDs call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementServerGetPlayFabIDsFromFacebookIDsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementServerGetPlayFabIDsFromFacebookIDsAsync call.
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
HRESULT PFAccountManagementServerGetPlayFabIDsFromFacebookIDsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromFacebookIDsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of Facebook Instant Games identifiers.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementServerGetPlayFabIDsFromFacebookInstantGamesIdsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFAccountManagementServerGetPlayFabIDsFromFacebookInstantGamesIdsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetPlayFabIDsFromFacebookInstantGamesIds call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementServerGetPlayFabIDsFromFacebookInstantGamesIdsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementServerGetPlayFabIDsFromFacebookInstantGamesIdsAsync call.
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
HRESULT PFAccountManagementServerGetPlayFabIDsFromFacebookInstantGamesIdsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of generic service identifiers. A generic
/// identifier is the service name plus the service-specific ID for the player, as specified by the title
/// when the generic identifier was added to the player account.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerAddGenericIDAsync, ServerRemoveGenericIDAsync.
///
/// If successful, call <see cref="PFAccountManagementServerGetPlayFabIDsFromGenericIDsGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFAccountManagementServerGetPlayFabIDsFromGenericIDsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromGenericIDsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetPlayFabIDsFromGenericIDs call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementServerGetPlayFabIDsFromGenericIDsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementServerGetPlayFabIDsFromGenericIDsAsync call.
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
HRESULT PFAccountManagementServerGetPlayFabIDsFromGenericIDsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromGenericIDsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of Nintendo Switch Device identifiers.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementServerGetPlayFabIDsFromNintendoSwitchDeviceIdsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFAccountManagementServerGetPlayFabIDsFromNintendoSwitchDeviceIdsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetPlayFabIDsFromNintendoSwitchDeviceIds call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementServerGetPlayFabIDsFromNintendoSwitchDeviceIdsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementServerGetPlayFabIDsFromNintendoSwitchDeviceIdsAsync call.
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
HRESULT PFAccountManagementServerGetPlayFabIDsFromNintendoSwitchDeviceIdsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of PlayStation Network identifiers.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementServerGetPlayFabIDsFromPSNAccountIDsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFAccountManagementServerGetPlayFabIDsFromPSNAccountIDsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetPlayFabIDsFromPSNAccountIDs call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementServerGetPlayFabIDsFromPSNAccountIDsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementServerGetPlayFabIDsFromPSNAccountIDsAsync call.
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
HRESULT PFAccountManagementServerGetPlayFabIDsFromPSNAccountIDsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of Steam identifiers. The Steam identifiers
/// are the profile IDs for the user accounts, available as SteamId in the Steamworks Community API calls.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementServerGetPlayFabIDsFromSteamIDsGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFAccountManagementServerGetPlayFabIDsFromSteamIDsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromSteamIDsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetPlayFabIDsFromSteamIDs call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementServerGetPlayFabIDsFromSteamIDsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementServerGetPlayFabIDsFromSteamIDsAsync call.
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
HRESULT PFAccountManagementServerGetPlayFabIDsFromSteamIDsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromSteamIDsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the unique PlayFab identifiers for the given set of XboxLive identifiers.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementServerGetPlayFabIDsFromXboxLiveIDsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFAccountManagementServerGetPlayFabIDsFromXboxLiveIDsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetPlayFabIDsFromXboxLiveIDs call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementServerGetPlayFabIDsFromXboxLiveIDsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementServerGetPlayFabIDsFromXboxLiveIDsAsync call.
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
HRESULT PFAccountManagementServerGetPlayFabIDsFromXboxLiveIDsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the associated PlayFab account identifiers for the given set of server custom identifiers.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementServerGetServerCustomIDsFromPlayFabIDsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFAccountManagementServerGetServerCustomIDsFromPlayFabIDsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetServerCustomIDsFromPlayFabIDs call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementServerGetServerCustomIDsFromPlayFabIDsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementServerGetServerCustomIDsFromPlayFabIDsAsync call.
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
HRESULT PFAccountManagementServerGetServerCustomIDsFromPlayFabIDsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the relevant details for a specified user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API allows for access to details regarding a user in the PlayFab service, usually for purposes
/// of customer support. Note that data returned may be Personally Identifying Information (PII), such
/// as email address, and so care should be taken in how this data is stored and managed. Since this call
/// will always return the relevant information for users who have accessed the title, the recommendation
/// is to not store this data locally. See also ServerGetUserInventoryAsync.
///
/// If successful, call <see cref="PFAccountManagementServerGetUserAccountInfoGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFAccountManagementServerGetUserAccountInfoAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementGetUserAccountInfoRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetUserAccountInfo call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementServerGetUserAccountInfoGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementServerGetUserAccountInfoAsync call.
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
HRESULT PFAccountManagementServerGetUserAccountInfoGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetUserAccountInfoResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Gets all bans for a user.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Get all bans for a user, including inactive and expired bans.  See also ServerBanUsersAsync, ServerRevokeAllBansForUserAsync,
/// ServerRevokeBansAsync, ServerUpdateBansAsync.
///
/// If successful, call <see cref="PFAccountManagementServerGetUserBansGetResult"/> to get the result.
/// </remarks>
HRESULT PFAccountManagementServerGetUserBansAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementGetUserBansRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetUserBans call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementServerGetUserBansGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementServerGetUserBansAsync call.
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
HRESULT PFAccountManagementServerGetUserBansGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementGetUserBansResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Links the PlayStation Network account associated with the provided access code to the user's PlayFab
/// account
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerUnlinkPSNAccountAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementServerLinkPSNAccountAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementServerLinkPSNAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

/// <summary>
/// Links the custom server identifier, generated by the title, to the user's PlayFab account.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementServerLinkServerCustomIdAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementLinkServerCustomIdRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Links the Xbox Live account associated with the provided access code to the user's PlayFab account
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerLoginWithXboxAsync, ServerUnlinkXboxAccountAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementServerLinkXboxAccountAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementServerLinkXboxAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Removes the specified generic service identifier from the player's PlayFab account.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerAddGenericIDAsync, ServerGetPlayFabIDsFromGenericIDsAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementServerRemoveGenericIDAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementServerRemoveGenericIDRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Revoke all active bans for a user.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Setting the active state of all non-expired bans for a user to Inactive. Expired bans with an Active
/// state will be ignored, however. Returns information about applied updates only. See also ServerBanUsersAsync,
/// ServerGetUserBansAsync, ServerRevokeBansAsync, ServerUpdateBansAsync.
///
/// If successful, call <see cref="PFAccountManagementServerRevokeAllBansForUserGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFAccountManagementServerRevokeAllBansForUserAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementRevokeAllBansForUserRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerRevokeAllBansForUser call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementServerRevokeAllBansForUserGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementServerRevokeAllBansForUserAsync call.
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
HRESULT PFAccountManagementServerRevokeAllBansForUserGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementRevokeAllBansForUserResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Revoke all active bans specified with BanId.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Setting the active state of all bans requested to Inactive regardless of whether that ban has already
/// expired. BanIds that do not exist will be skipped. Returns information about applied updates only.
///  See also ServerBanUsersAsync, ServerGetUserBansAsync, ServerRevokeAllBansForUserAsync, ServerUpdateBansAsync.
///
/// If successful, call <see cref="PFAccountManagementServerRevokeBansGetResult"/> to get the result.
/// </remarks>
HRESULT PFAccountManagementServerRevokeBansAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementRevokeBansRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerRevokeBans call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementServerRevokeBansGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementServerRevokeBansAsync call.
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
HRESULT PFAccountManagementServerRevokeBansGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementRevokeBansResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Saves push notification template for title
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAccountManagementServerSavePushNotificationTemplateGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFAccountManagementServerSavePushNotificationTemplateAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementSavePushNotificationTemplateRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerSavePushNotificationTemplate call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementServerSavePushNotificationTemplateGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementServerSavePushNotificationTemplateAsync call.
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
HRESULT PFAccountManagementServerSavePushNotificationTemplateGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementSavePushNotificationTemplateResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Forces an email to be sent to the registered contact email address for the user's account based on
/// an account recovery email template
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// PlayFab accounts which have valid email address or username will be able to receive a password reset
/// email using this API.The email sent must be an account recovery email template. The username or email
/// can be passed in to send the email.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementServerSendCustomAccountRecoveryEmailAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementSendCustomAccountRecoveryEmailRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Sends an email based on an email template to a player's contact email 
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Sends an email for only players that have contact emails associated with them. Takes in an email
/// template ID specifyingthe email template to send.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementServerSendEmailFromTemplateAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementSendEmailFromTemplateRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Sends an iOS/Android Push Notification to a specific user, if that user's device has been configured
/// for Push Notifications in PlayFab. If a user has linked both Android and iOS devices, both will be
/// notified.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementServerSendPushNotificationAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementSendPushNotificationRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Sends an iOS/Android Push Notification template to a specific user, if that user's device has been
/// configured for Push Notifications in PlayFab. If a user has linked both Android and iOS devices, both
/// will be notified.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementServerSendPushNotificationFromTemplateAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementSendPushNotificationFromTemplateRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Unlinks the related PSN account from the user's PlayFab account
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerLinkPSNAccountAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementServerUnlinkPSNAccountAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementServerUnlinkPSNAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Unlinks the custom server identifier from the user's PlayFab account.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerLinkServerCustomIdAsync, ServerLoginWithServerCustomIdAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementServerUnlinkServerCustomIdAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementUnlinkServerCustomIdRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Unlinks the related Xbox Live account from the user's PlayFab account
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerLinkXboxAccountAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementServerUnlinkXboxAccountAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementServerUnlinkXboxAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Update the avatar URL of the specified player
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAccountManagementServerUpdateAvatarUrlAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementServerUpdateAvatarUrlRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Updates information of a list of existing bans specified with Ban Ids.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// For each ban, only updates the values that are set. Leave any value to null for no change. If a ban
/// could not be found, the rest are still applied. Returns information about applied updates only. See
/// also ServerBanUsersAsync, ServerGetUserBansAsync, ServerRevokeAllBansForUserAsync, ServerRevokeBansAsync.
///
/// If successful, call <see cref="PFAccountManagementServerUpdateBansGetResult"/> to get the result.
/// </remarks>
HRESULT PFAccountManagementServerUpdateBansAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAccountManagementUpdateBansRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerUpdateBans call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAccountManagementServerUpdateBansGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAccountManagementServerUpdateBansAsync call.
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
HRESULT PFAccountManagementServerUpdateBansGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAccountManagementUpdateBansResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;


}