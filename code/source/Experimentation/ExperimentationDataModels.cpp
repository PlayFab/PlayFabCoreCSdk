#include "stdafx.h"
#include "ExperimentationDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Experimentation
{

JsonValue CreateExclusionGroupRequest::ToJson() const
{
    return CreateExclusionGroupRequest::ToJson(this->Model());
}

JsonValue CreateExclusionGroupRequest::ToJson(const PFExperimentationCreateExclusionGroupRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Description", input.description);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    return output;
}

void CreateExclusionGroupResult::FromJson(const JsonValue& input)
{
    String exclusionGroupId{};
    JsonUtils::ObjectGetMember(input, "ExclusionGroupId", exclusionGroupId);
    this->SetExclusionGroupId(std::move(exclusionGroupId));
}

size_t CreateExclusionGroupResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFExperimentationCreateExclusionGroupResult const*> CreateExclusionGroupResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreateExclusionGroupResult>(&this->Model());
}

size_t CreateExclusionGroupResult::RequiredBufferSize(const PFExperimentationCreateExclusionGroupResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.exclusionGroupId)
    {
        requiredSize += (std::strlen(model.exclusionGroupId) + 1);
    }
    return requiredSize;
}

HRESULT CreateExclusionGroupResult::Copy(const PFExperimentationCreateExclusionGroupResult& input, PFExperimentationCreateExclusionGroupResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.exclusionGroupId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.exclusionGroupId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue Variant::ToJson() const
{
    return Variant::ToJson(this->Model());
}

JsonValue Variant::ToJson(const PFExperimentationVariant& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Description", input.description);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    JsonUtils::ObjectAddMember(output, "IsControl", input.isControl);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    JsonUtils::ObjectAddMember(output, "TitleDataOverrideLabel", input.titleDataOverrideLabel);
    JsonUtils::ObjectAddMember(output, "TrafficPercentage", input.trafficPercentage);
    JsonUtils::ObjectAddMemberArray<Variable>(output, "Variables", input.variables, input.variablesCount);
    return output;
}

void Variant::FromJson(const JsonValue& input)
{
    String description{};
    JsonUtils::ObjectGetMember(input, "Description", description);
    this->SetDescription(std::move(description));

    String id{};
    JsonUtils::ObjectGetMember(input, "Id", id);
    this->SetId(std::move(id));

    JsonUtils::ObjectGetMember(input, "IsControl", this->m_model.isControl);

    String name{};
    JsonUtils::ObjectGetMember(input, "Name", name);
    this->SetName(std::move(name));

    String titleDataOverrideLabel{};
    JsonUtils::ObjectGetMember(input, "TitleDataOverrideLabel", titleDataOverrideLabel);
    this->SetTitleDataOverrideLabel(std::move(titleDataOverrideLabel));

    JsonUtils::ObjectGetMember(input, "TrafficPercentage", this->m_model.trafficPercentage);

    ModelVector<Variable> variables{};
    JsonUtils::ObjectGetMember<Variable>(input, "Variables", variables);
    this->SetVariables(std::move(variables));
}

size_t Variant::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFExperimentationVariant const*> Variant::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<Variant>(&this->Model());
}

size_t Variant::RequiredBufferSize(const PFExperimentationVariant& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.description)
    {
        requiredSize += (std::strlen(model.description) + 1);
    }
    if (model.id)
    {
        requiredSize += (std::strlen(model.id) + 1);
    }
    if (model.name)
    {
        requiredSize += (std::strlen(model.name) + 1);
    }
    if (model.titleDataOverrideLabel)
    {
        requiredSize += (std::strlen(model.titleDataOverrideLabel) + 1);
    }
    requiredSize += (alignof(PFVariable*) + sizeof(PFVariable*) * model.variablesCount);
    for (size_t i = 0; i < model.variablesCount; ++i)
    {
        requiredSize += Variable::RequiredBufferSize(*model.variables[i]);
    }
    return requiredSize;
}

