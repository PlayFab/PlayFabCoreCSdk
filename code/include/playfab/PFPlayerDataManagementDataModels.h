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
/// StatisticAggregationMethod enum.
/// </summary>
enum class PFPlayerDataManagementStatisticAggregationMethod : uint32_t
{
    Last,
    Min,
    Max,
    Sum
};

/// <summary>
/// StatisticResetIntervalOption enum.
/// </summary>
enum class PFPlayerDataManagementStatisticResetIntervalOption : uint32_t
{
    Never,
    Hour,
    Day,
    Week,
    Month
};

/// <summary>
/// StatisticVersionStatus enum.
/// </summary>
enum class PFPlayerDataManagementStatisticVersionStatus : uint32_t
{
    Active,
    SnapshotPending,
    Snapshot,
    ArchivalPending,
    Archived
};

/// <summary>
/// ResolutionOutcome enum.
/// </summary>
enum class PFPlayerDataManagementResolutionOutcome : uint32_t
{
    Revoke,
    Reinstate,
    Manual
};

/// <summary>
/// PFPlayerDataManagementCreatePlayerStatisticDefinitionRequest data model. Statistics are numeric values,
/// with each statistic in the title also generating a leaderboard. The ResetInterval enables automatically
/// resetting leaderboards on a specified interval. Upon reset, the statistic updates to a new version
/// with no values (effectively removing all players from the leaderboard). The previous version's statistic
/// values are also archived for retrieval, if needed (see GetPlayerStatisticVersions). Statistics not
/// created via a call to CreatePlayerStatisticDefinition by default have a VersionChangeInterval of Never,
/// meaning they do not reset on a schedule, but they can be set to do so via a call to UpdatePlayerStatisticDefinition.
/// Once a statistic has been reset (sometimes referred to as versioned or incremented), the now-previous
/// version can still be written to for up a short, pre-defined period (currently 10 seconds), to prevent
/// issues with levels completing around the time of the reset. Also, once reset, the historical statistics
/// for players in the title may be retrieved using the URL specified in the version information (GetPlayerStatisticVersions).
/// The AggregationMethod determines what action is taken when a new statistic value is submitted - always
/// update with the new value (Last), use the highest of the old and new values (Max), use the smallest
/// (Min), or add them together (Sum).
/// </summary>
typedef struct PFPlayerDataManagementCreatePlayerStatisticDefinitionRequest
{
    /// <summary>
    /// (Optional) The aggregation method to use in updating the statistic (defaults to last).
    /// </summary>
    _Maybenull_ PFPlayerDataManagementStatisticAggregationMethod const* aggregationMethod;

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
    /// Unique name of the statistic.
    /// </summary>
    _Null_terminated_ const char* statisticName;

    /// <summary>
    /// (Optional) Interval at which the values of the statistic for all players are reset (resets begin
    /// at the next interval boundary).
    /// </summary>
    _Maybenull_ PFPlayerDataManagementStatisticResetIntervalOption const* versionChangeInterval;

} PFPlayerDataManagementCreatePlayerStatisticDefinitionRequest;

/// <summary>
/// PFPlayerDataManagementPlayerStatisticDefinition data model.
/// </summary>
typedef struct PFPlayerDataManagementPlayerStatisticDefinition
{
    /// <summary>
    /// (Optional) The aggregation method to use in updating the statistic (defaults to last).
    /// </summary>
    _Maybenull_ PFPlayerDataManagementStatisticAggregationMethod const* aggregationMethod;

    /// <summary>
    /// Current active version of the statistic, incremented each time the statistic resets.
    /// </summary>
    uint32_t currentVersion;

    /// <summary>
    /// (Optional) Unique name of the statistic.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* statisticName;

    /// <summary>
    /// (Optional) Interval at which the values of the statistic for all players are reset automatically.
    /// </summary>
    _Maybenull_ PFPlayerDataManagementStatisticResetIntervalOption const* versionChangeInterval;

} PFPlayerDataManagementPlayerStatisticDefinition;

/// <summary>
/// PFPlayerDataManagementCreatePlayerStatisticDefinitionResult data model.
/// </summary>
typedef struct PFPlayerDataManagementCreatePlayerStatisticDefinitionResult
{
    /// <summary>
    /// (Optional) Created statistic definition.
    /// </summary>
    _Maybenull_ PFPlayerDataManagementPlayerStatisticDefinition const* statistic;

} PFPlayerDataManagementCreatePlayerStatisticDefinitionResult;

/// <summary>
/// PFPlayerDataManagementGetDataReportRequest data model. Gets the download URL for the requested report
/// data (in CSV form). The reports available through this API call are those available in the Game Manager,
/// in the Analytics->Reports tab.
/// </summary>
typedef struct PFPlayerDataManagementGetDataReportRequest
{
    /// <summary>
    /// Reporting year (UTC).
    /// </summary>
    int32_t day;

    /// <summary>
    /// Reporting month (UTC).
    /// </summary>
    int32_t month;

    /// <summary>
    /// Report name.
    /// </summary>
    _Null_terminated_ const char* reportName;

    /// <summary>
    /// Reporting year (UTC).
    /// </summary>
    int32_t year;

} PFPlayerDataManagementGetDataReportRequest;

/// <summary>
/// PFPlayerDataManagementGetDataReportResult data model.
/// </summary>
typedef struct PFPlayerDataManagementGetDataReportResult
{
    /// <summary>
    /// (Optional) The URL where the requested report can be downloaded. This can be any PlayFab generated
    /// reports. The full list of reports can be found at: https://docs.microsoft.com/en-us/gaming/playfab/features/analytics/reports/quickstart.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* downloadUrl;

} PFPlayerDataManagementGetDataReportResult;

