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
/// SourceType enum.
/// </summary>
enum class PFTitleDataManagementSourceType : uint32_t
{
    Admin,
    BackEnd,
    GameClient,
    GameServer,
    Partner,
    Custom,
    API
};

/// <summary>
/// PushSetupPlatform enum.
/// </summary>
enum class PFTitleDataManagementPushSetupPlatform : uint32_t
{
    GCM,
    APNS,
    APNS_SANDBOX
};

/// <summary>
/// PFTitleDataManagementAddLocalizedNewsRequest data model.
/// </summary>
typedef struct PFTitleDataManagementAddLocalizedNewsRequest
{
    /// <summary>
    /// Localized body text of the news.
    /// </summary>
    _Null_terminated_ const char* body;

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
    /// Language of the news item.
    /// </summary>
    _Null_terminated_ const char* language;

    /// <summary>
    /// Unique id of the updated news item.
    /// </summary>
    _Null_terminated_ const char* newsId;

    /// <summary>
    /// Localized title (headline) of the news item.
    /// </summary>
    _Null_terminated_ const char* title;

} PFTitleDataManagementAddLocalizedNewsRequest;

/// <summary>
/// PFTitleDataManagementAddNewsRequest data model.
/// </summary>
typedef struct PFTitleDataManagementAddNewsRequest
{
    /// <summary>
    /// Default body text of the news.
    /// </summary>
    _Null_terminated_ const char* body;

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
    /// (Optional) Time this news was published. If not set, defaults to now.
    /// </summary>
    _Maybenull_ time_t const* timestamp;

    /// <summary>
    /// Default title (headline) of the news item.
    /// </summary>
    _Null_terminated_ const char* title;

} PFTitleDataManagementAddNewsRequest;

/// <summary>
/// PFTitleDataManagementAddNewsResult data model.
/// </summary>
typedef struct PFTitleDataManagementAddNewsResult
{
    /// <summary>
    /// (Optional) Unique id of the new news item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* newsId;

} PFTitleDataManagementAddNewsResult;

/// <summary>
/// PFTitleDataManagementVirtualCurrencyData data model.
/// </summary>
typedef struct PFTitleDataManagementVirtualCurrencyData
{
    /// <summary>
    /// Unique two-character identifier for this currency type (e.g.: "CC").
    /// </summary>
    _Null_terminated_ const char* currencyCode;

    /// <summary>
    /// (Optional) Friendly name to show in the developer portal, reports, etc.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* displayName;

    /// <summary>
    /// (Optional) Amount to automatically grant users upon first login to the title.
    /// </summary>
    _Maybenull_ int32_t const* initialDeposit;

    /// <summary>
    /// (Optional) Maximum amount to which the currency will recharge (cannot exceed MaxAmount, but can
    /// be less).
    /// </summary>
    _Maybenull_ int32_t const* rechargeMax;

    /// <summary>
    /// (Optional) Rate at which the currency automatically be added to over time, in units per day (24
    /// hours).
    /// </summary>
    _Maybenull_ int32_t const* rechargeRate;

} PFTitleDataManagementVirtualCurrencyData;

/// <summary>
/// PFTitleDataManagementAddVirtualCurrencyTypesRequest data model. This operation is additive. Any new
/// currencies defined in the array will be added to the set of those available for the title, while any
/// CurrencyCode identifiers matching existing ones in the game will be overwritten with the new values.
/// </summary>
typedef struct PFTitleDataManagementAddVirtualCurrencyTypesRequest
{
    /// <summary>
    /// List of virtual currencies and their initial deposits (the amount a user is granted when signing
    /// in for the first time) to the title.
    /// </summary>
    _Field_size_(virtualCurrenciesCount) PFTitleDataManagementVirtualCurrencyData const* const* virtualCurrencies;

    /// <summary>
    /// Count of virtualCurrencies
    /// </summary>
    uint32_t virtualCurrenciesCount;

} PFTitleDataManagementAddVirtualCurrencyTypesRequest;

/// <summary>
/// PFTitleDataManagementDeleteStoreRequest data model. This non-reversible operation will permanently
/// delete the requested store.
/// </summary>
typedef struct PFTitleDataManagementDeleteStoreRequest
{
    /// <summary>
    /// (Optional) Catalog version of the store to delete. If null, uses the default catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

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
    /// Unqiue identifier for the store which is to be deleted.
    /// </summary>
    _Null_terminated_ const char* storeId;

} PFTitleDataManagementDeleteStoreRequest;

