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

    static void FillAcceptGroupApplicationPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreAcceptGroupApplicationPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillAcceptGroupApplicationPrerequisiteApplyToGroupRequest(PlayFab::Wrappers::PFGroupsApplyToGroupRequestWrapper<>& request);
    static HRESULT StoreAcceptGroupApplicationPrerequisiteApplyToGroupResponse(std::shared_ptr<ApplyToGroupResponseHolder> result);
    static void FillAcceptGroupApplicationRequest(PlayFab::Wrappers::PFGroupsAcceptGroupApplicationRequestWrapper<>& request);
    static void FillAcceptGroupApplicationCleanupRemoveMembersRequest(PlayFab::Wrappers::PFGroupsRemoveMembersRequestWrapper<>& request);

    static void FillAcceptGroupInvitationPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreAcceptGroupInvitationPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillAcceptGroupInvitationPrerequisiteInviteToGroupRequest(PlayFab::Wrappers::PFGroupsInviteToGroupRequestWrapper<>& request);
    static HRESULT StoreAcceptGroupInvitationPrerequisiteInviteToGroupResponse(std::shared_ptr<InviteToGroupResponseHolder> result);
    static void FillAcceptGroupInvitationRequest(PlayFab::Wrappers::PFGroupsAcceptGroupInvitationRequestWrapper<>& request);
    static void FillAcceptGroupInvitationCleanupRemoveMembersRequest(PlayFab::Wrappers::PFGroupsRemoveMembersRequestWrapper<>& request);

    static void FillAddMembersPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreAddMembersPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillAddMembersRequest(PlayFab::Wrappers::PFGroupsAddMembersRequestWrapper<>& request);
    static void FillAddMembersCleanupRemoveMembersRequest(PlayFab::Wrappers::PFGroupsRemoveMembersRequestWrapper<>& request);

    static void FillApplyToGroupPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreApplyToGroupPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillApplyToGroupRequest(PlayFab::Wrappers::PFGroupsApplyToGroupRequestWrapper<>& request);
    static HRESULT ValidateApplyToGroupResponse(PFGroupsApplyToGroupResponse* result);
    static void FillApplyToGroupCleanupRemoveGroupApplicationRequest(PlayFab::Wrappers::PFGroupsRemoveGroupApplicationRequestWrapper<>& request);

    static void FillBlockEntityPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreBlockEntityPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillBlockEntityRequest(PlayFab::Wrappers::PFGroupsBlockEntityRequestWrapper<>& request);
    static void FillBlockEntityCleanupUnblockEntityRequest(PlayFab::Wrappers::PFGroupsUnblockEntityRequestWrapper<>& request);

    static void FillChangeMemberRolePrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreChangeMemberRolePrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillChangeMemberRoleRequest(PlayFab::Wrappers::PFGroupsChangeMemberRoleRequestWrapper<>& request);
    static void FillChangeMemberRoleCleanupChangeMemberRoleRequest(PlayFab::Wrappers::PFGroupsChangeMemberRoleRequestWrapper<>& request);

    static void FillCreateGroupRequest(PlayFab::Wrappers::PFGroupsCreateGroupRequestWrapper<>& request);
    static HRESULT ValidateCreateGroupResponse(PFGroupsCreateGroupResponse* result);
    static void FillCreateGroupCleanupGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreCreateGroupCleanupGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillCreateGroupCleanupDeleteGroupRequest(PlayFab::Wrappers::PFGroupsDeleteGroupRequestWrapper<>& request);

    static void FillCreateRolePrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreCreateRolePrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillCreateRoleRequest(PlayFab::Wrappers::PFGroupsCreateGroupRoleRequestWrapper<>& request);
    static HRESULT ValidateCreateRoleResponse(PFGroupsCreateGroupRoleResponse* result);
    static void FillCreateRoleCleanupDeleteRoleRequest(PlayFab::Wrappers::PFGroupsDeleteRoleRequestWrapper<>& request);

    static void FillDeleteGroupPrerequisiteCreateGroupRequest(PlayFab::Wrappers::PFGroupsCreateGroupRequestWrapper<>& request);
    static HRESULT StoreDeleteGroupPrerequisiteCreateGroupResponse(std::shared_ptr<CreateGroupResponseHolder> result);
    static void FillDeleteGroupRequest(PlayFab::Wrappers::PFGroupsDeleteGroupRequestWrapper<>& request);

    static void FillDeleteRolePrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreDeleteRolePrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillDeleteRolePrerequisiteCreateRoleRequest(PlayFab::Wrappers::PFGroupsCreateGroupRoleRequestWrapper<>& request);
    static HRESULT StoreDeleteRolePrerequisiteCreateRoleResponse(std::shared_ptr<CreateGroupRoleResponseHolder> result);
    static void FillDeleteRoleRequest(PlayFab::Wrappers::PFGroupsDeleteRoleRequestWrapper<>& request);

    static void FillGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT ValidateGetGroupResponse(PFGroupsGetGroupResponse* result);

    static void FillInviteToGroupPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreInviteToGroupPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillInviteToGroupRequest(PlayFab::Wrappers::PFGroupsInviteToGroupRequestWrapper<>& request);
    static HRESULT ValidateInviteToGroupResponse(PFGroupsInviteToGroupResponse* result);
    static void FillInviteToGroupCleanupRemoveGroupInvitationRequest(PlayFab::Wrappers::PFGroupsRemoveGroupInvitationRequestWrapper<>& request);

    static void FillIsMemberPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreIsMemberPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillIsMemberRequest(PlayFab::Wrappers::PFGroupsIsMemberRequestWrapper<>& request);
    static HRESULT ValidateIsMemberResponse(PFGroupsIsMemberResponse* result);

    static void FillListGroupApplicationsPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListGroupApplicationsPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillListGroupApplicationsRequest(PlayFab::Wrappers::PFGroupsListGroupApplicationsRequestWrapper<>& request);
    static HRESULT ValidateListGroupApplicationsResponse(PFGroupsListGroupApplicationsResponse* result);

    static void FillListGroupBlocksPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListGroupBlocksPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillListGroupBlocksRequest(PlayFab::Wrappers::PFGroupsListGroupBlocksRequestWrapper<>& request);
    static HRESULT ValidateListGroupBlocksResponse(PFGroupsListGroupBlocksResponse* result);

    static void FillListGroupInvitationsPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListGroupInvitationsPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillListGroupInvitationsRequest(PlayFab::Wrappers::PFGroupsListGroupInvitationsRequestWrapper<>& request);
    static HRESULT ValidateListGroupInvitationsResponse(PFGroupsListGroupInvitationsResponse* result);

    static void FillListGroupMembersPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListGroupMembersPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillListGroupMembersRequest(PlayFab::Wrappers::PFGroupsListGroupMembersRequestWrapper<>& request);
    static HRESULT ValidateListGroupMembersResponse(PFGroupsListGroupMembersResponse* result);

    static void FillListMembershipPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListMembershipPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillListMembershipRequest(PlayFab::Wrappers::PFGroupsListMembershipRequestWrapper<>& request);
    static HRESULT ValidateListMembershipResponse(PFGroupsListMembershipResponse* result);

    static void FillListMembershipOpportunitiesPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListMembershipOpportunitiesPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillListMembershipOpportunitiesPrerequisiteApplyToGroupRequest(PlayFab::Wrappers::PFGroupsApplyToGroupRequestWrapper<>& request);
    static HRESULT StoreListMembershipOpportunitiesPrerequisiteApplyToGroupResponse(std::shared_ptr<ApplyToGroupResponseHolder> result);
    static void FillListMembershipOpportunitiesRequest(PlayFab::Wrappers::PFGroupsListMembershipOpportunitiesRequestWrapper<>& request);
    static HRESULT ValidateListMembershipOpportunitiesResponse(PFGroupsListMembershipOpportunitiesResponse* result);
    static void FillListMembershipOpportunitiesCleanupRemoveGroupApplicationRequest(PlayFab::Wrappers::PFGroupsRemoveGroupApplicationRequestWrapper<>& request);

    static void FillRemoveGroupApplicationPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreRemoveGroupApplicationPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillRemoveGroupApplicationPrerequisiteApplyToGroupRequest(PlayFab::Wrappers::PFGroupsApplyToGroupRequestWrapper<>& request);
    static HRESULT StoreRemoveGroupApplicationPrerequisiteApplyToGroupResponse(std::shared_ptr<ApplyToGroupResponseHolder> result);
    static void FillRemoveGroupApplicationRequest(PlayFab::Wrappers::PFGroupsRemoveGroupApplicationRequestWrapper<>& request);

    static void FillRemoveGroupInvitationPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreRemoveGroupInvitationPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillRemoveGroupInvitationPrerequisiteInviteToGroupRequest(PlayFab::Wrappers::PFGroupsInviteToGroupRequestWrapper<>& request);
    static HRESULT StoreRemoveGroupInvitationPrerequisiteInviteToGroupResponse(std::shared_ptr<InviteToGroupResponseHolder> result);
    static void FillRemoveGroupInvitationRequest(PlayFab::Wrappers::PFGroupsRemoveGroupInvitationRequestWrapper<>& request);

    static void FillRemoveMembersPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreRemoveMembersPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillRemoveMembersPrerequisiteAddMembersRequest(PlayFab::Wrappers::PFGroupsAddMembersRequestWrapper<>& request);
    static void FillRemoveMembersRequest(PlayFab::Wrappers::PFGroupsRemoveMembersRequestWrapper<>& request);

    static void FillUnblockEntityPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreUnblockEntityPrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillUnblockEntityPrerequisiteBlockEntityRequest(PlayFab::Wrappers::PFGroupsBlockEntityRequestWrapper<>& request);
    static void FillUnblockEntityRequest(PlayFab::Wrappers::PFGroupsUnblockEntityRequestWrapper<>& request);

    static void FillUpdateGroupPrerequisiteCreateGroupRequest(PlayFab::Wrappers::PFGroupsCreateGroupRequestWrapper<>& request);
    static HRESULT StoreUpdateGroupPrerequisiteCreateGroupResponse(std::shared_ptr<CreateGroupResponseHolder> result);
    static void FillUpdateGroupRequest(PlayFab::Wrappers::PFGroupsUpdateGroupRequestWrapper<>& request);
    static HRESULT ValidateUpdateGroupResponse(PFGroupsUpdateGroupResponse* result);
    static void FillUpdateGroupCleanupDeleteGroupRequest(PlayFab::Wrappers::PFGroupsDeleteGroupRequestWrapper<>& request);

    static void FillUpdateRolePrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreUpdateRolePrerequisiteGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillUpdateRolePrerequisiteUpdateRoleRequest(PlayFab::Wrappers::PFGroupsUpdateGroupRoleRequestWrapper<>& request);
    static HRESULT StoreUpdateRolePrerequisiteUpdateRoleResponse(std::shared_ptr<UpdateGroupRoleResponseHolder> result);
    static void FillUpdateRoleRequest(PlayFab::Wrappers::PFGroupsUpdateGroupRoleRequestWrapper<>& request);
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
