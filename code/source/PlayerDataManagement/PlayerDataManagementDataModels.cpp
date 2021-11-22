#include "stdafx.h"
#include "PlayerDataManagementDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace PlayerDataManagement
{

JsonValue CreatePlayerStatisticDefinitionRequest::ToJson() const
{
    return CreatePlayerStatisticDefinitionRequest::ToJson(this->Model());
}

JsonValue CreatePlayerStatisticDefinitionRequest::ToJson(const PFPlayerDataManagementCreatePlayerStatisticDefinitionRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AggregationMethod", input.aggregationMethod);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    JsonUtils::ObjectAddMember(output, "VersionChangeInterval", input.versionChangeInterval);
    return output;
}

void PlayerStatisticDefinition::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFPlayerDataManagementStatisticAggregationMethod> aggregationMethod{};
    JsonUtils::ObjectGetMember(input, "AggregationMethod", aggregationMethod);
    this->SetAggregationMethod(std::move(aggregationMethod));

    JsonUtils::ObjectGetMember(input, "CurrentVersion", this->m_model.currentVersion);

    String statisticName{};
    JsonUtils::ObjectGetMember(input, "StatisticName", statisticName);
    this->SetStatisticName(std::move(statisticName));

    StdExtra::optional<PFPlayerDataManagementStatisticResetIntervalOption> versionChangeInterval{};
    JsonUtils::ObjectGetMember(input, "VersionChangeInterval", versionChangeInterval);
    this->SetVersionChangeInterval(std::move(versionChangeInterval));
}

size_t PlayerStatisticDefinition::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementPlayerStatisticDefinition const*> PlayerStatisticDefinition::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PlayerStatisticDefinition>(&this->Model());
}

size_t PlayerStatisticDefinition::RequiredBufferSize(const PFPlayerDataManagementPlayerStatisticDefinition& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.aggregationMethod)
    {
        requiredSize += (alignof(PFPlayerDataManagementStatisticAggregationMethod) + sizeof(PFPlayerDataManagementStatisticAggregationMethod));
    }
    if (model.statisticName)
    {
        requiredSize += (std::strlen(model.statisticName) + 1);
    }
    if (model.versionChangeInterval)
    {
        requiredSize += (alignof(PFPlayerDataManagementStatisticResetIntervalOption) + sizeof(PFPlayerDataManagementStatisticResetIntervalOption));
    }
    return requiredSize;
}

HRESULT PlayerStatisticDefinition::Copy(const PFPlayerDataManagementPlayerStatisticDefinition& input, PFPlayerDataManagementPlayerStatisticDefinition& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.aggregationMethod); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.aggregationMethod = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.statisticName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statisticName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.versionChangeInterval); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.versionChangeInterval = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void CreatePlayerStatisticDefinitionResult::FromJson(const JsonValue& input)
{
    StdExtra::optional<PlayerStatisticDefinition> statistic{};
    JsonUtils::ObjectGetMember(input, "Statistic", statistic);
    if (statistic)
    {
        this->SetStatistic(std::move(*statistic));
    }
}

size_t CreatePlayerStatisticDefinitionResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementCreatePlayerStatisticDefinitionResult const*> CreatePlayerStatisticDefinitionResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreatePlayerStatisticDefinitionResult>(&this->Model());
}

size_t CreatePlayerStatisticDefinitionResult::RequiredBufferSize(const PFPlayerDataManagementCreatePlayerStatisticDefinitionResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.statistic)
    {
        requiredSize += PlayerStatisticDefinition::RequiredBufferSize(*model.statistic);
    }
    return requiredSize;
}

HRESULT CreatePlayerStatisticDefinitionResult::Copy(const PFPlayerDataManagementCreatePlayerStatisticDefinitionResult& input, PFPlayerDataManagementCreatePlayerStatisticDefinitionResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<PlayerStatisticDefinition>(input.statistic); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statistic = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetDataReportRequest::ToJson() const
{
    return GetDataReportRequest::ToJson(this->Model());
}

JsonValue GetDataReportRequest::ToJson(const PFPlayerDataManagementGetDataReportRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Day", input.day);
    JsonUtils::ObjectAddMember(output, "Month", input.month);
    JsonUtils::ObjectAddMember(output, "ReportName", input.reportName);
    JsonUtils::ObjectAddMember(output, "Year", input.year);
    return output;
}

void GetDataReportResult::FromJson(const JsonValue& input)
{
    String downloadUrl{};
    JsonUtils::ObjectGetMember(input, "DownloadUrl", downloadUrl);
    this->SetDownloadUrl(std::move(downloadUrl));
}

size_t GetDataReportResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementGetDataReportResult const*> GetDataReportResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetDataReportResult>(&this->Model());
}

size_t GetDataReportResult::RequiredBufferSize(const PFPlayerDataManagementGetDataReportResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.downloadUrl)
    {
        requiredSize += (std::strlen(model.downloadUrl) + 1);
    }
    return requiredSize;
}

