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
    AddTest("TestAuthenticationAuthenticateWithCustomId", &AutoGenAuthenticationTests::TestAuthenticationAuthenticateWithCustomId);

    AddTest("TestAuthenticationGetLinkedPlayerIdentities", &AutoGenAuthenticationTests::TestAuthenticationGetLinkedPlayerIdentities);

    AddTest("TestAuthenticationUnlinkPlayerIdentity", &AutoGenAuthenticationTests::TestAuthenticationUnlinkPlayerIdentity);

    AddTest("TestAuthenticationLoginPlayer", &AutoGenAuthenticationTests::TestAuthenticationLoginPlayer);
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

#pragma region AuthenticateWithCustomId

void AutoGenAuthenticationTests::TestAuthenticationAuthenticateWithCustomId(TestContext& testContext)
{
    struct AuthenticateWithCustomIdResultHolderStruct : public AuthenticateIdentityResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationAuthenticateWithCustomIdGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationAuthenticateWithCustomIdGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogAuthenticateIdentityResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAuthenticateWithCustomIdResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AuthenticateWithCustomIdResultHolderStruct>>(testContext);

    PFAuthenticationAuthenticateCustomIdIdentityRequestWrapper<> request;
    FillAuthenticateWithCustomIdRequest(request);
    LogAuthenticateCustomIdIdentityRequest(&request.Model(), "TestAuthenticationAuthenticateWithCustomId");
    HRESULT hr = PFAuthenticationAuthenticateWithCustomIdAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationAuthenticateWithCustomIdAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetLinkedPlayerIdentities

void AutoGenAuthenticationTests::TestAuthenticationGetLinkedPlayerIdentities(TestContext& testContext)
{
    struct GetLinkedPlayerIdentitiesResultHolderStruct : public GetLinkedPlayerIdentitiesResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationGetLinkedPlayerIdentitiesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationGetLinkedPlayerIdentitiesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetLinkedPlayerIdentitiesResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetLinkedPlayerIdentitiesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetLinkedPlayerIdentitiesResultHolderStruct>>(testContext);

    PFAuthenticationGetLinkedPlayerIdentitiesRequestWrapper<> request;
    FillGetLinkedPlayerIdentitiesRequest(request);
    LogGetLinkedPlayerIdentitiesRequest(&request.Model(), "TestAuthenticationGetLinkedPlayerIdentities");
    HRESULT hr = PFAuthenticationGetLinkedPlayerIdentitiesAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationGetLinkedPlayerIdentitiesAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region UnlinkPlayerIdentity

void AutoGenAuthenticationTests::TestAuthenticationUnlinkPlayerIdentity(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAuthenticationUnlinkPlayerIdentityRequestWrapper<> request;
    FillUnlinkPlayerIdentityRequest(request);
    LogUnlinkPlayerIdentityRequest(&request.Model(), "TestAuthenticationUnlinkPlayerIdentity");
    HRESULT hr = PFAuthenticationUnlinkPlayerIdentityAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationUnlinkPlayerIdentityAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region LoginPlayer

void AutoGenAuthenticationTests::TestAuthenticationLoginPlayer(TestContext& testContext)
{
    struct LoginPlayerResultHolderStruct : public LoginPlayerResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAuthenticationLoginPlayerGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAuthenticationLoginPlayerGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogLoginPlayerResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateLoginPlayerResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<LoginPlayerResultHolderStruct>>(testContext);

    PFAuthenticationLoginPlayerRequestWrapper<> request;
    FillLoginPlayerRequest(request);
    LogLoginPlayerRequest(&request.Model(), "TestAuthenticationLoginPlayer");
    HRESULT hr = PFAuthenticationLoginPlayerAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAuthenticationAuthenticationLoginPlayerAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
