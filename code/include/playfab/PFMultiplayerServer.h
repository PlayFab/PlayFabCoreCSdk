// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFMultiplayerServerDataModels.h>
#include <playfab/PFGlobal.h>
#include <playfab/PFTitlePlayer.h>

extern "C"
{

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Creates a multiplayer server build alias.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Creates a multiplayer server build alias and returns the created alias. See also MultiplayerServerDeleteBuildAliasAsync,
/// MultiplayerServerGetBuildAliasAsync, MultiplayerServerUpdateBuildAliasAsync.
///
/// If successful, call <see cref="PFMultiplayerServerCreateBuildAliasGetResult"/> to get the result.
/// </remarks>
HRESULT PFMultiplayerServerCreateBuildAliasAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerCreateBuildAliasRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a CreateBuildAlias call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerCreateBuildAliasGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerCreateBuildAliasAsync call.
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
HRESULT PFMultiplayerServerCreateBuildAliasGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerBuildAliasDetailsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Creates a multiplayer server build with a custom container.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Creates a multiplayer server build with a custom container and returns information about the build
/// creation request. See also MultiplayerServerCreateBuildWithManagedContainerAsync, MultiplayerServerDeleteBuildAsync,
/// MultiplayerServerGetBuildAsync, MultiplayerServerListBuildSummariesV2Async.
///
/// If successful, call <see cref="PFMultiplayerServerCreateBuildWithCustomContainerGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFMultiplayerServerCreateBuildWithCustomContainerAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerCreateBuildWithCustomContainerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a CreateBuildWithCustomContainer call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerCreateBuildWithCustomContainerGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerCreateBuildWithCustomContainerAsync call.
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
HRESULT PFMultiplayerServerCreateBuildWithCustomContainerGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerCreateBuildWithCustomContainerResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Creates a multiplayer server build with a managed container.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Creates a multiplayer server build with a managed container and returns information about the build
/// creation request. See also MultiplayerServerDeleteBuildAsync, MultiplayerServerGetBuildAsync, MultiplayerServerListBuildSummariesV2Async.
///
/// If successful, call <see cref="PFMultiplayerServerCreateBuildWithManagedContainerGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFMultiplayerServerCreateBuildWithManagedContainerAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerCreateBuildWithManagedContainerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a CreateBuildWithManagedContainer call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerCreateBuildWithManagedContainerGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerCreateBuildWithManagedContainerAsync call.
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
HRESULT PFMultiplayerServerCreateBuildWithManagedContainerGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerCreateBuildWithManagedContainerResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Creates a multiplayer server build with the server running as a process.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Creates a multiplayer server build with the game server running as a process and returns information
/// about the build creation request. See also MultiplayerServerCreateBuildWithManagedContainerAsync,
/// MultiplayerServerDeleteBuildAsync, MultiplayerServerGetBuildAsync, MultiplayerServerListBuildSummariesV2Async.
///
/// If successful, call <see cref="PFMultiplayerServerCreateBuildWithProcessBasedServerGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFMultiplayerServerCreateBuildWithProcessBasedServerAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerCreateBuildWithProcessBasedServerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a CreateBuildWithProcessBasedServer call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerCreateBuildWithProcessBasedServerGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerCreateBuildWithProcessBasedServerAsync call.
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
HRESULT PFMultiplayerServerCreateBuildWithProcessBasedServerGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerCreateBuildWithProcessBasedServerResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Creates a remote user to log on to a VM for a multiplayer server build.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Creates a remote user to log on to a VM for a multiplayer server build in a specific region. Returns
/// user credential information necessary to log on. See also MultiplayerServerDeleteRemoteUserAsync,
/// MultiplayerServerGetRemoteLoginEndpointAsync.
///
/// If successful, call <see cref="PFMultiplayerServerCreateRemoteUserGetResult"/> to get the result.
/// </remarks>
HRESULT PFMultiplayerServerCreateRemoteUserAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerCreateRemoteUserRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a CreateRemoteUser call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerCreateRemoteUserGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerCreateRemoteUserAsync call.
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
HRESULT PFMultiplayerServerCreateRemoteUserGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerCreateRemoteUserResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Creates a request to change a title's multiplayer server quotas.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Creates a request to change a title's multiplayer server quotas. See also MultiplayerServerGetTitleMultiplayerServersQuotaChangeAsync,
/// MultiplayerServerListTitleMultiplayerServersQuotaChangesAsync.
///
/// If successful, call <see cref="PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a CreateTitleMultiplayerServersQuotaChange call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeAsync call.
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
HRESULT PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Deletes a multiplayer server game asset for a title.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Deletes a multiplayer server game asset for a title. See also MultiplayerServerGetAssetUploadUrlAsync,
/// MultiplayerServerListAssetSummariesAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMultiplayerServerDeleteAssetAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerDeleteAssetRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Deletes a multiplayer server build.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Deletes a multiplayer server build. See also MultiplayerServerCreateBuildWithManagedContainerAsync,
/// MultiplayerServerGetBuildAsync, MultiplayerServerListBuildSummariesV2Async.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMultiplayerServerDeleteBuildAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerDeleteBuildRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Deletes a multiplayer server build alias.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Deletes a multiplayer server build alias. See also MultiplayerServerCreateBuildAliasAsync, MultiplayerServerGetBuildAliasAsync,
/// MultiplayerServerUpdateBuildAliasAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMultiplayerServerDeleteBuildAliasAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerDeleteBuildAliasRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Removes a multiplayer server build's region.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Removes a multiplayer server build's region. See also MultiplayerServerDeleteBuildAsync, MultiplayerServerGetBuildAsync,
/// MultiplayerServerListBuildSummariesV2Async, MultiplayerServerUpdateBuildRegionAsync, MultiplayerServerUpdateBuildRegionsAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMultiplayerServerDeleteBuildRegionAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerDeleteBuildRegionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Deletes a multiplayer server game certificate.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Deletes a multiplayer server game certificate. See also MultiplayerServerListCertificateSummariesAsync,
/// MultiplayerServerUploadCertificateAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMultiplayerServerDeleteCertificateAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerDeleteCertificateRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Deletes a container image repository.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Removes the specified container image repository. After this operation, a 'docker pull' will fail
/// for all the tags of the specified image. Morever, ListContainerImages will not return the specified
/// image. See also MultiplayerServerListContainerImageTagsAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMultiplayerServerDeleteContainerImageRepositoryAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerDeleteContainerImageRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Deletes a remote user to log on to a VM for a multiplayer server build.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Deletes a remote user to log on to a VM for a multiplayer server build in a specific region. Returns
/// user credential information necessary to log on. See also MultiplayerServerCreateRemoteUserAsync,
/// MultiplayerServerGetRemoteLoginEndpointAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMultiplayerServerDeleteRemoteUserAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerDeleteRemoteUserRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Enables the multiplayer server feature for a title.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Enables the multiplayer server feature for a title and returns the enabled status. The enabled status
/// can be Initializing, Enabled, and Disabled. It can up to 20 minutes or more for the title to be enabled
/// for the feature. On average, it can take up to 20 minutes for the title to be enabled for the feature.
/// See also MultiplayerServerGetTitleEnabledForMultiplayerServersStatusAsync.
///
/// If successful, call <see cref="PFMultiplayerServerEnableMultiplayerServersForTitleGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFMultiplayerServerEnableMultiplayerServersForTitleAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerEnableMultiplayerServersForTitleRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a EnableMultiplayerServersForTitle call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerEnableMultiplayerServersForTitleGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerEnableMultiplayerServersForTitleAsync call.
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
HRESULT PFMultiplayerServerEnableMultiplayerServersForTitleGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerEnableMultiplayerServersForTitleResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

/// <summary>
/// Gets a URL that can be used to download the specified asset. A sample pre-authenticated url - https://sampleStorageAccount.blob.core.windows.net/gameassets/gameserver.zip?sv=2015-04-05&ss=b&srt=sco&sp=rw&st=startDate&se=endDate&spr=https&sig=sampleSig&api-version=2017-07-29
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Gets a URL that can be used to download the specified asset. See also MultiplayerServerGetAssetUploadUrlAsync,
/// MultiplayerServerListAssetSummariesAsync.
///
/// If successful, call <see cref="PFMultiplayerServerGetAssetDownloadUrlGetResult"/> to get the result.
/// </remarks>
HRESULT PFMultiplayerServerGetAssetDownloadUrlAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerGetAssetDownloadUrlRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetAssetDownloadUrl call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerGetAssetDownloadUrlGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerGetAssetDownloadUrlAsync call.
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
HRESULT PFMultiplayerServerGetAssetDownloadUrlGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetAssetDownloadUrlResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Gets the URL to upload assets to. A sample pre-authenticated url - https://sampleStorageAccount.blob.core.windows.net/gameassets/gameserver.zip?sv=2015-04-05&ss=b&srt=sco&sp=rw&st=startDate&se=endDate&spr=https&sig=sampleSig&api-version=2017-07-29
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Gets the URL to upload assets to. See also MultiplayerServerListAssetSummariesAsync, MultiplayerServerListCertificateSummariesAsync,
/// MultiplayerServerUploadCertificateAsync.
///
/// If successful, call <see cref="PFMultiplayerServerGetAssetUploadUrlGetResult"/> to get the result.
/// </remarks>
HRESULT PFMultiplayerServerGetAssetUploadUrlAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerGetAssetUploadUrlRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetAssetUploadUrl call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerGetAssetUploadUrlGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerGetAssetUploadUrlAsync call.
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
HRESULT PFMultiplayerServerGetAssetUploadUrlGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetAssetUploadUrlResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Gets a multiplayer server build.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Returns the details about a multiplayer server build. See also MultiplayerServerCreateBuildWithManagedContainerAsync,
/// MultiplayerServerDeleteBuildAsync, MultiplayerServerListBuildSummariesV2Async.
///
/// If successful, call <see cref="PFMultiplayerServerGetBuildGetResult"/> to get the result.
/// </remarks>
HRESULT PFMultiplayerServerGetBuildAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerGetBuildRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetBuild call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerGetBuildGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerGetBuildAsync call.
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
HRESULT PFMultiplayerServerGetBuildGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetBuildResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Gets a multiplayer server build alias.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Returns the details about a multiplayer server build alias. See also MultiplayerServerCreateBuildAliasAsync,
/// MultiplayerServerDeleteBuildAliasAsync, MultiplayerServerUpdateBuildAliasAsync.
///
/// If successful, call <see cref="PFMultiplayerServerGetBuildAliasGetResult"/> to get the result.
/// </remarks>
HRESULT PFMultiplayerServerGetBuildAliasAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerGetBuildAliasRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetBuildAlias call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerGetBuildAliasGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerGetBuildAliasAsync call.
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
HRESULT PFMultiplayerServerGetBuildAliasGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerBuildAliasDetailsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Gets the credentials to the container registry.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Gets credentials to the container registry where game developers can upload custom container images
/// to before creating a new build. See also MultiplayerServerCreateBuildWithCustomContainerAsync, MultiplayerServerRolloverContainerRegistryCredentialsAsync.
///
/// If successful, call <see cref="PFMultiplayerServerGetContainerRegistryCredentialsGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFMultiplayerServerGetContainerRegistryCredentialsAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerGetContainerRegistryCredentialsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetContainerRegistryCredentials call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerGetContainerRegistryCredentialsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerGetContainerRegistryCredentialsAsync call.
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
HRESULT PFMultiplayerServerGetContainerRegistryCredentialsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetContainerRegistryCredentialsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Gets multiplayer server session details for a build.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Gets multiplayer server session details for a build in a specific region. See also MultiplayerServerRequestMultiplayerServerAsync.
///
/// If successful, call <see cref="PFMultiplayerServerGetMultiplayerServerDetailsGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFMultiplayerServerGetMultiplayerServerDetailsAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerGetMultiplayerServerDetailsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetMultiplayerServerDetails call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerGetMultiplayerServerDetailsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerGetMultiplayerServerDetailsAsync call.
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
HRESULT PFMultiplayerServerGetMultiplayerServerDetailsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetMultiplayerServerDetailsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Gets multiplayer server logs after a server has terminated.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Gets multiplayer server logs for a specific server id in a region. The logs are available only after
/// a server has terminated. See also MultiplayerServerGetMultiplayerServerDetailsAsync, MultiplayerServerRequestMultiplayerServerAsync.
///
/// If successful, call <see cref="PFMultiplayerServerGetMultiplayerServerLogsGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFMultiplayerServerGetMultiplayerServerLogsAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerGetMultiplayerServerLogsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetMultiplayerServerLogs call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerGetMultiplayerServerLogsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerGetMultiplayerServerLogsAsync call.
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
HRESULT PFMultiplayerServerGetMultiplayerServerLogsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetMultiplayerServerLogsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Gets multiplayer server logs after a server has terminated.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Gets multiplayer server logs for a specific server id in a region. The logs are available only after
/// a server has terminated. See also MultiplayerServerGetMultiplayerServerDetailsAsync, MultiplayerServerRequestMultiplayerServerAsync.
///
/// If successful, call <see cref="PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetMultiplayerSessionLogsBySessionId call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdAsync call.
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
HRESULT PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetMultiplayerServerLogsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Gets a remote login endpoint to a VM that is hosting a multiplayer server build.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Gets a remote login endpoint to a VM that is hosting a multiplayer server build in a specific region.
/// See also MultiplayerServerCreateRemoteUserAsync.
///
/// If successful, call <see cref="PFMultiplayerServerGetRemoteLoginEndpointGetResult"/> to get the result.
/// </remarks>
HRESULT PFMultiplayerServerGetRemoteLoginEndpointAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerGetRemoteLoginEndpointRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetRemoteLoginEndpoint call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerGetRemoteLoginEndpointGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerGetRemoteLoginEndpointAsync call.
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
HRESULT PFMultiplayerServerGetRemoteLoginEndpointGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetRemoteLoginEndpointResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Gets the status of whether a title is enabled for the multiplayer server feature.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Gets the status of whether a title is enabled for the multiplayer server feature. The enabled status
/// can be Initializing, Enabled, and Disabled. See also MultiplayerServerEnableMultiplayerServersForTitleAsync.
///
/// If successful, call <see cref="PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetTitleEnabledForMultiplayerServersStatus call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusAsync call.
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
HRESULT PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Gets a title's server quota change request.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Gets a title's server quota change request. See also MultiplayerServerCreateTitleMultiplayerServersQuotaChangeAsync,
/// MultiplayerServerListTitleMultiplayerServersQuotaChangesAsync.
///
/// If successful, call <see cref="PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetTitleMultiplayerServersQuotaChange call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeAsync call.
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
HRESULT PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Gets the quotas for a title in relation to multiplayer servers.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Gets the quotas for a title in relation to multiplayer servers.
///
/// If successful, call <see cref="PFMultiplayerServerGetTitleMultiplayerServersQuotasGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFMultiplayerServerGetTitleMultiplayerServersQuotasAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerGetTitleMultiplayerServersQuotasRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetTitleMultiplayerServersQuotas call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerGetTitleMultiplayerServersQuotasGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerGetTitleMultiplayerServersQuotasAsync call.
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
HRESULT PFMultiplayerServerGetTitleMultiplayerServersQuotasGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Lists archived multiplayer server sessions for a build.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Returns a list of archived multiplayer servers for a build in a specific region. See also MultiplayerServerRequestMultiplayerServerAsync.
///
/// If successful, call <see cref="PFMultiplayerServerListArchivedMultiplayerServersGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFMultiplayerServerListArchivedMultiplayerServersAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerListMultiplayerServersRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ListArchivedMultiplayerServers call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerListArchivedMultiplayerServersGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerListArchivedMultiplayerServersAsync call.
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
HRESULT PFMultiplayerServerListArchivedMultiplayerServersGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListMultiplayerServersResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Lists multiplayer server game assets for a title.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Returns a list of multiplayer server game asset summaries for a title. See also MultiplayerServerGetAssetUploadUrlAsync,
/// MultiplayerServerListCertificateSummariesAsync, MultiplayerServerUploadCertificateAsync.
///
/// If successful, call <see cref="PFMultiplayerServerListAssetSummariesGetResult"/> to get the result.
/// </remarks>
HRESULT PFMultiplayerServerListAssetSummariesAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerListAssetSummariesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ListAssetSummaries call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerListAssetSummariesGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerListAssetSummariesAsync call.
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
HRESULT PFMultiplayerServerListAssetSummariesGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListAssetSummariesResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Lists details of all build aliases for a title. Accepts tokens for title and if game client access
/// is enabled, allows game client to request list of builds with player entity token.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Returns a list of summarized details of all multiplayer server builds for a title. See also MultiplayerServerCreateBuildWithManagedContainerAsync,
/// MultiplayerServerDeleteBuildAsync, MultiplayerServerGetBuildAsync.
///
/// If successful, call <see cref="PFMultiplayerServerListBuildAliasesGetResult"/> to get the result.
/// </remarks>
HRESULT PFMultiplayerServerListBuildAliasesAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerListBuildAliasesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ListBuildAliases call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerListBuildAliasesGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerListBuildAliasesAsync call.
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
HRESULT PFMultiplayerServerListBuildAliasesGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListBuildAliasesResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Lists summarized details of all multiplayer server builds for a title. Accepts tokens for title and
/// if game client access is enabled, allows game client to request list of builds with player entity
/// token.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Returns a list of summarized details of all multiplayer server builds for a title. See also MultiplayerServerCreateBuildWithManagedContainerAsync,
/// MultiplayerServerDeleteBuildAsync, MultiplayerServerGetBuildAsync.
///
/// If successful, call <see cref="PFMultiplayerServerListBuildSummariesV2GetResult"/> to get the result.
/// </remarks>
HRESULT PFMultiplayerServerListBuildSummariesV2Async(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerListBuildSummariesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ListBuildSummariesV2 call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerListBuildSummariesV2GetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerListBuildSummariesV2Async call.
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
HRESULT PFMultiplayerServerListBuildSummariesV2GetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListBuildSummariesResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Lists multiplayer server game certificates for a title.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Returns a list of multiplayer server game certificates for a title. See also MultiplayerServerDeleteCertificateAsync,
/// MultiplayerServerUploadCertificateAsync.
///
/// If successful, call <see cref="PFMultiplayerServerListCertificateSummariesGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFMultiplayerServerListCertificateSummariesAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerListCertificateSummariesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ListCertificateSummaries call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerListCertificateSummariesGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerListCertificateSummariesAsync call.
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
HRESULT PFMultiplayerServerListCertificateSummariesGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListCertificateSummariesResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Lists custom container images for a title.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Returns a list of the container images that have been uploaded to the container registry for a title.
/// See also MultiplayerServerGetContainerRegistryCredentialsAsync, MultiplayerServerListContainerImageTagsAsync.
///
/// If successful, call <see cref="PFMultiplayerServerListContainerImagesGetResult"/> to get the result.
/// </remarks>
HRESULT PFMultiplayerServerListContainerImagesAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerListContainerImagesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ListContainerImages call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerListContainerImagesGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerListContainerImagesAsync call.
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
HRESULT PFMultiplayerServerListContainerImagesGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListContainerImagesResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Lists the tags for a custom container image.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Returns a list of the tags for a particular container image that exists in the container registry
/// for a title. See also MultiplayerServerListContainerImagesAsync.
///
/// If successful, call <see cref="PFMultiplayerServerListContainerImageTagsGetResult"/> to get the result.
/// </remarks>
HRESULT PFMultiplayerServerListContainerImageTagsAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerListContainerImageTagsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ListContainerImageTags call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerListContainerImageTagsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerListContainerImageTagsAsync call.
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
HRESULT PFMultiplayerServerListContainerImageTagsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListContainerImageTagsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Lists multiplayer server sessions for a build.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Returns a list of multiplayer servers for a build in a specific region. See also MultiplayerServerRequestMultiplayerServerAsync.
///
/// If successful, call <see cref="PFMultiplayerServerListMultiplayerServersGetResult"/> to get the result.
/// </remarks>
HRESULT PFMultiplayerServerListMultiplayerServersAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerListMultiplayerServersRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ListMultiplayerServers call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerListMultiplayerServersGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerListMultiplayerServersAsync call.
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
HRESULT PFMultiplayerServerListMultiplayerServersGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListMultiplayerServersResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

/// <summary>
/// Lists quality of service servers for party.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Returns a list of quality of service servers for party.
///
/// If successful, call <see cref="PFMultiplayerServerListPartyQosServersGetResult"/> to get the result.
/// </remarks>
HRESULT PFMultiplayerServerListPartyQosServersAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFMultiplayerServerListPartyQosServersRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ListPartyQosServers call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerListPartyQosServersGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerListPartyQosServersAsync call.
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
HRESULT PFMultiplayerServerListPartyQosServersGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListPartyQosServersResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Lists quality of service servers for the title. By default, servers are only returned for regions
/// where a Multiplayer Servers build has been deployed.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Returns a list of quality of service servers for a title.
///
/// If successful, call <see cref="PFMultiplayerServerListQosServersForTitleGetResult"/> to get the result.
/// </remarks>
HRESULT PFMultiplayerServerListQosServersForTitleAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerListQosServersForTitleRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ListQosServersForTitle call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerListQosServersForTitleGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerListQosServersForTitleAsync call.
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
HRESULT PFMultiplayerServerListQosServersForTitleGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListQosServersForTitleResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// List all server quota change requests for a title.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// List all server quota change requests for a title. See also MultiplayerServerCreateTitleMultiplayerServersQuotaChangeAsync,
/// MultiplayerServerGetTitleMultiplayerServersQuotaChangeAsync.
///
/// If successful, call <see cref="PFMultiplayerServerListTitleMultiplayerServersQuotaChangesGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFMultiplayerServerListTitleMultiplayerServersQuotaChangesAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ListTitleMultiplayerServersQuotaChanges call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerListTitleMultiplayerServersQuotaChangesGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerListTitleMultiplayerServersQuotaChangesAsync call.
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
HRESULT PFMultiplayerServerListTitleMultiplayerServersQuotaChangesGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Lists virtual machines for a title.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Returns a list of virtual machines for a title.
///
/// If successful, call <see cref="PFMultiplayerServerListVirtualMachineSummariesGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFMultiplayerServerListVirtualMachineSummariesAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerListVirtualMachineSummariesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ListVirtualMachineSummaries call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerListVirtualMachineSummariesGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerListVirtualMachineSummariesAsync call.
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
HRESULT PFMultiplayerServerListVirtualMachineSummariesGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerListVirtualMachineSummariesResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

/// <summary>
/// Request a multiplayer server session. Accepts tokens for title and if game client access is enabled,
/// allows game client to request a server with player entity token.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Requests a multiplayer server session from a particular build in any of the given preferred regions.
/// See also MultiplayerServerGetMultiplayerServerDetailsAsync.
///
/// If successful, call <see cref="PFMultiplayerServerRequestMultiplayerServerGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFMultiplayerServerRequestMultiplayerServerAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerRequestMultiplayerServerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a RequestMultiplayerServer call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerRequestMultiplayerServerGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerRequestMultiplayerServerAsync call.
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
HRESULT PFMultiplayerServerRequestMultiplayerServerGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerRequestMultiplayerServerResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Rolls over the credentials to the container registry.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Gets new credentials to the container registry where game developers can upload custom container
/// images to before creating a new build. See also MultiplayerServerGetContainerRegistryCredentialsAsync.
///
/// If successful, call <see cref="PFMultiplayerServerRolloverContainerRegistryCredentialsGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFMultiplayerServerRolloverContainerRegistryCredentialsAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerRolloverContainerRegistryCredentialsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a RolloverContainerRegistryCredentials call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerRolloverContainerRegistryCredentialsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerRolloverContainerRegistryCredentialsAsync call.
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
HRESULT PFMultiplayerServerRolloverContainerRegistryCredentialsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerRolloverContainerRegistryCredentialsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

/// <summary>
/// Shuts down a multiplayer server session.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Executes the shutdown callback from the GSDK and terminates the multiplayer server session. The callback
/// in the GSDK will allow for graceful shutdown with a 15 minute timeoutIf graceful shutdown has not
/// been completed before 15 minutes have elapsed, the multiplayer server session will be forcefully terminated
/// on it's own. See also MultiplayerServerGetMultiplayerServerDetailsAsync, MultiplayerServerRequestMultiplayerServerAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMultiplayerServerShutdownMultiplayerServerAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerShutdownMultiplayerServerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Untags a container image.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Removes the specified tag from the image. After this operation, a 'docker pull' will fail for the
/// specified image and tag combination. Morever, ListContainerImageTags will not return the specified
/// tag. See also MultiplayerServerListContainerImageTagsAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMultiplayerServerUntagContainerImageAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerUntagContainerImageRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Creates a multiplayer server build alias.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Creates a multiplayer server build alias and returns the created alias. See also MultiplayerServerCreateBuildAliasAsync,
/// MultiplayerServerDeleteBuildAliasAsync, MultiplayerServerGetBuildAliasAsync.
///
/// If successful, call <see cref="PFMultiplayerServerUpdateBuildAliasGetResult"/> to get the result.
/// </remarks>
HRESULT PFMultiplayerServerUpdateBuildAliasAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerUpdateBuildAliasRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a UpdateBuildAlias call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFMultiplayerServerUpdateBuildAliasGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFMultiplayerServerUpdateBuildAliasAsync call.
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
HRESULT PFMultiplayerServerUpdateBuildAliasGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFMultiplayerServerBuildAliasDetailsResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates a multiplayer server build's name.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Updates a multiplayer server build's name. See also MultiplayerServerDeleteBuildAsync, MultiplayerServerGetBuildAsync,
/// MultiplayerServerListBuildSummariesV2Async, MultiplayerServerUpdateBuildRegionAsync, MultiplayerServerUpdateBuildRegionsAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMultiplayerServerUpdateBuildNameAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerUpdateBuildNameRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates a multiplayer server build's region. If the region is not yet created, it will be created
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Updates a multiplayer server build's region. See also MultiplayerServerDeleteBuildAsync, MultiplayerServerDeleteBuildRegionAsync,
/// MultiplayerServerGetBuildAsync, MultiplayerServerListBuildSummariesV2Async, MultiplayerServerUpdateBuildRegionsAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMultiplayerServerUpdateBuildRegionAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerUpdateBuildRegionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates a multiplayer server build's regions.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Updates a multiplayer server build's regions. See also MultiplayerServerDeleteBuildAsync, MultiplayerServerDeleteBuildRegionAsync,
/// MultiplayerServerGetBuildAsync, MultiplayerServerListBuildSummariesV2Async, MultiplayerServerUpdateBuildRegionAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMultiplayerServerUpdateBuildRegionsAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerUpdateBuildRegionsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Uploads a multiplayer server game certificate.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Uploads a multiplayer server game certificate. See also MultiplayerServerDeleteCertificateAsync,
/// MultiplayerServerListCertificateSummariesAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFMultiplayerServerUploadCertificateAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFMultiplayerServerUploadCertificateRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif


}