// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFSharedDataModels.h>

extern "C"
{

#pragma push_macro("IN")
#undef IN

/// <summary>
/// AuthTokenType enum.
/// </summary>
enum class PFAccountManagementAuthTokenType : uint32_t
{
    Email
};

/// <summary>
/// PFAccountManagementBanRequest data model. Represents a single ban request.
/// </summary>
typedef struct PFAccountManagementBanRequest
{
    /// <summary>
    /// (Optional) The duration in hours for the ban. Leave this blank for a permanent ban.
    /// </summary>
    _Maybenull_ uint32_t const* durationInHours;

    /// <summary>
    /// (Optional) IP address to be banned. May affect multiple players.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* IPAddress;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) The reason for this ban. Maximum 140 characters.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reason;

} PFAccountManagementBanRequest;

/// <summary>
/// PFAccountManagementBanUsersRequest data model. The existence of each user will not be verified. When
/// banning by IP or MAC address, multiple players may be affected, so use this feature with caution.
/// Returns information about the new bans.
/// </summary>
typedef struct PFAccountManagementBanUsersRequest
{
    /// <summary>
    /// List of ban requests to be applied. Maximum 100.
    /// </summary>
    _Field_size_(bansCount) PFAccountManagementBanRequest const* const* bans;

    /// <summary>
    /// Count of bans
    /// </summary>
    uint32_t bansCount;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFAccountManagementBanUsersRequest;

/// <summary>
/// PFAccountManagementBanInfo data model. Contains information for a ban.
/// </summary>
typedef struct PFAccountManagementBanInfo
{
    /// <summary>
    /// The active state of this ban. Expired bans may still have this value set to true but they will
    /// have no effect.
    /// </summary>
    bool active;

    /// <summary>
    /// (Optional) The unique Ban Id associated with this ban.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* banId;

    /// <summary>
    /// (Optional) The time when this ban was applied.
    /// </summary>
    _Maybenull_ time_t const* created;

    /// <summary>
    /// (Optional) The time when this ban expires. Permanent bans do not have expiration date.
    /// </summary>
    _Maybenull_ time_t const* expires;

    /// <summary>
    /// (Optional) The IP address on which the ban was applied. May affect multiple players.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* IPAddress;

    /// <summary>
    /// (Optional) Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) The reason why this ban was applied.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reason;

} PFAccountManagementBanInfo;

/// <summary>
/// PFAccountManagementBanUsersResult data model.
/// </summary>
typedef struct PFAccountManagementBanUsersResult
{
    /// <summary>
    /// (Optional) Information on the bans that were applied.
    /// </summary>
    _Maybenull_ _Field_size_(banDataCount) PFAccountManagementBanInfo const* const* banData;

    /// <summary>
    /// Count of banData
    /// </summary>
    uint32_t banDataCount;

} PFAccountManagementBanUsersResult;

/// <summary>
/// PFAccountManagementDeleteMasterPlayerAccountRequest data model. Deletes all data associated with
/// the master player account, including data from all titles the player has played, such as statistics,
/// custom data, inventory, purchases, virtual currency balances, characters, group memberships, publisher
/// data, credential data, account linkages, friends list and PlayStream event history. Removes the player
/// from all leaderboards and player search indexes. Note, this API queues the player for deletion and
/// returns a receipt immediately. Record the receipt ID for future reference. It may take some time before
/// all player data is fully deleted. Upon completion of the deletion, an email will be sent to the notification
/// email address configured for the title confirming the deletion. Until the player data is fully deleted,
/// attempts to recreate the player with the same user account in the same title will fail with the 'AccountDeleted'
/// error. It is highly recommended to know the impact of the deletion by calling GetPlayedTitleList,
/// before calling this API.
/// </summary>
typedef struct PFAccountManagementDeleteMasterPlayerAccountRequest
{
    /// <summary>
    /// (Optional) Developer created string to identify a user without PlayFab ID.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* metaData;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementDeleteMasterPlayerAccountRequest;

/// <summary>
/// PFAccountManagementDeleteMasterPlayerAccountResult data model.
/// </summary>
typedef struct PFAccountManagementDeleteMasterPlayerAccountResult
{
    /// <summary>
    /// (Optional) A notification email with this job receipt Id will be sent to the title notification
    /// email address when deletion is complete.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* jobReceiptId;

    /// <summary>
    /// (Optional) List of titles from which the player's data will be deleted.
    /// </summary>
    _Maybenull_ _Field_size_(titleIdsCount) const char* const* titleIds;

    /// <summary>
    /// Count of titleIds
    /// </summary>
    uint32_t titleIdsCount;

} PFAccountManagementDeleteMasterPlayerAccountResult;

/// <summary>
/// PFAccountManagementDeleteMembershipSubscriptionRequest data model. This API lets developers delete
/// a membership subscription.
/// </summary>
typedef struct PFAccountManagementDeleteMembershipSubscriptionRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// Id of the membership to apply the override expiration date to.
    /// </summary>
    _Null_terminated_ const char* membershipId;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// Id of the subscription that should be deleted from the membership.
    /// </summary>
    _Null_terminated_ const char* subscriptionId;

} PFAccountManagementDeleteMembershipSubscriptionRequest;

/// <summary>
/// PFAccountManagementDeletePlayerRequest data model. Deletes all data associated with the player, including
/// statistics, custom data, inventory, purchases, virtual currency balances, characters and shared group
/// memberships. Removes the player from all leaderboards and player search indexes. Does not delete PlayStream
/// event history associated with the player. Does not delete the publisher user account that created
/// the player in the title nor associated data such as username, password, email address, account linkages,
/// or friends list. Note, this API queues the player for deletion and returns immediately. It may take
/// several minutes or more before all player data is fully deleted. Until the player data is fully deleted,
/// attempts to recreate the player with the same user account in the same title will fail with the 'AccountDeleted'
/// error.
/// </summary>
typedef struct PFAccountManagementDeletePlayerRequest
{
    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementDeletePlayerRequest;

/// <summary>
/// PFAccountManagementExportMasterPlayerDataRequest data model. Exports all data associated with the
/// master player account, including data from all titles the player has played, such as statistics, custom
/// data, inventory, purchases, virtual currency balances, characters, group memberships, publisher data,
/// credential data, account linkages, friends list and PlayStream event history. Note, this API queues
/// the player for export and returns a receipt immediately. Record the receipt ID for future reference.
/// It may take some time before the export is available for download. Upon completion of the export,
/// an email containing the URL to download the export dump will be sent to the notification email address
/// configured for the title.
/// </summary>
typedef struct PFAccountManagementExportMasterPlayerDataRequest
{
    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementExportMasterPlayerDataRequest;

/// <summary>
/// PFAccountManagementExportMasterPlayerDataResult data model.
/// </summary>
typedef struct PFAccountManagementExportMasterPlayerDataResult
{
    /// <summary>
    /// (Optional) An email with this job receipt Id containing the export download link will be sent
    /// to the title notification email address when the export is complete.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* jobReceiptId;

} PFAccountManagementExportMasterPlayerDataResult;

/// <summary>
/// PFAccountManagementGetPlayedTitleListRequest data model. Useful for identifying titles of which the
/// player's data will be deleted by DeleteMasterPlayer.
/// </summary>
typedef struct PFAccountManagementGetPlayedTitleListRequest
{
    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementGetPlayedTitleListRequest;

/// <summary>
/// PFAccountManagementGetPlayedTitleListResult data model.
/// </summary>
typedef struct PFAccountManagementGetPlayedTitleListResult
{
    /// <summary>
    /// (Optional) List of titles the player has played.
    /// </summary>
    _Maybenull_ _Field_size_(titleIdsCount) const char* const* titleIds;

    /// <summary>
    /// Count of titleIds
    /// </summary>
    uint32_t titleIdsCount;

} PFAccountManagementGetPlayedTitleListResult;

/// <summary>
/// PFAccountManagementGetPlayerIdFromAuthTokenRequest data model. Gets a player ID from an auth token.
/// The token expires after 30 minutes and cannot be used to look up a player when expired.
/// </summary>
typedef struct PFAccountManagementGetPlayerIdFromAuthTokenRequest
{
    /// <summary>
    /// The auth token of the player requesting the password reset.
    /// </summary>
    _Null_terminated_ const char* token;

    /// <summary>
    /// The type of auth token of the player requesting the password reset.
    /// </summary>
    PFAccountManagementAuthTokenType tokenType;

} PFAccountManagementGetPlayerIdFromAuthTokenRequest;

/// <summary>
/// PFAccountManagementGetPlayerIdFromAuthTokenResult data model.
/// </summary>
typedef struct PFAccountManagementGetPlayerIdFromAuthTokenResult
{
    /// <summary>
    /// (Optional) The player ID from the token passed in.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

} PFAccountManagementGetPlayerIdFromAuthTokenResult;

/// <summary>
/// PFAccountManagementGetPlayerProfileRequest data model. This API allows for access to details regarding
/// a user in the PlayFab service, usually for purposes of customer support. Note that data returned may
/// be Personally Identifying Information (PII), such as email address, and so care should be taken in
/// how this data is stored and managed. Since this call will always return the relevant information for
/// users who have accessed the title, the recommendation is to not store this data locally.
/// </summary>
typedef struct PFAccountManagementGetPlayerProfileRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) If non-null, this determines which properties of the resulting player profiles to
    /// return. For API calls from the client, only the allowed client profile properties for the title
    /// may be requested. These allowed properties are configured in the Game Manager "Client Profile
    /// Options" tab in the "Settings" section.
    /// </summary>
    _Maybenull_ PFPlayerProfileViewConstraints const* profileConstraints;

} PFAccountManagementGetPlayerProfileRequest;

/// <summary>
/// PFAccountManagementGetPlayerProfileResult data model.
/// </summary>
typedef struct PFAccountManagementGetPlayerProfileResult
{
    /// <summary>
    /// (Optional) The profile of the player. This profile is not guaranteed to be up-to-date. For a
    /// new player, this profile will not exist.
    /// </summary>
    _Maybenull_ PFPlayerProfileModel const* playerProfile;

} PFAccountManagementGetPlayerProfileResult;

/// <summary>
/// PFAccountManagementLookupUserAccountInfoRequest data model. This API allows for access to details
/// regarding a user in the PlayFab service, usually for purposes of customer support. Note that data
/// returned may be Personally Identifying Information (PII), such as email address, and so care should
/// be taken in how this data is stored and managed. Since this call will always return the relevant information
/// for users who have accessed the title, the recommendation is to not store this data locally.
/// </summary>
typedef struct PFAccountManagementLookupUserAccountInfoRequest
{
    /// <summary>
    /// (Optional) User email address attached to their account.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* email;

    /// <summary>
    /// (Optional) Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) Title specific username to match against existing user accounts.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* titleDisplayName;

    /// <summary>
    /// (Optional) PlayFab username for the account (3-20 characters).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* username;

} PFAccountManagementLookupUserAccountInfoRequest;

/// <summary>
/// PFAccountManagementLookupUserAccountInfoResult data model.
/// </summary>
typedef struct PFAccountManagementLookupUserAccountInfoResult
{
    /// <summary>
    /// (Optional) User info for the user matching the request.
    /// </summary>
    _Maybenull_ PFUserAccountInfo const* userInfo;

} PFAccountManagementLookupUserAccountInfoResult;

/// <summary>
/// PFAccountManagementGetUserBansRequest data model. Get all bans for a user, including inactive and
/// expired bans. .
/// </summary>
typedef struct PFAccountManagementGetUserBansRequest
{
    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementGetUserBansRequest;

/// <summary>
/// PFAccountManagementGetUserBansResult data model.
/// </summary>
typedef struct PFAccountManagementGetUserBansResult
{
    /// <summary>
    /// (Optional) Information about the bans.
    /// </summary>
    _Maybenull_ _Field_size_(banDataCount) PFAccountManagementBanInfo const* const* banData;

    /// <summary>
    /// Count of banData
    /// </summary>
    uint32_t banDataCount;

} PFAccountManagementGetUserBansResult;

/// <summary>
/// PFAccountManagementResetPasswordRequest data model. Resets a player's password taking in a new password
/// based and validating the user based off of a token sent to the playerto their email. The token expires
/// after 30 minutes.
/// </summary>
typedef struct PFAccountManagementResetPasswordRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// The new password for the player.
    /// </summary>
    _Null_terminated_ const char* password;

    /// <summary>
    /// The token of the player requesting the password reset.
    /// </summary>
    _Null_terminated_ const char* token;

} PFAccountManagementResetPasswordRequest;

/// <summary>
/// PFAccountManagementRevokeAllBansForUserRequest data model. Setting the active state of all non-expired
/// bans for a user to Inactive. Expired bans with an Active state will be ignored, however. Returns information
/// about applied updates only.
/// </summary>
typedef struct PFAccountManagementRevokeAllBansForUserRequest
{
    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementRevokeAllBansForUserRequest;

/// <summary>
/// PFAccountManagementRevokeAllBansForUserResult data model.
/// </summary>
typedef struct PFAccountManagementRevokeAllBansForUserResult
{
    /// <summary>
    /// (Optional) Information on the bans that were revoked.
    /// </summary>
    _Maybenull_ _Field_size_(banDataCount) PFAccountManagementBanInfo const* const* banData;

    /// <summary>
    /// Count of banData
    /// </summary>
    uint32_t banDataCount;

} PFAccountManagementRevokeAllBansForUserResult;

/// <summary>
/// PFAccountManagementRevokeBansRequest data model. Setting the active state of all bans requested to
/// Inactive regardless of whether that ban has already expired. BanIds that do not exist will be skipped.
/// Returns information about applied updates only. .
/// </summary>
typedef struct PFAccountManagementRevokeBansRequest
{
    /// <summary>
    /// Ids of the bans to be revoked. Maximum 100.
    /// </summary>
    _Field_size_(banIdsCount) const char* const* banIds;

    /// <summary>
    /// Count of banIds
    /// </summary>
    uint32_t banIdsCount;

} PFAccountManagementRevokeBansRequest;

/// <summary>
/// PFAccountManagementRevokeBansResult data model.
/// </summary>
typedef struct PFAccountManagementRevokeBansResult
{
    /// <summary>
    /// (Optional) Information on the bans that were revoked.
    /// </summary>
    _Maybenull_ _Field_size_(banDataCount) PFAccountManagementBanInfo const* const* banData;

    /// <summary>
    /// Count of banData
    /// </summary>
    uint32_t banDataCount;

} PFAccountManagementRevokeBansResult;

/// <summary>
/// PFAccountManagementAdminSendAccountRecoveryEmailRequest data model. If the account in question is
/// a "temporary" account (for example, one that was created via a call to LoginFromIOSDeviceID), thisfunction
/// will have no effect. Only PlayFab accounts which have valid email addresses will be able to receive
/// a password reset email using this API.
/// </summary>
typedef struct PFAccountManagementAdminSendAccountRecoveryEmailRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// User email address attached to their account.
    /// </summary>
    _Null_terminated_ const char* email;

    /// <summary>
    /// (Optional) The email template id of the account recovery email template to send.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* emailTemplateId;

} PFAccountManagementAdminSendAccountRecoveryEmailRequest;

/// <summary>
/// PFAccountManagementSetMembershipOverrideRequest data model. This API lets developers set overrides
/// for membership expirations, independent of any subscriptions setting it.
/// </summary>
typedef struct PFAccountManagementSetMembershipOverrideRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// Expiration time for the membership in DateTime format, will override any subscription expirations.
    /// </summary>
    time_t expirationTime;

    /// <summary>
    /// Id of the membership to apply the override expiration date to.
    /// </summary>
    _Null_terminated_ const char* membershipId;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementSetMembershipOverrideRequest;

/// <summary>
/// PFAccountManagementUpdateBanRequest data model. Represents a single update ban request.
/// </summary>
typedef struct PFAccountManagementUpdateBanRequest
{
    /// <summary>
    /// (Optional) The updated active state for the ban. Null for no change.
    /// </summary>
    _Maybenull_ bool const* active;

    /// <summary>
    /// The id of the ban to be updated.
    /// </summary>
    _Null_terminated_ const char* banId;

    /// <summary>
    /// (Optional) The updated expiration date for the ban. Null for no change.
    /// </summary>
    _Maybenull_ time_t const* expires;

    /// <summary>
    /// (Optional) The updated IP address for the ban. Null for no change.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* IPAddress;

    /// <summary>
    /// (Optional) Whether to make this ban permanent. Set to true to make this ban permanent. This will
    /// not modify Active state.
    /// </summary>
    _Maybenull_ bool const* permanent;

    /// <summary>
    /// (Optional) The updated reason for the ban to be updated. Maximum 140 characters. Null for no
    /// change.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reason;

} PFAccountManagementUpdateBanRequest;

/// <summary>
/// PFAccountManagementUpdateBansRequest data model. For each ban, only updates the values that are set.
/// Leave any value to null for no change. If a ban could not be found, the rest are still applied. Returns
/// information about applied updates only.
/// </summary>
typedef struct PFAccountManagementUpdateBansRequest
{
    /// <summary>
    /// List of bans to be updated. Maximum 100.
    /// </summary>
    _Field_size_(bansCount) PFAccountManagementUpdateBanRequest const* const* bans;

    /// <summary>
    /// Count of bans
    /// </summary>
    uint32_t bansCount;

} PFAccountManagementUpdateBansRequest;

/// <summary>
/// PFAccountManagementUpdateBansResult data model.
/// </summary>
typedef struct PFAccountManagementUpdateBansResult
{
    /// <summary>
    /// (Optional) Information on the bans that were updated.
    /// </summary>
    _Maybenull_ _Field_size_(banDataCount) PFAccountManagementBanInfo const* const* banData;

    /// <summary>
    /// Count of banData
    /// </summary>
    uint32_t banDataCount;

} PFAccountManagementUpdateBansResult;

/// <summary>
/// PFAccountManagementAdminUpdateUserTitleDisplayNameRequest data model. In addition to the PlayFab
/// username, titles can make use of a DisplayName which is also a unique identifier, but specific to
/// the title. This allows for unique names which more closely match the theme or genre of a title, for
/// example. This API enables changing that name, whether due to a customer request, an offensive name
/// choice, etc.
/// </summary>
typedef struct PFAccountManagementAdminUpdateUserTitleDisplayNameRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// New title display name for the user - must be between 3 and 25 characters.
    /// </summary>
    _Null_terminated_ const char* displayName;

    /// <summary>
    /// PlayFab unique identifier of the user whose title specific display name is to be changed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementAdminUpdateUserTitleDisplayNameRequest;

/// <summary>
/// PFAccountManagementUpdateUserTitleDisplayNameResult data model.
/// </summary>
typedef struct PFAccountManagementUpdateUserTitleDisplayNameResult
{
    /// <summary>
    /// (Optional) Current title display name for the user (this will be the original display name if
    /// the rename attempt failed).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* displayName;

} PFAccountManagementUpdateUserTitleDisplayNameResult;

/// <summary>
/// PFAccountManagementGenericServiceId data model.
/// </summary>
typedef struct PFAccountManagementGenericServiceId
{
    /// <summary>
    /// Name of the service for which the player has a unique identifier.
    /// </summary>
    _Null_terminated_ const char* serviceName;

    /// <summary>
    /// Unique identifier of the player in that service.
    /// </summary>
    _Null_terminated_ const char* userId;

} PFAccountManagementGenericServiceId;

/// <summary>
/// PFAccountManagementClientAddGenericIDRequest data model.
/// </summary>
typedef struct PFAccountManagementClientAddGenericIDRequest
{
    /// <summary>
    /// Generic service identifier to add to the player account.
    /// </summary>
    PFAccountManagementGenericServiceId const* genericId;

} PFAccountManagementClientAddGenericIDRequest;

/// <summary>
/// PFAccountManagementAddOrUpdateContactEmailRequest data model. This API adds a contact email to the
/// player's profile. If the player's profile already contains a contact email, it will update the contact
/// email to the email address specified.
/// </summary>
typedef struct PFAccountManagementAddOrUpdateContactEmailRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// The new contact email to associate with the player.
    /// </summary>
    _Null_terminated_ const char* emailAddress;

} PFAccountManagementAddOrUpdateContactEmailRequest;

/// <summary>
/// PFAccountManagementAddUsernamePasswordRequest data model.
/// </summary>
typedef struct PFAccountManagementAddUsernamePasswordRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// User email address attached to their account.
    /// </summary>
    _Null_terminated_ const char* email;

    /// <summary>
    /// Password for the PlayFab account (6-100 characters).
    /// </summary>
    _Null_terminated_ const char* password;

    /// <summary>
    /// PlayFab username for the account (3-20 characters).
    /// </summary>
    _Null_terminated_ const char* username;

} PFAccountManagementAddUsernamePasswordRequest;

/// <summary>
/// PFAccountManagementAddUsernamePasswordResult data model. Each account must have a unique username
/// and email address in the PlayFab service. Once created, the account may be associated with additional
/// accounts (Steam, Facebook, Game Center, etc.), allowing for added social network lists and achievements
/// systems. This can also be used to provide a recovery method if the user loses their original means
/// of access.
/// </summary>
typedef struct PFAccountManagementAddUsernamePasswordResult
{
    /// <summary>
    /// (Optional) PlayFab unique user name.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* username;

} PFAccountManagementAddUsernamePasswordResult;

/// <summary>
/// PFAccountManagementGetAccountInfoRequest data model.
/// </summary>
typedef struct PFAccountManagementGetAccountInfoRequest
{
    /// <summary>
    /// (Optional) User email address for the account to find (if no Username is specified).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* email;

    /// <summary>
    /// (Optional) Unique PlayFab identifier of the user whose info is being requested. Optional, defaults
    /// to the authenticated user if no other lookup identifier set.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) Title-specific username for the account to find (if no Email is set). Note that if
    /// the non-unique Title Display Names option is enabled for the title, attempts to look up users
    /// by Title Display Name will always return AccountNotFound.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* titleDisplayName;

    /// <summary>
    /// (Optional) PlayFab Username for the account to find (if no PlayFabId is specified).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* username;

} PFAccountManagementGetAccountInfoRequest;

/// <summary>
/// PFAccountManagementGetAccountInfoResult data model. This API retrieves details regarding the player
/// in the PlayFab service. Note that when this call is used to retrieve data about another player (not
/// the one signed into the local client), some data, such as Personally Identifying Information (PII),
/// will be omitted for privacy reasons or to comply with the requirements of the platform belongs to.
/// The user account returned will be based on the identifier provided in priority order: PlayFabId, Username,
/// Email, then TitleDisplayName. If no identifier is specified, the currently signed in user's information
/// will be returned.
/// </summary>
typedef struct PFAccountManagementGetAccountInfoResult
{
    /// <summary>
    /// (Optional) Account information for the local user.
    /// </summary>
    _Maybenull_ PFUserAccountInfo const* accountInfo;

} PFAccountManagementGetAccountInfoResult;

/// <summary>
/// PFAccountManagementGetPlayerCombinedInfoRequest data model.
/// </summary>
typedef struct PFAccountManagementGetPlayerCombinedInfoRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// Flags for which pieces of info to return for the user.
    /// </summary>
    PFGetPlayerCombinedInfoRequestParams const* infoRequestParameters;

    /// <summary>
    /// PlayFabId of the user whose data will be returned. If not filled included, we return the data
    /// for the calling player. .
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementGetPlayerCombinedInfoRequest;

/// <summary>
/// PFAccountManagementGetPlayerCombinedInfoResult data model. Returns whatever info is requested in
/// the response for the user. If no user is explicitly requested this defaults to the authenticated user.
/// If the user is the same as the requester, PII (like email address, facebook id) is returned if available.
/// Otherwise, only public information is returned. All parameters default to false.
/// </summary>
typedef struct PFAccountManagementGetPlayerCombinedInfoResult
{
    /// <summary>
    /// (Optional) Results for requested info.
    /// </summary>
    _Maybenull_ PFGetPlayerCombinedInfoResultPayload const* infoResultPayload;

    /// <summary>
    /// (Optional) Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

} PFAccountManagementGetPlayerCombinedInfoResult;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromFacebookIDsRequest data model.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromFacebookIDsRequest
{
    /// <summary>
    /// Array of unique Facebook identifiers for which the title needs to get PlayFab identifiers.
    /// </summary>
    _Field_size_(facebookIDsCount) const char* const* facebookIDs;

    /// <summary>
    /// Count of facebookIDs
    /// </summary>
    uint32_t facebookIDsCount;

} PFAccountManagementGetPlayFabIDsFromFacebookIDsRequest;

/// <summary>
/// PFAccountManagementFacebookPlayFabIdPair data model.
/// </summary>
typedef struct PFAccountManagementFacebookPlayFabIdPair
{
    /// <summary>
    /// (Optional) Unique Facebook identifier for a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* facebookId;

    /// <summary>
    /// (Optional) Unique PlayFab identifier for a user, or null if no PlayFab account is linked to the
    /// Facebook identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

} PFAccountManagementFacebookPlayFabIdPair;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromFacebookIDsResult data model. For Facebook identifiers which
/// have not been linked to PlayFab accounts, null will be returned.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromFacebookIDsResult
{
    /// <summary>
    /// (Optional) Mapping of Facebook identifiers to PlayFab identifiers.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) PFAccountManagementFacebookPlayFabIdPair const* const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

} PFAccountManagementGetPlayFabIDsFromFacebookIDsResult;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequest data model.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequest
{
    /// <summary>
    /// Array of unique Facebook Instant Games identifiers for which the title needs to get PlayFab identifiers.
    /// </summary>
    _Field_size_(facebookInstantGamesIdsCount) const char* const* facebookInstantGamesIds;

    /// <summary>
    /// Count of facebookInstantGamesIds
    /// </summary>
    uint32_t facebookInstantGamesIdsCount;

} PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequest;

/// <summary>
/// PFAccountManagementFacebookInstantGamesPlayFabIdPair data model.
/// </summary>
typedef struct PFAccountManagementFacebookInstantGamesPlayFabIdPair
{
    /// <summary>
    /// (Optional) Unique Facebook Instant Games identifier for a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* facebookInstantGamesId;

    /// <summary>
    /// (Optional) Unique PlayFab identifier for a user, or null if no PlayFab account is linked to the
    /// Facebook Instant Games identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

} PFAccountManagementFacebookInstantGamesPlayFabIdPair;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult data model. For Facebook Instant
/// Game identifiers which have not been linked to PlayFab accounts, null will be returned.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult
{
    /// <summary>
    /// (Optional) Mapping of Facebook Instant Games identifiers to PlayFab identifiers.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) PFAccountManagementFacebookInstantGamesPlayFabIdPair const* const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

} PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequest data model.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequest
{
    /// <summary>
    /// Array of unique Game Center identifiers (the Player Identifier) for which the title needs to
    /// get PlayFab identifiers.
    /// </summary>
    _Field_size_(gameCenterIDsCount) const char* const* gameCenterIDs;

    /// <summary>
    /// Count of gameCenterIDs
    /// </summary>
    uint32_t gameCenterIDsCount;

} PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequest;

/// <summary>
/// PFAccountManagementGameCenterPlayFabIdPair data model.
/// </summary>
typedef struct PFAccountManagementGameCenterPlayFabIdPair
{
    /// <summary>
    /// (Optional) Unique Game Center identifier for a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* gameCenterId;

    /// <summary>
    /// (Optional) Unique PlayFab identifier for a user, or null if no PlayFab account is linked to the
    /// Game Center identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

} PFAccountManagementGameCenterPlayFabIdPair;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult data model. For Game Center identifiers which
/// have not been linked to PlayFab accounts, null will be returned.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult
{
    /// <summary>
    /// (Optional) Mapping of Game Center identifiers to PlayFab identifiers.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) PFAccountManagementGameCenterPlayFabIdPair const* const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

} PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromGenericIDsRequest data model.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromGenericIDsRequest
{
    /// <summary>
    /// Array of unique generic service identifiers for which the title needs to get PlayFab identifiers.
    /// Currently limited to a maximum of 10 in a single request.
    /// </summary>
    _Field_size_(genericIDsCount) PFAccountManagementGenericServiceId const* const* genericIDs;

    /// <summary>
    /// Count of genericIDs
    /// </summary>
    uint32_t genericIDsCount;

} PFAccountManagementGetPlayFabIDsFromGenericIDsRequest;

/// <summary>
/// PFAccountManagementGenericPlayFabIdPair data model.
/// </summary>
typedef struct PFAccountManagementGenericPlayFabIdPair
{
    /// <summary>
    /// (Optional) Unique generic service identifier for a user.
    /// </summary>
    _Maybenull_ PFAccountManagementGenericServiceId const* genericId;

    /// <summary>
    /// (Optional) Unique PlayFab identifier for a user, or null if no PlayFab account is linked to the
    /// given generic identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

} PFAccountManagementGenericPlayFabIdPair;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromGenericIDsResult data model. For generic service identifiers
/// which have not been linked to PlayFab accounts, null will be returned.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromGenericIDsResult
{
    /// <summary>
    /// (Optional) Mapping of generic service identifiers to PlayFab identifiers.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) PFAccountManagementGenericPlayFabIdPair const* const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

} PFAccountManagementGetPlayFabIDsFromGenericIDsResult;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromGoogleIDsRequest data model.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromGoogleIDsRequest
{
    /// <summary>
    /// Array of unique Google identifiers (Google+ user IDs) for which the title needs to get PlayFab
    /// identifiers.
    /// </summary>
    _Field_size_(googleIDsCount) const char* const* googleIDs;

    /// <summary>
    /// Count of googleIDs
    /// </summary>
    uint32_t googleIDsCount;

} PFAccountManagementGetPlayFabIDsFromGoogleIDsRequest;

/// <summary>
/// PFAccountManagementGooglePlayFabIdPair data model.
/// </summary>
typedef struct PFAccountManagementGooglePlayFabIdPair
{
    /// <summary>
    /// (Optional) Unique Google identifier for a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* googleId;

    /// <summary>
    /// (Optional) Unique PlayFab identifier for a user, or null if no PlayFab account is linked to the
    /// Google identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

} PFAccountManagementGooglePlayFabIdPair;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromGoogleIDsResult data model. For Google identifiers which have
/// not been linked to PlayFab accounts, null will be returned.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromGoogleIDsResult
{
    /// <summary>
    /// (Optional) Mapping of Google identifiers to PlayFab identifiers.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) PFAccountManagementGooglePlayFabIdPair const* const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

} PFAccountManagementGetPlayFabIDsFromGoogleIDsResult;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsRequest data model.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsRequest
{
    /// <summary>
    /// Array of unique Google Play Games identifiers (Google+ user IDs) for which the title needs to
    /// get PlayFab identifiers.
    /// </summary>
    _Field_size_(googlePlayGamesPlayerIDsCount) const char* const* googlePlayGamesPlayerIDs;

    /// <summary>
    /// Count of googlePlayGamesPlayerIDs
    /// </summary>
    uint32_t googlePlayGamesPlayerIDsCount;

} PFAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsRequest;

/// <summary>
/// PFAccountManagementGooglePlayGamesPlayFabIdPair data model.
/// </summary>
typedef struct PFAccountManagementGooglePlayGamesPlayFabIdPair
{
    /// <summary>
    /// (Optional) Unique Google Play Games identifier for a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* googlePlayGamesPlayerId;

    /// <summary>
    /// (Optional) Unique PlayFab identifier for a user, or null if no PlayFab account is linked to the
    /// Google Play Games identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

} PFAccountManagementGooglePlayGamesPlayFabIdPair;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsResult data model. For Google Play Games
/// identifiers which have not been linked to PlayFab accounts, null will be returned.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsResult
{
    /// <summary>
    /// (Optional) Mapping of Google Play Games identifiers to PlayFab identifiers.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) PFAccountManagementGooglePlayGamesPlayFabIdPair const* const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

} PFAccountManagementGetPlayFabIDsFromGooglePlayGamesPlayerIDsResult;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromKongregateIDsRequest data model.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromKongregateIDsRequest
{
    /// <summary>
    /// Array of unique Kongregate identifiers (Kongregate's user_id) for which the title needs to get
    /// PlayFab identifiers.
    /// </summary>
    _Field_size_(kongregateIDsCount) const char* const* kongregateIDs;

    /// <summary>
    /// Count of kongregateIDs
    /// </summary>
    uint32_t kongregateIDsCount;

} PFAccountManagementGetPlayFabIDsFromKongregateIDsRequest;

/// <summary>
/// PFAccountManagementKongregatePlayFabIdPair data model.
/// </summary>
typedef struct PFAccountManagementKongregatePlayFabIdPair
{
    /// <summary>
    /// (Optional) Unique Kongregate identifier for a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* kongregateId;

    /// <summary>
    /// (Optional) Unique PlayFab identifier for a user, or null if no PlayFab account is linked to the
    /// Kongregate identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

} PFAccountManagementKongregatePlayFabIdPair;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromKongregateIDsResult data model. For Kongregate identifiers which
/// have not been linked to PlayFab accounts, null will be returned.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromKongregateIDsResult
{
    /// <summary>
    /// (Optional) Mapping of Kongregate identifiers to PlayFab identifiers.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) PFAccountManagementKongregatePlayFabIdPair const* const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

} PFAccountManagementGetPlayFabIDsFromKongregateIDsResult;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsRequest data model.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsRequest
{
    /// <summary>
    /// Array of unique Nintendo Switch Account identifiers for which the title needs to get PlayFab
    /// identifiers.
    /// </summary>
    _Field_size_(nintendoAccountIdsCount) const char* const* nintendoAccountIds;

    /// <summary>
    /// Count of nintendoAccountIds
    /// </summary>
    uint32_t nintendoAccountIdsCount;

} PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsRequest;

/// <summary>
/// PFAccountManagementNintendoServiceAccountPlayFabIdPair data model.
/// </summary>
typedef struct PFAccountManagementNintendoServiceAccountPlayFabIdPair
{
    /// <summary>
    /// (Optional) Unique Nintendo Switch Service Account identifier for a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* nintendoServiceAccountId;

    /// <summary>
    /// (Optional) Unique PlayFab identifier for a user, or null if no PlayFab account is linked to the
    /// Nintendo Switch Service Account identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

} PFAccountManagementNintendoServiceAccountPlayFabIdPair;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsResult data model. For Nintendo Service
/// Account identifiers which have not been linked to PlayFab accounts, null will be returned.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsResult
{
    /// <summary>
    /// (Optional) Mapping of Nintendo Switch Service Account identifiers to PlayFab identifiers.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) PFAccountManagementNintendoServiceAccountPlayFabIdPair const* const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

} PFAccountManagementGetPlayFabIDsFromNintendoServiceAccountIdsResult;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest data model.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest
{
    /// <summary>
    /// Array of unique Nintendo Switch Device identifiers for which the title needs to get PlayFab identifiers.
    /// </summary>
    _Field_size_(nintendoSwitchDeviceIdsCount) const char* const* nintendoSwitchDeviceIds;

    /// <summary>
    /// Count of nintendoSwitchDeviceIds
    /// </summary>
    uint32_t nintendoSwitchDeviceIdsCount;

} PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest;

/// <summary>
/// PFAccountManagementNintendoSwitchPlayFabIdPair data model.
/// </summary>
typedef struct PFAccountManagementNintendoSwitchPlayFabIdPair
{
    /// <summary>
    /// (Optional) Unique Nintendo Switch Device identifier for a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* nintendoSwitchDeviceId;

    /// <summary>
    /// (Optional) Unique PlayFab identifier for a user, or null if no PlayFab account is linked to the
    /// Nintendo Switch Device identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

} PFAccountManagementNintendoSwitchPlayFabIdPair;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult data model. For Nintendo Switch
/// identifiers which have not been linked to PlayFab accounts, null will be returned.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult
{
    /// <summary>
    /// (Optional) Mapping of Nintendo Switch Device identifiers to PlayFab identifiers.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) PFAccountManagementNintendoSwitchPlayFabIdPair const* const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

} PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequest data model.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequest
{
    /// <summary>
    /// (Optional) Id of the PlayStation :tm: Network issuer environment. If null, defaults to production
    /// environment.
    /// </summary>
    _Maybenull_ int32_t const* issuerId;

    /// <summary>
    /// Array of unique PlayStation :tm: Network identifiers for which the title needs to get PlayFab
    /// identifiers.
    /// </summary>
    _Field_size_(PSNAccountIDsCount) const char* const* PSNAccountIDs;

    /// <summary>
    /// Count of PSNAccountIDs
    /// </summary>
    uint32_t PSNAccountIDsCount;

} PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequest;

/// <summary>
/// PFAccountManagementPSNAccountPlayFabIdPair data model.
/// </summary>
typedef struct PFAccountManagementPSNAccountPlayFabIdPair
{
    /// <summary>
    /// (Optional) Unique PlayFab identifier for a user, or null if no PlayFab account is linked to the
    /// PlayStation :tm: Network identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) Unique PlayStation :tm: Network identifier for a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* PSNAccountId;

} PFAccountManagementPSNAccountPlayFabIdPair;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult data model. For PlayStation :tm: Network
/// identifiers which have not been linked to PlayFab accounts, null will be returned.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult
{
    /// <summary>
    /// (Optional) Mapping of PlayStation :tm: Network identifiers to PlayFab identifiers.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) PFAccountManagementPSNAccountPlayFabIdPair const* const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

} PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromSteamIDsRequest data model.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromSteamIDsRequest
{
    /// <summary>
    /// (Optional) Array of unique Steam identifiers (Steam profile IDs) for which the title needs to
    /// get PlayFab identifiers.
    /// </summary>
    _Maybenull_ _Field_size_(steamStringIDsCount) const char* const* steamStringIDs;

    /// <summary>
    /// Count of steamStringIDs
    /// </summary>
    uint32_t steamStringIDsCount;

} PFAccountManagementGetPlayFabIDsFromSteamIDsRequest;

/// <summary>
/// PFAccountManagementSteamPlayFabIdPair data model.
/// </summary>
typedef struct PFAccountManagementSteamPlayFabIdPair
{
    /// <summary>
    /// (Optional) Unique PlayFab identifier for a user, or null if no PlayFab account is linked to the
    /// Steam identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) Unique Steam identifier for a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* steamStringId;

} PFAccountManagementSteamPlayFabIdPair;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromSteamIDsResult data model. For Steam identifiers which have not
/// been linked to PlayFab accounts, null will be returned.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromSteamIDsResult
{
    /// <summary>
    /// (Optional) Mapping of Steam identifiers to PlayFab identifiers.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) PFAccountManagementSteamPlayFabIdPair const* const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

} PFAccountManagementGetPlayFabIDsFromSteamIDsResult;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromTwitchIDsRequest data model.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromTwitchIDsRequest
{
    /// <summary>
    /// Array of unique Twitch identifiers (Twitch's _id) for which the title needs to get PlayFab identifiers.
    /// </summary>
    _Field_size_(twitchIdsCount) const char* const* twitchIds;

    /// <summary>
    /// Count of twitchIds
    /// </summary>
    uint32_t twitchIdsCount;

} PFAccountManagementGetPlayFabIDsFromTwitchIDsRequest;

/// <summary>
/// PFAccountManagementTwitchPlayFabIdPair data model.
/// </summary>
typedef struct PFAccountManagementTwitchPlayFabIdPair
{
    /// <summary>
    /// (Optional) Unique PlayFab identifier for a user, or null if no PlayFab account is linked to the
    /// Twitch identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) Unique Twitch identifier for a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* twitchId;

} PFAccountManagementTwitchPlayFabIdPair;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromTwitchIDsResult data model. For Twitch identifiers which have
/// not been linked to PlayFab accounts, null will be returned.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromTwitchIDsResult
{
    /// <summary>
    /// (Optional) Mapping of Twitch identifiers to PlayFab identifiers.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) PFAccountManagementTwitchPlayFabIdPair const* const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

} PFAccountManagementGetPlayFabIDsFromTwitchIDsResult;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequest data model.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequest
{
    /// <summary>
    /// (Optional) The ID of Xbox Live sandbox.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* sandbox;

    /// <summary>
    /// Array of unique Xbox Live account identifiers for which the title needs to get PlayFab identifiers.
    /// </summary>
    _Field_size_(xboxLiveAccountIDsCount) const char* const* xboxLiveAccountIDs;

    /// <summary>
    /// Count of xboxLiveAccountIDs
    /// </summary>
    uint32_t xboxLiveAccountIDsCount;

} PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequest;

/// <summary>
/// PFAccountManagementXboxLiveAccountPlayFabIdPair data model.
/// </summary>
typedef struct PFAccountManagementXboxLiveAccountPlayFabIdPair
{
    /// <summary>
    /// (Optional) Unique PlayFab identifier for a user, or null if no PlayFab account is linked to the
    /// Xbox Live identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) Unique Xbox Live identifier for a user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* xboxLiveAccountId;

} PFAccountManagementXboxLiveAccountPlayFabIdPair;

/// <summary>
/// PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult data model. For XboxLive identifiers which
/// have not been linked to PlayFab accounts, null will be returned.
/// </summary>
typedef struct PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult
{
    /// <summary>
    /// (Optional) Mapping of Xbox Live identifiers to PlayFab identifiers.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) PFAccountManagementXboxLiveAccountPlayFabIdPair const* const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

} PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult;

/// <summary>
/// PFAccountManagementLinkAndroidDeviceIDRequest data model.
/// </summary>
typedef struct PFAccountManagementLinkAndroidDeviceIDRequest
{
    /// <summary>
    /// (Optional) Specific model of the user's device.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* androidDevice;

    /// <summary>
    /// Android device identifier for the user's device.
    /// </summary>
    _Null_terminated_ const char* androidDeviceId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to the device, unlink the other user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// (Optional) Specific Operating System version for the user's device.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* OS;

} PFAccountManagementLinkAndroidDeviceIDRequest;

/// <summary>
/// PFAccountManagementLinkAppleRequest data model.
/// </summary>
typedef struct PFAccountManagementLinkAppleRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to a specific Apple account, unlink the other user
    /// and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// The JSON Web token (JWT) returned by Apple after login. Represented as the identityToken field
    /// in the authorization credential payload. Used to validate the request and find the user ID (Apple
    /// subject) to link with.
    /// </summary>
    _Null_terminated_ const char* identityToken;

} PFAccountManagementLinkAppleRequest;

