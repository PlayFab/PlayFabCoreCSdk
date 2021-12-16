#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenPlayStreamTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenPlayStreamTests::PlayStreamTestData AutoGenPlayStreamTests::testData;

void AutoGenPlayStreamTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenPlayStreamTests::LogHR(HRESULT hr)
{
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenPlayStreamTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayStreamAdminGetAllSegments", &AutoGenPlayStreamTests::TestPlayStreamAdminGetAllSegments);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayStreamAdminGetPlayerSegments", &AutoGenPlayStreamTests::TestPlayStreamAdminGetPlayerSegments);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayStreamAdminGetPlayersInSegment", &AutoGenPlayStreamTests::TestPlayStreamAdminGetPlayersInSegment);
#endif

    AddTest("TestPlayStreamClientGetPlayerSegments", &AutoGenPlayStreamTests::TestPlayStreamClientGetPlayerSegments);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayStreamServerGetAllSegments", &AutoGenPlayStreamTests::TestPlayStreamServerGetAllSegments);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayStreamServerGetPlayerSegments", &AutoGenPlayStreamTests::TestPlayStreamServerGetPlayerSegments);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayStreamServerGetPlayersInSegment", &AutoGenPlayStreamTests::TestPlayStreamServerGetPlayersInSegment);
#endif
}

void AutoGenPlayStreamTests::ClassSetUp()
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

void AutoGenPlayStreamTests::ClassTearDown()
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

void AutoGenPlayStreamTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AdminGetAllSegments

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayStreamTests::TestPlayStreamAdminGetAllSegments(TestContext& testContext)
{
    struct AdminGetAllSegmentsResultHolderStruct : public GetAllSegmentsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayStreamAdminGetAllSegmentsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayStreamAdminGetAllSegmentsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayStreamGetAllSegmentsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayStreamGetAllSegmentsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetAllSegmentsResultHolderStruct>>(testContext);

    HRESULT hr = PFPlayStreamAdminGetAllSegmentsAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamAdminGetAllSegmentsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetPlayerSegments

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayStreamTests::TestPlayStreamAdminGetPlayerSegments(TestContext& testContext)
{
    struct AdminGetPlayerSegmentsResultHolderStruct : public GetPlayerSegmentsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayStreamAdminGetPlayerSegmentsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayStreamAdminGetPlayerSegmentsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayStreamGetPlayerSegmentsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayStreamGetPlayerSegmentsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetPlayerSegmentsResultHolderStruct>>(testContext);

    PFPlayStreamGetPlayersSegmentsRequestWrapper<> request;
    FillGetPlayersSegmentsRequest(request);
    LogGetPlayersSegmentsRequest(&request.Model(), "TestPlayStreamAdminGetPlayerSegments");
    HRESULT hr = PFPlayStreamAdminGetPlayerSegmentsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamAdminGetPlayerSegmentsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetPlayersInSegment

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayStreamTests::TestPlayStreamAdminGetPlayersInSegment(TestContext& testContext)
{
    struct AdminGetPlayersInSegmentResultHolderStruct : public GetPlayersInSegmentResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayStreamAdminGetPlayersInSegmentGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayStreamAdminGetPlayersInSegmentGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayStreamGetPlayersInSegmentResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayStreamGetPlayersInSegmentResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetPlayersInSegmentResultHolderStruct>>(testContext);

    PFPlayStreamGetPlayersInSegmentRequestWrapper<> request;
    FillGetPlayersInSegmentRequest(request);
    LogGetPlayersInSegmentRequest(&request.Model(), "TestPlayStreamAdminGetPlayersInSegment");
    HRESULT hr = PFPlayStreamAdminGetPlayersInSegmentAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamAdminGetPlayersInSegmentAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientGetPlayerSegments

void AutoGenPlayStreamTests::TestPlayStreamClientGetPlayerSegments(TestContext& testContext)
{
    struct ClientGetPlayerSegmentsResultHolderStruct : public GetPlayerSegmentsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayStreamClientGetPlayerSegmentsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayStreamClientGetPlayerSegmentsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayStreamGetPlayerSegmentsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayStreamGetPlayerSegmentsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayerSegmentsResultHolderStruct>>(testContext);

    HRESULT hr = PFPlayStreamClientGetPlayerSegmentsAsync(titlePlayerHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamClientGetPlayerSegmentsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetAllSegments

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayStreamTests::TestPlayStreamServerGetAllSegments(TestContext& testContext)
{
    struct ServerGetAllSegmentsResultHolderStruct : public GetAllSegmentsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayStreamServerGetAllSegmentsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayStreamServerGetAllSegmentsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayStreamGetAllSegmentsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayStreamGetAllSegmentsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetAllSegmentsResultHolderStruct>>(testContext);

    HRESULT hr = PFPlayStreamServerGetAllSegmentsAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamServerGetAllSegmentsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetPlayerSegments

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayStreamTests::TestPlayStreamServerGetPlayerSegments(TestContext& testContext)
{
    struct ServerGetPlayerSegmentsResultHolderStruct : public GetPlayerSegmentsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayStreamServerGetPlayerSegmentsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayStreamServerGetPlayerSegmentsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayStreamGetPlayerSegmentsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayStreamGetPlayerSegmentsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayerSegmentsResultHolderStruct>>(testContext);

    PFPlayStreamGetPlayersSegmentsRequestWrapper<> request;
    FillGetPlayersSegmentsRequest(request);
    LogGetPlayersSegmentsRequest(&request.Model(), "TestPlayStreamServerGetPlayerSegments");
    HRESULT hr = PFPlayStreamServerGetPlayerSegmentsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamServerGetPlayerSegmentsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetPlayersInSegment

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayStreamTests::TestPlayStreamServerGetPlayersInSegment(TestContext& testContext)
{
    struct ServerGetPlayersInSegmentResultHolderStruct : public GetPlayersInSegmentResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayStreamServerGetPlayersInSegmentGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayStreamServerGetPlayersInSegmentGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayStreamGetPlayersInSegmentResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayStreamGetPlayersInSegmentResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayersInSegmentResultHolderStruct>>(testContext);

    PFPlayStreamGetPlayersInSegmentRequestWrapper<> request;
    FillGetPlayersInSegmentRequest(request);
    LogGetPlayersInSegmentRequest(&request.Model(), "TestPlayStreamServerGetPlayersInSegment");
    HRESULT hr = PFPlayStreamServerGetPlayersInSegmentAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamServerGetPlayersInSegmentAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
