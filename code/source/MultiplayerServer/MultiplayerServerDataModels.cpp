#include "stdafx.h"
#include "MultiplayerServerDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace MultiplayerServer
{

JsonValue BuildSelectionCriterion::ToJson() const
{
    return BuildSelectionCriterion::ToJson(this->Model());
}

JsonValue BuildSelectionCriterion::ToJson(const PFMultiplayerServerBuildSelectionCriterion& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "BuildWeightDistribution", input.buildWeightDistribution, input.buildWeightDistributionCount);
    return output;
}

void BuildSelectionCriterion::FromJson(const JsonValue& input)
{
    DictionaryEntryVector<PFUint32DictionaryEntry> buildWeightDistribution{};
    JsonUtils::ObjectGetMember(input, "BuildWeightDistribution", buildWeightDistribution);
    this->SetBuildWeightDistribution(std::move(buildWeightDistribution));
}

size_t BuildSelectionCriterion::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerBuildSelectionCriterion const*> BuildSelectionCriterion::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<BuildSelectionCriterion>(&this->Model());
}

size_t BuildSelectionCriterion::RequiredBufferSize(const PFMultiplayerServerBuildSelectionCriterion& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFUint32DictionaryEntry) + sizeof(PFUint32DictionaryEntry) * model.buildWeightDistributionCount);
    for (size_t i = 0; i < model.buildWeightDistributionCount; ++i)
    {
        requiredSize += (std::strlen(model.buildWeightDistribution[i].key) + 1);
    }
    return requiredSize;
}

HRESULT BuildSelectionCriterion::Copy(const PFMultiplayerServerBuildSelectionCriterion& input, PFMultiplayerServerBuildSelectionCriterion& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToDictionary(input.buildWeightDistribution, input.buildWeightDistributionCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildWeightDistribution = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CreateBuildAliasRequest::ToJson() const
{
    return CreateBuildAliasRequest::ToJson(this->Model());
}

JsonValue CreateBuildAliasRequest::ToJson(const PFMultiplayerServerCreateBuildAliasRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AliasName", input.aliasName);
    JsonUtils::ObjectAddMemberArray<BuildSelectionCriterion>(output, "BuildSelectionCriteria", input.buildSelectionCriteria, input.buildSelectionCriteriaCount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

void BuildAliasDetailsResponse::FromJson(const JsonValue& input)
{
    String aliasId{};
    JsonUtils::ObjectGetMember(input, "AliasId", aliasId);
    this->SetAliasId(std::move(aliasId));

    String aliasName{};
    JsonUtils::ObjectGetMember(input, "AliasName", aliasName);
    this->SetAliasName(std::move(aliasName));

    ModelVector<BuildSelectionCriterion> buildSelectionCriteria{};
    JsonUtils::ObjectGetMember<BuildSelectionCriterion>(input, "BuildSelectionCriteria", buildSelectionCriteria);
    this->SetBuildSelectionCriteria(std::move(buildSelectionCriteria));
}

size_t BuildAliasDetailsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerBuildAliasDetailsResponse const*> BuildAliasDetailsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<BuildAliasDetailsResponse>(&this->Model());
}

size_t BuildAliasDetailsResponse::RequiredBufferSize(const PFMultiplayerServerBuildAliasDetailsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.aliasId)
    {
        requiredSize += (std::strlen(model.aliasId) + 1);
    }
    if (model.aliasName)
    {
        requiredSize += (std::strlen(model.aliasName) + 1);
    }
    requiredSize += (alignof(PFMultiplayerServerBuildSelectionCriterion*) + sizeof(PFMultiplayerServerBuildSelectionCriterion*) * model.buildSelectionCriteriaCount);
    for (size_t i = 0; i < model.buildSelectionCriteriaCount; ++i)
    {
        requiredSize += BuildSelectionCriterion::RequiredBufferSize(*model.buildSelectionCriteria[i]);
    }
    return requiredSize;
}

HRESULT BuildAliasDetailsResponse::Copy(const PFMultiplayerServerBuildAliasDetailsResponse& input, PFMultiplayerServerBuildAliasDetailsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.aliasId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.aliasId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.aliasName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.aliasName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<BuildSelectionCriterion>(input.buildSelectionCriteria, input.buildSelectionCriteriaCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildSelectionCriteria = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ContainerImageReference::ToJson() const
{
    return ContainerImageReference::ToJson(this->Model());
}

JsonValue ContainerImageReference::ToJson(const PFMultiplayerServerContainerImageReference& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ImageName", input.imageName);
    JsonUtils::ObjectAddMember(output, "Tag", input.tag);
    return output;
}

void ContainerImageReference::FromJson(const JsonValue& input)
{
    String imageName{};
    JsonUtils::ObjectGetMember(input, "ImageName", imageName);
    this->SetImageName(std::move(imageName));

    String tag{};
    JsonUtils::ObjectGetMember(input, "Tag", tag);
    this->SetTag(std::move(tag));
}

size_t ContainerImageReference::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerContainerImageReference const*> ContainerImageReference::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ContainerImageReference>(&this->Model());
}

size_t ContainerImageReference::RequiredBufferSize(const PFMultiplayerServerContainerImageReference& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.imageName)
    {
        requiredSize += (std::strlen(model.imageName) + 1);
    }
    if (model.tag)
    {
        requiredSize += (std::strlen(model.tag) + 1);
    }
    return requiredSize;
}

HRESULT ContainerImageReference::Copy(const PFMultiplayerServerContainerImageReference& input, PFMultiplayerServerContainerImageReference& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.imageName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.imageName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.tag); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.tag = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue AssetReferenceParams::ToJson() const
{
    return AssetReferenceParams::ToJson(this->Model());
}

JsonValue AssetReferenceParams::ToJson(const PFMultiplayerServerAssetReferenceParams& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "FileName", input.fileName);
    JsonUtils::ObjectAddMember(output, "MountPath", input.mountPath);
    return output;
}

JsonValue GameCertificateReferenceParams::ToJson() const
{
    return GameCertificateReferenceParams::ToJson(this->Model());
}

JsonValue GameCertificateReferenceParams::ToJson(const PFMultiplayerServerGameCertificateReferenceParams& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "GsdkAlias", input.gsdkAlias);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    return output;
}

JsonValue LinuxInstrumentationConfiguration::ToJson() const
{
    return LinuxInstrumentationConfiguration::ToJson(this->Model());
}

JsonValue LinuxInstrumentationConfiguration::ToJson(const PFMultiplayerServerLinuxInstrumentationConfiguration& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "IsEnabled", input.isEnabled);
    return output;
}

void LinuxInstrumentationConfiguration::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "IsEnabled", this->m_model.isEnabled);
}

size_t LinuxInstrumentationConfiguration::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerLinuxInstrumentationConfiguration const*> LinuxInstrumentationConfiguration::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<LinuxInstrumentationConfiguration>(&this->Model());
}

size_t LinuxInstrumentationConfiguration::RequiredBufferSize(const PFMultiplayerServerLinuxInstrumentationConfiguration& model)
{
    UNREFERENCED_PARAMETER(model); // Fixed size
    return sizeof(ModelType);
}

HRESULT LinuxInstrumentationConfiguration::Copy(const PFMultiplayerServerLinuxInstrumentationConfiguration& input, PFMultiplayerServerLinuxInstrumentationConfiguration& output, ModelBuffer& buffer)
{
    output = input;
    UNREFERENCED_PARAMETER(buffer); // Fixed size
    return S_OK;
}

JsonValue DynamicStandbyThreshold::ToJson() const
{
    return DynamicStandbyThreshold::ToJson(this->Model());
}

JsonValue DynamicStandbyThreshold::ToJson(const PFMultiplayerServerDynamicStandbyThreshold& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Multiplier", input.multiplier);
    JsonUtils::ObjectAddMember(output, "TriggerThresholdPercentage", input.triggerThresholdPercentage);
    return output;
}

void DynamicStandbyThreshold::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "Multiplier", this->m_model.multiplier);

    JsonUtils::ObjectGetMember(input, "TriggerThresholdPercentage", this->m_model.triggerThresholdPercentage);
}

size_t DynamicStandbyThreshold::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerDynamicStandbyThreshold const*> DynamicStandbyThreshold::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<DynamicStandbyThreshold>(&this->Model());
}

size_t DynamicStandbyThreshold::RequiredBufferSize(const PFMultiplayerServerDynamicStandbyThreshold& model)
{
    UNREFERENCED_PARAMETER(model); // Fixed size
    return sizeof(ModelType);
}

HRESULT DynamicStandbyThreshold::Copy(const PFMultiplayerServerDynamicStandbyThreshold& input, PFMultiplayerServerDynamicStandbyThreshold& output, ModelBuffer& buffer)
{
    output = input;
    UNREFERENCED_PARAMETER(buffer); // Fixed size
    return S_OK;
}

JsonValue DynamicStandbySettings::ToJson() const
{
    return DynamicStandbySettings::ToJson(this->Model());
}

JsonValue DynamicStandbySettings::ToJson(const PFMultiplayerServerDynamicStandbySettings& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray<DynamicStandbyThreshold>(output, "DynamicFloorMultiplierThresholds", input.dynamicFloorMultiplierThresholds, input.dynamicFloorMultiplierThresholdsCount);
    JsonUtils::ObjectAddMember(output, "IsEnabled", input.isEnabled);
    JsonUtils::ObjectAddMember(output, "RampDownSeconds", input.rampDownSeconds);
    return output;
}

void DynamicStandbySettings::FromJson(const JsonValue& input)
{
    ModelVector<DynamicStandbyThreshold> dynamicFloorMultiplierThresholds{};
    JsonUtils::ObjectGetMember<DynamicStandbyThreshold>(input, "DynamicFloorMultiplierThresholds", dynamicFloorMultiplierThresholds);
    this->SetDynamicFloorMultiplierThresholds(std::move(dynamicFloorMultiplierThresholds));

    JsonUtils::ObjectGetMember(input, "IsEnabled", this->m_model.isEnabled);

    StdExtra::optional<int32_t> rampDownSeconds{};
    JsonUtils::ObjectGetMember(input, "RampDownSeconds", rampDownSeconds);
    this->SetRampDownSeconds(std::move(rampDownSeconds));
}

size_t DynamicStandbySettings::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerDynamicStandbySettings const*> DynamicStandbySettings::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<DynamicStandbySettings>(&this->Model());
}

size_t DynamicStandbySettings::RequiredBufferSize(const PFMultiplayerServerDynamicStandbySettings& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFMultiplayerServerDynamicStandbyThreshold*) + sizeof(PFMultiplayerServerDynamicStandbyThreshold*) * model.dynamicFloorMultiplierThresholdsCount);
    for (size_t i = 0; i < model.dynamicFloorMultiplierThresholdsCount; ++i)
    {
        requiredSize += DynamicStandbyThreshold::RequiredBufferSize(*model.dynamicFloorMultiplierThresholds[i]);
    }
    if (model.rampDownSeconds)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    return requiredSize;
}

HRESULT DynamicStandbySettings::Copy(const PFMultiplayerServerDynamicStandbySettings& input, PFMultiplayerServerDynamicStandbySettings& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<DynamicStandbyThreshold>(input.dynamicFloorMultiplierThresholds, input.dynamicFloorMultiplierThresholdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.dynamicFloorMultiplierThresholds = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.rampDownSeconds); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.rampDownSeconds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue Schedule::ToJson() const
{
    return Schedule::ToJson(this->Model());
}

JsonValue Schedule::ToJson(const PFMultiplayerServerSchedule& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Description", input.description);
    JsonUtils::ObjectAddMemberTime(output, "EndTime", input.endTime);
    JsonUtils::ObjectAddMember(output, "IsDisabled", input.isDisabled);
    JsonUtils::ObjectAddMember(output, "IsRecurringWeekly", input.isRecurringWeekly);
    JsonUtils::ObjectAddMemberTime(output, "StartTime", input.startTime);
    JsonUtils::ObjectAddMember(output, "TargetStandby", input.targetStandby);
    return output;
}

void Schedule::FromJson(const JsonValue& input)
{
    String description{};
    JsonUtils::ObjectGetMember(input, "Description", description);
    this->SetDescription(std::move(description));

    JsonUtils::ObjectGetMemberTime(input, "EndTime", this->m_model.endTime);

    JsonUtils::ObjectGetMember(input, "IsDisabled", this->m_model.isDisabled);

    JsonUtils::ObjectGetMember(input, "IsRecurringWeekly", this->m_model.isRecurringWeekly);

    JsonUtils::ObjectGetMemberTime(input, "StartTime", this->m_model.startTime);

    JsonUtils::ObjectGetMember(input, "TargetStandby", this->m_model.targetStandby);
}

size_t Schedule::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerSchedule const*> Schedule::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<Schedule>(&this->Model());
}

size_t Schedule::RequiredBufferSize(const PFMultiplayerServerSchedule& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.description)
    {
        requiredSize += (std::strlen(model.description) + 1);
    }
    return requiredSize;
}

HRESULT Schedule::Copy(const PFMultiplayerServerSchedule& input, PFMultiplayerServerSchedule& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.description); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.description = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ScheduledStandbySettings::ToJson() const
{
    return ScheduledStandbySettings::ToJson(this->Model());
}

JsonValue ScheduledStandbySettings::ToJson(const PFMultiplayerServerScheduledStandbySettings& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "IsEnabled", input.isEnabled);
    JsonUtils::ObjectAddMemberArray<Schedule>(output, "ScheduleList", input.scheduleList, input.scheduleListCount);
    return output;
}

void ScheduledStandbySettings::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "IsEnabled", this->m_model.isEnabled);

    ModelVector<Schedule> scheduleList{};
    JsonUtils::ObjectGetMember<Schedule>(input, "ScheduleList", scheduleList);
    this->SetScheduleList(std::move(scheduleList));
}

size_t ScheduledStandbySettings::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerScheduledStandbySettings const*> ScheduledStandbySettings::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ScheduledStandbySettings>(&this->Model());
}

size_t ScheduledStandbySettings::RequiredBufferSize(const PFMultiplayerServerScheduledStandbySettings& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFMultiplayerServerSchedule*) + sizeof(PFMultiplayerServerSchedule*) * model.scheduleListCount);
    for (size_t i = 0; i < model.scheduleListCount; ++i)
    {
        requiredSize += Schedule::RequiredBufferSize(*model.scheduleList[i]);
    }
    return requiredSize;
}

HRESULT ScheduledStandbySettings::Copy(const PFMultiplayerServerScheduledStandbySettings& input, PFMultiplayerServerScheduledStandbySettings& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<Schedule>(input.scheduleList, input.scheduleListCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.scheduleList = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue BuildRegionParams::ToJson() const
{
    return BuildRegionParams::ToJson(this->Model());
}

JsonValue BuildRegionParams::ToJson(const PFMultiplayerServerBuildRegionParams& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<DynamicStandbySettings>(output, "DynamicStandbySettings", input.dynamicStandbySettings);
    JsonUtils::ObjectAddMember(output, "MaxServers", input.maxServers);
    JsonUtils::ObjectAddMember(output, "MultiplayerServerCountPerVm", input.multiplayerServerCountPerVm);
    JsonUtils::ObjectAddMember(output, "Region", input.region);
    JsonUtils::ObjectAddMember<ScheduledStandbySettings>(output, "ScheduledStandbySettings", input.scheduledStandbySettings);
    JsonUtils::ObjectAddMember(output, "StandbyServers", input.standbyServers);
    JsonUtils::ObjectAddMember(output, "VmSize", input.vmSize);
    return output;
}

JsonValue CreateBuildWithCustomContainerRequest::ToJson() const
{
    return CreateBuildWithCustomContainerRequest::ToJson(this->Model());
}

JsonValue CreateBuildWithCustomContainerRequest::ToJson(const PFMultiplayerServerCreateBuildWithCustomContainerRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AreAssetsReadonly", input.areAssetsReadonly);
    JsonUtils::ObjectAddMember(output, "BuildName", input.buildName);
    JsonUtils::ObjectAddMember(output, "ContainerFlavor", input.containerFlavor);
    JsonUtils::ObjectAddMember<ContainerImageReference>(output, "ContainerImageReference", input.containerImageReference);
    JsonUtils::ObjectAddMember(output, "ContainerRunCommand", input.containerRunCommand);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray<AssetReferenceParams>(output, "GameAssetReferences", input.gameAssetReferences, input.gameAssetReferencesCount);
    JsonUtils::ObjectAddMemberArray<GameCertificateReferenceParams>(output, "GameCertificateReferences", input.gameCertificateReferences, input.gameCertificateReferencesCount);
    JsonUtils::ObjectAddMember<LinuxInstrumentationConfiguration>(output, "LinuxInstrumentationConfiguration", input.linuxInstrumentationConfiguration);
    JsonUtils::ObjectAddMemberDictionary(output, "Metadata", input.metadata, input.metadataCount);
    JsonUtils::ObjectAddMember(output, "MultiplayerServerCountPerVm", input.multiplayerServerCountPerVm);
    JsonUtils::ObjectAddMemberArray<Port>(output, "Ports", input.ports, input.portsCount);
    JsonUtils::ObjectAddMemberArray<BuildRegionParams>(output, "RegionConfigurations", input.regionConfigurations, input.regionConfigurationsCount);
    JsonUtils::ObjectAddMember(output, "UseStreamingForAssetDownloads", input.useStreamingForAssetDownloads);
    JsonUtils::ObjectAddMember(output, "VmSize", input.vmSize);
    return output;
}

void AssetReference::FromJson(const JsonValue& input)
{
    String fileName{};
    JsonUtils::ObjectGetMember(input, "FileName", fileName);
    this->SetFileName(std::move(fileName));

    String mountPath{};
    JsonUtils::ObjectGetMember(input, "MountPath", mountPath);
    this->SetMountPath(std::move(mountPath));
}

size_t AssetReference::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerAssetReference const*> AssetReference::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AssetReference>(&this->Model());
}

size_t AssetReference::RequiredBufferSize(const PFMultiplayerServerAssetReference& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.fileName)
    {
        requiredSize += (std::strlen(model.fileName) + 1);
    }
    if (model.mountPath)
    {
        requiredSize += (std::strlen(model.mountPath) + 1);
    }
    return requiredSize;
}

