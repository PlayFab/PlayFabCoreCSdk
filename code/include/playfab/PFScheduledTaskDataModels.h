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
/// TaskInstanceStatus enum.
/// </summary>
enum class PFScheduledTaskTaskInstanceStatus : uint32_t
{
    Succeeded,
    Starting,
    InProgress,
    Failed,
    Aborted,
    Stalled
};

/// <summary>
/// ScheduledTaskType enum.
/// </summary>
enum class PFScheduledTaskScheduledTaskType : uint32_t
{
    CloudScript,
    ActionsOnPlayerSegment,
    CloudScriptAzureFunctions,
    InsightsScheduledScaling
};

/// <summary>
/// PFScheduledTaskAbortTaskInstanceRequest data model. If the task instance has already completed, there
/// will be no-op.
/// </summary>
typedef struct PFScheduledTaskAbortTaskInstanceRequest
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
    /// ID of a task instance that is being aborted.
    /// </summary>
    _Null_terminated_ const char* taskInstanceId;

} PFScheduledTaskAbortTaskInstanceRequest;

/// <summary>
/// PFScheduledTaskActionsOnPlayersInSegmentTaskParameter data model.
/// </summary>
typedef struct PFScheduledTaskActionsOnPlayersInSegmentTaskParameter
{
    /// <summary>
    /// ID of the action to perform on each player in segment.
    /// </summary>
    _Null_terminated_ const char* actionId;

    /// <summary>
    /// ID of the segment to perform actions on.
    /// </summary>
    _Null_terminated_ const char* segmentId;

} PFScheduledTaskActionsOnPlayersInSegmentTaskParameter;

/// <summary>
/// PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequest data model. Task name is unique within a title.
/// Using a task name that's already taken will cause a name conflict error. Too many create-task requests
/// within a short time will cause a create conflict error.
/// </summary>
typedef struct PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequest
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
    /// (Optional) Description the task.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* description;

    /// <summary>
    /// Whether the schedule is active. Inactive schedule will not trigger task execution.
    /// </summary>
    bool isActive;

    /// <summary>
    /// Name of the task. This is a unique identifier for tasks in the title.
    /// </summary>
    _Null_terminated_ const char* name;

    /// <summary>
    /// Task details related to segment and action.
    /// </summary>
    PFScheduledTaskActionsOnPlayersInSegmentTaskParameter const* parameter;

    /// <summary>
    /// (Optional) Cron expression for the run schedule of the task. The expression should be in UTC.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* schedule;

} PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequest;

/// <summary>
/// PFScheduledTaskCreateTaskResult data model.
/// </summary>
typedef struct PFScheduledTaskCreateTaskResult
{
    /// <summary>
    /// (Optional) ID of the task.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* taskId;

} PFScheduledTaskCreateTaskResult;

/// <summary>
/// PFScheduledTaskCloudScriptTaskParameter data model.
/// </summary>
typedef struct PFScheduledTaskCloudScriptTaskParameter
{
    /// <summary>
    /// (Optional) Argument to pass to the CloudScript function.
    /// </summary>
    PFJsonObject argument;

    /// <summary>
    /// (Optional) Name of the CloudScript function to execute.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* functionName;

} PFScheduledTaskCloudScriptTaskParameter;

/// <summary>
/// PFScheduledTaskCreateCloudScriptTaskRequest data model. Task name is unique within a title. Using
/// a task name that's already taken will cause a name conflict error. Too many create-task requests within
/// a short time will cause a create conflict error.
/// </summary>
typedef struct PFScheduledTaskCreateCloudScriptTaskRequest
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
    /// (Optional) Description the task.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* description;

    /// <summary>
    /// Whether the schedule is active. Inactive schedule will not trigger task execution.
    /// </summary>
    bool isActive;

    /// <summary>
    /// Name of the task. This is a unique identifier for tasks in the title.
    /// </summary>
    _Null_terminated_ const char* name;

    /// <summary>
    /// Task details related to CloudScript.
    /// </summary>
    PFScheduledTaskCloudScriptTaskParameter const* parameter;

    /// <summary>
    /// (Optional) Cron expression for the run schedule of the task. The expression should be in UTC.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* schedule;

} PFScheduledTaskCreateCloudScriptTaskRequest;

