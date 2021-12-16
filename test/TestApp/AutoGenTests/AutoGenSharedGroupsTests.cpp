#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenSharedGroupsTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenSharedGroupsTests::SharedGroupsTestData AutoGenSharedGroupsTests::testData;

void AutoGenSharedGroupsTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenSharedGroupsTests::LogHR(HRESULT hr)
{
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenSharedGroupsTests::AddTests()
{
    // Generated tests 
    AddTest("TestSharedGroupsClientAddSharedGroupMembersPrerequisiteClientCreateSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsClientAddSharedGroupMembersPrerequisiteClientCreateSharedGroup);
    AddTest("TestSharedGroupsClientAddSharedGroupMembers", &AutoGenSharedGroupsTests::TestSharedGroupsClientAddSharedGroupMembers);
    AddTest("TestSharedGroupsClientAddSharedGroupMembersCleanupClientRemoveSharedGroupMembers", &AutoGenSharedGroupsTests::TestSharedGroupsClientAddSharedGroupMembersCleanupClientRemoveSharedGroupMembers);

    //AddTest("TestSharedGroupsClientCreateSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsClientCreateSharedGroup); // TODO: debug failing test

    AddTest("TestSharedGroupsClientGetSharedGroupDataPrerequisiteClientCreateSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsClientGetSharedGroupDataPrerequisiteClientCreateSharedGroup);
    AddTest("TestSharedGroupsClientGetSharedGroupDataPrerequisiteClientUpdateSharedGroupData", &AutoGenSharedGroupsTests::TestSharedGroupsClientGetSharedGroupDataPrerequisiteClientUpdateSharedGroupData);
    AddTest("TestSharedGroupsClientGetSharedGroupData", &AutoGenSharedGroupsTests::TestSharedGroupsClientGetSharedGroupData);

    AddTest("TestSharedGroupsClientRemoveSharedGroupMembersPrerequisiteClientCreateSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsClientRemoveSharedGroupMembersPrerequisiteClientCreateSharedGroup);
    AddTest("TestSharedGroupsClientRemoveSharedGroupMembersPrerequisiteClientAddSharedGroupMembers", &AutoGenSharedGroupsTests::TestSharedGroupsClientRemoveSharedGroupMembersPrerequisiteClientAddSharedGroupMembers);
    AddTest("TestSharedGroupsClientRemoveSharedGroupMembers", &AutoGenSharedGroupsTests::TestSharedGroupsClientRemoveSharedGroupMembers);

    AddTest("TestSharedGroupsClientUpdateSharedGroupDataPrerequisiteClientCreateSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsClientUpdateSharedGroupDataPrerequisiteClientCreateSharedGroup);
    AddTest("TestSharedGroupsClientUpdateSharedGroupData", &AutoGenSharedGroupsTests::TestSharedGroupsClientUpdateSharedGroupData);

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestSharedGroupsServerAddSharedGroupMembers", &AutoGenSharedGroupsTests::TestSharedGroupsServerAddSharedGroupMembers); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestSharedGroupsServerCreateSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsServerCreateSharedGroup); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestSharedGroupsServerDeleteSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsServerDeleteSharedGroup); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestSharedGroupsServerGetSharedGroupData", &AutoGenSharedGroupsTests::TestSharedGroupsServerGetSharedGroupData); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestSharedGroupsServerRemoveSharedGroupMembers", &AutoGenSharedGroupsTests::TestSharedGroupsServerRemoveSharedGroupMembers); // TODO: debug failing test
#endif

#if HC_PLATFORM != HC_PLATFORM_GDK
    //AddTest("TestSharedGroupsServerUpdateSharedGroupData", &AutoGenSharedGroupsTests::TestSharedGroupsServerUpdateSharedGroupData); // TODO: debug failing test
#endif
}

void AutoGenSharedGroupsTests::ClassSetUp()
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

void AutoGenSharedGroupsTests::ClassTearDown()
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

void AutoGenSharedGroupsTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region ClientAddSharedGroupMembers

void AutoGenSharedGroupsTests::TestSharedGroupsClientAddSharedGroupMembersPrerequisiteClientCreateSharedGroup(TestContext& testContext)
{
    struct ClientCreateSharedGroupResultHolderStruct : public CreateSharedGroupResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFSharedGroupsClientCreateSharedGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFSharedGroupsClientCreateSharedGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFSharedGroupsCreateSharedGroupResult(result);
            return StoreClientAddSharedGroupMembersPrerequisitePFSharedGroupsCreateSharedGroupResult(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientCreateSharedGroupResultHolderStruct>>(testContext);

    PFSharedGroupsCreateSharedGroupRequestWrapper<> request;
    FillClientAddSharedGroupMembersPrerequisiteCreateSharedGroupRequest(request);
    LogCreateSharedGroupRequest(&request.Model(), "TestSharedGroupsServerUpdateSharedGroupData");
    HRESULT hr = PFSharedGroupsClientCreateSharedGroupAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsClientAddSharedGroupMembersPrerequisiteClientCreateSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenSharedGroupsTests::TestSharedGroupsClientAddSharedGroupMembers(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsAddSharedGroupMembersRequestWrapper<> request;
    FillAddSharedGroupMembersRequest(request);
    LogAddSharedGroupMembersRequest(&request.Model(), "TestSharedGroupsClientAddSharedGroupMembers");
    HRESULT hr = PFSharedGroupsClientAddSharedGroupMembersAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsClientAddSharedGroupMembersAsync", hr);
        return;
    }
    async.release(); 
}
void AutoGenSharedGroupsTests::TestSharedGroupsClientAddSharedGroupMembersCleanupClientRemoveSharedGroupMembers(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsRemoveSharedGroupMembersRequestWrapper<> request;
    FillClientAddSharedGroupMembersCleanupRemoveSharedGroupMembersRequest(request);
    LogRemoveSharedGroupMembersRequest(&request.Model(), "TestSharedGroupsClientAddSharedGroupMembersCleanupClientRemoveSharedGroupMembers");
    HRESULT hr = PFSharedGroupsClientRemoveSharedGroupMembersAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsClientAddSharedGroupMembersCleanupClientRemoveSharedGroupMembersAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region ClientCreateSharedGroup

void AutoGenSharedGroupsTests::TestSharedGroupsClientCreateSharedGroup(TestContext& testContext)
{
    struct ClientCreateSharedGroupResultHolderStruct : public CreateSharedGroupResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFSharedGroupsClientCreateSharedGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFSharedGroupsClientCreateSharedGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFSharedGroupsCreateSharedGroupResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFSharedGroupsCreateSharedGroupResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientCreateSharedGroupResultHolderStruct>>(testContext);

    PFSharedGroupsCreateSharedGroupRequestWrapper<> request;
    FillCreateSharedGroupRequest(request);
    LogCreateSharedGroupRequest(&request.Model(), "TestSharedGroupsClientCreateSharedGroup");
    HRESULT hr = PFSharedGroupsClientCreateSharedGroupAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsClientCreateSharedGroupAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientGetSharedGroupData

void AutoGenSharedGroupsTests::TestSharedGroupsClientGetSharedGroupDataPrerequisiteClientCreateSharedGroup(TestContext& testContext)
{
    struct ClientCreateSharedGroupResultHolderStruct : public CreateSharedGroupResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFSharedGroupsClientCreateSharedGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFSharedGroupsClientCreateSharedGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFSharedGroupsCreateSharedGroupResult(result);
            return StoreClientGetSharedGroupDataPrerequisitePFSharedGroupsCreateSharedGroupResult(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientCreateSharedGroupResultHolderStruct>>(testContext);

    PFSharedGroupsCreateSharedGroupRequestWrapper<> request;
    FillClientGetSharedGroupDataPrerequisiteCreateSharedGroupRequest(request);
    LogCreateSharedGroupRequest(&request.Model(), "TestSharedGroupsClientCreateSharedGroup");
    HRESULT hr = PFSharedGroupsClientCreateSharedGroupAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsClientGetSharedGroupDataPrerequisiteClientCreateSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenSharedGroupsTests::TestSharedGroupsClientGetSharedGroupDataPrerequisiteClientUpdateSharedGroupData(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsUpdateSharedGroupDataRequestWrapper<> request;
    FillClientGetSharedGroupDataPrerequisiteUpdateSharedGroupDataRequest(request);
    LogUpdateSharedGroupDataRequest(&request.Model(), "TestSharedGroupsClientCreateSharedGroup");
    HRESULT hr = PFSharedGroupsClientUpdateSharedGroupDataAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsClientGetSharedGroupDataPrerequisiteClientUpdateSharedGroupDataAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenSharedGroupsTests::TestSharedGroupsClientGetSharedGroupData(TestContext& testContext)
{
    struct ClientGetSharedGroupDataResultHolderStruct : public GetSharedGroupDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFSharedGroupsClientGetSharedGroupDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFSharedGroupsClientGetSharedGroupDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFSharedGroupsGetSharedGroupDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFSharedGroupsGetSharedGroupDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientGetSharedGroupDataResultHolderStruct>>(testContext);

    PFSharedGroupsGetSharedGroupDataRequestWrapper<> request;
    FillGetSharedGroupDataRequest(request);
    LogGetSharedGroupDataRequest(&request.Model(), "TestSharedGroupsClientGetSharedGroupData");
    HRESULT hr = PFSharedGroupsClientGetSharedGroupDataAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsClientGetSharedGroupDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientRemoveSharedGroupMembers

void AutoGenSharedGroupsTests::TestSharedGroupsClientRemoveSharedGroupMembersPrerequisiteClientCreateSharedGroup(TestContext& testContext)
{
    struct ClientCreateSharedGroupResultHolderStruct : public CreateSharedGroupResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFSharedGroupsClientCreateSharedGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFSharedGroupsClientCreateSharedGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFSharedGroupsCreateSharedGroupResult(result);
            return StoreClientRemoveSharedGroupMembersPrerequisitePFSharedGroupsCreateSharedGroupResult(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientCreateSharedGroupResultHolderStruct>>(testContext);

    PFSharedGroupsCreateSharedGroupRequestWrapper<> request;
    FillClientRemoveSharedGroupMembersPrerequisiteCreateSharedGroupRequest(request);
    LogCreateSharedGroupRequest(&request.Model(), "TestSharedGroupsClientGetSharedGroupData");
    HRESULT hr = PFSharedGroupsClientCreateSharedGroupAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsClientRemoveSharedGroupMembersPrerequisiteClientCreateSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenSharedGroupsTests::TestSharedGroupsClientRemoveSharedGroupMembersPrerequisiteClientAddSharedGroupMembers(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsAddSharedGroupMembersRequestWrapper<> request;
    FillClientRemoveSharedGroupMembersPrerequisiteAddSharedGroupMembersRequest(request);
    LogAddSharedGroupMembersRequest(&request.Model(), "TestSharedGroupsClientGetSharedGroupData");
    HRESULT hr = PFSharedGroupsClientAddSharedGroupMembersAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsClientRemoveSharedGroupMembersPrerequisiteClientAddSharedGroupMembersAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenSharedGroupsTests::TestSharedGroupsClientRemoveSharedGroupMembers(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsRemoveSharedGroupMembersRequestWrapper<> request;
    FillRemoveSharedGroupMembersRequest(request);
    LogRemoveSharedGroupMembersRequest(&request.Model(), "TestSharedGroupsClientRemoveSharedGroupMembers");
    HRESULT hr = PFSharedGroupsClientRemoveSharedGroupMembersAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsClientRemoveSharedGroupMembersAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ClientUpdateSharedGroupData

void AutoGenSharedGroupsTests::TestSharedGroupsClientUpdateSharedGroupDataPrerequisiteClientCreateSharedGroup(TestContext& testContext)
{
    struct ClientCreateSharedGroupResultHolderStruct : public CreateSharedGroupResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFSharedGroupsClientCreateSharedGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFSharedGroupsClientCreateSharedGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFSharedGroupsCreateSharedGroupResult(result);
            return StoreClientUpdateSharedGroupDataPrerequisitePFSharedGroupsCreateSharedGroupResult(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientCreateSharedGroupResultHolderStruct>>(testContext);

    PFSharedGroupsCreateSharedGroupRequestWrapper<> request;
    FillClientUpdateSharedGroupDataPrerequisiteCreateSharedGroupRequest(request);
    LogCreateSharedGroupRequest(&request.Model(), "TestSharedGroupsClientRemoveSharedGroupMembers");
    HRESULT hr = PFSharedGroupsClientCreateSharedGroupAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsClientUpdateSharedGroupDataPrerequisiteClientCreateSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenSharedGroupsTests::TestSharedGroupsClientUpdateSharedGroupData(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsUpdateSharedGroupDataRequestWrapper<> request;
    FillUpdateSharedGroupDataRequest(request);
    LogUpdateSharedGroupDataRequest(&request.Model(), "TestSharedGroupsClientUpdateSharedGroupData");
    HRESULT hr = PFSharedGroupsClientUpdateSharedGroupDataAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsClientUpdateSharedGroupDataAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ServerAddSharedGroupMembers

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenSharedGroupsTests::TestSharedGroupsServerAddSharedGroupMembers(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsAddSharedGroupMembersRequestWrapper<> request;
    FillAddSharedGroupMembersRequest(request);
    LogAddSharedGroupMembersRequest(&request.Model(), "TestSharedGroupsServerAddSharedGroupMembers");
    HRESULT hr = PFSharedGroupsServerAddSharedGroupMembersAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerAddSharedGroupMembersAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerCreateSharedGroup

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenSharedGroupsTests::TestSharedGroupsServerCreateSharedGroup(TestContext& testContext)
{
    struct ServerCreateSharedGroupResultHolderStruct : public CreateSharedGroupResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFSharedGroupsServerCreateSharedGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFSharedGroupsServerCreateSharedGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFSharedGroupsCreateSharedGroupResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFSharedGroupsCreateSharedGroupResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerCreateSharedGroupResultHolderStruct>>(testContext);

    PFSharedGroupsCreateSharedGroupRequestWrapper<> request;
    FillCreateSharedGroupRequest(request);
    LogCreateSharedGroupRequest(&request.Model(), "TestSharedGroupsServerCreateSharedGroup");
    HRESULT hr = PFSharedGroupsServerCreateSharedGroupAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerCreateSharedGroupAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerDeleteSharedGroup

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenSharedGroupsTests::TestSharedGroupsServerDeleteSharedGroup(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsDeleteSharedGroupRequestWrapper<> request;
    FillDeleteSharedGroupRequest(request);
    LogDeleteSharedGroupRequest(&request.Model(), "TestSharedGroupsServerDeleteSharedGroup");
    HRESULT hr = PFSharedGroupsServerDeleteSharedGroupAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerDeleteSharedGroupAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerGetSharedGroupData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenSharedGroupsTests::TestSharedGroupsServerGetSharedGroupData(TestContext& testContext)
{
    struct ServerGetSharedGroupDataResultHolderStruct : public GetSharedGroupDataResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFSharedGroupsServerGetSharedGroupDataGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFSharedGroupsServerGetSharedGroupDataGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFSharedGroupsGetSharedGroupDataResult(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFSharedGroupsGetSharedGroupDataResult(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerGetSharedGroupDataResultHolderStruct>>(testContext);

    PFSharedGroupsGetSharedGroupDataRequestWrapper<> request;
    FillGetSharedGroupDataRequest(request);
    LogGetSharedGroupDataRequest(&request.Model(), "TestSharedGroupsServerGetSharedGroupData");
    HRESULT hr = PFSharedGroupsServerGetSharedGroupDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerGetSharedGroupDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerRemoveSharedGroupMembers

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenSharedGroupsTests::TestSharedGroupsServerRemoveSharedGroupMembers(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsRemoveSharedGroupMembersRequestWrapper<> request;
    FillRemoveSharedGroupMembersRequest(request);
    LogRemoveSharedGroupMembersRequest(&request.Model(), "TestSharedGroupsServerRemoveSharedGroupMembers");
    HRESULT hr = PFSharedGroupsServerRemoveSharedGroupMembersAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerRemoveSharedGroupMembersAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion

#pragma region ServerUpdateSharedGroupData

#if HC_PLATFORM != HC_PLATFORM_GDK
void AutoGenSharedGroupsTests::TestSharedGroupsServerUpdateSharedGroupData(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsUpdateSharedGroupDataRequestWrapper<> request;
    FillUpdateSharedGroupDataRequest(request);
    LogUpdateSharedGroupDataRequest(&request.Model(), "TestSharedGroupsServerUpdateSharedGroupData");
    HRESULT hr = PFSharedGroupsServerUpdateSharedGroupDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerUpdateSharedGroupDataAsync", hr);
        return;
    }
    async.release(); 
}
#endif

#pragma endregion


}
