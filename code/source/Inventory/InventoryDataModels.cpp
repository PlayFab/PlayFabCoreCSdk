#include "stdafx.h"
#include "InventoryDataModels.h"
#include "JsonUtils.h"

namespace PlayFab
{
namespace Inventory
{

JsonValue AlternateId::ToJson() const
{
    return AlternateId::ToJson(this->Model());
}

JsonValue AlternateId::ToJson(const PFInventoryAlternateId& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Type", input.type);
    JsonUtils::ObjectAddMember(output, "Value", input.value);
    return output;
}

JsonValue InventoryItemReference::ToJson() const
{
    return InventoryItemReference::ToJson(this->Model());
}

JsonValue InventoryItemReference::ToJson(const PFInventoryInventoryItemReference& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<AlternateId>(output, "AlternateId", input.alternateId);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    JsonUtils::ObjectAddMember(output, "StackId", input.stackId);
    return output;
}

JsonValue AddInventoryItemsRequest::ToJson() const
{
    return AddInventoryItemsRequest::ToJson(this->Model());
}

JsonValue AddInventoryItemsRequest::ToJson(const PFInventoryAddInventoryItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMember(output, "CollectionId", input.collectionId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "IdempotencyId", input.idempotencyId);
    JsonUtils::ObjectAddMember<InventoryItemReference>(output, "Item", input.item);
    return output;
}

void AddInventoryItemsResponse::FromJson(const JsonValue& input)
{
    String idempotencyId{};
    JsonUtils::ObjectGetMember(input, "IdempotencyId", idempotencyId);
    this->SetIdempotencyId(std::move(idempotencyId));

    CStringVector transactionIds{};
    JsonUtils::ObjectGetMember(input, "TransactionIds", transactionIds);
    this->SetTransactionIds(std::move(transactionIds));
}

size_t AddInventoryItemsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryAddInventoryItemsResponse const*> AddInventoryItemsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<AddInventoryItemsResponse>(&this->Model());
}

size_t AddInventoryItemsResponse::RequiredBufferSize(const PFInventoryAddInventoryItemsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.idempotencyId)
    {
        requiredSize += (std::strlen(model.idempotencyId) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.transactionIdsCount);
    for (size_t i = 0; i < model.transactionIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.transactionIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT AddInventoryItemsResponse::Copy(const PFInventoryAddInventoryItemsResponse& input, PFInventoryAddInventoryItemsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.idempotencyId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.idempotencyId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.transactionIds, input.transactionIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.transactionIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue DeleteInventoryCollectionRequest::ToJson() const
{
    return DeleteInventoryCollectionRequest::ToJson(this->Model());
}

JsonValue DeleteInventoryCollectionRequest::ToJson(const PFInventoryDeleteInventoryCollectionRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CollectionId", input.collectionId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    return output;
}

JsonValue DeleteInventoryItemsRequest::ToJson() const
{
    return DeleteInventoryItemsRequest::ToJson(this->Model());
}

JsonValue DeleteInventoryItemsRequest::ToJson(const PFInventoryDeleteInventoryItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CollectionId", input.collectionId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "IdempotencyId", input.idempotencyId);
    JsonUtils::ObjectAddMember<InventoryItemReference>(output, "Item", input.item);
    return output;
}

void DeleteInventoryItemsResponse::FromJson(const JsonValue& input)
{
    String idempotencyId{};
    JsonUtils::ObjectGetMember(input, "IdempotencyId", idempotencyId);
    this->SetIdempotencyId(std::move(idempotencyId));

    CStringVector transactionIds{};
    JsonUtils::ObjectGetMember(input, "TransactionIds", transactionIds);
    this->SetTransactionIds(std::move(transactionIds));
}

size_t DeleteInventoryItemsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryDeleteInventoryItemsResponse const*> DeleteInventoryItemsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<DeleteInventoryItemsResponse>(&this->Model());
}

size_t DeleteInventoryItemsResponse::RequiredBufferSize(const PFInventoryDeleteInventoryItemsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.idempotencyId)
    {
        requiredSize += (std::strlen(model.idempotencyId) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.transactionIdsCount);
    for (size_t i = 0; i < model.transactionIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.transactionIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT DeleteInventoryItemsResponse::Copy(const PFInventoryDeleteInventoryItemsResponse& input, PFInventoryDeleteInventoryItemsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.idempotencyId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.idempotencyId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.transactionIds, input.transactionIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.transactionIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue AddInventoryItemsOperation::ToJson() const
{
    return AddInventoryItemsOperation::ToJson(this->Model());
}

JsonValue AddInventoryItemsOperation::ToJson(const PFInventoryAddInventoryItemsOperation& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMember<InventoryItemReference>(output, "Item", input.item);
    return output;
}

JsonValue DeleteInventoryItemsOperation::ToJson() const
{
    return DeleteInventoryItemsOperation::ToJson(this->Model());
}

JsonValue DeleteInventoryItemsOperation::ToJson(const PFInventoryDeleteInventoryItemsOperation& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<InventoryItemReference>(output, "Item", input.item);
    return output;
}

JsonValue PurchasePriceAmount::ToJson() const
{
    return PurchasePriceAmount::ToJson(this->Model());
}

JsonValue PurchasePriceAmount::ToJson(const PFInventoryPurchasePriceAmount& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMember(output, "ItemId", input.itemId);
    JsonUtils::ObjectAddMember(output, "StackId", input.stackId);
    return output;
}

JsonValue PurchaseInventoryItemsOperation::ToJson() const
{
    return PurchaseInventoryItemsOperation::ToJson(this->Model());
}

JsonValue PurchaseInventoryItemsOperation::ToJson(const PFInventoryPurchaseInventoryItemsOperation& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMember(output, "DeleteEmptyStacks", input.deleteEmptyStacks);
    JsonUtils::ObjectAddMember<InventoryItemReference>(output, "Item", input.item);
    JsonUtils::ObjectAddMemberArray<PurchasePriceAmount>(output, "PriceAmounts", input.priceAmounts, input.priceAmountsCount);
    JsonUtils::ObjectAddMember(output, "StoreId", input.storeId);
    return output;
}

JsonValue SubtractInventoryItemsOperation::ToJson() const
{
    return SubtractInventoryItemsOperation::ToJson(this->Model());
}

JsonValue SubtractInventoryItemsOperation::ToJson(const PFInventorySubtractInventoryItemsOperation& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMember(output, "DeleteEmptyStacks", input.deleteEmptyStacks);
    JsonUtils::ObjectAddMember<InventoryItemReference>(output, "Item", input.item);
    return output;
}

JsonValue TransferInventoryItemsOperation::ToJson() const
{
    return TransferInventoryItemsOperation::ToJson(this->Model());
}

JsonValue TransferInventoryItemsOperation::ToJson(const PFInventoryTransferInventoryItemsOperation& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMember(output, "DeleteEmptyStacks", input.deleteEmptyStacks);
    JsonUtils::ObjectAddMember<InventoryItemReference>(output, "GivingItem", input.givingItem);
    JsonUtils::ObjectAddMember<InventoryItemReference>(output, "ReceivingItem", input.receivingItem);
    return output;
}

JsonValue InventoryItem::ToJson() const
{
    return InventoryItem::ToJson(this->Model());
}

JsonValue InventoryItem::ToJson(const PFInventoryInventoryItem& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMember(output, "Id", input.id);
    JsonUtils::ObjectAddMember(output, "StackId", input.stackId);
    JsonUtils::ObjectAddMember(output, "Type", input.type);
    return output;
}

void InventoryItem::FromJson(const JsonValue& input)
{
    JsonUtils::ObjectGetMember(input, "Amount", this->m_model.amount);

    String id{};
    JsonUtils::ObjectGetMember(input, "Id", id);
    this->SetId(std::move(id));

    String stackId{};
    JsonUtils::ObjectGetMember(input, "StackId", stackId);
    this->SetStackId(std::move(stackId));

    String type{};
    JsonUtils::ObjectGetMember(input, "Type", type);
    this->SetType(std::move(type));
}

size_t InventoryItem::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryInventoryItem const*> InventoryItem::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<InventoryItem>(&this->Model());
}

size_t InventoryItem::RequiredBufferSize(const PFInventoryInventoryItem& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.id)
    {
        requiredSize += (std::strlen(model.id) + 1);
    }
    if (model.stackId)
    {
        requiredSize += (std::strlen(model.stackId) + 1);
    }
    if (model.type)
    {
        requiredSize += (std::strlen(model.type) + 1);
    }
    return requiredSize;
}

HRESULT InventoryItem::Copy(const PFInventoryInventoryItem& input, PFInventoryInventoryItem& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.id); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.id = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.stackId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.stackId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.type); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.type = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue UpdateInventoryItemsOperation::ToJson() const
{
    return UpdateInventoryItemsOperation::ToJson(this->Model());
}

JsonValue UpdateInventoryItemsOperation::ToJson(const PFInventoryUpdateInventoryItemsOperation& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<InventoryItem>(output, "Item", input.item);
    return output;
}

JsonValue InventoryOperation::ToJson() const
{
    return InventoryOperation::ToJson(this->Model());
}

JsonValue InventoryOperation::ToJson(const PFInventoryInventoryOperation& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember<AddInventoryItemsOperation>(output, "Add", input.add);
    JsonUtils::ObjectAddMember<DeleteInventoryItemsOperation>(output, "Delete", input.delete2);
    JsonUtils::ObjectAddMember<PurchaseInventoryItemsOperation>(output, "Purchase", input.purchase);
    JsonUtils::ObjectAddMember<SubtractInventoryItemsOperation>(output, "Subtract", input.subtract);
    JsonUtils::ObjectAddMember<TransferInventoryItemsOperation>(output, "Transfer", input.transfer);
    JsonUtils::ObjectAddMember<UpdateInventoryItemsOperation>(output, "Update", input.update);
    return output;
}

JsonValue ExecuteInventoryOperationsRequest::ToJson() const
{
    return ExecuteInventoryOperationsRequest::ToJson(this->Model());
}

JsonValue ExecuteInventoryOperationsRequest::ToJson(const PFInventoryExecuteInventoryOperationsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CollectionId", input.collectionId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "IdempotencyId", input.idempotencyId);
    JsonUtils::ObjectAddMemberArray<InventoryOperation>(output, "Operations", input.operations, input.operationsCount);
    return output;
}

void ExecuteInventoryOperationsResponse::FromJson(const JsonValue& input)
{
    String idempotencyId{};
    JsonUtils::ObjectGetMember(input, "IdempotencyId", idempotencyId);
    this->SetIdempotencyId(std::move(idempotencyId));

    CStringVector transactionIds{};
    JsonUtils::ObjectGetMember(input, "TransactionIds", transactionIds);
    this->SetTransactionIds(std::move(transactionIds));
}

size_t ExecuteInventoryOperationsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryExecuteInventoryOperationsResponse const*> ExecuteInventoryOperationsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<ExecuteInventoryOperationsResponse>(&this->Model());
}

size_t ExecuteInventoryOperationsResponse::RequiredBufferSize(const PFInventoryExecuteInventoryOperationsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.idempotencyId)
    {
        requiredSize += (std::strlen(model.idempotencyId) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.transactionIdsCount);
    for (size_t i = 0; i < model.transactionIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.transactionIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT ExecuteInventoryOperationsResponse::Copy(const PFInventoryExecuteInventoryOperationsResponse& input, PFInventoryExecuteInventoryOperationsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.idempotencyId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.idempotencyId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.transactionIds, input.transactionIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.transactionIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetInventoryCollectionIdsRequest::ToJson() const
{
    return GetInventoryCollectionIdsRequest::ToJson(this->Model());
}

JsonValue GetInventoryCollectionIdsRequest::ToJson(const PFInventoryGetInventoryCollectionIdsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ContinuationToken", input.continuationToken);
    JsonUtils::ObjectAddMember(output, "Count", input.count);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    return output;
}

void GetInventoryCollectionIdsResponse::FromJson(const JsonValue& input)
{
    CStringVector collectionIds{};
    JsonUtils::ObjectGetMember(input, "CollectionIds", collectionIds);
    this->SetCollectionIds(std::move(collectionIds));

    String continuationToken{};
    JsonUtils::ObjectGetMember(input, "ContinuationToken", continuationToken);
    this->SetContinuationToken(std::move(continuationToken));
}

size_t GetInventoryCollectionIdsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryGetInventoryCollectionIdsResponse const*> GetInventoryCollectionIdsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetInventoryCollectionIdsResponse>(&this->Model());
}

size_t GetInventoryCollectionIdsResponse::RequiredBufferSize(const PFInventoryGetInventoryCollectionIdsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(char*) + sizeof(char*) * model.collectionIdsCount);
    for (size_t i = 0; i < model.collectionIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.collectionIds[i]) + 1);
    }
    if (model.continuationToken)
    {
        requiredSize += (std::strlen(model.continuationToken) + 1);
    }
    return requiredSize;
}

HRESULT GetInventoryCollectionIdsResponse::Copy(const PFInventoryGetInventoryCollectionIdsResponse& input, PFInventoryGetInventoryCollectionIdsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray(input.collectionIds, input.collectionIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.collectionIds = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.continuationToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.continuationToken = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetInventoryItemsRequest::ToJson() const
{
    return GetInventoryItemsRequest::ToJson(this->Model());
}

JsonValue GetInventoryItemsRequest::ToJson(const PFInventoryGetInventoryItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CollectionId", input.collectionId);
    JsonUtils::ObjectAddMember(output, "ContinuationToken", input.continuationToken);
    JsonUtils::ObjectAddMember(output, "Count", input.count);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "Filter", input.filter);
    return output;
}

void GetInventoryItemsResponse::FromJson(const JsonValue& input)
{
    String continuationToken{};
    JsonUtils::ObjectGetMember(input, "ContinuationToken", continuationToken);
    this->SetContinuationToken(std::move(continuationToken));

    ModelVector<InventoryItem> items{};
    JsonUtils::ObjectGetMember<InventoryItem>(input, "Items", items);
    this->SetItems(std::move(items));
}

size_t GetInventoryItemsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryGetInventoryItemsResponse const*> GetInventoryItemsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetInventoryItemsResponse>(&this->Model());
}

size_t GetInventoryItemsResponse::RequiredBufferSize(const PFInventoryGetInventoryItemsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.continuationToken)
    {
        requiredSize += (std::strlen(model.continuationToken) + 1);
    }
    requiredSize += (alignof(PFInventoryInventoryItem*) + sizeof(PFInventoryInventoryItem*) * model.itemsCount);
    for (size_t i = 0; i < model.itemsCount; ++i)
    {
        requiredSize += InventoryItem::RequiredBufferSize(*model.items[i]);
    }
    return requiredSize;
}