/// <summary>
/// PFPlayerDataManagementGetPlayerStatisticDefinitionsResult data model. Statistics are numeric values,
/// with each statistic in the title also generating a leaderboard. The ResetInterval defines the period
/// of time at which the leaderboard for the statistic will automatically reset. Upon reset, the statistic
/// updates to a new version with no values (effectively removing all players from the leaderboard). The
/// previous version's statistic values are also archived for retrieval, if needed (see GetPlayerStatisticVersions).
/// Statistics not created via a call to CreatePlayerStatisticDefinition by default have a VersionChangeInterval
/// of Never, meaning they do not reset on a schedule, but they can be set to do so via a call to UpdatePlayerStatisticDefinition.
/// Once a statistic has been reset (sometimes referred to as versioned or incremented), the previous
/// version can still be written to for up a short, pre-defined period (currently 10 seconds), to prevent
/// issues with levels completing around the time of the reset. Also, once reset, the historical statistics
/// for players in the title may be retrieved using the URL specified in the version information (GetPlayerStatisticVersions).
/// The AggregationMethod defines what action is taken when a new statistic value is submitted - always
/// update with the new value (Last), use the highest of the old and new values (Max), use the smallest
/// (Min), or add them together (Sum).
/// </summary>
typedef struct PFPlayerDataManagementGetPlayerStatisticDefinitionsResult
{
    /// <summary>
    /// (Optional) The player statistic definitions for the title.
    /// </summary>
    _Maybenull_ _Field_size_(statisticsCount) PFPlayerDataManagementPlayerStatisticDefinition const* const* statistics;

    /// <summary>
    /// Count of statistics
    /// </summary>
    uint32_t statisticsCount;

} PFPlayerDataManagementGetPlayerStatisticDefinitionsResult;

/// <summary>
/// PFPlayerDataManagementGetPlayerStatisticVersionsRequest data model.
/// </summary>
typedef struct PFPlayerDataManagementGetPlayerStatisticVersionsRequest
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
    /// (Optional) Unique name of the statistic.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* statisticName;

} PFPlayerDataManagementGetPlayerStatisticVersionsRequest;

/// <summary>
/// PFPlayerDataManagementPlayerStatisticVersion data model.
/// </summary>
typedef struct PFPlayerDataManagementPlayerStatisticVersion
{
    /// <summary>
    /// Time when the statistic version became active.
    /// </summary>
    time_t activationTime;

    /// <summary>
    /// (Optional) URL for the downloadable archive of player statistic values, if available.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* archiveDownloadUrl;

    /// <summary>
    /// (Optional) Time when the statistic version became inactive due to statistic version incrementing.
    /// </summary>
    _Maybenull_ time_t const* deactivationTime;

    /// <summary>
    /// (Optional) Time at which the statistic version was scheduled to become active, based on the configured
    /// ResetInterval.
    /// </summary>
    _Maybenull_ time_t const* scheduledActivationTime;

    /// <summary>
    /// (Optional) Time at which the statistic version was scheduled to become inactive, based on the
    /// configured ResetInterval.
    /// </summary>
    _Maybenull_ time_t const* scheduledDeactivationTime;

    /// <summary>
    /// (Optional) Name of the statistic when the version became active.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* statisticName;

    /// <summary>
    /// (Optional) Status of the statistic version.
    /// </summary>
    _Maybenull_ PFPlayerDataManagementStatisticVersionStatus const* status;

    /// <summary>
    /// Version of the statistic.
    /// </summary>
    uint32_t version;

} PFPlayerDataManagementPlayerStatisticVersion;

/// <summary>
/// PFPlayerDataManagementGetPlayerStatisticVersionsResult data model. Statistics are numeric values,
/// with each statistic in the title also generating a leaderboard. The information returned in the results
/// defines the state of a specific version of a statistic, including when it was or will become the currently
/// active version, when it will (or did) become a previous version, and its archival state if it is no
/// longer the active version. For a statistic which has been reset, once the archival status is Complete,
/// the full set of statistics for all players in the leaderboard for that version may be retrieved via
/// the ArchiveDownloadUrl. Statistics which have not been reset (incremented/versioned) will only have
/// a single version which is not scheduled to reset.
/// </summary>
typedef struct PFPlayerDataManagementGetPlayerStatisticVersionsResult
{
    /// <summary>
    /// (Optional) Version change history of the statistic.
    /// </summary>
    _Maybenull_ _Field_size_(statisticVersionsCount) PFPlayerDataManagementPlayerStatisticVersion const* const* statisticVersions;

    /// <summary>
    /// Count of statisticVersions
    /// </summary>
    uint32_t statisticVersionsCount;

} PFPlayerDataManagementGetPlayerStatisticVersionsResult;

