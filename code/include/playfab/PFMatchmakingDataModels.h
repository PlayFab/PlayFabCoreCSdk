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
/// GameInstanceState enum.
/// </summary>
enum class PFMatchmakingGameInstanceState : uint32_t
{
    Open,
    Closed
};

/// <summary>
/// MatchmakeStatus enum.
/// </summary>
enum class PFMatchmakingMatchmakeStatus : uint32_t
{
    Complete,
    Waiting,
    GameNotFound,
    NoAvailableSlots,
    SessionClosed
};

/// <summary>
/// PlayerConnectionState enum.
/// </summary>
enum class PFMatchmakingPlayerConnectionState : uint32_t
{
    Unassigned,
    Connecting,
    Participating,
    Participated
};

/// <summary>
/// PFMatchmakingGetMatchmakerGameInfoRequest data model.
/// </summary>
typedef struct PFMatchmakingGetMatchmakerGameInfoRequest
{
    /// <summary>
    /// Unique identifier of the lobby for which info is being requested.
    /// </summary>
    _Null_terminated_ const char* lobbyId;

} PFMatchmakingGetMatchmakerGameInfoRequest;

/// <summary>
/// PFMatchmakingGetMatchmakerGameInfoResult data model.
/// </summary>
typedef struct PFMatchmakingGetMatchmakerGameInfoResult
{
    /// <summary>
    /// (Optional) Version identifier of the game server executable binary being run.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildVersion;

    /// <summary>
    /// (Optional) Time when Game Server Instance is currently scheduled to end.
    /// </summary>
    _Maybenull_ time_t const* endTime;

    /// <summary>
    /// (Optional) Unique identifier of the lobby .
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* lobbyId;

    /// <summary>
    /// (Optional) Game mode for this Game Server Instance.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* mode;

    /// <summary>
    /// (Optional) Array of unique PlayFab identifiers for users currently connected to this Game Server
    /// Instance.
    /// </summary>
    _Maybenull_ _Field_size_(playersCount) const char* const* players;

    /// <summary>
    /// Count of players
    /// </summary>
    uint32_t playersCount;

    /// <summary>
    /// (Optional) Region in which the Game Server Instance is running.
    /// </summary>
    _Maybenull_ PFRegion const* region;

    /// <summary>
    /// (Optional) IPV4 address of the server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverIPV4Address;

    /// <summary>
    /// (Optional) IPV6 address of the server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverIPV6Address;

    /// <summary>
    /// Communication port for this Game Server Instance.
    /// </summary>
    uint32_t serverPort;

    /// <summary>
    /// (Optional) Public DNS name (if any) of the server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverPublicDNSName;

    /// <summary>
    /// Time when the Game Server Instance was created.
    /// </summary>
    time_t startTime;

    /// <summary>
    /// (Optional) Unique identifier of the Game Server Instance for this lobby.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* titleId;

} PFMatchmakingGetMatchmakerGameInfoResult;

/// <summary>
/// PFMatchmakingGetMatchmakerGameModesRequest data model. These details are used by the PlayFab matchmaking
/// service to determine if an existing Game Server Instance has room for additional users, and by the
/// PlayFab game server management service to determine when a new Game Server Host should be created
/// in order to prevent excess load on existing Hosts.
/// </summary>
typedef struct PFMatchmakingGetMatchmakerGameModesRequest
{
    /// <summary>
    /// Previously uploaded build version for which game modes are being requested.
    /// </summary>
    _Null_terminated_ const char* buildVersion;

} PFMatchmakingGetMatchmakerGameModesRequest;

/// <summary>
/// PFMatchmakingGameModeInfo data model.
/// </summary>
typedef struct PFMatchmakingGameModeInfo
{
    /// <summary>
    /// Specific game mode type.
    /// </summary>
    _Null_terminated_ const char* gamemode;

    /// <summary>
    /// Maximum user count a specific Game Server Instance can support.
    /// </summary>
    uint32_t maxPlayerCount;

    /// <summary>
    /// Minimum user count required for this Game Server Instance to continue (usually 1).
    /// </summary>
    uint32_t minPlayerCount;

    /// <summary>
    /// (Optional) Whether to start as an open session, meaning that players can matchmake into it (defaults
    /// to true).
    /// </summary>
    _Maybenull_ bool const* startOpen;

} PFMatchmakingGameModeInfo;

/// <summary>
/// PFMatchmakingGetMatchmakerGameModesResult data model.
/// </summary>
typedef struct PFMatchmakingGetMatchmakerGameModesResult
{
    /// <summary>
    /// (Optional) Array of game modes available for the specified build.
    /// </summary>
    _Maybenull_ _Field_size_(gameModesCount) PFMatchmakingGameModeInfo const* const* gameModes;

    /// <summary>
    /// Count of gameModes
    /// </summary>
    uint32_t gameModesCount;

} PFMatchmakingGetMatchmakerGameModesResult;

/// <summary>
/// PFMatchmakingContainer_Dictionary_String_String data model. A data container.
/// </summary>
typedef struct PFMatchmakingContainer_Dictionary_String_String
{
    /// <summary>
    /// (Optional) Content of data.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) struct PFStringDictionaryEntry const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

} PFMatchmakingContainer_Dictionary_String_String;

/// <summary>
/// PFMatchmakingCollectionFilter data model. Collection filter to include and/or exclude collections
/// with certain key-value pairs. The filter generates a collection set defined by Includes rules and
/// then remove collections that matches the Excludes rules. A collection is considered matching a rule
/// if the rule describes a subset of the collection. .
/// </summary>
typedef struct PFMatchmakingCollectionFilter
{
    /// <summary>
    /// (Optional) List of Exclude rules, with any of which if a collection matches, it is excluded by
    /// the filter.
    /// </summary>
    _Maybenull_ _Field_size_(excludesCount) PFMatchmakingContainer_Dictionary_String_String const* const* excludes;

    /// <summary>
    /// Count of excludes
    /// </summary>
    uint32_t excludesCount;

    /// <summary>
    /// (Optional) List of Include rules, with any of which if a collection matches, it is included by
    /// the filter, unless it is excluded by one of the Exclude rule.
    /// </summary>
    _Maybenull_ _Field_size_(includesCount) PFMatchmakingContainer_Dictionary_String_String const* const* includes;

    /// <summary>
    /// Count of includes
    /// </summary>
    uint32_t includesCount;

} PFMatchmakingCollectionFilter;

