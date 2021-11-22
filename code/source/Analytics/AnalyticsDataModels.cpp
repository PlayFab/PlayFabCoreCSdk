#include "stdafx.h"
#include "AnalyticsDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Analytics
{

JsonValue DeviceInfoRequest::ToJson() const
{
    return DeviceInfoRequest::ToJson(this->Model());
}

JsonValue DeviceInfoRequest::ToJson(const PFAnalyticsDeviceInfoRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Info", input.info);
    return output;
}

JsonValue WriteClientCharacterEventRequest::ToJson() const
{
    return WriteClientCharacterEventRequest::ToJson(this->Model());
}

JsonValue WriteClientCharacterEventRequest::ToJson(const PFAnalyticsWriteClientCharacterEventRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Body", input.body);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "EventName", input.eventName);
    JsonUtils::ObjectAddMemberTime(output, "Timestamp", input.timestamp);
    return output;
}

void WriteEventResponse::FromJson(const JsonValue& input)
{
    String eventId{};
    JsonUtils::ObjectGetMember(input, "EventId", eventId);
    this->SetEventId(std::move(eventId));
}

size_t WriteEventResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAnalyticsWriteEventResponse const*> WriteEventResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<WriteEventResponse>(&this->Model());
}

size_t WriteEventResponse::RequiredBufferSize(const PFAnalyticsWriteEventResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.eventId)
    {
        requiredSize += (std::strlen(model.eventId) + 1);
    }
    return requiredSize;
}

HRESULT WriteEventResponse::Copy(const PFAnalyticsWriteEventResponse& input, PFAnalyticsWriteEventResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.eventId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.eventId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue WriteClientPlayerEventRequest::ToJson() const
{
    return WriteClientPlayerEventRequest::ToJson(this->Model());
}

JsonValue WriteClientPlayerEventRequest::ToJson(const PFAnalyticsWriteClientPlayerEventRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Body", input.body);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "EventName", input.eventName);
    JsonUtils::ObjectAddMemberTime(output, "Timestamp", input.timestamp);
    return output;
}

JsonValue WriteTitleEventRequest::ToJson() const
{
    return WriteTitleEventRequest::ToJson(this->Model());
}

JsonValue WriteTitleEventRequest::ToJson(const PFAnalyticsWriteTitleEventRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Body", input.body);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "EventName", input.eventName);
    JsonUtils::ObjectAddMemberTime(output, "Timestamp", input.timestamp);
    return output;
}

JsonValue WriteServerCharacterEventRequest::ToJson() const
{
    return WriteServerCharacterEventRequest::ToJson(this->Model());
}

JsonValue WriteServerCharacterEventRequest::ToJson(const PFAnalyticsWriteServerCharacterEventRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Body", input.body);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "EventName", input.eventName);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMemberTime(output, "Timestamp", input.timestamp);
    return output;
}

JsonValue WriteServerPlayerEventRequest::ToJson() const
{
    return WriteServerPlayerEventRequest::ToJson(this->Model());
}

JsonValue WriteServerPlayerEventRequest::ToJson(const PFAnalyticsWriteServerPlayerEventRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Body", input.body);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "EventName", input.eventName);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMemberTime(output, "Timestamp", input.timestamp);
    return output;
}

JsonValue InsightsEmptyRequest::ToJson() const
{
    return InsightsEmptyRequest::ToJson(this->Model());
}

JsonValue InsightsEmptyRequest::ToJson(const PFAnalyticsInsightsEmptyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

void InsightsPerformanceLevel::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "ActiveEventExports", this->m_model.activeEventExports);

    JsonUtils::ObjectGetMember(input, "CacheSizeMB", this->m_model.cacheSizeMB);

    JsonUtils::ObjectGetMember(input, "Concurrency", this->m_model.concurrency);

    JsonUtils::ObjectGetMember(input, "CreditsPerMinute", this->m_model.creditsPerMinute);

    JsonUtils::ObjectGetMember(input, "EventsPerSecond", this->m_model.eventsPerSecond);

    JsonUtils::ObjectGetMember(input, "Level", this->m_model.level);

    JsonUtils::ObjectGetMember(input, "MaxMemoryPerQueryMB", this->m_model.maxMemoryPerQueryMB);

    JsonUtils::ObjectGetMember(input, "VirtualCpuCores", this->m_model.virtualCpuCores);
}

size_t InsightsPerformanceLevel::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAnalyticsInsightsPerformanceLevel const*> InsightsPerformanceLevel::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<InsightsPerformanceLevel>(&this->Model());
}

size_t InsightsPerformanceLevel::RequiredBufferSize(const PFAnalyticsInsightsPerformanceLevel& model)
{
    UNREFERENCED_PARAMETER(model); // Fixed size
    return sizeof(ModelType);
}

HRESULT InsightsPerformanceLevel::Copy(const PFAnalyticsInsightsPerformanceLevel& input, PFAnalyticsInsightsPerformanceLevel& output, ModelBuffer& buffer)
{
    output = input;
    UNREFERENCED_PARAMETER(buffer); // Fixed size
    return S_OK;
}

