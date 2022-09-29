// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFLobbyDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyMemberWrapper : public ModelWrapper<PFLobbyMember, Alloc>
{
public:
    using ModelType = typename PFLobbyMember;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyMemberWrapper() = default;

    PFLobbyMemberWrapper(const PFLobbyMember& model) :
        ModelWrapper<PFLobbyMember, Alloc>{ model },
        m_memberData{ model.memberData, model.memberData + model.memberDataCount },
        m_memberEntity{ model.memberEntity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.memberEntity } : StdExtra::nullopt },
        m_pubSubConnectionHandle{ SafeString(model.pubSubConnectionHandle) }
    {
        SetModelPointers();
    }

    PFLobbyMemberWrapper(const PFLobbyMemberWrapper& src) :
        PFLobbyMemberWrapper{ src.Model() }
    {
    }

    PFLobbyMemberWrapper(PFLobbyMemberWrapper&& src) :
        PFLobbyMemberWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyMemberWrapper& operator=(PFLobbyMemberWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyMemberWrapper() = default;

    friend void swap(PFLobbyMemberWrapper& lhs, PFLobbyMemberWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_memberData, rhs.m_memberData);
        swap(lhs.m_memberEntity, rhs.m_memberEntity);
        swap(lhs.m_pubSubConnectionHandle, rhs.m_pubSubConnectionHandle);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetMemberData(StringDictionaryEntryVector<Alloc> value)
    {
        m_memberData = std::move(value);
        this->m_model.memberData =  m_memberData.empty() ? nullptr : m_memberData.data();
        this->m_model.memberDataCount =  static_cast<uint32_t>(m_memberData.size());
    }

    void SetMemberEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_memberEntity = std::move(value);
        this->m_model.memberEntity = m_memberEntity ? &m_memberEntity->Model() : nullptr;
    }

    void SetPubSubConnectionHandle(String value)
    {
        m_pubSubConnectionHandle = std::move(value);
        this->m_model.pubSubConnectionHandle =  m_pubSubConnectionHandle.empty() ? nullptr : m_pubSubConnectionHandle.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.memberData = m_memberData.empty() ? nullptr : m_memberData.data();
        this->m_model.memberEntity = m_memberEntity ?  &m_memberEntity->Model() : nullptr;
        this->m_model.pubSubConnectionHandle = m_pubSubConnectionHandle.empty() ? nullptr : m_pubSubConnectionHandle.data();
    }

    StringDictionaryEntryVector<Alloc> m_memberData;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_memberEntity;
    String m_pubSubConnectionHandle;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyCreateLobbyRequestWrapper : public ModelWrapper<PFLobbyCreateLobbyRequest, Alloc>
{
public:
    using ModelType = typename PFLobbyCreateLobbyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyCreateLobbyRequestWrapper() = default;

    PFLobbyCreateLobbyRequestWrapper(const PFLobbyCreateLobbyRequest& model) :
        ModelWrapper<PFLobbyCreateLobbyRequest, Alloc>{ model },
        m_accessPolicy{ model.accessPolicy ? StdExtra::optional<PFLobbyAccessPolicy>{ *model.accessPolicy } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_lobbyData{ model.lobbyData, model.lobbyData + model.lobbyDataCount },
        m_members{ model.members, model.members + model.membersCount },
        m_owner{ model.owner ? *model.owner : decltype(*model.owner){} },
        m_ownerMigrationPolicy{ model.ownerMigrationPolicy ? StdExtra::optional<PFLobbyOwnerMigrationPolicy>{ *model.ownerMigrationPolicy } : StdExtra::nullopt },
        m_searchData{ model.searchData, model.searchData + model.searchDataCount }
    {
        SetModelPointers();
    }

    PFLobbyCreateLobbyRequestWrapper(const PFLobbyCreateLobbyRequestWrapper& src) :
        PFLobbyCreateLobbyRequestWrapper{ src.Model() }
    {
    }

    PFLobbyCreateLobbyRequestWrapper(PFLobbyCreateLobbyRequestWrapper&& src) :
        PFLobbyCreateLobbyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyCreateLobbyRequestWrapper& operator=(PFLobbyCreateLobbyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyCreateLobbyRequestWrapper() = default;

    friend void swap(PFLobbyCreateLobbyRequestWrapper& lhs, PFLobbyCreateLobbyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_accessPolicy, rhs.m_accessPolicy);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_lobbyData, rhs.m_lobbyData);
        swap(lhs.m_members, rhs.m_members);
        swap(lhs.m_owner, rhs.m_owner);
        swap(lhs.m_ownerMigrationPolicy, rhs.m_ownerMigrationPolicy);
        swap(lhs.m_searchData, rhs.m_searchData);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAccessPolicy(StdExtra::optional<PFLobbyAccessPolicy> value)
    {
        m_accessPolicy = std::move(value);
        this->m_model.accessPolicy = m_accessPolicy ? m_accessPolicy.operator->() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetLobbyData(StringDictionaryEntryVector<Alloc> value)
    {
        m_lobbyData = std::move(value);
        this->m_model.lobbyData =  m_lobbyData.empty() ? nullptr : m_lobbyData.data();
        this->m_model.lobbyDataCount =  static_cast<uint32_t>(m_lobbyData.size());
    }

    void SetMaxPlayers(uint32_t value)
    {
        this->m_model.maxPlayers = value;
    }

    void SetMembers(ModelVector<PFLobbyMemberWrapper<Alloc>, Alloc> value)
    {
        m_members = std::move(value);
        this->m_model.members =  m_members.empty() ? nullptr : m_members.data();
        this->m_model.membersCount =  static_cast<uint32_t>(m_members.size());
    }

    void SetOwner(PFEntityKeyWrapper<Alloc> value)
    {
        m_owner = std::move(value);
        this->m_model.owner = &m_owner.Model();
    }

    void SetOwnerMigrationPolicy(StdExtra::optional<PFLobbyOwnerMigrationPolicy> value)
    {
        m_ownerMigrationPolicy = std::move(value);
        this->m_model.ownerMigrationPolicy = m_ownerMigrationPolicy ? m_ownerMigrationPolicy.operator->() : nullptr;
    }

    void SetSearchData(StringDictionaryEntryVector<Alloc> value)
    {
        m_searchData = std::move(value);
        this->m_model.searchData =  m_searchData.empty() ? nullptr : m_searchData.data();
        this->m_model.searchDataCount =  static_cast<uint32_t>(m_searchData.size());
    }

    void SetUseConnections(bool value)
    {
        this->m_model.useConnections = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.accessPolicy = m_accessPolicy ? m_accessPolicy.operator->() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.lobbyData = m_lobbyData.empty() ? nullptr : m_lobbyData.data();
        this->m_model.members = m_members.empty() ? nullptr : m_members.data();
        this->m_model.owner = &m_owner.Model();
        this->m_model.ownerMigrationPolicy = m_ownerMigrationPolicy ? m_ownerMigrationPolicy.operator->() : nullptr;
        this->m_model.searchData = m_searchData.empty() ? nullptr : m_searchData.data();
    }

    StdExtra::optional<PFLobbyAccessPolicy> m_accessPolicy;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StringDictionaryEntryVector<Alloc> m_lobbyData;
    ModelVector<PFLobbyMemberWrapper<Alloc>, Alloc> m_members;
    PFEntityKeyWrapper<Alloc> m_owner;
    StdExtra::optional<PFLobbyOwnerMigrationPolicy> m_ownerMigrationPolicy;
    StringDictionaryEntryVector<Alloc> m_searchData;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyCreateLobbyResultWrapper : public ModelWrapper<PFLobbyCreateLobbyResult, Alloc>
{
public:
    using ModelType = typename PFLobbyCreateLobbyResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyCreateLobbyResultWrapper() = default;

    PFLobbyCreateLobbyResultWrapper(const PFLobbyCreateLobbyResult& model) :
        ModelWrapper<PFLobbyCreateLobbyResult, Alloc>{ model },
        m_connectionString{ SafeString(model.connectionString) },
        m_lobbyId{ SafeString(model.lobbyId) }
    {
        SetModelPointers();
    }

    PFLobbyCreateLobbyResultWrapper(const PFLobbyCreateLobbyResultWrapper& src) :
        PFLobbyCreateLobbyResultWrapper{ src.Model() }
    {
    }

    PFLobbyCreateLobbyResultWrapper(PFLobbyCreateLobbyResultWrapper&& src) :
        PFLobbyCreateLobbyResultWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyCreateLobbyResultWrapper& operator=(PFLobbyCreateLobbyResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyCreateLobbyResultWrapper() = default;

    friend void swap(PFLobbyCreateLobbyResultWrapper& lhs, PFLobbyCreateLobbyResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_connectionString, rhs.m_connectionString);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConnectionString(String value)
    {
        m_connectionString = std::move(value);
        this->m_model.connectionString =  m_connectionString.empty() ? nullptr : m_connectionString.data();
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.connectionString = m_connectionString.empty() ? nullptr : m_connectionString.data();
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    String m_connectionString;
    String m_lobbyId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyDeleteLobbyRequestWrapper : public ModelWrapper<PFLobbyDeleteLobbyRequest, Alloc>
{
public:
    using ModelType = typename PFLobbyDeleteLobbyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyDeleteLobbyRequestWrapper() = default;

    PFLobbyDeleteLobbyRequestWrapper(const PFLobbyDeleteLobbyRequest& model) :
        ModelWrapper<PFLobbyDeleteLobbyRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_lobbyId{ SafeString(model.lobbyId) }
    {
        SetModelPointers();
    }

    PFLobbyDeleteLobbyRequestWrapper(const PFLobbyDeleteLobbyRequestWrapper& src) :
        PFLobbyDeleteLobbyRequestWrapper{ src.Model() }
    {
    }

    PFLobbyDeleteLobbyRequestWrapper(PFLobbyDeleteLobbyRequestWrapper&& src) :
        PFLobbyDeleteLobbyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyDeleteLobbyRequestWrapper& operator=(PFLobbyDeleteLobbyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyDeleteLobbyRequestWrapper() = default;

    friend void swap(PFLobbyDeleteLobbyRequestWrapper& lhs, PFLobbyDeleteLobbyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_lobbyId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyPaginationRequestWrapper : public ModelWrapper<PFLobbyPaginationRequest, Alloc>
{
public:
    using ModelType = typename PFLobbyPaginationRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyPaginationRequestWrapper() = default;

    PFLobbyPaginationRequestWrapper(const PFLobbyPaginationRequest& model) :
        ModelWrapper<PFLobbyPaginationRequest, Alloc>{ model },
        m_continuationToken{ SafeString(model.continuationToken) },
        m_pageSizeRequested{ model.pageSizeRequested ? StdExtra::optional<uint32_t>{ *model.pageSizeRequested } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLobbyPaginationRequestWrapper(const PFLobbyPaginationRequestWrapper& src) :
        PFLobbyPaginationRequestWrapper{ src.Model() }
    {
    }

    PFLobbyPaginationRequestWrapper(PFLobbyPaginationRequestWrapper&& src) :
        PFLobbyPaginationRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyPaginationRequestWrapper& operator=(PFLobbyPaginationRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyPaginationRequestWrapper() = default;

    friend void swap(PFLobbyPaginationRequestWrapper& lhs, PFLobbyPaginationRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_continuationToken, rhs.m_continuationToken);
        swap(lhs.m_pageSizeRequested, rhs.m_pageSizeRequested);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetContinuationToken(String value)
    {
        m_continuationToken = std::move(value);
        this->m_model.continuationToken =  m_continuationToken.empty() ? nullptr : m_continuationToken.data();
    }

    void SetPageSizeRequested(StdExtra::optional<uint32_t> value)
    {
        m_pageSizeRequested = std::move(value);
        this->m_model.pageSizeRequested = m_pageSizeRequested ? m_pageSizeRequested.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.continuationToken = m_continuationToken.empty() ? nullptr : m_continuationToken.data();
        this->m_model.pageSizeRequested = m_pageSizeRequested ? m_pageSizeRequested.operator->() : nullptr;
    }

    String m_continuationToken;
    StdExtra::optional<uint32_t> m_pageSizeRequested;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyFindFriendLobbiesRequestWrapper : public ModelWrapper<PFLobbyFindFriendLobbiesRequest, Alloc>
{
public:
    using ModelType = typename PFLobbyFindFriendLobbiesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyFindFriendLobbiesRequestWrapper() = default;

    PFLobbyFindFriendLobbiesRequestWrapper(const PFLobbyFindFriendLobbiesRequest& model) :
        ModelWrapper<PFLobbyFindFriendLobbiesRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_filter{ SafeString(model.filter) },
        m_orderBy{ SafeString(model.orderBy) },
        m_pagination{ model.pagination ? StdExtra::optional<PFLobbyPaginationRequestWrapper<Alloc>>{ *model.pagination } : StdExtra::nullopt },
        m_xboxToken{ SafeString(model.xboxToken) }
    {
        SetModelPointers();
    }

    PFLobbyFindFriendLobbiesRequestWrapper(const PFLobbyFindFriendLobbiesRequestWrapper& src) :
        PFLobbyFindFriendLobbiesRequestWrapper{ src.Model() }
    {
    }

    PFLobbyFindFriendLobbiesRequestWrapper(PFLobbyFindFriendLobbiesRequestWrapper&& src) :
        PFLobbyFindFriendLobbiesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyFindFriendLobbiesRequestWrapper& operator=(PFLobbyFindFriendLobbiesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyFindFriendLobbiesRequestWrapper() = default;

    friend void swap(PFLobbyFindFriendLobbiesRequestWrapper& lhs, PFLobbyFindFriendLobbiesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_filter, rhs.m_filter);
        swap(lhs.m_orderBy, rhs.m_orderBy);
        swap(lhs.m_pagination, rhs.m_pagination);
        swap(lhs.m_xboxToken, rhs.m_xboxToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetExcludeFacebookFriends(bool value)
    {
        this->m_model.excludeFacebookFriends = value;
    }

    void SetExcludeSteamFriends(bool value)
    {
        this->m_model.excludeSteamFriends = value;
    }

    void SetFilter(String value)
    {
        m_filter = std::move(value);
        this->m_model.filter =  m_filter.empty() ? nullptr : m_filter.data();
    }

    void SetOrderBy(String value)
    {
        m_orderBy = std::move(value);
        this->m_model.orderBy =  m_orderBy.empty() ? nullptr : m_orderBy.data();
    }

    void SetPagination(StdExtra::optional<PFLobbyPaginationRequestWrapper<Alloc>> value)
    {
        m_pagination = std::move(value);
        this->m_model.pagination = m_pagination ? &m_pagination->Model() : nullptr;
    }

    void SetXboxToken(String value)
    {
        m_xboxToken = std::move(value);
        this->m_model.xboxToken =  m_xboxToken.empty() ? nullptr : m_xboxToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.filter = m_filter.empty() ? nullptr : m_filter.data();
        this->m_model.orderBy = m_orderBy.empty() ? nullptr : m_orderBy.data();
        this->m_model.pagination = m_pagination ?  &m_pagination->Model() : nullptr;
        this->m_model.xboxToken = m_xboxToken.empty() ? nullptr : m_xboxToken.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_filter;
    String m_orderBy;
    StdExtra::optional<PFLobbyPaginationRequestWrapper<Alloc>> m_pagination;
    String m_xboxToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyFriendLobbySummaryWrapper : public ModelWrapper<PFLobbyFriendLobbySummary, Alloc>
{
public:
    using ModelType = typename PFLobbyFriendLobbySummary;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyFriendLobbySummaryWrapper() = default;

    PFLobbyFriendLobbySummaryWrapper(const PFLobbyFriendLobbySummary& model) :
        ModelWrapper<PFLobbyFriendLobbySummary, Alloc>{ model },
        m_connectionString{ SafeString(model.connectionString) },
        m_friends{ model.friends, model.friends + model.friendsCount },
        m_lobbyId{ SafeString(model.lobbyId) },
        m_membershipLock{ model.membershipLock ? StdExtra::optional<PFLobbyMembershipLock>{ *model.membershipLock } : StdExtra::nullopt },
        m_owner{ model.owner ? *model.owner : decltype(*model.owner){} },
        m_searchData{ model.searchData, model.searchData + model.searchDataCount }
    {
        SetModelPointers();
    }

    PFLobbyFriendLobbySummaryWrapper(const PFLobbyFriendLobbySummaryWrapper& src) :
        PFLobbyFriendLobbySummaryWrapper{ src.Model() }
    {
    }

    PFLobbyFriendLobbySummaryWrapper(PFLobbyFriendLobbySummaryWrapper&& src) :
        PFLobbyFriendLobbySummaryWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyFriendLobbySummaryWrapper& operator=(PFLobbyFriendLobbySummaryWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyFriendLobbySummaryWrapper() = default;

    friend void swap(PFLobbyFriendLobbySummaryWrapper& lhs, PFLobbyFriendLobbySummaryWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_connectionString, rhs.m_connectionString);
        swap(lhs.m_friends, rhs.m_friends);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        swap(lhs.m_membershipLock, rhs.m_membershipLock);
        swap(lhs.m_owner, rhs.m_owner);
        swap(lhs.m_searchData, rhs.m_searchData);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConnectionString(String value)
    {
        m_connectionString = std::move(value);
        this->m_model.connectionString =  m_connectionString.empty() ? nullptr : m_connectionString.data();
    }

    void SetCurrentPlayers(uint32_t value)
    {
        this->m_model.currentPlayers = value;
    }

    void SetFriends(ModelVector<PFEntityKeyWrapper<Alloc>, Alloc> value)
    {
        m_friends = std::move(value);
        this->m_model.friends =  m_friends.empty() ? nullptr : m_friends.data();
        this->m_model.friendsCount =  static_cast<uint32_t>(m_friends.size());
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    void SetMaxPlayers(uint32_t value)
    {
        this->m_model.maxPlayers = value;
    }

    void SetMembershipLock(StdExtra::optional<PFLobbyMembershipLock> value)
    {
        m_membershipLock = std::move(value);
        this->m_model.membershipLock = m_membershipLock ? m_membershipLock.operator->() : nullptr;
    }

    void SetOwner(PFEntityKeyWrapper<Alloc> value)
    {
        m_owner = std::move(value);
        this->m_model.owner = &m_owner.Model();
    }

    void SetSearchData(StringDictionaryEntryVector<Alloc> value)
    {
        m_searchData = std::move(value);
        this->m_model.searchData =  m_searchData.empty() ? nullptr : m_searchData.data();
        this->m_model.searchDataCount =  static_cast<uint32_t>(m_searchData.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.connectionString = m_connectionString.empty() ? nullptr : m_connectionString.data();
        this->m_model.friends = m_friends.empty() ? nullptr : m_friends.data();
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
        this->m_model.membershipLock = m_membershipLock ? m_membershipLock.operator->() : nullptr;
        this->m_model.owner = &m_owner.Model();
        this->m_model.searchData = m_searchData.empty() ? nullptr : m_searchData.data();
    }

    String m_connectionString;
    ModelVector<PFEntityKeyWrapper<Alloc>, Alloc> m_friends;
    String m_lobbyId;
    StdExtra::optional<PFLobbyMembershipLock> m_membershipLock;
    PFEntityKeyWrapper<Alloc> m_owner;
    StringDictionaryEntryVector<Alloc> m_searchData;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyPaginationResponseWrapper : public ModelWrapper<PFLobbyPaginationResponse, Alloc>
{
public:
    using ModelType = typename PFLobbyPaginationResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyPaginationResponseWrapper() = default;

    PFLobbyPaginationResponseWrapper(const PFLobbyPaginationResponse& model) :
        ModelWrapper<PFLobbyPaginationResponse, Alloc>{ model },
        m_continuationToken{ SafeString(model.continuationToken) },
        m_totalMatchedLobbyCount{ model.totalMatchedLobbyCount ? StdExtra::optional<uint32_t>{ *model.totalMatchedLobbyCount } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLobbyPaginationResponseWrapper(const PFLobbyPaginationResponseWrapper& src) :
        PFLobbyPaginationResponseWrapper{ src.Model() }
    {
    }

    PFLobbyPaginationResponseWrapper(PFLobbyPaginationResponseWrapper&& src) :
        PFLobbyPaginationResponseWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyPaginationResponseWrapper& operator=(PFLobbyPaginationResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyPaginationResponseWrapper() = default;

    friend void swap(PFLobbyPaginationResponseWrapper& lhs, PFLobbyPaginationResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_continuationToken, rhs.m_continuationToken);
        swap(lhs.m_totalMatchedLobbyCount, rhs.m_totalMatchedLobbyCount);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetContinuationToken(String value)
    {
        m_continuationToken = std::move(value);
        this->m_model.continuationToken =  m_continuationToken.empty() ? nullptr : m_continuationToken.data();
    }

    void SetTotalMatchedLobbyCount(StdExtra::optional<uint32_t> value)
    {
        m_totalMatchedLobbyCount = std::move(value);
        this->m_model.totalMatchedLobbyCount = m_totalMatchedLobbyCount ? m_totalMatchedLobbyCount.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.continuationToken = m_continuationToken.empty() ? nullptr : m_continuationToken.data();
        this->m_model.totalMatchedLobbyCount = m_totalMatchedLobbyCount ? m_totalMatchedLobbyCount.operator->() : nullptr;
    }

    String m_continuationToken;
    StdExtra::optional<uint32_t> m_totalMatchedLobbyCount;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyFindFriendLobbiesResultWrapper : public ModelWrapper<PFLobbyFindFriendLobbiesResult, Alloc>
{
public:
    using ModelType = typename PFLobbyFindFriendLobbiesResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyFindFriendLobbiesResultWrapper() = default;

    PFLobbyFindFriendLobbiesResultWrapper(const PFLobbyFindFriendLobbiesResult& model) :
        ModelWrapper<PFLobbyFindFriendLobbiesResult, Alloc>{ model },
        m_lobbies{ model.lobbies, model.lobbies + model.lobbiesCount },
        m_pagination{ model.pagination ? *model.pagination : decltype(*model.pagination){} }
    {
        SetModelPointers();
    }

    PFLobbyFindFriendLobbiesResultWrapper(const PFLobbyFindFriendLobbiesResultWrapper& src) :
        PFLobbyFindFriendLobbiesResultWrapper{ src.Model() }
    {
    }

    PFLobbyFindFriendLobbiesResultWrapper(PFLobbyFindFriendLobbiesResultWrapper&& src) :
        PFLobbyFindFriendLobbiesResultWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyFindFriendLobbiesResultWrapper& operator=(PFLobbyFindFriendLobbiesResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyFindFriendLobbiesResultWrapper() = default;

    friend void swap(PFLobbyFindFriendLobbiesResultWrapper& lhs, PFLobbyFindFriendLobbiesResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_lobbies, rhs.m_lobbies);
        swap(lhs.m_pagination, rhs.m_pagination);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLobbies(ModelVector<PFLobbyFriendLobbySummaryWrapper<Alloc>, Alloc> value)
    {
        m_lobbies = std::move(value);
        this->m_model.lobbies =  m_lobbies.empty() ? nullptr : m_lobbies.data();
        this->m_model.lobbiesCount =  static_cast<uint32_t>(m_lobbies.size());
    }

    void SetPagination(PFLobbyPaginationResponseWrapper<Alloc> value)
    {
        m_pagination = std::move(value);
        this->m_model.pagination = &m_pagination.Model();
    }

private:
    void SetModelPointers()
    {
        this->m_model.lobbies = m_lobbies.empty() ? nullptr : m_lobbies.data();
        this->m_model.pagination = &m_pagination.Model();
    }

    ModelVector<PFLobbyFriendLobbySummaryWrapper<Alloc>, Alloc> m_lobbies;
    PFLobbyPaginationResponseWrapper<Alloc> m_pagination;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyFindLobbiesRequestWrapper : public ModelWrapper<PFLobbyFindLobbiesRequest, Alloc>
{
public:
    using ModelType = typename PFLobbyFindLobbiesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyFindLobbiesRequestWrapper() = default;

    PFLobbyFindLobbiesRequestWrapper(const PFLobbyFindLobbiesRequest& model) :
        ModelWrapper<PFLobbyFindLobbiesRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_filter{ SafeString(model.filter) },
        m_orderBy{ SafeString(model.orderBy) },
        m_pagination{ model.pagination ? StdExtra::optional<PFLobbyPaginationRequestWrapper<Alloc>>{ *model.pagination } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLobbyFindLobbiesRequestWrapper(const PFLobbyFindLobbiesRequestWrapper& src) :
        PFLobbyFindLobbiesRequestWrapper{ src.Model() }
    {
    }

    PFLobbyFindLobbiesRequestWrapper(PFLobbyFindLobbiesRequestWrapper&& src) :
        PFLobbyFindLobbiesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyFindLobbiesRequestWrapper& operator=(PFLobbyFindLobbiesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyFindLobbiesRequestWrapper() = default;

    friend void swap(PFLobbyFindLobbiesRequestWrapper& lhs, PFLobbyFindLobbiesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_filter, rhs.m_filter);
        swap(lhs.m_orderBy, rhs.m_orderBy);
        swap(lhs.m_pagination, rhs.m_pagination);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetFilter(String value)
    {
        m_filter = std::move(value);
        this->m_model.filter =  m_filter.empty() ? nullptr : m_filter.data();
    }

    void SetOrderBy(String value)
    {
        m_orderBy = std::move(value);
        this->m_model.orderBy =  m_orderBy.empty() ? nullptr : m_orderBy.data();
    }

    void SetPagination(StdExtra::optional<PFLobbyPaginationRequestWrapper<Alloc>> value)
    {
        m_pagination = std::move(value);
        this->m_model.pagination = m_pagination ? &m_pagination->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.filter = m_filter.empty() ? nullptr : m_filter.data();
        this->m_model.orderBy = m_orderBy.empty() ? nullptr : m_orderBy.data();
        this->m_model.pagination = m_pagination ?  &m_pagination->Model() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_filter;
    String m_orderBy;
    StdExtra::optional<PFLobbyPaginationRequestWrapper<Alloc>> m_pagination;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyLobbySummaryWrapper : public ModelWrapper<PFLobbyLobbySummary, Alloc>
{
public:
    using ModelType = typename PFLobbyLobbySummary;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyLobbySummaryWrapper() = default;

    PFLobbyLobbySummaryWrapper(const PFLobbyLobbySummary& model) :
        ModelWrapper<PFLobbyLobbySummary, Alloc>{ model },
        m_connectionString{ SafeString(model.connectionString) },
        m_lobbyId{ SafeString(model.lobbyId) },
        m_membershipLock{ model.membershipLock ? StdExtra::optional<PFLobbyMembershipLock>{ *model.membershipLock } : StdExtra::nullopt },
        m_owner{ model.owner ? *model.owner : decltype(*model.owner){} },
        m_searchData{ model.searchData, model.searchData + model.searchDataCount }
    {
        SetModelPointers();
    }

    PFLobbyLobbySummaryWrapper(const PFLobbyLobbySummaryWrapper& src) :
        PFLobbyLobbySummaryWrapper{ src.Model() }
    {
    }

    PFLobbyLobbySummaryWrapper(PFLobbyLobbySummaryWrapper&& src) :
        PFLobbyLobbySummaryWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyLobbySummaryWrapper& operator=(PFLobbyLobbySummaryWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyLobbySummaryWrapper() = default;

    friend void swap(PFLobbyLobbySummaryWrapper& lhs, PFLobbyLobbySummaryWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_connectionString, rhs.m_connectionString);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        swap(lhs.m_membershipLock, rhs.m_membershipLock);
        swap(lhs.m_owner, rhs.m_owner);
        swap(lhs.m_searchData, rhs.m_searchData);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConnectionString(String value)
    {
        m_connectionString = std::move(value);
        this->m_model.connectionString =  m_connectionString.empty() ? nullptr : m_connectionString.data();
    }

    void SetCurrentPlayers(uint32_t value)
    {
        this->m_model.currentPlayers = value;
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    void SetMaxPlayers(uint32_t value)
    {
        this->m_model.maxPlayers = value;
    }

    void SetMembershipLock(StdExtra::optional<PFLobbyMembershipLock> value)
    {
        m_membershipLock = std::move(value);
        this->m_model.membershipLock = m_membershipLock ? m_membershipLock.operator->() : nullptr;
    }

    void SetOwner(PFEntityKeyWrapper<Alloc> value)
    {
        m_owner = std::move(value);
        this->m_model.owner = &m_owner.Model();
    }

    void SetSearchData(StringDictionaryEntryVector<Alloc> value)
    {
        m_searchData = std::move(value);
        this->m_model.searchData =  m_searchData.empty() ? nullptr : m_searchData.data();
        this->m_model.searchDataCount =  static_cast<uint32_t>(m_searchData.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.connectionString = m_connectionString.empty() ? nullptr : m_connectionString.data();
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
        this->m_model.membershipLock = m_membershipLock ? m_membershipLock.operator->() : nullptr;
        this->m_model.owner = &m_owner.Model();
        this->m_model.searchData = m_searchData.empty() ? nullptr : m_searchData.data();
    }

    String m_connectionString;
    String m_lobbyId;
    StdExtra::optional<PFLobbyMembershipLock> m_membershipLock;
    PFEntityKeyWrapper<Alloc> m_owner;
    StringDictionaryEntryVector<Alloc> m_searchData;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyFindLobbiesResultWrapper : public ModelWrapper<PFLobbyFindLobbiesResult, Alloc>
{
public:
    using ModelType = typename PFLobbyFindLobbiesResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyFindLobbiesResultWrapper() = default;

    PFLobbyFindLobbiesResultWrapper(const PFLobbyFindLobbiesResult& model) :
        ModelWrapper<PFLobbyFindLobbiesResult, Alloc>{ model },
        m_lobbies{ model.lobbies, model.lobbies + model.lobbiesCount },
        m_pagination{ model.pagination ? *model.pagination : decltype(*model.pagination){} }
    {
        SetModelPointers();
    }

    PFLobbyFindLobbiesResultWrapper(const PFLobbyFindLobbiesResultWrapper& src) :
        PFLobbyFindLobbiesResultWrapper{ src.Model() }
    {
    }

    PFLobbyFindLobbiesResultWrapper(PFLobbyFindLobbiesResultWrapper&& src) :
        PFLobbyFindLobbiesResultWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyFindLobbiesResultWrapper& operator=(PFLobbyFindLobbiesResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyFindLobbiesResultWrapper() = default;

    friend void swap(PFLobbyFindLobbiesResultWrapper& lhs, PFLobbyFindLobbiesResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_lobbies, rhs.m_lobbies);
        swap(lhs.m_pagination, rhs.m_pagination);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLobbies(ModelVector<PFLobbyLobbySummaryWrapper<Alloc>, Alloc> value)
    {
        m_lobbies = std::move(value);
        this->m_model.lobbies =  m_lobbies.empty() ? nullptr : m_lobbies.data();
        this->m_model.lobbiesCount =  static_cast<uint32_t>(m_lobbies.size());
    }

    void SetPagination(PFLobbyPaginationResponseWrapper<Alloc> value)
    {
        m_pagination = std::move(value);
        this->m_model.pagination = &m_pagination.Model();
    }

private:
    void SetModelPointers()
    {
        this->m_model.lobbies = m_lobbies.empty() ? nullptr : m_lobbies.data();
        this->m_model.pagination = &m_pagination.Model();
    }

    ModelVector<PFLobbyLobbySummaryWrapper<Alloc>, Alloc> m_lobbies;
    PFLobbyPaginationResponseWrapper<Alloc> m_pagination;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyGetLobbyRequestWrapper : public ModelWrapper<PFLobbyGetLobbyRequest, Alloc>
{
public:
    using ModelType = typename PFLobbyGetLobbyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyGetLobbyRequestWrapper() = default;

    PFLobbyGetLobbyRequestWrapper(const PFLobbyGetLobbyRequest& model) :
        ModelWrapper<PFLobbyGetLobbyRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_lobbyId{ SafeString(model.lobbyId) }
    {
        SetModelPointers();
    }

    PFLobbyGetLobbyRequestWrapper(const PFLobbyGetLobbyRequestWrapper& src) :
        PFLobbyGetLobbyRequestWrapper{ src.Model() }
    {
    }

    PFLobbyGetLobbyRequestWrapper(PFLobbyGetLobbyRequestWrapper&& src) :
        PFLobbyGetLobbyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyGetLobbyRequestWrapper& operator=(PFLobbyGetLobbyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyGetLobbyRequestWrapper() = default;

    friend void swap(PFLobbyGetLobbyRequestWrapper& lhs, PFLobbyGetLobbyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_lobbyId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyLobbyWrapper : public ModelWrapper<PFLobbyLobby, Alloc>
{
public:
    using ModelType = typename PFLobbyLobby;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyLobbyWrapper() = default;

    PFLobbyLobbyWrapper(const PFLobbyLobby& model) :
        ModelWrapper<PFLobbyLobby, Alloc>{ model },
        m_connectionString{ SafeString(model.connectionString) },
        m_lobbyData{ model.lobbyData, model.lobbyData + model.lobbyDataCount },
        m_lobbyId{ SafeString(model.lobbyId) },
        m_members{ model.members, model.members + model.membersCount },
        m_owner{ model.owner ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.owner } : StdExtra::nullopt },
        m_ownerMigrationPolicy{ model.ownerMigrationPolicy ? StdExtra::optional<PFLobbyOwnerMigrationPolicy>{ *model.ownerMigrationPolicy } : StdExtra::nullopt },
        m_pubSubConnectionHandle{ SafeString(model.pubSubConnectionHandle) },
        m_searchData{ model.searchData, model.searchData + model.searchDataCount }
    {
        SetModelPointers();
    }

    PFLobbyLobbyWrapper(const PFLobbyLobbyWrapper& src) :
        PFLobbyLobbyWrapper{ src.Model() }
    {
    }

    PFLobbyLobbyWrapper(PFLobbyLobbyWrapper&& src) :
        PFLobbyLobbyWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyLobbyWrapper& operator=(PFLobbyLobbyWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyLobbyWrapper() = default;

    friend void swap(PFLobbyLobbyWrapper& lhs, PFLobbyLobbyWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_connectionString, rhs.m_connectionString);
        swap(lhs.m_lobbyData, rhs.m_lobbyData);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        swap(lhs.m_members, rhs.m_members);
        swap(lhs.m_owner, rhs.m_owner);
        swap(lhs.m_ownerMigrationPolicy, rhs.m_ownerMigrationPolicy);
        swap(lhs.m_pubSubConnectionHandle, rhs.m_pubSubConnectionHandle);
        swap(lhs.m_searchData, rhs.m_searchData);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAccessPolicy(PFLobbyAccessPolicy value)
    {
        this->m_model.accessPolicy = value;
    }

    void SetChangeNumber(uint32_t value)
    {
        this->m_model.changeNumber = value;
    }

    void SetConnectionString(String value)
    {
        m_connectionString = std::move(value);
        this->m_model.connectionString =  m_connectionString.empty() ? nullptr : m_connectionString.data();
    }

    void SetLobbyData(StringDictionaryEntryVector<Alloc> value)
    {
        m_lobbyData = std::move(value);
        this->m_model.lobbyData =  m_lobbyData.empty() ? nullptr : m_lobbyData.data();
        this->m_model.lobbyDataCount =  static_cast<uint32_t>(m_lobbyData.size());
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    void SetMaxPlayers(uint32_t value)
    {
        this->m_model.maxPlayers = value;
    }

    void SetMembers(ModelVector<PFLobbyMemberWrapper<Alloc>, Alloc> value)
    {
        m_members = std::move(value);
        this->m_model.members =  m_members.empty() ? nullptr : m_members.data();
        this->m_model.membersCount =  static_cast<uint32_t>(m_members.size());
    }

    void SetMembershipLock(PFLobbyMembershipLock value)
    {
        this->m_model.membershipLock = value;
    }

    void SetOwner(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_owner = std::move(value);
        this->m_model.owner = m_owner ? &m_owner->Model() : nullptr;
    }

    void SetOwnerMigrationPolicy(StdExtra::optional<PFLobbyOwnerMigrationPolicy> value)
    {
        m_ownerMigrationPolicy = std::move(value);
        this->m_model.ownerMigrationPolicy = m_ownerMigrationPolicy ? m_ownerMigrationPolicy.operator->() : nullptr;
    }

    void SetPubSubConnectionHandle(String value)
    {
        m_pubSubConnectionHandle = std::move(value);
        this->m_model.pubSubConnectionHandle =  m_pubSubConnectionHandle.empty() ? nullptr : m_pubSubConnectionHandle.data();
    }

    void SetSearchData(StringDictionaryEntryVector<Alloc> value)
    {
        m_searchData = std::move(value);
        this->m_model.searchData =  m_searchData.empty() ? nullptr : m_searchData.data();
        this->m_model.searchDataCount =  static_cast<uint32_t>(m_searchData.size());
    }

    void SetUseConnections(bool value)
    {
        this->m_model.useConnections = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.connectionString = m_connectionString.empty() ? nullptr : m_connectionString.data();
        this->m_model.lobbyData = m_lobbyData.empty() ? nullptr : m_lobbyData.data();
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
        this->m_model.members = m_members.empty() ? nullptr : m_members.data();
        this->m_model.owner = m_owner ?  &m_owner->Model() : nullptr;
        this->m_model.ownerMigrationPolicy = m_ownerMigrationPolicy ? m_ownerMigrationPolicy.operator->() : nullptr;
        this->m_model.pubSubConnectionHandle = m_pubSubConnectionHandle.empty() ? nullptr : m_pubSubConnectionHandle.data();
        this->m_model.searchData = m_searchData.empty() ? nullptr : m_searchData.data();
    }

    String m_connectionString;
    StringDictionaryEntryVector<Alloc> m_lobbyData;
    String m_lobbyId;
    ModelVector<PFLobbyMemberWrapper<Alloc>, Alloc> m_members;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_owner;
    StdExtra::optional<PFLobbyOwnerMigrationPolicy> m_ownerMigrationPolicy;
    String m_pubSubConnectionHandle;
    StringDictionaryEntryVector<Alloc> m_searchData;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyGetLobbyResultWrapper : public ModelWrapper<PFLobbyGetLobbyResult, Alloc>
{
public:
    using ModelType = typename PFLobbyGetLobbyResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyGetLobbyResultWrapper() = default;

    PFLobbyGetLobbyResultWrapper(const PFLobbyGetLobbyResult& model) :
        ModelWrapper<PFLobbyGetLobbyResult, Alloc>{ model },
        m_lobby{ model.lobby ? *model.lobby : decltype(*model.lobby){} }
    {
        SetModelPointers();
    }

    PFLobbyGetLobbyResultWrapper(const PFLobbyGetLobbyResultWrapper& src) :
        PFLobbyGetLobbyResultWrapper{ src.Model() }
    {
    }

    PFLobbyGetLobbyResultWrapper(PFLobbyGetLobbyResultWrapper&& src) :
        PFLobbyGetLobbyResultWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyGetLobbyResultWrapper& operator=(PFLobbyGetLobbyResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyGetLobbyResultWrapper() = default;

    friend void swap(PFLobbyGetLobbyResultWrapper& lhs, PFLobbyGetLobbyResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_lobby, rhs.m_lobby);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLobby(PFLobbyLobbyWrapper<Alloc> value)
    {
        m_lobby = std::move(value);
        this->m_model.lobby = &m_lobby.Model();
    }

private:
    void SetModelPointers()
    {
        this->m_model.lobby = &m_lobby.Model();
    }

    PFLobbyLobbyWrapper<Alloc> m_lobby;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyInviteToLobbyRequestWrapper : public ModelWrapper<PFLobbyInviteToLobbyRequest, Alloc>
{
public:
    using ModelType = typename PFLobbyInviteToLobbyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyInviteToLobbyRequestWrapper() = default;

    PFLobbyInviteToLobbyRequestWrapper(const PFLobbyInviteToLobbyRequest& model) :
        ModelWrapper<PFLobbyInviteToLobbyRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_inviteeEntity{ model.inviteeEntity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.inviteeEntity } : StdExtra::nullopt },
        m_lobbyId{ SafeString(model.lobbyId) },
        m_memberEntity{ model.memberEntity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.memberEntity } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLobbyInviteToLobbyRequestWrapper(const PFLobbyInviteToLobbyRequestWrapper& src) :
        PFLobbyInviteToLobbyRequestWrapper{ src.Model() }
    {
    }

    PFLobbyInviteToLobbyRequestWrapper(PFLobbyInviteToLobbyRequestWrapper&& src) :
        PFLobbyInviteToLobbyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyInviteToLobbyRequestWrapper& operator=(PFLobbyInviteToLobbyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyInviteToLobbyRequestWrapper() = default;

    friend void swap(PFLobbyInviteToLobbyRequestWrapper& lhs, PFLobbyInviteToLobbyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_inviteeEntity, rhs.m_inviteeEntity);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        swap(lhs.m_memberEntity, rhs.m_memberEntity);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetInviteeEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_inviteeEntity = std::move(value);
        this->m_model.inviteeEntity = m_inviteeEntity ? &m_inviteeEntity->Model() : nullptr;
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    void SetMemberEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_memberEntity = std::move(value);
        this->m_model.memberEntity = m_memberEntity ? &m_memberEntity->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.inviteeEntity = m_inviteeEntity ?  &m_inviteeEntity->Model() : nullptr;
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
        this->m_model.memberEntity = m_memberEntity ?  &m_memberEntity->Model() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_inviteeEntity;
    String m_lobbyId;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_memberEntity;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyJoinArrangedLobbyRequestWrapper : public ModelWrapper<PFLobbyJoinArrangedLobbyRequest, Alloc>
{
public:
    using ModelType = typename PFLobbyJoinArrangedLobbyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyJoinArrangedLobbyRequestWrapper() = default;

    PFLobbyJoinArrangedLobbyRequestWrapper(const PFLobbyJoinArrangedLobbyRequest& model) :
        ModelWrapper<PFLobbyJoinArrangedLobbyRequest, Alloc>{ model },
        m_accessPolicy{ model.accessPolicy ? StdExtra::optional<PFLobbyAccessPolicy>{ *model.accessPolicy } : StdExtra::nullopt },
        m_arrangementString{ SafeString(model.arrangementString) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_memberData{ model.memberData, model.memberData + model.memberDataCount },
        m_memberEntity{ model.memberEntity ? *model.memberEntity : decltype(*model.memberEntity){} },
        m_ownerMigrationPolicy{ model.ownerMigrationPolicy ? StdExtra::optional<PFLobbyOwnerMigrationPolicy>{ *model.ownerMigrationPolicy } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLobbyJoinArrangedLobbyRequestWrapper(const PFLobbyJoinArrangedLobbyRequestWrapper& src) :
        PFLobbyJoinArrangedLobbyRequestWrapper{ src.Model() }
    {
    }

    PFLobbyJoinArrangedLobbyRequestWrapper(PFLobbyJoinArrangedLobbyRequestWrapper&& src) :
        PFLobbyJoinArrangedLobbyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyJoinArrangedLobbyRequestWrapper& operator=(PFLobbyJoinArrangedLobbyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyJoinArrangedLobbyRequestWrapper() = default;

    friend void swap(PFLobbyJoinArrangedLobbyRequestWrapper& lhs, PFLobbyJoinArrangedLobbyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_accessPolicy, rhs.m_accessPolicy);
        swap(lhs.m_arrangementString, rhs.m_arrangementString);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_memberData, rhs.m_memberData);
        swap(lhs.m_memberEntity, rhs.m_memberEntity);
        swap(lhs.m_ownerMigrationPolicy, rhs.m_ownerMigrationPolicy);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAccessPolicy(StdExtra::optional<PFLobbyAccessPolicy> value)
    {
        m_accessPolicy = std::move(value);
        this->m_model.accessPolicy = m_accessPolicy ? m_accessPolicy.operator->() : nullptr;
    }

    void SetArrangementString(String value)
    {
        m_arrangementString = std::move(value);
        this->m_model.arrangementString =  m_arrangementString.empty() ? nullptr : m_arrangementString.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetMaxPlayers(uint32_t value)
    {
        this->m_model.maxPlayers = value;
    }

    void SetMemberData(StringDictionaryEntryVector<Alloc> value)
    {
        m_memberData = std::move(value);
        this->m_model.memberData =  m_memberData.empty() ? nullptr : m_memberData.data();
        this->m_model.memberDataCount =  static_cast<uint32_t>(m_memberData.size());
    }

    void SetMemberEntity(PFEntityKeyWrapper<Alloc> value)
    {
        m_memberEntity = std::move(value);
        this->m_model.memberEntity = &m_memberEntity.Model();
    }

    void SetOwnerMigrationPolicy(StdExtra::optional<PFLobbyOwnerMigrationPolicy> value)
    {
        m_ownerMigrationPolicy = std::move(value);
        this->m_model.ownerMigrationPolicy = m_ownerMigrationPolicy ? m_ownerMigrationPolicy.operator->() : nullptr;
    }

    void SetUseConnections(bool value)
    {
        this->m_model.useConnections = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.accessPolicy = m_accessPolicy ? m_accessPolicy.operator->() : nullptr;
        this->m_model.arrangementString = m_arrangementString.empty() ? nullptr : m_arrangementString.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.memberData = m_memberData.empty() ? nullptr : m_memberData.data();
        this->m_model.memberEntity = &m_memberEntity.Model();
        this->m_model.ownerMigrationPolicy = m_ownerMigrationPolicy ? m_ownerMigrationPolicy.operator->() : nullptr;
    }

    StdExtra::optional<PFLobbyAccessPolicy> m_accessPolicy;
    String m_arrangementString;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StringDictionaryEntryVector<Alloc> m_memberData;
    PFEntityKeyWrapper<Alloc> m_memberEntity;
    StdExtra::optional<PFLobbyOwnerMigrationPolicy> m_ownerMigrationPolicy;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyJoinLobbyResultWrapper : public ModelWrapper<PFLobbyJoinLobbyResult, Alloc>
{
public:
    using ModelType = typename PFLobbyJoinLobbyResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyJoinLobbyResultWrapper() = default;

    PFLobbyJoinLobbyResultWrapper(const PFLobbyJoinLobbyResult& model) :
        ModelWrapper<PFLobbyJoinLobbyResult, Alloc>{ model },
        m_lobbyId{ SafeString(model.lobbyId) }
    {
        SetModelPointers();
    }

    PFLobbyJoinLobbyResultWrapper(const PFLobbyJoinLobbyResultWrapper& src) :
        PFLobbyJoinLobbyResultWrapper{ src.Model() }
    {
    }

    PFLobbyJoinLobbyResultWrapper(PFLobbyJoinLobbyResultWrapper&& src) :
        PFLobbyJoinLobbyResultWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyJoinLobbyResultWrapper& operator=(PFLobbyJoinLobbyResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyJoinLobbyResultWrapper() = default;

    friend void swap(PFLobbyJoinLobbyResultWrapper& lhs, PFLobbyJoinLobbyResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    String m_lobbyId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyJoinLobbyRequestWrapper : public ModelWrapper<PFLobbyJoinLobbyRequest, Alloc>
{
public:
    using ModelType = typename PFLobbyJoinLobbyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyJoinLobbyRequestWrapper() = default;

    PFLobbyJoinLobbyRequestWrapper(const PFLobbyJoinLobbyRequest& model) :
        ModelWrapper<PFLobbyJoinLobbyRequest, Alloc>{ model },
        m_connectionString{ SafeString(model.connectionString) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_memberData{ model.memberData, model.memberData + model.memberDataCount },
        m_memberEntity{ model.memberEntity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.memberEntity } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLobbyJoinLobbyRequestWrapper(const PFLobbyJoinLobbyRequestWrapper& src) :
        PFLobbyJoinLobbyRequestWrapper{ src.Model() }
    {
    }

    PFLobbyJoinLobbyRequestWrapper(PFLobbyJoinLobbyRequestWrapper&& src) :
        PFLobbyJoinLobbyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyJoinLobbyRequestWrapper& operator=(PFLobbyJoinLobbyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyJoinLobbyRequestWrapper() = default;

    friend void swap(PFLobbyJoinLobbyRequestWrapper& lhs, PFLobbyJoinLobbyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_connectionString, rhs.m_connectionString);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_memberData, rhs.m_memberData);
        swap(lhs.m_memberEntity, rhs.m_memberEntity);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConnectionString(String value)
    {
        m_connectionString = std::move(value);
        this->m_model.connectionString =  m_connectionString.empty() ? nullptr : m_connectionString.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetMemberData(StringDictionaryEntryVector<Alloc> value)
    {
        m_memberData = std::move(value);
        this->m_model.memberData =  m_memberData.empty() ? nullptr : m_memberData.data();
        this->m_model.memberDataCount =  static_cast<uint32_t>(m_memberData.size());
    }

    void SetMemberEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_memberEntity = std::move(value);
        this->m_model.memberEntity = m_memberEntity ? &m_memberEntity->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.connectionString = m_connectionString.empty() ? nullptr : m_connectionString.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.memberData = m_memberData.empty() ? nullptr : m_memberData.data();
        this->m_model.memberEntity = m_memberEntity ?  &m_memberEntity->Model() : nullptr;
    }

    String m_connectionString;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StringDictionaryEntryVector<Alloc> m_memberData;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_memberEntity;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyLeaveLobbyRequestWrapper : public ModelWrapper<PFLobbyLeaveLobbyRequest, Alloc>
{
public:
    using ModelType = typename PFLobbyLeaveLobbyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyLeaveLobbyRequestWrapper() = default;

    PFLobbyLeaveLobbyRequestWrapper(const PFLobbyLeaveLobbyRequest& model) :
        ModelWrapper<PFLobbyLeaveLobbyRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_lobbyId{ SafeString(model.lobbyId) },
        m_memberEntity{ model.memberEntity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.memberEntity } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLobbyLeaveLobbyRequestWrapper(const PFLobbyLeaveLobbyRequestWrapper& src) :
        PFLobbyLeaveLobbyRequestWrapper{ src.Model() }
    {
    }

    PFLobbyLeaveLobbyRequestWrapper(PFLobbyLeaveLobbyRequestWrapper&& src) :
        PFLobbyLeaveLobbyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyLeaveLobbyRequestWrapper& operator=(PFLobbyLeaveLobbyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyLeaveLobbyRequestWrapper() = default;

    friend void swap(PFLobbyLeaveLobbyRequestWrapper& lhs, PFLobbyLeaveLobbyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        swap(lhs.m_memberEntity, rhs.m_memberEntity);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    void SetMemberEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_memberEntity = std::move(value);
        this->m_model.memberEntity = m_memberEntity ? &m_memberEntity->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
        this->m_model.memberEntity = m_memberEntity ?  &m_memberEntity->Model() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_lobbyId;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_memberEntity;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyRemoveMemberFromLobbyRequestWrapper : public ModelWrapper<PFLobbyRemoveMemberFromLobbyRequest, Alloc>
{
public:
    using ModelType = typename PFLobbyRemoveMemberFromLobbyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyRemoveMemberFromLobbyRequestWrapper() = default;

    PFLobbyRemoveMemberFromLobbyRequestWrapper(const PFLobbyRemoveMemberFromLobbyRequest& model) :
        ModelWrapper<PFLobbyRemoveMemberFromLobbyRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_lobbyId{ SafeString(model.lobbyId) },
        m_memberEntity{ model.memberEntity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.memberEntity } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLobbyRemoveMemberFromLobbyRequestWrapper(const PFLobbyRemoveMemberFromLobbyRequestWrapper& src) :
        PFLobbyRemoveMemberFromLobbyRequestWrapper{ src.Model() }
    {
    }

    PFLobbyRemoveMemberFromLobbyRequestWrapper(PFLobbyRemoveMemberFromLobbyRequestWrapper&& src) :
        PFLobbyRemoveMemberFromLobbyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyRemoveMemberFromLobbyRequestWrapper& operator=(PFLobbyRemoveMemberFromLobbyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyRemoveMemberFromLobbyRequestWrapper() = default;

    friend void swap(PFLobbyRemoveMemberFromLobbyRequestWrapper& lhs, PFLobbyRemoveMemberFromLobbyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        swap(lhs.m_memberEntity, rhs.m_memberEntity);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    void SetMemberEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_memberEntity = std::move(value);
        this->m_model.memberEntity = m_memberEntity ? &m_memberEntity->Model() : nullptr;
    }

    void SetPreventRejoin(bool value)
    {
        this->m_model.preventRejoin = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
        this->m_model.memberEntity = m_memberEntity ?  &m_memberEntity->Model() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_lobbyId;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_memberEntity;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbySubscribeToLobbyResourceRequestWrapper : public ModelWrapper<PFLobbySubscribeToLobbyResourceRequest, Alloc>
{
public:
    using ModelType = typename PFLobbySubscribeToLobbyResourceRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbySubscribeToLobbyResourceRequestWrapper() = default;

    PFLobbySubscribeToLobbyResourceRequestWrapper(const PFLobbySubscribeToLobbyResourceRequest& model) :
        ModelWrapper<PFLobbySubscribeToLobbyResourceRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entityKey{ model.entityKey ? *model.entityKey : decltype(*model.entityKey){} },
        m_pubSubConnectionHandle{ SafeString(model.pubSubConnectionHandle) },
        m_resourceId{ SafeString(model.resourceId) }
    {
        SetModelPointers();
    }

    PFLobbySubscribeToLobbyResourceRequestWrapper(const PFLobbySubscribeToLobbyResourceRequestWrapper& src) :
        PFLobbySubscribeToLobbyResourceRequestWrapper{ src.Model() }
    {
    }

    PFLobbySubscribeToLobbyResourceRequestWrapper(PFLobbySubscribeToLobbyResourceRequestWrapper&& src) :
        PFLobbySubscribeToLobbyResourceRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLobbySubscribeToLobbyResourceRequestWrapper& operator=(PFLobbySubscribeToLobbyResourceRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbySubscribeToLobbyResourceRequestWrapper() = default;

    friend void swap(PFLobbySubscribeToLobbyResourceRequestWrapper& lhs, PFLobbySubscribeToLobbyResourceRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entityKey, rhs.m_entityKey);
        swap(lhs.m_pubSubConnectionHandle, rhs.m_pubSubConnectionHandle);
        swap(lhs.m_resourceId, rhs.m_resourceId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntityKey(PFEntityKeyWrapper<Alloc> value)
    {
        m_entityKey = std::move(value);
        this->m_model.entityKey = &m_entityKey.Model();
    }

    void SetPubSubConnectionHandle(String value)
    {
        m_pubSubConnectionHandle = std::move(value);
        this->m_model.pubSubConnectionHandle =  m_pubSubConnectionHandle.empty() ? nullptr : m_pubSubConnectionHandle.data();
    }

    void SetResourceId(String value)
    {
        m_resourceId = std::move(value);
        this->m_model.resourceId =  m_resourceId.empty() ? nullptr : m_resourceId.data();
    }

    void SetSubscriptionVersion(uint32_t value)
    {
        this->m_model.subscriptionVersion = value;
    }

    void SetType(PFLobbySubscriptionType value)
    {
        this->m_model.type = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entityKey = &m_entityKey.Model();
        this->m_model.pubSubConnectionHandle = m_pubSubConnectionHandle.empty() ? nullptr : m_pubSubConnectionHandle.data();
        this->m_model.resourceId = m_resourceId.empty() ? nullptr : m_resourceId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    PFEntityKeyWrapper<Alloc> m_entityKey;
    String m_pubSubConnectionHandle;
    String m_resourceId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbySubscribeToLobbyResourceResultWrapper : public ModelWrapper<PFLobbySubscribeToLobbyResourceResult, Alloc>
{
public:
    using ModelType = typename PFLobbySubscribeToLobbyResourceResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbySubscribeToLobbyResourceResultWrapper() = default;

    PFLobbySubscribeToLobbyResourceResultWrapper(const PFLobbySubscribeToLobbyResourceResult& model) :
        ModelWrapper<PFLobbySubscribeToLobbyResourceResult, Alloc>{ model },
        m_topic{ SafeString(model.topic) }
    {
        SetModelPointers();
    }

    PFLobbySubscribeToLobbyResourceResultWrapper(const PFLobbySubscribeToLobbyResourceResultWrapper& src) :
        PFLobbySubscribeToLobbyResourceResultWrapper{ src.Model() }
    {
    }

    PFLobbySubscribeToLobbyResourceResultWrapper(PFLobbySubscribeToLobbyResourceResultWrapper&& src) :
        PFLobbySubscribeToLobbyResourceResultWrapper{}
    {
        swap(*this, src);
    }

    PFLobbySubscribeToLobbyResourceResultWrapper& operator=(PFLobbySubscribeToLobbyResourceResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbySubscribeToLobbyResourceResultWrapper() = default;

    friend void swap(PFLobbySubscribeToLobbyResourceResultWrapper& lhs, PFLobbySubscribeToLobbyResourceResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_topic, rhs.m_topic);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTopic(String value)
    {
        m_topic = std::move(value);
        this->m_model.topic =  m_topic.empty() ? nullptr : m_topic.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.topic = m_topic.empty() ? nullptr : m_topic.data();
    }

    String m_topic;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyUnsubscribeFromLobbyResourceRequestWrapper : public ModelWrapper<PFLobbyUnsubscribeFromLobbyResourceRequest, Alloc>
{
public:
    using ModelType = typename PFLobbyUnsubscribeFromLobbyResourceRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyUnsubscribeFromLobbyResourceRequestWrapper() = default;

    PFLobbyUnsubscribeFromLobbyResourceRequestWrapper(const PFLobbyUnsubscribeFromLobbyResourceRequest& model) :
        ModelWrapper<PFLobbyUnsubscribeFromLobbyResourceRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_entityKey{ model.entityKey ? *model.entityKey : decltype(*model.entityKey){} },
        m_pubSubConnectionHandle{ SafeString(model.pubSubConnectionHandle) },
        m_resourceId{ SafeString(model.resourceId) }
    {
        SetModelPointers();
    }

    PFLobbyUnsubscribeFromLobbyResourceRequestWrapper(const PFLobbyUnsubscribeFromLobbyResourceRequestWrapper& src) :
        PFLobbyUnsubscribeFromLobbyResourceRequestWrapper{ src.Model() }
    {
    }

    PFLobbyUnsubscribeFromLobbyResourceRequestWrapper(PFLobbyUnsubscribeFromLobbyResourceRequestWrapper&& src) :
        PFLobbyUnsubscribeFromLobbyResourceRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyUnsubscribeFromLobbyResourceRequestWrapper& operator=(PFLobbyUnsubscribeFromLobbyResourceRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyUnsubscribeFromLobbyResourceRequestWrapper() = default;

    friend void swap(PFLobbyUnsubscribeFromLobbyResourceRequestWrapper& lhs, PFLobbyUnsubscribeFromLobbyResourceRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_entityKey, rhs.m_entityKey);
        swap(lhs.m_pubSubConnectionHandle, rhs.m_pubSubConnectionHandle);
        swap(lhs.m_resourceId, rhs.m_resourceId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEntityKey(PFEntityKeyWrapper<Alloc> value)
    {
        m_entityKey = std::move(value);
        this->m_model.entityKey = &m_entityKey.Model();
    }

    void SetPubSubConnectionHandle(String value)
    {
        m_pubSubConnectionHandle = std::move(value);
        this->m_model.pubSubConnectionHandle =  m_pubSubConnectionHandle.empty() ? nullptr : m_pubSubConnectionHandle.data();
    }

    void SetResourceId(String value)
    {
        m_resourceId = std::move(value);
        this->m_model.resourceId =  m_resourceId.empty() ? nullptr : m_resourceId.data();
    }

    void SetSubscriptionVersion(uint32_t value)
    {
        this->m_model.subscriptionVersion = value;
    }

    void SetType(PFLobbySubscriptionType value)
    {
        this->m_model.type = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.entityKey = &m_entityKey.Model();
        this->m_model.pubSubConnectionHandle = m_pubSubConnectionHandle.empty() ? nullptr : m_pubSubConnectionHandle.data();
        this->m_model.resourceId = m_resourceId.empty() ? nullptr : m_resourceId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    PFEntityKeyWrapper<Alloc> m_entityKey;
    String m_pubSubConnectionHandle;
    String m_resourceId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLobbyUpdateLobbyRequestWrapper : public ModelWrapper<PFLobbyUpdateLobbyRequest, Alloc>
{
public:
    using ModelType = typename PFLobbyUpdateLobbyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLobbyUpdateLobbyRequestWrapper() = default;

    PFLobbyUpdateLobbyRequestWrapper(const PFLobbyUpdateLobbyRequest& model) :
        ModelWrapper<PFLobbyUpdateLobbyRequest, Alloc>{ model },
        m_accessPolicy{ model.accessPolicy ? StdExtra::optional<PFLobbyAccessPolicy>{ *model.accessPolicy } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_lobbyData{ model.lobbyData, model.lobbyData + model.lobbyDataCount },
        m_lobbyDataToDelete{ model.lobbyDataToDelete, model.lobbyDataToDelete + model.lobbyDataToDeleteCount },
        m_lobbyId{ SafeString(model.lobbyId) },
        m_maxPlayers{ model.maxPlayers ? StdExtra::optional<uint32_t>{ *model.maxPlayers } : StdExtra::nullopt },
        m_memberData{ model.memberData, model.memberData + model.memberDataCount },
        m_memberDataToDelete{ model.memberDataToDelete, model.memberDataToDelete + model.memberDataToDeleteCount },
        m_memberEntity{ model.memberEntity ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.memberEntity } : StdExtra::nullopt },
        m_membershipLock{ model.membershipLock ? StdExtra::optional<PFLobbyMembershipLock>{ *model.membershipLock } : StdExtra::nullopt },
        m_owner{ model.owner ? StdExtra::optional<PFEntityKeyWrapper<Alloc>>{ *model.owner } : StdExtra::nullopt },
        m_searchData{ model.searchData, model.searchData + model.searchDataCount },
        m_searchDataToDelete{ model.searchDataToDelete, model.searchDataToDelete + model.searchDataToDeleteCount }
    {
        SetModelPointers();
    }

    PFLobbyUpdateLobbyRequestWrapper(const PFLobbyUpdateLobbyRequestWrapper& src) :
        PFLobbyUpdateLobbyRequestWrapper{ src.Model() }
    {
    }

    PFLobbyUpdateLobbyRequestWrapper(PFLobbyUpdateLobbyRequestWrapper&& src) :
        PFLobbyUpdateLobbyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLobbyUpdateLobbyRequestWrapper& operator=(PFLobbyUpdateLobbyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLobbyUpdateLobbyRequestWrapper() = default;

    friend void swap(PFLobbyUpdateLobbyRequestWrapper& lhs, PFLobbyUpdateLobbyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_accessPolicy, rhs.m_accessPolicy);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_lobbyData, rhs.m_lobbyData);
        swap(lhs.m_lobbyDataToDelete, rhs.m_lobbyDataToDelete);
        swap(lhs.m_lobbyId, rhs.m_lobbyId);
        swap(lhs.m_maxPlayers, rhs.m_maxPlayers);
        swap(lhs.m_memberData, rhs.m_memberData);
        swap(lhs.m_memberDataToDelete, rhs.m_memberDataToDelete);
        swap(lhs.m_memberEntity, rhs.m_memberEntity);
        swap(lhs.m_membershipLock, rhs.m_membershipLock);
        swap(lhs.m_owner, rhs.m_owner);
        swap(lhs.m_searchData, rhs.m_searchData);
        swap(lhs.m_searchDataToDelete, rhs.m_searchDataToDelete);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAccessPolicy(StdExtra::optional<PFLobbyAccessPolicy> value)
    {
        m_accessPolicy = std::move(value);
        this->m_model.accessPolicy = m_accessPolicy ? m_accessPolicy.operator->() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetLobbyData(StringDictionaryEntryVector<Alloc> value)
    {
        m_lobbyData = std::move(value);
        this->m_model.lobbyData =  m_lobbyData.empty() ? nullptr : m_lobbyData.data();
        this->m_model.lobbyDataCount =  static_cast<uint32_t>(m_lobbyData.size());
    }

    void SetLobbyDataToDelete(CStringVector<Alloc> value)
    {
        m_lobbyDataToDelete = std::move(value);
        this->m_model.lobbyDataToDelete =  m_lobbyDataToDelete.empty() ? nullptr : m_lobbyDataToDelete.data();
        this->m_model.lobbyDataToDeleteCount =  static_cast<uint32_t>(m_lobbyDataToDelete.size());
    }

    void SetLobbyId(String value)
    {
        m_lobbyId = std::move(value);
        this->m_model.lobbyId =  m_lobbyId.empty() ? nullptr : m_lobbyId.data();
    }

    void SetMaxPlayers(StdExtra::optional<uint32_t> value)
    {
        m_maxPlayers = std::move(value);
        this->m_model.maxPlayers = m_maxPlayers ? m_maxPlayers.operator->() : nullptr;
    }

    void SetMemberData(StringDictionaryEntryVector<Alloc> value)
    {
        m_memberData = std::move(value);
        this->m_model.memberData =  m_memberData.empty() ? nullptr : m_memberData.data();
        this->m_model.memberDataCount =  static_cast<uint32_t>(m_memberData.size());
    }

    void SetMemberDataToDelete(CStringVector<Alloc> value)
    {
        m_memberDataToDelete = std::move(value);
        this->m_model.memberDataToDelete =  m_memberDataToDelete.empty() ? nullptr : m_memberDataToDelete.data();
        this->m_model.memberDataToDeleteCount =  static_cast<uint32_t>(m_memberDataToDelete.size());
    }

    void SetMemberEntity(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_memberEntity = std::move(value);
        this->m_model.memberEntity = m_memberEntity ? &m_memberEntity->Model() : nullptr;
    }

    void SetMembershipLock(StdExtra::optional<PFLobbyMembershipLock> value)
    {
        m_membershipLock = std::move(value);
        this->m_model.membershipLock = m_membershipLock ? m_membershipLock.operator->() : nullptr;
    }

    void SetOwner(StdExtra::optional<PFEntityKeyWrapper<Alloc>> value)
    {
        m_owner = std::move(value);
        this->m_model.owner = m_owner ? &m_owner->Model() : nullptr;
    }

    void SetSearchData(StringDictionaryEntryVector<Alloc> value)
    {
        m_searchData = std::move(value);
        this->m_model.searchData =  m_searchData.empty() ? nullptr : m_searchData.data();
        this->m_model.searchDataCount =  static_cast<uint32_t>(m_searchData.size());
    }

    void SetSearchDataToDelete(CStringVector<Alloc> value)
    {
        m_searchDataToDelete = std::move(value);
        this->m_model.searchDataToDelete =  m_searchDataToDelete.empty() ? nullptr : m_searchDataToDelete.data();
        this->m_model.searchDataToDeleteCount =  static_cast<uint32_t>(m_searchDataToDelete.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.accessPolicy = m_accessPolicy ? m_accessPolicy.operator->() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.lobbyData = m_lobbyData.empty() ? nullptr : m_lobbyData.data();
        this->m_model.lobbyDataToDelete = m_lobbyDataToDelete.empty() ? nullptr : m_lobbyDataToDelete.data();
        this->m_model.lobbyId = m_lobbyId.empty() ? nullptr : m_lobbyId.data();
        this->m_model.maxPlayers = m_maxPlayers ? m_maxPlayers.operator->() : nullptr;
        this->m_model.memberData = m_memberData.empty() ? nullptr : m_memberData.data();
        this->m_model.memberDataToDelete = m_memberDataToDelete.empty() ? nullptr : m_memberDataToDelete.data();
        this->m_model.memberEntity = m_memberEntity ?  &m_memberEntity->Model() : nullptr;
        this->m_model.membershipLock = m_membershipLock ? m_membershipLock.operator->() : nullptr;
        this->m_model.owner = m_owner ?  &m_owner->Model() : nullptr;
        this->m_model.searchData = m_searchData.empty() ? nullptr : m_searchData.data();
        this->m_model.searchDataToDelete = m_searchDataToDelete.empty() ? nullptr : m_searchDataToDelete.data();
    }

    StdExtra::optional<PFLobbyAccessPolicy> m_accessPolicy;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StringDictionaryEntryVector<Alloc> m_lobbyData;
    CStringVector<Alloc> m_lobbyDataToDelete;
    String m_lobbyId;
    StdExtra::optional<uint32_t> m_maxPlayers;
    StringDictionaryEntryVector<Alloc> m_memberData;
    CStringVector<Alloc> m_memberDataToDelete;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_memberEntity;
    StdExtra::optional<PFLobbyMembershipLock> m_membershipLock;
    StdExtra::optional<PFEntityKeyWrapper<Alloc>> m_owner;
    StringDictionaryEntryVector<Alloc> m_searchData;
    CStringVector<Alloc> m_searchDataToDelete;
};

} // namespace Wrappers
} // namespace PlayFab