/// <summary>
/// PFAccountManagementLinkCustomIDRequest data model.
/// </summary>
typedef struct PFAccountManagementLinkCustomIDRequest
{
    /// <summary>
    /// Custom unique identifier for the user, generated by the title.
    /// </summary>
    _Null_terminated_ const char* customId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to the custom ID, unlink the other user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

} PFAccountManagementLinkCustomIDRequest;

/// <summary>
/// PFAccountManagementLinkFacebookAccountRequest data model. Facebook sign-in is accomplished using
/// the Facebook User Access Token. More information on the Token can be found in the Facebook developer
/// documentation (https://developers.facebook.com/docs/facebook-login/access-tokens/). In Unity, for
/// example, the Token is available as AccessToken in the Facebook SDK ScriptableObject FB. Note that
/// titles should never re-use the same Facebook applications between PlayFab Title IDs, as Facebook provides
/// unique user IDs per application and doing so can result in issues with the Facebook ID for the user
/// in their PlayFab account information. If you must re-use an application in a new PlayFab Title ID,
/// please be sure to first unlink all accounts from Facebook, or delete all users in the first Title
/// ID.
/// </summary>
typedef struct PFAccountManagementLinkFacebookAccountRequest
{
    /// <summary>
    /// Unique identifier from Facebook for the user.
    /// </summary>
    _Null_terminated_ const char* accessToken;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to the account, unlink the other user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

} PFAccountManagementLinkFacebookAccountRequest;

