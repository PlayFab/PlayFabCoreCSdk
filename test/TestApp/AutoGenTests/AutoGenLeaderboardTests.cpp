#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenLeaderboardTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenLeaderboardTests::LeaderboardTestData AutoGenLeaderboardTests::testData;

void AutoGenLeaderboardTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenLeaderboardTests::LogHR(HRESULT hr)
{
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenLeaderboardTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestLeaderboardAdminCreatePlayerStatisticDefinition", &AutoGenLeaderboardTests::TestLeaderboardAdminCreatePlayerStatisticDefinition);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestLeaderboardAdminGetPlayerStatisticDefinitions", &AutoGenLeaderboardTests::TestLeaderboardAdminGetPlayerStatisticDefinitions);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestLeaderboardAdminGetPlayerStatisticVersions", &AutoGenLeaderboardTests::TestLeaderboardAdminGetPlayerStatisticVersions);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestLeaderboardAdminIncrementPlayerStatisticVersion", &AutoGenLeaderboardTests::TestLeaderboardAdminIncrementPlayerStatisticVersion);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestLeaderboardAdminResetUserStatistics", &AutoGenLeaderboardTests::TestLeaderboardAdminResetUserStatistics);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestLeaderboardAdminUpdatePlayerStatisticDefinition", &AutoGenLeaderboardTests::TestLeaderboardAdminUpdatePlayerStatisticDefinition);
#endif

    AddTest("TestLeaderboardClientGetFriendLeaderboard", &AutoGenLeaderboardTests::TestLeaderboardClientGetFriendLeaderboard);

    AddTest("TestLeaderboardClientGetFriendLeaderboardAroundPlayer", &AutoGenLeaderboardTests::TestLeaderboardClientGetFriendLeaderboardAroundPlayer);

    AddTest("TestLeaderboardClientGetLeaderboard", &AutoGenLeaderboardTests::TestLeaderboardClientGetLeaderboard);

    AddTest("TestLeaderboardClientGetLeaderboardAroundPlayer", &AutoGenLeaderboardTests::TestLeaderboardClientGetLeaderboardAroundPlayer);

    AddTest("TestLeaderboardClientGetPlayerStatistics", &AutoGenLeaderboardTests::TestLeaderboardClientGetPlayerStatistics);

    AddTest("TestLeaderboardClientGetPlayerStatisticVersions", &AutoGenLeaderboardTests::TestLeaderboardClientGetPlayerStatisticVersions);

    AddTest("TestLeaderboardClientUpdatePlayerStatistics", &AutoGenLeaderboardTests::TestLeaderboardClientUpdatePlayerStatistics);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestLeaderboardServerGetFriendLeaderboard", &AutoGenLeaderboardTests::TestLeaderboardServerGetFriendLeaderboard);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestLeaderboardServerGetLeaderboard", &AutoGenLeaderboardTests::TestLeaderboardServerGetLeaderboard);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestLeaderboardServerGetLeaderboardAroundUser", &AutoGenLeaderboardTests::TestLeaderboardServerGetLeaderboardAroundUser);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestLeaderboardServerGetPlayerStatistics", &AutoGenLeaderboardTests::TestLeaderboardServerGetPlayerStatistics);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestLeaderboardServerGetPlayerStatisticVersions", &AutoGenLeaderboardTests::TestLeaderboardServerGetPlayerStatisticVersions);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestLeaderboardServerUpdatePlayerStatistics", &AutoGenLeaderboardTests::TestLeaderboardServerUpdatePlayerStatistics);
#endif
}

void AutoGenLeaderboardTests::ClassSetUp()
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

void AutoGenLeaderboardTests::ClassTearDown()
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

void AutoGenLeaderboardTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AdminCreatePlayerStatisticDefinition

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenLeaderboardTests::TestLeaderboardAdminCreatePlayerStatisticDefinition(TestContext& testContext)
{
    struct AdminCreatePlayerStatisticDefinitionResultHolderStruct : public CreatePlayerStatisticDefinitionResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLeaderboardAdminCreatePlayerStatisticDefinitionGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLeaderboardAdminCreatePlayerStatisticDefinitionGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogCreatePlayerStatisticDefinitionResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminCreatePlayerStatisticDefinitionResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminCreatePlayerStatisticDefinitionResultHolderStruct>>(testContext);

    PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper<> request;
    FillAdminCreatePlayerStatisticDefinitionRequest(request);
    LogCreatePlayerStatisticDefinitionRequest(&request.Model(), "TestLeaderboardAdminCreatePlayerStatisticDefinition");
    HRESULT hr = PFLeaderboardAdminCreatePlayerStatisticDefinitionAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardAdminCreatePlayerStatisticDefinitionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetPlayerStatisticDefinitions

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenLeaderboardTests::TestLeaderboardAdminGetPlayerStatisticDefinitions(TestContext& testContext)
{
    struct AdminGetPlayerStatisticDefinitionsResultHolderStruct : public GetPlayerStatisticDefinitionsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLeaderboardAdminGetPlayerStatisticDefinitionsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLeaderboardAdminGetPlayerStatisticDefinitionsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetPlayerStatisticDefinitionsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetPlayerStatisticDefinitionsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetPlayerStatisticDefinitionsResultHolderStruct>>(testContext);

    HRESULT hr = PFLeaderboardAdminGetPlayerStatisticDefinitionsAsync(stateHandle, &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardAdminGetPlayerStatisticDefinitionsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminGetPlayerStatisticVersions

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenLeaderboardTests::TestLeaderboardAdminGetPlayerStatisticVersions(TestContext& testContext)
{
    struct AdminGetPlayerStatisticVersionsResultHolderStruct : public GetPlayerStatisticVersionsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLeaderboardAdminGetPlayerStatisticVersionsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLeaderboardAdminGetPlayerStatisticVersionsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetPlayerStatisticVersionsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminGetPlayerStatisticVersionsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminGetPlayerStatisticVersionsResultHolderStruct>>(testContext);

    PFLeaderboardGetPlayerStatisticVersionsRequestWrapper<> request;
    FillAdminGetPlayerStatisticVersionsRequest(request);
    LogGetPlayerStatisticVersionsRequest(&request.Model(), "TestLeaderboardAdminGetPlayerStatisticVersions");
    HRESULT hr = PFLeaderboardAdminGetPlayerStatisticVersionsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardAdminGetPlayerStatisticVersionsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminIncrementPlayerStatisticVersion

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenLeaderboardTests::TestLeaderboardAdminIncrementPlayerStatisticVersion(TestContext& testContext)
{
    struct AdminIncrementPlayerStatisticVersionResultHolderStruct : public IncrementPlayerStatisticVersionResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLeaderboardAdminIncrementPlayerStatisticVersionGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLeaderboardAdminIncrementPlayerStatisticVersionGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogIncrementPlayerStatisticVersionResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminIncrementPlayerStatisticVersionResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminIncrementPlayerStatisticVersionResultHolderStruct>>(testContext);

    PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper<> request;
    FillAdminIncrementPlayerStatisticVersionRequest(request);
    LogIncrementPlayerStatisticVersionRequest(&request.Model(), "TestLeaderboardAdminIncrementPlayerStatisticVersion");
    HRESULT hr = PFLeaderboardAdminIncrementPlayerStatisticVersionAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardAdminIncrementPlayerStatisticVersionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminResetUserStatistics

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenLeaderboardTests::TestLeaderboardAdminResetUserStatistics(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFLeaderboardResetUserStatisticsRequestWrapper<> request;
    FillAdminResetUserStatisticsRequest(request);
    LogResetUserStatisticsRequest(&request.Model(), "TestLeaderboardAdminResetUserStatistics");
    HRESULT hr = PFLeaderboardAdminResetUserStatisticsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardAdminResetUserStatisticsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region AdminUpdatePlayerStatisticDefinition

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenLeaderboardTests::TestLeaderboardAdminUpdatePlayerStatisticDefinition(TestContext& testContext)
{
    struct AdminUpdatePlayerStatisticDefinitionResultHolderStruct : public UpdatePlayerStatisticDefinitionResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLeaderboardAdminUpdatePlayerStatisticDefinitionGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLeaderboardAdminUpdatePlayerStatisticDefinitionGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogUpdatePlayerStatisticDefinitionResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateAdminUpdatePlayerStatisticDefinitionResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<AdminUpdatePlayerStatisticDefinitionResultHolderStruct>>(testContext);

    PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper<> request;
    FillAdminUpdatePlayerStatisticDefinitionRequest(request);
    LogUpdatePlayerStatisticDefinitionRequest(&request.Model(), "TestLeaderboardAdminUpdatePlayerStatisticDefinition");
    HRESULT hr = PFLeaderboardAdminUpdatePlayerStatisticDefinitionAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardAdminUpdatePlayerStatisticDefinitionAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientGetFriendLeaderboard

void AutoGenLeaderboardTests::TestLeaderboardClientGetFriendLeaderboard(TestContext& testContext)
{
    struct ClientGetFriendLeaderboardResultHolderStruct : public GetLeaderboardResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLeaderboardClientGetFriendLeaderboardGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLeaderboardClientGetFriendLeaderboardGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetLeaderboardResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetFriendLeaderboardResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetFriendLeaderboardResultHolderStruct>>(testContext);

    PFLeaderboardClientGetFriendLeaderboardRequestWrapper<> request;
    FillClientGetFriendLeaderboardRequest(request);
    LogClientGetFriendLeaderboardRequest(&request.Model(), "TestLeaderboardClientGetFriendLeaderboard");
    HRESULT hr = PFLeaderboardClientGetFriendLeaderboardAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardClientGetFriendLeaderboardAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetFriendLeaderboardAroundPlayer

void AutoGenLeaderboardTests::TestLeaderboardClientGetFriendLeaderboardAroundPlayer(TestContext& testContext)
{
    struct ClientGetFriendLeaderboardAroundPlayerResultHolderStruct : public GetFriendLeaderboardAroundPlayerResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLeaderboardClientGetFriendLeaderboardAroundPlayerGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLeaderboardClientGetFriendLeaderboardAroundPlayerGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetFriendLeaderboardAroundPlayerResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetFriendLeaderboardAroundPlayerResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetFriendLeaderboardAroundPlayerResultHolderStruct>>(testContext);

    PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper<> request;
    FillClientGetFriendLeaderboardAroundPlayerRequest(request);
    LogGetFriendLeaderboardAroundPlayerRequest(&request.Model(), "TestLeaderboardClientGetFriendLeaderboardAroundPlayer");
    HRESULT hr = PFLeaderboardClientGetFriendLeaderboardAroundPlayerAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardClientGetFriendLeaderboardAroundPlayerAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetLeaderboard

void AutoGenLeaderboardTests::TestLeaderboardClientGetLeaderboard(TestContext& testContext)
{
    struct ClientGetLeaderboardResultHolderStruct : public GetLeaderboardResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLeaderboardClientGetLeaderboardGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLeaderboardClientGetLeaderboardGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetLeaderboardResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetLeaderboardResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetLeaderboardResultHolderStruct>>(testContext);

    PFLeaderboardGetLeaderboardRequestWrapper<> request;
    FillClientGetLeaderboardRequest(request);
    LogGetLeaderboardRequest(&request.Model(), "TestLeaderboardClientGetLeaderboard");
    HRESULT hr = PFLeaderboardClientGetLeaderboardAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardClientGetLeaderboardAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetLeaderboardAroundPlayer

void AutoGenLeaderboardTests::TestLeaderboardClientGetLeaderboardAroundPlayer(TestContext& testContext)
{
    struct ClientGetLeaderboardAroundPlayerResultHolderStruct : public GetLeaderboardAroundPlayerResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLeaderboardClientGetLeaderboardAroundPlayerGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLeaderboardClientGetLeaderboardAroundPlayerGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetLeaderboardAroundPlayerResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetLeaderboardAroundPlayerResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetLeaderboardAroundPlayerResultHolderStruct>>(testContext);

    PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper<> request;
    FillClientGetLeaderboardAroundPlayerRequest(request);
    LogGetLeaderboardAroundPlayerRequest(&request.Model(), "TestLeaderboardClientGetLeaderboardAroundPlayer");
    HRESULT hr = PFLeaderboardClientGetLeaderboardAroundPlayerAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardClientGetLeaderboardAroundPlayerAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayerStatistics

void AutoGenLeaderboardTests::TestLeaderboardClientGetPlayerStatistics(TestContext& testContext)
{
    struct ClientGetPlayerStatisticsResultHolderStruct : public ClientGetPlayerStatisticsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLeaderboardClientGetPlayerStatisticsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLeaderboardClientGetPlayerStatisticsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogClientGetPlayerStatisticsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetPlayerStatisticsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayerStatisticsResultHolderStruct>>(testContext);

    PFLeaderboardClientGetPlayerStatisticsRequestWrapper<> request;
    FillClientGetPlayerStatisticsRequest(request);
    LogClientGetPlayerStatisticsRequest(&request.Model(), "TestLeaderboardClientGetPlayerStatistics");
    HRESULT hr = PFLeaderboardClientGetPlayerStatisticsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardClientGetPlayerStatisticsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetPlayerStatisticVersions

void AutoGenLeaderboardTests::TestLeaderboardClientGetPlayerStatisticVersions(TestContext& testContext)
{
    struct ClientGetPlayerStatisticVersionsResultHolderStruct : public GetPlayerStatisticVersionsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLeaderboardClientGetPlayerStatisticVersionsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLeaderboardClientGetPlayerStatisticVersionsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetPlayerStatisticVersionsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetPlayerStatisticVersionsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetPlayerStatisticVersionsResultHolderStruct>>(testContext);

    PFLeaderboardGetPlayerStatisticVersionsRequestWrapper<> request;
    FillClientGetPlayerStatisticVersionsRequest(request);
    LogGetPlayerStatisticVersionsRequest(&request.Model(), "TestLeaderboardClientGetPlayerStatisticVersions");
    HRESULT hr = PFLeaderboardClientGetPlayerStatisticVersionsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardClientGetPlayerStatisticVersionsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientUpdatePlayerStatistics

void AutoGenLeaderboardTests::TestLeaderboardClientUpdatePlayerStatistics(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper<> request;
    FillClientUpdatePlayerStatisticsRequest(request);
    LogClientUpdatePlayerStatisticsRequest(&request.Model(), "TestLeaderboardClientUpdatePlayerStatistics");
    HRESULT hr = PFLeaderboardClientUpdatePlayerStatisticsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardClientUpdatePlayerStatisticsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetFriendLeaderboard

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenLeaderboardTests::TestLeaderboardServerGetFriendLeaderboard(TestContext& testContext)
{
    struct ServerGetFriendLeaderboardResultHolderStruct : public GetLeaderboardResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLeaderboardServerGetFriendLeaderboardGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLeaderboardServerGetFriendLeaderboardGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetLeaderboardResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetFriendLeaderboardResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetFriendLeaderboardResultHolderStruct>>(testContext);

    PFLeaderboardServerGetFriendLeaderboardRequestWrapper<> request;
    FillServerGetFriendLeaderboardRequest(request);
    LogServerGetFriendLeaderboardRequest(&request.Model(), "TestLeaderboardServerGetFriendLeaderboard");
    HRESULT hr = PFLeaderboardServerGetFriendLeaderboardAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardServerGetFriendLeaderboardAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetLeaderboard

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenLeaderboardTests::TestLeaderboardServerGetLeaderboard(TestContext& testContext)
{
    struct ServerGetLeaderboardResultHolderStruct : public GetLeaderboardResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLeaderboardServerGetLeaderboardGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLeaderboardServerGetLeaderboardGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetLeaderboardResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetLeaderboardResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetLeaderboardResultHolderStruct>>(testContext);

    PFLeaderboardGetLeaderboardRequestWrapper<> request;
    FillServerGetLeaderboardRequest(request);
    LogGetLeaderboardRequest(&request.Model(), "TestLeaderboardServerGetLeaderboard");
    HRESULT hr = PFLeaderboardServerGetLeaderboardAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardServerGetLeaderboardAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetLeaderboardAroundUser

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenLeaderboardTests::TestLeaderboardServerGetLeaderboardAroundUser(TestContext& testContext)
{
    struct ServerGetLeaderboardAroundUserResultHolderStruct : public GetLeaderboardAroundUserResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLeaderboardServerGetLeaderboardAroundUserGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLeaderboardServerGetLeaderboardAroundUserGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetLeaderboardAroundUserResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetLeaderboardAroundUserResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetLeaderboardAroundUserResultHolderStruct>>(testContext);

    PFLeaderboardGetLeaderboardAroundUserRequestWrapper<> request;
    FillServerGetLeaderboardAroundUserRequest(request);
    LogGetLeaderboardAroundUserRequest(&request.Model(), "TestLeaderboardServerGetLeaderboardAroundUser");
    HRESULT hr = PFLeaderboardServerGetLeaderboardAroundUserAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardServerGetLeaderboardAroundUserAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetPlayerStatistics

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenLeaderboardTests::TestLeaderboardServerGetPlayerStatistics(TestContext& testContext)
{
    struct ServerGetPlayerStatisticsResultHolderStruct : public ServerGetPlayerStatisticsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLeaderboardServerGetPlayerStatisticsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLeaderboardServerGetPlayerStatisticsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerGetPlayerStatisticsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetPlayerStatisticsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayerStatisticsResultHolderStruct>>(testContext);

    PFLeaderboardServerGetPlayerStatisticsRequestWrapper<> request;
    FillServerGetPlayerStatisticsRequest(request);
    LogServerGetPlayerStatisticsRequest(&request.Model(), "TestLeaderboardServerGetPlayerStatistics");
    HRESULT hr = PFLeaderboardServerGetPlayerStatisticsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardServerGetPlayerStatisticsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetPlayerStatisticVersions

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenLeaderboardTests::TestLeaderboardServerGetPlayerStatisticVersions(TestContext& testContext)
{
    struct ServerGetPlayerStatisticVersionsResultHolderStruct : public GetPlayerStatisticVersionsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLeaderboardServerGetPlayerStatisticVersionsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLeaderboardServerGetPlayerStatisticVersionsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetPlayerStatisticVersionsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetPlayerStatisticVersionsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetPlayerStatisticVersionsResultHolderStruct>>(testContext);

    PFLeaderboardGetPlayerStatisticVersionsRequestWrapper<> request;
    FillServerGetPlayerStatisticVersionsRequest(request);
    LogGetPlayerStatisticVersionsRequest(&request.Model(), "TestLeaderboardServerGetPlayerStatisticVersions");
    HRESULT hr = PFLeaderboardServerGetPlayerStatisticVersionsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardServerGetPlayerStatisticVersionsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerUpdatePlayerStatistics

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenLeaderboardTests::TestLeaderboardServerUpdatePlayerStatistics(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper<> request;
    FillServerUpdatePlayerStatisticsRequest(request);
    LogServerUpdatePlayerStatisticsRequest(&request.Model(), "TestLeaderboardServerUpdatePlayerStatistics");
    HRESULT hr = PFLeaderboardServerUpdatePlayerStatisticsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLeaderboardLeaderboardServerUpdatePlayerStatisticsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
