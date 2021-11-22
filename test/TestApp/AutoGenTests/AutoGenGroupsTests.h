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

    static void FillAcceptGroupApplicationPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreAcceptGroupApplicationPrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillAcceptGroupApplicationPrerequisiteApplyToGroupRequest(PlayFab::Wrappers::PFGroupsApplyToGroupRequestWrapper<>& request);
    static HRESULT StoreAcceptGroupApplicationPrerequisitePFGroupsApplyToGroupResponse(std::shared_ptr<ApplyToGroupResponseHolder> result);
    static void LogAcceptGroupApplicationRequest(PFGroupsAcceptGroupApplicationRequest const* request, const char* testName);
    static void FillAcceptGroupApplicationRequest(PlayFab::Wrappers::PFGroupsAcceptGroupApplicationRequestWrapper<>& request);
    static void FillAcceptGroupApplicationCleanupRemoveMembersRequest(PlayFab::Wrappers::PFGroupsRemoveMembersRequestWrapper<>& request);

    static void FillAcceptGroupInvitationPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreAcceptGroupInvitationPrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillAcceptGroupInvitationPrerequisiteInviteToGroupRequest(PlayFab::Wrappers::PFGroupsInviteToGroupRequestWrapper<>& request);
    static HRESULT StoreAcceptGroupInvitationPrerequisitePFGroupsInviteToGroupResponse(std::shared_ptr<InviteToGroupResponseHolder> result);
    static void LogAcceptGroupInvitationRequest(PFGroupsAcceptGroupInvitationRequest const* request, const char* testName);
    static void FillAcceptGroupInvitationRequest(PlayFab::Wrappers::PFGroupsAcceptGroupInvitationRequestWrapper<>& request);
    static void FillAcceptGroupInvitationCleanupRemoveMembersRequest(PlayFab::Wrappers::PFGroupsRemoveMembersRequestWrapper<>& request);

    static void FillAddMembersPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreAddMembersPrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void LogAddMembersRequest(PFGroupsAddMembersRequest const* request, const char* testName);
    static void FillAddMembersRequest(PlayFab::Wrappers::PFGroupsAddMembersRequestWrapper<>& request);
    static void FillAddMembersCleanupRemoveMembersRequest(PlayFab::Wrappers::PFGroupsRemoveMembersRequestWrapper<>& request);

    static void FillApplyToGroupPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreApplyToGroupPrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void LogApplyToGroupRequest(PFGroupsApplyToGroupRequest const* request, const char* testName);
    static void FillApplyToGroupRequest(PlayFab::Wrappers::PFGroupsApplyToGroupRequestWrapper<>& request);
    static HRESULT LogPFGroupsApplyToGroupResponse(PFGroupsApplyToGroupResponse const* result);
    static HRESULT ValidatePFGroupsApplyToGroupResponse(PFGroupsApplyToGroupResponse* result);
    static void FillApplyToGroupCleanupRemoveGroupApplicationRequest(PlayFab::Wrappers::PFGroupsRemoveGroupApplicationRequestWrapper<>& request);

    static void FillBlockEntityPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreBlockEntityPrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void LogBlockEntityRequest(PFGroupsBlockEntityRequest const* request, const char* testName);
    static void FillBlockEntityRequest(PlayFab::Wrappers::PFGroupsBlockEntityRequestWrapper<>& request);
    static void FillBlockEntityCleanupUnblockEntityRequest(PlayFab::Wrappers::PFGroupsUnblockEntityRequestWrapper<>& request);

    static void FillChangeMemberRolePrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreChangeMemberRolePrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void LogChangeMemberRoleRequest(PFGroupsChangeMemberRoleRequest const* request, const char* testName);
    static void FillChangeMemberRoleRequest(PlayFab::Wrappers::PFGroupsChangeMemberRoleRequestWrapper<>& request);
    static void FillChangeMemberRoleCleanupChangeMemberRoleRequest(PlayFab::Wrappers::PFGroupsChangeMemberRoleRequestWrapper<>& request);

    static void LogCreateGroupRequest(PFGroupsCreateGroupRequest const* request, const char* testName);
    static void FillCreateGroupRequest(PlayFab::Wrappers::PFGroupsCreateGroupRequestWrapper<>& request);
    static HRESULT LogPFGroupsCreateGroupResponse(PFGroupsCreateGroupResponse const* result);
    static HRESULT ValidatePFGroupsCreateGroupResponse(PFGroupsCreateGroupResponse* result);
    static void FillCreateGroupCleanupGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreCreateGroupCleanupPFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillCreateGroupCleanupDeleteGroupRequest(PlayFab::Wrappers::PFGroupsDeleteGroupRequestWrapper<>& request);

    static void FillCreateRolePrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreCreateRolePrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void LogCreateGroupRoleRequest(PFGroupsCreateGroupRoleRequest const* request, const char* testName);
    static void FillCreateGroupRoleRequest(PlayFab::Wrappers::PFGroupsCreateGroupRoleRequestWrapper<>& request);
    static HRESULT LogPFGroupsCreateGroupRoleResponse(PFGroupsCreateGroupRoleResponse const* result);
    static HRESULT ValidatePFGroupsCreateGroupRoleResponse(PFGroupsCreateGroupRoleResponse* result);
    static void FillCreateRoleCleanupDeleteRoleRequest(PlayFab::Wrappers::PFGroupsDeleteRoleRequestWrapper<>& request);

    static void FillDeleteGroupPrerequisiteCreateGroupRequest(PlayFab::Wrappers::PFGroupsCreateGroupRequestWrapper<>& request);
    static HRESULT StoreDeleteGroupPrerequisitePFGroupsCreateGroupResponse(std::shared_ptr<CreateGroupResponseHolder> result);
    static void LogDeleteGroupRequest(PFGroupsDeleteGroupRequest const* request, const char* testName);
    static void FillDeleteGroupRequest(PlayFab::Wrappers::PFGroupsDeleteGroupRequestWrapper<>& request);

    static void FillDeleteRolePrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreDeleteRolePrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillDeleteRolePrerequisiteCreateGroupRoleRequest(PlayFab::Wrappers::PFGroupsCreateGroupRoleRequestWrapper<>& request);
    static HRESULT StoreDeleteRolePrerequisitePFGroupsCreateGroupRoleResponse(std::shared_ptr<CreateGroupRoleResponseHolder> result);
    static void LogDeleteRoleRequest(PFGroupsDeleteRoleRequest const* request, const char* testName);
    static void FillDeleteRoleRequest(PlayFab::Wrappers::PFGroupsDeleteRoleRequestWrapper<>& request);

    static void LogGetGroupRequest(PFGroupsGetGroupRequest const* request, const char* testName);
    static void FillGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT LogPFGroupsGetGroupResponse(PFGroupsGetGroupResponse const* result);
    static HRESULT ValidatePFGroupsGetGroupResponse(PFGroupsGetGroupResponse* result);

    static void FillInviteToGroupPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreInviteToGroupPrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void LogInviteToGroupRequest(PFGroupsInviteToGroupRequest const* request, const char* testName);
    static void FillInviteToGroupRequest(PlayFab::Wrappers::PFGroupsInviteToGroupRequestWrapper<>& request);
    static HRESULT LogPFGroupsInviteToGroupResponse(PFGroupsInviteToGroupResponse const* result);
    static HRESULT ValidatePFGroupsInviteToGroupResponse(PFGroupsInviteToGroupResponse* result);
    static void FillInviteToGroupCleanupRemoveGroupInvitationRequest(PlayFab::Wrappers::PFGroupsRemoveGroupInvitationRequestWrapper<>& request);

    static void FillIsMemberPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreIsMemberPrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void LogIsMemberRequest(PFGroupsIsMemberRequest const* request, const char* testName);
    static void FillIsMemberRequest(PlayFab::Wrappers::PFGroupsIsMemberRequestWrapper<>& request);
    static HRESULT LogPFGroupsIsMemberResponse(PFGroupsIsMemberResponse const* result);
    static HRESULT ValidatePFGroupsIsMemberResponse(PFGroupsIsMemberResponse* result);

    static void FillListGroupApplicationsPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListGroupApplicationsPrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void LogListGroupApplicationsRequest(PFGroupsListGroupApplicationsRequest const* request, const char* testName);
    static void FillListGroupApplicationsRequest(PlayFab::Wrappers::PFGroupsListGroupApplicationsRequestWrapper<>& request);
    static HRESULT LogPFGroupsListGroupApplicationsResponse(PFGroupsListGroupApplicationsResponse const* result);
    static HRESULT ValidatePFGroupsListGroupApplicationsResponse(PFGroupsListGroupApplicationsResponse* result);

    static void FillListGroupBlocksPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListGroupBlocksPrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void LogListGroupBlocksRequest(PFGroupsListGroupBlocksRequest const* request, const char* testName);
    static void FillListGroupBlocksRequest(PlayFab::Wrappers::PFGroupsListGroupBlocksRequestWrapper<>& request);
    static HRESULT LogPFGroupsListGroupBlocksResponse(PFGroupsListGroupBlocksResponse const* result);
    static HRESULT ValidatePFGroupsListGroupBlocksResponse(PFGroupsListGroupBlocksResponse* result);

    static void FillListGroupInvitationsPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListGroupInvitationsPrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void LogListGroupInvitationsRequest(PFGroupsListGroupInvitationsRequest const* request, const char* testName);
    static void FillListGroupInvitationsRequest(PlayFab::Wrappers::PFGroupsListGroupInvitationsRequestWrapper<>& request);
    static HRESULT LogPFGroupsListGroupInvitationsResponse(PFGroupsListGroupInvitationsResponse const* result);
    static HRESULT ValidatePFGroupsListGroupInvitationsResponse(PFGroupsListGroupInvitationsResponse* result);

    static void FillListGroupMembersPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListGroupMembersPrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void LogListGroupMembersRequest(PFGroupsListGroupMembersRequest const* request, const char* testName);
    static void FillListGroupMembersRequest(PlayFab::Wrappers::PFGroupsListGroupMembersRequestWrapper<>& request);
    static HRESULT LogPFGroupsListGroupMembersResponse(PFGroupsListGroupMembersResponse const* result);
    static HRESULT ValidatePFGroupsListGroupMembersResponse(PFGroupsListGroupMembersResponse* result);

    static void FillListMembershipPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListMembershipPrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void LogListMembershipRequest(PFGroupsListMembershipRequest const* request, const char* testName);
    static void FillListMembershipRequest(PlayFab::Wrappers::PFGroupsListMembershipRequestWrapper<>& request);
    static HRESULT LogPFGroupsListMembershipResponse(PFGroupsListMembershipResponse const* result);
    static HRESULT ValidatePFGroupsListMembershipResponse(PFGroupsListMembershipResponse* result);

    static void FillListMembershipOpportunitiesPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreListMembershipOpportunitiesPrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillListMembershipOpportunitiesPrerequisiteApplyToGroupRequest(PlayFab::Wrappers::PFGroupsApplyToGroupRequestWrapper<>& request);
    static HRESULT StoreListMembershipOpportunitiesPrerequisitePFGroupsApplyToGroupResponse(std::shared_ptr<ApplyToGroupResponseHolder> result);
    static void LogListMembershipOpportunitiesRequest(PFGroupsListMembershipOpportunitiesRequest const* request, const char* testName);
    static void FillListMembershipOpportunitiesRequest(PlayFab::Wrappers::PFGroupsListMembershipOpportunitiesRequestWrapper<>& request);
    static HRESULT LogPFGroupsListMembershipOpportunitiesResponse(PFGroupsListMembershipOpportunitiesResponse const* result);
    static HRESULT ValidatePFGroupsListMembershipOpportunitiesResponse(PFGroupsListMembershipOpportunitiesResponse* result);
    static void FillListMembershipOpportunitiesCleanupRemoveGroupApplicationRequest(PlayFab::Wrappers::PFGroupsRemoveGroupApplicationRequestWrapper<>& request);

    static void FillRemoveGroupApplicationPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreRemoveGroupApplicationPrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillRemoveGroupApplicationPrerequisiteApplyToGroupRequest(PlayFab::Wrappers::PFGroupsApplyToGroupRequestWrapper<>& request);
    static HRESULT StoreRemoveGroupApplicationPrerequisitePFGroupsApplyToGroupResponse(std::shared_ptr<ApplyToGroupResponseHolder> result);
    static void LogRemoveGroupApplicationRequest(PFGroupsRemoveGroupApplicationRequest const* request, const char* testName);
    static void FillRemoveGroupApplicationRequest(PlayFab::Wrappers::PFGroupsRemoveGroupApplicationRequestWrapper<>& request);

    static void FillRemoveGroupInvitationPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreRemoveGroupInvitationPrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillRemoveGroupInvitationPrerequisiteInviteToGroupRequest(PlayFab::Wrappers::PFGroupsInviteToGroupRequestWrapper<>& request);
    static HRESULT StoreRemoveGroupInvitationPrerequisitePFGroupsInviteToGroupResponse(std::shared_ptr<InviteToGroupResponseHolder> result);
    static void LogRemoveGroupInvitationRequest(PFGroupsRemoveGroupInvitationRequest const* request, const char* testName);
    static void FillRemoveGroupInvitationRequest(PlayFab::Wrappers::PFGroupsRemoveGroupInvitationRequestWrapper<>& request);

    static void FillRemoveMembersPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreRemoveMembersPrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillRemoveMembersPrerequisiteAddMembersRequest(PlayFab::Wrappers::PFGroupsAddMembersRequestWrapper<>& request);
    static void LogRemoveMembersRequest(PFGroupsRemoveMembersRequest const* request, const char* testName);
    static void FillRemoveMembersRequest(PlayFab::Wrappers::PFGroupsRemoveMembersRequestWrapper<>& request);

    static void FillUnblockEntityPrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreUnblockEntityPrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillUnblockEntityPrerequisiteBlockEntityRequest(PlayFab::Wrappers::PFGroupsBlockEntityRequestWrapper<>& request);
    static void LogUnblockEntityRequest(PFGroupsUnblockEntityRequest const* request, const char* testName);
    static void FillUnblockEntityRequest(PlayFab::Wrappers::PFGroupsUnblockEntityRequestWrapper<>& request);

    static void FillUpdateGroupPrerequisiteCreateGroupRequest(PlayFab::Wrappers::PFGroupsCreateGroupRequestWrapper<>& request);
    static HRESULT StoreUpdateGroupPrerequisitePFGroupsCreateGroupResponse(std::shared_ptr<CreateGroupResponseHolder> result);
    static void LogUpdateGroupRequest(PFGroupsUpdateGroupRequest const* request, const char* testName);
    static void FillUpdateGroupRequest(PlayFab::Wrappers::PFGroupsUpdateGroupRequestWrapper<>& request);
    static HRESULT LogPFGroupsUpdateGroupResponse(PFGroupsUpdateGroupResponse const* result);
    static HRESULT ValidatePFGroupsUpdateGroupResponse(PFGroupsUpdateGroupResponse* result);
    static void FillUpdateGroupCleanupDeleteGroupRequest(PlayFab::Wrappers::PFGroupsDeleteGroupRequestWrapper<>& request);

    static void FillUpdateRolePrerequisiteGetGroupRequest(PlayFab::Wrappers::PFGroupsGetGroupRequestWrapper<>& request);
    static HRESULT StoreUpdateRolePrerequisitePFGroupsGetGroupResponse(std::shared_ptr<GetGroupResponseHolder> result);
    static void FillUpdateRolePrerequisiteUpdateGroupRoleRequest(PlayFab::Wrappers::PFGroupsUpdateGroupRoleRequestWrapper<>& request);
    static HRESULT StoreUpdateRolePrerequisitePFGroupsUpdateGroupRoleResponse(std::shared_ptr<UpdateGroupRoleResponseHolder> result);
    static void LogUpdateGroupRoleRequest(PFGroupsUpdateGroupRoleRequest const* request, const char* testName);
    static void FillUpdateGroupRoleRequest(PlayFab::Wrappers::PFGroupsUpdateGroupRoleRequestWrapper<>& request);
    static HRESULT LogPFGroupsUpdateGroupRoleResponse(PFGroupsUpdateGroupRoleResponse const* result);
    static HRESULT ValidatePFGroupsUpdateGroupRoleResponse(PFGroupsUpdateGroupRoleResponse* result);

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
