// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFSharedGroupsDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFSharedGroupsAddSharedGroupMembersRequestWrapper : public ModelWrapper<PFSharedGroupsAddSharedGroupMembersRequest, Alloc>
{
public:
    using ModelType = typename PFSharedGroupsAddSharedGroupMembersRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSharedGroupsAddSharedGroupMembersRequestWrapper() = default;

    PFSharedGroupsAddSharedGroupMembersRequestWrapper(const PFSharedGroupsAddSharedGroupMembersRequest& model) :
        ModelWrapper<PFSharedGroupsAddSharedGroupMembersRequest, Alloc>{ model },
        m_playFabIds{ model.playFabIds, model.playFabIds + model.playFabIdsCount },
        m_sharedGroupId{ SafeString(model.sharedGroupId) }
    {
        SetModelPointers();
    }

    PFSharedGroupsAddSharedGroupMembersRequestWrapper(const PFSharedGroupsAddSharedGroupMembersRequestWrapper& src) :
        PFSharedGroupsAddSharedGroupMembersRequestWrapper{ src.Model() }
    {
    }

    PFSharedGroupsAddSharedGroupMembersRequestWrapper(PFSharedGroupsAddSharedGroupMembersRequestWrapper&& src) :
        PFSharedGroupsAddSharedGroupMembersRequestWrapper{}
    {
        swap(*this, src);
    }

    PFSharedGroupsAddSharedGroupMembersRequestWrapper& operator=(PFSharedGroupsAddSharedGroupMembersRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSharedGroupsAddSharedGroupMembersRequestWrapper() = default;

    friend void swap(PFSharedGroupsAddSharedGroupMembersRequestWrapper& lhs, PFSharedGroupsAddSharedGroupMembersRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabIds, rhs.m_playFabIds);
        swap(lhs.m_sharedGroupId, rhs.m_sharedGroupId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabIds(CStringVector<Alloc> value)
    {
        m_playFabIds = std::move(value);
        this->m_model.playFabIds =  m_playFabIds.empty() ? nullptr : m_playFabIds.data();
        this->m_model.playFabIdsCount =  static_cast<uint32_t>(m_playFabIds.size());
    }

    void SetSharedGroupId(String value)
    {
        m_sharedGroupId = std::move(value);
        this->m_model.sharedGroupId =  m_sharedGroupId.empty() ? nullptr : m_sharedGroupId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabIds = m_playFabIds.empty() ? nullptr : m_playFabIds.data();
        this->m_model.sharedGroupId = m_sharedGroupId.empty() ? nullptr : m_sharedGroupId.data();
    }

    CStringVector<Alloc> m_playFabIds;
    String m_sharedGroupId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSharedGroupsCreateSharedGroupRequestWrapper : public ModelWrapper<PFSharedGroupsCreateSharedGroupRequest, Alloc>
{
public:
    using ModelType = typename PFSharedGroupsCreateSharedGroupRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSharedGroupsCreateSharedGroupRequestWrapper() = default;

    PFSharedGroupsCreateSharedGroupRequestWrapper(const PFSharedGroupsCreateSharedGroupRequest& model) :
        ModelWrapper<PFSharedGroupsCreateSharedGroupRequest, Alloc>{ model },
        m_sharedGroupId{ SafeString(model.sharedGroupId) }
    {
        SetModelPointers();
    }

    PFSharedGroupsCreateSharedGroupRequestWrapper(const PFSharedGroupsCreateSharedGroupRequestWrapper& src) :
        PFSharedGroupsCreateSharedGroupRequestWrapper{ src.Model() }
    {
    }

    PFSharedGroupsCreateSharedGroupRequestWrapper(PFSharedGroupsCreateSharedGroupRequestWrapper&& src) :
        PFSharedGroupsCreateSharedGroupRequestWrapper{}
    {
        swap(*this, src);
    }

    PFSharedGroupsCreateSharedGroupRequestWrapper& operator=(PFSharedGroupsCreateSharedGroupRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSharedGroupsCreateSharedGroupRequestWrapper() = default;

    friend void swap(PFSharedGroupsCreateSharedGroupRequestWrapper& lhs, PFSharedGroupsCreateSharedGroupRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_sharedGroupId, rhs.m_sharedGroupId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSharedGroupId(String value)
    {
        m_sharedGroupId = std::move(value);
        this->m_model.sharedGroupId =  m_sharedGroupId.empty() ? nullptr : m_sharedGroupId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.sharedGroupId = m_sharedGroupId.empty() ? nullptr : m_sharedGroupId.data();
    }

    String m_sharedGroupId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSharedGroupsCreateSharedGroupResultWrapper : public ModelWrapper<PFSharedGroupsCreateSharedGroupResult, Alloc>
{
public:
    using ModelType = typename PFSharedGroupsCreateSharedGroupResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSharedGroupsCreateSharedGroupResultWrapper() = default;

    PFSharedGroupsCreateSharedGroupResultWrapper(const PFSharedGroupsCreateSharedGroupResult& model) :
        ModelWrapper<PFSharedGroupsCreateSharedGroupResult, Alloc>{ model },
        m_sharedGroupId{ SafeString(model.sharedGroupId) }
    {
        SetModelPointers();
    }

    PFSharedGroupsCreateSharedGroupResultWrapper(const PFSharedGroupsCreateSharedGroupResultWrapper& src) :
        PFSharedGroupsCreateSharedGroupResultWrapper{ src.Model() }
    {
    }

    PFSharedGroupsCreateSharedGroupResultWrapper(PFSharedGroupsCreateSharedGroupResultWrapper&& src) :
        PFSharedGroupsCreateSharedGroupResultWrapper{}
    {
        swap(*this, src);
    }

    PFSharedGroupsCreateSharedGroupResultWrapper& operator=(PFSharedGroupsCreateSharedGroupResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSharedGroupsCreateSharedGroupResultWrapper() = default;

    friend void swap(PFSharedGroupsCreateSharedGroupResultWrapper& lhs, PFSharedGroupsCreateSharedGroupResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_sharedGroupId, rhs.m_sharedGroupId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSharedGroupId(String value)
    {
        m_sharedGroupId = std::move(value);
        this->m_model.sharedGroupId =  m_sharedGroupId.empty() ? nullptr : m_sharedGroupId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.sharedGroupId = m_sharedGroupId.empty() ? nullptr : m_sharedGroupId.data();
    }

    String m_sharedGroupId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSharedGroupsGetSharedGroupDataRequestWrapper : public ModelWrapper<PFSharedGroupsGetSharedGroupDataRequest, Alloc>
{
public:
    using ModelType = typename PFSharedGroupsGetSharedGroupDataRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSharedGroupsGetSharedGroupDataRequestWrapper() = default;

    PFSharedGroupsGetSharedGroupDataRequestWrapper(const PFSharedGroupsGetSharedGroupDataRequest& model) :
        ModelWrapper<PFSharedGroupsGetSharedGroupDataRequest, Alloc>{ model },
        m_getMembers{ model.getMembers ? StdExtra::optional<bool>{ *model.getMembers } : StdExtra::nullopt },
        m_keys{ model.keys, model.keys + model.keysCount },
        m_sharedGroupId{ SafeString(model.sharedGroupId) }
    {
        SetModelPointers();
    }

    PFSharedGroupsGetSharedGroupDataRequestWrapper(const PFSharedGroupsGetSharedGroupDataRequestWrapper& src) :
        PFSharedGroupsGetSharedGroupDataRequestWrapper{ src.Model() }
    {
    }

    PFSharedGroupsGetSharedGroupDataRequestWrapper(PFSharedGroupsGetSharedGroupDataRequestWrapper&& src) :
        PFSharedGroupsGetSharedGroupDataRequestWrapper{}
    {
        swap(*this, src);
    }

    PFSharedGroupsGetSharedGroupDataRequestWrapper& operator=(PFSharedGroupsGetSharedGroupDataRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSharedGroupsGetSharedGroupDataRequestWrapper() = default;

    friend void swap(PFSharedGroupsGetSharedGroupDataRequestWrapper& lhs, PFSharedGroupsGetSharedGroupDataRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_getMembers, rhs.m_getMembers);
        swap(lhs.m_keys, rhs.m_keys);
        swap(lhs.m_sharedGroupId, rhs.m_sharedGroupId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGetMembers(StdExtra::optional<bool> value)
    {
        m_getMembers = std::move(value);
        this->m_model.getMembers = m_getMembers ? m_getMembers.operator->() : nullptr;
    }

    void SetKeys(CStringVector<Alloc> value)
    {
        m_keys = std::move(value);
        this->m_model.keys =  m_keys.empty() ? nullptr : m_keys.data();
        this->m_model.keysCount =  static_cast<uint32_t>(m_keys.size());
    }

    void SetSharedGroupId(String value)
    {
        m_sharedGroupId = std::move(value);
        this->m_model.sharedGroupId =  m_sharedGroupId.empty() ? nullptr : m_sharedGroupId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.getMembers = m_getMembers ? m_getMembers.operator->() : nullptr;
        this->m_model.keys = m_keys.empty() ? nullptr : m_keys.data();
        this->m_model.sharedGroupId = m_sharedGroupId.empty() ? nullptr : m_sharedGroupId.data();
    }

    StdExtra::optional<bool> m_getMembers;
    CStringVector<Alloc> m_keys;
    String m_sharedGroupId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSharedGroupsSharedGroupDataRecordWrapper : public ModelWrapper<PFSharedGroupsSharedGroupDataRecord, Alloc>
{
public:
    using ModelType = typename PFSharedGroupsSharedGroupDataRecord;
    using DictionaryEntryType = typename PFSharedGroupsSharedGroupDataRecordDictionaryEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSharedGroupsSharedGroupDataRecordWrapper() = default;

    PFSharedGroupsSharedGroupDataRecordWrapper(const PFSharedGroupsSharedGroupDataRecord& model) :
        ModelWrapper<PFSharedGroupsSharedGroupDataRecord, Alloc>{ model },
        m_lastUpdatedBy{ SafeString(model.lastUpdatedBy) },
        m_permission{ model.permission ? StdExtra::optional<PFUserDataPermission>{ *model.permission } : StdExtra::nullopt },
        m_value{ SafeString(model.value) }
    {
        SetModelPointers();
    }

    PFSharedGroupsSharedGroupDataRecordWrapper(const PFSharedGroupsSharedGroupDataRecordWrapper& src) :
        PFSharedGroupsSharedGroupDataRecordWrapper{ src.Model() }
    {
    }

    PFSharedGroupsSharedGroupDataRecordWrapper(PFSharedGroupsSharedGroupDataRecordWrapper&& src) :
        PFSharedGroupsSharedGroupDataRecordWrapper{}
    {
        swap(*this, src);
    }

    PFSharedGroupsSharedGroupDataRecordWrapper& operator=(PFSharedGroupsSharedGroupDataRecordWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSharedGroupsSharedGroupDataRecordWrapper() = default;

    friend void swap(PFSharedGroupsSharedGroupDataRecordWrapper& lhs, PFSharedGroupsSharedGroupDataRecordWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_lastUpdatedBy, rhs.m_lastUpdatedBy);
        swap(lhs.m_permission, rhs.m_permission);
        swap(lhs.m_value, rhs.m_value);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLastUpdated(time_t value)
    {
        this->m_model.lastUpdated = value;
    }

    void SetLastUpdatedBy(String value)
    {
        m_lastUpdatedBy = std::move(value);
        this->m_model.lastUpdatedBy =  m_lastUpdatedBy.empty() ? nullptr : m_lastUpdatedBy.data();
    }

    void SetPermission(StdExtra::optional<PFUserDataPermission> value)
    {
        m_permission = std::move(value);
        this->m_model.permission = m_permission ? m_permission.operator->() : nullptr;
    }

    void SetValue(String value)
    {
        m_value = std::move(value);
        this->m_model.value =  m_value.empty() ? nullptr : m_value.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.lastUpdatedBy = m_lastUpdatedBy.empty() ? nullptr : m_lastUpdatedBy.data();
        this->m_model.permission = m_permission ? m_permission.operator->() : nullptr;
        this->m_model.value = m_value.empty() ? nullptr : m_value.data();
    }

    String m_lastUpdatedBy;
    StdExtra::optional<PFUserDataPermission> m_permission;
    String m_value;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSharedGroupsGetSharedGroupDataResultWrapper : public ModelWrapper<PFSharedGroupsGetSharedGroupDataResult, Alloc>
{
public:
    using ModelType = typename PFSharedGroupsGetSharedGroupDataResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSharedGroupsGetSharedGroupDataResultWrapper() = default;

    PFSharedGroupsGetSharedGroupDataResultWrapper(const PFSharedGroupsGetSharedGroupDataResult& model) :
        ModelWrapper<PFSharedGroupsGetSharedGroupDataResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount },
        m_members{ model.members, model.members + model.membersCount }
    {
        SetModelPointers();
    }

    PFSharedGroupsGetSharedGroupDataResultWrapper(const PFSharedGroupsGetSharedGroupDataResultWrapper& src) :
        PFSharedGroupsGetSharedGroupDataResultWrapper{ src.Model() }
    {
    }

    PFSharedGroupsGetSharedGroupDataResultWrapper(PFSharedGroupsGetSharedGroupDataResultWrapper&& src) :
        PFSharedGroupsGetSharedGroupDataResultWrapper{}
    {
        swap(*this, src);
    }

    PFSharedGroupsGetSharedGroupDataResultWrapper& operator=(PFSharedGroupsGetSharedGroupDataResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSharedGroupsGetSharedGroupDataResultWrapper() = default;

    friend void swap(PFSharedGroupsGetSharedGroupDataResultWrapper& lhs, PFSharedGroupsGetSharedGroupDataResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        swap(lhs.m_members, rhs.m_members);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(ModelDictionaryEntryVector<PFSharedGroupsSharedGroupDataRecordWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

    void SetMembers(CStringVector<Alloc> value)
    {
        m_members = std::move(value);
        this->m_model.members =  m_members.empty() ? nullptr : m_members.data();
        this->m_model.membersCount =  static_cast<uint32_t>(m_members.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
        this->m_model.members = m_members.empty() ? nullptr : m_members.data();
    }

    ModelDictionaryEntryVector<PFSharedGroupsSharedGroupDataRecordWrapper<Alloc>, Alloc> m_data;
    CStringVector<Alloc> m_members;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSharedGroupsRemoveSharedGroupMembersRequestWrapper : public ModelWrapper<PFSharedGroupsRemoveSharedGroupMembersRequest, Alloc>
{
public:
    using ModelType = typename PFSharedGroupsRemoveSharedGroupMembersRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSharedGroupsRemoveSharedGroupMembersRequestWrapper() = default;

    PFSharedGroupsRemoveSharedGroupMembersRequestWrapper(const PFSharedGroupsRemoveSharedGroupMembersRequest& model) :
        ModelWrapper<PFSharedGroupsRemoveSharedGroupMembersRequest, Alloc>{ model },
        m_playFabIds{ model.playFabIds, model.playFabIds + model.playFabIdsCount },
        m_sharedGroupId{ SafeString(model.sharedGroupId) }
    {
        SetModelPointers();
    }

    PFSharedGroupsRemoveSharedGroupMembersRequestWrapper(const PFSharedGroupsRemoveSharedGroupMembersRequestWrapper& src) :
        PFSharedGroupsRemoveSharedGroupMembersRequestWrapper{ src.Model() }
    {
    }

    PFSharedGroupsRemoveSharedGroupMembersRequestWrapper(PFSharedGroupsRemoveSharedGroupMembersRequestWrapper&& src) :
        PFSharedGroupsRemoveSharedGroupMembersRequestWrapper{}
    {
        swap(*this, src);
    }

    PFSharedGroupsRemoveSharedGroupMembersRequestWrapper& operator=(PFSharedGroupsRemoveSharedGroupMembersRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSharedGroupsRemoveSharedGroupMembersRequestWrapper() = default;

    friend void swap(PFSharedGroupsRemoveSharedGroupMembersRequestWrapper& lhs, PFSharedGroupsRemoveSharedGroupMembersRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabIds, rhs.m_playFabIds);
        swap(lhs.m_sharedGroupId, rhs.m_sharedGroupId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabIds(CStringVector<Alloc> value)
    {
        m_playFabIds = std::move(value);
        this->m_model.playFabIds =  m_playFabIds.empty() ? nullptr : m_playFabIds.data();
        this->m_model.playFabIdsCount =  static_cast<uint32_t>(m_playFabIds.size());
    }

    void SetSharedGroupId(String value)
    {
        m_sharedGroupId = std::move(value);
        this->m_model.sharedGroupId =  m_sharedGroupId.empty() ? nullptr : m_sharedGroupId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabIds = m_playFabIds.empty() ? nullptr : m_playFabIds.data();
        this->m_model.sharedGroupId = m_sharedGroupId.empty() ? nullptr : m_sharedGroupId.data();
    }

    CStringVector<Alloc> m_playFabIds;
    String m_sharedGroupId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSharedGroupsUpdateSharedGroupDataRequestWrapper : public ModelWrapper<PFSharedGroupsUpdateSharedGroupDataRequest, Alloc>
{
public:
    using ModelType = typename PFSharedGroupsUpdateSharedGroupDataRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSharedGroupsUpdateSharedGroupDataRequestWrapper() = default;

    PFSharedGroupsUpdateSharedGroupDataRequestWrapper(const PFSharedGroupsUpdateSharedGroupDataRequest& model) :
        ModelWrapper<PFSharedGroupsUpdateSharedGroupDataRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_data{ model.data, model.data + model.dataCount },
        m_keysToRemove{ model.keysToRemove, model.keysToRemove + model.keysToRemoveCount },
        m_permission{ model.permission ? StdExtra::optional<PFUserDataPermission>{ *model.permission } : StdExtra::nullopt },
        m_sharedGroupId{ SafeString(model.sharedGroupId) }
    {
        SetModelPointers();
    }

    PFSharedGroupsUpdateSharedGroupDataRequestWrapper(const PFSharedGroupsUpdateSharedGroupDataRequestWrapper& src) :
        PFSharedGroupsUpdateSharedGroupDataRequestWrapper{ src.Model() }
    {
    }

    PFSharedGroupsUpdateSharedGroupDataRequestWrapper(PFSharedGroupsUpdateSharedGroupDataRequestWrapper&& src) :
        PFSharedGroupsUpdateSharedGroupDataRequestWrapper{}
    {
        swap(*this, src);
    }

    PFSharedGroupsUpdateSharedGroupDataRequestWrapper& operator=(PFSharedGroupsUpdateSharedGroupDataRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSharedGroupsUpdateSharedGroupDataRequestWrapper() = default;

    friend void swap(PFSharedGroupsUpdateSharedGroupDataRequestWrapper& lhs, PFSharedGroupsUpdateSharedGroupDataRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_data, rhs.m_data);
        swap(lhs.m_keysToRemove, rhs.m_keysToRemove);
        swap(lhs.m_permission, rhs.m_permission);
        swap(lhs.m_sharedGroupId, rhs.m_sharedGroupId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetData(StringDictionaryEntryVector<Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

    void SetKeysToRemove(CStringVector<Alloc> value)
    {
        m_keysToRemove = std::move(value);
        this->m_model.keysToRemove =  m_keysToRemove.empty() ? nullptr : m_keysToRemove.data();
        this->m_model.keysToRemoveCount =  static_cast<uint32_t>(m_keysToRemove.size());
    }

    void SetPermission(StdExtra::optional<PFUserDataPermission> value)
    {
        m_permission = std::move(value);
        this->m_model.permission = m_permission ? m_permission.operator->() : nullptr;
    }

    void SetSharedGroupId(String value)
    {
        m_sharedGroupId = std::move(value);
        this->m_model.sharedGroupId =  m_sharedGroupId.empty() ? nullptr : m_sharedGroupId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
        this->m_model.keysToRemove = m_keysToRemove.empty() ? nullptr : m_keysToRemove.data();
        this->m_model.permission = m_permission ? m_permission.operator->() : nullptr;
        this->m_model.sharedGroupId = m_sharedGroupId.empty() ? nullptr : m_sharedGroupId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StringDictionaryEntryVector<Alloc> m_data;
    CStringVector<Alloc> m_keysToRemove;
    StdExtra::optional<PFUserDataPermission> m_permission;
    String m_sharedGroupId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFSharedGroupsDeleteSharedGroupRequestWrapper : public ModelWrapper<PFSharedGroupsDeleteSharedGroupRequest, Alloc>
{
public:
    using ModelType = typename PFSharedGroupsDeleteSharedGroupRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFSharedGroupsDeleteSharedGroupRequestWrapper() = default;

    PFSharedGroupsDeleteSharedGroupRequestWrapper(const PFSharedGroupsDeleteSharedGroupRequest& model) :
        ModelWrapper<PFSharedGroupsDeleteSharedGroupRequest, Alloc>{ model },
        m_sharedGroupId{ SafeString(model.sharedGroupId) }
    {
        SetModelPointers();
    }

    PFSharedGroupsDeleteSharedGroupRequestWrapper(const PFSharedGroupsDeleteSharedGroupRequestWrapper& src) :
        PFSharedGroupsDeleteSharedGroupRequestWrapper{ src.Model() }
    {
    }

    PFSharedGroupsDeleteSharedGroupRequestWrapper(PFSharedGroupsDeleteSharedGroupRequestWrapper&& src) :
        PFSharedGroupsDeleteSharedGroupRequestWrapper{}
    {
        swap(*this, src);
    }

    PFSharedGroupsDeleteSharedGroupRequestWrapper& operator=(PFSharedGroupsDeleteSharedGroupRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFSharedGroupsDeleteSharedGroupRequestWrapper() = default;

    friend void swap(PFSharedGroupsDeleteSharedGroupRequestWrapper& lhs, PFSharedGroupsDeleteSharedGroupRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_sharedGroupId, rhs.m_sharedGroupId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSharedGroupId(String value)
    {
        m_sharedGroupId = std::move(value);
        this->m_model.sharedGroupId =  m_sharedGroupId.empty() ? nullptr : m_sharedGroupId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.sharedGroupId = m_sharedGroupId.empty() ? nullptr : m_sharedGroupId.data();
    }

    String m_sharedGroupId;
};

} // namespace Wrappers
} // namespace PlayFab
