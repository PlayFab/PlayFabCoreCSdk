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
/// PFAnalyticsDeviceInfoRequest data model. Any arbitrary information collected by the device.
/// </summary>
typedef struct PFAnalyticsDeviceInfoRequest
{
    /// <summary>
    /// (Optional) Information posted to the PlayStream Event. Currently arbitrary, and specific to the
    /// environment sending it.
    /// </summary>
    PFJsonObject info;

} PFAnalyticsDeviceInfoRequest;

/// <summary>
/// PFAnalyticsWriteClientCharacterEventRequest data model. This API is designed to write a multitude
/// of different client-defined events into PlayStream. It supports a flexible JSON schema, which allowsfor
/// arbitrary key-value pairs to describe any character-based event. The created event will be locked
/// to the authenticated title and player. .
/// </summary>
typedef struct PFAnalyticsWriteClientCharacterEventRequest
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

} PFAnalyticsWriteClientCharacterEventRequest;

/// <summary>
/// PFAnalyticsWriteEventResponse data model.
/// </summary>
typedef struct PFAnalyticsWriteEventResponse
{
    /// <summary>
    /// (Optional) The unique identifier of the event. The values of this identifier consist of ASCII
    /// characters and are not constrained to any particular format.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* eventId;

} PFAnalyticsWriteEventResponse;

/// <summary>
/// PFAnalyticsWriteClientPlayerEventRequest data model. This API is designed to write a multitude of
/// different event types into PlayStream. It supports a flexible JSON schema, which allowsfor arbitrary
/// key-value pairs to describe any player-based event. The created event will be locked to the authenticated
/// title and player. .
/// </summary>
typedef struct PFAnalyticsWriteClientPlayerEventRequest
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

} PFAnalyticsWriteClientPlayerEventRequest;

/// <summary>
/// PFAnalyticsWriteTitleEventRequest data model. This API is designed to write a multitude of different
/// client-defined events into PlayStream. It supports a flexible JSON schema, which allowsfor arbitrary
/// key-value pairs to describe any title-based event. The created event will be locked to the authenticated
/// title. .
/// </summary>
typedef struct PFAnalyticsWriteTitleEventRequest
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

} PFAnalyticsWriteTitleEventRequest;

/// <summary>
/// PFAnalyticsWriteServerCharacterEventRequest data model. This API is designed to write a multitude
/// of different event types into PlayStream. It supports a flexible JSON schema, which allowsfor arbitrary
/// key-value pairs to describe any character-based event. The created event will be locked to the authenticated
/// title. .
/// </summary>
typedef struct PFAnalyticsWriteServerCharacterEventRequest
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

} PFAnalyticsWriteServerCharacterEventRequest;

/// <summary>
/// PFAnalyticsWriteServerPlayerEventRequest data model. This API is designed to write a multitude of
/// different event types into PlayStream. It supports a flexible JSON schema, which allowsfor arbitrary
/// key-value pairs to describe any player-based event. The created event will be locked to the authenticated
/// title. .
/// </summary>
typedef struct PFAnalyticsWriteServerPlayerEventRequest
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

} PFAnalyticsWriteServerPlayerEventRequest;

/// <summary>
/// PFAnalyticsInsightsEmptyRequest data model.
/// </summary>
typedef struct PFAnalyticsInsightsEmptyRequest
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

} PFAnalyticsInsightsEmptyRequest;

/// <summary>
/// PFAnalyticsInsightsPerformanceLevel data model.
/// </summary>
typedef struct PFAnalyticsInsightsPerformanceLevel
{
    /// <summary>
    /// Number of allowed active event exports.
    /// </summary>
    int32_t activeEventExports;

    /// <summary>
    /// Maximum cache size.
    /// </summary>
    int32_t cacheSizeMB;

    /// <summary>
    /// Maximum number of concurrent queries.
    /// </summary>
    int32_t concurrency;

    /// <summary>
    /// Number of Insights credits consumed per minute.
    /// </summary>
    double creditsPerMinute;

    /// <summary>
    /// Maximum events per second.
    /// </summary>
    int32_t eventsPerSecond;

    /// <summary>
    /// Performance level.
    /// </summary>
    int32_t level;

    /// <summary>
    /// Maximum amount of memory allowed per query.
    /// </summary>
    int32_t maxMemoryPerQueryMB;

    /// <summary>
    /// Amount of compute power allocated for queries and operations.
    /// </summary>
    int32_t virtualCpuCores;

} PFAnalyticsInsightsPerformanceLevel;

/// <summary>
/// PFAnalyticsInsightsGetLimitsResponse data model.
/// </summary>
typedef struct PFAnalyticsInsightsGetLimitsResponse
{
    /// <summary>
    /// Default Insights performance level.
    /// </summary>
    int32_t defaultPerformanceLevel;

    /// <summary>
    /// Default Insights data storage retention days.
    /// </summary>
    int32_t defaultStorageRetentionDays;

    /// <summary>
    /// Maximum allowed data storage retention days.
    /// </summary>
    int32_t storageMaxRetentionDays;

    /// <summary>
    /// Minimum allowed data storage retention days.
    /// </summary>
    int32_t storageMinRetentionDays;

    /// <summary>
    /// (Optional) List of Insights submeter limits for the allowed performance levels.
    /// </summary>
    _Maybenull_ _Field_size_(subMetersCount) PFAnalyticsInsightsPerformanceLevel const* const* subMeters;

    /// <summary>
    /// Count of subMeters
    /// </summary>
    uint32_t subMetersCount;

} PFAnalyticsInsightsGetLimitsResponse;

