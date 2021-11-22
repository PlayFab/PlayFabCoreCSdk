#include "stdafx.h"
#include "MultiplayerServer.h"
#include "GlobalState.h"
#include "TitlePlayer.h"

namespace PlayFab
{
namespace MultiplayerServer
{


AsyncOp<BuildAliasDetailsResponse> MultiplayerServerAPI::CreateBuildAlias(
    SharedPtr<Entity> entity,
    const CreateBuildAliasRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/CreateBuildAlias" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<BuildAliasDetailsResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            BuildAliasDetailsResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<BuildAliasDetailsResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<CreateBuildWithCustomContainerResponse> MultiplayerServerAPI::CreateBuildWithCustomContainer(
    SharedPtr<Entity> entity,
    const CreateBuildWithCustomContainerRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/CreateBuildWithCustomContainer" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<CreateBuildWithCustomContainerResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            CreateBuildWithCustomContainerResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<CreateBuildWithCustomContainerResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<CreateBuildWithManagedContainerResponse> MultiplayerServerAPI::CreateBuildWithManagedContainer(
    SharedPtr<Entity> entity,
    const CreateBuildWithManagedContainerRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/CreateBuildWithManagedContainer" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<CreateBuildWithManagedContainerResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            CreateBuildWithManagedContainerResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<CreateBuildWithManagedContainerResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<CreateBuildWithProcessBasedServerResponse> MultiplayerServerAPI::CreateBuildWithProcessBasedServer(
    SharedPtr<Entity> entity,
    const CreateBuildWithProcessBasedServerRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/CreateBuildWithProcessBasedServer" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<CreateBuildWithProcessBasedServerResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            CreateBuildWithProcessBasedServerResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<CreateBuildWithProcessBasedServerResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<CreateRemoteUserResponse> MultiplayerServerAPI::CreateRemoteUser(
    SharedPtr<Entity> entity,
    const CreateRemoteUserRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/CreateRemoteUser" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<CreateRemoteUserResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            CreateRemoteUserResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<CreateRemoteUserResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<CreateTitleMultiplayerServersQuotaChangeResponse> MultiplayerServerAPI::CreateTitleMultiplayerServersQuotaChange(
    SharedPtr<Entity> entity,
    const CreateTitleMultiplayerServersQuotaChangeRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/CreateTitleMultiplayerServersQuotaChange" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<CreateTitleMultiplayerServersQuotaChangeResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            CreateTitleMultiplayerServersQuotaChangeResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<CreateTitleMultiplayerServersQuotaChangeResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<void> MultiplayerServerAPI::DeleteAsset(
    SharedPtr<Entity> entity,
    const DeleteAssetRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/DeleteAsset" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
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

AsyncOp<void> MultiplayerServerAPI::DeleteBuild(
    SharedPtr<Entity> entity,
    const DeleteBuildRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/DeleteBuild" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
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

AsyncOp<void> MultiplayerServerAPI::DeleteBuildAlias(
    SharedPtr<Entity> entity,
    const DeleteBuildAliasRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/DeleteBuildAlias" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
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

AsyncOp<void> MultiplayerServerAPI::DeleteBuildRegion(
    SharedPtr<Entity> entity,
    const DeleteBuildRegionRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/DeleteBuildRegion" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
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

AsyncOp<void> MultiplayerServerAPI::DeleteCertificate(
    SharedPtr<Entity> entity,
    const DeleteCertificateRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/DeleteCertificate" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
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

AsyncOp<void> MultiplayerServerAPI::DeleteContainerImageRepository(
    SharedPtr<Entity> entity,
    const DeleteContainerImageRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/DeleteContainerImageRepository" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
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

AsyncOp<void> MultiplayerServerAPI::DeleteRemoteUser(
    SharedPtr<Entity> entity,
    const DeleteRemoteUserRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/DeleteRemoteUser" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
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

AsyncOp<EnableMultiplayerServersForTitleResponse> MultiplayerServerAPI::EnableMultiplayerServersForTitle(
    SharedPtr<Entity> entity,
    const EnableMultiplayerServersForTitleRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/EnableMultiplayerServersForTitle" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<EnableMultiplayerServersForTitleResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            EnableMultiplayerServersForTitleResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<EnableMultiplayerServersForTitleResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetAssetDownloadUrlResponse> MultiplayerServerAPI::GetAssetDownloadUrl(
    SharedPtr<Entity> entity,
    const GetAssetDownloadUrlRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/GetAssetDownloadUrl" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetAssetDownloadUrlResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetAssetDownloadUrlResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetAssetDownloadUrlResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetAssetUploadUrlResponse> MultiplayerServerAPI::GetAssetUploadUrl(
    SharedPtr<Entity> entity,
    const GetAssetUploadUrlRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/GetAssetUploadUrl" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetAssetUploadUrlResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetAssetUploadUrlResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetAssetUploadUrlResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetBuildResponse> MultiplayerServerAPI::GetBuild(
    SharedPtr<Entity> entity,
    const GetBuildRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/GetBuild" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetBuildResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetBuildResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetBuildResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<BuildAliasDetailsResponse> MultiplayerServerAPI::GetBuildAlias(
    SharedPtr<Entity> entity,
    const GetBuildAliasRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/GetBuildAlias" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<BuildAliasDetailsResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            BuildAliasDetailsResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<BuildAliasDetailsResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetContainerRegistryCredentialsResponse> MultiplayerServerAPI::GetContainerRegistryCredentials(
    SharedPtr<Entity> entity,
    const GetContainerRegistryCredentialsRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/GetContainerRegistryCredentials" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetContainerRegistryCredentialsResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetContainerRegistryCredentialsResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetContainerRegistryCredentialsResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetMultiplayerServerDetailsResponse> MultiplayerServerAPI::GetMultiplayerServerDetails(
    SharedPtr<Entity> entity,
    const GetMultiplayerServerDetailsRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/GetMultiplayerServerDetails" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetMultiplayerServerDetailsResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetMultiplayerServerDetailsResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetMultiplayerServerDetailsResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetMultiplayerServerLogsResponse> MultiplayerServerAPI::GetMultiplayerServerLogs(
    SharedPtr<Entity> entity,
    const GetMultiplayerServerLogsRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/GetMultiplayerServerLogs" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetMultiplayerServerLogsResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetMultiplayerServerLogsResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetMultiplayerServerLogsResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetMultiplayerServerLogsResponse> MultiplayerServerAPI::GetMultiplayerSessionLogsBySessionId(
    SharedPtr<Entity> entity,
    const GetMultiplayerSessionLogsBySessionIdRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/GetMultiplayerSessionLogsBySessionId" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetMultiplayerServerLogsResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetMultiplayerServerLogsResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetMultiplayerServerLogsResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetRemoteLoginEndpointResponse> MultiplayerServerAPI::GetRemoteLoginEndpoint(
    SharedPtr<Entity> entity,
    const GetRemoteLoginEndpointRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/GetRemoteLoginEndpoint" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetRemoteLoginEndpointResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetRemoteLoginEndpointResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetRemoteLoginEndpointResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetTitleEnabledForMultiplayerServersStatusResponse> MultiplayerServerAPI::GetTitleEnabledForMultiplayerServersStatus(
    SharedPtr<Entity> entity,
    const GetTitleEnabledForMultiplayerServersStatusRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/GetTitleEnabledForMultiplayerServersStatus" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetTitleEnabledForMultiplayerServersStatusResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetTitleEnabledForMultiplayerServersStatusResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetTitleEnabledForMultiplayerServersStatusResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetTitleMultiplayerServersQuotaChangeResponse> MultiplayerServerAPI::GetTitleMultiplayerServersQuotaChange(
    SharedPtr<Entity> entity,
    const GetTitleMultiplayerServersQuotaChangeRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/GetTitleMultiplayerServersQuotaChange" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetTitleMultiplayerServersQuotaChangeResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetTitleMultiplayerServersQuotaChangeResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetTitleMultiplayerServersQuotaChangeResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetTitleMultiplayerServersQuotasResponse> MultiplayerServerAPI::GetTitleMultiplayerServersQuotas(
    SharedPtr<Entity> entity,
    const GetTitleMultiplayerServersQuotasRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/GetTitleMultiplayerServersQuotas" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetTitleMultiplayerServersQuotasResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetTitleMultiplayerServersQuotasResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetTitleMultiplayerServersQuotasResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ListMultiplayerServersResponse> MultiplayerServerAPI::ListArchivedMultiplayerServers(
    SharedPtr<Entity> entity,
    const ListMultiplayerServersRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/ListArchivedMultiplayerServers" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ListMultiplayerServersResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ListMultiplayerServersResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ListMultiplayerServersResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ListAssetSummariesResponse> MultiplayerServerAPI::ListAssetSummaries(
    SharedPtr<Entity> entity,
    const ListAssetSummariesRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/ListAssetSummaries" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ListAssetSummariesResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ListAssetSummariesResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ListAssetSummariesResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ListBuildAliasesResponse> MultiplayerServerAPI::ListBuildAliases(
    SharedPtr<Entity> entity,
    const ListBuildAliasesRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/ListBuildAliases" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ListBuildAliasesResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ListBuildAliasesResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ListBuildAliasesResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ListBuildSummariesResponse> MultiplayerServerAPI::ListBuildSummariesV2(
    SharedPtr<Entity> entity,
    const ListBuildSummariesRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/ListBuildSummariesV2" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ListBuildSummariesResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ListBuildSummariesResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ListBuildSummariesResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ListCertificateSummariesResponse> MultiplayerServerAPI::ListCertificateSummaries(
    SharedPtr<Entity> entity,
    const ListCertificateSummariesRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/ListCertificateSummaries" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ListCertificateSummariesResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ListCertificateSummariesResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ListCertificateSummariesResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ListContainerImagesResponse> MultiplayerServerAPI::ListContainerImages(
    SharedPtr<Entity> entity,
    const ListContainerImagesRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/ListContainerImages" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ListContainerImagesResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ListContainerImagesResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ListContainerImagesResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ListContainerImageTagsResponse> MultiplayerServerAPI::ListContainerImageTags(
    SharedPtr<Entity> entity,
    const ListContainerImageTagsRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/ListContainerImageTags" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ListContainerImageTagsResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ListContainerImageTagsResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ListContainerImageTagsResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ListMultiplayerServersResponse> MultiplayerServerAPI::ListMultiplayerServers(
    SharedPtr<Entity> entity,
    const ListMultiplayerServersRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/ListMultiplayerServers" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ListMultiplayerServersResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ListMultiplayerServersResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ListMultiplayerServersResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ListPartyQosServersResponse> MultiplayerServerAPI::ListPartyQosServers(
    SharedPtr<GlobalState const> state,
    const ListPartyQosServersRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/MultiplayerServer/ListPartyQosServers" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ListPartyQosServersResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ListPartyQosServersResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ListPartyQosServersResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ListQosServersForTitleResponse> MultiplayerServerAPI::ListQosServersForTitle(
    SharedPtr<Entity> entity,
    const ListQosServersForTitleRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/ListQosServersForTitle" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ListQosServersForTitleResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ListQosServersForTitleResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ListQosServersForTitleResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ListTitleMultiplayerServersQuotaChangesResponse> MultiplayerServerAPI::ListTitleMultiplayerServersQuotaChanges(
    SharedPtr<Entity> entity,
    const ListTitleMultiplayerServersQuotaChangesRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/ListTitleMultiplayerServersQuotaChanges" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ListTitleMultiplayerServersQuotaChangesResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ListTitleMultiplayerServersQuotaChangesResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ListTitleMultiplayerServersQuotaChangesResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ListVirtualMachineSummariesResponse> MultiplayerServerAPI::ListVirtualMachineSummaries(
    SharedPtr<Entity> entity,
    const ListVirtualMachineSummariesRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/ListVirtualMachineSummaries" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ListVirtualMachineSummariesResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ListVirtualMachineSummariesResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ListVirtualMachineSummariesResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<RequestMultiplayerServerResponse> MultiplayerServerAPI::RequestMultiplayerServer(
    SharedPtr<Entity> entity,
    const RequestMultiplayerServerRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/RequestMultiplayerServer" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<RequestMultiplayerServerResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            RequestMultiplayerServerResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<RequestMultiplayerServerResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<RolloverContainerRegistryCredentialsResponse> MultiplayerServerAPI::RolloverContainerRegistryCredentials(
    SharedPtr<Entity> entity,
    const RolloverContainerRegistryCredentialsRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/RolloverContainerRegistryCredentials" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<RolloverContainerRegistryCredentialsResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            RolloverContainerRegistryCredentialsResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<RolloverContainerRegistryCredentialsResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<void> MultiplayerServerAPI::ShutdownMultiplayerServer(
    SharedPtr<Entity> entity,
    const ShutdownMultiplayerServerRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/ShutdownMultiplayerServer" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
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

AsyncOp<void> MultiplayerServerAPI::UntagContainerImage(
    SharedPtr<Entity> entity,
    const UntagContainerImageRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/UntagContainerImage" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
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

AsyncOp<BuildAliasDetailsResponse> MultiplayerServerAPI::UpdateBuildAlias(
    SharedPtr<Entity> entity,
    const UpdateBuildAliasRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/UpdateBuildAlias" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<BuildAliasDetailsResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            BuildAliasDetailsResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<BuildAliasDetailsResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<void> MultiplayerServerAPI::UpdateBuildName(
    SharedPtr<Entity> entity,
    const UpdateBuildNameRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/UpdateBuildName" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
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

AsyncOp<void> MultiplayerServerAPI::UpdateBuildRegion(
    SharedPtr<Entity> entity,
    const UpdateBuildRegionRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/UpdateBuildRegion" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
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

AsyncOp<void> MultiplayerServerAPI::UpdateBuildRegions(
    SharedPtr<Entity> entity,
    const UpdateBuildRegionsRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/UpdateBuildRegions" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
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

AsyncOp<void> MultiplayerServerAPI::UploadCertificate(
    SharedPtr<Entity> entity,
    const UploadCertificateRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/MultiplayerServer/UploadCertificate" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
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

} // namespace MultiplayerServer
} // namespace PlayFab
