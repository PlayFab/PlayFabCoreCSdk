#pragma once

#include <playfab/cpp/PFAnalyticsDataModelWrappers.h>
#include <Shared/SharedDataModels.h>
#include "BaseModel.h"

namespace PlayFab
{
namespace Analytics
{

// Analytics Classes
class DeviceInfoRequest : public Wrappers::PFAnalyticsDeviceInfoRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsDeviceInfoRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAnalyticsDeviceInfoRequest& input);

};

class WriteClientCharacterEventRequest : public Wrappers::PFAnalyticsWriteClientCharacterEventRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsWriteClientCharacterEventRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAnalyticsWriteClientCharacterEventRequest& input);

};

class WriteEventResponse : public Wrappers::PFAnalyticsWriteEventResponseWrapper<Allocator>, public OutputModel<PFAnalyticsWriteEventResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsWriteEventResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAnalyticsWriteEventResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAnalyticsWriteEventResponse& model);
    static HRESULT Copy(const PFAnalyticsWriteEventResponse& input, PFAnalyticsWriteEventResponse& output, ModelBuffer& buffer);
};

class WriteClientPlayerEventRequest : public Wrappers::PFAnalyticsWriteClientPlayerEventRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsWriteClientPlayerEventRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAnalyticsWriteClientPlayerEventRequest& input);

};

class WriteTitleEventRequest : public Wrappers::PFAnalyticsWriteTitleEventRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsWriteTitleEventRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAnalyticsWriteTitleEventRequest& input);

};

class WriteServerCharacterEventRequest : public Wrappers::PFAnalyticsWriteServerCharacterEventRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsWriteServerCharacterEventRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAnalyticsWriteServerCharacterEventRequest& input);

};

class WriteServerPlayerEventRequest : public Wrappers::PFAnalyticsWriteServerPlayerEventRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsWriteServerPlayerEventRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAnalyticsWriteServerPlayerEventRequest& input);

};

class InsightsEmptyRequest : public Wrappers::PFAnalyticsInsightsEmptyRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsInsightsEmptyRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAnalyticsInsightsEmptyRequest& input);

};

class InsightsPerformanceLevel : public Wrappers::PFAnalyticsInsightsPerformanceLevelWrapper<Allocator>, public OutputModel<PFAnalyticsInsightsPerformanceLevel>
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsInsightsPerformanceLevelWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAnalyticsInsightsPerformanceLevel const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAnalyticsInsightsPerformanceLevel& model);
    static HRESULT Copy(const PFAnalyticsInsightsPerformanceLevel& input, PFAnalyticsInsightsPerformanceLevel& output, ModelBuffer& buffer);
};

class InsightsGetLimitsResponse : public Wrappers::PFAnalyticsInsightsGetLimitsResponseWrapper<Allocator>, public OutputModel<PFAnalyticsInsightsGetLimitsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsInsightsGetLimitsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAnalyticsInsightsGetLimitsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAnalyticsInsightsGetLimitsResponse& model);
    static HRESULT Copy(const PFAnalyticsInsightsGetLimitsResponse& input, PFAnalyticsInsightsGetLimitsResponse& output, ModelBuffer& buffer);
};

class InsightsGetOperationStatusResponse : public Wrappers::PFAnalyticsInsightsGetOperationStatusResponseWrapper<Allocator>, public OutputModel<PFAnalyticsInsightsGetOperationStatusResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsInsightsGetOperationStatusResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAnalyticsInsightsGetOperationStatusResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAnalyticsInsightsGetOperationStatusResponse& model);
    static HRESULT Copy(const PFAnalyticsInsightsGetOperationStatusResponse& input, PFAnalyticsInsightsGetOperationStatusResponse& output, ModelBuffer& buffer);
};

class InsightsGetDetailsResponse : public Wrappers::PFAnalyticsInsightsGetDetailsResponseWrapper<Allocator>, public OutputModel<PFAnalyticsInsightsGetDetailsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsInsightsGetDetailsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAnalyticsInsightsGetDetailsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAnalyticsInsightsGetDetailsResponse& model);
    static HRESULT Copy(const PFAnalyticsInsightsGetDetailsResponse& input, PFAnalyticsInsightsGetDetailsResponse& output, ModelBuffer& buffer);
};

class InsightsGetOperationStatusRequest : public Wrappers::PFAnalyticsInsightsGetOperationStatusRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsInsightsGetOperationStatusRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAnalyticsInsightsGetOperationStatusRequest& input);

};

class InsightsGetPendingOperationsRequest : public Wrappers::PFAnalyticsInsightsGetPendingOperationsRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsInsightsGetPendingOperationsRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAnalyticsInsightsGetPendingOperationsRequest& input);

};

class InsightsGetPendingOperationsResponse : public Wrappers::PFAnalyticsInsightsGetPendingOperationsResponseWrapper<Allocator>, public OutputModel<PFAnalyticsInsightsGetPendingOperationsResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsInsightsGetPendingOperationsResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAnalyticsInsightsGetPendingOperationsResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAnalyticsInsightsGetPendingOperationsResponse& model);
    static HRESULT Copy(const PFAnalyticsInsightsGetPendingOperationsResponse& input, PFAnalyticsInsightsGetPendingOperationsResponse& output, ModelBuffer& buffer);
};

class InsightsSetPerformanceRequest : public Wrappers::PFAnalyticsInsightsSetPerformanceRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsInsightsSetPerformanceRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAnalyticsInsightsSetPerformanceRequest& input);

};

class InsightsOperationResponse : public Wrappers::PFAnalyticsInsightsOperationResponseWrapper<Allocator>, public OutputModel<PFAnalyticsInsightsOperationResponse>
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsInsightsOperationResponseWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // OutputModel
    void FromJson(const JsonValue& input) override;
    size_t RequiredBufferSize() const override;
    Result<PFAnalyticsInsightsOperationResponse const*> Copy(ModelBuffer& buffer) const override;

    static size_t RequiredBufferSize(const PFAnalyticsInsightsOperationResponse& model);
    static HRESULT Copy(const PFAnalyticsInsightsOperationResponse& input, PFAnalyticsInsightsOperationResponse& output, ModelBuffer& buffer);
};

class InsightsSetStorageRetentionRequest : public Wrappers::PFAnalyticsInsightsSetStorageRetentionRequestWrapper<Allocator>, public InputModel
{
public:
    using ModelWrapperType = typename Wrappers::PFAnalyticsInsightsSetStorageRetentionRequestWrapper<Allocator>;
    using ModelWrapperType::ModelType;

    // Constructors
    using ModelWrapperType::ModelWrapperType;

    // InputModel
    JsonValue ToJson() const override;
    static JsonValue ToJson(const PFAnalyticsInsightsSetStorageRetentionRequest& input);

};

} // namespace Analytics
// EnumRange definitions used for Enum (de)serialization
} // namespace PlayFab
