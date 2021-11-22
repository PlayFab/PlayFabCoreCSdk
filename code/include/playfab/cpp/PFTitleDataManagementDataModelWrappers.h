// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFTitleDataManagementDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementAddLocalizedNewsRequestWrapper : public ModelWrapper<PFTitleDataManagementAddLocalizedNewsRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementAddLocalizedNewsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementAddLocalizedNewsRequestWrapper() = default;

    PFTitleDataManagementAddLocalizedNewsRequestWrapper(const PFTitleDataManagementAddLocalizedNewsRequest& model) :
        ModelWrapper<PFTitleDataManagementAddLocalizedNewsRequest, Alloc>{ model },
        m_body{ SafeString(model.body) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_language{ SafeString(model.language) },
        m_newsId{ SafeString(model.newsId) },
        m_title{ SafeString(model.title) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementAddLocalizedNewsRequestWrapper(const PFTitleDataManagementAddLocalizedNewsRequestWrapper& src) :
        PFTitleDataManagementAddLocalizedNewsRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementAddLocalizedNewsRequestWrapper(PFTitleDataManagementAddLocalizedNewsRequestWrapper&& src) :
        PFTitleDataManagementAddLocalizedNewsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementAddLocalizedNewsRequestWrapper& operator=(PFTitleDataManagementAddLocalizedNewsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementAddLocalizedNewsRequestWrapper() = default;

    friend void swap(PFTitleDataManagementAddLocalizedNewsRequestWrapper& lhs, PFTitleDataManagementAddLocalizedNewsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_body, rhs.m_body);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_language, rhs.m_language);
        swap(lhs.m_newsId, rhs.m_newsId);
        swap(lhs.m_title, rhs.m_title);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBody(String value)
    {
        m_body = std::move(value);
        this->m_model.body =  m_body.empty() ? nullptr : m_body.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetLanguage(String value)
    {
        m_language = std::move(value);
        this->m_model.language =  m_language.empty() ? nullptr : m_language.data();
    }

    void SetNewsId(String value)
    {
        m_newsId = std::move(value);
        this->m_model.newsId =  m_newsId.empty() ? nullptr : m_newsId.data();
    }

    void SetTitle(String value)
    {
        m_title = std::move(value);
        this->m_model.title =  m_title.empty() ? nullptr : m_title.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.body = m_body.empty() ? nullptr : m_body.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.language = m_language.empty() ? nullptr : m_language.data();
        this->m_model.newsId = m_newsId.empty() ? nullptr : m_newsId.data();
        this->m_model.title = m_title.empty() ? nullptr : m_title.data();
    }

    String m_body;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_language;
    String m_newsId;
    String m_title;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementAddNewsRequestWrapper : public ModelWrapper<PFTitleDataManagementAddNewsRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementAddNewsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementAddNewsRequestWrapper() = default;

    PFTitleDataManagementAddNewsRequestWrapper(const PFTitleDataManagementAddNewsRequest& model) :
        ModelWrapper<PFTitleDataManagementAddNewsRequest, Alloc>{ model },
        m_body{ SafeString(model.body) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_timestamp{ model.timestamp ? StdExtra::optional<time_t>{ *model.timestamp } : StdExtra::nullopt },
        m_title{ SafeString(model.title) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementAddNewsRequestWrapper(const PFTitleDataManagementAddNewsRequestWrapper& src) :
        PFTitleDataManagementAddNewsRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementAddNewsRequestWrapper(PFTitleDataManagementAddNewsRequestWrapper&& src) :
        PFTitleDataManagementAddNewsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementAddNewsRequestWrapper& operator=(PFTitleDataManagementAddNewsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementAddNewsRequestWrapper() = default;

    friend void swap(PFTitleDataManagementAddNewsRequestWrapper& lhs, PFTitleDataManagementAddNewsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_body, rhs.m_body);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_timestamp, rhs.m_timestamp);
        swap(lhs.m_title, rhs.m_title);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBody(String value)
    {
        m_body = std::move(value);
        this->m_model.body =  m_body.empty() ? nullptr : m_body.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetTimestamp(StdExtra::optional<time_t> value)
    {
        m_timestamp = std::move(value);
        this->m_model.timestamp = m_timestamp ? m_timestamp.operator->() : nullptr;
    }

    void SetTitle(String value)
    {
        m_title = std::move(value);
        this->m_model.title =  m_title.empty() ? nullptr : m_title.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.body = m_body.empty() ? nullptr : m_body.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.timestamp = m_timestamp ? m_timestamp.operator->() : nullptr;
        this->m_model.title = m_title.empty() ? nullptr : m_title.data();
    }

    String m_body;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<time_t> m_timestamp;
    String m_title;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementAddNewsResultWrapper : public ModelWrapper<PFTitleDataManagementAddNewsResult, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementAddNewsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementAddNewsResultWrapper() = default;

    PFTitleDataManagementAddNewsResultWrapper(const PFTitleDataManagementAddNewsResult& model) :
        ModelWrapper<PFTitleDataManagementAddNewsResult, Alloc>{ model },
        m_newsId{ SafeString(model.newsId) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementAddNewsResultWrapper(const PFTitleDataManagementAddNewsResultWrapper& src) :
        PFTitleDataManagementAddNewsResultWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementAddNewsResultWrapper(PFTitleDataManagementAddNewsResultWrapper&& src) :
        PFTitleDataManagementAddNewsResultWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementAddNewsResultWrapper& operator=(PFTitleDataManagementAddNewsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementAddNewsResultWrapper() = default;

    friend void swap(PFTitleDataManagementAddNewsResultWrapper& lhs, PFTitleDataManagementAddNewsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_newsId, rhs.m_newsId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetNewsId(String value)
    {
        m_newsId = std::move(value);
        this->m_model.newsId =  m_newsId.empty() ? nullptr : m_newsId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.newsId = m_newsId.empty() ? nullptr : m_newsId.data();
    }

    String m_newsId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementVirtualCurrencyDataWrapper : public ModelWrapper<PFTitleDataManagementVirtualCurrencyData, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementVirtualCurrencyData;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementVirtualCurrencyDataWrapper() = default;

    PFTitleDataManagementVirtualCurrencyDataWrapper(const PFTitleDataManagementVirtualCurrencyData& model) :
        ModelWrapper<PFTitleDataManagementVirtualCurrencyData, Alloc>{ model },
        m_currencyCode{ SafeString(model.currencyCode) },
        m_displayName{ SafeString(model.displayName) },
        m_initialDeposit{ model.initialDeposit ? StdExtra::optional<int32_t>{ *model.initialDeposit } : StdExtra::nullopt },
        m_rechargeMax{ model.rechargeMax ? StdExtra::optional<int32_t>{ *model.rechargeMax } : StdExtra::nullopt },
        m_rechargeRate{ model.rechargeRate ? StdExtra::optional<int32_t>{ *model.rechargeRate } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFTitleDataManagementVirtualCurrencyDataWrapper(const PFTitleDataManagementVirtualCurrencyDataWrapper& src) :
        PFTitleDataManagementVirtualCurrencyDataWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementVirtualCurrencyDataWrapper(PFTitleDataManagementVirtualCurrencyDataWrapper&& src) :
        PFTitleDataManagementVirtualCurrencyDataWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementVirtualCurrencyDataWrapper& operator=(PFTitleDataManagementVirtualCurrencyDataWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementVirtualCurrencyDataWrapper() = default;

    friend void swap(PFTitleDataManagementVirtualCurrencyDataWrapper& lhs, PFTitleDataManagementVirtualCurrencyDataWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_currencyCode, rhs.m_currencyCode);
        swap(lhs.m_displayName, rhs.m_displayName);
        swap(lhs.m_initialDeposit, rhs.m_initialDeposit);
        swap(lhs.m_rechargeMax, rhs.m_rechargeMax);
        swap(lhs.m_rechargeRate, rhs.m_rechargeRate);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCurrencyCode(String value)
    {
        m_currencyCode = std::move(value);
        this->m_model.currencyCode =  m_currencyCode.empty() ? nullptr : m_currencyCode.data();
    }

    void SetDisplayName(String value)
    {
        m_displayName = std::move(value);
        this->m_model.displayName =  m_displayName.empty() ? nullptr : m_displayName.data();
    }

    void SetInitialDeposit(StdExtra::optional<int32_t> value)
    {
        m_initialDeposit = std::move(value);
        this->m_model.initialDeposit = m_initialDeposit ? m_initialDeposit.operator->() : nullptr;
    }

    void SetRechargeMax(StdExtra::optional<int32_t> value)
    {
        m_rechargeMax = std::move(value);
        this->m_model.rechargeMax = m_rechargeMax ? m_rechargeMax.operator->() : nullptr;
    }

    void SetRechargeRate(StdExtra::optional<int32_t> value)
    {
        m_rechargeRate = std::move(value);
        this->m_model.rechargeRate = m_rechargeRate ? m_rechargeRate.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.currencyCode = m_currencyCode.empty() ? nullptr : m_currencyCode.data();
        this->m_model.displayName = m_displayName.empty() ? nullptr : m_displayName.data();
        this->m_model.initialDeposit = m_initialDeposit ? m_initialDeposit.operator->() : nullptr;
        this->m_model.rechargeMax = m_rechargeMax ? m_rechargeMax.operator->() : nullptr;
        this->m_model.rechargeRate = m_rechargeRate ? m_rechargeRate.operator->() : nullptr;
    }

    String m_currencyCode;
    String m_displayName;
    StdExtra::optional<int32_t> m_initialDeposit;
    StdExtra::optional<int32_t> m_rechargeMax;
    StdExtra::optional<int32_t> m_rechargeRate;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper : public ModelWrapper<PFTitleDataManagementAddVirtualCurrencyTypesRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementAddVirtualCurrencyTypesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper() = default;

    PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper(const PFTitleDataManagementAddVirtualCurrencyTypesRequest& model) :
        ModelWrapper<PFTitleDataManagementAddVirtualCurrencyTypesRequest, Alloc>{ model },
        m_virtualCurrencies{ model.virtualCurrencies, model.virtualCurrencies + model.virtualCurrenciesCount }
    {
        SetModelPointers();
    }

    PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper(const PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper& src) :
        PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper(PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper&& src) :
        PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper& operator=(PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper() = default;

    friend void swap(PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper& lhs, PFTitleDataManagementAddVirtualCurrencyTypesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_virtualCurrencies, rhs.m_virtualCurrencies);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetVirtualCurrencies(ModelVector<PFTitleDataManagementVirtualCurrencyDataWrapper<Alloc>, Alloc> value)
    {
        m_virtualCurrencies = std::move(value);
        this->m_model.virtualCurrencies =  m_virtualCurrencies.empty() ? nullptr : m_virtualCurrencies.data();
        this->m_model.virtualCurrenciesCount =  static_cast<uint32_t>(m_virtualCurrencies.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.virtualCurrencies = m_virtualCurrencies.empty() ? nullptr : m_virtualCurrencies.data();
    }

    ModelVector<PFTitleDataManagementVirtualCurrencyDataWrapper<Alloc>, Alloc> m_virtualCurrencies;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementDeleteStoreRequestWrapper : public ModelWrapper<PFTitleDataManagementDeleteStoreRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementDeleteStoreRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementDeleteStoreRequestWrapper() = default;

    PFTitleDataManagementDeleteStoreRequestWrapper(const PFTitleDataManagementDeleteStoreRequest& model) :
        ModelWrapper<PFTitleDataManagementDeleteStoreRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_storeId{ SafeString(model.storeId) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementDeleteStoreRequestWrapper(const PFTitleDataManagementDeleteStoreRequestWrapper& src) :
        PFTitleDataManagementDeleteStoreRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementDeleteStoreRequestWrapper(PFTitleDataManagementDeleteStoreRequestWrapper&& src) :
        PFTitleDataManagementDeleteStoreRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementDeleteStoreRequestWrapper& operator=(PFTitleDataManagementDeleteStoreRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementDeleteStoreRequestWrapper() = default;

    friend void swap(PFTitleDataManagementDeleteStoreRequestWrapper& lhs, PFTitleDataManagementDeleteStoreRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_customTags, rhs.m_customTags);
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
        this->m_model.storeId = m_storeId.empty() ? nullptr : m_storeId.data();
    }

    String m_catalogVersion;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_storeId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper : public ModelWrapper<PFTitleDataManagementDeleteTitleDataOverrideRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementDeleteTitleDataOverrideRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper() = default;

    PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper(const PFTitleDataManagementDeleteTitleDataOverrideRequest& model) :
        ModelWrapper<PFTitleDataManagementDeleteTitleDataOverrideRequest, Alloc>{ model },
        m_overrideLabel{ SafeString(model.overrideLabel) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper(const PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper& src) :
        PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper(PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper&& src) :
        PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper& operator=(PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper() = default;

    friend void swap(PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper& lhs, PFTitleDataManagementDeleteTitleDataOverrideRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_overrideLabel, rhs.m_overrideLabel);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetOverrideLabel(String value)
    {
        m_overrideLabel = std::move(value);
        this->m_model.overrideLabel =  m_overrideLabel.empty() ? nullptr : m_overrideLabel.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.overrideLabel = m_overrideLabel.empty() ? nullptr : m_overrideLabel.data();
    }

    String m_overrideLabel;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementGetCatalogItemsRequestWrapper : public ModelWrapper<PFTitleDataManagementGetCatalogItemsRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementGetCatalogItemsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementGetCatalogItemsRequestWrapper() = default;

    PFTitleDataManagementGetCatalogItemsRequestWrapper(const PFTitleDataManagementGetCatalogItemsRequest& model) :
        ModelWrapper<PFTitleDataManagementGetCatalogItemsRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementGetCatalogItemsRequestWrapper(const PFTitleDataManagementGetCatalogItemsRequestWrapper& src) :
        PFTitleDataManagementGetCatalogItemsRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementGetCatalogItemsRequestWrapper(PFTitleDataManagementGetCatalogItemsRequestWrapper&& src) :
        PFTitleDataManagementGetCatalogItemsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementGetCatalogItemsRequestWrapper& operator=(PFTitleDataManagementGetCatalogItemsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementGetCatalogItemsRequestWrapper() = default;

    friend void swap(PFTitleDataManagementGetCatalogItemsRequestWrapper& lhs, PFTitleDataManagementGetCatalogItemsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    String m_catalogVersion;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementCatalogItemBundleInfoWrapper : public ModelWrapper<PFTitleDataManagementCatalogItemBundleInfo, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementCatalogItemBundleInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementCatalogItemBundleInfoWrapper() = default;

    PFTitleDataManagementCatalogItemBundleInfoWrapper(const PFTitleDataManagementCatalogItemBundleInfo& model) :
        ModelWrapper<PFTitleDataManagementCatalogItemBundleInfo, Alloc>{ model },
        m_bundledItems{ model.bundledItems, model.bundledItems + model.bundledItemsCount },
        m_bundledResultTables{ model.bundledResultTables, model.bundledResultTables + model.bundledResultTablesCount },
        m_bundledVirtualCurrencies{ model.bundledVirtualCurrencies, model.bundledVirtualCurrencies + model.bundledVirtualCurrenciesCount }
    {
        SetModelPointers();
    }

    PFTitleDataManagementCatalogItemBundleInfoWrapper(const PFTitleDataManagementCatalogItemBundleInfoWrapper& src) :
        PFTitleDataManagementCatalogItemBundleInfoWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementCatalogItemBundleInfoWrapper(PFTitleDataManagementCatalogItemBundleInfoWrapper&& src) :
        PFTitleDataManagementCatalogItemBundleInfoWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementCatalogItemBundleInfoWrapper& operator=(PFTitleDataManagementCatalogItemBundleInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementCatalogItemBundleInfoWrapper() = default;

    friend void swap(PFTitleDataManagementCatalogItemBundleInfoWrapper& lhs, PFTitleDataManagementCatalogItemBundleInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_bundledItems, rhs.m_bundledItems);
        swap(lhs.m_bundledResultTables, rhs.m_bundledResultTables);
        swap(lhs.m_bundledVirtualCurrencies, rhs.m_bundledVirtualCurrencies);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBundledItems(CStringVector<Alloc> value)
    {
        m_bundledItems = std::move(value);
        this->m_model.bundledItems =  m_bundledItems.empty() ? nullptr : m_bundledItems.data();
        this->m_model.bundledItemsCount =  static_cast<uint32_t>(m_bundledItems.size());
    }

    void SetBundledResultTables(CStringVector<Alloc> value)
    {
        m_bundledResultTables = std::move(value);
        this->m_model.bundledResultTables =  m_bundledResultTables.empty() ? nullptr : m_bundledResultTables.data();
        this->m_model.bundledResultTablesCount =  static_cast<uint32_t>(m_bundledResultTables.size());
    }

    void SetBundledVirtualCurrencies(DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> value)
    {
        m_bundledVirtualCurrencies = std::move(value);
        this->m_model.bundledVirtualCurrencies =  m_bundledVirtualCurrencies.empty() ? nullptr : m_bundledVirtualCurrencies.data();
        this->m_model.bundledVirtualCurrenciesCount =  static_cast<uint32_t>(m_bundledVirtualCurrencies.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.bundledItems = m_bundledItems.empty() ? nullptr : m_bundledItems.data();
        this->m_model.bundledResultTables = m_bundledResultTables.empty() ? nullptr : m_bundledResultTables.data();
        this->m_model.bundledVirtualCurrencies = m_bundledVirtualCurrencies.empty() ? nullptr : m_bundledVirtualCurrencies.data();
    }

    CStringVector<Alloc> m_bundledItems;
    CStringVector<Alloc> m_bundledResultTables;
    DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> m_bundledVirtualCurrencies;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementCatalogItemConsumableInfoWrapper : public ModelWrapper<PFTitleDataManagementCatalogItemConsumableInfo, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementCatalogItemConsumableInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementCatalogItemConsumableInfoWrapper() = default;

    PFTitleDataManagementCatalogItemConsumableInfoWrapper(const PFTitleDataManagementCatalogItemConsumableInfo& model) :
        ModelWrapper<PFTitleDataManagementCatalogItemConsumableInfo, Alloc>{ model },
        m_usageCount{ model.usageCount ? StdExtra::optional<uint32_t>{ *model.usageCount } : StdExtra::nullopt },
        m_usagePeriod{ model.usagePeriod ? StdExtra::optional<uint32_t>{ *model.usagePeriod } : StdExtra::nullopt },
        m_usagePeriodGroup{ SafeString(model.usagePeriodGroup) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementCatalogItemConsumableInfoWrapper(const PFTitleDataManagementCatalogItemConsumableInfoWrapper& src) :
        PFTitleDataManagementCatalogItemConsumableInfoWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementCatalogItemConsumableInfoWrapper(PFTitleDataManagementCatalogItemConsumableInfoWrapper&& src) :
        PFTitleDataManagementCatalogItemConsumableInfoWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementCatalogItemConsumableInfoWrapper& operator=(PFTitleDataManagementCatalogItemConsumableInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementCatalogItemConsumableInfoWrapper() = default;

    friend void swap(PFTitleDataManagementCatalogItemConsumableInfoWrapper& lhs, PFTitleDataManagementCatalogItemConsumableInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_usageCount, rhs.m_usageCount);
        swap(lhs.m_usagePeriod, rhs.m_usagePeriod);
        swap(lhs.m_usagePeriodGroup, rhs.m_usagePeriodGroup);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetUsageCount(StdExtra::optional<uint32_t> value)
    {
        m_usageCount = std::move(value);
        this->m_model.usageCount = m_usageCount ? m_usageCount.operator->() : nullptr;
    }

    void SetUsagePeriod(StdExtra::optional<uint32_t> value)
    {
        m_usagePeriod = std::move(value);
        this->m_model.usagePeriod = m_usagePeriod ? m_usagePeriod.operator->() : nullptr;
    }

    void SetUsagePeriodGroup(String value)
    {
        m_usagePeriodGroup = std::move(value);
        this->m_model.usagePeriodGroup =  m_usagePeriodGroup.empty() ? nullptr : m_usagePeriodGroup.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.usageCount = m_usageCount ? m_usageCount.operator->() : nullptr;
        this->m_model.usagePeriod = m_usagePeriod ? m_usagePeriod.operator->() : nullptr;
        this->m_model.usagePeriodGroup = m_usagePeriodGroup.empty() ? nullptr : m_usagePeriodGroup.data();
    }

    StdExtra::optional<uint32_t> m_usageCount;
    StdExtra::optional<uint32_t> m_usagePeriod;
    String m_usagePeriodGroup;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementCatalogItemContainerInfoWrapper : public ModelWrapper<PFTitleDataManagementCatalogItemContainerInfo, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementCatalogItemContainerInfo;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementCatalogItemContainerInfoWrapper() = default;

    PFTitleDataManagementCatalogItemContainerInfoWrapper(const PFTitleDataManagementCatalogItemContainerInfo& model) :
        ModelWrapper<PFTitleDataManagementCatalogItemContainerInfo, Alloc>{ model },
        m_itemContents{ model.itemContents, model.itemContents + model.itemContentsCount },
        m_keyItemId{ SafeString(model.keyItemId) },
        m_resultTableContents{ model.resultTableContents, model.resultTableContents + model.resultTableContentsCount },
        m_virtualCurrencyContents{ model.virtualCurrencyContents, model.virtualCurrencyContents + model.virtualCurrencyContentsCount }
    {
        SetModelPointers();
    }

    PFTitleDataManagementCatalogItemContainerInfoWrapper(const PFTitleDataManagementCatalogItemContainerInfoWrapper& src) :
        PFTitleDataManagementCatalogItemContainerInfoWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementCatalogItemContainerInfoWrapper(PFTitleDataManagementCatalogItemContainerInfoWrapper&& src) :
        PFTitleDataManagementCatalogItemContainerInfoWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementCatalogItemContainerInfoWrapper& operator=(PFTitleDataManagementCatalogItemContainerInfoWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementCatalogItemContainerInfoWrapper() = default;

    friend void swap(PFTitleDataManagementCatalogItemContainerInfoWrapper& lhs, PFTitleDataManagementCatalogItemContainerInfoWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_itemContents, rhs.m_itemContents);
        swap(lhs.m_keyItemId, rhs.m_keyItemId);
        swap(lhs.m_resultTableContents, rhs.m_resultTableContents);
        swap(lhs.m_virtualCurrencyContents, rhs.m_virtualCurrencyContents);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetItemContents(CStringVector<Alloc> value)
    {
        m_itemContents = std::move(value);
        this->m_model.itemContents =  m_itemContents.empty() ? nullptr : m_itemContents.data();
        this->m_model.itemContentsCount =  static_cast<uint32_t>(m_itemContents.size());
    }

    void SetKeyItemId(String value)
    {
        m_keyItemId = std::move(value);
        this->m_model.keyItemId =  m_keyItemId.empty() ? nullptr : m_keyItemId.data();
    }

    void SetResultTableContents(CStringVector<Alloc> value)
    {
        m_resultTableContents = std::move(value);
        this->m_model.resultTableContents =  m_resultTableContents.empty() ? nullptr : m_resultTableContents.data();
        this->m_model.resultTableContentsCount =  static_cast<uint32_t>(m_resultTableContents.size());
    }

    void SetVirtualCurrencyContents(DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> value)
    {
        m_virtualCurrencyContents = std::move(value);
        this->m_model.virtualCurrencyContents =  m_virtualCurrencyContents.empty() ? nullptr : m_virtualCurrencyContents.data();
        this->m_model.virtualCurrencyContentsCount =  static_cast<uint32_t>(m_virtualCurrencyContents.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.itemContents = m_itemContents.empty() ? nullptr : m_itemContents.data();
        this->m_model.keyItemId = m_keyItemId.empty() ? nullptr : m_keyItemId.data();
        this->m_model.resultTableContents = m_resultTableContents.empty() ? nullptr : m_resultTableContents.data();
        this->m_model.virtualCurrencyContents = m_virtualCurrencyContents.empty() ? nullptr : m_virtualCurrencyContents.data();
    }

    CStringVector<Alloc> m_itemContents;
    String m_keyItemId;
    CStringVector<Alloc> m_resultTableContents;
    DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> m_virtualCurrencyContents;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementCatalogItemWrapper : public ModelWrapper<PFTitleDataManagementCatalogItem, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementCatalogItem;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementCatalogItemWrapper() = default;

    PFTitleDataManagementCatalogItemWrapper(const PFTitleDataManagementCatalogItem& model) :
        ModelWrapper<PFTitleDataManagementCatalogItem, Alloc>{ model },
        m_bundle{ model.bundle ? StdExtra::optional<PFTitleDataManagementCatalogItemBundleInfoWrapper<Alloc>>{ *model.bundle } : StdExtra::nullopt },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_consumable{ model.consumable ? StdExtra::optional<PFTitleDataManagementCatalogItemConsumableInfoWrapper<Alloc>>{ *model.consumable } : StdExtra::nullopt },
        m_container{ model.container ? StdExtra::optional<PFTitleDataManagementCatalogItemContainerInfoWrapper<Alloc>>{ *model.container } : StdExtra::nullopt },
        m_customData{ SafeString(model.customData) },
        m_description{ SafeString(model.description) },
        m_displayName{ SafeString(model.displayName) },
        m_itemClass{ SafeString(model.itemClass) },
        m_itemId{ SafeString(model.itemId) },
        m_itemImageUrl{ SafeString(model.itemImageUrl) },
        m_realCurrencyPrices{ model.realCurrencyPrices, model.realCurrencyPrices + model.realCurrencyPricesCount },
        m_tags{ model.tags, model.tags + model.tagsCount },
        m_virtualCurrencyPrices{ model.virtualCurrencyPrices, model.virtualCurrencyPrices + model.virtualCurrencyPricesCount }
    {
        SetModelPointers();
    }

    PFTitleDataManagementCatalogItemWrapper(const PFTitleDataManagementCatalogItemWrapper& src) :
        PFTitleDataManagementCatalogItemWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementCatalogItemWrapper(PFTitleDataManagementCatalogItemWrapper&& src) :
        PFTitleDataManagementCatalogItemWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementCatalogItemWrapper& operator=(PFTitleDataManagementCatalogItemWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementCatalogItemWrapper() = default;

    friend void swap(PFTitleDataManagementCatalogItemWrapper& lhs, PFTitleDataManagementCatalogItemWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_bundle, rhs.m_bundle);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_consumable, rhs.m_consumable);
        swap(lhs.m_container, rhs.m_container);
        swap(lhs.m_customData, rhs.m_customData);
        swap(lhs.m_description, rhs.m_description);
        swap(lhs.m_displayName, rhs.m_displayName);
        swap(lhs.m_itemClass, rhs.m_itemClass);
        swap(lhs.m_itemId, rhs.m_itemId);
        swap(lhs.m_itemImageUrl, rhs.m_itemImageUrl);
        swap(lhs.m_realCurrencyPrices, rhs.m_realCurrencyPrices);
        swap(lhs.m_tags, rhs.m_tags);
        swap(lhs.m_virtualCurrencyPrices, rhs.m_virtualCurrencyPrices);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBundle(StdExtra::optional<PFTitleDataManagementCatalogItemBundleInfoWrapper<Alloc>> value)
    {
        m_bundle = std::move(value);
        this->m_model.bundle = m_bundle ? &m_bundle->Model() : nullptr;
    }

    void SetCanBecomeCharacter(bool value)
    {
        this->m_model.canBecomeCharacter = value;
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetConsumable(StdExtra::optional<PFTitleDataManagementCatalogItemConsumableInfoWrapper<Alloc>> value)
    {
        m_consumable = std::move(value);
        this->m_model.consumable = m_consumable ? &m_consumable->Model() : nullptr;
    }

    void SetContainer(StdExtra::optional<PFTitleDataManagementCatalogItemContainerInfoWrapper<Alloc>> value)
    {
        m_container = std::move(value);
        this->m_model.container = m_container ? &m_container->Model() : nullptr;
    }

    void SetCustomData(String value)
    {
        m_customData = std::move(value);
        this->m_model.customData =  m_customData.empty() ? nullptr : m_customData.data();
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

    void SetInitialLimitedEditionCount(int32_t value)
    {
        this->m_model.initialLimitedEditionCount = value;
    }

    void SetIsLimitedEdition(bool value)
    {
        this->m_model.isLimitedEdition = value;
    }

    void SetIsStackable(bool value)
    {
        this->m_model.isStackable = value;
    }

    void SetIsTradable(bool value)
    {
        this->m_model.isTradable = value;
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

    void SetItemImageUrl(String value)
    {
        m_itemImageUrl = std::move(value);
        this->m_model.itemImageUrl =  m_itemImageUrl.empty() ? nullptr : m_itemImageUrl.data();
    }

    void SetRealCurrencyPrices(DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> value)
    {
        m_realCurrencyPrices = std::move(value);
        this->m_model.realCurrencyPrices =  m_realCurrencyPrices.empty() ? nullptr : m_realCurrencyPrices.data();
        this->m_model.realCurrencyPricesCount =  static_cast<uint32_t>(m_realCurrencyPrices.size());
    }

    void SetTags(CStringVector<Alloc> value)
    {
        m_tags = std::move(value);
        this->m_model.tags =  m_tags.empty() ? nullptr : m_tags.data();
        this->m_model.tagsCount =  static_cast<uint32_t>(m_tags.size());
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
        this->m_model.bundle = m_bundle ?  &m_bundle->Model() : nullptr;
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.consumable = m_consumable ?  &m_consumable->Model() : nullptr;
        this->m_model.container = m_container ?  &m_container->Model() : nullptr;
        this->m_model.customData = m_customData.empty() ? nullptr : m_customData.data();
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
        this->m_model.displayName = m_displayName.empty() ? nullptr : m_displayName.data();
        this->m_model.itemClass = m_itemClass.empty() ? nullptr : m_itemClass.data();
        this->m_model.itemId = m_itemId.empty() ? nullptr : m_itemId.data();
        this->m_model.itemImageUrl = m_itemImageUrl.empty() ? nullptr : m_itemImageUrl.data();
        this->m_model.realCurrencyPrices = m_realCurrencyPrices.empty() ? nullptr : m_realCurrencyPrices.data();
        this->m_model.tags = m_tags.empty() ? nullptr : m_tags.data();
        this->m_model.virtualCurrencyPrices = m_virtualCurrencyPrices.empty() ? nullptr : m_virtualCurrencyPrices.data();
    }

    StdExtra::optional<PFTitleDataManagementCatalogItemBundleInfoWrapper<Alloc>> m_bundle;
    String m_catalogVersion;
    StdExtra::optional<PFTitleDataManagementCatalogItemConsumableInfoWrapper<Alloc>> m_consumable;
    StdExtra::optional<PFTitleDataManagementCatalogItemContainerInfoWrapper<Alloc>> m_container;
    String m_customData;
    String m_description;
    String m_displayName;
    String m_itemClass;
    String m_itemId;
    String m_itemImageUrl;
    DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> m_realCurrencyPrices;
    CStringVector<Alloc> m_tags;
    DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> m_virtualCurrencyPrices;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementGetCatalogItemsResultWrapper : public ModelWrapper<PFTitleDataManagementGetCatalogItemsResult, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementGetCatalogItemsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementGetCatalogItemsResultWrapper() = default;

    PFTitleDataManagementGetCatalogItemsResultWrapper(const PFTitleDataManagementGetCatalogItemsResult& model) :
        ModelWrapper<PFTitleDataManagementGetCatalogItemsResult, Alloc>{ model },
        m_catalog{ model.catalog, model.catalog + model.catalogCount }
    {
        SetModelPointers();
    }

    PFTitleDataManagementGetCatalogItemsResultWrapper(const PFTitleDataManagementGetCatalogItemsResultWrapper& src) :
        PFTitleDataManagementGetCatalogItemsResultWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementGetCatalogItemsResultWrapper(PFTitleDataManagementGetCatalogItemsResultWrapper&& src) :
        PFTitleDataManagementGetCatalogItemsResultWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementGetCatalogItemsResultWrapper& operator=(PFTitleDataManagementGetCatalogItemsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementGetCatalogItemsResultWrapper() = default;

    friend void swap(PFTitleDataManagementGetCatalogItemsResultWrapper& lhs, PFTitleDataManagementGetCatalogItemsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalog, rhs.m_catalog);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalog(ModelVector<PFTitleDataManagementCatalogItemWrapper<Alloc>, Alloc> value)
    {
        m_catalog = std::move(value);
        this->m_model.catalog =  m_catalog.empty() ? nullptr : m_catalog.data();
        this->m_model.catalogCount =  static_cast<uint32_t>(m_catalog.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalog = m_catalog.empty() ? nullptr : m_catalog.data();
    }

    ModelVector<PFTitleDataManagementCatalogItemWrapper<Alloc>, Alloc> m_catalog;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementGetPublisherDataRequestWrapper : public ModelWrapper<PFTitleDataManagementGetPublisherDataRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementGetPublisherDataRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementGetPublisherDataRequestWrapper() = default;

    PFTitleDataManagementGetPublisherDataRequestWrapper(const PFTitleDataManagementGetPublisherDataRequest& model) :
        ModelWrapper<PFTitleDataManagementGetPublisherDataRequest, Alloc>{ model },
        m_keys{ model.keys, model.keys + model.keysCount }
    {
        SetModelPointers();
    }

    PFTitleDataManagementGetPublisherDataRequestWrapper(const PFTitleDataManagementGetPublisherDataRequestWrapper& src) :
        PFTitleDataManagementGetPublisherDataRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementGetPublisherDataRequestWrapper(PFTitleDataManagementGetPublisherDataRequestWrapper&& src) :
        PFTitleDataManagementGetPublisherDataRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementGetPublisherDataRequestWrapper& operator=(PFTitleDataManagementGetPublisherDataRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementGetPublisherDataRequestWrapper() = default;

    friend void swap(PFTitleDataManagementGetPublisherDataRequestWrapper& lhs, PFTitleDataManagementGetPublisherDataRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_keys, rhs.m_keys);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetKeys(CStringVector<Alloc> value)
    {
        m_keys = std::move(value);
        this->m_model.keys =  m_keys.empty() ? nullptr : m_keys.data();
        this->m_model.keysCount =  static_cast<uint32_t>(m_keys.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.keys = m_keys.empty() ? nullptr : m_keys.data();
    }

    CStringVector<Alloc> m_keys;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementGetPublisherDataResultWrapper : public ModelWrapper<PFTitleDataManagementGetPublisherDataResult, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementGetPublisherDataResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementGetPublisherDataResultWrapper() = default;

    PFTitleDataManagementGetPublisherDataResultWrapper(const PFTitleDataManagementGetPublisherDataResult& model) :
        ModelWrapper<PFTitleDataManagementGetPublisherDataResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount }
    {
        SetModelPointers();
    }

    PFTitleDataManagementGetPublisherDataResultWrapper(const PFTitleDataManagementGetPublisherDataResultWrapper& src) :
        PFTitleDataManagementGetPublisherDataResultWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementGetPublisherDataResultWrapper(PFTitleDataManagementGetPublisherDataResultWrapper&& src) :
        PFTitleDataManagementGetPublisherDataResultWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementGetPublisherDataResultWrapper& operator=(PFTitleDataManagementGetPublisherDataResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementGetPublisherDataResultWrapper() = default;

    friend void swap(PFTitleDataManagementGetPublisherDataResultWrapper& lhs, PFTitleDataManagementGetPublisherDataResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(StringDictionaryEntryVector<Alloc> value)
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

    StringDictionaryEntryVector<Alloc> m_data;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementGetRandomResultTablesRequestWrapper : public ModelWrapper<PFTitleDataManagementGetRandomResultTablesRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementGetRandomResultTablesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementGetRandomResultTablesRequestWrapper() = default;

    PFTitleDataManagementGetRandomResultTablesRequestWrapper(const PFTitleDataManagementGetRandomResultTablesRequest& model) :
        ModelWrapper<PFTitleDataManagementGetRandomResultTablesRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementGetRandomResultTablesRequestWrapper(const PFTitleDataManagementGetRandomResultTablesRequestWrapper& src) :
        PFTitleDataManagementGetRandomResultTablesRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementGetRandomResultTablesRequestWrapper(PFTitleDataManagementGetRandomResultTablesRequestWrapper&& src) :
        PFTitleDataManagementGetRandomResultTablesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementGetRandomResultTablesRequestWrapper& operator=(PFTitleDataManagementGetRandomResultTablesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementGetRandomResultTablesRequestWrapper() = default;

    friend void swap(PFTitleDataManagementGetRandomResultTablesRequestWrapper& lhs, PFTitleDataManagementGetRandomResultTablesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    String m_catalogVersion;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementGetStoreItemsRequestWrapper : public ModelWrapper<PFTitleDataManagementGetStoreItemsRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementGetStoreItemsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementGetStoreItemsRequestWrapper() = default;

    PFTitleDataManagementGetStoreItemsRequestWrapper(const PFTitleDataManagementGetStoreItemsRequest& model) :
        ModelWrapper<PFTitleDataManagementGetStoreItemsRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_storeId{ SafeString(model.storeId) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementGetStoreItemsRequestWrapper(const PFTitleDataManagementGetStoreItemsRequestWrapper& src) :
        PFTitleDataManagementGetStoreItemsRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementGetStoreItemsRequestWrapper(PFTitleDataManagementGetStoreItemsRequestWrapper&& src) :
        PFTitleDataManagementGetStoreItemsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementGetStoreItemsRequestWrapper& operator=(PFTitleDataManagementGetStoreItemsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementGetStoreItemsRequestWrapper() = default;

    friend void swap(PFTitleDataManagementGetStoreItemsRequestWrapper& lhs, PFTitleDataManagementGetStoreItemsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_storeId, rhs.m_storeId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
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
        this->m_model.storeId = m_storeId.empty() ? nullptr : m_storeId.data();
    }

    String m_catalogVersion;
    String m_storeId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementStoreMarketingModelWrapper : public ModelWrapper<PFTitleDataManagementStoreMarketingModel, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementStoreMarketingModel;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementStoreMarketingModelWrapper() = default;

    PFTitleDataManagementStoreMarketingModelWrapper(const PFTitleDataManagementStoreMarketingModel& model) :
        ModelWrapper<PFTitleDataManagementStoreMarketingModel, Alloc>{ model },
        m_description{ SafeString(model.description) },
        m_displayName{ SafeString(model.displayName) },
        m_metadata{ model.metadata }
    {
        SetModelPointers();
    }

    PFTitleDataManagementStoreMarketingModelWrapper(const PFTitleDataManagementStoreMarketingModelWrapper& src) :
        PFTitleDataManagementStoreMarketingModelWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementStoreMarketingModelWrapper(PFTitleDataManagementStoreMarketingModelWrapper&& src) :
        PFTitleDataManagementStoreMarketingModelWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementStoreMarketingModelWrapper& operator=(PFTitleDataManagementStoreMarketingModelWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementStoreMarketingModelWrapper() = default;

    friend void swap(PFTitleDataManagementStoreMarketingModelWrapper& lhs, PFTitleDataManagementStoreMarketingModelWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_description, rhs.m_description);
        swap(lhs.m_displayName, rhs.m_displayName);
        swap(lhs.m_metadata, rhs.m_metadata);
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

    void SetMetadata(JsonObject<Alloc> value)
    {
        m_metadata = std::move(value);
        this->m_model.metadata.stringValue = m_metadata.stringValue.empty() ? nullptr : m_metadata.stringValue.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.description = m_description.empty() ? nullptr : m_description.data();
        this->m_model.displayName = m_displayName.empty() ? nullptr : m_displayName.data();
        this->m_model.metadata.stringValue = m_metadata.stringValue.empty() ? nullptr : m_metadata.stringValue.data();
    }

    String m_description;
    String m_displayName;
    JsonObject<Alloc> m_metadata;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementStoreItemWrapper : public ModelWrapper<PFTitleDataManagementStoreItem, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementStoreItem;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementStoreItemWrapper() = default;

    PFTitleDataManagementStoreItemWrapper(const PFTitleDataManagementStoreItem& model) :
        ModelWrapper<PFTitleDataManagementStoreItem, Alloc>{ model },
        m_customData{ model.customData },
        m_displayPosition{ model.displayPosition ? StdExtra::optional<uint32_t>{ *model.displayPosition } : StdExtra::nullopt },
        m_itemId{ SafeString(model.itemId) },
        m_realCurrencyPrices{ model.realCurrencyPrices, model.realCurrencyPrices + model.realCurrencyPricesCount },
        m_virtualCurrencyPrices{ model.virtualCurrencyPrices, model.virtualCurrencyPrices + model.virtualCurrencyPricesCount }
    {
        SetModelPointers();
    }

    PFTitleDataManagementStoreItemWrapper(const PFTitleDataManagementStoreItemWrapper& src) :
        PFTitleDataManagementStoreItemWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementStoreItemWrapper(PFTitleDataManagementStoreItemWrapper&& src) :
        PFTitleDataManagementStoreItemWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementStoreItemWrapper& operator=(PFTitleDataManagementStoreItemWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementStoreItemWrapper() = default;

    friend void swap(PFTitleDataManagementStoreItemWrapper& lhs, PFTitleDataManagementStoreItemWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customData, rhs.m_customData);
        swap(lhs.m_displayPosition, rhs.m_displayPosition);
        swap(lhs.m_itemId, rhs.m_itemId);
        swap(lhs.m_realCurrencyPrices, rhs.m_realCurrencyPrices);
        swap(lhs.m_virtualCurrencyPrices, rhs.m_virtualCurrencyPrices);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomData(JsonObject<Alloc> value)
    {
        m_customData = std::move(value);
        this->m_model.customData.stringValue = m_customData.stringValue.empty() ? nullptr : m_customData.stringValue.data();
    }

    void SetDisplayPosition(StdExtra::optional<uint32_t> value)
    {
        m_displayPosition = std::move(value);
        this->m_model.displayPosition = m_displayPosition ? m_displayPosition.operator->() : nullptr;
    }

    void SetItemId(String value)
    {
        m_itemId = std::move(value);
        this->m_model.itemId =  m_itemId.empty() ? nullptr : m_itemId.data();
    }

    void SetRealCurrencyPrices(DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> value)
    {
        m_realCurrencyPrices = std::move(value);
        this->m_model.realCurrencyPrices =  m_realCurrencyPrices.empty() ? nullptr : m_realCurrencyPrices.data();
        this->m_model.realCurrencyPricesCount =  static_cast<uint32_t>(m_realCurrencyPrices.size());
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
        this->m_model.customData.stringValue = m_customData.stringValue.empty() ? nullptr : m_customData.stringValue.data();
        this->m_model.displayPosition = m_displayPosition ? m_displayPosition.operator->() : nullptr;
        this->m_model.itemId = m_itemId.empty() ? nullptr : m_itemId.data();
        this->m_model.realCurrencyPrices = m_realCurrencyPrices.empty() ? nullptr : m_realCurrencyPrices.data();
        this->m_model.virtualCurrencyPrices = m_virtualCurrencyPrices.empty() ? nullptr : m_virtualCurrencyPrices.data();
    }

    JsonObject<Alloc> m_customData;
    StdExtra::optional<uint32_t> m_displayPosition;
    String m_itemId;
    DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> m_realCurrencyPrices;
    DictionaryEntryVector<PFUint32DictionaryEntry, Alloc> m_virtualCurrencyPrices;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementGetStoreItemsResultWrapper : public ModelWrapper<PFTitleDataManagementGetStoreItemsResult, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementGetStoreItemsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementGetStoreItemsResultWrapper() = default;

    PFTitleDataManagementGetStoreItemsResultWrapper(const PFTitleDataManagementGetStoreItemsResult& model) :
        ModelWrapper<PFTitleDataManagementGetStoreItemsResult, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_marketingData{ model.marketingData ? StdExtra::optional<PFTitleDataManagementStoreMarketingModelWrapper<Alloc>>{ *model.marketingData } : StdExtra::nullopt },
        m_source{ model.source ? StdExtra::optional<PFTitleDataManagementSourceType>{ *model.source } : StdExtra::nullopt },
        m_store{ model.store, model.store + model.storeCount },
        m_storeId{ SafeString(model.storeId) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementGetStoreItemsResultWrapper(const PFTitleDataManagementGetStoreItemsResultWrapper& src) :
        PFTitleDataManagementGetStoreItemsResultWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementGetStoreItemsResultWrapper(PFTitleDataManagementGetStoreItemsResultWrapper&& src) :
        PFTitleDataManagementGetStoreItemsResultWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementGetStoreItemsResultWrapper& operator=(PFTitleDataManagementGetStoreItemsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementGetStoreItemsResultWrapper() = default;

    friend void swap(PFTitleDataManagementGetStoreItemsResultWrapper& lhs, PFTitleDataManagementGetStoreItemsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_marketingData, rhs.m_marketingData);
        swap(lhs.m_source, rhs.m_source);
        swap(lhs.m_store, rhs.m_store);
        swap(lhs.m_storeId, rhs.m_storeId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogVersion(String value)
    {
        m_catalogVersion = std::move(value);
        this->m_model.catalogVersion =  m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
    }

    void SetMarketingData(StdExtra::optional<PFTitleDataManagementStoreMarketingModelWrapper<Alloc>> value)
    {
        m_marketingData = std::move(value);
        this->m_model.marketingData = m_marketingData ? &m_marketingData->Model() : nullptr;
    }

    void SetSource(StdExtra::optional<PFTitleDataManagementSourceType> value)
    {
        m_source = std::move(value);
        this->m_model.source = m_source ? m_source.operator->() : nullptr;
    }

    void SetStore(ModelVector<PFTitleDataManagementStoreItemWrapper<Alloc>, Alloc> value)
    {
        m_store = std::move(value);
        this->m_model.store =  m_store.empty() ? nullptr : m_store.data();
        this->m_model.storeCount =  static_cast<uint32_t>(m_store.size());
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
        this->m_model.marketingData = m_marketingData ?  &m_marketingData->Model() : nullptr;
        this->m_model.source = m_source ? m_source.operator->() : nullptr;
        this->m_model.store = m_store.empty() ? nullptr : m_store.data();
        this->m_model.storeId = m_storeId.empty() ? nullptr : m_storeId.data();
    }

    String m_catalogVersion;
    StdExtra::optional<PFTitleDataManagementStoreMarketingModelWrapper<Alloc>> m_marketingData;
    StdExtra::optional<PFTitleDataManagementSourceType> m_source;
    ModelVector<PFTitleDataManagementStoreItemWrapper<Alloc>, Alloc> m_store;
    String m_storeId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementGetTitleDataRequestWrapper : public ModelWrapper<PFTitleDataManagementGetTitleDataRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementGetTitleDataRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementGetTitleDataRequestWrapper() = default;

    PFTitleDataManagementGetTitleDataRequestWrapper(const PFTitleDataManagementGetTitleDataRequest& model) :
        ModelWrapper<PFTitleDataManagementGetTitleDataRequest, Alloc>{ model },
        m_keys{ model.keys, model.keys + model.keysCount },
        m_overrideLabel{ SafeString(model.overrideLabel) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementGetTitleDataRequestWrapper(const PFTitleDataManagementGetTitleDataRequestWrapper& src) :
        PFTitleDataManagementGetTitleDataRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementGetTitleDataRequestWrapper(PFTitleDataManagementGetTitleDataRequestWrapper&& src) :
        PFTitleDataManagementGetTitleDataRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementGetTitleDataRequestWrapper& operator=(PFTitleDataManagementGetTitleDataRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementGetTitleDataRequestWrapper() = default;

    friend void swap(PFTitleDataManagementGetTitleDataRequestWrapper& lhs, PFTitleDataManagementGetTitleDataRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_keys, rhs.m_keys);
        swap(lhs.m_overrideLabel, rhs.m_overrideLabel);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetKeys(CStringVector<Alloc> value)
    {
        m_keys = std::move(value);
        this->m_model.keys =  m_keys.empty() ? nullptr : m_keys.data();
        this->m_model.keysCount =  static_cast<uint32_t>(m_keys.size());
    }

    void SetOverrideLabel(String value)
    {
        m_overrideLabel = std::move(value);
        this->m_model.overrideLabel =  m_overrideLabel.empty() ? nullptr : m_overrideLabel.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.keys = m_keys.empty() ? nullptr : m_keys.data();
        this->m_model.overrideLabel = m_overrideLabel.empty() ? nullptr : m_overrideLabel.data();
    }

    CStringVector<Alloc> m_keys;
    String m_overrideLabel;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementGetTitleDataResultWrapper : public ModelWrapper<PFTitleDataManagementGetTitleDataResult, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementGetTitleDataResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementGetTitleDataResultWrapper() = default;

    PFTitleDataManagementGetTitleDataResultWrapper(const PFTitleDataManagementGetTitleDataResult& model) :
        ModelWrapper<PFTitleDataManagementGetTitleDataResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount }
    {
        SetModelPointers();
    }

    PFTitleDataManagementGetTitleDataResultWrapper(const PFTitleDataManagementGetTitleDataResultWrapper& src) :
        PFTitleDataManagementGetTitleDataResultWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementGetTitleDataResultWrapper(PFTitleDataManagementGetTitleDataResultWrapper&& src) :
        PFTitleDataManagementGetTitleDataResultWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementGetTitleDataResultWrapper& operator=(PFTitleDataManagementGetTitleDataResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementGetTitleDataResultWrapper() = default;

    friend void swap(PFTitleDataManagementGetTitleDataResultWrapper& lhs, PFTitleDataManagementGetTitleDataResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(StringDictionaryEntryVector<Alloc> value)
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

    StringDictionaryEntryVector<Alloc> m_data;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementListVirtualCurrencyTypesResultWrapper : public ModelWrapper<PFTitleDataManagementListVirtualCurrencyTypesResult, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementListVirtualCurrencyTypesResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementListVirtualCurrencyTypesResultWrapper() = default;

    PFTitleDataManagementListVirtualCurrencyTypesResultWrapper(const PFTitleDataManagementListVirtualCurrencyTypesResult& model) :
        ModelWrapper<PFTitleDataManagementListVirtualCurrencyTypesResult, Alloc>{ model },
        m_virtualCurrencies{ model.virtualCurrencies, model.virtualCurrencies + model.virtualCurrenciesCount }
    {
        SetModelPointers();
    }

    PFTitleDataManagementListVirtualCurrencyTypesResultWrapper(const PFTitleDataManagementListVirtualCurrencyTypesResultWrapper& src) :
        PFTitleDataManagementListVirtualCurrencyTypesResultWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementListVirtualCurrencyTypesResultWrapper(PFTitleDataManagementListVirtualCurrencyTypesResultWrapper&& src) :
        PFTitleDataManagementListVirtualCurrencyTypesResultWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementListVirtualCurrencyTypesResultWrapper& operator=(PFTitleDataManagementListVirtualCurrencyTypesResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementListVirtualCurrencyTypesResultWrapper() = default;

    friend void swap(PFTitleDataManagementListVirtualCurrencyTypesResultWrapper& lhs, PFTitleDataManagementListVirtualCurrencyTypesResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_virtualCurrencies, rhs.m_virtualCurrencies);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetVirtualCurrencies(ModelVector<PFTitleDataManagementVirtualCurrencyDataWrapper<Alloc>, Alloc> value)
    {
        m_virtualCurrencies = std::move(value);
        this->m_model.virtualCurrencies =  m_virtualCurrencies.empty() ? nullptr : m_virtualCurrencies.data();
        this->m_model.virtualCurrenciesCount =  static_cast<uint32_t>(m_virtualCurrencies.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.virtualCurrencies = m_virtualCurrencies.empty() ? nullptr : m_virtualCurrencies.data();
    }

    ModelVector<PFTitleDataManagementVirtualCurrencyDataWrapper<Alloc>, Alloc> m_virtualCurrencies;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper : public ModelWrapper<PFTitleDataManagementRemoveVirtualCurrencyTypesRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementRemoveVirtualCurrencyTypesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper() = default;

    PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper(const PFTitleDataManagementRemoveVirtualCurrencyTypesRequest& model) :
        ModelWrapper<PFTitleDataManagementRemoveVirtualCurrencyTypesRequest, Alloc>{ model },
        m_virtualCurrencies{ model.virtualCurrencies, model.virtualCurrencies + model.virtualCurrenciesCount }
    {
        SetModelPointers();
    }

    PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper(const PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper& src) :
        PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper(PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper&& src) :
        PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper& operator=(PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper() = default;

    friend void swap(PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper& lhs, PFTitleDataManagementRemoveVirtualCurrencyTypesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_virtualCurrencies, rhs.m_virtualCurrencies);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetVirtualCurrencies(ModelVector<PFTitleDataManagementVirtualCurrencyDataWrapper<Alloc>, Alloc> value)
    {
        m_virtualCurrencies = std::move(value);
        this->m_model.virtualCurrencies =  m_virtualCurrencies.empty() ? nullptr : m_virtualCurrencies.data();
        this->m_model.virtualCurrenciesCount =  static_cast<uint32_t>(m_virtualCurrencies.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.virtualCurrencies = m_virtualCurrencies.empty() ? nullptr : m_virtualCurrencies.data();
    }

    ModelVector<PFTitleDataManagementVirtualCurrencyDataWrapper<Alloc>, Alloc> m_virtualCurrencies;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementUpdateCatalogItemsRequestWrapper : public ModelWrapper<PFTitleDataManagementUpdateCatalogItemsRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementUpdateCatalogItemsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementUpdateCatalogItemsRequestWrapper() = default;

    PFTitleDataManagementUpdateCatalogItemsRequestWrapper(const PFTitleDataManagementUpdateCatalogItemsRequest& model) :
        ModelWrapper<PFTitleDataManagementUpdateCatalogItemsRequest, Alloc>{ model },
        m_catalog{ model.catalog, model.catalog + model.catalogCount },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_setAsDefaultCatalog{ model.setAsDefaultCatalog ? StdExtra::optional<bool>{ *model.setAsDefaultCatalog } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFTitleDataManagementUpdateCatalogItemsRequestWrapper(const PFTitleDataManagementUpdateCatalogItemsRequestWrapper& src) :
        PFTitleDataManagementUpdateCatalogItemsRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementUpdateCatalogItemsRequestWrapper(PFTitleDataManagementUpdateCatalogItemsRequestWrapper&& src) :
        PFTitleDataManagementUpdateCatalogItemsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementUpdateCatalogItemsRequestWrapper& operator=(PFTitleDataManagementUpdateCatalogItemsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementUpdateCatalogItemsRequestWrapper() = default;

    friend void swap(PFTitleDataManagementUpdateCatalogItemsRequestWrapper& lhs, PFTitleDataManagementUpdateCatalogItemsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalog, rhs.m_catalog);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_setAsDefaultCatalog, rhs.m_setAsDefaultCatalog);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalog(ModelVector<PFTitleDataManagementCatalogItemWrapper<Alloc>, Alloc> value)
    {
        m_catalog = std::move(value);
        this->m_model.catalog =  m_catalog.empty() ? nullptr : m_catalog.data();
        this->m_model.catalogCount =  static_cast<uint32_t>(m_catalog.size());
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

    void SetSetAsDefaultCatalog(StdExtra::optional<bool> value)
    {
        m_setAsDefaultCatalog = std::move(value);
        this->m_model.setAsDefaultCatalog = m_setAsDefaultCatalog ? m_setAsDefaultCatalog.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalog = m_catalog.empty() ? nullptr : m_catalog.data();
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.setAsDefaultCatalog = m_setAsDefaultCatalog ? m_setAsDefaultCatalog.operator->() : nullptr;
    }

    ModelVector<PFTitleDataManagementCatalogItemWrapper<Alloc>, Alloc> m_catalog;
    String m_catalogVersion;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_setAsDefaultCatalog;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementSetPublisherDataRequestWrapper : public ModelWrapper<PFTitleDataManagementSetPublisherDataRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementSetPublisherDataRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementSetPublisherDataRequestWrapper() = default;

    PFTitleDataManagementSetPublisherDataRequestWrapper(const PFTitleDataManagementSetPublisherDataRequest& model) :
        ModelWrapper<PFTitleDataManagementSetPublisherDataRequest, Alloc>{ model },
        m_key{ SafeString(model.key) },
        m_value{ SafeString(model.value) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementSetPublisherDataRequestWrapper(const PFTitleDataManagementSetPublisherDataRequestWrapper& src) :
        PFTitleDataManagementSetPublisherDataRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementSetPublisherDataRequestWrapper(PFTitleDataManagementSetPublisherDataRequestWrapper&& src) :
        PFTitleDataManagementSetPublisherDataRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementSetPublisherDataRequestWrapper& operator=(PFTitleDataManagementSetPublisherDataRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementSetPublisherDataRequestWrapper() = default;

    friend void swap(PFTitleDataManagementSetPublisherDataRequestWrapper& lhs, PFTitleDataManagementSetPublisherDataRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_key, rhs.m_key);
        swap(lhs.m_value, rhs.m_value);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetKey(String value)
    {
        m_key = std::move(value);
        this->m_model.key =  m_key.empty() ? nullptr : m_key.data();
    }

    void SetValue(String value)
    {
        m_value = std::move(value);
        this->m_model.value =  m_value.empty() ? nullptr : m_value.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.key = m_key.empty() ? nullptr : m_key.data();
        this->m_model.value = m_value.empty() ? nullptr : m_value.data();
    }

    String m_key;
    String m_value;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementUpdateStoreItemsRequestWrapper : public ModelWrapper<PFTitleDataManagementUpdateStoreItemsRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementUpdateStoreItemsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementUpdateStoreItemsRequestWrapper() = default;

    PFTitleDataManagementUpdateStoreItemsRequestWrapper(const PFTitleDataManagementUpdateStoreItemsRequest& model) :
        ModelWrapper<PFTitleDataManagementUpdateStoreItemsRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_marketingData{ model.marketingData ? StdExtra::optional<PFTitleDataManagementStoreMarketingModelWrapper<Alloc>>{ *model.marketingData } : StdExtra::nullopt },
        m_store{ model.store, model.store + model.storeCount },
        m_storeId{ SafeString(model.storeId) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementUpdateStoreItemsRequestWrapper(const PFTitleDataManagementUpdateStoreItemsRequestWrapper& src) :
        PFTitleDataManagementUpdateStoreItemsRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementUpdateStoreItemsRequestWrapper(PFTitleDataManagementUpdateStoreItemsRequestWrapper&& src) :
        PFTitleDataManagementUpdateStoreItemsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementUpdateStoreItemsRequestWrapper& operator=(PFTitleDataManagementUpdateStoreItemsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementUpdateStoreItemsRequestWrapper() = default;

    friend void swap(PFTitleDataManagementUpdateStoreItemsRequestWrapper& lhs, PFTitleDataManagementUpdateStoreItemsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_marketingData, rhs.m_marketingData);
        swap(lhs.m_store, rhs.m_store);
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

    void SetMarketingData(StdExtra::optional<PFTitleDataManagementStoreMarketingModelWrapper<Alloc>> value)
    {
        m_marketingData = std::move(value);
        this->m_model.marketingData = m_marketingData ? &m_marketingData->Model() : nullptr;
    }

    void SetStore(ModelVector<PFTitleDataManagementStoreItemWrapper<Alloc>, Alloc> value)
    {
        m_store = std::move(value);
        this->m_model.store =  m_store.empty() ? nullptr : m_store.data();
        this->m_model.storeCount =  static_cast<uint32_t>(m_store.size());
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
        this->m_model.marketingData = m_marketingData ?  &m_marketingData->Model() : nullptr;
        this->m_model.store = m_store.empty() ? nullptr : m_store.data();
        this->m_model.storeId = m_storeId.empty() ? nullptr : m_storeId.data();
    }

    String m_catalogVersion;
    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFTitleDataManagementStoreMarketingModelWrapper<Alloc>> m_marketingData;
    ModelVector<PFTitleDataManagementStoreItemWrapper<Alloc>, Alloc> m_store;
    String m_storeId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementSetTitleDataRequestWrapper : public ModelWrapper<PFTitleDataManagementSetTitleDataRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementSetTitleDataRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementSetTitleDataRequestWrapper() = default;

    PFTitleDataManagementSetTitleDataRequestWrapper(const PFTitleDataManagementSetTitleDataRequest& model) :
        ModelWrapper<PFTitleDataManagementSetTitleDataRequest, Alloc>{ model },
        m_azureResourceId{ SafeString(model.azureResourceId) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_key{ SafeString(model.key) },
        m_titleId{ SafeString(model.titleId) },
        m_value{ SafeString(model.value) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementSetTitleDataRequestWrapper(const PFTitleDataManagementSetTitleDataRequestWrapper& src) :
        PFTitleDataManagementSetTitleDataRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementSetTitleDataRequestWrapper(PFTitleDataManagementSetTitleDataRequestWrapper&& src) :
        PFTitleDataManagementSetTitleDataRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementSetTitleDataRequestWrapper& operator=(PFTitleDataManagementSetTitleDataRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementSetTitleDataRequestWrapper() = default;

    friend void swap(PFTitleDataManagementSetTitleDataRequestWrapper& lhs, PFTitleDataManagementSetTitleDataRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_azureResourceId, rhs.m_azureResourceId);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_key, rhs.m_key);
        swap(lhs.m_titleId, rhs.m_titleId);
        swap(lhs.m_value, rhs.m_value);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAzureResourceId(String value)
    {
        m_azureResourceId = std::move(value);
        this->m_model.azureResourceId =  m_azureResourceId.empty() ? nullptr : m_azureResourceId.data();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetKey(String value)
    {
        m_key = std::move(value);
        this->m_model.key =  m_key.empty() ? nullptr : m_key.data();
    }

    void SetTitleId(String value)
    {
        m_titleId = std::move(value);
        this->m_model.titleId =  m_titleId.empty() ? nullptr : m_titleId.data();
    }

    void SetValue(String value)
    {
        m_value = std::move(value);
        this->m_model.value =  m_value.empty() ? nullptr : m_value.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.azureResourceId = m_azureResourceId.empty() ? nullptr : m_azureResourceId.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.key = m_key.empty() ? nullptr : m_key.data();
        this->m_model.titleId = m_titleId.empty() ? nullptr : m_titleId.data();
        this->m_model.value = m_value.empty() ? nullptr : m_value.data();
    }

    String m_azureResourceId;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_key;
    String m_titleId;
    String m_value;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementSetTitleDataResultWrapper : public ModelWrapper<PFTitleDataManagementSetTitleDataResult, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementSetTitleDataResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementSetTitleDataResultWrapper() = default;

    PFTitleDataManagementSetTitleDataResultWrapper(const PFTitleDataManagementSetTitleDataResult& model) :
        ModelWrapper<PFTitleDataManagementSetTitleDataResult, Alloc>{ model },
        m_azureResourceId{ SafeString(model.azureResourceId) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementSetTitleDataResultWrapper(const PFTitleDataManagementSetTitleDataResultWrapper& src) :
        PFTitleDataManagementSetTitleDataResultWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementSetTitleDataResultWrapper(PFTitleDataManagementSetTitleDataResultWrapper&& src) :
        PFTitleDataManagementSetTitleDataResultWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementSetTitleDataResultWrapper& operator=(PFTitleDataManagementSetTitleDataResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementSetTitleDataResultWrapper() = default;

    friend void swap(PFTitleDataManagementSetTitleDataResultWrapper& lhs, PFTitleDataManagementSetTitleDataResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_azureResourceId, rhs.m_azureResourceId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAzureResourceId(String value)
    {
        m_azureResourceId = std::move(value);
        this->m_model.azureResourceId =  m_azureResourceId.empty() ? nullptr : m_azureResourceId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.azureResourceId = m_azureResourceId.empty() ? nullptr : m_azureResourceId.data();
    }

    String m_azureResourceId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementTitleDataKeyValueWrapper : public ModelWrapper<PFTitleDataManagementTitleDataKeyValue, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementTitleDataKeyValue;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementTitleDataKeyValueWrapper() = default;

    PFTitleDataManagementTitleDataKeyValueWrapper(const PFTitleDataManagementTitleDataKeyValue& model) :
        ModelWrapper<PFTitleDataManagementTitleDataKeyValue, Alloc>{ model },
        m_key{ SafeString(model.key) },
        m_value{ SafeString(model.value) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementTitleDataKeyValueWrapper(const PFTitleDataManagementTitleDataKeyValueWrapper& src) :
        PFTitleDataManagementTitleDataKeyValueWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementTitleDataKeyValueWrapper(PFTitleDataManagementTitleDataKeyValueWrapper&& src) :
        PFTitleDataManagementTitleDataKeyValueWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementTitleDataKeyValueWrapper& operator=(PFTitleDataManagementTitleDataKeyValueWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementTitleDataKeyValueWrapper() = default;

    friend void swap(PFTitleDataManagementTitleDataKeyValueWrapper& lhs, PFTitleDataManagementTitleDataKeyValueWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_key, rhs.m_key);
        swap(lhs.m_value, rhs.m_value);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetKey(String value)
    {
        m_key = std::move(value);
        this->m_model.key =  m_key.empty() ? nullptr : m_key.data();
    }

    void SetValue(String value)
    {
        m_value = std::move(value);
        this->m_model.value =  m_value.empty() ? nullptr : m_value.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.key = m_key.empty() ? nullptr : m_key.data();
        this->m_model.value = m_value.empty() ? nullptr : m_value.data();
    }

    String m_key;
    String m_value;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper : public ModelWrapper<PFTitleDataManagementSetTitleDataAndOverridesRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementSetTitleDataAndOverridesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper() = default;

    PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper(const PFTitleDataManagementSetTitleDataAndOverridesRequest& model) :
        ModelWrapper<PFTitleDataManagementSetTitleDataAndOverridesRequest, Alloc>{ model },
        m_keyValues{ model.keyValues, model.keyValues + model.keyValuesCount },
        m_overrideLabel{ SafeString(model.overrideLabel) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper(const PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper& src) :
        PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper(PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper&& src) :
        PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper& operator=(PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper() = default;

    friend void swap(PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper& lhs, PFTitleDataManagementSetTitleDataAndOverridesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_keyValues, rhs.m_keyValues);
        swap(lhs.m_overrideLabel, rhs.m_overrideLabel);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetKeyValues(ModelVector<PFTitleDataManagementTitleDataKeyValueWrapper<Alloc>, Alloc> value)
    {
        m_keyValues = std::move(value);
        this->m_model.keyValues =  m_keyValues.empty() ? nullptr : m_keyValues.data();
        this->m_model.keyValuesCount =  static_cast<uint32_t>(m_keyValues.size());
    }

    void SetOverrideLabel(String value)
    {
        m_overrideLabel = std::move(value);
        this->m_model.overrideLabel =  m_overrideLabel.empty() ? nullptr : m_overrideLabel.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.keyValues = m_keyValues.empty() ? nullptr : m_keyValues.data();
        this->m_model.overrideLabel = m_overrideLabel.empty() ? nullptr : m_overrideLabel.data();
    }

    ModelVector<PFTitleDataManagementTitleDataKeyValueWrapper<Alloc>, Alloc> m_keyValues;
    String m_overrideLabel;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementSetupPushNotificationRequestWrapper : public ModelWrapper<PFTitleDataManagementSetupPushNotificationRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementSetupPushNotificationRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementSetupPushNotificationRequestWrapper() = default;

    PFTitleDataManagementSetupPushNotificationRequestWrapper(const PFTitleDataManagementSetupPushNotificationRequest& model) :
        ModelWrapper<PFTitleDataManagementSetupPushNotificationRequest, Alloc>{ model },
        m_credential{ SafeString(model.credential) },
        m_key{ SafeString(model.key) },
        m_name{ SafeString(model.name) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementSetupPushNotificationRequestWrapper(const PFTitleDataManagementSetupPushNotificationRequestWrapper& src) :
        PFTitleDataManagementSetupPushNotificationRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementSetupPushNotificationRequestWrapper(PFTitleDataManagementSetupPushNotificationRequestWrapper&& src) :
        PFTitleDataManagementSetupPushNotificationRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementSetupPushNotificationRequestWrapper& operator=(PFTitleDataManagementSetupPushNotificationRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementSetupPushNotificationRequestWrapper() = default;

    friend void swap(PFTitleDataManagementSetupPushNotificationRequestWrapper& lhs, PFTitleDataManagementSetupPushNotificationRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_credential, rhs.m_credential);
        swap(lhs.m_key, rhs.m_key);
        swap(lhs.m_name, rhs.m_name);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCredential(String value)
    {
        m_credential = std::move(value);
        this->m_model.credential =  m_credential.empty() ? nullptr : m_credential.data();
    }

    void SetKey(String value)
    {
        m_key = std::move(value);
        this->m_model.key =  m_key.empty() ? nullptr : m_key.data();
    }

    void SetName(String value)
    {
        m_name = std::move(value);
        this->m_model.name =  m_name.empty() ? nullptr : m_name.data();
    }

    void SetOverwriteOldARN(bool value)
    {
        this->m_model.overwriteOldARN = value;
    }

    void SetPlatform(PFTitleDataManagementPushSetupPlatform value)
    {
        this->m_model.platform = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.credential = m_credential.empty() ? nullptr : m_credential.data();
        this->m_model.key = m_key.empty() ? nullptr : m_key.data();
        this->m_model.name = m_name.empty() ? nullptr : m_name.data();
    }

    String m_credential;
    String m_key;
    String m_name;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementSetupPushNotificationResultWrapper : public ModelWrapper<PFTitleDataManagementSetupPushNotificationResult, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementSetupPushNotificationResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementSetupPushNotificationResultWrapper() = default;

    PFTitleDataManagementSetupPushNotificationResultWrapper(const PFTitleDataManagementSetupPushNotificationResult& model) :
        ModelWrapper<PFTitleDataManagementSetupPushNotificationResult, Alloc>{ model },
        m_aRN{ SafeString(model.aRN) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementSetupPushNotificationResultWrapper(const PFTitleDataManagementSetupPushNotificationResultWrapper& src) :
        PFTitleDataManagementSetupPushNotificationResultWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementSetupPushNotificationResultWrapper(PFTitleDataManagementSetupPushNotificationResultWrapper&& src) :
        PFTitleDataManagementSetupPushNotificationResultWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementSetupPushNotificationResultWrapper& operator=(PFTitleDataManagementSetupPushNotificationResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementSetupPushNotificationResultWrapper() = default;

    friend void swap(PFTitleDataManagementSetupPushNotificationResultWrapper& lhs, PFTitleDataManagementSetupPushNotificationResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_aRN, rhs.m_aRN);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetARN(String value)
    {
        m_aRN = std::move(value);
        this->m_model.aRN =  m_aRN.empty() ? nullptr : m_aRN.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.aRN = m_aRN.empty() ? nullptr : m_aRN.data();
    }

    String m_aRN;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementRandomResultTableWrapper : public ModelWrapper<PFTitleDataManagementRandomResultTable, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementRandomResultTable;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementRandomResultTableWrapper() = default;

    PFTitleDataManagementRandomResultTableWrapper(const PFTitleDataManagementRandomResultTable& model) :
        ModelWrapper<PFTitleDataManagementRandomResultTable, Alloc>{ model },
        m_nodes{ model.nodes, model.nodes + model.nodesCount },
        m_tableId{ SafeString(model.tableId) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementRandomResultTableWrapper(const PFTitleDataManagementRandomResultTableWrapper& src) :
        PFTitleDataManagementRandomResultTableWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementRandomResultTableWrapper(PFTitleDataManagementRandomResultTableWrapper&& src) :
        PFTitleDataManagementRandomResultTableWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementRandomResultTableWrapper& operator=(PFTitleDataManagementRandomResultTableWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementRandomResultTableWrapper() = default;

    friend void swap(PFTitleDataManagementRandomResultTableWrapper& lhs, PFTitleDataManagementRandomResultTableWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_nodes, rhs.m_nodes);
        swap(lhs.m_tableId, rhs.m_tableId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetNodes(ModelVector<PFResultTableNodeWrapper<Alloc>, Alloc> value)
    {
        m_nodes = std::move(value);
        this->m_model.nodes =  m_nodes.empty() ? nullptr : m_nodes.data();
        this->m_model.nodesCount =  static_cast<uint32_t>(m_nodes.size());
    }

    void SetTableId(String value)
    {
        m_tableId = std::move(value);
        this->m_model.tableId =  m_tableId.empty() ? nullptr : m_tableId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.nodes = m_nodes.empty() ? nullptr : m_nodes.data();
        this->m_model.tableId = m_tableId.empty() ? nullptr : m_tableId.data();
    }

    ModelVector<PFResultTableNodeWrapper<Alloc>, Alloc> m_nodes;
    String m_tableId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementUpdateRandomResultTablesRequestWrapper : public ModelWrapper<PFTitleDataManagementUpdateRandomResultTablesRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementUpdateRandomResultTablesRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementUpdateRandomResultTablesRequestWrapper() = default;

    PFTitleDataManagementUpdateRandomResultTablesRequestWrapper(const PFTitleDataManagementUpdateRandomResultTablesRequest& model) :
        ModelWrapper<PFTitleDataManagementUpdateRandomResultTablesRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_tables{ model.tables, model.tables + model.tablesCount }
    {
        SetModelPointers();
    }

    PFTitleDataManagementUpdateRandomResultTablesRequestWrapper(const PFTitleDataManagementUpdateRandomResultTablesRequestWrapper& src) :
        PFTitleDataManagementUpdateRandomResultTablesRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementUpdateRandomResultTablesRequestWrapper(PFTitleDataManagementUpdateRandomResultTablesRequestWrapper&& src) :
        PFTitleDataManagementUpdateRandomResultTablesRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementUpdateRandomResultTablesRequestWrapper& operator=(PFTitleDataManagementUpdateRandomResultTablesRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementUpdateRandomResultTablesRequestWrapper() = default;

    friend void swap(PFTitleDataManagementUpdateRandomResultTablesRequestWrapper& lhs, PFTitleDataManagementUpdateRandomResultTablesRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_tables, rhs.m_tables);
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

    void SetTables(ModelVector<PFTitleDataManagementRandomResultTableWrapper<Alloc>, Alloc> value)
    {
        m_tables = std::move(value);
        this->m_model.tables =  m_tables.empty() ? nullptr : m_tables.data();
        this->m_model.tablesCount =  static_cast<uint32_t>(m_tables.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogVersion = m_catalogVersion.empty() ? nullptr : m_catalogVersion.data();
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.tables = m_tables.empty() ? nullptr : m_tables.data();
    }

    String m_catalogVersion;
    StringDictionaryEntryVector<Alloc> m_customTags;
    ModelVector<PFTitleDataManagementRandomResultTableWrapper<Alloc>, Alloc> m_tables;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementGetTimeResultWrapper : public ModelWrapper<PFTitleDataManagementGetTimeResult, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementGetTimeResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    using ModelWrapper<PFTitleDataManagementGetTimeResult, Alloc>::ModelWrapper;

    void SetTime(time_t value)
    {
        this->m_model.time = value;
    }

private:
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementGetTitleNewsRequestWrapper : public ModelWrapper<PFTitleDataManagementGetTitleNewsRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementGetTitleNewsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementGetTitleNewsRequestWrapper() = default;

    PFTitleDataManagementGetTitleNewsRequestWrapper(const PFTitleDataManagementGetTitleNewsRequest& model) :
        ModelWrapper<PFTitleDataManagementGetTitleNewsRequest, Alloc>{ model },
        m_count{ model.count ? StdExtra::optional<int32_t>{ *model.count } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFTitleDataManagementGetTitleNewsRequestWrapper(const PFTitleDataManagementGetTitleNewsRequestWrapper& src) :
        PFTitleDataManagementGetTitleNewsRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementGetTitleNewsRequestWrapper(PFTitleDataManagementGetTitleNewsRequestWrapper&& src) :
        PFTitleDataManagementGetTitleNewsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementGetTitleNewsRequestWrapper& operator=(PFTitleDataManagementGetTitleNewsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementGetTitleNewsRequestWrapper() = default;

    friend void swap(PFTitleDataManagementGetTitleNewsRequestWrapper& lhs, PFTitleDataManagementGetTitleNewsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_count, rhs.m_count);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCount(StdExtra::optional<int32_t> value)
    {
        m_count = std::move(value);
        this->m_model.count = m_count ? m_count.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.count = m_count ? m_count.operator->() : nullptr;
    }

    StdExtra::optional<int32_t> m_count;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementTitleNewsItemWrapper : public ModelWrapper<PFTitleDataManagementTitleNewsItem, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementTitleNewsItem;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementTitleNewsItemWrapper() = default;

    PFTitleDataManagementTitleNewsItemWrapper(const PFTitleDataManagementTitleNewsItem& model) :
        ModelWrapper<PFTitleDataManagementTitleNewsItem, Alloc>{ model },
        m_body{ SafeString(model.body) },
        m_newsId{ SafeString(model.newsId) },
        m_title{ SafeString(model.title) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementTitleNewsItemWrapper(const PFTitleDataManagementTitleNewsItemWrapper& src) :
        PFTitleDataManagementTitleNewsItemWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementTitleNewsItemWrapper(PFTitleDataManagementTitleNewsItemWrapper&& src) :
        PFTitleDataManagementTitleNewsItemWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementTitleNewsItemWrapper& operator=(PFTitleDataManagementTitleNewsItemWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementTitleNewsItemWrapper() = default;

    friend void swap(PFTitleDataManagementTitleNewsItemWrapper& lhs, PFTitleDataManagementTitleNewsItemWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_body, rhs.m_body);
        swap(lhs.m_newsId, rhs.m_newsId);
        swap(lhs.m_title, rhs.m_title);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetBody(String value)
    {
        m_body = std::move(value);
        this->m_model.body =  m_body.empty() ? nullptr : m_body.data();
    }

    void SetNewsId(String value)
    {
        m_newsId = std::move(value);
        this->m_model.newsId =  m_newsId.empty() ? nullptr : m_newsId.data();
    }

    void SetTimestamp(time_t value)
    {
        this->m_model.timestamp = value;
    }

    void SetTitle(String value)
    {
        m_title = std::move(value);
        this->m_model.title =  m_title.empty() ? nullptr : m_title.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.body = m_body.empty() ? nullptr : m_body.data();
        this->m_model.newsId = m_newsId.empty() ? nullptr : m_newsId.data();
        this->m_model.title = m_title.empty() ? nullptr : m_title.data();
    }

    String m_body;
    String m_newsId;
    String m_title;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementGetTitleNewsResultWrapper : public ModelWrapper<PFTitleDataManagementGetTitleNewsResult, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementGetTitleNewsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementGetTitleNewsResultWrapper() = default;

    PFTitleDataManagementGetTitleNewsResultWrapper(const PFTitleDataManagementGetTitleNewsResult& model) :
        ModelWrapper<PFTitleDataManagementGetTitleNewsResult, Alloc>{ model },
        m_news{ model.news, model.news + model.newsCount }
    {
        SetModelPointers();
    }

    PFTitleDataManagementGetTitleNewsResultWrapper(const PFTitleDataManagementGetTitleNewsResultWrapper& src) :
        PFTitleDataManagementGetTitleNewsResultWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementGetTitleNewsResultWrapper(PFTitleDataManagementGetTitleNewsResultWrapper&& src) :
        PFTitleDataManagementGetTitleNewsResultWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementGetTitleNewsResultWrapper& operator=(PFTitleDataManagementGetTitleNewsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementGetTitleNewsResultWrapper() = default;

    friend void swap(PFTitleDataManagementGetTitleNewsResultWrapper& lhs, PFTitleDataManagementGetTitleNewsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_news, rhs.m_news);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetNews(ModelVector<PFTitleDataManagementTitleNewsItemWrapper<Alloc>, Alloc> value)
    {
        m_news = std::move(value);
        this->m_model.news =  m_news.empty() ? nullptr : m_news.data();
        this->m_model.newsCount =  static_cast<uint32_t>(m_news.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.news = m_news.empty() ? nullptr : m_news.data();
    }

    ModelVector<PFTitleDataManagementTitleNewsItemWrapper<Alloc>, Alloc> m_news;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFTitleDataManagementGetStoreItemsServerRequestWrapper : public ModelWrapper<PFTitleDataManagementGetStoreItemsServerRequest, Alloc>
{
public:
    using ModelType = typename PFTitleDataManagementGetStoreItemsServerRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFTitleDataManagementGetStoreItemsServerRequestWrapper() = default;

    PFTitleDataManagementGetStoreItemsServerRequestWrapper(const PFTitleDataManagementGetStoreItemsServerRequest& model) :
        ModelWrapper<PFTitleDataManagementGetStoreItemsServerRequest, Alloc>{ model },
        m_catalogVersion{ SafeString(model.catalogVersion) },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_storeId{ SafeString(model.storeId) }
    {
        SetModelPointers();
    }

    PFTitleDataManagementGetStoreItemsServerRequestWrapper(const PFTitleDataManagementGetStoreItemsServerRequestWrapper& src) :
        PFTitleDataManagementGetStoreItemsServerRequestWrapper{ src.Model() }
    {
    }

    PFTitleDataManagementGetStoreItemsServerRequestWrapper(PFTitleDataManagementGetStoreItemsServerRequestWrapper&& src) :
        PFTitleDataManagementGetStoreItemsServerRequestWrapper{}
    {
        swap(*this, src);
    }

    PFTitleDataManagementGetStoreItemsServerRequestWrapper& operator=(PFTitleDataManagementGetStoreItemsServerRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFTitleDataManagementGetStoreItemsServerRequestWrapper() = default;

    friend void swap(PFTitleDataManagementGetStoreItemsServerRequestWrapper& lhs, PFTitleDataManagementGetStoreItemsServerRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogVersion, rhs.m_catalogVersion);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
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

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
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
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.storeId = m_storeId.empty() ? nullptr : m_storeId.data();
    }

    String m_catalogVersion;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
    String m_storeId;
};

} // namespace Wrappers
} // namespace PlayFab
