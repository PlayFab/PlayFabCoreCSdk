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
/// PFEventsAddPlayerTagRequest data model. This API will trigger a player_tag_added event and add a
/// tag with the given TagName and PlayFabID to the corresponding player profile. TagName can be used
/// for segmentation and it is limited to 256 characters. Also there is a limit on the number of tags
/// a title can have.
/// </summary>
typedef struct PFEventsAddPlayerTagRequest
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
    /// Unique tag for player profile.
    /// </summary>
    _Null_terminated_ const char* tagName;

} PFEventsAddPlayerTagRequest;

/// <summary>
/// PFEventsGetPlayerTagsRequest data model. This API will return a list of canonical tags which includes
/// both namespace and tag's name. If namespace is not provided, the result is a list of all canonical
/// tags. TagName can be used for segmentation and Namespace is limited to 128 characters.
/// </summary>
typedef struct PFEventsGetPlayerTagsRequest
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
    /// (Optional) Optional namespace to filter results by.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playfabNamespace;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

} PFEventsGetPlayerTagsRequest;

/// <summary>
/// PFEventsGetPlayerTagsResult data model.
/// </summary>
typedef struct PFEventsGetPlayerTagsResult
{
    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// Canonical tags (including namespace and tag's name) for the requested user.
    /// </summary>
    _Field_size_(tagsCount) const char* const* tags;

    /// <summary>
    /// Count of tags
    /// </summary>
    uint32_t tagsCount;

} PFEventsGetPlayerTagsResult;

/// <summary>
/// PFEventsRemovePlayerTagRequest data model. This API will trigger a player_tag_removed event and remove
/// a tag with the given TagName and PlayFabID from the corresponding player profile. TagName can be used
/// for segmentation and it is limited to 256 characters.
/// </summary>
typedef struct PFEventsRemovePlayerTagRequest
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
    /// Unique tag for player profile.
    /// </summary>
    _Null_terminated_ const char* tagName;

} PFEventsRemovePlayerTagRequest;

/// <summary>
/// PFEventsWriteClientCharacterEventRequest data model. This API is designed to write a multitude of
/// different client-defined events into PlayStream. It supports a flexible JSON schema, which allowsfor
/// arbitrary key-value pairs to describe any character-based event. The created event will be locked
/// to the authenticated title and player. .
/// </summary>
typedef struct PFEventsWriteClientCharacterEventRequest
{
    /// <summary>
    /// (Optional) Custom event properties. Each property consists of a name (string) and a value (JSON
    /// object).
    /// </summary>
    PFJsonObject body;

    /// <summary>
    /// Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Null_terminated_ const char* characterId;

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
    /// The name of the event, within the namespace scoped to the title. The naming convention is up
    /// to the caller, but it commonly follows the subject_verb_object pattern (e.g. player_logged_in).
    /// </summary>
    _Null_terminated_ const char* eventName;

    /// <summary>
    /// (Optional) The time (in UTC) associated with this event. The value defaults to the current time.
    /// </summary>
    _Maybenull_ time_t const* timestamp;

} PFEventsWriteClientCharacterEventRequest;

/// <summary>
/// PFEventsWriteEventResponse data model.
/// </summary>
typedef struct PFEventsWriteEventResponse
{
    /// <summary>
    /// (Optional) The unique identifier of the event. The values of this identifier consist of ASCII
    /// characters and are not constrained to any particular format.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* eventId;

} PFEventsWriteEventResponse;

/// <summary>
/// PFEventsWriteClientPlayerEventRequest data model. This API is designed to write a multitude of different
/// event types into PlayStream. It supports a flexible JSON schema, which allowsfor arbitrary key-value
/// pairs to describe any player-based event. The created event will be locked to the authenticated title
/// and player. .
/// </summary>
typedef struct PFEventsWriteClientPlayerEventRequest
{
    /// <summary>
    /// (Optional) Custom data properties associated with the event. Each property consists of a name
    /// (string) and a value (JSON object).
    /// </summary>
    PFJsonObject body;

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
    /// The name of the event, within the namespace scoped to the title. The naming convention is up
    /// to the caller, but it commonly follows the subject_verb_object pattern (e.g. player_logged_in).
    /// </summary>
    _Null_terminated_ const char* eventName;

    /// <summary>
    /// (Optional) The time (in UTC) associated with this event. The value defaults to the current time.
    /// </summary>
    _Maybenull_ time_t const* timestamp;

} PFEventsWriteClientPlayerEventRequest;

/// <summary>
/// PFEventsWriteTitleEventRequest data model. This API is designed to write a multitude of different
/// client-defined events into PlayStream. It supports a flexible JSON schema, which allowsfor arbitrary
/// key-value pairs to describe any title-based event. The created event will be locked to the authenticated
/// title. .
/// </summary>
typedef struct PFEventsWriteTitleEventRequest
{
    /// <summary>
    /// (Optional) Custom event properties. Each property consists of a name (string) and a value (JSON
    /// object).
    /// </summary>
    PFJsonObject body;

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
    /// The name of the event, within the namespace scoped to the title. The naming convention is up
    /// to the caller, but it commonly follows the subject_verb_object pattern (e.g. player_logged_in).
    /// </summary>
    _Null_terminated_ const char* eventName;

    /// <summary>
    /// (Optional) The time (in UTC) associated with this event. The value defaults to the current time.
    /// </summary>
    _Maybenull_ time_t const* timestamp;

} PFEventsWriteTitleEventRequest;