/// <summary>
/// PFPlayerDataManagementGetUserDataRequest data model. Data is stored as JSON key-value pairs. If the
/// Keys parameter is provided, the data object returned will only contain the data specific to the indicated
/// Keys. Otherwise, the full set of custom user data will be returned.
/// </summary>
typedef struct PFPlayerDataManagementGetUserDataRequest
{
    /// <summary>
    /// (Optional) The version that currently exists according to the caller. The call will return the
    /// data for all of the keys if the version in the system is greater than this.
    /// </summary>
    _Maybenull_ uint32_t const* ifChangedFromDataVersion;

    /// <summary>
    /// (Optional) Specific keys to search for in the custom user data.
    /// </summary>
    _Maybenull_ _Field_size_(keysCount) const char* const* keys;

    /// <summary>
    /// Count of keys
    /// </summary>
    uint32_t keysCount;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerDataManagementGetUserDataRequest;

/// <summary>
/// PFPlayerDataManagementAdminGetUserDataResult data model.
/// </summary>
typedef struct PFPlayerDataManagementAdminGetUserDataResult
{
    /// <summary>
    /// (Optional) User specific data for this title.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) struct PFUserDataRecordDictionaryEntry const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

    /// <summary>
    /// Indicates the current version of the data that has been set. This is incremented with every set
    /// call for that type of data (read-only, internal, etc). This version can be provided in Get calls
    /// to find updated data.
    /// </summary>
    uint32_t dataVersion;

    /// <summary>
    /// (Optional) PlayFab unique identifier of the user whose custom data is being returned.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

} PFPlayerDataManagementAdminGetUserDataResult;

/// <summary>
/// PFPlayerDataManagementIncrementPlayerStatisticVersionRequest data model. Statistics are numeric values,
/// with each statistic in the title also generating a leaderboard. When this call is made on a given
/// statistic, this forces a reset of that statistic. Upon reset, the statistic updates to a new version
/// with no values (effectively removing all players from the leaderboard). The previous version's statistic
/// values are also archived for retrieval, if needed (see GetPlayerStatisticVersions). Statistics not
/// created via a call to CreatePlayerStatisticDefinition by default have a VersionChangeInterval of Never,
/// meaning they do not reset on a schedule, but they can be set to do so via a call to UpdatePlayerStatisticDefinition.
/// Once a statistic has been reset (sometimes referred to as versioned or incremented), the now-previous
/// version can still be written to for up a short, pre-defined period (currently 10 seconds), to prevent
/// issues with levels completing around the time of the reset. Also, once reset, the historical statistics
/// for players in the title may be retrieved using the URL specified in the version information (GetPlayerStatisticVersions).
/// </summary>
typedef struct PFPlayerDataManagementIncrementPlayerStatisticVersionRequest
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
    /// (Optional) Unique name of the statistic.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* statisticName;

} PFPlayerDataManagementIncrementPlayerStatisticVersionRequest;

/// <summary>
/// PFPlayerDataManagementIncrementPlayerStatisticVersionResult data model.
/// </summary>
typedef struct PFPlayerDataManagementIncrementPlayerStatisticVersionResult
{
    /// <summary>
    /// (Optional) Version change history of the statistic.
    /// </summary>
    _Maybenull_ PFPlayerDataManagementPlayerStatisticVersion const* statisticVersion;

} PFPlayerDataManagementIncrementPlayerStatisticVersionResult;

/// <summary>
/// PFPlayerDataManagementRefundPurchaseRequest data model.
/// </summary>
typedef struct PFPlayerDataManagementRefundPurchaseRequest
{
    /// <summary>
    /// Unique order ID for the purchase in question.
    /// </summary>
    _Null_terminated_ const char* orderId;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) The Reason parameter should correspond with the payment providers reason field, if
    /// they require one such as Facebook. In the case of Facebook this must match one of their refund
    /// or dispute resolution enums (See: https://developers.facebook.com/docs/payments/implementation-guide/handling-disputes-refunds).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reason;

} PFPlayerDataManagementRefundPurchaseRequest;

/// <summary>
/// PFPlayerDataManagementRefundPurchaseResponse data model.
/// </summary>
typedef struct PFPlayerDataManagementRefundPurchaseResponse
{
    /// <summary>
    /// (Optional) The order's updated purchase status.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* purchaseStatus;

} PFPlayerDataManagementRefundPurchaseResponse;

/// <summary>
/// PFPlayerDataManagementResetUserStatisticsRequest data model. Note that this action cannot be un-done.
/// All statistics for this user will be deleted, removing the user from all leaderboards for the game.
/// </summary>
typedef struct PFPlayerDataManagementResetUserStatisticsRequest
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

} PFPlayerDataManagementResetUserStatisticsRequest;

/// <summary>
/// PFPlayerDataManagementResolvePurchaseDisputeRequest data model.
/// </summary>
typedef struct PFPlayerDataManagementResolvePurchaseDisputeRequest
{
    /// <summary>
    /// Unique order ID for the purchase in question.
    /// </summary>
    _Null_terminated_ const char* orderId;

    /// <summary>
    /// Enum for the desired purchase result state after notifying the payment provider. Valid values
    /// are Revoke, Reinstate and Manual. Manual will cause no change to the order state.
    /// </summary>
    PFPlayerDataManagementResolutionOutcome outcome;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) The Reason parameter should correspond with the payment providers reason field, if
    /// they require one such as Facebook. In the case of Facebook this must match one of their refund
    /// or dispute resolution enums (See: https://developers.facebook.com/docs/payments/implementation-guide/handling-disputes-refunds).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* reason;

} PFPlayerDataManagementResolvePurchaseDisputeRequest;

/// <summary>
/// PFPlayerDataManagementResolvePurchaseDisputeResponse data model.
/// </summary>
typedef struct PFPlayerDataManagementResolvePurchaseDisputeResponse
{
    /// <summary>
    /// (Optional) The order's updated purchase status.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* purchaseStatus;

} PFPlayerDataManagementResolvePurchaseDisputeResponse;

