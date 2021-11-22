#include "stdafx.h"
#include "ScheduledTask.h"
#include "GlobalState.h"
#include "TitlePlayer.h"

namespace PlayFab
{
namespace ScheduledTask
{


AsyncOp<void> ScheduledTaskAPI::AdminAbortTaskInstance(
    SharedPtr<GlobalState const> state,
    const AbortTaskInstanceRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/AbortTaskInstance" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<void>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            return S_OK;
        }
        else
        {
            return Result<void>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<CreateTaskResult> ScheduledTaskAPI::AdminCreateActionsOnPlayersInSegmentTask(
    SharedPtr<GlobalState const> state,
    const CreateActionsOnPlayerSegmentTaskRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/CreateActionsOnPlayersInSegmentTask" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<CreateTaskResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            CreateTaskResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<CreateTaskResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<CreateTaskResult> ScheduledTaskAPI::AdminCreateCloudScriptTask(
    SharedPtr<GlobalState const> state,
    const CreateCloudScriptTaskRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/CreateCloudScriptTask" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<CreateTaskResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            CreateTaskResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<CreateTaskResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<CreateTaskResult> ScheduledTaskAPI::AdminCreateInsightsScheduledScalingTask(
    SharedPtr<GlobalState const> state,
    const CreateInsightsScheduledScalingTaskRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/CreateInsightsScheduledScalingTask" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<CreateTaskResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            CreateTaskResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<CreateTaskResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<void> ScheduledTaskAPI::AdminDeleteTask(
    SharedPtr<GlobalState const> state,
    const DeleteTaskRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/DeleteTask" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<void>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            return S_OK;
        }
        else
        {
            return Result<void>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetActionsOnPlayersInSegmentTaskInstanceResult> ScheduledTaskAPI::AdminGetActionsOnPlayersInSegmentTaskInstance(
    SharedPtr<GlobalState const> state,
    const GetTaskInstanceRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/GetActionsOnPlayersInSegmentTaskInstance" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetActionsOnPlayersInSegmentTaskInstanceResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetActionsOnPlayersInSegmentTaskInstanceResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetActionsOnPlayersInSegmentTaskInstanceResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetCloudScriptTaskInstanceResult> ScheduledTaskAPI::AdminGetCloudScriptTaskInstance(
    SharedPtr<GlobalState const> state,
    const GetTaskInstanceRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/GetCloudScriptTaskInstance" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetCloudScriptTaskInstanceResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetCloudScriptTaskInstanceResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetCloudScriptTaskInstanceResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetTaskInstancesResult> ScheduledTaskAPI::AdminGetTaskInstances(
    SharedPtr<GlobalState const> state,
    const GetTaskInstancesRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/GetTaskInstances" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetTaskInstancesResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetTaskInstancesResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetTaskInstancesResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetTasksResult> ScheduledTaskAPI::AdminGetTasks(
    SharedPtr<GlobalState const> state,
    const GetTasksRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/GetTasks" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetTasksResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetTasksResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetTasksResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<RunTaskResult> ScheduledTaskAPI::AdminRunTask(
    SharedPtr<GlobalState const> state,
    const RunTaskRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/RunTask" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<RunTaskResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            RunTaskResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<RunTaskResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<void> ScheduledTaskAPI::AdminUpdateTask(
    SharedPtr<GlobalState const> state,
    const UpdateTaskRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/UpdateTask" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<void>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            return S_OK;
        }
        else
        {
            return Result<void>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

} // namespace ScheduledTask
} // namespace PlayFab
