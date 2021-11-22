#include "stdafx.h"
#include "ScheduledTaskDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace ScheduledTask
{

JsonValue AbortTaskInstanceRequest::ToJson() const
{
    return AbortTaskInstanceRequest::ToJson(this->Model());
}

JsonValue AbortTaskInstanceRequest::ToJson(const PFScheduledTaskAbortTaskInstanceRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "TaskInstanceId", input.taskInstanceId);
    return output;
}

JsonValue ActionsOnPlayersInSegmentTaskParameter::ToJson() const
{
    return ActionsOnPlayersInSegmentTaskParameter::ToJson(this->Model());
}

JsonValue ActionsOnPlayersInSegmentTaskParameter::ToJson(const PFScheduledTaskActionsOnPlayersInSegmentTaskParameter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ActionId", input.actionId);
    JsonUtils::ObjectAddMember(output, "SegmentId", input.segmentId);
    return output;
}

void ActionsOnPlayersInSegmentTaskParameter::FromJson(const JsonValue& input)
{
    String actionId{};
    JsonUtils::ObjectGetMember(input, "ActionId", actionId);
    this->SetActionId(std::move(actionId));

    String segmentId{};
    JsonUtils::ObjectGetMember(input, "SegmentId", segmentId);
    this->SetSegmentId(std::move(segmentId));
}

size_t ActionsOnPlayersInSegmentTaskParameter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFScheduledTaskActionsOnPlayersInSegmentTaskParameter const*> ActionsOnPlayersInSegmentTaskParameter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ActionsOnPlayersInSegmentTaskParameter>(&this->Model());
}

size_t ActionsOnPlayersInSegmentTaskParameter::RequiredBufferSize(const PFScheduledTaskActionsOnPlayersInSegmentTaskParameter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.actionId)
    {
        requiredSize += (std::strlen(model.actionId) + 1);
    }
    if (model.segmentId)
    {
        requiredSize += (std::strlen(model.segmentId) + 1);
    }
    return requiredSize;
}

HRESULT ActionsOnPlayersInSegmentTaskParameter::Copy(const PFScheduledTaskActionsOnPlayersInSegmentTaskParameter& input, PFScheduledTaskActionsOnPlayersInSegmentTaskParameter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.actionId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.actionId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.segmentId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.segmentId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CreateActionsOnPlayerSegmentTaskRequest::ToJson() const
{
    return CreateActionsOnPlayerSegmentTaskRequest::ToJson(this->Model());
}

JsonValue CreateActionsOnPlayerSegmentTaskRequest::ToJson(const PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Description", input.description);
    JsonUtils::ObjectAddMember(output, "IsActive", input.isActive);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    JsonUtils::ObjectAddMember<ActionsOnPlayersInSegmentTaskParameter>(output, "Parameter", input.parameter);
    JsonUtils::ObjectAddMember(output, "Schedule", input.schedule);
    return output;
}

void CreateTaskResult::FromJson(const JsonValue& input)
{
    String taskId{};
    JsonUtils::ObjectGetMember(input, "TaskId", taskId);
    this->SetTaskId(std::move(taskId));
}

size_t CreateTaskResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFScheduledTaskCreateTaskResult const*> CreateTaskResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreateTaskResult>(&this->Model());
}

size_t CreateTaskResult::RequiredBufferSize(const PFScheduledTaskCreateTaskResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.taskId)
    {
        requiredSize += (std::strlen(model.taskId) + 1);
    }
    return requiredSize;
}