/// <summary>
/// PFMatchmakingCurrentGamesRequest data model.
/// </summary>
typedef struct PFMatchmakingCurrentGamesRequest
{
    /// <summary>
    /// (Optional) Build to match against.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildVersion;

    /// <summary>
    /// (Optional) Game mode to look for.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* gameMode;

    /// <summary>
    /// (Optional) Region to check for Game Server Instances.
    /// </summary>
    _Maybenull_ PFRegion const* region;

    /// <summary>
    /// (Optional) Statistic name to find statistic-based matches.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* statisticName;

    /// <summary>
    /// (Optional) Filter to include and/or exclude Game Server Instances associated with certain tags.
    /// </summary>
    _Maybenull_ PFMatchmakingCollectionFilter const* tagFilter;

} PFMatchmakingCurrentGamesRequest;

/// <summary>
/// PFMatchmakingGameInfo data model.
/// </summary>
typedef struct PFMatchmakingGameInfo
{
    /// <summary>
    /// (Optional) Build version this server is running.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildVersion;

    /// <summary>
    /// (Optional) Game mode this server is running.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* gameMode;

    /// <summary>
    /// (Optional) Game session custom data.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* gameServerData;

    /// <summary>
    /// (Optional) Game specific string denoting server configuration.
    /// </summary>
    _Maybenull_ PFMatchmakingGameInstanceState const* gameServerStateEnum;

    /// <summary>
    /// (Optional) Last heartbeat of the game server instance, used in external game server provider
    /// mode.
    /// </summary>
    _Maybenull_ time_t const* lastHeartbeat;

    /// <summary>
    /// (Optional) Unique lobby identifier for this game server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* lobbyID;

    /// <summary>
    /// (Optional) Maximum players this server can support.
    /// </summary>
    _Maybenull_ int32_t const* maxPlayers;

    /// <summary>
    /// (Optional) Array of current player IDs on this server.
    /// </summary>
    _Maybenull_ _Field_size_(playerUserIdsCount) const char* const* playerUserIds;

    /// <summary>
    /// Count of playerUserIds
    /// </summary>
    uint32_t playerUserIdsCount;

    /// <summary>
    /// (Optional) Region to which this server is associated.
    /// </summary>
    _Maybenull_ PFRegion const* region;

    /// <summary>
    /// Duration in seconds this server has been running.
    /// </summary>
    uint32_t runTime;

    /// <summary>
    /// (Optional) IPV4 address of the server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverIPV4Address;

    /// <summary>
    /// (Optional) IPV6 address of the server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverIPV6Address;

    /// <summary>
    /// (Optional) Port number to use for non-http communications with the server.
    /// </summary>
    _Maybenull_ int32_t const* serverPort;

    /// <summary>
    /// (Optional) Public DNS name (if any) of the server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverPublicDNSName;

    /// <summary>
    /// (Optional) Stastic used to match this game in player statistic matchmaking.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* statisticName;

    /// <summary>
    /// (Optional) Game session tags.
    /// </summary>
    _Maybenull_ _Field_size_(tagsCount) struct PFStringDictionaryEntry const* tags;

    /// <summary>
    /// Count of tags
    /// </summary>
    uint32_t tagsCount;

} PFMatchmakingGameInfo;

/// <summary>
/// PFMatchmakingCurrentGamesResult data model.
/// </summary>
typedef struct PFMatchmakingCurrentGamesResult
{
    /// <summary>
    /// Number of games running.
    /// </summary>
    int32_t gameCount;

    /// <summary>
    /// (Optional) Array of games found.
    /// </summary>
    _Maybenull_ _Field_size_(gamesCount) PFMatchmakingGameInfo const* const* games;

    /// <summary>
    /// Count of games
    /// </summary>
    uint32_t gamesCount;

    /// <summary>
    /// Total number of players across all servers.
    /// </summary>
    int32_t playerCount;

} PFMatchmakingCurrentGamesResult;

/// <summary>
/// PFMatchmakingGameServerRegionsRequest data model.
/// </summary>
typedef struct PFMatchmakingGameServerRegionsRequest
{
    /// <summary>
    /// Version of game server for which stats are being requested.
    /// </summary>
    _Null_terminated_ const char* buildVersion;

    /// <summary>
    /// (Optional) Unique identifier for the title, found in the Settings > Game Properties section of
    /// the PlayFab developer site when a title has been selected.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* titleId;

} PFMatchmakingGameServerRegionsRequest;

/// <summary>
/// PFMatchmakingRegionInfo data model.
/// </summary>
typedef struct PFMatchmakingRegionInfo
{
    /// <summary>
    /// Indicates whether the server specified is available in this region.
    /// </summary>
    bool available;

    /// <summary>
    /// (Optional) Name of the region.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* name;

    /// <summary>
    /// (Optional) Url to ping to get roundtrip time.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* pingUrl;

    /// <summary>
    /// (Optional) Unique identifier for the region.
    /// </summary>
    _Maybenull_ PFRegion const* region;

} PFMatchmakingRegionInfo;

/// <summary>
/// PFMatchmakingGameServerRegionsResult data model.
/// </summary>
typedef struct PFMatchmakingGameServerRegionsResult
{
    /// <summary>
    /// (Optional) Array of regions found matching the request parameters.
    /// </summary>
    _Maybenull_ _Field_size_(regionsCount) PFMatchmakingRegionInfo const* const* regions;

    /// <summary>
    /// Count of regions
    /// </summary>
    uint32_t regionsCount;

} PFMatchmakingGameServerRegionsResult;