HRESULT GetDataReportResult::Copy(const PFPlayerDataManagementGetDataReportResult& input, PFPlayerDataManagementGetDataReportResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.downloadUrl); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.downloadUrl = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPlayerStatisticDefinitionsResult::FromJson(const JsonValue& input)
{
    ModelVector<PlayerStatisticDefinition> statistics{};
    JsonUtils::ObjectGetMember<PlayerStatisticDefinition>(input, "Statistics", statistics);
    this->SetStatistics(std::move(statistics));
}

size_t GetPlayerStatisticDefinitionsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementGetPlayerStatisticDefinitionsResult const*> GetPlayerStatisticDefinitionsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayerStatisticDefinitionsResult>(&this->Model());
}

size_t GetPlayerStatisticDefinitionsResult::RequiredBufferSize(const PFPlayerDataManagementGetPlayerStatisticDefinitionsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlayerDataManagementPlayerStatisticDefinition*) + sizeof(PFPlayerDataManagementPlayerStatisticDefinition*) * model.statisticsCount);
    for (size_t i = 0; i < model.statisticsCount; ++i)
    {
        requiredSize += PlayerStatisticDefinition::RequiredBufferSize(*model.statistics[i]);
    }
    return requiredSize;
}

HRESULT GetPlayerStatisticDefinitionsResult::Copy(const PFPlayerDataManagementGetPlayerStatisticDefinitionsResult& input, PFPlayerDataManagementGetPlayerStatisticDefinitionsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<PlayerStatisticDefinition>(input.statistics, input.statisticsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statistics = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayerStatisticVersionsRequest::ToJson() const
{
    return GetPlayerStatisticVersionsRequest::ToJson(this->Model());
}

JsonValue GetPlayerStatisticVersionsRequest::ToJson(const PFPlayerDataManagementGetPlayerStatisticVersionsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    return output;
}

void PlayerStatisticVersion::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMemberTime(input, "ActivationTime", this->m_model.activationTime);

    String archiveDownloadUrl{};
    JsonUtils::ObjectGetMember(input, "ArchiveDownloadUrl", archiveDownloadUrl);
    this->SetArchiveDownloadUrl(std::move(archiveDownloadUrl));

    StdExtra::optional<time_t> deactivationTime{};
    JsonUtils::ObjectGetMemberTime(input, "DeactivationTime", deactivationTime);
    this->SetDeactivationTime(std::move(deactivationTime));

    StdExtra::optional<time_t> scheduledActivationTime{};
    JsonUtils::ObjectGetMemberTime(input, "ScheduledActivationTime", scheduledActivationTime);
    this->SetScheduledActivationTime(std::move(scheduledActivationTime));

    StdExtra::optional<time_t> scheduledDeactivationTime{};
    JsonUtils::ObjectGetMemberTime(input, "ScheduledDeactivationTime", scheduledDeactivationTime);
    this->SetScheduledDeactivationTime(std::move(scheduledDeactivationTime));

    String statisticName{};
    JsonUtils::ObjectGetMember(input, "StatisticName", statisticName);
    this->SetStatisticName(std::move(statisticName));

    StdExtra::optional<PFPlayerDataManagementStatisticVersionStatus> status{};
    JsonUtils::ObjectGetMember(input, "Status", status);
    this->SetStatus(std::move(status));

    JsonUtils::ObjectGetMember(input, "Version", this->m_model.version);
}

size_t PlayerStatisticVersion::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementPlayerStatisticVersion const*> PlayerStatisticVersion::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PlayerStatisticVersion>(&this->Model());
}

size_t PlayerStatisticVersion::RequiredBufferSize(const PFPlayerDataManagementPlayerStatisticVersion& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.archiveDownloadUrl)
    {
        requiredSize += (std::strlen(model.archiveDownloadUrl) + 1);
    }
    if (model.deactivationTime)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.scheduledActivationTime)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.scheduledDeactivationTime)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.statisticName)
    {
        requiredSize += (std::strlen(model.statisticName) + 1);
    }
    if (model.status)
    {
        requiredSize += (alignof(PFPlayerDataManagementStatisticVersionStatus) + sizeof(PFPlayerDataManagementStatisticVersionStatus));
    }
    return requiredSize;
}

HRESULT PlayerStatisticVersion::Copy(const PFPlayerDataManagementPlayerStatisticVersion& input, PFPlayerDataManagementPlayerStatisticVersion& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.archiveDownloadUrl); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.archiveDownloadUrl = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.deactivationTime); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.deactivationTime = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.scheduledActivationTime); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.scheduledActivationTime = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.scheduledDeactivationTime); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.scheduledDeactivationTime = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.statisticName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statisticName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.status); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.status = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPlayerStatisticVersionsResult::FromJson(const JsonValue& input)
{
    ModelVector<PlayerStatisticVersion> statisticVersions{};
    JsonUtils::ObjectGetMember<PlayerStatisticVersion>(input, "StatisticVersions", statisticVersions);
    this->SetStatisticVersions(std::move(statisticVersions));
}

size_t GetPlayerStatisticVersionsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementGetPlayerStatisticVersionsResult const*> GetPlayerStatisticVersionsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayerStatisticVersionsResult>(&this->Model());
}