/// <summary>
/// PFAccountManagementLinkFacebookInstantGamesIdRequest data model.
/// </summary>
typedef struct PFAccountManagementLinkFacebookInstantGamesIdRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// Facebook Instant Games signature for the user.
    /// </summary>
    _Null_terminated_ const char* facebookInstantGamesSignature;

    /// <summary>
    /// (Optional) If another user is already linked to the Facebook Instant Games ID, unlink the other
    /// user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

} PFAccountManagementLinkFacebookInstantGamesIdRequest;

/// <summary>
/// PFAccountManagementLinkGameCenterAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementLinkGameCenterAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to the account, unlink the other user and re-link.
    /// If the current user is already linked, link both accounts.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// Game Center identifier for the player account to be linked.
    /// </summary>
    _Null_terminated_ const char* gameCenterId;

    /// <summary>
    /// (Optional) The URL for the public encryption key that will be used to verify the signature.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* publicKeyUrl;

    /// <summary>
    /// (Optional) A random value used to compute the hash and keep it randomized.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* salt;

    /// <summary>
    /// (Optional) The verification signature of the authentication payload.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* signature;

    /// <summary>
    /// (Optional) The integer representation of date and time that the signature was created on. PlayFab
    /// will reject authentication signatures not within 10 minutes of the server's current time.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* timestamp;

} PFAccountManagementLinkGameCenterAccountRequest;