HRESULT CreateTaskResult::Copy(const PFScheduledTaskCreateTaskResult& input, PFScheduledTaskCreateTaskResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.taskId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.taskId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CloudScriptTaskParameter::ToJson() const
{
    return CloudScriptTaskParameter::ToJson(this->Model());
}

JsonValue CloudScriptTaskParameter::ToJson(const PFScheduledTaskCloudScriptTaskParameter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Argument", input.argument);
    JsonUtils::ObjectAddMember(output, "FunctionName", input.functionName);
    return output;
}

void CloudScriptTaskParameter::FromJson(const JsonValue& input)
{
    JsonObject argument{};
    JsonUtils::ObjectGetMember(input, "Argument", argument);
    this->SetArgument(std::move(argument));

    String functionName{};
    JsonUtils::ObjectGetMember(input, "FunctionName", functionName);
    this->SetFunctionName(std::move(functionName));
}

size_t CloudScriptTaskParameter::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFScheduledTaskCloudScriptTaskParameter const*> CloudScriptTaskParameter::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CloudScriptTaskParameter>(&this->Model());
}

size_t CloudScriptTaskParameter::RequiredBufferSize(const PFScheduledTaskCloudScriptTaskParameter& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.argument.stringValue)
    {
    requiredSize += (std::strlen(model.argument.stringValue) + 1);
    }
    if (model.functionName)
    {
        requiredSize += (std::strlen(model.functionName) + 1);
    }
    return requiredSize;
}

HRESULT CloudScriptTaskParameter::Copy(const PFScheduledTaskCloudScriptTaskParameter& input, PFScheduledTaskCloudScriptTaskParameter& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.argument.stringValue);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.argument.stringValue = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.functionName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.functionName = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CreateCloudScriptTaskRequest::ToJson() const
{
    return CreateCloudScriptTaskRequest::ToJson(this->Model());
}

JsonValue CreateCloudScriptTaskRequest::ToJson(const PFScheduledTaskCreateCloudScriptTaskRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Description", input.description);
    JsonUtils::ObjectAddMember(output, "IsActive", input.isActive);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    JsonUtils::ObjectAddMember<CloudScriptTaskParameter>(output, "Parameter", input.parameter);
    JsonUtils::ObjectAddMember(output, "Schedule", input.schedule);
    return output;
}

JsonValue InsightsScalingTaskParameter::ToJson() const
{
    return InsightsScalingTaskParameter::ToJson(this->Model());
}

JsonValue InsightsScalingTaskParameter::ToJson(const PFScheduledTaskInsightsScalingTaskParameter& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Level", input.level);
    return output;
}

JsonValue CreateInsightsScheduledScalingTaskRequest::ToJson() const
{
    return CreateInsightsScheduledScalingTaskRequest::ToJson(this->Model());
}

JsonValue CreateInsightsScheduledScalingTaskRequest::ToJson(const PFScheduledTaskCreateInsightsScheduledScalingTaskRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Description", input.description);
    JsonUtils::ObjectAddMember(output, "IsActive", input.isActive);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    JsonUtils::ObjectAddMember<InsightsScalingTaskParameter>(output, "Parameter", input.parameter);
    JsonUtils::ObjectAddMember(output, "Schedule", input.schedule);
    return output;
}

JsonValue DeleteTaskRequest::ToJson() const
{
    return DeleteTaskRequest::ToJson(this->Model());
}

JsonValue DeleteTaskRequest::ToJson(const PFScheduledTaskDeleteTaskRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<NameIdentifier>(output, "Identifier", input.identifier);
    return output;
}

JsonValue GetTaskInstanceRequest::ToJson() const
{
    return GetTaskInstanceRequest::ToJson(this->Model());
}

JsonValue GetTaskInstanceRequest::ToJson(const PFScheduledTaskGetTaskInstanceRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "TaskInstanceId", input.taskInstanceId);
    return output;
}

