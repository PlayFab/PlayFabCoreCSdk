#include "stdafx.h"
#include "PlatformSpecificDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace PlatformSpecific
{

JsonValue AndroidDevicePushNotificationRegistrationRequest::ToJson() const
{
    return AndroidDevicePushNotificationRegistrationRequest::ToJson(this->Model());
}

JsonValue AndroidDevicePushNotificationRegistrationRequest::ToJson(const PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ConfirmationMessage", input.confirmationMessage);
    JsonUtils::ObjectAddMember(output, "DeviceToken", input.deviceToken);
    JsonUtils::ObjectAddMember(output, "SendPushNotificationConfirmation", input.sendPushNotificationConfirmation);
    return output;
}

JsonValue MicrosoftStorePayload::ToJson() const
{
    return MicrosoftStorePayload::ToJson(this->Model());
}

JsonValue MicrosoftStorePayload::ToJson(const PFPlatformSpecificMicrosoftStorePayload& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CollectionsMsIdKey", input.collectionsMsIdKey);
    JsonUtils::ObjectAddMember(output, "UserId", input.userId);
    JsonUtils::ObjectAddMember(output, "XboxToken", input.xboxToken);
    return output;
}

JsonValue ConsumeMicrosoftStoreEntitlementsRequest::ToJson() const
{
    return ConsumeMicrosoftStoreEntitlementsRequest::ToJson(this->Model());
}

JsonValue ConsumeMicrosoftStoreEntitlementsRequest::ToJson(const PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<MicrosoftStorePayload>(output, "MarketplaceSpecificData", input.marketplaceSpecificData);
    return output;
}

void ConsumeMicrosoftStoreEntitlementsResponse::FromJson(const JsonValue& input)
{
    ModelVector<ItemInstance> items{};
    JsonUtils::ObjectGetMember<ItemInstance>(input, "Items", items);
    this->SetItems(std::move(items));
}

size_t ConsumeMicrosoftStoreEntitlementsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse const*> ConsumeMicrosoftStoreEntitlementsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ConsumeMicrosoftStoreEntitlementsResponse>(&this->Model());
}

size_t ConsumeMicrosoftStoreEntitlementsResponse::RequiredBufferSize(const PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFItemInstance*) + sizeof(PFItemInstance*) * model.itemsCount);
    for (size_t i = 0; i < model.itemsCount; ++i)
    {
        requiredSize += ItemInstance::RequiredBufferSize(*model.items[i]);
    }
    return requiredSize;
}

HRESULT ConsumeMicrosoftStoreEntitlementsResponse::Copy(const PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse& input, PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ItemInstance>(input.items, input.itemsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.items = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue PlayStation5Payload::ToJson() const
{
    return PlayStation5Payload::ToJson(this->Model());
}

JsonValue PlayStation5Payload::ToJson(const PFPlatformSpecificPlayStation5Payload& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray(output, "Ids", input.ids, input.idsCount);
    JsonUtils::ObjectAddMember(output, "ServiceLabel", input.serviceLabel);
    return output;
}

JsonValue ConsumePS5EntitlementsRequest::ToJson() const
{
    return ConsumePS5EntitlementsRequest::ToJson(this->Model());
}

JsonValue ConsumePS5EntitlementsRequest::ToJson(const PFPlatformSpecificConsumePS5EntitlementsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<PlayStation5Payload>(output, "MarketplaceSpecificData", input.marketplaceSpecificData);
    return output;
}

void ConsumePS5EntitlementsResult::FromJson(const JsonValue& input)
{
    ModelVector<ItemInstance> items{};
    JsonUtils::ObjectGetMember<ItemInstance>(input, "Items", items);
    this->SetItems(std::move(items));
}

size_t ConsumePS5EntitlementsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlatformSpecificConsumePS5EntitlementsResult const*> ConsumePS5EntitlementsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ConsumePS5EntitlementsResult>(&this->Model());
}

size_t ConsumePS5EntitlementsResult::RequiredBufferSize(const PFPlatformSpecificConsumePS5EntitlementsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFItemInstance*) + sizeof(PFItemInstance*) * model.itemsCount);
    for (size_t i = 0; i < model.itemsCount; ++i)
    {
        requiredSize += ItemInstance::RequiredBufferSize(*model.items[i]);
    }
    return requiredSize;
}

