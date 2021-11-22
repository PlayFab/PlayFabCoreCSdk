#include "stdafx.h"
#include "AdvertisingDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Advertising
{

JsonValue AttributeInstallRequest::ToJson() const
{
    return AttributeInstallRequest::ToJson(this->Model());
}

JsonValue AttributeInstallRequest::ToJson(const PFAdvertisingAttributeInstallRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Adid", input.adid);
    JsonUtils::ObjectAddMember(output, "Idfa", input.idfa);
    return output;
}

JsonValue GetAdPlacementsRequest::ToJson() const
{
    return GetAdPlacementsRequest::ToJson(this->Model());
}

JsonValue GetAdPlacementsRequest::ToJson(const PFAdvertisingGetAdPlacementsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AppId", input.appId);
    JsonUtils::ObjectAddMember<NameIdentifier>(output, "Identifier", input.identifier);
    return output;
}

void AdPlacementDetails::FromJson(const JsonValue& input)
{
    String placementId{};
    JsonUtils::ObjectGetMember(input, "PlacementId", placementId);
    this->SetPlacementId(std::move(placementId));

    String placementName{};
    JsonUtils::ObjectGetMember(input, "PlacementName", placementName);
    this->SetPlacementName(std::move(placementName));

    StdExtra::optional<int32_t> placementViewsRemaining{};
    JsonUtils::ObjectGetMember(input, "PlacementViewsRemaining", placementViewsRemaining);
    this->SetPlacementViewsRemaining(std::move(placementViewsRemaining));

    StdExtra::optional<double> placementViewsResetMinutes{};
    JsonUtils::ObjectGetMember(input, "PlacementViewsResetMinutes", placementViewsResetMinutes);
    this->SetPlacementViewsResetMinutes(std::move(placementViewsResetMinutes));

    String rewardAssetUrl{};
    JsonUtils::ObjectGetMember(input, "RewardAssetUrl", rewardAssetUrl);
    this->SetRewardAssetUrl(std::move(rewardAssetUrl));

    String rewardDescription{};
    JsonUtils::ObjectGetMember(input, "RewardDescription", rewardDescription);
    this->SetRewardDescription(std::move(rewardDescription));

    String rewardId{};
    JsonUtils::ObjectGetMember(input, "RewardId", rewardId);
    this->SetRewardId(std::move(rewardId));

    String rewardName{};
    JsonUtils::ObjectGetMember(input, "RewardName", rewardName);
    this->SetRewardName(std::move(rewardName));
}

size_t AdPlacementDetails::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAdvertisingAdPlacementDetails const*> AdPlacementDetails::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AdPlacementDetails>(&this->Model());
}

size_t AdPlacementDetails::RequiredBufferSize(const PFAdvertisingAdPlacementDetails& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.placementId)
    {
        requiredSize += (std::strlen(model.placementId) + 1);
    }
    if (model.placementName)
    {
        requiredSize += (std::strlen(model.placementName) + 1);
    }
    if (model.placementViewsRemaining)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    if (model.placementViewsResetMinutes)
    {
        requiredSize += (alignof(double) + sizeof(double));
    }
    if (model.rewardAssetUrl)
    {
        requiredSize += (std::strlen(model.rewardAssetUrl) + 1);
    }
    if (model.rewardDescription)
    {
        requiredSize += (std::strlen(model.rewardDescription) + 1);
    }
    if (model.rewardId)
    {
        requiredSize += (std::strlen(model.rewardId) + 1);
    }
    if (model.rewardName)
    {
        requiredSize += (std::strlen(model.rewardName) + 1);
    }
    return requiredSize;
}

HRESULT AdPlacementDetails::Copy(const PFAdvertisingAdPlacementDetails& input, PFAdvertisingAdPlacementDetails& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.placementId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.placementId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.placementName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.placementName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.placementViewsRemaining); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.placementViewsRemaining = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.placementViewsResetMinutes); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.placementViewsResetMinutes = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.rewardAssetUrl); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.rewardAssetUrl = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.rewardDescription); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.rewardDescription = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.rewardId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.rewardId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.rewardName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.rewardName = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetAdPlacementsResult::FromJson(const JsonValue& input)
{
    ModelVector<AdPlacementDetails> adPlacements{};
    JsonUtils::ObjectGetMember<AdPlacementDetails>(input, "AdPlacements", adPlacements);
    this->SetAdPlacements(std::move(adPlacements));
}