void ActionsOnPlayersInSegmentTaskSummary::FromJson(const JsonValue& input)
{
    StdExtra::optional<time_t> completedAt{};
    JsonUtils::ObjectGetMemberTime(input, "CompletedAt", completedAt);
    this->SetCompletedAt(std::move(completedAt));

    String errorMessage{};
    JsonUtils::ObjectGetMember(input, "ErrorMessage", errorMessage);
    this->SetErrorMessage(std::move(errorMessage));

    StdExtra::optional<bool> errorWasFatal{};
    JsonUtils::ObjectGetMember(input, "ErrorWasFatal", errorWasFatal);
    this->SetErrorWasFatal(std::move(errorWasFatal));

    StdExtra::optional<double> estimatedSecondsRemaining{};
    JsonUtils::ObjectGetMember(input, "EstimatedSecondsRemaining", estimatedSecondsRemaining);
    this->SetEstimatedSecondsRemaining(std::move(estimatedSecondsRemaining));

    StdExtra::optional<double> percentComplete{};
    JsonUtils::ObjectGetMember(input, "PercentComplete", percentComplete);
    this->SetPercentComplete(std::move(percentComplete));

    String scheduledByUserId{};
    JsonUtils::ObjectGetMember(input, "ScheduledByUserId", scheduledByUserId);
    this->SetScheduledByUserId(std::move(scheduledByUserId));

    JsonUtils::ObjectGetMemberTime(input, "StartedAt", this->m_model.startedAt);

    StdExtra::optional<PFScheduledTaskTaskInstanceStatus> status{};
    JsonUtils::ObjectGetMember(input, "Status", status);
    this->SetStatus(std::move(status));

    StdExtra::optional<NameIdentifier> taskIdentifier{};
    JsonUtils::ObjectGetMember(input, "TaskIdentifier", taskIdentifier);
    if (taskIdentifier)
    {
        this->SetTaskIdentifier(std::move(*taskIdentifier));
    }

    String taskInstanceId{};
    JsonUtils::ObjectGetMember(input, "TaskInstanceId", taskInstanceId);
    this->SetTaskInstanceId(std::move(taskInstanceId));

    StdExtra::optional<int32_t> totalPlayersInSegment{};
    JsonUtils::ObjectGetMember(input, "TotalPlayersInSegment", totalPlayersInSegment);
    this->SetTotalPlayersInSegment(std::move(totalPlayersInSegment));

    StdExtra::optional<int32_t> totalPlayersProcessed{};
    JsonUtils::ObjectGetMember(input, "TotalPlayersProcessed", totalPlayersProcessed);
    this->SetTotalPlayersProcessed(std::move(totalPlayersProcessed));
}

size_t ActionsOnPlayersInSegmentTaskSummary::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFScheduledTaskActionsOnPlayersInSegmentTaskSummary const*> ActionsOnPlayersInSegmentTaskSummary::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ActionsOnPlayersInSegmentTaskSummary>(&this->Model());
}

size_t ActionsOnPlayersInSegmentTaskSummary::RequiredBufferSize(const PFScheduledTaskActionsOnPlayersInSegmentTaskSummary& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.completedAt)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.errorMessage)
    {
        requiredSize += (std::strlen(model.errorMessage) + 1);
    }
    if (model.errorWasFatal)
    {
        requiredSize += (alignof(bool) + sizeof(bool));
    }
    if (model.estimatedSecondsRemaining)
    {
        requiredSize += (alignof(double) + sizeof(double));
    }
    if (model.percentComplete)
    {
        requiredSize += (alignof(double) + sizeof(double));
    }
    if (model.scheduledByUserId)
    {
        requiredSize += (std::strlen(model.scheduledByUserId) + 1);
    }
    if (model.status)
    {
        requiredSize += (alignof(PFScheduledTaskTaskInstanceStatus) + sizeof(PFScheduledTaskTaskInstanceStatus));
    }
    if (model.taskIdentifier)
    {
        requiredSize += NameIdentifier::RequiredBufferSize(*model.taskIdentifier);
    }
    if (model.taskInstanceId)
    {
        requiredSize += (std::strlen(model.taskInstanceId) + 1);
    }
    if (model.totalPlayersInSegment)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    if (model.totalPlayersProcessed)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    return requiredSize;
}

