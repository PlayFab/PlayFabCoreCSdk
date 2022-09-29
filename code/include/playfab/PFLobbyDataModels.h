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
/// AccessPolicy enum.
/// </summary>
enum class PFLobbyAccessPolicy : uint32_t
{
    Public,
    Friends,
    Private
};

/// <summary>
/// OwnerMigrationPolicy enum.
/// </summary>
enum class PFLobbyOwnerMigrationPolicy : uint32_t
{
    None,
    Automatic,
    Manual,
    Server
};

/// <summary>
/// MembershipLock enum.
/// </summary>
enum class PFLobbyMembershipLock : uint32_t
{
    Unlocked,
    Locked
};

/// <summary>
/// SubscriptionType enum.
/// </summary>
enum class PFLobbySubscriptionType : uint32_t
{
    LobbyChange,
    LobbyInvite
};

/// <summary>
/// PFLobbyMember data model.
/// </summary>
typedef struct PFLobbyMember
{
    /// <summary>
    /// (Optional) Key-value pairs specific to member.
    /// </summary>
    _Maybenull_ _Field_size_(memberDataCount) struct PFStringDictionaryEntry const* memberData;

    /// <summary>
    /// Count of memberData
    /// </summary>
    uint32_t memberDataCount;

    /// <summary>
    /// (Optional) The member entity key.
    /// </summary>
    _Maybenull_ PFEntityKey const* memberEntity;

    /// <summary>
    /// (Optional) Opaque string, stored on a Subscribe call, which indicates the connection an owner
    /// or member has with PubSub.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* pubSubConnectionHandle;

} PFLobbyMember;

/// <summary>
/// PFLobbyCreateLobbyRequest data model. Request to create a lobby. A Server or client can create a
/// lobby.
/// </summary>
typedef struct PFLobbyCreateLobbyRequest
{
    /// <summary>
    /// (Optional) The policy indicating who is allowed to join the lobby, and the visibility to queries.
    /// May be 'Public', 'Friends' or 'Private'. Public means the lobby is both visible in queries and
    /// any player may join, including invited players. Friends means that users who are bidirectional
    /// friends of members in the lobby may search to find friend lobbies, to retrieve its connection
    /// string. Private means the lobby is not visible in queries, and a player must receive an invitation
    /// to join. Defaults to 'Public' on creation. Can only be changed by the lobby owner.
    /// </summary>
    _Maybenull_ PFLobbyAccessPolicy const* accessPolicy;

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
    /// (Optional) The private key-value pairs which are only visible to members of the lobby. At most
    /// 30 key-value pairs may be stored here, keys are limited to 30 characters and values to 1000. The
    /// total size of all lobbyData values may not exceed 4096 bytes. Keys are case sensitive.
    /// </summary>
    _Maybenull_ _Field_size_(lobbyDataCount) struct PFStringDictionaryEntry const* lobbyData;

    /// <summary>
    /// Count of lobbyData
    /// </summary>
    uint32_t lobbyDataCount;

    /// <summary>
    /// The maximum number of players allowed in the lobby. The value must be between 2 and 128.
    /// </summary>
    uint32_t maxPlayers;

    /// <summary>
    /// (Optional) The member initially added to the lobby. Client must specify exactly one member, which
    /// is the creator's entity and member data. Member PubSubConnectionHandle must be null or empty.
    /// Game servers must not specify any members.
    /// </summary>
    _Maybenull_ _Field_size_(membersCount) PFLobbyMember const* const* members;

    /// <summary>
    /// Count of members
    /// </summary>
    uint32_t membersCount;

    /// <summary>
    /// The lobby owner. Must be the calling entity.
    /// </summary>
    PFEntityKey const* owner;

    /// <summary>
    /// (Optional) The policy for how a new owner is chosen. May be 'Automatic', 'Manual' or 'None'.
    /// Can only be specified by clients. If client-owned and 'Automatic' - The Lobby service will automatically
    /// assign another connected owner when the current owner leaves or disconnects. The useConnections
    /// property must be true. If client - owned and 'Manual' - Ownership is protected as long as the
    /// current owner is connected. If the current owner leaves or disconnects any member may set themselves
    /// as the current owner. The useConnections property must be true. If client-owned and 'None' - Any
    /// member can set ownership. The useConnections property can be either true or false.
    /// </summary>
    _Maybenull_ PFLobbyOwnerMigrationPolicy const* ownerMigrationPolicy;

    /// <summary>
    /// (Optional) The public key-value pairs which allow queries to differentiate between lobbies. Queries
    /// will refer to these key-value pairs in their filter and order by clauses to retrieve lobbies fitting
    /// the specified criteria. At most 30 key-value pairs may be stored here. Keys are of the format
    /// string_key1, string_key2 ... string_key30 for string values, or number_key1, number_key2, ...
    /// number_key30 for numeric values.Numeric values are floats. Values can be at most 256 characters
    /// long. The total size of all searchData values may not exceed 1024 bytes.
    /// </summary>
    _Maybenull_ _Field_size_(searchDataCount) struct PFStringDictionaryEntry const* searchData;

    /// <summary>
    /// Count of searchData
    /// </summary>
    uint32_t searchDataCount;

    /// <summary>
    /// A setting to control whether connections are used. Defaults to true. When true, notifications
    /// are sent to subscribed players, disconnect detection removes connectionHandles, only owner migration
    /// policies using connections are allowed, and lobbies must have at least one connected member to
    /// be searchable or be a server hosted lobby with a connected server. If false, then notifications
    /// are not sent, connections are not allowed, and lobbies do not need connections to be searchable.
    /// </summary>
    bool useConnections;

} PFLobbyCreateLobbyRequest;