HRESULT ConsumePS5EntitlementsResult::Copy(const PFPlatformSpecificConsumePS5EntitlementsResult& input, PFPlatformSpecificConsumePS5EntitlementsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ItemInstance>(input.items, input.itemsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.items = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ConsumePSNEntitlementsRequest::ToJson() const
{
    return ConsumePSNEntitlementsRequest::ToJson(this->Model());
}

JsonValue ConsumePSNEntitlementsRequest::ToJson(const PFPlatformSpecificConsumePSNEntitlementsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ServiceLabel", input.serviceLabel);
    return output;
}

void ConsumePSNEntitlementsResult::FromJson(const JsonValue& input)
{
    ModelVector<ItemInstance> itemsGranted{};
    JsonUtils::ObjectGetMember<ItemInstance>(input, "ItemsGranted", itemsGranted);
    this->SetItemsGranted(std::move(itemsGranted));
}

size_t ConsumePSNEntitlementsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlatformSpecificConsumePSNEntitlementsResult const*> ConsumePSNEntitlementsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ConsumePSNEntitlementsResult>(&this->Model());
}

size_t ConsumePSNEntitlementsResult::RequiredBufferSize(const PFPlatformSpecificConsumePSNEntitlementsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFItemInstance*) + sizeof(PFItemInstance*) * model.itemsGrantedCount);
    for (size_t i = 0; i < model.itemsGrantedCount; ++i)
    {
        requiredSize += ItemInstance::RequiredBufferSize(*model.itemsGranted[i]);
    }
    return requiredSize;
}

HRESULT ConsumePSNEntitlementsResult::Copy(const PFPlatformSpecificConsumePSNEntitlementsResult& input, PFPlatformSpecificConsumePSNEntitlementsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ItemInstance>(input.itemsGranted, input.itemsGrantedCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.itemsGranted = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ConsumeXboxEntitlementsRequest::ToJson() const
{
    return ConsumeXboxEntitlementsRequest::ToJson(this->Model());
}

JsonValue ConsumeXboxEntitlementsRequest::ToJson(const PFPlatformSpecificConsumeXboxEntitlementsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "XboxToken", input.xboxToken);
    return output;
}

void ConsumeXboxEntitlementsResult::FromJson(const JsonValue& input)
{
    ModelVector<ItemInstance> items{};
    JsonUtils::ObjectGetMember<ItemInstance>(input, "Items", items);
    this->SetItems(std::move(items));
}

size_t ConsumeXboxEntitlementsResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlatformSpecificConsumeXboxEntitlementsResult const*> ConsumeXboxEntitlementsResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ConsumeXboxEntitlementsResult>(&this->Model());
}

size_t ConsumeXboxEntitlementsResult::RequiredBufferSize(const PFPlatformSpecificConsumeXboxEntitlementsResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFItemInstance*) + sizeof(PFItemInstance*) * model.itemsCount);
    for (size_t i = 0; i < model.itemsCount; ++i)
    {
        requiredSize += ItemInstance::RequiredBufferSize(*model.items[i]);
    }
    return requiredSize;
}