HRESULT ActionsOnPlayersInSegmentTaskSummary::Copy(const PFScheduledTaskActionsOnPlayersInSegmentTaskSummary& input, PFScheduledTaskActionsOnPlayersInSegmentTaskSummary& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.completedAt); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.completedAt = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.errorMessage); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.errorMessage = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.errorWasFatal); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.errorWasFatal = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.estimatedSecondsRemaining); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.estimatedSecondsRemaining = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.percentComplete); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.percentComplete = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.scheduledByUserId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.scheduledByUserId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.status); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.status = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<NameIdentifier>(input.taskIdentifier); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.taskIdentifier = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.taskInstanceId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.taskInstanceId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.totalPlayersInSegment); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.totalPlayersInSegment = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.totalPlayersProcessed); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.totalPlayersProcessed = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetActionsOnPlayersInSegmentTaskInstanceResult::FromJson(const JsonValue& input)
{
    StdExtra::optional<ActionsOnPlayersInSegmentTaskParameter> parameter{};
    JsonUtils::ObjectGetMember(input, "Parameter", parameter);
    if (parameter)
    {
        this->SetParameter(std::move(*parameter));
    }

    StdExtra::optional<ActionsOnPlayersInSegmentTaskSummary> summary{};
    JsonUtils::ObjectGetMember(input, "Summary", summary);
    if (summary)
    {
        this->SetSummary(std::move(*summary));
    }
}

size_t GetActionsOnPlayersInSegmentTaskInstanceResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult const*> GetActionsOnPlayersInSegmentTaskInstanceResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetActionsOnPlayersInSegmentTaskInstanceResult>(&this->Model());
}

size_t GetActionsOnPlayersInSegmentTaskInstanceResult::RequiredBufferSize(const PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.parameter)
    {
        requiredSize += ActionsOnPlayersInSegmentTaskParameter::RequiredBufferSize(*model.parameter);
    }
    if (model.summary)
    {
        requiredSize += ActionsOnPlayersInSegmentTaskSummary::RequiredBufferSize(*model.summary);
    }
    return requiredSize;
}

HRESULT GetActionsOnPlayersInSegmentTaskInstanceResult::Copy(const PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult& input, PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<ActionsOnPlayersInSegmentTaskParameter>(input.parameter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.parameter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<ActionsOnPlayersInSegmentTaskSummary>(input.summary); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.summary = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void CloudScriptTaskSummary::FromJson(const JsonValue& input)
{
    StdExtra::optional<time_t> completedAt{};
    JsonUtils::ObjectGetMemberTime(input, "CompletedAt", completedAt);
    this->SetCompletedAt(std::move(completedAt));

    StdExtra::optional<double> estimatedSecondsRemaining{};
    JsonUtils::ObjectGetMember(input, "EstimatedSecondsRemaining", estimatedSecondsRemaining);
    this->SetEstimatedSecondsRemaining(std::move(estimatedSecondsRemaining));

    StdExtra::optional<double> percentComplete{};
    JsonUtils::ObjectGetMember(input, "PercentComplete", percentComplete);
    this->SetPercentComplete(std::move(percentComplete));

    StdExtra::optional<ExecuteCloudScriptResult> result{};
    JsonUtils::ObjectGetMember(input, "Result", result);
    if (result)
    {
        this->SetResult(std::move(*result));
    }

    String scheduledByUserId{};
    JsonUtils::ObjectGetMember(input, "ScheduledByUserId", scheduledByUserId);
    this->SetScheduledByUserId(std::move(scheduledByUserId));

    JsonUtils::ObjectGetMemberTime(input, "StartedAt", this->m_model.startedAt);

    StdExtra::optional<PFScheduledTaskTaskInstanceStatus> status{};
    JsonUtils::ObjectGetMember(input, "Status", status);
    this->SetStatus(std::move(status));

    StdExtra::optional<NameIdentifier> taskIdentifier{};
    JsonUtils::ObjectGetMember(input, "TaskIdentifier", taskIdentifier);
    if (taskIdentifier)
    {
        this->SetTaskIdentifier(std::move(*taskIdentifier));
    }

    String taskInstanceId{};
    JsonUtils::ObjectGetMember(input, "TaskInstanceId", taskInstanceId);
    this->SetTaskInstanceId(std::move(taskInstanceId));
}

size_t CloudScriptTaskSummary::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFScheduledTaskCloudScriptTaskSummary const*> CloudScriptTaskSummary::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CloudScriptTaskSummary>(&this->Model());
}

size_t CloudScriptTaskSummary::RequiredBufferSize(const PFScheduledTaskCloudScriptTaskSummary& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.completedAt)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.estimatedSecondsRemaining)
    {
        requiredSize += (alignof(double) + sizeof(double));
    }
    if (model.percentComplete)
    {
        requiredSize += (alignof(double) + sizeof(double));
    }
    if (model.result)
    {
        requiredSize += ExecuteCloudScriptResult::RequiredBufferSize(*model.result);
    }
    if (model.scheduledByUserId)
    {
        requiredSize += (std::strlen(model.scheduledByUserId) + 1);
    }
    if (model.status)
    {
        requiredSize += (alignof(PFScheduledTaskTaskInstanceStatus) + sizeof(PFScheduledTaskTaskInstanceStatus));
    }
    if (model.taskIdentifier)
    {
        requiredSize += NameIdentifier::RequiredBufferSize(*model.taskIdentifier);
    }
    if (model.taskInstanceId)
    {
        requiredSize += (std::strlen(model.taskInstanceId) + 1);
    }
    return requiredSize;
}

