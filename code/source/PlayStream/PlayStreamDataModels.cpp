#include "stdafx.h"
#include "PlayStreamDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace PlayStream
{

JsonValue AddPlayerTagRequest::ToJson() const
{
    return AddPlayerTagRequest::ToJson(this->Model());
}

JsonValue AddPlayerTagRequest::ToJson(const PFPlayStreamAddPlayerTagRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "TagName", input.tagName);
    return output;
}

void GetSegmentResult::FromJson(const JsonValue& input)
{
    String aBTestParent{};
    JsonUtils::ObjectGetMember(input, "ABTestParent", aBTestParent);
    this->SetABTestParent(std::move(aBTestParent));

    String id{};
    JsonUtils::ObjectGetMember(input, "Id", id);
    this->SetId(std::move(id));

    String name{};
    JsonUtils::ObjectGetMember(input, "Name", name);
    this->SetName(std::move(name));
}

size_t GetSegmentResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayStreamGetSegmentResult const*> GetSegmentResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetSegmentResult>(&this->Model());
}

size_t GetSegmentResult::RequiredBufferSize(const PFPlayStreamGetSegmentResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.aBTestParent)
    {
        requiredSize += (std::strlen(model.aBTestParent) + 1);
    }
    if (model.id)
    {
        requiredSize += (std::strlen(model.id) + 1);
    }
    if (model.name)
    {
        requiredSize += (std::strlen(model.name) + 1);
    }
    return requiredSize;
}

HRESULT GetSegmentResult::Copy(const PFPlayStreamGetSegmentResult& input, PFPlayStreamGetSegmentResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.aBTestParent); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.aBTestParent = propCopyResult.ExtractPayload();
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
    return S_OK;
}

void GetAllSegmentsResult::FromJson(const JsonValue& input)
{
    ModelVector<GetSegmentResult> segments{};
    JsonUtils::ObjectGetMember<GetSegmentResult>(input, "Segments", segments);
    this->SetSegments(std::move(segments));
}

size_t GetAllSegmentsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayStreamGetAllSegmentsResult const*> GetAllSegmentsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetAllSegmentsResult>(&this->Model());
}

size_t GetAllSegmentsResult::RequiredBufferSize(const PFPlayStreamGetAllSegmentsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlayStreamGetSegmentResult*) + sizeof(PFPlayStreamGetSegmentResult*) * model.segmentsCount);
    for (size_t i = 0; i < model.segmentsCount; ++i)
    {
        requiredSize += GetSegmentResult::RequiredBufferSize(*model.segments[i]);
    }
    return requiredSize;
}

HRESULT GetAllSegmentsResult::Copy(const PFPlayStreamGetAllSegmentsResult& input, PFPlayStreamGetAllSegmentsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<GetSegmentResult>(input.segments, input.segmentsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.segments = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayersSegmentsRequest::ToJson() const
{
    return GetPlayersSegmentsRequest::ToJson(this->Model());
}

JsonValue GetPlayersSegmentsRequest::ToJson(const PFPlayStreamGetPlayersSegmentsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void GetPlayerSegmentsResult::FromJson(const JsonValue& input)
{
    ModelVector<GetSegmentResult> segments{};
    JsonUtils::ObjectGetMember<GetSegmentResult>(input, "Segments", segments);
    this->SetSegments(std::move(segments));
}

size_t GetPlayerSegmentsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayStreamGetPlayerSegmentsResult const*> GetPlayerSegmentsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayerSegmentsResult>(&this->Model());
}

size_t GetPlayerSegmentsResult::RequiredBufferSize(const PFPlayStreamGetPlayerSegmentsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlayStreamGetSegmentResult*) + sizeof(PFPlayStreamGetSegmentResult*) * model.segmentsCount);
    for (size_t i = 0; i < model.segmentsCount; ++i)
    {
        requiredSize += GetSegmentResult::RequiredBufferSize(*model.segments[i]);
    }
    return requiredSize;
}

