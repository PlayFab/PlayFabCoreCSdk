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


AsyncOp<void> AuthenticationAPI::AdminCreateOpenIdConnection(
    SharedPtr<GlobalState const> state,
    const CreateOpenIdConnectionRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/CreateOpenIdConnection" };
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

AsyncOp<CreatePlayerSharedSecretResult> AuthenticationAPI::AdminCreatePlayerSharedSecret(
    SharedPtr<GlobalState const> state,
    const CreatePlayerSharedSecretRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/CreatePlayerSharedSecret" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<CreatePlayerSharedSecretResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            CreatePlayerSharedSecretResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<CreatePlayerSharedSecretResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<void> AuthenticationAPI::AdminDeleteOpenIdConnection(
    SharedPtr<GlobalState const> state,
    const DeleteOpenIdConnectionRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/DeleteOpenIdConnection" };
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

AsyncOp<void> AuthenticationAPI::AdminDeletePlayerSharedSecret(
    SharedPtr<GlobalState const> state,
    const DeletePlayerSharedSecretRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/DeletePlayerSharedSecret" };
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

AsyncOp<GetPlayerSharedSecretsResult> AuthenticationAPI::AdminGetPlayerSharedSecrets(
    SharedPtr<GlobalState const> state,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/GetPlayerSharedSecrets" };
    JsonValue requestBody{ rapidjson::kNullType };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetPlayerSharedSecretsResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetPlayerSharedSecretsResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetPlayerSharedSecretsResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetPolicyResponse> AuthenticationAPI::AdminGetPolicy(
    SharedPtr<GlobalState const> state,
    const GetPolicyRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/GetPolicy" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetPolicyResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetPolicyResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetPolicyResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ListOpenIdConnectionResponse> AuthenticationAPI::AdminListOpenIdConnection(
    SharedPtr<GlobalState const> state,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/ListOpenIdConnection" };
    JsonValue requestBody{ rapidjson::kNullType };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ListOpenIdConnectionResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ListOpenIdConnectionResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ListOpenIdConnectionResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<void> AuthenticationAPI::AdminSetPlayerSecret(
    SharedPtr<GlobalState const> state,
    const AdminSetPlayerSecretRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/SetPlayerSecret" };
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

AsyncOp<void> AuthenticationAPI::AdminUpdateOpenIdConnection(
    SharedPtr<GlobalState const> state,
    const UpdateOpenIdConnectionRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/UpdateOpenIdConnection" };
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

AsyncOp<void> AuthenticationAPI::AdminUpdatePlayerSharedSecret(
    SharedPtr<GlobalState const> state,
    const UpdatePlayerSharedSecretRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/UpdatePlayerSharedSecret" };
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

AsyncOp<UpdatePolicyResponse> AuthenticationAPI::AdminUpdatePolicy(
    SharedPtr<GlobalState const> state,
    const UpdatePolicyRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Admin/UpdatePolicy" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<UpdatePolicyResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            UpdatePolicyResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<UpdatePolicyResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetPhotonAuthenticationTokenResult> AuthenticationAPI::ClientGetPhotonAuthenticationToken(
    SharedPtr<TitlePlayer> entity,
    const GetPhotonAuthenticationTokenRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/GetPhotonAuthenticationToken" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetPhotonAuthenticationTokenResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetPhotonAuthenticationTokenResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetPhotonAuthenticationTokenResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetTitlePublicKeyResult> AuthenticationAPI::ClientGetTitlePublicKey(
    SharedPtr<GlobalState const> state,
    const GetTitlePublicKeyRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/GetTitlePublicKey" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetTitlePublicKeyResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetTitlePublicKeyResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetTitlePublicKeyResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithAndroidDeviceID(
    SharedPtr<GlobalState const> state,
    const LoginWithAndroidDeviceIDRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithAndroidDeviceID" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithApple(
    SharedPtr<GlobalState const> state,
    const LoginWithAppleRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithApple" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithCustomID(
    SharedPtr<GlobalState const> state,
    const LoginWithCustomIDRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithCustomID" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithEmailAddress(
    SharedPtr<GlobalState const> state,
    const LoginWithEmailAddressRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithEmailAddress" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithFacebook(
    SharedPtr<GlobalState const> state,
    const LoginWithFacebookRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithFacebook" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithFacebookInstantGamesId(
    SharedPtr<GlobalState const> state,
    const LoginWithFacebookInstantGamesIdRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithFacebookInstantGamesId" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithGameCenter(
    SharedPtr<GlobalState const> state,
    const LoginWithGameCenterRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithGameCenter" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithGoogleAccount(
    SharedPtr<GlobalState const> state,
    const LoginWithGoogleAccountRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithGoogleAccount" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithIOSDeviceID(
    SharedPtr<GlobalState const> state,
    const LoginWithIOSDeviceIDRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithIOSDeviceID" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithKongregate(
    SharedPtr<GlobalState const> state,
    const LoginWithKongregateRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithKongregate" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithNintendoServiceAccount(
    SharedPtr<GlobalState const> state,
    const LoginWithNintendoServiceAccountRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithNintendoServiceAccount" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithNintendoSwitchDeviceId(
    SharedPtr<GlobalState const> state,
    const LoginWithNintendoSwitchDeviceIdRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithNintendoSwitchDeviceId" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithOpenIdConnect(
    SharedPtr<GlobalState const> state,
    const LoginWithOpenIdConnectRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithOpenIdConnect" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithPlayFab(
    SharedPtr<GlobalState const> state,
    const LoginWithPlayFabRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithPlayFab" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithPSN(
    SharedPtr<GlobalState const> state,
    const LoginWithPSNRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithPSN" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithSteam(
    SharedPtr<GlobalState const> state,
    const LoginWithSteamRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithSteam" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithTwitch(
    SharedPtr<GlobalState const> state,
    const LoginWithTwitchRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithTwitch" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientLoginWithXbox(
    SharedPtr<GlobalState const> state,
    const ClientLoginWithXboxRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/LoginWithXbox" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

#if HC_PLATFORM == HC_PLATFORM_GDK

class XUserLoginContext : public LoginContext
{
public:
    XUserLoginContext(XUser&& platformUser, String titleId, const PFAuthenticationLoginWithXUserRequest& request);

    AsyncOp<JsonValue> GetRequestBody(const TaskQueue& queue) const override;

private:
    XUser m_platformUser;
    String m_titleId;
    ClientLoginWithXboxRequest m_request;
};

XUserLoginContext::XUserLoginContext(XUser&& platformUser, String titleId, const PFAuthenticationLoginWithXUserRequest& request)
    : LoginContext{ "/Client/LoginWithXbox" },
    m_platformUser{ std::move(platformUser) },
    m_titleId{ std::move(titleId) },
    m_request{ PFAuthenticationClientLoginWithXboxRequest
    {
        request.createAccount,
        request.customTags,
        request.customTagsCount,
        request.infoRequestParameters,
        request.playerSecret,
        nullptr // XboxToken, will be populated later
    }
    }
{
}

AsyncOp<JsonValue> XUserLoginContext::GetRequestBody(const TaskQueue& queue) const
{
    return m_platformUser.GetTokenAndSignature(
        XUserGetTokenAndSignatureOptions::None,
        "POST",
        "https://playfabapi.com/",
        UnorderedMap<String, String>{},
        0,
        nullptr,
        queue
    ).Then([request{ this->m_request }, titleId{ this->m_titleId }](Result<TokenAndSignature> getTokenResult) mutable->Result<JsonValue>
    {
        RETURN_IF_FAILED(getTokenResult.hr);
        request.SetXboxToken(getTokenResult.Payload().token);
        auto requestJson = request.ToJson();
        JsonUtils::ObjectAddMember(requestJson, "TitleId", titleId);
        return requestJson;
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::LoginWithXUser(
    SharedPtr<GlobalState> state,
    const PFAuthenticationLoginWithXUserRequest& request,
    const TaskQueue& queue
)
{
    auto wrapUserHandleResult = XUser::WrapHandle(request.userHandle);
    RETURN_IF_FAILED(wrapUserHandleResult.hr);

    auto loginContext = MakeShared<XUserLoginContext>(wrapUserHandleResult.ExtractPayload(), state->TitleId(), request);

    return loginContext->GetRequestBody(queue.DeriveWorkerQueue()).Then([ httpClient{ state->HttpClient() }, queue = TaskQueue{ queue }, loginContext](Result<JsonValue> requestBodyResult) -> AsyncOp<ServiceResponse>
    {
        RETURN_IF_FAILED(requestBodyResult.hr);

        return httpClient->MakePostRequest(
            loginContext->RequestPath(),
            UnorderedMap<String, String>{},
            requestBodyResult.Payload(),
            queue
        );

    }).Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            LoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}
#endif

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ClientRegisterPlayFabUser(
    SharedPtr<GlobalState const> state,
    const RegisterPlayFabUserRequest& request,
    const TaskQueue& queue
)
{
    const char* path{ "/Client/RegisterPlayFabUser" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            RegisterPlayFabUserResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<void> AuthenticationAPI::ClientSetPlayerSecret(
    SharedPtr<TitlePlayer> entity,
    const ClientSetPlayerSecretRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/SetPlayerSecret" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
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

AsyncOp<AuthenticateSessionTicketResult> AuthenticationAPI::ServerAuthenticateSessionTicket(
    SharedPtr<GlobalState const> state,
    const AuthenticateSessionTicketRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Server/AuthenticateSessionTicket" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<AuthenticateSessionTicketResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            AuthenticateSessionTicketResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<AuthenticateSessionTicketResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ServerLoginWithServerCustomId(
    SharedPtr<GlobalState const> state,
    const LoginWithServerCustomIdRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Server/LoginWithServerCustomId" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ServerLoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ServerLoginWithSteamId(
    SharedPtr<GlobalState const> state,
    const LoginWithSteamIdRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Server/LoginWithSteamId" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ServerLoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ServerLoginWithXbox(
    SharedPtr<GlobalState const> state,
    const ServerLoginWithXboxRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Server/LoginWithXbox" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ServerLoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<SharedPtr<TitlePlayer>> AuthenticationAPI::ServerLoginWithXboxId(
    SharedPtr<GlobalState const> state,
    const LoginWithXboxIdRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Server/LoginWithXboxId" };
    JsonValue requestBody{ request.ToJson() };
    JsonUtils::ObjectAddMember(requestBody, "TitleId", state->TitleId());
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    // Remember LoginContext so we can refresh tokens
    auto loginContext = MakeShared<LoginContext>(path, std::move(requestBody), std::move(headers));
    return requestOp.Then([ state, loginContext ](Result<ServiceResponse> result) -> Result<SharedPtr<TitlePlayer>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ServerLoginResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<TitlePlayer>(state->HttpClient(), state->QoSAPI(), loginContext, std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<TitlePlayer>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<void> AuthenticationAPI::ServerSetPlayerSecret(
    SharedPtr<GlobalState const> state,
    const ServerSetPlayerSecretRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Server/SetPlayerSecret" };
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

AsyncOp<SharedPtr<Entity>> AuthenticationAPI::GetEntityToken(
    SharedPtr<GlobalState const> state,
    const GetEntityTokenRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Authentication/GetEntityToken" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([ state ](Result<ServiceResponse> result) -> Result<SharedPtr<Entity>>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetEntityTokenResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return MakeShared<Entity>(state->HttpClient(), state->QoSAPI(), std::move(resultModel));
        }
        else
        {
            return Result<SharedPtr<Entity>>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ValidateEntityTokenResponse> AuthenticationAPI::ValidateEntityToken(
    SharedPtr<Entity> entity,
    const ValidateEntityTokenRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/Authentication/ValidateEntityToken" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ValidateEntityTokenResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ValidateEntityTokenResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ValidateEntityTokenResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

} // namespace Authentication
} // namespace PlayFab