/// <summary>
/// PFLobbyCreateLobbyResult data model.
/// </summary>
typedef struct PFLobbyCreateLobbyResult
{
    /// <summary>
    /// A field which indicates which lobby the user will be joining.
    /// </summary>
    _Null_terminated_ const char* connectionString;

    /// <summary>
    /// Id to uniquely identify a lobby.
    /// </summary>
    _Null_terminated_ const char* lobbyId;

} PFLobbyCreateLobbyResult;

/// <summary>
/// PFLobbyDeleteLobbyRequest data model. Request to delete a lobby. Only servers can delete lobbies.
/// </summary>
typedef struct PFLobbyDeleteLobbyRequest
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
    /// (Optional) The id of the lobby.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* lobbyId;

} PFLobbyDeleteLobbyRequest;

/// <summary>
/// PFLobbyPaginationRequest data model.
/// </summary>
typedef struct PFLobbyPaginationRequest
{
    /// <summary>
    /// (Optional) Continuation token returned as a result in a previous FindLobbies call. Cannot be
    /// specified by clients.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* continuationToken;

    /// <summary>
    /// (Optional) The number of lobbies that should be retrieved. Cannot be specified by servers, clients
    /// may specify any value up to 50.
    /// </summary>
    _Maybenull_ uint32_t const* pageSizeRequested;

} PFLobbyPaginationRequest;

/// <summary>
/// PFLobbyFindFriendLobbiesRequest data model. Request to find friends lobbies. Only a client can find
/// friend lobbies.
/// </summary>
typedef struct PFLobbyFindFriendLobbiesRequest
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
    /// Controls whether this query should link to friends made on the Facebook network. Defaults to
    /// false.
    /// </summary>
    bool excludeFacebookFriends;

    /// <summary>
    /// Controls whether this query should link to friends made on the Steam network. Defaults to false.
    /// </summary>
    bool excludeSteamFriends;

    /// <summary>
    /// (Optional) OData style string that contains one or more filters. Only the following operators
    /// are supported: "and" (logical and), "eq" (equal), "ne" (not equals), "ge" (greater than or equal),
    /// "gt" (greater than), "le" (less than or equal), and "lt" (less than). The left-hand side of each
    /// OData logical expression should be either a search property key (e.g. string_key1, number_key3,
    /// etc) or one of the pre-defined search keys all of which must be prefixed by "lobby/": lobby/memberCount
    /// (number of players in a lobby), lobby/maxMemberCount (maximum number of players allowed in a lobby),
    /// lobby/membershipLock (must equal 'Unlocked' or 'Locked'), lobby/amOwner (required to equal "true"),
    /// lobby/amMember (required to equal "true").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* filter;

    /// <summary>
    /// (Optional) OData style string that contains sorting for this query in either ascending ("asc")
    /// or descending ("desc") order. OrderBy clauses are of the form "number_key1 asc" or the pre-defined
    /// search key "lobby/memberCount asc" and "lobby/maxMemberCount desc". To sort by closest, a moniker
    /// `distance{number_key1 = 5}` can be used to sort by distance from the given number. This field
    /// only supports either one sort clause or one distance clause.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* orderBy;

    /// <summary>
    /// (Optional) Request pagination information.
    /// </summary>
    _Maybenull_ PFLobbyPaginationRequest const* pagination;

    /// <summary>
    /// (Optional) Xbox token if Xbox friends should be included. Requires Xbox be configured on PlayFab.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* xboxToken;

} PFLobbyFindFriendLobbiesRequest;

