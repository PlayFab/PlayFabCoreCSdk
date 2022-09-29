// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFSharedDataModels.h>

extern "C"
{

#pragma push_macro("IN")
#undef IN

/// <summary>
/// PFInventoryAlternateId data model.
/// </summary>
typedef struct PFInventoryAlternateId
{
    /// <summary>
    /// (Optional) Type of the alternate ID.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* type;

    /// <summary>
    /// (Optional) Value of the alternate ID.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* value;

} PFInventoryAlternateId;

/// <summary>
/// PFInventoryInventoryItemReference data model.
/// </summary>
typedef struct PFInventoryInventoryItemReference
{
    /// <summary>
    /// (Optional) The inventory item alternate id the request applies to.
    /// </summary>
    _Maybenull_ PFInventoryAlternateId const* alternateId;

    /// <summary>
    /// (Optional) The inventory item id the request applies to.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

    /// <summary>
    /// (Optional) The inventory stack id the request should redeem to. (Default="default").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* stackId;

} PFInventoryInventoryItemReference;

/// <summary>
/// PFInventoryAddInventoryItemsRequest data model. Given an entity type, entity identifier and container
/// details, will add the specified inventory items.
/// </summary>
typedef struct PFInventoryAddInventoryItemsRequest
{
    /// <summary>
    /// The amount to add for the current item.
    /// </summary>
    int32_t amount;

    /// <summary>
    /// (Optional) The id of the entity's collection to perform this action on. (Default="default").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* collectionId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The Idempotency ID for this request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* idempotencyId;

    /// <summary>
    /// (Optional) The inventory item the request applies to.
    /// </summary>
    _Maybenull_ PFInventoryInventoryItemReference const* item;

} PFInventoryAddInventoryItemsRequest;

/// <summary>
/// PFInventoryAddInventoryItemsResponse data model.
/// </summary>
typedef struct PFInventoryAddInventoryItemsResponse
{
    /// <summary>
    /// (Optional) The idempotency id used in the request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* idempotencyId;

    /// <summary>
    /// (Optional) The ids of transactions that occurred as a result of the request.
    /// </summary>
    _Maybenull_ _Field_size_(transactionIdsCount) const char* const* transactionIds;

    /// <summary>
    /// Count of transactionIds
    /// </summary>
    uint32_t transactionIdsCount;

} PFInventoryAddInventoryItemsResponse;

/// <summary>
/// PFInventoryDeleteInventoryCollectionRequest data model. Delete an Inventory Collection by the specified
/// Id for an Entity.
/// </summary>
typedef struct PFInventoryDeleteInventoryCollectionRequest
{
    /// <summary>
    /// (Optional) The inventory collection id the request applies to.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* collectionId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity the request is about. Set to the caller by default.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

} PFInventoryDeleteInventoryCollectionRequest;

/// <summary>
/// PFInventoryDeleteInventoryItemsRequest data model. Given an entity type, entity identifier and container
/// details, will delete the entity's inventory items.
/// </summary>
typedef struct PFInventoryDeleteInventoryItemsRequest
{
    /// <summary>
    /// (Optional) The id of the entity's collection to perform this action on. (Default="default").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* collectionId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The Idempotency ID for this request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* idempotencyId;

    /// <summary>
    /// (Optional) The inventory item the request applies to.
    /// </summary>
    _Maybenull_ PFInventoryInventoryItemReference const* item;

} PFInventoryDeleteInventoryItemsRequest;

/// <summary>
/// PFInventoryDeleteInventoryItemsResponse data model.
/// </summary>
typedef struct PFInventoryDeleteInventoryItemsResponse
{
    /// <summary>
    /// (Optional) The idempotency id used in the request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* idempotencyId;

    /// <summary>
    /// (Optional) The ids of transactions that occurred as a result of the request.
    /// </summary>
    _Maybenull_ _Field_size_(transactionIdsCount) const char* const* transactionIds;

    /// <summary>
    /// Count of transactionIds
    /// </summary>
    uint32_t transactionIdsCount;

} PFInventoryDeleteInventoryItemsResponse;

/// <summary>
/// PFInventoryAddInventoryItemsOperation data model.
/// </summary>
typedef struct PFInventoryAddInventoryItemsOperation
{
    /// <summary>
    /// The amount to add to the current item amount.
    /// </summary>
    int32_t amount;

    /// <summary>
    /// (Optional) The inventory item the operation applies to.
    /// </summary>
    _Maybenull_ PFInventoryInventoryItemReference const* item;

} PFInventoryAddInventoryItemsOperation;

/// <summary>
/// PFInventoryDeleteInventoryItemsOperation data model.
/// </summary>
typedef struct PFInventoryDeleteInventoryItemsOperation
{
    /// <summary>
    /// (Optional) The inventory item the operation applies to.
    /// </summary>
    _Maybenull_ PFInventoryInventoryItemReference const* item;

} PFInventoryDeleteInventoryItemsOperation;

/// <summary>
/// PFInventoryPurchasePriceAmount data model.
/// </summary>
typedef struct PFInventoryPurchasePriceAmount
{
    /// <summary>
    /// The amount of the inventory item to use in the purchase .
    /// </summary>
    int32_t amount;

    /// <summary>
    /// (Optional) The inventory item id to use in the purchase .
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* itemId;

    /// <summary>
    /// (Optional) The inventory stack id the to use in the purchase. Set to "default" by default.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* stackId;

} PFInventoryPurchasePriceAmount;

/// <summary>
/// PFInventoryPurchaseInventoryItemsOperation data model.
/// </summary>
typedef struct PFInventoryPurchaseInventoryItemsOperation
{
    /// <summary>
    /// The amount to purchase.
    /// </summary>
    int32_t amount;

    /// <summary>
    /// Indicates whether stacks reduced to an amount of 0 during the operation should be deleted from
    /// the inventory. (Default = false).
    /// </summary>
    bool deleteEmptyStacks;

    /// <summary>
    /// (Optional) The inventory item the operation applies to.
    /// </summary>
    _Maybenull_ PFInventoryInventoryItemReference const* item;

    /// <summary>
    /// (Optional) The per-item price the item is expected to be purchased at. This must match a value
    /// configured in the Catalog or specified Store.
    /// </summary>
    _Maybenull_ _Field_size_(priceAmountsCount) PFInventoryPurchasePriceAmount const* const* priceAmounts;

    /// <summary>
    /// Count of priceAmounts
    /// </summary>
    uint32_t priceAmountsCount;

    /// <summary>
    /// (Optional) The id of the Store to purchase the item from.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* storeId;

} PFInventoryPurchaseInventoryItemsOperation;

/// <summary>
/// PFInventorySubtractInventoryItemsOperation data model.
/// </summary>
typedef struct PFInventorySubtractInventoryItemsOperation
{
    /// <summary>
    /// The amount to subtract from the current item amount.
    /// </summary>
    int32_t amount;

    /// <summary>
    /// Indicates whether stacks reduced to an amount of 0 during the request should be deleted from
    /// the inventory. (Default = false).
    /// </summary>
    bool deleteEmptyStacks;

    /// <summary>
    /// (Optional) The inventory item the operation applies to.
    /// </summary>
    _Maybenull_ PFInventoryInventoryItemReference const* item;

} PFInventorySubtractInventoryItemsOperation;

/// <summary>
/// PFInventoryTransferInventoryItemsOperation data model.
/// </summary>
typedef struct PFInventoryTransferInventoryItemsOperation
{
    /// <summary>
    /// The amount to transfer.
    /// </summary>
    int32_t amount;

    /// <summary>
    /// Indicates whether stacks reduced to an amount of 0 during the operation should be deleted from
    /// the inventory. (Default = false).
    /// </summary>
    bool deleteEmptyStacks;

    /// <summary>
    /// (Optional) The inventory item the operation is transferring from.
    /// </summary>
    _Maybenull_ PFInventoryInventoryItemReference const* givingItem;

    /// <summary>
    /// (Optional) The inventory item the operation is transferring to.
    /// </summary>
    _Maybenull_ PFInventoryInventoryItemReference const* receivingItem;

} PFInventoryTransferInventoryItemsOperation;

/// <summary>
/// PFInventoryInventoryItem data model.
/// </summary>
typedef struct PFInventoryInventoryItem
{
    /// <summary>
    /// The amount of the item.
    /// </summary>
    int32_t amount;

    /// <summary>
    /// (Optional) The id of the item. This should correspond to the item id in the catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* id;

    /// <summary>
    /// (Optional) The stack id of the item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* stackId;

    /// <summary>
    /// (Optional) The type of the item. This should correspond to the item type in the catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* type;

} PFInventoryInventoryItem;

/// <summary>
/// PFInventoryUpdateInventoryItemsOperation data model.
/// </summary>
typedef struct PFInventoryUpdateInventoryItemsOperation
{
    /// <summary>
    /// (Optional) The inventory item to update with the specified values.
    /// </summary>
    _Maybenull_ PFInventoryInventoryItem const* item;

} PFInventoryUpdateInventoryItemsOperation;

/// <summary>
/// PFInventoryInventoryOperation data model.
/// </summary>
typedef struct PFInventoryInventoryOperation
{
    /// <summary>
    /// (Optional) The add operation.
    /// </summary>
    _Maybenull_ PFInventoryAddInventoryItemsOperation const* add;

    /// <summary>
    /// (Optional) The delete operation.
    /// </summary>
    _Maybenull_ PFInventoryDeleteInventoryItemsOperation const* delete2;

    /// <summary>
    /// (Optional) The purchase operation.
    /// </summary>
    _Maybenull_ PFInventoryPurchaseInventoryItemsOperation const* purchase;

    /// <summary>
    /// (Optional) The subtract operation.
    /// </summary>
    _Maybenull_ PFInventorySubtractInventoryItemsOperation const* subtract;

    /// <summary>
    /// (Optional) The transfer operation.
    /// </summary>
    _Maybenull_ PFInventoryTransferInventoryItemsOperation const* transfer;

    /// <summary>
    /// (Optional) The update operation.
    /// </summary>
    _Maybenull_ PFInventoryUpdateInventoryItemsOperation const* update;

} PFInventoryInventoryOperation;

/// <summary>
/// PFInventoryExecuteInventoryOperationsRequest data model. Execute a list of Inventory Operations for
/// an Entity.
/// </summary>
typedef struct PFInventoryExecuteInventoryOperationsRequest
{
    /// <summary>
    /// (Optional) The id of the entity's collection to perform this action on. (Default="default").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* collectionId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The Idempotency ID for this request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* idempotencyId;

    /// <summary>
    /// (Optional) The operations to run transactionally. The operations will be executed in-order sequentially
    /// and will succeed or fail as a batch.
    /// </summary>
    _Maybenull_ _Field_size_(operationsCount) PFInventoryInventoryOperation const* const* operations;

    /// <summary>
    /// Count of operations
    /// </summary>
    uint32_t operationsCount;

} PFInventoryExecuteInventoryOperationsRequest;

/// <summary>
/// PFInventoryExecuteInventoryOperationsResponse data model.
/// </summary>
typedef struct PFInventoryExecuteInventoryOperationsResponse
{
    /// <summary>
    /// (Optional) The idempotency id used in the request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* idempotencyId;

    /// <summary>
    /// (Optional) The ids of the transactions that occurred as a result of the request.
    /// </summary>
    _Maybenull_ _Field_size_(transactionIdsCount) const char* const* transactionIds;

    /// <summary>
    /// Count of transactionIds
    /// </summary>
    uint32_t transactionIdsCount;

} PFInventoryExecuteInventoryOperationsResponse;

/// <summary>
/// PFInventoryGetInventoryCollectionIdsRequest data model. Get a list of Inventory Collection Ids for
/// the specified Entity.
/// </summary>
typedef struct PFInventoryGetInventoryCollectionIdsRequest
{
    /// <summary>
    /// (Optional) An opaque token used to retrieve the next page of collection ids, if any are available.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* continuationToken;

    /// <summary>
    /// Number of items to retrieve. (Default = 10).
    /// </summary>
    int32_t count;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity the request is about. Set to the caller by default.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

} PFInventoryGetInventoryCollectionIdsRequest;

/// <summary>
/// PFInventoryGetInventoryCollectionIdsResponse data model.
/// </summary>
typedef struct PFInventoryGetInventoryCollectionIdsResponse
{
    /// <summary>
    /// (Optional) The requested inventory collection ids.
    /// </summary>
    _Maybenull_ _Field_size_(collectionIdsCount) const char* const* collectionIds;

    /// <summary>
    /// Count of collectionIds
    /// </summary>
    uint32_t collectionIdsCount;

    /// <summary>
    /// (Optional) An opaque token used to retrieve the next page of collection ids, if any are available.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* continuationToken;

} PFInventoryGetInventoryCollectionIdsResponse;

/// <summary>
/// PFInventoryGetInventoryItemsRequest data model. Given an entity type, entity identifier and container
/// details, will get the entity's inventory items. .
/// </summary>
typedef struct PFInventoryGetInventoryItemsRequest
{
    /// <summary>
    /// (Optional) The id of the entity's collection to perform this action on. (Default="default").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* collectionId;

    /// <summary>
    /// (Optional) An opaque token used to retrieve the next page of items in the inventory, if any are
    /// available. Should be null on initial request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* continuationToken;

    /// <summary>
    /// Number of items to retrieve. Maximum page size is 50. (Default=10).
    /// </summary>
    int32_t count;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The filters to limit what is returned to the client.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* filter;

} PFInventoryGetInventoryItemsRequest;

/// <summary>
/// PFInventoryGetInventoryItemsResponse data model.
/// </summary>
typedef struct PFInventoryGetInventoryItemsResponse
{
    /// <summary>
    /// (Optional) An opaque token used to retrieve the next page of items, if any are available.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* continuationToken;

    /// <summary>
    /// (Optional) The requested inventory items.
    /// </summary>
    _Maybenull_ _Field_size_(itemsCount) PFInventoryInventoryItem const* const* items;

    /// <summary>
    /// Count of items
    /// </summary>
    uint32_t itemsCount;

} PFInventoryGetInventoryItemsResponse;

/// <summary>
/// PFInventoryGetMicrosoftStoreAccessTokensRequest data model. Gets the access tokens for Microsoft
/// Store authentication.
/// </summary>
typedef struct PFInventoryGetMicrosoftStoreAccessTokensRequest
{
    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

} PFInventoryGetMicrosoftStoreAccessTokensRequest;

/// <summary>
/// PFInventoryGetMicrosoftStoreAccessTokensResponse data model.
/// </summary>
typedef struct PFInventoryGetMicrosoftStoreAccessTokensResponse
{
    /// <summary>
    /// (Optional) The collections access token for calling https://onestore.microsoft.com/b2b/keys/create/collections
    /// to obtain a CollectionsIdKey for the user.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* collectionsAccessToken;

    /// <summary>
    /// The date the collections access token expires.
    /// </summary>
    time_t collectionsAccessTokenExpirationDate;

} PFInventoryGetMicrosoftStoreAccessTokensResponse;

/// <summary>
/// PFInventoryPurchaseInventoryItemsRequest data model. Purchase a single item or bundle, paying the
/// associated price.
/// </summary>
typedef struct PFInventoryPurchaseInventoryItemsRequest
{
    /// <summary>
    /// The amount to purchase.
    /// </summary>
    int32_t amount;

    /// <summary>
    /// (Optional) The id of the entity's collection to perform this action on. (Default="default").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* collectionId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// Indicates whether stacks reduced to an amount of 0 during the request should be deleted from
    /// the inventory. (Default=false).
    /// </summary>
    bool deleteEmptyStacks;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The Idempotency ID for this request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* idempotencyId;

    /// <summary>
    /// (Optional) The inventory item the request applies to.
    /// </summary>
    _Maybenull_ PFInventoryInventoryItemReference const* item;

    /// <summary>
    /// (Optional) The per-item price the item is expected to be purchased at. This must match a value
    /// configured in the Catalog or specified Store. .
    /// </summary>
    _Maybenull_ _Field_size_(priceAmountsCount) PFInventoryPurchasePriceAmount const* const* priceAmounts;

    /// <summary>
    /// Count of priceAmounts
    /// </summary>
    uint32_t priceAmountsCount;

    /// <summary>
    /// (Optional) The id of the Store to purchase the item from.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* storeId;

} PFInventoryPurchaseInventoryItemsRequest;

/// <summary>
/// PFInventoryPurchaseInventoryItemsResponse data model.
/// </summary>
typedef struct PFInventoryPurchaseInventoryItemsResponse
{
    /// <summary>
    /// (Optional) The idempotency id used in the request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* idempotencyId;

    /// <summary>
    /// (Optional) The ids of transactions that occurred as a result of the request.
    /// </summary>
    _Maybenull_ _Field_size_(transactionIdsCount) const char* const* transactionIds;

    /// <summary>
    /// Count of transactionIds
    /// </summary>
    uint32_t transactionIdsCount;

} PFInventoryPurchaseInventoryItemsResponse;

/// <summary>
/// PFInventoryRedeemAppleAppStoreInventoryItemsRequest data model. Redeem items from the Apple App Store.
/// </summary>
typedef struct PFInventoryRedeemAppleAppStoreInventoryItemsRequest
{
    /// <summary>
    /// (Optional) The id of the entity's collection to perform this action on. (Default="default").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* collectionId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The receipt provided by the Apple marketplace upon successful purchase.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* receipt;

} PFInventoryRedeemAppleAppStoreInventoryItemsRequest;

/// <summary>
/// PFInventoryRedemptionFailure data model.
/// </summary>
typedef struct PFInventoryRedemptionFailure
{
    /// <summary>
    /// (Optional) The marketplace failure code.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* failureCode;

    /// <summary>
    /// (Optional) The marketplace error details explaining why the offer failed to redeem.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* failureDetails;

    /// <summary>
    /// (Optional) The transaction id in the external marketplace.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* marketplaceTransactionId;

    /// <summary>
    /// (Optional) The ID of the offer being redeemed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* offerId;

} PFInventoryRedemptionFailure;

/// <summary>
/// PFInventoryRedemptionSuccess data model.
/// </summary>
typedef struct PFInventoryRedemptionSuccess
{
    /// <summary>
    /// (Optional) The transaction id in the external marketplace.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* marketplaceTransactionId;

    /// <summary>
    /// (Optional) The ID of the offer being redeemed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* offerId;

    /// <summary>
    /// The timestamp for when the redeem was completed.
    /// </summary>
    time_t successTimestamp;

} PFInventoryRedemptionSuccess;

/// <summary>
/// PFInventoryRedeemAppleAppStoreInventoryItemsResponse data model.
/// </summary>
typedef struct PFInventoryRedeemAppleAppStoreInventoryItemsResponse
{
    /// <summary>
    /// (Optional) The list of failed redemptions from the external marketplace.
    /// </summary>
    _Maybenull_ _Field_size_(failedCount) PFInventoryRedemptionFailure const* const* failed;

    /// <summary>
    /// Count of failed
    /// </summary>
    uint32_t failedCount;

    /// <summary>
    /// (Optional) The list of successful redemptions from the external marketplace.
    /// </summary>
    _Maybenull_ _Field_size_(succeededCount) PFInventoryRedemptionSuccess const* const* succeeded;

    /// <summary>
    /// Count of succeeded
    /// </summary>
    uint32_t succeededCount;

    /// <summary>
    /// (Optional) The Transaction IDs associated with the inventory modifications.
    /// </summary>
    _Maybenull_ _Field_size_(transactionIdsCount) const char* const* transactionIds;

    /// <summary>
    /// Count of transactionIds
    /// </summary>
    uint32_t transactionIdsCount;

} PFInventoryRedeemAppleAppStoreInventoryItemsResponse;

/// <summary>
/// PFInventoryGooglePlayProductPurchase data model.
/// </summary>
typedef struct PFInventoryGooglePlayProductPurchase
{
    /// <summary>
    /// (Optional) The Product ID (SKU) of the InApp product purchased from the Google Play store.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* productId;

    /// <summary>
    /// (Optional) The token provided to the player's device when the product was purchased.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* token;

} PFInventoryGooglePlayProductPurchase;

/// <summary>
/// PFInventoryRedeemGooglePlayInventoryItemsRequest data model. Redeem items from the Google Play Store.
/// </summary>
typedef struct PFInventoryRedeemGooglePlayInventoryItemsRequest
{
    /// <summary>
    /// (Optional) The id of the entity's collection to perform this action on. (Default="default").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* collectionId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The list of purchases to redeem.
    /// </summary>
    _Maybenull_ _Field_size_(purchasesCount) PFInventoryGooglePlayProductPurchase const* const* purchases;

    /// <summary>
    /// Count of purchases
    /// </summary>
    uint32_t purchasesCount;

} PFInventoryRedeemGooglePlayInventoryItemsRequest;

/// <summary>
/// PFInventoryRedeemGooglePlayInventoryItemsResponse data model.
/// </summary>
typedef struct PFInventoryRedeemGooglePlayInventoryItemsResponse
{
    /// <summary>
    /// (Optional) The list of failed redemptions from the external marketplace.
    /// </summary>
    _Maybenull_ _Field_size_(failedCount) PFInventoryRedemptionFailure const* const* failed;

    /// <summary>
    /// Count of failed
    /// </summary>
    uint32_t failedCount;

    /// <summary>
    /// (Optional) The list of successful redemptions from the external marketplace.
    /// </summary>
    _Maybenull_ _Field_size_(succeededCount) PFInventoryRedemptionSuccess const* const* succeeded;

    /// <summary>
    /// Count of succeeded
    /// </summary>
    uint32_t succeededCount;

    /// <summary>
    /// (Optional) The Transaction IDs associated with the inventory modifications.
    /// </summary>
    _Maybenull_ _Field_size_(transactionIdsCount) const char* const* transactionIds;

    /// <summary>
    /// Count of transactionIds
    /// </summary>
    uint32_t transactionIdsCount;

} PFInventoryRedeemGooglePlayInventoryItemsResponse;

/// <summary>
/// PFInventoryRedeemMicrosoftStoreInventoryItemsRequest data model. Redeem items from the Microsoft
/// Store.
/// </summary>
typedef struct PFInventoryRedeemMicrosoftStoreInventoryItemsRequest
{
    /// <summary>
    /// (Optional) The id of the entity's collection to perform this action on. (Default="default").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* collectionId;

    /// <summary>
    /// (Optional) The OneStore Collections Id Key used for AAD authentication.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* collectionsIdKey;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) Xbox Token used for delegated business partner authentication.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* xboxToken;

} PFInventoryRedeemMicrosoftStoreInventoryItemsRequest;

/// <summary>
/// PFInventoryRedeemMicrosoftStoreInventoryItemsResponse data model.
/// </summary>
typedef struct PFInventoryRedeemMicrosoftStoreInventoryItemsResponse
{
    /// <summary>
    /// (Optional) The list of failed redemptions from the external marketplace.
    /// </summary>
    _Maybenull_ _Field_size_(failedCount) PFInventoryRedemptionFailure const* const* failed;

    /// <summary>
    /// Count of failed
    /// </summary>
    uint32_t failedCount;

    /// <summary>
    /// (Optional) The list of successful redemptions from the external marketplace.
    /// </summary>
    _Maybenull_ _Field_size_(succeededCount) PFInventoryRedemptionSuccess const* const* succeeded;

    /// <summary>
    /// Count of succeeded
    /// </summary>
    uint32_t succeededCount;

    /// <summary>
    /// (Optional) The Transaction IDs associated with the inventory modifications.
    /// </summary>
    _Maybenull_ _Field_size_(transactionIdsCount) const char* const* transactionIds;

    /// <summary>
    /// Count of transactionIds
    /// </summary>
    uint32_t transactionIdsCount;

} PFInventoryRedeemMicrosoftStoreInventoryItemsResponse;

/// <summary>
/// PFInventoryRedeemNintendoEShopInventoryItemsRequest data model. Redeem items from the Nintendo EShop.
/// </summary>
typedef struct PFInventoryRedeemNintendoEShopInventoryItemsRequest
{
    /// <summary>
    /// (Optional) The id of the entity's collection to perform this action on. (Default="default").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* collectionId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The Nintendo provided token authorizing redemption.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* nintendoServiceAccountIdToken;

} PFInventoryRedeemNintendoEShopInventoryItemsRequest;

/// <summary>
/// PFInventoryRedeemNintendoEShopInventoryItemsResponse data model.
/// </summary>
typedef struct PFInventoryRedeemNintendoEShopInventoryItemsResponse
{
    /// <summary>
    /// (Optional) The list of failed redemptions from the external marketplace.
    /// </summary>
    _Maybenull_ _Field_size_(failedCount) PFInventoryRedemptionFailure const* const* failed;

    /// <summary>
    /// Count of failed
    /// </summary>
    uint32_t failedCount;

    /// <summary>
    /// (Optional) The list of successful redemptions from the external marketplace.
    /// </summary>
    _Maybenull_ _Field_size_(succeededCount) PFInventoryRedemptionSuccess const* const* succeeded;

    /// <summary>
    /// Count of succeeded
    /// </summary>
    uint32_t succeededCount;

    /// <summary>
    /// (Optional) The Transaction IDs associated with the inventory modifications.
    /// </summary>
    _Maybenull_ _Field_size_(transactionIdsCount) const char* const* transactionIds;

    /// <summary>
    /// Count of transactionIds
    /// </summary>
    uint32_t transactionIdsCount;

} PFInventoryRedeemNintendoEShopInventoryItemsResponse;

/// <summary>
/// PFInventoryRedeemPlayStationStoreInventoryItemsRequest data model. Redeem items from the PlayStation
/// Store.
/// </summary>
typedef struct PFInventoryRedeemPlayStationStoreInventoryItemsRequest
{
    /// <summary>
    /// (Optional) Authorization code provided by the PlayStation OAuth provider.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* authorizationCode;

    /// <summary>
    /// (Optional) The id of the entity's collection to perform this action on. (Default="default").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* collectionId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) Optional Service Label to pass into the request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serviceLabel;

} PFInventoryRedeemPlayStationStoreInventoryItemsRequest;

/// <summary>
/// PFInventoryRedeemPlayStationStoreInventoryItemsResponse data model.
/// </summary>
typedef struct PFInventoryRedeemPlayStationStoreInventoryItemsResponse
{
    /// <summary>
    /// (Optional) The list of failed redemptions from the external marketplace.
    /// </summary>
    _Maybenull_ _Field_size_(failedCount) PFInventoryRedemptionFailure const* const* failed;

    /// <summary>
    /// Count of failed
    /// </summary>
    uint32_t failedCount;

    /// <summary>
    /// (Optional) The list of successful redemptions from the external marketplace.
    /// </summary>
    _Maybenull_ _Field_size_(succeededCount) PFInventoryRedemptionSuccess const* const* succeeded;

    /// <summary>
    /// Count of succeeded
    /// </summary>
    uint32_t succeededCount;

    /// <summary>
    /// (Optional) The Transaction IDs associated with the inventory modifications.
    /// </summary>
    _Maybenull_ _Field_size_(transactionIdsCount) const char* const* transactionIds;

    /// <summary>
    /// Count of transactionIds
    /// </summary>
    uint32_t transactionIdsCount;

} PFInventoryRedeemPlayStationStoreInventoryItemsResponse;

/// <summary>
/// PFInventoryRedeemSteamInventoryItemsRequest data model. Redeem inventory items from Steam.
/// </summary>
typedef struct PFInventoryRedeemSteamInventoryItemsRequest
{
    /// <summary>
    /// (Optional) The id of the entity's collection to perform this action on. (Default="default").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* collectionId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

} PFInventoryRedeemSteamInventoryItemsRequest;

/// <summary>
/// PFInventoryRedeemSteamInventoryItemsResponse data model.
/// </summary>
typedef struct PFInventoryRedeemSteamInventoryItemsResponse
{
    /// <summary>
    /// (Optional) The list of failed redemptions from the external marketplace.
    /// </summary>
    _Maybenull_ _Field_size_(failedCount) PFInventoryRedemptionFailure const* const* failed;

    /// <summary>
    /// Count of failed
    /// </summary>
    uint32_t failedCount;

    /// <summary>
    /// (Optional) The list of successful redemptions from the external marketplace.
    /// </summary>
    _Maybenull_ _Field_size_(succeededCount) PFInventoryRedemptionSuccess const* const* succeeded;

    /// <summary>
    /// Count of succeeded
    /// </summary>
    uint32_t succeededCount;

    /// <summary>
    /// (Optional) The Transaction IDs associated with the inventory modifications.
    /// </summary>
    _Maybenull_ _Field_size_(transactionIdsCount) const char* const* transactionIds;

    /// <summary>
    /// Count of transactionIds
    /// </summary>
    uint32_t transactionIdsCount;

} PFInventoryRedeemSteamInventoryItemsResponse;

/// <summary>
/// PFInventorySubtractInventoryItemsRequest data model. Given an entity type, entity identifier and
/// container details, will subtract the specified inventory items. .
/// </summary>
typedef struct PFInventorySubtractInventoryItemsRequest
{
    /// <summary>
    /// The amount to add for the current item.
    /// </summary>
    int32_t amount;

    /// <summary>
    /// (Optional) The id of the entity's collection to perform this action on. (Default="default").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* collectionId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// Indicates whether stacks reduced to an amount of 0 during the request should be deleted from
    /// the inventory. (Default=false).
    /// </summary>
    bool deleteEmptyStacks;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The Idempotency ID for this request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* idempotencyId;

    /// <summary>
    /// (Optional) The inventory item the request applies to.
    /// </summary>
    _Maybenull_ PFInventoryInventoryItemReference const* item;

} PFInventorySubtractInventoryItemsRequest;

/// <summary>
/// PFInventorySubtractInventoryItemsResponse data model.
/// </summary>
typedef struct PFInventorySubtractInventoryItemsResponse
{
    /// <summary>
    /// (Optional) The idempotency id used in the request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* idempotencyId;

    /// <summary>
    /// (Optional) The ids of transactions that occurred as a result of the request.
    /// </summary>
    _Maybenull_ _Field_size_(transactionIdsCount) const char* const* transactionIds;

    /// <summary>
    /// Count of transactionIds
    /// </summary>
    uint32_t transactionIdsCount;

} PFInventorySubtractInventoryItemsResponse;

/// <summary>
/// PFInventoryTransferInventoryItemsRequest data model. Transfer the specified inventory items of an
/// entity's container Id to another entity's container Id.
/// </summary>
typedef struct PFInventoryTransferInventoryItemsRequest
{
    /// <summary>
    /// The amount to transfer .
    /// </summary>
    int32_t amount;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// Indicates whether stacks reduced to an amount of 0 during the request should be deleted from
    /// the inventory. (Default = false).
    /// </summary>
    bool deleteEmptyStacks;

    /// <summary>
    /// (Optional) The inventory collection id the request is transferring from. (Default="default").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* givingCollectionId;

    /// <summary>
    /// (Optional) The entity the request is transferring from. Set to the caller by default.
    /// </summary>
    _Maybenull_ PFEntityKey const* givingEntity;

    /// <summary>
    /// (Optional) The inventory item the request is transferring from.
    /// </summary>
    _Maybenull_ PFInventoryInventoryItemReference const* givingItem;

    /// <summary>
    /// (Optional) The idempotency id for the request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* idempotencyId;

    /// <summary>
    /// (Optional) The inventory collection id the request is transferring to. (Default="default").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* receivingCollectionId;

    /// <summary>
    /// (Optional) The entity the request is transferring to. Set to the caller by default.
    /// </summary>
    _Maybenull_ PFEntityKey const* receivingEntity;

    /// <summary>
    /// (Optional) The inventory item the request is transferring to.
    /// </summary>
    _Maybenull_ PFInventoryInventoryItemReference const* receivingItem;

} PFInventoryTransferInventoryItemsRequest;

/// <summary>
/// PFInventoryTransferInventoryItemsResponse data model.
/// </summary>
typedef struct PFInventoryTransferInventoryItemsResponse
{
    /// <summary>
    /// (Optional) The ids of transactions that occurred as a result of the request's giving action.
    /// </summary>
    _Maybenull_ _Field_size_(givingTransactionIdsCount) const char* const* givingTransactionIds;

    /// <summary>
    /// Count of givingTransactionIds
    /// </summary>
    uint32_t givingTransactionIdsCount;

    /// <summary>
    /// (Optional) The idempotency id for the request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* idempotencyId;

    /// <summary>
    /// (Optional) The ids of transactions that occurred as a result of the request's receiving action.
    /// </summary>
    _Maybenull_ _Field_size_(receivingTransactionIdsCount) const char* const* receivingTransactionIds;

    /// <summary>
    /// Count of receivingTransactionIds
    /// </summary>
    uint32_t receivingTransactionIdsCount;

} PFInventoryTransferInventoryItemsResponse;

/// <summary>
/// PFInventoryUpdateInventoryItemsRequest data model. Given an entity type, entity identifier and container
/// details, will update the entity's inventory items.
/// </summary>
typedef struct PFInventoryUpdateInventoryItemsRequest
{
    /// <summary>
    /// (Optional) The id of the entity's collection to perform this action on. (Default="default").
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* collectionId;

    /// <summary>
    /// (Optional) The optional custom tags associated with the request (e.g. build number, external
    /// trace identifiers, etc.).
    /// </summary>
    _Maybenull_ _Field_size_(customTagsCount) struct PFStringDictionaryEntry const* customTags;

    /// <summary>
    /// Count of customTags
    /// </summary>
    uint32_t customTagsCount;

    /// <summary>
    /// (Optional) The entity to perform this action on.
    /// </summary>
    _Maybenull_ PFEntityKey const* entity;

    /// <summary>
    /// (Optional) The Idempotency ID for this request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* idempotencyId;

    /// <summary>
    /// (Optional) The inventory item to update with the specified values.
    /// </summary>
    _Maybenull_ PFInventoryInventoryItem const* item;

} PFInventoryUpdateInventoryItemsRequest;

/// <summary>
/// PFInventoryUpdateInventoryItemsResponse data model.
/// </summary>
typedef struct PFInventoryUpdateInventoryItemsResponse
{
    /// <summary>
    /// (Optional) The idempotency id used in the request.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* idempotencyId;

    /// <summary>
    /// (Optional) The ids of transactions that occurred as a result of the request.
    /// </summary>
    _Maybenull_ _Field_size_(transactionIdsCount) const char* const* transactionIds;

    /// <summary>
    /// Count of transactionIds
    /// </summary>
    uint32_t transactionIdsCount;

} PFInventoryUpdateInventoryItemsResponse;

#pragma pop_macro("IN")

}