HRESULT Variant::Copy(const PFExperimentationVariant& input, PFExperimentationVariant& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.description); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.description = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.id); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.id = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.name); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.name = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.titleDataOverrideLabel); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.titleDataOverrideLabel = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<Variable>(input.variables, input.variablesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.variables = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CreateExperimentRequest::ToJson() const
{
    return CreateExperimentRequest::ToJson(this->Model());
}

JsonValue CreateExperimentRequest::ToJson(const PFExperimentationCreateExperimentRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Description", input.description);
    JsonUtils::ObjectAddMemberTime(output, "EndDate", input.endDate);
    JsonUtils::ObjectAddMember(output, "ExclusionGroupId", input.exclusionGroupId);
    JsonUtils::ObjectAddMember(output, "ExclusionGroupTrafficAllocation", input.exclusionGroupTrafficAllocation);
    JsonUtils::ObjectAddMember(output, "ExperimentType", input.experimentType);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    JsonUtils::ObjectAddMember(output, "SegmentId", input.segmentId);
    JsonUtils::ObjectAddMemberTime(output, "StartDate", input.startDate);
    JsonUtils::ObjectAddMemberArray(output, "TitlePlayerAccountTestIds", input.titlePlayerAccountTestIds, input.titlePlayerAccountTestIdsCount);
    JsonUtils::ObjectAddMemberArray<Variant>(output, "Variants", input.variants, input.variantsCount);
    return output;
}

void CreateExperimentResult::FromJson(const JsonValue& input)
{
    String experimentId{};
    JsonUtils::ObjectGetMember(input, "ExperimentId", experimentId);
    this->SetExperimentId(std::move(experimentId));
}

size_t CreateExperimentResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFExperimentationCreateExperimentResult const*> CreateExperimentResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreateExperimentResult>(&this->Model());
}

size_t CreateExperimentResult::RequiredBufferSize(const PFExperimentationCreateExperimentResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.experimentId)
    {
        requiredSize += (std::strlen(model.experimentId) + 1);
    }
    return requiredSize;
}

HRESULT CreateExperimentResult::Copy(const PFExperimentationCreateExperimentResult& input, PFExperimentationCreateExperimentResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.experimentId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.experimentId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue DeleteExclusionGroupRequest::ToJson() const
{
    return DeleteExclusionGroupRequest::ToJson(this->Model());
}

JsonValue DeleteExclusionGroupRequest::ToJson(const PFExperimentationDeleteExclusionGroupRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ExclusionGroupId", input.exclusionGroupId);
    return output;
}

JsonValue DeleteExperimentRequest::ToJson() const
{
    return DeleteExperimentRequest::ToJson(this->Model());
}

JsonValue DeleteExperimentRequest::ToJson(const PFExperimentationDeleteExperimentRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ExperimentId", input.experimentId);
    return output;
}

JsonValue GetExclusionGroupsRequest::ToJson() const
{
    return GetExclusionGroupsRequest::ToJson(this->Model());
}

JsonValue GetExclusionGroupsRequest::ToJson(const PFExperimentationGetExclusionGroupsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

void ExperimentExclusionGroup::FromJson(const JsonValue& input)
{
    String description{};
    JsonUtils::ObjectGetMember(input, "Description", description);
    this->SetDescription(std::move(description));

    String exclusionGroupId{};
    JsonUtils::ObjectGetMember(input, "ExclusionGroupId", exclusionGroupId);
    this->SetExclusionGroupId(std::move(exclusionGroupId));

    String name{};
    JsonUtils::ObjectGetMember(input, "Name", name);
    this->SetName(std::move(name));
}

size_t ExperimentExclusionGroup::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFExperimentationExperimentExclusionGroup const*> ExperimentExclusionGroup::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ExperimentExclusionGroup>(&this->Model());
}

size_t ExperimentExclusionGroup::RequiredBufferSize(const PFExperimentationExperimentExclusionGroup& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.description)
    {
        requiredSize += (std::strlen(model.description) + 1);
    }
    if (model.exclusionGroupId)
    {
        requiredSize += (std::strlen(model.exclusionGroupId) + 1);
    }
    if (model.name)
    {
        requiredSize += (std::strlen(model.name) + 1);
    }
    return requiredSize;
}

HRESULT ExperimentExclusionGroup::Copy(const PFExperimentationExperimentExclusionGroup& input, PFExperimentationExperimentExclusionGroup& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.description); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.description = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.exclusionGroupId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.exclusionGroupId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.name); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.name = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetExclusionGroupsResult::FromJson(const JsonValue& input)
{
    ModelVector<ExperimentExclusionGroup> exclusionGroups{};
    JsonUtils::ObjectGetMember<ExperimentExclusionGroup>(input, "ExclusionGroups", exclusionGroups);
    this->SetExclusionGroups(std::move(exclusionGroups));
}

