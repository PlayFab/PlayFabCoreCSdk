#include "stdafx.h"
#include "PlayerItemManagementDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace PlayerItemManagement
{

JsonValue AdminAddUserVirtualCurrencyRequest::ToJson() const
{
    return AdminAddUserVirtualCurrencyRequest::ToJson(this->Model());
}

JsonValue AdminAddUserVirtualCurrencyRequest::ToJson(const PFPlayerItemManagementAdminAddUserVirtualCurrencyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "VirtualCurrency", input.virtualCurrency);
    return output;
}

void ModifyUserVirtualCurrencyResult::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "Balance", this->m_model.balance);

    JsonUtils::ObjectGetMember(input, "BalanceChange", this->m_model.balanceChange);

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    String virtualCurrency{};
    JsonUtils::ObjectGetMember(input, "VirtualCurrency", virtualCurrency);
    this->SetVirtualCurrency(std::move(virtualCurrency));
}

size_t ModifyUserVirtualCurrencyResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementModifyUserVirtualCurrencyResult const*> ModifyUserVirtualCurrencyResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ModifyUserVirtualCurrencyResult>(&this->Model());
}

size_t ModifyUserVirtualCurrencyResult::RequiredBufferSize(const PFPlayerItemManagementModifyUserVirtualCurrencyResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    if (model.virtualCurrency)
    {
        requiredSize += (std::strlen(model.virtualCurrency) + 1);
    }
    return requiredSize;
}

HRESULT ModifyUserVirtualCurrencyResult::Copy(const PFPlayerItemManagementModifyUserVirtualCurrencyResult& input, PFPlayerItemManagementModifyUserVirtualCurrencyResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.virtualCurrency); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrency = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue CheckLimitedEditionItemAvailabilityRequest::ToJson() const
{
    return CheckLimitedEditionItemAvailabilityRequest::ToJson(this->Model());
}

JsonValue CheckLimitedEditionItemAvailabilityRequest::ToJson(const PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "ItemId", input.itemId);
    return output;
}

void CheckLimitedEditionItemAvailabilityResult::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "Amount", this->m_model.amount);
}

size_t CheckLimitedEditionItemAvailabilityResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult const*> CheckLimitedEditionItemAvailabilityResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CheckLimitedEditionItemAvailabilityResult>(&this->Model());
}

size_t CheckLimitedEditionItemAvailabilityResult::RequiredBufferSize(const PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult& model)
{
    UNREFERENCED_PARAMETER(model); // Fixed size
    return sizeof(ModelType);
}

HRESULT CheckLimitedEditionItemAvailabilityResult::Copy(const PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult& input, PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult& output, ModelBuffer& buffer)
{
    output = input;
    UNREFERENCED_PARAMETER(buffer); // Fixed size
    return S_OK;
}

JsonValue AdminGetUserInventoryRequest::ToJson() const
{
    return AdminGetUserInventoryRequest::ToJson(this->Model());
}

JsonValue AdminGetUserInventoryRequest::ToJson(const PFPlayerItemManagementAdminGetUserInventoryRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void AdminGetUserInventoryResult::FromJson(const JsonValue& input)
{
    ModelVector<ItemInstance> inventory{};
    JsonUtils::ObjectGetMember<ItemInstance>(input, "Inventory", inventory);
    this->SetInventory(std::move(inventory));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    DictionaryEntryVector<PFInt32DictionaryEntry> virtualCurrency{};
    JsonUtils::ObjectGetMember(input, "VirtualCurrency", virtualCurrency);
    this->SetVirtualCurrency(std::move(virtualCurrency));

    ModelDictionaryEntryVector<VirtualCurrencyRechargeTime> virtualCurrencyRechargeTimes{};
    JsonUtils::ObjectGetMember<VirtualCurrencyRechargeTime>(input, "VirtualCurrencyRechargeTimes", virtualCurrencyRechargeTimes);
    this->SetVirtualCurrencyRechargeTimes(std::move(virtualCurrencyRechargeTimes));
}

size_t AdminGetUserInventoryResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementAdminGetUserInventoryResult const*> AdminGetUserInventoryResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AdminGetUserInventoryResult>(&this->Model());
}

size_t AdminGetUserInventoryResult::RequiredBufferSize(const PFPlayerItemManagementAdminGetUserInventoryResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFItemInstance*) + sizeof(PFItemInstance*) * model.inventoryCount);
    for (size_t i = 0; i < model.inventoryCount; ++i)
    {
        requiredSize += ItemInstance::RequiredBufferSize(*model.inventory[i]);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    requiredSize += (alignof(PFInt32DictionaryEntry) + sizeof(PFInt32DictionaryEntry) * model.virtualCurrencyCount);
    for (size_t i = 0; i < model.virtualCurrencyCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrency[i].key) + 1);
    }
    requiredSize += (alignof(PFVirtualCurrencyRechargeTimeDictionaryEntry) + sizeof(PFVirtualCurrencyRechargeTimeDictionaryEntry) * model.virtualCurrencyRechargeTimesCount);
    for (size_t i = 0; i < model.virtualCurrencyRechargeTimesCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrencyRechargeTimes[i].key) + 1);
        requiredSize += VirtualCurrencyRechargeTime::RequiredBufferSize(*model.virtualCurrencyRechargeTimes[i].value);
    }
    return requiredSize;
}

