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
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenCharacterTests::AddTests()
{
    // Generated tests 
    AddTest("TestCharacterAdminResetCharacterStatistics", &AutoGenCharacterTests::TestCharacterAdminResetCharacterStatistics);

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

    AddTest("TestCharacterServerDeleteCharacterFromUser", &AutoGenCharacterTests::TestCharacterServerDeleteCharacterFromUser);

    AddTest("TestCharacterServerGetAllUsersCharacters", &AutoGenCharacterTests::TestCharacterServerGetAllUsersCharacters);

    AddTest("TestCharacterServerGetCharacterData", &AutoGenCharacterTests::TestCharacterServerGetCharacterData);

    AddTest("TestCharacterServerGetCharacterInternalData", &AutoGenCharacterTests::TestCharacterServerGetCharacterInternalData);

    AddTest("TestCharacterServerGetCharacterLeaderboard", &AutoGenCharacterTests::TestCharacterServerGetCharacterLeaderboard);

    AddTest("TestCharacterServerGetCharacterReadOnlyData", &AutoGenCharacterTests::TestCharacterServerGetCharacterReadOnlyData);

    AddTest("TestCharacterServerGetCharacterStatistics", &AutoGenCharacterTests::TestCharacterServerGetCharacterStatistics);

    AddTest("TestCharacterServerGetLeaderboardAroundCharacter", &AutoGenCharacterTests::TestCharacterServerGetLeaderboardAroundCharacter);

    AddTest("TestCharacterServerGetLeaderboardForUserCharacters", &AutoGenCharacterTests::TestCharacterServerGetLeaderboardForUserCharacters);

    AddTest("TestCharacterServerGrantCharacterToUser", &AutoGenCharacterTests::TestCharacterServerGrantCharacterToUser);

    AddTest("TestCharacterServerUpdateCharacterData", &AutoGenCharacterTests::TestCharacterServerUpdateCharacterData);

    AddTest("TestCharacterServerUpdateCharacterInternalData", &AutoGenCharacterTests::TestCharacterServerUpdateCharacterInternalData);

    AddTest("TestCharacterServerUpdateCharacterReadOnlyData", &AutoGenCharacterTests::TestCharacterServerUpdateCharacterReadOnlyData);

    AddTest("TestCharacterServerUpdateCharacterStatistics", &AutoGenCharacterTests::TestCharacterServerUpdateCharacterStatistics);
}

void AutoGenCharacterTests::ClassSetUp()
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

void AutoGenCharacterTests::TestCharacterAdminResetCharacterStatistics(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCharacterResetCharacterStatisticsRequestWrapper<> request;
    FillResetCharacterStatisticsRequest(request);
    LogResetCharacterStatisticsRequest(&request.Model(), "TestCharacterAdminResetCharacterStatistics");
    HRESULT hr = PFCharacterAdminResetCharacterStatisticsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterAdminResetCharacterStatisticsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetAllUsersCharacters

void AutoGenCharacterTests::TestCharacterClientGetAllUsersCharacters(TestContext& testContext)
{
    struct ClientGetAllUsersCharactersResultHolder : public ListUsersCharactersResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetAllUsersCharactersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetAllUsersCharactersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCharacterListUsersCharactersResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterListUsersCharactersResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetAllUsersCharactersResultHolder>>(testContext);

    PFCharacterListUsersCharactersRequestWrapper<> request;
    FillListUsersCharactersRequest(request);
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
    struct ClientGetCharacterDataResultHolder : public ClientGetCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetCharacterDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetCharacterDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCharacterClientGetCharacterDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterClientGetCharacterDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetCharacterDataResultHolder>>(testContext);

    PFCharacterGetCharacterDataRequestWrapper<> request;
    FillGetCharacterDataRequest(request);
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
    struct ClientGetCharacterLeaderboardResultHolder : public GetCharacterLeaderboardResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetCharacterLeaderboardGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetCharacterLeaderboardGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCharacterGetCharacterLeaderboardResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterGetCharacterLeaderboardResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetCharacterLeaderboardResultHolder>>(testContext);

    PFCharacterGetCharacterLeaderboardRequestWrapper<> request;
    FillGetCharacterLeaderboardRequest(request);
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
    struct ClientGetCharacterReadOnlyDataResultHolder : public ClientGetCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetCharacterReadOnlyDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetCharacterReadOnlyDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCharacterClientGetCharacterDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterClientGetCharacterDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetCharacterReadOnlyDataResultHolder>>(testContext);

    PFCharacterGetCharacterDataRequestWrapper<> request;
    FillGetCharacterDataRequest(request);
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
    struct ClientGetCharacterStatisticsResultHolder : public ClientGetCharacterStatisticsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetCharacterStatisticsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetCharacterStatisticsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCharacterClientGetCharacterStatisticsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterClientGetCharacterStatisticsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetCharacterStatisticsResultHolder>>(testContext);

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
    struct ClientGetLeaderboardAroundCharacterResultHolder : public GetLeaderboardAroundCharacterResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetLeaderboardAroundCharacterGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetLeaderboardAroundCharacterGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCharacterGetLeaderboardAroundCharacterResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterGetLeaderboardAroundCharacterResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetLeaderboardAroundCharacterResultHolder>>(testContext);

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
    struct ClientGetLeaderboardForUserCharactersResultHolder : public GetLeaderboardForUsersCharactersResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetLeaderboardForUserCharactersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterClientGetLeaderboardForUserCharactersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCharacterGetLeaderboardForUsersCharactersResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterGetLeaderboardForUsersCharactersResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetLeaderboardForUserCharactersResultHolder>>(testContext);

    PFCharacterClientGetLeaderboardForUsersCharactersRequestWrapper<> request;
    FillClientGetLeaderboardForUsersCharactersRequest(request);
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
    struct ClientGrantCharacterToUserResultHolder : public ClientGrantCharacterToUserResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterClientGrantCharacterToUserGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterClientGrantCharacterToUserGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCharacterClientGrantCharacterToUserResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterClientGrantCharacterToUserResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGrantCharacterToUserResultHolder>>(testContext);

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
    struct ClientUpdateCharacterDataResultHolder : public UpdateCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFCharacterClientUpdateCharacterDataGetResult(async, &result)));
            LogPFCharacterUpdateCharacterDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterUpdateCharacterDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientUpdateCharacterDataResultHolder>>(testContext);

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

