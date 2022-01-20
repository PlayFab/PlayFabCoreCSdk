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
enum class PFLeaderboardStatisticAggregationMethod : uint32_t
{
    Last,
    Min,
    Max,
    Sum
};

/// <summary>
/// StatisticResetIntervalOption enum.
/// </summary>
enum class PFLeaderboardStatisticResetIntervalOption : uint32_t
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
enum class PFLeaderboardStatisticVersionStatus : uint32_t
{
    Active,
    SnapshotPending,
    Snapshot,
    ArchivalPending,
    Archived
};

/// <summary>
/// PFLeaderboardCreatePlayerStatisticDefinitionRequest data model. Statistics are numeric values, with
/// each statistic in the title also generating a leaderboard. The ResetInterval enables automatically
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
typedef struct PFLeaderboardCreatePlayerStatisticDefinitionRequest
{
    /// <summary>
    /// (Optional) The aggregation method to use in updating the statistic (defaults to last).
    /// </summary>
    _Maybenull_ PFLeaderboardStatisticAggregationMethod const* aggregationMethod;

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
    _Maybenull_ PFLeaderboardStatisticResetIntervalOption const* versionChangeInterval;

} PFLeaderboardCreatePlayerStatisticDefinitionRequest;

/// <summary>
/// PFLeaderboardPlayerStatisticDefinition data model.
/// </summary>
typedef struct PFLeaderboardPlayerStatisticDefinition
{
    /// <summary>
    /// (Optional) The aggregation method to use in updating the statistic (defaults to last).
    /// </summary>
    _Maybenull_ PFLeaderboardStatisticAggregationMethod const* aggregationMethod;

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
    _Maybenull_ PFLeaderboardStatisticResetIntervalOption const* versionChangeInterval;

} PFLeaderboardPlayerStatisticDefinition;

/// <summary>
/// PFLeaderboardCreatePlayerStatisticDefinitionResult data model.
/// </summary>
typedef struct PFLeaderboardCreatePlayerStatisticDefinitionResult
{
    /// <summary>
    /// (Optional) Created statistic definition.
    /// </summary>
    _Maybenull_ PFLeaderboardPlayerStatisticDefinition const* statistic;

} PFLeaderboardCreatePlayerStatisticDefinitionResult;

/// <summary>
/// PFLeaderboardGetPlayerStatisticDefinitionsResult data model. Statistics are numeric values, with
/// each statistic in the title also generating a leaderboard. The ResetInterval defines the period of
/// time at which the leaderboard for the statistic will automatically reset. Upon reset, the statistic
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
typedef struct PFLeaderboardGetPlayerStatisticDefinitionsResult
{
    /// <summary>
    /// (Optional) The player statistic definitions for the title.
    /// </summary>
    _Maybenull_ _Field_size_(statisticsCount) PFLeaderboardPlayerStatisticDefinition const* const* statistics;

    /// <summary>
    /// Count of statistics
    /// </summary>
    uint32_t statisticsCount;

} PFLeaderboardGetPlayerStatisticDefinitionsResult;

/// <summary>
/// PFLeaderboardGetPlayerStatisticVersionsRequest data model.
/// </summary>
typedef struct PFLeaderboardGetPlayerStatisticVersionsRequest
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

} PFLeaderboardGetPlayerStatisticVersionsRequest;

/// <summary>
/// PFLeaderboardPlayerStatisticVersion data model.
/// </summary>
typedef struct PFLeaderboardPlayerStatisticVersion
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
    _Maybenull_ PFLeaderboardStatisticVersionStatus const* status;

    /// <summary>
    /// Version of the statistic.
    /// </summary>
    uint32_t version;

} PFLeaderboardPlayerStatisticVersion;

/// <summary>
/// PFLeaderboardGetPlayerStatisticVersionsResult data model. Statistics are numeric values, with each
/// statistic in the title also generating a leaderboard. The information returned in the results defines
/// the state of a specific version of a statistic, including when it was or will become the currently
/// active version, when it will (or did) become a previous version, and its archival state if it is no
/// longer the active version. For a statistic which has been reset, once the archival status is Complete,
/// the full set of statistics for all players in the leaderboard for that version may be retrieved via
/// the ArchiveDownloadUrl. Statistics which have not been reset (incremented/versioned) will only have
/// a single version which is not scheduled to reset.
/// </summary>
typedef struct PFLeaderboardGetPlayerStatisticVersionsResult
{
    /// <summary>
    /// (Optional) Version change history of the statistic.
    /// </summary>
    _Maybenull_ _Field_size_(statisticVersionsCount) PFLeaderboardPlayerStatisticVersion const* const* statisticVersions;

    /// <summary>
    /// Count of statisticVersions
    /// </summary>
    uint32_t statisticVersionsCount;

} PFLeaderboardGetPlayerStatisticVersionsResult;

