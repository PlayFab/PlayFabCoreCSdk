// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFSharedDataModels.h>

#if HC_PLATFORM == HC_PLATFORM_GDK
#include <XUser.h>
#endif

extern "C"
{

#pragma push_macro("IN")
#undef IN

/// <summary>
/// AccountLinkAction enum.
/// </summary>
enum class PFAuthenticationAccountLinkAction : uint32_t
{
    CreateAndLinkNewAccount,
    LinkToExistingAccount,
    LeaveUnlinked
};

/// <summary>
/// PlayerIdentityProvider enum.
/// </summary>
enum class PFAuthenticationPlayerIdentityProvider : uint32_t
{
    AndroidDevice,
    Apple,
    CustomId,
    Email,
    FacebookInstantGames,
    GameCenter,
    Google,
    iOSDevice,
    Kongregate,
    NintendoSwitchDevice,
    NintendoAccount,
    OpenId,
    PSN,
    ServerCustomId,
    Steam,
    Twitch,
    Username,
    Xbox
};

/// <summary>
/// PFAuthenticationAuthenticateCustomIdIdentityRequest data model.
/// </summary>
typedef struct PFAuthenticationAuthenticateCustomIdIdentityRequest
{
    /// <summary>
    /// Controls what happens if the authenticated player identity is not yet associated with a master_player_account
    /// in the player account pool. 'CreateAndLinkNewAccount' (default) creates a new master_player_account
    /// entity and associates the player identity with it. 'LinkToExistingAccount' attempts to associate
    /// the player identity with the master_player_account entity specified by 'ExistingMasterPlayerAccountId',
    /// returning an 'AccountAlreadyLinked' error if the master_player_account is already associated with
    /// another player identity. 'LeaveUnlinked' leaves the player identity unlinked and returns the 'AccountNotFound'
    /// error.
    /// </summary>
    PFAuthenticationAccountLinkAction behaviorIfIdentityNotLinked;

    /// <summary>
    /// Custom string value which uniquely identifies a player identity within the player account pool.
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
    /// (Optional) Optional master_player_account entity in the player account pool to associate with
    /// the authenticated player identity. When specified, then the request must be authenticated as either
    /// the same master_player_account (with an entity token obtained from a previous authentication API
    /// call) or as another entity authorized to make calls on behalf of it, such as a title entity in
    /// the same player account pool (with a title secret key).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* existingMasterPlayerAccountId;

} PFAuthenticationAuthenticateCustomIdIdentityRequest;

/// <summary>
/// PFAuthenticationGetLinkedPlayerIdentitiesRequest data model.
/// </summary>
typedef struct PFAuthenticationGetLinkedPlayerIdentitiesRequest
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
    /// (Optional) Master_player_account entity.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* masterPlayerAccountId;

} PFAuthenticationGetLinkedPlayerIdentitiesRequest;

/// <summary>
/// PFAuthenticationLinkedPlayerIdentity data model.
/// </summary>
typedef struct PFAuthenticationLinkedPlayerIdentity
{
    /// <summary>
    /// (Optional) Unique identifier of the link between the player identity and master_player_account.Can
    /// be used to specify the link in requests to UnlinkPlayerIdentity.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* identityLinkId;

    /// <summary>
    /// The player identity provider in which the identity exists.
    /// </summary>
    PFAuthenticationPlayerIdentityProvider identityProvider;

    /// <summary>
    /// (Optional) The unique identifier of the player identity, as assigned by the player identity provider.
    /// The format varies by identity provider.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* identityProviderIssuedId;

} PFAuthenticationLinkedPlayerIdentity;

/// <summary>
/// PFAuthenticationGetLinkedPlayerIdentitiesResult data model.
/// </summary>
typedef struct PFAuthenticationGetLinkedPlayerIdentitiesResult
{
    /// <summary>
    /// (Optional) List of player identities currently linked to the master_player_account.
    /// </summary>
    _Maybenull_ _Field_size_(linkedIdentitiesCount) PFAuthenticationLinkedPlayerIdentity const* const* linkedIdentities;

    /// <summary>
    /// Count of linkedIdentities
    /// </summary>
    uint32_t linkedIdentitiesCount;

} PFAuthenticationGetLinkedPlayerIdentitiesResult;

/// <summary>
/// PFAuthenticationUnlinkPlayerIdentityRequest data model.
/// </summary>
typedef struct PFAuthenticationUnlinkPlayerIdentityRequest
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
    /// Unique identifier of the link between the player identity and master_player_account to be unlinked.
    /// If no matching player identity is currently linked to the master_player_account, then the 'AccountNotLinked'
    /// error is returned.
    /// </summary>
    _Null_terminated_ const char* identityLinkId;

    /// <summary>
    /// (Optional) Master_player_account entity.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* masterPlayerAccountId;

} PFAuthenticationUnlinkPlayerIdentityRequest;

#pragma pop_macro("IN")

}
