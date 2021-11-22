// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFPlayerDataManagementDataModels.h>
#include <playfab/PFGlobal.h>
#include <playfab/PFTitlePlayer.h>

extern "C"
{

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Adds a new player statistic configuration to the title, optionally allowing the developer to specify
/// a reset interval and an aggregation method.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Statistics are numeric values, with each statistic in the title also generating a leaderboard. The
/// ResetInterval enables automatically resetting leaderboards on a specified interval. Upon reset, the
/// statistic updates to a new version with no values (effectively removing all players from the leaderboard).
/// The previous version's statistic values are also archived for retrieval, if needed (see GetPlayerStatisticVersions).
/// Statistics not created via a call to CreatePlayerStatisticDefinition by default have a VersionChangeInterval
/// of Never, meaning they do not reset on a schedule, but they can be set to do so via a call to UpdatePlayerStatisticDefinition.
/// Once a statistic has been reset (sometimes referred to as versioned or incremented), the now-previous
/// version can still be written to for up a short, pre-defined period (currently 10 seconds), to prevent
/// issues with levels completing around the time of the reset. Also, once reset, the historical statistics
/// for players in the title may be retrieved using the URL specified in the version information (GetPlayerStatisticVersions).
/// The AggregationMethod determines what action is taken when a new statistic value is submitted - always
/// update with the new value (Last), use the highest of the old and new values (Max), use the smallest
/// (Min), or add them together (Sum). See also AdminGetPlayerStatisticDefinitionsAsync, ClientGetPlayerStatisticsAsync,
/// ServerGetPlayerStatisticsAsync, AdminGetPlayerStatisticVersionsAsync, AdminUpdatePlayerStatisticDefinitionAsync,
/// ClientUpdatePlayerStatisticsAsync, ServerUpdatePlayerStatisticsAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminCreatePlayerStatisticDefinitionGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminCreatePlayerStatisticDefinitionAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementCreatePlayerStatisticDefinitionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminCreatePlayerStatisticDefinition call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminCreatePlayerStatisticDefinitionGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminCreatePlayerStatisticDefinitionAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementAdminCreatePlayerStatisticDefinitionGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementCreatePlayerStatisticDefinitionResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves a download URL for the requested report
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Gets the download URL for the requested report data (in CSV form). The reports available through
/// this API call are those available in the Game Manager, in the Analytics->Reports tab.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminGetDataReportGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetDataReportAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementGetDataReportRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetDataReport call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminGetDataReportGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminGetDataReportAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetDataReportGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementGetDataReportResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the configuration information for all player statistics defined in the title, regardless
/// of whether they have a reset interval.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminCreatePlayerStatisticDefinitionAsync, ClientGetPlayerStatisticsAsync, ServerGetPlayerStatisticsAsync,
/// AdminUpdatePlayerStatisticDefinitionAsync, ClientUpdatePlayerStatisticsAsync, ServerUpdatePlayerStatisticsAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminGetPlayerStatisticDefinitionsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetPlayerStatisticDefinitionsAsync(
    _In_ PFStateHandle stateHandle,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetPlayerStatisticDefinitions call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminGetPlayerStatisticDefinitionsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminGetPlayerStatisticDefinitionsAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetPlayerStatisticDefinitionsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementGetPlayerStatisticDefinitionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the information on the available versions of the specified statistic.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminCreatePlayerStatisticDefinitionAsync, AdminGetPlayerStatisticDefinitionsAsync, ClientGetPlayerStatisticsAsync,
/// ServerGetPlayerStatisticsAsync, AdminUpdatePlayerStatisticDefinitionAsync, ClientUpdatePlayerStatisticsAsync,
/// ServerUpdatePlayerStatisticsAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminGetPlayerStatisticVersionsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetPlayerStatisticVersionsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementGetPlayerStatisticVersionsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetPlayerStatisticVersions call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminGetPlayerStatisticVersionsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminGetPlayerStatisticVersionsAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetPlayerStatisticVersionsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementGetPlayerStatisticVersionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the title-specific custom data for the user which is readable and writable by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom user
/// data will be returned. See also AdminGetUserInternalDataAsync, AdminGetUserReadOnlyDataAsync, AdminUpdateUserDataAsync,
/// AdminUpdateUserInternalDataAsync, AdminUpdateUserReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminGetUserDataGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetUserDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementGetUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetUserData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminGetUserDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminGetUserDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetUserDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementAdminGetUserDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the title-specific custom data for the user which cannot be accessed by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom user
/// data will be returned. See also AdminGetUserDataAsync, AdminGetUserReadOnlyDataAsync, AdminUpdateUserDataAsync,
/// AdminUpdateUserInternalDataAsync, AdminUpdateUserReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminGetUserInternalDataGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetUserInternalDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementGetUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetUserInternalData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminGetUserInternalDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminGetUserInternalDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetUserInternalDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementAdminGetUserDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the publisher-specific custom data for the user which is readable and writable by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom user
/// data will be returned. See also AdminGetUserPublisherInternalDataAsync, AdminGetUserPublisherReadOnlyDataAsync,
/// AdminUpdateUserPublisherDataAsync, AdminUpdateUserPublisherInternalDataAsync, AdminUpdateUserPublisherReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminGetUserPublisherDataGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetUserPublisherDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementGetUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetUserPublisherData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminGetUserPublisherDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminGetUserPublisherDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetUserPublisherDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementAdminGetUserDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the publisher-specific custom data for the user which cannot be accessed by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom user
/// data will be returned. See also AdminGetUserPublisherDataAsync, AdminGetUserPublisherReadOnlyDataAsync,
/// AdminUpdateUserPublisherDataAsync, AdminUpdateUserPublisherInternalDataAsync, AdminUpdateUserPublisherReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminGetUserPublisherInternalDataGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetUserPublisherInternalDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementGetUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetUserPublisherInternalData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminGetUserPublisherInternalDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminGetUserPublisherInternalDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetUserPublisherInternalDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementAdminGetUserDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the publisher-specific custom data for the user which can only be read by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom user
/// data will be returned. See also AdminGetUserPublisherDataAsync, AdminGetUserPublisherInternalDataAsync,
/// AdminUpdateUserPublisherDataAsync, AdminUpdateUserPublisherInternalDataAsync, AdminUpdateUserPublisherReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminGetUserPublisherReadOnlyDataGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetUserPublisherReadOnlyDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementGetUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetUserPublisherReadOnlyData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminGetUserPublisherReadOnlyDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminGetUserPublisherReadOnlyDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetUserPublisherReadOnlyDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementAdminGetUserDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the title-specific custom data for the user which can only be read by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom user
/// data will be returned. See also AdminGetUserDataAsync, AdminGetUserInternalDataAsync, AdminUpdateUserDataAsync,
/// AdminUpdateUserInternalDataAsync, AdminUpdateUserReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminGetUserReadOnlyDataGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetUserReadOnlyDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementGetUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetUserReadOnlyData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminGetUserReadOnlyDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminGetUserReadOnlyDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementAdminGetUserReadOnlyDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementAdminGetUserDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Resets the indicated statistic, removing all player entries for it and backing up the old values.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Statistics are numeric values, with each statistic in the title also generating a leaderboard. When
/// this call is made on a given statistic, this forces a reset of that statistic. Upon reset, the statistic
/// updates to a new version with no values (effectively removing all players from the leaderboard). The
/// previous version's statistic values are also archived for retrieval, if needed (see GetPlayerStatisticVersions).
/// Statistics not created via a call to CreatePlayerStatisticDefinition by default have a VersionChangeInterval
/// of Never, meaning they do not reset on a schedule, but they can be set to do so via a call to UpdatePlayerStatisticDefinition.
/// Once a statistic has been reset (sometimes referred to as versioned or incremented), the now-previous
/// version can still be written to for up a short, pre-defined period (currently 10 seconds), to prevent
/// issues with levels completing around the time of the reset. Also, once reset, the historical statistics
/// for players in the title may be retrieved using the URL specified in the version information (GetPlayerStatisticVersions).
/// See also AdminCreatePlayerStatisticDefinitionAsync, AdminGetPlayerStatisticDefinitionsAsync, ClientGetPlayerStatisticsAsync,
/// ServerGetPlayerStatisticsAsync, AdminGetPlayerStatisticVersionsAsync, AdminUpdatePlayerStatisticDefinitionAsync,
/// ClientUpdatePlayerStatisticsAsync, ServerUpdatePlayerStatisticsAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminIncrementPlayerStatisticVersionGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminIncrementPlayerStatisticVersionAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementIncrementPlayerStatisticVersionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminIncrementPlayerStatisticVersion call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminIncrementPlayerStatisticVersionGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminIncrementPlayerStatisticVersionAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementAdminIncrementPlayerStatisticVersionGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementIncrementPlayerStatisticVersionResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Attempts to process an order refund through the original real money payment provider.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFPlayerDataManagementAdminRefundPurchaseGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminRefundPurchaseAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementRefundPurchaseRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminRefundPurchase call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminRefundPurchaseGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminRefundPurchaseAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementAdminRefundPurchaseGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementRefundPurchaseResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Completely removes all statistics for the specified user, for the current game
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Note that this action cannot be un-done. All statistics for this user will be deleted, removing the
/// user from all leaderboards for the game.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFPlayerDataManagementAdminResetUserStatisticsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementResetUserStatisticsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Attempts to resolve a dispute with the original order's payment provider.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFPlayerDataManagementAdminResolvePurchaseDisputeGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminResolvePurchaseDisputeAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementResolvePurchaseDisputeRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminResolvePurchaseDispute call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminResolvePurchaseDisputeGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminResolvePurchaseDisputeAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementAdminResolvePurchaseDisputeGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementResolvePurchaseDisputeResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates a player statistic configuration for the title, optionally allowing the developer to specify
/// a reset interval.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Statistics are numeric values, with each statistic in the title also generating a leaderboard. The
/// ResetInterval enables automatically resetting leaderboards on a specified interval. Upon reset, the
/// statistic updates to a new version with no values (effectively removing all players from the leaderboard).
/// The previous version's statistic values are also archived for retrieval, if needed (see GetPlayerStatisticVersions).
/// Statistics not created via a call to CreatePlayerStatisticDefinition by default have a VersionChangeInterval
/// of Never, meaning they do not reset on a schedule, but they can be set to do so via a call to UpdatePlayerStatisticDefinition.
/// Once a statistic has been reset (sometimes referred to as versioned or incremented), the now-previous
/// version can still be written to for up a short, pre-defined period (currently 10 seconds), to prevent
/// issues with levels completing around the time of the reset. Also, once reset, the historical statistics
/// for players in the title may be retrieved using the URL specified in the version information (GetPlayerStatisticVersions).
/// The AggregationMethod determines what action is taken when a new statistic value is submitted - always
/// update with the new value (Last), use the highest of the old and new values (Max), use the smallest
/// (Min), or add them together (Sum). See also AdminCreatePlayerStatisticDefinitionAsync, AdminGetPlayerStatisticDefinitionsAsync,
/// ClientGetPlayerStatisticsAsync, ServerGetPlayerStatisticsAsync, AdminGetPlayerStatisticVersionsAsync,
/// ClientUpdatePlayerStatisticsAsync, ServerUpdatePlayerStatisticsAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminUpdatePlayerStatisticDefinitionGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminUpdatePlayerStatisticDefinitionAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminUpdatePlayerStatisticDefinition call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminUpdatePlayerStatisticDefinitionGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminUpdatePlayerStatisticDefinitionAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementAdminUpdatePlayerStatisticDefinitionGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the title-specific custom data for the user which is readable and writable by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary JSON object containing the custom data
/// for the user. In updating the custom data object, keys which already exist in the object will have
/// their values overwritten, while keys with null values will be removed. No other key-value pairs will
/// be changed apart from those specified in the call. See also AdminGetUserDataAsync, AdminGetUserInternalDataAsync,
/// AdminGetUserReadOnlyDataAsync, AdminUpdateUserInternalDataAsync, AdminUpdateUserReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminUpdateUserDataGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminUpdateUserDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementAdminUpdateUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminUpdateUserDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFPlayerDataManagementUpdateUserDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminUpdateUserDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFPlayerDataManagementUpdateUserDataResult* result
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the title-specific custom data for the user which cannot be accessed by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary JSON object containing the custom data
/// for the user. In updating the custom data object, keys which already exist in the object will have
/// their values overwritten, keys with null values will be removed. No other key-value pairs will be
/// changed apart from those specified in the call. See also AdminGetUserDataAsync, AdminGetUserInternalDataAsync,
/// AdminGetUserReadOnlyDataAsync, AdminUpdateUserDataAsync, AdminUpdateUserReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminUpdateUserInternalDataGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminUpdateUserInternalDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementUpdateUserInternalDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminUpdateUserInternalDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFPlayerDataManagementUpdateUserDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminUpdateUserInternalDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFPlayerDataManagementUpdateUserDataResult* result
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the publisher-specific custom data for the user which is readable and writable by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary JSON object containing the custom data
/// for the user. In updating the custom data object, keys which already exist in the object will have
/// their values overwritten, while keys with null values will be removed. No other key-value pairs will
/// be changed apart from those specified in the call. Note that in the example call provided, title-specific
/// data is used, as there may be a need to share this across titles (in sequels, for example). See also
/// AdminGetUserPublisherDataAsync, AdminGetUserPublisherInternalDataAsync, AdminGetUserPublisherReadOnlyDataAsync,
/// AdminUpdateUserPublisherInternalDataAsync, AdminUpdateUserPublisherReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminUpdateUserPublisherDataGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminUpdateUserPublisherDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementAdminUpdateUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminUpdateUserPublisherDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFPlayerDataManagementUpdateUserDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminUpdateUserPublisherDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFPlayerDataManagementUpdateUserDataResult* result
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the publisher-specific custom data for the user which cannot be accessed by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary JSON object containing the custom data
/// for the user. In updating the custom data object, keys which already exist in the object will have
/// their values overwritten, keys with null values will be removed. No other key-value pairs will be
/// changed apart from those specified in the call. Note that in the example call provided, title-specific
/// data is used, as there may be a need to share this across titles (in sequels, for example). See also
/// AdminGetUserPublisherDataAsync, AdminGetUserPublisherInternalDataAsync, AdminGetUserPublisherReadOnlyDataAsync,
/// AdminUpdateUserPublisherDataAsync, AdminUpdateUserPublisherReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminUpdateUserPublisherInternalDataGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminUpdateUserPublisherInternalDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementUpdateUserInternalDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminUpdateUserPublisherInternalDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFPlayerDataManagementUpdateUserDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminUpdateUserPublisherInternalDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFPlayerDataManagementUpdateUserDataResult* result
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the publisher-specific custom data for the user which can only be read by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary JSON object containing the custom data
/// for the user. In updating the custom data object, keys which already exist in the object will have
/// their values overwritten, keys with null values will be removed. No other key-value pairs will be
/// changed apart from those specified in the call. Note that in the example call provided, title-specific
/// data is used, as there may be a need to share this across titles (in sequels, for example). See also
/// AdminGetUserPublisherDataAsync, AdminGetUserPublisherInternalDataAsync, AdminGetUserPublisherReadOnlyDataAsync,
/// AdminUpdateUserPublisherDataAsync, AdminUpdateUserPublisherInternalDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminUpdateUserPublisherReadOnlyDataGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminUpdateUserPublisherReadOnlyDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementAdminUpdateUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminUpdateUserPublisherReadOnlyDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFPlayerDataManagementUpdateUserDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminUpdateUserPublisherReadOnlyDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFPlayerDataManagementUpdateUserDataResult* result
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the title-specific custom data for the user which can only be read by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary JSON object containing the custom data
/// for the user. In updating the custom data object, keys which already exist in the object will have
/// their values overwritten, keys with null values will be removed. No other key-value pairs will be
/// changed apart from those specified in the call. See also AdminGetUserDataAsync, AdminGetUserInternalDataAsync,
/// AdminGetUserReadOnlyDataAsync, AdminUpdateUserDataAsync, AdminUpdateUserInternalDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementAdminUpdateUserReadOnlyDataGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerDataManagementAdminUpdateUserReadOnlyDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementAdminUpdateUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementAdminUpdateUserReadOnlyDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFPlayerDataManagementUpdateUserDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementAdminUpdateUserReadOnlyDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFPlayerDataManagementUpdateUserDataResult* result
) noexcept;
#endif

