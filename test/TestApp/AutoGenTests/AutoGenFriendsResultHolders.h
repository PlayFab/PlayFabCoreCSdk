#pragma once

#include "XAsyncHelper.h"

namespace PlayFabUnit
{


struct AddFriendResultHolder : public XAsyncResult, public std::enable_shared_from_this<AddFriendResultHolder>
{
    AddFriendResultHolder() = default;
    AddFriendResultHolder(const AddFriendResultHolder&) = default;
    AddFriendResultHolder(AddFriendResultHolder&&) = default;
    AddFriendResultHolder& operator=(const AddFriendResultHolder&) = default;
    AddFriendResultHolder& operator=(AddFriendResultHolder&&) = default;
    ~AddFriendResultHolder() = default;

    PFFriendsAddFriendResult result{};
};

struct GetFriendsListResultHolder : public XAsyncResult, public std::enable_shared_from_this<GetFriendsListResultHolder>
{
    GetFriendsListResultHolder() = default;
    GetFriendsListResultHolder(const GetFriendsListResultHolder&) = delete;
    GetFriendsListResultHolder(GetFriendsListResultHolder&&) = default;
    GetFriendsListResultHolder& operator=(const GetFriendsListResultHolder&) = delete;
    GetFriendsListResultHolder& operator=(GetFriendsListResultHolder&&) = default;
    ~GetFriendsListResultHolder() = default;

    PFFriendsGetFriendsListResult* result{ nullptr };
};


}