/// <summary>
/// PFMatchmakingMatchmakeRequest data model.
/// </summary>
typedef struct PFMatchmakingMatchmakeRequest
{
    /// <summary>
    /// (Optional) Build version to match against. [Note: Required if LobbyId is not specified].
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* buildVersion;

    /// <summary>
    /// (Optional) Character to use for stats based matching. Leave null to use account stats.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* characterId;

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
    /// (Optional) Game mode to match make against. [Note: Required if LobbyId is not specified].
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* gameMode;

    /// <summary>
    /// (Optional) Lobby identifier to match make against. This is used to select a specific Game Server
    /// Instance.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* lobbyId;

    /// <summary>
    /// (Optional) Region to match make against. [Note: Required if LobbyId is not specified].
    /// </summary>
    _Maybenull_ PFRegion const* region;

    /// <summary>
    /// (Optional) Start a game session if one with an open slot is not found. Defaults to true.
    /// </summary>
    _Maybenull_ bool const* startNewIfNoneFound;

    /// <summary>
    /// (Optional) Player statistic to use in finding a match. May be null for no stat-based matching.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* statisticName;

    /// <summary>
    /// (Optional) Filter to include and/or exclude Game Server Instances associated with certain Tags.
    /// </summary>
    _Maybenull_ PFMatchmakingCollectionFilter const* tagFilter;

} PFMatchmakingMatchmakeRequest;

/// <summary>
/// PFMatchmakingMatchmakeResult data model.
/// </summary>
typedef struct PFMatchmakingMatchmakeResult
{
    /// <summary>
    /// (Optional) Timestamp for when the server will expire, if applicable.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* expires;

    /// <summary>
    /// (Optional) Unique lobby identifier of the server matched.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* lobbyID;

    /// <summary>
    /// (Optional) Time in milliseconds the application is configured to wait on matchmaking results.
    /// </summary>
    _Maybenull_ int32_t const* pollWaitTimeMS;

    /// <summary>
    /// (Optional) IPV4 address of the server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverIPV4Address;

    /// <summary>
    /// (Optional) IPV6 address of the server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverIPV6Address;

    /// <summary>
    /// (Optional) Port number to use for non-http communications with the server.
    /// </summary>
    _Maybenull_ int32_t const* serverPort;

    /// <summary>
    /// (Optional) Public DNS name (if any) of the server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverPublicDNSName;

    /// <summary>
    /// (Optional) Result of match making process.
    /// </summary>
    _Maybenull_ PFMatchmakingMatchmakeStatus const* status;

    /// <summary>
    /// (Optional) Server authorization ticket (used by RedeemMatchmakerTicket to validate user insertion
    /// into the game).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* ticket;

} PFMatchmakingMatchmakeResult;

/// <summary>
/// PFMatchmakingAuthUserRequest data model. This API allows the external match-making service to confirm
/// that the user has a valid Session Ticket for the title, in order to securely enable match-making.
/// The client passes the user's Session Ticket to the external match-making service, which then passes
/// the Session Ticket in as the AuthorizationTicket in this call.
/// </summary>
typedef struct PFMatchmakingAuthUserRequest
{
    /// <summary>
    /// Session Ticket provided by the client.
    /// </summary>
    _Null_terminated_ const char* authorizationTicket;

} PFMatchmakingAuthUserRequest;

/// <summary>
/// PFMatchmakingAuthUserResponse data model.
/// </summary>
typedef struct PFMatchmakingAuthUserResponse
{
    /// <summary>
    /// Boolean indicating if the user has been authorized to use the external match-making service.
    /// </summary>
    bool authorized;

    /// <summary>
    /// (Optional) PlayFab unique identifier of the account that has been authorized.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

} PFMatchmakingAuthUserResponse;

/// <summary>
/// PFMatchmakingPlayerJoinedRequest data model.
/// </summary>
typedef struct PFMatchmakingPlayerJoinedRequest
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
    /// Unique identifier of the Game Server Instance the user is joining. This must be a Game Server
    /// Instance started with the Matchmaker/StartGame API.
    /// </summary>
    _Null_terminated_ const char* lobbyId;

    /// <summary>
    /// PlayFab unique identifier for the player joining.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFMatchmakingPlayerJoinedRequest;

/// <summary>
/// PFMatchmakingPlayerLeftRequest data model.
/// </summary>
typedef struct PFMatchmakingPlayerLeftRequest
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
    /// Unique identifier of the Game Server Instance the user is leaving. This must be a Game Server
    /// Instance started with the Matchmaker/StartGame API.
    /// </summary>
    _Null_terminated_ const char* lobbyId;

    /// <summary>
    /// PlayFab unique identifier for the player leaving.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFMatchmakingPlayerLeftRequest;

/// <summary>
/// PFMatchmakingUserInfoRequest data model.
/// </summary>
typedef struct PFMatchmakingUserInfoRequest
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
    /// Minimum catalog version for which data is requested (filters the results to only contain inventory
    /// items which have a catalog version of this or higher).
    /// </summary>
    int32_t minCatalogVersion;

    /// <summary>
    /// PlayFab unique identifier of the user whose information is being requested.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFMatchmakingUserInfoRequest;

/// <summary>
/// PFMatchmakingUserInfoResponse data model.
/// </summary>
typedef struct PFMatchmakingUserInfoResponse
{
    /// <summary>
    /// (Optional) Array of inventory items in the user's current inventory.
    /// </summary>
    _Maybenull_ _Field_size_(inventoryCount) PFItemInstance const* const* inventory;

    /// <summary>
    /// Count of inventory
    /// </summary>
    uint32_t inventoryCount;

    /// <summary>
    /// Boolean indicating whether the user is a developer.
    /// </summary>
    bool isDeveloper;

    /// <summary>
    /// (Optional) PlayFab unique identifier of the user whose information was requested.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) Steam unique identifier, if the user has an associated Steam account.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* steamId;

    /// <summary>
    /// (Optional) Title specific display name, if set.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* titleDisplayName;

    /// <summary>
    /// (Optional) PlayFab unique user name.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* username;

    /// <summary>
    /// (Optional) Array of virtual currency balance(s) belonging to the user.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyCount) struct PFInt32DictionaryEntry const* virtualCurrency;

    /// <summary>
    /// Count of virtualCurrency
    /// </summary>
    uint32_t virtualCurrencyCount;

    /// <summary>
    /// (Optional) Array of remaining times and timestamps for virtual currencies.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyRechargeTimesCount) struct PFVirtualCurrencyRechargeTimeDictionaryEntry const* virtualCurrencyRechargeTimes;

    /// <summary>
    /// Count of virtualCurrencyRechargeTimes
    /// </summary>
    uint32_t virtualCurrencyRechargeTimesCount;

} PFMatchmakingUserInfoResponse;

