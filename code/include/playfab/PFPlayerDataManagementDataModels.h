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
