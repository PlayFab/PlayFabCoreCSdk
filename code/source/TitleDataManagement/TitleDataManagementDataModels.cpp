#include "stdafx.h"
#include "TitleDataManagementDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace TitleDataManagement
{

JsonValue AddLocalizedNewsRequest::ToJson() const
{
    return AddLocalizedNewsRequest::ToJson(this->Model());
}

JsonValue AddLocalizedNewsRequest::ToJson(const PFTitleDataManagementAddLocalizedNewsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Body", input.body);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Language", input.language);
    JsonUtils::ObjectAddMember(output, "NewsId", input.newsId);
    JsonUtils::ObjectAddMember(output, "Title", input.title);
    return output;
}

JsonValue AddNewsRequest::ToJson() const
{
    return AddNewsRequest::ToJson(this->Model());
}

JsonValue AddNewsRequest::ToJson(const PFTitleDataManagementAddNewsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Body", input.body);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberTime(output, "Timestamp", input.timestamp);
    JsonUtils::ObjectAddMember(output, "Title", input.title);
    return output;
}

void AddNewsResult::FromJson(const JsonValue& input)
{
    String newsId{};
    JsonUtils::ObjectGetMember(input, "NewsId", newsId);
    this->SetNewsId(std::move(newsId));
}

size_t AddNewsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFTitleDataManagementAddNewsResult const*> AddNewsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AddNewsResult>(&this->Model());
}

size_t AddNewsResult::RequiredBufferSize(const PFTitleDataManagementAddNewsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.newsId)
    {
        requiredSize += (std::strlen(model.newsId) + 1);
    }
    return requiredSize;
}

HRESULT AddNewsResult::Copy(const PFTitleDataManagementAddNewsResult& input, PFTitleDataManagementAddNewsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.newsId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.newsId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue VirtualCurrencyData::ToJson() const
{
    return VirtualCurrencyData::ToJson(this->Model());
}

JsonValue VirtualCurrencyData::ToJson(const PFTitleDataManagementVirtualCurrencyData& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CurrencyCode", input.currencyCode);
    JsonUtils::ObjectAddMember(output, "DisplayName", input.displayName);
    JsonUtils::ObjectAddMember(output, "InitialDeposit", input.initialDeposit);
    JsonUtils::ObjectAddMember(output, "RechargeMax", input.rechargeMax);
    JsonUtils::ObjectAddMember(output, "RechargeRate", input.rechargeRate);
    return output;
}

void VirtualCurrencyData::FromJson(const JsonValue& input)
{
    String currencyCode{};
    JsonUtils::ObjectGetMember(input, "CurrencyCode", currencyCode);
    this->SetCurrencyCode(std::move(currencyCode));

    String displayName{};
    JsonUtils::ObjectGetMember(input, "DisplayName", displayName);
    this->SetDisplayName(std::move(displayName));

    StdExtra::optional<int32_t> initialDeposit{};
    JsonUtils::ObjectGetMember(input, "InitialDeposit", initialDeposit);
    this->SetInitialDeposit(std::move(initialDeposit));

    StdExtra::optional<int32_t> rechargeMax{};
    JsonUtils::ObjectGetMember(input, "RechargeMax", rechargeMax);
    this->SetRechargeMax(std::move(rechargeMax));

    StdExtra::optional<int32_t> rechargeRate{};
    JsonUtils::ObjectGetMember(input, "RechargeRate", rechargeRate);
    this->SetRechargeRate(std::move(rechargeRate));
}

size_t VirtualCurrencyData::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFTitleDataManagementVirtualCurrencyData const*> VirtualCurrencyData::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<VirtualCurrencyData>(&this->Model());
}

size_t VirtualCurrencyData::RequiredBufferSize(const PFTitleDataManagementVirtualCurrencyData& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.currencyCode)
    {
        requiredSize += (std::strlen(model.currencyCode) + 1);
    }
    if (model.displayName)
    {
        requiredSize += (std::strlen(model.displayName) + 1);
    }
    if (model.initialDeposit)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    if (model.rechargeMax)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    if (model.rechargeRate)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    return requiredSize;
}

HRESULT VirtualCurrencyData::Copy(const PFTitleDataManagementVirtualCurrencyData& input, PFTitleDataManagementVirtualCurrencyData& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.currencyCode); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.currencyCode = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.displayName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.displayName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.initialDeposit); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.initialDeposit = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.rechargeMax); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.rechargeMax = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.rechargeRate); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.rechargeRate = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue AddVirtualCurrencyTypesRequest::ToJson() const
{
    return AddVirtualCurrencyTypesRequest::ToJson(this->Model());
}

JsonValue AddVirtualCurrencyTypesRequest::ToJson(const PFTitleDataManagementAddVirtualCurrencyTypesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray<VirtualCurrencyData>(output, "VirtualCurrencies", input.virtualCurrencies, input.virtualCurrenciesCount);
    return output;
}

JsonValue DeleteStoreRequest::ToJson() const
{
    return DeleteStoreRequest::ToJson(this->Model());
}

JsonValue DeleteStoreRequest::ToJson(const PFTitleDataManagementDeleteStoreRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "StoreId", input.storeId);
    return output;
}

JsonValue DeleteTitleDataOverrideRequest::ToJson() const
{
    return DeleteTitleDataOverrideRequest::ToJson(this->Model());
}

JsonValue DeleteTitleDataOverrideRequest::ToJson(const PFTitleDataManagementDeleteTitleDataOverrideRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "OverrideLabel", input.overrideLabel);
    return output;
}