/// <summary>
/// PFTitleDataManagementDeleteTitleDataOverrideRequest data model. Will delete all the title data associated
/// with the given override label.
/// </summary>
typedef struct PFTitleDataManagementDeleteTitleDataOverrideRequest
{
    /// <summary>
    /// Name of the override.
    /// </summary>
    _Null_terminated_ const char* overrideLabel;

} PFTitleDataManagementDeleteTitleDataOverrideRequest;

/// <summary>
/// PFTitleDataManagementGetCatalogItemsRequest data model.
/// </summary>
typedef struct PFTitleDataManagementGetCatalogItemsRequest
{
    /// <summary>
    /// (Optional) Which catalog is being requested. If null, uses the default catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

} PFTitleDataManagementGetCatalogItemsRequest;

/// <summary>
/// PFTitleDataManagementCatalogItemBundleInfo data model.
/// </summary>
typedef struct PFTitleDataManagementCatalogItemBundleInfo
{
    /// <summary>
    /// (Optional) Unique ItemId values for all items which will be added to the player inventory when
    /// the bundle is added.
    /// </summary>
    _Maybenull_ _Field_size_(bundledItemsCount) const char* const* bundledItems;

    /// <summary>
    /// Count of bundledItems
    /// </summary>
    uint32_t bundledItemsCount;

    /// <summary>
    /// (Optional) Unique TableId values for all RandomResultTable objects which are part of the bundle
    /// (random tables will be resolved and add the relevant items to the player inventory when the bundle
    /// is added).
    /// </summary>
    _Maybenull_ _Field_size_(bundledResultTablesCount) const char* const* bundledResultTables;

    /// <summary>
    /// Count of bundledResultTables
    /// </summary>
    uint32_t bundledResultTablesCount;

    /// <summary>
    /// (Optional) Virtual currency types and balances which will be added to the player inventory when
    /// the bundle is added.
    /// </summary>
    _Maybenull_ _Field_size_(bundledVirtualCurrenciesCount) struct PFUint32DictionaryEntry const* bundledVirtualCurrencies;

    /// <summary>
    /// Count of bundledVirtualCurrencies
    /// </summary>
    uint32_t bundledVirtualCurrenciesCount;

} PFTitleDataManagementCatalogItemBundleInfo;

/// <summary>
/// PFTitleDataManagementCatalogItemConsumableInfo data model.
/// </summary>
typedef struct PFTitleDataManagementCatalogItemConsumableInfo
{
    /// <summary>
    /// (Optional) Number of times this object can be used, after which it will be removed from the player
    /// inventory.
    /// </summary>
    _Maybenull_ uint32_t const* usageCount;

    /// <summary>
    /// (Optional) Duration in seconds for how long the item will remain in the player inventory - once
    /// elapsed, the item will be removed (recommended minimum value is 5 seconds, as lower values can
    /// cause the item to expire before operations depending on this item's details have completed).
    /// </summary>
    _Maybenull_ uint32_t const* usagePeriod;

    /// <summary>
    /// (Optional) All inventory item instances in the player inventory sharing a non-null UsagePeriodGroup
    /// have their UsagePeriod values added together, and share the result - when that period has elapsed,
    /// all the items in the group will be removed.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* usagePeriodGroup;

} PFTitleDataManagementCatalogItemConsumableInfo;

/// <summary>
/// PFTitleDataManagementCatalogItemContainerInfo data model. Containers are inventory items that can
/// hold other items defined in the catalog, as well as virtual currency, which is added to the player
/// inventory when the container is unlocked, using the UnlockContainerItem API. The items can be anything
/// defined in the catalog, as well as RandomResultTable objects which will be resolved when the container
/// is unlocked. Containers and their keys should be defined as Consumable (having a limited number of
/// uses) in their catalog defintiions, unless the intent is for the player to be able to re-use them
/// infinitely.
/// </summary>
typedef struct PFTitleDataManagementCatalogItemContainerInfo
{
    /// <summary>
    /// (Optional) Unique ItemId values for all items which will be added to the player inventory, once
    /// the container has been unlocked.
    /// </summary>
    _Maybenull_ _Field_size_(itemContentsCount) const char* const* itemContents;

    /// <summary>
    /// Count of itemContents
    /// </summary>
    uint32_t itemContentsCount;

    /// <summary>
    /// (Optional) ItemId for the catalog item used to unlock the container, if any (if not specified,
    /// a call to UnlockContainerItem will open the container, adding the contents to the player inventory
    /// and currency balances).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* keyItemId;

    /// <summary>
    /// (Optional) Unique TableId values for all RandomResultTable objects which are part of the container
    /// (once unlocked, random tables will be resolved and add the relevant items to the player inventory).
    /// </summary>
    _Maybenull_ _Field_size_(resultTableContentsCount) const char* const* resultTableContents;

    /// <summary>
    /// Count of resultTableContents
    /// </summary>
    uint32_t resultTableContentsCount;

    /// <summary>
    /// (Optional) Virtual currency types and balances which will be added to the player inventory when
    /// the container is unlocked.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyContentsCount) struct PFUint32DictionaryEntry const* virtualCurrencyContents;

    /// <summary>
    /// Count of virtualCurrencyContents
    /// </summary>
    uint32_t virtualCurrencyContentsCount;

} PFTitleDataManagementCatalogItemContainerInfo;

