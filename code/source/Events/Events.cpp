#include "stdafx.h"
#include "Events.h"
#include "GlobalState.h"
#include "TitlePlayer.h"

namespace PlayFab
{
namespace Events
{


AsyncOp<WriteEventsResponse> EventsAPI::WriteEvents(
    SharedPtr<TitlePlayer> entity,
    const WriteEventsRequest& request,
    RunContext rc
)
{
    const char* path{ "/Event/WriteEvents" };
    JsonValue requestBody{ request.ToJson() };

    auto requestOp = entity->ServiceConfig()->HttpClient()->MakeEntityRequest(
        entity,
        path,
        UnorderedMap<String, String>{},
        std::move(requestBody),
        rc.Derive()
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<WriteEventsResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            WriteEventsResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<WriteEventsResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

} // namespace Events
} // namespace PlayFab
