// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include <playfab/PFAuthenticationDataModels.h>
#include <playfab/PFGlobal.h>
#include <playfab/PFTitlePlayer.h>

extern "C"
{

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Registers a relationship between a title and an Open ID Connect provider.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminDeleteOpenIdConnectionAsync, AdminListOpenIdConnectionAsync, AdminUpdateOpenIdConnectionAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAuthenticationAdminCreateOpenIdConnectionAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationCreateOpenIdConnectionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Creates a new Player Shared Secret Key. It may take up to 5 minutes for this key to become generally
/// available after this API returns.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Player Shared Secret Keys are used for the call to Client/GetTitlePublicKey, which exchanges the
/// shared secret for an RSA CSP blob to be used to encrypt the payload of account creation requests when
/// that API requires a signature header. See also AdminGetPlayerSharedSecretsAsync, AdminUpdatePlayerSharedSecretAsync.
///
/// If successful, call <see cref="PFAuthenticationAdminCreatePlayerSharedSecretGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFAuthenticationAdminCreatePlayerSharedSecretAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationCreatePlayerSharedSecretRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminCreatePlayerSharedSecret call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAuthenticationAdminCreatePlayerSharedSecretGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAuthenticationAdminCreatePlayerSharedSecretAsync call.
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
HRESULT PFAuthenticationAdminCreatePlayerSharedSecretGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationCreatePlayerSharedSecretResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Removes a relationship between a title and an OpenID Connect provider.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminCreateOpenIdConnectionAsync, AdminListOpenIdConnectionAsync, AdminUpdateOpenIdConnectionAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAuthenticationAdminDeleteOpenIdConnectionAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationDeleteOpenIdConnectionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Deletes an existing Player Shared Secret Key. It may take up to 5 minutes for this delete to be reflected
/// after this API returns.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Player Shared Secret Keys are used for the call to Client/GetTitlePublicKey, which exchanges the
/// shared secret for an RSA CSP blob to be used to encrypt the payload of account creation requests when
/// that API requires a signature header. See also AdminCreatePlayerSharedSecretAsync, AdminGetPlayerSharedSecretsAsync,
/// AdminUpdatePlayerSharedSecretAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAuthenticationAdminDeletePlayerSharedSecretAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationDeletePlayerSharedSecretRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Returns all Player Shared Secret Keys including disabled and expired.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Player Shared Secret Keys are used for the call to Client/GetTitlePublicKey, which exchanges the
/// shared secret for an RSA CSP blob to be used to encrypt the payload of account creation requests when
/// that API requires a signature header. See also AdminCreatePlayerSharedSecretAsync, AdminUpdatePlayerSharedSecretAsync.
///
/// If successful, call <see cref="PFAuthenticationAdminGetPlayerSharedSecretsGetResult"/> to get the
/// result.
/// </remarks>
HRESULT PFAuthenticationAdminGetPlayerSharedSecretsAsync(
    _In_ PFStateHandle stateHandle,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetPlayerSharedSecrets call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAuthenticationAdminGetPlayerSharedSecretsGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAuthenticationAdminGetPlayerSharedSecretsAsync call.
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
HRESULT PFAuthenticationAdminGetPlayerSharedSecretsGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationGetPlayerSharedSecretsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Gets the requested policy.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Views the requested policy. Today, the only supported policy is 'ApiPolicy'. See also AdminUpdatePolicyAsync.
///
/// If successful, call <see cref="PFAuthenticationAdminGetPolicyGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationAdminGetPolicyAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationGetPolicyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminGetPolicy call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAuthenticationAdminGetPolicyGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAuthenticationAdminGetPolicyAsync call.
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
HRESULT PFAuthenticationAdminGetPolicyGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationGetPolicyResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Retrieves a list of all Open ID Connect providers registered to a title.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminCreateOpenIdConnectionAsync, AdminDeleteOpenIdConnectionAsync, AdminUpdateOpenIdConnectionAsync.
///
/// If successful, call <see cref="PFAuthenticationAdminListOpenIdConnectionGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationAdminListOpenIdConnectionAsync(
    _In_ PFStateHandle stateHandle,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminListOpenIdConnection call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAuthenticationAdminListOpenIdConnectionGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAuthenticationAdminListOpenIdConnectionAsync call.
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
HRESULT PFAuthenticationAdminListOpenIdConnectionGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationListOpenIdConnectionResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Sets or resets the player's secret. Player secrets are used to sign API requests.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// APIs that require signatures require that the player have a configured Player Secret Key that is
/// used to sign all requests. Players that don't have a secret will be blocked from making API calls
/// until it is configured. To create a signature header add a SHA256 hashed string containing UTF8 encoded
/// JSON body as it will be sent to the server, the current time in UTC formatted to ISO 8601, and the
/// players secret formatted as 'body.date.secret'. Place the resulting hash into the header X-PlayFab-Signature,
/// along with a header X-PlayFab-Timestamp of the same UTC timestamp used in the signature.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAuthenticationAdminSetPlayerSecretAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationAdminSetPlayerSecretRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Modifies data and credentials for an existing relationship between a title and an Open ID Connect
/// provider
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also AdminCreateOpenIdConnectionAsync, AdminDeleteOpenIdConnectionAsync, AdminListOpenIdConnectionAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAuthenticationAdminUpdateOpenIdConnectionAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationUpdateOpenIdConnectionRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Updates a existing Player Shared Secret Key. It may take up to 5 minutes for this update to become
/// generally available after this API returns.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Player Shared Secret Keys are used for the call to Client/GetTitlePublicKey, which exchanges the
/// shared secret for an RSA CSP blob to be used to encrypt the payload of account creation requests when
/// that API requires a signature header. See also AdminCreatePlayerSharedSecretAsync, AdminGetPlayerSharedSecretsAsync.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAuthenticationAdminUpdatePlayerSharedSecretAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationUpdatePlayerSharedSecretRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Changes a policy for a title
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Updates permissions for your title. Policies affect what is allowed to happen on your title. Your
/// policy is a collection of statements that, together, govern particular area for your title. Today,
/// the only allowed policy is called 'ApiPolicy' and it governs what API calls are allowed. To verify
/// that you have the latest version always download the current policy from GetPolicy before uploading
/// a new policy. PlayFab updates the base policy periodically and will automatically apply it to the
/// uploaded policy. Overwriting the combined policy blindly may result in unexpected API errors. See
/// also AdminGetPolicyAsync.
///
/// If successful, call <see cref="PFAuthenticationAdminUpdatePolicyGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationAdminUpdatePolicyAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationUpdatePolicyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AdminUpdatePolicy call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAuthenticationAdminUpdatePolicyGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAuthenticationAdminUpdatePolicyAsync call.
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
HRESULT PFAuthenticationAdminUpdatePolicyGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationUpdatePolicyResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

/// <summary>
/// Gets a Photon custom authentication token that can be used to securely join the player into a Photon
/// room. See https://docs.microsoft.com/gaming/playfab/features/multiplayer/photon/quickstart for more
/// details.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAuthenticationClientGetPhotonAuthenticationTokenGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFAuthenticationClientGetPhotonAuthenticationTokenAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAuthenticationGetPhotonAuthenticationTokenRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetPhotonAuthenticationToken call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAuthenticationClientGetPhotonAuthenticationTokenGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAuthenticationClientGetPhotonAuthenticationTokenAsync call.
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
HRESULT PFAuthenticationClientGetPhotonAuthenticationTokenGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationGetPhotonAuthenticationTokenResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Returns the title's base 64 encoded RSA CSP blob.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// An RSA CSP blob to be used to encrypt the payload of account creation requests when that API requires
/// a signature header. For example if Client/LoginWithCustomId requires signature headers but the player
/// does not have an account yet follow these steps: 1) Call Client/GetTitlePublicKey with one of the
/// title's shared secrets. 2) Convert the Base64 encoded CSP blob to a byte array and create an RSA signing
/// object. 3) Encrypt the UTF8 encoded JSON body of the registration request and place the Base64 encoded
/// result into the EncryptedRequest and with the TitleId field, all other fields can be left empty when
/// performing the API request. 4) Client receives authentication token as normal. Future requests to
/// LoginWithCustomId will require the X-PlayFab-Signature header.
///
/// If successful, call <see cref="PFAuthenticationClientGetTitlePublicKeyGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientGetTitlePublicKeyAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationGetTitlePublicKeyRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ClientGetTitlePublicKey call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAuthenticationClientGetTitlePublicKeyGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAuthenticationClientGetTitlePublicKeyAsync call.
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
HRESULT PFAuthenticationClientGetTitlePublicKeyGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationGetTitlePublicKeyResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Signs the user in using the Android device identifier, returning a session identifier that can subsequently
/// be used for API calls which require an authenticated user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// On Android devices, the recommendation is to use the Settings.Secure.ANDROID_ID as the AndroidDeviceId,
/// as described in this blog post (http://android-developers.blogspot.com/2011/03/identifying-app-installations.html).
/// More information on this identifier can be found in the Android documentation (http://developer.android.com/reference/android/provider/Settings.Secure.html).
/// If this is the first time a user has signed in with the Android device and CreateAccount is set to
/// true, a new PlayFab account will be created and linked to the Android device ID. In this case, no
/// email or username will be associated with the PlayFab account. Otherwise, if no PlayFab account is
/// linked to the Android device, an error indicating this will be returned, so that the title can guide
/// the user through creation of a PlayFab account. Please note that while multiple devices of this type
/// can be linked to a single user account, only the one most recently used to login (or most recently
/// linked) will be reflected in the user's account information. We will be updating to show all linked
/// devices in a future release. See also ClientLinkAndroidDeviceIDAsync, ClientLoginWithIOSDeviceIDAsync,
/// ClientUnlinkAndroidDeviceIDAsync.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithAndroidDeviceIDAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithAndroidDeviceIDRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <symmary>
/// Get the result from a PFAuthenticationClientLogin* call.
/// </symmary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="titlePlayerHandle">TitlePlayer handle which can be used to authenticate other PlayFab API calls.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If the login attempt fails, titlePlayerHandle with be null. Otherwise, the handle must be closed with PFTitlePlayerCloseHandle
/// when it is no longer needed.
/// </remarks>
HRESULT PFAuthenticationClientLoginGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFTitlePlayerHandle* titlePlayerHandle
) noexcept;

/// <summary>
/// Signs in the user with a Sign in with Apple identity token.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLinkAppleAsync, ClientUnlinkAppleAsync.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithAppleAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithAppleRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Signs the user in using a custom unique identifier generated by the title, returning a session identifier
/// that can subsequently be used for API calls which require an authenticated user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// It is highly recommended that developers ensure that it is extremely unlikely that a customer could
/// generate an ID which is already in use by another customer. If this is the first time a user has signed
/// in with the Custom ID and CreateAccount is set to true, a new PlayFab account will be created and
/// linked to the Custom ID. In this case, no email or username will be associated with the PlayFab account.
/// Otherwise, if no PlayFab account is linked to the Custom ID, an error indicating this will be returned,
/// so that the title can guide the user through creation of a PlayFab account. See also ClientLinkCustomIDAsync,
/// ClientUnlinkCustomIDAsync.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithCustomIDAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithCustomIDRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Signs the user into the PlayFab account, returning a session identifier that can subsequently be
/// used for API calls which require an authenticated user. Unlike most other login API calls, LoginWithEmailAddress
/// does not permit the creation of new accounts via the CreateAccountFlag. Email addresses may be used
/// to create accounts via RegisterPlayFabUser.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Email address and password lengths are provided for information purposes. The server will validate
/// that data passed in conforms to the field definition and report errors appropriately. It is recommended
/// that developers not perform this validation locally, so that future updates do not require client
/// updates. See also ClientLoginWithPlayFabAsync, ClientRegisterPlayFabUserAsync.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithEmailAddressAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithEmailAddressRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Signs the user in using a Facebook access token, returning a session identifier that can subsequently
/// be used for API calls which require an authenticated user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Facebook sign-in is accomplished using the Facebook User Access Token. More information on the Token
/// can be found in the Facebook developer documentation (https://developers.facebook.com/docs/facebook-login/access-tokens/).
/// In Unity, for example, the Token is available as AccessToken in the Facebook SDK ScriptableObject
/// FB. If this is the first time a user has signed in with the Facebook account and CreateAccount is
/// set to true, a new PlayFab account will be created and linked to the provided account's Facebook ID.
/// In this case, no email or username will be associated with the PlayFab account. Otherwise, if no PlayFab
/// account is linked to the Facebook account, an error indicating this will be returned, so that the
/// title can guide the user through creation of a PlayFab account. Note that titles should never re-use
/// the same Facebook applications between PlayFab Title IDs, as Facebook provides unique user IDs per
/// application and doing so can result in issues with the Facebook ID for the user in their PlayFab account
/// information. If you must re-use an application in a new PlayFab Title ID, please be sure to first
/// unlink all accounts from Facebook, or delete all users in the first Title ID. See also ClientLinkFacebookAccountAsync,
/// ClientUnlinkFacebookAccountAsync.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithFacebookAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithFacebookRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Signs the user in using a Facebook Instant Games ID, returning a session identifier that can subsequently
/// be used for API calls which require an authenticated user. Requires Facebook Instant Games to be configured.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLinkFacebookInstantGamesIdAsync, ClientUnlinkFacebookInstantGamesIdAsync.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithFacebookInstantGamesIdAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithFacebookInstantGamesIdRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Signs the user in using an iOS Game Center player identifier, returning a session identifier that
/// can subsequently be used for API calls which require an authenticated user. Logging in with a Game
/// Center ID is insecure if you do not include the optional PublicKeyUrl, Salt, Signature, and Timestamp
/// parameters in this request. It is recommended you require these parameters on all Game Center calls
/// by going to the Apple Add-ons page in the PlayFab Game Manager and enabling the 'Require secure authentication
/// only for this app' option.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// The Game Center player identifier (https://developer.apple.com/library/ios/documentation/Accounts/Reference/ACAccountClassRef/index.html#//apple_ref/occ/instp/ACAccount/identifier)
/// is a generated string which is stored on the local device. As with device identifiers, care must be
/// taken to never expose a player's Game Center identifier to end users, as that could result in a user's
/// account being compromised. If this is the first time a user has signed in with Game Center and CreateAccount
/// is set to true, a new PlayFab account will be created and linked to the Game Center identifier. In
/// this case, no email or username will be associated with the PlayFab account. Otherwise, if no PlayFab
/// account is linked to the Game Center account, an error indicating this will be returned, so that the
/// title can guide the user through creation of a PlayFab account. See also ClientLoginWithIOSDeviceIDAsync.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithGameCenterAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithGameCenterRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Signs the user in using their Google account credentials
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Google sign-in is accomplished by obtaining a Google OAuth 2.0 credential using the Google sign-in
/// for Android APIs on the device and passing it to this API. If this is the first time a user has signed
/// in with the Google account and CreateAccount is set to true, a new PlayFab account will be created
/// and linked to the Google account. Otherwise, if no PlayFab account is linked to the Google account,
/// an error indicating this will be returned, so that the title can guide the user through creation of
/// a PlayFab account. The current (recommended) method for obtaining a Google account credential in an
/// Android application is to call GoogleSignInAccount.getServerAuthCode() and send the auth code as the
/// ServerAuthCode parameter of this API. Before doing this, you must create an OAuth 2.0 web application
/// client ID in the Google API Console and configure its client ID and secret in the PlayFab Game Manager
/// Google Add-on for your title. This method does not require prompting of the user for additional Google
/// account permissions, resulting in a user experience with the least possible friction. For more information
/// about obtaining the server auth code, see https://developers.google.com/identity/sign-in/android/offline-access.
/// The previous (deprecated) method was to obtain an OAuth access token by calling GetAccessToken() on
/// the client and passing it as the AccessToken parameter to this API. for the with the Google OAuth
/// 2.0 Access Token. More information on this change can be found in the Google developer documentation
/// (https://android-developers.googleblog.com/2016/01/play-games-permissions-are-changing-in.html).
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithGoogleAccountAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithGoogleAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Signs the user in using their Google Play Games account credentials
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Google Play Games sign-in is accomplished by obtaining a Google OAuth 2.0 credential using the Google
/// Play Games sign-in for Android APIs on the device and passing it to this API. If this is the first
/// time a user has signed in with the Google Play Games account and CreateAccount is set to true, a new
/// PlayFab account will be created and linked to the Google Play Games account. Otherwise, if no PlayFab
/// account is linked to the Google Play Games account, an error indicating this will be returned, so
/// that the title can guide the user through creation of a PlayFab account. The current (recommended)
/// method for obtaining a Google Play Games account credential in an Android application is to call GamesSignInClient.requestServerSideAccess()
/// and send the auth code as the ServerAuthCode parameter of this API. Before doing this, you must create
/// an OAuth 2.0 web application client ID in the Google API Console and configure its client ID and secret
/// in the PlayFab Game Manager Google Add-on for your title. This method does not require prompting of
/// the user for additional Google account permissions, resulting in a user experience with the least
/// possible friction. For more information about obtaining the server auth code, see https://developers.google.com/games/services/android/signin.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithGooglePlayGamesServicesAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithGooglePlayGamesServicesRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Signs the user in using the vendor-specific iOS device identifier, returning a session identifier
/// that can subsequently be used for API calls which require an authenticated user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// On iOS devices, the identifierForVendor (https://developer.apple.com/library/ios/documentation/UIKit/Reference/UIDevice_Class/index.html#//apple_ref/occ/instp/UIDevice/identifierForVendor)
/// must be used as the DeviceId, as the UIDevice uniqueIdentifier has been deprecated as of iOS 5, and
/// use of the advertisingIdentifier for this purpose will result in failure of Apple's certification
/// process. If this is the first time a user has signed in with the iOS device and CreateAccount is set
/// to true, a new PlayFab account will be created and linked to the vendor-specific iOS device ID. In
/// this case, no email or username will be associated with the PlayFab account. Otherwise, if no PlayFab
/// account is linked to the iOS device, an error indicating this will be returned, so that the title
/// can guide the user through creation of a PlayFab account. Please note that while multiple devices
/// of this type can be linked to a single user account, only the one most recently used to login (or
/// most recently linked) will be reflected in the user's account information. We will be updating to
/// show all linked devices in a future release. See also ClientLinkIOSDeviceIDAsync, ClientUnlinkIOSDeviceIDAsync.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithIOSDeviceIDAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithIOSDeviceIDRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Signs the user in using a Kongregate player account.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// More details regarding Kongregate and their game authentication system can be found at http://developers.kongregate.com/docs/virtual-goods/authentication.
/// Developers must provide the Kongregate user ID and auth token that are generated using the Kongregate
/// client library. PlayFab will combine these identifiers with the title's unique Kongregate app ID to
/// log the player into the Kongregate system. If CreateAccount is set to true and there is not already
/// a user matched to this Kongregate ID, then PlayFab will create a new account for this user and link
/// the ID. In this case, no email or username will be associated with the PlayFab account. If there is
/// already a different PlayFab user linked with this account, then an error will be returned. See also
/// ClientLinkKongregateAsync, ClientUnlinkKongregateAsync.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithKongregateAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithKongregateRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Signs in the user with a Nintendo service account token.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLinkNintendoServiceAccountAsync, ClientUnlinkNintendoServiceAccountAsync.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithNintendoServiceAccountAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithNintendoServiceAccountRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Signs the user in using a Nintendo Switch Device ID, returning a session identifier that can subsequently
/// be used for API calls which require an authenticated user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLinkNintendoSwitchDeviceIdAsync, ClientUnlinkNintendoSwitchDeviceIdAsync.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithNintendoSwitchDeviceIdAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithNintendoSwitchDeviceIdRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Logs in a user with an Open ID Connect JWT created by an existing relationship between a title and
/// an Open ID Connect provider.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLinkOpenIdConnectAsync, ClientUnlinkOpenIdConnectAsync.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithOpenIdConnectAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithOpenIdConnectRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Signs the user into the PlayFab account, returning a session identifier that can subsequently be
/// used for API calls which require an authenticated user. Unlike most other login API calls, LoginWithPlayFab
/// does not permit the creation of new accounts via the CreateAccountFlag. Username/Password credentials
/// may be used to create accounts via RegisterPlayFabUser, or added to existing accounts using AddUsernamePassword.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Username and password lengths are provided for information purposes. The server will validate that
/// data passed in conforms to the field definition and report errors appropriately. It is recommended
/// that developers not perform this validation locally, so that future updates to the username or password
/// do not require client updates. See also ClientAddUsernamePasswordAsync, ClientLoginWithEmailAddressAsync,
/// ClientRegisterPlayFabUserAsync.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithPlayFabAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithPlayFabRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Signs the user in using a PlayStation :tm: Network authentication code, returning a session identifier
/// that can subsequently be used for API calls which require an authenticated user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If this is the first time a user has signed in with the PlayStation :tm: Network account and CreateAccount
/// is set to true, a new PlayFab account will be created and linked to the PlayStation :tm: Network account.
/// In this case, no email or username will be associated with the PlayFab account. Otherwise, if no PlayFab
/// account is linked to the PlayStation :tm: Network account, an error indicating this will be returned,
/// so that the title can guide the user through creation of a PlayFab account. See also ClientLinkPSNAccountAsync,
/// ClientUnlinkPSNAccountAsync.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithPSNAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithPSNRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Signs the user in using a Steam authentication ticket, returning a session identifier that can subsequently
/// be used for API calls which require an authenticated user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Steam sign-in is accomplished with the Steam Session Ticket. More information on the Ticket can be
/// found in the Steamworks SDK, here: https://partner.steamgames.com/documentation/auth (requires sign-in).
/// NOTE: For Steam authentication to work, the title must be configured with the Steam Application ID
/// and Web API Key in the PlayFab Game Manager (under Steam in the Add-ons Marketplace). You can obtain
/// a Web API Key from the Permissions page of any Group associated with your App ID in the Steamworks
/// site. If this is the first time a user has signed in with the Steam account and CreateAccount is set
/// to true, a new PlayFab account will be created and linked to the provided account's Steam ID. In this
/// case, no email or username will be associated with the PlayFab account. Otherwise, if no PlayFab account
/// is linked to the Steam account, an error indicating this will be returned, so that the title can guide
/// the user through creation of a PlayFab account. See also ClientLinkSteamAccountAsync, ClientUnlinkSteamAccountAsync.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithSteamAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithSteamRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Signs the user in using a Twitch access token.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// More details regarding Twitch and their authentication system can be found at https://github.com/justintv/Twitch-API/blob/master/authentication.md.
/// Developers must provide the Twitch access token that is generated using one of the Twitch authentication
/// flows. PlayFab will use the title's unique Twitch Client ID to authenticate the token and log in to
/// the PlayFab system. If CreateAccount is set to true and there is not already a user matched to the
/// Twitch username that generated the token, then PlayFab will create a new account for this user and
/// link the ID. In this case, no email or username will be associated with the PlayFab account. If there
/// is already a different PlayFab user linked with this account, then an error will be returned. See
/// also ClientLinkTwitchAsync, ClientUnlinkTwitchAsync.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithTwitchAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithTwitchRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Signs the user in using a Xbox Live Token, returning a session identifier that can subsequently be
/// used for API calls which require an authenticated user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If this is the first time a user has signed in with the Xbox Live account and CreateAccount is set
/// to true, a new PlayFab account will be created and linked to the Xbox Live account. In this case,
/// no email or username will be associated with the PlayFab account. Otherwise, if no PlayFab account
/// is linked to the Xbox Live account, an error indicating this will be returned, so that the title can
/// guide the user through creation of a PlayFab account. See also ClientLinkXboxAccountAsync, ClientUnlinkXboxAccountAsync.
///
/// If successful, call <see cref="PFAuthenticationClientLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientLoginWithXboxAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationClientLoginWithXboxRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

#if HC_PLATFORM == HC_PLATFORM_GDK
/// <summary>
/// Login using a GDK XUser handle. The API will first acquire an XToken and then authenticate with PlayFab service.
/// The returned Entity will hold an XUser reference (via XUserDuplicateHandle) until it is closed. The stored XUserHandle
/// will be used to get a new XToken prior to refreshing PlayFab auth tokens.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFGetAuthResult"/> to get the result. The resulting PFEntityHandle
/// will be used to authenticate future PlayFab calls.
/// </remarks>
HRESULT PFAuthenticationLoginWithXUserAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithXUserRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

/// <summary>
/// Registers a new Playfab user account, returning a session identifier that can subsequently be used
/// for API calls which require an authenticated user. You must supply either a username or an email address.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// See also ClientLoginWithEmailAddressAsync, ClientLoginWithPlayFabAsync.
///
/// If successful, call <see cref="PFAuthenticationClientRegisterPlayFabUserGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationClientRegisterPlayFabUserAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationRegisterPlayFabUserRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <symmary>
/// Get the result from a PFAuthenticationClientRegisterPlayFabUserAsync call.
/// </symmary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="entityHandle">TitlePlayer handle which can be used to authenticate other PlayFab API calls.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If the PFAuthenticationClientRegisterPlayFabUserAsync call fails, entityHandle with be null. Otherwise, the handle must be closed with PFTitlePlayerCloseHandle
/// when it is no longer needed.
/// </remarks>
HRESULT PFAuthenticationClientRegisterPlayFabUserGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFTitlePlayerHandle* entityHandle
) noexcept;

