#include "stdafx.h"
#include "Trading.h"
#include "GlobalState.h"
#include "TitlePlayer.h"

namespace PlayFab
{
namespace Trading
{


AsyncOp<AcceptTradeResponse> TradingAPI::ClientAcceptTrade(
    SharedPtr<TitlePlayer> entity,
    const AcceptTradeRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/AcceptTrade" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<AcceptTradeResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            AcceptTradeResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<AcceptTradeResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<CancelTradeResponse> TradingAPI::ClientCancelTrade(
    SharedPtr<TitlePlayer> entity,
    const CancelTradeRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/CancelTrade" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<CancelTradeResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            CancelTradeResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<CancelTradeResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetPlayerTradesResponse> TradingAPI::ClientGetPlayerTrades(
    SharedPtr<TitlePlayer> entity,
    const GetPlayerTradesRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/GetPlayerTrades" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetPlayerTradesResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetPlayerTradesResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetPlayerTradesResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<GetTradeStatusResponse> TradingAPI::ClientGetTradeStatus(
    SharedPtr<TitlePlayer> entity,
    const GetTradeStatusRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/GetTradeStatus" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetTradeStatusResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetTradeStatusResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetTradeStatusResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

AsyncOp<OpenTradeResponse> TradingAPI::ClientOpenTrade(
    SharedPtr<TitlePlayer> entity,
    const OpenTradeRequest& request,
    const TaskQueue& queue
)
{
    auto sessionTicket{ entity->SessionTicket() };
    if (!sessionTicket || sessionTicket->empty()) 
    {
        return E_PF_NOSESSIONTICKET;
    }

    const char* path{ "/Client/OpenTrade" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kSessionTicketHeaderName, *sessionTicket }};

    auto requestOp = entity->HttpClient()->MakeClassicRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<OpenTradeResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            OpenTradeResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<OpenTradeResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

} // namespace Trading
} // namespace PlayFab
