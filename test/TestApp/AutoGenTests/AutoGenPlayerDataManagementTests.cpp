#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenPlayerDataManagementTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenPlayerDataManagementTests::PlayerDataManagementTestData AutoGenPlayerDataManagementTests::testData;

void AutoGenPlayerDataManagementTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenPlayerDataManagementTests::LogHR(HRESULT hr)
{
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenPlayerDataManagementTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementAdminGetDataReport", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetDataReport); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementAdminGetUserData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementAdminGetUserInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserInternalData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementAdminGetUserPublisherData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserPublisherData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementAdminGetUserPublisherInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserPublisherInternalData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementAdminGetUserPublisherReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserPublisherReadOnlyData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementAdminGetUserReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserReadOnlyData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementAdminUpdateUserData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementAdminUpdateUserInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserInternalData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementAdminUpdateUserPublisherData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserPublisherData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementAdminUpdateUserPublisherInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserPublisherInternalData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementAdminUpdateUserPublisherReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserPublisherReadOnlyData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementAdminUpdateUserReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserReadOnlyData); // TODO: debug failing test
#endif

    AddTest("TestPlayerDataManagementClientGetUserData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetUserData);

    AddTest("TestPlayerDataManagementClientGetUserPublisherData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetUserPublisherData);

    AddTest("TestPlayerDataManagementClientGetUserPublisherReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetUserPublisherReadOnlyData);

    AddTest("TestPlayerDataManagementClientGetUserReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetUserReadOnlyData);

    AddTest("TestPlayerDataManagementClientUpdateUserData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientUpdateUserData);

    AddTest("TestPlayerDataManagementClientUpdateUserPublisherData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientUpdateUserPublisherData);

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementServerGetUserData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementServerGetUserInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserInternalData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementServerGetUserPublisherData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserPublisherData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementServerGetUserPublisherInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserPublisherInternalData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementServerGetUserPublisherReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserPublisherReadOnlyData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementServerGetUserReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserReadOnlyData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementServerUpdateUserData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementServerUpdateUserInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserInternalData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementServerUpdateUserPublisherData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserPublisherData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementServerUpdateUserPublisherInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserPublisherInternalData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementServerUpdateUserPublisherReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserPublisherReadOnlyData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestPlayerDataManagementServerUpdateUserReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserReadOnlyData); // TODO: debug failing test
#endif
}

void AutoGenPlayerDataManagementTests::ClassSetUp()
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

void AutoGenPlayerDataManagementTests::ClassTearDown()
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

void AutoGenPlayerDataManagementTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AdminGetDataReport

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetDataReport(TestContext& testContext)
{
    struct AdminGetDataReportResultHolderStruct : public GetDataReportResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetDataReportGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetDataReportGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetDataReportResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetDataReportResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetDataReportResultHolderStruct>>(testContext);

    PFPlayerDataManagementGetDataReportRequestWrapper<> request;
    FillAdminGetDataReportRequest(request);
    LogGetDataReportRequest(&request.Model(), "TestPlayerDataManagementAdminGetDataReport");
    HRESULT hr = PFPlayerDataManagementAdminGetDataReportAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminGetDataReportAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetUserData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserData(TestContext& testContext)
{
    struct AdminGetUserDataResultHolderStruct : public AdminGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetUserDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillAdminGetUserDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminGetUserData");
    HRESULT hr = PFPlayerDataManagementAdminGetUserDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminGetUserDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetUserInternalData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserInternalData(TestContext& testContext)
{
    struct AdminGetUserInternalDataResultHolderStruct : public AdminGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserInternalDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserInternalDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetUserInternalDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserInternalDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillAdminGetUserInternalDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminGetUserInternalData");
    HRESULT hr = PFPlayerDataManagementAdminGetUserInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminGetUserInternalDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetUserPublisherData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserPublisherData(TestContext& testContext)
{
    struct AdminGetUserPublisherDataResultHolderStruct : public AdminGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserPublisherDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserPublisherDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetUserPublisherDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserPublisherDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillAdminGetUserPublisherDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminGetUserPublisherData");
    HRESULT hr = PFPlayerDataManagementAdminGetUserPublisherDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminGetUserPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetUserPublisherInternalData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserPublisherInternalData(TestContext& testContext)
{
    struct AdminGetUserPublisherInternalDataResultHolderStruct : public AdminGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserPublisherInternalDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserPublisherInternalDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetUserPublisherInternalDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserPublisherInternalDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillAdminGetUserPublisherInternalDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminGetUserPublisherInternalData");
    HRESULT hr = PFPlayerDataManagementAdminGetUserPublisherInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminGetUserPublisherInternalDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetUserPublisherReadOnlyData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserPublisherReadOnlyData(TestContext& testContext)
{
    struct AdminGetUserPublisherReadOnlyDataResultHolderStruct : public AdminGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserPublisherReadOnlyDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserPublisherReadOnlyDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetUserPublisherReadOnlyDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserPublisherReadOnlyDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillAdminGetUserPublisherReadOnlyDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminGetUserPublisherReadOnlyData");
    HRESULT hr = PFPlayerDataManagementAdminGetUserPublisherReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminGetUserPublisherReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetUserReadOnlyData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserReadOnlyData(TestContext& testContext)
{
    struct AdminGetUserReadOnlyDataResultHolderStruct : public AdminGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserReadOnlyDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserReadOnlyDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetUserReadOnlyDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserReadOnlyDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillAdminGetUserReadOnlyDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminGetUserReadOnlyData");
    HRESULT hr = PFPlayerDataManagementAdminGetUserReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminGetUserReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdateUserData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserData(TestContext& testContext)
{
    struct AdminUpdateUserDataResultHolderStruct : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminUpdateUserDataGetResult(async, &result)));
            LogUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminUpdateUserDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementAdminUpdateUserDataRequestWrapper<> request;
    FillAdminUpdateUserDataRequest(request);
    LogAdminUpdateUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminUpdateUserData");
    HRESULT hr = PFPlayerDataManagementAdminUpdateUserDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminUpdateUserDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdateUserInternalData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserInternalData(TestContext& testContext)
{
    struct AdminUpdateUserInternalDataResultHolderStruct : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminUpdateUserInternalDataGetResult(async, &result)));
            LogUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminUpdateUserInternalDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserInternalDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementUpdateUserInternalDataRequestWrapper<> request;
    FillAdminUpdateUserInternalDataRequest(request);
    LogUpdateUserInternalDataRequest(&request.Model(), "TestPlayerDataManagementAdminUpdateUserInternalData");
    HRESULT hr = PFPlayerDataManagementAdminUpdateUserInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminUpdateUserInternalDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdateUserPublisherData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserPublisherData(TestContext& testContext)
{
    struct AdminUpdateUserPublisherDataResultHolderStruct : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminUpdateUserPublisherDataGetResult(async, &result)));
            LogUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminUpdateUserPublisherDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserPublisherDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementAdminUpdateUserDataRequestWrapper<> request;
    FillAdminUpdateUserPublisherDataRequest(request);
    LogAdminUpdateUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminUpdateUserPublisherData");
    HRESULT hr = PFPlayerDataManagementAdminUpdateUserPublisherDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminUpdateUserPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdateUserPublisherInternalData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserPublisherInternalData(TestContext& testContext)
{
    struct AdminUpdateUserPublisherInternalDataResultHolderStruct : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminUpdateUserPublisherInternalDataGetResult(async, &result)));
            LogUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminUpdateUserPublisherInternalDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserPublisherInternalDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementUpdateUserInternalDataRequestWrapper<> request;
    FillAdminUpdateUserPublisherInternalDataRequest(request);
    LogUpdateUserInternalDataRequest(&request.Model(), "TestPlayerDataManagementAdminUpdateUserPublisherInternalData");
    HRESULT hr = PFPlayerDataManagementAdminUpdateUserPublisherInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminUpdateUserPublisherInternalDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdateUserPublisherReadOnlyData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserPublisherReadOnlyData(TestContext& testContext)
{
    struct AdminUpdateUserPublisherReadOnlyDataResultHolderStruct : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminUpdateUserPublisherReadOnlyDataGetResult(async, &result)));
            LogUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminUpdateUserPublisherReadOnlyDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserPublisherReadOnlyDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementAdminUpdateUserDataRequestWrapper<> request;
    FillAdminUpdateUserPublisherReadOnlyDataRequest(request);
    LogAdminUpdateUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminUpdateUserPublisherReadOnlyData");
    HRESULT hr = PFPlayerDataManagementAdminUpdateUserPublisherReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminUpdateUserPublisherReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdateUserReadOnlyData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserReadOnlyData(TestContext& testContext)
{
    struct AdminUpdateUserReadOnlyDataResultHolderStruct : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminUpdateUserReadOnlyDataGetResult(async, &result)));
            LogUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminUpdateUserReadOnlyDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserReadOnlyDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementAdminUpdateUserDataRequestWrapper<> request;
    FillAdminUpdateUserReadOnlyDataRequest(request);
    LogAdminUpdateUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminUpdateUserReadOnlyData");
    HRESULT hr = PFPlayerDataManagementAdminUpdateUserReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminUpdateUserReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientGetUserData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetUserData(TestContext& testContext)
{
    struct ClientGetUserDataResultHolderStruct : public ClientGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetUserDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetUserDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogClientGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetUserDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetUserDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillClientGetUserDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementClientGetUserData");
    HRESULT hr = PFPlayerDataManagementClientGetUserDataAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementClientGetUserDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetUserPublisherData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetUserPublisherData(TestContext& testContext)
{
    struct ClientGetUserPublisherDataResultHolderStruct : public ClientGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetUserPublisherDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetUserPublisherDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogClientGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetUserPublisherDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetUserPublisherDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillClientGetUserPublisherDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementClientGetUserPublisherData");
    HRESULT hr = PFPlayerDataManagementClientGetUserPublisherDataAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementClientGetUserPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetUserPublisherReadOnlyData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetUserPublisherReadOnlyData(TestContext& testContext)
{
    struct ClientGetUserPublisherReadOnlyDataResultHolderStruct : public ClientGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetUserPublisherReadOnlyDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetUserPublisherReadOnlyDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogClientGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetUserPublisherReadOnlyDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetUserPublisherReadOnlyDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillClientGetUserPublisherReadOnlyDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementClientGetUserPublisherReadOnlyData");
    HRESULT hr = PFPlayerDataManagementClientGetUserPublisherReadOnlyDataAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementClientGetUserPublisherReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetUserReadOnlyData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetUserReadOnlyData(TestContext& testContext)
{
    struct ClientGetUserReadOnlyDataResultHolderStruct : public ClientGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetUserReadOnlyDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetUserReadOnlyDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogClientGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetUserReadOnlyDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetUserReadOnlyDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillClientGetUserReadOnlyDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementClientGetUserReadOnlyData");
    HRESULT hr = PFPlayerDataManagementClientGetUserReadOnlyDataAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementClientGetUserReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientUpdateUserData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientUpdateUserData(TestContext& testContext)
{
    struct ClientUpdateUserDataResultHolderStruct : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientUpdateUserDataGetResult(async, &result)));
            LogUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientUpdateUserDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientUpdateUserDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementClientUpdateUserDataRequestWrapper<> request;
    FillClientUpdateUserDataRequest(request);
    LogClientUpdateUserDataRequest(&request.Model(), "TestPlayerDataManagementClientUpdateUserData");
    HRESULT hr = PFPlayerDataManagementClientUpdateUserDataAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementClientUpdateUserDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientUpdateUserPublisherData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientUpdateUserPublisherData(TestContext& testContext)
{
    struct ClientUpdateUserPublisherDataResultHolderStruct : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientUpdateUserPublisherDataGetResult(async, &result)));
            LogUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientUpdateUserPublisherDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientUpdateUserPublisherDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementClientUpdateUserDataRequestWrapper<> request;
    FillClientUpdateUserPublisherDataRequest(request);
    LogClientUpdateUserDataRequest(&request.Model(), "TestPlayerDataManagementClientUpdateUserPublisherData");
    HRESULT hr = PFPlayerDataManagementClientUpdateUserPublisherDataAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementClientUpdateUserPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetUserData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserData(TestContext& testContext)
{
    struct ServerGetUserDataResultHolderStruct : public ServerGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetUserDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillServerGetUserDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementServerGetUserData");
    HRESULT hr = PFPlayerDataManagementServerGetUserDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetUserDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetUserInternalData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserInternalData(TestContext& testContext)
{
    struct ServerGetUserInternalDataResultHolderStruct : public ServerGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserInternalDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserInternalDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetUserInternalDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserInternalDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillServerGetUserInternalDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementServerGetUserInternalData");
    HRESULT hr = PFPlayerDataManagementServerGetUserInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetUserInternalDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetUserPublisherData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserPublisherData(TestContext& testContext)
{
    struct ServerGetUserPublisherDataResultHolderStruct : public ServerGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserPublisherDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserPublisherDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetUserPublisherDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserPublisherDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillServerGetUserPublisherDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementServerGetUserPublisherData");
    HRESULT hr = PFPlayerDataManagementServerGetUserPublisherDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetUserPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetUserPublisherInternalData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserPublisherInternalData(TestContext& testContext)
{
    struct ServerGetUserPublisherInternalDataResultHolderStruct : public ServerGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserPublisherInternalDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserPublisherInternalDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetUserPublisherInternalDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserPublisherInternalDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillServerGetUserPublisherInternalDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementServerGetUserPublisherInternalData");
    HRESULT hr = PFPlayerDataManagementServerGetUserPublisherInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetUserPublisherInternalDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetUserPublisherReadOnlyData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserPublisherReadOnlyData(TestContext& testContext)
{
    struct ServerGetUserPublisherReadOnlyDataResultHolderStruct : public ServerGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserPublisherReadOnlyDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserPublisherReadOnlyDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetUserPublisherReadOnlyDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserPublisherReadOnlyDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillServerGetUserPublisherReadOnlyDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementServerGetUserPublisherReadOnlyData");
    HRESULT hr = PFPlayerDataManagementServerGetUserPublisherReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetUserPublisherReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetUserReadOnlyData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserReadOnlyData(TestContext& testContext)
{
    struct ServerGetUserReadOnlyDataResultHolderStruct : public ServerGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserReadOnlyDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserReadOnlyDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetUserReadOnlyDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserReadOnlyDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillServerGetUserReadOnlyDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementServerGetUserReadOnlyData");
    HRESULT hr = PFPlayerDataManagementServerGetUserReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetUserReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerUpdateUserData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserData(TestContext& testContext)
{
    struct ServerUpdateUserDataResultHolderStruct : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerUpdateUserDataGetResult(async, &result)));
            LogUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerUpdateUserDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateUserDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementServerUpdateUserDataRequestWrapper<> request;
    FillServerUpdateUserDataRequest(request);
    LogServerUpdateUserDataRequest(&request.Model(), "TestPlayerDataManagementServerUpdateUserData");
    HRESULT hr = PFPlayerDataManagementServerUpdateUserDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerUpdateUserDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerUpdateUserInternalData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserInternalData(TestContext& testContext)
{
    struct ServerUpdateUserInternalDataResultHolderStruct : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerUpdateUserInternalDataGetResult(async, &result)));
            LogUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerUpdateUserInternalDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateUserInternalDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementUpdateUserInternalDataRequestWrapper<> request;
    FillServerUpdateUserInternalDataRequest(request);
    LogUpdateUserInternalDataRequest(&request.Model(), "TestPlayerDataManagementServerUpdateUserInternalData");
    HRESULT hr = PFPlayerDataManagementServerUpdateUserInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerUpdateUserInternalDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerUpdateUserPublisherData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserPublisherData(TestContext& testContext)
{
    struct ServerUpdateUserPublisherDataResultHolderStruct : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerUpdateUserPublisherDataGetResult(async, &result)));
            LogUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerUpdateUserPublisherDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateUserPublisherDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementServerUpdateUserDataRequestWrapper<> request;
    FillServerUpdateUserPublisherDataRequest(request);
    LogServerUpdateUserDataRequest(&request.Model(), "TestPlayerDataManagementServerUpdateUserPublisherData");
    HRESULT hr = PFPlayerDataManagementServerUpdateUserPublisherDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerUpdateUserPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerUpdateUserPublisherInternalData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserPublisherInternalData(TestContext& testContext)
{
    struct ServerUpdateUserPublisherInternalDataResultHolderStruct : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerUpdateUserPublisherInternalDataGetResult(async, &result)));
            LogUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerUpdateUserPublisherInternalDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateUserPublisherInternalDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementUpdateUserInternalDataRequestWrapper<> request;
    FillServerUpdateUserPublisherInternalDataRequest(request);
    LogUpdateUserInternalDataRequest(&request.Model(), "TestPlayerDataManagementServerUpdateUserPublisherInternalData");
    HRESULT hr = PFPlayerDataManagementServerUpdateUserPublisherInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerUpdateUserPublisherInternalDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerUpdateUserPublisherReadOnlyData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserPublisherReadOnlyData(TestContext& testContext)
{
    struct ServerUpdateUserPublisherReadOnlyDataResultHolderStruct : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerUpdateUserPublisherReadOnlyDataGetResult(async, &result)));
            LogUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerUpdateUserPublisherReadOnlyDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateUserPublisherReadOnlyDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementServerUpdateUserDataRequestWrapper<> request;
    FillServerUpdateUserPublisherReadOnlyDataRequest(request);
    LogServerUpdateUserDataRequest(&request.Model(), "TestPlayerDataManagementServerUpdateUserPublisherReadOnlyData");
    HRESULT hr = PFPlayerDataManagementServerUpdateUserPublisherReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerUpdateUserPublisherReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerUpdateUserReadOnlyData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserReadOnlyData(TestContext& testContext)
{
    struct ServerUpdateUserReadOnlyDataResultHolderStruct : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerUpdateUserReadOnlyDataGetResult(async, &result)));
            LogUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerUpdateUserReadOnlyDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateUserReadOnlyDataResultHolderStruct>>(testContext);

    PFPlayerDataManagementServerUpdateUserDataRequestWrapper<> request;
    FillServerUpdateUserReadOnlyDataRequest(request);
    LogServerUpdateUserDataRequest(&request.Model(), "TestPlayerDataManagementServerUpdateUserReadOnlyData");
    HRESULT hr = PFPlayerDataManagementServerUpdateUserReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerUpdateUserReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