size_t GetPlayerStatisticVersionsResult::RequiredBufferSize(const PFPlayerDataManagementGetPlayerStatisticVersionsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlayerDataManagementPlayerStatisticVersion*) + sizeof(PFPlayerDataManagementPlayerStatisticVersion*) * model.statisticVersionsCount);
    for (size_t i = 0; i < model.statisticVersionsCount; ++i)
    {
        requiredSize += PlayerStatisticVersion::RequiredBufferSize(*model.statisticVersions[i]);
    }
    return requiredSize;
}

HRESULT GetPlayerStatisticVersionsResult::Copy(const PFPlayerDataManagementGetPlayerStatisticVersionsResult& input, PFPlayerDataManagementGetPlayerStatisticVersionsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<PlayerStatisticVersion>(input.statisticVersions, input.statisticVersionsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statisticVersions = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetUserDataRequest::ToJson() const
{
    return GetUserDataRequest::ToJson(this->Model());
}

JsonValue GetUserDataRequest::ToJson(const PFPlayerDataManagementGetUserDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "IfChangedFromDataVersion", input.ifChangedFromDataVersion);
    JsonUtils::ObjectAddMemberArray(output, "Keys", input.keys, input.keysCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void AdminGetUserDataResult::FromJson(const JsonValue& input)
{
    ModelDictionaryEntryVector<UserDataRecord> data{};
    JsonUtils::ObjectGetMember<UserDataRecord>(input, "Data", data);
    this->SetData(std::move(data));

    JsonUtils::ObjectGetMember(input, "DataVersion", this->m_model.dataVersion);

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t AdminGetUserDataResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementAdminGetUserDataResult const*> AdminGetUserDataResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AdminGetUserDataResult>(&this->Model());
}

size_t AdminGetUserDataResult::RequiredBufferSize(const PFPlayerDataManagementAdminGetUserDataResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFUserDataRecordDictionaryEntry) + sizeof(PFUserDataRecordDictionaryEntry) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += (std::strlen(model.data[i].key) + 1);
        requiredSize += UserDataRecord::RequiredBufferSize(*model.data[i].value);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT AdminGetUserDataResult::Copy(const PFPlayerDataManagementAdminGetUserDataResult& input, PFPlayerDataManagementAdminGetUserDataResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToDictionary<UserDataRecord>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue IncrementPlayerStatisticVersionRequest::ToJson() const
{
    return IncrementPlayerStatisticVersionRequest::ToJson(this->Model());
}

JsonValue IncrementPlayerStatisticVersionRequest::ToJson(const PFPlayerDataManagementIncrementPlayerStatisticVersionRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    return output;
}

void IncrementPlayerStatisticVersionResult::FromJson(const JsonValue& input)
{
    StdExtra::optional<PlayerStatisticVersion> statisticVersion{};
    JsonUtils::ObjectGetMember(input, "StatisticVersion", statisticVersion);
    if (statisticVersion)
    {
        this->SetStatisticVersion(std::move(*statisticVersion));
    }
}

size_t IncrementPlayerStatisticVersionResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementIncrementPlayerStatisticVersionResult const*> IncrementPlayerStatisticVersionResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<IncrementPlayerStatisticVersionResult>(&this->Model());
}

size_t IncrementPlayerStatisticVersionResult::RequiredBufferSize(const PFPlayerDataManagementIncrementPlayerStatisticVersionResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.statisticVersion)
    {
        requiredSize += PlayerStatisticVersion::RequiredBufferSize(*model.statisticVersion);
    }
    return requiredSize;
}

HRESULT IncrementPlayerStatisticVersionResult::Copy(const PFPlayerDataManagementIncrementPlayerStatisticVersionResult& input, PFPlayerDataManagementIncrementPlayerStatisticVersionResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<PlayerStatisticVersion>(input.statisticVersion); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statisticVersion = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RefundPurchaseRequest::ToJson() const
{
    return RefundPurchaseRequest::ToJson(this->Model());
}

JsonValue RefundPurchaseRequest::ToJson(const PFPlayerDataManagementRefundPurchaseRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "OrderId", input.orderId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "Reason", input.reason);
    return output;
}

void RefundPurchaseResponse::FromJson(const JsonValue& input)
{
    String purchaseStatus{};
    JsonUtils::ObjectGetMember(input, "PurchaseStatus", purchaseStatus);
    this->SetPurchaseStatus(std::move(purchaseStatus));
}

size_t RefundPurchaseResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementRefundPurchaseResponse const*> RefundPurchaseResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RefundPurchaseResponse>(&this->Model());
}

size_t RefundPurchaseResponse::RequiredBufferSize(const PFPlayerDataManagementRefundPurchaseResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.purchaseStatus)
    {
        requiredSize += (std::strlen(model.purchaseStatus) + 1);
    }
    return requiredSize;
}

HRESULT RefundPurchaseResponse::Copy(const PFPlayerDataManagementRefundPurchaseResponse& input, PFPlayerDataManagementRefundPurchaseResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.purchaseStatus); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.purchaseStatus = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ResetUserStatisticsRequest::ToJson() const
{
    return ResetUserStatisticsRequest::ToJson(this->Model());
}