/// <summary>
/// PFLobbyFriendLobbySummary data model.
/// </summary>
typedef struct PFLobbyFriendLobbySummary
{
    /// <summary>
    /// A string used to join the lobby.This field is populated by the Lobby service.Invites are performed
    /// by communicating this connectionString to other players.
    /// </summary>
    _Null_terminated_ const char* connectionString;

    /// <summary>
    /// The current number of players in the lobby.
    /// </summary>
    uint32_t currentPlayers;

    /// <summary>
    /// (Optional) Friends in Lobby.
    /// </summary>
    _Maybenull_ _Field_size_(friendsCount) PFEntityKey const* const* friends;

    /// <summary>
    /// Count of friends
    /// </summary>
    uint32_t friendsCount;

    /// <summary>
    /// Id to uniquely identify a lobby.
    /// </summary>
    _Null_terminated_ const char* lobbyId;

    /// <summary>
    /// The maximum number of players allowed in the lobby.
    /// </summary>
    uint32_t maxPlayers;

    /// <summary>
    /// (Optional) A setting indicating whether members are allowed to join this lobby. When Locked new
    /// members are prevented from joining.
    /// </summary>
    _Maybenull_ PFLobbyMembershipLock const* membershipLock;

    /// <summary>
    /// The client or server entity which owns this lobby.
    /// </summary>
    PFEntityKey const* owner;

    /// <summary>
    /// (Optional) Search data.
    /// </summary>
    _Maybenull_ _Field_size_(searchDataCount) struct PFStringDictionaryEntry const* searchData;

    /// <summary>
    /// Count of searchData
    /// </summary>
    uint32_t searchDataCount;

} PFLobbyFriendLobbySummary;

/// <summary>
/// PFLobbyPaginationResponse data model.
/// </summary>
typedef struct PFLobbyPaginationResponse
{
    /// <summary>
    /// (Optional) Continuation token returned by server call. Not returned for clients.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* continuationToken;

    /// <summary>
    /// (Optional) The number of lobbies that matched the search request.
    /// </summary>
    _Maybenull_ uint32_t const* totalMatchedLobbyCount;

} PFLobbyPaginationResponse;

/// <summary>
/// PFLobbyFindFriendLobbiesResult data model.
/// </summary>
typedef struct PFLobbyFindFriendLobbiesResult
{
    /// <summary>
    /// Array of lobbies found that matched FindFriendLobbies request.
    /// </summary>
    _Field_size_(lobbiesCount) PFLobbyFriendLobbySummary const* const* lobbies;

    /// <summary>
    /// Count of lobbies
    /// </summary>
    uint32_t lobbiesCount;

    /// <summary>
    /// Pagination response for FindFriendLobbies request.
    /// </summary>
    PFLobbyPaginationResponse const* pagination;

} PFLobbyFindFriendLobbiesResult;

/// <summary>
/// PFLobbyFindLobbiesRequest data model. Request to find lobbies.
/// </summary>
typedef struct PFLobbyFindLobbiesRequest
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
    /// (Optional) OData style string that contains one or more filters. Only the following operators
    /// are supported: "and" (logical and), "eq" (equal), "ne" (not equals), "ge" (greater than or equal),
    /// "gt" (greater than), "le" (less than or equal), and "lt" (less than). The left-hand side of each
    /// OData logical expression should be either a search property key (e.g. string_key1, number_key3,
    /// etc) or one of the pre-defined search keys all of which must be prefixed by "lobby/": lobby/memberCount
    /// (number of players in a lobby), lobby/maxMemberCount (maximum number of players allowed in a lobby),
    /// lobby/membershipLock (must equal 'Unlocked' or 'Locked'), lobby/amOwner (required to equal "true"),
    /// lobby/amMember (required to equal "true").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* filter;

    /// <summary>
    /// (Optional) OData style string that contains sorting for this query in either ascending ("asc")
    /// or descending ("desc") order. OrderBy clauses are of the form "number_key1 asc" or the pre-defined
    /// search key "lobby/memberCount asc" and "lobby/maxMemberCount desc". To sort by closest, a moniker
    /// `distance{number_key1 = 5}` can be used to sort by distance from the given number. This field
    /// only supports either one sort clause or one distance clause.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* orderBy;

    /// <summary>
    /// (Optional) Request pagination information.
    /// </summary>
    _Maybenull_ PFLobbyPaginationRequest const* pagination;

} PFLobbyFindLobbiesRequest;

