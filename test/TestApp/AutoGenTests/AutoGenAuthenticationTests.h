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

    void TestAuthenticationAdminCreateOpenIdConnection(TestContext& testContext);

    void TestAuthenticationAdminCreatePlayerSharedSecret(TestContext& testContext);

    void TestAuthenticationAdminDeleteOpenIdConnection(TestContext& testContext);

    void TestAuthenticationAdminDeletePlayerSharedSecret(TestContext& testContext);

    void TestAuthenticationAdminGetPlayerSharedSecrets(TestContext& testContext);

    void TestAuthenticationAdminGetPolicy(TestContext& testContext);

    void TestAuthenticationAdminListOpenIdConnection(TestContext& testContext);

    void TestAuthenticationAdminSetPlayerSecret(TestContext& testContext);

    void TestAuthenticationAdminUpdateOpenIdConnection(TestContext& testContext);

    void TestAuthenticationAdminUpdatePlayerSharedSecret(TestContext& testContext);

    void TestAuthenticationAdminUpdatePolicy(TestContext& testContext);

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

    void TestAuthenticationServerAuthenticateSessionTicket(TestContext& testContext);

    void TestAuthenticationServerLoginWithServerCustomId(TestContext& testContext);

    void TestAuthenticationServerLoginWithSteamId(TestContext& testContext);

    void TestAuthenticationServerLoginWithXbox(TestContext& testContext);

    void TestAuthenticationServerLoginWithXboxId(TestContext& testContext);

    void TestAuthenticationServerSetPlayerSecret(TestContext& testContext);

    void TestAuthenticationGetEntityToken(TestContext& testContext);

    void TestAuthenticationValidateEntityToken(TestContext& testContext);


