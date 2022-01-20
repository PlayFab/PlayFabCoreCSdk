#include "stdafx.h"
#include "LeaderboardDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Leaderboard
{

JsonValue CreatePlayerStatisticDefinitionRequest::ToJson() const
{
    return CreatePlayerStatisticDefinitionRequest::ToJson(this->Model());
}

JsonValue CreatePlayerStatisticDefinitionRequest::ToJson(const PFLeaderboardCreatePlayerStatisticDefinitionRequest& input)
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
    StdExtra::optional<PFLeaderboardStatisticAggregationMethod> aggregationMethod{};
    JsonUtils::ObjectGetMember(input, "AggregationMethod", aggregationMethod);
    this->SetAggregationMethod(std::move(aggregationMethod));

    JsonUtils::ObjectGetMember(input, "CurrentVersion", this->m_model.currentVersion);

    String statisticName{};
    JsonUtils::ObjectGetMember(input, "StatisticName", statisticName);
    this->SetStatisticName(std::move(statisticName));

    StdExtra::optional<PFLeaderboardStatisticResetIntervalOption> versionChangeInterval{};
    JsonUtils::ObjectGetMember(input, "VersionChangeInterval", versionChangeInterval);
    this->SetVersionChangeInterval(std::move(versionChangeInterval));
}

size_t PlayerStatisticDefinition::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFLeaderboardPlayerStatisticDefinition const*> PlayerStatisticDefinition::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PlayerStatisticDefinition>(&this->Model());
}

size_t PlayerStatisticDefinition::RequiredBufferSize(const PFLeaderboardPlayerStatisticDefinition& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.aggregationMethod)
    {
        requiredSize += (alignof(PFLeaderboardStatisticAggregationMethod) + sizeof(PFLeaderboardStatisticAggregationMethod));
    }
    if (model.statisticName)
    {
        requiredSize += (std::strlen(model.statisticName) + 1);
    }
    if (model.versionChangeInterval)
    {
        requiredSize += (alignof(PFLeaderboardStatisticResetIntervalOption) + sizeof(PFLeaderboardStatisticResetIntervalOption));
    }
    return requiredSize;
}

HRESULT PlayerStatisticDefinition::Copy(const PFLeaderboardPlayerStatisticDefinition& input, PFLeaderboardPlayerStatisticDefinition& output, ModelBuffer& buffer)
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

Result<PFLeaderboardCreatePlayerStatisticDefinitionResult const*> CreatePlayerStatisticDefinitionResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CreatePlayerStatisticDefinitionResult>(&this->Model());
}

size_t CreatePlayerStatisticDefinitionResult::RequiredBufferSize(const PFLeaderboardCreatePlayerStatisticDefinitionResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.statistic)
    {
        requiredSize += PlayerStatisticDefinition::RequiredBufferSize(*model.statistic);
    }
    return requiredSize;
}

HRESULT CreatePlayerStatisticDefinitionResult::Copy(const PFLeaderboardCreatePlayerStatisticDefinitionResult& input, PFLeaderboardCreatePlayerStatisticDefinitionResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<PlayerStatisticDefinition>(input.statistic); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statistic = propCopyResult.ExtractPayload();
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

Result<PFLeaderboardGetPlayerStatisticDefinitionsResult const*> GetPlayerStatisticDefinitionsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayerStatisticDefinitionsResult>(&this->Model());
}

size_t GetPlayerStatisticDefinitionsResult::RequiredBufferSize(const PFLeaderboardGetPlayerStatisticDefinitionsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFLeaderboardPlayerStatisticDefinition*) + sizeof(PFLeaderboardPlayerStatisticDefinition*) * model.statisticsCount);
    for (size_t i = 0; i < model.statisticsCount; ++i)
    {
        requiredSize += PlayerStatisticDefinition::RequiredBufferSize(*model.statistics[i]);
    }
    return requiredSize;
}

HRESULT GetPlayerStatisticDefinitionsResult::Copy(const PFLeaderboardGetPlayerStatisticDefinitionsResult& input, PFLeaderboardGetPlayerStatisticDefinitionsResult& output, ModelBuffer& buffer)
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