HRESULT AdminGetUserInventoryResult::Copy(const PFPlayerItemManagementAdminGetUserInventoryResult& input, PFPlayerItemManagementAdminGetUserInventoryResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ItemInstance>(input.inventory, input.inventoryCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.inventory = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.virtualCurrency, input.virtualCurrencyCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrency = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary<VirtualCurrencyRechargeTime>(input.virtualCurrencyRechargeTimes, input.virtualCurrencyRechargeTimesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrencyRechargeTimes = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ItemGrant::ToJson() const
{
    return ItemGrant::ToJson(this->Model());
}

JsonValue ItemGrant::ToJson(const PFPlayerItemManagementItemGrant& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Annotation", input.annotation);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "Data", input.data, input.dataCount);
    JsonUtils::ObjectAddMember(output, "ItemId", input.itemId);
    JsonUtils::ObjectAddMemberArray(output, "KeysToRemove", input.keysToRemove, input.keysToRemoveCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue GrantItemsToUsersRequest::ToJson() const
{
    return GrantItemsToUsersRequest::ToJson(this->Model());
}

JsonValue GrantItemsToUsersRequest::ToJson(const PFPlayerItemManagementGrantItemsToUsersRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray<ItemGrant>(output, "ItemGrants", input.itemGrants, input.itemGrantsCount);
    return output;
}

void GrantedItemInstance::FromJson(const JsonValue& input)
{
    String annotation{};
    JsonUtils::ObjectGetMember(input, "Annotation", annotation);
    this->SetAnnotation(std::move(annotation));

    CStringVector bundleContents{};
    JsonUtils::ObjectGetMember(input, "BundleContents", bundleContents);
    this->SetBundleContents(std::move(bundleContents));

    String bundleParent{};
    JsonUtils::ObjectGetMember(input, "BundleParent", bundleParent);
    this->SetBundleParent(std::move(bundleParent));

    String catalogVersion{};
    JsonUtils::ObjectGetMember(input, "CatalogVersion", catalogVersion);
    this->SetCatalogVersion(std::move(catalogVersion));

    String characterId{};
    JsonUtils::ObjectGetMember(input, "CharacterId", characterId);
    this->SetCharacterId(std::move(characterId));

    StringDictionaryEntryVector customData{};
    JsonUtils::ObjectGetMember(input, "CustomData", customData);
    this->SetCustomData(std::move(customData));

    String displayName{};
    JsonUtils::ObjectGetMember(input, "DisplayName", displayName);
    this->SetDisplayName(std::move(displayName));

    StdExtra::optional<time_t> expiration{};
    JsonUtils::ObjectGetMemberTime(input, "Expiration", expiration);
    this->SetExpiration(std::move(expiration));

    String itemClass{};
    JsonUtils::ObjectGetMember(input, "ItemClass", itemClass);
    this->SetItemClass(std::move(itemClass));

    String itemId{};
    JsonUtils::ObjectGetMember(input, "ItemId", itemId);
    this->SetItemId(std::move(itemId));

    String itemInstanceId{};
    JsonUtils::ObjectGetMember(input, "ItemInstanceId", itemInstanceId);
    this->SetItemInstanceId(std::move(itemInstanceId));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    StdExtra::optional<time_t> purchaseDate{};
    JsonUtils::ObjectGetMemberTime(input, "PurchaseDate", purchaseDate);
    this->SetPurchaseDate(std::move(purchaseDate));

    StdExtra::optional<int32_t> remainingUses{};
    JsonUtils::ObjectGetMember(input, "RemainingUses", remainingUses);
    this->SetRemainingUses(std::move(remainingUses));

    JsonUtils::ObjectGetMember(input, "Result", this->m_model.result);

    String unitCurrency{};
    JsonUtils::ObjectGetMember(input, "UnitCurrency", unitCurrency);
    this->SetUnitCurrency(std::move(unitCurrency));

    JsonUtils::ObjectGetMember(input, "UnitPrice", this->m_model.unitPrice);

    StdExtra::optional<int32_t> usesIncrementedBy{};
    JsonUtils::ObjectGetMember(input, "UsesIncrementedBy", usesIncrementedBy);
    this->SetUsesIncrementedBy(std::move(usesIncrementedBy));
}

size_t GrantedItemInstance::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementGrantedItemInstance const*> GrantedItemInstance::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GrantedItemInstance>(&this->Model());
}

size_t GrantedItemInstance::RequiredBufferSize(const PFPlayerItemManagementGrantedItemInstance& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.annotation)
    {
        requiredSize += (std::strlen(model.annotation) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.bundleContentsCount);
    for (size_t i = 0; i < model.bundleContentsCount; ++i)
    {
        requiredSize += (std::strlen(model.bundleContents[i]) + 1);
    }
    if (model.bundleParent)
    {
        requiredSize += (std::strlen(model.bundleParent) + 1);
    }
    if (model.catalogVersion)
    {
        requiredSize += (std::strlen(model.catalogVersion) + 1);
    }
    if (model.characterId)
    {
        requiredSize += (std::strlen(model.characterId) + 1);
    }
    requiredSize += (alignof(PFStringDictionaryEntry) + sizeof(PFStringDictionaryEntry) * model.customDataCount);
    for (size_t i = 0; i < model.customDataCount; ++i)
    {
        requiredSize += (std::strlen(model.customData[i].key) + 1);
        requiredSize += (std::strlen(model.customData[i].value) + 1);
    }
    if (model.displayName)
    {
        requiredSize += (std::strlen(model.displayName) + 1);
    }
    if (model.expiration)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.itemClass)
    {
        requiredSize += (std::strlen(model.itemClass) + 1);
    }
    if (model.itemId)
    {
        requiredSize += (std::strlen(model.itemId) + 1);
    }
    if (model.itemInstanceId)
    {
        requiredSize += (std::strlen(model.itemInstanceId) + 1);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    if (model.purchaseDate)
    {
        requiredSize += (alignof(time_t) + sizeof(time_t));
    }
    if (model.remainingUses)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    if (model.unitCurrency)
    {
        requiredSize += (std::strlen(model.unitCurrency) + 1);
    }
    if (model.usesIncrementedBy)
    {
        requiredSize += (alignof(int32_t) + sizeof(int32_t));
    }
    return requiredSize;
}

HRESULT GrantedItemInstance::Copy(const PFPlayerItemManagementGrantedItemInstance& input, PFPlayerItemManagementGrantedItemInstance& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.annotation); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.annotation = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.bundleContents, input.bundleContentsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.bundleContents = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.bundleParent); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.bundleParent = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.catalogVersion); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.catalogVersion = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.characterId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.characterId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.customData, input.customDataCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.customData = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.displayName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.displayName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.expiration); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.expiration = propCopyResult.ExtractPayload();
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
        auto propCopyResult = buffer.CopyTo(input.itemInstanceId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemInstanceId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.purchaseDate); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.purchaseDate = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.remainingUses); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.remainingUses = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.unitCurrency); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.unitCurrency = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.usesIncrementedBy); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.usesIncrementedBy = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void GrantItemsToUsersResult::FromJson(const JsonValue& input)
{
    ModelVector<GrantedItemInstance> itemGrantResults{};
    JsonUtils::ObjectGetMember<GrantedItemInstance>(input, "ItemGrantResults", itemGrantResults);
    this->SetItemGrantResults(std::move(itemGrantResults));
}

size_t GrantItemsToUsersResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementGrantItemsToUsersResult const*> GrantItemsToUsersResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GrantItemsToUsersResult>(&this->Model());
}

size_t GrantItemsToUsersResult::RequiredBufferSize(const PFPlayerItemManagementGrantItemsToUsersResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlayerItemManagementGrantedItemInstance*) + sizeof(PFPlayerItemManagementGrantedItemInstance*) * model.itemGrantResultsCount);
    for (size_t i = 0; i < model.itemGrantResultsCount; ++i)
    {
        requiredSize += GrantedItemInstance::RequiredBufferSize(*model.itemGrantResults[i]);
    }
    return requiredSize;
}

HRESULT GrantItemsToUsersResult::Copy(const PFPlayerItemManagementGrantItemsToUsersResult& input, PFPlayerItemManagementGrantItemsToUsersResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<GrantedItemInstance>(input.itemGrantResults, input.itemGrantResultsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemGrantResults = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue IncrementLimitedEditionItemAvailabilityRequest::ToJson() const
{
    return IncrementLimitedEditionItemAvailabilityRequest::ToJson(this->Model());
}

JsonValue IncrementLimitedEditionItemAvailabilityRequest::ToJson(const PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ItemId", input.itemId);
    return output;
}

JsonValue RevokeInventoryItemRequest::ToJson() const
{
    return RevokeInventoryItemRequest::ToJson(this->Model());
}

JsonValue RevokeInventoryItemRequest::ToJson(const PFPlayerItemManagementRevokeInventoryItemRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMember(output, "ItemInstanceId", input.itemInstanceId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue RevokeInventoryItem::ToJson() const
{
    return RevokeInventoryItem::ToJson(this->Model());
}

JsonValue RevokeInventoryItem::ToJson(const PFPlayerItemManagementRevokeInventoryItem& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMember(output, "ItemInstanceId", input.itemInstanceId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void RevokeInventoryItem::FromJson(const JsonValue& input)
{
    String characterId{};
    JsonUtils::ObjectGetMember(input, "CharacterId", characterId);
    this->SetCharacterId(std::move(characterId));

    String itemInstanceId{};
    JsonUtils::ObjectGetMember(input, "ItemInstanceId", itemInstanceId);
    this->SetItemInstanceId(std::move(itemInstanceId));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));
}

size_t RevokeInventoryItem::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementRevokeInventoryItem const*> RevokeInventoryItem::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RevokeInventoryItem>(&this->Model());
}

size_t RevokeInventoryItem::RequiredBufferSize(const PFPlayerItemManagementRevokeInventoryItem& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.characterId)
    {
        requiredSize += (std::strlen(model.characterId) + 1);
    }
    if (model.itemInstanceId)
    {
        requiredSize += (std::strlen(model.itemInstanceId) + 1);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT RevokeInventoryItem::Copy(const PFPlayerItemManagementRevokeInventoryItem& input, PFPlayerItemManagementRevokeInventoryItem& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.characterId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.characterId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.itemInstanceId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemInstanceId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RevokeInventoryItemsRequest::ToJson() const
{
    return RevokeInventoryItemsRequest::ToJson(this->Model());
}

JsonValue RevokeInventoryItemsRequest::ToJson(const PFPlayerItemManagementRevokeInventoryItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray<RevokeInventoryItem>(output, "Items", input.items, input.itemsCount);
    return output;
}

void RevokeItemError::FromJson(const JsonValue& input)
{
    StdExtra::optional<PFPlayerItemManagementGenericErrorCodes> error{};
    JsonUtils::ObjectGetMember(input, "Error", error);
    this->SetError(std::move(error));

    StdExtra::optional<RevokeInventoryItem> item{};
    JsonUtils::ObjectGetMember(input, "Item", item);
    if (item)
    {
        this->SetItem(std::move(*item));
    }
}

size_t RevokeItemError::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementRevokeItemError const*> RevokeItemError::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RevokeItemError>(&this->Model());
}

size_t RevokeItemError::RequiredBufferSize(const PFPlayerItemManagementRevokeItemError& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.error)
    {
        requiredSize += (alignof(PFPlayerItemManagementGenericErrorCodes) + sizeof(PFPlayerItemManagementGenericErrorCodes));
    }
    if (model.item)
    {
        requiredSize += RevokeInventoryItem::RequiredBufferSize(*model.item);
    }
    return requiredSize;
}

HRESULT RevokeItemError::Copy(const PFPlayerItemManagementRevokeItemError& input, PFPlayerItemManagementRevokeItemError& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.error); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.error = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo<RevokeInventoryItem>(input.item); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.item = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void RevokeInventoryItemsResult::FromJson(const JsonValue& input)
{
    ModelVector<RevokeItemError> errors{};
    JsonUtils::ObjectGetMember<RevokeItemError>(input, "Errors", errors);
    this->SetErrors(std::move(errors));
}

size_t RevokeInventoryItemsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementRevokeInventoryItemsResult const*> RevokeInventoryItemsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RevokeInventoryItemsResult>(&this->Model());
}

size_t RevokeInventoryItemsResult::RequiredBufferSize(const PFPlayerItemManagementRevokeInventoryItemsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlayerItemManagementRevokeItemError*) + sizeof(PFPlayerItemManagementRevokeItemError*) * model.errorsCount);
    for (size_t i = 0; i < model.errorsCount; ++i)
    {
        requiredSize += RevokeItemError::RequiredBufferSize(*model.errors[i]);
    }
    return requiredSize;
}

