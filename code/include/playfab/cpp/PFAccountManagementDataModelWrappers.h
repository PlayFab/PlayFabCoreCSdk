// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFAccountManagementDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementBanRequestWrapper : public ModelWrapper<PFAccountManagementBanRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementBanRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementBanRequestWrapper() = default;

    PFAccountManagementBanRequestWrapper(const PFAccountManagementBanRequest& model) :
        ModelWrapper<PFAccountManagementBanRequest, Alloc>{ model },
        m_durationInHours{ model.durationInHours ? StdExtra::optional<uint32_t>{ *model.durationInHours } : StdExtra::nullopt },
        m_IPAddress{ SafeString(model.IPAddress) },
        m_MACAddress{ SafeString(model.MACAddress) },
        m_playFabId{ SafeString(model.playFabId) },
        m_reason{ SafeString(model.reason) }
    {
        SetModelPointers();
    }

    PFAccountManagementBanRequestWrapper(const PFAccountManagementBanRequestWrapper& src) :
        PFAccountManagementBanRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementBanRequestWrapper(PFAccountManagementBanRequestWrapper&& src) :
        PFAccountManagementBanRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementBanRequestWrapper& operator=(PFAccountManagementBanRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementBanRequestWrapper() = default;

    friend void swap(PFAccountManagementBanRequestWrapper& lhs, PFAccountManagementBanRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_durationInHours, rhs.m_durationInHours);
        swap(lhs.m_IPAddress, rhs.m_IPAddress);
        swap(lhs.m_MACAddress, rhs.m_MACAddress);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_reason, rhs.m_reason);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDurationInHours(StdExtra::optional<uint32_t> value)
    {
        m_durationInHours = std::move(value);
        this->m_model.durationInHours = m_durationInHours ? m_durationInHours.operator->() : nullptr;
    }

    void SetIPAddress(String value)
    {
        m_IPAddress = std::move(value);
        this->m_model.IPAddress =  m_IPAddress.empty() ? nullptr : m_IPAddress.data();
    }

    void SetMACAddress(String value)
    {
        m_MACAddress = std::move(value);
        this->m_model.MACAddress =  m_MACAddress.empty() ? nullptr : m_MACAddress.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetReason(String value)
    {
        m_reason = std::move(value);
        this->m_model.reason =  m_reason.empty() ? nullptr : m_reason.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.durationInHours = m_durationInHours ? m_durationInHours.operator->() : nullptr;
        this->m_model.IPAddress = m_IPAddress.empty() ? nullptr : m_IPAddress.data();
        this->m_model.MACAddress = m_MACAddress.empty() ? nullptr : m_MACAddress.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.reason = m_reason.empty() ? nullptr : m_reason.data();
    }

    StdExtra::optional<uint32_t> m_durationInHours;
    String m_IPAddress;
    String m_MACAddress;
    String m_playFabId;
    String m_reason;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementBanUsersRequestWrapper : public ModelWrapper<PFAccountManagementBanUsersRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementBanUsersRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementBanUsersRequestWrapper() = default;

    PFAccountManagementBanUsersRequestWrapper(const PFAccountManagementBanUsersRequest& model) :
        ModelWrapper<PFAccountManagementBanUsersRequest, Alloc>{ model },
        m_bans{ model.bans, model.bans + model.bansCount },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementBanUsersRequestWrapper(const PFAccountManagementBanUsersRequestWrapper& src) :
        PFAccountManagementBanUsersRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementBanUsersRequestWrapper(PFAccountManagementBanUsersRequestWrapper&& src) :
        PFAccountManagementBanUsersRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementBanUsersRequestWrapper& operator=(PFAccountManagementBanUsersRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementBanUsersRequestWrapper() = default;

    friend void swap(PFAccountManagementBanUsersRequestWrapper& lhs, PFAccountManagementBanUsersRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_bans, rhs.m_bans);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBans(ModelVector<PFAccountManagementBanRequestWrapper<Alloc>, Alloc> value)
    {
        m_bans = std::move(value);
        this->m_model.bans =  m_bans.empty() ? nullptr : m_bans.data();
        this->m_model.bansCount =  static_cast<uint32_t>(m_bans.size());
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.bans = m_bans.empty() ? nullptr : m_bans.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    ModelVector<PFAccountManagementBanRequestWrapper<Alloc>, Alloc> m_bans;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementBanInfoWrapper : public ModelWrapper<PFAccountManagementBanInfo, Alloc>
{
public:
    using ModelType = typename PFAccountManagementBanInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementBanInfoWrapper() = default;

    PFAccountManagementBanInfoWrapper(const PFAccountManagementBanInfo& model) :
        ModelWrapper<PFAccountManagementBanInfo, Alloc>{ model },
        m_banId{ SafeString(model.banId) },
        m_created{ model.created ? StdExtra::optional<time_t>{ *model.created } : StdExtra::nullopt },
        m_expires{ model.expires ? StdExtra::optional<time_t>{ *model.expires } : StdExtra::nullopt },
        m_IPAddress{ SafeString(model.IPAddress) },
        m_MACAddress{ SafeString(model.MACAddress) },
        m_playFabId{ SafeString(model.playFabId) },
        m_reason{ SafeString(model.reason) }
    {
        SetModelPointers();
    }

    PFAccountManagementBanInfoWrapper(const PFAccountManagementBanInfoWrapper& src) :
        PFAccountManagementBanInfoWrapper{ src.Model() }
    {
    }

    PFAccountManagementBanInfoWrapper(PFAccountManagementBanInfoWrapper&& src) :
        PFAccountManagementBanInfoWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementBanInfoWrapper& operator=(PFAccountManagementBanInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementBanInfoWrapper() = default;

    friend void swap(PFAccountManagementBanInfoWrapper& lhs, PFAccountManagementBanInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_banId, rhs.m_banId);
        swap(lhs.m_created, rhs.m_created);
        swap(lhs.m_expires, rhs.m_expires);
        swap(lhs.m_IPAddress, rhs.m_IPAddress);
        swap(lhs.m_MACAddress, rhs.m_MACAddress);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_reason, rhs.m_reason);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetActive(bool value)
    {
        this->m_model.active = value;
    }

    void SetBanId(String value)
    {
        m_banId = std::move(value);
        this->m_model.banId =  m_banId.empty() ? nullptr : m_banId.data();
    }

    void SetCreated(StdExtra::optional<time_t> value)
    {
        m_created = std::move(value);
        this->m_model.created = m_created ? m_created.operator->() : nullptr;
    }

    void SetExpires(StdExtra::optional<time_t> value)
    {
        m_expires = std::move(value);
        this->m_model.expires = m_expires ? m_expires.operator->() : nullptr;
    }

    void SetIPAddress(String value)
    {
        m_IPAddress = std::move(value);
        this->m_model.IPAddress =  m_IPAddress.empty() ? nullptr : m_IPAddress.data();
    }

    void SetMACAddress(String value)
    {
        m_MACAddress = std::move(value);
        this->m_model.MACAddress =  m_MACAddress.empty() ? nullptr : m_MACAddress.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetReason(String value)
    {
        m_reason = std::move(value);
        this->m_model.reason =  m_reason.empty() ? nullptr : m_reason.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.banId = m_banId.empty() ? nullptr : m_banId.data();
        this->m_model.created = m_created ? m_created.operator->() : nullptr;
        this->m_model.expires = m_expires ? m_expires.operator->() : nullptr;
        this->m_model.IPAddress = m_IPAddress.empty() ? nullptr : m_IPAddress.data();
        this->m_model.MACAddress = m_MACAddress.empty() ? nullptr : m_MACAddress.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.reason = m_reason.empty() ? nullptr : m_reason.data();
    }

    String m_banId;
    StdExtra::optional<time_t> m_created;
    StdExtra::optional<time_t> m_expires;
    String m_IPAddress;
    String m_MACAddress;
    String m_playFabId;
    String m_reason;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementBanUsersResultWrapper : public ModelWrapper<PFAccountManagementBanUsersResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementBanUsersResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementBanUsersResultWrapper() = default;

    PFAccountManagementBanUsersResultWrapper(const PFAccountManagementBanUsersResult& model) :
        ModelWrapper<PFAccountManagementBanUsersResult, Alloc>{ model },
        m_banData{ model.banData, model.banData + model.banDataCount }
    {
        SetModelPointers();
    }

    PFAccountManagementBanUsersResultWrapper(const PFAccountManagementBanUsersResultWrapper& src) :
        PFAccountManagementBanUsersResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementBanUsersResultWrapper(PFAccountManagementBanUsersResultWrapper&& src) :
        PFAccountManagementBanUsersResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementBanUsersResultWrapper& operator=(PFAccountManagementBanUsersResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementBanUsersResultWrapper() = default;

    friend void swap(PFAccountManagementBanUsersResultWrapper& lhs, PFAccountManagementBanUsersResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_banData, rhs.m_banData);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBanData(ModelVector<PFAccountManagementBanInfoWrapper<Alloc>, Alloc> value)
    {
        m_banData = std::move(value);
        this->m_model.banData =  m_banData.empty() ? nullptr : m_banData.data();
        this->m_model.banDataCount =  static_cast<uint32_t>(m_banData.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.banData = m_banData.empty() ? nullptr : m_banData.data();
    }

    ModelVector<PFAccountManagementBanInfoWrapper<Alloc>, Alloc> m_banData;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementDeleteMasterPlayerAccountRequestWrapper : public ModelWrapper<PFAccountManagementDeleteMasterPlayerAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementDeleteMasterPlayerAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementDeleteMasterPlayerAccountRequestWrapper() = default;

    PFAccountManagementDeleteMasterPlayerAccountRequestWrapper(const PFAccountManagementDeleteMasterPlayerAccountRequest& model) :
        ModelWrapper<PFAccountManagementDeleteMasterPlayerAccountRequest, Alloc>{ model },
        m_metaData{ SafeString(model.metaData) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementDeleteMasterPlayerAccountRequestWrapper(const PFAccountManagementDeleteMasterPlayerAccountRequestWrapper& src) :
        PFAccountManagementDeleteMasterPlayerAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementDeleteMasterPlayerAccountRequestWrapper(PFAccountManagementDeleteMasterPlayerAccountRequestWrapper&& src) :
        PFAccountManagementDeleteMasterPlayerAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementDeleteMasterPlayerAccountRequestWrapper& operator=(PFAccountManagementDeleteMasterPlayerAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementDeleteMasterPlayerAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementDeleteMasterPlayerAccountRequestWrapper& lhs, PFAccountManagementDeleteMasterPlayerAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_metaData, rhs.m_metaData);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetMetaData(String value)
    {
        m_metaData = std::move(value);
        this->m_model.metaData =  m_metaData.empty() ? nullptr : m_metaData.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.metaData = m_metaData.empty() ? nullptr : m_metaData.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_metaData;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementDeleteMasterPlayerAccountResultWrapper : public ModelWrapper<PFAccountManagementDeleteMasterPlayerAccountResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementDeleteMasterPlayerAccountResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementDeleteMasterPlayerAccountResultWrapper() = default;

    PFAccountManagementDeleteMasterPlayerAccountResultWrapper(const PFAccountManagementDeleteMasterPlayerAccountResult& model) :
        ModelWrapper<PFAccountManagementDeleteMasterPlayerAccountResult, Alloc>{ model },
        m_jobReceiptId{ SafeString(model.jobReceiptId) },
        m_titleIds{ model.titleIds, model.titleIds + model.titleIdsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementDeleteMasterPlayerAccountResultWrapper(const PFAccountManagementDeleteMasterPlayerAccountResultWrapper& src) :
        PFAccountManagementDeleteMasterPlayerAccountResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementDeleteMasterPlayerAccountResultWrapper(PFAccountManagementDeleteMasterPlayerAccountResultWrapper&& src) :
        PFAccountManagementDeleteMasterPlayerAccountResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementDeleteMasterPlayerAccountResultWrapper& operator=(PFAccountManagementDeleteMasterPlayerAccountResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementDeleteMasterPlayerAccountResultWrapper() = default;

    friend void swap(PFAccountManagementDeleteMasterPlayerAccountResultWrapper& lhs, PFAccountManagementDeleteMasterPlayerAccountResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_jobReceiptId, rhs.m_jobReceiptId);
        swap(lhs.m_titleIds, rhs.m_titleIds);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetJobReceiptId(String value)
    {
        m_jobReceiptId = std::move(value);
        this->m_model.jobReceiptId =  m_jobReceiptId.empty() ? nullptr : m_jobReceiptId.data();
    }

    void SetTitleIds(CStringVector<Alloc> value)
    {
        m_titleIds = std::move(value);
        this->m_model.titleIds =  m_titleIds.empty() ? nullptr : m_titleIds.data();
        this->m_model.titleIdsCount =  static_cast<uint32_t>(m_titleIds.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.jobReceiptId = m_jobReceiptId.empty() ? nullptr : m_jobReceiptId.data();
        this->m_model.titleIds = m_titleIds.empty() ? nullptr : m_titleIds.data();
    }

    String m_jobReceiptId;
    CStringVector<Alloc> m_titleIds;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementDeleteMembershipSubscriptionRequestWrapper : public ModelWrapper<PFAccountManagementDeleteMembershipSubscriptionRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementDeleteMembershipSubscriptionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementDeleteMembershipSubscriptionRequestWrapper() = default;

    PFAccountManagementDeleteMembershipSubscriptionRequestWrapper(const PFAccountManagementDeleteMembershipSubscriptionRequest& model) :
        ModelWrapper<PFAccountManagementDeleteMembershipSubscriptionRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_membershipId{ SafeString(model.membershipId) },
        m_playFabId{ SafeString(model.playFabId) },
        m_subscriptionId{ SafeString(model.subscriptionId) }
    {
        SetModelPointers();
    }

    PFAccountManagementDeleteMembershipSubscriptionRequestWrapper(const PFAccountManagementDeleteMembershipSubscriptionRequestWrapper& src) :
        PFAccountManagementDeleteMembershipSubscriptionRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementDeleteMembershipSubscriptionRequestWrapper(PFAccountManagementDeleteMembershipSubscriptionRequestWrapper&& src) :
        PFAccountManagementDeleteMembershipSubscriptionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementDeleteMembershipSubscriptionRequestWrapper& operator=(PFAccountManagementDeleteMembershipSubscriptionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementDeleteMembershipSubscriptionRequestWrapper() = default;

    friend void swap(PFAccountManagementDeleteMembershipSubscriptionRequestWrapper& lhs, PFAccountManagementDeleteMembershipSubscriptionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_membershipId, rhs.m_membershipId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_subscriptionId, rhs.m_subscriptionId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetMembershipId(String value)
    {
        m_membershipId = std::move(value);
        this->m_model.membershipId =  m_membershipId.empty() ? nullptr : m_membershipId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetSubscriptionId(String value)
    {
        m_subscriptionId = std::move(value);
        this->m_model.subscriptionId =  m_subscriptionId.empty() ? nullptr : m_subscriptionId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.membershipId = m_membershipId.empty() ? nullptr : m_membershipId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.subscriptionId = m_subscriptionId.empty() ? nullptr : m_subscriptionId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_membershipId;
    String m_playFabId;
    String m_subscriptionId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementDeletePlayerRequestWrapper : public ModelWrapper<PFAccountManagementDeletePlayerRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementDeletePlayerRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementDeletePlayerRequestWrapper() = default;

    PFAccountManagementDeletePlayerRequestWrapper(const PFAccountManagementDeletePlayerRequest& model) :
        ModelWrapper<PFAccountManagementDeletePlayerRequest, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementDeletePlayerRequestWrapper(const PFAccountManagementDeletePlayerRequestWrapper& src) :
        PFAccountManagementDeletePlayerRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementDeletePlayerRequestWrapper(PFAccountManagementDeletePlayerRequestWrapper&& src) :
        PFAccountManagementDeletePlayerRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementDeletePlayerRequestWrapper& operator=(PFAccountManagementDeletePlayerRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementDeletePlayerRequestWrapper() = default;

    friend void swap(PFAccountManagementDeletePlayerRequestWrapper& lhs, PFAccountManagementDeletePlayerRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementExportMasterPlayerDataRequestWrapper : public ModelWrapper<PFAccountManagementExportMasterPlayerDataRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementExportMasterPlayerDataRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementExportMasterPlayerDataRequestWrapper() = default;

    PFAccountManagementExportMasterPlayerDataRequestWrapper(const PFAccountManagementExportMasterPlayerDataRequest& model) :
        ModelWrapper<PFAccountManagementExportMasterPlayerDataRequest, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementExportMasterPlayerDataRequestWrapper(const PFAccountManagementExportMasterPlayerDataRequestWrapper& src) :
        PFAccountManagementExportMasterPlayerDataRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementExportMasterPlayerDataRequestWrapper(PFAccountManagementExportMasterPlayerDataRequestWrapper&& src) :
        PFAccountManagementExportMasterPlayerDataRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementExportMasterPlayerDataRequestWrapper& operator=(PFAccountManagementExportMasterPlayerDataRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementExportMasterPlayerDataRequestWrapper() = default;

    friend void swap(PFAccountManagementExportMasterPlayerDataRequestWrapper& lhs, PFAccountManagementExportMasterPlayerDataRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementExportMasterPlayerDataResultWrapper : public ModelWrapper<PFAccountManagementExportMasterPlayerDataResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementExportMasterPlayerDataResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementExportMasterPlayerDataResultWrapper() = default;

    PFAccountManagementExportMasterPlayerDataResultWrapper(const PFAccountManagementExportMasterPlayerDataResult& model) :
        ModelWrapper<PFAccountManagementExportMasterPlayerDataResult, Alloc>{ model },
        m_jobReceiptId{ SafeString(model.jobReceiptId) }
    {
        SetModelPointers();
    }

    PFAccountManagementExportMasterPlayerDataResultWrapper(const PFAccountManagementExportMasterPlayerDataResultWrapper& src) :
        PFAccountManagementExportMasterPlayerDataResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementExportMasterPlayerDataResultWrapper(PFAccountManagementExportMasterPlayerDataResultWrapper&& src) :
        PFAccountManagementExportMasterPlayerDataResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementExportMasterPlayerDataResultWrapper& operator=(PFAccountManagementExportMasterPlayerDataResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementExportMasterPlayerDataResultWrapper() = default;

    friend void swap(PFAccountManagementExportMasterPlayerDataResultWrapper& lhs, PFAccountManagementExportMasterPlayerDataResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_jobReceiptId, rhs.m_jobReceiptId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetJobReceiptId(String value)
    {
        m_jobReceiptId = std::move(value);
        this->m_model.jobReceiptId =  m_jobReceiptId.empty() ? nullptr : m_jobReceiptId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.jobReceiptId = m_jobReceiptId.empty() ? nullptr : m_jobReceiptId.data();
    }

    String m_jobReceiptId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayedTitleListRequestWrapper : public ModelWrapper<PFAccountManagementGetPlayedTitleListRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayedTitleListRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayedTitleListRequestWrapper() = default;

    PFAccountManagementGetPlayedTitleListRequestWrapper(const PFAccountManagementGetPlayedTitleListRequest& model) :
        ModelWrapper<PFAccountManagementGetPlayedTitleListRequest, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayedTitleListRequestWrapper(const PFAccountManagementGetPlayedTitleListRequestWrapper& src) :
        PFAccountManagementGetPlayedTitleListRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayedTitleListRequestWrapper(PFAccountManagementGetPlayedTitleListRequestWrapper&& src) :
        PFAccountManagementGetPlayedTitleListRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayedTitleListRequestWrapper& operator=(PFAccountManagementGetPlayedTitleListRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayedTitleListRequestWrapper() = default;

    friend void swap(PFAccountManagementGetPlayedTitleListRequestWrapper& lhs, PFAccountManagementGetPlayedTitleListRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayedTitleListResultWrapper : public ModelWrapper<PFAccountManagementGetPlayedTitleListResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayedTitleListResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayedTitleListResultWrapper() = default;

    PFAccountManagementGetPlayedTitleListResultWrapper(const PFAccountManagementGetPlayedTitleListResult& model) :
        ModelWrapper<PFAccountManagementGetPlayedTitleListResult, Alloc>{ model },
        m_titleIds{ model.titleIds, model.titleIds + model.titleIdsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayedTitleListResultWrapper(const PFAccountManagementGetPlayedTitleListResultWrapper& src) :
        PFAccountManagementGetPlayedTitleListResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayedTitleListResultWrapper(PFAccountManagementGetPlayedTitleListResultWrapper&& src) :
        PFAccountManagementGetPlayedTitleListResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayedTitleListResultWrapper& operator=(PFAccountManagementGetPlayedTitleListResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayedTitleListResultWrapper() = default;

    friend void swap(PFAccountManagementGetPlayedTitleListResultWrapper& lhs, PFAccountManagementGetPlayedTitleListResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_titleIds, rhs.m_titleIds);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTitleIds(CStringVector<Alloc> value)
    {
        m_titleIds = std::move(value);
        this->m_model.titleIds =  m_titleIds.empty() ? nullptr : m_titleIds.data();
        this->m_model.titleIdsCount =  static_cast<uint32_t>(m_titleIds.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.titleIds = m_titleIds.empty() ? nullptr : m_titleIds.data();
    }

    CStringVector<Alloc> m_titleIds;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper : public ModelWrapper<PFAccountManagementGetPlayerIdFromAuthTokenRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayerIdFromAuthTokenRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper() = default;

    PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper(const PFAccountManagementGetPlayerIdFromAuthTokenRequest& model) :
        ModelWrapper<PFAccountManagementGetPlayerIdFromAuthTokenRequest, Alloc>{ model },
        m_token{ SafeString(model.token) }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper(const PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper& src) :
        PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper(PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper&& src) :
        PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper& operator=(PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper() = default;

    friend void swap(PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper& lhs, PFAccountManagementGetPlayerIdFromAuthTokenRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_token, rhs.m_token);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetToken(String value)
    {
        m_token = std::move(value);
        this->m_model.token =  m_token.empty() ? nullptr : m_token.data();
    }

    void SetTokenType(PFAccountManagementAuthTokenType value)
    {
        this->m_model.tokenType = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.token = m_token.empty() ? nullptr : m_token.data();
    }

    String m_token;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayerIdFromAuthTokenResultWrapper : public ModelWrapper<PFAccountManagementGetPlayerIdFromAuthTokenResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayerIdFromAuthTokenResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayerIdFromAuthTokenResultWrapper() = default;

    PFAccountManagementGetPlayerIdFromAuthTokenResultWrapper(const PFAccountManagementGetPlayerIdFromAuthTokenResult& model) :
        ModelWrapper<PFAccountManagementGetPlayerIdFromAuthTokenResult, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayerIdFromAuthTokenResultWrapper(const PFAccountManagementGetPlayerIdFromAuthTokenResultWrapper& src) :
        PFAccountManagementGetPlayerIdFromAuthTokenResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayerIdFromAuthTokenResultWrapper(PFAccountManagementGetPlayerIdFromAuthTokenResultWrapper&& src) :
        PFAccountManagementGetPlayerIdFromAuthTokenResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayerIdFromAuthTokenResultWrapper& operator=(PFAccountManagementGetPlayerIdFromAuthTokenResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayerIdFromAuthTokenResultWrapper() = default;

    friend void swap(PFAccountManagementGetPlayerIdFromAuthTokenResultWrapper& lhs, PFAccountManagementGetPlayerIdFromAuthTokenResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayerProfileRequestWrapper : public ModelWrapper<PFAccountManagementGetPlayerProfileRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayerProfileRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayerProfileRequestWrapper() = default;

    PFAccountManagementGetPlayerProfileRequestWrapper(const PFAccountManagementGetPlayerProfileRequest& model) :
        ModelWrapper<PFAccountManagementGetPlayerProfileRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_profileConstraints{ model.profileConstraints ? StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>>{ *model.profileConstraints } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayerProfileRequestWrapper(const PFAccountManagementGetPlayerProfileRequestWrapper& src) :
        PFAccountManagementGetPlayerProfileRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayerProfileRequestWrapper(PFAccountManagementGetPlayerProfileRequestWrapper&& src) :
        PFAccountManagementGetPlayerProfileRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayerProfileRequestWrapper& operator=(PFAccountManagementGetPlayerProfileRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayerProfileRequestWrapper() = default;

    friend void swap(PFAccountManagementGetPlayerProfileRequestWrapper& lhs, PFAccountManagementGetPlayerProfileRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_profileConstraints, rhs.m_profileConstraints);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetProfileConstraints(StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>> value)
    {
        m_profileConstraints = std::move(value);
        this->m_model.profileConstraints = m_profileConstraints ? &m_profileConstraints->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.profileConstraints = m_profileConstraints ?  &m_profileConstraints->Model() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
    StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>> m_profileConstraints;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayerProfileResultWrapper : public ModelWrapper<PFAccountManagementGetPlayerProfileResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayerProfileResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayerProfileResultWrapper() = default;

    PFAccountManagementGetPlayerProfileResultWrapper(const PFAccountManagementGetPlayerProfileResult& model) :
        ModelWrapper<PFAccountManagementGetPlayerProfileResult, Alloc>{ model },
        m_playerProfile{ model.playerProfile ? StdExtra::optional<PFPlayerProfileModelWrapper<Alloc>>{ *model.playerProfile } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayerProfileResultWrapper(const PFAccountManagementGetPlayerProfileResultWrapper& src) :
        PFAccountManagementGetPlayerProfileResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayerProfileResultWrapper(PFAccountManagementGetPlayerProfileResultWrapper&& src) :
        PFAccountManagementGetPlayerProfileResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayerProfileResultWrapper& operator=(PFAccountManagementGetPlayerProfileResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayerProfileResultWrapper() = default;

    friend void swap(PFAccountManagementGetPlayerProfileResultWrapper& lhs, PFAccountManagementGetPlayerProfileResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playerProfile, rhs.m_playerProfile);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayerProfile(StdExtra::optional<PFPlayerProfileModelWrapper<Alloc>> value)
    {
        m_playerProfile = std::move(value);
        this->m_model.playerProfile = m_playerProfile ? &m_playerProfile->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.playerProfile = m_playerProfile ?  &m_playerProfile->Model() : nullptr;
    }

    StdExtra::optional<PFPlayerProfileModelWrapper<Alloc>> m_playerProfile;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLookupUserAccountInfoRequestWrapper : public ModelWrapper<PFAccountManagementLookupUserAccountInfoRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLookupUserAccountInfoRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLookupUserAccountInfoRequestWrapper() = default;

    PFAccountManagementLookupUserAccountInfoRequestWrapper(const PFAccountManagementLookupUserAccountInfoRequest& model) :
        ModelWrapper<PFAccountManagementLookupUserAccountInfoRequest, Alloc>{ model },
        m_email{ SafeString(model.email) },
        m_playFabId{ SafeString(model.playFabId) },
        m_titleDisplayName{ SafeString(model.titleDisplayName) },
        m_username{ SafeString(model.username) }
    {
        SetModelPointers();
    }

    PFAccountManagementLookupUserAccountInfoRequestWrapper(const PFAccountManagementLookupUserAccountInfoRequestWrapper& src) :
        PFAccountManagementLookupUserAccountInfoRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementLookupUserAccountInfoRequestWrapper(PFAccountManagementLookupUserAccountInfoRequestWrapper&& src) :
        PFAccountManagementLookupUserAccountInfoRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLookupUserAccountInfoRequestWrapper& operator=(PFAccountManagementLookupUserAccountInfoRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLookupUserAccountInfoRequestWrapper() = default;

    friend void swap(PFAccountManagementLookupUserAccountInfoRequestWrapper& lhs, PFAccountManagementLookupUserAccountInfoRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_email, rhs.m_email);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_titleDisplayName, rhs.m_titleDisplayName);
        swap(lhs.m_username, rhs.m_username);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetEmail(String value)
    {
        m_email = std::move(value);
        this->m_model.email =  m_email.empty() ? nullptr : m_email.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetTitleDisplayName(String value)
    {
        m_titleDisplayName = std::move(value);
        this->m_model.titleDisplayName =  m_titleDisplayName.empty() ? nullptr : m_titleDisplayName.data();
    }

    void SetUsername(String value)
    {
        m_username = std::move(value);
        this->m_model.username =  m_username.empty() ? nullptr : m_username.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.email = m_email.empty() ? nullptr : m_email.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.titleDisplayName = m_titleDisplayName.empty() ? nullptr : m_titleDisplayName.data();
        this->m_model.username = m_username.empty() ? nullptr : m_username.data();
    }

    String m_email;
    String m_playFabId;
    String m_titleDisplayName;
    String m_username;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLookupUserAccountInfoResultWrapper : public ModelWrapper<PFAccountManagementLookupUserAccountInfoResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLookupUserAccountInfoResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLookupUserAccountInfoResultWrapper() = default;

    PFAccountManagementLookupUserAccountInfoResultWrapper(const PFAccountManagementLookupUserAccountInfoResult& model) :
        ModelWrapper<PFAccountManagementLookupUserAccountInfoResult, Alloc>{ model },
        m_userInfo{ model.userInfo ? StdExtra::optional<PFUserAccountInfoWrapper<Alloc>>{ *model.userInfo } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAccountManagementLookupUserAccountInfoResultWrapper(const PFAccountManagementLookupUserAccountInfoResultWrapper& src) :
        PFAccountManagementLookupUserAccountInfoResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementLookupUserAccountInfoResultWrapper(PFAccountManagementLookupUserAccountInfoResultWrapper&& src) :
        PFAccountManagementLookupUserAccountInfoResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLookupUserAccountInfoResultWrapper& operator=(PFAccountManagementLookupUserAccountInfoResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLookupUserAccountInfoResultWrapper() = default;

    friend void swap(PFAccountManagementLookupUserAccountInfoResultWrapper& lhs, PFAccountManagementLookupUserAccountInfoResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_userInfo, rhs.m_userInfo);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetUserInfo(StdExtra::optional<PFUserAccountInfoWrapper<Alloc>> value)
    {
        m_userInfo = std::move(value);
        this->m_model.userInfo = m_userInfo ? &m_userInfo->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.userInfo = m_userInfo ?  &m_userInfo->Model() : nullptr;
    }

    StdExtra::optional<PFUserAccountInfoWrapper<Alloc>> m_userInfo;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetUserBansRequestWrapper : public ModelWrapper<PFAccountManagementGetUserBansRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetUserBansRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetUserBansRequestWrapper() = default;

    PFAccountManagementGetUserBansRequestWrapper(const PFAccountManagementGetUserBansRequest& model) :
        ModelWrapper<PFAccountManagementGetUserBansRequest, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementGetUserBansRequestWrapper(const PFAccountManagementGetUserBansRequestWrapper& src) :
        PFAccountManagementGetUserBansRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetUserBansRequestWrapper(PFAccountManagementGetUserBansRequestWrapper&& src) :
        PFAccountManagementGetUserBansRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetUserBansRequestWrapper& operator=(PFAccountManagementGetUserBansRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetUserBansRequestWrapper() = default;

    friend void swap(PFAccountManagementGetUserBansRequestWrapper& lhs, PFAccountManagementGetUserBansRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetUserBansResultWrapper : public ModelWrapper<PFAccountManagementGetUserBansResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetUserBansResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetUserBansResultWrapper() = default;

    PFAccountManagementGetUserBansResultWrapper(const PFAccountManagementGetUserBansResult& model) :
        ModelWrapper<PFAccountManagementGetUserBansResult, Alloc>{ model },
        m_banData{ model.banData, model.banData + model.banDataCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetUserBansResultWrapper(const PFAccountManagementGetUserBansResultWrapper& src) :
        PFAccountManagementGetUserBansResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetUserBansResultWrapper(PFAccountManagementGetUserBansResultWrapper&& src) :
        PFAccountManagementGetUserBansResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetUserBansResultWrapper& operator=(PFAccountManagementGetUserBansResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetUserBansResultWrapper() = default;

    friend void swap(PFAccountManagementGetUserBansResultWrapper& lhs, PFAccountManagementGetUserBansResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_banData, rhs.m_banData);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBanData(ModelVector<PFAccountManagementBanInfoWrapper<Alloc>, Alloc> value)
    {
        m_banData = std::move(value);
        this->m_model.banData =  m_banData.empty() ? nullptr : m_banData.data();
        this->m_model.banDataCount =  static_cast<uint32_t>(m_banData.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.banData = m_banData.empty() ? nullptr : m_banData.data();
    }

    ModelVector<PFAccountManagementBanInfoWrapper<Alloc>, Alloc> m_banData;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementResetPasswordRequestWrapper : public ModelWrapper<PFAccountManagementResetPasswordRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementResetPasswordRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementResetPasswordRequestWrapper() = default;

    PFAccountManagementResetPasswordRequestWrapper(const PFAccountManagementResetPasswordRequest& model) :
        ModelWrapper<PFAccountManagementResetPasswordRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_password{ SafeString(model.password) },
        m_token{ SafeString(model.token) }
    {
        SetModelPointers();
    }

    PFAccountManagementResetPasswordRequestWrapper(const PFAccountManagementResetPasswordRequestWrapper& src) :
        PFAccountManagementResetPasswordRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementResetPasswordRequestWrapper(PFAccountManagementResetPasswordRequestWrapper&& src) :
        PFAccountManagementResetPasswordRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementResetPasswordRequestWrapper& operator=(PFAccountManagementResetPasswordRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementResetPasswordRequestWrapper() = default;

    friend void swap(PFAccountManagementResetPasswordRequestWrapper& lhs, PFAccountManagementResetPasswordRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_password, rhs.m_password);
        swap(lhs.m_token, rhs.m_token);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPassword(String value)
    {
        m_password = std::move(value);
        this->m_model.password =  m_password.empty() ? nullptr : m_password.data();
    }

    void SetToken(String value)
    {
        m_token = std::move(value);
        this->m_model.token =  m_token.empty() ? nullptr : m_token.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.password = m_password.empty() ? nullptr : m_password.data();
        this->m_model.token = m_token.empty() ? nullptr : m_token.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_password;
    String m_token;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementRevokeAllBansForUserRequestWrapper : public ModelWrapper<PFAccountManagementRevokeAllBansForUserRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementRevokeAllBansForUserRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementRevokeAllBansForUserRequestWrapper() = default;

    PFAccountManagementRevokeAllBansForUserRequestWrapper(const PFAccountManagementRevokeAllBansForUserRequest& model) :
        ModelWrapper<PFAccountManagementRevokeAllBansForUserRequest, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementRevokeAllBansForUserRequestWrapper(const PFAccountManagementRevokeAllBansForUserRequestWrapper& src) :
        PFAccountManagementRevokeAllBansForUserRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementRevokeAllBansForUserRequestWrapper(PFAccountManagementRevokeAllBansForUserRequestWrapper&& src) :
        PFAccountManagementRevokeAllBansForUserRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementRevokeAllBansForUserRequestWrapper& operator=(PFAccountManagementRevokeAllBansForUserRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementRevokeAllBansForUserRequestWrapper() = default;

    friend void swap(PFAccountManagementRevokeAllBansForUserRequestWrapper& lhs, PFAccountManagementRevokeAllBansForUserRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementRevokeAllBansForUserResultWrapper : public ModelWrapper<PFAccountManagementRevokeAllBansForUserResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementRevokeAllBansForUserResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementRevokeAllBansForUserResultWrapper() = default;

    PFAccountManagementRevokeAllBansForUserResultWrapper(const PFAccountManagementRevokeAllBansForUserResult& model) :
        ModelWrapper<PFAccountManagementRevokeAllBansForUserResult, Alloc>{ model },
        m_banData{ model.banData, model.banData + model.banDataCount }
    {
        SetModelPointers();
    }

    PFAccountManagementRevokeAllBansForUserResultWrapper(const PFAccountManagementRevokeAllBansForUserResultWrapper& src) :
        PFAccountManagementRevokeAllBansForUserResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementRevokeAllBansForUserResultWrapper(PFAccountManagementRevokeAllBansForUserResultWrapper&& src) :
        PFAccountManagementRevokeAllBansForUserResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementRevokeAllBansForUserResultWrapper& operator=(PFAccountManagementRevokeAllBansForUserResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementRevokeAllBansForUserResultWrapper() = default;

    friend void swap(PFAccountManagementRevokeAllBansForUserResultWrapper& lhs, PFAccountManagementRevokeAllBansForUserResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_banData, rhs.m_banData);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBanData(ModelVector<PFAccountManagementBanInfoWrapper<Alloc>, Alloc> value)
    {
        m_banData = std::move(value);
        this->m_model.banData =  m_banData.empty() ? nullptr : m_banData.data();
        this->m_model.banDataCount =  static_cast<uint32_t>(m_banData.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.banData = m_banData.empty() ? nullptr : m_banData.data();
    }

    ModelVector<PFAccountManagementBanInfoWrapper<Alloc>, Alloc> m_banData;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementRevokeBansRequestWrapper : public ModelWrapper<PFAccountManagementRevokeBansRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementRevokeBansRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementRevokeBansRequestWrapper() = default;

    PFAccountManagementRevokeBansRequestWrapper(const PFAccountManagementRevokeBansRequest& model) :
        ModelWrapper<PFAccountManagementRevokeBansRequest, Alloc>{ model },
        m_banIds{ model.banIds, model.banIds + model.banIdsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementRevokeBansRequestWrapper(const PFAccountManagementRevokeBansRequestWrapper& src) :
        PFAccountManagementRevokeBansRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementRevokeBansRequestWrapper(PFAccountManagementRevokeBansRequestWrapper&& src) :
        PFAccountManagementRevokeBansRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementRevokeBansRequestWrapper& operator=(PFAccountManagementRevokeBansRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementRevokeBansRequestWrapper() = default;

    friend void swap(PFAccountManagementRevokeBansRequestWrapper& lhs, PFAccountManagementRevokeBansRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_banIds, rhs.m_banIds);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBanIds(CStringVector<Alloc> value)
    {
        m_banIds = std::move(value);
        this->m_model.banIds =  m_banIds.empty() ? nullptr : m_banIds.data();
        this->m_model.banIdsCount =  static_cast<uint32_t>(m_banIds.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.banIds = m_banIds.empty() ? nullptr : m_banIds.data();
    }

    CStringVector<Alloc> m_banIds;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementRevokeBansResultWrapper : public ModelWrapper<PFAccountManagementRevokeBansResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementRevokeBansResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementRevokeBansResultWrapper() = default;

    PFAccountManagementRevokeBansResultWrapper(const PFAccountManagementRevokeBansResult& model) :
        ModelWrapper<PFAccountManagementRevokeBansResult, Alloc>{ model },
        m_banData{ model.banData, model.banData + model.banDataCount }
    {
        SetModelPointers();
    }

    PFAccountManagementRevokeBansResultWrapper(const PFAccountManagementRevokeBansResultWrapper& src) :
        PFAccountManagementRevokeBansResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementRevokeBansResultWrapper(PFAccountManagementRevokeBansResultWrapper&& src) :
        PFAccountManagementRevokeBansResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementRevokeBansResultWrapper& operator=(PFAccountManagementRevokeBansResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementRevokeBansResultWrapper() = default;

    friend void swap(PFAccountManagementRevokeBansResultWrapper& lhs, PFAccountManagementRevokeBansResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_banData, rhs.m_banData);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBanData(ModelVector<PFAccountManagementBanInfoWrapper<Alloc>, Alloc> value)
    {
        m_banData = std::move(value);
        this->m_model.banData =  m_banData.empty() ? nullptr : m_banData.data();
        this->m_model.banDataCount =  static_cast<uint32_t>(m_banData.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.banData = m_banData.empty() ? nullptr : m_banData.data();
    }

    ModelVector<PFAccountManagementBanInfoWrapper<Alloc>, Alloc> m_banData;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper : public ModelWrapper<PFAccountManagementAdminSendAccountRecoveryEmailRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementAdminSendAccountRecoveryEmailRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper() = default;

    PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper(const PFAccountManagementAdminSendAccountRecoveryEmailRequest& model) :
        ModelWrapper<PFAccountManagementAdminSendAccountRecoveryEmailRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_email{ SafeString(model.email) },
        m_emailTemplateId{ SafeString(model.emailTemplateId) }
    {
        SetModelPointers();
    }

    PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper(const PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper& src) :
        PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper(PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper&& src) :
        PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper& operator=(PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper() = default;

    friend void swap(PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper& lhs, PFAccountManagementAdminSendAccountRecoveryEmailRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_email, rhs.m_email);
        swap(lhs.m_emailTemplateId, rhs.m_emailTemplateId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEmail(String value)
    {
        m_email = std::move(value);
        this->m_model.email =  m_email.empty() ? nullptr : m_email.data();
    }

    void SetEmailTemplateId(String value)
    {
        m_emailTemplateId = std::move(value);
        this->m_model.emailTemplateId =  m_emailTemplateId.empty() ? nullptr : m_emailTemplateId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.email = m_email.empty() ? nullptr : m_email.data();
        this->m_model.emailTemplateId = m_emailTemplateId.empty() ? nullptr : m_emailTemplateId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_email;
    String m_emailTemplateId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementSetMembershipOverrideRequestWrapper : public ModelWrapper<PFAccountManagementSetMembershipOverrideRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementSetMembershipOverrideRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementSetMembershipOverrideRequestWrapper() = default;

    PFAccountManagementSetMembershipOverrideRequestWrapper(const PFAccountManagementSetMembershipOverrideRequest& model) :
        ModelWrapper<PFAccountManagementSetMembershipOverrideRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_membershipId{ SafeString(model.membershipId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementSetMembershipOverrideRequestWrapper(const PFAccountManagementSetMembershipOverrideRequestWrapper& src) :
        PFAccountManagementSetMembershipOverrideRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementSetMembershipOverrideRequestWrapper(PFAccountManagementSetMembershipOverrideRequestWrapper&& src) :
        PFAccountManagementSetMembershipOverrideRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementSetMembershipOverrideRequestWrapper& operator=(PFAccountManagementSetMembershipOverrideRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementSetMembershipOverrideRequestWrapper() = default;

    friend void swap(PFAccountManagementSetMembershipOverrideRequestWrapper& lhs, PFAccountManagementSetMembershipOverrideRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_membershipId, rhs.m_membershipId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetExpirationTime(time_t value)
    {
        this->m_model.expirationTime = value;
    }

    void SetMembershipId(String value)
    {
        m_membershipId = std::move(value);
        this->m_model.membershipId =  m_membershipId.empty() ? nullptr : m_membershipId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.membershipId = m_membershipId.empty() ? nullptr : m_membershipId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_membershipId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUpdateBanRequestWrapper : public ModelWrapper<PFAccountManagementUpdateBanRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUpdateBanRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUpdateBanRequestWrapper() = default;

    PFAccountManagementUpdateBanRequestWrapper(const PFAccountManagementUpdateBanRequest& model) :
        ModelWrapper<PFAccountManagementUpdateBanRequest, Alloc>{ model },
        m_active{ model.active ? StdExtra::optional<bool>{ *model.active } : StdExtra::nullopt },
        m_banId{ SafeString(model.banId) },
        m_expires{ model.expires ? StdExtra::optional<time_t>{ *model.expires } : StdExtra::nullopt },
        m_IPAddress{ SafeString(model.IPAddress) },
        m_MACAddress{ SafeString(model.MACAddress) },
        m_permanent{ model.permanent ? StdExtra::optional<bool>{ *model.permanent } : StdExtra::nullopt },
        m_reason{ SafeString(model.reason) }
    {
        SetModelPointers();
    }

    PFAccountManagementUpdateBanRequestWrapper(const PFAccountManagementUpdateBanRequestWrapper& src) :
        PFAccountManagementUpdateBanRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementUpdateBanRequestWrapper(PFAccountManagementUpdateBanRequestWrapper&& src) :
        PFAccountManagementUpdateBanRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUpdateBanRequestWrapper& operator=(PFAccountManagementUpdateBanRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUpdateBanRequestWrapper() = default;

    friend void swap(PFAccountManagementUpdateBanRequestWrapper& lhs, PFAccountManagementUpdateBanRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_active, rhs.m_active);
        swap(lhs.m_banId, rhs.m_banId);
        swap(lhs.m_expires, rhs.m_expires);
        swap(lhs.m_IPAddress, rhs.m_IPAddress);
        swap(lhs.m_MACAddress, rhs.m_MACAddress);
        swap(lhs.m_permanent, rhs.m_permanent);
        swap(lhs.m_reason, rhs.m_reason);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetActive(StdExtra::optional<bool> value)
    {
        m_active = std::move(value);
        this->m_model.active = m_active ? m_active.operator->() : nullptr;
    }

    void SetBanId(String value)
    {
        m_banId = std::move(value);
        this->m_model.banId =  m_banId.empty() ? nullptr : m_banId.data();
    }

    void SetExpires(StdExtra::optional<time_t> value)
    {
        m_expires = std::move(value);
        this->m_model.expires = m_expires ? m_expires.operator->() : nullptr;
    }

    void SetIPAddress(String value)
    {
        m_IPAddress = std::move(value);
        this->m_model.IPAddress =  m_IPAddress.empty() ? nullptr : m_IPAddress.data();
    }

    void SetMACAddress(String value)
    {
        m_MACAddress = std::move(value);
        this->m_model.MACAddress =  m_MACAddress.empty() ? nullptr : m_MACAddress.data();
    }

    void SetPermanent(StdExtra::optional<bool> value)
    {
        m_permanent = std::move(value);
        this->m_model.permanent = m_permanent ? m_permanent.operator->() : nullptr;
    }

    void SetReason(String value)
    {
        m_reason = std::move(value);
        this->m_model.reason =  m_reason.empty() ? nullptr : m_reason.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.active = m_active ? m_active.operator->() : nullptr;
        this->m_model.banId = m_banId.empty() ? nullptr : m_banId.data();
        this->m_model.expires = m_expires ? m_expires.operator->() : nullptr;
        this->m_model.IPAddress = m_IPAddress.empty() ? nullptr : m_IPAddress.data();
        this->m_model.MACAddress = m_MACAddress.empty() ? nullptr : m_MACAddress.data();
        this->m_model.permanent = m_permanent ? m_permanent.operator->() : nullptr;
        this->m_model.reason = m_reason.empty() ? nullptr : m_reason.data();
    }

    StdExtra::optional<bool> m_active;
    String m_banId;
    StdExtra::optional<time_t> m_expires;
    String m_IPAddress;
    String m_MACAddress;
    StdExtra::optional<bool> m_permanent;
    String m_reason;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUpdateBansRequestWrapper : public ModelWrapper<PFAccountManagementUpdateBansRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUpdateBansRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUpdateBansRequestWrapper() = default;

    PFAccountManagementUpdateBansRequestWrapper(const PFAccountManagementUpdateBansRequest& model) :
        ModelWrapper<PFAccountManagementUpdateBansRequest, Alloc>{ model },
        m_bans{ model.bans, model.bans + model.bansCount }
    {
        SetModelPointers();
    }

    PFAccountManagementUpdateBansRequestWrapper(const PFAccountManagementUpdateBansRequestWrapper& src) :
        PFAccountManagementUpdateBansRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementUpdateBansRequestWrapper(PFAccountManagementUpdateBansRequestWrapper&& src) :
        PFAccountManagementUpdateBansRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUpdateBansRequestWrapper& operator=(PFAccountManagementUpdateBansRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUpdateBansRequestWrapper() = default;

    friend void swap(PFAccountManagementUpdateBansRequestWrapper& lhs, PFAccountManagementUpdateBansRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_bans, rhs.m_bans);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBans(ModelVector<PFAccountManagementUpdateBanRequestWrapper<Alloc>, Alloc> value)
    {
        m_bans = std::move(value);
        this->m_model.bans =  m_bans.empty() ? nullptr : m_bans.data();
        this->m_model.bansCount =  static_cast<uint32_t>(m_bans.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.bans = m_bans.empty() ? nullptr : m_bans.data();
    }

    ModelVector<PFAccountManagementUpdateBanRequestWrapper<Alloc>, Alloc> m_bans;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUpdateBansResultWrapper : public ModelWrapper<PFAccountManagementUpdateBansResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUpdateBansResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUpdateBansResultWrapper() = default;

    PFAccountManagementUpdateBansResultWrapper(const PFAccountManagementUpdateBansResult& model) :
        ModelWrapper<PFAccountManagementUpdateBansResult, Alloc>{ model },
        m_banData{ model.banData, model.banData + model.banDataCount }
    {
        SetModelPointers();
    }

    PFAccountManagementUpdateBansResultWrapper(const PFAccountManagementUpdateBansResultWrapper& src) :
        PFAccountManagementUpdateBansResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementUpdateBansResultWrapper(PFAccountManagementUpdateBansResultWrapper&& src) :
        PFAccountManagementUpdateBansResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUpdateBansResultWrapper& operator=(PFAccountManagementUpdateBansResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUpdateBansResultWrapper() = default;

    friend void swap(PFAccountManagementUpdateBansResultWrapper& lhs, PFAccountManagementUpdateBansResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_banData, rhs.m_banData);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBanData(ModelVector<PFAccountManagementBanInfoWrapper<Alloc>, Alloc> value)
    {
        m_banData = std::move(value);
        this->m_model.banData =  m_banData.empty() ? nullptr : m_banData.data();
        this->m_model.banDataCount =  static_cast<uint32_t>(m_banData.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.banData = m_banData.empty() ? nullptr : m_banData.data();
    }

    ModelVector<PFAccountManagementBanInfoWrapper<Alloc>, Alloc> m_banData;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper : public ModelWrapper<PFAccountManagementAdminUpdateUserTitleDisplayNameRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementAdminUpdateUserTitleDisplayNameRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper() = default;

    PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper(const PFAccountManagementAdminUpdateUserTitleDisplayNameRequest& model) :
        ModelWrapper<PFAccountManagementAdminUpdateUserTitleDisplayNameRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_displayName{ SafeString(model.displayName) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper(const PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper& src) :
        PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper(PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper&& src) :
        PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper& operator=(PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper() = default;

    friend void swap(PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper& lhs, PFAccountManagementAdminUpdateUserTitleDisplayNameRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_displayName, rhs.m_displayName);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetDisplayName(String value)
    {
        m_displayName = std::move(value);
        this->m_model.displayName =  m_displayName.empty() ? nullptr : m_displayName.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.displayName = m_displayName.empty() ? nullptr : m_displayName.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_displayName;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUpdateUserTitleDisplayNameResultWrapper : public ModelWrapper<PFAccountManagementUpdateUserTitleDisplayNameResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUpdateUserTitleDisplayNameResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUpdateUserTitleDisplayNameResultWrapper() = default;

    PFAccountManagementUpdateUserTitleDisplayNameResultWrapper(const PFAccountManagementUpdateUserTitleDisplayNameResult& model) :
        ModelWrapper<PFAccountManagementUpdateUserTitleDisplayNameResult, Alloc>{ model },
        m_displayName{ SafeString(model.displayName) }
    {
        SetModelPointers();
    }

    PFAccountManagementUpdateUserTitleDisplayNameResultWrapper(const PFAccountManagementUpdateUserTitleDisplayNameResultWrapper& src) :
        PFAccountManagementUpdateUserTitleDisplayNameResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementUpdateUserTitleDisplayNameResultWrapper(PFAccountManagementUpdateUserTitleDisplayNameResultWrapper&& src) :
        PFAccountManagementUpdateUserTitleDisplayNameResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUpdateUserTitleDisplayNameResultWrapper& operator=(PFAccountManagementUpdateUserTitleDisplayNameResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUpdateUserTitleDisplayNameResultWrapper() = default;

    friend void swap(PFAccountManagementUpdateUserTitleDisplayNameResultWrapper& lhs, PFAccountManagementUpdateUserTitleDisplayNameResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_displayName, rhs.m_displayName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDisplayName(String value)
    {
        m_displayName = std::move(value);
        this->m_model.displayName =  m_displayName.empty() ? nullptr : m_displayName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.displayName = m_displayName.empty() ? nullptr : m_displayName.data();
    }

    String m_displayName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGenericServiceIdWrapper : public ModelWrapper<PFAccountManagementGenericServiceId, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGenericServiceId;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGenericServiceIdWrapper() = default;

    PFAccountManagementGenericServiceIdWrapper(const PFAccountManagementGenericServiceId& model) :
        ModelWrapper<PFAccountManagementGenericServiceId, Alloc>{ model },
        m_serviceName{ SafeString(model.serviceName) },
        m_userId{ SafeString(model.userId) }
    {
        SetModelPointers();
    }

    PFAccountManagementGenericServiceIdWrapper(const PFAccountManagementGenericServiceIdWrapper& src) :
        PFAccountManagementGenericServiceIdWrapper{ src.Model() }
    {
    }

    PFAccountManagementGenericServiceIdWrapper(PFAccountManagementGenericServiceIdWrapper&& src) :
        PFAccountManagementGenericServiceIdWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGenericServiceIdWrapper& operator=(PFAccountManagementGenericServiceIdWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGenericServiceIdWrapper() = default;

    friend void swap(PFAccountManagementGenericServiceIdWrapper& lhs, PFAccountManagementGenericServiceIdWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_serviceName, rhs.m_serviceName);
        swap(lhs.m_userId, rhs.m_userId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetServiceName(String value)
    {
        m_serviceName = std::move(value);
        this->m_model.serviceName =  m_serviceName.empty() ? nullptr : m_serviceName.data();
    }

    void SetUserId(String value)
    {
        m_userId = std::move(value);
        this->m_model.userId =  m_userId.empty() ? nullptr : m_userId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.serviceName = m_serviceName.empty() ? nullptr : m_serviceName.data();
        this->m_model.userId = m_userId.empty() ? nullptr : m_userId.data();
    }

    String m_serviceName;
    String m_userId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementClientAddGenericIDRequestWrapper : public ModelWrapper<PFAccountManagementClientAddGenericIDRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementClientAddGenericIDRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementClientAddGenericIDRequestWrapper() = default;

    PFAccountManagementClientAddGenericIDRequestWrapper(const PFAccountManagementClientAddGenericIDRequest& model) :
        ModelWrapper<PFAccountManagementClientAddGenericIDRequest, Alloc>{ model },
        m_genericId{ model.genericId ? *model.genericId : decltype(*model.genericId){} }
    {
        SetModelPointers();
    }

    PFAccountManagementClientAddGenericIDRequestWrapper(const PFAccountManagementClientAddGenericIDRequestWrapper& src) :
        PFAccountManagementClientAddGenericIDRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementClientAddGenericIDRequestWrapper(PFAccountManagementClientAddGenericIDRequestWrapper&& src) :
        PFAccountManagementClientAddGenericIDRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementClientAddGenericIDRequestWrapper& operator=(PFAccountManagementClientAddGenericIDRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementClientAddGenericIDRequestWrapper() = default;

    friend void swap(PFAccountManagementClientAddGenericIDRequestWrapper& lhs, PFAccountManagementClientAddGenericIDRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_genericId, rhs.m_genericId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGenericId(PFAccountManagementGenericServiceIdWrapper<Alloc> value)
    {
        m_genericId = std::move(value);
        this->m_model.genericId = &m_genericId.Model();
    }

private:
    void SetModelPointers()
    {
        this->m_model.genericId = &m_genericId.Model();
    }

    PFAccountManagementGenericServiceIdWrapper<Alloc> m_genericId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementAddOrUpdateContactEmailRequestWrapper : public ModelWrapper<PFAccountManagementAddOrUpdateContactEmailRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementAddOrUpdateContactEmailRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementAddOrUpdateContactEmailRequestWrapper() = default;

    PFAccountManagementAddOrUpdateContactEmailRequestWrapper(const PFAccountManagementAddOrUpdateContactEmailRequest& model) :
        ModelWrapper<PFAccountManagementAddOrUpdateContactEmailRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_emailAddress{ SafeString(model.emailAddress) }
    {
        SetModelPointers();
    }

    PFAccountManagementAddOrUpdateContactEmailRequestWrapper(const PFAccountManagementAddOrUpdateContactEmailRequestWrapper& src) :
        PFAccountManagementAddOrUpdateContactEmailRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementAddOrUpdateContactEmailRequestWrapper(PFAccountManagementAddOrUpdateContactEmailRequestWrapper&& src) :
        PFAccountManagementAddOrUpdateContactEmailRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementAddOrUpdateContactEmailRequestWrapper& operator=(PFAccountManagementAddOrUpdateContactEmailRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementAddOrUpdateContactEmailRequestWrapper() = default;

    friend void swap(PFAccountManagementAddOrUpdateContactEmailRequestWrapper& lhs, PFAccountManagementAddOrUpdateContactEmailRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_emailAddress, rhs.m_emailAddress);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEmailAddress(String value)
    {
        m_emailAddress = std::move(value);
        this->m_model.emailAddress =  m_emailAddress.empty() ? nullptr : m_emailAddress.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.emailAddress = m_emailAddress.empty() ? nullptr : m_emailAddress.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_emailAddress;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementAddUsernamePasswordRequestWrapper : public ModelWrapper<PFAccountManagementAddUsernamePasswordRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementAddUsernamePasswordRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementAddUsernamePasswordRequestWrapper() = default;

    PFAccountManagementAddUsernamePasswordRequestWrapper(const PFAccountManagementAddUsernamePasswordRequest& model) :
        ModelWrapper<PFAccountManagementAddUsernamePasswordRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_email{ SafeString(model.email) },
        m_password{ SafeString(model.password) },
        m_username{ SafeString(model.username) }
    {
        SetModelPointers();
    }

    PFAccountManagementAddUsernamePasswordRequestWrapper(const PFAccountManagementAddUsernamePasswordRequestWrapper& src) :
        PFAccountManagementAddUsernamePasswordRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementAddUsernamePasswordRequestWrapper(PFAccountManagementAddUsernamePasswordRequestWrapper&& src) :
        PFAccountManagementAddUsernamePasswordRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementAddUsernamePasswordRequestWrapper& operator=(PFAccountManagementAddUsernamePasswordRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementAddUsernamePasswordRequestWrapper() = default;

    friend void swap(PFAccountManagementAddUsernamePasswordRequestWrapper& lhs, PFAccountManagementAddUsernamePasswordRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_email, rhs.m_email);
        swap(lhs.m_password, rhs.m_password);
        swap(lhs.m_username, rhs.m_username);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEmail(String value)
    {
        m_email = std::move(value);
        this->m_model.email =  m_email.empty() ? nullptr : m_email.data();
    }

    void SetPassword(String value)
    {
        m_password = std::move(value);
        this->m_model.password =  m_password.empty() ? nullptr : m_password.data();
    }

    void SetUsername(String value)
    {
        m_username = std::move(value);
        this->m_model.username =  m_username.empty() ? nullptr : m_username.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.email = m_email.empty() ? nullptr : m_email.data();
        this->m_model.password = m_password.empty() ? nullptr : m_password.data();
        this->m_model.username = m_username.empty() ? nullptr : m_username.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_email;
    String m_password;
    String m_username;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementAddUsernamePasswordResultWrapper : public ModelWrapper<PFAccountManagementAddUsernamePasswordResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementAddUsernamePasswordResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementAddUsernamePasswordResultWrapper() = default;

    PFAccountManagementAddUsernamePasswordResultWrapper(const PFAccountManagementAddUsernamePasswordResult& model) :
        ModelWrapper<PFAccountManagementAddUsernamePasswordResult, Alloc>{ model },
        m_username{ SafeString(model.username) }
    {
        SetModelPointers();
    }

    PFAccountManagementAddUsernamePasswordResultWrapper(const PFAccountManagementAddUsernamePasswordResultWrapper& src) :
        PFAccountManagementAddUsernamePasswordResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementAddUsernamePasswordResultWrapper(PFAccountManagementAddUsernamePasswordResultWrapper&& src) :
        PFAccountManagementAddUsernamePasswordResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementAddUsernamePasswordResultWrapper& operator=(PFAccountManagementAddUsernamePasswordResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementAddUsernamePasswordResultWrapper() = default;

    friend void swap(PFAccountManagementAddUsernamePasswordResultWrapper& lhs, PFAccountManagementAddUsernamePasswordResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_username, rhs.m_username);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetUsername(String value)
    {
        m_username = std::move(value);
        this->m_model.username =  m_username.empty() ? nullptr : m_username.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.username = m_username.empty() ? nullptr : m_username.data();
    }

    String m_username;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetAccountInfoRequestWrapper : public ModelWrapper<PFAccountManagementGetAccountInfoRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetAccountInfoRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetAccountInfoRequestWrapper() = default;

    PFAccountManagementGetAccountInfoRequestWrapper(const PFAccountManagementGetAccountInfoRequest& model) :
        ModelWrapper<PFAccountManagementGetAccountInfoRequest, Alloc>{ model },
        m_email{ SafeString(model.email) },
        m_playFabId{ SafeString(model.playFabId) },
        m_titleDisplayName{ SafeString(model.titleDisplayName) },
        m_username{ SafeString(model.username) }
    {
        SetModelPointers();
    }

    PFAccountManagementGetAccountInfoRequestWrapper(const PFAccountManagementGetAccountInfoRequestWrapper& src) :
        PFAccountManagementGetAccountInfoRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetAccountInfoRequestWrapper(PFAccountManagementGetAccountInfoRequestWrapper&& src) :
        PFAccountManagementGetAccountInfoRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetAccountInfoRequestWrapper& operator=(PFAccountManagementGetAccountInfoRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetAccountInfoRequestWrapper() = default;

    friend void swap(PFAccountManagementGetAccountInfoRequestWrapper& lhs, PFAccountManagementGetAccountInfoRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_email, rhs.m_email);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_titleDisplayName, rhs.m_titleDisplayName);
        swap(lhs.m_username, rhs.m_username);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetEmail(String value)
    {
        m_email = std::move(value);
        this->m_model.email =  m_email.empty() ? nullptr : m_email.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetTitleDisplayName(String value)
    {
        m_titleDisplayName = std::move(value);
        this->m_model.titleDisplayName =  m_titleDisplayName.empty() ? nullptr : m_titleDisplayName.data();
    }

    void SetUsername(String value)
    {
        m_username = std::move(value);
        this->m_model.username =  m_username.empty() ? nullptr : m_username.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.email = m_email.empty() ? nullptr : m_email.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.titleDisplayName = m_titleDisplayName.empty() ? nullptr : m_titleDisplayName.data();
        this->m_model.username = m_username.empty() ? nullptr : m_username.data();
    }

    String m_email;
    String m_playFabId;
    String m_titleDisplayName;
    String m_username;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetAccountInfoResultWrapper : public ModelWrapper<PFAccountManagementGetAccountInfoResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetAccountInfoResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetAccountInfoResultWrapper() = default;

    PFAccountManagementGetAccountInfoResultWrapper(const PFAccountManagementGetAccountInfoResult& model) :
        ModelWrapper<PFAccountManagementGetAccountInfoResult, Alloc>{ model },
        m_accountInfo{ model.accountInfo ? StdExtra::optional<PFUserAccountInfoWrapper<Alloc>>{ *model.accountInfo } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAccountManagementGetAccountInfoResultWrapper(const PFAccountManagementGetAccountInfoResultWrapper& src) :
        PFAccountManagementGetAccountInfoResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetAccountInfoResultWrapper(PFAccountManagementGetAccountInfoResultWrapper&& src) :
        PFAccountManagementGetAccountInfoResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetAccountInfoResultWrapper& operator=(PFAccountManagementGetAccountInfoResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetAccountInfoResultWrapper() = default;

    friend void swap(PFAccountManagementGetAccountInfoResultWrapper& lhs, PFAccountManagementGetAccountInfoResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_accountInfo, rhs.m_accountInfo);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAccountInfo(StdExtra::optional<PFUserAccountInfoWrapper<Alloc>> value)
    {
        m_accountInfo = std::move(value);
        this->m_model.accountInfo = m_accountInfo ? &m_accountInfo->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.accountInfo = m_accountInfo ?  &m_accountInfo->Model() : nullptr;
    }

    StdExtra::optional<PFUserAccountInfoWrapper<Alloc>> m_accountInfo;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromFacebookIDsRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromFacebookIDsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromFacebookIDsRequest& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromFacebookIDsRequest, Alloc>{ model },
        m_facebookIDs{ model.facebookIDs, model.facebookIDs + model.facebookIDsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper(PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper& operator=(PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper& lhs, PFAccountManagementGetPlayFabIDsFromFacebookIDsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_facebookIDs, rhs.m_facebookIDs);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFacebookIDs(CStringVector<Alloc> value)
    {
        m_facebookIDs = std::move(value);
        this->m_model.facebookIDs =  m_facebookIDs.empty() ? nullptr : m_facebookIDs.data();
        this->m_model.facebookIDsCount =  static_cast<uint32_t>(m_facebookIDs.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.facebookIDs = m_facebookIDs.empty() ? nullptr : m_facebookIDs.data();
    }

    CStringVector<Alloc> m_facebookIDs;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementFacebookPlayFabIdPairWrapper : public ModelWrapper<PFAccountManagementFacebookPlayFabIdPair, Alloc>
{
public:
    using ModelType = typename PFAccountManagementFacebookPlayFabIdPair;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementFacebookPlayFabIdPairWrapper() = default;

    PFAccountManagementFacebookPlayFabIdPairWrapper(const PFAccountManagementFacebookPlayFabIdPair& model) :
        ModelWrapper<PFAccountManagementFacebookPlayFabIdPair, Alloc>{ model },
        m_facebookId{ SafeString(model.facebookId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementFacebookPlayFabIdPairWrapper(const PFAccountManagementFacebookPlayFabIdPairWrapper& src) :
        PFAccountManagementFacebookPlayFabIdPairWrapper{ src.Model() }
    {
    }

    PFAccountManagementFacebookPlayFabIdPairWrapper(PFAccountManagementFacebookPlayFabIdPairWrapper&& src) :
        PFAccountManagementFacebookPlayFabIdPairWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementFacebookPlayFabIdPairWrapper& operator=(PFAccountManagementFacebookPlayFabIdPairWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementFacebookPlayFabIdPairWrapper() = default;

    friend void swap(PFAccountManagementFacebookPlayFabIdPairWrapper& lhs, PFAccountManagementFacebookPlayFabIdPairWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_facebookId, rhs.m_facebookId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFacebookId(String value)
    {
        m_facebookId = std::move(value);
        this->m_model.facebookId =  m_facebookId.empty() ? nullptr : m_facebookId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.facebookId = m_facebookId.empty() ? nullptr : m_facebookId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_facebookId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromFacebookIDsResultWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromFacebookIDsResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromFacebookIDsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromFacebookIDsResultWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromFacebookIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromFacebookIDsResult& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromFacebookIDsResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromFacebookIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromFacebookIDsResultWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromFacebookIDsResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromFacebookIDsResultWrapper(PFAccountManagementGetPlayFabIDsFromFacebookIDsResultWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromFacebookIDsResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromFacebookIDsResultWrapper& operator=(PFAccountManagementGetPlayFabIDsFromFacebookIDsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromFacebookIDsResultWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromFacebookIDsResultWrapper& lhs, PFAccountManagementGetPlayFabIDsFromFacebookIDsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(ModelVector<PFAccountManagementFacebookPlayFabIdPairWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
    }

    ModelVector<PFAccountManagementFacebookPlayFabIdPairWrapper<Alloc>, Alloc> m_data;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequest& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequest, Alloc>{ model },
        m_facebookInstantGamesIds{ model.facebookInstantGamesIds, model.facebookInstantGamesIds + model.facebookInstantGamesIdsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper(PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper& operator=(PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper& lhs, PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_facebookInstantGamesIds, rhs.m_facebookInstantGamesIds);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFacebookInstantGamesIds(CStringVector<Alloc> value)
    {
        m_facebookInstantGamesIds = std::move(value);
        this->m_model.facebookInstantGamesIds =  m_facebookInstantGamesIds.empty() ? nullptr : m_facebookInstantGamesIds.data();
        this->m_model.facebookInstantGamesIdsCount =  static_cast<uint32_t>(m_facebookInstantGamesIds.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.facebookInstantGamesIds = m_facebookInstantGamesIds.empty() ? nullptr : m_facebookInstantGamesIds.data();
    }

    CStringVector<Alloc> m_facebookInstantGamesIds;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementFacebookInstantGamesPlayFabIdPairWrapper : public ModelWrapper<PFAccountManagementFacebookInstantGamesPlayFabIdPair, Alloc>
{
public:
    using ModelType = typename PFAccountManagementFacebookInstantGamesPlayFabIdPair;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementFacebookInstantGamesPlayFabIdPairWrapper() = default;

    PFAccountManagementFacebookInstantGamesPlayFabIdPairWrapper(const PFAccountManagementFacebookInstantGamesPlayFabIdPair& model) :
        ModelWrapper<PFAccountManagementFacebookInstantGamesPlayFabIdPair, Alloc>{ model },
        m_facebookInstantGamesId{ SafeString(model.facebookInstantGamesId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementFacebookInstantGamesPlayFabIdPairWrapper(const PFAccountManagementFacebookInstantGamesPlayFabIdPairWrapper& src) :
        PFAccountManagementFacebookInstantGamesPlayFabIdPairWrapper{ src.Model() }
    {
    }

    PFAccountManagementFacebookInstantGamesPlayFabIdPairWrapper(PFAccountManagementFacebookInstantGamesPlayFabIdPairWrapper&& src) :
        PFAccountManagementFacebookInstantGamesPlayFabIdPairWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementFacebookInstantGamesPlayFabIdPairWrapper& operator=(PFAccountManagementFacebookInstantGamesPlayFabIdPairWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementFacebookInstantGamesPlayFabIdPairWrapper() = default;

    friend void swap(PFAccountManagementFacebookInstantGamesPlayFabIdPairWrapper& lhs, PFAccountManagementFacebookInstantGamesPlayFabIdPairWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_facebookInstantGamesId, rhs.m_facebookInstantGamesId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetFacebookInstantGamesId(String value)
    {
        m_facebookInstantGamesId = std::move(value);
        this->m_model.facebookInstantGamesId =  m_facebookInstantGamesId.empty() ? nullptr : m_facebookInstantGamesId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.facebookInstantGamesId = m_facebookInstantGamesId.empty() ? nullptr : m_facebookInstantGamesId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_facebookInstantGamesId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResultWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResultWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResultWrapper(const PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResultWrapper(const PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResultWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResultWrapper(PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResultWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResultWrapper& operator=(PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResultWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResultWrapper& lhs, PFAccountManagementGetPlayFabIDsFromFacebookInstantGamesIdsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(ModelVector<PFAccountManagementFacebookInstantGamesPlayFabIdPairWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
    }

    ModelVector<PFAccountManagementFacebookInstantGamesPlayFabIdPairWrapper<Alloc>, Alloc> m_data;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequest& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequest, Alloc>{ model },
        m_gameCenterIDs{ model.gameCenterIDs, model.gameCenterIDs + model.gameCenterIDsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper(PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper& operator=(PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper& lhs, PFAccountManagementGetPlayFabIDsFromGameCenterIDsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_gameCenterIDs, rhs.m_gameCenterIDs);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGameCenterIDs(CStringVector<Alloc> value)
    {
        m_gameCenterIDs = std::move(value);
        this->m_model.gameCenterIDs =  m_gameCenterIDs.empty() ? nullptr : m_gameCenterIDs.data();
        this->m_model.gameCenterIDsCount =  static_cast<uint32_t>(m_gameCenterIDs.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.gameCenterIDs = m_gameCenterIDs.empty() ? nullptr : m_gameCenterIDs.data();
    }

    CStringVector<Alloc> m_gameCenterIDs;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGameCenterPlayFabIdPairWrapper : public ModelWrapper<PFAccountManagementGameCenterPlayFabIdPair, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGameCenterPlayFabIdPair;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGameCenterPlayFabIdPairWrapper() = default;

    PFAccountManagementGameCenterPlayFabIdPairWrapper(const PFAccountManagementGameCenterPlayFabIdPair& model) :
        ModelWrapper<PFAccountManagementGameCenterPlayFabIdPair, Alloc>{ model },
        m_gameCenterId{ SafeString(model.gameCenterId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementGameCenterPlayFabIdPairWrapper(const PFAccountManagementGameCenterPlayFabIdPairWrapper& src) :
        PFAccountManagementGameCenterPlayFabIdPairWrapper{ src.Model() }
    {
    }

    PFAccountManagementGameCenterPlayFabIdPairWrapper(PFAccountManagementGameCenterPlayFabIdPairWrapper&& src) :
        PFAccountManagementGameCenterPlayFabIdPairWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGameCenterPlayFabIdPairWrapper& operator=(PFAccountManagementGameCenterPlayFabIdPairWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGameCenterPlayFabIdPairWrapper() = default;

    friend void swap(PFAccountManagementGameCenterPlayFabIdPairWrapper& lhs, PFAccountManagementGameCenterPlayFabIdPairWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_gameCenterId, rhs.m_gameCenterId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGameCenterId(String value)
    {
        m_gameCenterId = std::move(value);
        this->m_model.gameCenterId =  m_gameCenterId.empty() ? nullptr : m_gameCenterId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.gameCenterId = m_gameCenterId.empty() ? nullptr : m_gameCenterId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_gameCenterId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromGameCenterIDsResultWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromGameCenterIDsResultWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromGameCenterIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromGameCenterIDsResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromGameCenterIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromGameCenterIDsResultWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromGameCenterIDsResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromGameCenterIDsResultWrapper(PFAccountManagementGetPlayFabIDsFromGameCenterIDsResultWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromGameCenterIDsResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromGameCenterIDsResultWrapper& operator=(PFAccountManagementGetPlayFabIDsFromGameCenterIDsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromGameCenterIDsResultWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromGameCenterIDsResultWrapper& lhs, PFAccountManagementGetPlayFabIDsFromGameCenterIDsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(ModelVector<PFAccountManagementGameCenterPlayFabIdPairWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
    }

    ModelVector<PFAccountManagementGameCenterPlayFabIdPairWrapper<Alloc>, Alloc> m_data;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromGenericIDsRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromGenericIDsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromGenericIDsRequest& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromGenericIDsRequest, Alloc>{ model },
        m_genericIDs{ model.genericIDs, model.genericIDs + model.genericIDsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper(PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper& operator=(PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper& lhs, PFAccountManagementGetPlayFabIDsFromGenericIDsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_genericIDs, rhs.m_genericIDs);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGenericIDs(ModelVector<PFAccountManagementGenericServiceIdWrapper<Alloc>, Alloc> value)
    {
        m_genericIDs = std::move(value);
        this->m_model.genericIDs =  m_genericIDs.empty() ? nullptr : m_genericIDs.data();
        this->m_model.genericIDsCount =  static_cast<uint32_t>(m_genericIDs.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.genericIDs = m_genericIDs.empty() ? nullptr : m_genericIDs.data();
    }

    ModelVector<PFAccountManagementGenericServiceIdWrapper<Alloc>, Alloc> m_genericIDs;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGenericPlayFabIdPairWrapper : public ModelWrapper<PFAccountManagementGenericPlayFabIdPair, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGenericPlayFabIdPair;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGenericPlayFabIdPairWrapper() = default;

    PFAccountManagementGenericPlayFabIdPairWrapper(const PFAccountManagementGenericPlayFabIdPair& model) :
        ModelWrapper<PFAccountManagementGenericPlayFabIdPair, Alloc>{ model },
        m_genericId{ model.genericId ? StdExtra::optional<PFAccountManagementGenericServiceIdWrapper<Alloc>>{ *model.genericId } : StdExtra::nullopt },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementGenericPlayFabIdPairWrapper(const PFAccountManagementGenericPlayFabIdPairWrapper& src) :
        PFAccountManagementGenericPlayFabIdPairWrapper{ src.Model() }
    {
    }

    PFAccountManagementGenericPlayFabIdPairWrapper(PFAccountManagementGenericPlayFabIdPairWrapper&& src) :
        PFAccountManagementGenericPlayFabIdPairWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGenericPlayFabIdPairWrapper& operator=(PFAccountManagementGenericPlayFabIdPairWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGenericPlayFabIdPairWrapper() = default;

    friend void swap(PFAccountManagementGenericPlayFabIdPairWrapper& lhs, PFAccountManagementGenericPlayFabIdPairWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_genericId, rhs.m_genericId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGenericId(StdExtra::optional<PFAccountManagementGenericServiceIdWrapper<Alloc>> value)
    {
        m_genericId = std::move(value);
        this->m_model.genericId = m_genericId ? &m_genericId->Model() : nullptr;
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.genericId = m_genericId ?  &m_genericId->Model() : nullptr;
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StdExtra::optional<PFAccountManagementGenericServiceIdWrapper<Alloc>> m_genericId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromGenericIDsResultWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromGenericIDsResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromGenericIDsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromGenericIDsResultWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromGenericIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromGenericIDsResult& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromGenericIDsResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromGenericIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromGenericIDsResultWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromGenericIDsResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromGenericIDsResultWrapper(PFAccountManagementGetPlayFabIDsFromGenericIDsResultWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromGenericIDsResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromGenericIDsResultWrapper& operator=(PFAccountManagementGetPlayFabIDsFromGenericIDsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromGenericIDsResultWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromGenericIDsResultWrapper& lhs, PFAccountManagementGetPlayFabIDsFromGenericIDsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(ModelVector<PFAccountManagementGenericPlayFabIdPairWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
    }

    ModelVector<PFAccountManagementGenericPlayFabIdPairWrapper<Alloc>, Alloc> m_data;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromGoogleIDsRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromGoogleIDsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromGoogleIDsRequest& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromGoogleIDsRequest, Alloc>{ model },
        m_googleIDs{ model.googleIDs, model.googleIDs + model.googleIDsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper(PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper& operator=(PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper& lhs, PFAccountManagementGetPlayFabIDsFromGoogleIDsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_googleIDs, rhs.m_googleIDs);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGoogleIDs(CStringVector<Alloc> value)
    {
        m_googleIDs = std::move(value);
        this->m_model.googleIDs =  m_googleIDs.empty() ? nullptr : m_googleIDs.data();
        this->m_model.googleIDsCount =  static_cast<uint32_t>(m_googleIDs.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.googleIDs = m_googleIDs.empty() ? nullptr : m_googleIDs.data();
    }

    CStringVector<Alloc> m_googleIDs;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGooglePlayFabIdPairWrapper : public ModelWrapper<PFAccountManagementGooglePlayFabIdPair, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGooglePlayFabIdPair;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGooglePlayFabIdPairWrapper() = default;

    PFAccountManagementGooglePlayFabIdPairWrapper(const PFAccountManagementGooglePlayFabIdPair& model) :
        ModelWrapper<PFAccountManagementGooglePlayFabIdPair, Alloc>{ model },
        m_googleId{ SafeString(model.googleId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementGooglePlayFabIdPairWrapper(const PFAccountManagementGooglePlayFabIdPairWrapper& src) :
        PFAccountManagementGooglePlayFabIdPairWrapper{ src.Model() }
    {
    }

    PFAccountManagementGooglePlayFabIdPairWrapper(PFAccountManagementGooglePlayFabIdPairWrapper&& src) :
        PFAccountManagementGooglePlayFabIdPairWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGooglePlayFabIdPairWrapper& operator=(PFAccountManagementGooglePlayFabIdPairWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGooglePlayFabIdPairWrapper() = default;

    friend void swap(PFAccountManagementGooglePlayFabIdPairWrapper& lhs, PFAccountManagementGooglePlayFabIdPairWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_googleId, rhs.m_googleId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGoogleId(String value)
    {
        m_googleId = std::move(value);
        this->m_model.googleId =  m_googleId.empty() ? nullptr : m_googleId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.googleId = m_googleId.empty() ? nullptr : m_googleId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_googleId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromGoogleIDsResultWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromGoogleIDsResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromGoogleIDsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromGoogleIDsResultWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromGoogleIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromGoogleIDsResult& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromGoogleIDsResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromGoogleIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromGoogleIDsResultWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromGoogleIDsResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromGoogleIDsResultWrapper(PFAccountManagementGetPlayFabIDsFromGoogleIDsResultWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromGoogleIDsResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromGoogleIDsResultWrapper& operator=(PFAccountManagementGetPlayFabIDsFromGoogleIDsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromGoogleIDsResultWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromGoogleIDsResultWrapper& lhs, PFAccountManagementGetPlayFabIDsFromGoogleIDsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(ModelVector<PFAccountManagementGooglePlayFabIdPairWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
    }

    ModelVector<PFAccountManagementGooglePlayFabIdPairWrapper<Alloc>, Alloc> m_data;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromKongregateIDsRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromKongregateIDsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromKongregateIDsRequest& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromKongregateIDsRequest, Alloc>{ model },
        m_kongregateIDs{ model.kongregateIDs, model.kongregateIDs + model.kongregateIDsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper(PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper& operator=(PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper& lhs, PFAccountManagementGetPlayFabIDsFromKongregateIDsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_kongregateIDs, rhs.m_kongregateIDs);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetKongregateIDs(CStringVector<Alloc> value)
    {
        m_kongregateIDs = std::move(value);
        this->m_model.kongregateIDs =  m_kongregateIDs.empty() ? nullptr : m_kongregateIDs.data();
        this->m_model.kongregateIDsCount =  static_cast<uint32_t>(m_kongregateIDs.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.kongregateIDs = m_kongregateIDs.empty() ? nullptr : m_kongregateIDs.data();
    }

    CStringVector<Alloc> m_kongregateIDs;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementKongregatePlayFabIdPairWrapper : public ModelWrapper<PFAccountManagementKongregatePlayFabIdPair, Alloc>
{
public:
    using ModelType = typename PFAccountManagementKongregatePlayFabIdPair;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementKongregatePlayFabIdPairWrapper() = default;

    PFAccountManagementKongregatePlayFabIdPairWrapper(const PFAccountManagementKongregatePlayFabIdPair& model) :
        ModelWrapper<PFAccountManagementKongregatePlayFabIdPair, Alloc>{ model },
        m_kongregateId{ SafeString(model.kongregateId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementKongregatePlayFabIdPairWrapper(const PFAccountManagementKongregatePlayFabIdPairWrapper& src) :
        PFAccountManagementKongregatePlayFabIdPairWrapper{ src.Model() }
    {
    }

    PFAccountManagementKongregatePlayFabIdPairWrapper(PFAccountManagementKongregatePlayFabIdPairWrapper&& src) :
        PFAccountManagementKongregatePlayFabIdPairWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementKongregatePlayFabIdPairWrapper& operator=(PFAccountManagementKongregatePlayFabIdPairWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementKongregatePlayFabIdPairWrapper() = default;

    friend void swap(PFAccountManagementKongregatePlayFabIdPairWrapper& lhs, PFAccountManagementKongregatePlayFabIdPairWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_kongregateId, rhs.m_kongregateId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetKongregateId(String value)
    {
        m_kongregateId = std::move(value);
        this->m_model.kongregateId =  m_kongregateId.empty() ? nullptr : m_kongregateId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.kongregateId = m_kongregateId.empty() ? nullptr : m_kongregateId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_kongregateId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromKongregateIDsResultWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromKongregateIDsResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromKongregateIDsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromKongregateIDsResultWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromKongregateIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromKongregateIDsResult& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromKongregateIDsResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromKongregateIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromKongregateIDsResultWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromKongregateIDsResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromKongregateIDsResultWrapper(PFAccountManagementGetPlayFabIDsFromKongregateIDsResultWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromKongregateIDsResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromKongregateIDsResultWrapper& operator=(PFAccountManagementGetPlayFabIDsFromKongregateIDsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromKongregateIDsResultWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromKongregateIDsResultWrapper& lhs, PFAccountManagementGetPlayFabIDsFromKongregateIDsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(ModelVector<PFAccountManagementKongregatePlayFabIdPairWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
    }

    ModelVector<PFAccountManagementKongregatePlayFabIdPairWrapper<Alloc>, Alloc> m_data;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequest, Alloc>{ model },
        m_nintendoSwitchDeviceIds{ model.nintendoSwitchDeviceIds, model.nintendoSwitchDeviceIds + model.nintendoSwitchDeviceIdsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper(PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper& operator=(PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper& lhs, PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_nintendoSwitchDeviceIds, rhs.m_nintendoSwitchDeviceIds);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetNintendoSwitchDeviceIds(CStringVector<Alloc> value)
    {
        m_nintendoSwitchDeviceIds = std::move(value);
        this->m_model.nintendoSwitchDeviceIds =  m_nintendoSwitchDeviceIds.empty() ? nullptr : m_nintendoSwitchDeviceIds.data();
        this->m_model.nintendoSwitchDeviceIdsCount =  static_cast<uint32_t>(m_nintendoSwitchDeviceIds.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.nintendoSwitchDeviceIds = m_nintendoSwitchDeviceIds.empty() ? nullptr : m_nintendoSwitchDeviceIds.data();
    }

    CStringVector<Alloc> m_nintendoSwitchDeviceIds;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementNintendoSwitchPlayFabIdPairWrapper : public ModelWrapper<PFAccountManagementNintendoSwitchPlayFabIdPair, Alloc>
{
public:
    using ModelType = typename PFAccountManagementNintendoSwitchPlayFabIdPair;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementNintendoSwitchPlayFabIdPairWrapper() = default;

    PFAccountManagementNintendoSwitchPlayFabIdPairWrapper(const PFAccountManagementNintendoSwitchPlayFabIdPair& model) :
        ModelWrapper<PFAccountManagementNintendoSwitchPlayFabIdPair, Alloc>{ model },
        m_nintendoSwitchDeviceId{ SafeString(model.nintendoSwitchDeviceId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementNintendoSwitchPlayFabIdPairWrapper(const PFAccountManagementNintendoSwitchPlayFabIdPairWrapper& src) :
        PFAccountManagementNintendoSwitchPlayFabIdPairWrapper{ src.Model() }
    {
    }

    PFAccountManagementNintendoSwitchPlayFabIdPairWrapper(PFAccountManagementNintendoSwitchPlayFabIdPairWrapper&& src) :
        PFAccountManagementNintendoSwitchPlayFabIdPairWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementNintendoSwitchPlayFabIdPairWrapper& operator=(PFAccountManagementNintendoSwitchPlayFabIdPairWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementNintendoSwitchPlayFabIdPairWrapper() = default;

    friend void swap(PFAccountManagementNintendoSwitchPlayFabIdPairWrapper& lhs, PFAccountManagementNintendoSwitchPlayFabIdPairWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_nintendoSwitchDeviceId, rhs.m_nintendoSwitchDeviceId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetNintendoSwitchDeviceId(String value)
    {
        m_nintendoSwitchDeviceId = std::move(value);
        this->m_model.nintendoSwitchDeviceId =  m_nintendoSwitchDeviceId.empty() ? nullptr : m_nintendoSwitchDeviceId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.nintendoSwitchDeviceId = m_nintendoSwitchDeviceId.empty() ? nullptr : m_nintendoSwitchDeviceId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_nintendoSwitchDeviceId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResultWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResultWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResultWrapper(const PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResultWrapper(const PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResultWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResultWrapper(PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResultWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResultWrapper& operator=(PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResultWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResultWrapper& lhs, PFAccountManagementGetPlayFabIDsFromNintendoSwitchDeviceIdsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(ModelVector<PFAccountManagementNintendoSwitchPlayFabIdPairWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
    }

    ModelVector<PFAccountManagementNintendoSwitchPlayFabIdPairWrapper<Alloc>, Alloc> m_data;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequest& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequest, Alloc>{ model },
        m_issuerId{ model.issuerId ? StdExtra::optional<int32_t>{ *model.issuerId } : StdExtra::nullopt },
        m_PSNAccountIDs{ model.PSNAccountIDs, model.PSNAccountIDs + model.PSNAccountIDsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper(PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper& operator=(PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper& lhs, PFAccountManagementGetPlayFabIDsFromPSNAccountIDsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_issuerId, rhs.m_issuerId);
        swap(lhs.m_PSNAccountIDs, rhs.m_PSNAccountIDs);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetIssuerId(StdExtra::optional<int32_t> value)
    {
        m_issuerId = std::move(value);
        this->m_model.issuerId = m_issuerId ? m_issuerId.operator->() : nullptr;
    }

    void SetPSNAccountIDs(CStringVector<Alloc> value)
    {
        m_PSNAccountIDs = std::move(value);
        this->m_model.PSNAccountIDs =  m_PSNAccountIDs.empty() ? nullptr : m_PSNAccountIDs.data();
        this->m_model.PSNAccountIDsCount =  static_cast<uint32_t>(m_PSNAccountIDs.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.issuerId = m_issuerId ? m_issuerId.operator->() : nullptr;
        this->m_model.PSNAccountIDs = m_PSNAccountIDs.empty() ? nullptr : m_PSNAccountIDs.data();
    }

    StdExtra::optional<int32_t> m_issuerId;
    CStringVector<Alloc> m_PSNAccountIDs;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementPSNAccountPlayFabIdPairWrapper : public ModelWrapper<PFAccountManagementPSNAccountPlayFabIdPair, Alloc>
{
public:
    using ModelType = typename PFAccountManagementPSNAccountPlayFabIdPair;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementPSNAccountPlayFabIdPairWrapper() = default;

    PFAccountManagementPSNAccountPlayFabIdPairWrapper(const PFAccountManagementPSNAccountPlayFabIdPair& model) :
        ModelWrapper<PFAccountManagementPSNAccountPlayFabIdPair, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) },
        m_PSNAccountId{ SafeString(model.PSNAccountId) }
    {
        SetModelPointers();
    }

    PFAccountManagementPSNAccountPlayFabIdPairWrapper(const PFAccountManagementPSNAccountPlayFabIdPairWrapper& src) :
        PFAccountManagementPSNAccountPlayFabIdPairWrapper{ src.Model() }
    {
    }

    PFAccountManagementPSNAccountPlayFabIdPairWrapper(PFAccountManagementPSNAccountPlayFabIdPairWrapper&& src) :
        PFAccountManagementPSNAccountPlayFabIdPairWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementPSNAccountPlayFabIdPairWrapper& operator=(PFAccountManagementPSNAccountPlayFabIdPairWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementPSNAccountPlayFabIdPairWrapper() = default;

    friend void swap(PFAccountManagementPSNAccountPlayFabIdPairWrapper& lhs, PFAccountManagementPSNAccountPlayFabIdPairWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_PSNAccountId, rhs.m_PSNAccountId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetPSNAccountId(String value)
    {
        m_PSNAccountId = std::move(value);
        this->m_model.PSNAccountId =  m_PSNAccountId.empty() ? nullptr : m_PSNAccountId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.PSNAccountId = m_PSNAccountId.empty() ? nullptr : m_PSNAccountId.data();
    }

    String m_playFabId;
    String m_PSNAccountId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResultWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResultWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResultWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResultWrapper(PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResultWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResultWrapper& operator=(PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResultWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResultWrapper& lhs, PFAccountManagementGetPlayFabIDsFromPSNAccountIDsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(ModelVector<PFAccountManagementPSNAccountPlayFabIdPairWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
    }

    ModelVector<PFAccountManagementPSNAccountPlayFabIdPairWrapper<Alloc>, Alloc> m_data;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromSteamIDsRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromSteamIDsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromSteamIDsRequest& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromSteamIDsRequest, Alloc>{ model },
        m_steamStringIDs{ model.steamStringIDs, model.steamStringIDs + model.steamStringIDsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper(PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper& operator=(PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper& lhs, PFAccountManagementGetPlayFabIDsFromSteamIDsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_steamStringIDs, rhs.m_steamStringIDs);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSteamStringIDs(CStringVector<Alloc> value)
    {
        m_steamStringIDs = std::move(value);
        this->m_model.steamStringIDs =  m_steamStringIDs.empty() ? nullptr : m_steamStringIDs.data();
        this->m_model.steamStringIDsCount =  static_cast<uint32_t>(m_steamStringIDs.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.steamStringIDs = m_steamStringIDs.empty() ? nullptr : m_steamStringIDs.data();
    }

    CStringVector<Alloc> m_steamStringIDs;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementSteamPlayFabIdPairWrapper : public ModelWrapper<PFAccountManagementSteamPlayFabIdPair, Alloc>
{
public:
    using ModelType = typename PFAccountManagementSteamPlayFabIdPair;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementSteamPlayFabIdPairWrapper() = default;

    PFAccountManagementSteamPlayFabIdPairWrapper(const PFAccountManagementSteamPlayFabIdPair& model) :
        ModelWrapper<PFAccountManagementSteamPlayFabIdPair, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) },
        m_steamStringId{ SafeString(model.steamStringId) }
    {
        SetModelPointers();
    }

    PFAccountManagementSteamPlayFabIdPairWrapper(const PFAccountManagementSteamPlayFabIdPairWrapper& src) :
        PFAccountManagementSteamPlayFabIdPairWrapper{ src.Model() }
    {
    }

    PFAccountManagementSteamPlayFabIdPairWrapper(PFAccountManagementSteamPlayFabIdPairWrapper&& src) :
        PFAccountManagementSteamPlayFabIdPairWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementSteamPlayFabIdPairWrapper& operator=(PFAccountManagementSteamPlayFabIdPairWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementSteamPlayFabIdPairWrapper() = default;

    friend void swap(PFAccountManagementSteamPlayFabIdPairWrapper& lhs, PFAccountManagementSteamPlayFabIdPairWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_steamStringId, rhs.m_steamStringId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetSteamStringId(String value)
    {
        m_steamStringId = std::move(value);
        this->m_model.steamStringId =  m_steamStringId.empty() ? nullptr : m_steamStringId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.steamStringId = m_steamStringId.empty() ? nullptr : m_steamStringId.data();
    }

    String m_playFabId;
    String m_steamStringId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromSteamIDsResultWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromSteamIDsResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromSteamIDsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromSteamIDsResultWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromSteamIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromSteamIDsResult& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromSteamIDsResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromSteamIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromSteamIDsResultWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromSteamIDsResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromSteamIDsResultWrapper(PFAccountManagementGetPlayFabIDsFromSteamIDsResultWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromSteamIDsResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromSteamIDsResultWrapper& operator=(PFAccountManagementGetPlayFabIDsFromSteamIDsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromSteamIDsResultWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromSteamIDsResultWrapper& lhs, PFAccountManagementGetPlayFabIDsFromSteamIDsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(ModelVector<PFAccountManagementSteamPlayFabIdPairWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
    }

    ModelVector<PFAccountManagementSteamPlayFabIdPairWrapper<Alloc>, Alloc> m_data;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromTwitchIDsRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromTwitchIDsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromTwitchIDsRequest& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromTwitchIDsRequest, Alloc>{ model },
        m_twitchIds{ model.twitchIds, model.twitchIds + model.twitchIdsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper(PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper& operator=(PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper& lhs, PFAccountManagementGetPlayFabIDsFromTwitchIDsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_twitchIds, rhs.m_twitchIds);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTwitchIds(CStringVector<Alloc> value)
    {
        m_twitchIds = std::move(value);
        this->m_model.twitchIds =  m_twitchIds.empty() ? nullptr : m_twitchIds.data();
        this->m_model.twitchIdsCount =  static_cast<uint32_t>(m_twitchIds.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.twitchIds = m_twitchIds.empty() ? nullptr : m_twitchIds.data();
    }

    CStringVector<Alloc> m_twitchIds;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementTwitchPlayFabIdPairWrapper : public ModelWrapper<PFAccountManagementTwitchPlayFabIdPair, Alloc>
{
public:
    using ModelType = typename PFAccountManagementTwitchPlayFabIdPair;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementTwitchPlayFabIdPairWrapper() = default;

    PFAccountManagementTwitchPlayFabIdPairWrapper(const PFAccountManagementTwitchPlayFabIdPair& model) :
        ModelWrapper<PFAccountManagementTwitchPlayFabIdPair, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) },
        m_twitchId{ SafeString(model.twitchId) }
    {
        SetModelPointers();
    }

    PFAccountManagementTwitchPlayFabIdPairWrapper(const PFAccountManagementTwitchPlayFabIdPairWrapper& src) :
        PFAccountManagementTwitchPlayFabIdPairWrapper{ src.Model() }
    {
    }

    PFAccountManagementTwitchPlayFabIdPairWrapper(PFAccountManagementTwitchPlayFabIdPairWrapper&& src) :
        PFAccountManagementTwitchPlayFabIdPairWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementTwitchPlayFabIdPairWrapper& operator=(PFAccountManagementTwitchPlayFabIdPairWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementTwitchPlayFabIdPairWrapper() = default;

    friend void swap(PFAccountManagementTwitchPlayFabIdPairWrapper& lhs, PFAccountManagementTwitchPlayFabIdPairWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_twitchId, rhs.m_twitchId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetTwitchId(String value)
    {
        m_twitchId = std::move(value);
        this->m_model.twitchId =  m_twitchId.empty() ? nullptr : m_twitchId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.twitchId = m_twitchId.empty() ? nullptr : m_twitchId.data();
    }

    String m_playFabId;
    String m_twitchId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromTwitchIDsResultWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromTwitchIDsResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromTwitchIDsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromTwitchIDsResultWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromTwitchIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromTwitchIDsResult& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromTwitchIDsResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromTwitchIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromTwitchIDsResultWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromTwitchIDsResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromTwitchIDsResultWrapper(PFAccountManagementGetPlayFabIDsFromTwitchIDsResultWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromTwitchIDsResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromTwitchIDsResultWrapper& operator=(PFAccountManagementGetPlayFabIDsFromTwitchIDsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromTwitchIDsResultWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromTwitchIDsResultWrapper& lhs, PFAccountManagementGetPlayFabIDsFromTwitchIDsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(ModelVector<PFAccountManagementTwitchPlayFabIdPairWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
    }

    ModelVector<PFAccountManagementTwitchPlayFabIdPairWrapper<Alloc>, Alloc> m_data;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequest& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequest, Alloc>{ model },
        m_sandbox{ SafeString(model.sandbox) },
        m_xboxLiveAccountIDs{ model.xboxLiveAccountIDs, model.xboxLiveAccountIDs + model.xboxLiveAccountIDsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper(const PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper(PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper& operator=(PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper& lhs, PFAccountManagementGetPlayFabIDsFromXboxLiveIDsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_sandbox, rhs.m_sandbox);
        swap(lhs.m_xboxLiveAccountIDs, rhs.m_xboxLiveAccountIDs);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetSandbox(String value)
    {
        m_sandbox = std::move(value);
        this->m_model.sandbox =  m_sandbox.empty() ? nullptr : m_sandbox.data();
    }

    void SetXboxLiveAccountIDs(CStringVector<Alloc> value)
    {
        m_xboxLiveAccountIDs = std::move(value);
        this->m_model.xboxLiveAccountIDs =  m_xboxLiveAccountIDs.empty() ? nullptr : m_xboxLiveAccountIDs.data();
        this->m_model.xboxLiveAccountIDsCount =  static_cast<uint32_t>(m_xboxLiveAccountIDs.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.sandbox = m_sandbox.empty() ? nullptr : m_sandbox.data();
        this->m_model.xboxLiveAccountIDs = m_xboxLiveAccountIDs.empty() ? nullptr : m_xboxLiveAccountIDs.data();
    }

    String m_sandbox;
    CStringVector<Alloc> m_xboxLiveAccountIDs;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementXboxLiveAccountPlayFabIdPairWrapper : public ModelWrapper<PFAccountManagementXboxLiveAccountPlayFabIdPair, Alloc>
{
public:
    using ModelType = typename PFAccountManagementXboxLiveAccountPlayFabIdPair;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementXboxLiveAccountPlayFabIdPairWrapper() = default;

    PFAccountManagementXboxLiveAccountPlayFabIdPairWrapper(const PFAccountManagementXboxLiveAccountPlayFabIdPair& model) :
        ModelWrapper<PFAccountManagementXboxLiveAccountPlayFabIdPair, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) },
        m_xboxLiveAccountId{ SafeString(model.xboxLiveAccountId) }
    {
        SetModelPointers();
    }

    PFAccountManagementXboxLiveAccountPlayFabIdPairWrapper(const PFAccountManagementXboxLiveAccountPlayFabIdPairWrapper& src) :
        PFAccountManagementXboxLiveAccountPlayFabIdPairWrapper{ src.Model() }
    {
    }

    PFAccountManagementXboxLiveAccountPlayFabIdPairWrapper(PFAccountManagementXboxLiveAccountPlayFabIdPairWrapper&& src) :
        PFAccountManagementXboxLiveAccountPlayFabIdPairWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementXboxLiveAccountPlayFabIdPairWrapper& operator=(PFAccountManagementXboxLiveAccountPlayFabIdPairWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementXboxLiveAccountPlayFabIdPairWrapper() = default;

    friend void swap(PFAccountManagementXboxLiveAccountPlayFabIdPairWrapper& lhs, PFAccountManagementXboxLiveAccountPlayFabIdPairWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_xboxLiveAccountId, rhs.m_xboxLiveAccountId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetXboxLiveAccountId(String value)
    {
        m_xboxLiveAccountId = std::move(value);
        this->m_model.xboxLiveAccountId =  m_xboxLiveAccountId.empty() ? nullptr : m_xboxLiveAccountId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.xboxLiveAccountId = m_xboxLiveAccountId.empty() ? nullptr : m_xboxLiveAccountId.data();
    }

    String m_playFabId;
    String m_xboxLiveAccountId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResultWrapper : public ModelWrapper<PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResultWrapper() = default;

    PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult& model) :
        ModelWrapper<PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResultWrapper(const PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResultWrapper& src) :
        PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResultWrapper(PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResultWrapper&& src) :
        PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResultWrapper& operator=(PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResultWrapper() = default;

    friend void swap(PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResultWrapper& lhs, PFAccountManagementGetPlayFabIDsFromXboxLiveIDsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(ModelVector<PFAccountManagementXboxLiveAccountPlayFabIdPairWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
    }

    ModelVector<PFAccountManagementXboxLiveAccountPlayFabIdPairWrapper<Alloc>, Alloc> m_data;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLinkAndroidDeviceIDRequestWrapper : public ModelWrapper<PFAccountManagementLinkAndroidDeviceIDRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLinkAndroidDeviceIDRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLinkAndroidDeviceIDRequestWrapper() = default;

    PFAccountManagementLinkAndroidDeviceIDRequestWrapper(const PFAccountManagementLinkAndroidDeviceIDRequest& model) :
        ModelWrapper<PFAccountManagementLinkAndroidDeviceIDRequest, Alloc>{ model },
        m_androidDevice{ SafeString(model.androidDevice) },
        m_androidDeviceId{ SafeString(model.androidDeviceId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt },
        m_OS{ SafeString(model.OS) }
    {
        SetModelPointers();
    }

    PFAccountManagementLinkAndroidDeviceIDRequestWrapper(const PFAccountManagementLinkAndroidDeviceIDRequestWrapper& src) :
        PFAccountManagementLinkAndroidDeviceIDRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementLinkAndroidDeviceIDRequestWrapper(PFAccountManagementLinkAndroidDeviceIDRequestWrapper&& src) :
        PFAccountManagementLinkAndroidDeviceIDRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLinkAndroidDeviceIDRequestWrapper& operator=(PFAccountManagementLinkAndroidDeviceIDRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLinkAndroidDeviceIDRequestWrapper() = default;

    friend void swap(PFAccountManagementLinkAndroidDeviceIDRequestWrapper& lhs, PFAccountManagementLinkAndroidDeviceIDRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_androidDevice, rhs.m_androidDevice);
        swap(lhs.m_androidDeviceId, rhs.m_androidDeviceId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        swap(lhs.m_OS, rhs.m_OS);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAndroidDevice(String value)
    {
        m_androidDevice = std::move(value);
        this->m_model.androidDevice =  m_androidDevice.empty() ? nullptr : m_androidDevice.data();
    }

    void SetAndroidDeviceId(String value)
    {
        m_androidDeviceId = std::move(value);
        this->m_model.androidDeviceId =  m_androidDeviceId.empty() ? nullptr : m_androidDeviceId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    void SetOS(String value)
    {
        m_OS = std::move(value);
        this->m_model.OS =  m_OS.empty() ? nullptr : m_OS.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.androidDevice = m_androidDevice.empty() ? nullptr : m_androidDevice.data();
        this->m_model.androidDeviceId = m_androidDeviceId.empty() ? nullptr : m_androidDeviceId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
        this->m_model.OS = m_OS.empty() ? nullptr : m_OS.data();
    }

    String m_androidDevice;
    String m_androidDeviceId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceLink;
    String m_OS;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLinkAppleRequestWrapper : public ModelWrapper<PFAccountManagementLinkAppleRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLinkAppleRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLinkAppleRequestWrapper() = default;

    PFAccountManagementLinkAppleRequestWrapper(const PFAccountManagementLinkAppleRequest& model) :
        ModelWrapper<PFAccountManagementLinkAppleRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt },
        m_identityToken{ SafeString(model.identityToken) }
    {
        SetModelPointers();
    }

    PFAccountManagementLinkAppleRequestWrapper(const PFAccountManagementLinkAppleRequestWrapper& src) :
        PFAccountManagementLinkAppleRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementLinkAppleRequestWrapper(PFAccountManagementLinkAppleRequestWrapper&& src) :
        PFAccountManagementLinkAppleRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLinkAppleRequestWrapper& operator=(PFAccountManagementLinkAppleRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLinkAppleRequestWrapper() = default;

    friend void swap(PFAccountManagementLinkAppleRequestWrapper& lhs, PFAccountManagementLinkAppleRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        swap(lhs.m_identityToken, rhs.m_identityToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    void SetIdentityToken(String value)
    {
        m_identityToken = std::move(value);
        this->m_model.identityToken =  m_identityToken.empty() ? nullptr : m_identityToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
        this->m_model.identityToken = m_identityToken.empty() ? nullptr : m_identityToken.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceLink;
    String m_identityToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLinkCustomIDRequestWrapper : public ModelWrapper<PFAccountManagementLinkCustomIDRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLinkCustomIDRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLinkCustomIDRequestWrapper() = default;

    PFAccountManagementLinkCustomIDRequestWrapper(const PFAccountManagementLinkCustomIDRequest& model) :
        ModelWrapper<PFAccountManagementLinkCustomIDRequest, Alloc>{ model },
        m_customId{ SafeString(model.customId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAccountManagementLinkCustomIDRequestWrapper(const PFAccountManagementLinkCustomIDRequestWrapper& src) :
        PFAccountManagementLinkCustomIDRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementLinkCustomIDRequestWrapper(PFAccountManagementLinkCustomIDRequestWrapper&& src) :
        PFAccountManagementLinkCustomIDRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLinkCustomIDRequestWrapper& operator=(PFAccountManagementLinkCustomIDRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLinkCustomIDRequestWrapper() = default;

    friend void swap(PFAccountManagementLinkCustomIDRequestWrapper& lhs, PFAccountManagementLinkCustomIDRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customId, rhs.m_customId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomId(String value)
    {
        m_customId = std::move(value);
        this->m_model.customId =  m_customId.empty() ? nullptr : m_customId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customId = m_customId.empty() ? nullptr : m_customId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    String m_customId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceLink;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLinkFacebookAccountRequestWrapper : public ModelWrapper<PFAccountManagementLinkFacebookAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLinkFacebookAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLinkFacebookAccountRequestWrapper() = default;

    PFAccountManagementLinkFacebookAccountRequestWrapper(const PFAccountManagementLinkFacebookAccountRequest& model) :
        ModelWrapper<PFAccountManagementLinkFacebookAccountRequest, Alloc>{ model },
        m_accessToken{ SafeString(model.accessToken) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAccountManagementLinkFacebookAccountRequestWrapper(const PFAccountManagementLinkFacebookAccountRequestWrapper& src) :
        PFAccountManagementLinkFacebookAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementLinkFacebookAccountRequestWrapper(PFAccountManagementLinkFacebookAccountRequestWrapper&& src) :
        PFAccountManagementLinkFacebookAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLinkFacebookAccountRequestWrapper& operator=(PFAccountManagementLinkFacebookAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLinkFacebookAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementLinkFacebookAccountRequestWrapper& lhs, PFAccountManagementLinkFacebookAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_accessToken, rhs.m_accessToken);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAccessToken(String value)
    {
        m_accessToken = std::move(value);
        this->m_model.accessToken =  m_accessToken.empty() ? nullptr : m_accessToken.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.accessToken = m_accessToken.empty() ? nullptr : m_accessToken.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    String m_accessToken;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceLink;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper : public ModelWrapper<PFAccountManagementLinkFacebookInstantGamesIdRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLinkFacebookInstantGamesIdRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper() = default;

    PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper(const PFAccountManagementLinkFacebookInstantGamesIdRequest& model) :
        ModelWrapper<PFAccountManagementLinkFacebookInstantGamesIdRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_facebookInstantGamesSignature{ SafeString(model.facebookInstantGamesSignature) },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper(const PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper& src) :
        PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper(PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper&& src) :
        PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper& operator=(PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper() = default;

    friend void swap(PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper& lhs, PFAccountManagementLinkFacebookInstantGamesIdRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_facebookInstantGamesSignature, rhs.m_facebookInstantGamesSignature);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetFacebookInstantGamesSignature(String value)
    {
        m_facebookInstantGamesSignature = std::move(value);
        this->m_model.facebookInstantGamesSignature =  m_facebookInstantGamesSignature.empty() ? nullptr : m_facebookInstantGamesSignature.data();
    }

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.facebookInstantGamesSignature = m_facebookInstantGamesSignature.empty() ? nullptr : m_facebookInstantGamesSignature.data();
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_facebookInstantGamesSignature;
    StdExtra::optional<bool> m_forceLink;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLinkGameCenterAccountRequestWrapper : public ModelWrapper<PFAccountManagementLinkGameCenterAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLinkGameCenterAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLinkGameCenterAccountRequestWrapper() = default;

    PFAccountManagementLinkGameCenterAccountRequestWrapper(const PFAccountManagementLinkGameCenterAccountRequest& model) :
        ModelWrapper<PFAccountManagementLinkGameCenterAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt },
        m_gameCenterId{ SafeString(model.gameCenterId) },
        m_publicKeyUrl{ SafeString(model.publicKeyUrl) },
        m_salt{ SafeString(model.salt) },
        m_signature{ SafeString(model.signature) },
        m_timestamp{ SafeString(model.timestamp) }
    {
        SetModelPointers();
    }

    PFAccountManagementLinkGameCenterAccountRequestWrapper(const PFAccountManagementLinkGameCenterAccountRequestWrapper& src) :
        PFAccountManagementLinkGameCenterAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementLinkGameCenterAccountRequestWrapper(PFAccountManagementLinkGameCenterAccountRequestWrapper&& src) :
        PFAccountManagementLinkGameCenterAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLinkGameCenterAccountRequestWrapper& operator=(PFAccountManagementLinkGameCenterAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLinkGameCenterAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementLinkGameCenterAccountRequestWrapper& lhs, PFAccountManagementLinkGameCenterAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        swap(lhs.m_gameCenterId, rhs.m_gameCenterId);
        swap(lhs.m_publicKeyUrl, rhs.m_publicKeyUrl);
        swap(lhs.m_salt, rhs.m_salt);
        swap(lhs.m_signature, rhs.m_signature);
        swap(lhs.m_timestamp, rhs.m_timestamp);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    void SetGameCenterId(String value)
    {
        m_gameCenterId = std::move(value);
        this->m_model.gameCenterId =  m_gameCenterId.empty() ? nullptr : m_gameCenterId.data();
    }

    void SetPublicKeyUrl(String value)
    {
        m_publicKeyUrl = std::move(value);
        this->m_model.publicKeyUrl =  m_publicKeyUrl.empty() ? nullptr : m_publicKeyUrl.data();
    }

    void SetSalt(String value)
    {
        m_salt = std::move(value);
        this->m_model.salt =  m_salt.empty() ? nullptr : m_salt.data();
    }

    void SetSignature(String value)
    {
        m_signature = std::move(value);
        this->m_model.signature =  m_signature.empty() ? nullptr : m_signature.data();
    }

    void SetTimestamp(String value)
    {
        m_timestamp = std::move(value);
        this->m_model.timestamp =  m_timestamp.empty() ? nullptr : m_timestamp.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
        this->m_model.gameCenterId = m_gameCenterId.empty() ? nullptr : m_gameCenterId.data();
        this->m_model.publicKeyUrl = m_publicKeyUrl.empty() ? nullptr : m_publicKeyUrl.data();
        this->m_model.salt = m_salt.empty() ? nullptr : m_salt.data();
        this->m_model.signature = m_signature.empty() ? nullptr : m_signature.data();
        this->m_model.timestamp = m_timestamp.empty() ? nullptr : m_timestamp.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceLink;
    String m_gameCenterId;
    String m_publicKeyUrl;
    String m_salt;
    String m_signature;
    String m_timestamp;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLinkGoogleAccountRequestWrapper : public ModelWrapper<PFAccountManagementLinkGoogleAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLinkGoogleAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLinkGoogleAccountRequestWrapper() = default;

    PFAccountManagementLinkGoogleAccountRequestWrapper(const PFAccountManagementLinkGoogleAccountRequest& model) :
        ModelWrapper<PFAccountManagementLinkGoogleAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt },
        m_serverAuthCode{ SafeString(model.serverAuthCode) }
    {
        SetModelPointers();
    }

    PFAccountManagementLinkGoogleAccountRequestWrapper(const PFAccountManagementLinkGoogleAccountRequestWrapper& src) :
        PFAccountManagementLinkGoogleAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementLinkGoogleAccountRequestWrapper(PFAccountManagementLinkGoogleAccountRequestWrapper&& src) :
        PFAccountManagementLinkGoogleAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLinkGoogleAccountRequestWrapper& operator=(PFAccountManagementLinkGoogleAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLinkGoogleAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementLinkGoogleAccountRequestWrapper& lhs, PFAccountManagementLinkGoogleAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        swap(lhs.m_serverAuthCode, rhs.m_serverAuthCode);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    void SetServerAuthCode(String value)
    {
        m_serverAuthCode = std::move(value);
        this->m_model.serverAuthCode =  m_serverAuthCode.empty() ? nullptr : m_serverAuthCode.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
        this->m_model.serverAuthCode = m_serverAuthCode.empty() ? nullptr : m_serverAuthCode.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceLink;
    String m_serverAuthCode;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLinkIOSDeviceIDRequestWrapper : public ModelWrapper<PFAccountManagementLinkIOSDeviceIDRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLinkIOSDeviceIDRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLinkIOSDeviceIDRequestWrapper() = default;

    PFAccountManagementLinkIOSDeviceIDRequestWrapper(const PFAccountManagementLinkIOSDeviceIDRequest& model) :
        ModelWrapper<PFAccountManagementLinkIOSDeviceIDRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_deviceId{ SafeString(model.deviceId) },
        m_deviceModel{ SafeString(model.deviceModel) },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt },
        m_OS{ SafeString(model.OS) }
    {
        SetModelPointers();
    }

    PFAccountManagementLinkIOSDeviceIDRequestWrapper(const PFAccountManagementLinkIOSDeviceIDRequestWrapper& src) :
        PFAccountManagementLinkIOSDeviceIDRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementLinkIOSDeviceIDRequestWrapper(PFAccountManagementLinkIOSDeviceIDRequestWrapper&& src) :
        PFAccountManagementLinkIOSDeviceIDRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLinkIOSDeviceIDRequestWrapper& operator=(PFAccountManagementLinkIOSDeviceIDRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLinkIOSDeviceIDRequestWrapper() = default;

    friend void swap(PFAccountManagementLinkIOSDeviceIDRequestWrapper& lhs, PFAccountManagementLinkIOSDeviceIDRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_deviceId, rhs.m_deviceId);
        swap(lhs.m_deviceModel, rhs.m_deviceModel);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        swap(lhs.m_OS, rhs.m_OS);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetDeviceId(String value)
    {
        m_deviceId = std::move(value);
        this->m_model.deviceId =  m_deviceId.empty() ? nullptr : m_deviceId.data();
    }

    void SetDeviceModel(String value)
    {
        m_deviceModel = std::move(value);
        this->m_model.deviceModel =  m_deviceModel.empty() ? nullptr : m_deviceModel.data();
    }

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    void SetOS(String value)
    {
        m_OS = std::move(value);
        this->m_model.OS =  m_OS.empty() ? nullptr : m_OS.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.deviceId = m_deviceId.empty() ? nullptr : m_deviceId.data();
        this->m_model.deviceModel = m_deviceModel.empty() ? nullptr : m_deviceModel.data();
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
        this->m_model.OS = m_OS.empty() ? nullptr : m_OS.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_deviceId;
    String m_deviceModel;
    StdExtra::optional<bool> m_forceLink;
    String m_OS;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLinkKongregateAccountRequestWrapper : public ModelWrapper<PFAccountManagementLinkKongregateAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLinkKongregateAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLinkKongregateAccountRequestWrapper() = default;

    PFAccountManagementLinkKongregateAccountRequestWrapper(const PFAccountManagementLinkKongregateAccountRequest& model) :
        ModelWrapper<PFAccountManagementLinkKongregateAccountRequest, Alloc>{ model },
        m_authTicket{ SafeString(model.authTicket) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt },
        m_kongregateId{ SafeString(model.kongregateId) }
    {
        SetModelPointers();
    }

    PFAccountManagementLinkKongregateAccountRequestWrapper(const PFAccountManagementLinkKongregateAccountRequestWrapper& src) :
        PFAccountManagementLinkKongregateAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementLinkKongregateAccountRequestWrapper(PFAccountManagementLinkKongregateAccountRequestWrapper&& src) :
        PFAccountManagementLinkKongregateAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLinkKongregateAccountRequestWrapper& operator=(PFAccountManagementLinkKongregateAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLinkKongregateAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementLinkKongregateAccountRequestWrapper& lhs, PFAccountManagementLinkKongregateAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_authTicket, rhs.m_authTicket);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        swap(lhs.m_kongregateId, rhs.m_kongregateId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAuthTicket(String value)
    {
        m_authTicket = std::move(value);
        this->m_model.authTicket =  m_authTicket.empty() ? nullptr : m_authTicket.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    void SetKongregateId(String value)
    {
        m_kongregateId = std::move(value);
        this->m_model.kongregateId =  m_kongregateId.empty() ? nullptr : m_kongregateId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.authTicket = m_authTicket.empty() ? nullptr : m_authTicket.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
        this->m_model.kongregateId = m_kongregateId.empty() ? nullptr : m_kongregateId.data();
    }

    String m_authTicket;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceLink;
    String m_kongregateId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLinkNintendoServiceAccountRequestWrapper : public ModelWrapper<PFAccountManagementLinkNintendoServiceAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLinkNintendoServiceAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLinkNintendoServiceAccountRequestWrapper() = default;

    PFAccountManagementLinkNintendoServiceAccountRequestWrapper(const PFAccountManagementLinkNintendoServiceAccountRequest& model) :
        ModelWrapper<PFAccountManagementLinkNintendoServiceAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt },
        m_identityToken{ SafeString(model.identityToken) }
    {
        SetModelPointers();
    }

    PFAccountManagementLinkNintendoServiceAccountRequestWrapper(const PFAccountManagementLinkNintendoServiceAccountRequestWrapper& src) :
        PFAccountManagementLinkNintendoServiceAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementLinkNintendoServiceAccountRequestWrapper(PFAccountManagementLinkNintendoServiceAccountRequestWrapper&& src) :
        PFAccountManagementLinkNintendoServiceAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLinkNintendoServiceAccountRequestWrapper& operator=(PFAccountManagementLinkNintendoServiceAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLinkNintendoServiceAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementLinkNintendoServiceAccountRequestWrapper& lhs, PFAccountManagementLinkNintendoServiceAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        swap(lhs.m_identityToken, rhs.m_identityToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    void SetIdentityToken(String value)
    {
        m_identityToken = std::move(value);
        this->m_model.identityToken =  m_identityToken.empty() ? nullptr : m_identityToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
        this->m_model.identityToken = m_identityToken.empty() ? nullptr : m_identityToken.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceLink;
    String m_identityToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLinkNintendoSwitchDeviceIdRequestWrapper : public ModelWrapper<PFAccountManagementLinkNintendoSwitchDeviceIdRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLinkNintendoSwitchDeviceIdRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLinkNintendoSwitchDeviceIdRequestWrapper() = default;

    PFAccountManagementLinkNintendoSwitchDeviceIdRequestWrapper(const PFAccountManagementLinkNintendoSwitchDeviceIdRequest& model) :
        ModelWrapper<PFAccountManagementLinkNintendoSwitchDeviceIdRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt },
        m_nintendoSwitchDeviceId{ SafeString(model.nintendoSwitchDeviceId) }
    {
        SetModelPointers();
    }

    PFAccountManagementLinkNintendoSwitchDeviceIdRequestWrapper(const PFAccountManagementLinkNintendoSwitchDeviceIdRequestWrapper& src) :
        PFAccountManagementLinkNintendoSwitchDeviceIdRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementLinkNintendoSwitchDeviceIdRequestWrapper(PFAccountManagementLinkNintendoSwitchDeviceIdRequestWrapper&& src) :
        PFAccountManagementLinkNintendoSwitchDeviceIdRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLinkNintendoSwitchDeviceIdRequestWrapper& operator=(PFAccountManagementLinkNintendoSwitchDeviceIdRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLinkNintendoSwitchDeviceIdRequestWrapper() = default;

    friend void swap(PFAccountManagementLinkNintendoSwitchDeviceIdRequestWrapper& lhs, PFAccountManagementLinkNintendoSwitchDeviceIdRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        swap(lhs.m_nintendoSwitchDeviceId, rhs.m_nintendoSwitchDeviceId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    void SetNintendoSwitchDeviceId(String value)
    {
        m_nintendoSwitchDeviceId = std::move(value);
        this->m_model.nintendoSwitchDeviceId =  m_nintendoSwitchDeviceId.empty() ? nullptr : m_nintendoSwitchDeviceId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
        this->m_model.nintendoSwitchDeviceId = m_nintendoSwitchDeviceId.empty() ? nullptr : m_nintendoSwitchDeviceId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceLink;
    String m_nintendoSwitchDeviceId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLinkOpenIdConnectRequestWrapper : public ModelWrapper<PFAccountManagementLinkOpenIdConnectRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLinkOpenIdConnectRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLinkOpenIdConnectRequestWrapper() = default;

    PFAccountManagementLinkOpenIdConnectRequestWrapper(const PFAccountManagementLinkOpenIdConnectRequest& model) :
        ModelWrapper<PFAccountManagementLinkOpenIdConnectRequest, Alloc>{ model },
        m_connectionId{ SafeString(model.connectionId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt },
        m_idToken{ SafeString(model.idToken) }
    {
        SetModelPointers();
    }

    PFAccountManagementLinkOpenIdConnectRequestWrapper(const PFAccountManagementLinkOpenIdConnectRequestWrapper& src) :
        PFAccountManagementLinkOpenIdConnectRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementLinkOpenIdConnectRequestWrapper(PFAccountManagementLinkOpenIdConnectRequestWrapper&& src) :
        PFAccountManagementLinkOpenIdConnectRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLinkOpenIdConnectRequestWrapper& operator=(PFAccountManagementLinkOpenIdConnectRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLinkOpenIdConnectRequestWrapper() = default;

    friend void swap(PFAccountManagementLinkOpenIdConnectRequestWrapper& lhs, PFAccountManagementLinkOpenIdConnectRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_connectionId, rhs.m_connectionId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        swap(lhs.m_idToken, rhs.m_idToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConnectionId(String value)
    {
        m_connectionId = std::move(value);
        this->m_model.connectionId =  m_connectionId.empty() ? nullptr : m_connectionId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    void SetIdToken(String value)
    {
        m_idToken = std::move(value);
        this->m_model.idToken =  m_idToken.empty() ? nullptr : m_idToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.connectionId = m_connectionId.empty() ? nullptr : m_connectionId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
        this->m_model.idToken = m_idToken.empty() ? nullptr : m_idToken.data();
    }

    String m_connectionId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceLink;
    String m_idToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementClientLinkPSNAccountRequestWrapper : public ModelWrapper<PFAccountManagementClientLinkPSNAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementClientLinkPSNAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementClientLinkPSNAccountRequestWrapper() = default;

    PFAccountManagementClientLinkPSNAccountRequestWrapper(const PFAccountManagementClientLinkPSNAccountRequest& model) :
        ModelWrapper<PFAccountManagementClientLinkPSNAccountRequest, Alloc>{ model },
        m_authCode{ SafeString(model.authCode) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt },
        m_issuerId{ model.issuerId ? StdExtra::optional<int32_t>{ *model.issuerId } : StdExtra::nullopt },
        m_redirectUri{ SafeString(model.redirectUri) }
    {
        SetModelPointers();
    }

    PFAccountManagementClientLinkPSNAccountRequestWrapper(const PFAccountManagementClientLinkPSNAccountRequestWrapper& src) :
        PFAccountManagementClientLinkPSNAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementClientLinkPSNAccountRequestWrapper(PFAccountManagementClientLinkPSNAccountRequestWrapper&& src) :
        PFAccountManagementClientLinkPSNAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementClientLinkPSNAccountRequestWrapper& operator=(PFAccountManagementClientLinkPSNAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementClientLinkPSNAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementClientLinkPSNAccountRequestWrapper& lhs, PFAccountManagementClientLinkPSNAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_authCode, rhs.m_authCode);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        swap(lhs.m_issuerId, rhs.m_issuerId);
        swap(lhs.m_redirectUri, rhs.m_redirectUri);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAuthCode(String value)
    {
        m_authCode = std::move(value);
        this->m_model.authCode =  m_authCode.empty() ? nullptr : m_authCode.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    void SetIssuerId(StdExtra::optional<int32_t> value)
    {
        m_issuerId = std::move(value);
        this->m_model.issuerId = m_issuerId ? m_issuerId.operator->() : nullptr;
    }

    void SetRedirectUri(String value)
    {
        m_redirectUri = std::move(value);
        this->m_model.redirectUri =  m_redirectUri.empty() ? nullptr : m_redirectUri.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.authCode = m_authCode.empty() ? nullptr : m_authCode.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
        this->m_model.issuerId = m_issuerId ? m_issuerId.operator->() : nullptr;
        this->m_model.redirectUri = m_redirectUri.empty() ? nullptr : m_redirectUri.data();
    }

    String m_authCode;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceLink;
    StdExtra::optional<int32_t> m_issuerId;
    String m_redirectUri;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLinkSteamAccountRequestWrapper : public ModelWrapper<PFAccountManagementLinkSteamAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLinkSteamAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLinkSteamAccountRequestWrapper() = default;

    PFAccountManagementLinkSteamAccountRequestWrapper(const PFAccountManagementLinkSteamAccountRequest& model) :
        ModelWrapper<PFAccountManagementLinkSteamAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt },
        m_steamTicket{ SafeString(model.steamTicket) }
    {
        SetModelPointers();
    }

    PFAccountManagementLinkSteamAccountRequestWrapper(const PFAccountManagementLinkSteamAccountRequestWrapper& src) :
        PFAccountManagementLinkSteamAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementLinkSteamAccountRequestWrapper(PFAccountManagementLinkSteamAccountRequestWrapper&& src) :
        PFAccountManagementLinkSteamAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLinkSteamAccountRequestWrapper& operator=(PFAccountManagementLinkSteamAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLinkSteamAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementLinkSteamAccountRequestWrapper& lhs, PFAccountManagementLinkSteamAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        swap(lhs.m_steamTicket, rhs.m_steamTicket);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    void SetSteamTicket(String value)
    {
        m_steamTicket = std::move(value);
        this->m_model.steamTicket =  m_steamTicket.empty() ? nullptr : m_steamTicket.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
        this->m_model.steamTicket = m_steamTicket.empty() ? nullptr : m_steamTicket.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceLink;
    String m_steamTicket;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLinkTwitchAccountRequestWrapper : public ModelWrapper<PFAccountManagementLinkTwitchAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLinkTwitchAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLinkTwitchAccountRequestWrapper() = default;

    PFAccountManagementLinkTwitchAccountRequestWrapper(const PFAccountManagementLinkTwitchAccountRequest& model) :
        ModelWrapper<PFAccountManagementLinkTwitchAccountRequest, Alloc>{ model },
        m_accessToken{ SafeString(model.accessToken) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAccountManagementLinkTwitchAccountRequestWrapper(const PFAccountManagementLinkTwitchAccountRequestWrapper& src) :
        PFAccountManagementLinkTwitchAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementLinkTwitchAccountRequestWrapper(PFAccountManagementLinkTwitchAccountRequestWrapper&& src) :
        PFAccountManagementLinkTwitchAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLinkTwitchAccountRequestWrapper& operator=(PFAccountManagementLinkTwitchAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLinkTwitchAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementLinkTwitchAccountRequestWrapper& lhs, PFAccountManagementLinkTwitchAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_accessToken, rhs.m_accessToken);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAccessToken(String value)
    {
        m_accessToken = std::move(value);
        this->m_model.accessToken =  m_accessToken.empty() ? nullptr : m_accessToken.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.accessToken = m_accessToken.empty() ? nullptr : m_accessToken.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    String m_accessToken;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceLink;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementClientLinkXboxAccountRequestWrapper : public ModelWrapper<PFAccountManagementClientLinkXboxAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementClientLinkXboxAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementClientLinkXboxAccountRequestWrapper() = default;

    PFAccountManagementClientLinkXboxAccountRequestWrapper(const PFAccountManagementClientLinkXboxAccountRequest& model) :
        ModelWrapper<PFAccountManagementClientLinkXboxAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt },
        m_xboxToken{ SafeString(model.xboxToken) }
    {
        SetModelPointers();
    }

    PFAccountManagementClientLinkXboxAccountRequestWrapper(const PFAccountManagementClientLinkXboxAccountRequestWrapper& src) :
        PFAccountManagementClientLinkXboxAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementClientLinkXboxAccountRequestWrapper(PFAccountManagementClientLinkXboxAccountRequestWrapper&& src) :
        PFAccountManagementClientLinkXboxAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementClientLinkXboxAccountRequestWrapper& operator=(PFAccountManagementClientLinkXboxAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementClientLinkXboxAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementClientLinkXboxAccountRequestWrapper& lhs, PFAccountManagementClientLinkXboxAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceLink, rhs.m_forceLink);
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

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
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
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
        this->m_model.xboxToken = m_xboxToken.empty() ? nullptr : m_xboxToken.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceLink;
    String m_xboxToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementRemoveContactEmailRequestWrapper : public ModelWrapper<PFAccountManagementRemoveContactEmailRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementRemoveContactEmailRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementRemoveContactEmailRequestWrapper() = default;

    PFAccountManagementRemoveContactEmailRequestWrapper(const PFAccountManagementRemoveContactEmailRequest& model) :
        ModelWrapper<PFAccountManagementRemoveContactEmailRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementRemoveContactEmailRequestWrapper(const PFAccountManagementRemoveContactEmailRequestWrapper& src) :
        PFAccountManagementRemoveContactEmailRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementRemoveContactEmailRequestWrapper(PFAccountManagementRemoveContactEmailRequestWrapper&& src) :
        PFAccountManagementRemoveContactEmailRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementRemoveContactEmailRequestWrapper& operator=(PFAccountManagementRemoveContactEmailRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementRemoveContactEmailRequestWrapper() = default;

    friend void swap(PFAccountManagementRemoveContactEmailRequestWrapper& lhs, PFAccountManagementRemoveContactEmailRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementClientRemoveGenericIDRequestWrapper : public ModelWrapper<PFAccountManagementClientRemoveGenericIDRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementClientRemoveGenericIDRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementClientRemoveGenericIDRequestWrapper() = default;

    PFAccountManagementClientRemoveGenericIDRequestWrapper(const PFAccountManagementClientRemoveGenericIDRequest& model) :
        ModelWrapper<PFAccountManagementClientRemoveGenericIDRequest, Alloc>{ model },
        m_genericId{ model.genericId ? *model.genericId : decltype(*model.genericId){} }
    {
        SetModelPointers();
    }

    PFAccountManagementClientRemoveGenericIDRequestWrapper(const PFAccountManagementClientRemoveGenericIDRequestWrapper& src) :
        PFAccountManagementClientRemoveGenericIDRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementClientRemoveGenericIDRequestWrapper(PFAccountManagementClientRemoveGenericIDRequestWrapper&& src) :
        PFAccountManagementClientRemoveGenericIDRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementClientRemoveGenericIDRequestWrapper& operator=(PFAccountManagementClientRemoveGenericIDRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementClientRemoveGenericIDRequestWrapper() = default;

    friend void swap(PFAccountManagementClientRemoveGenericIDRequestWrapper& lhs, PFAccountManagementClientRemoveGenericIDRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_genericId, rhs.m_genericId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGenericId(PFAccountManagementGenericServiceIdWrapper<Alloc> value)
    {
        m_genericId = std::move(value);
        this->m_model.genericId = &m_genericId.Model();
    }

private:
    void SetModelPointers()
    {
        this->m_model.genericId = &m_genericId.Model();
    }

    PFAccountManagementGenericServiceIdWrapper<Alloc> m_genericId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementReportPlayerClientRequestWrapper : public ModelWrapper<PFAccountManagementReportPlayerClientRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementReportPlayerClientRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementReportPlayerClientRequestWrapper() = default;

    PFAccountManagementReportPlayerClientRequestWrapper(const PFAccountManagementReportPlayerClientRequest& model) :
        ModelWrapper<PFAccountManagementReportPlayerClientRequest, Alloc>{ model },
        m_comment{ SafeString(model.comment) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_reporteeId{ SafeString(model.reporteeId) }
    {
        SetModelPointers();
    }

    PFAccountManagementReportPlayerClientRequestWrapper(const PFAccountManagementReportPlayerClientRequestWrapper& src) :
        PFAccountManagementReportPlayerClientRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementReportPlayerClientRequestWrapper(PFAccountManagementReportPlayerClientRequestWrapper&& src) :
        PFAccountManagementReportPlayerClientRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementReportPlayerClientRequestWrapper& operator=(PFAccountManagementReportPlayerClientRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementReportPlayerClientRequestWrapper() = default;

    friend void swap(PFAccountManagementReportPlayerClientRequestWrapper& lhs, PFAccountManagementReportPlayerClientRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_comment, rhs.m_comment);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_reporteeId, rhs.m_reporteeId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetComment(String value)
    {
        m_comment = std::move(value);
        this->m_model.comment =  m_comment.empty() ? nullptr : m_comment.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetReporteeId(String value)
    {
        m_reporteeId = std::move(value);
        this->m_model.reporteeId =  m_reporteeId.empty() ? nullptr : m_reporteeId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.comment = m_comment.empty() ? nullptr : m_comment.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.reporteeId = m_reporteeId.empty() ? nullptr : m_reporteeId.data();
    }

    String m_comment;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_reporteeId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementReportPlayerClientResultWrapper : public ModelWrapper<PFAccountManagementReportPlayerClientResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementReportPlayerClientResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    using ModelWrapper<PFAccountManagementReportPlayerClientResult, Alloc>::ModelWrapper;

    void SetSubmissionsRemaining(int32_t value)
    {
        this->m_model.submissionsRemaining = value;
    }

private:
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper : public ModelWrapper<PFAccountManagementClientSendAccountRecoveryEmailRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementClientSendAccountRecoveryEmailRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper() = default;

    PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper(const PFAccountManagementClientSendAccountRecoveryEmailRequest& model) :
        ModelWrapper<PFAccountManagementClientSendAccountRecoveryEmailRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_email{ SafeString(model.email) },
        m_emailTemplateId{ SafeString(model.emailTemplateId) },
        m_titleId{ SafeString(model.titleId) }
    {
        SetModelPointers();
    }

    PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper(const PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper& src) :
        PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper(PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper&& src) :
        PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper& operator=(PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper() = default;

    friend void swap(PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper& lhs, PFAccountManagementClientSendAccountRecoveryEmailRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_email, rhs.m_email);
        swap(lhs.m_emailTemplateId, rhs.m_emailTemplateId);
        swap(lhs.m_titleId, rhs.m_titleId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEmail(String value)
    {
        m_email = std::move(value);
        this->m_model.email =  m_email.empty() ? nullptr : m_email.data();
    }

    void SetEmailTemplateId(String value)
    {
        m_emailTemplateId = std::move(value);
        this->m_model.emailTemplateId =  m_emailTemplateId.empty() ? nullptr : m_emailTemplateId.data();
    }

    void SetTitleId(String value)
    {
        m_titleId = std::move(value);
        this->m_model.titleId =  m_titleId.empty() ? nullptr : m_titleId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.email = m_email.empty() ? nullptr : m_email.data();
        this->m_model.emailTemplateId = m_emailTemplateId.empty() ? nullptr : m_emailTemplateId.data();
        this->m_model.titleId = m_titleId.empty() ? nullptr : m_titleId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_email;
    String m_emailTemplateId;
    String m_titleId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper : public ModelWrapper<PFAccountManagementUnlinkAndroidDeviceIDRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUnlinkAndroidDeviceIDRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper() = default;

    PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper(const PFAccountManagementUnlinkAndroidDeviceIDRequest& model) :
        ModelWrapper<PFAccountManagementUnlinkAndroidDeviceIDRequest, Alloc>{ model },
        m_androidDeviceId{ SafeString(model.androidDeviceId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper(const PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper& src) :
        PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper(PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper&& src) :
        PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper& operator=(PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper() = default;

    friend void swap(PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper& lhs, PFAccountManagementUnlinkAndroidDeviceIDRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_androidDeviceId, rhs.m_androidDeviceId);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAndroidDeviceId(String value)
    {
        m_androidDeviceId = std::move(value);
        this->m_model.androidDeviceId =  m_androidDeviceId.empty() ? nullptr : m_androidDeviceId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.androidDeviceId = m_androidDeviceId.empty() ? nullptr : m_androidDeviceId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_androidDeviceId;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUnlinkAppleRequestWrapper : public ModelWrapper<PFAccountManagementUnlinkAppleRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUnlinkAppleRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUnlinkAppleRequestWrapper() = default;

    PFAccountManagementUnlinkAppleRequestWrapper(const PFAccountManagementUnlinkAppleRequest& model) :
        ModelWrapper<PFAccountManagementUnlinkAppleRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementUnlinkAppleRequestWrapper(const PFAccountManagementUnlinkAppleRequestWrapper& src) :
        PFAccountManagementUnlinkAppleRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementUnlinkAppleRequestWrapper(PFAccountManagementUnlinkAppleRequestWrapper&& src) :
        PFAccountManagementUnlinkAppleRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUnlinkAppleRequestWrapper& operator=(PFAccountManagementUnlinkAppleRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUnlinkAppleRequestWrapper() = default;

    friend void swap(PFAccountManagementUnlinkAppleRequestWrapper& lhs, PFAccountManagementUnlinkAppleRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUnlinkCustomIDRequestWrapper : public ModelWrapper<PFAccountManagementUnlinkCustomIDRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUnlinkCustomIDRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUnlinkCustomIDRequestWrapper() = default;

    PFAccountManagementUnlinkCustomIDRequestWrapper(const PFAccountManagementUnlinkCustomIDRequest& model) :
        ModelWrapper<PFAccountManagementUnlinkCustomIDRequest, Alloc>{ model },
        m_customId{ SafeString(model.customId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementUnlinkCustomIDRequestWrapper(const PFAccountManagementUnlinkCustomIDRequestWrapper& src) :
        PFAccountManagementUnlinkCustomIDRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementUnlinkCustomIDRequestWrapper(PFAccountManagementUnlinkCustomIDRequestWrapper&& src) :
        PFAccountManagementUnlinkCustomIDRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUnlinkCustomIDRequestWrapper& operator=(PFAccountManagementUnlinkCustomIDRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUnlinkCustomIDRequestWrapper() = default;

    friend void swap(PFAccountManagementUnlinkCustomIDRequestWrapper& lhs, PFAccountManagementUnlinkCustomIDRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customId, rhs.m_customId);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomId(String value)
    {
        m_customId = std::move(value);
        this->m_model.customId =  m_customId.empty() ? nullptr : m_customId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customId = m_customId.empty() ? nullptr : m_customId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_customId;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUnlinkFacebookAccountRequestWrapper : public ModelWrapper<PFAccountManagementUnlinkFacebookAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUnlinkFacebookAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUnlinkFacebookAccountRequestWrapper() = default;

    PFAccountManagementUnlinkFacebookAccountRequestWrapper(const PFAccountManagementUnlinkFacebookAccountRequest& model) :
        ModelWrapper<PFAccountManagementUnlinkFacebookAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementUnlinkFacebookAccountRequestWrapper(const PFAccountManagementUnlinkFacebookAccountRequestWrapper& src) :
        PFAccountManagementUnlinkFacebookAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementUnlinkFacebookAccountRequestWrapper(PFAccountManagementUnlinkFacebookAccountRequestWrapper&& src) :
        PFAccountManagementUnlinkFacebookAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUnlinkFacebookAccountRequestWrapper& operator=(PFAccountManagementUnlinkFacebookAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUnlinkFacebookAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementUnlinkFacebookAccountRequestWrapper& lhs, PFAccountManagementUnlinkFacebookAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper : public ModelWrapper<PFAccountManagementUnlinkFacebookInstantGamesIdRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUnlinkFacebookInstantGamesIdRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper() = default;

    PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper(const PFAccountManagementUnlinkFacebookInstantGamesIdRequest& model) :
        ModelWrapper<PFAccountManagementUnlinkFacebookInstantGamesIdRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_facebookInstantGamesId{ SafeString(model.facebookInstantGamesId) }
    {
        SetModelPointers();
    }

    PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper(const PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper& src) :
        PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper(PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper&& src) :
        PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper& operator=(PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper() = default;

    friend void swap(PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper& lhs, PFAccountManagementUnlinkFacebookInstantGamesIdRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_facebookInstantGamesId, rhs.m_facebookInstantGamesId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetFacebookInstantGamesId(String value)
    {
        m_facebookInstantGamesId = std::move(value);
        this->m_model.facebookInstantGamesId =  m_facebookInstantGamesId.empty() ? nullptr : m_facebookInstantGamesId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.facebookInstantGamesId = m_facebookInstantGamesId.empty() ? nullptr : m_facebookInstantGamesId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_facebookInstantGamesId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUnlinkGameCenterAccountRequestWrapper : public ModelWrapper<PFAccountManagementUnlinkGameCenterAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUnlinkGameCenterAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUnlinkGameCenterAccountRequestWrapper() = default;

    PFAccountManagementUnlinkGameCenterAccountRequestWrapper(const PFAccountManagementUnlinkGameCenterAccountRequest& model) :
        ModelWrapper<PFAccountManagementUnlinkGameCenterAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementUnlinkGameCenterAccountRequestWrapper(const PFAccountManagementUnlinkGameCenterAccountRequestWrapper& src) :
        PFAccountManagementUnlinkGameCenterAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementUnlinkGameCenterAccountRequestWrapper(PFAccountManagementUnlinkGameCenterAccountRequestWrapper&& src) :
        PFAccountManagementUnlinkGameCenterAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUnlinkGameCenterAccountRequestWrapper& operator=(PFAccountManagementUnlinkGameCenterAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUnlinkGameCenterAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementUnlinkGameCenterAccountRequestWrapper& lhs, PFAccountManagementUnlinkGameCenterAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUnlinkGoogleAccountRequestWrapper : public ModelWrapper<PFAccountManagementUnlinkGoogleAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUnlinkGoogleAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUnlinkGoogleAccountRequestWrapper() = default;

    PFAccountManagementUnlinkGoogleAccountRequestWrapper(const PFAccountManagementUnlinkGoogleAccountRequest& model) :
        ModelWrapper<PFAccountManagementUnlinkGoogleAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementUnlinkGoogleAccountRequestWrapper(const PFAccountManagementUnlinkGoogleAccountRequestWrapper& src) :
        PFAccountManagementUnlinkGoogleAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementUnlinkGoogleAccountRequestWrapper(PFAccountManagementUnlinkGoogleAccountRequestWrapper&& src) :
        PFAccountManagementUnlinkGoogleAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUnlinkGoogleAccountRequestWrapper& operator=(PFAccountManagementUnlinkGoogleAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUnlinkGoogleAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementUnlinkGoogleAccountRequestWrapper& lhs, PFAccountManagementUnlinkGoogleAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUnlinkIOSDeviceIDRequestWrapper : public ModelWrapper<PFAccountManagementUnlinkIOSDeviceIDRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUnlinkIOSDeviceIDRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUnlinkIOSDeviceIDRequestWrapper() = default;

    PFAccountManagementUnlinkIOSDeviceIDRequestWrapper(const PFAccountManagementUnlinkIOSDeviceIDRequest& model) :
        ModelWrapper<PFAccountManagementUnlinkIOSDeviceIDRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_deviceId{ SafeString(model.deviceId) }
    {
        SetModelPointers();
    }

    PFAccountManagementUnlinkIOSDeviceIDRequestWrapper(const PFAccountManagementUnlinkIOSDeviceIDRequestWrapper& src) :
        PFAccountManagementUnlinkIOSDeviceIDRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementUnlinkIOSDeviceIDRequestWrapper(PFAccountManagementUnlinkIOSDeviceIDRequestWrapper&& src) :
        PFAccountManagementUnlinkIOSDeviceIDRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUnlinkIOSDeviceIDRequestWrapper& operator=(PFAccountManagementUnlinkIOSDeviceIDRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUnlinkIOSDeviceIDRequestWrapper() = default;

    friend void swap(PFAccountManagementUnlinkIOSDeviceIDRequestWrapper& lhs, PFAccountManagementUnlinkIOSDeviceIDRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_deviceId, rhs.m_deviceId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetDeviceId(String value)
    {
        m_deviceId = std::move(value);
        this->m_model.deviceId =  m_deviceId.empty() ? nullptr : m_deviceId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.deviceId = m_deviceId.empty() ? nullptr : m_deviceId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_deviceId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUnlinkKongregateAccountRequestWrapper : public ModelWrapper<PFAccountManagementUnlinkKongregateAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUnlinkKongregateAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUnlinkKongregateAccountRequestWrapper() = default;

    PFAccountManagementUnlinkKongregateAccountRequestWrapper(const PFAccountManagementUnlinkKongregateAccountRequest& model) :
        ModelWrapper<PFAccountManagementUnlinkKongregateAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementUnlinkKongregateAccountRequestWrapper(const PFAccountManagementUnlinkKongregateAccountRequestWrapper& src) :
        PFAccountManagementUnlinkKongregateAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementUnlinkKongregateAccountRequestWrapper(PFAccountManagementUnlinkKongregateAccountRequestWrapper&& src) :
        PFAccountManagementUnlinkKongregateAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUnlinkKongregateAccountRequestWrapper& operator=(PFAccountManagementUnlinkKongregateAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUnlinkKongregateAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementUnlinkKongregateAccountRequestWrapper& lhs, PFAccountManagementUnlinkKongregateAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUnlinkNintendoServiceAccountRequestWrapper : public ModelWrapper<PFAccountManagementUnlinkNintendoServiceAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUnlinkNintendoServiceAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUnlinkNintendoServiceAccountRequestWrapper() = default;

    PFAccountManagementUnlinkNintendoServiceAccountRequestWrapper(const PFAccountManagementUnlinkNintendoServiceAccountRequest& model) :
        ModelWrapper<PFAccountManagementUnlinkNintendoServiceAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementUnlinkNintendoServiceAccountRequestWrapper(const PFAccountManagementUnlinkNintendoServiceAccountRequestWrapper& src) :
        PFAccountManagementUnlinkNintendoServiceAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementUnlinkNintendoServiceAccountRequestWrapper(PFAccountManagementUnlinkNintendoServiceAccountRequestWrapper&& src) :
        PFAccountManagementUnlinkNintendoServiceAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUnlinkNintendoServiceAccountRequestWrapper& operator=(PFAccountManagementUnlinkNintendoServiceAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUnlinkNintendoServiceAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementUnlinkNintendoServiceAccountRequestWrapper& lhs, PFAccountManagementUnlinkNintendoServiceAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUnlinkNintendoSwitchDeviceIdRequestWrapper : public ModelWrapper<PFAccountManagementUnlinkNintendoSwitchDeviceIdRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUnlinkNintendoSwitchDeviceIdRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUnlinkNintendoSwitchDeviceIdRequestWrapper() = default;

    PFAccountManagementUnlinkNintendoSwitchDeviceIdRequestWrapper(const PFAccountManagementUnlinkNintendoSwitchDeviceIdRequest& model) :
        ModelWrapper<PFAccountManagementUnlinkNintendoSwitchDeviceIdRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_nintendoSwitchDeviceId{ SafeString(model.nintendoSwitchDeviceId) }
    {
        SetModelPointers();
    }

    PFAccountManagementUnlinkNintendoSwitchDeviceIdRequestWrapper(const PFAccountManagementUnlinkNintendoSwitchDeviceIdRequestWrapper& src) :
        PFAccountManagementUnlinkNintendoSwitchDeviceIdRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementUnlinkNintendoSwitchDeviceIdRequestWrapper(PFAccountManagementUnlinkNintendoSwitchDeviceIdRequestWrapper&& src) :
        PFAccountManagementUnlinkNintendoSwitchDeviceIdRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUnlinkNintendoSwitchDeviceIdRequestWrapper& operator=(PFAccountManagementUnlinkNintendoSwitchDeviceIdRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUnlinkNintendoSwitchDeviceIdRequestWrapper() = default;

    friend void swap(PFAccountManagementUnlinkNintendoSwitchDeviceIdRequestWrapper& lhs, PFAccountManagementUnlinkNintendoSwitchDeviceIdRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_nintendoSwitchDeviceId, rhs.m_nintendoSwitchDeviceId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetNintendoSwitchDeviceId(String value)
    {
        m_nintendoSwitchDeviceId = std::move(value);
        this->m_model.nintendoSwitchDeviceId =  m_nintendoSwitchDeviceId.empty() ? nullptr : m_nintendoSwitchDeviceId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.nintendoSwitchDeviceId = m_nintendoSwitchDeviceId.empty() ? nullptr : m_nintendoSwitchDeviceId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_nintendoSwitchDeviceId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUnlinkOpenIdConnectRequestWrapper : public ModelWrapper<PFAccountManagementUnlinkOpenIdConnectRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUnlinkOpenIdConnectRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUnlinkOpenIdConnectRequestWrapper() = default;

    PFAccountManagementUnlinkOpenIdConnectRequestWrapper(const PFAccountManagementUnlinkOpenIdConnectRequest& model) :
        ModelWrapper<PFAccountManagementUnlinkOpenIdConnectRequest, Alloc>{ model },
        m_connectionId{ SafeString(model.connectionId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementUnlinkOpenIdConnectRequestWrapper(const PFAccountManagementUnlinkOpenIdConnectRequestWrapper& src) :
        PFAccountManagementUnlinkOpenIdConnectRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementUnlinkOpenIdConnectRequestWrapper(PFAccountManagementUnlinkOpenIdConnectRequestWrapper&& src) :
        PFAccountManagementUnlinkOpenIdConnectRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUnlinkOpenIdConnectRequestWrapper& operator=(PFAccountManagementUnlinkOpenIdConnectRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUnlinkOpenIdConnectRequestWrapper() = default;

    friend void swap(PFAccountManagementUnlinkOpenIdConnectRequestWrapper& lhs, PFAccountManagementUnlinkOpenIdConnectRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_connectionId, rhs.m_connectionId);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetConnectionId(String value)
    {
        m_connectionId = std::move(value);
        this->m_model.connectionId =  m_connectionId.empty() ? nullptr : m_connectionId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.connectionId = m_connectionId.empty() ? nullptr : m_connectionId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_connectionId;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementClientUnlinkPSNAccountRequestWrapper : public ModelWrapper<PFAccountManagementClientUnlinkPSNAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementClientUnlinkPSNAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementClientUnlinkPSNAccountRequestWrapper() = default;

    PFAccountManagementClientUnlinkPSNAccountRequestWrapper(const PFAccountManagementClientUnlinkPSNAccountRequest& model) :
        ModelWrapper<PFAccountManagementClientUnlinkPSNAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementClientUnlinkPSNAccountRequestWrapper(const PFAccountManagementClientUnlinkPSNAccountRequestWrapper& src) :
        PFAccountManagementClientUnlinkPSNAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementClientUnlinkPSNAccountRequestWrapper(PFAccountManagementClientUnlinkPSNAccountRequestWrapper&& src) :
        PFAccountManagementClientUnlinkPSNAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementClientUnlinkPSNAccountRequestWrapper& operator=(PFAccountManagementClientUnlinkPSNAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementClientUnlinkPSNAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementClientUnlinkPSNAccountRequestWrapper& lhs, PFAccountManagementClientUnlinkPSNAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUnlinkSteamAccountRequestWrapper : public ModelWrapper<PFAccountManagementUnlinkSteamAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUnlinkSteamAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUnlinkSteamAccountRequestWrapper() = default;

    PFAccountManagementUnlinkSteamAccountRequestWrapper(const PFAccountManagementUnlinkSteamAccountRequest& model) :
        ModelWrapper<PFAccountManagementUnlinkSteamAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementUnlinkSteamAccountRequestWrapper(const PFAccountManagementUnlinkSteamAccountRequestWrapper& src) :
        PFAccountManagementUnlinkSteamAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementUnlinkSteamAccountRequestWrapper(PFAccountManagementUnlinkSteamAccountRequestWrapper&& src) :
        PFAccountManagementUnlinkSteamAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUnlinkSteamAccountRequestWrapper& operator=(PFAccountManagementUnlinkSteamAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUnlinkSteamAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementUnlinkSteamAccountRequestWrapper& lhs, PFAccountManagementUnlinkSteamAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUnlinkTwitchAccountRequestWrapper : public ModelWrapper<PFAccountManagementUnlinkTwitchAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUnlinkTwitchAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUnlinkTwitchAccountRequestWrapper() = default;

    PFAccountManagementUnlinkTwitchAccountRequestWrapper(const PFAccountManagementUnlinkTwitchAccountRequest& model) :
        ModelWrapper<PFAccountManagementUnlinkTwitchAccountRequest, Alloc>{ model },
        m_accessToken{ SafeString(model.accessToken) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementUnlinkTwitchAccountRequestWrapper(const PFAccountManagementUnlinkTwitchAccountRequestWrapper& src) :
        PFAccountManagementUnlinkTwitchAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementUnlinkTwitchAccountRequestWrapper(PFAccountManagementUnlinkTwitchAccountRequestWrapper&& src) :
        PFAccountManagementUnlinkTwitchAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUnlinkTwitchAccountRequestWrapper& operator=(PFAccountManagementUnlinkTwitchAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUnlinkTwitchAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementUnlinkTwitchAccountRequestWrapper& lhs, PFAccountManagementUnlinkTwitchAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_accessToken, rhs.m_accessToken);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAccessToken(String value)
    {
        m_accessToken = std::move(value);
        this->m_model.accessToken =  m_accessToken.empty() ? nullptr : m_accessToken.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.accessToken = m_accessToken.empty() ? nullptr : m_accessToken.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_accessToken;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementClientUnlinkXboxAccountRequestWrapper : public ModelWrapper<PFAccountManagementClientUnlinkXboxAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementClientUnlinkXboxAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementClientUnlinkXboxAccountRequestWrapper() = default;

    PFAccountManagementClientUnlinkXboxAccountRequestWrapper(const PFAccountManagementClientUnlinkXboxAccountRequest& model) :
        ModelWrapper<PFAccountManagementClientUnlinkXboxAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementClientUnlinkXboxAccountRequestWrapper(const PFAccountManagementClientUnlinkXboxAccountRequestWrapper& src) :
        PFAccountManagementClientUnlinkXboxAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementClientUnlinkXboxAccountRequestWrapper(PFAccountManagementClientUnlinkXboxAccountRequestWrapper&& src) :
        PFAccountManagementClientUnlinkXboxAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementClientUnlinkXboxAccountRequestWrapper& operator=(PFAccountManagementClientUnlinkXboxAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementClientUnlinkXboxAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementClientUnlinkXboxAccountRequestWrapper& lhs, PFAccountManagementClientUnlinkXboxAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementClientUpdateAvatarUrlRequestWrapper : public ModelWrapper<PFAccountManagementClientUpdateAvatarUrlRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementClientUpdateAvatarUrlRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementClientUpdateAvatarUrlRequestWrapper() = default;

    PFAccountManagementClientUpdateAvatarUrlRequestWrapper(const PFAccountManagementClientUpdateAvatarUrlRequest& model) :
        ModelWrapper<PFAccountManagementClientUpdateAvatarUrlRequest, Alloc>{ model },
        m_imageUrl{ SafeString(model.imageUrl) }
    {
        SetModelPointers();
    }

    PFAccountManagementClientUpdateAvatarUrlRequestWrapper(const PFAccountManagementClientUpdateAvatarUrlRequestWrapper& src) :
        PFAccountManagementClientUpdateAvatarUrlRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementClientUpdateAvatarUrlRequestWrapper(PFAccountManagementClientUpdateAvatarUrlRequestWrapper&& src) :
        PFAccountManagementClientUpdateAvatarUrlRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementClientUpdateAvatarUrlRequestWrapper& operator=(PFAccountManagementClientUpdateAvatarUrlRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementClientUpdateAvatarUrlRequestWrapper() = default;

    friend void swap(PFAccountManagementClientUpdateAvatarUrlRequestWrapper& lhs, PFAccountManagementClientUpdateAvatarUrlRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_imageUrl, rhs.m_imageUrl);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetImageUrl(String value)
    {
        m_imageUrl = std::move(value);
        this->m_model.imageUrl =  m_imageUrl.empty() ? nullptr : m_imageUrl.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.imageUrl = m_imageUrl.empty() ? nullptr : m_imageUrl.data();
    }

    String m_imageUrl;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper : public ModelWrapper<PFAccountManagementClientUpdateUserTitleDisplayNameRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementClientUpdateUserTitleDisplayNameRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper() = default;

    PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper(const PFAccountManagementClientUpdateUserTitleDisplayNameRequest& model) :
        ModelWrapper<PFAccountManagementClientUpdateUserTitleDisplayNameRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_displayName{ SafeString(model.displayName) }
    {
        SetModelPointers();
    }

    PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper(const PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper& src) :
        PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper(PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper&& src) :
        PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper& operator=(PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper() = default;

    friend void swap(PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper& lhs, PFAccountManagementClientUpdateUserTitleDisplayNameRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_displayName, rhs.m_displayName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetDisplayName(String value)
    {
        m_displayName = std::move(value);
        this->m_model.displayName =  m_displayName.empty() ? nullptr : m_displayName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.displayName = m_displayName.empty() ? nullptr : m_displayName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_displayName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementServerAddGenericIDRequestWrapper : public ModelWrapper<PFAccountManagementServerAddGenericIDRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementServerAddGenericIDRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementServerAddGenericIDRequestWrapper() = default;

    PFAccountManagementServerAddGenericIDRequestWrapper(const PFAccountManagementServerAddGenericIDRequest& model) :
        ModelWrapper<PFAccountManagementServerAddGenericIDRequest, Alloc>{ model },
        m_genericId{ model.genericId ? *model.genericId : decltype(*model.genericId){} },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementServerAddGenericIDRequestWrapper(const PFAccountManagementServerAddGenericIDRequestWrapper& src) :
        PFAccountManagementServerAddGenericIDRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementServerAddGenericIDRequestWrapper(PFAccountManagementServerAddGenericIDRequestWrapper&& src) :
        PFAccountManagementServerAddGenericIDRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementServerAddGenericIDRequestWrapper& operator=(PFAccountManagementServerAddGenericIDRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementServerAddGenericIDRequestWrapper() = default;

    friend void swap(PFAccountManagementServerAddGenericIDRequestWrapper& lhs, PFAccountManagementServerAddGenericIDRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_genericId, rhs.m_genericId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGenericId(PFAccountManagementGenericServiceIdWrapper<Alloc> value)
    {
        m_genericId = std::move(value);
        this->m_model.genericId = &m_genericId.Model();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.genericId = &m_genericId.Model();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    PFAccountManagementGenericServiceIdWrapper<Alloc> m_genericId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementDeletePushNotificationTemplateRequestWrapper : public ModelWrapper<PFAccountManagementDeletePushNotificationTemplateRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementDeletePushNotificationTemplateRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementDeletePushNotificationTemplateRequestWrapper() = default;

    PFAccountManagementDeletePushNotificationTemplateRequestWrapper(const PFAccountManagementDeletePushNotificationTemplateRequest& model) :
        ModelWrapper<PFAccountManagementDeletePushNotificationTemplateRequest, Alloc>{ model },
        m_pushNotificationTemplateId{ SafeString(model.pushNotificationTemplateId) }
    {
        SetModelPointers();
    }

    PFAccountManagementDeletePushNotificationTemplateRequestWrapper(const PFAccountManagementDeletePushNotificationTemplateRequestWrapper& src) :
        PFAccountManagementDeletePushNotificationTemplateRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementDeletePushNotificationTemplateRequestWrapper(PFAccountManagementDeletePushNotificationTemplateRequestWrapper&& src) :
        PFAccountManagementDeletePushNotificationTemplateRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementDeletePushNotificationTemplateRequestWrapper& operator=(PFAccountManagementDeletePushNotificationTemplateRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementDeletePushNotificationTemplateRequestWrapper() = default;

    friend void swap(PFAccountManagementDeletePushNotificationTemplateRequestWrapper& lhs, PFAccountManagementDeletePushNotificationTemplateRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_pushNotificationTemplateId, rhs.m_pushNotificationTemplateId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPushNotificationTemplateId(String value)
    {
        m_pushNotificationTemplateId = std::move(value);
        this->m_model.pushNotificationTemplateId =  m_pushNotificationTemplateId.empty() ? nullptr : m_pushNotificationTemplateId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.pushNotificationTemplateId = m_pushNotificationTemplateId.empty() ? nullptr : m_pushNotificationTemplateId.data();
    }

    String m_pushNotificationTemplateId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper : public ModelWrapper<PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper() = default;

    PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper(const PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequest& model) :
        ModelWrapper<PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequest, Alloc>{ model },
        m_playFabIDs{ model.playFabIDs, model.playFabIDs + model.playFabIDsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper(const PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper& src) :
        PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper(PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper&& src) :
        PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper& operator=(PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper() = default;

    friend void swap(PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper& lhs, PFAccountManagementGetServerCustomIDsFromPlayFabIDsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabIDs, rhs.m_playFabIDs);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabIDs(CStringVector<Alloc> value)
    {
        m_playFabIDs = std::move(value);
        this->m_model.playFabIDs =  m_playFabIDs.empty() ? nullptr : m_playFabIDs.data();
        this->m_model.playFabIDsCount =  static_cast<uint32_t>(m_playFabIDs.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabIDs = m_playFabIDs.empty() ? nullptr : m_playFabIDs.data();
    }

    CStringVector<Alloc> m_playFabIDs;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementServerCustomIDPlayFabIDPairWrapper : public ModelWrapper<PFAccountManagementServerCustomIDPlayFabIDPair, Alloc>
{
public:
    using ModelType = typename PFAccountManagementServerCustomIDPlayFabIDPair;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementServerCustomIDPlayFabIDPairWrapper() = default;

    PFAccountManagementServerCustomIDPlayFabIDPairWrapper(const PFAccountManagementServerCustomIDPlayFabIDPair& model) :
        ModelWrapper<PFAccountManagementServerCustomIDPlayFabIDPair, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) },
        m_serverCustomId{ SafeString(model.serverCustomId) }
    {
        SetModelPointers();
    }

    PFAccountManagementServerCustomIDPlayFabIDPairWrapper(const PFAccountManagementServerCustomIDPlayFabIDPairWrapper& src) :
        PFAccountManagementServerCustomIDPlayFabIDPairWrapper{ src.Model() }
    {
    }

    PFAccountManagementServerCustomIDPlayFabIDPairWrapper(PFAccountManagementServerCustomIDPlayFabIDPairWrapper&& src) :
        PFAccountManagementServerCustomIDPlayFabIDPairWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementServerCustomIDPlayFabIDPairWrapper& operator=(PFAccountManagementServerCustomIDPlayFabIDPairWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementServerCustomIDPlayFabIDPairWrapper() = default;

    friend void swap(PFAccountManagementServerCustomIDPlayFabIDPairWrapper& lhs, PFAccountManagementServerCustomIDPlayFabIDPairWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_serverCustomId, rhs.m_serverCustomId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetServerCustomId(String value)
    {
        m_serverCustomId = std::move(value);
        this->m_model.serverCustomId =  m_serverCustomId.empty() ? nullptr : m_serverCustomId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.serverCustomId = m_serverCustomId.empty() ? nullptr : m_serverCustomId.data();
    }

    String m_playFabId;
    String m_serverCustomId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetServerCustomIDsFromPlayFabIDsResultWrapper : public ModelWrapper<PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetServerCustomIDsFromPlayFabIDsResultWrapper() = default;

    PFAccountManagementGetServerCustomIDsFromPlayFabIDsResultWrapper(const PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult& model) :
        ModelWrapper<PFAccountManagementGetServerCustomIDsFromPlayFabIDsResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount }
    {
        SetModelPointers();
    }

    PFAccountManagementGetServerCustomIDsFromPlayFabIDsResultWrapper(const PFAccountManagementGetServerCustomIDsFromPlayFabIDsResultWrapper& src) :
        PFAccountManagementGetServerCustomIDsFromPlayFabIDsResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetServerCustomIDsFromPlayFabIDsResultWrapper(PFAccountManagementGetServerCustomIDsFromPlayFabIDsResultWrapper&& src) :
        PFAccountManagementGetServerCustomIDsFromPlayFabIDsResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetServerCustomIDsFromPlayFabIDsResultWrapper& operator=(PFAccountManagementGetServerCustomIDsFromPlayFabIDsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetServerCustomIDsFromPlayFabIDsResultWrapper() = default;

    friend void swap(PFAccountManagementGetServerCustomIDsFromPlayFabIDsResultWrapper& lhs, PFAccountManagementGetServerCustomIDsFromPlayFabIDsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(ModelVector<PFAccountManagementServerCustomIDPlayFabIDPairWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
    }

    ModelVector<PFAccountManagementServerCustomIDPlayFabIDPairWrapper<Alloc>, Alloc> m_data;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetUserAccountInfoRequestWrapper : public ModelWrapper<PFAccountManagementGetUserAccountInfoRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetUserAccountInfoRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetUserAccountInfoRequestWrapper() = default;

    PFAccountManagementGetUserAccountInfoRequestWrapper(const PFAccountManagementGetUserAccountInfoRequest& model) :
        ModelWrapper<PFAccountManagementGetUserAccountInfoRequest, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementGetUserAccountInfoRequestWrapper(const PFAccountManagementGetUserAccountInfoRequestWrapper& src) :
        PFAccountManagementGetUserAccountInfoRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetUserAccountInfoRequestWrapper(PFAccountManagementGetUserAccountInfoRequestWrapper&& src) :
        PFAccountManagementGetUserAccountInfoRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetUserAccountInfoRequestWrapper& operator=(PFAccountManagementGetUserAccountInfoRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetUserAccountInfoRequestWrapper() = default;

    friend void swap(PFAccountManagementGetUserAccountInfoRequestWrapper& lhs, PFAccountManagementGetUserAccountInfoRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementGetUserAccountInfoResultWrapper : public ModelWrapper<PFAccountManagementGetUserAccountInfoResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementGetUserAccountInfoResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementGetUserAccountInfoResultWrapper() = default;

    PFAccountManagementGetUserAccountInfoResultWrapper(const PFAccountManagementGetUserAccountInfoResult& model) :
        ModelWrapper<PFAccountManagementGetUserAccountInfoResult, Alloc>{ model },
        m_userInfo{ model.userInfo ? StdExtra::optional<PFUserAccountInfoWrapper<Alloc>>{ *model.userInfo } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAccountManagementGetUserAccountInfoResultWrapper(const PFAccountManagementGetUserAccountInfoResultWrapper& src) :
        PFAccountManagementGetUserAccountInfoResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementGetUserAccountInfoResultWrapper(PFAccountManagementGetUserAccountInfoResultWrapper&& src) :
        PFAccountManagementGetUserAccountInfoResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementGetUserAccountInfoResultWrapper& operator=(PFAccountManagementGetUserAccountInfoResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementGetUserAccountInfoResultWrapper() = default;

    friend void swap(PFAccountManagementGetUserAccountInfoResultWrapper& lhs, PFAccountManagementGetUserAccountInfoResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_userInfo, rhs.m_userInfo);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetUserInfo(StdExtra::optional<PFUserAccountInfoWrapper<Alloc>> value)
    {
        m_userInfo = std::move(value);
        this->m_model.userInfo = m_userInfo ? &m_userInfo->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.userInfo = m_userInfo ?  &m_userInfo->Model() : nullptr;
    }

    StdExtra::optional<PFUserAccountInfoWrapper<Alloc>> m_userInfo;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementServerLinkPSNAccountRequestWrapper : public ModelWrapper<PFAccountManagementServerLinkPSNAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementServerLinkPSNAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementServerLinkPSNAccountRequestWrapper() = default;

    PFAccountManagementServerLinkPSNAccountRequestWrapper(const PFAccountManagementServerLinkPSNAccountRequest& model) :
        ModelWrapper<PFAccountManagementServerLinkPSNAccountRequest, Alloc>{ model },
        m_authCode{ SafeString(model.authCode) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt },
        m_issuerId{ model.issuerId ? StdExtra::optional<int32_t>{ *model.issuerId } : StdExtra::nullopt },
        m_playFabId{ SafeString(model.playFabId) },
        m_redirectUri{ SafeString(model.redirectUri) }
    {
        SetModelPointers();
    }

    PFAccountManagementServerLinkPSNAccountRequestWrapper(const PFAccountManagementServerLinkPSNAccountRequestWrapper& src) :
        PFAccountManagementServerLinkPSNAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementServerLinkPSNAccountRequestWrapper(PFAccountManagementServerLinkPSNAccountRequestWrapper&& src) :
        PFAccountManagementServerLinkPSNAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementServerLinkPSNAccountRequestWrapper& operator=(PFAccountManagementServerLinkPSNAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementServerLinkPSNAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementServerLinkPSNAccountRequestWrapper& lhs, PFAccountManagementServerLinkPSNAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_authCode, rhs.m_authCode);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        swap(lhs.m_issuerId, rhs.m_issuerId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_redirectUri, rhs.m_redirectUri);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAuthCode(String value)
    {
        m_authCode = std::move(value);
        this->m_model.authCode =  m_authCode.empty() ? nullptr : m_authCode.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    void SetIssuerId(StdExtra::optional<int32_t> value)
    {
        m_issuerId = std::move(value);
        this->m_model.issuerId = m_issuerId ? m_issuerId.operator->() : nullptr;
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetRedirectUri(String value)
    {
        m_redirectUri = std::move(value);
        this->m_model.redirectUri =  m_redirectUri.empty() ? nullptr : m_redirectUri.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.authCode = m_authCode.empty() ? nullptr : m_authCode.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
        this->m_model.issuerId = m_issuerId ? m_issuerId.operator->() : nullptr;
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.redirectUri = m_redirectUri.empty() ? nullptr : m_redirectUri.data();
    }

    String m_authCode;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceLink;
    StdExtra::optional<int32_t> m_issuerId;
    String m_playFabId;
    String m_redirectUri;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLinkServerCustomIdRequestWrapper : public ModelWrapper<PFAccountManagementLinkServerCustomIdRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLinkServerCustomIdRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLinkServerCustomIdRequestWrapper() = default;

    PFAccountManagementLinkServerCustomIdRequestWrapper(const PFAccountManagementLinkServerCustomIdRequest& model) :
        ModelWrapper<PFAccountManagementLinkServerCustomIdRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt },
        m_playFabId{ SafeString(model.playFabId) },
        m_serverCustomId{ SafeString(model.serverCustomId) }
    {
        SetModelPointers();
    }

    PFAccountManagementLinkServerCustomIdRequestWrapper(const PFAccountManagementLinkServerCustomIdRequestWrapper& src) :
        PFAccountManagementLinkServerCustomIdRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementLinkServerCustomIdRequestWrapper(PFAccountManagementLinkServerCustomIdRequestWrapper&& src) :
        PFAccountManagementLinkServerCustomIdRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLinkServerCustomIdRequestWrapper& operator=(PFAccountManagementLinkServerCustomIdRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLinkServerCustomIdRequestWrapper() = default;

    friend void swap(PFAccountManagementLinkServerCustomIdRequestWrapper& lhs, PFAccountManagementLinkServerCustomIdRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_serverCustomId, rhs.m_serverCustomId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetServerCustomId(String value)
    {
        m_serverCustomId = std::move(value);
        this->m_model.serverCustomId =  m_serverCustomId.empty() ? nullptr : m_serverCustomId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.serverCustomId = m_serverCustomId.empty() ? nullptr : m_serverCustomId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceLink;
    String m_playFabId;
    String m_serverCustomId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementServerLinkXboxAccountRequestWrapper : public ModelWrapper<PFAccountManagementServerLinkXboxAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementServerLinkXboxAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementServerLinkXboxAccountRequestWrapper() = default;

    PFAccountManagementServerLinkXboxAccountRequestWrapper(const PFAccountManagementServerLinkXboxAccountRequest& model) :
        ModelWrapper<PFAccountManagementServerLinkXboxAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceLink{ model.forceLink ? StdExtra::optional<bool>{ *model.forceLink } : StdExtra::nullopt },
        m_playFabId{ SafeString(model.playFabId) },
        m_xboxToken{ SafeString(model.xboxToken) }
    {
        SetModelPointers();
    }

    PFAccountManagementServerLinkXboxAccountRequestWrapper(const PFAccountManagementServerLinkXboxAccountRequestWrapper& src) :
        PFAccountManagementServerLinkXboxAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementServerLinkXboxAccountRequestWrapper(PFAccountManagementServerLinkXboxAccountRequestWrapper&& src) :
        PFAccountManagementServerLinkXboxAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementServerLinkXboxAccountRequestWrapper& operator=(PFAccountManagementServerLinkXboxAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementServerLinkXboxAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementServerLinkXboxAccountRequestWrapper& lhs, PFAccountManagementServerLinkXboxAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceLink, rhs.m_forceLink);
        swap(lhs.m_playFabId, rhs.m_playFabId);
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

    void SetForceLink(StdExtra::optional<bool> value)
    {
        m_forceLink = std::move(value);
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
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
        this->m_model.forceLink = m_forceLink ? m_forceLink.operator->() : nullptr;
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.xboxToken = m_xboxToken.empty() ? nullptr : m_xboxToken.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceLink;
    String m_playFabId;
    String m_xboxToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementServerRemoveGenericIDRequestWrapper : public ModelWrapper<PFAccountManagementServerRemoveGenericIDRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementServerRemoveGenericIDRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementServerRemoveGenericIDRequestWrapper() = default;

    PFAccountManagementServerRemoveGenericIDRequestWrapper(const PFAccountManagementServerRemoveGenericIDRequest& model) :
        ModelWrapper<PFAccountManagementServerRemoveGenericIDRequest, Alloc>{ model },
        m_genericId{ model.genericId ? *model.genericId : decltype(*model.genericId){} },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementServerRemoveGenericIDRequestWrapper(const PFAccountManagementServerRemoveGenericIDRequestWrapper& src) :
        PFAccountManagementServerRemoveGenericIDRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementServerRemoveGenericIDRequestWrapper(PFAccountManagementServerRemoveGenericIDRequestWrapper&& src) :
        PFAccountManagementServerRemoveGenericIDRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementServerRemoveGenericIDRequestWrapper& operator=(PFAccountManagementServerRemoveGenericIDRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementServerRemoveGenericIDRequestWrapper() = default;

    friend void swap(PFAccountManagementServerRemoveGenericIDRequestWrapper& lhs, PFAccountManagementServerRemoveGenericIDRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_genericId, rhs.m_genericId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGenericId(PFAccountManagementGenericServiceIdWrapper<Alloc> value)
    {
        m_genericId = std::move(value);
        this->m_model.genericId = &m_genericId.Model();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.genericId = &m_genericId.Model();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    PFAccountManagementGenericServiceIdWrapper<Alloc> m_genericId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementLocalizedPushNotificationPropertiesWrapper : public ModelWrapper<PFAccountManagementLocalizedPushNotificationProperties, Alloc>
{
public:
    using ModelType = typename PFAccountManagementLocalizedPushNotificationProperties;
    using DictionaryEntryType = typename PFAccountManagementLocalizedPushNotificationPropertiesDictionaryEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementLocalizedPushNotificationPropertiesWrapper() = default;

    PFAccountManagementLocalizedPushNotificationPropertiesWrapper(const PFAccountManagementLocalizedPushNotificationProperties& model) :
        ModelWrapper<PFAccountManagementLocalizedPushNotificationProperties, Alloc>{ model },
        m_message{ SafeString(model.message) },
        m_subject{ SafeString(model.subject) }
    {
        SetModelPointers();
    }

    PFAccountManagementLocalizedPushNotificationPropertiesWrapper(const PFAccountManagementLocalizedPushNotificationPropertiesWrapper& src) :
        PFAccountManagementLocalizedPushNotificationPropertiesWrapper{ src.Model() }
    {
    }

    PFAccountManagementLocalizedPushNotificationPropertiesWrapper(PFAccountManagementLocalizedPushNotificationPropertiesWrapper&& src) :
        PFAccountManagementLocalizedPushNotificationPropertiesWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementLocalizedPushNotificationPropertiesWrapper& operator=(PFAccountManagementLocalizedPushNotificationPropertiesWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementLocalizedPushNotificationPropertiesWrapper() = default;

    friend void swap(PFAccountManagementLocalizedPushNotificationPropertiesWrapper& lhs, PFAccountManagementLocalizedPushNotificationPropertiesWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_message, rhs.m_message);
        swap(lhs.m_subject, rhs.m_subject);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetMessage(String value)
    {
        m_message = std::move(value);
        this->m_model.message =  m_message.empty() ? nullptr : m_message.data();
    }

    void SetSubject(String value)
    {
        m_subject = std::move(value);
        this->m_model.subject =  m_subject.empty() ? nullptr : m_subject.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.message = m_message.empty() ? nullptr : m_message.data();
        this->m_model.subject = m_subject.empty() ? nullptr : m_subject.data();
    }

    String m_message;
    String m_subject;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementSavePushNotificationTemplateRequestWrapper : public ModelWrapper<PFAccountManagementSavePushNotificationTemplateRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementSavePushNotificationTemplateRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementSavePushNotificationTemplateRequestWrapper() = default;

    PFAccountManagementSavePushNotificationTemplateRequestWrapper(const PFAccountManagementSavePushNotificationTemplateRequest& model) :
        ModelWrapper<PFAccountManagementSavePushNotificationTemplateRequest, Alloc>{ model },
        m_androidPayload{ SafeString(model.androidPayload) },
        m_id{ SafeString(model.id) },
        m_iOSPayload{ SafeString(model.iOSPayload) },
        m_localizedPushNotificationTemplates{ model.localizedPushNotificationTemplates, model.localizedPushNotificationTemplates + model.localizedPushNotificationTemplatesCount },
        m_name{ SafeString(model.name) }
    {
        SetModelPointers();
    }

    PFAccountManagementSavePushNotificationTemplateRequestWrapper(const PFAccountManagementSavePushNotificationTemplateRequestWrapper& src) :
        PFAccountManagementSavePushNotificationTemplateRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementSavePushNotificationTemplateRequestWrapper(PFAccountManagementSavePushNotificationTemplateRequestWrapper&& src) :
        PFAccountManagementSavePushNotificationTemplateRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementSavePushNotificationTemplateRequestWrapper& operator=(PFAccountManagementSavePushNotificationTemplateRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementSavePushNotificationTemplateRequestWrapper() = default;

    friend void swap(PFAccountManagementSavePushNotificationTemplateRequestWrapper& lhs, PFAccountManagementSavePushNotificationTemplateRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_androidPayload, rhs.m_androidPayload);
        swap(lhs.m_id, rhs.m_id);
        swap(lhs.m_iOSPayload, rhs.m_iOSPayload);
        swap(lhs.m_localizedPushNotificationTemplates, rhs.m_localizedPushNotificationTemplates);
        swap(lhs.m_name, rhs.m_name);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAndroidPayload(String value)
    {
        m_androidPayload = std::move(value);
        this->m_model.androidPayload =  m_androidPayload.empty() ? nullptr : m_androidPayload.data();
    }

    void SetId(String value)
    {
        m_id = std::move(value);
        this->m_model.id =  m_id.empty() ? nullptr : m_id.data();
    }

    void SetIOSPayload(String value)
    {
        m_iOSPayload = std::move(value);
        this->m_model.iOSPayload =  m_iOSPayload.empty() ? nullptr : m_iOSPayload.data();
    }

    void SetLocalizedPushNotificationTemplates(ModelDictionaryEntryVector<PFAccountManagementLocalizedPushNotificationPropertiesWrapper<Alloc>, Alloc> value)
    {
        m_localizedPushNotificationTemplates = std::move(value);
        this->m_model.localizedPushNotificationTemplates =  m_localizedPushNotificationTemplates.empty() ? nullptr : m_localizedPushNotificationTemplates.data();
        this->m_model.localizedPushNotificationTemplatesCount =  static_cast<uint32_t>(m_localizedPushNotificationTemplates.size());
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.androidPayload = m_androidPayload.empty() ? nullptr : m_androidPayload.data();
        this->m_model.id = m_id.empty() ? nullptr : m_id.data();
        this->m_model.iOSPayload = m_iOSPayload.empty() ? nullptr : m_iOSPayload.data();
        this->m_model.localizedPushNotificationTemplates = m_localizedPushNotificationTemplates.empty() ? nullptr : m_localizedPushNotificationTemplates.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
    }

    String m_androidPayload;
    String m_id;
    String m_iOSPayload;
    ModelDictionaryEntryVector<PFAccountManagementLocalizedPushNotificationPropertiesWrapper<Alloc>, Alloc> m_localizedPushNotificationTemplates;
    String m_name;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementSavePushNotificationTemplateResultWrapper : public ModelWrapper<PFAccountManagementSavePushNotificationTemplateResult, Alloc>
{
public:
    using ModelType = typename PFAccountManagementSavePushNotificationTemplateResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementSavePushNotificationTemplateResultWrapper() = default;

    PFAccountManagementSavePushNotificationTemplateResultWrapper(const PFAccountManagementSavePushNotificationTemplateResult& model) :
        ModelWrapper<PFAccountManagementSavePushNotificationTemplateResult, Alloc>{ model },
        m_pushNotificationTemplateId{ SafeString(model.pushNotificationTemplateId) }
    {
        SetModelPointers();
    }

    PFAccountManagementSavePushNotificationTemplateResultWrapper(const PFAccountManagementSavePushNotificationTemplateResultWrapper& src) :
        PFAccountManagementSavePushNotificationTemplateResultWrapper{ src.Model() }
    {
    }

    PFAccountManagementSavePushNotificationTemplateResultWrapper(PFAccountManagementSavePushNotificationTemplateResultWrapper&& src) :
        PFAccountManagementSavePushNotificationTemplateResultWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementSavePushNotificationTemplateResultWrapper& operator=(PFAccountManagementSavePushNotificationTemplateResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementSavePushNotificationTemplateResultWrapper() = default;

    friend void swap(PFAccountManagementSavePushNotificationTemplateResultWrapper& lhs, PFAccountManagementSavePushNotificationTemplateResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_pushNotificationTemplateId, rhs.m_pushNotificationTemplateId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPushNotificationTemplateId(String value)
    {
        m_pushNotificationTemplateId = std::move(value);
        this->m_model.pushNotificationTemplateId =  m_pushNotificationTemplateId.empty() ? nullptr : m_pushNotificationTemplateId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.pushNotificationTemplateId = m_pushNotificationTemplateId.empty() ? nullptr : m_pushNotificationTemplateId.data();
    }

    String m_pushNotificationTemplateId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper : public ModelWrapper<PFAccountManagementSendCustomAccountRecoveryEmailRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementSendCustomAccountRecoveryEmailRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper() = default;

    PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper(const PFAccountManagementSendCustomAccountRecoveryEmailRequest& model) :
        ModelWrapper<PFAccountManagementSendCustomAccountRecoveryEmailRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_email{ SafeString(model.email) },
        m_emailTemplateId{ SafeString(model.emailTemplateId) },
        m_username{ SafeString(model.username) }
    {
        SetModelPointers();
    }

    PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper(const PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper& src) :
        PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper(PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper&& src) :
        PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper& operator=(PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper() = default;

    friend void swap(PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper& lhs, PFAccountManagementSendCustomAccountRecoveryEmailRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_email, rhs.m_email);
        swap(lhs.m_emailTemplateId, rhs.m_emailTemplateId);
        swap(lhs.m_username, rhs.m_username);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEmail(String value)
    {
        m_email = std::move(value);
        this->m_model.email =  m_email.empty() ? nullptr : m_email.data();
    }

    void SetEmailTemplateId(String value)
    {
        m_emailTemplateId = std::move(value);
        this->m_model.emailTemplateId =  m_emailTemplateId.empty() ? nullptr : m_emailTemplateId.data();
    }

    void SetUsername(String value)
    {
        m_username = std::move(value);
        this->m_model.username =  m_username.empty() ? nullptr : m_username.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.email = m_email.empty() ? nullptr : m_email.data();
        this->m_model.emailTemplateId = m_emailTemplateId.empty() ? nullptr : m_emailTemplateId.data();
        this->m_model.username = m_username.empty() ? nullptr : m_username.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_email;
    String m_emailTemplateId;
    String m_username;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementSendEmailFromTemplateRequestWrapper : public ModelWrapper<PFAccountManagementSendEmailFromTemplateRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementSendEmailFromTemplateRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementSendEmailFromTemplateRequestWrapper() = default;

    PFAccountManagementSendEmailFromTemplateRequestWrapper(const PFAccountManagementSendEmailFromTemplateRequest& model) :
        ModelWrapper<PFAccountManagementSendEmailFromTemplateRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_emailTemplateId{ SafeString(model.emailTemplateId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementSendEmailFromTemplateRequestWrapper(const PFAccountManagementSendEmailFromTemplateRequestWrapper& src) :
        PFAccountManagementSendEmailFromTemplateRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementSendEmailFromTemplateRequestWrapper(PFAccountManagementSendEmailFromTemplateRequestWrapper&& src) :
        PFAccountManagementSendEmailFromTemplateRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementSendEmailFromTemplateRequestWrapper& operator=(PFAccountManagementSendEmailFromTemplateRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementSendEmailFromTemplateRequestWrapper() = default;

    friend void swap(PFAccountManagementSendEmailFromTemplateRequestWrapper& lhs, PFAccountManagementSendEmailFromTemplateRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_emailTemplateId, rhs.m_emailTemplateId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetEmailTemplateId(String value)
    {
        m_emailTemplateId = std::move(value);
        this->m_model.emailTemplateId =  m_emailTemplateId.empty() ? nullptr : m_emailTemplateId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.emailTemplateId = m_emailTemplateId.empty() ? nullptr : m_emailTemplateId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_emailTemplateId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementAdvancedPushPlatformMsgWrapper : public ModelWrapper<PFAccountManagementAdvancedPushPlatformMsg, Alloc>
{
public:
    using ModelType = typename PFAccountManagementAdvancedPushPlatformMsg;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementAdvancedPushPlatformMsgWrapper() = default;

    PFAccountManagementAdvancedPushPlatformMsgWrapper(const PFAccountManagementAdvancedPushPlatformMsg& model) :
        ModelWrapper<PFAccountManagementAdvancedPushPlatformMsg, Alloc>{ model },
        m_gCMDataOnly{ model.gCMDataOnly ? StdExtra::optional<bool>{ *model.gCMDataOnly } : StdExtra::nullopt },
        m_json{ SafeString(model.json) }
    {
        SetModelPointers();
    }

    PFAccountManagementAdvancedPushPlatformMsgWrapper(const PFAccountManagementAdvancedPushPlatformMsgWrapper& src) :
        PFAccountManagementAdvancedPushPlatformMsgWrapper{ src.Model() }
    {
    }

    PFAccountManagementAdvancedPushPlatformMsgWrapper(PFAccountManagementAdvancedPushPlatformMsgWrapper&& src) :
        PFAccountManagementAdvancedPushPlatformMsgWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementAdvancedPushPlatformMsgWrapper& operator=(PFAccountManagementAdvancedPushPlatformMsgWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementAdvancedPushPlatformMsgWrapper() = default;

    friend void swap(PFAccountManagementAdvancedPushPlatformMsgWrapper& lhs, PFAccountManagementAdvancedPushPlatformMsgWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_gCMDataOnly, rhs.m_gCMDataOnly);
        swap(lhs.m_json, rhs.m_json);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGCMDataOnly(StdExtra::optional<bool> value)
    {
        m_gCMDataOnly = std::move(value);
        this->m_model.gCMDataOnly = m_gCMDataOnly ? m_gCMDataOnly.operator->() : nullptr;
    }

    void SetJson(String value)
    {
        m_json = std::move(value);
        this->m_model.json =  m_json.empty() ? nullptr : m_json.data();
    }

    void SetPlatform(PFPushNotificationPlatform value)
    {
        this->m_model.platform = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.gCMDataOnly = m_gCMDataOnly ? m_gCMDataOnly.operator->() : nullptr;
        this->m_model.json = m_json.empty() ? nullptr : m_json.data();
    }

    StdExtra::optional<bool> m_gCMDataOnly;
    String m_json;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementPushNotificationPackageWrapper : public ModelWrapper<PFAccountManagementPushNotificationPackage, Alloc>
{
public:
    using ModelType = typename PFAccountManagementPushNotificationPackage;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementPushNotificationPackageWrapper() = default;

    PFAccountManagementPushNotificationPackageWrapper(const PFAccountManagementPushNotificationPackage& model) :
        ModelWrapper<PFAccountManagementPushNotificationPackage, Alloc>{ model },
        m_customData{ SafeString(model.customData) },
        m_icon{ SafeString(model.icon) },
        m_message{ SafeString(model.message) },
        m_sound{ SafeString(model.sound) },
        m_title{ SafeString(model.title) }
    {
        SetModelPointers();
    }

    PFAccountManagementPushNotificationPackageWrapper(const PFAccountManagementPushNotificationPackageWrapper& src) :
        PFAccountManagementPushNotificationPackageWrapper{ src.Model() }
    {
    }

    PFAccountManagementPushNotificationPackageWrapper(PFAccountManagementPushNotificationPackageWrapper&& src) :
        PFAccountManagementPushNotificationPackageWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementPushNotificationPackageWrapper& operator=(PFAccountManagementPushNotificationPackageWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementPushNotificationPackageWrapper() = default;

    friend void swap(PFAccountManagementPushNotificationPackageWrapper& lhs, PFAccountManagementPushNotificationPackageWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customData, rhs.m_customData);
        swap(lhs.m_icon, rhs.m_icon);
        swap(lhs.m_message, rhs.m_message);
        swap(lhs.m_sound, rhs.m_sound);
        swap(lhs.m_title, rhs.m_title);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBadge(int32_t value)
    {
        this->m_model.badge = value;
    }

    void SetCustomData(String value)
    {
        m_customData = std::move(value);
        this->m_model.customData =  m_customData.empty() ? nullptr : m_customData.data();
    }

    void SetIcon(String value)
    {
        m_icon = std::move(value);
        this->m_model.icon =  m_icon.empty() ? nullptr : m_icon.data();
    }

    void SetMessage(String value)
    {
        m_message = std::move(value);
        this->m_model.message =  m_message.empty() ? nullptr : m_message.data();
    }

    void SetSound(String value)
    {
        m_sound = std::move(value);
        this->m_model.sound =  m_sound.empty() ? nullptr : m_sound.data();
    }

    void SetTitle(String value)
    {
        m_title = std::move(value);
        this->m_model.title =  m_title.empty() ? nullptr : m_title.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customData = m_customData.empty() ? nullptr : m_customData.data();
        this->m_model.icon = m_icon.empty() ? nullptr : m_icon.data();
        this->m_model.message = m_message.empty() ? nullptr : m_message.data();
        this->m_model.sound = m_sound.empty() ? nullptr : m_sound.data();
        this->m_model.title = m_title.empty() ? nullptr : m_title.data();
    }

    String m_customData;
    String m_icon;
    String m_message;
    String m_sound;
    String m_title;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementSendPushNotificationRequestWrapper : public ModelWrapper<PFAccountManagementSendPushNotificationRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementSendPushNotificationRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementSendPushNotificationRequestWrapper() = default;

    PFAccountManagementSendPushNotificationRequestWrapper(const PFAccountManagementSendPushNotificationRequest& model) :
        ModelWrapper<PFAccountManagementSendPushNotificationRequest, Alloc>{ model },
        m_advancedPlatformDelivery{ model.advancedPlatformDelivery, model.advancedPlatformDelivery + model.advancedPlatformDeliveryCount },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_message{ SafeString(model.message) },
        m_package{ model.package ? StdExtra::optional<PFAccountManagementPushNotificationPackageWrapper<Alloc>>{ *model.package } : StdExtra::nullopt },
        m_recipient{ SafeString(model.recipient) },
        m_subject{ SafeString(model.subject) },
        m_targetPlatforms{ model.targetPlatforms, model.targetPlatforms + model.targetPlatformsCount }
    {
        SetModelPointers();
    }

    PFAccountManagementSendPushNotificationRequestWrapper(const PFAccountManagementSendPushNotificationRequestWrapper& src) :
        PFAccountManagementSendPushNotificationRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementSendPushNotificationRequestWrapper(PFAccountManagementSendPushNotificationRequestWrapper&& src) :
        PFAccountManagementSendPushNotificationRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementSendPushNotificationRequestWrapper& operator=(PFAccountManagementSendPushNotificationRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementSendPushNotificationRequestWrapper() = default;

    friend void swap(PFAccountManagementSendPushNotificationRequestWrapper& lhs, PFAccountManagementSendPushNotificationRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_advancedPlatformDelivery, rhs.m_advancedPlatformDelivery);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_message, rhs.m_message);
        swap(lhs.m_package, rhs.m_package);
        swap(lhs.m_recipient, rhs.m_recipient);
        swap(lhs.m_subject, rhs.m_subject);
        swap(lhs.m_targetPlatforms, rhs.m_targetPlatforms);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAdvancedPlatformDelivery(ModelVector<PFAccountManagementAdvancedPushPlatformMsgWrapper<Alloc>, Alloc> value)
    {
        m_advancedPlatformDelivery = std::move(value);
        this->m_model.advancedPlatformDelivery =  m_advancedPlatformDelivery.empty() ? nullptr : m_advancedPlatformDelivery.data();
        this->m_model.advancedPlatformDeliveryCount =  static_cast<uint32_t>(m_advancedPlatformDelivery.size());
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetMessage(String value)
    {
        m_message = std::move(value);
        this->m_model.message =  m_message.empty() ? nullptr : m_message.data();
    }

    void SetPackage(StdExtra::optional<PFAccountManagementPushNotificationPackageWrapper<Alloc>> value)
    {
        m_package = std::move(value);
        this->m_model.package = m_package ? &m_package->Model() : nullptr;
    }

    void SetRecipient(String value)
    {
        m_recipient = std::move(value);
        this->m_model.recipient =  m_recipient.empty() ? nullptr : m_recipient.data();
    }

    void SetSubject(String value)
    {
        m_subject = std::move(value);
        this->m_model.subject =  m_subject.empty() ? nullptr : m_subject.data();
    }

    void SetTargetPlatforms(Vector<PFPushNotificationPlatform> value)
    {
        m_targetPlatforms = std::move(value);
        this->m_model.targetPlatforms =  m_targetPlatforms.empty() ? nullptr : m_targetPlatforms.data();
        this->m_model.targetPlatformsCount =  static_cast<uint32_t>(m_targetPlatforms.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.advancedPlatformDelivery = m_advancedPlatformDelivery.empty() ? nullptr : m_advancedPlatformDelivery.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.message = m_message.empty() ? nullptr : m_message.data();
        this->m_model.package = m_package ?  &m_package->Model() : nullptr;
        this->m_model.recipient = m_recipient.empty() ? nullptr : m_recipient.data();
        this->m_model.subject = m_subject.empty() ? nullptr : m_subject.data();
        this->m_model.targetPlatforms = m_targetPlatforms.empty() ? nullptr : m_targetPlatforms.data();
    }

    ModelVector<PFAccountManagementAdvancedPushPlatformMsgWrapper<Alloc>, Alloc> m_advancedPlatformDelivery;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_message;
    StdExtra::optional<PFAccountManagementPushNotificationPackageWrapper<Alloc>> m_package;
    String m_recipient;
    String m_subject;
    Vector<PFPushNotificationPlatform> m_targetPlatforms;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementSendPushNotificationFromTemplateRequestWrapper : public ModelWrapper<PFAccountManagementSendPushNotificationFromTemplateRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementSendPushNotificationFromTemplateRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementSendPushNotificationFromTemplateRequestWrapper() = default;

    PFAccountManagementSendPushNotificationFromTemplateRequestWrapper(const PFAccountManagementSendPushNotificationFromTemplateRequest& model) :
        ModelWrapper<PFAccountManagementSendPushNotificationFromTemplateRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_pushNotificationTemplateId{ SafeString(model.pushNotificationTemplateId) },
        m_recipient{ SafeString(model.recipient) }
    {
        SetModelPointers();
    }

    PFAccountManagementSendPushNotificationFromTemplateRequestWrapper(const PFAccountManagementSendPushNotificationFromTemplateRequestWrapper& src) :
        PFAccountManagementSendPushNotificationFromTemplateRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementSendPushNotificationFromTemplateRequestWrapper(PFAccountManagementSendPushNotificationFromTemplateRequestWrapper&& src) :
        PFAccountManagementSendPushNotificationFromTemplateRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementSendPushNotificationFromTemplateRequestWrapper& operator=(PFAccountManagementSendPushNotificationFromTemplateRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementSendPushNotificationFromTemplateRequestWrapper() = default;

    friend void swap(PFAccountManagementSendPushNotificationFromTemplateRequestWrapper& lhs, PFAccountManagementSendPushNotificationFromTemplateRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_pushNotificationTemplateId, rhs.m_pushNotificationTemplateId);
        swap(lhs.m_recipient, rhs.m_recipient);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPushNotificationTemplateId(String value)
    {
        m_pushNotificationTemplateId = std::move(value);
        this->m_model.pushNotificationTemplateId =  m_pushNotificationTemplateId.empty() ? nullptr : m_pushNotificationTemplateId.data();
    }

    void SetRecipient(String value)
    {
        m_recipient = std::move(value);
        this->m_model.recipient =  m_recipient.empty() ? nullptr : m_recipient.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.pushNotificationTemplateId = m_pushNotificationTemplateId.empty() ? nullptr : m_pushNotificationTemplateId.data();
        this->m_model.recipient = m_recipient.empty() ? nullptr : m_recipient.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_pushNotificationTemplateId;
    String m_recipient;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementServerUnlinkPSNAccountRequestWrapper : public ModelWrapper<PFAccountManagementServerUnlinkPSNAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementServerUnlinkPSNAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementServerUnlinkPSNAccountRequestWrapper() = default;

    PFAccountManagementServerUnlinkPSNAccountRequestWrapper(const PFAccountManagementServerUnlinkPSNAccountRequest& model) :
        ModelWrapper<PFAccountManagementServerUnlinkPSNAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementServerUnlinkPSNAccountRequestWrapper(const PFAccountManagementServerUnlinkPSNAccountRequestWrapper& src) :
        PFAccountManagementServerUnlinkPSNAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementServerUnlinkPSNAccountRequestWrapper(PFAccountManagementServerUnlinkPSNAccountRequestWrapper&& src) :
        PFAccountManagementServerUnlinkPSNAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementServerUnlinkPSNAccountRequestWrapper& operator=(PFAccountManagementServerUnlinkPSNAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementServerUnlinkPSNAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementServerUnlinkPSNAccountRequestWrapper& lhs, PFAccountManagementServerUnlinkPSNAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementUnlinkServerCustomIdRequestWrapper : public ModelWrapper<PFAccountManagementUnlinkServerCustomIdRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementUnlinkServerCustomIdRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementUnlinkServerCustomIdRequestWrapper() = default;

    PFAccountManagementUnlinkServerCustomIdRequestWrapper(const PFAccountManagementUnlinkServerCustomIdRequest& model) :
        ModelWrapper<PFAccountManagementUnlinkServerCustomIdRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_serverCustomId{ SafeString(model.serverCustomId) }
    {
        SetModelPointers();
    }

    PFAccountManagementUnlinkServerCustomIdRequestWrapper(const PFAccountManagementUnlinkServerCustomIdRequestWrapper& src) :
        PFAccountManagementUnlinkServerCustomIdRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementUnlinkServerCustomIdRequestWrapper(PFAccountManagementUnlinkServerCustomIdRequestWrapper&& src) :
        PFAccountManagementUnlinkServerCustomIdRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementUnlinkServerCustomIdRequestWrapper& operator=(PFAccountManagementUnlinkServerCustomIdRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementUnlinkServerCustomIdRequestWrapper() = default;

    friend void swap(PFAccountManagementUnlinkServerCustomIdRequestWrapper& lhs, PFAccountManagementUnlinkServerCustomIdRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_serverCustomId, rhs.m_serverCustomId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetServerCustomId(String value)
    {
        m_serverCustomId = std::move(value);
        this->m_model.serverCustomId =  m_serverCustomId.empty() ? nullptr : m_serverCustomId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.serverCustomId = m_serverCustomId.empty() ? nullptr : m_serverCustomId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
    String m_serverCustomId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementServerUnlinkXboxAccountRequestWrapper : public ModelWrapper<PFAccountManagementServerUnlinkXboxAccountRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementServerUnlinkXboxAccountRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementServerUnlinkXboxAccountRequestWrapper() = default;

    PFAccountManagementServerUnlinkXboxAccountRequestWrapper(const PFAccountManagementServerUnlinkXboxAccountRequest& model) :
        ModelWrapper<PFAccountManagementServerUnlinkXboxAccountRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementServerUnlinkXboxAccountRequestWrapper(const PFAccountManagementServerUnlinkXboxAccountRequestWrapper& src) :
        PFAccountManagementServerUnlinkXboxAccountRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementServerUnlinkXboxAccountRequestWrapper(PFAccountManagementServerUnlinkXboxAccountRequestWrapper&& src) :
        PFAccountManagementServerUnlinkXboxAccountRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementServerUnlinkXboxAccountRequestWrapper& operator=(PFAccountManagementServerUnlinkXboxAccountRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementServerUnlinkXboxAccountRequestWrapper() = default;

    friend void swap(PFAccountManagementServerUnlinkXboxAccountRequestWrapper& lhs, PFAccountManagementServerUnlinkXboxAccountRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAccountManagementServerUpdateAvatarUrlRequestWrapper : public ModelWrapper<PFAccountManagementServerUpdateAvatarUrlRequest, Alloc>
{
public:
    using ModelType = typename PFAccountManagementServerUpdateAvatarUrlRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAccountManagementServerUpdateAvatarUrlRequestWrapper() = default;

    PFAccountManagementServerUpdateAvatarUrlRequestWrapper(const PFAccountManagementServerUpdateAvatarUrlRequest& model) :
        ModelWrapper<PFAccountManagementServerUpdateAvatarUrlRequest, Alloc>{ model },
        m_imageUrl{ SafeString(model.imageUrl) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFAccountManagementServerUpdateAvatarUrlRequestWrapper(const PFAccountManagementServerUpdateAvatarUrlRequestWrapper& src) :
        PFAccountManagementServerUpdateAvatarUrlRequestWrapper{ src.Model() }
    {
    }

    PFAccountManagementServerUpdateAvatarUrlRequestWrapper(PFAccountManagementServerUpdateAvatarUrlRequestWrapper&& src) :
        PFAccountManagementServerUpdateAvatarUrlRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAccountManagementServerUpdateAvatarUrlRequestWrapper& operator=(PFAccountManagementServerUpdateAvatarUrlRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAccountManagementServerUpdateAvatarUrlRequestWrapper() = default;

    friend void swap(PFAccountManagementServerUpdateAvatarUrlRequestWrapper& lhs, PFAccountManagementServerUpdateAvatarUrlRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_imageUrl, rhs.m_imageUrl);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetImageUrl(String value)
    {
        m_imageUrl = std::move(value);
        this->m_model.imageUrl =  m_imageUrl.empty() ? nullptr : m_imageUrl.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.imageUrl = m_imageUrl.empty() ? nullptr : m_imageUrl.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_imageUrl;
    String m_playFabId;
};

} // namespace Wrappers
} // namespace PlayFab