/// <summary>
/// PFScheduledTaskInsightsScalingTaskParameter data model.
/// </summary>
typedef struct PFScheduledTaskInsightsScalingTaskParameter
{
    /// <summary>
    /// Insights Performance Level to scale to.
    /// </summary>
    int32_t level;

} PFScheduledTaskInsightsScalingTaskParameter;

/// <summary>
/// PFScheduledTaskCreateInsightsScheduledScalingTaskRequest data model. Task name is unique within a
/// title. Using a task name that's already taken will cause a name conflict error. Too many create-task
/// requests within a short time will cause a create conflict error.
/// </summary>
typedef struct PFScheduledTaskCreateInsightsScheduledScalingTaskRequest
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
    /// (Optional) Description the task.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* description;

    /// <summary>
    /// Whether the schedule is active. Inactive schedule will not trigger task execution.
    /// </summary>
    bool isActive;

    /// <summary>
    /// Name of the task. This is a unique identifier for tasks in the title.
    /// </summary>
    _Null_terminated_ const char* name;

    /// <summary>
    /// Task details related to Insights Scaling.
    /// </summary>
    PFScheduledTaskInsightsScalingTaskParameter const* parameter;

    /// <summary>
    /// (Optional) Cron expression for the run schedule of the task. The expression should be in UTC.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* schedule;

} PFScheduledTaskCreateInsightsScheduledScalingTaskRequest;

/// <summary>
/// PFScheduledTaskDeleteTaskRequest data model. After a task is deleted, for tracking purposes, the
/// task instances belonging to this task will still remain. They will become orphaned and does not belongs
/// to any task. Executions of any in-progress task instances will continue. If the task specified does
/// not exist, the deletion is considered a success.
/// </summary>
typedef struct PFScheduledTaskDeleteTaskRequest
{
    /// <summary>
    /// (Optional) Specify either the task ID or the name of task to be deleted.
    /// </summary>
    _Maybenull_ PFNameIdentifier const* identifier;

} PFScheduledTaskDeleteTaskRequest;

/// <summary>
/// PFScheduledTaskGetTaskInstanceRequest data model. The result includes detail information that's specific
/// to a CloudScript task. Only CloudScript tasks configured as "Run Cloud Script function once" will
/// be retrieved. To get a list of task instances by task, status, or time range, use GetTaskInstances.
/// </summary>
typedef struct PFScheduledTaskGetTaskInstanceRequest
{
    /// <summary>
    /// ID of the requested task instance.
    /// </summary>
    _Null_terminated_ const char* taskInstanceId;

} PFScheduledTaskGetTaskInstanceRequest;

/// <summary>
/// PFScheduledTaskActionsOnPlayersInSegmentTaskSummary data model.
/// </summary>
typedef struct PFScheduledTaskActionsOnPlayersInSegmentTaskSummary
{
    /// <summary>
    /// (Optional) UTC timestamp when the task completed.
    /// </summary>
    _Maybenull_ time_t const* completedAt;

    /// <summary>
    /// (Optional) Error message for last processing attempt, if an error occured.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* errorMessage;

    /// <summary>
    /// (Optional) Flag indicating if the error was fatal, if false job will be retried.
    /// </summary>
    _Maybenull_ bool const* errorWasFatal;

    /// <summary>
    /// (Optional) Estimated time remaining in seconds.
    /// </summary>
    _Maybenull_ double const* estimatedSecondsRemaining;

    /// <summary>
    /// (Optional) Progress represented as percentage.
    /// </summary>
    _Maybenull_ double const* percentComplete;

    /// <summary>
    /// (Optional) If manually scheduled, ID of user who scheduled the task.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* scheduledByUserId;

    /// <summary>
    /// UTC timestamp when the task started.
    /// </summary>
    time_t startedAt;

    /// <summary>
    /// (Optional) Current status of the task instance.
    /// </summary>
    _Maybenull_ PFScheduledTaskTaskInstanceStatus const* status;

    /// <summary>
    /// (Optional) Identifier of the task this instance belongs to.
    /// </summary>
    _Maybenull_ PFNameIdentifier const* taskIdentifier;

    /// <summary>
    /// (Optional) ID of the task instance.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* taskInstanceId;

    /// <summary>
    /// (Optional) Total players in segment when task was started.
    /// </summary>
    _Maybenull_ int32_t const* totalPlayersInSegment;

    /// <summary>
    /// (Optional) Total number of players that have had the actions applied to.
    /// </summary>
    _Maybenull_ int32_t const* totalPlayersProcessed;

} PFScheduledTaskActionsOnPlayersInSegmentTaskSummary;