JsonValue GetCatalogItemsRequest::ToJson() const
{
    return GetCatalogItemsRequest::ToJson(this->Model());
}

JsonValue GetCatalogItemsRequest::ToJson(const PFTitleDataManagementGetCatalogItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    return output;
}

JsonValue CatalogItemBundleInfo::ToJson() const
{
    return CatalogItemBundleInfo::ToJson(this->Model());
}

JsonValue CatalogItemBundleInfo::ToJson(const PFTitleDataManagementCatalogItemBundleInfo& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "BundledItems", input.bundledItems, input.bundledItemsCount);
    JsonUtils::ObjectAddMemberArray(output, "BundledResultTables", input.bundledResultTables, input.bundledResultTablesCount);
    JsonUtils::ObjectAddMemberDictionary(output, "BundledVirtualCurrencies", input.bundledVirtualCurrencies, input.bundledVirtualCurrenciesCount);
    return output;
}

void CatalogItemBundleInfo::FromJson(const JsonValue& input)
{
    CStringVector bundledItems{};
    JsonUtils::ObjectGetMember(input, "BundledItems", bundledItems);
    this->SetBundledItems(std::move(bundledItems));

    CStringVector bundledResultTables{};
    JsonUtils::ObjectGetMember(input, "BundledResultTables", bundledResultTables);
    this->SetBundledResultTables(std::move(bundledResultTables));

    DictionaryEntryVector<PFUint32DictionaryEntry> bundledVirtualCurrencies{};
    JsonUtils::ObjectGetMember(input, "BundledVirtualCurrencies", bundledVirtualCurrencies);
    this->SetBundledVirtualCurrencies(std::move(bundledVirtualCurrencies));
}

size_t CatalogItemBundleInfo::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFTitleDataManagementCatalogItemBundleInfo const*> CatalogItemBundleInfo::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CatalogItemBundleInfo>(&this->Model());
}

size_t CatalogItemBundleInfo::RequiredBufferSize(const PFTitleDataManagementCatalogItemBundleInfo& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(char*) + sizeof(char*) * model.bundledItemsCount);
    for (size_t i = 0; i < model.bundledItemsCount; ++i)
    {
        requiredSize += (std::strlen(model.bundledItems[i]) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.bundledResultTablesCount);
    for (size_t i = 0; i < model.bundledResultTablesCount; ++i)
    {
        requiredSize += (std::strlen(model.bundledResultTables[i]) + 1);
    }
    requiredSize += (alignof(PFUint32DictionaryEntry) + sizeof(PFUint32DictionaryEntry) * model.bundledVirtualCurrenciesCount);
    for (size_t i = 0; i < model.bundledVirtualCurrenciesCount; ++i)
    {
        requiredSize += (std::strlen(model.bundledVirtualCurrencies[i].key) + 1);
    }
    return requiredSize;
}

HRESULT CatalogItemBundleInfo::Copy(const PFTitleDataManagementCatalogItemBundleInfo& input, PFTitleDataManagementCatalogItemBundleInfo& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray(input.bundledItems, input.bundledItemsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.bundledItems = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.bundledResultTables, input.bundledResultTablesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.bundledResultTables = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.bundledVirtualCurrencies, input.bundledVirtualCurrenciesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.bundledVirtualCurrencies = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CatalogItemConsumableInfo::ToJson() const
{
    return CatalogItemConsumableInfo::ToJson(this->Model());
}

JsonValue CatalogItemConsumableInfo::ToJson(const PFTitleDataManagementCatalogItemConsumableInfo& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "UsageCount", input.usageCount);
    JsonUtils::ObjectAddMember(output, "UsagePeriod", input.usagePeriod);
    JsonUtils::ObjectAddMember(output, "UsagePeriodGroup", input.usagePeriodGroup);
    return output;
}

void CatalogItemConsumableInfo::FromJson(const JsonValue& input)
{
    StdExtra::optional<uint32_t> usageCount{};
    JsonUtils::ObjectGetMember(input, "UsageCount", usageCount);
    this->SetUsageCount(std::move(usageCount));

    StdExtra::optional<uint32_t> usagePeriod{};
    JsonUtils::ObjectGetMember(input, "UsagePeriod", usagePeriod);
    this->SetUsagePeriod(std::move(usagePeriod));

    String usagePeriodGroup{};
    JsonUtils::ObjectGetMember(input, "UsagePeriodGroup", usagePeriodGroup);
    this->SetUsagePeriodGroup(std::move(usagePeriodGroup));
}

size_t CatalogItemConsumableInfo::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFTitleDataManagementCatalogItemConsumableInfo const*> CatalogItemConsumableInfo::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CatalogItemConsumableInfo>(&this->Model());
}

size_t CatalogItemConsumableInfo::RequiredBufferSize(const PFTitleDataManagementCatalogItemConsumableInfo& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.usageCount)
    {
        requiredSize += (alignof(uint32_t) + sizeof(uint32_t));
    }
    if (model.usagePeriod)
    {
        requiredSize += (alignof(uint32_t) + sizeof(uint32_t));
    }
    if (model.usagePeriodGroup)
    {
        requiredSize += (std::strlen(model.usagePeriodGroup) + 1);
    }
    return requiredSize;
}

HRESULT CatalogItemConsumableInfo::Copy(const PFTitleDataManagementCatalogItemConsumableInfo& input, PFTitleDataManagementCatalogItemConsumableInfo& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.usageCount); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.usageCount = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.usagePeriod); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.usagePeriod = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.usagePeriodGroup); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.usagePeriodGroup = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CatalogItemContainerInfo::ToJson() const
{
    return CatalogItemContainerInfo::ToJson(this->Model());
}

