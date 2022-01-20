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
/// PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequest data model. More information can
/// be found on configuring your game for the Google Cloud Messaging service in the Google developer documentation,
/// here: http://developer.android.com/google/gcm/client.html. The steps to configure and send Push Notifications
/// is described in the PlayFab tutorials, here: https://docs.microsoft.com/gaming/playfab/features/engagement/push-notifications/quickstart.
/// </summary>
typedef struct PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequest
{
    /// <summary>
    /// (Optional) Message to display when confirming push notification.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* confirmationMessage;

    /// <summary>
    /// Registration ID provided by the Google Cloud Messaging service when the title registered to receive
    /// push notifications (see the GCM documentation, here: http://developer.android.com/google/gcm/client.html).
    /// </summary>
    _Null_terminated_ const char* deviceToken;

    /// <summary>
    /// (Optional) If true, send a test push message immediately after sucessful registration. Defaults
    /// to false.
    /// </summary>
    _Maybenull_ bool const* sendPushNotificationConfirmation;

} PFPlatformSpecificAndroidDevicePushNotificationRegistrationRequest;

/// <summary>
/// PFPlatformSpecificMicrosoftStorePayload data model.
/// </summary>
typedef struct PFPlatformSpecificMicrosoftStorePayload
{
    /// <summary>
    /// (Optional) Microsoft store ID key. This is optional. Alternatively you can use XboxToken.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* collectionsMsIdKey;

    /// <summary>
    /// (Optional) If collectionsMsIdKey is provided, this will verify the user id in the collectionsMsIdKey
    /// is the same.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* userId;

    /// <summary>
    /// (Optional) Token provided by the Xbox Live SDK/XDK method GetTokenAndSignatureAsync("POST", "https://playfabapi.com/",
    /// ""). This is optional. Alternatively can use CollectionsMsIdKey.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* xboxToken;

} PFPlatformSpecificMicrosoftStorePayload;

/// <summary>
/// PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequest data model.
/// </summary>
typedef struct PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequest
{
    /// <summary>
    /// (Optional) Catalog version to use.
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
    /// Marketplace specific payload containing details to fetch in app purchase transactions.
    /// </summary>
    PFPlatformSpecificMicrosoftStorePayload const* marketplaceSpecificData;

} PFPlatformSpecificConsumeMicrosoftStoreEntitlementsRequest;

/// <summary>
/// PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse data model.
/// </summary>
typedef struct PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse
{
    /// <summary>
    /// (Optional) Details for the items purchased.
    /// </summary>
    _Maybenull_ _Field_size_(itemsCount) PFItemInstance const* const* items;

    /// <summary>
    /// Count of items
    /// </summary>
    uint32_t itemsCount;

} PFPlatformSpecificConsumeMicrosoftStoreEntitlementsResponse;

/// <summary>
/// PFPlatformSpecificPlayStation5Payload data model.
/// </summary>
typedef struct PFPlatformSpecificPlayStation5Payload
{
    /// <summary>
    /// (Optional) An optional list of entitlement ids to query against PSN.
    /// </summary>
    _Maybenull_ _Field_size_(idsCount) const char* const* ids;

    /// <summary>
    /// Count of ids
    /// </summary>
    uint32_t idsCount;

    /// <summary>
    /// (Optional) Id of the PSN service label to consume entitlements from.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* serviceLabel;

} PFPlatformSpecificPlayStation5Payload;

/// <summary>
/// PFPlatformSpecificConsumePS5EntitlementsRequest data model.
/// </summary>
typedef struct PFPlatformSpecificConsumePS5EntitlementsRequest
{
    /// <summary>
    /// (Optional) Catalog version to use.
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
    /// Marketplace specific payload containing details to fetch in app purchase transactions.
    /// </summary>
    PFPlatformSpecificPlayStation5Payload const* marketplaceSpecificData;

} PFPlatformSpecificConsumePS5EntitlementsRequest;

/// <summary>
/// PFPlatformSpecificConsumePS5EntitlementsResult data model.
/// </summary>
typedef struct PFPlatformSpecificConsumePS5EntitlementsResult
{
    /// <summary>
    /// (Optional) Details for the items purchased.
    /// </summary>
    _Maybenull_ _Field_size_(itemsCount) PFItemInstance const* const* items;

    /// <summary>
    /// Count of items
    /// </summary>
    uint32_t itemsCount;

} PFPlatformSpecificConsumePS5EntitlementsResult;

