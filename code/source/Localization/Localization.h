#pragma once

#include "LocalizationDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Localization
{

class LocalizationAPI
{
public:
    LocalizationAPI() = delete;
    LocalizationAPI(const LocalizationAPI& source) = delete;
    LocalizationAPI& operator=(const LocalizationAPI& source) = delete;
    ~LocalizationAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<GetLanguageListResponse> GetLanguageList(SharedPtr<Entity> entity, const GetLanguageListRequest& request, const TaskQueue& queue);
};

} // namespace Localization
} // namespace PlayFab
