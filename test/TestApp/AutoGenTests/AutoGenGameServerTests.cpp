#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenGameServerTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenGameServerTests::GameServerTestData AutoGenGameServerTests::testData;

void AutoGenGameServerTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenGameServerTests::LogHR(HRESULT hr)
{
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenGameServerTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestGameServerAdminAddServerBuild", &AutoGenGameServerTests::TestGameServerAdminAddServerBuild);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestGameServerAdminGetServerBuildInfo", &AutoGenGameServerTests::TestGameServerAdminGetServerBuildInfo);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestGameServerAdminGetServerBuildUploadUrl", &AutoGenGameServerTests::TestGameServerAdminGetServerBuildUploadUrl);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestGameServerAdminListServerBuilds", &AutoGenGameServerTests::TestGameServerAdminListServerBuilds);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestGameServerAdminModifyServerBuild", &AutoGenGameServerTests::TestGameServerAdminModifyServerBuild);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestGameServerAdminRemoveServerBuild", &AutoGenGameServerTests::TestGameServerAdminRemoveServerBuild);
#endif
}

void AutoGenGameServerTests::ClassSetUp()
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

void AutoGenGameServerTests::ClassTearDown()
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

void AutoGenGameServerTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AdminAddServerBuild

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenGameServerTests::TestGameServerAdminAddServerBuild(TestContext& testContext)
{
    struct AdminAddServerBuildResultHolderStruct : public AddServerBuildResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGameServerAdminAddServerBuildGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGameServerAdminAddServerBuildGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogAddServerBuildResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminAddServerBuildResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminAddServerBuildResultHolderStruct>>(testContext);

    PFGameServerAddServerBuildRequestWrapper<> request;
    FillAdminAddServerBuildRequest(request);
    LogAddServerBuildRequest(&request.Model(), "TestGameServerAdminAddServerBuild");
    HRESULT hr = PFGameServerAdminAddServerBuildAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGameServerGameServerAdminAddServerBuildAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetServerBuildInfo

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenGameServerTests::TestGameServerAdminGetServerBuildInfo(TestContext& testContext)
{
    struct AdminGetServerBuildInfoResultHolderStruct : public GetServerBuildInfoResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGameServerAdminGetServerBuildInfoGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGameServerAdminGetServerBuildInfoGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetServerBuildInfoResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetServerBuildInfoResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetServerBuildInfoResultHolderStruct>>(testContext);

    PFGameServerGetServerBuildInfoRequestWrapper<> request;
    FillAdminGetServerBuildInfoRequest(request);
    LogGetServerBuildInfoRequest(&request.Model(), "TestGameServerAdminGetServerBuildInfo");
    HRESULT hr = PFGameServerAdminGetServerBuildInfoAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGameServerGameServerAdminGetServerBuildInfoAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetServerBuildUploadUrl

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenGameServerTests::TestGameServerAdminGetServerBuildUploadUrl(TestContext& testContext)
{
    struct AdminGetServerBuildUploadUrlResultHolderStruct : public GetServerBuildUploadURLResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGameServerAdminGetServerBuildUploadUrlGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGameServerAdminGetServerBuildUploadUrlGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetServerBuildUploadURLResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetServerBuildUploadUrlResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetServerBuildUploadUrlResultHolderStruct>>(testContext);

    PFGameServerGetServerBuildUploadURLRequestWrapper<> request;
    FillAdminGetServerBuildUploadUrlRequest(request);
    LogGetServerBuildUploadURLRequest(&request.Model(), "TestGameServerAdminGetServerBuildUploadUrl");
    HRESULT hr = PFGameServerAdminGetServerBuildUploadUrlAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGameServerGameServerAdminGetServerBuildUploadUrlAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminListServerBuilds

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenGameServerTests::TestGameServerAdminListServerBuilds(TestContext& testContext)
{
    struct AdminListServerBuildsResultHolderStruct : public ListBuildsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGameServerAdminListServerBuildsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGameServerAdminListServerBuildsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListBuildsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminListServerBuildsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminListServerBuildsResultHolderStruct>>(testContext);

    HRESULT hr = PFGameServerAdminListServerBuildsAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGameServerGameServerAdminListServerBuildsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminModifyServerBuild

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenGameServerTests::TestGameServerAdminModifyServerBuild(TestContext& testContext)
{
    struct AdminModifyServerBuildResultHolderStruct : public ModifyServerBuildResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGameServerAdminModifyServerBuildGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGameServerAdminModifyServerBuildGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogModifyServerBuildResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminModifyServerBuildResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminModifyServerBuildResultHolderStruct>>(testContext);

    PFGameServerModifyServerBuildRequestWrapper<> request;
    FillAdminModifyServerBuildRequest(request);
    LogModifyServerBuildRequest(&request.Model(), "TestGameServerAdminModifyServerBuild");
    HRESULT hr = PFGameServerAdminModifyServerBuildAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGameServerGameServerAdminModifyServerBuildAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminRemoveServerBuild

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenGameServerTests::TestGameServerAdminRemoveServerBuild(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGameServerRemoveServerBuildRequestWrapper<> request;
    FillAdminRemoveServerBuildRequest(request);
    LogRemoveServerBuildRequest(&request.Model(), "TestGameServerAdminRemoveServerBuild");
    HRESULT hr = PFGameServerAdminRemoveServerBuildAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGameServerGameServerAdminRemoveServerBuildAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