HRESULT RevokeInventoryItemsResult::Copy(const PFPlayerItemManagementRevokeInventoryItemsResult& input, PFPlayerItemManagementRevokeInventoryItemsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<RevokeItemError>(input.errors, input.errorsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.errors = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue AdminSubtractUserVirtualCurrencyRequest::ToJson() const
{
    return AdminSubtractUserVirtualCurrencyRequest::ToJson(this->Model());
}

JsonValue AdminSubtractUserVirtualCurrencyRequest::ToJson(const PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "VirtualCurrency", input.virtualCurrency);
    return output;
}

JsonValue ClientAddUserVirtualCurrencyRequest::ToJson() const
{
    return ClientAddUserVirtualCurrencyRequest::ToJson(this->Model());
}

JsonValue ClientAddUserVirtualCurrencyRequest::ToJson(const PFPlayerItemManagementClientAddUserVirtualCurrencyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "VirtualCurrency", input.virtualCurrency);
    return output;
}

JsonValue ConfirmPurchaseRequest::ToJson() const
{
    return ConfirmPurchaseRequest::ToJson(this->Model());
}

JsonValue ConfirmPurchaseRequest::ToJson(const PFPlayerItemManagementConfirmPurchaseRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "OrderId", input.orderId);
    return output;
}

void ConfirmPurchaseResult::FromJson(const JsonValue& input)
{
    ModelVector<ItemInstance> items{};
    JsonUtils::ObjectGetMember<ItemInstance>(input, "Items", items);
    this->SetItems(std::move(items));

    String orderId{};
    JsonUtils::ObjectGetMember(input, "OrderId", orderId);
    this->SetOrderId(std::move(orderId));

    JsonUtils::ObjectGetMemberTime(input, "PurchaseDate", this->m_model.purchaseDate);
}

size_t ConfirmPurchaseResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementConfirmPurchaseResult const*> ConfirmPurchaseResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ConfirmPurchaseResult>(&this->Model());
}

size_t ConfirmPurchaseResult::RequiredBufferSize(const PFPlayerItemManagementConfirmPurchaseResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFItemInstance*) + sizeof(PFItemInstance*) * model.itemsCount);
    for (size_t i = 0; i < model.itemsCount; ++i)
    {
        requiredSize += ItemInstance::RequiredBufferSize(*model.items[i]);
    }
    if (model.orderId)
    {
        requiredSize += (std::strlen(model.orderId) + 1);
    }
    return requiredSize;
}

HRESULT ConfirmPurchaseResult::Copy(const PFPlayerItemManagementConfirmPurchaseResult& input, PFPlayerItemManagementConfirmPurchaseResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ItemInstance>(input.items, input.itemsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.items = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.orderId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.orderId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ClientConsumeItemRequest::ToJson() const
{
    return ClientConsumeItemRequest::ToJson(this->Model());
}

JsonValue ClientConsumeItemRequest::ToJson(const PFPlayerItemManagementClientConsumeItemRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMember(output, "ConsumeCount", input.consumeCount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ItemInstanceId", input.itemInstanceId);
    return output;
}

void ConsumeItemResult::FromJson(const JsonValue& input)
{
    String itemInstanceId{};
    JsonUtils::ObjectGetMember(input, "ItemInstanceId", itemInstanceId);
    this->SetItemInstanceId(std::move(itemInstanceId));

    JsonUtils::ObjectGetMember(input, "RemainingUses", this->m_model.remainingUses);
}

size_t ConsumeItemResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementConsumeItemResult const*> ConsumeItemResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ConsumeItemResult>(&this->Model());
}

size_t ConsumeItemResult::RequiredBufferSize(const PFPlayerItemManagementConsumeItemResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.itemInstanceId)
    {
        requiredSize += (std::strlen(model.itemInstanceId) + 1);
    }
    return requiredSize;
}

HRESULT ConsumeItemResult::Copy(const PFPlayerItemManagementConsumeItemResult& input, PFPlayerItemManagementConsumeItemResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.itemInstanceId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemInstanceId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ClientGetCharacterInventoryRequest::ToJson() const
{
    return ClientGetCharacterInventoryRequest::ToJson(this->Model());
}

JsonValue ClientGetCharacterInventoryRequest::ToJson(const PFPlayerItemManagementClientGetCharacterInventoryRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

void ClientGetCharacterInventoryResult::FromJson(const JsonValue& input)
{
    String characterId{};
    JsonUtils::ObjectGetMember(input, "CharacterId", characterId);
    this->SetCharacterId(std::move(characterId));

    ModelVector<ItemInstance> inventory{};
    JsonUtils::ObjectGetMember<ItemInstance>(input, "Inventory", inventory);
    this->SetInventory(std::move(inventory));

    DictionaryEntryVector<PFInt32DictionaryEntry> virtualCurrency{};
    JsonUtils::ObjectGetMember(input, "VirtualCurrency", virtualCurrency);
    this->SetVirtualCurrency(std::move(virtualCurrency));

    ModelDictionaryEntryVector<VirtualCurrencyRechargeTime> virtualCurrencyRechargeTimes{};
    JsonUtils::ObjectGetMember<VirtualCurrencyRechargeTime>(input, "VirtualCurrencyRechargeTimes", virtualCurrencyRechargeTimes);
    this->SetVirtualCurrencyRechargeTimes(std::move(virtualCurrencyRechargeTimes));
}

size_t ClientGetCharacterInventoryResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementClientGetCharacterInventoryResult const*> ClientGetCharacterInventoryResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ClientGetCharacterInventoryResult>(&this->Model());
}

size_t ClientGetCharacterInventoryResult::RequiredBufferSize(const PFPlayerItemManagementClientGetCharacterInventoryResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.characterId)
    {
        requiredSize += (std::strlen(model.characterId) + 1);
    }
    requiredSize += (alignof(PFItemInstance*) + sizeof(PFItemInstance*) * model.inventoryCount);
    for (size_t i = 0; i < model.inventoryCount; ++i)
    {
        requiredSize += ItemInstance::RequiredBufferSize(*model.inventory[i]);
    }
    requiredSize += (alignof(PFInt32DictionaryEntry) + sizeof(PFInt32DictionaryEntry) * model.virtualCurrencyCount);
    for (size_t i = 0; i < model.virtualCurrencyCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrency[i].key) + 1);
    }
    requiredSize += (alignof(PFVirtualCurrencyRechargeTimeDictionaryEntry) + sizeof(PFVirtualCurrencyRechargeTimeDictionaryEntry) * model.virtualCurrencyRechargeTimesCount);
    for (size_t i = 0; i < model.virtualCurrencyRechargeTimesCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrencyRechargeTimes[i].key) + 1);
        requiredSize += VirtualCurrencyRechargeTime::RequiredBufferSize(*model.virtualCurrencyRechargeTimes[i].value);
    }
    return requiredSize;
}

HRESULT ClientGetCharacterInventoryResult::Copy(const PFPlayerItemManagementClientGetCharacterInventoryResult& input, PFPlayerItemManagementClientGetCharacterInventoryResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.characterId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.characterId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<ItemInstance>(input.inventory, input.inventoryCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.inventory = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.virtualCurrency, input.virtualCurrencyCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrency = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary<VirtualCurrencyRechargeTime>(input.virtualCurrencyRechargeTimes, input.virtualCurrencyRechargeTimesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrencyRechargeTimes = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPaymentTokenRequest::ToJson() const
{
    return GetPaymentTokenRequest::ToJson(this->Model());
}

JsonValue GetPaymentTokenRequest::ToJson(const PFPlayerItemManagementGetPaymentTokenRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "TokenProvider", input.tokenProvider);
    return output;
}

void GetPaymentTokenResult::FromJson(const JsonValue& input)
{
    String orderId{};
    JsonUtils::ObjectGetMember(input, "OrderId", orderId);
    this->SetOrderId(std::move(orderId));

    String providerToken{};
    JsonUtils::ObjectGetMember(input, "ProviderToken", providerToken);
    this->SetProviderToken(std::move(providerToken));
}

size_t GetPaymentTokenResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementGetPaymentTokenResult const*> GetPaymentTokenResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPaymentTokenResult>(&this->Model());
}

size_t GetPaymentTokenResult::RequiredBufferSize(const PFPlayerItemManagementGetPaymentTokenResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.orderId)
    {
        requiredSize += (std::strlen(model.orderId) + 1);
    }
    if (model.providerToken)
    {
        requiredSize += (std::strlen(model.providerToken) + 1);
    }
    return requiredSize;
}