/// <summary>
/// Sets the player's secret if it is not already set. Player secrets are used to sign API requests.
/// To reset a player's secret use the Admin or Server API method SetPlayerSecret.
/// </summary>
/// <param name="entityHandle">PFTitlePlayerHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// APIs that require signatures require that the player have a configured Player Secret Key that is
/// used to sign all requests. Players that don't have a secret will be blocked from making API calls
/// until it is configured. To create a signature header add a SHA256 hashed string containing UTF8 encoded
/// JSON body as it will be sent to the server, the current time in UTC formatted to ISO 8601, and the
/// players secret formatted as 'body.date.secret'. Place the resulting hash into the header X-PlayFab-Signature,
/// along with a header X-PlayFab-Timestamp of the same UTC timestamp used in the signature.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAuthenticationClientSetPlayerSecretAsync(
    _In_ PFTitlePlayerHandle titlePlayerHandle,
    _In_ const PFAuthenticationClientSetPlayerSecretRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Validated a client's session ticket, and if successful, returns details for that user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Note that data returned may be Personally Identifying Information (PII), such as email address, and
/// so care should be taken in how this data is stored and managed. Since this call will always return
/// the relevant information for users who have accessed the title, the recommendation is to not store
/// this data locally.
///
/// If successful, call <see cref="PFAuthenticationServerAuthenticateSessionTicketGetResult"/> to get
/// the result.
/// </remarks>
HRESULT PFAuthenticationServerAuthenticateSessionTicketAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationAuthenticateSessionTicketRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ServerAuthenticateSessionTicket call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAuthenticationServerAuthenticateSessionTicketGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAuthenticationServerAuthenticateSessionTicketAsync call.
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
HRESULT PFAuthenticationServerAuthenticateSessionTicketGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationAuthenticateSessionTicketResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Securely login a game client from an external server backend using a custom identifier for that player.
/// Server Custom ID and Client Custom ID are mutually exclusive and cannot be used to retrieve the same
/// player account.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAuthenticationServerLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationServerLoginWithServerCustomIdAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithServerCustomIdRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <symmary>
/// Get the result from a PFAuthenticationServerLogin* call.
/// </symmary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="titlePlayerHandle">TitlePlayer handle which can be used to authenticate other PlayFab API calls.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If the login attempt fails, titlePlayerHandle with be null. Otherwise, the handle must be closed with PFTitlePlayerCloseHandle
/// when it is no longer needed.
/// </remarks>
HRESULT PFAuthenticationServerLoginGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFTitlePlayerHandle* titlePlayerHandle
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Signs the user in using an Steam ID, returning a session identifier that can subsequently be used
/// for API calls which require an authenticated user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If this is the first time a user has signed in with the Steam ID and CreateAccount is set to true,
/// a new PlayFab account will be created and linked to the Steam account. In this case, no email or username
/// will be associated with the PlayFab account. Otherwise, if no PlayFab account is linked to the Steam
/// account, an error indicating this will be returned, so that the title can guide the user through creation
/// of a PlayFab account. Steam users that are not logged into the Steam Client app will only have their
/// Steam username synced, other data, such as currency and country will not be available until they login
/// while the Client is open.
///
/// If successful, call <see cref="PFAuthenticationServerLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationServerLoginWithSteamIdAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithSteamIdRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Signs the user in using a Xbox Live Token from an external server backend, returning a session identifier
/// that can subsequently be used for API calls which require an authenticated user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If this is the first time a user has signed in with the Xbox Live account and CreateAccount is set
/// to true, a new PlayFab account will be created and linked to the Xbox Live account. In this case,
/// no email or username will be associated with the PlayFab account. Otherwise, if no PlayFab account
/// is linked to the Xbox Live account, an error indicating this will be returned, so that the title can
/// guide the user through creation of a PlayFab account.
///
/// If successful, call <see cref="PFAuthenticationServerLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationServerLoginWithXboxAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationServerLoginWithXboxRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Signs the user in using an Xbox ID and Sandbox ID, returning a session identifier that can subsequently
/// be used for API calls which require an authenticated user
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If this is the first time a user has signed in with the Xbox ID and CreateAccount is set to true,
/// a new PlayFab account will be created and linked to the Xbox Live account. In this case, no email
/// or username will be associated with the PlayFab account. Otherwise, if no PlayFab account is linked
/// to the Xbox Live account, an error indicating this will be returned, so that the title can guide the
/// user through creation of a PlayFab account.
///
/// If successful, call <see cref="PFAuthenticationServerLoginGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationServerLoginWithXboxIdAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationLoginWithXboxIdRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
/// <summary>
/// Sets the player's secret if it is not already set. Player secrets are used to sign API requests.
/// To reset a player's secret use the Admin or Server API method SetPlayerSecret.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// APIs that require signatures require that the player have a configured Player Secret Key that is
/// used to sign all requests. Players that don't have a secret will be blocked from making API calls
/// until it is configured. To create a signature header add a SHA256 hashed string containing UTF8 encoded
/// JSON body as it will be sent to the server, the current time in UTC formatted to ISO 8601, and the
/// players secret formatted as 'body.date.secret'. Place the resulting hash into the header X-PlayFab-Signature,
/// along with a header X-PlayFab-Timestamp of the same UTC timestamp used in the signature.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAuthenticationServerSetPlayerSecretAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationServerSetPlayerSecretRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;
#endif