HRESULT GetPlayerSegmentsResult::Copy(const PFPlayStreamGetPlayerSegmentsResult& input, PFPlayStreamGetPlayerSegmentsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<GetSegmentResult>(input.segments, input.segmentsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.segments = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayersInSegmentRequest::ToJson() const
{
    return GetPlayersInSegmentRequest::ToJson(this->Model());
}

JsonValue GetPlayersInSegmentRequest::ToJson(const PFPlayStreamGetPlayersInSegmentRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ContinuationToken", input.continuationToken);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "MaxBatchSize", input.maxBatchSize);
    JsonUtils::ObjectAddMember(output, "SecondsToLive", input.secondsToLive);
    JsonUtils::ObjectAddMember(output, "SegmentId", input.segmentId);
    return output;
}

void AdCampaignAttribution::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMemberTime(input, "AttributedAt", this->m_model.attributedAt);

    String campaignId{};
    JsonUtils::ObjectGetMember(input, "CampaignId", campaignId);
    this->SetCampaignId(std::move(campaignId));

    String platform{};
    JsonUtils::ObjectGetMember(input, "Platform", platform);
    this->SetPlatform(std::move(platform));
}

size_t AdCampaignAttribution::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayStreamAdCampaignAttribution const*> AdCampaignAttribution::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AdCampaignAttribution>(&this->Model());
}

size_t AdCampaignAttribution::RequiredBufferSize(const PFPlayStreamAdCampaignAttribution& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.campaignId)
    {
        requiredSize += (std::strlen(model.campaignId) + 1);
    }
    if (model.platform)
    {
        requiredSize += (std::strlen(model.platform) + 1);
    }
    return requiredSize;
}

HRESULT AdCampaignAttribution::Copy(const PFPlayStreamAdCampaignAttribution& input, PFPlayStreamAdCampaignAttribution& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.campaignId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.campaignId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.platform); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.platform = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void ContactEmailInfo::FromJson(const JsonValue& input)
{
    String emailAddress{};
    JsonUtils::ObjectGetMember(input, "EmailAddress", emailAddress);
    this->SetEmailAddress(std::move(emailAddress));

    String name{};
    JsonUtils::ObjectGetMember(input, "Name", name);
    this->SetName(std::move(name));

    StdExtra::optional<PFEmailVerificationStatus> verificationStatus{};
    JsonUtils::ObjectGetMember(input, "VerificationStatus", verificationStatus);
    this->SetVerificationStatus(std::move(verificationStatus));
}

size_t ContactEmailInfo::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayStreamContactEmailInfo const*> ContactEmailInfo::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ContactEmailInfo>(&this->Model());
}

size_t ContactEmailInfo::RequiredBufferSize(const PFPlayStreamContactEmailInfo& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.emailAddress)
    {
        requiredSize += (std::strlen(model.emailAddress) + 1);
    }
    if (model.name)
    {
        requiredSize += (std::strlen(model.name) + 1);
    }
    if (model.verificationStatus)
    {
        requiredSize += (alignof(PFEmailVerificationStatus) + sizeof(PFEmailVerificationStatus));
    }
    return requiredSize;
}

HRESULT ContactEmailInfo::Copy(const PFPlayStreamContactEmailInfo& input, PFPlayStreamContactEmailInfo& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.emailAddress); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.emailAddress = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.name); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.name = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.verificationStatus); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.verificationStatus = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void PlayerLinkedAccount::FromJson(const JsonValue& input)
{
    String email{};
    JsonUtils::ObjectGetMember(input, "Email", email);
    this->SetEmail(std::move(email));

    StdExtra::optional<PFLoginIdentityProvider> platform{};
    JsonUtils::ObjectGetMember(input, "Platform", platform);
    this->SetPlatform(std::move(platform));

    String platformUserId{};
    JsonUtils::ObjectGetMember(input, "PlatformUserId", platformUserId);
    this->SetPlatformUserId(std::move(platformUserId));

    String username{};
    JsonUtils::ObjectGetMember(input, "Username", username);
    this->SetUsername(std::move(username));
}

size_t PlayerLinkedAccount::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayStreamPlayerLinkedAccount const*> PlayerLinkedAccount::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PlayerLinkedAccount>(&this->Model());
}