/// <summary>
/// PFPlatformSpecificConsumePSNEntitlementsRequest data model.
/// </summary>
typedef struct PFPlatformSpecificConsumePSNEntitlementsRequest
{
    /// <summary>
    /// (Optional) Which catalog to match granted entitlements against. If null, defaults to title default
    /// catalog.
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
    /// Id of the PSN service label to consume entitlements from.
    /// </summary>
    int32_t serviceLabel;

} PFPlatformSpecificConsumePSNEntitlementsRequest;

/// <summary>
/// PFPlatformSpecificConsumePSNEntitlementsResult data model.
/// </summary>
typedef struct PFPlatformSpecificConsumePSNEntitlementsResult
{
    /// <summary>
    /// (Optional) Array of items granted to the player as a result of consuming entitlements.
    /// </summary>
    _Maybenull_ _Field_size_(itemsGrantedCount) PFItemInstance const* const* itemsGranted;

    /// <summary>
    /// Count of itemsGranted
    /// </summary>
    uint32_t itemsGrantedCount;

} PFPlatformSpecificConsumePSNEntitlementsResult;

/// <summary>
/// PFPlatformSpecificConsumeXboxEntitlementsRequest data model.
/// </summary>
typedef struct PFPlatformSpecificConsumeXboxEntitlementsRequest
{
    /// <summary>
    /// (Optional) Catalog version to use.
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
    /// Token provided by the Xbox Live SDK/XDK method GetTokenAndSignatureAsync("POST", "https://playfabapi.com/",
    /// "").
    /// </summary>
    _Null_terminated_ const char* xboxToken;

} PFPlatformSpecificConsumeXboxEntitlementsRequest;

/// <summary>
/// PFPlatformSpecificConsumeXboxEntitlementsResult data model.
/// </summary>
typedef struct PFPlatformSpecificConsumeXboxEntitlementsResult
{
    /// <summary>
    /// (Optional) Details for the items purchased.
    /// </summary>
    _Maybenull_ _Field_size_(itemsCount) PFItemInstance const* const* items;

    /// <summary>
    /// Count of items
    /// </summary>
    uint32_t itemsCount;

} PFPlatformSpecificConsumeXboxEntitlementsResult;

/// <summary>
/// PFPlatformSpecificRefreshPSNAuthTokenRequest data model.
/// </summary>
typedef struct PFPlatformSpecificRefreshPSNAuthTokenRequest
{
    /// <summary>
    /// Auth code returned by PSN OAuth system.
    /// </summary>
    _Null_terminated_ const char* authCode;

    /// <summary>
    /// (Optional) Id of the PSN issuer environment. If null, defaults to production environment.
    /// </summary>
    _Maybenull_ int32_t const* issuerId;

    /// <summary>
    /// Redirect URI supplied to PSN when requesting an auth code.
    /// </summary>
    _Null_terminated_ const char* redirectUri;

} PFPlatformSpecificRefreshPSNAuthTokenRequest;

/// <summary>
/// PFPlatformSpecificRegisterForIOSPushNotificationRequest data model. The steps to configure and send
/// Push Notifications is described in the PlayFab tutorials, here: https://docs.microsoft.com/gaming/playfab/features/engagement/push-notifications/quickstart.
/// </summary>
typedef struct PFPlatformSpecificRegisterForIOSPushNotificationRequest
{
    /// <summary>
    /// (Optional) Message to display when confirming push notification.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* confirmationMessage;

    /// <summary>
    /// Unique token generated by the Apple Push Notification service when the title registered to receive
    /// push notifications.
    /// </summary>
    _Null_terminated_ const char* deviceToken;

    /// <summary>
    /// (Optional) If true, send a test push message immediately after sucessful registration. Defaults
    /// to false.
    /// </summary>
    _Maybenull_ bool const* sendPushNotificationConfirmation;

} PFPlatformSpecificRegisterForIOSPushNotificationRequest;