size_t GetExclusionGroupsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFExperimentationGetExclusionGroupsResult const*> GetExclusionGroupsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetExclusionGroupsResult>(&this->Model());
}

size_t GetExclusionGroupsResult::RequiredBufferSize(const PFExperimentationGetExclusionGroupsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFExperimentationExperimentExclusionGroup*) + sizeof(PFExperimentationExperimentExclusionGroup*) * model.exclusionGroupsCount);
    for (size_t i = 0; i < model.exclusionGroupsCount; ++i)
    {
        requiredSize += ExperimentExclusionGroup::RequiredBufferSize(*model.exclusionGroups[i]);
    }
    return requiredSize;
}

HRESULT GetExclusionGroupsResult::Copy(const PFExperimentationGetExclusionGroupsResult& input, PFExperimentationGetExclusionGroupsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ExperimentExclusionGroup>(input.exclusionGroups, input.exclusionGroupsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.exclusionGroups = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetExclusionGroupTrafficRequest::ToJson() const
{
    return GetExclusionGroupTrafficRequest::ToJson(this->Model());
}

JsonValue GetExclusionGroupTrafficRequest::ToJson(const PFExperimentationGetExclusionGroupTrafficRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ExclusionGroupId", input.exclusionGroupId);
    return output;
}

void ExclusionGroupTrafficAllocation::FromJson(const JsonValue& input)
{
    String experimentId{};
    JsonUtils::ObjectGetMember(input, "ExperimentId", experimentId);
    this->SetExperimentId(std::move(experimentId));

    JsonUtils::ObjectGetMember(input, "TrafficAllocation", this->m_model.trafficAllocation);
}

size_t ExclusionGroupTrafficAllocation::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFExperimentationExclusionGroupTrafficAllocation const*> ExclusionGroupTrafficAllocation::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ExclusionGroupTrafficAllocation>(&this->Model());
}

size_t ExclusionGroupTrafficAllocation::RequiredBufferSize(const PFExperimentationExclusionGroupTrafficAllocation& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.experimentId)
    {
        requiredSize += (std::strlen(model.experimentId) + 1);
    }
    return requiredSize;
}

HRESULT ExclusionGroupTrafficAllocation::Copy(const PFExperimentationExclusionGroupTrafficAllocation& input, PFExperimentationExclusionGroupTrafficAllocation& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.experimentId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.experimentId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetExclusionGroupTrafficResult::FromJson(const JsonValue& input)
{
    ModelVector<ExclusionGroupTrafficAllocation> trafficAllocations{};
    JsonUtils::ObjectGetMember<ExclusionGroupTrafficAllocation>(input, "TrafficAllocations", trafficAllocations);
    this->SetTrafficAllocations(std::move(trafficAllocations));
}

size_t GetExclusionGroupTrafficResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFExperimentationGetExclusionGroupTrafficResult const*> GetExclusionGroupTrafficResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetExclusionGroupTrafficResult>(&this->Model());
}

size_t GetExclusionGroupTrafficResult::RequiredBufferSize(const PFExperimentationGetExclusionGroupTrafficResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFExperimentationExclusionGroupTrafficAllocation*) + sizeof(PFExperimentationExclusionGroupTrafficAllocation*) * model.trafficAllocationsCount);
    for (size_t i = 0; i < model.trafficAllocationsCount; ++i)
    {
        requiredSize += ExclusionGroupTrafficAllocation::RequiredBufferSize(*model.trafficAllocations[i]);
    }
    return requiredSize;
}