HRESULT GetInventoryItemsResponse::Copy(const PFInventoryGetInventoryItemsResponse& input, PFInventoryGetInventoryItemsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.continuationToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.continuationToken = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<InventoryItem>(input.items, input.itemsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.items = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GetMicrosoftStoreAccessTokensRequest::ToJson() const
{
    return GetMicrosoftStoreAccessTokensRequest::ToJson(this->Model());
}

JsonValue GetMicrosoftStoreAccessTokensRequest::ToJson(const PFInventoryGetMicrosoftStoreAccessTokensRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    return output;
}

void GetMicrosoftStoreAccessTokensResponse::FromJson(const JsonValue& input)
{
    String collectionsAccessToken{};
    JsonUtils::ObjectGetMember(input, "CollectionsAccessToken", collectionsAccessToken);
    this->SetCollectionsAccessToken(std::move(collectionsAccessToken));

    JsonUtils::ObjectGetMemberTime(input, "CollectionsAccessTokenExpirationDate", this->m_model.collectionsAccessTokenExpirationDate);
}

size_t GetMicrosoftStoreAccessTokensResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryGetMicrosoftStoreAccessTokensResponse const*> GetMicrosoftStoreAccessTokensResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<GetMicrosoftStoreAccessTokensResponse>(&this->Model());
}

size_t GetMicrosoftStoreAccessTokensResponse::RequiredBufferSize(const PFInventoryGetMicrosoftStoreAccessTokensResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.collectionsAccessToken)
    {
        requiredSize += (std::strlen(model.collectionsAccessToken) + 1);
    }
    return requiredSize;
}