HRESULT GetPaymentTokenResult::Copy(const PFPlayerItemManagementGetPaymentTokenResult& input, PFPlayerItemManagementGetPaymentTokenResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.orderId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.orderId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.providerToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.providerToken = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetPurchaseRequest::ToJson() const
{
    return GetPurchaseRequest::ToJson(this->Model());
}

JsonValue GetPurchaseRequest::ToJson(const PFPlayerItemManagementGetPurchaseRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "OrderId", input.orderId);
    return output;
}

void GetPurchaseResult::FromJson(const JsonValue& input)
{
    String orderId{};
    JsonUtils::ObjectGetMember(input, "OrderId", orderId);
    this->SetOrderId(std::move(orderId));

    String paymentProvider{};
    JsonUtils::ObjectGetMember(input, "PaymentProvider", paymentProvider);
    this->SetPaymentProvider(std::move(paymentProvider));

    JsonUtils::ObjectGetMemberTime(input, "PurchaseDate", this->m_model.purchaseDate);

    String transactionId{};
    JsonUtils::ObjectGetMember(input, "TransactionId", transactionId);
    this->SetTransactionId(std::move(transactionId));

    String transactionStatus{};
    JsonUtils::ObjectGetMember(input, "TransactionStatus", transactionStatus);
    this->SetTransactionStatus(std::move(transactionStatus));
}

size_t GetPurchaseResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementGetPurchaseResult const*> GetPurchaseResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetPurchaseResult>(&this->Model());
}

size_t GetPurchaseResult::RequiredBufferSize(const PFPlayerItemManagementGetPurchaseResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.orderId)
    {
        requiredSize += (std::strlen(model.orderId) + 1);
    }
    if (model.paymentProvider)
    {
        requiredSize += (std::strlen(model.paymentProvider) + 1);
    }
    if (model.transactionId)
    {
        requiredSize += (std::strlen(model.transactionId) + 1);
    }
    if (model.transactionStatus)
    {
        requiredSize += (std::strlen(model.transactionStatus) + 1);
    }
    return requiredSize;
}

HRESULT GetPurchaseResult::Copy(const PFPlayerItemManagementGetPurchaseResult& input, PFPlayerItemManagementGetPurchaseResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.orderId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.orderId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.paymentProvider); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.paymentProvider = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.transactionId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.transactionId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.transactionStatus); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.transactionStatus = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ClientGetUserInventoryRequest::ToJson() const
{
    return ClientGetUserInventoryRequest::ToJson(this->Model());
}

JsonValue ClientGetUserInventoryRequest::ToJson(const PFPlayerItemManagementClientGetUserInventoryRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

void ClientGetUserInventoryResult::FromJson(const JsonValue& input)
{
    ModelVector<ItemInstance> inventory{};
    JsonUtils::ObjectGetMember<ItemInstance>(input, "Inventory", inventory);
    this->SetInventory(std::move(inventory));

    DictionaryEntryVector<PFInt32DictionaryEntry> virtualCurrency{};
    JsonUtils::ObjectGetMember(input, "VirtualCurrency", virtualCurrency);
    this->SetVirtualCurrency(std::move(virtualCurrency));

    ModelDictionaryEntryVector<VirtualCurrencyRechargeTime> virtualCurrencyRechargeTimes{};
    JsonUtils::ObjectGetMember<VirtualCurrencyRechargeTime>(input, "VirtualCurrencyRechargeTimes", virtualCurrencyRechargeTimes);
    this->SetVirtualCurrencyRechargeTimes(std::move(virtualCurrencyRechargeTimes));
}

size_t ClientGetUserInventoryResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementClientGetUserInventoryResult const*> ClientGetUserInventoryResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ClientGetUserInventoryResult>(&this->Model());
}

size_t ClientGetUserInventoryResult::RequiredBufferSize(const PFPlayerItemManagementClientGetUserInventoryResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFItemInstance*) + sizeof(PFItemInstance*) * model.inventoryCount);
    for (size_t i = 0; i < model.inventoryCount; ++i)
    {
        requiredSize += ItemInstance::RequiredBufferSize(*model.inventory[i]);
    }
    requiredSize += (alignof(PFInt32DictionaryEntry) + sizeof(PFInt32DictionaryEntry) * model.virtualCurrencyCount);
    for (size_t i = 0; i < model.virtualCurrencyCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrency[i].key) + 1);
    }
    requiredSize += (alignof(PFVirtualCurrencyRechargeTimeDictionaryEntry) + sizeof(PFVirtualCurrencyRechargeTimeDictionaryEntry) * model.virtualCurrencyRechargeTimesCount);
    for (size_t i = 0; i < model.virtualCurrencyRechargeTimesCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrencyRechargeTimes[i].key) + 1);
        requiredSize += VirtualCurrencyRechargeTime::RequiredBufferSize(*model.virtualCurrencyRechargeTimes[i].value);
    }
    return requiredSize;
}

HRESULT ClientGetUserInventoryResult::Copy(const PFPlayerItemManagementClientGetUserInventoryResult& input, PFPlayerItemManagementClientGetUserInventoryResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ItemInstance>(input.inventory, input.inventoryCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.inventory = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.virtualCurrency, input.virtualCurrencyCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrency = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary<VirtualCurrencyRechargeTime>(input.virtualCurrencyRechargeTimes, input.virtualCurrencyRechargeTimesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrencyRechargeTimes = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue PayForPurchaseRequest::ToJson() const
{
    return PayForPurchaseRequest::ToJson(this->Model());
}

JsonValue PayForPurchaseRequest::ToJson(const PFPlayerItemManagementPayForPurchaseRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Currency", input.currency);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "OrderId", input.orderId);
    JsonUtils::ObjectAddMember(output, "ProviderName", input.providerName);
    JsonUtils::ObjectAddMember(output, "ProviderTransactionId", input.providerTransactionId);
    return output;
}

void PayForPurchaseResult::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "CreditApplied", this->m_model.creditApplied);

    String orderId{};
    JsonUtils::ObjectGetMember(input, "OrderId", orderId);
    this->SetOrderId(std::move(orderId));

    String providerData{};
    JsonUtils::ObjectGetMember(input, "ProviderData", providerData);
    this->SetProviderData(std::move(providerData));

    String providerToken{};
    JsonUtils::ObjectGetMember(input, "ProviderToken", providerToken);
    this->SetProviderToken(std::move(providerToken));

    String purchaseConfirmationPageURL{};
    JsonUtils::ObjectGetMember(input, "PurchaseConfirmationPageURL", purchaseConfirmationPageURL);
    this->SetPurchaseConfirmationPageURL(std::move(purchaseConfirmationPageURL));

    String purchaseCurrency{};
    JsonUtils::ObjectGetMember(input, "PurchaseCurrency", purchaseCurrency);
    this->SetPurchaseCurrency(std::move(purchaseCurrency));

    JsonUtils::ObjectGetMember(input, "PurchasePrice", this->m_model.purchasePrice);

    StdExtra::optional<PFPlayerItemManagementTransactionStatus> status{};
    JsonUtils::ObjectGetMember(input, "Status", status);
    this->SetStatus(std::move(status));

    DictionaryEntryVector<PFInt32DictionaryEntry> vCAmount{};
    JsonUtils::ObjectGetMember(input, "VCAmount", vCAmount);
    this->SetVCAmount(std::move(vCAmount));

    DictionaryEntryVector<PFInt32DictionaryEntry> virtualCurrency{};
    JsonUtils::ObjectGetMember(input, "VirtualCurrency", virtualCurrency);
    this->SetVirtualCurrency(std::move(virtualCurrency));
}

size_t PayForPurchaseResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementPayForPurchaseResult const*> PayForPurchaseResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PayForPurchaseResult>(&this->Model());
}

size_t PayForPurchaseResult::RequiredBufferSize(const PFPlayerItemManagementPayForPurchaseResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.orderId)
    {
        requiredSize += (std::strlen(model.orderId) + 1);
    }
    if (model.providerData)
    {
        requiredSize += (std::strlen(model.providerData) + 1);
    }
    if (model.providerToken)
    {
        requiredSize += (std::strlen(model.providerToken) + 1);
    }
    if (model.purchaseConfirmationPageURL)
    {
        requiredSize += (std::strlen(model.purchaseConfirmationPageURL) + 1);
    }
    if (model.purchaseCurrency)
    {
        requiredSize += (std::strlen(model.purchaseCurrency) + 1);
    }
    if (model.status)
    {
        requiredSize += (alignof(PFPlayerItemManagementTransactionStatus) + sizeof(PFPlayerItemManagementTransactionStatus));
    }
    requiredSize += (alignof(PFInt32DictionaryEntry) + sizeof(PFInt32DictionaryEntry) * model.vCAmountCount);
    for (size_t i = 0; i < model.vCAmountCount; ++i)
    {
        requiredSize += (std::strlen(model.vCAmount[i].key) + 1);
    }
    requiredSize += (alignof(PFInt32DictionaryEntry) + sizeof(PFInt32DictionaryEntry) * model.virtualCurrencyCount);
    for (size_t i = 0; i < model.virtualCurrencyCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrency[i].key) + 1);
    }
    return requiredSize;
}

