// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFEntity.h>
#include <httpClient/async.h>

extern "C"
{

/// <summary>
/// The result of pinging a QoS server.
/// </summary>
typedef struct PFQoSRegionResult
{
    /// <summary>
    /// The region the server is locationed in.
    /// </summary>
    const char* region;

    /// <summary>
    /// Average latency of successful server pings.
    /// </summary>
    uint32_t averageLatencyMs;

    /// <summary>
    /// Number of successful pings used to compute average latency.
    /// </summary>
    uint32_t successfulPingCount;

    /// <summary>
    /// Number of failed ping attempts.
    /// </summary>
    uint32_t failedPingCount;

} PFQoSRegionResult;

/// <summary>
/// QoS measurements for multiple regions.
/// </summary>
typedef struct PFQoSMeasurements
{
    /// <summary>
    /// List of QoS measurements for different regions.
    /// </summary>
    PFQoSRegionResult const* const* regionResults;

    /// <summary>
    /// Count of regionResults.
    /// </summary>
    uint32_t regionResultsCount;

} PFQoSMeasurements;

/// <summary>
/// Take QoS measurements and upload them to PlayFab. The operation first queries for the QoS servers, pings each of them
/// to determine response time, and finally uploads that result to PlayFab. The QoS measuresments are also returned
/// to the caller.
/// </summary>
/// <param name="entityHandle">PFEntityHandle returned from a auth call.</param>
/// <param name="pingIterations">The number of times to ping each server to compute average latency.</param>
/// <param name="timeoutMs">The timeout (in milliseconds) for each ping attempt.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFQoSGetMeasurementsGetResult"/> to get the result.
/// </remarks>
HRESULT PFQoSGetMeasurementsAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ uint32_t pingIterations,
    _In_ uint32_t timeoutMs,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a PFQoSGetMeasurmentsAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFQoSGetMeasurementsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFQoSGetMeasurementsAsync call.
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
HRESULT PFQoSGetMeasurementsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFQoSMeasurements** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

}
