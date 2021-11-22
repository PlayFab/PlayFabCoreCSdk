#pragma once

#include "GroupsDataModels.h"
#include "TitlePlayer.h"
#include "GlobalState.h"

namespace PlayFab
{
namespace Groups
{

class GroupsAPI
{
public:
    GroupsAPI() = delete;
    GroupsAPI(const GroupsAPI& source) = delete;
    GroupsAPI& operator=(const GroupsAPI& source) = delete;
    ~GroupsAPI() = default;

    // ------------ Generated API calls
    static AsyncOp<void> AcceptGroupApplication(SharedPtr<Entity> entity, const AcceptGroupApplicationRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AcceptGroupInvitation(SharedPtr<Entity> entity, const AcceptGroupInvitationRequest& request, const TaskQueue& queue);
    static AsyncOp<void> AddMembers(SharedPtr<Entity> entity, const AddMembersRequest& request, const TaskQueue& queue);
    static AsyncOp<ApplyToGroupResponse> ApplyToGroup(SharedPtr<Entity> entity, const ApplyToGroupRequest& request, const TaskQueue& queue);
    static AsyncOp<void> BlockEntity(SharedPtr<Entity> entity, const BlockEntityRequest& request, const TaskQueue& queue);
    static AsyncOp<void> ChangeMemberRole(SharedPtr<Entity> entity, const ChangeMemberRoleRequest& request, const TaskQueue& queue);
    static AsyncOp<CreateGroupResponse> CreateGroup(SharedPtr<Entity> entity, const CreateGroupRequest& request, const TaskQueue& queue);
    static AsyncOp<CreateGroupRoleResponse> CreateRole(SharedPtr<Entity> entity, const CreateGroupRoleRequest& request, const TaskQueue& queue);
    static AsyncOp<void> DeleteGroup(SharedPtr<Entity> entity, const DeleteGroupRequest& request, const TaskQueue& queue);
    static AsyncOp<void> DeleteRole(SharedPtr<Entity> entity, const DeleteRoleRequest& request, const TaskQueue& queue);
    static AsyncOp<GetGroupResponse> GetGroup(SharedPtr<Entity> entity, const GetGroupRequest& request, const TaskQueue& queue);
    static AsyncOp<InviteToGroupResponse> InviteToGroup(SharedPtr<Entity> entity, const InviteToGroupRequest& request, const TaskQueue& queue);
    static AsyncOp<IsMemberResponse> IsMember(SharedPtr<Entity> entity, const IsMemberRequest& request, const TaskQueue& queue);
    static AsyncOp<ListGroupApplicationsResponse> ListGroupApplications(SharedPtr<Entity> entity, const ListGroupApplicationsRequest& request, const TaskQueue& queue);
    static AsyncOp<ListGroupBlocksResponse> ListGroupBlocks(SharedPtr<Entity> entity, const ListGroupBlocksRequest& request, const TaskQueue& queue);
    static AsyncOp<ListGroupInvitationsResponse> ListGroupInvitations(SharedPtr<Entity> entity, const ListGroupInvitationsRequest& request, const TaskQueue& queue);
    static AsyncOp<ListGroupMembersResponse> ListGroupMembers(SharedPtr<Entity> entity, const ListGroupMembersRequest& request, const TaskQueue& queue);
    static AsyncOp<ListMembershipResponse> ListMembership(SharedPtr<Entity> entity, const ListMembershipRequest& request, const TaskQueue& queue);
    static AsyncOp<ListMembershipOpportunitiesResponse> ListMembershipOpportunities(SharedPtr<Entity> entity, const ListMembershipOpportunitiesRequest& request, const TaskQueue& queue);
    static AsyncOp<void> RemoveGroupApplication(SharedPtr<Entity> entity, const RemoveGroupApplicationRequest& request, const TaskQueue& queue);
    static AsyncOp<void> RemoveGroupInvitation(SharedPtr<Entity> entity, const RemoveGroupInvitationRequest& request, const TaskQueue& queue);
    static AsyncOp<void> RemoveMembers(SharedPtr<Entity> entity, const RemoveMembersRequest& request, const TaskQueue& queue);
    static AsyncOp<void> UnblockEntity(SharedPtr<Entity> entity, const UnblockEntityRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateGroupResponse> UpdateGroup(SharedPtr<Entity> entity, const UpdateGroupRequest& request, const TaskQueue& queue);
    static AsyncOp<UpdateGroupRoleResponse> UpdateRole(SharedPtr<Entity> entity, const UpdateGroupRoleRequest& request, const TaskQueue& queue);
};

} // namespace Groups
} // namespace PlayFab
