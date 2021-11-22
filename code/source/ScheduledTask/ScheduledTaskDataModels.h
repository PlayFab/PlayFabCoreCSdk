#pragma once

#include <playfab/cpp/PFScheduledTaskDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace ScheduledTask
{

// ScheduledTask Classes
class AbortTaskInstanceRequest : public Wrappers::PFScheduledTaskAbortTaskInstanceRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskAbortTaskInstanceRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFScheduledTaskAbortTaskInstanceRequest& input);

};

class ActionsOnPlayersInSegmentTaskParameter : public Wrappers::PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper<Allocator>, public InputModel, public OutputModel<PFScheduledTaskActionsOnPlayersInSegmentTaskParameter>
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskActionsOnPlayersInSegmentTaskParameterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFScheduledTaskActionsOnPlayersInSegmentTaskParameter& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFScheduledTaskActionsOnPlayersInSegmentTaskParameter const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFScheduledTaskActionsOnPlayersInSegmentTaskParameter& model);
    static HRESULT Copy(const PFScheduledTaskActionsOnPlayersInSegmentTaskParameter& input, PFScheduledTaskActionsOnPlayersInSegmentTaskParameter& output, ModelBuffer& buffer);
};

class CreateActionsOnPlayerSegmentTaskRequest : public Wrappers::PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFScheduledTaskCreateActionsOnPlayerSegmentTaskRequest& input);

};

class CreateTaskResult : public Wrappers::PFScheduledTaskCreateTaskResultWrapper<Allocator>, public OutputModel<PFScheduledTaskCreateTaskResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskCreateTaskResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFScheduledTaskCreateTaskResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFScheduledTaskCreateTaskResult& model);
    static HRESULT Copy(const PFScheduledTaskCreateTaskResult& input, PFScheduledTaskCreateTaskResult& output, ModelBuffer& buffer);
};

class CloudScriptTaskParameter : public Wrappers::PFScheduledTaskCloudScriptTaskParameterWrapper<Allocator>, public InputModel, public OutputModel<PFScheduledTaskCloudScriptTaskParameter>
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskCloudScriptTaskParameterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFScheduledTaskCloudScriptTaskParameter& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFScheduledTaskCloudScriptTaskParameter const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFScheduledTaskCloudScriptTaskParameter& model);
    static HRESULT Copy(const PFScheduledTaskCloudScriptTaskParameter& input, PFScheduledTaskCloudScriptTaskParameter& output, ModelBuffer& buffer);
};

class CreateCloudScriptTaskRequest : public Wrappers::PFScheduledTaskCreateCloudScriptTaskRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskCreateCloudScriptTaskRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFScheduledTaskCreateCloudScriptTaskRequest& input);

};

class InsightsScalingTaskParameter : public Wrappers::PFScheduledTaskInsightsScalingTaskParameterWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskInsightsScalingTaskParameterWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFScheduledTaskInsightsScalingTaskParameter& input);

};

class CreateInsightsScheduledScalingTaskRequest : public Wrappers::PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskCreateInsightsScheduledScalingTaskRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFScheduledTaskCreateInsightsScheduledScalingTaskRequest& input);

};

class DeleteTaskRequest : public Wrappers::PFScheduledTaskDeleteTaskRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskDeleteTaskRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFScheduledTaskDeleteTaskRequest& input);

};

class GetTaskInstanceRequest : public Wrappers::PFScheduledTaskGetTaskInstanceRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskGetTaskInstanceRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFScheduledTaskGetTaskInstanceRequest& input);

};

class ActionsOnPlayersInSegmentTaskSummary : public Wrappers::PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper<Allocator>, public OutputModel<PFScheduledTaskActionsOnPlayersInSegmentTaskSummary>
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskActionsOnPlayersInSegmentTaskSummaryWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFScheduledTaskActionsOnPlayersInSegmentTaskSummary const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFScheduledTaskActionsOnPlayersInSegmentTaskSummary& model);
    static HRESULT Copy(const PFScheduledTaskActionsOnPlayersInSegmentTaskSummary& input, PFScheduledTaskActionsOnPlayersInSegmentTaskSummary& output, ModelBuffer& buffer);
};

class GetActionsOnPlayersInSegmentTaskInstanceResult : public Wrappers::PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResultWrapper<Allocator>, public OutputModel<PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult& model);
    static HRESULT Copy(const PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult& input, PFScheduledTaskGetActionsOnPlayersInSegmentTaskInstanceResult& output, ModelBuffer& buffer);
};