size_t GetAdPlacementsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAdvertisingGetAdPlacementsResult const*> GetAdPlacementsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetAdPlacementsResult>(&this->Model());
}

size_t GetAdPlacementsResult::RequiredBufferSize(const PFAdvertisingGetAdPlacementsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAdvertisingAdPlacementDetails*) + sizeof(PFAdvertisingAdPlacementDetails*) * model.adPlacementsCount);
    for (size_t i = 0; i < model.adPlacementsCount; ++i)
    {
        requiredSize += AdPlacementDetails::RequiredBufferSize(*model.adPlacements[i]);
    }
    return requiredSize;
}

HRESULT GetAdPlacementsResult::Copy(const PFAdvertisingGetAdPlacementsResult& input, PFAdvertisingGetAdPlacementsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<AdPlacementDetails>(input.adPlacements, input.adPlacementsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.adPlacements = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ReportAdActivityRequest::ToJson() const
{
    return ReportAdActivityRequest::ToJson(this->Model());
}

JsonValue ReportAdActivityRequest::ToJson(const PFAdvertisingReportAdActivityRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Activity", input.activity);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlacementId", input.placementId);
    JsonUtils::ObjectAddMember(output, "RewardId", input.rewardId);
    return output;
}

JsonValue RewardAdActivityRequest::ToJson() const
{
    return RewardAdActivityRequest::ToJson(this->Model());
}

JsonValue RewardAdActivityRequest::ToJson(const PFAdvertisingRewardAdActivityRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlacementId", input.placementId);
    JsonUtils::ObjectAddMember(output, "RewardId", input.rewardId);
    return output;
}

void AdRewardItemGranted::FromJson(const JsonValue& input)
{
    String catalogId{};
    JsonUtils::ObjectGetMember(input, "CatalogId", catalogId);
    this->SetCatalogId(std::move(catalogId));

    String displayName{};
    JsonUtils::ObjectGetMember(input, "DisplayName", displayName);
    this->SetDisplayName(std::move(displayName));

    String instanceId{};
    JsonUtils::ObjectGetMember(input, "InstanceId", instanceId);
    this->SetInstanceId(std::move(instanceId));

    String itemId{};
    JsonUtils::ObjectGetMember(input, "ItemId", itemId);
    this->SetItemId(std::move(itemId));
}

size_t AdRewardItemGranted::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAdvertisingAdRewardItemGranted const*> AdRewardItemGranted::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AdRewardItemGranted>(&this->Model());
}

size_t AdRewardItemGranted::RequiredBufferSize(const PFAdvertisingAdRewardItemGranted& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.catalogId)
    {
        requiredSize += (std::strlen(model.catalogId) + 1);
    }
    if (model.displayName)
    {
        requiredSize += (std::strlen(model.displayName) + 1);
    }
    if (model.instanceId)
    {
        requiredSize += (std::strlen(model.instanceId) + 1);
    }
    if (model.itemId)
    {
        requiredSize += (std::strlen(model.itemId) + 1);
    }
    return requiredSize;
}

HRESULT AdRewardItemGranted::Copy(const PFAdvertisingAdRewardItemGranted& input, PFAdvertisingAdRewardItemGranted& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.catalogId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.catalogId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.displayName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.displayName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.instanceId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.instanceId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.itemId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void AdRewardResults::FromJson(const JsonValue& input)
{
    ModelVector<AdRewardItemGranted> grantedItems{};
    JsonUtils::ObjectGetMember<AdRewardItemGranted>(input, "GrantedItems", grantedItems);
    this->SetGrantedItems(std::move(grantedItems));

    DictionaryEntryVector<PFInt32DictionaryEntry> grantedVirtualCurrencies{};
    JsonUtils::ObjectGetMember(input, "GrantedVirtualCurrencies", grantedVirtualCurrencies);
    this->SetGrantedVirtualCurrencies(std::move(grantedVirtualCurrencies));

    DictionaryEntryVector<PFInt32DictionaryEntry> incrementedStatistics{};
    JsonUtils::ObjectGetMember(input, "IncrementedStatistics", incrementedStatistics);
    this->SetIncrementedStatistics(std::move(incrementedStatistics));
}

size_t AdRewardResults::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAdvertisingAdRewardResults const*> AdRewardResults::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AdRewardResults>(&this->Model());
}