JsonValue GetPlayerStatisticVersionsRequest::ToJson(const PFLeaderboardGetPlayerStatisticVersionsRequest& input)
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

    StdExtra::optional<PFLeaderboardStatisticVersionStatus> status{};
    JsonUtils::ObjectGetMember(input, "Status", status);
    this->SetStatus(std::move(status));

    JsonUtils::ObjectGetMember(input, "Version", this->m_model.version);
}

size_t PlayerStatisticVersion::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFLeaderboardPlayerStatisticVersion const*> PlayerStatisticVersion::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PlayerStatisticVersion>(&this->Model());
}

size_t PlayerStatisticVersion::RequiredBufferSize(const PFLeaderboardPlayerStatisticVersion& model)
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
        requiredSize += (alignof(PFLeaderboardStatisticVersionStatus) + sizeof(PFLeaderboardStatisticVersionStatus));
    }
    return requiredSize;
}

HRESULT PlayerStatisticVersion::Copy(const PFLeaderboardPlayerStatisticVersion& input, PFLeaderboardPlayerStatisticVersion& output, ModelBuffer& buffer)
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

Result<PFLeaderboardGetPlayerStatisticVersionsResult const*> GetPlayerStatisticVersionsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayerStatisticVersionsResult>(&this->Model());
}

size_t GetPlayerStatisticVersionsResult::RequiredBufferSize(const PFLeaderboardGetPlayerStatisticVersionsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFLeaderboardPlayerStatisticVersion*) + sizeof(PFLeaderboardPlayerStatisticVersion*) * model.statisticVersionsCount);
    for (size_t i = 0; i < model.statisticVersionsCount; ++i)
    {
        requiredSize += PlayerStatisticVersion::RequiredBufferSize(*model.statisticVersions[i]);
    }
    return requiredSize;
}

HRESULT GetPlayerStatisticVersionsResult::Copy(const PFLeaderboardGetPlayerStatisticVersionsResult& input, PFLeaderboardGetPlayerStatisticVersionsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<PlayerStatisticVersion>(input.statisticVersions, input.statisticVersionsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statisticVersions = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue IncrementPlayerStatisticVersionRequest::ToJson() const
{
    return IncrementPlayerStatisticVersionRequest::ToJson(this->Model());
}

JsonValue IncrementPlayerStatisticVersionRequest::ToJson(const PFLeaderboardIncrementPlayerStatisticVersionRequest& input)
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

Result<PFLeaderboardIncrementPlayerStatisticVersionResult const*> IncrementPlayerStatisticVersionResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<IncrementPlayerStatisticVersionResult>(&this->Model());
}

size_t IncrementPlayerStatisticVersionResult::RequiredBufferSize(const PFLeaderboardIncrementPlayerStatisticVersionResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.statisticVersion)
    {
        requiredSize += PlayerStatisticVersion::RequiredBufferSize(*model.statisticVersion);
    }
    return requiredSize;
}

HRESULT IncrementPlayerStatisticVersionResult::Copy(const PFLeaderboardIncrementPlayerStatisticVersionResult& input, PFLeaderboardIncrementPlayerStatisticVersionResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<PlayerStatisticVersion>(input.statisticVersion); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statisticVersion = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ResetUserStatisticsRequest::ToJson() const
{
    return ResetUserStatisticsRequest::ToJson(this->Model());
}

JsonValue ResetUserStatisticsRequest::ToJson(const PFLeaderboardResetUserStatisticsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue UpdatePlayerStatisticDefinitionRequest::ToJson() const
{
    return UpdatePlayerStatisticDefinitionRequest::ToJson(this->Model());
}

JsonValue UpdatePlayerStatisticDefinitionRequest::ToJson(const PFLeaderboardUpdatePlayerStatisticDefinitionRequest& input)
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

Result<PFLeaderboardUpdatePlayerStatisticDefinitionResult const*> UpdatePlayerStatisticDefinitionResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<UpdatePlayerStatisticDefinitionResult>(&this->Model());
}

size_t UpdatePlayerStatisticDefinitionResult::RequiredBufferSize(const PFLeaderboardUpdatePlayerStatisticDefinitionResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.statistic)
    {
        requiredSize += PlayerStatisticDefinition::RequiredBufferSize(*model.statistic);
    }
    return requiredSize;
}