JsonValue CatalogItemContainerInfo::ToJson(const PFTitleDataManagementCatalogItemContainerInfo& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "ItemContents", input.itemContents, input.itemContentsCount);
    JsonUtils::ObjectAddMember(output, "KeyItemId", input.keyItemId);
    JsonUtils::ObjectAddMemberArray(output, "ResultTableContents", input.resultTableContents, input.resultTableContentsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "VirtualCurrencyContents", input.virtualCurrencyContents, input.virtualCurrencyContentsCount);
    return output;
}

void CatalogItemContainerInfo::FromJson(const JsonValue& input)
{
    CStringVector itemContents{};
    JsonUtils::ObjectGetMember(input, "ItemContents", itemContents);
    this->SetItemContents(std::move(itemContents));

    String keyItemId{};
    JsonUtils::ObjectGetMember(input, "KeyItemId", keyItemId);
    this->SetKeyItemId(std::move(keyItemId));

    CStringVector resultTableContents{};
    JsonUtils::ObjectGetMember(input, "ResultTableContents", resultTableContents);
    this->SetResultTableContents(std::move(resultTableContents));

    DictionaryEntryVector<PFUint32DictionaryEntry> virtualCurrencyContents{};
    JsonUtils::ObjectGetMember(input, "VirtualCurrencyContents", virtualCurrencyContents);
    this->SetVirtualCurrencyContents(std::move(virtualCurrencyContents));
}

size_t CatalogItemContainerInfo::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFTitleDataManagementCatalogItemContainerInfo const*> CatalogItemContainerInfo::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CatalogItemContainerInfo>(&this->Model());
}

size_t CatalogItemContainerInfo::RequiredBufferSize(const PFTitleDataManagementCatalogItemContainerInfo& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(char*) + sizeof(char*) * model.itemContentsCount);
    for (size_t i = 0; i < model.itemContentsCount; ++i)
    {
        requiredSize += (std::strlen(model.itemContents[i]) + 1);
    }
    if (model.keyItemId)
    {
        requiredSize += (std::strlen(model.keyItemId) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.resultTableContentsCount);
    for (size_t i = 0; i < model.resultTableContentsCount; ++i)
    {
        requiredSize += (std::strlen(model.resultTableContents[i]) + 1);
    }
    requiredSize += (alignof(PFUint32DictionaryEntry) + sizeof(PFUint32DictionaryEntry) * model.virtualCurrencyContentsCount);
    for (size_t i = 0; i < model.virtualCurrencyContentsCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrencyContents[i].key) + 1);
    }
    return requiredSize;
}