/// <summary>
/// PFPlatformSpecificRestoreIOSPurchasesRequest data model. The title should obtain a refresh receipt
/// via restoreCompletedTransactions in the SKPaymentQueue of the Apple StoreKit and pass that in to this
/// call. The resultant receipt contains new receipt instances for all non-consumable goods previously
/// purchased by the user. This API call iterates through every purchase in the receipt and restores the
/// items if they still exist in the catalog and can be validated.
/// </summary>
typedef struct PFPlatformSpecificRestoreIOSPurchasesRequest
{
    /// <summary>
    /// (Optional) Catalog version of the restored items. If null, defaults to primary catalog.
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
    /// Base64 encoded receipt data, passed back by the App Store as a result of a successful purchase.
    /// </summary>
    _Null_terminated_ const char* receiptData;

} PFPlatformSpecificRestoreIOSPurchasesRequest;

/// <summary>
/// PFPlatformSpecificPurchaseReceiptFulfillment data model.
/// </summary>
typedef struct PFPlatformSpecificPurchaseReceiptFulfillment
{
    /// <summary>
    /// (Optional) Items granted to the player in fulfillment of the validated receipt.
    /// </summary>
    _Maybenull_ _Field_size_(fulfilledItemsCount) PFItemInstance const* const* fulfilledItems;

    /// <summary>
    /// Count of fulfilledItems
    /// </summary>
    uint32_t fulfilledItemsCount;

    /// <summary>
    /// (Optional) Source of the payment price information for the recorded purchase transaction. A value
    /// of 'Request' indicates that the price specified in the request was used, whereas a value of 'Catalog'
    /// indicates that the real-money price of the catalog item matching the product ID in the validated
    /// receipt transaction and the currency specified in the request (defaulting to USD) was used.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* recordedPriceSource;

    /// <summary>
    /// (Optional) Currency used to purchase the items (ISO 4217 currency code).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* recordedTransactionCurrency;

    /// <summary>
    /// (Optional) Amount of the stated currency paid for the items, in centesimal units.
    /// </summary>
    _Maybenull_ uint32_t const* recordedTransactionTotal;

} PFPlatformSpecificPurchaseReceiptFulfillment;

/// <summary>
/// PFPlatformSpecificRestoreIOSPurchasesResult data model. Once verified, the valid items will be restored
/// into the user's inventory. This result should be used for immediate updates to the local client game
/// state as opposed to the GetUserInventory API which can have an up to half second delay.
/// </summary>
typedef struct PFPlatformSpecificRestoreIOSPurchasesResult
{
    /// <summary>
    /// (Optional) Fulfilled inventory items and recorded purchases in fulfillment of the validated receipt
    /// transactions.
    /// </summary>
    _Maybenull_ _Field_size_(fulfillmentsCount) PFPlatformSpecificPurchaseReceiptFulfillment const* const* fulfillments;

    /// <summary>
    /// Count of fulfillments
    /// </summary>
    uint32_t fulfillmentsCount;

} PFPlatformSpecificRestoreIOSPurchasesResult;

/// <summary>
/// PFPlatformSpecificValidateAmazonReceiptRequest data model.
/// </summary>
typedef struct PFPlatformSpecificValidateAmazonReceiptRequest
{
    /// <summary>
    /// (Optional) Catalog version of the fulfilled items. If null, defaults to the primary catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// (Optional) Currency used to pay for the purchase (ISO 4217 currency code).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* currencyCode;

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
    /// Amount of the stated currency paid, in centesimal units.
    /// </summary>
    int32_t purchasePrice;

    /// <summary>
    /// ReceiptId returned by the Amazon App Store in-app purchase API.
    /// </summary>
    _Null_terminated_ const char* receiptId;

    /// <summary>
    /// AmazonId of the user making the purchase as returned by the Amazon App Store in-app purchase
    /// API.
    /// </summary>
    _Null_terminated_ const char* userId;

} PFPlatformSpecificValidateAmazonReceiptRequest;

