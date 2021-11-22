#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct GetAdPlacementsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetAdPlacementsResultHolder>
{
    GetAdPlacementsResultHolder() = default;
    GetAdPlacementsResultHolder(const GetAdPlacementsResultHolder&) = delete;
    GetAdPlacementsResultHolder(GetAdPlacementsResultHolder&&) = default;
    GetAdPlacementsResultHolder& operator=(const GetAdPlacementsResultHolder&) = delete;
    GetAdPlacementsResultHolder& operator=(GetAdPlacementsResultHolder&&) = default;
    ~GetAdPlacementsResultHolder() = default;

    PFAdvertisingGetAdPlacementsResult* result{ nullptr };
};

struct RewardAdActivityResultHolder : public XAsyncResult, public std::enable_shared_from_this<RewardAdActivityResultHolder>
{
    RewardAdActivityResultHolder() = default;
    RewardAdActivityResultHolder(const RewardAdActivityResultHolder&) = delete;
    RewardAdActivityResultHolder(RewardAdActivityResultHolder&&) = default;
    RewardAdActivityResultHolder& operator=(const RewardAdActivityResultHolder&) = delete;
    RewardAdActivityResultHolder& operator=(RewardAdActivityResultHolder&&) = default;
    ~RewardAdActivityResultHolder() = default;

    PFAdvertisingRewardAdActivityResult* result{ nullptr };
};


}