HRESULT AssetReference::Copy(const PFMultiplayerServerAssetReference& input, PFMultiplayerServerAssetReference& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.fileName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.fileName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.mountPath); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.mountPath = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GameCertificateReference::FromJson(const JsonValue& input)
{
    String gsdkAlias{};
    JsonUtils::ObjectGetMember(input, "GsdkAlias", gsdkAlias);
    this->SetGsdkAlias(std::move(gsdkAlias));

    String name{};
    JsonUtils::ObjectGetMember(input, "Name", name);
    this->SetName(std::move(name));
}

size_t GameCertificateReference::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerGameCertificateReference const*> GameCertificateReference::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GameCertificateReference>(&this->Model());
}

size_t GameCertificateReference::RequiredBufferSize(const PFMultiplayerServerGameCertificateReference& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.gsdkAlias)
    {
        requiredSize += (std::strlen(model.gsdkAlias) + 1);
    }
    if (model.name)
    {
        requiredSize += (std::strlen(model.name) + 1);
    }
    return requiredSize;
}

HRESULT GameCertificateReference::Copy(const PFMultiplayerServerGameCertificateReference& input, PFMultiplayerServerGameCertificateReference& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.gsdkAlias); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.gsdkAlias = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.name); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.name = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void CurrentServerStats::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "Active", this->m_model.active);

    JsonUtils::ObjectGetMember(input, "Propping", this->m_model.propping);

    JsonUtils::ObjectGetMember(input, "StandingBy", this->m_model.standingBy);

    JsonUtils::ObjectGetMember(input, "Total", this->m_model.total);
}

size_t CurrentServerStats::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerCurrentServerStats const*> CurrentServerStats::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CurrentServerStats>(&this->Model());
}

size_t CurrentServerStats::RequiredBufferSize(const PFMultiplayerServerCurrentServerStats& model)
{
    UNREFERENCED_PARAMETER(model); // Fixed size
    return sizeof(ModelType);
}

HRESULT CurrentServerStats::Copy(const PFMultiplayerServerCurrentServerStats& input, PFMultiplayerServerCurrentServerStats& output, ModelBuffer& buffer)
{
    output = input;
    UNREFERENCED_PARAMETER(buffer); // Fixed size
    return S_OK;
}

void BuildRegion::FromJson(const JsonValue& input)
{
    StdExtra::optional<CurrentServerStats> currentServerStats{};
    JsonUtils::ObjectGetMember(input, "CurrentServerStats", currentServerStats);
    if (currentServerStats)
    {
        this->SetCurrentServerStats(std::move(*currentServerStats));
    }

    StdExtra::optional<DynamicStandbySettings> dynamicStandbySettings{};
    JsonUtils::ObjectGetMember(input, "DynamicStandbySettings", dynamicStandbySettings);
    if (dynamicStandbySettings)
    {
        this->SetDynamicStandbySettings(std::move(*dynamicStandbySettings));
    }

    JsonUtils::ObjectGetMember(input, "MaxServers", this->m_model.maxServers);

    StdExtra::optional<int32_t> multiplayerServerCountPerVm{};
    JsonUtils::ObjectGetMember(input, "MultiplayerServerCountPerVm", multiplayerServerCountPerVm);
    this->SetMultiplayerServerCountPerVm(std::move(multiplayerServerCountPerVm));

    String region{};
    JsonUtils::ObjectGetMember(input, "Region", region);
    this->SetRegion(std::move(region));

    StdExtra::optional<ScheduledStandbySettings> scheduledStandbySettings{};
    JsonUtils::ObjectGetMember(input, "ScheduledStandbySettings", scheduledStandbySettings);
    if (scheduledStandbySettings)
    {
        this->SetScheduledStandbySettings(std::move(*scheduledStandbySettings));
    }

    JsonUtils::ObjectGetMember(input, "StandbyServers", this->m_model.standbyServers);

    String status{};
    JsonUtils::ObjectGetMember(input, "Status", status);
    this->SetStatus(std::move(status));

    StdExtra::optional<PFMultiplayerServerAzureVmSize> vmSize{};
    JsonUtils::ObjectGetMember(input, "VmSize", vmSize);
    this->SetVmSize(std::move(vmSize));
}

size_t BuildRegion::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerBuildRegion const*> BuildRegion::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<BuildRegion>(&this->Model());
}

size_t BuildRegion::RequiredBufferSize(const PFMultiplayerServerBuildRegion& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.currentServerStats)
    {
        requiredSize += CurrentServerStats::RequiredBufferSize(*model.currentServerStats);
    }
    if (model.dynamicStandbySettings)
    {
        requiredSize += DynamicStandbySettings::RequiredBufferSize(*model.dynamicStandbySettings);
    }
    if (model.multiplayerServerCountPerVm)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    if (model.region)
    {
        requiredSize += (std::strlen(model.region) + 1);
    }
    if (model.scheduledStandbySettings)
    {
        requiredSize += ScheduledStandbySettings::RequiredBufferSize(*model.scheduledStandbySettings);
    }
    if (model.status)
    {
        requiredSize += (std::strlen(model.status) + 1);
    }
    if (model.vmSize)
    {
        requiredSize += (alignof(PFMultiplayerServerAzureVmSize) + sizeof(PFMultiplayerServerAzureVmSize));
    }
    return requiredSize;
}

HRESULT BuildRegion::Copy(const PFMultiplayerServerBuildRegion& input, PFMultiplayerServerBuildRegion& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<CurrentServerStats>(input.currentServerStats); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.currentServerStats = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<DynamicStandbySettings>(input.dynamicStandbySettings); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.dynamicStandbySettings = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.multiplayerServerCountPerVm); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.multiplayerServerCountPerVm = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.region); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.region = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<ScheduledStandbySettings>(input.scheduledStandbySettings); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.scheduledStandbySettings = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.status); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.status = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.vmSize); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.vmSize = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void CreateBuildWithCustomContainerResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<bool> areAssetsReadonly{};
    JsonUtils::ObjectGetMember(input, "AreAssetsReadonly", areAssetsReadonly);
    this->SetAreAssetsReadonly(std::move(areAssetsReadonly));

    String buildId{};
    JsonUtils::ObjectGetMember(input, "BuildId", buildId);
    this->SetBuildId(std::move(buildId));

    String buildName{};
    JsonUtils::ObjectGetMember(input, "BuildName", buildName);
    this->SetBuildName(std::move(buildName));

    StdExtra::optional<PFMultiplayerServerContainerFlavor> containerFlavor{};
    JsonUtils::ObjectGetMember(input, "ContainerFlavor", containerFlavor);
    this->SetContainerFlavor(std::move(containerFlavor));

    String containerRunCommand{};
    JsonUtils::ObjectGetMember(input, "ContainerRunCommand", containerRunCommand);
    this->SetContainerRunCommand(std::move(containerRunCommand));

    StdExtra::optional<time_t> creationTime{};
    JsonUtils::ObjectGetMemberTime(input, "CreationTime", creationTime);
    this->SetCreationTime(std::move(creationTime));

    StdExtra::optional<ContainerImageReference> customGameContainerImage{};
    JsonUtils::ObjectGetMember(input, "CustomGameContainerImage", customGameContainerImage);
    if (customGameContainerImage)
    {
        this->SetCustomGameContainerImage(std::move(*customGameContainerImage));
    }

    ModelVector<AssetReference> gameAssetReferences{};
    JsonUtils::ObjectGetMember<AssetReference>(input, "GameAssetReferences", gameAssetReferences);
    this->SetGameAssetReferences(std::move(gameAssetReferences));

    ModelVector<GameCertificateReference> gameCertificateReferences{};
    JsonUtils::ObjectGetMember<GameCertificateReference>(input, "GameCertificateReferences", gameCertificateReferences);
    this->SetGameCertificateReferences(std::move(gameCertificateReferences));

    StdExtra::optional<LinuxInstrumentationConfiguration> linuxInstrumentationConfiguration{};
    JsonUtils::ObjectGetMember(input, "LinuxInstrumentationConfiguration", linuxInstrumentationConfiguration);
    if (linuxInstrumentationConfiguration)
    {
        this->SetLinuxInstrumentationConfiguration(std::move(*linuxInstrumentationConfiguration));
    }

    StringDictionaryEntryVector metadata{};
    JsonUtils::ObjectGetMember(input, "Metadata", metadata);
    this->SetMetadata(std::move(metadata));

    JsonUtils::ObjectGetMember(input, "MultiplayerServerCountPerVm", this->m_model.multiplayerServerCountPerVm);

    String osPlatform{};
    JsonUtils::ObjectGetMember(input, "OsPlatform", osPlatform);
    this->SetOsPlatform(std::move(osPlatform));

    ModelVector<Port> ports{};
    JsonUtils::ObjectGetMember<Port>(input, "Ports", ports);
    this->SetPorts(std::move(ports));

    ModelVector<BuildRegion> regionConfigurations{};
    JsonUtils::ObjectGetMember<BuildRegion>(input, "RegionConfigurations", regionConfigurations);
    this->SetRegionConfigurations(std::move(regionConfigurations));

    String serverType{};
    JsonUtils::ObjectGetMember(input, "ServerType", serverType);
    this->SetServerType(std::move(serverType));

    StdExtra::optional<bool> useStreamingForAssetDownloads{};
    JsonUtils::ObjectGetMember(input, "UseStreamingForAssetDownloads", useStreamingForAssetDownloads);
    this->SetUseStreamingForAssetDownloads(std::move(useStreamingForAssetDownloads));

    StdExtra::optional<PFMultiplayerServerAzureVmSize> vmSize{};
    JsonUtils::ObjectGetMember(input, "VmSize", vmSize);
    this->SetVmSize(std::move(vmSize));
}

size_t CreateBuildWithCustomContainerResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerCreateBuildWithCustomContainerResponse const*> CreateBuildWithCustomContainerResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreateBuildWithCustomContainerResponse>(&this->Model());
}

size_t CreateBuildWithCustomContainerResponse::RequiredBufferSize(const PFMultiplayerServerCreateBuildWithCustomContainerResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.areAssetsReadonly)
    {
        requiredSize += (alignof(bool) + sizeof(bool));
    }
    if (model.buildId)
    {
        requiredSize += (std::strlen(model.buildId) + 1);
    }
    if (model.buildName)
    {
        requiredSize += (std::strlen(model.buildName) + 1);
    }
    if (model.containerFlavor)
    {
        requiredSize += (alignof(PFMultiplayerServerContainerFlavor) + sizeof(PFMultiplayerServerContainerFlavor));
    }
    if (model.containerRunCommand)
    {
        requiredSize += (std::strlen(model.containerRunCommand) + 1);
    }
    if (model.creationTime)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.customGameContainerImage)
    {
        requiredSize += ContainerImageReference::RequiredBufferSize(*model.customGameContainerImage);
    }
    requiredSize += (alignof(PFMultiplayerServerAssetReference*) + sizeof(PFMultiplayerServerAssetReference*) * model.gameAssetReferencesCount);
    for (size_t i = 0; i < model.gameAssetReferencesCount; ++i)
    {
        requiredSize += AssetReference::RequiredBufferSize(*model.gameAssetReferences[i]);
    }
    requiredSize += (alignof(PFMultiplayerServerGameCertificateReference*) + sizeof(PFMultiplayerServerGameCertificateReference*) * model.gameCertificateReferencesCount);
    for (size_t i = 0; i < model.gameCertificateReferencesCount; ++i)
    {
        requiredSize += GameCertificateReference::RequiredBufferSize(*model.gameCertificateReferences[i]);
    }
    if (model.linuxInstrumentationConfiguration)
    {
        requiredSize += LinuxInstrumentationConfiguration::RequiredBufferSize(*model.linuxInstrumentationConfiguration);
    }
    requiredSize += (alignof(PFStringDictionaryEntry) + sizeof(PFStringDictionaryEntry) * model.metadataCount);
    for (size_t i = 0; i < model.metadataCount; ++i)
    {
        requiredSize += (std::strlen(model.metadata[i].key) + 1);
        requiredSize += (std::strlen(model.metadata[i].value) + 1);
    }
    if (model.osPlatform)
    {
        requiredSize += (std::strlen(model.osPlatform) + 1);
    }
    requiredSize += (alignof(PFPort*) + sizeof(PFPort*) * model.portsCount);
    for (size_t i = 0; i < model.portsCount; ++i)
    {
        requiredSize += Port::RequiredBufferSize(*model.ports[i]);
    }
    requiredSize += (alignof(PFMultiplayerServerBuildRegion*) + sizeof(PFMultiplayerServerBuildRegion*) * model.regionConfigurationsCount);
    for (size_t i = 0; i < model.regionConfigurationsCount; ++i)
    {
        requiredSize += BuildRegion::RequiredBufferSize(*model.regionConfigurations[i]);
    }
    if (model.serverType)
    {
        requiredSize += (std::strlen(model.serverType) + 1);
    }
    if (model.useStreamingForAssetDownloads)
    {
        requiredSize += (alignof(bool) + sizeof(bool));
    }
    if (model.vmSize)
    {
        requiredSize += (alignof(PFMultiplayerServerAzureVmSize) + sizeof(PFMultiplayerServerAzureVmSize));
    }
    return requiredSize;
}

HRESULT CreateBuildWithCustomContainerResponse::Copy(const PFMultiplayerServerCreateBuildWithCustomContainerResponse& input, PFMultiplayerServerCreateBuildWithCustomContainerResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.areAssetsReadonly); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.areAssetsReadonly = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.buildId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.buildName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.containerFlavor); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.containerFlavor = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.containerRunCommand); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.containerRunCommand = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.creationTime); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.creationTime = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<ContainerImageReference>(input.customGameContainerImage); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.customGameContainerImage = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<AssetReference>(input.gameAssetReferences, input.gameAssetReferencesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.gameAssetReferences = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<GameCertificateReference>(input.gameCertificateReferences, input.gameCertificateReferencesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.gameCertificateReferences = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<LinuxInstrumentationConfiguration>(input.linuxInstrumentationConfiguration); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.linuxInstrumentationConfiguration = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.metadata, input.metadataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.metadata = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.osPlatform); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.osPlatform = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<Port>(input.ports, input.portsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.ports = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<BuildRegion>(input.regionConfigurations, input.regionConfigurationsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.regionConfigurations = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverType); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverType = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.useStreamingForAssetDownloads); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.useStreamingForAssetDownloads = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.vmSize); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.vmSize = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue InstrumentationConfiguration::ToJson() const
{
    return InstrumentationConfiguration::ToJson(this->Model());
}

JsonValue InstrumentationConfiguration::ToJson(const PFMultiplayerServerInstrumentationConfiguration& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "IsEnabled", input.isEnabled);
    JsonUtils::ObjectAddMemberArray(output, "ProcessesToMonitor", input.processesToMonitor, input.processesToMonitorCount);
    return output;
}

void InstrumentationConfiguration::FromJson(const JsonValue& input)
{
    StdExtra::optional<bool> isEnabled{};
    JsonUtils::ObjectGetMember(input, "IsEnabled", isEnabled);
    this->SetIsEnabled(std::move(isEnabled));

    CStringVector processesToMonitor{};
    JsonUtils::ObjectGetMember(input, "ProcessesToMonitor", processesToMonitor);
    this->SetProcessesToMonitor(std::move(processesToMonitor));
}

size_t InstrumentationConfiguration::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerInstrumentationConfiguration const*> InstrumentationConfiguration::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<InstrumentationConfiguration>(&this->Model());
}