HRESULT ConsumeXboxEntitlementsResult::Copy(const PFPlatformSpecificConsumeXboxEntitlementsResult& input, PFPlatformSpecificConsumeXboxEntitlementsResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ItemInstance>(input.items, input.itemsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.items = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RefreshPSNAuthTokenRequest::ToJson() const
{
    return RefreshPSNAuthTokenRequest::ToJson(this->Model());
}

JsonValue RefreshPSNAuthTokenRequest::ToJson(const PFPlatformSpecificRefreshPSNAuthTokenRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AuthCode", input.authCode);
    JsonUtils::ObjectAddMember(output, "IssuerId", input.issuerId);
    JsonUtils::ObjectAddMember(output, "RedirectUri", input.redirectUri);
    return output;
}

JsonValue RegisterForIOSPushNotificationRequest::ToJson() const
{
    return RegisterForIOSPushNotificationRequest::ToJson(this->Model());
}

JsonValue RegisterForIOSPushNotificationRequest::ToJson(const PFPlatformSpecificRegisterForIOSPushNotificationRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ConfirmationMessage", input.confirmationMessage);
    JsonUtils::ObjectAddMember(output, "DeviceToken", input.deviceToken);
    JsonUtils::ObjectAddMember(output, "SendPushNotificationConfirmation", input.sendPushNotificationConfirmation);
    return output;
}

JsonValue RestoreIOSPurchasesRequest::ToJson() const
{
    return RestoreIOSPurchasesRequest::ToJson(this->Model());
}

JsonValue RestoreIOSPurchasesRequest::ToJson(const PFPlatformSpecificRestoreIOSPurchasesRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "ReceiptData", input.receiptData);
    return output;
}

void PurchaseReceiptFulfillment::FromJson(const JsonValue& input)
{
    ModelVector<ItemInstance> fulfilledItems{};
    JsonUtils::ObjectGetMember<ItemInstance>(input, "FulfilledItems", fulfilledItems);
    this->SetFulfilledItems(std::move(fulfilledItems));

    String recordedPriceSource{};
    JsonUtils::ObjectGetMember(input, "RecordedPriceSource", recordedPriceSource);
    this->SetRecordedPriceSource(std::move(recordedPriceSource));

    String recordedTransactionCurrency{};
    JsonUtils::ObjectGetMember(input, "RecordedTransactionCurrency", recordedTransactionCurrency);
    this->SetRecordedTransactionCurrency(std::move(recordedTransactionCurrency));

    StdExtra::optional<uint32_t> recordedTransactionTotal{};
    JsonUtils::ObjectGetMember(input, "RecordedTransactionTotal", recordedTransactionTotal);
    this->SetRecordedTransactionTotal(std::move(recordedTransactionTotal));
}

size_t PurchaseReceiptFulfillment::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlatformSpecificPurchaseReceiptFulfillment const*> PurchaseReceiptFulfillment::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PurchaseReceiptFulfillment>(&this->Model());
}

size_t PurchaseReceiptFulfillment::RequiredBufferSize(const PFPlatformSpecificPurchaseReceiptFulfillment& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFItemInstance*) + sizeof(PFItemInstance*) * model.fulfilledItemsCount);
    for (size_t i = 0; i < model.fulfilledItemsCount; ++i)
    {
        requiredSize += ItemInstance::RequiredBufferSize(*model.fulfilledItems[i]);
    }
    if (model.recordedPriceSource)
    {
        requiredSize += (std::strlen(model.recordedPriceSource) + 1);
    }
    if (model.recordedTransactionCurrency)
    {
        requiredSize += (std::strlen(model.recordedTransactionCurrency) + 1);
    }
    if (model.recordedTransactionTotal)
    {
        requiredSize += (alignof(uint32_t) + sizeof(uint32_t));
    }
    return requiredSize;
}

HRESULT PurchaseReceiptFulfillment::Copy(const PFPlatformSpecificPurchaseReceiptFulfillment& input, PFPlatformSpecificPurchaseReceiptFulfillment& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<ItemInstance>(input.fulfilledItems, input.fulfilledItemsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.fulfilledItems = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.recordedPriceSource); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.recordedPriceSource = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.recordedTransactionCurrency); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.recordedTransactionCurrency = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.recordedTransactionTotal); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.recordedTransactionTotal = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void RestoreIOSPurchasesResult::FromJson(const JsonValue& input)
{
    ModelVector<PurchaseReceiptFulfillment> fulfillments{};
    JsonUtils::ObjectGetMember<PurchaseReceiptFulfillment>(input, "Fulfillments", fulfillments);
    this->SetFulfillments(std::move(fulfillments));
}

size_t RestoreIOSPurchasesResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlatformSpecificRestoreIOSPurchasesResult const*> RestoreIOSPurchasesResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RestoreIOSPurchasesResult>(&this->Model());
}

