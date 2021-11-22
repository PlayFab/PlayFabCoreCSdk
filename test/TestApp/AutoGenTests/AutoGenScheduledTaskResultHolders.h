#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct CreateTaskResultHolder : public XAsyncResult, public std::enable_shared_from_this<CreateTaskResultHolder>
{
    CreateTaskResultHolder() = default;
    CreateTaskResultHolder(const CreateTaskResultHolder&) = delete;
    CreateTaskResultHolder(CreateTaskResultHolder&&) = default;
    CreateTaskResultHolder& operator=(const CreateTaskResultHolder&) = delete;
    CreateTaskResultHolder& operator=(CreateTaskResultHolder&&) = default;
    ~CreateTaskResultHolder() = default;

    PFScheduledTaskCreateTaskResult* result{ nullptr };
};

struct GetActionsOnPlayersInSegmentTaskInstanceResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetActionsOnPlayersInSegmentTaskInstanceResultHolder>
{
    GetActionsOnPlayersInSegmentTaskInstanceResultHolder() = default;
    GetActionsOnPlayersInSegmentTaskInstanceResultHolder(const GetActionsOnPlayersInSegmentTaskInstanceResultHolder&) = delete;
    GetActionsOnPlayersInSegmentTaskInstanceResultHolder(GetActionsOnPlayersInSegmentTaskInstanceResultHolder&&) = default;
    GetActionsOnPlayersInSegmentTaskInstanceResultHolder& operator=(const GetActionsOnPlayersInSegmentTaskInstanceResultHolder&) = delete;
    GetActionsOnPlayersInSegmentTaskInstanceResultHolder& operator=(GetActionsOnPlayersInSegmentTaskInstanceResultHolder&&) = default;
    ~GetActionsOnPlayersInSegmentTaskInstanceResultHolder() = default;

    PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult* result{ nullptr };
};

struct GetCloudScriptTaskInstanceResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetCloudScriptTaskInstanceResultHolder>
{
    GetCloudScriptTaskInstanceResultHolder() = default;
    GetCloudScriptTaskInstanceResultHolder(const GetCloudScriptTaskInstanceResultHolder&) = delete;
    GetCloudScriptTaskInstanceResultHolder(GetCloudScriptTaskInstanceResultHolder&&) = default;
    GetCloudScriptTaskInstanceResultHolder& operator=(const GetCloudScriptTaskInstanceResultHolder&) = delete;
    GetCloudScriptTaskInstanceResultHolder& operator=(GetCloudScriptTaskInstanceResultHolder&&) = default;
    ~GetCloudScriptTaskInstanceResultHolder() = default;

    PFScheduledTaskGetCloudScriptTaskInstanceResult* result{ nullptr };
};

struct GetTaskInstancesResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetTaskInstancesResultHolder>
{
    GetTaskInstancesResultHolder() = default;
    GetTaskInstancesResultHolder(const GetTaskInstancesResultHolder&) = delete;
    GetTaskInstancesResultHolder(GetTaskInstancesResultHolder&&) = default;
    GetTaskInstancesResultHolder& operator=(const GetTaskInstancesResultHolder&) = delete;
    GetTaskInstancesResultHolder& operator=(GetTaskInstancesResultHolder&&) = default;
    ~GetTaskInstancesResultHolder() = default;

    PFScheduledTaskGetTaskInstancesResult* result{ nullptr };
};

struct GetTasksResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetTasksResultHolder>
{
    GetTasksResultHolder() = default;
    GetTasksResultHolder(const GetTasksResultHolder&) = delete;
    GetTasksResultHolder(GetTasksResultHolder&&) = default;
    GetTasksResultHolder& operator=(const GetTasksResultHolder&) = delete;
    GetTasksResultHolder& operator=(GetTasksResultHolder&&) = default;
    ~GetTasksResultHolder() = default;

    PFScheduledTaskGetTasksResult* result{ nullptr };
};

struct RunTaskResultHolder : public XAsyncResult, public std::enable_shared_from_this<RunTaskResultHolder>
{
    RunTaskResultHolder() = default;
    RunTaskResultHolder(const RunTaskResultHolder&) = delete;
    RunTaskResultHolder(RunTaskResultHolder&&) = default;
    RunTaskResultHolder& operator=(const RunTaskResultHolder&) = delete;
    RunTaskResultHolder& operator=(RunTaskResultHolder&&) = default;
    ~RunTaskResultHolder() = default;

    PFScheduledTaskRunTaskResult* result{ nullptr };
};


}