/// <summary>
/// PFMatchmakingDeregisterGameRequest data model.
/// </summary>
typedef struct PFMatchmakingDeregisterGameRequest
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
    /// Unique identifier for the Game Server Instance that is being deregistered.
    /// </summary>
    _Null_terminated_ const char* lobbyId;

} PFMatchmakingDeregisterGameRequest;

/// <summary>
/// PFMatchmakingNotifyMatchmakerPlayerLeftRequest data model.
/// </summary>
typedef struct PFMatchmakingNotifyMatchmakerPlayerLeftRequest
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
    /// Unique identifier of the Game Instance the user is leaving.
    /// </summary>
    _Null_terminated_ const char* lobbyId;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFMatchmakingNotifyMatchmakerPlayerLeftRequest;

/// <summary>
/// PFMatchmakingNotifyMatchmakerPlayerLeftResult data model.
/// </summary>
typedef struct PFMatchmakingNotifyMatchmakerPlayerLeftResult
{
    /// <summary>
    /// (Optional) State of user leaving the Game Server Instance.
    /// </summary>
    _Maybenull_ PFMatchmakingPlayerConnectionState const* playerState;

} PFMatchmakingNotifyMatchmakerPlayerLeftResult;

/// <summary>
/// PFMatchmakingRedeemMatchmakerTicketRequest data model. This function is used by a Game Server Instance
/// to validate with the PlayFab service that a user has been registered as connected to the server. The
/// Ticket is provided to the client either as a result of a call to StartGame or Matchmake, each of which
/// return a Ticket specific to the Game Server Instance. This function will fail in any case where the
/// Ticket presented is not valid for the specific Game Server Instance making the call. Note that data
/// returned may be Personally Identifying Information (PII), such as email address, and so care should
/// be taken in how this data is stored and managed. Since this call will always return the relevant information
/// for users who have accessed the title, the recommendation is to not store this data locally.
/// </summary>
typedef struct PFMatchmakingRedeemMatchmakerTicketRequest
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
    /// Unique identifier of the Game Server Instance that is asking for validation of the authorization
    /// ticket.
    /// </summary>
    _Null_terminated_ const char* lobbyId;

    /// <summary>
    /// Server authorization ticket passed back from a call to Matchmake or StartGame.
    /// </summary>
    _Null_terminated_ const char* ticket;

} PFMatchmakingRedeemMatchmakerTicketRequest;

/// <summary>
/// PFMatchmakingRedeemMatchmakerTicketResult data model.
/// </summary>
typedef struct PFMatchmakingRedeemMatchmakerTicketResult
{
    /// <summary>
    /// (Optional) Error value if the ticket was not validated.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* error;

    /// <summary>
    /// Boolean indicating whether the ticket was validated by the PlayFab service.
    /// </summary>
    bool ticketIsValid;

    /// <summary>
    /// (Optional) User account information for the user validated.
    /// </summary>
    _Maybenull_ PFUserAccountInfo const* userInfo;

} PFMatchmakingRedeemMatchmakerTicketResult;

/// <summary>
/// PFMatchmakingRefreshGameServerInstanceHeartbeatRequest data model.
/// </summary>
typedef struct PFMatchmakingRefreshGameServerInstanceHeartbeatRequest
{
    /// <summary>
    /// Unique identifier of the Game Server Instance for which the heartbeat is updated.
    /// </summary>
    _Null_terminated_ const char* lobbyId;

} PFMatchmakingRefreshGameServerInstanceHeartbeatRequest;

/// <summary>
/// PFMatchmakingRegisterGameRequest data model.
/// </summary>
typedef struct PFMatchmakingRegisterGameRequest
{
    /// <summary>
    /// Unique identifier of the build running on the Game Server Instance.
    /// </summary>
    _Null_terminated_ const char* build;

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
    /// Game Mode the Game Server instance is running. Note that this must be defined in the Game Modes
    /// tab in the PlayFab Game Manager, along with the Build ID (the same Game Mode can be defined for
    /// multiple Build IDs).
    /// </summary>
    _Null_terminated_ const char* gameMode;

    /// <summary>
    /// (Optional) Previous lobby id if re-registering an existing game.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* lobbyId;

    /// <summary>
    /// Region in which the Game Server Instance is running. For matchmaking using non-AWS region names,
    /// set this to any AWS region and use Tags (below) to specify your custom region.
    /// </summary>
    PFRegion region;

    /// <summary>
    /// (Optional) IPV4 address of the game server instance.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverIPV4Address;

    /// <summary>
    /// (Optional) IPV6 address (if any) of the game server instance.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverIPV6Address;

    /// <summary>
    /// Port number for communication with the Game Server Instance.
    /// </summary>
    _Null_terminated_ const char* serverPort;

    /// <summary>
    /// (Optional) Public DNS name (if any) of the server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serverPublicDNSName;

    /// <summary>
    /// (Optional) Tags for the Game Server Instance.
    /// </summary>
    _Maybenull_ _Field_size_(tagsCount) struct PFStringDictionaryEntry const* tags;

    /// <summary>
    /// Count of tags
    /// </summary>
    uint32_t tagsCount;

} PFMatchmakingRegisterGameRequest;

/// <summary>
/// PFMatchmakingRegisterGameResponse data model.
/// </summary>
typedef struct PFMatchmakingRegisterGameResponse
{
    /// <summary>
    /// (Optional) Unique identifier generated for the Game Server Instance that is registered. If LobbyId
    /// is specified in request and the game still exists in PlayFab, the LobbyId in request is returned.
    /// Otherwise a new lobby id will be returned.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* lobbyId;

} PFMatchmakingRegisterGameResponse;

