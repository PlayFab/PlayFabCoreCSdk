#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct ApplyToGroupResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ApplyToGroupResponseHolder>
{
    ApplyToGroupResponseHolder() = default;
    ApplyToGroupResponseHolder(const ApplyToGroupResponseHolder&) = delete;
    ApplyToGroupResponseHolder(ApplyToGroupResponseHolder&&) = default;
    ApplyToGroupResponseHolder& operator=(const ApplyToGroupResponseHolder&) = delete;
    ApplyToGroupResponseHolder& operator=(ApplyToGroupResponseHolder&&) = default;
    ~ApplyToGroupResponseHolder() = default;

    PFGroupsApplyToGroupResponse* result{ nullptr };
};

struct CreateGroupResponseHolder : public XAsyncResult, public std::enable_shared_from_this<CreateGroupResponseHolder>
{
    CreateGroupResponseHolder() = default;
    CreateGroupResponseHolder(const CreateGroupResponseHolder&) = delete;
    CreateGroupResponseHolder(CreateGroupResponseHolder&&) = default;
    CreateGroupResponseHolder& operator=(const CreateGroupResponseHolder&) = delete;
    CreateGroupResponseHolder& operator=(CreateGroupResponseHolder&&) = default;
    ~CreateGroupResponseHolder() = default;

    PFGroupsCreateGroupResponse* result{ nullptr };
};

struct CreateGroupRoleResponseHolder : public XAsyncResult, public std::enable_shared_from_this<CreateGroupRoleResponseHolder>
{
    CreateGroupRoleResponseHolder() = default;
    CreateGroupRoleResponseHolder(const CreateGroupRoleResponseHolder&) = delete;
    CreateGroupRoleResponseHolder(CreateGroupRoleResponseHolder&&) = default;
    CreateGroupRoleResponseHolder& operator=(const CreateGroupRoleResponseHolder&) = delete;
    CreateGroupRoleResponseHolder& operator=(CreateGroupRoleResponseHolder&&) = default;
    ~CreateGroupRoleResponseHolder() = default;

    PFGroupsCreateGroupRoleResponse* result{ nullptr };
};

struct GetGroupResponseHolder : public XAsyncResult, public std::enable_shared_from_this<GetGroupResponseHolder>
{
    GetGroupResponseHolder() = default;
    GetGroupResponseHolder(const GetGroupResponseHolder&) = delete;
    GetGroupResponseHolder(GetGroupResponseHolder&&) = default;
    GetGroupResponseHolder& operator=(const GetGroupResponseHolder&) = delete;
    GetGroupResponseHolder& operator=(GetGroupResponseHolder&&) = default;
    ~GetGroupResponseHolder() = default;

    PFGroupsGetGroupResponse* result{ nullptr };
};

struct InviteToGroupResponseHolder : public XAsyncResult, public std::enable_shared_from_this<InviteToGroupResponseHolder>
{
    InviteToGroupResponseHolder() = default;
    InviteToGroupResponseHolder(const InviteToGroupResponseHolder&) = delete;
    InviteToGroupResponseHolder(InviteToGroupResponseHolder&&) = default;
    InviteToGroupResponseHolder& operator=(const InviteToGroupResponseHolder&) = delete;
    InviteToGroupResponseHolder& operator=(InviteToGroupResponseHolder&&) = default;
    ~InviteToGroupResponseHolder() = default;

    PFGroupsInviteToGroupResponse* result{ nullptr };
};

struct IsMemberResponseHolder : public XAsyncResult, public std::enable_shared_from_this<IsMemberResponseHolder>
{
    IsMemberResponseHolder() = default;
    IsMemberResponseHolder(const IsMemberResponseHolder&) = default;
    IsMemberResponseHolder(IsMemberResponseHolder&&) = default;
    IsMemberResponseHolder& operator=(const IsMemberResponseHolder&) = default;
    IsMemberResponseHolder& operator=(IsMemberResponseHolder&&) = default;
    ~IsMemberResponseHolder() = default;

    PFGroupsIsMemberResponse result{};
};

struct ListGroupApplicationsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListGroupApplicationsResponseHolder>
{
    ListGroupApplicationsResponseHolder() = default;
    ListGroupApplicationsResponseHolder(const ListGroupApplicationsResponseHolder&) = delete;
    ListGroupApplicationsResponseHolder(ListGroupApplicationsResponseHolder&&) = default;
    ListGroupApplicationsResponseHolder& operator=(const ListGroupApplicationsResponseHolder&) = delete;
    ListGroupApplicationsResponseHolder& operator=(ListGroupApplicationsResponseHolder&&) = default;
    ~ListGroupApplicationsResponseHolder() = default;

    PFGroupsListGroupApplicationsResponse* result{ nullptr };
};