/// <summary>
/// PFLobbyLobbySummary data model.
/// </summary>
typedef struct PFLobbyLobbySummary
{
    /// <summary>
    /// A string used to join the lobby.This field is populated by the Lobby service.Invites are performed
    /// by communicating this connectionString to other players.
    /// </summary>
    _Null_terminated_ const char* connectionString;

    /// <summary>
    /// The current number of players in the lobby.
    /// </summary>
    uint32_t currentPlayers;

    /// <summary>
    /// Id to uniquely identify a lobby.
    /// </summary>
    _Null_terminated_ const char* lobbyId;

    /// <summary>
    /// The maximum number of players allowed in the lobby.
    /// </summary>
    uint32_t maxPlayers;

    /// <summary>
    /// (Optional) A setting indicating whether members are allowed to join this lobby. When Locked new
    /// members are prevented from joining.
    /// </summary>
    _Maybenull_ PFLobbyMembershipLock const* membershipLock;

    /// <summary>
    /// The client or server entity which owns this lobby.
    /// </summary>
    PFEntityKey const* owner;

    /// <summary>
    /// (Optional) Search data.
    /// </summary>
    _Maybenull_ _Field_size_(searchDataCount) struct PFStringDictionaryEntry const* searchData;

    /// <summary>
    /// Count of searchData
    /// </summary>
    uint32_t searchDataCount;

} PFLobbyLobbySummary;

/// <summary>
/// PFLobbyFindLobbiesResult data model.
/// </summary>
typedef struct PFLobbyFindLobbiesResult
{
    /// <summary>
    /// Array of lobbies found that matched FindLobbies request.
    /// </summary>
    _Field_size_(lobbiesCount) PFLobbyLobbySummary const* const* lobbies;

    /// <summary>
    /// Count of lobbies
    /// </summary>
    uint32_t lobbiesCount;

    /// <summary>
    /// Pagination response for FindLobbies request.
    /// </summary>
    PFLobbyPaginationResponse const* pagination;

} PFLobbyFindLobbiesResult;

/// <summary>
/// PFLobbyGetLobbyRequest data model. Request to get a lobby.
/// </summary>
typedef struct PFLobbyGetLobbyRequest
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
    /// (Optional) The id of the lobby.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* lobbyId;

} PFLobbyGetLobbyRequest;

/// <summary>
/// PFLobbyLobby data model.
/// </summary>
typedef struct PFLobbyLobby
{
    /// <summary>
    /// A setting indicating who is allowed to join this lobby, as well as see it in queries.
    /// </summary>
    PFLobbyAccessPolicy accessPolicy;

    /// <summary>
    /// A number that increments once for each request that modifies the lobby.
    /// </summary>
    uint32_t changeNumber;

    /// <summary>
    /// A string used to join the lobby. This field is populated by the Lobby service. Invites are performed
    /// by communicating this connectionString to other players.
    /// </summary>
    _Null_terminated_ const char* connectionString;

    /// <summary>
    /// (Optional) Lobby data.
    /// </summary>
    _Maybenull_ _Field_size_(lobbyDataCount) struct PFStringDictionaryEntry const* lobbyData;

    /// <summary>
    /// Count of lobbyData
    /// </summary>
    uint32_t lobbyDataCount;

    /// <summary>
    /// Id to uniquely identify a lobby.
    /// </summary>
    _Null_terminated_ const char* lobbyId;

    /// <summary>
    /// The maximum number of players allowed in the lobby.
    /// </summary>
    uint32_t maxPlayers;

    /// <summary>
    /// (Optional) Array of all lobby members.
    /// </summary>
    _Maybenull_ _Field_size_(membersCount) PFLobbyMember const* const* members;

    /// <summary>
    /// Count of members
    /// </summary>
    uint32_t membersCount;

    /// <summary>
    /// A setting indicating whether members are allowed to join this lobby. When Locked new members
    /// are prevented from joining.
    /// </summary>
    PFLobbyMembershipLock membershipLock;

    /// <summary>
    /// (Optional) The client or server entity which owns this lobby.
    /// </summary>
    _Maybenull_ PFEntityKey const* owner;

    /// <summary>
    /// (Optional) A setting indicating the owner migration policy. If server owned, this field is not
    /// present.
    /// </summary>
    _Maybenull_ PFLobbyOwnerMigrationPolicy const* ownerMigrationPolicy;

    /// <summary>
    /// (Optional) An opaque string stored on a SubscribeToLobbyResource call, which indicates the connection
    /// an owner or member has with PubSub.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* pubSubConnectionHandle;

    /// <summary>
    /// (Optional) Search data.
    /// </summary>
    _Maybenull_ _Field_size_(searchDataCount) struct PFStringDictionaryEntry const* searchData;

    /// <summary>
    /// Count of searchData
    /// </summary>
    uint32_t searchDataCount;

    /// <summary>
    /// A flag which determines if connections are used. Defaults to true. Only set on create.
    /// </summary>
    bool useConnections;

} PFLobbyLobby;