void InsightsGetLimitsResponse::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "DefaultPerformanceLevel", this->m_model.defaultPerformanceLevel);

    JsonUtils::ObjectGetMember(input, "DefaultStorageRetentionDays", this->m_model.defaultStorageRetentionDays);

    JsonUtils::ObjectGetMember(input, "StorageMaxRetentionDays", this->m_model.storageMaxRetentionDays);

    JsonUtils::ObjectGetMember(input, "StorageMinRetentionDays", this->m_model.storageMinRetentionDays);

    ModelVector<InsightsPerformanceLevel> subMeters{};
    JsonUtils::ObjectGetMember<InsightsPerformanceLevel>(input, "SubMeters", subMeters);
    this->SetSubMeters(std::move(subMeters));
}

size_t InsightsGetLimitsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAnalyticsInsightsGetLimitsResponse const*> InsightsGetLimitsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<InsightsGetLimitsResponse>(&this->Model());
}

size_t InsightsGetLimitsResponse::RequiredBufferSize(const PFAnalyticsInsightsGetLimitsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAnalyticsInsightsPerformanceLevel*) + sizeof(PFAnalyticsInsightsPerformanceLevel*) * model.subMetersCount);
    for (size_t i = 0; i < model.subMetersCount; ++i)
    {
        requiredSize += InsightsPerformanceLevel::RequiredBufferSize(*model.subMeters[i]);
    }
    return requiredSize;
}

HRESULT InsightsGetLimitsResponse::Copy(const PFAnalyticsInsightsGetLimitsResponse& input, PFAnalyticsInsightsGetLimitsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<InsightsPerformanceLevel>(input.subMeters, input.subMetersCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.subMeters = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void InsightsGetOperationStatusResponse::FromJson(const JsonValue& input)
{
    String message{};
    JsonUtils::ObjectGetMember(input, "Message", message);
    this->SetMessage(std::move(message));

    JsonUtils::ObjectGetMemberTime(input, "OperationCompletedTime", this->m_model.operationCompletedTime);

    String operationId{};
    JsonUtils::ObjectGetMember(input, "OperationId", operationId);
    this->SetOperationId(std::move(operationId));

    JsonUtils::ObjectGetMemberTime(input, "OperationLastUpdated", this->m_model.operationLastUpdated);

    JsonUtils::ObjectGetMemberTime(input, "OperationStartedTime", this->m_model.operationStartedTime);

    String operationType{};
    JsonUtils::ObjectGetMember(input, "OperationType", operationType);
    this->SetOperationType(std::move(operationType));

    JsonUtils::ObjectGetMember(input, "OperationValue", this->m_model.operationValue);

    String status{};
    JsonUtils::ObjectGetMember(input, "Status", status);
    this->SetStatus(std::move(status));
}

size_t InsightsGetOperationStatusResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAnalyticsInsightsGetOperationStatusResponse const*> InsightsGetOperationStatusResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<InsightsGetOperationStatusResponse>(&this->Model());
}

size_t InsightsGetOperationStatusResponse::RequiredBufferSize(const PFAnalyticsInsightsGetOperationStatusResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.message)
    {
        requiredSize += (std::strlen(model.message) + 1);
    }
    if (model.operationId)
    {
        requiredSize += (std::strlen(model.operationId) + 1);
    }
    if (model.operationType)
    {
        requiredSize += (std::strlen(model.operationType) + 1);
    }
    if (model.status)
    {
        requiredSize += (std::strlen(model.status) + 1);
    }
    return requiredSize;
}

HRESULT InsightsGetOperationStatusResponse::Copy(const PFAnalyticsInsightsGetOperationStatusResponse& input, PFAnalyticsInsightsGetOperationStatusResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.message); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.message = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.operationId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.operationId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.operationType); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.operationType = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.status); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.status = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void InsightsGetDetailsResponse::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "DataUsageMb", this->m_model.dataUsageMb);

    String errorMessage{};
    JsonUtils::ObjectGetMember(input, "ErrorMessage", errorMessage);
    this->SetErrorMessage(std::move(errorMessage));

    StdExtra::optional<InsightsGetLimitsResponse> limits{};
    JsonUtils::ObjectGetMember(input, "Limits", limits);
    if (limits)
    {
        this->SetLimits(std::move(*limits));
    }

    ModelVector<InsightsGetOperationStatusResponse> pendingOperations{};
    JsonUtils::ObjectGetMember<InsightsGetOperationStatusResponse>(input, "PendingOperations", pendingOperations);
    this->SetPendingOperations(std::move(pendingOperations));

    JsonUtils::ObjectGetMember(input, "PerformanceLevel", this->m_model.performanceLevel);

    JsonUtils::ObjectGetMember(input, "RetentionDays", this->m_model.retentionDays);
}

size_t InsightsGetDetailsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAnalyticsInsightsGetDetailsResponse const*> InsightsGetDetailsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<InsightsGetDetailsResponse>(&this->Model());
}