class CloudScriptTaskSummary : public Wrappers::PFScheduledTaskCloudScriptTaskSummaryWrapper<Allocator>, public OutputModel<PFScheduledTaskCloudScriptTaskSummary>
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskCloudScriptTaskSummaryWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFScheduledTaskCloudScriptTaskSummary const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFScheduledTaskCloudScriptTaskSummary& model);
    static HRESULT Copy(const PFScheduledTaskCloudScriptTaskSummary& input, PFScheduledTaskCloudScriptTaskSummary& output, ModelBuffer& buffer);
};

class GetCloudScriptTaskInstanceResult : public Wrappers::PFScheduledTaskGetCloudScriptTaskInstanceResultWrapper<Allocator>, public OutputModel<PFScheduledTaskGetCloudScriptTaskInstanceResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskGetCloudScriptTaskInstanceResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFScheduledTaskGetCloudScriptTaskInstanceResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFScheduledTaskGetCloudScriptTaskInstanceResult& model);
    static HRESULT Copy(const PFScheduledTaskGetCloudScriptTaskInstanceResult& input, PFScheduledTaskGetCloudScriptTaskInstanceResult& output, ModelBuffer& buffer);
};

class GetTaskInstancesRequest : public Wrappers::PFScheduledTaskGetTaskInstancesRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskGetTaskInstancesRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFScheduledTaskGetTaskInstancesRequest& input);

};

class TaskInstanceBasicSummary : public Wrappers::PFScheduledTaskTaskInstanceBasicSummaryWrapper<Allocator>, public OutputModel<PFScheduledTaskTaskInstanceBasicSummary>
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskTaskInstanceBasicSummaryWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFScheduledTaskTaskInstanceBasicSummary const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFScheduledTaskTaskInstanceBasicSummary& model);
    static HRESULT Copy(const PFScheduledTaskTaskInstanceBasicSummary& input, PFScheduledTaskTaskInstanceBasicSummary& output, ModelBuffer& buffer);
};

class GetTaskInstancesResult : public Wrappers::PFScheduledTaskGetTaskInstancesResultWrapper<Allocator>, public OutputModel<PFScheduledTaskGetTaskInstancesResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskGetTaskInstancesResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFScheduledTaskGetTaskInstancesResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFScheduledTaskGetTaskInstancesResult& model);
    static HRESULT Copy(const PFScheduledTaskGetTaskInstancesResult& input, PFScheduledTaskGetTaskInstancesResult& output, ModelBuffer& buffer);
};

class GetTasksRequest : public Wrappers::PFScheduledTaskGetTasksRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskGetTasksRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFScheduledTaskGetTasksRequest& input);

};

class ScheduledTask : public Wrappers::PFScheduledTaskScheduledTaskWrapper<Allocator>, public OutputModel<PFScheduledTaskScheduledTask>
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskScheduledTaskWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFScheduledTaskScheduledTask const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFScheduledTaskScheduledTask& model);
    static HRESULT Copy(const PFScheduledTaskScheduledTask& input, PFScheduledTaskScheduledTask& output, ModelBuffer& buffer);
};

class GetTasksResult : public Wrappers::PFScheduledTaskGetTasksResultWrapper<Allocator>, public OutputModel<PFScheduledTaskGetTasksResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskGetTasksResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFScheduledTaskGetTasksResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFScheduledTaskGetTasksResult& model);
    static HRESULT Copy(const PFScheduledTaskGetTasksResult& input, PFScheduledTaskGetTasksResult& output, ModelBuffer& buffer);
};

class RunTaskRequest : public Wrappers::PFScheduledTaskRunTaskRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskRunTaskRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFScheduledTaskRunTaskRequest& input);

};

class RunTaskResult : public Wrappers::PFScheduledTaskRunTaskResultWrapper<Allocator>, public OutputModel<PFScheduledTaskRunTaskResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskRunTaskResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFScheduledTaskRunTaskResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFScheduledTaskRunTaskResult& model);
    static HRESULT Copy(const PFScheduledTaskRunTaskResult& input, PFScheduledTaskRunTaskResult& output, ModelBuffer& buffer);
};

class UpdateTaskRequest : public Wrappers::PFScheduledTaskUpdateTaskRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFScheduledTaskUpdateTaskRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFScheduledTaskUpdateTaskRequest& input);

};

} // namespace ScheduledTask
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
