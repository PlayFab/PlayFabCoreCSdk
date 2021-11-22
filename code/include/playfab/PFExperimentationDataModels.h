// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFSharedDataModels.h>

extern "C"
{

#pragma push_macro("IN")
#undef IN

/// <summary>
/// ExperimentType enum.
/// </summary>
enum class PFExperimentationExperimentType : uint32_t
{
    Active,
    Snapshot
};

/// <summary>
/// ExperimentState enum.
/// </summary>
enum class PFExperimentationExperimentState : uint32_t
{
    New,
    Started,
    Stopped,
    Deleted
};

/// <summary>
/// AnalysisTaskState enum.
/// </summary>
enum class PFExperimentationAnalysisTaskState : uint32_t
{
    Waiting,
    ReadyForSubmission,
    SubmittingToPipeline,
    Running,
    Completed,
    Failed,
    Canceled
};

/// <summary>
/// PFExperimentationCreateExclusionGroupRequest data model. Given a title entity token and exclusion
/// group details, will create a new exclusion group for the title.
/// </summary>
typedef struct PFExperimentationCreateExclusionGroupRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) Description of the exclusion group.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* description;

    /// <summary>
    /// Friendly name of the exclusion group.
    /// </summary>
    _Null_terminated_ const char* name;

} PFExperimentationCreateExclusionGroupRequest;

/// <summary>
/// PFExperimentationCreateExclusionGroupResult data model.
/// </summary>
typedef struct PFExperimentationCreateExclusionGroupResult
{
    /// <summary>
    /// (Optional) Identifier of the exclusion group.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* exclusionGroupId;

} PFExperimentationCreateExclusionGroupResult;

/// <summary>
/// PFExperimentationVariant data model.
/// </summary>
typedef struct PFExperimentationVariant
{
    /// <summary>
    /// (Optional) Description of the variant.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* description;

    /// <summary>
    /// (Optional) Id of the variant.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

    /// <summary>
    /// Specifies if variant is control for experiment.
    /// </summary>
    bool isControl;

    /// <summary>
    /// Name of the variant.
    /// </summary>
    _Null_terminated_ const char* name;

    /// <summary>
    /// (Optional) Id of the TitleDataOverride to use with this variant.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* titleDataOverrideLabel;

    /// <summary>
    /// Percentage of target audience traffic that will see this variant.
    /// </summary>
    uint32_t trafficPercentage;

    /// <summary>
    /// (Optional) Variables returned by this variant.
    /// </summary>
    _Maybenull_ _Field_size_(variablesCount) PFVariable const* const* variables;

    /// <summary>
    /// Count of variables
    /// </summary>
    uint32_t variablesCount;

} PFExperimentationVariant;

/// <summary>
/// PFExperimentationCreateExperimentRequest data model. Given a title entity token and experiment details,
/// will create a new experiment for the title.
/// </summary>
typedef struct PFExperimentationCreateExperimentRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) Description of the experiment.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* description;

    /// <summary>
    /// (Optional) When experiment should end.
    /// </summary>
    _Maybenull_ time_t const* endDate;

    /// <summary>
    /// (Optional) Id of the exclusion group.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* exclusionGroupId;

    /// <summary>
    /// (Optional) Percentage of exclusion group traffic that will see this experiment.
    /// </summary>
    _Maybenull_ uint32_t const* exclusionGroupTrafficAllocation;

    /// <summary>
    /// (Optional) Type of experiment.
    /// </summary>
    _Maybenull_ PFExperimentationExperimentType const* experimentType;

    /// <summary>
    /// Friendly name of the experiment.
    /// </summary>
    _Null_terminated_ const char* name;

    /// <summary>
    /// (Optional) Id of the segment to which this experiment applies. Defaults to the 'All Players'
    /// segment.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* segmentId;

    /// <summary>
    /// When experiment should start.
    /// </summary>
    time_t startDate;

    /// <summary>
    /// (Optional) List of title player account IDs that automatically receive treatments in the experiment,
    /// but are not included when calculating experiment metrics.
    /// </summary>
    _Maybenull_ _Field_size_(titlePlayerAccountTestIdsCount) const char* const* titlePlayerAccountTestIds;

    /// <summary>
    /// Count of titlePlayerAccountTestIds
    /// </summary>
    uint32_t titlePlayerAccountTestIdsCount;

    /// <summary>
    /// List of variants for the experiment.
    /// </summary>
    _Field_size_(variantsCount) PFExperimentationVariant const* const* variants;

    /// <summary>
    /// Count of variants
    /// </summary>
    uint32_t variantsCount;

} PFExperimentationCreateExperimentRequest;

