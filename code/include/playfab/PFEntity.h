// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <httpClient/pal.h>
#include <httpClient/async.h>
#include <playfab/PFSharedDataModels.h>
#include <playfab/PFAuthenticationDataModels.h>

extern "C"
{

/// <summary>
/// Handle to an authenticated Entity (TitlePlayer, Title, etc.). Contains the auth tokens needed to make PlayFab service
/// calls. When no longer needed, the Entity handle must be closed with PFEntityCloseHandle.
/// </summary>
typedef struct PFEntity* PFEntityHandle;

/// <summary>
/// PlayFab EntityToken and its expiration time. Used internally to authenticate PlayFab service calls.
/// </summary>
typedef struct PFEntityToken
{
    /// <summary>
    /// The token used to set X-EntityToken for all entity based API calls.
    /// </summary>
    const char* token;

    /// <summary>
    /// (Optional) The time the token will expire, if it is an expiring token, in UTC.
    /// </summary>
    time_t const* expiration;

} PFEntityToken;

/// <summary>
/// Duplicates a PFEntityHandle.
/// </summary>
/// <param name="entityHandle">Entity handle to duplicate.</param>
/// <param name="duplicatedEntityHandle">The duplicated handle.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Both the duplicated handle and the original handle need to be closed with PFEntityCloseHandle when they
/// are no longer needed.
/// </remarks>
HRESULT PFEntityDuplicateHandle(
    _In_ PFEntityHandle entityHandle,
    _Out_ PFEntityHandle* duplicatedEntityHandle
) noexcept;

/// <summary>
/// Closes a PFEntityHandle.
/// </summary>
/// <param name="entityHandle">Entity handle to close.</param>
/// <returns>Result code for this API operation.</returns>
void PFEntityCloseHandle(
    _In_ PFEntityHandle entityHandle
) noexcept;

/// <summary>
/// A callback invoked every time an Entity is automatically reauthenticated, thus obtaining a new EntityToken. An entity
/// will be automatically reauthenticated prior to its EntityToken expiring.
/// </summary>
typedef void CALLBACK PFEntityTokenRefreshedCallback(
    _In_ const PFEntityToken* newToken,
    _In_opt_ void* context
);

/// <summary>
/// Registers a PFTokenRefreshedCallback for an Entity.
/// </summary>
/// <param name="entityHandle">Entity handle for the entity.</param>
/// <param name="queue">The async queue the callback should be invoked on.</param>
/// <param name="callback">The callback, <see cref="PFEntityTokenRefreshedCallback"/>.</param>
/// <param name="context">Optional pointer to data used by the callback.</param>
/// <param name="token">The token for unregistering the callback.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFEntityRegisterTokenRefreshedCallback(
    _In_ PFEntityHandle entityHandle,
    _In_ XTaskQueueHandle queue,
    _In_ PFEntityTokenRefreshedCallback* callback,
    _In_opt_ void* context,
    _Out_ PFRegistrationToken* token
) noexcept;

/// <summary>
/// Unregisters a previously registered PFEntityTokenRefreshedCallback.
/// </summary>
/// <param name="entityHandle">Entity handle for the entity.</param>
/// <param name="token">Registration token from PFEntityRegisterTokenRefreshedCallback.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFEntityUnregisterTokenRefreshedCallback(
    _In_ PFEntityHandle entityHandle,
    _In_ PFRegistrationToken token
) noexcept;

/// <summary>
/// Method to get an EntityToken for an owned Entity. The token requested can either be for the calling entity (i.e. refreshing
/// the existing valid token) or for an entity owned by the calling entity. If the a token refresh is requested, the internal auth
/// tokens will be updated and used for future calls. Note that the previous EntityToken remains valid until expiration, even though
/// it will no longer be used internally. If the requested token was for a different Entity, a new Entity object is created.
/// </summary>
/// <param name="entityHandle">Existing PFEntityHandle returned from an auth call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFEntityGetEntityTokenGetResult"/> to get the result. If the requested token was the calling Entity, the resulting handle
/// will be a new handle to the same Entity object (it still must be closed by the caller when no longer needed). 
/// </remarks>
HRESULT PFEntityGetEntityTokenAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFAuthenticationGetEntityTokenRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <symmary>
/// Get the result from a PFEntityGetEntityTokenAsync call.
/// </symmary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="entityHandle">Entity handle which can be used to authenticate other PlayFab API calls.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If the PFEntityGetEntityTokenAsync call fails, entityHandle with be null. Otherwise, the handle must be closed with PFEntityCloseHandle
/// when it is no longer needed.
/// </remarks>
HRESULT PFEntityGetEntityTokenGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFEntityHandle* entityHandle
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the PFEntityKey for an Entity.
/// </summary>
/// <param name="entityHandle">PFEntityHandle returned from a auth call.</param>
/// <param name="bufferSize">The buffer size in bytes required for the EntityKey.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFEntityGetEntityKeySize(
    _In_ PFEntityHandle entityHandle,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Get the PFEntityKey for an entity.
/// </summary>
/// <param name="entityHandle">PFEntityHandle returned from a auth call.</param>
/// <param name="bufferSize">The size of the buffer for the PFEntityKey. The required size can be obtained from PFEntityGetEntityKeySize.</param>
/// <param name="buffer">Byte buffer used for the PFEntityKey and its fields.</param>
/// <param name="result">Pointer to the PFEntityKey object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// entityKey is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFEntityGetEntityKey(
    _In_ PFEntityHandle entityHandle,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ const PFEntityKey** entityKey,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the cached PFEntityToken for an Entity.
/// </summary>
/// <param name="entityHandle">PFEntityHandle returned from a auth call.</param>
/// <param name="bufferSize">The buffer size in bytes required for the cached PFEntityToken.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFEntityGetCachedEntityTokenSize(
    _In_ PFEntityHandle entityHandle,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Get the cached Entity token.
/// </summary>
/// <param name="entityHandle">PFEntityHandle returned from a auth call.</param>
/// <param name="bufferSize">The size of the buffer for the PFEntityToken.  The required size can be obtained from PFEntityGetCachedEntityTokenSize.</param>
/// <param name="buffer">Byte buffer used for the PFEntityToken and its fields.</param>
/// <param name="result">Pointer to the PFEntityToken object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// entityToken is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFEntityGetCachedEntityToken(
    _In_ PFEntityHandle entityHandle,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ const PFEntityToken** entityToken,
    _Out_opt_ size_t* bufferUsed
) noexcept;

}
