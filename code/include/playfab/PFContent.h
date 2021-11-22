// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFContentDataModels.h>
#include <playfab/PFGlobal.h>
#include <playfab/PFTitlePlayer.h>

extern "C"
{

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Delete a content file from the title. When deleting a file that does not exist, it returns success.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientGetContentDownloadUrlAsync, ServerGetContentDownloadUrlAsync, AdminGetContentListAsync,
/// AdminGetContentUploadUrlAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFContentAdminDeleteContentAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFContentDeleteContentRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// List all contents of the title and get statistics such as size
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminDeleteContentAsync, ClientGetContentDownloadUrlAsync, ServerGetContentDownloadUrlAsync,
/// AdminGetContentUploadUrlAsync.
///
/// If successful, call <see cref="PFContentAdminGetContentListGetResult"/> to get the result.
/// </remarks>
HRESULT PFContentAdminGetContentListAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFContentGetContentListRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetContentList call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFContentAdminGetContentListGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFContentAdminGetContentListAsync call.
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
HRESULT PFContentAdminGetContentListGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFContentGetContentListResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the pre-signed URL for uploading a content file. A subsequent HTTP PUT to the returned
/// URL uploads the content. Also, please be aware that the Content service is specifically PlayFab's
/// CDN offering, for which standard CDN rates apply.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminDeleteContentAsync, ClientGetContentDownloadUrlAsync, ServerGetContentDownloadUrlAsync,
/// AdminGetContentListAsync.
///
/// If successful, call <see cref="PFContentAdminGetContentUploadUrlGetResult"/> to get the result.
/// </remarks>
HRESULT PFContentAdminGetContentUploadUrlAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFContentGetContentUploadUrlRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetContentUploadUrl call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFContentAdminGetContentUploadUrlGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFContentAdminGetContentUploadUrlAsync call.
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
HRESULT PFContentAdminGetContentUploadUrlGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFContentGetContentUploadUrlResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// This API retrieves a pre-signed URL for accessing a content file for the title. A subsequent HTTP
/// GET to the returned URL will attempt to download the content. A HEAD query to the returned URL will
/// attempt to retrieve the metadata of the content. Note that a successful result does not guarantee
/// the existence of this content - if it has not been uploaded, the query to retrieve the data will fail.
/// See this post for more information: https://community.playfab.com/hc/community/posts/205469488-How-to-upload-files-to-PlayFab-s-Content-Service.
/// Also, please be aware that the Content service is specifically PlayFab's CDN offering, for which standard
/// CDN rates apply.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminDeleteContentAsync, ServerGetContentDownloadUrlAsync, AdminGetContentListAsync, AdminGetContentUploadUrlAsync.
///
/// If successful, call <see cref="PFContentClientGetContentDownloadUrlGetResult"/> to get the result.
/// </remarks>
HRESULT PFContentClientGetContentDownloadUrlAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFContentGetContentDownloadUrlRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetContentDownloadUrl call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFContentClientGetContentDownloadUrlGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFContentClientGetContentDownloadUrlAsync call.
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
HRESULT PFContentClientGetContentDownloadUrlGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFContentGetContentDownloadUrlResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// This API retrieves a pre-signed URL for accessing a content file for the title. A subsequent HTTP
/// GET to the returned URL will attempt to download the content. A HEAD query to the returned URL will
/// attempt to retrieve the metadata of the content. Note that a successful result does not guarantee
/// the existence of this content - if it has not been uploaded, the query to retrieve the data will fail.
/// See this post for more information: https://community.playfab.com/hc/community/posts/205469488-How-to-upload-files-to-PlayFab-s-Content-Service.
/// Also, please be aware that the Content service is specifically PlayFab's CDN offering, for which standard
/// CDN rates apply.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminDeleteContentAsync, ClientGetContentDownloadUrlAsync, AdminGetContentListAsync, AdminGetContentUploadUrlAsync.
///
/// If successful, call <see cref="PFContentServerGetContentDownloadUrlGetResult"/> to get the result.
/// </remarks>
HRESULT PFContentServerGetContentDownloadUrlAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFContentGetContentDownloadUrlRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetContentDownloadUrl call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFContentServerGetContentDownloadUrlGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFContentServerGetContentDownloadUrlAsync call.
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
HRESULT PFContentServerGetContentDownloadUrlGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFContentGetContentDownloadUrlResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif


}