HRESULT CatalogItemContainerInfo::Copy(const PFTitleDataManagementCatalogItemContainerInfo& input, PFTitleDataManagementCatalogItemContainerInfo& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray(input.itemContents, input.itemContentsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemContents = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.keyItemId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.keyItemId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.resultTableContents, input.resultTableContentsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.resultTableContents = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.virtualCurrencyContents, input.virtualCurrencyContentsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrencyContents = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CatalogItem::ToJson() const
{
    return CatalogItem::ToJson(this->Model());
}

JsonValue CatalogItem::ToJson(const PFTitleDataManagementCatalogItem& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<CatalogItemBundleInfo>(output, "Bundle", input.bundle);
    JsonUtils::ObjectAddMember(output, "CanBecomeCharacter", input.canBecomeCharacter);
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember<CatalogItemConsumableInfo>(output, "Consumable", input.consumable);
    JsonUtils::ObjectAddMember<CatalogItemContainerInfo>(output, "Container", input.container);
    JsonUtils::ObjectAddMember(output, "CustomData", input.customData);
    JsonUtils::ObjectAddMember(output, "Description", input.description);
    JsonUtils::ObjectAddMember(output, "DisplayName", input.displayName);
    JsonUtils::ObjectAddMember(output, "InitialLimitedEditionCount", input.initialLimitedEditionCount);
    JsonUtils::ObjectAddMember(output, "IsLimitedEdition", input.isLimitedEdition);
    JsonUtils::ObjectAddMember(output, "IsStackable", input.isStackable);
    JsonUtils::ObjectAddMember(output, "IsTradable", input.isTradable);
    JsonUtils::ObjectAddMember(output, "ItemClass", input.itemClass);
    JsonUtils::ObjectAddMember(output, "ItemId", input.itemId);
    JsonUtils::ObjectAddMember(output, "ItemImageUrl", input.itemImageUrl);
    JsonUtils::ObjectAddMemberDictionary(output, "RealCurrencyPrices", input.realCurrencyPrices, input.realCurrencyPricesCount);
    JsonUtils::ObjectAddMemberArray(output, "Tags", input.tags, input.tagsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "VirtualCurrencyPrices", input.virtualCurrencyPrices, input.virtualCurrencyPricesCount);
    return output;
}

void CatalogItem::FromJson(const JsonValue& input)
{
    StdExtra::optional<CatalogItemBundleInfo> bundle{};
    JsonUtils::ObjectGetMember(input, "Bundle", bundle);
    if (bundle)
    {
        this->SetBundle(std::move(*bundle));
    }

    JsonUtils::ObjectGetMember(input, "CanBecomeCharacter", this->m_model.canBecomeCharacter);

    String catalogVersion{};
    JsonUtils::ObjectGetMember(input, "CatalogVersion", catalogVersion);
    this->SetCatalogVersion(std::move(catalogVersion));

    StdExtra::optional<CatalogItemConsumableInfo> consumable{};
    JsonUtils::ObjectGetMember(input, "Consumable", consumable);
    if (consumable)
    {
        this->SetConsumable(std::move(*consumable));
    }

    StdExtra::optional<CatalogItemContainerInfo> container{};
    JsonUtils::ObjectGetMember(input, "Container", container);
    if (container)
    {
        this->SetContainer(std::move(*container));
    }

    String customData{};
    JsonUtils::ObjectGetMember(input, "CustomData", customData);
    this->SetCustomData(std::move(customData));

    String description{};
    JsonUtils::ObjectGetMember(input, "Description", description);
    this->SetDescription(std::move(description));

    String displayName{};
    JsonUtils::ObjectGetMember(input, "DisplayName", displayName);
    this->SetDisplayName(std::move(displayName));

    JsonUtils::ObjectGetMember(input, "InitialLimitedEditionCount", this->m_model.initialLimitedEditionCount);

    JsonUtils::ObjectGetMember(input, "IsLimitedEdition", this->m_model.isLimitedEdition);

    JsonUtils::ObjectGetMember(input, "IsStackable", this->m_model.isStackable);

    JsonUtils::ObjectGetMember(input, "IsTradable", this->m_model.isTradable);

    String itemClass{};
    JsonUtils::ObjectGetMember(input, "ItemClass", itemClass);
    this->SetItemClass(std::move(itemClass));

    String itemId{};
    JsonUtils::ObjectGetMember(input, "ItemId", itemId);
    this->SetItemId(std::move(itemId));

    String itemImageUrl{};
    JsonUtils::ObjectGetMember(input, "ItemImageUrl", itemImageUrl);
    this->SetItemImageUrl(std::move(itemImageUrl));

    DictionaryEntryVector<PFUint32DictionaryEntry> realCurrencyPrices{};
    JsonUtils::ObjectGetMember(input, "RealCurrencyPrices", realCurrencyPrices);
    this->SetRealCurrencyPrices(std::move(realCurrencyPrices));

    CStringVector tags{};
    JsonUtils::ObjectGetMember(input, "Tags", tags);
    this->SetTags(std::move(tags));

    DictionaryEntryVector<PFUint32DictionaryEntry> virtualCurrencyPrices{};
    JsonUtils::ObjectGetMember(input, "VirtualCurrencyPrices", virtualCurrencyPrices);
    this->SetVirtualCurrencyPrices(std::move(virtualCurrencyPrices));
}

size_t CatalogItem::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFTitleDataManagementCatalogItem const*> CatalogItem::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CatalogItem>(&this->Model());
}

size_t CatalogItem::RequiredBufferSize(const PFTitleDataManagementCatalogItem& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.bundle)
    {
        requiredSize += CatalogItemBundleInfo::RequiredBufferSize(*model.bundle);
    }
    if (model.catalogVersion)
    {
        requiredSize += (std::strlen(model.catalogVersion) + 1);
    }
    if (model.consumable)
    {
        requiredSize += CatalogItemConsumableInfo::RequiredBufferSize(*model.consumable);
    }
    if (model.container)
    {
        requiredSize += CatalogItemContainerInfo::RequiredBufferSize(*model.container);
    }
    if (model.customData)
    {
        requiredSize += (std::strlen(model.customData) + 1);
    }
    if (model.description)
    {
        requiredSize += (std::strlen(model.description) + 1);
    }
    if (model.displayName)
    {
        requiredSize += (std::strlen(model.displayName) + 1);
    }
    if (model.itemClass)
    {
        requiredSize += (std::strlen(model.itemClass) + 1);
    }
    if (model.itemId)
    {
        requiredSize += (std::strlen(model.itemId) + 1);
    }
    if (model.itemImageUrl)
    {
        requiredSize += (std::strlen(model.itemImageUrl) + 1);
    }
    requiredSize += (alignof(PFUint32DictionaryEntry) + sizeof(PFUint32DictionaryEntry) * model.realCurrencyPricesCount);
    for (size_t i = 0; i < model.realCurrencyPricesCount; ++i)
    {
        requiredSize += (std::strlen(model.realCurrencyPrices[i].key) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.tagsCount);
    for (size_t i = 0; i < model.tagsCount; ++i)
    {
        requiredSize += (std::strlen(model.tags[i]) + 1);
    }
    requiredSize += (alignof(PFUint32DictionaryEntry) + sizeof(PFUint32DictionaryEntry) * model.virtualCurrencyPricesCount);
    for (size_t i = 0; i < model.virtualCurrencyPricesCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrencyPrices[i].key) + 1);
    }
    return requiredSize;
}

HRESULT CatalogItem::Copy(const PFTitleDataManagementCatalogItem& input, PFTitleDataManagementCatalogItem& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo<CatalogItemBundleInfo>(input.bundle); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.bundle = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.catalogVersion); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.catalogVersion = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<CatalogItemConsumableInfo>(input.consumable); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.consumable = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<CatalogItemContainerInfo>(input.container); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.container = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.customData); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.customData = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.description); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.description = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.displayName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.displayName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.itemClass); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemClass = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.itemId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.itemImageUrl); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemImageUrl = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.realCurrencyPrices, input.realCurrencyPricesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.realCurrencyPrices = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.tags, input.tagsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.tags = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.virtualCurrencyPrices, input.virtualCurrencyPricesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrencyPrices = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetCatalogItemsResult::FromJson(const JsonValue& input)
{
    ModelVector<CatalogItem> catalog{};
    JsonUtils::ObjectGetMember<CatalogItem>(input, "Catalog", catalog);
    this->SetCatalog(std::move(catalog));
}