/// <summary>
/// PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequest data model. Statistics are numeric values,
/// with each statistic in the title also generating a leaderboard. The ResetInterval enables automatically
/// resetting leaderboards on a specified interval. Upon reset, the statistic updates to a new version
/// with no values (effectively removing all players from the leaderboard). The previous version's statistic
/// values are also archived for retrieval, if needed (see GetPlayerStatisticVersions). Statistics not
/// created via a call to CreatePlayerStatisticDefinition by default have a VersionChangeInterval of Never,
/// meaning they do not reset on a schedule, but they can be set to do so via a call to UpdatePlayerStatisticDefinition.
/// Once a statistic has been reset (sometimes referred to as versioned or incremented), the now-previous
/// version can still be written to for up a short, pre-defined period (currently 10 seconds), to prevent
/// issues with levels completing around the time of the reset. Also, once reset, the historical statistics
/// for players in the title may be retrieved using the URL specified in the version information (GetPlayerStatisticVersions).
/// The AggregationMethod determines what action is taken when a new statistic value is submitted - always
/// update with the new value (Last), use the highest of the old and new values (Max), use the smallest
/// (Min), or add them together (Sum).
/// </summary>
typedef struct PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequest
{
    /// <summary>
    /// (Optional) The aggregation method to use in updating the statistic (defaults to last).
    /// </summary>
    _Maybenull_ PFPlayerDataManagementStatisticAggregationMethod const* aggregationMethod;

    /// <summary>
    /// Unique name of the statistic.
    /// </summary>
    _Null_terminated_ const char* statisticName;

    /// <summary>
    /// (Optional) Interval at which the values of the statistic for all players are reset (changes are
    /// effective at the next occurance of the new interval boundary).
    /// </summary>
    _Maybenull_ PFPlayerDataManagementStatisticResetIntervalOption const* versionChangeInterval;

} PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequest;

/// <summary>
/// PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult data model.
/// </summary>
typedef struct PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult
{
    /// <summary>
    /// (Optional) Updated statistic definition.
    /// </summary>
    _Maybenull_ PFPlayerDataManagementPlayerStatisticDefinition const* statistic;

} PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult;

/// <summary>
/// PFPlayerDataManagementAdminUpdateUserDataRequest data model. This function performs an additive update
/// of the arbitrary JSON object containing the custom data for the user. In updating the custom data
/// object, keys which already exist in the object will have their values overwritten, while keys with
/// null values will be removed. No other key-value pairs will be changed apart from those specified in
/// the call.
/// </summary>
typedef struct PFPlayerDataManagementAdminUpdateUserDataRequest
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
    /// (Optional) Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace,
    /// are limited in size, and may not begin with a '!' character or be null.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) struct PFStringDictionaryEntry const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

    /// <summary>
    /// (Optional) Optional list of Data-keys to remove from UserData. Some SDKs cannot insert null-values
    /// into Data due to language constraints. Use this to delete the keys directly.
    /// </summary>
    _Maybenull_ _Field_size_(keysToRemoveCount) const char* const* keysToRemove;

    /// <summary>
    /// Count of keysToRemove
    /// </summary>
    uint32_t keysToRemoveCount;

    /// <summary>
    /// (Optional) Permission to be applied to all user data keys written in this request. Defaults to
    /// "private" if not set.
    /// </summary>
    _Maybenull_ PFUserDataPermission const* permission;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerDataManagementAdminUpdateUserDataRequest;

/// <summary>
/// PFPlayerDataManagementUpdateUserDataResult data model.
/// </summary>
typedef struct PFPlayerDataManagementUpdateUserDataResult
{
    /// <summary>
    /// Indicates the current version of the data that has been set. This is incremented with every set
    /// call for that type of data (read-only, internal, etc). This version can be provided in Get calls
    /// to find updated data.
    /// </summary>
    uint32_t dataVersion;

} PFPlayerDataManagementUpdateUserDataResult;

/// <summary>
/// PFPlayerDataManagementUpdateUserInternalDataRequest data model. This function performs an additive
/// update of the arbitrary JSON object containing the custom data for the user. In updating the custom
/// data object, keys which already exist in the object will have their values overwritten, keys with
/// null values will be removed. No other key-value pairs will be changed apart from those specified in
/// the call.
/// </summary>
typedef struct PFPlayerDataManagementUpdateUserInternalDataRequest
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
    /// (Optional) Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace,
    /// are limited in size, and may not begin with a '!' character or be null.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) struct PFStringDictionaryEntry const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

    /// <summary>
    /// (Optional) Optional list of Data-keys to remove from UserData. Some SDKs cannot insert null-values
    /// into Data due to language constraints. Use this to delete the keys directly.
    /// </summary>
    _Maybenull_ _Field_size_(keysToRemoveCount) const char* const* keysToRemove;

    /// <summary>
    /// Count of keysToRemove
    /// </summary>
    uint32_t keysToRemoveCount;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerDataManagementUpdateUserInternalDataRequest;

/// <summary>
/// PFPlayerDataManagementClientGetFriendLeaderboardRequest data model.
/// </summary>
typedef struct PFPlayerDataManagementClientGetFriendLeaderboardRequest
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
    /// (Optional) Indicates whether Facebook friends should be included in the response. Default is
    /// true.
    /// </summary>
    _Maybenull_ bool const* includeFacebookFriends;

    /// <summary>
    /// (Optional) Indicates whether Steam service friends should be included in the response. Default
    /// is true.
    /// </summary>
    _Maybenull_ bool const* includeSteamFriends;

    /// <summary>
    /// (Optional) Maximum number of entries to retrieve. Default 10, maximum 100.
    /// </summary>
    _Maybenull_ int32_t const* maxResultsCount;

    /// <summary>
    /// (Optional) If non-null, this determines which properties of the resulting player profiles to
    /// return. For API calls from the client, only the allowed client profile properties for the title
    /// may be requested. These allowed properties are configured in the Game Manager "Client Profile
    /// Options" tab in the "Settings" section.
    /// </summary>
    _Maybenull_ PFPlayerProfileViewConstraints const* profileConstraints;

    /// <summary>
    /// Position in the leaderboard to start this listing (defaults to the first entry).
    /// </summary>
    int32_t startPosition;

    /// <summary>
    /// Statistic used to rank friends for this leaderboard.
    /// </summary>
    _Null_terminated_ const char* statisticName;

    /// <summary>
    /// (Optional) The version of the leaderboard to get.
    /// </summary>
    _Maybenull_ int32_t const* version;

    /// <summary>
    /// (Optional) Xbox token if Xbox friends should be included. Requires Xbox be configured on PlayFab.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* xboxToken;

} PFPlayerDataManagementClientGetFriendLeaderboardRequest;

