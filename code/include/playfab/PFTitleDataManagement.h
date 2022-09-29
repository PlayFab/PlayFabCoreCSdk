// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFTitleDataManagementDataModels.h>
#include <playfab/PFGlobal.h>
#include <playfab/PFTitlePlayer.h>

extern "C"
{

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Update news item to include localized version
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFTitleDataManagementAdminAddLocalizedNewsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementAddLocalizedNewsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Adds a new news item to the title's news feed
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFTitleDataManagementAdminAddNewsGetResult"/> to get the result.
/// </remarks>
HRESULT PFTitleDataManagementAdminAddNewsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementAddNewsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminAddNews call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementAdminAddNewsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementAdminAddNewsAsync call.
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
HRESULT PFTitleDataManagementAdminAddNewsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementAddNewsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Adds one or more virtual currencies to the set defined for the title. Virtual Currencies have a maximum
/// value of 2,147,483,647 when granted to a player. Any value over that will be discarded.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This operation is additive. Any new currencies defined in the array will be added to the set of those
/// available for the title, while any CurrencyCode identifiers matching existing ones in the game will
/// be overwritten with the new values. See also AdminListVirtualCurrencyTypesAsync, AdminRemoveVirtualCurrencyTypesAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFTitleDataManagementAdminAddVirtualCurrencyTypesAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementAddVirtualCurrencyTypesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Deletes an existing virtual item store
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This non-reversible operation will permanently delete the requested store. See also AdminGetStoreItemsAsync,
/// AdminSetStoreItemsAsync, AdminUpdateStoreItemsAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFTitleDataManagementAdminDeleteStoreAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementDeleteStoreRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Deletes a specified set of title data overrides.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API method is designed to delete specified title data overrides associated with the given label.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFTitleDataManagementAdminDeleteTitleDataOverrideAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementDeleteTitleDataOverrideRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the specified version of the title's catalog of virtual goods, including all defined properties
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminSetCatalogItemsAsync, AdminUpdateCatalogItemsAsync.
///
/// If successful, call <see cref="PFTitleDataManagementAdminGetCatalogItemsGetResult"/> to get the result.
/// </remarks>
HRESULT PFTitleDataManagementAdminGetCatalogItemsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementGetCatalogItemsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetCatalogItems call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementAdminGetCatalogItemsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementAdminGetCatalogItemsAsync call.
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
HRESULT PFTitleDataManagementAdminGetCatalogItemsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementGetCatalogItemsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the key-value store of custom publisher settings
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API is designed to return publisher-specific values which can be read, but not written to, by
/// the client. This data is shared across all titles assigned to a particular publisher, and can be used
/// for cross-game coordination. Only titles assigned to a publisher can use this API. For more information
/// email helloplayfab@microsoft.com. This AdminAPI call for getting title data guarantees no delay in
/// between update and retrieval of newly set data. See also AdminSetPublisherDataAsync.
///
/// If successful, call <see cref="PFTitleDataManagementAdminGetPublisherDataGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFTitleDataManagementAdminGetPublisherDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementGetPublisherDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetPublisherData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementAdminGetPublisherDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementAdminGetPublisherDataAsync call.
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
HRESULT PFTitleDataManagementAdminGetPublisherDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementGetPublisherDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the random drop table configuration for the title
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminUpdateRandomResultTablesAsync.
///
/// If successful, call <see cref="PFTitleDataManagementAdminGetRandomResultTablesGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFTitleDataManagementAdminGetRandomResultTablesAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementGetRandomResultTablesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetRandomResultTables call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementAdminGetRandomResultTablesGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementAdminGetRandomResultTablesAsync call.
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
HRESULT PFTitleDataManagementAdminGetRandomResultTablesGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFGetRandomResultTablesResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the set of items defined for the specified store, including all prices defined
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// A store contains an array of references to items defined in the catalog, along with the prices for
/// the item, in both real world and virtual currencies. These prices act as an override to any prices
/// defined in the catalog. In this way, the base definitions of the items may be defined in the catalog,
/// with all associated properties, while the pricing can be set for each store, as needed. This allows
/// for subsets of goods to be defined for different purposes (in order to simplify showing some, but
/// not all catalog items to users, based upon different characteristics), along with unique prices. Note
/// that all prices defined in the catalog and store definitions for the item are considered valid, and
/// that a compromised client can be made to send a request for an item based upon any of these definitions.
/// If no price is specified in the store for an item, the price set in the catalog should be displayed
/// to the user. See also AdminDeleteStoreAsync, AdminSetStoreItemsAsync, AdminUpdateStoreItemsAsync.
///
/// If successful, call <see cref="PFTitleDataManagementAdminGetStoreItemsGetResult"/> to get the result.
/// </remarks>
HRESULT PFTitleDataManagementAdminGetStoreItemsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementGetStoreItemsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetStoreItems call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementAdminGetStoreItemsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementAdminGetStoreItemsAsync call.
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
HRESULT PFTitleDataManagementAdminGetStoreItemsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementGetStoreItemsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the key-value store of custom title settings which can be read by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API method is designed to return title specific values which can be read by the client. For
/// example, a developer could choose to store values which modify the user experience, such as enemy
/// spawn rates, weapon strengths, movement speeds, etc. This allows a developer to update the title without
/// the need to create, test, and ship a new build. If an override label is specified in the request,
/// the overrides are applied automatically and returned with the title data. Note that due to caching,
/// there may up to a minute delay in between updating title data and a query returning the newest value.
/// See also AdminSetTitleDataAsync.
///
/// If successful, call <see cref="PFTitleDataManagementAdminGetTitleDataGetResult"/> to get the result.
/// </remarks>
HRESULT PFTitleDataManagementAdminGetTitleDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementGetTitleDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetTitleData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementAdminGetTitleDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementAdminGetTitleDataAsync call.
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
HRESULT PFTitleDataManagementAdminGetTitleDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementGetTitleDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the key-value store of custom title settings which cannot be read by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API method is designed to return title specific values which are accessible only by the server.
/// These values can be used to tweak settings used by game servers and Cloud Scripts without the need
/// to update and re-deploy. Note that due to caching, there may up to a minute delay in between updating
/// title data and this query returning the newest value. See also AdminSetTitleInternalDataAsync.
///
/// If successful, call <see cref="PFTitleDataManagementAdminGetTitleInternalDataGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFTitleDataManagementAdminGetTitleInternalDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementGetTitleDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetTitleInternalData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementAdminGetTitleInternalDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementAdminGetTitleInternalDataAsync call.
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
HRESULT PFTitleDataManagementAdminGetTitleInternalDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementGetTitleDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retuns the list of all defined virtual currencies for the title
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminAddVirtualCurrencyTypesAsync, AdminRemoveVirtualCurrencyTypesAsync.
///
/// If successful, call <see cref="PFTitleDataManagementAdminListVirtualCurrencyTypesGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFTitleDataManagementAdminListVirtualCurrencyTypesAsync(
    _In_ PFStateHandle stateHandle,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminListVirtualCurrencyTypes call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementAdminListVirtualCurrencyTypesGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementAdminListVirtualCurrencyTypesAsync call.
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
HRESULT PFTitleDataManagementAdminListVirtualCurrencyTypesGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementListVirtualCurrencyTypesResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Removes one or more virtual currencies from the set defined for the title.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Virtual currencies to be removed cannot have entries in any catalog nor store for the title. Note
/// that this operation will not remove player balances for the removed currencies; if a deleted currency
/// is recreated at any point, user balances will be in an undefined state. See also AdminAddVirtualCurrencyTypesAsync,
/// AdminListVirtualCurrencyTypesAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFTitleDataManagementAdminRemoveVirtualCurrencyTypesAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementRemoveVirtualCurrencyTypesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Creates the catalog configuration of all virtual goods for the specified catalog version
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// When used for SetCatalogItems, this operation is not additive. Using it will cause the indicated
/// catalog version to be created from scratch. If there is an existing catalog with the version number
/// in question, it will be deleted and replaced with only the items specified in this call. When used
/// for UpdateCatalogItems, this operation is additive. Items with ItemId values not currently in the
/// catalog will be added, while those with ItemId values matching items currently in the catalog will
/// overwrite those items with the given values. See also AdminGetCatalogItemsAsync, AdminUpdateCatalogItemsAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFTitleDataManagementAdminSetCatalogItemsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementUpdateCatalogItemsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the key-value store of custom publisher settings
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API is designed to store publisher-specific values which can be read, but not written to, by
/// the client. This data is shared across all titles assigned to a particular publisher, and can be used
/// for cross-game coordination. Only titles assigned to a publisher can use this API. This operation
/// is additive. If a Key does not exist in the current dataset, it will be added with the specified Value.
/// If it already exists, the Value for that key will be overwritten with the new Value. For more information
/// email helloplayfab@microsoft.com See also AdminGetPublisherDataAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFTitleDataManagementAdminSetPublisherDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementSetPublisherDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Sets all the items in one virtual store
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// When used for SetStoreItems, this operation is not additive. Using it will cause the indicated virtual
/// store to be created from scratch. If there is an existing store with the same storeId, it will be
/// deleted and replaced with only the items specified in this call. When used for UpdateStoreItems, this
/// operation is additive. Items with ItemId values not currently in the store will be added, while those
/// with ItemId values matching items currently in the catalog will overwrite those items with the given
/// values. In both cases, a store contains an array of references to items defined in the catalog, along
/// with the prices for the item, in both real world and virtual currencies. These prices act as an override
/// to any prices defined in the catalog. In this way, the base definitions of the items may be defined
/// in the catalog, with all associated properties, while the pricing can be set for each store, as needed.
/// This allows for subsets of goods to be defined for different purposes (in order to simplify showing
/// some, but not all catalog items to users, based upon different characteristics), along with unique
/// prices. Note that all prices defined in the catalog and store definitions for the item are considered
/// valid, and that a compromised client can be made to send a request for an item based upon any of these
/// definitions. If no price is specified in the store for an item, the price set in the catalog should
/// be displayed to the user. See also AdminDeleteStoreAsync, AdminGetStoreItemsAsync, AdminUpdateStoreItemsAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFTitleDataManagementAdminSetStoreItemsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementUpdateStoreItemsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Creates and updates the key-value store of custom title settings which can be read by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API method is designed to store title specific values which can be read by the client. For example,
/// a developer could choose to store values which modify the user experience, such as enemy spawn rates,
/// weapon strengths, movement speeds, etc. This allows a developer to update the title without the need
/// to create, test, and ship a new build. This operation is additive. If a Key does not exist in the
/// current dataset, it will be added with the specified Value. If it already exists, the Value for that
/// key will be overwritten with the new Value. See also AdminGetTitleDataAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFTitleDataManagementAdminSetTitleDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementSetTitleDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Set and delete key-value pairs in a title data override instance.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API method is designed to set and delete key-value pairs in a title data override instance.
/// If the key exists and the new value is empty, the method will delete the key; otherwise, the method
/// will update the current value with the new value. Keys are trimmed and cannot start with '!'. See
/// also AdminGetTitleDataAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFTitleDataManagementAdminSetTitleDataAndOverridesAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementSetTitleDataAndOverridesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the key-value store of custom title settings which cannot be read by the client
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API method is designed to store title specific values which are accessible only by the server.
/// These values can be used to tweak settings used by game servers and Cloud Scripts without the need
/// to update and re-deploy. This operation is additive. If a Key does not exist in the current dataset,
/// it will be added with the specified Value. If it already exists, the Value for that key will be overwritten
/// with the new Value. See also AdminGetTitleInternalDataAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFTitleDataManagementAdminSetTitleInternalDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementSetTitleDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Sets the Amazon Resource Name (ARN) for iOS and Android push notifications. Documentation on the
/// exact restrictions can be found at: http://docs.aws.amazon.com/sns/latest/api/API_CreatePlatformApplication.html.
/// Currently, Amazon device Messaging is not supported.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// When using the Apple Push Notification service (APNS) or the development version (APNS_SANDBOX),
/// the APNS Private Key should be used as the Credential in this call. With Google Cloud Messaging (GCM),
/// the Android API Key should be used. The current ARN (if one exists) can be overwritten by setting
/// the OverwriteOldARN boolean to true.
///
/// If successful, call <see cref="PFTitleDataManagementAdminSetupPushNotificationGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFTitleDataManagementAdminSetupPushNotificationAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementSetupPushNotificationRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminSetupPushNotification call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementAdminSetupPushNotificationGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementAdminSetupPushNotificationAsync call.
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
HRESULT PFTitleDataManagementAdminSetupPushNotificationGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementSetupPushNotificationResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the catalog configuration for virtual goods in the specified catalog version
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// When used for SetCatalogItems, this operation is not additive. Using it will cause the indicated
/// catalog version to be created from scratch. If there is an existing catalog with the version number
/// in question, it will be deleted and replaced with only the items specified in this call. When used
/// for UpdateCatalogItems, this operation is additive. Items with ItemId values not currently in the
/// catalog will be added, while those with ItemId values matching items currently in the catalog will
/// overwrite those items with the given values. See also AdminGetCatalogItemsAsync, AdminSetCatalogItemsAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFTitleDataManagementAdminUpdateCatalogItemsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementUpdateCatalogItemsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the random drop table configuration for the title
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This operation is additive. Tables with TableId values not currently defined will be added, while
/// those with TableId values matching Tables currently in the catalog will be overwritten with the given
/// values. See also AdminGetRandomResultTablesAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFTitleDataManagementAdminUpdateRandomResultTablesAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementUpdateRandomResultTablesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates an existing virtual item store with new or modified items
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// When used for SetStoreItems, this operation is not additive. Using it will cause the indicated virtual
/// store to be created from scratch. If there is an existing store with the same storeId, it will be
/// deleted and replaced with only the items specified in this call. When used for UpdateStoreItems, this
/// operation is additive. Items with ItemId values not currently in the store will be added, while those
/// with ItemId values matching items currently in the catalog will overwrite those items with the given
/// values. In both cases, a store contains an array of references to items defined in the catalog, along
/// with the prices for the item, in both real world and virtual currencies. These prices act as an override
/// to any prices defined in the catalog. In this way, the base definitions of the items may be defined
/// in the catalog, with all associated properties, while the pricing can be set for each store, as needed.
/// This allows for subsets of goods to be defined for different purposes (in order to simplify showing
/// some, but not all catalog items to users, based upon different characteristics), along with unique
/// prices. Note that all prices defined in the catalog and store definitions for the item are considered
/// valid, and that a compromised client can be made to send a request for an item based upon any of these
/// definitions. If no price is specified in the store for an item, the price set in the catalog should
/// be displayed to the user. See also AdminDeleteStoreAsync, AdminGetStoreItemsAsync, AdminSetStoreItemsAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFTitleDataManagementAdminUpdateStoreItemsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementUpdateStoreItemsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

/// <summary>
/// Retrieves the specified version of the title's catalog of virtual goods, including all defined properties
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientGetStoreItemsAsync, ClientGetUserInventoryAsync.
///
/// If successful, call <see cref="PFTitleDataManagementClientGetCatalogItemsGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFTitleDataManagementClientGetCatalogItemsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFTitleDataManagementGetCatalogItemsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetCatalogItems call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementClientGetCatalogItemsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementClientGetCatalogItemsAsync call.
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
HRESULT PFTitleDataManagementClientGetCatalogItemsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementGetCatalogItemsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the key-value store of custom publisher settings
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API is designed to return publisher-specific values which can be read, but not written to, by
/// the client. This data is shared across all titles assigned to a particular publisher, and can be used
/// for cross-game coordination. Only titles assigned to a publisher can use this API. For more information
/// email helloplayfab@microsoft.com. Note that there may up to a minute delay in between updating title
/// data and this API call returning the newest value.
///
/// If successful, call <see cref="PFTitleDataManagementClientGetPublisherDataGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFTitleDataManagementClientGetPublisherDataAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFTitleDataManagementGetPublisherDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPublisherData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementClientGetPublisherDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementClientGetPublisherDataAsync call.
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
HRESULT PFTitleDataManagementClientGetPublisherDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementGetPublisherDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the set of items defined for the specified store, including all prices defined
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// A store contains an array of references to items defined in one or more catalog versions of the game,
/// along with the prices for the item, in both real world and virtual currencies. These prices act as
/// an override to any prices defined in the catalog. In this way, the base definitions of the items may
/// be defined in the catalog, with all associated properties, while the pricing can be set for each store,
/// as needed. This allows for subsets of goods to be defined for different purposes (in order to simplify
/// showing some, but not all catalog items to users, based upon different characteristics), along with
/// unique prices. Note that all prices defined in the catalog and store definitions for the item are
/// considered valid, and that a compromised client can be made to send a request for an item based upon
/// any of these definitions. If no price is specified in the store for an item, the price set in the
/// catalog should be displayed to the user. See also ClientGetCatalogItemsAsync.
///
/// If successful, call <see cref="PFTitleDataManagementClientGetStoreItemsGetResult"/> to get the result.
/// </remarks>
HRESULT PFTitleDataManagementClientGetStoreItemsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFTitleDataManagementGetStoreItemsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetStoreItems call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementClientGetStoreItemsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementClientGetStoreItemsAsync call.
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
HRESULT PFTitleDataManagementClientGetStoreItemsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementGetStoreItemsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the current server time
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This query retrieves the current time from one of the servers in PlayFab. Please note that due to
/// clock drift between servers, there is a potential variance of up to 5 seconds.
///
/// If successful, call <see cref="PFTitleDataManagementClientGetTimeGetResult"/> to get the result.
/// </remarks>
HRESULT PFTitleDataManagementClientGetTimeAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementClientGetTimeAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFTitleDataManagementGetTimeResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementClientGetTimeGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFTitleDataManagementGetTimeResult* result
) noexcept;

