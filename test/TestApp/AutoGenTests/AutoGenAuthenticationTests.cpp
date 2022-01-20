#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenAuthenticationTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenAuthenticationTests::AuthenticationTestData AutoGenAuthenticationTests::testData;

void AutoGenAuthenticationTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenAuthenticationTests::LogHR(HRESULT hr)
{
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenAuthenticationTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAuthenticationAdminCreateOpenIdConnection", &AutoGenAuthenticationTests::TestAuthenticationAdminCreateOpenIdConnection);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAuthenticationAdminCreatePlayerSharedSecret", &AutoGenAuthenticationTests::TestAuthenticationAdminCreatePlayerSharedSecret);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAuthenticationAdminDeleteOpenIdConnection", &AutoGenAuthenticationTests::TestAuthenticationAdminDeleteOpenIdConnection);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAuthenticationAdminDeletePlayerSharedSecret", &AutoGenAuthenticationTests::TestAuthenticationAdminDeletePlayerSharedSecret);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAuthenticationAdminGetPlayerSharedSecrets", &AutoGenAuthenticationTests::TestAuthenticationAdminGetPlayerSharedSecrets);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAuthenticationAdminGetPolicy", &AutoGenAuthenticationTests::TestAuthenticationAdminGetPolicy);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAuthenticationAdminListOpenIdConnection", &AutoGenAuthenticationTests::TestAuthenticationAdminListOpenIdConnection);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAuthenticationAdminSetPlayerSecret", &AutoGenAuthenticationTests::TestAuthenticationAdminSetPlayerSecret);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAuthenticationAdminUpdateOpenIdConnection", &AutoGenAuthenticationTests::TestAuthenticationAdminUpdateOpenIdConnection);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAuthenticationAdminUpdatePlayerSharedSecret", &AutoGenAuthenticationTests::TestAuthenticationAdminUpdatePlayerSharedSecret);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAuthenticationAdminUpdatePolicy", &AutoGenAuthenticationTests::TestAuthenticationAdminUpdatePolicy);
#endif

    AddTest("TestAuthenticationClientGetPhotonAuthenticationToken", &AutoGenAuthenticationTests::TestAuthenticationClientGetPhotonAuthenticationToken);

    AddTest("TestAuthenticationClientGetTitlePublicKey", &AutoGenAuthenticationTests::TestAuthenticationClientGetTitlePublicKey);

    AddTest("TestAuthenticationClientLoginWithAndroidDeviceID", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithAndroidDeviceID);

    AddTest("TestAuthenticationClientLoginWithApple", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithApple);

    AddTest("TestAuthenticationClientLoginWithCustomID", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithCustomID);

    AddTest("TestAuthenticationClientLoginWithEmailAddress", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithEmailAddress);

    AddTest("TestAuthenticationClientLoginWithFacebook", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithFacebook);

    AddTest("TestAuthenticationClientLoginWithFacebookInstantGamesId", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithFacebookInstantGamesId);

    AddTest("TestAuthenticationClientLoginWithGameCenter", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithGameCenter);

    AddTest("TestAuthenticationClientLoginWithGoogleAccount", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithGoogleAccount);

    AddTest("TestAuthenticationClientLoginWithIOSDeviceID", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithIOSDeviceID);

    AddTest("TestAuthenticationClientLoginWithKongregate", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithKongregate);

    AddTest("TestAuthenticationClientLoginWithNintendoServiceAccount", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithNintendoServiceAccount);

    AddTest("TestAuthenticationClientLoginWithNintendoSwitchDeviceId", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithNintendoSwitchDeviceId);

    AddTest("TestAuthenticationClientLoginWithOpenIdConnect", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithOpenIdConnect);

    AddTest("TestAuthenticationClientLoginWithPlayFab", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithPlayFab);

    AddTest("TestAuthenticationClientLoginWithPSN", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithPSN);

    AddTest("TestAuthenticationClientLoginWithSteam", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithSteam);

    AddTest("TestAuthenticationClientLoginWithTwitch", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithTwitch);

    AddTest("TestAuthenticationClientLoginWithXbox", &AutoGenAuthenticationTests::TestAuthenticationClientLoginWithXbox);

    AddTest("TestAuthenticationClientRegisterPlayFabUser", &AutoGenAuthenticationTests::TestAuthenticationClientRegisterPlayFabUser);

    AddTest("TestAuthenticationClientSetPlayerSecret", &AutoGenAuthenticationTests::TestAuthenticationClientSetPlayerSecret);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAuthenticationServerAuthenticateSessionTicket", &AutoGenAuthenticationTests::TestAuthenticationServerAuthenticateSessionTicket);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAuthenticationServerLoginWithServerCustomId", &AutoGenAuthenticationTests::TestAuthenticationServerLoginWithServerCustomId);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAuthenticationServerLoginWithSteamId", &AutoGenAuthenticationTests::TestAuthenticationServerLoginWithSteamId);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAuthenticationServerLoginWithXbox", &AutoGenAuthenticationTests::TestAuthenticationServerLoginWithXbox);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAuthenticationServerLoginWithXboxId", &AutoGenAuthenticationTests::TestAuthenticationServerLoginWithXboxId);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAuthenticationServerSetPlayerSecret", &AutoGenAuthenticationTests::TestAuthenticationServerSetPlayerSecret);
