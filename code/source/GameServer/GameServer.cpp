#include "stdafx.h"
#include "GameServer.h"
#include "GlobalState.h"
#include "TitlePlayer.h"

namespace PlayFab
{
namespace GameServer
{


AsyncOp<AddServerBuildResult> GameServerAPI::AdminAddServerBuild(
    SharedPtr<GlobalState const> state,
    const AddServerBuildRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/AddServerBuild" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<AddServerBuildResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            AddServerBuildResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<AddServerBuildResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetServerBuildInfoResult> GameServerAPI::AdminGetServerBuildInfo(
    SharedPtr<GlobalState const> state,
    const GetServerBuildInfoRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/GetServerBuildInfo" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetServerBuildInfoResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetServerBuildInfoResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetServerBuildInfoResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetServerBuildUploadURLResult> GameServerAPI::AdminGetServerBuildUploadUrl(
    SharedPtr<GlobalState const> state,
    const GetServerBuildUploadURLRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/GetServerBuildUploadUrl" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetServerBuildUploadURLResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetServerBuildUploadURLResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetServerBuildUploadURLResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ListBuildsResult> GameServerAPI::AdminListServerBuilds(
    SharedPtr<GlobalState const> state,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/ListServerBuilds" };
    JsonValue requestBody{ rapidjson::kNullType };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ListBuildsResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ListBuildsResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ListBuildsResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ModifyServerBuildResult> GameServerAPI::AdminModifyServerBuild(
    SharedPtr<GlobalState const> state,
    const ModifyServerBuildRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/ModifyServerBuild" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ModifyServerBuildResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ModifyServerBuildResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ModifyServerBuildResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<void> GameServerAPI::AdminRemoveServerBuild(
    SharedPtr<GlobalState const> state,
    const RemoveServerBuildRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/RemoveServerBuild" };
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

} // namespace GameServer
} // namespace PlayFab