size_t InstrumentationConfiguration::RequiredBufferSize(const PFMultiplayerServerInstrumentationConfiguration& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.isEnabled)
    {
        requiredSize += (alignof(bool) + sizeof(bool));
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.processesToMonitorCount);
    for (size_t i = 0; i < model.processesToMonitorCount; ++i)
    {
        requiredSize += (std::strlen(model.processesToMonitor[i]) + 1);
    }
    return requiredSize;
}

HRESULT InstrumentationConfiguration::Copy(const PFMultiplayerServerInstrumentationConfiguration& input, PFMultiplayerServerInstrumentationConfiguration& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.isEnabled); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.isEnabled = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.processesToMonitor, input.processesToMonitorCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.processesToMonitor = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CreateBuildWithManagedContainerRequest::ToJson() const
{
    return CreateBuildWithManagedContainerRequest::ToJson(this->Model());
}

JsonValue CreateBuildWithManagedContainerRequest::ToJson(const PFMultiplayerServerCreateBuildWithManagedContainerRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AreAssetsReadonly", input.areAssetsReadonly);
    JsonUtils::ObjectAddMember(output, "BuildName", input.buildName);
    JsonUtils::ObjectAddMember(output, "ContainerFlavor", input.containerFlavor);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray<AssetReferenceParams>(output, "GameAssetReferences", input.gameAssetReferences, input.gameAssetReferencesCount);
    JsonUtils::ObjectAddMemberArray<GameCertificateReferenceParams>(output, "GameCertificateReferences", input.gameCertificateReferences, input.gameCertificateReferencesCount);
    JsonUtils::ObjectAddMember(output, "GameWorkingDirectory", input.gameWorkingDirectory);
    JsonUtils::ObjectAddMember<InstrumentationConfiguration>(output, "InstrumentationConfiguration", input.instrumentationConfiguration);
    JsonUtils::ObjectAddMemberDictionary(output, "Metadata", input.metadata, input.metadataCount);
    JsonUtils::ObjectAddMember(output, "MultiplayerServerCountPerVm", input.multiplayerServerCountPerVm);
    JsonUtils::ObjectAddMemberArray<Port>(output, "Ports", input.ports, input.portsCount);
    JsonUtils::ObjectAddMemberArray<BuildRegionParams>(output, "RegionConfigurations", input.regionConfigurations, input.regionConfigurationsCount);
    JsonUtils::ObjectAddMember(output, "StartMultiplayerServerCommand", input.startMultiplayerServerCommand);
    JsonUtils::ObjectAddMember(output, "UseStreamingForAssetDownloads", input.useStreamingForAssetDownloads);
    JsonUtils::ObjectAddMember(output, "VmSize", input.vmSize);
    return output;
}

void CreateBuildWithManagedContainerResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<bool> areAssetsReadonly{};
    JsonUtils::ObjectGetMember(input, "AreAssetsReadonly", areAssetsReadonly);
    this->SetAreAssetsReadonly(std::move(areAssetsReadonly));

    String buildId{};
    JsonUtils::ObjectGetMember(input, "BuildId", buildId);
    this->SetBuildId(std::move(buildId));

    String buildName{};
    JsonUtils::ObjectGetMember(input, "BuildName", buildName);
    this->SetBuildName(std::move(buildName));

    StdExtra::optional<PFMultiplayerServerContainerFlavor> containerFlavor{};
    JsonUtils::ObjectGetMember(input, "ContainerFlavor", containerFlavor);
    this->SetContainerFlavor(std::move(containerFlavor));

    StdExtra::optional<time_t> creationTime{};
    JsonUtils::ObjectGetMemberTime(input, "CreationTime", creationTime);
    this->SetCreationTime(std::move(creationTime));

    ModelVector<AssetReference> gameAssetReferences{};
    JsonUtils::ObjectGetMember<AssetReference>(input, "GameAssetReferences", gameAssetReferences);
    this->SetGameAssetReferences(std::move(gameAssetReferences));

    ModelVector<GameCertificateReference> gameCertificateReferences{};
    JsonUtils::ObjectGetMember<GameCertificateReference>(input, "GameCertificateReferences", gameCertificateReferences);
    this->SetGameCertificateReferences(std::move(gameCertificateReferences));

    String gameWorkingDirectory{};
    JsonUtils::ObjectGetMember(input, "GameWorkingDirectory", gameWorkingDirectory);
    this->SetGameWorkingDirectory(std::move(gameWorkingDirectory));

    StdExtra::optional<InstrumentationConfiguration> instrumentationConfiguration{};
    JsonUtils::ObjectGetMember(input, "InstrumentationConfiguration", instrumentationConfiguration);
    if (instrumentationConfiguration)
    {
        this->SetInstrumentationConfiguration(std::move(*instrumentationConfiguration));
    }

    StringDictionaryEntryVector metadata{};
    JsonUtils::ObjectGetMember(input, "Metadata", metadata);
    this->SetMetadata(std::move(metadata));

    JsonUtils::ObjectGetMember(input, "MultiplayerServerCountPerVm", this->m_model.multiplayerServerCountPerVm);

    String osPlatform{};
    JsonUtils::ObjectGetMember(input, "OsPlatform", osPlatform);
    this->SetOsPlatform(std::move(osPlatform));

    ModelVector<Port> ports{};
    JsonUtils::ObjectGetMember<Port>(input, "Ports", ports);
    this->SetPorts(std::move(ports));

    ModelVector<BuildRegion> regionConfigurations{};
    JsonUtils::ObjectGetMember<BuildRegion>(input, "RegionConfigurations", regionConfigurations);
    this->SetRegionConfigurations(std::move(regionConfigurations));

    String serverType{};
    JsonUtils::ObjectGetMember(input, "ServerType", serverType);
    this->SetServerType(std::move(serverType));

    String startMultiplayerServerCommand{};
    JsonUtils::ObjectGetMember(input, "StartMultiplayerServerCommand", startMultiplayerServerCommand);
    this->SetStartMultiplayerServerCommand(std::move(startMultiplayerServerCommand));

    StdExtra::optional<bool> useStreamingForAssetDownloads{};
    JsonUtils::ObjectGetMember(input, "UseStreamingForAssetDownloads", useStreamingForAssetDownloads);
    this->SetUseStreamingForAssetDownloads(std::move(useStreamingForAssetDownloads));

    StdExtra::optional<PFMultiplayerServerAzureVmSize> vmSize{};
    JsonUtils::ObjectGetMember(input, "VmSize", vmSize);
    this->SetVmSize(std::move(vmSize));
}

size_t CreateBuildWithManagedContainerResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerCreateBuildWithManagedContainerResponse const*> CreateBuildWithManagedContainerResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreateBuildWithManagedContainerResponse>(&this->Model());
}

size_t CreateBuildWithManagedContainerResponse::RequiredBufferSize(const PFMultiplayerServerCreateBuildWithManagedContainerResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.areAssetsReadonly)
    {
        requiredSize += (alignof(bool) + sizeof(bool));
    }
    if (model.buildId)
    {
        requiredSize += (std::strlen(model.buildId) + 1);
    }
    if (model.buildName)
    {
        requiredSize += (std::strlen(model.buildName) + 1);
    }
    if (model.containerFlavor)
    {
        requiredSize += (alignof(PFMultiplayerServerContainerFlavor) + sizeof(PFMultiplayerServerContainerFlavor));
    }
    if (model.creationTime)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    requiredSize += (alignof(PFMultiplayerServerAssetReference*) + sizeof(PFMultiplayerServerAssetReference*) * model.gameAssetReferencesCount);
    for (size_t i = 0; i < model.gameAssetReferencesCount; ++i)
    {
        requiredSize += AssetReference::RequiredBufferSize(*model.gameAssetReferences[i]);
    }
    requiredSize += (alignof(PFMultiplayerServerGameCertificateReference*) + sizeof(PFMultiplayerServerGameCertificateReference*) * model.gameCertificateReferencesCount);
    for (size_t i = 0; i < model.gameCertificateReferencesCount; ++i)
    {
        requiredSize += GameCertificateReference::RequiredBufferSize(*model.gameCertificateReferences[i]);
    }
    if (model.gameWorkingDirectory)
    {
        requiredSize += (std::strlen(model.gameWorkingDirectory) + 1);
    }
    if (model.instrumentationConfiguration)
    {
        requiredSize += InstrumentationConfiguration::RequiredBufferSize(*model.instrumentationConfiguration);
    }
    requiredSize += (alignof(PFStringDictionaryEntry) + sizeof(PFStringDictionaryEntry) * model.metadataCount);
    for (size_t i = 0; i < model.metadataCount; ++i)
    {
        requiredSize += (std::strlen(model.metadata[i].key) + 1);
        requiredSize += (std::strlen(model.metadata[i].value) + 1);
    }
    if (model.osPlatform)
    {
        requiredSize += (std::strlen(model.osPlatform) + 1);
    }
    requiredSize += (alignof(PFPort*) + sizeof(PFPort*) * model.portsCount);
    for (size_t i = 0; i < model.portsCount; ++i)
    {
        requiredSize += Port::RequiredBufferSize(*model.ports[i]);
    }
    requiredSize += (alignof(PFMultiplayerServerBuildRegion*) + sizeof(PFMultiplayerServerBuildRegion*) * model.regionConfigurationsCount);
    for (size_t i = 0; i < model.regionConfigurationsCount; ++i)
    {
        requiredSize += BuildRegion::RequiredBufferSize(*model.regionConfigurations[i]);
    }
    if (model.serverType)
    {
        requiredSize += (std::strlen(model.serverType) + 1);
    }
    if (model.startMultiplayerServerCommand)
    {
        requiredSize += (std::strlen(model.startMultiplayerServerCommand) + 1);
    }
    if (model.useStreamingForAssetDownloads)
    {
        requiredSize += (alignof(bool) + sizeof(bool));
    }
    if (model.vmSize)
    {
        requiredSize += (alignof(PFMultiplayerServerAzureVmSize) + sizeof(PFMultiplayerServerAzureVmSize));
    }
    return requiredSize;
}

HRESULT CreateBuildWithManagedContainerResponse::Copy(const PFMultiplayerServerCreateBuildWithManagedContainerResponse& input, PFMultiplayerServerCreateBuildWithManagedContainerResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.areAssetsReadonly); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.areAssetsReadonly = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.buildId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.buildName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.containerFlavor); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.containerFlavor = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.creationTime); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.creationTime = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<AssetReference>(input.gameAssetReferences, input.gameAssetReferencesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.gameAssetReferences = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<GameCertificateReference>(input.gameCertificateReferences, input.gameCertificateReferencesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.gameCertificateReferences = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.gameWorkingDirectory); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.gameWorkingDirectory = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<InstrumentationConfiguration>(input.instrumentationConfiguration); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.instrumentationConfiguration = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.metadata, input.metadataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.metadata = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.osPlatform); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.osPlatform = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<Port>(input.ports, input.portsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.ports = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<BuildRegion>(input.regionConfigurations, input.regionConfigurationsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.regionConfigurations = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverType); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverType = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.startMultiplayerServerCommand); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.startMultiplayerServerCommand = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.useStreamingForAssetDownloads); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.useStreamingForAssetDownloads = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.vmSize); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.vmSize = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CreateBuildWithProcessBasedServerRequest::ToJson() const
{
    return CreateBuildWithProcessBasedServerRequest::ToJson(this->Model());
}

JsonValue CreateBuildWithProcessBasedServerRequest::ToJson(const PFMultiplayerServerCreateBuildWithProcessBasedServerRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AreAssetsReadonly", input.areAssetsReadonly);
    JsonUtils::ObjectAddMember(output, "BuildName", input.buildName);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray<AssetReferenceParams>(output, "GameAssetReferences", input.gameAssetReferences, input.gameAssetReferencesCount);
    JsonUtils::ObjectAddMemberArray<GameCertificateReferenceParams>(output, "GameCertificateReferences", input.gameCertificateReferences, input.gameCertificateReferencesCount);
    JsonUtils::ObjectAddMember(output, "GameWorkingDirectory", input.gameWorkingDirectory);
    JsonUtils::ObjectAddMember<InstrumentationConfiguration>(output, "InstrumentationConfiguration", input.instrumentationConfiguration);
    JsonUtils::ObjectAddMember(output, "IsOSPreview", input.isOSPreview);
    JsonUtils::ObjectAddMemberDictionary(output, "Metadata", input.metadata, input.metadataCount);
    JsonUtils::ObjectAddMember(output, "MultiplayerServerCountPerVm", input.multiplayerServerCountPerVm);
    JsonUtils::ObjectAddMember(output, "OsPlatform", input.osPlatform);
    JsonUtils::ObjectAddMemberArray<Port>(output, "Ports", input.ports, input.portsCount);
    JsonUtils::ObjectAddMemberArray<BuildRegionParams>(output, "RegionConfigurations", input.regionConfigurations, input.regionConfigurationsCount);
    JsonUtils::ObjectAddMember(output, "StartMultiplayerServerCommand", input.startMultiplayerServerCommand);
    JsonUtils::ObjectAddMember(output, "UseStreamingForAssetDownloads", input.useStreamingForAssetDownloads);
    JsonUtils::ObjectAddMember(output, "VmSize", input.vmSize);
    return output;
}

void CreateBuildWithProcessBasedServerResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<bool> areAssetsReadonly{};
    JsonUtils::ObjectGetMember(input, "AreAssetsReadonly", areAssetsReadonly);
    this->SetAreAssetsReadonly(std::move(areAssetsReadonly));

    String buildId{};
    JsonUtils::ObjectGetMember(input, "BuildId", buildId);
    this->SetBuildId(std::move(buildId));

    String buildName{};
    JsonUtils::ObjectGetMember(input, "BuildName", buildName);
    this->SetBuildName(std::move(buildName));

    StdExtra::optional<PFMultiplayerServerContainerFlavor> containerFlavor{};
    JsonUtils::ObjectGetMember(input, "ContainerFlavor", containerFlavor);
    this->SetContainerFlavor(std::move(containerFlavor));

    StdExtra::optional<time_t> creationTime{};
    JsonUtils::ObjectGetMemberTime(input, "CreationTime", creationTime);
    this->SetCreationTime(std::move(creationTime));

    ModelVector<AssetReference> gameAssetReferences{};
    JsonUtils::ObjectGetMember<AssetReference>(input, "GameAssetReferences", gameAssetReferences);
    this->SetGameAssetReferences(std::move(gameAssetReferences));

    ModelVector<GameCertificateReference> gameCertificateReferences{};
    JsonUtils::ObjectGetMember<GameCertificateReference>(input, "GameCertificateReferences", gameCertificateReferences);
    this->SetGameCertificateReferences(std::move(gameCertificateReferences));

    String gameWorkingDirectory{};
    JsonUtils::ObjectGetMember(input, "GameWorkingDirectory", gameWorkingDirectory);
    this->SetGameWorkingDirectory(std::move(gameWorkingDirectory));

    StdExtra::optional<InstrumentationConfiguration> instrumentationConfiguration{};
    JsonUtils::ObjectGetMember(input, "InstrumentationConfiguration", instrumentationConfiguration);
    if (instrumentationConfiguration)
    {
        this->SetInstrumentationConfiguration(std::move(*instrumentationConfiguration));
    }

    StdExtra::optional<bool> isOSPreview{};
    JsonUtils::ObjectGetMember(input, "IsOSPreview", isOSPreview);
    this->SetIsOSPreview(std::move(isOSPreview));

    StringDictionaryEntryVector metadata{};
    JsonUtils::ObjectGetMember(input, "Metadata", metadata);
    this->SetMetadata(std::move(metadata));

    JsonUtils::ObjectGetMember(input, "MultiplayerServerCountPerVm", this->m_model.multiplayerServerCountPerVm);

    String osPlatform{};
    JsonUtils::ObjectGetMember(input, "OsPlatform", osPlatform);
    this->SetOsPlatform(std::move(osPlatform));

    ModelVector<Port> ports{};
    JsonUtils::ObjectGetMember<Port>(input, "Ports", ports);
    this->SetPorts(std::move(ports));

    ModelVector<BuildRegion> regionConfigurations{};
    JsonUtils::ObjectGetMember<BuildRegion>(input, "RegionConfigurations", regionConfigurations);
    this->SetRegionConfigurations(std::move(regionConfigurations));

    String serverType{};
    JsonUtils::ObjectGetMember(input, "ServerType", serverType);
    this->SetServerType(std::move(serverType));

    String startMultiplayerServerCommand{};
    JsonUtils::ObjectGetMember(input, "StartMultiplayerServerCommand", startMultiplayerServerCommand);
    this->SetStartMultiplayerServerCommand(std::move(startMultiplayerServerCommand));

    StdExtra::optional<bool> useStreamingForAssetDownloads{};
    JsonUtils::ObjectGetMember(input, "UseStreamingForAssetDownloads", useStreamingForAssetDownloads);
    this->SetUseStreamingForAssetDownloads(std::move(useStreamingForAssetDownloads));

    StdExtra::optional<PFMultiplayerServerAzureVmSize> vmSize{};
    JsonUtils::ObjectGetMember(input, "VmSize", vmSize);
    this->SetVmSize(std::move(vmSize));
}

size_t CreateBuildWithProcessBasedServerResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerCreateBuildWithProcessBasedServerResponse const*> CreateBuildWithProcessBasedServerResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreateBuildWithProcessBasedServerResponse>(&this->Model());
}

size_t CreateBuildWithProcessBasedServerResponse::RequiredBufferSize(const PFMultiplayerServerCreateBuildWithProcessBasedServerResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.areAssetsReadonly)
    {
        requiredSize += (alignof(bool) + sizeof(bool));
    }
    if (model.buildId)
    {
        requiredSize += (std::strlen(model.buildId) + 1);
    }
    if (model.buildName)
    {
        requiredSize += (std::strlen(model.buildName) + 1);
    }
    if (model.containerFlavor)
    {
        requiredSize += (alignof(PFMultiplayerServerContainerFlavor) + sizeof(PFMultiplayerServerContainerFlavor));
    }
    if (model.creationTime)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    requiredSize += (alignof(PFMultiplayerServerAssetReference*) + sizeof(PFMultiplayerServerAssetReference*) * model.gameAssetReferencesCount);
    for (size_t i = 0; i < model.gameAssetReferencesCount; ++i)
    {
        requiredSize += AssetReference::RequiredBufferSize(*model.gameAssetReferences[i]);
    }
    requiredSize += (alignof(PFMultiplayerServerGameCertificateReference*) + sizeof(PFMultiplayerServerGameCertificateReference*) * model.gameCertificateReferencesCount);
    for (size_t i = 0; i < model.gameCertificateReferencesCount; ++i)
    {
        requiredSize += GameCertificateReference::RequiredBufferSize(*model.gameCertificateReferences[i]);
    }
    if (model.gameWorkingDirectory)
    {
        requiredSize += (std::strlen(model.gameWorkingDirectory) + 1);
    }
    if (model.instrumentationConfiguration)
    {
        requiredSize += InstrumentationConfiguration::RequiredBufferSize(*model.instrumentationConfiguration);
    }
    if (model.isOSPreview)
    {
        requiredSize += (alignof(bool) + sizeof(bool));
    }
    requiredSize += (alignof(PFStringDictionaryEntry) + sizeof(PFStringDictionaryEntry) * model.metadataCount);
    for (size_t i = 0; i < model.metadataCount; ++i)
    {
        requiredSize += (std::strlen(model.metadata[i].key) + 1);
        requiredSize += (std::strlen(model.metadata[i].value) + 1);
    }
    if (model.osPlatform)
    {
        requiredSize += (std::strlen(model.osPlatform) + 1);
    }
    requiredSize += (alignof(PFPort*) + sizeof(PFPort*) * model.portsCount);
    for (size_t i = 0; i < model.portsCount; ++i)
    {
        requiredSize += Port::RequiredBufferSize(*model.ports[i]);
    }
    requiredSize += (alignof(PFMultiplayerServerBuildRegion*) + sizeof(PFMultiplayerServerBuildRegion*) * model.regionConfigurationsCount);
    for (size_t i = 0; i < model.regionConfigurationsCount; ++i)
    {
        requiredSize += BuildRegion::RequiredBufferSize(*model.regionConfigurations[i]);
    }
    if (model.serverType)
    {
        requiredSize += (std::strlen(model.serverType) + 1);
    }
    if (model.startMultiplayerServerCommand)
    {
        requiredSize += (std::strlen(model.startMultiplayerServerCommand) + 1);
    }
    if (model.useStreamingForAssetDownloads)
    {
        requiredSize += (alignof(bool) + sizeof(bool));
    }
    if (model.vmSize)
    {
        requiredSize += (alignof(PFMultiplayerServerAzureVmSize) + sizeof(PFMultiplayerServerAzureVmSize));
    }
    return requiredSize;
}

HRESULT CreateBuildWithProcessBasedServerResponse::Copy(const PFMultiplayerServerCreateBuildWithProcessBasedServerResponse& input, PFMultiplayerServerCreateBuildWithProcessBasedServerResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.areAssetsReadonly); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.areAssetsReadonly = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.buildId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.buildName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.containerFlavor); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.containerFlavor = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.creationTime); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.creationTime = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<AssetReference>(input.gameAssetReferences, input.gameAssetReferencesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.gameAssetReferences = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<GameCertificateReference>(input.gameCertificateReferences, input.gameCertificateReferencesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.gameCertificateReferences = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.gameWorkingDirectory); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.gameWorkingDirectory = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<InstrumentationConfiguration>(input.instrumentationConfiguration); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.instrumentationConfiguration = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.isOSPreview); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.isOSPreview = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.metadata, input.metadataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.metadata = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.osPlatform); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.osPlatform = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<Port>(input.ports, input.portsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.ports = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<BuildRegion>(input.regionConfigurations, input.regionConfigurationsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.regionConfigurations = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverType); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverType = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.startMultiplayerServerCommand); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.startMultiplayerServerCommand = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.useStreamingForAssetDownloads); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.useStreamingForAssetDownloads = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.vmSize); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.vmSize = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CreateRemoteUserRequest::ToJson() const
{
    return CreateRemoteUserRequest::ToJson(this->Model());
}

JsonValue CreateRemoteUserRequest::ToJson(const PFMultiplayerServerCreateRemoteUserRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberTime(output, "ExpirationTime", input.expirationTime);
    JsonUtils::ObjectAddMember(output, "Region", input.region);
    JsonUtils::ObjectAddMember(output, "Username", input.username);
    JsonUtils::ObjectAddMember(output, "VmId", input.vmId);
    return output;
}

void CreateRemoteUserResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<time_t> expirationTime{};
    JsonUtils::ObjectGetMemberTime(input, "ExpirationTime", expirationTime);
    this->SetExpirationTime(std::move(expirationTime));

    String password{};
    JsonUtils::ObjectGetMember(input, "Password", password);
    this->SetPassword(std::move(password));

    String username{};
    JsonUtils::ObjectGetMember(input, "Username", username);
    this->SetUsername(std::move(username));
}

size_t CreateRemoteUserResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerCreateRemoteUserResponse const*> CreateRemoteUserResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreateRemoteUserResponse>(&this->Model());
}

size_t CreateRemoteUserResponse::RequiredBufferSize(const PFMultiplayerServerCreateRemoteUserResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.expirationTime)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.password)
    {
        requiredSize += (std::strlen(model.password) + 1);
    }
    if (model.username)
    {
        requiredSize += (std::strlen(model.username) + 1);
    }
    return requiredSize;
}

HRESULT CreateRemoteUserResponse::Copy(const PFMultiplayerServerCreateRemoteUserResponse& input, PFMultiplayerServerCreateRemoteUserResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.expirationTime); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.expirationTime = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.password); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.password = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.username); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.username = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CoreCapacityChange::ToJson() const
{
    return CoreCapacityChange::ToJson(this->Model());
}

JsonValue CoreCapacityChange::ToJson(const PFMultiplayerServerCoreCapacityChange& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "NewCoreLimit", input.newCoreLimit);
    JsonUtils::ObjectAddMember(output, "Region", input.region);
    JsonUtils::ObjectAddMember(output, "VmFamily", input.vmFamily);
    return output;
}

void CoreCapacityChange::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "NewCoreLimit", this->m_model.newCoreLimit);

    String region{};
    JsonUtils::ObjectGetMember(input, "Region", region);
    this->SetRegion(std::move(region));

    JsonUtils::ObjectGetMember(input, "VmFamily", this->m_model.vmFamily);
}

size_t CoreCapacityChange::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerCoreCapacityChange const*> CoreCapacityChange::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CoreCapacityChange>(&this->Model());
}

size_t CoreCapacityChange::RequiredBufferSize(const PFMultiplayerServerCoreCapacityChange& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.region)
    {
        requiredSize += (std::strlen(model.region) + 1);
    }
    return requiredSize;
}

HRESULT CoreCapacityChange::Copy(const PFMultiplayerServerCoreCapacityChange& input, PFMultiplayerServerCoreCapacityChange& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.region); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.region = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CreateTitleMultiplayerServersQuotaChangeRequest::ToJson() const
{
    return CreateTitleMultiplayerServersQuotaChangeRequest::ToJson(this->Model());
}

JsonValue CreateTitleMultiplayerServersQuotaChangeRequest::ToJson(const PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ChangeDescription", input.changeDescription);
    JsonUtils::ObjectAddMemberArray<CoreCapacityChange>(output, "Changes", input.changes, input.changesCount);
    JsonUtils::ObjectAddMember(output, "ContactEmail", input.contactEmail);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Notes", input.notes);
    JsonUtils::ObjectAddMemberTime(output, "StartDate", input.startDate);
    return output;
}

void CreateTitleMultiplayerServersQuotaChangeResponse::FromJson(const JsonValue& input)
{
    String requestId{};
    JsonUtils::ObjectGetMember(input, "RequestId", requestId);
    this->SetRequestId(std::move(requestId));

    JsonUtils::ObjectGetMember(input, "WasApproved", this->m_model.wasApproved);
}

size_t CreateTitleMultiplayerServersQuotaChangeResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse const*> CreateTitleMultiplayerServersQuotaChangeResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreateTitleMultiplayerServersQuotaChangeResponse>(&this->Model());
}

size_t CreateTitleMultiplayerServersQuotaChangeResponse::RequiredBufferSize(const PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.requestId)
    {
        requiredSize += (std::strlen(model.requestId) + 1);
    }
    return requiredSize;
}

HRESULT CreateTitleMultiplayerServersQuotaChangeResponse::Copy(const PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse& input, PFMultiplayerServerCreateTitleMultiplayerServersQuotaChangeResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.requestId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.requestId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue DeleteAssetRequest::ToJson() const
{
    return DeleteAssetRequest::ToJson(this->Model());
}

JsonValue DeleteAssetRequest::ToJson(const PFMultiplayerServerDeleteAssetRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "FileName", input.fileName);
    return output;
}

JsonValue DeleteBuildRequest::ToJson() const
{
    return DeleteBuildRequest::ToJson(this->Model());
}

JsonValue DeleteBuildRequest::ToJson(const PFMultiplayerServerDeleteBuildRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue DeleteBuildAliasRequest::ToJson() const
{
    return DeleteBuildAliasRequest::ToJson(this->Model());
}

JsonValue DeleteBuildAliasRequest::ToJson(const PFMultiplayerServerDeleteBuildAliasRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AliasId", input.aliasId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue DeleteBuildRegionRequest::ToJson() const
{
    return DeleteBuildRegionRequest::ToJson(this->Model());
}

JsonValue DeleteBuildRegionRequest::ToJson(const PFMultiplayerServerDeleteBuildRegionRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Region", input.region);
    return output;
}

JsonValue DeleteCertificateRequest::ToJson() const
{
    return DeleteCertificateRequest::ToJson(this->Model());
}

JsonValue DeleteCertificateRequest::ToJson(const PFMultiplayerServerDeleteCertificateRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    return output;
}

JsonValue DeleteContainerImageRequest::ToJson() const
{
    return DeleteContainerImageRequest::ToJson(this->Model());
}

JsonValue DeleteContainerImageRequest::ToJson(const PFMultiplayerServerDeleteContainerImageRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ImageName", input.imageName);
    return output;
}

JsonValue DeleteRemoteUserRequest::ToJson() const
{
    return DeleteRemoteUserRequest::ToJson(this->Model());
}

JsonValue DeleteRemoteUserRequest::ToJson(const PFMultiplayerServerDeleteRemoteUserRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Region", input.region);
    JsonUtils::ObjectAddMember(output, "Username", input.username);
    JsonUtils::ObjectAddMember(output, "VmId", input.vmId);
    return output;
}

JsonValue EnableMultiplayerServersForTitleRequest::ToJson() const
{
    return EnableMultiplayerServersForTitleRequest::ToJson(this->Model());
}

JsonValue EnableMultiplayerServersForTitleRequest::ToJson(const PFMultiplayerServerEnableMultiplayerServersForTitleRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

void EnableMultiplayerServersForTitleResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFMultiplayerServerTitleMultiplayerServerEnabledStatus> status{};
    JsonUtils::ObjectGetMember(input, "Status", status);
    this->SetStatus(std::move(status));
}

size_t EnableMultiplayerServersForTitleResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerEnableMultiplayerServersForTitleResponse const*> EnableMultiplayerServersForTitleResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<EnableMultiplayerServersForTitleResponse>(&this->Model());
}

size_t EnableMultiplayerServersForTitleResponse::RequiredBufferSize(const PFMultiplayerServerEnableMultiplayerServersForTitleResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.status)
    {
        requiredSize += (alignof(PFMultiplayerServerTitleMultiplayerServerEnabledStatus) + sizeof(PFMultiplayerServerTitleMultiplayerServerEnabledStatus));
    }
    return requiredSize;
}

HRESULT EnableMultiplayerServersForTitleResponse::Copy(const PFMultiplayerServerEnableMultiplayerServersForTitleResponse& input, PFMultiplayerServerEnableMultiplayerServersForTitleResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.status); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.status = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetAssetDownloadUrlRequest::ToJson() const
{
    return GetAssetDownloadUrlRequest::ToJson(this->Model());
}

JsonValue GetAssetDownloadUrlRequest::ToJson(const PFMultiplayerServerGetAssetDownloadUrlRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "FileName", input.fileName);
    return output;
}

void GetAssetDownloadUrlResponse::FromJson(const JsonValue& input)
{
    String assetDownloadUrl{};
    JsonUtils::ObjectGetMember(input, "AssetDownloadUrl", assetDownloadUrl);
    this->SetAssetDownloadUrl(std::move(assetDownloadUrl));

    String fileName{};
    JsonUtils::ObjectGetMember(input, "FileName", fileName);
    this->SetFileName(std::move(fileName));
}

size_t GetAssetDownloadUrlResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerGetAssetDownloadUrlResponse const*> GetAssetDownloadUrlResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetAssetDownloadUrlResponse>(&this->Model());
}

size_t GetAssetDownloadUrlResponse::RequiredBufferSize(const PFMultiplayerServerGetAssetDownloadUrlResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.assetDownloadUrl)
    {
        requiredSize += (std::strlen(model.assetDownloadUrl) + 1);
    }
    if (model.fileName)
    {
        requiredSize += (std::strlen(model.fileName) + 1);
    }
    return requiredSize;
}

HRESULT GetAssetDownloadUrlResponse::Copy(const PFMultiplayerServerGetAssetDownloadUrlResponse& input, PFMultiplayerServerGetAssetDownloadUrlResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.assetDownloadUrl); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.assetDownloadUrl = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.fileName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.fileName = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetAssetUploadUrlRequest::ToJson() const
{
    return GetAssetUploadUrlRequest::ToJson(this->Model());
}

JsonValue GetAssetUploadUrlRequest::ToJson(const PFMultiplayerServerGetAssetUploadUrlRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "FileName", input.fileName);
    return output;
}

void GetAssetUploadUrlResponse::FromJson(const JsonValue& input)
{
    String assetUploadUrl{};
    JsonUtils::ObjectGetMember(input, "AssetUploadUrl", assetUploadUrl);
    this->SetAssetUploadUrl(std::move(assetUploadUrl));

    String fileName{};
    JsonUtils::ObjectGetMember(input, "FileName", fileName);
    this->SetFileName(std::move(fileName));
}

size_t GetAssetUploadUrlResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerGetAssetUploadUrlResponse const*> GetAssetUploadUrlResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetAssetUploadUrlResponse>(&this->Model());
}

size_t GetAssetUploadUrlResponse::RequiredBufferSize(const PFMultiplayerServerGetAssetUploadUrlResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.assetUploadUrl)
    {
        requiredSize += (std::strlen(model.assetUploadUrl) + 1);
    }
    if (model.fileName)
    {
        requiredSize += (std::strlen(model.fileName) + 1);
    }
    return requiredSize;
}

HRESULT GetAssetUploadUrlResponse::Copy(const PFMultiplayerServerGetAssetUploadUrlResponse& input, PFMultiplayerServerGetAssetUploadUrlResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.assetUploadUrl); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.assetUploadUrl = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.fileName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.fileName = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetBuildRequest::ToJson() const
{
    return GetBuildRequest::ToJson(this->Model());
}

