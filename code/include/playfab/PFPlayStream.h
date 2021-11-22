// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFPlayStreamDataModels.h>
#include <playfab/PFGlobal.h>
#include <playfab/PFTitlePlayer.h>

extern "C"
{

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Adds a given tag to a player profile. The tag's namespace is automatically generated based on the
/// source of the tag.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API will trigger a player_tag_added event and add a tag with the given TagName and PlayFabID
/// to the corresponding player profile. TagName can be used for segmentation and it is limited to 256
/// characters. Also there is a limit on the number of tags a title can have. See also AdminGetPlayerTagsAsync,
/// AdminRemovePlayerTagAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFPlayStreamAdminAddPlayerTagAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayStreamAddPlayerTagRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves an array of player segment definitions. Results from this can be used in subsequent API
/// calls such as GetPlayersInSegment which requires a Segment ID. While segment names can change the
/// ID for that segment will not change.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Request has no paramaters. See also AdminGetPlayersInSegmentAsync.
///
/// If successful, call <see cref="PFPlayStreamAdminGetAllSegmentsGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayStreamAdminGetAllSegmentsAsync(
    _In_ PFStateHandle stateHandle,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetAllSegments call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayStreamAdminGetAllSegmentsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayStreamAdminGetAllSegmentsAsync call.
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
HRESULT PFPlayStreamAdminGetAllSegmentsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayStreamGetAllSegmentsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// List all segments that a player currently belongs to at this moment in time.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminGetAllSegmentsAsync.
///
/// If successful, call <see cref="PFPlayStreamAdminGetPlayerSegmentsGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayStreamAdminGetPlayerSegmentsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayStreamGetPlayersSegmentsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetPlayerSegments call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayStreamAdminGetPlayerSegmentsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayStreamAdminGetPlayerSegmentsAsync call.
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
HRESULT PFPlayStreamAdminGetPlayerSegmentsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayStreamGetPlayerSegmentsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Allows for paging through all players in a given segment. This API creates a snapshot of all player
/// profiles that match the segment definition at the time of its creation and lives through the Total
/// Seconds to Live, refreshing its life span on each subsequent use of the Continuation Token. Profiles
/// that change during the course of paging will not be reflected in the results. AB Test segments are
/// currently not supported by this operation. NOTE: This API is limited to being called 30 times in one
/// minute. You will be returned an error if you exceed this threshold.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Initial request must contain at least a Segment ID. Subsequent requests must contain the Segment
/// ID as well as the Continuation Token. Failure to send the Continuation Token will result in a new
/// player segment list being generated. Each time the Continuation Token is passed in the length of the
/// Total Seconds to Live is refreshed. If too much time passes between requests to the point that a subsequent
/// request is past the Total Seconds to Live an error will be returned and paging will be terminated.
/// This API is resource intensive and should not be used in scenarios which might generate high request
/// volumes. Only one request to this API at a time should be made per title. Concurrent requests to the
/// API may be rejected with the APIConcurrentRequestLimitExceeded error. See also AdminGetAllSegmentsAsync.
///
/// If successful, call <see cref="PFPlayStreamAdminGetPlayersInSegmentGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayStreamAdminGetPlayersInSegmentAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayStreamGetPlayersInSegmentRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetPlayersInSegment call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayStreamAdminGetPlayersInSegmentGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayStreamAdminGetPlayersInSegmentAsync call.
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
HRESULT PFPlayStreamAdminGetPlayersInSegmentGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayStreamGetPlayersInSegmentResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Get all tags with a given Namespace (optional) from a player profile.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API will return a list of canonical tags which includes both namespace and tag's name. If namespace
/// is not provided, the result is a list of all canonical tags. TagName can be used for segmentation
/// and Namespace is limited to 128 characters. See also AdminAddPlayerTagAsync, AdminRemovePlayerTagAsync.
///
/// If successful, call <see cref="PFPlayStreamAdminGetPlayerTagsGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayStreamAdminGetPlayerTagsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayStreamGetPlayerTagsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetPlayerTags call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayStreamAdminGetPlayerTagsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayStreamAdminGetPlayerTagsAsync call.
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
HRESULT PFPlayStreamAdminGetPlayerTagsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayStreamGetPlayerTagsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Remove a given tag from a player profile. The tag's namespace is automatically generated based on
/// the source of the tag.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API will trigger a player_tag_removed event and remove a tag with the given TagName and PlayFabID
/// from the corresponding player profile. TagName can be used for segmentation and it is limited to 256
/// characters See also AdminAddPlayerTagAsync, AdminGetPlayerTagsAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFPlayStreamAdminRemovePlayerTagAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayStreamRemovePlayerTagRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

/// <summary>
/// List all segments that a player currently belongs to at this moment in time.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFPlayStreamClientGetPlayerSegmentsGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayStreamClientGetPlayerSegmentsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayerSegments call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayStreamClientGetPlayerSegmentsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayStreamClientGetPlayerSegmentsAsync call.
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
HRESULT PFPlayStreamClientGetPlayerSegmentsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayStreamGetPlayerSegmentsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Get all tags with a given Namespace (optional) from a player profile.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API will return a list of canonical tags which includes both namespace and tag's name. If namespace
/// is not provided, the result is a list of all canonical tags. TagName can be used for segmentation
/// and Namespace is limited to 128 characters.
///
/// If successful, call <see cref="PFPlayStreamClientGetPlayerTagsGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayStreamClientGetPlayerTagsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayStreamGetPlayerTagsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPlayerTags call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayStreamClientGetPlayerTagsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayStreamClientGetPlayerTagsAsync call.
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
HRESULT PFPlayStreamClientGetPlayerTagsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayStreamGetPlayerTagsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Adds a given tag to a player profile. The tag's namespace is automatically generated based on the
/// source of the tag.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API will trigger a player_tag_added event and add a tag with the given TagName and PlayFabID
/// to the corresponding player profile. TagName can be used for segmentation and it is limited to 256
/// characters. Also there is a limit on the number of tags a title can have. See also ServerGetPlayerTagsAsync,
/// ServerRemovePlayerTagAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFPlayStreamServerAddPlayerTagAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayStreamAddPlayerTagRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Retrieves an array of player segment definitions. Results from this can be used in subsequent API
/// calls such as GetPlayersInSegment which requires a Segment ID. While segment names can change the
/// ID for that segment will not change.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Request has no paramaters. See also ServerGetPlayersInSegmentAsync.
///
/// If successful, call <see cref="PFPlayStreamServerGetAllSegmentsGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayStreamServerGetAllSegmentsAsync(
    _In_ PFStateHandle stateHandle,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetAllSegments call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayStreamServerGetAllSegmentsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayStreamServerGetAllSegmentsAsync call.
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
HRESULT PFPlayStreamServerGetAllSegmentsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayStreamGetAllSegmentsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// List all segments that a player currently belongs to at this moment in time.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerGetAllSegmentsAsync.
///
/// If successful, call <see cref="PFPlayStreamServerGetPlayerSegmentsGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayStreamServerGetPlayerSegmentsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayStreamGetPlayersSegmentsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetPlayerSegments call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayStreamServerGetPlayerSegmentsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayStreamServerGetPlayerSegmentsAsync call.
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
HRESULT PFPlayStreamServerGetPlayerSegmentsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayStreamGetPlayerSegmentsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Allows for paging through all players in a given segment. This API creates a snapshot of all player
/// profiles that match the segment definition at the time of its creation and lives through the Total
/// Seconds to Live, refreshing its life span on each subsequent use of the Continuation Token. Profiles
/// that change during the course of paging will not be reflected in the results. AB Test segments are
/// currently not supported by this operation. NOTE: This API is limited to being called 30 times in one
/// minute. You will be returned an error if you exceed this threshold.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Initial request must contain at least a Segment ID. Subsequent requests must contain the Segment
/// ID as well as the Continuation Token. Failure to send the Continuation Token will result in a new
/// player segment list being generated. Each time the Continuation Token is passed in the length of the
/// Total Seconds to Live is refreshed. If too much time passes between requests to the point that a subsequent
/// request is past the Total Seconds to Live an error will be returned and paging will be terminated.
/// This API is resource intensive and should not be used in scenarios which might generate high request
/// volumes. Only one request to this API at a time should be made per title. Concurrent requests to the
/// API may be rejected with the APIConcurrentRequestLimitExceeded error. See also ServerGetAllSegmentsAsync.
///
/// If successful, call <see cref="PFPlayStreamServerGetPlayersInSegmentGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayStreamServerGetPlayersInSegmentAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayStreamGetPlayersInSegmentRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetPlayersInSegment call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayStreamServerGetPlayersInSegmentGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayStreamServerGetPlayersInSegmentAsync call.
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
HRESULT PFPlayStreamServerGetPlayersInSegmentGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayStreamGetPlayersInSegmentResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Get all tags with a given Namespace (optional) from a player profile.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API will return a list of canonical tags which includes both namespace and tag's name. If namespace
/// is not provided, the result is a list of all canonical tags. TagName can be used for segmentation
/// and Namespace is limited to 128 characters. See also ServerAddPlayerTagAsync, ServerRemovePlayerTagAsync.
///
/// If successful, call <see cref="PFPlayStreamServerGetPlayerTagsGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayStreamServerGetPlayerTagsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayStreamGetPlayerTagsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetPlayerTags call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayStreamServerGetPlayerTagsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayStreamServerGetPlayerTagsAsync call.
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
HRESULT PFPlayStreamServerGetPlayerTagsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayStreamGetPlayerTagsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Remove a given tag from a player profile. The tag's namespace is automatically generated based on
/// the source of the tag.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API will trigger a player_tag_removed event and remove a tag with the given TagName and PlayFabID
/// from the corresponding player profile. TagName can be used for segmentation and it is limited to 256
/// characters See also ServerAddPlayerTagAsync, ServerGetPlayerTagsAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFPlayStreamServerRemovePlayerTagAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayStreamRemovePlayerTagRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Write batches of entity based events to PlayStream. The namespace of the Event must be 'custom' or
/// start with 'custom.'.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFPlayStreamWriteEventsGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayStreamWriteEventsAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFPlayStreamWriteEventsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a WriteEvents call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayStreamWriteEventsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayStreamWriteEventsAsync call.
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
HRESULT PFPlayStreamWriteEventsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayStreamWriteEventsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Write batches of entity based events to as Telemetry events (bypass PlayStream). The namespace must
/// be 'custom' or start with 'custom.'
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFPlayStreamWriteTelemetryEventsGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayStreamWriteTelemetryEventsAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFPlayStreamWriteEventsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a WriteTelemetryEvents call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayStreamWriteTelemetryEventsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayStreamWriteTelemetryEventsAsync call.
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
HRESULT PFPlayStreamWriteTelemetryEventsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayStreamWriteEventsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;


}