/// <summary>
/// PFLobbyGetLobbyResult data model.
/// </summary>
typedef struct PFLobbyGetLobbyResult
{
    /// <summary>
    /// The information pertaining to the requested lobby.
    /// </summary>
    PFLobbyLobby const* lobby;

} PFLobbyGetLobbyResult;

/// <summary>
/// PFLobbyInviteToLobbyRequest data model. Request to invite a player to a lobby the caller is already
/// a member of. Only a client can invite another player to a lobby.
/// </summary>
typedef struct PFLobbyInviteToLobbyRequest
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
    /// (Optional) The entity invited to the lobby.
    /// </summary>
    _Maybenull_ PFEntityKey const* inviteeEntity;

    /// <summary>
    /// (Optional) The id of the lobby.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* lobbyId;

    /// <summary>
    /// (Optional) The member entity sending the invite. Must be a member of the lobby.
    /// </summary>
    _Maybenull_ PFEntityKey const* memberEntity;

} PFLobbyInviteToLobbyRequest;

/// <summary>
/// PFLobbyJoinArrangedLobbyRequest data model. Request to join an arranged lobby. Only a client can
/// join an arranged lobby.
/// </summary>
typedef struct PFLobbyJoinArrangedLobbyRequest
{
    /// <summary>
    /// (Optional) The policy indicating who is allowed to join the lobby, and the visibility to queries.
    /// May be 'Public', 'Friends' or 'Private'. Public means the lobby is both visible in queries and
    /// any player may join, including invited players. Friends means that users who are bidirectional
    /// friends of members in the lobby may search to find friend lobbies, to retrieve its connection
    /// string. Private means the lobby is not visible in queries, and a player must receive an invitation
    /// to join. Defaults to 'Public' on creation. Can only be changed by the lobby owner.
    /// </summary>
    _Maybenull_ PFLobbyAccessPolicy const* accessPolicy;

    /// <summary>
    /// A field which indicates which lobby the user will be joining. This field is opaque to everyone
    /// except the Lobby service and the creator of the arrangementString (Matchmaking). This string defines
    /// a unique identifier for the arranged lobby as well as the title and member the string is valid
    /// for. Arrangement strings have an expiration.
    /// </summary>
    _Null_terminated_ const char* arrangementString;

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
    /// The maximum number of players allowed in the lobby. The value must be between 2 and 128.
    /// </summary>
    uint32_t maxPlayers;

    /// <summary>
    /// (Optional) The private key-value pairs used by the member to communicate information to other
    /// members and the owner. Visible to all members of the lobby. At most 30 key-value pairs may be
    /// stored here, keys are limited to 30 characters and values to 1000. The total size of all memberData
    /// values may not exceed 4096 bytes. Keys are case sensitive.
    /// </summary>
    _Maybenull_ _Field_size_(memberDataCount) struct PFStringDictionaryEntry const* memberData;

    /// <summary>
    /// Count of memberData
    /// </summary>
    uint32_t memberDataCount;

    /// <summary>
    /// The member entity who is joining the lobby. The first member to join will be the lobby owner.
    /// </summary>
    PFEntityKey const* memberEntity;

    /// <summary>
    /// (Optional) The policy for how a new owner is chosen. May be 'Automatic', 'Manual' or 'None'.
    /// Can only be specified by clients. If client-owned and 'Automatic' - The Lobby service will automatically
    /// assign another connected owner when the current owner leaves or disconnects. The useConnections
    /// property must be true. If client - owned and 'Manual' - Ownership is protected as long as the
    /// current owner is connected. If the current owner leaves or disconnects any member may set themselves
    /// as the current owner. The useConnections property must be true. If client-owned and 'None' - Any
    /// member can set ownership. The useConnections property can be either true or false.
    /// </summary>
    _Maybenull_ PFLobbyOwnerMigrationPolicy const* ownerMigrationPolicy;

    /// <summary>
    /// A setting to control whether connections are used. Defaults to true. When true, notifications
    /// are sent to subscribed players, disconnect detection removes connectionHandles, only owner migration
    /// policies using connections are allowed, and lobbies must have at least one connected member to
    /// be searchable or be a server hosted lobby with a connected server. If false, then notifications
    /// are not sent, connections are not allowed, and lobbies do not need connections to be searchable.
    /// </summary>
    bool useConnections;

} PFLobbyJoinArrangedLobbyRequest;

