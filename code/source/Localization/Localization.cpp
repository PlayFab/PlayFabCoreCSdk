#include "stdafx.h"
#include "Localization.h"
#include "GlobalState.h"
#include "TitlePlayer.h"

namespace PlayFab
{
namespace Localization
{


AsyncOp<GetLanguageListResponse> LocalizationAPI::GetLanguageList(
    SharedPtr<Entity> entity,
    const GetLanguageListRequest& request,
    const TaskQueue& queue
)
{
    auto entityToken{ entity->EntityToken() };
    if (!entityToken || !entityToken->token) 
    {
        return E_PF_NOENTITYTOKEN;
    }

    const char* path{ "/Locale/GetLanguageList" };
    JsonValue requestBody{ request.ToJson() };
    UnorderedMap<String, String> headers{{ kEntityTokenHeaderName, entityToken->token }};

    auto requestOp = entity->HttpClient()->MakeEntityRequest(
        entity,
        path,
        std::move(headers),
        std::move(requestBody),
        queue
    );

    return requestOp.Then([](Result<ServiceResponse> result) -> Result<GetLanguageListResponse>
    {
        RETURN_IF_FAILED(result.hr);

        auto serviceResponse = result.ExtractPayload();
        if (serviceResponse.HttpCode == 200)
        {
            GetLanguageListResponse resultModel;
            resultModel.FromJson(serviceResponse.Data);
            return resultModel;
        }
        else
        {
            return Result<GetLanguageListResponse>{ ServiceErrorToHR(serviceResponse.ErrorCode), std::move(serviceResponse.ErrorMessage) };
        }
    });
}

} // namespace Localization
} // namespace PlayFab
