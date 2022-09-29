// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFLeaderboardDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper : public ModelWrapper<PFLeaderboardCreatePlayerStatisticDefinitionRequest, Alloc>
{
public:
    using ModelType = typename PFLeaderboardCreatePlayerStatisticDefinitionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper() = default;

    PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper(const PFLeaderboardCreatePlayerStatisticDefinitionRequest& model) :
        ModelWrapper<PFLeaderboardCreatePlayerStatisticDefinitionRequest, Alloc>{ model },
        m_aggregationMethod{ model.aggregationMethod ? StdExtra::optional<PFLeaderboardStatisticAggregationMethod>{ *model.aggregationMethod } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_statisticName{ SafeString(model.statisticName) },
        m_versionChangeInterval{ model.versionChangeInterval ? StdExtra::optional<PFLeaderboardStatisticResetIntervalOption>{ *model.versionChangeInterval } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper(const PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper& src) :
        PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper{ src.Model() }
    {
    }

    PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper(PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper&& src) :
        PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper& operator=(PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper() = default;

    friend void swap(PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper& lhs, PFLeaderboardCreatePlayerStatisticDefinitionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_aggregationMethod, rhs.m_aggregationMethod);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        swap(lhs.m_versionChangeInterval, rhs.m_versionChangeInterval);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAggregationMethod(StdExtra::optional<PFLeaderboardStatisticAggregationMethod> value)
    {
        m_aggregationMethod = std::move(value);
        this->m_model.aggregationMethod = m_aggregationMethod ? m_aggregationMethod.operator->() : nullptr;
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    void SetVersionChangeInterval(StdExtra::optional<PFLeaderboardStatisticResetIntervalOption> value)
    {
        m_versionChangeInterval = std::move(value);
        this->m_model.versionChangeInterval = m_versionChangeInterval ? m_versionChangeInterval.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.aggregationMethod = m_aggregationMethod ? m_aggregationMethod.operator->() : nullptr;
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
        this->m_model.versionChangeInterval = m_versionChangeInterval ? m_versionChangeInterval.operator->() : nullptr;
    }

    StdExtra::optional<PFLeaderboardStatisticAggregationMethod> m_aggregationMethod;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_statisticName;
    StdExtra::optional<PFLeaderboardStatisticResetIntervalOption> m_versionChangeInterval;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardPlayerStatisticDefinitionWrapper : public ModelWrapper<PFLeaderboardPlayerStatisticDefinition, Alloc>
{
public:
    using ModelType = typename PFLeaderboardPlayerStatisticDefinition;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardPlayerStatisticDefinitionWrapper() = default;

    PFLeaderboardPlayerStatisticDefinitionWrapper(const PFLeaderboardPlayerStatisticDefinition& model) :
        ModelWrapper<PFLeaderboardPlayerStatisticDefinition, Alloc>{ model },
        m_aggregationMethod{ model.aggregationMethod ? StdExtra::optional<PFLeaderboardStatisticAggregationMethod>{ *model.aggregationMethod } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) },
        m_versionChangeInterval{ model.versionChangeInterval ? StdExtra::optional<PFLeaderboardStatisticResetIntervalOption>{ *model.versionChangeInterval } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLeaderboardPlayerStatisticDefinitionWrapper(const PFLeaderboardPlayerStatisticDefinitionWrapper& src) :
        PFLeaderboardPlayerStatisticDefinitionWrapper{ src.Model() }
    {
    }

    PFLeaderboardPlayerStatisticDefinitionWrapper(PFLeaderboardPlayerStatisticDefinitionWrapper&& src) :
        PFLeaderboardPlayerStatisticDefinitionWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardPlayerStatisticDefinitionWrapper& operator=(PFLeaderboardPlayerStatisticDefinitionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardPlayerStatisticDefinitionWrapper() = default;

    friend void swap(PFLeaderboardPlayerStatisticDefinitionWrapper& lhs, PFLeaderboardPlayerStatisticDefinitionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_aggregationMethod, rhs.m_aggregationMethod);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        swap(lhs.m_versionChangeInterval, rhs.m_versionChangeInterval);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAggregationMethod(StdExtra::optional<PFLeaderboardStatisticAggregationMethod> value)
    {
        m_aggregationMethod = std::move(value);
        this->m_model.aggregationMethod = m_aggregationMethod ? m_aggregationMethod.operator->() : nullptr;
    }

    void SetCurrentVersion(uint32_t value)
    {
        this->m_model.currentVersion = value;
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    void SetVersionChangeInterval(StdExtra::optional<PFLeaderboardStatisticResetIntervalOption> value)
    {
        m_versionChangeInterval = std::move(value);
        this->m_model.versionChangeInterval = m_versionChangeInterval ? m_versionChangeInterval.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.aggregationMethod = m_aggregationMethod ? m_aggregationMethod.operator->() : nullptr;
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
        this->m_model.versionChangeInterval = m_versionChangeInterval ? m_versionChangeInterval.operator->() : nullptr;
    }

    StdExtra::optional<PFLeaderboardStatisticAggregationMethod> m_aggregationMethod;
    String m_statisticName;
    StdExtra::optional<PFLeaderboardStatisticResetIntervalOption> m_versionChangeInterval;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardCreatePlayerStatisticDefinitionResultWrapper : public ModelWrapper<PFLeaderboardCreatePlayerStatisticDefinitionResult, Alloc>
{
public:
    using ModelType = typename PFLeaderboardCreatePlayerStatisticDefinitionResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardCreatePlayerStatisticDefinitionResultWrapper() = default;

    PFLeaderboardCreatePlayerStatisticDefinitionResultWrapper(const PFLeaderboardCreatePlayerStatisticDefinitionResult& model) :
        ModelWrapper<PFLeaderboardCreatePlayerStatisticDefinitionResult, Alloc>{ model },
        m_statistic{ model.statistic ? StdExtra::optional<PFLeaderboardPlayerStatisticDefinitionWrapper<Alloc>>{ *model.statistic } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLeaderboardCreatePlayerStatisticDefinitionResultWrapper(const PFLeaderboardCreatePlayerStatisticDefinitionResultWrapper& src) :
        PFLeaderboardCreatePlayerStatisticDefinitionResultWrapper{ src.Model() }
    {
    }

    PFLeaderboardCreatePlayerStatisticDefinitionResultWrapper(PFLeaderboardCreatePlayerStatisticDefinitionResultWrapper&& src) :
        PFLeaderboardCreatePlayerStatisticDefinitionResultWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardCreatePlayerStatisticDefinitionResultWrapper& operator=(PFLeaderboardCreatePlayerStatisticDefinitionResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardCreatePlayerStatisticDefinitionResultWrapper() = default;

    friend void swap(PFLeaderboardCreatePlayerStatisticDefinitionResultWrapper& lhs, PFLeaderboardCreatePlayerStatisticDefinitionResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_statistic, rhs.m_statistic);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStatistic(StdExtra::optional<PFLeaderboardPlayerStatisticDefinitionWrapper<Alloc>> value)
    {
        m_statistic = std::move(value);
        this->m_model.statistic = m_statistic ? &m_statistic->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.statistic = m_statistic ?  &m_statistic->Model() : nullptr;
    }

    StdExtra::optional<PFLeaderboardPlayerStatisticDefinitionWrapper<Alloc>> m_statistic;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardGetPlayerStatisticDefinitionsResultWrapper : public ModelWrapper<PFLeaderboardGetPlayerStatisticDefinitionsResult, Alloc>
{
public:
    using ModelType = typename PFLeaderboardGetPlayerStatisticDefinitionsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardGetPlayerStatisticDefinitionsResultWrapper() = default;

    PFLeaderboardGetPlayerStatisticDefinitionsResultWrapper(const PFLeaderboardGetPlayerStatisticDefinitionsResult& model) :
        ModelWrapper<PFLeaderboardGetPlayerStatisticDefinitionsResult, Alloc>{ model },
        m_statistics{ model.statistics, model.statistics + model.statisticsCount }
    {
        SetModelPointers();
    }

    PFLeaderboardGetPlayerStatisticDefinitionsResultWrapper(const PFLeaderboardGetPlayerStatisticDefinitionsResultWrapper& src) :
        PFLeaderboardGetPlayerStatisticDefinitionsResultWrapper{ src.Model() }
    {
    }

    PFLeaderboardGetPlayerStatisticDefinitionsResultWrapper(PFLeaderboardGetPlayerStatisticDefinitionsResultWrapper&& src) :
        PFLeaderboardGetPlayerStatisticDefinitionsResultWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardGetPlayerStatisticDefinitionsResultWrapper& operator=(PFLeaderboardGetPlayerStatisticDefinitionsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardGetPlayerStatisticDefinitionsResultWrapper() = default;

    friend void swap(PFLeaderboardGetPlayerStatisticDefinitionsResultWrapper& lhs, PFLeaderboardGetPlayerStatisticDefinitionsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_statistics, rhs.m_statistics);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStatistics(ModelVector<PFLeaderboardPlayerStatisticDefinitionWrapper<Alloc>, Alloc> value)
    {
        m_statistics = std::move(value);
        this->m_model.statistics =  m_statistics.empty() ? nullptr : m_statistics.data();
        this->m_model.statisticsCount =  static_cast<uint32_t>(m_statistics.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.statistics = m_statistics.empty() ? nullptr : m_statistics.data();
    }

    ModelVector<PFLeaderboardPlayerStatisticDefinitionWrapper<Alloc>, Alloc> m_statistics;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardGetPlayerStatisticVersionsRequestWrapper : public ModelWrapper<PFLeaderboardGetPlayerStatisticVersionsRequest, Alloc>
{
public:
    using ModelType = typename PFLeaderboardGetPlayerStatisticVersionsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardGetPlayerStatisticVersionsRequestWrapper() = default;

    PFLeaderboardGetPlayerStatisticVersionsRequestWrapper(const PFLeaderboardGetPlayerStatisticVersionsRequest& model) :
        ModelWrapper<PFLeaderboardGetPlayerStatisticVersionsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_statisticName{ SafeString(model.statisticName) }
    {
        SetModelPointers();
    }

    PFLeaderboardGetPlayerStatisticVersionsRequestWrapper(const PFLeaderboardGetPlayerStatisticVersionsRequestWrapper& src) :
        PFLeaderboardGetPlayerStatisticVersionsRequestWrapper{ src.Model() }
    {
    }

    PFLeaderboardGetPlayerStatisticVersionsRequestWrapper(PFLeaderboardGetPlayerStatisticVersionsRequestWrapper&& src) :
        PFLeaderboardGetPlayerStatisticVersionsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardGetPlayerStatisticVersionsRequestWrapper& operator=(PFLeaderboardGetPlayerStatisticVersionsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardGetPlayerStatisticVersionsRequestWrapper() = default;

    friend void swap(PFLeaderboardGetPlayerStatisticVersionsRequestWrapper& lhs, PFLeaderboardGetPlayerStatisticVersionsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_statisticName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardPlayerStatisticVersionWrapper : public ModelWrapper<PFLeaderboardPlayerStatisticVersion, Alloc>
{
public:
    using ModelType = typename PFLeaderboardPlayerStatisticVersion;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardPlayerStatisticVersionWrapper() = default;

    PFLeaderboardPlayerStatisticVersionWrapper(const PFLeaderboardPlayerStatisticVersion& model) :
        ModelWrapper<PFLeaderboardPlayerStatisticVersion, Alloc>{ model },
        m_archiveDownloadUrl{ SafeString(model.archiveDownloadUrl) },
        m_deactivationTime{ model.deactivationTime ? StdExtra::optional<time_t>{ *model.deactivationTime } : StdExtra::nullopt },
        m_scheduledActivationTime{ model.scheduledActivationTime ? StdExtra::optional<time_t>{ *model.scheduledActivationTime } : StdExtra::nullopt },
        m_scheduledDeactivationTime{ model.scheduledDeactivationTime ? StdExtra::optional<time_t>{ *model.scheduledDeactivationTime } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) },
        m_status{ model.status ? StdExtra::optional<PFLeaderboardStatisticVersionStatus>{ *model.status } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLeaderboardPlayerStatisticVersionWrapper(const PFLeaderboardPlayerStatisticVersionWrapper& src) :
        PFLeaderboardPlayerStatisticVersionWrapper{ src.Model() }
    {
    }

    PFLeaderboardPlayerStatisticVersionWrapper(PFLeaderboardPlayerStatisticVersionWrapper&& src) :
        PFLeaderboardPlayerStatisticVersionWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardPlayerStatisticVersionWrapper& operator=(PFLeaderboardPlayerStatisticVersionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardPlayerStatisticVersionWrapper() = default;

    friend void swap(PFLeaderboardPlayerStatisticVersionWrapper& lhs, PFLeaderboardPlayerStatisticVersionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_archiveDownloadUrl, rhs.m_archiveDownloadUrl);
        swap(lhs.m_deactivationTime, rhs.m_deactivationTime);
        swap(lhs.m_scheduledActivationTime, rhs.m_scheduledActivationTime);
        swap(lhs.m_scheduledDeactivationTime, rhs.m_scheduledDeactivationTime);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        swap(lhs.m_status, rhs.m_status);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetActivationTime(time_t value)
    {
        this->m_model.activationTime = value;
    }

    void SetArchiveDownloadUrl(String value)
    {
        m_archiveDownloadUrl = std::move(value);
        this->m_model.archiveDownloadUrl =  m_archiveDownloadUrl.empty() ? nullptr : m_archiveDownloadUrl.data();
    }

    void SetDeactivationTime(StdExtra::optional<time_t> value)
    {
        m_deactivationTime = std::move(value);
        this->m_model.deactivationTime = m_deactivationTime ? m_deactivationTime.operator->() : nullptr;
    }

    void SetScheduledActivationTime(StdExtra::optional<time_t> value)
    {
        m_scheduledActivationTime = std::move(value);
        this->m_model.scheduledActivationTime = m_scheduledActivationTime ? m_scheduledActivationTime.operator->() : nullptr;
    }

    void SetScheduledDeactivationTime(StdExtra::optional<time_t> value)
    {
        m_scheduledDeactivationTime = std::move(value);
        this->m_model.scheduledDeactivationTime = m_scheduledDeactivationTime ? m_scheduledDeactivationTime.operator->() : nullptr;
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    void SetStatus(StdExtra::optional<PFLeaderboardStatisticVersionStatus> value)
    {
        m_status = std::move(value);
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

    void SetVersion(uint32_t value)
    {
        this->m_model.version = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.archiveDownloadUrl = m_archiveDownloadUrl.empty() ? nullptr : m_archiveDownloadUrl.data();
        this->m_model.deactivationTime = m_deactivationTime ? m_deactivationTime.operator->() : nullptr;
        this->m_model.scheduledActivationTime = m_scheduledActivationTime ? m_scheduledActivationTime.operator->() : nullptr;
        this->m_model.scheduledDeactivationTime = m_scheduledDeactivationTime ? m_scheduledDeactivationTime.operator->() : nullptr;
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
        this->m_model.status = m_status ? m_status.operator->() : nullptr;
    }

    String m_archiveDownloadUrl;
    StdExtra::optional<time_t> m_deactivationTime;
    StdExtra::optional<time_t> m_scheduledActivationTime;
    StdExtra::optional<time_t> m_scheduledDeactivationTime;
    String m_statisticName;
    StdExtra::optional<PFLeaderboardStatisticVersionStatus> m_status;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardGetPlayerStatisticVersionsResultWrapper : public ModelWrapper<PFLeaderboardGetPlayerStatisticVersionsResult, Alloc>
{
public:
    using ModelType = typename PFLeaderboardGetPlayerStatisticVersionsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardGetPlayerStatisticVersionsResultWrapper() = default;

    PFLeaderboardGetPlayerStatisticVersionsResultWrapper(const PFLeaderboardGetPlayerStatisticVersionsResult& model) :
        ModelWrapper<PFLeaderboardGetPlayerStatisticVersionsResult, Alloc>{ model },
        m_statisticVersions{ model.statisticVersions, model.statisticVersions + model.statisticVersionsCount }
    {
        SetModelPointers();
    }

    PFLeaderboardGetPlayerStatisticVersionsResultWrapper(const PFLeaderboardGetPlayerStatisticVersionsResultWrapper& src) :
        PFLeaderboardGetPlayerStatisticVersionsResultWrapper{ src.Model() }
    {
    }

    PFLeaderboardGetPlayerStatisticVersionsResultWrapper(PFLeaderboardGetPlayerStatisticVersionsResultWrapper&& src) :
        PFLeaderboardGetPlayerStatisticVersionsResultWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardGetPlayerStatisticVersionsResultWrapper& operator=(PFLeaderboardGetPlayerStatisticVersionsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardGetPlayerStatisticVersionsResultWrapper() = default;

    friend void swap(PFLeaderboardGetPlayerStatisticVersionsResultWrapper& lhs, PFLeaderboardGetPlayerStatisticVersionsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_statisticVersions, rhs.m_statisticVersions);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStatisticVersions(ModelVector<PFLeaderboardPlayerStatisticVersionWrapper<Alloc>, Alloc> value)
    {
        m_statisticVersions = std::move(value);
        this->m_model.statisticVersions =  m_statisticVersions.empty() ? nullptr : m_statisticVersions.data();
        this->m_model.statisticVersionsCount =  static_cast<uint32_t>(m_statisticVersions.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.statisticVersions = m_statisticVersions.empty() ? nullptr : m_statisticVersions.data();
    }

    ModelVector<PFLeaderboardPlayerStatisticVersionWrapper<Alloc>, Alloc> m_statisticVersions;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper : public ModelWrapper<PFLeaderboardIncrementPlayerStatisticVersionRequest, Alloc>
{
public:
    using ModelType = typename PFLeaderboardIncrementPlayerStatisticVersionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper() = default;

    PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper(const PFLeaderboardIncrementPlayerStatisticVersionRequest& model) :
        ModelWrapper<PFLeaderboardIncrementPlayerStatisticVersionRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_statisticName{ SafeString(model.statisticName) }
    {
        SetModelPointers();
    }

    PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper(const PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper& src) :
        PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper{ src.Model() }
    {
    }

    PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper(PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper&& src) :
        PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper& operator=(PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper() = default;

    friend void swap(PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper& lhs, PFLeaderboardIncrementPlayerStatisticVersionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_statisticName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardIncrementPlayerStatisticVersionResultWrapper : public ModelWrapper<PFLeaderboardIncrementPlayerStatisticVersionResult, Alloc>
{
public:
    using ModelType = typename PFLeaderboardIncrementPlayerStatisticVersionResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardIncrementPlayerStatisticVersionResultWrapper() = default;

    PFLeaderboardIncrementPlayerStatisticVersionResultWrapper(const PFLeaderboardIncrementPlayerStatisticVersionResult& model) :
        ModelWrapper<PFLeaderboardIncrementPlayerStatisticVersionResult, Alloc>{ model },
        m_statisticVersion{ model.statisticVersion ? StdExtra::optional<PFLeaderboardPlayerStatisticVersionWrapper<Alloc>>{ *model.statisticVersion } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLeaderboardIncrementPlayerStatisticVersionResultWrapper(const PFLeaderboardIncrementPlayerStatisticVersionResultWrapper& src) :
        PFLeaderboardIncrementPlayerStatisticVersionResultWrapper{ src.Model() }
    {
    }

    PFLeaderboardIncrementPlayerStatisticVersionResultWrapper(PFLeaderboardIncrementPlayerStatisticVersionResultWrapper&& src) :
        PFLeaderboardIncrementPlayerStatisticVersionResultWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardIncrementPlayerStatisticVersionResultWrapper& operator=(PFLeaderboardIncrementPlayerStatisticVersionResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardIncrementPlayerStatisticVersionResultWrapper() = default;

    friend void swap(PFLeaderboardIncrementPlayerStatisticVersionResultWrapper& lhs, PFLeaderboardIncrementPlayerStatisticVersionResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_statisticVersion, rhs.m_statisticVersion);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStatisticVersion(StdExtra::optional<PFLeaderboardPlayerStatisticVersionWrapper<Alloc>> value)
    {
        m_statisticVersion = std::move(value);
        this->m_model.statisticVersion = m_statisticVersion ? &m_statisticVersion->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.statisticVersion = m_statisticVersion ?  &m_statisticVersion->Model() : nullptr;
    }

    StdExtra::optional<PFLeaderboardPlayerStatisticVersionWrapper<Alloc>> m_statisticVersion;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardResetUserStatisticsRequestWrapper : public ModelWrapper<PFLeaderboardResetUserStatisticsRequest, Alloc>
{
public:
    using ModelType = typename PFLeaderboardResetUserStatisticsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardResetUserStatisticsRequestWrapper() = default;

    PFLeaderboardResetUserStatisticsRequestWrapper(const PFLeaderboardResetUserStatisticsRequest& model) :
        ModelWrapper<PFLeaderboardResetUserStatisticsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFLeaderboardResetUserStatisticsRequestWrapper(const PFLeaderboardResetUserStatisticsRequestWrapper& src) :
        PFLeaderboardResetUserStatisticsRequestWrapper{ src.Model() }
    {
    }

    PFLeaderboardResetUserStatisticsRequestWrapper(PFLeaderboardResetUserStatisticsRequestWrapper&& src) :
        PFLeaderboardResetUserStatisticsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardResetUserStatisticsRequestWrapper& operator=(PFLeaderboardResetUserStatisticsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardResetUserStatisticsRequestWrapper() = default;

    friend void swap(PFLeaderboardResetUserStatisticsRequestWrapper& lhs, PFLeaderboardResetUserStatisticsRequestWrapper& rhs)
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
class PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper : public ModelWrapper<PFLeaderboardUpdatePlayerStatisticDefinitionRequest, Alloc>
{
public:
    using ModelType = typename PFLeaderboardUpdatePlayerStatisticDefinitionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper() = default;

    PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper(const PFLeaderboardUpdatePlayerStatisticDefinitionRequest& model) :
        ModelWrapper<PFLeaderboardUpdatePlayerStatisticDefinitionRequest, Alloc>{ model },
        m_aggregationMethod{ model.aggregationMethod ? StdExtra::optional<PFLeaderboardStatisticAggregationMethod>{ *model.aggregationMethod } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) },
        m_versionChangeInterval{ model.versionChangeInterval ? StdExtra::optional<PFLeaderboardStatisticResetIntervalOption>{ *model.versionChangeInterval } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper(const PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper& src) :
        PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper{ src.Model() }
    {
    }

    PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper(PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper&& src) :
        PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper& operator=(PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper() = default;

    friend void swap(PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper& lhs, PFLeaderboardUpdatePlayerStatisticDefinitionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_aggregationMethod, rhs.m_aggregationMethod);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        swap(lhs.m_versionChangeInterval, rhs.m_versionChangeInterval);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAggregationMethod(StdExtra::optional<PFLeaderboardStatisticAggregationMethod> value)
    {
        m_aggregationMethod = std::move(value);
        this->m_model.aggregationMethod = m_aggregationMethod ? m_aggregationMethod.operator->() : nullptr;
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    void SetVersionChangeInterval(StdExtra::optional<PFLeaderboardStatisticResetIntervalOption> value)
    {
        m_versionChangeInterval = std::move(value);
        this->m_model.versionChangeInterval = m_versionChangeInterval ? m_versionChangeInterval.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.aggregationMethod = m_aggregationMethod ? m_aggregationMethod.operator->() : nullptr;
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
        this->m_model.versionChangeInterval = m_versionChangeInterval ? m_versionChangeInterval.operator->() : nullptr;
    }

    StdExtra::optional<PFLeaderboardStatisticAggregationMethod> m_aggregationMethod;
    String m_statisticName;
    StdExtra::optional<PFLeaderboardStatisticResetIntervalOption> m_versionChangeInterval;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardUpdatePlayerStatisticDefinitionResultWrapper : public ModelWrapper<PFLeaderboardUpdatePlayerStatisticDefinitionResult, Alloc>
{
public:
    using ModelType = typename PFLeaderboardUpdatePlayerStatisticDefinitionResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardUpdatePlayerStatisticDefinitionResultWrapper() = default;

    PFLeaderboardUpdatePlayerStatisticDefinitionResultWrapper(const PFLeaderboardUpdatePlayerStatisticDefinitionResult& model) :
        ModelWrapper<PFLeaderboardUpdatePlayerStatisticDefinitionResult, Alloc>{ model },
        m_statistic{ model.statistic ? StdExtra::optional<PFLeaderboardPlayerStatisticDefinitionWrapper<Alloc>>{ *model.statistic } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLeaderboardUpdatePlayerStatisticDefinitionResultWrapper(const PFLeaderboardUpdatePlayerStatisticDefinitionResultWrapper& src) :
        PFLeaderboardUpdatePlayerStatisticDefinitionResultWrapper{ src.Model() }
    {
    }

    PFLeaderboardUpdatePlayerStatisticDefinitionResultWrapper(PFLeaderboardUpdatePlayerStatisticDefinitionResultWrapper&& src) :
        PFLeaderboardUpdatePlayerStatisticDefinitionResultWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardUpdatePlayerStatisticDefinitionResultWrapper& operator=(PFLeaderboardUpdatePlayerStatisticDefinitionResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardUpdatePlayerStatisticDefinitionResultWrapper() = default;

    friend void swap(PFLeaderboardUpdatePlayerStatisticDefinitionResultWrapper& lhs, PFLeaderboardUpdatePlayerStatisticDefinitionResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_statistic, rhs.m_statistic);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStatistic(StdExtra::optional<PFLeaderboardPlayerStatisticDefinitionWrapper<Alloc>> value)
    {
        m_statistic = std::move(value);
        this->m_model.statistic = m_statistic ? &m_statistic->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.statistic = m_statistic ?  &m_statistic->Model() : nullptr;
    }

    StdExtra::optional<PFLeaderboardPlayerStatisticDefinitionWrapper<Alloc>> m_statistic;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardClientGetFriendLeaderboardRequestWrapper : public ModelWrapper<PFLeaderboardClientGetFriendLeaderboardRequest, Alloc>
{
public:
    using ModelType = typename PFLeaderboardClientGetFriendLeaderboardRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardClientGetFriendLeaderboardRequestWrapper() = default;

    PFLeaderboardClientGetFriendLeaderboardRequestWrapper(const PFLeaderboardClientGetFriendLeaderboardRequest& model) :
        ModelWrapper<PFLeaderboardClientGetFriendLeaderboardRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_includeFacebookFriends{ model.includeFacebookFriends ? StdExtra::optional<bool>{ *model.includeFacebookFriends } : StdExtra::nullopt },
        m_includeSteamFriends{ model.includeSteamFriends ? StdExtra::optional<bool>{ *model.includeSteamFriends } : StdExtra::nullopt },
        m_maxResultsCount{ model.maxResultsCount ? StdExtra::optional<int32_t>{ *model.maxResultsCount } : StdExtra::nullopt },
        m_profileConstraints{ model.profileConstraints ? StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>>{ *model.profileConstraints } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) },
        m_version{ model.version ? StdExtra::optional<int32_t>{ *model.version } : StdExtra::nullopt },
        m_xboxToken{ SafeString(model.xboxToken) }
    {
        SetModelPointers();
    }

    PFLeaderboardClientGetFriendLeaderboardRequestWrapper(const PFLeaderboardClientGetFriendLeaderboardRequestWrapper& src) :
        PFLeaderboardClientGetFriendLeaderboardRequestWrapper{ src.Model() }
    {
    }

    PFLeaderboardClientGetFriendLeaderboardRequestWrapper(PFLeaderboardClientGetFriendLeaderboardRequestWrapper&& src) :
        PFLeaderboardClientGetFriendLeaderboardRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardClientGetFriendLeaderboardRequestWrapper& operator=(PFLeaderboardClientGetFriendLeaderboardRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardClientGetFriendLeaderboardRequestWrapper() = default;

    friend void swap(PFLeaderboardClientGetFriendLeaderboardRequestWrapper& lhs, PFLeaderboardClientGetFriendLeaderboardRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_includeFacebookFriends, rhs.m_includeFacebookFriends);
        swap(lhs.m_includeSteamFriends, rhs.m_includeSteamFriends);
        swap(lhs.m_maxResultsCount, rhs.m_maxResultsCount);
        swap(lhs.m_profileConstraints, rhs.m_profileConstraints);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        swap(lhs.m_version, rhs.m_version);
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

    void SetIncludeFacebookFriends(StdExtra::optional<bool> value)
    {
        m_includeFacebookFriends = std::move(value);
        this->m_model.includeFacebookFriends = m_includeFacebookFriends ? m_includeFacebookFriends.operator->() : nullptr;
    }

    void SetIncludeSteamFriends(StdExtra::optional<bool> value)
    {
        m_includeSteamFriends = std::move(value);
        this->m_model.includeSteamFriends = m_includeSteamFriends ? m_includeSteamFriends.operator->() : nullptr;
    }

    void SetMaxResultsCount(StdExtra::optional<int32_t> value)
    {
        m_maxResultsCount = std::move(value);
        this->m_model.maxResultsCount = m_maxResultsCount ? m_maxResultsCount.operator->() : nullptr;
    }

    void SetProfileConstraints(StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>> value)
    {
        m_profileConstraints = std::move(value);
        this->m_model.profileConstraints = m_profileConstraints ? &m_profileConstraints->Model() : nullptr;
    }

    void SetStartPosition(int32_t value)
    {
        this->m_model.startPosition = value;
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    void SetVersion(StdExtra::optional<int32_t> value)
    {
        m_version = std::move(value);
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
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
        this->m_model.includeFacebookFriends = m_includeFacebookFriends ? m_includeFacebookFriends.operator->() : nullptr;
        this->m_model.includeSteamFriends = m_includeSteamFriends ? m_includeSteamFriends.operator->() : nullptr;
        this->m_model.maxResultsCount = m_maxResultsCount ? m_maxResultsCount.operator->() : nullptr;
        this->m_model.profileConstraints = m_profileConstraints ?  &m_profileConstraints->Model() : nullptr;
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
        this->m_model.xboxToken = m_xboxToken.empty() ? nullptr : m_xboxToken.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_includeFacebookFriends;
    StdExtra::optional<bool> m_includeSteamFriends;
    StdExtra::optional<int32_t> m_maxResultsCount;
    StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>> m_profileConstraints;
    String m_statisticName;
    StdExtra::optional<int32_t> m_version;
    String m_xboxToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardPlayerLeaderboardEntryWrapper : public ModelWrapper<PFLeaderboardPlayerLeaderboardEntry, Alloc>
{
public:
    using ModelType = typename PFLeaderboardPlayerLeaderboardEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardPlayerLeaderboardEntryWrapper() = default;

    PFLeaderboardPlayerLeaderboardEntryWrapper(const PFLeaderboardPlayerLeaderboardEntry& model) :
        ModelWrapper<PFLeaderboardPlayerLeaderboardEntry, Alloc>{ model },
        m_displayName{ SafeString(model.displayName) },
        m_playFabId{ SafeString(model.playFabId) },
        m_profile{ model.profile ? StdExtra::optional<PFPlayerProfileModelWrapper<Alloc>>{ *model.profile } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLeaderboardPlayerLeaderboardEntryWrapper(const PFLeaderboardPlayerLeaderboardEntryWrapper& src) :
        PFLeaderboardPlayerLeaderboardEntryWrapper{ src.Model() }
    {
    }

    PFLeaderboardPlayerLeaderboardEntryWrapper(PFLeaderboardPlayerLeaderboardEntryWrapper&& src) :
        PFLeaderboardPlayerLeaderboardEntryWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardPlayerLeaderboardEntryWrapper& operator=(PFLeaderboardPlayerLeaderboardEntryWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardPlayerLeaderboardEntryWrapper() = default;

    friend void swap(PFLeaderboardPlayerLeaderboardEntryWrapper& lhs, PFLeaderboardPlayerLeaderboardEntryWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_displayName, rhs.m_displayName);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_profile, rhs.m_profile);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
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

    void SetPosition(int32_t value)
    {
        this->m_model.position = value;
    }

    void SetProfile(StdExtra::optional<PFPlayerProfileModelWrapper<Alloc>> value)
    {
        m_profile = std::move(value);
        this->m_model.profile = m_profile ? &m_profile->Model() : nullptr;
    }

    void SetStatValue(int32_t value)
    {
        this->m_model.statValue = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.displayName = m_displayName.empty() ? nullptr : m_displayName.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.profile = m_profile ?  &m_profile->Model() : nullptr;
    }

    String m_displayName;
    String m_playFabId;
    StdExtra::optional<PFPlayerProfileModelWrapper<Alloc>> m_profile;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardGetLeaderboardResultWrapper : public ModelWrapper<PFLeaderboardGetLeaderboardResult, Alloc>
{
public:
    using ModelType = typename PFLeaderboardGetLeaderboardResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardGetLeaderboardResultWrapper() = default;

    PFLeaderboardGetLeaderboardResultWrapper(const PFLeaderboardGetLeaderboardResult& model) :
        ModelWrapper<PFLeaderboardGetLeaderboardResult, Alloc>{ model },
        m_leaderboard{ model.leaderboard, model.leaderboard + model.leaderboardCount },
        m_nextReset{ model.nextReset ? StdExtra::optional<time_t>{ *model.nextReset } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLeaderboardGetLeaderboardResultWrapper(const PFLeaderboardGetLeaderboardResultWrapper& src) :
        PFLeaderboardGetLeaderboardResultWrapper{ src.Model() }
    {
    }

    PFLeaderboardGetLeaderboardResultWrapper(PFLeaderboardGetLeaderboardResultWrapper&& src) :
        PFLeaderboardGetLeaderboardResultWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardGetLeaderboardResultWrapper& operator=(PFLeaderboardGetLeaderboardResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardGetLeaderboardResultWrapper() = default;

    friend void swap(PFLeaderboardGetLeaderboardResultWrapper& lhs, PFLeaderboardGetLeaderboardResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_leaderboard, rhs.m_leaderboard);
        swap(lhs.m_nextReset, rhs.m_nextReset);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLeaderboard(ModelVector<PFLeaderboardPlayerLeaderboardEntryWrapper<Alloc>, Alloc> value)
    {
        m_leaderboard = std::move(value);
        this->m_model.leaderboard =  m_leaderboard.empty() ? nullptr : m_leaderboard.data();
        this->m_model.leaderboardCount =  static_cast<uint32_t>(m_leaderboard.size());
    }

    void SetNextReset(StdExtra::optional<time_t> value)
    {
        m_nextReset = std::move(value);
        this->m_model.nextReset = m_nextReset ? m_nextReset.operator->() : nullptr;
    }

    void SetVersion(int32_t value)
    {
        this->m_model.version = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.leaderboard = m_leaderboard.empty() ? nullptr : m_leaderboard.data();
        this->m_model.nextReset = m_nextReset ? m_nextReset.operator->() : nullptr;
    }

    ModelVector<PFLeaderboardPlayerLeaderboardEntryWrapper<Alloc>, Alloc> m_leaderboard;
    StdExtra::optional<time_t> m_nextReset;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper : public ModelWrapper<PFLeaderboardGetFriendLeaderboardAroundPlayerRequest, Alloc>
{
public:
    using ModelType = typename PFLeaderboardGetFriendLeaderboardAroundPlayerRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper() = default;

    PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper(const PFLeaderboardGetFriendLeaderboardAroundPlayerRequest& model) :
        ModelWrapper<PFLeaderboardGetFriendLeaderboardAroundPlayerRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_includeFacebookFriends{ model.includeFacebookFriends ? StdExtra::optional<bool>{ *model.includeFacebookFriends } : StdExtra::nullopt },
        m_includeSteamFriends{ model.includeSteamFriends ? StdExtra::optional<bool>{ *model.includeSteamFriends } : StdExtra::nullopt },
        m_maxResultsCount{ model.maxResultsCount ? StdExtra::optional<int32_t>{ *model.maxResultsCount } : StdExtra::nullopt },
        m_playFabId{ SafeString(model.playFabId) },
        m_profileConstraints{ model.profileConstraints ? StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>>{ *model.profileConstraints } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) },
        m_version{ model.version ? StdExtra::optional<int32_t>{ *model.version } : StdExtra::nullopt },
        m_xboxToken{ SafeString(model.xboxToken) }
    {
        SetModelPointers();
    }

    PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper(const PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper& src) :
        PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper{ src.Model() }
    {
    }

    PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper(PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper&& src) :
        PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper& operator=(PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper() = default;

    friend void swap(PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper& lhs, PFLeaderboardGetFriendLeaderboardAroundPlayerRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_includeFacebookFriends, rhs.m_includeFacebookFriends);
        swap(lhs.m_includeSteamFriends, rhs.m_includeSteamFriends);
        swap(lhs.m_maxResultsCount, rhs.m_maxResultsCount);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_profileConstraints, rhs.m_profileConstraints);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        swap(lhs.m_version, rhs.m_version);
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

    void SetIncludeFacebookFriends(StdExtra::optional<bool> value)
    {
        m_includeFacebookFriends = std::move(value);
        this->m_model.includeFacebookFriends = m_includeFacebookFriends ? m_includeFacebookFriends.operator->() : nullptr;
    }

    void SetIncludeSteamFriends(StdExtra::optional<bool> value)
    {
        m_includeSteamFriends = std::move(value);
        this->m_model.includeSteamFriends = m_includeSteamFriends ? m_includeSteamFriends.operator->() : nullptr;
    }

    void SetMaxResultsCount(StdExtra::optional<int32_t> value)
    {
        m_maxResultsCount = std::move(value);
        this->m_model.maxResultsCount = m_maxResultsCount ? m_maxResultsCount.operator->() : nullptr;
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

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    void SetVersion(StdExtra::optional<int32_t> value)
    {
        m_version = std::move(value);
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
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
        this->m_model.includeFacebookFriends = m_includeFacebookFriends ? m_includeFacebookFriends.operator->() : nullptr;
        this->m_model.includeSteamFriends = m_includeSteamFriends ? m_includeSteamFriends.operator->() : nullptr;
        this->m_model.maxResultsCount = m_maxResultsCount ? m_maxResultsCount.operator->() : nullptr;
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.profileConstraints = m_profileConstraints ?  &m_profileConstraints->Model() : nullptr;
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
        this->m_model.xboxToken = m_xboxToken.empty() ? nullptr : m_xboxToken.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_includeFacebookFriends;
    StdExtra::optional<bool> m_includeSteamFriends;
    StdExtra::optional<int32_t> m_maxResultsCount;
    String m_playFabId;
    StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>> m_profileConstraints;
    String m_statisticName;
    StdExtra::optional<int32_t> m_version;
    String m_xboxToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardGetFriendLeaderboardAroundPlayerResultWrapper : public ModelWrapper<PFLeaderboardGetFriendLeaderboardAroundPlayerResult, Alloc>
{
public:
    using ModelType = typename PFLeaderboardGetFriendLeaderboardAroundPlayerResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardGetFriendLeaderboardAroundPlayerResultWrapper() = default;

    PFLeaderboardGetFriendLeaderboardAroundPlayerResultWrapper(const PFLeaderboardGetFriendLeaderboardAroundPlayerResult& model) :
        ModelWrapper<PFLeaderboardGetFriendLeaderboardAroundPlayerResult, Alloc>{ model },
        m_leaderboard{ model.leaderboard, model.leaderboard + model.leaderboardCount },
        m_nextReset{ model.nextReset ? StdExtra::optional<time_t>{ *model.nextReset } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLeaderboardGetFriendLeaderboardAroundPlayerResultWrapper(const PFLeaderboardGetFriendLeaderboardAroundPlayerResultWrapper& src) :
        PFLeaderboardGetFriendLeaderboardAroundPlayerResultWrapper{ src.Model() }
    {
    }

    PFLeaderboardGetFriendLeaderboardAroundPlayerResultWrapper(PFLeaderboardGetFriendLeaderboardAroundPlayerResultWrapper&& src) :
        PFLeaderboardGetFriendLeaderboardAroundPlayerResultWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardGetFriendLeaderboardAroundPlayerResultWrapper& operator=(PFLeaderboardGetFriendLeaderboardAroundPlayerResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardGetFriendLeaderboardAroundPlayerResultWrapper() = default;

    friend void swap(PFLeaderboardGetFriendLeaderboardAroundPlayerResultWrapper& lhs, PFLeaderboardGetFriendLeaderboardAroundPlayerResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_leaderboard, rhs.m_leaderboard);
        swap(lhs.m_nextReset, rhs.m_nextReset);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLeaderboard(ModelVector<PFLeaderboardPlayerLeaderboardEntryWrapper<Alloc>, Alloc> value)
    {
        m_leaderboard = std::move(value);
        this->m_model.leaderboard =  m_leaderboard.empty() ? nullptr : m_leaderboard.data();
        this->m_model.leaderboardCount =  static_cast<uint32_t>(m_leaderboard.size());
    }

    void SetNextReset(StdExtra::optional<time_t> value)
    {
        m_nextReset = std::move(value);
        this->m_model.nextReset = m_nextReset ? m_nextReset.operator->() : nullptr;
    }

    void SetVersion(int32_t value)
    {
        this->m_model.version = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.leaderboard = m_leaderboard.empty() ? nullptr : m_leaderboard.data();
        this->m_model.nextReset = m_nextReset ? m_nextReset.operator->() : nullptr;
    }

    ModelVector<PFLeaderboardPlayerLeaderboardEntryWrapper<Alloc>, Alloc> m_leaderboard;
    StdExtra::optional<time_t> m_nextReset;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardGetLeaderboardRequestWrapper : public ModelWrapper<PFLeaderboardGetLeaderboardRequest, Alloc>
{
public:
    using ModelType = typename PFLeaderboardGetLeaderboardRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardGetLeaderboardRequestWrapper() = default;

    PFLeaderboardGetLeaderboardRequestWrapper(const PFLeaderboardGetLeaderboardRequest& model) :
        ModelWrapper<PFLeaderboardGetLeaderboardRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_profileConstraints{ model.profileConstraints ? StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>>{ *model.profileConstraints } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) },
        m_version{ model.version ? StdExtra::optional<int32_t>{ *model.version } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLeaderboardGetLeaderboardRequestWrapper(const PFLeaderboardGetLeaderboardRequestWrapper& src) :
        PFLeaderboardGetLeaderboardRequestWrapper{ src.Model() }
    {
    }

    PFLeaderboardGetLeaderboardRequestWrapper(PFLeaderboardGetLeaderboardRequestWrapper&& src) :
        PFLeaderboardGetLeaderboardRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardGetLeaderboardRequestWrapper& operator=(PFLeaderboardGetLeaderboardRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardGetLeaderboardRequestWrapper() = default;

    friend void swap(PFLeaderboardGetLeaderboardRequestWrapper& lhs, PFLeaderboardGetLeaderboardRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_profileConstraints, rhs.m_profileConstraints);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        swap(lhs.m_version, rhs.m_version);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetMaxResultsCount(int32_t value)
    {
        this->m_model.maxResultsCount = value;
    }

    void SetProfileConstraints(StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>> value)
    {
        m_profileConstraints = std::move(value);
        this->m_model.profileConstraints = m_profileConstraints ? &m_profileConstraints->Model() : nullptr;
    }

    void SetStartPosition(int32_t value)
    {
        this->m_model.startPosition = value;
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    void SetVersion(StdExtra::optional<int32_t> value)
    {
        m_version = std::move(value);
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.profileConstraints = m_profileConstraints ?  &m_profileConstraints->Model() : nullptr;
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>> m_profileConstraints;
    String m_statisticName;
    StdExtra::optional<int32_t> m_version;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper : public ModelWrapper<PFLeaderboardGetLeaderboardAroundPlayerRequest, Alloc>
{
public:
    using ModelType = typename PFLeaderboardGetLeaderboardAroundPlayerRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper() = default;

    PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper(const PFLeaderboardGetLeaderboardAroundPlayerRequest& model) :
        ModelWrapper<PFLeaderboardGetLeaderboardAroundPlayerRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_maxResultsCount{ model.maxResultsCount ? StdExtra::optional<int32_t>{ *model.maxResultsCount } : StdExtra::nullopt },
        m_playFabId{ SafeString(model.playFabId) },
        m_profileConstraints{ model.profileConstraints ? StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>>{ *model.profileConstraints } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) },
        m_version{ model.version ? StdExtra::optional<int32_t>{ *model.version } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper(const PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper& src) :
        PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper{ src.Model() }
    {
    }

    PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper(PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper&& src) :
        PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper& operator=(PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper() = default;

    friend void swap(PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper& lhs, PFLeaderboardGetLeaderboardAroundPlayerRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_maxResultsCount, rhs.m_maxResultsCount);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_profileConstraints, rhs.m_profileConstraints);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        swap(lhs.m_version, rhs.m_version);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetMaxResultsCount(StdExtra::optional<int32_t> value)
    {
        m_maxResultsCount = std::move(value);
        this->m_model.maxResultsCount = m_maxResultsCount ? m_maxResultsCount.operator->() : nullptr;
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

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    void SetVersion(StdExtra::optional<int32_t> value)
    {
        m_version = std::move(value);
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.maxResultsCount = m_maxResultsCount ? m_maxResultsCount.operator->() : nullptr;
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.profileConstraints = m_profileConstraints ?  &m_profileConstraints->Model() : nullptr;
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<int32_t> m_maxResultsCount;
    String m_playFabId;
    StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>> m_profileConstraints;
    String m_statisticName;
    StdExtra::optional<int32_t> m_version;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardGetLeaderboardAroundPlayerResultWrapper : public ModelWrapper<PFLeaderboardGetLeaderboardAroundPlayerResult, Alloc>
{
public:
    using ModelType = typename PFLeaderboardGetLeaderboardAroundPlayerResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardGetLeaderboardAroundPlayerResultWrapper() = default;

    PFLeaderboardGetLeaderboardAroundPlayerResultWrapper(const PFLeaderboardGetLeaderboardAroundPlayerResult& model) :
        ModelWrapper<PFLeaderboardGetLeaderboardAroundPlayerResult, Alloc>{ model },
        m_leaderboard{ model.leaderboard, model.leaderboard + model.leaderboardCount },
        m_nextReset{ model.nextReset ? StdExtra::optional<time_t>{ *model.nextReset } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLeaderboardGetLeaderboardAroundPlayerResultWrapper(const PFLeaderboardGetLeaderboardAroundPlayerResultWrapper& src) :
        PFLeaderboardGetLeaderboardAroundPlayerResultWrapper{ src.Model() }
    {
    }

    PFLeaderboardGetLeaderboardAroundPlayerResultWrapper(PFLeaderboardGetLeaderboardAroundPlayerResultWrapper&& src) :
        PFLeaderboardGetLeaderboardAroundPlayerResultWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardGetLeaderboardAroundPlayerResultWrapper& operator=(PFLeaderboardGetLeaderboardAroundPlayerResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardGetLeaderboardAroundPlayerResultWrapper() = default;

    friend void swap(PFLeaderboardGetLeaderboardAroundPlayerResultWrapper& lhs, PFLeaderboardGetLeaderboardAroundPlayerResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_leaderboard, rhs.m_leaderboard);
        swap(lhs.m_nextReset, rhs.m_nextReset);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLeaderboard(ModelVector<PFLeaderboardPlayerLeaderboardEntryWrapper<Alloc>, Alloc> value)
    {
        m_leaderboard = std::move(value);
        this->m_model.leaderboard =  m_leaderboard.empty() ? nullptr : m_leaderboard.data();
        this->m_model.leaderboardCount =  static_cast<uint32_t>(m_leaderboard.size());
    }

    void SetNextReset(StdExtra::optional<time_t> value)
    {
        m_nextReset = std::move(value);
        this->m_model.nextReset = m_nextReset ? m_nextReset.operator->() : nullptr;
    }

    void SetVersion(int32_t value)
    {
        this->m_model.version = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.leaderboard = m_leaderboard.empty() ? nullptr : m_leaderboard.data();
        this->m_model.nextReset = m_nextReset ? m_nextReset.operator->() : nullptr;
    }

    ModelVector<PFLeaderboardPlayerLeaderboardEntryWrapper<Alloc>, Alloc> m_leaderboard;
    StdExtra::optional<time_t> m_nextReset;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardStatisticNameVersionWrapper : public ModelWrapper<PFLeaderboardStatisticNameVersion, Alloc>
{
public:
    using ModelType = typename PFLeaderboardStatisticNameVersion;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardStatisticNameVersionWrapper() = default;

    PFLeaderboardStatisticNameVersionWrapper(const PFLeaderboardStatisticNameVersion& model) :
        ModelWrapper<PFLeaderboardStatisticNameVersion, Alloc>{ model },
        m_statisticName{ SafeString(model.statisticName) }
    {
        SetModelPointers();
    }

    PFLeaderboardStatisticNameVersionWrapper(const PFLeaderboardStatisticNameVersionWrapper& src) :
        PFLeaderboardStatisticNameVersionWrapper{ src.Model() }
    {
    }

    PFLeaderboardStatisticNameVersionWrapper(PFLeaderboardStatisticNameVersionWrapper&& src) :
        PFLeaderboardStatisticNameVersionWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardStatisticNameVersionWrapper& operator=(PFLeaderboardStatisticNameVersionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardStatisticNameVersionWrapper() = default;

    friend void swap(PFLeaderboardStatisticNameVersionWrapper& lhs, PFLeaderboardStatisticNameVersionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    void SetVersion(uint32_t value)
    {
        this->m_model.version = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    String m_statisticName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardClientGetPlayerStatisticsRequestWrapper : public ModelWrapper<PFLeaderboardClientGetPlayerStatisticsRequest, Alloc>
{
public:
    using ModelType = typename PFLeaderboardClientGetPlayerStatisticsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardClientGetPlayerStatisticsRequestWrapper() = default;

    PFLeaderboardClientGetPlayerStatisticsRequestWrapper(const PFLeaderboardClientGetPlayerStatisticsRequest& model) :
        ModelWrapper<PFLeaderboardClientGetPlayerStatisticsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_statisticNames{ model.statisticNames, model.statisticNames + model.statisticNamesCount },
        m_statisticNameVersions{ model.statisticNameVersions, model.statisticNameVersions + model.statisticNameVersionsCount }
    {
        SetModelPointers();
    }

    PFLeaderboardClientGetPlayerStatisticsRequestWrapper(const PFLeaderboardClientGetPlayerStatisticsRequestWrapper& src) :
        PFLeaderboardClientGetPlayerStatisticsRequestWrapper{ src.Model() }
    {
    }

    PFLeaderboardClientGetPlayerStatisticsRequestWrapper(PFLeaderboardClientGetPlayerStatisticsRequestWrapper&& src) :
        PFLeaderboardClientGetPlayerStatisticsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardClientGetPlayerStatisticsRequestWrapper& operator=(PFLeaderboardClientGetPlayerStatisticsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardClientGetPlayerStatisticsRequestWrapper() = default;

    friend void swap(PFLeaderboardClientGetPlayerStatisticsRequestWrapper& lhs, PFLeaderboardClientGetPlayerStatisticsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_statisticNames, rhs.m_statisticNames);
        swap(lhs.m_statisticNameVersions, rhs.m_statisticNameVersions);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetStatisticNames(CStringVector<Alloc> value)
    {
        m_statisticNames = std::move(value);
        this->m_model.statisticNames =  m_statisticNames.empty() ? nullptr : m_statisticNames.data();
        this->m_model.statisticNamesCount =  static_cast<uint32_t>(m_statisticNames.size());
    }

    void SetStatisticNameVersions(ModelVector<PFLeaderboardStatisticNameVersionWrapper<Alloc>, Alloc> value)
    {
        m_statisticNameVersions = std::move(value);
        this->m_model.statisticNameVersions =  m_statisticNameVersions.empty() ? nullptr : m_statisticNameVersions.data();
        this->m_model.statisticNameVersionsCount =  static_cast<uint32_t>(m_statisticNameVersions.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.statisticNames = m_statisticNames.empty() ? nullptr : m_statisticNames.data();
        this->m_model.statisticNameVersions = m_statisticNameVersions.empty() ? nullptr : m_statisticNameVersions.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    CStringVector<Alloc> m_statisticNames;
    ModelVector<PFLeaderboardStatisticNameVersionWrapper<Alloc>, Alloc> m_statisticNameVersions;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardClientGetPlayerStatisticsResultWrapper : public ModelWrapper<PFLeaderboardClientGetPlayerStatisticsResult, Alloc>
{
public:
    using ModelType = typename PFLeaderboardClientGetPlayerStatisticsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardClientGetPlayerStatisticsResultWrapper() = default;

    PFLeaderboardClientGetPlayerStatisticsResultWrapper(const PFLeaderboardClientGetPlayerStatisticsResult& model) :
        ModelWrapper<PFLeaderboardClientGetPlayerStatisticsResult, Alloc>{ model },
        m_statistics{ model.statistics, model.statistics + model.statisticsCount }
    {
        SetModelPointers();
    }

    PFLeaderboardClientGetPlayerStatisticsResultWrapper(const PFLeaderboardClientGetPlayerStatisticsResultWrapper& src) :
        PFLeaderboardClientGetPlayerStatisticsResultWrapper{ src.Model() }
    {
    }

    PFLeaderboardClientGetPlayerStatisticsResultWrapper(PFLeaderboardClientGetPlayerStatisticsResultWrapper&& src) :
        PFLeaderboardClientGetPlayerStatisticsResultWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardClientGetPlayerStatisticsResultWrapper& operator=(PFLeaderboardClientGetPlayerStatisticsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardClientGetPlayerStatisticsResultWrapper() = default;

    friend void swap(PFLeaderboardClientGetPlayerStatisticsResultWrapper& lhs, PFLeaderboardClientGetPlayerStatisticsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_statistics, rhs.m_statistics);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStatistics(ModelVector<PFStatisticValueWrapper<Alloc>, Alloc> value)
    {
        m_statistics = std::move(value);
        this->m_model.statistics =  m_statistics.empty() ? nullptr : m_statistics.data();
        this->m_model.statisticsCount =  static_cast<uint32_t>(m_statistics.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.statistics = m_statistics.empty() ? nullptr : m_statistics.data();
    }

    ModelVector<PFStatisticValueWrapper<Alloc>, Alloc> m_statistics;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardStatisticUpdateWrapper : public ModelWrapper<PFLeaderboardStatisticUpdate, Alloc>
{
public:
    using ModelType = typename PFLeaderboardStatisticUpdate;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardStatisticUpdateWrapper() = default;

    PFLeaderboardStatisticUpdateWrapper(const PFLeaderboardStatisticUpdate& model) :
        ModelWrapper<PFLeaderboardStatisticUpdate, Alloc>{ model },
        m_statisticName{ SafeString(model.statisticName) },
        m_version{ model.version ? StdExtra::optional<uint32_t>{ *model.version } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLeaderboardStatisticUpdateWrapper(const PFLeaderboardStatisticUpdateWrapper& src) :
        PFLeaderboardStatisticUpdateWrapper{ src.Model() }
    {
    }

    PFLeaderboardStatisticUpdateWrapper(PFLeaderboardStatisticUpdateWrapper&& src) :
        PFLeaderboardStatisticUpdateWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardStatisticUpdateWrapper& operator=(PFLeaderboardStatisticUpdateWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardStatisticUpdateWrapper() = default;

    friend void swap(PFLeaderboardStatisticUpdateWrapper& lhs, PFLeaderboardStatisticUpdateWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        swap(lhs.m_version, rhs.m_version);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    void SetValue(int32_t value)
    {
        this->m_model.value = value;
    }

    void SetVersion(StdExtra::optional<uint32_t> value)
    {
        m_version = std::move(value);
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
    }

    String m_statisticName;
    StdExtra::optional<uint32_t> m_version;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper : public ModelWrapper<PFLeaderboardClientUpdatePlayerStatisticsRequest, Alloc>
{
public:
    using ModelType = typename PFLeaderboardClientUpdatePlayerStatisticsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper() = default;

    PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper(const PFLeaderboardClientUpdatePlayerStatisticsRequest& model) :
        ModelWrapper<PFLeaderboardClientUpdatePlayerStatisticsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_statistics{ model.statistics, model.statistics + model.statisticsCount }
    {
        SetModelPointers();
    }

    PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper(const PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper& src) :
        PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper{ src.Model() }
    {
    }

    PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper(PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper&& src) :
        PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper& operator=(PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper() = default;

    friend void swap(PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper& lhs, PFLeaderboardClientUpdatePlayerStatisticsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_statistics, rhs.m_statistics);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetStatistics(ModelVector<PFLeaderboardStatisticUpdateWrapper<Alloc>, Alloc> value)
    {
        m_statistics = std::move(value);
        this->m_model.statistics =  m_statistics.empty() ? nullptr : m_statistics.data();
        this->m_model.statisticsCount =  static_cast<uint32_t>(m_statistics.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.statistics = m_statistics.empty() ? nullptr : m_statistics.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    ModelVector<PFLeaderboardStatisticUpdateWrapper<Alloc>, Alloc> m_statistics;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardServerGetFriendLeaderboardRequestWrapper : public ModelWrapper<PFLeaderboardServerGetFriendLeaderboardRequest, Alloc>
{
public:
    using ModelType = typename PFLeaderboardServerGetFriendLeaderboardRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardServerGetFriendLeaderboardRequestWrapper() = default;

    PFLeaderboardServerGetFriendLeaderboardRequestWrapper(const PFLeaderboardServerGetFriendLeaderboardRequest& model) :
        ModelWrapper<PFLeaderboardServerGetFriendLeaderboardRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_includeFacebookFriends{ model.includeFacebookFriends ? StdExtra::optional<bool>{ *model.includeFacebookFriends } : StdExtra::nullopt },
        m_includeSteamFriends{ model.includeSteamFriends ? StdExtra::optional<bool>{ *model.includeSteamFriends } : StdExtra::nullopt },
        m_playFabId{ SafeString(model.playFabId) },
        m_profileConstraints{ model.profileConstraints ? StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>>{ *model.profileConstraints } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) },
        m_version{ model.version ? StdExtra::optional<int32_t>{ *model.version } : StdExtra::nullopt },
        m_xboxToken{ SafeString(model.xboxToken) }
    {
        SetModelPointers();
    }

    PFLeaderboardServerGetFriendLeaderboardRequestWrapper(const PFLeaderboardServerGetFriendLeaderboardRequestWrapper& src) :
        PFLeaderboardServerGetFriendLeaderboardRequestWrapper{ src.Model() }
    {
    }

    PFLeaderboardServerGetFriendLeaderboardRequestWrapper(PFLeaderboardServerGetFriendLeaderboardRequestWrapper&& src) :
        PFLeaderboardServerGetFriendLeaderboardRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardServerGetFriendLeaderboardRequestWrapper& operator=(PFLeaderboardServerGetFriendLeaderboardRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardServerGetFriendLeaderboardRequestWrapper() = default;

    friend void swap(PFLeaderboardServerGetFriendLeaderboardRequestWrapper& lhs, PFLeaderboardServerGetFriendLeaderboardRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_includeFacebookFriends, rhs.m_includeFacebookFriends);
        swap(lhs.m_includeSteamFriends, rhs.m_includeSteamFriends);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_profileConstraints, rhs.m_profileConstraints);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        swap(lhs.m_version, rhs.m_version);
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

    void SetIncludeFacebookFriends(StdExtra::optional<bool> value)
    {
        m_includeFacebookFriends = std::move(value);
        this->m_model.includeFacebookFriends = m_includeFacebookFriends ? m_includeFacebookFriends.operator->() : nullptr;
    }

    void SetIncludeSteamFriends(StdExtra::optional<bool> value)
    {
        m_includeSteamFriends = std::move(value);
        this->m_model.includeSteamFriends = m_includeSteamFriends ? m_includeSteamFriends.operator->() : nullptr;
    }

    void SetMaxResultsCount(int32_t value)
    {
        this->m_model.maxResultsCount = value;
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

    void SetStartPosition(int32_t value)
    {
        this->m_model.startPosition = value;
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    void SetVersion(StdExtra::optional<int32_t> value)
    {
        m_version = std::move(value);
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
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
        this->m_model.includeFacebookFriends = m_includeFacebookFriends ? m_includeFacebookFriends.operator->() : nullptr;
        this->m_model.includeSteamFriends = m_includeSteamFriends ? m_includeSteamFriends.operator->() : nullptr;
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.profileConstraints = m_profileConstraints ?  &m_profileConstraints->Model() : nullptr;
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
        this->m_model.xboxToken = m_xboxToken.empty() ? nullptr : m_xboxToken.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_includeFacebookFriends;
    StdExtra::optional<bool> m_includeSteamFriends;
    String m_playFabId;
    StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>> m_profileConstraints;
    String m_statisticName;
    StdExtra::optional<int32_t> m_version;
    String m_xboxToken;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardGetLeaderboardAroundUserRequestWrapper : public ModelWrapper<PFLeaderboardGetLeaderboardAroundUserRequest, Alloc>
{
public:
    using ModelType = typename PFLeaderboardGetLeaderboardAroundUserRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardGetLeaderboardAroundUserRequestWrapper() = default;

    PFLeaderboardGetLeaderboardAroundUserRequestWrapper(const PFLeaderboardGetLeaderboardAroundUserRequest& model) :
        ModelWrapper<PFLeaderboardGetLeaderboardAroundUserRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_profileConstraints{ model.profileConstraints ? StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>>{ *model.profileConstraints } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) },
        m_version{ model.version ? StdExtra::optional<int32_t>{ *model.version } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLeaderboardGetLeaderboardAroundUserRequestWrapper(const PFLeaderboardGetLeaderboardAroundUserRequestWrapper& src) :
        PFLeaderboardGetLeaderboardAroundUserRequestWrapper{ src.Model() }
    {
    }

    PFLeaderboardGetLeaderboardAroundUserRequestWrapper(PFLeaderboardGetLeaderboardAroundUserRequestWrapper&& src) :
        PFLeaderboardGetLeaderboardAroundUserRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardGetLeaderboardAroundUserRequestWrapper& operator=(PFLeaderboardGetLeaderboardAroundUserRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardGetLeaderboardAroundUserRequestWrapper() = default;

    friend void swap(PFLeaderboardGetLeaderboardAroundUserRequestWrapper& lhs, PFLeaderboardGetLeaderboardAroundUserRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_profileConstraints, rhs.m_profileConstraints);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        swap(lhs.m_version, rhs.m_version);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetMaxResultsCount(int32_t value)
    {
        this->m_model.maxResultsCount = value;
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

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    void SetVersion(StdExtra::optional<int32_t> value)
    {
        m_version = std::move(value);
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.profileConstraints = m_profileConstraints ?  &m_profileConstraints->Model() : nullptr;
        this->m_model.statisticName = m_statisticName.empty() ? nullptr : m_statisticName.data();
        this->m_model.version = m_version ? m_version.operator->() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
    StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>> m_profileConstraints;
    String m_statisticName;
    StdExtra::optional<int32_t> m_version;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardGetLeaderboardAroundUserResultWrapper : public ModelWrapper<PFLeaderboardGetLeaderboardAroundUserResult, Alloc>
{
public:
    using ModelType = typename PFLeaderboardGetLeaderboardAroundUserResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardGetLeaderboardAroundUserResultWrapper() = default;

    PFLeaderboardGetLeaderboardAroundUserResultWrapper(const PFLeaderboardGetLeaderboardAroundUserResult& model) :
        ModelWrapper<PFLeaderboardGetLeaderboardAroundUserResult, Alloc>{ model },
        m_leaderboard{ model.leaderboard, model.leaderboard + model.leaderboardCount },
        m_nextReset{ model.nextReset ? StdExtra::optional<time_t>{ *model.nextReset } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFLeaderboardGetLeaderboardAroundUserResultWrapper(const PFLeaderboardGetLeaderboardAroundUserResultWrapper& src) :
        PFLeaderboardGetLeaderboardAroundUserResultWrapper{ src.Model() }
    {
    }

    PFLeaderboardGetLeaderboardAroundUserResultWrapper(PFLeaderboardGetLeaderboardAroundUserResultWrapper&& src) :
        PFLeaderboardGetLeaderboardAroundUserResultWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardGetLeaderboardAroundUserResultWrapper& operator=(PFLeaderboardGetLeaderboardAroundUserResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardGetLeaderboardAroundUserResultWrapper() = default;

    friend void swap(PFLeaderboardGetLeaderboardAroundUserResultWrapper& lhs, PFLeaderboardGetLeaderboardAroundUserResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_leaderboard, rhs.m_leaderboard);
        swap(lhs.m_nextReset, rhs.m_nextReset);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLeaderboard(ModelVector<PFLeaderboardPlayerLeaderboardEntryWrapper<Alloc>, Alloc> value)
    {
        m_leaderboard = std::move(value);
        this->m_model.leaderboard =  m_leaderboard.empty() ? nullptr : m_leaderboard.data();
        this->m_model.leaderboardCount =  static_cast<uint32_t>(m_leaderboard.size());
    }

    void SetNextReset(StdExtra::optional<time_t> value)
    {
        m_nextReset = std::move(value);
        this->m_model.nextReset = m_nextReset ? m_nextReset.operator->() : nullptr;
    }

    void SetVersion(int32_t value)
    {
        this->m_model.version = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.leaderboard = m_leaderboard.empty() ? nullptr : m_leaderboard.data();
        this->m_model.nextReset = m_nextReset ? m_nextReset.operator->() : nullptr;
    }

    ModelVector<PFLeaderboardPlayerLeaderboardEntryWrapper<Alloc>, Alloc> m_leaderboard;
    StdExtra::optional<time_t> m_nextReset;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardServerGetPlayerStatisticsRequestWrapper : public ModelWrapper<PFLeaderboardServerGetPlayerStatisticsRequest, Alloc>
{
public:
    using ModelType = typename PFLeaderboardServerGetPlayerStatisticsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardServerGetPlayerStatisticsRequestWrapper() = default;

    PFLeaderboardServerGetPlayerStatisticsRequestWrapper(const PFLeaderboardServerGetPlayerStatisticsRequest& model) :
        ModelWrapper<PFLeaderboardServerGetPlayerStatisticsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_statisticNames{ model.statisticNames, model.statisticNames + model.statisticNamesCount },
        m_statisticNameVersions{ model.statisticNameVersions, model.statisticNameVersions + model.statisticNameVersionsCount }
    {
        SetModelPointers();
    }

    PFLeaderboardServerGetPlayerStatisticsRequestWrapper(const PFLeaderboardServerGetPlayerStatisticsRequestWrapper& src) :
        PFLeaderboardServerGetPlayerStatisticsRequestWrapper{ src.Model() }
    {
    }

    PFLeaderboardServerGetPlayerStatisticsRequestWrapper(PFLeaderboardServerGetPlayerStatisticsRequestWrapper&& src) :
        PFLeaderboardServerGetPlayerStatisticsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardServerGetPlayerStatisticsRequestWrapper& operator=(PFLeaderboardServerGetPlayerStatisticsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardServerGetPlayerStatisticsRequestWrapper() = default;

    friend void swap(PFLeaderboardServerGetPlayerStatisticsRequestWrapper& lhs, PFLeaderboardServerGetPlayerStatisticsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_statisticNames, rhs.m_statisticNames);
        swap(lhs.m_statisticNameVersions, rhs.m_statisticNameVersions);
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

    void SetStatisticNames(CStringVector<Alloc> value)
    {
        m_statisticNames = std::move(value);
        this->m_model.statisticNames =  m_statisticNames.empty() ? nullptr : m_statisticNames.data();
        this->m_model.statisticNamesCount =  static_cast<uint32_t>(m_statisticNames.size());
    }

    void SetStatisticNameVersions(ModelVector<PFLeaderboardStatisticNameVersionWrapper<Alloc>, Alloc> value)
    {
        m_statisticNameVersions = std::move(value);
        this->m_model.statisticNameVersions =  m_statisticNameVersions.empty() ? nullptr : m_statisticNameVersions.data();
        this->m_model.statisticNameVersionsCount =  static_cast<uint32_t>(m_statisticNameVersions.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.statisticNames = m_statisticNames.empty() ? nullptr : m_statisticNames.data();
        this->m_model.statisticNameVersions = m_statisticNameVersions.empty() ? nullptr : m_statisticNameVersions.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_playFabId;
    CStringVector<Alloc> m_statisticNames;
    ModelVector<PFLeaderboardStatisticNameVersionWrapper<Alloc>, Alloc> m_statisticNameVersions;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardServerGetPlayerStatisticsResultWrapper : public ModelWrapper<PFLeaderboardServerGetPlayerStatisticsResult, Alloc>
{
public:
    using ModelType = typename PFLeaderboardServerGetPlayerStatisticsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardServerGetPlayerStatisticsResultWrapper() = default;

    PFLeaderboardServerGetPlayerStatisticsResultWrapper(const PFLeaderboardServerGetPlayerStatisticsResult& model) :
        ModelWrapper<PFLeaderboardServerGetPlayerStatisticsResult, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) },
        m_statistics{ model.statistics, model.statistics + model.statisticsCount }
    {
        SetModelPointers();
    }

    PFLeaderboardServerGetPlayerStatisticsResultWrapper(const PFLeaderboardServerGetPlayerStatisticsResultWrapper& src) :
        PFLeaderboardServerGetPlayerStatisticsResultWrapper{ src.Model() }
    {
    }

    PFLeaderboardServerGetPlayerStatisticsResultWrapper(PFLeaderboardServerGetPlayerStatisticsResultWrapper&& src) :
        PFLeaderboardServerGetPlayerStatisticsResultWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardServerGetPlayerStatisticsResultWrapper& operator=(PFLeaderboardServerGetPlayerStatisticsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardServerGetPlayerStatisticsResultWrapper() = default;

    friend void swap(PFLeaderboardServerGetPlayerStatisticsResultWrapper& lhs, PFLeaderboardServerGetPlayerStatisticsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_statistics, rhs.m_statistics);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetStatistics(ModelVector<PFStatisticValueWrapper<Alloc>, Alloc> value)
    {
        m_statistics = std::move(value);
        this->m_model.statistics =  m_statistics.empty() ? nullptr : m_statistics.data();
        this->m_model.statisticsCount =  static_cast<uint32_t>(m_statistics.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.statistics = m_statistics.empty() ? nullptr : m_statistics.data();
    }

    String m_playFabId;
    ModelVector<PFStatisticValueWrapper<Alloc>, Alloc> m_statistics;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper : public ModelWrapper<PFLeaderboardServerUpdatePlayerStatisticsRequest, Alloc>
{
public:
    using ModelType = typename PFLeaderboardServerUpdatePlayerStatisticsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper() = default;

    PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper(const PFLeaderboardServerUpdatePlayerStatisticsRequest& model) :
        ModelWrapper<PFLeaderboardServerUpdatePlayerStatisticsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceUpdate{ model.forceUpdate ? StdExtra::optional<bool>{ *model.forceUpdate } : StdExtra::nullopt },
        m_playFabId{ SafeString(model.playFabId) },
        m_statistics{ model.statistics, model.statistics + model.statisticsCount }
    {
        SetModelPointers();
    }

    PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper(const PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper& src) :
        PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper{ src.Model() }
    {
    }

    PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper(PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper&& src) :
        PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper& operator=(PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper() = default;

    friend void swap(PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper& lhs, PFLeaderboardServerUpdatePlayerStatisticsRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_forceUpdate, rhs.m_forceUpdate);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_statistics, rhs.m_statistics);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetCustomTags(StringDictionaryEntryVector<Alloc> value)
    {
        m_customTags = std::move(value);
        this->m_model.customTags =  m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.customTagsCount =  static_cast<uint32_t>(m_customTags.size());
    }

    void SetForceUpdate(StdExtra::optional<bool> value)
    {
        m_forceUpdate = std::move(value);
        this->m_model.forceUpdate = m_forceUpdate ? m_forceUpdate.operator->() : nullptr;
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    void SetStatistics(ModelVector<PFLeaderboardStatisticUpdateWrapper<Alloc>, Alloc> value)
    {
        m_statistics = std::move(value);
        this->m_model.statistics =  m_statistics.empty() ? nullptr : m_statistics.data();
        this->m_model.statisticsCount =  static_cast<uint32_t>(m_statistics.size());
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.forceUpdate = m_forceUpdate ? m_forceUpdate.operator->() : nullptr;
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.statistics = m_statistics.empty() ? nullptr : m_statistics.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StdExtra::optional<bool> m_forceUpdate;
    String m_playFabId;
    ModelVector<PFLeaderboardStatisticUpdateWrapper<Alloc>, Alloc> m_statistics;
};

} // namespace Wrappers
} // namespace PlayFab