/// <summary>
/// PFLeaderboardIncrementPlayerStatisticVersionRequest data model. Statistics are numeric values, with
/// each statistic in the title also generating a leaderboard. When this call is made on a given statistic,
/// this forces a reset of that statistic. Upon reset, the statistic updates to a new version with no
/// values (effectively removing all players from the leaderboard). The previous version's statistic values
/// are also archived for retrieval, if needed (see GetPlayerStatisticVersions). Statistics not created
/// via a call to CreatePlayerStatisticDefinition by default have a VersionChangeInterval of Never, meaning
/// they do not reset on a schedule, but they can be set to do so via a call to UpdatePlayerStatisticDefinition.
/// Once a statistic has been reset (sometimes referred to as versioned or incremented), the now-previous
/// version can still be written to for up a short, pre-defined period (currently 10 seconds), to prevent
/// issues with levels completing around the time of the reset. Also, once reset, the historical statistics
/// for players in the title may be retrieved using the URL specified in the version information (GetPlayerStatisticVersions).
/// </summary>
typedef struct PFLeaderboardIncrementPlayerStatisticVersionRequest
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

} PFLeaderboardIncrementPlayerStatisticVersionRequest;

/// <summary>
/// PFLeaderboardIncrementPlayerStatisticVersionResult data model.
/// </summary>
typedef struct PFLeaderboardIncrementPlayerStatisticVersionResult
{
    /// <summary>
    /// (Optional) Version change history of the statistic.
    /// </summary>
    _Maybenull_ PFLeaderboardPlayerStatisticVersion const* statisticVersion;

} PFLeaderboardIncrementPlayerStatisticVersionResult;

/// <summary>
/// PFLeaderboardResetUserStatisticsRequest data model. Note that this action cannot be un-done. All
/// statistics for this user will be deleted, removing the user from all leaderboards for the game.
/// </summary>
typedef struct PFLeaderboardResetUserStatisticsRequest
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

} PFLeaderboardResetUserStatisticsRequest;

/// <summary>
/// PFLeaderboardUpdatePlayerStatisticDefinitionRequest data model. Statistics are numeric values, with
/// each statistic in the title also generating a leaderboard. The ResetInterval enables automatically
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
typedef struct PFLeaderboardUpdatePlayerStatisticDefinitionRequest
{
    /// <summary>
    /// (Optional) The aggregation method to use in updating the statistic (defaults to last).
    /// </summary>
    _Maybenull_ PFLeaderboardStatisticAggregationMethod const* aggregationMethod;

    /// <summary>
    /// Unique name of the statistic.
    /// </summary>
    _Null_terminated_ const char* statisticName;

    /// <summary>
    /// (Optional) Interval at which the values of the statistic for all players are reset (changes are
    /// effective at the next occurance of the new interval boundary).
    /// </summary>
    _Maybenull_ PFLeaderboardStatisticResetIntervalOption const* versionChangeInterval;

} PFLeaderboardUpdatePlayerStatisticDefinitionRequest;

/// <summary>
/// PFLeaderboardUpdatePlayerStatisticDefinitionResult data model.
/// </summary>
typedef struct PFLeaderboardUpdatePlayerStatisticDefinitionResult
{
    /// <summary>
    /// (Optional) Updated statistic definition.
    /// </summary>
    _Maybenull_ PFLeaderboardPlayerStatisticDefinition const* statistic;

} PFLeaderboardUpdatePlayerStatisticDefinitionResult;

/// <summary>
/// PFLeaderboardClientGetFriendLeaderboardRequest data model.
/// </summary>
typedef struct PFLeaderboardClientGetFriendLeaderboardRequest
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

} PFLeaderboardClientGetFriendLeaderboardRequest;

/// <summary>
/// PFLeaderboardPlayerLeaderboardEntry data model.
/// </summary>
typedef struct PFLeaderboardPlayerLeaderboardEntry
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

} PFLeaderboardPlayerLeaderboardEntry;