HRESULT CloudScriptTaskSummary::Copy(const PFScheduledTaskCloudScriptTaskSummary& input, PFScheduledTaskCloudScriptTaskSummary& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.completedAt); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.completedAt = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.estimatedSecondsRemaining); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.estimatedSecondsRemaining = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.percentComplete); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.percentComplete = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<ExecuteCloudScriptResult>(input.result); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.result = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.scheduledByUserId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.scheduledByUserId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.status); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.status = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<NameIdentifier>(input.taskIdentifier); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.taskIdentifier = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.taskInstanceId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.taskInstanceId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetCloudScriptTaskInstanceResult::FromJson(const JsonValue& input)
{
    StdExtra::optional<CloudScriptTaskParameter> parameter{};
    JsonUtils::ObjectGetMember(input, "Parameter", parameter);
    if (parameter)
    {
        this->SetParameter(std::move(*parameter));
    }

    StdExtra::optional<CloudScriptTaskSummary> summary{};
    JsonUtils::ObjectGetMember(input, "Summary", summary);
    if (summary)
    {
        this->SetSummary(std::move(*summary));
    }
}

size_t GetCloudScriptTaskInstanceResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFScheduledTaskGetCloudScriptTaskInstanceResult const*> GetCloudScriptTaskInstanceResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetCloudScriptTaskInstanceResult>(&this->Model());
}

size_t GetCloudScriptTaskInstanceResult::RequiredBufferSize(const PFScheduledTaskGetCloudScriptTaskInstanceResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.parameter)
    {
        requiredSize += CloudScriptTaskParameter::RequiredBufferSize(*model.parameter);
    }
    if (model.summary)
    {
        requiredSize += CloudScriptTaskSummary::RequiredBufferSize(*model.summary);
    }
    return requiredSize;
}