/// <summary>
/// PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult data model.
/// </summary>
typedef struct PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult
{
    /// <summary>
    /// (Optional) Parameter of this task instance.
    /// </summary>
    _Maybenull_ PFScheduledTaskActionsOnPlayersInSegmentTaskParameter const* parameter;

    /// <summary>
    /// (Optional) Status summary of the actions-on-players-in-segment task instance.
    /// </summary>
    _Maybenull_ PFScheduledTaskActionsOnPlayersInSegmentTaskSummary const* summary;

} PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult;

/// <summary>
/// PFScheduledTaskCloudScriptTaskSummary data model.
/// </summary>
typedef struct PFScheduledTaskCloudScriptTaskSummary
{
    /// <summary>
    /// (Optional) UTC timestamp when the task completed.
    /// </summary>
    _Maybenull_ time_t const* completedAt;

    /// <summary>
    /// (Optional) Estimated time remaining in seconds.
    /// </summary>
    _Maybenull_ double const* estimatedSecondsRemaining;

    /// <summary>
    /// (Optional) Progress represented as percentage.
    /// </summary>
    _Maybenull_ double const* percentComplete;

    /// <summary>
    /// (Optional) Result of CloudScript execution.
    /// </summary>
    _Maybenull_ PFExecuteCloudScriptResult const* result;

    /// <summary>
    /// (Optional) If manually scheduled, ID of user who scheduled the task.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* scheduledByUserId;

    /// <summary>
    /// UTC timestamp when the task started.
    /// </summary>
    time_t startedAt;

    /// <summary>
    /// (Optional) Current status of the task instance.
    /// </summary>
    _Maybenull_ PFScheduledTaskTaskInstanceStatus const* status;

    /// <summary>
    /// (Optional) Identifier of the task this instance belongs to.
    /// </summary>
    _Maybenull_ PFNameIdentifier const* taskIdentifier;

    /// <summary>
    /// (Optional) ID of the task instance.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* taskInstanceId;

} PFScheduledTaskCloudScriptTaskSummary;

/// <summary>
/// PFScheduledTaskGetCloudScriptTaskInstanceResult data model.
/// </summary>
typedef struct PFScheduledTaskGetCloudScriptTaskInstanceResult
{
    /// <summary>
    /// (Optional) Parameter of this task instance.
    /// </summary>
    _Maybenull_ PFScheduledTaskCloudScriptTaskParameter const* parameter;

    /// <summary>
    /// (Optional) Status summary of the CloudScript task instance.
    /// </summary>
    _Maybenull_ PFScheduledTaskCloudScriptTaskSummary const* summary;

} PFScheduledTaskGetCloudScriptTaskInstanceResult;