JsonValue ResetUserStatisticsRequest::ToJson(const PFPlayerDataManagementResetUserStatisticsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue ResolvePurchaseDisputeRequest::ToJson() const
{
    return ResolvePurchaseDisputeRequest::ToJson(this->Model());
}

JsonValue ResolvePurchaseDisputeRequest::ToJson(const PFPlayerDataManagementResolvePurchaseDisputeRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "OrderId", input.orderId);
    JsonUtils::ObjectAddMember(output, "Outcome", input.outcome);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "Reason", input.reason);
    return output;
}

void ResolvePurchaseDisputeResponse::FromJson(const JsonValue& input)
{
    String purchaseStatus{};
    JsonUtils::ObjectGetMember(input, "PurchaseStatus", purchaseStatus);
    this->SetPurchaseStatus(std::move(purchaseStatus));
}

size_t ResolvePurchaseDisputeResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementResolvePurchaseDisputeResponse const*> ResolvePurchaseDisputeResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ResolvePurchaseDisputeResponse>(&this->Model());
}

size_t ResolvePurchaseDisputeResponse::RequiredBufferSize(const PFPlayerDataManagementResolvePurchaseDisputeResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.purchaseStatus)
    {
        requiredSize += (std::strlen(model.purchaseStatus) + 1);
    }
    return requiredSize;
}

HRESULT ResolvePurchaseDisputeResponse::Copy(const PFPlayerDataManagementResolvePurchaseDisputeResponse& input, PFPlayerDataManagementResolvePurchaseDisputeResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.purchaseStatus); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.purchaseStatus = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue UpdatePlayerStatisticDefinitionRequest::ToJson() const
{
    return UpdatePlayerStatisticDefinitionRequest::ToJson(this->Model());
}

JsonValue UpdatePlayerStatisticDefinitionRequest::ToJson(const PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AggregationMethod", input.aggregationMethod);
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    JsonUtils::ObjectAddMember(output, "VersionChangeInterval", input.versionChangeInterval);
    return output;
}

void UpdatePlayerStatisticDefinitionResult::FromJson(const JsonValue& input)
{
    StdExtra::optional<PlayerStatisticDefinition> statistic{};
    JsonUtils::ObjectGetMember(input, "Statistic", statistic);
    if (statistic)
    {
        this->SetStatistic(std::move(*statistic));
    }
}

size_t UpdatePlayerStatisticDefinitionResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult const*> UpdatePlayerStatisticDefinitionResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<UpdatePlayerStatisticDefinitionResult>(&this->Model());
}

size_t UpdatePlayerStatisticDefinitionResult::RequiredBufferSize(const PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.statistic)
    {
        requiredSize += PlayerStatisticDefinition::RequiredBufferSize(*model.statistic);
    }
    return requiredSize;
}

HRESULT UpdatePlayerStatisticDefinitionResult::Copy(const PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult& input, PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<PlayerStatisticDefinition>(input.statistic); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statistic = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue AdminUpdateUserDataRequest::ToJson() const
{
    return AdminUpdateUserDataRequest::ToJson(this->Model());
}

JsonValue AdminUpdateUserDataRequest::ToJson(const PFPlayerDataManagementAdminUpdateUserDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "Data", input.data, input.dataCount);
    JsonUtils::ObjectAddMemberArray(output, "KeysToRemove", input.keysToRemove, input.keysToRemoveCount);
    JsonUtils::ObjectAddMember(output, "Permission", input.permission);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void UpdateUserDataResult::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "DataVersion", this->m_model.dataVersion);
}

size_t UpdateUserDataResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementUpdateUserDataResult const*> UpdateUserDataResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<UpdateUserDataResult>(&this->Model());
}

size_t UpdateUserDataResult::RequiredBufferSize(const PFPlayerDataManagementUpdateUserDataResult& model)
{
    UNREFERENCED_PARAMETER(model); // Fixed size
    return sizeof(ModelType);
}

HRESULT UpdateUserDataResult::Copy(const PFPlayerDataManagementUpdateUserDataResult& input, PFPlayerDataManagementUpdateUserDataResult& output, ModelBuffer& buffer)
{
    output = input;
    UNREFERENCED_PARAMETER(buffer); // Fixed size
    return S_OK;
}

JsonValue UpdateUserInternalDataRequest::ToJson() const
{
    return UpdateUserInternalDataRequest::ToJson(this->Model());
}

JsonValue UpdateUserInternalDataRequest::ToJson(const PFPlayerDataManagementUpdateUserInternalDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "Data", input.data, input.dataCount);
    JsonUtils::ObjectAddMemberArray(output, "KeysToRemove", input.keysToRemove, input.keysToRemoveCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue ClientGetFriendLeaderboardRequest::ToJson() const
{
    return ClientGetFriendLeaderboardRequest::ToJson(this->Model());
}

JsonValue ClientGetFriendLeaderboardRequest::ToJson(const PFPlayerDataManagementClientGetFriendLeaderboardRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "IncludeFacebookFriends", input.includeFacebookFriends);
    JsonUtils::ObjectAddMember(output, "IncludeSteamFriends", input.includeSteamFriends);
    JsonUtils::ObjectAddMember(output, "MaxResultsCount", input.maxResultsCount);
    JsonUtils::ObjectAddMember<PlayerProfileViewConstraints>(output, "ProfileConstraints", input.profileConstraints);
    JsonUtils::ObjectAddMember(output, "StartPosition", input.startPosition);
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    JsonUtils::ObjectAddMember(output, "Version", input.version);
    JsonUtils::ObjectAddMember(output, "XboxToken", input.xboxToken);
    return output;
}