/// <summary>
/// PFTitleDataManagementCatalogItem data model. A purchasable item from the item catalog.
/// </summary>
typedef struct PFTitleDataManagementCatalogItem
{
    /// <summary>
    /// (Optional) Defines the bundle properties for the item - bundles are items which contain other
    /// items, including random drop tables and virtual currencies.
    /// </summary>
    _Maybenull_ PFTitleDataManagementCatalogItemBundleInfo const* bundle;

    /// <summary>
    /// If true, then an item instance of this type can be used to grant a character to a user.
    /// </summary>
    bool canBecomeCharacter;

    /// <summary>
    /// (Optional) Catalog version for this item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// (Optional) Defines the consumable properties (number of uses, timeout) for the item.
    /// </summary>
    _Maybenull_ PFTitleDataManagementCatalogItemConsumableInfo const* consumable;

    /// <summary>
    /// (Optional) Defines the container properties for the item - what items it contains, including
    /// random drop tables and virtual currencies, and what item (if any) is required to open it via the
    /// UnlockContainerItem API.
    /// </summary>
    _Maybenull_ PFTitleDataManagementCatalogItemContainerInfo const* container;

    /// <summary>
    /// (Optional) Game specific custom data.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* customData;

    /// <summary>
    /// (Optional) Text description of item, to show in-game.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* description;

    /// <summary>
    /// (Optional) Text name for the item, to show in-game.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* displayName;

    /// <summary>
    /// If the item has IsLImitedEdition set to true, and this is the first time this ItemId has been
    /// defined as a limited edition item, this value determines the total number of instances to allocate
    /// for the title. Once this limit has been reached, no more instances of this ItemId can be created,
    /// and attempts to purchase or grant it will return a Result of false for that ItemId. If the item
    /// has already been defined to have a limited edition count, or if this value is less than zero,
    /// it will be ignored.
    /// </summary>
    int32_t initialLimitedEditionCount;

    /// <summary>
    /// BETA: If true, then only a fixed number can ever be granted.
    /// </summary>
    bool isLimitedEdition;

    /// <summary>
    /// If true, then only one item instance of this type will exist and its remaininguses will be incremented
    /// instead. RemainingUses will cap out at Int32.Max (2,147,483,647). All subsequent increases will
    /// be discarded.
    /// </summary>
    bool isStackable;

    /// <summary>
    /// If true, then an item instance of this type can be traded between players using the trading APIs.
    /// </summary>
    bool isTradable;

    /// <summary>
    /// (Optional) Class to which the item belongs.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* itemClass;

    /// <summary>
    /// Unique identifier for this item.
    /// </summary>
    _Null_terminated_ const char* itemId;

    /// <summary>
    /// (Optional) URL to the item image. For Facebook purchase to display the image on the item purchase
    /// page, this must be set to an HTTP URL.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* itemImageUrl;

    /// <summary>
    /// (Optional) Override prices for this item for specific currencies.
    /// </summary>
    _Maybenull_ _Field_size_(realCurrencyPricesCount) struct PFUint32DictionaryEntry const* realCurrencyPrices;

    /// <summary>
    /// Count of realCurrencyPrices
    /// </summary>
    uint32_t realCurrencyPricesCount;

    /// <summary>
    /// (Optional) List of item tags.
    /// </summary>
    _Maybenull_ _Field_size_(tagsCount) const char* const* tags;

    /// <summary>
    /// Count of tags
    /// </summary>
    uint32_t tagsCount;

    /// <summary>
    /// (Optional) Price of this item in virtual currencies and "RM" (the base Real Money purchase price,
    /// in USD pennies).
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyPricesCount) struct PFUint32DictionaryEntry const* virtualCurrencyPrices;

    /// <summary>
    /// Count of virtualCurrencyPrices
    /// </summary>
    uint32_t virtualCurrencyPricesCount;

} PFTitleDataManagementCatalogItem;

