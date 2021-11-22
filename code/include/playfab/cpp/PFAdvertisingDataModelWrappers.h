// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFAdvertisingDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFAdvertisingAttributeInstallRequestWrapper : public ModelWrapper<PFAdvertisingAttributeInstallRequest, Alloc>
{
public:
    using ModelType = typename PFAdvertisingAttributeInstallRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAdvertisingAttributeInstallRequestWrapper() = default;

    PFAdvertisingAttributeInstallRequestWrapper(const PFAdvertisingAttributeInstallRequest& model) :
        ModelWrapper<PFAdvertisingAttributeInstallRequest, Alloc>{ model },
        m_adid{ SafeString(model.adid) },
        m_idfa{ SafeString(model.idfa) }
    {
        SetModelPointers();
    }

    PFAdvertisingAttributeInstallRequestWrapper(const PFAdvertisingAttributeInstallRequestWrapper& src) :
        PFAdvertisingAttributeInstallRequestWrapper{ src.Model() }
    {
    }

    PFAdvertisingAttributeInstallRequestWrapper(PFAdvertisingAttributeInstallRequestWrapper&& src) :
        PFAdvertisingAttributeInstallRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAdvertisingAttributeInstallRequestWrapper& operator=(PFAdvertisingAttributeInstallRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAdvertisingAttributeInstallRequestWrapper() = default;

    friend void swap(PFAdvertisingAttributeInstallRequestWrapper& lhs, PFAdvertisingAttributeInstallRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_adid, rhs.m_adid);
        swap(lhs.m_idfa, rhs.m_idfa);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAdid(String value)
    {
        m_adid = std::move(value);
        this->m_model.adid =  m_adid.empty() ? nullptr : m_adid.data();
    }

    void SetIdfa(String value)
    {
        m_idfa = std::move(value);
        this->m_model.idfa =  m_idfa.empty() ? nullptr : m_idfa.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.adid = m_adid.empty() ? nullptr : m_adid.data();
        this->m_model.idfa = m_idfa.empty() ? nullptr : m_idfa.data();
    }

    String m_adid;
    String m_idfa;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAdvertisingGetAdPlacementsRequestWrapper : public ModelWrapper<PFAdvertisingGetAdPlacementsRequest, Alloc>
{
public:
    using ModelType = typename PFAdvertisingGetAdPlacementsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAdvertisingGetAdPlacementsRequestWrapper() = default;

    PFAdvertisingGetAdPlacementsRequestWrapper(const PFAdvertisingGetAdPlacementsRequest& model) :
        ModelWrapper<PFAdvertisingGetAdPlacementsRequest, Alloc>{ model },
        m_appId{ SafeString(model.appId) },
        m_identifier{ model.identifier ? StdExtra::optional<PFNameIdentifierWrapper<Alloc>>{ *model.identifier } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAdvertisingGetAdPlacementsRequestWrapper(const PFAdvertisingGetAdPlacementsRequestWrapper& src) :
        PFAdvertisingGetAdPlacementsRequestWrapper{ src.Model() }
    {
    }

    PFAdvertisingGetAdPlacementsRequestWrapper(PFAdvertisingGetAdPlacementsRequestWrapper&& src) :
        PFAdvertisingGetAdPlacementsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAdvertisingGetAdPlacementsRequestWrapper& operator=(PFAdvertisingGetAdPlacementsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAdvertisingGetAdPlacementsRequestWrapper() = default;

    friend void swap(PFAdvertisingGetAdPlacementsRequestWrapper& lhs, PFAdvertisingGetAdPlacementsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_appId, rhs.m_appId);
        swap(lhs.m_identifier, rhs.m_identifier);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAppId(String value)
    {
        m_appId = std::move(value);
        this->m_model.appId =  m_appId.empty() ? nullptr : m_appId.data();
    }

    void SetIdentifier(StdExtra::optional<PFNameIdentifierWrapper<Alloc>> value)
    {
        m_identifier = std::move(value);
        this->m_model.identifier = m_identifier ? &m_identifier->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.appId = m_appId.empty() ? nullptr : m_appId.data();
        this->m_model.identifier = m_identifier ?  &m_identifier->Model() : nullptr;
    }

    String m_appId;
    StdExtra::optional<PFNameIdentifierWrapper<Alloc>> m_identifier;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAdvertisingAdPlacementDetailsWrapper : public ModelWrapper<PFAdvertisingAdPlacementDetails, Alloc>
{
public:
    using ModelType = typename PFAdvertisingAdPlacementDetails;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAdvertisingAdPlacementDetailsWrapper() = default;

    PFAdvertisingAdPlacementDetailsWrapper(const PFAdvertisingAdPlacementDetails& model) :
        ModelWrapper<PFAdvertisingAdPlacementDetails, Alloc>{ model },
        m_placementId{ SafeString(model.placementId) },
        m_placementName{ SafeString(model.placementName) },
        m_placementViewsRemaining{ model.placementViewsRemaining ? StdExtra::optional<int32_t>{ *model.placementViewsRemaining } : StdExtra::nullopt },
        m_placementViewsResetMinutes{ model.placementViewsResetMinutes ? StdExtra::optional<double>{ *model.placementViewsResetMinutes } : StdExtra::nullopt },
        m_rewardAssetUrl{ SafeString(model.rewardAssetUrl) },
        m_rewardDescription{ SafeString(model.rewardDescription) },
        m_rewardId{ SafeString(model.rewardId) },
        m_rewardName{ SafeString(model.rewardName) }
    {
        SetModelPointers();
    }

    PFAdvertisingAdPlacementDetailsWrapper(const PFAdvertisingAdPlacementDetailsWrapper& src) :
        PFAdvertisingAdPlacementDetailsWrapper{ src.Model() }
    {
    }

    PFAdvertisingAdPlacementDetailsWrapper(PFAdvertisingAdPlacementDetailsWrapper&& src) :
        PFAdvertisingAdPlacementDetailsWrapper{}
    {
        swap(*this, src);
    }

    PFAdvertisingAdPlacementDetailsWrapper& operator=(PFAdvertisingAdPlacementDetailsWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAdvertisingAdPlacementDetailsWrapper() = default;

    friend void swap(PFAdvertisingAdPlacementDetailsWrapper& lhs, PFAdvertisingAdPlacementDetailsWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_placementId, rhs.m_placementId);
        swap(lhs.m_placementName, rhs.m_placementName);
        swap(lhs.m_placementViewsRemaining, rhs.m_placementViewsRemaining);
        swap(lhs.m_placementViewsResetMinutes, rhs.m_placementViewsResetMinutes);
        swap(lhs.m_rewardAssetUrl, rhs.m_rewardAssetUrl);
        swap(lhs.m_rewardDescription, rhs.m_rewardDescription);
        swap(lhs.m_rewardId, rhs.m_rewardId);
        swap(lhs.m_rewardName, rhs.m_rewardName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlacementId(String value)
    {
        m_placementId = std::move(value);
        this->m_model.placementId =  m_placementId.empty() ? nullptr : m_placementId.data();
    }

    void SetPlacementName(String value)
    {
        m_placementName = std::move(value);
        this->m_model.placementName =  m_placementName.empty() ? nullptr : m_placementName.data();
    }

    void SetPlacementViewsRemaining(StdExtra::optional<int32_t> value)
    {
        m_placementViewsRemaining = std::move(value);
        this->m_model.placementViewsRemaining = m_placementViewsRemaining ? m_placementViewsRemaining.operator->() : nullptr;
    }

    void SetPlacementViewsResetMinutes(StdExtra::optional<double> value)
    {
        m_placementViewsResetMinutes = std::move(value);
        this->m_model.placementViewsResetMinutes = m_placementViewsResetMinutes ? m_placementViewsResetMinutes.operator->() : nullptr;
    }

    void SetRewardAssetUrl(String value)
    {
        m_rewardAssetUrl = std::move(value);
        this->m_model.rewardAssetUrl =  m_rewardAssetUrl.empty() ? nullptr : m_rewardAssetUrl.data();
    }

    void SetRewardDescription(String value)
    {
        m_rewardDescription = std::move(value);
        this->m_model.rewardDescription =  m_rewardDescription.empty() ? nullptr : m_rewardDescription.data();
    }

    void SetRewardId(String value)
    {
        m_rewardId = std::move(value);
        this->m_model.rewardId =  m_rewardId.empty() ? nullptr : m_rewardId.data();
    }

    void SetRewardName(String value)
    {
        m_rewardName = std::move(value);
        this->m_model.rewardName =  m_rewardName.empty() ? nullptr : m_rewardName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.placementId = m_placementId.empty() ? nullptr : m_placementId.data();
        this->m_model.placementName = m_placementName.empty() ? nullptr : m_placementName.data();
        this->m_model.placementViewsRemaining = m_placementViewsRemaining ? m_placementViewsRemaining.operator->() : nullptr;
        this->m_model.placementViewsResetMinutes = m_placementViewsResetMinutes ? m_placementViewsResetMinutes.operator->() : nullptr;
        this->m_model.rewardAssetUrl = m_rewardAssetUrl.empty() ? nullptr : m_rewardAssetUrl.data();
        this->m_model.rewardDescription = m_rewardDescription.empty() ? nullptr : m_rewardDescription.data();
        this->m_model.rewardId = m_rewardId.empty() ? nullptr : m_rewardId.data();
        this->m_model.rewardName = m_rewardName.empty() ? nullptr : m_rewardName.data();
    }

    String m_placementId;
    String m_placementName;
    StdExtra::optional<int32_t> m_placementViewsRemaining;
    StdExtra::optional<double> m_placementViewsResetMinutes;
    String m_rewardAssetUrl;
    String m_rewardDescription;
    String m_rewardId;
    String m_rewardName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAdvertisingGetAdPlacementsResultWrapper : public ModelWrapper<PFAdvertisingGetAdPlacementsResult, Alloc>
{
public:
    using ModelType = typename PFAdvertisingGetAdPlacementsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAdvertisingGetAdPlacementsResultWrapper() = default;

    PFAdvertisingGetAdPlacementsResultWrapper(const PFAdvertisingGetAdPlacementsResult& model) :
        ModelWrapper<PFAdvertisingGetAdPlacementsResult, Alloc>{ model },
        m_adPlacements{ model.adPlacements, model.adPlacements + model.adPlacementsCount }
    {
        SetModelPointers();
    }

    PFAdvertisingGetAdPlacementsResultWrapper(const PFAdvertisingGetAdPlacementsResultWrapper& src) :
        PFAdvertisingGetAdPlacementsResultWrapper{ src.Model() }
    {
    }

    PFAdvertisingGetAdPlacementsResultWrapper(PFAdvertisingGetAdPlacementsResultWrapper&& src) :
        PFAdvertisingGetAdPlacementsResultWrapper{}
    {
        swap(*this, src);
    }

    PFAdvertisingGetAdPlacementsResultWrapper& operator=(PFAdvertisingGetAdPlacementsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAdvertisingGetAdPlacementsResultWrapper() = default;

    friend void swap(PFAdvertisingGetAdPlacementsResultWrapper& lhs, PFAdvertisingGetAdPlacementsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_adPlacements, rhs.m_adPlacements);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAdPlacements(ModelVector<PFAdvertisingAdPlacementDetailsWrapper<Alloc>, Alloc> value)
    {
        m_adPlacements = std::move(value);
        this->m_model.adPlacements =  m_adPlacements.empty() ? nullptr : m_adPlacements.data();
        this->m_model.adPlacementsCount =  static_cast<uint32_t>(m_adPlacements.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.adPlacements = m_adPlacements.empty() ? nullptr : m_adPlacements.data();
    }

    ModelVector<PFAdvertisingAdPlacementDetailsWrapper<Alloc>, Alloc> m_adPlacements;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAdvertisingReportAdActivityRequestWrapper : public ModelWrapper<PFAdvertisingReportAdActivityRequest, Alloc>
{
public:
    using ModelType = typename PFAdvertisingReportAdActivityRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAdvertisingReportAdActivityRequestWrapper() = default;

    PFAdvertisingReportAdActivityRequestWrapper(const PFAdvertisingReportAdActivityRequest& model) :
        ModelWrapper<PFAdvertisingReportAdActivityRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_placementId{ SafeString(model.placementId) },
        m_rewardId{ SafeString(model.rewardId) }
    {
        SetModelPointers();
    }

    PFAdvertisingReportAdActivityRequestWrapper(const PFAdvertisingReportAdActivityRequestWrapper& src) :
        PFAdvertisingReportAdActivityRequestWrapper{ src.Model() }
    {
    }

    PFAdvertisingReportAdActivityRequestWrapper(PFAdvertisingReportAdActivityRequestWrapper&& src) :
        PFAdvertisingReportAdActivityRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAdvertisingReportAdActivityRequestWrapper& operator=(PFAdvertisingReportAdActivityRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAdvertisingReportAdActivityRequestWrapper() = default;

    friend void swap(PFAdvertisingReportAdActivityRequestWrapper& lhs, PFAdvertisingReportAdActivityRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_placementId, rhs.m_placementId);
        swap(lhs.m_rewardId, rhs.m_rewardId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetActivity(PFAdvertisingAdActivity value)
    {
        this->m_model.activity = value;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPlacementId(String value)
    {
        m_placementId = std::move(value);
        this->m_model.placementId =  m_placementId.empty() ? nullptr : m_placementId.data();
    }

    void SetRewardId(String value)
    {
        m_rewardId = std::move(value);
        this->m_model.rewardId =  m_rewardId.empty() ? nullptr : m_rewardId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.placementId = m_placementId.empty() ? nullptr : m_placementId.data();
        this->m_model.rewardId = m_rewardId.empty() ? nullptr : m_rewardId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_placementId;
    String m_rewardId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAdvertisingRewardAdActivityRequestWrapper : public ModelWrapper<PFAdvertisingRewardAdActivityRequest, Alloc>
{
public:
    using ModelType = typename PFAdvertisingRewardAdActivityRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAdvertisingRewardAdActivityRequestWrapper() = default;

    PFAdvertisingRewardAdActivityRequestWrapper(const PFAdvertisingRewardAdActivityRequest& model) :
        ModelWrapper<PFAdvertisingRewardAdActivityRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_placementId{ SafeString(model.placementId) },
        m_rewardId{ SafeString(model.rewardId) }
    {
        SetModelPointers();
    }

    PFAdvertisingRewardAdActivityRequestWrapper(const PFAdvertisingRewardAdActivityRequestWrapper& src) :
        PFAdvertisingRewardAdActivityRequestWrapper{ src.Model() }
    {
    }

    PFAdvertisingRewardAdActivityRequestWrapper(PFAdvertisingRewardAdActivityRequestWrapper&& src) :
        PFAdvertisingRewardAdActivityRequestWrapper{}
    {
        swap(*this, src);
    }

    PFAdvertisingRewardAdActivityRequestWrapper& operator=(PFAdvertisingRewardAdActivityRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAdvertisingRewardAdActivityRequestWrapper() = default;

    friend void swap(PFAdvertisingRewardAdActivityRequestWrapper& lhs, PFAdvertisingRewardAdActivityRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_placementId, rhs.m_placementId);
        swap(lhs.m_rewardId, rhs.m_rewardId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetPlacementId(String value)
    {
        m_placementId = std::move(value);
        this->m_model.placementId =  m_placementId.empty() ? nullptr : m_placementId.data();
    }

    void SetRewardId(String value)
    {
        m_rewardId = std::move(value);
        this->m_model.rewardId =  m_rewardId.empty() ? nullptr : m_rewardId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.placementId = m_placementId.empty() ? nullptr : m_placementId.data();
        this->m_model.rewardId = m_rewardId.empty() ? nullptr : m_rewardId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_placementId;
    String m_rewardId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAdvertisingAdRewardItemGrantedWrapper : public ModelWrapper<PFAdvertisingAdRewardItemGranted, Alloc>
{
public:
    using ModelType = typename PFAdvertisingAdRewardItemGranted;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAdvertisingAdRewardItemGrantedWrapper() = default;

    PFAdvertisingAdRewardItemGrantedWrapper(const PFAdvertisingAdRewardItemGranted& model) :
        ModelWrapper<PFAdvertisingAdRewardItemGranted, Alloc>{ model },
        m_catalogId{ SafeString(model.catalogId) },
        m_displayName{ SafeString(model.displayName) },
        m_instanceId{ SafeString(model.instanceId) },
        m_itemId{ SafeString(model.itemId) }
    {
        SetModelPointers();
    }

    PFAdvertisingAdRewardItemGrantedWrapper(const PFAdvertisingAdRewardItemGrantedWrapper& src) :
        PFAdvertisingAdRewardItemGrantedWrapper{ src.Model() }
    {
    }

    PFAdvertisingAdRewardItemGrantedWrapper(PFAdvertisingAdRewardItemGrantedWrapper&& src) :
        PFAdvertisingAdRewardItemGrantedWrapper{}
    {
        swap(*this, src);
    }

    PFAdvertisingAdRewardItemGrantedWrapper& operator=(PFAdvertisingAdRewardItemGrantedWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAdvertisingAdRewardItemGrantedWrapper() = default;

    friend void swap(PFAdvertisingAdRewardItemGrantedWrapper& lhs, PFAdvertisingAdRewardItemGrantedWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_catalogId, rhs.m_catalogId);
        swap(lhs.m_displayName, rhs.m_displayName);
        swap(lhs.m_instanceId, rhs.m_instanceId);
        swap(lhs.m_itemId, rhs.m_itemId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCatalogId(String value)
    {
        m_catalogId = std::move(value);
        this->m_model.catalogId =  m_catalogId.empty() ? nullptr : m_catalogId.data();
    }

    void SetDisplayName(String value)
    {
        m_displayName = std::move(value);
        this->m_model.displayName =  m_displayName.empty() ? nullptr : m_displayName.data();
    }

    void SetInstanceId(String value)
    {
        m_instanceId = std::move(value);
        this->m_model.instanceId =  m_instanceId.empty() ? nullptr : m_instanceId.data();
    }

    void SetItemId(String value)
    {
        m_itemId = std::move(value);
        this->m_model.itemId =  m_itemId.empty() ? nullptr : m_itemId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.catalogId = m_catalogId.empty() ? nullptr : m_catalogId.data();
        this->m_model.displayName = m_displayName.empty() ? nullptr : m_displayName.data();
        this->m_model.instanceId = m_instanceId.empty() ? nullptr : m_instanceId.data();
        this->m_model.itemId = m_itemId.empty() ? nullptr : m_itemId.data();
    }

    String m_catalogId;
    String m_displayName;
    String m_instanceId;
    String m_itemId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAdvertisingAdRewardResultsWrapper : public ModelWrapper<PFAdvertisingAdRewardResults, Alloc>
{
public:
    using ModelType = typename PFAdvertisingAdRewardResults;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAdvertisingAdRewardResultsWrapper() = default;

    PFAdvertisingAdRewardResultsWrapper(const PFAdvertisingAdRewardResults& model) :
        ModelWrapper<PFAdvertisingAdRewardResults, Alloc>{ model },
        m_grantedItems{ model.grantedItems, model.grantedItems + model.grantedItemsCount },
        m_grantedVirtualCurrencies{ model.grantedVirtualCurrencies, model.grantedVirtualCurrencies + model.grantedVirtualCurrenciesCount },
        m_incrementedStatistics{ model.incrementedStatistics, model.incrementedStatistics + model.incrementedStatisticsCount }
    {
        SetModelPointers();
    }

    PFAdvertisingAdRewardResultsWrapper(const PFAdvertisingAdRewardResultsWrapper& src) :
        PFAdvertisingAdRewardResultsWrapper{ src.Model() }
    {
    }

    PFAdvertisingAdRewardResultsWrapper(PFAdvertisingAdRewardResultsWrapper&& src) :
        PFAdvertisingAdRewardResultsWrapper{}
    {
        swap(*this, src);
    }

    PFAdvertisingAdRewardResultsWrapper& operator=(PFAdvertisingAdRewardResultsWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAdvertisingAdRewardResultsWrapper() = default;

    friend void swap(PFAdvertisingAdRewardResultsWrapper& lhs, PFAdvertisingAdRewardResultsWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_grantedItems, rhs.m_grantedItems);
        swap(lhs.m_grantedVirtualCurrencies, rhs.m_grantedVirtualCurrencies);
        swap(lhs.m_incrementedStatistics, rhs.m_incrementedStatistics);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetGrantedItems(ModelVector<PFAdvertisingAdRewardItemGrantedWrapper<Alloc>, Alloc> value)
    {
        m_grantedItems = std::move(value);
        this->m_model.grantedItems =  m_grantedItems.empty() ? nullptr : m_grantedItems.data();
        this->m_model.grantedItemsCount =  static_cast<uint32_t>(m_grantedItems.size());
    }

    void SetGrantedVirtualCurrencies(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_grantedVirtualCurrencies = std::move(value);
        this->m_model.grantedVirtualCurrencies =  m_grantedVirtualCurrencies.empty() ? nullptr : m_grantedVirtualCurrencies.data();
        this->m_model.grantedVirtualCurrenciesCount =  static_cast<uint32_t>(m_grantedVirtualCurrencies.size());
    }

    void SetIncrementedStatistics(DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> value)
    {
        m_incrementedStatistics = std::move(value);
        this->m_model.incrementedStatistics =  m_incrementedStatistics.empty() ? nullptr : m_incrementedStatistics.data();
        this->m_model.incrementedStatisticsCount =  static_cast<uint32_t>(m_incrementedStatistics.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.grantedItems = m_grantedItems.empty() ? nullptr : m_grantedItems.data();
        this->m_model.grantedVirtualCurrencies = m_grantedVirtualCurrencies.empty() ? nullptr : m_grantedVirtualCurrencies.data();
        this->m_model.incrementedStatistics = m_incrementedStatistics.empty() ? nullptr : m_incrementedStatistics.data();
    }

    ModelVector<PFAdvertisingAdRewardItemGrantedWrapper<Alloc>, Alloc> m_grantedItems;
    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_grantedVirtualCurrencies;
    DictionaryEntryVector<PFInt32DictionaryEntry, Alloc> m_incrementedStatistics;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFAdvertisingRewardAdActivityResultWrapper : public ModelWrapper<PFAdvertisingRewardAdActivityResult, Alloc>
{
public:
    using ModelType = typename PFAdvertisingRewardAdActivityResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFAdvertisingRewardAdActivityResultWrapper() = default;

    PFAdvertisingRewardAdActivityResultWrapper(const PFAdvertisingRewardAdActivityResult& model) :
        ModelWrapper<PFAdvertisingRewardAdActivityResult, Alloc>{ model },
        m_adActivityEventId{ SafeString(model.adActivityEventId) },
        m_debugResults{ model.debugResults, model.debugResults + model.debugResultsCount },
        m_placementId{ SafeString(model.placementId) },
        m_placementName{ SafeString(model.placementName) },
        m_placementViewsRemaining{ model.placementViewsRemaining ? StdExtra::optional<int32_t>{ *model.placementViewsRemaining } : StdExtra::nullopt },
        m_placementViewsResetMinutes{ model.placementViewsResetMinutes ? StdExtra::optional<double>{ *model.placementViewsResetMinutes } : StdExtra::nullopt },
        m_rewardResults{ model.rewardResults ? StdExtra::optional<PFAdvertisingAdRewardResultsWrapper<Alloc>>{ *model.rewardResults } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFAdvertisingRewardAdActivityResultWrapper(const PFAdvertisingRewardAdActivityResultWrapper& src) :
        PFAdvertisingRewardAdActivityResultWrapper{ src.Model() }
    {
    }

    PFAdvertisingRewardAdActivityResultWrapper(PFAdvertisingRewardAdActivityResultWrapper&& src) :
        PFAdvertisingRewardAdActivityResultWrapper{}
    {
        swap(*this, src);
    }

    PFAdvertisingRewardAdActivityResultWrapper& operator=(PFAdvertisingRewardAdActivityResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFAdvertisingRewardAdActivityResultWrapper() = default;

    friend void swap(PFAdvertisingRewardAdActivityResultWrapper& lhs, PFAdvertisingRewardAdActivityResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_adActivityEventId, rhs.m_adActivityEventId);
        swap(lhs.m_debugResults, rhs.m_debugResults);
        swap(lhs.m_placementId, rhs.m_placementId);
        swap(lhs.m_placementName, rhs.m_placementName);
        swap(lhs.m_placementViewsRemaining, rhs.m_placementViewsRemaining);
        swap(lhs.m_placementViewsResetMinutes, rhs.m_placementViewsResetMinutes);
        swap(lhs.m_rewardResults, rhs.m_rewardResults);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAdActivityEventId(String value)
    {
        m_adActivityEventId = std::move(value);
        this->m_model.adActivityEventId =  m_adActivityEventId.empty() ? nullptr : m_adActivityEventId.data();
    }

    void SetDebugResults(CStringVector<Alloc> value)
    {
        m_debugResults = std::move(value);
        this->m_model.debugResults =  m_debugResults.empty() ? nullptr : m_debugResults.data();
        this->m_model.debugResultsCount =  static_cast<uint32_t>(m_debugResults.size());
    }

    void SetPlacementId(String value)
    {
        m_placementId = std::move(value);
        this->m_model.placementId =  m_placementId.empty() ? nullptr : m_placementId.data();
    }

    void SetPlacementName(String value)
    {
        m_placementName = std::move(value);
        this->m_model.placementName =  m_placementName.empty() ? nullptr : m_placementName.data();
    }

    void SetPlacementViewsRemaining(StdExtra::optional<int32_t> value)
    {
        m_placementViewsRemaining = std::move(value);
        this->m_model.placementViewsRemaining = m_placementViewsRemaining ? m_placementViewsRemaining.operator->() : nullptr;
    }

    void SetPlacementViewsResetMinutes(StdExtra::optional<double> value)
    {
        m_placementViewsResetMinutes = std::move(value);
        this->m_model.placementViewsResetMinutes = m_placementViewsResetMinutes ? m_placementViewsResetMinutes.operator->() : nullptr;
    }

    void SetRewardResults(StdExtra::optional<PFAdvertisingAdRewardResultsWrapper<Alloc>> value)
    {
        m_rewardResults = std::move(value);
        this->m_model.rewardResults = m_rewardResults ? &m_rewardResults->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.adActivityEventId = m_adActivityEventId.empty() ? nullptr : m_adActivityEventId.data();
        this->m_model.debugResults = m_debugResults.empty() ? nullptr : m_debugResults.data();
        this->m_model.placementId = m_placementId.empty() ? nullptr : m_placementId.data();
        this->m_model.placementName = m_placementName.empty() ? nullptr : m_placementName.data();
        this->m_model.placementViewsRemaining = m_placementViewsRemaining ? m_placementViewsRemaining.operator->() : nullptr;
        this->m_model.placementViewsResetMinutes = m_placementViewsResetMinutes ? m_placementViewsResetMinutes.operator->() : nullptr;
        this->m_model.rewardResults = m_rewardResults ?  &m_rewardResults->Model() : nullptr;
    }

    String m_adActivityEventId;
    CStringVector<Alloc> m_debugResults;
    String m_placementId;
    String m_placementName;
    StdExtra::optional<int32_t> m_placementViewsRemaining;
    StdExtra::optional<double> m_placementViewsResetMinutes;
    StdExtra::optional<PFAdvertisingAdRewardResultsWrapper<Alloc>> m_rewardResults;
};

} // namespace Wrappers
} // namespace PlayFab
