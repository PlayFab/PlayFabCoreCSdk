#include "TestAppPch.h"
#include "TestContext.h"
#include "TestApp.h"
#include "AutoGenGroupsTests.h"
#include "XAsyncHelper.h"
#include "playfab/PFAuthentication.h"

namespace PlayFabUnit
{

using namespace PlayFab::Wrappers;

AutoGenGroupsTests::GroupsTestData AutoGenGroupsTests::testData;

void AutoGenGroupsTests::Log(std::stringstream& ss)
{
    TestApp::LogPut(ss.str().c_str());
    ss.str(std::string());
    ss.clear();
}

HRESULT AutoGenGroupsTests::LogHR(HRESULT hr)
{
    if (TestApp::ShouldTrace(PFTestTraceLevel::Information))
    {
        TestApp::Log("Result: 0x%0.8x", hr);
    }

    return hr;
}

void AutoGenGroupsTests::AddTests()
{
    // Generated tests 
    AddTest("TestGroupsAcceptGroupApplicationPrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsAcceptGroupApplicationPrerequisiteGetGroup);
    AddTest("TestGroupsAcceptGroupApplicationPrerequisiteApplyToGroup", &AutoGenGroupsTests::TestGroupsAcceptGroupApplicationPrerequisiteApplyToGroup);
    AddTest("TestGroupsAcceptGroupApplication", &AutoGenGroupsTests::TestGroupsAcceptGroupApplication);
    AddTest("TestGroupsAcceptGroupApplicationCleanupRemoveMembers", &AutoGenGroupsTests::TestGroupsAcceptGroupApplicationCleanupRemoveMembers);

    AddTest("TestGroupsAcceptGroupInvitationPrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsAcceptGroupInvitationPrerequisiteGetGroup);
    AddTest("TestGroupsAcceptGroupInvitationPrerequisiteInviteToGroup", &AutoGenGroupsTests::TestGroupsAcceptGroupInvitationPrerequisiteInviteToGroup);
    AddTest("TestGroupsAcceptGroupInvitation", &AutoGenGroupsTests::TestGroupsAcceptGroupInvitation);
    AddTest("TestGroupsAcceptGroupInvitationCleanupRemoveMembers", &AutoGenGroupsTests::TestGroupsAcceptGroupInvitationCleanupRemoveMembers);

    AddTest("TestGroupsAddMembersPrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsAddMembersPrerequisiteGetGroup);
    AddTest("TestGroupsAddMembers", &AutoGenGroupsTests::TestGroupsAddMembers);
    AddTest("TestGroupsAddMembersCleanupRemoveMembers", &AutoGenGroupsTests::TestGroupsAddMembersCleanupRemoveMembers);

    AddTest("TestGroupsApplyToGroupPrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsApplyToGroupPrerequisiteGetGroup);
    AddTest("TestGroupsApplyToGroup", &AutoGenGroupsTests::TestGroupsApplyToGroup);
    AddTest("TestGroupsApplyToGroupCleanupRemoveGroupApplication", &AutoGenGroupsTests::TestGroupsApplyToGroupCleanupRemoveGroupApplication);

    AddTest("TestGroupsBlockEntityPrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsBlockEntityPrerequisiteGetGroup);
    AddTest("TestGroupsBlockEntity", &AutoGenGroupsTests::TestGroupsBlockEntity);
    AddTest("TestGroupsBlockEntityCleanupUnblockEntity", &AutoGenGroupsTests::TestGroupsBlockEntityCleanupUnblockEntity);

    AddTest("TestGroupsChangeMemberRolePrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsChangeMemberRolePrerequisiteGetGroup);
    AddTest("TestGroupsChangeMemberRole", &AutoGenGroupsTests::TestGroupsChangeMemberRole);
    AddTest("TestGroupsChangeMemberRoleCleanupChangeMemberRole", &AutoGenGroupsTests::TestGroupsChangeMemberRoleCleanupChangeMemberRole);

    AddTest("TestGroupsCreateGroup", &AutoGenGroupsTests::TestGroupsCreateGroup);
    AddTest("TestGroupsCreateGroupCleanupGetGroup", &AutoGenGroupsTests::TestGroupsCreateGroupCleanupGetGroup);
    AddTest("TestGroupsCreateGroupCleanupDeleteGroup", &AutoGenGroupsTests::TestGroupsCreateGroupCleanupDeleteGroup);

    AddTest("TestGroupsCreateRolePrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsCreateRolePrerequisiteGetGroup);
    AddTest("TestGroupsCreateRole", &AutoGenGroupsTests::TestGroupsCreateRole);
    AddTest("TestGroupsCreateRoleCleanupDeleteRole", &AutoGenGroupsTests::TestGroupsCreateRoleCleanupDeleteRole);

    AddTest("TestGroupsDeleteGroupPrerequisiteCreateGroup", &AutoGenGroupsTests::TestGroupsDeleteGroupPrerequisiteCreateGroup);
    AddTest("TestGroupsDeleteGroup", &AutoGenGroupsTests::TestGroupsDeleteGroup);

    AddTest("TestGroupsDeleteRolePrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsDeleteRolePrerequisiteGetGroup);
    AddTest("TestGroupsDeleteRolePrerequisiteCreateRole", &AutoGenGroupsTests::TestGroupsDeleteRolePrerequisiteCreateRole);
    AddTest("TestGroupsDeleteRole", &AutoGenGroupsTests::TestGroupsDeleteRole);

    AddTest("TestGroupsGetGroup", &AutoGenGroupsTests::TestGroupsGetGroup);

    AddTest("TestGroupsInviteToGroupPrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsInviteToGroupPrerequisiteGetGroup);
    AddTest("TestGroupsInviteToGroup", &AutoGenGroupsTests::TestGroupsInviteToGroup);
    AddTest("TestGroupsInviteToGroupCleanupRemoveGroupInvitation", &AutoGenGroupsTests::TestGroupsInviteToGroupCleanupRemoveGroupInvitation);

    AddTest("TestGroupsIsMemberPrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsIsMemberPrerequisiteGetGroup);
    AddTest("TestGroupsIsMember", &AutoGenGroupsTests::TestGroupsIsMember);

    AddTest("TestGroupsListGroupApplicationsPrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsListGroupApplicationsPrerequisiteGetGroup);
    AddTest("TestGroupsListGroupApplications", &AutoGenGroupsTests::TestGroupsListGroupApplications);

    AddTest("TestGroupsListGroupBlocksPrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsListGroupBlocksPrerequisiteGetGroup);
    AddTest("TestGroupsListGroupBlocks", &AutoGenGroupsTests::TestGroupsListGroupBlocks);

    AddTest("TestGroupsListGroupInvitationsPrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsListGroupInvitationsPrerequisiteGetGroup);
    AddTest("TestGroupsListGroupInvitations", &AutoGenGroupsTests::TestGroupsListGroupInvitations);

    AddTest("TestGroupsListGroupMembersPrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsListGroupMembersPrerequisiteGetGroup);
    AddTest("TestGroupsListGroupMembers", &AutoGenGroupsTests::TestGroupsListGroupMembers);

    AddTest("TestGroupsListMembershipPrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsListMembershipPrerequisiteGetGroup);
    AddTest("TestGroupsListMembership", &AutoGenGroupsTests::TestGroupsListMembership);

    AddTest("TestGroupsListMembershipOpportunitiesPrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsListMembershipOpportunitiesPrerequisiteGetGroup);
    AddTest("TestGroupsListMembershipOpportunitiesPrerequisiteApplyToGroup", &AutoGenGroupsTests::TestGroupsListMembershipOpportunitiesPrerequisiteApplyToGroup);
    AddTest("TestGroupsListMembershipOpportunities", &AutoGenGroupsTests::TestGroupsListMembershipOpportunities);
    AddTest("TestGroupsListMembershipOpportunitiesCleanupRemoveGroupApplication", &AutoGenGroupsTests::TestGroupsListMembershipOpportunitiesCleanupRemoveGroupApplication);

    AddTest("TestGroupsRemoveGroupApplicationPrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsRemoveGroupApplicationPrerequisiteGetGroup);
    AddTest("TestGroupsRemoveGroupApplicationPrerequisiteApplyToGroup", &AutoGenGroupsTests::TestGroupsRemoveGroupApplicationPrerequisiteApplyToGroup);
    AddTest("TestGroupsRemoveGroupApplication", &AutoGenGroupsTests::TestGroupsRemoveGroupApplication);

    AddTest("TestGroupsRemoveGroupInvitationPrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsRemoveGroupInvitationPrerequisiteGetGroup);
    AddTest("TestGroupsRemoveGroupInvitationPrerequisiteInviteToGroup", &AutoGenGroupsTests::TestGroupsRemoveGroupInvitationPrerequisiteInviteToGroup);
    AddTest("TestGroupsRemoveGroupInvitation", &AutoGenGroupsTests::TestGroupsRemoveGroupInvitation);

    AddTest("TestGroupsRemoveMembersPrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsRemoveMembersPrerequisiteGetGroup);
    AddTest("TestGroupsRemoveMembersPrerequisiteAddMembers", &AutoGenGroupsTests::TestGroupsRemoveMembersPrerequisiteAddMembers);
    AddTest("TestGroupsRemoveMembers", &AutoGenGroupsTests::TestGroupsRemoveMembers);

    AddTest("TestGroupsUnblockEntityPrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsUnblockEntityPrerequisiteGetGroup);
    AddTest("TestGroupsUnblockEntityPrerequisiteBlockEntity", &AutoGenGroupsTests::TestGroupsUnblockEntityPrerequisiteBlockEntity);
    AddTest("TestGroupsUnblockEntity", &AutoGenGroupsTests::TestGroupsUnblockEntity);

    AddTest("TestGroupsUpdateGroupPrerequisiteCreateGroup", &AutoGenGroupsTests::TestGroupsUpdateGroupPrerequisiteCreateGroup);
    AddTest("TestGroupsUpdateGroup", &AutoGenGroupsTests::TestGroupsUpdateGroup);
    AddTest("TestGroupsUpdateGroupCleanupDeleteGroup", &AutoGenGroupsTests::TestGroupsUpdateGroupCleanupDeleteGroup);

    AddTest("TestGroupsUpdateRolePrerequisiteGetGroup", &AutoGenGroupsTests::TestGroupsUpdateRolePrerequisiteGetGroup);
    AddTest("TestGroupsUpdateRolePrerequisiteUpdateRole", &AutoGenGroupsTests::TestGroupsUpdateRolePrerequisiteUpdateRole);
    AddTest("TestGroupsUpdateRole", &AutoGenGroupsTests::TestGroupsUpdateRole);
}

void AutoGenGroupsTests::ClassSetUp()
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

void AutoGenGroupsTests::ClassTearDown()
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

void AutoGenGroupsTests::SetUp(TestContext& testContext)
{
    if (!entityHandle)
    {
        testContext.Skip("Skipping test because login failed");
    }


}

#pragma region AcceptGroupApplication

void AutoGenGroupsTests::TestGroupsAcceptGroupApplicationPrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreAcceptGroupApplicationPrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillAcceptGroupApplicationPrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsAcceptGroupApplicationPrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsAcceptGroupApplicationPrerequisiteApplyToGroup(TestContext& testContext)
{
    struct ApplyToGroupResultHolderStruct : public ApplyToGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsApplyToGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsApplyToGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreAcceptGroupApplicationPrerequisiteApplyToGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<ApplyToGroupResultHolderStruct>>(testContext);

    PFGroupsApplyToGroupRequestWrapper<> request;
    FillAcceptGroupApplicationPrerequisiteApplyToGroupRequest(request);
    HRESULT hr = PFGroupsApplyToGroupAsync(entityHandle2, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsAcceptGroupApplicationPrerequisiteApplyToGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsAcceptGroupApplication(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsAcceptGroupApplicationRequestWrapper<> request;
    FillAcceptGroupApplicationRequest(request);
    LogAcceptGroupApplicationRequest(&request.Model(), "TestGroupsAcceptGroupApplication");
    HRESULT hr = PFGroupsAcceptGroupApplicationAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsAcceptGroupApplicationAsync", hr);
        return;
    }
    async.release(); 
}
void AutoGenGroupsTests::TestGroupsAcceptGroupApplicationCleanupRemoveMembers(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsRemoveMembersRequestWrapper<> request;
    FillAcceptGroupApplicationCleanupRemoveMembersRequest(request);
    HRESULT hr = PFGroupsRemoveMembersAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsAcceptGroupApplicationCleanupRemoveMembersAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region AcceptGroupInvitation

void AutoGenGroupsTests::TestGroupsAcceptGroupInvitationPrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreAcceptGroupInvitationPrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillAcceptGroupInvitationPrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsAcceptGroupInvitationPrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsAcceptGroupInvitationPrerequisiteInviteToGroup(TestContext& testContext)
{
    struct InviteToGroupResultHolderStruct : public InviteToGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsInviteToGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsInviteToGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreAcceptGroupInvitationPrerequisiteInviteToGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<InviteToGroupResultHolderStruct>>(testContext);

    PFGroupsInviteToGroupRequestWrapper<> request;
    FillAcceptGroupInvitationPrerequisiteInviteToGroupRequest(request);
    HRESULT hr = PFGroupsInviteToGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsAcceptGroupInvitationPrerequisiteInviteToGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsAcceptGroupInvitation(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsAcceptGroupInvitationRequestWrapper<> request;
    FillAcceptGroupInvitationRequest(request);
    LogAcceptGroupInvitationRequest(&request.Model(), "TestGroupsAcceptGroupInvitation");
    HRESULT hr = PFGroupsAcceptGroupInvitationAsync(entityHandle2, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsAcceptGroupInvitationAsync", hr);
        return;
    }
    async.release(); 
}
void AutoGenGroupsTests::TestGroupsAcceptGroupInvitationCleanupRemoveMembers(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsRemoveMembersRequestWrapper<> request;
    FillAcceptGroupInvitationCleanupRemoveMembersRequest(request);
    HRESULT hr = PFGroupsRemoveMembersAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsAcceptGroupInvitationCleanupRemoveMembersAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region AddMembers

void AutoGenGroupsTests::TestGroupsAddMembersPrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreAddMembersPrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillAddMembersPrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsAddMembersPrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsAddMembers(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsAddMembersRequestWrapper<> request;
    FillAddMembersRequest(request);
    LogAddMembersRequest(&request.Model(), "TestGroupsAddMembers");
    HRESULT hr = PFGroupsAddMembersAsync(titleEntityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsAddMembersAsync", hr);
        return;
    }
    async.release(); 
}
void AutoGenGroupsTests::TestGroupsAddMembersCleanupRemoveMembers(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsRemoveMembersRequestWrapper<> request;
    FillAddMembersCleanupRemoveMembersRequest(request);
    HRESULT hr = PFGroupsRemoveMembersAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsAddMembersCleanupRemoveMembersAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region ApplyToGroup

void AutoGenGroupsTests::TestGroupsApplyToGroupPrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreApplyToGroupPrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillApplyToGroupPrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsApplyToGroupPrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsApplyToGroup(TestContext& testContext)
{
    struct ApplyToGroupResultHolderStruct : public ApplyToGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsApplyToGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsApplyToGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogApplyToGroupResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateApplyToGroupResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ApplyToGroupResultHolderStruct>>(testContext);

    PFGroupsApplyToGroupRequestWrapper<> request;
    FillApplyToGroupRequest(request);
    LogApplyToGroupRequest(&request.Model(), "TestGroupsApplyToGroup");
    HRESULT hr = PFGroupsApplyToGroupAsync(entityHandle2, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsApplyToGroupAsync", hr);
        return;
    }
    async.release(); 
}
void AutoGenGroupsTests::TestGroupsApplyToGroupCleanupRemoveGroupApplication(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsRemoveGroupApplicationRequestWrapper<> request;
    FillApplyToGroupCleanupRemoveGroupApplicationRequest(request);
    HRESULT hr = PFGroupsRemoveGroupApplicationAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsApplyToGroupCleanupRemoveGroupApplicationAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region BlockEntity

void AutoGenGroupsTests::TestGroupsBlockEntityPrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreBlockEntityPrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillBlockEntityPrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsBlockEntityPrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsBlockEntity(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsBlockEntityRequestWrapper<> request;
    FillBlockEntityRequest(request);
    LogBlockEntityRequest(&request.Model(), "TestGroupsBlockEntity");
    HRESULT hr = PFGroupsBlockEntityAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsBlockEntityAsync", hr);
        return;
    }
    async.release(); 
}
void AutoGenGroupsTests::TestGroupsBlockEntityCleanupUnblockEntity(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsUnblockEntityRequestWrapper<> request;
    FillBlockEntityCleanupUnblockEntityRequest(request);
    HRESULT hr = PFGroupsUnblockEntityAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsBlockEntityCleanupUnblockEntityAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region ChangeMemberRole

void AutoGenGroupsTests::TestGroupsChangeMemberRolePrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreChangeMemberRolePrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillChangeMemberRolePrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsChangeMemberRolePrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsChangeMemberRole(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsChangeMemberRoleRequestWrapper<> request;
    FillChangeMemberRoleRequest(request);
    LogChangeMemberRoleRequest(&request.Model(), "TestGroupsChangeMemberRole");
    HRESULT hr = PFGroupsChangeMemberRoleAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsChangeMemberRoleAsync", hr);
        return;
    }
    async.release(); 
}
void AutoGenGroupsTests::TestGroupsChangeMemberRoleCleanupChangeMemberRole(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsChangeMemberRoleRequestWrapper<> request;
    FillChangeMemberRoleCleanupChangeMemberRoleRequest(request);
    HRESULT hr = PFGroupsChangeMemberRoleAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsChangeMemberRoleCleanupChangeMemberRoleAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region CreateGroup

void AutoGenGroupsTests::TestGroupsCreateGroup(TestContext& testContext)
{
    struct CreateGroupResultHolderStruct : public CreateGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsCreateGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsCreateGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogCreateGroupResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateCreateGroupResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateGroupResultHolderStruct>>(testContext);

    PFGroupsCreateGroupRequestWrapper<> request;
    FillCreateGroupRequest(request);
    LogCreateGroupRequest(&request.Model(), "TestGroupsCreateGroup");
    HRESULT hr = PFGroupsCreateGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsCreateGroupAsync", hr);
        return;
    }
    async.release(); 
}
void AutoGenGroupsTests::TestGroupsCreateGroupCleanupGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreCreateGroupCleanupGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillCreateGroupCleanupGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsCreateGroupCleanupGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsCreateGroupCleanupDeleteGroup(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsDeleteGroupRequestWrapper<> request;
    FillCreateGroupCleanupDeleteGroupRequest(request);
    HRESULT hr = PFGroupsDeleteGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsCreateGroupCleanupDeleteGroupAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region CreateRole

void AutoGenGroupsTests::TestGroupsCreateRolePrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreCreateRolePrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillCreateRolePrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsCreateRolePrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsCreateRole(TestContext& testContext)
{
    struct CreateRoleResultHolderStruct : public CreateGroupRoleResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsCreateRoleGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsCreateRoleGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogCreateGroupRoleResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateCreateRoleResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateRoleResultHolderStruct>>(testContext);

    PFGroupsCreateGroupRoleRequestWrapper<> request;
    FillCreateRoleRequest(request);
    LogCreateGroupRoleRequest(&request.Model(), "TestGroupsCreateRole");
    HRESULT hr = PFGroupsCreateRoleAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsCreateRoleAsync", hr);
        return;
    }
    async.release(); 
}
void AutoGenGroupsTests::TestGroupsCreateRoleCleanupDeleteRole(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsDeleteRoleRequestWrapper<> request;
    FillCreateRoleCleanupDeleteRoleRequest(request);
    HRESULT hr = PFGroupsDeleteRoleAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsCreateRoleCleanupDeleteRoleAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region DeleteGroup

void AutoGenGroupsTests::TestGroupsDeleteGroupPrerequisiteCreateGroup(TestContext& testContext)
{
    struct CreateGroupResultHolderStruct : public CreateGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsCreateGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsCreateGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreDeleteGroupPrerequisiteCreateGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateGroupResultHolderStruct>>(testContext);

    PFGroupsCreateGroupRequestWrapper<> request;
    FillDeleteGroupPrerequisiteCreateGroupRequest(request);
    HRESULT hr = PFGroupsCreateGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsDeleteGroupPrerequisiteCreateGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsDeleteGroup(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsDeleteGroupRequestWrapper<> request;
    FillDeleteGroupRequest(request);
    LogDeleteGroupRequest(&request.Model(), "TestGroupsDeleteGroup");
    HRESULT hr = PFGroupsDeleteGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsDeleteGroupAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region DeleteRole

void AutoGenGroupsTests::TestGroupsDeleteRolePrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreDeleteRolePrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillDeleteRolePrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsDeleteRolePrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsDeleteRolePrerequisiteCreateRole(TestContext& testContext)
{
    struct CreateRoleResultHolderStruct : public CreateGroupRoleResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsCreateRoleGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsCreateRoleGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreDeleteRolePrerequisiteCreateRoleResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateRoleResultHolderStruct>>(testContext);

    PFGroupsCreateGroupRoleRequestWrapper<> request;
    FillDeleteRolePrerequisiteCreateRoleRequest(request);
    HRESULT hr = PFGroupsCreateRoleAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsDeleteRolePrerequisiteCreateRoleAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsDeleteRole(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsDeleteRoleRequestWrapper<> request;
    FillDeleteRoleRequest(request);
    LogDeleteRoleRequest(&request.Model(), "TestGroupsDeleteRole");
    HRESULT hr = PFGroupsDeleteRoleAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsDeleteRoleAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region GetGroup

void AutoGenGroupsTests::TestGroupsGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogGetGroupResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateGetGroupResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsGetGroup");
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsGetGroupAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region InviteToGroup

void AutoGenGroupsTests::TestGroupsInviteToGroupPrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreInviteToGroupPrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillInviteToGroupPrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsInviteToGroupPrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsInviteToGroup(TestContext& testContext)
{
    struct InviteToGroupResultHolderStruct : public InviteToGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsInviteToGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsInviteToGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogInviteToGroupResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateInviteToGroupResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<InviteToGroupResultHolderStruct>>(testContext);

    PFGroupsInviteToGroupRequestWrapper<> request;
    FillInviteToGroupRequest(request);
    LogInviteToGroupRequest(&request.Model(), "TestGroupsInviteToGroup");
    HRESULT hr = PFGroupsInviteToGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsInviteToGroupAsync", hr);
        return;
    }
    async.release(); 
}
void AutoGenGroupsTests::TestGroupsInviteToGroupCleanupRemoveGroupInvitation(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsRemoveGroupInvitationRequestWrapper<> request;
    FillInviteToGroupCleanupRemoveGroupInvitationRequest(request);
    HRESULT hr = PFGroupsRemoveGroupInvitationAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsInviteToGroupCleanupRemoveGroupInvitationAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region IsMember

void AutoGenGroupsTests::TestGroupsIsMemberPrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreIsMemberPrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillIsMemberPrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsIsMemberPrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsIsMember(TestContext& testContext)
{
    struct IsMemberResultHolderStruct : public IsMemberResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFGroupsIsMemberGetResult(async, &result)));
            LogIsMemberResponse(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateIsMemberResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<IsMemberResultHolderStruct>>(testContext);

    PFGroupsIsMemberRequestWrapper<> request;
    FillIsMemberRequest(request);
    LogIsMemberRequest(&request.Model(), "TestGroupsIsMember");
    HRESULT hr = PFGroupsIsMemberAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsIsMemberAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ListGroupApplications

void AutoGenGroupsTests::TestGroupsListGroupApplicationsPrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreListGroupApplicationsPrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillListGroupApplicationsPrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsListGroupApplicationsPrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsListGroupApplications(TestContext& testContext)
{
    struct ListGroupApplicationsResultHolderStruct : public ListGroupApplicationsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsListGroupApplicationsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsListGroupApplicationsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListGroupApplicationsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListGroupApplicationsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListGroupApplicationsResultHolderStruct>>(testContext);

    PFGroupsListGroupApplicationsRequestWrapper<> request;
    FillListGroupApplicationsRequest(request);
    LogListGroupApplicationsRequest(&request.Model(), "TestGroupsListGroupApplications");
    HRESULT hr = PFGroupsListGroupApplicationsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsListGroupApplicationsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ListGroupBlocks

void AutoGenGroupsTests::TestGroupsListGroupBlocksPrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreListGroupBlocksPrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillListGroupBlocksPrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsListGroupBlocksPrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsListGroupBlocks(TestContext& testContext)
{
    struct ListGroupBlocksResultHolderStruct : public ListGroupBlocksResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsListGroupBlocksGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsListGroupBlocksGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListGroupBlocksResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListGroupBlocksResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListGroupBlocksResultHolderStruct>>(testContext);

    PFGroupsListGroupBlocksRequestWrapper<> request;
    FillListGroupBlocksRequest(request);
    LogListGroupBlocksRequest(&request.Model(), "TestGroupsListGroupBlocks");
    HRESULT hr = PFGroupsListGroupBlocksAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsListGroupBlocksAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ListGroupInvitations

void AutoGenGroupsTests::TestGroupsListGroupInvitationsPrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreListGroupInvitationsPrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillListGroupInvitationsPrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsListGroupInvitationsPrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsListGroupInvitations(TestContext& testContext)
{
    struct ListGroupInvitationsResultHolderStruct : public ListGroupInvitationsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsListGroupInvitationsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsListGroupInvitationsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListGroupInvitationsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListGroupInvitationsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListGroupInvitationsResultHolderStruct>>(testContext);

    PFGroupsListGroupInvitationsRequestWrapper<> request;
    FillListGroupInvitationsRequest(request);
    LogListGroupInvitationsRequest(&request.Model(), "TestGroupsListGroupInvitations");
    HRESULT hr = PFGroupsListGroupInvitationsAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsListGroupInvitationsAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ListGroupMembers

void AutoGenGroupsTests::TestGroupsListGroupMembersPrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreListGroupMembersPrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillListGroupMembersPrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsListGroupMembersPrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsListGroupMembers(TestContext& testContext)
{
    struct ListGroupMembersResultHolderStruct : public ListGroupMembersResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsListGroupMembersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsListGroupMembersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListGroupMembersResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListGroupMembersResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListGroupMembersResultHolderStruct>>(testContext);

    PFGroupsListGroupMembersRequestWrapper<> request;
    FillListGroupMembersRequest(request);
    LogListGroupMembersRequest(&request.Model(), "TestGroupsListGroupMembers");
    HRESULT hr = PFGroupsListGroupMembersAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsListGroupMembersAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ListMembership

void AutoGenGroupsTests::TestGroupsListMembershipPrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreListMembershipPrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillListMembershipPrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsListMembershipPrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsListMembership(TestContext& testContext)
{
    struct ListMembershipResultHolderStruct : public ListMembershipResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsListMembershipGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsListMembershipGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListMembershipResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListMembershipResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListMembershipResultHolderStruct>>(testContext);

    PFGroupsListMembershipRequestWrapper<> request;
    FillListMembershipRequest(request);
    LogListMembershipRequest(&request.Model(), "TestGroupsListMembership");
    HRESULT hr = PFGroupsListMembershipAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsListMembershipAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region ListMembershipOpportunities

void AutoGenGroupsTests::TestGroupsListMembershipOpportunitiesPrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreListMembershipOpportunitiesPrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillListMembershipOpportunitiesPrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsListMembershipOpportunitiesPrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsListMembershipOpportunitiesPrerequisiteApplyToGroup(TestContext& testContext)
{
    struct ApplyToGroupResultHolderStruct : public ApplyToGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsApplyToGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsApplyToGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreListMembershipOpportunitiesPrerequisiteApplyToGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<ApplyToGroupResultHolderStruct>>(testContext);

    PFGroupsApplyToGroupRequestWrapper<> request;
    FillListMembershipOpportunitiesPrerequisiteApplyToGroupRequest(request);
    HRESULT hr = PFGroupsApplyToGroupAsync(entityHandle2, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsListMembershipOpportunitiesPrerequisiteApplyToGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsListMembershipOpportunities(TestContext& testContext)
{
    struct ListMembershipOpportunitiesResultHolderStruct : public ListMembershipOpportunitiesResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsListMembershipOpportunitiesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsListMembershipOpportunitiesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogListMembershipOpportunitiesResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateListMembershipOpportunitiesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListMembershipOpportunitiesResultHolderStruct>>(testContext);

    PFGroupsListMembershipOpportunitiesRequestWrapper<> request;
    FillListMembershipOpportunitiesRequest(request);
    LogListMembershipOpportunitiesRequest(&request.Model(), "TestGroupsListMembershipOpportunities");
    HRESULT hr = PFGroupsListMembershipOpportunitiesAsync(entityHandle2, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsListMembershipOpportunitiesAsync", hr);
        return;
    }
    async.release(); 
}
void AutoGenGroupsTests::TestGroupsListMembershipOpportunitiesCleanupRemoveGroupApplication(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsRemoveGroupApplicationRequestWrapper<> request;
    FillListMembershipOpportunitiesCleanupRemoveGroupApplicationRequest(request);
    HRESULT hr = PFGroupsRemoveGroupApplicationAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsListMembershipOpportunitiesCleanupRemoveGroupApplicationAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region RemoveGroupApplication

void AutoGenGroupsTests::TestGroupsRemoveGroupApplicationPrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreRemoveGroupApplicationPrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillRemoveGroupApplicationPrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsRemoveGroupApplicationPrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsRemoveGroupApplicationPrerequisiteApplyToGroup(TestContext& testContext)
{
    struct ApplyToGroupResultHolderStruct : public ApplyToGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsApplyToGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsApplyToGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreRemoveGroupApplicationPrerequisiteApplyToGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<ApplyToGroupResultHolderStruct>>(testContext);

    PFGroupsApplyToGroupRequestWrapper<> request;
    FillRemoveGroupApplicationPrerequisiteApplyToGroupRequest(request);
    HRESULT hr = PFGroupsApplyToGroupAsync(entityHandle2, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsRemoveGroupApplicationPrerequisiteApplyToGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsRemoveGroupApplication(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsRemoveGroupApplicationRequestWrapper<> request;
    FillRemoveGroupApplicationRequest(request);
    LogRemoveGroupApplicationRequest(&request.Model(), "TestGroupsRemoveGroupApplication");
    HRESULT hr = PFGroupsRemoveGroupApplicationAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsRemoveGroupApplicationAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region RemoveGroupInvitation

void AutoGenGroupsTests::TestGroupsRemoveGroupInvitationPrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreRemoveGroupInvitationPrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillRemoveGroupInvitationPrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsRemoveGroupInvitationPrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsRemoveGroupInvitationPrerequisiteInviteToGroup(TestContext& testContext)
{
    struct InviteToGroupResultHolderStruct : public InviteToGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsInviteToGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsInviteToGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreRemoveGroupInvitationPrerequisiteInviteToGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<InviteToGroupResultHolderStruct>>(testContext);

    PFGroupsInviteToGroupRequestWrapper<> request;
    FillRemoveGroupInvitationPrerequisiteInviteToGroupRequest(request);
    HRESULT hr = PFGroupsInviteToGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsRemoveGroupInvitationPrerequisiteInviteToGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsRemoveGroupInvitation(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsRemoveGroupInvitationRequestWrapper<> request;
    FillRemoveGroupInvitationRequest(request);
    LogRemoveGroupInvitationRequest(&request.Model(), "TestGroupsRemoveGroupInvitation");
    HRESULT hr = PFGroupsRemoveGroupInvitationAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsRemoveGroupInvitationAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region RemoveMembers

void AutoGenGroupsTests::TestGroupsRemoveMembersPrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreRemoveMembersPrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillRemoveMembersPrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsRemoveMembersPrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsRemoveMembersPrerequisiteAddMembers(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsAddMembersRequestWrapper<> request;
    FillRemoveMembersPrerequisiteAddMembersRequest(request);
    HRESULT hr = PFGroupsAddMembersAsync(titleEntityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsRemoveMembersPrerequisiteAddMembersAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsRemoveMembers(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsRemoveMembersRequestWrapper<> request;
    FillRemoveMembersRequest(request);
    LogRemoveMembersRequest(&request.Model(), "TestGroupsRemoveMembers");
    HRESULT hr = PFGroupsRemoveMembersAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsRemoveMembersAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region UnblockEntity

void AutoGenGroupsTests::TestGroupsUnblockEntityPrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreUnblockEntityPrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillUnblockEntityPrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsUnblockEntityPrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsUnblockEntityPrerequisiteBlockEntity(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsBlockEntityRequestWrapper<> request;
    FillUnblockEntityPrerequisiteBlockEntityRequest(request);
    HRESULT hr = PFGroupsBlockEntityAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsUnblockEntityPrerequisiteBlockEntityAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsUnblockEntity(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsUnblockEntityRequestWrapper<> request;
    FillUnblockEntityRequest(request);
    LogUnblockEntityRequest(&request.Model(), "TestGroupsUnblockEntity");
    HRESULT hr = PFGroupsUnblockEntityAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsUnblockEntityAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion

#pragma region UpdateGroup

void AutoGenGroupsTests::TestGroupsUpdateGroupPrerequisiteCreateGroup(TestContext& testContext)
{
    struct CreateGroupResultHolderStruct : public CreateGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsCreateGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsCreateGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreUpdateGroupPrerequisiteCreateGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateGroupResultHolderStruct>>(testContext);

    PFGroupsCreateGroupRequestWrapper<> request;
    FillUpdateGroupPrerequisiteCreateGroupRequest(request);
    HRESULT hr = PFGroupsCreateGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsUpdateGroupPrerequisiteCreateGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsUpdateGroup(TestContext& testContext)
{
    struct UpdateGroupResultHolderStruct : public UpdateGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsUpdateGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsUpdateGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogUpdateGroupResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateUpdateGroupResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<UpdateGroupResultHolderStruct>>(testContext);

    PFGroupsUpdateGroupRequestWrapper<> request;
    FillUpdateGroupRequest(request);
    LogUpdateGroupRequest(&request.Model(), "TestGroupsUpdateGroup");
    HRESULT hr = PFGroupsUpdateGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsUpdateGroupAsync", hr);
        return;
    }
    async.release(); 
}
void AutoGenGroupsTests::TestGroupsUpdateGroupCleanupDeleteGroup(TestContext& testContext)
{
    auto async = std::make_unique<XAsyncHelper<XAsyncResult>>(testContext);

    PFGroupsDeleteGroupRequestWrapper<> request;
    FillUpdateGroupCleanupDeleteGroupRequest(request);
    HRESULT hr = PFGroupsDeleteGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsUpdateGroupCleanupDeleteGroupAsync", hr);
        return;
    }
    async.release(); 
} 

#pragma endregion

#pragma region UpdateRole

void AutoGenGroupsTests::TestGroupsUpdateRolePrerequisiteGetGroup(TestContext& testContext)
{
    struct GetGroupResultHolderStruct : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreUpdateRolePrerequisiteGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolderStruct>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillUpdateRolePrerequisiteGetGroupRequest(request);
    HRESULT hr = PFGroupsGetGroupAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsUpdateRolePrerequisiteGetGroupAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsUpdateRolePrerequisiteUpdateRole(TestContext& testContext)
{
    struct UpdateRoleResultHolderStruct : public UpdateGroupRoleResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsUpdateRoleGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsUpdateRoleGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreUpdateRolePrerequisiteUpdateRoleResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<UpdateRoleResultHolderStruct>>(testContext);

    PFGroupsUpdateGroupRoleRequestWrapper<> request;
    FillUpdateRolePrerequisiteUpdateRoleRequest(request);
    HRESULT hr = PFGroupsUpdateRoleAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsUpdateRolePrerequisiteUpdateRoleAsync", hr);
        return;
    }
    async.release(); 
} 
void AutoGenGroupsTests::TestGroupsUpdateRole(TestContext& testContext)
{
    struct UpdateRoleResultHolderStruct : public UpdateGroupRoleResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsUpdateRoleGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsUpdateRoleGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogUpdateGroupRoleResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidateUpdateRoleResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<UpdateRoleResultHolderStruct>>(testContext);

    PFGroupsUpdateGroupRoleRequestWrapper<> request;
    FillUpdateRoleRequest(request);
    LogUpdateGroupRoleRequest(&request.Model(), "TestGroupsUpdateRole");
    HRESULT hr = PFGroupsUpdateRoleAsync(entityHandle, &request.Model(), &async->asyncBlock);
    if (FAILED(hr))
    {
        testContext.Fail("PFGroupsGroupsUpdateRoleAsync", hr);
        return;
    }
    async.release(); 
}

#pragma endregion


}