/// <summary>
/// PFTitleDataManagementGetCatalogItemsResult data model.
/// </summary>
typedef struct PFTitleDataManagementGetCatalogItemsResult
{
    /// <summary>
    /// (Optional) Array of items which can be purchased.
    /// </summary>
    _Maybenull_ _Field_size_(catalogCount) PFTitleDataManagementCatalogItem const* const* catalog;

    /// <summary>
    /// Count of catalog
    /// </summary>
    uint32_t catalogCount;

} PFTitleDataManagementGetCatalogItemsResult;

/// <summary>
/// PFTitleDataManagementGetPublisherDataRequest data model. This API is designed to return publisher-specific
/// values which can be read, but not written to, by the client. This data is shared across all titles
/// assigned to a particular publisher, and can be used for cross-game coordination. Only titles assigned
/// to a publisher can use this API. For more information email helloplayfab@microsoft.com. This AdminAPI
/// call for getting title data guarantees no delay in between update and retrieval of newly set data.
/// </summary>
typedef struct PFTitleDataManagementGetPublisherDataRequest
{
    /// <summary>
    ///  array of keys to get back data from the Publisher data blob, set by the admin tools.
    /// </summary>
    _Field_size_(keysCount) const char* const* keys;

    /// <summary>
    /// Count of keys
    /// </summary>
    uint32_t keysCount;

} PFTitleDataManagementGetPublisherDataRequest;

/// <summary>
/// PFTitleDataManagementGetPublisherDataResult data model.
/// </summary>
typedef struct PFTitleDataManagementGetPublisherDataResult
{
    /// <summary>
    /// (Optional) A dictionary object of key / value pairs.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) struct PFStringDictionaryEntry const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

} PFTitleDataManagementGetPublisherDataResult;

/// <summary>
/// PFTitleDataManagementGetRandomResultTablesRequest data model.
/// </summary>
typedef struct PFTitleDataManagementGetRandomResultTablesRequest
{
    /// <summary>
    /// (Optional) Catalog version to fetch tables from. Use default catalog version if null.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

} PFTitleDataManagementGetRandomResultTablesRequest;

/// <summary>
/// PFTitleDataManagementGetStoreItemsRequest data model. A store contains an array of references to
/// items defined in the catalog, along with the prices for the item, in both real world and virtual currencies.
/// These prices act as an override to any prices defined in the catalog. In this way, the base definitions
/// of the items may be defined in the catalog, with all associated properties, while the pricing can
/// be set for each store, as needed. This allows for subsets of goods to be defined for different purposes
/// (in order to simplify showing some, but not all catalog items to users, based upon different characteristics),
/// along with unique prices. Note that all prices defined in the catalog and store definitions for the
/// item are considered valid, and that a compromised client can be made to send a request for an item
/// based upon any of these definitions. If no price is specified in the store for an item, the price
/// set in the catalog should be displayed to the user.
/// </summary>
typedef struct PFTitleDataManagementGetStoreItemsRequest
{
    /// <summary>
    /// (Optional) Catalog version to store items from. Use default catalog version if null.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// Unqiue identifier for the store which is being requested.
    /// </summary>
    _Null_terminated_ const char* storeId;

} PFTitleDataManagementGetStoreItemsRequest;

/// <summary>
/// PFTitleDataManagementStoreMarketingModel data model. Marketing data about a specific store.
/// </summary>
typedef struct PFTitleDataManagementStoreMarketingModel
{
    /// <summary>
    /// (Optional) Tagline for a store.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* description;

    /// <summary>
    /// (Optional) Display name of a store as it will appear to users.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* displayName;

    /// <summary>
    /// (Optional) Custom data about a store.
    /// </summary>
    PFJsonObject metadata;

} PFTitleDataManagementStoreMarketingModel;

/// <summary>
/// PFTitleDataManagementStoreItem data model. A store entry that list a catalog item at a particular
/// price.
/// </summary>
typedef struct PFTitleDataManagementStoreItem
{
    /// <summary>
    /// (Optional) Store specific custom data. The data only exists as part of this store; it is not
    /// transferred to item instances.
    /// </summary>
    PFJsonObject customData;

    /// <summary>
    /// (Optional) Intended display position for this item. Note that 0 is the first position.
    /// </summary>
    _Maybenull_ uint32_t const* displayPosition;

    /// <summary>
    /// Unique identifier of the item as it exists in the catalog - note that this must exactly match
    /// the ItemId from the catalog.
    /// </summary>
    _Null_terminated_ const char* itemId;

    /// <summary>
    /// (Optional) Override prices for this item for specific currencies.
    /// </summary>
    _Maybenull_ _Field_size_(realCurrencyPricesCount) struct PFUint32DictionaryEntry const* realCurrencyPrices;

    /// <summary>
    /// Count of realCurrencyPrices
    /// </summary>
    uint32_t realCurrencyPricesCount;

    /// <summary>
    /// (Optional) Override prices for this item in virtual currencies and "RM" (the base Real Money
    /// purchase price, in USD pennies).
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrencyPricesCount) struct PFUint32DictionaryEntry const* virtualCurrencyPrices;

    /// <summary>
    /// Count of virtualCurrencyPrices
    /// </summary>
    uint32_t virtualCurrencyPricesCount;

} PFTitleDataManagementStoreItem;

