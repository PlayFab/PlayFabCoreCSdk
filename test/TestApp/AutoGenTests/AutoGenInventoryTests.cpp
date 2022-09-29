#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenInventoryTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenInventoryTests::InventoryTestData AutoGenInventoryTests::testData;

void AutoGenInventoryTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenInventoryTests::LogHR(HRESULT hr)
{
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenInventoryTests::AddTests()
{
    // Generated tests 
    AddTest("TestInventoryAddInventoryItems", &AutoGenInventoryTests::TestInventoryAddInventoryItems);

    AddTest("TestInventoryDeleteInventoryCollection", &AutoGenInventoryTests::TestInventoryDeleteInventoryCollection);

    AddTest("TestInventoryDeleteInventoryItems", &AutoGenInventoryTests::TestInventoryDeleteInventoryItems);

    AddTest("TestInventoryExecuteInventoryOperations", &AutoGenInventoryTests::TestInventoryExecuteInventoryOperations);

    AddTest("TestInventoryGetInventoryCollectionIds", &AutoGenInventoryTests::TestInventoryGetInventoryCollectionIds);

    AddTest("TestInventoryGetInventoryItems", &AutoGenInventoryTests::TestInventoryGetInventoryItems);

    AddTest("TestInventoryGetMicrosoftStoreAccessTokens", &AutoGenInventoryTests::TestInventoryGetMicrosoftStoreAccessTokens);

    AddTest("TestInventoryPurchaseInventoryItems", &AutoGenInventoryTests::TestInventoryPurchaseInventoryItems);

    AddTest("TestInventoryRedeemAppleAppStoreInventoryItems", &AutoGenInventoryTests::TestInventoryRedeemAppleAppStoreInventoryItems);

    AddTest("TestInventoryRedeemGooglePlayInventoryItems", &AutoGenInventoryTests::TestInventoryRedeemGooglePlayInventoryItems);

    AddTest("TestInventoryRedeemMicrosoftStoreInventoryItems", &AutoGenInventoryTests::TestInventoryRedeemMicrosoftStoreInventoryItems);

    AddTest("TestInventoryRedeemNintendoEShopInventoryItems", &AutoGenInventoryTests::TestInventoryRedeemNintendoEShopInventoryItems);

    AddTest("TestInventoryRedeemPlayStationStoreInventoryItems", &AutoGenInventoryTests::TestInventoryRedeemPlayStationStoreInventoryItems);

    AddTest("TestInventoryRedeemSteamInventoryItems", &AutoGenInventoryTests::TestInventoryRedeemSteamInventoryItems);

    AddTest("TestInventorySubtractInventoryItems", &AutoGenInventoryTests::TestInventorySubtractInventoryItems);

    AddTest("TestInventoryTransferInventoryItems", &AutoGenInventoryTests::TestInventoryTransferInventoryItems);

    AddTest("TestInventoryUpdateInventoryItems", &AutoGenInventoryTests::TestInventoryUpdateInventoryItems);
}

void AutoGenInventoryTests::ClassSetUp()
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

void AutoGenInventoryTests::ClassTearDown()
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

void AutoGenInventoryTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AddInventoryItems

void AutoGenInventoryTests::TestInventoryAddInventoryItems(TestContext& testContext)
{
    struct AddInventoryItemsResultHolderStruct : public AddInventoryItemsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFInventoryAddInventoryItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFInventoryAddInventoryItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogAddInventoryItemsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAddInventoryItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AddInventoryItemsResultHolderStruct>>(testContext);

    PFInventoryAddInventoryItemsRequestWrapper<> request;
    FillAddInventoryItemsRequest(request);
    LogAddInventoryItemsRequest(&request.Model(), "TestInventoryAddInventoryItems");
    HRESULT hr = PFInventoryAddInventoryItemsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFInventoryInventoryAddInventoryItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region DeleteInventoryCollection

void AutoGenInventoryTests::TestInventoryDeleteInventoryCollection(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFInventoryDeleteInventoryCollectionRequestWrapper<> request;
    FillDeleteInventoryCollectionRequest(request);
    LogDeleteInventoryCollectionRequest(&request.Model(), "TestInventoryDeleteInventoryCollection");
    HRESULT hr = PFInventoryDeleteInventoryCollectionAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFInventoryInventoryDeleteInventoryCollectionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region DeleteInventoryItems

void AutoGenInventoryTests::TestInventoryDeleteInventoryItems(TestContext& testContext)
{
    struct DeleteInventoryItemsResultHolderStruct : public DeleteInventoryItemsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFInventoryDeleteInventoryItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFInventoryDeleteInventoryItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogDeleteInventoryItemsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateDeleteInventoryItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<DeleteInventoryItemsResultHolderStruct>>(testContext);

    PFInventoryDeleteInventoryItemsRequestWrapper<> request;
    FillDeleteInventoryItemsRequest(request);
    LogDeleteInventoryItemsRequest(&request.Model(), "TestInventoryDeleteInventoryItems");
    HRESULT hr = PFInventoryDeleteInventoryItemsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFInventoryInventoryDeleteInventoryItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ExecuteInventoryOperations

void AutoGenInventoryTests::TestInventoryExecuteInventoryOperations(TestContext& testContext)
{
    struct ExecuteInventoryOperationsResultHolderStruct : public ExecuteInventoryOperationsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFInventoryExecuteInventoryOperationsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFInventoryExecuteInventoryOperationsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogExecuteInventoryOperationsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateExecuteInventoryOperationsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ExecuteInventoryOperationsResultHolderStruct>>(testContext);

    PFInventoryExecuteInventoryOperationsRequestWrapper<> request;
    FillExecuteInventoryOperationsRequest(request);
    LogExecuteInventoryOperationsRequest(&request.Model(), "TestInventoryExecuteInventoryOperations");
    HRESULT hr = PFInventoryExecuteInventoryOperationsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFInventoryInventoryExecuteInventoryOperationsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetInventoryCollectionIds

void AutoGenInventoryTests::TestInventoryGetInventoryCollectionIds(TestContext& testContext)
{
    struct GetInventoryCollectionIdsResultHolderStruct : public GetInventoryCollectionIdsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFInventoryGetInventoryCollectionIdsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFInventoryGetInventoryCollectionIdsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetInventoryCollectionIdsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetInventoryCollectionIdsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetInventoryCollectionIdsResultHolderStruct>>(testContext);

    PFInventoryGetInventoryCollectionIdsRequestWrapper<> request;
    FillGetInventoryCollectionIdsRequest(request);
    LogGetInventoryCollectionIdsRequest(&request.Model(), "TestInventoryGetInventoryCollectionIds");
    HRESULT hr = PFInventoryGetInventoryCollectionIdsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFInventoryInventoryGetInventoryCollectionIdsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetInventoryItems

void AutoGenInventoryTests::TestInventoryGetInventoryItems(TestContext& testContext)
{
    struct GetInventoryItemsResultHolderStruct : public GetInventoryItemsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFInventoryGetInventoryItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFInventoryGetInventoryItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetInventoryItemsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetInventoryItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetInventoryItemsResultHolderStruct>>(testContext);

    PFInventoryGetInventoryItemsRequestWrapper<> request;
    FillGetInventoryItemsRequest(request);
    LogGetInventoryItemsRequest(&request.Model(), "TestInventoryGetInventoryItems");
    HRESULT hr = PFInventoryGetInventoryItemsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFInventoryInventoryGetInventoryItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetMicrosoftStoreAccessTokens

void AutoGenInventoryTests::TestInventoryGetMicrosoftStoreAccessTokens(TestContext& testContext)
{
    struct GetMicrosoftStoreAccessTokensResultHolderStruct : public GetMicrosoftStoreAccessTokensResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFInventoryGetMicrosoftStoreAccessTokensGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFInventoryGetMicrosoftStoreAccessTokensGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetMicrosoftStoreAccessTokensResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetMicrosoftStoreAccessTokensResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetMicrosoftStoreAccessTokensResultHolderStruct>>(testContext);

    PFInventoryGetMicrosoftStoreAccessTokensRequestWrapper<> request;
    FillGetMicrosoftStoreAccessTokensRequest(request);
    LogGetMicrosoftStoreAccessTokensRequest(&request.Model(), "TestInventoryGetMicrosoftStoreAccessTokens");
    HRESULT hr = PFInventoryGetMicrosoftStoreAccessTokensAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFInventoryInventoryGetMicrosoftStoreAccessTokensAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region PurchaseInventoryItems

void AutoGenInventoryTests::TestInventoryPurchaseInventoryItems(TestContext& testContext)
{
    struct PurchaseInventoryItemsResultHolderStruct : public PurchaseInventoryItemsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFInventoryPurchaseInventoryItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFInventoryPurchaseInventoryItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPurchaseInventoryItemsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePurchaseInventoryItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<PurchaseInventoryItemsResultHolderStruct>>(testContext);

    PFInventoryPurchaseInventoryItemsRequestWrapper<> request;
    FillPurchaseInventoryItemsRequest(request);
    LogPurchaseInventoryItemsRequest(&request.Model(), "TestInventoryPurchaseInventoryItems");
    HRESULT hr = PFInventoryPurchaseInventoryItemsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFInventoryInventoryPurchaseInventoryItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region RedeemAppleAppStoreInventoryItems

void AutoGenInventoryTests::TestInventoryRedeemAppleAppStoreInventoryItems(TestContext& testContext)
{
    struct RedeemAppleAppStoreInventoryItemsResultHolderStruct : public RedeemAppleAppStoreInventoryItemsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFInventoryRedeemAppleAppStoreInventoryItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFInventoryRedeemAppleAppStoreInventoryItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogRedeemAppleAppStoreInventoryItemsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateRedeemAppleAppStoreInventoryItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<RedeemAppleAppStoreInventoryItemsResultHolderStruct>>(testContext);

    PFInventoryRedeemAppleAppStoreInventoryItemsRequestWrapper<> request;
    FillRedeemAppleAppStoreInventoryItemsRequest(request);
    LogRedeemAppleAppStoreInventoryItemsRequest(&request.Model(), "TestInventoryRedeemAppleAppStoreInventoryItems");
    HRESULT hr = PFInventoryRedeemAppleAppStoreInventoryItemsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFInventoryInventoryRedeemAppleAppStoreInventoryItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region RedeemGooglePlayInventoryItems

void AutoGenInventoryTests::TestInventoryRedeemGooglePlayInventoryItems(TestContext& testContext)
{
    struct RedeemGooglePlayInventoryItemsResultHolderStruct : public RedeemGooglePlayInventoryItemsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFInventoryRedeemGooglePlayInventoryItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFInventoryRedeemGooglePlayInventoryItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogRedeemGooglePlayInventoryItemsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateRedeemGooglePlayInventoryItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<RedeemGooglePlayInventoryItemsResultHolderStruct>>(testContext);

    PFInventoryRedeemGooglePlayInventoryItemsRequestWrapper<> request;
    FillRedeemGooglePlayInventoryItemsRequest(request);
    LogRedeemGooglePlayInventoryItemsRequest(&request.Model(), "TestInventoryRedeemGooglePlayInventoryItems");
    HRESULT hr = PFInventoryRedeemGooglePlayInventoryItemsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFInventoryInventoryRedeemGooglePlayInventoryItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region RedeemMicrosoftStoreInventoryItems

void AutoGenInventoryTests::TestInventoryRedeemMicrosoftStoreInventoryItems(TestContext& testContext)
{
    struct RedeemMicrosoftStoreInventoryItemsResultHolderStruct : public RedeemMicrosoftStoreInventoryItemsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFInventoryRedeemMicrosoftStoreInventoryItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFInventoryRedeemMicrosoftStoreInventoryItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogRedeemMicrosoftStoreInventoryItemsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateRedeemMicrosoftStoreInventoryItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<RedeemMicrosoftStoreInventoryItemsResultHolderStruct>>(testContext);

    PFInventoryRedeemMicrosoftStoreInventoryItemsRequestWrapper<> request;
    FillRedeemMicrosoftStoreInventoryItemsRequest(request);
    LogRedeemMicrosoftStoreInventoryItemsRequest(&request.Model(), "TestInventoryRedeemMicrosoftStoreInventoryItems");
    HRESULT hr = PFInventoryRedeemMicrosoftStoreInventoryItemsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFInventoryInventoryRedeemMicrosoftStoreInventoryItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region RedeemNintendoEShopInventoryItems

void AutoGenInventoryTests::TestInventoryRedeemNintendoEShopInventoryItems(TestContext& testContext)
{
    struct RedeemNintendoEShopInventoryItemsResultHolderStruct : public RedeemNintendoEShopInventoryItemsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFInventoryRedeemNintendoEShopInventoryItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFInventoryRedeemNintendoEShopInventoryItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogRedeemNintendoEShopInventoryItemsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateRedeemNintendoEShopInventoryItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<RedeemNintendoEShopInventoryItemsResultHolderStruct>>(testContext);

    PFInventoryRedeemNintendoEShopInventoryItemsRequestWrapper<> request;
    FillRedeemNintendoEShopInventoryItemsRequest(request);
    LogRedeemNintendoEShopInventoryItemsRequest(&request.Model(), "TestInventoryRedeemNintendoEShopInventoryItems");
    HRESULT hr = PFInventoryRedeemNintendoEShopInventoryItemsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFInventoryInventoryRedeemNintendoEShopInventoryItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region RedeemPlayStationStoreInventoryItems

void AutoGenInventoryTests::TestInventoryRedeemPlayStationStoreInventoryItems(TestContext& testContext)
{
    struct RedeemPlayStationStoreInventoryItemsResultHolderStruct : public RedeemPlayStationStoreInventoryItemsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFInventoryRedeemPlayStationStoreInventoryItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFInventoryRedeemPlayStationStoreInventoryItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogRedeemPlayStationStoreInventoryItemsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateRedeemPlayStationStoreInventoryItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<RedeemPlayStationStoreInventoryItemsResultHolderStruct>>(testContext);

    PFInventoryRedeemPlayStationStoreInventoryItemsRequestWrapper<> request;
    FillRedeemPlayStationStoreInventoryItemsRequest(request);
    LogRedeemPlayStationStoreInventoryItemsRequest(&request.Model(), "TestInventoryRedeemPlayStationStoreInventoryItems");
    HRESULT hr = PFInventoryRedeemPlayStationStoreInventoryItemsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFInventoryInventoryRedeemPlayStationStoreInventoryItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region RedeemSteamInventoryItems

void AutoGenInventoryTests::TestInventoryRedeemSteamInventoryItems(TestContext& testContext)
{
    struct RedeemSteamInventoryItemsResultHolderStruct : public RedeemSteamInventoryItemsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFInventoryRedeemSteamInventoryItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFInventoryRedeemSteamInventoryItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogRedeemSteamInventoryItemsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateRedeemSteamInventoryItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<RedeemSteamInventoryItemsResultHolderStruct>>(testContext);

    PFInventoryRedeemSteamInventoryItemsRequestWrapper<> request;
    FillRedeemSteamInventoryItemsRequest(request);
    LogRedeemSteamInventoryItemsRequest(&request.Model(), "TestInventoryRedeemSteamInventoryItems");
    HRESULT hr = PFInventoryRedeemSteamInventoryItemsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFInventoryInventoryRedeemSteamInventoryItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region SubtractInventoryItems

void AutoGenInventoryTests::TestInventorySubtractInventoryItems(TestContext& testContext)
{
    struct SubtractInventoryItemsResultHolderStruct : public SubtractInventoryItemsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFInventorySubtractInventoryItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFInventorySubtractInventoryItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogSubtractInventoryItemsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateSubtractInventoryItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<SubtractInventoryItemsResultHolderStruct>>(testContext);

    PFInventorySubtractInventoryItemsRequestWrapper<> request;
    FillSubtractInventoryItemsRequest(request);
    LogSubtractInventoryItemsRequest(&request.Model(), "TestInventorySubtractInventoryItems");
    HRESULT hr = PFInventorySubtractInventoryItemsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFInventoryInventorySubtractInventoryItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region TransferInventoryItems

void AutoGenInventoryTests::TestInventoryTransferInventoryItems(TestContext& testContext)
{
    struct TransferInventoryItemsResultHolderStruct : public TransferInventoryItemsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFInventoryTransferInventoryItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFInventoryTransferInventoryItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogTransferInventoryItemsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateTransferInventoryItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<TransferInventoryItemsResultHolderStruct>>(testContext);

    PFInventoryTransferInventoryItemsRequestWrapper<> request;
    FillTransferInventoryItemsRequest(request);
    LogTransferInventoryItemsRequest(&request.Model(), "TestInventoryTransferInventoryItems");
    HRESULT hr = PFInventoryTransferInventoryItemsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFInventoryInventoryTransferInventoryItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region UpdateInventoryItems

void AutoGenInventoryTests::TestInventoryUpdateInventoryItems(TestContext& testContext)
{
    struct UpdateInventoryItemsResultHolderStruct : public UpdateInventoryItemsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFInventoryUpdateInventoryItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFInventoryUpdateInventoryItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogUpdateInventoryItemsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateUpdateInventoryItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<UpdateInventoryItemsResultHolderStruct>>(testContext);

    PFInventoryUpdateInventoryItemsRequestWrapper<> request;
    FillUpdateInventoryItemsRequest(request);
    LogUpdateInventoryItemsRequest(&request.Model(), "TestInventoryUpdateInventoryItems");
    HRESULT hr = PFInventoryUpdateInventoryItemsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFInventoryInventoryUpdateInventoryItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