/// <summary>
/// PFPlatformSpecificValidateAmazonReceiptResult data model. Once verified, the catalog item matching
/// the Amazon item name will be added to the user's inventory. This result should be used for immediate
/// updates to the local client game state as opposed to the GetUserInventory API which can have an up
/// to half second delay.
/// </summary>
typedef struct PFPlatformSpecificValidateAmazonReceiptResult
{
    /// <summary>
    /// (Optional) Fulfilled inventory items and recorded purchases in fulfillment of the validated receipt
    /// transactions.
    /// </summary>
    _Maybenull_ _Field_size_(fulfillmentsCount) PFPlatformSpecificPurchaseReceiptFulfillment const* const* fulfillments;

    /// <summary>
    /// Count of fulfillments
    /// </summary>
    uint32_t fulfillmentsCount;

} PFPlatformSpecificValidateAmazonReceiptResult;

/// <summary>
/// PFPlatformSpecificValidateGooglePlayPurchaseRequest data model. The packageName and productId are
/// defined in the GooglePlay store. The productId must match the ItemId of the inventory item in the
/// PlayFab catalog for the title. This enables the PlayFab service to securely validate that the purchase
/// is for the correct item, in order to prevent uses from passing valid receipts as being for more expensive
/// items (passing a receipt for a 99-cent purchase as being for a $19.99 purchase, for example). Each
/// receipt may be validated only once to avoid granting the same item over and over from a single purchase.
/// </summary>
typedef struct PFPlatformSpecificValidateGooglePlayPurchaseRequest
{
    /// <summary>
    /// (Optional) Catalog version of the fulfilled items. If null, defaults to the primary catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// (Optional) Currency used to pay for the purchase (ISO 4217 currency code).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* currencyCode;

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
    /// (Optional) Amount of the stated currency paid, in centesimal units.
    /// </summary>
    _Maybenull_ uint32_t const* purchasePrice;

    /// <summary>
    /// Original JSON string returned by the Google Play IAB API.
    /// </summary>
    _Null_terminated_ const char* receiptJson;

    /// <summary>
    /// Signature returned by the Google Play IAB API.
    /// </summary>
    _Null_terminated_ const char* signature;

} PFPlatformSpecificValidateGooglePlayPurchaseRequest;

/// <summary>
/// PFPlatformSpecificValidateGooglePlayPurchaseResult data model. Once verified, the catalog item (ItemId)
/// matching the GooglePlay store item (productId) will be added to the user's inventory. This result
/// should be used for immediate updates to the local client game state as opposed to the GetUserInventory
/// API which can have an up to half second delay.
/// </summary>
typedef struct PFPlatformSpecificValidateGooglePlayPurchaseResult
{
    /// <summary>
    /// (Optional) Fulfilled inventory items and recorded purchases in fulfillment of the validated receipt
    /// transactions.
    /// </summary>
    _Maybenull_ _Field_size_(fulfillmentsCount) PFPlatformSpecificPurchaseReceiptFulfillment const* const* fulfillments;

    /// <summary>
    /// Count of fulfillments
    /// </summary>
    uint32_t fulfillmentsCount;

} PFPlatformSpecificValidateGooglePlayPurchaseResult;

/// <summary>
/// PFPlatformSpecificValidateIOSReceiptRequest data model. The CurrencyCode and PurchasePrice must match
/// the price which was set up for the item in the Apple store. In addition, The ItemId of the inventory
/// in the PlayFab Catalog must match the Product ID as it was set up in the Apple store. This enables
/// the PlayFab service to securely validate that the purchase is for the correct item, in order to prevent
/// uses from passing valid receipts as being for more expensive items (passing a receipt for a 99-cent
/// purchase as being for a $19.99 purchase, for example).
/// </summary>
typedef struct PFPlatformSpecificValidateIOSReceiptRequest
{
    /// <summary>
    /// (Optional) Catalog version of the fulfilled items. If null, defaults to the primary catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// (Optional) Currency used to pay for the purchase (ISO 4217 currency code).
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* currencyCode;

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
    /// Amount of the stated currency paid, in centesimal units.
    /// </summary>
    int32_t purchasePrice;

    /// <summary>
    /// Base64 encoded receipt data, passed back by the App Store as a result of a successful purchase.
    /// </summary>
    _Null_terminated_ const char* receiptData;

} PFPlatformSpecificValidateIOSReceiptRequest;

