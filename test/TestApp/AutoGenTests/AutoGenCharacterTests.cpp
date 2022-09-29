#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenCharacterTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenCharacterTests::CharacterTestData AutoGenCharacterTests::testData;

void AutoGenCharacterTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenCharacterTests::LogHR(HRESULT hr)
{
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenCharacterTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCharacterAdminResetCharacterStatistics", &AutoGenCharacterTests::TestCharacterAdminResetCharacterStatistics);
#endif

    AddTest("TestCharacterClientGetAllUsersCharacters", &AutoGenCharacterTests::TestCharacterClientGetAllUsersCharacters);

    AddTest("TestCharacterClientGetCharacterData", &AutoGenCharacterTests::TestCharacterClientGetCharacterData);

    AddTest("TestCharacterClientGetCharacterLeaderboard", &AutoGenCharacterTests::TestCharacterClientGetCharacterLeaderboard);

    AddTest("TestCharacterClientGetCharacterReadOnlyData", &AutoGenCharacterTests::TestCharacterClientGetCharacterReadOnlyData);

    AddTest("TestCharacterClientGetCharacterStatistics", &AutoGenCharacterTests::TestCharacterClientGetCharacterStatistics);

    AddTest("TestCharacterClientGetLeaderboardAroundCharacter", &AutoGenCharacterTests::TestCharacterClientGetLeaderboardAroundCharacter);

    AddTest("TestCharacterClientGetLeaderboardForUserCharacters", &AutoGenCharacterTests::TestCharacterClientGetLeaderboardForUserCharacters);

    AddTest("TestCharacterClientGrantCharacterToUser", &AutoGenCharacterTests::TestCharacterClientGrantCharacterToUser);

    AddTest("TestCharacterClientUpdateCharacterData", &AutoGenCharacterTests::TestCharacterClientUpdateCharacterData);

    AddTest("TestCharacterClientUpdateCharacterStatistics", &AutoGenCharacterTests::TestCharacterClientUpdateCharacterStatistics);

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCharacterServerDeleteCharacterFromUser", &AutoGenCharacterTests::TestCharacterServerDeleteCharacterFromUser);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCharacterServerGetAllUsersCharacters", &AutoGenCharacterTests::TestCharacterServerGetAllUsersCharacters);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCharacterServerGetCharacterData", &AutoGenCharacterTests::TestCharacterServerGetCharacterData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCharacterServerGetCharacterInternalData", &AutoGenCharacterTests::TestCharacterServerGetCharacterInternalData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCharacterServerGetCharacterLeaderboard", &AutoGenCharacterTests::TestCharacterServerGetCharacterLeaderboard);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCharacterServerGetCharacterReadOnlyData", &AutoGenCharacterTests::TestCharacterServerGetCharacterReadOnlyData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCharacterServerGetCharacterStatistics", &AutoGenCharacterTests::TestCharacterServerGetCharacterStatistics);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCharacterServerGetLeaderboardAroundCharacter", &AutoGenCharacterTests::TestCharacterServerGetLeaderboardAroundCharacter);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCharacterServerGetLeaderboardForUserCharacters", &AutoGenCharacterTests::TestCharacterServerGetLeaderboardForUserCharacters);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCharacterServerGrantCharacterToUser", &AutoGenCharacterTests::TestCharacterServerGrantCharacterToUser);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCharacterServerUpdateCharacterData", &AutoGenCharacterTests::TestCharacterServerUpdateCharacterData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCharacterServerUpdateCharacterInternalData", &AutoGenCharacterTests::TestCharacterServerUpdateCharacterInternalData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCharacterServerUpdateCharacterReadOnlyData", &AutoGenCharacterTests::TestCharacterServerUpdateCharacterReadOnlyData);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestCharacterServerUpdateCharacterStatistics", &AutoGenCharacterTests::TestCharacterServerUpdateCharacterStatistics);
#endif
}

void AutoGenCharacterTests::ClassSetUp()
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

void AutoGenCharacterTests::ClassTearDown()
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

void AutoGenCharacterTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AdminResetCharacterStatistics

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCharacterTests::TestCharacterAdminResetCharacterStatistics(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCharacterResetCharacterStatisticsRequestWrapper<> request;
    FillAdminResetCharacterStatisticsRequest(request);
    LogResetCharacterStatisticsRequest(&request.Model(), "TestCharacterAdminResetCharacterStatistics");
    HRESULT hr = PFCharacterAdminResetCharacterStatisticsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterAdminResetCharacterStatisticsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ClientGetAllUsersCharacters

void AutoGenCharacterTests::TestCharacterClientGetAllUsersCharacters(TestContext& testContext)
{
    struct ClientGetAllUsersCharactersResultHolderStruct : public ListUsersCharactersResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetAllUsersCharactersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetAllUsersCharactersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListUsersCharactersResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetAllUsersCharactersResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetAllUsersCharactersResultHolderStruct>>(testContext);

    PFCharacterListUsersCharactersRequestWrapper<> request;
    FillClientGetAllUsersCharactersRequest(request);
    LogListUsersCharactersRequest(&request.Model(), "TestCharacterClientGetAllUsersCharacters");
    HRESULT hr = PFCharacterClientGetAllUsersCharactersAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterClientGetAllUsersCharactersAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetCharacterData

void AutoGenCharacterTests::TestCharacterClientGetCharacterData(TestContext& testContext)
{
    struct ClientGetCharacterDataResultHolderStruct : public ClientGetCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetCharacterDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetCharacterDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogClientGetCharacterDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetCharacterDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetCharacterDataResultHolderStruct>>(testContext);

    PFCharacterGetCharacterDataRequestWrapper<> request;
    FillClientGetCharacterDataRequest(request);
    LogGetCharacterDataRequest(&request.Model(), "TestCharacterClientGetCharacterData");
    HRESULT hr = PFCharacterClientGetCharacterDataAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterClientGetCharacterDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetCharacterLeaderboard

void AutoGenCharacterTests::TestCharacterClientGetCharacterLeaderboard(TestContext& testContext)
{
    struct ClientGetCharacterLeaderboardResultHolderStruct : public GetCharacterLeaderboardResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetCharacterLeaderboardGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetCharacterLeaderboardGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetCharacterLeaderboardResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetCharacterLeaderboardResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetCharacterLeaderboardResultHolderStruct>>(testContext);

    PFCharacterGetCharacterLeaderboardRequestWrapper<> request;
    FillClientGetCharacterLeaderboardRequest(request);
    LogGetCharacterLeaderboardRequest(&request.Model(), "TestCharacterClientGetCharacterLeaderboard");
    HRESULT hr = PFCharacterClientGetCharacterLeaderboardAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterClientGetCharacterLeaderboardAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetCharacterReadOnlyData

void AutoGenCharacterTests::TestCharacterClientGetCharacterReadOnlyData(TestContext& testContext)
{
    struct ClientGetCharacterReadOnlyDataResultHolderStruct : public ClientGetCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetCharacterReadOnlyDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetCharacterReadOnlyDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogClientGetCharacterDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetCharacterReadOnlyDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetCharacterReadOnlyDataResultHolderStruct>>(testContext);

    PFCharacterGetCharacterDataRequestWrapper<> request;
    FillClientGetCharacterReadOnlyDataRequest(request);
    LogGetCharacterDataRequest(&request.Model(), "TestCharacterClientGetCharacterReadOnlyData");
    HRESULT hr = PFCharacterClientGetCharacterReadOnlyDataAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterClientGetCharacterReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetCharacterStatistics

void AutoGenCharacterTests::TestCharacterClientGetCharacterStatistics(TestContext& testContext)
{
    struct ClientGetCharacterStatisticsResultHolderStruct : public ClientGetCharacterStatisticsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetCharacterStatisticsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetCharacterStatisticsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogClientGetCharacterStatisticsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetCharacterStatisticsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetCharacterStatisticsResultHolderStruct>>(testContext);

    PFCharacterClientGetCharacterStatisticsRequestWrapper<> request;
    FillClientGetCharacterStatisticsRequest(request);
    LogClientGetCharacterStatisticsRequest(&request.Model(), "TestCharacterClientGetCharacterStatistics");
    HRESULT hr = PFCharacterClientGetCharacterStatisticsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterClientGetCharacterStatisticsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetLeaderboardAroundCharacter

void AutoGenCharacterTests::TestCharacterClientGetLeaderboardAroundCharacter(TestContext& testContext)
{
    struct ClientGetLeaderboardAroundCharacterResultHolderStruct : public GetLeaderboardAroundCharacterResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetLeaderboardAroundCharacterGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetLeaderboardAroundCharacterGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetLeaderboardAroundCharacterResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetLeaderboardAroundCharacterResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetLeaderboardAroundCharacterResultHolderStruct>>(testContext);

    PFCharacterClientGetLeaderboardAroundCharacterRequestWrapper<> request;
    FillClientGetLeaderboardAroundCharacterRequest(request);
    LogClientGetLeaderboardAroundCharacterRequest(&request.Model(), "TestCharacterClientGetLeaderboardAroundCharacter");
    HRESULT hr = PFCharacterClientGetLeaderboardAroundCharacterAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterClientGetLeaderboardAroundCharacterAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetLeaderboardForUserCharacters

void AutoGenCharacterTests::TestCharacterClientGetLeaderboardForUserCharacters(TestContext& testContext)
{
    struct ClientGetLeaderboardForUserCharactersResultHolderStruct : public GetLeaderboardForUsersCharactersResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetLeaderboardForUserCharactersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetLeaderboardForUserCharactersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetLeaderboardForUsersCharactersResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetLeaderboardForUserCharactersResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetLeaderboardForUserCharactersResultHolderStruct>>(testContext);

    PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper<> request;
    FillClientGetLeaderboardForUserCharactersRequest(request);
    LogClientGetLeaderboardForUsersCharactersRequest(&request.Model(), "TestCharacterClientGetLeaderboardForUserCharacters");
    HRESULT hr = PFCharacterClientGetLeaderboardForUserCharactersAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterClientGetLeaderboardForUserCharactersAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGrantCharacterToUser

void AutoGenCharacterTests::TestCharacterClientGrantCharacterToUser(TestContext& testContext)
{
    struct ClientGrantCharacterToUserResultHolderStruct : public ClientGrantCharacterToUserResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterClientGrantCharacterToUserGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterClientGrantCharacterToUserGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogClientGrantCharacterToUserResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGrantCharacterToUserResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGrantCharacterToUserResultHolderStruct>>(testContext);

    PFCharacterClientGrantCharacterToUserRequestWrapper<> request;
    FillClientGrantCharacterToUserRequest(request);
    LogClientGrantCharacterToUserRequest(&request.Model(), "TestCharacterClientGrantCharacterToUser");
    HRESULT hr = PFCharacterClientGrantCharacterToUserAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterClientGrantCharacterToUserAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientUpdateCharacterData

void AutoGenCharacterTests::TestCharacterClientUpdateCharacterData(TestContext& testContext)
{
    struct ClientUpdateCharacterDataResultHolderStruct : public UpdateCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFCharacterClientUpdateCharacterDataGetResult(async, &result)));
            LogUpdateCharacterDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientUpdateCharacterDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientUpdateCharacterDataResultHolderStruct>>(testContext);

    PFCharacterClientUpdateCharacterDataRequestWrapper<> request;
    FillClientUpdateCharacterDataRequest(request);
    LogClientUpdateCharacterDataRequest(&request.Model(), "TestCharacterClientUpdateCharacterData");
    HRESULT hr = PFCharacterClientUpdateCharacterDataAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterClientUpdateCharacterDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientUpdateCharacterStatistics

void AutoGenCharacterTests::TestCharacterClientUpdateCharacterStatistics(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCharacterClientUpdateCharacterStatisticsRequestWrapper<> request;
    FillClientUpdateCharacterStatisticsRequest(request);
    LogClientUpdateCharacterStatisticsRequest(&request.Model(), "TestCharacterClientUpdateCharacterStatistics");
    HRESULT hr = PFCharacterClientUpdateCharacterStatisticsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterClientUpdateCharacterStatisticsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerDeleteCharacterFromUser

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCharacterTests::TestCharacterServerDeleteCharacterFromUser(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCharacterDeleteCharacterFromUserRequestWrapper<> request;
    FillServerDeleteCharacterFromUserRequest(request);
    LogDeleteCharacterFromUserRequest(&request.Model(), "TestCharacterServerDeleteCharacterFromUser");
    HRESULT hr = PFCharacterServerDeleteCharacterFromUserAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerDeleteCharacterFromUserAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetAllUsersCharacters

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCharacterTests::TestCharacterServerGetAllUsersCharacters(TestContext& testContext)
{
    struct ServerGetAllUsersCharactersResultHolderStruct : public ListUsersCharactersResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetAllUsersCharactersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetAllUsersCharactersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListUsersCharactersResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetAllUsersCharactersResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetAllUsersCharactersResultHolderStruct>>(testContext);

    PFCharacterListUsersCharactersRequestWrapper<> request;
    FillServerGetAllUsersCharactersRequest(request);
    LogListUsersCharactersRequest(&request.Model(), "TestCharacterServerGetAllUsersCharacters");
    HRESULT hr = PFCharacterServerGetAllUsersCharactersAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerGetAllUsersCharactersAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetCharacterData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCharacterTests::TestCharacterServerGetCharacterData(TestContext& testContext)
{
    struct ServerGetCharacterDataResultHolderStruct : public ServerGetCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerGetCharacterDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetCharacterDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetCharacterDataResultHolderStruct>>(testContext);

    PFCharacterGetCharacterDataRequestWrapper<> request;
    FillServerGetCharacterDataRequest(request);
    LogGetCharacterDataRequest(&request.Model(), "TestCharacterServerGetCharacterData");
    HRESULT hr = PFCharacterServerGetCharacterDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerGetCharacterDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetCharacterInternalData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCharacterTests::TestCharacterServerGetCharacterInternalData(TestContext& testContext)
{
    struct ServerGetCharacterInternalDataResultHolderStruct : public ServerGetCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterInternalDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterInternalDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerGetCharacterDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetCharacterInternalDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetCharacterInternalDataResultHolderStruct>>(testContext);

    PFCharacterGetCharacterDataRequestWrapper<> request;
    FillServerGetCharacterInternalDataRequest(request);
    LogGetCharacterDataRequest(&request.Model(), "TestCharacterServerGetCharacterInternalData");
    HRESULT hr = PFCharacterServerGetCharacterInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerGetCharacterInternalDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetCharacterLeaderboard

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCharacterTests::TestCharacterServerGetCharacterLeaderboard(TestContext& testContext)
{
    struct ServerGetCharacterLeaderboardResultHolderStruct : public GetCharacterLeaderboardResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterLeaderboardGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterLeaderboardGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetCharacterLeaderboardResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetCharacterLeaderboardResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetCharacterLeaderboardResultHolderStruct>>(testContext);

    PFCharacterGetCharacterLeaderboardRequestWrapper<> request;
    FillServerGetCharacterLeaderboardRequest(request);
    LogGetCharacterLeaderboardRequest(&request.Model(), "TestCharacterServerGetCharacterLeaderboard");
    HRESULT hr = PFCharacterServerGetCharacterLeaderboardAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerGetCharacterLeaderboardAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetCharacterReadOnlyData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCharacterTests::TestCharacterServerGetCharacterReadOnlyData(TestContext& testContext)
{
    struct ServerGetCharacterReadOnlyDataResultHolderStruct : public ServerGetCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterReadOnlyDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterReadOnlyDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerGetCharacterDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetCharacterReadOnlyDataResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetCharacterReadOnlyDataResultHolderStruct>>(testContext);

    PFCharacterGetCharacterDataRequestWrapper<> request;
    FillServerGetCharacterReadOnlyDataRequest(request);
    LogGetCharacterDataRequest(&request.Model(), "TestCharacterServerGetCharacterReadOnlyData");
    HRESULT hr = PFCharacterServerGetCharacterReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerGetCharacterReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetCharacterStatistics

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCharacterTests::TestCharacterServerGetCharacterStatistics(TestContext& testContext)
{
    struct ServerGetCharacterStatisticsResultHolderStruct : public ServerGetCharacterStatisticsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterStatisticsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterStatisticsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerGetCharacterStatisticsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetCharacterStatisticsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetCharacterStatisticsResultHolderStruct>>(testContext);

    PFCharacterServerGetCharacterStatisticsRequestWrapper<> request;
    FillServerGetCharacterStatisticsRequest(request);
    LogServerGetCharacterStatisticsRequest(&request.Model(), "TestCharacterServerGetCharacterStatistics");
    HRESULT hr = PFCharacterServerGetCharacterStatisticsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerGetCharacterStatisticsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetLeaderboardAroundCharacter

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCharacterTests::TestCharacterServerGetLeaderboardAroundCharacter(TestContext& testContext)
{
    struct ServerGetLeaderboardAroundCharacterResultHolderStruct : public GetLeaderboardAroundCharacterResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetLeaderboardAroundCharacterGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetLeaderboardAroundCharacterGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetLeaderboardAroundCharacterResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetLeaderboardAroundCharacterResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetLeaderboardAroundCharacterResultHolderStruct>>(testContext);

    PFCharacterServerGetLeaderboardAroundCharacterRequestWrapper<> request;
    FillServerGetLeaderboardAroundCharacterRequest(request);
    LogServerGetLeaderboardAroundCharacterRequest(&request.Model(), "TestCharacterServerGetLeaderboardAroundCharacter");
    HRESULT hr = PFCharacterServerGetLeaderboardAroundCharacterAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerGetLeaderboardAroundCharacterAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetLeaderboardForUserCharacters

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCharacterTests::TestCharacterServerGetLeaderboardForUserCharacters(TestContext& testContext)
{
    struct ServerGetLeaderboardForUserCharactersResultHolderStruct : public GetLeaderboardForUsersCharactersResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetLeaderboardForUserCharactersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetLeaderboardForUserCharactersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetLeaderboardForUsersCharactersResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetLeaderboardForUserCharactersResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetLeaderboardForUserCharactersResultHolderStruct>>(testContext);

    PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper<> request;
    FillServerGetLeaderboardForUserCharactersRequest(request);
    LogServerGetLeaderboardForUsersCharactersRequest(&request.Model(), "TestCharacterServerGetLeaderboardForUserCharacters");
    HRESULT hr = PFCharacterServerGetLeaderboardForUserCharactersAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerGetLeaderboardForUserCharactersAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGrantCharacterToUser

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCharacterTests::TestCharacterServerGrantCharacterToUser(TestContext& testContext)
{
    struct ServerGrantCharacterToUserResultHolderStruct : public ServerGrantCharacterToUserResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGrantCharacterToUserGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGrantCharacterToUserGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogServerGrantCharacterToUserResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGrantCharacterToUserResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGrantCharacterToUserResultHolderStruct>>(testContext);

    PFCharacterServerGrantCharacterToUserRequestWrapper<> request;
    FillServerGrantCharacterToUserRequest(request);
    LogServerGrantCharacterToUserRequest(&request.Model(), "TestCharacterServerGrantCharacterToUser");
    HRESULT hr = PFCharacterServerGrantCharacterToUserAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerGrantCharacterToUserAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerUpdateCharacterData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCharacterTests::TestCharacterServerUpdateCharacterData(TestContext& testContext)
{
    struct ServerUpdateCharacterDataResultHolderStruct : public UpdateCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFCharacterServerUpdateCharacterDataGetResult(async, &result)));
            LogUpdateCharacterDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerUpdateCharacterDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateCharacterDataResultHolderStruct>>(testContext);

    PFCharacterServerUpdateCharacterDataRequestWrapper<> request;
    FillServerUpdateCharacterDataRequest(request);
    LogServerUpdateCharacterDataRequest(&request.Model(), "TestCharacterServerUpdateCharacterData");
    HRESULT hr = PFCharacterServerUpdateCharacterDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerUpdateCharacterDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerUpdateCharacterInternalData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCharacterTests::TestCharacterServerUpdateCharacterInternalData(TestContext& testContext)
{
    struct ServerUpdateCharacterInternalDataResultHolderStruct : public UpdateCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFCharacterServerUpdateCharacterInternalDataGetResult(async, &result)));
            LogUpdateCharacterDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerUpdateCharacterInternalDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateCharacterInternalDataResultHolderStruct>>(testContext);

    PFCharacterServerUpdateCharacterDataRequestWrapper<> request;
    FillServerUpdateCharacterInternalDataRequest(request);
    LogServerUpdateCharacterDataRequest(&request.Model(), "TestCharacterServerUpdateCharacterInternalData");
    HRESULT hr = PFCharacterServerUpdateCharacterInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerUpdateCharacterInternalDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerUpdateCharacterReadOnlyData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCharacterTests::TestCharacterServerUpdateCharacterReadOnlyData(TestContext& testContext)
{
    struct ServerUpdateCharacterReadOnlyDataResultHolderStruct : public UpdateCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFCharacterServerUpdateCharacterReadOnlyDataGetResult(async, &result)));
            LogUpdateCharacterDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerUpdateCharacterReadOnlyDataResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateCharacterReadOnlyDataResultHolderStruct>>(testContext);

    PFCharacterServerUpdateCharacterDataRequestWrapper<> request;
    FillServerUpdateCharacterReadOnlyDataRequest(request);
    LogServerUpdateCharacterDataRequest(&request.Model(), "TestCharacterServerUpdateCharacterReadOnlyData");
    HRESULT hr = PFCharacterServerUpdateCharacterReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerUpdateCharacterReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerUpdateCharacterStatistics

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenCharacterTests::TestCharacterServerUpdateCharacterStatistics(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCharacterServerUpdateCharacterStatisticsRequestWrapper<> request;
    FillServerUpdateCharacterStatisticsRequest(request);
    LogServerUpdateCharacterStatisticsRequest(&request.Model(), "TestCharacterServerUpdateCharacterStatistics");
    HRESULT hr = PFCharacterServerUpdateCharacterStatisticsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerUpdateCharacterStatisticsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
