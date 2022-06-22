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

    void TestAuthenticationAuthenticateWithCustomId(TestContext& testContext);

    void TestAuthenticationGetLinkedPlayerIdentities(TestContext& testContext);

    void TestAuthenticationUnlinkPlayerIdentity(TestContext& testContext);

    void TestAuthenticationLoginPlayer(TestContext& testContext);


protected:
    void AddTests();

    static void LogAuthenticateCustomIdIdentityRequest(PFAuthenticationAuthenticateCustomIdIdentityRequest const* request, const char* testName);
    static HRESULT LogAuthenticateIdentityResult(PFAuthenticationAuthenticateIdentityResult const* result);
    static void LogGetLinkedPlayerIdentitiesRequest(PFAuthenticationGetLinkedPlayerIdentitiesRequest const* request, const char* testName);
    static HRESULT LogGetLinkedPlayerIdentitiesResult(PFAuthenticationGetLinkedPlayerIdentitiesResult const* result);
    static void LogUnlinkPlayerIdentityRequest(PFAuthenticationUnlinkPlayerIdentityRequest const* request, const char* testName);
    static void LogLoginPlayerRequest(PFAuthenticationLoginPlayerRequest const* request, const char* testName);
    static HRESULT LogLoginPlayerResult(PFAuthenticationLoginPlayerResult const* result);

    static void FillAuthenticateWithCustomIdRequest(PlayFab::Wrappers::PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper<>& request);
    static HRESULT ValidateAuthenticateWithCustomIdResponse(PFAuthenticationAuthenticateIdentityResult* result);

    static void FillGetLinkedPlayerIdentitiesRequest(PlayFab::Wrappers::PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper<>& request);
    static HRESULT ValidateGetLinkedPlayerIdentitiesResponse(PFAuthenticationGetLinkedPlayerIdentitiesResult* result);

    static void FillUnlinkPlayerIdentityRequest(PlayFab::Wrappers::PFAuthenticationUnlinkPlayerIdentityRequestWrapper<>& request);

    static void FillLoginPlayerRequest(PlayFab::Wrappers::PFAuthenticationLoginPlayerRequestWrapper<>& request);
    static HRESULT ValidateLoginPlayerResponse(PFAuthenticationLoginPlayerResult* result);

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