/// <summary>
/// PFMatchmakingSetGameServerInstanceDataRequest data model.
/// </summary>
typedef struct PFMatchmakingSetGameServerInstanceDataRequest
{
    /// <summary>
    /// Custom data to set for the specified game server instance.
    /// </summary>
    _Null_terminated_ const char* gameServerData;

    /// <summary>
    /// Unique identifier of the Game Instance to be updated, in decimal format.
    /// </summary>
    _Null_terminated_ const char* lobbyId;

} PFMatchmakingSetGameServerInstanceDataRequest;

/// <summary>
/// PFMatchmakingSetGameServerInstanceStateRequest data model.
/// </summary>
typedef struct PFMatchmakingSetGameServerInstanceStateRequest
{
    /// <summary>
    /// Unique identifier of the Game Instance to be updated, in decimal format.
    /// </summary>
    _Null_terminated_ const char* lobbyId;

    /// <summary>
    /// State to set for the specified game server instance.
    /// </summary>
    PFMatchmakingGameInstanceState state;

} PFMatchmakingSetGameServerInstanceStateRequest;

/// <summary>
/// PFMatchmakingSetGameServerInstanceTagsRequest data model.
/// </summary>
typedef struct PFMatchmakingSetGameServerInstanceTagsRequest
{
    /// <summary>
    /// Unique identifier of the Game Server Instance to be updated.
    /// </summary>
    _Null_terminated_ const char* lobbyId;

    /// <summary>
    /// Tags to set for the specified Game Server Instance. Note that this is the complete list of tags
    /// to be associated with the Game Server Instance.
    /// </summary>
    _Field_size_(tagsCount) struct PFStringDictionaryEntry const* tags;

    /// <summary>
    /// Count of tags
    /// </summary>
    uint32_t tagsCount;

} PFMatchmakingSetGameServerInstanceTagsRequest;

/// <summary>
/// PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequest data model. Cancels all tickets of which
/// the player is a member in a given queue that are not cancelled or matched. This API is useful if you
/// lose track of what tickets the player is a member of (if the title crashes for instance) and want
/// to "reset". The Entity field is optional if the caller is a player and defaults to that player. Players
/// may not cancel tickets for other people. The Entity field is required if the caller is a server (authenticated
/// as the title).
/// </summary>
typedef struct PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequest
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
    /// (Optional) The entity key of the player whose tickets should be canceled.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// The name of the queue from which a player's tickets should be canceled.
    /// </summary>
    _Null_terminated_ const char* queueName;

} PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequest;

/// <summary>
/// PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequest data model. Cancels all backfill tickets
/// of which the player is a member in a given queue that are not cancelled or matched. This API is useful
/// if you lose track of what tickets the player is a member of (if the server crashes for instance) and
/// want to "reset".
/// </summary>
typedef struct PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequest
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
    /// The entity key of the player whose backfill tickets should be canceled.
    /// </summary>
    PFEntityKey const* entity;

    /// <summary>
    /// The name of the queue from which a player's backfill tickets should be canceled.
    /// </summary>
    _Null_terminated_ const char* queueName;

} PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequest;

/// <summary>
/// PFMatchmakingCancelMatchmakingTicketRequest data model. Only servers and ticket members can cancel
/// a ticket. The ticket can be in five different states when it is cancelled. 1: the ticket is waiting
/// for members to join it, and it has not started matching. If the ticket is cancelled at this stage,
/// it will never match. 2: the ticket is matching. If the ticket is cancelled, it will stop matching.
/// 3: the ticket is matched. A matched ticket cannot be cancelled. 4: the ticket is already cancelled
/// and nothing happens. 5: the ticket is waiting for a server. If the ticket is cancelled, server allocation
/// will be stopped. A server may still be allocated due to a race condition, but that will not be reflected
/// in the ticket. There may be race conditions between the ticket getting matched and the client making
/// a cancellation request. The client must handle the possibility that the cancel request fails if a
/// match is found before the cancellation request is processed. We do not allow resubmitting a cancelled
/// ticket because players must consent to enter matchmaking again. Create a new ticket instead.
/// </summary>
typedef struct PFMatchmakingCancelMatchmakingTicketRequest
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
    /// The name of the queue the ticket is in.
    /// </summary>
    _Null_terminated_ const char* queueName;

    /// <summary>
    /// The Id of the ticket to find a match for.
    /// </summary>
    _Null_terminated_ const char* ticketId;

} PFMatchmakingCancelMatchmakingTicketRequest;

/// <summary>
/// PFMatchmakingCancelServerBackfillTicketRequest data model. Only servers can cancel a backfill ticket.
/// The ticket can be in three different states when it is cancelled. 1: the ticket is matching. If the
/// ticket is cancelled, it will stop matching. 2: the ticket is matched. A matched ticket cannot be cancelled.
/// 3: the ticket is already cancelled and nothing happens. There may be race conditions between the ticket
/// getting matched and the server making a cancellation request. The server must handle the possibility
/// that the cancel request fails if a match is found before the cancellation request is processed. We
/// do not allow resubmitting a cancelled ticket. Create a new ticket instead.
/// </summary>
typedef struct PFMatchmakingCancelServerBackfillTicketRequest
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
    /// The name of the queue the ticket is in.
    /// </summary>
    _Null_terminated_ const char* queueName;

    /// <summary>
    /// The Id of the ticket to find a match for.
    /// </summary>
    _Null_terminated_ const char* ticketId;

} PFMatchmakingCancelServerBackfillTicketRequest;

/// <summary>
/// PFMatchmakingMatchmakingPlayerAttributes data model. The matchmaking attributes for a user.
/// </summary>
typedef struct PFMatchmakingMatchmakingPlayerAttributes
{
    /// <summary>
    /// (Optional) A data object representing a user's attributes.
    /// </summary>
    PFJsonObject dataObject;

    /// <summary>
    /// (Optional) An escaped data object representing a user's attributes.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* escapedDataObject;

} PFMatchmakingMatchmakingPlayerAttributes;