HRESULT GetExclusionGroupTrafficResult::Copy(const PFExperimentationGetExclusionGroupTrafficResult& input, PFExperimentationGetExclusionGroupTrafficResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ExclusionGroupTrafficAllocation>(input.trafficAllocations, input.trafficAllocationsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.trafficAllocations = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetExperimentsRequest::ToJson() const
{
    return GetExperimentsRequest::ToJson(this->Model());
}

JsonValue GetExperimentsRequest::ToJson(const PFExperimentationGetExperimentsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

void Experiment::FromJson(const JsonValue& input)
{
    String description{};
    JsonUtils::ObjectGetMember(input, "Description", description);
    this->SetDescription(std::move(description));

    StdExtra::optional<time_t> endDate{};
    JsonUtils::ObjectGetMemberTime(input, "EndDate", endDate);
    this->SetEndDate(std::move(endDate));

    String exclusionGroupId{};
    JsonUtils::ObjectGetMember(input, "ExclusionGroupId", exclusionGroupId);
    this->SetExclusionGroupId(std::move(exclusionGroupId));

    StdExtra::optional<uint32_t> exclusionGroupTrafficAllocation{};
    JsonUtils::ObjectGetMember(input, "ExclusionGroupTrafficAllocation", exclusionGroupTrafficAllocation);
    this->SetExclusionGroupTrafficAllocation(std::move(exclusionGroupTrafficAllocation));

    StdExtra::optional<PFExperimentationExperimentType> experimentType{};
    JsonUtils::ObjectGetMember(input, "ExperimentType", experimentType);
    this->SetExperimentType(std::move(experimentType));

    String id{};
    JsonUtils::ObjectGetMember(input, "Id", id);
    this->SetId(std::move(id));

    String name{};
    JsonUtils::ObjectGetMember(input, "Name", name);
    this->SetName(std::move(name));

    String segmentId{};
    JsonUtils::ObjectGetMember(input, "SegmentId", segmentId);
    this->SetSegmentId(std::move(segmentId));

    JsonUtils::ObjectGetMemberTime(input, "StartDate", this->m_model.startDate);

    StdExtra::optional<PFExperimentationExperimentState> state{};
    JsonUtils::ObjectGetMember(input, "State", state);
    this->SetState(std::move(state));

    CStringVector titlePlayerAccountTestIds{};
    JsonUtils::ObjectGetMember(input, "TitlePlayerAccountTestIds", titlePlayerAccountTestIds);
    this->SetTitlePlayerAccountTestIds(std::move(titlePlayerAccountTestIds));

    ModelVector<Variant> variants{};
    JsonUtils::ObjectGetMember<Variant>(input, "Variants", variants);
    this->SetVariants(std::move(variants));
}

size_t Experiment::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFExperimentationExperiment const*> Experiment::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<Experiment>(&this->Model());
}

size_t Experiment::RequiredBufferSize(const PFExperimentationExperiment& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.description)
    {
        requiredSize += (std::strlen(model.description) + 1);
    }
    if (model.endDate)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.exclusionGroupId)
    {
        requiredSize += (std::strlen(model.exclusionGroupId) + 1);
    }
    if (model.exclusionGroupTrafficAllocation)
    {
        requiredSize += (alignof(uint32_t) + sizeof(uint32_t));
    }
    if (model.experimentType)
    {
        requiredSize += (alignof(PFExperimentationExperimentType) + sizeof(PFExperimentationExperimentType));
    }
    if (model.id)
    {
        requiredSize += (std::strlen(model.id) + 1);
    }
    if (model.name)
    {
        requiredSize += (std::strlen(model.name) + 1);
    }
    if (model.segmentId)
    {
        requiredSize += (std::strlen(model.segmentId) + 1);
    }
    if (model.state)
    {
        requiredSize += (alignof(PFExperimentationExperimentState) + sizeof(PFExperimentationExperimentState));
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.titlePlayerAccountTestIdsCount);
    for (size_t i = 0; i < model.titlePlayerAccountTestIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.titlePlayerAccountTestIds[i]) + 1);
    }
    requiredSize += (alignof(PFExperimentationVariant*) + sizeof(PFExperimentationVariant*) * model.variantsCount);
    for (size_t i = 0; i < model.variantsCount; ++i)
    {
        requiredSize += Variant::RequiredBufferSize(*model.variants[i]);
    }
    return requiredSize;
}

HRESULT Experiment::Copy(const PFExperimentationExperiment& input, PFExperimentationExperiment& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.description); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.description = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.endDate); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.endDate = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.exclusionGroupId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.exclusionGroupId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.exclusionGroupTrafficAllocation); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.exclusionGroupTrafficAllocation = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.experimentType); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.experimentType = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.id); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.id = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.name); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.name = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.segmentId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.segmentId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.state); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.state = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.titlePlayerAccountTestIds, input.titlePlayerAccountTestIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.titlePlayerAccountTestIds = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<Variant>(input.variants, input.variantsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.variants = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetExperimentsResult::FromJson(const JsonValue& input)
{
    ModelVector<Experiment> experiments{};
    JsonUtils::ObjectGetMember<Experiment>(input, "Experiments", experiments);
    this->SetExperiments(std::move(experiments));
}

size_t GetExperimentsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFExperimentationGetExperimentsResult const*> GetExperimentsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetExperimentsResult>(&this->Model());
}