/// <summary>
/// Create a game_server entity token and return a new or existing game_server entity.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Create or return a game_server entity token. Caller must be a title entity.
///
/// If successful, call <see cref="PFAuthenticationAuthenticateGameServerWithCustomIdGetResult"/> to
/// get the result.
/// </remarks>
HRESULT PFAuthenticationAuthenticateGameServerWithCustomIdAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFAuthenticationAuthenticateCustomIdRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a AuthenticateGameServerWithCustomId call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAuthenticationAuthenticateGameServerWithCustomIdGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAuthenticationAuthenticateGameServerWithCustomIdAsync call.
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
HRESULT PFAuthenticationAuthenticateGameServerWithCustomIdGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationAuthenticateCustomIdResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;

/// <summary>
/// Delete a game_server entity.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Delete a game_server entity. The caller can be the game_server entity attempting to delete itself.
/// Or a title entity attempting to delete game_server entities for this title.
///
/// Call <see cref="XAsyncGetStatus"/> to get the status of the operation.
/// </remarks>
HRESULT PFAuthenticationDeleteAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFAuthenticationDeleteRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Method to exchange a title SecretKey for an Entity Token.
/// </summary>
/// <param name="stateHandle">PFStateHandle returned from PFInitialize call.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If successful, call <see cref="PFAuthenticationGetEntityTokenGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationGetEntityTokenAsync(
    _In_ PFStateHandle stateHandle,
    _In_ const PFAuthenticationGetEntityTokenRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <symmary>