HRESULT PayForPurchaseResult::Copy(const PFPlayerItemManagementPayForPurchaseResult& input, PFPlayerItemManagementPayForPurchaseResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.orderId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.orderId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.providerData); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.providerData = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.providerToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.providerToken = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.purchaseConfirmationPageURL); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.purchaseConfirmationPageURL = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.purchaseCurrency); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.purchaseCurrency = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.status); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.status = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.vCAmount, input.vCAmountCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.vCAmount = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.virtualCurrency, input.virtualCurrencyCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrency = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue PurchaseItemRequest::ToJson() const
{
    return PurchaseItemRequest::ToJson(this->Model());
}

JsonValue PurchaseItemRequest::ToJson(const PFPlayerItemManagementPurchaseItemRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ItemId", input.itemId);
    JsonUtils::ObjectAddMember(output, "Price", input.price);
    JsonUtils::ObjectAddMember(output, "StoreId", input.storeId);
    JsonUtils::ObjectAddMember(output, "VirtualCurrency", input.virtualCurrency);
    return output;
}

void PurchaseItemResult::FromJson(const JsonValue& input)
{
    ModelVector<ItemInstance> items{};
    JsonUtils::ObjectGetMember<ItemInstance>(input, "Items", items);
    this->SetItems(std::move(items));
}

size_t PurchaseItemResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementPurchaseItemResult const*> PurchaseItemResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PurchaseItemResult>(&this->Model());
}

size_t PurchaseItemResult::RequiredBufferSize(const PFPlayerItemManagementPurchaseItemResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFItemInstance*) + sizeof(PFItemInstance*) * model.itemsCount);
    for (size_t i = 0; i < model.itemsCount; ++i)
    {
        requiredSize += ItemInstance::RequiredBufferSize(*model.items[i]);
    }
    return requiredSize;
}

HRESULT PurchaseItemResult::Copy(const PFPlayerItemManagementPurchaseItemResult& input, PFPlayerItemManagementPurchaseItemResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ItemInstance>(input.items, input.itemsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.items = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ClientRedeemCouponRequest::ToJson() const
{
    return ClientRedeemCouponRequest::ToJson(this->Model());
}

JsonValue ClientRedeemCouponRequest::ToJson(const PFPlayerItemManagementClientRedeemCouponRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMember(output, "CouponCode", input.couponCode);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

void RedeemCouponResult::FromJson(const JsonValue& input)
{
    ModelVector<ItemInstance> grantedItems{};
    JsonUtils::ObjectGetMember<ItemInstance>(input, "GrantedItems", grantedItems);
    this->SetGrantedItems(std::move(grantedItems));
}

size_t RedeemCouponResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementRedeemCouponResult const*> RedeemCouponResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RedeemCouponResult>(&this->Model());
}

size_t RedeemCouponResult::RequiredBufferSize(const PFPlayerItemManagementRedeemCouponResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFItemInstance*) + sizeof(PFItemInstance*) * model.grantedItemsCount);
    for (size_t i = 0; i < model.grantedItemsCount; ++i)
    {
        requiredSize += ItemInstance::RequiredBufferSize(*model.grantedItems[i]);
    }
    return requiredSize;
}

HRESULT RedeemCouponResult::Copy(const PFPlayerItemManagementRedeemCouponResult& input, PFPlayerItemManagementRedeemCouponResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ItemInstance>(input.grantedItems, input.grantedItemsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.grantedItems = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ItemPurchaseRequest::ToJson() const
{
    return ItemPurchaseRequest::ToJson(this->Model());
}

JsonValue ItemPurchaseRequest::ToJson(const PFPlayerItemManagementItemPurchaseRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Annotation", input.annotation);
    JsonUtils::ObjectAddMember(output, "ItemId", input.itemId);
    JsonUtils::ObjectAddMember(output, "Quantity", input.quantity);
    JsonUtils::ObjectAddMemberArray(output, "UpgradeFromItems", input.upgradeFromItems, input.upgradeFromItemsCount);
    return output;
}

JsonValue StartPurchaseRequest::ToJson() const
{
    return StartPurchaseRequest::ToJson(this->Model());
}

JsonValue StartPurchaseRequest::ToJson(const PFPlayerItemManagementStartPurchaseRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray<ItemPurchaseRequest>(output, "Items", input.items, input.itemsCount);
    JsonUtils::ObjectAddMember(output, "StoreId", input.storeId);
    return output;
}

void CartItem::FromJson(const JsonValue& input)
{
    String description{};
    JsonUtils::ObjectGetMember(input, "Description", description);
    this->SetDescription(std::move(description));

    String displayName{};
    JsonUtils::ObjectGetMember(input, "DisplayName", displayName);
    this->SetDisplayName(std::move(displayName));

    String itemClass{};
    JsonUtils::ObjectGetMember(input, "ItemClass", itemClass);
    this->SetItemClass(std::move(itemClass));

    String itemId{};
    JsonUtils::ObjectGetMember(input, "ItemId", itemId);
    this->SetItemId(std::move(itemId));

    String itemInstanceId{};
    JsonUtils::ObjectGetMember(input, "ItemInstanceId", itemInstanceId);
    this->SetItemInstanceId(std::move(itemInstanceId));

    DictionaryEntryVector<PFUint32DictionaryEntry> realCurrencyPrices{};
    JsonUtils::ObjectGetMember(input, "RealCurrencyPrices", realCurrencyPrices);
    this->SetRealCurrencyPrices(std::move(realCurrencyPrices));

    DictionaryEntryVector<PFUint32DictionaryEntry> vCAmount{};
    JsonUtils::ObjectGetMember(input, "VCAmount", vCAmount);
    this->SetVCAmount(std::move(vCAmount));

    DictionaryEntryVector<PFUint32DictionaryEntry> virtualCurrencyPrices{};
    JsonUtils::ObjectGetMember(input, "VirtualCurrencyPrices", virtualCurrencyPrices);
    this->SetVirtualCurrencyPrices(std::move(virtualCurrencyPrices));
}

size_t CartItem::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementCartItem const*> CartItem::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<CartItem>(&this->Model());
}

size_t CartItem::RequiredBufferSize(const PFPlayerItemManagementCartItem& model)
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
    if (model.itemClass)
    {
        requiredSize += (std::strlen(model.itemClass) + 1);
    }
    if (model.itemId)
    {
        requiredSize += (std::strlen(model.itemId) + 1);
    }
    if (model.itemInstanceId)
    {
        requiredSize += (std::strlen(model.itemInstanceId) + 1);
    }
    requiredSize += (alignof(PFUint32DictionaryEntry) + sizeof(PFUint32DictionaryEntry) * model.realCurrencyPricesCount);
    for (size_t i = 0; i < model.realCurrencyPricesCount; ++i)
    {
        requiredSize += (std::strlen(model.realCurrencyPrices[i].key) + 1);
    }
    requiredSize += (alignof(PFUint32DictionaryEntry) + sizeof(PFUint32DictionaryEntry) * model.vCAmountCount);
    for (size_t i = 0; i < model.vCAmountCount; ++i)
    {
        requiredSize += (std::strlen(model.vCAmount[i].key) + 1);
    }
    requiredSize += (alignof(PFUint32DictionaryEntry) + sizeof(PFUint32DictionaryEntry) * model.virtualCurrencyPricesCount);
    for (size_t i = 0; i < model.virtualCurrencyPricesCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrencyPrices[i].key) + 1);
    }
    return requiredSize;
}

HRESULT CartItem::Copy(const PFPlayerItemManagementCartItem& input, PFPlayerItemManagementCartItem& output, ModelBuffer& buffer)
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
        auto propCopyResult = buffer.CopyTo(input.itemInstanceId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemInstanceId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.realCurrencyPrices, input.realCurrencyPricesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.realCurrencyPrices = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.vCAmount, input.vCAmountCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.vCAmount = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.virtualCurrencyPrices, input.virtualCurrencyPricesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrencyPrices = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void PaymentOption::FromJson(const JsonValue& input)
{
    String currency{};
    JsonUtils::ObjectGetMember(input, "Currency", currency);
    this->SetCurrency(std::move(currency));

    JsonUtils::ObjectGetMember(input, "Price", this->m_model.price);

    String providerName{};
    JsonUtils::ObjectGetMember(input, "ProviderName", providerName);
    this->SetProviderName(std::move(providerName));

    JsonUtils::ObjectGetMember(input, "StoreCredit", this->m_model.storeCredit);
}

size_t PaymentOption::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementPaymentOption const*> PaymentOption::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PaymentOption>(&this->Model());
}

