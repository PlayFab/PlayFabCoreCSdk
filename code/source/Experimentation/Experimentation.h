#pragma once

#include "ExperimentationDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Experimentation
{

class ExperimentationAPI
{
public:
    ExperimentationAPI() = delete;
    ExperimentationAPI(const ExperimentationAPI& source) = delete;
    ExperimentationAPI& operator=(const ExperimentationAPI& source) = delete;
    ~ExperimentationAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<CreateExclusionGroupResult> CreateExclusionGroup(SharedPtr<Entity> entity, const CreateExclusionGroupRequest& request, const TaskQueue& queue);
    static AsyncOp<CreateExperimentResult> CreateExperiment(SharedPtr<Entity> entity, const CreateExperimentRequest& request, const TaskQueue& queue);
    static AsyncOp<void> DeleteExclusionGroup(SharedPtr<Entity> entity, const DeleteExclusionGroupRequest& request, const TaskQueue& queue);
    static AsyncOp<void> DeleteExperiment(SharedPtr<Entity> entity, const DeleteExperimentRequest& request, const TaskQueue& queue);
    static AsyncOp<GetExclusionGroupsResult> GetExclusionGroups(SharedPtr<Entity> entity, const GetExclusionGroupsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetExclusionGroupTrafficResult> GetExclusionGroupTraffic(SharedPtr<Entity> entity, const GetExclusionGroupTrafficRequest& request, const TaskQueue& queue);
    static AsyncOp<GetExperimentsResult> GetExperiments(SharedPtr<Entity> entity, const GetExperimentsRequest& request, const TaskQueue& queue);
    static AsyncOp<GetLatestScorecardResult> GetLatestScorecard(SharedPtr<Entity> entity, const GetLatestScorecardRequest& request, const TaskQueue& queue);
    static AsyncOp<GetTreatmentAssignmentResult> GetTreatmentAssignment(SharedPtr<Entity> entity, const GetTreatmentAssignmentRequest& request, const TaskQueue& queue);
    static AsyncOp<void> StartExperiment(SharedPtr<Entity> entity, const StartExperimentRequest& request, const TaskQueue& queue);
    static AsyncOp<void> StopExperiment(SharedPtr<Entity> entity, const StopExperimentRequest& request, const TaskQueue& queue);
    static AsyncOp<void> UpdateExclusionGroup(SharedPtr<Entity> entity, const UpdateExclusionGroupRequest& request, const TaskQueue& queue);
    static AsyncOp<void> UpdateExperiment(SharedPtr<Entity> entity, const UpdateExperimentRequest& request, const TaskQueue& queue);
};

} // namespace Experimentation
} // namespace PlayFab
