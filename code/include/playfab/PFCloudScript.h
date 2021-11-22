// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFCloudScriptDataModels.h>
#include <playfab/PFGlobal.h>
#include <playfab/PFTitlePlayer.h>

extern "C"
{

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Gets the contents and information of a specific Cloud Script revision.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFCloudScriptAdminGetCloudScriptRevisionGetResult"/> to get the result.
/// </remarks>
HRESULT PFCloudScriptAdminGetCloudScriptRevisionAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCloudScriptGetCloudScriptRevisionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetCloudScriptRevision call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCloudScriptAdminGetCloudScriptRevisionGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCloudScriptAdminGetCloudScriptRevisionAsync call.
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
HRESULT PFCloudScriptAdminGetCloudScriptRevisionGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCloudScriptGetCloudScriptRevisionResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Lists all the current cloud script versions. For each version, information about the current published
/// and latest revisions is also listed.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFCloudScriptAdminGetCloudScriptVersionsGetResult"/> to get the result.
/// </remarks>
HRESULT PFCloudScriptAdminGetCloudScriptVersionsAsync(
    _In_ PFStateHandle stateHandle,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetCloudScriptVersions call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCloudScriptAdminGetCloudScriptVersionsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCloudScriptAdminGetCloudScriptVersionsAsync call.
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
HRESULT PFCloudScriptAdminGetCloudScriptVersionsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCloudScriptGetCloudScriptVersionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Sets the currently published revision of a title Cloud Script
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFCloudScriptAdminSetPublishedRevisionAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCloudScriptSetPublishedRevisionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Creates a new Cloud Script revision and uploads source code to it. Note that at this time, only one
/// file should be submitted in the revision.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFCloudScriptAdminUpdateCloudScriptGetResult"/> to get the result.
/// </remarks>
HRESULT PFCloudScriptAdminUpdateCloudScriptAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCloudScriptUpdateCloudScriptRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFCloudScriptAdminUpdateCloudScriptAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFCloudScriptUpdateCloudScriptResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCloudScriptAdminUpdateCloudScriptGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFCloudScriptUpdateCloudScriptResult* result
) noexcept;
#endif

/// <summary>
/// Executes a CloudScript function, with the 'currentPlayerId' set to the PlayFab ID of the authenticated
/// player.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFCloudScriptClientExecuteCloudScriptGetResult"/> to get the result.
/// </remarks>
HRESULT PFCloudScriptClientExecuteCloudScriptAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFCloudScriptExecuteCloudScriptRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientExecuteCloudScript call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCloudScriptClientExecuteCloudScriptGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCloudScriptClientExecuteCloudScriptAsync call.
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
HRESULT PFCloudScriptClientExecuteCloudScriptGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFExecuteCloudScriptResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Executes a CloudScript function, with the 'currentPlayerId' variable set to the specified PlayFabId
/// parameter value.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFCloudScriptServerExecuteCloudScriptGetResult"/> to get the result.
/// </remarks>
HRESULT PFCloudScriptServerExecuteCloudScriptAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFCloudScriptExecuteCloudScriptServerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerExecuteCloudScript call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCloudScriptServerExecuteCloudScriptGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCloudScriptServerExecuteCloudScriptAsync call.
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
HRESULT PFCloudScriptServerExecuteCloudScriptGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFExecuteCloudScriptResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Cloud Script is one of PlayFab's most versatile features. It allows client code to request execution
/// of any kind of custom server-side functionality you can implement, and it can be used in conjunction
/// with virtually anything.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Executes CloudScript with the entity profile that is defined in the request.
///
/// If successful, call <see cref="PFCloudScriptExecuteEntityCloudScriptGetResult"/> to get the result.
/// </remarks>
HRESULT PFCloudScriptExecuteEntityCloudScriptAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFCloudScriptExecuteEntityCloudScriptRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ExecuteEntityCloudScript call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCloudScriptExecuteEntityCloudScriptGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCloudScriptExecuteEntityCloudScriptAsync call.
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
HRESULT PFCloudScriptExecuteEntityCloudScriptGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFExecuteCloudScriptResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Cloud Script is one of PlayFab's most versatile features. It allows client code to request execution
/// of any kind of custom server-side functionality you can implement, and it can be used in conjunction
/// with virtually anything.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Executes an Azure Function with the profile of the entity that is defined in the request. See also
/// CloudScriptRegisterHttpFunctionAsync, CloudScriptRegisterQueuedFunctionAsync.
///
/// If successful, call <see cref="PFCloudScriptExecuteFunctionGetResult"/> to get the result.
/// </remarks>
HRESULT PFCloudScriptExecuteFunctionAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFCloudScriptExecuteFunctionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ExecuteFunction call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCloudScriptExecuteFunctionGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCloudScriptExecuteFunctionAsync call.
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
HRESULT PFCloudScriptExecuteFunctionGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCloudScriptExecuteFunctionResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Gets registered Azure Functions for a given title id and function name.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also CloudScriptListFunctionsAsync, CloudScriptListHttpFunctionsAsync, CloudScriptListQueuedFunctionsAsync,
/// CloudScriptRegisterHttpFunctionAsync, CloudScriptRegisterQueuedFunctionAsync.
///
/// If successful, call <see cref="PFCloudScriptGetFunctionGetResult"/> to get the result.
/// </remarks>
HRESULT PFCloudScriptGetFunctionAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFCloudScriptGetFunctionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a GetFunction call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCloudScriptGetFunctionGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCloudScriptGetFunctionAsync call.
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
HRESULT PFCloudScriptGetFunctionGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCloudScriptGetFunctionResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Lists all currently registered Azure Functions for a given title.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also CloudScriptListHttpFunctionsAsync, CloudScriptListQueuedFunctionsAsync, CloudScriptRegisterHttpFunctionAsync,
/// CloudScriptRegisterQueuedFunctionAsync.
///
/// If successful, call <see cref="PFCloudScriptListFunctionsGetResult"/> to get the result.
/// </remarks>
HRESULT PFCloudScriptListFunctionsAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFCloudScriptListFunctionsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ListFunctions call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCloudScriptListFunctionsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCloudScriptListFunctionsAsync call.
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
HRESULT PFCloudScriptListFunctionsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCloudScriptListFunctionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Lists all currently registered HTTP triggered Azure Functions for a given title.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// A title can have many functions, ListHttpFunctions will return a list of all the currently registered
/// HTTP triggered functions for a given title. See also CloudScriptListFunctionsAsync, CloudScriptListQueuedFunctionsAsync,
/// CloudScriptRegisterHttpFunctionAsync.
///
/// If successful, call <see cref="PFCloudScriptListHttpFunctionsGetResult"/> to get the result.
/// </remarks>
HRESULT PFCloudScriptListHttpFunctionsAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFCloudScriptListFunctionsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ListHttpFunctions call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCloudScriptListHttpFunctionsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCloudScriptListHttpFunctionsAsync call.
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
HRESULT PFCloudScriptListHttpFunctionsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCloudScriptListHttpFunctionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Lists all currently registered Queue triggered Azure Functions for a given title.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also CloudScriptListFunctionsAsync, CloudScriptListHttpFunctionsAsync, CloudScriptRegisterQueuedFunctionAsync.
///
/// If successful, call <see cref="PFCloudScriptListQueuedFunctionsGetResult"/> to get the result.
/// </remarks>
HRESULT PFCloudScriptListQueuedFunctionsAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFCloudScriptListFunctionsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ListQueuedFunctions call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFCloudScriptListQueuedFunctionsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFCloudScriptListQueuedFunctionsAsync call.
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
HRESULT PFCloudScriptListQueuedFunctionsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFCloudScriptListQueuedFunctionsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Generate an entity PlayStream event for the provided function result.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also CloudScriptPostFunctionResultForFunctionExecutionAsync, CloudScriptPostFunctionResultForPlayerTriggeredActionAsync,
/// CloudScriptPostFunctionResultForScheduledTaskAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFCloudScriptPostFunctionResultForEntityTriggeredActionAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFCloudScriptPostFunctionResultForEntityTriggeredActionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Generate an entity PlayStream event for the provided function result.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also CloudScriptPostFunctionResultForEntityTriggeredActionAsync, CloudScriptPostFunctionResultForPlayerTriggeredActionAsync,
/// CloudScriptPostFunctionResultForScheduledTaskAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFCloudScriptPostFunctionResultForFunctionExecutionAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFCloudScriptPostFunctionResultForFunctionExecutionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Generate a player PlayStream event for the provided function result.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also CloudScriptPostFunctionResultForEntityTriggeredActionAsync, CloudScriptPostFunctionResultForFunctionExecutionAsync,
/// CloudScriptPostFunctionResultForScheduledTaskAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFCloudScriptPostFunctionResultForPlayerTriggeredActionAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Generate a PlayStream event for the provided function result.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also CloudScriptPostFunctionResultForEntityTriggeredActionAsync, CloudScriptPostFunctionResultForFunctionExecutionAsync,
/// CloudScriptPostFunctionResultForPlayerTriggeredActionAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFCloudScriptPostFunctionResultForScheduledTaskAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFCloudScriptPostFunctionResultForScheduledTaskRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Registers an HTTP triggered Azure function with a title.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also CloudScriptExecuteFunctionAsync, CloudScriptListFunctionsAsync, CloudScriptListHttpFunctionsAsync,
/// CloudScriptRegisterQueuedFunctionAsync, CloudScriptUnregisterFunctionAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFCloudScriptRegisterHttpFunctionAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFCloudScriptRegisterHttpFunctionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Registers a queue triggered Azure Function with a title.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// A title can have many functions, RegisterQueuedFunction associates a function name with a queue name
/// and connection string. See also CloudScriptExecuteFunctionAsync, CloudScriptListFunctionsAsync, CloudScriptListQueuedFunctionsAsync,
/// CloudScriptPostFunctionResultForEntityTriggeredActionAsync, CloudScriptPostFunctionResultForFunctionExecutionAsync,
/// CloudScriptPostFunctionResultForPlayerTriggeredActionAsync, CloudScriptPostFunctionResultForScheduledTaskAsync,
/// CloudScriptRegisterHttpFunctionAsync, CloudScriptUnregisterFunctionAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFCloudScriptRegisterQueuedFunctionAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFCloudScriptRegisterQueuedFunctionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Unregisters an Azure Function with a title.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also CloudScriptRegisterHttpFunctionAsync, CloudScriptRegisterQueuedFunctionAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFCloudScriptUnregisterFunctionAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFCloudScriptUnregisterFunctionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif


}