size_t PaymentOption::RequiredBufferSize(const PFPlayerItemManagementPaymentOption& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.currency)
    {
        requiredSize += (std::strlen(model.currency) + 1);
    }
    if (model.providerName)
    {
        requiredSize += (std::strlen(model.providerName) + 1);
    }
    return requiredSize;
}

HRESULT PaymentOption::Copy(const PFPlayerItemManagementPaymentOption& input, PFPlayerItemManagementPaymentOption& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.currency); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.currency = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.providerName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.providerName = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void StartPurchaseResult::FromJson(const JsonValue& input)
{
    ModelVector<CartItem> contents{};
    JsonUtils::ObjectGetMember<CartItem>(input, "Contents", contents);
    this->SetContents(std::move(contents));

    String orderId{};
    JsonUtils::ObjectGetMember(input, "OrderId", orderId);
    this->SetOrderId(std::move(orderId));

    ModelVector<PaymentOption> paymentOptions{};
    JsonUtils::ObjectGetMember<PaymentOption>(input, "PaymentOptions", paymentOptions);
    this->SetPaymentOptions(std::move(paymentOptions));

    DictionaryEntryVector<PFInt32DictionaryEntry> virtualCurrencyBalances{};
    JsonUtils::ObjectGetMember(input, "VirtualCurrencyBalances", virtualCurrencyBalances);
    this->SetVirtualCurrencyBalances(std::move(virtualCurrencyBalances));
}

size_t StartPurchaseResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementStartPurchaseResult const*> StartPurchaseResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<StartPurchaseResult>(&this->Model());
}

size_t StartPurchaseResult::RequiredBufferSize(const PFPlayerItemManagementStartPurchaseResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlayerItemManagementCartItem*) + sizeof(PFPlayerItemManagementCartItem*) * model.contentsCount);
    for (size_t i = 0; i < model.contentsCount; ++i)
    {
        requiredSize += CartItem::RequiredBufferSize(*model.contents[i]);
    }
    if (model.orderId)
    {
        requiredSize += (std::strlen(model.orderId) + 1);
    }
    requiredSize += (alignof(PFPlayerItemManagementPaymentOption*) + sizeof(PFPlayerItemManagementPaymentOption*) * model.paymentOptionsCount);
    for (size_t i = 0; i < model.paymentOptionsCount; ++i)
    {
        requiredSize += PaymentOption::RequiredBufferSize(*model.paymentOptions[i]);
    }
    requiredSize += (alignof(PFInt32DictionaryEntry) + sizeof(PFInt32DictionaryEntry) * model.virtualCurrencyBalancesCount);
    for (size_t i = 0; i < model.virtualCurrencyBalancesCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrencyBalances[i].key) + 1);
    }
    return requiredSize;
}

HRESULT StartPurchaseResult::Copy(const PFPlayerItemManagementStartPurchaseResult& input, PFPlayerItemManagementStartPurchaseResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<CartItem>(input.contents, input.contentsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.contents = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.orderId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.orderId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<PaymentOption>(input.paymentOptions, input.paymentOptionsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.paymentOptions = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.virtualCurrencyBalances, input.virtualCurrencyBalancesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrencyBalances = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ClientSubtractUserVirtualCurrencyRequest::ToJson() const
{
    return ClientSubtractUserVirtualCurrencyRequest::ToJson(this->Model());
}

JsonValue ClientSubtractUserVirtualCurrencyRequest::ToJson(const PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "VirtualCurrency", input.virtualCurrency);
    return output;
}

JsonValue ClientUnlockContainerInstanceRequest::ToJson() const
{
    return ClientUnlockContainerInstanceRequest::ToJson(this->Model());
}

JsonValue ClientUnlockContainerInstanceRequest::ToJson(const PFPlayerItemManagementClientUnlockContainerInstanceRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMember(output, "ContainerItemInstanceId", input.containerItemInstanceId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "KeyItemInstanceId", input.keyItemInstanceId);
    return output;
}

void UnlockContainerItemResult::FromJson(const JsonValue& input)
{
    ModelVector<ItemInstance> grantedItems{};
    JsonUtils::ObjectGetMember<ItemInstance>(input, "GrantedItems", grantedItems);
    this->SetGrantedItems(std::move(grantedItems));

    String unlockedItemInstanceId{};
    JsonUtils::ObjectGetMember(input, "UnlockedItemInstanceId", unlockedItemInstanceId);
    this->SetUnlockedItemInstanceId(std::move(unlockedItemInstanceId));

    String unlockedWithItemInstanceId{};
    JsonUtils::ObjectGetMember(input, "UnlockedWithItemInstanceId", unlockedWithItemInstanceId);
    this->SetUnlockedWithItemInstanceId(std::move(unlockedWithItemInstanceId));

    DictionaryEntryVector<PFUint32DictionaryEntry> virtualCurrency{};
    JsonUtils::ObjectGetMember(input, "VirtualCurrency", virtualCurrency);
    this->SetVirtualCurrency(std::move(virtualCurrency));
}

size_t UnlockContainerItemResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementUnlockContainerItemResult const*> UnlockContainerItemResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<UnlockContainerItemResult>(&this->Model());
}

size_t UnlockContainerItemResult::RequiredBufferSize(const PFPlayerItemManagementUnlockContainerItemResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFItemInstance*) + sizeof(PFItemInstance*) * model.grantedItemsCount);
    for (size_t i = 0; i < model.grantedItemsCount; ++i)
    {
        requiredSize += ItemInstance::RequiredBufferSize(*model.grantedItems[i]);
    }
    if (model.unlockedItemInstanceId)
    {
        requiredSize += (std::strlen(model.unlockedItemInstanceId) + 1);
    }
    if (model.unlockedWithItemInstanceId)
    {
        requiredSize += (std::strlen(model.unlockedWithItemInstanceId) + 1);
    }
    requiredSize += (alignof(PFUint32DictionaryEntry) + sizeof(PFUint32DictionaryEntry) * model.virtualCurrencyCount);
    for (size_t i = 0; i < model.virtualCurrencyCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrency[i].key) + 1);
    }
    return requiredSize;
}

HRESULT UnlockContainerItemResult::Copy(const PFPlayerItemManagementUnlockContainerItemResult& input, PFPlayerItemManagementUnlockContainerItemResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ItemInstance>(input.grantedItems, input.grantedItemsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.grantedItems = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.unlockedItemInstanceId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.unlockedItemInstanceId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.unlockedWithItemInstanceId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.unlockedWithItemInstanceId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.virtualCurrency, input.virtualCurrencyCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrency = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ClientUnlockContainerItemRequest::ToJson() const
{
    return ClientUnlockContainerItemRequest::ToJson(this->Model());
}

JsonValue ClientUnlockContainerItemRequest::ToJson(const PFPlayerItemManagementClientUnlockContainerItemRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMember(output, "ContainerItemId", input.containerItemId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

JsonValue AddCharacterVirtualCurrencyRequest::ToJson() const
{
    return AddCharacterVirtualCurrencyRequest::ToJson(this->Model());
}

JsonValue AddCharacterVirtualCurrencyRequest::ToJson(const PFPlayerItemManagementAddCharacterVirtualCurrencyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "VirtualCurrency", input.virtualCurrency);
    return output;
}

void ModifyCharacterVirtualCurrencyResult::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "Balance", this->m_model.balance);

    String virtualCurrency{};
    JsonUtils::ObjectGetMember(input, "VirtualCurrency", virtualCurrency);
    this->SetVirtualCurrency(std::move(virtualCurrency));
}

size_t ModifyCharacterVirtualCurrencyResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementModifyCharacterVirtualCurrencyResult const*> ModifyCharacterVirtualCurrencyResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ModifyCharacterVirtualCurrencyResult>(&this->Model());
}

size_t ModifyCharacterVirtualCurrencyResult::RequiredBufferSize(const PFPlayerItemManagementModifyCharacterVirtualCurrencyResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.virtualCurrency)
    {
        requiredSize += (std::strlen(model.virtualCurrency) + 1);
    }
    return requiredSize;
}

HRESULT ModifyCharacterVirtualCurrencyResult::Copy(const PFPlayerItemManagementModifyCharacterVirtualCurrencyResult& input, PFPlayerItemManagementModifyCharacterVirtualCurrencyResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.virtualCurrency); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrency = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ServerAddUserVirtualCurrencyRequest::ToJson() const
{
    return ServerAddUserVirtualCurrencyRequest::ToJson(this->Model());
}

JsonValue ServerAddUserVirtualCurrencyRequest::ToJson(const PFPlayerItemManagementServerAddUserVirtualCurrencyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "VirtualCurrency", input.virtualCurrency);
    return output;
}

JsonValue ServerConsumeItemRequest::ToJson() const
{
    return ServerConsumeItemRequest::ToJson(this->Model());
}

