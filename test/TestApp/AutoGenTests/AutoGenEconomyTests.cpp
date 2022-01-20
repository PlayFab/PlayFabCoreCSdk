#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenEconomyTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenEconomyTests::EconomyTestData AutoGenEconomyTests::testData;

void AutoGenEconomyTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenEconomyTests::LogHR(HRESULT hr)
{
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenEconomyTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestEconomyAdminRefundPurchase", &AutoGenEconomyTests::TestEconomyAdminRefundPurchase);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestEconomyAdminResolvePurchaseDispute", &AutoGenEconomyTests::TestEconomyAdminResolvePurchaseDispute);
#endif
}

void AutoGenEconomyTests::ClassSetUp()
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

void AutoGenEconomyTests::ClassTearDown()
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

void AutoGenEconomyTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AdminRefundPurchase

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenEconomyTests::TestEconomyAdminRefundPurchase(TestContext& testContext)
{
    struct AdminRefundPurchaseResultHolderStruct : public RefundPurchaseResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFEconomyAdminRefundPurchaseGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFEconomyAdminRefundPurchaseGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogRefundPurchaseResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminRefundPurchaseResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminRefundPurchaseResultHolderStruct>>(testContext);

    PFEconomyRefundPurchaseRequestWrapper<> request;
    FillAdminRefundPurchaseRequest(request);
    LogRefundPurchaseRequest(&request.Model(), "TestEconomyAdminRefundPurchase");
    HRESULT hr = PFEconomyAdminRefundPurchaseAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFEconomyEconomyAdminRefundPurchaseAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminResolvePurchaseDispute

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenEconomyTests::TestEconomyAdminResolvePurchaseDispute(TestContext& testContext)
{
    struct AdminResolvePurchaseDisputeResultHolderStruct : public ResolvePurchaseDisputeResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFEconomyAdminResolvePurchaseDisputeGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFEconomyAdminResolvePurchaseDisputeGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogResolvePurchaseDisputeResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminResolvePurchaseDisputeResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminResolvePurchaseDisputeResultHolderStruct>>(testContext);

    PFEconomyResolvePurchaseDisputeRequestWrapper<> request;
    FillAdminResolvePurchaseDisputeRequest(request);
    LogResolvePurchaseDisputeRequest(&request.Model(), "TestEconomyAdminResolvePurchaseDispute");
    HRESULT hr = PFEconomyAdminResolvePurchaseDisputeAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFEconomyEconomyAdminResolvePurchaseDisputeAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
