#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenLobbyTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenLobbyTests::LobbyTestData AutoGenLobbyTests::testData;

void AutoGenLobbyTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenLobbyTests::LogHR(HRESULT hr)
{
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenLobbyTests::AddTests()
{
    // Generated tests 
    AddTest("TestLobbyCreateLobby", &AutoGenLobbyTests::TestLobbyCreateLobby);

    AddTest("TestLobbyDeleteLobby", &AutoGenLobbyTests::TestLobbyDeleteLobby);

    AddTest("TestLobbyFindFriendLobbies", &AutoGenLobbyTests::TestLobbyFindFriendLobbies);

    AddTest("TestLobbyFindLobbies", &AutoGenLobbyTests::TestLobbyFindLobbies);

    AddTest("TestLobbyGetLobby", &AutoGenLobbyTests::TestLobbyGetLobby);

    AddTest("TestLobbyInviteToLobby", &AutoGenLobbyTests::TestLobbyInviteToLobby);

    AddTest("TestLobbyJoinArrangedLobby", &AutoGenLobbyTests::TestLobbyJoinArrangedLobby);

    AddTest("TestLobbyJoinLobby", &AutoGenLobbyTests::TestLobbyJoinLobby);

    AddTest("TestLobbyLeaveLobby", &AutoGenLobbyTests::TestLobbyLeaveLobby);

    AddTest("TestLobbyRemoveMember", &AutoGenLobbyTests::TestLobbyRemoveMember);

    AddTest("TestLobbySubscribeToLobbyResource", &AutoGenLobbyTests::TestLobbySubscribeToLobbyResource);

    AddTest("TestLobbyUnsubscribeFromLobbyResource", &AutoGenLobbyTests::TestLobbyUnsubscribeFromLobbyResource);

    AddTest("TestLobbyUpdateLobby", &AutoGenLobbyTests::TestLobbyUpdateLobby);
}

void AutoGenLobbyTests::ClassSetUp()
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

void AutoGenLobbyTests::ClassTearDown()
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

void AutoGenLobbyTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region CreateLobby

void AutoGenLobbyTests::TestLobbyCreateLobby(TestContext& testContext)
{
    struct CreateLobbyResultHolderStruct : public CreateLobbyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLobbyCreateLobbyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLobbyCreateLobbyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogCreateLobbyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateCreateLobbyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateLobbyResultHolderStruct>>(testContext);

    PFLobbyCreateLobbyRequestWrapper<> request;
    FillCreateLobbyRequest(request);
    LogCreateLobbyRequest(&request.Model(), "TestLobbyCreateLobby");
    HRESULT hr = PFLobbyCreateLobbyAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLobbyLobbyCreateLobbyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region DeleteLobby

void AutoGenLobbyTests::TestLobbyDeleteLobby(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFLobbyDeleteLobbyRequestWrapper<> request;
    FillDeleteLobbyRequest(request);
    LogDeleteLobbyRequest(&request.Model(), "TestLobbyDeleteLobby");
    HRESULT hr = PFLobbyDeleteLobbyAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLobbyLobbyDeleteLobbyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region FindFriendLobbies

void AutoGenLobbyTests::TestLobbyFindFriendLobbies(TestContext& testContext)
{
    struct FindFriendLobbiesResultHolderStruct : public FindFriendLobbiesResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLobbyFindFriendLobbiesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLobbyFindFriendLobbiesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogFindFriendLobbiesResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateFindFriendLobbiesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<FindFriendLobbiesResultHolderStruct>>(testContext);

    PFLobbyFindFriendLobbiesRequestWrapper<> request;
    FillFindFriendLobbiesRequest(request);
    LogFindFriendLobbiesRequest(&request.Model(), "TestLobbyFindFriendLobbies");
    HRESULT hr = PFLobbyFindFriendLobbiesAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLobbyLobbyFindFriendLobbiesAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region FindLobbies

void AutoGenLobbyTests::TestLobbyFindLobbies(TestContext& testContext)
{
    struct FindLobbiesResultHolderStruct : public FindLobbiesResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLobbyFindLobbiesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLobbyFindLobbiesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogFindLobbiesResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateFindLobbiesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<FindLobbiesResultHolderStruct>>(testContext);

    PFLobbyFindLobbiesRequestWrapper<> request;
    FillFindLobbiesRequest(request);
    LogFindLobbiesRequest(&request.Model(), "TestLobbyFindLobbies");
    HRESULT hr = PFLobbyFindLobbiesAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLobbyLobbyFindLobbiesAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetLobby

void AutoGenLobbyTests::TestLobbyGetLobby(TestContext& testContext)
{
    struct GetLobbyResultHolderStruct : public GetLobbyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLobbyGetLobbyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLobbyGetLobbyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetLobbyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetLobbyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetLobbyResultHolderStruct>>(testContext);

    PFLobbyGetLobbyRequestWrapper<> request;
    FillGetLobbyRequest(request);
    LogGetLobbyRequest(&request.Model(), "TestLobbyGetLobby");
    HRESULT hr = PFLobbyGetLobbyAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLobbyLobbyGetLobbyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region InviteToLobby

void AutoGenLobbyTests::TestLobbyInviteToLobby(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFLobbyInviteToLobbyRequestWrapper<> request;
    FillInviteToLobbyRequest(request);
    LogInviteToLobbyRequest(&request.Model(), "TestLobbyInviteToLobby");
    HRESULT hr = PFLobbyInviteToLobbyAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLobbyLobbyInviteToLobbyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region JoinArrangedLobby

void AutoGenLobbyTests::TestLobbyJoinArrangedLobby(TestContext& testContext)
{
    struct JoinArrangedLobbyResultHolderStruct : public JoinLobbyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLobbyJoinArrangedLobbyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLobbyJoinArrangedLobbyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogJoinLobbyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateJoinArrangedLobbyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<JoinArrangedLobbyResultHolderStruct>>(testContext);

    PFLobbyJoinArrangedLobbyRequestWrapper<> request;
    FillJoinArrangedLobbyRequest(request);
    LogJoinArrangedLobbyRequest(&request.Model(), "TestLobbyJoinArrangedLobby");
    HRESULT hr = PFLobbyJoinArrangedLobbyAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLobbyLobbyJoinArrangedLobbyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region JoinLobby

void AutoGenLobbyTests::TestLobbyJoinLobby(TestContext& testContext)
{
    struct JoinLobbyResultHolderStruct : public JoinLobbyResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLobbyJoinLobbyGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLobbyJoinLobbyGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogJoinLobbyResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateJoinLobbyResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<JoinLobbyResultHolderStruct>>(testContext);

    PFLobbyJoinLobbyRequestWrapper<> request;
    FillJoinLobbyRequest(request);
    LogJoinLobbyRequest(&request.Model(), "TestLobbyJoinLobby");
    HRESULT hr = PFLobbyJoinLobbyAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLobbyLobbyJoinLobbyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region LeaveLobby

void AutoGenLobbyTests::TestLobbyLeaveLobby(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFLobbyLeaveLobbyRequestWrapper<> request;
    FillLeaveLobbyRequest(request);
    LogLeaveLobbyRequest(&request.Model(), "TestLobbyLeaveLobby");
    HRESULT hr = PFLobbyLeaveLobbyAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLobbyLobbyLeaveLobbyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region RemoveMember

void AutoGenLobbyTests::TestLobbyRemoveMember(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFLobbyRemoveMemberFromLobbyRequestWrapper<> request;
    FillRemoveMemberRequest(request);
    LogRemoveMemberFromLobbyRequest(&request.Model(), "TestLobbyRemoveMember");
    HRESULT hr = PFLobbyRemoveMemberAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLobbyLobbyRemoveMemberAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region SubscribeToLobbyResource

void AutoGenLobbyTests::TestLobbySubscribeToLobbyResource(TestContext& testContext)
{
    struct SubscribeToLobbyResourceResultHolderStruct : public SubscribeToLobbyResourceResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFLobbySubscribeToLobbyResourceGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFLobbySubscribeToLobbyResourceGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogSubscribeToLobbyResourceResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateSubscribeToLobbyResourceResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<SubscribeToLobbyResourceResultHolderStruct>>(testContext);

    PFLobbySubscribeToLobbyResourceRequestWrapper<> request;
    FillSubscribeToLobbyResourceRequest(request);
    LogSubscribeToLobbyResourceRequest(&request.Model(), "TestLobbySubscribeToLobbyResource");
    HRESULT hr = PFLobbySubscribeToLobbyResourceAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLobbyLobbySubscribeToLobbyResourceAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region UnsubscribeFromLobbyResource

void AutoGenLobbyTests::TestLobbyUnsubscribeFromLobbyResource(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFLobbyUnsubscribeFromLobbyResourceRequestWrapper<> request;
    FillUnsubscribeFromLobbyResourceRequest(request);
    LogUnsubscribeFromLobbyResourceRequest(&request.Model(), "TestLobbyUnsubscribeFromLobbyResource");
    HRESULT hr = PFLobbyUnsubscribeFromLobbyResourceAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLobbyLobbyUnsubscribeFromLobbyResourceAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region UpdateLobby

void AutoGenLobbyTests::TestLobbyUpdateLobby(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFLobbyUpdateLobbyRequestWrapper<> request;
    FillUpdateLobbyRequest(request);
    LogUpdateLobbyRequest(&request.Model(), "TestLobbyUpdateLobby");
    HRESULT hr = PFLobbyUpdateLobbyAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFLobbyLobbyUpdateLobbyAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