size_t GetCatalogItemsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFTitleDataManagementGetCatalogItemsResult const*> GetCatalogItemsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetCatalogItemsResult>(&this->Model());
}

size_t GetCatalogItemsResult::RequiredBufferSize(const PFTitleDataManagementGetCatalogItemsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFTitleDataManagementCatalogItem*) + sizeof(PFTitleDataManagementCatalogItem*) * model.catalogCount);
    for (size_t i = 0; i < model.catalogCount; ++i)
    {
        requiredSize += CatalogItem::RequiredBufferSize(*model.catalog[i]);
    }
    return requiredSize;
}

HRESULT GetCatalogItemsResult::Copy(const PFTitleDataManagementGetCatalogItemsResult& input, PFTitleDataManagementGetCatalogItemsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<CatalogItem>(input.catalog, input.catalogCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.catalog = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPublisherDataRequest::ToJson() const
{
    return GetPublisherDataRequest::ToJson(this->Model());
}

JsonValue GetPublisherDataRequest::ToJson(const PFTitleDataManagementGetPublisherDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "Keys", input.keys, input.keysCount);
    return output;
}

void GetPublisherDataResult::FromJson(const JsonValue& input)
{
    StringDictionaryEntryVector data{};
    JsonUtils::ObjectGetMember(input, "Data", data);
    this->SetData(std::move(data));
}

size_t GetPublisherDataResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFTitleDataManagementGetPublisherDataResult const*> GetPublisherDataResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPublisherDataResult>(&this->Model());
}

size_t GetPublisherDataResult::RequiredBufferSize(const PFTitleDataManagementGetPublisherDataResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFStringDictionaryEntry) + sizeof(PFStringDictionaryEntry) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += (std::strlen(model.data[i].key) + 1);
        requiredSize += (std::strlen(model.data[i].value) + 1);
    }
    return requiredSize;
}

HRESULT GetPublisherDataResult::Copy(const PFTitleDataManagementGetPublisherDataResult& input, PFTitleDataManagementGetPublisherDataResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToDictionary(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetRandomResultTablesRequest::ToJson() const
{
    return GetRandomResultTablesRequest::ToJson(this->Model());
}

JsonValue GetRandomResultTablesRequest::ToJson(const PFTitleDataManagementGetRandomResultTablesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    return output;
}

JsonValue GetStoreItemsRequest::ToJson() const
{
    return GetStoreItemsRequest::ToJson(this->Model());
}

JsonValue GetStoreItemsRequest::ToJson(const PFTitleDataManagementGetStoreItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "StoreId", input.storeId);
    return output;
}

JsonValue StoreMarketingModel::ToJson() const
{
    return StoreMarketingModel::ToJson(this->Model());
}

JsonValue StoreMarketingModel::ToJson(const PFTitleDataManagementStoreMarketingModel& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Description", input.description);
    JsonUtils::ObjectAddMember(output, "DisplayName", input.displayName);
    JsonUtils::ObjectAddMember(output, "Metadata", input.metadata);
    return output;
}

void StoreMarketingModel::FromJson(const JsonValue& input)
{
    String description{};
    JsonUtils::ObjectGetMember(input, "Description", description);
    this->SetDescription(std::move(description));

    String displayName{};
    JsonUtils::ObjectGetMember(input, "DisplayName", displayName);
    this->SetDisplayName(std::move(displayName));

    JsonObject metadata{};
    JsonUtils::ObjectGetMember(input, "Metadata", metadata);
    this->SetMetadata(std::move(metadata));
}

size_t StoreMarketingModel::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFTitleDataManagementStoreMarketingModel const*> StoreMarketingModel::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<StoreMarketingModel>(&this->Model());
}

size_t StoreMarketingModel::RequiredBufferSize(const PFTitleDataManagementStoreMarketingModel& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.description)
    {
        requiredSize += (std::strlen(model.description) + 1);
    }
    if (model.displayName)
    {
        requiredSize += (std::strlen(model.displayName) + 1);
    }
    if (model.metadata.stringValue)
    {
    requiredSize += (std::strlen(model.metadata.stringValue) + 1);
    }
    return requiredSize;
}

HRESULT StoreMarketingModel::Copy(const PFTitleDataManagementStoreMarketingModel& input, PFTitleDataManagementStoreMarketingModel& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.description); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.description = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.displayName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.displayName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.metadata.stringValue);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.metadata.stringValue = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue StoreItem::ToJson() const
{
    return StoreItem::ToJson(this->Model());
}

JsonValue StoreItem::ToJson(const PFTitleDataManagementStoreItem& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CustomData", input.customData);
    JsonUtils::ObjectAddMember(output, "DisplayPosition", input.displayPosition);
    JsonUtils::ObjectAddMember(output, "ItemId", input.itemId);
    JsonUtils::ObjectAddMemberDictionary(output, "RealCurrencyPrices", input.realCurrencyPrices, input.realCurrencyPricesCount);
    JsonUtils::ObjectAddMemberDictionary(output, "VirtualCurrencyPrices", input.virtualCurrencyPrices, input.virtualCurrencyPricesCount);
    return output;
}