/// <summary>
/// PFAccountManagementLinkGoogleAccountRequest data model. Google sign-in is accomplished by obtaining
/// a Google OAuth 2.0 credential using the Google sign-in for Android APIs on the device and passing
/// it to this API.
/// </summary>
typedef struct PFAccountManagementLinkGoogleAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to the account, unlink the other user and re-link.
    /// If the current user is already linked, link both accounts.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// (Optional) Server authentication code obtained on the client by calling getServerAuthCode() (https://developers.google.com/identity/sign-in/android/offline-access)
    /// from Google Play for the user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverAuthCode;

} PFAccountManagementLinkGoogleAccountRequest;

/// <summary>
/// PFAccountManagementLinkGooglePlayGamesServicesAccountRequest data model. Google Play Games sign-in
/// is accomplished by obtaining a Google OAuth 2.0 credential using the Google Play Games sign-in for
/// Android APIs on the device and passing it to this API.
/// </summary>
typedef struct PFAccountManagementLinkGooglePlayGamesServicesAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to the account, unlink the other user and re-link.
    /// If the current user is already linked, link both accounts.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// OAuth 2.0 server authentication code obtained on the client by calling the requestServerSideAccess()
    /// (https://developers.google.com/games/services/android/signin) Google Play Games client API.
    /// </summary>
    _Null_terminated_ const char* serverAuthCode;

} PFAccountManagementLinkGooglePlayGamesServicesAccountRequest;