size_t RestoreIOSPurchasesResult::RequiredBufferSize(const PFPlatformSpecificRestoreIOSPurchasesResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlatformSpecificPurchaseReceiptFulfillment*) + sizeof(PFPlatformSpecificPurchaseReceiptFulfillment*) * model.fulfillmentsCount);
    for (size_t i = 0; i < model.fulfillmentsCount; ++i)
    {
        requiredSize += PurchaseReceiptFulfillment::RequiredBufferSize(*model.fulfillments[i]);
    }
    return requiredSize;
}

HRESULT RestoreIOSPurchasesResult::Copy(const PFPlatformSpecificRestoreIOSPurchasesResult& input, PFPlatformSpecificRestoreIOSPurchasesResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<PurchaseReceiptFulfillment>(input.fulfillments, input.fulfillmentsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.fulfillments = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ValidateAmazonReceiptRequest::ToJson() const
{
    return ValidateAmazonReceiptRequest::ToJson(this->Model());
}

JsonValue ValidateAmazonReceiptRequest::ToJson(const PFPlatformSpecificValidateAmazonReceiptRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "CurrencyCode", input.currencyCode);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PurchasePrice", input.purchasePrice);
    JsonUtils::ObjectAddMember(output, "ReceiptId", input.receiptId);
    JsonUtils::ObjectAddMember(output, "UserId", input.userId);
    return output;
}

void ValidateAmazonReceiptResult::FromJson(const JsonValue& input)
{
    ModelVector<PurchaseReceiptFulfillment> fulfillments{};
    JsonUtils::ObjectGetMember<PurchaseReceiptFulfillment>(input, "Fulfillments", fulfillments);
    this->SetFulfillments(std::move(fulfillments));
}

size_t ValidateAmazonReceiptResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlatformSpecificValidateAmazonReceiptResult const*> ValidateAmazonReceiptResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ValidateAmazonReceiptResult>(&this->Model());
}

size_t ValidateAmazonReceiptResult::RequiredBufferSize(const PFPlatformSpecificValidateAmazonReceiptResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlatformSpecificPurchaseReceiptFulfillment*) + sizeof(PFPlatformSpecificPurchaseReceiptFulfillment*) * model.fulfillmentsCount);
    for (size_t i = 0; i < model.fulfillmentsCount; ++i)
    {
        requiredSize += PurchaseReceiptFulfillment::RequiredBufferSize(*model.fulfillments[i]);
    }
    return requiredSize;
}

HRESULT ValidateAmazonReceiptResult::Copy(const PFPlatformSpecificValidateAmazonReceiptResult& input, PFPlatformSpecificValidateAmazonReceiptResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<PurchaseReceiptFulfillment>(input.fulfillments, input.fulfillmentsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.fulfillments = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ValidateGooglePlayPurchaseRequest::ToJson() const
{
    return ValidateGooglePlayPurchaseRequest::ToJson(this->Model());
}

JsonValue ValidateGooglePlayPurchaseRequest::ToJson(const PFPlatformSpecificValidateGooglePlayPurchaseRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "CurrencyCode", input.currencyCode);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PurchasePrice", input.purchasePrice);
    JsonUtils::ObjectAddMember(output, "ReceiptJson", input.receiptJson);
    JsonUtils::ObjectAddMember(output, "Signature", input.signature);
    return output;
}

void ValidateGooglePlayPurchaseResult::FromJson(const JsonValue& input)
{
    ModelVector<PurchaseReceiptFulfillment> fulfillments{};
    JsonUtils::ObjectGetMember<PurchaseReceiptFulfillment>(input, "Fulfillments", fulfillments);
    this->SetFulfillments(std::move(fulfillments));
}

size_t ValidateGooglePlayPurchaseResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlatformSpecificValidateGooglePlayPurchaseResult const*> ValidateGooglePlayPurchaseResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ValidateGooglePlayPurchaseResult>(&this->Model());
}