HRESULT GetCloudScriptTaskInstanceResult::Copy(const PFScheduledTaskGetCloudScriptTaskInstanceResult& input, PFScheduledTaskGetCloudScriptTaskInstanceResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<CloudScriptTaskParameter>(input.parameter); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.parameter = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<CloudScriptTaskSummary>(input.summary); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.summary = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetTaskInstancesRequest::ToJson() const
{
    return GetTaskInstancesRequest::ToJson(this->Model());
}

JsonValue GetTaskInstancesRequest::ToJson(const PFScheduledTaskGetTaskInstancesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberTime(output, "StartedAtRangeFrom", input.startedAtRangeFrom);
    JsonUtils::ObjectAddMemberTime(output, "StartedAtRangeTo", input.startedAtRangeTo);
    JsonUtils::ObjectAddMember(output, "StatusFilter", input.statusFilter);
    JsonUtils::ObjectAddMember<NameIdentifier>(output, "TaskIdentifier", input.taskIdentifier);
    return output;
}

void TaskInstanceBasicSummary::FromJson(const JsonValue& input)
{
    StdExtra::optional<time_t> completedAt{};
    JsonUtils::ObjectGetMemberTime(input, "CompletedAt", completedAt);
    this->SetCompletedAt(std::move(completedAt));

    String errorMessage{};
    JsonUtils::ObjectGetMember(input, "ErrorMessage", errorMessage);
    this->SetErrorMessage(std::move(errorMessage));

    StdExtra::optional<double> estimatedSecondsRemaining{};
    JsonUtils::ObjectGetMember(input, "EstimatedSecondsRemaining", estimatedSecondsRemaining);
    this->SetEstimatedSecondsRemaining(std::move(estimatedSecondsRemaining));

    StdExtra::optional<double> percentComplete{};
    JsonUtils::ObjectGetMember(input, "PercentComplete", percentComplete);
    this->SetPercentComplete(std::move(percentComplete));

    String scheduledByUserId{};
    JsonUtils::ObjectGetMember(input, "ScheduledByUserId", scheduledByUserId);
    this->SetScheduledByUserId(std::move(scheduledByUserId));

    JsonUtils::ObjectGetMemberTime(input, "StartedAt", this->m_model.startedAt);

    StdExtra::optional<PFScheduledTaskTaskInstanceStatus> status{};
    JsonUtils::ObjectGetMember(input, "Status", status);
    this->SetStatus(std::move(status));

    StdExtra::optional<NameIdentifier> taskIdentifier{};
    JsonUtils::ObjectGetMember(input, "TaskIdentifier", taskIdentifier);
    if (taskIdentifier)
    {
        this->SetTaskIdentifier(std::move(*taskIdentifier));
    }

    String taskInstanceId{};
    JsonUtils::ObjectGetMember(input, "TaskInstanceId", taskInstanceId);
    this->SetTaskInstanceId(std::move(taskInstanceId));

    StdExtra::optional<PFScheduledTaskScheduledTaskType> type{};
    JsonUtils::ObjectGetMember(input, "Type", type);
    this->SetType(std::move(type));
}

size_t TaskInstanceBasicSummary::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFScheduledTaskTaskInstanceBasicSummary const*> TaskInstanceBasicSummary::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<TaskInstanceBasicSummary>(&this->Model());
}

size_t TaskInstanceBasicSummary::RequiredBufferSize(const PFScheduledTaskTaskInstanceBasicSummary& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.completedAt)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.errorMessage)
    {
        requiredSize += (std::strlen(model.errorMessage) + 1);
    }
    if (model.estimatedSecondsRemaining)
    {
        requiredSize += (alignof(double) + sizeof(double));
    }
    if (model.percentComplete)
    {
        requiredSize += (alignof(double) + sizeof(double));
    }
    if (model.scheduledByUserId)
    {
        requiredSize += (std::strlen(model.scheduledByUserId) + 1);
    }
    if (model.status)
    {
        requiredSize += (alignof(PFScheduledTaskTaskInstanceStatus) + sizeof(PFScheduledTaskTaskInstanceStatus));
    }
    if (model.taskIdentifier)
    {
        requiredSize += NameIdentifier::RequiredBufferSize(*model.taskIdentifier);
    }
    if (model.taskInstanceId)
    {
        requiredSize += (std::strlen(model.taskInstanceId) + 1);
    }
    if (model.type)
    {
        requiredSize += (alignof(PFScheduledTaskScheduledTaskType) + sizeof(PFScheduledTaskScheduledTaskType));
    }
    return requiredSize;
}