/// <summary>
/// PFAccountManagementLinkIOSDeviceIDRequest data model.
/// </summary>
typedef struct PFAccountManagementLinkIOSDeviceIDRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// Vendor-specific iOS identifier for the user's device.
    /// </summary>
    _Null_terminated_ const char* deviceId;

    /// <summary>
    /// (Optional) Specific model of the user's device.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* deviceModel;

    /// <summary>
    /// (Optional) If another user is already linked to the device, unlink the other user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// (Optional) Specific Operating System version for the user's device.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* OS;

} PFAccountManagementLinkIOSDeviceIDRequest;

/// <summary>
/// PFAccountManagementLinkKongregateAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementLinkKongregateAccountRequest
{
    /// <summary>
    /// Valid session auth ticket issued by Kongregate.
    /// </summary>
    _Null_terminated_ const char* authTicket;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to the account, unlink the other user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// Numeric user ID assigned by Kongregate.
    /// </summary>
    _Null_terminated_ const char* kongregateId;

} PFAccountManagementLinkKongregateAccountRequest;

/// <summary>
/// PFAccountManagementClientLinkNintendoServiceAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementClientLinkNintendoServiceAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to a specific Nintendo Switch account, unlink the
    /// other user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// The JSON Web token (JWT) returned by Nintendo after login. Used to validate the request and find
    /// the user ID (Nintendo Switch subject) to link with.
    /// </summary>
    _Null_terminated_ const char* identityToken;

} PFAccountManagementClientLinkNintendoServiceAccountRequest;