void PlayerLeaderboardEntry::FromJson(const JsonValue& input)
{
    String displayName{};
    JsonUtils::ObjectGetMember(input, "DisplayName", displayName);
    this->SetDisplayName(std::move(displayName));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    JsonUtils::ObjectGetMember(input, "Position", this->m_model.position);

    StdExtra::optional<PlayerProfileModel> profile{};
    JsonUtils::ObjectGetMember(input, "Profile", profile);
    if (profile)
    {
        this->SetProfile(std::move(*profile));
    }

    JsonUtils::ObjectGetMember(input, "StatValue", this->m_model.statValue);
}

size_t PlayerLeaderboardEntry::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementPlayerLeaderboardEntry const*> PlayerLeaderboardEntry::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PlayerLeaderboardEntry>(&this->Model());
}

size_t PlayerLeaderboardEntry::RequiredBufferSize(const PFPlayerDataManagementPlayerLeaderboardEntry& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.displayName)
    {
        requiredSize += (std::strlen(model.displayName) + 1);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    if (model.profile)
    {
        requiredSize += PlayerProfileModel::RequiredBufferSize(*model.profile);
    }
    return requiredSize;
}

HRESULT PlayerLeaderboardEntry::Copy(const PFPlayerDataManagementPlayerLeaderboardEntry& input, PFPlayerDataManagementPlayerLeaderboardEntry& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.displayName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.displayName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<PlayerProfileModel>(input.profile); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.profile = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetLeaderboardResult::FromJson(const JsonValue& input)
{
    ModelVector<PlayerLeaderboardEntry> leaderboard{};
    JsonUtils::ObjectGetMember<PlayerLeaderboardEntry>(input, "Leaderboard", leaderboard);
    this->SetLeaderboard(std::move(leaderboard));

    StdExtra::optional<time_t> nextReset{};
    JsonUtils::ObjectGetMemberTime(input, "NextReset", nextReset);
    this->SetNextReset(std::move(nextReset));

    JsonUtils::ObjectGetMember(input, "Version", this->m_model.version);
}

size_t GetLeaderboardResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementGetLeaderboardResult const*> GetLeaderboardResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetLeaderboardResult>(&this->Model());
}

size_t GetLeaderboardResult::RequiredBufferSize(const PFPlayerDataManagementGetLeaderboardResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlayerDataManagementPlayerLeaderboardEntry*) + sizeof(PFPlayerDataManagementPlayerLeaderboardEntry*) * model.leaderboardCount);
    for (size_t i = 0; i < model.leaderboardCount; ++i)
    {
        requiredSize += PlayerLeaderboardEntry::RequiredBufferSize(*model.leaderboard[i]);
    }
    if (model.nextReset)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    return requiredSize;
}

HRESULT GetLeaderboardResult::Copy(const PFPlayerDataManagementGetLeaderboardResult& input, PFPlayerDataManagementGetLeaderboardResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<PlayerLeaderboardEntry>(input.leaderboard, input.leaderboardCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.leaderboard = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.nextReset); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.nextReset = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetFriendLeaderboardAroundPlayerRequest::ToJson() const
{
    return GetFriendLeaderboardAroundPlayerRequest::ToJson(this->Model());
}

JsonValue GetFriendLeaderboardAroundPlayerRequest::ToJson(const PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "IncludeFacebookFriends", input.includeFacebookFriends);
    JsonUtils::ObjectAddMember(output, "IncludeSteamFriends", input.includeSteamFriends);
    JsonUtils::ObjectAddMember(output, "MaxResultsCount", input.maxResultsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember<PlayerProfileViewConstraints>(output, "ProfileConstraints", input.profileConstraints);
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    JsonUtils::ObjectAddMember(output, "Version", input.version);
    JsonUtils::ObjectAddMember(output, "XboxToken", input.xboxToken);
    return output;
}

void GetFriendLeaderboardAroundPlayerResult::FromJson(const JsonValue& input)
{
    ModelVector<PlayerLeaderboardEntry> leaderboard{};
    JsonUtils::ObjectGetMember<PlayerLeaderboardEntry>(input, "Leaderboard", leaderboard);
    this->SetLeaderboard(std::move(leaderboard));

    StdExtra::optional<time_t> nextReset{};
    JsonUtils::ObjectGetMemberTime(input, "NextReset", nextReset);
    this->SetNextReset(std::move(nextReset));

    JsonUtils::ObjectGetMember(input, "Version", this->m_model.version);
}

size_t GetFriendLeaderboardAroundPlayerResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult const*> GetFriendLeaderboardAroundPlayerResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetFriendLeaderboardAroundPlayerResult>(&this->Model());
}

