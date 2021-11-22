#include "stdafx.h"
#include "PlatformSpecific.h"
#include "GlobalState.h"
#include "TitlePlayer.h"

namespace PlayFab
{
namespace PlatformSpecific
{


AsyncOp<void> PlatformSpecificAPI::ClientAndroidDevicePushNotificationRegistration(
    SharedPtr<TitlePlayer> entity,
    const AndroidDevicePushNotificationRegistrationRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/AndroidDevicePushNotificationRegistration" };
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

AsyncOp<ConsumeMicrosoftStoreEntitlementsResponse> PlatformSpecificAPI::ClientConsumeMicrosoftStoreEntitlements(
    SharedPtr<TitlePlayer> entity,
    const ConsumeMicrosoftStoreEntitlementsRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/ConsumeMicrosoftStoreEntitlements" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ConsumeMicrosoftStoreEntitlementsResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ConsumeMicrosoftStoreEntitlementsResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ConsumeMicrosoftStoreEntitlementsResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ConsumePS5EntitlementsResult> PlatformSpecificAPI::ClientConsumePS5Entitlements(
    SharedPtr<TitlePlayer> entity,
    const ConsumePS5EntitlementsRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/ConsumePS5Entitlements" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ConsumePS5EntitlementsResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ConsumePS5EntitlementsResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ConsumePS5EntitlementsResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ConsumePSNEntitlementsResult> PlatformSpecificAPI::ClientConsumePSNEntitlements(
    SharedPtr<TitlePlayer> entity,
    const ConsumePSNEntitlementsRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/ConsumePSNEntitlements" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ConsumePSNEntitlementsResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ConsumePSNEntitlementsResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ConsumePSNEntitlementsResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ConsumeXboxEntitlementsResult> PlatformSpecificAPI::ClientConsumeXboxEntitlements(
    SharedPtr<TitlePlayer> entity,
    const ConsumeXboxEntitlementsRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/ConsumeXboxEntitlements" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ConsumeXboxEntitlementsResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ConsumeXboxEntitlementsResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ConsumeXboxEntitlementsResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<void> PlatformSpecificAPI::ClientRefreshPSNAuthToken(
    SharedPtr<TitlePlayer> entity,
    const RefreshPSNAuthTokenRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/RefreshPSNAuthToken" };
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

AsyncOp<void> PlatformSpecificAPI::ClientRegisterForIOSPushNotification(
    SharedPtr<TitlePlayer> entity,
    const RegisterForIOSPushNotificationRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/RegisterForIOSPushNotification" };
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

AsyncOp<RestoreIOSPurchasesResult> PlatformSpecificAPI::ClientRestoreIOSPurchases(
    SharedPtr<TitlePlayer> entity,
    const RestoreIOSPurchasesRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/RestoreIOSPurchases" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<RestoreIOSPurchasesResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            RestoreIOSPurchasesResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<RestoreIOSPurchasesResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ValidateAmazonReceiptResult> PlatformSpecificAPI::ClientValidateAmazonIAPReceipt(
    SharedPtr<TitlePlayer> entity,
    const ValidateAmazonReceiptRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/ValidateAmazonIAPReceipt" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ValidateAmazonReceiptResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ValidateAmazonReceiptResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ValidateAmazonReceiptResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ValidateGooglePlayPurchaseResult> PlatformSpecificAPI::ClientValidateGooglePlayPurchase(
    SharedPtr<TitlePlayer> entity,
    const ValidateGooglePlayPurchaseRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/ValidateGooglePlayPurchase" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ValidateGooglePlayPurchaseResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ValidateGooglePlayPurchaseResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ValidateGooglePlayPurchaseResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ValidateIOSReceiptResult> PlatformSpecificAPI::ClientValidateIOSReceipt(
    SharedPtr<TitlePlayer> entity,
    const ValidateIOSReceiptRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/ValidateIOSReceipt" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ValidateIOSReceiptResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ValidateIOSReceiptResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ValidateIOSReceiptResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<ValidateWindowsReceiptResult> PlatformSpecificAPI::ClientValidateWindowsStoreReceipt(
    SharedPtr<TitlePlayer> entity,
    const ValidateWindowsReceiptRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/ValidateWindowsStoreReceipt" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<ValidateWindowsReceiptResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            ValidateWindowsReceiptResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<ValidateWindowsReceiptResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<AwardSteamAchievementResult> PlatformSpecificAPI::ServerAwardSteamAchievement(
    SharedPtr<GlobalState const> state,
    const AwardSteamAchievementRequest& request,
    const TaskQueue& queue
)
{
    auto secretKey{ state->SecretKey() };
    if (!secretKey || secretKey->empty())
    {
        return E_PF_NOSECRETKEY;
    }

    const char* path{ "/Server/AwardSteamAchievement" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSecretKeyHeaderName, *secretKey }};

    auto requestOp = state->HttpClient()->MakePostRequest(
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<AwardSteamAchievementResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            AwardSteamAchievementResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<AwardSteamAchievementResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

} // namespace PlatformSpecific
} // namespace PlayFab