void StoreItem::FromJson(const JsonValue& input)
{
    JsonObject customData{};
    JsonUtils::ObjectGetMember(input, "CustomData", customData);
    this->SetCustomData(std::move(customData));

    StdExtra::optional<uint32_t> displayPosition{};
    JsonUtils::ObjectGetMember(input, "DisplayPosition", displayPosition);
    this->SetDisplayPosition(std::move(displayPosition));

    String itemId{};
    JsonUtils::ObjectGetMember(input, "ItemId", itemId);
    this->SetItemId(std::move(itemId));

    DictionaryEntryVector<PFUint32DictionaryEntry> realCurrencyPrices{};
    JsonUtils::ObjectGetMember(input, "RealCurrencyPrices", realCurrencyPrices);
    this->SetRealCurrencyPrices(std::move(realCurrencyPrices));

    DictionaryEntryVector<PFUint32DictionaryEntry> virtualCurrencyPrices{};
    JsonUtils::ObjectGetMember(input, "VirtualCurrencyPrices", virtualCurrencyPrices);
    this->SetVirtualCurrencyPrices(std::move(virtualCurrencyPrices));
}

size_t StoreItem::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFTitleDataManagementStoreItem const*> StoreItem::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<StoreItem>(&this->Model());
}

size_t StoreItem::RequiredBufferSize(const PFTitleDataManagementStoreItem& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.customData.stringValue)
    {
    requiredSize += (std::strlen(model.customData.stringValue) + 1);
    }
    if (model.displayPosition)
    {
        requiredSize += (alignof(uint32_t) + sizeof(uint32_t));
    }
    if (model.itemId)
    {
        requiredSize += (std::strlen(model.itemId) + 1);
    }
    requiredSize += (alignof(PFUint32DictionaryEntry) + sizeof(PFUint32DictionaryEntry) * model.realCurrencyPricesCount);
    for (size_t i = 0; i < model.realCurrencyPricesCount; ++i)
    {
        requiredSize += (std::strlen(model.realCurrencyPrices[i].key) + 1);
    }
    requiredSize += (alignof(PFUint32DictionaryEntry) + sizeof(PFUint32DictionaryEntry) * model.virtualCurrencyPricesCount);
    for (size_t i = 0; i < model.virtualCurrencyPricesCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrencyPrices[i].key) + 1);
    }
    return requiredSize;
}

HRESULT StoreItem::Copy(const PFTitleDataManagementStoreItem& input, PFTitleDataManagementStoreItem& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.customData.stringValue);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.customData.stringValue = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.displayPosition); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.displayPosition = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.itemId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.realCurrencyPrices, input.realCurrencyPricesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.realCurrencyPrices = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.virtualCurrencyPrices, input.virtualCurrencyPricesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrencyPrices = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetStoreItemsResult::FromJson(const JsonValue& input)
{
    String catalogVersion{};
    JsonUtils::ObjectGetMember(input, "CatalogVersion", catalogVersion);
    this->SetCatalogVersion(std::move(catalogVersion));

    StdExtra::optional<StoreMarketingModel> marketingData{};
    JsonUtils::ObjectGetMember(input, "MarketingData", marketingData);
    if (marketingData)
    {
        this->SetMarketingData(std::move(*marketingData));
    }

    StdExtra::optional<PFTitleDataManagementSourceType> source{};
    JsonUtils::ObjectGetMember(input, "Source", source);
    this->SetSource(std::move(source));

    ModelVector<StoreItem> store{};
    JsonUtils::ObjectGetMember<StoreItem>(input, "Store", store);
    this->SetStore(std::move(store));

    String storeId{};
    JsonUtils::ObjectGetMember(input, "StoreId", storeId);
    this->SetStoreId(std::move(storeId));
}

size_t GetStoreItemsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFTitleDataManagementGetStoreItemsResult const*> GetStoreItemsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetStoreItemsResult>(&this->Model());
}

size_t GetStoreItemsResult::RequiredBufferSize(const PFTitleDataManagementGetStoreItemsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.catalogVersion)
    {
        requiredSize += (std::strlen(model.catalogVersion) + 1);
    }
    if (model.marketingData)
    {
        requiredSize += StoreMarketingModel::RequiredBufferSize(*model.marketingData);
    }
    if (model.source)
    {
        requiredSize += (alignof(PFTitleDataManagementSourceType) + sizeof(PFTitleDataManagementSourceType));
    }
    requiredSize += (alignof(PFTitleDataManagementStoreItem*) + sizeof(PFTitleDataManagementStoreItem*) * model.storeCount);
    for (size_t i = 0; i < model.storeCount; ++i)
    {
        requiredSize += StoreItem::RequiredBufferSize(*model.store[i]);
    }
    if (model.storeId)
    {
        requiredSize += (std::strlen(model.storeId) + 1);
    }
    return requiredSize;
}

HRESULT GetStoreItemsResult::Copy(const PFTitleDataManagementGetStoreItemsResult& input, PFTitleDataManagementGetStoreItemsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.catalogVersion); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.catalogVersion = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<StoreMarketingModel>(input.marketingData); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.marketingData = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.source); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.source = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<StoreItem>(input.store, input.storeCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.store = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.storeId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.storeId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetTitleDataRequest::ToJson() const
{
    return GetTitleDataRequest::ToJson(this->Model());
}

JsonValue GetTitleDataRequest::ToJson(const PFTitleDataManagementGetTitleDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "Keys", input.keys, input.keysCount);
    JsonUtils::ObjectAddMember(output, "OverrideLabel", input.overrideLabel);
    return output;
}

void GetTitleDataResult::FromJson(const JsonValue& input)
{
    StringDictionaryEntryVector data{};
    JsonUtils::ObjectGetMember(input, "Data", data);
    this->SetData(std::move(data));
}

size_t GetTitleDataResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFTitleDataManagementGetTitleDataResult const*> GetTitleDataResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetTitleDataResult>(&this->Model());
}