/// <summary>
/// PFTitleDataManagementGetStoreItemsResult data model.
/// </summary>
typedef struct PFTitleDataManagementGetStoreItemsResult
{
    /// <summary>
    /// (Optional) The base catalog that this store is a part of.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// (Optional) Additional data about the store.
    /// </summary>
    _Maybenull_ PFTitleDataManagementStoreMarketingModel const* marketingData;

    /// <summary>
    /// (Optional) How the store was last updated (Admin or a third party).
    /// </summary>
    _Maybenull_ PFTitleDataManagementSourceType const* source;

    /// <summary>
    /// (Optional) Array of items which can be purchased from this store.
    /// </summary>
    _Maybenull_ _Field_size_(storeCount) PFTitleDataManagementStoreItem const* const* store;

    /// <summary>
    /// Count of store
    /// </summary>
    uint32_t storeCount;

    /// <summary>
    /// (Optional) The ID of this store.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* storeId;

} PFTitleDataManagementGetStoreItemsResult;

/// <summary>
/// PFTitleDataManagementGetTitleDataRequest data model. This API method is designed to return title
/// specific values which can be read by the client. For example, a developer could choose to store values
/// which modify the user experience, such as enemy spawn rates, weapon strengths, movement speeds, etc.
/// This allows a developer to update the title without the need to create, test, and ship a new build.
/// If an override label is specified in the request, the overrides are applied automatically and returned
/// with the title data. Note that due to caching, there may up to a minute delay in between updating
/// title data and a query returning the newest value.
/// </summary>
typedef struct PFTitleDataManagementGetTitleDataRequest
{
    /// <summary>
    /// (Optional) Specific keys to search for in the title data (leave null to get all keys).
    /// </summary>
    _Maybenull_ _Field_size_(keysCount) const char* const* keys;

    /// <summary>
    /// Count of keys
    /// </summary>
    uint32_t keysCount;

    /// <summary>
    /// (Optional) Optional field that specifies the name of an override. This value is ignored when
    /// used by the game client; otherwise, the overrides are applied automatically to the title data.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* overrideLabel;

} PFTitleDataManagementGetTitleDataRequest;

/// <summary>
/// PFTitleDataManagementGetTitleDataResult data model.
/// </summary>
typedef struct PFTitleDataManagementGetTitleDataResult
{
    /// <summary>
    /// (Optional) A dictionary object of key / value pairs.
    /// </summary>
    _Maybenull_ _Field_size_(dataCount) struct PFStringDictionaryEntry const* data;

    /// <summary>
    /// Count of data
    /// </summary>
    uint32_t dataCount;

} PFTitleDataManagementGetTitleDataResult;

/// <summary>
/// PFTitleDataManagementListVirtualCurrencyTypesResult data model.
/// </summary>
typedef struct PFTitleDataManagementListVirtualCurrencyTypesResult
{
    /// <summary>
    /// (Optional) List of virtual currency names defined for this title.
    /// </summary>
    _Maybenull_ _Field_size_(virtualCurrenciesCount) PFTitleDataManagementVirtualCurrencyData const* const* virtualCurrencies;

    /// <summary>
    /// Count of virtualCurrencies
    /// </summary>
    uint32_t virtualCurrenciesCount;

} PFTitleDataManagementListVirtualCurrencyTypesResult;

/// <summary>
/// PFTitleDataManagementRemoveVirtualCurrencyTypesRequest data model. Virtual currencies to be removed
/// cannot have entries in any catalog nor store for the title. Note that this operation will not remove
/// player balances for the removed currencies; if a deleted currency is recreated at any point, user
/// balances will be in an undefined state.
/// </summary>
typedef struct PFTitleDataManagementRemoveVirtualCurrencyTypesRequest
{
    /// <summary>
    /// List of virtual currencies to delete.
    /// </summary>
    _Field_size_(virtualCurrenciesCount) PFTitleDataManagementVirtualCurrencyData const* const* virtualCurrencies;

    /// <summary>
    /// Count of virtualCurrencies
    /// </summary>
    uint32_t virtualCurrenciesCount;

} PFTitleDataManagementRemoveVirtualCurrencyTypesRequest;