/// <summary>
/// PFMatchmakingMatchmakingPlayer data model. A user in a matchmaking ticket.
/// </summary>
typedef struct PFMatchmakingMatchmakingPlayer
{
    /// <summary>
    /// (Optional) The user's attributes custom to the title.
    /// </summary>
    _Maybenull_ PFMatchmakingMatchmakingPlayerAttributes const* attributes;

    /// <summary>
    /// The entity key of the matchmaking user.
    /// </summary>
    PFEntityKey const* entity;

} PFMatchmakingMatchmakingPlayer;

/// <summary>
/// PFMatchmakingCreateMatchmakingTicketRequest data model. The client specifies the creator's attributes
/// and optionally a list of other users to match with.
/// </summary>
typedef struct PFMatchmakingCreateMatchmakingTicketRequest
{
    /// <summary>
    /// The User who created this ticket.
    /// </summary>
    PFMatchmakingMatchmakingPlayer const* creator;

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
    /// How long to attempt matching this ticket in seconds.
    /// </summary>
    int32_t giveUpAfterSeconds;

    /// <summary>
    /// (Optional) A list of Entity Keys of other users to match with.
    /// </summary>
    _Maybenull_ _Field_size_(membersToMatchWithCount) PFEntityKey const* const* membersToMatchWith;

    /// <summary>
    /// Count of membersToMatchWith
    /// </summary>
    uint32_t membersToMatchWithCount;

    /// <summary>
    /// The Id of a match queue.
    /// </summary>
    _Null_terminated_ const char* queueName;

} PFMatchmakingCreateMatchmakingTicketRequest;

/// <summary>
/// PFMatchmakingCreateMatchmakingTicketResult data model.
/// </summary>
typedef struct PFMatchmakingCreateMatchmakingTicketResult
{
    /// <summary>
    /// The Id of the ticket to find a match for.
    /// </summary>
    _Null_terminated_ const char* ticketId;

} PFMatchmakingCreateMatchmakingTicketResult;

/// <summary>
/// PFMatchmakingMatchmakingPlayerWithTeamAssignment data model. A player in a created matchmaking match
/// with a team assignment.
/// </summary>
typedef struct PFMatchmakingMatchmakingPlayerWithTeamAssignment
{
    /// <summary>
    /// (Optional) The user's attributes custom to the title. These attributes will be null unless the
    /// request has ReturnMemberAttributes flag set to true.
    /// </summary>
    _Maybenull_ PFMatchmakingMatchmakingPlayerAttributes const* attributes;

    /// <summary>
    /// The entity key of the matchmaking user.
    /// </summary>
    PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The Id of the team the User is assigned to.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* teamId;

} PFMatchmakingMatchmakingPlayerWithTeamAssignment;

/// <summary>
/// PFMatchmakingServerDetails data model.
/// </summary>
typedef struct PFMatchmakingServerDetails
{
    /// <summary>
    /// (Optional) The fully qualified domain name of the virtual machine that is hosting this multiplayer
    /// server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* fqdn;

    /// <summary>
    /// (Optional) The IPv4 address of the virtual machine that is hosting this multiplayer server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* iPV4Address;

    /// <summary>
    /// (Optional) The ports the multiplayer server uses.
    /// </summary>
    _Maybenull_ _Field_size_(portsCount) PFPort const* const* ports;

    /// <summary>
    /// Count of ports
    /// </summary>
    uint32_t portsCount;

    /// <summary>
    /// (Optional) The server's region.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* region;

} PFMatchmakingServerDetails;

/// <summary>
/// PFMatchmakingCreateServerBackfillTicketRequest data model. The server specifies all the members,
/// their teams and their attributes, and the server details if applicable.
/// </summary>
typedef struct PFMatchmakingCreateServerBackfillTicketRequest
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
    /// How long to attempt matching this ticket in seconds.
    /// </summary>
    int32_t giveUpAfterSeconds;

    /// <summary>
    /// The users who will be part of this ticket, along with their team assignments.
    /// </summary>
    _Field_size_(membersCount) PFMatchmakingMatchmakingPlayerWithTeamAssignment const* const* members;

    /// <summary>
    /// Count of members
    /// </summary>
    uint32_t membersCount;

    /// <summary>
    /// The Id of a match queue.
    /// </summary>
    _Null_terminated_ const char* queueName;

    /// <summary>
    /// (Optional) The details of the server the members are connected to.
    /// </summary>
    _Maybenull_ PFMatchmakingServerDetails const* serverDetails;

} PFMatchmakingCreateServerBackfillTicketRequest;

/// <summary>
/// PFMatchmakingCreateServerBackfillTicketResult data model.
/// </summary>
typedef struct PFMatchmakingCreateServerBackfillTicketResult
{
    /// <summary>
    /// The Id of the ticket to find a match for.
    /// </summary>
    _Null_terminated_ const char* ticketId;

} PFMatchmakingCreateServerBackfillTicketResult;

/// <summary>
/// PFMatchmakingCreateServerMatchmakingTicketRequest data model. The server specifies all the members
/// and their attributes.
/// </summary>
typedef struct PFMatchmakingCreateServerMatchmakingTicketRequest
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
    /// How long to attempt matching this ticket in seconds.
    /// </summary>
    int32_t giveUpAfterSeconds;

    /// <summary>
    /// The users who will be part of this ticket.
    /// </summary>
    _Field_size_(membersCount) PFMatchmakingMatchmakingPlayer const* const* members;

    /// <summary>
    /// Count of members
    /// </summary>
    uint32_t membersCount;

    /// <summary>
    /// The Id of a match queue.
    /// </summary>
    _Null_terminated_ const char* queueName;

} PFMatchmakingCreateServerMatchmakingTicketRequest;

/// <summary>
/// PFMatchmakingGetMatchRequest data model. When matchmaking has successfully matched together a collection
/// of tickets, it produces a 'match' with an Id. The match contains all of the players that were matched
/// together, and their team assigments. Only servers and ticket members can get the match.
/// </summary>
typedef struct PFMatchmakingGetMatchRequest
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
    /// Determines whether the matchmaking attributes will be returned as an escaped JSON string or as
    /// an un-escaped JSON object.
    /// </summary>
    bool escapeObject;

    /// <summary>
    /// The Id of a match.
    /// </summary>
    _Null_terminated_ const char* matchId;

    /// <summary>
    /// The name of the queue to join.
    /// </summary>
    _Null_terminated_ const char* queueName;

    /// <summary>
    /// Determines whether the matchmaking attributes for each user should be returned in the response
    /// for match request.
    /// </summary>
    bool returnMemberAttributes;

} PFMatchmakingGetMatchRequest;