#endif

    AddTest("TestAuthenticationGetEntityToken", &AutoGenAuthenticationTests::TestAuthenticationGetEntityToken);

    AddTest("TestAuthenticationValidateEntityToken", &AutoGenAuthenticationTests::TestAuthenticationValidateEntityToken);
}

void AutoGenAuthenticationTests::ClassSetUp()
{
    HRESULT hr = PFAdminInitialize(testTitleData.titleId.data(), testTitleData.developerSecretKey.data(), testTitleData.connectionString.data(), nullptr, &stateHandle);
    assert(SUCCEEDED(hr));
    if (SUCCEEDED(hr))
    {
        PFAuthenticationLoginWithCustomIDRequest request{};
        request.customId = "CustomId";
        request.createAccount = true;

        PFGetPlayerCombinedInfoRequestParams combinedInfoRequestParams{};
        combinedInfoRequestParams.getCharacterInventories = true;
        combinedInfoRequestParams.getCharacterList = true;
        combinedInfoRequestParams.getPlayerProfile = true;
        combinedInfoRequestParams.getPlayerStatistics = true;
        combinedInfoRequestParams.getTitleData = true;
        combinedInfoRequestParams.getUserAccountInfo = true;
        combinedInfoRequestParams.getUserData = true;
        combinedInfoRequestParams.getUserInventory = true;
        combinedInfoRequestParams.getUserReadOnlyData = true;
        combinedInfoRequestParams.getUserVirtualCurrency = true;
        request.infoRequestParameters = &combinedInfoRequestParams;

        XAsyncBlock async{};
        hr = PFAuthenticationClientLoginWithCustomIDAsync(stateHandle, &request, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously wait for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationClientLoginGetResult(&async, &titlePlayerHandle);
                assert(SUCCEEDED(hr) && titlePlayerHandle);

                hr = PFTitlePlayerGetEntityHandle(titlePlayerHandle, &entityHandle);
                assert(SUCCEEDED(hr) && entityHandle);
            }
        }

        request.customId = "CustomId2";
        async = {};
        hr = PFAuthenticationClientLoginWithCustomIDAsync(stateHandle, &request, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously what for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationClientLoginGetResult(&async, &titlePlayerHandle2);
                assert(SUCCEEDED(hr) && titlePlayerHandle2);

                hr = PFTitlePlayerGetEntityHandle(titlePlayerHandle2, &entityHandle2);
                assert(SUCCEEDED(hr) && entityHandle2);
            }
        }

        PFAuthenticationGetEntityTokenRequest titleTokenRequest{};
        async = {};
        hr = PFAuthenticationGetEntityTokenAsync(stateHandle, &titleTokenRequest, &async);
        assert(SUCCEEDED(hr));
        if (SUCCEEDED(hr))
        {
            // Synchronously wait for login to complete
            hr = XAsyncGetStatus(&async, true);
            assert(SUCCEEDED(hr));
            
            if (SUCCEEDED(hr))
            {
                hr = PFAuthenticationGetEntityTokenGetResult(&async, &titleEntityHandle);
                assert(SUCCEEDED(hr));
            }
        }
    }
}

