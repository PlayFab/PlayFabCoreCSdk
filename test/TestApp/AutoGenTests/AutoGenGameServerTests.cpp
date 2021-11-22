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
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenGameServerTests::AddTests()
{
    // Generated tests 
    AddTest("TestGameServerAdminAddServerBuild", &AutoGenGameServerTests::TestGameServerAdminAddServerBuild);

    AddTest("TestGameServerAdminGetServerBuildInfo", &AutoGenGameServerTests::TestGameServerAdminGetServerBuildInfo);

    AddTest("TestGameServerAdminGetServerBuildUploadUrl", &AutoGenGameServerTests::TestGameServerAdminGetServerBuildUploadUrl);

    AddTest("TestGameServerAdminListServerBuilds", &AutoGenGameServerTests::TestGameServerAdminListServerBuilds);

    AddTest("TestGameServerAdminModifyServerBuild", &AutoGenGameServerTests::TestGameServerAdminModifyServerBuild);

    AddTest("TestGameServerAdminRemoveServerBuild", &AutoGenGameServerTests::TestGameServerAdminRemoveServerBuild);
}

void AutoGenGameServerTests::ClassSetUp()
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

void AutoGenGameServerTests::TestGameServerAdminAddServerBuild(TestContext& testContext)
{
    struct AdminAddServerBuildResultHolder : public AddServerBuildResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGameServerAdminAddServerBuildGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGameServerAdminAddServerBuildGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGameServerAddServerBuildResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGameServerAddServerBuildResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminAddServerBuildResultHolder>>(testContext);

    PFGameServerAddServerBuildRequestWrapper<> request;
    FillAddServerBuildRequest(request);
    LogAddServerBuildRequest(&request.Model(), "TestGameServerAdminAddServerBuild");
    HRESULT hr = PFGameServerAdminAddServerBuildAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGameServerGameServerAdminAddServerBuildAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetServerBuildInfo

void AutoGenGameServerTests::TestGameServerAdminGetServerBuildInfo(TestContext& testContext)
{
    struct AdminGetServerBuildInfoResultHolder : public GetServerBuildInfoResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGameServerAdminGetServerBuildInfoGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGameServerAdminGetServerBuildInfoGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGameServerGetServerBuildInfoResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGameServerGetServerBuildInfoResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetServerBuildInfoResultHolder>>(testContext);

    PFGameServerGetServerBuildInfoRequestWrapper<> request;
    FillGetServerBuildInfoRequest(request);
    LogGetServerBuildInfoRequest(&request.Model(), "TestGameServerAdminGetServerBuildInfo");
    HRESULT hr = PFGameServerAdminGetServerBuildInfoAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGameServerGameServerAdminGetServerBuildInfoAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetServerBuildUploadUrl

void AutoGenGameServerTests::TestGameServerAdminGetServerBuildUploadUrl(TestContext& testContext)
{
    struct AdminGetServerBuildUploadUrlResultHolder : public GetServerBuildUploadURLResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGameServerAdminGetServerBuildUploadUrlGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGameServerAdminGetServerBuildUploadUrlGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGameServerGetServerBuildUploadURLResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGameServerGetServerBuildUploadURLResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetServerBuildUploadUrlResultHolder>>(testContext);

    PFGameServerGetServerBuildUploadURLRequestWrapper<> request;
    FillGetServerBuildUploadURLRequest(request);
    LogGetServerBuildUploadURLRequest(&request.Model(), "TestGameServerAdminGetServerBuildUploadUrl");
    HRESULT hr = PFGameServerAdminGetServerBuildUploadUrlAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGameServerGameServerAdminGetServerBuildUploadUrlAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminListServerBuilds

void AutoGenGameServerTests::TestGameServerAdminListServerBuilds(TestContext& testContext)
{
    struct AdminListServerBuildsResultHolder : public ListBuildsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGameServerAdminListServerBuildsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGameServerAdminListServerBuildsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGameServerListBuildsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGameServerListBuildsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminListServerBuildsResultHolder>>(testContext);

    HRESULT hr = PFGameServerAdminListServerBuildsAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGameServerGameServerAdminListServerBuildsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminModifyServerBuild

void AutoGenGameServerTests::TestGameServerAdminModifyServerBuild(TestContext& testContext)
{
    struct AdminModifyServerBuildResultHolder : public ModifyServerBuildResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGameServerAdminModifyServerBuildGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGameServerAdminModifyServerBuildGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGameServerModifyServerBuildResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGameServerModifyServerBuildResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminModifyServerBuildResultHolder>>(testContext);

    PFGameServerModifyServerBuildRequestWrapper<> request;
    FillModifyServerBuildRequest(request);
    LogModifyServerBuildRequest(&request.Model(), "TestGameServerAdminModifyServerBuild");
    HRESULT hr = PFGameServerAdminModifyServerBuildAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGameServerGameServerAdminModifyServerBuildAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminRemoveServerBuild

void AutoGenGameServerTests::TestGameServerAdminRemoveServerBuild(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGameServerRemoveServerBuildRequestWrapper<> request;
    FillRemoveServerBuildRequest(request);
    LogRemoveServerBuildRequest(&request.Model(), "TestGameServerAdminRemoveServerBuild");
    HRESULT hr = PFGameServerAdminRemoveServerBuildAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGameServerGameServerAdminRemoveServerBuildAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
