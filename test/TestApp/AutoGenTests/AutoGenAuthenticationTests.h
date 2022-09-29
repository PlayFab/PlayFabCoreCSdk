#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFAuthenticationDataModelWrappers.h>
#include "AutoGenAuthenticationResultHolders.h"

namespace PlayFabUnit
{

class AutoGenAuthenticationTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAuthenticationAdminCreateOpenIdConnection(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAuthenticationAdminCreatePlayerSharedSecret(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAuthenticationAdminDeleteOpenIdConnection(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAuthenticationAdminDeletePlayerSharedSecret(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAuthenticationAdminGetPlayerSharedSecrets(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAuthenticationAdminGetPolicy(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAuthenticationAdminListOpenIdConnection(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAuthenticationAdminSetPlayerSecret(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAuthenticationAdminUpdateOpenIdConnection(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAuthenticationAdminUpdatePlayerSharedSecret(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAuthenticationAdminUpdatePolicy(TestContext& testContext);
#endif

    void TestAuthenticationClientGetPhotonAuthenticationToken(TestContext& testContext);

    void TestAuthenticationClientGetTitlePublicKey(TestContext& testContext);

    void TestAuthenticationClientLoginWithAndroidDeviceID(TestContext& testContext);

    void TestAuthenticationClientLoginWithApple(TestContext& testContext);

    void TestAuthenticationClientLoginWithCustomID(TestContext& testContext);

    void TestAuthenticationClientLoginWithEmailAddress(TestContext& testContext);

    void TestAuthenticationClientLoginWithFacebook(TestContext& testContext);

    void TestAuthenticationClientLoginWithFacebookInstantGamesId(TestContext& testContext);

    void TestAuthenticationClientLoginWithGameCenter(TestContext& testContext);

    void TestAuthenticationClientLoginWithGoogleAccount(TestContext& testContext);

    void TestAuthenticationClientLoginWithGooglePlayGamesServices(TestContext& testContext);

    void TestAuthenticationClientLoginWithIOSDeviceID(TestContext& testContext);

    void TestAuthenticationClientLoginWithKongregate(TestContext& testContext);

    void TestAuthenticationClientLoginWithNintendoServiceAccount(TestContext& testContext);

    void TestAuthenticationClientLoginWithNintendoSwitchDeviceId(TestContext& testContext);

    void TestAuthenticationClientLoginWithOpenIdConnect(TestContext& testContext);

    void TestAuthenticationClientLoginWithPlayFab(TestContext& testContext);

    void TestAuthenticationClientLoginWithPSN(TestContext& testContext);

    void TestAuthenticationClientLoginWithSteam(TestContext& testContext);

    void TestAuthenticationClientLoginWithTwitch(TestContext& testContext);

    void TestAuthenticationClientLoginWithXbox(TestContext& testContext);

    void TestAuthenticationClientRegisterPlayFabUser(TestContext& testContext);

    void TestAuthenticationClientSetPlayerSecret(TestContext& testContext);

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAuthenticationServerAuthenticateSessionTicket(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAuthenticationServerLoginWithServerCustomId(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAuthenticationServerLoginWithSteamId(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAuthenticationServerLoginWithXbox(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAuthenticationServerLoginWithXboxId(TestContext& testContext);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    void TestAuthenticationServerSetPlayerSecret(TestContext& testContext);
#endif

    void TestAuthenticationAuthenticateGameServerWithCustomId(TestContext& testContext);

    void TestAuthenticationDelete(TestContext& testContext);

    void TestAuthenticationGetEntityToken(TestContext& testContext);

    void TestAuthenticationValidateEntityToken(TestContext& testContext);


protected:
    void AddTests();

    static void LogCreateOpenIdConnectionRequest(PFAuthenticationCreateOpenIdConnectionRequest const* request, const char* testName);
    static void LogCreatePlayerSharedSecretRequest(PFAuthenticationCreatePlayerSharedSecretRequest const* request, const char* testName);
    static HRESULT LogCreatePlayerSharedSecretResult(PFAuthenticationCreatePlayerSharedSecretResult const* result);
    static void LogDeleteOpenIdConnectionRequest(PFAuthenticationDeleteOpenIdConnectionRequest const* request, const char* testName);
    static void LogDeletePlayerSharedSecretRequest(PFAuthenticationDeletePlayerSharedSecretRequest const* request, const char* testName);
    static HRESULT LogGetPlayerSharedSecretsResult(PFAuthenticationGetPlayerSharedSecretsResult const* result);
    static void LogGetPolicyRequest(PFAuthenticationGetPolicyRequest const* request, const char* testName);
    static HRESULT LogGetPolicyResponse(PFAuthenticationGetPolicyResponse const* result);
    static HRESULT LogListOpenIdConnectionResponse(PFAuthenticationListOpenIdConnectionResponse const* result);
    static void LogAdminSetPlayerSecretRequest(PFAuthenticationAdminSetPlayerSecretRequest const* request, const char* testName);
    static void LogUpdateOpenIdConnectionRequest(PFAuthenticationUpdateOpenIdConnectionRequest const* request, const char* testName);
    static void LogUpdatePlayerSharedSecretRequest(PFAuthenticationUpdatePlayerSharedSecretRequest const* request, const char* testName);
    static void LogUpdatePolicyRequest(PFAuthenticationUpdatePolicyRequest const* request, const char* testName);
    static HRESULT LogUpdatePolicyResponse(PFAuthenticationUpdatePolicyResponse const* result);
    static void LogGetPhotonAuthenticationTokenRequest(PFAuthenticationGetPhotonAuthenticationTokenRequest const* request, const char* testName);
    static HRESULT LogGetPhotonAuthenticationTokenResult(PFAuthenticationGetPhotonAuthenticationTokenResult const* result);
    static void LogGetTitlePublicKeyRequest(PFAuthenticationGetTitlePublicKeyRequest const* request, const char* testName);
    static HRESULT LogGetTitlePublicKeyResult(PFAuthenticationGetTitlePublicKeyResult const* result);
    static void LogLoginWithAndroidDeviceIDRequest(PFAuthenticationLoginWithAndroidDeviceIDRequest const* request, const char* testName);
    static HRESULT LogLoginResult(PFAuthenticationLoginResult const* result);
    static void LogLoginWithAppleRequest(PFAuthenticationLoginWithAppleRequest const* request, const char* testName);
    static void LogLoginWithCustomIDRequest(PFAuthenticationLoginWithCustomIDRequest const* request, const char* testName);
    static void LogLoginWithEmailAddressRequest(PFAuthenticationLoginWithEmailAddressRequest const* request, const char* testName);
    static void LogLoginWithFacebookRequest(PFAuthenticationLoginWithFacebookRequest const* request, const char* testName);
    static void LogLoginWithFacebookInstantGamesIdRequest(PFAuthenticationLoginWithFacebookInstantGamesIdRequest const* request, const char* testName);
    static void LogLoginWithGameCenterRequest(PFAuthenticationLoginWithGameCenterRequest const* request, const char* testName);
    static void LogLoginWithGoogleAccountRequest(PFAuthenticationLoginWithGoogleAccountRequest const* request, const char* testName);
    static void LogLoginWithGooglePlayGamesServicesRequest(PFAuthenticationLoginWithGooglePlayGamesServicesRequest const* request, const char* testName);
    static void LogLoginWithIOSDeviceIDRequest(PFAuthenticationLoginWithIOSDeviceIDRequest const* request, const char* testName);
    static void LogLoginWithKongregateRequest(PFAuthenticationLoginWithKongregateRequest const* request, const char* testName);
    static void LogLoginWithNintendoServiceAccountRequest(PFAuthenticationLoginWithNintendoServiceAccountRequest const* request, const char* testName);
    static void LogLoginWithNintendoSwitchDeviceIdRequest(PFAuthenticationLoginWithNintendoSwitchDeviceIdRequest const* request, const char* testName);
    static void LogLoginWithOpenIdConnectRequest(PFAuthenticationLoginWithOpenIdConnectRequest const* request, const char* testName);
    static void LogLoginWithPlayFabRequest(PFAuthenticationLoginWithPlayFabRequest const* request, const char* testName);
    static void LogLoginWithPSNRequest(PFAuthenticationLoginWithPSNRequest const* request, const char* testName);
    static void LogLoginWithSteamRequest(PFAuthenticationLoginWithSteamRequest const* request, const char* testName);
    static void LogLoginWithTwitchRequest(PFAuthenticationLoginWithTwitchRequest const* request, const char* testName);
    static void LogClientLoginWithXboxRequest(PFAuthenticationClientLoginWithXboxRequest const* request, const char* testName);
    static void LogRegisterPlayFabUserRequest(PFAuthenticationRegisterPlayFabUserRequest const* request, const char* testName);
    static HRESULT LogRegisterPlayFabUserResult(PFAuthenticationRegisterPlayFabUserResult const* result);
    static void LogClientSetPlayerSecretRequest(PFAuthenticationClientSetPlayerSecretRequest const* request, const char* testName);
    static void LogAuthenticateSessionTicketRequest(PFAuthenticationAuthenticateSessionTicketRequest const* request, const char* testName);
    static HRESULT LogAuthenticateSessionTicketResult(PFAuthenticationAuthenticateSessionTicketResult const* result);
    static void LogLoginWithServerCustomIdRequest(PFAuthenticationLoginWithServerCustomIdRequest const* request, const char* testName);
    static HRESULT LogServerLoginResult(PFAuthenticationServerLoginResult const* result);
    static void LogLoginWithSteamIdRequest(PFAuthenticationLoginWithSteamIdRequest const* request, const char* testName);
    static void LogServerLoginWithXboxRequest(PFAuthenticationServerLoginWithXboxRequest const* request, const char* testName);
    static void LogLoginWithXboxIdRequest(PFAuthenticationLoginWithXboxIdRequest const* request, const char* testName);
    static void LogServerSetPlayerSecretRequest(PFAuthenticationServerSetPlayerSecretRequest const* request, const char* testName);
    static void LogAuthenticateCustomIdRequest(PFAuthenticationAuthenticateCustomIdRequest const* request, const char* testName);
    static HRESULT LogAuthenticateCustomIdResult(PFAuthenticationAuthenticateCustomIdResult const* result);
    static void LogDeleteRequest(PFAuthenticationDeleteRequest const* request, const char* testName);
    static void LogGetEntityTokenRequest(PFAuthenticationGetEntityTokenRequest const* request, const char* testName);
    static HRESULT LogGetEntityTokenResponse(PFAuthenticationGetEntityTokenResponse const* result);
    static void LogValidateEntityTokenRequest(PFAuthenticationValidateEntityTokenRequest const* request, const char* testName);
    static HRESULT LogValidateEntityTokenResponse(PFAuthenticationValidateEntityTokenResponse const* result);

    void FillAdminCreateOpenIdConnectionRequest(PlayFab::Wrappers::PFAuthenticationCreateOpenIdConnectionRequestWrapper<>& request);

    void FillAdminCreatePlayerSharedSecretRequest(PlayFab::Wrappers::PFAuthenticationCreatePlayerSharedSecretRequestWrapper<>& request);
    static HRESULT ValidateAdminCreatePlayerSharedSecretResponse(PFAuthenticationCreatePlayerSharedSecretResult* result);

    void FillAdminDeleteOpenIdConnectionRequest(PlayFab::Wrappers::PFAuthenticationDeleteOpenIdConnectionRequestWrapper<>& request);

    void FillAdminDeletePlayerSharedSecretRequest(PlayFab::Wrappers::PFAuthenticationDeletePlayerSharedSecretRequestWrapper<>& request);

    static HRESULT ValidateAdminGetPlayerSharedSecretsResponse(PFAuthenticationGetPlayerSharedSecretsResult* result);

    void FillAdminGetPolicyRequest(PlayFab::Wrappers::PFAuthenticationGetPolicyRequestWrapper<>& request);
    static HRESULT ValidateAdminGetPolicyResponse(PFAuthenticationGetPolicyResponse* result);

    static HRESULT ValidateAdminListOpenIdConnectionResponse(PFAuthenticationListOpenIdConnectionResponse* result);

    void FillAdminSetPlayerSecretRequest(PlayFab::Wrappers::PFAuthenticationAdminSetPlayerSecretRequestWrapper<>& request);

    void FillAdminUpdateOpenIdConnectionRequest(PlayFab::Wrappers::PFAuthenticationUpdateOpenIdConnectionRequestWrapper<>& request);

    void FillAdminUpdatePlayerSharedSecretRequest(PlayFab::Wrappers::PFAuthenticationUpdatePlayerSharedSecretRequestWrapper<>& request);

    void FillAdminUpdatePolicyRequest(PlayFab::Wrappers::PFAuthenticationUpdatePolicyRequestWrapper<>& request);
    static HRESULT ValidateAdminUpdatePolicyResponse(PFAuthenticationUpdatePolicyResponse* result);

    void FillClientGetPhotonAuthenticationTokenRequest(PlayFab::Wrappers::PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper<>& request);
    static HRESULT ValidateClientGetPhotonAuthenticationTokenResponse(PFAuthenticationGetPhotonAuthenticationTokenResult* result);

    void FillClientGetTitlePublicKeyRequest(PlayFab::Wrappers::PFAuthenticationGetTitlePublicKeyRequestWrapper<>& request);
    static HRESULT ValidateClientGetTitlePublicKeyResponse(PFAuthenticationGetTitlePublicKeyResult* result);

    void FillClientLoginWithAndroidDeviceIDRequest(PlayFab::Wrappers::PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithAndroidDeviceIDResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithAppleRequest(PlayFab::Wrappers::PFAuthenticationLoginWithAppleRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithAppleResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithCustomIDRequest(PlayFab::Wrappers::PFAuthenticationLoginWithCustomIDRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithCustomIDResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithEmailAddressRequest(PlayFab::Wrappers::PFAuthenticationLoginWithEmailAddressRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithEmailAddressResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithFacebookRequest(PlayFab::Wrappers::PFAuthenticationLoginWithFacebookRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithFacebookResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithFacebookInstantGamesIdRequest(PlayFab::Wrappers::PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithFacebookInstantGamesIdResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithGameCenterRequest(PlayFab::Wrappers::PFAuthenticationLoginWithGameCenterRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithGameCenterResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithGoogleAccountRequest(PlayFab::Wrappers::PFAuthenticationLoginWithGoogleAccountRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithGoogleAccountResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithGooglePlayGamesServicesRequest(PlayFab::Wrappers::PFAuthenticationLoginWithGooglePlayGamesServicesRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithGooglePlayGamesServicesResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithIOSDeviceIDRequest(PlayFab::Wrappers::PFAuthenticationLoginWithIOSDeviceIDRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithIOSDeviceIDResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithKongregateRequest(PlayFab::Wrappers::PFAuthenticationLoginWithKongregateRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithKongregateResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithNintendoServiceAccountRequest(PlayFab::Wrappers::PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithNintendoServiceAccountResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithNintendoSwitchDeviceIdRequest(PlayFab::Wrappers::PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithNintendoSwitchDeviceIdResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithOpenIdConnectRequest(PlayFab::Wrappers::PFAuthenticationLoginWithOpenIdConnectRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithOpenIdConnectResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithPlayFabRequest(PlayFab::Wrappers::PFAuthenticationLoginWithPlayFabRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithPlayFabResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithPSNRequest(PlayFab::Wrappers::PFAuthenticationLoginWithPSNRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithPSNResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithSteamRequest(PlayFab::Wrappers::PFAuthenticationLoginWithSteamRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithSteamResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithTwitchRequest(PlayFab::Wrappers::PFAuthenticationLoginWithTwitchRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithTwitchResponse(PFAuthenticationLoginResult* result);

    void FillClientLoginWithXboxRequest(PlayFab::Wrappers::PFAuthenticationClientLoginWithXboxRequestWrapper<>& request);
    static HRESULT ValidateClientLoginWithXboxResponse(PFAuthenticationLoginResult* result);

    void FillClientRegisterPlayFabUserRequest(PlayFab::Wrappers::PFAuthenticationRegisterPlayFabUserRequestWrapper<>& request);
    static HRESULT ValidateClientRegisterPlayFabUserResponse(PFAuthenticationRegisterPlayFabUserResult* result);

    void FillClientSetPlayerSecretRequest(PlayFab::Wrappers::PFAuthenticationClientSetPlayerSecretRequestWrapper<>& request);

    void FillServerAuthenticateSessionTicketRequest(PlayFab::Wrappers::PFAuthenticationAuthenticateSessionTicketRequestWrapper<>& request);
    static HRESULT ValidateServerAuthenticateSessionTicketResponse(PFAuthenticationAuthenticateSessionTicketResult* result);

    void FillServerLoginWithServerCustomIdRequest(PlayFab::Wrappers::PFAuthenticationLoginWithServerCustomIdRequestWrapper<>& request);
    static HRESULT ValidateServerLoginWithServerCustomIdResponse(PFAuthenticationServerLoginResult* result);

    void FillServerLoginWithSteamIdRequest(PlayFab::Wrappers::PFAuthenticationLoginWithSteamIdRequestWrapper<>& request);
    static HRESULT ValidateServerLoginWithSteamIdResponse(PFAuthenticationServerLoginResult* result);

    void FillServerLoginWithXboxRequest(PlayFab::Wrappers::PFAuthenticationServerLoginWithXboxRequestWrapper<>& request);
    static HRESULT ValidateServerLoginWithXboxResponse(PFAuthenticationServerLoginResult* result);

    void FillServerLoginWithXboxIdRequest(PlayFab::Wrappers::PFAuthenticationLoginWithXboxIdRequestWrapper<>& request);
    static HRESULT ValidateServerLoginWithXboxIdResponse(PFAuthenticationServerLoginResult* result);

    void FillServerSetPlayerSecretRequest(PlayFab::Wrappers::PFAuthenticationServerSetPlayerSecretRequestWrapper<>& request);

    void FillAuthenticateGameServerWithCustomIdRequest(PlayFab::Wrappers::PFAuthenticationAuthenticateCustomIdRequestWrapper<>& request);
    static HRESULT ValidateAuthenticateGameServerWithCustomIdResponse(PFAuthenticationAuthenticateCustomIdResult* result);

    void FillDeleteRequest(PlayFab::Wrappers::PFAuthenticationDeleteRequestWrapper<>& request);

    void FillGetEntityTokenRequest(PlayFab::Wrappers::PFAuthenticationGetEntityTokenRequestWrapper<>& request);
    static HRESULT ValidateGetEntityTokenResponse(PFAuthenticationGetEntityTokenResponse* result);

    void FillValidateEntityTokenRequest(PlayFab::Wrappers::PFAuthenticationValidateEntityTokenRequestWrapper<>& request);
    static HRESULT ValidateValidateEntityTokenResponse(PFAuthenticationValidateEntityTokenResponse* result);

    struct AuthenticationTestData
    {
        ~AuthenticationTestData() = default;

    };

    static AuthenticationTestData testData;

public:
    PFStateHandle stateHandle{ nullptr };
    PFTitlePlayerHandle titlePlayerHandle{ nullptr };
    PFEntityHandle entityHandle{ nullptr };
    PFTitlePlayerHandle titlePlayerHandle2{ nullptr };
    PFEntityHandle entityHandle2{ nullptr };
    PFEntityHandle titleEntityHandle{ nullptr };

    void ClassSetUp() override;
    void ClassTearDown() override;
    void SetUp(TestContext& testContext) override;

    void Tick(TestContext&) override {}
};

}