/// <summary>
/// PFPlayerDataManagementPlayerLeaderboardEntry data model.
/// </summary>
typedef struct PFPlayerDataManagementPlayerLeaderboardEntry
{
    /// <summary>
    /// (Optional) Title-specific display name of the user for this leaderboard entry.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* displayName;

    /// <summary>
    /// (Optional) PlayFab unique identifier of the user for this leaderboard entry.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// User's overall position in the leaderboard.
    /// </summary>
    int32_t position;

    /// <summary>
    /// (Optional) The profile of the user, if requested.
    /// </summary>
    _Maybenull_ PFPlayerProfileModel const* profile;

    /// <summary>
    /// Specific value of the user's statistic.
    /// </summary>
    int32_t statValue;

} PFPlayerDataManagementPlayerLeaderboardEntry;

/// <summary>
/// PFPlayerDataManagementGetLeaderboardResult data model. Note that the Position of the user in the
/// results is for the overall leaderboard. If Facebook friends are included, make sure the access token
/// from previous LoginWithFacebook call is still valid and not expired. If Xbox Live friends are included,
/// make sure the access token from the previous LoginWithXbox call is still valid and not expired. .
/// </summary>
typedef struct PFPlayerDataManagementGetLeaderboardResult
{
    /// <summary>
    /// (Optional) Ordered listing of users and their positions in the requested leaderboard.
    /// </summary>
    _Maybenull_ _Field_size_(leaderboardCount) PFPlayerDataManagementPlayerLeaderboardEntry const* const* leaderboard;

    /// <summary>
    /// Count of leaderboard
    /// </summary>
    uint32_t leaderboardCount;

    /// <summary>
    /// (Optional) The time the next scheduled reset will occur. Null if the leaderboard does not reset
    /// on a schedule.
    /// </summary>
    _Maybenull_ time_t const* nextReset;

    /// <summary>
    /// The version of the leaderboard returned.
    /// </summary>
    int32_t version;

} PFPlayerDataManagementGetLeaderboardResult;

/// <summary>
/// PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequest data model.
/// </summary>
typedef struct PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequest
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
    /// (Optional) Indicates whether Facebook friends should be included in the response. Default is
    /// true.
    /// </summary>
    _Maybenull_ bool const* includeFacebookFriends;

    /// <summary>
    /// (Optional) Indicates whether Steam service friends should be included in the response. Default
    /// is true.
    /// </summary>
    _Maybenull_ bool const* includeSteamFriends;

    /// <summary>
    /// (Optional) Maximum number of entries to retrieve. Default 10, maximum 100.
    /// </summary>
    _Maybenull_ int32_t const* maxResultsCount;

    /// <summary>
    /// (Optional) PlayFab unique identifier of the user to center the leaderboard around. If null will
    /// center on the logged in user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) If non-null, this determines which properties of the resulting player profiles to
    /// return. For API calls from the client, only the allowed client profile properties for the title
    /// may be requested. These allowed properties are configured in the Game Manager "Client Profile
    /// Options" tab in the "Settings" section.
    /// </summary>
    _Maybenull_ PFPlayerProfileViewConstraints const* profileConstraints;

    /// <summary>
    /// Statistic used to rank players for this leaderboard.
    /// </summary>
    _Null_terminated_ const char* statisticName;

    /// <summary>
    /// (Optional) The version of the leaderboard to get.
    /// </summary>
    _Maybenull_ int32_t const* version;

    /// <summary>
    /// (Optional) Xbox token if Xbox friends should be included. Requires Xbox be configured on PlayFab.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* xboxToken;

} PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequest;

/// <summary>
/// PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult data model. Note: When calling 'GetLeaderboardAround...'
/// APIs, the position of the user defaults to 0 when the user does not have the corresponding statistic.If
/// Facebook friends are included, make sure the access token from previous LoginWithFacebook call is
/// still valid and not expired. If Xbox Live friends are included, make sure the access token from the
/// previous LoginWithXbox call is still valid and not expired. .
/// </summary>
typedef struct PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult
{
    /// <summary>
    /// (Optional) Ordered listing of users and their positions in the requested leaderboard.
    /// </summary>
    _Maybenull_ _Field_size_(leaderboardCount) PFPlayerDataManagementPlayerLeaderboardEntry const* const* leaderboard;

    /// <summary>
    /// Count of leaderboard
    /// </summary>
    uint32_t leaderboardCount;

    /// <summary>
    /// (Optional) The time the next scheduled reset will occur. Null if the leaderboard does not reset
    /// on a schedule.
    /// </summary>
    _Maybenull_ time_t const* nextReset;

    /// <summary>
    /// The version of the leaderboard returned.
    /// </summary>
    int32_t version;

} PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult;

