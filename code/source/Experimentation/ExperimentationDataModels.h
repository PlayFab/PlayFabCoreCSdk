#pragma once

#include <playfab/cpp/PFExperimentationDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Experimentation
{

// Experimentation Classes
class CreateExclusionGroupRequest : public Wrappers::PFExperimentationCreateExclusionGroupRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationCreateExclusionGroupRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFExperimentationCreateExclusionGroupRequest& input);

};

class CreateExclusionGroupResult : public Wrappers::PFExperimentationCreateExclusionGroupResultWrapper<Allocator>, public OutputModel<PFExperimentationCreateExclusionGroupResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationCreateExclusionGroupResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFExperimentationCreateExclusionGroupResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFExperimentationCreateExclusionGroupResult& model);
    static HRESULT Copy(const PFExperimentationCreateExclusionGroupResult& input, PFExperimentationCreateExclusionGroupResult& output, ModelBuffer& buffer);
};

class Variant : public Wrappers::PFExperimentationVariantWrapper<Allocator>, public InputModel, public OutputModel<PFExperimentationVariant>
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationVariantWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFExperimentationVariant& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFExperimentationVariant const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFExperimentationVariant& model);
    static HRESULT Copy(const PFExperimentationVariant& input, PFExperimentationVariant& output, ModelBuffer& buffer);
};

class CreateExperimentRequest : public Wrappers::PFExperimentationCreateExperimentRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationCreateExperimentRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFExperimentationCreateExperimentRequest& input);

};

class CreateExperimentResult : public Wrappers::PFExperimentationCreateExperimentResultWrapper<Allocator>, public OutputModel<PFExperimentationCreateExperimentResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationCreateExperimentResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFExperimentationCreateExperimentResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFExperimentationCreateExperimentResult& model);
    static HRESULT Copy(const PFExperimentationCreateExperimentResult& input, PFExperimentationCreateExperimentResult& output, ModelBuffer& buffer);
};

class DeleteExclusionGroupRequest : public Wrappers::PFExperimentationDeleteExclusionGroupRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationDeleteExclusionGroupRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFExperimentationDeleteExclusionGroupRequest& input);

};

class DeleteExperimentRequest : public Wrappers::PFExperimentationDeleteExperimentRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationDeleteExperimentRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFExperimentationDeleteExperimentRequest& input);

};

class GetExclusionGroupsRequest : public Wrappers::PFExperimentationGetExclusionGroupsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationGetExclusionGroupsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFExperimentationGetExclusionGroupsRequest& input);

};

class ExperimentExclusionGroup : public Wrappers::PFExperimentationExperimentExclusionGroupWrapper<Allocator>, public OutputModel<PFExperimentationExperimentExclusionGroup>
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationExperimentExclusionGroupWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFExperimentationExperimentExclusionGroup const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFExperimentationExperimentExclusionGroup& model);
    static HRESULT Copy(const PFExperimentationExperimentExclusionGroup& input, PFExperimentationExperimentExclusionGroup& output, ModelBuffer& buffer);
};

class GetExclusionGroupsResult : public Wrappers::PFExperimentationGetExclusionGroupsResultWrapper<Allocator>, public OutputModel<PFExperimentationGetExclusionGroupsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationGetExclusionGroupsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFExperimentationGetExclusionGroupsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFExperimentationGetExclusionGroupsResult& model);
    static HRESULT Copy(const PFExperimentationGetExclusionGroupsResult& input, PFExperimentationGetExclusionGroupsResult& output, ModelBuffer& buffer);
};

class GetExclusionGroupTrafficRequest : public Wrappers::PFExperimentationGetExclusionGroupTrafficRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationGetExclusionGroupTrafficRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFExperimentationGetExclusionGroupTrafficRequest& input);

};

class ExclusionGroupTrafficAllocation : public Wrappers::PFExperimentationExclusionGroupTrafficAllocationWrapper<Allocator>, public OutputModel<PFExperimentationExclusionGroupTrafficAllocation>
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationExclusionGroupTrafficAllocationWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFExperimentationExclusionGroupTrafficAllocation const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFExperimentationExclusionGroupTrafficAllocation& model);
    static HRESULT Copy(const PFExperimentationExclusionGroupTrafficAllocation& input, PFExperimentationExclusionGroupTrafficAllocation& output, ModelBuffer& buffer);
};

class GetExclusionGroupTrafficResult : public Wrappers::PFExperimentationGetExclusionGroupTrafficResultWrapper<Allocator>, public OutputModel<PFExperimentationGetExclusionGroupTrafficResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationGetExclusionGroupTrafficResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFExperimentationGetExclusionGroupTrafficResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFExperimentationGetExclusionGroupTrafficResult& model);
    static HRESULT Copy(const PFExperimentationGetExclusionGroupTrafficResult& input, PFExperimentationGetExclusionGroupTrafficResult& output, ModelBuffer& buffer);
};