JsonValue ServerConsumeItemRequest::ToJson(const PFPlayerItemManagementServerConsumeItemRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMember(output, "ConsumeCount", input.consumeCount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ItemInstanceId", input.itemInstanceId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue EvaluateRandomResultTableRequest::ToJson() const
{
    return EvaluateRandomResultTableRequest::ToJson(this->Model());
}

JsonValue EvaluateRandomResultTableRequest::ToJson(const PFPlayerItemManagementEvaluateRandomResultTableRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "TableId", input.tableId);
    return output;
}

void EvaluateRandomResultTableResult::FromJson(const JsonValue& input)
{
    String resultItemId{};
    JsonUtils::ObjectGetMember(input, "ResultItemId", resultItemId);
    this->SetResultItemId(std::move(resultItemId));
}

size_t EvaluateRandomResultTableResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementEvaluateRandomResultTableResult const*> EvaluateRandomResultTableResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<EvaluateRandomResultTableResult>(&this->Model());
}

size_t EvaluateRandomResultTableResult::RequiredBufferSize(const PFPlayerItemManagementEvaluateRandomResultTableResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.resultItemId)
    {
        requiredSize += (std::strlen(model.resultItemId) + 1);
    }
    return requiredSize;
}

HRESULT EvaluateRandomResultTableResult::Copy(const PFPlayerItemManagementEvaluateRandomResultTableResult& input, PFPlayerItemManagementEvaluateRandomResultTableResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.resultItemId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.resultItemId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ServerGetCharacterInventoryRequest::ToJson() const
{
    return ServerGetCharacterInventoryRequest::ToJson(this->Model());
}

JsonValue ServerGetCharacterInventoryRequest::ToJson(const PFPlayerItemManagementServerGetCharacterInventoryRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void ServerGetCharacterInventoryResult::FromJson(const JsonValue& input)
{
    String characterId{};
    JsonUtils::ObjectGetMember(input, "CharacterId", characterId);
    this->SetCharacterId(std::move(characterId));

    ModelVector<ItemInstance> inventory{};
    JsonUtils::ObjectGetMember<ItemInstance>(input, "Inventory", inventory);
    this->SetInventory(std::move(inventory));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    DictionaryEntryVector<PFInt32DictionaryEntry> virtualCurrency{};
    JsonUtils::ObjectGetMember(input, "VirtualCurrency", virtualCurrency);
    this->SetVirtualCurrency(std::move(virtualCurrency));

    ModelDictionaryEntryVector<VirtualCurrencyRechargeTime> virtualCurrencyRechargeTimes{};
    JsonUtils::ObjectGetMember<VirtualCurrencyRechargeTime>(input, "VirtualCurrencyRechargeTimes", virtualCurrencyRechargeTimes);
    this->SetVirtualCurrencyRechargeTimes(std::move(virtualCurrencyRechargeTimes));
}

size_t ServerGetCharacterInventoryResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementServerGetCharacterInventoryResult const*> ServerGetCharacterInventoryResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ServerGetCharacterInventoryResult>(&this->Model());
}

size_t ServerGetCharacterInventoryResult::RequiredBufferSize(const PFPlayerItemManagementServerGetCharacterInventoryResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.characterId)
    {
        requiredSize += (std::strlen(model.characterId) + 1);
    }
    requiredSize += (alignof(PFItemInstance*) + sizeof(PFItemInstance*) * model.inventoryCount);
    for (size_t i = 0; i < model.inventoryCount; ++i)
    {
        requiredSize += ItemInstance::RequiredBufferSize(*model.inventory[i]);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    requiredSize += (alignof(PFInt32DictionaryEntry) + sizeof(PFInt32DictionaryEntry) * model.virtualCurrencyCount);
    for (size_t i = 0; i < model.virtualCurrencyCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrency[i].key) + 1);
    }
    requiredSize += (alignof(PFVirtualCurrencyRechargeTimeDictionaryEntry) + sizeof(PFVirtualCurrencyRechargeTimeDictionaryEntry) * model.virtualCurrencyRechargeTimesCount);
    for (size_t i = 0; i < model.virtualCurrencyRechargeTimesCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrencyRechargeTimes[i].key) + 1);
        requiredSize += VirtualCurrencyRechargeTime::RequiredBufferSize(*model.virtualCurrencyRechargeTimes[i].value);
    }
    return requiredSize;
}

HRESULT ServerGetCharacterInventoryResult::Copy(const PFPlayerItemManagementServerGetCharacterInventoryResult& input, PFPlayerItemManagementServerGetCharacterInventoryResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.characterId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.characterId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<ItemInstance>(input.inventory, input.inventoryCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.inventory = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.virtualCurrency, input.virtualCurrencyCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrency = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary<VirtualCurrencyRechargeTime>(input.virtualCurrencyRechargeTimes, input.virtualCurrencyRechargeTimesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrencyRechargeTimes = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetRandomResultTablesRequest::ToJson() const
{
    return GetRandomResultTablesRequest::ToJson(this->Model());
}

JsonValue GetRandomResultTablesRequest::ToJson(const PFPlayerItemManagementGetRandomResultTablesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMemberArray(output, "TableIDs", input.tableIDs, input.tableIDsCount);
    return output;
}

JsonValue ServerGetUserInventoryRequest::ToJson() const
{
    return ServerGetUserInventoryRequest::ToJson(this->Model());
}

JsonValue ServerGetUserInventoryRequest::ToJson(const PFPlayerItemManagementServerGetUserInventoryRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void ServerGetUserInventoryResult::FromJson(const JsonValue& input)
{
    ModelVector<ItemInstance> inventory{};
    JsonUtils::ObjectGetMember<ItemInstance>(input, "Inventory", inventory);
    this->SetInventory(std::move(inventory));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    DictionaryEntryVector<PFInt32DictionaryEntry> virtualCurrency{};
    JsonUtils::ObjectGetMember(input, "VirtualCurrency", virtualCurrency);
    this->SetVirtualCurrency(std::move(virtualCurrency));

    ModelDictionaryEntryVector<VirtualCurrencyRechargeTime> virtualCurrencyRechargeTimes{};
    JsonUtils::ObjectGetMember<VirtualCurrencyRechargeTime>(input, "VirtualCurrencyRechargeTimes", virtualCurrencyRechargeTimes);
    this->SetVirtualCurrencyRechargeTimes(std::move(virtualCurrencyRechargeTimes));
}

size_t ServerGetUserInventoryResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementServerGetUserInventoryResult const*> ServerGetUserInventoryResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ServerGetUserInventoryResult>(&this->Model());
}

size_t ServerGetUserInventoryResult::RequiredBufferSize(const PFPlayerItemManagementServerGetUserInventoryResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFItemInstance*) + sizeof(PFItemInstance*) * model.inventoryCount);
    for (size_t i = 0; i < model.inventoryCount; ++i)
    {
        requiredSize += ItemInstance::RequiredBufferSize(*model.inventory[i]);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    requiredSize += (alignof(PFInt32DictionaryEntry) + sizeof(PFInt32DictionaryEntry) * model.virtualCurrencyCount);
    for (size_t i = 0; i < model.virtualCurrencyCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrency[i].key) + 1);
    }
    requiredSize += (alignof(PFVirtualCurrencyRechargeTimeDictionaryEntry) + sizeof(PFVirtualCurrencyRechargeTimeDictionaryEntry) * model.virtualCurrencyRechargeTimesCount);
    for (size_t i = 0; i < model.virtualCurrencyRechargeTimesCount; ++i)
    {
        requiredSize += (std::strlen(model.virtualCurrencyRechargeTimes[i].key) + 1);
        requiredSize += VirtualCurrencyRechargeTime::RequiredBufferSize(*model.virtualCurrencyRechargeTimes[i].value);
    }
    return requiredSize;
}