HRESULT GetMicrosoftStoreAccessTokensResponse::Copy(const PFInventoryGetMicrosoftStoreAccessTokensResponse& input, PFInventoryGetMicrosoftStoreAccessTokensResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.collectionsAccessToken); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.collectionsAccessToken = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue PurchaseInventoryItemsRequest::ToJson() const
{
    return PurchaseInventoryItemsRequest::ToJson(this->Model());
}

JsonValue PurchaseInventoryItemsRequest::ToJson(const PFInventoryPurchaseInventoryItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMember(output, "CollectionId", input.collectionId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "DeleteEmptyStacks", input.deleteEmptyStacks);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "IdempotencyId", input.idempotencyId);
    JsonUtils::ObjectAddMember<InventoryItemReference>(output, "Item", input.item);
    JsonUtils::ObjectAddMemberArray<PurchasePriceAmount>(output, "PriceAmounts", input.priceAmounts, input.priceAmountsCount);
    JsonUtils::ObjectAddMember(output, "StoreId", input.storeId);
    return output;
}

void PurchaseInventoryItemsResponse::FromJson(const JsonValue& input)
{
    String idempotencyId{};
    JsonUtils::ObjectGetMember(input, "IdempotencyId", idempotencyId);
    this->SetIdempotencyId(std::move(idempotencyId));

    CStringVector transactionIds{};
    JsonUtils::ObjectGetMember(input, "TransactionIds", transactionIds);
    this->SetTransactionIds(std::move(transactionIds));
}

