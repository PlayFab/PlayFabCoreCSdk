#pragma once

#include "TestCase.h"
#include <playfab/PFGlobal.h>
#include <playfab/PFEntity.h>
#include <playfab/cpp/PFGroupsDataModelWrappers.h>
#include "AutoGenGroupsResultHolders.h"

namespace PlayFabUnit
{

class AutoGenGroupsTests : public PlayFabApiTestCase
{
private: 
    static void Log(std::stringstream& ss);
    static HRESULT LogHR(HRESULT hr);

    void TestGroupsAcceptGroupApplicationPrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsAcceptGroupApplicationPrerequisiteApplyToGroup(TestContext& testContext);
    void TestGroupsAcceptGroupApplication(TestContext& testContext);
    void TestGroupsAcceptGroupApplicationCleanupRemoveMembers(TestContext& testContext);

    void TestGroupsAcceptGroupInvitationPrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsAcceptGroupInvitationPrerequisiteInviteToGroup(TestContext& testContext);
    void TestGroupsAcceptGroupInvitation(TestContext& testContext);
    void TestGroupsAcceptGroupInvitationCleanupRemoveMembers(TestContext& testContext);

    void TestGroupsAddMembersPrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsAddMembers(TestContext& testContext);
    void TestGroupsAddMembersCleanupRemoveMembers(TestContext& testContext);

    void TestGroupsApplyToGroupPrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsApplyToGroup(TestContext& testContext);
    void TestGroupsApplyToGroupCleanupRemoveGroupApplication(TestContext& testContext);

    void TestGroupsBlockEntityPrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsBlockEntity(TestContext& testContext);
    void TestGroupsBlockEntityCleanupUnblockEntity(TestContext& testContext);

    void TestGroupsChangeMemberRolePrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsChangeMemberRole(TestContext& testContext);
    void TestGroupsChangeMemberRoleCleanupChangeMemberRole(TestContext& testContext);

    void TestGroupsCreateGroup(TestContext& testContext);
    void TestGroupsCreateGroupCleanupGetGroup(TestContext& testContext);
    void TestGroupsCreateGroupCleanupDeleteGroup(TestContext& testContext);

    void TestGroupsCreateRolePrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsCreateRole(TestContext& testContext);
    void TestGroupsCreateRoleCleanupDeleteRole(TestContext& testContext);

    void TestGroupsDeleteGroupPrerequisiteCreateGroup(TestContext& testContext);
    void TestGroupsDeleteGroup(TestContext& testContext);

    void TestGroupsDeleteRolePrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsDeleteRolePrerequisiteCreateRole(TestContext& testContext);
    void TestGroupsDeleteRole(TestContext& testContext);

    void TestGroupsGetGroup(TestContext& testContext);

    void TestGroupsInviteToGroupPrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsInviteToGroup(TestContext& testContext);
    void TestGroupsInviteToGroupCleanupRemoveGroupInvitation(TestContext& testContext);

    void TestGroupsIsMemberPrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsIsMember(TestContext& testContext);

    void TestGroupsListGroupApplicationsPrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsListGroupApplications(TestContext& testContext);

    void TestGroupsListGroupBlocksPrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsListGroupBlocks(TestContext& testContext);

    void TestGroupsListGroupInvitationsPrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsListGroupInvitations(TestContext& testContext);

    void TestGroupsListGroupMembersPrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsListGroupMembers(TestContext& testContext);

    void TestGroupsListMembershipPrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsListMembership(TestContext& testContext);

    void TestGroupsListMembershipOpportunitiesPrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsListMembershipOpportunitiesPrerequisiteApplyToGroup(TestContext& testContext);
    void TestGroupsListMembershipOpportunities(TestContext& testContext);
    void TestGroupsListMembershipOpportunitiesCleanupRemoveGroupApplication(TestContext& testContext);

    void TestGroupsRemoveGroupApplicationPrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsRemoveGroupApplicationPrerequisiteApplyToGroup(TestContext& testContext);
    void TestGroupsRemoveGroupApplication(TestContext& testContext);

    void TestGroupsRemoveGroupInvitationPrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsRemoveGroupInvitationPrerequisiteInviteToGroup(TestContext& testContext);
    void TestGroupsRemoveGroupInvitation(TestContext& testContext);

    void TestGroupsRemoveMembersPrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsRemoveMembersPrerequisiteAddMembers(TestContext& testContext);
    void TestGroupsRemoveMembers(TestContext& testContext);

    void TestGroupsUnblockEntityPrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsUnblockEntityPrerequisiteBlockEntity(TestContext& testContext);
    void TestGroupsUnblockEntity(TestContext& testContext);

    void TestGroupsUpdateGroupPrerequisiteCreateGroup(TestContext& testContext);
    void TestGroupsUpdateGroup(TestContext& testContext);
    void TestGroupsUpdateGroupCleanupDeleteGroup(TestContext& testContext);

    void TestGroupsUpdateRolePrerequisiteGetGroup(TestContext& testContext);
    void TestGroupsUpdateRolePrerequisiteUpdateRole(TestContext& testContext);
    void TestGroupsUpdateRole(TestContext& testContext);


protected:
    void AddTests();

    static void LogAcceptGroupApplicationRequest(PFGroupsAcceptGroupApplicationRequest const* request, const char* testName);
    static void LogAcceptGroupInvitationRequest(PFGroupsAcceptGroupInvitationRequest const* request, const char* testName);
    static void LogAddMembersRequest(PFGroupsAddMembersRequest const* request, const char* testName);
    static void LogApplyToGroupRequest(PFGroupsApplyToGroupRequest const* request, const char* testName);
    static HRESULT LogApplyToGroupResponse(PFGroupsApplyToGroupResponse const* result);
    static void LogBlockEntityRequest(PFGroupsBlockEntityRequest const* request, const char* testName);
    static void LogChangeMemberRoleRequest(PFGroupsChangeMemberRoleRequest const* request, const char* testName);
    static void LogCreateGroupRequest(PFGroupsCreateGroupRequest const* request, const char* testName);
    static HRESULT LogCreateGroupResponse(PFGroupsCreateGroupResponse const* result);
    static void LogCreateGroupRoleRequest(PFGroupsCreateGroupRoleRequest const* request, const char* testName);
    static HRESULT LogCreateGroupRoleResponse(PFGroupsCreateGroupRoleResponse const* result);
    static void LogDeleteGroupRequest(PFGroupsDeleteGroupRequest const* request, const char* testName);
    static void LogDeleteRoleRequest(PFGroupsDeleteRoleRequest const* request, const char* testName);
    static void LogGetGroupRequest(PFGroupsGetGroupRequest const* request, const char* testName);
    static HRESULT LogGetGroupResponse(PFGroupsGetGroupResponse const* result);
    static void LogInviteToGroupRequest(PFGroupsInviteToGroupRequest const* request, const char* testName);
    static HRESULT LogInviteToGroupResponse(PFGroupsInviteToGroupResponse const* result);
    static void LogIsMemberRequest(PFGroupsIsMemberRequest const* request, const char* testName);
    static HRESULT LogIsMemberResponse(PFGroupsIsMemberResponse const* result);
    static void LogListGroupApplicationsRequest(PFGroupsListGroupApplicationsRequest const* request, const char* testName);
    static HRESULT LogListGroupApplicationsResponse(PFGroupsListGroupApplicationsResponse const* result);
    static void LogListGroupBlocksRequest(PFGroupsListGroupBlocksRequest const* request, const char* testName);
    static HRESULT LogListGroupBlocksResponse(PFGroupsListGroupBlocksResponse const* result);
    static void LogListGroupInvitationsRequest(PFGroupsListGroupInvitationsRequest const* request, const char* testName);
    static HRESULT LogListGroupInvitationsResponse(PFGroupsListGroupInvitationsResponse const* result);
    static void LogListGroupMembersRequest(PFGroupsListGroupMembersRequest const* request, const char* testName);
    static HRESULT LogListGroupMembersResponse(PFGroupsListGroupMembersResponse const* result);
    static void LogListMembershipRequest(PFGroupsListMembershipRequest const* request, const char* testName);
    static HRESULT LogListMembershipResponse(PFGroupsListMembershipResponse const* result);
    static void LogListMembershipOpportunitiesRequest(PFGroupsListMembershipOpportunitiesRequest const* request, const char* testName);
    static HRESULT LogListMembershipOpportunitiesResponse(PFGroupsListMembershipOpportunitiesResponse const* result);
    static void LogRemoveGroupApplicationRequest(PFGroupsRemoveGroupApplicationRequest const* request, const char* testName);
    static void LogRemoveGroupInvitationRequest(PFGroupsRemoveGroupInvitationRequest const* request, const char* testName);
    static void LogRemoveMembersRequest(PFGroupsRemoveMembersRequest const* request, const char* testName);
    static void LogUnblockEntityRequest(PFGroupsUnblockEntityRequest const* request, const char* testName);
    static void LogUpdateGroupRequest(PFGroupsUpdateGroupRequest const* request, const char* testName);
    static HRESULT LogUpdateGroupResponse(PFGroupsUpdateGroupResponse const* result);
    static void LogUpdateGroupRoleRequest(PFGroupsUpdateGroupRoleRequest const* request, const char* testName);
    static HRESULT LogUpdateGroupRoleResponse(PFGroupsUpdateGroupRoleResponse const* result);

    void FillAcceptGroupApplicationPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreAcceptGroupApplicationPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillAcceptGroupApplicationPrerequisiteApplyToGroupRequest(PlayFab::Wrappers::PFGroupsApplyToGroupRequestWrapper<>& request);
    static HRESULT StoreAcceptGroupApplicationPrerequisiteApplyToGroupResponse(std::shared_ptr<ApplyToGroupResponseHolder> result);
    void FillAcceptGroupApplicationRequest(PlayFab::Wrappers::PFGroupsAcceptGroupApplicationRequestWrapper<>& request);
    void FillAcceptGroupApplicationCleanupRemoveMembersRequest(PlayFab::Wrappers::PFGroupsRemoveMembersRequestWrapper<>& request);

    void FillAcceptGroupInvitationPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreAcceptGroupInvitationPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillAcceptGroupInvitationPrerequisiteInviteToGroupRequest(PlayFab::Wrappers::PFGroupsInviteToGroupRequestWrapper<>& request);
    static HRESULT StoreAcceptGroupInvitationPrerequisiteInviteToGroupResponse(std::shared_ptr<InviteToGroupResponseHolder> result);
    void FillAcceptGroupInvitationRequest(PlayFab::Wrappers::PFGroupsAcceptGroupInvitationRequestWrapper<>& request);
    void FillAcceptGroupInvitationCleanupRemoveMembersRequest(PlayFab::Wrappers::PFGroupsRemoveMembersRequestWrapper<>& request);

    void FillAddMembersPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreAddMembersPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillAddMembersRequest(PlayFab::Wrappers::PFGroupsAddMembersRequestWrapper<>& request);
    void FillAddMembersCleanupRemoveMembersRequest(PlayFab::Wrappers::PFGroupsRemoveMembersRequestWrapper<>& request);

    void FillApplyToGroupPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreApplyToGroupPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillApplyToGroupRequest(PlayFab::Wrappers::PFGroupsApplyToGroupRequestWrapper<>& request);
    static HRESULT ValidateApplyToGroupResponse(PFGroupsApplyToGroupResponse* result);
    void FillApplyToGroupCleanupRemoveGroupApplicationRequest(PlayFab::Wrappers::PFGroupsRemoveGroupApplicationRequestWrapper<>& request);

    void FillBlockEntityPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreBlockEntityPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillBlockEntityRequest(PlayFab::Wrappers::PFGroupsBlockEntityRequestWrapper<>& request);
    void FillBlockEntityCleanupUnblockEntityRequest(PlayFab::Wrappers::PFGroupsUnblockEntityRequestWrapper<>& request);

    void FillChangeMemberRolePrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreChangeMemberRolePrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillChangeMemberRoleRequest(PlayFab::Wrappers::PFGroupsChangeMemberRoleRequestWrapper<>& request);
    void FillChangeMemberRoleCleanupChangeMemberRoleRequest(PlayFab::Wrappers::PFGroupsChangeMemberRoleRequestWrapper<>& request);

    void FillCreateGroupRequest(PlayFab::Wrappers::PFGroupsCreateGroupRequestWrapper<>& request);
    static HRESULT ValidateCreateGroupResponse(PFGroupsCreateGroupResponse* result);
    void FillCreateGroupCleanupGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreCreateGroupCleanupGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillCreateGroupCleanupDeleteGroupRequest(PlayFab::Wrappers::PFGroupsDeleteGroupRequestWrapper<>& request);

    void FillCreateRolePrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreCreateRolePrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillCreateRoleRequest(PlayFab::Wrappers::PFGroupsCreateGroupRoleRequestWrapper<>& request);
    static HRESULT ValidateCreateRoleResponse(PFGroupsCreateGroupRoleResponse* result);
    void FillCreateRoleCleanupDeleteRoleRequest(PlayFab::Wrappers::PFGroupsDeleteRoleRequestWrapper<>& request);