/// <summary>
/// PFTitleDataManagementUpdateCatalogItemsRequest data model. This operation is not additive. Using
/// it will cause the indicated catalog version to be created from scratch. If there is an existing catalog
/// with the version number in question, it will be deleted and replaced with only the items specified
/// in this call.
/// </summary>
typedef struct PFTitleDataManagementUpdateCatalogItemsRequest
{
    /// <summary>
    /// (Optional) Array of catalog items to be submitted. Note that while CatalogItem has a parameter
    /// for CatalogVersion, it is not required and ignored in this call.
    /// </summary>
    _Maybenull_ _Field_size_(catalogCount) PFTitleDataManagementCatalogItem const* const* catalog;

    /// <summary>
    /// Count of catalog
    /// </summary>
    uint32_t catalogCount;

    /// <summary>
    /// (Optional) Which catalog is being updated. If null, uses the default catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

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
    /// (Optional) Should this catalog be set as the default catalog. Defaults to true. If there is currently
    /// no default catalog, this will always set it.
    /// </summary>
    _Maybenull_ bool const* setAsDefaultCatalog;

} PFTitleDataManagementUpdateCatalogItemsRequest;

/// <summary>
/// PFTitleDataManagementSetPublisherDataRequest data model. This API is designed to store publisher-specific
/// values which can be read, but not written to, by the client. This data is shared across all titles
/// assigned to a particular publisher, and can be used for cross-game coordination. Only titles assigned
/// to a publisher can use this API. This operation is additive. If a Key does not exist in the current
/// dataset, it will be added with the specified Value. If it already exists, the Value for that key will
/// be overwritten with the new Value. For more information email helloplayfab@microsoft.com.
/// </summary>
typedef struct PFTitleDataManagementSetPublisherDataRequest
{
    /// <summary>
    /// Key we want to set a value on (note, this is additive - will only replace an existing key's value
    /// if they are the same name.) Keys are trimmed of whitespace. Keys may not begin with the '!' character.
    /// </summary>
    _Null_terminated_ const char* key;

    /// <summary>
    /// (Optional) New value to set. Set to null to remove a value.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* value;

} PFTitleDataManagementSetPublisherDataRequest;

/// <summary>
/// PFTitleDataManagementUpdateStoreItemsRequest data model. This operation is not additive. Using it
/// will cause the indicated virtual store to be created from scratch. If there is an existing store with
/// the same storeId, it will be deleted and replaced with only the items specified in this call. A store
/// contains an array of references to items defined inthe catalog, along with the prices for the item,
/// in both real world and virtual currencies. These prices act as an override to any prices defined in
/// the catalog. In this way, the base definitions of the items may be defined in the catalog, with all
/// associated properties, while the pricing can be set for each store, as needed. This allows for subsets
/// of goods to be defined for different purposes (in order to simplify showing some, but not all catalog
/// items to users, based upon different characteristics), along with unique prices. Note that all prices
/// defined in the catalog and store definitions for the item are considered valid, and that a compromised
/// client can be made to send a request for an item based upon any of these definitions. If no price
/// is specified in the store for an item, the price set in the catalog should be displayed to the user.
/// </summary>
typedef struct PFTitleDataManagementUpdateStoreItemsRequest
{
    /// <summary>
    /// (Optional) Catalog version of the store to update. If null, uses the default catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

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
    /// (Optional) Additional data about the store.
    /// </summary>
    _Maybenull_ PFTitleDataManagementStoreMarketingModel const* marketingData;

    /// <summary>
    /// (Optional) Array of store items - references to catalog items, with specific pricing - to be
    /// added.
    /// </summary>
    _Maybenull_ _Field_size_(storeCount) PFTitleDataManagementStoreItem const* const* store;

    /// <summary>
    /// Count of store
    /// </summary>
    uint32_t storeCount;

    /// <summary>
    /// Unique identifier for the store which is to be updated.
    /// </summary>
    _Null_terminated_ const char* storeId;

} PFTitleDataManagementUpdateStoreItemsRequest;