size_t GetExperimentsResult::RequiredBufferSize(const PFExperimentationGetExperimentsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFExperimentationExperiment*) + sizeof(PFExperimentationExperiment*) * model.experimentsCount);
    for (size_t i = 0; i < model.experimentsCount; ++i)
    {
        requiredSize += Experiment::RequiredBufferSize(*model.experiments[i]);
    }
    return requiredSize;
}

HRESULT GetExperimentsResult::Copy(const PFExperimentationGetExperimentsResult& input, PFExperimentationGetExperimentsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<Experiment>(input.experiments, input.experimentsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.experiments = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetLatestScorecardRequest::ToJson() const
{
    return GetLatestScorecardRequest::ToJson(this->Model());
}

JsonValue GetLatestScorecardRequest::ToJson(const PFExperimentationGetLatestScorecardRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ExperimentId", input.experimentId);
    return output;
}

void MetricData::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "ConfidenceIntervalEnd", this->m_model.confidenceIntervalEnd);

    JsonUtils::ObjectGetMember(input, "ConfidenceIntervalStart", this->m_model.confidenceIntervalStart);

    JsonUtils::ObjectGetMember(input, "DeltaAbsoluteChange", this->m_model.deltaAbsoluteChange);

    JsonUtils::ObjectGetMember(input, "DeltaRelativeChange", this->m_model.deltaRelativeChange);

    String internalName{};
    JsonUtils::ObjectGetMember(input, "InternalName", internalName);
    this->SetInternalName(std::move(internalName));

    String movement{};
    JsonUtils::ObjectGetMember(input, "Movement", movement);
    this->SetMovement(std::move(movement));

    String name{};
    JsonUtils::ObjectGetMember(input, "Name", name);
    this->SetName(std::move(name));

    JsonUtils::ObjectGetMember(input, "PMove", this->m_model.pMove);

    JsonUtils::ObjectGetMember(input, "PValue", this->m_model.pValue);

    JsonUtils::ObjectGetMember(input, "PValueThreshold", this->m_model.pValueThreshold);

    String statSigLevel{};
    JsonUtils::ObjectGetMember(input, "StatSigLevel", statSigLevel);
    this->SetStatSigLevel(std::move(statSigLevel));

    JsonUtils::ObjectGetMember(input, "StdDev", this->m_model.stdDev);

    JsonUtils::ObjectGetMember(input, "Value", this->m_model.value);
}

size_t MetricData::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFExperimentationMetricData const*> MetricData::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<MetricData>(&this->Model());
}

size_t MetricData::RequiredBufferSize(const PFExperimentationMetricData& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.internalName)
    {
        requiredSize += (std::strlen(model.internalName) + 1);
    }
    if (model.movement)
    {
        requiredSize += (std::strlen(model.movement) + 1);
    }
    if (model.name)
    {
        requiredSize += (std::strlen(model.name) + 1);
    }
    if (model.statSigLevel)
    {
        requiredSize += (std::strlen(model.statSigLevel) + 1);
    }
    return requiredSize;
}

HRESULT MetricData::Copy(const PFExperimentationMetricData& input, PFExperimentationMetricData& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.internalName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.internalName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.movement); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.movement = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.name); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.name = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.statSigLevel); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statSigLevel = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void ScorecardDataRow::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "IsControl", this->m_model.isControl);

    ModelDictionaryEntryVector<MetricData> metricDataRows{};
    JsonUtils::ObjectGetMember<MetricData>(input, "MetricDataRows", metricDataRows);
    this->SetMetricDataRows(std::move(metricDataRows));

    JsonUtils::ObjectGetMember(input, "PlayerCount", this->m_model.playerCount);

    String variantName{};
    JsonUtils::ObjectGetMember(input, "VariantName", variantName);
    this->SetVariantName(std::move(variantName));
}