protected:
    void AddTests();

    static void LogCreateOpenIdConnectionRequest(PFAuthenticationCreateOpenIdConnectionRequest const* request, const char* testName);
    static void FillCreateOpenIdConnectionRequest(PlayFab::Wrappers::PFAuthenticationCreateOpenIdConnectionRequestWrapper<>& request);

    static void LogCreatePlayerSharedSecretRequest(PFAuthenticationCreatePlayerSharedSecretRequest const* request, const char* testName);
    static void FillCreatePlayerSharedSecretRequest(PlayFab::Wrappers::PFAuthenticationCreatePlayerSharedSecretRequestWrapper<>& request);
    static HRESULT LogPFAuthenticationCreatePlayerSharedSecretResult(PFAuthenticationCreatePlayerSharedSecretResult const* result);
    static HRESULT ValidatePFAuthenticationCreatePlayerSharedSecretResult(PFAuthenticationCreatePlayerSharedSecretResult* result);

    static void LogDeleteOpenIdConnectionRequest(PFAuthenticationDeleteOpenIdConnectionRequest const* request, const char* testName);
    static void FillDeleteOpenIdConnectionRequest(PlayFab::Wrappers::PFAuthenticationDeleteOpenIdConnectionRequestWrapper<>& request);

    static void LogDeletePlayerSharedSecretRequest(PFAuthenticationDeletePlayerSharedSecretRequest const* request, const char* testName);
    static void FillDeletePlayerSharedSecretRequest(PlayFab::Wrappers::PFAuthenticationDeletePlayerSharedSecretRequestWrapper<>& request);

    static HRESULT LogPFAuthenticationGetPlayerSharedSecretsResult(PFAuthenticationGetPlayerSharedSecretsResult const* result);
    static HRESULT ValidatePFAuthenticationGetPlayerSharedSecretsResult(PFAuthenticationGetPlayerSharedSecretsResult* result);

    static void LogGetPolicyRequest(PFAuthenticationGetPolicyRequest const* request, const char* testName);
    static void FillGetPolicyRequest(PlayFab::Wrappers::PFAuthenticationGetPolicyRequestWrapper<>& request);
    static HRESULT LogPFAuthenticationGetPolicyResponse(PFAuthenticationGetPolicyResponse const* result);
    static HRESULT ValidatePFAuthenticationGetPolicyResponse(PFAuthenticationGetPolicyResponse* result);

    static HRESULT LogPFAuthenticationListOpenIdConnectionResponse(PFAuthenticationListOpenIdConnectionResponse const* result);
    static HRESULT ValidatePFAuthenticationListOpenIdConnectionResponse(PFAuthenticationListOpenIdConnectionResponse* result);

    static void LogAdminSetPlayerSecretRequest(PFAuthenticationAdminSetPlayerSecretRequest const* request, const char* testName);
    static void FillAdminSetPlayerSecretRequest(PlayFab::Wrappers::PFAuthenticationAdminSetPlayerSecretRequestWrapper<>& request);

    static void LogUpdateOpenIdConnectionRequest(PFAuthenticationUpdateOpenIdConnectionRequest const* request, const char* testName);
    static void FillUpdateOpenIdConnectionRequest(PlayFab::Wrappers::PFAuthenticationUpdateOpenIdConnectionRequestWrapper<>& request);

    static void LogUpdatePlayerSharedSecretRequest(PFAuthenticationUpdatePlayerSharedSecretRequest const* request, const char* testName);
    static void FillUpdatePlayerSharedSecretRequest(PlayFab::Wrappers::PFAuthenticationUpdatePlayerSharedSecretRequestWrapper<>& request);

    static void LogUpdatePolicyRequest(PFAuthenticationUpdatePolicyRequest const* request, const char* testName);
    static void FillUpdatePolicyRequest(PlayFab::Wrappers::PFAuthenticationUpdatePolicyRequestWrapper<>& request);
    static HRESULT LogPFAuthenticationUpdatePolicyResponse(PFAuthenticationUpdatePolicyResponse const* result);
    static HRESULT ValidatePFAuthenticationUpdatePolicyResponse(PFAuthenticationUpdatePolicyResponse* result);

    static void LogGetPhotonAuthenticationTokenRequest(PFAuthenticationGetPhotonAuthenticationTokenRequest const* request, const char* testName);
    static void FillGetPhotonAuthenticationTokenRequest(PlayFab::Wrappers::PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper<>& request);
    static HRESULT LogPFAuthenticationGetPhotonAuthenticationTokenResult(PFAuthenticationGetPhotonAuthenticationTokenResult const* result);
    static HRESULT ValidatePFAuthenticationGetPhotonAuthenticationTokenResult(PFAuthenticationGetPhotonAuthenticationTokenResult* result);

    static void LogGetTitlePublicKeyRequest(PFAuthenticationGetTitlePublicKeyRequest const* request, const char* testName);
    static void FillGetTitlePublicKeyRequest(PlayFab::Wrappers::PFAuthenticationGetTitlePublicKeyRequestWrapper<>& request);
    static HRESULT LogPFAuthenticationGetTitlePublicKeyResult(PFAuthenticationGetTitlePublicKeyResult const* result);
    static HRESULT ValidatePFAuthenticationGetTitlePublicKeyResult(PFAuthenticationGetTitlePublicKeyResult* result);

    static void LogLoginWithAndroidDeviceIDRequest(PFAuthenticationLoginWithAndroidDeviceIDRequest const* request, const char* testName);
    static void FillLoginWithAndroidDeviceIDRequest(PlayFab::Wrappers::PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper<>& request);
    static HRESULT LogPFAuthenticationLoginResult(PFAuthenticationLoginResult const* result);
    static HRESULT ValidatePFAuthenticationLoginResult(PFAuthenticationLoginResult* result);

    static void LogLoginWithAppleRequest(PFAuthenticationLoginWithAppleRequest const* request, const char* testName);
    static void FillLoginWithAppleRequest(PlayFab::Wrappers::PFAuthenticationLoginWithAppleRequestWrapper<>& request);

    static void LogLoginWithCustomIDRequest(PFAuthenticationLoginWithCustomIDRequest const* request, const char* testName);
    static void FillLoginWithCustomIDRequest(PlayFab::Wrappers::PFAuthenticationLoginWithCustomIDRequestWrapper<>& request);

    static void LogLoginWithEmailAddressRequest(PFAuthenticationLoginWithEmailAddressRequest const* request, const char* testName);
    static void FillLoginWithEmailAddressRequest(PlayFab::Wrappers::PFAuthenticationLoginWithEmailAddressRequestWrapper<>& request);

    static void LogLoginWithFacebookRequest(PFAuthenticationLoginWithFacebookRequest const* request, const char* testName);
    static void FillLoginWithFacebookRequest(PlayFab::Wrappers::PFAuthenticationLoginWithFacebookRequestWrapper<>& request);

    static void LogLoginWithFacebookInstantGamesIdRequest(PFAuthenticationLoginWithFacebookInstantGamesIdRequest const* request, const char* testName);
    static void FillLoginWithFacebookInstantGamesIdRequest(PlayFab::Wrappers::PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper<>& request);

    static void LogLoginWithGameCenterRequest(PFAuthenticationLoginWithGameCenterRequest const* request, const char* testName);
    static void FillLoginWithGameCenterRequest(PlayFab::Wrappers::PFAuthenticationLoginWithGameCenterRequestWrapper<>& request);

    static void LogLoginWithGoogleAccountRequest(PFAuthenticationLoginWithGoogleAccountRequest const* request, const char* testName);
    static void FillLoginWithGoogleAccountRequest(PlayFab::Wrappers::PFAuthenticationLoginWithGoogleAccountRequestWrapper<>& request);

    static void LogLoginWithIOSDeviceIDRequest(PFAuthenticationLoginWithIOSDeviceIDRequest const* request, const char* testName);
    static void FillLoginWithIOSDeviceIDRequest(PlayFab::Wrappers::PFAuthenticationLoginWithIOSDeviceIDRequestWrapper<>& request);

    static void LogLoginWithKongregateRequest(PFAuthenticationLoginWithKongregateRequest const* request, const char* testName);
    static void FillLoginWithKongregateRequest(PlayFab::Wrappers::PFAuthenticationLoginWithKongregateRequestWrapper<>& request);

    static void LogLoginWithNintendoServiceAccountRequest(PFAuthenticationLoginWithNintendoServiceAccountRequest const* request, const char* testName);
    static void FillLoginWithNintendoServiceAccountRequest(PlayFab::Wrappers::PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper<>& request);

    static void LogLoginWithNintendoSwitchDeviceIdRequest(PFAuthenticationLoginWithNintendoSwitchDeviceIdRequest const* request, const char* testName);
    static void FillLoginWithNintendoSwitchDeviceIdRequest(PlayFab::Wrappers::PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper<>& request);

    static void LogLoginWithOpenIdConnectRequest(PFAuthenticationLoginWithOpenIdConnectRequest const* request, const char* testName);
    static void FillLoginWithOpenIdConnectRequest(PlayFab::Wrappers::PFAuthenticationLoginWithOpenIdConnectRequestWrapper<>& request);

    static void LogLoginWithPlayFabRequest(PFAuthenticationLoginWithPlayFabRequest const* request, const char* testName);
    static void FillLoginWithPlayFabRequest(PlayFab::Wrappers::PFAuthenticationLoginWithPlayFabRequestWrapper<>& request);

    static void LogLoginWithPSNRequest(PFAuthenticationLoginWithPSNRequest const* request, const char* testName);
    static void FillLoginWithPSNRequest(PlayFab::Wrappers::PFAuthenticationLoginWithPSNRequestWrapper<>& request);

    static void LogLoginWithSteamRequest(PFAuthenticationLoginWithSteamRequest const* request, const char* testName);
    static void FillLoginWithSteamRequest(PlayFab::Wrappers::PFAuthenticationLoginWithSteamRequestWrapper<>& request);

    static void LogLoginWithTwitchRequest(PFAuthenticationLoginWithTwitchRequest const* request, const char* testName);
    static void FillLoginWithTwitchRequest(PlayFab::Wrappers::PFAuthenticationLoginWithTwitchRequestWrapper<>& request);

    static void LogClientLoginWithXboxRequest(PFAuthenticationClientLoginWithXboxRequest const* request, const char* testName);
    static void FillClientLoginWithXboxRequest(PlayFab::Wrappers::PFAuthenticationClientLoginWithXboxRequestWrapper<>& request);

    static void LogRegisterPlayFabUserRequest(PFAuthenticationRegisterPlayFabUserRequest const* request, const char* testName);
    static void FillRegisterPlayFabUserRequest(PlayFab::Wrappers::PFAuthenticationRegisterPlayFabUserRequestWrapper<>& request);
    static HRESULT LogPFAuthenticationRegisterPlayFabUserResult(PFAuthenticationRegisterPlayFabUserResult const* result);
    static HRESULT ValidatePFAuthenticationRegisterPlayFabUserResult(PFAuthenticationRegisterPlayFabUserResult* result);

    static void LogClientSetPlayerSecretRequest(PFAuthenticationClientSetPlayerSecretRequest const* request, const char* testName);
    static void FillClientSetPlayerSecretRequest(PlayFab::Wrappers::PFAuthenticationClientSetPlayerSecretRequestWrapper<>& request);

    static void LogAuthenticateSessionTicketRequest(PFAuthenticationAuthenticateSessionTicketRequest const* request, const char* testName);
    static void FillAuthenticateSessionTicketRequest(PlayFab::Wrappers::PFAuthenticationAuthenticateSessionTicketRequestWrapper<>& request);
    static HRESULT LogPFAuthenticationAuthenticateSessionTicketResult(PFAuthenticationAuthenticateSessionTicketResult const* result);
    static HRESULT ValidatePFAuthenticationAuthenticateSessionTicketResult(PFAuthenticationAuthenticateSessionTicketResult* result);

    static void LogLoginWithServerCustomIdRequest(PFAuthenticationLoginWithServerCustomIdRequest const* request, const char* testName);
    static void FillLoginWithServerCustomIdRequest(PlayFab::Wrappers::PFAuthenticationLoginWithServerCustomIdRequestWrapper<>& request);
    static HRESULT LogPFAuthenticationServerLoginResult(PFAuthenticationServerLoginResult const* result);
    static HRESULT ValidatePFAuthenticationServerLoginResult(PFAuthenticationServerLoginResult* result);

    static void LogLoginWithSteamIdRequest(PFAuthenticationLoginWithSteamIdRequest const* request, const char* testName);
    static void FillLoginWithSteamIdRequest(PlayFab::Wrappers::PFAuthenticationLoginWithSteamIdRequestWrapper<>& request);

    static void LogServerLoginWithXboxRequest(PFAuthenticationServerLoginWithXboxRequest const* request, const char* testName);
    static void FillServerLoginWithXboxRequest(PlayFab::Wrappers::PFAuthenticationServerLoginWithXboxRequestWrapper<>& request);

    static void LogLoginWithXboxIdRequest(PFAuthenticationLoginWithXboxIdRequest const* request, const char* testName);
    static void FillLoginWithXboxIdRequest(PlayFab::Wrappers::PFAuthenticationLoginWithXboxIdRequestWrapper<>& request);

    static void LogServerSetPlayerSecretRequest(PFAuthenticationServerSetPlayerSecretRequest const* request, const char* testName);
    static void FillServerSetPlayerSecretRequest(PlayFab::Wrappers::PFAuthenticationServerSetPlayerSecretRequestWrapper<>& request);

    static void LogGetEntityTokenRequest(PFAuthenticationGetEntityTokenRequest const* request, const char* testName);
    static void FillGetEntityTokenRequest(PlayFab::Wrappers::PFAuthenticationGetEntityTokenRequestWrapper<>& request);
    static HRESULT LogPFAuthenticationGetEntityTokenResponse(PFAuthenticationGetEntityTokenResponse const* result);
    static HRESULT ValidatePFAuthenticationGetEntityTokenResponse(PFAuthenticationGetEntityTokenResponse* result);

    static void LogValidateEntityTokenRequest(PFAuthenticationValidateEntityTokenRequest const* request, const char* testName);
    static void FillValidateEntityTokenRequest(PlayFab::Wrappers::PFAuthenticationValidateEntityTokenRequestWrapper<>& request);
    static HRESULT LogPFAuthenticationValidateEntityTokenResponse(PFAuthenticationValidateEntityTokenResponse const* result);
    static HRESULT ValidatePFAuthenticationValidateEntityTokenResponse(PFAuthenticationValidateEntityTokenResponse* result);

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