/// <summary>
/// Retrieves a list of ranked friends of the current player for the given statistic, starting from the
/// indicated point in the leaderboard
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFPlayerDataManagementClientGetFriendLeaderboardGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetFriendLeaderboardAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerDataManagementClientGetFriendLeaderboardRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetFriendLeaderboard call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementClientGetFriendLeaderboardGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementClientGetFriendLeaderboardAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetFriendLeaderboardGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementGetLeaderboardResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves a list of ranked friends of the current player for the given statistic, centered on the
/// requested PlayFab user. If PlayFabId is empty or null will return currently logged in user.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFPlayerDataManagementClientGetFriendLeaderboardAroundPlayerGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetFriendLeaderboardAroundPlayerAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetFriendLeaderboardAroundPlayer call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementClientGetFriendLeaderboardAroundPlayerGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementClientGetFriendLeaderboardAroundPlayerAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetFriendLeaderboardAroundPlayerGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves a list of ranked users for the given statistic, starting from the indicated point in the
/// leaderboard
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientGetFriendLeaderboardAsync, ClientGetLeaderboardAroundPlayerAsync, ClientGetUserStatisticsAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementClientGetLeaderboardGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetLeaderboardAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerDataManagementGetLeaderboardRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetLeaderboard call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementClientGetLeaderboardGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementClientGetLeaderboardAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetLeaderboardGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementGetLeaderboardResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves a list of ranked users for the given statistic, centered on the requested player. If PlayFabId
/// is empty or null will return currently logged in user.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientGetFriendLeaderboardAsync, ClientGetLeaderboardAsync, ClientGetUserStatisticsAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementClientGetLeaderboardAroundPlayerGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetLeaderboardAroundPlayerAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerDataManagementGetLeaderboardAroundPlayerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetLeaderboardAroundPlayer call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementClientGetLeaderboardAroundPlayerGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementClientGetLeaderboardAroundPlayerAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetLeaderboardAroundPlayerGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementGetLeaderboardAroundPlayerResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the indicated statistics (current version and values for all statistics, if none are specified),
/// for the local player.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminCreatePlayerStatisticDefinitionAsync, ClientGetPlayerStatisticVersionsAsync, AdminUpdatePlayerStatisticDefinitionAsync,
/// ClientUpdatePlayerStatisticsAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementClientGetPlayerStatisticsGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetPlayerStatisticsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerDataManagementClientGetPlayerStatisticsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayerStatistics call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementClientGetPlayerStatisticsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementClientGetPlayerStatisticsAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetPlayerStatisticsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementClientGetPlayerStatisticsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the information on the available versions of the specified statistic.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFPlayerDataManagementClientGetPlayerStatisticVersionsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetPlayerStatisticVersionsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerDataManagementGetPlayerStatisticVersionsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayerStatisticVersions call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementClientGetPlayerStatisticVersionsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementClientGetPlayerStatisticVersionsAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetPlayerStatisticVersionsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementGetPlayerStatisticVersionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the title-specific custom data for the user which is readable and writable by the client
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. Every time the data is updated via any source, the version
/// counter is incremented. If the Version parameter is provided, then this call will only return data
/// if the current version on the system is greater than the value provided. If the Keys parameter is
/// provided, the data object returned will only contain the data specific to the indicated Keys. Otherwise,
/// the full set of custom user data will be returned. See also ClientGetUserReadOnlyDataAsync, ClientUpdateUserDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementClientGetUserDataGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetUserDataAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerDataManagementGetUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetUserData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementClientGetUserDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementClientGetUserDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetUserDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementClientGetUserDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the publisher-specific custom data for the user which is readable and writable by the client
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom user
/// data will be returned. See also ClientGetUserPublisherReadOnlyDataAsync, ClientUpdateUserPublisherDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementClientGetUserPublisherDataGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetUserPublisherDataAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerDataManagementGetUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetUserPublisherData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementClientGetUserPublisherDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementClientGetUserPublisherDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetUserPublisherDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementClientGetUserDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the publisher-specific custom data for the user which can only be read by the client
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom user
/// data will be returned. See also ClientGetUserPublisherDataAsync, ClientUpdateUserPublisherDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementClientGetUserPublisherReadOnlyDataGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetUserPublisherReadOnlyDataAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerDataManagementGetUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetUserPublisherReadOnlyData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementClientGetUserPublisherReadOnlyDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementClientGetUserPublisherReadOnlyDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetUserPublisherReadOnlyDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementClientGetUserDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the title-specific custom data for the user which can only be read by the client
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. Every time the data is updated via any source, the version
/// counter is incremented. If the Version parameter is provided, then this call will only return data
/// if the current version on the system is greater than the value provided. If the Keys parameter is
/// provided, the data object returned will only contain the data specific to the indicated Keys. Otherwise,
/// the full set of custom user data will be returned. See also ClientGetUserDataAsync, ClientUpdateUserDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementClientGetUserReadOnlyDataGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetUserReadOnlyDataAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerDataManagementGetUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetUserReadOnlyData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementClientGetUserReadOnlyDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementClientGetUserReadOnlyDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementClientGetUserReadOnlyDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementClientGetUserDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Updates the values of the specified title-specific statistics for the user. By default, clients are
/// not permitted to update statistics. Developers may override this setting in the Game Manager > Settings
/// > API Features.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Enable this option with the 'Allow Client to Post Player Statistics' option in PlayFab GameManager
/// for your title. However, this is not best practice, as this data will no longer be safely controlled
/// by the server. This operation is additive. Statistics not currently defined will be added, while those
/// already defined will be updated with the given values. All other user statistics will remain unchanged.
/// Note that if the statistic is intended to have a reset period, the UpdatePlayerStatisticDefinition
/// API call can be used to define that reset period. Once a statistic has been versioned (reset), the
/// now-previous version can still be written to for up a short, pre-defined period (currently 10 seconds),
/// using the Version parameter in this call.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFPlayerDataManagementClientUpdatePlayerStatisticsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerDataManagementClientUpdatePlayerStatisticsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Creates and updates the title-specific custom data for the user which is readable and writable by
/// the client
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary strings containing the custom data for
/// the user. In updating the custom data object, keys which already exist in the object will have their
/// values overwritten, while keys with null values will be removed. New keys will be added, with the
/// given values. No other key-value pairs will be changed apart from those specified in the call. See
/// also ClientGetUserDataAsync, ClientGetUserReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementClientUpdateUserDataGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFPlayerDataManagementClientUpdateUserDataAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerDataManagementClientUpdateUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementClientUpdateUserDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFPlayerDataManagementUpdateUserDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementClientUpdateUserDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFPlayerDataManagementUpdateUserDataResult* result
) noexcept;

