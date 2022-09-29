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
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenAnalyticsTests::AddTests()
{
    // Generated tests 
    AddTest("TestAnalyticsClientReportDeviceInfo", &AutoGenAnalyticsTests::TestAnalyticsClientReportDeviceInfo);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAnalyticsGetDetails", &AutoGenAnalyticsTests::TestAnalyticsGetDetails);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAnalyticsGetLimits", &AutoGenAnalyticsTests::TestAnalyticsGetLimits);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAnalyticsGetOperationStatus", &AutoGenAnalyticsTests::TestAnalyticsGetOperationStatus);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAnalyticsGetPendingOperations", &AutoGenAnalyticsTests::TestAnalyticsGetPendingOperations);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAnalyticsSetPerformance", &AutoGenAnalyticsTests::TestAnalyticsSetPerformance);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestAnalyticsSetStorageRetention", &AutoGenAnalyticsTests::TestAnalyticsSetStorageRetention);
#endif
}

void AutoGenAnalyticsTests::ClassSetUp()
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
    FillClientReportDeviceInfoRequest(request);
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

#pragma region GetDetails

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAnalyticsTests::TestAnalyticsGetDetails(TestContext& testContext)
{
    struct GetDetailsResultHolderStruct : public InsightsGetDetailsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsGetDetailsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsGetDetailsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogInsightsGetDetailsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetDetailsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetDetailsResultHolderStruct>>(testContext);

    PFAnalyticsInsightsEmptyRequestWrapper<> request;
    FillGetDetailsRequest(request);
    LogInsightsEmptyRequest(&request.Model(), "TestAnalyticsGetDetails");
    HRESULT hr = PFAnalyticsGetDetailsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsGetDetailsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetLimits

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAnalyticsTests::TestAnalyticsGetLimits(TestContext& testContext)
{
    struct GetLimitsResultHolderStruct : public InsightsGetLimitsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsGetLimitsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsGetLimitsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogInsightsGetLimitsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetLimitsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetLimitsResultHolderStruct>>(testContext);

    PFAnalyticsInsightsEmptyRequestWrapper<> request;
    FillGetLimitsRequest(request);
    LogInsightsEmptyRequest(&request.Model(), "TestAnalyticsGetLimits");
    HRESULT hr = PFAnalyticsGetLimitsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsGetLimitsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetOperationStatus

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAnalyticsTests::TestAnalyticsGetOperationStatus(TestContext& testContext)
{
    struct GetOperationStatusResultHolderStruct : public InsightsGetOperationStatusResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsGetOperationStatusGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsGetOperationStatusGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogInsightsGetOperationStatusResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetOperationStatusResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetOperationStatusResultHolderStruct>>(testContext);

    PFAnalyticsInsightsGetOperationStatusRequestWrapper<> request;
    FillGetOperationStatusRequest(request);
    LogInsightsGetOperationStatusRequest(&request.Model(), "TestAnalyticsGetOperationStatus");
    HRESULT hr = PFAnalyticsGetOperationStatusAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsGetOperationStatusAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetPendingOperations

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAnalyticsTests::TestAnalyticsGetPendingOperations(TestContext& testContext)
{
    struct GetPendingOperationsResultHolderStruct : public InsightsGetPendingOperationsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsGetPendingOperationsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsGetPendingOperationsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogInsightsGetPendingOperationsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetPendingOperationsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetPendingOperationsResultHolderStruct>>(testContext);

    PFAnalyticsInsightsGetPendingOperationsRequestWrapper<> request;
    FillGetPendingOperationsRequest(request);
    LogInsightsGetPendingOperationsRequest(&request.Model(), "TestAnalyticsGetPendingOperations");
    HRESULT hr = PFAnalyticsGetPendingOperationsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsGetPendingOperationsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region SetPerformance

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAnalyticsTests::TestAnalyticsSetPerformance(TestContext& testContext)
{
    struct SetPerformanceResultHolderStruct : public InsightsOperationResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsSetPerformanceGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsSetPerformanceGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogInsightsOperationResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateSetPerformanceResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<SetPerformanceResultHolderStruct>>(testContext);

    PFAnalyticsInsightsSetPerformanceRequestWrapper<> request;
    FillSetPerformanceRequest(request);
    LogInsightsSetPerformanceRequest(&request.Model(), "TestAnalyticsSetPerformance");
    HRESULT hr = PFAnalyticsSetPerformanceAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsSetPerformanceAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region SetStorageRetention

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenAnalyticsTests::TestAnalyticsSetStorageRetention(TestContext& testContext)
{
    struct SetStorageRetentionResultHolderStruct : public InsightsOperationResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAnalyticsSetStorageRetentionGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAnalyticsSetStorageRetentionGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogInsightsOperationResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateSetStorageRetentionResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<SetStorageRetentionResultHolderStruct>>(testContext);

    PFAnalyticsInsightsSetStorageRetentionRequestWrapper<> request;
    FillSetStorageRetentionRequest(request);
    LogInsightsSetStorageRetentionRequest(&request.Model(), "TestAnalyticsSetStorageRetention");
    HRESULT hr = PFAnalyticsSetStorageRetentionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAnalyticsAnalyticsSetStorageRetentionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
