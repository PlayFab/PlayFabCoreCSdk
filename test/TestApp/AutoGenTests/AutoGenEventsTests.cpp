#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenEventsTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenEventsTests::EventsTestData AutoGenEventsTests::testData;

void AutoGenEventsTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenEventsTests::LogHR(HRESULT hr)
{
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenEventsTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestEventsAdminAddPlayerTag", &AutoGenEventsTests::TestEventsAdminAddPlayerTag); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestEventsAdminGetPlayerTags", &AutoGenEventsTests::TestEventsAdminGetPlayerTags); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestEventsAdminRemovePlayerTag", &AutoGenEventsTests::TestEventsAdminRemovePlayerTag); // TODO: debug failing test
#endif

    AddTest("TestEventsClientGetPlayerTags", &AutoGenEventsTests::TestEventsClientGetPlayerTags);

    AddTest("TestEventsClientWriteCharacterEvent", &AutoGenEventsTests::TestEventsClientWriteCharacterEvent);

    AddTest("TestEventsClientWritePlayerEvent", &AutoGenEventsTests::TestEventsClientWritePlayerEvent);

    AddTest("TestEventsClientWriteTitleEvent", &AutoGenEventsTests::TestEventsClientWriteTitleEvent);

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestEventsServerAddPlayerTag", &AutoGenEventsTests::TestEventsServerAddPlayerTag); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestEventsServerGetPlayerTags", &AutoGenEventsTests::TestEventsServerGetPlayerTags); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestEventsServerRemovePlayerTag", &AutoGenEventsTests::TestEventsServerRemovePlayerTag); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestEventsServerWriteCharacterEvent", &AutoGenEventsTests::TestEventsServerWriteCharacterEvent); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestEventsServerWritePlayerEvent", &AutoGenEventsTests::TestEventsServerWritePlayerEvent); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestEventsServerWriteTitleEvent", &AutoGenEventsTests::TestEventsServerWriteTitleEvent); // TODO: debug failing test
#endif

    AddTest("TestEventsWriteEvents", &AutoGenEventsTests::TestEventsWriteEvents);

    AddTest("TestEventsWriteTelemetryEvents", &AutoGenEventsTests::TestEventsWriteTelemetryEvents);
}

void AutoGenEventsTests::ClassSetUp()
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

void AutoGenEventsTests::ClassTearDown()
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

void AutoGenEventsTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AdminAddPlayerTag

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenEventsTests::TestEventsAdminAddPlayerTag(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFEventsAddPlayerTagRequestWrapper<> request;
    FillAdminAddPlayerTagRequest(request);
    LogAddPlayerTagRequest(&request.Model(), "TestEventsAdminAddPlayerTag");
    HRESULT hr = PFEventsAdminAddPlayerTagAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFEventsEventsAdminAddPlayerTagAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetPlayerTags

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenEventsTests::TestEventsAdminGetPlayerTags(TestContext& testContext)
{
    struct AdminGetPlayerTagsResultHolderStruct : public GetPlayerTagsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFEventsAdminGetPlayerTagsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFEventsAdminGetPlayerTagsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetPlayerTagsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetPlayerTagsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetPlayerTagsResultHolderStruct>>(testContext);

    PFEventsGetPlayerTagsRequestWrapper<> request;
    FillAdminGetPlayerTagsRequest(request);
    LogGetPlayerTagsRequest(&request.Model(), "TestEventsAdminGetPlayerTags");
    HRESULT hr = PFEventsAdminGetPlayerTagsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFEventsEventsAdminGetPlayerTagsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminRemovePlayerTag

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenEventsTests::TestEventsAdminRemovePlayerTag(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFEventsRemovePlayerTagRequestWrapper<> request;
    FillAdminRemovePlayerTagRequest(request);
    LogRemovePlayerTagRequest(&request.Model(), "TestEventsAdminRemovePlayerTag");
    HRESULT hr = PFEventsAdminRemovePlayerTagAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFEventsEventsAdminRemovePlayerTagAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientGetPlayerTags

void AutoGenEventsTests::TestEventsClientGetPlayerTags(TestContext& testContext)
{
    struct ClientGetPlayerTagsResultHolderStruct : public GetPlayerTagsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFEventsClientGetPlayerTagsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFEventsClientGetPlayerTagsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetPlayerTagsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetPlayerTagsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayerTagsResultHolderStruct>>(testContext);

    PFEventsGetPlayerTagsRequestWrapper<> request;
    FillClientGetPlayerTagsRequest(request);
    LogGetPlayerTagsRequest(&request.Model(), "TestEventsClientGetPlayerTags");
    HRESULT hr = PFEventsClientGetPlayerTagsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFEventsEventsClientGetPlayerTagsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientWriteCharacterEvent

void AutoGenEventsTests::TestEventsClientWriteCharacterEvent(TestContext& testContext)
{
    struct ClientWriteCharacterEventResultHolderStruct : public WriteEventResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFEventsClientWriteCharacterEventGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFEventsClientWriteCharacterEventGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogWriteEventResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientWriteCharacterEventResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientWriteCharacterEventResultHolderStruct>>(testContext);

    PFEventsWriteClientCharacterEventRequestWrapper<> request;
    FillClientWriteCharacterEventRequest(request);
    LogWriteClientCharacterEventRequest(&request.Model(), "TestEventsClientWriteCharacterEvent");
    HRESULT hr = PFEventsClientWriteCharacterEventAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFEventsEventsClientWriteCharacterEventAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientWritePlayerEvent

void AutoGenEventsTests::TestEventsClientWritePlayerEvent(TestContext& testContext)
{
    struct ClientWritePlayerEventResultHolderStruct : public WriteEventResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFEventsClientWritePlayerEventGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFEventsClientWritePlayerEventGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogWriteEventResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientWritePlayerEventResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientWritePlayerEventResultHolderStruct>>(testContext);

    PFEventsWriteClientPlayerEventRequestWrapper<> request;
    FillClientWritePlayerEventRequest(request);
    LogWriteClientPlayerEventRequest(&request.Model(), "TestEventsClientWritePlayerEvent");
    HRESULT hr = PFEventsClientWritePlayerEventAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFEventsEventsClientWritePlayerEventAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientWriteTitleEvent

void AutoGenEventsTests::TestEventsClientWriteTitleEvent(TestContext& testContext)
{
    struct ClientWriteTitleEventResultHolderStruct : public WriteEventResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFEventsClientWriteTitleEventGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFEventsClientWriteTitleEventGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogWriteEventResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientWriteTitleEventResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientWriteTitleEventResultHolderStruct>>(testContext);

    PFEventsWriteTitleEventRequestWrapper<> request;
    FillClientWriteTitleEventRequest(request);
    LogWriteTitleEventRequest(&request.Model(), "TestEventsClientWriteTitleEvent");
    HRESULT hr = PFEventsClientWriteTitleEventAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFEventsEventsClientWriteTitleEventAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerAddPlayerTag

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenEventsTests::TestEventsServerAddPlayerTag(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFEventsAddPlayerTagRequestWrapper<> request;
    FillServerAddPlayerTagRequest(request);
    LogAddPlayerTagRequest(&request.Model(), "TestEventsServerAddPlayerTag");
    HRESULT hr = PFEventsServerAddPlayerTagAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFEventsEventsServerAddPlayerTagAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetPlayerTags

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenEventsTests::TestEventsServerGetPlayerTags(TestContext& testContext)
{
    struct ServerGetPlayerTagsResultHolderStruct : public GetPlayerTagsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFEventsServerGetPlayerTagsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFEventsServerGetPlayerTagsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetPlayerTagsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetPlayerTagsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayerTagsResultHolderStruct>>(testContext);

    PFEventsGetPlayerTagsRequestWrapper<> request;
    FillServerGetPlayerTagsRequest(request);
    LogGetPlayerTagsRequest(&request.Model(), "TestEventsServerGetPlayerTags");
    HRESULT hr = PFEventsServerGetPlayerTagsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFEventsEventsServerGetPlayerTagsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerRemovePlayerTag

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenEventsTests::TestEventsServerRemovePlayerTag(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFEventsRemovePlayerTagRequestWrapper<> request;
    FillServerRemovePlayerTagRequest(request);
    LogRemovePlayerTagRequest(&request.Model(), "TestEventsServerRemovePlayerTag");
    HRESULT hr = PFEventsServerRemovePlayerTagAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFEventsEventsServerRemovePlayerTagAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerWriteCharacterEvent

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenEventsTests::TestEventsServerWriteCharacterEvent(TestContext& testContext)
{
    struct ServerWriteCharacterEventResultHolderStruct : public WriteEventResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFEventsServerWriteCharacterEventGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFEventsServerWriteCharacterEventGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogWriteEventResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerWriteCharacterEventResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerWriteCharacterEventResultHolderStruct>>(testContext);

    PFEventsWriteServerCharacterEventRequestWrapper<> request;
    FillServerWriteCharacterEventRequest(request);
    LogWriteServerCharacterEventRequest(&request.Model(), "TestEventsServerWriteCharacterEvent");
    HRESULT hr = PFEventsServerWriteCharacterEventAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFEventsEventsServerWriteCharacterEventAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerWritePlayerEvent

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenEventsTests::TestEventsServerWritePlayerEvent(TestContext& testContext)
{
    struct ServerWritePlayerEventResultHolderStruct : public WriteEventResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFEventsServerWritePlayerEventGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFEventsServerWritePlayerEventGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogWriteEventResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerWritePlayerEventResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerWritePlayerEventResultHolderStruct>>(testContext);

    PFEventsWriteServerPlayerEventRequestWrapper<> request;
    FillServerWritePlayerEventRequest(request);
    LogWriteServerPlayerEventRequest(&request.Model(), "TestEventsServerWritePlayerEvent");
    HRESULT hr = PFEventsServerWritePlayerEventAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFEventsEventsServerWritePlayerEventAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerWriteTitleEvent

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenEventsTests::TestEventsServerWriteTitleEvent(TestContext& testContext)
{
    struct ServerWriteTitleEventResultHolderStruct : public WriteEventResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFEventsServerWriteTitleEventGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFEventsServerWriteTitleEventGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogWriteEventResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerWriteTitleEventResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerWriteTitleEventResultHolderStruct>>(testContext);

    PFEventsWriteTitleEventRequestWrapper<> request;
    FillServerWriteTitleEventRequest(request);
    LogWriteTitleEventRequest(&request.Model(), "TestEventsServerWriteTitleEvent");
    HRESULT hr = PFEventsServerWriteTitleEventAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFEventsEventsServerWriteTitleEventAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region WriteEvents

void AutoGenEventsTests::TestEventsWriteEvents(TestContext& testContext)
{
    struct WriteEventsResultHolderStruct : public WriteEventsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFEventsWriteEventsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFEventsWriteEventsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogWriteEventsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateWriteEventsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<WriteEventsResultHolderStruct>>(testContext);

    PFEventsWriteEventsRequestWrapper<> request;
    FillWriteEventsRequest(request);
    LogWriteEventsRequest(&request.Model(), "TestEventsWriteEvents");
    HRESULT hr = PFEventsWriteEventsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFEventsEventsWriteEventsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region WriteTelemetryEvents

void AutoGenEventsTests::TestEventsWriteTelemetryEvents(TestContext& testContext)
{
    struct WriteTelemetryEventsResultHolderStruct : public WriteEventsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFEventsWriteTelemetryEventsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFEventsWriteTelemetryEventsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogWriteEventsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateWriteTelemetryEventsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<WriteTelemetryEventsResultHolderStruct>>(testContext);

    PFEventsWriteEventsRequestWrapper<> request;
    FillWriteTelemetryEventsRequest(request);
    LogWriteEventsRequest(&request.Model(), "TestEventsWriteTelemetryEvents");
    HRESULT hr = PFEventsWriteTelemetryEventsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFEventsEventsWriteTelemetryEventsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
