#pragma once

#include "ScheduledTaskDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace ScheduledTask
{

class ScheduledTaskAPI
{
public:
    ScheduledTaskAPI() = delete;
    ScheduledTaskAPI(const ScheduledTaskAPI& source) = delete;
    ScheduledTaskAPI& operator=(const ScheduledTaskAPI& source) = delete;
    ~ScheduledTaskAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<void> AdminAbortTaskInstance(SharedPtr<GlobalState const> state, const AbortTaskInstanceRequest& request, const TaskQueue& queue);
    static AsyncOp<CreateTaskResult> AdminCreateActionsOnPlayersInSegmentTask(SharedPtr<GlobalState const> state, const CreateActionsOnPlayerSegmentTaskRequest& request, const TaskQueue& queue);
    static AsyncOp<CreateTaskResult> AdminCreateCloudScriptTask(SharedPtr<GlobalState const> state, const CreateCloudScriptTaskRequest& request, const TaskQueue& queue);
    static AsyncOp<CreateTaskResult> AdminCreateInsightsScheduledScalingTask(SharedPtr<GlobalState const> state, const CreateInsightsScheduledScalingTaskRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminDeleteTask(SharedPtr<GlobalState const> state, const DeleteTaskRequest& request, const TaskQueue& queue);
    static AsyncOp<GetActionsOnPlayersInSegmentTaskInstanceResult> AdminGetActionsOnPlayersInSegmentTaskInstance(SharedPtr<GlobalState const> state, const GetTaskInstanceRequest& request, const TaskQueue& queue);
    static AsyncOp<GetCloudScriptTaskInstanceResult> AdminGetCloudScriptTaskInstance(SharedPtr<GlobalState const> state, const GetTaskInstanceRequest& request, const TaskQueue& queue);
    static AsyncOp<GetTaskInstancesResult> AdminGetTaskInstances(SharedPtr<GlobalState const> state, const GetTaskInstancesRequest& request, const TaskQueue& queue);
    static AsyncOp<GetTasksResult> AdminGetTasks(SharedPtr<GlobalState const> state, const GetTasksRequest& request, const TaskQueue& queue);
    static AsyncOp<RunTaskResult> AdminRunTask(SharedPtr<GlobalState const> state, const RunTaskRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AdminUpdateTask(SharedPtr<GlobalState const> state, const UpdateTaskRequest& request, const TaskQueue& queue);
};

} // namespace ScheduledTask
} // namespace PlayFab