size_t PurchaseInventoryItemsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryPurchaseInventoryItemsResponse const*> PurchaseInventoryItemsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<PurchaseInventoryItemsResponse>(&this->Model());
}

size_t PurchaseInventoryItemsResponse::RequiredBufferSize(const PFInventoryPurchaseInventoryItemsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.idempotencyId)
    {
        requiredSize += (std::strlen(model.idempotencyId) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.transactionIdsCount);
    for (size_t i = 0; i < model.transactionIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.transactionIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT PurchaseInventoryItemsResponse::Copy(const PFInventoryPurchaseInventoryItemsResponse& input, PFInventoryPurchaseInventoryItemsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.idempotencyId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.idempotencyId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.transactionIds, input.transactionIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.transactionIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RedeemAppleAppStoreInventoryItemsRequest::ToJson() const
{
    return RedeemAppleAppStoreInventoryItemsRequest::ToJson(this->Model());
}

JsonValue RedeemAppleAppStoreInventoryItemsRequest::ToJson(const PFInventoryRedeemAppleAppStoreInventoryItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CollectionId", input.collectionId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "Receipt", input.receipt);
    return output;
}

void RedemptionFailure::FromJson(const JsonValue& input)
{
    String failureCode{};
    JsonUtils::ObjectGetMember(input, "FailureCode", failureCode);
    this->SetFailureCode(std::move(failureCode));

    String failureDetails{};
    JsonUtils::ObjectGetMember(input, "FailureDetails", failureDetails);
    this->SetFailureDetails(std::move(failureDetails));

    String marketplaceTransactionId{};
    JsonUtils::ObjectGetMember(input, "MarketplaceTransactionId", marketplaceTransactionId);
    this->SetMarketplaceTransactionId(std::move(marketplaceTransactionId));

    String offerId{};
    JsonUtils::ObjectGetMember(input, "OfferId", offerId);
    this->SetOfferId(std::move(offerId));
}

size_t RedemptionFailure::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryRedemptionFailure const*> RedemptionFailure::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RedemptionFailure>(&this->Model());
}

size_t RedemptionFailure::RequiredBufferSize(const PFInventoryRedemptionFailure& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.failureCode)
    {
        requiredSize += (std::strlen(model.failureCode) + 1);
    }
    if (model.failureDetails)
    {
        requiredSize += (std::strlen(model.failureDetails) + 1);
    }
    if (model.marketplaceTransactionId)
    {
        requiredSize += (std::strlen(model.marketplaceTransactionId) + 1);
    }
    if (model.offerId)
    {
        requiredSize += (std::strlen(model.offerId) + 1);
    }
    return requiredSize;
}

HRESULT RedemptionFailure::Copy(const PFInventoryRedemptionFailure& input, PFInventoryRedemptionFailure& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.failureCode); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.failureCode = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.failureDetails); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.failureDetails = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.marketplaceTransactionId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.marketplaceTransactionId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.offerId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.offerId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void RedemptionSuccess::FromJson(const JsonValue& input)
{
    String marketplaceTransactionId{};
    JsonUtils::ObjectGetMember(input, "MarketplaceTransactionId", marketplaceTransactionId);
    this->SetMarketplaceTransactionId(std::move(marketplaceTransactionId));

    String offerId{};
    JsonUtils::ObjectGetMember(input, "OfferId", offerId);
    this->SetOfferId(std::move(offerId));

    JsonUtils::ObjectGetMemberTime(input, "SuccessTimestamp", this->m_model.successTimestamp);
}

size_t RedemptionSuccess::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryRedemptionSuccess const*> RedemptionSuccess::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RedemptionSuccess>(&this->Model());
}

size_t RedemptionSuccess::RequiredBufferSize(const PFInventoryRedemptionSuccess& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.marketplaceTransactionId)
    {
        requiredSize += (std::strlen(model.marketplaceTransactionId) + 1);
    }
    if (model.offerId)
    {
        requiredSize += (std::strlen(model.offerId) + 1);
    }
    return requiredSize;
}

HRESULT RedemptionSuccess::Copy(const PFInventoryRedemptionSuccess& input, PFInventoryRedemptionSuccess& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.marketplaceTransactionId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.marketplaceTransactionId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.offerId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.offerId = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

void RedeemAppleAppStoreInventoryItemsResponse::FromJson(const JsonValue& input)
{
    ModelVector<RedemptionFailure> failed{};
    JsonUtils::ObjectGetMember<RedemptionFailure>(input, "Failed", failed);
    this->SetFailed(std::move(failed));

    ModelVector<RedemptionSuccess> succeeded{};
    JsonUtils::ObjectGetMember<RedemptionSuccess>(input, "Succeeded", succeeded);
    this->SetSucceeded(std::move(succeeded));

    CStringVector transactionIds{};
    JsonUtils::ObjectGetMember(input, "TransactionIds", transactionIds);
    this->SetTransactionIds(std::move(transactionIds));
}

size_t RedeemAppleAppStoreInventoryItemsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryRedeemAppleAppStoreInventoryItemsResponse const*> RedeemAppleAppStoreInventoryItemsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RedeemAppleAppStoreInventoryItemsResponse>(&this->Model());
}