/// <summary>
/// Retrieves the key-value store of custom title settings
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API is designed to return title specific values which can be read, but not written to, by the
/// client. For example, a developer could choose to store values which modify the user experience, such
/// as enemy spawn rates, weapon strengths, movement speeds, etc. This allows a developer to update the
/// title without the need to create, test, and ship a new build. If the player belongs to an experiment
/// variant that uses title data overrides, the overrides are applied automatically and returned with
/// the title data. Note that there may up to a minute delay in between updating title data and this API
/// call returning the newest value.
///
/// If successful, call <see cref="PFTitleDataManagementClientGetTitleDataGetResult"/> to get the result.
/// </remarks>
HRESULT PFTitleDataManagementClientGetTitleDataAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFTitleDataManagementGetTitleDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetTitleData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementClientGetTitleDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementClientGetTitleDataAsync call.
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
HRESULT PFTitleDataManagementClientGetTitleDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementGetTitleDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves the title news feed, as configured in the developer portal
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFTitleDataManagementClientGetTitleNewsGetResult"/> to get the result.
/// </remarks>
HRESULT PFTitleDataManagementClientGetTitleNewsAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFTitleDataManagementGetTitleNewsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetTitleNews call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementClientGetTitleNewsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementClientGetTitleNewsAsync call.
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
HRESULT PFTitleDataManagementClientGetTitleNewsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementGetTitleNewsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the specified version of the title's catalog of virtual goods, including all defined properties
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFTitleDataManagementServerGetCatalogItemsGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFTitleDataManagementServerGetCatalogItemsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementGetCatalogItemsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetCatalogItems call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementServerGetCatalogItemsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementServerGetCatalogItemsAsync call.
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
HRESULT PFTitleDataManagementServerGetCatalogItemsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementGetCatalogItemsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the key-value store of custom publisher settings
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API is designed to return publisher-specific values which can be read, but not written to, by
/// the client. This data is shared across all titles assigned to a particular publisher, and can be used
/// for cross-game coordination. Only titles assigned to a publisher can use this API. For more information
/// email helloplayfab@microsoft.com. Note that there may up to a minute delay in between updating title
/// data and this API call returning the newest value.
///
/// If successful, call <see cref="PFTitleDataManagementServerGetPublisherDataGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFTitleDataManagementServerGetPublisherDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementGetPublisherDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetPublisherData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementServerGetPublisherDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementServerGetPublisherDataAsync call.
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
HRESULT PFTitleDataManagementServerGetPublisherDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementGetPublisherDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the set of items defined for the specified store, including all prices defined, for the
/// specified player
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// A store contains an array of references to items defined in one or more catalog versions of the game,
/// along with the prices for the item, in both real world and virtual currencies. These prices act as
/// an override to any prices defined in the catalog. In this way, the base definitions of the items may
/// be defined in the catalog, with all associated properties, while the pricing can be set for each store,
/// as needed. This allows for subsets of goods to be defined for different purposes (in order to simplify
/// showing some, but not all catalog items to users, based upon different characteristics), along with
/// unique prices. Note that all prices defined in the catalog and store definitions for the item are
/// considered valid, and that a compromised client can be made to send a request for an item based upon
/// any of these definitions. If no price is specified in the store for an item, the price set in the
/// catalog should be displayed to the user.
///
/// If successful, call <see cref="PFTitleDataManagementServerGetStoreItemsGetResult"/> to get the result.
/// </remarks>
HRESULT PFTitleDataManagementServerGetStoreItemsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementGetStoreItemsServerRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetStoreItems call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementServerGetStoreItemsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementServerGetStoreItemsAsync call.
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
HRESULT PFTitleDataManagementServerGetStoreItemsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementGetStoreItemsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the current server time
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This query retrieves the current time from one of the servers in PlayFab. Please note that due to
/// clock drift between servers, there is a potential variance of up to 5 seconds.
///
/// If successful, call <see cref="PFTitleDataManagementServerGetTimeGetResult"/> to get the result.
/// </remarks>
HRESULT PFTitleDataManagementServerGetTimeAsync(
    _In_ PFStateHandle stateHandle,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementServerGetTimeAsync call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="result">PFTitleDataManagementGetTimeResult object that will be populated with the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementServerGetTimeGetResult(
    _Inout_ XAsyncBlock* async,
    _Out_ PFTitleDataManagementGetTimeResult* result
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the key-value store of custom title settings
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API is designed to return title specific values which can be read, but not written to, by the
/// client. For example, a developer could choose to store values which modify the user experience, such
/// as enemy spawn rates, weapon strengths, movement speeds, etc. This allows a developer to update the
/// title without the need to create, test, and ship a new build. If an override label is specified in
/// the request, the overrides are applied automatically and returned with the title data. Note that there
/// may up to a minute delay in between updating title data and this API call returning the newest value.
///
/// If successful, call <see cref="PFTitleDataManagementServerGetTitleDataGetResult"/> to get the result.
/// </remarks>
HRESULT PFTitleDataManagementServerGetTitleDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementGetTitleDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetTitleData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementServerGetTitleDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementServerGetTitleDataAsync call.
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
HRESULT PFTitleDataManagementServerGetTitleDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementGetTitleDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the key-value store of custom internal title settings
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API is designed to return title specific values which are accessible only to the server. This
/// can be used to tweak settings on game servers and Cloud Scripts without needed to update and re-deploy
/// them. Note that there may up to a minute delay in between updating title data and this API call returning
/// the newest value.
///
/// If successful, call <see cref="PFTitleDataManagementServerGetTitleInternalDataGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFTitleDataManagementServerGetTitleInternalDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementGetTitleDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetTitleInternalData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementServerGetTitleInternalDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementServerGetTitleInternalDataAsync call.
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
HRESULT PFTitleDataManagementServerGetTitleInternalDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementGetTitleDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves the title news feed, as configured in the developer portal
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFTitleDataManagementServerGetTitleNewsGetResult"/> to get the result.
/// </remarks>
HRESULT PFTitleDataManagementServerGetTitleNewsAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementGetTitleNewsRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetTitleNews call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFTitleDataManagementServerGetTitleNewsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFTitleDataManagementServerGetTitleNewsAsync call.
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
HRESULT PFTitleDataManagementServerGetTitleNewsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFTitleDataManagementGetTitleNewsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the key-value store of custom publisher settings
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API is designed to store publisher-specific values which can be read, but not written to, by
/// the client. This data is shared across all titles assigned to a particular publisher, and can be used
/// for cross-game coordination. Only titles assigned to a publisher can use this API. This operation
/// is additive. If a Key does not exist in the current dataset, it will be added with the specified Value.
/// If it already exists, the Value for that key will be overwritten with the new Value. For more information
/// email helloplayfab@microsoft.com.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFTitleDataManagementServerSetPublisherDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementSetPublisherDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the key-value store of custom title settings
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API is designed to store title specific values which can be read, but not written to, by the
/// client. For example, a developer could choose to store values which modify the user experience, such
/// as enemy spawn rates, weapon strengths, movement speeds, etc. This allows a developer to update the
/// title without the need to create, test, and ship a new build. This operation is additive. If a Key
/// does not exist in the current dataset, it will be added with the specified Value. If it already exists,
/// the Value for that key will be overwritten with the new Value.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFTitleDataManagementServerSetTitleDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementSetTitleDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates the key-value store of custom title settings
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// This API is designed to store title specific values which are accessible only to the server. This
/// can be used to tweak settings on game servers and Cloud Scripts without needed to update and re-deploy
/// them. This operation is additive. If a Key does not exist in the current dataset, it will be added
/// with the specified Value. If it already exists, the Value for that key will be overwritten with the
/// new Value.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFTitleDataManagementServerSetTitleInternalDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFTitleDataManagementSetTitleDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif


}