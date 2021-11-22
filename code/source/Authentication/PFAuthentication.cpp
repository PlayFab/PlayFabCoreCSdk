#include "stdafx.h"
#include <playfab/PFAuthentication.h>
#include "Authentication.h"
#include "ApiAsyncProviders.h"
#include "GlobalState.h"
#include "Entity.h"

using namespace PlayFab;
using namespace PlayFab::Authentication;

HRESULT PFAuthenticationAdminCreateOpenIdConnectionAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationCreateOpenIdConnectionRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::AdminCreateOpenIdConnection, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationAdminCreatePlayerSharedSecretAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationCreatePlayerSharedSecretRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::AdminCreatePlayerSharedSecret, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationAdminCreatePlayerSharedSecretGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFAuthenticationAdminCreatePlayerSharedSecretGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationCreatePlayerSharedSecretResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFAuthenticationCreatePlayerSharedSecretResult*>(buffer);

    return S_OK;
}

HRESULT PFAuthenticationAdminDeleteOpenIdConnectionAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationDeleteOpenIdConnectionRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::AdminDeleteOpenIdConnection, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationAdminDeletePlayerSharedSecretAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationDeletePlayerSharedSecretRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::AdminDeletePlayerSharedSecret, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationAdminGetPlayerSharedSecretsAsync(
    _In_ PFStateHandle contextHandle,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::AdminGetPlayerSharedSecrets, contextHandle->state, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationAdminGetPlayerSharedSecretsGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFAuthenticationAdminGetPlayerSharedSecretsGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationGetPlayerSharedSecretsResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFAuthenticationGetPlayerSharedSecretsResult*>(buffer);

    return S_OK;
}

HRESULT PFAuthenticationAdminGetPolicyAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationGetPolicyRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::AdminGetPolicy, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationAdminGetPolicyGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFAuthenticationAdminGetPolicyGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationGetPolicyResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFAuthenticationGetPolicyResponse*>(buffer);

    return S_OK;
}

HRESULT PFAuthenticationAdminListOpenIdConnectionAsync(
    _In_ PFStateHandle contextHandle,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::AdminListOpenIdConnection, contextHandle->state, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationAdminListOpenIdConnectionGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFAuthenticationAdminListOpenIdConnectionGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationListOpenIdConnectionResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFAuthenticationListOpenIdConnectionResponse*>(buffer);

    return S_OK;
}

HRESULT PFAuthenticationAdminSetPlayerSecretAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationAdminSetPlayerSecretRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::AdminSetPlayerSecret, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationAdminUpdateOpenIdConnectionAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationUpdateOpenIdConnectionRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::AdminUpdateOpenIdConnection, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationAdminUpdatePlayerSharedSecretAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationUpdatePlayerSharedSecretRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::AdminUpdatePlayerSharedSecret, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationAdminUpdatePolicyAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationUpdatePolicyRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::AdminUpdatePolicy, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationAdminUpdatePolicyGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFAuthenticationAdminUpdatePolicyGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationUpdatePolicyResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFAuthenticationUpdatePolicyResponse*>(buffer);

    return S_OK;
}

HRESULT PFAuthenticationClientGetPhotonAuthenticationTokenAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFAuthenticationGetPhotonAuthenticationTokenRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientGetPhotonAuthenticationToken, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientGetPhotonAuthenticationTokenGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFAuthenticationClientGetPhotonAuthenticationTokenGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationGetPhotonAuthenticationTokenResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFAuthenticationGetPhotonAuthenticationTokenResult*>(buffer);

    return S_OK;
}

HRESULT PFAuthenticationClientGetTitlePublicKeyAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationGetTitlePublicKeyRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientGetTitlePublicKey, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientGetTitlePublicKeyGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFAuthenticationClientGetTitlePublicKeyGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationGetTitlePublicKeyResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFAuthenticationGetTitlePublicKeyResult*>(buffer);

    return S_OK;
}

HRESULT PFAuthenticationClientLoginWithAndroidDeviceIDAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithAndroidDeviceIDRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithAndroidDeviceID, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientLoginGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFTitlePlayerHandle* titlePlayerHandle
) noexcept
{
    return XAsyncGetResult(async, nullptr, sizeof(PFTitlePlayerHandle), titlePlayerHandle, nullptr);
}