JsonValue GetBuildRequest::ToJson(const PFMultiplayerServerGetBuildRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

void GetBuildResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<bool> areAssetsReadonly{};
    JsonUtils::ObjectGetMember(input, "AreAssetsReadonly", areAssetsReadonly);
    this->SetAreAssetsReadonly(std::move(areAssetsReadonly));

    String buildId{};
    JsonUtils::ObjectGetMember(input, "BuildId", buildId);
    this->SetBuildId(std::move(buildId));

    String buildName{};
    JsonUtils::ObjectGetMember(input, "BuildName", buildName);
    this->SetBuildName(std::move(buildName));

    String buildStatus{};
    JsonUtils::ObjectGetMember(input, "BuildStatus", buildStatus);
    this->SetBuildStatus(std::move(buildStatus));

    StdExtra::optional<PFMultiplayerServerContainerFlavor> containerFlavor{};
    JsonUtils::ObjectGetMember(input, "ContainerFlavor", containerFlavor);
    this->SetContainerFlavor(std::move(containerFlavor));

    String containerRunCommand{};
    JsonUtils::ObjectGetMember(input, "ContainerRunCommand", containerRunCommand);
    this->SetContainerRunCommand(std::move(containerRunCommand));

    StdExtra::optional<time_t> creationTime{};
    JsonUtils::ObjectGetMemberTime(input, "CreationTime", creationTime);
    this->SetCreationTime(std::move(creationTime));

    StdExtra::optional<ContainerImageReference> customGameContainerImage{};
    JsonUtils::ObjectGetMember(input, "CustomGameContainerImage", customGameContainerImage);
    if (customGameContainerImage)
    {
        this->SetCustomGameContainerImage(std::move(*customGameContainerImage));
    }

    ModelVector<AssetReference> gameAssetReferences{};
    JsonUtils::ObjectGetMember<AssetReference>(input, "GameAssetReferences", gameAssetReferences);
    this->SetGameAssetReferences(std::move(gameAssetReferences));

    ModelVector<GameCertificateReference> gameCertificateReferences{};
    JsonUtils::ObjectGetMember<GameCertificateReference>(input, "GameCertificateReferences", gameCertificateReferences);
    this->SetGameCertificateReferences(std::move(gameCertificateReferences));

    StdExtra::optional<InstrumentationConfiguration> instrumentationConfiguration{};
    JsonUtils::ObjectGetMember(input, "InstrumentationConfiguration", instrumentationConfiguration);
    if (instrumentationConfiguration)
    {
        this->SetInstrumentationConfiguration(std::move(*instrumentationConfiguration));
    }

    StringDictionaryEntryVector metadata{};
    JsonUtils::ObjectGetMember(input, "Metadata", metadata);
    this->SetMetadata(std::move(metadata));

    JsonUtils::ObjectGetMember(input, "MultiplayerServerCountPerVm", this->m_model.multiplayerServerCountPerVm);

    String osPlatform{};
    JsonUtils::ObjectGetMember(input, "OsPlatform", osPlatform);
    this->SetOsPlatform(std::move(osPlatform));

    ModelVector<Port> ports{};
    JsonUtils::ObjectGetMember<Port>(input, "Ports", ports);
    this->SetPorts(std::move(ports));

    ModelVector<BuildRegion> regionConfigurations{};
    JsonUtils::ObjectGetMember<BuildRegion>(input, "RegionConfigurations", regionConfigurations);
    this->SetRegionConfigurations(std::move(regionConfigurations));

    String serverType{};
    JsonUtils::ObjectGetMember(input, "ServerType", serverType);
    this->SetServerType(std::move(serverType));

    String startMultiplayerServerCommand{};
    JsonUtils::ObjectGetMember(input, "StartMultiplayerServerCommand", startMultiplayerServerCommand);
    this->SetStartMultiplayerServerCommand(std::move(startMultiplayerServerCommand));

    StdExtra::optional<bool> useStreamingForAssetDownloads{};
    JsonUtils::ObjectGetMember(input, "UseStreamingForAssetDownloads", useStreamingForAssetDownloads);
    this->SetUseStreamingForAssetDownloads(std::move(useStreamingForAssetDownloads));

    StdExtra::optional<PFMultiplayerServerAzureVmSize> vmSize{};
    JsonUtils::ObjectGetMember(input, "VmSize", vmSize);
    this->SetVmSize(std::move(vmSize));
}

size_t GetBuildResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerGetBuildResponse const*> GetBuildResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetBuildResponse>(&this->Model());
}

size_t GetBuildResponse::RequiredBufferSize(const PFMultiplayerServerGetBuildResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.areAssetsReadonly)
    {
        requiredSize += (alignof(bool) + sizeof(bool));
    }
    if (model.buildId)
    {
        requiredSize += (std::strlen(model.buildId) + 1);
    }
    if (model.buildName)
    {
        requiredSize += (std::strlen(model.buildName) + 1);
    }
    if (model.buildStatus)
    {
        requiredSize += (std::strlen(model.buildStatus) + 1);
    }
    if (model.containerFlavor)
    {
        requiredSize += (alignof(PFMultiplayerServerContainerFlavor) + sizeof(PFMultiplayerServerContainerFlavor));
    }
    if (model.containerRunCommand)
    {
        requiredSize += (std::strlen(model.containerRunCommand) + 1);
    }
    if (model.creationTime)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.customGameContainerImage)
    {
        requiredSize += ContainerImageReference::RequiredBufferSize(*model.customGameContainerImage);
    }
    requiredSize += (alignof(PFMultiplayerServerAssetReference*) + sizeof(PFMultiplayerServerAssetReference*) * model.gameAssetReferencesCount);
    for (size_t i = 0; i < model.gameAssetReferencesCount; ++i)
    {
        requiredSize += AssetReference::RequiredBufferSize(*model.gameAssetReferences[i]);
    }
    requiredSize += (alignof(PFMultiplayerServerGameCertificateReference*) + sizeof(PFMultiplayerServerGameCertificateReference*) * model.gameCertificateReferencesCount);
    for (size_t i = 0; i < model.gameCertificateReferencesCount; ++i)
    {
        requiredSize += GameCertificateReference::RequiredBufferSize(*model.gameCertificateReferences[i]);
    }
    if (model.instrumentationConfiguration)
    {
        requiredSize += InstrumentationConfiguration::RequiredBufferSize(*model.instrumentationConfiguration);
    }
    requiredSize += (alignof(PFStringDictionaryEntry) + sizeof(PFStringDictionaryEntry) * model.metadataCount);
    for (size_t i = 0; i < model.metadataCount; ++i)
    {
        requiredSize += (std::strlen(model.metadata[i].key) + 1);
        requiredSize += (std::strlen(model.metadata[i].value) + 1);
    }
    if (model.osPlatform)
    {
        requiredSize += (std::strlen(model.osPlatform) + 1);
    }
    requiredSize += (alignof(PFPort*) + sizeof(PFPort*) * model.portsCount);
    for (size_t i = 0; i < model.portsCount; ++i)
    {
        requiredSize += Port::RequiredBufferSize(*model.ports[i]);
    }
    requiredSize += (alignof(PFMultiplayerServerBuildRegion*) + sizeof(PFMultiplayerServerBuildRegion*) * model.regionConfigurationsCount);
    for (size_t i = 0; i < model.regionConfigurationsCount; ++i)
    {
        requiredSize += BuildRegion::RequiredBufferSize(*model.regionConfigurations[i]);
    }
    if (model.serverType)
    {
        requiredSize += (std::strlen(model.serverType) + 1);
    }
    if (model.startMultiplayerServerCommand)
    {
        requiredSize += (std::strlen(model.startMultiplayerServerCommand) + 1);
    }
    if (model.useStreamingForAssetDownloads)
    {
        requiredSize += (alignof(bool) + sizeof(bool));
    }
    if (model.vmSize)
    {
        requiredSize += (alignof(PFMultiplayerServerAzureVmSize) + sizeof(PFMultiplayerServerAzureVmSize));
    }
    return requiredSize;
}

HRESULT GetBuildResponse::Copy(const PFMultiplayerServerGetBuildResponse& input, PFMultiplayerServerGetBuildResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.areAssetsReadonly); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.areAssetsReadonly = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.buildId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.buildName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.buildStatus); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildStatus = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.containerFlavor); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.containerFlavor = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.containerRunCommand); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.containerRunCommand = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.creationTime); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.creationTime = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<ContainerImageReference>(input.customGameContainerImage); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.customGameContainerImage = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<AssetReference>(input.gameAssetReferences, input.gameAssetReferencesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.gameAssetReferences = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<GameCertificateReference>(input.gameCertificateReferences, input.gameCertificateReferencesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.gameCertificateReferences = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<InstrumentationConfiguration>(input.instrumentationConfiguration); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.instrumentationConfiguration = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.metadata, input.metadataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.metadata = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.osPlatform); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.osPlatform = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<Port>(input.ports, input.portsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.ports = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<BuildRegion>(input.regionConfigurations, input.regionConfigurationsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.regionConfigurations = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverType); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverType = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.startMultiplayerServerCommand); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.startMultiplayerServerCommand = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.useStreamingForAssetDownloads); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.useStreamingForAssetDownloads = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.vmSize); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.vmSize = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetBuildAliasRequest::ToJson() const
{
    return GetBuildAliasRequest::ToJson(this->Model());
}

JsonValue GetBuildAliasRequest::ToJson(const PFMultiplayerServerGetBuildAliasRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AliasId", input.aliasId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue GetContainerRegistryCredentialsRequest::ToJson() const
{
    return GetContainerRegistryCredentialsRequest::ToJson(this->Model());
}

JsonValue GetContainerRegistryCredentialsRequest::ToJson(const PFMultiplayerServerGetContainerRegistryCredentialsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

void GetContainerRegistryCredentialsResponse::FromJson(const JsonValue& input)
{
    String dnsName{};
    JsonUtils::ObjectGetMember(input, "DnsName", dnsName);
    this->SetDnsName(std::move(dnsName));

    String password{};
    JsonUtils::ObjectGetMember(input, "Password", password);
    this->SetPassword(std::move(password));

    String username{};
    JsonUtils::ObjectGetMember(input, "Username", username);
    this->SetUsername(std::move(username));
}

size_t GetContainerRegistryCredentialsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerGetContainerRegistryCredentialsResponse const*> GetContainerRegistryCredentialsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetContainerRegistryCredentialsResponse>(&this->Model());
}

size_t GetContainerRegistryCredentialsResponse::RequiredBufferSize(const PFMultiplayerServerGetContainerRegistryCredentialsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.dnsName)
    {
        requiredSize += (std::strlen(model.dnsName) + 1);
    }
    if (model.password)
    {
        requiredSize += (std::strlen(model.password) + 1);
    }
    if (model.username)
    {
        requiredSize += (std::strlen(model.username) + 1);
    }
    return requiredSize;
}

HRESULT GetContainerRegistryCredentialsResponse::Copy(const PFMultiplayerServerGetContainerRegistryCredentialsResponse& input, PFMultiplayerServerGetContainerRegistryCredentialsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.dnsName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.dnsName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.password); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.password = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.username); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.username = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetMultiplayerServerDetailsRequest::ToJson() const
{
    return GetMultiplayerServerDetailsRequest::ToJson(this->Model());
}

JsonValue GetMultiplayerServerDetailsRequest::ToJson(const PFMultiplayerServerGetMultiplayerServerDetailsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Region", input.region);
    JsonUtils::ObjectAddMember(output, "SessionId", input.sessionId);
    return output;
}

void ConnectedPlayer::FromJson(const JsonValue& input)
{
    String playerId{};
    JsonUtils::ObjectGetMember(input, "PlayerId", playerId);
    this->SetPlayerId(std::move(playerId));
}

size_t ConnectedPlayer::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerConnectedPlayer const*> ConnectedPlayer::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ConnectedPlayer>(&this->Model());
}

size_t ConnectedPlayer::RequiredBufferSize(const PFMultiplayerServerConnectedPlayer& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.playerId)
    {
        requiredSize += (std::strlen(model.playerId) + 1);
    }
    return requiredSize;
}

HRESULT ConnectedPlayer::Copy(const PFMultiplayerServerConnectedPlayer& input, PFMultiplayerServerConnectedPlayer& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.playerId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playerId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetMultiplayerServerDetailsResponse::FromJson(const JsonValue& input)
{
    String buildId{};
    JsonUtils::ObjectGetMember(input, "BuildId", buildId);
    this->SetBuildId(std::move(buildId));

    ModelVector<ConnectedPlayer> connectedPlayers{};
    JsonUtils::ObjectGetMember<ConnectedPlayer>(input, "ConnectedPlayers", connectedPlayers);
    this->SetConnectedPlayers(std::move(connectedPlayers));

    String fQDN{};
    JsonUtils::ObjectGetMember(input, "FQDN", fQDN);
    this->SetFQDN(std::move(fQDN));

    String iPV4Address{};
    JsonUtils::ObjectGetMember(input, "IPV4Address", iPV4Address);
    this->SetIPV4Address(std::move(iPV4Address));

    StdExtra::optional<time_t> lastStateTransitionTime{};
    JsonUtils::ObjectGetMemberTime(input, "LastStateTransitionTime", lastStateTransitionTime);
    this->SetLastStateTransitionTime(std::move(lastStateTransitionTime));

    ModelVector<Port> ports{};
    JsonUtils::ObjectGetMember<Port>(input, "Ports", ports);
    this->SetPorts(std::move(ports));

    String region{};
    JsonUtils::ObjectGetMember(input, "Region", region);
    this->SetRegion(std::move(region));

    String serverId{};
    JsonUtils::ObjectGetMember(input, "ServerId", serverId);
    this->SetServerId(std::move(serverId));

    String sessionId{};
    JsonUtils::ObjectGetMember(input, "SessionId", sessionId);
    this->SetSessionId(std::move(sessionId));

    String state{};
    JsonUtils::ObjectGetMember(input, "State", state);
    this->SetState(std::move(state));

    String vmId{};
    JsonUtils::ObjectGetMember(input, "VmId", vmId);
    this->SetVmId(std::move(vmId));
}

size_t GetMultiplayerServerDetailsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerGetMultiplayerServerDetailsResponse const*> GetMultiplayerServerDetailsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetMultiplayerServerDetailsResponse>(&this->Model());
}

size_t GetMultiplayerServerDetailsResponse::RequiredBufferSize(const PFMultiplayerServerGetMultiplayerServerDetailsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.buildId)
    {
        requiredSize += (std::strlen(model.buildId) + 1);
    }
    requiredSize += (alignof(PFMultiplayerServerConnectedPlayer*) + sizeof(PFMultiplayerServerConnectedPlayer*) * model.connectedPlayersCount);
    for (size_t i = 0; i < model.connectedPlayersCount; ++i)
    {
        requiredSize += ConnectedPlayer::RequiredBufferSize(*model.connectedPlayers[i]);
    }
    if (model.fQDN)
    {
        requiredSize += (std::strlen(model.fQDN) + 1);
    }
    if (model.iPV4Address)
    {
        requiredSize += (std::strlen(model.iPV4Address) + 1);
    }
    if (model.lastStateTransitionTime)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    requiredSize += (alignof(PFPort*) + sizeof(PFPort*) * model.portsCount);
    for (size_t i = 0; i < model.portsCount; ++i)
    {
        requiredSize += Port::RequiredBufferSize(*model.ports[i]);
    }
    if (model.region)
    {
        requiredSize += (std::strlen(model.region) + 1);
    }
    if (model.serverId)
    {
        requiredSize += (std::strlen(model.serverId) + 1);
    }
    if (model.sessionId)
    {
        requiredSize += (std::strlen(model.sessionId) + 1);
    }
    if (model.state)
    {
        requiredSize += (std::strlen(model.state) + 1);
    }
    if (model.vmId)
    {
        requiredSize += (std::strlen(model.vmId) + 1);
    }
    return requiredSize;
}

HRESULT GetMultiplayerServerDetailsResponse::Copy(const PFMultiplayerServerGetMultiplayerServerDetailsResponse& input, PFMultiplayerServerGetMultiplayerServerDetailsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.buildId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<ConnectedPlayer>(input.connectedPlayers, input.connectedPlayersCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.connectedPlayers = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.fQDN); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.fQDN = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.iPV4Address); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.iPV4Address = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.lastStateTransitionTime); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lastStateTransitionTime = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<Port>(input.ports, input.portsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.ports = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.region); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.region = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.sessionId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.sessionId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.state); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.state = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.vmId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.vmId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetMultiplayerServerLogsRequest::ToJson() const
{
    return GetMultiplayerServerLogsRequest::ToJson(this->Model());
}

JsonValue GetMultiplayerServerLogsRequest::ToJson(const PFMultiplayerServerGetMultiplayerServerLogsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ServerId", input.serverId);
    return output;
}

void GetMultiplayerServerLogsResponse::FromJson(const JsonValue& input)
{
    String logDownloadUrl{};
    JsonUtils::ObjectGetMember(input, "LogDownloadUrl", logDownloadUrl);
    this->SetLogDownloadUrl(std::move(logDownloadUrl));
}

size_t GetMultiplayerServerLogsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerGetMultiplayerServerLogsResponse const*> GetMultiplayerServerLogsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetMultiplayerServerLogsResponse>(&this->Model());
}