size_t AdRewardResults::RequiredBufferSize(const PFAdvertisingAdRewardResults& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFAdvertisingAdRewardItemGranted*) + sizeof(PFAdvertisingAdRewardItemGranted*) * model.grantedItemsCount);
    for (size_t i = 0; i < model.grantedItemsCount; ++i)
    {
        requiredSize += AdRewardItemGranted::RequiredBufferSize(*model.grantedItems[i]);
    }
    requiredSize += (alignof(PFInt32DictionaryEntry) + sizeof(PFInt32DictionaryEntry) * model.grantedVirtualCurrenciesCount);
    for (size_t i = 0; i < model.grantedVirtualCurrenciesCount; ++i)
    {
        requiredSize += (std::strlen(model.grantedVirtualCurrencies[i].key) + 1);
    }
    requiredSize += (alignof(PFInt32DictionaryEntry) + sizeof(PFInt32DictionaryEntry) * model.incrementedStatisticsCount);
    for (size_t i = 0; i < model.incrementedStatisticsCount; ++i)
    {
        requiredSize += (std::strlen(model.incrementedStatistics[i].key) + 1);
    }
    return requiredSize;
}

HRESULT AdRewardResults::Copy(const PFAdvertisingAdRewardResults& input, PFAdvertisingAdRewardResults& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<AdRewardItemGranted>(input.grantedItems, input.grantedItemsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.grantedItems = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.grantedVirtualCurrencies, input.grantedVirtualCurrenciesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.grantedVirtualCurrencies = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.incrementedStatistics, input.incrementedStatisticsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.incrementedStatistics = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void RewardAdActivityResult::FromJson(const JsonValue& input)
{
    String adActivityEventId{};
    JsonUtils::ObjectGetMember(input, "AdActivityEventId", adActivityEventId);
    this->SetAdActivityEventId(std::move(adActivityEventId));

    CStringVector debugResults{};
    JsonUtils::ObjectGetMember(input, "DebugResults", debugResults);
    this->SetDebugResults(std::move(debugResults));

    String placementId{};
    JsonUtils::ObjectGetMember(input, "PlacementId", placementId);
    this->SetPlacementId(std::move(placementId));

    String placementName{};
    JsonUtils::ObjectGetMember(input, "PlacementName", placementName);
    this->SetPlacementName(std::move(placementName));

    StdExtra::optional<int32_t> placementViewsRemaining{};
    JsonUtils::ObjectGetMember(input, "PlacementViewsRemaining", placementViewsRemaining);
    this->SetPlacementViewsRemaining(std::move(placementViewsRemaining));

    StdExtra::optional<double> placementViewsResetMinutes{};
    JsonUtils::ObjectGetMember(input, "PlacementViewsResetMinutes", placementViewsResetMinutes);
    this->SetPlacementViewsResetMinutes(std::move(placementViewsResetMinutes));

    StdExtra::optional<AdRewardResults> rewardResults{};
    JsonUtils::ObjectGetMember(input, "RewardResults", rewardResults);
    if (rewardResults)
    {
        this->SetRewardResults(std::move(*rewardResults));
    }
}

size_t RewardAdActivityResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFAdvertisingRewardAdActivityResult const*> RewardAdActivityResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RewardAdActivityResult>(&this->Model());
}

size_t RewardAdActivityResult::RequiredBufferSize(const PFAdvertisingRewardAdActivityResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.adActivityEventId)
    {
        requiredSize += (std::strlen(model.adActivityEventId) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.debugResultsCount);
    for (size_t i = 0; i < model.debugResultsCount; ++i)
    {
        requiredSize += (std::strlen(model.debugResults[i]) + 1);
    }
    if (model.placementId)
    {
        requiredSize += (std::strlen(model.placementId) + 1);
    }
    if (model.placementName)
    {
        requiredSize += (std::strlen(model.placementName) + 1);
    }
    if (model.placementViewsRemaining)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    if (model.placementViewsResetMinutes)
    {
        requiredSize += (alignof(double) + sizeof(double));
    }
    if (model.rewardResults)
    {
        requiredSize += AdRewardResults::RequiredBufferSize(*model.rewardResults);
    }
    return requiredSize;
}

HRESULT RewardAdActivityResult::Copy(const PFAdvertisingRewardAdActivityResult& input, PFAdvertisingRewardAdActivityResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.adActivityEventId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.adActivityEventId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.debugResults, input.debugResultsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.debugResults = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.placementId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.placementId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.placementName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.placementName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.placementViewsRemaining); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.placementViewsRemaining = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.placementViewsResetMinutes); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.placementViewsResetMinutes = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<AdRewardResults>(input.rewardResults); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.rewardResults = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

} // namespace Advertising
} // namespace PlayFab
