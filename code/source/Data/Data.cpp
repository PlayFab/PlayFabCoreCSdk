#include "stdafx.h"
#include "Data.h"
#include "GlobalState.h"
#include "TitlePlayer.h"

namespace PlayFab
{
namespace Data
{


AsyncOp<AbortFileUploadsResponse> DataAPI::AbortFileUploads(
    SharedPtr<Entity> entity,
    const AbortFileUploadsRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/File/AbortFileUploads" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<AbortFileUploadsResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            AbortFileUploadsResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<AbortFileUploadsResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<DeleteFilesResponse> DataAPI::DeleteFiles(
    SharedPtr<Entity> entity,
    const DeleteFilesRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/File/DeleteFiles" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<DeleteFilesResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            DeleteFilesResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<DeleteFilesResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<FinalizeFileUploadsResponse> DataAPI::FinalizeFileUploads(
    SharedPtr<Entity> entity,
    const FinalizeFileUploadsRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/File/FinalizeFileUploads" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<FinalizeFileUploadsResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            FinalizeFileUploadsResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<FinalizeFileUploadsResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetFilesResponse> DataAPI::GetFiles(
    SharedPtr<Entity> entity,
    const GetFilesRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/File/GetFiles" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetFilesResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetFilesResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetFilesResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetObjectsResponse> DataAPI::GetObjects(
    SharedPtr<Entity> entity,
    const GetObjectsRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/Object/GetObjects" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetObjectsResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetObjectsResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetObjectsResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<InitiateFileUploadsResponse> DataAPI::InitiateFileUploads(
    SharedPtr<Entity> entity,
    const InitiateFileUploadsRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/File/InitiateFileUploads" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<InitiateFileUploadsResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            InitiateFileUploadsResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<InitiateFileUploadsResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SetObjectsResponse> DataAPI::SetObjects(
    SharedPtr<Entity> entity,
    const SetObjectsRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/Object/SetObjects" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<SetObjectsResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            SetObjectsResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<SetObjectsResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

} // namespace Data
} // namespace PlayFab