size_t ValidateGooglePlayPurchaseResult::RequiredBufferSize(const PFPlatformSpecificValidateGooglePlayPurchaseResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlatformSpecificPurchaseReceiptFulfillment*) + sizeof(PFPlatformSpecificPurchaseReceiptFulfillment*) * model.fulfillmentsCount);
    for (size_t i = 0; i < model.fulfillmentsCount; ++i)
    {
        requiredSize += PurchaseReceiptFulfillment::RequiredBufferSize(*model.fulfillments[i]);
    }
    return requiredSize;
}

HRESULT ValidateGooglePlayPurchaseResult::Copy(const PFPlatformSpecificValidateGooglePlayPurchaseResult& input, PFPlatformSpecificValidateGooglePlayPurchaseResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<PurchaseReceiptFulfillment>(input.fulfillments, input.fulfillmentsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.fulfillments = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ValidateIOSReceiptRequest::ToJson() const
{
    return ValidateIOSReceiptRequest::ToJson(this->Model());
}

JsonValue ValidateIOSReceiptRequest::ToJson(const PFPlatformSpecificValidateIOSReceiptRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "CurrencyCode", input.currencyCode);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PurchasePrice", input.purchasePrice);
    JsonUtils::ObjectAddMember(output, "ReceiptData", input.receiptData);
    return output;
}

void ValidateIOSReceiptResult::FromJson(const JsonValue& input)
{
    ModelVector<PurchaseReceiptFulfillment> fulfillments{};
    JsonUtils::ObjectGetMember<PurchaseReceiptFulfillment>(input, "Fulfillments", fulfillments);
    this->SetFulfillments(std::move(fulfillments));
}

size_t ValidateIOSReceiptResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlatformSpecificValidateIOSReceiptResult const*> ValidateIOSReceiptResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ValidateIOSReceiptResult>(&this->Model());
}

size_t ValidateIOSReceiptResult::RequiredBufferSize(const PFPlatformSpecificValidateIOSReceiptResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlatformSpecificPurchaseReceiptFulfillment*) + sizeof(PFPlatformSpecificPurchaseReceiptFulfillment*) * model.fulfillmentsCount);
    for (size_t i = 0; i < model.fulfillmentsCount; ++i)
    {
        requiredSize += PurchaseReceiptFulfillment::RequiredBufferSize(*model.fulfillments[i]);
    }
    return requiredSize;
}

HRESULT ValidateIOSReceiptResult::Copy(const PFPlatformSpecificValidateIOSReceiptResult& input, PFPlatformSpecificValidateIOSReceiptResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<PurchaseReceiptFulfillment>(input.fulfillments, input.fulfillmentsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.fulfillments = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue ValidateWindowsReceiptRequest::ToJson() const
{
    return ValidateWindowsReceiptRequest::ToJson(this->Model());
}

JsonValue ValidateWindowsReceiptRequest::ToJson(const PFPlatformSpecificValidateWindowsReceiptRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CatalogVersion", input.catalogVersion);
    JsonUtils::ObjectAddMember(output, "CurrencyCode", input.currencyCode);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "PurchasePrice", input.purchasePrice);
    JsonUtils::ObjectAddMember(output, "Receipt", input.receipt);
    return output;
}

void ValidateWindowsReceiptResult::FromJson(const JsonValue& input)
{
    ModelVector<PurchaseReceiptFulfillment> fulfillments{};
    JsonUtils::ObjectGetMember<PurchaseReceiptFulfillment>(input, "Fulfillments", fulfillments);
    this->SetFulfillments(std::move(fulfillments));
}

size_t ValidateWindowsReceiptResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlatformSpecificValidateWindowsReceiptResult const*> ValidateWindowsReceiptResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ValidateWindowsReceiptResult>(&this->Model());
}

size_t ValidateWindowsReceiptResult::RequiredBufferSize(const PFPlatformSpecificValidateWindowsReceiptResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlatformSpecificPurchaseReceiptFulfillment*) + sizeof(PFPlatformSpecificPurchaseReceiptFulfillment*) * model.fulfillmentsCount);
    for (size_t i = 0; i < model.fulfillmentsCount; ++i)
    {
        requiredSize += PurchaseReceiptFulfillment::RequiredBufferSize(*model.fulfillments[i]);
    }
    return requiredSize;
}