size_t GetMultiplayerServerLogsResponse::RequiredBufferSize(const PFMultiplayerServerGetMultiplayerServerLogsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.logDownloadUrl)
    {
        requiredSize += (std::strlen(model.logDownloadUrl) + 1);
    }
    return requiredSize;
}

HRESULT GetMultiplayerServerLogsResponse::Copy(const PFMultiplayerServerGetMultiplayerServerLogsResponse& input, PFMultiplayerServerGetMultiplayerServerLogsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.logDownloadUrl); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.logDownloadUrl = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetMultiplayerSessionLogsBySessionIdRequest::ToJson() const
{
    return GetMultiplayerSessionLogsBySessionIdRequest::ToJson(this->Model());
}

JsonValue GetMultiplayerSessionLogsBySessionIdRequest::ToJson(const PFMultiplayerServerGetMultiplayerSessionLogsBySessionIdRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "SessionId", input.sessionId);
    return output;
}

JsonValue GetRemoteLoginEndpointRequest::ToJson() const
{
    return GetRemoteLoginEndpointRequest::ToJson(this->Model());
}

JsonValue GetRemoteLoginEndpointRequest::ToJson(const PFMultiplayerServerGetRemoteLoginEndpointRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Region", input.region);
    JsonUtils::ObjectAddMember(output, "VmId", input.vmId);
    return output;
}

void GetRemoteLoginEndpointResponse::FromJson(const JsonValue& input)
{
    String iPV4Address{};
    JsonUtils::ObjectGetMember(input, "IPV4Address", iPV4Address);
    this->SetIPV4Address(std::move(iPV4Address));

    JsonUtils::ObjectGetMember(input, "Port", this->m_model.port);
}

size_t GetRemoteLoginEndpointResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerGetRemoteLoginEndpointResponse const*> GetRemoteLoginEndpointResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetRemoteLoginEndpointResponse>(&this->Model());
}

size_t GetRemoteLoginEndpointResponse::RequiredBufferSize(const PFMultiplayerServerGetRemoteLoginEndpointResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.iPV4Address)
    {
        requiredSize += (std::strlen(model.iPV4Address) + 1);
    }
    return requiredSize;
}

HRESULT GetRemoteLoginEndpointResponse::Copy(const PFMultiplayerServerGetRemoteLoginEndpointResponse& input, PFMultiplayerServerGetRemoteLoginEndpointResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.iPV4Address); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.iPV4Address = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetTitleEnabledForMultiplayerServersStatusRequest::ToJson() const
{
    return GetTitleEnabledForMultiplayerServersStatusRequest::ToJson(this->Model());
}

JsonValue GetTitleEnabledForMultiplayerServersStatusRequest::ToJson(const PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

void GetTitleEnabledForMultiplayerServersStatusResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFMultiplayerServerTitleMultiplayerServerEnabledStatus> status{};
    JsonUtils::ObjectGetMember(input, "Status", status);
    this->SetStatus(std::move(status));
}

size_t GetTitleEnabledForMultiplayerServersStatusResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse const*> GetTitleEnabledForMultiplayerServersStatusResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetTitleEnabledForMultiplayerServersStatusResponse>(&this->Model());
}

size_t GetTitleEnabledForMultiplayerServersStatusResponse::RequiredBufferSize(const PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.status)
    {
        requiredSize += (alignof(PFMultiplayerServerTitleMultiplayerServerEnabledStatus) + sizeof(PFMultiplayerServerTitleMultiplayerServerEnabledStatus));
    }
    return requiredSize;
}

HRESULT GetTitleEnabledForMultiplayerServersStatusResponse::Copy(const PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse& input, PFMultiplayerServerGetTitleEnabledForMultiplayerServersStatusResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.status); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.status = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetTitleMultiplayerServersQuotaChangeRequest::ToJson() const
{
    return GetTitleMultiplayerServersQuotaChangeRequest::ToJson(this->Model());
}

JsonValue GetTitleMultiplayerServersQuotaChangeRequest::ToJson(const PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "RequestId", input.requestId);
    return output;
}

void QuotaChange::FromJson(const JsonValue& input)
{
    String changeDescription{};
    JsonUtils::ObjectGetMember(input, "ChangeDescription", changeDescription);
    this->SetChangeDescription(std::move(changeDescription));

    ModelVector<CoreCapacityChange> changes{};
    JsonUtils::ObjectGetMember<CoreCapacityChange>(input, "Changes", changes);
    this->SetChanges(std::move(changes));

    JsonUtils::ObjectGetMember(input, "IsPendingReview", this->m_model.isPendingReview);

    String notes{};
    JsonUtils::ObjectGetMember(input, "Notes", notes);
    this->SetNotes(std::move(notes));

    String requestId{};
    JsonUtils::ObjectGetMember(input, "RequestId", requestId);
    this->SetRequestId(std::move(requestId));

    String reviewComments{};
    JsonUtils::ObjectGetMember(input, "ReviewComments", reviewComments);
    this->SetReviewComments(std::move(reviewComments));

    JsonUtils::ObjectGetMember(input, "WasApproved", this->m_model.wasApproved);
}

size_t QuotaChange::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerQuotaChange const*> QuotaChange::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<QuotaChange>(&this->Model());
}

size_t QuotaChange::RequiredBufferSize(const PFMultiplayerServerQuotaChange& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.changeDescription)
    {
        requiredSize += (std::strlen(model.changeDescription) + 1);
    }
    requiredSize += (alignof(PFMultiplayerServerCoreCapacityChange*) + sizeof(PFMultiplayerServerCoreCapacityChange*) * model.changesCount);
    for (size_t i = 0; i < model.changesCount; ++i)
    {
        requiredSize += CoreCapacityChange::RequiredBufferSize(*model.changes[i]);
    }
    if (model.notes)
    {
        requiredSize += (std::strlen(model.notes) + 1);
    }
    if (model.requestId)
    {
        requiredSize += (std::strlen(model.requestId) + 1);
    }
    if (model.reviewComments)
    {
        requiredSize += (std::strlen(model.reviewComments) + 1);
    }
    return requiredSize;
}

HRESULT QuotaChange::Copy(const PFMultiplayerServerQuotaChange& input, PFMultiplayerServerQuotaChange& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.changeDescription); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.changeDescription = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<CoreCapacityChange>(input.changes, input.changesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.changes = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.notes); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.notes = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.requestId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.requestId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.reviewComments); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.reviewComments = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetTitleMultiplayerServersQuotaChangeResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<QuotaChange> change{};
    JsonUtils::ObjectGetMember(input, "Change", change);
    if (change)
    {
        this->SetChange(std::move(*change));
    }
}

size_t GetTitleMultiplayerServersQuotaChangeResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse const*> GetTitleMultiplayerServersQuotaChangeResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetTitleMultiplayerServersQuotaChangeResponse>(&this->Model());
}

size_t GetTitleMultiplayerServersQuotaChangeResponse::RequiredBufferSize(const PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.change)
    {
        requiredSize += QuotaChange::RequiredBufferSize(*model.change);
    }
    return requiredSize;
}

HRESULT GetTitleMultiplayerServersQuotaChangeResponse::Copy(const PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse& input, PFMultiplayerServerGetTitleMultiplayerServersQuotaChangeResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<QuotaChange>(input.change); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.change = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetTitleMultiplayerServersQuotasRequest::ToJson() const
{
    return GetTitleMultiplayerServersQuotasRequest::ToJson(this->Model());
}

JsonValue GetTitleMultiplayerServersQuotasRequest::ToJson(const PFMultiplayerServerGetTitleMultiplayerServersQuotasRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

void CoreCapacity::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "Available", this->m_model.available);

    String region{};
    JsonUtils::ObjectGetMember(input, "Region", region);
    this->SetRegion(std::move(region));

    JsonUtils::ObjectGetMember(input, "Total", this->m_model.total);

    StdExtra::optional<PFMultiplayerServerAzureVmFamily> vmFamily{};
    JsonUtils::ObjectGetMember(input, "VmFamily", vmFamily);
    this->SetVmFamily(std::move(vmFamily));
}

size_t CoreCapacity::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerCoreCapacity const*> CoreCapacity::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CoreCapacity>(&this->Model());
}

size_t CoreCapacity::RequiredBufferSize(const PFMultiplayerServerCoreCapacity& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.region)
    {
        requiredSize += (std::strlen(model.region) + 1);
    }
    if (model.vmFamily)
    {
        requiredSize += (alignof(PFMultiplayerServerAzureVmFamily) + sizeof(PFMultiplayerServerAzureVmFamily));
    }
    return requiredSize;
}

HRESULT CoreCapacity::Copy(const PFMultiplayerServerCoreCapacity& input, PFMultiplayerServerCoreCapacity& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.region); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.region = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.vmFamily); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.vmFamily = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void TitleMultiplayerServersQuotas::FromJson(const JsonValue& input)
{
    ModelVector<CoreCapacity> coreCapacities{};
    JsonUtils::ObjectGetMember<CoreCapacity>(input, "CoreCapacities", coreCapacities);
    this->SetCoreCapacities(std::move(coreCapacities));
}

size_t TitleMultiplayerServersQuotas::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerTitleMultiplayerServersQuotas const*> TitleMultiplayerServersQuotas::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<TitleMultiplayerServersQuotas>(&this->Model());
}

size_t TitleMultiplayerServersQuotas::RequiredBufferSize(const PFMultiplayerServerTitleMultiplayerServersQuotas& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFMultiplayerServerCoreCapacity*) + sizeof(PFMultiplayerServerCoreCapacity*) * model.coreCapacitiesCount);
    for (size_t i = 0; i < model.coreCapacitiesCount; ++i)
    {
        requiredSize += CoreCapacity::RequiredBufferSize(*model.coreCapacities[i]);
    }
    return requiredSize;
}

HRESULT TitleMultiplayerServersQuotas::Copy(const PFMultiplayerServerTitleMultiplayerServersQuotas& input, PFMultiplayerServerTitleMultiplayerServersQuotas& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<CoreCapacity>(input.coreCapacities, input.coreCapacitiesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.coreCapacities = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetTitleMultiplayerServersQuotasResponse::FromJson(const JsonValue& input)
{
    StdExtra::optional<TitleMultiplayerServersQuotas> quotas{};
    JsonUtils::ObjectGetMember(input, "Quotas", quotas);
    if (quotas)
    {
        this->SetQuotas(std::move(*quotas));
    }
}

size_t GetTitleMultiplayerServersQuotasResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse const*> GetTitleMultiplayerServersQuotasResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetTitleMultiplayerServersQuotasResponse>(&this->Model());
}

size_t GetTitleMultiplayerServersQuotasResponse::RequiredBufferSize(const PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.quotas)
    {
        requiredSize += TitleMultiplayerServersQuotas::RequiredBufferSize(*model.quotas);
    }
    return requiredSize;
}

HRESULT GetTitleMultiplayerServersQuotasResponse::Copy(const PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse& input, PFMultiplayerServerGetTitleMultiplayerServersQuotasResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<TitleMultiplayerServersQuotas>(input.quotas); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.quotas = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ListMultiplayerServersRequest::ToJson() const
{
    return ListMultiplayerServersRequest::ToJson(this->Model());
}

JsonValue ListMultiplayerServersRequest::ToJson(const PFMultiplayerServerListMultiplayerServersRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PageSize", input.pageSize);
    JsonUtils::ObjectAddMember(output, "Region", input.region);
    JsonUtils::ObjectAddMember(output, "SkipToken", input.skipToken);
    return output;
}

void MultiplayerServerSummary::FromJson(const JsonValue& input)
{
    ModelVector<ConnectedPlayer> connectedPlayers{};
    JsonUtils::ObjectGetMember<ConnectedPlayer>(input, "ConnectedPlayers", connectedPlayers);
    this->SetConnectedPlayers(std::move(connectedPlayers));

    StdExtra::optional<time_t> lastStateTransitionTime{};
    JsonUtils::ObjectGetMemberTime(input, "LastStateTransitionTime", lastStateTransitionTime);
    this->SetLastStateTransitionTime(std::move(lastStateTransitionTime));

    String region{};
    JsonUtils::ObjectGetMember(input, "Region", region);
    this->SetRegion(std::move(region));

    String serverId{};
    JsonUtils::ObjectGetMember(input, "ServerId", serverId);
    this->SetServerId(std::move(serverId));

    String sessionId{};
    JsonUtils::ObjectGetMember(input, "SessionId", sessionId);
    this->SetSessionId(std::move(sessionId));

    String state{};
    JsonUtils::ObjectGetMember(input, "State", state);
    this->SetState(std::move(state));

    String vmId{};
    JsonUtils::ObjectGetMember(input, "VmId", vmId);
    this->SetVmId(std::move(vmId));
}

size_t MultiplayerServerSummary::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerMultiplayerServerSummary const*> MultiplayerServerSummary::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<MultiplayerServerSummary>(&this->Model());
}

size_t MultiplayerServerSummary::RequiredBufferSize(const PFMultiplayerServerMultiplayerServerSummary& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFMultiplayerServerConnectedPlayer*) + sizeof(PFMultiplayerServerConnectedPlayer*) * model.connectedPlayersCount);
    for (size_t i = 0; i < model.connectedPlayersCount; ++i)
    {
        requiredSize += ConnectedPlayer::RequiredBufferSize(*model.connectedPlayers[i]);
    }
    if (model.lastStateTransitionTime)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.region)
    {
        requiredSize += (std::strlen(model.region) + 1);
    }
    if (model.serverId)
    {
        requiredSize += (std::strlen(model.serverId) + 1);
    }
    if (model.sessionId)
    {
        requiredSize += (std::strlen(model.sessionId) + 1);
    }
    if (model.state)
    {
        requiredSize += (std::strlen(model.state) + 1);
    }
    if (model.vmId)
    {
        requiredSize += (std::strlen(model.vmId) + 1);
    }
    return requiredSize;
}

HRESULT MultiplayerServerSummary::Copy(const PFMultiplayerServerMultiplayerServerSummary& input, PFMultiplayerServerMultiplayerServerSummary& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ConnectedPlayer>(input.connectedPlayers, input.connectedPlayersCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.connectedPlayers = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.lastStateTransitionTime); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lastStateTransitionTime = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.region); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.region = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.sessionId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.sessionId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.state); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.state = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.vmId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.vmId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void ListMultiplayerServersResponse::FromJson(const JsonValue& input)
{
    ModelVector<MultiplayerServerSummary> multiplayerServerSummaries{};
    JsonUtils::ObjectGetMember<MultiplayerServerSummary>(input, "MultiplayerServerSummaries", multiplayerServerSummaries);
    this->SetMultiplayerServerSummaries(std::move(multiplayerServerSummaries));

    JsonUtils::ObjectGetMember(input, "PageSize", this->m_model.pageSize);

    String skipToken{};
    JsonUtils::ObjectGetMember(input, "SkipToken", skipToken);
    this->SetSkipToken(std::move(skipToken));
}

size_t ListMultiplayerServersResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerListMultiplayerServersResponse const*> ListMultiplayerServersResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ListMultiplayerServersResponse>(&this->Model());
}

size_t ListMultiplayerServersResponse::RequiredBufferSize(const PFMultiplayerServerListMultiplayerServersResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFMultiplayerServerMultiplayerServerSummary*) + sizeof(PFMultiplayerServerMultiplayerServerSummary*) * model.multiplayerServerSummariesCount);
    for (size_t i = 0; i < model.multiplayerServerSummariesCount; ++i)
    {
        requiredSize += MultiplayerServerSummary::RequiredBufferSize(*model.multiplayerServerSummaries[i]);
    }
    if (model.skipToken)
    {
        requiredSize += (std::strlen(model.skipToken) + 1);
    }
    return requiredSize;
}

HRESULT ListMultiplayerServersResponse::Copy(const PFMultiplayerServerListMultiplayerServersResponse& input, PFMultiplayerServerListMultiplayerServersResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<MultiplayerServerSummary>(input.multiplayerServerSummaries, input.multiplayerServerSummariesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.multiplayerServerSummaries = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.skipToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.skipToken = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ListAssetSummariesRequest::ToJson() const
{
    return ListAssetSummariesRequest::ToJson(this->Model());
}

JsonValue ListAssetSummariesRequest::ToJson(const PFMultiplayerServerListAssetSummariesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PageSize", input.pageSize);
    JsonUtils::ObjectAddMember(output, "SkipToken", input.skipToken);
    return output;
}

void AssetSummary::FromJson(const JsonValue& input)
{
    String fileName{};
    JsonUtils::ObjectGetMember(input, "FileName", fileName);
    this->SetFileName(std::move(fileName));

    StringDictionaryEntryVector metadata{};
    JsonUtils::ObjectGetMember(input, "Metadata", metadata);
    this->SetMetadata(std::move(metadata));
}

size_t AssetSummary::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerAssetSummary const*> AssetSummary::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AssetSummary>(&this->Model());
}

size_t AssetSummary::RequiredBufferSize(const PFMultiplayerServerAssetSummary& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.fileName)
    {
        requiredSize += (std::strlen(model.fileName) + 1);
    }
    requiredSize += (alignof(PFStringDictionaryEntry) + sizeof(PFStringDictionaryEntry) * model.metadataCount);
    for (size_t i = 0; i < model.metadataCount; ++i)
    {
        requiredSize += (std::strlen(model.metadata[i].key) + 1);
        requiredSize += (std::strlen(model.metadata[i].value) + 1);
    }
    return requiredSize;
}

