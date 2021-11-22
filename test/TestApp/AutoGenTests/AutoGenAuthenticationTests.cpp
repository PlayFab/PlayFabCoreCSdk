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
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenAuthenticationTests::AddTests()
{
    // Generated tests 
    AddTest("TestAuthenticationAdminCreateOpenIdConnection", &AutoGenAuthenticationTests::TestAuthenticationAdminCreateOpenIdConnection);

    AddTest("TestAuthenticationAdminCreatePlayerSharedSecret", &AutoGenAuthenticationTests::TestAuthenticationAdminCreatePlayerSharedSecret);

    AddTest("TestAuthenticationAdminDeleteOpenIdConnection", &AutoGenAuthenticationTests::TestAuthenticationAdminDeleteOpenIdConnection);

    AddTest("TestAuthenticationAdminDeletePlayerSharedSecret", &AutoGenAuthenticationTests::TestAuthenticationAdminDeletePlayerSharedSecret);

    AddTest("TestAuthenticationAdminGetPlayerSharedSecrets", &AutoGenAuthenticationTests::TestAuthenticationAdminGetPlayerSharedSecrets);

    AddTest("TestAuthenticationAdminGetPolicy", &AutoGenAuthenticationTests::TestAuthenticationAdminGetPolicy);

    AddTest("TestAuthenticationAdminListOpenIdConnection", &AutoGenAuthenticationTests::TestAuthenticationAdminListOpenIdConnection);

    AddTest("TestAuthenticationAdminSetPlayerSecret", &AutoGenAuthenticationTests::TestAuthenticationAdminSetPlayerSecret);

    AddTest("TestAuthenticationAdminUpdateOpenIdConnection", &AutoGenAuthenticationTests::TestAuthenticationAdminUpdateOpenIdConnection);

    AddTest("TestAuthenticationAdminUpdatePlayerSharedSecret", &AutoGenAuthenticationTests::TestAuthenticationAdminUpdatePlayerSharedSecret);

    AddTest("TestAuthenticationAdminUpdatePolicy", &AutoGenAuthenticationTests::TestAuthenticationAdminUpdatePolicy);

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

    AddTest("TestAuthenticationServerAuthenticateSessionTicket", &AutoGenAuthenticationTests::TestAuthenticationServerAuthenticateSessionTicket);

    AddTest("TestAuthenticationServerLoginWithServerCustomId", &AutoGenAuthenticationTests::TestAuthenticationServerLoginWithServerCustomId);

    AddTest("TestAuthenticationServerLoginWithSteamId", &AutoGenAuthenticationTests::TestAuthenticationServerLoginWithSteamId);

    AddTest("TestAuthenticationServerLoginWithXbox", &AutoGenAuthenticationTests::TestAuthenticationServerLoginWithXbox);

    AddTest("TestAuthenticationServerLoginWithXboxId", &AutoGenAuthenticationTests::TestAuthenticationServerLoginWithXboxId);

    AddTest("TestAuthenticationServerSetPlayerSecret", &AutoGenAuthenticationTests::TestAuthenticationServerSetPlayerSecret);

    AddTest("TestAuthenticationGetEntityToken", &AutoGenAuthenticationTests::TestAuthenticationGetEntityToken);

    AddTest("TestAuthenticationValidateEntityToken", &AutoGenAuthenticationTests::TestAuthenticationValidateEntityToken);
}