/// <summary>
/// PFMatchmakingGetMatchResult data model.
/// </summary>
typedef struct PFMatchmakingGetMatchResult
{
    /// <summary>
    /// (Optional) A string that is used by players that are matched together to join an arranged lobby.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* arrangementString;

    /// <summary>
    /// The Id of a match.
    /// </summary>
    _Null_terminated_ const char* matchId;

    /// <summary>
    /// A list of Users that are matched together, along with their team assignments.
    /// </summary>
    _Field_size_(membersCount) PFMatchmakingMatchmakingPlayerWithTeamAssignment const* const* members;

    /// <summary>
    /// Count of members
    /// </summary>
    uint32_t membersCount;

    /// <summary>
    /// (Optional) A list of regions that the match could be played in sorted by preference. This value
    /// is only set if the queue has a region selection rule.
    /// </summary>
    _Maybenull_ _Field_size_(regionPreferencesCount) const char* const* regionPreferences;

    /// <summary>
    /// Count of regionPreferences
    /// </summary>
    uint32_t regionPreferencesCount;

    /// <summary>
    /// (Optional) The details of the server that the match has been allocated to.
    /// </summary>
    _Maybenull_ PFMatchmakingServerDetails const* serverDetails;

} PFMatchmakingGetMatchResult;

/// <summary>
/// PFMatchmakingGetMatchmakingTicketRequest data model. The ticket includes the invited players, their
/// attributes if they have joined, the ticket status, the match Id when applicable, etc. Only servers,
/// the ticket creator and the invited players can get the ticket.
/// </summary>
typedef struct PFMatchmakingGetMatchmakingTicketRequest
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
    /// Determines whether the matchmaking attributes will be returned as an escaped JSON string or as
    /// an un-escaped JSON object.
    /// </summary>
    bool escapeObject;

    /// <summary>
    /// The name of the queue to find a match for.
    /// </summary>
    _Null_terminated_ const char* queueName;

    /// <summary>
    /// The Id of the ticket to find a match for.
    /// </summary>
    _Null_terminated_ const char* ticketId;

} PFMatchmakingGetMatchmakingTicketRequest;

/// <summary>
/// PFMatchmakingGetMatchmakingTicketResult data model.
/// </summary>
typedef struct PFMatchmakingGetMatchmakingTicketResult
{
    /// <summary>
    /// (Optional) The reason why the current ticket was canceled. This field is only set if the ticket
    /// is in canceled state.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* cancellationReasonString;

    /// <summary>
    /// (Optional) Change number used for differentiating older matchmaking status updates from newer
    /// ones.
    /// </summary>
    _Maybenull_ uint32_t const* changeNumber;

    /// <summary>
    /// The server date and time at which ticket was created.
    /// </summary>
    time_t created;

    /// <summary>
    /// The Creator's entity key.
    /// </summary>
    PFEntityKey const* creator;

    /// <summary>
    /// How long to attempt matching this ticket in seconds.
    /// </summary>
    int32_t giveUpAfterSeconds;

    /// <summary>
    /// (Optional) The Id of a match.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* matchId;

    /// <summary>
    /// A list of Users that have joined this ticket.
    /// </summary>
    _Field_size_(membersCount) PFMatchmakingMatchmakingPlayer const* const* members;

    /// <summary>
    /// Count of members
    /// </summary>
    uint32_t membersCount;

    /// <summary>
    /// (Optional) A list of PlayFab Ids of Users to match with.
    /// </summary>
    _Maybenull_ _Field_size_(membersToMatchWithCount) PFEntityKey const* const* membersToMatchWith;

    /// <summary>
    /// Count of membersToMatchWith
    /// </summary>
    uint32_t membersToMatchWithCount;

    /// <summary>
    /// The Id of a match queue.
    /// </summary>
    _Null_terminated_ const char* queueName;

    /// <summary>
    /// The current ticket status. Possible values are: WaitingForPlayers, WaitingForMatch, WaitingForServer,
    /// Canceled and Matched.
    /// </summary>
    _Null_terminated_ const char* status;

    /// <summary>
    /// The Id of the ticket to find a match for.
    /// </summary>
    _Null_terminated_ const char* ticketId;

} PFMatchmakingGetMatchmakingTicketResult;

/// <summary>
/// PFMatchmakingGetQueueStatisticsRequest data model. Returns the matchmaking statistics for a queue.
/// These include the number of players matching and the statistics related to the time to match statistics
/// in seconds (average and percentiles). Statistics are refreshed once every 5 minutes. Servers can access
/// all statistics no matter what the ClientStatisticsVisibility is configured to. Clients can access
/// statistics according to the ClientStatisticsVisibility. Client requests are forbidden if all visibility
/// fields are false.
/// </summary>
typedef struct PFMatchmakingGetQueueStatisticsRequest
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
    /// The name of the queue.
    /// </summary>
    _Null_terminated_ const char* queueName;

} PFMatchmakingGetQueueStatisticsRequest;

/// <summary>
/// PFMatchmakingStatistics data model.
/// </summary>
typedef struct PFMatchmakingStatistics
{
    /// <summary>
    /// The average.
    /// </summary>
    double average;

    /// <summary>
    /// The 50th percentile.
    /// </summary>
    double percentile50;

    /// <summary>
    /// The 90th percentile.
    /// </summary>
    double percentile90;

    /// <summary>
    /// The 99th percentile.
    /// </summary>
    double percentile99;

} PFMatchmakingStatistics;