size_t InsightsGetDetailsResponse::RequiredBufferSize(const PFAnalyticsInsightsGetDetailsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.errorMessage)
    {
        requiredSize += (std::strlen(model.errorMessage) + 1);
    }
    if (model.limits)
    {
        requiredSize += InsightsGetLimitsResponse::RequiredBufferSize(*model.limits);
    }
    requiredSize += (alignof(PFAnalyticsInsightsGetOperationStatusResponse*) + sizeof(PFAnalyticsInsightsGetOperationStatusResponse*) * model.pendingOperationsCount);
    for (size_t i = 0; i < model.pendingOperationsCount; ++i)
    {
        requiredSize += InsightsGetOperationStatusResponse::RequiredBufferSize(*model.pendingOperations[i]);
    }
    return requiredSize;
}

HRESULT InsightsGetDetailsResponse::Copy(const PFAnalyticsInsightsGetDetailsResponse& input, PFAnalyticsInsightsGetDetailsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.errorMessage); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.errorMessage = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<InsightsGetLimitsResponse>(input.limits); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.limits = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<InsightsGetOperationStatusResponse>(input.pendingOperations, input.pendingOperationsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.pendingOperations = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue InsightsGetOperationStatusRequest::ToJson() const
{
    return InsightsGetOperationStatusRequest::ToJson(this->Model());
}

JsonValue InsightsGetOperationStatusRequest::ToJson(const PFAnalyticsInsightsGetOperationStatusRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "OperationId", input.operationId);
    return output;
}

JsonValue InsightsGetPendingOperationsRequest::ToJson() const
{
    return InsightsGetPendingOperationsRequest::ToJson(this->Model());
}

JsonValue InsightsGetPendingOperationsRequest::ToJson(const PFAnalyticsInsightsGetPendingOperationsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "OperationType", input.operationType);
    return output;
}

void InsightsGetPendingOperationsResponse::FromJson(const JsonValue& input)
{
    ModelVector<InsightsGetOperationStatusResponse> pendingOperations{};
    JsonUtils::ObjectGetMember<InsightsGetOperationStatusResponse>(input, "PendingOperations", pendingOperations);
    this->SetPendingOperations(std::move(pendingOperations));
}

size_t InsightsGetPendingOperationsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAnalyticsInsightsGetPendingOperationsResponse const*> InsightsGetPendingOperationsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<InsightsGetPendingOperationsResponse>(&this->Model());
}

size_t InsightsGetPendingOperationsResponse::RequiredBufferSize(const PFAnalyticsInsightsGetPendingOperationsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAnalyticsInsightsGetOperationStatusResponse*) + sizeof(PFAnalyticsInsightsGetOperationStatusResponse*) * model.pendingOperationsCount);
    for (size_t i = 0; i < model.pendingOperationsCount; ++i)
    {
        requiredSize += InsightsGetOperationStatusResponse::RequiredBufferSize(*model.pendingOperations[i]);
    }
    return requiredSize;
}

HRESULT InsightsGetPendingOperationsResponse::Copy(const PFAnalyticsInsightsGetPendingOperationsResponse& input, PFAnalyticsInsightsGetPendingOperationsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<InsightsGetOperationStatusResponse>(input.pendingOperations, input.pendingOperationsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.pendingOperations = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue InsightsSetPerformanceRequest::ToJson() const
{
    return InsightsSetPerformanceRequest::ToJson(this->Model());
}

JsonValue InsightsSetPerformanceRequest::ToJson(const PFAnalyticsInsightsSetPerformanceRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PerformanceLevel", input.performanceLevel);
    return output;
}

void InsightsOperationResponse::FromJson(const JsonValue& input)
{
    String message{};
    JsonUtils::ObjectGetMember(input, "Message", message);
    this->SetMessage(std::move(message));

    String operationId{};
    JsonUtils::ObjectGetMember(input, "OperationId", operationId);
    this->SetOperationId(std::move(operationId));

    String operationType{};
    JsonUtils::ObjectGetMember(input, "OperationType", operationType);
    this->SetOperationType(std::move(operationType));
}

size_t InsightsOperationResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAnalyticsInsightsOperationResponse const*> InsightsOperationResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<InsightsOperationResponse>(&this->Model());
}

size_t InsightsOperationResponse::RequiredBufferSize(const PFAnalyticsInsightsOperationResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.message)
    {
        requiredSize += (std::strlen(model.message) + 1);
    }
    if (model.operationId)
    {
        requiredSize += (std::strlen(model.operationId) + 1);
    }
    if (model.operationType)
    {
        requiredSize += (std::strlen(model.operationType) + 1);
    }
    return requiredSize;
}

HRESULT InsightsOperationResponse::Copy(const PFAnalyticsInsightsOperationResponse& input, PFAnalyticsInsightsOperationResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.message); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.message = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.operationId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.operationId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.operationType); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.operationType = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue InsightsSetStorageRetentionRequest::ToJson() const
{
    return InsightsSetStorageRetentionRequest::ToJson(this->Model());
}

JsonValue InsightsSetStorageRetentionRequest::ToJson(const PFAnalyticsInsightsSetStorageRetentionRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "RetentionDays", input.retentionDays);
    return output;
}

} // namespace Analytics
} // namespace PlayFab