size_t ScorecardDataRow::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFExperimentationScorecardDataRow const*> ScorecardDataRow::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ScorecardDataRow>(&this->Model());
}

size_t ScorecardDataRow::RequiredBufferSize(const PFExperimentationScorecardDataRow& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFExperimentationMetricDataDictionaryEntry) + sizeof(PFExperimentationMetricDataDictionaryEntry) * model.metricDataRowsCount);
    for (size_t i = 0; i < model.metricDataRowsCount; ++i)
    {
        requiredSize += (std::strlen(model.metricDataRows[i].key) + 1);
        requiredSize += MetricData::RequiredBufferSize(*model.metricDataRows[i].value);
    }
    if (model.variantName)
    {
        requiredSize += (std::strlen(model.variantName) + 1);
    }
    return requiredSize;
}

HRESULT ScorecardDataRow::Copy(const PFExperimentationScorecardDataRow& input, PFExperimentationScorecardDataRow& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToDictionary<MetricData>(input.metricDataRows, input.metricDataRowsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.metricDataRows = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.variantName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.variantName = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void Scorecard::FromJson(const JsonValue& input)
{
    String dateGenerated{};
    JsonUtils::ObjectGetMember(input, "DateGenerated", dateGenerated);
    this->SetDateGenerated(std::move(dateGenerated));

    String duration{};
    JsonUtils::ObjectGetMember(input, "Duration", duration);
    this->SetDuration(std::move(duration));

    JsonUtils::ObjectGetMember(input, "EventsProcessed", this->m_model.eventsProcessed);

    String experimentId{};
    JsonUtils::ObjectGetMember(input, "ExperimentId", experimentId);
    this->SetExperimentId(std::move(experimentId));

    String experimentName{};
    JsonUtils::ObjectGetMember(input, "ExperimentName", experimentName);
    this->SetExperimentName(std::move(experimentName));

    StdExtra::optional<PFExperimentationAnalysisTaskState> latestJobStatus{};
    JsonUtils::ObjectGetMember(input, "LatestJobStatus", latestJobStatus);
    this->SetLatestJobStatus(std::move(latestJobStatus));

    JsonUtils::ObjectGetMember(input, "SampleRatioMismatch", this->m_model.sampleRatioMismatch);

    ModelVector<ScorecardDataRow> scorecardDataRows{};
    JsonUtils::ObjectGetMember<ScorecardDataRow>(input, "ScorecardDataRows", scorecardDataRows);
    this->SetScorecardDataRows(std::move(scorecardDataRows));
}

size_t Scorecard::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFExperimentationScorecard const*> Scorecard::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<Scorecard>(&this->Model());
}

size_t Scorecard::RequiredBufferSize(const PFExperimentationScorecard& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.dateGenerated)
    {
        requiredSize += (std::strlen(model.dateGenerated) + 1);
    }
    if (model.duration)
    {
        requiredSize += (std::strlen(model.duration) + 1);
    }
    if (model.experimentId)
    {
        requiredSize += (std::strlen(model.experimentId) + 1);
    }
    if (model.experimentName)
    {
        requiredSize += (std::strlen(model.experimentName) + 1);
    }
    if (model.latestJobStatus)
    {
        requiredSize += (alignof(PFExperimentationAnalysisTaskState) + sizeof(PFExperimentationAnalysisTaskState));
    }
    requiredSize += (alignof(PFExperimentationScorecardDataRow*) + sizeof(PFExperimentationScorecardDataRow*) * model.scorecardDataRowsCount);
    for (size_t i = 0; i < model.scorecardDataRowsCount; ++i)
    {
        requiredSize += ScorecardDataRow::RequiredBufferSize(*model.scorecardDataRows[i]);
    }
    return requiredSize;
}

HRESULT Scorecard::Copy(const PFExperimentationScorecard& input, PFExperimentationScorecard& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.dateGenerated); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.dateGenerated = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.duration); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.duration = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.experimentId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.experimentId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.experimentName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.experimentName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.latestJobStatus); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.latestJobStatus = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<ScorecardDataRow>(input.scorecardDataRows, input.scorecardDataRowsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.scorecardDataRows = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetLatestScorecardResult::FromJson(const JsonValue& input)
{
    StdExtra::optional<Scorecard> scorecard{};
    JsonUtils::ObjectGetMember(input, "Scorecard", scorecard);
    if (scorecard)
    {
        this->SetScorecard(std::move(*scorecard));
    }
}

size_t GetLatestScorecardResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFExperimentationGetLatestScorecardResult const*> GetLatestScorecardResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetLatestScorecardResult>(&this->Model());
}