size_t GetTitleDataResult::RequiredBufferSize(const PFTitleDataManagementGetTitleDataResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFStringDictionaryEntry) + sizeof(PFStringDictionaryEntry) * model.dataCount);
    for (size_t i = 0; i < model.dataCount; ++i)
    {
        requiredSize += (std::strlen(model.data[i].key) + 1);
        requiredSize += (std::strlen(model.data[i].value) + 1);
    }
    return requiredSize;
}

HRESULT GetTitleDataResult::Copy(const PFTitleDataManagementGetTitleDataResult& input, PFTitleDataManagementGetTitleDataResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToDictionary(input.data, input.dataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.data = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void ListVirtualCurrencyTypesResult::FromJson(const JsonValue& input)
{
    ModelVector<VirtualCurrencyData> virtualCurrencies{};
    JsonUtils::ObjectGetMember<VirtualCurrencyData>(input, "VirtualCurrencies", virtualCurrencies);
    this->SetVirtualCurrencies(std::move(virtualCurrencies));
}

size_t ListVirtualCurrencyTypesResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFTitleDataManagementListVirtualCurrencyTypesResult const*> ListVirtualCurrencyTypesResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ListVirtualCurrencyTypesResult>(&this->Model());
}

size_t ListVirtualCurrencyTypesResult::RequiredBufferSize(const PFTitleDataManagementListVirtualCurrencyTypesResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFTitleDataManagementVirtualCurrencyData*) + sizeof(PFTitleDataManagementVirtualCurrencyData*) * model.virtualCurrenciesCount);
    for (size_t i = 0; i < model.virtualCurrenciesCount; ++i)
    {
        requiredSize += VirtualCurrencyData::RequiredBufferSize(*model.virtualCurrencies[i]);
    }
    return requiredSize;
}

HRESULT ListVirtualCurrencyTypesResult::Copy(const PFTitleDataManagementListVirtualCurrencyTypesResult& input, PFTitleDataManagementListVirtualCurrencyTypesResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<VirtualCurrencyData>(input.virtualCurrencies, input.virtualCurrenciesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrencies = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RemoveVirtualCurrencyTypesRequest::ToJson() const
{
    return RemoveVirtualCurrencyTypesRequest::ToJson(this->Model());
}

JsonValue RemoveVirtualCurrencyTypesRequest::ToJson(const PFTitleDataManagementRemoveVirtualCurrencyTypesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray<VirtualCurrencyData>(output, "VirtualCurrencies", input.virtualCurrencies, input.virtualCurrenciesCount);
    return output;
}

JsonValue UpdateCatalogItemsRequest::ToJson() const
{
    return UpdateCatalogItemsRequest::ToJson(this->Model());
}

JsonValue UpdateCatalogItemsRequest::ToJson(const PFTitleDataManagementUpdateCatalogItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray<CatalogItem>(output, "Catalog", input.catalog, input.catalogCount);
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "SetAsDefaultCatalog", input.setAsDefaultCatalog);
    return output;
}

JsonValue SetPublisherDataRequest::ToJson() const
{
    return SetPublisherDataRequest::ToJson(this->Model());
}

JsonValue SetPublisherDataRequest::ToJson(const PFTitleDataManagementSetPublisherDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Key", input.key);
    JsonUtils::ObjectAddMember(output, "Value", input.value);
    return output;
}

JsonValue UpdateStoreItemsRequest::ToJson() const
{
    return UpdateStoreItemsRequest::ToJson(this->Model());
}

JsonValue UpdateStoreItemsRequest::ToJson(const PFTitleDataManagementUpdateStoreItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<StoreMarketingModel>(output, "MarketingData", input.marketingData);
    JsonUtils::ObjectAddMemberArray<StoreItem>(output, "Store", input.store, input.storeCount);
    JsonUtils::ObjectAddMember(output, "StoreId", input.storeId);
    return output;
}

JsonValue SetTitleDataRequest::ToJson() const
{
    return SetTitleDataRequest::ToJson(this->Model());
}

JsonValue SetTitleDataRequest::ToJson(const PFTitleDataManagementSetTitleDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "Key", input.key);
    JsonUtils::ObjectAddMember(output, "Value", input.value);
    return output;
}

JsonValue TitleDataKeyValue::ToJson() const
{
    return TitleDataKeyValue::ToJson(this->Model());
}

JsonValue TitleDataKeyValue::ToJson(const PFTitleDataManagementTitleDataKeyValue& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Key", input.key);
    JsonUtils::ObjectAddMember(output, "Value", input.value);
    return output;
}

JsonValue SetTitleDataAndOverridesRequest::ToJson() const
{
    return SetTitleDataAndOverridesRequest::ToJson(this->Model());
}

JsonValue SetTitleDataAndOverridesRequest::ToJson(const PFTitleDataManagementSetTitleDataAndOverridesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray<TitleDataKeyValue>(output, "KeyValues", input.keyValues, input.keyValuesCount);
    JsonUtils::ObjectAddMember(output, "OverrideLabel", input.overrideLabel);
    return output;
}

JsonValue SetupPushNotificationRequest::ToJson() const
{
    return SetupPushNotificationRequest::ToJson(this->Model());
}

JsonValue SetupPushNotificationRequest::ToJson(const PFTitleDataManagementSetupPushNotificationRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Credential", input.credential);
    JsonUtils::ObjectAddMember(output, "Key", input.key);
    JsonUtils::ObjectAddMember(output, "Name", input.name);
    JsonUtils::ObjectAddMember(output, "OverwriteOldARN", input.overwriteOldARN);
    JsonUtils::ObjectAddMember(output, "Platform", input.platform);
    return output;
}

