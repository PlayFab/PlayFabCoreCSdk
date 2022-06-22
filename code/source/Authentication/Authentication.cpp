#include "stdafx.h"
#include "Authentication.h"
#include "GlobalState.h"
#include "TitlePlayer.h"
#include "PlatformUser.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Authentication
{


AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::AuthenticateWithCustomId(
    SharedPtr<GlobalState const> state,
    SharedPtr<ServiceConfig const> serviceConfig,
    const AuthenticateCustomIdIdentityRequest& request,
    RunContext rc
)
{
    const char* path{ "/PlayerIdentity/AuthenticateWithCustomId" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", serviceConfig->TitleId());
    JsonUtils::ObjectAddMember(requestBody, "PlayerAccountPoolId", serviceConfig->PlayerAccountPoolId());

    auto requestOp = serviceConfig->HttpClient()->MakePostRequest(
        path,
        UnorderedMap<String, String>{},
        std::move(requestBody),
        rc.Derive()
    );

    return requestOp.Then([ state, serviceConfig ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            AuthenticateIdentityResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return TitlePlayer::Make(std::move(resultModel), serviceConfig, state->RunContext(), state->TokenExpiredHandler());
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<void> AuthenticationAPI::ReAuthenticateWithCustomId(
    SharedPtr<TitlePlayer> player,
    const AuthenticateCustomIdIdentityRequest& request,
    RunContext rc)
{
    const char* path{ "/PlayerIdentity/AuthenticateWithCustomId" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", player->ServiceConfig()->TitleId());
    JsonUtils::ObjectAddMember(requestBody, "PlayerAccountPoolId", player->ServiceConfig()->PlayerAccountPoolId());

    auto requestOp = player->ServiceConfig()->HttpClient()->MakePostRequest(
        path,
        UnorderedMap<String, String>{},
        std::move(requestBody),
        rc.Derive()
    );

    return requestOp.Then([ player ](Result<ServiceResponse> result) -> Result<void>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            AuthenticateIdentityResult resultModel;
            resultModel.FromJson(serviceResponse.Data);

            assert(resultModel.titlePlayerAccount.has_value());
            RETURN_HR_IF(E_FAIL, !resultModel.titlePlayerAccount.has_value());
            return player->SetEntityToken(*resultModel.titlePlayerAccount);
            // TODO update MasterPlayer EntityToken as well
        }
        else
        {
            return Result<void>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetLinkedPlayerIdentitiesResult> AuthenticationAPI::GetLinkedPlayerIdentities(
    SharedPtr<TitlePlayer> entity,
    const GetLinkedPlayerIdentitiesRequest& request,
    RunContext rc
)
{
    const char* path{ "/PlayerIdentity/GetLinkedPlayerIdentities" };
    JsonValue requestBody{ request.ToJson() };

    auto requestOp = entity->ServiceConfig()->HttpClient()->MakeEntityRequest(
        entity,
        path,
        UnorderedMap<String, String>{},
        std::move(requestBody),
        rc.Derive()
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetLinkedPlayerIdentitiesResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetLinkedPlayerIdentitiesResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetLinkedPlayerIdentitiesResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<void> AuthenticationAPI::UnlinkPlayerIdentity(
    SharedPtr<TitlePlayer> entity,
    const UnlinkPlayerIdentityRequest& request,
    RunContext rc
)
{
    const char* path{ "/PlayerIdentity/UnlinkPlayerIdentity" };
    JsonValue requestBody{ request.ToJson() };

    auto requestOp = entity->ServiceConfig()->HttpClient()->MakeEntityRequest(
        entity,
        path,
        UnorderedMap<String, String>{},
        std::move(requestBody),
        rc.Derive()
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

} // namespace Authentication
} // namespace PlayFab