/// <summary>
/// PFPlayerDataManagementGetLeaderboardRequest data model.
/// </summary>
typedef struct PFPlayerDataManagementGetLeaderboardRequest
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
    /// Maximum number of entries to retrieve. Default 10, maximum 100.
    /// </summary>
    int32_t maxResultsCount;

    /// <summary>
    /// (Optional) If non-null, this determines which properties of the resulting player profiles to
    /// return. For API calls from the client, only the allowed client profile properties for the title
    /// may be requested. These allowed properties are configured in the Game Manager "Client Profile
    /// Options" tab in the "Settings" section.
    /// </summary>
    _Maybenull_ PFPlayerProfileViewConstraints const* profileConstraints;

    /// <summary>
    /// Position in the leaderboard to start this listing (defaults to the first entry).
    /// </summary>
    int32_t startPosition;

    /// <summary>
    /// Statistic used to rank players for this leaderboard.
    /// </summary>
    _Null_terminated_ const char* statisticName;

    /// <summary>
    /// (Optional) The version of the leaderboard to get.
    /// </summary>
    _Maybenull_ int32_t const* version;

} PFPlayerDataManagementGetLeaderboardRequest;

/// <summary>
/// PFPlayerDataManagementGetLeaderboardAroundPlayerRequest data model.
/// </summary>
typedef struct PFPlayerDataManagementGetLeaderboardAroundPlayerRequest
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
    /// (Optional) Maximum number of entries to retrieve. Default 10, maximum 100.
    /// </summary>
    _Maybenull_ int32_t const* maxResultsCount;

    /// <summary>
    /// (Optional) PlayFab unique identifier of the user to center the leaderboard around. If null will
    /// center on the logged in user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) If non-null, this determines which properties of the resulting player profiles to
    /// return. For API calls from the client, only the allowed client profile properties for the title
    /// may be requested. These allowed properties are configured in the Game Manager "Client Profile
    /// Options" tab in the "Settings" section.
    /// </summary>
    _Maybenull_ PFPlayerProfileViewConstraints const* profileConstraints;

    /// <summary>
    /// Statistic used to rank players for this leaderboard.
    /// </summary>
    _Null_terminated_ const char* statisticName;

    /// <summary>
    /// (Optional) The version of the leaderboard to get.
    /// </summary>
    _Maybenull_ int32_t const* version;

} PFPlayerDataManagementGetLeaderboardAroundPlayerRequest;

/// <summary>
/// PFPlayerDataManagementGetLeaderboardAroundPlayerResult data model. Note: When calling 'GetLeaderboardAround...'
/// APIs, the position of the user defaults to 0 when the user does not have the corresponding statistic.
/// </summary>
typedef struct PFPlayerDataManagementGetLeaderboardAroundPlayerResult
{
    /// <summary>
    /// (Optional) Ordered listing of users and their positions in the requested leaderboard.
    /// </summary>
    _Maybenull_ _Field_size_(leaderboardCount) PFPlayerDataManagementPlayerLeaderboardEntry const* const* leaderboard;

    /// <summary>
    /// Count of leaderboard
    /// </summary>
    uint32_t leaderboardCount;

    /// <summary>
    /// (Optional) The time the next scheduled reset will occur. Null if the leaderboard does not reset
    /// on a schedule.
    /// </summary>
    _Maybenull_ time_t const* nextReset;

    /// <summary>
    /// The version of the leaderboard returned.
    /// </summary>
    int32_t version;

} PFPlayerDataManagementGetLeaderboardAroundPlayerResult;

/// <summary>
/// PFPlayerDataManagementStatisticNameVersion data model.
/// </summary>
typedef struct PFPlayerDataManagementStatisticNameVersion
{
    /// <summary>
    /// Unique name of the statistic.
    /// </summary>
    _Null_terminated_ const char* statisticName;

    /// <summary>
    /// The version of the statistic to be returned.
    /// </summary>
    uint32_t version;

} PFPlayerDataManagementStatisticNameVersion;

/// <summary>
/// PFPlayerDataManagementClientGetPlayerStatisticsRequest data model.
/// </summary>
typedef struct PFPlayerDataManagementClientGetPlayerStatisticsRequest
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
    /// (Optional) Statistics to return (current version will be returned for each).
    /// </summary>
    _Maybenull_ _Field_size_(statisticNamesCount) const char* const* statisticNames;

    /// <summary>
    /// Count of statisticNames
    /// </summary>
    uint32_t statisticNamesCount;

    /// <summary>
    /// (Optional) Statistics to return, if StatisticNames is not set (only statistics which have a version
    /// matching that provided will be returned).
    /// </summary>
    _Maybenull_ _Field_size_(statisticNameVersionsCount) PFPlayerDataManagementStatisticNameVersion const* const* statisticNameVersions;

    /// <summary>
    /// Count of statisticNameVersions
    /// </summary>
    uint32_t statisticNameVersionsCount;

} PFPlayerDataManagementClientGetPlayerStatisticsRequest;

/// <summary>
/// PFPlayerDataManagementClientGetPlayerStatisticsResult data model. In addition to being available
/// for use by the title, the statistics are used for all leaderboard operations in PlayFab.
/// </summary>
typedef struct PFPlayerDataManagementClientGetPlayerStatisticsResult
{
    /// <summary>
    /// (Optional) User statistics for the requested user.
    /// </summary>
    _Maybenull_ _Field_size_(statisticsCount) PFStatisticValue const* const* statistics;

    /// <summary>
    /// Count of statistics
    /// </summary>
    uint32_t statisticsCount;

} PFPlayerDataManagementClientGetPlayerStatisticsResult;

/// <summary>
/// PFPlayerDataManagementClientGetUserDataResult data model.
/// </summary>
typedef struct PFPlayerDataManagementClientGetUserDataResult
{
    /// <summary>
    /// (Optional) User specific data for this title.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) struct PFUserDataRecordDictionaryEntry const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

    /// <summary>
    /// Indicates the current version of the data that has been set. This is incremented with every set
    /// call for that type of data (read-only, internal, etc). This version can be provided in Get calls
    /// to find updated data.
    /// </summary>
    uint32_t dataVersion;

} PFPlayerDataManagementClientGetUserDataResult;