/// <summary>
/// Creates and updates the publisher-specific custom data for the user which is readable and writable
/// by the client
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary strings containing the custom data for
/// the user. In updating the custom data object, keys which already exist in the object will have their
/// values overwritten, while keys with null values will be removed. New keys will be added, with the
/// given values. No other key-value pairs will be changed apart from those specified in the call. See
/// also ClientGetUserPublisherDataAsync, ClientGetUserPublisherReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementClientUpdateUserPublisherDataGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFPlayerDataManagementClientUpdateUserPublisherDataAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerDataManagementClientUpdateUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementClientUpdateUserPublisherDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFPlayerDataManagementUpdateUserDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementClientUpdateUserPublisherDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFPlayerDataManagementUpdateUserDataResult* result
) noexcept;

/// <summary>
/// Retrieves a list of ranked friends of the given player for the given statistic, starting from the
/// indicated point in the leaderboard
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientGetLeaderboardAroundCurrentUserAsync, ServerGetLeaderboardAroundUserAsync, ServerGetUserStatisticsAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementServerGetFriendLeaderboardGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetFriendLeaderboardAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementServerGetFriendLeaderboardRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetFriendLeaderboard call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerGetFriendLeaderboardGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerGetFriendLeaderboardAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetFriendLeaderboardGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementGetLeaderboardResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves a list of ranked users for the given statistic, starting from the indicated point in the
/// leaderboard
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerGetLeaderboardAroundUserAsync, ServerGetUserStatisticsAsync, ServerUpdateUserStatisticsAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementServerGetLeaderboardGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetLeaderboardAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementGetLeaderboardRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetLeaderboard call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerGetLeaderboardGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerGetLeaderboardAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetLeaderboardGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementGetLeaderboardResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves a list of ranked users for the given statistic, centered on the currently signed-in user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerGetLeaderboardAsync, ServerGetUserStatisticsAsync, ServerUpdateUserStatisticsAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementServerGetLeaderboardAroundUserGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetLeaderboardAroundUserAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementGetLeaderboardAroundUserRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetLeaderboardAroundUser call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerGetLeaderboardAroundUserGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerGetLeaderboardAroundUserAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetLeaderboardAroundUserGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementGetLeaderboardAroundUserResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Returns whatever info is requested in the response for the user. Note that PII (like email address,
/// facebook id) may be returned. All parameters default to false.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFPlayerDataManagementServerGetPlayerCombinedInfoGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetPlayerCombinedInfoAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFGetPlayerCombinedInfoRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetPlayerCombinedInfo call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerGetPlayerCombinedInfoGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerGetPlayerCombinedInfoAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetPlayerCombinedInfoGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFGetPlayerCombinedInfoResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the current version and values for the indicated statistics, for the local player.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminCreatePlayerStatisticDefinitionAsync, ServerGetPlayerStatisticVersionsAsync, AdminUpdatePlayerStatisticDefinitionAsync,
/// ServerUpdatePlayerStatisticsAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementServerGetPlayerStatisticsGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetPlayerStatisticsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementServerGetPlayerStatisticsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetPlayerStatistics call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerGetPlayerStatisticsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerGetPlayerStatisticsAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetPlayerStatisticsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementServerGetPlayerStatisticsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the information on the available versions of the specified statistic.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminCreatePlayerStatisticDefinitionAsync, ServerGetPlayerStatisticsAsync, AdminUpdatePlayerStatisticDefinitionAsync,
/// ServerUpdatePlayerStatisticsAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementServerGetPlayerStatisticVersionsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetPlayerStatisticVersionsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementGetPlayerStatisticVersionsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetPlayerStatisticVersions call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerGetPlayerStatisticVersionsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerGetPlayerStatisticVersionsAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetPlayerStatisticVersionsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementGetPlayerStatisticVersionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the title-specific custom data for the user which is readable and writable by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom user
/// data will be returned. See also ServerGetUserInternalDataAsync, ServerGetUserReadOnlyDataAsync, ServerUpdateUserDataAsync,
/// ServerUpdateUserInternalDataAsync, ServerUpdateUserReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementServerGetUserDataGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetUserDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementGetUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetUserData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerGetUserDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerGetUserDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetUserDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementServerGetUserDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the title-specific custom data for the user which cannot be accessed by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom user
/// data will be returned. See also ServerGetUserDataAsync, ServerGetUserReadOnlyDataAsync, ServerUpdateUserDataAsync,
/// ServerUpdateUserInternalDataAsync, ServerUpdateUserReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementServerGetUserInternalDataGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetUserInternalDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementGetUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetUserInternalData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerGetUserInternalDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerGetUserInternalDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetUserInternalDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementServerGetUserDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the publisher-specific custom data for the user which is readable and writable by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom user
/// data will be returned. See also ServerGetUserPublisherInternalDataAsync, ServerGetUserPublisherReadOnlyDataAsync,
/// ServerUpdateUserPublisherDataAsync, ServerUpdateUserPublisherInternalDataAsync, ServerUpdateUserPublisherReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementServerGetUserPublisherDataGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetUserPublisherDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementGetUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetUserPublisherData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerGetUserPublisherDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerGetUserPublisherDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetUserPublisherDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementServerGetUserDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the publisher-specific custom data for the user which cannot be accessed by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom user
/// data will be returned. See also ServerGetUserPublisherDataAsync, ServerGetUserPublisherReadOnlyDataAsync,
/// ServerUpdateUserPublisherDataAsync, ServerUpdateUserPublisherInternalDataAsync, ServerUpdateUserPublisherReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementServerGetUserPublisherInternalDataGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetUserPublisherInternalDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementGetUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetUserPublisherInternalData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerGetUserPublisherInternalDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerGetUserPublisherInternalDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetUserPublisherInternalDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementServerGetUserDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the publisher-specific custom data for the user which can only be read by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom user
/// data will be returned. See also ServerGetUserPublisherDataAsync, ServerGetUserPublisherInternalDataAsync,
/// ServerUpdateUserPublisherDataAsync, ServerUpdateUserPublisherInternalDataAsync, ServerUpdateUserPublisherReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementServerGetUserPublisherReadOnlyDataGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetUserPublisherReadOnlyDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementGetUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetUserPublisherReadOnlyData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerGetUserPublisherReadOnlyDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerGetUserPublisherReadOnlyDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetUserPublisherReadOnlyDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementServerGetUserDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the title-specific custom data for the user which can only be read by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Data is stored as JSON key-value pairs. If the Keys parameter is provided, the data object returned
/// will only contain the data specific to the indicated Keys. Otherwise, the full set of custom user
/// data will be returned. See also ServerGetUserDataAsync, ServerGetUserInternalDataAsync, ServerUpdateUserDataAsync,
/// ServerUpdateUserInternalDataAsync, ServerUpdateUserReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementServerGetUserReadOnlyDataGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetUserReadOnlyDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementGetUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetUserReadOnlyData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerGetUserReadOnlyDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerGetUserReadOnlyDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerDataManagementServerGetUserReadOnlyDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerDataManagementServerGetUserDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Updates the values of the specified title-specific statistics for the user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This operation is additive. Statistics not currently defined will be added, while those already defined
/// will be updated with the given values. All other user statistics will remain unchanged. See also AdminCreatePlayerStatisticDefinitionAsync,
/// ServerGetPlayerStatisticsAsync, AdminUpdatePlayerStatisticDefinitionAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFPlayerDataManagementServerUpdatePlayerStatisticsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementServerUpdatePlayerStatisticsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Updates the title-specific custom data for the user which is readable and writable by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary JSON object containing the custom data
/// for the user. In updating the custom data object, keys which already exist in the object will have
/// their values overwritten, while keys with null values will be removed. No other key-value pairs will
/// be changed apart from those specified in the call. See also ServerGetUserDataAsync, ServerGetUserInternalDataAsync,
/// ServerGetUserReadOnlyDataAsync, ServerUpdateUserInternalDataAsync, ServerUpdateUserReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementServerUpdateUserDataGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFPlayerDataManagementServerUpdateUserDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementServerUpdateUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerUpdateUserDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFPlayerDataManagementUpdateUserDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerUpdateUserDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFPlayerDataManagementUpdateUserDataResult* result
) noexcept;