/// <summary>
/// PFAccountManagementClientLinkNintendoSwitchDeviceIdRequest data model.
/// </summary>
typedef struct PFAccountManagementClientLinkNintendoSwitchDeviceIdRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to the Nintendo Switch Device ID, unlink the other
    /// user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// Nintendo Switch unique identifier for the user's device.
    /// </summary>
    _Null_terminated_ const char* nintendoSwitchDeviceId;

} PFAccountManagementClientLinkNintendoSwitchDeviceIdRequest;

/// <summary>
/// PFAccountManagementLinkOpenIdConnectRequest data model.
/// </summary>
typedef struct PFAccountManagementLinkOpenIdConnectRequest
{
    /// <summary>
    /// A name that identifies which configured OpenID Connect provider relationship to use. Maximum
    /// 100 characters.
    /// </summary>
    _Null_terminated_ const char* connectionId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to a specific OpenId Connect user, unlink the other
    /// user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// The JSON Web token (JWT) returned by the identity provider after login. Represented as the id_token
    /// field in the identity provider's response. Used to validate the request and find the user ID (OpenID
    /// Connect subject) to link with.
    /// </summary>
    _Null_terminated_ const char* idToken;

} PFAccountManagementLinkOpenIdConnectRequest;

/// <summary>
/// PFAccountManagementClientLinkPSNAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementClientLinkPSNAccountRequest
{
    /// <summary>
    /// Authentication code provided by the PlayStation :tm: Network.
    /// </summary>
    _Null_terminated_ const char* authCode;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to the account, unlink the other user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// (Optional) Id of the PlayStation :tm: Network issuer environment. If null, defaults to production
    /// environment.
    /// </summary>
    _Maybenull_ int32_t const* issuerId;

    /// <summary>
    /// Redirect URI supplied to PlayStation :tm: Network when requesting an auth code.
    /// </summary>
    _Null_terminated_ const char* redirectUri;

} PFAccountManagementClientLinkPSNAccountRequest;

/// <summary>
/// PFAccountManagementLinkSteamAccountRequest data model. Steam authentication is accomplished with
/// the Steam Session Ticket. More information on the Ticket can be found in the Steamworks SDK, here:
/// https://partner.steamgames.com/documentation/auth (requires sign-in). NOTE: For Steam authentication
/// to work, the title must be configured with the Steam Application ID and Publisher Key in the PlayFab
/// Game Manager (under Properties). Information on creating a Publisher Key (referred to as the Secret
/// Key in PlayFab) for your title can be found here: https://partner.steamgames.com/documentation/webapi#publisherkey.
/// </summary>
typedef struct PFAccountManagementLinkSteamAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to the account, unlink the other user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// Authentication token for the user, returned as a byte array from Steam, and converted to a string
    /// (for example, the byte 0x08 should become "08").
    /// </summary>
    _Null_terminated_ const char* steamTicket;

} PFAccountManagementLinkSteamAccountRequest;

