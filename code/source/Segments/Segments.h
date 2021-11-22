#pragma once

#include "SegmentsDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Segments
{

class SegmentsAPI
{
public:
    SegmentsAPI() = delete;
    SegmentsAPI(const SegmentsAPI& source) = delete;
    SegmentsAPI& operator=(const SegmentsAPI& source) = delete;
    ~SegmentsAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<CreateSegmentResponse> AdminCreateSegment(SharedPtr<GlobalState const> state, const CreateSegmentRequest& request, const TaskQueue& queue);
    static AsyncOp<DeleteSegmentsResponse> AdminDeleteSegment(SharedPtr<GlobalState const> state, const DeleteSegmentRequest& request, const TaskQueue& queue);
    static AsyncOp<GetSegmentsResponse> AdminGetSegments(SharedPtr<GlobalState const> state, const GetSegmentsRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateSegmentResponse> AdminUpdateSegment(SharedPtr<GlobalState const> state, const UpdateSegmentRequest& request, const TaskQueue& queue);
};

} // namespace Segments
} // namespace PlayFab