struct ListGroupBlocksResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListGroupBlocksResponseHolder>
{
    ListGroupBlocksResponseHolder() = default;
    ListGroupBlocksResponseHolder(const ListGroupBlocksResponseHolder&) = delete;
    ListGroupBlocksResponseHolder(ListGroupBlocksResponseHolder&&) = default;
    ListGroupBlocksResponseHolder& operator=(const ListGroupBlocksResponseHolder&) = delete;
    ListGroupBlocksResponseHolder& operator=(ListGroupBlocksResponseHolder&&) = default;
    ~ListGroupBlocksResponseHolder() = default;

    PFGroupsListGroupBlocksResponse* result{ nullptr };
};

struct ListGroupInvitationsResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListGroupInvitationsResponseHolder>
{
    ListGroupInvitationsResponseHolder() = default;
    ListGroupInvitationsResponseHolder(const ListGroupInvitationsResponseHolder&) = delete;
    ListGroupInvitationsResponseHolder(ListGroupInvitationsResponseHolder&&) = default;
    ListGroupInvitationsResponseHolder& operator=(const ListGroupInvitationsResponseHolder&) = delete;
    ListGroupInvitationsResponseHolder& operator=(ListGroupInvitationsResponseHolder&&) = default;
    ~ListGroupInvitationsResponseHolder() = default;

    PFGroupsListGroupInvitationsResponse* result{ nullptr };
};

struct ListGroupMembersResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListGroupMembersResponseHolder>
{
    ListGroupMembersResponseHolder() = default;
    ListGroupMembersResponseHolder(const ListGroupMembersResponseHolder&) = delete;
    ListGroupMembersResponseHolder(ListGroupMembersResponseHolder&&) = default;
    ListGroupMembersResponseHolder& operator=(const ListGroupMembersResponseHolder&) = delete;
    ListGroupMembersResponseHolder& operator=(ListGroupMembersResponseHolder&&) = default;
    ~ListGroupMembersResponseHolder() = default;

    PFGroupsListGroupMembersResponse* result{ nullptr };
};

struct ListMembershipResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListMembershipResponseHolder>
{
    ListMembershipResponseHolder() = default;
    ListMembershipResponseHolder(const ListMembershipResponseHolder&) = delete;
    ListMembershipResponseHolder(ListMembershipResponseHolder&&) = default;
    ListMembershipResponseHolder& operator=(const ListMembershipResponseHolder&) = delete;
    ListMembershipResponseHolder& operator=(ListMembershipResponseHolder&&) = default;
    ~ListMembershipResponseHolder() = default;

    PFGroupsListMembershipResponse* result{ nullptr };
};

struct ListMembershipOpportunitiesResponseHolder : public XAsyncResult, public std::enable_shared_from_this<ListMembershipOpportunitiesResponseHolder>
{
    ListMembershipOpportunitiesResponseHolder() = default;
    ListMembershipOpportunitiesResponseHolder(const ListMembershipOpportunitiesResponseHolder&) = delete;
    ListMembershipOpportunitiesResponseHolder(ListMembershipOpportunitiesResponseHolder&&) = default;
    ListMembershipOpportunitiesResponseHolder& operator=(const ListMembershipOpportunitiesResponseHolder&) = delete;
    ListMembershipOpportunitiesResponseHolder& operator=(ListMembershipOpportunitiesResponseHolder&&) = default;
    ~ListMembershipOpportunitiesResponseHolder() = default;

    PFGroupsListMembershipOpportunitiesResponse* result{ nullptr };
};

struct UpdateGroupResponseHolder : public XAsyncResult, public std::enable_shared_from_this<UpdateGroupResponseHolder>
{
    UpdateGroupResponseHolder() = default;
    UpdateGroupResponseHolder(const UpdateGroupResponseHolder&) = delete;
    UpdateGroupResponseHolder(UpdateGroupResponseHolder&&) = default;
    UpdateGroupResponseHolder& operator=(const UpdateGroupResponseHolder&) = delete;
    UpdateGroupResponseHolder& operator=(UpdateGroupResponseHolder&&) = default;
    ~UpdateGroupResponseHolder() = default;

    PFGroupsUpdateGroupResponse* result{ nullptr };
};

struct UpdateGroupRoleResponseHolder : public XAsyncResult, public std::enable_shared_from_this<UpdateGroupRoleResponseHolder>
{
    UpdateGroupRoleResponseHolder() = default;
    UpdateGroupRoleResponseHolder(const UpdateGroupRoleResponseHolder&) = delete;
    UpdateGroupRoleResponseHolder(UpdateGroupRoleResponseHolder&&) = default;
    UpdateGroupRoleResponseHolder& operator=(const UpdateGroupRoleResponseHolder&) = delete;
    UpdateGroupRoleResponseHolder& operator=(UpdateGroupRoleResponseHolder&&) = default;
    ~UpdateGroupRoleResponseHolder() = default;

    PFGroupsUpdateGroupRoleResponse* result{ nullptr };
};


}