/// <summary>
/// PFLeaderboardGetLeaderboardResult data model. Note that the Position of the user in the results is
/// for the overall leaderboard. If Facebook friends are included, make sure the access token from previous
/// LoginWithFacebook call is still valid and not expired. If Xbox Live friends are included, make sure
/// the access token from the previous LoginWithXbox call is still valid and not expired. .
/// </summary>
typedef struct PFLeaderboardGetLeaderboardResult
{
    /// <summary>
    /// (Optional) Ordered listing of users and their positions in the requested leaderboard.
    /// </summary>
    _Maybenull_ _Field_size_(leaderboardCount) PFLeaderboardPlayerLeaderboardEntry const* const* leaderboard;

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

} PFLeaderboardGetLeaderboardResult;

/// <summary>
/// PFLeaderboardGetFriendLeaderboardAroundPlayerRequest data model.
/// </summary>
typedef struct PFLeaderboardGetFriendLeaderboardAroundPlayerRequest
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

} PFLeaderboardGetFriendLeaderboardAroundPlayerRequest;

/// <summary>
/// PFLeaderboardGetFriendLeaderboardAroundPlayerResult data model. Note: When calling 'GetLeaderboardAround...'
/// APIs, the position of the user defaults to 0 when the user does not have the corresponding statistic.If
/// Facebook friends are included, make sure the access token from previous LoginWithFacebook call is
/// still valid and not expired. If Xbox Live friends are included, make sure the access token from the
/// previous LoginWithXbox call is still valid and not expired. .
/// </summary>
typedef struct PFLeaderboardGetFriendLeaderboardAroundPlayerResult
{
    /// <summary>
    /// (Optional) Ordered listing of users and their positions in the requested leaderboard.
    /// </summary>
    _Maybenull_ _Field_size_(leaderboardCount) PFLeaderboardPlayerLeaderboardEntry const* const* leaderboard;

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

} PFLeaderboardGetFriendLeaderboardAroundPlayerResult;

/// <summary>
/// PFLeaderboardGetLeaderboardRequest data model.
/// </summary>
typedef struct PFLeaderboardGetLeaderboardRequest
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

} PFLeaderboardGetLeaderboardRequest;

/// <summary>
/// PFLeaderboardGetLeaderboardAroundPlayerRequest data model.
/// </summary>
typedef struct PFLeaderboardGetLeaderboardAroundPlayerRequest
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

} PFLeaderboardGetLeaderboardAroundPlayerRequest;

/// <summary>
/// PFLeaderboardGetLeaderboardAroundPlayerResult data model. Note: When calling 'GetLeaderboardAround...'
/// APIs, the position of the user defaults to 0 when the user does not have the corresponding statistic.
/// </summary>
typedef struct PFLeaderboardGetLeaderboardAroundPlayerResult
{
    /// <summary>
    /// (Optional) Ordered listing of users and their positions in the requested leaderboard.
    /// </summary>
    _Maybenull_ _Field_size_(leaderboardCount) PFLeaderboardPlayerLeaderboardEntry const* const* leaderboard;

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

} PFLeaderboardGetLeaderboardAroundPlayerResult;

/// <summary>
/// PFLeaderboardStatisticNameVersion data model.
/// </summary>
typedef struct PFLeaderboardStatisticNameVersion
{
    /// <summary>
    /// Unique name of the statistic.
    /// </summary>
    _Null_terminated_ const char* statisticName;

    /// <summary>
    /// The version of the statistic to be returned.
    /// </summary>
    uint32_t version;

} PFLeaderboardStatisticNameVersion;

/// <summary>
/// PFLeaderboardClientGetPlayerStatisticsRequest data model.
/// </summary>
typedef struct PFLeaderboardClientGetPlayerStatisticsRequest
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
    _Maybenull_ _Field_size_(statisticNameVersionsCount) PFLeaderboardStatisticNameVersion const* const* statisticNameVersions;

    /// <summary>
    /// Count of statisticNameVersions
    /// </summary>
    uint32_t statisticNameVersionsCount;

} PFLeaderboardClientGetPlayerStatisticsRequest;