HRESULT TaskInstanceBasicSummary::Copy(const PFScheduledTaskTaskInstanceBasicSummary& input, PFScheduledTaskTaskInstanceBasicSummary& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.completedAt); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.completedAt = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.errorMessage); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.errorMessage = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.estimatedSecondsRemaining); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.estimatedSecondsRemaining = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.percentComplete); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.percentComplete = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.scheduledByUserId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.scheduledByUserId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.status); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.status = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<NameIdentifier>(input.taskIdentifier); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.taskIdentifier = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.taskInstanceId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.taskInstanceId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.type); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.type = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetTaskInstancesResult::FromJson(const JsonValue& input)
{
    ModelVector<TaskInstanceBasicSummary> summaries{};
    JsonUtils::ObjectGetMember<TaskInstanceBasicSummary>(input, "Summaries", summaries);
    this->SetSummaries(std::move(summaries));
}

size_t GetTaskInstancesResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFScheduledTaskGetTaskInstancesResult const*> GetTaskInstancesResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetTaskInstancesResult>(&this->Model());
}

size_t GetTaskInstancesResult::RequiredBufferSize(const PFScheduledTaskGetTaskInstancesResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFScheduledTaskTaskInstanceBasicSummary*) + sizeof(PFScheduledTaskTaskInstanceBasicSummary*) * model.summariesCount);
    for (size_t i = 0; i < model.summariesCount; ++i)
    {
        requiredSize += TaskInstanceBasicSummary::RequiredBufferSize(*model.summaries[i]);
    }
    return requiredSize;
}

HRESULT GetTaskInstancesResult::Copy(const PFScheduledTaskGetTaskInstancesResult& input, PFScheduledTaskGetTaskInstancesResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<TaskInstanceBasicSummary>(input.summaries, input.summariesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.summaries = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetTasksRequest::ToJson() const
{
    return GetTasksRequest::ToJson(this->Model());
}

JsonValue GetTasksRequest::ToJson(const PFScheduledTaskGetTasksRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<NameIdentifier>(output, "Identifier", input.identifier);
    return output;
}

void ScheduledTask::FromJson(const JsonValue& input)
{
    String description{};
    JsonUtils::ObjectGetMember(input, "Description", description);
    this->SetDescription(std::move(description));

    JsonUtils::ObjectGetMember(input, "IsActive", this->m_model.isActive);

    StdExtra::optional<time_t> lastRunTime{};
    JsonUtils::ObjectGetMemberTime(input, "LastRunTime", lastRunTime);
    this->SetLastRunTime(std::move(lastRunTime));

    String name{};
    JsonUtils::ObjectGetMember(input, "Name", name);
    this->SetName(std::move(name));

    StdExtra::optional<time_t> nextRunTime{};
    JsonUtils::ObjectGetMemberTime(input, "NextRunTime", nextRunTime);
    this->SetNextRunTime(std::move(nextRunTime));

    JsonObject parameter{};
    JsonUtils::ObjectGetMember(input, "Parameter", parameter);
    this->SetParameter(std::move(parameter));

    String schedule{};
    JsonUtils::ObjectGetMember(input, "Schedule", schedule);
    this->SetSchedule(std::move(schedule));

    String taskId{};
    JsonUtils::ObjectGetMember(input, "TaskId", taskId);
    this->SetTaskId(std::move(taskId));

    StdExtra::optional<PFScheduledTaskScheduledTaskType> type{};
    JsonUtils::ObjectGetMember(input, "Type", type);
    this->SetType(std::move(type));
}

size_t ScheduledTask::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFScheduledTaskScheduledTask const*> ScheduledTask::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ScheduledTask>(&this->Model());
}

size_t ScheduledTask::RequiredBufferSize(const PFScheduledTaskScheduledTask& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.description)
    {
        requiredSize += (std::strlen(model.description) + 1);
    }
    if (model.lastRunTime)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.name)
    {
        requiredSize += (std::strlen(model.name) + 1);
    }
    if (model.nextRunTime)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.parameter.stringValue)
    {
    requiredSize += (std::strlen(model.parameter.stringValue) + 1);
    }
    if (model.schedule)
    {
        requiredSize += (std::strlen(model.schedule) + 1);
    }
    if (model.taskId)
    {
        requiredSize += (std::strlen(model.taskId) + 1);
    }
    if (model.type)
    {
        requiredSize += (alignof(PFScheduledTaskScheduledTaskType) + sizeof(PFScheduledTaskScheduledTaskType));
    }
    return requiredSize;
}