HRESULT PFAuthenticationClientLoginWithAppleAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithAppleRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithApple, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientLoginWithCustomIDAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithCustomIDRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithCustomID, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientLoginWithEmailAddressAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithEmailAddressRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithEmailAddress, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientLoginWithFacebookAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithFacebookRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithFacebook, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientLoginWithFacebookInstantGamesIdAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithFacebookInstantGamesIdRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithFacebookInstantGamesId, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientLoginWithGameCenterAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithGameCenterRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithGameCenter, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientLoginWithGoogleAccountAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithGoogleAccountRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithGoogleAccount, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientLoginWithIOSDeviceIDAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithIOSDeviceIDRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithIOSDeviceID, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientLoginWithKongregateAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithKongregateRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithKongregate, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientLoginWithNintendoServiceAccountAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithNintendoServiceAccountRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithNintendoServiceAccount, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientLoginWithNintendoSwitchDeviceIdAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithNintendoSwitchDeviceIdRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithNintendoSwitchDeviceId, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientLoginWithOpenIdConnectAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithOpenIdConnectRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithOpenIdConnect, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientLoginWithPlayFabAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithPlayFabRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithPlayFab, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientLoginWithPSNAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithPSNRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithPSN, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientLoginWithSteamAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithSteamRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithSteam, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientLoginWithTwitchAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithTwitchRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithTwitch, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientLoginWithXboxAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationClientLoginWithXboxRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientLoginWithXbox, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

#if HC_PLATFORM == HC_PLATFORM_GDK
HRESULT PFAuthenticationLoginWithXUserAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithXUserRequest* request,
    _Inout_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::LoginWithXUser, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}
#endif

HRESULT PFAuthenticationClientRegisterPlayFabUserAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationRegisterPlayFabUserRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientRegisterPlayFabUser, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationClientRegisterPlayFabUserGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFTitlePlayerHandle* entityHandle
) noexcept
{
    return XAsyncGetResult(async, nullptr, sizeof(PFTitlePlayerHandle), entityHandle, nullptr);
}

HRESULT PFAuthenticationClientSetPlayerSecretAsync(
    _In_ PFTitlePlayerHandle contextHandle,
    _In_ const PFAuthenticationClientSetPlayerSecretRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ClientSetPlayerSecret, contextHandle->titlePlayer, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationServerAuthenticateSessionTicketAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationAuthenticateSessionTicketRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ServerAuthenticateSessionTicket, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationServerAuthenticateSessionTicketGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFAuthenticationServerAuthenticateSessionTicketGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationAuthenticateSessionTicketResult** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFAuthenticationAuthenticateSessionTicketResult*>(buffer);

    return S_OK;
}

HRESULT PFAuthenticationServerLoginWithServerCustomIdAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithServerCustomIdRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ServerLoginWithServerCustomId, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationServerLoginGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFTitlePlayerHandle* titlePlayerHandle
) noexcept
{
    return XAsyncGetResult(async, nullptr, sizeof(PFTitlePlayerHandle), titlePlayerHandle, nullptr);
}            

HRESULT PFAuthenticationServerLoginWithSteamIdAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithSteamIdRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ServerLoginWithSteamId, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationServerLoginWithXboxAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationServerLoginWithXboxRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ServerLoginWithXbox, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationServerLoginWithXboxIdAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationLoginWithXboxIdRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ServerLoginWithXboxId, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationServerSetPlayerSecretAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationServerSetPlayerSecretRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ServerSetPlayerSecret, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationGetEntityTokenAsync(
    _In_ PFStateHandle contextHandle,
    _In_ const PFAuthenticationGetEntityTokenRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeAuthProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::GetEntityToken, contextHandle->state, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationGetEntityTokenGetResult(
    _In_ XAsyncBlock* async,
    _Out_ PFEntityHandle* entityHandle
) noexcept
{
    return XAsyncGetResult(async, nullptr, sizeof(PFEntityHandle), entityHandle, nullptr);
}

HRESULT PFAuthenticationValidateEntityTokenAsync(
    _In_ PFEntityHandle contextHandle,
    _In_ const PFAuthenticationValidateEntityTokenRequest* request,
    _In_ XAsyncBlock* async
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(contextHandle);
    RETURN_HR_INVALIDARG_IF_NULL(request);

    auto provider = MakeProvider(async, __FUNCTION__, std::bind(&AuthenticationAPI::ValidateEntityToken, contextHandle->entity, *request, std::placeholders::_1));
    return Provider::Run(UniquePtr<Provider>(provider.release()));
}

HRESULT PFAuthenticationValidateEntityTokenGetResultSize(
    _In_ XAsyncBlock* async,
    _Out_ size_t* bufferSize
) noexcept
{
    return XAsyncGetResultSize(async, bufferSize);
}

HRESULT PFAuthenticationValidateEntityTokenGetResult(
    _In_ XAsyncBlock* async,
    _In_ size_t bufferSize,
    _Out_writes_bytes_to_(bufferSize, *bufferUsed) void* buffer,
    _Outptr_ PFAuthenticationValidateEntityTokenResponse** result,
    _Out_opt_ size_t* bufferUsed
) noexcept
{
    RETURN_HR_INVALIDARG_IF_NULL(result);

    RETURN_IF_FAILED(XAsyncGetResult(async, nullptr, bufferSize, buffer, bufferUsed));
    *result = static_cast<PFAuthenticationValidateEntityTokenResponse*>(buffer);

    return S_OK;
}