size_t RedeemAppleAppStoreInventoryItemsResponse::RequiredBufferSize(const PFInventoryRedeemAppleAppStoreInventoryItemsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFInventoryRedemptionFailure*) + sizeof(PFInventoryRedemptionFailure*) * model.failedCount);
    for (size_t i = 0; i < model.failedCount; ++i)
    {
        requiredSize += RedemptionFailure::RequiredBufferSize(*model.failed[i]);
    }
    requiredSize += (alignof(PFInventoryRedemptionSuccess*) + sizeof(PFInventoryRedemptionSuccess*) * model.succeededCount);
    for (size_t i = 0; i < model.succeededCount; ++i)
    {
        requiredSize += RedemptionSuccess::RequiredBufferSize(*model.succeeded[i]);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.transactionIdsCount);
    for (size_t i = 0; i < model.transactionIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.transactionIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT RedeemAppleAppStoreInventoryItemsResponse::Copy(const PFInventoryRedeemAppleAppStoreInventoryItemsResponse& input, PFInventoryRedeemAppleAppStoreInventoryItemsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<RedemptionFailure>(input.failed, input.failedCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.failed = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<RedemptionSuccess>(input.succeeded, input.succeededCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.succeeded = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.transactionIds, input.transactionIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.transactionIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue GooglePlayProductPurchase::ToJson() const
{
    return GooglePlayProductPurchase::ToJson(this->Model());
}

JsonValue GooglePlayProductPurchase::ToJson(const PFInventoryGooglePlayProductPurchase& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "ProductId", input.productId);
    JsonUtils::ObjectAddMember(output, "Token", input.token);
    return output;
}

JsonValue RedeemGooglePlayInventoryItemsRequest::ToJson() const
{
    return RedeemGooglePlayInventoryItemsRequest::ToJson(this->Model());
}

JsonValue RedeemGooglePlayInventoryItemsRequest::ToJson(const PFInventoryRedeemGooglePlayInventoryItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CollectionId", input.collectionId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMemberArray<GooglePlayProductPurchase>(output, "Purchases", input.purchases, input.purchasesCount);
    return output;
}

void RedeemGooglePlayInventoryItemsResponse::FromJson(const JsonValue& input)
{
    ModelVector<RedemptionFailure> failed{};
    JsonUtils::ObjectGetMember<RedemptionFailure>(input, "Failed", failed);
    this->SetFailed(std::move(failed));

    ModelVector<RedemptionSuccess> succeeded{};
    JsonUtils::ObjectGetMember<RedemptionSuccess>(input, "Succeeded", succeeded);
    this->SetSucceeded(std::move(succeeded));

    CStringVector transactionIds{};
    JsonUtils::ObjectGetMember(input, "TransactionIds", transactionIds);
    this->SetTransactionIds(std::move(transactionIds));
}

size_t RedeemGooglePlayInventoryItemsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryRedeemGooglePlayInventoryItemsResponse const*> RedeemGooglePlayInventoryItemsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RedeemGooglePlayInventoryItemsResponse>(&this->Model());
}

size_t RedeemGooglePlayInventoryItemsResponse::RequiredBufferSize(const PFInventoryRedeemGooglePlayInventoryItemsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFInventoryRedemptionFailure*) + sizeof(PFInventoryRedemptionFailure*) * model.failedCount);
    for (size_t i = 0; i < model.failedCount; ++i)
    {
        requiredSize += RedemptionFailure::RequiredBufferSize(*model.failed[i]);
    }
    requiredSize += (alignof(PFInventoryRedemptionSuccess*) + sizeof(PFInventoryRedemptionSuccess*) * model.succeededCount);
    for (size_t i = 0; i < model.succeededCount; ++i)
    {
        requiredSize += RedemptionSuccess::RequiredBufferSize(*model.succeeded[i]);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.transactionIdsCount);
    for (size_t i = 0; i < model.transactionIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.transactionIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT RedeemGooglePlayInventoryItemsResponse::Copy(const PFInventoryRedeemGooglePlayInventoryItemsResponse& input, PFInventoryRedeemGooglePlayInventoryItemsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<RedemptionFailure>(input.failed, input.failedCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.failed = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<RedemptionSuccess>(input.succeeded, input.succeededCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.succeeded = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.transactionIds, input.transactionIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.transactionIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RedeemMicrosoftStoreInventoryItemsRequest::ToJson() const
{
    return RedeemMicrosoftStoreInventoryItemsRequest::ToJson(this->Model());
}

JsonValue RedeemMicrosoftStoreInventoryItemsRequest::ToJson(const PFInventoryRedeemMicrosoftStoreInventoryItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CollectionId", input.collectionId);
    JsonUtils::ObjectAddMember(output, "CollectionsIdKey", input.collectionsIdKey);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "XboxToken", input.xboxToken);
    return output;
}

void RedeemMicrosoftStoreInventoryItemsResponse::FromJson(const JsonValue& input)
{
    ModelVector<RedemptionFailure> failed{};
    JsonUtils::ObjectGetMember<RedemptionFailure>(input, "Failed", failed);
    this->SetFailed(std::move(failed));

    ModelVector<RedemptionSuccess> succeeded{};
    JsonUtils::ObjectGetMember<RedemptionSuccess>(input, "Succeeded", succeeded);
    this->SetSucceeded(std::move(succeeded));

    CStringVector transactionIds{};
    JsonUtils::ObjectGetMember(input, "TransactionIds", transactionIds);
    this->SetTransactionIds(std::move(transactionIds));
}

size_t RedeemMicrosoftStoreInventoryItemsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryRedeemMicrosoftStoreInventoryItemsResponse const*> RedeemMicrosoftStoreInventoryItemsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RedeemMicrosoftStoreInventoryItemsResponse>(&this->Model());
}

size_t RedeemMicrosoftStoreInventoryItemsResponse::RequiredBufferSize(const PFInventoryRedeemMicrosoftStoreInventoryItemsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFInventoryRedemptionFailure*) + sizeof(PFInventoryRedemptionFailure*) * model.failedCount);
    for (size_t i = 0; i < model.failedCount; ++i)
    {
        requiredSize += RedemptionFailure::RequiredBufferSize(*model.failed[i]);
    }
    requiredSize += (alignof(PFInventoryRedemptionSuccess*) + sizeof(PFInventoryRedemptionSuccess*) * model.succeededCount);
    for (size_t i = 0; i < model.succeededCount; ++i)
    {
        requiredSize += RedemptionSuccess::RequiredBufferSize(*model.succeeded[i]);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.transactionIdsCount);
    for (size_t i = 0; i < model.transactionIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.transactionIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT RedeemMicrosoftStoreInventoryItemsResponse::Copy(const PFInventoryRedeemMicrosoftStoreInventoryItemsResponse& input, PFInventoryRedeemMicrosoftStoreInventoryItemsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<RedemptionFailure>(input.failed, input.failedCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.failed = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<RedemptionSuccess>(input.succeeded, input.succeededCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.succeeded = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.transactionIds, input.transactionIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.transactionIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RedeemNintendoEShopInventoryItemsRequest::ToJson() const
{
    return RedeemNintendoEShopInventoryItemsRequest::ToJson(this->Model());
}

JsonValue RedeemNintendoEShopInventoryItemsRequest::ToJson(const PFInventoryRedeemNintendoEShopInventoryItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CollectionId", input.collectionId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "NintendoServiceAccountIdToken", input.nintendoServiceAccountIdToken);
    return output;
}

void RedeemNintendoEShopInventoryItemsResponse::FromJson(const JsonValue& input)
{
    ModelVector<RedemptionFailure> failed{};
    JsonUtils::ObjectGetMember<RedemptionFailure>(input, "Failed", failed);
    this->SetFailed(std::move(failed));

    ModelVector<RedemptionSuccess> succeeded{};
    JsonUtils::ObjectGetMember<RedemptionSuccess>(input, "Succeeded", succeeded);
    this->SetSucceeded(std::move(succeeded));

    CStringVector transactionIds{};
    JsonUtils::ObjectGetMember(input, "TransactionIds", transactionIds);
    this->SetTransactionIds(std::move(transactionIds));
}

size_t RedeemNintendoEShopInventoryItemsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryRedeemNintendoEShopInventoryItemsResponse const*> RedeemNintendoEShopInventoryItemsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RedeemNintendoEShopInventoryItemsResponse>(&this->Model());
}

size_t RedeemNintendoEShopInventoryItemsResponse::RequiredBufferSize(const PFInventoryRedeemNintendoEShopInventoryItemsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFInventoryRedemptionFailure*) + sizeof(PFInventoryRedemptionFailure*) * model.failedCount);
    for (size_t i = 0; i < model.failedCount; ++i)
    {
        requiredSize += RedemptionFailure::RequiredBufferSize(*model.failed[i]);
    }
    requiredSize += (alignof(PFInventoryRedemptionSuccess*) + sizeof(PFInventoryRedemptionSuccess*) * model.succeededCount);
    for (size_t i = 0; i < model.succeededCount; ++i)
    {
        requiredSize += RedemptionSuccess::RequiredBufferSize(*model.succeeded[i]);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.transactionIdsCount);
    for (size_t i = 0; i < model.transactionIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.transactionIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT RedeemNintendoEShopInventoryItemsResponse::Copy(const PFInventoryRedeemNintendoEShopInventoryItemsResponse& input, PFInventoryRedeemNintendoEShopInventoryItemsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<RedemptionFailure>(input.failed, input.failedCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.failed = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<RedemptionSuccess>(input.succeeded, input.succeededCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.succeeded = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.transactionIds, input.transactionIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.transactionIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RedeemPlayStationStoreInventoryItemsRequest::ToJson() const
{
    return RedeemPlayStationStoreInventoryItemsRequest::ToJson(this->Model());
}

JsonValue RedeemPlayStationStoreInventoryItemsRequest::ToJson(const PFInventoryRedeemPlayStationStoreInventoryItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "AuthorizationCode", input.authorizationCode);
    JsonUtils::ObjectAddMember(output, "CollectionId", input.collectionId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "ServiceLabel", input.serviceLabel);
    return output;
}

void RedeemPlayStationStoreInventoryItemsResponse::FromJson(const JsonValue& input)
{
    ModelVector<RedemptionFailure> failed{};
    JsonUtils::ObjectGetMember<RedemptionFailure>(input, "Failed", failed);
    this->SetFailed(std::move(failed));

    ModelVector<RedemptionSuccess> succeeded{};
    JsonUtils::ObjectGetMember<RedemptionSuccess>(input, "Succeeded", succeeded);
    this->SetSucceeded(std::move(succeeded));

    CStringVector transactionIds{};
    JsonUtils::ObjectGetMember(input, "TransactionIds", transactionIds);
    this->SetTransactionIds(std::move(transactionIds));
}

size_t RedeemPlayStationStoreInventoryItemsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryRedeemPlayStationStoreInventoryItemsResponse const*> RedeemPlayStationStoreInventoryItemsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RedeemPlayStationStoreInventoryItemsResponse>(&this->Model());
}

size_t RedeemPlayStationStoreInventoryItemsResponse::RequiredBufferSize(const PFInventoryRedeemPlayStationStoreInventoryItemsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFInventoryRedemptionFailure*) + sizeof(PFInventoryRedemptionFailure*) * model.failedCount);
    for (size_t i = 0; i < model.failedCount; ++i)
    {
        requiredSize += RedemptionFailure::RequiredBufferSize(*model.failed[i]);
    }
    requiredSize += (alignof(PFInventoryRedemptionSuccess*) + sizeof(PFInventoryRedemptionSuccess*) * model.succeededCount);
    for (size_t i = 0; i < model.succeededCount; ++i)
    {
        requiredSize += RedemptionSuccess::RequiredBufferSize(*model.succeeded[i]);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.transactionIdsCount);
    for (size_t i = 0; i < model.transactionIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.transactionIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT RedeemPlayStationStoreInventoryItemsResponse::Copy(const PFInventoryRedeemPlayStationStoreInventoryItemsResponse& input, PFInventoryRedeemPlayStationStoreInventoryItemsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<RedemptionFailure>(input.failed, input.failedCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.failed = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<RedemptionSuccess>(input.succeeded, input.succeededCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.succeeded = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.transactionIds, input.transactionIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.transactionIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue RedeemSteamInventoryItemsRequest::ToJson() const
{
    return RedeemSteamInventoryItemsRequest::ToJson(this->Model());
}

JsonValue RedeemSteamInventoryItemsRequest::ToJson(const PFInventoryRedeemSteamInventoryItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CollectionId", input.collectionId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    return output;
}

void RedeemSteamInventoryItemsResponse::FromJson(const JsonValue& input)
{
    ModelVector<RedemptionFailure> failed{};
    JsonUtils::ObjectGetMember<RedemptionFailure>(input, "Failed", failed);
    this->SetFailed(std::move(failed));

    ModelVector<RedemptionSuccess> succeeded{};
    JsonUtils::ObjectGetMember<RedemptionSuccess>(input, "Succeeded", succeeded);
    this->SetSucceeded(std::move(succeeded));

    CStringVector transactionIds{};
    JsonUtils::ObjectGetMember(input, "TransactionIds", transactionIds);
    this->SetTransactionIds(std::move(transactionIds));
}

size_t RedeemSteamInventoryItemsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryRedeemSteamInventoryItemsResponse const*> RedeemSteamInventoryItemsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<RedeemSteamInventoryItemsResponse>(&this->Model());
}

size_t RedeemSteamInventoryItemsResponse::RequiredBufferSize(const PFInventoryRedeemSteamInventoryItemsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(PFInventoryRedemptionFailure*) + sizeof(PFInventoryRedemptionFailure*) * model.failedCount);
    for (size_t i = 0; i < model.failedCount; ++i)
    {
        requiredSize += RedemptionFailure::RequiredBufferSize(*model.failed[i]);
    }
    requiredSize += (alignof(PFInventoryRedemptionSuccess*) + sizeof(PFInventoryRedemptionSuccess*) * model.succeededCount);
    for (size_t i = 0; i < model.succeededCount; ++i)
    {
        requiredSize += RedemptionSuccess::RequiredBufferSize(*model.succeeded[i]);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.transactionIdsCount);
    for (size_t i = 0; i < model.transactionIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.transactionIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT RedeemSteamInventoryItemsResponse::Copy(const PFInventoryRedeemSteamInventoryItemsResponse& input, PFInventoryRedeemSteamInventoryItemsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray<RedemptionFailure>(input.failed, input.failedCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.failed = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray<RedemptionSuccess>(input.succeeded, input.succeededCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.succeeded = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.transactionIds, input.transactionIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.transactionIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue SubtractInventoryItemsRequest::ToJson() const
{
    return SubtractInventoryItemsRequest::ToJson(this->Model());
}

JsonValue SubtractInventoryItemsRequest::ToJson(const PFInventorySubtractInventoryItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMember(output, "CollectionId", input.collectionId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "DeleteEmptyStacks", input.deleteEmptyStacks);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "IdempotencyId", input.idempotencyId);
    JsonUtils::ObjectAddMember<InventoryItemReference>(output, "Item", input.item);
    return output;
}

void SubtractInventoryItemsResponse::FromJson(const JsonValue& input)
{
    String idempotencyId{};
    JsonUtils::ObjectGetMember(input, "IdempotencyId", idempotencyId);
    this->SetIdempotencyId(std::move(idempotencyId));

    CStringVector transactionIds{};
    JsonUtils::ObjectGetMember(input, "TransactionIds", transactionIds);
    this->SetTransactionIds(std::move(transactionIds));
}

size_t SubtractInventoryItemsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventorySubtractInventoryItemsResponse const*> SubtractInventoryItemsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<SubtractInventoryItemsResponse>(&this->Model());
}

size_t SubtractInventoryItemsResponse::RequiredBufferSize(const PFInventorySubtractInventoryItemsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.idempotencyId)
    {
        requiredSize += (std::strlen(model.idempotencyId) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.transactionIdsCount);
    for (size_t i = 0; i < model.transactionIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.transactionIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT SubtractInventoryItemsResponse::Copy(const PFInventorySubtractInventoryItemsResponse& input, PFInventorySubtractInventoryItemsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.idempotencyId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.idempotencyId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.transactionIds, input.transactionIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.transactionIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue TransferInventoryItemsRequest::ToJson() const
{
    return TransferInventoryItemsRequest::ToJson(this->Model());
}

JsonValue TransferInventoryItemsRequest::ToJson(const PFInventoryTransferInventoryItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "Amount", input.amount);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember(output, "DeleteEmptyStacks", input.deleteEmptyStacks);
    JsonUtils::ObjectAddMember(output, "GivingCollectionId", input.givingCollectionId);
    JsonUtils::ObjectAddMember<EntityKey>(output, "GivingEntity", input.givingEntity);
    JsonUtils::ObjectAddMember<InventoryItemReference>(output, "GivingItem", input.givingItem);
    JsonUtils::ObjectAddMember(output, "IdempotencyId", input.idempotencyId);
    JsonUtils::ObjectAddMember(output, "ReceivingCollectionId", input.receivingCollectionId);
    JsonUtils::ObjectAddMember<EntityKey>(output, "ReceivingEntity", input.receivingEntity);
    JsonUtils::ObjectAddMember<InventoryItemReference>(output, "ReceivingItem", input.receivingItem);
    return output;
}

void TransferInventoryItemsResponse::FromJson(const JsonValue& input)
{
    CStringVector givingTransactionIds{};
    JsonUtils::ObjectGetMember(input, "GivingTransactionIds", givingTransactionIds);
    this->SetGivingTransactionIds(std::move(givingTransactionIds));

    String idempotencyId{};
    JsonUtils::ObjectGetMember(input, "IdempotencyId", idempotencyId);
    this->SetIdempotencyId(std::move(idempotencyId));

    CStringVector receivingTransactionIds{};
    JsonUtils::ObjectGetMember(input, "ReceivingTransactionIds", receivingTransactionIds);
    this->SetReceivingTransactionIds(std::move(receivingTransactionIds));
}

size_t TransferInventoryItemsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryTransferInventoryItemsResponse const*> TransferInventoryItemsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<TransferInventoryItemsResponse>(&this->Model());
}

size_t TransferInventoryItemsResponse::RequiredBufferSize(const PFInventoryTransferInventoryItemsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    requiredSize += (alignof(char*) + sizeof(char*) * model.givingTransactionIdsCount);
    for (size_t i = 0; i < model.givingTransactionIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.givingTransactionIds[i]) + 1);
    }
    if (model.idempotencyId)
    {
        requiredSize += (std::strlen(model.idempotencyId) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.receivingTransactionIdsCount);
    for (size_t i = 0; i < model.receivingTransactionIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.receivingTransactionIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT TransferInventoryItemsResponse::Copy(const PFInventoryTransferInventoryItemsResponse& input, PFInventoryTransferInventoryItemsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyToArray(input.givingTransactionIds, input.givingTransactionIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.givingTransactionIds = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyTo(input.idempotencyId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.idempotencyId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.receivingTransactionIds, input.receivingTransactionIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.receivingTransactionIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

JsonValue UpdateInventoryItemsRequest::ToJson() const
{
    return UpdateInventoryItemsRequest::ToJson(this->Model());
}

JsonValue UpdateInventoryItemsRequest::ToJson(const PFInventoryUpdateInventoryItemsRequest& input)
{
    JsonValue output{ rapidjson::kObjectType };
    JsonUtils::ObjectAddMember(output, "CollectionId", input.collectionId);
    JsonUtils::ObjectAddMemberDictionary(output, "CustomTags", input.customTags, input.customTagsCount);
    JsonUtils::ObjectAddMember<EntityKey>(output, "Entity", input.entity);
    JsonUtils::ObjectAddMember(output, "IdempotencyId", input.idempotencyId);
    JsonUtils::ObjectAddMember<InventoryItem>(output, "Item", input.item);
    return output;
}

void UpdateInventoryItemsResponse::FromJson(const JsonValue& input)
{
    String idempotencyId{};
    JsonUtils::ObjectGetMember(input, "IdempotencyId", idempotencyId);
    this->SetIdempotencyId(std::move(idempotencyId));

    CStringVector transactionIds{};
    JsonUtils::ObjectGetMember(input, "TransactionIds", transactionIds);
    this->SetTransactionIds(std::move(transactionIds));
}

size_t UpdateInventoryItemsResponse::RequiredBufferSize() const
{
    return RequiredBufferSize(this->Model());
}

Result<PFInventoryUpdateInventoryItemsResponse const*> UpdateInventoryItemsResponse::Copy(ModelBuffer& buffer) const
{
    return buffer.CopyTo<UpdateInventoryItemsResponse>(&this->Model());
}

size_t UpdateInventoryItemsResponse::RequiredBufferSize(const PFInventoryUpdateInventoryItemsResponse& model)
{
    size_t requiredSize{ alignof(ModelType) + sizeof(ModelType) };
    if (model.idempotencyId)
    {
        requiredSize += (std::strlen(model.idempotencyId) + 1);
    }
    requiredSize += (alignof(char*) + sizeof(char*) * model.transactionIdsCount);
    for (size_t i = 0; i < model.transactionIdsCount; ++i)
    {
        requiredSize += (std::strlen(model.transactionIds[i]) + 1);
    }
    return requiredSize;
}

HRESULT UpdateInventoryItemsResponse::Copy(const PFInventoryUpdateInventoryItemsResponse& input, PFInventoryUpdateInventoryItemsResponse& output, ModelBuffer& buffer)
{
    output = input;
    {
        auto propCopyResult = buffer.CopyTo(input.idempotencyId); 
        RETURN_IF_FAILED(propCopyResult.hr);
        output.idempotencyId = propCopyResult.ExtractPayload();
    }
    {
        auto propCopyResult = buffer.CopyToArray(input.transactionIds, input.transactionIdsCount);
        RETURN_IF_FAILED(propCopyResult.hr);
        output.transactionIds = propCopyResult.ExtractPayload();
    }
    return S_OK;
}

} // namespace Inventory
} // namespace PlayFab