HRESULT ScheduledTask::Copy(const PFScheduledTaskScheduledTask& input, PFScheduledTaskScheduledTask& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.description); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.description = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.lastRunTime); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lastRunTime = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.name); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.name = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.nextRunTime); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.nextRunTime = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.parameter.stringValue);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.parameter.stringValue = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.schedule); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.schedule = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.taskId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.taskId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.type); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.type = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetTasksResult::FromJson(const JsonValue& input)
{
    ModelVector<ScheduledTask> tasks{};
    JsonUtils::ObjectGetMember<ScheduledTask>(input, "Tasks", tasks);
    this->SetTasks(std::move(tasks));
}

size_t GetTasksResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFScheduledTaskGetTasksResult const*> GetTasksResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetTasksResult>(&this->Model());
}

size_t GetTasksResult::RequiredBufferSize(const PFScheduledTaskGetTasksResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFScheduledTaskScheduledTask*) + sizeof(PFScheduledTaskScheduledTask*) * model.tasksCount);
    for (size_t i = 0; i < model.tasksCount; ++i)
    {
        requiredSize += ScheduledTask::RequiredBufferSize(*model.tasks[i]);
    }
    return requiredSize;
}

HRESULT GetTasksResult::Copy(const PFScheduledTaskGetTasksResult& input, PFScheduledTaskGetTasksResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ScheduledTask>(input.tasks, input.tasksCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.tasks = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RunTaskRequest::ToJson() const
{
    return RunTaskRequest::ToJson(this->Model());
}

JsonValue RunTaskRequest::ToJson(const PFScheduledTaskRunTaskRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<NameIdentifier>(output, "Identifier", input.identifier);
    return output;
}

void RunTaskResult::FromJson(const JsonValue& input)
{
    String taskInstanceId{};
    JsonUtils::ObjectGetMember(input, "TaskInstanceId", taskInstanceId);
    this->SetTaskInstanceId(std::move(taskInstanceId));
}

size_t RunTaskResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFScheduledTaskRunTaskResult const*> RunTaskResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RunTaskResult>(&this->Model());
}

size_t RunTaskResult::RequiredBufferSize(const PFScheduledTaskRunTaskResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.taskInstanceId)
    {
        requiredSize += (std::strlen(model.taskInstanceId) + 1);
    }
    return requiredSize;
}

HRESULT RunTaskResult::Copy(const PFScheduledTaskRunTaskResult& input, PFScheduledTaskRunTaskResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.taskInstanceId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.taskInstanceId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue UpdateTaskRequest::ToJson() const
{
    return UpdateTaskRequest::ToJson(this->Model());
}

JsonValue UpdateTaskRequest::ToJson(const PFScheduledTaskUpdateTaskRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Description", input.description);
    JsonUtils::ObjectAddMember<NameIdentifier>(output, "Identifier", input.identifier);
    JsonUtils::ObjectAddMember(output, "IsActive", input.isActive);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    JsonUtils::ObjectAddMember(output, "Parameter", input.parameter);
    JsonUtils::ObjectAddMember(output, "Schedule", input.schedule);
    JsonUtils::ObjectAddMember(output, "Type", input.type);
    return output;
}

} // namespace ScheduledTask
} // namespace PlayFab