/// <summary>
/// PFMatchmakingGetQueueStatisticsResult data model.
/// </summary>
typedef struct PFMatchmakingGetQueueStatisticsResult
{
    /// <summary>
    /// (Optional) The current number of players in the matchmaking queue, who are waiting to be matched.
    /// </summary>
    _Maybenull_ uint32_t const* numberOfPlayersMatching;

    /// <summary>
    /// (Optional) Statistics representing the time (in seconds) it takes for tickets to find a match.
    /// </summary>
    _Maybenull_ PFMatchmakingStatistics const* timeToMatchStatisticsInSeconds;

} PFMatchmakingGetQueueStatisticsResult;

/// <summary>
/// PFMatchmakingGetServerBackfillTicketRequest data model. The ticket includes the players, their attributes,
/// their teams, the ticket status, the match Id and the server details when applicable, etc. Only servers
/// can get the ticket.
/// </summary>
typedef struct PFMatchmakingGetServerBackfillTicketRequest
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
    /// Determines whether the matchmaking attributes will be returned as an escaped JSON string or as
    /// an un-escaped JSON object.
    /// </summary>
    bool escapeObject;

    /// <summary>
    /// The name of the queue to find a match for.
    /// </summary>
    _Null_terminated_ const char* queueName;

    /// <summary>
    /// The Id of the ticket to find a match for.
    /// </summary>
    _Null_terminated_ const char* ticketId;

} PFMatchmakingGetServerBackfillTicketRequest;

/// <summary>
/// PFMatchmakingGetServerBackfillTicketResult data model.
/// </summary>
typedef struct PFMatchmakingGetServerBackfillTicketResult
{
    /// <summary>
    /// (Optional) The reason why the current ticket was canceled. This field is only set if the ticket
    /// is in canceled state.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* cancellationReasonString;

    /// <summary>
    /// The server date and time at which ticket was created.
    /// </summary>
    time_t created;

    /// <summary>
    /// How long to attempt matching this ticket in seconds.
    /// </summary>
    int32_t giveUpAfterSeconds;

    /// <summary>
    /// (Optional) The Id of a match.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* matchId;

    /// <summary>
    /// A list of Users that are part of this ticket, along with their team assignments.
    /// </summary>
    _Field_size_(membersCount) PFMatchmakingMatchmakingPlayerWithTeamAssignment const* const* members;

    /// <summary>
    /// Count of members
    /// </summary>
    uint32_t membersCount;

    /// <summary>
    /// The Id of a match queue.
    /// </summary>
    _Null_terminated_ const char* queueName;

    /// <summary>
    /// The details of the server the members are connected to.
    /// </summary>
    PFMatchmakingServerDetails const* serverDetails;

    /// <summary>
    /// The current ticket status. Possible values are: WaitingForMatch, Canceled and Matched.
    /// </summary>
    _Null_terminated_ const char* status;

    /// <summary>
    /// The Id of the ticket to find a match for.
    /// </summary>
    _Null_terminated_ const char* ticketId;

} PFMatchmakingGetServerBackfillTicketResult;

/// <summary>
/// PFMatchmakingJoinMatchmakingTicketRequest data model. Add the player to a matchmaking ticket and
/// specify all of its matchmaking attributes. Players can join a ticket if and only if their EntityKeys
/// are already listed in the ticket's Members list. The matchmaking service automatically starts matching
/// the ticket against other matchmaking tickets once all players have joined the ticket. It is not possible
/// to join a ticket once it has started matching.
/// </summary>
typedef struct PFMatchmakingJoinMatchmakingTicketRequest
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
    /// The User who wants to join the ticket. Their Id must be listed in PlayFabIdsToMatchWith.
    /// </summary>
    PFMatchmakingMatchmakingPlayer const* member;

    /// <summary>
    /// The name of the queue to join.
    /// </summary>
    _Null_terminated_ const char* queueName;

    /// <summary>
    /// The Id of the ticket to find a match for.
    /// </summary>
    _Null_terminated_ const char* ticketId;

} PFMatchmakingJoinMatchmakingTicketRequest;

/// <summary>
/// PFMatchmakingListMatchmakingTicketsForPlayerRequest data model. If the caller is a title, the EntityKey
/// in the request is required. If the caller is a player, then it is optional. If it is provided it must
/// match the caller's entity.
/// </summary>
typedef struct PFMatchmakingListMatchmakingTicketsForPlayerRequest
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
    /// (Optional) The entity key for which to find the ticket Ids.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// The name of the queue to find a match for.
    /// </summary>
    _Null_terminated_ const char* queueName;

} PFMatchmakingListMatchmakingTicketsForPlayerRequest;

/// <summary>
/// PFMatchmakingListMatchmakingTicketsForPlayerResult data model.
/// </summary>
typedef struct PFMatchmakingListMatchmakingTicketsForPlayerResult
{
    /// <summary>
    /// The list of ticket Ids the user is a member of.
    /// </summary>
    _Field_size_(ticketIdsCount) const char* const* ticketIds;

    /// <summary>
    /// Count of ticketIds
    /// </summary>
    uint32_t ticketIdsCount;

} PFMatchmakingListMatchmakingTicketsForPlayerResult;

/// <summary>
/// PFMatchmakingListServerBackfillTicketsForPlayerRequest data model. List all server backfill ticket
/// Ids the user is a member of.
/// </summary>
typedef struct PFMatchmakingListServerBackfillTicketsForPlayerRequest
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
    /// The entity key for which to find the ticket Ids.
    /// </summary>
    PFEntityKey const* entity;

    /// <summary>
    /// The name of the queue the tickets are in.
    /// </summary>
    _Null_terminated_ const char* queueName;

} PFMatchmakingListServerBackfillTicketsForPlayerRequest;

/// <summary>
/// PFMatchmakingListServerBackfillTicketsForPlayerResult data model.
/// </summary>
typedef struct PFMatchmakingListServerBackfillTicketsForPlayerResult
{
    /// <summary>
    /// The list of backfill ticket Ids the user is a member of.
    /// </summary>
    _Field_size_(ticketIdsCount) const char* const* ticketIds;

    /// <summary>
    /// Count of ticketIds
    /// </summary>
    uint32_t ticketIdsCount;

} PFMatchmakingListServerBackfillTicketsForPlayerResult;

#pragma pop_macro("IN")

}