/// <summary>
/// Updates the title-specific custom data for the user which cannot be accessed by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary JSON object containing the custom data
/// for the user. In updating the custom data object, keys which already exist in the object will have
/// their values overwritten, keys with null values will be removed. No other key-value pairs will be
/// changed apart from those specified in the call. See also ServerGetUserDataAsync, ServerGetUserInternalDataAsync,
/// ServerGetUserReadOnlyDataAsync, ServerUpdateUserDataAsync, ServerUpdateUserReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementServerUpdateUserInternalDataGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFPlayerDataManagementServerUpdateUserInternalDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementUpdateUserInternalDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerUpdateUserInternalDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFPlayerDataManagementUpdateUserDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerUpdateUserInternalDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFPlayerDataManagementUpdateUserDataResult* result
) noexcept;

/// <summary>
/// Updates the publisher-specific custom data for the user which is readable and writable by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary JSON object containing the custom data
/// for the user. In updating the custom data object, keys which already exist in the object will have
/// their values overwritten, while keys with null values will be removed. No other key-value pairs will
/// be changed apart from those specified in the call. See also ServerGetUserPublisherDataAsync, ServerGetUserPublisherInternalDataAsync,
/// ServerGetUserPublisherReadOnlyDataAsync, ServerUpdateUserPublisherInternalDataAsync, ServerUpdateUserPublisherReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementServerUpdateUserPublisherDataGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFPlayerDataManagementServerUpdateUserPublisherDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementServerUpdateUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerUpdateUserPublisherDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFPlayerDataManagementUpdateUserDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerUpdateUserPublisherDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFPlayerDataManagementUpdateUserDataResult* result
) noexcept;