HRESULT UpdatePlayerStatisticDefinitionResult::Copy(const PFLeaderboardUpdatePlayerStatisticDefinitionResult& input, PFLeaderboardUpdatePlayerStatisticDefinitionResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<PlayerStatisticDefinition>(input.statistic); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statistic = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ClientGetFriendLeaderboardRequest::ToJson() const
{
    return ClientGetFriendLeaderboardRequest::ToJson(this->Model());
}

JsonValue ClientGetFriendLeaderboardRequest::ToJson(const PFLeaderboardClientGetFriendLeaderboardRequest& input)
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

Result<PFLeaderboardPlayerLeaderboardEntry const*> PlayerLeaderboardEntry::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PlayerLeaderboardEntry>(&this->Model());
}

size_t PlayerLeaderboardEntry::RequiredBufferSize(const PFLeaderboardPlayerLeaderboardEntry& model)
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

HRESULT PlayerLeaderboardEntry::Copy(const PFLeaderboardPlayerLeaderboardEntry& input, PFLeaderboardPlayerLeaderboardEntry& output, ModelBuffer& buffer)
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

Result<PFLeaderboardGetLeaderboardResult const*> GetLeaderboardResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetLeaderboardResult>(&this->Model());
}

size_t GetLeaderboardResult::RequiredBufferSize(const PFLeaderboardGetLeaderboardResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFLeaderboardPlayerLeaderboardEntry*) + sizeof(PFLeaderboardPlayerLeaderboardEntry*) * model.leaderboardCount);
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

HRESULT GetLeaderboardResult::Copy(const PFLeaderboardGetLeaderboardResult& input, PFLeaderboardGetLeaderboardResult& output, ModelBuffer& buffer)
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

JsonValue GetFriendLeaderboardAroundPlayerRequest::ToJson(const PFLeaderboardGetFriendLeaderboardAroundPlayerRequest& input)
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

Result<PFLeaderboardGetFriendLeaderboardAroundPlayerResult const*> GetFriendLeaderboardAroundPlayerResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetFriendLeaderboardAroundPlayerResult>(&this->Model());
}

size_t GetFriendLeaderboardAroundPlayerResult::RequiredBufferSize(const PFLeaderboardGetFriendLeaderboardAroundPlayerResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFLeaderboardPlayerLeaderboardEntry*) + sizeof(PFLeaderboardPlayerLeaderboardEntry*) * model.leaderboardCount);
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

HRESULT GetFriendLeaderboardAroundPlayerResult::Copy(const PFLeaderboardGetFriendLeaderboardAroundPlayerResult& input, PFLeaderboardGetFriendLeaderboardAroundPlayerResult& output, ModelBuffer& buffer)
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

JsonValue GetLeaderboardRequest::ToJson(const PFLeaderboardGetLeaderboardRequest& input)
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

JsonValue GetLeaderboardAroundPlayerRequest::ToJson(const PFLeaderboardGetLeaderboardAroundPlayerRequest& input)
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

Result<PFLeaderboardGetLeaderboardAroundPlayerResult const*> GetLeaderboardAroundPlayerResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetLeaderboardAroundPlayerResult>(&this->Model());
}

size_t GetLeaderboardAroundPlayerResult::RequiredBufferSize(const PFLeaderboardGetLeaderboardAroundPlayerResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFLeaderboardPlayerLeaderboardEntry*) + sizeof(PFLeaderboardPlayerLeaderboardEntry*) * model.leaderboardCount);
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

HRESULT GetLeaderboardAroundPlayerResult::Copy(const PFLeaderboardGetLeaderboardAroundPlayerResult& input, PFLeaderboardGetLeaderboardAroundPlayerResult& output, ModelBuffer& buffer)
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

