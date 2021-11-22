#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenAnalyticsTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenAnalyticsTests::AnalyticsTestData AutoGenAnalyticsTests::testData;

void AutoGenAnalyticsTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenAnalyticsTests::LogHR(HRESULT hr)
{
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenAnalyticsTests::AddTests()
{
    // Generated tests 
    AddTest("TestAnalyticsClientReportDeviceInfo", &AutoGenAnalyticsTests::TestAnalyticsClientReportDeviceInfo);

    AddTest("TestAnalyticsClientWriteCharacterEvent", &AutoGenAnalyticsTests::TestAnalyticsClientWriteCharacterEvent);

    AddTest("TestAnalyticsClientWritePlayerEvent", &AutoGenAnalyticsTests::TestAnalyticsClientWritePlayerEvent);

    AddTest("TestAnalyticsClientWriteTitleEvent", &AutoGenAnalyticsTests::TestAnalyticsClientWriteTitleEvent);

    AddTest("TestAnalyticsServerWriteCharacterEvent", &AutoGenAnalyticsTests::TestAnalyticsServerWriteCharacterEvent);

    AddTest("TestAnalyticsServerWritePlayerEvent", &AutoGenAnalyticsTests::TestAnalyticsServerWritePlayerEvent);

    AddTest("TestAnalyticsServerWriteTitleEvent", &AutoGenAnalyticsTests::TestAnalyticsServerWriteTitleEvent);

    AddTest("TestAnalyticsGetDetails", &AutoGenAnalyticsTests::TestAnalyticsGetDetails);

    AddTest("TestAnalyticsGetLimits", &AutoGenAnalyticsTests::TestAnalyticsGetLimits);

    AddTest("TestAnalyticsGetOperationStatus", &AutoGenAnalyticsTests::TestAnalyticsGetOperationStatus);

    AddTest("TestAnalyticsGetPendingOperations", &AutoGenAnalyticsTests::TestAnalyticsGetPendingOperations);

    AddTest("TestAnalyticsSetPerformance", &AutoGenAnalyticsTests::TestAnalyticsSetPerformance);

    AddTest("TestAnalyticsSetStorageRetention", &AutoGenAnalyticsTests::TestAnalyticsSetStorageRetention);
}

void AutoGenAnalyticsTests::ClassSetUp()
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

void AutoGenAnalyticsTests::ClassTearDown()
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

void AutoGenAnalyticsTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region ClientReportDeviceInfo

void AutoGenAnalyticsTests::TestAnalyticsClientReportDeviceInfo(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAnalyticsDeviceInfoRequestWrapper<> request;
    FillDeviceInfoRequest(request);
    LogDeviceInfoRequest(&request.Model(), "TestAnalyticsClientReportDeviceInfo");
    HRESULT hr = PFAnalyticsClientReportDeviceInfoAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsClientReportDeviceInfoAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientWriteCharacterEvent

void AutoGenAnalyticsTests::TestAnalyticsClientWriteCharacterEvent(TestContext& testContext)
{
    struct ClientWriteCharacterEventResultHolder : public WriteEventResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsClientWriteCharacterEventGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsClientWriteCharacterEventGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAnalyticsWriteEventResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAnalyticsWriteEventResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientWriteCharacterEventResultHolder>>(testContext);

    PFAnalyticsWriteClientCharacterEventRequestWrapper<> request;
    FillWriteClientCharacterEventRequest(request);
    LogWriteClientCharacterEventRequest(&request.Model(), "TestAnalyticsClientWriteCharacterEvent");
    HRESULT hr = PFAnalyticsClientWriteCharacterEventAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsClientWriteCharacterEventAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientWritePlayerEvent

void AutoGenAnalyticsTests::TestAnalyticsClientWritePlayerEvent(TestContext& testContext)
{
    struct ClientWritePlayerEventResultHolder : public WriteEventResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsClientWritePlayerEventGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsClientWritePlayerEventGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAnalyticsWriteEventResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAnalyticsWriteEventResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientWritePlayerEventResultHolder>>(testContext);

    PFAnalyticsWriteClientPlayerEventRequestWrapper<> request;
    FillWriteClientPlayerEventRequest(request);
    LogWriteClientPlayerEventRequest(&request.Model(), "TestAnalyticsClientWritePlayerEvent");
    HRESULT hr = PFAnalyticsClientWritePlayerEventAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsClientWritePlayerEventAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientWriteTitleEvent

void AutoGenAnalyticsTests::TestAnalyticsClientWriteTitleEvent(TestContext& testContext)
{
    struct ClientWriteTitleEventResultHolder : public WriteEventResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsClientWriteTitleEventGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsClientWriteTitleEventGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAnalyticsWriteEventResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAnalyticsWriteEventResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientWriteTitleEventResultHolder>>(testContext);

    PFAnalyticsWriteTitleEventRequestWrapper<> request;
    FillWriteTitleEventRequest(request);
    LogWriteTitleEventRequest(&request.Model(), "TestAnalyticsClientWriteTitleEvent");
    HRESULT hr = PFAnalyticsClientWriteTitleEventAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsClientWriteTitleEventAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerWriteCharacterEvent

void AutoGenAnalyticsTests::TestAnalyticsServerWriteCharacterEvent(TestContext& testContext)
{
    struct ServerWriteCharacterEventResultHolder : public WriteEventResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsServerWriteCharacterEventGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsServerWriteCharacterEventGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAnalyticsWriteEventResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAnalyticsWriteEventResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerWriteCharacterEventResultHolder>>(testContext);

    PFAnalyticsWriteServerCharacterEventRequestWrapper<> request;
    FillWriteServerCharacterEventRequest(request);
    LogWriteServerCharacterEventRequest(&request.Model(), "TestAnalyticsServerWriteCharacterEvent");
    HRESULT hr = PFAnalyticsServerWriteCharacterEventAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsServerWriteCharacterEventAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerWritePlayerEvent

void AutoGenAnalyticsTests::TestAnalyticsServerWritePlayerEvent(TestContext& testContext)
{
    struct ServerWritePlayerEventResultHolder : public WriteEventResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsServerWritePlayerEventGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsServerWritePlayerEventGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAnalyticsWriteEventResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAnalyticsWriteEventResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerWritePlayerEventResultHolder>>(testContext);

    PFAnalyticsWriteServerPlayerEventRequestWrapper<> request;
    FillWriteServerPlayerEventRequest(request);
    LogWriteServerPlayerEventRequest(&request.Model(), "TestAnalyticsServerWritePlayerEvent");
    HRESULT hr = PFAnalyticsServerWritePlayerEventAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsServerWritePlayerEventAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerWriteTitleEvent

void AutoGenAnalyticsTests::TestAnalyticsServerWriteTitleEvent(TestContext& testContext)
{
    struct ServerWriteTitleEventResultHolder : public WriteEventResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsServerWriteTitleEventGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsServerWriteTitleEventGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAnalyticsWriteEventResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAnalyticsWriteEventResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerWriteTitleEventResultHolder>>(testContext);

    PFAnalyticsWriteTitleEventRequestWrapper<> request;
    FillWriteTitleEventRequest(request);
    LogWriteTitleEventRequest(&request.Model(), "TestAnalyticsServerWriteTitleEvent");
    HRESULT hr = PFAnalyticsServerWriteTitleEventAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsServerWriteTitleEventAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetDetails

void AutoGenAnalyticsTests::TestAnalyticsGetDetails(TestContext& testContext)
{
    struct GetDetailsResultHolder : public InsightsGetDetailsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsGetDetailsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsGetDetailsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAnalyticsInsightsGetDetailsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAnalyticsInsightsGetDetailsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetDetailsResultHolder>>(testContext);

    PFAnalyticsInsightsEmptyRequestWrapper<> request;
    FillInsightsEmptyRequest(request);
    LogInsightsEmptyRequest(&request.Model(), "TestAnalyticsGetDetails");
    HRESULT hr = PFAnalyticsGetDetailsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsGetDetailsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetLimits

void AutoGenAnalyticsTests::TestAnalyticsGetLimits(TestContext& testContext)
{
    struct GetLimitsResultHolder : public InsightsGetLimitsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsGetLimitsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsGetLimitsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAnalyticsInsightsGetLimitsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAnalyticsInsightsGetLimitsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetLimitsResultHolder>>(testContext);

    PFAnalyticsInsightsEmptyRequestWrapper<> request;
    FillInsightsEmptyRequest(request);
    LogInsightsEmptyRequest(&request.Model(), "TestAnalyticsGetLimits");
    HRESULT hr = PFAnalyticsGetLimitsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsGetLimitsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetOperationStatus

void AutoGenAnalyticsTests::TestAnalyticsGetOperationStatus(TestContext& testContext)
{
    struct GetOperationStatusResultHolder : public InsightsGetOperationStatusResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsGetOperationStatusGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsGetOperationStatusGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAnalyticsInsightsGetOperationStatusResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAnalyticsInsightsGetOperationStatusResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetOperationStatusResultHolder>>(testContext);

    PFAnalyticsInsightsGetOperationStatusRequestWrapper<> request;
    FillInsightsGetOperationStatusRequest(request);
    LogInsightsGetOperationStatusRequest(&request.Model(), "TestAnalyticsGetOperationStatus");
    HRESULT hr = PFAnalyticsGetOperationStatusAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsGetOperationStatusAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetPendingOperations

void AutoGenAnalyticsTests::TestAnalyticsGetPendingOperations(TestContext& testContext)
{
    struct GetPendingOperationsResultHolder : public InsightsGetPendingOperationsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsGetPendingOperationsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsGetPendingOperationsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAnalyticsInsightsGetPendingOperationsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAnalyticsInsightsGetPendingOperationsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetPendingOperationsResultHolder>>(testContext);

    PFAnalyticsInsightsGetPendingOperationsRequestWrapper<> request;
    FillInsightsGetPendingOperationsRequest(request);
    LogInsightsGetPendingOperationsRequest(&request.Model(), "TestAnalyticsGetPendingOperations");
    HRESULT hr = PFAnalyticsGetPendingOperationsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsGetPendingOperationsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region SetPerformance

void AutoGenAnalyticsTests::TestAnalyticsSetPerformance(TestContext& testContext)
{
    struct SetPerformanceResultHolder : public InsightsOperationResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsSetPerformanceGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsSetPerformanceGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAnalyticsInsightsOperationResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAnalyticsInsightsOperationResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<SetPerformanceResultHolder>>(testContext);

    PFAnalyticsInsightsSetPerformanceRequestWrapper<> request;
    FillInsightsSetPerformanceRequest(request);
    LogInsightsSetPerformanceRequest(&request.Model(), "TestAnalyticsSetPerformance");
    HRESULT hr = PFAnalyticsSetPerformanceAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsSetPerformanceAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region SetStorageRetention

void AutoGenAnalyticsTests::TestAnalyticsSetStorageRetention(TestContext& testContext)
{
    struct SetStorageRetentionResultHolder : public InsightsOperationResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsSetStorageRetentionGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsSetStorageRetentionGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAnalyticsInsightsOperationResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAnalyticsInsightsOperationResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<SetStorageRetentionResultHolder>>(testContext);

    PFAnalyticsInsightsSetStorageRetentionRequestWrapper<> request;
    FillInsightsSetStorageRetentionRequest(request);
    LogInsightsSetStorageRetentionRequest(&request.Model(), "TestAnalyticsSetStorageRetention");
    HRESULT hr = PFAnalyticsSetStorageRetentionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsSetStorageRetentionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