/// <summary>
/// PFAccountManagementLinkTwitchAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementLinkTwitchAccountRequest
{
    /// <summary>
    /// Valid token issued by Twitch.
    /// </summary>
    _Null_terminated_ const char* accessToken;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to the account, unlink the other user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

} PFAccountManagementLinkTwitchAccountRequest;

/// <summary>
/// PFAccountManagementClientLinkXboxAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementClientLinkXboxAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to the account, unlink the other user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// Token provided by the Xbox Live SDK/XDK method GetTokenAndSignatureAsync("POST", "https://playfabapi.com/",
    /// "").
    /// </summary>
    _Null_terminated_ const char* xboxToken;

} PFAccountManagementClientLinkXboxAccountRequest;

/// <summary>
/// PFAccountManagementRemoveContactEmailRequest data model. This API removes an existing contact email
/// from the player's profile.
/// </summary>
typedef struct PFAccountManagementRemoveContactEmailRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFAccountManagementRemoveContactEmailRequest;

/// <summary>
/// PFAccountManagementClientRemoveGenericIDRequest data model.
/// </summary>
typedef struct PFAccountManagementClientRemoveGenericIDRequest
{
    /// <summary>
    /// Generic service identifier to be removed from the player.
    /// </summary>
    PFAccountManagementGenericServiceId const* genericId;

} PFAccountManagementClientRemoveGenericIDRequest;

/// <summary>
/// PFAccountManagementReportPlayerClientRequest data model.
/// </summary>
typedef struct PFAccountManagementReportPlayerClientRequest
{
    /// <summary>
    /// (Optional) Optional additional comment by reporting player.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* comment;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// Unique PlayFab identifier of the reported player.
    /// </summary>
    _Null_terminated_ const char* reporteeId;

} PFAccountManagementReportPlayerClientRequest;

/// <summary>
/// PFAccountManagementReportPlayerClientResult data model. Players are currently limited to five reports
/// per day. Attempts by a single user account to submit reports beyond five will result in Updated being
/// returned as false.
/// </summary>
typedef struct PFAccountManagementReportPlayerClientResult
{
    /// <summary>
    /// The number of remaining reports which may be filed today.
    /// </summary>
    int32_t submissionsRemaining;

} PFAccountManagementReportPlayerClientResult;

/// <summary>
/// PFAccountManagementClientSendAccountRecoveryEmailRequest data model. If the account in question is
/// a "temporary" account (for example, one that was created via a call to LoginFromIOSDeviceID), thisfunction
/// will have no effect. Only PlayFab accounts which have valid email addresses will be able to receive
/// a password reset email using this API.
/// </summary>
typedef struct PFAccountManagementClientSendAccountRecoveryEmailRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// User email address attached to their account.
    /// </summary>
    _Null_terminated_ const char* email;

    /// <summary>
    /// (Optional) The email template id of the account recovery email template to send.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* emailTemplateId;

    /// <summary>
    /// Unique identifier for the title, found in the Settings > Game Properties section of the PlayFab
    /// developer site when a title has been selected.
    /// </summary>
    _Null_terminated_ const char* titleId;

} PFAccountManagementClientSendAccountRecoveryEmailRequest;

/// <summary>
/// PFAccountManagementUnlinkAndroidDeviceIDRequest data model.
/// </summary>
typedef struct PFAccountManagementUnlinkAndroidDeviceIDRequest
{
    /// <summary>
    /// (Optional) Android device identifier for the user's device. If not specified, the most recently
    /// signed in Android Device ID will be used.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* androidDeviceId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFAccountManagementUnlinkAndroidDeviceIDRequest;

/// <summary>
/// PFAccountManagementUnlinkAppleRequest data model.
/// </summary>
typedef struct PFAccountManagementUnlinkAppleRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFAccountManagementUnlinkAppleRequest;

/// <summary>
/// PFAccountManagementUnlinkCustomIDRequest data model.
/// </summary>
typedef struct PFAccountManagementUnlinkCustomIDRequest
{
    /// <summary>
    /// (Optional) Custom unique identifier for the user, generated by the title. If not specified, the
    /// most recently signed in Custom ID will be used.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* customId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFAccountManagementUnlinkCustomIDRequest;

/// <summary>
/// PFAccountManagementUnlinkFacebookAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementUnlinkFacebookAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFAccountManagementUnlinkFacebookAccountRequest;

/// <summary>
/// PFAccountManagementUnlinkFacebookInstantGamesIdRequest data model.
/// </summary>
typedef struct PFAccountManagementUnlinkFacebookInstantGamesIdRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) Facebook Instant Games identifier for the user. If not specified, the most recently
    /// signed in ID will be used.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* facebookInstantGamesId;

} PFAccountManagementUnlinkFacebookInstantGamesIdRequest;

/// <summary>
/// PFAccountManagementUnlinkGameCenterAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementUnlinkGameCenterAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFAccountManagementUnlinkGameCenterAccountRequest;

/// <summary>
/// PFAccountManagementUnlinkGoogleAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementUnlinkGoogleAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFAccountManagementUnlinkGoogleAccountRequest;

/// <summary>
/// PFAccountManagementUnlinkGooglePlayGamesServicesAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementUnlinkGooglePlayGamesServicesAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFAccountManagementUnlinkGooglePlayGamesServicesAccountRequest;

/// <summary>
/// PFAccountManagementUnlinkIOSDeviceIDRequest data model.
/// </summary>
typedef struct PFAccountManagementUnlinkIOSDeviceIDRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) Vendor-specific iOS identifier for the user's device. If not specified, the most recently
    /// signed in iOS Device ID will be used.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* deviceId;

} PFAccountManagementUnlinkIOSDeviceIDRequest;

/// <summary>
/// PFAccountManagementUnlinkKongregateAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementUnlinkKongregateAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFAccountManagementUnlinkKongregateAccountRequest;

/// <summary>
/// PFAccountManagementClientUnlinkNintendoServiceAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementClientUnlinkNintendoServiceAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFAccountManagementClientUnlinkNintendoServiceAccountRequest;

/// <summary>
/// PFAccountManagementClientUnlinkNintendoSwitchDeviceIdRequest data model.
/// </summary>
typedef struct PFAccountManagementClientUnlinkNintendoSwitchDeviceIdRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) Nintendo Switch Device identifier for the user. If not specified, the most recently
    /// signed in device ID will be used.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* nintendoSwitchDeviceId;

} PFAccountManagementClientUnlinkNintendoSwitchDeviceIdRequest;

