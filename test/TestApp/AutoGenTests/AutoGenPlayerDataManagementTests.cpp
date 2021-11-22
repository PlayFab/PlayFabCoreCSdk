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
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenPlayerDataManagementTests::AddTests()
{
    // Generated tests 
    AddTest("TestPlayerDataManagementAdminCreatePlayerStatisticDefinition", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminCreatePlayerStatisticDefinition);

    AddTest("TestPlayerDataManagementAdminGetDataReport", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetDataReport);

    AddTest("TestPlayerDataManagementAdminGetPlayerStatisticDefinitions", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetPlayerStatisticDefinitions);

    AddTest("TestPlayerDataManagementAdminGetPlayerStatisticVersions", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetPlayerStatisticVersions);

    AddTest("TestPlayerDataManagementAdminGetUserData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserData);

    AddTest("TestPlayerDataManagementAdminGetUserInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserInternalData);

    AddTest("TestPlayerDataManagementAdminGetUserPublisherData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserPublisherData);

    AddTest("TestPlayerDataManagementAdminGetUserPublisherInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserPublisherInternalData);

    AddTest("TestPlayerDataManagementAdminGetUserPublisherReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserPublisherReadOnlyData);

    AddTest("TestPlayerDataManagementAdminGetUserReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserReadOnlyData);

    AddTest("TestPlayerDataManagementAdminIncrementPlayerStatisticVersion", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminIncrementPlayerStatisticVersion);

    AddTest("TestPlayerDataManagementAdminRefundPurchase", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminRefundPurchase);

    AddTest("TestPlayerDataManagementAdminResetUserStatistics", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminResetUserStatistics);

    AddTest("TestPlayerDataManagementAdminResolvePurchaseDispute", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminResolvePurchaseDispute);

    AddTest("TestPlayerDataManagementAdminUpdatePlayerStatisticDefinition", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdatePlayerStatisticDefinition);

    AddTest("TestPlayerDataManagementAdminUpdateUserData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserData);

    AddTest("TestPlayerDataManagementAdminUpdateUserInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserInternalData);

    AddTest("TestPlayerDataManagementAdminUpdateUserPublisherData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserPublisherData);

    AddTest("TestPlayerDataManagementAdminUpdateUserPublisherInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserPublisherInternalData);

    AddTest("TestPlayerDataManagementAdminUpdateUserPublisherReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserPublisherReadOnlyData);

    AddTest("TestPlayerDataManagementAdminUpdateUserReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserReadOnlyData);

    AddTest("TestPlayerDataManagementClientGetFriendLeaderboard", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetFriendLeaderboard);

    AddTest("TestPlayerDataManagementClientGetFriendLeaderboardAroundPlayer", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetFriendLeaderboardAroundPlayer);

    AddTest("TestPlayerDataManagementClientGetLeaderboard", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetLeaderboard);

    AddTest("TestPlayerDataManagementClientGetLeaderboardAroundPlayer", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetLeaderboardAroundPlayer);

    AddTest("TestPlayerDataManagementClientGetPlayerStatistics", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetPlayerStatistics);

    AddTest("TestPlayerDataManagementClientGetPlayerStatisticVersions", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetPlayerStatisticVersions);

    AddTest("TestPlayerDataManagementClientGetUserData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetUserData);

    AddTest("TestPlayerDataManagementClientGetUserPublisherData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetUserPublisherData);

    AddTest("TestPlayerDataManagementClientGetUserPublisherReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetUserPublisherReadOnlyData);

    AddTest("TestPlayerDataManagementClientGetUserReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetUserReadOnlyData);

    AddTest("TestPlayerDataManagementClientUpdatePlayerStatistics", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientUpdatePlayerStatistics);

    AddTest("TestPlayerDataManagementClientUpdateUserData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientUpdateUserData);

    AddTest("TestPlayerDataManagementClientUpdateUserPublisherData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientUpdateUserPublisherData);

    AddTest("TestPlayerDataManagementServerGetFriendLeaderboard", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetFriendLeaderboard);

    AddTest("TestPlayerDataManagementServerGetLeaderboard", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetLeaderboard);

    AddTest("TestPlayerDataManagementServerGetLeaderboardAroundUser", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetLeaderboardAroundUser);

    AddTest("TestPlayerDataManagementServerGetPlayerCombinedInfo", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetPlayerCombinedInfo);

    AddTest("TestPlayerDataManagementServerGetPlayerStatistics", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetPlayerStatistics);

    AddTest("TestPlayerDataManagementServerGetPlayerStatisticVersions", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetPlayerStatisticVersions);

    AddTest("TestPlayerDataManagementServerGetUserData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserData);

    AddTest("TestPlayerDataManagementServerGetUserInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserInternalData);

    AddTest("TestPlayerDataManagementServerGetUserPublisherData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserPublisherData);

    AddTest("TestPlayerDataManagementServerGetUserPublisherInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserPublisherInternalData);

    AddTest("TestPlayerDataManagementServerGetUserPublisherReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserPublisherReadOnlyData);

    AddTest("TestPlayerDataManagementServerGetUserReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserReadOnlyData);

    AddTest("TestPlayerDataManagementServerUpdatePlayerStatistics", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdatePlayerStatistics);

    AddTest("TestPlayerDataManagementServerUpdateUserData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserData);

    AddTest("TestPlayerDataManagementServerUpdateUserInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserInternalData);

    AddTest("TestPlayerDataManagementServerUpdateUserPublisherData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserPublisherData);

    AddTest("TestPlayerDataManagementServerUpdateUserPublisherInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserPublisherInternalData);

    AddTest("TestPlayerDataManagementServerUpdateUserPublisherReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserPublisherReadOnlyData);

    AddTest("TestPlayerDataManagementServerUpdateUserReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserReadOnlyData);
}

void AutoGenPlayerDataManagementTests::ClassSetUp()
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

#pragma region AdminCreatePlayerStatisticDefinition

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminCreatePlayerStatisticDefinition(TestContext& testContext)
{
    struct AdminCreatePlayerStatisticDefinitionResultHolder : public CreatePlayerStatisticDefinitionResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminCreatePlayerStatisticDefinitionGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminCreatePlayerStatisticDefinitionGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementCreatePlayerStatisticDefinitionResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementCreatePlayerStatisticDefinitionResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminCreatePlayerStatisticDefinitionResultHolder>>(testContext);

    PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper<> request;
    FillCreatePlayerStatisticDefinitionRequest(request);
    LogCreatePlayerStatisticDefinitionRequest(&request.Model(), "TestPlayerDataManagementAdminCreatePlayerStatisticDefinition");
    HRESULT hr = PFPlayerDataManagementAdminCreatePlayerStatisticDefinitionAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminCreatePlayerStatisticDefinitionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetDataReport

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetDataReport(TestContext& testContext)
{
    struct AdminGetDataReportResultHolder : public GetDataReportResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetDataReportGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetDataReportGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementGetDataReportResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementGetDataReportResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetDataReportResultHolder>>(testContext);

    PFPlayerDataManagementGetDataReportRequestWrapper<> request;
    FillGetDataReportRequest(request);
    LogGetDataReportRequest(&request.Model(), "TestPlayerDataManagementAdminGetDataReport");
    HRESULT hr = PFPlayerDataManagementAdminGetDataReportAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminGetDataReportAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetPlayerStatisticDefinitions

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetPlayerStatisticDefinitions(TestContext& testContext)
{
    struct AdminGetPlayerStatisticDefinitionsResultHolder : public GetPlayerStatisticDefinitionsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetPlayerStatisticDefinitionsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetPlayerStatisticDefinitionsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementGetPlayerStatisticDefinitionsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementGetPlayerStatisticDefinitionsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetPlayerStatisticDefinitionsResultHolder>>(testContext);

    HRESULT hr = PFPlayerDataManagementAdminGetPlayerStatisticDefinitionsAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminGetPlayerStatisticDefinitionsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetPlayerStatisticVersions

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetPlayerStatisticVersions(TestContext& testContext)
{
    struct AdminGetPlayerStatisticVersionsResultHolder : public GetPlayerStatisticVersionsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetPlayerStatisticVersionsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetPlayerStatisticVersionsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementGetPlayerStatisticVersionsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementGetPlayerStatisticVersionsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetPlayerStatisticVersionsResultHolder>>(testContext);

    PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper<> request;
    FillGetPlayerStatisticVersionsRequest(request);
    LogGetPlayerStatisticVersionsRequest(&request.Model(), "TestPlayerDataManagementAdminGetPlayerStatisticVersions");
    HRESULT hr = PFPlayerDataManagementAdminGetPlayerStatisticVersionsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminGetPlayerStatisticVersionsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetUserData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserData(TestContext& testContext)
{
    struct AdminGetUserDataResultHolder : public AdminGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementAdminGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserDataResultHolder>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillGetUserDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminGetUserData");
    HRESULT hr = PFPlayerDataManagementAdminGetUserDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminGetUserDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetUserInternalData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserInternalData(TestContext& testContext)
{
    struct AdminGetUserInternalDataResultHolder : public AdminGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserInternalDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserInternalDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementAdminGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserInternalDataResultHolder>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillGetUserDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminGetUserInternalData");
    HRESULT hr = PFPlayerDataManagementAdminGetUserInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminGetUserInternalDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetUserPublisherData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserPublisherData(TestContext& testContext)
{
    struct AdminGetUserPublisherDataResultHolder : public AdminGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserPublisherDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserPublisherDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementAdminGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserPublisherDataResultHolder>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillGetUserDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminGetUserPublisherData");
    HRESULT hr = PFPlayerDataManagementAdminGetUserPublisherDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminGetUserPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetUserPublisherInternalData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserPublisherInternalData(TestContext& testContext)
{
    struct AdminGetUserPublisherInternalDataResultHolder : public AdminGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserPublisherInternalDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserPublisherInternalDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementAdminGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserPublisherInternalDataResultHolder>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillGetUserDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminGetUserPublisherInternalData");
    HRESULT hr = PFPlayerDataManagementAdminGetUserPublisherInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminGetUserPublisherInternalDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetUserPublisherReadOnlyData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserPublisherReadOnlyData(TestContext& testContext)
{
    struct AdminGetUserPublisherReadOnlyDataResultHolder : public AdminGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserPublisherReadOnlyDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserPublisherReadOnlyDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementAdminGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserPublisherReadOnlyDataResultHolder>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillGetUserDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminGetUserPublisherReadOnlyData");
    HRESULT hr = PFPlayerDataManagementAdminGetUserPublisherReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminGetUserPublisherReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminGetUserReadOnlyData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserReadOnlyData(TestContext& testContext)
{
    struct AdminGetUserReadOnlyDataResultHolder : public AdminGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserReadOnlyDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminGetUserReadOnlyDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementAdminGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserReadOnlyDataResultHolder>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillGetUserDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminGetUserReadOnlyData");
    HRESULT hr = PFPlayerDataManagementAdminGetUserReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminGetUserReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminIncrementPlayerStatisticVersion

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminIncrementPlayerStatisticVersion(TestContext& testContext)
{
    struct AdminIncrementPlayerStatisticVersionResultHolder : public IncrementPlayerStatisticVersionResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminIncrementPlayerStatisticVersionGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminIncrementPlayerStatisticVersionGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementIncrementPlayerStatisticVersionResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementIncrementPlayerStatisticVersionResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminIncrementPlayerStatisticVersionResultHolder>>(testContext);

    PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper<> request;
    FillIncrementPlayerStatisticVersionRequest(request);
    LogIncrementPlayerStatisticVersionRequest(&request.Model(), "TestPlayerDataManagementAdminIncrementPlayerStatisticVersion");
    HRESULT hr = PFPlayerDataManagementAdminIncrementPlayerStatisticVersionAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminIncrementPlayerStatisticVersionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminRefundPurchase

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminRefundPurchase(TestContext& testContext)
{
    struct AdminRefundPurchaseResultHolder : public RefundPurchaseResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminRefundPurchaseGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminRefundPurchaseGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementRefundPurchaseResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementRefundPurchaseResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminRefundPurchaseResultHolder>>(testContext);

    PFPlayerDataManagementRefundPurchaseRequestWrapper<> request;
    FillRefundPurchaseRequest(request);
    LogRefundPurchaseRequest(&request.Model(), "TestPlayerDataManagementAdminRefundPurchase");
    HRESULT hr = PFPlayerDataManagementAdminRefundPurchaseAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminRefundPurchaseAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminResetUserStatistics

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminResetUserStatistics(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayerDataManagementResetUserStatisticsRequestWrapper<> request;
    FillResetUserStatisticsRequest(request);
    LogResetUserStatisticsRequest(&request.Model(), "TestPlayerDataManagementAdminResetUserStatistics");
    HRESULT hr = PFPlayerDataManagementAdminResetUserStatisticsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminResetUserStatisticsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminResolvePurchaseDispute

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminResolvePurchaseDispute(TestContext& testContext)
{
    struct AdminResolvePurchaseDisputeResultHolder : public ResolvePurchaseDisputeResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminResolvePurchaseDisputeGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminResolvePurchaseDisputeGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementResolvePurchaseDisputeResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementResolvePurchaseDisputeResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminResolvePurchaseDisputeResultHolder>>(testContext);

    PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper<> request;
    FillResolvePurchaseDisputeRequest(request);
    LogResolvePurchaseDisputeRequest(&request.Model(), "TestPlayerDataManagementAdminResolvePurchaseDispute");
    HRESULT hr = PFPlayerDataManagementAdminResolvePurchaseDisputeAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminResolvePurchaseDisputeAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminUpdatePlayerStatisticDefinition

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdatePlayerStatisticDefinition(TestContext& testContext)
{
    struct AdminUpdatePlayerStatisticDefinitionResultHolder : public UpdatePlayerStatisticDefinitionResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminUpdatePlayerStatisticDefinitionGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminUpdatePlayerStatisticDefinitionGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementUpdatePlayerStatisticDefinitionResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdatePlayerStatisticDefinitionResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdatePlayerStatisticDefinitionResultHolder>>(testContext);

    PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper<> request;
    FillUpdatePlayerStatisticDefinitionRequest(request);
    LogUpdatePlayerStatisticDefinitionRequest(&request.Model(), "TestPlayerDataManagementAdminUpdatePlayerStatisticDefinition");
    HRESULT hr = PFPlayerDataManagementAdminUpdatePlayerStatisticDefinitionAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminUpdatePlayerStatisticDefinitionAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminUpdateUserData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserData(TestContext& testContext)
{
    struct AdminUpdateUserDataResultHolder : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminUpdateUserDataGetResult(async, &result)));
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserDataResultHolder>>(testContext);

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

#pragma endregion

#pragma region AdminUpdateUserInternalData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserInternalData(TestContext& testContext)
{
    struct AdminUpdateUserInternalDataResultHolder : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminUpdateUserInternalDataGetResult(async, &result)));
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserInternalDataResultHolder>>(testContext);

    PFPlayerDataManagementUpdateUserInternalDataRequestWrapper<> request;
    FillUpdateUserInternalDataRequest(request);
    LogUpdateUserInternalDataRequest(&request.Model(), "TestPlayerDataManagementAdminUpdateUserInternalData");
    HRESULT hr = PFPlayerDataManagementAdminUpdateUserInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminUpdateUserInternalDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminUpdateUserPublisherData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserPublisherData(TestContext& testContext)
{
    struct AdminUpdateUserPublisherDataResultHolder : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminUpdateUserPublisherDataGetResult(async, &result)));
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserPublisherDataResultHolder>>(testContext);

    PFPlayerDataManagementAdminUpdateUserDataRequestWrapper<> request;
    FillAdminUpdateUserDataRequest(request);
    LogAdminUpdateUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminUpdateUserPublisherData");
    HRESULT hr = PFPlayerDataManagementAdminUpdateUserPublisherDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminUpdateUserPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminUpdateUserPublisherInternalData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserPublisherInternalData(TestContext& testContext)
{
    struct AdminUpdateUserPublisherInternalDataResultHolder : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminUpdateUserPublisherInternalDataGetResult(async, &result)));
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserPublisherInternalDataResultHolder>>(testContext);

    PFPlayerDataManagementUpdateUserInternalDataRequestWrapper<> request;
    FillUpdateUserInternalDataRequest(request);
    LogUpdateUserInternalDataRequest(&request.Model(), "TestPlayerDataManagementAdminUpdateUserPublisherInternalData");
    HRESULT hr = PFPlayerDataManagementAdminUpdateUserPublisherInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminUpdateUserPublisherInternalDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminUpdateUserPublisherReadOnlyData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserPublisherReadOnlyData(TestContext& testContext)
{
    struct AdminUpdateUserPublisherReadOnlyDataResultHolder : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminUpdateUserPublisherReadOnlyDataGetResult(async, &result)));
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserPublisherReadOnlyDataResultHolder>>(testContext);

    PFPlayerDataManagementAdminUpdateUserDataRequestWrapper<> request;
    FillAdminUpdateUserDataRequest(request);
    LogAdminUpdateUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminUpdateUserPublisherReadOnlyData");
    HRESULT hr = PFPlayerDataManagementAdminUpdateUserPublisherReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminUpdateUserPublisherReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region AdminUpdateUserReadOnlyData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserReadOnlyData(TestContext& testContext)
{
    struct AdminUpdateUserReadOnlyDataResultHolder : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementAdminUpdateUserReadOnlyDataGetResult(async, &result)));
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserReadOnlyDataResultHolder>>(testContext);

    PFPlayerDataManagementAdminUpdateUserDataRequestWrapper<> request;
    FillAdminUpdateUserDataRequest(request);
    LogAdminUpdateUserDataRequest(&request.Model(), "TestPlayerDataManagementAdminUpdateUserReadOnlyData");
    HRESULT hr = PFPlayerDataManagementAdminUpdateUserReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminUpdateUserReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetFriendLeaderboard

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetFriendLeaderboard(TestContext& testContext)
{
    struct ClientGetFriendLeaderboardResultHolder : public GetLeaderboardResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetFriendLeaderboardGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetFriendLeaderboardGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementGetLeaderboardResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementGetLeaderboardResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetFriendLeaderboardResultHolder>>(testContext);

    PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper<> request;
    FillClientGetFriendLeaderboardRequest(request);
    LogClientGetFriendLeaderboardRequest(&request.Model(), "TestPlayerDataManagementClientGetFriendLeaderboard");
    HRESULT hr = PFPlayerDataManagementClientGetFriendLeaderboardAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementClientGetFriendLeaderboardAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetFriendLeaderboardAroundPlayer

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetFriendLeaderboardAroundPlayer(TestContext& testContext)
{
    struct ClientGetFriendLeaderboardAroundPlayerResultHolder : public GetFriendLeaderboardAroundPlayerResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetFriendLeaderboardAroundPlayerGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetFriendLeaderboardAroundPlayerGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetFriendLeaderboardAroundPlayerResultHolder>>(testContext);

    PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper<> request;
    FillGetFriendLeaderboardAroundPlayerRequest(request);
    LogGetFriendLeaderboardAroundPlayerRequest(&request.Model(), "TestPlayerDataManagementClientGetFriendLeaderboardAroundPlayer");
    HRESULT hr = PFPlayerDataManagementClientGetFriendLeaderboardAroundPlayerAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementClientGetFriendLeaderboardAroundPlayerAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetLeaderboard

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetLeaderboard(TestContext& testContext)
{
    struct ClientGetLeaderboardResultHolder : public GetLeaderboardResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetLeaderboardGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetLeaderboardGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementGetLeaderboardResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementGetLeaderboardResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetLeaderboardResultHolder>>(testContext);

    PFPlayerDataManagementGetLeaderboardRequestWrapper<> request;
    FillGetLeaderboardRequest(request);
    LogGetLeaderboardRequest(&request.Model(), "TestPlayerDataManagementClientGetLeaderboard");
    HRESULT hr = PFPlayerDataManagementClientGetLeaderboardAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementClientGetLeaderboardAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetLeaderboardAroundPlayer

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetLeaderboardAroundPlayer(TestContext& testContext)
{
    struct ClientGetLeaderboardAroundPlayerResultHolder : public GetLeaderboardAroundPlayerResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetLeaderboardAroundPlayerGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetLeaderboardAroundPlayerGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementGetLeaderboardAroundPlayerResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementGetLeaderboardAroundPlayerResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetLeaderboardAroundPlayerResultHolder>>(testContext);

    PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper<> request;
    FillGetLeaderboardAroundPlayerRequest(request);
    LogGetLeaderboardAroundPlayerRequest(&request.Model(), "TestPlayerDataManagementClientGetLeaderboardAroundPlayer");
    HRESULT hr = PFPlayerDataManagementClientGetLeaderboardAroundPlayerAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementClientGetLeaderboardAroundPlayerAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayerStatistics

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetPlayerStatistics(TestContext& testContext)
{
    struct ClientGetPlayerStatisticsResultHolder : public ClientGetPlayerStatisticsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetPlayerStatisticsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetPlayerStatisticsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementClientGetPlayerStatisticsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementClientGetPlayerStatisticsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayerStatisticsResultHolder>>(testContext);

    PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper<> request;
    FillClientGetPlayerStatisticsRequest(request);
    LogClientGetPlayerStatisticsRequest(&request.Model(), "TestPlayerDataManagementClientGetPlayerStatistics");
    HRESULT hr = PFPlayerDataManagementClientGetPlayerStatisticsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementClientGetPlayerStatisticsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayerStatisticVersions

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetPlayerStatisticVersions(TestContext& testContext)
{
    struct ClientGetPlayerStatisticVersionsResultHolder : public GetPlayerStatisticVersionsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetPlayerStatisticVersionsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetPlayerStatisticVersionsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementGetPlayerStatisticVersionsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementGetPlayerStatisticVersionsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayerStatisticVersionsResultHolder>>(testContext);

    PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper<> request;
    FillGetPlayerStatisticVersionsRequest(request);
    LogGetPlayerStatisticVersionsRequest(&request.Model(), "TestPlayerDataManagementClientGetPlayerStatisticVersions");
    HRESULT hr = PFPlayerDataManagementClientGetPlayerStatisticVersionsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementClientGetPlayerStatisticVersionsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetUserData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetUserData(TestContext& testContext)
{
    struct ClientGetUserDataResultHolder : public ClientGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetUserDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetUserDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementClientGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementClientGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetUserDataResultHolder>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillGetUserDataRequest(request);
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
    struct ClientGetUserPublisherDataResultHolder : public ClientGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetUserPublisherDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetUserPublisherDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementClientGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementClientGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetUserPublisherDataResultHolder>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillGetUserDataRequest(request);
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
    struct ClientGetUserPublisherReadOnlyDataResultHolder : public ClientGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetUserPublisherReadOnlyDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetUserPublisherReadOnlyDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementClientGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementClientGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetUserPublisherReadOnlyDataResultHolder>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillGetUserDataRequest(request);
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
    struct ClientGetUserReadOnlyDataResultHolder : public ClientGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetUserReadOnlyDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientGetUserReadOnlyDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementClientGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementClientGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetUserReadOnlyDataResultHolder>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillGetUserDataRequest(request);
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

#pragma region ClientUpdatePlayerStatistics

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientUpdatePlayerStatistics(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper<> request;
    FillClientUpdatePlayerStatisticsRequest(request);
    LogClientUpdatePlayerStatisticsRequest(&request.Model(), "TestPlayerDataManagementClientUpdatePlayerStatistics");
    HRESULT hr = PFPlayerDataManagementClientUpdatePlayerStatisticsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementClientUpdatePlayerStatisticsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientUpdateUserData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientUpdateUserData(TestContext& testContext)
{
    struct ClientUpdateUserDataResultHolder : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientUpdateUserDataGetResult(async, &result)));
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientUpdateUserDataResultHolder>>(testContext);

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
    struct ClientUpdateUserPublisherDataResultHolder : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementClientUpdateUserPublisherDataGetResult(async, &result)));
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientUpdateUserPublisherDataResultHolder>>(testContext);

    PFPlayerDataManagementClientUpdateUserDataRequestWrapper<> request;
    FillClientUpdateUserDataRequest(request);
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

#pragma region ServerGetFriendLeaderboard

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetFriendLeaderboard(TestContext& testContext)
{
    struct ServerGetFriendLeaderboardResultHolder : public GetLeaderboardResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetFriendLeaderboardGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetFriendLeaderboardGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementGetLeaderboardResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementGetLeaderboardResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetFriendLeaderboardResultHolder>>(testContext);

    PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper<> request;
    FillServerGetFriendLeaderboardRequest(request);
    LogServerGetFriendLeaderboardRequest(&request.Model(), "TestPlayerDataManagementServerGetFriendLeaderboard");
    HRESULT hr = PFPlayerDataManagementServerGetFriendLeaderboardAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetFriendLeaderboardAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetLeaderboard

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetLeaderboard(TestContext& testContext)
{
    struct ServerGetLeaderboardResultHolder : public GetLeaderboardResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetLeaderboardGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetLeaderboardGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementGetLeaderboardResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementGetLeaderboardResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetLeaderboardResultHolder>>(testContext);

    PFPlayerDataManagementGetLeaderboardRequestWrapper<> request;
    FillGetLeaderboardRequest(request);
    LogGetLeaderboardRequest(&request.Model(), "TestPlayerDataManagementServerGetLeaderboard");
    HRESULT hr = PFPlayerDataManagementServerGetLeaderboardAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetLeaderboardAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetLeaderboardAroundUser

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetLeaderboardAroundUser(TestContext& testContext)
{
    struct ServerGetLeaderboardAroundUserResultHolder : public GetLeaderboardAroundUserResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetLeaderboardAroundUserGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetLeaderboardAroundUserGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementGetLeaderboardAroundUserResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementGetLeaderboardAroundUserResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetLeaderboardAroundUserResultHolder>>(testContext);

    PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper<> request;
    FillGetLeaderboardAroundUserRequest(request);
    LogGetLeaderboardAroundUserRequest(&request.Model(), "TestPlayerDataManagementServerGetLeaderboardAroundUser");
    HRESULT hr = PFPlayerDataManagementServerGetLeaderboardAroundUserAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetLeaderboardAroundUserAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetPlayerCombinedInfo

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetPlayerCombinedInfo(TestContext& testContext)
{
    struct ServerGetPlayerCombinedInfoResultHolder : public GetPlayerCombinedInfoResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetPlayerCombinedInfoGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetPlayerCombinedInfoGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGetPlayerCombinedInfoResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGetPlayerCombinedInfoResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayerCombinedInfoResultHolder>>(testContext);

    PFGetPlayerCombinedInfoRequestWrapper<> request;
    FillGetPlayerCombinedInfoRequest(request);
    LogGetPlayerCombinedInfoRequest(&request.Model(), "TestPlayerDataManagementServerGetPlayerCombinedInfo");
    HRESULT hr = PFPlayerDataManagementServerGetPlayerCombinedInfoAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetPlayerCombinedInfoAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetPlayerStatistics

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetPlayerStatistics(TestContext& testContext)
{
    struct ServerGetPlayerStatisticsResultHolder : public ServerGetPlayerStatisticsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetPlayerStatisticsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetPlayerStatisticsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementServerGetPlayerStatisticsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementServerGetPlayerStatisticsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayerStatisticsResultHolder>>(testContext);

    PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper<> request;
    FillServerGetPlayerStatisticsRequest(request);
    LogServerGetPlayerStatisticsRequest(&request.Model(), "TestPlayerDataManagementServerGetPlayerStatistics");
    HRESULT hr = PFPlayerDataManagementServerGetPlayerStatisticsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetPlayerStatisticsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetPlayerStatisticVersions

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetPlayerStatisticVersions(TestContext& testContext)
{
    struct ServerGetPlayerStatisticVersionsResultHolder : public GetPlayerStatisticVersionsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetPlayerStatisticVersionsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetPlayerStatisticVersionsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementGetPlayerStatisticVersionsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementGetPlayerStatisticVersionsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayerStatisticVersionsResultHolder>>(testContext);

    PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper<> request;
    FillGetPlayerStatisticVersionsRequest(request);
    LogGetPlayerStatisticVersionsRequest(&request.Model(), "TestPlayerDataManagementServerGetPlayerStatisticVersions");
    HRESULT hr = PFPlayerDataManagementServerGetPlayerStatisticVersionsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetPlayerStatisticVersionsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetUserData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserData(TestContext& testContext)
{
    struct ServerGetUserDataResultHolder : public ServerGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementServerGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserDataResultHolder>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillGetUserDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementServerGetUserData");
    HRESULT hr = PFPlayerDataManagementServerGetUserDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetUserDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetUserInternalData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserInternalData(TestContext& testContext)
{
    struct ServerGetUserInternalDataResultHolder : public ServerGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserInternalDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserInternalDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementServerGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserInternalDataResultHolder>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillGetUserDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementServerGetUserInternalData");
    HRESULT hr = PFPlayerDataManagementServerGetUserInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetUserInternalDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetUserPublisherData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserPublisherData(TestContext& testContext)
{
    struct ServerGetUserPublisherDataResultHolder : public ServerGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserPublisherDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserPublisherDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementServerGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserPublisherDataResultHolder>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillGetUserDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementServerGetUserPublisherData");
    HRESULT hr = PFPlayerDataManagementServerGetUserPublisherDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetUserPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetUserPublisherInternalData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserPublisherInternalData(TestContext& testContext)
{
    struct ServerGetUserPublisherInternalDataResultHolder : public ServerGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserPublisherInternalDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserPublisherInternalDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementServerGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserPublisherInternalDataResultHolder>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillGetUserDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementServerGetUserPublisherInternalData");
    HRESULT hr = PFPlayerDataManagementServerGetUserPublisherInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetUserPublisherInternalDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetUserPublisherReadOnlyData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserPublisherReadOnlyData(TestContext& testContext)
{
    struct ServerGetUserPublisherReadOnlyDataResultHolder : public ServerGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserPublisherReadOnlyDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserPublisherReadOnlyDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementServerGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserPublisherReadOnlyDataResultHolder>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillGetUserDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementServerGetUserPublisherReadOnlyData");
    HRESULT hr = PFPlayerDataManagementServerGetUserPublisherReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetUserPublisherReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetUserReadOnlyData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserReadOnlyData(TestContext& testContext)
{
    struct ServerGetUserReadOnlyDataResultHolder : public ServerGetUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserReadOnlyDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerGetUserReadOnlyDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFPlayerDataManagementServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementServerGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserReadOnlyDataResultHolder>>(testContext);

    PFPlayerDataManagementGetUserDataRequestWrapper<> request;
    FillGetUserDataRequest(request);
    LogGetUserDataRequest(&request.Model(), "TestPlayerDataManagementServerGetUserReadOnlyData");
    HRESULT hr = PFPlayerDataManagementServerGetUserReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerGetUserReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerUpdatePlayerStatistics

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdatePlayerStatistics(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper<> request;
    FillServerUpdatePlayerStatisticsRequest(request);
    LogServerUpdatePlayerStatisticsRequest(&request.Model(), "TestPlayerDataManagementServerUpdatePlayerStatistics");
    HRESULT hr = PFPlayerDataManagementServerUpdatePlayerStatisticsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerUpdatePlayerStatisticsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerUpdateUserData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserData(TestContext& testContext)
{
    struct ServerUpdateUserDataResultHolder : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerUpdateUserDataGetResult(async, &result)));
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateUserDataResultHolder>>(testContext);

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

#pragma endregion

#pragma region ServerUpdateUserInternalData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserInternalData(TestContext& testContext)
{
    struct ServerUpdateUserInternalDataResultHolder : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerUpdateUserInternalDataGetResult(async, &result)));
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateUserInternalDataResultHolder>>(testContext);

    PFPlayerDataManagementUpdateUserInternalDataRequestWrapper<> request;
    FillUpdateUserInternalDataRequest(request);
    LogUpdateUserInternalDataRequest(&request.Model(), "TestPlayerDataManagementServerUpdateUserInternalData");
    HRESULT hr = PFPlayerDataManagementServerUpdateUserInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerUpdateUserInternalDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerUpdateUserPublisherData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserPublisherData(TestContext& testContext)
{
    struct ServerUpdateUserPublisherDataResultHolder : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerUpdateUserPublisherDataGetResult(async, &result)));
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateUserPublisherDataResultHolder>>(testContext);

    PFPlayerDataManagementServerUpdateUserDataRequestWrapper<> request;
    FillServerUpdateUserDataRequest(request);
    LogServerUpdateUserDataRequest(&request.Model(), "TestPlayerDataManagementServerUpdateUserPublisherData");
    HRESULT hr = PFPlayerDataManagementServerUpdateUserPublisherDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerUpdateUserPublisherDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerUpdateUserPublisherInternalData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserPublisherInternalData(TestContext& testContext)
{
    struct ServerUpdateUserPublisherInternalDataResultHolder : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerUpdateUserPublisherInternalDataGetResult(async, &result)));
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateUserPublisherInternalDataResultHolder>>(testContext);

    PFPlayerDataManagementUpdateUserInternalDataRequestWrapper<> request;
    FillUpdateUserInternalDataRequest(request);
    LogUpdateUserInternalDataRequest(&request.Model(), "TestPlayerDataManagementServerUpdateUserPublisherInternalData");
    HRESULT hr = PFPlayerDataManagementServerUpdateUserPublisherInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerUpdateUserPublisherInternalDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerUpdateUserPublisherReadOnlyData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserPublisherReadOnlyData(TestContext& testContext)
{
    struct ServerUpdateUserPublisherReadOnlyDataResultHolder : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerUpdateUserPublisherReadOnlyDataGetResult(async, &result)));
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateUserPublisherReadOnlyDataResultHolder>>(testContext);

    PFPlayerDataManagementServerUpdateUserDataRequestWrapper<> request;
    FillServerUpdateUserDataRequest(request);
    LogServerUpdateUserDataRequest(&request.Model(), "TestPlayerDataManagementServerUpdateUserPublisherReadOnlyData");
    HRESULT hr = PFPlayerDataManagementServerUpdateUserPublisherReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerUpdateUserPublisherReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerUpdateUserReadOnlyData

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserReadOnlyData(TestContext& testContext)
{
    struct ServerUpdateUserReadOnlyDataResultHolder : public UpdateUserDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFPlayerDataManagementServerUpdateUserReadOnlyDataGetResult(async, &result)));
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateUserReadOnlyDataResultHolder>>(testContext);

    PFPlayerDataManagementServerUpdateUserDataRequestWrapper<> request;
    FillServerUpdateUserDataRequest(request);
    LogServerUpdateUserDataRequest(&request.Model(), "TestPlayerDataManagementServerUpdateUserReadOnlyData");
    HRESULT hr = PFPlayerDataManagementServerUpdateUserReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementServerUpdateUserReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