/// <summary>
/// PFPlayerDataManagementStatisticUpdate data model.
/// </summary>
typedef struct PFPlayerDataManagementStatisticUpdate
{
    /// <summary>
    /// Unique name of the statistic.
    /// </summary>
    _Null_terminated_ const char* statisticName;

    /// <summary>
    /// Statistic value for the player.
    /// </summary>
    int32_t value;

    /// <summary>
    /// (Optional) For updates to an existing statistic value for a player, the version of the statistic
    /// when it was loaded. Null when setting the statistic value for the first time.
    /// </summary>
    _Maybenull_ uint32_t const* version;

} PFPlayerDataManagementStatisticUpdate;

/// <summary>
/// PFPlayerDataManagementClientUpdatePlayerStatisticsRequest data model. Enable this option with the
/// 'Allow Client to Post Player Statistics' option in PlayFab GameManager for your title. However, this
/// is not best practice, as this data will no longer be safely controlled by the server. This operation
/// is additive. Statistics not currently defined will be added, while those already defined will be updated
/// with the given values. All other user statistics will remain unchanged. Note that if the statistic
/// is intended to have a reset period, the UpdatePlayerStatisticDefinition API call can be used to define
/// that reset period. Once a statistic has been versioned (reset), the now-previous version can still
/// be written to for up a short, pre-defined period (currently 10 seconds), using the Version parameter
/// in this call.
/// </summary>
typedef struct PFPlayerDataManagementClientUpdatePlayerStatisticsRequest
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
    /// Statistics to be updated with the provided values.
    /// </summary>
    _Field_size_(statisticsCount) PFPlayerDataManagementStatisticUpdate const* const* statistics;

    /// <summary>
    /// Count of statistics
    /// </summary>
    uint32_t statisticsCount;

} PFPlayerDataManagementClientUpdatePlayerStatisticsRequest;

/// <summary>
/// PFPlayerDataManagementClientUpdateUserDataRequest data model. This function performs an additive
/// update of the arbitrary strings containing the custom data for the user. In updating the custom data
/// object, keys which already exist in the object will have their values overwritten, while keys with
/// null values will be removed. New keys will be added, with the given values. No other key-value pairs
/// will be changed apart from those specified in the call.
/// </summary>
typedef struct PFPlayerDataManagementClientUpdateUserDataRequest
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
    /// (Optional) Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace,
    /// are limited in size, and may not begin with a '!' character or be null.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) struct PFStringDictionaryEntry const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

    /// <summary>
    /// (Optional) Optional list of Data-keys to remove from UserData. Some SDKs cannot insert null-values
    /// into Data due to language constraints. Use this to delete the keys directly.
    /// </summary>
    _Maybenull_ _Field_size_(keysToRemoveCount) const char* const* keysToRemove;

    /// <summary>
    /// Count of keysToRemove
    /// </summary>
    uint32_t keysToRemoveCount;

    /// <summary>
    /// (Optional) Permission to be applied to all user data keys written in this request. Defaults to
    /// "private" if not set. This is used for requests by one player for information about another player;
    /// those requests will only return Public keys.
    /// </summary>
    _Maybenull_ PFUserDataPermission const* permission;

} PFPlayerDataManagementClientUpdateUserDataRequest;

/// <summary>
/// PFPlayerDataManagementServerGetFriendLeaderboardRequest data model.
/// </summary>
typedef struct PFPlayerDataManagementServerGetFriendLeaderboardRequest
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
    /// (Optional) Indicates whether Facebook friends should be included in the response. Default is
    /// true.
    /// </summary>
    _Maybenull_ bool const* includeFacebookFriends;

    /// <summary>
    /// (Optional) Indicates whether Steam service friends should be included in the response. Default
    /// is true.
    /// </summary>
    _Maybenull_ bool const* includeSteamFriends;

    /// <summary>
    /// Maximum number of entries to retrieve.
    /// </summary>
    int32_t maxResultsCount;

    /// <summary>
    /// The player whose friend leaderboard to get.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) If non-null, this determines which properties of the resulting player profiles to
    /// return. For API calls from the client, only the allowed client profile properties for the title
    /// may be requested. These allowed properties are configured in the Game Manager "Client Profile
    /// Options" tab in the "Settings" section.
    /// </summary>
    _Maybenull_ PFPlayerProfileViewConstraints const* profileConstraints;

    /// <summary>
    /// Position in the leaderboard to start this listing (defaults to the first entry).
    /// </summary>
    int32_t startPosition;

    /// <summary>
    /// Statistic used to rank friends for this leaderboard.
    /// </summary>
    _Null_terminated_ const char* statisticName;

    /// <summary>
    /// (Optional) The version of the leaderboard to get.
    /// </summary>
    _Maybenull_ int32_t const* version;

    /// <summary>
    /// (Optional) Xbox token if Xbox friends should be included. Requires Xbox be configured on PlayFab.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* xboxToken;

} PFPlayerDataManagementServerGetFriendLeaderboardRequest;

/// <summary>
/// PFPlayerDataManagementGetLeaderboardAroundUserRequest data model.
/// </summary>
typedef struct PFPlayerDataManagementGetLeaderboardAroundUserRequest
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
    /// Maximum number of entries to retrieve.
    /// </summary>
    int32_t maxResultsCount;

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

    /// <summary>
    /// Unique identifier for the title-specific statistic for the leaderboard.
    /// </summary>
    _Null_terminated_ const char* statisticName;

    /// <summary>
    /// (Optional) The version of the leaderboard to get.
    /// </summary>
    _Maybenull_ int32_t const* version;

} PFPlayerDataManagementGetLeaderboardAroundUserRequest;

