#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenContentTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenContentTests::ContentTestData AutoGenContentTests::testData;

void AutoGenContentTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenContentTests::LogHR(HRESULT hr)
{
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenContentTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestContentAdminDeleteContent", &AutoGenContentTests::TestContentAdminDeleteContent);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestContentAdminGetContentList", &AutoGenContentTests::TestContentAdminGetContentList);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestContentAdminGetContentUploadUrl", &AutoGenContentTests::TestContentAdminGetContentUploadUrl);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestContentClientGetContentDownloadUrl", &AutoGenContentTests::TestContentClientGetContentDownloadUrl);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestContentServerGetContentDownloadUrl", &AutoGenContentTests::TestContentServerGetContentDownloadUrl);
#endif
}

void AutoGenContentTests::ClassSetUp()
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

void AutoGenContentTests::ClassTearDown()
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

void AutoGenContentTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AdminDeleteContent

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenContentTests::TestContentAdminDeleteContent(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFContentDeleteContentRequestWrapper<> request;
    FillDeleteContentRequest(request);
    LogDeleteContentRequest(&request.Model(), "TestContentAdminDeleteContent");
    HRESULT hr = PFContentAdminDeleteContentAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFContentContentAdminDeleteContentAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetContentList

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenContentTests::TestContentAdminGetContentList(TestContext& testContext)
{
    struct AdminGetContentListResultHolderStruct : public GetContentListResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFContentAdminGetContentListGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFContentAdminGetContentListGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFContentGetContentListResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFContentGetContentListResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetContentListResultHolderStruct>>(testContext);

    PFContentGetContentListRequestWrapper<> request;
    FillGetContentListRequest(request);
    LogGetContentListRequest(&request.Model(), "TestContentAdminGetContentList");
    HRESULT hr = PFContentAdminGetContentListAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFContentContentAdminGetContentListAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetContentUploadUrl

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenContentTests::TestContentAdminGetContentUploadUrl(TestContext& testContext)
{
    struct AdminGetContentUploadUrlResultHolderStruct : public GetContentUploadUrlResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFContentAdminGetContentUploadUrlGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFContentAdminGetContentUploadUrlGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFContentGetContentUploadUrlResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFContentGetContentUploadUrlResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetContentUploadUrlResultHolderStruct>>(testContext);

    PFContentGetContentUploadUrlRequestWrapper<> request;
    FillGetContentUploadUrlRequest(request);
    LogGetContentUploadUrlRequest(&request.Model(), "TestContentAdminGetContentUploadUrl");
    HRESULT hr = PFContentAdminGetContentUploadUrlAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFContentContentAdminGetContentUploadUrlAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientGetContentDownloadUrl

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenContentTests::TestContentClientGetContentDownloadUrl(TestContext& testContext)
{
    struct ClientGetContentDownloadUrlResultHolderStruct : public GetContentDownloadUrlResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFContentClientGetContentDownloadUrlGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFContentClientGetContentDownloadUrlGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFContentGetContentDownloadUrlResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFContentGetContentDownloadUrlResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetContentDownloadUrlResultHolderStruct>>(testContext);

    PFContentGetContentDownloadUrlRequestWrapper<> request;
    FillGetContentDownloadUrlRequest(request);
    LogGetContentDownloadUrlRequest(&request.Model(), "TestContentClientGetContentDownloadUrl");
    HRESULT hr = PFContentClientGetContentDownloadUrlAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFContentContentClientGetContentDownloadUrlAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetContentDownloadUrl

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenContentTests::TestContentServerGetContentDownloadUrl(TestContext& testContext)
{
    struct ServerGetContentDownloadUrlResultHolderStruct : public GetContentDownloadUrlResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFContentServerGetContentDownloadUrlGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFContentServerGetContentDownloadUrlGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFContentGetContentDownloadUrlResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFContentGetContentDownloadUrlResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetContentDownloadUrlResultHolderStruct>>(testContext);

    PFContentGetContentDownloadUrlRequestWrapper<> request;
    FillGetContentDownloadUrlRequest(request);
    LogGetContentDownloadUrlRequest(&request.Model(), "TestContentServerGetContentDownloadUrl");
    HRESULT hr = PFContentServerGetContentDownloadUrlAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFContentContentServerGetContentDownloadUrlAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