/// <summary>
/// PFScheduledTaskGetTaskInstancesRequest data model. Only the most recent 100 task instances are returned,
/// ordered by start time descending. The results are generic basic information for task instances. To
/// get detail information specific to each task type, use Get*TaskInstance based on its corresponding
/// task type.
/// </summary>
typedef struct PFScheduledTaskGetTaskInstancesRequest
{
    /// <summary>
    /// (Optional) Optional range-from filter for task instances' StartedAt timestamp.
    /// </summary>
    _Maybenull_ time_t const* startedAtRangeFrom;

    /// <summary>
    /// (Optional) Optional range-to filter for task instances' StartedAt timestamp.
    /// </summary>
    _Maybenull_ time_t const* startedAtRangeTo;

    /// <summary>
    /// (Optional) Optional filter for task instances that are of a specific status.
    /// </summary>
    _Maybenull_ PFScheduledTaskTaskInstanceStatus const* statusFilter;

    /// <summary>
    /// (Optional) Name or ID of the task whose instances are being queried. If not specified, return
    /// all task instances that satisfy conditions set by other filters.
    /// </summary>
    _Maybenull_ PFNameIdentifier const* taskIdentifier;

} PFScheduledTaskGetTaskInstancesRequest;

/// <summary>
/// PFScheduledTaskTaskInstanceBasicSummary data model.
/// </summary>
typedef struct PFScheduledTaskTaskInstanceBasicSummary
{
    /// <summary>
    /// (Optional) UTC timestamp when the task completed.
    /// </summary>
    _Maybenull_ time_t const* completedAt;

    /// <summary>
    /// (Optional) Error message for last processing attempt, if an error occured.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* errorMessage;

    /// <summary>
    /// (Optional) Estimated time remaining in seconds.
    /// </summary>
    _Maybenull_ double const* estimatedSecondsRemaining;

    /// <summary>
    /// (Optional) Progress represented as percentage.
    /// </summary>
    _Maybenull_ double const* percentComplete;

    /// <summary>
    /// (Optional) If manually scheduled, ID of user who scheduled the task.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* scheduledByUserId;

    /// <summary>
    /// UTC timestamp when the task started.
    /// </summary>
    time_t startedAt;

    /// <summary>
    /// (Optional) Current status of the task instance.
    /// </summary>
    _Maybenull_ PFScheduledTaskTaskInstanceStatus const* status;

    /// <summary>
    /// (Optional) Identifier of the task this instance belongs to.
    /// </summary>
    _Maybenull_ PFNameIdentifier const* taskIdentifier;

    /// <summary>
    /// (Optional) ID of the task instance.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* taskInstanceId;

    /// <summary>
    /// (Optional) Type of the task.
    /// </summary>
    _Maybenull_ PFScheduledTaskScheduledTaskType const* type;

} PFScheduledTaskTaskInstanceBasicSummary;

/// <summary>
/// PFScheduledTaskGetTaskInstancesResult data model.
/// </summary>
typedef struct PFScheduledTaskGetTaskInstancesResult
{
    /// <summary>
    /// (Optional) Basic status summaries of the queried task instances. Empty If no task instances meets
    /// the filter criteria. To get detailed status summary, use Get*TaskInstance API according to task
    /// type (e.g. GetActionsOnPlayersInSegmentTaskInstance).
    /// </summary>
    _Maybenull_ _Field_size_(summariesCount) PFScheduledTaskTaskInstanceBasicSummary const* const* summaries;

    /// <summary>
    /// Count of summaries
    /// </summary>
    uint32_t summariesCount;

} PFScheduledTaskGetTaskInstancesResult;

/// <summary>
/// PFScheduledTaskGetTasksRequest data model.
/// </summary>
typedef struct PFScheduledTaskGetTasksRequest
{
    /// <summary>
    /// (Optional) Provide either the task ID or the task name to get a specific task. If not specified,
    /// return all defined tasks.
    /// </summary>
    _Maybenull_ PFNameIdentifier const* identifier;

} PFScheduledTaskGetTasksRequest;

