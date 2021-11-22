#include "stdafx.h"
#include "Profiles.h"
#include "GlobalState.h"
#include "TitlePlayer.h"

namespace PlayFab
{
namespace Profiles
{


AsyncOp<GetGlobalPolicyResponse> ProfilesAPI::GetGlobalPolicy(
    SharedPtr<Entity> entity,
    const GetGlobalPolicyRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/Profile/GetGlobalPolicy" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetGlobalPolicyResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetGlobalPolicyResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetGlobalPolicyResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetEntityProfileResponse> ProfilesAPI::GetProfile(
    SharedPtr<Entity> entity,
    const GetEntityProfileRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/Profile/GetProfile" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetEntityProfileResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetEntityProfileResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetEntityProfileResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetEntityProfilesResponse> ProfilesAPI::GetProfiles(
    SharedPtr<Entity> entity,
    const GetEntityProfilesRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/Profile/GetProfiles" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetEntityProfilesResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetEntityProfilesResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetEntityProfilesResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetTitlePlayersFromMasterPlayerAccountIdsResponse> ProfilesAPI::GetTitlePlayersFromMasterPlayerAccountIds(
    SharedPtr<Entity> entity,
    const GetTitlePlayersFromMasterPlayerAccountIdsRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/Profile/GetTitlePlayersFromMasterPlayerAccountIds" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetTitlePlayersFromMasterPlayerAccountIdsResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetTitlePlayersFromMasterPlayerAccountIdsResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetTitlePlayersFromMasterPlayerAccountIdsResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<void> ProfilesAPI::SetGlobalPolicy(
    SharedPtr<Entity> entity,
    const SetGlobalPolicyRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/Profile/SetGlobalPolicy" };
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

AsyncOp<SetProfileLanguageResponse> ProfilesAPI::SetProfileLanguage(
    SharedPtr<Entity> entity,
    const SetProfileLanguageRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/Profile/SetProfileLanguage" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<SetProfileLanguageResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            SetProfileLanguageResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<SetProfileLanguageResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SetEntityProfilePolicyResponse> ProfilesAPI::SetProfilePolicy(
    SharedPtr<Entity> entity,
    const SetEntityProfilePolicyRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/Profile/SetProfilePolicy" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<SetEntityProfilePolicyResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            SetEntityProfilePolicyResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<SetEntityProfilePolicyResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

} // namespace Profiles
} // namespace PlayFab