void AutoGenAuthenticationTests::ClassTearDown()
{
    PFTitlePlayerCloseHandle(titlePlayerHandle);
    PFEntityCloseHandle(entityHandle);
    PFEntityCloseHandle(titleEntityHandle);

    XAsyncBlock async{};
    HRESULT hr = PFUninitializeAsync(stateHandle, &async);
    assert(SUCCEEDED(hr));

    hr = XAsyncGetStatus(&async, true);
    assert(SUCCEEDED(hr));

    UNREFERENCED_PARAMETER(hr);
}

void AutoGenAuthenticationTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AdminCreateOpenIdConnection

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAuthenticationTests::TestAuthenticationAdminCreateOpenIdConnection(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAuthenticationCreateOpenIdConnectionRequestWrapper<> request;
    FillAdminCreateOpenIdConnectionRequest(request);
    LogCreateOpenIdConnectionRequest(&request.Model(), "TestAuthenticationAdminCreateOpenIdConnection");
    HRESULT hr = PFAuthenticationAdminCreateOpenIdConnectionAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminCreateOpenIdConnectionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminCreatePlayerSharedSecret

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAuthenticationTests::TestAuthenticationAdminCreatePlayerSharedSecret(TestContext& testContext)
{
    struct AdminCreatePlayerSharedSecretResultHolderStruct : public CreatePlayerSharedSecretResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminCreatePlayerSharedSecretGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminCreatePlayerSharedSecretGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogCreatePlayerSharedSecretResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminCreatePlayerSharedSecretResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminCreatePlayerSharedSecretResultHolderStruct>>(testContext);

    PFAuthenticationCreatePlayerSharedSecretRequestWrapper<> request;
    FillAdminCreatePlayerSharedSecretRequest(request);
    LogCreatePlayerSharedSecretRequest(&request.Model(), "TestAuthenticationAdminCreatePlayerSharedSecret");
    HRESULT hr = PFAuthenticationAdminCreatePlayerSharedSecretAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminCreatePlayerSharedSecretAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminDeleteOpenIdConnection

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAuthenticationTests::TestAuthenticationAdminDeleteOpenIdConnection(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAuthenticationDeleteOpenIdConnectionRequestWrapper<> request;
    FillAdminDeleteOpenIdConnectionRequest(request);
    LogDeleteOpenIdConnectionRequest(&request.Model(), "TestAuthenticationAdminDeleteOpenIdConnection");
    HRESULT hr = PFAuthenticationAdminDeleteOpenIdConnectionAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminDeleteOpenIdConnectionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminDeletePlayerSharedSecret

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAuthenticationTests::TestAuthenticationAdminDeletePlayerSharedSecret(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAuthenticationDeletePlayerSharedSecretRequestWrapper<> request;
    FillAdminDeletePlayerSharedSecretRequest(request);
    LogDeletePlayerSharedSecretRequest(&request.Model(), "TestAuthenticationAdminDeletePlayerSharedSecret");
    HRESULT hr = PFAuthenticationAdminDeletePlayerSharedSecretAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminDeletePlayerSharedSecretAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetPlayerSharedSecrets

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAuthenticationTests::TestAuthenticationAdminGetPlayerSharedSecrets(TestContext& testContext)
{
    struct AdminGetPlayerSharedSecretsResultHolderStruct : public GetPlayerSharedSecretsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminGetPlayerSharedSecretsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminGetPlayerSharedSecretsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetPlayerSharedSecretsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetPlayerSharedSecretsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetPlayerSharedSecretsResultHolderStruct>>(testContext);

    HRESULT hr = PFAuthenticationAdminGetPlayerSharedSecretsAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminGetPlayerSharedSecretsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetPolicy

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAuthenticationTests::TestAuthenticationAdminGetPolicy(TestContext& testContext)
{
    struct AdminGetPolicyResultHolderStruct : public GetPolicyResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminGetPolicyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminGetPolicyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetPolicyResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetPolicyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetPolicyResultHolderStruct>>(testContext);

    PFAuthenticationGetPolicyRequestWrapper<> request;
    FillAdminGetPolicyRequest(request);
    LogGetPolicyRequest(&request.Model(), "TestAuthenticationAdminGetPolicy");
    HRESULT hr = PFAuthenticationAdminGetPolicyAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminGetPolicyAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminListOpenIdConnection

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAuthenticationTests::TestAuthenticationAdminListOpenIdConnection(TestContext& testContext)
{
    struct AdminListOpenIdConnectionResultHolderStruct : public ListOpenIdConnectionResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminListOpenIdConnectionGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminListOpenIdConnectionGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListOpenIdConnectionResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminListOpenIdConnectionResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminListOpenIdConnectionResultHolderStruct>>(testContext);

    HRESULT hr = PFAuthenticationAdminListOpenIdConnectionAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminListOpenIdConnectionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminSetPlayerSecret

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAuthenticationTests::TestAuthenticationAdminSetPlayerSecret(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAuthenticationAdminSetPlayerSecretRequestWrapper<> request;
    FillAdminSetPlayerSecretRequest(request);
    LogAdminSetPlayerSecretRequest(&request.Model(), "TestAuthenticationAdminSetPlayerSecret");
    HRESULT hr = PFAuthenticationAdminSetPlayerSecretAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminSetPlayerSecretAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdateOpenIdConnection

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAuthenticationTests::TestAuthenticationAdminUpdateOpenIdConnection(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAuthenticationUpdateOpenIdConnectionRequestWrapper<> request;
    FillAdminUpdateOpenIdConnectionRequest(request);
    LogUpdateOpenIdConnectionRequest(&request.Model(), "TestAuthenticationAdminUpdateOpenIdConnection");
    HRESULT hr = PFAuthenticationAdminUpdateOpenIdConnectionAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminUpdateOpenIdConnectionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdatePlayerSharedSecret

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAuthenticationTests::TestAuthenticationAdminUpdatePlayerSharedSecret(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAuthenticationUpdatePlayerSharedSecretRequestWrapper<> request;
    FillAdminUpdatePlayerSharedSecretRequest(request);
    LogUpdatePlayerSharedSecretRequest(&request.Model(), "TestAuthenticationAdminUpdatePlayerSharedSecret");
    HRESULT hr = PFAuthenticationAdminUpdatePlayerSharedSecretAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminUpdatePlayerSharedSecretAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdatePolicy

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAuthenticationTests::TestAuthenticationAdminUpdatePolicy(TestContext& testContext)
{
    struct AdminUpdatePolicyResultHolderStruct : public UpdatePolicyResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminUpdatePolicyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminUpdatePolicyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogUpdatePolicyResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminUpdatePolicyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdatePolicyResultHolderStruct>>(testContext);

    PFAuthenticationUpdatePolicyRequestWrapper<> request;
    FillAdminUpdatePolicyRequest(request);
    LogUpdatePolicyRequest(&request.Model(), "TestAuthenticationAdminUpdatePolicy");
    HRESULT hr = PFAuthenticationAdminUpdatePolicyAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminUpdatePolicyAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientGetPhotonAuthenticationToken

void AutoGenAuthenticationTests::TestAuthenticationClientGetPhotonAuthenticationToken(TestContext& testContext)
{
    struct ClientGetPhotonAuthenticationTokenResultHolderStruct : public GetPhotonAuthenticationTokenResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientGetPhotonAuthenticationTokenGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientGetPhotonAuthenticationTokenGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetPhotonAuthenticationTokenResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetPhotonAuthenticationTokenResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPhotonAuthenticationTokenResultHolderStruct>>(testContext);

    PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper<> request;
    FillClientGetPhotonAuthenticationTokenRequest(request);
    LogGetPhotonAuthenticationTokenRequest(&request.Model(), "TestAuthenticationClientGetPhotonAuthenticationToken");
    HRESULT hr = PFAuthenticationClientGetPhotonAuthenticationTokenAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientGetPhotonAuthenticationTokenAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetTitlePublicKey

void AutoGenAuthenticationTests::TestAuthenticationClientGetTitlePublicKey(TestContext& testContext)
{
    struct ClientGetTitlePublicKeyResultHolderStruct : public GetTitlePublicKeyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientGetTitlePublicKeyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientGetTitlePublicKeyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetTitlePublicKeyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetTitlePublicKeyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetTitlePublicKeyResultHolderStruct>>(testContext);

    PFAuthenticationGetTitlePublicKeyRequestWrapper<> request;
    FillClientGetTitlePublicKeyRequest(request);
    LogGetTitlePublicKeyRequest(&request.Model(), "TestAuthenticationClientGetTitlePublicKey");
    HRESULT hr = PFAuthenticationClientGetTitlePublicKeyAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientGetTitlePublicKeyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithAndroidDeviceID

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithAndroidDeviceID(TestContext& testContext)
{
    struct ClientLoginWithAndroidDeviceIDResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithAndroidDeviceIDGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithAndroidDeviceIDGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithAndroidDeviceIDResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithAndroidDeviceIDResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper<> request;
    FillClientLoginWithAndroidDeviceIDRequest(request);
    LogLoginWithAndroidDeviceIDRequest(&request.Model(), "TestAuthenticationClientLoginWithAndroidDeviceID");
    HRESULT hr = PFAuthenticationClientLoginWithAndroidDeviceIDAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithAndroidDeviceIDAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithApple

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithApple(TestContext& testContext)
{
    struct ClientLoginWithAppleResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithAppleGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithAppleGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithAppleResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithAppleResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithAppleRequestWrapper<> request;
    FillClientLoginWithAppleRequest(request);
    LogLoginWithAppleRequest(&request.Model(), "TestAuthenticationClientLoginWithApple");
    HRESULT hr = PFAuthenticationClientLoginWithAppleAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithAppleAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithCustomID

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithCustomID(TestContext& testContext)
{
    struct ClientLoginWithCustomIDResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithCustomIDGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithCustomIDGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithCustomIDResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithCustomIDResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithCustomIDRequestWrapper<> request;
    FillClientLoginWithCustomIDRequest(request);
    LogLoginWithCustomIDRequest(&request.Model(), "TestAuthenticationClientLoginWithCustomID");
    HRESULT hr = PFAuthenticationClientLoginWithCustomIDAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithCustomIDAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithEmailAddress

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithEmailAddress(TestContext& testContext)
{
    struct ClientLoginWithEmailAddressResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithEmailAddressGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithEmailAddressGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithEmailAddressResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithEmailAddressResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithEmailAddressRequestWrapper<> request;
    FillClientLoginWithEmailAddressRequest(request);
    LogLoginWithEmailAddressRequest(&request.Model(), "TestAuthenticationClientLoginWithEmailAddress");
    HRESULT hr = PFAuthenticationClientLoginWithEmailAddressAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithEmailAddressAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithFacebook

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithFacebook(TestContext& testContext)
{
    struct ClientLoginWithFacebookResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithFacebookGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithFacebookGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithFacebookResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithFacebookResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithFacebookRequestWrapper<> request;
    FillClientLoginWithFacebookRequest(request);
    LogLoginWithFacebookRequest(&request.Model(), "TestAuthenticationClientLoginWithFacebook");
    HRESULT hr = PFAuthenticationClientLoginWithFacebookAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithFacebookAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithFacebookInstantGamesId

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithFacebookInstantGamesId(TestContext& testContext)
{
    struct ClientLoginWithFacebookInstantGamesIdResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithFacebookInstantGamesIdGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithFacebookInstantGamesIdGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithFacebookInstantGamesIdResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithFacebookInstantGamesIdResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper<> request;
    FillClientLoginWithFacebookInstantGamesIdRequest(request);
    LogLoginWithFacebookInstantGamesIdRequest(&request.Model(), "TestAuthenticationClientLoginWithFacebookInstantGamesId");
    HRESULT hr = PFAuthenticationClientLoginWithFacebookInstantGamesIdAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithFacebookInstantGamesIdAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithGameCenter

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithGameCenter(TestContext& testContext)
{
    struct ClientLoginWithGameCenterResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithGameCenterGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithGameCenterGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithGameCenterResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithGameCenterResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithGameCenterRequestWrapper<> request;
    FillClientLoginWithGameCenterRequest(request);
    LogLoginWithGameCenterRequest(&request.Model(), "TestAuthenticationClientLoginWithGameCenter");
    HRESULT hr = PFAuthenticationClientLoginWithGameCenterAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithGameCenterAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithGoogleAccount

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithGoogleAccount(TestContext& testContext)
{
    struct ClientLoginWithGoogleAccountResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithGoogleAccountGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithGoogleAccountGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithGoogleAccountResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithGoogleAccountResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithGoogleAccountRequestWrapper<> request;
    FillClientLoginWithGoogleAccountRequest(request);
    LogLoginWithGoogleAccountRequest(&request.Model(), "TestAuthenticationClientLoginWithGoogleAccount");
    HRESULT hr = PFAuthenticationClientLoginWithGoogleAccountAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithGoogleAccountAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithIOSDeviceID

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithIOSDeviceID(TestContext& testContext)
{
    struct ClientLoginWithIOSDeviceIDResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithIOSDeviceIDGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithIOSDeviceIDGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithIOSDeviceIDResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithIOSDeviceIDResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithIOSDeviceIDRequestWrapper<> request;
    FillClientLoginWithIOSDeviceIDRequest(request);
    LogLoginWithIOSDeviceIDRequest(&request.Model(), "TestAuthenticationClientLoginWithIOSDeviceID");
    HRESULT hr = PFAuthenticationClientLoginWithIOSDeviceIDAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithIOSDeviceIDAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithKongregate

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithKongregate(TestContext& testContext)
{
    struct ClientLoginWithKongregateResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithKongregateGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithKongregateGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithKongregateResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithKongregateResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithKongregateRequestWrapper<> request;
    FillClientLoginWithKongregateRequest(request);
    LogLoginWithKongregateRequest(&request.Model(), "TestAuthenticationClientLoginWithKongregate");
    HRESULT hr = PFAuthenticationClientLoginWithKongregateAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithKongregateAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithNintendoServiceAccount

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithNintendoServiceAccount(TestContext& testContext)
{
    struct ClientLoginWithNintendoServiceAccountResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithNintendoServiceAccountGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithNintendoServiceAccountGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithNintendoServiceAccountResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithNintendoServiceAccountResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper<> request;
    FillClientLoginWithNintendoServiceAccountRequest(request);
    LogLoginWithNintendoServiceAccountRequest(&request.Model(), "TestAuthenticationClientLoginWithNintendoServiceAccount");
    HRESULT hr = PFAuthenticationClientLoginWithNintendoServiceAccountAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithNintendoServiceAccountAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithNintendoSwitchDeviceId

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithNintendoSwitchDeviceId(TestContext& testContext)
{
    struct ClientLoginWithNintendoSwitchDeviceIdResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithNintendoSwitchDeviceIdGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithNintendoSwitchDeviceIdGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithNintendoSwitchDeviceIdResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithNintendoSwitchDeviceIdResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper<> request;
    FillClientLoginWithNintendoSwitchDeviceIdRequest(request);
    LogLoginWithNintendoSwitchDeviceIdRequest(&request.Model(), "TestAuthenticationClientLoginWithNintendoSwitchDeviceId");
    HRESULT hr = PFAuthenticationClientLoginWithNintendoSwitchDeviceIdAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithNintendoSwitchDeviceIdAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithOpenIdConnect

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithOpenIdConnect(TestContext& testContext)
{
    struct ClientLoginWithOpenIdConnectResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithOpenIdConnectGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithOpenIdConnectGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithOpenIdConnectResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithOpenIdConnectResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithOpenIdConnectRequestWrapper<> request;
    FillClientLoginWithOpenIdConnectRequest(request);
    LogLoginWithOpenIdConnectRequest(&request.Model(), "TestAuthenticationClientLoginWithOpenIdConnect");
    HRESULT hr = PFAuthenticationClientLoginWithOpenIdConnectAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithOpenIdConnectAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithPlayFab

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithPlayFab(TestContext& testContext)
{
    struct ClientLoginWithPlayFabResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithPlayFabGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithPlayFabGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithPlayFabResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithPlayFabResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithPlayFabRequestWrapper<> request;
    FillClientLoginWithPlayFabRequest(request);
    LogLoginWithPlayFabRequest(&request.Model(), "TestAuthenticationClientLoginWithPlayFab");
    HRESULT hr = PFAuthenticationClientLoginWithPlayFabAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithPlayFabAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithPSN

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithPSN(TestContext& testContext)
{
    struct ClientLoginWithPSNResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithPSNGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithPSNGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithPSNResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithPSNResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithPSNRequestWrapper<> request;
    FillClientLoginWithPSNRequest(request);
    LogLoginWithPSNRequest(&request.Model(), "TestAuthenticationClientLoginWithPSN");
    HRESULT hr = PFAuthenticationClientLoginWithPSNAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithPSNAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithSteam

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithSteam(TestContext& testContext)
{
    struct ClientLoginWithSteamResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithSteamGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithSteamGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithSteamResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithSteamResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithSteamRequestWrapper<> request;
    FillClientLoginWithSteamRequest(request);
    LogLoginWithSteamRequest(&request.Model(), "TestAuthenticationClientLoginWithSteam");
    HRESULT hr = PFAuthenticationClientLoginWithSteamAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithSteamAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithTwitch

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithTwitch(TestContext& testContext)
{
    struct ClientLoginWithTwitchResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithTwitchGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithTwitchGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithTwitchResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithTwitchResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithTwitchRequestWrapper<> request;
    FillClientLoginWithTwitchRequest(request);
    LogLoginWithTwitchRequest(&request.Model(), "TestAuthenticationClientLoginWithTwitch");
    HRESULT hr = PFAuthenticationClientLoginWithTwitchAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithTwitchAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientLoginWithXbox

void AutoGenAuthenticationTests::TestAuthenticationClientLoginWithXbox(TestContext& testContext)
{
    struct ClientLoginWithXboxResultHolderStruct : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithXboxGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithXboxGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientLoginWithXboxResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithXboxResultHolderStruct>>(testContext);

    PFAuthenticationClientLoginWithXboxRequestWrapper<> request;
    FillClientLoginWithXboxRequest(request);
    LogClientLoginWithXboxRequest(&request.Model(), "TestAuthenticationClientLoginWithXbox");
    HRESULT hr = PFAuthenticationClientLoginWithXboxAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientLoginWithXboxAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientRegisterPlayFabUser

void AutoGenAuthenticationTests::TestAuthenticationClientRegisterPlayFabUser(TestContext& testContext)
{
    struct ClientRegisterPlayFabUserResultHolderStruct : public RegisterPlayFabUserResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientRegisterPlayFabUserGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientRegisterPlayFabUserGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogRegisterPlayFabUserResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientRegisterPlayFabUserResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientRegisterPlayFabUserResultHolderStruct>>(testContext);

    PFAuthenticationRegisterPlayFabUserRequestWrapper<> request;
    FillClientRegisterPlayFabUserRequest(request);
    LogRegisterPlayFabUserRequest(&request.Model(), "TestAuthenticationClientRegisterPlayFabUser");
    HRESULT hr = PFAuthenticationClientRegisterPlayFabUserAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientRegisterPlayFabUserAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientSetPlayerSecret

void AutoGenAuthenticationTests::TestAuthenticationClientSetPlayerSecret(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAuthenticationClientSetPlayerSecretRequestWrapper<> request;
    FillClientSetPlayerSecretRequest(request);
    LogClientSetPlayerSecretRequest(&request.Model(), "TestAuthenticationClientSetPlayerSecret");
    HRESULT hr = PFAuthenticationClientSetPlayerSecretAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationClientSetPlayerSecretAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerAuthenticateSessionTicket

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAuthenticationTests::TestAuthenticationServerAuthenticateSessionTicket(TestContext& testContext)
{
    struct ServerAuthenticateSessionTicketResultHolderStruct : public AuthenticateSessionTicketResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerAuthenticateSessionTicketGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerAuthenticateSessionTicketGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogAuthenticateSessionTicketResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerAuthenticateSessionTicketResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerAuthenticateSessionTicketResultHolderStruct>>(testContext);

    PFAuthenticationAuthenticateSessionTicketRequestWrapper<> request;
    FillServerAuthenticateSessionTicketRequest(request);
    LogAuthenticateSessionTicketRequest(&request.Model(), "TestAuthenticationServerAuthenticateSessionTicket");
    HRESULT hr = PFAuthenticationServerAuthenticateSessionTicketAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationServerAuthenticateSessionTicketAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerLoginWithServerCustomId

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAuthenticationTests::TestAuthenticationServerLoginWithServerCustomId(TestContext& testContext)
{
    struct ServerLoginWithServerCustomIdResultHolderStruct : public ServerLoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerLoginWithServerCustomIdGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerLoginWithServerCustomIdGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerLoginWithServerCustomIdResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerLoginWithServerCustomIdResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithServerCustomIdRequestWrapper<> request;
    FillServerLoginWithServerCustomIdRequest(request);
    LogLoginWithServerCustomIdRequest(&request.Model(), "TestAuthenticationServerLoginWithServerCustomId");
    HRESULT hr = PFAuthenticationServerLoginWithServerCustomIdAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationServerLoginWithServerCustomIdAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerLoginWithSteamId

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAuthenticationTests::TestAuthenticationServerLoginWithSteamId(TestContext& testContext)
{
    struct ServerLoginWithSteamIdResultHolderStruct : public ServerLoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerLoginWithSteamIdGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerLoginWithSteamIdGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerLoginWithSteamIdResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerLoginWithSteamIdResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithSteamIdRequestWrapper<> request;
    FillServerLoginWithSteamIdRequest(request);
    LogLoginWithSteamIdRequest(&request.Model(), "TestAuthenticationServerLoginWithSteamId");
    HRESULT hr = PFAuthenticationServerLoginWithSteamIdAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationServerLoginWithSteamIdAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerLoginWithXbox

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAuthenticationTests::TestAuthenticationServerLoginWithXbox(TestContext& testContext)
{
    struct ServerLoginWithXboxResultHolderStruct : public ServerLoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerLoginWithXboxGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerLoginWithXboxGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerLoginWithXboxResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerLoginWithXboxResultHolderStruct>>(testContext);

    PFAuthenticationServerLoginWithXboxRequestWrapper<> request;
    FillServerLoginWithXboxRequest(request);
    LogServerLoginWithXboxRequest(&request.Model(), "TestAuthenticationServerLoginWithXbox");
    HRESULT hr = PFAuthenticationServerLoginWithXboxAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationServerLoginWithXboxAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerLoginWithXboxId

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAuthenticationTests::TestAuthenticationServerLoginWithXboxId(TestContext& testContext)
{
    struct ServerLoginWithXboxIdResultHolderStruct : public ServerLoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerLoginWithXboxIdGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerLoginWithXboxIdGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerLoginWithXboxIdResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerLoginWithXboxIdResultHolderStruct>>(testContext);

    PFAuthenticationLoginWithXboxIdRequestWrapper<> request;
    FillServerLoginWithXboxIdRequest(request);
    LogLoginWithXboxIdRequest(&request.Model(), "TestAuthenticationServerLoginWithXboxId");
    HRESULT hr = PFAuthenticationServerLoginWithXboxIdAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationServerLoginWithXboxIdAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerSetPlayerSecret

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAuthenticationTests::TestAuthenticationServerSetPlayerSecret(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAuthenticationServerSetPlayerSecretRequestWrapper<> request;
    FillServerSetPlayerSecretRequest(request);
    LogServerSetPlayerSecretRequest(&request.Model(), "TestAuthenticationServerSetPlayerSecret");
    HRESULT hr = PFAuthenticationServerSetPlayerSecretAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationServerSetPlayerSecretAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetEntityToken

void AutoGenAuthenticationTests::TestAuthenticationGetEntityToken(TestContext& testContext)
{
    struct GetEntityTokenResultHolderStruct : public GetEntityTokenResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationGetEntityTokenGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationGetEntityTokenGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetEntityTokenResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetEntityTokenResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetEntityTokenResultHolderStruct>>(testContext);

    PFAuthenticationGetEntityTokenRequestWrapper<> request;
    FillGetEntityTokenRequest(request);
    LogGetEntityTokenRequest(&request.Model(), "TestAuthenticationGetEntityToken");
    HRESULT hr = PFAuthenticationGetEntityTokenAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationGetEntityTokenAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ValidateEntityToken

void AutoGenAuthenticationTests::TestAuthenticationValidateEntityToken(TestContext& testContext)
{
    struct ValidateEntityTokenResultHolderStruct : public ValidateEntityTokenResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationValidateEntityTokenGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationValidateEntityTokenGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogValidateEntityTokenResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateValidateEntityTokenResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ValidateEntityTokenResultHolderStruct>>(testContext);

    PFAuthenticationValidateEntityTokenRequestWrapper<> request;
    FillValidateEntityTokenRequest(request);
    LogValidateEntityTokenRequest(&request.Model(), "TestAuthenticationValidateEntityToken");
    HRESULT hr = PFAuthenticationValidateEntityTokenAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationValidateEntityTokenAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