/// <summary>
/// PFPlayerDataManagementGetLeaderboardAroundUserResult data model. Note: When calling 'GetLeaderboardAround...'
/// APIs, the position of the user defaults to 0 when the user does not have the corresponding statistic.
/// </summary>
typedef struct PFPlayerDataManagementGetLeaderboardAroundUserResult
{
    /// <summary>
    /// (Optional) Ordered listing of users and their positions in the requested leaderboard.
    /// </summary>
    _Maybenull_ _Field_size_(leaderboardCount) PFPlayerDataManagementPlayerLeaderboardEntry const* const* leaderboard;

    /// <summary>
    /// Count of leaderboard
    /// </summary>
    uint32_t leaderboardCount;

    /// <summary>
    /// (Optional) The time the next scheduled reset will occur. Null if the leaderboard does not reset
    /// on a schedule.
    /// </summary>
    _Maybenull_ time_t const* nextReset;

    /// <summary>
    /// The version of the leaderboard returned.
    /// </summary>
    int32_t version;

} PFPlayerDataManagementGetLeaderboardAroundUserResult;

/// <summary>
/// PFPlayerDataManagementServerGetPlayerStatisticsRequest data model.
/// </summary>
typedef struct PFPlayerDataManagementServerGetPlayerStatisticsRequest
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
    /// User for whom statistics are being requested.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) Statistics to return.
    /// </summary>
    _Maybenull_ _Field_size_(statisticNamesCount) const char* const* statisticNames;

    /// <summary>
    /// Count of statisticNames
    /// </summary>
    uint32_t statisticNamesCount;

    /// <summary>
    /// (Optional) Statistics to return, if StatisticNames is not set (only statistics which have a version
    /// matching that provided will be returned).
    /// </summary>
    _Maybenull_ _Field_size_(statisticNameVersionsCount) PFPlayerDataManagementStatisticNameVersion const* const* statisticNameVersions;

    /// <summary>
    /// Count of statisticNameVersions
    /// </summary>
    uint32_t statisticNameVersionsCount;

} PFPlayerDataManagementServerGetPlayerStatisticsRequest;

/// <summary>
/// PFPlayerDataManagementServerGetPlayerStatisticsResult data model. In addition to being available
/// for use by the title, the statistics are used for all leaderboard operations in PlayFab.
/// </summary>
typedef struct PFPlayerDataManagementServerGetPlayerStatisticsResult
{
    /// <summary>
    /// (Optional) PlayFab unique identifier of the user whose statistics are being returned.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) User statistics for the requested user.
    /// </summary>
    _Maybenull_ _Field_size_(statisticsCount) PFStatisticValue const* const* statistics;

    /// <summary>
    /// Count of statistics
    /// </summary>
    uint32_t statisticsCount;

} PFPlayerDataManagementServerGetPlayerStatisticsResult;

/// <summary>
/// PFPlayerDataManagementServerGetUserDataResult data model.
/// </summary>
typedef struct PFPlayerDataManagementServerGetUserDataResult
{
    /// <summary>
    /// (Optional) User specific data for this title.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) struct PFUserDataRecordDictionaryEntry const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

    /// <summary>
    /// Indicates the current version of the data that has been set. This is incremented with every set
    /// call for that type of data (read-only, internal, etc). This version can be provided in Get calls
    /// to find updated data.
    /// </summary>
    uint32_t dataVersion;

    /// <summary>
    /// (Optional) PlayFab unique identifier of the user whose custom data is being returned.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

} PFPlayerDataManagementServerGetUserDataResult;

/// <summary>
/// PFPlayerDataManagementServerUpdatePlayerStatisticsRequest data model. This operation is additive.
/// Statistics not currently defined will be added, while those already defined will be updated with the
/// given values. All other user statistics will remain unchanged.
/// </summary>
typedef struct PFPlayerDataManagementServerUpdatePlayerStatisticsRequest
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
    /// (Optional) Indicates whether the statistics provided should be set, regardless of the aggregation
    /// method set on the statistic. Default is false.
    /// </summary>
    _Maybenull_ bool const* forceUpdate;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// Statistics to be updated with the provided values.
    /// </summary>
    _Field_size_(statisticsCount) PFPlayerDataManagementStatisticUpdate const* const* statistics;

    /// <summary>
    /// Count of statistics
    /// </summary>
    uint32_t statisticsCount;

} PFPlayerDataManagementServerUpdatePlayerStatisticsRequest;

/// <summary>
/// PFPlayerDataManagementServerUpdateUserDataRequest data model. This function performs an additive
/// update of the arbitrary JSON object containing the custom data for the user. In updating the custom
/// data object, keys which already exist in the object will have their values overwritten, while keys
/// with null values will be removed. No other key-value pairs will be changed apart from those specified
/// in the call.
/// </summary>
typedef struct PFPlayerDataManagementServerUpdateUserDataRequest
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
    /// (Optional) Key-value pairs to be written to the custom data. Note that keys are trimmed of whitespace,
    /// are limited in size, and may not begin with a '!' character or be null.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) struct PFStringDictionaryEntry const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

    /// <summary>
    /// (Optional) Optional list of Data-keys to remove from UserData. Some SDKs cannot insert null-values
    /// into Data due to language constraints. Use this to delete the keys directly.
    /// </summary>
    _Maybenull_ _Field_size_(keysToRemoveCount) const char* const* keysToRemove;

    /// <summary>
    /// Count of keysToRemove
    /// </summary>
    uint32_t keysToRemoveCount;

    /// <summary>
    /// (Optional) Permission to be applied to all user data keys written in this request. Defaults to
    /// "private" if not set.
    /// </summary>
    _Maybenull_ PFUserDataPermission const* permission;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFPlayerDataManagementServerUpdateUserDataRequest;

#pragma pop_macro("IN")

}
