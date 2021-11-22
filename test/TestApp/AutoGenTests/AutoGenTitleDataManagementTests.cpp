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
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenTitleDataManagementTests::AddTests()
{
    // Generated tests 
    AddTest("TestTitleDataManagementAdminAddLocalizedNews", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminAddLocalizedNews);

    AddTest("TestTitleDataManagementAdminAddNews", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminAddNews);

    AddTest("TestTitleDataManagementAdminAddVirtualCurrencyTypes", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminAddVirtualCurrencyTypes);

    AddTest("TestTitleDataManagementAdminDeleteStore", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminDeleteStore);

    AddTest("TestTitleDataManagementAdminDeleteTitleDataOverride", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminDeleteTitleDataOverride);

    AddTest("TestTitleDataManagementAdminGetCatalogItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetCatalogItems);

    AddTest("TestTitleDataManagementAdminGetPublisherData", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetPublisherData);

    AddTest("TestTitleDataManagementAdminGetRandomResultTables", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetRandomResultTables);

    AddTest("TestTitleDataManagementAdminGetStoreItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetStoreItems);

    AddTest("TestTitleDataManagementAdminGetTitleData", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetTitleData);

    AddTest("TestTitleDataManagementAdminGetTitleInternalData", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetTitleInternalData);

    AddTest("TestTitleDataManagementAdminListVirtualCurrencyTypes", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminListVirtualCurrencyTypes);

    AddTest("TestTitleDataManagementAdminRemoveVirtualCurrencyTypes", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminRemoveVirtualCurrencyTypes);

    AddTest("TestTitleDataManagementAdminSetCatalogItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetCatalogItems);

    AddTest("TestTitleDataManagementAdminSetPublisherData", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetPublisherData);

    AddTest("TestTitleDataManagementAdminSetStoreItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetStoreItems);

    AddTest("TestTitleDataManagementAdminSetTitleData", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetTitleData);

    AddTest("TestTitleDataManagementAdminSetTitleDataAndOverrides", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetTitleDataAndOverrides);

    AddTest("TestTitleDataManagementAdminSetTitleInternalData", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetTitleInternalData);

    AddTest("TestTitleDataManagementAdminSetupPushNotification", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetupPushNotification);

    AddTest("TestTitleDataManagementAdminUpdateCatalogItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminUpdateCatalogItems);

    AddTest("TestTitleDataManagementAdminUpdateRandomResultTables", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminUpdateRandomResultTables);

    AddTest("TestTitleDataManagementAdminUpdateStoreItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementAdminUpdateStoreItems);

    AddTest("TestTitleDataManagementClientGetCatalogItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetCatalogItems);

    AddTest("TestTitleDataManagementClientGetPublisherData", &AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetPublisherData);

    AddTest("TestTitleDataManagementClientGetStoreItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetStoreItems);

    AddTest("TestTitleDataManagementClientGetTime", &AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetTime);

    AddTest("TestTitleDataManagementClientGetTitleData", &AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetTitleData);

    AddTest("TestTitleDataManagementClientGetTitleNews", &AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetTitleNews);

    AddTest("TestTitleDataManagementServerGetCatalogItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetCatalogItems);

    AddTest("TestTitleDataManagementServerGetPublisherData", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetPublisherData);

    AddTest("TestTitleDataManagementServerGetStoreItems", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetStoreItems);

    AddTest("TestTitleDataManagementServerGetTime", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetTime);

    AddTest("TestTitleDataManagementServerGetTitleData", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetTitleData);

    AddTest("TestTitleDataManagementServerGetTitleInternalData", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetTitleInternalData);

    AddTest("TestTitleDataManagementServerGetTitleNews", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetTitleNews);

    AddTest("TestTitleDataManagementServerSetPublisherData", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerSetPublisherData);

    AddTest("TestTitleDataManagementServerSetTitleData", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerSetTitleData);

    AddTest("TestTitleDataManagementServerSetTitleInternalData", &AutoGenTitleDataManagementTests::TestTitleDataManagementServerSetTitleInternalData);
}

void AutoGenTitleDataManagementTests::ClassSetUp()
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

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminAddLocalizedNews(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementAddLocalizedNewsRequestWrapper<> request;
    FillAddLocalizedNewsRequest(request);
    LogAddLocalizedNewsRequest(&request.Model(), "TestTitleDataManagementAdminAddLocalizedNews");
    HRESULT hr = PFTitleDataManagementAdminAddLocalizedNewsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminAddLocalizedNewsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminAddNews

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminAddNews(TestContext& testContext)
{
    struct AdminAddNewsResultHolder : public AddNewsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminAddNewsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminAddNewsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementAddNewsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementAddNewsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminAddNewsResultHolder>>(testContext);

    PFTitleDataManagementAddNewsRequestWrapper<> request;
    FillAddNewsRequest(request);
    LogAddNewsRequest(&request.Model(), "TestTitleDataManagementAdminAddNews");
    HRESULT hr = PFTitleDataManagementAdminAddNewsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminAddNewsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminAddVirtualCurrencyTypes

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminAddVirtualCurrencyTypes(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper<> request;
    FillAddVirtualCurrencyTypesRequest(request);
    LogAddVirtualCurrencyTypesRequest(&request.Model(), "TestTitleDataManagementAdminAddVirtualCurrencyTypes");
    HRESULT hr = PFTitleDataManagementAdminAddVirtualCurrencyTypesAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminAddVirtualCurrencyTypesAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminDeleteStore

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminDeleteStore(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementDeleteStoreRequestWrapper<> request;
    FillDeleteStoreRequest(request);
    LogDeleteStoreRequest(&request.Model(), "TestTitleDataManagementAdminDeleteStore");
    HRESULT hr = PFTitleDataManagementAdminDeleteStoreAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminDeleteStoreAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminDeleteTitleDataOverride

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminDeleteTitleDataOverride(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper<> request;
    FillDeleteTitleDataOverrideRequest(request);
    LogDeleteTitleDataOverrideRequest(&request.Model(), "TestTitleDataManagementAdminDeleteTitleDataOverride");
    HRESULT hr = PFTitleDataManagementAdminDeleteTitleDataOverrideAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminDeleteTitleDataOverrideAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetCatalogItems

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetCatalogItems(TestContext& testContext)
{
    struct AdminGetCatalogItemsResultHolder : public GetCatalogItemsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetCatalogItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetCatalogItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementGetCatalogItemsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetCatalogItemsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetCatalogItemsResultHolder>>(testContext);

    PFTitleDataManagementGetCatalogItemsRequestWrapper<> request;
    FillGetCatalogItemsRequest(request);
    LogGetCatalogItemsRequest(&request.Model(), "TestTitleDataManagementAdminGetCatalogItems");
    HRESULT hr = PFTitleDataManagementAdminGetCatalogItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminGetCatalogItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetPublisherData

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetPublisherData(TestContext& testContext)
{
    struct AdminGetPublisherDataResultHolder : public GetPublisherDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetPublisherDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetPublisherDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementGetPublisherDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetPublisherDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetPublisherDataResultHolder>>(testContext);

    PFTitleDataManagementGetPublisherDataRequestWrapper<> request;
    FillGetPublisherDataRequest(request);
    LogGetPublisherDataRequest(&request.Model(), "TestTitleDataManagementAdminGetPublisherData");
    HRESULT hr = PFTitleDataManagementAdminGetPublisherDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminGetPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetRandomResultTables

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetRandomResultTables(TestContext& testContext)
{
    struct AdminGetRandomResultTablesResultHolder : public GetRandomResultTablesResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetRandomResultTablesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetRandomResultTablesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGetRandomResultTablesResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGetRandomResultTablesResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetRandomResultTablesResultHolder>>(testContext);

    PFTitleDataManagementGetRandomResultTablesRequestWrapper<> request;
    FillGetRandomResultTablesRequest(request);
    LogGetRandomResultTablesRequest(&request.Model(), "TestTitleDataManagementAdminGetRandomResultTables");
    HRESULT hr = PFTitleDataManagementAdminGetRandomResultTablesAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminGetRandomResultTablesAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetStoreItems

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetStoreItems(TestContext& testContext)
{
    struct AdminGetStoreItemsResultHolder : public GetStoreItemsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetStoreItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetStoreItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementGetStoreItemsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetStoreItemsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetStoreItemsResultHolder>>(testContext);

    PFTitleDataManagementGetStoreItemsRequestWrapper<> request;
    FillGetStoreItemsRequest(request);
    LogGetStoreItemsRequest(&request.Model(), "TestTitleDataManagementAdminGetStoreItems");
    HRESULT hr = PFTitleDataManagementAdminGetStoreItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminGetStoreItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetTitleData

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetTitleData(TestContext& testContext)
{
    struct AdminGetTitleDataResultHolder : public GetTitleDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetTitleDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetTitleDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementGetTitleDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetTitleDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetTitleDataResultHolder>>(testContext);

    PFTitleDataManagementGetTitleDataRequestWrapper<> request;
    FillGetTitleDataRequest(request);
    LogGetTitleDataRequest(&request.Model(), "TestTitleDataManagementAdminGetTitleData");
    HRESULT hr = PFTitleDataManagementAdminGetTitleDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminGetTitleDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetTitleInternalData

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminGetTitleInternalData(TestContext& testContext)
{
    struct AdminGetTitleInternalDataResultHolder : public GetTitleDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetTitleInternalDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminGetTitleInternalDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementGetTitleDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetTitleDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetTitleInternalDataResultHolder>>(testContext);

    PFTitleDataManagementGetTitleDataRequestWrapper<> request;
    FillGetTitleDataRequest(request);
    LogGetTitleDataRequest(&request.Model(), "TestTitleDataManagementAdminGetTitleInternalData");
    HRESULT hr = PFTitleDataManagementAdminGetTitleInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminGetTitleInternalDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminListVirtualCurrencyTypes

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminListVirtualCurrencyTypes(TestContext& testContext)
{
    struct AdminListVirtualCurrencyTypesResultHolder : public ListVirtualCurrencyTypesResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminListVirtualCurrencyTypesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminListVirtualCurrencyTypesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementListVirtualCurrencyTypesResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementListVirtualCurrencyTypesResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminListVirtualCurrencyTypesResultHolder>>(testContext);

    HRESULT hr = PFTitleDataManagementAdminListVirtualCurrencyTypesAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminListVirtualCurrencyTypesAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminRemoveVirtualCurrencyTypes

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminRemoveVirtualCurrencyTypes(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper<> request;
    FillRemoveVirtualCurrencyTypesRequest(request);
    LogRemoveVirtualCurrencyTypesRequest(&request.Model(), "TestTitleDataManagementAdminRemoveVirtualCurrencyTypes");
    HRESULT hr = PFTitleDataManagementAdminRemoveVirtualCurrencyTypesAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminRemoveVirtualCurrencyTypesAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminSetCatalogItems

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetCatalogItems(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementUpdateCatalogItemsRequestWrapper<> request;
    FillUpdateCatalogItemsRequest(request);
    LogUpdateCatalogItemsRequest(&request.Model(), "TestTitleDataManagementAdminSetCatalogItems");
    HRESULT hr = PFTitleDataManagementAdminSetCatalogItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminSetCatalogItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminSetPublisherData

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetPublisherData(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementSetPublisherDataRequestWrapper<> request;
    FillSetPublisherDataRequest(request);
    LogSetPublisherDataRequest(&request.Model(), "TestTitleDataManagementAdminSetPublisherData");
    HRESULT hr = PFTitleDataManagementAdminSetPublisherDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminSetPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminSetStoreItems

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetStoreItems(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementUpdateStoreItemsRequestWrapper<> request;
    FillUpdateStoreItemsRequest(request);
    LogUpdateStoreItemsRequest(&request.Model(), "TestTitleDataManagementAdminSetStoreItems");
    HRESULT hr = PFTitleDataManagementAdminSetStoreItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminSetStoreItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminSetTitleData

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetTitleData(TestContext& testContext)
{
    struct AdminSetTitleDataResultHolder : public SetTitleDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminSetTitleDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminSetTitleDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementSetTitleDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementSetTitleDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminSetTitleDataResultHolder>>(testContext);

    PFTitleDataManagementSetTitleDataRequestWrapper<> request;
    FillSetTitleDataRequest(request);
    LogSetTitleDataRequest(&request.Model(), "TestTitleDataManagementAdminSetTitleData");
    HRESULT hr = PFTitleDataManagementAdminSetTitleDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminSetTitleDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminSetTitleDataAndOverrides

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetTitleDataAndOverrides(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper<> request;
    FillSetTitleDataAndOverridesRequest(request);
    LogSetTitleDataAndOverridesRequest(&request.Model(), "TestTitleDataManagementAdminSetTitleDataAndOverrides");
    HRESULT hr = PFTitleDataManagementAdminSetTitleDataAndOverridesAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminSetTitleDataAndOverridesAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminSetTitleInternalData

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetTitleInternalData(TestContext& testContext)
{
    struct AdminSetTitleInternalDataResultHolder : public SetTitleDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminSetTitleInternalDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminSetTitleInternalDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementSetTitleDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementSetTitleDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminSetTitleInternalDataResultHolder>>(testContext);

    PFTitleDataManagementSetTitleDataRequestWrapper<> request;
    FillSetTitleDataRequest(request);
    LogSetTitleDataRequest(&request.Model(), "TestTitleDataManagementAdminSetTitleInternalData");
    HRESULT hr = PFTitleDataManagementAdminSetTitleInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminSetTitleInternalDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminSetupPushNotification

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminSetupPushNotification(TestContext& testContext)
{
    struct AdminSetupPushNotificationResultHolder : public SetupPushNotificationResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminSetupPushNotificationGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementAdminSetupPushNotificationGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementSetupPushNotificationResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementSetupPushNotificationResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminSetupPushNotificationResultHolder>>(testContext);

    PFTitleDataManagementSetupPushNotificationRequestWrapper<> request;
    FillSetupPushNotificationRequest(request);
    LogSetupPushNotificationRequest(&request.Model(), "TestTitleDataManagementAdminSetupPushNotification");
    HRESULT hr = PFTitleDataManagementAdminSetupPushNotificationAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminSetupPushNotificationAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminUpdateCatalogItems

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminUpdateCatalogItems(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementUpdateCatalogItemsRequestWrapper<> request;
    FillUpdateCatalogItemsRequest(request);
    LogUpdateCatalogItemsRequest(&request.Model(), "TestTitleDataManagementAdminUpdateCatalogItems");
    HRESULT hr = PFTitleDataManagementAdminUpdateCatalogItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminUpdateCatalogItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminUpdateRandomResultTables

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminUpdateRandomResultTables(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementUpdateRandomResultTablesRequestWrapper<> request;
    FillUpdateRandomResultTablesRequest(request);
    LogUpdateRandomResultTablesRequest(&request.Model(), "TestTitleDataManagementAdminUpdateRandomResultTables");
    HRESULT hr = PFTitleDataManagementAdminUpdateRandomResultTablesAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminUpdateRandomResultTablesAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminUpdateStoreItems

void AutoGenTitleDataManagementTests::TestTitleDataManagementAdminUpdateStoreItems(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementUpdateStoreItemsRequestWrapper<> request;
    FillUpdateStoreItemsRequest(request);
    LogUpdateStoreItemsRequest(&request.Model(), "TestTitleDataManagementAdminUpdateStoreItems");
    HRESULT hr = PFTitleDataManagementAdminUpdateStoreItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementAdminUpdateStoreItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetCatalogItems

void AutoGenTitleDataManagementTests::TestTitleDataManagementClientGetCatalogItems(TestContext& testContext)
{
    struct ClientGetCatalogItemsResultHolder : public GetCatalogItemsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetCatalogItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetCatalogItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementGetCatalogItemsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetCatalogItemsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetCatalogItemsResultHolder>>(testContext);

    PFTitleDataManagementGetCatalogItemsRequestWrapper<> request;
    FillGetCatalogItemsRequest(request);
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
    struct ClientGetPublisherDataResultHolder : public GetPublisherDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetPublisherDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetPublisherDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementGetPublisherDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetPublisherDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPublisherDataResultHolder>>(testContext);

    PFTitleDataManagementGetPublisherDataRequestWrapper<> request;
    FillGetPublisherDataRequest(request);
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
    struct ClientGetStoreItemsResultHolder : public GetStoreItemsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetStoreItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetStoreItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementGetStoreItemsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetStoreItemsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetStoreItemsResultHolder>>(testContext);

    PFTitleDataManagementGetStoreItemsRequestWrapper<> request;
    FillGetStoreItemsRequest(request);
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
    struct ClientGetTimeResultHolder : public GetTimeResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetTimeGetResult(async, &result)));
            LogPFTitleDataManagementGetTimeResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetTimeResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetTimeResultHolder>>(testContext);

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
    struct ClientGetTitleDataResultHolder : public GetTitleDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetTitleDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetTitleDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementGetTitleDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetTitleDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetTitleDataResultHolder>>(testContext);

    PFTitleDataManagementGetTitleDataRequestWrapper<> request;
    FillGetTitleDataRequest(request);
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
    struct ClientGetTitleNewsResultHolder : public GetTitleNewsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetTitleNewsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementClientGetTitleNewsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementGetTitleNewsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetTitleNewsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetTitleNewsResultHolder>>(testContext);

    PFTitleDataManagementGetTitleNewsRequestWrapper<> request;
    FillGetTitleNewsRequest(request);
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

void AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetCatalogItems(TestContext& testContext)
{
    struct ServerGetCatalogItemsResultHolder : public GetCatalogItemsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetCatalogItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetCatalogItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementGetCatalogItemsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetCatalogItemsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetCatalogItemsResultHolder>>(testContext);

    PFTitleDataManagementGetCatalogItemsRequestWrapper<> request;
    FillGetCatalogItemsRequest(request);
    LogGetCatalogItemsRequest(&request.Model(), "TestTitleDataManagementServerGetCatalogItems");
    HRESULT hr = PFTitleDataManagementServerGetCatalogItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerGetCatalogItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetPublisherData

void AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetPublisherData(TestContext& testContext)
{
    struct ServerGetPublisherDataResultHolder : public GetPublisherDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetPublisherDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetPublisherDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementGetPublisherDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetPublisherDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPublisherDataResultHolder>>(testContext);

    PFTitleDataManagementGetPublisherDataRequestWrapper<> request;
    FillGetPublisherDataRequest(request);
    LogGetPublisherDataRequest(&request.Model(), "TestTitleDataManagementServerGetPublisherData");
    HRESULT hr = PFTitleDataManagementServerGetPublisherDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerGetPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetStoreItems

void AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetStoreItems(TestContext& testContext)
{
    struct ServerGetStoreItemsResultHolder : public GetStoreItemsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetStoreItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetStoreItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementGetStoreItemsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetStoreItemsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetStoreItemsResultHolder>>(testContext);

    PFTitleDataManagementGetStoreItemsServerRequestWrapper<> request;
    FillGetStoreItemsServerRequest(request);
    LogGetStoreItemsServerRequest(&request.Model(), "TestTitleDataManagementServerGetStoreItems");
    HRESULT hr = PFTitleDataManagementServerGetStoreItemsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerGetStoreItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetTime

void AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetTime(TestContext& testContext)
{
    struct ServerGetTimeResultHolder : public GetTimeResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetTimeGetResult(async, &result)));
            LogPFTitleDataManagementGetTimeResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetTimeResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetTimeResultHolder>>(testContext);

    HRESULT hr = PFTitleDataManagementServerGetTimeAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerGetTimeAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetTitleData

void AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetTitleData(TestContext& testContext)
{
    struct ServerGetTitleDataResultHolder : public GetTitleDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetTitleDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetTitleDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementGetTitleDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetTitleDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetTitleDataResultHolder>>(testContext);

    PFTitleDataManagementGetTitleDataRequestWrapper<> request;
    FillGetTitleDataRequest(request);
    LogGetTitleDataRequest(&request.Model(), "TestTitleDataManagementServerGetTitleData");
    HRESULT hr = PFTitleDataManagementServerGetTitleDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerGetTitleDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetTitleInternalData

void AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetTitleInternalData(TestContext& testContext)
{
    struct ServerGetTitleInternalDataResultHolder : public GetTitleDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetTitleInternalDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetTitleInternalDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementGetTitleDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetTitleDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetTitleInternalDataResultHolder>>(testContext);

    PFTitleDataManagementGetTitleDataRequestWrapper<> request;
    FillGetTitleDataRequest(request);
    LogGetTitleDataRequest(&request.Model(), "TestTitleDataManagementServerGetTitleInternalData");
    HRESULT hr = PFTitleDataManagementServerGetTitleInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerGetTitleInternalDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetTitleNews

void AutoGenTitleDataManagementTests::TestTitleDataManagementServerGetTitleNews(TestContext& testContext)
{
    struct ServerGetTitleNewsResultHolder : public GetTitleNewsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetTitleNewsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerGetTitleNewsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementGetTitleNewsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementGetTitleNewsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetTitleNewsResultHolder>>(testContext);

    PFTitleDataManagementGetTitleNewsRequestWrapper<> request;
    FillGetTitleNewsRequest(request);
    LogGetTitleNewsRequest(&request.Model(), "TestTitleDataManagementServerGetTitleNews");
    HRESULT hr = PFTitleDataManagementServerGetTitleNewsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerGetTitleNewsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerSetPublisherData

void AutoGenTitleDataManagementTests::TestTitleDataManagementServerSetPublisherData(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFTitleDataManagementSetPublisherDataRequestWrapper<> request;
    FillSetPublisherDataRequest(request);
    LogSetPublisherDataRequest(&request.Model(), "TestTitleDataManagementServerSetPublisherData");
    HRESULT hr = PFTitleDataManagementServerSetPublisherDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerSetPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerSetTitleData

void AutoGenTitleDataManagementTests::TestTitleDataManagementServerSetTitleData(TestContext& testContext)
{
    struct ServerSetTitleDataResultHolder : public SetTitleDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerSetTitleDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerSetTitleDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementSetTitleDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementSetTitleDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerSetTitleDataResultHolder>>(testContext);

    PFTitleDataManagementSetTitleDataRequestWrapper<> request;
    FillSetTitleDataRequest(request);
    LogSetTitleDataRequest(&request.Model(), "TestTitleDataManagementServerSetTitleData");
    HRESULT hr = PFTitleDataManagementServerSetTitleDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerSetTitleDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerSetTitleInternalData

void AutoGenTitleDataManagementTests::TestTitleDataManagementServerSetTitleInternalData(TestContext& testContext)
{
    struct ServerSetTitleInternalDataResultHolder : public SetTitleDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerSetTitleInternalDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFTitleDataManagementServerSetTitleInternalDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFTitleDataManagementSetTitleDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFTitleDataManagementSetTitleDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerSetTitleInternalDataResultHolder>>(testContext);

    PFTitleDataManagementSetTitleDataRequestWrapper<> request;
    FillSetTitleDataRequest(request);
    LogSetTitleDataRequest(&request.Model(), "TestTitleDataManagementServerSetTitleInternalData");
    HRESULT hr = PFTitleDataManagementServerSetTitleInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFTitleDataManagementTitleDataManagementServerSetTitleInternalDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
