#pragma once

#include <playfab/cpp/PFCloudScriptDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace CloudScript
{

// CloudScript Classes
class GetCloudScriptRevisionRequest : public Wrappers::PFCloudScriptGetCloudScriptRevisionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptGetCloudScriptRevisionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptGetCloudScriptRevisionRequest& input);

};

class CloudScriptFile : public Wrappers::PFCloudScriptCloudScriptFileWrapper<Allocator>, public InputModel, public OutputModel<PFCloudScriptCloudScriptFile>
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptCloudScriptFileWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptCloudScriptFile& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCloudScriptCloudScriptFile const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCloudScriptCloudScriptFile& model);
    static HRESULT Copy(const PFCloudScriptCloudScriptFile& input, PFCloudScriptCloudScriptFile& output, ModelBuffer& buffer);
};

class GetCloudScriptRevisionResult : public Wrappers::PFCloudScriptGetCloudScriptRevisionResultWrapper<Allocator>, public OutputModel<PFCloudScriptGetCloudScriptRevisionResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptGetCloudScriptRevisionResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCloudScriptGetCloudScriptRevisionResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCloudScriptGetCloudScriptRevisionResult& model);
    static HRESULT Copy(const PFCloudScriptGetCloudScriptRevisionResult& input, PFCloudScriptGetCloudScriptRevisionResult& output, ModelBuffer& buffer);
};

class CloudScriptVersionStatus : public Wrappers::PFCloudScriptCloudScriptVersionStatusWrapper<Allocator>, public OutputModel<PFCloudScriptCloudScriptVersionStatus>
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptCloudScriptVersionStatusWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCloudScriptCloudScriptVersionStatus const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCloudScriptCloudScriptVersionStatus& model);
    static HRESULT Copy(const PFCloudScriptCloudScriptVersionStatus& input, PFCloudScriptCloudScriptVersionStatus& output, ModelBuffer& buffer);
};

class GetCloudScriptVersionsResult : public Wrappers::PFCloudScriptGetCloudScriptVersionsResultWrapper<Allocator>, public OutputModel<PFCloudScriptGetCloudScriptVersionsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptGetCloudScriptVersionsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCloudScriptGetCloudScriptVersionsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCloudScriptGetCloudScriptVersionsResult& model);
    static HRESULT Copy(const PFCloudScriptGetCloudScriptVersionsResult& input, PFCloudScriptGetCloudScriptVersionsResult& output, ModelBuffer& buffer);
};

class SetPublishedRevisionRequest : public Wrappers::PFCloudScriptSetPublishedRevisionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptSetPublishedRevisionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptSetPublishedRevisionRequest& input);

};

class UpdateCloudScriptRequest : public Wrappers::PFCloudScriptUpdateCloudScriptRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptUpdateCloudScriptRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptUpdateCloudScriptRequest& input);

};

class UpdateCloudScriptResult : public Wrappers::PFCloudScriptUpdateCloudScriptResultWrapper<Allocator>, public OutputModel<PFCloudScriptUpdateCloudScriptResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptUpdateCloudScriptResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCloudScriptUpdateCloudScriptResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCloudScriptUpdateCloudScriptResult& model);
    static HRESULT Copy(const PFCloudScriptUpdateCloudScriptResult& input, PFCloudScriptUpdateCloudScriptResult& output, ModelBuffer& buffer);
};

class ExecuteCloudScriptRequest : public Wrappers::PFCloudScriptExecuteCloudScriptRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptExecuteCloudScriptRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptExecuteCloudScriptRequest& input);

};

class ExecuteCloudScriptServerRequest : public Wrappers::PFCloudScriptExecuteCloudScriptServerRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptExecuteCloudScriptServerRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptExecuteCloudScriptServerRequest& input);

};

class ExecuteEntityCloudScriptRequest : public Wrappers::PFCloudScriptExecuteEntityCloudScriptRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptExecuteEntityCloudScriptRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptExecuteEntityCloudScriptRequest& input);

};

class ExecuteFunctionRequest : public Wrappers::PFCloudScriptExecuteFunctionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptExecuteFunctionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptExecuteFunctionRequest& input);

};

class FunctionExecutionError : public Wrappers::PFCloudScriptFunctionExecutionErrorWrapper<Allocator>, public InputModel, public OutputModel<PFCloudScriptFunctionExecutionError>
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptFunctionExecutionErrorWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptFunctionExecutionError& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCloudScriptFunctionExecutionError const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCloudScriptFunctionExecutionError& model);
    static HRESULT Copy(const PFCloudScriptFunctionExecutionError& input, PFCloudScriptFunctionExecutionError& output, ModelBuffer& buffer);
};

class ExecuteFunctionResult : public Wrappers::PFCloudScriptExecuteFunctionResultWrapper<Allocator>, public InputModel, public OutputModel<PFCloudScriptExecuteFunctionResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptExecuteFunctionResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptExecuteFunctionResult& input);

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCloudScriptExecuteFunctionResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCloudScriptExecuteFunctionResult& model);
    static HRESULT Copy(const PFCloudScriptExecuteFunctionResult& input, PFCloudScriptExecuteFunctionResult& output, ModelBuffer& buffer);
};

