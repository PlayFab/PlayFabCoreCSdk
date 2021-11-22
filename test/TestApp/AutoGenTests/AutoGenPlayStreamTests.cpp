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
    AddTest("TestPlayStreamAdminAddPlayerTag", &AutoGenPlayStreamTests::TestPlayStreamAdminAddPlayerTag);

    AddTest("TestPlayStreamAdminGetAllSegments", &AutoGenPlayStreamTests::TestPlayStreamAdminGetAllSegments);

    AddTest("TestPlayStreamAdminGetPlayerSegments", &AutoGenPlayStreamTests::TestPlayStreamAdminGetPlayerSegments);

    AddTest("TestPlayStreamAdminGetPlayersInSegment", &AutoGenPlayStreamTests::TestPlayStreamAdminGetPlayersInSegment);

    AddTest("TestPlayStreamAdminGetPlayerTags", &AutoGenPlayStreamTests::TestPlayStreamAdminGetPlayerTags);

    AddTest("TestPlayStreamAdminRemovePlayerTag", &AutoGenPlayStreamTests::TestPlayStreamAdminRemovePlayerTag);

    AddTest("TestPlayStreamClientGetPlayerSegments", &AutoGenPlayStreamTests::TestPlayStreamClientGetPlayerSegments);

    AddTest("TestPlayStreamClientGetPlayerTags", &AutoGenPlayStreamTests::TestPlayStreamClientGetPlayerTags);

    AddTest("TestPlayStreamServerAddPlayerTag", &AutoGenPlayStreamTests::TestPlayStreamServerAddPlayerTag);

    AddTest("TestPlayStreamServerGetAllSegments", &AutoGenPlayStreamTests::TestPlayStreamServerGetAllSegments);

    AddTest("TestPlayStreamServerGetPlayerSegments", &AutoGenPlayStreamTests::TestPlayStreamServerGetPlayerSegments);

    AddTest("TestPlayStreamServerGetPlayersInSegment", &AutoGenPlayStreamTests::TestPlayStreamServerGetPlayersInSegment);

    AddTest("TestPlayStreamServerGetPlayerTags", &AutoGenPlayStreamTests::TestPlayStreamServerGetPlayerTags);

    AddTest("TestPlayStreamServerRemovePlayerTag", &AutoGenPlayStreamTests::TestPlayStreamServerRemovePlayerTag);

    AddTest("TestPlayStreamWriteEvents", &AutoGenPlayStreamTests::TestPlayStreamWriteEvents);

    AddTest("TestPlayStreamWriteTelemetryEvents", &AutoGenPlayStreamTests::TestPlayStreamWriteTelemetryEvents);
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

#pragma region AdminAddPlayerTag

