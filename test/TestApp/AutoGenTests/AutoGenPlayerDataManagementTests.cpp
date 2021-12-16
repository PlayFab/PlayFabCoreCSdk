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
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminCreatePlayerStatisticDefinition", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminCreatePlayerStatisticDefinition);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminGetDataReport", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetDataReport);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminGetPlayerStatisticDefinitions", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetPlayerStatisticDefinitions);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminGetPlayerStatisticVersions", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetPlayerStatisticVersions);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminGetUserData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminGetUserInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserInternalData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminGetUserPublisherData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserPublisherData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminGetUserPublisherInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserPublisherInternalData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminGetUserPublisherReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserPublisherReadOnlyData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminGetUserReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetUserReadOnlyData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminIncrementPlayerStatisticVersion", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminIncrementPlayerStatisticVersion);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminRefundPurchase", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminRefundPurchase);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminResetUserStatistics", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminResetUserStatistics);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminResolvePurchaseDispute", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminResolvePurchaseDispute);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminUpdatePlayerStatisticDefinition", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdatePlayerStatisticDefinition);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminUpdateUserData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminUpdateUserInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserInternalData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminUpdateUserPublisherData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserPublisherData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminUpdateUserPublisherInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserPublisherInternalData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminUpdateUserPublisherReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserPublisherReadOnlyData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementAdminUpdateUserReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdateUserReadOnlyData);
#endif

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

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerGetFriendLeaderboard", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetFriendLeaderboard);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerGetLeaderboard", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetLeaderboard);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerGetLeaderboardAroundUser", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetLeaderboardAroundUser);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerGetPlayerCombinedInfo", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetPlayerCombinedInfo);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerGetPlayerStatistics", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetPlayerStatistics);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerGetPlayerStatisticVersions", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetPlayerStatisticVersions);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerGetUserData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerGetUserInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserInternalData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerGetUserPublisherData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserPublisherData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerGetUserPublisherInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserPublisherInternalData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerGetUserPublisherReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserPublisherReadOnlyData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerGetUserReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetUserReadOnlyData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerUpdatePlayerStatistics", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdatePlayerStatistics);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerUpdateUserData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerUpdateUserInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserInternalData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerUpdateUserPublisherData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserPublisherData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerUpdateUserPublisherInternalData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserPublisherInternalData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerUpdateUserPublisherReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserPublisherReadOnlyData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestPlayerDataManagementServerUpdateUserReadOnlyData", &AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerUpdateUserReadOnlyData);
#endif
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

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminCreatePlayerStatisticDefinition(TestContext& testContext)
{
    struct AdminCreatePlayerStatisticDefinitionResultHolderStruct : public CreatePlayerStatisticDefinitionResultHolder
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
    auto async = std::make_unique<XAsyncHelper<AdminCreatePlayerStatisticDefinitionResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

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
            
            LogPFPlayerDataManagementGetDataReportResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementGetDataReportResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetDataReportResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region AdminGetPlayerStatisticDefinitions

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetPlayerStatisticDefinitions(TestContext& testContext)
{
    struct AdminGetPlayerStatisticDefinitionsResultHolderStruct : public GetPlayerStatisticDefinitionsResultHolder
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
    auto async = std::make_unique<XAsyncHelper<AdminGetPlayerStatisticDefinitionsResultHolderStruct>>(testContext);

    HRESULT hr = PFPlayerDataManagementAdminGetPlayerStatisticDefinitionsAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFPlayerDataManagementPlayerDataManagementAdminGetPlayerStatisticDefinitionsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetPlayerStatisticVersions

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminGetPlayerStatisticVersions(TestContext& testContext)
{
    struct AdminGetPlayerStatisticVersionsResultHolderStruct : public GetPlayerStatisticVersionsResultHolder
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
    auto async = std::make_unique<XAsyncHelper<AdminGetPlayerStatisticVersionsResultHolderStruct>>(testContext);

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
            
            LogPFPlayerDataManagementAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementAdminGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserDataResultHolderStruct>>(testContext);

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
            
            LogPFPlayerDataManagementAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementAdminGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserInternalDataResultHolderStruct>>(testContext);

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
            
            LogPFPlayerDataManagementAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementAdminGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserPublisherDataResultHolderStruct>>(testContext);

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
            
            LogPFPlayerDataManagementAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementAdminGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserPublisherInternalDataResultHolderStruct>>(testContext);

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
            
            LogPFPlayerDataManagementAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementAdminGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserPublisherReadOnlyDataResultHolderStruct>>(testContext);

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
            
            LogPFPlayerDataManagementAdminGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementAdminGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetUserReadOnlyDataResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region AdminIncrementPlayerStatisticVersion

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminIncrementPlayerStatisticVersion(TestContext& testContext)
{
    struct AdminIncrementPlayerStatisticVersionResultHolderStruct : public IncrementPlayerStatisticVersionResultHolder
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
    auto async = std::make_unique<XAsyncHelper<AdminIncrementPlayerStatisticVersionResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region AdminRefundPurchase

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminRefundPurchase(TestContext& testContext)
{
    struct AdminRefundPurchaseResultHolderStruct : public RefundPurchaseResponseHolder
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
    auto async = std::make_unique<XAsyncHelper<AdminRefundPurchaseResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region AdminResetUserStatistics

#if HC_PLATFORM != HC_PLATFORM_GDK
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
#endif

#pragma endregion

#pragma region AdminResolvePurchaseDispute

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminResolvePurchaseDispute(TestContext& testContext)
{
    struct AdminResolvePurchaseDisputeResultHolderStruct : public ResolvePurchaseDisputeResponseHolder
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
    auto async = std::make_unique<XAsyncHelper<AdminResolvePurchaseDisputeResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region AdminUpdatePlayerStatisticDefinition

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementAdminUpdatePlayerStatisticDefinition(TestContext& testContext)
{
    struct AdminUpdatePlayerStatisticDefinitionResultHolderStruct : public UpdatePlayerStatisticDefinitionResultHolder
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
    auto async = std::make_unique<XAsyncHelper<AdminUpdatePlayerStatisticDefinitionResultHolderStruct>>(testContext);

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
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
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
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserInternalDataResultHolderStruct>>(testContext);

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
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserPublisherDataResultHolderStruct>>(testContext);

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
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserPublisherInternalDataResultHolderStruct>>(testContext);

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
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserPublisherReadOnlyDataResultHolderStruct>>(testContext);

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
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdateUserReadOnlyDataResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region ClientGetFriendLeaderboard

void AutoGenPlayerDataManagementTests::TestPlayerDataManagementClientGetFriendLeaderboard(TestContext& testContext)
{
    struct ClientGetFriendLeaderboardResultHolderStruct : public GetLeaderboardResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ClientGetFriendLeaderboardResultHolderStruct>>(testContext);

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
    struct ClientGetFriendLeaderboardAroundPlayerResultHolderStruct : public GetFriendLeaderboardAroundPlayerResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ClientGetFriendLeaderboardAroundPlayerResultHolderStruct>>(testContext);

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
    struct ClientGetLeaderboardResultHolderStruct : public GetLeaderboardResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ClientGetLeaderboardResultHolderStruct>>(testContext);

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
    struct ClientGetLeaderboardAroundPlayerResultHolderStruct : public GetLeaderboardAroundPlayerResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ClientGetLeaderboardAroundPlayerResultHolderStruct>>(testContext);

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
    struct ClientGetPlayerStatisticsResultHolderStruct : public ClientGetPlayerStatisticsResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayerStatisticsResultHolderStruct>>(testContext);

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
    struct ClientGetPlayerStatisticVersionsResultHolderStruct : public GetPlayerStatisticVersionsResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayerStatisticVersionsResultHolderStruct>>(testContext);

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
    struct ClientGetUserDataResultHolderStruct : public ClientGetUserDataResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ClientGetUserDataResultHolderStruct>>(testContext);

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
    struct ClientGetUserPublisherDataResultHolderStruct : public ClientGetUserDataResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ClientGetUserPublisherDataResultHolderStruct>>(testContext);

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
    struct ClientGetUserPublisherReadOnlyDataResultHolderStruct : public ClientGetUserDataResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ClientGetUserPublisherReadOnlyDataResultHolderStruct>>(testContext);

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
    struct ClientGetUserReadOnlyDataResultHolderStruct : public ClientGetUserDataResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ClientGetUserReadOnlyDataResultHolderStruct>>(testContext);

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
    struct ClientUpdateUserDataResultHolderStruct : public UpdateUserDataResultHolder
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
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientUpdateUserPublisherDataResultHolderStruct>>(testContext);

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

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetFriendLeaderboard(TestContext& testContext)
{
    struct ServerGetFriendLeaderboardResultHolderStruct : public GetLeaderboardResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ServerGetFriendLeaderboardResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region ServerGetLeaderboard

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetLeaderboard(TestContext& testContext)
{
    struct ServerGetLeaderboardResultHolderStruct : public GetLeaderboardResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ServerGetLeaderboardResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region ServerGetLeaderboardAroundUser

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetLeaderboardAroundUser(TestContext& testContext)
{
    struct ServerGetLeaderboardAroundUserResultHolderStruct : public GetLeaderboardAroundUserResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ServerGetLeaderboardAroundUserResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region ServerGetPlayerCombinedInfo

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetPlayerCombinedInfo(TestContext& testContext)
{
    struct ServerGetPlayerCombinedInfoResultHolderStruct : public GetPlayerCombinedInfoResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayerCombinedInfoResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region ServerGetPlayerStatistics

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetPlayerStatistics(TestContext& testContext)
{
    struct ServerGetPlayerStatisticsResultHolderStruct : public ServerGetPlayerStatisticsResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayerStatisticsResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region ServerGetPlayerStatisticVersions

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenPlayerDataManagementTests::TestPlayerDataManagementServerGetPlayerStatisticVersions(TestContext& testContext)
{
    struct ServerGetPlayerStatisticVersionsResultHolderStruct : public GetPlayerStatisticVersionsResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayerStatisticVersionsResultHolderStruct>>(testContext);

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
#endif

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
            
            LogPFPlayerDataManagementServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementServerGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserDataResultHolderStruct>>(testContext);

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
            
            LogPFPlayerDataManagementServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementServerGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserInternalDataResultHolderStruct>>(testContext);

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
            
            LogPFPlayerDataManagementServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementServerGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserPublisherDataResultHolderStruct>>(testContext);

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
            
            LogPFPlayerDataManagementServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementServerGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserPublisherInternalDataResultHolderStruct>>(testContext);

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
            
            LogPFPlayerDataManagementServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementServerGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserPublisherReadOnlyDataResultHolderStruct>>(testContext);

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
            
            LogPFPlayerDataManagementServerGetUserDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementServerGetUserDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetUserReadOnlyDataResultHolderStruct>>(testContext);

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
#endif

#pragma endregion

#pragma region ServerUpdatePlayerStatistics

#if HC_PLATFORM != HC_PLATFORM_GDK
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
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
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
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateUserInternalDataResultHolderStruct>>(testContext);

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
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateUserPublisherDataResultHolderStruct>>(testContext);

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
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateUserPublisherInternalDataResultHolderStruct>>(testContext);

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
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateUserPublisherReadOnlyDataResultHolderStruct>>(testContext);

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
            LogPFPlayerDataManagementUpdateUserDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFPlayerDataManagementUpdateUserDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateUserReadOnlyDataResultHolderStruct>>(testContext);

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
#endif

#pragma endregion


}