HRESULT ServerGetUserInventoryResult::Copy(const PFPlayerItemManagementServerGetUserInventoryResult& input, PFPlayerItemManagementServerGetUserInventoryResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ItemInstance>(input.inventory, input.inventoryCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.inventory = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary(input.virtualCurrency, input.virtualCurrencyCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrency = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToDictionary<VirtualCurrencyRechargeTime>(input.virtualCurrencyRechargeTimes, input.virtualCurrencyRechargeTimesCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.virtualCurrencyRechargeTimes = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GrantItemsToCharacterRequest::ToJson() const
{
    return GrantItemsToCharacterRequest::ToJson(this->Model());
}

JsonValue GrantItemsToCharacterRequest::ToJson(const PFPlayerItemManagementGrantItemsToCharacterRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Annotation", input.annotation);
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray(output, "ItemIds", input.itemIds, input.itemIdsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void GrantItemsToCharacterResult::FromJson(const JsonValue& input)
{
    ModelVector<GrantedItemInstance> itemGrantResults{};
    JsonUtils::ObjectGetMember<GrantedItemInstance>(input, "ItemGrantResults", itemGrantResults);
    this->SetItemGrantResults(std::move(itemGrantResults));
}

size_t GrantItemsToCharacterResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementGrantItemsToCharacterResult const*> GrantItemsToCharacterResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GrantItemsToCharacterResult>(&this->Model());
}

size_t GrantItemsToCharacterResult::RequiredBufferSize(const PFPlayerItemManagementGrantItemsToCharacterResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlayerItemManagementGrantedItemInstance*) + sizeof(PFPlayerItemManagementGrantedItemInstance*) * model.itemGrantResultsCount);
    for (size_t i = 0; i < model.itemGrantResultsCount; ++i)
    {
        requiredSize += GrantedItemInstance::RequiredBufferSize(*model.itemGrantResults[i]);
    }
    return requiredSize;
}

HRESULT GrantItemsToCharacterResult::Copy(const PFPlayerItemManagementGrantItemsToCharacterResult& input, PFPlayerItemManagementGrantItemsToCharacterResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<GrantedItemInstance>(input.itemGrantResults, input.itemGrantResultsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemGrantResults = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GrantItemsToUserRequest::ToJson() const
{
    return GrantItemsToUserRequest::ToJson(this->Model());
}

JsonValue GrantItemsToUserRequest::ToJson(const PFPlayerItemManagementGrantItemsToUserRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Annotation", input.annotation);
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberArray(output, "ItemIds", input.itemIds, input.itemIdsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

void GrantItemsToUserResult::FromJson(const JsonValue& input)
{
    ModelVector<GrantedItemInstance> itemGrantResults{};
    JsonUtils::ObjectGetMember<GrantedItemInstance>(input, "ItemGrantResults", itemGrantResults);
    this->SetItemGrantResults(std::move(itemGrantResults));
}

size_t GrantItemsToUserResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementGrantItemsToUserResult const*> GrantItemsToUserResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GrantItemsToUserResult>(&this->Model());
}

size_t GrantItemsToUserResult::RequiredBufferSize(const PFPlayerItemManagementGrantItemsToUserResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlayerItemManagementGrantedItemInstance*) + sizeof(PFPlayerItemManagementGrantedItemInstance*) * model.itemGrantResultsCount);
    for (size_t i = 0; i < model.itemGrantResultsCount; ++i)
    {
        requiredSize += GrantedItemInstance::RequiredBufferSize(*model.itemGrantResults[i]);
    }
    return requiredSize;
}

HRESULT GrantItemsToUserResult::Copy(const PFPlayerItemManagementGrantItemsToUserResult& input, PFPlayerItemManagementGrantItemsToUserResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<GrantedItemInstance>(input.itemGrantResults, input.itemGrantResultsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemGrantResults = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ModifyItemUsesRequest::ToJson() const
{
    return ModifyItemUsesRequest::ToJson(this->Model());
}

JsonValue ModifyItemUsesRequest::ToJson(const PFPlayerItemManagementModifyItemUsesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ItemInstanceId", input.itemInstanceId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "UsesToAdd", input.usesToAdd);
    return output;
}

void ModifyItemUsesResult::FromJson(const JsonValue& input)
{
    String itemInstanceId{};
    JsonUtils::ObjectGetMember(input, "ItemInstanceId", itemInstanceId);
    this->SetItemInstanceId(std::move(itemInstanceId));

    JsonUtils::ObjectGetMember(input, "RemainingUses", this->m_model.remainingUses);
}

size_t ModifyItemUsesResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementModifyItemUsesResult const*> ModifyItemUsesResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ModifyItemUsesResult>(&this->Model());
}

size_t ModifyItemUsesResult::RequiredBufferSize(const PFPlayerItemManagementModifyItemUsesResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.itemInstanceId)
    {
        requiredSize += (std::strlen(model.itemInstanceId) + 1);
    }
    return requiredSize;
}

HRESULT ModifyItemUsesResult::Copy(const PFPlayerItemManagementModifyItemUsesResult& input, PFPlayerItemManagementModifyItemUsesResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.itemInstanceId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemInstanceId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue MoveItemToCharacterFromCharacterRequest::ToJson() const
{
    return MoveItemToCharacterFromCharacterRequest::ToJson(this->Model());
}

JsonValue MoveItemToCharacterFromCharacterRequest::ToJson(const PFPlayerItemManagementMoveItemToCharacterFromCharacterRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "GivingCharacterId", input.givingCharacterId);
    JsonUtils::ObjectAddMember(output, "ItemInstanceId", input.itemInstanceId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "ReceivingCharacterId", input.receivingCharacterId);
    return output;
}

JsonValue MoveItemToCharacterFromUserRequest::ToJson() const
{
    return MoveItemToCharacterFromUserRequest::ToJson(this->Model());
}

JsonValue MoveItemToCharacterFromUserRequest::ToJson(const PFPlayerItemManagementMoveItemToCharacterFromUserRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMember(output, "ItemInstanceId", input.itemInstanceId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue MoveItemToUserFromCharacterRequest::ToJson() const
{
    return MoveItemToUserFromCharacterRequest::ToJson(this->Model());
}

JsonValue MoveItemToUserFromCharacterRequest::ToJson(const PFPlayerItemManagementMoveItemToUserFromCharacterRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMember(output, "ItemInstanceId", input.itemInstanceId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue ServerRedeemCouponRequest::ToJson() const
{
    return ServerRedeemCouponRequest::ToJson(this->Model());
}

JsonValue ServerRedeemCouponRequest::ToJson(const PFPlayerItemManagementServerRedeemCouponRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMember(output, "CouponCode", input.couponCode);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue ReportPlayerServerRequest::ToJson() const
{
    return ReportPlayerServerRequest::ToJson(this->Model());
}

JsonValue ReportPlayerServerRequest::ToJson(const PFPlayerItemManagementReportPlayerServerRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Comment", input.comment);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ReporteeId", input.reporteeId);
    JsonUtils::ObjectAddMember(output, "ReporterId", input.reporterId);
    return output;
}

void ReportPlayerServerResult::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "SubmissionsRemaining", this->m_model.submissionsRemaining);
}

size_t ReportPlayerServerResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlayerItemManagementReportPlayerServerResult const*> ReportPlayerServerResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ReportPlayerServerResult>(&this->Model());
}

size_t ReportPlayerServerResult::RequiredBufferSize(const PFPlayerItemManagementReportPlayerServerResult& model)
{
    UNREFERENCED_PARAMETER(model); // Fixed size
    return sizeof(ModelType);
}

HRESULT ReportPlayerServerResult::Copy(const PFPlayerItemManagementReportPlayerServerResult& input, PFPlayerItemManagementReportPlayerServerResult& output, ModelBuffer& buffer)
{
    output = input;
    UNREFERENCED_PARAMETER(buffer); // Fixed size
    return S_OK;
}

JsonValue SubtractCharacterVirtualCurrencyRequest::ToJson() const
{
    return SubtractCharacterVirtualCurrencyRequest::ToJson(this->Model());
}

JsonValue SubtractCharacterVirtualCurrencyRequest::ToJson(const PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "VirtualCurrency", input.virtualCurrency);
    return output;
}

JsonValue ServerSubtractUserVirtualCurrencyRequest::ToJson() const
{
    return ServerSubtractUserVirtualCurrencyRequest::ToJson(this->Model());
}

JsonValue ServerSubtractUserVirtualCurrencyRequest::ToJson(const PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "VirtualCurrency", input.virtualCurrency);
    return output;
}

JsonValue ServerUnlockContainerInstanceRequest::ToJson() const
{
    return ServerUnlockContainerInstanceRequest::ToJson(this->Model());
}

JsonValue ServerUnlockContainerInstanceRequest::ToJson(const PFPlayerItemManagementServerUnlockContainerInstanceRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMember(output, "ContainerItemInstanceId", input.containerItemInstanceId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "KeyItemInstanceId", input.keyItemInstanceId);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue ServerUnlockContainerItemRequest::ToJson() const
{
    return ServerUnlockContainerItemRequest::ToJson(this->Model());
}

JsonValue ServerUnlockContainerItemRequest::ToJson(const PFPlayerItemManagementServerUnlockContainerItemRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMember(output, "ContainerItemId", input.containerItemId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

JsonValue UpdateUserInventoryItemDataRequest::ToJson() const
{
    return UpdateUserInventoryItemDataRequest::ToJson(this->Model());
}

JsonValue UpdateUserInventoryItemDataRequest::ToJson(const PFPlayerItemManagementUpdateUserInventoryItemDataRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CharacterId", input.characterId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMemberDictionary(output, "Data", input.data, input.dataCount);
    JsonUtils::ObjectAddMember(output, "ItemInstanceId", input.itemInstanceId);
    JsonUtils::ObjectAddMemberArray(output, "KeysToRemove", input.keysToRemove, input.keysToRemoveCount);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    return output;
}

} // namespace PlayerItemManagement
} // namespace PlayFab