/// <summary>
/// PFLobbyJoinLobbyResult data model.
/// </summary>
typedef struct PFLobbyJoinLobbyResult
{
    /// <summary>
    /// Successfully joined lobby's id.
    /// </summary>
    _Null_terminated_ const char* lobbyId;

} PFLobbyJoinLobbyResult;

/// <summary>
/// PFLobbyJoinLobbyRequest data model. Request to join a lobby. Only a client can join a lobby.
/// </summary>
typedef struct PFLobbyJoinLobbyRequest
{
    /// <summary>
    /// (Optional) A field which indicates which lobby the user will be joining. This field is opaque
    /// to everyone except the Lobby service.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* connectionString;

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
    /// (Optional) The private key-value pairs used by the member to communicate information to other
    /// members and the owner. Visible to all members of the lobby. At most 30 key-value pairs may be
    /// stored here, keys are limited to 30 characters and values to 1000. The total size of all memberData
    /// values may not exceed 4096 bytes.Keys are case sensitive.
    /// </summary>
    _Maybenull_ _Field_size_(memberDataCount) struct PFStringDictionaryEntry const* memberData;

    /// <summary>
    /// Count of memberData
    /// </summary>
    uint32_t memberDataCount;

    /// <summary>
    /// (Optional) The member entity who is joining the lobby.
    /// </summary>
    _Maybenull_ PFEntityKey const* memberEntity;

} PFLobbyJoinLobbyRequest;

/// <summary>
/// PFLobbyLeaveLobbyRequest data model. Request to leave a lobby. Only a client can leave a lobby.
/// </summary>
typedef struct PFLobbyLeaveLobbyRequest
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
    /// (Optional) The id of the lobby.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* lobbyId;

    /// <summary>
    /// (Optional) The member entity leaving the lobby.
    /// </summary>
    _Maybenull_ PFEntityKey const* memberEntity;

} PFLobbyLeaveLobbyRequest;

/// <summary>
/// PFLobbyRemoveMemberFromLobbyRequest data model. Request to remove a member from a lobby. Owners may
/// remove other members from a lobby. Members cannot remove themselves (use LeaveLobby instead).
/// </summary>
typedef struct PFLobbyRemoveMemberFromLobbyRequest
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
    /// (Optional) The id of the lobby.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* lobbyId;

    /// <summary>
    /// (Optional) The member entity to be removed from the lobby.
    /// </summary>
    _Maybenull_ PFEntityKey const* memberEntity;

    /// <summary>
    /// If true, removed member can never rejoin this lobby.
    /// </summary>
    bool preventRejoin;

} PFLobbyRemoveMemberFromLobbyRequest;

