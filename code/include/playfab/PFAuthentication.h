// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFAuthenticationDataModels.h>
#include <playfab/PFServiceConfig.h>
#include <playfab/PFTitlePlayer.h>

extern "C"
{

/// <summary>
/// Authenticates a player from the specified player account pool using the 'Custom ID' player identity
/// provider, finds or provisions a master_player_account associated with the player identity, and returns
/// an entity token for it. Optionally logs the authenticated player into the specified title and returns
/// an additional entity token for the title_player_account.
/// </summary>
/// <param name="serviceConfigHandle">PFServiceConfigHandle returned from PFPFServiceConfigCreateHandle call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAuthenticationAuthenticateWithCustomIdGetResult"/> to get the result.
/// </remarks>
PF_API PFAuthenticationAuthenticateWithCustomIdAsync(
    _In_ PFServiceConfigHandle serviceConfigHandle,
    _In_ const PFAuthenticationAuthenticateCustomIdIdentityRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <symmary>
/// Get the result from a PFAuthenticationAuthenticateWithCustomIdAsync call.
/// </symmary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="entityHandle">TitlePlayer handle which can be used to authenticate other PlayFab API calls.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If the PFAuthenticationAuthenticateWithCustomIdAsync call fails, entityHandle with be null. Otherwise, the handle must be closed with PFTitlePlayerCloseHandle
/// when it is no longer needed.
/// </remarks>
PF_API PFAuthenticationAuthenticateWithCustomIdGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFTitlePlayerHandle* entityHandle
) noexcept;

/// <summary>
/// Authenticates a player from the specified player account pool using the 'Custom ID' player identity
/// provider, finds or provisions a master_player_account associated with the player identity, and returns
/// an entity token for it. Optionally logs the authenticated player into the specified title and returns
/// an additional entity token for the title_player_account.
/// </summary>
/// <param name="titlePlayerHandle">PFTitlePlayerHandle to reauthenticate.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Call XAsyncGetStatus to get the result of the operation.
/// If successful, the cached EntityToken for the TitlePlayer will be updated in place.
/// </remarks>
PF_API PFAuthenticationReAuthenticateWithCustomIdAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAuthenticationAuthenticateCustomIdIdentityRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;


}