/// <summary>
/// PFAccountManagementUnlinkOpenIdConnectRequest data model.
/// </summary>
typedef struct PFAccountManagementUnlinkOpenIdConnectRequest
{
    /// <summary>
    /// A name that identifies which configured OpenID Connect provider relationship to use. Maximum
    /// 100 characters.
    /// </summary>
    _Null_terminated_ const char* connectionId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFAccountManagementUnlinkOpenIdConnectRequest;

/// <summary>
/// PFAccountManagementClientUnlinkPSNAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementClientUnlinkPSNAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFAccountManagementClientUnlinkPSNAccountRequest;

/// <summary>
/// PFAccountManagementUnlinkSteamAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementUnlinkSteamAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFAccountManagementUnlinkSteamAccountRequest;

/// <summary>
/// PFAccountManagementUnlinkTwitchAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementUnlinkTwitchAccountRequest
{
    /// <summary>
    /// (Optional) Valid token issued by Twitch. Used to specify which twitch account to unlink from
    /// the profile. By default it uses the one that is present on the profile.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* accessToken;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFAccountManagementUnlinkTwitchAccountRequest;

/// <summary>
/// PFAccountManagementClientUnlinkXboxAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementClientUnlinkXboxAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFAccountManagementClientUnlinkXboxAccountRequest;

/// <summary>
/// PFAccountManagementClientUpdateAvatarUrlRequest data model.
/// </summary>
typedef struct PFAccountManagementClientUpdateAvatarUrlRequest
{
    /// <summary>
    /// URL of the avatar image. If empty, it removes the existing avatar URL.
    /// </summary>
    _Null_terminated_ const char* imageUrl;

} PFAccountManagementClientUpdateAvatarUrlRequest;

/// <summary>
/// PFAccountManagementClientUpdateUserTitleDisplayNameRequest data model. In addition to the PlayFab
/// username, titles can make use of a DisplayName which is also a unique identifier, but specific to
/// the title. This allows for unique names which more closely match the theme or genre of a title, for
/// example.
/// </summary>
typedef struct PFAccountManagementClientUpdateUserTitleDisplayNameRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// New title display name for the user - must be between 3 and 25 characters.
    /// </summary>
    _Null_terminated_ const char* displayName;

} PFAccountManagementClientUpdateUserTitleDisplayNameRequest;

/// <summary>
/// PFAccountManagementServerAddGenericIDRequest data model.
/// </summary>
typedef struct PFAccountManagementServerAddGenericIDRequest
{
    /// <summary>
    /// Generic service identifier to add to the player account.
    /// </summary>
    PFAccountManagementGenericServiceId const* genericId;

    /// <summary>
    /// PlayFabId of the user to link.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementServerAddGenericIDRequest;

/// <summary>
/// PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequest data model.
/// </summary>
typedef struct PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequest
{
    /// <summary>
    /// Array of unique PlayFab player identifiers for which the title needs to get server custom identifiers.
    /// Cannot contain more than 25 identifiers.
    /// </summary>
    _Field_size_(playFabIDsCount) const char* const* playFabIDs;

    /// <summary>
    /// Count of playFabIDs
    /// </summary>
    uint32_t playFabIDsCount;

} PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequest;

/// <summary>
/// PFAccountManagementServerCustomIDPlayFabIDPair data model.
/// </summary>
typedef struct PFAccountManagementServerCustomIDPlayFabIDPair
{
    /// <summary>
    /// (Optional) Unique PlayFab identifier.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) Unique server custom identifier for this player.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverCustomId;

} PFAccountManagementServerCustomIDPlayFabIDPair;

/// <summary>
/// PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult data model. For a PlayFab account that
/// isn't associated with a server custom identity, ServerCustomId will be null.
/// </summary>
typedef struct PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult
{
    /// <summary>
    /// (Optional) Mapping of server custom player identifiers to PlayFab identifiers.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) PFAccountManagementServerCustomIDPlayFabIDPair const* const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

} PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult;

/// <summary>
/// PFAccountManagementGetUserAccountInfoRequest data model. This API allows for access to details regarding
/// a user in the PlayFab service, usually for purposes of customer support. Note that data returned may
/// be Personally Identifying Information (PII), such as email address, and so care should be taken in
/// how this data is stored and managed. Since this call will always return the relevant information for
/// users who have accessed the title, the recommendation is to not store this data locally.
/// </summary>
typedef struct PFAccountManagementGetUserAccountInfoRequest
{
    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementGetUserAccountInfoRequest;

/// <summary>
/// PFAccountManagementGetUserAccountInfoResult data model.
/// </summary>
typedef struct PFAccountManagementGetUserAccountInfoResult
{
    /// <summary>
    /// (Optional) Account details for the user whose information was requested.
    /// </summary>
    _Maybenull_ PFUserAccountInfo const* userInfo;

} PFAccountManagementGetUserAccountInfoResult;

/// <summary>
/// PFAccountManagementServerLinkNintendoServiceAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementServerLinkNintendoServiceAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to a specific Nintendo Switch account, unlink the
    /// other user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// The JSON Web token (JWT) returned by Nintendo after login. Used to validate the request and find
    /// the user ID (Nintendo Switch subject) to link with.
    /// </summary>
    _Null_terminated_ const char* identityToken;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementServerLinkNintendoServiceAccountRequest;

/// <summary>
/// PFAccountManagementServerLinkNintendoSwitchDeviceIdRequest data model.
/// </summary>
typedef struct PFAccountManagementServerLinkNintendoSwitchDeviceIdRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to the Nintendo Switch Device ID, unlink the other
    /// user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// Nintendo Switch unique identifier for the user's device.
    /// </summary>
    _Null_terminated_ const char* nintendoSwitchDeviceId;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementServerLinkNintendoSwitchDeviceIdRequest;

/// <summary>
/// PFAccountManagementServerLinkPSNAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementServerLinkPSNAccountRequest
{
    /// <summary>
    /// Authentication code provided by the PlayStation :tm: Network.
    /// </summary>
    _Null_terminated_ const char* authCode;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to the account, unlink the other user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// (Optional) Id of the PlayStation :tm: Network issuer environment. If null, defaults to production
    /// environment.
    /// </summary>
    _Maybenull_ int32_t const* issuerId;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// Redirect URI supplied to PlayStation :tm: Network when requesting an auth code.
    /// </summary>
    _Null_terminated_ const char* redirectUri;

} PFAccountManagementServerLinkPSNAccountRequest;

/// <summary>
/// PFAccountManagementLinkServerCustomIdRequest data model.
/// </summary>
typedef struct PFAccountManagementLinkServerCustomIdRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to the custom ID, unlink the other user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// Unique PlayFab identifier.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// Unique server custom identifier for this player.
    /// </summary>
    _Null_terminated_ const char* serverCustomId;

} PFAccountManagementLinkServerCustomIdRequest;

/// <summary>
/// PFAccountManagementServerLinkXboxAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementServerLinkXboxAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) If another user is already linked to the account, unlink the other user and re-link.
    /// </summary>
    _Maybenull_ bool const* forceLink;

    /// <summary>
    /// Unique PlayFab identifier for a user, or null if no PlayFab account is linked to the Xbox Live
    /// identifier.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// Token provided by the Xbox Live SDK/XDK method GetTokenAndSignatureAsync("POST", "https://playfabapi.com/",
    /// "").
    /// </summary>
    _Null_terminated_ const char* xboxToken;

} PFAccountManagementServerLinkXboxAccountRequest;

/// <summary>
/// PFAccountManagementServerRemoveGenericIDRequest data model.
/// </summary>
typedef struct PFAccountManagementServerRemoveGenericIDRequest
{
    /// <summary>
    /// Generic service identifier to be removed from the player.
    /// </summary>
    PFAccountManagementGenericServiceId const* genericId;

    /// <summary>
    /// PlayFabId of the user to remove.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementServerRemoveGenericIDRequest;

/// <summary>
/// PFAccountManagementSendCustomAccountRecoveryEmailRequest data model. PlayFab accounts which have
/// valid email address or username will be able to receive a password reset email using this API.The
/// email sent must be an account recovery email template. The username or email can be passed in to send
/// the email.
/// </summary>
typedef struct PFAccountManagementSendCustomAccountRecoveryEmailRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) User email address attached to their account.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* email;

    /// <summary>
    /// The email template id of the account recovery email template to send.
    /// </summary>
    _Null_terminated_ const char* emailTemplateId;

    /// <summary>
    /// (Optional) The user's username requesting an account recovery.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* username;

} PFAccountManagementSendCustomAccountRecoveryEmailRequest;

/// <summary>
/// PFAccountManagementSendEmailFromTemplateRequest data model. Sends an email for only players that
/// have contact emails associated with them. Takes in an email template ID specifyingthe email template
/// to send.
/// </summary>
typedef struct PFAccountManagementSendEmailFromTemplateRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// The email template id of the email template to send.
    /// </summary>
    _Null_terminated_ const char* emailTemplateId;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementSendEmailFromTemplateRequest;

/// <summary>
/// PFAccountManagementServerUnlinkNintendoServiceAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementServerUnlinkNintendoServiceAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementServerUnlinkNintendoServiceAccountRequest;

/// <summary>
/// PFAccountManagementServerUnlinkNintendoSwitchDeviceIdRequest data model.
/// </summary>
typedef struct PFAccountManagementServerUnlinkNintendoSwitchDeviceIdRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) Nintendo Switch Device identifier for the user. If not specified, the most recently
    /// signed in device ID will be used.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* nintendoSwitchDeviceId;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementServerUnlinkNintendoSwitchDeviceIdRequest;

/// <summary>
/// PFAccountManagementServerUnlinkPSNAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementServerUnlinkPSNAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementServerUnlinkPSNAccountRequest;

/// <summary>
/// PFAccountManagementUnlinkServerCustomIdRequest data model.
/// </summary>
typedef struct PFAccountManagementUnlinkServerCustomIdRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// Unique PlayFab identifier.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// Unique server custom identifier for this player.
    /// </summary>
    _Null_terminated_ const char* serverCustomId;

} PFAccountManagementUnlinkServerCustomIdRequest;

/// <summary>
/// PFAccountManagementServerUnlinkXboxAccountRequest data model.
/// </summary>
typedef struct PFAccountManagementServerUnlinkXboxAccountRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// Unique PlayFab identifier for a user, or null if no PlayFab account is linked to the Xbox Live
    /// identifier.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementServerUnlinkXboxAccountRequest;

/// <summary>
/// PFAccountManagementServerUpdateAvatarUrlRequest data model.
/// </summary>
typedef struct PFAccountManagementServerUpdateAvatarUrlRequest
{
    /// <summary>
    /// URL of the avatar image. If empty, it removes the existing avatar URL.
    /// </summary>
    _Null_terminated_ const char* imageUrl;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFAccountManagementServerUpdateAvatarUrlRequest;

#pragma pop_macro("IN")

}
