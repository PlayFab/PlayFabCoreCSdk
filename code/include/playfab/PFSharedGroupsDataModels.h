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
/// PFSharedGroupsAddSharedGroupMembersRequest data model.
/// </summary>
typedef struct PFSharedGroupsAddSharedGroupMembersRequest
{
    /// <summary>
    /// An array of unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Field_size_(playFabIdsCount) const char* const* playFabIds;

    /// <summary>
    /// Count of playFabIds
    /// </summary>
    uint32_t playFabIdsCount;

    /// <summary>
    /// Unique identifier for the shared group.
    /// </summary>
    _Null_terminated_ const char* sharedGroupId;

} PFSharedGroupsAddSharedGroupMembersRequest;

/// <summary>
/// PFSharedGroupsCreateSharedGroupRequest data model. If SharedGroupId is specified, the service will
/// attempt to create a group with that identifier, and will return an error if it is already in use.
/// If no SharedGroupId is specified, a random identifier will be assigned.
/// </summary>
typedef struct PFSharedGroupsCreateSharedGroupRequest
{
    /// <summary>
    /// (Optional) Unique identifier for the shared group (a random identifier will be assigned, if one
    /// is not specified).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* sharedGroupId;

} PFSharedGroupsCreateSharedGroupRequest;

/// <summary>
/// PFSharedGroupsCreateSharedGroupResult data model.
/// </summary>
typedef struct PFSharedGroupsCreateSharedGroupResult
{
    /// <summary>
    /// (Optional) Unique identifier for the shared group.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* sharedGroupId;

} PFSharedGroupsCreateSharedGroupResult;

/// <summary>
/// PFSharedGroupsGetSharedGroupDataRequest data model.
/// </summary>
typedef struct PFSharedGroupsGetSharedGroupDataRequest
{
    /// <summary>
    /// (Optional) If true, return the list of all members of the shared group.
    /// </summary>
    _Maybenull_ bool const* getMembers;

    /// <summary>
    /// (Optional) Specific keys to retrieve from the shared group (if not specified, all keys will be
    /// returned, while an empty array indicates that no keys should be returned).
    /// </summary>
    _Maybenull_ _Field_size_(keysCount) const char* const* keys;

    /// <summary>
    /// Count of keys
    /// </summary>
    uint32_t keysCount;

    /// <summary>
    /// Unique identifier for the shared group.
    /// </summary>
    _Null_terminated_ const char* sharedGroupId;

} PFSharedGroupsGetSharedGroupDataRequest;

/// <summary>
/// PFSharedGroupsSharedGroupDataRecord data model.
/// </summary>
typedef struct PFSharedGroupsSharedGroupDataRecord
{
    /// <summary>
    /// Timestamp for when this data was last updated.
    /// </summary>
    time_t lastUpdated;

    /// <summary>
    /// (Optional) Unique PlayFab identifier of the user to last update this value.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* lastUpdatedBy;

    /// <summary>
    /// (Optional) Indicates whether this data can be read by all users (public) or only members of the
    /// group (private).
    /// </summary>
    _Maybenull_ PFUserDataPermission const* permission;

    /// <summary>
    /// (Optional) Data stored for the specified group data key.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* value;

} PFSharedGroupsSharedGroupDataRecord;

/// <summary>
/// PFSharedGroupsGetSharedGroupDataResult data model.
/// </summary>
typedef struct PFSharedGroupsGetSharedGroupDataResult
{
    /// <summary>
    /// (Optional) Data for the requested keys.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) struct PFSharedGroupsSharedGroupDataRecordDictionaryEntry const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

    /// <summary>
    /// (Optional) List of PlayFabId identifiers for the members of this group, if requested.
    /// </summary>
    _Maybenull_ _Field_size_(membersCount) const char* const* members;

    /// <summary>
    /// Count of members
    /// </summary>
    uint32_t membersCount;

} PFSharedGroupsGetSharedGroupDataResult;

/// <summary>
/// PFSharedGroupsRemoveSharedGroupMembersRequest data model.
/// </summary>
typedef struct PFSharedGroupsRemoveSharedGroupMembersRequest
{
    /// <summary>
    /// An array of unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Field_size_(playFabIdsCount) const char* const* playFabIds;

    /// <summary>
    /// Count of playFabIds
    /// </summary>
    uint32_t playFabIdsCount;

    /// <summary>
    /// Unique identifier for the shared group.
    /// </summary>
    _Null_terminated_ const char* sharedGroupId;

} PFSharedGroupsRemoveSharedGroupMembersRequest;

/// <summary>
/// PFSharedGroupsUpdateSharedGroupDataRequest data model. Note that in the case of multiple calls to
/// write to the same shared group data keys, the last write received by the PlayFab service will determine
/// the value available to subsequent read operations. For scenarios requiring coordination of data updates,
/// it is recommended that titles make use of user data with read permission set to public, or a combination
/// of user data and shared group data.
/// </summary>
typedef struct PFSharedGroupsUpdateSharedGroupDataRequest
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
    /// (Optional) Permission to be applied to all user data keys in this request.
    /// </summary>
    _Maybenull_ PFUserDataPermission const* permission;

    /// <summary>
    /// Unique identifier for the shared group.
    /// </summary>
    _Null_terminated_ const char* sharedGroupId;

} PFSharedGroupsUpdateSharedGroupDataRequest;

/// <summary>
/// PFSharedGroupsDeleteSharedGroupRequest data model.
/// </summary>
typedef struct PFSharedGroupsDeleteSharedGroupRequest
{
    /// <summary>
    /// Unique identifier for the shared group.
    /// </summary>
    _Null_terminated_ const char* sharedGroupId;

} PFSharedGroupsDeleteSharedGroupRequest;

/// <summary>
/// Dictionary entry for an associative array with PFSharedGroupsSharedGroupDataRecord values.
/// </summary>
typedef struct PFSharedGroupsSharedGroupDataRecordDictionaryEntry
{
    _Null_terminated_ const char* key;
    PFSharedGroupsSharedGroupDataRecord const* value;
} PFSharedGroupsSharedGroupDataRecordDictionaryEntry;

#pragma pop_macro("IN")

}