/// <summary>
/// PFEventsWriteServerCharacterEventRequest data model. This API is designed to write a multitude of
/// different event types into PlayStream. It supports a flexible JSON schema, which allowsfor arbitrary
/// key-value pairs to describe any character-based event. The created event will be locked to the authenticated
/// title. .
/// </summary>
typedef struct PFEventsWriteServerCharacterEventRequest
{
    /// <summary>
    /// (Optional) Custom event properties. Each property consists of a name (string) and a value (JSON
    /// object).
    /// </summary>
    PFJsonObject body;

    /// <summary>
    /// Unique PlayFab assigned ID for a specific character owned by a user.
    /// </summary>
    _Null_terminated_ const char* characterId;

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
    /// The name of the event, within the namespace scoped to the title. The naming convention is up
    /// to the caller, but it commonly follows the subject_verb_object pattern (e.g. player_logged_in).
    /// </summary>
    _Null_terminated_ const char* eventName;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) The time (in UTC) associated with this event. The value defaults to the current time.
    /// </summary>
    _Maybenull_ time_t const* timestamp;

} PFEventsWriteServerCharacterEventRequest;

/// <summary>
/// PFEventsWriteServerPlayerEventRequest data model. This API is designed to write a multitude of different
/// event types into PlayStream. It supports a flexible JSON schema, which allowsfor arbitrary key-value
/// pairs to describe any player-based event. The created event will be locked to the authenticated title.
/// .
/// </summary>
typedef struct PFEventsWriteServerPlayerEventRequest
{
    /// <summary>
    /// (Optional) Custom data properties associated with the event. Each property consists of a name
    /// (string) and a value (JSON object).
    /// </summary>
    PFJsonObject body;

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
    /// The name of the event, within the namespace scoped to the title. The naming convention is up
    /// to the caller, but it commonly follows the subject_verb_object pattern (e.g. player_logged_in).
    /// </summary>
    _Null_terminated_ const char* eventName;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// (Optional) The time (in UTC) associated with this event. The value defaults to the current time.
    /// </summary>
    _Maybenull_ time_t const* timestamp;

} PFEventsWriteServerPlayerEventRequest;

/// <summary>
/// PFEventsEventContents data model.
/// </summary>
typedef struct PFEventsEventContents
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the event (e.g. build number, external trace
    /// identifiers, etc.). Before an event is written, this collection and the base request custom tags
    /// will be merged, but not overriden. This enables the caller to specify static tags and per event
    /// tags.
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) Entity associated with the event. If null, the event will apply to the calling entity.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// The namespace in which the event is defined. Allowed namespaces can vary by API.
    /// </summary>
    _Null_terminated_ const char* eventNamespace;

    /// <summary>
    /// The name of this event.
    /// </summary>
    _Null_terminated_ const char* name;

    /// <summary>
    /// (Optional) The original unique identifier associated with this event before it was posted to
    /// PlayFab. The value might differ from the EventId value, which is assigned when the event is received
    /// by the server.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* originalId;

    /// <summary>
    /// (Optional) The time (in UTC) associated with this event when it occurred. If specified, this
    /// value is stored in the OriginalTimestamp property of the PlayStream event.
    /// </summary>
    _Maybenull_ time_t const* originalTimestamp;

    /// <summary>
    /// (Optional) Arbitrary data associated with the event. Only one of Payload or PayloadJSON is allowed.
    /// </summary>
    PFJsonObject payload;

    /// <summary>
    /// (Optional) Arbitrary data associated with the event, represented as a JSON serialized string.
    /// Only one of Payload or PayloadJSON is allowed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* payloadJSON;

} PFEventsEventContents;

/// <summary>
/// PFEventsWriteEventsRequest data model.
/// </summary>
typedef struct PFEventsWriteEventsRequest
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
    /// Collection of events to write to PlayStream.
    /// </summary>
    _Field_size_(eventsCount) PFEventsEventContents const* const* events;

    /// <summary>
    /// Count of events
    /// </summary>
    uint32_t eventsCount;

} PFEventsWriteEventsRequest;

/// <summary>
/// PFEventsWriteEventsResponse data model.
/// </summary>
typedef struct PFEventsWriteEventsResponse
{
    /// <summary>
    /// (Optional) The unique identifiers assigned by the server to the events, in the same order as
    /// the events in the request. Only returned if FlushToPlayStream option is true.
    /// </summary>
    _Maybenull_ _Field_size_(assignedEventIdsCount) const char* const* assignedEventIds;

    /// <summary>
    /// Count of assignedEventIds
    /// </summary>
    uint32_t assignedEventIdsCount;

} PFEventsWriteEventsResponse;

#pragma pop_macro("IN")

}