/// <summary>
/// PFExperimentationCreateExperimentResult data model.
/// </summary>
typedef struct PFExperimentationCreateExperimentResult
{
    /// <summary>
    /// (Optional) The ID of the new experiment.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* experimentId;

} PFExperimentationCreateExperimentResult;

/// <summary>
/// PFExperimentationDeleteExclusionGroupRequest data model. Given an entity token and an exclusion group
/// ID this API deletes the exclusion group.
/// </summary>
typedef struct PFExperimentationDeleteExclusionGroupRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// The ID of the exclusion group to delete.
    /// </summary>
    _Null_terminated_ const char* exclusionGroupId;

} PFExperimentationDeleteExclusionGroupRequest;

/// <summary>
/// PFExperimentationDeleteExperimentRequest data model. Given an entity token and an experiment ID this
/// API deletes the experiment. A running experiment must be stopped before it can be deleted.
/// </summary>
typedef struct PFExperimentationDeleteExperimentRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// The ID of the experiment to delete.
    /// </summary>
    _Null_terminated_ const char* experimentId;

} PFExperimentationDeleteExperimentRequest;

/// <summary>
/// PFExperimentationGetExclusionGroupsRequest data model. Given a title entity token will return the
/// list of all exclusion groups for a title.
/// </summary>
typedef struct PFExperimentationGetExclusionGroupsRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFExperimentationGetExclusionGroupsRequest;

/// <summary>
/// PFExperimentationExperimentExclusionGroup data model.
/// </summary>
typedef struct PFExperimentationExperimentExclusionGroup
{
    /// <summary>
    /// (Optional) Description of the exclusion group.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* description;

    /// <summary>
    /// (Optional) Id of the exclusion group.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* exclusionGroupId;

    /// <summary>
    /// (Optional) Friendly name of the exclusion group.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* name;

} PFExperimentationExperimentExclusionGroup;

/// <summary>
/// PFExperimentationGetExclusionGroupsResult data model.
/// </summary>
typedef struct PFExperimentationGetExclusionGroupsResult
{
    /// <summary>
    /// (Optional) List of exclusion groups for the title.
    /// </summary>
    _Maybenull_ _Field_size_(exclusionGroupsCount) PFExperimentationExperimentExclusionGroup const* const* exclusionGroups;

    /// <summary>
    /// Count of exclusionGroups
    /// </summary>
    uint32_t exclusionGroupsCount;

} PFExperimentationGetExclusionGroupsResult;

/// <summary>
/// PFExperimentationGetExclusionGroupTrafficRequest data model. Given a title entity token and an exclusion
/// group ID, will return the list of traffic allocations for the exclusion group.
/// </summary>
typedef struct PFExperimentationGetExclusionGroupTrafficRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// The ID of the exclusion group.
    /// </summary>
    _Null_terminated_ const char* exclusionGroupId;

} PFExperimentationGetExclusionGroupTrafficRequest;

/// <summary>
/// PFExperimentationExclusionGroupTrafficAllocation data model.
/// </summary>
typedef struct PFExperimentationExclusionGroupTrafficAllocation
{
    /// <summary>
    /// (Optional) Id of the experiment.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* experimentId;

    /// <summary>
    /// Percentage of exclusion group traffic that will see this experiment.
    /// </summary>
    uint32_t trafficAllocation;

} PFExperimentationExclusionGroupTrafficAllocation;

