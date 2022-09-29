#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenTitleDataManagementTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenTitleDataManagementTests::TitleDataManagementTestData AutoGenTitleDataManagementTests::testData;

void AutoGenTitleDataManagementTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenTitleDataManagementTests::LogHR(HRESULT hr)
{
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenTitleDataManagementTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminAddLocalizedNews", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminAddLocalizedNews);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminAddNews", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminAddNews);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminAddVirtualCurrencyTypes", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminAddVirtualCurrencyTypes);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminDeleteStore", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminDeleteStore);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminDeleteTitleDataOverride", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminDeleteTitleDataOverride);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminGetCatalogItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetCatalogItems);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminGetPublisherData", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetPublisherData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminGetRandomResultTables", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetRandomResultTables);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminGetStoreItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetStoreItems);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminGetTitleData", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetTitleData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminGetTitleInternalData", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetTitleInternalData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminListVirtualCurrencyTypes", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminListVirtualCurrencyTypes);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminRemoveVirtualCurrencyTypes", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminRemoveVirtualCurrencyTypes);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminSetCatalogItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetCatalogItems);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminSetPublisherData", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetPublisherData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminSetStoreItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetStoreItems);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminSetTitleData", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetTitleData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminSetTitleDataAndOverrides", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetTitleDataAndOverrides);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminSetTitleInternalData", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetTitleInternalData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminSetupPushNotification", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetupPushNotification);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminUpdateCatalogItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminUpdateCatalogItems);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminUpdateRandomResultTables", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminUpdateRandomResultTables);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementAdminUpdateStoreItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminUpdateStoreItems);
#endif

    AddTest("TestTitleDataManagementClientGetCatalogItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetCatalogItems);

    AddTest("TestTitleDataManagementClientGetPublisherData", &AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetPublisherData);

    AddTest("TestTitleDataManagementClientGetStoreItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetStoreItems);

    AddTest("TestTitleDataManagementClientGetTime", &AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetTime);

    AddTest("TestTitleDataManagementClientGetTitleData", &AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetTitleData);

    AddTest("TestTitleDataManagementClientGetTitleNews", &AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetTitleNews);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementServerGetCatalogItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetCatalogItems);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementServerGetPublisherData", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetPublisherData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementServerGetStoreItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetStoreItems);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementServerGetTime", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetTime);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementServerGetTitleData", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetTitleData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementServerGetTitleInternalData", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetTitleInternalData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementServerGetTitleNews", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetTitleNews);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementServerSetPublisherData", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerSetPublisherData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementServerSetTitleData", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerSetTitleData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestTitleDataManagementServerSetTitleInternalData", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerSetTitleInternalData);
#endif
}

void AutoGenTitleDataManagementTests::ClassSetUp()
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

void AutoGenTitleDataManagementTests::ClassTearDown()
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

void AutoGenTitleDataManagementTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AdminAddLocalizedNews

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminAddLocalizedNews(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementAddLocalizedNewsRequestWrapper<> request;
    FillAdminAddLocalizedNewsRequest(request);
    LogAddLocalizedNewsRequest(&request.Model(), "TestTitleDataManagementAdminAddLocalizedNews");
    HRESULT hr = PFTitleDataManagementAdminAddLocalizedNewsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminAddLocalizedNewsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminAddNews

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminAddNews(TestContext& testContext)
{
    struct AdminAddNewsResultHolderStruct : public AddNewsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminAddNewsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminAddNewsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogAddNewsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminAddNewsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminAddNewsResultHolderStruct>>(testContext);

    PFTitleDataManagementAddNewsRequestWrapper<> request;
    FillAdminAddNewsRequest(request);
    LogAddNewsRequest(&request.Model(), "TestTitleDataManagementAdminAddNews");
    HRESULT hr = PFTitleDataManagementAdminAddNewsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminAddNewsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminAddVirtualCurrencyTypes

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminAddVirtualCurrencyTypes(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper<> request;
    FillAdminAddVirtualCurrencyTypesRequest(request);
    LogAddVirtualCurrencyTypesRequest(&request.Model(), "TestTitleDataManagementAdminAddVirtualCurrencyTypes");
    HRESULT hr = PFTitleDataManagementAdminAddVirtualCurrencyTypesAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminAddVirtualCurrencyTypesAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminDeleteStore

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminDeleteStore(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementDeleteStoreRequestWrapper<> request;
    FillAdminDeleteStoreRequest(request);
    LogDeleteStoreRequest(&request.Model(), "TestTitleDataManagementAdminDeleteStore");
    HRESULT hr = PFTitleDataManagementAdminDeleteStoreAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminDeleteStoreAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminDeleteTitleDataOverride

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminDeleteTitleDataOverride(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper<> request;
    FillAdminDeleteTitleDataOverrideRequest(request);
    LogDeleteTitleDataOverrideRequest(&request.Model(), "TestTitleDataManagementAdminDeleteTitleDataOverride");
    HRESULT hr = PFTitleDataManagementAdminDeleteTitleDataOverrideAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminDeleteTitleDataOverrideAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetCatalogItems

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetCatalogItems(TestContext& testContext)
{
    struct AdminGetCatalogItemsResultHolderStruct : public GetCatalogItemsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetCatalogItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetCatalogItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetCatalogItemsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetCatalogItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetCatalogItemsResultHolderStruct>>(testContext);

    PFTitleDataManagementGetCatalogItemsRequestWrapper<> request;
    FillAdminGetCatalogItemsRequest(request);
    LogGetCatalogItemsRequest(&request.Model(), "TestTitleDataManagementAdminGetCatalogItems");
    HRESULT hr = PFTitleDataManagementAdminGetCatalogItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminGetCatalogItemsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetPublisherData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetPublisherData(TestContext& testContext)
{
    struct AdminGetPublisherDataResultHolderStruct : public GetPublisherDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetPublisherDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetPublisherDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetPublisherDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetPublisherDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetPublisherDataResultHolderStruct>>(testContext);

    PFTitleDataManagementGetPublisherDataRequestWrapper<> request;
    FillAdminGetPublisherDataRequest(request);
    LogGetPublisherDataRequest(&request.Model(), "TestTitleDataManagementAdminGetPublisherData");
    HRESULT hr = PFTitleDataManagementAdminGetPublisherDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminGetPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetRandomResultTables

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetRandomResultTables(TestContext& testContext)
{
    struct AdminGetRandomResultTablesResultHolderStruct : public GetRandomResultTablesResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetRandomResultTablesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetRandomResultTablesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetRandomResultTablesResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetRandomResultTablesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetRandomResultTablesResultHolderStruct>>(testContext);

    PFTitleDataManagementGetRandomResultTablesRequestWrapper<> request;
    FillAdminGetRandomResultTablesRequest(request);
    LogGetRandomResultTablesRequest(&request.Model(), "TestTitleDataManagementAdminGetRandomResultTables");
    HRESULT hr = PFTitleDataManagementAdminGetRandomResultTablesAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminGetRandomResultTablesAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetStoreItems

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetStoreItems(TestContext& testContext)
{
    struct AdminGetStoreItemsResultHolderStruct : public GetStoreItemsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetStoreItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetStoreItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetStoreItemsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetStoreItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetStoreItemsResultHolderStruct>>(testContext);

    PFTitleDataManagementGetStoreItemsRequestWrapper<> request;
    FillAdminGetStoreItemsRequest(request);
    LogGetStoreItemsRequest(&request.Model(), "TestTitleDataManagementAdminGetStoreItems");
    HRESULT hr = PFTitleDataManagementAdminGetStoreItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminGetStoreItemsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetTitleData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetTitleData(TestContext& testContext)
{
    struct AdminGetTitleDataResultHolderStruct : public GetTitleDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetTitleDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetTitleDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetTitleDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetTitleDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetTitleDataResultHolderStruct>>(testContext);

    PFTitleDataManagementGetTitleDataRequestWrapper<> request;
    FillAdminGetTitleDataRequest(request);
    LogGetTitleDataRequest(&request.Model(), "TestTitleDataManagementAdminGetTitleData");
    HRESULT hr = PFTitleDataManagementAdminGetTitleDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminGetTitleDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetTitleInternalData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetTitleInternalData(TestContext& testContext)
{
    struct AdminGetTitleInternalDataResultHolderStruct : public GetTitleDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetTitleInternalDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetTitleInternalDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetTitleDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetTitleInternalDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetTitleInternalDataResultHolderStruct>>(testContext);

    PFTitleDataManagementGetTitleDataRequestWrapper<> request;
    FillAdminGetTitleInternalDataRequest(request);
    LogGetTitleDataRequest(&request.Model(), "TestTitleDataManagementAdminGetTitleInternalData");
    HRESULT hr = PFTitleDataManagementAdminGetTitleInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminGetTitleInternalDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminListVirtualCurrencyTypes

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminListVirtualCurrencyTypes(TestContext& testContext)
{
    struct AdminListVirtualCurrencyTypesResultHolderStruct : public ListVirtualCurrencyTypesResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminListVirtualCurrencyTypesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminListVirtualCurrencyTypesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListVirtualCurrencyTypesResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminListVirtualCurrencyTypesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminListVirtualCurrencyTypesResultHolderStruct>>(testContext);

    HRESULT hr = PFTitleDataManagementAdminListVirtualCurrencyTypesAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminListVirtualCurrencyTypesAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminRemoveVirtualCurrencyTypes

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminRemoveVirtualCurrencyTypes(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper<> request;
    FillAdminRemoveVirtualCurrencyTypesRequest(request);
    LogRemoveVirtualCurrencyTypesRequest(&request.Model(), "TestTitleDataManagementAdminRemoveVirtualCurrencyTypes");
    HRESULT hr = PFTitleDataManagementAdminRemoveVirtualCurrencyTypesAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminRemoveVirtualCurrencyTypesAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminSetCatalogItems

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetCatalogItems(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementUpdateCatalogItemsRequestWrapper<> request;
    FillAdminSetCatalogItemsRequest(request);
    LogUpdateCatalogItemsRequest(&request.Model(), "TestTitleDataManagementAdminSetCatalogItems");
    HRESULT hr = PFTitleDataManagementAdminSetCatalogItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminSetCatalogItemsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminSetPublisherData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetPublisherData(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementSetPublisherDataRequestWrapper<> request;
    FillAdminSetPublisherDataRequest(request);
    LogSetPublisherDataRequest(&request.Model(), "TestTitleDataManagementAdminSetPublisherData");
    HRESULT hr = PFTitleDataManagementAdminSetPublisherDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminSetPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminSetStoreItems

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetStoreItems(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementUpdateStoreItemsRequestWrapper<> request;
    FillAdminSetStoreItemsRequest(request);
    LogUpdateStoreItemsRequest(&request.Model(), "TestTitleDataManagementAdminSetStoreItems");
    HRESULT hr = PFTitleDataManagementAdminSetStoreItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminSetStoreItemsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminSetTitleData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetTitleData(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementSetTitleDataRequestWrapper<> request;
    FillAdminSetTitleDataRequest(request);
    LogSetTitleDataRequest(&request.Model(), "TestTitleDataManagementAdminSetTitleData");
    HRESULT hr = PFTitleDataManagementAdminSetTitleDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminSetTitleDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminSetTitleDataAndOverrides

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetTitleDataAndOverrides(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper<> request;
    FillAdminSetTitleDataAndOverridesRequest(request);
    LogSetTitleDataAndOverridesRequest(&request.Model(), "TestTitleDataManagementAdminSetTitleDataAndOverrides");
    HRESULT hr = PFTitleDataManagementAdminSetTitleDataAndOverridesAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminSetTitleDataAndOverridesAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminSetTitleInternalData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetTitleInternalData(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementSetTitleDataRequestWrapper<> request;
    FillAdminSetTitleInternalDataRequest(request);
    LogSetTitleDataRequest(&request.Model(), "TestTitleDataManagementAdminSetTitleInternalData");
    HRESULT hr = PFTitleDataManagementAdminSetTitleInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminSetTitleInternalDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminSetupPushNotification

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetupPushNotification(TestContext& testContext)
{
    struct AdminSetupPushNotificationResultHolderStruct : public SetupPushNotificationResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminSetupPushNotificationGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminSetupPushNotificationGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogSetupPushNotificationResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminSetupPushNotificationResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminSetupPushNotificationResultHolderStruct>>(testContext);

    PFTitleDataManagementSetupPushNotificationRequestWrapper<> request;
    FillAdminSetupPushNotificationRequest(request);
    LogSetupPushNotificationRequest(&request.Model(), "TestTitleDataManagementAdminSetupPushNotification");
    HRESULT hr = PFTitleDataManagementAdminSetupPushNotificationAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminSetupPushNotificationAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdateCatalogItems

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminUpdateCatalogItems(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementUpdateCatalogItemsRequestWrapper<> request;
    FillAdminUpdateCatalogItemsRequest(request);
    LogUpdateCatalogItemsRequest(&request.Model(), "TestTitleDataManagementAdminUpdateCatalogItems");
    HRESULT hr = PFTitleDataManagementAdminUpdateCatalogItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminUpdateCatalogItemsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdateRandomResultTables

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminUpdateRandomResultTables(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementUpdateRandomResultTablesRequestWrapper<> request;
    FillAdminUpdateRandomResultTablesRequest(request);
    LogUpdateRandomResultTablesRequest(&request.Model(), "TestTitleDataManagementAdminUpdateRandomResultTables");
    HRESULT hr = PFTitleDataManagementAdminUpdateRandomResultTablesAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminUpdateRandomResultTablesAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdateStoreItems

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminUpdateStoreItems(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementUpdateStoreItemsRequestWrapper<> request;
    FillAdminUpdateStoreItemsRequest(request);
    LogUpdateStoreItemsRequest(&request.Model(), "TestTitleDataManagementAdminUpdateStoreItems");
    HRESULT hr = PFTitleDataManagementAdminUpdateStoreItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminUpdateStoreItemsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientGetCatalogItems

void AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetCatalogItems(TestContext& testContext)
{
    struct ClientGetCatalogItemsResultHolderStruct : public GetCatalogItemsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetCatalogItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetCatalogItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetCatalogItemsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetCatalogItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetCatalogItemsResultHolderStruct>>(testContext);

    PFTitleDataManagementGetCatalogItemsRequestWrapper<> request;
    FillClientGetCatalogItemsRequest(request);
    LogGetCatalogItemsRequest(&request.Model(), "TestTitleDataManagementClientGetCatalogItems");
    HRESULT hr = PFTitleDataManagementClientGetCatalogItemsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementClientGetCatalogItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPublisherData

void AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetPublisherData(TestContext& testContext)
{
    struct ClientGetPublisherDataResultHolderStruct : public GetPublisherDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetPublisherDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetPublisherDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetPublisherDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetPublisherDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPublisherDataResultHolderStruct>>(testContext);

    PFTitleDataManagementGetPublisherDataRequestWrapper<> request;
    FillClientGetPublisherDataRequest(request);
    LogGetPublisherDataRequest(&request.Model(), "TestTitleDataManagementClientGetPublisherData");
    HRESULT hr = PFTitleDataManagementClientGetPublisherDataAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementClientGetPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetStoreItems

void AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetStoreItems(TestContext& testContext)
{
    struct ClientGetStoreItemsResultHolderStruct : public GetStoreItemsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetStoreItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetStoreItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetStoreItemsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetStoreItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetStoreItemsResultHolderStruct>>(testContext);

    PFTitleDataManagementGetStoreItemsRequestWrapper<> request;
    FillClientGetStoreItemsRequest(request);
    LogGetStoreItemsRequest(&request.Model(), "TestTitleDataManagementClientGetStoreItems");
    HRESULT hr = PFTitleDataManagementClientGetStoreItemsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementClientGetStoreItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetTime

void AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetTime(TestContext& testContext)
{
    struct ClientGetTimeResultHolderStruct : public GetTimeResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetTimeGetResult(async, &result)));
            LogGetTimeResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetTimeResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetTimeResultHolderStruct>>(testContext);

    HRESULT hr = PFTitleDataManagementClientGetTimeAsync(titlePlayerHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementClientGetTimeAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetTitleData

void AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetTitleData(TestContext& testContext)
{
    struct ClientGetTitleDataResultHolderStruct : public GetTitleDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetTitleDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetTitleDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetTitleDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetTitleDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetTitleDataResultHolderStruct>>(testContext);

    PFTitleDataManagementGetTitleDataRequestWrapper<> request;
    FillClientGetTitleDataRequest(request);
    LogGetTitleDataRequest(&request.Model(), "TestTitleDataManagementClientGetTitleData");
    HRESULT hr = PFTitleDataManagementClientGetTitleDataAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementClientGetTitleDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetTitleNews

void AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetTitleNews(TestContext& testContext)
{
    struct ClientGetTitleNewsResultHolderStruct : public GetTitleNewsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetTitleNewsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetTitleNewsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetTitleNewsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetTitleNewsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetTitleNewsResultHolderStruct>>(testContext);

    PFTitleDataManagementGetTitleNewsRequestWrapper<> request;
    FillClientGetTitleNewsRequest(request);
    LogGetTitleNewsRequest(&request.Model(), "TestTitleDataManagementClientGetTitleNews");
    HRESULT hr = PFTitleDataManagementClientGetTitleNewsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementClientGetTitleNewsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetCatalogItems

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetCatalogItems(TestContext& testContext)
{
    struct ServerGetCatalogItemsResultHolderStruct : public GetCatalogItemsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetCatalogItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetCatalogItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetCatalogItemsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetCatalogItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetCatalogItemsResultHolderStruct>>(testContext);

    PFTitleDataManagementGetCatalogItemsRequestWrapper<> request;
    FillServerGetCatalogItemsRequest(request);
    LogGetCatalogItemsRequest(&request.Model(), "TestTitleDataManagementServerGetCatalogItems");
    HRESULT hr = PFTitleDataManagementServerGetCatalogItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerGetCatalogItemsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetPublisherData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetPublisherData(TestContext& testContext)
{
    struct ServerGetPublisherDataResultHolderStruct : public GetPublisherDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetPublisherDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetPublisherDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetPublisherDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetPublisherDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPublisherDataResultHolderStruct>>(testContext);

    PFTitleDataManagementGetPublisherDataRequestWrapper<> request;
    FillServerGetPublisherDataRequest(request);
    LogGetPublisherDataRequest(&request.Model(), "TestTitleDataManagementServerGetPublisherData");
    HRESULT hr = PFTitleDataManagementServerGetPublisherDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerGetPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetStoreItems

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetStoreItems(TestContext& testContext)
{
    struct ServerGetStoreItemsResultHolderStruct : public GetStoreItemsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetStoreItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetStoreItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetStoreItemsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetStoreItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetStoreItemsResultHolderStruct>>(testContext);

    PFTitleDataManagementGetStoreItemsServerRequestWrapper<> request;
    FillServerGetStoreItemsRequest(request);
    LogGetStoreItemsServerRequest(&request.Model(), "TestTitleDataManagementServerGetStoreItems");
    HRESULT hr = PFTitleDataManagementServerGetStoreItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerGetStoreItemsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetTime

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetTime(TestContext& testContext)
{
    struct ServerGetTimeResultHolderStruct : public GetTimeResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetTimeGetResult(async, &result)));
            LogGetTimeResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetTimeResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetTimeResultHolderStruct>>(testContext);

    HRESULT hr = PFTitleDataManagementServerGetTimeAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerGetTimeAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetTitleData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetTitleData(TestContext& testContext)
{
    struct ServerGetTitleDataResultHolderStruct : public GetTitleDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetTitleDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetTitleDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetTitleDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetTitleDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetTitleDataResultHolderStruct>>(testContext);

    PFTitleDataManagementGetTitleDataRequestWrapper<> request;
    FillServerGetTitleDataRequest(request);
    LogGetTitleDataRequest(&request.Model(), "TestTitleDataManagementServerGetTitleData");
    HRESULT hr = PFTitleDataManagementServerGetTitleDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerGetTitleDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetTitleInternalData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetTitleInternalData(TestContext& testContext)
{
    struct ServerGetTitleInternalDataResultHolderStruct : public GetTitleDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetTitleInternalDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetTitleInternalDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetTitleDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetTitleInternalDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetTitleInternalDataResultHolderStruct>>(testContext);

    PFTitleDataManagementGetTitleDataRequestWrapper<> request;
    FillServerGetTitleInternalDataRequest(request);
    LogGetTitleDataRequest(&request.Model(), "TestTitleDataManagementServerGetTitleInternalData");
    HRESULT hr = PFTitleDataManagementServerGetTitleInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerGetTitleInternalDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetTitleNews

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetTitleNews(TestContext& testContext)
{
    struct ServerGetTitleNewsResultHolderStruct : public GetTitleNewsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetTitleNewsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetTitleNewsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetTitleNewsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetTitleNewsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetTitleNewsResultHolderStruct>>(testContext);

    PFTitleDataManagementGetTitleNewsRequestWrapper<> request;
    FillServerGetTitleNewsRequest(request);
    LogGetTitleNewsRequest(&request.Model(), "TestTitleDataManagementServerGetTitleNews");
    HRESULT hr = PFTitleDataManagementServerGetTitleNewsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerGetTitleNewsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerSetPublisherData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementServerSetPublisherData(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementSetPublisherDataRequestWrapper<> request;
    FillServerSetPublisherDataRequest(request);
    LogSetPublisherDataRequest(&request.Model(), "TestTitleDataManagementServerSetPublisherData");
    HRESULT hr = PFTitleDataManagementServerSetPublisherDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerSetPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerSetTitleData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementServerSetTitleData(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementSetTitleDataRequestWrapper<> request;
    FillServerSetTitleDataRequest(request);
    LogSetTitleDataRequest(&request.Model(), "TestTitleDataManagementServerSetTitleData");
    HRESULT hr = PFTitleDataManagementServerSetTitleDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerSetTitleDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerSetTitleInternalData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenTitleDataManagementTests::TestTitleDataManagementServerSetTitleInternalData(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementSetTitleDataRequestWrapper<> request;
    FillServerSetTitleInternalDataRequest(request);
    LogSetTitleDataRequest(&request.Model(), "TestTitleDataManagementServerSetTitleInternalData");
    HRESULT hr = PFTitleDataManagementServerSetTitleInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerSetTitleInternalDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