size_t GetFriendLeaderboardAroundPlayerResult::RequiredBufferSize(const PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlayerDataManagementPlayerLeaderboardEntry*) + sizeof(PFPlayerDataManagementPlayerLeaderboardEntry*) * model.leaderboardCount);
    for (size_t i = 0; i < model.leaderboardCount; ++i)
    {
        requiredSize += PlayerLeaderboardEntry::RequiredBufferSize(*model.leaderboard[i]);
    }
    if (model.nextReset)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    return requiredSize;
}

HRESULT GetFriendLeaderboardAroundPlayerResult::Copy(const PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult& input, PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<PlayerLeaderboardEntry>(input.leaderboard, input.leaderboardCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.leaderboard = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.nextReset); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.nextReset = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetLeaderboardRequest::ToJson() const
{
    return GetLeaderboardRequest::ToJson(this->Model());
}

JsonValue GetLeaderboardRequest::ToJson(const PFPlayerDataManagementGetLeaderboardRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "MaxResultsCount", input.maxResultsCount);
    JsonUtils::ObjectAddMember<PlayerProfileViewConstraints>(output, "ProfileConstraints", input.profileConstraints);
    JsonUtils::ObjectAddMember(output, "StartPosition", input.startPosition);
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    JsonUtils::ObjectAddMember(output, "Version", input.version);
    return output;
}

JsonValue GetLeaderboardAroundPlayerRequest::ToJson() const
{
    return GetLeaderboardAroundPlayerRequest::ToJson(this->Model());
}

JsonValue GetLeaderboardAroundPlayerRequest::ToJson(const PFPlayerDataManagementGetLeaderboardAroundPlayerRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "MaxResultsCount", input.maxResultsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember<PlayerProfileViewConstraints>(output, "ProfileConstraints", input.profileConstraints);
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    JsonUtils::ObjectAddMember(output, "Version", input.version);
    return output;
}

void GetLeaderboardAroundPlayerResult::FromJson(const JsonValue& input)
{
    ModelVector<PlayerLeaderboardEntry> leaderboard{};
    JsonUtils::ObjectGetMember<PlayerLeaderboardEntry>(input, "Leaderboard", leaderboard);
    this->SetLeaderboard(std::move(leaderboard));

    StdExtra::optional<time_t> nextReset{};
    JsonUtils::ObjectGetMemberTime(input, "NextReset", nextReset);
    this->SetNextReset(std::move(nextReset));

    JsonUtils::ObjectGetMember(input, "Version", this->m_model.version);
}

size_t GetLeaderboardAroundPlayerResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementGetLeaderboardAroundPlayerResult const*> GetLeaderboardAroundPlayerResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetLeaderboardAroundPlayerResult>(&this->Model());
}

size_t GetLeaderboardAroundPlayerResult::RequiredBufferSize(const PFPlayerDataManagementGetLeaderboardAroundPlayerResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlayerDataManagementPlayerLeaderboardEntry*) + sizeof(PFPlayerDataManagementPlayerLeaderboardEntry*) * model.leaderboardCount);
    for (size_t i = 0; i < model.leaderboardCount; ++i)
    {
        requiredSize += PlayerLeaderboardEntry::RequiredBufferSize(*model.leaderboard[i]);
    }
    if (model.nextReset)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    return requiredSize;
}

HRESULT GetLeaderboardAroundPlayerResult::Copy(const PFPlayerDataManagementGetLeaderboardAroundPlayerResult& input, PFPlayerDataManagementGetLeaderboardAroundPlayerResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<PlayerLeaderboardEntry>(input.leaderboard, input.leaderboardCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.leaderboard = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.nextReset); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.nextReset = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue StatisticNameVersion::ToJson() const
{
    return StatisticNameVersion::ToJson(this->Model());
}

JsonValue StatisticNameVersion::ToJson(const PFPlayerDataManagementStatisticNameVersion& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    JsonUtils::ObjectAddMember(output, "Version", input.version);
    return output;
}

JsonValue ClientGetPlayerStatisticsRequest::ToJson() const
{
    return ClientGetPlayerStatisticsRequest::ToJson(this->Model());
}

JsonValue ClientGetPlayerStatisticsRequest::ToJson(const PFPlayerDataManagementClientGetPlayerStatisticsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray(output, "StatisticNames", input.statisticNames, input.statisticNamesCount);
    JsonUtils::ObjectAddMemberArray<StatisticNameVersion>(output, "StatisticNameVersions", input.statisticNameVersions, input.statisticNameVersionsCount);
    return output;
}

void ClientGetPlayerStatisticsResult::FromJson(const JsonValue& input)
{
    ModelVector<StatisticValue> statistics{};
    JsonUtils::ObjectGetMember<StatisticValue>(input, "Statistics", statistics);
    this->SetStatistics(std::move(statistics));
}

size_t ClientGetPlayerStatisticsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementClientGetPlayerStatisticsResult const*> ClientGetPlayerStatisticsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ClientGetPlayerStatisticsResult>(&this->Model());
}