/// <summary>
/// PFPlatformSpecificValidateIOSReceiptResult data model. Once verified, the catalog item matching the
/// iTunes item name will be added to the user's inventory. This result should be used for immediate updates
/// to the local client game state as opposed to the GetUserInventory API which can have an up to half
/// second delay.
/// </summary>
typedef struct PFPlatformSpecificValidateIOSReceiptResult
{
    /// <summary>
    /// (Optional) Fulfilled inventory items and recorded purchases in fulfillment of the validated receipt
    /// transactions.
    /// </summary>
    _Maybenull_ _Field_size_(fulfillmentsCount) PFPlatformSpecificPurchaseReceiptFulfillment const* const* fulfillments;

    /// <summary>
    /// Count of fulfillments
    /// </summary>
    uint32_t fulfillmentsCount;

} PFPlatformSpecificValidateIOSReceiptResult;

/// <summary>
/// PFPlatformSpecificValidateWindowsReceiptRequest data model.
/// </summary>
typedef struct PFPlatformSpecificValidateWindowsReceiptRequest
{
    /// <summary>
    /// (Optional) Catalog version of the fulfilled items. If null, defaults to the primary catalog.
    /// </summary>
    _Maybenull_ _Null_terminated_ const char* catalogVersion;

    /// <summary>
    /// Currency used to pay for the purchase (ISO 4217 currency code).
    /// </summary>
    _Null_terminated_ const char* currencyCode;

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
    /// Amount of the stated currency paid, in centesimal units.
    /// </summary>
    uint32_t purchasePrice;

    /// <summary>
    /// XML Receipt returned by the Windows App Store in-app purchase API.
    /// </summary>
    _Null_terminated_ const char* receipt;

} PFPlatformSpecificValidateWindowsReceiptRequest;

/// <summary>
/// PFPlatformSpecificValidateWindowsReceiptResult data model. Once verified, the catalog item matching
/// the Product name will be added to the user's inventory. This result should be used for immediate updates
/// to the local client game state as opposed to the GetUserInventory API which can have an up to half
/// second delay.
/// </summary>
typedef struct PFPlatformSpecificValidateWindowsReceiptResult
{
    /// <summary>
    /// (Optional) Fulfilled inventory items and recorded purchases in fulfillment of the validated receipt
    /// transactions.
    /// </summary>
    _Maybenull_ _Field_size_(fulfillmentsCount) PFPlatformSpecificPurchaseReceiptFulfillment const* const* fulfillments;

    /// <summary>
    /// Count of fulfillments
    /// </summary>
    uint32_t fulfillmentsCount;

} PFPlatformSpecificValidateWindowsReceiptResult;

/// <summary>
/// PFPlatformSpecificAwardSteamAchievementItem data model.
/// </summary>
typedef struct PFPlatformSpecificAwardSteamAchievementItem
{
    /// <summary>
    /// Unique Steam achievement name.
    /// </summary>
    _Null_terminated_ const char* achievementName;

    /// <summary>
    /// Unique PlayFab assigned ID of the user on whom the operation will be performed.
    /// </summary>
    _Null_terminated_ const char* playFabId;

    /// <summary>
    /// Result of the award attempt (only valid on response, not on request).
    /// </summary>
    bool result;

} PFPlatformSpecificAwardSteamAchievementItem;

/// <summary>
/// PFPlatformSpecificAwardSteamAchievementRequest data model.
/// </summary>
typedef struct PFPlatformSpecificAwardSteamAchievementRequest
{
    /// <summary>
    /// Array of achievements to grant and the users to whom they are to be granted.
    /// </summary>
    _Field_size_(achievementsCount) PFPlatformSpecificAwardSteamAchievementItem const* const* achievements;

    /// <summary>
    /// Count of achievements
    /// </summary>
    uint32_t achievementsCount;

} PFPlatformSpecificAwardSteamAchievementRequest;

/// <summary>
/// PFPlatformSpecificAwardSteamAchievementResult data model.
/// </summary>
typedef struct PFPlatformSpecificAwardSteamAchievementResult
{
    /// <summary>
    /// (Optional) Array of achievements granted.
    /// </summary>
    _Maybenull_ _Field_size_(achievementResultsCount) PFPlatformSpecificAwardSteamAchievementItem const* const* achievementResults;

    /// <summary>
    /// Count of achievementResults
    /// </summary>
    uint32_t achievementResultsCount;

} PFPlatformSpecificAwardSteamAchievementResult;

#pragma pop_macro("IN")

}
