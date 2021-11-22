#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct CreateSegmentResponseHolder : public XAsyncResult, public std::enable_shared_from_this<CreateSegmentResponseHolder>
{
    CreateSegmentResponseHolder() = default;
    CreateSegmentResponseHolder(const CreateSegmentResponseHolder&) = delete;
    CreateSegmentResponseHolder(CreateSegmentResponseHolder&&) = default;
    CreateSegmentResponseHolder& operator=(const CreateSegmentResponseHolder&) = delete;
    CreateSegmentResponseHolder& operator=(CreateSegmentResponseHolder&&) = default;
    ~CreateSegmentResponseHolder() = default;

    PFSegmentsCreateSegmentResponse* result{ nullptr };
};

struct DeleteSegmentsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<DeleteSegmentsResponseHolder>
{
    DeleteSegmentsResponseHolder() = default;
    DeleteSegmentsResponseHolder(const DeleteSegmentsResponseHolder&) = delete;
    DeleteSegmentsResponseHolder(DeleteSegmentsResponseHolder&&) = default;
    DeleteSegmentsResponseHolder& operator=(const DeleteSegmentsResponseHolder&) = delete;
    DeleteSegmentsResponseHolder& operator=(DeleteSegmentsResponseHolder&&) = default;
    ~DeleteSegmentsResponseHolder() = default;

    PFSegmentsDeleteSegmentsResponse* result{ nullptr };
};

struct GetSegmentsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetSegmentsResponseHolder>
{
    GetSegmentsResponseHolder() = default;
    GetSegmentsResponseHolder(const GetSegmentsResponseHolder&) = delete;
    GetSegmentsResponseHolder(GetSegmentsResponseHolder&&) = default;
    GetSegmentsResponseHolder& operator=(const GetSegmentsResponseHolder&) = delete;
    GetSegmentsResponseHolder& operator=(GetSegmentsResponseHolder&&) = default;
    ~GetSegmentsResponseHolder() = default;

    PFSegmentsGetSegmentsResponse* result{ nullptr };
};

struct UpdateSegmentResponseHolder : public XAsyncResult, public std::enable_shared_from_this<UpdateSegmentResponseHolder>
{
    UpdateSegmentResponseHolder() = default;
    UpdateSegmentResponseHolder(const UpdateSegmentResponseHolder&) = delete;
    UpdateSegmentResponseHolder(UpdateSegmentResponseHolder&&) = default;
    UpdateSegmentResponseHolder& operator=(const UpdateSegmentResponseHolder&) = delete;
    UpdateSegmentResponseHolder& operator=(UpdateSegmentResponseHolder&&) = default;
    ~UpdateSegmentResponseHolder() = default;

    PFSegmentsUpdateSegmentResponse* result{ nullptr };
};


}