/// <summary>
/// PFTitleDataManagementSetTitleDataRequest data model. This API method is designed to store title specific
/// values which can be read by the client. For example, a developer could choose to store values which
/// modify the user experience, such as enemy spawn rates, weapon strengths, movement speeds, etc. This
/// allows a developer to update the title without the need to create, test, and ship a new build. This
/// operation is additive. If a Key does not exist in the current dataset, it will be added with the specified
/// Value. If it already exists, the Value for that key will be overwritten with the new Value.
/// </summary>
typedef struct PFTitleDataManagementSetTitleDataRequest
{
    /// <summary>
    /// (Optional) Id of azure resource.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* azureResourceId;

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
    /// Key we want to set a value on (note, this is additive - will only replace an existing key's value
    /// if they are the same name.) Keys are trimmed of whitespace. Keys may not begin with the '!' character.
    /// </summary>
    _Null_terminated_ const char* key;

    /// <summary>
    /// (Optional) Unique identifier for the title, found in the Settings > Game Properties section of
    /// the PlayFab developer site when a title has been selected.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* titleId;

    /// <summary>
    /// (Optional) New value to set. Set to null to remove a value.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* value;

} PFTitleDataManagementSetTitleDataRequest;

/// <summary>
/// PFTitleDataManagementSetTitleDataResult data model.
/// </summary>
typedef struct PFTitleDataManagementSetTitleDataResult
{
    /// <summary>
    /// (Optional) Id of azure resource.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* azureResourceId;

} PFTitleDataManagementSetTitleDataResult;

/// <summary>
/// PFTitleDataManagementTitleDataKeyValue data model.
/// </summary>
typedef struct PFTitleDataManagementTitleDataKeyValue
{
    /// <summary>
    /// (Optional) Key we want to set a value on (note, this is additive - will only replace an existing
    /// key's value if they are the same name.) Keys are trimmed of whitespace. Keys may not begin with
    /// the '!' character.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* key;

    /// <summary>
    /// (Optional) New value to set. Set to null to remove a value.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* value;

} PFTitleDataManagementTitleDataKeyValue;

/// <summary>
/// PFTitleDataManagementSetTitleDataAndOverridesRequest data model. Will set the given key values in
/// the specified override or the primary title data based on whether the label is provided or not.
/// </summary>
typedef struct PFTitleDataManagementSetTitleDataAndOverridesRequest
{
    /// <summary>
    /// List of titleData key-value pairs to set/delete. Use an empty value to delete an existing key;
    /// use a non-empty value to create/update a key.
    /// </summary>
    _Field_size_(keyValuesCount) PFTitleDataManagementTitleDataKeyValue const* const* keyValues;

    /// <summary>
    /// Count of keyValues
    /// </summary>
    uint32_t keyValuesCount;

    /// <summary>
    /// (Optional) Name of the override.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* overrideLabel;

} PFTitleDataManagementSetTitleDataAndOverridesRequest;

/// <summary>
/// PFTitleDataManagementSetupPushNotificationRequest data model. When using the Apple Push Notification
/// service (APNS) or the development version (APNS_SANDBOX), the APNS Private Key should be used as the
/// Credential in this call. With Google Cloud Messaging (GCM), the Android API Key should be used. The
/// current ARN (if one exists) can be overwritten by setting the OverwriteOldARN boolean to true.
/// </summary>
typedef struct PFTitleDataManagementSetupPushNotificationRequest
{
    /// <summary>
    /// Credential is the Private Key for APNS/APNS_SANDBOX, and the API Key for GCM.
    /// </summary>
    _Null_terminated_ const char* credential;

    /// <summary>
    /// (Optional) For APNS, this is the PlatformPrincipal (SSL Certificate).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* key;

    /// <summary>
    /// (Optional) This field is deprecated and any usage of this will cause the API to fail.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* name;

    /// <summary>
    /// Replace any existing ARN with the newly generated one. If this is set to false, an error will
    /// be returned if notifications have already setup for this platform.
    /// </summary>
    bool overwriteOldARN;

    /// <summary>
    /// Supported notification platforms are Apple Push Notification Service (APNS and APNS_SANDBOX)
    /// for iOS and Google Cloud Messaging (GCM) for Android.
    /// </summary>
    PFTitleDataManagementPushSetupPlatform platform;

} PFTitleDataManagementSetupPushNotificationRequest;

/// <summary>
/// PFTitleDataManagementSetupPushNotificationResult data model.
/// </summary>
typedef struct PFTitleDataManagementSetupPushNotificationResult
{
    /// <summary>
    /// (Optional) Amazon Resource Name for the created notification topic.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* aRN;

} PFTitleDataManagementSetupPushNotificationResult;

