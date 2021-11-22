#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenCatalogTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenCatalogTests::CatalogTestData AutoGenCatalogTests::testData;

void AutoGenCatalogTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenCatalogTests::LogHR(HRESULT hr)
{
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenCatalogTests::AddTests()
{
    // Generated tests 
    AddTest("TestCatalogCreateDraftItem", &AutoGenCatalogTests::TestCatalogCreateDraftItem);

    AddTest("TestCatalogCreateUploadUrls", &AutoGenCatalogTests::TestCatalogCreateUploadUrls);

    AddTest("TestCatalogDeleteEntityItemReviews", &AutoGenCatalogTests::TestCatalogDeleteEntityItemReviews);

    AddTest("TestCatalogDeleteItem", &AutoGenCatalogTests::TestCatalogDeleteItem);

    AddTest("TestCatalogGetCatalogConfig", &AutoGenCatalogTests::TestCatalogGetCatalogConfig);

    AddTest("TestCatalogGetDraftItem", &AutoGenCatalogTests::TestCatalogGetDraftItem);

    AddTest("TestCatalogGetDraftItems", &AutoGenCatalogTests::TestCatalogGetDraftItems);

    AddTest("TestCatalogGetEntityDraftItems", &AutoGenCatalogTests::TestCatalogGetEntityDraftItems);

    AddTest("TestCatalogGetEntityItemReview", &AutoGenCatalogTests::TestCatalogGetEntityItemReview);

    AddTest("TestCatalogGetItem", &AutoGenCatalogTests::TestCatalogGetItem);

    AddTest("TestCatalogGetItemModerationState", &AutoGenCatalogTests::TestCatalogGetItemModerationState);

    AddTest("TestCatalogGetItemPublishStatus", &AutoGenCatalogTests::TestCatalogGetItemPublishStatus);

    AddTest("TestCatalogGetItemReviews", &AutoGenCatalogTests::TestCatalogGetItemReviews);

    AddTest("TestCatalogGetItemReviewSummary", &AutoGenCatalogTests::TestCatalogGetItemReviewSummary);

    AddTest("TestCatalogPublishDraftItem", &AutoGenCatalogTests::TestCatalogPublishDraftItem);

    AddTest("TestCatalogReportItem", &AutoGenCatalogTests::TestCatalogReportItem);

    AddTest("TestCatalogReportItemReview", &AutoGenCatalogTests::TestCatalogReportItemReview);

    AddTest("TestCatalogReviewItem", &AutoGenCatalogTests::TestCatalogReviewItem);

    AddTest("TestCatalogSearchItems", &AutoGenCatalogTests::TestCatalogSearchItems);

    AddTest("TestCatalogSetItemModerationState", &AutoGenCatalogTests::TestCatalogSetItemModerationState);

    AddTest("TestCatalogSubmitItemReviewVote", &AutoGenCatalogTests::TestCatalogSubmitItemReviewVote);

    AddTest("TestCatalogTakedownItemReviews", &AutoGenCatalogTests::TestCatalogTakedownItemReviews);

    AddTest("TestCatalogUpdateCatalogConfig", &AutoGenCatalogTests::TestCatalogUpdateCatalogConfig);

    AddTest("TestCatalogUpdateDraftItem", &AutoGenCatalogTests::TestCatalogUpdateDraftItem);
}

void AutoGenCatalogTests::ClassSetUp()
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

void AutoGenCatalogTests::ClassTearDown()
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

void AutoGenCatalogTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region CreateDraftItem

void AutoGenCatalogTests::TestCatalogCreateDraftItem(TestContext& testContext)
{
    struct CreateDraftItemResultHolder : public CreateDraftItemResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCatalogCreateDraftItemGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCatalogCreateDraftItemGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCatalogCreateDraftItemResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCatalogCreateDraftItemResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateDraftItemResultHolder>>(testContext);

    PFCatalogCreateDraftItemRequestWrapper<> request;
    FillCreateDraftItemRequest(request);
    LogCreateDraftItemRequest(&request.Model(), "TestCatalogCreateDraftItem");
    HRESULT hr = PFCatalogCreateDraftItemAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogCreateDraftItemAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region CreateUploadUrls

void AutoGenCatalogTests::TestCatalogCreateUploadUrls(TestContext& testContext)
{
    struct CreateUploadUrlsResultHolder : public CreateUploadUrlsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCatalogCreateUploadUrlsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCatalogCreateUploadUrlsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCatalogCreateUploadUrlsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCatalogCreateUploadUrlsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateUploadUrlsResultHolder>>(testContext);

    PFCatalogCreateUploadUrlsRequestWrapper<> request;
    FillCreateUploadUrlsRequest(request);
    LogCreateUploadUrlsRequest(&request.Model(), "TestCatalogCreateUploadUrls");
    HRESULT hr = PFCatalogCreateUploadUrlsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogCreateUploadUrlsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region DeleteEntityItemReviews

void AutoGenCatalogTests::TestCatalogDeleteEntityItemReviews(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCatalogDeleteEntityItemReviewsRequestWrapper<> request;
    FillDeleteEntityItemReviewsRequest(request);
    LogDeleteEntityItemReviewsRequest(&request.Model(), "TestCatalogDeleteEntityItemReviews");
    HRESULT hr = PFCatalogDeleteEntityItemReviewsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogDeleteEntityItemReviewsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region DeleteItem

void AutoGenCatalogTests::TestCatalogDeleteItem(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCatalogDeleteItemRequestWrapper<> request;
    FillDeleteItemRequest(request);
    LogDeleteItemRequest(&request.Model(), "TestCatalogDeleteItem");
    HRESULT hr = PFCatalogDeleteItemAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogDeleteItemAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetCatalogConfig

void AutoGenCatalogTests::TestCatalogGetCatalogConfig(TestContext& testContext)
{
    struct GetCatalogConfigResultHolder : public GetCatalogConfigResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCatalogGetCatalogConfigGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCatalogGetCatalogConfigGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCatalogGetCatalogConfigResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCatalogGetCatalogConfigResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetCatalogConfigResultHolder>>(testContext);

    PFCatalogGetCatalogConfigRequestWrapper<> request;
    FillGetCatalogConfigRequest(request);
    LogGetCatalogConfigRequest(&request.Model(), "TestCatalogGetCatalogConfig");
    HRESULT hr = PFCatalogGetCatalogConfigAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogGetCatalogConfigAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetDraftItem

void AutoGenCatalogTests::TestCatalogGetDraftItem(TestContext& testContext)
{
    struct GetDraftItemResultHolder : public GetDraftItemResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCatalogGetDraftItemGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCatalogGetDraftItemGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCatalogGetDraftItemResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCatalogGetDraftItemResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetDraftItemResultHolder>>(testContext);

    PFCatalogGetDraftItemRequestWrapper<> request;
    FillGetDraftItemRequest(request);
    LogGetDraftItemRequest(&request.Model(), "TestCatalogGetDraftItem");
    HRESULT hr = PFCatalogGetDraftItemAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogGetDraftItemAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetDraftItems

void AutoGenCatalogTests::TestCatalogGetDraftItems(TestContext& testContext)
{
    struct GetDraftItemsResultHolder : public GetDraftItemsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCatalogGetDraftItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCatalogGetDraftItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCatalogGetDraftItemsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCatalogGetDraftItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetDraftItemsResultHolder>>(testContext);

    PFCatalogGetDraftItemsRequestWrapper<> request;
    FillGetDraftItemsRequest(request);
    LogGetDraftItemsRequest(&request.Model(), "TestCatalogGetDraftItems");
    HRESULT hr = PFCatalogGetDraftItemsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogGetDraftItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetEntityDraftItems

void AutoGenCatalogTests::TestCatalogGetEntityDraftItems(TestContext& testContext)
{
    struct GetEntityDraftItemsResultHolder : public GetEntityDraftItemsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCatalogGetEntityDraftItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCatalogGetEntityDraftItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCatalogGetEntityDraftItemsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCatalogGetEntityDraftItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetEntityDraftItemsResultHolder>>(testContext);

    PFCatalogGetEntityDraftItemsRequestWrapper<> request;
    FillGetEntityDraftItemsRequest(request);
    LogGetEntityDraftItemsRequest(&request.Model(), "TestCatalogGetEntityDraftItems");
    HRESULT hr = PFCatalogGetEntityDraftItemsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogGetEntityDraftItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetEntityItemReview

void AutoGenCatalogTests::TestCatalogGetEntityItemReview(TestContext& testContext)
{
    struct GetEntityItemReviewResultHolder : public GetEntityItemReviewResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCatalogGetEntityItemReviewGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCatalogGetEntityItemReviewGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCatalogGetEntityItemReviewResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCatalogGetEntityItemReviewResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetEntityItemReviewResultHolder>>(testContext);

    PFCatalogGetEntityItemReviewRequestWrapper<> request;
    FillGetEntityItemReviewRequest(request);
    LogGetEntityItemReviewRequest(&request.Model(), "TestCatalogGetEntityItemReview");
    HRESULT hr = PFCatalogGetEntityItemReviewAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogGetEntityItemReviewAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetItem

void AutoGenCatalogTests::TestCatalogGetItem(TestContext& testContext)
{
    struct GetItemResultHolder : public GetItemResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCatalogGetItemGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCatalogGetItemGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCatalogGetItemResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCatalogGetItemResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetItemResultHolder>>(testContext);

    PFCatalogGetItemRequestWrapper<> request;
    FillGetItemRequest(request);
    LogGetItemRequest(&request.Model(), "TestCatalogGetItem");
    HRESULT hr = PFCatalogGetItemAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogGetItemAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetItemModerationState

void AutoGenCatalogTests::TestCatalogGetItemModerationState(TestContext& testContext)
{
    struct GetItemModerationStateResultHolder : public GetItemModerationStateResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCatalogGetItemModerationStateGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCatalogGetItemModerationStateGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCatalogGetItemModerationStateResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCatalogGetItemModerationStateResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetItemModerationStateResultHolder>>(testContext);

    PFCatalogGetItemModerationStateRequestWrapper<> request;
    FillGetItemModerationStateRequest(request);
    LogGetItemModerationStateRequest(&request.Model(), "TestCatalogGetItemModerationState");
    HRESULT hr = PFCatalogGetItemModerationStateAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogGetItemModerationStateAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetItemPublishStatus

void AutoGenCatalogTests::TestCatalogGetItemPublishStatus(TestContext& testContext)
{
    struct GetItemPublishStatusResultHolder : public GetItemPublishStatusResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCatalogGetItemPublishStatusGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCatalogGetItemPublishStatusGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCatalogGetItemPublishStatusResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCatalogGetItemPublishStatusResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetItemPublishStatusResultHolder>>(testContext);

    PFCatalogGetItemPublishStatusRequestWrapper<> request;
    FillGetItemPublishStatusRequest(request);
    LogGetItemPublishStatusRequest(&request.Model(), "TestCatalogGetItemPublishStatus");
    HRESULT hr = PFCatalogGetItemPublishStatusAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogGetItemPublishStatusAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetItemReviews

void AutoGenCatalogTests::TestCatalogGetItemReviews(TestContext& testContext)
{
    struct GetItemReviewsResultHolder : public GetItemReviewsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCatalogGetItemReviewsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCatalogGetItemReviewsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCatalogGetItemReviewsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCatalogGetItemReviewsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetItemReviewsResultHolder>>(testContext);

    PFCatalogGetItemReviewsRequestWrapper<> request;
    FillGetItemReviewsRequest(request);
    LogGetItemReviewsRequest(&request.Model(), "TestCatalogGetItemReviews");
    HRESULT hr = PFCatalogGetItemReviewsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogGetItemReviewsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetItemReviewSummary

void AutoGenCatalogTests::TestCatalogGetItemReviewSummary(TestContext& testContext)
{
    struct GetItemReviewSummaryResultHolder : public GetItemReviewSummaryResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCatalogGetItemReviewSummaryGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCatalogGetItemReviewSummaryGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCatalogGetItemReviewSummaryResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCatalogGetItemReviewSummaryResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetItemReviewSummaryResultHolder>>(testContext);

    PFCatalogGetItemReviewSummaryRequestWrapper<> request;
    FillGetItemReviewSummaryRequest(request);
    LogGetItemReviewSummaryRequest(&request.Model(), "TestCatalogGetItemReviewSummary");
    HRESULT hr = PFCatalogGetItemReviewSummaryAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogGetItemReviewSummaryAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region PublishDraftItem

void AutoGenCatalogTests::TestCatalogPublishDraftItem(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCatalogPublishDraftItemRequestWrapper<> request;
    FillPublishDraftItemRequest(request);
    LogPublishDraftItemRequest(&request.Model(), "TestCatalogPublishDraftItem");
    HRESULT hr = PFCatalogPublishDraftItemAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogPublishDraftItemAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ReportItem

void AutoGenCatalogTests::TestCatalogReportItem(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCatalogReportItemRequestWrapper<> request;
    FillReportItemRequest(request);
    LogReportItemRequest(&request.Model(), "TestCatalogReportItem");
    HRESULT hr = PFCatalogReportItemAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogReportItemAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ReportItemReview

void AutoGenCatalogTests::TestCatalogReportItemReview(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCatalogReportItemReviewRequestWrapper<> request;
    FillReportItemReviewRequest(request);
    LogReportItemReviewRequest(&request.Model(), "TestCatalogReportItemReview");
    HRESULT hr = PFCatalogReportItemReviewAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogReportItemReviewAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ReviewItem

void AutoGenCatalogTests::TestCatalogReviewItem(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCatalogReviewItemRequestWrapper<> request;
    FillReviewItemRequest(request);
    LogReviewItemRequest(&request.Model(), "TestCatalogReviewItem");
    HRESULT hr = PFCatalogReviewItemAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogReviewItemAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region SearchItems

void AutoGenCatalogTests::TestCatalogSearchItems(TestContext& testContext)
{
    struct SearchItemsResultHolder : public SearchItemsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCatalogSearchItemsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCatalogSearchItemsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCatalogSearchItemsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCatalogSearchItemsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<SearchItemsResultHolder>>(testContext);

    PFCatalogSearchItemsRequestWrapper<> request;
    FillSearchItemsRequest(request);
    LogSearchItemsRequest(&request.Model(), "TestCatalogSearchItems");
    HRESULT hr = PFCatalogSearchItemsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogSearchItemsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region SetItemModerationState

void AutoGenCatalogTests::TestCatalogSetItemModerationState(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCatalogSetItemModerationStateRequestWrapper<> request;
    FillSetItemModerationStateRequest(request);
    LogSetItemModerationStateRequest(&request.Model(), "TestCatalogSetItemModerationState");
    HRESULT hr = PFCatalogSetItemModerationStateAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogSetItemModerationStateAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region SubmitItemReviewVote

void AutoGenCatalogTests::TestCatalogSubmitItemReviewVote(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCatalogSubmitItemReviewVoteRequestWrapper<> request;
    FillSubmitItemReviewVoteRequest(request);
    LogSubmitItemReviewVoteRequest(&request.Model(), "TestCatalogSubmitItemReviewVote");
    HRESULT hr = PFCatalogSubmitItemReviewVoteAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogSubmitItemReviewVoteAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region TakedownItemReviews

void AutoGenCatalogTests::TestCatalogTakedownItemReviews(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCatalogTakedownItemReviewsRequestWrapper<> request;
    FillTakedownItemReviewsRequest(request);
    LogTakedownItemReviewsRequest(&request.Model(), "TestCatalogTakedownItemReviews");
    HRESULT hr = PFCatalogTakedownItemReviewsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogTakedownItemReviewsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region UpdateCatalogConfig

void AutoGenCatalogTests::TestCatalogUpdateCatalogConfig(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCatalogUpdateCatalogConfigRequestWrapper<> request;
    FillUpdateCatalogConfigRequest(request);
    LogUpdateCatalogConfigRequest(&request.Model(), "TestCatalogUpdateCatalogConfig");
    HRESULT hr = PFCatalogUpdateCatalogConfigAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogUpdateCatalogConfigAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region UpdateDraftItem

void AutoGenCatalogTests::TestCatalogUpdateDraftItem(TestContext& testContext)
{
    struct UpdateDraftItemResultHolder : public UpdateDraftItemResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCatalogUpdateDraftItemGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCatalogUpdateDraftItemGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCatalogUpdateDraftItemResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCatalogUpdateDraftItemResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<UpdateDraftItemResultHolder>>(testContext);

    PFCatalogUpdateDraftItemRequestWrapper<> request;
    FillUpdateDraftItemRequest(request);
    LogUpdateDraftItemRequest(&request.Model(), "TestCatalogUpdateDraftItem");
    HRESULT hr = PFCatalogUpdateDraftItemAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCatalogCatalogUpdateDraftItemAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