/// <summary>
/// PFLeaderboardClientGetPlayerStatisticsResult data model. In addition to being available for use by
/// the title, the statistics are used for all leaderboard operations in PlayFab.
/// </summary>
typedef struct PFLeaderboardClientGetPlayerStatisticsResult
{
    /// <summary>
    /// (Optional) User statistics for the requested user.
    /// </summary>
    _Maybenull_ _Field_size_(statisticsCount) PFStatisticValue const* const* statistics;

    /// <summary>
    /// Count of statistics
    /// </summary>
    uint32_t statisticsCount;

} PFLeaderboardClientGetPlayerStatisticsResult;

/// <summary>
/// PFLeaderboardStatisticUpdate data model.
/// </summary>
typedef struct PFLeaderboardStatisticUpdate
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

} PFLeaderboardStatisticUpdate;

/// <summary>
/// PFLeaderboardClientUpdatePlayerStatisticsRequest data model. Enable this option with the 'Allow Client
/// to Post Player Statistics' option in PlayFab GameManager for your title. However, this is not best
/// practice, as this data will no longer be safely controlled by the server. This operation is additive.
/// Statistics not currently defined will be added, while those already defined will be updated with the
/// given values. All other user statistics will remain unchanged. Note that if the statistic is intended
/// to have a reset period, the UpdatePlayerStatisticDefinition API call can be used to define that reset
/// period. Once a statistic has been versioned (reset), the now-previous version can still be written
/// to for up a short, pre-defined period (currently 10 seconds), using the Version parameter in this
/// call.
/// </summary>
typedef struct PFLeaderboardClientUpdatePlayerStatisticsRequest
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
    _Field_size_(statisticsCount) PFLeaderboardStatisticUpdate const* const* statistics;

    /// <summary>
    /// Count of statistics
    /// </summary>
    uint32_t statisticsCount;

} PFLeaderboardClientUpdatePlayerStatisticsRequest;

/// <summary>
/// PFLeaderboardServerGetFriendLeaderboardRequest data model.
/// </summary>
typedef struct PFLeaderboardServerGetFriendLeaderboardRequest
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

} PFLeaderboardServerGetFriendLeaderboardRequest;

/// <summary>
/// PFLeaderboardGetLeaderboardAroundUserRequest data model.
/// </summary>
typedef struct PFLeaderboardGetLeaderboardAroundUserRequest
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

} PFLeaderboardGetLeaderboardAroundUserRequest;

/// <summary>
/// PFLeaderboardGetLeaderboardAroundUserResult data model. Note: When calling 'GetLeaderboardAround...'
/// APIs, the position of the user defaults to 0 when the user does not have the corresponding statistic.
/// </summary>
typedef struct PFLeaderboardGetLeaderboardAroundUserResult
{
    /// <summary>
    /// (Optional) Ordered listing of users and their positions in the requested leaderboard.
    /// </summary>
    _Maybenull_ _Field_size_(leaderboardCount) PFLeaderboardPlayerLeaderboardEntry const* const* leaderboard;

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

} PFLeaderboardGetLeaderboardAroundUserResult;

/// <summary>
/// PFLeaderboardServerGetPlayerStatisticsRequest data model.
/// </summary>
typedef struct PFLeaderboardServerGetPlayerStatisticsRequest
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
    _Maybenull_ _Field_size_(statisticNameVersionsCount) PFLeaderboardStatisticNameVersion const* const* statisticNameVersions;

    /// <summary>
    /// Count of statisticNameVersions
    /// </summary>
    uint32_t statisticNameVersionsCount;

} PFLeaderboardServerGetPlayerStatisticsRequest;

/// <summary>
/// PFLeaderboardServerGetPlayerStatisticsResult data model. In addition to being available for use by
/// the title, the statistics are used for all leaderboard operations in PlayFab.
/// </summary>
typedef struct PFLeaderboardServerGetPlayerStatisticsResult
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

} PFLeaderboardServerGetPlayerStatisticsResult;

/// <summary>
/// PFLeaderboardServerUpdatePlayerStatisticsRequest data model. This operation is additive. Statistics
/// not currently defined will be added, while those already defined will be updated with the given values.
/// All other user statistics will remain unchanged.
/// </summary>
typedef struct PFLeaderboardServerUpdatePlayerStatisticsRequest
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
    _Field_size_(statisticsCount) PFLeaderboardStatisticUpdate const* const* statistics;

    /// <summary>
    /// Count of statistics
    /// </summary>
    uint32_t statisticsCount;

} PFLeaderboardServerUpdatePlayerStatisticsRequest;

#pragma pop_macro("IN")

}