HRESULT AssetSummary::Copy(const PFMultiplayerServerAssetSummary& input, PFMultiplayerServerAssetSummary& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.fileName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.fileName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.metadata, input.metadataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.metadata = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void ListAssetSummariesResponse::FromJson(const JsonValue& input)
{
    ModelVector<AssetSummary> assetSummaries{};
    JsonUtils::ObjectGetMember<AssetSummary>(input, "AssetSummaries", assetSummaries);
    this->SetAssetSummaries(std::move(assetSummaries));

    JsonUtils::ObjectGetMember(input, "PageSize", this->m_model.pageSize);

    String skipToken{};
    JsonUtils::ObjectGetMember(input, "SkipToken", skipToken);
    this->SetSkipToken(std::move(skipToken));
}

size_t ListAssetSummariesResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerListAssetSummariesResponse const*> ListAssetSummariesResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ListAssetSummariesResponse>(&this->Model());
}

size_t ListAssetSummariesResponse::RequiredBufferSize(const PFMultiplayerServerListAssetSummariesResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFMultiplayerServerAssetSummary*) + sizeof(PFMultiplayerServerAssetSummary*) * model.assetSummariesCount);
    for (size_t i = 0; i < model.assetSummariesCount; ++i)
    {
        requiredSize += AssetSummary::RequiredBufferSize(*model.assetSummaries[i]);
    }
    if (model.skipToken)
    {
        requiredSize += (std::strlen(model.skipToken) + 1);
    }
    return requiredSize;
}

HRESULT ListAssetSummariesResponse::Copy(const PFMultiplayerServerListAssetSummariesResponse& input, PFMultiplayerServerListAssetSummariesResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<AssetSummary>(input.assetSummaries, input.assetSummariesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.assetSummaries = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.skipToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.skipToken = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ListBuildAliasesRequest::ToJson() const
{
    return ListBuildAliasesRequest::ToJson(this->Model());
}

JsonValue ListBuildAliasesRequest::ToJson(const PFMultiplayerServerListBuildAliasesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PageSize", input.pageSize);
    JsonUtils::ObjectAddMember(output, "SkipToken", input.skipToken);
    return output;
}

void ListBuildAliasesResponse::FromJson(const JsonValue& input)
{
    ModelVector<BuildAliasDetailsResponse> buildAliases{};
    JsonUtils::ObjectGetMember<BuildAliasDetailsResponse>(input, "BuildAliases", buildAliases);
    this->SetBuildAliases(std::move(buildAliases));

    JsonUtils::ObjectGetMember(input, "PageSize", this->m_model.pageSize);

    String skipToken{};
    JsonUtils::ObjectGetMember(input, "SkipToken", skipToken);
    this->SetSkipToken(std::move(skipToken));
}

size_t ListBuildAliasesResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerListBuildAliasesResponse const*> ListBuildAliasesResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ListBuildAliasesResponse>(&this->Model());
}

size_t ListBuildAliasesResponse::RequiredBufferSize(const PFMultiplayerServerListBuildAliasesResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFMultiplayerServerBuildAliasDetailsResponse*) + sizeof(PFMultiplayerServerBuildAliasDetailsResponse*) * model.buildAliasesCount);
    for (size_t i = 0; i < model.buildAliasesCount; ++i)
    {
        requiredSize += BuildAliasDetailsResponse::RequiredBufferSize(*model.buildAliases[i]);
    }
    if (model.skipToken)
    {
        requiredSize += (std::strlen(model.skipToken) + 1);
    }
    return requiredSize;
}

HRESULT ListBuildAliasesResponse::Copy(const PFMultiplayerServerListBuildAliasesResponse& input, PFMultiplayerServerListBuildAliasesResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<BuildAliasDetailsResponse>(input.buildAliases, input.buildAliasesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildAliases = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.skipToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.skipToken = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ListBuildSummariesRequest::ToJson() const
{
    return ListBuildSummariesRequest::ToJson(this->Model());
}

JsonValue ListBuildSummariesRequest::ToJson(const PFMultiplayerServerListBuildSummariesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PageSize", input.pageSize);
    JsonUtils::ObjectAddMember(output, "SkipToken", input.skipToken);
    return output;
}

void BuildSummary::FromJson(const JsonValue& input)
{
    String buildId{};
    JsonUtils::ObjectGetMember(input, "BuildId", buildId);
    this->SetBuildId(std::move(buildId));

    String buildName{};
    JsonUtils::ObjectGetMember(input, "BuildName", buildName);
    this->SetBuildName(std::move(buildName));

    StdExtra::optional<time_t> creationTime{};
    JsonUtils::ObjectGetMemberTime(input, "CreationTime", creationTime);
    this->SetCreationTime(std::move(creationTime));

    StringDictionaryEntryVector metadata{};
    JsonUtils::ObjectGetMember(input, "Metadata", metadata);
    this->SetMetadata(std::move(metadata));

    ModelVector<BuildRegion> regionConfigurations{};
    JsonUtils::ObjectGetMember<BuildRegion>(input, "RegionConfigurations", regionConfigurations);
    this->SetRegionConfigurations(std::move(regionConfigurations));
}

size_t BuildSummary::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerBuildSummary const*> BuildSummary::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<BuildSummary>(&this->Model());
}

size_t BuildSummary::RequiredBufferSize(const PFMultiplayerServerBuildSummary& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.buildId)
    {
        requiredSize += (std::strlen(model.buildId) + 1);
    }
    if (model.buildName)
    {
        requiredSize += (std::strlen(model.buildName) + 1);
    }
    if (model.creationTime)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    requiredSize += (alignof(PFStringDictionaryEntry) + sizeof(PFStringDictionaryEntry) * model.metadataCount);
    for (size_t i = 0; i < model.metadataCount; ++i)
    {
        requiredSize += (std::strlen(model.metadata[i].key) + 1);
        requiredSize += (std::strlen(model.metadata[i].value) + 1);
    }
    requiredSize += (alignof(PFMultiplayerServerBuildRegion*) + sizeof(PFMultiplayerServerBuildRegion*) * model.regionConfigurationsCount);
    for (size_t i = 0; i < model.regionConfigurationsCount; ++i)
    {
        requiredSize += BuildRegion::RequiredBufferSize(*model.regionConfigurations[i]);
    }
    return requiredSize;
}

HRESULT BuildSummary::Copy(const PFMultiplayerServerBuildSummary& input, PFMultiplayerServerBuildSummary& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.buildId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.buildName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.creationTime); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.creationTime = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.metadata, input.metadataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.metadata = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<BuildRegion>(input.regionConfigurations, input.regionConfigurationsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.regionConfigurations = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void ListBuildSummariesResponse::FromJson(const JsonValue& input)
{
    ModelVector<BuildSummary> buildSummaries{};
    JsonUtils::ObjectGetMember<BuildSummary>(input, "BuildSummaries", buildSummaries);
    this->SetBuildSummaries(std::move(buildSummaries));

    JsonUtils::ObjectGetMember(input, "PageSize", this->m_model.pageSize);

    String skipToken{};
    JsonUtils::ObjectGetMember(input, "SkipToken", skipToken);
    this->SetSkipToken(std::move(skipToken));
}

size_t ListBuildSummariesResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerListBuildSummariesResponse const*> ListBuildSummariesResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ListBuildSummariesResponse>(&this->Model());
}

size_t ListBuildSummariesResponse::RequiredBufferSize(const PFMultiplayerServerListBuildSummariesResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFMultiplayerServerBuildSummary*) + sizeof(PFMultiplayerServerBuildSummary*) * model.buildSummariesCount);
    for (size_t i = 0; i < model.buildSummariesCount; ++i)
    {
        requiredSize += BuildSummary::RequiredBufferSize(*model.buildSummaries[i]);
    }
    if (model.skipToken)
    {
        requiredSize += (std::strlen(model.skipToken) + 1);
    }
    return requiredSize;
}

HRESULT ListBuildSummariesResponse::Copy(const PFMultiplayerServerListBuildSummariesResponse& input, PFMultiplayerServerListBuildSummariesResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<BuildSummary>(input.buildSummaries, input.buildSummariesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildSummaries = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.skipToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.skipToken = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ListCertificateSummariesRequest::ToJson() const
{
    return ListCertificateSummariesRequest::ToJson(this->Model());
}

JsonValue ListCertificateSummariesRequest::ToJson(const PFMultiplayerServerListCertificateSummariesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PageSize", input.pageSize);
    JsonUtils::ObjectAddMember(output, "SkipToken", input.skipToken);
    return output;
}

void CertificateSummary::FromJson(const JsonValue& input)
{
    String name{};
    JsonUtils::ObjectGetMember(input, "Name", name);
    this->SetName(std::move(name));

    String thumbprint{};
    JsonUtils::ObjectGetMember(input, "Thumbprint", thumbprint);
    this->SetThumbprint(std::move(thumbprint));
}

size_t CertificateSummary::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerCertificateSummary const*> CertificateSummary::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CertificateSummary>(&this->Model());
}

size_t CertificateSummary::RequiredBufferSize(const PFMultiplayerServerCertificateSummary& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.name)
    {
        requiredSize += (std::strlen(model.name) + 1);
    }
    if (model.thumbprint)
    {
        requiredSize += (std::strlen(model.thumbprint) + 1);
    }
    return requiredSize;
}

HRESULT CertificateSummary::Copy(const PFMultiplayerServerCertificateSummary& input, PFMultiplayerServerCertificateSummary& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.name); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.name = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.thumbprint); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.thumbprint = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void ListCertificateSummariesResponse::FromJson(const JsonValue& input)
{
    ModelVector<CertificateSummary> certificateSummaries{};
    JsonUtils::ObjectGetMember<CertificateSummary>(input, "CertificateSummaries", certificateSummaries);
    this->SetCertificateSummaries(std::move(certificateSummaries));

    JsonUtils::ObjectGetMember(input, "PageSize", this->m_model.pageSize);

    String skipToken{};
    JsonUtils::ObjectGetMember(input, "SkipToken", skipToken);
    this->SetSkipToken(std::move(skipToken));
}

size_t ListCertificateSummariesResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerListCertificateSummariesResponse const*> ListCertificateSummariesResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ListCertificateSummariesResponse>(&this->Model());
}

size_t ListCertificateSummariesResponse::RequiredBufferSize(const PFMultiplayerServerListCertificateSummariesResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFMultiplayerServerCertificateSummary*) + sizeof(PFMultiplayerServerCertificateSummary*) * model.certificateSummariesCount);
    for (size_t i = 0; i < model.certificateSummariesCount; ++i)
    {
        requiredSize += CertificateSummary::RequiredBufferSize(*model.certificateSummaries[i]);
    }
    if (model.skipToken)
    {
        requiredSize += (std::strlen(model.skipToken) + 1);
    }
    return requiredSize;
}

HRESULT ListCertificateSummariesResponse::Copy(const PFMultiplayerServerListCertificateSummariesResponse& input, PFMultiplayerServerListCertificateSummariesResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<CertificateSummary>(input.certificateSummaries, input.certificateSummariesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.certificateSummaries = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.skipToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.skipToken = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ListContainerImagesRequest::ToJson() const
{
    return ListContainerImagesRequest::ToJson(this->Model());
}

JsonValue ListContainerImagesRequest::ToJson(const PFMultiplayerServerListContainerImagesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PageSize", input.pageSize);
    JsonUtils::ObjectAddMember(output, "SkipToken", input.skipToken);
    return output;
}

void ListContainerImagesResponse::FromJson(const JsonValue& input)
{
    CStringVector images{};
    JsonUtils::ObjectGetMember(input, "Images", images);
    this->SetImages(std::move(images));

    JsonUtils::ObjectGetMember(input, "PageSize", this->m_model.pageSize);

    String skipToken{};
    JsonUtils::ObjectGetMember(input, "SkipToken", skipToken);
    this->SetSkipToken(std::move(skipToken));
}

size_t ListContainerImagesResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerListContainerImagesResponse const*> ListContainerImagesResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ListContainerImagesResponse>(&this->Model());
}

size_t ListContainerImagesResponse::RequiredBufferSize(const PFMultiplayerServerListContainerImagesResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(char*) + sizeof(char*) * model.imagesCount);
    for (size_t i = 0; i < model.imagesCount; ++i)
    {
        requiredSize += (std::strlen(model.images[i]) + 1);
    }
    if (model.skipToken)
    {
        requiredSize += (std::strlen(model.skipToken) + 1);
    }
    return requiredSize;
}

HRESULT ListContainerImagesResponse::Copy(const PFMultiplayerServerListContainerImagesResponse& input, PFMultiplayerServerListContainerImagesResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray(input.images, input.imagesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.images = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.skipToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.skipToken = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ListContainerImageTagsRequest::ToJson() const
{
    return ListContainerImageTagsRequest::ToJson(this->Model());
}

JsonValue ListContainerImageTagsRequest::ToJson(const PFMultiplayerServerListContainerImageTagsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ImageName", input.imageName);
    return output;
}

void ListContainerImageTagsResponse::FromJson(const JsonValue& input)
{
    CStringVector tags{};
    JsonUtils::ObjectGetMember(input, "Tags", tags);
    this->SetTags(std::move(tags));
}

size_t ListContainerImageTagsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerListContainerImageTagsResponse const*> ListContainerImageTagsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ListContainerImageTagsResponse>(&this->Model());
}

size_t ListContainerImageTagsResponse::RequiredBufferSize(const PFMultiplayerServerListContainerImageTagsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(char*) + sizeof(char*) * model.tagsCount);
    for (size_t i = 0; i < model.tagsCount; ++i)
    {
        requiredSize += (std::strlen(model.tags[i]) + 1);
    }
    return requiredSize;
}

HRESULT ListContainerImageTagsResponse::Copy(const PFMultiplayerServerListContainerImageTagsResponse& input, PFMultiplayerServerListContainerImageTagsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray(input.tags, input.tagsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.tags = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ListPartyQosServersRequest::ToJson() const
{
    return ListPartyQosServersRequest::ToJson(this->Model());
}

JsonValue ListPartyQosServersRequest::ToJson(const PFMultiplayerServerListPartyQosServersRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

void QosServer::FromJson(const JsonValue& input)
{
    String region{};
    JsonUtils::ObjectGetMember(input, "Region", region);
    this->SetRegion(std::move(region));

    String serverUrl{};
    JsonUtils::ObjectGetMember(input, "ServerUrl", serverUrl);
    this->SetServerUrl(std::move(serverUrl));
}

size_t QosServer::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerQosServer const*> QosServer::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<QosServer>(&this->Model());
}

size_t QosServer::RequiredBufferSize(const PFMultiplayerServerQosServer& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.region)
    {
        requiredSize += (std::strlen(model.region) + 1);
    }
    if (model.serverUrl)
    {
        requiredSize += (std::strlen(model.serverUrl) + 1);
    }
    return requiredSize;
}

HRESULT QosServer::Copy(const PFMultiplayerServerQosServer& input, PFMultiplayerServerQosServer& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.region); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.region = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverUrl); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverUrl = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void ListPartyQosServersResponse::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "PageSize", this->m_model.pageSize);

    ModelVector<QosServer> qosServers{};
    JsonUtils::ObjectGetMember<QosServer>(input, "QosServers", qosServers);
    this->SetQosServers(std::move(qosServers));

    String skipToken{};
    JsonUtils::ObjectGetMember(input, "SkipToken", skipToken);
    this->SetSkipToken(std::move(skipToken));
}

size_t ListPartyQosServersResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerListPartyQosServersResponse const*> ListPartyQosServersResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ListPartyQosServersResponse>(&this->Model());
}

size_t ListPartyQosServersResponse::RequiredBufferSize(const PFMultiplayerServerListPartyQosServersResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFMultiplayerServerQosServer*) + sizeof(PFMultiplayerServerQosServer*) * model.qosServersCount);
    for (size_t i = 0; i < model.qosServersCount; ++i)
    {
        requiredSize += QosServer::RequiredBufferSize(*model.qosServers[i]);
    }
    if (model.skipToken)
    {
        requiredSize += (std::strlen(model.skipToken) + 1);
    }
    return requiredSize;
}