void SetupPushNotificationResult::FromJson(const JsonValue& input)
{
    String aRN{};
    JsonUtils::ObjectGetMember(input, "ARN", aRN);
    this->SetARN(std::move(aRN));
}

size_t SetupPushNotificationResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFTitleDataManagementSetupPushNotificationResult const*> SetupPushNotificationResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<SetupPushNotificationResult>(&this->Model());
}

size_t SetupPushNotificationResult::RequiredBufferSize(const PFTitleDataManagementSetupPushNotificationResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.aRN)
    {
        requiredSize += (std::strlen(model.aRN) + 1);
    }
    return requiredSize;
}

HRESULT SetupPushNotificationResult::Copy(const PFTitleDataManagementSetupPushNotificationResult& input, PFTitleDataManagementSetupPushNotificationResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.aRN); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.aRN = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RandomResultTable::ToJson() const
{
    return RandomResultTable::ToJson(this->Model());
}

JsonValue RandomResultTable::ToJson(const PFTitleDataManagementRandomResultTable& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray<ResultTableNode>(output, "Nodes", input.nodes, input.nodesCount);
    JsonUtils::ObjectAddMember(output, "TableId", input.tableId);
    return output;
}

JsonValue UpdateRandomResultTablesRequest::ToJson() const
{
    return UpdateRandomResultTablesRequest::ToJson(this->Model());
}

JsonValue UpdateRandomResultTablesRequest::ToJson(const PFTitleDataManagementUpdateRandomResultTablesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray<RandomResultTable>(output, "Tables", input.tables, input.tablesCount);
    return output;
}

void GetTimeResult::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMemberTime(input, "Time", this->m_model.time);
}

size_t GetTimeResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFTitleDataManagementGetTimeResult const*> GetTimeResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetTimeResult>(&this->Model());
}

size_t GetTimeResult::RequiredBufferSize(const PFTitleDataManagementGetTimeResult& model)
{
    UNREFERENCED_PARAMETER(model); // Fixed size
    return sizeof(ModelType);
}

HRESULT GetTimeResult::Copy(const PFTitleDataManagementGetTimeResult& input, PFTitleDataManagementGetTimeResult& output, ModelBuffer& buffer)
{
    output = input;
    UNREFERENCED_PARAMETER(buffer); // Fixed size
    return S_OK;
}

JsonValue GetTitleNewsRequest::ToJson() const
{
    return GetTitleNewsRequest::ToJson(this->Model());
}

JsonValue GetTitleNewsRequest::ToJson(const PFTitleDataManagementGetTitleNewsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Count", input.count);
    return output;
}

void TitleNewsItem::FromJson(const JsonValue& input)
{
    String body{};
    JsonUtils::ObjectGetMember(input, "Body", body);
    this->SetBody(std::move(body));

    String newsId{};
    JsonUtils::ObjectGetMember(input, "NewsId", newsId);
    this->SetNewsId(std::move(newsId));

    JsonUtils::ObjectGetMemberTime(input, "Timestamp", this->m_model.timestamp);

    String title{};
    JsonUtils::ObjectGetMember(input, "Title", title);
    this->SetTitle(std::move(title));
}

size_t TitleNewsItem::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFTitleDataManagementTitleNewsItem const*> TitleNewsItem::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<TitleNewsItem>(&this->Model());
}

size_t TitleNewsItem::RequiredBufferSize(const PFTitleDataManagementTitleNewsItem& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.body)
    {
        requiredSize += (std::strlen(model.body) + 1);
    }
    if (model.newsId)
    {
        requiredSize += (std::strlen(model.newsId) + 1);
    }
    if (model.title)
    {
        requiredSize += (std::strlen(model.title) + 1);
    }
    return requiredSize;
}

HRESULT TitleNewsItem::Copy(const PFTitleDataManagementTitleNewsItem& input, PFTitleDataManagementTitleNewsItem& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.body); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.body = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.newsId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.newsId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.title); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.title = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GetTitleNewsResult::FromJson(const JsonValue& input)
{
    ModelVector<TitleNewsItem> news{};
    JsonUtils::ObjectGetMember<TitleNewsItem>(input, "News", news);
    this->SetNews(std::move(news));
}

size_t GetTitleNewsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFTitleDataManagementGetTitleNewsResult const*> GetTitleNewsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetTitleNewsResult>(&this->Model());
}

size_t GetTitleNewsResult::RequiredBufferSize(const PFTitleDataManagementGetTitleNewsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFTitleDataManagementTitleNewsItem*) + sizeof(PFTitleDataManagementTitleNewsItem*) * model.newsCount);
    for (size_t i = 0; i < model.newsCount; ++i)
    {
        requiredSize += TitleNewsItem::RequiredBufferSize(*model.news[i]);
    }
    return requiredSize;
}

HRESULT GetTitleNewsResult::Copy(const PFTitleDataManagementGetTitleNewsResult& input, PFTitleDataManagementGetTitleNewsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<TitleNewsItem>(input.news, input.newsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.news = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetStoreItemsServerRequest::ToJson() const
{
    return GetStoreItemsServerRequest::ToJson(this->Model());
}

JsonValue GetStoreItemsServerRequest::ToJson(const PFTitleDataManagementGetStoreItemsServerRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "StoreId", input.storeId);
    return output;
}

} // namespace TitleDataManagement
} // namespace PlayFab
