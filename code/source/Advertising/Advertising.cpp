#include "stdafx.h"
#include "Advertising.h"
#include "GlobalState.h"
#include "TitlePlayer.h"

namespace PlayFab
{
namespace Advertising
{


AsyncOp<void> AdvertisingAPI::ClientAttributeInstall(
    SharedPtr<TitlePlayer> entity,
    const AttributeInstallRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/AttributeInstall" };
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

AsyncOp<GetAdPlacementsResult> AdvertisingAPI::ClientGetAdPlacements(
    SharedPtr<TitlePlayer> entity,
    const GetAdPlacementsRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/GetAdPlacements" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetAdPlacementsResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetAdPlacementsResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetAdPlacementsResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<void> AdvertisingAPI::ClientReportAdActivity(
    SharedPtr<TitlePlayer> entity,
    const ReportAdActivityRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/ReportAdActivity" };
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

AsyncOp<RewardAdActivityResult> AdvertisingAPI::ClientRewardAdActivity(
    SharedPtr<TitlePlayer> entity,
    const RewardAdActivityRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/RewardAdActivity" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<RewardAdActivityResult>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            RewardAdActivityResult resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<RewardAdActivityResult>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

} // namespace Advertising
} // namespace PlayFab