/// <summary>
/// PFLobbySubscribeToLobbyResourceRequest data model. Request to subscribe to lobby resource notifications.
/// </summary>
typedef struct PFLobbySubscribeToLobbyResourceRequest
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
    /// The entity performing the subscription.
    /// </summary>
    PFEntityKey const* entityKey;

    /// <summary>
    /// Opaque string, given to a client upon creating a connection with PubSub.
    /// </summary>
    _Null_terminated_ const char* pubSubConnectionHandle;

    /// <summary>
    /// The name of the resource to subscribe to.
    /// </summary>
    _Null_terminated_ const char* resourceId;

    /// <summary>
    /// Version number for the subscription of this resource.
    /// </summary>
    uint32_t subscriptionVersion;

    /// <summary>
    /// Subscription type.
    /// </summary>
    PFLobbySubscriptionType type;

} PFLobbySubscribeToLobbyResourceRequest;

/// <summary>
/// PFLobbySubscribeToLobbyResourceResult data model.
/// </summary>
typedef struct PFLobbySubscribeToLobbyResourceResult
{
    /// <summary>
    /// Topic will be returned in all notifications that are the result of this subscription.
    /// </summary>
    _Null_terminated_ const char* topic;

} PFLobbySubscribeToLobbyResourceResult;

/// <summary>
/// PFLobbyUnsubscribeFromLobbyResourceRequest data model. Request to unsubscribe from lobby notifications.
/// </summary>
typedef struct PFLobbyUnsubscribeFromLobbyResourceRequest
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
    /// The entity which performed the subscription.
    /// </summary>
    PFEntityKey const* entityKey;

    /// <summary>
    /// Opaque string, given to a client upon creating a connection with PubSub.
    /// </summary>
    _Null_terminated_ const char* pubSubConnectionHandle;

    /// <summary>
    /// The name of the resource to unsubscribe from.
    /// </summary>
    _Null_terminated_ const char* resourceId;

    /// <summary>
    /// Version number passed for the subscription of this resource.
    /// </summary>
    uint32_t subscriptionVersion;

    /// <summary>
    /// Subscription type.
    /// </summary>
    PFLobbySubscriptionType type;

} PFLobbyUnsubscribeFromLobbyResourceRequest;

