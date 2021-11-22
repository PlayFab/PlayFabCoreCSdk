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
    AddTest("TestSharedGroupsClientAddSharedGroupMembersCleanupServerDeleteSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsClientAddSharedGroupMembersCleanupServerDeleteSharedGroup);

    AddTest("TestSharedGroupsClientCreateSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsClientCreateSharedGroup);
    AddTest("TestSharedGroupsClientCreateSharedGroupCleanupServerDeleteSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsClientCreateSharedGroupCleanupServerDeleteSharedGroup);

    AddTest("TestSharedGroupsClientGetSharedGroupDataPrerequisiteClientCreateSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsClientGetSharedGroupDataPrerequisiteClientCreateSharedGroup);
    AddTest("TestSharedGroupsClientGetSharedGroupDataPrerequisiteClientUpdateSharedGroupData", &AutoGenSharedGroupsTests::TestSharedGroupsClientGetSharedGroupDataPrerequisiteClientUpdateSharedGroupData);
    AddTest("TestSharedGroupsClientGetSharedGroupData", &AutoGenSharedGroupsTests::TestSharedGroupsClientGetSharedGroupData);
    AddTest("TestSharedGroupsClientGetSharedGroupDataCleanupServerDeleteSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsClientGetSharedGroupDataCleanupServerDeleteSharedGroup);

    AddTest("TestSharedGroupsClientRemoveSharedGroupMembersPrerequisiteClientCreateSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsClientRemoveSharedGroupMembersPrerequisiteClientCreateSharedGroup);
    AddTest("TestSharedGroupsClientRemoveSharedGroupMembersPrerequisiteClientAddSharedGroupMembers", &AutoGenSharedGroupsTests::TestSharedGroupsClientRemoveSharedGroupMembersPrerequisiteClientAddSharedGroupMembers);
    AddTest("TestSharedGroupsClientRemoveSharedGroupMembers", &AutoGenSharedGroupsTests::TestSharedGroupsClientRemoveSharedGroupMembers);
    AddTest("TestSharedGroupsClientRemoveSharedGroupMembersCleanupServerDeleteSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsClientRemoveSharedGroupMembersCleanupServerDeleteSharedGroup);

    AddTest("TestSharedGroupsClientUpdateSharedGroupDataPrerequisiteClientCreateSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsClientUpdateSharedGroupDataPrerequisiteClientCreateSharedGroup);
    AddTest("TestSharedGroupsClientUpdateSharedGroupData", &AutoGenSharedGroupsTests::TestSharedGroupsClientUpdateSharedGroupData);
    AddTest("TestSharedGroupsClientUpdateSharedGroupDataCleanupServerDeleteSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsClientUpdateSharedGroupDataCleanupServerDeleteSharedGroup);

    AddTest("TestSharedGroupsServerAddSharedGroupMembersPrerequisiteServerCreateSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsServerAddSharedGroupMembersPrerequisiteServerCreateSharedGroup);
    AddTest("TestSharedGroupsServerAddSharedGroupMembers", &AutoGenSharedGroupsTests::TestSharedGroupsServerAddSharedGroupMembers);
    AddTest("TestSharedGroupsServerAddSharedGroupMembersCleanupServerRemoveSharedGroupMembers", &AutoGenSharedGroupsTests::TestSharedGroupsServerAddSharedGroupMembersCleanupServerRemoveSharedGroupMembers);
    AddTest("TestSharedGroupsServerAddSharedGroupMembersCleanupServerDeleteSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsServerAddSharedGroupMembersCleanupServerDeleteSharedGroup);

    AddTest("TestSharedGroupsServerCreateSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsServerCreateSharedGroup);
    AddTest("TestSharedGroupsServerCreateSharedGroupCleanupServerDeleteSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsServerCreateSharedGroupCleanupServerDeleteSharedGroup);

    AddTest("TestSharedGroupsServerDeleteSharedGroupPrerequisiteServerCreateSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsServerDeleteSharedGroupPrerequisiteServerCreateSharedGroup);
    AddTest("TestSharedGroupsServerDeleteSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsServerDeleteSharedGroup);

    AddTest("TestSharedGroupsServerGetSharedGroupDataPrerequisiteClientCreateSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsServerGetSharedGroupDataPrerequisiteClientCreateSharedGroup);
    AddTest("TestSharedGroupsServerGetSharedGroupDataPrerequisiteServerUpdateSharedGroupData", &AutoGenSharedGroupsTests::TestSharedGroupsServerGetSharedGroupDataPrerequisiteServerUpdateSharedGroupData);
    AddTest("TestSharedGroupsServerGetSharedGroupData", &AutoGenSharedGroupsTests::TestSharedGroupsServerGetSharedGroupData);
    AddTest("TestSharedGroupsServerGetSharedGroupDataCleanupServerDeleteSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsServerGetSharedGroupDataCleanupServerDeleteSharedGroup);

    AddTest("TestSharedGroupsServerRemoveSharedGroupMembersPrerequisiteServerCreateSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsServerRemoveSharedGroupMembersPrerequisiteServerCreateSharedGroup);
    AddTest("TestSharedGroupsServerRemoveSharedGroupMembersPrerequisiteServerAddSharedGroupMembers", &AutoGenSharedGroupsTests::TestSharedGroupsServerRemoveSharedGroupMembersPrerequisiteServerAddSharedGroupMembers);
    AddTest("TestSharedGroupsServerRemoveSharedGroupMembers", &AutoGenSharedGroupsTests::TestSharedGroupsServerRemoveSharedGroupMembers);
    AddTest("TestSharedGroupsServerRemoveSharedGroupMembersCleanupServerDeleteSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsServerRemoveSharedGroupMembersCleanupServerDeleteSharedGroup);

    AddTest("TestSharedGroupsServerUpdateSharedGroupDataPrerequisiteServerCreateSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsServerUpdateSharedGroupDataPrerequisiteServerCreateSharedGroup);
    AddTest("TestSharedGroupsServerUpdateSharedGroupData", &AutoGenSharedGroupsTests::TestSharedGroupsServerUpdateSharedGroupData);
    AddTest("TestSharedGroupsServerUpdateSharedGroupDataCleanupServerDeleteSharedGroup", &AutoGenSharedGroupsTests::TestSharedGroupsServerUpdateSharedGroupDataCleanupServerDeleteSharedGroup);
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
    struct ClientCreateSharedGroupResultHolder : public CreateSharedGroupResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ClientCreateSharedGroupResultHolder>>(testContext);

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
void AutoGenSharedGroupsTests::TestSharedGroupsClientAddSharedGroupMembersCleanupServerDeleteSharedGroup(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsDeleteSharedGroupRequestWrapper<> request;
    FillClientAddSharedGroupMembersCleanupDeleteSharedGroupRequest(request);
    LogDeleteSharedGroupRequest(&request.Model(), "TestSharedGroupsClientAddSharedGroupMembersCleanupServerDeleteSharedGroup");
    HRESULT hr = PFSharedGroupsServerDeleteSharedGroupAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsClientAddSharedGroupMembersCleanupServerDeleteSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region ClientCreateSharedGroup

void AutoGenSharedGroupsTests::TestSharedGroupsClientCreateSharedGroup(TestContext& testContext)
{
    struct ClientCreateSharedGroupResultHolder : public CreateSharedGroupResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ClientCreateSharedGroupResultHolder>>(testContext);

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
void AutoGenSharedGroupsTests::TestSharedGroupsClientCreateSharedGroupCleanupServerDeleteSharedGroup(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsDeleteSharedGroupRequestWrapper<> request;
    FillClientCreateSharedGroupCleanupDeleteSharedGroupRequest(request);
    LogDeleteSharedGroupRequest(&request.Model(), "TestSharedGroupsClientCreateSharedGroupCleanupServerDeleteSharedGroup");
    HRESULT hr = PFSharedGroupsServerDeleteSharedGroupAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsClientCreateSharedGroupCleanupServerDeleteSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region ClientGetSharedGroupData

void AutoGenSharedGroupsTests::TestSharedGroupsClientGetSharedGroupDataPrerequisiteClientCreateSharedGroup(TestContext& testContext)
{
    struct ClientCreateSharedGroupResultHolder : public CreateSharedGroupResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ClientCreateSharedGroupResultHolder>>(testContext);

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
    struct ClientGetSharedGroupDataResultHolder : public GetSharedGroupDataResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ClientGetSharedGroupDataResultHolder>>(testContext);

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
void AutoGenSharedGroupsTests::TestSharedGroupsClientGetSharedGroupDataCleanupServerDeleteSharedGroup(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsDeleteSharedGroupRequestWrapper<> request;
    FillClientGetSharedGroupDataCleanupDeleteSharedGroupRequest(request);
    LogDeleteSharedGroupRequest(&request.Model(), "TestSharedGroupsClientGetSharedGroupDataCleanupServerDeleteSharedGroup");
    HRESULT hr = PFSharedGroupsServerDeleteSharedGroupAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsClientGetSharedGroupDataCleanupServerDeleteSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region ClientRemoveSharedGroupMembers

void AutoGenSharedGroupsTests::TestSharedGroupsClientRemoveSharedGroupMembersPrerequisiteClientCreateSharedGroup(TestContext& testContext)
{
    struct ClientCreateSharedGroupResultHolder : public CreateSharedGroupResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ClientCreateSharedGroupResultHolder>>(testContext);

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
void AutoGenSharedGroupsTests::TestSharedGroupsClientRemoveSharedGroupMembersCleanupServerDeleteSharedGroup(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsDeleteSharedGroupRequestWrapper<> request;
    FillClientRemoveSharedGroupMembersCleanupDeleteSharedGroupRequest(request);
    LogDeleteSharedGroupRequest(&request.Model(), "TestSharedGroupsClientRemoveSharedGroupMembersCleanupServerDeleteSharedGroup");
    HRESULT hr = PFSharedGroupsServerDeleteSharedGroupAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsClientRemoveSharedGroupMembersCleanupServerDeleteSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region ClientUpdateSharedGroupData

void AutoGenSharedGroupsTests::TestSharedGroupsClientUpdateSharedGroupDataPrerequisiteClientCreateSharedGroup(TestContext& testContext)
{
    struct ClientCreateSharedGroupResultHolder : public CreateSharedGroupResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ClientCreateSharedGroupResultHolder>>(testContext);

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
void AutoGenSharedGroupsTests::TestSharedGroupsClientUpdateSharedGroupDataCleanupServerDeleteSharedGroup(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsDeleteSharedGroupRequestWrapper<> request;
    FillClientUpdateSharedGroupDataCleanupDeleteSharedGroupRequest(request);
    LogDeleteSharedGroupRequest(&request.Model(), "TestSharedGroupsClientUpdateSharedGroupDataCleanupServerDeleteSharedGroup");
    HRESULT hr = PFSharedGroupsServerDeleteSharedGroupAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsClientUpdateSharedGroupDataCleanupServerDeleteSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region ServerAddSharedGroupMembers

void AutoGenSharedGroupsTests::TestSharedGroupsServerAddSharedGroupMembersPrerequisiteServerCreateSharedGroup(TestContext& testContext)
{
    struct ServerCreateSharedGroupResultHolder : public CreateSharedGroupResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFSharedGroupsServerCreateSharedGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFSharedGroupsServerCreateSharedGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFSharedGroupsCreateSharedGroupResult(result);
            return StoreServerAddSharedGroupMembersPrerequisitePFSharedGroupsCreateSharedGroupResult(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerCreateSharedGroupResultHolder>>(testContext);

    PFSharedGroupsCreateSharedGroupRequestWrapper<> request;
    FillServerAddSharedGroupMembersPrerequisiteCreateSharedGroupRequest(request);
    LogCreateSharedGroupRequest(&request.Model(), "TestSharedGroupsClientUpdateSharedGroupData");
    HRESULT hr = PFSharedGroupsServerCreateSharedGroupAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerAddSharedGroupMembersPrerequisiteServerCreateSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 
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
void AutoGenSharedGroupsTests::TestSharedGroupsServerAddSharedGroupMembersCleanupServerRemoveSharedGroupMembers(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsRemoveSharedGroupMembersRequestWrapper<> request;
    FillServerAddSharedGroupMembersCleanupRemoveSharedGroupMembersRequest(request);
    LogRemoveSharedGroupMembersRequest(&request.Model(), "TestSharedGroupsServerAddSharedGroupMembersCleanupServerRemoveSharedGroupMembers");
    HRESULT hr = PFSharedGroupsServerRemoveSharedGroupMembersAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerAddSharedGroupMembersCleanupServerRemoveSharedGroupMembersAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenSharedGroupsTests::TestSharedGroupsServerAddSharedGroupMembersCleanupServerDeleteSharedGroup(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsDeleteSharedGroupRequestWrapper<> request;
    FillServerAddSharedGroupMembersCleanupDeleteSharedGroupRequest(request);
    LogDeleteSharedGroupRequest(&request.Model(), "TestSharedGroupsServerAddSharedGroupMembersCleanupServerDeleteSharedGroup");
    HRESULT hr = PFSharedGroupsServerDeleteSharedGroupAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerAddSharedGroupMembersCleanupServerDeleteSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region ServerCreateSharedGroup

void AutoGenSharedGroupsTests::TestSharedGroupsServerCreateSharedGroup(TestContext& testContext)
{
    struct ServerCreateSharedGroupResultHolder : public CreateSharedGroupResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ServerCreateSharedGroupResultHolder>>(testContext);

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
void AutoGenSharedGroupsTests::TestSharedGroupsServerCreateSharedGroupCleanupServerDeleteSharedGroup(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsDeleteSharedGroupRequestWrapper<> request;
    FillServerCreateSharedGroupCleanupDeleteSharedGroupRequest(request);
    LogDeleteSharedGroupRequest(&request.Model(), "TestSharedGroupsServerCreateSharedGroupCleanupServerDeleteSharedGroup");
    HRESULT hr = PFSharedGroupsServerDeleteSharedGroupAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerCreateSharedGroupCleanupServerDeleteSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region ServerDeleteSharedGroup

void AutoGenSharedGroupsTests::TestSharedGroupsServerDeleteSharedGroupPrerequisiteServerCreateSharedGroup(TestContext& testContext)
{
    struct ServerCreateSharedGroupResultHolder : public CreateSharedGroupResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFSharedGroupsServerCreateSharedGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFSharedGroupsServerCreateSharedGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFSharedGroupsCreateSharedGroupResult(result);
            return StoreServerDeleteSharedGroupPrerequisitePFSharedGroupsCreateSharedGroupResult(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerCreateSharedGroupResultHolder>>(testContext);

    PFSharedGroupsCreateSharedGroupRequestWrapper<> request;
    FillServerDeleteSharedGroupPrerequisiteCreateSharedGroupRequest(request);
    LogCreateSharedGroupRequest(&request.Model(), "TestSharedGroupsServerCreateSharedGroup");
    HRESULT hr = PFSharedGroupsServerCreateSharedGroupAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerDeleteSharedGroupPrerequisiteServerCreateSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 
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

#pragma endregion

#pragma region ServerGetSharedGroupData

void AutoGenSharedGroupsTests::TestSharedGroupsServerGetSharedGroupDataPrerequisiteClientCreateSharedGroup(TestContext& testContext)
{
    struct ClientCreateSharedGroupResultHolder : public CreateSharedGroupResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFSharedGroupsClientCreateSharedGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFSharedGroupsClientCreateSharedGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFSharedGroupsCreateSharedGroupResult(result);
            return StoreServerGetSharedGroupDataPrerequisitePFSharedGroupsCreateSharedGroupResult(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<ClientCreateSharedGroupResultHolder>>(testContext);

    PFSharedGroupsCreateSharedGroupRequestWrapper<> request;
    FillServerGetSharedGroupDataPrerequisiteCreateSharedGroupRequest(request);
    LogCreateSharedGroupRequest(&request.Model(), "TestSharedGroupsServerDeleteSharedGroup");
    HRESULT hr = PFSharedGroupsClientCreateSharedGroupAsync(titlePlayerHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerGetSharedGroupDataPrerequisiteClientCreateSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenSharedGroupsTests::TestSharedGroupsServerGetSharedGroupDataPrerequisiteServerUpdateSharedGroupData(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsUpdateSharedGroupDataRequestWrapper<> request;
    FillServerGetSharedGroupDataPrerequisiteUpdateSharedGroupDataRequest(request);
    LogUpdateSharedGroupDataRequest(&request.Model(), "TestSharedGroupsServerDeleteSharedGroup");
    HRESULT hr = PFSharedGroupsServerUpdateSharedGroupDataAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerGetSharedGroupDataPrerequisiteServerUpdateSharedGroupDataAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenSharedGroupsTests::TestSharedGroupsServerGetSharedGroupData(TestContext& testContext)
{
    struct ServerGetSharedGroupDataResultHolder : public GetSharedGroupDataResultHolder
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
    auto async = std::make_unique<XAsyncHelper<ServerGetSharedGroupDataResultHolder>>(testContext);

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
void AutoGenSharedGroupsTests::TestSharedGroupsServerGetSharedGroupDataCleanupServerDeleteSharedGroup(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsDeleteSharedGroupRequestWrapper<> request;
    FillServerGetSharedGroupDataCleanupDeleteSharedGroupRequest(request);
    LogDeleteSharedGroupRequest(&request.Model(), "TestSharedGroupsServerGetSharedGroupDataCleanupServerDeleteSharedGroup");
    HRESULT hr = PFSharedGroupsServerDeleteSharedGroupAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerGetSharedGroupDataCleanupServerDeleteSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region ServerRemoveSharedGroupMembers

void AutoGenSharedGroupsTests::TestSharedGroupsServerRemoveSharedGroupMembersPrerequisiteServerCreateSharedGroup(TestContext& testContext)
{
    struct ServerCreateSharedGroupResultHolder : public CreateSharedGroupResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFSharedGroupsServerCreateSharedGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFSharedGroupsServerCreateSharedGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFSharedGroupsCreateSharedGroupResult(result);
            return StoreServerRemoveSharedGroupMembersPrerequisitePFSharedGroupsCreateSharedGroupResult(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerCreateSharedGroupResultHolder>>(testContext);

    PFSharedGroupsCreateSharedGroupRequestWrapper<> request;
    FillServerRemoveSharedGroupMembersPrerequisiteCreateSharedGroupRequest(request);
    LogCreateSharedGroupRequest(&request.Model(), "TestSharedGroupsServerGetSharedGroupData");
    HRESULT hr = PFSharedGroupsServerCreateSharedGroupAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerRemoveSharedGroupMembersPrerequisiteServerCreateSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenSharedGroupsTests::TestSharedGroupsServerRemoveSharedGroupMembersPrerequisiteServerAddSharedGroupMembers(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsAddSharedGroupMembersRequestWrapper<> request;
    FillServerRemoveSharedGroupMembersPrerequisiteAddSharedGroupMembersRequest(request);
    LogAddSharedGroupMembersRequest(&request.Model(), "TestSharedGroupsServerGetSharedGroupData");
    HRESULT hr = PFSharedGroupsServerAddSharedGroupMembersAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerRemoveSharedGroupMembersPrerequisiteServerAddSharedGroupMembersAsync", hr);
        return;
    }
    async.release(); 
} 
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
void AutoGenSharedGroupsTests::TestSharedGroupsServerRemoveSharedGroupMembersCleanupServerDeleteSharedGroup(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsDeleteSharedGroupRequestWrapper<> request;
    FillServerRemoveSharedGroupMembersCleanupDeleteSharedGroupRequest(request);
    LogDeleteSharedGroupRequest(&request.Model(), "TestSharedGroupsServerRemoveSharedGroupMembersCleanupServerDeleteSharedGroup");
    HRESULT hr = PFSharedGroupsServerDeleteSharedGroupAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerRemoveSharedGroupMembersCleanupServerDeleteSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region ServerUpdateSharedGroupData

void AutoGenSharedGroupsTests::TestSharedGroupsServerUpdateSharedGroupDataPrerequisiteServerCreateSharedGroup(TestContext& testContext)
{
    struct ServerCreateSharedGroupResultHolder : public CreateSharedGroupResultHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFSharedGroupsServerCreateSharedGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFSharedGroupsServerCreateSharedGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFSharedGroupsCreateSharedGroupResult(result);
            return StoreServerUpdateSharedGroupDataPrerequisitePFSharedGroupsCreateSharedGroupResult(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<ServerCreateSharedGroupResultHolder>>(testContext);

    PFSharedGroupsCreateSharedGroupRequestWrapper<> request;
    FillServerUpdateSharedGroupDataPrerequisiteCreateSharedGroupRequest(request);
    LogCreateSharedGroupRequest(&request.Model(), "TestSharedGroupsServerRemoveSharedGroupMembers");
    HRESULT hr = PFSharedGroupsServerCreateSharedGroupAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerUpdateSharedGroupDataPrerequisiteServerCreateSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 
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
void AutoGenSharedGroupsTests::TestSharedGroupsServerUpdateSharedGroupDataCleanupServerDeleteSharedGroup(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFSharedGroupsDeleteSharedGroupRequestWrapper<> request;
    FillServerUpdateSharedGroupDataCleanupDeleteSharedGroupRequest(request);
    LogDeleteSharedGroupRequest(&request.Model(), "TestSharedGroupsServerUpdateSharedGroupDataCleanupServerDeleteSharedGroup");
    HRESULT hr = PFSharedGroupsServerDeleteSharedGroupAsync(stateHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFSharedGroupsSharedGroupsServerUpdateSharedGroupDataCleanupServerDeleteSharedGroupAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion


}