void AutoGenCharacterTests::TestCharacterServerDeleteCharacterFromUser(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFCharacterDeleteCharacterFromUserRequestWrapper<> request;
    FillDeleteCharacterFromUserRequest(request);
    LogDeleteCharacterFromUserRequest(&request.Model(), "TestCharacterServerDeleteCharacterFromUser");
    HRESULT hr = PFCharacterServerDeleteCharacterFromUserAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerDeleteCharacterFromUserAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetAllUsersCharacters

void AutoGenCharacterTests::TestCharacterServerGetAllUsersCharacters(TestContext& testContext)
{
    struct ServerGetAllUsersCharactersResultHolder : public ListUsersCharactersResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetAllUsersCharactersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetAllUsersCharactersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCharacterListUsersCharactersResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterListUsersCharactersResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetAllUsersCharactersResultHolder>>(testContext);

    PFCharacterListUsersCharactersRequestWrapper<> request;
    FillListUsersCharactersRequest(request);
    LogListUsersCharactersRequest(&request.Model(), "TestCharacterServerGetAllUsersCharacters");
    HRESULT hr = PFCharacterServerGetAllUsersCharactersAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerGetAllUsersCharactersAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetCharacterData

void AutoGenCharacterTests::TestCharacterServerGetCharacterData(TestContext& testContext)
{
    struct ServerGetCharacterDataResultHolder : public ServerGetCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCharacterServerGetCharacterDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterServerGetCharacterDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetCharacterDataResultHolder>>(testContext);

    PFCharacterGetCharacterDataRequestWrapper<> request;
    FillGetCharacterDataRequest(request);
    LogGetCharacterDataRequest(&request.Model(), "TestCharacterServerGetCharacterData");
    HRESULT hr = PFCharacterServerGetCharacterDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerGetCharacterDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetCharacterInternalData

void AutoGenCharacterTests::TestCharacterServerGetCharacterInternalData(TestContext& testContext)
{
    struct ServerGetCharacterInternalDataResultHolder : public ServerGetCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterInternalDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterInternalDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCharacterServerGetCharacterDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterServerGetCharacterDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetCharacterInternalDataResultHolder>>(testContext);

    PFCharacterGetCharacterDataRequestWrapper<> request;
    FillGetCharacterDataRequest(request);
    LogGetCharacterDataRequest(&request.Model(), "TestCharacterServerGetCharacterInternalData");
    HRESULT hr = PFCharacterServerGetCharacterInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerGetCharacterInternalDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetCharacterLeaderboard

void AutoGenCharacterTests::TestCharacterServerGetCharacterLeaderboard(TestContext& testContext)
{
    struct ServerGetCharacterLeaderboardResultHolder : public GetCharacterLeaderboardResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterLeaderboardGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterLeaderboardGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCharacterGetCharacterLeaderboardResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterGetCharacterLeaderboardResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetCharacterLeaderboardResultHolder>>(testContext);

    PFCharacterGetCharacterLeaderboardRequestWrapper<> request;
    FillGetCharacterLeaderboardRequest(request);
    LogGetCharacterLeaderboardRequest(&request.Model(), "TestCharacterServerGetCharacterLeaderboard");
    HRESULT hr = PFCharacterServerGetCharacterLeaderboardAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerGetCharacterLeaderboardAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetCharacterReadOnlyData

void AutoGenCharacterTests::TestCharacterServerGetCharacterReadOnlyData(TestContext& testContext)
{
    struct ServerGetCharacterReadOnlyDataResultHolder : public ServerGetCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterReadOnlyDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterReadOnlyDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCharacterServerGetCharacterDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterServerGetCharacterDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetCharacterReadOnlyDataResultHolder>>(testContext);

    PFCharacterGetCharacterDataRequestWrapper<> request;
    FillGetCharacterDataRequest(request);
    LogGetCharacterDataRequest(&request.Model(), "TestCharacterServerGetCharacterReadOnlyData");
    HRESULT hr = PFCharacterServerGetCharacterReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerGetCharacterReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGetCharacterStatistics

void AutoGenCharacterTests::TestCharacterServerGetCharacterStatistics(TestContext& testContext)
{
    struct ServerGetCharacterStatisticsResultHolder : public ServerGetCharacterStatisticsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterStatisticsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetCharacterStatisticsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCharacterServerGetCharacterStatisticsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterServerGetCharacterStatisticsResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetCharacterStatisticsResultHolder>>(testContext);

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

#pragma endregion

#pragma region ServerGetLeaderboardAroundCharacter

void AutoGenCharacterTests::TestCharacterServerGetLeaderboardAroundCharacter(TestContext& testContext)
{
    struct ServerGetLeaderboardAroundCharacterResultHolder : public GetLeaderboardAroundCharacterResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetLeaderboardAroundCharacterGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetLeaderboardAroundCharacterGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCharacterGetLeaderboardAroundCharacterResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterGetLeaderboardAroundCharacterResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetLeaderboardAroundCharacterResultHolder>>(testContext);

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

#pragma endregion

#pragma region ServerGetLeaderboardForUserCharacters

void AutoGenCharacterTests::TestCharacterServerGetLeaderboardForUserCharacters(TestContext& testContext)
{
    struct ServerGetLeaderboardForUserCharactersResultHolder : public GetLeaderboardForUsersCharactersResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetLeaderboardForUserCharactersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGetLeaderboardForUserCharactersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCharacterGetLeaderboardForUsersCharactersResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterGetLeaderboardForUsersCharactersResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetLeaderboardForUserCharactersResultHolder>>(testContext);

    PFCharacterServerGetLeaderboardForUsersCharactersRequestWrapper<> request;
    FillServerGetLeaderboardForUsersCharactersRequest(request);
    LogServerGetLeaderboardForUsersCharactersRequest(&request.Model(), "TestCharacterServerGetLeaderboardForUserCharacters");
    HRESULT hr = PFCharacterServerGetLeaderboardForUserCharactersAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerGetLeaderboardForUserCharactersAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerGrantCharacterToUser

void AutoGenCharacterTests::TestCharacterServerGrantCharacterToUser(TestContext& testContext)
{
    struct ServerGrantCharacterToUserResultHolder : public ServerGrantCharacterToUserResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFCharacterServerGrantCharacterToUserGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFCharacterServerGrantCharacterToUserGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFCharacterServerGrantCharacterToUserResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterServerGrantCharacterToUserResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGrantCharacterToUserResultHolder>>(testContext);

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

#pragma endregion

#pragma region ServerUpdateCharacterData

void AutoGenCharacterTests::TestCharacterServerUpdateCharacterData(TestContext& testContext)
{
    struct ServerUpdateCharacterDataResultHolder : public UpdateCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFCharacterServerUpdateCharacterDataGetResult(async, &result)));
            LogPFCharacterUpdateCharacterDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterUpdateCharacterDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateCharacterDataResultHolder>>(testContext);

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

#pragma endregion

#pragma region ServerUpdateCharacterInternalData

void AutoGenCharacterTests::TestCharacterServerUpdateCharacterInternalData(TestContext& testContext)
{
    struct ServerUpdateCharacterInternalDataResultHolder : public UpdateCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFCharacterServerUpdateCharacterInternalDataGetResult(async, &result)));
            LogPFCharacterUpdateCharacterDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterUpdateCharacterDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateCharacterInternalDataResultHolder>>(testContext);

    PFCharacterServerUpdateCharacterDataRequestWrapper<> request;
    FillServerUpdateCharacterDataRequest(request);
    LogServerUpdateCharacterDataRequest(&request.Model(), "TestCharacterServerUpdateCharacterInternalData");
    HRESULT hr = PFCharacterServerUpdateCharacterInternalDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerUpdateCharacterInternalDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerUpdateCharacterReadOnlyData

void AutoGenCharacterTests::TestCharacterServerUpdateCharacterReadOnlyData(TestContext& testContext)
{
    struct ServerUpdateCharacterReadOnlyDataResultHolder : public UpdateCharacterDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFCharacterServerUpdateCharacterReadOnlyDataGetResult(async, &result)));
            LogPFCharacterUpdateCharacterDataResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFCharacterUpdateCharacterDataResult(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerUpdateCharacterReadOnlyDataResultHolder>>(testContext);

    PFCharacterServerUpdateCharacterDataRequestWrapper<> request;
    FillServerUpdateCharacterDataRequest(request);
    LogServerUpdateCharacterDataRequest(&request.Model(), "TestCharacterServerUpdateCharacterReadOnlyData");
    HRESULT hr = PFCharacterServerUpdateCharacterReadOnlyDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFCharacterCharacterServerUpdateCharacterReadOnlyDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerUpdateCharacterStatistics

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

#pragma endregion


}