/// <summary>
/// PFTitleDataManagementRandomResultTable data model.
/// </summary>
typedef struct PFTitleDataManagementRandomResultTable
{
    /// <summary>
    /// Child nodes that indicate what kind of drop table item this actually is.
    /// </summary>
    _Field_size_(nodesCount) PFResultTableNode const* const* nodes;

    /// <summary>
    /// Count of nodes
    /// </summary>
    uint32_t nodesCount;

    /// <summary>
    /// Unique name for this drop table.
    /// </summary>
    _Null_terminated_ const char* tableId;

} PFTitleDataManagementRandomResultTable;

/// <summary>
/// PFTitleDataManagementUpdateRandomResultTablesRequest data model. This operation is additive. Tables
/// with TableId values not currently defined will be added, while those with TableId values matching
/// Tables currently in the catalog will be overwritten with the given values.
/// </summary>
typedef struct PFTitleDataManagementUpdateRandomResultTablesRequest
{
    /// <summary>
    /// (Optional) Which catalog is being updated. If null, update the current default catalog version.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

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
    /// (Optional) Array of random result tables to make available (Note: specifying an existing TableId
    /// will result in overwriting that table, while any others will be added to the available set).
    /// </summary>
    _Maybenull_ _Field_size_(tablesCount) PFTitleDataManagementRandomResultTable const* const* tables;

    /// <summary>
    /// Count of tables
    /// </summary>
    uint32_t tablesCount;

} PFTitleDataManagementUpdateRandomResultTablesRequest;

/// <summary>
/// PFTitleDataManagementGetTimeResult data model. Time is always returned as Coordinated Universal Time
/// (UTC).
/// </summary>
typedef struct PFTitleDataManagementGetTimeResult
{
    /// <summary>
    /// Current server time when the request was received, in UTC.
    /// </summary>
    time_t time;

} PFTitleDataManagementGetTimeResult;

/// <summary>
/// PFTitleDataManagementGetTitleNewsRequest data model.
/// </summary>
typedef struct PFTitleDataManagementGetTitleNewsRequest
{
    /// <summary>
    /// (Optional) Limits the results to the last n entries. Defaults to 10 if not set.
    /// </summary>
    _Maybenull_ int32_t const* count;

} PFTitleDataManagementGetTitleNewsRequest;

/// <summary>
/// PFTitleDataManagementTitleNewsItem data model.
/// </summary>
typedef struct PFTitleDataManagementTitleNewsItem
{
    /// <summary>
    /// (Optional) News item text.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* body;

    /// <summary>
    /// (Optional) Unique identifier of news item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* newsId;

    /// <summary>
    /// Date and time when the news item was posted.
    /// </summary>
    time_t timestamp;

    /// <summary>
    /// (Optional) Title of the news item.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* title;

} PFTitleDataManagementTitleNewsItem;

/// <summary>
/// PFTitleDataManagementGetTitleNewsResult data model.
/// </summary>
typedef struct PFTitleDataManagementGetTitleNewsResult
{
    /// <summary>
    /// (Optional) Array of news items.
    /// </summary>
    _Maybenull_ _Field_size_(newsCount) PFTitleDataManagementTitleNewsItem const* const* news;

    /// <summary>
    /// Count of news
    /// </summary>
    uint32_t newsCount;

} PFTitleDataManagementGetTitleNewsResult;

/// <summary>
/// PFTitleDataManagementGetStoreItemsServerRequest data model. A store contains an array of references
/// to items defined in one or more catalog versions of the game, along with the prices for the item,
/// in both real world and virtual currencies. These prices act as an override to any prices defined in
/// the catalog. In this way, the base definitions of the items may be defined in the catalog, with all
/// associated properties, while the pricing can be set for each store, as needed. This allows for subsets
/// of goods to be defined for different purposes (in order to simplify showing some, but not all catalog
/// items to users, based upon different characteristics), along with unique prices. Note that all prices
/// defined in the catalog and store definitions for the item are considered valid, and that a compromised
/// client can be made to send a request for an item based upon any of these definitions. If no price
/// is specified in the store for an item, the price set in the catalog should be displayed to the user.
/// </summary>
typedef struct PFTitleDataManagementGetStoreItemsServerRequest
{
    /// <summary>
    /// (Optional) Catalog version to store items from. Use default catalog version if null.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

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
    /// (Optional) Optional identifier for the player to use in requesting the store information - if
    /// used, segment overrides will be applied.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* playFabId;

    /// <summary>
    /// Unqiue identifier for the store which is being requested.
    /// </summary>
    _Null_terminated_ const char* storeId;

} PFTitleDataManagementGetStoreItemsServerRequest;

#pragma pop_macro("IN")

}
