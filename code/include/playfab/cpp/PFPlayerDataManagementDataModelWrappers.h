// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#if !defined(__cplusplus)
#error C++11 required
#endif

#pragma once

#include "PFModelWrapperHelpers.h"
#include "PFSharedDataModelWrappers.h"
#include <playfab/PFPlayerDataManagementDataModels.h>

namespace PlayFab
{
namespace Wrappers
{

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper : public ModelWrapper<PFPlayerDataManagementCreatePlayerStatisticDefinitionRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementCreatePlayerStatisticDefinitionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper() = default;

    PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper(const PFPlayerDataManagementCreatePlayerStatisticDefinitionRequest& model) :
        ModelWrapper<PFPlayerDataManagementCreatePlayerStatisticDefinitionRequest, Alloc>{ model },
        m_aggregationMethod{ model.aggregationMethod ? StdExtra::optional<PFPlayerDataManagementStatisticAggregationMethod>{ *model.aggregationMethod } : StdExtra::nullopt },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_statisticName{ SafeString(model.statisticName) },
        m_versionChangeInterval{ model.versionChangeInterval ? StdExtra::optional<PFPlayerDataManagementStatisticResetIntervalOption>{ *model.versionChangeInterval } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper(const PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper& src) :
        PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper(PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper&& src) :
        PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper& operator=(PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper& lhs, PFPlayerDataManagementCreatePlayerStatisticDefinitionRequestWrapper& rhs)
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

    void SetAggregationMethod(StdExtra::optional<PFPlayerDataManagementStatisticAggregationMethod> value)
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

    void SetVersionChangeInterval(StdExtra::optional<PFPlayerDataManagementStatisticResetIntervalOption> value)
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

    StdExtra::optional<PFPlayerDataManagementStatisticAggregationMethod> m_aggregationMethod;
    StringDictionaryEntryVector<Alloc> m_customTags;
    String m_statisticName;
    StdExtra::optional<PFPlayerDataManagementStatisticResetIntervalOption> m_versionChangeInterval;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementPlayerStatisticDefinitionWrapper : public ModelWrapper<PFPlayerDataManagementPlayerStatisticDefinition, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementPlayerStatisticDefinition;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementPlayerStatisticDefinitionWrapper() = default;

    PFPlayerDataManagementPlayerStatisticDefinitionWrapper(const PFPlayerDataManagementPlayerStatisticDefinition& model) :
        ModelWrapper<PFPlayerDataManagementPlayerStatisticDefinition, Alloc>{ model },
        m_aggregationMethod{ model.aggregationMethod ? StdExtra::optional<PFPlayerDataManagementStatisticAggregationMethod>{ *model.aggregationMethod } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) },
        m_versionChangeInterval{ model.versionChangeInterval ? StdExtra::optional<PFPlayerDataManagementStatisticResetIntervalOption>{ *model.versionChangeInterval } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementPlayerStatisticDefinitionWrapper(const PFPlayerDataManagementPlayerStatisticDefinitionWrapper& src) :
        PFPlayerDataManagementPlayerStatisticDefinitionWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementPlayerStatisticDefinitionWrapper(PFPlayerDataManagementPlayerStatisticDefinitionWrapper&& src) :
        PFPlayerDataManagementPlayerStatisticDefinitionWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementPlayerStatisticDefinitionWrapper& operator=(PFPlayerDataManagementPlayerStatisticDefinitionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementPlayerStatisticDefinitionWrapper() = default;

    friend void swap(PFPlayerDataManagementPlayerStatisticDefinitionWrapper& lhs, PFPlayerDataManagementPlayerStatisticDefinitionWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_aggregationMethod, rhs.m_aggregationMethod);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        swap(lhs.m_versionChangeInterval, rhs.m_versionChangeInterval);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAggregationMethod(StdExtra::optional<PFPlayerDataManagementStatisticAggregationMethod> value)
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

    void SetVersionChangeInterval(StdExtra::optional<PFPlayerDataManagementStatisticResetIntervalOption> value)
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

    StdExtra::optional<PFPlayerDataManagementStatisticAggregationMethod> m_aggregationMethod;
    String m_statisticName;
    StdExtra::optional<PFPlayerDataManagementStatisticResetIntervalOption> m_versionChangeInterval;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementCreatePlayerStatisticDefinitionResultWrapper : public ModelWrapper<PFPlayerDataManagementCreatePlayerStatisticDefinitionResult, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementCreatePlayerStatisticDefinitionResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementCreatePlayerStatisticDefinitionResultWrapper() = default;

    PFPlayerDataManagementCreatePlayerStatisticDefinitionResultWrapper(const PFPlayerDataManagementCreatePlayerStatisticDefinitionResult& model) :
        ModelWrapper<PFPlayerDataManagementCreatePlayerStatisticDefinitionResult, Alloc>{ model },
        m_statistic{ model.statistic ? StdExtra::optional<PFPlayerDataManagementPlayerStatisticDefinitionWrapper<Alloc>>{ *model.statistic } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementCreatePlayerStatisticDefinitionResultWrapper(const PFPlayerDataManagementCreatePlayerStatisticDefinitionResultWrapper& src) :
        PFPlayerDataManagementCreatePlayerStatisticDefinitionResultWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementCreatePlayerStatisticDefinitionResultWrapper(PFPlayerDataManagementCreatePlayerStatisticDefinitionResultWrapper&& src) :
        PFPlayerDataManagementCreatePlayerStatisticDefinitionResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementCreatePlayerStatisticDefinitionResultWrapper& operator=(PFPlayerDataManagementCreatePlayerStatisticDefinitionResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementCreatePlayerStatisticDefinitionResultWrapper() = default;

    friend void swap(PFPlayerDataManagementCreatePlayerStatisticDefinitionResultWrapper& lhs, PFPlayerDataManagementCreatePlayerStatisticDefinitionResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_statistic, rhs.m_statistic);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStatistic(StdExtra::optional<PFPlayerDataManagementPlayerStatisticDefinitionWrapper<Alloc>> value)
    {
        m_statistic = std::move(value);
        this->m_model.statistic = m_statistic ? &m_statistic->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.statistic = m_statistic ?  &m_statistic->Model() : nullptr;
    }

    StdExtra::optional<PFPlayerDataManagementPlayerStatisticDefinitionWrapper<Alloc>> m_statistic;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementGetDataReportRequestWrapper : public ModelWrapper<PFPlayerDataManagementGetDataReportRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementGetDataReportRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementGetDataReportRequestWrapper() = default;

    PFPlayerDataManagementGetDataReportRequestWrapper(const PFPlayerDataManagementGetDataReportRequest& model) :
        ModelWrapper<PFPlayerDataManagementGetDataReportRequest, Alloc>{ model },
        m_reportName{ SafeString(model.reportName) }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementGetDataReportRequestWrapper(const PFPlayerDataManagementGetDataReportRequestWrapper& src) :
        PFPlayerDataManagementGetDataReportRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementGetDataReportRequestWrapper(PFPlayerDataManagementGetDataReportRequestWrapper&& src) :
        PFPlayerDataManagementGetDataReportRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementGetDataReportRequestWrapper& operator=(PFPlayerDataManagementGetDataReportRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementGetDataReportRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementGetDataReportRequestWrapper& lhs, PFPlayerDataManagementGetDataReportRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_reportName, rhs.m_reportName);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDay(int32_t value)
    {
        this->m_model.day = value;
    }

    void SetMonth(int32_t value)
    {
        this->m_model.month = value;
    }

    void SetReportName(String value)
    {
        m_reportName = std::move(value);
        this->m_model.reportName =  m_reportName.empty() ? nullptr : m_reportName.data();
    }

    void SetYear(int32_t value)
    {
        this->m_model.year = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.reportName = m_reportName.empty() ? nullptr : m_reportName.data();
    }

    String m_reportName;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementGetDataReportResultWrapper : public ModelWrapper<PFPlayerDataManagementGetDataReportResult, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementGetDataReportResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementGetDataReportResultWrapper() = default;

    PFPlayerDataManagementGetDataReportResultWrapper(const PFPlayerDataManagementGetDataReportResult& model) :
        ModelWrapper<PFPlayerDataManagementGetDataReportResult, Alloc>{ model },
        m_downloadUrl{ SafeString(model.downloadUrl) }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementGetDataReportResultWrapper(const PFPlayerDataManagementGetDataReportResultWrapper& src) :
        PFPlayerDataManagementGetDataReportResultWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementGetDataReportResultWrapper(PFPlayerDataManagementGetDataReportResultWrapper&& src) :
        PFPlayerDataManagementGetDataReportResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementGetDataReportResultWrapper& operator=(PFPlayerDataManagementGetDataReportResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementGetDataReportResultWrapper() = default;

    friend void swap(PFPlayerDataManagementGetDataReportResultWrapper& lhs, PFPlayerDataManagementGetDataReportResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_downloadUrl, rhs.m_downloadUrl);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetDownloadUrl(String value)
    {
        m_downloadUrl = std::move(value);
        this->m_model.downloadUrl =  m_downloadUrl.empty() ? nullptr : m_downloadUrl.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.downloadUrl = m_downloadUrl.empty() ? nullptr : m_downloadUrl.data();
    }

    String m_downloadUrl;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementGetPlayerStatisticDefinitionsResultWrapper : public ModelWrapper<PFPlayerDataManagementGetPlayerStatisticDefinitionsResult, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementGetPlayerStatisticDefinitionsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementGetPlayerStatisticDefinitionsResultWrapper() = default;

    PFPlayerDataManagementGetPlayerStatisticDefinitionsResultWrapper(const PFPlayerDataManagementGetPlayerStatisticDefinitionsResult& model) :
        ModelWrapper<PFPlayerDataManagementGetPlayerStatisticDefinitionsResult, Alloc>{ model },
        m_statistics{ model.statistics, model.statistics + model.statisticsCount }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementGetPlayerStatisticDefinitionsResultWrapper(const PFPlayerDataManagementGetPlayerStatisticDefinitionsResultWrapper& src) :
        PFPlayerDataManagementGetPlayerStatisticDefinitionsResultWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementGetPlayerStatisticDefinitionsResultWrapper(PFPlayerDataManagementGetPlayerStatisticDefinitionsResultWrapper&& src) :
        PFPlayerDataManagementGetPlayerStatisticDefinitionsResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementGetPlayerStatisticDefinitionsResultWrapper& operator=(PFPlayerDataManagementGetPlayerStatisticDefinitionsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementGetPlayerStatisticDefinitionsResultWrapper() = default;

    friend void swap(PFPlayerDataManagementGetPlayerStatisticDefinitionsResultWrapper& lhs, PFPlayerDataManagementGetPlayerStatisticDefinitionsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_statistics, rhs.m_statistics);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStatistics(ModelVector<PFPlayerDataManagementPlayerStatisticDefinitionWrapper<Alloc>, Alloc> value)
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

    ModelVector<PFPlayerDataManagementPlayerStatisticDefinitionWrapper<Alloc>, Alloc> m_statistics;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper : public ModelWrapper<PFPlayerDataManagementGetPlayerStatisticVersionsRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementGetPlayerStatisticVersionsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper() = default;

    PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper(const PFPlayerDataManagementGetPlayerStatisticVersionsRequest& model) :
        ModelWrapper<PFPlayerDataManagementGetPlayerStatisticVersionsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_statisticName{ SafeString(model.statisticName) }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper(const PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper& src) :
        PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper(PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper&& src) :
        PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper& operator=(PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper& lhs, PFPlayerDataManagementGetPlayerStatisticVersionsRequestWrapper& rhs)
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
class PFPlayerDataManagementPlayerStatisticVersionWrapper : public ModelWrapper<PFPlayerDataManagementPlayerStatisticVersion, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementPlayerStatisticVersion;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementPlayerStatisticVersionWrapper() = default;

    PFPlayerDataManagementPlayerStatisticVersionWrapper(const PFPlayerDataManagementPlayerStatisticVersion& model) :
        ModelWrapper<PFPlayerDataManagementPlayerStatisticVersion, Alloc>{ model },
        m_archiveDownloadUrl{ SafeString(model.archiveDownloadUrl) },
        m_deactivationTime{ model.deactivationTime ? StdExtra::optional<time_t>{ *model.deactivationTime } : StdExtra::nullopt },
        m_scheduledActivationTime{ model.scheduledActivationTime ? StdExtra::optional<time_t>{ *model.scheduledActivationTime } : StdExtra::nullopt },
        m_scheduledDeactivationTime{ model.scheduledDeactivationTime ? StdExtra::optional<time_t>{ *model.scheduledDeactivationTime } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) },
        m_status{ model.status ? StdExtra::optional<PFPlayerDataManagementStatisticVersionStatus>{ *model.status } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementPlayerStatisticVersionWrapper(const PFPlayerDataManagementPlayerStatisticVersionWrapper& src) :
        PFPlayerDataManagementPlayerStatisticVersionWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementPlayerStatisticVersionWrapper(PFPlayerDataManagementPlayerStatisticVersionWrapper&& src) :
        PFPlayerDataManagementPlayerStatisticVersionWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementPlayerStatisticVersionWrapper& operator=(PFPlayerDataManagementPlayerStatisticVersionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementPlayerStatisticVersionWrapper() = default;

    friend void swap(PFPlayerDataManagementPlayerStatisticVersionWrapper& lhs, PFPlayerDataManagementPlayerStatisticVersionWrapper& rhs)
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

    void SetStatus(StdExtra::optional<PFPlayerDataManagementStatisticVersionStatus> value)
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
    StdExtra::optional<PFPlayerDataManagementStatisticVersionStatus> m_status;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementGetPlayerStatisticVersionsResultWrapper : public ModelWrapper<PFPlayerDataManagementGetPlayerStatisticVersionsResult, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementGetPlayerStatisticVersionsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementGetPlayerStatisticVersionsResultWrapper() = default;

    PFPlayerDataManagementGetPlayerStatisticVersionsResultWrapper(const PFPlayerDataManagementGetPlayerStatisticVersionsResult& model) :
        ModelWrapper<PFPlayerDataManagementGetPlayerStatisticVersionsResult, Alloc>{ model },
        m_statisticVersions{ model.statisticVersions, model.statisticVersions + model.statisticVersionsCount }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementGetPlayerStatisticVersionsResultWrapper(const PFPlayerDataManagementGetPlayerStatisticVersionsResultWrapper& src) :
        PFPlayerDataManagementGetPlayerStatisticVersionsResultWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementGetPlayerStatisticVersionsResultWrapper(PFPlayerDataManagementGetPlayerStatisticVersionsResultWrapper&& src) :
        PFPlayerDataManagementGetPlayerStatisticVersionsResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementGetPlayerStatisticVersionsResultWrapper& operator=(PFPlayerDataManagementGetPlayerStatisticVersionsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementGetPlayerStatisticVersionsResultWrapper() = default;

    friend void swap(PFPlayerDataManagementGetPlayerStatisticVersionsResultWrapper& lhs, PFPlayerDataManagementGetPlayerStatisticVersionsResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_statisticVersions, rhs.m_statisticVersions);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStatisticVersions(ModelVector<PFPlayerDataManagementPlayerStatisticVersionWrapper<Alloc>, Alloc> value)
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

    ModelVector<PFPlayerDataManagementPlayerStatisticVersionWrapper<Alloc>, Alloc> m_statisticVersions;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementGetUserDataRequestWrapper : public ModelWrapper<PFPlayerDataManagementGetUserDataRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementGetUserDataRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementGetUserDataRequestWrapper() = default;

    PFPlayerDataManagementGetUserDataRequestWrapper(const PFPlayerDataManagementGetUserDataRequest& model) :
        ModelWrapper<PFPlayerDataManagementGetUserDataRequest, Alloc>{ model },
        m_ifChangedFromDataVersion{ model.ifChangedFromDataVersion ? StdExtra::optional<uint32_t>{ *model.ifChangedFromDataVersion } : StdExtra::nullopt },
        m_keys{ model.keys, model.keys + model.keysCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementGetUserDataRequestWrapper(const PFPlayerDataManagementGetUserDataRequestWrapper& src) :
        PFPlayerDataManagementGetUserDataRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementGetUserDataRequestWrapper(PFPlayerDataManagementGetUserDataRequestWrapper&& src) :
        PFPlayerDataManagementGetUserDataRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementGetUserDataRequestWrapper& operator=(PFPlayerDataManagementGetUserDataRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementGetUserDataRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementGetUserDataRequestWrapper& lhs, PFPlayerDataManagementGetUserDataRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_ifChangedFromDataVersion, rhs.m_ifChangedFromDataVersion);
        swap(lhs.m_keys, rhs.m_keys);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetIfChangedFromDataVersion(StdExtra::optional<uint32_t> value)
    {
        m_ifChangedFromDataVersion = std::move(value);
        this->m_model.ifChangedFromDataVersion = m_ifChangedFromDataVersion ? m_ifChangedFromDataVersion.operator->() : nullptr;
    }

    void SetKeys(CStringVector<Alloc> value)
    {
        m_keys = std::move(value);
        this->m_model.keys =  m_keys.empty() ? nullptr : m_keys.data();
        this->m_model.keysCount =  static_cast<uint32_t>(m_keys.size());
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.ifChangedFromDataVersion = m_ifChangedFromDataVersion ? m_ifChangedFromDataVersion.operator->() : nullptr;
        this->m_model.keys = m_keys.empty() ? nullptr : m_keys.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StdExtra::optional<uint32_t> m_ifChangedFromDataVersion;
    CStringVector<Alloc> m_keys;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementAdminGetUserDataResultWrapper : public ModelWrapper<PFPlayerDataManagementAdminGetUserDataResult, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementAdminGetUserDataResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementAdminGetUserDataResultWrapper() = default;

    PFPlayerDataManagementAdminGetUserDataResultWrapper(const PFPlayerDataManagementAdminGetUserDataResult& model) :
        ModelWrapper<PFPlayerDataManagementAdminGetUserDataResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementAdminGetUserDataResultWrapper(const PFPlayerDataManagementAdminGetUserDataResultWrapper& src) :
        PFPlayerDataManagementAdminGetUserDataResultWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementAdminGetUserDataResultWrapper(PFPlayerDataManagementAdminGetUserDataResultWrapper&& src) :
        PFPlayerDataManagementAdminGetUserDataResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementAdminGetUserDataResultWrapper& operator=(PFPlayerDataManagementAdminGetUserDataResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementAdminGetUserDataResultWrapper() = default;

    friend void swap(PFPlayerDataManagementAdminGetUserDataResultWrapper& lhs, PFPlayerDataManagementAdminGetUserDataResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(ModelDictionaryEntryVector<PFUserDataRecordWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

    void SetDataVersion(uint32_t value)
    {
        this->m_model.dataVersion = value;
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    ModelDictionaryEntryVector<PFUserDataRecordWrapper<Alloc>, Alloc> m_data;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper : public ModelWrapper<PFPlayerDataManagementIncrementPlayerStatisticVersionRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementIncrementPlayerStatisticVersionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper() = default;

    PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper(const PFPlayerDataManagementIncrementPlayerStatisticVersionRequest& model) :
        ModelWrapper<PFPlayerDataManagementIncrementPlayerStatisticVersionRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_statisticName{ SafeString(model.statisticName) }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper(const PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper& src) :
        PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper(PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper&& src) :
        PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper& operator=(PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper& lhs, PFPlayerDataManagementIncrementPlayerStatisticVersionRequestWrapper& rhs)
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
class PFPlayerDataManagementIncrementPlayerStatisticVersionResultWrapper : public ModelWrapper<PFPlayerDataManagementIncrementPlayerStatisticVersionResult, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementIncrementPlayerStatisticVersionResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementIncrementPlayerStatisticVersionResultWrapper() = default;

    PFPlayerDataManagementIncrementPlayerStatisticVersionResultWrapper(const PFPlayerDataManagementIncrementPlayerStatisticVersionResult& model) :
        ModelWrapper<PFPlayerDataManagementIncrementPlayerStatisticVersionResult, Alloc>{ model },
        m_statisticVersion{ model.statisticVersion ? StdExtra::optional<PFPlayerDataManagementPlayerStatisticVersionWrapper<Alloc>>{ *model.statisticVersion } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementIncrementPlayerStatisticVersionResultWrapper(const PFPlayerDataManagementIncrementPlayerStatisticVersionResultWrapper& src) :
        PFPlayerDataManagementIncrementPlayerStatisticVersionResultWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementIncrementPlayerStatisticVersionResultWrapper(PFPlayerDataManagementIncrementPlayerStatisticVersionResultWrapper&& src) :
        PFPlayerDataManagementIncrementPlayerStatisticVersionResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementIncrementPlayerStatisticVersionResultWrapper& operator=(PFPlayerDataManagementIncrementPlayerStatisticVersionResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementIncrementPlayerStatisticVersionResultWrapper() = default;

    friend void swap(PFPlayerDataManagementIncrementPlayerStatisticVersionResultWrapper& lhs, PFPlayerDataManagementIncrementPlayerStatisticVersionResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_statisticVersion, rhs.m_statisticVersion);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStatisticVersion(StdExtra::optional<PFPlayerDataManagementPlayerStatisticVersionWrapper<Alloc>> value)
    {
        m_statisticVersion = std::move(value);
        this->m_model.statisticVersion = m_statisticVersion ? &m_statisticVersion->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.statisticVersion = m_statisticVersion ?  &m_statisticVersion->Model() : nullptr;
    }

    StdExtra::optional<PFPlayerDataManagementPlayerStatisticVersionWrapper<Alloc>> m_statisticVersion;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementRefundPurchaseRequestWrapper : public ModelWrapper<PFPlayerDataManagementRefundPurchaseRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementRefundPurchaseRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementRefundPurchaseRequestWrapper() = default;

    PFPlayerDataManagementRefundPurchaseRequestWrapper(const PFPlayerDataManagementRefundPurchaseRequest& model) :
        ModelWrapper<PFPlayerDataManagementRefundPurchaseRequest, Alloc>{ model },
        m_orderId{ SafeString(model.orderId) },
        m_playFabId{ SafeString(model.playFabId) },
        m_reason{ SafeString(model.reason) }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementRefundPurchaseRequestWrapper(const PFPlayerDataManagementRefundPurchaseRequestWrapper& src) :
        PFPlayerDataManagementRefundPurchaseRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementRefundPurchaseRequestWrapper(PFPlayerDataManagementRefundPurchaseRequestWrapper&& src) :
        PFPlayerDataManagementRefundPurchaseRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementRefundPurchaseRequestWrapper& operator=(PFPlayerDataManagementRefundPurchaseRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementRefundPurchaseRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementRefundPurchaseRequestWrapper& lhs, PFPlayerDataManagementRefundPurchaseRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_orderId, rhs.m_orderId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_reason, rhs.m_reason);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetOrderId(String value)
    {
        m_orderId = std::move(value);
        this->m_model.orderId =  m_orderId.empty() ? nullptr : m_orderId.data();
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
        this->m_model.orderId = m_orderId.empty() ? nullptr : m_orderId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.reason = m_reason.empty() ? nullptr : m_reason.data();
    }

    String m_orderId;
    String m_playFabId;
    String m_reason;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementRefundPurchaseResponseWrapper : public ModelWrapper<PFPlayerDataManagementRefundPurchaseResponse, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementRefundPurchaseResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementRefundPurchaseResponseWrapper() = default;

    PFPlayerDataManagementRefundPurchaseResponseWrapper(const PFPlayerDataManagementRefundPurchaseResponse& model) :
        ModelWrapper<PFPlayerDataManagementRefundPurchaseResponse, Alloc>{ model },
        m_purchaseStatus{ SafeString(model.purchaseStatus) }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementRefundPurchaseResponseWrapper(const PFPlayerDataManagementRefundPurchaseResponseWrapper& src) :
        PFPlayerDataManagementRefundPurchaseResponseWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementRefundPurchaseResponseWrapper(PFPlayerDataManagementRefundPurchaseResponseWrapper&& src) :
        PFPlayerDataManagementRefundPurchaseResponseWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementRefundPurchaseResponseWrapper& operator=(PFPlayerDataManagementRefundPurchaseResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementRefundPurchaseResponseWrapper() = default;

    friend void swap(PFPlayerDataManagementRefundPurchaseResponseWrapper& lhs, PFPlayerDataManagementRefundPurchaseResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_purchaseStatus, rhs.m_purchaseStatus);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPurchaseStatus(String value)
    {
        m_purchaseStatus = std::move(value);
        this->m_model.purchaseStatus =  m_purchaseStatus.empty() ? nullptr : m_purchaseStatus.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.purchaseStatus = m_purchaseStatus.empty() ? nullptr : m_purchaseStatus.data();
    }

    String m_purchaseStatus;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementResetUserStatisticsRequestWrapper : public ModelWrapper<PFPlayerDataManagementResetUserStatisticsRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementResetUserStatisticsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementResetUserStatisticsRequestWrapper() = default;

    PFPlayerDataManagementResetUserStatisticsRequestWrapper(const PFPlayerDataManagementResetUserStatisticsRequest& model) :
        ModelWrapper<PFPlayerDataManagementResetUserStatisticsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementResetUserStatisticsRequestWrapper(const PFPlayerDataManagementResetUserStatisticsRequestWrapper& src) :
        PFPlayerDataManagementResetUserStatisticsRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementResetUserStatisticsRequestWrapper(PFPlayerDataManagementResetUserStatisticsRequestWrapper&& src) :
        PFPlayerDataManagementResetUserStatisticsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementResetUserStatisticsRequestWrapper& operator=(PFPlayerDataManagementResetUserStatisticsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementResetUserStatisticsRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementResetUserStatisticsRequestWrapper& lhs, PFPlayerDataManagementResetUserStatisticsRequestWrapper& rhs)
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
class PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper : public ModelWrapper<PFPlayerDataManagementResolvePurchaseDisputeRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementResolvePurchaseDisputeRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper() = default;

    PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper(const PFPlayerDataManagementResolvePurchaseDisputeRequest& model) :
        ModelWrapper<PFPlayerDataManagementResolvePurchaseDisputeRequest, Alloc>{ model },
        m_orderId{ SafeString(model.orderId) },
        m_playFabId{ SafeString(model.playFabId) },
        m_reason{ SafeString(model.reason) }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper(const PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper& src) :
        PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper(PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper&& src) :
        PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper& operator=(PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper& lhs, PFPlayerDataManagementResolvePurchaseDisputeRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_orderId, rhs.m_orderId);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        swap(lhs.m_reason, rhs.m_reason);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetOrderId(String value)
    {
        m_orderId = std::move(value);
        this->m_model.orderId =  m_orderId.empty() ? nullptr : m_orderId.data();
    }

    void SetOutcome(PFPlayerDataManagementResolutionOutcome value)
    {
        this->m_model.outcome = value;
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
        this->m_model.orderId = m_orderId.empty() ? nullptr : m_orderId.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
        this->m_model.reason = m_reason.empty() ? nullptr : m_reason.data();
    }

    String m_orderId;
    String m_playFabId;
    String m_reason;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementResolvePurchaseDisputeResponseWrapper : public ModelWrapper<PFPlayerDataManagementResolvePurchaseDisputeResponse, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementResolvePurchaseDisputeResponse;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementResolvePurchaseDisputeResponseWrapper() = default;

    PFPlayerDataManagementResolvePurchaseDisputeResponseWrapper(const PFPlayerDataManagementResolvePurchaseDisputeResponse& model) :
        ModelWrapper<PFPlayerDataManagementResolvePurchaseDisputeResponse, Alloc>{ model },
        m_purchaseStatus{ SafeString(model.purchaseStatus) }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementResolvePurchaseDisputeResponseWrapper(const PFPlayerDataManagementResolvePurchaseDisputeResponseWrapper& src) :
        PFPlayerDataManagementResolvePurchaseDisputeResponseWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementResolvePurchaseDisputeResponseWrapper(PFPlayerDataManagementResolvePurchaseDisputeResponseWrapper&& src) :
        PFPlayerDataManagementResolvePurchaseDisputeResponseWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementResolvePurchaseDisputeResponseWrapper& operator=(PFPlayerDataManagementResolvePurchaseDisputeResponseWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementResolvePurchaseDisputeResponseWrapper() = default;

    friend void swap(PFPlayerDataManagementResolvePurchaseDisputeResponseWrapper& lhs, PFPlayerDataManagementResolvePurchaseDisputeResponseWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_purchaseStatus, rhs.m_purchaseStatus);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetPurchaseStatus(String value)
    {
        m_purchaseStatus = std::move(value);
        this->m_model.purchaseStatus =  m_purchaseStatus.empty() ? nullptr : m_purchaseStatus.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.purchaseStatus = m_purchaseStatus.empty() ? nullptr : m_purchaseStatus.data();
    }

    String m_purchaseStatus;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper : public ModelWrapper<PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper() = default;

    PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper(const PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequest& model) :
        ModelWrapper<PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequest, Alloc>{ model },
        m_aggregationMethod{ model.aggregationMethod ? StdExtra::optional<PFPlayerDataManagementStatisticAggregationMethod>{ *model.aggregationMethod } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) },
        m_versionChangeInterval{ model.versionChangeInterval ? StdExtra::optional<PFPlayerDataManagementStatisticResetIntervalOption>{ *model.versionChangeInterval } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper(const PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper& src) :
        PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper(PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper&& src) :
        PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper& operator=(PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper& lhs, PFPlayerDataManagementUpdatePlayerStatisticDefinitionRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_aggregationMethod, rhs.m_aggregationMethod);
        swap(lhs.m_statisticName, rhs.m_statisticName);
        swap(lhs.m_versionChangeInterval, rhs.m_versionChangeInterval);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetAggregationMethod(StdExtra::optional<PFPlayerDataManagementStatisticAggregationMethod> value)
    {
        m_aggregationMethod = std::move(value);
        this->m_model.aggregationMethod = m_aggregationMethod ? m_aggregationMethod.operator->() : nullptr;
    }

    void SetStatisticName(String value)
    {
        m_statisticName = std::move(value);
        this->m_model.statisticName =  m_statisticName.empty() ? nullptr : m_statisticName.data();
    }

    void SetVersionChangeInterval(StdExtra::optional<PFPlayerDataManagementStatisticResetIntervalOption> value)
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

    StdExtra::optional<PFPlayerDataManagementStatisticAggregationMethod> m_aggregationMethod;
    String m_statisticName;
    StdExtra::optional<PFPlayerDataManagementStatisticResetIntervalOption> m_versionChangeInterval;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementUpdatePlayerStatisticDefinitionResultWrapper : public ModelWrapper<PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementUpdatePlayerStatisticDefinitionResultWrapper() = default;

    PFPlayerDataManagementUpdatePlayerStatisticDefinitionResultWrapper(const PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult& model) :
        ModelWrapper<PFPlayerDataManagementUpdatePlayerStatisticDefinitionResult, Alloc>{ model },
        m_statistic{ model.statistic ? StdExtra::optional<PFPlayerDataManagementPlayerStatisticDefinitionWrapper<Alloc>>{ *model.statistic } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementUpdatePlayerStatisticDefinitionResultWrapper(const PFPlayerDataManagementUpdatePlayerStatisticDefinitionResultWrapper& src) :
        PFPlayerDataManagementUpdatePlayerStatisticDefinitionResultWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementUpdatePlayerStatisticDefinitionResultWrapper(PFPlayerDataManagementUpdatePlayerStatisticDefinitionResultWrapper&& src) :
        PFPlayerDataManagementUpdatePlayerStatisticDefinitionResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementUpdatePlayerStatisticDefinitionResultWrapper& operator=(PFPlayerDataManagementUpdatePlayerStatisticDefinitionResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementUpdatePlayerStatisticDefinitionResultWrapper() = default;

    friend void swap(PFPlayerDataManagementUpdatePlayerStatisticDefinitionResultWrapper& lhs, PFPlayerDataManagementUpdatePlayerStatisticDefinitionResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_statistic, rhs.m_statistic);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetStatistic(StdExtra::optional<PFPlayerDataManagementPlayerStatisticDefinitionWrapper<Alloc>> value)
    {
        m_statistic = std::move(value);
        this->m_model.statistic = m_statistic ? &m_statistic->Model() : nullptr;
    }

private:
    void SetModelPointers()
    {
        this->m_model.statistic = m_statistic ?  &m_statistic->Model() : nullptr;
    }

    StdExtra::optional<PFPlayerDataManagementPlayerStatisticDefinitionWrapper<Alloc>> m_statistic;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementAdminUpdateUserDataRequestWrapper : public ModelWrapper<PFPlayerDataManagementAdminUpdateUserDataRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementAdminUpdateUserDataRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementAdminUpdateUserDataRequestWrapper() = default;

    PFPlayerDataManagementAdminUpdateUserDataRequestWrapper(const PFPlayerDataManagementAdminUpdateUserDataRequest& model) :
        ModelWrapper<PFPlayerDataManagementAdminUpdateUserDataRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_data{ model.data, model.data + model.dataCount },
        m_keysToRemove{ model.keysToRemove, model.keysToRemove + model.keysToRemoveCount },
        m_permission{ model.permission ? StdExtra::optional<PFUserDataPermission>{ *model.permission } : StdExtra::nullopt },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementAdminUpdateUserDataRequestWrapper(const PFPlayerDataManagementAdminUpdateUserDataRequestWrapper& src) :
        PFPlayerDataManagementAdminUpdateUserDataRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementAdminUpdateUserDataRequestWrapper(PFPlayerDataManagementAdminUpdateUserDataRequestWrapper&& src) :
        PFPlayerDataManagementAdminUpdateUserDataRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementAdminUpdateUserDataRequestWrapper& operator=(PFPlayerDataManagementAdminUpdateUserDataRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementAdminUpdateUserDataRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementAdminUpdateUserDataRequestWrapper& lhs, PFPlayerDataManagementAdminUpdateUserDataRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_data, rhs.m_data);
        swap(lhs.m_keysToRemove, rhs.m_keysToRemove);
        swap(lhs.m_permission, rhs.m_permission);
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

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
        this->m_model.keysToRemove = m_keysToRemove.empty() ? nullptr : m_keysToRemove.data();
        this->m_model.permission = m_permission ? m_permission.operator->() : nullptr;
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StringDictionaryEntryVector<Alloc> m_data;
    CStringVector<Alloc> m_keysToRemove;
    StdExtra::optional<PFUserDataPermission> m_permission;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementUpdateUserDataResultWrapper : public ModelWrapper<PFPlayerDataManagementUpdateUserDataResult, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementUpdateUserDataResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    using ModelWrapper<PFPlayerDataManagementUpdateUserDataResult, Alloc>::ModelWrapper;

    void SetDataVersion(uint32_t value)
    {
        this->m_model.dataVersion = value;
    }

private:
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementUpdateUserInternalDataRequestWrapper : public ModelWrapper<PFPlayerDataManagementUpdateUserInternalDataRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementUpdateUserInternalDataRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementUpdateUserInternalDataRequestWrapper() = default;

    PFPlayerDataManagementUpdateUserInternalDataRequestWrapper(const PFPlayerDataManagementUpdateUserInternalDataRequest& model) :
        ModelWrapper<PFPlayerDataManagementUpdateUserInternalDataRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_data{ model.data, model.data + model.dataCount },
        m_keysToRemove{ model.keysToRemove, model.keysToRemove + model.keysToRemoveCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementUpdateUserInternalDataRequestWrapper(const PFPlayerDataManagementUpdateUserInternalDataRequestWrapper& src) :
        PFPlayerDataManagementUpdateUserInternalDataRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementUpdateUserInternalDataRequestWrapper(PFPlayerDataManagementUpdateUserInternalDataRequestWrapper&& src) :
        PFPlayerDataManagementUpdateUserInternalDataRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementUpdateUserInternalDataRequestWrapper& operator=(PFPlayerDataManagementUpdateUserInternalDataRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementUpdateUserInternalDataRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementUpdateUserInternalDataRequestWrapper& lhs, PFPlayerDataManagementUpdateUserInternalDataRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_data, rhs.m_data);
        swap(lhs.m_keysToRemove, rhs.m_keysToRemove);
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

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
        this->m_model.keysToRemove = m_keysToRemove.empty() ? nullptr : m_keysToRemove.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StringDictionaryEntryVector<Alloc> m_data;
    CStringVector<Alloc> m_keysToRemove;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper : public ModelWrapper<PFPlayerDataManagementClientGetFriendLeaderboardRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementClientGetFriendLeaderboardRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper() = default;

    PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper(const PFPlayerDataManagementClientGetFriendLeaderboardRequest& model) :
        ModelWrapper<PFPlayerDataManagementClientGetFriendLeaderboardRequest, Alloc>{ model },
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

    PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper(const PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper& src) :
        PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper(PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper&& src) :
        PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper& operator=(PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper& lhs, PFPlayerDataManagementClientGetFriendLeaderboardRequestWrapper& rhs)
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
class PFPlayerDataManagementPlayerLeaderboardEntryWrapper : public ModelWrapper<PFPlayerDataManagementPlayerLeaderboardEntry, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementPlayerLeaderboardEntry;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementPlayerLeaderboardEntryWrapper() = default;

    PFPlayerDataManagementPlayerLeaderboardEntryWrapper(const PFPlayerDataManagementPlayerLeaderboardEntry& model) :
        ModelWrapper<PFPlayerDataManagementPlayerLeaderboardEntry, Alloc>{ model },
        m_displayName{ SafeString(model.displayName) },
        m_playFabId{ SafeString(model.playFabId) },
        m_profile{ model.profile ? StdExtra::optional<PFPlayerProfileModelWrapper<Alloc>>{ *model.profile } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementPlayerLeaderboardEntryWrapper(const PFPlayerDataManagementPlayerLeaderboardEntryWrapper& src) :
        PFPlayerDataManagementPlayerLeaderboardEntryWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementPlayerLeaderboardEntryWrapper(PFPlayerDataManagementPlayerLeaderboardEntryWrapper&& src) :
        PFPlayerDataManagementPlayerLeaderboardEntryWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementPlayerLeaderboardEntryWrapper& operator=(PFPlayerDataManagementPlayerLeaderboardEntryWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementPlayerLeaderboardEntryWrapper() = default;

    friend void swap(PFPlayerDataManagementPlayerLeaderboardEntryWrapper& lhs, PFPlayerDataManagementPlayerLeaderboardEntryWrapper& rhs)
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
class PFPlayerDataManagementGetLeaderboardResultWrapper : public ModelWrapper<PFPlayerDataManagementGetLeaderboardResult, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementGetLeaderboardResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementGetLeaderboardResultWrapper() = default;

    PFPlayerDataManagementGetLeaderboardResultWrapper(const PFPlayerDataManagementGetLeaderboardResult& model) :
        ModelWrapper<PFPlayerDataManagementGetLeaderboardResult, Alloc>{ model },
        m_leaderboard{ model.leaderboard, model.leaderboard + model.leaderboardCount },
        m_nextReset{ model.nextReset ? StdExtra::optional<time_t>{ *model.nextReset } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementGetLeaderboardResultWrapper(const PFPlayerDataManagementGetLeaderboardResultWrapper& src) :
        PFPlayerDataManagementGetLeaderboardResultWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementGetLeaderboardResultWrapper(PFPlayerDataManagementGetLeaderboardResultWrapper&& src) :
        PFPlayerDataManagementGetLeaderboardResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementGetLeaderboardResultWrapper& operator=(PFPlayerDataManagementGetLeaderboardResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementGetLeaderboardResultWrapper() = default;

    friend void swap(PFPlayerDataManagementGetLeaderboardResultWrapper& lhs, PFPlayerDataManagementGetLeaderboardResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_leaderboard, rhs.m_leaderboard);
        swap(lhs.m_nextReset, rhs.m_nextReset);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLeaderboard(ModelVector<PFPlayerDataManagementPlayerLeaderboardEntryWrapper<Alloc>, Alloc> value)
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

    ModelVector<PFPlayerDataManagementPlayerLeaderboardEntryWrapper<Alloc>, Alloc> m_leaderboard;
    StdExtra::optional<time_t> m_nextReset;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper : public ModelWrapper<PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper() = default;

    PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper(const PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequest& model) :
        ModelWrapper<PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequest, Alloc>{ model },
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

    PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper(const PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper& src) :
        PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper(PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper&& src) :
        PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper& operator=(PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper& lhs, PFPlayerDataManagementGetFriendLeaderboardAroundPlayerRequestWrapper& rhs)
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
class PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResultWrapper : public ModelWrapper<PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResultWrapper() = default;

    PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResultWrapper(const PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult& model) :
        ModelWrapper<PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResult, Alloc>{ model },
        m_leaderboard{ model.leaderboard, model.leaderboard + model.leaderboardCount },
        m_nextReset{ model.nextReset ? StdExtra::optional<time_t>{ *model.nextReset } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResultWrapper(const PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResultWrapper& src) :
        PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResultWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResultWrapper(PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResultWrapper&& src) :
        PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResultWrapper& operator=(PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResultWrapper() = default;

    friend void swap(PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResultWrapper& lhs, PFPlayerDataManagementGetFriendLeaderboardAroundPlayerResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_leaderboard, rhs.m_leaderboard);
        swap(lhs.m_nextReset, rhs.m_nextReset);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLeaderboard(ModelVector<PFPlayerDataManagementPlayerLeaderboardEntryWrapper<Alloc>, Alloc> value)
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

    ModelVector<PFPlayerDataManagementPlayerLeaderboardEntryWrapper<Alloc>, Alloc> m_leaderboard;
    StdExtra::optional<time_t> m_nextReset;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementGetLeaderboardRequestWrapper : public ModelWrapper<PFPlayerDataManagementGetLeaderboardRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementGetLeaderboardRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementGetLeaderboardRequestWrapper() = default;

    PFPlayerDataManagementGetLeaderboardRequestWrapper(const PFPlayerDataManagementGetLeaderboardRequest& model) :
        ModelWrapper<PFPlayerDataManagementGetLeaderboardRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_profileConstraints{ model.profileConstraints ? StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>>{ *model.profileConstraints } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) },
        m_version{ model.version ? StdExtra::optional<int32_t>{ *model.version } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementGetLeaderboardRequestWrapper(const PFPlayerDataManagementGetLeaderboardRequestWrapper& src) :
        PFPlayerDataManagementGetLeaderboardRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementGetLeaderboardRequestWrapper(PFPlayerDataManagementGetLeaderboardRequestWrapper&& src) :
        PFPlayerDataManagementGetLeaderboardRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementGetLeaderboardRequestWrapper& operator=(PFPlayerDataManagementGetLeaderboardRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementGetLeaderboardRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementGetLeaderboardRequestWrapper& lhs, PFPlayerDataManagementGetLeaderboardRequestWrapper& rhs)
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
class PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper : public ModelWrapper<PFPlayerDataManagementGetLeaderboardAroundPlayerRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementGetLeaderboardAroundPlayerRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper() = default;

    PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper(const PFPlayerDataManagementGetLeaderboardAroundPlayerRequest& model) :
        ModelWrapper<PFPlayerDataManagementGetLeaderboardAroundPlayerRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_maxResultsCount{ model.maxResultsCount ? StdExtra::optional<int32_t>{ *model.maxResultsCount } : StdExtra::nullopt },
        m_playFabId{ SafeString(model.playFabId) },
        m_profileConstraints{ model.profileConstraints ? StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>>{ *model.profileConstraints } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) },
        m_version{ model.version ? StdExtra::optional<int32_t>{ *model.version } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper(const PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper& src) :
        PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper(PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper&& src) :
        PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper& operator=(PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper& lhs, PFPlayerDataManagementGetLeaderboardAroundPlayerRequestWrapper& rhs)
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
class PFPlayerDataManagementGetLeaderboardAroundPlayerResultWrapper : public ModelWrapper<PFPlayerDataManagementGetLeaderboardAroundPlayerResult, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementGetLeaderboardAroundPlayerResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementGetLeaderboardAroundPlayerResultWrapper() = default;

    PFPlayerDataManagementGetLeaderboardAroundPlayerResultWrapper(const PFPlayerDataManagementGetLeaderboardAroundPlayerResult& model) :
        ModelWrapper<PFPlayerDataManagementGetLeaderboardAroundPlayerResult, Alloc>{ model },
        m_leaderboard{ model.leaderboard, model.leaderboard + model.leaderboardCount },
        m_nextReset{ model.nextReset ? StdExtra::optional<time_t>{ *model.nextReset } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementGetLeaderboardAroundPlayerResultWrapper(const PFPlayerDataManagementGetLeaderboardAroundPlayerResultWrapper& src) :
        PFPlayerDataManagementGetLeaderboardAroundPlayerResultWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementGetLeaderboardAroundPlayerResultWrapper(PFPlayerDataManagementGetLeaderboardAroundPlayerResultWrapper&& src) :
        PFPlayerDataManagementGetLeaderboardAroundPlayerResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementGetLeaderboardAroundPlayerResultWrapper& operator=(PFPlayerDataManagementGetLeaderboardAroundPlayerResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementGetLeaderboardAroundPlayerResultWrapper() = default;

    friend void swap(PFPlayerDataManagementGetLeaderboardAroundPlayerResultWrapper& lhs, PFPlayerDataManagementGetLeaderboardAroundPlayerResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_leaderboard, rhs.m_leaderboard);
        swap(lhs.m_nextReset, rhs.m_nextReset);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLeaderboard(ModelVector<PFPlayerDataManagementPlayerLeaderboardEntryWrapper<Alloc>, Alloc> value)
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

    ModelVector<PFPlayerDataManagementPlayerLeaderboardEntryWrapper<Alloc>, Alloc> m_leaderboard;
    StdExtra::optional<time_t> m_nextReset;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementStatisticNameVersionWrapper : public ModelWrapper<PFPlayerDataManagementStatisticNameVersion, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementStatisticNameVersion;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementStatisticNameVersionWrapper() = default;

    PFPlayerDataManagementStatisticNameVersionWrapper(const PFPlayerDataManagementStatisticNameVersion& model) :
        ModelWrapper<PFPlayerDataManagementStatisticNameVersion, Alloc>{ model },
        m_statisticName{ SafeString(model.statisticName) }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementStatisticNameVersionWrapper(const PFPlayerDataManagementStatisticNameVersionWrapper& src) :
        PFPlayerDataManagementStatisticNameVersionWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementStatisticNameVersionWrapper(PFPlayerDataManagementStatisticNameVersionWrapper&& src) :
        PFPlayerDataManagementStatisticNameVersionWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementStatisticNameVersionWrapper& operator=(PFPlayerDataManagementStatisticNameVersionWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementStatisticNameVersionWrapper() = default;

    friend void swap(PFPlayerDataManagementStatisticNameVersionWrapper& lhs, PFPlayerDataManagementStatisticNameVersionWrapper& rhs)
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
class PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper : public ModelWrapper<PFPlayerDataManagementClientGetPlayerStatisticsRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementClientGetPlayerStatisticsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper() = default;

    PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper(const PFPlayerDataManagementClientGetPlayerStatisticsRequest& model) :
        ModelWrapper<PFPlayerDataManagementClientGetPlayerStatisticsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_statisticNames{ model.statisticNames, model.statisticNames + model.statisticNamesCount },
        m_statisticNameVersions{ model.statisticNameVersions, model.statisticNameVersions + model.statisticNameVersionsCount }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper(const PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper& src) :
        PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper(PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper&& src) :
        PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper& operator=(PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper& lhs, PFPlayerDataManagementClientGetPlayerStatisticsRequestWrapper& rhs)
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

    void SetStatisticNameVersions(ModelVector<PFPlayerDataManagementStatisticNameVersionWrapper<Alloc>, Alloc> value)
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
    ModelVector<PFPlayerDataManagementStatisticNameVersionWrapper<Alloc>, Alloc> m_statisticNameVersions;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementClientGetPlayerStatisticsResultWrapper : public ModelWrapper<PFPlayerDataManagementClientGetPlayerStatisticsResult, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementClientGetPlayerStatisticsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementClientGetPlayerStatisticsResultWrapper() = default;

    PFPlayerDataManagementClientGetPlayerStatisticsResultWrapper(const PFPlayerDataManagementClientGetPlayerStatisticsResult& model) :
        ModelWrapper<PFPlayerDataManagementClientGetPlayerStatisticsResult, Alloc>{ model },
        m_statistics{ model.statistics, model.statistics + model.statisticsCount }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementClientGetPlayerStatisticsResultWrapper(const PFPlayerDataManagementClientGetPlayerStatisticsResultWrapper& src) :
        PFPlayerDataManagementClientGetPlayerStatisticsResultWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementClientGetPlayerStatisticsResultWrapper(PFPlayerDataManagementClientGetPlayerStatisticsResultWrapper&& src) :
        PFPlayerDataManagementClientGetPlayerStatisticsResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementClientGetPlayerStatisticsResultWrapper& operator=(PFPlayerDataManagementClientGetPlayerStatisticsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementClientGetPlayerStatisticsResultWrapper() = default;

    friend void swap(PFPlayerDataManagementClientGetPlayerStatisticsResultWrapper& lhs, PFPlayerDataManagementClientGetPlayerStatisticsResultWrapper& rhs)
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
class PFPlayerDataManagementClientGetUserDataResultWrapper : public ModelWrapper<PFPlayerDataManagementClientGetUserDataResult, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementClientGetUserDataResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementClientGetUserDataResultWrapper() = default;

    PFPlayerDataManagementClientGetUserDataResultWrapper(const PFPlayerDataManagementClientGetUserDataResult& model) :
        ModelWrapper<PFPlayerDataManagementClientGetUserDataResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementClientGetUserDataResultWrapper(const PFPlayerDataManagementClientGetUserDataResultWrapper& src) :
        PFPlayerDataManagementClientGetUserDataResultWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementClientGetUserDataResultWrapper(PFPlayerDataManagementClientGetUserDataResultWrapper&& src) :
        PFPlayerDataManagementClientGetUserDataResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementClientGetUserDataResultWrapper& operator=(PFPlayerDataManagementClientGetUserDataResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementClientGetUserDataResultWrapper() = default;

    friend void swap(PFPlayerDataManagementClientGetUserDataResultWrapper& lhs, PFPlayerDataManagementClientGetUserDataResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(ModelDictionaryEntryVector<PFUserDataRecordWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

    void SetDataVersion(uint32_t value)
    {
        this->m_model.dataVersion = value;
    }

private:
    void SetModelPointers()
    {
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
    }

    ModelDictionaryEntryVector<PFUserDataRecordWrapper<Alloc>, Alloc> m_data;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementStatisticUpdateWrapper : public ModelWrapper<PFPlayerDataManagementStatisticUpdate, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementStatisticUpdate;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementStatisticUpdateWrapper() = default;

    PFPlayerDataManagementStatisticUpdateWrapper(const PFPlayerDataManagementStatisticUpdate& model) :
        ModelWrapper<PFPlayerDataManagementStatisticUpdate, Alloc>{ model },
        m_statisticName{ SafeString(model.statisticName) },
        m_version{ model.version ? StdExtra::optional<uint32_t>{ *model.version } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementStatisticUpdateWrapper(const PFPlayerDataManagementStatisticUpdateWrapper& src) :
        PFPlayerDataManagementStatisticUpdateWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementStatisticUpdateWrapper(PFPlayerDataManagementStatisticUpdateWrapper&& src) :
        PFPlayerDataManagementStatisticUpdateWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementStatisticUpdateWrapper& operator=(PFPlayerDataManagementStatisticUpdateWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementStatisticUpdateWrapper() = default;

    friend void swap(PFPlayerDataManagementStatisticUpdateWrapper& lhs, PFPlayerDataManagementStatisticUpdateWrapper& rhs)
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
class PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper : public ModelWrapper<PFPlayerDataManagementClientUpdatePlayerStatisticsRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementClientUpdatePlayerStatisticsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper() = default;

    PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper(const PFPlayerDataManagementClientUpdatePlayerStatisticsRequest& model) :
        ModelWrapper<PFPlayerDataManagementClientUpdatePlayerStatisticsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_statistics{ model.statistics, model.statistics + model.statisticsCount }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper(const PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper& src) :
        PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper(PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper&& src) :
        PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper& operator=(PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper& lhs, PFPlayerDataManagementClientUpdatePlayerStatisticsRequestWrapper& rhs)
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

    void SetStatistics(ModelVector<PFPlayerDataManagementStatisticUpdateWrapper<Alloc>, Alloc> value)
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
    ModelVector<PFPlayerDataManagementStatisticUpdateWrapper<Alloc>, Alloc> m_statistics;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementClientUpdateUserDataRequestWrapper : public ModelWrapper<PFPlayerDataManagementClientUpdateUserDataRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementClientUpdateUserDataRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementClientUpdateUserDataRequestWrapper() = default;

    PFPlayerDataManagementClientUpdateUserDataRequestWrapper(const PFPlayerDataManagementClientUpdateUserDataRequest& model) :
        ModelWrapper<PFPlayerDataManagementClientUpdateUserDataRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_data{ model.data, model.data + model.dataCount },
        m_keysToRemove{ model.keysToRemove, model.keysToRemove + model.keysToRemoveCount },
        m_permission{ model.permission ? StdExtra::optional<PFUserDataPermission>{ *model.permission } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementClientUpdateUserDataRequestWrapper(const PFPlayerDataManagementClientUpdateUserDataRequestWrapper& src) :
        PFPlayerDataManagementClientUpdateUserDataRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementClientUpdateUserDataRequestWrapper(PFPlayerDataManagementClientUpdateUserDataRequestWrapper&& src) :
        PFPlayerDataManagementClientUpdateUserDataRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementClientUpdateUserDataRequestWrapper& operator=(PFPlayerDataManagementClientUpdateUserDataRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementClientUpdateUserDataRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementClientUpdateUserDataRequestWrapper& lhs, PFPlayerDataManagementClientUpdateUserDataRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_data, rhs.m_data);
        swap(lhs.m_keysToRemove, rhs.m_keysToRemove);
        swap(lhs.m_permission, rhs.m_permission);
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

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
        this->m_model.keysToRemove = m_keysToRemove.empty() ? nullptr : m_keysToRemove.data();
        this->m_model.permission = m_permission ? m_permission.operator->() : nullptr;
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StringDictionaryEntryVector<Alloc> m_data;
    CStringVector<Alloc> m_keysToRemove;
    StdExtra::optional<PFUserDataPermission> m_permission;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper : public ModelWrapper<PFPlayerDataManagementServerGetFriendLeaderboardRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementServerGetFriendLeaderboardRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper() = default;

    PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper(const PFPlayerDataManagementServerGetFriendLeaderboardRequest& model) :
        ModelWrapper<PFPlayerDataManagementServerGetFriendLeaderboardRequest, Alloc>{ model },
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

    PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper(const PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper& src) :
        PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper(PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper&& src) :
        PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper& operator=(PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper& lhs, PFPlayerDataManagementServerGetFriendLeaderboardRequestWrapper& rhs)
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
class PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper : public ModelWrapper<PFPlayerDataManagementGetLeaderboardAroundUserRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementGetLeaderboardAroundUserRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper() = default;

    PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper(const PFPlayerDataManagementGetLeaderboardAroundUserRequest& model) :
        ModelWrapper<PFPlayerDataManagementGetLeaderboardAroundUserRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_profileConstraints{ model.profileConstraints ? StdExtra::optional<PFPlayerProfileViewConstraintsWrapper<Alloc>>{ *model.profileConstraints } : StdExtra::nullopt },
        m_statisticName{ SafeString(model.statisticName) },
        m_version{ model.version ? StdExtra::optional<int32_t>{ *model.version } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper(const PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper& src) :
        PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper(PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper&& src) :
        PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper& operator=(PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper& lhs, PFPlayerDataManagementGetLeaderboardAroundUserRequestWrapper& rhs)
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
class PFPlayerDataManagementGetLeaderboardAroundUserResultWrapper : public ModelWrapper<PFPlayerDataManagementGetLeaderboardAroundUserResult, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementGetLeaderboardAroundUserResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementGetLeaderboardAroundUserResultWrapper() = default;

    PFPlayerDataManagementGetLeaderboardAroundUserResultWrapper(const PFPlayerDataManagementGetLeaderboardAroundUserResult& model) :
        ModelWrapper<PFPlayerDataManagementGetLeaderboardAroundUserResult, Alloc>{ model },
        m_leaderboard{ model.leaderboard, model.leaderboard + model.leaderboardCount },
        m_nextReset{ model.nextReset ? StdExtra::optional<time_t>{ *model.nextReset } : StdExtra::nullopt }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementGetLeaderboardAroundUserResultWrapper(const PFPlayerDataManagementGetLeaderboardAroundUserResultWrapper& src) :
        PFPlayerDataManagementGetLeaderboardAroundUserResultWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementGetLeaderboardAroundUserResultWrapper(PFPlayerDataManagementGetLeaderboardAroundUserResultWrapper&& src) :
        PFPlayerDataManagementGetLeaderboardAroundUserResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementGetLeaderboardAroundUserResultWrapper& operator=(PFPlayerDataManagementGetLeaderboardAroundUserResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementGetLeaderboardAroundUserResultWrapper() = default;

    friend void swap(PFPlayerDataManagementGetLeaderboardAroundUserResultWrapper& lhs, PFPlayerDataManagementGetLeaderboardAroundUserResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_leaderboard, rhs.m_leaderboard);
        swap(lhs.m_nextReset, rhs.m_nextReset);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetLeaderboard(ModelVector<PFPlayerDataManagementPlayerLeaderboardEntryWrapper<Alloc>, Alloc> value)
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

    ModelVector<PFPlayerDataManagementPlayerLeaderboardEntryWrapper<Alloc>, Alloc> m_leaderboard;
    StdExtra::optional<time_t> m_nextReset;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper : public ModelWrapper<PFPlayerDataManagementServerGetPlayerStatisticsRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementServerGetPlayerStatisticsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper() = default;

    PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper(const PFPlayerDataManagementServerGetPlayerStatisticsRequest& model) :
        ModelWrapper<PFPlayerDataManagementServerGetPlayerStatisticsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_playFabId{ SafeString(model.playFabId) },
        m_statisticNames{ model.statisticNames, model.statisticNames + model.statisticNamesCount },
        m_statisticNameVersions{ model.statisticNameVersions, model.statisticNameVersions + model.statisticNameVersionsCount }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper(const PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper& src) :
        PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper(PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper&& src) :
        PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper& operator=(PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper& lhs, PFPlayerDataManagementServerGetPlayerStatisticsRequestWrapper& rhs)
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

    void SetStatisticNameVersions(ModelVector<PFPlayerDataManagementStatisticNameVersionWrapper<Alloc>, Alloc> value)
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
    ModelVector<PFPlayerDataManagementStatisticNameVersionWrapper<Alloc>, Alloc> m_statisticNameVersions;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementServerGetPlayerStatisticsResultWrapper : public ModelWrapper<PFPlayerDataManagementServerGetPlayerStatisticsResult, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementServerGetPlayerStatisticsResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementServerGetPlayerStatisticsResultWrapper() = default;

    PFPlayerDataManagementServerGetPlayerStatisticsResultWrapper(const PFPlayerDataManagementServerGetPlayerStatisticsResult& model) :
        ModelWrapper<PFPlayerDataManagementServerGetPlayerStatisticsResult, Alloc>{ model },
        m_playFabId{ SafeString(model.playFabId) },
        m_statistics{ model.statistics, model.statistics + model.statisticsCount }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementServerGetPlayerStatisticsResultWrapper(const PFPlayerDataManagementServerGetPlayerStatisticsResultWrapper& src) :
        PFPlayerDataManagementServerGetPlayerStatisticsResultWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementServerGetPlayerStatisticsResultWrapper(PFPlayerDataManagementServerGetPlayerStatisticsResultWrapper&& src) :
        PFPlayerDataManagementServerGetPlayerStatisticsResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementServerGetPlayerStatisticsResultWrapper& operator=(PFPlayerDataManagementServerGetPlayerStatisticsResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementServerGetPlayerStatisticsResultWrapper() = default;

    friend void swap(PFPlayerDataManagementServerGetPlayerStatisticsResultWrapper& lhs, PFPlayerDataManagementServerGetPlayerStatisticsResultWrapper& rhs)
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
class PFPlayerDataManagementServerGetUserDataResultWrapper : public ModelWrapper<PFPlayerDataManagementServerGetUserDataResult, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementServerGetUserDataResult;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementServerGetUserDataResultWrapper() = default;

    PFPlayerDataManagementServerGetUserDataResultWrapper(const PFPlayerDataManagementServerGetUserDataResult& model) :
        ModelWrapper<PFPlayerDataManagementServerGetUserDataResult, Alloc>{ model },
        m_data{ model.data, model.data + model.dataCount },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementServerGetUserDataResultWrapper(const PFPlayerDataManagementServerGetUserDataResultWrapper& src) :
        PFPlayerDataManagementServerGetUserDataResultWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementServerGetUserDataResultWrapper(PFPlayerDataManagementServerGetUserDataResultWrapper&& src) :
        PFPlayerDataManagementServerGetUserDataResultWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementServerGetUserDataResultWrapper& operator=(PFPlayerDataManagementServerGetUserDataResultWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementServerGetUserDataResultWrapper() = default;

    friend void swap(PFPlayerDataManagementServerGetUserDataResultWrapper& lhs, PFPlayerDataManagementServerGetUserDataResultWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_data, rhs.m_data);
        swap(lhs.m_playFabId, rhs.m_playFabId);
        lhs.SetModelPointers();
        rhs.SetModelPointers();
    }

    void SetData(ModelDictionaryEntryVector<PFUserDataRecordWrapper<Alloc>, Alloc> value)
    {
        m_data = std::move(value);
        this->m_model.data =  m_data.empty() ? nullptr : m_data.data();
        this->m_model.dataCount =  static_cast<uint32_t>(m_data.size());
    }

    void SetDataVersion(uint32_t value)
    {
        this->m_model.dataVersion = value;
    }

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    ModelDictionaryEntryVector<PFUserDataRecordWrapper<Alloc>, Alloc> m_data;
    String m_playFabId;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper : public ModelWrapper<PFPlayerDataManagementServerUpdatePlayerStatisticsRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementServerUpdatePlayerStatisticsRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper() = default;

    PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper(const PFPlayerDataManagementServerUpdatePlayerStatisticsRequest& model) :
        ModelWrapper<PFPlayerDataManagementServerUpdatePlayerStatisticsRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_forceUpdate{ model.forceUpdate ? StdExtra::optional<bool>{ *model.forceUpdate } : StdExtra::nullopt },
        m_playFabId{ SafeString(model.playFabId) },
        m_statistics{ model.statistics, model.statistics + model.statisticsCount }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper(const PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper& src) :
        PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper(PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper&& src) :
        PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper& operator=(PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper& lhs, PFPlayerDataManagementServerUpdatePlayerStatisticsRequestWrapper& rhs)
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

    void SetStatistics(ModelVector<PFPlayerDataManagementStatisticUpdateWrapper<Alloc>, Alloc> value)
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
    ModelVector<PFPlayerDataManagementStatisticUpdateWrapper<Alloc>, Alloc> m_statistics;
};

template<template<typename AllocT> class Alloc = std::allocator>
class PFPlayerDataManagementServerUpdateUserDataRequestWrapper : public ModelWrapper<PFPlayerDataManagementServerUpdateUserDataRequest, Alloc>
{
public:
    using ModelType = typename PFPlayerDataManagementServerUpdateUserDataRequest;
    using String = typename std::basic_string<char, std::char_traits<char>, Alloc<char>>;
    template<typename T> using Vector = typename std::vector<T, Alloc<T>>;

    PFPlayerDataManagementServerUpdateUserDataRequestWrapper() = default;

    PFPlayerDataManagementServerUpdateUserDataRequestWrapper(const PFPlayerDataManagementServerUpdateUserDataRequest& model) :
        ModelWrapper<PFPlayerDataManagementServerUpdateUserDataRequest, Alloc>{ model },
        m_customTags{ model.customTags, model.customTags + model.customTagsCount },
        m_data{ model.data, model.data + model.dataCount },
        m_keysToRemove{ model.keysToRemove, model.keysToRemove + model.keysToRemoveCount },
        m_permission{ model.permission ? StdExtra::optional<PFUserDataPermission>{ *model.permission } : StdExtra::nullopt },
        m_playFabId{ SafeString(model.playFabId) }
    {
        SetModelPointers();
    }

    PFPlayerDataManagementServerUpdateUserDataRequestWrapper(const PFPlayerDataManagementServerUpdateUserDataRequestWrapper& src) :
        PFPlayerDataManagementServerUpdateUserDataRequestWrapper{ src.Model() }
    {
    }

    PFPlayerDataManagementServerUpdateUserDataRequestWrapper(PFPlayerDataManagementServerUpdateUserDataRequestWrapper&& src) :
        PFPlayerDataManagementServerUpdateUserDataRequestWrapper{}
    {
        swap(*this, src);
    }

    PFPlayerDataManagementServerUpdateUserDataRequestWrapper& operator=(PFPlayerDataManagementServerUpdateUserDataRequestWrapper src) 
    {
        swap(*this, src);
        return *this;
    }

    virtual ~PFPlayerDataManagementServerUpdateUserDataRequestWrapper() = default;

    friend void swap(PFPlayerDataManagementServerUpdateUserDataRequestWrapper& lhs, PFPlayerDataManagementServerUpdateUserDataRequestWrapper& rhs)
    {
        using std::swap;
        swap(lhs.m_model, rhs.m_model);
        swap(lhs.m_customTags, rhs.m_customTags);
        swap(lhs.m_data, rhs.m_data);
        swap(lhs.m_keysToRemove, rhs.m_keysToRemove);
        swap(lhs.m_permission, rhs.m_permission);
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

    void SetPlayFabId(String value)
    {
        m_playFabId = std::move(value);
        this->m_model.playFabId =  m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

private:
    void SetModelPointers()
    {
        this->m_model.customTags = m_customTags.empty() ? nullptr : m_customTags.data();
        this->m_model.data = m_data.empty() ? nullptr : m_data.data();
        this->m_model.keysToRemove = m_keysToRemove.empty() ? nullptr : m_keysToRemove.data();
        this->m_model.permission = m_permission ? m_permission.operator->() : nullptr;
        this->m_model.playFabId = m_playFabId.empty() ? nullptr : m_playFabId.data();
    }

    StringDictionaryEntryVector<Alloc> m_customTags;
    StringDictionaryEntryVector<Alloc> m_data;
    CStringVector<Alloc> m_keysToRemove;
    StdExtra::optional<PFUserDataPermission> m_permission;
    String m_playFabId;
};

} // namespace Wrappers
} // namespace PlayFab
