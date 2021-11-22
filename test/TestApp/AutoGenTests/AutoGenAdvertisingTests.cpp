#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenAdvertisingTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenAdvertisingTests::AdvertisingTestData AutoGenAdvertisingTests::testData;

void AutoGenAdvertisingTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenAdvertisingTests::LogHR(HRESULT hr)
{
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenAdvertisingTests::AddTests()
{
    // Generated tests 
    AddTest("TestAdvertisingClientAttributeInstall", &AutoGenAdvertisingTests::TestAdvertisingClientAttributeInstall);

    AddTest("TestAdvertisingClientGetAdPlacements", &AutoGenAdvertisingTests::TestAdvertisingClientGetAdPlacements);

    AddTest("TestAdvertisingClientReportAdActivity", &AutoGenAdvertisingTests::TestAdvertisingClientReportAdActivity);

    AddTest("TestAdvertisingClientRewardAdActivity", &AutoGenAdvertisingTests::TestAdvertisingClientRewardAdActivity);
}

void AutoGenAdvertisingTests::ClassSetUp()
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

void AutoGenAdvertisingTests::ClassTearDown()
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

void AutoGenAdvertisingTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region ClientAttributeInstall

void AutoGenAdvertisingTests::TestAdvertisingClientAttributeInstall(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAdvertisingAttributeInstallRequestWrapper<> request;
    FillAttributeInstallRequest(request);
    LogAttributeInstallRequest(&request.Model(), "TestAdvertisingClientAttributeInstall");
    HRESULT hr = PFAdvertisingClientAttributeInstallAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAdvertisingAdvertisingClientAttributeInstallAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetAdPlacements

void AutoGenAdvertisingTests::TestAdvertisingClientGetAdPlacements(TestContext& testContext)
{
    struct ClientGetAdPlacementsResultHolder : public GetAdPlacementsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAdvertisingClientGetAdPlacementsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAdvertisingClientGetAdPlacementsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAdvertisingGetAdPlacementsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAdvertisingGetAdPlacementsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetAdPlacementsResultHolder>>(testContext);

    PFAdvertisingGetAdPlacementsRequestWrapper<> request;
    FillGetAdPlacementsRequest(request);
    LogGetAdPlacementsRequest(&request.Model(), "TestAdvertisingClientGetAdPlacements");
    HRESULT hr = PFAdvertisingClientGetAdPlacementsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAdvertisingAdvertisingClientGetAdPlacementsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientReportAdActivity

void AutoGenAdvertisingTests::TestAdvertisingClientReportAdActivity(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFAdvertisingReportAdActivityRequestWrapper<> request;
    FillReportAdActivityRequest(request);
    LogReportAdActivityRequest(&request.Model(), "TestAdvertisingClientReportAdActivity");
    HRESULT hr = PFAdvertisingClientReportAdActivityAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAdvertisingAdvertisingClientReportAdActivityAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientRewardAdActivity

void AutoGenAdvertisingTests::TestAdvertisingClientRewardAdActivity(TestContext& testContext)
{
    struct ClientRewardAdActivityResultHolder : public RewardAdActivityResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFAdvertisingClientRewardAdActivityGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFAdvertisingClientRewardAdActivityGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFAdvertisingRewardAdActivityResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFAdvertisingRewardAdActivityResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientRewardAdActivityResultHolder>>(testContext);

    PFAdvertisingRewardAdActivityRequestWrapper<> request;
    FillRewardAdActivityRequest(request);
    LogRewardAdActivityRequest(&request.Model(), "TestAdvertisingClientRewardAdActivity");
    HRESULT hr = PFAdvertisingClientRewardAdActivityAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFAdvertisingAdvertisingClientRewardAdActivityAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
