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
    if( TestApp::ShouldTrace(PFTestTraceLevel::Information) )
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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreAcceptGroupApplicationPrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillAcceptGroupApplicationPrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsUpdateRole");
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
    struct ApplyToGroupResultHolder : public ApplyToGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsApplyToGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsApplyToGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsApplyToGroupResponse(result);
            return StoreAcceptGroupApplicationPrerequisitePFGroupsApplyToGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<ApplyToGroupResultHolder>>(testContext);

    PFGroupsApplyToGroupRequestWrapper<> request;
    FillAcceptGroupApplicationPrerequisiteApplyToGroupRequest(request);
    LogApplyToGroupRequest(&request.Model(), "TestGroupsUpdateRole");
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
    LogRemoveMembersRequest(&request.Model(), "TestGroupsAcceptGroupApplicationCleanupRemoveMembers");
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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreAcceptGroupInvitationPrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillAcceptGroupInvitationPrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsAcceptGroupApplication");
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
    struct InviteToGroupResultHolder : public InviteToGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsInviteToGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsInviteToGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsInviteToGroupResponse(result);
            return StoreAcceptGroupInvitationPrerequisitePFGroupsInviteToGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<InviteToGroupResultHolder>>(testContext);

    PFGroupsInviteToGroupRequestWrapper<> request;
    FillAcceptGroupInvitationPrerequisiteInviteToGroupRequest(request);
    LogInviteToGroupRequest(&request.Model(), "TestGroupsAcceptGroupApplication");
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
    LogRemoveMembersRequest(&request.Model(), "TestGroupsAcceptGroupInvitationCleanupRemoveMembers");
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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreAddMembersPrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillAddMembersPrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsAcceptGroupInvitation");
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
    LogRemoveMembersRequest(&request.Model(), "TestGroupsAddMembersCleanupRemoveMembers");
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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreApplyToGroupPrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillApplyToGroupPrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsAddMembers");
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
    struct ApplyToGroupResultHolder : public ApplyToGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsApplyToGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsApplyToGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsApplyToGroupResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGroupsApplyToGroupResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ApplyToGroupResultHolder>>(testContext);

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
    LogRemoveGroupApplicationRequest(&request.Model(), "TestGroupsApplyToGroupCleanupRemoveGroupApplication");
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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreBlockEntityPrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillBlockEntityPrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsApplyToGroup");
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
    LogUnblockEntityRequest(&request.Model(), "TestGroupsBlockEntityCleanupUnblockEntity");
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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreChangeMemberRolePrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillChangeMemberRolePrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsBlockEntity");
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
    LogChangeMemberRoleRequest(&request.Model(), "TestGroupsChangeMemberRoleCleanupChangeMemberRole");
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
    struct CreateGroupResultHolder : public CreateGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsCreateGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsCreateGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsCreateGroupResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGroupsCreateGroupResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateGroupResultHolder>>(testContext);

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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            return StoreCreateGroupCleanupPFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillCreateGroupCleanupGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsCreateGroupCleanupGetGroup");
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
    LogDeleteGroupRequest(&request.Model(), "TestGroupsCreateGroupCleanupDeleteGroup");
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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreCreateRolePrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillCreateRolePrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsCreateGroup");
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
    struct CreateRoleResultHolder : public CreateGroupRoleResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsCreateRoleGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsCreateRoleGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsCreateGroupRoleResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGroupsCreateGroupRoleResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateRoleResultHolder>>(testContext);

    PFGroupsCreateGroupRoleRequestWrapper<> request;
    FillCreateGroupRoleRequest(request);
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
    LogDeleteRoleRequest(&request.Model(), "TestGroupsCreateRoleCleanupDeleteRole");
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
    struct CreateGroupResultHolder : public CreateGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsCreateGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsCreateGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsCreateGroupResponse(result);
            return StoreDeleteGroupPrerequisitePFGroupsCreateGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateGroupResultHolder>>(testContext);

    PFGroupsCreateGroupRequestWrapper<> request;
    FillDeleteGroupPrerequisiteCreateGroupRequest(request);
    LogCreateGroupRequest(&request.Model(), "TestGroupsCreateRole");
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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreDeleteRolePrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillDeleteRolePrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsDeleteGroup");
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
    struct CreateRoleResultHolder : public CreateGroupRoleResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsCreateRoleGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsCreateRoleGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsCreateGroupRoleResponse(result);
            return StoreDeleteRolePrerequisitePFGroupsCreateGroupRoleResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateRoleResultHolder>>(testContext);

    PFGroupsCreateGroupRoleRequestWrapper<> request;
    FillDeleteRolePrerequisiteCreateGroupRoleRequest(request);
    LogCreateGroupRoleRequest(&request.Model(), "TestGroupsDeleteGroup");
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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGroupsGetGroupResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreInviteToGroupPrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillInviteToGroupPrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsGetGroup");
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
    struct InviteToGroupResultHolder : public InviteToGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsInviteToGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsInviteToGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsInviteToGroupResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGroupsInviteToGroupResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<InviteToGroupResultHolder>>(testContext);

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
    LogRemoveGroupInvitationRequest(&request.Model(), "TestGroupsInviteToGroupCleanupRemoveGroupInvitation");
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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreIsMemberPrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillIsMemberPrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsInviteToGroup");
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
    struct IsMemberResultHolder : public IsMemberResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            RETURN_IF_FAILED(LogHR(PFGroupsIsMemberGetResult(async, &result)));
            LogPFGroupsIsMemberResponse(&result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGroupsIsMemberResponse(&result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<IsMemberResultHolder>>(testContext);

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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreListGroupApplicationsPrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillListGroupApplicationsPrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsIsMember");
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
    struct ListGroupApplicationsResultHolder : public ListGroupApplicationsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsListGroupApplicationsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsListGroupApplicationsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsListGroupApplicationsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGroupsListGroupApplicationsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListGroupApplicationsResultHolder>>(testContext);

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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreListGroupBlocksPrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillListGroupBlocksPrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsListGroupApplications");
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
    struct ListGroupBlocksResultHolder : public ListGroupBlocksResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsListGroupBlocksGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsListGroupBlocksGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsListGroupBlocksResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGroupsListGroupBlocksResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListGroupBlocksResultHolder>>(testContext);

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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreListGroupInvitationsPrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillListGroupInvitationsPrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsListGroupBlocks");
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
    struct ListGroupInvitationsResultHolder : public ListGroupInvitationsResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsListGroupInvitationsGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsListGroupInvitationsGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsListGroupInvitationsResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGroupsListGroupInvitationsResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListGroupInvitationsResultHolder>>(testContext);

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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreListGroupMembersPrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillListGroupMembersPrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsListGroupInvitations");
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
    struct ListGroupMembersResultHolder : public ListGroupMembersResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsListGroupMembersGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsListGroupMembersGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsListGroupMembersResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGroupsListGroupMembersResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListGroupMembersResultHolder>>(testContext);

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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreListMembershipPrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillListMembershipPrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsListGroupMembers");
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
    struct ListMembershipResultHolder : public ListMembershipResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsListMembershipGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsListMembershipGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsListMembershipResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGroupsListMembershipResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListMembershipResultHolder>>(testContext);

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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreListMembershipOpportunitiesPrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillListMembershipOpportunitiesPrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsListMembership");
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
    struct ApplyToGroupResultHolder : public ApplyToGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsApplyToGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsApplyToGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsApplyToGroupResponse(result);
            return StoreListMembershipOpportunitiesPrerequisitePFGroupsApplyToGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<ApplyToGroupResultHolder>>(testContext);

    PFGroupsApplyToGroupRequestWrapper<> request;
    FillListMembershipOpportunitiesPrerequisiteApplyToGroupRequest(request);
    LogApplyToGroupRequest(&request.Model(), "TestGroupsListMembership");
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
    struct ListMembershipOpportunitiesResultHolder : public ListMembershipOpportunitiesResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsListMembershipOpportunitiesGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsListMembershipOpportunitiesGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsListMembershipOpportunitiesResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGroupsListMembershipOpportunitiesResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<ListMembershipOpportunitiesResultHolder>>(testContext);

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
    LogRemoveGroupApplicationRequest(&request.Model(), "TestGroupsListMembershipOpportunitiesCleanupRemoveGroupApplication");
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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreRemoveGroupApplicationPrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillRemoveGroupApplicationPrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsListMembershipOpportunities");
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
    struct ApplyToGroupResultHolder : public ApplyToGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsApplyToGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsApplyToGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsApplyToGroupResponse(result);
            return StoreRemoveGroupApplicationPrerequisitePFGroupsApplyToGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<ApplyToGroupResultHolder>>(testContext);

    PFGroupsApplyToGroupRequestWrapper<> request;
    FillRemoveGroupApplicationPrerequisiteApplyToGroupRequest(request);
    LogApplyToGroupRequest(&request.Model(), "TestGroupsListMembershipOpportunities");
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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreRemoveGroupInvitationPrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillRemoveGroupInvitationPrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsRemoveGroupApplication");
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
    struct InviteToGroupResultHolder : public InviteToGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsInviteToGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsInviteToGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsInviteToGroupResponse(result);
            return StoreRemoveGroupInvitationPrerequisitePFGroupsInviteToGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<InviteToGroupResultHolder>>(testContext);

    PFGroupsInviteToGroupRequestWrapper<> request;
    FillRemoveGroupInvitationPrerequisiteInviteToGroupRequest(request);
    LogInviteToGroupRequest(&request.Model(), "TestGroupsRemoveGroupApplication");
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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreRemoveMembersPrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillRemoveMembersPrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsRemoveGroupInvitation");
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
    LogAddMembersRequest(&request.Model(), "TestGroupsRemoveGroupInvitation");
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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreUnblockEntityPrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillUnblockEntityPrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsRemoveMembers");
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
    LogBlockEntityRequest(&request.Model(), "TestGroupsRemoveMembers");
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
    struct CreateGroupResultHolder : public CreateGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsCreateGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsCreateGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsCreateGroupResponse(result);
            return StoreUpdateGroupPrerequisitePFGroupsCreateGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<CreateGroupResultHolder>>(testContext);

    PFGroupsCreateGroupRequestWrapper<> request;
    FillUpdateGroupPrerequisiteCreateGroupRequest(request);
    LogCreateGroupRequest(&request.Model(), "TestGroupsUnblockEntity");
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
    struct UpdateGroupResultHolder : public UpdateGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsUpdateGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsUpdateGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsUpdateGroupResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGroupsUpdateGroupResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<UpdateGroupResultHolder>>(testContext);

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
    LogDeleteGroupRequest(&request.Model(), "TestGroupsUpdateGroupCleanupDeleteGroup");
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
    struct GetGroupResultHolder : public GetGroupResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsGetGroupGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsGetGroupResponse(result);
            return StoreUpdateRolePrerequisitePFGroupsGetGroupResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<GetGroupResultHolder>>(testContext);

    PFGroupsGetGroupRequestWrapper<> request;
    FillUpdateRolePrerequisiteGetGroupRequest(request);
    LogGetGroupRequest(&request.Model(), "TestGroupsUpdateGroup");
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
    struct UpdateRoleResultHolder : public UpdateGroupRoleResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsUpdateRoleGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsUpdateRoleGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsUpdateGroupRoleResponse(result);
            return StoreUpdateRolePrerequisitePFGroupsUpdateGroupRoleResponse(shared_from_this());
        }
    };
    auto async = std::make_unique<XAsyncHelper<UpdateRoleResultHolder>>(testContext);

    PFGroupsUpdateGroupRoleRequestWrapper<> request;
    FillUpdateRolePrerequisiteUpdateGroupRoleRequest(request);
    LogUpdateGroupRoleRequest(&request.Model(), "TestGroupsUpdateGroup");
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
    struct UpdateRoleResultHolder : public UpdateGroupRoleResponseHolder
    {
        HRESULT Get(XAsyncBlock* async) override
        {
            size_t requiredBufferSize;
            RETURN_IF_FAILED(LogHR(PFGroupsUpdateRoleGetResultSize(async, &requiredBufferSize)));

            resultBuffer.resize(requiredBufferSize);
            RETURN_IF_FAILED(LogHR(PFGroupsUpdateRoleGetResult(async, resultBuffer.size(), resultBuffer.data(), &result, nullptr)));
            
            LogPFGroupsUpdateGroupRoleResponse(result);
            return S_OK;
        }

        HRESULT Validate() override
        {
            return ValidatePFGroupsUpdateGroupRoleResponse(result);
        }
    };
    auto async = std::make_unique<XAsyncHelper<UpdateRoleResultHolder>>(testContext);

    PFGroupsUpdateGroupRoleRequestWrapper<> request;
    FillUpdateGroupRoleRequest(request);
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