/// <summary>
/// PFAnalyticsInsightsGetOperationStatusResponse data model.
/// </summary>
typedef struct PFAnalyticsInsightsGetOperationStatusResponse
{
    /// <summary>
    /// (Optional) Optional message related to the operation details.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* message;

    /// <summary>
    /// Time the operation was completed.
    /// </summary>
    time_t operationCompletedTime;

    /// <summary>
    /// (Optional) Id of the Insights operation.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* operationId;

    /// <summary>
    /// Time the operation status was last updated.
    /// </summary>
    time_t operationLastUpdated;

    /// <summary>
    /// Time the operation started.
    /// </summary>
    time_t operationStartedTime;

    /// <summary>
    /// (Optional) The type of operation, SetPerformance or SetStorageRetention.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* operationType;

    /// <summary>
    /// The value requested for the operation.
    /// </summary>
    int32_t operationValue;

    /// <summary>
    /// (Optional) Current status of the operation.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* status;

} PFAnalyticsInsightsGetOperationStatusResponse;

/// <summary>
/// PFAnalyticsInsightsGetDetailsResponse data model.
/// </summary>
typedef struct PFAnalyticsInsightsGetDetailsResponse
{
    /// <summary>
    /// Amount of data (in MB) currently used by Insights.
    /// </summary>
    uint32_t dataUsageMb;

    /// <summary>
    /// (Optional) Details of any error that occurred while retrieving Insights details.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* errorMessage;

    /// <summary>
    /// (Optional) Allowed range of values for performance level and data storage retention.
    /// </summary>
    _Maybenull_ PFAnalyticsInsightsGetLimitsResponse const* limits;

    /// <summary>
    /// (Optional) List of pending Insights operations for the title.
    /// </summary>
    _Maybenull_ _Field_size_(pendingOperationsCount) PFAnalyticsInsightsGetOperationStatusResponse const* const* pendingOperations;

    /// <summary>
    /// Count of pendingOperations
    /// </summary>
    uint32_t pendingOperationsCount;

    /// <summary>
    /// Current Insights performance level setting.
    /// </summary>
    int32_t performanceLevel;

    /// <summary>
    /// Current Insights data storage retention value in days.
    /// </summary>
    int32_t retentionDays;

} PFAnalyticsInsightsGetDetailsResponse;

/// <summary>
/// PFAnalyticsInsightsGetOperationStatusRequest data model. Returns the current status for the requested
/// operation id.
/// </summary>
typedef struct PFAnalyticsInsightsGetOperationStatusRequest
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
    /// (Optional) Id of the Insights operation.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* operationId;

} PFAnalyticsInsightsGetOperationStatusRequest;

/// <summary>
/// PFAnalyticsInsightsGetPendingOperationsRequest data model. Returns a list of operations that are
/// in the pending state for the requested operation type.
/// </summary>
typedef struct PFAnalyticsInsightsGetPendingOperationsRequest
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
    /// (Optional) The type of pending operations requested, or blank for all operation types.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* operationType;

} PFAnalyticsInsightsGetPendingOperationsRequest;

/// <summary>
/// PFAnalyticsInsightsGetPendingOperationsResponse data model.
/// </summary>
typedef struct PFAnalyticsInsightsGetPendingOperationsResponse
{
    /// <summary>
    /// (Optional) List of pending Insights operations.
    /// </summary>
    _Maybenull_ _Field_size_(pendingOperationsCount) PFAnalyticsInsightsGetOperationStatusResponse const* const* pendingOperations;

    /// <summary>
    /// Count of pendingOperations
    /// </summary>
    uint32_t pendingOperationsCount;

} PFAnalyticsInsightsGetPendingOperationsResponse;

/// <summary>
/// PFAnalyticsInsightsSetPerformanceRequest data model. Sets the performance level to the requested
/// value. Use the GetLimits method to get the allowed values.
/// </summary>
typedef struct PFAnalyticsInsightsSetPerformanceRequest
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
    /// The Insights performance level to apply to the title.
    /// </summary>
    int32_t performanceLevel;

} PFAnalyticsInsightsSetPerformanceRequest;

/// <summary>
/// PFAnalyticsInsightsOperationResponse data model.
/// </summary>
typedef struct PFAnalyticsInsightsOperationResponse
{
    /// <summary>
    /// (Optional) Optional message related to the operation details.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* message;

    /// <summary>
    /// (Optional) Id of the Insights operation.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* operationId;

    /// <summary>
    /// (Optional) The type of operation, SetPerformance or SetStorageRetention.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* operationType;

} PFAnalyticsInsightsOperationResponse;

/// <summary>
/// PFAnalyticsInsightsSetStorageRetentionRequest data model. Sets the data storage retention to the
/// requested value. Use the GetLimits method to get the range of allowed values.
/// </summary>
typedef struct PFAnalyticsInsightsSetStorageRetentionRequest
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
    /// The Insights data storage retention value (in days) to apply to the title.
    /// </summary>
    int32_t retentionDays;

} PFAnalyticsInsightsSetStorageRetentionRequest;

#pragma pop_macro("IN")

}
