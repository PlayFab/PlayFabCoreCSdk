#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenFriendsTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenFriendsTests::FriendsTestData AutoGenFriendsTests::testData;

void AutoGenFriendsTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenFriendsTests::LogHR(HRESULT hr)
{
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenFriendsTests::AddTests()
{
    // Generated tests 
    AddTest("TestFriendsClientAddFriend", &AutoGenFriendsTests::TestFriendsClientAddFriend);
    AddTest("TestFriendsClientAddFriendCleanupClientRemoveFriend", &AutoGenFriendsTests::TestFriendsClientAddFriendCleanupClientRemoveFriend);

    AddTest("TestFriendsClientGetFriendsList", &AutoGenFriendsTests::TestFriendsClientGetFriendsList);

    AddTest("TestFriendsClientRemoveFriendPrerequisiteClientAddFriend", &AutoGenFriendsTests::TestFriendsClientRemoveFriendPrerequisiteClientAddFriend);
    AddTest("TestFriendsClientRemoveFriend", &AutoGenFriendsTests::TestFriendsClientRemoveFriend);

    AddTest("TestFriendsClientSetFriendTags", &AutoGenFriendsTests::TestFriendsClientSetFriendTags);

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestFriendsServerAddFriend", &AutoGenFriendsTests::TestFriendsServerAddFriend); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestFriendsServerGetFriendsList", &AutoGenFriendsTests::TestFriendsServerGetFriendsList); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestFriendsServerRemoveFriend", &AutoGenFriendsTests::TestFriendsServerRemoveFriend); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestFriendsServerSetFriendTags", &AutoGenFriendsTests::TestFriendsServerSetFriendTags); // TODO: debug failing test
#endif
}

void AutoGenFriendsTests::ClassSetUp()
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

void AutoGenFriendsTests::ClassTearDown()
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

void AutoGenFriendsTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region ClientAddFriend

void AutoGenFriendsTests::TestFriendsClientAddFriend(TestContext& testContext)
{
    struct ClientAddFriendResultHolderStruct : public AddFriendResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFFriendsClientAddFriendGetResult(async, &result)));
            LogAddFriendResult(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientAddFriendResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientAddFriendResultHolderStruct>>(testContext);

    PFFriendsClientAddFriendRequestWrapper<> request;
    FillClientAddFriendRequest(request);
    LogClientAddFriendRequest(&request.Model(), "TestFriendsClientAddFriend");
    HRESULT hr = PFFriendsClientAddFriendAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFFriendsFriendsClientAddFriendAsync", hr);
        return;
    }
    async.release(); 
}
void AutoGenFriendsTests::TestFriendsClientAddFriendCleanupClientRemoveFriend(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFFriendsClientRemoveFriendRequestWrapper<> request;
    FillClientAddFriendCleanupClientRemoveFriendRequest(request);
    HRESULT hr = PFFriendsClientRemoveFriendAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFFriendsFriendsClientAddFriendCleanupClientRemoveFriendAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region ClientGetFriendsList

void AutoGenFriendsTests::TestFriendsClientGetFriendsList(TestContext& testContext)
{
    struct ClientGetFriendsListResultHolderStruct : public GetFriendsListResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFFriendsClientGetFriendsListGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFFriendsClientGetFriendsListGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetFriendsListResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateClientGetFriendsListResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetFriendsListResultHolderStruct>>(testContext);

    PFFriendsClientGetFriendsListRequestWrapper<> request;
    FillClientGetFriendsListRequest(request);
    LogClientGetFriendsListRequest(&request.Model(), "TestFriendsClientGetFriendsList");
    HRESULT hr = PFFriendsClientGetFriendsListAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFFriendsFriendsClientGetFriendsListAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientRemoveFriend

void AutoGenFriendsTests::TestFriendsClientRemoveFriendPrerequisiteClientAddFriend(TestContext& testContext)
{
    struct ClientAddFriendResultHolderStruct : public AddFriendResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFFriendsClientAddFriendGetResult(async, &result)));
            return StoreClientRemoveFriendPrerequisiteClientAddFriendResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientAddFriendResultHolderStruct>>(testContext);

    PFFriendsClientAddFriendRequestWrapper<> request;
    FillClientRemoveFriendPrerequisiteClientAddFriendRequest(request);
    HRESULT hr = PFFriendsClientAddFriendAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFFriendsFriendsClientRemoveFriendPrerequisiteClientAddFriendAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenFriendsTests::TestFriendsClientRemoveFriend(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFFriendsClientRemoveFriendRequestWrapper<> request;
    FillClientRemoveFriendRequest(request);
    LogClientRemoveFriendRequest(&request.Model(), "TestFriendsClientRemoveFriend");
    HRESULT hr = PFFriendsClientRemoveFriendAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFFriendsFriendsClientRemoveFriendAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientSetFriendTags

void AutoGenFriendsTests::TestFriendsClientSetFriendTags(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFFriendsClientSetFriendTagsRequestWrapper<> request;
    FillClientSetFriendTagsRequest(request);
    LogClientSetFriendTagsRequest(&request.Model(), "TestFriendsClientSetFriendTags");
    HRESULT hr = PFFriendsClientSetFriendTagsAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFFriendsFriendsClientSetFriendTagsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerAddFriend

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenFriendsTests::TestFriendsServerAddFriend(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFFriendsServerAddFriendRequestWrapper<> request;
    FillServerAddFriendRequest(request);
    LogServerAddFriendRequest(&request.Model(), "TestFriendsServerAddFriend");
    HRESULT hr = PFFriendsServerAddFriendAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFFriendsFriendsServerAddFriendAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetFriendsList

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenFriendsTests::TestFriendsServerGetFriendsList(TestContext& testContext)
{
    struct ServerGetFriendsListResultHolderStruct : public GetFriendsListResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFFriendsServerGetFriendsListGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFFriendsServerGetFriendsListGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetFriendsListResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateServerGetFriendsListResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetFriendsListResultHolderStruct>>(testContext);

    PFFriendsServerGetFriendsListRequestWrapper<> request;
    FillServerGetFriendsListRequest(request);
    LogServerGetFriendsListRequest(&request.Model(), "TestFriendsServerGetFriendsList");
    HRESULT hr = PFFriendsServerGetFriendsListAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFFriendsFriendsServerGetFriendsListAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerRemoveFriend

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenFriendsTests::TestFriendsServerRemoveFriend(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFFriendsServerRemoveFriendRequestWrapper<> request;
    FillServerRemoveFriendRequest(request);
    LogServerRemoveFriendRequest(&request.Model(), "TestFriendsServerRemoveFriend");
    HRESULT hr = PFFriendsServerRemoveFriendAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFFriendsFriendsServerRemoveFriendAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerSetFriendTags

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenFriendsTests::TestFriendsServerSetFriendTags(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFFriendsServerSetFriendTagsRequestWrapper<> request;
    FillServerSetFriendTagsRequest(request);
    LogServerSetFriendTagsRequest(&request.Model(), "TestFriendsServerSetFriendTags");
    HRESULT hr = PFFriendsServerSetFriendTagsAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFFriendsFriendsServerSetFriendTagsAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