size_t GetLatestScorecardResult::RequiredBufferSize(const PFExperimentationGetLatestScorecardResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.scorecard)
    {
        requiredSize += Scorecard::RequiredBufferSize(*model.scorecard);
    }
    return requiredSize;
}

HRESULT GetLatestScorecardResult::Copy(const PFExperimentationGetLatestScorecardResult& input, PFExperimentationGetLatestScorecardResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<Scorecard>(input.scorecard); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.scorecard = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetTreatmentAssignmentRequest::ToJson() const
{
    return GetTreatmentAssignmentRequest::ToJson(this->Model());
}

JsonValue GetTreatmentAssignmentRequest::ToJson(const PFExperimentationGetTreatmentAssignmentRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    return output;
}

void GetTreatmentAssignmentResult::FromJson(const JsonValue& input)
{
    StdExtra::optional<TreatmentAssignment> treatmentAssignment{};
    JsonUtils::ObjectGetMember(input, "TreatmentAssignment", treatmentAssignment);
    if (treatmentAssignment)
    {
        this->SetTreatmentAssignment(std::move(*treatmentAssignment));
    }
}

size_t GetTreatmentAssignmentResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFExperimentationGetTreatmentAssignmentResult const*> GetTreatmentAssignmentResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetTreatmentAssignmentResult>(&this->Model());
}

size_t GetTreatmentAssignmentResult::RequiredBufferSize(const PFExperimentationGetTreatmentAssignmentResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.treatmentAssignment)
    {
        requiredSize += TreatmentAssignment::RequiredBufferSize(*model.treatmentAssignment);
    }
    return requiredSize;
}

HRESULT GetTreatmentAssignmentResult::Copy(const PFExperimentationGetTreatmentAssignmentResult& input, PFExperimentationGetTreatmentAssignmentResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<TreatmentAssignment>(input.treatmentAssignment); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.treatmentAssignment = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue StartExperimentRequest::ToJson() const
{
    return StartExperimentRequest::ToJson(this->Model());
}

JsonValue StartExperimentRequest::ToJson(const PFExperimentationStartExperimentRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ExperimentId", input.experimentId);
    return output;
}

JsonValue StopExperimentRequest::ToJson() const
{
    return StopExperimentRequest::ToJson(this->Model());
}

JsonValue StopExperimentRequest::ToJson(const PFExperimentationStopExperimentRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ExperimentId", input.experimentId);
    return output;
}

JsonValue UpdateExclusionGroupRequest::ToJson() const
{
    return UpdateExclusionGroupRequest::ToJson(this->Model());
}

JsonValue UpdateExclusionGroupRequest::ToJson(const PFExperimentationUpdateExclusionGroupRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Description", input.description);
    JsonUtils::ObjectAddMember(output, "ExclusionGroupId", input.exclusionGroupId);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    return output;
}

JsonValue UpdateExperimentRequest::ToJson() const
{
    return UpdateExperimentRequest::ToJson(this->Model());
}

JsonValue UpdateExperimentRequest::ToJson(const PFExperimentationUpdateExperimentRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Description", input.description);
    JsonUtils::ObjectAddMemberTime(output, "EndDate", input.endDate);
    JsonUtils::ObjectAddMember(output, "ExclusionGroupId", input.exclusionGroupId);
    JsonUtils::ObjectAddMember(output, "ExclusionGroupTrafficAllocation", input.exclusionGroupTrafficAllocation);
    JsonUtils::ObjectAddMember(output, "ExperimentType", input.experimentType);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    JsonUtils::ObjectAddMember(output, "SegmentId", input.segmentId);
    JsonUtils::ObjectAddMemberTime(output, "StartDate", input.startDate);
    JsonUtils::ObjectAddMemberArray(output, "TitlePlayerAccountTestIds", input.titlePlayerAccountTestIds, input.titlePlayerAccountTestIdsCount);
    JsonUtils::ObjectAddMemberArray<Variant>(output, "Variants", input.variants, input.variantsCount);
    return output;
}

} // namespace Experimentation
} // namespace PlayFab
