// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFSharedGroupsDataModels.h>
#include <playfab/PFGlobal.h>
#include <playfab/PFTitlePlayer.h>

extern "C"
{

/// <summary>
/// Adds users to the set of those able to update both the shared data, as well as the set of users in
/// the group. Only users in the group can add new members. Shared Groups are designed for sharing data
/// between a very small number of players, please see our guide: https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFSharedGroupsClientAddSharedGroupMembersAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFSharedGroupsAddSharedGroupMembersRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Requests the creation of a shared group object, containing key/value pairs which may be updated by
/// all members of the group. Upon creation, the current user will be the only member of the group. Shared
/// Groups are designed for sharing data between a very small number of players, please see our guide:
/// https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If SharedGroupId is specified, the service will attempt to create a group with that identifier, and
/// will return an error if it is already in use. If no SharedGroupId is specified, a random identifier
/// will be assigned.
///
/// If successful, call <see cref="PFSharedGroupsClientCreateSharedGroupGetResult"/> to get the result.
/// </remarks>
HRESULT PFSharedGroupsClientCreateSharedGroupAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFSharedGroupsCreateSharedGroupRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientCreateSharedGroup call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFSharedGroupsClientCreateSharedGroupGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFSharedGroupsClientCreateSharedGroupAsync call.
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
HRESULT PFSharedGroupsClientCreateSharedGroupGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFSharedGroupsCreateSharedGroupResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Retrieves data stored in a shared group object, as well as the list of members in the group. Non-members
/// of the group may use this to retrieve group data, including membership, but they will not receive
/// data for keys marked as private. Shared Groups are designed for sharing data between a very small
/// number of players, please see our guide: https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFSharedGroupsClientGetSharedGroupDataGetResult"/> to get the result.
/// </remarks>
HRESULT PFSharedGroupsClientGetSharedGroupDataAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFSharedGroupsGetSharedGroupDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetSharedGroupData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFSharedGroupsClientGetSharedGroupDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFSharedGroupsClientGetSharedGroupDataAsync call.
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
HRESULT PFSharedGroupsClientGetSharedGroupDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFSharedGroupsGetSharedGroupDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Removes users from the set of those able to update the shared data and the set of users in the group.
/// Only users in the group can remove members. If as a result of the call, zero users remain with access,
/// the group and its associated data will be deleted. Shared Groups are designed for sharing data between
/// a very small number of players, please see our guide: https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFSharedGroupsClientRemoveSharedGroupMembersAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFSharedGroupsRemoveSharedGroupMembersRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Adds, updates, and removes data keys for a shared group object. If the permission is set to Public,
/// all fields updated or added in this call will be readable by users not in the group. By default, data
/// permissions are set to Private. Regardless of the permission setting, only members of the group can
/// update the data. Shared Groups are designed for sharing data between a very small number of players,
/// please see our guide: https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Note that in the case of multiple calls to write to the same shared group data keys, the last write
/// received by the PlayFab service will determine the value available to subsequent read operations.
/// For scenarios requiring coordination of data updates, it is recommended that titles make use of user
/// data with read permission set to public, or a combination of user data and shared group data.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFSharedGroupsClientUpdateSharedGroupDataAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFSharedGroupsUpdateSharedGroupDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Adds users to the set of those able to update both the shared data, as well as the set of users in
/// the group. Only users in the group (and the server) can add new members. Shared Groups are designed
/// for sharing data between a very small number of players, please see our guide: https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFSharedGroupsServerAddSharedGroupMembersAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFSharedGroupsAddSharedGroupMembersRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Requests the creation of a shared group object, containing key/value pairs which may be updated by
/// all members of the group. When created by a server, the group will initially have no members. Shared
/// Groups are designed for sharing data between a very small number of players, please see our guide:
/// https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If SharedGroupId is specified, the service will attempt to create a group with that identifier, and
/// will return an error if it is already in use. If no SharedGroupId is specified, a random identifier
/// will be assigned.
///
/// If successful, call <see cref="PFSharedGroupsServerCreateSharedGroupGetResult"/> to get the result.
/// </remarks>
HRESULT PFSharedGroupsServerCreateSharedGroupAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFSharedGroupsCreateSharedGroupRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerCreateSharedGroup call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFSharedGroupsServerCreateSharedGroupGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFSharedGroupsServerCreateSharedGroupAsync call.
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
HRESULT PFSharedGroupsServerCreateSharedGroupGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFSharedGroupsCreateSharedGroupResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Deletes a shared group, freeing up the shared group ID to be reused for a new group. Shared Groups
/// are designed for sharing data between a very small number of players, please see our guide: https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFSharedGroupsServerDeleteSharedGroupAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFSharedGroupsDeleteSharedGroupRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Retrieves data stored in a shared group object, as well as the list of members in the group. The
/// server can access all public and private group data. Shared Groups are designed for sharing data between
/// a very small number of players, please see our guide: https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFSharedGroupsServerGetSharedGroupDataGetResult"/> to get the result.
/// </remarks>
HRESULT PFSharedGroupsServerGetSharedGroupDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFSharedGroupsGetSharedGroupDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerGetSharedGroupData call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFSharedGroupsServerGetSharedGroupDataGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFSharedGroupsServerGetSharedGroupDataAsync call.
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
HRESULT PFSharedGroupsServerGetSharedGroupDataGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFSharedGroupsGetSharedGroupDataResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Removes users from the set of those able to update the shared data and the set of users in the group.
/// Only users in the group can remove members. If as a result of the call, zero users remain with access,
/// the group and its associated data will be deleted. Shared Groups are designed for sharing data between
/// a very small number of players, please see our guide: https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFSharedGroupsServerRemoveSharedGroupMembersAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFSharedGroupsRemoveSharedGroupMembersRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Adds, updates, and removes data keys for a shared group object. If the permission is set to Public,
/// all fields updated or added in this call will be readable by users not in the group. By default, data
/// permissions are set to Private. Regardless of the permission setting, only members of the group (and
/// the server) can update the data. Shared Groups are designed for sharing data between a very small
/// number of players, please see our guide: https://docs.microsoft.com/gaming/playfab/features/social/groups/using-shared-group-data
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Note that in the case of multiple calls to write to the same shared group data keys, the last write
/// received by the PlayFab service will determine the value available to subsequent read operations.
/// For scenarios requiring coordination of data updates, it is recommended that titles make use of user
/// data with read permission set to public, or a combination of user data and shared group data.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFSharedGroupsServerUpdateSharedGroupDataAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFSharedGroupsUpdateSharedGroupDataRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;


}