void AutoGenAuthenticationTests::ClassSetUp()
{
    HRESULT hr = PFAdminInitialize(testTitleData.titleId.data(), testTitleData.developerSecretKey.data(), nullptr, &stateHandle);
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

void AutoGenAuthenticationTests::TestAuthenticationAdminCreateOpenIdConnection(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAuthenticationCreateOpenIdConnectionRequestWrapper<> request;
    FillCreateOpenIdConnectionRequest(request);
    LogCreateOpenIdConnectionRequest(&request.Model(), "TestAuthenticationAdminCreateOpenIdConnection");
    HRESULT hr = PFAuthenticationAdminCreateOpenIdConnectionAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminCreateOpenIdConnectionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminCreatePlayerSharedSecret

void AutoGenAuthenticationTests::TestAuthenticationAdminCreatePlayerSharedSecret(TestContext& testContext)
{
    struct AdminCreatePlayerSharedSecretResultHolder : public CreatePlayerSharedSecretResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminCreatePlayerSharedSecretGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminCreatePlayerSharedSecretGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationCreatePlayerSharedSecretResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationCreatePlayerSharedSecretResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminCreatePlayerSharedSecretResultHolder>>(testContext);

    PFAuthenticationCreatePlayerSharedSecretRequestWrapper<> request;
    FillCreatePlayerSharedSecretRequest(request);
    LogCreatePlayerSharedSecretRequest(&request.Model(), "TestAuthenticationAdminCreatePlayerSharedSecret");
    HRESULT hr = PFAuthenticationAdminCreatePlayerSharedSecretAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminCreatePlayerSharedSecretAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminDeleteOpenIdConnection

void AutoGenAuthenticationTests::TestAuthenticationAdminDeleteOpenIdConnection(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAuthenticationDeleteOpenIdConnectionRequestWrapper<> request;
    FillDeleteOpenIdConnectionRequest(request);
    LogDeleteOpenIdConnectionRequest(&request.Model(), "TestAuthenticationAdminDeleteOpenIdConnection");
    HRESULT hr = PFAuthenticationAdminDeleteOpenIdConnectionAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminDeleteOpenIdConnectionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminDeletePlayerSharedSecret

void AutoGenAuthenticationTests::TestAuthenticationAdminDeletePlayerSharedSecret(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAuthenticationDeletePlayerSharedSecretRequestWrapper<> request;
    FillDeletePlayerSharedSecretRequest(request);
    LogDeletePlayerSharedSecretRequest(&request.Model(), "TestAuthenticationAdminDeletePlayerSharedSecret");
    HRESULT hr = PFAuthenticationAdminDeletePlayerSharedSecretAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminDeletePlayerSharedSecretAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetPlayerSharedSecrets

void AutoGenAuthenticationTests::TestAuthenticationAdminGetPlayerSharedSecrets(TestContext& testContext)
{
    struct AdminGetPlayerSharedSecretsResultHolder : public GetPlayerSharedSecretsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminGetPlayerSharedSecretsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminGetPlayerSharedSecretsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationGetPlayerSharedSecretsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationGetPlayerSharedSecretsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetPlayerSharedSecretsResultHolder>>(testContext);

    HRESULT hr = PFAuthenticationAdminGetPlayerSharedSecretsAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminGetPlayerSharedSecretsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetPolicy

void AutoGenAuthenticationTests::TestAuthenticationAdminGetPolicy(TestContext& testContext)
{
    struct AdminGetPolicyResultHolder : public GetPolicyResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminGetPolicyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminGetPolicyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationGetPolicyResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationGetPolicyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetPolicyResultHolder>>(testContext);

    PFAuthenticationGetPolicyRequestWrapper<> request;
    FillGetPolicyRequest(request);
    LogGetPolicyRequest(&request.Model(), "TestAuthenticationAdminGetPolicy");
    HRESULT hr = PFAuthenticationAdminGetPolicyAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminGetPolicyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminListOpenIdConnection

void AutoGenAuthenticationTests::TestAuthenticationAdminListOpenIdConnection(TestContext& testContext)
{
    struct AdminListOpenIdConnectionResultHolder : public ListOpenIdConnectionResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminListOpenIdConnectionGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminListOpenIdConnectionGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationListOpenIdConnectionResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationListOpenIdConnectionResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminListOpenIdConnectionResultHolder>>(testContext);

    HRESULT hr = PFAuthenticationAdminListOpenIdConnectionAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminListOpenIdConnectionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminSetPlayerSecret

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

#pragma endregion

#pragma region AdminUpdateOpenIdConnection

void AutoGenAuthenticationTests::TestAuthenticationAdminUpdateOpenIdConnection(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAuthenticationUpdateOpenIdConnectionRequestWrapper<> request;
    FillUpdateOpenIdConnectionRequest(request);
    LogUpdateOpenIdConnectionRequest(&request.Model(), "TestAuthenticationAdminUpdateOpenIdConnection");
    HRESULT hr = PFAuthenticationAdminUpdateOpenIdConnectionAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminUpdateOpenIdConnectionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminUpdatePlayerSharedSecret

void AutoGenAuthenticationTests::TestAuthenticationAdminUpdatePlayerSharedSecret(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAuthenticationUpdatePlayerSharedSecretRequestWrapper<> request;
    FillUpdatePlayerSharedSecretRequest(request);
    LogUpdatePlayerSharedSecretRequest(&request.Model(), "TestAuthenticationAdminUpdatePlayerSharedSecret");
    HRESULT hr = PFAuthenticationAdminUpdatePlayerSharedSecretAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminUpdatePlayerSharedSecretAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminUpdatePolicy

void AutoGenAuthenticationTests::TestAuthenticationAdminUpdatePolicy(TestContext& testContext)
{
    struct AdminUpdatePolicyResultHolder : public UpdatePolicyResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminUpdatePolicyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationAdminUpdatePolicyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationUpdatePolicyResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationUpdatePolicyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdatePolicyResultHolder>>(testContext);

    PFAuthenticationUpdatePolicyRequestWrapper<> request;
    FillUpdatePolicyRequest(request);
    LogUpdatePolicyRequest(&request.Model(), "TestAuthenticationAdminUpdatePolicy");
    HRESULT hr = PFAuthenticationAdminUpdatePolicyAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAdminUpdatePolicyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPhotonAuthenticationToken

void AutoGenAuthenticationTests::TestAuthenticationClientGetPhotonAuthenticationToken(TestContext& testContext)
{
    struct ClientGetPhotonAuthenticationTokenResultHolder : public GetPhotonAuthenticationTokenResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientGetPhotonAuthenticationTokenGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientGetPhotonAuthenticationTokenGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationGetPhotonAuthenticationTokenResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationGetPhotonAuthenticationTokenResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPhotonAuthenticationTokenResultHolder>>(testContext);

    PFAuthenticationGetPhotonAuthenticationTokenRequestWrapper<> request;
    FillGetPhotonAuthenticationTokenRequest(request);
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
    struct ClientGetTitlePublicKeyResultHolder : public GetTitlePublicKeyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientGetTitlePublicKeyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientGetTitlePublicKeyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationGetTitlePublicKeyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationGetTitlePublicKeyResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetTitlePublicKeyResultHolder>>(testContext);

    PFAuthenticationGetTitlePublicKeyRequestWrapper<> request;
    FillGetTitlePublicKeyRequest(request);
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
    struct ClientLoginWithAndroidDeviceIDResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithAndroidDeviceIDGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithAndroidDeviceIDGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithAndroidDeviceIDResultHolder>>(testContext);

    PFAuthenticationLoginWithAndroidDeviceIDRequestWrapper<> request;
    FillLoginWithAndroidDeviceIDRequest(request);
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
    struct ClientLoginWithAppleResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithAppleGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithAppleGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithAppleResultHolder>>(testContext);

    PFAuthenticationLoginWithAppleRequestWrapper<> request;
    FillLoginWithAppleRequest(request);
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
    struct ClientLoginWithCustomIDResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithCustomIDGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithCustomIDGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithCustomIDResultHolder>>(testContext);

    PFAuthenticationLoginWithCustomIDRequestWrapper<> request;
    FillLoginWithCustomIDRequest(request);
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
    struct ClientLoginWithEmailAddressResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithEmailAddressGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithEmailAddressGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithEmailAddressResultHolder>>(testContext);

    PFAuthenticationLoginWithEmailAddressRequestWrapper<> request;
    FillLoginWithEmailAddressRequest(request);
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
    struct ClientLoginWithFacebookResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithFacebookGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithFacebookGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithFacebookResultHolder>>(testContext);

    PFAuthenticationLoginWithFacebookRequestWrapper<> request;
    FillLoginWithFacebookRequest(request);
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
    struct ClientLoginWithFacebookInstantGamesIdResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithFacebookInstantGamesIdGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithFacebookInstantGamesIdGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithFacebookInstantGamesIdResultHolder>>(testContext);

    PFAuthenticationLoginWithFacebookInstantGamesIdRequestWrapper<> request;
    FillLoginWithFacebookInstantGamesIdRequest(request);
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
    struct ClientLoginWithGameCenterResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithGameCenterGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithGameCenterGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithGameCenterResultHolder>>(testContext);

    PFAuthenticationLoginWithGameCenterRequestWrapper<> request;
    FillLoginWithGameCenterRequest(request);
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
    struct ClientLoginWithGoogleAccountResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithGoogleAccountGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithGoogleAccountGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithGoogleAccountResultHolder>>(testContext);

    PFAuthenticationLoginWithGoogleAccountRequestWrapper<> request;
    FillLoginWithGoogleAccountRequest(request);
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
    struct ClientLoginWithIOSDeviceIDResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithIOSDeviceIDGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithIOSDeviceIDGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithIOSDeviceIDResultHolder>>(testContext);

    PFAuthenticationLoginWithIOSDeviceIDRequestWrapper<> request;
    FillLoginWithIOSDeviceIDRequest(request);
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
    struct ClientLoginWithKongregateResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithKongregateGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithKongregateGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithKongregateResultHolder>>(testContext);

    PFAuthenticationLoginWithKongregateRequestWrapper<> request;
    FillLoginWithKongregateRequest(request);
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
    struct ClientLoginWithNintendoServiceAccountResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithNintendoServiceAccountGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithNintendoServiceAccountGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithNintendoServiceAccountResultHolder>>(testContext);

    PFAuthenticationLoginWithNintendoServiceAccountRequestWrapper<> request;
    FillLoginWithNintendoServiceAccountRequest(request);
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
    struct ClientLoginWithNintendoSwitchDeviceIdResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithNintendoSwitchDeviceIdGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithNintendoSwitchDeviceIdGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithNintendoSwitchDeviceIdResultHolder>>(testContext);

    PFAuthenticationLoginWithNintendoSwitchDeviceIdRequestWrapper<> request;
    FillLoginWithNintendoSwitchDeviceIdRequest(request);
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
    struct ClientLoginWithOpenIdConnectResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithOpenIdConnectGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithOpenIdConnectGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithOpenIdConnectResultHolder>>(testContext);

    PFAuthenticationLoginWithOpenIdConnectRequestWrapper<> request;
    FillLoginWithOpenIdConnectRequest(request);
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
    struct ClientLoginWithPlayFabResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithPlayFabGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithPlayFabGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithPlayFabResultHolder>>(testContext);

    PFAuthenticationLoginWithPlayFabRequestWrapper<> request;
    FillLoginWithPlayFabRequest(request);
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
    struct ClientLoginWithPSNResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithPSNGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithPSNGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithPSNResultHolder>>(testContext);

    PFAuthenticationLoginWithPSNRequestWrapper<> request;
    FillLoginWithPSNRequest(request);
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
    struct ClientLoginWithSteamResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithSteamGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithSteamGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithSteamResultHolder>>(testContext);

    PFAuthenticationLoginWithSteamRequestWrapper<> request;
    FillLoginWithSteamRequest(request);
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
    struct ClientLoginWithTwitchResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithTwitchGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithTwitchGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithTwitchResultHolder>>(testContext);

    PFAuthenticationLoginWithTwitchRequestWrapper<> request;
    FillLoginWithTwitchRequest(request);
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
    struct ClientLoginWithXboxResultHolder : public LoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithXboxGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientLoginWithXboxGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientLoginWithXboxResultHolder>>(testContext);

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
    struct ClientRegisterPlayFabUserResultHolder : public RegisterPlayFabUserResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientRegisterPlayFabUserGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationClientRegisterPlayFabUserGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationRegisterPlayFabUserResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationRegisterPlayFabUserResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientRegisterPlayFabUserResultHolder>>(testContext);

    PFAuthenticationRegisterPlayFabUserRequestWrapper<> request;
    FillRegisterPlayFabUserRequest(request);
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

void AutoGenAuthenticationTests::TestAuthenticationServerAuthenticateSessionTicket(TestContext& testContext)
{
    struct ServerAuthenticateSessionTicketResultHolder : public AuthenticateSessionTicketResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerAuthenticateSessionTicketGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerAuthenticateSessionTicketGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationAuthenticateSessionTicketResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationAuthenticateSessionTicketResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerAuthenticateSessionTicketResultHolder>>(testContext);

    PFAuthenticationAuthenticateSessionTicketRequestWrapper<> request;
    FillAuthenticateSessionTicketRequest(request);
    LogAuthenticateSessionTicketRequest(&request.Model(), "TestAuthenticationServerAuthenticateSessionTicket");
    HRESULT hr = PFAuthenticationServerAuthenticateSessionTicketAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationServerAuthenticateSessionTicketAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerLoginWithServerCustomId

void AutoGenAuthenticationTests::TestAuthenticationServerLoginWithServerCustomId(TestContext& testContext)
{
    struct ServerLoginWithServerCustomIdResultHolder : public ServerLoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerLoginWithServerCustomIdGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerLoginWithServerCustomIdGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationServerLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationServerLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerLoginWithServerCustomIdResultHolder>>(testContext);

    PFAuthenticationLoginWithServerCustomIdRequestWrapper<> request;
    FillLoginWithServerCustomIdRequest(request);
    LogLoginWithServerCustomIdRequest(&request.Model(), "TestAuthenticationServerLoginWithServerCustomId");
    HRESULT hr = PFAuthenticationServerLoginWithServerCustomIdAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationServerLoginWithServerCustomIdAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerLoginWithSteamId

void AutoGenAuthenticationTests::TestAuthenticationServerLoginWithSteamId(TestContext& testContext)
{
    struct ServerLoginWithSteamIdResultHolder : public ServerLoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerLoginWithSteamIdGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerLoginWithSteamIdGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationServerLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationServerLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerLoginWithSteamIdResultHolder>>(testContext);

    PFAuthenticationLoginWithSteamIdRequestWrapper<> request;
    FillLoginWithSteamIdRequest(request);
    LogLoginWithSteamIdRequest(&request.Model(), "TestAuthenticationServerLoginWithSteamId");
    HRESULT hr = PFAuthenticationServerLoginWithSteamIdAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationServerLoginWithSteamIdAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerLoginWithXbox

void AutoGenAuthenticationTests::TestAuthenticationServerLoginWithXbox(TestContext& testContext)
{
    struct ServerLoginWithXboxResultHolder : public ServerLoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerLoginWithXboxGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerLoginWithXboxGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationServerLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationServerLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerLoginWithXboxResultHolder>>(testContext);

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

#pragma endregion

#pragma region ServerLoginWithXboxId

void AutoGenAuthenticationTests::TestAuthenticationServerLoginWithXboxId(TestContext& testContext)
{
    struct ServerLoginWithXboxIdResultHolder : public ServerLoginResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerLoginWithXboxIdGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationServerLoginWithXboxIdGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationServerLoginResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationServerLoginResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerLoginWithXboxIdResultHolder>>(testContext);

    PFAuthenticationLoginWithXboxIdRequestWrapper<> request;
    FillLoginWithXboxIdRequest(request);
    LogLoginWithXboxIdRequest(&request.Model(), "TestAuthenticationServerLoginWithXboxId");
    HRESULT hr = PFAuthenticationServerLoginWithXboxIdAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationServerLoginWithXboxIdAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerSetPlayerSecret

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

#pragma endregion

#pragma region GetEntityToken

void AutoGenAuthenticationTests::TestAuthenticationGetEntityToken(TestContext& testContext)
{
    struct GetEntityTokenResultHolder : public GetEntityTokenResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationGetEntityTokenGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationGetEntityTokenGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationGetEntityTokenResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationGetEntityTokenResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetEntityTokenResultHolder>>(testContext);

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
    struct ValidateEntityTokenResultHolder : public ValidateEntityTokenResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationValidateEntityTokenGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationValidateEntityTokenGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAuthenticationValidateEntityTokenResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAuthenticationValidateEntityTokenResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ValidateEntityTokenResultHolder>>(testContext);

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