void AutoGenPlayStreamTests::TestPlayStreamAdminAddPlayerTag(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayStreamAddPlayerTagRequestWrapper<> request;
    FillAddPlayerTagRequest(request);
    LogAddPlayerTagRequest(&request.Model(), "TestPlayStreamAdminAddPlayerTag");
    HRESULT hr = PFPlayStreamAdminAddPlayerTagAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamAdminAddPlayerTagAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetAllSegments

void AutoGenPlayStreamTests::TestPlayStreamAdminGetAllSegments(TestContext& testContext)
{
    struct AdminGetAllSegmentsResultHolder : public GetAllSegmentsResultHolder
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
    auto async = std::make_unique<XAsyncHelper<AdminGetAllSegmentsResultHolder>>(testContext);

    HRESULT hr = PFPlayStreamAdminGetAllSegmentsAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamAdminGetAllSegmentsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetPlayerSegments

void AutoGenPlayStreamTests::TestPlayStreamAdminGetPlayerSegments(TestContext& testContext)
{
    struct AdminGetPlayerSegmentsResultHolder : public GetPlayerSegmentsResultHolder
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
    auto async = std::make_unique<XAsyncHelper<AdminGetPlayerSegmentsResultHolder>>(testContext);

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

#pragma endregion

#pragma region AdminGetPlayersInSegment

void AutoGenPlayStreamTests::TestPlayStreamAdminGetPlayersInSegment(TestContext& testContext)
{
    struct AdminGetPlayersInSegmentResultHolder : public GetPlayersInSegmentResultHolder
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
    auto async = std::make_unique<XAsyncHelper<AdminGetPlayersInSegmentResultHolder>>(testContext);

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

#pragma endregion

#pragma region AdminGetPlayerTags

void AutoGenPlayStreamTests::TestPlayStreamAdminGetPlayerTags(TestContext& testContext)
{
    struct AdminGetPlayerTagsResultHolder : public GetPlayerTagsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayStreamAdminGetPlayerTagsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayStreamAdminGetPlayerTagsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayStreamGetPlayerTagsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayStreamGetPlayerTagsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetPlayerTagsResultHolder>>(testContext);

    PFPlayStreamGetPlayerTagsRequestWrapper<> request;
    FillGetPlayerTagsRequest(request);
    LogGetPlayerTagsRequest(&request.Model(), "TestPlayStreamAdminGetPlayerTags");
    HRESULT hr = PFPlayStreamAdminGetPlayerTagsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamAdminGetPlayerTagsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminRemovePlayerTag

void AutoGenPlayStreamTests::TestPlayStreamAdminRemovePlayerTag(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayStreamRemovePlayerTagRequestWrapper<> request;
    FillRemovePlayerTagRequest(request);
    LogRemovePlayerTagRequest(&request.Model(), "TestPlayStreamAdminRemovePlayerTag");
    HRESULT hr = PFPlayStreamAdminRemovePlayerTagAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamAdminRemovePlayerTagAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayerSegments

void AutoGenPlayStreamTests::TestPlayStreamClientGetPlayerSegments(TestContext& testContext)
{
    struct ClientGetPlayerSegmentsResultHolder : public GetPlayerSegmentsResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayerSegmentsResultHolder>>(testContext);

    HRESULT hr = PFPlayStreamClientGetPlayerSegmentsAsync(titlePlayerHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamClientGetPlayerSegmentsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayerTags

void AutoGenPlayStreamTests::TestPlayStreamClientGetPlayerTags(TestContext& testContext)
{
    struct ClientGetPlayerTagsResultHolder : public GetPlayerTagsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayStreamClientGetPlayerTagsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayStreamClientGetPlayerTagsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayStreamGetPlayerTagsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayStreamGetPlayerTagsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayerTagsResultHolder>>(testContext);

    PFPlayStreamGetPlayerTagsRequestWrapper<> request;
    FillGetPlayerTagsRequest(request);
    LogGetPlayerTagsRequest(&request.Model(), "TestPlayStreamClientGetPlayerTags");
    HRESULT hr = PFPlayStreamClientGetPlayerTagsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamClientGetPlayerTagsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerAddPlayerTag

void AutoGenPlayStreamTests::TestPlayStreamServerAddPlayerTag(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayStreamAddPlayerTagRequestWrapper<> request;
    FillAddPlayerTagRequest(request);
    LogAddPlayerTagRequest(&request.Model(), "TestPlayStreamServerAddPlayerTag");
    HRESULT hr = PFPlayStreamServerAddPlayerTagAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamServerAddPlayerTagAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetAllSegments

void AutoGenPlayStreamTests::TestPlayStreamServerGetAllSegments(TestContext& testContext)
{
    struct ServerGetAllSegmentsResultHolder : public GetAllSegmentsResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ServerGetAllSegmentsResultHolder>>(testContext);

    HRESULT hr = PFPlayStreamServerGetAllSegmentsAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamServerGetAllSegmentsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetPlayerSegments

void AutoGenPlayStreamTests::TestPlayStreamServerGetPlayerSegments(TestContext& testContext)
{
    struct ServerGetPlayerSegmentsResultHolder : public GetPlayerSegmentsResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayerSegmentsResultHolder>>(testContext);

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

#pragma endregion

#pragma region ServerGetPlayersInSegment

void AutoGenPlayStreamTests::TestPlayStreamServerGetPlayersInSegment(TestContext& testContext)
{
    struct ServerGetPlayersInSegmentResultHolder : public GetPlayersInSegmentResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayersInSegmentResultHolder>>(testContext);

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

#pragma endregion

#pragma region ServerGetPlayerTags

void AutoGenPlayStreamTests::TestPlayStreamServerGetPlayerTags(TestContext& testContext)
{
    struct ServerGetPlayerTagsResultHolder : public GetPlayerTagsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayStreamServerGetPlayerTagsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayStreamServerGetPlayerTagsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayStreamGetPlayerTagsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayStreamGetPlayerTagsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayerTagsResultHolder>>(testContext);

    PFPlayStreamGetPlayerTagsRequestWrapper<> request;
    FillGetPlayerTagsRequest(request);
    LogGetPlayerTagsRequest(&request.Model(), "TestPlayStreamServerGetPlayerTags");
    HRESULT hr = PFPlayStreamServerGetPlayerTagsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamServerGetPlayerTagsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerRemovePlayerTag

void AutoGenPlayStreamTests::TestPlayStreamServerRemovePlayerTag(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayStreamRemovePlayerTagRequestWrapper<> request;
    FillRemovePlayerTagRequest(request);
    LogRemovePlayerTagRequest(&request.Model(), "TestPlayStreamServerRemovePlayerTag");
    HRESULT hr = PFPlayStreamServerRemovePlayerTagAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamServerRemovePlayerTagAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region WriteEvents

void AutoGenPlayStreamTests::TestPlayStreamWriteEvents(TestContext& testContext)
{
    struct WriteEventsResultHolder : public WriteEventsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayStreamWriteEventsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayStreamWriteEventsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayStreamWriteEventsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayStreamWriteEventsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<WriteEventsResultHolder>>(testContext);

    PFPlayStreamWriteEventsRequestWrapper<> request;
    FillWriteEventsRequest(request);
    LogWriteEventsRequest(&request.Model(), "TestPlayStreamWriteEvents");
    HRESULT hr = PFPlayStreamWriteEventsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamWriteEventsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region WriteTelemetryEvents

void AutoGenPlayStreamTests::TestPlayStreamWriteTelemetryEvents(TestContext& testContext)
{
    struct WriteTelemetryEventsResultHolder : public WriteEventsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayStreamWriteTelemetryEventsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayStreamWriteTelemetryEventsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayStreamWriteEventsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayStreamWriteEventsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<WriteTelemetryEventsResultHolder>>(testContext);

    PFPlayStreamWriteEventsRequestWrapper<> request;
    FillWriteEventsRequest(request);
    LogWriteEventsRequest(&request.Model(), "TestPlayStreamWriteTelemetryEvents");
    HRESULT hr = PFPlayStreamWriteTelemetryEventsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayStreamPlayStreamWriteTelemetryEventsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
