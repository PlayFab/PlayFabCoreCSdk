#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenMatchmakingTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenMatchmakingTests::MatchmakingTestData AutoGenMatchmakingTests::testData;

void AutoGenMatchmakingTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenMatchmakingTests::LogHR(HRESULT hr)
{
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenMatchmakingTests::AddTests()
{
    // Generated tests 
#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMatchmakingCancelAllMatchmakingTicketsForPlayer", &AutoGenMatchmakingTests::TestMatchmakingCancelAllMatchmakingTicketsForPlayer);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMatchmakingCancelAllServerBackfillTicketsForPlayer", &AutoGenMatchmakingTests::TestMatchmakingCancelAllServerBackfillTicketsForPlayer);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMatchmakingCancelMatchmakingTicket", &AutoGenMatchmakingTests::TestMatchmakingCancelMatchmakingTicket);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMatchmakingCancelServerBackfillTicket", &AutoGenMatchmakingTests::TestMatchmakingCancelServerBackfillTicket);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMatchmakingCreateMatchmakingTicket", &AutoGenMatchmakingTests::TestMatchmakingCreateMatchmakingTicket);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMatchmakingCreateServerBackfillTicket", &AutoGenMatchmakingTests::TestMatchmakingCreateServerBackfillTicket);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMatchmakingCreateServerMatchmakingTicket", &AutoGenMatchmakingTests::TestMatchmakingCreateServerMatchmakingTicket);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMatchmakingGetMatch", &AutoGenMatchmakingTests::TestMatchmakingGetMatch);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMatchmakingGetMatchmakingTicket", &AutoGenMatchmakingTests::TestMatchmakingGetMatchmakingTicket);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMatchmakingGetQueueStatistics", &AutoGenMatchmakingTests::TestMatchmakingGetQueueStatistics);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMatchmakingGetServerBackfillTicket", &AutoGenMatchmakingTests::TestMatchmakingGetServerBackfillTicket);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMatchmakingJoinMatchmakingTicket", &AutoGenMatchmakingTests::TestMatchmakingJoinMatchmakingTicket);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMatchmakingListMatchmakingTicketsForPlayer", &AutoGenMatchmakingTests::TestMatchmakingListMatchmakingTicketsForPlayer);
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    AddTest("TestMatchmakingListServerBackfillTicketsForPlayer", &AutoGenMatchmakingTests::TestMatchmakingListServerBackfillTicketsForPlayer);
#endif
}

void AutoGenMatchmakingTests::ClassSetUp()
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

void AutoGenMatchmakingTests::ClassTearDown()
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

void AutoGenMatchmakingTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region CancelAllMatchmakingTicketsForPlayer

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMatchmakingTests::TestMatchmakingCancelAllMatchmakingTicketsForPlayer(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMatchmakingCancelAllMatchmakingTicketsForPlayerRequestWrapper<> request;
    FillCancelAllMatchmakingTicketsForPlayerRequest(request);
    LogCancelAllMatchmakingTicketsForPlayerRequest(&request.Model(), "TestMatchmakingCancelAllMatchmakingTicketsForPlayer");
    HRESULT hr = PFMatchmakingCancelAllMatchmakingTicketsForPlayerAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMatchmakingMatchmakingCancelAllMatchmakingTicketsForPlayerAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region CancelAllServerBackfillTicketsForPlayer

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMatchmakingTests::TestMatchmakingCancelAllServerBackfillTicketsForPlayer(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMatchmakingCancelAllServerBackfillTicketsForPlayerRequestWrapper<> request;
    FillCancelAllServerBackfillTicketsForPlayerRequest(request);
    LogCancelAllServerBackfillTicketsForPlayerRequest(&request.Model(), "TestMatchmakingCancelAllServerBackfillTicketsForPlayer");
    HRESULT hr = PFMatchmakingCancelAllServerBackfillTicketsForPlayerAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMatchmakingMatchmakingCancelAllServerBackfillTicketsForPlayerAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region CancelMatchmakingTicket

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMatchmakingTests::TestMatchmakingCancelMatchmakingTicket(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMatchmakingCancelMatchmakingTicketRequestWrapper<> request;
    FillCancelMatchmakingTicketRequest(request);
    LogCancelMatchmakingTicketRequest(&request.Model(), "TestMatchmakingCancelMatchmakingTicket");
    HRESULT hr = PFMatchmakingCancelMatchmakingTicketAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMatchmakingMatchmakingCancelMatchmakingTicketAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region CancelServerBackfillTicket

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMatchmakingTests::TestMatchmakingCancelServerBackfillTicket(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMatchmakingCancelServerBackfillTicketRequestWrapper<> request;
    FillCancelServerBackfillTicketRequest(request);
    LogCancelServerBackfillTicketRequest(&request.Model(), "TestMatchmakingCancelServerBackfillTicket");
    HRESULT hr = PFMatchmakingCancelServerBackfillTicketAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMatchmakingMatchmakingCancelServerBackfillTicketAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region CreateMatchmakingTicket

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMatchmakingTests::TestMatchmakingCreateMatchmakingTicket(TestContext& testContext)
{
    struct CreateMatchmakingTicketResultHolderStruct : public CreateMatchmakingTicketResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMatchmakingCreateMatchmakingTicketGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMatchmakingCreateMatchmakingTicketGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogCreateMatchmakingTicketResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateCreateMatchmakingTicketResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateMatchmakingTicketResultHolderStruct>>(testContext);

    PFMatchmakingCreateMatchmakingTicketRequestWrapper<> request;
    FillCreateMatchmakingTicketRequest(request);
    LogCreateMatchmakingTicketRequest(&request.Model(), "TestMatchmakingCreateMatchmakingTicket");
    HRESULT hr = PFMatchmakingCreateMatchmakingTicketAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMatchmakingMatchmakingCreateMatchmakingTicketAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region CreateServerBackfillTicket

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMatchmakingTests::TestMatchmakingCreateServerBackfillTicket(TestContext& testContext)
{
    struct CreateServerBackfillTicketResultHolderStruct : public CreateServerBackfillTicketResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMatchmakingCreateServerBackfillTicketGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMatchmakingCreateServerBackfillTicketGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogCreateServerBackfillTicketResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateCreateServerBackfillTicketResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateServerBackfillTicketResultHolderStruct>>(testContext);

    PFMatchmakingCreateServerBackfillTicketRequestWrapper<> request;
    FillCreateServerBackfillTicketRequest(request);
    LogCreateServerBackfillTicketRequest(&request.Model(), "TestMatchmakingCreateServerBackfillTicket");
    HRESULT hr = PFMatchmakingCreateServerBackfillTicketAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMatchmakingMatchmakingCreateServerBackfillTicketAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region CreateServerMatchmakingTicket

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMatchmakingTests::TestMatchmakingCreateServerMatchmakingTicket(TestContext& testContext)
{
    struct CreateServerMatchmakingTicketResultHolderStruct : public CreateMatchmakingTicketResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMatchmakingCreateServerMatchmakingTicketGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMatchmakingCreateServerMatchmakingTicketGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogCreateMatchmakingTicketResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateCreateServerMatchmakingTicketResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateServerMatchmakingTicketResultHolderStruct>>(testContext);

    PFMatchmakingCreateServerMatchmakingTicketRequestWrapper<> request;
    FillCreateServerMatchmakingTicketRequest(request);
    LogCreateServerMatchmakingTicketRequest(&request.Model(), "TestMatchmakingCreateServerMatchmakingTicket");
    HRESULT hr = PFMatchmakingCreateServerMatchmakingTicketAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMatchmakingMatchmakingCreateServerMatchmakingTicketAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetMatch

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMatchmakingTests::TestMatchmakingGetMatch(TestContext& testContext)
{
    struct GetMatchResultHolderStruct : public GetMatchResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMatchmakingGetMatchGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMatchmakingGetMatchGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetMatchResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetMatchResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetMatchResultHolderStruct>>(testContext);

    PFMatchmakingGetMatchRequestWrapper<> request;
    FillGetMatchRequest(request);
    LogGetMatchRequest(&request.Model(), "TestMatchmakingGetMatch");
    HRESULT hr = PFMatchmakingGetMatchAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMatchmakingMatchmakingGetMatchAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetMatchmakingTicket

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMatchmakingTests::TestMatchmakingGetMatchmakingTicket(TestContext& testContext)
{
    struct GetMatchmakingTicketResultHolderStruct : public GetMatchmakingTicketResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMatchmakingGetMatchmakingTicketGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMatchmakingGetMatchmakingTicketGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetMatchmakingTicketResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetMatchmakingTicketResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetMatchmakingTicketResultHolderStruct>>(testContext);

    PFMatchmakingGetMatchmakingTicketRequestWrapper<> request;
    FillGetMatchmakingTicketRequest(request);
    LogGetMatchmakingTicketRequest(&request.Model(), "TestMatchmakingGetMatchmakingTicket");
    HRESULT hr = PFMatchmakingGetMatchmakingTicketAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMatchmakingMatchmakingGetMatchmakingTicketAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetQueueStatistics

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMatchmakingTests::TestMatchmakingGetQueueStatistics(TestContext& testContext)
{
    struct GetQueueStatisticsResultHolderStruct : public GetQueueStatisticsResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMatchmakingGetQueueStatisticsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMatchmakingGetQueueStatisticsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetQueueStatisticsResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetQueueStatisticsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetQueueStatisticsResultHolderStruct>>(testContext);

    PFMatchmakingGetQueueStatisticsRequestWrapper<> request;
    FillGetQueueStatisticsRequest(request);
    LogGetQueueStatisticsRequest(&request.Model(), "TestMatchmakingGetQueueStatistics");
    HRESULT hr = PFMatchmakingGetQueueStatisticsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMatchmakingMatchmakingGetQueueStatisticsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region GetServerBackfillTicket

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMatchmakingTests::TestMatchmakingGetServerBackfillTicket(TestContext& testContext)
{
    struct GetServerBackfillTicketResultHolderStruct : public GetServerBackfillTicketResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMatchmakingGetServerBackfillTicketGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMatchmakingGetServerBackfillTicketGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetServerBackfillTicketResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetServerBackfillTicketResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetServerBackfillTicketResultHolderStruct>>(testContext);

    PFMatchmakingGetServerBackfillTicketRequestWrapper<> request;
    FillGetServerBackfillTicketRequest(request);
    LogGetServerBackfillTicketRequest(&request.Model(), "TestMatchmakingGetServerBackfillTicket");
    HRESULT hr = PFMatchmakingGetServerBackfillTicketAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMatchmakingMatchmakingGetServerBackfillTicketAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region JoinMatchmakingTicket

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMatchmakingTests::TestMatchmakingJoinMatchmakingTicket(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFMatchmakingJoinMatchmakingTicketRequestWrapper<> request;
    FillJoinMatchmakingTicketRequest(request);
    LogJoinMatchmakingTicketRequest(&request.Model(), "TestMatchmakingJoinMatchmakingTicket");
    HRESULT hr = PFMatchmakingJoinMatchmakingTicketAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMatchmakingMatchmakingJoinMatchmakingTicketAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ListMatchmakingTicketsForPlayer

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMatchmakingTests::TestMatchmakingListMatchmakingTicketsForPlayer(TestContext& testContext)
{
    struct ListMatchmakingTicketsForPlayerResultHolderStruct : public ListMatchmakingTicketsForPlayerResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMatchmakingListMatchmakingTicketsForPlayerGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMatchmakingListMatchmakingTicketsForPlayerGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListMatchmakingTicketsForPlayerResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListMatchmakingTicketsForPlayerResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListMatchmakingTicketsForPlayerResultHolderStruct>>(testContext);

    PFMatchmakingListMatchmakingTicketsForPlayerRequestWrapper<> request;
    FillListMatchmakingTicketsForPlayerRequest(request);
    LogListMatchmakingTicketsForPlayerRequest(&request.Model(), "TestMatchmakingListMatchmakingTicketsForPlayer");
    HRESULT hr = PFMatchmakingListMatchmakingTicketsForPlayerAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMatchmakingMatchmakingListMatchmakingTicketsForPlayerAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ListServerBackfillTicketsForPlayer

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenMatchmakingTests::TestMatchmakingListServerBackfillTicketsForPlayer(TestContext& testContext)
{
    struct ListServerBackfillTicketsForPlayerResultHolderStruct : public ListServerBackfillTicketsForPlayerResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFMatchmakingListServerBackfillTicketsForPlayerGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFMatchmakingListServerBackfillTicketsForPlayerGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListServerBackfillTicketsForPlayerResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListServerBackfillTicketsForPlayerResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListServerBackfillTicketsForPlayerResultHolderStruct>>(testContext);

    PFMatchmakingListServerBackfillTicketsForPlayerRequestWrapper<> request;
    FillListServerBackfillTicketsForPlayerRequest(request);
    LogListServerBackfillTicketsForPlayerRequest(&request.Model(), "TestMatchmakingListServerBackfillTicketsForPlayer");
    HRESULT hr = PFMatchmakingListServerBackfillTicketsForPlayerAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFMatchmakingMatchmakingListServerBackfillTicketsForPlayerAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