size_t PlayerLinkedAccount::RequiredBufferSize(const PFPlayStreamPlayerLinkedAccount& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.email)
    {
        requiredSize += (std::strlen(model.email) + 1);
    }
    if (model.platform)
    {
        requiredSize += (alignof(PFLoginIdentityProvider) + sizeof(PFLoginIdentityProvider));
    }
    if (model.platformUserId)
    {
        requiredSize += (std::strlen(model.platformUserId) + 1);
    }
    if (model.username)
    {
        requiredSize += (std::strlen(model.username) + 1);
    }
    return requiredSize;
}

HRESULT PlayerLinkedAccount::Copy(const PFPlayStreamPlayerLinkedAccount& input, PFPlayStreamPlayerLinkedAccount& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.email); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.email = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.platform); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.platform = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.platformUserId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.platformUserId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.username); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.username = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void PlayerLocation::FromJson(const JsonValue& input)
{
    String city{};
    JsonUtils::ObjectGetMember(input, "City", city);
    this->SetCity(std::move(city));

    JsonUtils::ObjectGetMember(input, "ContinentCode", this->m_model.continentCode);

    JsonUtils::ObjectGetMember(input, "CountryCode", this->m_model.countryCode);

    StdExtra::optional<double> latitude{};
    JsonUtils::ObjectGetMember(input, "Latitude", latitude);
    this->SetLatitude(std::move(latitude));

    StdExtra::optional<double> longitude{};
    JsonUtils::ObjectGetMember(input, "Longitude", longitude);
    this->SetLongitude(std::move(longitude));
}

size_t PlayerLocation::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayStreamPlayerLocation const*> PlayerLocation::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PlayerLocation>(&this->Model());
}

size_t PlayerLocation::RequiredBufferSize(const PFPlayStreamPlayerLocation& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.city)
    {
        requiredSize += (std::strlen(model.city) + 1);
    }
    if (model.latitude)
    {
        requiredSize += (alignof(double) + sizeof(double));
    }
    if (model.longitude)
    {
        requiredSize += (alignof(double) + sizeof(double));
    }
    return requiredSize;
}

HRESULT PlayerLocation::Copy(const PFPlayStreamPlayerLocation& input, PFPlayStreamPlayerLocation& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.city); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.city = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.latitude); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.latitude = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.longitude); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.longitude = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void PlayerStatistic::FromJson(const JsonValue& input)
{
    String id{};
    JsonUtils::ObjectGetMember(input, "Id", id);
    this->SetId(std::move(id));

    String name{};
    JsonUtils::ObjectGetMember(input, "Name", name);
    this->SetName(std::move(name));

    JsonUtils::ObjectGetMember(input, "StatisticValue", this->m_model.statisticValue);

    JsonUtils::ObjectGetMember(input, "StatisticVersion", this->m_model.statisticVersion);
}

size_t PlayerStatistic::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayStreamPlayerStatistic const*> PlayerStatistic::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PlayerStatistic>(&this->Model());
}

size_t PlayerStatistic::RequiredBufferSize(const PFPlayStreamPlayerStatistic& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.id)
    {
        requiredSize += (std::strlen(model.id) + 1);
    }
    if (model.name)
    {
        requiredSize += (std::strlen(model.name) + 1);
    }
    return requiredSize;
}

HRESULT PlayerStatistic::Copy(const PFPlayStreamPlayerStatistic& input, PFPlayStreamPlayerStatistic& output, ModelBuffer& buffer)
{
    output = input;
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
    return S_OK;
}

void PushNotificationRegistration::FromJson(const JsonValue& input)
{
    String notificationEndpointARN{};
    JsonUtils::ObjectGetMember(input, "NotificationEndpointARN", notificationEndpointARN);
    this->SetNotificationEndpointARN(std::move(notificationEndpointARN));

    StdExtra::optional<PFPushNotificationPlatform> platform{};
    JsonUtils::ObjectGetMember(input, "Platform", platform);
    this->SetPlatform(std::move(platform));
}

size_t PushNotificationRegistration::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayStreamPushNotificationRegistration const*> PushNotificationRegistration::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PushNotificationRegistration>(&this->Model());
}