/// <summary>
/// Updates the publisher-specific custom data for the user which cannot be accessed by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary JSON object containing the custom data
/// for the user. In updating the custom data object, keys which already exist in the object will have
/// their values overwritten, keys with null values will be removed. No other key-value pairs will be
/// changed apart from those specified in the call. See also ServerGetUserPublisherDataAsync, ServerGetUserPublisherInternalDataAsync,
/// ServerGetUserPublisherReadOnlyDataAsync, ServerUpdateUserPublisherDataAsync, ServerUpdateUserPublisherReadOnlyDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementServerUpdateUserPublisherInternalDataGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementServerUpdateUserPublisherInternalDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementUpdateUserInternalDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerUpdateUserPublisherInternalDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFPlayerDataManagementUpdateUserDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerUpdateUserPublisherInternalDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFPlayerDataManagementUpdateUserDataResult* result
) noexcept;

/// <summary>
/// Updates the publisher-specific custom data for the user which can only be read by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary JSON object containing the custom data
/// for the user. In updating the custom data object, keys which already exist in the object will have
/// their values overwritten, keys with null values will be removed. No other key-value pairs will be
/// changed apart from those specified in the call. See also ServerGetUserPublisherDataAsync, ServerGetUserPublisherInternalDataAsync,
/// ServerGetUserPublisherReadOnlyDataAsync, ServerUpdateUserPublisherDataAsync, ServerUpdateUserPublisherInternalDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementServerUpdateUserPublisherReadOnlyDataGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerDataManagementServerUpdateUserPublisherReadOnlyDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementServerUpdateUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerUpdateUserPublisherReadOnlyDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFPlayerDataManagementUpdateUserDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerUpdateUserPublisherReadOnlyDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFPlayerDataManagementUpdateUserDataResult* result
) noexcept;

/// <summary>
/// Updates the title-specific custom data for the user which can only be read by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary JSON object containing the custom data
/// for the user. In updating the custom data object, keys which already exist in the object will have
/// their values overwritten, keys with null values will be removed. No other key-value pairs will be
/// changed apart from those specified in the call. See also ServerGetUserDataAsync, ServerGetUserInternalDataAsync,
/// ServerGetUserReadOnlyDataAsync, ServerUpdateUserDataAsync, ServerUpdateUserInternalDataAsync.
///
/// If successful, call <see cref="PFPlayerDataManagementServerUpdateUserReadOnlyDataGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFPlayerDataManagementServerUpdateUserReadOnlyDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerDataManagementServerUpdateUserDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerDataManagementServerUpdateUserReadOnlyDataAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFPlayerDataManagementUpdateUserDataResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerDataManagementServerUpdateUserReadOnlyDataGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFPlayerDataManagementUpdateUserDataResult* result
) noexcept;


}