#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct CreateExclusionGroupResultHolder : public XAsyncResult, public std::enable_shared_from_this<CreateExclusionGroupResultHolder>
{
    CreateExclusionGroupResultHolder() = default;
    CreateExclusionGroupResultHolder(const CreateExclusionGroupResultHolder&) = delete;
    CreateExclusionGroupResultHolder(CreateExclusionGroupResultHolder&&) = default;
    CreateExclusionGroupResultHolder& operator=(const CreateExclusionGroupResultHolder&) = delete;
    CreateExclusionGroupResultHolder& operator=(CreateExclusionGroupResultHolder&&) = default;
    ~CreateExclusionGroupResultHolder() = default;

    PFExperimentationCreateExclusionGroupResult* result{ nullptr };
};

struct CreateExperimentResultHolder : public XAsyncResult, public std::enable_shared_from_this<CreateExperimentResultHolder>
{
    CreateExperimentResultHolder() = default;
    CreateExperimentResultHolder(const CreateExperimentResultHolder&) = delete;
    CreateExperimentResultHolder(CreateExperimentResultHolder&&) = default;
    CreateExperimentResultHolder& operator=(const CreateExperimentResultHolder&) = delete;
    CreateExperimentResultHolder& operator=(CreateExperimentResultHolder&&) = default;
    ~CreateExperimentResultHolder() = default;

    PFExperimentationCreateExperimentResult* result{ nullptr };
};

struct GetExclusionGroupsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetExclusionGroupsResultHolder>
{
    GetExclusionGroupsResultHolder() = default;
    GetExclusionGroupsResultHolder(const GetExclusionGroupsResultHolder&) = delete;
    GetExclusionGroupsResultHolder(GetExclusionGroupsResultHolder&&) = default;
    GetExclusionGroupsResultHolder& operator=(const GetExclusionGroupsResultHolder&) = delete;
    GetExclusionGroupsResultHolder& operator=(GetExclusionGroupsResultHolder&&) = default;
    ~GetExclusionGroupsResultHolder() = default;

    PFExperimentationGetExclusionGroupsResult* result{ nullptr };
};

struct GetExclusionGroupTrafficResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetExclusionGroupTrafficResultHolder>
{
    GetExclusionGroupTrafficResultHolder() = default;
    GetExclusionGroupTrafficResultHolder(const GetExclusionGroupTrafficResultHolder&) = delete;
    GetExclusionGroupTrafficResultHolder(GetExclusionGroupTrafficResultHolder&&) = default;
    GetExclusionGroupTrafficResultHolder& operator=(const GetExclusionGroupTrafficResultHolder&) = delete;
    GetExclusionGroupTrafficResultHolder& operator=(GetExclusionGroupTrafficResultHolder&&) = default;
    ~GetExclusionGroupTrafficResultHolder() = default;

    PFExperimentationGetExclusionGroupTrafficResult* result{ nullptr };
};

struct GetExperimentsResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetExperimentsResultHolder>
{
    GetExperimentsResultHolder() = default;
    GetExperimentsResultHolder(const GetExperimentsResultHolder&) = delete;
    GetExperimentsResultHolder(GetExperimentsResultHolder&&) = default;
    GetExperimentsResultHolder& operator=(const GetExperimentsResultHolder&) = delete;
    GetExperimentsResultHolder& operator=(GetExperimentsResultHolder&&) = default;
    ~GetExperimentsResultHolder() = default;

    PFExperimentationGetExperimentsResult* result{ nullptr };
};

struct GetLatestScorecardResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetLatestScorecardResultHolder>
{
    GetLatestScorecardResultHolder() = default;
    GetLatestScorecardResultHolder(const GetLatestScorecardResultHolder&) = delete;
    GetLatestScorecardResultHolder(GetLatestScorecardResultHolder&&) = default;
    GetLatestScorecardResultHolder& operator=(const GetLatestScorecardResultHolder&) = delete;
    GetLatestScorecardResultHolder& operator=(GetLatestScorecardResultHolder&&) = default;
    ~GetLatestScorecardResultHolder() = default;

    PFExperimentationGetLatestScorecardResult* result{ nullptr };
};

struct GetTreatmentAssignmentResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetTreatmentAssignmentResultHolder>
{
    GetTreatmentAssignmentResultHolder() = default;
    GetTreatmentAssignmentResultHolder(const GetTreatmentAssignmentResultHolder&) = delete;
    GetTreatmentAssignmentResultHolder(GetTreatmentAssignmentResultHolder&&) = default;
    GetTreatmentAssignmentResultHolder& operator=(const GetTreatmentAssignmentResultHolder&) = delete;
    GetTreatmentAssignmentResultHolder& operator=(GetTreatmentAssignmentResultHolder&&) = default;
    ~GetTreatmentAssignmentResultHolder() = default;

    PFExperimentationGetTreatmentAssignmentResult* result{ nullptr };
};


}