HRESULT ValidateWindowsReceiptResult::Copy(const PFPlatformSpecificValidateWindowsReceiptResult& input, PFPlatformSpecificValidateWindowsReceiptResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<PurchaseReceiptFulfillment>(input.fulfillments, input.fulfillmentsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.fulfillments = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue AwardSteamAchievementItem::ToJson() const
{
    return AwardSteamAchievementItem::ToJson(this->Model());
}

JsonValue AwardSteamAchievementItem::ToJson(const PFPlatformSpecificAwardSteamAchievementItem& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AchievementName", input.achievementName);
    JsonUtils::ObjectAddMember(output, "PlayFabId", input.playFabId);
    JsonUtils::ObjectAddMember(output, "Result", input.result);
    return output;
}

void AwardSteamAchievementItem::FromJson(const JsonValue& input)
{
    String achievementName{};
    JsonUtils::ObjectGetMember(input, "AchievementName", achievementName);
    this->SetAchievementName(std::move(achievementName));

    String playFabId{};
    JsonUtils::ObjectGetMember(input, "PlayFabId", playFabId);
    this->SetPlayFabId(std::move(playFabId));

    JsonUtils::ObjectGetMember(input, "Result", this->m_model.result);
}

size_t AwardSteamAchievementItem::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlatformSpecificAwardSteamAchievementItem const*> AwardSteamAchievementItem::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AwardSteamAchievementItem>(&this->Model());
}

size_t AwardSteamAchievementItem::RequiredBufferSize(const PFPlatformSpecificAwardSteamAchievementItem& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.achievementName)
    {
        requiredSize += (std::strlen(model.achievementName) + 1);
    }
    if (model.playFabId)
    {
        requiredSize += (std::strlen(model.playFabId) + 1);
    }
    return requiredSize;
}

HRESULT AwardSteamAchievementItem::Copy(const PFPlatformSpecificAwardSteamAchievementItem& input, PFPlatformSpecificAwardSteamAchievementItem& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.achievementName); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.achievementName = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.playFabId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.playFabId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue AwardSteamAchievementRequest::ToJson() const
{
    return AwardSteamAchievementRequest::ToJson(this->Model());
}

JsonValue AwardSteamAchievementRequest::ToJson(const PFPlatformSpecificAwardSteamAchievementRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberArray<AwardSteamAchievementItem>(output, "Achievements", input.achievements, input.achievementsCount);
    return output;
}

void AwardSteamAchievementResult::FromJson(const JsonValue& input)
{
    ModelVector<AwardSteamAchievementItem> achievementResults{};
    JsonUtils::ObjectGetMember<AwardSteamAchievementItem>(input, "AchievementResults", achievementResults);
    this->SetAchievementResults(std::move(achievementResults));
}

size_t AwardSteamAchievementResult::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFPlatformSpecificAwardSteamAchievementResult const*> AwardSteamAchievementResult::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AwardSteamAchievementResult>(&this->Model());
}

size_t AwardSteamAchievementResult::RequiredBufferSize(const PFPlatformSpecificAwardSteamAchievementResult& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFPlatformSpecificAwardSteamAchievementItem*) + sizeof(PFPlatformSpecificAwardSteamAchievementItem*) * model.achievementResultsCount);
    for (size_t i = 0; i < model.achievementResultsCount; ++i)
    {
        requiredSize += AwardSteamAchievementItem::RequiredBufferSize(*model.achievementResults[i]);
    }
    return requiredSize;
}

HRESULT AwardSteamAchievementResult::Copy(const PFPlatformSpecificAwardSteamAchievementResult& input, PFPlatformSpecificAwardSteamAchievementResult& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<AwardSteamAchievementItem>(input.achievementResults, input.achievementResultsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.achievementResults = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

} // namespace PlatformSpecific
} // namespace PlayFab
