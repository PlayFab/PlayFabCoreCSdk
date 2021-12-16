#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct GetAllSegmentsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetAllSegmentsResultHolder>
{
    GetAllSegmentsResultHolder() = default;
    GetAllSegmentsResultHolder(const GetAllSegmentsResultHolder&) = delete;
    GetAllSegmentsResultHolder(GetAllSegmentsResultHolder&&) = default;
    GetAllSegmentsResultHolder& operator=(const GetAllSegmentsResultHolder&) = delete;
    GetAllSegmentsResultHolder& operator=(GetAllSegmentsResultHolder&&) = default;
    ~GetAllSegmentsResultHolder() = default;

    PFPlayStreamGetAllSegmentsResult* result{ nullptr };
};

struct GetPlayerSegmentsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayerSegmentsResultHolder>
{
    GetPlayerSegmentsResultHolder() = default;
    GetPlayerSegmentsResultHolder(const GetPlayerSegmentsResultHolder&) = delete;
    GetPlayerSegmentsResultHolder(GetPlayerSegmentsResultHolder&&) = default;
    GetPlayerSegmentsResultHolder& operator=(const GetPlayerSegmentsResultHolder&) = delete;
    GetPlayerSegmentsResultHolder& operator=(GetPlayerSegmentsResultHolder&&) = default;
    ~GetPlayerSegmentsResultHolder() = default;

    PFPlayStreamGetPlayerSegmentsResult* result{ nullptr };
};

struct GetPlayersInSegmentResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetPlayersInSegmentResultHolder>
{
    GetPlayersInSegmentResultHolder() = default;
    GetPlayersInSegmentResultHolder(const GetPlayersInSegmentResultHolder&) = delete;
    GetPlayersInSegmentResultHolder(GetPlayersInSegmentResultHolder&&) = default;
    GetPlayersInSegmentResultHolder& operator=(const GetPlayersInSegmentResultHolder&) = delete;
    GetPlayersInSegmentResultHolder& operator=(GetPlayersInSegmentResultHolder&&) = default;
    ~GetPlayersInSegmentResultHolder() = default;

    PFPlayStreamGetPlayersInSegmentResult* result{ nullptr };
};


}