size_t PushNotificationRegistration::RequiredBufferSize(const PFPlayStreamPushNotificationRegistration& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.notificationEndpointARN)
    {
        requiredSize += (std::strlen(model.notificationEndpointARN) + 1);
    }
    if (model.platform)
    {
        requiredSize += (alignof(PFPushNotificationPlatform) + sizeof(PFPushNotificationPlatform));
    }
    return requiredSize;
}

HRESULT PushNotificationRegistration::Copy(const PFPlayStreamPushNotificationRegistration& input, PFPlayStreamPushNotificationRegistration& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.notificationEndpointARN); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.notificationEndpointARN = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.platform); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.platform = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void PlayerProfile::FromJson(const JsonValue& input)
{
    ModelVector<AdCampaignAttribution> adCampaignAttributions{};
    JsonUtils::ObjectGetMember<AdCampaignAttribution>(input, "AdCampaignAttributions", adCampaignAttributions);
    this->SetAdCampaignAttributions(std::move(adCampaignAttributions));

    String avatarUrl{};
    JsonUtils::ObjectGetMember(input, "AvatarUrl", avatarUrl);
    this->SetAvatarUrl(std::move(avatarUrl));

    StdExtra::optional<time_t> bannedUntil{};
    JsonUtils::ObjectGetMemberTime(input, "BannedUntil", bannedUntil);
    this->SetBannedUntil(std::move(bannedUntil));

    ModelVector<ContactEmailInfo> contactEmailAddresses{};
    JsonUtils::ObjectGetMember<ContactEmailInfo>(input, "ContactEmailAddresses", contactEmailAddresses);
    this->SetContactEmailAddresses(std::move(contactEmailAddresses));

    StdExtra::optional<time_t> created{};
    JsonUtils::ObjectGetMemberTime(input, "Created", created);
    this->SetCreated(std::move(created));

    String displayName{};
    JsonUtils::ObjectGetMember(input, "DisplayName", displayName);
    this->SetDisplayName(std::move(displayName));

    StdExtra::optional<time_t> lastLogin{};
    JsonUtils::ObjectGetMemberTime(input, "LastLogin", lastLogin);
    this->SetLastLogin(std::move(lastLogin));

    ModelVector<PlayerLinkedAccount> linkedAccounts{};
    JsonUtils::ObjectGetMember<PlayerLinkedAccount>(input, "LinkedAccounts", linkedAccounts);
    this->SetLinkedAccounts(std::move(linkedAccounts));

    ModelDictionaryEntryVector<PlayerLocation> locations{};
    JsonUtils::ObjectGetMember<PlayerLocation>(input, "Locations", locations);
    this->SetLocations(std::move(locations));

    StdExtra::optional<PFLoginIdentityProvider> origination{};
    JsonUtils::ObjectGetMember(input, "Origination", origination);
    this->SetOrigination(std::move(origination));

    CStringVector playerExperimentVariants{};
    JsonUtils::ObjectGetMember(input, "PlayerExperimentVariants", playerExperimentVariants);
    this->SetPlayerExperimentVariants(std::move(playerExperimentVariants));

    String playerId{};
    JsonUtils::ObjectGetMember(input, "PlayerId", playerId);
    this->SetPlayerId(std::move(playerId));

    ModelVector<PlayerStatistic> playerStatistics{};
    JsonUtils::ObjectGetMember<PlayerStatistic>(input, "PlayerStatistics", playerStatistics);
    this->SetPlayerStatistics(std::move(playerStatistics));

    String publisherId{};
    JsonUtils::ObjectGetMember(input, "PublisherId", publisherId);
    this->SetPublisherId(std::move(publisherId));

    ModelVector<PushNotificationRegistration> pushNotificationRegistrations{};
    JsonUtils::ObjectGetMember<PushNotificationRegistration>(input, "PushNotificationRegistrations", pushNotificationRegistrations);
    this->SetPushNotificationRegistrations(std::move(pushNotificationRegistrations));

    DictionaryEntryVector<PFInt32DictionaryEntry> statistics{};
    JsonUtils::ObjectGetMember(input, "Statistics", statistics);
    this->SetStatistics(std::move(statistics));

    CStringVector tags{};
    JsonUtils::ObjectGetMember(input, "Tags", tags);
    this->SetTags(std::move(tags));

    String titleId{};
    JsonUtils::ObjectGetMember(input, "TitleId", titleId);
    this->SetTitleId(std::move(titleId));

    StdExtra::optional<uint32_t> totalValueToDateInUSD{};
    JsonUtils::ObjectGetMember(input, "TotalValueToDateInUSD", totalValueToDateInUSD);
    this->SetTotalValueToDateInUSD(std::move(totalValueToDateInUSD));

    DictionaryEntryVector<PFUint32DictionaryEntry> valuesToDate{};
    JsonUtils::ObjectGetMember(input, "ValuesToDate", valuesToDate);
    this->SetValuesToDate(std::move(valuesToDate));

    DictionaryEntryVector<PFInt32DictionaryEntry> virtualCurrencyBalances{};
    JsonUtils::ObjectGetMember(input, "VirtualCurrencyBalances", virtualCurrencyBalances);
    this->SetVirtualCurrencyBalances(std::move(virtualCurrencyBalances));
}