/// <summary>
/// PFLobbyUpdateLobbyRequest data model. Request to update a lobby.
/// </summary>
typedef struct PFLobbyUpdateLobbyRequest
{
    /// <summary>
    /// (Optional) The policy indicating who is allowed to join the lobby, and the visibility to queries.
    /// May be 'Public', 'Friends' or 'Private'. Public means the lobby is both visible in queries and
    /// any player may join, including invited players. Friends means that users who are bidirectional
    /// friends of members in the lobby may search to find friend lobbies, to retrieve its connection
    /// string. Private means the lobby is not visible in queries, and a player must receive an invitation
    /// to join. Defaults to 'Public' on creation. Can only be changed by the lobby owner.
    /// </summary>
    _Maybenull_ PFLobbyAccessPolicy const* accessPolicy;

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
    /// (Optional) The private key-value pairs which are only visible to members of the lobby. Optional.
    /// Sets or updates key-value pairs on the lobby. Only the current lobby owner can set lobby data.
    /// Keys may be an arbitrary string of at most 30 characters. The total size of all lobbyData values
    /// may not exceed 4096 bytes. Values are not individually limited. There can be up to 30 key-value
    /// pairs stored here. Keys are case sensitive.
    /// </summary>
    _Maybenull_ _Field_size_(lobbyDataCount) struct PFStringDictionaryEntry const* lobbyData;

    /// <summary>
    /// Count of lobbyData
    /// </summary>
    uint32_t lobbyDataCount;

    /// <summary>
    /// (Optional) The keys to delete from the lobby LobbyData. Optional. Behaves similar to searchDataToDelete,
    /// but applies to lobbyData.
    /// </summary>
    _Maybenull_ _Field_size_(lobbyDataToDeleteCount) const char* const* lobbyDataToDelete;

    /// <summary>
    /// Count of lobbyDataToDelete
    /// </summary>
    uint32_t lobbyDataToDeleteCount;

    /// <summary>
    /// (Optional) The id of the lobby.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* lobbyId;

    /// <summary>
    /// (Optional) The maximum number of players allowed in the lobby. Updates the maximum allowed number
    /// of players in the lobby. Only the current lobby owner can set this. If set, the value must be
    /// greater than or equal to the number of members currently in the lobby.
    /// </summary>
    _Maybenull_ uint32_t const* maxPlayers;

    /// <summary>
    /// (Optional) The private key-value pairs used by the member to communicate information to other
    /// members and the owner. Optional. Sets or updates new key-value pairs on the caller's member data.
    /// New keys will be added with their values and existing keys will be updated with the new values.
    /// Visible to all members of the lobby. At most 30 key-value pairs may be stored here, keys are limited
    /// to 30 characters and values to 1000. The total size of all memberData values may not exceed 4096
    /// bytes. Keys are case sensitive. Servers cannot specifiy this.
    /// </summary>
    _Maybenull_ _Field_size_(memberDataCount) struct PFStringDictionaryEntry const* memberData;

    /// <summary>
    /// Count of memberData
    /// </summary>
    uint32_t memberDataCount;

    /// <summary>
    /// (Optional) The keys to delete from the lobby MemberData. Optional. Deletes key-value pairs on
    /// the caller's member data. All the specified keys will be removed from the caller's member data.
    /// Keys that do not exist are a no-op. If the key to delete exists in the memberData (same request)
    /// it will result in a bad request. Servers cannot specifiy this.
    /// </summary>
    _Maybenull_ _Field_size_(memberDataToDeleteCount) const char* const* memberDataToDelete;

    /// <summary>
    /// Count of memberDataToDelete
    /// </summary>
    uint32_t memberDataToDeleteCount;

    /// <summary>
    /// (Optional) The member entity whose data is being modified. Servers cannot specify this.
    /// </summary>
    _Maybenull_ PFEntityKey const* memberEntity;

    /// <summary>
    /// (Optional) A setting indicating whether the lobby is locked. May be 'Unlocked' or 'Locked'. When
    /// Locked new members are not allowed to join. Defaults to 'Unlocked' on creation. Can only be changed
    /// by the lobby owner.
    /// </summary>
    _Maybenull_ PFLobbyMembershipLock const* membershipLock;

    /// <summary>
    /// (Optional) The lobby owner. Optional. Set to transfer ownership of the lobby. If client - owned
    /// and 'Automatic' - The Lobby service will automatically assign another connected owner when the
    /// current owner leaves or disconnects. useConnections must be true. If client - owned and 'Manual'
    /// - Ownership is protected as long as the current owner is connected. If the current owner leaves
    /// or disconnects any member may set themselves as the current owner. The useConnections property
    /// must be true. If client-owned and 'None' - Any member can set ownership. The useConnections property
    /// can be either true or false. For all client-owned lobbies when the owner leaves and a new owner
    /// can not be automatically selected - The owner field is set to null. For all client-owned lobbies
    /// when the owner disconnects and a new owner can not be automatically selected - The owner field
    /// remains unchanged and the current owner retains all owner abilities for the lobby. If server-owned
    /// (must be 'Server') - Any server can set ownership. The useConnections property must be true.
    /// </summary>
    _Maybenull_ PFEntityKey const* owner;

    /// <summary>
    /// (Optional) The public key-value pairs which allow queries to differentiate between lobbies. Optional.
    /// Sets or updates key-value pairs on the lobby for use with queries. Only the current lobby owner
    /// can set search data. New keys will be added with their values and existing keys will be updated
    /// with the new values. There can be up to 30 key-value pairs stored here. Keys are of the format
    /// string_key1, string_key2... string_key30 for string values, or number_key1, number_key2, ... number_key30
    /// for numeric values. Numeric values are floats. Values can be at most 256 characters long. The
    /// total size of all searchData values may not exceed 1024 bytes.Keys are case sensitive.
    /// </summary>
    _Maybenull_ _Field_size_(searchDataCount) struct PFStringDictionaryEntry const* searchData;

    /// <summary>
    /// Count of searchData
    /// </summary>
    uint32_t searchDataCount;

    /// <summary>
    /// (Optional) The keys to delete from the lobby SearchData. Optional. Deletes key-value pairs on
    /// the lobby. Only the current lobby owner can delete search data. All the specified keys will be
    /// removed from the search data. Keys that do not exist in the lobby are a no-op.If the key to delete
    /// exists in the searchData (same request) it will result in a bad request.
    /// </summary>
    _Maybenull_ _Field_size_(searchDataToDeleteCount) const char* const* searchDataToDelete;

    /// <summary>
    /// Count of searchDataToDelete
    /// </summary>
    uint32_t searchDataToDeleteCount;

} PFLobbyUpdateLobbyRequest;

#pragma pop_macro("IN")

}