/// <summary>
/// PFScheduledTaskScheduledTask data model.
/// </summary>
typedef struct PFScheduledTaskScheduledTask
{
    /// <summary>
    /// (Optional) Description the task.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* description;

    /// <summary>
    /// Whether the schedule is active. Inactive schedule will not trigger task execution.
    /// </summary>
    bool isActive;

    /// <summary>
    /// (Optional) UTC time of last run.
    /// </summary>
    _Maybenull_ time_t const* lastRunTime;

    /// <summary>
    /// Name of the task. This is a unique identifier for tasks in the title.
    /// </summary>
    _Null_terminated_ const char* name;

    /// <summary>
    /// (Optional) UTC time of next run.
    /// </summary>
    _Maybenull_ time_t const* nextRunTime;

    /// <summary>
    /// (Optional) Task parameter. Different types of task have different parameter structure. See each
    /// task type's create API documentation for the details.
    /// </summary>
    PFJsonObject parameter;

    /// <summary>
    /// (Optional) Cron expression for the run schedule of the task. The expression should be in UTC.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* schedule;

    /// <summary>
    /// (Optional) ID of the task.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* taskId;

    /// <summary>
    /// (Optional) Task type.
    /// </summary>
    _Maybenull_ PFScheduledTaskScheduledTaskType const* type;

} PFScheduledTaskScheduledTask;

/// <summary>
/// PFScheduledTaskGetTasksResult data model.
/// </summary>
typedef struct PFScheduledTaskGetTasksResult
{
    /// <summary>
    /// (Optional) Result tasks. Empty if there is no task found.
    /// </summary>
    _Maybenull_ _Field_size_(tasksCount) PFScheduledTaskScheduledTask const* const* tasks;

    /// <summary>
    /// Count of tasks
    /// </summary>
    uint32_t tasksCount;

} PFScheduledTaskGetTasksResult;

/// <summary>
/// PFScheduledTaskRunTaskRequest data model. The returned task instance ID can be used to query for
/// task execution status.
/// </summary>
typedef struct PFScheduledTaskRunTaskRequest
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
    /// (Optional) Provide either the task ID or the task name to run a task.
    /// </summary>
    _Maybenull_ PFNameIdentifier const* identifier;

} PFScheduledTaskRunTaskRequest;

/// <summary>
/// PFScheduledTaskRunTaskResult data model.
/// </summary>
typedef struct PFScheduledTaskRunTaskResult
{
    /// <summary>
    /// (Optional) ID of the task instance that is started. This can be used in Get*TaskInstance (e.g.
    /// GetCloudScriptTaskInstance) API call to retrieve status for the task instance.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* taskInstanceId;

} PFScheduledTaskRunTaskResult;

/// <summary>
/// PFScheduledTaskUpdateTaskRequest data model. Note that when calling this API, all properties of the
/// task have to be provided, including properties that you do not want to change. Parameters not specified
/// would be set to default value. If the task name in the update request is new, a task rename operation
/// will be executed before updating other fields of the task. WARNING: Renaming of a task may break logics
/// where the task name is used as an identifier.
/// </summary>
typedef struct PFScheduledTaskUpdateTaskRequest
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
    /// (Optional) Description the task.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* description;

    /// <summary>
    /// (Optional) Specify either the task ID or the name of the task to be updated.
    /// </summary>
    _Maybenull_ PFNameIdentifier const* identifier;

    /// <summary>
    /// Whether the schedule is active. Inactive schedule will not trigger task execution.
    /// </summary>
    bool isActive;

    /// <summary>
    /// Name of the task. This is a unique identifier for tasks in the title.
    /// </summary>
    _Null_terminated_ const char* name;

    /// <summary>
    /// (Optional) Parameter object specific to the task type. See each task type's create API documentation
    /// for details.
    /// </summary>
    PFJsonObject parameter;

    /// <summary>
    /// (Optional) Cron expression for the run schedule of the task. The expression should be in UTC.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* schedule;

    /// <summary>
    /// Task type.
    /// </summary>
    PFScheduledTaskScheduledTaskType type;

} PFScheduledTaskUpdateTaskRequest;

#pragma pop_macro("IN")

}