size_t PlayerProfile::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayStreamPlayerProfile const*> PlayerProfile::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PlayerProfile>(&this->Model());
}

size_t PlayerProfile::RequiredBufferSize(const PFPlayStreamPlayerProfile& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlayStreamAdCampaignAttribution*) + sizeof(PFPlayStreamAdCampaignAttribution*) * model.adCampaignAttributionsCount);
    for (size_t i = 0; i < model.adCampaignAttributionsCount; ++i)
    {
        requiredSize += AdCampaignAttribution::RequiredBufferSize(*model.adCampaignAttributions[i]);
    }
    if (model.avatarUrl)
    {
        requiredSize += (std::strlen(model.avatarUrl) + 1);
    }
    if (model.bannedUntil)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    requiredSize += (alignof(PFPlayStreamContactEmailInfo*) + sizeof(PFPlayStreamContactEmailInfo*) * model.contactEmailAddressesCount);
    for (size_t i = 0; i < model.contactEmailAddressesCount; ++i)
    {
        requiredSize += ContactEmailInfo::RequiredBufferSize(*model.contactEmailAddresses[i]);
    }
    if (model.created)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.displayName)
    {
        requiredSize += (std::strlen(model.displayName) + 1);
    }
    if (model.lastLogin)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    requiredSize += (alignof(PFPlayStreamPlayerLinkedAccount*) + sizeof(PFPlayStreamPlayerLinkedAccount*) * model.linkedAccountsCount);
    for (size_t i = 0; i < model.linkedAccountsCount; ++i)
    {
        requiredSize += PlayerLinkedAccount::RequiredBufferSize(*model.linkedAccounts[i]);
    }
    requiredSize += (alignof(PFPlayStreamPlayerLocationDictionaryEntry) + sizeof(PFPlayStreamPlayerLocationDictionaryEntry) * model.locationsCount);
    for (size_t i = 0; i < model.locationsCount; ++i)
    {
        requiredSize += (std::strlen(model.locations[i].key) + 1);
        requiredSize += PlayerLocation::RequiredBufferSize(*model.locations[i].value);
    }
    if (model.origination)
    {
        requiredSize += (alignof(PFLoginIdentityProvider) + sizeof(PFLoginIdentityProvider));
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.playerExperimentVariantsCount);
    for (size_t i = 0; i < model.playerExperimentVariantsCount; ++i)
    {
        requiredSize += (std::strlen(model.playerExperimentVariants[i]) + 1);
    }
    if (model.playerId)
    {
        requiredSize += (std::strlen(model.playerId) + 1);
    }
    requiredSize += (alignof(PFPlayStreamPlayerStatistic*) + sizeof(PFPlayStreamPlayerStatistic*) * model.playerStatisticsCount);
    for (size_t i = 0; i < model.playerStatisticsCount; ++i)
    {
        requiredSize += PlayerStatistic::RequiredBufferSize(*model.playerStatistics[i]);
    }
    if (model.publisherId)
    {
        requiredSize += (std::strlen(model.publisherId) + 1);
    }
    requiredSize += (alignof(PFPlayStreamPushNotificationRegistration*) + sizeof(PFPlayStreamPushNotificationRegistration*) * model.pushNotificationRegistrationsCount);
    for (size_t i = 0; i < model.pushNotificationRegistrationsCount; ++i)
    {
        requiredSize += PushNotificationRegistration::RequiredBufferSize(*model.pushNotificationRegistrations[i]);
    }
    requiredSize += (alignof(PFInt32DictionaryEntry) + sizeof(PFInt32DictionaryEntry) * model.statisticsCount);
    for (size_t i = 0; i < model.statisticsCount; ++i)
    {
        requiredSize += (std::strlen(model.statistics[i].key) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.tagsCount);
    for (size_t i = 0; i < model.tagsCount; ++i)
    {
        requiredSize += (std::strlen(model.tags[i]) + 1);
    }
    if (model.titleId)
    {
        requiredSize += (std::strlen(model.titleId) + 1);
    }
    if (model.totalValueToDateInUSD)
    {
        requiredSize += (alignof(uint32_t) + sizeof(uint32_t));
    }
    requiredSize += (alignof(PFUint32DictionaryEntry) + sizeof(PFUint32DictionaryEntry) * model.valuesToDateCount);
    for (size_t i = 0; i < model.valuesToDateCount; ++i)
    {
        requiredSize += (std::strlen(model.valuesToDate[i].key) + 1);
    }
    requiredSize += (alignof(PFInt32DictionaryEntry) + sizeof(PFInt32DictionaryEntry) * model.virtualCurrencyBalancesCount);
    for (size_t i = 0; i < model.virtualCurrencyBalancesCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrencyBalances[i].key) + 1);
    }
    return requiredSize;
}

