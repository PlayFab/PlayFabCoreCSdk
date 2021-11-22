#include "stdafx.h"
#include <playfab/PFScheduledTask.h>
#include "ScheduledTask.h"
#include "ApiAsyncProviders.h"
#include "GlobalState.h"
#include "Entity.h"

using namespace PlayFab;
using namespace PlayFab::ScheduledTask;

HRESULT PFScheduledTaskAdminAbortTaskInstanceAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFScheduledTaskAbortTaskInstanceRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&ScheduledTaskAPI::AdminAbortTaskInstance, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFScheduledTaskAdminCreateActionsOnPlayersInSegmentTaskAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&ScheduledTaskAPI::AdminCreateActionsOnPlayersInSegmentTask, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFScheduledTaskAdminCreateActionsOnPlayersInSegmentTaskGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFScheduledTaskAdminCreateActionsOnPlayersInSegmentTaskGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFScheduledTaskCreateTaskResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFScheduledTaskCreateTaskResult*>(buffer);

    return S_OK;
}

HRESULT PFScheduledTaskAdminCreateCloudScriptTaskAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFScheduledTaskCreateCloudScriptTaskRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&ScheduledTaskAPI::AdminCreateCloudScriptTask, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFScheduledTaskAdminCreateCloudScriptTaskGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFScheduledTaskAdminCreateCloudScriptTaskGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFScheduledTaskCreateTaskResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFScheduledTaskCreateTaskResult*>(buffer);

    return S_OK;
}

HRESULT PFScheduledTaskAdminCreateInsightsScheduledScalingTaskAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFScheduledTaskCreateInsightsScheduledScalingTaskRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&ScheduledTaskAPI::AdminCreateInsightsScheduledScalingTask, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFScheduledTaskAdminCreateInsightsScheduledScalingTaskGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFScheduledTaskAdminCreateInsightsScheduledScalingTaskGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFScheduledTaskCreateTaskResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFScheduledTaskCreateTaskResult*>(buffer);

    return S_OK;
}

HRESULT PFScheduledTaskAdminDeleteTaskAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFScheduledTaskDeleteTaskRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&ScheduledTaskAPI::AdminDeleteTask, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFScheduledTaskAdminGetActionsOnPlayersInSegmentTaskInstanceAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFScheduledTaskGetTaskInstanceRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&ScheduledTaskAPI::AdminGetActionsOnPlayersInSegmentTaskInstance, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFScheduledTaskAdminGetActionsOnPlayersInSegmentTaskInstanceGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFScheduledTaskAdminGetActionsOnPlayersInSegmentTaskInstanceGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult*>(buffer);

    return S_OK;
}

HRESULT PFScheduledTaskAdminGetCloudScriptTaskInstanceAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFScheduledTaskGetTaskInstanceRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&ScheduledTaskAPI::AdminGetCloudScriptTaskInstance, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFScheduledTaskAdminGetCloudScriptTaskInstanceGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFScheduledTaskAdminGetCloudScriptTaskInstanceGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFScheduledTaskGetCloudScriptTaskInstanceResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFScheduledTaskGetCloudScriptTaskInstanceResult*>(buffer);

    return S_OK;
}

HRESULT PFScheduledTaskAdminGetTaskInstancesAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFScheduledTaskGetTaskInstancesRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&ScheduledTaskAPI::AdminGetTaskInstances, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFScheduledTaskAdminGetTaskInstancesGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFScheduledTaskAdminGetTaskInstancesGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFScheduledTaskGetTaskInstancesResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFScheduledTaskGetTaskInstancesResult*>(buffer);

    return S_OK;
}

HRESULT PFScheduledTaskAdminGetTasksAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFScheduledTaskGetTasksRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&ScheduledTaskAPI::AdminGetTasks, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFScheduledTaskAdminGetTasksGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFScheduledTaskAdminGetTasksGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFScheduledTaskGetTasksResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFScheduledTaskGetTasksResult*>(buffer);

    return S_OK;
}

HRESULT PFScheduledTaskAdminRunTaskAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFScheduledTaskRunTaskRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&ScheduledTaskAPI::AdminRunTask, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFScheduledTaskAdminRunTaskGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFScheduledTaskAdminRunTaskGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFScheduledTaskRunTaskResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFScheduledTaskRunTaskResult*>(buffer);

    return S_OK;
}

HRESULT PFScheduledTaskAdminUpdateTaskAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFScheduledTaskUpdateTaskRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&ScheduledTaskAPI::AdminUpdateTask, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