/// <summary>
/// PFExperimentationGetExclusionGroupTrafficResult data model.
/// </summary>
typedef struct PFExperimentationGetExclusionGroupTrafficResult
{
    /// <summary>
    /// (Optional) List of traffic allocations for the exclusion group.
    /// </summary>
    _Maybenull_ _Field_size_(trafficAllocationsCount) PFExperimentationExclusionGroupTrafficAllocation const* const* trafficAllocations;

    /// <summary>
    /// Count of trafficAllocations
    /// </summary>
    uint32_t trafficAllocationsCount;

} PFExperimentationGetExclusionGroupTrafficResult;

/// <summary>
/// PFExperimentationGetExperimentsRequest data model. Given a title entity token will return the list
/// of all experiments for a title, including scheduled, started, stopped or completed experiments.
/// </summary>
typedef struct PFExperimentationGetExperimentsRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFExperimentationGetExperimentsRequest;

/// <summary>
/// PFExperimentationExperiment data model.
/// </summary>
typedef struct PFExperimentationExperiment
{
    /// <summary>
    /// (Optional) Description of the experiment.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* description;

    /// <summary>
    /// (Optional) When experiment should end/was ended.
    /// </summary>
    _Maybenull_ time_t const* endDate;

    /// <summary>
    /// (Optional) Id of the exclusion group for this experiment.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* exclusionGroupId;

    /// <summary>
    /// (Optional) Percentage of exclusion group traffic that will see this experiment.
    /// </summary>
    _Maybenull_ uint32_t const* exclusionGroupTrafficAllocation;

    /// <summary>
    /// (Optional) Type of experiment.
    /// </summary>
    _Maybenull_ PFExperimentationExperimentType const* experimentType;

    /// <summary>
    /// (Optional) Id of the experiment.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

    /// <summary>
    /// (Optional) Friendly name of the experiment.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* name;

    /// <summary>
    /// (Optional) Id of the segment to which this experiment applies. Defaults to the 'All Players'
    /// segment.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* segmentId;

    /// <summary>
    /// When experiment should start/was started.
    /// </summary>
    time_t startDate;

    /// <summary>
    /// (Optional) State experiment is currently in.
    /// </summary>
    _Maybenull_ PFExperimentationExperimentState const* state;

    /// <summary>
    /// (Optional) List of title player account IDs that automatically receive treatments in the experiment,
    /// but are not included when calculating experiment metrics.
    /// </summary>
    _Maybenull_ _Field_size_(titlePlayerAccountTestIdsCount) const char* const* titlePlayerAccountTestIds;

    /// <summary>
    /// Count of titlePlayerAccountTestIds
    /// </summary>
    uint32_t titlePlayerAccountTestIdsCount;

    /// <summary>
    /// (Optional) List of variants for the experiment.
    /// </summary>
    _Maybenull_ _Field_size_(variantsCount) PFExperimentationVariant const* const* variants;

    /// <summary>
    /// Count of variants
    /// </summary>
    uint32_t variantsCount;

} PFExperimentationExperiment;

/// <summary>
/// PFExperimentationGetExperimentsResult data model.
/// </summary>
typedef struct PFExperimentationGetExperimentsResult
{
    /// <summary>
    /// (Optional) List of experiments for the title.
    /// </summary>
    _Maybenull_ _Field_size_(experimentsCount) PFExperimentationExperiment const* const* experiments;

    /// <summary>
    /// Count of experiments
    /// </summary>
    uint32_t experimentsCount;

} PFExperimentationGetExperimentsResult;

/// <summary>
/// PFExperimentationGetLatestScorecardRequest data model. Given a title entity token and experiment
/// details, will return the latest available scorecard.
/// </summary>
typedef struct PFExperimentationGetLatestScorecardRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The ID of the experiment.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* experimentId;

} PFExperimentationGetLatestScorecardRequest;