HRESULT PlayerProfile::Copy(const PFPlayStreamPlayerProfile& input, PFPlayStreamPlayerProfile& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<AdCampaignAttribution>(input.adCampaignAttributions, input.adCampaignAttributionsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.adCampaignAttributions = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.avatarUrl); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.avatarUrl = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.bannedUntil); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.bannedUntil = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<ContactEmailInfo>(input.contactEmailAddresses, input.contactEmailAddressesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.contactEmailAddresses = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.created); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.created = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.displayName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.displayName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.lastLogin); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.lastLogin = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<PlayerLinkedAccount>(input.linkedAccounts, input.linkedAccountsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.linkedAccounts = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary<PlayerLocation>(input.locations, input.locationsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.locations = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.origination); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.origination = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.playerExperimentVariants, input.playerExperimentVariantsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playerExperimentVariants = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playerId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playerId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<PlayerStatistic>(input.playerStatistics, input.playerStatisticsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playerStatistics = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.publisherId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.publisherId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<PushNotificationRegistration>(input.pushNotificationRegistrations, input.pushNotificationRegistrationsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.pushNotificationRegistrations = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.statistics, input.statisticsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.statistics = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.tags, input.tagsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.tags = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.titleId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.titleId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.totalValueToDateInUSD); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.totalValueToDateInUSD = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.valuesToDate, input.valuesToDateCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.valuesToDate = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.virtualCurrencyBalances, input.virtualCurrencyBalancesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrencyBalances = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetPlayersInSegmentResult::FromJson(const JsonValue& input)
{
    String continuationToken{};
    JsonUtils::ObjectGetMember(input, "ContinuationToken", continuationToken);
    this->SetContinuationToken(std::move(continuationToken));

    ModelVector<PlayerProfile> playerProfiles{};
    JsonUtils::ObjectGetMember<PlayerProfile>(input, "PlayerProfiles", playerProfiles);
    this->SetPlayerProfiles(std::move(playerProfiles));

    JsonUtils::ObjectGetMember(input, "ProfilesInSegment", this->m_model.profilesInSegment);
}

size_t GetPlayersInSegmentResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayStreamGetPlayersInSegmentResult const*> GetPlayersInSegmentResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayersInSegmentResult>(&this->Model());
}

size_t GetPlayersInSegmentResult::RequiredBufferSize(const PFPlayStreamGetPlayersInSegmentResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.continuationToken)
    {
        requiredSize += (std::strlen(model.continuationToken) + 1);
    }
    requiredSize += (alignof(PFPlayStreamPlayerProfile*) + sizeof(PFPlayStreamPlayerProfile*) * model.playerProfilesCount);
    for (size_t i = 0; i < model.playerProfilesCount; ++i)
    {
        requiredSize += PlayerProfile::RequiredBufferSize(*model.playerProfiles[i]);
    }
    return requiredSize;
}