JsonValue StatisticNameVersion::ToJson(const PFLeaderboardStatisticNameVersion& input)
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

JsonValue ClientGetPlayerStatisticsRequest::ToJson(const PFLeaderboardClientGetPlayerStatisticsRequest& input)
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

Result<PFLeaderboardClientGetPlayerStatisticsResult const*> ClientGetPlayerStatisticsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ClientGetPlayerStatisticsResult>(&this->Model());
}

size_t ClientGetPlayerStatisticsResult::RequiredBufferSize(const PFLeaderboardClientGetPlayerStatisticsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFStatisticValue*) + sizeof(PFStatisticValue*) * model.statisticsCount);
    for (size_t i = 0; i < model.statisticsCount; ++i)
    {
        requiredSize += StatisticValue::RequiredBufferSize(*model.statistics[i]);
    }
    return requiredSize;
}

HRESULT ClientGetPlayerStatisticsResult::Copy(const PFLeaderboardClientGetPlayerStatisticsResult& input, PFLeaderboardClientGetPlayerStatisticsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<StatisticValue>(input.statistics, input.statisticsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statistics = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue StatisticUpdate::ToJson() const
{
    return StatisticUpdate::ToJson(this->Model());
}

JsonValue StatisticUpdate::ToJson(const PFLeaderboardStatisticUpdate& input)
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

JsonValue ClientUpdatePlayerStatisticsRequest::ToJson(const PFLeaderboardClientUpdatePlayerStatisticsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray<StatisticUpdate>(output, "Statistics", input.statistics, input.statisticsCount);
    return output;
}

JsonValue ServerGetFriendLeaderboardRequest::ToJson() const
{
    return ServerGetFriendLeaderboardRequest::ToJson(this->Model());
}

JsonValue ServerGetFriendLeaderboardRequest::ToJson(const PFLeaderboardServerGetFriendLeaderboardRequest& input)
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

JsonValue GetLeaderboardAroundUserRequest::ToJson(const PFLeaderboardGetLeaderboardAroundUserRequest& input)
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

Result<PFLeaderboardGetLeaderboardAroundUserResult const*> GetLeaderboardAroundUserResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetLeaderboardAroundUserResult>(&this->Model());
}

size_t GetLeaderboardAroundUserResult::RequiredBufferSize(const PFLeaderboardGetLeaderboardAroundUserResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFLeaderboardPlayerLeaderboardEntry*) + sizeof(PFLeaderboardPlayerLeaderboardEntry*) * model.leaderboardCount);
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

HRESULT GetLeaderboardAroundUserResult::Copy(const PFLeaderboardGetLeaderboardAroundUserResult& input, PFLeaderboardGetLeaderboardAroundUserResult& output, ModelBuffer& buffer)
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

JsonValue ServerGetPlayerStatisticsRequest::ToJson(const PFLeaderboardServerGetPlayerStatisticsRequest& input)
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

Result<PFLeaderboardServerGetPlayerStatisticsResult const*> ServerGetPlayerStatisticsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ServerGetPlayerStatisticsResult>(&this->Model());
}

size_t ServerGetPlayerStatisticsResult::RequiredBufferSize(const PFLeaderboardServerGetPlayerStatisticsResult& model)
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

HRESULT ServerGetPlayerStatisticsResult::Copy(const PFLeaderboardServerGetPlayerStatisticsResult& input, PFLeaderboardServerGetPlayerStatisticsResult& output, ModelBuffer& buffer)
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

JsonValue ServerUpdatePlayerStatisticsRequest::ToJson() const
{
    return ServerUpdatePlayerStatisticsRequest::ToJson(this->Model());
}

JsonValue ServerUpdatePlayerStatisticsRequest::ToJson(const PFLeaderboardServerUpdatePlayerStatisticsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ForceUpdate", input.forceUpdate);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMemberArray<StatisticUpdate>(output, "Statistics", input.statistics, input.statisticsCount);
    return output;
}

} // namespace Leaderboard
} // namespace PlayFab
