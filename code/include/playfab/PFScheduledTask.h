// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFScheduledTaskDataModels.h>
#include <playfab/PFGlobal.h>
#include <playfab/PFTitlePlayer.h>

extern "C"
{

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Abort an ongoing task instance.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If the task instance has already completed, there will be no-op. See also AdminGetActionsOnPlayersInSegmentTaskInstanceAsync,
/// AdminGetCloudScriptTaskInstanceAsync, AdminGetTaskInstancesAsync, AdminRunTaskAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFScheduledTaskAdminAbortTaskInstanceAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFScheduledTaskAbortTaskInstanceRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Create an ActionsOnPlayersInSegment task, which iterates through all players in a segment to execute
/// action.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Task name is unique within a title. Using a task name that's already taken will cause a name conflict
/// error. Too many create-task requests within a short time will cause a create conflict error. See also
/// AdminCreateCloudScriptTaskAsync, AdminDeleteTaskAsync, AdminGetTasksAsync, AdminRunTaskAsync, AdminUpdateTaskAsync.
///
/// If successful, call <see cref="PFScheduledTaskAdminCreateActionsOnPlayersInSegmentTaskGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFScheduledTaskAdminCreateActionsOnPlayersInSegmentTaskAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminCreateActionsOnPlayersInSegmentTask call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFScheduledTaskAdminCreateActionsOnPlayersInSegmentTaskGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFScheduledTaskAdminCreateActionsOnPlayersInSegmentTaskAsync call.
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
HRESULT PFScheduledTaskAdminCreateActionsOnPlayersInSegmentTaskGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFScheduledTaskCreateTaskResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Create a CloudScript task, which can run a CloudScript on a schedule.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Task name is unique within a title. Using a task name that's already taken will cause a name conflict
/// error. Too many create-task requests within a short time will cause a create conflict error. See also
/// AdminCreateActionsOnPlayersInSegmentTaskAsync, AdminDeleteTaskAsync, AdminGetTasksAsync, AdminRunTaskAsync,
/// AdminUpdateTaskAsync.
///
/// If successful, call <see cref="PFScheduledTaskAdminCreateCloudScriptTaskGetResult"/> to get the result.
/// </remarks>
HRESULT PFScheduledTaskAdminCreateCloudScriptTaskAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFScheduledTaskCreateCloudScriptTaskRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminCreateCloudScriptTask call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFScheduledTaskAdminCreateCloudScriptTaskGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFScheduledTaskAdminCreateCloudScriptTaskAsync call.
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
HRESULT PFScheduledTaskAdminCreateCloudScriptTaskGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFScheduledTaskCreateTaskResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Create a Insights Scheduled Scaling task, which can scale Insights Performance Units on a schedule
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Task name is unique within a title. Using a task name that's already taken will cause a name conflict
/// error. Too many create-task requests within a short time will cause a create conflict error. See also
/// AdminCreateActionsOnPlayersInSegmentTaskAsync, AdminDeleteTaskAsync, AdminGetTasksAsync, AdminRunTaskAsync,
/// AdminUpdateTaskAsync.
///
/// If successful, call <see cref="PFScheduledTaskAdminCreateInsightsScheduledScalingTaskGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFScheduledTaskAdminCreateInsightsScheduledScalingTaskAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFScheduledTaskCreateInsightsScheduledScalingTaskRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminCreateInsightsScheduledScalingTask call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFScheduledTaskAdminCreateInsightsScheduledScalingTaskGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFScheduledTaskAdminCreateInsightsScheduledScalingTaskAsync call.
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
HRESULT PFScheduledTaskAdminCreateInsightsScheduledScalingTaskGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFScheduledTaskCreateTaskResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Delete a task.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// After a task is deleted, for tracking purposes, the task instances belonging to this task will still
/// remain. They will become orphaned and does not belongs to any task. Executions of any in-progress
/// task instances will continue. If the task specified does not exist, the deletion is considered a success.
/// See also AdminCreateActionsOnPlayersInSegmentTaskAsync, AdminCreateCloudScriptAzureFunctionsTaskAsync,
/// AdminCreateCloudScriptTaskAsync, AdminGetTasksAsync, AdminRunTaskAsync, AdminUpdateTaskAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFScheduledTaskAdminDeleteTaskAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFScheduledTaskDeleteTaskRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Get information about a ActionsOnPlayersInSegment task instance.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// The result includes detail information that's specific to an ActionsOnPlayersInSegment task. To get
/// a list of task instances with generic basic information, use GetTaskInstances. See also AdminAbortTaskInstanceAsync,
/// AdminGetCloudScriptAzureFunctionsTaskInstanceAsync, AdminGetCloudScriptTaskInstanceAsync, AdminGetTaskInstancesAsync,
/// AdminRunTaskAsync.
///
/// If successful, call <see cref="PFScheduledTaskAdminGetActionsOnPlayersInSegmentTaskInstanceGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFScheduledTaskAdminGetActionsOnPlayersInSegmentTaskInstanceAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFScheduledTaskGetTaskInstanceRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetActionsOnPlayersInSegmentTaskInstance call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFScheduledTaskAdminGetActionsOnPlayersInSegmentTaskInstanceGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFScheduledTaskAdminGetActionsOnPlayersInSegmentTaskInstanceAsync call.
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
HRESULT PFScheduledTaskAdminGetActionsOnPlayersInSegmentTaskInstanceGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Get detail information about a CloudScript task instance.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// The result includes detail information that's specific to a CloudScript task. Only CloudScript tasks
/// configured as 'Run Cloud Script function once' will be retrieved. To get a list of task instances
/// by task, status, or time range, use GetTaskInstances. See also AdminAbortTaskInstanceAsync, AdminGetActionsOnPlayersInSegmentTaskInstanceAsync,
/// AdminGetCloudScriptAzureFunctionsTaskInstanceAsync, AdminGetTaskInstancesAsync, AdminRunTaskAsync.
///
/// If successful, call <see cref="PFScheduledTaskAdminGetCloudScriptTaskInstanceGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFScheduledTaskAdminGetCloudScriptTaskInstanceAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFScheduledTaskGetTaskInstanceRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetCloudScriptTaskInstance call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFScheduledTaskAdminGetCloudScriptTaskInstanceGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFScheduledTaskAdminGetCloudScriptTaskInstanceAsync call.
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
HRESULT PFScheduledTaskAdminGetCloudScriptTaskInstanceGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFScheduledTaskGetCloudScriptTaskInstanceResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Query for task instances by task, status, or time range.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Only the most recent 100 task instances are returned, ordered by start time descending. The results
/// are generic basic information for task instances. To get detail information specific to each task
/// type, use Get*TaskInstance based on its corresponding task type. See also AdminAbortTaskInstanceAsync,
/// AdminGetActionsOnPlayersInSegmentTaskInstanceAsync, AdminGetCloudScriptAzureFunctionsTaskInstanceAsync,
/// AdminGetCloudScriptTaskInstanceAsync, AdminRunTaskAsync.
///
/// If successful, call <see cref="PFScheduledTaskAdminGetTaskInstancesGetResult"/> to get the result.
/// </remarks>
HRESULT PFScheduledTaskAdminGetTaskInstancesAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFScheduledTaskGetTaskInstancesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetTaskInstances call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFScheduledTaskAdminGetTaskInstancesGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFScheduledTaskAdminGetTaskInstancesAsync call.
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
HRESULT PFScheduledTaskAdminGetTaskInstancesGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFScheduledTaskGetTaskInstancesResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Get definition information on a specified task or all tasks within a title.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminCreateCloudScriptAzureFunctionsTaskAsync, AdminCreateCloudScriptTaskAsync, AdminDeleteTaskAsync,
/// AdminGetTasksAsync, AdminRunTaskAsync, AdminUpdateTaskAsync.
///
/// If successful, call <see cref="PFScheduledTaskAdminGetTasksGetResult"/> to get the result.
/// </remarks>
HRESULT PFScheduledTaskAdminGetTasksAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFScheduledTaskGetTasksRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetTasks call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFScheduledTaskAdminGetTasksGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFScheduledTaskAdminGetTasksAsync call.
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
HRESULT PFScheduledTaskAdminGetTasksGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFScheduledTaskGetTasksResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Run a task immediately regardless of its schedule.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// The returned task instance ID can be used to query for task execution status. See also AdminCreateActionsOnPlayersInSegmentTaskAsync,
/// AdminCreateCloudScriptAzureFunctionsTaskAsync, AdminCreateCloudScriptTaskAsync, AdminDeleteTaskAsync,
/// AdminGetTasksAsync, AdminUpdateTaskAsync.
///
/// If successful, call <see cref="PFScheduledTaskAdminRunTaskGetResult"/> to get the result.
/// </remarks>
HRESULT PFScheduledTaskAdminRunTaskAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFScheduledTaskRunTaskRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminRunTask call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFScheduledTaskAdminRunTaskGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFScheduledTaskAdminRunTaskAsync call.
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
HRESULT PFScheduledTaskAdminRunTaskGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFScheduledTaskRunTaskResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Update an existing task.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Note that when calling this API, all properties of the task have to be provided, including properties
/// that you do not want to change. Parameters not specified would be set to default value. If the task
/// name in the update request is new, a task rename operation will be executed before updating other
/// fields of the task. WARNING: Renaming of a task may break logics where the task name is used as an
/// identifier. See also AdminCreateActionsOnPlayersInSegmentTaskAsync, AdminCreateCloudScriptTaskAsync,
/// AdminDeleteTaskAsync, AdminGetTasksAsync, AdminRunTaskAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFScheduledTaskAdminUpdateTaskAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFScheduledTaskUpdateTaskRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif


}