HRESULT ListPartyQosServersResponse::Copy(const PFMultiplayerServerListPartyQosServersResponse& input, PFMultiplayerServerListPartyQosServersResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<QosServer>(input.qosServers, input.qosServersCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.qosServers = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.skipToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.skipToken = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ListQosServersForTitleRequest::ToJson() const
{
    return ListQosServersForTitleRequest::ToJson(this->Model());
}

JsonValue ListQosServersForTitleRequest::ToJson(const PFMultiplayerServerListQosServersForTitleRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "IncludeAllRegions", input.includeAllRegions);
    return output;
}

void ListQosServersForTitleResponse::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "PageSize", this->m_model.pageSize);

    ModelVector<QosServer> qosServers{};
    JsonUtils::ObjectGetMember<QosServer>(input, "QosServers", qosServers);
    this->SetQosServers(std::move(qosServers));

    String skipToken{};
    JsonUtils::ObjectGetMember(input, "SkipToken", skipToken);
    this->SetSkipToken(std::move(skipToken));
}

size_t ListQosServersForTitleResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerListQosServersForTitleResponse const*> ListQosServersForTitleResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ListQosServersForTitleResponse>(&this->Model());
}

size_t ListQosServersForTitleResponse::RequiredBufferSize(const PFMultiplayerServerListQosServersForTitleResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFMultiplayerServerQosServer*) + sizeof(PFMultiplayerServerQosServer*) * model.qosServersCount);
    for (size_t i = 0; i < model.qosServersCount; ++i)
    {
        requiredSize += QosServer::RequiredBufferSize(*model.qosServers[i]);
    }
    if (model.skipToken)
    {
        requiredSize += (std::strlen(model.skipToken) + 1);
    }
    return requiredSize;
}

HRESULT ListQosServersForTitleResponse::Copy(const PFMultiplayerServerListQosServersForTitleResponse& input, PFMultiplayerServerListQosServersForTitleResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<QosServer>(input.qosServers, input.qosServersCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.qosServers = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.skipToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.skipToken = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ListTitleMultiplayerServersQuotaChangesRequest::ToJson() const
{
    return ListTitleMultiplayerServersQuotaChangesRequest::ToJson(this->Model());
}

JsonValue ListTitleMultiplayerServersQuotaChangesRequest::ToJson(const PFMultiplayerServerListTitleMultiplayerServersQuotaChangesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

void ListTitleMultiplayerServersQuotaChangesResponse::FromJson(const JsonValue& input)
{
    ModelVector<QuotaChange> changes{};
    JsonUtils::ObjectGetMember<QuotaChange>(input, "Changes", changes);
    this->SetChanges(std::move(changes));
}

size_t ListTitleMultiplayerServersQuotaChangesResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse const*> ListTitleMultiplayerServersQuotaChangesResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ListTitleMultiplayerServersQuotaChangesResponse>(&this->Model());
}

size_t ListTitleMultiplayerServersQuotaChangesResponse::RequiredBufferSize(const PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFMultiplayerServerQuotaChange*) + sizeof(PFMultiplayerServerQuotaChange*) * model.changesCount);
    for (size_t i = 0; i < model.changesCount; ++i)
    {
        requiredSize += QuotaChange::RequiredBufferSize(*model.changes[i]);
    }
    return requiredSize;
}

HRESULT ListTitleMultiplayerServersQuotaChangesResponse::Copy(const PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse& input, PFMultiplayerServerListTitleMultiplayerServersQuotaChangesResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<QuotaChange>(input.changes, input.changesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.changes = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ListVirtualMachineSummariesRequest::ToJson() const
{
    return ListVirtualMachineSummariesRequest::ToJson(this->Model());
}

JsonValue ListVirtualMachineSummariesRequest::ToJson(const PFMultiplayerServerListVirtualMachineSummariesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PageSize", input.pageSize);
    JsonUtils::ObjectAddMember(output, "Region", input.region);
    JsonUtils::ObjectAddMember(output, "SkipToken", input.skipToken);
    return output;
}

void VirtualMachineSummary::FromJson(const JsonValue& input)
{
    String healthStatus{};
    JsonUtils::ObjectGetMember(input, "HealthStatus", healthStatus);
    this->SetHealthStatus(std::move(healthStatus));

    String state{};
    JsonUtils::ObjectGetMember(input, "State", state);
    this->SetState(std::move(state));

    String vmId{};
    JsonUtils::ObjectGetMember(input, "VmId", vmId);
    this->SetVmId(std::move(vmId));
}

size_t VirtualMachineSummary::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerVirtualMachineSummary const*> VirtualMachineSummary::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<VirtualMachineSummary>(&this->Model());
}

size_t VirtualMachineSummary::RequiredBufferSize(const PFMultiplayerServerVirtualMachineSummary& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.healthStatus)
    {
        requiredSize += (std::strlen(model.healthStatus) + 1);
    }
    if (model.state)
    {
        requiredSize += (std::strlen(model.state) + 1);
    }
    if (model.vmId)
    {
        requiredSize += (std::strlen(model.vmId) + 1);
    }
    return requiredSize;
}

HRESULT VirtualMachineSummary::Copy(const PFMultiplayerServerVirtualMachineSummary& input, PFMultiplayerServerVirtualMachineSummary& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.healthStatus); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.healthStatus = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.state); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.state = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.vmId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.vmId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void ListVirtualMachineSummariesResponse::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "PageSize", this->m_model.pageSize);

    String skipToken{};
    JsonUtils::ObjectGetMember(input, "SkipToken", skipToken);
    this->SetSkipToken(std::move(skipToken));

    ModelVector<VirtualMachineSummary> virtualMachines{};
    JsonUtils::ObjectGetMember<VirtualMachineSummary>(input, "VirtualMachines", virtualMachines);
    this->SetVirtualMachines(std::move(virtualMachines));
}

size_t ListVirtualMachineSummariesResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerListVirtualMachineSummariesResponse const*> ListVirtualMachineSummariesResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ListVirtualMachineSummariesResponse>(&this->Model());
}

size_t ListVirtualMachineSummariesResponse::RequiredBufferSize(const PFMultiplayerServerListVirtualMachineSummariesResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.skipToken)
    {
        requiredSize += (std::strlen(model.skipToken) + 1);
    }
    requiredSize += (alignof(PFMultiplayerServerVirtualMachineSummary*) + sizeof(PFMultiplayerServerVirtualMachineSummary*) * model.virtualMachinesCount);
    for (size_t i = 0; i < model.virtualMachinesCount; ++i)
    {
        requiredSize += VirtualMachineSummary::RequiredBufferSize(*model.virtualMachines[i]);
    }
    return requiredSize;
}

HRESULT ListVirtualMachineSummariesResponse::Copy(const PFMultiplayerServerListVirtualMachineSummariesResponse& input, PFMultiplayerServerListVirtualMachineSummariesResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.skipToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.skipToken = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<VirtualMachineSummary>(input.virtualMachines, input.virtualMachinesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualMachines = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue BuildAliasParams::ToJson() const
{
    return BuildAliasParams::ToJson(this->Model());
}

JsonValue BuildAliasParams::ToJson(const PFMultiplayerServerBuildAliasParams& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AliasId", input.aliasId);
    return output;
}

JsonValue RequestMultiplayerServerRequest::ToJson() const
{
    return RequestMultiplayerServerRequest::ToJson(this->Model());
}

JsonValue RequestMultiplayerServerRequest::ToJson(const PFMultiplayerServerRequestMultiplayerServerRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<BuildAliasParams>(output, "BuildAliasParams", input.buildAliasParams);
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray(output, "InitialPlayers", input.initialPlayers, input.initialPlayersCount);
    JsonUtils::ObjectAddMemberArray(output, "PreferredRegions", input.preferredRegions, input.preferredRegionsCount);
    JsonUtils::ObjectAddMember(output, "SessionCookie", input.sessionCookie);
    JsonUtils::ObjectAddMember(output, "SessionId", input.sessionId);
    return output;
}

void RequestMultiplayerServerResponse::FromJson(const JsonValue& input)
{
    String buildId{};
    JsonUtils::ObjectGetMember(input, "BuildId", buildId);
    this->SetBuildId(std::move(buildId));

    ModelVector<ConnectedPlayer> connectedPlayers{};
    JsonUtils::ObjectGetMember<ConnectedPlayer>(input, "ConnectedPlayers", connectedPlayers);
    this->SetConnectedPlayers(std::move(connectedPlayers));

    String fQDN{};
    JsonUtils::ObjectGetMember(input, "FQDN", fQDN);
    this->SetFQDN(std::move(fQDN));

    String iPV4Address{};
    JsonUtils::ObjectGetMember(input, "IPV4Address", iPV4Address);
    this->SetIPV4Address(std::move(iPV4Address));

    StdExtra::optional<time_t> lastStateTransitionTime{};
    JsonUtils::ObjectGetMemberTime(input, "LastStateTransitionTime", lastStateTransitionTime);
    this->SetLastStateTransitionTime(std::move(lastStateTransitionTime));

    ModelVector<Port> ports{};
    JsonUtils::ObjectGetMember<Port>(input, "Ports", ports);
    this->SetPorts(std::move(ports));

    String region{};
    JsonUtils::ObjectGetMember(input, "Region", region);
    this->SetRegion(std::move(region));

    String serverId{};
    JsonUtils::ObjectGetMember(input, "ServerId", serverId);
    this->SetServerId(std::move(serverId));

    String sessionId{};
    JsonUtils::ObjectGetMember(input, "SessionId", sessionId);
    this->SetSessionId(std::move(sessionId));

    String state{};
    JsonUtils::ObjectGetMember(input, "State", state);
    this->SetState(std::move(state));

    String vmId{};
    JsonUtils::ObjectGetMember(input, "VmId", vmId);
    this->SetVmId(std::move(vmId));
}

size_t RequestMultiplayerServerResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerRequestMultiplayerServerResponse const*> RequestMultiplayerServerResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RequestMultiplayerServerResponse>(&this->Model());
}

size_t RequestMultiplayerServerResponse::RequiredBufferSize(const PFMultiplayerServerRequestMultiplayerServerResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.buildId)
    {
        requiredSize += (std::strlen(model.buildId) + 1);
    }
    requiredSize += (alignof(PFMultiplayerServerConnectedPlayer*) + sizeof(PFMultiplayerServerConnectedPlayer*) * model.connectedPlayersCount);
    for (size_t i = 0; i < model.connectedPlayersCount; ++i)
    {
        requiredSize += ConnectedPlayer::RequiredBufferSize(*model.connectedPlayers[i]);
    }
    if (model.fQDN)
    {
        requiredSize += (std::strlen(model.fQDN) + 1);
    }
    if (model.iPV4Address)
    {
        requiredSize += (std::strlen(model.iPV4Address) + 1);
    }
    if (model.lastStateTransitionTime)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    requiredSize += (alignof(PFPort*) + sizeof(PFPort*) * model.portsCount);
    for (size_t i = 0; i < model.portsCount; ++i)
    {
        requiredSize += Port::RequiredBufferSize(*model.ports[i]);
    }
    if (model.region)
    {
        requiredSize += (std::strlen(model.region) + 1);
    }
    if (model.serverId)
    {
        requiredSize += (std::strlen(model.serverId) + 1);
    }
    if (model.sessionId)
    {
        requiredSize += (std::strlen(model.sessionId) + 1);
    }
    if (model.state)
    {
        requiredSize += (std::strlen(model.state) + 1);
    }
    if (model.vmId)
    {
        requiredSize += (std::strlen(model.vmId) + 1);
    }
    return requiredSize;
}

HRESULT RequestMultiplayerServerResponse::Copy(const PFMultiplayerServerRequestMultiplayerServerResponse& input, PFMultiplayerServerRequestMultiplayerServerResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.buildId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.buildId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<ConnectedPlayer>(input.connectedPlayers, input.connectedPlayersCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.connectedPlayers = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.fQDN); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.fQDN = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.iPV4Address); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.iPV4Address = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.lastStateTransitionTime); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lastStateTransitionTime = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<Port>(input.ports, input.portsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.ports = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.region); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.region = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.serverId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.serverId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.sessionId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.sessionId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.state); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.state = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.vmId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.vmId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RolloverContainerRegistryCredentialsRequest::ToJson() const
{
    return RolloverContainerRegistryCredentialsRequest::ToJson(this->Model());
}

JsonValue RolloverContainerRegistryCredentialsRequest::ToJson(const PFMultiplayerServerRolloverContainerRegistryCredentialsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

void RolloverContainerRegistryCredentialsResponse::FromJson(const JsonValue& input)
{
    String dnsName{};
    JsonUtils::ObjectGetMember(input, "DnsName", dnsName);
    this->SetDnsName(std::move(dnsName));

    String password{};
    JsonUtils::ObjectGetMember(input, "Password", password);
    this->SetPassword(std::move(password));

    String username{};
    JsonUtils::ObjectGetMember(input, "Username", username);
    this->SetUsername(std::move(username));
}

size_t RolloverContainerRegistryCredentialsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFMultiplayerServerRolloverContainerRegistryCredentialsResponse const*> RolloverContainerRegistryCredentialsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RolloverContainerRegistryCredentialsResponse>(&this->Model());
}

size_t RolloverContainerRegistryCredentialsResponse::RequiredBufferSize(const PFMultiplayerServerRolloverContainerRegistryCredentialsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.dnsName)
    {
        requiredSize += (std::strlen(model.dnsName) + 1);
    }
    if (model.password)
    {
        requiredSize += (std::strlen(model.password) + 1);
    }
    if (model.username)
    {
        requiredSize += (std::strlen(model.username) + 1);
    }
    return requiredSize;
}

HRESULT RolloverContainerRegistryCredentialsResponse::Copy(const PFMultiplayerServerRolloverContainerRegistryCredentialsResponse& input, PFMultiplayerServerRolloverContainerRegistryCredentialsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.dnsName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.dnsName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.password); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.password = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.username); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.username = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ShutdownMultiplayerServerRequest::ToJson() const
{
    return ShutdownMultiplayerServerRequest::ToJson(this->Model());
}

JsonValue ShutdownMultiplayerServerRequest::ToJson(const PFMultiplayerServerShutdownMultiplayerServerRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "SessionId", input.sessionId);
    return output;
}

JsonValue UntagContainerImageRequest::ToJson() const
{
    return UntagContainerImageRequest::ToJson(this->Model());
}

JsonValue UntagContainerImageRequest::ToJson(const PFMultiplayerServerUntagContainerImageRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ImageName", input.imageName);
    JsonUtils::ObjectAddMember(output, "Tag", input.tag);
    return output;
}

JsonValue UpdateBuildAliasRequest::ToJson() const
{
    return UpdateBuildAliasRequest::ToJson(this->Model());
}

JsonValue UpdateBuildAliasRequest::ToJson(const PFMultiplayerServerUpdateBuildAliasRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AliasId", input.aliasId);
    JsonUtils::ObjectAddMember(output, "AliasName", input.aliasName);
    JsonUtils::ObjectAddMemberArray<BuildSelectionCriterion>(output, "BuildSelectionCriteria", input.buildSelectionCriteria, input.buildSelectionCriteriaCount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue UpdateBuildNameRequest::ToJson() const
{
    return UpdateBuildNameRequest::ToJson(this->Model());
}

JsonValue UpdateBuildNameRequest::ToJson(const PFMultiplayerServerUpdateBuildNameRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    JsonUtils::ObjectAddMember(output, "BuildName", input.buildName);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue UpdateBuildRegionRequest::ToJson() const
{
    return UpdateBuildRegionRequest::ToJson(this->Model());
}

JsonValue UpdateBuildRegionRequest::ToJson(const PFMultiplayerServerUpdateBuildRegionRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    JsonUtils::ObjectAddMember<BuildRegionParams>(output, "BuildRegion", input.buildRegion);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue UpdateBuildRegionsRequest::ToJson() const
{
    return UpdateBuildRegionsRequest::ToJson(this->Model());
}

JsonValue UpdateBuildRegionsRequest::ToJson(const PFMultiplayerServerUpdateBuildRegionsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "BuildId", input.buildId);
    JsonUtils::ObjectAddMemberArray<BuildRegionParams>(output, "BuildRegions", input.buildRegions, input.buildRegionsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue Certificate::ToJson() const
{
    return Certificate::ToJson(this->Model());
}

JsonValue Certificate::ToJson(const PFMultiplayerServerCertificate& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Base64EncodedValue", input.base64EncodedValue);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    JsonUtils::ObjectAddMember(output, "Password", input.password);
    return output;
}

JsonValue UploadCertificateRequest::ToJson() const
{
    return UploadCertificateRequest::ToJson(this->Model());
}

JsonValue UploadCertificateRequest::ToJson(const PFMultiplayerServerUploadCertificateRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<Certificate>(output, "GameCertificate", input.gameCertificate);
    return output;
}

} // namespace MultiplayerServer
} // namespace PlayFab