class GetExperimentsRequest : public Wrappers::PFExperimentationGetExperimentsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationGetExperimentsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFExperimentationGetExperimentsRequest& input);

};

class Experiment : public Wrappers::PFExperimentationExperimentWrapper<Allocator>, public OutputModel<PFExperimentationExperiment>
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationExperimentWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFExperimentationExperiment const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFExperimentationExperiment& model);
    static HRESULT Copy(const PFExperimentationExperiment& input, PFExperimentationExperiment& output, ModelBuffer& buffer);
};

class GetExperimentsResult : public Wrappers::PFExperimentationGetExperimentsResultWrapper<Allocator>, public OutputModel<PFExperimentationGetExperimentsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationGetExperimentsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFExperimentationGetExperimentsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFExperimentationGetExperimentsResult& model);
    static HRESULT Copy(const PFExperimentationGetExperimentsResult& input, PFExperimentationGetExperimentsResult& output, ModelBuffer& buffer);
};

class GetLatestScorecardRequest : public Wrappers::PFExperimentationGetLatestScorecardRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationGetLatestScorecardRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFExperimentationGetLatestScorecardRequest& input);

};

class MetricData : public Wrappers::PFExperimentationMetricDataWrapper<Allocator>, public OutputModel<PFExperimentationMetricData>
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationMetricDataWrapper<Allocator>;
    using ModelWrapperType::ModelType;
    using DictionaryEntryType = ModelWrapperType::DictionaryEntryType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFExperimentationMetricData const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFExperimentationMetricData& model);
    static HRESULT Copy(const PFExperimentationMetricData& input, PFExperimentationMetricData& output, ModelBuffer& buffer);
};

class ScorecardDataRow : public Wrappers::PFExperimentationScorecardDataRowWrapper<Allocator>, public OutputModel<PFExperimentationScorecardDataRow>
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationScorecardDataRowWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFExperimentationScorecardDataRow const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFExperimentationScorecardDataRow& model);
    static HRESULT Copy(const PFExperimentationScorecardDataRow& input, PFExperimentationScorecardDataRow& output, ModelBuffer& buffer);
};

class Scorecard : public Wrappers::PFExperimentationScorecardWrapper<Allocator>, public OutputModel<PFExperimentationScorecard>
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationScorecardWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFExperimentationScorecard const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFExperimentationScorecard& model);
    static HRESULT Copy(const PFExperimentationScorecard& input, PFExperimentationScorecard& output, ModelBuffer& buffer);
};

class GetLatestScorecardResult : public Wrappers::PFExperimentationGetLatestScorecardResultWrapper<Allocator>, public OutputModel<PFExperimentationGetLatestScorecardResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationGetLatestScorecardResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFExperimentationGetLatestScorecardResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFExperimentationGetLatestScorecardResult& model);
    static HRESULT Copy(const PFExperimentationGetLatestScorecardResult& input, PFExperimentationGetLatestScorecardResult& output, ModelBuffer& buffer);
};

class GetTreatmentAssignmentRequest : public Wrappers::PFExperimentationGetTreatmentAssignmentRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationGetTreatmentAssignmentRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFExperimentationGetTreatmentAssignmentRequest& input);

};

class GetTreatmentAssignmentResult : public Wrappers::PFExperimentationGetTreatmentAssignmentResultWrapper<Allocator>, public OutputModel<PFExperimentationGetTreatmentAssignmentResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationGetTreatmentAssignmentResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFExperimentationGetTreatmentAssignmentResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFExperimentationGetTreatmentAssignmentResult& model);
    static HRESULT Copy(const PFExperimentationGetTreatmentAssignmentResult& input, PFExperimentationGetTreatmentAssignmentResult& output, ModelBuffer& buffer);
};

class StartExperimentRequest : public Wrappers::PFExperimentationStartExperimentRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationStartExperimentRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFExperimentationStartExperimentRequest& input);

};

class StopExperimentRequest : public Wrappers::PFExperimentationStopExperimentRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationStopExperimentRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFExperimentationStopExperimentRequest& input);

};

class UpdateExclusionGroupRequest : public Wrappers::PFExperimentationUpdateExclusionGroupRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationUpdateExclusionGroupRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFExperimentationUpdateExclusionGroupRequest& input);

};

class UpdateExperimentRequest : public Wrappers::PFExperimentationUpdateExperimentRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFExperimentationUpdateExperimentRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFExperimentationUpdateExperimentRequest& input);

};

} // namespace Experimentation
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
