// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFPlayerItemManagementDataModels.h>
#include <playfab/PFGlobal.h>
#include <playfab/PFTitlePlayer.h>

extern "C"
{

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Increments the specified virtual currency by the stated amount
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminSubtractUserVirtualCurrencyAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementAdminAddUserVirtualCurrencyGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerItemManagementAdminAddUserVirtualCurrencyAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementAdminAddUserVirtualCurrencyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminAddUserVirtualCurrency call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementAdminAddUserVirtualCurrencyGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementAdminAddUserVirtualCurrencyAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementAdminAddUserVirtualCurrencyGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementModifyUserVirtualCurrencyResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Checks the global count for the limited edition item.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This returns the total number of these items available. See also AdminIncrementLimitedEditionItemAvailabilityAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementAdminCheckLimitedEditionItemAvailabilityGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerItemManagementAdminCheckLimitedEditionItemAvailabilityAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementAdminCheckLimitedEditionItemAvailabilityAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementAdminCheckLimitedEditionItemAvailabilityGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult* result
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the specified user's current inventory of virtual goods
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// All items currently in the user inventory will be returned, irrespective of how they were acquired
/// (via purchasing, grants, coupons, etc.). Items that are expired, fully consumed, or are no longer
/// valid are not considered to be in the user's current inventory, and so will not be not included. See
/// also AdminGetUserAccountInfoAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementAdminGetUserInventoryGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFPlayerItemManagementAdminGetUserInventoryAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementAdminGetUserInventoryRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetUserInventory call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementAdminGetUserInventoryGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementAdminGetUserInventoryAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementAdminGetUserInventoryGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementAdminGetUserInventoryResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Adds the specified items to the specified user inventories
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function directly adds inventory items to user inventories. As a result of this operations,
/// the user will not be charged any transaction fee, regardless of the inventory item catalog definition.
/// Please note that the processing time for inventory grants and purchases increases fractionally the
/// more items are in the inventory, and the more items are in the grant/purchase operation.
///
/// If successful, call <see cref="PFPlayerItemManagementAdminGrantItemsToUsersGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFPlayerItemManagementAdminGrantItemsToUsersAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementGrantItemsToUsersRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGrantItemsToUsers call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementAdminGrantItemsToUsersGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementAdminGrantItemsToUsersAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementAdminGrantItemsToUsersGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementGrantItemsToUsersResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Increases the global count for the given scarce resource.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This operation will increment the global counter for the number of these items available. This number
/// cannot be decremented, except by actual grants. See also AdminCheckLimitedEditionItemAvailabilityAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFPlayerItemManagementAdminIncrementLimitedEditionItemAvailabilityAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Revokes access to an item in a user's inventory
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// In cases where the inventory item in question is a 'crate', and the items it contained have already
/// been dispensed, this will not revoke access or otherwise remove the items which were dispensed. See
/// also AdminGetUserInventoryAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFPlayerItemManagementAdminRevokeInventoryItemAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementRevokeInventoryItemRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Revokes access for up to 25 items across multiple users and characters.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// In cases where the inventory item in question is a 'crate', and the items it contained have already
/// been dispensed, this will not revoke access or otherwise remove the items which were dispensed. See
/// also AdminGetUserInventoryAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementAdminRevokeInventoryItemsGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerItemManagementAdminRevokeInventoryItemsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementRevokeInventoryItemsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminRevokeInventoryItems call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementAdminRevokeInventoryItemsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementAdminRevokeInventoryItemsAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementAdminRevokeInventoryItemsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementRevokeInventoryItemsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Decrements the specified virtual currency by the stated amount
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminAddUserVirtualCurrencyAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementAdminSubtractUserVirtualCurrencyGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerItemManagementAdminSubtractUserVirtualCurrencyAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminSubtractUserVirtualCurrency call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementAdminSubtractUserVirtualCurrencyGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementAdminSubtractUserVirtualCurrencyAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementAdminSubtractUserVirtualCurrencyGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementModifyUserVirtualCurrencyResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

/// <summary>
/// Increments the user's balance of the specified virtual currency by the stated amount
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API must be enabled for use as an option in the game manager website. It is disabled by default.
/// See also ClientSubtractUserVirtualCurrencyAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementClientAddUserVirtualCurrencyGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFPlayerItemManagementClientAddUserVirtualCurrencyAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerItemManagementClientAddUserVirtualCurrencyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientAddUserVirtualCurrency call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementClientAddUserVirtualCurrencyGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementClientAddUserVirtualCurrencyAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementClientAddUserVirtualCurrencyGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementModifyUserVirtualCurrencyResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Confirms with the payment provider that the purchase was approved (if applicable) and adjusts inventory
/// and virtual currency balances as appropriate
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// The final step in the purchasing process, this API finalizes the purchase with the payment provider,
/// where applicable, adding virtual goods to the player inventory (including random drop table resolution
/// and recursive addition of bundled items) and adjusting virtual currency balances for funds used or
/// added. Note that this is a pull operation, and should be polled regularly when a purchase is in progress.
/// Please note that the processing time for inventory grants and purchases increases fractionally the
/// more items are in the inventory, and the more items are in the grant/purchase operation. See also
/// ClientPayForPurchaseAsync, ClientStartPurchaseAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementClientConfirmPurchaseGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFPlayerItemManagementClientConfirmPurchaseAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerItemManagementConfirmPurchaseRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientConfirmPurchase call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementClientConfirmPurchaseGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementClientConfirmPurchaseAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementClientConfirmPurchaseGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementConfirmPurchaseResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Consume uses of a consumable item. When all uses are consumed, it will be removed from the player's
/// inventory.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFPlayerItemManagementClientConsumeItemGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayerItemManagementClientConsumeItemAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerItemManagementClientConsumeItemRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientConsumeItem call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementClientConsumeItemGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementClientConsumeItemAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementClientConsumeItemGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementConsumeItemResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the specified character's current inventory of virtual goods
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// All items currently in the character inventory will be returned, irrespective of how they were acquired
/// (via purchasing, grants, coupons, etc.). Items that are expired, fully consumed, or are no longer
/// valid are not considered to be in the user's current inventory, and so will not be not included. Also
/// returns their virtual currency balances. See also ClientGetUserInventoryAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementClientGetCharacterInventoryGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerItemManagementClientGetCharacterInventoryAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerItemManagementClientGetCharacterInventoryRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetCharacterInventory call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementClientGetCharacterInventoryGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementClientGetCharacterInventoryAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementClientGetCharacterInventoryGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementClientGetCharacterInventoryResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// For payments flows where the provider requires playfab (the fulfiller) to initiate the transaction,
/// but the client completes the rest of the flow. In the Xsolla case, the token returned here will be
/// passed to Xsolla by the client to create a cart. Poll GetPurchase using the returned OrderId once
/// you've completed the payment.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientGetPurchaseAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementClientGetPaymentTokenGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFPlayerItemManagementClientGetPaymentTokenAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerItemManagementGetPaymentTokenRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPaymentToken call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementClientGetPaymentTokenGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementClientGetPaymentTokenAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementClientGetPaymentTokenGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementGetPaymentTokenResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves a purchase along with its current PlayFab status. Returns inventory items from the purchase
/// that are still active.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientStartPurchaseAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementClientGetPurchaseGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayerItemManagementClientGetPurchaseAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerItemManagementGetPurchaseRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPurchase call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementClientGetPurchaseGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementClientGetPurchaseAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementClientGetPurchaseGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementGetPurchaseResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the user's current inventory of virtual goods
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientGetCatalogItemsAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementClientGetUserInventoryGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFPlayerItemManagementClientGetUserInventoryAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerItemManagementClientGetUserInventoryRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetUserInventory call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementClientGetUserInventoryGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementClientGetUserInventoryAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementClientGetUserInventoryGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementClientGetUserInventoryResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Selects a payment option for purchase order created via StartPurchase
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This is the second step in the purchasing process, initiating the purchase transaction with the payment
/// provider (if applicable). For payment provider scenarios, the title should next present the user with
/// the payment provider'sinterface for payment. Once the player has completed the payment with the provider,
/// the title should call ConfirmPurchase tofinalize the process and add the appropriate items to the
/// player inventory. See also ClientConfirmPurchaseAsync, ClientStartPurchaseAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementClientPayForPurchaseGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFPlayerItemManagementClientPayForPurchaseAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerItemManagementPayForPurchaseRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientPayForPurchase call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementClientPayForPurchaseGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementClientPayForPurchaseAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementClientPayForPurchaseGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementPayForPurchaseResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Buys a single item with virtual currency. You must specify both the virtual currency to use to purchase,
/// as well as what the client believes the price to be. This lets the server fail the purchase if the
/// price has changed.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Please note that the processing time for inventory grants and purchases increases fractionally the
/// more items are in the inventory, and the more items are in the grant/purchase operation (with each
/// item in a bundle being a distinct add). See also ClientStartPurchaseAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementClientPurchaseItemGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayerItemManagementClientPurchaseItemAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerItemManagementPurchaseItemRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientPurchaseItem call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementClientPurchaseItemGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementClientPurchaseItemAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementClientPurchaseItemGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementPurchaseItemResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Adds the virtual goods associated with the coupon to the user's inventory. Coupons can be generated
/// via the Economy->Catalogs tab in the PlayFab Game Manager.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Coupon codes can be created for any item, or set of items, in the catalog for the title. This operation
/// causes the coupon to be consumed, and the specific items to be awarded to the user. Attempting to
/// re-use an already consumed code, or a code which has not yet been created in the service, will result
/// in an error.
///
/// If successful, call <see cref="PFPlayerItemManagementClientRedeemCouponGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayerItemManagementClientRedeemCouponAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerItemManagementClientRedeemCouponRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientRedeemCoupon call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementClientRedeemCouponGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementClientRedeemCouponAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementClientRedeemCouponGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementRedeemCouponResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Creates an order for a list of items from the title catalog
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This is the first step in the purchasing process. For security purposes, once the order (or 'cart')
/// has been created, additional inventory objects may no longer be added. In addition, inventory objects
/// will be locked to the current prices, regardless of any subsequent changes at the catalog level which
/// may occur during the next two steps. See also ClientConfirmPurchaseAsync, ClientPayForPurchaseAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementClientStartPurchaseGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayerItemManagementClientStartPurchaseAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerItemManagementStartPurchaseRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientStartPurchase call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementClientStartPurchaseGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementClientStartPurchaseAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementClientStartPurchaseGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementStartPurchaseResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Decrements the user's balance of the specified virtual currency by the stated amount. It is possible
/// to make a VC balance negative with this API.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API must be enabled for use as an option in the game manager website. It is disabled by default.
/// See also ClientAddUserVirtualCurrencyAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementClientSubtractUserVirtualCurrencyGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerItemManagementClientSubtractUserVirtualCurrencyAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientSubtractUserVirtualCurrency call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementClientSubtractUserVirtualCurrencyGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementClientSubtractUserVirtualCurrencyAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementClientSubtractUserVirtualCurrencyGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementModifyUserVirtualCurrencyResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Opens the specified container, with the specified key (when required), and returns the contents of
/// the opened container. If the container (and key when relevant) are consumable (RemainingUses > 0),
/// their RemainingUses will be decremented, consistent with the operation of ConsumeItem.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Specify the container and optionally the catalogVersion for the container to open.
///
/// If successful, call <see cref="PFPlayerItemManagementClientUnlockContainerInstanceGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFPlayerItemManagementClientUnlockContainerInstanceAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerItemManagementClientUnlockContainerInstanceRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientUnlockContainerInstance call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementClientUnlockContainerInstanceGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementClientUnlockContainerInstanceAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementClientUnlockContainerInstanceGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementUnlockContainerItemResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Searches target inventory for an ItemInstance matching the given CatalogItemId, if necessary unlocks
/// it using an appropriate key, and returns the contents of the opened container. If the container (and
/// key when relevant) are consumable (RemainingUses > 0), their RemainingUses will be decremented, consistent
/// with the operation of ConsumeItem.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Specify the type of container to open and optionally the catalogVersion for the container to open.
///
/// If successful, call <see cref="PFPlayerItemManagementClientUnlockContainerItemGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerItemManagementClientUnlockContainerItemAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFPlayerItemManagementClientUnlockContainerItemRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientUnlockContainerItem call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementClientUnlockContainerItemGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementClientUnlockContainerItemAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementClientUnlockContainerItemGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementUnlockContainerItemResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Increments the character's balance of the specified virtual currency by the stated amount
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerAddUserVirtualCurrencyAsync, ServerSubtractCharacterVirtualCurrencyAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementServerAddCharacterVirtualCurrencyGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerItemManagementServerAddCharacterVirtualCurrencyAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementAddCharacterVirtualCurrencyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerAddCharacterVirtualCurrency call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerAddCharacterVirtualCurrencyGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerAddCharacterVirtualCurrencyAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementServerAddCharacterVirtualCurrencyGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementModifyCharacterVirtualCurrencyResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Increments the user's balance of the specified virtual currency by the stated amount
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerSubtractUserVirtualCurrencyAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementServerAddUserVirtualCurrencyGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFPlayerItemManagementServerAddUserVirtualCurrencyAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementServerAddUserVirtualCurrencyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerAddUserVirtualCurrency call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerAddUserVirtualCurrencyGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerAddUserVirtualCurrencyAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementServerAddUserVirtualCurrencyGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementModifyUserVirtualCurrencyResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Consume uses of a consumable item. When all uses are consumed, it will be removed from the player's
/// inventory.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFPlayerItemManagementServerConsumeItemGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayerItemManagementServerConsumeItemAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementServerConsumeItemRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerConsumeItem call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerConsumeItemGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerConsumeItemAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementServerConsumeItemGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementConsumeItemResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Returns the result of an evaluation of a Random Result Table - the ItemId from the game Catalog which
/// would have been added to the player inventory, if the Random Result Table were added via a Bundle
/// or a call to UnlockContainer.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFPlayerItemManagementServerEvaluateRandomResultTableGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerItemManagementServerEvaluateRandomResultTableAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementEvaluateRandomResultTableRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerEvaluateRandomResultTable call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerEvaluateRandomResultTableGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerEvaluateRandomResultTableAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementServerEvaluateRandomResultTableGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementEvaluateRandomResultTableResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the specified character's current inventory of virtual goods
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// All items currently in the character inventory will be returned, irrespective of how they were acquired
/// (via purchasing, grants, coupons, etc.). Items that are expired, fully consumed, or are no longer
/// valid are not considered to be in the user's current inventory, and so will not be not included. Also
/// returns their virtual currency balances. See also ServerGetUserInventoryAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementServerGetCharacterInventoryGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerItemManagementServerGetCharacterInventoryAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementServerGetCharacterInventoryRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetCharacterInventory call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerGetCharacterInventoryGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerGetCharacterInventoryAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementServerGetCharacterInventoryGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementServerGetCharacterInventoryResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the configuration information for the specified random results tables for the title, including
/// all ItemId values and weights
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerEvaluateRandomResultTableAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementServerGetRandomResultTablesGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerItemManagementServerGetRandomResultTablesAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementGetRandomResultTablesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetRandomResultTables call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerGetRandomResultTablesGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerGetRandomResultTablesAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementServerGetRandomResultTablesGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFGetRandomResultTablesResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the specified user's current inventory of virtual goods
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// All items currently in the user inventory will be returned, irrespective of how they were acquired
/// (via purchasing, grants, coupons, etc.). Items that are expired, fully consumed, or are no longer
/// valid are not considered to be in the user's current inventory, and so will not be not included. See
/// also ServerGetUserAccountInfoAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementServerGetUserInventoryGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFPlayerItemManagementServerGetUserInventoryAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementServerGetUserInventoryRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetUserInventory call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerGetUserInventoryGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerGetUserInventoryAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementServerGetUserInventoryGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementServerGetUserInventoryResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Adds the specified items to the specified character's inventory
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function directly adds inventory items to the character's inventories. As a result of this operations,
/// the user will not be charged any transaction fee, regardless of the inventory item catalog definition.
/// Please note that the processing time for inventory grants and purchases increases fractionally the
/// more items are in the inventory, and the more items are in the grant/purchase operation.
///
/// If successful, call <see cref="PFPlayerItemManagementServerGrantItemsToCharacterGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerItemManagementServerGrantItemsToCharacterAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementGrantItemsToCharacterRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGrantItemsToCharacter call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerGrantItemsToCharacterGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerGrantItemsToCharacterAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementServerGrantItemsToCharacterGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementGrantItemsToCharacterResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Adds the specified items to the specified user's inventory
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function directly adds inventory items to the user's inventories. As a result of this operations,
/// the user will not be charged any transaction fee, regardless of the inventory item catalog definition.
/// Please note that the processing time for inventory grants and purchases increases fractionally the
/// more items are in the inventory, and the more items are in the grant/purchase operation.
///
/// If successful, call <see cref="PFPlayerItemManagementServerGrantItemsToUserGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFPlayerItemManagementServerGrantItemsToUserAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementGrantItemsToUserRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGrantItemsToUser call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerGrantItemsToUserGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerGrantItemsToUserAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementServerGrantItemsToUserGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementGrantItemsToUserResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Adds the specified items to the specified user inventories
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function directly adds inventory items to user inventories. As a result of this operations,
/// the user will not be charged any transaction fee, regardless of the inventory item catalog definition.
/// Please note that the processing time for inventory grants and purchases increases fractionally the
/// more items are in the inventory, and the more items are in the grant/purchase operation.
///
/// If successful, call <see cref="PFPlayerItemManagementServerGrantItemsToUsersGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFPlayerItemManagementServerGrantItemsToUsersAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementGrantItemsToUsersRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGrantItemsToUsers call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerGrantItemsToUsersGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerGrantItemsToUsersAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementServerGrantItemsToUsersGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementGrantItemsToUsersResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Modifies the number of remaining uses of a player's inventory item
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function can both add and remove uses of an inventory item. If the number of uses drops below
/// zero, the item will be removed from active inventory.
///
/// If successful, call <see cref="PFPlayerItemManagementServerModifyItemUsesGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFPlayerItemManagementServerModifyItemUsesAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementModifyItemUsesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerModifyItemUses call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerModifyItemUsesGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerModifyItemUsesAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementServerModifyItemUsesGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementModifyItemUsesResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Moves an item from a character's inventory into another of the users's character's inventory.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Transfers an item from a character to another character that is owned by the same user. This will
/// remove the item from the character's inventory (until and unless it is moved back), and will enable
/// the other character to make use of the item instead. See also ServerGrantItemsToCharacterAsync, ServerMoveItemToCharacterFromUserAsync,
/// ServerMoveItemToUserFromCharacterAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFPlayerItemManagementServerMoveItemToCharacterFromCharacterAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementMoveItemToCharacterFromCharacterRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Moves an item from a user's inventory into their character's inventory.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Transfers an item from a user to a character she owns. This will remove the item from the user's
/// inventory (until and unless it is moved back), and will enable the character to make use of the item
/// instead. See also ServerGrantItemsToCharacterAsync, ServerMoveItemToUserFromCharacterAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFPlayerItemManagementServerMoveItemToCharacterFromUserAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementMoveItemToCharacterFromUserRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Moves an item from a character's inventory into the owning user's inventory.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Transfers an item from a character to the owning user. This will remove the item from the character's
/// inventory (until and unless it is moved back), and will enable the user to make use of the item instead.
/// See also ServerGrantItemsToCharacterAsync, ServerMoveItemToCharacterFromUserAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFPlayerItemManagementServerMoveItemToUserFromCharacterAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementMoveItemToUserFromCharacterRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Adds the virtual goods associated with the coupon to the user's inventory. Coupons can be generated
/// via the Economy->Catalogs tab in the PlayFab Game Manager.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Coupon codes can be created for any item, or set of items, in the catalog for the title. This operation
/// causes the coupon to be consumed, and the specific items to be awarded to the user. Attempting to
/// re-use an already consumed code, or a code which has not yet been created in the service, will result
/// in an error.
///
/// If successful, call <see cref="PFPlayerItemManagementServerRedeemCouponGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayerItemManagementServerRedeemCouponAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementServerRedeemCouponRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerRedeemCoupon call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerRedeemCouponGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerRedeemCouponAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementServerRedeemCouponGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementRedeemCouponResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Submit a report about a player (due to bad bahavior, etc.) on behalf of another player, so that customer
/// service representatives for the title can take action concerning potentially toxic players.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFPlayerItemManagementServerReportPlayerGetResult"/> to get the result.
/// </remarks>
HRESULT PFPlayerItemManagementServerReportPlayerAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementReportPlayerServerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerReportPlayerAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFPlayerItemManagementReportPlayerServerResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerReportPlayerGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFPlayerItemManagementReportPlayerServerResult* result
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Revokes access to an item in a user's inventory
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// In cases where the inventory item in question is a 'crate', and the items it contained have already
/// been dispensed, this will not revoke access or otherwise remove the items which were dispensed. See
/// also ServerGetUserInventoryAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFPlayerItemManagementServerRevokeInventoryItemAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementRevokeInventoryItemRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Revokes access for up to 25 items across multiple users and characters.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// In cases where the inventory item in question is a 'crate', and the items it contained have already
/// been dispensed, this will not revoke access or otherwise remove the items which were dispensed. See
/// also ServerGetUserInventoryAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementServerRevokeInventoryItemsGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerItemManagementServerRevokeInventoryItemsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementRevokeInventoryItemsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerRevokeInventoryItems call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerRevokeInventoryItemsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerRevokeInventoryItemsAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementServerRevokeInventoryItemsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementRevokeInventoryItemsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Decrements the character's balance of the specified virtual currency by the stated amount. It is
/// possible to make a VC balance negative with this API.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerAddCharacterVirtualCurrencyAsync, ServerSubtractUserVirtualCurrencyAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementServerSubtractCharacterVirtualCurrencyGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerItemManagementServerSubtractCharacterVirtualCurrencyAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerSubtractCharacterVirtualCurrency call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerSubtractCharacterVirtualCurrencyGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerSubtractCharacterVirtualCurrencyAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementServerSubtractCharacterVirtualCurrencyGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementModifyCharacterVirtualCurrencyResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Decrements the user's balance of the specified virtual currency by the stated amount. It is possible
/// to make a VC balance negative with this API.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ServerAddUserVirtualCurrencyAsync.
///
/// If successful, call <see cref="PFPlayerItemManagementServerSubtractUserVirtualCurrencyGetResult"/>
/// to get the result.
/// </remarks>
HRESULT PFPlayerItemManagementServerSubtractUserVirtualCurrencyAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerSubtractUserVirtualCurrency call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerSubtractUserVirtualCurrencyGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerSubtractUserVirtualCurrencyAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementServerSubtractUserVirtualCurrencyGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementModifyUserVirtualCurrencyResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Opens a specific container (ContainerItemInstanceId), with a specific key (KeyItemInstanceId, when
/// required), and returns the contents of the opened container. If the container (and key when relevant)
/// are consumable (RemainingUses > 0), their RemainingUses will be decremented, consistent with the operation
/// of ConsumeItem.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Specify the container and optionally the catalogVersion for the container to open.
///
/// If successful, call <see cref="PFPlayerItemManagementServerUnlockContainerInstanceGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFPlayerItemManagementServerUnlockContainerInstanceAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementServerUnlockContainerInstanceRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerUnlockContainerInstance call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerUnlockContainerInstanceGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerUnlockContainerInstanceAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementServerUnlockContainerInstanceGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementUnlockContainerItemResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Searches Player or Character inventory for any ItemInstance matching the given CatalogItemId, if
/// necessary unlocks it using any appropriate key, and returns the contents of the opened container.
/// If the container (and key when relevant) are consumable (RemainingUses > 0), their RemainingUses will
/// be decremented, consistent with the operation of ConsumeItem.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Specify the type of container to open and optionally the catalogVersion for the container to open.
///
/// If successful, call <see cref="PFPlayerItemManagementServerUnlockContainerItemGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFPlayerItemManagementServerUnlockContainerItemAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementServerUnlockContainerItemRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerUnlockContainerItem call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFPlayerItemManagementServerUnlockContainerItemGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFPlayerItemManagementServerUnlockContainerItemAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The size of the buffer for the result object.</param>
/// <param name="buffer">Byte buffer used for the result value and its fields.</param>
/// <param name="result">Pointer to the result object.</param>
/// <param name="bufferUsed">The number of bytes in the provided buffer that were used.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// result is a pointer within buffer and does not need to be freed separately.
/// </remarks>
HRESULT PFPlayerItemManagementServerUnlockContainerItemGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFPlayerItemManagementUnlockContainerItemResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the key-value pair data tagged to the specified item, which is read-only from the client.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This function performs an additive update of the arbitrary JSON object containing the custom data
/// for the item instance which belongs to the specified user. In updating the custom data object, keys
/// which already exist in the object will have their values overwritten, while keys with null values
/// will be removed. No other key-value pairs will be changed apart from those specified in the call.
/// See also ServerGetUserInventoryAsync, ServerUpdateUserInternalDataAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFPlayerItemManagementServerUpdateUserInventoryItemCustomDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFPlayerItemManagementUpdateUserInventoryItemDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif


}