/// <summary>
/// PFExperimentationMetricData data model.
/// </summary>
typedef struct PFExperimentationMetricData
{
    /// <summary>
    /// The upper bound of the confidence interval for the relative delta (Delta.RelativeValue).
    /// </summary>
    double confidenceIntervalEnd;

    /// <summary>
    /// The lower bound of the confidence interval for the relative delta (Delta.RelativeValue).
    /// </summary>
    double confidenceIntervalStart;

    /// <summary>
    /// The absolute delta between TreatmentStats.Average and ControlStats.Average.
    /// </summary>
    float deltaAbsoluteChange;

    /// <summary>
    /// The relative delta ratio between TreatmentStats.Average and ControlStats.Average.
    /// </summary>
    float deltaRelativeChange;

    /// <summary>
    /// (Optional) The machine name of the metric.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* internalName;

    /// <summary>
    /// (Optional) Indicates if a movement was detected on that metric.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* movement;

    /// <summary>
    /// (Optional) The readable name of the metric.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* name;

    /// <summary>
    /// The expectation that a movement is real.
    /// </summary>
    float pMove;

    /// <summary>
    /// The p-value resulting from the statistical test run for this metric.
    /// </summary>
    float pValue;

    /// <summary>
    /// The threshold for observing sample ratio mismatch.
    /// </summary>
    float pValueThreshold;

    /// <summary>
    /// (Optional) Indicates if the movement is statistically significant.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* statSigLevel;

    /// <summary>
    /// Observed standard deviation value of the metric.
    /// </summary>
    float stdDev;

    /// <summary>
    /// Observed average value of the metric.
    /// </summary>
    float value;

} PFExperimentationMetricData;

/// <summary>
/// PFExperimentationScorecardDataRow data model.
/// </summary>
typedef struct PFExperimentationScorecardDataRow
{
    /// <summary>
    /// Represents whether the variant is control or not.
    /// </summary>
    bool isControl;

    /// <summary>
    /// (Optional) Data of the analysis with the internal name of the metric as the key and an object
    /// of metric data as value.
    /// </summary>
    _Maybenull_ _Field_size_(metricDataRowsCount) struct PFExperimentationMetricDataDictionaryEntry const* metricDataRows;

    /// <summary>
    /// Count of metricDataRows
    /// </summary>
    uint32_t metricDataRowsCount;

    /// <summary>
    /// Represents the player count in the variant.
    /// </summary>
    uint32_t playerCount;

    /// <summary>
    /// (Optional) Name of the variant of analysis.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* variantName;

} PFExperimentationScorecardDataRow;

/// <summary>
/// PFExperimentationScorecard data model.
/// </summary>
typedef struct PFExperimentationScorecard
{
    /// <summary>
    /// (Optional) Represents the date the scorecard was generated.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* dateGenerated;

    /// <summary>
    /// (Optional) Represents the duration of scorecard analysis.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* duration;

    /// <summary>
    /// Represents the number of events processed for the generation of this scorecard.
    /// </summary>
    double eventsProcessed;

    /// <summary>
    /// (Optional) Id of the experiment.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* experimentId;

    /// <summary>
    /// (Optional) Friendly name of the experiment.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* experimentName;

    /// <summary>
    /// (Optional) Represents the latest compute job status.
    /// </summary>
    _Maybenull_ PFExperimentationAnalysisTaskState const* latestJobStatus;

    /// <summary>
    /// Represents the presence of a sample ratio mismatch in the scorecard data.
    /// </summary>
    bool sampleRatioMismatch;

    /// <summary>
    /// (Optional) Scorecard containing list of analysis.
    /// </summary>
    _Maybenull_ _Field_size_(scorecardDataRowsCount) PFExperimentationScorecardDataRow const* const* scorecardDataRows;

    /// <summary>
    /// Count of scorecardDataRows
    /// </summary>
    uint32_t scorecardDataRowsCount;

} PFExperimentationScorecard;

/// <summary>
/// PFExperimentationGetLatestScorecardResult data model.
/// </summary>
typedef struct PFExperimentationGetLatestScorecardResult
{
    /// <summary>
    /// (Optional) Scorecard for the experiment of the title.
    /// </summary>
    _Maybenull_ PFExperimentationScorecard const* scorecard;

} PFExperimentationGetLatestScorecardResult;

/// <summary>
/// PFExperimentationGetTreatmentAssignmentRequest data model. Given a title player or a title entity
/// token, returns the treatment variants and variables assigned to the entity across all running experiments.
/// </summary>
typedef struct PFExperimentationGetTreatmentAssignmentRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

} PFExperimentationGetTreatmentAssignmentRequest;