/// Get the result from a PFAuthenticationGetEntityTokenAsync call.
/// </symmary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="entityHandle">Entity handle which can be used to authenticate other PlayFab API calls.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// If the PFAuthenticationGetEntityTokenAsync call fails, entityHandle with be null. Otherwise, the handle must be closed with PFEntityCloseHandle
/// when it is no longer needed.
/// </remarks>
HRESULT PFAuthenticationGetEntityTokenGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFEntityHandle* entityHandle
) noexcept;

/// <summary>
/// Method for a server to validate a client provided EntityToken. Only callable by the title entity.
/// </summary>
/// <param name="entityHandle">PFEntityHandle to use for authentication.</param>
/// <param name="request">Populated request object.</param>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <returns>Result code for this API operation.</returns>
/// <remarks>
/// Given an entity token, validates that it hasn't expired or been revoked and will return details of
/// the owner.
///
/// If successful, call <see cref="PFAuthenticationValidateEntityTokenGetResult"/> to get the result.
/// </remarks>
HRESULT PFAuthenticationValidateEntityTokenAsync(
    _In_ PFEntityHandle entityHandle,
    _In_ const PFAuthenticationValidateEntityTokenRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept;

/// <summary>
/// Get the size in bytes needed to store the result of a ValidateEntityToken call.
/// </summary>
/// <param name="async">XAsyncBlock for the async operation.</param>
/// <param name="bufferSize">The buffer size in bytes required for the result.</param>
/// <returns>Result code for this API operation.</returns>
HRESULT PFAuthenticationValidateEntityTokenGetResultSize(
    _Inout_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept;

/// <summary>
/// Gets the result of a successful PFAuthenticationValidateEntityTokenAsync call.
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
HRESULT PFAuthenticationValidateEntityTokenGetResult(
    _Inout_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationValidateEntityTokenResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept;


}