HRESULT GetPlayersInSegmentResult::Copy(const PFPlayStreamGetPlayersInSegmentResult& input, PFPlayStreamGetPlayersInSegmentResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.continuationToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.continuationToken = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<PlayerProfile>(input.playerProfiles, input.playerProfilesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playerProfiles = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPlayerTagsRequest::ToJson() const
{
    return GetPlayerTagsRequest::ToJson(this->Model());
}

JsonValue GetPlayerTagsRequest::ToJson(const PFPlayStreamGetPlayerTagsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Namespace", input.playfabNamespace);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void GetPlayerTagsResult::FromJson(const JsonValue& input)
{
    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    CStringVector tags{};
    JsonUtils::ObjectGetMember(input, "Tags", tags);
    this->SetTags(std::move(tags));
}

size_t GetPlayerTagsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayStreamGetPlayerTagsResult const*> GetPlayerTagsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPlayerTagsResult>(&this->Model());
}

size_t GetPlayerTagsResult::RequiredBufferSize(const PFPlayStreamGetPlayerTagsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.tagsCount);
    for (size_t i = 0; i < model.tagsCount; ++i)
    {
        requiredSize += (std::strlen(model.tags[i]) + 1);
    }
    return requiredSize;
}

HRESULT GetPlayerTagsResult::Copy(const PFPlayStreamGetPlayerTagsResult& input, PFPlayStreamGetPlayerTagsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.tags, input.tagsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.tags = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RemovePlayerTagRequest::ToJson() const
{
    return RemovePlayerTagRequest::ToJson(this->Model());
}

JsonValue RemovePlayerTagRequest::ToJson(const PFPlayStreamRemovePlayerTagRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "TagName", input.tagName);
    return output;
}

JsonValue EventContents::ToJson() const
{
    return EventContents::ToJson(this->Model());
}

JsonValue EventContents::ToJson(const PFPlayStreamEventContents& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "EventNamespace", input.eventNamespace);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    JsonUtils::ObjectAddMember(output, "OriginalId", input.originalId);
    JsonUtils::ObjectAddMemberTime(output, "OriginalTimestamp", input.originalTimestamp);
    JsonUtils::ObjectAddMember(output, "Payload", input.payload);
    JsonUtils::ObjectAddMember(output, "PayloadJSON", input.payloadJSON);
    return output;
}

JsonValue WriteEventsRequest::ToJson() const
{
    return WriteEventsRequest::ToJson(this->Model());
}

JsonValue WriteEventsRequest::ToJson(const PFPlayStreamWriteEventsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray<EventContents>(output, "Events", input.events, input.eventsCount);
    return output;
}

void WriteEventsResponse::FromJson(const JsonValue& input)
{
    CStringVector assignedEventIds{};
    JsonUtils::ObjectGetMember(input, "AssignedEventIds", assignedEventIds);
    this->SetAssignedEventIds(std::move(assignedEventIds));
}

size_t WriteEventsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayStreamWriteEventsResponse const*> WriteEventsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<WriteEventsResponse>(&this->Model());
}

size_t WriteEventsResponse::RequiredBufferSize(const PFPlayStreamWriteEventsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(char*) + sizeof(char*) * model.assignedEventIdsCount);
    for (size_t i = 0; i < model.assignedEventIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.assignedEventIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT WriteEventsResponse::Copy(const PFPlayStreamWriteEventsResponse& input, PFPlayStreamWriteEventsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray(input.assignedEventIds, input.assignedEventIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.assignedEventIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

} // namespace PlayStream
} // namespace PlayFab