class GetFunctionRequest : public Wrappers::PFCloudScriptGetFunctionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptGetFunctionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptGetFunctionRequest& input);

};

class GetFunctionResult : public Wrappers::PFCloudScriptGetFunctionResultWrapper<Allocator>, public OutputModel<PFCloudScriptGetFunctionResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptGetFunctionResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCloudScriptGetFunctionResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCloudScriptGetFunctionResult& model);
    static HRESULT Copy(const PFCloudScriptGetFunctionResult& input, PFCloudScriptGetFunctionResult& output, ModelBuffer& buffer);
};

class ListFunctionsRequest : public Wrappers::PFCloudScriptListFunctionsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptListFunctionsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptListFunctionsRequest& input);

};

class FunctionModel : public Wrappers::PFCloudScriptFunctionModelWrapper<Allocator>, public OutputModel<PFCloudScriptFunctionModel>
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptFunctionModelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCloudScriptFunctionModel const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCloudScriptFunctionModel& model);
    static HRESULT Copy(const PFCloudScriptFunctionModel& input, PFCloudScriptFunctionModel& output, ModelBuffer& buffer);
};

class ListFunctionsResult : public Wrappers::PFCloudScriptListFunctionsResultWrapper<Allocator>, public OutputModel<PFCloudScriptListFunctionsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptListFunctionsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCloudScriptListFunctionsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCloudScriptListFunctionsResult& model);
    static HRESULT Copy(const PFCloudScriptListFunctionsResult& input, PFCloudScriptListFunctionsResult& output, ModelBuffer& buffer);
};

class HttpFunctionModel : public Wrappers::PFCloudScriptHttpFunctionModelWrapper<Allocator>, public OutputModel<PFCloudScriptHttpFunctionModel>
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptHttpFunctionModelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCloudScriptHttpFunctionModel const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCloudScriptHttpFunctionModel& model);
    static HRESULT Copy(const PFCloudScriptHttpFunctionModel& input, PFCloudScriptHttpFunctionModel& output, ModelBuffer& buffer);
};

class ListHttpFunctionsResult : public Wrappers::PFCloudScriptListHttpFunctionsResultWrapper<Allocator>, public OutputModel<PFCloudScriptListHttpFunctionsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptListHttpFunctionsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCloudScriptListHttpFunctionsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCloudScriptListHttpFunctionsResult& model);
    static HRESULT Copy(const PFCloudScriptListHttpFunctionsResult& input, PFCloudScriptListHttpFunctionsResult& output, ModelBuffer& buffer);
};

class QueuedFunctionModel : public Wrappers::PFCloudScriptQueuedFunctionModelWrapper<Allocator>, public OutputModel<PFCloudScriptQueuedFunctionModel>
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptQueuedFunctionModelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCloudScriptQueuedFunctionModel const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCloudScriptQueuedFunctionModel& model);
    static HRESULT Copy(const PFCloudScriptQueuedFunctionModel& input, PFCloudScriptQueuedFunctionModel& output, ModelBuffer& buffer);
};

class ListQueuedFunctionsResult : public Wrappers::PFCloudScriptListQueuedFunctionsResultWrapper<Allocator>, public OutputModel<PFCloudScriptListQueuedFunctionsResult>
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptListQueuedFunctionsResultWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFCloudScriptListQueuedFunctionsResult const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFCloudScriptListQueuedFunctionsResult& model);
    static HRESULT Copy(const PFCloudScriptListQueuedFunctionsResult& input, PFCloudScriptListQueuedFunctionsResult& output, ModelBuffer& buffer);
};

class PostFunctionResultForEntityTriggeredActionRequest : public Wrappers::PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptPostFunctionResultForEntityTriggeredActionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptPostFunctionResultForEntityTriggeredActionRequest& input);

};

class PostFunctionResultForFunctionExecutionRequest : public Wrappers::PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptPostFunctionResultForFunctionExecutionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptPostFunctionResultForFunctionExecutionRequest& input);

};

class PlayStreamEventEnvelopeModel : public Wrappers::PFCloudScriptPlayStreamEventEnvelopeModelWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptPlayStreamEventEnvelopeModelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptPlayStreamEventEnvelopeModel& input);

};

class PostFunctionResultForPlayerTriggeredActionRequest : public Wrappers::PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptPostFunctionResultForPlayerTriggeredActionRequest& input);

};

class PostFunctionResultForScheduledTaskRequest : public Wrappers::PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptPostFunctionResultForScheduledTaskRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptPostFunctionResultForScheduledTaskRequest& input);

};

class RegisterHttpFunctionRequest : public Wrappers::PFCloudScriptRegisterHttpFunctionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptRegisterHttpFunctionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptRegisterHttpFunctionRequest& input);

};

class RegisterQueuedFunctionRequest : public Wrappers::PFCloudScriptRegisterQueuedFunctionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptRegisterQueuedFunctionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptRegisterQueuedFunctionRequest& input);

};

class UnregisterFunctionRequest : public Wrappers::PFCloudScriptUnregisterFunctionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFCloudScriptUnregisterFunctionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFCloudScriptUnregisterFunctionRequest& input);

};

} // namespace CloudScript
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
