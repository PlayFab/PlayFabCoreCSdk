#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenProfilesTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenProfilesTests::ProfilesTestData AutoGenProfilesTests::testData;

void AutoGenProfilesTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenProfilesTests::LogHR(HRESULT hr)
{
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenProfilesTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestProfilesGetGlobalPolicy", &AutoGenProfilesTests::TestProfilesGetGlobalPolicy); // TODO: debug failing test
#endif

    AddTest("TestProfilesGetProfile", &AutoGenProfilesTests::TestProfilesGetProfile);

    AddTest("TestProfilesGetProfiles", &AutoGenProfilesTests::TestProfilesGetProfiles);

    AddTest("TestProfilesGetTitlePlayersFromMasterPlayerAccountIds", &AutoGenProfilesTests::TestProfilesGetTitlePlayersFromMasterPlayerAccountIds);

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestProfilesSetGlobalPolicy", &AutoGenProfilesTests::TestProfilesSetGlobalPolicy); // TODO: debug failing test
#endif

    AddTest("TestProfilesSetProfileLanguage", &AutoGenProfilesTests::TestProfilesSetProfileLanguage);

    AddTest("TestProfilesSetProfilePolicy", &AutoGenProfilesTests::TestProfilesSetProfilePolicy);
}

void AutoGenProfilesTests::ClassSetUp()
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

void AutoGenProfilesTests::ClassTearDown()
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

void AutoGenProfilesTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region GetGlobalPolicy

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenProfilesTests::TestProfilesGetGlobalPolicy(TestContext& testContext)
{
    struct GetGlobalPolicyResultHolderStruct : public GetGlobalPolicyResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFProfilesGetGlobalPolicyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFProfilesGetGlobalPolicyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFProfilesGetGlobalPolicyResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFProfilesGetGlobalPolicyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGlobalPolicyResultHolderStruct>>(testContext);

    PFProfilesGetGlobalPolicyRequestWrapper<> request;
    FillGetGlobalPolicyRequest(request);
    LogGetGlobalPolicyRequest(&request.Model(), "TestProfilesGetGlobalPolicy");
    HRESULT hr = PFProfilesGetGlobalPolicyAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFProfilesProfilesGetGlobalPolicyAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetProfile

void AutoGenProfilesTests::TestProfilesGetProfile(TestContext& testContext)
{
    struct GetProfileResultHolderStruct : public GetEntityProfileResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFProfilesGetProfileGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFProfilesGetProfileGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFProfilesGetEntityProfileResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFProfilesGetEntityProfileResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetProfileResultHolderStruct>>(testContext);

    PFProfilesGetEntityProfileRequestWrapper<> request;
    FillGetEntityProfileRequest(request);
    LogGetEntityProfileRequest(&request.Model(), "TestProfilesGetProfile");
    HRESULT hr = PFProfilesGetProfileAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFProfilesProfilesGetProfileAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetProfiles

void AutoGenProfilesTests::TestProfilesGetProfiles(TestContext& testContext)
{
    struct GetProfilesResultHolderStruct : public GetEntityProfilesResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFProfilesGetProfilesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFProfilesGetProfilesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFProfilesGetEntityProfilesResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFProfilesGetEntityProfilesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetProfilesResultHolderStruct>>(testContext);

    PFProfilesGetEntityProfilesRequestWrapper<> request;
    FillGetEntityProfilesRequest(request);
    LogGetEntityProfilesRequest(&request.Model(), "TestProfilesGetProfiles");
    HRESULT hr = PFProfilesGetProfilesAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFProfilesProfilesGetProfilesAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetTitlePlayersFromMasterPlayerAccountIds

void AutoGenProfilesTests::TestProfilesGetTitlePlayersFromMasterPlayerAccountIds(TestContext& testContext)
{
    struct GetTitlePlayersFromMasterPlayerAccountIdsResultHolderStruct : public GetTitlePlayersFromMasterPlayerAccountIdsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFProfilesGetTitlePlayersFromMasterPlayerAccountIdsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetTitlePlayersFromMasterPlayerAccountIdsResultHolderStruct>>(testContext);

    PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsRequestWrapper<> request;
    FillGetTitlePlayersFromMasterPlayerAccountIdsRequest(request);
    LogGetTitlePlayersFromMasterPlayerAccountIdsRequest(&request.Model(), "TestProfilesGetTitlePlayersFromMasterPlayerAccountIds");
    HRESULT hr = PFProfilesGetTitlePlayersFromMasterPlayerAccountIdsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFProfilesProfilesGetTitlePlayersFromMasterPlayerAccountIdsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region SetGlobalPolicy

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenProfilesTests::TestProfilesSetGlobalPolicy(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFProfilesSetGlobalPolicyRequestWrapper<> request;
    FillSetGlobalPolicyRequest(request);
    LogSetGlobalPolicyRequest(&request.Model(), "TestProfilesSetGlobalPolicy");
    HRESULT hr = PFProfilesSetGlobalPolicyAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFProfilesProfilesSetGlobalPolicyAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region SetProfileLanguage

void AutoGenProfilesTests::TestProfilesSetProfileLanguage(TestContext& testContext)
{
    struct SetProfileLanguageResultHolderStruct : public SetProfileLanguageResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFProfilesSetProfileLanguageGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFProfilesSetProfileLanguageGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFProfilesSetProfileLanguageResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFProfilesSetProfileLanguageResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<SetProfileLanguageResultHolderStruct>>(testContext);

    PFProfilesSetProfileLanguageRequestWrapper<> request;
    FillSetProfileLanguageRequest(request);
    LogSetProfileLanguageRequest(&request.Model(), "TestProfilesSetProfileLanguage");
    HRESULT hr = PFProfilesSetProfileLanguageAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFProfilesProfilesSetProfileLanguageAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region SetProfilePolicy

void AutoGenProfilesTests::TestProfilesSetProfilePolicy(TestContext& testContext)
{
    struct SetProfilePolicyResultHolderStruct : public SetEntityProfilePolicyResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFProfilesSetProfilePolicyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFProfilesSetProfilePolicyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFProfilesSetEntityProfilePolicyResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFProfilesSetEntityProfilePolicyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<SetProfilePolicyResultHolderStruct>>(testContext);

    PFProfilesSetEntityProfilePolicyRequestWrapper<> request;
    FillSetEntityProfilePolicyRequest(request);
    LogSetEntityProfilePolicyRequest(&request.Model(), "TestProfilesSetProfilePolicy");
    HRESULT hr = PFProfilesSetProfilePolicyAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFProfilesProfilesSetProfilePolicyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