/// <summary>
/// PFExperimentationGetTreatmentAssignmentResult data model.
/// </summary>
typedef struct PFExperimentationGetTreatmentAssignmentResult
{
    /// <summary>
    /// (Optional) Treatment assignment for the entity.
    /// </summary>
    _Maybenull_ PFTreatmentAssignment const* treatmentAssignment;

} PFExperimentationGetTreatmentAssignmentResult;

/// <summary>
/// PFExperimentationStartExperimentRequest data model. Given a title entity token and an experiment
/// ID, this API starts the experiment.
/// </summary>
typedef struct PFExperimentationStartExperimentRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// The ID of the experiment to start.
    /// </summary>
    _Null_terminated_ const char* experimentId;

} PFExperimentationStartExperimentRequest;

/// <summary>
/// PFExperimentationStopExperimentRequest data model. Given a title entity token and an experiment ID,
/// this API stops the experiment if it is running.
/// </summary>
typedef struct PFExperimentationStopExperimentRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// The ID of the experiment to stop.
    /// </summary>
    _Null_terminated_ const char* experimentId;

} PFExperimentationStopExperimentRequest;

/// <summary>
/// PFExperimentationUpdateExclusionGroupRequest data model. Given an entity token and exclusion group
/// details this API updates the exclusion group.
/// </summary>
typedef struct PFExperimentationUpdateExclusionGroupRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) Description of the exclusion group.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* description;

    /// <summary>
    /// The ID of the exclusion group to update.
    /// </summary>
    _Null_terminated_ const char* exclusionGroupId;

    /// <summary>
    /// Friendly name of the exclusion group.
    /// </summary>
    _Null_terminated_ const char* name;

} PFExperimentationUpdateExclusionGroupRequest;

/// <summary>
/// PFExperimentationUpdateExperimentRequest data model. Given a title entity token and experiment details,
/// this API updates the experiment. If an experiment is already running, only the description and duration
/// properties can be updated.
/// </summary>
typedef struct PFExperimentationUpdateExperimentRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) Description of the experiment.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* description;

    /// <summary>
    /// (Optional) When experiment should end.
    /// </summary>
    _Maybenull_ time_t const* endDate;

    /// <summary>
    /// (Optional) Id of the exclusion group.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* exclusionGroupId;

    /// <summary>
    /// (Optional) Percentage of exclusion group traffic that will see this experiment.
    /// </summary>
    _Maybenull_ uint32_t const* exclusionGroupTrafficAllocation;

    /// <summary>
    /// (Optional) Type of experiment.
    /// </summary>
    _Maybenull_ PFExperimentationExperimentType const* experimentType;

    /// <summary>
    /// Id of the experiment.
    /// </summary>
    _Null_terminated_ const char* id;

    /// <summary>
    /// Friendly name of the experiment.
    /// </summary>
    _Null_terminated_ const char* name;

    /// <summary>
    /// (Optional) Id of the segment to which this experiment applies. Defaults to the 'All Players'
    /// segment.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* segmentId;

    /// <summary>
    /// When experiment should start.
    /// </summary>
    time_t startDate;

    /// <summary>
    /// (Optional) List of title player account IDs that automatically receive treatments in the experiment,
    /// but are not included when calculating experiment metrics.
    /// </summary>
    _Maybenull_ _Field_size_(titlePlayerAccountTestIdsCount) const char* const* titlePlayerAccountTestIds;

    /// <summary>
    /// Count of titlePlayerAccountTestIds
    /// </summary>
    uint32_t titlePlayerAccountTestIdsCount;

    /// <summary>
    /// List of variants for the experiment.
    /// </summary>
    _Field_size_(variantsCount) PFExperimentationVariant const* const* variants;

    /// <summary>
    /// Count of variants
    /// </summary>
    uint32_t variantsCount;

} PFExperimentationUpdateExperimentRequest;

/// <summary>
/// Dictionary entry for an associative array with PFExperimentationMetricData values.
/// </summary>
typedef struct PFExperimentationMetricDataDictionaryEntry
{
    _Null_terminated_ const char* key;
    PFExperimentationMetricData const* value;
} PFExperimentationMetricDataDictionaryEntry;

#pragma pop_macro("IN")

}