    void FillDeleteGroupPrerequisiteCreateGroupRequest(PlayFab::Wrappers::PFGroupsCreateGroupRequestWrapper<>& request);
    static HRESULT StoreDeleteGroupPrerequisiteCreateGroupResponse(std::shared_ptr<CreateGroupResponseHolder> result);
    void FillDeleteGroupRequest(PlayFab::Wrappers::PFGroupsDeleteGroupRequestWrapper<>& request);

    void FillDeleteRolePrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreDeleteRolePrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillDeleteRolePrerequisiteCreateRoleRequest(PlayFab::Wrappers::PFGroupsCreateGroupRoleRequestWrapper<>& request);
    static HRESULT StoreDeleteRolePrerequisiteCreateRoleResponse(std::shared_ptr<CreateGroupRoleResponseHolder> result);
    void FillDeleteRoleRequest(PlayFab::Wrappers::PFGroupsDeleteRoleRequestWrapper<>& request);

    void FillGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT ValidateGetGroupResponse(PFGroupsGetGroupResponse* result);

    void FillInviteToGroupPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreInviteToGroupPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillInviteToGroupRequest(PlayFab::Wrappers::PFGroupsInviteToGroupRequestWrapper<>& request);
    static HRESULT ValidateInviteToGroupResponse(PFGroupsInviteToGroupResponse* result);
    void FillInviteToGroupCleanupRemoveGroupInvitationRequest(PlayFab::Wrappers::PFGroupsRemoveGroupInvitationRequestWrapper<>& request);

    void FillIsMemberPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreIsMemberPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillIsMemberRequest(PlayFab::Wrappers::PFGroupsIsMemberRequestWrapper<>& request);
    static HRESULT ValidateIsMemberResponse(PFGroupsIsMemberResponse* result);

    void FillListGroupApplicationsPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListGroupApplicationsPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillListGroupApplicationsRequest(PlayFab::Wrappers::PFGroupsListGroupApplicationsRequestWrapper<>& request);
    static HRESULT ValidateListGroupApplicationsResponse(PFGroupsListGroupApplicationsResponse* result);

    void FillListGroupBlocksPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListGroupBlocksPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillListGroupBlocksRequest(PlayFab::Wrappers::PFGroupsListGroupBlocksRequestWrapper<>& request);
    static HRESULT ValidateListGroupBlocksResponse(PFGroupsListGroupBlocksResponse* result);

    void FillListGroupInvitationsPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListGroupInvitationsPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillListGroupInvitationsRequest(PlayFab::Wrappers::PFGroupsListGroupInvitationsRequestWrapper<>& request);
    static HRESULT ValidateListGroupInvitationsResponse(PFGroupsListGroupInvitationsResponse* result);

    void FillListGroupMembersPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListGroupMembersPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillListGroupMembersRequest(PlayFab::Wrappers::PFGroupsListGroupMembersRequestWrapper<>& request);
    static HRESULT ValidateListGroupMembersResponse(PFGroupsListGroupMembersResponse* result);

    void FillListMembershipPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListMembershipPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillListMembershipRequest(PlayFab::Wrappers::PFGroupsListMembershipRequestWrapper<>& request);
    static HRESULT ValidateListMembershipResponse(PFGroupsListMembershipResponse* result);

    void FillListMembershipOpportunitiesPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListMembershipOpportunitiesPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillListMembershipOpportunitiesPrerequisiteApplyToGroupRequest(PlayFab::Wrappers::PFGroupsApplyToGroupRequestWrapper<>& request);
    static HRESULT StoreListMembershipOpportunitiesPrerequisiteApplyToGroupResponse(std::shared_ptr<ApplyToGroupResponseHolder> result);
    void FillListMembershipOpportunitiesRequest(PlayFab::Wrappers::PFGroupsListMembershipOpportunitiesRequestWrapper<>& request);
    static HRESULT ValidateListMembershipOpportunitiesResponse(PFGroupsListMembershipOpportunitiesResponse* result);
    void FillListMembershipOpportunitiesCleanupRemoveGroupApplicationRequest(PlayFab::Wrappers::PFGroupsRemoveGroupApplicationRequestWrapper<>& request);

    void FillRemoveGroupApplicationPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreRemoveGroupApplicationPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillRemoveGroupApplicationPrerequisiteApplyToGroupRequest(PlayFab::Wrappers::PFGroupsApplyToGroupRequestWrapper<>& request);
    static HRESULT StoreRemoveGroupApplicationPrerequisiteApplyToGroupResponse(std::shared_ptr<ApplyToGroupResponseHolder> result);
    void FillRemoveGroupApplicationRequest(PlayFab::Wrappers::PFGroupsRemoveGroupApplicationRequestWrapper<>& request);

    void FillRemoveGroupInvitationPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreRemoveGroupInvitationPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillRemoveGroupInvitationPrerequisiteInviteToGroupRequest(PlayFab::Wrappers::PFGroupsInviteToGroupRequestWrapper<>& request);
    static HRESULT StoreRemoveGroupInvitationPrerequisiteInviteToGroupResponse(std::shared_ptr<InviteToGroupResponseHolder> result);
    void FillRemoveGroupInvitationRequest(PlayFab::Wrappers::PFGroupsRemoveGroupInvitationRequestWrapper<>& request);

    void FillRemoveMembersPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreRemoveMembersPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillRemoveMembersPrerequisiteAddMembersRequest(PlayFab::Wrappers::PFGroupsAddMembersRequestWrapper<>& request);
    void FillRemoveMembersRequest(PlayFab::Wrappers::PFGroupsRemoveMembersRequestWrapper<>& request);

    void FillUnblockEntityPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreUnblockEntityPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillUnblockEntityPrerequisiteBlockEntityRequest(PlayFab::Wrappers::PFGroupsBlockEntityRequestWrapper<>& request);
    void FillUnblockEntityRequest(PlayFab::Wrappers::PFGroupsUnblockEntityRequestWrapper<>& request);

    void FillUpdateGroupPrerequisiteCreateGroupRequest(PlayFab::Wrappers::PFGroupsCreateGroupRequestWrapper<>& request);
    static HRESULT StoreUpdateGroupPrerequisiteCreateGroupResponse(std::shared_ptr<CreateGroupResponseHolder> result);
    void FillUpdateGroupRequest(PlayFab::Wrappers::PFGroupsUpdateGroupRequestWrapper<>& request);
    static HRESULT ValidateUpdateGroupResponse(PFGroupsUpdateGroupResponse* result);
    void FillUpdateGroupCleanupDeleteGroupRequest(PlayFab::Wrappers::PFGroupsDeleteGroupRequestWrapper<>& request);

    void FillUpdateRolePrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreUpdateRolePrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    void FillUpdateRolePrerequisiteUpdateRoleRequest(PlayFab::Wrappers::PFGroupsUpdateGroupRoleRequestWrapper<>& request);
    static HRESULT StoreUpdateRolePrerequisiteUpdateRoleResponse(std::shared_ptr<UpdateGroupRoleResponseHolder> result);
    void FillUpdateRoleRequest(PlayFab::Wrappers::PFGroupsUpdateGroupRoleRequestWrapper<>& request);
    static HRESULT ValidateUpdateRoleResponse(PFGroupsUpdateGroupRoleResponse* result);

    struct GroupsTestData
    {
        ~GroupsTestData() = default;

        std::shared_ptr<GetGroupResponseHolder> m_GetGroupResponse;
        std::shared_ptr<ApplyToGroupResponseHolder> m_ApplyToGroupResponse;
        std::shared_ptr<InviteToGroupResponseHolder> m_InviteToGroupResponse;
        std::shared_ptr<CreateGroupResponseHolder> m_CreateGroupResponse;
        std::shared_ptr<CreateGroupRoleResponseHolder> m_CreateGroupRoleResponse;
        std::shared_ptr<UpdateGroupRoleResponseHolder> m_UpdateGroupRoleResponse;
    };

    static GroupsTestData testData;

public:
    PFStateHandle stateHandle{ nullptr };
    PFTitlePlayerHandle titlePlayerHandle{ nullptr };
    PFEntityHandle entityHandle{ nullptr };
    PFTitlePlayerHandle titlePlayerHandle2{ nullptr };
    PFEntityHandle entityHandle2{ nullptr };
    PFEntityHandle titleEntityHandle{ nullptr };

    void ClassSetUp() override;
    void ClassTearDown() override;
    void SetUp(TestContext& testContext) override;

    void Tick(TestContext&) override {}
};

}
