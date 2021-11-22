#pragma once

#include "AdvertisingDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Advertising
{

class AdvertisingAPI
{
public:
    AdvertisingAPI() = delete;
    AdvertisingAPI(const AdvertisingAPI& source) = delete;
    AdvertisingAPI& operator=(const AdvertisingAPI& source) = delete;
    ~AdvertisingAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<void> ClientAttributeInstall(SharedPtr<TitlePlayer> entity, const AttributeInstallRequest& request, const TaskQueue& queue);
    static AsyncOp<GetAdPlacementsResult> ClientGetAdPlacements(SharedPtr<TitlePlayer> entity, const GetAdPlacementsRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ClientReportAdActivity(SharedPtr<TitlePlayer> entity, const ReportAdActivityRequest& request, const TaskQueue& queue);
    static AsyncOp<RewardAdActivityResult> ClientRewardAdActivity(SharedPtr<TitlePlayer> entity, const RewardAdActivityRequest& request, const TaskQueue& queue);
};

} // namespace Advertising
} // namespace PlayFab