size_t ClientGetPlayerStatisticsResult::RequiredBufferSize(const PFPlayerDataManagementClientGetPlayerStatisticsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFStatisticValue*) + sizeof(PFStatisticValue*) * model.statisticsCount);
    for (size_t i = 0; i < model.statisticsCount; ++i)
    {
        requiredSize += StatisticValue::RequiredBufferSize(*model.statistics[i]);
    }
    return requiredSize;
}

HRESULT ClientGetPlayerStatisticsResult::Copy(const PFPlayerDataManagementClientGetPlayerStatisticsResult& input, PFPlayerDataManagementClientGetPlayerStatisticsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<StatisticValue>(input.statistics, input.statisticsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statistics = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void ClientGetUserDataResult::FromJson(const JsonValue& input)
{
    ModelDictionaryEntryVector<UserDataRecord> data{};
    JsonUtils::ObjectGetMember<UserDataRecord>(input, "Data", data);
    this->SetData(std::move(data));

    JsonUtils::ObjectGetMember(input, "DataVersion", this->m_model.dataVersion);
}

size_t ClientGetUserDataResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementClientGetUserDataResult const*> ClientGetUserDataResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ClientGetUserDataResult>(&this->Model());
}

size_t ClientGetUserDataResult::RequiredBufferSize(const PFPlayerDataManagementClientGetUserDataResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFUserDataRecordDictionaryEntry) + sizeof(PFUserDataRecordDictionaryEntry) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += (std::strlen(model.data[i].key) + 1);
        requiredSize += UserDataRecord::RequiredBufferSize(*model.data[i].value);
    }
    return requiredSize;
}

HRESULT ClientGetUserDataResult::Copy(const PFPlayerDataManagementClientGetUserDataResult& input, PFPlayerDataManagementClientGetUserDataResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToDictionary<UserDataRecord>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue StatisticUpdate::ToJson() const
{
    return StatisticUpdate::ToJson(this->Model());
}

JsonValue StatisticUpdate::ToJson(const PFPlayerDataManagementStatisticUpdate& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    JsonUtils::ObjectAddMember(output, "Value", input.value);
    JsonUtils::ObjectAddMember(output, "Version", input.version);
    return output;
}

JsonValue ClientUpdatePlayerStatisticsRequest::ToJson() const
{
    return ClientUpdatePlayerStatisticsRequest::ToJson(this->Model());
}

JsonValue ClientUpdatePlayerStatisticsRequest::ToJson(const PFPlayerDataManagementClientUpdatePlayerStatisticsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray<StatisticUpdate>(output, "Statistics", input.statistics, input.statisticsCount);
    return output;
}

JsonValue ClientUpdateUserDataRequest::ToJson() const
{
    return ClientUpdateUserDataRequest::ToJson(this->Model());
}

JsonValue ClientUpdateUserDataRequest::ToJson(const PFPlayerDataManagementClientUpdateUserDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "Data", input.data, input.dataCount);
    JsonUtils::ObjectAddMemberArray(output, "KeysToRemove", input.keysToRemove, input.keysToRemoveCount);
    JsonUtils::ObjectAddMember(output, "Permission", input.permission);
    return output;
}

JsonValue ServerGetFriendLeaderboardRequest::ToJson() const
{
    return ServerGetFriendLeaderboardRequest::ToJson(this->Model());
}

JsonValue ServerGetFriendLeaderboardRequest::ToJson(const PFPlayerDataManagementServerGetFriendLeaderboardRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "IncludeFacebookFriends", input.includeFacebookFriends);
    JsonUtils::ObjectAddMember(output, "IncludeSteamFriends", input.includeSteamFriends);
    JsonUtils::ObjectAddMember(output, "MaxResultsCount", input.maxResultsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember<PlayerProfileViewConstraints>(output, "ProfileConstraints", input.profileConstraints);
    JsonUtils::ObjectAddMember(output, "StartPosition", input.startPosition);
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    JsonUtils::ObjectAddMember(output, "Version", input.version);
    JsonUtils::ObjectAddMember(output, "XboxToken", input.xboxToken);
    return output;
}

JsonValue GetLeaderboardAroundUserRequest::ToJson() const
{
    return GetLeaderboardAroundUserRequest::ToJson(this->Model());
}

JsonValue GetLeaderboardAroundUserRequest::ToJson(const PFPlayerDataManagementGetLeaderboardAroundUserRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "MaxResultsCount", input.maxResultsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember<PlayerProfileViewConstraints>(output, "ProfileConstraints", input.profileConstraints);
    JsonUtils::ObjectAddMember(output, "StatisticName", input.statisticName);
    JsonUtils::ObjectAddMember(output, "Version", input.version);
    return output;
}

void GetLeaderboardAroundUserResult::FromJson(const JsonValue& input)
{
    ModelVector<PlayerLeaderboardEntry> leaderboard{};
    JsonUtils::ObjectGetMember<PlayerLeaderboardEntry>(input, "Leaderboard", leaderboard);
    this->SetLeaderboard(std::move(leaderboard));

    StdExtra::optional<time_t> nextReset{};
    JsonUtils::ObjectGetMemberTime(input, "NextReset", nextReset);
    this->SetNextReset(std::move(nextReset));

    JsonUtils::ObjectGetMember(input, "Version", this->m_model.version);
}

size_t GetLeaderboardAroundUserResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementGetLeaderboardAroundUserResult const*> GetLeaderboardAroundUserResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetLeaderboardAroundUserResult>(&this->Model());
}

size_t GetLeaderboardAroundUserResult::RequiredBufferSize(const PFPlayerDataManagementGetLeaderboardAroundUserResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlayerDataManagementPlayerLeaderboardEntry*) + sizeof(PFPlayerDataManagementPlayerLeaderboardEntry*) * model.leaderboardCount);
    for (size_t i = 0; i < model.leaderboardCount; ++i)
    {
        requiredSize += PlayerLeaderboardEntry::RequiredBufferSize(*model.leaderboard[i]);
    }
    if (model.nextReset)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    return requiredSize;
}

HRESULT GetLeaderboardAroundUserResult::Copy(const PFPlayerDataManagementGetLeaderboardAroundUserResult& input, PFPlayerDataManagementGetLeaderboardAroundUserResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<PlayerLeaderboardEntry>(input.leaderboard, input.leaderboardCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.leaderboard = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.nextReset); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.nextReset = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ServerGetPlayerStatisticsRequest::ToJson() const
{
    return ServerGetPlayerStatisticsRequest::ToJson(this->Model());
}

JsonValue ServerGetPlayerStatisticsRequest::ToJson(const PFPlayerDataManagementServerGetPlayerStatisticsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMemberArray(output, "StatisticNames", input.statisticNames, input.statisticNamesCount);
    JsonUtils::ObjectAddMemberArray<StatisticNameVersion>(output, "StatisticNameVersions", input.statisticNameVersions, input.statisticNameVersionsCount);
    return output;
}

void ServerGetPlayerStatisticsResult::FromJson(const JsonValue& input)
{
    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    ModelVector<StatisticValue> statistics{};
    JsonUtils::ObjectGetMember<StatisticValue>(input, "Statistics", statistics);
    this->SetStatistics(std::move(statistics));
}

size_t ServerGetPlayerStatisticsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementServerGetPlayerStatisticsResult const*> ServerGetPlayerStatisticsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ServerGetPlayerStatisticsResult>(&this->Model());
}

size_t ServerGetPlayerStatisticsResult::RequiredBufferSize(const PFPlayerDataManagementServerGetPlayerStatisticsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    requiredSize += (alignof(PFStatisticValue*) + sizeof(PFStatisticValue*) * model.statisticsCount);
    for (size_t i = 0; i < model.statisticsCount; ++i)
    {
        requiredSize += StatisticValue::RequiredBufferSize(*model.statistics[i]);
    }
    return requiredSize;
}

HRESULT ServerGetPlayerStatisticsResult::Copy(const PFPlayerDataManagementServerGetPlayerStatisticsResult& input, PFPlayerDataManagementServerGetPlayerStatisticsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<StatisticValue>(input.statistics, input.statisticsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statistics = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void ServerGetUserDataResult::FromJson(const JsonValue& input)
{
    ModelDictionaryEntryVector<UserDataRecord> data{};
    JsonUtils::ObjectGetMember<UserDataRecord>(input, "Data", data);
    this->SetData(std::move(data));

    JsonUtils::ObjectGetMember(input, "DataVersion", this->m_model.dataVersion);

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t ServerGetUserDataResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerDataManagementServerGetUserDataResult const*> ServerGetUserDataResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ServerGetUserDataResult>(&this->Model());
}

size_t ServerGetUserDataResult::RequiredBufferSize(const PFPlayerDataManagementServerGetUserDataResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFUserDataRecordDictionaryEntry) + sizeof(PFUserDataRecordDictionaryEntry) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += (std::strlen(model.data[i].key) + 1);
        requiredSize += UserDataRecord::RequiredBufferSize(*model.data[i].value);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT ServerGetUserDataResult::Copy(const PFPlayerDataManagementServerGetUserDataResult& input, PFPlayerDataManagementServerGetUserDataResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToDictionary<UserDataRecord>(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ServerUpdatePlayerStatisticsRequest::ToJson() const
{
    return ServerUpdatePlayerStatisticsRequest::ToJson(this->Model());
}

JsonValue ServerUpdatePlayerStatisticsRequest::ToJson(const PFPlayerDataManagementServerUpdatePlayerStatisticsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceUpdate", input.forceUpdate);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMemberArray<StatisticUpdate>(output, "Statistics", input.statistics, input.statisticsCount);
    return output;
}

JsonValue ServerUpdateUserDataRequest::ToJson() const
{
    return ServerUpdateUserDataRequest::ToJson(this->Model());
}

JsonValue ServerUpdateUserDataRequest::ToJson(const PFPlayerDataManagementServerUpdateUserDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "Data", input.data, input.dataCount);
    JsonUtils::ObjectAddMemberArray(output, "KeysToRemove", input.keysToRemove, input.keysToRemoveCount);
    JsonUtils::ObjectAddMember(output, "Permission", input.permission);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

} // namespace PlayerDataManagement
} // namespace PlayFab
