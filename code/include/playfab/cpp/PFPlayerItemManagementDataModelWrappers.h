// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFPlayerItemManagementDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper : public ModelWrapper<PFPlayerItemManagementAdminAddUserVirtualCurrencyRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementAdminAddUserVirtualCurrencyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper() = default;

    PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper(const PFPlayerItemManagementAdminAddUserVirtualCurrencyRequest& model) :
        ModelWrapper<PFPlayerItemManagementAdminAddUserVirtualCurrencyRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_virtualCurrency{ SafeString(model.virtualCurrency) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper(const PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper& src) :
        PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper(PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper&& src) :
        PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper& operator=(PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper& lhs, PFPlayerItemManagementAdminAddUserVirtualCurrencyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAmount(int32_t value)
    {
        this->m_model.amount = value;
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

    void SetVirtualCurrency(String value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
    String m_virtualCurrency;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementModifyUserVirtualCurrencyResultWrapper : public ModelWrapper<PFPlayerItemManagementModifyUserVirtualCurrencyResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementModifyUserVirtualCurrencyResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementModifyUserVirtualCurrencyResultWrapper() = default;

    PFPlayerItemManagementModifyUserVirtualCurrencyResultWrapper(const PFPlayerItemManagementModifyUserVirtualCurrencyResult& model) :
        ModelWrapper<PFPlayerItemManagementModifyUserVirtualCurrencyResult, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) },
        m_virtualCurrency{ SafeString(model.virtualCurrency) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementModifyUserVirtualCurrencyResultWrapper(const PFPlayerItemManagementModifyUserVirtualCurrencyResultWrapper& src) :
        PFPlayerItemManagementModifyUserVirtualCurrencyResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementModifyUserVirtualCurrencyResultWrapper(PFPlayerItemManagementModifyUserVirtualCurrencyResultWrapper&& src) :
        PFPlayerItemManagementModifyUserVirtualCurrencyResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementModifyUserVirtualCurrencyResultWrapper& operator=(PFPlayerItemManagementModifyUserVirtualCurrencyResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementModifyUserVirtualCurrencyResultWrapper() = default;

    friend void swap(PFPlayerItemManagementModifyUserVirtualCurrencyResultWrapper& lhs, PFPlayerItemManagementModifyUserVirtualCurrencyResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBalance(int32_t value)
    {
        this->m_model.balance = value;
    }

    void SetBalanceChange(int32_t value)
    {
        this->m_model.balanceChange = value;
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetVirtualCurrency(String value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

    String m_playFabId;
    String m_virtualCurrency;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper : public ModelWrapper<PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper() = default;

    PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper(const PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequest& model) :
        ModelWrapper<PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_itemId{ SafeString(model.itemId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper(const PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper& src) :
        PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper(PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper&& src) :
        PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper& operator=(PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper& lhs, PFPlayerItemManagementCheckLimitedEditionItemAvailabilityRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_itemId, rhs.m_itemId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetItemId(String value)
    {
        m_itemId = std::move(value);
        this->m_model.itemId =  m_itemId.empty() ? nullptr : m_itemId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.itemId = m_itemId.empty() ? nullptr : m_itemId.data();
    }

    String m_catalogVersion;
    String m_itemId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResultWrapper : public ModelWrapper<PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    using ModelWrapper<PFPlayerItemManagementCheckLimitedEditionItemAvailabilityResult, Alloc>::ModelWrapper;

    void SetAmount(int32_t value)
    {
        this->m_model.amount = value;
    }

private:
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementAdminGetUserInventoryRequestWrapper : public ModelWrapper<PFPlayerItemManagementAdminGetUserInventoryRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementAdminGetUserInventoryRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementAdminGetUserInventoryRequestWrapper() = default;

    PFPlayerItemManagementAdminGetUserInventoryRequestWrapper(const PFPlayerItemManagementAdminGetUserInventoryRequest& model) :
        ModelWrapper<PFPlayerItemManagementAdminGetUserInventoryRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementAdminGetUserInventoryRequestWrapper(const PFPlayerItemManagementAdminGetUserInventoryRequestWrapper& src) :
        PFPlayerItemManagementAdminGetUserInventoryRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementAdminGetUserInventoryRequestWrapper(PFPlayerItemManagementAdminGetUserInventoryRequestWrapper&& src) :
        PFPlayerItemManagementAdminGetUserInventoryRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementAdminGetUserInventoryRequestWrapper& operator=(PFPlayerItemManagementAdminGetUserInventoryRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementAdminGetUserInventoryRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementAdminGetUserInventoryRequestWrapper& lhs, PFPlayerItemManagementAdminGetUserInventoryRequestWrapper& rhs)
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
class PFPlayerItemManagementAdminGetUserInventoryResultWrapper : public ModelWrapper<PFPlayerItemManagementAdminGetUserInventoryResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementAdminGetUserInventoryResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementAdminGetUserInventoryResultWrapper() = default;

    PFPlayerItemManagementAdminGetUserInventoryResultWrapper(const PFPlayerItemManagementAdminGetUserInventoryResult& model) :
        ModelWrapper<PFPlayerItemManagementAdminGetUserInventoryResult, Alloc>{ model },
        m_inventory{ model.inventory, model.inventory + model.inventoryCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_virtualCurrency{ model.virtualCurrency, model.virtualCurrency + model.virtualCurrencyCount },
        m_virtualCurrencyRechargeTimes{ model.virtualCurrencyRechargeTimes, model.virtualCurrencyRechargeTimes + model.virtualCurrencyRechargeTimesCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementAdminGetUserInventoryResultWrapper(const PFPlayerItemManagementAdminGetUserInventoryResultWrapper& src) :
        PFPlayerItemManagementAdminGetUserInventoryResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementAdminGetUserInventoryResultWrapper(PFPlayerItemManagementAdminGetUserInventoryResultWrapper&& src) :
        PFPlayerItemManagementAdminGetUserInventoryResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementAdminGetUserInventoryResultWrapper& operator=(PFPlayerItemManagementAdminGetUserInventoryResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementAdminGetUserInventoryResultWrapper() = default;

    friend void swap(PFPlayerItemManagementAdminGetUserInventoryResultWrapper& lhs, PFPlayerItemManagementAdminGetUserInventoryResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_inventory, rhs.m_inventory);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        swap(lhs.m_virtualCurrencyRechargeTimes, rhs.m_virtualCurrencyRechargeTimes);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetInventory(ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_inventory = std::move(value);
        this->m_model.inventory =  m_inventory.empty() ? nullptr : m_inventory.data();
        this->m_model.inventoryCount =  static_cast<uint32_t>(m_inventory.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetVirtualCurrency(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
        this->m_model.virtualCurrencyCount =  static_cast<uint32_t>(m_virtualCurrency.size());
    }

    void SetVirtualCurrencyRechargeTimes(ModelDictionaryEntryVector<PFVirtualCurrencyRechargeTimeWrapper<Alloc>, Alloc> value)
    {
        m_virtualCurrencyRechargeTimes = std::move(value);
        this->m_model.virtualCurrencyRechargeTimes =  m_virtualCurrencyRechargeTimes.empty() ? nullptr : m_virtualCurrencyRechargeTimes.data();
        this->m_model.virtualCurrencyRechargeTimesCount =  static_cast<uint32_t>(m_virtualCurrencyRechargeTimes.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.inventory = m_inventory.empty() ? nullptr : m_inventory.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
        this->m_model.virtualCurrencyRechargeTimes = m_virtualCurrencyRechargeTimes.empty() ? nullptr : m_virtualCurrencyRechargeTimes.data();
    }

    ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> m_inventory;
    String m_playFabId;
    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_virtualCurrency;
    ModelDictionaryEntryVector<PFVirtualCurrencyRechargeTimeWrapper<Alloc>, Alloc> m_virtualCurrencyRechargeTimes;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementItemGrantWrapper : public ModelWrapper<PFPlayerItemManagementItemGrant, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementItemGrant;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementItemGrantWrapper() = default;

    PFPlayerItemManagementItemGrantWrapper(const PFPlayerItemManagementItemGrant& model) :
        ModelWrapper<PFPlayerItemManagementItemGrant, Alloc>{ model },
        m_annotation{ SafeString(model.annotation) },
        m_characterId{ SafeString(model.characterId) },
        m_data{ model.data, model.data + model.dataCount },
        m_itemId{ SafeString(model.itemId) },
        m_keysToRemove{ model.keysToRemove, model.keysToRemove + model.keysToRemoveCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementItemGrantWrapper(const PFPlayerItemManagementItemGrantWrapper& src) :
        PFPlayerItemManagementItemGrantWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementItemGrantWrapper(PFPlayerItemManagementItemGrantWrapper&& src) :
        PFPlayerItemManagementItemGrantWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementItemGrantWrapper& operator=(PFPlayerItemManagementItemGrantWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementItemGrantWrapper() = default;

    friend void swap(PFPlayerItemManagementItemGrantWrapper& lhs, PFPlayerItemManagementItemGrantWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_annotation, rhs.m_annotation);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_data, rhs.m_data);
        swap(lhs.m_itemId, rhs.m_itemId);
        swap(lhs.m_keysToRemove, rhs.m_keysToRemove);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAnnotation(String value)
    {
        m_annotation = std::move(value);
        this->m_model.annotation =  m_annotation.empty() ? nullptr : m_annotation.data();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetData(StringDictionaryEntryVector<Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

    void SetItemId(String value)
    {
        m_itemId = std::move(value);
        this->m_model.itemId =  m_itemId.empty() ? nullptr : m_itemId.data();
    }

    void SetKeysToRemove(CStringVector<Alloc> value)
    {
        m_keysToRemove = std::move(value);
        this->m_model.keysToRemove =  m_keysToRemove.empty() ? nullptr : m_keysToRemove.data();
        this->m_model.keysToRemoveCount =  static_cast<uint32_t>(m_keysToRemove.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.annotation = m_annotation.empty() ? nullptr : m_annotation.data();
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
        this->m_model.itemId = m_itemId.empty() ? nullptr : m_itemId.data();
        this->m_model.keysToRemove = m_keysToRemove.empty() ? nullptr : m_keysToRemove.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_annotation;
    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_data;
    String m_itemId;
    CStringVector<Alloc> m_keysToRemove;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementGrantItemsToUsersRequestWrapper : public ModelWrapper<PFPlayerItemManagementGrantItemsToUsersRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementGrantItemsToUsersRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementGrantItemsToUsersRequestWrapper() = default;

    PFPlayerItemManagementGrantItemsToUsersRequestWrapper(const PFPlayerItemManagementGrantItemsToUsersRequest& model) :
        ModelWrapper<PFPlayerItemManagementGrantItemsToUsersRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_itemGrants{ model.itemGrants, model.itemGrants + model.itemGrantsCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementGrantItemsToUsersRequestWrapper(const PFPlayerItemManagementGrantItemsToUsersRequestWrapper& src) :
        PFPlayerItemManagementGrantItemsToUsersRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementGrantItemsToUsersRequestWrapper(PFPlayerItemManagementGrantItemsToUsersRequestWrapper&& src) :
        PFPlayerItemManagementGrantItemsToUsersRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementGrantItemsToUsersRequestWrapper& operator=(PFPlayerItemManagementGrantItemsToUsersRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementGrantItemsToUsersRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementGrantItemsToUsersRequestWrapper& lhs, PFPlayerItemManagementGrantItemsToUsersRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_itemGrants, rhs.m_itemGrants);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetItemGrants(ModelVector<PFPlayerItemManagementItemGrantWrapper<Alloc>, Alloc> value)
    {
        m_itemGrants = std::move(value);
        this->m_model.itemGrants =  m_itemGrants.empty() ? nullptr : m_itemGrants.data();
        this->m_model.itemGrantsCount =  static_cast<uint32_t>(m_itemGrants.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.itemGrants = m_itemGrants.empty() ? nullptr : m_itemGrants.data();
    }

    String m_catalogVersion;
    StringDictionaryEntryVector<Alloc> m_customTags;
    ModelVector<PFPlayerItemManagementItemGrantWrapper<Alloc>, Alloc> m_itemGrants;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementGrantedItemInstanceWrapper : public ModelWrapper<PFPlayerItemManagementGrantedItemInstance, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementGrantedItemInstance;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementGrantedItemInstanceWrapper() = default;

    PFPlayerItemManagementGrantedItemInstanceWrapper(const PFPlayerItemManagementGrantedItemInstance& model) :
        ModelWrapper<PFPlayerItemManagementGrantedItemInstance, Alloc>{ model },
        m_annotation{ SafeString(model.annotation) },
        m_bundleContents{ model.bundleContents, model.bundleContents + model.bundleContentsCount },
        m_bundleParent{ SafeString(model.bundleParent) },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_characterId{ SafeString(model.characterId) },
        m_customData{ model.customData, model.customData + model.customDataCount },
        m_displayName{ SafeString(model.displayName) },
        m_expiration{ model.expiration ? StdExtra::optional<time_t>{ *model.expiration } : StdExtra::nullopt },
        m_itemClass{ SafeString(model.itemClass) },
        m_itemId{ SafeString(model.itemId) },
        m_itemInstanceId{ SafeString(model.itemInstanceId) },
        m_playFabId{ SafeString(model.playFabId) },
        m_purchaseDate{ model.purchaseDate ? StdExtra::optional<time_t>{ *model.purchaseDate } : StdExtra::nullopt },
        m_remainingUses{ model.remainingUses ? StdExtra::optional<int32_t>{ *model.remainingUses } : StdExtra::nullopt },
        m_unitCurrency{ SafeString(model.unitCurrency) },
        m_usesIncrementedBy{ model.usesIncrementedBy ? StdExtra::optional<int32_t>{ *model.usesIncrementedBy } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementGrantedItemInstanceWrapper(const PFPlayerItemManagementGrantedItemInstanceWrapper& src) :
        PFPlayerItemManagementGrantedItemInstanceWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementGrantedItemInstanceWrapper(PFPlayerItemManagementGrantedItemInstanceWrapper&& src) :
        PFPlayerItemManagementGrantedItemInstanceWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementGrantedItemInstanceWrapper& operator=(PFPlayerItemManagementGrantedItemInstanceWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementGrantedItemInstanceWrapper() = default;

    friend void swap(PFPlayerItemManagementGrantedItemInstanceWrapper& lhs, PFPlayerItemManagementGrantedItemInstanceWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_annotation, rhs.m_annotation);
        swap(lhs.m_bundleContents, rhs.m_bundleContents);
        swap(lhs.m_bundleParent, rhs.m_bundleParent);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customData, rhs.m_customData);
        swap(lhs.m_displayName, rhs.m_displayName);
        swap(lhs.m_expiration, rhs.m_expiration);
        swap(lhs.m_itemClass, rhs.m_itemClass);
        swap(lhs.m_itemId, rhs.m_itemId);
        swap(lhs.m_itemInstanceId, rhs.m_itemInstanceId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_purchaseDate, rhs.m_purchaseDate);
        swap(lhs.m_remainingUses, rhs.m_remainingUses);
        swap(lhs.m_unitCurrency, rhs.m_unitCurrency);
        swap(lhs.m_usesIncrementedBy, rhs.m_usesIncrementedBy);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAnnotation(String value)
    {
        m_annotation = std::move(value);
        this->m_model.annotation =  m_annotation.empty() ? nullptr : m_annotation.data();
    }

    void SetBundleContents(CStringVector<Alloc> value)
    {
        m_bundleContents = std::move(value);
        this->m_model.bundleContents =  m_bundleContents.empty() ? nullptr : m_bundleContents.data();
        this->m_model.bundleContentsCount =  static_cast<uint32_t>(m_bundleContents.size());
    }

    void SetBundleParent(String value)
    {
        m_bundleParent = std::move(value);
        this->m_model.bundleParent =  m_bundleParent.empty() ? nullptr : m_bundleParent.data();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetCustomData(StringDictionaryEntryVector<Alloc> value)
    {
        m_customData = std::move(value);
        this->m_model.customData =  m_customData.empty() ? nullptr : m_customData.data();
        this->m_model.customDataCount =  static_cast<uint32_t>(m_customData.size());
    }

    void SetDisplayName(String value)
    {
        m_displayName = std::move(value);
        this->m_model.displayName =  m_displayName.empty() ? nullptr : m_displayName.data();
    }

    void SetExpiration(StdExtra::optional<time_t> value)
    {
        m_expiration = std::move(value);
        this->m_model.expiration = m_expiration ? m_expiration.operator->() : nullptr;
    }

    void SetItemClass(String value)
    {
        m_itemClass = std::move(value);
        this->m_model.itemClass =  m_itemClass.empty() ? nullptr : m_itemClass.data();
    }

    void SetItemId(String value)
    {
        m_itemId = std::move(value);
        this->m_model.itemId =  m_itemId.empty() ? nullptr : m_itemId.data();
    }

    void SetItemInstanceId(String value)
    {
        m_itemInstanceId = std::move(value);
        this->m_model.itemInstanceId =  m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetPurchaseDate(StdExtra::optional<time_t> value)
    {
        m_purchaseDate = std::move(value);
        this->m_model.purchaseDate = m_purchaseDate ? m_purchaseDate.operator->() : nullptr;
    }

    void SetRemainingUses(StdExtra::optional<int32_t> value)
    {
        m_remainingUses = std::move(value);
        this->m_model.remainingUses = m_remainingUses ? m_remainingUses.operator->() : nullptr;
    }

    void SetResult(bool value)
    {
        this->m_model.result = value;
    }

    void SetUnitCurrency(String value)
    {
        m_unitCurrency = std::move(value);
        this->m_model.unitCurrency =  m_unitCurrency.empty() ? nullptr : m_unitCurrency.data();
    }

    void SetUnitPrice(uint32_t value)
    {
        this->m_model.unitPrice = value;
    }

    void SetUsesIncrementedBy(StdExtra::optional<int32_t> value)
    {
        m_usesIncrementedBy = std::move(value);
        this->m_model.usesIncrementedBy = m_usesIncrementedBy ? m_usesIncrementedBy.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.annotation = m_annotation.empty() ? nullptr : m_annotation.data();
        this->m_model.bundleContents = m_bundleContents.empty() ? nullptr : m_bundleContents.data();
        this->m_model.bundleParent = m_bundleParent.empty() ? nullptr : m_bundleParent.data();
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customData = m_customData.empty() ? nullptr : m_customData.data();
        this->m_model.displayName = m_displayName.empty() ? nullptr : m_displayName.data();
        this->m_model.expiration = m_expiration ? m_expiration.operator->() : nullptr;
        this->m_model.itemClass = m_itemClass.empty() ? nullptr : m_itemClass.data();
        this->m_model.itemId = m_itemId.empty() ? nullptr : m_itemId.data();
        this->m_model.itemInstanceId = m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.purchaseDate = m_purchaseDate ? m_purchaseDate.operator->() : nullptr;
        this->m_model.remainingUses = m_remainingUses ? m_remainingUses.operator->() : nullptr;
        this->m_model.unitCurrency = m_unitCurrency.empty() ? nullptr : m_unitCurrency.data();
        this->m_model.usesIncrementedBy = m_usesIncrementedBy ? m_usesIncrementedBy.operator->() : nullptr;
    }

    String m_annotation;
    CStringVector<Alloc> m_bundleContents;
    String m_bundleParent;
    String m_catalogVersion;
    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_customData;
    String m_displayName;
    StdExtra::optional<time_t> m_expiration;
    String m_itemClass;
    String m_itemId;
    String m_itemInstanceId;
    String m_playFabId;
    StdExtra::optional<time_t> m_purchaseDate;
    StdExtra::optional<int32_t> m_remainingUses;
    String m_unitCurrency;
    StdExtra::optional<int32_t> m_usesIncrementedBy;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementGrantItemsToUsersResultWrapper : public ModelWrapper<PFPlayerItemManagementGrantItemsToUsersResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementGrantItemsToUsersResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementGrantItemsToUsersResultWrapper() = default;

    PFPlayerItemManagementGrantItemsToUsersResultWrapper(const PFPlayerItemManagementGrantItemsToUsersResult& model) :
        ModelWrapper<PFPlayerItemManagementGrantItemsToUsersResult, Alloc>{ model },
        m_itemGrantResults{ model.itemGrantResults, model.itemGrantResults + model.itemGrantResultsCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementGrantItemsToUsersResultWrapper(const PFPlayerItemManagementGrantItemsToUsersResultWrapper& src) :
        PFPlayerItemManagementGrantItemsToUsersResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementGrantItemsToUsersResultWrapper(PFPlayerItemManagementGrantItemsToUsersResultWrapper&& src) :
        PFPlayerItemManagementGrantItemsToUsersResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementGrantItemsToUsersResultWrapper& operator=(PFPlayerItemManagementGrantItemsToUsersResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementGrantItemsToUsersResultWrapper() = default;

    friend void swap(PFPlayerItemManagementGrantItemsToUsersResultWrapper& lhs, PFPlayerItemManagementGrantItemsToUsersResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_itemGrantResults, rhs.m_itemGrantResults);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetItemGrantResults(ModelVector<PFPlayerItemManagementGrantedItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_itemGrantResults = std::move(value);
        this->m_model.itemGrantResults =  m_itemGrantResults.empty() ? nullptr : m_itemGrantResults.data();
        this->m_model.itemGrantResultsCount =  static_cast<uint32_t>(m_itemGrantResults.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.itemGrantResults = m_itemGrantResults.empty() ? nullptr : m_itemGrantResults.data();
    }

    ModelVector<PFPlayerItemManagementGrantedItemInstanceWrapper<Alloc>, Alloc> m_itemGrantResults;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper : public ModelWrapper<PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper() = default;

    PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper(const PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequest& model) :
        ModelWrapper<PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_itemId{ SafeString(model.itemId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper(const PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper& src) :
        PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper(PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper&& src) :
        PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper& operator=(PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper& lhs, PFPlayerItemManagementIncrementLimitedEditionItemAvailabilityRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_itemId, rhs.m_itemId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAmount(int32_t value)
    {
        this->m_model.amount = value;
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetItemId(String value)
    {
        m_itemId = std::move(value);
        this->m_model.itemId =  m_itemId.empty() ? nullptr : m_itemId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.itemId = m_itemId.empty() ? nullptr : m_itemId.data();
    }

    String m_catalogVersion;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_itemId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementRevokeInventoryItemRequestWrapper : public ModelWrapper<PFPlayerItemManagementRevokeInventoryItemRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementRevokeInventoryItemRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementRevokeInventoryItemRequestWrapper() = default;

    PFPlayerItemManagementRevokeInventoryItemRequestWrapper(const PFPlayerItemManagementRevokeInventoryItemRequest& model) :
        ModelWrapper<PFPlayerItemManagementRevokeInventoryItemRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_itemInstanceId{ SafeString(model.itemInstanceId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementRevokeInventoryItemRequestWrapper(const PFPlayerItemManagementRevokeInventoryItemRequestWrapper& src) :
        PFPlayerItemManagementRevokeInventoryItemRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementRevokeInventoryItemRequestWrapper(PFPlayerItemManagementRevokeInventoryItemRequestWrapper&& src) :
        PFPlayerItemManagementRevokeInventoryItemRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementRevokeInventoryItemRequestWrapper& operator=(PFPlayerItemManagementRevokeInventoryItemRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementRevokeInventoryItemRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementRevokeInventoryItemRequestWrapper& lhs, PFPlayerItemManagementRevokeInventoryItemRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_itemInstanceId, rhs.m_itemInstanceId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetItemInstanceId(String value)
    {
        m_itemInstanceId = std::move(value);
        this->m_model.itemInstanceId =  m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.itemInstanceId = m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_characterId;
    String m_itemInstanceId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementRevokeInventoryItemWrapper : public ModelWrapper<PFPlayerItemManagementRevokeInventoryItem, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementRevokeInventoryItem;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementRevokeInventoryItemWrapper() = default;

    PFPlayerItemManagementRevokeInventoryItemWrapper(const PFPlayerItemManagementRevokeInventoryItem& model) :
        ModelWrapper<PFPlayerItemManagementRevokeInventoryItem, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_itemInstanceId{ SafeString(model.itemInstanceId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementRevokeInventoryItemWrapper(const PFPlayerItemManagementRevokeInventoryItemWrapper& src) :
        PFPlayerItemManagementRevokeInventoryItemWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementRevokeInventoryItemWrapper(PFPlayerItemManagementRevokeInventoryItemWrapper&& src) :
        PFPlayerItemManagementRevokeInventoryItemWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementRevokeInventoryItemWrapper& operator=(PFPlayerItemManagementRevokeInventoryItemWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementRevokeInventoryItemWrapper() = default;

    friend void swap(PFPlayerItemManagementRevokeInventoryItemWrapper& lhs, PFPlayerItemManagementRevokeInventoryItemWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_itemInstanceId, rhs.m_itemInstanceId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetItemInstanceId(String value)
    {
        m_itemInstanceId = std::move(value);
        this->m_model.itemInstanceId =  m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.itemInstanceId = m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_characterId;
    String m_itemInstanceId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementRevokeInventoryItemsRequestWrapper : public ModelWrapper<PFPlayerItemManagementRevokeInventoryItemsRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementRevokeInventoryItemsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementRevokeInventoryItemsRequestWrapper() = default;

    PFPlayerItemManagementRevokeInventoryItemsRequestWrapper(const PFPlayerItemManagementRevokeInventoryItemsRequest& model) :
        ModelWrapper<PFPlayerItemManagementRevokeInventoryItemsRequest, Alloc>{ model },
        m_items{ model.items, model.items + model.itemsCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementRevokeInventoryItemsRequestWrapper(const PFPlayerItemManagementRevokeInventoryItemsRequestWrapper& src) :
        PFPlayerItemManagementRevokeInventoryItemsRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementRevokeInventoryItemsRequestWrapper(PFPlayerItemManagementRevokeInventoryItemsRequestWrapper&& src) :
        PFPlayerItemManagementRevokeInventoryItemsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementRevokeInventoryItemsRequestWrapper& operator=(PFPlayerItemManagementRevokeInventoryItemsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementRevokeInventoryItemsRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementRevokeInventoryItemsRequestWrapper& lhs, PFPlayerItemManagementRevokeInventoryItemsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_items, rhs.m_items);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetItems(ModelVector<PFPlayerItemManagementRevokeInventoryItemWrapper<Alloc>, Alloc> value)
    {
        m_items = std::move(value);
        this->m_model.items =  m_items.empty() ? nullptr : m_items.data();
        this->m_model.itemsCount =  static_cast<uint32_t>(m_items.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.items = m_items.empty() ? nullptr : m_items.data();
    }

    ModelVector<PFPlayerItemManagementRevokeInventoryItemWrapper<Alloc>, Alloc> m_items;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementRevokeItemErrorWrapper : public ModelWrapper<PFPlayerItemManagementRevokeItemError, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementRevokeItemError;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementRevokeItemErrorWrapper() = default;

    PFPlayerItemManagementRevokeItemErrorWrapper(const PFPlayerItemManagementRevokeItemError& model) :
        ModelWrapper<PFPlayerItemManagementRevokeItemError, Alloc>{ model },
        m_error{ model.error ? StdExtra::optional<PFPlayerItemManagementGenericErrorCodes>{ *model.error } : StdExtra::nullopt },
        m_item{ model.item ? StdExtra::optional<PFPlayerItemManagementRevokeInventoryItemWrapper<Alloc>>{ *model.item } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementRevokeItemErrorWrapper(const PFPlayerItemManagementRevokeItemErrorWrapper& src) :
        PFPlayerItemManagementRevokeItemErrorWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementRevokeItemErrorWrapper(PFPlayerItemManagementRevokeItemErrorWrapper&& src) :
        PFPlayerItemManagementRevokeItemErrorWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementRevokeItemErrorWrapper& operator=(PFPlayerItemManagementRevokeItemErrorWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementRevokeItemErrorWrapper() = default;

    friend void swap(PFPlayerItemManagementRevokeItemErrorWrapper& lhs, PFPlayerItemManagementRevokeItemErrorWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_error, rhs.m_error);
        swap(lhs.m_item, rhs.m_item);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetError(StdExtra::optional<PFPlayerItemManagementGenericErrorCodes> value)
    {
        m_error = std::move(value);
        this->m_model.error = m_error ? m_error.operator->() : nullptr;
    }

    void SetItem(StdExtra::optional<PFPlayerItemManagementRevokeInventoryItemWrapper<Alloc>> value)
    {
        m_item = std::move(value);
        this->m_model.item = m_item ? &m_item->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.error = m_error ? m_error.operator->() : nullptr;
        this->m_model.item = m_item ?  &m_item->Model() : nullptr;
    }

    StdExtra::optional<PFPlayerItemManagementGenericErrorCodes> m_error;
    StdExtra::optional<PFPlayerItemManagementRevokeInventoryItemWrapper<Alloc>> m_item;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementRevokeInventoryItemsResultWrapper : public ModelWrapper<PFPlayerItemManagementRevokeInventoryItemsResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementRevokeInventoryItemsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementRevokeInventoryItemsResultWrapper() = default;

    PFPlayerItemManagementRevokeInventoryItemsResultWrapper(const PFPlayerItemManagementRevokeInventoryItemsResult& model) :
        ModelWrapper<PFPlayerItemManagementRevokeInventoryItemsResult, Alloc>{ model },
        m_errors{ model.errors, model.errors + model.errorsCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementRevokeInventoryItemsResultWrapper(const PFPlayerItemManagementRevokeInventoryItemsResultWrapper& src) :
        PFPlayerItemManagementRevokeInventoryItemsResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementRevokeInventoryItemsResultWrapper(PFPlayerItemManagementRevokeInventoryItemsResultWrapper&& src) :
        PFPlayerItemManagementRevokeInventoryItemsResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementRevokeInventoryItemsResultWrapper& operator=(PFPlayerItemManagementRevokeInventoryItemsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementRevokeInventoryItemsResultWrapper() = default;

    friend void swap(PFPlayerItemManagementRevokeInventoryItemsResultWrapper& lhs, PFPlayerItemManagementRevokeInventoryItemsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_errors, rhs.m_errors);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetErrors(ModelVector<PFPlayerItemManagementRevokeItemErrorWrapper<Alloc>, Alloc> value)
    {
        m_errors = std::move(value);
        this->m_model.errors =  m_errors.empty() ? nullptr : m_errors.data();
        this->m_model.errorsCount =  static_cast<uint32_t>(m_errors.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.errors = m_errors.empty() ? nullptr : m_errors.data();
    }

    ModelVector<PFPlayerItemManagementRevokeItemErrorWrapper<Alloc>, Alloc> m_errors;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper : public ModelWrapper<PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper() = default;

    PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper(const PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequest& model) :
        ModelWrapper<PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_virtualCurrency{ SafeString(model.virtualCurrency) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper(const PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper& src) :
        PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper(PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper&& src) :
        PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper& operator=(PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper& lhs, PFPlayerItemManagementAdminSubtractUserVirtualCurrencyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAmount(int32_t value)
    {
        this->m_model.amount = value;
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

    void SetVirtualCurrency(String value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
    String m_virtualCurrency;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper : public ModelWrapper<PFPlayerItemManagementClientAddUserVirtualCurrencyRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementClientAddUserVirtualCurrencyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper() = default;

    PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper(const PFPlayerItemManagementClientAddUserVirtualCurrencyRequest& model) :
        ModelWrapper<PFPlayerItemManagementClientAddUserVirtualCurrencyRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_virtualCurrency{ SafeString(model.virtualCurrency) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper(const PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper& src) :
        PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper(PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper&& src) :
        PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper& operator=(PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper& lhs, PFPlayerItemManagementClientAddUserVirtualCurrencyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAmount(int32_t value)
    {
        this->m_model.amount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetVirtualCurrency(String value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_virtualCurrency;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementConfirmPurchaseRequestWrapper : public ModelWrapper<PFPlayerItemManagementConfirmPurchaseRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementConfirmPurchaseRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementConfirmPurchaseRequestWrapper() = default;

    PFPlayerItemManagementConfirmPurchaseRequestWrapper(const PFPlayerItemManagementConfirmPurchaseRequest& model) :
        ModelWrapper<PFPlayerItemManagementConfirmPurchaseRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_orderId{ SafeString(model.orderId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementConfirmPurchaseRequestWrapper(const PFPlayerItemManagementConfirmPurchaseRequestWrapper& src) :
        PFPlayerItemManagementConfirmPurchaseRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementConfirmPurchaseRequestWrapper(PFPlayerItemManagementConfirmPurchaseRequestWrapper&& src) :
        PFPlayerItemManagementConfirmPurchaseRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementConfirmPurchaseRequestWrapper& operator=(PFPlayerItemManagementConfirmPurchaseRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementConfirmPurchaseRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementConfirmPurchaseRequestWrapper& lhs, PFPlayerItemManagementConfirmPurchaseRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_orderId, rhs.m_orderId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetOrderId(String value)
    {
        m_orderId = std::move(value);
        this->m_model.orderId =  m_orderId.empty() ? nullptr : m_orderId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.orderId = m_orderId.empty() ? nullptr : m_orderId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_orderId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementConfirmPurchaseResultWrapper : public ModelWrapper<PFPlayerItemManagementConfirmPurchaseResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementConfirmPurchaseResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementConfirmPurchaseResultWrapper() = default;

    PFPlayerItemManagementConfirmPurchaseResultWrapper(const PFPlayerItemManagementConfirmPurchaseResult& model) :
        ModelWrapper<PFPlayerItemManagementConfirmPurchaseResult, Alloc>{ model },
        m_items{ model.items, model.items + model.itemsCount },
        m_orderId{ SafeString(model.orderId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementConfirmPurchaseResultWrapper(const PFPlayerItemManagementConfirmPurchaseResultWrapper& src) :
        PFPlayerItemManagementConfirmPurchaseResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementConfirmPurchaseResultWrapper(PFPlayerItemManagementConfirmPurchaseResultWrapper&& src) :
        PFPlayerItemManagementConfirmPurchaseResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementConfirmPurchaseResultWrapper& operator=(PFPlayerItemManagementConfirmPurchaseResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementConfirmPurchaseResultWrapper() = default;

    friend void swap(PFPlayerItemManagementConfirmPurchaseResultWrapper& lhs, PFPlayerItemManagementConfirmPurchaseResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_items, rhs.m_items);
        swap(lhs.m_orderId, rhs.m_orderId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetItems(ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_items = std::move(value);
        this->m_model.items =  m_items.empty() ? nullptr : m_items.data();
        this->m_model.itemsCount =  static_cast<uint32_t>(m_items.size());
    }

    void SetOrderId(String value)
    {
        m_orderId = std::move(value);
        this->m_model.orderId =  m_orderId.empty() ? nullptr : m_orderId.data();
    }

    void SetPurchaseDate(time_t value)
    {
        this->m_model.purchaseDate = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.items = m_items.empty() ? nullptr : m_items.data();
        this->m_model.orderId = m_orderId.empty() ? nullptr : m_orderId.data();
    }

    ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> m_items;
    String m_orderId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementClientConsumeItemRequestWrapper : public ModelWrapper<PFPlayerItemManagementClientConsumeItemRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementClientConsumeItemRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementClientConsumeItemRequestWrapper() = default;

    PFPlayerItemManagementClientConsumeItemRequestWrapper(const PFPlayerItemManagementClientConsumeItemRequest& model) :
        ModelWrapper<PFPlayerItemManagementClientConsumeItemRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_itemInstanceId{ SafeString(model.itemInstanceId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementClientConsumeItemRequestWrapper(const PFPlayerItemManagementClientConsumeItemRequestWrapper& src) :
        PFPlayerItemManagementClientConsumeItemRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementClientConsumeItemRequestWrapper(PFPlayerItemManagementClientConsumeItemRequestWrapper&& src) :
        PFPlayerItemManagementClientConsumeItemRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementClientConsumeItemRequestWrapper& operator=(PFPlayerItemManagementClientConsumeItemRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementClientConsumeItemRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementClientConsumeItemRequestWrapper& lhs, PFPlayerItemManagementClientConsumeItemRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_itemInstanceId, rhs.m_itemInstanceId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetConsumeCount(int32_t value)
    {
        this->m_model.consumeCount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetItemInstanceId(String value)
    {
        m_itemInstanceId = std::move(value);
        this->m_model.itemInstanceId =  m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.itemInstanceId = m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
    }

    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_itemInstanceId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementConsumeItemResultWrapper : public ModelWrapper<PFPlayerItemManagementConsumeItemResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementConsumeItemResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementConsumeItemResultWrapper() = default;

    PFPlayerItemManagementConsumeItemResultWrapper(const PFPlayerItemManagementConsumeItemResult& model) :
        ModelWrapper<PFPlayerItemManagementConsumeItemResult, Alloc>{ model },
        m_itemInstanceId{ SafeString(model.itemInstanceId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementConsumeItemResultWrapper(const PFPlayerItemManagementConsumeItemResultWrapper& src) :
        PFPlayerItemManagementConsumeItemResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementConsumeItemResultWrapper(PFPlayerItemManagementConsumeItemResultWrapper&& src) :
        PFPlayerItemManagementConsumeItemResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementConsumeItemResultWrapper& operator=(PFPlayerItemManagementConsumeItemResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementConsumeItemResultWrapper() = default;

    friend void swap(PFPlayerItemManagementConsumeItemResultWrapper& lhs, PFPlayerItemManagementConsumeItemResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_itemInstanceId, rhs.m_itemInstanceId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetItemInstanceId(String value)
    {
        m_itemInstanceId = std::move(value);
        this->m_model.itemInstanceId =  m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
    }

    void SetRemainingUses(int32_t value)
    {
        this->m_model.remainingUses = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.itemInstanceId = m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
    }

    String m_itemInstanceId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper : public ModelWrapper<PFPlayerItemManagementClientGetCharacterInventoryRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementClientGetCharacterInventoryRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper() = default;

    PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper(const PFPlayerItemManagementClientGetCharacterInventoryRequest& model) :
        ModelWrapper<PFPlayerItemManagementClientGetCharacterInventoryRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper(const PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper& src) :
        PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper(PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper&& src) :
        PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper& operator=(PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper& lhs, PFPlayerItemManagementClientGetCharacterInventoryRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
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
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_catalogVersion;
    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementClientGetCharacterInventoryResultWrapper : public ModelWrapper<PFPlayerItemManagementClientGetCharacterInventoryResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementClientGetCharacterInventoryResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementClientGetCharacterInventoryResultWrapper() = default;

    PFPlayerItemManagementClientGetCharacterInventoryResultWrapper(const PFPlayerItemManagementClientGetCharacterInventoryResult& model) :
        ModelWrapper<PFPlayerItemManagementClientGetCharacterInventoryResult, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_inventory{ model.inventory, model.inventory + model.inventoryCount },
        m_virtualCurrency{ model.virtualCurrency, model.virtualCurrency + model.virtualCurrencyCount },
        m_virtualCurrencyRechargeTimes{ model.virtualCurrencyRechargeTimes, model.virtualCurrencyRechargeTimes + model.virtualCurrencyRechargeTimesCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementClientGetCharacterInventoryResultWrapper(const PFPlayerItemManagementClientGetCharacterInventoryResultWrapper& src) :
        PFPlayerItemManagementClientGetCharacterInventoryResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementClientGetCharacterInventoryResultWrapper(PFPlayerItemManagementClientGetCharacterInventoryResultWrapper&& src) :
        PFPlayerItemManagementClientGetCharacterInventoryResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementClientGetCharacterInventoryResultWrapper& operator=(PFPlayerItemManagementClientGetCharacterInventoryResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementClientGetCharacterInventoryResultWrapper() = default;

    friend void swap(PFPlayerItemManagementClientGetCharacterInventoryResultWrapper& lhs, PFPlayerItemManagementClientGetCharacterInventoryResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_inventory, rhs.m_inventory);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        swap(lhs.m_virtualCurrencyRechargeTimes, rhs.m_virtualCurrencyRechargeTimes);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetInventory(ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_inventory = std::move(value);
        this->m_model.inventory =  m_inventory.empty() ? nullptr : m_inventory.data();
        this->m_model.inventoryCount =  static_cast<uint32_t>(m_inventory.size());
    }

    void SetVirtualCurrency(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
        this->m_model.virtualCurrencyCount =  static_cast<uint32_t>(m_virtualCurrency.size());
    }

    void SetVirtualCurrencyRechargeTimes(ModelDictionaryEntryVector<PFVirtualCurrencyRechargeTimeWrapper<Alloc>, Alloc> value)
    {
        m_virtualCurrencyRechargeTimes = std::move(value);
        this->m_model.virtualCurrencyRechargeTimes =  m_virtualCurrencyRechargeTimes.empty() ? nullptr : m_virtualCurrencyRechargeTimes.data();
        this->m_model.virtualCurrencyRechargeTimesCount =  static_cast<uint32_t>(m_virtualCurrencyRechargeTimes.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.inventory = m_inventory.empty() ? nullptr : m_inventory.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
        this->m_model.virtualCurrencyRechargeTimes = m_virtualCurrencyRechargeTimes.empty() ? nullptr : m_virtualCurrencyRechargeTimes.data();
    }

    String m_characterId;
    ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> m_inventory;
    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_virtualCurrency;
    ModelDictionaryEntryVector<PFVirtualCurrencyRechargeTimeWrapper<Alloc>, Alloc> m_virtualCurrencyRechargeTimes;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementGetPaymentTokenRequestWrapper : public ModelWrapper<PFPlayerItemManagementGetPaymentTokenRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementGetPaymentTokenRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementGetPaymentTokenRequestWrapper() = default;

    PFPlayerItemManagementGetPaymentTokenRequestWrapper(const PFPlayerItemManagementGetPaymentTokenRequest& model) :
        ModelWrapper<PFPlayerItemManagementGetPaymentTokenRequest, Alloc>{ model },
        m_tokenProvider{ SafeString(model.tokenProvider) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementGetPaymentTokenRequestWrapper(const PFPlayerItemManagementGetPaymentTokenRequestWrapper& src) :
        PFPlayerItemManagementGetPaymentTokenRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementGetPaymentTokenRequestWrapper(PFPlayerItemManagementGetPaymentTokenRequestWrapper&& src) :
        PFPlayerItemManagementGetPaymentTokenRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementGetPaymentTokenRequestWrapper& operator=(PFPlayerItemManagementGetPaymentTokenRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementGetPaymentTokenRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementGetPaymentTokenRequestWrapper& lhs, PFPlayerItemManagementGetPaymentTokenRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_tokenProvider, rhs.m_tokenProvider);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetTokenProvider(String value)
    {
        m_tokenProvider = std::move(value);
        this->m_model.tokenProvider =  m_tokenProvider.empty() ? nullptr : m_tokenProvider.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.tokenProvider = m_tokenProvider.empty() ? nullptr : m_tokenProvider.data();
    }

    String m_tokenProvider;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementGetPaymentTokenResultWrapper : public ModelWrapper<PFPlayerItemManagementGetPaymentTokenResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementGetPaymentTokenResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementGetPaymentTokenResultWrapper() = default;

    PFPlayerItemManagementGetPaymentTokenResultWrapper(const PFPlayerItemManagementGetPaymentTokenResult& model) :
        ModelWrapper<PFPlayerItemManagementGetPaymentTokenResult, Alloc>{ model },
        m_orderId{ SafeString(model.orderId) },
        m_providerToken{ SafeString(model.providerToken) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementGetPaymentTokenResultWrapper(const PFPlayerItemManagementGetPaymentTokenResultWrapper& src) :
        PFPlayerItemManagementGetPaymentTokenResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementGetPaymentTokenResultWrapper(PFPlayerItemManagementGetPaymentTokenResultWrapper&& src) :
        PFPlayerItemManagementGetPaymentTokenResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementGetPaymentTokenResultWrapper& operator=(PFPlayerItemManagementGetPaymentTokenResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementGetPaymentTokenResultWrapper() = default;

    friend void swap(PFPlayerItemManagementGetPaymentTokenResultWrapper& lhs, PFPlayerItemManagementGetPaymentTokenResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_orderId, rhs.m_orderId);
        swap(lhs.m_providerToken, rhs.m_providerToken);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetOrderId(String value)
    {
        m_orderId = std::move(value);
        this->m_model.orderId =  m_orderId.empty() ? nullptr : m_orderId.data();
    }

    void SetProviderToken(String value)
    {
        m_providerToken = std::move(value);
        this->m_model.providerToken =  m_providerToken.empty() ? nullptr : m_providerToken.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.orderId = m_orderId.empty() ? nullptr : m_orderId.data();
        this->m_model.providerToken = m_providerToken.empty() ? nullptr : m_providerToken.data();
    }

    String m_orderId;
    String m_providerToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementGetPurchaseRequestWrapper : public ModelWrapper<PFPlayerItemManagementGetPurchaseRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementGetPurchaseRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementGetPurchaseRequestWrapper() = default;

    PFPlayerItemManagementGetPurchaseRequestWrapper(const PFPlayerItemManagementGetPurchaseRequest& model) :
        ModelWrapper<PFPlayerItemManagementGetPurchaseRequest, Alloc>{ model },
        m_orderId{ SafeString(model.orderId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementGetPurchaseRequestWrapper(const PFPlayerItemManagementGetPurchaseRequestWrapper& src) :
        PFPlayerItemManagementGetPurchaseRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementGetPurchaseRequestWrapper(PFPlayerItemManagementGetPurchaseRequestWrapper&& src) :
        PFPlayerItemManagementGetPurchaseRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementGetPurchaseRequestWrapper& operator=(PFPlayerItemManagementGetPurchaseRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementGetPurchaseRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementGetPurchaseRequestWrapper& lhs, PFPlayerItemManagementGetPurchaseRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_orderId, rhs.m_orderId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetOrderId(String value)
    {
        m_orderId = std::move(value);
        this->m_model.orderId =  m_orderId.empty() ? nullptr : m_orderId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.orderId = m_orderId.empty() ? nullptr : m_orderId.data();
    }

    String m_orderId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementGetPurchaseResultWrapper : public ModelWrapper<PFPlayerItemManagementGetPurchaseResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementGetPurchaseResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementGetPurchaseResultWrapper() = default;

    PFPlayerItemManagementGetPurchaseResultWrapper(const PFPlayerItemManagementGetPurchaseResult& model) :
        ModelWrapper<PFPlayerItemManagementGetPurchaseResult, Alloc>{ model },
        m_orderId{ SafeString(model.orderId) },
        m_paymentProvider{ SafeString(model.paymentProvider) },
        m_transactionId{ SafeString(model.transactionId) },
        m_transactionStatus{ SafeString(model.transactionStatus) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementGetPurchaseResultWrapper(const PFPlayerItemManagementGetPurchaseResultWrapper& src) :
        PFPlayerItemManagementGetPurchaseResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementGetPurchaseResultWrapper(PFPlayerItemManagementGetPurchaseResultWrapper&& src) :
        PFPlayerItemManagementGetPurchaseResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementGetPurchaseResultWrapper& operator=(PFPlayerItemManagementGetPurchaseResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementGetPurchaseResultWrapper() = default;

    friend void swap(PFPlayerItemManagementGetPurchaseResultWrapper& lhs, PFPlayerItemManagementGetPurchaseResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_orderId, rhs.m_orderId);
        swap(lhs.m_paymentProvider, rhs.m_paymentProvider);
        swap(lhs.m_transactionId, rhs.m_transactionId);
        swap(lhs.m_transactionStatus, rhs.m_transactionStatus);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetOrderId(String value)
    {
        m_orderId = std::move(value);
        this->m_model.orderId =  m_orderId.empty() ? nullptr : m_orderId.data();
    }

    void SetPaymentProvider(String value)
    {
        m_paymentProvider = std::move(value);
        this->m_model.paymentProvider =  m_paymentProvider.empty() ? nullptr : m_paymentProvider.data();
    }

    void SetPurchaseDate(time_t value)
    {
        this->m_model.purchaseDate = value;
    }

    void SetTransactionId(String value)
    {
        m_transactionId = std::move(value);
        this->m_model.transactionId =  m_transactionId.empty() ? nullptr : m_transactionId.data();
    }

    void SetTransactionStatus(String value)
    {
        m_transactionStatus = std::move(value);
        this->m_model.transactionStatus =  m_transactionStatus.empty() ? nullptr : m_transactionStatus.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.orderId = m_orderId.empty() ? nullptr : m_orderId.data();
        this->m_model.paymentProvider = m_paymentProvider.empty() ? nullptr : m_paymentProvider.data();
        this->m_model.transactionId = m_transactionId.empty() ? nullptr : m_transactionId.data();
        this->m_model.transactionStatus = m_transactionStatus.empty() ? nullptr : m_transactionStatus.data();
    }

    String m_orderId;
    String m_paymentProvider;
    String m_transactionId;
    String m_transactionStatus;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementClientGetUserInventoryRequestWrapper : public ModelWrapper<PFPlayerItemManagementClientGetUserInventoryRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementClientGetUserInventoryRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementClientGetUserInventoryRequestWrapper() = default;

    PFPlayerItemManagementClientGetUserInventoryRequestWrapper(const PFPlayerItemManagementClientGetUserInventoryRequest& model) :
        ModelWrapper<PFPlayerItemManagementClientGetUserInventoryRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementClientGetUserInventoryRequestWrapper(const PFPlayerItemManagementClientGetUserInventoryRequestWrapper& src) :
        PFPlayerItemManagementClientGetUserInventoryRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementClientGetUserInventoryRequestWrapper(PFPlayerItemManagementClientGetUserInventoryRequestWrapper&& src) :
        PFPlayerItemManagementClientGetUserInventoryRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementClientGetUserInventoryRequestWrapper& operator=(PFPlayerItemManagementClientGetUserInventoryRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementClientGetUserInventoryRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementClientGetUserInventoryRequestWrapper& lhs, PFPlayerItemManagementClientGetUserInventoryRequestWrapper& rhs)
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
class PFPlayerItemManagementClientGetUserInventoryResultWrapper : public ModelWrapper<PFPlayerItemManagementClientGetUserInventoryResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementClientGetUserInventoryResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementClientGetUserInventoryResultWrapper() = default;

    PFPlayerItemManagementClientGetUserInventoryResultWrapper(const PFPlayerItemManagementClientGetUserInventoryResult& model) :
        ModelWrapper<PFPlayerItemManagementClientGetUserInventoryResult, Alloc>{ model },
        m_inventory{ model.inventory, model.inventory + model.inventoryCount },
        m_virtualCurrency{ model.virtualCurrency, model.virtualCurrency + model.virtualCurrencyCount },
        m_virtualCurrencyRechargeTimes{ model.virtualCurrencyRechargeTimes, model.virtualCurrencyRechargeTimes + model.virtualCurrencyRechargeTimesCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementClientGetUserInventoryResultWrapper(const PFPlayerItemManagementClientGetUserInventoryResultWrapper& src) :
        PFPlayerItemManagementClientGetUserInventoryResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementClientGetUserInventoryResultWrapper(PFPlayerItemManagementClientGetUserInventoryResultWrapper&& src) :
        PFPlayerItemManagementClientGetUserInventoryResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementClientGetUserInventoryResultWrapper& operator=(PFPlayerItemManagementClientGetUserInventoryResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementClientGetUserInventoryResultWrapper() = default;

    friend void swap(PFPlayerItemManagementClientGetUserInventoryResultWrapper& lhs, PFPlayerItemManagementClientGetUserInventoryResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_inventory, rhs.m_inventory);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        swap(lhs.m_virtualCurrencyRechargeTimes, rhs.m_virtualCurrencyRechargeTimes);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetInventory(ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_inventory = std::move(value);
        this->m_model.inventory =  m_inventory.empty() ? nullptr : m_inventory.data();
        this->m_model.inventoryCount =  static_cast<uint32_t>(m_inventory.size());
    }

    void SetVirtualCurrency(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
        this->m_model.virtualCurrencyCount =  static_cast<uint32_t>(m_virtualCurrency.size());
    }

    void SetVirtualCurrencyRechargeTimes(ModelDictionaryEntryVector<PFVirtualCurrencyRechargeTimeWrapper<Alloc>, Alloc> value)
    {
        m_virtualCurrencyRechargeTimes = std::move(value);
        this->m_model.virtualCurrencyRechargeTimes =  m_virtualCurrencyRechargeTimes.empty() ? nullptr : m_virtualCurrencyRechargeTimes.data();
        this->m_model.virtualCurrencyRechargeTimesCount =  static_cast<uint32_t>(m_virtualCurrencyRechargeTimes.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.inventory = m_inventory.empty() ? nullptr : m_inventory.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
        this->m_model.virtualCurrencyRechargeTimes = m_virtualCurrencyRechargeTimes.empty() ? nullptr : m_virtualCurrencyRechargeTimes.data();
    }

    ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> m_inventory;
    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_virtualCurrency;
    ModelDictionaryEntryVector<PFVirtualCurrencyRechargeTimeWrapper<Alloc>, Alloc> m_virtualCurrencyRechargeTimes;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementPayForPurchaseRequestWrapper : public ModelWrapper<PFPlayerItemManagementPayForPurchaseRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementPayForPurchaseRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementPayForPurchaseRequestWrapper() = default;

    PFPlayerItemManagementPayForPurchaseRequestWrapper(const PFPlayerItemManagementPayForPurchaseRequest& model) :
        ModelWrapper<PFPlayerItemManagementPayForPurchaseRequest, Alloc>{ model },
        m_currency{ SafeString(model.currency) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_orderId{ SafeString(model.orderId) },
        m_providerName{ SafeString(model.providerName) },
        m_providerTransactionId{ SafeString(model.providerTransactionId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementPayForPurchaseRequestWrapper(const PFPlayerItemManagementPayForPurchaseRequestWrapper& src) :
        PFPlayerItemManagementPayForPurchaseRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementPayForPurchaseRequestWrapper(PFPlayerItemManagementPayForPurchaseRequestWrapper&& src) :
        PFPlayerItemManagementPayForPurchaseRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementPayForPurchaseRequestWrapper& operator=(PFPlayerItemManagementPayForPurchaseRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementPayForPurchaseRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementPayForPurchaseRequestWrapper& lhs, PFPlayerItemManagementPayForPurchaseRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_currency, rhs.m_currency);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_orderId, rhs.m_orderId);
        swap(lhs.m_providerName, rhs.m_providerName);
        swap(lhs.m_providerTransactionId, rhs.m_providerTransactionId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCurrency(String value)
    {
        m_currency = std::move(value);
        this->m_model.currency =  m_currency.empty() ? nullptr : m_currency.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetOrderId(String value)
    {
        m_orderId = std::move(value);
        this->m_model.orderId =  m_orderId.empty() ? nullptr : m_orderId.data();
    }

    void SetProviderName(String value)
    {
        m_providerName = std::move(value);
        this->m_model.providerName =  m_providerName.empty() ? nullptr : m_providerName.data();
    }

    void SetProviderTransactionId(String value)
    {
        m_providerTransactionId = std::move(value);
        this->m_model.providerTransactionId =  m_providerTransactionId.empty() ? nullptr : m_providerTransactionId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.currency = m_currency.empty() ? nullptr : m_currency.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.orderId = m_orderId.empty() ? nullptr : m_orderId.data();
        this->m_model.providerName = m_providerName.empty() ? nullptr : m_providerName.data();
        this->m_model.providerTransactionId = m_providerTransactionId.empty() ? nullptr : m_providerTransactionId.data();
    }

    String m_currency;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_orderId;
    String m_providerName;
    String m_providerTransactionId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementPayForPurchaseResultWrapper : public ModelWrapper<PFPlayerItemManagementPayForPurchaseResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementPayForPurchaseResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementPayForPurchaseResultWrapper() = default;

    PFPlayerItemManagementPayForPurchaseResultWrapper(const PFPlayerItemManagementPayForPurchaseResult& model) :
        ModelWrapper<PFPlayerItemManagementPayForPurchaseResult, Alloc>{ model },
        m_orderId{ SafeString(model.orderId) },
        m_providerData{ SafeString(model.providerData) },
        m_providerToken{ SafeString(model.providerToken) },
        m_purchaseConfirmationPageURL{ SafeString(model.purchaseConfirmationPageURL) },
        m_purchaseCurrency{ SafeString(model.purchaseCurrency) },
        m_status{ model.status ? StdExtra::optional<PFPlayerItemManagementTransactionStatus>{ *model.status } : StdExtra::nullopt },
        m_vCAmount{ model.vCAmount, model.vCAmount + model.vCAmountCount },
        m_virtualCurrency{ model.virtualCurrency, model.virtualCurrency + model.virtualCurrencyCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementPayForPurchaseResultWrapper(const PFPlayerItemManagementPayForPurchaseResultWrapper& src) :
        PFPlayerItemManagementPayForPurchaseResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementPayForPurchaseResultWrapper(PFPlayerItemManagementPayForPurchaseResultWrapper&& src) :
        PFPlayerItemManagementPayForPurchaseResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementPayForPurchaseResultWrapper& operator=(PFPlayerItemManagementPayForPurchaseResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementPayForPurchaseResultWrapper() = default;

    friend void swap(PFPlayerItemManagementPayForPurchaseResultWrapper& lhs, PFPlayerItemManagementPayForPurchaseResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_orderId, rhs.m_orderId);
        swap(lhs.m_providerData, rhs.m_providerData);
        swap(lhs.m_providerToken, rhs.m_providerToken);
        swap(lhs.m_purchaseConfirmationPageURL, rhs.m_purchaseConfirmationPageURL);
        swap(lhs.m_purchaseCurrency, rhs.m_purchaseCurrency);
        swap(lhs.m_status, rhs.m_status);
        swap(lhs.m_vCAmount, rhs.m_vCAmount);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCreditApplied(uint32_t value)
    {
        this->m_model.creditApplied = value;
    }

    void SetOrderId(String value)
    {
        m_orderId = std::move(value);
        this->m_model.orderId =  m_orderId.empty() ? nullptr : m_orderId.data();
    }

    void SetProviderData(String value)
    {
        m_providerData = std::move(value);
        this->m_model.providerData =  m_providerData.empty() ? nullptr : m_providerData.data();
    }

    void SetProviderToken(String value)
    {
        m_providerToken = std::move(value);
        this->m_model.providerToken =  m_providerToken.empty() ? nullptr : m_providerToken.data();
    }

    void SetPurchaseConfirmationPageURL(String value)
    {
        m_purchaseConfirmationPageURL = std::move(value);
        this->m_model.purchaseConfirmationPageURL =  m_purchaseConfirmationPageURL.empty() ? nullptr : m_purchaseConfirmationPageURL.data();
    }

    void SetPurchaseCurrency(String value)
    {
        m_purchaseCurrency = std::move(value);
        this->m_model.purchaseCurrency =  m_purchaseCurrency.empty() ? nullptr : m_purchaseCurrency.data();
    }

    void SetPurchasePrice(uint32_t value)
    {
        this->m_model.purchasePrice = value;
    }

    void SetStatus(StdExtra::optional<PFPlayerItemManagementTransactionStatus> value)
    {
        m_status = std::move(value);
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

    void SetVCAmount(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_vCAmount = std::move(value);
        this->m_model.vCAmount =  m_vCAmount.empty() ? nullptr : m_vCAmount.data();
        this->m_model.vCAmountCount =  static_cast<uint32_t>(m_vCAmount.size());
    }

    void SetVirtualCurrency(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
        this->m_model.virtualCurrencyCount =  static_cast<uint32_t>(m_virtualCurrency.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.orderId = m_orderId.empty() ? nullptr : m_orderId.data();
        this->m_model.providerData = m_providerData.empty() ? nullptr : m_providerData.data();
        this->m_model.providerToken = m_providerToken.empty() ? nullptr : m_providerToken.data();
        this->m_model.purchaseConfirmationPageURL = m_purchaseConfirmationPageURL.empty() ? nullptr : m_purchaseConfirmationPageURL.data();
        this->m_model.purchaseCurrency = m_purchaseCurrency.empty() ? nullptr : m_purchaseCurrency.data();
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
        this->m_model.vCAmount = m_vCAmount.empty() ? nullptr : m_vCAmount.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

    String m_orderId;
    String m_providerData;
    String m_providerToken;
    String m_purchaseConfirmationPageURL;
    String m_purchaseCurrency;
    StdExtra::optional<PFPlayerItemManagementTransactionStatus> m_status;
    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_vCAmount;
    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_virtualCurrency;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementPurchaseItemRequestWrapper : public ModelWrapper<PFPlayerItemManagementPurchaseItemRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementPurchaseItemRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementPurchaseItemRequestWrapper() = default;

    PFPlayerItemManagementPurchaseItemRequestWrapper(const PFPlayerItemManagementPurchaseItemRequest& model) :
        ModelWrapper<PFPlayerItemManagementPurchaseItemRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_itemId{ SafeString(model.itemId) },
        m_storeId{ SafeString(model.storeId) },
        m_virtualCurrency{ SafeString(model.virtualCurrency) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementPurchaseItemRequestWrapper(const PFPlayerItemManagementPurchaseItemRequestWrapper& src) :
        PFPlayerItemManagementPurchaseItemRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementPurchaseItemRequestWrapper(PFPlayerItemManagementPurchaseItemRequestWrapper&& src) :
        PFPlayerItemManagementPurchaseItemRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementPurchaseItemRequestWrapper& operator=(PFPlayerItemManagementPurchaseItemRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementPurchaseItemRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementPurchaseItemRequestWrapper& lhs, PFPlayerItemManagementPurchaseItemRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_itemId, rhs.m_itemId);
        swap(lhs.m_storeId, rhs.m_storeId);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetItemId(String value)
    {
        m_itemId = std::move(value);
        this->m_model.itemId =  m_itemId.empty() ? nullptr : m_itemId.data();
    }

    void SetPrice(int32_t value)
    {
        this->m_model.price = value;
    }

    void SetStoreId(String value)
    {
        m_storeId = std::move(value);
        this->m_model.storeId =  m_storeId.empty() ? nullptr : m_storeId.data();
    }

    void SetVirtualCurrency(String value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.itemId = m_itemId.empty() ? nullptr : m_itemId.data();
        this->m_model.storeId = m_storeId.empty() ? nullptr : m_storeId.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

    String m_catalogVersion;
    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_itemId;
    String m_storeId;
    String m_virtualCurrency;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementPurchaseItemResultWrapper : public ModelWrapper<PFPlayerItemManagementPurchaseItemResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementPurchaseItemResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementPurchaseItemResultWrapper() = default;

    PFPlayerItemManagementPurchaseItemResultWrapper(const PFPlayerItemManagementPurchaseItemResult& model) :
        ModelWrapper<PFPlayerItemManagementPurchaseItemResult, Alloc>{ model },
        m_items{ model.items, model.items + model.itemsCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementPurchaseItemResultWrapper(const PFPlayerItemManagementPurchaseItemResultWrapper& src) :
        PFPlayerItemManagementPurchaseItemResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementPurchaseItemResultWrapper(PFPlayerItemManagementPurchaseItemResultWrapper&& src) :
        PFPlayerItemManagementPurchaseItemResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementPurchaseItemResultWrapper& operator=(PFPlayerItemManagementPurchaseItemResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementPurchaseItemResultWrapper() = default;

    friend void swap(PFPlayerItemManagementPurchaseItemResultWrapper& lhs, PFPlayerItemManagementPurchaseItemResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_items, rhs.m_items);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetItems(ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_items = std::move(value);
        this->m_model.items =  m_items.empty() ? nullptr : m_items.data();
        this->m_model.itemsCount =  static_cast<uint32_t>(m_items.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.items = m_items.empty() ? nullptr : m_items.data();
    }

    ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> m_items;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementClientRedeemCouponRequestWrapper : public ModelWrapper<PFPlayerItemManagementClientRedeemCouponRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementClientRedeemCouponRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementClientRedeemCouponRequestWrapper() = default;

    PFPlayerItemManagementClientRedeemCouponRequestWrapper(const PFPlayerItemManagementClientRedeemCouponRequest& model) :
        ModelWrapper<PFPlayerItemManagementClientRedeemCouponRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_characterId{ SafeString(model.characterId) },
        m_couponCode{ SafeString(model.couponCode) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementClientRedeemCouponRequestWrapper(const PFPlayerItemManagementClientRedeemCouponRequestWrapper& src) :
        PFPlayerItemManagementClientRedeemCouponRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementClientRedeemCouponRequestWrapper(PFPlayerItemManagementClientRedeemCouponRequestWrapper&& src) :
        PFPlayerItemManagementClientRedeemCouponRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementClientRedeemCouponRequestWrapper& operator=(PFPlayerItemManagementClientRedeemCouponRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementClientRedeemCouponRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementClientRedeemCouponRequestWrapper& lhs, PFPlayerItemManagementClientRedeemCouponRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_couponCode, rhs.m_couponCode);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetCouponCode(String value)
    {
        m_couponCode = std::move(value);
        this->m_model.couponCode =  m_couponCode.empty() ? nullptr : m_couponCode.data();
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
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.couponCode = m_couponCode.empty() ? nullptr : m_couponCode.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_catalogVersion;
    String m_characterId;
    String m_couponCode;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementRedeemCouponResultWrapper : public ModelWrapper<PFPlayerItemManagementRedeemCouponResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementRedeemCouponResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementRedeemCouponResultWrapper() = default;

    PFPlayerItemManagementRedeemCouponResultWrapper(const PFPlayerItemManagementRedeemCouponResult& model) :
        ModelWrapper<PFPlayerItemManagementRedeemCouponResult, Alloc>{ model },
        m_grantedItems{ model.grantedItems, model.grantedItems + model.grantedItemsCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementRedeemCouponResultWrapper(const PFPlayerItemManagementRedeemCouponResultWrapper& src) :
        PFPlayerItemManagementRedeemCouponResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementRedeemCouponResultWrapper(PFPlayerItemManagementRedeemCouponResultWrapper&& src) :
        PFPlayerItemManagementRedeemCouponResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementRedeemCouponResultWrapper& operator=(PFPlayerItemManagementRedeemCouponResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementRedeemCouponResultWrapper() = default;

    friend void swap(PFPlayerItemManagementRedeemCouponResultWrapper& lhs, PFPlayerItemManagementRedeemCouponResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_grantedItems, rhs.m_grantedItems);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGrantedItems(ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_grantedItems = std::move(value);
        this->m_model.grantedItems =  m_grantedItems.empty() ? nullptr : m_grantedItems.data();
        this->m_model.grantedItemsCount =  static_cast<uint32_t>(m_grantedItems.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.grantedItems = m_grantedItems.empty() ? nullptr : m_grantedItems.data();
    }

    ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> m_grantedItems;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementItemPurchaseRequestWrapper : public ModelWrapper<PFPlayerItemManagementItemPurchaseRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementItemPurchaseRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementItemPurchaseRequestWrapper() = default;

    PFPlayerItemManagementItemPurchaseRequestWrapper(const PFPlayerItemManagementItemPurchaseRequest& model) :
        ModelWrapper<PFPlayerItemManagementItemPurchaseRequest, Alloc>{ model },
        m_annotation{ SafeString(model.annotation) },
        m_itemId{ SafeString(model.itemId) },
        m_upgradeFromItems{ model.upgradeFromItems, model.upgradeFromItems + model.upgradeFromItemsCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementItemPurchaseRequestWrapper(const PFPlayerItemManagementItemPurchaseRequestWrapper& src) :
        PFPlayerItemManagementItemPurchaseRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementItemPurchaseRequestWrapper(PFPlayerItemManagementItemPurchaseRequestWrapper&& src) :
        PFPlayerItemManagementItemPurchaseRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementItemPurchaseRequestWrapper& operator=(PFPlayerItemManagementItemPurchaseRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementItemPurchaseRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementItemPurchaseRequestWrapper& lhs, PFPlayerItemManagementItemPurchaseRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_annotation, rhs.m_annotation);
        swap(lhs.m_itemId, rhs.m_itemId);
        swap(lhs.m_upgradeFromItems, rhs.m_upgradeFromItems);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAnnotation(String value)
    {
        m_annotation = std::move(value);
        this->m_model.annotation =  m_annotation.empty() ? nullptr : m_annotation.data();
    }

    void SetItemId(String value)
    {
        m_itemId = std::move(value);
        this->m_model.itemId =  m_itemId.empty() ? nullptr : m_itemId.data();
    }

    void SetQuantity(uint32_t value)
    {
        this->m_model.quantity = value;
    }

    void SetUpgradeFromItems(CStringVector<Alloc> value)
    {
        m_upgradeFromItems = std::move(value);
        this->m_model.upgradeFromItems =  m_upgradeFromItems.empty() ? nullptr : m_upgradeFromItems.data();
        this->m_model.upgradeFromItemsCount =  static_cast<uint32_t>(m_upgradeFromItems.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.annotation = m_annotation.empty() ? nullptr : m_annotation.data();
        this->m_model.itemId = m_itemId.empty() ? nullptr : m_itemId.data();
        this->m_model.upgradeFromItems = m_upgradeFromItems.empty() ? nullptr : m_upgradeFromItems.data();
    }

    String m_annotation;
    String m_itemId;
    CStringVector<Alloc> m_upgradeFromItems;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementStartPurchaseRequestWrapper : public ModelWrapper<PFPlayerItemManagementStartPurchaseRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementStartPurchaseRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementStartPurchaseRequestWrapper() = default;

    PFPlayerItemManagementStartPurchaseRequestWrapper(const PFPlayerItemManagementStartPurchaseRequest& model) :
        ModelWrapper<PFPlayerItemManagementStartPurchaseRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_items{ model.items, model.items + model.itemsCount },
        m_storeId{ SafeString(model.storeId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementStartPurchaseRequestWrapper(const PFPlayerItemManagementStartPurchaseRequestWrapper& src) :
        PFPlayerItemManagementStartPurchaseRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementStartPurchaseRequestWrapper(PFPlayerItemManagementStartPurchaseRequestWrapper&& src) :
        PFPlayerItemManagementStartPurchaseRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementStartPurchaseRequestWrapper& operator=(PFPlayerItemManagementStartPurchaseRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementStartPurchaseRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementStartPurchaseRequestWrapper& lhs, PFPlayerItemManagementStartPurchaseRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_items, rhs.m_items);
        swap(lhs.m_storeId, rhs.m_storeId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetItems(ModelVector<PFPlayerItemManagementItemPurchaseRequestWrapper<Alloc>, Alloc> value)
    {
        m_items = std::move(value);
        this->m_model.items =  m_items.empty() ? nullptr : m_items.data();
        this->m_model.itemsCount =  static_cast<uint32_t>(m_items.size());
    }

    void SetStoreId(String value)
    {
        m_storeId = std::move(value);
        this->m_model.storeId =  m_storeId.empty() ? nullptr : m_storeId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.items = m_items.empty() ? nullptr : m_items.data();
        this->m_model.storeId = m_storeId.empty() ? nullptr : m_storeId.data();
    }

    String m_catalogVersion;
    StringDictionaryEntryVector<Alloc> m_customTags;
    ModelVector<PFPlayerItemManagementItemPurchaseRequestWrapper<Alloc>, Alloc> m_items;
    String m_storeId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementCartItemWrapper : public ModelWrapper<PFPlayerItemManagementCartItem, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementCartItem;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementCartItemWrapper() = default;

    PFPlayerItemManagementCartItemWrapper(const PFPlayerItemManagementCartItem& model) :
        ModelWrapper<PFPlayerItemManagementCartItem, Alloc>{ model },
        m_description{ SafeString(model.description) },
        m_displayName{ SafeString(model.displayName) },
        m_itemClass{ SafeString(model.itemClass) },
        m_itemId{ SafeString(model.itemId) },
        m_itemInstanceId{ SafeString(model.itemInstanceId) },
        m_realCurrencyPrices{ model.realCurrencyPrices, model.realCurrencyPrices + model.realCurrencyPricesCount },
        m_vCAmount{ model.vCAmount, model.vCAmount + model.vCAmountCount },
        m_virtualCurrencyPrices{ model.virtualCurrencyPrices, model.virtualCurrencyPrices + model.virtualCurrencyPricesCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementCartItemWrapper(const PFPlayerItemManagementCartItemWrapper& src) :
        PFPlayerItemManagementCartItemWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementCartItemWrapper(PFPlayerItemManagementCartItemWrapper&& src) :
        PFPlayerItemManagementCartItemWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementCartItemWrapper& operator=(PFPlayerItemManagementCartItemWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementCartItemWrapper() = default;

    friend void swap(PFPlayerItemManagementCartItemWrapper& lhs, PFPlayerItemManagementCartItemWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_description, rhs.m_description);
        swap(lhs.m_displayName, rhs.m_displayName);
        swap(lhs.m_itemClass, rhs.m_itemClass);
        swap(lhs.m_itemId, rhs.m_itemId);
        swap(lhs.m_itemInstanceId, rhs.m_itemInstanceId);
        swap(lhs.m_realCurrencyPrices, rhs.m_realCurrencyPrices);
        swap(lhs.m_vCAmount, rhs.m_vCAmount);
        swap(lhs.m_virtualCurrencyPrices, rhs.m_virtualCurrencyPrices);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDescription(String value)
    {
        m_description = std::move(value);
        this->m_model.description =  m_description.empty() ? nullptr : m_description.data();
    }

    void SetDisplayName(String value)
    {
        m_displayName = std::move(value);
        this->m_model.displayName =  m_displayName.empty() ? nullptr : m_displayName.data();
    }

    void SetItemClass(String value)
    {
        m_itemClass = std::move(value);
        this->m_model.itemClass =  m_itemClass.empty() ? nullptr : m_itemClass.data();
    }

    void SetItemId(String value)
    {
        m_itemId = std::move(value);
        this->m_model.itemId =  m_itemId.empty() ? nullptr : m_itemId.data();
    }

    void SetItemInstanceId(String value)
    {
        m_itemInstanceId = std::move(value);
        this->m_model.itemInstanceId =  m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
    }

    void SetRealCurrencyPrices(DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> value)
    {
        m_realCurrencyPrices = std::move(value);
        this->m_model.realCurrencyPrices =  m_realCurrencyPrices.empty() ? nullptr : m_realCurrencyPrices.data();
        this->m_model.realCurrencyPricesCount =  static_cast<uint32_t>(m_realCurrencyPrices.size());
    }

    void SetVCAmount(DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> value)
    {
        m_vCAmount = std::move(value);
        this->m_model.vCAmount =  m_vCAmount.empty() ? nullptr : m_vCAmount.data();
        this->m_model.vCAmountCount =  static_cast<uint32_t>(m_vCAmount.size());
    }

    void SetVirtualCurrencyPrices(DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> value)
    {
        m_virtualCurrencyPrices = std::move(value);
        this->m_model.virtualCurrencyPrices =  m_virtualCurrencyPrices.empty() ? nullptr : m_virtualCurrencyPrices.data();
        this->m_model.virtualCurrencyPricesCount =  static_cast<uint32_t>(m_virtualCurrencyPrices.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
        this->m_model.displayName = m_displayName.empty() ? nullptr : m_displayName.data();
        this->m_model.itemClass = m_itemClass.empty() ? nullptr : m_itemClass.data();
        this->m_model.itemId = m_itemId.empty() ? nullptr : m_itemId.data();
        this->m_model.itemInstanceId = m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
        this->m_model.realCurrencyPrices = m_realCurrencyPrices.empty() ? nullptr : m_realCurrencyPrices.data();
        this->m_model.vCAmount = m_vCAmount.empty() ? nullptr : m_vCAmount.data();
        this->m_model.virtualCurrencyPrices = m_virtualCurrencyPrices.empty() ? nullptr : m_virtualCurrencyPrices.data();
    }

    String m_description;
    String m_displayName;
    String m_itemClass;
    String m_itemId;
    String m_itemInstanceId;
    DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> m_realCurrencyPrices;
    DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> m_vCAmount;
    DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> m_virtualCurrencyPrices;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementPaymentOptionWrapper : public ModelWrapper<PFPlayerItemManagementPaymentOption, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementPaymentOption;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementPaymentOptionWrapper() = default;

    PFPlayerItemManagementPaymentOptionWrapper(const PFPlayerItemManagementPaymentOption& model) :
        ModelWrapper<PFPlayerItemManagementPaymentOption, Alloc>{ model },
        m_currency{ SafeString(model.currency) },
        m_providerName{ SafeString(model.providerName) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementPaymentOptionWrapper(const PFPlayerItemManagementPaymentOptionWrapper& src) :
        PFPlayerItemManagementPaymentOptionWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementPaymentOptionWrapper(PFPlayerItemManagementPaymentOptionWrapper&& src) :
        PFPlayerItemManagementPaymentOptionWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementPaymentOptionWrapper& operator=(PFPlayerItemManagementPaymentOptionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementPaymentOptionWrapper() = default;

    friend void swap(PFPlayerItemManagementPaymentOptionWrapper& lhs, PFPlayerItemManagementPaymentOptionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_currency, rhs.m_currency);
        swap(lhs.m_providerName, rhs.m_providerName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCurrency(String value)
    {
        m_currency = std::move(value);
        this->m_model.currency =  m_currency.empty() ? nullptr : m_currency.data();
    }

    void SetPrice(uint32_t value)
    {
        this->m_model.price = value;
    }

    void SetProviderName(String value)
    {
        m_providerName = std::move(value);
        this->m_model.providerName =  m_providerName.empty() ? nullptr : m_providerName.data();
    }

    void SetStoreCredit(uint32_t value)
    {
        this->m_model.storeCredit = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.currency = m_currency.empty() ? nullptr : m_currency.data();
        this->m_model.providerName = m_providerName.empty() ? nullptr : m_providerName.data();
    }

    String m_currency;
    String m_providerName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementStartPurchaseResultWrapper : public ModelWrapper<PFPlayerItemManagementStartPurchaseResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementStartPurchaseResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementStartPurchaseResultWrapper() = default;

    PFPlayerItemManagementStartPurchaseResultWrapper(const PFPlayerItemManagementStartPurchaseResult& model) :
        ModelWrapper<PFPlayerItemManagementStartPurchaseResult, Alloc>{ model },
        m_contents{ model.contents, model.contents + model.contentsCount },
        m_orderId{ SafeString(model.orderId) },
        m_paymentOptions{ model.paymentOptions, model.paymentOptions + model.paymentOptionsCount },
        m_virtualCurrencyBalances{ model.virtualCurrencyBalances, model.virtualCurrencyBalances + model.virtualCurrencyBalancesCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementStartPurchaseResultWrapper(const PFPlayerItemManagementStartPurchaseResultWrapper& src) :
        PFPlayerItemManagementStartPurchaseResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementStartPurchaseResultWrapper(PFPlayerItemManagementStartPurchaseResultWrapper&& src) :
        PFPlayerItemManagementStartPurchaseResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementStartPurchaseResultWrapper& operator=(PFPlayerItemManagementStartPurchaseResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementStartPurchaseResultWrapper() = default;

    friend void swap(PFPlayerItemManagementStartPurchaseResultWrapper& lhs, PFPlayerItemManagementStartPurchaseResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_contents, rhs.m_contents);
        swap(lhs.m_orderId, rhs.m_orderId);
        swap(lhs.m_paymentOptions, rhs.m_paymentOptions);
        swap(lhs.m_virtualCurrencyBalances, rhs.m_virtualCurrencyBalances);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetContents(ModelVector<PFPlayerItemManagementCartItemWrapper<Alloc>, Alloc> value)
    {
        m_contents = std::move(value);
        this->m_model.contents =  m_contents.empty() ? nullptr : m_contents.data();
        this->m_model.contentsCount =  static_cast<uint32_t>(m_contents.size());
    }

    void SetOrderId(String value)
    {
        m_orderId = std::move(value);
        this->m_model.orderId =  m_orderId.empty() ? nullptr : m_orderId.data();
    }

    void SetPaymentOptions(ModelVector<PFPlayerItemManagementPaymentOptionWrapper<Alloc>, Alloc> value)
    {
        m_paymentOptions = std::move(value);
        this->m_model.paymentOptions =  m_paymentOptions.empty() ? nullptr : m_paymentOptions.data();
        this->m_model.paymentOptionsCount =  static_cast<uint32_t>(m_paymentOptions.size());
    }

    void SetVirtualCurrencyBalances(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_virtualCurrencyBalances = std::move(value);
        this->m_model.virtualCurrencyBalances =  m_virtualCurrencyBalances.empty() ? nullptr : m_virtualCurrencyBalances.data();
        this->m_model.virtualCurrencyBalancesCount =  static_cast<uint32_t>(m_virtualCurrencyBalances.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.contents = m_contents.empty() ? nullptr : m_contents.data();
        this->m_model.orderId = m_orderId.empty() ? nullptr : m_orderId.data();
        this->m_model.paymentOptions = m_paymentOptions.empty() ? nullptr : m_paymentOptions.data();
        this->m_model.virtualCurrencyBalances = m_virtualCurrencyBalances.empty() ? nullptr : m_virtualCurrencyBalances.data();
    }

    ModelVector<PFPlayerItemManagementCartItemWrapper<Alloc>, Alloc> m_contents;
    String m_orderId;
    ModelVector<PFPlayerItemManagementPaymentOptionWrapper<Alloc>, Alloc> m_paymentOptions;
    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_virtualCurrencyBalances;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper : public ModelWrapper<PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper() = default;

    PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper(const PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequest& model) :
        ModelWrapper<PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_virtualCurrency{ SafeString(model.virtualCurrency) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper(const PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper& src) :
        PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper(PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper&& src) :
        PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper& operator=(PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper& lhs, PFPlayerItemManagementClientSubtractUserVirtualCurrencyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAmount(int32_t value)
    {
        this->m_model.amount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetVirtualCurrency(String value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_virtualCurrency;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper : public ModelWrapper<PFPlayerItemManagementClientUnlockContainerInstanceRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementClientUnlockContainerInstanceRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper() = default;

    PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper(const PFPlayerItemManagementClientUnlockContainerInstanceRequest& model) :
        ModelWrapper<PFPlayerItemManagementClientUnlockContainerInstanceRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_characterId{ SafeString(model.characterId) },
        m_containerItemInstanceId{ SafeString(model.containerItemInstanceId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_keyItemInstanceId{ SafeString(model.keyItemInstanceId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper(const PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper& src) :
        PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper(PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper&& src) :
        PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper& operator=(PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper& lhs, PFPlayerItemManagementClientUnlockContainerInstanceRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_containerItemInstanceId, rhs.m_containerItemInstanceId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_keyItemInstanceId, rhs.m_keyItemInstanceId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetContainerItemInstanceId(String value)
    {
        m_containerItemInstanceId = std::move(value);
        this->m_model.containerItemInstanceId =  m_containerItemInstanceId.empty() ? nullptr : m_containerItemInstanceId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetKeyItemInstanceId(String value)
    {
        m_keyItemInstanceId = std::move(value);
        this->m_model.keyItemInstanceId =  m_keyItemInstanceId.empty() ? nullptr : m_keyItemInstanceId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.containerItemInstanceId = m_containerItemInstanceId.empty() ? nullptr : m_containerItemInstanceId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.keyItemInstanceId = m_keyItemInstanceId.empty() ? nullptr : m_keyItemInstanceId.data();
    }

    String m_catalogVersion;
    String m_characterId;
    String m_containerItemInstanceId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_keyItemInstanceId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementUnlockContainerItemResultWrapper : public ModelWrapper<PFPlayerItemManagementUnlockContainerItemResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementUnlockContainerItemResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementUnlockContainerItemResultWrapper() = default;

    PFPlayerItemManagementUnlockContainerItemResultWrapper(const PFPlayerItemManagementUnlockContainerItemResult& model) :
        ModelWrapper<PFPlayerItemManagementUnlockContainerItemResult, Alloc>{ model },
        m_grantedItems{ model.grantedItems, model.grantedItems + model.grantedItemsCount },
        m_unlockedItemInstanceId{ SafeString(model.unlockedItemInstanceId) },
        m_unlockedWithItemInstanceId{ SafeString(model.unlockedWithItemInstanceId) },
        m_virtualCurrency{ model.virtualCurrency, model.virtualCurrency + model.virtualCurrencyCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementUnlockContainerItemResultWrapper(const PFPlayerItemManagementUnlockContainerItemResultWrapper& src) :
        PFPlayerItemManagementUnlockContainerItemResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementUnlockContainerItemResultWrapper(PFPlayerItemManagementUnlockContainerItemResultWrapper&& src) :
        PFPlayerItemManagementUnlockContainerItemResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementUnlockContainerItemResultWrapper& operator=(PFPlayerItemManagementUnlockContainerItemResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementUnlockContainerItemResultWrapper() = default;

    friend void swap(PFPlayerItemManagementUnlockContainerItemResultWrapper& lhs, PFPlayerItemManagementUnlockContainerItemResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_grantedItems, rhs.m_grantedItems);
        swap(lhs.m_unlockedItemInstanceId, rhs.m_unlockedItemInstanceId);
        swap(lhs.m_unlockedWithItemInstanceId, rhs.m_unlockedWithItemInstanceId);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGrantedItems(ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_grantedItems = std::move(value);
        this->m_model.grantedItems =  m_grantedItems.empty() ? nullptr : m_grantedItems.data();
        this->m_model.grantedItemsCount =  static_cast<uint32_t>(m_grantedItems.size());
    }

    void SetUnlockedItemInstanceId(String value)
    {
        m_unlockedItemInstanceId = std::move(value);
        this->m_model.unlockedItemInstanceId =  m_unlockedItemInstanceId.empty() ? nullptr : m_unlockedItemInstanceId.data();
    }

    void SetUnlockedWithItemInstanceId(String value)
    {
        m_unlockedWithItemInstanceId = std::move(value);
        this->m_model.unlockedWithItemInstanceId =  m_unlockedWithItemInstanceId.empty() ? nullptr : m_unlockedWithItemInstanceId.data();
    }

    void SetVirtualCurrency(DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
        this->m_model.virtualCurrencyCount =  static_cast<uint32_t>(m_virtualCurrency.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.grantedItems = m_grantedItems.empty() ? nullptr : m_grantedItems.data();
        this->m_model.unlockedItemInstanceId = m_unlockedItemInstanceId.empty() ? nullptr : m_unlockedItemInstanceId.data();
        this->m_model.unlockedWithItemInstanceId = m_unlockedWithItemInstanceId.empty() ? nullptr : m_unlockedWithItemInstanceId.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

    ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> m_grantedItems;
    String m_unlockedItemInstanceId;
    String m_unlockedWithItemInstanceId;
    DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> m_virtualCurrency;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementClientUnlockContainerItemRequestWrapper : public ModelWrapper<PFPlayerItemManagementClientUnlockContainerItemRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementClientUnlockContainerItemRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementClientUnlockContainerItemRequestWrapper() = default;

    PFPlayerItemManagementClientUnlockContainerItemRequestWrapper(const PFPlayerItemManagementClientUnlockContainerItemRequest& model) :
        ModelWrapper<PFPlayerItemManagementClientUnlockContainerItemRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_characterId{ SafeString(model.characterId) },
        m_containerItemId{ SafeString(model.containerItemId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementClientUnlockContainerItemRequestWrapper(const PFPlayerItemManagementClientUnlockContainerItemRequestWrapper& src) :
        PFPlayerItemManagementClientUnlockContainerItemRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementClientUnlockContainerItemRequestWrapper(PFPlayerItemManagementClientUnlockContainerItemRequestWrapper&& src) :
        PFPlayerItemManagementClientUnlockContainerItemRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementClientUnlockContainerItemRequestWrapper& operator=(PFPlayerItemManagementClientUnlockContainerItemRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementClientUnlockContainerItemRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementClientUnlockContainerItemRequestWrapper& lhs, PFPlayerItemManagementClientUnlockContainerItemRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_containerItemId, rhs.m_containerItemId);
        swap(lhs.m_customTags, rhs.m_customTags);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetContainerItemId(String value)
    {
        m_containerItemId = std::move(value);
        this->m_model.containerItemId =  m_containerItemId.empty() ? nullptr : m_containerItemId.data();
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
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.containerItemId = m_containerItemId.empty() ? nullptr : m_containerItemId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
    }

    String m_catalogVersion;
    String m_characterId;
    String m_containerItemId;
    StringDictionaryEntryVector<Alloc> m_customTags;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper : public ModelWrapper<PFPlayerItemManagementAddCharacterVirtualCurrencyRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementAddCharacterVirtualCurrencyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper() = default;

    PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper(const PFPlayerItemManagementAddCharacterVirtualCurrencyRequest& model) :
        ModelWrapper<PFPlayerItemManagementAddCharacterVirtualCurrencyRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_virtualCurrency{ SafeString(model.virtualCurrency) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper(const PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper& src) :
        PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper(PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper&& src) :
        PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper& operator=(PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper& lhs, PFPlayerItemManagementAddCharacterVirtualCurrencyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAmount(int32_t value)
    {
        this->m_model.amount = value;
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
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

    void SetVirtualCurrency(String value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
    String m_virtualCurrency;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementModifyCharacterVirtualCurrencyResultWrapper : public ModelWrapper<PFPlayerItemManagementModifyCharacterVirtualCurrencyResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementModifyCharacterVirtualCurrencyResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementModifyCharacterVirtualCurrencyResultWrapper() = default;

    PFPlayerItemManagementModifyCharacterVirtualCurrencyResultWrapper(const PFPlayerItemManagementModifyCharacterVirtualCurrencyResult& model) :
        ModelWrapper<PFPlayerItemManagementModifyCharacterVirtualCurrencyResult, Alloc>{ model },
        m_virtualCurrency{ SafeString(model.virtualCurrency) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementModifyCharacterVirtualCurrencyResultWrapper(const PFPlayerItemManagementModifyCharacterVirtualCurrencyResultWrapper& src) :
        PFPlayerItemManagementModifyCharacterVirtualCurrencyResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementModifyCharacterVirtualCurrencyResultWrapper(PFPlayerItemManagementModifyCharacterVirtualCurrencyResultWrapper&& src) :
        PFPlayerItemManagementModifyCharacterVirtualCurrencyResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementModifyCharacterVirtualCurrencyResultWrapper& operator=(PFPlayerItemManagementModifyCharacterVirtualCurrencyResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementModifyCharacterVirtualCurrencyResultWrapper() = default;

    friend void swap(PFPlayerItemManagementModifyCharacterVirtualCurrencyResultWrapper& lhs, PFPlayerItemManagementModifyCharacterVirtualCurrencyResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBalance(int32_t value)
    {
        this->m_model.balance = value;
    }

    void SetVirtualCurrency(String value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

    String m_virtualCurrency;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper : public ModelWrapper<PFPlayerItemManagementServerAddUserVirtualCurrencyRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementServerAddUserVirtualCurrencyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper() = default;

    PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper(const PFPlayerItemManagementServerAddUserVirtualCurrencyRequest& model) :
        ModelWrapper<PFPlayerItemManagementServerAddUserVirtualCurrencyRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_virtualCurrency{ SafeString(model.virtualCurrency) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper(const PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper& src) :
        PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper(PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper&& src) :
        PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper& operator=(PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper& lhs, PFPlayerItemManagementServerAddUserVirtualCurrencyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAmount(int32_t value)
    {
        this->m_model.amount = value;
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

    void SetVirtualCurrency(String value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
    String m_virtualCurrency;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementServerConsumeItemRequestWrapper : public ModelWrapper<PFPlayerItemManagementServerConsumeItemRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementServerConsumeItemRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementServerConsumeItemRequestWrapper() = default;

    PFPlayerItemManagementServerConsumeItemRequestWrapper(const PFPlayerItemManagementServerConsumeItemRequest& model) :
        ModelWrapper<PFPlayerItemManagementServerConsumeItemRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_itemInstanceId{ SafeString(model.itemInstanceId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementServerConsumeItemRequestWrapper(const PFPlayerItemManagementServerConsumeItemRequestWrapper& src) :
        PFPlayerItemManagementServerConsumeItemRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementServerConsumeItemRequestWrapper(PFPlayerItemManagementServerConsumeItemRequestWrapper&& src) :
        PFPlayerItemManagementServerConsumeItemRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementServerConsumeItemRequestWrapper& operator=(PFPlayerItemManagementServerConsumeItemRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementServerConsumeItemRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementServerConsumeItemRequestWrapper& lhs, PFPlayerItemManagementServerConsumeItemRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_itemInstanceId, rhs.m_itemInstanceId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetConsumeCount(int32_t value)
    {
        this->m_model.consumeCount = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetItemInstanceId(String value)
    {
        m_itemInstanceId = std::move(value);
        this->m_model.itemInstanceId =  m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.itemInstanceId = m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_itemInstanceId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper : public ModelWrapper<PFPlayerItemManagementEvaluateRandomResultTableRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementEvaluateRandomResultTableRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper() = default;

    PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper(const PFPlayerItemManagementEvaluateRandomResultTableRequest& model) :
        ModelWrapper<PFPlayerItemManagementEvaluateRandomResultTableRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_tableId{ SafeString(model.tableId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper(const PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper& src) :
        PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper(PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper&& src) :
        PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper& operator=(PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper& lhs, PFPlayerItemManagementEvaluateRandomResultTableRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_tableId, rhs.m_tableId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetTableId(String value)
    {
        m_tableId = std::move(value);
        this->m_model.tableId =  m_tableId.empty() ? nullptr : m_tableId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.tableId = m_tableId.empty() ? nullptr : m_tableId.data();
    }

    String m_catalogVersion;
    String m_tableId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementEvaluateRandomResultTableResultWrapper : public ModelWrapper<PFPlayerItemManagementEvaluateRandomResultTableResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementEvaluateRandomResultTableResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementEvaluateRandomResultTableResultWrapper() = default;

    PFPlayerItemManagementEvaluateRandomResultTableResultWrapper(const PFPlayerItemManagementEvaluateRandomResultTableResult& model) :
        ModelWrapper<PFPlayerItemManagementEvaluateRandomResultTableResult, Alloc>{ model },
        m_resultItemId{ SafeString(model.resultItemId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementEvaluateRandomResultTableResultWrapper(const PFPlayerItemManagementEvaluateRandomResultTableResultWrapper& src) :
        PFPlayerItemManagementEvaluateRandomResultTableResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementEvaluateRandomResultTableResultWrapper(PFPlayerItemManagementEvaluateRandomResultTableResultWrapper&& src) :
        PFPlayerItemManagementEvaluateRandomResultTableResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementEvaluateRandomResultTableResultWrapper& operator=(PFPlayerItemManagementEvaluateRandomResultTableResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementEvaluateRandomResultTableResultWrapper() = default;

    friend void swap(PFPlayerItemManagementEvaluateRandomResultTableResultWrapper& lhs, PFPlayerItemManagementEvaluateRandomResultTableResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_resultItemId, rhs.m_resultItemId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetResultItemId(String value)
    {
        m_resultItemId = std::move(value);
        this->m_model.resultItemId =  m_resultItemId.empty() ? nullptr : m_resultItemId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.resultItemId = m_resultItemId.empty() ? nullptr : m_resultItemId.data();
    }

    String m_resultItemId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper : public ModelWrapper<PFPlayerItemManagementServerGetCharacterInventoryRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementServerGetCharacterInventoryRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper() = default;

    PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper(const PFPlayerItemManagementServerGetCharacterInventoryRequest& model) :
        ModelWrapper<PFPlayerItemManagementServerGetCharacterInventoryRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper(const PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper& src) :
        PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper(PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper&& src) :
        PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper& operator=(PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper& lhs, PFPlayerItemManagementServerGetCharacterInventoryRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
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
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_catalogVersion;
    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementServerGetCharacterInventoryResultWrapper : public ModelWrapper<PFPlayerItemManagementServerGetCharacterInventoryResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementServerGetCharacterInventoryResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementServerGetCharacterInventoryResultWrapper() = default;

    PFPlayerItemManagementServerGetCharacterInventoryResultWrapper(const PFPlayerItemManagementServerGetCharacterInventoryResult& model) :
        ModelWrapper<PFPlayerItemManagementServerGetCharacterInventoryResult, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_inventory{ model.inventory, model.inventory + model.inventoryCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_virtualCurrency{ model.virtualCurrency, model.virtualCurrency + model.virtualCurrencyCount },
        m_virtualCurrencyRechargeTimes{ model.virtualCurrencyRechargeTimes, model.virtualCurrencyRechargeTimes + model.virtualCurrencyRechargeTimesCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementServerGetCharacterInventoryResultWrapper(const PFPlayerItemManagementServerGetCharacterInventoryResultWrapper& src) :
        PFPlayerItemManagementServerGetCharacterInventoryResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementServerGetCharacterInventoryResultWrapper(PFPlayerItemManagementServerGetCharacterInventoryResultWrapper&& src) :
        PFPlayerItemManagementServerGetCharacterInventoryResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementServerGetCharacterInventoryResultWrapper& operator=(PFPlayerItemManagementServerGetCharacterInventoryResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementServerGetCharacterInventoryResultWrapper() = default;

    friend void swap(PFPlayerItemManagementServerGetCharacterInventoryResultWrapper& lhs, PFPlayerItemManagementServerGetCharacterInventoryResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_inventory, rhs.m_inventory);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        swap(lhs.m_virtualCurrencyRechargeTimes, rhs.m_virtualCurrencyRechargeTimes);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetInventory(ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_inventory = std::move(value);
        this->m_model.inventory =  m_inventory.empty() ? nullptr : m_inventory.data();
        this->m_model.inventoryCount =  static_cast<uint32_t>(m_inventory.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetVirtualCurrency(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
        this->m_model.virtualCurrencyCount =  static_cast<uint32_t>(m_virtualCurrency.size());
    }

    void SetVirtualCurrencyRechargeTimes(ModelDictionaryEntryVector<PFVirtualCurrencyRechargeTimeWrapper<Alloc>, Alloc> value)
    {
        m_virtualCurrencyRechargeTimes = std::move(value);
        this->m_model.virtualCurrencyRechargeTimes =  m_virtualCurrencyRechargeTimes.empty() ? nullptr : m_virtualCurrencyRechargeTimes.data();
        this->m_model.virtualCurrencyRechargeTimesCount =  static_cast<uint32_t>(m_virtualCurrencyRechargeTimes.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.inventory = m_inventory.empty() ? nullptr : m_inventory.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
        this->m_model.virtualCurrencyRechargeTimes = m_virtualCurrencyRechargeTimes.empty() ? nullptr : m_virtualCurrencyRechargeTimes.data();
    }

    String m_characterId;
    ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> m_inventory;
    String m_playFabId;
    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_virtualCurrency;
    ModelDictionaryEntryVector<PFVirtualCurrencyRechargeTimeWrapper<Alloc>, Alloc> m_virtualCurrencyRechargeTimes;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementGetRandomResultTablesRequestWrapper : public ModelWrapper<PFPlayerItemManagementGetRandomResultTablesRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementGetRandomResultTablesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementGetRandomResultTablesRequestWrapper() = default;

    PFPlayerItemManagementGetRandomResultTablesRequestWrapper(const PFPlayerItemManagementGetRandomResultTablesRequest& model) :
        ModelWrapper<PFPlayerItemManagementGetRandomResultTablesRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_tableIDs{ model.tableIDs, model.tableIDs + model.tableIDsCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementGetRandomResultTablesRequestWrapper(const PFPlayerItemManagementGetRandomResultTablesRequestWrapper& src) :
        PFPlayerItemManagementGetRandomResultTablesRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementGetRandomResultTablesRequestWrapper(PFPlayerItemManagementGetRandomResultTablesRequestWrapper&& src) :
        PFPlayerItemManagementGetRandomResultTablesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementGetRandomResultTablesRequestWrapper& operator=(PFPlayerItemManagementGetRandomResultTablesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementGetRandomResultTablesRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementGetRandomResultTablesRequestWrapper& lhs, PFPlayerItemManagementGetRandomResultTablesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_tableIDs, rhs.m_tableIDs);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetTableIDs(CStringVector<Alloc> value)
    {
        m_tableIDs = std::move(value);
        this->m_model.tableIDs =  m_tableIDs.empty() ? nullptr : m_tableIDs.data();
        this->m_model.tableIDsCount =  static_cast<uint32_t>(m_tableIDs.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.tableIDs = m_tableIDs.empty() ? nullptr : m_tableIDs.data();
    }

    String m_catalogVersion;
    CStringVector<Alloc> m_tableIDs;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementServerGetUserInventoryRequestWrapper : public ModelWrapper<PFPlayerItemManagementServerGetUserInventoryRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementServerGetUserInventoryRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementServerGetUserInventoryRequestWrapper() = default;

    PFPlayerItemManagementServerGetUserInventoryRequestWrapper(const PFPlayerItemManagementServerGetUserInventoryRequest& model) :
        ModelWrapper<PFPlayerItemManagementServerGetUserInventoryRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementServerGetUserInventoryRequestWrapper(const PFPlayerItemManagementServerGetUserInventoryRequestWrapper& src) :
        PFPlayerItemManagementServerGetUserInventoryRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementServerGetUserInventoryRequestWrapper(PFPlayerItemManagementServerGetUserInventoryRequestWrapper&& src) :
        PFPlayerItemManagementServerGetUserInventoryRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementServerGetUserInventoryRequestWrapper& operator=(PFPlayerItemManagementServerGetUserInventoryRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementServerGetUserInventoryRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementServerGetUserInventoryRequestWrapper& lhs, PFPlayerItemManagementServerGetUserInventoryRequestWrapper& rhs)
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
class PFPlayerItemManagementServerGetUserInventoryResultWrapper : public ModelWrapper<PFPlayerItemManagementServerGetUserInventoryResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementServerGetUserInventoryResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementServerGetUserInventoryResultWrapper() = default;

    PFPlayerItemManagementServerGetUserInventoryResultWrapper(const PFPlayerItemManagementServerGetUserInventoryResult& model) :
        ModelWrapper<PFPlayerItemManagementServerGetUserInventoryResult, Alloc>{ model },
        m_inventory{ model.inventory, model.inventory + model.inventoryCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_virtualCurrency{ model.virtualCurrency, model.virtualCurrency + model.virtualCurrencyCount },
        m_virtualCurrencyRechargeTimes{ model.virtualCurrencyRechargeTimes, model.virtualCurrencyRechargeTimes + model.virtualCurrencyRechargeTimesCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementServerGetUserInventoryResultWrapper(const PFPlayerItemManagementServerGetUserInventoryResultWrapper& src) :
        PFPlayerItemManagementServerGetUserInventoryResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementServerGetUserInventoryResultWrapper(PFPlayerItemManagementServerGetUserInventoryResultWrapper&& src) :
        PFPlayerItemManagementServerGetUserInventoryResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementServerGetUserInventoryResultWrapper& operator=(PFPlayerItemManagementServerGetUserInventoryResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementServerGetUserInventoryResultWrapper() = default;

    friend void swap(PFPlayerItemManagementServerGetUserInventoryResultWrapper& lhs, PFPlayerItemManagementServerGetUserInventoryResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_inventory, rhs.m_inventory);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        swap(lhs.m_virtualCurrencyRechargeTimes, rhs.m_virtualCurrencyRechargeTimes);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetInventory(ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_inventory = std::move(value);
        this->m_model.inventory =  m_inventory.empty() ? nullptr : m_inventory.data();
        this->m_model.inventoryCount =  static_cast<uint32_t>(m_inventory.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetVirtualCurrency(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
        this->m_model.virtualCurrencyCount =  static_cast<uint32_t>(m_virtualCurrency.size());
    }

    void SetVirtualCurrencyRechargeTimes(ModelDictionaryEntryVector<PFVirtualCurrencyRechargeTimeWrapper<Alloc>, Alloc> value)
    {
        m_virtualCurrencyRechargeTimes = std::move(value);
        this->m_model.virtualCurrencyRechargeTimes =  m_virtualCurrencyRechargeTimes.empty() ? nullptr : m_virtualCurrencyRechargeTimes.data();
        this->m_model.virtualCurrencyRechargeTimesCount =  static_cast<uint32_t>(m_virtualCurrencyRechargeTimes.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.inventory = m_inventory.empty() ? nullptr : m_inventory.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
        this->m_model.virtualCurrencyRechargeTimes = m_virtualCurrencyRechargeTimes.empty() ? nullptr : m_virtualCurrencyRechargeTimes.data();
    }

    ModelVector<PFItemInstanceWrapper<Alloc>, Alloc> m_inventory;
    String m_playFabId;
    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_virtualCurrency;
    ModelDictionaryEntryVector<PFVirtualCurrencyRechargeTimeWrapper<Alloc>, Alloc> m_virtualCurrencyRechargeTimes;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementGrantItemsToCharacterRequestWrapper : public ModelWrapper<PFPlayerItemManagementGrantItemsToCharacterRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementGrantItemsToCharacterRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementGrantItemsToCharacterRequestWrapper() = default;

    PFPlayerItemManagementGrantItemsToCharacterRequestWrapper(const PFPlayerItemManagementGrantItemsToCharacterRequest& model) :
        ModelWrapper<PFPlayerItemManagementGrantItemsToCharacterRequest, Alloc>{ model },
        m_annotation{ SafeString(model.annotation) },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_itemIds{ model.itemIds, model.itemIds + model.itemIdsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementGrantItemsToCharacterRequestWrapper(const PFPlayerItemManagementGrantItemsToCharacterRequestWrapper& src) :
        PFPlayerItemManagementGrantItemsToCharacterRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementGrantItemsToCharacterRequestWrapper(PFPlayerItemManagementGrantItemsToCharacterRequestWrapper&& src) :
        PFPlayerItemManagementGrantItemsToCharacterRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementGrantItemsToCharacterRequestWrapper& operator=(PFPlayerItemManagementGrantItemsToCharacterRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementGrantItemsToCharacterRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementGrantItemsToCharacterRequestWrapper& lhs, PFPlayerItemManagementGrantItemsToCharacterRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_annotation, rhs.m_annotation);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_itemIds, rhs.m_itemIds);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAnnotation(String value)
    {
        m_annotation = std::move(value);
        this->m_model.annotation =  m_annotation.empty() ? nullptr : m_annotation.data();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetItemIds(CStringVector<Alloc> value)
    {
        m_itemIds = std::move(value);
        this->m_model.itemIds =  m_itemIds.empty() ? nullptr : m_itemIds.data();
        this->m_model.itemIdsCount =  static_cast<uint32_t>(m_itemIds.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.annotation = m_annotation.empty() ? nullptr : m_annotation.data();
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.itemIds = m_itemIds.empty() ? nullptr : m_itemIds.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_annotation;
    String m_catalogVersion;
    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    CStringVector<Alloc> m_itemIds;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementGrantItemsToCharacterResultWrapper : public ModelWrapper<PFPlayerItemManagementGrantItemsToCharacterResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementGrantItemsToCharacterResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementGrantItemsToCharacterResultWrapper() = default;

    PFPlayerItemManagementGrantItemsToCharacterResultWrapper(const PFPlayerItemManagementGrantItemsToCharacterResult& model) :
        ModelWrapper<PFPlayerItemManagementGrantItemsToCharacterResult, Alloc>{ model },
        m_itemGrantResults{ model.itemGrantResults, model.itemGrantResults + model.itemGrantResultsCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementGrantItemsToCharacterResultWrapper(const PFPlayerItemManagementGrantItemsToCharacterResultWrapper& src) :
        PFPlayerItemManagementGrantItemsToCharacterResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementGrantItemsToCharacterResultWrapper(PFPlayerItemManagementGrantItemsToCharacterResultWrapper&& src) :
        PFPlayerItemManagementGrantItemsToCharacterResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementGrantItemsToCharacterResultWrapper& operator=(PFPlayerItemManagementGrantItemsToCharacterResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementGrantItemsToCharacterResultWrapper() = default;

    friend void swap(PFPlayerItemManagementGrantItemsToCharacterResultWrapper& lhs, PFPlayerItemManagementGrantItemsToCharacterResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_itemGrantResults, rhs.m_itemGrantResults);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetItemGrantResults(ModelVector<PFPlayerItemManagementGrantedItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_itemGrantResults = std::move(value);
        this->m_model.itemGrantResults =  m_itemGrantResults.empty() ? nullptr : m_itemGrantResults.data();
        this->m_model.itemGrantResultsCount =  static_cast<uint32_t>(m_itemGrantResults.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.itemGrantResults = m_itemGrantResults.empty() ? nullptr : m_itemGrantResults.data();
    }

    ModelVector<PFPlayerItemManagementGrantedItemInstanceWrapper<Alloc>, Alloc> m_itemGrantResults;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementGrantItemsToUserRequestWrapper : public ModelWrapper<PFPlayerItemManagementGrantItemsToUserRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementGrantItemsToUserRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementGrantItemsToUserRequestWrapper() = default;

    PFPlayerItemManagementGrantItemsToUserRequestWrapper(const PFPlayerItemManagementGrantItemsToUserRequest& model) :
        ModelWrapper<PFPlayerItemManagementGrantItemsToUserRequest, Alloc>{ model },
        m_annotation{ SafeString(model.annotation) },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_itemIds{ model.itemIds, model.itemIds + model.itemIdsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementGrantItemsToUserRequestWrapper(const PFPlayerItemManagementGrantItemsToUserRequestWrapper& src) :
        PFPlayerItemManagementGrantItemsToUserRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementGrantItemsToUserRequestWrapper(PFPlayerItemManagementGrantItemsToUserRequestWrapper&& src) :
        PFPlayerItemManagementGrantItemsToUserRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementGrantItemsToUserRequestWrapper& operator=(PFPlayerItemManagementGrantItemsToUserRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementGrantItemsToUserRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementGrantItemsToUserRequestWrapper& lhs, PFPlayerItemManagementGrantItemsToUserRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_annotation, rhs.m_annotation);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_itemIds, rhs.m_itemIds);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAnnotation(String value)
    {
        m_annotation = std::move(value);
        this->m_model.annotation =  m_annotation.empty() ? nullptr : m_annotation.data();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetItemIds(CStringVector<Alloc> value)
    {
        m_itemIds = std::move(value);
        this->m_model.itemIds =  m_itemIds.empty() ? nullptr : m_itemIds.data();
        this->m_model.itemIdsCount =  static_cast<uint32_t>(m_itemIds.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.annotation = m_annotation.empty() ? nullptr : m_annotation.data();
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.itemIds = m_itemIds.empty() ? nullptr : m_itemIds.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_annotation;
    String m_catalogVersion;
    StringDictionaryEntryVector<Alloc> m_customTags;
    CStringVector<Alloc> m_itemIds;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementGrantItemsToUserResultWrapper : public ModelWrapper<PFPlayerItemManagementGrantItemsToUserResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementGrantItemsToUserResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementGrantItemsToUserResultWrapper() = default;

    PFPlayerItemManagementGrantItemsToUserResultWrapper(const PFPlayerItemManagementGrantItemsToUserResult& model) :
        ModelWrapper<PFPlayerItemManagementGrantItemsToUserResult, Alloc>{ model },
        m_itemGrantResults{ model.itemGrantResults, model.itemGrantResults + model.itemGrantResultsCount }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementGrantItemsToUserResultWrapper(const PFPlayerItemManagementGrantItemsToUserResultWrapper& src) :
        PFPlayerItemManagementGrantItemsToUserResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementGrantItemsToUserResultWrapper(PFPlayerItemManagementGrantItemsToUserResultWrapper&& src) :
        PFPlayerItemManagementGrantItemsToUserResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementGrantItemsToUserResultWrapper& operator=(PFPlayerItemManagementGrantItemsToUserResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementGrantItemsToUserResultWrapper() = default;

    friend void swap(PFPlayerItemManagementGrantItemsToUserResultWrapper& lhs, PFPlayerItemManagementGrantItemsToUserResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_itemGrantResults, rhs.m_itemGrantResults);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetItemGrantResults(ModelVector<PFPlayerItemManagementGrantedItemInstanceWrapper<Alloc>, Alloc> value)
    {
        m_itemGrantResults = std::move(value);
        this->m_model.itemGrantResults =  m_itemGrantResults.empty() ? nullptr : m_itemGrantResults.data();
        this->m_model.itemGrantResultsCount =  static_cast<uint32_t>(m_itemGrantResults.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.itemGrantResults = m_itemGrantResults.empty() ? nullptr : m_itemGrantResults.data();
    }

    ModelVector<PFPlayerItemManagementGrantedItemInstanceWrapper<Alloc>, Alloc> m_itemGrantResults;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementModifyItemUsesRequestWrapper : public ModelWrapper<PFPlayerItemManagementModifyItemUsesRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementModifyItemUsesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementModifyItemUsesRequestWrapper() = default;

    PFPlayerItemManagementModifyItemUsesRequestWrapper(const PFPlayerItemManagementModifyItemUsesRequest& model) :
        ModelWrapper<PFPlayerItemManagementModifyItemUsesRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_itemInstanceId{ SafeString(model.itemInstanceId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementModifyItemUsesRequestWrapper(const PFPlayerItemManagementModifyItemUsesRequestWrapper& src) :
        PFPlayerItemManagementModifyItemUsesRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementModifyItemUsesRequestWrapper(PFPlayerItemManagementModifyItemUsesRequestWrapper&& src) :
        PFPlayerItemManagementModifyItemUsesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementModifyItemUsesRequestWrapper& operator=(PFPlayerItemManagementModifyItemUsesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementModifyItemUsesRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementModifyItemUsesRequestWrapper& lhs, PFPlayerItemManagementModifyItemUsesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_itemInstanceId, rhs.m_itemInstanceId);
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

    void SetItemInstanceId(String value)
    {
        m_itemInstanceId = std::move(value);
        this->m_model.itemInstanceId =  m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetUsesToAdd(int32_t value)
    {
        this->m_model.usesToAdd = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.itemInstanceId = m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_itemInstanceId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementModifyItemUsesResultWrapper : public ModelWrapper<PFPlayerItemManagementModifyItemUsesResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementModifyItemUsesResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementModifyItemUsesResultWrapper() = default;

    PFPlayerItemManagementModifyItemUsesResultWrapper(const PFPlayerItemManagementModifyItemUsesResult& model) :
        ModelWrapper<PFPlayerItemManagementModifyItemUsesResult, Alloc>{ model },
        m_itemInstanceId{ SafeString(model.itemInstanceId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementModifyItemUsesResultWrapper(const PFPlayerItemManagementModifyItemUsesResultWrapper& src) :
        PFPlayerItemManagementModifyItemUsesResultWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementModifyItemUsesResultWrapper(PFPlayerItemManagementModifyItemUsesResultWrapper&& src) :
        PFPlayerItemManagementModifyItemUsesResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementModifyItemUsesResultWrapper& operator=(PFPlayerItemManagementModifyItemUsesResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementModifyItemUsesResultWrapper() = default;

    friend void swap(PFPlayerItemManagementModifyItemUsesResultWrapper& lhs, PFPlayerItemManagementModifyItemUsesResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_itemInstanceId, rhs.m_itemInstanceId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetItemInstanceId(String value)
    {
        m_itemInstanceId = std::move(value);
        this->m_model.itemInstanceId =  m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
    }

    void SetRemainingUses(int32_t value)
    {
        this->m_model.remainingUses = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.itemInstanceId = m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
    }

    String m_itemInstanceId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper : public ModelWrapper<PFPlayerItemManagementMoveItemToCharacterFromCharacterRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementMoveItemToCharacterFromCharacterRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper() = default;

    PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper(const PFPlayerItemManagementMoveItemToCharacterFromCharacterRequest& model) :
        ModelWrapper<PFPlayerItemManagementMoveItemToCharacterFromCharacterRequest, Alloc>{ model },
        m_givingCharacterId{ SafeString(model.givingCharacterId) },
        m_itemInstanceId{ SafeString(model.itemInstanceId) },
        m_playFabId{ SafeString(model.playFabId) },
        m_receivingCharacterId{ SafeString(model.receivingCharacterId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper(const PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper& src) :
        PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper(PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper&& src) :
        PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper& operator=(PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper& lhs, PFPlayerItemManagementMoveItemToCharacterFromCharacterRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_givingCharacterId, rhs.m_givingCharacterId);
        swap(lhs.m_itemInstanceId, rhs.m_itemInstanceId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_receivingCharacterId, rhs.m_receivingCharacterId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGivingCharacterId(String value)
    {
        m_givingCharacterId = std::move(value);
        this->m_model.givingCharacterId =  m_givingCharacterId.empty() ? nullptr : m_givingCharacterId.data();
    }

    void SetItemInstanceId(String value)
    {
        m_itemInstanceId = std::move(value);
        this->m_model.itemInstanceId =  m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetReceivingCharacterId(String value)
    {
        m_receivingCharacterId = std::move(value);
        this->m_model.receivingCharacterId =  m_receivingCharacterId.empty() ? nullptr : m_receivingCharacterId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.givingCharacterId = m_givingCharacterId.empty() ? nullptr : m_givingCharacterId.data();
        this->m_model.itemInstanceId = m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.receivingCharacterId = m_receivingCharacterId.empty() ? nullptr : m_receivingCharacterId.data();
    }

    String m_givingCharacterId;
    String m_itemInstanceId;
    String m_playFabId;
    String m_receivingCharacterId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper : public ModelWrapper<PFPlayerItemManagementMoveItemToCharacterFromUserRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementMoveItemToCharacterFromUserRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper() = default;

    PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper(const PFPlayerItemManagementMoveItemToCharacterFromUserRequest& model) :
        ModelWrapper<PFPlayerItemManagementMoveItemToCharacterFromUserRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_itemInstanceId{ SafeString(model.itemInstanceId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper(const PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper& src) :
        PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper(PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper&& src) :
        PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper& operator=(PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper& lhs, PFPlayerItemManagementMoveItemToCharacterFromUserRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_itemInstanceId, rhs.m_itemInstanceId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetItemInstanceId(String value)
    {
        m_itemInstanceId = std::move(value);
        this->m_model.itemInstanceId =  m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.itemInstanceId = m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_characterId;
    String m_itemInstanceId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper : public ModelWrapper<PFPlayerItemManagementMoveItemToUserFromCharacterRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementMoveItemToUserFromCharacterRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper() = default;

    PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper(const PFPlayerItemManagementMoveItemToUserFromCharacterRequest& model) :
        ModelWrapper<PFPlayerItemManagementMoveItemToUserFromCharacterRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_itemInstanceId{ SafeString(model.itemInstanceId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper(const PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper& src) :
        PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper(PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper&& src) :
        PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper& operator=(PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper& lhs, PFPlayerItemManagementMoveItemToUserFromCharacterRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_itemInstanceId, rhs.m_itemInstanceId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetItemInstanceId(String value)
    {
        m_itemInstanceId = std::move(value);
        this->m_model.itemInstanceId =  m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.itemInstanceId = m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_characterId;
    String m_itemInstanceId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementServerRedeemCouponRequestWrapper : public ModelWrapper<PFPlayerItemManagementServerRedeemCouponRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementServerRedeemCouponRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementServerRedeemCouponRequestWrapper() = default;

    PFPlayerItemManagementServerRedeemCouponRequestWrapper(const PFPlayerItemManagementServerRedeemCouponRequest& model) :
        ModelWrapper<PFPlayerItemManagementServerRedeemCouponRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_characterId{ SafeString(model.characterId) },
        m_couponCode{ SafeString(model.couponCode) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementServerRedeemCouponRequestWrapper(const PFPlayerItemManagementServerRedeemCouponRequestWrapper& src) :
        PFPlayerItemManagementServerRedeemCouponRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementServerRedeemCouponRequestWrapper(PFPlayerItemManagementServerRedeemCouponRequestWrapper&& src) :
        PFPlayerItemManagementServerRedeemCouponRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementServerRedeemCouponRequestWrapper& operator=(PFPlayerItemManagementServerRedeemCouponRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementServerRedeemCouponRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementServerRedeemCouponRequestWrapper& lhs, PFPlayerItemManagementServerRedeemCouponRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_couponCode, rhs.m_couponCode);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetCouponCode(String value)
    {
        m_couponCode = std::move(value);
        this->m_model.couponCode =  m_couponCode.empty() ? nullptr : m_couponCode.data();
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
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.couponCode = m_couponCode.empty() ? nullptr : m_couponCode.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_catalogVersion;
    String m_characterId;
    String m_couponCode;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementReportPlayerServerRequestWrapper : public ModelWrapper<PFPlayerItemManagementReportPlayerServerRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementReportPlayerServerRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementReportPlayerServerRequestWrapper() = default;

    PFPlayerItemManagementReportPlayerServerRequestWrapper(const PFPlayerItemManagementReportPlayerServerRequest& model) :
        ModelWrapper<PFPlayerItemManagementReportPlayerServerRequest, Alloc>{ model },
        m_comment{ SafeString(model.comment) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_reporteeId{ SafeString(model.reporteeId) },
        m_reporterId{ SafeString(model.reporterId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementReportPlayerServerRequestWrapper(const PFPlayerItemManagementReportPlayerServerRequestWrapper& src) :
        PFPlayerItemManagementReportPlayerServerRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementReportPlayerServerRequestWrapper(PFPlayerItemManagementReportPlayerServerRequestWrapper&& src) :
        PFPlayerItemManagementReportPlayerServerRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementReportPlayerServerRequestWrapper& operator=(PFPlayerItemManagementReportPlayerServerRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementReportPlayerServerRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementReportPlayerServerRequestWrapper& lhs, PFPlayerItemManagementReportPlayerServerRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_comment, rhs.m_comment);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_reporteeId, rhs.m_reporteeId);
        swap(lhs.m_reporterId, rhs.m_reporterId);
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

    void SetReporterId(String value)
    {
        m_reporterId = std::move(value);
        this->m_model.reporterId =  m_reporterId.empty() ? nullptr : m_reporterId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.comment = m_comment.empty() ? nullptr : m_comment.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.reporteeId = m_reporteeId.empty() ? nullptr : m_reporteeId.data();
        this->m_model.reporterId = m_reporterId.empty() ? nullptr : m_reporterId.data();
    }

    String m_comment;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_reporteeId;
    String m_reporterId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementReportPlayerServerResultWrapper : public ModelWrapper<PFPlayerItemManagementReportPlayerServerResult, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementReportPlayerServerResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    using ModelWrapper<PFPlayerItemManagementReportPlayerServerResult, Alloc>::ModelWrapper;

    void SetSubmissionsRemaining(int32_t value)
    {
        this->m_model.submissionsRemaining = value;
    }

private:
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper : public ModelWrapper<PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper() = default;

    PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper(const PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequest& model) :
        ModelWrapper<PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_virtualCurrency{ SafeString(model.virtualCurrency) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper(const PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper& src) :
        PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper(PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper&& src) :
        PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper& operator=(PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper& lhs, PFPlayerItemManagementSubtractCharacterVirtualCurrencyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAmount(int32_t value)
    {
        this->m_model.amount = value;
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
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

    void SetVirtualCurrency(String value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
    String m_virtualCurrency;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper : public ModelWrapper<PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper() = default;

    PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper(const PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequest& model) :
        ModelWrapper<PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_virtualCurrency{ SafeString(model.virtualCurrency) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper(const PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper& src) :
        PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper(PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper&& src) :
        PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper& operator=(PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper& lhs, PFPlayerItemManagementServerSubtractUserVirtualCurrencyRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_virtualCurrency, rhs.m_virtualCurrency);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAmount(int32_t value)
    {
        this->m_model.amount = value;
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

    void SetVirtualCurrency(String value)
    {
        m_virtualCurrency = std::move(value);
        this->m_model.virtualCurrency =  m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.virtualCurrency = m_virtualCurrency.empty() ? nullptr : m_virtualCurrency.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
    String m_virtualCurrency;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper : public ModelWrapper<PFPlayerItemManagementServerUnlockContainerInstanceRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementServerUnlockContainerInstanceRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper() = default;

    PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper(const PFPlayerItemManagementServerUnlockContainerInstanceRequest& model) :
        ModelWrapper<PFPlayerItemManagementServerUnlockContainerInstanceRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_characterId{ SafeString(model.characterId) },
        m_containerItemInstanceId{ SafeString(model.containerItemInstanceId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_keyItemInstanceId{ SafeString(model.keyItemInstanceId) },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper(const PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper& src) :
        PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper(PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper&& src) :
        PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper& operator=(PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper& lhs, PFPlayerItemManagementServerUnlockContainerInstanceRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_containerItemInstanceId, rhs.m_containerItemInstanceId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_keyItemInstanceId, rhs.m_keyItemInstanceId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetContainerItemInstanceId(String value)
    {
        m_containerItemInstanceId = std::move(value);
        this->m_model.containerItemInstanceId =  m_containerItemInstanceId.empty() ? nullptr : m_containerItemInstanceId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetKeyItemInstanceId(String value)
    {
        m_keyItemInstanceId = std::move(value);
        this->m_model.keyItemInstanceId =  m_keyItemInstanceId.empty() ? nullptr : m_keyItemInstanceId.data();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.containerItemInstanceId = m_containerItemInstanceId.empty() ? nullptr : m_containerItemInstanceId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.keyItemInstanceId = m_keyItemInstanceId.empty() ? nullptr : m_keyItemInstanceId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_catalogVersion;
    String m_characterId;
    String m_containerItemInstanceId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_keyItemInstanceId;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementServerUnlockContainerItemRequestWrapper : public ModelWrapper<PFPlayerItemManagementServerUnlockContainerItemRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementServerUnlockContainerItemRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementServerUnlockContainerItemRequestWrapper() = default;

    PFPlayerItemManagementServerUnlockContainerItemRequestWrapper(const PFPlayerItemManagementServerUnlockContainerItemRequest& model) :
        ModelWrapper<PFPlayerItemManagementServerUnlockContainerItemRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_characterId{ SafeString(model.characterId) },
        m_containerItemId{ SafeString(model.containerItemId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementServerUnlockContainerItemRequestWrapper(const PFPlayerItemManagementServerUnlockContainerItemRequestWrapper& src) :
        PFPlayerItemManagementServerUnlockContainerItemRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementServerUnlockContainerItemRequestWrapper(PFPlayerItemManagementServerUnlockContainerItemRequestWrapper&& src) :
        PFPlayerItemManagementServerUnlockContainerItemRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementServerUnlockContainerItemRequestWrapper& operator=(PFPlayerItemManagementServerUnlockContainerItemRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementServerUnlockContainerItemRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementServerUnlockContainerItemRequestWrapper& lhs, PFPlayerItemManagementServerUnlockContainerItemRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_containerItemId, rhs.m_containerItemId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
    }

    void SetContainerItemId(String value)
    {
        m_containerItemId = std::move(value);
        this->m_model.containerItemId =  m_containerItemId.empty() ? nullptr : m_containerItemId.data();
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
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.containerItemId = m_containerItemId.empty() ? nullptr : m_containerItemId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_catalogVersion;
    String m_characterId;
    String m_containerItemId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper : public ModelWrapper<PFPlayerItemManagementUpdateUserInventoryItemDataRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerItemManagementUpdateUserInventoryItemDataRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper() = default;

    PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper(const PFPlayerItemManagementUpdateUserInventoryItemDataRequest& model) :
        ModelWrapper<PFPlayerItemManagementUpdateUserInventoryItemDataRequest, Alloc>{ model },
        m_characterId{ SafeString(model.characterId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_data{ model.data, model.data + model.dataCount },
        m_itemInstanceId{ SafeString(model.itemInstanceId) },
        m_keysToRemove{ model.keysToRemove, model.keysToRemove + model.keysToRemoveCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper(const PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper& src) :
        PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper{ src.Model() }
    {
    }

    PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper(PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper&& src) :
        PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper& operator=(PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper() = default;

    friend void swap(PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper& lhs, PFPlayerItemManagementUpdateUserInventoryItemDataRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_characterId, rhs.m_characterId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_data, rhs.m_data);
        swap(lhs.m_itemInstanceId, rhs.m_itemInstanceId);
        swap(lhs.m_keysToRemove, rhs.m_keysToRemove);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCharacterId(String value)
    {
        m_characterId = std::move(value);
        this->m_model.characterId =  m_characterId.empty() ? nullptr : m_characterId.data();
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

    void SetItemInstanceId(String value)
    {
        m_itemInstanceId = std::move(value);
        this->m_model.itemInstanceId =  m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
    }

    void SetKeysToRemove(CStringVector<Alloc> value)
    {
        m_keysToRemove = std::move(value);
        this->m_model.keysToRemove =  m_keysToRemove.empty() ? nullptr : m_keysToRemove.data();
        this->m_model.keysToRemoveCount =  static_cast<uint32_t>(m_keysToRemove.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.characterId = m_characterId.empty() ? nullptr : m_characterId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
        this->m_model.itemInstanceId = m_itemInstanceId.empty() ? nullptr : m_itemInstanceId.data();
        this->m_model.keysToRemove = m_keysToRemove.empty() ? nullptr : m_keysToRemove.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    String m_characterId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StringDictionaryEntryVector<Alloc> m_data;
    String m_itemInstanceId;
    CStringVector<Alloc> m_keysToRemove;
    String m_playFabId;
};

} // namespace Wrappers
} // namespace PlayFab
